/* $Id: lib_name_identifier_mapping_request.h,v 1.2 2004/07/22 06:59:03 eraviart Exp $ 
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

#ifndef __LASSO_LIB_NAME_IDENTIFIER_MAPPING_REQUEST_H__
#define __LASSO_LIB_NAME_IDENTIFIER_MAPPING_REQUEST_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/saml_name_identifier.h>
#include <lasso/xml/samlp_request_abstract.h>

#define LASSO_TYPE_LIB_NAME_IDENTIFIER_MAPPING_REQUEST (lasso_lib_name_identifier_mapping_request_get_type())
#define LASSO_LIB_NAME_IDENTIFIER_MAPPING_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_LIB_NAME_IDENTIFIER_MAPPING_REQUEST, LassoLibNameIdentifierMappingRequest))
#define LASSO_LIB_NAME_IDENTIFIER_MAPPING_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_LIB_NAME_IDENTIFIER_MAPPING_REQUEST, LassoLibNameIdentifierMappingRequestClass))
#define LASSO_IS_LIB_NAME_IDENTIFIER_MAPPING_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_LIB_NAME_IDENTIFIER_MAPPING_REQUEST))
#define LASSO_IS_LIB_NAME_IDENTIFIER_MAPPING_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_LIB_NAME_IDENTIFIER_MAPPING_REQUEST))
#define LASSO_LIB_NAME_IDENTIFIER_MAPPING_REQUEST_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_LIB_NAME_IDENTIFIER_MAPPING_REQUEST, LassoLibNameIdentifierMappingRequestClass)) 

typedef struct _LassoLibNameIdentifierMappingRequest LassoLibNameIdentifierMappingRequest;
typedef struct _LassoLibNameIdentifierMappingRequestClass LassoLibNameIdentifierMappingRequestClass;

struct _LassoLibNameIdentifierMappingRequest {
  LassoSamlpRequestAbstract parent;
  /*< private >*/
};

struct _LassoLibNameIdentifierMappingRequestClass {
  LassoSamlpRequestAbstractClass parent;
};

LASSO_EXPORT GType lasso_lib_name_identifier_mapping_request_get_type(void);
LASSO_EXPORT LassoNode* lasso_lib_name_identifier_mapping_request_new(void);

LASSO_EXPORT void lasso_lib_name_identifier_mapping_request_set_consent        (LassoLibNameIdentifierMappingRequest *,
										const xmlChar *);

LASSO_EXPORT void lasso_lib_name_identifier_mapping_request_set_providerID     (LassoLibNameIdentifierMappingRequest *,
										const xmlChar *);

LASSO_EXPORT void lasso_lib_name_identifier_mapping_request_set_nameIdentifier (LassoLibNameIdentifierMappingRequest *,
										LassoSamlNameIdentifier *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_LIB_NAME_IDENTIFIER_MAPPING_REQUEST_H__ */
