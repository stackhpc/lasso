/* $Id: sa_sasl_response.c,v 1.4 2005/03/02 17:10:22 nclapies Exp $ 
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

#include <lasso/xml/sa_sasl_response.h>

/*
 * Schema fragments (lib-arch-authn-svc.xsd):
 * 
 * <xs:element name="SASLResponse">
 * <xs:complexType>
 *   <xs:sequence>
 *     <xs:element ref="Status"/>
 *     <xs:element ref="PasswordTransforms" minOccurs="0"/>
 *     <xs:element name="Data" minOccurs="0">
 *     <xs:complexType>
 *       <xs:simpleContent>
 *         <xs:extension base="xs:base64Binary"/>
 *       </xs:simpleContent>
 *     </xs:complexType>
 *     </xs:element>
 *     <xs:element ref="disco:ResourceOffering" minOccurs="0" maxOccurs="unbounded"/>
 *     <xs:element name="Credentials" minOccurs="0">
 *     <xs:complexType>
 *       <xs:sequence>
 *         <xs:any namespace="##any" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
 *       </xs:sequence>
 *     </xs:complexType>
 *     </xs:element>
 *   </xs:sequence> 
 *   <xs:attribute name="serverMechanism" type="xs:string" ="optional"/>
 *   <xs:attribute name="id" type="xs:ID" use="optional"/>
 * </xs:complexType>
 * </xs:element>
 *
 */ 

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Status", SNIPPET_NODE, G_STRUCT_OFFSET(LassoSaSASLResponse, Status) },
	{ "PasswordTransforms", SNIPPET_LIST_NODES,
	  G_STRUCT_OFFSET(LassoSaSASLResponse, PasswordTransforms) },
	{ "Data", SNIPPET_LIST_CONTENT,
	  G_STRUCT_OFFSET(LassoSaSASLResponse, Data) },
	{ "ResourceOffering", SNIPPET_LIST_NODES,
	  G_STRUCT_OFFSET(LassoSaSASLResponse, ResourceOffering) },
	{ "Credentials", SNIPPET_LIST_NODES, G_STRUCT_OFFSET(LassoSaSASLResponse, Credentials) },
	{ "serverMechanism", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSaSASLResponse, serverMechanism) },
	{ "id", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSaSASLResponse, id) },
	{ NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;

static void
insure_namespace(xmlNode *xmlnode, xmlNs *ns)
{
	xmlNode *t = xmlnode->children;

	xmlSetNs(xmlnode, ns);
	while (t) {
		if (t->type == XML_ELEMENT_NODE && t->ns == NULL)
			insure_namespace(t, ns);
		t = t->next;
	}
}

static xmlNode*
get_xmlNode(LassoNode *node, gboolean lasso_dump)
{
	xmlNode *xmlnode;
	xmlNs *ns;

	xmlnode = parent_class->get_xmlNode(node, lasso_dump);
	ns = xmlNewNs(xmlnode, LASSO_SA_HREF, LASSO_SA_PREFIX);
	insure_namespace(xmlnode, ns);

	return xmlnode;
}

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSaSASLResponse *node)
{
	node->Status = NULL;
	node->PasswordTransforms = NULL;
	node->Data = NULL;
	node->ResourceOffering = NULL;
	node->Credentials = NULL;
	node->any = NULL;
	node->serverMechanism = NULL;
	node->id = NULL;
}

static void
class_init(LassoSaSASLResponseClass *klass)
{
	LassoNodeClass *nodeClass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nodeClass->get_xmlNode = get_xmlNode;
	nodeClass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nodeClass, "SASLResponse");
	lasso_node_class_add_snippets(nodeClass, schema_snippets);
}

GType
lasso_sa_sasl_response_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSaSASLResponseClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSaSASLResponse),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSaSASLResponse", &this_info, 0);
	}
	return this_type;
}

LassoSaSASLResponse*
lasso_sa_sasl_response_new(LassoUtilityStatus *status)
{
	LassoSaSASLResponse *node;

	node = g_object_new(LASSO_TYPE_SA_SASL_RESPONSE, NULL);

	g_object_ref(status);
	node->Status = status;

	return node;
}

LassoSaSASLResponse*
lasso_sa_sasl_response_new_from_message(const gchar *message)
{
	LassoSaSASLResponse *node;

	g_return_val_if_fail(message != NULL, NULL);

	node = g_object_new(LASSO_TYPE_SA_SASL_RESPONSE, NULL);
	lasso_node_init_from_message(LASSO_NODE(node), message);

	return node;
}

gint
lasso_sa_sasl_response_add_credentials(LassoSaSASLResponse *response,
				       LassoSaCredentials *credentials)
{
	g_return_val_if_fail(LASSO_IS_SA_SASL_RESPONSE(response),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(LASSO_IS_SA_CREDENTIALS(credentials),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	g_object_ref(credentials);
	response->Credentials = g_list_append(response->Credentials, credentials);

	return 0;
}

gint
lasso_sa_sasl_response_add_resource_offering(LassoSaSASLResponse *response,
					     LassoDiscoResourceOffering *resourceOffering)
{
	g_return_val_if_fail(LASSO_IS_SA_SASL_RESPONSE(response),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(LASSO_IS_DISCO_RESOURCE_OFFERING(resourceOffering),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	g_object_ref(resourceOffering);
	response->ResourceOffering = g_list_append(response->ResourceOffering, resourceOffering);

	return 0;
}
