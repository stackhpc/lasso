/* $Id: samlp2_artifact_resolve.c 3704 2008-05-15 21:17:44Z fpeters $ 
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

#include "samlp2_artifact_resolve.h"

/**
 * SECTION:samlp2_artifact_resolve
 * @short_description: &lt;samlp2:ArtifactResolve&gt;
 *
 * <figure><title>Schema fragment for samlp2:ArtifactResolve</title>
 * <programlisting><![CDATA[
 *
 * <complexType name="ArtifactResolveType">
 *   <complexContent>
 *     <extension base="samlp:RequestAbstractType">
 *       <sequence>
 *         <element ref="samlp:Artifact"/>
 *       </sequence>
 *     </extension>
 *   </complexContent>
 * </complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "Artifact", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoSamlp2ArtifactResolve, Artifact) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSamlp2ArtifactResolve *node)
{
	node->Artifact = NULL;
}

static void
class_init(LassoSamlp2ArtifactResolveClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "ArtifactResolve"); 
	lasso_node_class_set_ns(nclass, LASSO_SAML2_PROTOCOL_HREF, LASSO_SAML2_PROTOCOL_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_samlp2_artifact_resolve_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlp2ArtifactResolveClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlp2ArtifactResolve),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_SAMLP2_REQUEST_ABSTRACT,
				"LassoSamlp2ArtifactResolve", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_samlp2_artifact_resolve_new:
 *
 * Creates a new #LassoSamlp2ArtifactResolve object.
 *
 * Return value: a newly created #LassoSamlp2ArtifactResolve object
 **/
LassoNode*
lasso_samlp2_artifact_resolve_new()
{
	return g_object_new(LASSO_TYPE_SAMLP2_ARTIFACT_RESOLVE, NULL);
}
