/* $Id: is_help.c,v 1.2 2005/01/22 15:57:55 eraviart Exp $ 
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

#include <lasso/xml/is_help.h>

/*
 * Schema fragments (liberty-idwsf-interaction-svc-v1.0.xsd):
 *
 * <xs:element name="Help" type="HelpType"/>
 * <xs:complexType name="HelpType">
 *   <xs:attribute name="label" type="xs:string" use="optional"/>
 *   <xs:attribute name="link" type="xs:anyURI" use="optional"/>
 *   <xs:attribute name="moreLink" type="xs:anyURI" use="optional"/>
 * </xs:complexType>
 */ 

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "label", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoIsHelp, label) },
	{ "link", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoIsHelp, link) },
	{ "moreLink", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoIsHelp, moreLink) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoIsHelp *node)
{
	node->label = NULL;
	node->link = NULL;
	node->moreLink = NULL;
}

static void
class_init(LassoIsHelpClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Help");
	lasso_node_class_set_ns(nclass, LASSO_IS_HREF, LASSO_IS_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_is_help_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIsHelpClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIsHelp),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoIsHelp", &this_info, 0);
	}
	return this_type;
}

LassoIsHelp*
lasso_is_help_new()
{
	LassoIsHelp *node;

	node = g_object_new(LASSO_TYPE_IS_HELP, NULL);

	return node;
}