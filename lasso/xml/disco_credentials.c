/* $Id: disco_credentials.c 3704 2008-05-15 21:17:44Z fpeters $ 
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

#include <lasso/xml/disco_credentials.h>

/**
 * SECTION:disco_credentials
 * @short_description: &lt;disco:Credentials&gt;
 *
 * <figure><title>Schema fragment for disco:Credentials</title>
 * <programlisting><![CDATA[
 * 
 * <xs:element name="Credentials" minOccurs="0">
 *   <xs:complexType>
 *     <xs:sequence>
 *       <xs:any namespace="##any" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
 *     </xs:sequence>
 *   </xs:complexType>
 * </xs:element>
 * ]]></programlisting>
 * </figure>
 */


/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "", SNIPPET_LIST_NODES, G_STRUCT_OFFSET(LassoDiscoCredentials, any) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoDiscoCredentials *node)
{
	node->any = NULL;
}

static void
class_init(LassoDiscoCredentialsClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Credentials");
	lasso_node_class_set_ns(nclass, LASSO_DISCO_HREF, LASSO_DISCO_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_disco_credentials_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoDiscoCredentialsClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoDiscoCredentials),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoDiscoCredentials", &this_info, 0);
	}
	return this_type;
}

LassoDiscoCredentials*
lasso_disco_credentials_new()
{
	LassoDiscoCredentials *node;

	node = g_object_new(LASSO_TYPE_DISCO_CREDENTIALS, NULL);

	return node;
}
