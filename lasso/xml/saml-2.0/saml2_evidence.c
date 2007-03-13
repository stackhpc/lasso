/* $Id: saml2_evidence.c,v 1.2 2005/11/21 18:51:52 fpeters Exp $ 
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

#include "saml2_evidence.h"

/*
 * Schema fragment (saml-schema-assertion-2.0.xsd):
 *
 * <complexType name="EvidenceType">
 *   <choice maxOccurs="unbounded">
 *     <element ref="saml:AssertionIDRef"/>
 *     <element ref="saml:AssertionURIRef"/>
 *     <element ref="saml:Assertion"/>
 *     <element ref="saml:EncryptedAssertion"/>
 *   </choice>
 * </complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "AssertionIDRef", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSaml2Evidence, AssertionIDRef) },
	{ "AssertionURIRef", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSaml2Evidence, AssertionURIRef) },
	{ "Assertion", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSaml2Evidence, Assertion) },
	{ "EncryptedAssertion", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSaml2Evidence, EncryptedAssertion) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSaml2Evidence *node)
{
	node->AssertionIDRef = NULL;
	node->AssertionURIRef = NULL;
	node->Assertion = NULL;
	node->EncryptedAssertion = NULL;
}

static void
class_init(LassoSaml2EvidenceClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Evidence"); 
	lasso_node_class_set_ns(nclass, LASSO_SAML2_ASSERTION_HREF, LASSO_SAML2_ASSERTION_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_saml2_evidence_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSaml2EvidenceClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSaml2Evidence),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSaml2Evidence", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_saml2_evidence_new:
 *
 * Creates a new #LassoSaml2Evidence object.
 *
 * Return value: a newly created #LassoSaml2Evidence object
 **/
LassoNode*
lasso_saml2_evidence_new()
{
	return g_object_new(LASSO_TYPE_SAML2_EVIDENCE, NULL);
}