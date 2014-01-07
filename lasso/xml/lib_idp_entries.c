/* $Id$
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

#include "private.h"
#include "lib_idp_entries.h"

/**
 * SECTION:lib_idp_entries
 * @short_description: &lt;lib:IDPEntries&gt;
 *
 * <figure><title>Schema fragment for lib:IDPEntries</title>
 * <programlisting><![CDATA[
 * <xs:element name="IDPEntries">
 *   <xs:complexType>
 *     <xs:sequence>
 *       <xs:element ref="IDPEntry" maxOccurs="unbounded"/>
 *     </xs:sequence>
 *   </xs:complexType>
 * </xs:element>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "IDPEntry", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoLibIDPEntries, IDPEntry), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoLibIDPEntriesClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "IDPEntries");
	lasso_node_class_set_ns(nclass, LASSO_LIB_HREF, LASSO_LIB_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_lib_idp_entries_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoLibIDPEntriesClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoLibIDPEntries),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoLibIDPEntries", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_lib_idp_entries_new:
 *
 * Creates a new #LassoLibIDPEntries object.
 *
 * Return value: a newly created #LassoLibIDPEntries object
 **/
LassoNode*
lasso_lib_idp_entries_new()
{
	return g_object_new(LASSO_TYPE_LIB_IDP_ENTRIES, NULL);
}
