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
#include "saml_advice.h"
#include "saml_assertion.h"

/**
 * SECTION:saml_advice
 * @short_description: &lt;saml:Advice&gt;
 *
 * <figure><title>Schema fragment for saml:Advice</title>
 * <programlisting><![CDATA[
 * <element name="Advice" type="saml:AdviceType"/>
 * <complexType name="AdviceType">
 *   <choice minOccurs="0" maxOccurs="unbounded">
 *     <element ref="saml:AssertionIDReference"/>
 *     <element ref="saml:Assertion"/>
 *     <any namespace="##other" processContents="lax"/>
 *   </choice>
 * </complexType>
 *
 * <element name="AssertionIDReference" type="saml:IDReferenceType"/>
 * <simpleType name="IDReferenceType">
 *   <restriction base="string"/>
 * </simpleType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods	                                                   */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "AssertionIDReference", SNIPPET_LIST_CONTENT,
		G_STRUCT_OFFSET(LassoSamlAdvice, AssertionIDReference), NULL, NULL, NULL},
	{ "Assertion", SNIPPET_NODE | SNIPPET_JUMP_ON_MATCH | SNIPPET_BACK_1, G_STRUCT_OFFSET(LassoSamlAdvice, Assertion), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

/*****************************************************************************/
/* instance and class init functions	                                 */
/*****************************************************************************/


static void
class_init(LassoSamlAdviceClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Advice");
	lasso_node_class_set_ns(nclass, LASSO_SAML_ASSERTION_HREF, LASSO_SAML_ASSERTION_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_saml_advice_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlAdviceClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlAdvice),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSamlAdvice", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_saml_advice_new:
 *
 * Creates a new #LassoSamlAdvice object.
 *
 * Return value: a newly created #LassoSamlAdvice
 **/
LassoNode*
lasso_saml_advice_new()
{
	return g_object_new(LASSO_TYPE_SAML_ADVICE, NULL);
}
