/* $Id: lib_sp_provided_name_identifier.c,v 1.6 2004/09/01 09:59:53 fpeters Exp $
 *
 * Lasso - A free implementation of the Samlerty Alliance specifications.
 *
 * Copyright (C) 2004 Entr'ouvert
 * http://lasso.entrouvert.org
 * 
 * Authors: Nicolas Clapies <nclapies@entrouvert.com>
 *          Valery Febvre <vfebvre@easter-eggs.com>
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

#include <lasso/xml/lib_sp_provided_name_identifier.h>

/*
The Schema fragment (liberty-idff-protocols-schema-v1.2.xsd):

<xs:element name="SPProvidedNameIdentifier" type="saml:NameIdentifierType"/>

*/

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
lasso_lib_sp_provided_name_identifier_instance_init(LassoLibSPProvidedNameIdentifier *node)
{
  LassoNodeClass *class = LASSO_NODE_GET_CLASS(LASSO_NODE(node));

  class->set_ns(LASSO_NODE(node), lassoLibHRef, lassoLibPrefix);
  class->set_name(LASSO_NODE(node), "SPProvidedNameIdentifier");
}

static void
lasso_lib_sp_provided_name_identifier_class_init(LassoLibSPProvidedNameIdentifierClass *klass)
{
}

GType lasso_lib_sp_provided_name_identifier_get_type() {
  static GType this_type = 0;

  if (!this_type) {
    static const GTypeInfo this_info = {
      sizeof (LassoLibSPProvidedNameIdentifierClass),
      NULL,
      NULL,
      (GClassInitFunc) lasso_lib_sp_provided_name_identifier_class_init,
      NULL,
      NULL,
      sizeof(LassoLibSPProvidedNameIdentifierClass),
      0,
      (GInstanceInitFunc) lasso_lib_sp_provided_name_identifier_instance_init,
    };
    
    this_type = g_type_register_static(LASSO_TYPE_SAML_NAME_IDENTIFIER,
				       "LassoLibSPProvidedNameIdentifier",
				       &this_info, 0);
  }
  return this_type;
}

LassoNode* lasso_lib_sp_provided_name_identifier_new(const xmlChar *content) {
  LassoNode *node;

  g_assert(content != NULL);

  node = LASSO_NODE(g_object_new(LASSO_TYPE_LIB_SP_PROVIDED_NAME_IDENTIFIER,
				 NULL));

  xmlNodeSetContent(LASSO_NODE_GET_CLASS(node)->get_xmlNode(node),
		    content);

  return node;
}
