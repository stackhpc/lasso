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
#include "saml_subject_confirmation.h"

/**
 * SECTION:saml_subject_confirmation
 * @short_description: &lt;saml:SubjectConfirmation&gt;
 *
 * <figure><title>Schema fragment for saml:SubjectConfirmation</title>
 * <programlisting><![CDATA[
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
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "ConfirmationMethod", SNIPPET_LIST_CONTENT,
		G_STRUCT_OFFSET(LassoSamlSubjectConfirmation, ConfirmationMethod), NULL, NULL, NULL},
	{ "SubjectConfirmationData", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoSamlSubjectConfirmation, SubjectConfirmationData), NULL, NULL, NULL},
	{ "KeyInfo", SNIPPET_NODE,
		G_STRUCT_OFFSET(LassoSamlSubjectConfirmation, KeyInfo), NULL, LASSO_DS_PREFIX,
		LASSO_DS_HREF},
	{NULL, 0, 0, NULL, NULL, NULL}
};

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/


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
			NULL,
			NULL
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
