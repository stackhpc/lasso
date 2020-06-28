/* $Id: sa_sasl_request.c,v 1.3 2005/03/02 08:31:22 nclapies Exp $
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

#include <lasso/xml/sa_sasl_request.h>

/*
 * Schema fragments (liberty-idwsf-authn-svc-v1.0.xsd):
 * 
 *  <xs:element name="SASLRequest">
 *    <xs:complexType>
 *      <xs:sequence>
 *        <xs:element name="Data" minOccurs="0">
 *          <xs:complexType>
 *            <xs:simpleContent>
 *              <xs:extension base="xs:base64Binary"/>
 *            </xs:simpleContent>
 *          </xs:complexType>
 *        </xs:element>
 *        <xs:element ref="lib:RequestAuthnContext" minOccurs="0"/> 
 *      </xs:sequence>
 *      <xs:attribute name="mechanism"type="xs:string" use="required"/>
 *      <xs:attribute name="authzID" type="xs:string" use="optional"/>
 *      <xs:attribute name="advisoryAuthnID" type="xs:string" use="optional"/>
 *      <xs:attribute name="id" type="xs:ID"use="optional"/>
 *    </xs:complexType>
 *  </xs:element>
 */ 

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Data", SNIPPET_LIST_CONTENT,
	  G_STRUCT_OFFSET(LassoSaSASLRequest, Data) },
	{ "RequestAuthnContext", SNIPPET_NODE,
	  G_STRUCT_OFFSET(LassoSaSASLRequest, RequestAuthnContext) },
	{ "mechanism", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSaSASLRequest, mechanism) },
	{ "authzID", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSaSASLRequest, authzID) },
	{ "advisoryAuthnID", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSaSASLRequest, advisoryAuthnID) },
	{ "id", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSaSASLRequest, id) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSaSASLRequest *node)
{
	node->Data = NULL;
	node->RequestAuthnContext = NULL;

	node->mechanism = NULL;
	node->authzID = NULL;
	node->advisoryAuthnID = NULL;
	node->id = NULL;
}

static void
class_init(LassoSaSASLRequestClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "SASLRequest");
	lasso_node_class_set_ns(nclass, LASSO_SA_HREF, LASSO_SA_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_sa_sasl_request_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSaSASLRequestClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSaSASLRequest),
			0,
			(GInstanceInitFunc) instance_init,
		};
		
		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSaSASLRequest", &this_info, 0);
	}
	return this_type;
}

LassoSaSASLRequest*
lasso_sa_sasl_request_new(const gchar *mechanism)
{
	LassoSaSASLRequest *node;

	g_return_val_if_fail(mechanism != NULL, NULL);

	node = g_object_new(LASSO_TYPE_SA_SASL_REQUEST, NULL);
	node->mechanism = g_strdup(mechanism);

	return node;
}

LassoSaSASLRequest*
lasso_sa_sasl_request_new_from_message(const gchar *message)
{
	LassoSaSASLRequest *node;

	g_return_val_if_fail(message != NULL, NULL);

	node = g_object_new(LASSO_TYPE_SA_SASL_REQUEST, NULL);
	lasso_node_init_from_message(LASSO_NODE(node), message);

	return node;
}