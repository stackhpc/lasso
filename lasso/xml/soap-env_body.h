/* $Id: soap-env_body.h,v 1.2 2004/05/05 12:56:17 nclapies Exp $ 
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004 Entr'ouvert
 * http://lasso.entrouvert.org
 * 
 * Author: Valery Febvre <vfebvre@easter-eggs.com>
 *         Nicolas Clapies <nclapies@entrouvert.com>
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

#ifndef __LASSO_SOAP_ENV_BODY_H__
#define __LASSO_SOAP_ENV_BODY_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>

#define LASSO_TYPE_SOAP_ENV_BODY (lasso_soap_env_body_get_type())
#define LASSO_SOAP_ENV_BODY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SOAP_ENV_BODY, LassoSoapEnvBody))
#define LASSO_SOAP_ENV_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SOAP_ENV_BODY, LassoSoapEnvBodyClass))
#define LASSO_IS_SOAP_ENV_BODY(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SOAP_ENV_BODY))
#define LASSO_IS_SOAP_ENV_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SOAP_ENV_BODY))
#define LASSO_SOAP_ENV_BODY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SOAP_ENV_BODY, LassoSoapEnvBodyClass))

typedef struct _LassoSoapEnvBody LassoSoapEnvBody;
typedef struct _LassoSoapEnvBodyClass LassoSoapEnvBodyClass;

struct _LassoSoapEnvBody {
  LassoNode parent;
  /*< private >*/
};

struct _LassoSoapEnvBodyClass {
  LassoNodeClass parent;
  /*< vtable >*/
};

LASSO_EXPORT GType lasso_soap_env_body_get_type(void);
LASSO_EXPORT LassoNode* lasso_soap_env_body_new(void);

LASSO_EXPORT void lasso_soap_env_body_add_child(LassoSoapEnvBody *body, LassoNode *node);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SOAP_ENV_BODY_H__ */
