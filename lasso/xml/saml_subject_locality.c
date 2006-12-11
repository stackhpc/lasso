/* $Id: saml_subject_locality.c,v 1.14 2005/01/22 15:57:55 eraviart Exp $
 *
 * Lasso - A free implementation of the Samlerty Alliance specifications.
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

#include <lasso/xml/saml_subject_locality.h>

/*
 * Schema fragment (oasis-sstc-saml-schema-assertion-1.0.xsd):
 * 
 * <element name="SubjectLocality" type="saml:SubjectLocalityType"/>
 * <complexType name="SubjectLocalityType">
 *   <attribute name="IPAddress" type="string" use="optional"/>
 *   <attribute name="DNSAddress" type="string" use="optional"/>
 * </complexType>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "IPAddress", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoSamlSubjectLocality, IPAddress) },
	{ "DNSAddress", SNIPPET_ATTRIBUTE, G_STRUCT_OFFSET(LassoSamlSubjectLocality, DNSAddress) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSamlSubjectLocality *node)
{
	node->IPAddress = NULL;
	node->DNSAddress = NULL;
}

static void
class_init(LassoSamlSubjectLocalityClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);
	
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "SubjectLocality");
	lasso_node_class_set_ns(nclass, LASSO_SAML_ASSERTION_HREF, LASSO_SAML_ASSERTION_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_saml_subject_locality_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlSubjectLocalityClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlSubjectLocality),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSamlSubjectLocality", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_saml_subject_locality_new:
 * 
 * Creates a new #LassoSamlSubjectLocality object.
 * 
 * Return value: a newly created #LassoSamlSubjectLocality object
 **/
LassoNode* lasso_saml_subject_locality_new()
{
	return g_object_new(LASSO_TYPE_SAML_SUBJECT_LOCALITY, NULL);
}
