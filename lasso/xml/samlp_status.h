/* $Id: samlp_status.h,v 1.2 2004/07/22 06:59:03 eraviart Exp $
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

#ifndef __LASSO_SAMLP_STATUS_H__
#define __LASSO_SAMLP_STATUS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>
#include <lasso/xml/samlp_status_code.h>

#define LASSO_TYPE_SAMLP_STATUS (lasso_samlp_status_get_type())
#define LASSO_SAMLP_STATUS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAMLP_STATUS, LassoSamlpStatus))
#define LASSO_SAMLP_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAMLP_STATUS, LassoSamlpStatusClass))
#define LASSO_IS_SAMLP_STATUS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAMLP_STATUS))
#define LASSO_IS_SAMLP_STATUS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAMLP_STATUS))
#define LASSO_SAMLP_STATUS_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAMLP_STATUS, LassoSamlpStatusClass)) 

typedef struct _LassoSamlpStatus LassoSamlpStatus;
typedef struct _LassoSamlpStatusClass LassoSamlpStatusClass;

struct _LassoSamlpStatus {
  LassoNode parent;
  /*< private >*/
};

struct _LassoSamlpStatusClass {
  LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_samlp_status_get_type(void);
LASSO_EXPORT LassoNode* lasso_samlp_status_new(void);

LASSO_EXPORT void lasso_samlp_status_set_statusCode    (LassoSamlpStatus *node,
							LassoSamlpStatusCode *statusCode);

/* TODO
LASSO_EXPORT void lasso_samlp_status_set_statusDetail(LassoSamlpStatus *node,
LassoSamlpStatusDetail *statusDetail);
*/

LASSO_EXPORT void lasso_samlp_status_set_statusMessage  (LassoSamlpStatus *node,
							 const xmlChar *statusMessage);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAMLP_STATUS_H__ */
