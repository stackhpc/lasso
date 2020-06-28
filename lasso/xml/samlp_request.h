/* $Id: samlp_request.h,v 1.3 2004/07/22 10:17:43 fpeters Exp $ 
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

#ifndef __LASSO_SAMLP_REQUEST_H__
#define __LASSO_SAMLP_REQUEST_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/samlp_request_abstract.h>

#define LASSO_TYPE_SAMLP_REQUEST (lasso_samlp_request_get_type())
#define LASSO_SAMLP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAMLP_REQUEST, LassoSamlpRequest))
#define LASSO_SAMLP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAMLP_REQUEST, LassoSamlpRequestClass))
#define LASSO_IS_SAMLP_REQUEST(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAMLP_REQUEST))
#define LASSO_IS_SAMLP_REQUEST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAMLP_REQUEST))
#define LASSO_SAMLP_REQUEST_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAMLP_REQUEST, LassoSamlpRequestClass)) 

typedef struct _LassoSamlpRequest LassoSamlpRequest;
typedef struct _LassoSamlpRequestClass LassoSamlpRequestClass;

struct _LassoSamlpRequest {
  LassoSamlpRequestAbstract parent;
  /*< private >*/
};

struct _LassoSamlpRequestClass {
  LassoSamlpRequestAbstractClass parent;
};

LASSO_EXPORT GType lasso_samlp_request_get_type(void);
LASSO_EXPORT LassoNode* lasso_samlp_request_new(void);

LASSO_EXPORT void lasso_samlp_request_set_assertionArtifact(LassoSamlpRequest *node,
					  const xmlChar *assertionArtifact);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAMLP_REQUEST_H__ */
