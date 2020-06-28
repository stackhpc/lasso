/* $Id: dstref_data.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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
#include "dstref_data.h"
#include "idwsf2_strings.h"

/**
 * SECTION:dstref_data
 * @short_description: &lt;dstref:Data&gt;
 *
 * <figure><title>Schema fragment for dstref:Data</title>
 * <programlisting><![CDATA[
 *
 * <xs:complexType name="DataType">
 *   <xs:complexContent>
 *     <xs:extension base="dstref:ItemDataType">
 *       <xs:attributeGroup ref="dst:PaginationResponseAttributeGroup"/>
 *     </xs:extension>
 *   </xs:complexContent>
 * </xs:complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "remaining", SNIPPET_ATTRIBUTE | SNIPPET_INTEGER | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2DstRefData, remaining), NULL, NULL, NULL},
	{ "nextOffset", SNIPPET_ATTRIBUTE | SNIPPET_INTEGER | SNIPPET_OPTIONAL_NEG,
		G_STRUCT_OFFSET(LassoIdWsf2DstRefData, nextOffset), NULL, NULL, NULL},
	{ "setID", SNIPPET_ATTRIBUTE | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2DstRefData, setID), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoIdWsf2DstRefData *node)
{
	node->nextOffset = -1;
}

static void
class_init(LassoIdWsf2DstRefDataClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Data");
	lasso_node_class_set_ns(nclass, LASSO_IDWSF2_DSTREF_HREF, LASSO_IDWSF2_DSTREF_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_idwsf2_dstref_data_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIdWsf2DstRefDataClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIdWsf2DstRefData),
			0,
			(GInstanceInitFunc) instance_init,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_IDWSF2_DSTREF_ITEM_DATA,
				"LassoIdWsf2DstRefData", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_idwsf2_dstref_data_new:
 *
 * Creates a new #LassoIdWsf2DstRefData object.
 *
 * Return value: a newly created #LassoIdWsf2DstRefData object
 **/
LassoIdWsf2DstRefData*
lasso_idwsf2_dstref_data_new()
{
	return g_object_new(LASSO_TYPE_IDWSF2_DSTREF_DATA, NULL);
}
