/* $Id: identity.h,v 1.7 2004/07/30 14:22:57 valos Exp $
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

#ifndef __LASSO_IDENTITY_H__
#define __LASSO_IDENTITY_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>
#include <lasso/protocols/federation.h>

#define LASSO_TYPE_IDENTITY (lasso_identity_get_type())
#define LASSO_IDENTITY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_IDENTITY, LassoIdentity))
#define LASSO_IDENTITY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_IDENTITY, LassoIdentityClass))
#define LASSO_IS_IDENTITY(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_IDENTITY))
#define LASSO_IS_IDENTITY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_IDENTITY))
#define LASSO_IDENTITY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_IDENTITY, LassoIdentityClass)) 

typedef struct _LassoIdentity LassoIdentity;
typedef struct _LassoIdentityClass LassoIdentityClass;
typedef struct _LassoIdentityPrivate LassoIdentityPrivate;

struct _LassoIdentity {
  GObject parent;

  /*< public >*/
  GPtrArray  *providerIDs; /* list of the remote provider ids for federations hash table */
  GHashTable *federations; /* hash for federations with remote ProviderID as key */

  gboolean is_dirty;

  /*< private >*/
  LassoIdentityPrivate *private;
};

struct _LassoIdentityClass {
  GObjectClass parent;
};

LASSO_EXPORT GType            lasso_identity_get_type                              (void);

LASSO_EXPORT LassoIdentity*   lasso_identity_new                                   (void);

LASSO_EXPORT LassoIdentity*   lasso_identity_new_from_dump                         (gchar *dump);

LASSO_EXPORT gint             lasso_identity_add_federation                        (LassoIdentity   *identity,
										    gchar           *remote_providerID,
										    LassoFederation *federation);

LASSO_EXPORT LassoIdentity*   lasso_identity_copy                                  (LassoIdentity *identity);

LASSO_EXPORT void             lasso_identity_destroy                               (LassoIdentity *identity);

LASSO_EXPORT gchar*           lasso_identity_dump                                  (LassoIdentity *identity);

LASSO_EXPORT LassoFederation* lasso_identity_get_federation                        (LassoIdentity *identity,
										    gchar         *remote_providerID);

LASSO_EXPORT gchar*           lasso_identity_get_next_federation_remote_providerID (LassoIdentity *identity);

LASSO_EXPORT gint             lasso_identity_remove_federation                     (LassoIdentity *identity,
										    gchar         *remote_providerID);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_IDENTITY_H__ */
