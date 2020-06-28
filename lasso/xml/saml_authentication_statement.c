/* $Id: saml_authentication_statement.c 3237 2007-05-30 17:17:45Z dlaniel $
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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <lasso/xml/saml_authentication_statement.h>

/*
 * Schema fragment (oasis-sstc-saml-schema-assertion-1.0.xsd):
 * 
 * <element name="AuthenticationStatement" type="saml:AuthenticationStatementType"/>
 * <complexType name="AuthenticationStatementType">
 *   <complexContent>
 *     <extension base="saml:SubjectStatementAbstractType">
 *       <sequence>
 *         <element ref="saml:SubjectLocality" minOccurs="0"/>
 *         <element ref="saml:AuthorityBinding" minOccurs="0" maxOccurs="unbounded"/>
 *       </sequence>
 *       <attribute name="AuthenticationMethod" type="anyURI" use="required"/>
 *       <attribute name="AuthenticationInstant" type="dateTime" use="required"/>
 *     </extension>
 *   </complexContent>
 * </complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "SubjectLocality", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlAuthenticationStatement, SubjectLocality) },
	{ "AuthorityBinding", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoSamlAuthenticationStatement, AuthorityBinding) },
	{ "AuthenticationMethod", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSamlAuthenticationStatement, AuthenticationMethod) },
	{ "AuthenticationInstant", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSamlAuthenticationStatement, AuthenticationInstant) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSamlAuthenticationStatement *node)
{
	node->SubjectLocality = NULL;
	node->AuthorityBinding = NULL;
	node->AuthenticationMethod = NULL;
	node->AuthenticationInstant = NULL;
}

static void
class_init(LassoSamlAuthenticationStatementClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "AuthenticationStatement");
	lasso_node_class_set_ns(nclass, LASSO_SAML_ASSERTION_HREF, LASSO_SAML_ASSERTION_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_saml_authentication_statement_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlAuthenticationStatementClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlAuthenticationStatement),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_SAML_SUBJECT_STATEMENT_ABSTRACT,
				"LassoSamlAuthenticationStatement", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_saml_authentication_statement_new:
 *
 * Creates a new #LassoSamlAuthenticationStatement object.
 * 
 * Return value: a newly created #LassoSamlAuthenticationStatement object
 **/
LassoNode*
lasso_saml_authentication_statement_new()
{
	return g_object_new(LASSO_TYPE_SAML_AUTHENTICATION_STATEMENT, NULL);
}
