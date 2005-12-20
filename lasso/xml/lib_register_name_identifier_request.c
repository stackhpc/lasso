/* $Id: lib_register_name_identifier_request.c,v 1.8 2004/08/13 15:16:13 fpeters Exp $ 
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

#include <lasso/xml/lib_register_name_identifier_request.h>

/*
The Schema fragment (liberty-idff-protocols-schema-v1.2.xsd):

<xs:element name="RegisterNameIdentifierRequest" type="RegisterNameIdentifierRequestType"/>
<xs:complexType name="RegisterNameIdentifierRequestType">
  <xs:complexContent>
    <xs:extension base="samlp:RequestAbstractType">
      <xs:sequence>
        <xs:element ref="Extension" minOccurs="0" maxOccurs="unbounded"/>
        <xs:element ref="ProviderID"/>
        <xs:element ref="IDPProvidedNameIdentifier"/>
        <xs:element ref="SPProvidedNameIdentifier"/>
        <xs:element ref="OldProvidedNameIdentifier"/>
        <xs:element ref="RelayState" minOccurs="0"/>
      </xs:sequence>
    </xs:extension>
  </xs:complexContent>
</xs:complexType>
<xs:element name="IDPProvidedNameIdentifier" type="saml:NameIdentifierType"/>
<xs:element name="SPProvidedNameIdentifier" type="saml:NameIdentifierType"/>
<xs:element name="OldProvidedNameIdentifier" type="saml:NameIdentifierType"/>

<xs:element name="ProviderID" type="md:entityIDType"/>
<xs:element name="RelayState" type="xs:string"/>

From liberty-metadata-v1.0.xsd:
<xs:simpleType name="entityIDType">
  <xs:restriction base="xs:anyURI">
    <xs:maxLength value="1024" id="maxlengthid"/>
  </xs:restriction>
</xs:simpleType>

*/

/*****************************************************************************/
/* public methods                                                            */
/*****************************************************************************/

void
lasso_lib_register_name_identifier_request_set_idpProvidedNameIdentifier(LassoLibRegisterNameIdentifierRequest *node,
									 LassoLibIDPProvidedNameIdentifier *idpProvidedNameIdentifier)
{
  LassoNodeClass *class;
  g_assert(LASSO_IS_LIB_REGISTER_NAME_IDENTIFIER_REQUEST(node));
  g_assert(LASSO_IS_LIB_IDP_PROVIDED_NAME_IDENTIFIER(idpProvidedNameIdentifier));

  class = LASSO_NODE_GET_CLASS(node);
  class->add_child(LASSO_NODE (node),
		   LASSO_NODE (idpProvidedNameIdentifier),
		   FALSE);
}

void
lasso_lib_register_name_identifier_request_set_oldProvidedNameIdentifier(LassoLibRegisterNameIdentifierRequest *node,
									 LassoLibOLDProvidedNameIdentifier *oldProvidedNameIdentifier)
{
  LassoNodeClass *class;
  g_assert(LASSO_IS_LIB_REGISTER_NAME_IDENTIFIER_REQUEST(node));
  g_assert(LASSO_IS_LIB_OLD_PROVIDED_NAME_IDENTIFIER(oldProvidedNameIdentifier));

  class = LASSO_NODE_GET_CLASS(node);
  class->add_child(LASSO_NODE (node),
		   LASSO_NODE (oldProvidedNameIdentifier),
		   FALSE);
}

void
lasso_lib_register_name_identifier_request_set_providerID(LassoLibRegisterNameIdentifierRequest *node,
							  const xmlChar *providerID)
{
  LassoNodeClass *class;
  g_assert(LASSO_IS_LIB_REGISTER_NAME_IDENTIFIER_REQUEST(node));
  g_assert(providerID != NULL);
  /* FIXME : providerID length SHOULD be <= 1024 */

  class = LASSO_NODE_GET_CLASS(node);
  class->new_child(LASSO_NODE (node), "ProviderID", providerID, FALSE);
}

void
lasso_lib_register_name_identifier_request_set_relayState(LassoLibRegisterNameIdentifierRequest *node,
							  const xmlChar *relayState)
{
  LassoNodeClass *class;
  g_assert(LASSO_IS_LIB_REGISTER_NAME_IDENTIFIER_REQUEST(node));
  g_assert(relayState != NULL);

  class = LASSO_NODE_GET_CLASS(node);
  class->new_child(LASSO_NODE (node), "RelayState", relayState, FALSE);
}

void
lasso_lib_register_name_identifier_request_set_spProvidedNameIdentifier(LassoLibRegisterNameIdentifierRequest *node,
									LassoLibSPProvidedNameIdentifier *spProvidedNameIdentifier)
{
  LassoNodeClass *class;
  g_assert(LASSO_IS_LIB_REGISTER_NAME_IDENTIFIER_REQUEST(node));
  g_assert(LASSO_IS_LIB_SP_PROVIDED_NAME_IDENTIFIER(spProvidedNameIdentifier));

  class = LASSO_NODE_GET_CLASS(node);
  class->add_child(LASSO_NODE (node),
		   LASSO_NODE (spProvidedNameIdentifier),
		   FALSE);
}

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
lasso_lib_register_name_identifier_request_instance_init(LassoLibRegisterNameIdentifierRequest *node)
{
  LassoNodeClass *class = LASSO_NODE_GET_CLASS(LASSO_NODE(node));

  class->set_ns(LASSO_NODE(node), lassoLibHRef, lassoLibPrefix);
  class->set_name(LASSO_NODE(node), "RegisterNameIdentifierRequest");
}

static void
lasso_lib_register_name_identifier_request_class_init(LassoLibRegisterNameIdentifierRequestClass *klass)
{
}

GType lasso_lib_register_name_identifier_request_get_type() {
  static GType this_type = 0;

  if (!this_type) {
    static const GTypeInfo this_info = {
      sizeof (LassoLibRegisterNameIdentifierRequestClass),
      NULL,
      NULL,
      (GClassInitFunc) lasso_lib_register_name_identifier_request_class_init,
      NULL,
      NULL,
      sizeof(LassoLibRegisterNameIdentifierRequest),
      0,
      (GInstanceInitFunc) lasso_lib_register_name_identifier_request_instance_init,
    };
    
    this_type = g_type_register_static(LASSO_TYPE_SAMLP_REQUEST_ABSTRACT,
				       "LassoLibRegisterNameIdentifierRequest",
				       &this_info, 0);
  }
  return this_type;
}

LassoNode* lasso_lib_register_name_identifier_request_new() {
  return LASSO_NODE(g_object_new(LASSO_TYPE_LIB_REGISTER_NAME_IDENTIFIER_REQUEST,
				 NULL));
}
