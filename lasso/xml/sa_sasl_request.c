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
#include "sa_sasl_request.h"
#include "idwsf_strings.h"

/**
 * SECTION:sa_sasl_request
 * @short_description: &lt;sa:SASLRequest&gt;
 *
 * <figure><title>Schema fragment for sa:SASLRequest</title>
 * <programlisting><![CDATA[
 *
 *  <xs:element name="SASLRequest">
 *    <xs:complexType>
 *      <xs:sequence>
 *        <xs:element name="Data" minOccurs="0">
 *          <xs:complexType>
 *            <xs:simpleContent>
 *              <xs:extension base="xs:base64Binary"/>
 *            </xs:simpleContent>
 *          </xs:complexType>
 *        </xs:element>
 *        <xs:element ref="lib:RequestAuthnContext" minOccurs="0"/>
 *      </xs:sequence>
 *      <xs:attribute name="mechanism"type="xs:string" use="required"/>
 *      <xs:attribute name="authzID" type="xs:string" use="optional"/>
 *      <xs:attribute name="advisoryAuthnID" type="xs:string" use="optional"/>
 *      <xs:attribute name="id" type="xs:ID"use="optional"/>
 *    </xs:complexType>
 *  </xs:element>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "Data", SNIPPET_LIST_CONTENT,
		G_STRUCT_OFFSET(LassoSaSASLRequest, Data), NULL, NULL, NULL},
	{ "RequestAuthnContext", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSaSASLRequest, RequestAuthnContext), NULL, LASSO_LIB_PREFIX,
		LASSO_LIB_HREF},
	{ "mechanism", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaSASLRequest, mechanism), NULL, NULL, NULL},
	{ "authzID", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaSASLRequest, authzID), NULL, NULL, NULL},
	{ "advisoryAuthnID", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaSASLRequest, advisoryAuthnID), NULL, NULL, NULL},
	{ "id", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaSASLRequest, id), NULL, NULL, NULL},
	{NULL, 0, 0, NULL, NULL, NULL}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


static void
class_init(LassoSaSASLRequestClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "SASLRequest");
	lasso_node_class_set_ns(nclass, LASSO_SA_HREF, LASSO_SA_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_sa_sasl_request_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSaSASLRequestClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSaSASLRequest),
			0,
			NULL,
			NULL
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSaSASLRequest", &this_info, 0);
	}
	return this_type;
}

LassoSaSASLRequest*
lasso_sa_sasl_request_new(const gchar *mechanism)
{
	LassoSaSASLRequest *node;

	g_return_val_if_fail(mechanism != NULL, NULL);

	node = g_object_new(LASSO_TYPE_SA_SASL_REQUEST, NULL);
	node->mechanism = g_strdup(mechanism);

	return node;
}
