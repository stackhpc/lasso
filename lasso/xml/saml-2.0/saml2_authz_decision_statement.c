/* $Id: saml2_authz_decision_statement.c,v 1.2 2005/11/21 18:51:52 fpeters Exp $ 
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

#include "saml2_authz_decision_statement.h"

/*
 * Schema fragment (saml-schema-assertion-2.0.xsd):
 *
 * <complexType name="AuthzDecisionStatementType">
 *   <complexContent>
 *     <extension base="saml:StatementAbstractType">
 *       <sequence>
 *         <element ref="saml:Action" maxOccurs="unbounded"/>
 *         <element ref="saml:Evidence" minOccurs="0"/>
 *       </sequence>
 *       <attribute name="Resource" type="anyURI" use="required"/>
 *       <attribute name="Decision" type="saml:DecisionType" use="required"/>
 *     </extension>
 *   </complexContent>
 * </complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "Action", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSaml2AuthzDecisionStatement, Action) },
	{ "Evidence", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSaml2AuthzDecisionStatement, Evidence) },
	{ "Resource", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaml2AuthzDecisionStatement, Resource) },
	{ "Decision", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaml2AuthzDecisionStatement, Decision) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSaml2AuthzDecisionStatement *node)
{
	node->Action = NULL;
	node->Evidence = NULL;
	node->Resource = NULL;
}

static void
class_init(LassoSaml2AuthzDecisionStatementClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "AuthzDecisionStatement"); 
	lasso_node_class_set_ns(nclass, LASSO_SAML2_ASSERTION_HREF, LASSO_SAML2_ASSERTION_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_saml2_authz_decision_statement_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSaml2AuthzDecisionStatementClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSaml2AuthzDecisionStatement),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_SAML2_STATEMENT_ABSTRACT,
				"LassoSaml2AuthzDecisionStatement", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_saml2_authz_decision_statement_new:
 *
 * Creates a new #LassoSaml2AuthzDecisionStatement object.
 *
 * Return value: a newly created #LassoSaml2AuthzDecisionStatement object
 **/
LassoNode*
lasso_saml2_authz_decision_statement_new()
{
	return g_object_new(LASSO_TYPE_SAML2_AUTHZ_DECISION_STATEMENT, NULL);
}
