/* $Id: is_interaction_request.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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
#include "is_interaction_request.h"
#include "idwsf2_strings.h"

/**
 * SECTION:is_interaction_request
 * @short_description: &lt;is:InteractionRequest&gt;
 *
 * <figure><title>Schema fragment for is:InteractionRequest</title>
 * <programlisting><![CDATA[
 *
 * <xs:complexType name="InteractionRequestType">
 *   <xs:sequence>
 *     <xs:element ref="Inquiry" maxOccurs="unbounded"/>
 *     <xs:element ref="ds:KeyInfo" minOccurs="0"/>
 *   </xs:sequence>
 *   <xs:attribute name="id" type="xs:ID" use="optional"/>
 *   <xs:attribute name="language" type="xs:NMTOKENS" use="optional"/>
 *   <xs:attribute name="maxInteractTime" type="xs:integer" use="optional"/>
 *   <xs:attribute name="signed" type="xs:token" use="optional"/>
 * </xs:complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "Inquiry", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoIdWsf2IsInteractionRequest, Inquiry), NULL, NULL, NULL},
	{ "KeyInfo", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoIdWsf2IsInteractionRequest, KeyInfo), NULL, LASSO_DS_PREFIX, LASSO_DS_HREF},
	{ "id", SNIPPET_ATTRIBUTE | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2IsInteractionRequest, id), NULL, NULL, NULL},
	{ "language", SNIPPET_ATTRIBUTE | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2IsInteractionRequest, language), NULL, NULL, NULL},
	{ "maxInteractTime", SNIPPET_ATTRIBUTE | SNIPPET_INTEGER | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2IsInteractionRequest, maxInteractTime), NULL, NULL, NULL},
	{ "signed", SNIPPET_ATTRIBUTE | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2IsInteractionRequest, signed_), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoIdWsf2IsInteractionRequestClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "InteractionRequest");
	lasso_node_class_set_ns(nclass, LASSO_IDWSF2_IS_HREF, LASSO_IDWSF2_IS_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_idwsf2_is_interaction_request_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIdWsf2IsInteractionRequestClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIdWsf2IsInteractionRequest),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoIdWsf2IsInteractionRequest", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_idwsf2_is_interaction_request_new:
 *
 * Creates a new #LassoIdWsf2IsInteractionRequest object.
 *
 * Return value: a newly created #LassoIdWsf2IsInteractionRequest object
 **/
LassoIdWsf2IsInteractionRequest*
lasso_idwsf2_is_interaction_request_new()
{
	return g_object_new(LASSO_TYPE_IDWSF2_IS_INTERACTION_REQUEST, NULL);
}
