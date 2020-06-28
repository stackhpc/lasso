/* $Id: dstref_create_item.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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
#include "dstref_create_item.h"
#include "idwsf2_strings.h"

/**
 * SECTION:dstref_create_item
 * @short_description: &lt;dstref:CreateItem&gt;
 *
 * <figure><title>Schema fragment for dstref:CreateItem</title>
 * <programlisting><![CDATA[
 *
 * <xs:complexType name="CreateItemType">
 *   <xs:sequence>
 *     <xs:element ref="dstref:NewData" minOccurs="0" maxOccurs="1"/>
 *   </xs:sequence>
 *   <xs:attributeGroup ref="dst:CreateItemAttributeGroup"/>
 * </xs:complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "NewData", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoIdWsf2DstRefCreateItem, NewData),
		"LassoIdWsf2DstRefAppData", NULL, NULL },
	{ "objectType", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoIdWsf2DstRefCreateItem, objectType), NULL, NULL, NULL},
	{ "id", SNIPPET_ATTRIBUTE | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2DstRefCreateItem, id), NULL, NULL, NULL},
	{ "itemID", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoIdWsf2DstRefCreateItem, itemID), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoIdWsf2DstRefCreateItemClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "CreateItem");
	lasso_node_class_set_ns(nclass, LASSO_IDWSF2_DSTREF_HREF, LASSO_IDWSF2_DSTREF_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_idwsf2_dstref_create_item_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIdWsf2DstRefCreateItemClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIdWsf2DstRefCreateItem),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoIdWsf2DstRefCreateItem", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_idwsf2_dstref_create_item_new:
 *
 * Creates a new #LassoIdWsf2DstRefCreateItem object.
 *
 * Return value: a newly created #LassoIdWsf2DstRefCreateItem object
 **/
LassoIdWsf2DstRefCreateItem*
lasso_idwsf2_dstref_create_item_new()
{
	return g_object_new(LASSO_TYPE_IDWSF2_DSTREF_CREATE_ITEM, NULL);
}
