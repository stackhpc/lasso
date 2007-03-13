/* $Id: saml2_assertion.c,v 1.2 2005/11/21 18:51:52 fpeters Exp $ 
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


#include <xmlsec/xmldsig.h>
#include <xmlsec/templates.h>

#include "saml2_assertion.h"

/*
 * Schema fragment (saml-schema-assertion-2.0.xsd):
 *
 * <complexType name="AssertionType">
 *   <sequence>
 *     <element ref="saml:Issuer"/>
 *     <element ref="ds:Signature" minOccurs="0"/>
 *     <element ref="saml:Subject" minOccurs="0"/>
 *     <element ref="saml:Conditions" minOccurs="0"/>
 *     <element ref="saml:Advice" minOccurs="0"/>
 *     <choice minOccurs="0" maxOccurs="unbounded">
 *       <element ref="saml:Statement"/>
 *       <element ref="saml:AuthnStatement"/>
 *       <element ref="saml:AuthzDecisionStatement"/>
 *       <element ref="saml:AttributeStatement"/>
 *     </choice>
 *   </sequence>
 *   <attribute name="Version" type="string" use="required"/>
 *   <attribute name="ID" type="ID" use="required"/>
 *   <attribute name="IssueInstant" type="dateTime" use="required"/>
 * </complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "Issuer", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSaml2Assertion, Issuer),
		"LassoSaml2NameID" },
	{ "Subject", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSaml2Assertion, Subject) },
	{ "Conditions", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSaml2Assertion, Conditions) },
	{ "Advice", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSaml2Assertion, Advice) },
	{ "Statement", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSaml2Assertion, Statement) },
	{ "AuthnStatement", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSaml2Assertion, AuthnStatement) },
	{ "AuthzDecisionStatement", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSaml2Assertion, AuthzDecisionStatement) },
	{ "AttributeStatement", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSaml2Assertion, AttributeStatement) },
	{ "Version", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaml2Assertion, Version) },
	{ "ID", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaml2Assertion, ID) },
	{ "IssueInstant", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaml2Assertion, IssueInstant) },
	{ "Signature", SNIPPET_SIGNATURE,
		G_STRUCT_OFFSET(LassoSaml2Assertion, ID) },

	/* hidden fields; used in lasso dumps */
	{ "SignType", SNIPPET_ATTRIBUTE | SNIPPET_INTEGER | SNIPPET_LASSO_DUMP,
		G_STRUCT_OFFSET(LassoSaml2Assertion, sign_type) },
	{ "SignMethod", SNIPPET_ATTRIBUTE | SNIPPET_INTEGER | SNIPPET_LASSO_DUMP,
		G_STRUCT_OFFSET(LassoSaml2Assertion, sign_method) },
	{ "PrivateKeyFile", SNIPPET_CONTENT | SNIPPET_LASSO_DUMP,
		G_STRUCT_OFFSET(LassoSaml2Assertion, private_key_file) },
	{ "CertificateFile", SNIPPET_CONTENT | SNIPPET_LASSO_DUMP,
		G_STRUCT_OFFSET(LassoSaml2Assertion, certificate_file) },

	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;



static xmlNode*
get_xmlNode(LassoNode *node, gboolean lasso_dump)
{
	LassoSaml2Assertion *request = LASSO_SAML2_ASSERTION(node);
	xmlNode *xmlnode;
	int rc;
	
	xmlnode = parent_class->get_xmlNode(node, lasso_dump);

	if (lasso_dump == FALSE && request->sign_type) {
		rc = lasso_sign_node(xmlnode, "ID", request->ID,
				request->private_key_file, request->certificate_file);
		/* signature may have failed; what to do ? */
	}

	return xmlnode;
}


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSaml2Assertion *node)
{
	node->Issuer = NULL;
	node->Subject = NULL;
	node->Conditions = NULL;
	node->Advice = NULL;
	node->Statement = NULL;
	node->AuthnStatement = NULL;
	node->AuthzDecisionStatement = NULL;
	node->AttributeStatement = NULL;
	node->Version = NULL;
	node->ID = NULL;
	node->IssueInstant = NULL;
	node->sign_type = LASSO_SIGNATURE_TYPE_NONE;
}

static void
class_init(LassoSaml2AssertionClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->get_xmlNode = get_xmlNode;
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Assertion"); 
	lasso_node_class_set_ns(nclass, LASSO_SAML2_ASSERTION_HREF, LASSO_SAML2_ASSERTION_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);

	nclass->node_data->sign_type_offset = G_STRUCT_OFFSET(
			LassoSaml2Assertion, sign_type);
	nclass->node_data->sign_method_offset = G_STRUCT_OFFSET(
			LassoSaml2Assertion, sign_method);
}

GType
lasso_saml2_assertion_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSaml2AssertionClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSaml2Assertion),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSaml2Assertion", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_saml2_assertion_new:
 *
 * Creates a new #LassoSaml2Assertion object.
 *
 * Return value: a newly created #LassoSaml2Assertion object
 **/
LassoNode*
lasso_saml2_assertion_new()
{
	return g_object_new(LASSO_TYPE_SAML2_ASSERTION, NULL);
}