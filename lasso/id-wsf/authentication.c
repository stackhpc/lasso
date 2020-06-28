/* $Id: authentication.c,v 1.10 2006/03/04 15:50:31 fpeters Exp $ 
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004, 2005 Entr'ouvert
 * http://lasso.entrouvert.org
 * 
 * Authors: See AUTHORS file in top-level directory.
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

#include <lasso/id-wsf/authentication.h>
#include <lasso/xml/sa_sasl_request.h>
#include <lasso/xml/sa_sasl_response.h>
#include <lasso/xml/soap_binding_correlation.h>
#include <xmlsec/base64.h>

/* SASL client callbacks (for secret, login, password, ... ) */
static sasl_callback_t lasso_sasl_callbacks[5];

static int
lasso_sasl_cb_log(void* context, int priority, const char* message)
{
	printf("SASL lasso_sasl_cb_log() : %s\n", message);

	return SASL_OK;
}

static int
lasso_sasl_cb_authname(void* context, int id, const char** result, unsigned* len)
{
	LassoUserAccount *account;
	int ret = SASL_FAIL;

	*result = NULL;
	if (len) *len = 0;

	account = (LassoUserAccount *)context;
	if (account != NULL && account->login != NULL) {
		*result = g_strdup(account->login);
		if (len) *len = strlen(account->login);
		ret = SASL_OK;
	} 

	return ret;
}

static int
lasso_sasl_cb_pass(sasl_conn_t* conn, void* context, int id, sasl_secret_t** psecret)
{
	static sasl_secret_t *s;
	LassoUserAccount *account;
	int ret = SASL_FAIL;
   
	account = (LassoUserAccount *)context;
	if (account != NULL && account->password != NULL) {
		s = (sasl_secret_t*) g_malloc0(sizeof(sasl_secret_t) + strlen(account->password));

		strcpy(s->data, account->password);
		s->len = strlen(account->password);

		*psecret = s;

		ret = SASL_OK;
	}

	return ret;
}

struct _LassoAuthenticationPrivate
{
	gboolean dispose_has_run;
};

gint
lasso_authentication_client_start(LassoAuthentication *authentication)
{
	LassoSaSASLRequest *request;
	int res;
	const char *mechusing;
	const char *out;
	int outlen = 0;

	char *outbase64;

	/* Liberty part */
	request = LASSO_SA_SASL_REQUEST(LASSO_WSF_PROFILE(authentication)->request);

	/* sasl part */
	res = sasl_client_start(authentication->connection, /* same context from above */
				request->mechanism, /* list of mechanisms from the server */
				NULL, /* filled in if an interaction is needed */
				&out, /* filled in on success */
				&outlen, /* filled in on success */
				&mechusing);

	/* mechusing is th resulting best mech to use, so copy it in SASLRequest element */
	if (mechusing != NULL) {
		g_free(request->mechanism);
		request->mechanism = g_strdup(mechusing);
	}
       
	if (outlen > 0) {
		outbase64 = xmlSecBase64Encode(out, outlen, 0);
		request->Data = g_list_append(request->Data, outbase64);
	}

	return res;
}

gint
lasso_authentication_client_step(LassoAuthentication *authentication)
{
	LassoSaSASLRequest *request;
	LassoSaSASLResponse *response;
	int res;
	char *in = NULL;
	int inlen = 0;
	xmlChar *inbase64 = NULL;

	char *outbase64;
	const char *out;
	int outlen = 0;

	/* Liberty part */
	request = LASSO_SA_SASL_REQUEST(LASSO_WSF_PROFILE(authentication)->request);
	response = LASSO_SA_SASL_RESPONSE(LASSO_WSF_PROFILE(authentication)->response);

	/* sasl part */

	if (response->Data != NULL) {
		inbase64 = response->Data->data;
		in = g_malloc(strlen(inbase64));
		inlen = xmlSecBase64Decode(inbase64, in, strlen(inbase64));

		res = sasl_client_step(authentication->connection, /* our context */
				       in,    /* the data from the server */
				       inlen, /* it's length */
				       NULL,  /* this should be unallocated and NULL */
				       &out,     /* filled in on success */
				       &outlen); /* filled in on success */
		if (outlen > 0) {
			outbase64 = xmlSecBase64Encode(out, outlen, 0);
			request->Data = g_list_append(request->Data, outbase64);
		}
	}

	return res;
}

void
lasso_authentication_destroy(LassoAuthentication *authentication)
{
	g_object_unref(G_OBJECT(authentication));
}

char*
lasso_authentication_get_mechanism_list(LassoAuthentication *authentication)
{
	int res;
	const char *result_string;
	int string_length = 0;
	unsigned number_of_mechanisms;

	if (authentication->connection == NULL) {
		return NULL;
	}

	res = sasl_listmech(authentication->connection,  /* The context for this connection */
			    NULL,  /* not supported */
			    "",   /* What to prepend the string with */
			    " ",  /* What to separate mechanisms with */
			    "",   /* What to append to the string */
			    &result_string, /* The produced string. */
			    &string_length, /* length of the string */
			    &number_of_mechanisms); /* Number of mechanisms in
						       the string */
	if (result_string == NULL)
		return NULL;

	return g_strdup(result_string);
}

gint
lasso_authentication_init_request(LassoAuthentication *authentication,
				  LassoDiscoDescription *description,
				  const gchar *mechanisms,
				  LassoUserAccount *account)
{
	LassoSoapEnvelope *envelope;
	LassoSaSASLRequest *request;
	int res;

	/* global callback for every connection */
	static sasl_callback_t global_callbacks[2];

	g_return_val_if_fail(LASSO_IS_AUTHENTICATION(authentication),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(LASSO_IS_DISCO_DESCRIPTION(description),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(mechanisms != NULL, LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);


	if (description->Endpoint != NULL) {
		LASSO_WSF_PROFILE(authentication)->msg_url = g_strdup(description->Endpoint);
	}
	else if (description->WsdlURI != NULL) {

	}

	/* liberty-idwsf-authn-svc-1.1.pdf - page 13 - lignes 342 / 343 :
	   In the case where a single SASL mechanism name is conveyed, the <SASLRequest> message
	   can contain a so-called initial response (see Section 5.1 of [RFC2222]) in the <Data>
	   element. */
	request = lasso_sa_sasl_request_new(mechanisms);
	LASSO_WSF_PROFILE(authentication)->request = LASSO_NODE(request);

	envelope = lasso_wsf_profile_build_soap_envelope(NULL, NULL);
	LASSO_WSF_PROFILE(authentication)->soap_envelope_request = envelope;
	envelope->Body->any = g_list_append(envelope->Body->any, request);

	/* set up default logging callback */
	global_callbacks[0].id = SASL_CB_LOG;
	global_callbacks[0].proc = lasso_sasl_cb_log;
	global_callbacks[0].context = NULL;

	global_callbacks[1].id = SASL_CB_LIST_END;
	global_callbacks[1].proc = NULL;
	global_callbacks[1].context = NULL;

	sasl_client_init(global_callbacks);

	/* sasl client new connection */
	{
		sasl_callback_t* callback;

		callback = lasso_sasl_callbacks;
	
		callback->id = SASL_CB_AUTHNAME;
		callback->proc = &lasso_sasl_cb_authname;
		callback->context = account;
		callback++;

		callback->id = SASL_CB_USER;
		callback->proc = &lasso_sasl_cb_authname;
		callback->context = account;
		callback++;

		callback->id = SASL_CB_PASS;
		callback->proc = &lasso_sasl_cb_pass;
		callback->context = account;
		callback++;

		callback->id = SASL_CB_GETREALM;
		callback->proc = NULL;
		callback->context = NULL;
		callback++;

		callback->id = SASL_CB_LIST_END;
		callback->proc = NULL;
		callback->context = NULL;
	}

	res = sasl_client_new(LASSO_SA_SASL_SERVICE_NAME,
			      NULL,
			      NULL,
			      NULL,
			      lasso_sasl_callbacks, /* new connection callbacks (log, ...) */
			      0,
			      &authentication->connection);

	return res;
}


gint
lasso_authentication_process_request_msg(LassoAuthentication *authentication,
					 const gchar *soap_msg)
{
	LassoSoapEnvelope *envelope;
	LassoSaSASLResponse *response;
	LassoUtilityStatus *status;
	LassoSoapBindingCorrelation *correlation;
	gchar *messageId;
	int res = 0;
	
	g_return_val_if_fail(LASSO_IS_AUTHENTICATION(authentication),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	g_return_val_if_fail(LASSO_IS_AUTHENTICATION(authentication),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(soap_msg != NULL, LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	/* if a previous request and response, then remove */
	if (LASSO_IS_SOAP_ENVELOPE(LASSO_WSF_PROFILE(authentication)->soap_envelope_response) \
	    == TRUE) {
		lasso_node_destroy(LASSO_NODE(LASSO_WSF_PROFILE(authentication)->\
					      soap_envelope_response));
		LASSO_WSF_PROFILE(authentication)->soap_envelope_response = NULL;
		LASSO_WSF_PROFILE(authentication)->response = NULL;
	}

	if (LASSO_IS_SOAP_ENVELOPE(LASSO_WSF_PROFILE(authentication)->soap_envelope_request) \
	    == TRUE) {
		lasso_node_destroy(LASSO_NODE(LASSO_WSF_PROFILE(authentication)->\
					      soap_envelope_request));
		LASSO_WSF_PROFILE(authentication)->soap_envelope_request = NULL;
		LASSO_WSF_PROFILE(authentication)->request = NULL;
	}

	envelope = LASSO_SOAP_ENVELOPE(lasso_node_new_from_dump(soap_msg));
	LASSO_WSF_PROFILE(authentication)->soap_envelope_request = envelope;
	LASSO_WSF_PROFILE(authentication)->request = LASSO_NODE(envelope->Body->any->data);

	correlation = envelope->Header->Other->data;
	messageId = correlation->messageID;
	envelope = lasso_wsf_profile_build_soap_envelope(messageId, NULL);
	LASSO_WSF_PROFILE(authentication)->soap_envelope_response = envelope;

	status = lasso_utility_status_new(LASSO_SA_STATUS_CODE_OK);
	response = lasso_sa_sasl_response_new(status);
	LASSO_WSF_PROFILE(authentication)->response = LASSO_NODE(response);
	envelope->Body->any = g_list_append(envelope->Body->any, response);

	/* liberty-idwsf-authn-svc-1.1.pdf - page 13 - lignes 359 / 361 :
	   <SASLRequest> message with multiple mechanism MUST NOT contain any "initial response"
	   data, and MUST be the initial SASL request. See Section 4.5.2.1.2 for details on the
	   returned <SASLResponse> message in this case. */

	/* liberty-idwsf-authn-svc-1.1.pdf - page 13 - lignes 380 / 384 :
	   A NULL string ("") in mechanism list SASLRequest indicates to the authentication server
	   that the client wishes to abort the authentication exchange.
	*/

	return res;
}

gint
lasso_authentication_process_response_msg(LassoAuthentication *authentication,
					  const gchar *soap_msg)
{
	LassoSoapEnvelope *envelope;
	LassoSaSASLRequest *request;
	LassoSaSASLResponse *response;
	LassoSoapBindingCorrelation *correlation;
	gchar *messageId;

	g_return_val_if_fail(LASSO_IS_AUTHENTICATION(authentication),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(soap_msg != NULL, LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	/* if a previous request or response, remove */
	if (LASSO_IS_SOAP_ENVELOPE(LASSO_WSF_PROFILE(authentication)->soap_envelope_request) \
	    == TRUE) {
		lasso_node_destroy(LASSO_NODE(LASSO_WSF_PROFILE(authentication)->\
					      soap_envelope_request));
		LASSO_WSF_PROFILE(authentication)->soap_envelope_request = NULL;
		LASSO_WSF_PROFILE(authentication)->request = NULL;
	}

	if (LASSO_IS_SOAP_ENVELOPE(LASSO_WSF_PROFILE(authentication)->soap_envelope_response) \
	    == TRUE) {
		lasso_node_destroy(LASSO_NODE(LASSO_WSF_PROFILE(authentication)->\
					      soap_envelope_response));
		LASSO_WSF_PROFILE(authentication)->soap_envelope_response = NULL;
		LASSO_WSF_PROFILE(authentication)->response = NULL;
	}

	envelope = LASSO_SOAP_ENVELOPE(lasso_node_new_from_dump(soap_msg));
	LASSO_WSF_PROFILE(authentication)->soap_envelope_response = envelope;

	response = envelope->Body->any->data;
	LASSO_WSF_PROFILE(authentication)->response = LASSO_NODE(response);

	/* if continue, init another request */
	if (g_str_equal(response->Status->code, LASSO_SA_STATUS_CODE_CONTINUE) == TRUE) {
		correlation = envelope->Header->Other->data;
		messageId = correlation->messageID;

		envelope = lasso_wsf_profile_build_soap_envelope(messageId, NULL);
		LASSO_WSF_PROFILE(authentication)->soap_envelope_request = envelope;

		request = lasso_sa_sasl_request_new(g_strdup(response->serverMechanism));
		LASSO_WSF_PROFILE(authentication)->request = LASSO_NODE(request);

		envelope->Body->any = g_list_append(envelope->Body->any, request);
	}

	return 0;
}

gint
lasso_authentication_server_start(LassoAuthentication *authentication)
{
	LassoSaSASLRequest *request;
	LassoSaSASLResponse *response;

	gchar *mechanisms, *chosen;
	gchar **server_mech_list, **client_mech_list, **smech, **cmech;
	int nbmech;

	char *inbase64, *outbase64;

	char *in = NULL;
	int inlen = 0;

	const char *out;
	int outlen = 0;

	int res = 0;

	g_return_val_if_fail(LASSO_IS_AUTHENTICATION(authentication),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	res = sasl_server_init(NULL, "Lasso"); /* FIXME : should be a param */
	res = sasl_server_new(LASSO_SA_SASL_SERVICE_NAME,
			      NULL,
			      NULL,
			      NULL,
			      NULL,
			      NULL,
			      0,
			      &authentication->connection);

	/* Liberty part */
	request = LASSO_SA_SASL_REQUEST(LASSO_WSF_PROFILE(authentication)->request);
	response = LASSO_SA_SASL_RESPONSE(LASSO_WSF_PROFILE(authentication)->response);

	/* if mechanism is NULL, then abort authentication exchange */
	chosen = NULL;
	nbmech = 0;
	if (g_str_equal(request->mechanism, "") == FALSE) {
		/* count nb client mechanism list */
		client_mech_list = g_strsplit(request->mechanism, " ", 0);
		cmech = client_mech_list;
		while (*cmech != NULL) {
			cmech++;
			nbmech++;
		}

		mechanisms  = lasso_authentication_get_mechanism_list(authentication);
		server_mech_list = g_strsplit(mechanisms, " ", 0);
		smech = server_mech_list;

		/* get chosen mechanism */
		while (*smech != NULL) {
			cmech = client_mech_list;
			while (*cmech != NULL) {
				if ( g_str_equal(*smech, *cmech) == TRUE) {
					chosen = g_strdup(*smech);
					break;
				}
				cmech++;
			}
			if (chosen != NULL)
				break;
			smech++;
		}
	}
	if (chosen == NULL) {
		g_free(response->Status->code);
		response->Status->code = g_strdup(LASSO_SA_STATUS_CODE_ABORT);
		return res;
	}

	if (nbmech > 1 && request->Data != NULL) {
		g_free(response->Status->code);
		response->Status->code = g_strdup(LASSO_SA_STATUS_CODE_ABORT);
		return res;	
	}

	/* decode Data if not NULL */
	if (request->Data != NULL) {
		inbase64 = request->Data->data;
		in = g_malloc(strlen(inbase64));
		inlen = xmlSecBase64Decode(inbase64, in, strlen(inbase64));
	}

	/* process sasl request */
	res = sasl_server_start(authentication->connection,
				chosen,
				in,
				inlen,
				&out, /* Might not be NULL terminated */
				&outlen);

	/* set status code in SASLResponse message if not ok */
	if (res != SASL_OK) {
		g_free(response->Status->code);

		/* continue, set Data in response */
		if (res == SASL_CONTINUE) {
			response->Status->code = g_strdup(LASSO_SA_STATUS_CODE_CONTINUE);
			response->serverMechanism = g_strdup(request->mechanism);
			if (outlen > 0) {
				outbase64 = xmlSecBase64Encode(out, outlen, 0);
				response->Data = g_list_append(response->Data, outbase64);
			}
		}
		/* abort authentication */
		else {
			response->Status->code = g_strdup(LASSO_SA_STATUS_CODE_ABORT);
		}
	}

	return res;
}

gint
lasso_authentication_server_step(LassoAuthentication *authentication)
{
	LassoSaSASLRequest *request;
	LassoSaSASLResponse *response;
	int res;
	char *in = NULL;
	int inlen = 0;
	const char *out;
	int outlen = 0;
	xmlChar *outbase64, *inbase64;
	
	g_return_val_if_fail(LASSO_IS_AUTHENTICATION(authentication),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	/* Liberty part */
	request = LASSO_SA_SASL_REQUEST(LASSO_WSF_PROFILE(authentication)->request);
	response = LASSO_SA_SASL_RESPONSE(LASSO_WSF_PROFILE(authentication)->response);

	/* If mechanism is NULL, thene client wants to abort authentication exchange */
	if (g_str_equal(request->mechanism, "") == TRUE) {
		g_free(response->Status->code);
		response->Status->code = g_strdup(LASSO_SA_STATUS_CODE_ABORT);

		return 0;
	}

	if (request->Data != NULL) {
		inbase64 = request->Data->data;
		in = g_malloc(strlen(inbase64));
		inlen = xmlSecBase64Decode(inbase64, in, strlen(inbase64));
	}

	res = sasl_server_step(authentication->connection,
			       in,      /* what the client gave */
			       inlen,   /* it's length */
			       &out,          /* Might not be NULL terminated */
			       &outlen);

	if (res != SASL_OK) {
		g_free(response->Status->code);

		/* authentication exchange must continue */
		if (res == SASL_CONTINUE) {
			response->Status->code = g_strdup(LASSO_SA_STATUS_CODE_ABORT);

			if (outlen > 0) {
				outbase64 = xmlSecBase64Encode(out, outlen, 0);
				response->Data = g_list_append(response->Data, outbase64);
			}
		}
		/* authentication failed, abort exchange */
		else  {
			response->Status->code = g_strdup(LASSO_SA_STATUS_CODE_ABORT);
		}
	}

	return res;
}


/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static LassoNodeClass *parent_class = NULL;

static xmlNode*
get_xmlNode(LassoNode *node, gboolean lasso_dump)
{
	xmlNode *xmlnode;

	xmlnode = parent_class->get_xmlNode(node, lasso_dump);
	xmlNodeSetName(xmlnode, (xmlChar*)"Authentication");
	xmlSetProp(xmlnode, (xmlChar*)"AuthenticationDumpVersion", (xmlChar*)"2");

	return xmlnode;
}

static int
init_from_xml(LassoNode *node, xmlNode *xmlnode)
{
	int rc;

	rc = parent_class->init_from_xml(node, xmlnode);
	if (rc) return rc;

	return 0;
}

/*****************************************************************************/
/* overrided parent class methods */
/*****************************************************************************/

static void
dispose(GObject *object)
{
	LassoAuthentication *authentication = LASSO_AUTHENTICATION(object);

	sasl_dispose(&authentication->connection);

	if (authentication->private_data->dispose_has_run == TRUE)
		return;
	authentication->private_data->dispose_has_run = TRUE;

	G_OBJECT_CLASS(parent_class)->dispose(object);
}

static void
finalize(GObject *object)
{ 
	LassoAuthentication *authentication = LASSO_AUTHENTICATION(object);
	g_free(authentication->private_data);
	authentication->private_data = NULL;
	G_OBJECT_CLASS(parent_class)->finalize(object);
}

/*****************************************************************************/
/* instance and class init functions */
/*****************************************************************************/

static void
instance_init(LassoAuthentication *authentication)
{
	authentication->private_data = g_new(LassoAuthenticationPrivate, 1);
	authentication->private_data->dispose_has_run = FALSE;
}

static void
class_init(LassoAuthenticationClass *klass)
{
	parent_class = g_type_class_peek_parent(klass);

	LASSO_NODE_CLASS(klass)->get_xmlNode = get_xmlNode;
	LASSO_NODE_CLASS(klass)->init_from_xml = init_from_xml;

	G_OBJECT_CLASS(klass)->dispose = dispose;
	G_OBJECT_CLASS(klass)->finalize = finalize;
}

GType
lasso_authentication_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof(LassoAuthenticationClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoAuthentication),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_WSF_PROFILE,
						   "LassoAuthentication", &this_info, 0);
	}
	return this_type;
}

LassoAuthentication*
lasso_authentication_new(LassoServer *server)
{
	LassoAuthentication *authentication = NULL;

	g_return_val_if_fail(LASSO_IS_SERVER(server), NULL);

	authentication = g_object_new(LASSO_TYPE_AUTHENTICATION, NULL);
	LASSO_WSF_PROFILE(authentication)->server = server;

	return authentication;
}