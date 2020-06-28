/* $Id: dstref_delete_item.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $ 
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

#include "dstref_delete_item.h"

/*
 * Schema fragment (liberty-idwsf-dst-ref-v2.1.xsd):
 *
 * <xs:complexType name="DeleteItemType">
 *   <xs:complexContent>
 *     <xs:extension base="dst:DeleteItemBaseType">
 *       <xs:sequence>
 *         <xs:element ref="dstref:Select" minOccurs="0" maxOccurs="1"/>
 *       </xs:sequence>
 *     </xs:extension>
 *   </xs:complexContent>
 * </xs:complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "Select", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoIdWsf2DstRefDeleteItem, Select) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoIdWsf2DstRefDeleteItem *node)
{
	node->Select = NULL;
}

static void
class_init(LassoIdWsf2DstRefDeleteItemClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "DeleteItem");
	lasso_node_class_set_ns(nclass, LASSO_IDWSF2_DSTREF_HREF, LASSO_IDWSF2_DSTREF_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_idwsf2_dstref_delete_item_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIdWsf2DstRefDeleteItemClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIdWsf2DstRefDeleteItem),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_IDWSF2_DST_DELETE_ITEM_BASE,
				"LassoIdWsf2DstRefDeleteItem", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_idwsf2_dstref_delete_item_new:
 *
 * Creates a new #LassoIdWsf2DstRefDeleteItem object.
 *
 * Return value: a newly created #LassoIdWsf2DstRefDeleteItem object
 **/
LassoIdWsf2DstRefDeleteItem*
lasso_idwsf2_dstref_delete_item_new()
{
	return g_object_new(LASSO_TYPE_IDWSF2_DSTREF_DELETE_ITEM, NULL);
}
