/* $Id: lib_logout_response.h,v 1.7 2005/01/22 15:57:55 eraviart Exp $ 
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004, 2005 Entr'ouvert
 * http://lasso.entrouvert.org
 * 
 * Authors: See AUTHORS file in top-level directory.
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

#ifndef __LASSO_LIB_LOGOUT_RESPONSE_H__
#define __LASSO_LIB_LOGOUT_RESPONSE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/lib_status_response.h>
#include <lasso/xml/lib_logout_request.h>

#define LASSO_TYPE_LIB_LOGOUT_RESPONSE (lasso_lib_logout_response_get_type())
#define LASSO_LIB_LOGOUT_RESPONSE(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_LIB_LOGOUT_RESPONSE, LassoLibLogoutResponse))
#define LASSO_LIB_LOGOUT_RESPONSE_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_LIB_LOGOUT_RESPONSE, \
				 LassoLibLogoutResponseClass))
#define LASSO_IS_LIB_LOGOUT_RESPONSE(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_LIB_LOGOUT_RESPONSE))
#define LASSO_IS_LIB_LOGOUT_RESPONSE_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_LIB_LOGOUT_RESPONSE))
#define LASSO_LIB_LOGOUT_RESPONSE_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_LIB_LOGOUT_RESPONSE, \
				    LassoLibLogoutResponseClass)) 

typedef struct _LassoLibLogoutResponse LassoLibLogoutResponse;
typedef struct _LassoLibLogoutResponseClass LassoLibLogoutResponseClass;

struct _LassoLibLogoutResponse {
	LassoLibStatusResponse parent;
};

struct _LassoLibLogoutResponseClass {
	LassoLibStatusResponseClass parent;
};

LASSO_EXPORT GType lasso_lib_logout_response_get_type(void);
LASSO_EXPORT LassoSamlpResponseAbstract* lasso_lib_logout_response_new(void);

LASSO_EXPORT LassoSamlpResponseAbstract* lasso_lib_logout_response_new_full(
		char *providerID, const char *statusCodeValue,
		LassoLibLogoutRequest *request,
		LassoSignatureType sign_type, LassoSignatureMethod sign_method);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_LIB_LOGOUT_RESPONSE_H__ */
