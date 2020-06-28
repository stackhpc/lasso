/* $Id: saml2_name_id.c,v 1.2 2005/11/21 18:51:52 fpeters Exp $ 
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

#include "saml2_name_id.h"

/*
 * Schema fragment (saml-schema-assertion-2.0.xsd):
 *
 * <complexType name="NameIDType">
 *   <simpleContent>
 *     <extension base="string">
 *       <attributeGroup ref="saml:IDNameQualifiers"/>
 *       <attribute name="Format" type="anyURI" use="optional"/>
 *       <attribute name="SPProvidedID" type="string" use="optional"/>
 *     </extension>
 *   </simpleContent>
 * </complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "content", SNIPPET_TEXT_CHILD,
		G_STRUCT_OFFSET(LassoSaml2NameID, content) },
	{ "Format", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaml2NameID, Format) },
	{ "SPProvidedID", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaml2NameID, SPProvidedID) },
	{ "NameQualifier", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaml2NameID, NameQualifier) },
	{ "SPNameQualifier", SNIPPET_ATTRIBUTE,
		G_STRUCT_OFFSET(LassoSaml2NameID, SPNameQualifier) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSaml2NameID *node)
{
	node->content = NULL;
	node->Format = NULL;
	node->SPProvidedID = NULL;
	node->NameQualifier = NULL;
	node->SPNameQualifier = NULL;
}

static void
class_init(LassoSaml2NameIDClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "NameID"); 
	lasso_node_class_set_ns(nclass, LASSO_SAML2_ASSERTION_HREF, LASSO_SAML2_ASSERTION_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_saml2_name_id_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSaml2NameIDClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSaml2NameID),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSaml2NameID", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_saml2_name_id_new:
 *
 * Creates a new #LassoSaml2NameID object.
 *
 * Return value: a newly created #LassoSaml2NameID object
 **/
LassoNode*
lasso_saml2_name_id_new()
{
	return g_object_new(LASSO_TYPE_SAML2_NAME_ID, NULL);
}


/**
 * lasso_saml2_name_id_new_with_string:
 * @content: 
 *
 * Creates a new #LassoSaml2NameID object and initializes it
 * with @content.
 *
 * Return value: a newly created #LassoSaml2NameID object
 **/
LassoNode*
lasso_saml2_name_id_new_with_string(char *content)
{
	LassoSaml2NameID *object;
	object = g_object_new(LASSO_TYPE_SAML2_NAME_ID, NULL);
	object->content = g_strdup(content);
	return LASSO_NODE(object);
}
