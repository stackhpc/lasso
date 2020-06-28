/* $Id: lib_authn_response.c,v 1.20 2007/01/06 22:55:24 fpeters Exp $ 
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

#include <lasso/xml/lib_authn_response.h>

/*
 * Schema fragment (liberty-idff-protocols-schema-v1.2.xsd):
 * 
 * <xs:element name="AuthnResponse" type="AuthnResponseType"/>
 * <xs:complexType name="AuthnResponseType">
 *   <xs:complexContent>
 *     <xs:extension base="samlp:ResponseType">
 *       <xs:sequence>
 *         <xs:element ref="Extension" minOccurs="0" maxOccurs="unbounded"/>
 * 	<xs:element ref="ProviderID"/>
 * 	<xs:element ref="RelayState" minOccurs="0"/>
 *       </xs:sequence>
 *       <xs:attribute ref="consent" use="optional"/>
 *     </xs:extension>
 *   </xs:complexContent>
 * </xs:complexType>
 * 
 * <xs:element name="ProviderID" type="md:entityIDType"/>
 * From liberty-metadata-v1.0.xsd:
 * <xs:simpleType name="entityIDType">
 *   <xs:restriction base="xs:anyURI">
 *     <xs:maxLength value="1024" id="maxlengthid"/>
 *   </xs:restriction>
 * </xs:simpleType>
 * <xs:element name="RelayState" type="xs:string"/>
 * 
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Extension", SNIPPET_EXTENSION, G_STRUCT_OFFSET(LassoLibAuthnResponse, Extension) },
	{ "ProviderID", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoLibAuthnResponse, ProviderID) },
	{ "RelayState", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoLibAuthnResponse, RelayState) },
	{ "consent", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoLibAuthnResponse, consent) },
	{ NULL, 0, 0 }
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoLibAuthnResponse *node)
{
	node->Extension = NULL;
	node->ProviderID = NULL;
	node->RelayState = NULL;
	node->consent = NULL;
}

static void
class_init(LassoLibAuthnResponseClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "AuthnResponse");
	lasso_node_class_set_ns(nclass, LASSO_LIB_HREF, LASSO_LIB_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_lib_authn_response_get_type()
{
	static GType authn_response_type = 0;

	if (!authn_response_type) {
		static const GTypeInfo authn_response_info = {
			sizeof (LassoLibAuthnResponseClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoLibAuthnResponse),
			0,
			(GInstanceInitFunc) instance_init,
		};

		authn_response_type = g_type_register_static(LASSO_TYPE_SAMLP_RESPONSE,
				"LassoLibAuthnResponse", &authn_response_info, 0);
	}
	return authn_response_type;
}


/**
 * lasso_lib_authn_response_new:
 * @providerID: the identity provider ID
 * @request: the #LassoLibAuthnRequest it is a response to
 *
 * Creates a new #LassoLibAuthnResponse object.
 *
 * Return value: a newly created #LassoLibAuthnResponse object
 **/
LassoNode*
lasso_lib_authn_response_new(char *providerID, LassoLibAuthnRequest *request)
{
	LassoLibAuthnResponse *response;

	response = g_object_new(LASSO_TYPE_LIB_AUTHN_RESPONSE, NULL);

	if (providerID) {
		lasso_samlp_response_abstract_fill(
				LASSO_SAMLP_RESPONSE_ABSTRACT(response),
				LASSO_SAMLP_REQUEST_ABSTRACT(request)->RequestID,
				request->ProviderID);
		response->ProviderID = g_strdup(providerID);
		response->RelayState = g_strdup(request->RelayState);
	}

	return LASSO_NODE(response);
}
