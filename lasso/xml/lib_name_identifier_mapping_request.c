/* $Id: lib_name_identifier_mapping_request.c,v 1.21 2005/11/20 15:38:19 fpeters Exp $ 
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

#include <lasso/xml/lib_name_identifier_mapping_request.h>

/*
 * Schema fragment (oasis-sstc-saml-schema-protocol-1.0.xsd):
 * 
 * <xs:element name="NameIdentifierMappingRequest" type="NameIdentifierMappingRequestType"/>
 * <xs:complexType name="NameIdentifierMappingRequestType">
 *   <xs:complexContent>
 *     <xs:extension base="samlp:RequestAbstractType">
 *       <xs:sequence>
 *         <xs:element ref="Extension" minOccurs="0" maxOccurs="unbounded"/>
 *         <xs:element ref="ProviderID"/>
 *         <xs:element ref="saml:NameIdentifier"/>
 *         <xs:element name="TargetNamespace" type="md:entityIDType"/>
 *       </xs:sequence>
 *       <xs:attribute ref="consent" use="optional"/>
 *     </xs:extension>
 *   </xs:complexContent>
 * </xs:complexType>
 * 
 * <xs:element name="ProviderID" type="md:entityIDType"/>
 * 
 * From liberty-metadata-v1.0.xsd:
 * <xs:simpleType name="entityIDType">
 *   <xs:restriction base="xs:anyURI">
 *     <xs:maxLength value="1024" id="maxlengthid"/>
 *   </xs:restriction>
 * </xs:simpleType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Extension", SNIPPET_EXTENSION,
		G_STRUCT_OFFSET(LassoLibNameIdentifierMappingRequest, Extension) },
	{ "ProviderID", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoLibNameIdentifierMappingRequest, ProviderID) },
	{ "NameIdentifier", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoLibNameIdentifierMappingRequest, NameIdentifier) },
	{ "TargetNamespace", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoLibNameIdentifierMappingRequest, TargetNamespace) },
	{ "consent", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoLibNameIdentifierMappingRequest, consent) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoLibNameIdentifierMappingRequest *node)
{
	node->Extension = NULL;
	node->ProviderID = NULL;
	node->NameIdentifier = NULL;
	node->TargetNamespace = NULL;
	node->consent = NULL;
}

static void
class_init(LassoLibNameIdentifierMappingRequestClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "NameIdentifierMappingRequest");
	lasso_node_class_set_ns(nclass, LASSO_LIB_HREF, LASSO_LIB_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_lib_name_identifier_mapping_request_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoLibNameIdentifierMappingRequestClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoLibNameIdentifierMappingRequest),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_SAMLP_REQUEST_ABSTRACT,
				"LassoLibNameIdentifierMappingRequest", &this_info, 0);
	}
	return this_type;
}


/**
 * lasso_lib_name_identifier_mapping_request_new:
 *
 * Creates a new #LassoLibNameIdentifierMappingRequest object.
 *
 * Return value: a newly created #LassoLibNameIdentifierMappingRequest object
 **/
LassoNode*
lasso_lib_name_identifier_mapping_request_new()
{
	return g_object_new(LASSO_TYPE_LIB_NAME_IDENTIFIER_MAPPING_REQUEST, NULL);
}


/**
 * lasso_lib_name_identifier_mapping_request_new_full:
 * @providerID: the provider ID requesting the name identifier mapping
 * @nameIdentifier:
 * @targetNamespace:
 * @sign_type:
 * @sign_method:
 *
 * Creates a new #LassoLibNameIdentifierMappingRequest object and initializes
 * it with the parameters.
 *
 * Return value: a newly created #LassoLibNameIdentifierMappingRequest object
 **/
LassoNode*
lasso_lib_name_identifier_mapping_request_new_full(char *providerID,
		LassoSamlNameIdentifier *nameIdentifier, const char *targetNamespace,
		LassoSignatureType sign_type, LassoSignatureMethod sign_method)
{
	LassoSamlpRequestAbstract *request;

	request = g_object_new(LASSO_TYPE_LIB_NAME_IDENTIFIER_MAPPING_REQUEST, NULL);

	request->RequestID = lasso_build_unique_id(32);
	request->MajorVersion = LASSO_LIB_MAJOR_VERSION_N;
	request->MinorVersion = LASSO_LIB_MINOR_VERSION_N;
	request->IssueInstant = lasso_get_current_time();
	request->sign_type = sign_type;
	request->sign_method = sign_method;

	/* ProviderID */
	LASSO_LIB_NAME_IDENTIFIER_MAPPING_REQUEST(request)->ProviderID = g_strdup(providerID);
	LASSO_LIB_NAME_IDENTIFIER_MAPPING_REQUEST(request)->NameIdentifier = 
		g_object_ref(nameIdentifier);

	LASSO_LIB_NAME_IDENTIFIER_MAPPING_REQUEST(request)->TargetNamespace =
		g_strdup(targetNamespace);

	/* XXX: consent ?  */

	return LASSO_NODE(request);
}
