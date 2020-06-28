/* $Id: wsse_reference.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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
#include "wsse_reference.h"
#include "../idwsf_strings.h"

/*
 * Schema fragment (oasis-200401-wss-wssecurity-secext-1.0.xsd):
 *
 * <xs:complexType name="ReferenceType">
 *   <xs:annotation>
 *     <xs:documentation>This type represents a reference to an external security
 *             token.</xs:documentation>
 *     </xs:annotation>
 *     <xs:attribute name="URI" type="xs:anyURI"/>
 *     <xs:attribute name="ValueType" type="xs:anyURI"/>
 *     <xs:anyAttribute namespace="##other" processContents="lax"/>
 *   </xs:complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "URI", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoWsSec1Reference, URI), NULL, NULL, NULL},
	{ "ValueType", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoWsSec1Reference, ValueType), NULL, NULL, NULL},
	{ "attributes", SNIPPET_ATTRIBUTE | SNIPPET_ANY,
		G_STRUCT_OFFSET(LassoWsSec1Reference, attributes), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoWsSec1Reference *node)
{
	node->attributes = g_hash_table_new_full(
		g_str_hash, g_str_equal, g_free, g_free);
}

static void
class_init(LassoWsSec1ReferenceClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Reference");
	lasso_node_class_set_ns(nclass, LASSO_WSSE1_HREF, LASSO_WSSE1_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_wsse_reference_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoWsSec1ReferenceClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoWsSec1Reference),
			0,
			(GInstanceInitFunc) instance_init,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoWsSec1Reference", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_wsse_reference_new:
 *
 * Creates a new #LassoWsSec1Reference object.
 *
 * Return value: a newly created #LassoWsSec1Reference object
 **/
LassoWsSec1Reference*
lasso_wsse_reference_new()
{
	return g_object_new(LASSO_TYPE_WSSE_REFERENCE, NULL);
}
