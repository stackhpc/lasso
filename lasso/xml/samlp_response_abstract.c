/* $Id: samlp_response_abstract.c,v 1.31 2005/01/22 15:57:55 eraviart Exp $ 
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

#include <lasso/xml/samlp_response_abstract.h>

/*
 * Schema fragment (oasis-sstc-saml-schema-protocol-1.0.xsd):
 * 
 * <complexType name="ResponseAbstractType" abstract="true">
 *   <sequence>
 *      <element ref="ds:Signature" minOccurs="0"/>
 *   </sequence>
 *   <attribute name="ResponseID" type="saml:IDType" use="required"/>
 *   <attribute name="InResponseTo" type="saml:IDReferenceType" use="optional"/>
 *   <attribute name="MajorVersion" type="integer" use="required"/>
 *   <attribute name="MinorVersion" type="integer" use="required"/>
 *   <attribute name="IssueInstant" type="dateTime" use="required"/>
 *   <attribute name="Recipient" type="anyURI" use="optional"/>
 * </complexType>
 * 
 * From oasis-sstc-saml-schema-assertion-1.0.xsd:
 * <simpleType name="IDType">
 *   <restriction base="string"/>
 * </simpleType>
 * <simpleType name="IDReferenceType">
 *   <restriction base="string"/>
 * </simpleType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Signature", SNIPPET_SIGNATURE,
		G_STRUCT_OFFSET(LassoSamlpResponseAbstract, ResponseID) },
	{ "ResponseID", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSamlpResponseAbstract, ResponseID) },
	{ "MajorVersion", SNIPPET_ATTRIBUTE | SNIPPET_INTEGER,
		G_STRUCT_OFFSET(LassoSamlpResponseAbstract, MajorVersion) },
	{ "MinorVersion", SNIPPET_ATTRIBUTE | SNIPPET_INTEGER,
		G_STRUCT_OFFSET(LassoSamlpResponseAbstract, MinorVersion) },
	{ "IssueInstant", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSamlpResponseAbstract, IssueInstant) },
	{ "InResponseTo", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSamlpResponseAbstract, InResponseTo) },
	{ "Recipient", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoSamlpResponseAbstract, Recipient) },
	{ NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;

static xmlNode*
get_xmlNode(LassoNode *node, gboolean lasso_dump)
{
	LassoSamlpResponseAbstract *response = LASSO_SAMLP_RESPONSE_ABSTRACT(node);
	xmlNode *xmlnode;
	int rc;
	
	xmlnode = parent_class->get_xmlNode(node, lasso_dump);

	if (lasso_dump == FALSE && response->sign_type) {
		rc = lasso_sign_node(xmlnode, "ResponseID", response->ResponseID,
				response->private_key_file, response->certificate_file);
		/* signature may have failed; what to do ? */
	}

	return xmlnode;
}

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSamlpResponseAbstract *node)
{
	node->ResponseID = NULL;
	node->MajorVersion = 0;
	node->MinorVersion = 0;
	node->IssueInstant = NULL;
	node->InResponseTo = NULL;
	node->Recipient = NULL;
	node->sign_type = LASSO_SIGNATURE_TYPE_NONE;
}

static void
class_init(LassoSamlpResponseAbstractClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->get_xmlNode = get_xmlNode;
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "ResponseAbstract");
	lasso_node_class_set_ns(nclass, LASSO_SAML_PROTOCOL_HREF, LASSO_SAML_PROTOCOL_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
	nclass->node_data->sign_type_offset = G_STRUCT_OFFSET(
			LassoSamlpResponseAbstract, sign_type);
	nclass->node_data->sign_method_offset = G_STRUCT_OFFSET(
			LassoSamlpResponseAbstract, sign_method);
}

GType
lasso_samlp_response_abstract_get_type()
{
	static GType response_abstract_type = 0;

	if (!response_abstract_type) {
		static const GTypeInfo response_abstract_info = {
			sizeof (LassoSamlpResponseAbstractClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlpResponseAbstract),
			0,
			(GInstanceInitFunc) instance_init,
		};

		response_abstract_type = g_type_register_static(LASSO_TYPE_NODE ,
				"LassoSamlpResponseAbstract",
				&response_abstract_info, 0);
	}
	return response_abstract_type;
}

void
lasso_samlp_response_abstract_fill(LassoSamlpResponseAbstract *response,
		const char *InResponseTo, const char *Recipient)
{
	response->ResponseID = lasso_build_unique_id(32);
	response->MajorVersion = LASSO_LIB_MAJOR_VERSION_N;
	response->MinorVersion = LASSO_LIB_MINOR_VERSION_N;
	response->IssueInstant = lasso_get_current_time();
	response->InResponseTo = g_strdup(InResponseTo);
	response->Recipient = g_strdup(Recipient);
}
