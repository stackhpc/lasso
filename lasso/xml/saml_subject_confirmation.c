/* $Id: saml_subject_confirmation.c,v 1.18 2005/10/05 15:59:59 nclapies Exp $
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

#include <lasso/xml/saml_subject_confirmation.h>

/*
 * Schema fragment (oasis-sstc-saml-schema-assertion-1.0.xsd):
 * 
 * <element name="SubjectConfirmation" type="saml:SubjectConfirmationType"/>
 * <complexType name="SubjectConfirmationType">
 *   <sequence>
 *     <element ref="saml:ConfirmationMethod" maxOccurs="unbounded"/>
 *     <element ref="saml:SubjectConfirmationData" minOccurs="0"/>
 *     <element ref="ds:KeyInfo" minOccurs="0"/>
 *   </sequence>
 * </complexType>
 * 
 * <element name="SubjectConfirmationData" type="anyType"/>
 * <element name="ConfirmationMethod" type="anyURI"/>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "ConfirmationMethod", SNIPPET_LIST_CONTENT,
		G_STRUCT_OFFSET(LassoSamlSubjectConfirmation, ConfirmationMethod) },
	{ "SubjectConfirmationData", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoSamlSubjectConfirmation, SubjectConfirmationData) },
	{ "KeyInfo", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlSubjectConfirmation, KeyInfo) },
	{ NULL, 0, 0}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoSamlSubjectConfirmation *node)
{
  node->ConfirmationMethod = NULL;
  node->SubjectConfirmationData = NULL;
  node->KeyInfo = NULL;
}

static void
class_init(LassoSamlSubjectConfirmationClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "SubjectConfirmation");
	lasso_node_class_set_ns(nclass, LASSO_SAML_ASSERTION_HREF, LASSO_SAML_ASSERTION_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_saml_subject_confirmation_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoSamlSubjectConfirmationClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoSamlSubjectConfirmation),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_NODE,
				"LassoSamlSubjectConfirmation", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_saml_subject_confirmation_new:
 * 
 * Creates a new #LassoSamlSubjectConfirmation object.
 * 
 * Return value: a newly created #LassoSamlSubjectConfirmation object
 **/
LassoSamlSubjectConfirmation*
lasso_saml_subject_confirmation_new()
{
	return g_object_new(LASSO_TYPE_SAML_SUBJECT_CONFIRMATION, NULL);
}
