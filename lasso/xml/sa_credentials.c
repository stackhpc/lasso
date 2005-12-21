/* $Id: sa_credentials.c,v 1.1 2005/03/02 17:09:14 nclapies Exp $
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

#include <lasso/xml/sa_credentials.h>

/*
 * Schema fragments (liberty-idwsf-authn-svc-v1.0.xsd):
 * 
 *     <xs:element name="Credentials" minOccurs="0">
 *     <xs:complexType>
 *       <xs:sequence>
 *         <xs:any namespace="##any" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
 *       </xs:sequence>
 *     </xs:complexType>
 *     </xs:element>
 */ 

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "", SNIPPET_LIST_NODES, G_STRUCT_OFFSET(LassoSaCredentials, any) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSaCredentials *node)
{
	node->any = NULL;
}

static void
class_init(LassoSaCredentialsClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Credentials");
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_sa_credentials_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSaCredentialsClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSaCredentials),
			0,
			(GInstanceInitFunc) instance_init,
		};
		
		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSaCredentials", &this_info, 0);
	}
	return this_type;
}

LassoSaCredentials*
lasso_sa_credentials_new()
{
	LassoSaCredentials *node;

	node = g_object_new(LASSO_TYPE_SA_CREDENTIALS, NULL);

	return node;
}

LassoSaCredentials*
lasso_sa_credentials_new_from_message(const gchar *message)
{
	LassoSaCredentials *node;

	g_return_val_if_fail(message != NULL, NULL);

	node = g_object_new(LASSO_TYPE_SA_CREDENTIALS, NULL);
	lasso_node_init_from_message(LASSO_NODE(node), message);

	return node;
}

gint
lasso_sa_credentials_add_assertion(LassoSaCredentials *credentials,
				   LassoSamlAssertion *assertion)
{
	g_return_val_if_fail(LASSO_IS_SA_CREDENTIALS(credentials),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(LASSO_IS_SAML_ASSERTION(assertion),
			     LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	g_object_ref(assertion);
	credentials->any = g_list_append(credentials->any, assertion);

	return 0;
}
