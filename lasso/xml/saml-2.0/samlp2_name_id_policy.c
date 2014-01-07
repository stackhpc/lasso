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

#include "../private.h"
#include "samlp2_name_id_policy.h"

/**
 * SECTION:samlp2_name_id_policy
 * @short_description: &lt;samlp2:NameIDPolicy&gt;
 *
 * <figure><title>Schema fragment for samlp2:NameIDPolicy</title>
 * <programlisting><![CDATA[
 *
 * <complexType name="NameIDPolicyType">
 *   <attribute name="Format" type="anyURI" use="optional"/>
 *   <attribute name="SPNameQualifier" type="string" use="optional"/>
 *   <attribute name="AllowCreate" type="boolean" use="optional"/>
 * </complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "Format", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSamlp2NameIDPolicy, Format), NULL, NULL, NULL},
	{ "SPNameQualifier", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSamlp2NameIDPolicy, SPNameQualifier), NULL, NULL, NULL},
	{ "AllowCreate", SNIPPET_ATTRIBUTE | SNIPPET_BOOLEAN,
		G_STRUCT_OFFSET(LassoSamlp2NameIDPolicy, AllowCreate), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoSamlp2NameIDPolicyClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "NameIDPolicy");
	lasso_node_class_set_ns(nclass, LASSO_SAML2_PROTOCOL_HREF, LASSO_SAML2_PROTOCOL_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_samlp2_name_id_policy_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlp2NameIDPolicyClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlp2NameIDPolicy),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSamlp2NameIDPolicy", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_samlp2_name_id_policy_new:
 *
 * Creates a new #LassoSamlp2NameIDPolicy object.
 *
 * Return value: a newly created #LassoSamlp2NameIDPolicy object
 **/
LassoNode*
lasso_samlp2_name_id_policy_new()
{
	return g_object_new(LASSO_TYPE_SAMLP2_NAME_ID_POLICY, NULL);
}
