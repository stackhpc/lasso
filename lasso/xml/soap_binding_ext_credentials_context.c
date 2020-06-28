/* $Id: soap_binding_ext_credentials_context.c 3704 2008-05-15 21:17:44Z fpeters $ 
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

#include <lasso/xml/soap_binding_ext_credentials_context.h>

/**
 * SECTION:soap_binding_ext_credentials_context
 * @short_description: &lt;soapbinding:CredentialsContextType&gt;
 *
 * <figure><title>Schema fragment for soapbinding:CredentialsContextType</title>
 * <programlisting><![CDATA[
 *
 * <xs:complexType name="CredentialsContextType">
 *   <xs:sequence>
 *     <xs:element ref="lib:RequestAuthnContext" minOccurs="0"/>
 *     <xs:element name="SecurityMechID" type="xs: anyURI" minOccurs="0" maxOccurs="unbounded"/>
 *   </xs:sequence>
 *   <xs:attribute name="id" type="xs:ID" use="optional"/>
 *   <xs:attribute ref="S:mustUnderstand" use="optional"/>
 *   <xs:attribute ref="S:actor" use="optional"/>
 * </xs:complexType>
 * <xs:element name="CredentialsContext" type="CredentialsContextType"/>
 * 
 * ]]></programlisting>
 * </figure>
 */ 

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "RequestAuthnContext", SNIPPET_NODE,
	  G_STRUCT_OFFSET(LassoSoapBindingExtCredentialsContext, RequestAuthnContext) },
	{ "SecurityMechID", SNIPPET_CONTENT,
	  G_STRUCT_OFFSET(LassoSoapBindingExtCredentialsContext, SecurityMechID) },
	{ "id", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoSoapBindingExtCredentialsContext, id) },
	{ "mustUnderstand", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSoapBindingExtCredentialsContext, mustUnderstand) },
	{ "actor", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSoapBindingExtCredentialsContext, actor) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSoapBindingExtCredentialsContext *node)
{
	node->RequestAuthnContext = NULL;
	node->SecurityMechID = NULL;
	node->id = NULL;
	node->mustUnderstand = NULL;
	node->actor = NULL;
}

static void
class_init(LassoSoapBindingExtCredentialsContextClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "CredentialsContext");
	lasso_node_class_set_ns(nclass, LASSO_SOAP_BINDING_EXT_HREF, LASSO_SOAP_BINDING_EXT_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_soap_binding_ext_credentials_context_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSoapBindingExtCredentialsContextClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSoapBindingExtCredentialsContext),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSoapBindingExtCredentialsContext", &this_info, 0);
	}
	return this_type;
}

LassoSoapBindingExtCredentialsContext*
lasso_soap_binding_ext_credentials_context_new()
{
	LassoSoapBindingExtCredentialsContext *node;

	node = g_object_new(LASSO_TYPE_SOAP_BINDING_EXT_CREDENTIALS_CONTEXT, NULL);

	return node;
}

LassoSoapBindingExtCredentialsContext*
lasso_soap_binding_ext_credentials_context_new_from_message(const gchar *message)
{
	LassoSoapBindingExtCredentialsContext *node;

	g_return_val_if_fail(message != NULL, NULL);

	node = g_object_new(LASSO_TYPE_SOAP_BINDING_EXT_CREDENTIALS_CONTEXT, NULL);
	lasso_node_init_from_message(LASSO_NODE(node), message);

	return node;
}
