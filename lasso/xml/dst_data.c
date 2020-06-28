/* $Id: dst_data.c,v 1.6 2005/01/27 23:41:05 eraviart Exp $ 
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

#include <lasso/xml/dst_data.h>

/*
 * Schema fragments (liberty-idwsf-dst-v1.0.xsd):
 * 
 * <xs:element name="Data" minOccurs="0" maxOccurs="unbounded">
 *   <xs:complexType>
 *     <xs:sequence>
 *       <xs:any minOccurs="0" maxOccurs="unbounded"/>
 *     </xs:sequence>
 *     <xs:attribute name="id" type="xs:ID"/>
 *     <xs:attribute name="itemIDRef" type="IDReferenceType"/>
 *   </xs:complexType>
 * </xs:element>
 *
 * Schema fragment (liberty-idwsf-utility-1.0-errata-v1.0.xsd)
 *
 * <xs:simpleType name="IDReferenceType">
 *   <xs:annotation>
 *     <xs:documentation> This type can be used when referring to elements that are
 *       identified using an IDType </xs:documentation>
 *     </xs:annotation>
 *   <xs:restriction base="xs:string"/>
 * </xs:simpleType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "", SNIPPET_LIST_XMLNODES, G_STRUCT_OFFSET(LassoDstData, any) },
	{ "id", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoDstData, id) },
	{ "itemIDRef", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoDstData, itemIDRef) },
	{ NULL, 0, 0}
};


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoDstData *node)
{
	node->any = NULL;
	node->id = NULL;
	node->itemIDRef = NULL;
}

static void
class_init(LassoDstDataClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Data");
	/* no namespace */
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_dst_data_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoDstDataClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoDstData),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoDstData", &this_info, 0);
	}
	return this_type;
}

LassoDstData*
lasso_dst_data_new()
{
	LassoDstData *data;

	data = g_object_new(LASSO_TYPE_DST_DATA, NULL);

	return data;
}
