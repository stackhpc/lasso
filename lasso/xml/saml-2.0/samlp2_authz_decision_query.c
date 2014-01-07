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
#include "samlp2_authz_decision_query.h"

/**
 * SECTION:samlp2_authz_decision_query
 * @short_description: &lt;samlp2:AuthzDecisionQuery&gt;
 *
 * <figure><title>Schema fragment for samlp2:AuthzDecisionQuery</title>
 * <programlisting><![CDATA[
 *
 * <complexType name="AuthzDecisionQueryType">
 *   <complexContent>
 *     <extension base="samlp:SubjectQueryAbstractType">
 *       <sequence>
 *         <element ref="saml:Action" maxOccurs="unbounded"/>
 *         <element ref="saml:Evidence" minOccurs="0"/>
 *       </sequence>
 *       <attribute name="Resource" type="anyURI" use="required"/>
 *     </extension>
 *   </complexContent>
 * </complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "Action", SNIPPET_NODE, G_STRUCT_OFFSET(LassoSamlp2AuthzDecisionQuery, Action), NULL,
		LASSO_SAML2_ASSERTION_PREFIX, LASSO_SAML2_ASSERTION_HREF},
	{ "Evidence", SNIPPET_NODE, G_STRUCT_OFFSET(LassoSamlp2AuthzDecisionQuery, Evidence), NULL,
		LASSO_SAML2_ASSERTION_PREFIX, LASSO_SAML2_ASSERTION_HREF},
	{ "Resource", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSamlp2AuthzDecisionQuery, Resource), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoSamlp2AuthzDecisionQueryClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "AuthzDecisionQuery");
	lasso_node_class_set_ns(nclass, LASSO_SAML2_PROTOCOL_HREF, LASSO_SAML2_PROTOCOL_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_samlp2_authz_decision_query_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlp2AuthzDecisionQueryClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlp2AuthzDecisionQuery),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_SAMLP2_SUBJECT_QUERY_ABSTRACT,
				"LassoSamlp2AuthzDecisionQuery", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_samlp2_authz_decision_query_new:
 *
 * Creates a new #LassoSamlp2AuthzDecisionQuery object.
 *
 * Return value: a newly created #LassoSamlp2AuthzDecisionQuery object
 **/
LassoNode*
lasso_samlp2_authz_decision_query_new()
{
	return g_object_new(LASSO_TYPE_SAMLP2_AUTHZ_DECISION_QUERY, NULL);
}
