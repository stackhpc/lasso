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

#include "private.h"
#include "is_interaction_response.h"
#include "idwsf_strings.h"

/**
 * SECTION:is_interaction_response
 * @short_description: &lt;is:InteractionResponse&gt;
 *
 * <figure><title>Schema fragment for is:InteractionResponse</title>
 * <programlisting><![CDATA[
 *
 * <xs:element name="InteractionResponse" type="InteractionResponseType"/>
 * <xs:complexType name="InteractionResponseType">
 *   <xs:sequence>
 *     <xs:element ref="Status"/>
 *     <xs:choice>
 *       <xs:element name="InteractionStatement" type="InteractionStatementType" minOccurs="0"
 *                                               maxOccurs="unbounded"/>
 *       <xs:element name="Parameter" type="ParameterType" minOccurs="0" maxOccurs="unbounded"/>
 *     </xs:choice>
 *   </xs:sequence>
 * </xs:complexType>
 *
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Status", SNIPPET_NODE, G_STRUCT_OFFSET(LassoIsInteractionResponse, Status), NULL, NULL, NULL},
	{ "InteractionStatement", SNIPPET_LIST_NODES, G_STRUCT_OFFSET(LassoIsInteractionResponse,
			InteractionStatement), NULL, NULL, NULL },
	{ "Parameter", SNIPPET_LIST_NODES, G_STRUCT_OFFSET(LassoIsInteractionResponse,
			Parameter), NULL, NULL, NULL },
	{NULL, 0, 0, NULL, NULL, NULL}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoIsInteractionResponseClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "InteractionResponse");
	lasso_node_class_set_ns(nclass, LASSO_IS_HREF, LASSO_IS_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_is_interaction_response_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIsInteractionResponseClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIsInteractionResponse),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoIsInteractionResponse", &this_info, 0);
	}
	return this_type;
}

LassoIsInteractionResponse*
lasso_is_interaction_response_new(LassoUtilityStatus *status)
{
	LassoIsInteractionResponse *node;

	node = g_object_new(LASSO_TYPE_IS_INTERACTION_RESPONSE, NULL);

	node->Status = status;

	return node;
}
