/* $Id: soap_binding_consent.c,v 1.1 2005/03/11 17:15:15 nclapies Exp $ 
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

#include <lasso/xml/soap_binding_consent.h>

/*
 * Schema fragments (liberty-idwsf-soap-binding-v1.1.xsd):
 *
 * <xs:complexType name="ConsentType">
 *   <xs:attribute name="uri" type="xs:anyURI" use="required"/>
 *   <xs:attribute name="timestamp" type="xs:dateTime" use="optional"/>
 *   <xs:attribute name="id" type="xs:ID" use="optional"/>
 *   <xs:attribute ref="S:mustUnderstand" use="optional"/>
 *   <xs:attribute ref="S:actor" use="optional"/>
 * </xs:complexType>
 * <xs:element name="Consent" type="ConsentType"/>
 *
 */ 

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "uri", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSoapBindingConsent, uri) },
	{ "timestamp", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSoapBindingConsent, timestamp) },
	{ "id", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoSoapBindingConsent, id) },
	{ "mustUnderstand", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSoapBindingConsent, mustUnderstand) },
	{ "actor", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoSoapBindingConsent, actor) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSoapBindingConsent *node)
{
	node->uri = NULL;
	node->timestamp = NULL;
	node->id = NULL;
	node->mustUnderstand = NULL;
	node->actor = NULL;
}

static void
class_init(LassoSoapBindingConsentClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Consent");
	lasso_node_class_set_ns(nclass, LASSO_SOAP_BINDING_HREF, LASSO_SOAP_BINDING_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_soap_binding_consent_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSoapBindingConsentClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSoapBindingConsent),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSoapBindingConsent", &this_info, 0);
	}
	return this_type;
}

LassoSoapBindingConsent*
lasso_soap_binding_consent_new(const gchar *uri)
{
	LassoSoapBindingConsent *node;

	node = g_object_new(LASSO_TYPE_SOAP_BINDING_CONSENT, NULL);

	node->uri = g_strdup(uri);

	return node;
}

LassoSoapBindingConsent*
lasso_soap_binding_consent_new_from_message(const gchar *message)
{
	LassoSoapBindingConsent *node;

	g_return_val_if_fail(message != NULL, NULL);

	node = g_object_new(LASSO_TYPE_SOAP_BINDING_CONSENT, NULL);
	lasso_node_init_from_message(LASSO_NODE(node), message);

	return node;
}
