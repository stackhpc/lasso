/* $Id: saml_statement_abstract.c,v 1.4 2004/09/01 09:59:53 fpeters Exp $
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

#include <lasso/xml/saml_statement_abstract.h>

/*
The schema fragment (oasis-sstc-saml-schema-assertion-1.0.xsd):

<element name="Statement" type="saml:StatementAbstractType"/>
<complexType name="StatementAbstractType" abstract="true"/>
*/

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
lasso_saml_statement_abstract_instance_init(LassoSamlStatementAbstract *node)
{
  LassoNodeClass *class = LASSO_NODE_GET_CLASS(LASSO_NODE(node));

  class->set_ns(LASSO_NODE(node), lassoSamlAssertionHRef,
		lassoSamlAssertionPrefix);
  class->set_name(LASSO_NODE(node), "StatementAbstract");
}

static void
lasso_saml_statement_abstract_class_init(LassoSamlStatementAbstractClass *klass)
{
}

GType lasso_saml_statement_abstract_get_type() {
  static GType this_type = 0;

  if (!this_type) {
    static const GTypeInfo this_info = {
      sizeof (LassoSamlStatementAbstractClass),
      NULL,
      NULL,
      (GClassInitFunc) lasso_saml_statement_abstract_class_init,
      NULL,
      NULL,
      sizeof(LassoSamlStatementAbstract),
      0,
      (GInstanceInitFunc) lasso_saml_statement_abstract_instance_init,
    };
    
    this_type = g_type_register_static(LASSO_TYPE_NODE,
				       "LassoSamlStatementAbstract",
				       &this_info, 0);
  }
  return this_type;
}

/**
 * lasso_saml_statement_abstract_new:
 * @name: the node's name. If @name is NULL or an empty string, default value
 * "StatementAbstract" will be used.
 *
 * Creates a new <saml:StatementAbstract> node object.
 * 
 * Return value: the new @LassoSamlStatementAbstract
 **/
LassoNode* lasso_saml_statement_abstract_new(const xmlChar *name)
{
  LassoNode *node;

  node = LASSO_NODE(g_object_new(LASSO_TYPE_SAML_STATEMENT_ABSTRACT, NULL));

  if (name && *name)
    LASSO_NODE_GET_CLASS(node)->set_name(node, name);

  return node;
}
