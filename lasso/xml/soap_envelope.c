/* $Id: soap_envelope.c,v 1.2 2005/03/18 09:09:22 nclapies Exp $ 
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

#include <lasso/xml/soap_envelope.h>

/*
 * Schema fragments ():
 * 
 */ 

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Header", SNIPPET_NODE, G_STRUCT_OFFSET(LassoSoapEnvelope, Header) },
	{ "Body", SNIPPET_NODE, G_STRUCT_OFFSET(LassoSoapEnvelope, Body) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSoapEnvelope *node)
{
	node->Body = NULL;
	node->Header = NULL;
}

static void
class_init(LassoSoapEnvelopeClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Envelope");
	lasso_node_class_set_ns(nclass, LASSO_SOAP_ENV_HREF, LASSO_SOAP_ENV_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_soap_envelope_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSoapEnvelopeClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSoapEnvelope),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSoapEnvelope", &this_info, 0);
	}
	return this_type;
}

LassoSoapEnvelope*
lasso_soap_envelope_new(LassoSoapBody *body)
{
	LassoSoapEnvelope *node;

	node = g_object_new(LASSO_TYPE_SOAP_ENVELOPE, NULL);

	node->Body = body;

	return node;
}

LassoSoapEnvelope*
lasso_soap_envelope_new_from_message(const gchar *message)
{
	LassoSoapEnvelope *node;

	g_return_val_if_fail(message != NULL, NULL);

/* 	node = g_object_new(LASSO_TYPE_SOAP_ENVELOPE, NULL); */
/* 	lasso_node_init_from_message(LASSO_NODE(node), message); */

	node = LASSO_SOAP_ENVELOPE(lasso_node_new_from_dump(message));

	return node;
}
