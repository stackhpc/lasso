/* $Id: sa_credentials.h,v 1.1 2005/03/02 17:09:14 nclapies Exp $$
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

#ifndef __LASSO_SA_CREDENTIALS_H__
#define __LASSO_SA_CREDENTIALS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>
#include <lasso/xml/saml_assertion.h>

#define LASSO_TYPE_SA_CREDENTIALS (lasso_sa_credentials_get_type())
#define LASSO_SA_CREDENTIALS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), \
			LASSO_TYPE_SA_CREDENTIALS, LassoSaCredentials))
#define LASSO_SA_CREDENTIALS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), \
			LASSO_TYPE_SA_CREDENTIALS, LassoSaCredentialsClass))
#define LASSO_IS_SA_CREDENTIALS(obj) \
			(G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SA_CREDENTIALS))
#define LASSO_IS_SA_CREDENTIALS_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass),LASSO_TYPE_SA_CREDENTIALS))
#define LASSO_SA_CREDENTIALS_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SA_CREDENTIALS, LassoSaCredentialsClass)) 

typedef struct _LassoSaCredentials LassoSaCredentials;
typedef struct _LassoSaCredentialsClass LassoSaCredentialsClass;

struct _LassoSaCredentials {
	LassoNode parent;

	GList *any;
};

struct _LassoSaCredentialsClass {
	LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_sa_credentials_get_type(void);

LASSO_EXPORT LassoSaCredentials* lasso_sa_credentials_new();

LASSO_EXPORT LassoSaCredentials* lasso_sa_credentials_new_from_message(const gchar *message);

LASSO_EXPORT gint lasso_sa_credentials_add_assertion(LassoSaCredentials *credentials,
						     LassoSamlAssertion *assertion);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SA_CREDENTIALS_H__ */
