/* $Id: disco_credentials.h,v 1.3 2005/01/22 15:57:55 eraviart Exp $ 
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

#ifndef __LASSO_DISCO_CREDENTIALS_H__
#define __LASSO_DISCO_CREDENTIALS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>

#define LASSO_TYPE_DISCO_CREDENTIALS (lasso_disco_credentials_get_type())
#define LASSO_DISCO_CREDENTIALS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), \
			LASSO_TYPE_DISCO_CREDENTIALS, LassoDiscoCredentials))
#define LASSO_DISCO_CREDENTIALS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), \
			LASSO_TYPE_DISCO_CREDENTIALS, LassoDiscoCredentialsClass))
#define LASSO_IS_DISCO_CREDENTIALS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), \
			LASSO_TYPE_DISCO_CREDENTIALS))
#define LASSO_IS_DISCO_CREDENTIALS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), \
			LASSO_TYPE_DISCO_CREDENTIALS))
#define LASSO_DISCO_CREDENTIALS_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), \
			LASSO_TYPE_DISCO_CREDENTIALS, LassoDiscoCredentialsClass))

typedef struct _LassoDiscoCredentials LassoDiscoCredentials;
typedef struct _LassoDiscoCredentialsClass LassoDiscoCredentialsClass;

struct _LassoDiscoCredentials {
	LassoNode parent;

	GList *any;
};

struct _LassoDiscoCredentialsClass {
	LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_disco_credentials_get_type(void);
LASSO_EXPORT LassoDiscoCredentials* lasso_disco_credentials_new(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_DISCO_CREDENTIALS_H__ */