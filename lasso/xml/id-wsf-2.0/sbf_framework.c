/* $Id: sbf_framework.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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
#include "sbf_framework.h"
#include "idwsf2_strings.h"

/**
 * SECTION:sbf_framework
 * @short_description: &lt;sbf:Framework&gt;
 *
 * <figure><title>Schema fragment for sbf:Framework</title>
 * <programlisting><![CDATA[
 *
 * <xs:complexType name="FrameworkType">
 *   <xs:sequence>
 *     <xs:any namespace="##any" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
 *   </xs:sequence>
 *   <xs:attribute name="version" type="xs:string" use="required"/>
 *   <xs:anyAttribute namespace="##other" processContents="lax"/>
 * </xs:complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "version", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoIdWsf2SbfFramework, version), NULL, NULL, NULL},
	{ "attributes", SNIPPET_ATTRIBUTE | SNIPPET_ANY,
		G_STRUCT_OFFSET(LassoIdWsf2SbfFramework, attributes), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoIdWsf2SbfFramework *node)
{
	node->attributes = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
}

static void
class_init(LassoIdWsf2SbfFrameworkClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Framework");
	lasso_node_class_set_ns(nclass, LASSO_IDWSF2_SBF_HREF, LASSO_IDWSF2_SBF_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_idwsf2_sbf_framework_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIdWsf2SbfFrameworkClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIdWsf2SbfFramework),
			0,
			(GInstanceInitFunc) instance_init,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoIdWsf2SbfFramework", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_idwsf2_sbf_framework_new:
 *
 * Creates a new #LassoIdWsf2SbfFramework object.
 *
 * Return value: a newly created #LassoIdWsf2SbfFramework object
 **/
LassoIdWsf2SbfFramework*
lasso_idwsf2_sbf_framework_new()
{
	return g_object_new(LASSO_TYPE_IDWSF2_SBF_FRAMEWORK, NULL);
}

LassoIdWsf2SbfFramework*
lasso_idwsf2_sbf_framework_new_full(const char *version)
{
	LassoIdWsf2SbfFramework* framework;

	framework = g_object_new(LASSO_TYPE_IDWSF2_SBF_FRAMEWORK, NULL);

	framework->version = g_strdup(version);

	return framework;
}
