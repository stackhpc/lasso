/* $Id: ims_mapping_input.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $ 
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

#include "ims_mapping_input.h"

/**
 * SECTION:ims_mapping_input
 * @short_description: &lt;ims:MappingInput&gt;
 *
 * <figure><title>Schema fragment for ims:MappingInput</title>
 * <programlisting><![CDATA[
 *
 * <xs:complexType name="MappingInputType">
 *   <xs:sequence>
 *     <xs:element ref="sec:TokenPolicy" minOccurs="0"/>
 *     <xs:element ref="sec:Token" minOccurs="0"/>
 *   </xs:sequence>
 *   <xs:attribute name="reqID" type="lu:IDType" use="optional"/>
 * </xs:complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "TokenPolicy", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoIdWsf2ImsMappingInput, TokenPolicy) },
	{ "Token", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoIdWsf2ImsMappingInput, Token) },
	{ "reqID", SNIPPET_ATTRIBUTE | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2ImsMappingInput, reqID) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoIdWsf2ImsMappingInput *node)
{
	node->TokenPolicy = NULL;
	node->Token = NULL;
	node->reqID = NULL;
}

static void
class_init(LassoIdWsf2ImsMappingInputClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "MappingInput");
	lasso_node_class_set_ns(nclass, LASSO_IDWSF2_IMS_HREF, LASSO_IDWSF2_IMS_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_idwsf2_ims_mapping_input_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIdWsf2ImsMappingInputClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIdWsf2ImsMappingInput),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoIdWsf2ImsMappingInput", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_idwsf2_ims_mapping_input_new:
 *
 * Creates a new #LassoIdWsf2ImsMappingInput object.
 *
 * Return value: a newly created #LassoIdWsf2ImsMappingInput object
 **/
LassoIdWsf2ImsMappingInput*
lasso_idwsf2_ims_mapping_input_new()
{
	return g_object_new(LASSO_TYPE_IDWSF2_IMS_MAPPING_INPUT, NULL);
}