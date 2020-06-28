/* $Id: register_name_identifier_response.h,v 1.7 2004/08/04 01:19:34 valos Exp $ 
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

#ifndef __LASSO_REGISTER_NAME_IDENTIFIER_RESPONSE_H__
#define __LASSO_REGISTER_NAME_IDENTIFIER_RESPONSE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/protocols/register_name_identifier_request.h>
#include <lasso/xml/lib_register_name_identifier_response.h>

#define LASSO_TYPE_REGISTER_NAME_IDENTIFIER_RESPONSE (lasso_register_name_identifier_response_get_type())
#define LASSO_REGISTER_NAME_IDENTIFIER_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_REGISTER_NAME_IDENTIFIER_RESPONSE, LassoRegisterNameIdentifierResponse))
#define LASSO_REGISTER_NAME_IDENTIFIER_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_REGISTER_NAME_IDENTIFIER_RESPONSE, LassoRegisterNameIdentifierResponseClass))
#define LASSO_IS_REGISTER_NAME_IDENTIFIER_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_REGISTER_NAME_IDENTIFIER_RESPONSE))
#define LASSO_IS_REGISTER_NAME_IDENTIFIER_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_REGISTER_NAME_IDENTIFIER_RESPONSE))
#define LASSO_REGISTER_NAME_IDENTIFIER_RESPONSE_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_REGISTER_NAME_IDENTIFIER_RESPONSE, LassoRegisterNameIdentifierResponseClass)) 

typedef struct _LassoRegisterNameIdentifierResponse LassoRegisterNameIdentifierResponse;
typedef struct _LassoRegisterNameIdentifierResponseClass LassoRegisterNameIdentifierResponseClass;

struct _LassoRegisterNameIdentifierResponse {
  LassoLibRegisterNameIdentifierResponse parent;
  /*< public >*/
  /*< private >*/
};

struct _LassoRegisterNameIdentifierResponseClass {
  LassoLibRegisterNameIdentifierResponseClass parent;
};

LASSO_EXPORT GType       lasso_register_name_identifier_response_get_type                (void);

LASSO_EXPORT LassoNode*  lasso_register_name_identifier_response_new                     (gchar     *providerID,
											  gchar     *statusCodeValue,
											  LassoNode *request);

LASSO_EXPORT LassoNode*  lasso_register_name_identifier_response_new_from_export         (gchar               *buffer,
											  lassoNodeExportType  export_type);

LASSO_EXPORT LassoNode*  lasso_register_name_identifier_response_new_from_request_export (gchar               *buffer,
											  lassoNodeExportType  export_type,
											  gchar               *providerID,
											  gchar               *statusCodeValue);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_REGISTER_NAME_IDENTIFIER_RESPONSE_H__ */
