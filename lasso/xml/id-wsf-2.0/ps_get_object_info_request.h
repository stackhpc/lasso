/* $Id: ps_get_object_info_request.h,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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

#ifndef __LASSO_IDWSF2_PS_GET_OBJECT_INFO_REQUEST_H__
#define __LASSO_IDWSF2_PS_GET_OBJECT_INFO_REQUEST_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../xml.h"
#include "subs_subscription.h"
#include "ps_request_abstract.h"

#define LASSO_TYPE_IDWSF2_PS_GET_OBJECT_INFO_REQUEST \
	(lasso_idwsf2_ps_get_object_info_request_get_type())
#define LASSO_IDWSF2_PS_GET_OBJECT_INFO_REQUEST(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), \
		LASSO_TYPE_IDWSF2_PS_GET_OBJECT_INFO_REQUEST, \
		LassoIdWsf2PsGetObjectInfoRequest))
#define LASSO_IDWSF2_PS_GET_OBJECT_INFO_REQUEST_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), \
		LASSO_TYPE_IDWSF2_PS_GET_OBJECT_INFO_REQUEST, \
		LassoIdWsf2PsGetObjectInfoRequestClass))
#define LASSO_IS_IDWSF2_PS_GET_OBJECT_INFO_REQUEST(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), \
		LASSO_TYPE_IDWSF2_PS_GET_OBJECT_INFO_REQUEST))
#define LASSO_IS_IDWSF2_PS_GET_OBJECT_INFO_REQUEST_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), \
		LASSO_TYPE_IDWSF2_PS_GET_OBJECT_INFO_REQUEST))
#define LASSO_IDWSF2_PS_GET_OBJECT_INFO_REQUEST_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), \
		LASSO_TYPE_IDWSF2_PS_GET_OBJECT_INFO_REQUEST, \
		LassoIdWsf2PsGetObjectInfoRequestClass))


typedef struct _LassoIdWsf2PsGetObjectInfoRequest LassoIdWsf2PsGetObjectInfoRequest;
typedef struct _LassoIdWsf2PsGetObjectInfoRequestClass LassoIdWsf2PsGetObjectInfoRequestClass;


struct _LassoIdWsf2PsGetObjectInfoRequest {
	LassoIdWsf2PsRequestAbstract parent;

	/*< public >*/
	/* elements */
	/* XXX */ void *TargetObjectID;
	/* XXX */ void *Subscription;
};


struct _LassoIdWsf2PsGetObjectInfoRequestClass {
	LassoIdWsf2PsRequestAbstractClass parent;
};

LASSO_EXPORT GType lasso_idwsf2_ps_get_object_info_request_get_type(void);
LASSO_EXPORT LassoIdWsf2PsGetObjectInfoRequest* lasso_idwsf2_ps_get_object_info_request_new(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_IDWSF2_PS_GET_OBJECT_INFO_REQUEST_H__ */