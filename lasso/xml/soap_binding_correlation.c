/* $Id: soap_binding_correlation.c 3704 2008-05-15 21:17:44Z fpeters $ 
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

#include <lasso/xml/soap_binding_correlation.h>

/**
 * SECTION:soap_binding_correlation
 * @short_description: &lt;soapbinding:correlationType&gt;
 *
 * <figure><title>Schema fragment for soapbinding:correlationType</title>
 * <programlisting><![CDATA[
 * <xs:complexType name="correlationType">
 *   <xs:attribute name="messageID" type="IDType" use="required"/>
 *   <xs:attribute name="refToMessageID" type="IDType" use="optional"/>
 *   <xs:attribute name="timestamp" type="xs: dateTime" use="required"/>
 *   <xs:attribute name="id" type="xs:ID" use="optional"/>
 *   <xs:attribute ref="S:mustUnderstand" use="optional"/>
 *   <xs:attribute ref="S:actor" use="optional"/>
 * </xs:complexType>
 * ]]></programlisting>
 * </figure>
 */ 

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "messageID", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSoapBindingCorrelation, messageID) },
	{ "refToMessageID", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSoapBindingCorrelation, refToMessageID) },
	{ "timestamp", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSoapBindingCorrelation, timestamp) },
	{ "id", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoSoapBindingCorrelation, id) },
	{ "mustUnderstand", SNIPPET_ATTRIBUTE,
	  G_STRUCT_OFFSET(LassoSoapBindingCorrelation, mustUnderstand) },
	{ "actor", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoSoapBindingCorrelation, actor) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSoapBindingCorrelation *node)
{
	node->messageID = NULL;
	node->refToMessageID = NULL;
	node->timestamp = NULL;
	node->id = NULL;
	node->mustUnderstand = NULL;
	node->actor = NULL;
}

static void
class_init(LassoSoapBindingCorrelationClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Correlation");
	lasso_node_class_set_ns(nclass, LASSO_SOAP_BINDING_HREF, LASSO_SOAP_BINDING_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_soap_binding_correlation_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSoapBindingCorrelationClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSoapBindingCorrelation),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSoapBindingCorrelation", &this_info, 0);
	}
	return this_type;
}

LassoSoapBindingCorrelation*
lasso_soap_binding_correlation_new(const gchar *messageId, const gchar *timestamp)
{
	LassoSoapBindingCorrelation *node;

	node = g_object_new(LASSO_TYPE_SOAP_BINDING_CORRELATION, NULL);

	node->messageID = g_strdup(messageId);
	node->timestamp = g_strdup(timestamp);

	return node;
}

LassoSoapBindingCorrelation*
lasso_soap_binding_correlation_new_from_message(const gchar *message)
{
	LassoSoapBindingCorrelation *node;

	g_return_val_if_fail(message != NULL, NULL);

	node = g_object_new(LASSO_TYPE_SOAP_BINDING_CORRELATION, NULL);
	lasso_node_init_from_message(LASSO_NODE(node), message);

	return node;
}
