/* $Id: dst_modification.c 3237 2007-05-30 17:17:45Z dlaniel $ 
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

#include <lasso/xml/dst_modification.h>

/*
 * Schema fragment (liberty-idwsf-dst-v1.0.xsd):
 *
 * <xs:element name="Modification" maxOccurs="unbounded">
 * <xs:complexType>
 *     <xs:sequence>
 *         <xs:element name="Select" type="SelectType"/>
 *         <xs:element name="NewData" minOccurs="0">
 *             <xs:complexType>
 *                 <xs:sequence>
 *                     <xs:any minOccurs="0" maxOccurs="unbounded"/>
 *                 </xs:sequence>
 *             </xs:complexType>
 *         </xs:element>
 *     </xs:sequence>
 *     <xs:attribute name="id" type="xs:ID"/>
 *     <xs:attribute name="notChangedSince" type="xs:dateTime"/>
 *     <xs:attribute name="overrideAllowed" type="xs:boolean" default="0"/>
 * </xs:complexType>
 * </xs:element>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Select", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoDstModification, Select) },
	{ "NewData", SNIPPET_NODE, G_STRUCT_OFFSET(LassoDstModification, NewData) },
	{ "id", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoDstModification, id) },
	{ "notChangedSince", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoDstModification,
								notChangedSince) },
	{ "overrideAllowed", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoDstModification,
								overrideAllowed) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoDstModification *node)
{
	node->Select = NULL;
	node->NewData = NULL;
	node->id = NULL;
	node->notChangedSince = NULL;
	node->overrideAllowed = FALSE;
}

static void
class_init(LassoDstModificationClass *klass)
{
	LassoNodeClass *nodeClass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nodeClass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nodeClass, "Modification");
	lasso_node_class_add_snippets(nodeClass, schema_snippets);
}

GType
lasso_dst_modification_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoDstModificationClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoDstModification),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoDstModification", &this_info, 0);
	}
	return this_type;
}

LassoDstModification*
lasso_dst_modification_new(const char *select)
{
	LassoDstModification *modification;

	g_return_val_if_fail(select != NULL, NULL);

	modification = g_object_new(LASSO_TYPE_DST_MODIFICATION, NULL);

	modification->Select = g_strdup(select);

	return modification;
}

