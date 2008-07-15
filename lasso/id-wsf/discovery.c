/* $Id: discovery.c 3716 2008-05-20 20:21:16Z fpeters $
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004-2007 Entr'ouvert
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

/**
 * SECTION:discovery
 * @short_description: ID-WSF Discovery Service Profile
 *
 * The Discovery service usually runs on the principal identity provider and
 * knowns about resources and services related to the principal.  Attribute
 * providers can register themselves as offering resources for an user while
 * other services can ask where to find a given resource.
 *
 * The following example is a service provider asking for a "PP" service (an
 * attribute provider for the "Personal Profile"):
 *
 * <informalexample>
 * <programlisting>
 * LassoServer *server;  // initialized before
 * char* session_dump;   // initialized before
 * 
 * LassoDiscovery *discovery;    // discovery service
 * char *soap_answer;            // SOAP answer from disco service
 * LassoProfileService *service; // instance to perform on requested service
 * 
 * discovery = lasso_discovery_new(server);
 * lasso_wsf_profile_set_session_from_dump(LASSO_WSF_PROFILE(discovery), session_dump);
 * lasso_discovery_init_query(discovery);
 * lasso_discovery_add_requested_service(discovery, LASSO_PP_HREF);
 * lasso_discovery_build_request_msg(discovery);
 * 
 * // service must perform SOAP call to LASSO_WSF_PROFILE(discovery)->msg_url
 * // the SOAP message is LASSO_WSF_PROFILE(discovery)->msg_body.  The answer
 * // is stored in char* soap_answer;
 * 
 * lasso_discovery_process_query_response_msg(discovery, soap_answer);
 * 
 * service = lasso_discovery_get_service(discovery);
 * </programlisting>
 * </informalexample>
 *
 */

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <xmlsec/xmltree.h>

#include <lasso/xml/soap_binding_correlation.h>
#include <lasso/xml/saml_assertion.h>
#include <lasso/xml/saml_attribute.h>
#include <lasso/xml/saml_attribute_value.h>
#include <lasso/xml/disco_modify.h>

#include <lasso/id-ff/server.h>
#include <lasso/id-ff/provider.h>
#include <lasso/id-ff/providerprivate.h>

#include <lasso/id-wsf/discovery.h>
#include <lasso/id-wsf/identity.h>
#include <lasso/id-wsf/data_service.h>
#include <lasso/id-wsf/personal_profile_service.h>
#include <lasso/id-wsf/wsf_profile_private.h>

struct _LassoDiscoveryPrivate
{
	gboolean dispose_has_run;
	GList *new_entry_ids;
	char *security_mech_id;
};

/*****************************************************************************/
/* static methods/functions */
/*****************************************************************************/

static gchar*
lasso_discovery_build_credential(LassoDiscovery *discovery, const gchar *providerId)
{
	/* XXX: providerId parameter is never used */

	LassoWsfProfile *profile = NULL;
	LassoSoapHeader *header = NULL;
	LassoSoapBindingProvider *provider = NULL;
	LassoDiscoQueryResponse *response = NULL;
	LassoDiscoCredentials *credentials = NULL;
	LassoSamlAssertion *assertion = NULL;
	LassoSamlAuthenticationStatement *authentication_statement = NULL;
	LassoSamlSubject *subject = NULL;
	LassoSamlNameIdentifier *name_identifier = NULL;
	LassoSamlSubjectConfirmation *subject_confirmation = NULL;
	LassoDsKeyInfo *key_info = NULL;
	GList *iter = NULL;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), NULL);

	profile = LASSO_WSF_PROFILE(discovery);

	/* Init assertion informations */
	assertion = lasso_saml_assertion_new();
	assertion->AssertionID = lasso_build_unique_id(32);
	assertion->MajorVersion = LASSO_SAML_MAJOR_VERSION_N;
	assertion->MinorVersion = LASSO_SAML_MINOR_VERSION_N;
	assertion->IssueInstant = lasso_get_current_time();
	assertion->Issuer = g_strdup(LASSO_PROVIDER(profile->server)->ProviderID);

	/* Add AuthenticationStatement */
	authentication_statement = LASSO_SAML_AUTHENTICATION_STATEMENT(
		lasso_saml_authentication_statement_new());
	authentication_statement->AuthenticationInstant = lasso_get_current_time();

	subject = LASSO_SAML_SUBJECT(lasso_saml_subject_new());

	/* NameIdentifier */
	name_identifier = lasso_saml_name_identifier_new();
	name_identifier->NameQualifier = g_strdup(LASSO_PROVIDER(profile->server)->ProviderID);
	header = profile->soap_envelope_request->Header;
	for (iter = header->Other; iter != NULL; iter = iter->next) {
		if (LASSO_IS_SOAP_BINDING_PROVIDER(iter->data)) {
			provider = LASSO_SOAP_BINDING_PROVIDER(iter->data);
			break;
		}
	}
	if (provider != NULL) {
		name_identifier->Format = g_strdup(LASSO_LIB_NAME_IDENTIFIER_FORMAT_ENTITYID);
		name_identifier->content = g_strdup(provider->providerID);
	} else {
		name_identifier->Format = g_strdup(LASSO_LIB_NAME_IDENTIFIER_FORMAT_FEDERATED);
	}
	subject->NameIdentifier = name_identifier;

	/* SubjectConfirmation */
	subject_confirmation = lasso_saml_subject_confirmation_new();
	subject_confirmation->ConfirmationMethod =
		g_list_append(subject_confirmation->ConfirmationMethod,
			g_strdup(LASSO_SAML_CONFIRMATION_METHOD_HOLDER_OF_KEY));

	/* Add public key value in credential */
	key_info = lasso_wsf_profile_get_key_info_node(profile, provider->providerID);
	if (key_info != NULL) {
		subject_confirmation->KeyInfo = key_info;
	}

	subject->SubjectConfirmation = subject_confirmation;

	/* Add the subject in the authentication statement */
	LASSO_SAML_SUBJECT_STATEMENT_ABSTRACT(authentication_statement)->Subject = subject;
	assertion->AuthenticationStatement = authentication_statement;

	/* Add credential to disco:QueryResponse */
	response = LASSO_DISCO_QUERY_RESPONSE(profile->response);
	credentials = lasso_disco_credentials_new();
	credentials->any = g_list_append(credentials->any, LASSO_NODE(assertion));
	response->Credentials = credentials;

	return g_strdup(assertion->AssertionID);
}

/**
 * lasso_discovery_init_request:
 * @discovery: a LassoDiscovery
 * @resourceOffering: a LassoDiscoResourceOffering
 * @description: a LassoDiscoDescription
 * 
 * Generic static method used by lasso_discovery_init_modify() and
 * lasso_discovery_init_query() 
 * 
 * Return value: 0 on success and a negative value if an error occurs.
 **/
static gint
lasso_discovery_init_request(LassoDiscovery *discovery,
			     LassoDiscoResourceOffering *resourceOffering,
			     LassoDiscoDescription *description)
{
	LassoWsfProfile *profile = LASSO_WSF_PROFILE(discovery);

	/* verify that description is present in resourceOffering->ServiceInstance->Description */
	if (g_list_find(resourceOffering->ServiceInstance->Description, description) == NULL) {
		message(G_LOG_LEVEL_CRITICAL, lasso_strerror(LASSO_PARAM_ERROR_INVALID_VALUE));
	}

	/* get ResourceID/EncryptedResourceID in description */
	/* ResourceID and EncryptedResourceID are owned by resourceOffering,
	 so increment reference count */
	if (resourceOffering->ResourceID != NULL) {
		g_object_ref(resourceOffering->ResourceID);
		if (LASSO_IS_DISCO_MODIFY(profile->request)) {
			LASSO_DISCO_MODIFY(profile->request)->ResourceID =
				resourceOffering->ResourceID;
		} else if (LASSO_IS_DISCO_QUERY(profile->request)) {
			LASSO_DISCO_QUERY(profile->request)->ResourceID =
				resourceOffering->ResourceID;
		}
	} else if (resourceOffering->EncryptedResourceID != NULL) {
		g_object_ref(resourceOffering->EncryptedResourceID);
		if (LASSO_IS_DISCO_MODIFY(profile->request)) {
			LASSO_DISCO_MODIFY(profile->request)->EncryptedResourceID =
				resourceOffering->EncryptedResourceID;
		} else if (LASSO_IS_DISCO_QUERY(profile->request)) {
			LASSO_DISCO_QUERY(profile->request)->EncryptedResourceID =
				resourceOffering->EncryptedResourceID;
		}
	}

	if (description->Endpoint != NULL) {
		profile->msg_url = g_strdup(description->Endpoint);
	} /* TODO: else, description->WsdlURI, get endpoint automatically */

	return 0;
}

LassoDiscoInsertEntry*
lasso_discovery_add_insert_entry(LassoDiscovery *discovery,
				 LassoDiscoServiceInstance *serviceInstance,
				 LassoDiscoResourceID *resourceId)
{
	LassoDiscoModify *modify = NULL;
	LassoDiscoInsertEntry *insertEntry = NULL;
	LassoDiscoResourceOffering *resourceOffering = NULL;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), NULL);
	g_return_val_if_fail(LASSO_IS_DISCO_SERVICE_INSTANCE(serviceInstance), NULL);
	g_return_val_if_fail(LASSO_IS_DISCO_RESOURCE_ID(resourceId), NULL);

	modify = LASSO_DISCO_MODIFY(LASSO_WSF_PROFILE(discovery)->request);

	/* ResourceOffering elements being inserted MUST NOT contain entryID attributes. */
	serviceInstance = serviceInstance ? g_object_ref(serviceInstance) : serviceInstance;
	resourceOffering = lasso_disco_resource_offering_new(serviceInstance);

	resourceId = resourceId ? g_object_ref(resourceId) : resourceId;
	resourceOffering->ResourceID = resourceId;

	insertEntry = lasso_disco_insert_entry_new(resourceOffering);

	modify->InsertEntry = g_list_append(modify->InsertEntry, insertEntry);

	return insertEntry;
}

gint
lasso_discovery_add_remove_entry(LassoDiscovery *discovery,
				 const gchar    *entryID)
{
	LassoDiscoModify *modify = NULL;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(entryID != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

	modify = LASSO_DISCO_MODIFY(LASSO_WSF_PROFILE(discovery)->request);

	/* add RemoveEntry */
	modify->RemoveEntry = g_list_append(modify->RemoveEntry,
		lasso_disco_remove_entry_new(entryID));

	return 0;
}

/**
 * lasso_discovery_add_requested_service_type:
 * @discovery: a #LassoDiscovery
 * @service_type: requested service type
 * @option: option to the requested service
 *
 * Adds a request for service of @service_type to the disco:Query being built.
 *
 * Return value: a newly created #LassoDiscoRequestedServiceType with the
 *      request.  Note that it is internally allocated and shouldn't be freed
 *      by the caller.
 **/
LassoDiscoRequestedServiceType*
lasso_discovery_add_requested_service_type(LassoDiscovery *discovery,
					   const gchar    *service_type,
					   const gchar    *option)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoQuery *query = NULL;
	LassoDiscoRequestedServiceType *rst = NULL;
	LassoDiscoOptions *opts = NULL;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), NULL);
	g_return_val_if_fail(service_type != NULL, NULL);
	/* "option" parameter is optional */

	profile = LASSO_WSF_PROFILE(discovery);

	if (! LASSO_IS_DISCO_QUERY(profile->request)) {
		return NULL;
	}
	query = LASSO_DISCO_QUERY(profile->request);

	rst = lasso_disco_requested_service_type_new(service_type);

	/* optionals data */
	if (option != NULL) {
		opts = lasso_disco_options_new();
		opts->Option = g_list_append(opts->Option, (gpointer)option);
		rst->Options = opts;
	}

	/* add RequestedServiceType */
	query->RequestedServiceType = g_list_append(query->RequestedServiceType, (gpointer)rst);

	return rst;
}

gint
lasso_discovery_init_modify(LassoDiscovery *discovery,
			    LassoDiscoResourceOffering *resourceOffering,
			    LassoDiscoDescription *description)
{
	LassoWsfProfile *profile = NULL;
	LassoSoapEnvelope *envelope = NULL;
	LassoDiscoModify *modify = NULL;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(LASSO_IS_DISCO_RESOURCE_OFFERING(resourceOffering),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(LASSO_IS_DISCO_DESCRIPTION(description),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	profile = LASSO_WSF_PROFILE(discovery);

	modify = lasso_disco_modify_new();
	profile->request = LASSO_NODE(modify);

	envelope = lasso_wsf_profile_build_soap_envelope(NULL, NULL);
	envelope->Body->any = g_list_append(envelope->Body->any, modify);
	profile->soap_envelope_request = envelope;

	return lasso_discovery_init_request(discovery, resourceOffering, description);
}

static LassoDiscoResourceOffering*
lasso_discovery_get_resource_offering_auto(LassoDiscovery *discovery, const gchar *service_type)
{
	LassoWsfProfile *profile = LASSO_WSF_PROFILE(discovery);
	LassoDiscoResourceOffering *resource_offering = NULL;
	LassoSession *session = NULL;
	GList *assertions = NULL;
	LassoSamlAssertion *assertion = NULL;
	LassoSamlAttribute *attribute = NULL;
	LassoSamlAttributeValue *attribute_value = NULL;
	LassoDiscoResourceOffering *offering = NULL;
	GList *iter = NULL;
	GList *iter2 = NULL;
	GList *iter3 = NULL;
	GList *iter4 = NULL;

	if (profile->session == NULL) {
		return NULL;
	}

	session = profile->session;
	assertions = lasso_session_get_assertions(session, NULL);
	for (iter = assertions; iter != NULL; iter = g_list_next(iter)) {
		if (! LASSO_IS_SAML_ASSERTION(iter->data)) {
			continue;
		}
		assertion = LASSO_SAML_ASSERTION(iter->data);
		if (assertion->AttributeStatement == NULL) {
			continue;
		}
		for (iter2 = assertion->AttributeStatement->Attribute; iter2 != NULL;
				iter2 = g_list_next(iter2)) {
			if (! LASSO_IS_SAML_ATTRIBUTE(iter2->data)) {
				continue;
			}
			attribute = LASSO_SAML_ATTRIBUTE(iter2->data);
			if (strcmp(attribute->attributeName, "DiscoveryResourceOffering") != 0) {
				continue;
			}
			for (iter3 = attribute->AttributeValue; iter3 != NULL;
					iter3 = g_list_next(iter3)) {
				if (! LASSO_IS_SAML_ATTRIBUTE_VALUE(iter3->data)) {
					continue;
				}
				attribute_value = LASSO_SAML_ATTRIBUTE_VALUE(iter3->data);
				for (iter4 = attribute_value->any; iter4 != NULL;
						iter4 = g_list_next(iter4)) {
					if (! LASSO_IS_DISCO_RESOURCE_OFFERING(iter4->data)) {
						continue;
					}
					offering = LASSO_DISCO_RESOURCE_OFFERING(iter4->data);
					if (offering->ServiceInstance == NULL) {
						continue;
					}
					if (strcmp(offering->ServiceInstance->ServiceType,
								service_type) == 0) {
						resource_offering = offering;
						goto end;
					}
				}
			}
		}
	}

end:

	g_list_free(assertions);

	if (resource_offering) {
		return g_object_ref(resource_offering);
	}

	return NULL;
}

/**
 * lasso_discovery_get_description_auto:
 *
 *
 *
 * Return value: internally allocated, don't free
 **/
LassoDiscoDescription*
lasso_discovery_get_description_auto(LassoDiscoResourceOffering *offering,
	const gchar *security_mech_id)
{
	g_return_val_if_fail(LASSO_IS_DISCO_RESOURCE_OFFERING(offering), NULL);
	g_return_val_if_fail(security_mech_id != NULL, NULL);

	if (offering->ServiceInstance == NULL) {
		return NULL;
	}

	return lasso_wsf_profile_get_description_auto(offering->ServiceInstance, security_mech_id);
}

/**
 * lasso_discovery_init_insert
 * @discovery: a #LassoDiscovery
 * @new_offering: the new service offered
 * @security_mech_id: the security mechanism identifier
 *
 * Initializes a disco Modify/InsertEntry
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_discovery_init_insert(LassoDiscovery *discovery, LassoDiscoResourceOffering *new_offering,
	const char *security_mech_id)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoModify *modify = NULL;
	LassoDiscoResourceOffering *offering = NULL;
	LassoDiscoDescription *description = NULL;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(LASSO_IS_DISCO_RESOURCE_OFFERING(new_offering),
	     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	profile = LASSO_WSF_PROFILE(discovery);

	modify = lasso_disco_modify_new();
	lasso_wsf_profile_init_soap_request(profile, LASSO_NODE(modify));

	/* get discovery service resource id from principal assertion */
	offering = lasso_discovery_get_resource_offering_auto(discovery, LASSO_DISCO_HREF);
	if (! LASSO_IS_DISCO_RESOURCE_OFFERING(offering)) {
		return LASSO_PROFILE_ERROR_MISSING_RESOURCE_OFFERING;
	}
	if (security_mech_id) {
		description = lasso_discovery_get_description_auto(offering, security_mech_id);
	} else if (offering->ServiceInstance && offering->ServiceInstance->Description) {
		description = LASSO_DISCO_DESCRIPTION(offering->ServiceInstance->Description->data);
	}
	if (! LASSO_IS_DISCO_DESCRIPTION(description)) {
		return LASSO_PROFILE_ERROR_MISSING_SERVICE_DESCRIPTION;
	}
	lasso_wsf_profile_set_description(profile, description);

	/* TODO: EncryptedResourceID support */
	modify->ResourceID = g_object_ref(offering->ResourceID);
	lasso_node_destroy(LASSO_NODE(offering));

	modify->InsertEntry = g_list_append(modify->InsertEntry,
			lasso_disco_insert_entry_new(new_offering));
	profile->request = LASSO_NODE(modify);

	if (description->Endpoint != NULL) {
		profile->msg_url = g_strdup(description->Endpoint);
	} /* TODO: else, description->WsdlURI, get endpoint automatically */

	return 0;
}


/**
 * lasso_discovery_init_remove
 * @discovery: a #LassoDiscovery
 * @entry_id: entry id of the resource offering to remove
 *
 * Initializes a disco Modify/RemoveEntry
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_discovery_init_remove(LassoDiscovery *discovery, const char *entry_id)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoModify *modify = NULL;
	LassoDiscoResourceOffering *offering = NULL;
	LassoDiscoDescription *description = NULL;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	profile = LASSO_WSF_PROFILE(discovery);

	modify = lasso_disco_modify_new();
	lasso_wsf_profile_init_soap_request(profile, LASSO_NODE(modify));

	/* get discovery service resource id from principal assertion */
	offering = lasso_discovery_get_resource_offering_auto(discovery, LASSO_DISCO_HREF);
	if (! LASSO_IS_DISCO_RESOURCE_OFFERING(offering)) {
		return LASSO_PROFILE_ERROR_MISSING_RESOURCE_OFFERING;
	}

	description = lasso_discovery_get_description_auto(offering, LASSO_SECURITY_MECH_NULL);
	if (! LASSO_IS_DISCO_DESCRIPTION(description)) {
		return LASSO_PROFILE_ERROR_MISSING_SERVICE_DESCRIPTION;
	}

	/* TODO: EncryptedResourceID support */
	modify->ResourceID = g_object_ref(offering->ResourceID);
	lasso_node_destroy(LASSO_NODE(offering));

	modify->RemoveEntry = g_list_append(modify->RemoveEntry,
			lasso_disco_remove_entry_new(entry_id));

	profile->request = LASSO_NODE(modify);

	if (description->Endpoint != NULL) {
		profile->msg_url = g_strdup(description->Endpoint);
	} /* TODO: else, description->WsdlURI, get endpoint automatically */

	return 0;
}

/**
 * lasso_discovery_init_query
 * @discovery: a #LassoDiscovery
 *
 * Initializes a disco:Query message.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_discovery_init_query(LassoDiscovery *discovery, const gchar *security_mech_id)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoQuery *query = NULL;
	LassoDiscoResourceOffering *offering = NULL;
	LassoDiscoDescription *description = NULL;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	profile = LASSO_WSF_PROFILE(discovery);

	query = lasso_disco_query_new();
	lasso_wsf_profile_init_soap_request(profile, LASSO_NODE(query));

	/* get discovery service resource id from principal assertion */
	offering = lasso_discovery_get_resource_offering_auto(discovery, LASSO_DISCO_HREF);
	if (! LASSO_IS_DISCO_RESOURCE_OFFERING(offering)) {
		return LASSO_PROFILE_ERROR_MISSING_RESOURCE_OFFERING;
	}

	if (security_mech_id == NULL) {
		description = LASSO_DISCO_DESCRIPTION(offering->ServiceInstance->Description->data);
	} else {
		description = lasso_discovery_get_description_auto(offering, security_mech_id);
	}
	if (! LASSO_IS_DISCO_DESCRIPTION(description)) {
		return LASSO_PROFILE_ERROR_MISSING_SERVICE_DESCRIPTION;
	}

	lasso_wsf_profile_set_description(profile, description);

	/* TODO: EncryptedResourceID support */
	query->ResourceID = g_object_ref(offering->ResourceID);
	lasso_node_destroy(LASSO_NODE(offering));

	profile->request = LASSO_NODE(query);

	if (description->Endpoint != NULL) {
		profile->msg_url = g_strdup(description->Endpoint);
	} /* TODO: else, description->WsdlURI, get endpoint automatically */

	return 0;
}


/**
 * lasso_discovery_process_modify_msg:
 * @discovery: a #LassoDiscovery
 * @message: the disco:Modify SOAP message
 *
 * Processes a disco:Modify SOAP message.  Rebuilds a request object from the
 * message and extracts ResourceID.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_discovery_process_modify_msg(LassoDiscovery *discovery, const gchar *message,
	const gchar *security_mech_id)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoModify *request = NULL;
	int res;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(message != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

	profile = LASSO_WSF_PROFILE(discovery);

	res = lasso_wsf_profile_process_soap_request_msg(profile, message,
		LASSO_DISCO_HREF, security_mech_id);
	if (res != 0) {
		return res;
	}

	request = LASSO_DISCO_MODIFY(profile->request);

	if (request->ResourceID) {
		discovery->resource_id = g_object_ref(request->ResourceID);
	} else if (request->EncryptedResourceID) {
		discovery->encrypted_resource_id = g_object_ref(request->EncryptedResourceID);
	}

	return 0;
}


/**
 * lasso_discovery_build_modify_response_msg:
 * @discovery: a #LassoDiscovery
 *
 * Builds a disco:ModifyResponse message; answer to the disco:Modify passed
 * to lasso_discovery_process_modify_msg().  It inserts and removed
 * ResourceOfferings from identity; it must be saved afterwards.
 *
 * Sets @msg_body to the SOAP answer.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_discovery_build_modify_response_msg(LassoDiscovery *discovery)
{
	/* FIXME: Check all error cases, set the right status code,
		and don't return without building a response */

	LassoWsfProfile *profile = NULL;
	LassoDiscoModify *request = NULL;
	LassoDiscoModifyResponse *response = NULL;
	LassoSoapEnvelope *envelope = NULL;
	LassoUtilityStatus *status = NULL;
	LassoDiscoRemoveEntry *remove_entry = NULL;
	LassoDiscoInsertEntry *insert_entry = NULL;
	char *new_entry_ids = NULL;
	char *t_new_entry_ids = NULL;
	GList *iter = NULL;
	int res = 0;
	int res2 = 0;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	profile = LASSO_WSF_PROFILE(discovery);
	request = LASSO_DISCO_MODIFY(profile->request);

	if (lasso_wsf_profile_get_fault(profile)) {
		return lasso_wsf_profile_build_soap_response_msg(profile);
	}
	
	if (profile->identity == NULL) {
		return LASSO_PROFILE_ERROR_IDENTITY_NOT_FOUND;
	}

	/* build response */
	status = lasso_utility_status_new(LASSO_DISCO_STATUS_CODE_OK);
	response = lasso_disco_modify_response_new(status);
	profile->response = LASSO_NODE(response);
	envelope = profile->soap_envelope_response;
	envelope->Body->any = g_list_append(envelope->Body->any, response);

	/* First verify remove entries are all ok */
	for (iter = request->RemoveEntry; iter != NULL; iter = g_list_next(iter)) {
		if (! LASSO_IS_DISCO_REMOVE_ENTRY(iter->data)) {
			continue;
		}
		remove_entry = LASSO_DISCO_REMOVE_ENTRY(iter->data);

		if (! lasso_identity_get_resource_offering(profile->identity,
				remove_entry->entryID)) {
			res = LASSO_PROFILE_ERROR_MISSING_RESOURCE_OFFERING;
			break;
		}
	}

	/* Then remove the entries */
	if (res == 0) {
		for (iter = request->RemoveEntry; iter != NULL; iter = g_list_next(iter)) {
			remove_entry = LASSO_DISCO_REMOVE_ENTRY(iter->data);
			if (! lasso_identity_remove_resource_offering(profile->identity,
					remove_entry->entryID)) {
				/* Set the right error code */
				res = -1;
				break;
			}
		}
	}

	if (request->InsertEntry) {
		new_entry_ids = g_malloc(10 * g_list_length(request->InsertEntry));
		t_new_entry_ids = new_entry_ids;
	}

	for (iter = request->InsertEntry; iter != NULL; iter = g_list_next(iter)) {
		if (! LASSO_IS_DISCO_INSERT_ENTRY(iter->data)) {
			continue;
		}
		insert_entry = LASSO_DISCO_INSERT_ENTRY(iter->data);

		lasso_identity_add_resource_offering(profile->identity,
				insert_entry->ResourceOffering);

		t_new_entry_ids = g_stpcpy(t_new_entry_ids,
			insert_entry->ResourceOffering->entryID);
		t_new_entry_ids = g_stpcpy(t_new_entry_ids, " ");
	}
	if (t_new_entry_ids) {
		t_new_entry_ids[-1] = 0; /* remove trailing white space */
	}

	if (new_entry_ids) {
		response->newEntryIDs = g_strdup(new_entry_ids);
		g_free(new_entry_ids);
	}

	if (res != 0) {
		g_free(status->code);
		status->code = g_strdup(LASSO_DISCO_STATUS_CODE_FAILED);
	}

	res2 = lasso_wsf_profile_build_soap_response_msg(profile);
	if (res != 0) {
		return res;
	} else {
		return res2;
	}
}

/**
 * lasso_discovery_process_modify_response_msg:
 * @discovery: a #LassoDiscovery
 * @message: the disco:ModifyResponse SOAP message
 *
 * Processes a disco:ModifyResponse SOAP message.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_discovery_process_modify_response_msg(LassoDiscovery *discovery, const gchar *message)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoModifyResponse *response = NULL;
	int rc;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(message != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

	profile = LASSO_WSF_PROFILE(discovery);

	rc = lasso_wsf_profile_process_soap_response_msg(profile, message);
	if (rc) {
		return rc;
	}

	response = LASSO_DISCO_MODIFY_RESPONSE(profile->response);

	if (strcmp(response->Status->code, LASSO_DISCO_STATUS_CODE_OK) != 0) {
		return LASSO_PROFILE_ERROR_STATUS_NOT_SUCCESS;
	}

	return 0;
}

/**
 * lasso_discovery_process_query_msg:
 * @discovery: a #LassoDiscovery
 * @message: the disco:Query SOAP message
 *
 * Processes a disco:Query SOAP message.  Rebuilds a request object from the
 * message and extracts ResourceID.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_discovery_process_query_msg(LassoDiscovery *discovery, const gchar *message,
	const char *security_mech_id)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoQuery *request = NULL;
	LassoSoapEnvelope *envelope = NULL;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(message != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

	profile = LASSO_WSF_PROFILE(discovery);

	lasso_wsf_profile_process_soap_request_msg(profile, message, LASSO_DISCO_HREF,
		security_mech_id);

	envelope = profile->soap_envelope_response;
	request = LASSO_DISCO_QUERY(profile->request);

	if (request->ResourceID) {
		discovery->resource_id = g_object_ref(request->ResourceID);
	} else if (request->EncryptedResourceID) {
		discovery->encrypted_resource_id = g_object_ref(request->EncryptedResourceID);
	} else {
		return LASSO_ERROR_UNIMPLEMENTED; /* implied ? */
	}

	return 0;
}


/**
 * lasso_discovery_build_response_msg
 * @discovery: a #LassoDiscovery
 *
 * Builds a disco:QueryResponse message; answer to the disco:Query passed to
 * lasso_discovery_process_query_msg().  It looks up resource offerings in the
 * principal identity and extracts those of the requested service type.
 *
 * Sets @msg_body to the SOAP answer.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_discovery_build_response_msg(LassoDiscovery *discovery)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoQuery *request = NULL;
	LassoDiscoQueryResponse *response = NULL;
	LassoSoapEnvelope *envelope = NULL;
	GList *offerings = NULL;
	gchar *credentialRef;
	GList *iter = NULL;
	GList *iter2 = NULL;
	GList *iter3 = NULL;
	int res = 0;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	profile = LASSO_WSF_PROFILE(discovery);
	request = LASSO_DISCO_QUERY(profile->request);

	if (lasso_wsf_profile_get_fault(profile)) {
		return lasso_wsf_profile_build_soap_response_msg(profile);
	}

	if (profile->identity == NULL) {
		return LASSO_PROFILE_ERROR_IDENTITY_NOT_FOUND;
	}

	iter = request->RequestedServiceType;
	while (iter) {
		LassoDiscoRequestedServiceType *service_type = iter->data;
		iter = g_list_next(iter);
		offerings = g_list_concat(offerings, lasso_identity_get_offerings(
					profile->identity,
					service_type->ServiceType));
	}

	/* build response */
	response = lasso_disco_query_response_new(
			lasso_utility_status_new(LASSO_DST_STATUS_CODE_OK));
	response->ResourceOffering = offerings;
	profile->response = LASSO_NODE(response);
	envelope = profile->soap_envelope_response;
	envelope->Body->any = g_list_append(envelope->Body->any, response);
	
	/* Add needed credentials for offerings */
	iter = offerings;
	while (iter) {
		LassoDiscoResourceOffering *resource_offering = iter->data;
		iter = g_list_next(iter);
		iter2 = resource_offering->ServiceInstance->Description;
		while (iter2) {
			LassoDiscoDescription *description = LASSO_DISCO_DESCRIPTION(iter2->data);
			iter3 = description->SecurityMechID;
			while (iter3) {
				if (lasso_security_mech_id_is_saml_authentication(
					    iter3->data) == TRUE) {
					credentialRef = lasso_discovery_build_credential(
						discovery, NULL);
					description->CredentialRef = g_list_append(
						description->CredentialRef, credentialRef);
				}
				iter3 = g_list_next(iter3);
			}
			iter2 = g_list_next(iter2);
		}
	}

	res = lasso_wsf_profile_build_soap_response_msg(profile);
	
	return res;
}

/**
 * lasso_discovery_process_query_response_msg:
 * @discovery: a #LassoDiscovery
 * @message: the disco:QueryResponse message
 *
 * Processes a disco:QueryResponse message.
 *
 * Return value: 0 on success; or a negative value otherwise.
 **/
gint
lasso_discovery_process_query_response_msg(LassoDiscovery *discovery, const gchar *message)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoQueryResponse *response;
	int rc;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(message != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

	profile = LASSO_WSF_PROFILE(discovery);

	rc = lasso_wsf_profile_process_soap_response_msg(profile, message);
	if (rc) {
		return rc;
	}

	response = LASSO_DISCO_QUERY_RESPONSE(profile->response);

	if (strcmp(response->Status->code, LASSO_DISCO_STATUS_CODE_OK) != 0) {
		return LASSO_PROFILE_ERROR_STATUS_NOT_SUCCESS;
	}

	/* XXX: anything else to do ? */

	return 0;
}


/**
 * lasso_discovery_get_service:
 * @discovery: a #LassoDiscovery
 * @service_type: the requested service type
 *
 * After a disco:query message, creates a #LassoDataService instance for the
 * requested @service_type.
 *
 * Return value: a newly created #LassoDataService object; or NULL if an
 *     error occured.
 **/
LassoDataService*
lasso_discovery_get_service(LassoDiscovery *discovery, const char *service_type)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoQueryResponse *response;
	GList *iter;
	LassoDiscoResourceOffering *offering = NULL;
	LassoDataService *service;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), NULL);

	profile = LASSO_WSF_PROFILE(discovery);

	response = LASSO_DISCO_QUERY_RESPONSE(profile->response);
	if (response == NULL) {
		/* no response; probably called at wrong time */
		return NULL;
	}

	iter = response->ResourceOffering;
	if (iter == NULL) {
		return NULL; /* resource not found */
	}
	if (service_type == NULL) {
		offering = iter->data;
	} else {
		while (iter) {
			LassoDiscoResourceOffering *t = iter->data;
			iter = g_list_next(iter);
			if (t->ServiceInstance == NULL)
				continue;
			if (strcmp(t->ServiceInstance->ServiceType, service_type) == 0) {
				offering = t;
				break;
			}
		}
		if (offering == NULL) {
			return NULL; /* resource not found */
		}
	}

	if (strcmp(offering->ServiceInstance->ServiceType, LASSO_PP_HREF) == 0) {
		service = LASSO_DATA_SERVICE(lasso_personal_profile_service_new_full(
					profile->server, offering));
	} else {
		service = lasso_data_service_new_full(profile->server,
				offering);
	}

	lasso_wsf_profile_move_credentials(profile,
					   LASSO_WSF_PROFILE(service));

	return service;
}


/**
 * lasso_discovery_get_services:
 * @discovery: a #LassoDiscovery
 *
 * After a disco:query message, creates a GList object of #LassoDataService.
 *
 * Return value: a newly created GList object of #LassoDataService;
 *     or NULL if an error occured.
 **/
GList*
lasso_discovery_get_services(LassoDiscovery *discovery)
{
	LassoWsfProfile *profile = NULL;
	LassoDiscoQueryResponse *response;
	GList *iter;
	LassoDiscoResourceOffering *offering;
	LassoDataService *service;
	GList *services;

	g_return_val_if_fail(LASSO_IS_DISCOVERY(discovery), NULL);

	profile = LASSO_WSF_PROFILE(discovery);
	response = LASSO_DISCO_QUERY_RESPONSE(profile->response);

	iter = response->ResourceOffering;
	if (iter == NULL) {
		return NULL; /* resource not found */
	}

	services = NULL;
	while (iter) {
		offering = iter->data;
		iter = g_list_next(iter);
		if (offering->ServiceInstance == NULL) {
			continue;
		}
		if (strcmp(offering->ServiceInstance->ServiceType, LASSO_PP_HREF) == 0) {
			service = LASSO_DATA_SERVICE(lasso_personal_profile_service_new_full(
				profile->server, offering));
		} else {
			service = lasso_data_service_new_full(
				profile->server, offering);
		}
		services = g_list_append(services, service);
	}

	return services;
}

/**
 * lasso_discovery_destroy:
 * @discovery: a LassoDiscovery
 * 
 * Destroys LassoDiscovery objects created with lasso_discovery_new() or
 * lasso_discovery_new_from_dump().
 **/
void
lasso_discovery_destroy(LassoDiscovery *discovery)
{
	lasso_node_destroy(LASSO_NODE(discovery));
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
	xmlNodeSetName(xmlnode, (xmlChar*)"Discovery");
	xmlSetProp(xmlnode, (xmlChar*)"DiscoveryDumpVersion", (xmlChar*)"2");

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
	LassoDiscovery *discovery = LASSO_DISCOVERY(object);

	if (discovery->private_data->dispose_has_run == TRUE)
		return;
	discovery->private_data->dispose_has_run = TRUE;

	G_OBJECT_CLASS(parent_class)->dispose(object);
}

static void
finalize(GObject *object)
{ 
	LassoDiscovery *discovery = LASSO_DISCOVERY(object);
	g_free(discovery->private_data);
	discovery->private_data = NULL;
	G_OBJECT_CLASS(parent_class)->finalize(object);
}

/*****************************************************************************/
/* instance and class init functions */
/*****************************************************************************/

static void
instance_init(LassoDiscovery *discovery)
{
	discovery->private_data = g_new0(LassoDiscoveryPrivate, 1);
	discovery->private_data->dispose_has_run = FALSE;
}

static void
class_init(LassoDiscoveryClass *klass)
{
	parent_class = g_type_class_peek_parent(klass);

	LASSO_NODE_CLASS(klass)->get_xmlNode = get_xmlNode;
	LASSO_NODE_CLASS(klass)->init_from_xml = init_from_xml;

	G_OBJECT_CLASS(klass)->dispose = dispose;
	G_OBJECT_CLASS(klass)->finalize = finalize;
}

GType
lasso_discovery_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof(LassoDiscoveryClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoDiscovery),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_WSF_PROFILE,
						   "LassoDiscovery", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_discovery_new:
 * @server: the #LassoServer
 *
 * Creates a new #LassoDiscovery.
 *
 * Return value: a newly created #LassoDiscovery object; or NULL if an error
 *      occured.
 **/
LassoDiscovery*
lasso_discovery_new(LassoServer *server)
{
	LassoDiscovery *discovery = NULL;

	g_return_val_if_fail(LASSO_IS_SERVER(server), NULL);

	discovery = g_object_new(LASSO_TYPE_DISCOVERY, NULL);
	LASSO_WSF_PROFILE(discovery)->server = g_object_ref(server);

	return discovery;
}
