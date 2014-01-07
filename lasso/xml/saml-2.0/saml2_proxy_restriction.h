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

#ifndef __LASSO_SAML2_PROXY_RESTRICTION_H__
#define __LASSO_SAML2_PROXY_RESTRICTION_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "saml2_condition_abstract.h"

#define LASSO_TYPE_SAML2_PROXY_RESTRICTION (lasso_saml2_proxy_restriction_get_type())
#define LASSO_SAML2_PROXY_RESTRICTION(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAML2_PROXY_RESTRICTION, \
				LassoSaml2ProxyRestriction))
#define LASSO_SAML2_PROXY_RESTRICTION_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAML2_PROXY_RESTRICTION, \
				LassoSaml2ProxyRestrictionClass))
#define LASSO_IS_SAML2_PROXY_RESTRICTION(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAML2_PROXY_RESTRICTION))
#define LASSO_IS_SAML2_PROXY_RESTRICTION_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAML2_PROXY_RESTRICTION))
#define LASSO_SAML2_PROXY_RESTRICTION_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAML2_PROXY_RESTRICTION, \
				LassoSaml2ProxyRestrictionClass))

typedef struct _LassoSaml2ProxyRestriction LassoSaml2ProxyRestriction;
typedef struct _LassoSaml2ProxyRestrictionClass LassoSaml2ProxyRestrictionClass;


struct _LassoSaml2ProxyRestriction {
	LassoSaml2ConditionAbstract parent;

	/*< public >*/
	/* elements */
	char *Audience;
	/* attributes */
	char *Count;
};


struct _LassoSaml2ProxyRestrictionClass {
	LassoSaml2ConditionAbstractClass parent;
};

LASSO_EXPORT GType lasso_saml2_proxy_restriction_get_type(void);
LASSO_EXPORT LassoNode* lasso_saml2_proxy_restriction_new(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAML2_PROXY_RESTRICTION_H__ */
