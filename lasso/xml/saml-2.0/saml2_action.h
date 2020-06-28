/* $Id$
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004-2007 Entr'ouvert
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LASSO_SAML2_ACTION_H__
#define __LASSO_SAML2_ACTION_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../xml.h"

#define LASSO_TYPE_SAML2_ACTION (lasso_saml2_action_get_type())
#define LASSO_SAML2_ACTION(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAML2_ACTION, \
				LassoSaml2Action))
#define LASSO_SAML2_ACTION_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAML2_ACTION, \
				LassoSaml2ActionClass))
#define LASSO_IS_SAML2_ACTION(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAML2_ACTION))
#define LASSO_IS_SAML2_ACTION_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAML2_ACTION))
#define LASSO_SAML2_ACTION_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAML2_ACTION, \
				LassoSaml2ActionClass))

typedef struct _LassoSaml2Action LassoSaml2Action;
typedef struct _LassoSaml2ActionClass LassoSaml2ActionClass;


struct _LassoSaml2Action {
	LassoNode parent;

	/*< public >*/
	/* elements */
	char *content;
	/* attributes */
	char *Namespace;
};


struct _LassoSaml2ActionClass {
	LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_saml2_action_get_type(void);
LASSO_EXPORT LassoNode* lasso_saml2_action_new(void);

LASSO_EXPORT LassoNode* lasso_saml2_action_new_with_string(char *content);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAML2_ACTION_H__ */
