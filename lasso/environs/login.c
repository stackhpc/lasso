 /* $Id: login.c,v 1.96 2004/09/06 17:49:19 fpeters Exp $
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004 Entr'ouvert
 * http://lasso.entrouvert.org
 * 
 * Authors: Nicolas Clapies <nclapies@entrouvert.com>
 *          Valery Febvre <vfebvre@easter-eggs.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <string.h>
#include <glib/gprintf.h>
#include <xmlsec/base64.h>

#include <lasso/xml/errors.h>

#include <lasso/protocols/artifact.h>
#include <lasso/protocols/provider.h>
#include <lasso/protocols/elements/authentication_statement.h>

#include <lasso/environs/login.h>

static GObjectClass *parent_class = NULL;

struct _LassoLoginPrivate
{
  gboolean dispose_has_run;
};

/*****************************************************************************/
/* functions                                                                 */
/*****************************************************************************/

/**
 * lasso_login_add_response_assertion:
 * @login: a Login
 * @federation: a Federation
 * @authenticationMethod: the authentication method
 * @reauthenticateOnOrAfter: the reauthenticate on or after time
 * 
 * Adds an assertion into the samlp:Response.
 * Assertion is also stored in session property. If session property
 * is NULL, a new session is build before.
 * The NameIdentifier of the assertion is stored into nameIdentifier
 * proprerty.
 * 
 * Return value: 0 on success or a negative value otherwise.
 **/
static gint
lasso_login_add_response_assertion(LassoLogin      *login,
				   LassoFederation *federation,
				   const gchar     *authenticationMethod,
				   const gchar     *reauthenticateOnOrAfter)
{
  LassoNode *assertion = NULL, *as;
  xmlChar *requestID;
  GError *err = NULL;
  gint ret = 0;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
  g_return_val_if_fail (LASSO_IS_FEDERATION(federation),
			LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

  /* get RequestID to build Assertion */
  requestID = lasso_node_get_attr_value(LASSO_NODE(LASSO_PROFILE(login)->request),
					"RequestID", &err);
  if (requestID == NULL) {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_error_free(err);
    return ret;
  }
  assertion = lasso_assertion_new(LASSO_PROFILE(login)->server->providerID,
				  requestID);
  xmlFree(requestID);

  as = lasso_authentication_statement_new(authenticationMethod,
					  reauthenticateOnOrAfter,
					  LASSO_SAML_NAME_IDENTIFIER(federation->remote_nameIdentifier),
					  LASSO_SAML_NAME_IDENTIFIER(federation->local_nameIdentifier));
  if (as != NULL) {
    lasso_saml_assertion_add_authenticationStatement(LASSO_SAML_ASSERTION(assertion),
						     LASSO_SAML_AUTHENTICATION_STATEMENT(as));
  }
  else {
    ret = -2;
    goto done;
  }

  /* FIXME : How to know if the assertion must be signed or unsigned ? */
  /* signature should be added at end */
  ret = lasso_saml_assertion_set_signature(LASSO_SAML_ASSERTION(assertion),
					   LASSO_PROFILE(login)->server->signature_method,
					   LASSO_PROFILE(login)->server->private_key,
					   LASSO_PROFILE(login)->server->certificate);
  if (ret == 0) {
    lasso_samlp_response_add_assertion(LASSO_SAMLP_RESPONSE(LASSO_PROFILE(login)->response),
				       assertion);
  
    /* store assertion in session object */
    if (LASSO_PROFILE(login)->session == NULL) {
      LASSO_PROFILE(login)->session = lasso_session_new();
    }
    lasso_session_add_assertion(LASSO_PROFILE(login)->session,
				LASSO_PROFILE(login)->remote_providerID,
				assertion);
  }

 done:
  lasso_node_destroy(as);
  lasso_node_destroy(assertion);

  return ret;
}

static gint
lasso_login_process_federation(LassoLogin *login)
{
  LassoFederation *federation;
  LassoNode *nameIdentifier;
  xmlChar *id, *nameIDPolicy, *consent = NULL;
  gint ret = 0;
  GError *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

  /* verify if an identity exists else create it */
  if (LASSO_PROFILE(login)->identity == NULL) {
    LASSO_PROFILE(login)->identity = lasso_identity_new();
  }
  federation = lasso_identity_get_federation(LASSO_PROFILE(login)->identity,
					     LASSO_PROFILE(login)->remote_providerID);
  nameIDPolicy = lasso_node_get_child_content(LASSO_PROFILE(login)->request,
					      "NameIDPolicy", lassoLibHRef, NULL);
  if (nameIDPolicy == NULL || xmlStrEqual(nameIDPolicy, lassoLibNameIDPolicyTypeNone)) {
    if (federation == NULL) {
      lasso_profile_set_response_status(LASSO_PROFILE(login),
					lassoLibStatusCodeFederationDoesNotExist);
      ret = -2;
      goto done;
    }
  }
  else if (xmlStrEqual(nameIDPolicy, lassoLibNameIDPolicyTypeFederated)) {
    debug("NameIDPolicy is federated\n");
    consent = lasso_node_get_attr_value(LASSO_PROFILE(login)->request,
					"consent", &err);
    if (consent != NULL) {
      if (!xmlStrEqual(consent, lassoLibConsentObtained)) {
	lasso_profile_set_response_status(LASSO_PROFILE(login),
					  lassoSamlStatusCodeRequestDenied);
	message(G_LOG_LEVEL_WARNING, "Consent not obtained");
	ret = -3;
	goto done;
      }
    }
    else {
      lasso_profile_set_response_status(LASSO_PROFILE(login),
					lassoSamlStatusCodeRequestDenied);
      message(G_LOG_LEVEL_WARNING, err->message);
      ret = err->code;
      g_error_free(err);
      goto done;
    }
    if (federation == NULL) {
      federation = lasso_federation_new(LASSO_PROFILE(login)->remote_providerID);

      /* set local NameIdentifier in federation */
      id = lasso_build_unique_id(32);
      nameIdentifier = lasso_saml_name_identifier_new(id);
      xmlFree(id);
      lasso_saml_name_identifier_set_nameQualifier(LASSO_SAML_NAME_IDENTIFIER(nameIdentifier),
						   LASSO_PROFILE(login)->server->providerID);
      lasso_saml_name_identifier_set_format(LASSO_SAML_NAME_IDENTIFIER(nameIdentifier),
					    lassoLibNameIdentifierFormatFederated);
      lasso_federation_set_local_nameIdentifier(federation, nameIdentifier);
      lasso_node_destroy(nameIdentifier);

      lasso_identity_add_federation(LASSO_PROFILE(login)->identity,
				    LASSO_PROFILE(login)->remote_providerID,
				    federation);
    }
    else {
      debug("Ok, a federation was found.\n");
    }
  }
  else if (xmlStrEqual(nameIDPolicy, lassoLibNameIDPolicyTypeOneTime)) {
    /* TODO */
  }

  /* store the IDP name identifier */
  LASSO_PROFILE(login)->nameIdentifier = lasso_node_get_content(federation->local_nameIdentifier, NULL);

 done:
  lasso_federation_destroy(federation);
  xmlFree(nameIDPolicy);
  xmlFree(consent);

  return ret;
}

static gint
lasso_login_process_response_status_and_assertion(LassoLogin *login) {
  LassoNode *assertion = NULL, *status = NULL, *statusCode = NULL;
  LassoProvider *idp = NULL;
  gchar *statusCode_value = NULL;
  gint ret = 0;
  GError *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

  /* check StatusCode value */
  status = lasso_node_get_child(LASSO_PROFILE(login)->response,
				"Status", lassoSamlProtocolHRef, &err);
  if (status == NULL) {
    /* nico : return a code error if status code not found */
    ret = -1;
    goto done;
  }
  statusCode = lasso_node_get_child(status, "StatusCode", lassoSamlProtocolHRef, &err);
  if (statusCode == NULL) {
    /* nico : return a code error if status code not found */
    ret = -1;
    goto done;
  }
  statusCode_value = lasso_node_get_attr_value(statusCode, "Value", &err);
  if (statusCode_value != NULL) {
    if (!xmlStrEqual(statusCode_value, lassoSamlStatusCodeSuccess)) {
      ret = -7;
      /* nico : go to done */
      goto done;
    }
  }

  /* check assertion */
  /* nico : removed ref on err pointer */
  assertion = lasso_node_get_child(LASSO_PROFILE(login)->response,
				   "Assertion",
				   NULL, /* lassoLibHRef, FIXME changed for SourceID */
				   NULL);

  if (assertion != NULL) {
    idp = lasso_server_get_provider_ref(LASSO_PROFILE(login)->server,
					LASSO_PROFILE(login)->remote_providerID,
					&err);
    /* verify signature */
    if (idp != NULL) {
      /* FIXME detect X509Data ? */
      /* signature_check = lasso_node_verify_x509_signature(assertion, idp->ca_certificate); */
      ret = lasso_node_verify_signature(assertion, idp->public_key);
      if (ret < 0) {
	goto done;
      }
    }
    else {
      message(G_LOG_LEVEL_CRITICAL, err->message);
      ret = err->code;
      g_error_free(err);
      goto done;
    }

    /* store NameIdentifier */
    LASSO_PROFILE(login)->nameIdentifier = lasso_node_get_child_content(assertion, "NameIdentifier",
									NULL, &err);
    if (LASSO_PROFILE(login)->nameIdentifier == NULL) {
      message(G_LOG_LEVEL_CRITICAL, err->message);
      ret = err->code;
      g_clear_error(&err);
      /* we continue */
    }
  }
/* nico : dont return a code error if no assertion found */
/*   else { */
/*     /\* no assertion found *\/ */
/*     debug(err->message); */
/*     ret = err->code; */
/*     g_clear_error(&err); */
/*     /\* we continue *\/ */
/*   } */

 done:
  if (err != NULL) {
    if (err->code < 0) {
      message(G_LOG_LEVEL_CRITICAL, err->message);
      ret = err->code;
      g_clear_error(&err);
    }
  }
  xmlFree(statusCode_value);
  lasso_node_destroy(statusCode);
  lasso_node_destroy(status);
  lasso_node_destroy(assertion);

  return ret;
}

/*****************************************************************************/
/* public methods                                                            */
/*****************************************************************************/

/**
 * lasso_login_accept_sso:
 * @login: a LassoLogin
 * 
 * Gets the assertion of the response and adds it into the session.
 * Builds a federation with the 2 name identifiers of the assertion
 * and adds it into the identity.
 * If the session or the identity are NULL, they are created.
 * 
 * Return value: 0 on success and a negative value otherwise.
 **/
gint
lasso_login_accept_sso(LassoLogin *login)
{
  LassoNode *assertion = NULL;
  LassoNode *ni = NULL;
  LassoNode *idp_ni, *idp_ni_copy = NULL;
  LassoFederation *federation = NULL;
  gint ret = 0;
  GError *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

  if(LASSO_PROFILE(login)->identity == NULL) {
    LASSO_PROFILE(login)->identity = lasso_identity_new();    
  }
  if(LASSO_PROFILE(login)->session == NULL) {
    LASSO_PROFILE(login)->session = lasso_session_new();
  }

  if (LASSO_PROFILE(login)->response != NULL) {
    assertion = lasso_node_get_child(LASSO_PROFILE(login)->response,
    				     "Assertion",
				     NULL, /* lassoLibHRef, FIXME changed for SourceID */
				     &err);
    if (assertion == NULL) {
      message(G_LOG_LEVEL_CRITICAL, err->message);
      ret = err->code;
      g_error_free(err);
      goto done;
    }

    /* put response assertion in session object */
    lasso_session_add_assertion(LASSO_PROFILE(login)->session,
				LASSO_PROFILE(login)->remote_providerID,
				assertion);

    /* get the 2 NameIdentifiers and put them in identity object */
    ni = lasso_node_get_child(assertion, "NameIdentifier",
			      lassoSamlAssertionHRef, &err);
    /* 1 - the saml:NameIdentifier SHOULD exists */
    if (ni == NULL) {
      message(G_LOG_LEVEL_CRITICAL, err->message);
      ret = err->code;
      g_error_free(err);
      goto done;
    }
    /* 2 - the lib:IDPProvidedNameIdentifier */
    idp_ni = lasso_node_get_child(assertion, "IDPProvidedNameIdentifier",
				  lassoLibHRef, &err);
    if (idp_ni != NULL) {
      idp_ni_copy = lasso_node_copy(idp_ni);
      lasso_node_destroy(idp_ni);
      /* transform the lib:IDPProvidedNameIdentifier into a saml:NameIdentifier */
      LASSO_NODE_GET_CLASS(idp_ni_copy)->set_name(idp_ni_copy, "NameIdentifier");
      LASSO_NODE_GET_CLASS(idp_ni_copy)->set_ns(idp_ni_copy,
						lassoSamlAssertionHRef,
						lassoSamlAssertionPrefix);
    }

    /* create federation */
    federation = lasso_federation_new(LASSO_PROFILE(login)->remote_providerID);
    if (ni != NULL && idp_ni_copy != NULL) {
      lasso_federation_set_local_nameIdentifier(federation, ni);
      lasso_federation_set_remote_nameIdentifier(federation, idp_ni_copy);
    }
    else {
      lasso_federation_set_remote_nameIdentifier(federation, ni);
    }
    /* add federation in identity */
    lasso_identity_add_federation(LASSO_PROFILE(login)->identity,
				  LASSO_PROFILE(login)->remote_providerID,
				  federation);
    lasso_federation_destroy(federation);
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, "response attribute is empty.\n");
  }
  
 done:
  lasso_node_destroy(ni);
  lasso_node_destroy(idp_ni_copy);
  lasso_node_destroy(assertion);

  return ret;
}

/**
 * lasso_login_build_artifact_msg:
 * @login: a LassoLogin
 * @authentication_result: the authentication result
 * @authenticationMethod: the authentication method
 * @reauthenticateOnOrAfter: the time at, or after which the service provider
 * reauthenticates the Principal with the identity provider 
 * @http_method: the HTTP method to send the artifact (REDIRECT or POST)
 * 
 * Builds an artifact. Depending of the HTTP method, the data for the sending of
 * the artifact are stored in msg_url (REDIRECT) or msg_url, msg_body and
 * msg_relayState (POST).
 * 
 * Return value: 0 on success and a negative value otherwise.
 **/
gint
lasso_login_build_artifact_msg(LassoLogin      *login,
			       gboolean         authentication_result,
			       const gchar     *authenticationMethod,
			       const gchar     *reauthenticateOnOrAfter,
			       lassoHttpMethod  http_method)
{
  LassoFederation *federation = NULL;
  LassoProvider *remote_provider;
  gchar   *url;
  xmlChar samlArt[42+1], *b64_samlArt, *relayState;
  xmlChar *assertionHandle, *identityProviderSuccinctID;
  gint i;

  /* nico */
  LassoNodeClass *assertion_class;
  LassoNode *assertion_node;
  xmlNodePtr assertion_xmlNode;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
  g_return_val_if_fail(authenticationMethod != NULL && reauthenticateOnOrAfter != NULL,
		       LASSO_PARAM_ERROR_INVALID_VALUE);

  if (http_method != lassoHttpMethodRedirect && http_method != lassoHttpMethodPost) {
    message(G_LOG_LEVEL_CRITICAL, "Invalid HTTP method, it could be REDIRECT or POST\n.");
    return -2;
  }

  /* ProtocolProfile must be BrwsArt */
  if (login->protocolProfile != lassoLoginProtocolProfileBrwsArt) {
    message(G_LOG_LEVEL_CRITICAL, "Failed to build artifact message, an AuthnResponse is required by ProtocolProfile.\n");
    return -3;
  }

  if (authentication_result == 0) {
    lasso_profile_set_response_status(LASSO_PROFILE(login),
				      lassoSamlStatusCodeRequestDenied);
  }
  else {
    /* federation */
    lasso_login_process_federation(login);
    federation = lasso_identity_get_federation(LASSO_PROFILE(login)->identity,
					       LASSO_PROFILE(login)->remote_providerID);
    /* fill the response with the assertion */
    if (federation != NULL) {
      lasso_login_add_response_assertion(login,
					 federation,
					 authenticationMethod,
					 reauthenticateOnOrAfter);
      lasso_federation_destroy(federation);
    }
  }

  /* save response dump */
  /*        login->response_dump = lasso_node_export_to_soap(LASSO_PROFILE(login)->response); */

  /* nico : doesn't dump the response anymore, instead store the assertion */
  login->assertion = NULL;
  assertion_node = lasso_node_get_child(LASSO_PROFILE(login)->response, "Assertion", NULL, NULL);
  if (assertion_node != NULL) {
    login->assertion = g_object_new(LASSO_TYPE_ASSERTION,
				    "use_xsitype", TRUE,
				    NULL);

    assertion_class = LASSO_NODE_GET_CLASS(assertion_node);
    assertion_xmlNode = xmlCopyNode(assertion_class->get_xmlNode(LASSO_NODE(assertion_node)), 1);

    assertion_class = LASSO_NODE_GET_CLASS(login->assertion);
    assertion_class->set_xmlNode(LASSO_NODE(login->assertion), assertion_xmlNode);

    lasso_node_destroy(assertion_node);
  }

  /* build artifact infos */
  remote_provider = lasso_server_get_provider_ref(LASSO_PROFILE(login)->server,
						  LASSO_PROFILE(login)->remote_providerID,
						  NULL);
  /* liberty-idff-bindings-profiles-v1.2.pdf p.25 */
  url = lasso_provider_get_assertionConsumerServiceURL(remote_provider, lassoProviderTypeSp, NULL);
  identityProviderSuccinctID = lasso_sha1(LASSO_PROFILE(login)->server->providerID);
  assertionHandle = lasso_build_random_sequence(20);

  /* g_sprintf(samlArt, "%c%c%s%s", 0, 3, identityProviderSuccinctID, assertionHandle); */
  g_sprintf(samlArt, "%c%c", 0, 3); /* ByteCode */
  for(i=0;i<20;i++) {
    samlArt[i+2] = identityProviderSuccinctID[i];
  }
  for(i=0;i<20;i++) {
    samlArt[i+22] = assertionHandle[i];
  }
  xmlFree(assertionHandle);
  xmlFree(identityProviderSuccinctID);
  b64_samlArt = xmlSecBase64Encode((const xmlSecByte *)samlArt, 42, 0);
  relayState = lasso_node_get_child_content(LASSO_PROFILE(login)->request,
					    "RelayState", NULL, NULL);

  switch (http_method) {
  case lassoHttpMethodRedirect:
    LASSO_PROFILE(login)->msg_url = g_new(gchar, 1024+1);
    g_sprintf(LASSO_PROFILE(login)->msg_url, "%s?SAMLart=%s", url, b64_samlArt);
    if (relayState != NULL) {
      g_sprintf(LASSO_PROFILE(login)->msg_url, "%s&RelayState=%s",
	      LASSO_PROFILE(login)->msg_url, relayState);
    }
    break;
  case lassoHttpMethodPost:
    LASSO_PROFILE(login)->msg_url  = g_strdup(url);
    LASSO_PROFILE(login)->msg_body = g_strdup(b64_samlArt);
    if (relayState != NULL) {
      LASSO_PROFILE(login)->msg_relayState = g_strdup(relayState);
    }
    break;
  default:
    break;
  }
  login->assertionArtifact = g_strdup(b64_samlArt);
  xmlFree(url);
  xmlFree(b64_samlArt);
  xmlFree(relayState);
  
  return 0;
}

/**
 * lasso_login_build_authn_request_msg:
 * @login: a LassoLogin
 * @remote_providerID: the providerID of the identity provider
 * 
 * Builds an authentication request. Depending of the SSO protocol profile of
 * the identity provider (defined in metadata file), the data for the sending of
 * the request are stored in msg_url (GET) or msg_url and msg_body (POST).
 * 
 * Return value: 0 on success and a negative value otherwise.
 **/
gint
lasso_login_build_authn_request_msg(LassoLogin      *login,
				    const gchar     *remote_providerID)
{
  LassoProvider *provider, *remote_provider;
  xmlChar *md_authnRequestsSigned = NULL;
  xmlChar *request_protocolProfile = NULL;
  xmlChar *url = NULL;
  gchar *query = NULL;
  gchar *lareq = NULL;
  gboolean must_sign;
  gint ret = 0;
  GError *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
  g_return_val_if_fail(remote_providerID != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

  LASSO_PROFILE(login)->remote_providerID = g_strdup(remote_providerID);
  
  provider = LASSO_PROVIDER(LASSO_PROFILE(login)->server);
  remote_provider = lasso_server_get_provider_ref(LASSO_PROFILE(login)->server,
						  LASSO_PROFILE(login)->remote_providerID,
						  &err);
  if (remote_provider == NULL) {
    ret = err->code;
    g_error_free(err);
    return ret;
  }

  /* check if authnRequest must be signed */
  md_authnRequestsSigned = lasso_provider_get_authnRequestsSigned(provider, &err);
  if (md_authnRequestsSigned != NULL) {
    must_sign = xmlStrEqual(md_authnRequestsSigned, "true");
    xmlFree(md_authnRequestsSigned);
  }
  else {
    /* AuthnRequestsSigned metadata is required in metadata */
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_error_free(err);
    goto done;
  }

  /* get SingleSignOnServiceURL metadata */
  url = lasso_provider_get_singleSignOnServiceURL(remote_provider, &err);
  if (url == NULL) {
    /* SingleSignOnServiceURL metadata is required */
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_error_free(err);
    goto done;
  }
  
  if (login->http_method == lassoHttpMethodRedirect) {
    /* REDIRECT -> query */
    if (must_sign) {
      query = lasso_node_export_to_query(LASSO_PROFILE(login)->request,
					 LASSO_PROFILE(login)->server->signature_method,
					 LASSO_PROFILE(login)->server->private_key);
      if (query == NULL) {
	message(G_LOG_LEVEL_CRITICAL, "Failed to create AuthnRequest query (signed).\n");
	ret = -3;
	goto done;
      }
    }
    else {
      query = lasso_node_export_to_query(LASSO_PROFILE(login)->request, 0, NULL);
      if (query == NULL) {
	message(G_LOG_LEVEL_CRITICAL, "Failed to create AuthnRequest query.\n");
	ret = -4;
	goto done;
      }
    }
    /* alloc msg_url (+2 for the ? and \0) */
    LASSO_PROFILE(login)->msg_url = (gchar *) g_new(gchar, strlen(url) + strlen(query) + 2);
    g_sprintf(LASSO_PROFILE(login)->msg_url, "%s?%s", url, query);
    LASSO_PROFILE(login)->msg_body = NULL;
    g_free(query);
  }
  else if (login->http_method == lassoHttpMethodPost) {
    /* POST -> formular */
    if (must_sign) {
      ret = lasso_samlp_request_abstract_sign_signature_tmpl(LASSO_SAMLP_REQUEST_ABSTRACT(LASSO_PROFILE(login)->request),
							     LASSO_PROFILE(login)->server->private_key,
							     LASSO_PROFILE(login)->server->certificate);
    }
    if (ret < 0) {
      goto done;
    }
    lareq = lasso_node_export_to_base64(LASSO_PROFILE(login)->request);
    if (lareq != NULL) {
      LASSO_PROFILE(login)->msg_url = g_strdup(url);
      LASSO_PROFILE(login)->msg_body = lareq;
    }
    else {
      message(G_LOG_LEVEL_CRITICAL, "Failed to export AuthnRequest (Base64 encoded).\n");
      ret = -5;
    }
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, "Invalid SingleSignOnProtocolProfile.\n");
  }

 done:
  xmlFree(url);
  xmlFree(request_protocolProfile);

  return ret;
}

/**
 * lasso_login_build_authn_response_msg:
 * @login: a LassoLogin
 * @authentication_result: the authentication result
 * @authenticationMethod: the authentication method
 * @reauthenticateOnOrAfter: the time at, or after which the service provider
 * reauthenticates the Principal with the identity provider 
 * 
 * Builds an authentication response. The data for the sending of the response
 * are stored in msg_url and msg_body.
 * 
 * Return value: 0 on success and a negative value otherwise.
 **/
gint
lasso_login_build_authn_response_msg(LassoLogin  *login,
				     gboolean     authentication_result,
				     const gchar *authenticationMethod,
				     const gchar *reauthenticateOnOrAfter)
{
  LassoProvider *remote_provider;
  LassoFederation *federation;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

  /* ProtocolProfile must be BrwsPost */
  if (login->protocolProfile != lassoLoginProtocolProfileBrwsPost) {
    message(G_LOG_LEVEL_CRITICAL, "Failed to build AuthnResponse message, an Artifact is required by ProtocolProfile.\n");
    return -1;
  }
  
  if (authentication_result == 0) {
    lasso_profile_set_response_status(LASSO_PROFILE(login),
				      lassoSamlStatusCodeRequestDenied);
  }
  else {
    /* federation */
    lasso_login_process_federation(login);
    federation = lasso_identity_get_federation(LASSO_PROFILE(login)->identity,
					       LASSO_PROFILE(login)->remote_providerID);
    /* fill the response with the assertion */
    if (federation != NULL) {
      lasso_login_add_response_assertion(login,
					 federation,
					 authenticationMethod,
					 reauthenticateOnOrAfter);
      lasso_federation_destroy(federation);
    }
  }
  
  remote_provider = lasso_server_get_provider_ref(LASSO_PROFILE(login)->server,
						  LASSO_PROFILE(login)->remote_providerID,
						  NULL);
  /* return an authnResponse (base64 encoded) */
  LASSO_PROFILE(login)->msg_body = lasso_node_export_to_base64(LASSO_PROFILE(login)->response);
  LASSO_PROFILE(login)->msg_url  = lasso_provider_get_assertionConsumerServiceURL(remote_provider,
										  lassoProviderTypeSp,
										  NULL);

  return 0;
}

gint
lasso_login_build_request_msg(LassoLogin *login)
{
  LassoProvider *remote_provider;
  gint ret = 0;
  GError *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

  /* sign request */
  ret= lasso_samlp_request_abstract_sign_signature_tmpl(LASSO_SAMLP_REQUEST_ABSTRACT(LASSO_PROFILE(login)->request),
							LASSO_PROFILE(login)->server->private_key,
							LASSO_PROFILE(login)->server->certificate);
  LASSO_PROFILE(login)->msg_body = lasso_node_export_to_soap(LASSO_PROFILE(login)->request);

  /* get msg_url (SOAP Endpoint) */
  remote_provider = lasso_server_get_provider_ref(LASSO_PROFILE(login)->server,
						  LASSO_PROFILE(login)->remote_providerID,
						  &err);
  if (err != NULL) {
    goto done;
  }
  LASSO_PROFILE(login)->msg_url = lasso_provider_get_soapEndpoint(remote_provider,
								  lassoProviderTypeIdp, &err);
  if (err != NULL) {
    goto done;
  }
  return 0;

 done:
  message(G_LOG_LEVEL_CRITICAL, err->message);
  ret = err->code;
  g_error_free(err);
  return ret;
}

gint
lasso_login_build_response_msg(LassoLogin *login)
{
  LassoNode *status, *status_code;
  LassoNode *response, *assertion;
  LassoNodeClass *class;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), -1);

  response = lasso_response_new();

  /* set status code */
  status = lasso_samlp_status_new();
  status_code = lasso_samlp_status_code_new();
  lasso_samlp_status_code_set_value(LASSO_SAMLP_STATUS_CODE(status_code),
				    lassoSamlStatusCodeSuccess);

  lasso_samlp_status_set_statusCode(LASSO_SAMLP_STATUS(status),
				    LASSO_SAMLP_STATUS_CODE(status_code));

  lasso_samlp_response_set_status(LASSO_SAMLP_RESPONSE(response),
				  LASSO_SAMLP_STATUS(status));
  lasso_node_destroy(status_code);
  lasso_node_destroy(status);

  /* add assertion */
  if (LASSO_IS_ASSERTION(login->assertion) == TRUE) {
    assertion = lasso_node_copy(LASSO_NODE(login->assertion));
    
    class = LASSO_NODE_GET_CLASS(response);
    class->add_child(LASSO_NODE(response), assertion, TRUE);
  }

  LASSO_PROFILE(login)->msg_body = lasso_node_export_to_soap(response);

  return 0;
}

void
lasso_login_destroy(LassoLogin *login)
{
  g_object_unref(G_OBJECT(login));
}

gchar*
lasso_login_dump(LassoLogin *login)
{
  LassoNode *node;
  gchar *parent_dump, *dump;
  gchar protocolProfile[6];

  g_return_val_if_fail(LASSO_IS_LOGIN(login), NULL);

  parent_dump = lasso_profile_dump(LASSO_PROFILE(login), "Login");
  node = lasso_node_new_from_dump(parent_dump);
  g_free(parent_dump);

  g_sprintf(protocolProfile, "%d", login->protocolProfile);
  LASSO_NODE_GET_CLASS(node)->new_child(node, "ProtocolProfile", protocolProfile, FALSE);

  /* nico : Added dump of assertion */
  if (login->assertion != NULL) {
    LASSO_NODE_GET_CLASS(node)->add_child(node, LASSO_NODE(login->assertion), FALSE);
  }

  if (login->assertionArtifact != NULL) {
    LASSO_NODE_GET_CLASS(node)->new_child(node, "AssertionArtifact", login->assertionArtifact, FALSE);
  }
  if (login->response_dump != NULL) {
    LASSO_NODE_GET_CLASS(node)->new_child(node, "ResponseDump", login->response_dump, FALSE);
  }

  dump = lasso_node_export(node);
  lasso_node_destroy(node);

  return dump;
}

LassoAssertion*
lasso_login_get_assertion(LassoLogin *login)
{
  LassoNodeClass *class;
  LassoAssertion *assertion;
  xmlNodePtr      assertion_xmlNode;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), NULL);

  if (LASSO_IS_ASSERTION(login->assertion) == FALSE) {
    return NULL;
  }

  assertion = g_object_new(LASSO_TYPE_ASSERTION,
			   "use_xsitype", TRUE,
			   NULL);

  class = LASSO_NODE_GET_CLASS(login->assertion);
  assertion_xmlNode = xmlCopyNode(class->get_xmlNode(login->assertion), 1);

  class = LASSO_NODE_GET_CLASS(assertion);
  class->set_xmlNode(LASSO_NODE(assertion), assertion_xmlNode);

  return assertion;
}

gint
lasso_login_init_authn_request(LassoLogin      *login,
			       lassoHttpMethod  http_method)
{
  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
  if (http_method != lassoHttpMethodRedirect && http_method != lassoHttpMethodPost) {
    message(G_LOG_LEVEL_CRITICAL, "Invalid HTTP method, it must be REDIRECT or POST\n.");
    return LASSO_PARAM_ERROR_INVALID_VALUE;
  }

  login->http_method = http_method;

  if (http_method == lassoHttpMethodPost) {
    LASSO_PROFILE(login)->request = lasso_authn_request_new(LASSO_PROFILE(login)->server->providerID,
							    lassoSignatureTypeWithX509,
							    lassoSignatureMethodRsaSha1);
  }
  else {
    LASSO_PROFILE(login)->request = lasso_authn_request_new(LASSO_PROFILE(login)->server->providerID,
							    lassoSignatureTypeNone,
							    0);    
  }

  if (LASSO_PROFILE(login)->request == NULL) {
    return -2;
  }

  LASSO_PROFILE(login)->request_type = lassoMessageTypeAuthnRequest;

  return 0;
}

gint
lasso_login_init_from_authn_request_msg(LassoLogin      *login,
					gchar           *authn_request_msg,
					lassoHttpMethod  authn_request_http_method)
{
  LassoServer *server;
  LassoProvider *remote_provider;
  gchar *protocolProfile;
  xmlChar *md_authnRequestsSigned;
  gboolean must_verify_signature = FALSE;
  gint ret = 0;
  GError *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
  g_return_val_if_fail(authn_request_msg != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

  if (authn_request_http_method != lassoHttpMethodRedirect && \
      authn_request_http_method != lassoHttpMethodPost && \
      authn_request_http_method != lassoHttpMethodSoap) {
    message(G_LOG_LEVEL_CRITICAL, "Invalid HTTP method, it could be REDIRECT, POST or SOAP (LECP)\n.");
    return -2;
  }

  server = LASSO_PROFILE(login)->server;

  /* rebuild request */
  switch (authn_request_http_method) {
  case lassoHttpMethodRedirect:
    /* LibAuthnRequest send by method GET */
    LASSO_PROFILE(login)->request = lasso_authn_request_new_from_export(authn_request_msg,
									lassoNodeExportTypeQuery);
    break;
  case lassoHttpMethodPost:
    /* LibAuthnRequest send by method POST */
    LASSO_PROFILE(login)->request = lasso_authn_request_new_from_export(authn_request_msg,
									lassoNodeExportTypeBase64);
    break;
  case lassoHttpMethodSoap:
    /* LibAuthnRequest send by method SOAP - useful only for LECP */
    LASSO_PROFILE(login)->request = lasso_authn_request_new_from_export(authn_request_msg,
									lassoNodeExportTypeSoap);
    break;
  default:
    break;
  }
  /* verify ASSO_PROFILE(login)-request is an AuthnRequest object */
  if ( LASSO_IS_AUTHN_REQUEST(LASSO_PROFILE(login)->request) == FALSE ) {
    message(G_LOG_LEVEL_CRITICAL, "Message is not an AuthnRequest\n");
    return -1;
  }

  LASSO_PROFILE(login)->request_type = lassoMessageTypeAuthnRequest;

  /* get ProtocolProfile in lib:AuthnRequest */
  protocolProfile = lasso_node_get_child_content(LASSO_PROFILE(login)->request,
						 "ProtocolProfile", NULL, NULL);
  if (protocolProfile == NULL) {
    login->protocolProfile = lassoLoginProtocolProfileBrwsArt;
  }
  else if (xmlStrEqual(protocolProfile, lassoLibProtocolProfileBrwsArt)) {
    login->protocolProfile = lassoLoginProtocolProfileBrwsArt;
  }
  else if (xmlStrEqual(protocolProfile, lassoLibProtocolProfileBrwsPost)) {
    login->protocolProfile = lassoLoginProtocolProfileBrwsPost;
  }
  xmlFree(protocolProfile);

  /* build response */
  switch (login->protocolProfile) {
  case lassoLoginProtocolProfileBrwsPost:
    /* create LibAuthnResponse */
    LASSO_PROFILE(login)->response = lasso_authn_response_new(LASSO_PROFILE(login)->server->providerID,
							      LASSO_PROFILE(login)->request);
    LASSO_PROFILE(login)->response_type = lassoMessageTypeAuthnResponse;
    break;
  case lassoLoginProtocolProfileBrwsArt:
    /* create SamlpResponse */
    LASSO_PROFILE(login)->response = lasso_response_new();
    LASSO_PROFILE(login)->response_type = lassoMessageTypeResponse;
    break;
  }

  /* get remote ProviderID */
  LASSO_PROFILE(login)->remote_providerID = lasso_node_get_child_content(LASSO_PROFILE(login)->request,
									 "ProviderID", NULL, NULL);

  remote_provider = lasso_server_get_provider_ref(LASSO_PROFILE(login)->server,
						  LASSO_PROFILE(login)->remote_providerID,
						  &err);
  if (remote_provider != NULL) {
    /* Is authnRequest signed ? */
    md_authnRequestsSigned = lasso_provider_get_authnRequestsSigned(remote_provider, &err);
    if (md_authnRequestsSigned != NULL) {
      must_verify_signature = xmlStrEqual(md_authnRequestsSigned, "true");
      xmlFree(md_authnRequestsSigned);
    }
    else {
      message(G_LOG_LEVEL_CRITICAL, err->message);
      ret = err->code;
      g_error_free(err);
      return ret;
    }
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_error_free(err);
    return ret;
  }

  /* verify request signature */
  if (must_verify_signature) {
    switch (authn_request_http_method) {
    case lassoHttpMethodGet:
    case lassoHttpMethodRedirect:
      ret = lasso_query_verify_signature(authn_request_msg,
					 remote_provider->public_key,
					 LASSO_PROFILE(login)->server->private_key);
      break;
    case lassoHttpMethodPost:
      /* FIXME detect X509Data ? */
      /* ret = lasso_node_verify_x509_signature(LASSO_PROFILE(login)->request, */
      /* 					remote_provider->ca_certificate); */
      ret = lasso_node_verify_signature(LASSO_PROFILE(login)->request,
					remote_provider->public_key);
      break;
    default:
      ret = 0;
      break;
    }
    
    /* Modify StatusCode if signature is not OK */
    if (ret == LASSO_DS_ERROR_INVALID_SIGNATURE || ret == LASSO_DS_ERROR_SIGNATURE_NOT_FOUND) {
      switch (ret) {
      case LASSO_DS_ERROR_INVALID_SIGNATURE:
	lasso_profile_set_response_status(LASSO_PROFILE(login),
					  lassoLibStatusCodeInvalidSignature);
	break;
      case LASSO_DS_ERROR_SIGNATURE_NOT_FOUND: /* Unsigned AuthnRequest */
	lasso_profile_set_response_status(LASSO_PROFILE(login),
					  lassoLibStatusCodeUnsignedAuthnRequest);
	break;
      }
      return -3;
    }
  }
  return 0;
}

gint
lasso_login_init_request(LassoLogin      *login,
			 gchar           *response_msg,
			 lassoHttpMethod  response_http_method)
{
  LassoNode *response = NULL;
  xmlChar *artifact, *b64_identityProviderSuccinctID;
  gint ret = 0;
  GError *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
  g_return_val_if_fail(response_msg != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

  if (response_http_method != lassoHttpMethodRedirect && \
      response_http_method != lassoHttpMethodPost) {
    message(G_LOG_LEVEL_CRITICAL, "Invalid HTTP method, it could be REDIRECT or POST\n.");
    return -1;
  }

  /* rebuild response (artifact) */
  switch (response_http_method) {
  case lassoHttpMethodRedirect:
    /* artifact by REDIRECT */
    response = lasso_artifact_new_from_query(response_msg);
    break;
  case lassoHttpMethodPost:
    /* artifact by POST */
    response = lasso_artifact_new_from_lares(response_msg, NULL);
    break;
  default:
    break;
  }
  LASSO_PROFILE(login)->response = response;
  LASSO_PROFILE(login)->response_type = lassoMessageTypeArtifact;

  /* get remote identityProviderSuccinctID */
  b64_identityProviderSuccinctID = lasso_artifact_get_b64IdentityProviderSuccinctID(LASSO_ARTIFACT(response), &err);
  if (b64_identityProviderSuccinctID != NULL) {
    LASSO_PROFILE(login)->remote_providerID = lasso_server_get_providerID_from_hash(LASSO_PROFILE(login)->server,
										    b64_identityProviderSuccinctID);
    xmlFree(b64_identityProviderSuccinctID);
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_clear_error(&err);
  }
  
  /* create SamlpRequest */
  artifact = lasso_artifact_get_samlArt(LASSO_ARTIFACT(LASSO_PROFILE(login)->response), &err);
  if (artifact != NULL) {
    LASSO_PROFILE(login)->request = lasso_request_new(artifact);
    LASSO_PROFILE(login)->request_type = lassoMessageTypeRequest;
    xmlFree(artifact);
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_clear_error(&err);
  }

  return ret;
}

gboolean
lasso_login_must_authenticate(LassoLogin *login)
{
  gboolean  must_authenticate = FALSE;
  gboolean  isPassive = TRUE;
  gboolean  forceAuthn = FALSE;
  gchar    *str;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

  /* verify if the user must be authenticated or not */
  str = lasso_node_get_child_content(LASSO_PROFILE(login)->request, "IsPassive",
				     NULL, NULL);
  if (str != NULL) {
    if (xmlStrEqual(str, "false")) {
      isPassive = FALSE;
    }
    xmlFree(str);
  }

  str = lasso_node_get_child_content(LASSO_PROFILE(login)->request, "ForceAuthn",
				     NULL, NULL);
  if (str != NULL) {
    if (xmlStrEqual(str, "true")) {
      forceAuthn = TRUE;
    }
    xmlFree(str);
  }

  if ((forceAuthn == TRUE || LASSO_PROFILE(login)->session == NULL) && isPassive == FALSE) {
    must_authenticate = TRUE;
  }
  else if (LASSO_PROFILE(login)->identity == NULL && isPassive == TRUE) {
    lasso_profile_set_response_status(LASSO_PROFILE(login),
				      lassoLibStatusCodeNoPassive);
  }

  return must_authenticate;
}

gint
lasso_login_process_authn_response_msg(LassoLogin *login,
				       gchar      *authn_response_msg)
{
  gint ret1 = 0, ret2 = 0;
  GError *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
  g_return_val_if_fail(authn_response_msg != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

  LASSO_PROFILE(login)->response = lasso_authn_response_new_from_export(authn_response_msg,
									lassoNodeExportTypeBase64);
  LASSO_PROFILE(login)->response_type = lassoMessageTypeAuthnResponse;

  LASSO_PROFILE(login)->remote_providerID = lasso_node_get_child_content(LASSO_PROFILE(login)->response,
									 "ProviderID",
									 lassoLibHRef,
									 &err);
  if (LASSO_PROFILE(login)->remote_providerID == NULL) {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret1 = err->code;
    g_error_free(err);
  }

  LASSO_PROFILE(login)->msg_relayState = lasso_node_get_child_content(LASSO_PROFILE(login)->response,
								      "RelayState",
								      lassoLibHRef,
								      NULL);

  ret2 = lasso_login_process_response_status_and_assertion(login);

  return ret2 == 0 ? ret1 : ret2;
}

gint
lasso_login_process_request_msg(LassoLogin *login,
				gchar      *request_msg)
{
  gint ret = 0;
  GError *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
  g_return_val_if_fail(request_msg != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

  /* rebuild samlp:Request with request_msg */
  LASSO_PROFILE(login)->request = lasso_request_new_from_export(request_msg,
								lassoNodeExportTypeSoap);
  if (LASSO_PROFILE(login)->request == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Failed to rebuild samlp:Request with request message.\n");
    return LASSO_ERROR_UNDEFINED;
  }
  LASSO_PROFILE(login)->request_type = lassoMessageTypeRequest;

  /* get AssertionArtifact */
  login->assertionArtifact = lasso_node_get_child_content(LASSO_PROFILE(login)->request,
							  "AssertionArtifact",
							  lassoSamlProtocolHRef, &err);
  if (err != NULL) {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_error_free(err);
  }

  return ret;
}

gint
lasso_login_process_response_msg(LassoLogin  *login,
				 gchar       *response_msg)
{
  g_return_val_if_fail(LASSO_IS_LOGIN(login), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
  g_return_val_if_fail(response_msg != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

  /* rebuild samlp:Response with response_msg */
  LASSO_PROFILE(login)->response = lasso_response_new_from_export(response_msg,
								  lassoNodeExportTypeSoap);
  if (LASSO_PROFILE(login)->response == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Failed to rebuild samlp:Response with response message.\n");
    return LASSO_ERROR_UNDEFINED;
  }
  LASSO_PROFILE(login)->response_type = lassoMessageTypeResponse;

  return lasso_login_process_response_status_and_assertion(login);
}

gint
lasso_login_set_assertion(LassoLogin     *login,
			  LassoAssertion *assertion)
{
  LassoNodeClass *assertion_class;
  xmlNodePtr      assertion_xmlNode;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), -1);
  g_return_val_if_fail(LASSO_IS_ASSERTION(assertion), -1);

  login->assertion = LASSO_NODE(g_object_new(LASSO_TYPE_ASSERTION,
					     "use_xsitype", TRUE,
					     NULL));

  assertion_xmlNode = xmlCopyNode(LASSO_NODE_GET_CLASS(assertion)->get_xmlNode(LASSO_NODE(assertion)), 1);
  assertion_class = LASSO_NODE_GET_CLASS(login->assertion);
  assertion_class->set_xmlNode(LASSO_NODE(login->assertion), assertion_xmlNode);

  return 0;
}

gint
lasso_login_set_assertion_from_dump(LassoLogin  *login,
				     gchar       *assertion_dump)
{
  LassoNodeClass *assertion_class;
  LassoNode      *assertion_node;
  xmlNodePtr      assertion_xmlNode;

  g_return_val_if_fail(LASSO_IS_LOGIN(login), -1);
  g_return_val_if_fail(assertion_dump != NULL, -1);

  login->assertion = LASSO_NODE(g_object_new(LASSO_TYPE_ASSERTION,
					     "use_xsitype", TRUE,
					     NULL));
  
  assertion_node = lasso_node_new_from_dump(assertion_dump);
  assertion_xmlNode = xmlCopyNode(LASSO_NODE_GET_CLASS(assertion_node)->get_xmlNode(LASSO_NODE(assertion_node)), 1);
  assertion_class = LASSO_NODE_GET_CLASS(login->assertion);
  assertion_class->set_xmlNode(LASSO_NODE(login->assertion), assertion_xmlNode);

  return 0;
}

/*****************************************************************************/
/* overrided parent class methods                                            */
/*****************************************************************************/

static void
lasso_login_dispose(LassoLogin *login)
{
  if (login->private->dispose_has_run == TRUE) {
    return;
  }
  login->private->dispose_has_run = TRUE;

  debug("Login object 0x%x disposed ...\n", login);

  /* unref reference counted objects */

  parent_class->dispose(G_OBJECT(login));
}

static void
lasso_login_finalize(LassoLogin *login)
{  
  debug("Login object 0x%x finalized ...\n", login);

  g_free(login->assertionArtifact);
  g_free(login->response_dump);

  g_free (login->private);

  parent_class->finalize(G_OBJECT(login));
}

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
lasso_login_instance_init(GTypeInstance   *instance,
			  gpointer         g_class)
{
  LassoLogin *login = LASSO_LOGIN(instance);

  login->private = g_new (LassoLoginPrivate, 1);
  login->private->dispose_has_run = FALSE;

  login->protocolProfile = 0;
  login->assertionArtifact = NULL;
  login->response_dump     = NULL;
}

static void
lasso_login_class_init(LassoLoginClass *class)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS(class);
  
  parent_class = g_type_class_peek_parent(class);
  /* override parent class methods */
  gobject_class->dispose  = (void *)lasso_login_dispose;
  gobject_class->finalize = (void *)lasso_login_finalize;
}

GType lasso_login_get_type() {
  static GType this_type = 0;

  if (!this_type) {
    static const GTypeInfo this_info = {
      sizeof (LassoLoginClass),
      NULL,
      NULL,
      (GClassInitFunc) lasso_login_class_init,
      NULL,
      NULL,
      sizeof(LassoLogin),
      0,
      (GInstanceInitFunc) lasso_login_instance_init,
    };
    
    this_type = g_type_register_static(LASSO_TYPE_PROFILE,
				       "LassoLogin",
				       &this_info, 0);
  }
  return this_type;
}

LassoLogin*
lasso_login_new(LassoServer *server)
{
  LassoLogin *login;

  g_return_val_if_fail(LASSO_IS_SERVER(server), NULL);

  login = LASSO_LOGIN(g_object_new(LASSO_TYPE_LOGIN,
				   "server", lasso_server_copy(server),
				   NULL));
  
  return login;
}

LassoLogin*
lasso_login_new_from_dump(LassoServer *server,
			  gchar       *dump)
{
  LassoLogin *login;
  LassoNode *node_dump, *request_node = NULL, *response_node = NULL;
  gchar *protocolProfile, *export, *type;

  /* nico : assertion vars */
  LassoNode      *assertion_node;
  LassoNodeClass *assertion_class;
  xmlNodePtr      assertion_xmlNode;

  g_return_val_if_fail(LASSO_IS_SERVER(server), NULL);
  g_return_val_if_fail(dump != NULL, NULL);

  login = LASSO_LOGIN(g_object_new(LASSO_TYPE_LOGIN,
				   "server", lasso_server_copy(server),
				   NULL));
  
  node_dump = lasso_node_new_from_dump(dump);

  /* profile attributes */
  LASSO_PROFILE(login)->nameIdentifier    = lasso_node_get_child_content(node_dump, "NameIdentifier",
									 lassoLassoHRef, NULL);
  LASSO_PROFILE(login)->remote_providerID = lasso_node_get_child_content(node_dump, "RemoteProviderID",
									 lassoLassoHRef, NULL);
  LASSO_PROFILE(login)->msg_url        = lasso_node_get_child_content(node_dump, "MsgUrl",
								      lassoLassoHRef, NULL);
  LASSO_PROFILE(login)->msg_body       = lasso_node_get_child_content(node_dump, "MsgBody",
								      lassoLassoHRef, NULL);
  LASSO_PROFILE(login)->msg_relayState = lasso_node_get_child_content(node_dump, "MsgRelayState",
								      lassoLassoHRef, NULL);

  type = lasso_node_get_child_content(node_dump, "RequestType", lassoLassoHRef, NULL);
  LASSO_PROFILE(login)->request_type = atoi(type);
  xmlFree(type);

  /* rebuild request */
  if (LASSO_PROFILE(login)->request_type == lassoMessageTypeAuthnRequest) {
    request_node = lasso_node_get_child(node_dump, "AuthnRequest", lassoLibHRef, NULL);
  }
  else if (LASSO_PROFILE(login)->request_type == lassoMessageTypeRequest) {
    request_node = lasso_node_get_child(node_dump, "Request", lassoSamlProtocolHRef, NULL);
  }
  if (request_node != NULL) {
    export = lasso_node_export(request_node);
    if (LASSO_PROFILE(login)->request_type == lassoMessageTypeAuthnRequest) {
      LASSO_PROFILE(login)->request = lasso_authn_request_new_from_export(export,
									  lassoNodeExportTypeXml);
    }
    else if (LASSO_PROFILE(login)->request_type == lassoMessageTypeRequest) {
      LASSO_PROFILE(login)->request = lasso_request_new_from_export(export,
								    lassoNodeExportTypeXml);
    }
    g_free(export);
    lasso_node_destroy(request_node);
  }

  type = lasso_node_get_child_content(node_dump, "ResponseType", lassoLassoHRef, NULL);
  LASSO_PROFILE(login)->response_type = atoi(type);
  xmlFree(type);

  /* rebuild response */
  if (LASSO_PROFILE(login)->response_type == lassoMessageTypeAuthnResponse) {
    response_node = lasso_node_get_child(node_dump, "AuthnResponse", lassoLibHRef, NULL);
  }
  else if (LASSO_PROFILE(login)->response_type == lassoMessageTypeResponse) {
    response_node = lasso_node_get_child(node_dump, "Response", lassoSamlProtocolHRef, NULL);
  }
  if (response_node != NULL) {
    export = lasso_node_export(response_node);
    if (LASSO_PROFILE(login)->response_type == lassoMessageTypeAuthnResponse) {
      LASSO_PROFILE(login)->response = lasso_authn_response_new_from_export(export,
									    lassoNodeExportTypeXml);
    }
    else if (LASSO_PROFILE(login)->response_type == lassoMessageTypeResponse) {
      LASSO_PROFILE(login)->response = lasso_response_new_from_export(export,
								      lassoNodeExportTypeXml);
    }
    g_free(export);
    lasso_node_destroy(response_node);
  }
  
  type = lasso_node_get_child_content(node_dump, "ProviderType", lassoLassoHRef, NULL);
  LASSO_PROFILE(login)->provider_type = atoi(type);
  xmlFree(type);

  /* login attributes */
  /* nico : get the assertion */
  assertion_node = lasso_node_get_child(node_dump, "Assertion", NULL, NULL);
  if (assertion_node != NULL) {
    login->assertion = g_object_new(LASSO_TYPE_ASSERTION,
				    "use_xsitype", TRUE,
				    NULL);

    assertion_class = LASSO_NODE_GET_CLASS(assertion_node);
    assertion_xmlNode = xmlCopyNode(assertion_class->get_xmlNode(LASSO_NODE(assertion_node)), 1);

    assertion_class = LASSO_NODE_GET_CLASS(login->assertion);
    assertion_class->set_xmlNode(LASSO_NODE(login->assertion), assertion_xmlNode);
    lasso_node_destroy(assertion_node);
  }

  protocolProfile = lasso_node_get_child_content(node_dump, "ProtocolProfile",
						 lassoLassoHRef, NULL);
  if (protocolProfile != NULL) {
    login->protocolProfile = atoi(protocolProfile);
    xmlFree(protocolProfile);
  }
  login->assertionArtifact = lasso_node_get_child_content(node_dump, "AssertionArtifact",
							  lassoLassoHRef, NULL);
  login->response_dump     = lasso_node_get_child_content(node_dump, "ResponseDump",
							  lassoLassoHRef, NULL);

  lasso_node_destroy(node_dump);

  return login;
}
