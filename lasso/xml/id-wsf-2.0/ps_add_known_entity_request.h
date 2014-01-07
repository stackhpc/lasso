/* $Id: ps_add_known_entity_request.h,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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

#ifndef __LASSO_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST_H__
#define __LASSO_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../xml.h"
#include "sec_token_policy.h"
#include "sec_token.h"
#include "ps_object.h"
#include "ps_request_abstract.h"
#include "subs_subscription.h"

#define LASSO_TYPE_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST \
	(lasso_idwsf2_ps_add_known_entity_request_get_type())
#define LASSO_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), \
		LASSO_TYPE_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST, \
		LassoIdWsf2PsAddKnownEntityRequest))
#define LASSO_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), \
		LASSO_TYPE_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST, \
		LassoIdWsf2PsAddKnownEntityRequestClass))
#define LASSO_IS_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), \
		LASSO_TYPE_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST))
#define LASSO_IS_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), \
		LASSO_TYPE_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST))
#define LASSO_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), \
		LASSO_TYPE_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST, \
		LassoIdWsf2PsAddKnownEntityRequestClass))


typedef struct _LassoIdWsf2PsAddKnownEntityRequest LassoIdWsf2PsAddKnownEntityRequest;
typedef struct _LassoIdWsf2PsAddKnownEntityRequestClass LassoIdWsf2PsAddKnownEntityRequestClass;


struct _LassoIdWsf2PsAddKnownEntityRequest {
	LassoIdWsf2PsRequestAbstract parent;

	/*< public >*/
	/* elements */
	/* XXX */ void *Object;
	/* XXX */ void *Token;
	char *CreatePSObject;
	/* XXX */ void *Subscription;
	/* XXX */ void *TokenPolicy;
};


struct _LassoIdWsf2PsAddKnownEntityRequestClass {
	LassoIdWsf2PsRequestAbstractClass parent;
};

LASSO_EXPORT GType lasso_idwsf2_ps_add_known_entity_request_get_type(void);
LASSO_EXPORT LassoIdWsf2PsAddKnownEntityRequest* lasso_idwsf2_ps_add_known_entity_request_new(
	void);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_IDWSF2_PS_ADD_KNOWN_ENTITY_REQUEST_H__ */
