/* $Id: disco_resource_id.c 3237 2007-05-30 17:17:45Z dlaniel $ 
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

#include <lasso/xml/disco_resource_id.h>

/*
 * Schema fragment (liberty-idwsf-disco-svc-1.0-errata-v1.0.xsd):
 * 
 * <xs:element name="ResourceID" type="ResourceIDType"/>
 * <xs:complexType name="ResourceIDType">
 *     <xs:simpleContent>
 *        <xs:extension base="xs:anyURI">
 *           <xs:attribute name="id" type="xs:ID" use="optional"/>
 *        </xs:extension>
 *     </xs:simpleContent>
 *  </xs:complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "id", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoDiscoResourceID, id) },
	{ "", SNIPPET_TEXT_CHILD, G_STRUCT_OFFSET(LassoDiscoResourceID, content) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoDiscoResourceID *node)
{
	node->id = NULL;
	node->content = NULL;
}

static void
class_init(LassoDiscoResourceIDClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "ResourceID");
	lasso_node_class_set_ns(nclass, LASSO_DISCO_HREF, LASSO_DISCO_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_disco_resource_id_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoDiscoResourceIDClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoDiscoResourceID),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoDiscoResourceID", &this_info, 0);
	}
	return this_type;
}

LassoDiscoResourceID*
lasso_disco_resource_id_new(const gchar *content)
{
	LassoDiscoResourceID *node;

	g_return_val_if_fail(content != NULL, NULL);

	node = g_object_new(LASSO_TYPE_DISCO_RESOURCE_ID, NULL);
	node->content = g_strdup(content);

	return node;
}
