/* $Id: lib_idp_entry.c,v 1.16 2005/01/22 15:57:55 eraviart Exp $
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

#include <lasso/xml/lib_idp_entry.h>

/*
 * Schema fragment (liberty-idff-protocols-schema-v1.2.xsd):
 * 
 * <xs:element name="IDPEntry">
 *   <xs:complexType>
 *     <xs:sequence>
 *       <xs:element ref="ProviderID"/>
 *       <xs:element name="ProviderName" type="xs:string" minOccurs="0"/>
 *       <xs:element name="Loc" type="xs:anyURI"/>
 *     </xs:sequence>
 *   </xs:complexType>
 * </xs:element>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "ProviderID", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoLibIDPEntry, ProviderID) },
	{ "ProviderName", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoLibIDPEntry, ProviderName) },
	{ "Loc", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoLibIDPEntry, Loc) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoLibIDPEntry *node)
{
	node->ProviderID = NULL;
	node->ProviderName = NULL;
	node->Loc = NULL;
}

static void
class_init(LassoLibIDPEntryClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "IDPEntry");
	lasso_node_class_set_ns(nclass, LASSO_LIB_HREF, LASSO_LIB_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_lib_idp_entry_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoLibIDPEntryClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoLibIDPEntry),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoLibIDPEntry", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_lib_idp_entry_new:
 *
 * Creates a new #LassoLibIDPEntry object.
 * 
 * Return value: a newly created @LassoLibIDPEntry object
 **/
LassoNode*
lasso_lib_idp_entry_new()
{
	return g_object_new(LASSO_TYPE_LIB_IDP_ENTRY, NULL);
}

