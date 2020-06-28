/* $Id: samlp_status_code.c,v 1.4 2004/08/13 15:16:13 fpeters Exp $
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
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

#include <lasso/xml/samlp_status_code.h>

/*
Schema fragment (oasis-sstc-saml-schema-protocol-1.0.xsd):

<element name="StatusCode" type="samlp:StatusCodeType"/>
<complexType name="StatusCodeType">
  <sequence>
    <element ref="samlp:StatusCode" minOccurs="0"/>
  </sequence>
  <attribute name="Value" type="QName" use="required"/>
</complexType>
*/

/*****************************************************************************/
/* public methods                                                            */
/*****************************************************************************/

void
lasso_samlp_status_code_set_value(LassoSamlpStatusCode *node,
				  const xmlChar *value)
{
  LassoNodeClass *class;
  g_assert(LASSO_IS_SAMLP_STATUS_CODE(node));
  g_assert(value != NULL);

  class = LASSO_NODE_GET_CLASS(node);
  class->set_prop(LASSO_NODE (node), "Value", value);
}

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
lasso_samlp_status_code_instance_init(LassoSamlpStatusCode *node)
{
  LassoNodeClass *class = LASSO_NODE_GET_CLASS(LASSO_NODE(node));

  class->set_ns(LASSO_NODE(node), lassoSamlProtocolHRef,
		lassoSamlProtocolPrefix);
  class->set_name(LASSO_NODE(node), "StatusCode");
}

static void
lasso_samlp_status_code_class_init(LassoSamlpStatusCodeClass *klass)
{
}

GType lasso_samlp_status_code_get_type() {
  static GType this_type = 0;

  if (!this_type) {
    static const GTypeInfo this_info = {
      sizeof (LassoSamlpStatusCodeClass),
      NULL,
      NULL,
      (GClassInitFunc) lasso_samlp_status_code_class_init,
      NULL,
      NULL,
      sizeof(LassoSamlpStatusCode),
      0,
      (GInstanceInitFunc) lasso_samlp_status_code_instance_init,
    };
    
    this_type = g_type_register_static(LASSO_TYPE_NODE,
				       "LassoSamlpStatusCode",
				       &this_info, 0);
  }
  return this_type;
}

LassoNode* lasso_samlp_status_code_new()
{
  return LASSO_NODE(g_object_new(LASSO_TYPE_SAMLP_STATUS_CODE, NULL));
}
