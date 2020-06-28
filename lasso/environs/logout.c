/* $Id: logout.c,v 1.124 2004/09/07 14:25:55 nclapies Exp $
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

#include <lasso/environs/logout.h>
#include <lasso/xml/errors.h>

#define LASSO_LOGOUT_NODE            "LassoLogout"
#define LASSO_REMOTE_PROVIDERID_NODE "RemoteProviderID"

static GObjectClass *parent_class = NULL;

struct _LassoLogoutPrivate
{
  gboolean dispose_has_run;
};

/*****************************************************************************/
/* public methods                                                            */
/*****************************************************************************/

/**
 * lasso_logout_build_request_msg:
 * @logout: the logout object
 * 
 * This method builds the logout request message.
 *
 * It gets the single logout protocol profile of the remote provider and :
 *    if it is a SOAP method, then it builds the logout request SOAP message,
 *    sets the msg_body attribute, gets the single logout service url
 *    and sets the msg_url attribute of the logout object.
 *
 *    if it is a HTTP-Redirect method, then it builds the logout request QUERY message,
 *    builds the logout request url, sets the msg_url to the logout request url,
 *    sets the msg_body to NULL
 *
 * Optionaly ( if private key and certificates paths are set in server object )
 *    it signs the message (with X509 if a SOAP message,
 *    else with simple signature if a QUERY message )
 * 
 * Return value: 0 if ok, else < 0
 **/
gint
lasso_logout_build_request_msg(LassoLogout *logout)
{
  LassoProfile     *profile;
  LassoProvider    *provider;
  xmlChar          *protocolProfile = NULL;
  GError           *err = NULL;
  gchar            *url = NULL, *query = NULL;
  lassoProviderType remote_provider_type;
  gint              ret = 0;

  g_return_val_if_fail(LASSO_IS_LOGOUT(logout), -1);
  
  profile = LASSO_PROFILE(logout);

  /* get the remote provider type and get the remote provider object */
  if (profile->provider_type == lassoProviderTypeSp) {
    remote_provider_type = lassoProviderTypeIdp;
  }
  else if (profile->provider_type == lassoProviderTypeIdp) {
    remote_provider_type = lassoProviderTypeSp;
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, "Invalid provider type\n");
    ret = -1;
    goto done;
  }
  provider = lasso_server_get_provider_ref(profile->server, profile->remote_providerID, &err);
  if (provider == NULL) {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_error_free(err);
    goto done;
  }

  /* get the prototocol profile of the logout request */
  protocolProfile = lasso_provider_get_singleLogoutProtocolProfile(provider,
								   remote_provider_type,
								   NULL);
  if (protocolProfile == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Single logout protocol profile not found\n");
    ret = -1;
    goto done;
  }
  
  /* build the logout request message */
  if (xmlStrEqual(protocolProfile, lassoLibProtocolProfileSloSpSoap) || \
      xmlStrEqual(protocolProfile, lassoLibProtocolProfileSloIdpSoap)) {
    /* sign the request message */
    lasso_samlp_request_abstract_sign_signature_tmpl(LASSO_SAMLP_REQUEST_ABSTRACT(profile->request),
						     profile->server->private_key,
						     profile->server->certificate);

    /* build the logout request message */
    profile->msg_url  = lasso_provider_get_soapEndpoint(provider,
							remote_provider_type,
							NULL);
    profile->msg_body = lasso_node_export_to_soap(profile->request);
  }
  else if (xmlStrEqual(protocolProfile,lassoLibProtocolProfileSloSpHttp) || \
	   xmlStrEqual(protocolProfile,lassoLibProtocolProfileSloIdpHttp)) {
    /* build and optionaly sign the logout request QUERY message */
    url = lasso_provider_get_singleLogoutServiceURL(provider, remote_provider_type, NULL);
    query = lasso_node_export_to_query(profile->request,
				       profile->server->signature_method,
				       profile->server->private_key);
    if ( (url == NULL) || (query == NULL) ) {
      message(G_LOG_LEVEL_CRITICAL, "Error while building url and query\n");
      ret = -1;
      goto done;
    }

    /* build the msg_url */
    profile->msg_url = g_new(gchar, strlen(url)+strlen(query)+1+1);
    g_sprintf(profile->msg_url, "%s?%s", url, query);
    profile->msg_body = NULL;
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, "Invalid logout protocol profile\n");
    ret = -1;
    goto done;
  }

  done:
  if (protocolProfile != NULL) {
    xmlFree(protocolProfile);
  }
  if (url != NULL) {
    xmlFree(url);
  }
  if (query != NULL) {
    xmlFree(query);
  }

  return ret;
}

/**
 * lasso_logout_build_response_msg:
 * @logout: the logout object
 * 
 * This method builds the logout response message.
 *
 * It gets the request message method and :
 *    if it is a SOAP method, then it builds the logout response SOAP message,
 *    sets the msg_body attribute, gets the single logout service return url
 *    and sets the msg_url attribute of the logout object.
 *
 *    if it is a HTTP-Redirect method, then it builds the logout response QUERY message,
 *    builds the logout response url, sets the msg_url with the logout response url,
 *    sets the msg_body with NULL
 *
 * Optionaly ( if private key and certificates paths are set in server object )
 *    it signs the message (with X509 if a SOAP message,
 *    else with simple signature if a QUERY message )
 * 
 * Return value: 0 if ok, else < 0
 **/
gint
lasso_logout_build_response_msg(LassoLogout *logout)
{
  LassoProfile  *profile;
  LassoProvider *provider;
  gchar         *url = NULL, *query = NULL;
  GError        *err = NULL;
  gint           ret = 0;
  gint           remote_provider_type;

  g_return_val_if_fail(LASSO_IS_LOGOUT(logout), -1);
  
  profile = LASSO_PROFILE(logout);

  /* get the provider */
  provider = lasso_server_get_provider_ref(profile->server, profile->remote_providerID, &err);
  if (provider == NULL) {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_error_free(err);
    goto done;
  }

  /* get the remote provider type */
  if (profile->provider_type == lassoProviderTypeSp) {
    remote_provider_type = lassoProviderTypeIdp;
  }
  else if (profile->provider_type == lassoProviderTypeIdp) {
    remote_provider_type = lassoProviderTypeSp;
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, "Invalid provider type\n");
    ret = -1;
    goto done;
  }

  /* build logout response message */
  switch (profile->http_request_method) {
  case lassoHttpMethodSoap:
    /* optionaly sign the response message */
    if (profile->server->private_key) {
      lasso_samlp_response_abstract_set_signature(LASSO_SAMLP_RESPONSE_ABSTRACT(profile->response),
						  profile->server->signature_method,
						  profile->server->private_key,
						  profile->server->certificate);
    }

    profile->msg_url = NULL;
    profile->msg_body = lasso_node_export_to_soap(profile->response);
    break;
  case lassoHttpMethodRedirect:
    url = lasso_provider_get_singleLogoutServiceReturnURL(provider, remote_provider_type, NULL);
    query = lasso_node_export_to_query(profile->response,
				       profile->server->signature_method,
				       profile->server->private_key);
    if ( (url == NULL) || (query == NULL) ) {
      message(G_LOG_LEVEL_CRITICAL, "Url %s or query %s not found\n", url, query);
      ret = -1;
      goto done;
    }

    profile->msg_url = g_new(gchar, strlen(url)+strlen(query)+1+1);
    g_sprintf(profile->msg_url, "%s?%s", url, query);
    profile->msg_body = NULL;
    break;
  default:
    ret = LASSO_PROFILE_ERROR_MISSING_REQUEST;
    goto done;
  }

  done:
  if (url != NULL) {
    xmlFree(url);
  }
  if (query != NULL) {
    xmlFree(query);
  }

  return ret;
}

/**
 * lasso_logout_destroy:
 * @logout: the logout object
 *
 * destroy the logout object
 * 
 **/
void
lasso_logout_destroy(LassoLogout *logout)
{
  g_object_unref(G_OBJECT(logout));
}

/**
 * lasso_logout_dump:
 * @logout: the logout object
 * 
 * This method dumps the logout object in string a xml message.
 * it first adds profile informations.
 * Next, it adds his logout informations (initial_request, initial_response,
 * initial_remote_providerID and providerID_index).
 * 
 * Return value: a newly allocated string or NULL
 **/
gchar *
lasso_logout_dump(LassoLogout *logout)
{
  LassoNode      *initial_node = NULL, *child_node = NULL;
  gchar          *dump = NULL, *parent_dump = NULL, *providerID_index_str;
  LassoNode      *node = NULL;

  g_return_val_if_fail(LASSO_IS_LOGOUT(logout), NULL);

  parent_dump = lasso_profile_dump(LASSO_PROFILE(logout), "Logout");
  node = lasso_node_new_from_dump(parent_dump);
  g_free(parent_dump);

  if (logout->initial_request != NULL) {
    initial_node = lasso_node_new();
    LASSO_NODE_GET_CLASS(initial_node)->set_name(initial_node, "InitialLogoutResquest");
    child_node = lasso_node_copy(logout->initial_request);
    LASSO_NODE_GET_CLASS(initial_node)->add_child(initial_node, child_node, FALSE);
    lasso_node_destroy(child_node);

    LASSO_NODE_GET_CLASS(node)->add_child(node, initial_node, FALSE);
  }

  if (logout->initial_response != NULL) {
    initial_node = lasso_node_new();
    LASSO_NODE_GET_CLASS(initial_node)->set_name(initial_node, "InitialLogoutResponse");
    child_node = lasso_node_copy(logout->initial_response);
    LASSO_NODE_GET_CLASS(initial_node)->add_child(initial_node, child_node, FALSE);
    lasso_node_destroy(child_node);

    LASSO_NODE_GET_CLASS(node)->add_child(node, initial_node, FALSE);
  }

  if (logout->initial_remote_providerID != NULL) {
    LASSO_NODE_GET_CLASS(node)->new_child(node, "InitialRemoteProviderID",
					  logout->initial_remote_providerID, FALSE);
  }
  
  /* add providerID_index */
  providerID_index_str = g_strdup_printf("%d", logout->providerID_index);
  LASSO_NODE_GET_CLASS(node)->new_child(node, "ProviderIDIndex",
					providerID_index_str, FALSE);

  dump = lasso_node_export(node);

  lasso_node_destroy(node);

  return dump;
}

/**
 * lasso_logout_get_next_providerID:
 * @logout: the logout object
 * 
 * This method returns the provider id from providerID_index in list of providerIDs in session object.
 * excepted the initial service provider id :
 *    It gets the remote provider id in session from the logout providerID_index.
 *    If it is the initial remote provider id, then it asks the next provider id
 *    from providerID_index + 1;
 * 
 * Return value: a newly allocated string or NULL
 **/
gchar*
lasso_logout_get_next_providerID(LassoLogout *logout)
{
  LassoProfile *profile;
  gchar        *providerID;

  g_return_val_if_fail(LASSO_IS_LOGOUT(logout), NULL);
  profile = LASSO_PROFILE(logout);

  g_return_val_if_fail(LASSO_IS_SESSION(profile->session), NULL);
  providerID = lasso_session_get_provider_index(profile->session, logout->providerID_index);
  logout->providerID_index++;
  /* if it is the provider id of the SP requester, then get the next */
  if (logout->initial_remote_providerID && xmlStrEqual(providerID, logout->initial_remote_providerID)) {
    providerID = lasso_session_get_provider_index(profile->session, logout->providerID_index);
    logout->providerID_index++;
  }
  
  return providerID;
}

/**
 * lasso_logout_init_request:
 * @logout: 
 * @remote_providerID: 
 * @request_method: if set, then it get the protocol profile in metadata
 *                  corresponding of this HTTP request method.
 *
 * First it verifies session and identity are set.
 * Next, gets federation with the remote provider and gets the name identifier for the request.
 *       gets the protocol profile and build the logout request object.
 * If the local provider is a Service Provider and if the protocol profile is a HTTP Redirect / GET method,
 *       then removes the assertion.
 * 
 * Return value: 0 if ok, else < 0
 **/
gint
lasso_logout_init_request(LassoLogout    *logout,
			  gchar          *remote_providerID,
			  lassoHttpMethod request_method) /* FIXME : support this param to allow the user to choose the request method */
{
  LassoProfile      *profile        = NULL;
  LassoProvider     *provider       = NULL;
  LassoNode         *nameIdentifier = NULL;
  LassoFederation   *federation     = NULL;
  xmlChar           *content        = NULL, *nameQualifier = NULL, *format = NULL;
  xmlChar           *singleLogoutProtocolProfile = NULL;
  GError            *err = NULL;
  gboolean           is_http_redirect_get_method = FALSE;
  gint               ret = 0;

  g_return_val_if_fail(LASSO_IS_LOGOUT(logout), -1);

  profile = LASSO_PROFILE(logout);

  /* verify if the identity and session exist */
  if (profile->identity == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Identity not found\n");
    ret = -1;
    goto done;
  }
  if (profile->session == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Session not found\n");
    ret = -1;
    goto done;
  }

  /* get the remote provider id */
  /* If remote_providerID is NULL, then get the first remote provider id in session */
  if (remote_providerID == NULL) {
    profile->remote_providerID = lasso_session_get_first_providerID(profile->session);
  }
  else {
    profile->remote_providerID = g_strdup(remote_providerID);
  }
  if (profile->remote_providerID == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "No remote provider id to send the logout request\n");
    ret = -1;
    goto done;
  }

  /* get federation */
  federation = lasso_identity_get_federation(profile->identity, profile->remote_providerID);
  if (federation == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Federation not found\n");
    ret = -1;
    goto done;
  }

  /* get the name identifier */
  switch (profile->provider_type) {
  case lassoProviderTypeSp:
    /* SP : get the local name identifier, if it is NULL, then get the remote name identifier */
    nameIdentifier = lasso_federation_get_local_nameIdentifier(federation);
    if (nameIdentifier == NULL) {
      nameIdentifier = lasso_federation_get_remote_nameIdentifier(federation);
    }
    break;
  case lassoProviderTypeIdp:
    /* IDP : get the remote name identifier, if it is NULL, then get the local name identifier */
    nameIdentifier = lasso_federation_get_remote_nameIdentifier(federation);
    if (nameIdentifier == NULL) {
      nameIdentifier = lasso_federation_get_local_nameIdentifier(federation);
    }
    break;
  default:
    message(G_LOG_LEVEL_CRITICAL, "Invalid provider type\n");
    ret = -1;
    goto done;
  }

  if (nameIdentifier == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Name identifier not found for %s\n",
	    profile->remote_providerID);
    ret = -1;
    goto done;
  }

  /* get name identifier attributes */
  content = lasso_node_get_content(nameIdentifier, NULL);
  nameQualifier = lasso_node_get_attr_value(nameIdentifier, "NameQualifier", NULL);
  format = lasso_node_get_attr_value(nameIdentifier, "Format", NULL);
  
  /* get the provider */
  provider = lasso_server_get_provider_ref(profile->server, profile->remote_providerID, &err);
  if (provider == NULL) {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    ret = err->code;
    g_error_free(err);
    goto done;
  }

  /* Get the single logout protocol profile */
  if (profile->provider_type == lassoProviderTypeIdp) {
    singleLogoutProtocolProfile = lasso_provider_get_singleLogoutProtocolProfile(provider, lassoProviderTypeSp, NULL);
  }
  else if (profile->provider_type == lassoProviderTypeSp) {
    singleLogoutProtocolProfile = lasso_provider_get_singleLogoutProtocolProfile(provider, lassoProviderTypeIdp, NULL);
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, "Invalid provider type\n");
    ret = -1;
    goto done;
  }
  if (singleLogoutProtocolProfile == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Single logout protocol profile not found\n");
    ret = -1;
    goto done;
  }

  /* before setting profile->request, verify if it is already set */
  if (LASSO_IS_LOGOUT_REQUEST(profile->request) == TRUE) {
    lasso_node_destroy(profile->request);
    profile->request = NULL;
  }

  /* build a new request object from single logout protocol profile */
  if (xmlStrEqual(singleLogoutProtocolProfile, lassoLibProtocolProfileSloSpSoap) || \
      xmlStrEqual(singleLogoutProtocolProfile, lassoLibProtocolProfileSloIdpSoap)) {
    profile->request = lasso_logout_request_new(profile->server->providerID,
						content,
						nameQualifier,
						format,
						lassoSignatureTypeWithX509,
						lassoSignatureMethodRsaSha1);
  }
  else if (xmlStrEqual(singleLogoutProtocolProfile, lassoLibProtocolProfileSloSpHttp) || \
	   xmlStrEqual(singleLogoutProtocolProfile, lassoLibProtocolProfileSloIdpHttp)) {
    is_http_redirect_get_method = TRUE;
    profile->request = lasso_logout_request_new(profile->server->providerID,
						content,
						nameQualifier,
						format,
						lassoSignatureTypeNone,
						0);
  }
  else {
    message(G_LOG_LEVEL_CRITICAL, "Invalid single logout protocol profile : %s\n", singleLogoutProtocolProfile);
    ret = -1;
    goto done;
  }
  if (LASSO_IS_LOGOUT_REQUEST(profile->request) == FALSE) {
    message(G_LOG_LEVEL_CRITICAL, "Error while building the request\n");
    ret = -1;
    goto done;
  }

  /* set the name identifier in logout object */
  profile->nameIdentifier = content;

  /* if logout request from a SP and if an HTTP Redirect / GET method, then remove assertion */
  if (profile->provider_type == lassoProviderTypeSp && is_http_redirect_get_method == TRUE) {
    lasso_session_remove_assertion(profile->session, profile->remote_providerID);
  }

  done:
  if (federation != NULL) {
    lasso_federation_destroy(federation);
  }
  if (nameIdentifier != NULL ) {
    lasso_node_destroy(nameIdentifier);
  }
  if (nameQualifier != NULL) {
    xmlFree(nameQualifier);
  }
  if (format != NULL) {
    xmlFree(format);
  }
  if (singleLogoutProtocolProfile != NULL) {
    xmlFree(singleLogoutProtocolProfile);
  }

  return ret;
}

/**
 * lasso_logout_process_request_msg:
 * @logout: the logout object
 * @request_msg: the logout request message
 * @request_method: the logout request method
 * 
 * Processes a logout request.
 *    if it is a SOAP request method then it builds the logout request object
 *    from the SOAP message and optionaly verifies the signature of the logout request.
 * 
 *    if it is a HTTP-Redirect request method then it builds the logout request object
 *    from the QUERY message and verify the signature. If there is an error while parsing the query,
 *    then returns the code error LASSO_PROFILE_ERROR_INVALID_QUERY.
 *
 *    Saves the HTTP request method.
 *    Saves the name identifier.
 *
 * Return value: 0 if OK else LASSO_PROFILE_ERROR_INVALID_QUERY or < 0
 **/
gint lasso_logout_process_request_msg(LassoLogout     *logout,
				      gchar           *request_msg,
				      lassoHttpMethod  request_method)
{
  LassoProfile  *profile;
  LassoProvider *provider;
  gchar         *remote_providerID = NULL;
  gint           ret = 0;
  GError        *err = NULL;

  g_return_val_if_fail(LASSO_IS_LOGOUT(logout), -1);
  g_return_val_if_fail(request_msg != NULL, -1);

  profile = LASSO_PROFILE(logout);

  /* rebuild the request message and optionaly verify the signature */
  switch (request_method) {
  case lassoHttpMethodSoap:
    profile->request = lasso_logout_request_new_from_export(request_msg,
							    lassoNodeExportTypeSoap);

    /* verify requets is a LogoutRequest */
    if (LASSO_IS_LOGOUT_REQUEST(profile->request) == FALSE) {
      message(G_LOG_LEVEL_CRITICAL, "Message is not a LogoutRequest\n");
      ret = -1;
      goto done;
    }

    /* verify signature  */
    remote_providerID = lasso_node_get_child_content(profile->request, "ProviderID", NULL, NULL);
    if (remote_providerID == NULL) {
      message(G_LOG_LEVEL_CRITICAL, "ProviderID not found\n");
      ret = -1;
      goto done;
    }
    provider = lasso_server_get_provider_ref(profile->server, remote_providerID, &err);
    if (provider == NULL) {
      message(G_LOG_LEVEL_CRITICAL, err->message);
      ret = err->code;
      g_error_free(err);
      goto done;
    }
    if (provider->ca_certificate != NULL) {
      ret = lasso_node_verify_x509_signature(profile->request, provider->ca_certificate);
    }
    break;
  case lassoHttpMethodRedirect:
    profile->request = lasso_logout_request_new_from_export(request_msg,
							    lassoNodeExportTypeQuery);
    /* if problem while rebuilding the response, then return invalid query code error */
    if (LASSO_IS_LOGOUT_REQUEST(profile->request) == FALSE) {
      ret = LASSO_PROFILE_ERROR_INVALID_QUERY;
      goto done;
    }

    break;
  default:
    message(G_LOG_LEVEL_CRITICAL, "Invalid request method\n");
    ret = -1;
    goto done;
  }

  /* set the http request method */
  profile->http_request_method = request_method;

  /* Set the NameIdentifier */
  profile->nameIdentifier = lasso_node_get_child_content(profile->request,
							 "NameIdentifier",
							 NULL, NULL);

  done:
  if (remote_providerID != NULL ) {
    xmlFree(remote_providerID);
  }

  return ret;
}

/**
 * lasso_logout_process_response_msg:
 * @logout: the logout object
 * @response_msg: the response message
 * @response_method: the response method
 * 
 * Parses the response message and builds the response object :
 *      if there is an error while parsing the HTTP Redirect / GET message,
 *          then returns a LASSO_PROFILE_ERROR_INVALID_QUERY code error.
 * Get the status code value :
 *     if it is not success, then if the local provider is a Service Provider and response method is SOAP,
 *         then builds a new logout request message for HTTP Redirect / GET method and returns the code error
 *         LASSO_LOGOUT_ERROR_UNSUPPORTED_PROFILE and exits.
 *
 * Sets the remote provider id.
 * Sets the relay state.
 * 
 * if it is a SOAP method or, IDP provider type and http method is Redirect / GET, then removes assertion.
 * 
 * If local server is an Identity Provider and if there is no more assertion (Identity Provider has logged out every Service Providers),
 *     then restores the initial response.
 * Return value: 0 if OK else LASSO_LOGOUT_ERROR_UNSUPPORTED_PROFILE or < 0
 **/
gint
lasso_logout_process_response_msg(LassoLogout     *logout,
				  gchar           *response_msg,
				  lassoHttpMethod  response_method)
{
  gchar        *last_providerID = NULL;
  xmlChar      *statusCodeValue = NULL;
  LassoNode    *statusCode = NULL;
  LassoProfile *profile = NULL;
  GError       *err = NULL;
  gint          ret = 0;

  g_return_val_if_fail(LASSO_IS_LOGOUT(logout), -1);
  g_return_val_if_fail(response_msg != NULL, -1);

  profile = LASSO_PROFILE(logout);

  /* before verify if profile->response is set */
  if (LASSO_IS_LOGOUT_RESPONSE(profile->response) == TRUE) {
    lasso_node_destroy(profile->response);
    profile->response = NULL;
  }

  /* build logout response object */
  switch (response_method) {
  case lassoHttpMethodSoap:
    profile->response = lasso_logout_response_new_from_export(response_msg, lassoNodeExportTypeSoap);
    break;
  case lassoHttpMethodRedirect:
    profile->response = lasso_logout_response_new_from_export(response_msg, lassoNodeExportTypeQuery);
    /* if problem while rebuilding the response, then return invalid query code error */
    if (LASSO_IS_LOGOUT_RESPONSE(profile->response) == FALSE) {
      ret = LASSO_PROFILE_ERROR_INVALID_QUERY;
      goto done;
    }
    break;
  default:
    message(G_LOG_LEVEL_CRITICAL, "Invalid response method\n");
    ret = -1;
    goto done;
  }
  if (LASSO_IS_LOGOUT_RESPONSE(profile->response) == FALSE) {
    message(G_LOG_LEVEL_CRITICAL, "Message is not a LogoutResponse\n");
    ret = -1;
    goto done;
  }

  /* get the status code */
  statusCode = lasso_node_get_child(profile->response, "StatusCode", NULL, NULL);
  if (statusCode == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "StatusCode node not found\n");
    ret = -1;
    goto done;
  }
  statusCodeValue = lasso_node_get_attr_value(statusCode, "Value", NULL);

  if (!xmlStrEqual(statusCodeValue, lassoSamlStatusCodeSuccess)) {

    /* At SP, if the request method was a SOAP type, then rebuild the request message with HTTP method */
    if (xmlStrEqual(statusCodeValue, lassoLibStatusCodeUnsupportedProfile) && \
	profile->provider_type == lassoProviderTypeSp && \
	profile->http_request_method == lassoHttpMethodSoap) {
      /* temporary vars */
      LassoProvider *provider;
      gchar *url, *query;

      provider = lasso_server_get_provider_ref(profile->server, profile->remote_providerID, &err);
      if (provider == NULL) {
	message(G_LOG_LEVEL_CRITICAL, err->message);
	ret = err->code;
	g_error_free(err);
	goto done;
      }

      /* FIXME : verify the IDP support a HTTP method */

      /* Build and optionaly sign the logout request QUERY message */
      url = lasso_provider_get_singleLogoutServiceURL(provider, lassoProviderTypeIdp, NULL);
      query = lasso_node_export_to_query(profile->request,
					 profile->server->signature_method,
					 profile->server->private_key);
      profile->msg_url = g_new(gchar, strlen(url)+strlen(query)+1+1);
      g_sprintf(profile->msg_url, "%s?%s", url, query);
      profile->msg_body = NULL;

      /* send a HTTP Redirect / GET method, so first remove session */
      lasso_session_remove_assertion(profile->session, profile->remote_providerID);

      ret = LASSO_LOGOUT_ERROR_UNSUPPORTED_PROFILE;
    }
    else {
      message(G_LOG_LEVEL_CRITICAL, "Status code is not success : %s\n", statusCodeValue);
      ret = -1;
    }

    goto done;
  }

  /* LogoutResponse status code value is ok */

  /* set the remote provider id */
  profile->remote_providerID = lasso_node_get_child_content(profile->response,
							    "ProviderID",
							    lassoLibHRef,
							    NULL);

  /* set the msg_relayState */
  profile->msg_relayState = lasso_node_get_child_content(profile->response, "RelayState", lassoLibHRef, NULL);

  /* if SOAP method or, if IDP provider type and HTTP Redirect, then remove assertion */
  if ( (response_method == lassoHttpMethodSoap) || (profile->provider_type == lassoProviderTypeIdp && response_method == lassoHttpMethodRedirect) ) {
    ret = lasso_session_remove_assertion(profile->session, profile->remote_providerID);
    if (profile->provider_type == lassoProviderTypeIdp && logout->providerID_index >= 0) {
      logout->providerID_index--;
    }
  }

  /* If at IDP and if there is no more assertion, IDP a logged out every SPs, return the initial response to initial SP */
  if (profile->provider_type == lassoProviderTypeIdp && logout->initial_remote_providerID && profile->session->providerIDs->len == 0) {
    if (profile->remote_providerID != NULL) {
      g_free(profile->remote_providerID);
    }
    if (profile->request != NULL) {
      lasso_node_destroy(profile->request);
    }
    if (profile->response != NULL) {
      lasso_node_destroy(profile->response);
    }

    profile->remote_providerID = logout->initial_remote_providerID;
    profile->request = logout->initial_request;
    profile->response = logout->initial_response;

    logout->initial_remote_providerID = NULL;
    logout->initial_request = NULL;
    logout->initial_response = NULL;
  }

  done:
  if (last_providerID != NULL) {
    g_free(last_providerID);
  }

  return ret;
}

/**
 * lasso_logout_reset_providerID_index:
 * @logout: the logout object
 * 
 * Reset the providerID_index attribute (set to 0).
 * 
 * Return value: 0
 **/
gint lasso_logout_reset_providerID_index(LassoLogout *logout)
{
  g_return_val_if_fail(LASSO_IS_LOGOUT(logout), -1);

  logout->providerID_index = 0;

  return 0;
}

/**
 * lasso_logout_validate_request:
 * @logout: the logout object
 * 
 * Sets the remote provider id
 * Sets a logout response with status code value to success.
 * Verifies federation and authentication.
 * If the request http method is a SOAP method, then verifies every other
 *     Service Providers supports SOAP method : if not, then sets status code value to
 *     UnsupportedProfile and returns a code error with LASSO_LOGOUT_ERROR_UNSUPPORTED_PROFILE.
 *
 * Every tests are ok, then removes assertion.
 * (profile->provider_type == lassoProviderTypeIdp && profile->session->providerIDs->len >= 1)
 * If local server is an Identity Provider and if there is more than one Service Provider
 *     (except the initial Service Provider),
 *     then saves the initial request, response and remote provider id.
 *
 * Return value: O if OK else < 0
 **/
gint
lasso_logout_validate_request(LassoLogout *logout)
{
  LassoProfile    *profile;
  LassoFederation *federation = NULL;
  LassoNode       *nameIdentifier, *assertion;
  LassoNode       *statusCode;
  LassoNodeClass  *statusCode_class;
  xmlChar         *remote_providerID;
  gint             ret = 0;

  g_return_val_if_fail(LASSO_IS_LOGOUT(logout), -1);

  profile = LASSO_PROFILE(logout);

  /* verify logout request */
  if (profile->request == NULL) {
    ret = LASSO_PROFILE_ERROR_MISSING_REQUEST;
    goto done;
  }

  /* Set the remote provider id from the request */
  remote_providerID = lasso_node_get_child_content(profile->request, "ProviderID",
						   NULL, NULL);
  if (remote_providerID == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "ProviderID in LogoutRequest not found\n");
    ret = -1;
    goto done;
  }
  profile->remote_providerID = remote_providerID;

  /* Set LogoutResponse */
  switch (profile->http_request_method) {
  case lassoHttpMethodSoap:
    profile->response = lasso_logout_response_new(profile->server->providerID,
						  lassoSamlStatusCodeSuccess,
						  profile->request,
						  lassoSignatureTypeWithX509,
						  lassoSignatureMethodRsaSha1);
    break;
  case lassoHttpMethodRedirect:
    profile->response = lasso_logout_response_new(profile->server->providerID,
						  lassoSamlStatusCodeSuccess,
						  profile->request,
						  lassoSignatureTypeNone,
						  0);
    break;
  default:
    message(G_LOG_LEVEL_CRITICAL, "Invalid HTTP request method\n");
    ret = -1;
    goto done;
  }
  if (LASSO_IS_LOGOUT_RESPONSE(profile->response) == FALSE) {
    message(G_LOG_LEVEL_CRITICAL, "Error while building response\n");
    ret = -1;
    goto done;
  }

  /* Get the name identifier */
  nameIdentifier = lasso_node_get_child(profile->request, "NameIdentifier",
					NULL, NULL);
  if (nameIdentifier == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Name identifier not found in logout request\n");
    lasso_profile_set_response_status(profile, lassoLibStatusCodeFederationDoesNotExist);
    ret = -1;
    goto done;
  }

  /* verify authentication */
  if (profile->identity == NULL) {
    message(G_LOG_LEVEL_WARNING, "Identity not found\n");
    /* FIXME : use RequestDenied if no identity found ? */
    lasso_profile_set_response_status(profile, lassoSamlStatusCodeRequestDenied);
    ret = -1;
    goto done;
  }
  assertion = lasso_session_get_assertion(profile->session, remote_providerID);
  if (assertion == NULL) {
    message(G_LOG_LEVEL_WARNING, "%s has no assertion\n", remote_providerID);
    lasso_profile_set_response_status(profile, lassoSamlStatusCodeRequestDenied);
    ret = -1;
    goto done;
  }
  lasso_node_destroy(assertion);

  /* Verify federation */
  federation = lasso_identity_get_federation(profile->identity, remote_providerID);
  if (federation == NULL) {
    message(G_LOG_LEVEL_WARNING, "No federation for %s\n", remote_providerID);
    lasso_profile_set_response_status(profile, lassoLibStatusCodeFederationDoesNotExist);
    ret = -1;
    goto done;
  }

  if (lasso_federation_verify_nameIdentifier(federation, nameIdentifier) == FALSE) {
    message(G_LOG_LEVEL_WARNING, "No name identifier for %s\n", remote_providerID);
    lasso_profile_set_response_status(profile, lassoLibStatusCodeFederationDoesNotExist);
    ret = -1;
    goto done;
  }

  /* if SOAP request method at IDP then verify all the remote service providers support SOAP protocol profile.
     If one remote authenticated principal service provider doesn't support SOAP
     then return UnsupportedProfile to original service provider */
  if (profile->provider_type == lassoProviderTypeIdp && profile->http_request_method == lassoHttpMethodSoap) {
    gboolean all_http_soap;
    LassoProvider *provider;
    gchar *providerID, *protocolProfile;
    int i;
    
    all_http_soap = TRUE;

    for (i = 0; i<profile->server->providers->len; i++) {
      provider = g_ptr_array_index(profile->server->providers, i);
      providerID = lasso_provider_get_providerID(provider);

      /* if the original service provider then continue */
      if (xmlStrEqual(remote_providerID, providerID)) {
	continue;
      }

      /* if principal is not authenticated with this remote service provider, continue */
      assertion = lasso_session_get_assertion(profile->session, providerID);
      if (assertion == NULL) {
	continue;
      }

      /* if protocolProfile is SOAP continue else break */
      protocolProfile = lasso_provider_get_singleLogoutProtocolProfile(provider, lassoProviderTypeSp, NULL);
      if (protocolProfile == NULL || !xmlStrEqual(protocolProfile, lassoLibProtocolProfileSloSpSoap)) {
	all_http_soap = FALSE;
	break;
      }
      if (protocolProfile != NULL) {
	xmlFree(protocolProfile);
      }
      if (providerID != NULL) {
	xmlFree(providerID);
      }
    }

    if (all_http_soap==FALSE) {
      lasso_profile_set_response_status(profile, lassoLibStatusCodeUnsupportedProfile);
      ret = LASSO_LOGOUT_ERROR_UNSUPPORTED_PROFILE;
      goto done;
    }
  }

  /* FIXME : set the status code in response */

  /* authentication is ok, federation is ok, propagation support is ok, remove federation */
  lasso_session_remove_assertion(profile->session, profile->remote_providerID);

  /* if at IDP and nb sp logged > 1, then backup remote provider id,
   * request and response
   * REMARK : if only initial service provider was logged,
   *   then profile->session->providerIDs->len == 0,
   *   else profile->session->providerIDs->len >= 1
   */
  if (profile->provider_type == lassoProviderTypeIdp && profile->session->providerIDs->len >= 1) {
    logout->initial_remote_providerID = profile->remote_providerID;
    logout->initial_request = profile->request;
    logout->initial_response = profile->response;

    profile->remote_providerID = NULL;
    profile->request = NULL;
    profile->response = NULL;
  }

  done:
  if (federation != NULL) {
    lasso_federation_destroy(federation);
  }

  return ret;
}

/*****************************************************************************/
/* overrided parent class methods                                            */
/*****************************************************************************/

static void
lasso_logout_dispose(LassoLogout *logout)
{
  if (logout->private->dispose_has_run) {
    return;
  }
  logout->private->dispose_has_run = TRUE;

  debug("Logout object 0x%x disposed ...\n", logout);

  /* unref reference counted objects */
  lasso_node_destroy(logout->initial_request);
  lasso_node_destroy(logout->initial_response);

  parent_class->dispose(G_OBJECT(logout));
}

static void
lasso_logout_finalize(LassoLogout *logout)
{  
  debug("Logout object 0x%x finalized ...\n", logout);

  g_free(logout->initial_remote_providerID);

  g_free(logout->private);

  parent_class->finalize(G_OBJECT(logout));
}

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
lasso_logout_instance_init(GTypeInstance   *instance,
			   gpointer         g_class)
{
  LassoLogout *logout = LASSO_LOGOUT(instance);

  logout->private = g_new (LassoLogoutPrivate, 1);
  logout->private->dispose_has_run = FALSE;

  logout->initial_request = NULL;
  logout->initial_response = NULL;
  logout->initial_remote_providerID = NULL;

  logout->providerID_index = 0;
}

static void
lasso_logout_class_init(LassoLogoutClass *class)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS(class);
  
  parent_class = g_type_class_peek_parent(class);
  /* override parent class methods */
  gobject_class->dispose  = (void *)lasso_logout_dispose;
  gobject_class->finalize = (void *)lasso_logout_finalize;
}

GType lasso_logout_get_type() {
  static GType this_type = 0;

  if (!this_type) {
    static const GTypeInfo this_info = {
      sizeof (LassoLogoutClass),
      NULL,
      NULL,
      (GClassInitFunc) lasso_logout_class_init,
      NULL,
      NULL,
      sizeof(LassoLogout),
      0,
      (GInstanceInitFunc) lasso_logout_instance_init,
    };
    
    this_type = g_type_register_static(LASSO_TYPE_PROFILE,
				       "LassoLogout",
				       &this_info, 0);
  }
  return this_type;
}

/**
 * lasso_logout_new:
 * @server: the logout object
 * @provider_type: the provider type (service provider or identity provider)
 * 
 * initialises a new logout object
 * 
 * Return value: a new instance of logout object or NULL
 **/
LassoLogout*
lasso_logout_new(LassoServer       *server,
		 lassoProviderType  provider_type)
{
  LassoLogout *logout;

  g_return_val_if_fail(LASSO_IS_SERVER(server), NULL);

  /* set the logout object */
  logout = g_object_new(LASSO_TYPE_LOGOUT,
			"server", lasso_server_copy(server),
			"provider_type", provider_type,
			NULL);

  return logout;
}

LassoLogout*
lasso_logout_new_from_dump(LassoServer *server,
			   gchar       *dump)
{
  LassoLogout  *logout;
  LassoProfile *profile;
  LassoNode    *node_dump, *request_node, *response_node;
  LassoNode    *initial_request_node, *initial_response_node;
  gchar        *type, *export, *providerID_index_str;

  g_return_val_if_fail(LASSO_IS_SERVER(server), NULL);
  g_return_val_if_fail(dump != NULL, NULL);

  logout = LASSO_LOGOUT(g_object_new(LASSO_TYPE_LOGOUT,
				     "server", lasso_server_copy(server),
				     NULL));

  profile = LASSO_PROFILE(logout);

  node_dump = lasso_node_new_from_dump(dump);

  /* profile attributes */
  profile->nameIdentifier    = lasso_node_get_child_content(node_dump, "NameIdentifier",
							    lassoLassoHRef, NULL);
  profile->remote_providerID = lasso_node_get_child_content(node_dump, "RemoteProviderID",
							    lassoLassoHRef, NULL);
  profile->msg_url           = lasso_node_get_child_content(node_dump, "MsgUrl",
							    lassoLassoHRef, NULL);
  profile->msg_body          = lasso_node_get_child_content(node_dump, "MsgBody",
							    lassoLassoHRef, NULL);
  profile->msg_relayState    = lasso_node_get_child_content(node_dump, "MsgRelayState",
							    lassoLassoHRef, NULL);

  /* rebuild request */
  request_node = lasso_node_get_child(node_dump, "LogoutRequest", lassoLibHRef, NULL);

  if (LASSO_IS_NODE(request_node) == TRUE) {
    export = lasso_node_export(request_node);
    profile->request = lasso_logout_request_new_from_export(export,
							    lassoNodeExportTypeXml);
    g_free(export);
    lasso_node_destroy(request_node);
  }


  /* rebuild response */
  response_node = lasso_node_get_child(node_dump, "LogoutResponse", lassoLibHRef, NULL);
  if (response_node != NULL) {
    export = lasso_node_export(response_node);
    profile->response = lasso_logout_response_new_from_export(export,
							      lassoNodeExportTypeXml);
    g_free(export);
    lasso_node_destroy(response_node);
  }
  
  /* provider type */
  type = lasso_node_get_child_content(node_dump, "ProviderType", lassoLassoHRef, NULL);
  profile->provider_type = atoi(type);
  xmlFree(type);

  /* logout attributes */
  /* Initial logout request */
  initial_request_node = lasso_node_get_child(node_dump, "InitialRequest", lassoLassoHRef, NULL);
  if (initial_request_node != NULL) {
    request_node = lasso_node_get_child(node_dump, "LogoutRequest", lassoLibHRef, NULL);
    export = lasso_node_export(request_node);
    profile->request = lasso_logout_request_new_from_export(export,
							    lassoNodeExportTypeXml);
    g_free(export);
    lasso_node_destroy(request_node);
  }

  /* Initial logout response */
  initial_response_node = lasso_node_get_child(node_dump, "InitialResponse", lassoLassoHRef, NULL);
  if (initial_response_node != NULL) {
    response_node = lasso_node_get_child(node_dump, "LogoutResponse", lassoLibHRef, NULL);
    export = lasso_node_export(response_node);
    profile->response = lasso_logout_response_new_from_export(export,
							      lassoNodeExportTypeXml);
    g_free(export);
    lasso_node_destroy(response_node);
  }

  /* Initial logout remote provider id */
  logout->initial_remote_providerID = lasso_node_get_child_content(node_dump, "InitialRemoteProviderID", lassoLassoHRef, NULL);

  /* index provider id */

  providerID_index_str = lasso_node_get_child_content(node_dump, "ProviderIDIndex", NULL, NULL);

  if (providerID_index_str == NULL) {
    message(G_LOG_LEVEL_CRITICAL, "Index ProviderID not found\n");
  }
  else {
    logout->providerID_index = atoi(providerID_index_str);
  }

  return logout;
}
