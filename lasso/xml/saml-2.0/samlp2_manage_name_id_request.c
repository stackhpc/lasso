/* $Id: samlp2_manage_name_id_request.c,v 1.3 2006/12/28 14:44:56 fpeters Exp $ 
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

#include "samlp2_manage_name_id_request.h"

/*
 * Schema fragment (saml-schema-protocol-2.0.xsd):
 *
 * <complexType name="ManageNameIDRequestType">
 *   <complexContent>
 *     <extension base="samlp:RequestAbstractType">
 *       <sequence>
 *         <choice>
 *           <element ref="saml:NameID"/>
 *           <element ref="saml:EncryptedID"/>
 *         </choice>
 *         <choice>
 *           <element ref="samlp:NewID"/>
 *           <element ref="samlp:NewEncryptedID"/>
 *           <element ref="samlp:Terminate"/>
 *         </choice>
 *       </sequence>
 *     </extension>
 *   </complexContent>
 * </complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "NameID", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlp2ManageNameIDRequest, NameID) },
	{ "EncryptedID", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlp2ManageNameIDRequest, EncryptedID),
		"LassoSaml2EncryptedElement" },
	{ "NewID", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoSamlp2ManageNameIDRequest, NewID) },
	{ "NewEncryptedID", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlp2ManageNameIDRequest, NewEncryptedID),
		"LassoSaml2EncryptedElement" },
	{ "Terminate", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlp2ManageNameIDRequest, Terminate) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


static gchar*
build_query(LassoNode *node)
{
	char *ret, *deflated_message;

	deflated_message = lasso_node_build_deflated_query(node);
	if (deflated_message == NULL) {
		return NULL;
	}
	ret = g_strdup_printf("SAMLRequest=%s", deflated_message);
	/* XXX: must support RelayState (which profiles?) */
	g_free(deflated_message);
	return ret;
}


static gboolean
init_from_query(LassoNode *node, char **query_fields)
{
	gboolean rc;
	char *relay_state = NULL;
	rc = lasso_node_init_from_saml2_query_fields(node, query_fields, &relay_state);
	if (rc && relay_state != NULL) {
		/* XXX: support RelayState? */
	}
	return rc;
}


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSamlp2ManageNameIDRequest *node)
{
	node->NameID = NULL;
	node->EncryptedID = NULL;
	node->NewID = NULL;
	node->NewEncryptedID = NULL;
	node->Terminate = NULL;
}

static void
class_init(LassoSamlp2ManageNameIDRequestClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->build_query = build_query;
	nclass->init_from_query = init_from_query;
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "ManageNameIDRequest"); 
	lasso_node_class_set_ns(nclass, LASSO_SAML2_PROTOCOL_HREF, LASSO_SAML2_PROTOCOL_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_samlp2_manage_name_id_request_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlp2ManageNameIDRequestClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlp2ManageNameIDRequest),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_SAMLP2_REQUEST_ABSTRACT,
				"LassoSamlp2ManageNameIDRequest", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_samlp2_manage_name_id_request_new:
 *
 * Creates a new #LassoSamlp2ManageNameIDRequest object.
 *
 * Return value: a newly created #LassoSamlp2ManageNameIDRequest object
 **/
LassoNode*
lasso_samlp2_manage_name_id_request_new()
{
	return g_object_new(LASSO_TYPE_SAMLP2_MANAGE_NAME_ID_REQUEST, NULL);
}
