/* $Id: wsa_problem_action.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "../private.h"
#include "wsa_problem_action.h"
#include "../idwsf_strings.h"

/*
 * Schema fragment (ws-addr.xsd):
 *
 * <xs:complexType name="ProblemActionType" mixed="false">
 *   <xs:sequence>
 *     <xs:element ref="tns:Action" minOccurs="0"/>
 *     <xs:element name="SoapAction" minOccurs="0" type="xs:anyURI"/>
 *   </xs:sequence>
 *   <xs:anyAttribute namespace="##other" processContents="lax"/>
 * </xs:complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "Action", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoWsAddrProblemAction, Action),
		"LassoWsAddrAttributedURI", NULL, NULL },
	{ "SoapAction", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoWsAddrProblemAction, SoapAction), NULL, NULL, NULL},
	{ "attributes", SNIPPET_ATTRIBUTE | SNIPPET_ANY,
		G_STRUCT_OFFSET(LassoWsAddrProblemAction, attributes), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoWsAddrProblemAction *node)
{
	node->attributes = g_hash_table_new_full(
		g_str_hash, g_str_equal, g_free, g_free);
}

static void
class_init(LassoWsAddrProblemActionClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "ProblemAction");
	lasso_node_class_set_ns(nclass, LASSO_WSA_HREF, LASSO_WSA_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_wsa_problem_action_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoWsAddrProblemActionClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoWsAddrProblemAction),
			0,
			(GInstanceInitFunc) instance_init,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoWsAddrProblemAction", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_wsa_problem_action_new:
 *
 * Creates a new #LassoWsAddrProblemAction object.
 *
 * Return value: a newly created #LassoWsAddrProblemAction object
 **/
LassoWsAddrProblemAction*
lasso_wsa_problem_action_new()
{
	return g_object_new(LASSO_TYPE_WSA_PROBLEM_ACTION, NULL);
}
