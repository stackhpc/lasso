/* $Id: name_identifier_mapping_response.c,v 1.14 2004/09/01 09:59:53 fpeters Exp $ 
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004 Entr'ouvert
 * http://lasso.entrouvert.org
 * 
 * Authors: Valery Febvre   <vfebvre@easter-eggs.com>
 *          Nicolas Clapies <nclapies@entrouvert.com>
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

#include <lasso/protocols/name_identifier_mapping_response.h>

/*****************************************************************************/
/* public methods                                                            */
/*****************************************************************************/

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
lasso_name_identifier_mapping_response_instance_init(LassoNameIdentifierMappingResponse *response)
{
}

static void
lasso_name_identifier_mapping_response_class_init(LassoNameIdentifierMappingResponseClass *class)
{
}

GType lasso_name_identifier_mapping_response_get_type() {
  static GType this_type = 0;

  if (!this_type) {
    static const GTypeInfo this_info = {
      sizeof (LassoNameIdentifierMappingResponseClass),
      NULL,
      NULL,
      (GClassInitFunc) lasso_name_identifier_mapping_response_class_init,
      NULL,
      NULL,
      sizeof(LassoNameIdentifierMappingResponse),
      0,
      (GInstanceInitFunc) lasso_name_identifier_mapping_response_instance_init,
    };
    
    this_type = g_type_register_static(LASSO_TYPE_LIB_NAME_IDENTIFIER_MAPPING_RESPONSE,
				       "LassoNameIdentifierMappingResponse",
				       &this_info, 0);
  }
  return this_type;
}

LassoNode*
lasso_name_identifier_mapping_response_new(const xmlChar *providerID,
					   const xmlChar *statusCodeValue,
					   LassoNode     *request)
{
  /* FIXME : change request type */
  LassoNode *response, *ss, *ssc;
  xmlChar *inResponseTo, *request_providerID;
  xmlChar *id, *time;

  response = LASSO_NODE(g_object_new(LASSO_TYPE_NAME_IDENTIFIER_MAPPING_RESPONSE, NULL));
  
  /* Set ONLY required elements/attributes */
  /* ResponseID */
  id = lasso_build_unique_id(32);
  lasso_samlp_response_abstract_set_responseID(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
					       (const xmlChar *)id);
  xmlFree(id);
  /* MajorVersion */
  lasso_samlp_response_abstract_set_majorVersion(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
						 lassoLibMajorVersion);
  /* MinorVersion */
  lasso_samlp_response_abstract_set_minorVersion(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
						 lassoLibMinorVersion);
  /* IssueInstant */
  time = lasso_get_current_time();
  lasso_samlp_response_abstract_set_issueInstant(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
						 (const xmlChar *)time);
  xmlFree(time);
  /* ProviderID */
  lasso_lib_name_identifier_mapping_response_set_providerID(LASSO_LIB_NAME_IDENTIFIER_MAPPING_RESPONSE(response),
							    providerID);

  inResponseTo = lasso_node_get_attr_value(request, "RequestID", NULL);
  lasso_samlp_response_abstract_set_inResponseTo(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
						 inResponseTo);
  xmlFree(inResponseTo);

  request_providerID = lasso_node_get_child_content(request, "ProviderID", NULL, NULL);
  lasso_samlp_response_abstract_set_recipient(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
					      request_providerID);
  xmlFree(request_providerID);

  ss = lasso_samlp_status_new();
  ssc = lasso_samlp_status_code_new();
  lasso_samlp_status_code_set_value(LASSO_SAMLP_STATUS_CODE(ssc),
				    statusCodeValue);
  lasso_samlp_status_set_statusCode(LASSO_SAMLP_STATUS(ss),
				    LASSO_SAMLP_STATUS_CODE(ssc));

  lasso_lib_name_identifier_mapping_response_set_status(LASSO_LIB_NAME_IDENTIFIER_MAPPING_RESPONSE(response),
							LASSO_SAMLP_STATUS(ss));
  lasso_node_destroy(ssc);
  lasso_node_destroy(ss);

  return response;
}

LassoNode *
lasso_name_identifier_mapping_response_new_from_dump(const gchar *buffer)
{
  LassoNode *response;
  
  response = LASSO_NODE(g_object_new(LASSO_TYPE_NAME_IDENTIFIER_MAPPING_RESPONSE, NULL));
  lasso_node_import(response, buffer);
  
  return response;
}

/* build a NameIdentifierMappingResponse from a query form NameIdentifierMappingResponse */
LassoNode *
lasso_name_identifier_mapping_response_new_from_query(const gchar *query)
{
  LassoNode *response;
  GData *gd;
  
  response = LASSO_NODE(g_object_new(LASSO_TYPE_NAME_IDENTIFIER_MAPPING_RESPONSE, NULL));

  gd = lasso_query_to_dict(query);
  
  /* ResponseID */
  lasso_samlp_response_abstract_set_responseID(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
					       lasso_g_ptr_array_index((GPtrArray *)g_datalist_get_data(&gd, "ResponseID"), 0));
  
  /* MajorVersion */
  lasso_samlp_response_abstract_set_majorVersion(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
						 lasso_g_ptr_array_index((GPtrArray *)g_datalist_get_data(&gd, "MajorVersion"), 0));
  
  /* MinorVersion */
  lasso_samlp_response_abstract_set_minorVersion(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
						 lasso_g_ptr_array_index((GPtrArray *)g_datalist_get_data(&gd, "MinorVersion"), 0));
  
  /* IssueInstant */
  lasso_samlp_response_abstract_set_issueInstant(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
						 lasso_g_ptr_array_index((GPtrArray *)g_datalist_get_data(&gd, "IssueInstant"), 0));
  
  /* InResponseTo */
  lasso_samlp_response_abstract_set_inResponseTo(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
						 lasso_g_ptr_array_index((GPtrArray *)g_datalist_get_data(&gd, "InResponseTo"), 0));
  
  /* Recipient */
  lasso_samlp_response_abstract_set_recipient(LASSO_SAMLP_RESPONSE_ABSTRACT(response),
					      lasso_g_ptr_array_index((GPtrArray *)g_datalist_get_data(&gd, "Recipient"), 0));
  
  /* ProviderID */
  lasso_lib_name_identifier_mapping_response_set_providerID(LASSO_LIB_NAME_IDENTIFIER_MAPPING_RESPONSE(response),
							  lasso_g_ptr_array_index((GPtrArray *)g_datalist_get_data(&gd, "ProviderID"), 0));


  g_datalist_clear(&gd);

  return response;
}

/* build a NameIdentifierMappingRespose from a soap form NameIdentifierMappingRequest */
LassoNode *
lasso_name_identifier_mapping_response_new_from_request_soap(const gchar   *buffer,
							     const xmlChar *providerID,
							     const xmlChar *statusCodeValue)
{
  LassoNode *request, *response;

  request = lasso_name_identifier_mapping_request_new_from_soap(buffer);

  response = lasso_name_identifier_mapping_response_new(providerID,
							statusCodeValue,
							request);
  lasso_node_destroy(request);

  return response;
}

LassoNode *
lasso_name_identifier_mapping_response_new_from_soap(const gchar *buffer)
{
  LassoNode *response;
  LassoNode *envelope, *lassoNode_response;
  xmlNodePtr xmlNode_response;
  LassoNodeClass *class;

  response = LASSO_NODE(g_object_new(LASSO_TYPE_NAME_IDENTIFIER_MAPPING_RESPONSE, NULL));

  envelope = lasso_node_new_from_dump(buffer);
  lassoNode_response = lasso_node_get_child(envelope, "NameIdentifierMappingResponse",
					    lassoLibHRef, NULL);
     
  class = LASSO_NODE_GET_CLASS(lassoNode_response);
  xmlNode_response = xmlCopyNode(class->get_xmlNode(LASSO_NODE(lassoNode_response)), 1);
  lasso_node_destroy(lassoNode_response);

  class = LASSO_NODE_GET_CLASS(response);
  class->set_xmlNode(LASSO_NODE(response), xmlNode_response);
  lasso_node_destroy(envelope);
  
  return response;
}

/* build a NameIdentifierMappingResponse from a query form NameIdentifierMappingRequest */
LassoNode *
lasso_name_identifier_mapping_response_new_from_request_query(const gchar   *query,
							      const xmlChar *providerID,
							      const xmlChar *statusCodeValue)
{
  LassoNode *request, *response;

  request = lasso_name_identifier_mapping_request_new_from_query(query);
  
  response = lasso_name_identifier_mapping_response_new(providerID,
							statusCodeValue,
							request);
  lasso_node_destroy(request);

  return response;
}
