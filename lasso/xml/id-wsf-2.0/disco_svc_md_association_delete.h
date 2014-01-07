/* $Id: disco_svc_md_association_delete.h,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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

#ifndef __LASSO_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE_H__
#define __LASSO_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../xml.h"

#define LASSO_TYPE_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE \
	(lasso_idwsf2_disco_svc_md_association_delete_get_type())
#define LASSO_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), \
		LASSO_TYPE_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE, \
		LassoIdWsf2DiscoSvcMDAssociationDelete))
#define LASSO_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), \
		LASSO_TYPE_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE, \
		LassoIdWsf2DiscoSvcMDAssociationDeleteClass))
#define LASSO_IS_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), \
		LASSO_TYPE_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE))
#define LASSO_IS_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), \
		LASSO_TYPE_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE))
#define LASSO_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), \
		LASSO_TYPE_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE, \
		LassoIdWsf2DiscoSvcMDAssociationDeleteClass))


typedef struct _LassoIdWsf2DiscoSvcMDAssociationDelete \
	LassoIdWsf2DiscoSvcMDAssociationDelete;
typedef struct _LassoIdWsf2DiscoSvcMDAssociationDeleteClass \
	LassoIdWsf2DiscoSvcMDAssociationDeleteClass;


struct _LassoIdWsf2DiscoSvcMDAssociationDelete {
	LassoNode parent;

	/*< public >*/
	/* elements */
	GList *SvcMDID; /* of strings */
	/* attributes */
	GHashTable *attributes;
};

struct _LassoIdWsf2DiscoSvcMDAssociationDeleteClass {
	LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_idwsf2_disco_svc_md_association_delete_get_type(void);
LASSO_EXPORT LassoIdWsf2DiscoSvcMDAssociationDelete*
	lasso_idwsf2_disco_svc_md_association_delete_new(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_IDWSF2_DISCO_SVC_MD_ASSOCIATION_DELETE_H__ */
