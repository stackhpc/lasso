/* $Id: disco_description.c 3237 2007-05-30 17:17:45Z dlaniel $ 
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

#include <lasso/xml/disco_description.h>

/*
 * Schema fragment (liberty-idwsf-disco-svc-1.0-errata-v1.0.xsd):
 * 
 * <xs:complexType name="DescriptionType">
 *   <xs:sequence>
 *     <xs:element name="SecurityMechID" type="xs:anyURI" minOccurs="1" maxOccurs="unbounded"/>
 *     <xs:element name="CredentialRef" type="xs:IDREF" minOccurs="0" maxOccurs="unbounded"/>
 *     <xs:choice>
 *       <xs:group ref="WsdlRef"/>
 *       <xs:group ref="BriefSoapHttpDescription"/>
 *     </xs:choice>
 *   </xs:sequence>
 *   <xs:attribute name="id" type="xs:ID"/>
 * </xs:complexType>
 * 
 * <xs:group name="WsdlRef">
 *   <xs:sequence>
 *     <xs:element name="WsdlURI" type="xs:anyURI"/>
 *     <xs:element name="ServiceNameRef" type="xs:QName"/>
 *   </xs:sequence>
 * </xs:group>
 * 
 * <xs:group name="BriefSoapHttpDescription">
 *   <xs:sequence>
 *     <xs:element name="Endpoint" type="xs:anyURI"/>
 *     <xs:element name="SoapAction" type="xs:anyURI" minOccurs="0"/>
 *   </xs:sequence>
 * </xs:group>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "SecurityMechID", SNIPPET_LIST_CONTENT,
	  G_STRUCT_OFFSET(LassoDiscoDescription, SecurityMechID) },
	{ "CredentialRef", SNIPPET_LIST_CONTENT,
	  G_STRUCT_OFFSET(LassoDiscoDescription, CredentialRef) },
	{ "WsdlURI", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoDiscoDescription, WsdlURI) },
	{ "ServiceNameRef", SNIPPET_CONTENT,
	  G_STRUCT_OFFSET(LassoDiscoDescription, ServiceNameRef) },
	{ "Endpoint", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoDiscoDescription, Endpoint) },
	{ "SoapAction", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoDiscoDescription, SoapAction) },
	{ "id", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoDiscoDescription, id) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoDiscoDescription *node)
{
	node->SecurityMechID = NULL;
	node->CredentialRef = NULL;

	node->WsdlURI= NULL;
	node->ServiceNameRef = NULL;

	node->Endpoint = NULL;
	node->SoapAction = NULL;

	node->id = NULL;
}

static void
class_init(LassoDiscoDescriptionClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Description");
	lasso_node_class_set_ns(nclass, LASSO_DISCO_HREF, LASSO_DISCO_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_disco_description_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoDiscoDescriptionClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoDiscoDescription),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
						   "LassoDiscoDescription", &this_info, 0);
	}
	return this_type;
}

LassoDiscoDescription*
lasso_disco_description_new()
{
	LassoDiscoDescription *description;

	description = g_object_new(LASSO_TYPE_DISCO_DESCRIPTION, NULL);

	return description;
}

LassoDiscoDescription*
lasso_disco_description_new_with_WsdlRef(const gchar *securityMechID,
					 const gchar *wsdlURI,
					 const gchar *serviceNameRef)
{
	LassoDiscoDescription *description;

	g_return_val_if_fail(securityMechID != NULL, NULL);
	g_return_val_if_fail(wsdlURI != NULL, NULL);
	g_return_val_if_fail(serviceNameRef != NULL, NULL);

	description = g_object_new(LASSO_TYPE_DISCO_DESCRIPTION, NULL);

	description->SecurityMechID = g_list_append(description->SecurityMechID,
						    g_strdup(securityMechID));
	description->WsdlURI = g_strdup(wsdlURI);
	description->ServiceNameRef = g_strdup(serviceNameRef);

	return description;
}

LassoDiscoDescription*
lasso_disco_description_new_with_BriefSoapHttpDescription(const gchar *securityMechID,
							  const gchar *endpoint,
							  const gchar *soapAction)
{
	LassoDiscoDescription *description;

	g_return_val_if_fail(securityMechID != NULL, NULL);
	g_return_val_if_fail(endpoint != NULL, NULL);
	
	description = g_object_new(LASSO_TYPE_DISCO_DESCRIPTION, NULL);

	description->SecurityMechID = g_list_append(description->SecurityMechID,
						    g_strdup(securityMechID));
	description->Endpoint = g_strdup(endpoint);
	if (soapAction != NULL) {
		description->SoapAction = g_strdup(soapAction);
	}

	return description;
}

LassoDiscoDescription*
lasso_disco_description_copy(LassoDiscoDescription *description)
{
	LassoDiscoDescription *newDescription;
	GList *securityMechIds, *credentialRefs;

	newDescription = g_object_new(LASSO_TYPE_DISCO_DESCRIPTION, NULL);

	securityMechIds = description->SecurityMechID;
	while (securityMechIds) {
		newDescription->SecurityMechID = g_list_append(newDescription->SecurityMechID,
							       g_strdup(securityMechIds->data));
		securityMechIds = securityMechIds->next;
	}

	credentialRefs = description->CredentialRef;
	while (credentialRefs) {
		newDescription->CredentialRef = g_list_append(newDescription->CredentialRef,
							      g_strdup(credentialRefs->data));
		credentialRefs = credentialRefs->next;
	}

	newDescription->WsdlURI = g_strdup(description->WsdlURI);
	newDescription->ServiceNameRef = g_strdup(description->ServiceNameRef);

	if (description->Endpoint) {
		newDescription->Endpoint = g_strdup(description->Endpoint);	
	}
	if (description->SoapAction) {
		newDescription->SoapAction = g_strdup(description->SoapAction);	
	}
	
	if (description->id) {
		newDescription->id = g_strdup(description->id);
	}

	return newDescription;
}
