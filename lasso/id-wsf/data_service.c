/* $Id: data_service.c,v 1.14 2005/09/27 08:07:10 nclapies Exp $
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

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <lasso/id-wsf/discovery.h>
#include <lasso/id-wsf/data_service.h>
#include <lasso/id-wsf/data_service_private.h>
#include <lasso/xml/dst_query.h>
#include <lasso/xml/dst_query_response.h>
#include <lasso/xml/dst_modify.h>
#include <lasso/xml/dst_modify_response.h>
#include <lasso/xml/soap_binding_correlation.h>


struct _LassoDataServicePrivate
{
	gboolean dispose_has_run;
	LassoDiscoResourceOffering *offering;
	GList *credentials;
};

/*****************************************************************************/
/* public methods                                                            */
/*****************************************************************************/

gint
lasso_data_service_add_credential(LassoDataService *service,
	LassoSamlAssertion *assertion)
{
	service->private_data->credentials = g_list_append(
		service->private_data->credentials,
		g_object_ref(assertion));
}

LassoDstModification*
lasso_data_service_add_modification(LassoDataService *service, const gchar *select)
{
	LassoWsfProfile *profile;
	LassoDstModification *modification;

	g_return_val_if_fail(LASSO_IS_PROFILE_SERVICE(service), NULL);
	g_return_val_if_fail(select != NULL, NULL);

	profile = LASSO_WSF_PROFILE(service);

	modification = lasso_dst_modification_new(select);
	LASSO_DST_MODIFY(profile->request)->Modification = g_list_append(
		LASSO_DST_MODIFY(profile->request)->Modification, (gpointer)modification);

	return modification;
}


/**
 * lasso_data_service_add_query_item:
 * @service: a #LassoDataService
 * @select: resource selection string (typically a XPath query)
 * @item_id: query item identifier
 *
 * Adds a dst:QueryItem to the current dst:Query request.
 *
 * Return value: a newly created #LassoDstQueryItem with the query item that
 *       has been created.  Note that it is internally allocated and shouldn't
 *       be freed by the caller.
 **/
LassoDstQueryItem*
lasso_data_service_add_query_item(LassoDataService *service,
		const char *select, const char *item_id)
{
	LassoDstQuery *query;
	LassoDstQueryItem *item;

	g_return_val_if_fail(LASSO_IS_PROFILE_SERVICE(service), NULL);
	g_return_val_if_fail(select != NULL, NULL);

	if (! LASSO_IS_DST_QUERY(LASSO_WSF_PROFILE(service)->request)) {
		return NULL;
	}

	query = LASSO_DST_QUERY(LASSO_WSF_PROFILE(service)->request);
	
	if (query->QueryItem && query->QueryItem->data && 
			LASSO_DST_QUERY_ITEM(query->QueryItem->data)->itemID == NULL) {
		/* XXX: all items must have itemID if there is more than one,
		 * perhaps we could generate an item id for those lacking it */
		return NULL;
	}

	item = lasso_dst_query_item_new(select, item_id);
	query->QueryItem = g_list_append(query->QueryItem, item);

	return item;
}

/**
 * lasso_data_service_init_query
 * @service: a #LassoDataService
 * @select: resource selection string (typically a XPath query)
 * @item_id: query item identifier (optional)
 *
 * Initializes a new dst:Query request, asking for element @select (with
 * optional itemID set to @item_id).  @item_id may be NULL only if the query
 * won't contain other query items.
 *
 * If both @select and @item_id are NULL, only a skeleton request is created
 * and calls to lasso_data_service_add_query_item() will need to be done.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_data_service_init_query(LassoDataService *service, const char *select,
	const char *item_id, const char *security_mech_id)
{
	LassoWsfProfile *profile;
	LassoDstQuery *query;
	LassoDiscoResourceOffering *offering;
	LassoDiscoDescription *description;
	GList *iter;

	profile = LASSO_WSF_PROFILE(service);

	if (select) {
		query = lasso_dst_query_new(lasso_dst_query_item_new(select, item_id));
	} else {
		query = lasso_dst_query_new(NULL);
	}
	profile->request = LASSO_NODE(query);
	
	offering = service->private_data->offering;

	query->hrefServiceType = g_strdup(offering->ServiceInstance->ServiceType);
	query->prefixServiceType = lasso_get_prefix_for_dst_service_href(
		query->hrefServiceType);
	if (query->prefixServiceType == NULL) {
		return LASSO_ERROR_UNDEFINED;
	}

	if (offering->ResourceID) {
		query->ResourceID = g_object_ref(offering->ResourceID);
	} else if (offering->EncryptedResourceID) {
		query->EncryptedResourceID = g_object_ref(offering->EncryptedResourceID);
	} else {
		/* XXX: no resource id, implied:resource, etc. */
		return LASSO_ERROR_UNIMPLEMENTED;
	}

	profile->soap_envelope_request = lasso_wsf_profile_build_soap_envelope(
		NULL, NULL);
	profile->soap_envelope_request->Body->any = g_list_append(
			profile->soap_envelope_request->Body->any, query);

	if (security_mech_id)
		description = lasso_discovery_get_description_auto(
			offering, security_mech_id);
	else
		description = lasso_discovery_get_description_auto(
			offering, LASSO_SECURITY_MECH_NULL);
	if (!description)
		return -1;

	if (description->Endpoint != NULL) {
		profile->msg_url = g_strdup(description->Endpoint);
	} else {
		/* XXX: else, description->WsdlURLI, get endpoint automatically */
		return LASSO_ERROR_UNIMPLEMENTED;
	}

	/* Added needed credential for remote service */
	if (description->CredentialRef) {
			char *credentialRef = description->CredentialRef->data;
			iter = service->private_data->credentials;
			while (iter) {
				LassoSamlAssertion *credential = LASSO_SAML_ASSERTION(
					iter->data);
				if (strcmp(credentialRef, credential->AssertionID) == 0)
					lasso_wsf_profile_add_saml_authentication(
						LASSO_WSF_PROFILE(service), credential);
				iter = iter->next;
			}
	}

	return 0;
}

/**
 * lasso_data_service_process_query_msg:
 * @service: a #LassoDataService
 * @message: the dst query message
 *
 * Processes a dst:Query message.  Rebuilds a request object from the message
 * and extracts ResourceID.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_data_service_process_query_msg(LassoDataService *service, const char *message,
	const char *security_mech_id)
{
	LassoDstQuery *query;
	LassoWsfProfile *profile;
	int rc;

	profile = LASSO_WSF_PROFILE(service);
	rc = lasso_wsf_profile_process_soap_request_msg(profile, message, security_mech_id);
	if (rc) {
		return rc;
	}

	/* Verify needed credential */
	if (lasso_security_mech_id_is_saml_authentication(security_mech_id) == TRUE) {
		int res = lasso_wsf_profile_verify_saml_authentication(LASSO_WSF_PROFILE(service));
		if (res < 0)
			return res;
	}

	query = LASSO_DST_QUERY(profile->request);
	if (query->ResourceID)
		service->resource_id = g_object_ref(query->ResourceID);
	else if (query->EncryptedResourceID)
		service->encrypted_resource_id = g_object_ref(query->EncryptedResourceID);
	else {
		return LASSO_ERROR_UNIMPLEMENTED; /* implied ? */
	}

	return 0;
}

gint
lasso_data_service_build_modify_response_msg(LassoDataService *service) {
	LassoWsfProfile *profile;
	LassoDstModify *request;
	LassoDstModifyResponse *response;

	GList *iter;
	xmlDoc *doc;
	xmlXPathContext *xpathCtx;
	xmlXPathObject *xpathObj;

	LassoSoapEnvelope *envelope;

	profile = LASSO_WSF_PROFILE(service);
	request = LASSO_DST_MODIFY(profile->request);

	response = lasso_dst_modify_response_new(
		lasso_utility_status_new(LASSO_DST_STATUS_CODE_OK));
	profile->response = LASSO_NODE(response);
	response->prefixServiceType = g_strdup(request->prefixServiceType);
	response->hrefServiceType = g_strdup(request->hrefServiceType);
	envelope = profile->soap_envelope_response;
	envelope->Body->any = g_list_append(envelope->Body->any, response);

	doc = xmlNewDoc((xmlChar*)"1.0");
	xmlDocSetRootElement(doc, service->resource_data);
	xpathCtx = xmlXPathNewContext(doc);
	xmlXPathRegisterNs(xpathCtx, (xmlChar*)response->prefixServiceType,
			(xmlChar*)response->hrefServiceType);

	iter = request->Modification;
	while (iter) {
		LassoDstModification *modification = iter->data;
		xmlNode *newNode = modification->NewData->any->data;
		xpathObj = xmlXPathEvalExpression((xmlChar*)modification->Select,
			xpathCtx);
		if (xpathObj && xpathObj->nodesetval && xpathObj->nodesetval->nodeNr) {
			xmlNode *node = xpathObj->nodesetval->nodeTab[0];
			xmlReplaceNode(node, newNode);
		}

		iter = g_list_next(iter);
	}

	return lasso_wsf_profile_build_soap_response_msg(profile);
}

/**
 * lasso_data_service_build_response_msg:
 * @service: a #LassoDataService
 *
 * Builds a dst:QueryResponse message.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_data_service_build_response_msg(LassoDataService *service)
{
	LassoWsfProfile *profile;
	LassoDstQuery *request;
	LassoDstQueryResponse *response;
	GList *iter;
	xmlDoc *doc;
	xmlXPathContext *xpathCtx;
	xmlXPathObject *xpathObj;
	LassoSoapEnvelope *envelope;

	profile = LASSO_WSF_PROFILE(service);
	request = LASSO_DST_QUERY(profile->request);

	response = lasso_dst_query_response_new(
		lasso_utility_status_new(LASSO_DST_STATUS_CODE_OK));
	profile->response = LASSO_NODE(response);
	response->prefixServiceType = g_strdup(request->prefixServiceType);
	response->hrefServiceType = g_strdup(request->hrefServiceType);
	envelope = profile->soap_envelope_response;
	envelope->Body->any = g_list_append(envelope->Body->any, response);

	doc = xmlNewDoc((xmlChar*)"1.0");
	xmlDocSetRootElement(doc, service->resource_data);
	xpathCtx = xmlXPathNewContext(doc);
	xmlXPathRegisterNs(xpathCtx, (xmlChar*)response->prefixServiceType,
			(xmlChar*)response->hrefServiceType);

	/* XXX: needs another level, since there may be more than one <dst:Query> */
	iter = request->QueryItem;
	while (iter) {
		LassoDstQueryItem *item = iter->data;
		xpathObj = xmlXPathEvalExpression((xmlChar*)item->Select, xpathCtx);
		if (xpathObj && xpathObj->nodesetval && xpathObj->nodesetval->nodeNr) {
			LassoDstData *data;
			xmlNode *node = xpathObj->nodesetval->nodeTab[0];
			/* XXX: assuming there is only one matching node */
			data = lasso_dst_data_new();
			data->any = g_list_append(data->any, xmlCopyNode(node, 1));
			if (item->itemID) {
				data->itemIDRef = g_strdup(item->itemID);
			}
			response->Data = g_list_append(response->Data, data);
		}
		iter = g_list_next(iter);
	}

	xmlUnlinkNode(service->resource_data);
	xmlFreeDoc(doc);

	return lasso_wsf_profile_build_soap_response_msg(profile);
}

/**
 * lasso_data_service_get_answer:
 * @service: a #LassoDataService
 * @select: resource selection string (typically a XPath query)
 * 
 * Returns the answer for the specified @select request.
 *
 * Return value: the node (libxml2 xmlNode*); or NULL if it was not found.
 *      This xmlnode must be freed by caller.
 **/
xmlNode*
lasso_data_service_get_answer(LassoDataService *service, const char *select)
{
	LassoDstQueryResponse *response;
	LassoDstData *data = NULL;
	GList *iter;
	char *item_id = NULL;

	response = LASSO_DST_QUERY_RESPONSE(LASSO_WSF_PROFILE(service)->response);
	iter = LASSO_DST_QUERY(LASSO_WSF_PROFILE(service)->request)->QueryItem;

	if (select == NULL) {
		/* if only one element; default to first */
		if (g_list_length(iter) > 1)
			return NULL;
		if (response->Data == NULL)
			return NULL;
		data = response->Data->data;
	} else {
		LassoDstQueryItem *item = NULL;
		/* lookup select in query to get itemId, then get data with itemIdRef */
		/* XXX: needs another level, since there may be more than one dst:Query */
		while (iter) {
			item = iter->data;
			iter = g_list_next(iter);
			if (strcmp(item->Select, select) == 0) {
				break;
			}
			item = NULL;
		}

		iter = LASSO_DST_QUERY(LASSO_WSF_PROFILE(service)->request)->QueryItem;
		if (item == NULL) {
			/* not found */
			return NULL;
		}
		item_id = item->itemID;
		if (item_id == NULL) {
			/* item_id is not mandatory when there is only one item */
			if (response->Data == NULL)
				return NULL;
			data = response->Data->data;
		}

		iter = response->Data;
		while (iter && item_id) {
			LassoDstData *t = iter->data;
			iter = g_list_next(iter);
			if (strcmp(t->itemIDRef, item_id) == 0) {
				data = t;
				break;
			}
		}
		if (data == NULL) {
			/* not found */
			return NULL;
		}
	}

	/* XXX: there may be more than one xmlnode */
	return xmlCopyNode(data->any->data, 1);
}

/**
 * lasso_data_service_get_answer_for_item_id:
 * @service: a #LassoDataService
 * @item_id: query item identifier
 * 
 * Returns the answer for the specified @item_id query item.
 *
 * Return value: the node (libxml2 xmlNode*); or NULL if it was not found.
 *      This xmlnode must be freed by caller.
 **/
xmlNode*
lasso_data_service_get_answer_for_item_id(LassoDataService *service, const char *item_id)
{
	LassoDstQueryResponse *response;
	LassoDstData *data = NULL;
	GList *iter;

	response = LASSO_DST_QUERY_RESPONSE(LASSO_WSF_PROFILE(service)->response);
	iter = LASSO_DST_QUERY(LASSO_WSF_PROFILE(service)->request)->QueryItem;

	iter = response->Data;
	while (iter && item_id) {
		LassoDstData *t = iter->data;
		iter = g_list_next(iter);
		if (strcmp(t->itemIDRef, item_id) == 0) {
			data = t;
			break;
		}
	}
	if (data == NULL) {
		/* not found */
		return NULL;
	}

	/* XXX: there may be more than one xmlnode */
	return xmlCopyNode(data->any->data, 1);
}


/**
 * lasso_data_service_process_query_response_msg:
 * @service: a #LassoDataService
 * @message: the dst query response message
 *
 * Processes a dst:Query message.  Rebuilds a request object from the message
 * and extracts ResourcedID.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_data_service_process_query_response_msg(LassoDataService *service,
	const char *message)
{
	int rc;
	LassoDstQueryResponse *response;

	rc = lasso_wsf_profile_process_soap_response_msg(LASSO_WSF_PROFILE(service), message);
	if (rc) return rc;

	if (! LASSO_IS_DST_QUERY_RESPONSE(LASSO_WSF_PROFILE(service)->response))
		return LASSO_ERROR_UNDEFINED;

	response = LASSO_DST_QUERY_RESPONSE(LASSO_WSF_PROFILE(service)->response);
	if (response->Status == NULL || strcmp(response->Status->code, "OK") != 0)
		return LASSO_ERROR_UNDEFINED;

	return 0;
}


gint
lasso_data_service_init_modify(LassoDataService *service, const gchar *select,
	xmlNode *xmlData)
{
	LassoDstModification *modification;
	LassoDstNewData *newData;
	LassoDiscoResourceOffering *offering;
	LassoDiscoDescription *description;
	LassoWsfProfile *profile;

	LassoSoapEnvelope *envelope;
	LassoDstModify *modify;


	profile = LASSO_WSF_PROFILE(service);

	/* init Modify */
	modification = lasso_dst_modification_new(select);
	newData = lasso_dst_new_data_new();
	newData->any = g_list_append(newData->any, xmlData);
	modification->NewData = newData;

	modify = lasso_dst_modify_new(modification);
	profile->request = LASSO_NODE(modify);

	offering = service->private_data->offering;
	
	modify->hrefServiceType = g_strdup(offering->ServiceInstance->ServiceType);
	modify->prefixServiceType = lasso_get_prefix_for_dst_service_href(
		modify->hrefServiceType);
	if (modify->prefixServiceType == NULL) {
		return LASSO_ERROR_UNDEFINED;
	}

	/* get ResourceID / EncryptedResourceID */
	if (offering->ResourceID) {
		modify->ResourceID = offering->ResourceID;
	}
	else if (offering->EncryptedResourceID) {
	  modify->EncryptedResourceID = offering->EncryptedResourceID;
	}
	else {
		/* XXX: no resource id, implied:resource, etc. */
		return LASSO_ERROR_UNIMPLEMENTED;
	}

	envelope = lasso_wsf_profile_build_soap_envelope(NULL, NULL);
	LASSO_WSF_PROFILE(service)->soap_envelope_request = envelope;
	envelope->Body->any = g_list_append(envelope->Body->any, modify);

	/* set msg_url */
	/* TODO : implement WSDLRef */
	if (description->Endpoint) {
		profile->msg_url = g_strdup(description->Endpoint);
	}

	return 0;
}


gint
lasso_data_service_process_modify_msg(LassoDataService *service,
	const gchar *modify_soap_msg, const gchar *security_mech_id)
{
	LassoDstModify *modify;
	LassoWsfProfile *profile;
	int rc;

	profile = LASSO_WSF_PROFILE(service);
	rc = lasso_wsf_profile_process_soap_request_msg(profile, modify_soap_msg, security_mech_id);
	if (rc) {
		return rc;
	}

	modify = LASSO_DST_MODIFY(profile->request);
	if (modify->ResourceID)
		service->resource_id = g_object_ref(modify->ResourceID);
	else if (modify->EncryptedResourceID)
		service->encrypted_resource_id = g_object_ref(modify->EncryptedResourceID);
	else {
		return LASSO_ERROR_UNIMPLEMENTED; /* implied ? */
	}

	return 0;}

gint
lasso_data_service_process_modify_response_msg(LassoDataService *service, const gchar *soap_msg)
{
	LassoDstModifyResponse *response;
	LassoSoapEnvelope *envelope;

	g_return_val_if_fail(LASSO_IS_PROFILE_SERVICE(service), -1);
	g_return_val_if_fail(soap_msg != NULL, -1);

	envelope = LASSO_SOAP_ENVELOPE(lasso_node_new_from_dump(soap_msg));
	LASSO_WSF_PROFILE(service)->soap_envelope_response = envelope;

	response = envelope->Body->any->data;
	LASSO_WSF_PROFILE(service)->response = LASSO_NODE(response);

	return 0;
}


/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static LassoNodeClass *parent_class = NULL;

void
lasso_data_service_set_offering(LassoDataService *service,
		LassoDiscoResourceOffering *offering)
{
	service->private_data->offering = g_object_ref(offering);
}

/*****************************************************************************/
/* overrided parent class methods */
/*****************************************************************************/

static void
dispose(GObject *object)
{
	LassoDataService *service = LASSO_DATA_SERVICE(object);

	if (service->private_data->dispose_has_run == TRUE)
		return;
	service->private_data->dispose_has_run = TRUE;

	G_OBJECT_CLASS(parent_class)->dispose(object);
}

static void
finalize(GObject *object)
{ 
	LassoDataService *service = LASSO_DATA_SERVICE(object);
	if (service->private_data->offering) {
		lasso_node_destroy(LASSO_NODE(service->private_data->offering));
		service->private_data->offering = NULL;
	}
	g_free(service->private_data);
	service->private_data = NULL;
	G_OBJECT_CLASS(parent_class)->finalize(object);
}


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoDataService *service)
{
	service->resource_data = NULL;
	service->private_data = g_new0(LassoDataServicePrivate, 1);
}

static void
class_init(LassoDataServiceClass *klass)
{
	parent_class = g_type_class_peek_parent(klass);
	
	G_OBJECT_CLASS(klass)->dispose = dispose;
	G_OBJECT_CLASS(klass)->finalize = finalize;
}

GType
lasso_data_service_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof(LassoDataServiceClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoDataService),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_WSF_PROFILE,
				"LassoDataService", &this_info, 0);
	}
	return this_type;
}


/**
 * lasso_data_service_new:
 * @server: the #LassoServer
 *
 * Creates a new #LassoDataService.
 *
 * Return value: a newly created #LassoDataService object; or NULL if an
 *      error occured.
 **/
LassoDataService*
lasso_data_service_new(LassoServer *server)
{
	LassoDataService *service;

	g_return_val_if_fail(LASSO_IS_SERVER(server) == TRUE, NULL);

	service = g_object_new(LASSO_TYPE_PROFILE_SERVICE, NULL);
	LASSO_WSF_PROFILE(service)->server = g_object_ref(server);

	return service;
}

LassoDataService*
lasso_data_service_new_full(LassoServer *server, LassoDiscoResourceOffering *offering)
{
	LassoDataService *service;

	service = lasso_data_service_new(server);
	if (service == NULL)
		return NULL;

	service->private_data->offering = g_object_ref(offering);

	return service;
}
