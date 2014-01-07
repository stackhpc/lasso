/* $Id: wsu_timestamp.h,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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

#ifndef __LASSO_WSU_TIMESTAMP_H__
#define __LASSO_WSU_TIMESTAMP_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../xml.h"

#define LASSO_TYPE_WSU_TIMESTAMP (lasso_wsu_timestamp_get_type())
#define LASSO_WSU_TIMESTAMP(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), \
		LASSO_TYPE_WSU_TIMESTAMP, \
		LassoWsUtil1Timestamp))
#define LASSO_WSU_TIMESTAMP_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), \
		LASSO_TYPE_WSU_TIMESTAMP, \
		LassoWsUtil1TimestampClass))
#define LASSO_IS_WSU_TIMESTAMP(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), \
		LASSO_TYPE_WSU_TIMESTAMP))
#define LASSO_IS_WSU_TIMESTAMP_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), \
		LASSO_TYPE_WSU_TIMESTAMP))
#define LASSO_WSU_TIMESTAMP_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), \
		LASSO_TYPE_WSU_TIMESTAMP, \
		LassoWsUtil1TimestampClass))


typedef struct _LassoWsUtil1Timestamp LassoWsUtil1Timestamp;
typedef struct _LassoWsUtil1TimestampClass LassoWsUtil1TimestampClass;


struct _LassoWsUtil1Timestamp {
	LassoNode parent;

	/*< public >*/
	/* elements */
	char *Created;
	char *Expires;
	/* attributes */
	char *Id;
	GHashTable *attributes;
};


struct _LassoWsUtil1TimestampClass {
	LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_wsu_timestamp_get_type(void);
LASSO_EXPORT LassoWsUtil1Timestamp* lasso_wsu_timestamp_new(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_WSU_TIMESTAMP_H__ */
