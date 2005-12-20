/* $Id: defederation.h,v 1.3 2004/08/26 16:07:56 nclapies Exp $ 
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

#ifndef __LASSO_DEFEDERATION_H__
#define __LASSO_DEFEDERATION_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/environs/profile.h>
#include <lasso/protocols/federation_termination_notification.h>

#define LASSO_TYPE_DEFEDERATION (lasso_defederation_get_type())
#define LASSO_DEFEDERATION(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_DEFEDERATION, LassoDefederation))
#define LASSO_DEFEDERATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_DEFEDERATION, LassoDefederationClass))
#define LASSO_IS_DEFEDERATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_DEFEDERATION))
#define LASSO_IS_DEFEDERATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_DEFEDERATION))
#define LASSO_DEFEDERATION_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_DEFEDERATION, LassoDefederationClass)) 

typedef struct _LassoDefederation LassoDefederation;
typedef struct _LassoDefederationClass LassoDefederationClass;
typedef struct _LassoDefederationPrivate LassoDefederationPrivate;

struct _LassoDefederation {
  LassoProfile parent;

  /*< private >*/

  LassoDefederationPrivate *private;
};

struct _LassoDefederationClass {
  LassoProfileClass parent;

};

LASSO_EXPORT GType              lasso_defederation_get_type (void);

LASSO_EXPORT LassoDefederation *lasso_defederation_new      (LassoServer       *server,
							     lassoProviderType  provider_type);
  

LASSO_EXPORT gint lasso_defederation_build_notification_msg   (LassoDefederation *defederation);

LASSO_EXPORT void lasso_defederation_destroy                  (LassoDefederation *defederation);

LASSO_EXPORT gint lasso_defederation_init_notification        (LassoDefederation *defederation,
							       gchar             *remote_providerID,
							       lassoHttpMethod    notification_method);

LASSO_EXPORT gint lasso_defederation_process_notification_msg (LassoDefederation *defederation,
							       gchar             *notification_msg,
							       lassoHttpMethod     notification_method);
  
LASSO_EXPORT gint lasso_defederation_validate_notification    (LassoDefederation *defederation);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_DEFEDERATION_H__ */
