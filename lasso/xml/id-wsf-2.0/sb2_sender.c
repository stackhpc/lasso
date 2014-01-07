/* $Id: sb2_sender.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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
#include "sb2_sender.h"
#include "idwsf2_strings.h"

/**
 * SECTION:sb2_sender
 * @short_description: &lt;sb2:Sender&gt;
 *
 * <figure><title>Schema fragment for sb2:Sender</title>
 * <programlisting><![CDATA[
 *
 * <xs:complexType name="SenderType">
 *   <xs:attribute name="providerID" type="xs:anyURI" use="required"/>
 *   <xs:attribute name="affiliationID" type="xs:anyURI" use="optional"/>
 *   <xs:anyAttribute namespace="##other" processContents="lax"/>
 * </xs:complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "providerID", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoIdWsf2Sb2Sender, providerID), NULL, NULL, NULL},
	{ "affiliationID", SNIPPET_ATTRIBUTE | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2Sb2Sender, affiliationID), NULL, NULL, NULL},
	{ "attributes", SNIPPET_ATTRIBUTE | SNIPPET_ANY,
		G_STRUCT_OFFSET(LassoIdWsf2Sb2Sender, attributes), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoIdWsf2Sb2Sender *node)
{
	node->attributes = g_hash_table_new_full(
		g_str_hash, g_str_equal, g_free, g_free);
}

static void
class_init(LassoIdWsf2Sb2SenderClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Sender");
	lasso_node_class_set_ns(nclass, LASSO_IDWSF2_SB2_HREF, LASSO_IDWSF2_SB2_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_idwsf2_sb2_sender_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIdWsf2Sb2SenderClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIdWsf2Sb2Sender),
			0,
			(GInstanceInitFunc) instance_init,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoIdWsf2Sb2Sender", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_idwsf2_sb2_sender_new:
 *
 * Creates a new #LassoIdWsf2Sb2Sender object.
 *
 * Return value: a newly created #LassoIdWsf2Sb2Sender object
 **/
LassoIdWsf2Sb2Sender*
lasso_idwsf2_sb2_sender_new()
{
	return g_object_new(LASSO_TYPE_IDWSF2_SB2_SENDER, NULL);
}
