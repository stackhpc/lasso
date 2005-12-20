/* $Id: name_registration.h,v 1.1 2004/08/26 15:32:48 nclapies Exp $ 
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

#ifndef __LASSO_NAME_REGISTRATION_H__
#define __LASSO_NAME_REGISTRATION_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/environs/profile.h>

#include <lasso/protocols/register_name_identifier_request.h>
#include <lasso/protocols/register_name_identifier_response.h>

#define LASSO_TYPE_NAME_REGISTRATION (lasso_name_registration_get_type())
#define LASSO_NAME_REGISTRATION(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_NAME_REGISTRATION, LassoNameRegistration))
#define LASSO_NAME_REGISTRATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_NAME_REGISTRATION, LassoNameRegistrationClass))
#define LASSO_IS_NAME_REGISTRATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_NAME_REGISTRATION))
#define LASSO_IS_NAME_REGISTRATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_NAME_REGISTRATION))
#define LASSO_NAME_REGISTRATION_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_NAME_REGISTRATION, LassoNameRegistrationClass)) 

typedef struct _LassoNameRegistration LassoNameRegistration;
typedef struct _LassoNameRegistrationClass LassoNameRegistrationClass;

struct _LassoNameRegistration {
  LassoProfile parent;

  /*< private >*/
};

struct _LassoNameRegistrationClass {
  LassoProfileClass parent;

};

LASSO_EXPORT GType                        lasso_name_registration_get_type (void);

LASSO_EXPORT LassoNameRegistration* lasso_name_registration_new      (LassoServer       *server,
								      lassoProviderType  provider_type);

LASSO_EXPORT gint            lasso_name_registration_build_request_msg    (LassoNameRegistration *name_registration);

LASSO_EXPORT gint            lasso_name_registration_build_response_msg   (LassoNameRegistration *name_registration);

LASSO_EXPORT void            lasso_name_registration_destroy              (LassoNameRegistration *name_registration);

LASSO_EXPORT gint            lasso_name_registration_init_request         (LassoNameRegistration *name_registration,
									   gchar                 *remote_providerID);

LASSO_EXPORT gint            lasso_name_registration_process_request_msg  (LassoNameRegistration *name_registration,
									   gchar                 *request_msg,
									   lassoHttpMethod        request_method);

LASSO_EXPORT gint            lasso_name_registration_validate_request     (LassoNameRegistration *name_registration);

LASSO_EXPORT gint            lasso_name_registration_process_response_msg (LassoNameRegistration *name_registration,
									   gchar                 *response_msg,
									   lassoHttpMethod        response_method);
  
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_NAME_REGISTRATION_H__ */
