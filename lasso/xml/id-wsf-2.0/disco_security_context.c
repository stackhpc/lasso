/* $Id: disco_security_context.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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
#include "disco_security_context.h"
#include "idwsf2_strings.h"

/**
 * SECTION:disco_security_context
 * @short_description: &lt;disco:SecurityContext&gt;
 *
 * <figure><title>Schema fragment for disco:SecurityContext</title>
 * <programlisting><![CDATA[
 *
 * <xs:element name="SecurityContext">
 *   <xs:complexType>
 *     <xs:sequence>
 *       <xs:element ref="SecurityMechID"
 *         minOccurs="1"
 *         maxOccurs="unbounded"/>
 *
 *         <xs:element ref="sec:Token"
 *           minOccurs="0"
 *           maxOccurs="unbounded"/>
 *         </xs:sequence>
 *       </xs:complexType>
 *     </xs:element>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "SecurityMechID", SNIPPET_LIST_CONTENT,
		G_STRUCT_OFFSET(LassoIdWsf2DiscoSecurityContext, SecurityMechID), NULL, NULL, NULL},
	{ "Token", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoIdWsf2DiscoSecurityContext, Token), NULL,
		LASSO_IDWSF2_SEC_PREFIX, LASSO_IDWSF2_SEC_HREF},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoIdWsf2DiscoSecurityContextClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "SecurityContext");
	lasso_node_class_set_ns(nclass, LASSO_IDWSF2_DISCOVERY_HREF, LASSO_IDWSF2_DISCOVERY_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_idwsf2_disco_security_context_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIdWsf2DiscoSecurityContextClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIdWsf2DiscoSecurityContext),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoIdWsf2DiscoSecurityContext", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_idwsf2_disco_security_context_new:
 *
 * Creates a new #LassoIdWsf2DiscoSecurityContext object.
 *
 * Return value: a newly created #LassoIdWsf2DiscoSecurityContext object
 **/
LassoIdWsf2DiscoSecurityContext*
lasso_idwsf2_disco_security_context_new()
{
	return g_object_new(LASSO_TYPE_IDWSF2_DISCO_SECURITY_CONTEXT, NULL);
}
