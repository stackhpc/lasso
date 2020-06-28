/* $Id: login.h,v 1.56 2006/12/05 17:16:54 nclapies Exp $ 
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

#ifndef __LASSO_LOGIN_H__
#define __LASSO_LOGIN_H__

#ifdef __cplusplus
extern "C" {

#endif /* __cplusplus */ 

#include <lasso/lasso_config.h>

#ifdef LASSO_WSF_ENABLED
#include <lasso/xml/disco_encrypted_resource_id.h>
#else
typedef void LassoDiscoEncryptedResourceID;
typedef void LassoDiscoResourceID;
#endif

#include <lasso/xml/lib_authn_request.h>
#include <lasso/xml/lib_authn_response.h>
#include <lasso/xml/samlp_request.h>
#include <lasso/xml/samlp_response.h>

#include <lasso/id-ff/profile.h>

#define LASSO_TYPE_LOGIN (lasso_login_get_type())
#define LASSO_LOGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_LOGIN, LassoLogin))
#define LASSO_LOGIN_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_LOGIN, LassoLoginClass))
#define LASSO_IS_LOGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_LOGIN))
#define LASSO_IS_LOGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_LOGIN))
#define LASSO_LOGIN_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_LOGIN, LassoLoginClass)) 

typedef struct _LassoLogin LassoLogin;
typedef struct _LassoLoginClass LassoLoginClass;
typedef struct _LassoLoginPrivate LassoLoginPrivate;

typedef enum {
	LASSO_LOGIN_PROTOCOL_PROFILE_BRWS_ART = 1,
	LASSO_LOGIN_PROTOCOL_PROFILE_BRWS_POST,
	LASSO_LOGIN_PROTOCOL_PROFILE_BRWS_LECP,
} LassoLoginProtocolProfile;

struct _LassoLogin {
	LassoProfile parent;

	/*< public >*/
	LassoLoginProtocolProfile protocolProfile;
	gchar *assertionArtifact;
	LassoSamlAssertion *assertion;

	/*< private >*/
	gchar *nameIDPolicy;
	LassoHttpMethod http_method;

	LassoLoginPrivate *private_data;
};

struct _LassoLoginClass {
	LassoProfileClass parent;
};

LASSO_EXPORT GType lasso_login_get_type(void);
LASSO_EXPORT LassoLogin* lasso_login_new(LassoServer *server);
LASSO_EXPORT LassoLogin* lasso_login_new_from_dump(LassoServer *server, const gchar *dump);
LASSO_EXPORT gint lasso_login_accept_sso(LassoLogin *login);

LASSO_EXPORT gint lasso_login_build_artifact_msg(LassoLogin *login, LassoHttpMethod http_method);

LASSO_EXPORT int lasso_login_build_assertion(LassoLogin *login,
		const char *authenticationMethod, const char *authenticationInstant,
		const char *reauthenticateOnOrAfter,
		const char *notBefore, const char *notOnOrAfter);

LASSO_EXPORT gint lasso_login_build_authn_request_msg(LassoLogin *login);

LASSO_EXPORT gint lasso_login_build_authn_response_msg(LassoLogin *login);

LASSO_EXPORT gint lasso_login_build_request_msg(LassoLogin *login);
LASSO_EXPORT gint lasso_login_build_response_msg(LassoLogin *login, gchar *remote_providerID);
LASSO_EXPORT void lasso_login_destroy(LassoLogin *login);
LASSO_EXPORT gchar* lasso_login_dump(LassoLogin *login);
LASSO_EXPORT gint lasso_login_init_authn_request(LassoLogin *login,
		const gchar *remote_providerID, LassoHttpMethod http_method);

LASSO_EXPORT gint lasso_login_init_request(LassoLogin *login, gchar *response_msg,
		LassoHttpMethod response_http_method);

LASSO_EXPORT gint lasso_login_init_idp_initiated_authn_request(LassoLogin *login,
		const gchar *remote_providerID);

LASSO_EXPORT gboolean lasso_login_must_ask_for_consent(LassoLogin *login);
LASSO_EXPORT gboolean lasso_login_must_authenticate(LassoLogin *login);

LASSO_EXPORT int lasso_login_process_authn_request_msg(LassoLogin *login,
		const char *authn_request_msg);

LASSO_EXPORT gint lasso_login_process_authn_response_msg(LassoLogin *login,
		gchar *authn_response_msg);

LASSO_EXPORT gint lasso_login_process_request_msg(LassoLogin *login, gchar *request_msg);
LASSO_EXPORT gint lasso_login_process_response_msg(LassoLogin *login, gchar *response_msg);

LASSO_EXPORT int lasso_login_set_encryptedResourceId(
		LassoLogin *login, LassoDiscoEncryptedResourceID *encryptedResourceId);

LASSO_EXPORT int lasso_login_set_resourceId(LassoLogin *login, const char *content);

LASSO_EXPORT int lasso_login_validate_request_msg(LassoLogin *login,
		gboolean authentication_result, gboolean is_consent_obtained);

LASSO_EXPORT int lasso_login_process_paos_response_msg(LassoLogin *login, gchar *msg);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_LOGIN_H__ */
