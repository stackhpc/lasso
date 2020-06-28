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
#include "saml2_advice.h"

/**
 * SECTION:saml2_advice
 * @short_description: &lt;saml2:Advice&gt;
 *
 * <figure><title>Schema fragment for saml2:Advice</title>
 * <programlisting><![CDATA[
 *
 * <complexType name="AdviceType">
 *   <choice minOccurs="0" maxOccurs="unbounded">
 *     <element ref="saml:AssertionIDRef"/>
 *     <element ref="saml:AssertionURIRef"/>
 *     <element ref="saml:Assertion"/>
 *     <element ref="saml:EncryptedAssertion"/>
 *     <any namespace="##other" processContents="lax"/>
 *   </choice>
 * </complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "AssertionIDRef", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSaml2Advice, AssertionIDRef), NULL, NULL, NULL},
	{ "AssertionURIRef", SNIPPET_LIST_NODES | SNIPPET_JUMP_ON_MATCH | SNIPPET_BACK_1,
		G_STRUCT_OFFSET(LassoSaml2Advice, AssertionURIRef), NULL, NULL, NULL},
	{ "Assertion", SNIPPET_LIST_NODES | SNIPPET_JUMP_ON_MATCH | SNIPPET_BACK_2,
		G_STRUCT_OFFSET(LassoSaml2Advice, Assertion), NULL, NULL, NULL},
	{ "EncryptedAssertion", SNIPPET_LIST_NODES | SNIPPET_JUMP_ON_MATCH | SNIPPET_BACK_3,
		G_STRUCT_OFFSET(LassoSaml2Advice, EncryptedAssertion), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoSaml2AdviceClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Advice");
	lasso_node_class_set_ns(nclass, LASSO_SAML2_ASSERTION_HREF, LASSO_SAML2_ASSERTION_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_saml2_advice_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSaml2AdviceClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSaml2Advice),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSaml2Advice", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_saml2_advice_new:
 *
 * Creates a new #LassoSaml2Advice object.
 *
 * Return value: a newly created #LassoSaml2Advice object
 **/
LassoNode*
lasso_saml2_advice_new()
{
	return g_object_new(LASSO_TYPE_SAML2_ADVICE, NULL);
}
