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
#include "samlp2_scoping.h"

/**
 * SECTION:samlp2_scoping
 * @short_description: &lt;samlp2:Scoping&gt;
 *
 * <figure><title>Schema fragment for samlp2:Scoping</title>
 * <programlisting><![CDATA[
 *
 * <complexType name="ScopingType">
 *   <sequence>
 *     <element ref="samlp:IDPList" minOccurs="0"/>
 *     <element ref="samlp:RequesterID" minOccurs="0" maxOccurs="unbounded"/>
 *   </sequence>
 *   <attribute name="ProxyCount" type="nonNegativeInteger" use="optional"/>
 * </complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "IDPList", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlp2Scoping, IDPList), NULL, NULL, NULL},
	{ "RequesterID", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoSamlp2Scoping, RequesterID), NULL, NULL, NULL},
	{ "ProxyCount", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoSamlp2Scoping, ProxyCount), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoSamlp2ScopingClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Scoping");
	lasso_node_class_set_ns(nclass, LASSO_SAML2_PROTOCOL_HREF, LASSO_SAML2_PROTOCOL_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_samlp2_scoping_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlp2ScopingClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlp2Scoping),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSamlp2Scoping", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_samlp2_scoping_new:
 *
 * Creates a new #LassoSamlp2Scoping object.
 *
 * Return value: a newly created #LassoSamlp2Scoping object
 **/
LassoNode*
lasso_samlp2_scoping_new()
{
	return g_object_new(LASSO_TYPE_SAMLP2_SCOPING, NULL);
}
