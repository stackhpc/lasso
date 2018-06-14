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
#include "soap_envelope.h"
#include "../../utils.h"

/**
 * SECTION:soap_envelope
 * @short_description: &lt;soap:Envelope&gt;
 *
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Header", SNIPPET_NODE, G_STRUCT_OFFSET(LassoSoapEnvelope, Header), NULL, NULL, NULL},
	{ "Body", SNIPPET_NODE, G_STRUCT_OFFSET(LassoSoapEnvelope, Body), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


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
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSoapEnvelope", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_soap_envelope_new:
 *
 * Creates a new #LassoSoapEnvelope with a new empty #LassoSoapBody
 * member.  Note, this function does not add a #LassoSoapHeader, if
 * you need both headers and a body use
 * lasso_soap_envelope_new_full() instead.
 *
 * Returns: new #LassoSoapEnvelope
 **/
LassoSoapEnvelope*
lasso_soap_envelope_new(LassoSoapBody *body)
{
	LassoSoapEnvelope *envelope;

	envelope = g_object_new(LASSO_TYPE_SOAP_ENVELOPE, NULL);

	lasso_assign_gobject(envelope->Body, body);

	return envelope;
}

/**
 * lasso_soap_envelope_new_from_message:
 * @message: XML document
 *
 * Given an XML document in @message, parse it and convert it into a
 * #LassoNode, then insert that #LassoNode into the body of the newly
 * returned #LassoSoapEnvelope.
 *
 * Returns: new #LassoSoapEnvelope
 **/
LassoSoapEnvelope*
lasso_soap_envelope_new_from_message(const gchar *message)
{
	LassoSoapEnvelope *envelope;

	g_return_val_if_fail(message != NULL, NULL);

	envelope = LASSO_SOAP_ENVELOPE(lasso_node_new_from_dump(message));
	if (! LASSO_IS_SOAP_ENVELOPE(envelope)) {
		lasso_release_gobject(envelope);
	}

	return envelope;
}

/**
 * lasso_soap_envelope_new_full:
 *
 * Creates a new #LassoSoapEnvelope with new empty #LassoSoapHeader
 * and #LassoSoapBody members.
 *
 * Returns: new #LassoSoapEnvelope
 **/
LassoSoapEnvelope*
lasso_soap_envelope_new_full()
{
	LassoSoapEnvelope *envelope = NULL;
	LassoSoapHeader *header = NULL;
	LassoSoapBody *body = NULL;
	LassoSoapEnvelope *result = NULL;

	envelope = g_object_new(LASSO_TYPE_SOAP_ENVELOPE, NULL);
	goto_cleanup_if_fail(envelope);

	header = lasso_soap_header_new();
	goto_cleanup_if_fail(header);
	lasso_assign_gobject(envelope->Header, header);

	body = lasso_soap_body_new();
	goto_cleanup_if_fail(body);
	lasso_assign_gobject(envelope->Body, body);
	lasso_transfer_gobject(result, envelope);

 cleanup:
	lasso_release_gobject(envelope);
	lasso_release_gobject(header);
	lasso_release_gobject(body);

	return result;
}
