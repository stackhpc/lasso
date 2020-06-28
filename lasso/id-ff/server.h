/* $Id: server.h,v 1.45 2005/08/24 14:54:55 fpeters Exp $ 
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

#ifndef __LASSO_SERVER_H__
#define __LASSO_SERVER_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/lasso_config.h>

#ifdef LASSO_WSF_ENABLED
#include <lasso/xml/disco_service_instance.h>
#else
typedef void LassoDiscoServiceInstance;
#endif
#include <lasso/id-ff/provider.h>


#define LASSO_TYPE_SERVER (lasso_server_get_type())
#define LASSO_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SERVER, LassoServer))
#define LASSO_SERVER_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SERVER, LassoServerClass))
#define LASSO_IS_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SERVER))
#define LASSO_IS_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SERVER))
#define LASSO_SERVER_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SERVER, LassoServerClass)) 

typedef struct _LassoServer LassoServer;
typedef struct _LassoServerClass LassoServerClass;
typedef struct _LassoServerPrivate LassoServerPrivate;

struct _LassoServer {
	LassoProvider parent;

	/*< public >*/
	GHashTable *providers;
	GHashTable *services;

	gchar *private_key;
	gchar *private_key_password;
	gchar *certificate;
	LassoSignatureMethod signature_method;

	/*< private >*/
	LassoServerPrivate *private_data;
};

struct _LassoServerClass {
	LassoProviderClass parent;
};

LASSO_EXPORT GType lasso_server_get_type(void);

LASSO_EXPORT LassoServer* lasso_server_new(const gchar *metadata,
		const gchar *private_key,
		const gchar *private_key_password,
		const gchar *certificate);

LASSO_EXPORT LassoServer* lasso_server_new_from_dump(const gchar *dump);

LASSO_EXPORT gint lasso_server_add_provider (LassoServer *server,
		LassoProviderRole role, const gchar *metadata,
		const gchar *public_key, const gchar *ca_cert_chain);

LASSO_EXPORT gint lasso_server_add_service(LassoServer *server, LassoDiscoServiceInstance *service);

LASSO_EXPORT void lasso_server_destroy(LassoServer *server);

LASSO_EXPORT gchar* lasso_server_dump(LassoServer *server);

LASSO_EXPORT LassoProvider* lasso_server_get_provider(LassoServer *server, gchar *providerID);

LASSO_EXPORT LassoDiscoServiceInstance* lasso_server_get_service(LassoServer *server,
								 gchar *serviceType);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SERVER_H__ */
