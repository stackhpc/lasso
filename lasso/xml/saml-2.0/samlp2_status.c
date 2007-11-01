/* $Id: samlp2_status.c 3237 2007-05-30 17:17:45Z dlaniel $ 
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

#include "samlp2_status.h"

/*
 * Schema fragment (saml-schema-protocol-2.0.xsd):
 *
 * <complexType name="StatusType">
 *   <sequence>
 *     <element ref="samlp:StatusCode"/>
 *     <element ref="samlp:StatusMessage" minOccurs="0"/>
 *     <element ref="samlp:StatusDetail" minOccurs="0"/>
 *   </sequence>
 * </complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "StatusCode", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlp2Status, StatusCode) },
	{ "StatusMessage", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoSamlp2Status, StatusMessage) },
	{ "StatusDetail", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlp2Status, StatusDetail) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSamlp2Status *node)
{
	node->StatusCode = NULL;
	node->StatusMessage = NULL;
	node->StatusDetail = NULL;
}

static void
class_init(LassoSamlp2StatusClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Status"); 
	lasso_node_class_set_ns(nclass, LASSO_SAML2_PROTOCOL_HREF, LASSO_SAML2_PROTOCOL_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_samlp2_status_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlp2StatusClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlp2Status),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSamlp2Status", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_samlp2_status_new:
 *
 * Creates a new #LassoSamlp2Status object.
 *
 * Return value: a newly created #LassoSamlp2Status object
 **/
LassoNode*
lasso_samlp2_status_new()
{
	return g_object_new(LASSO_TYPE_SAMLP2_STATUS, NULL);
}
