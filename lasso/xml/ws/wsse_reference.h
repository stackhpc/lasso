/* $Id: wsse_reference.h,v 1.0 2005/10/14 15:17:55 fpeters Exp $
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

#ifndef __LASSO_WSSE_REFERENCE_H__
#define __LASSO_WSSE_REFERENCE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../xml.h"

#define LASSO_TYPE_WSSE_REFERENCE (lasso_wsse_reference_get_type())
#define LASSO_WSSE_REFERENCE(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), \
		LASSO_TYPE_WSSE_REFERENCE, \
		LassoWsSec1Reference))
#define LASSO_WSSE_REFERENCE_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), \
		LASSO_TYPE_WSSE_REFERENCE, \
		LassoWsSec1ReferenceClass))
#define LASSO_IS_WSSE_REFERENCE(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), \
		LASSO_TYPE_WSSE_REFERENCE))
#define LASSO_IS_WSSE_REFERENCE_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), \
		LASSO_TYPE_WSSE_REFERENCE))
#define LASSO_WSSE_REFERENCE_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), \
		LASSO_TYPE_WSSE_REFERENCE, \
		LassoWsSec1ReferenceClass))


typedef struct _LassoWsSec1Reference LassoWsSec1Reference;
typedef struct _LassoWsSec1ReferenceClass LassoWsSec1ReferenceClass;


struct _LassoWsSec1Reference {
	LassoNode parent;

	/*< public >*/
	/* attributes */
	char *URI;
	char *ValueType;
	GHashTable *attributes;
};


struct _LassoWsSec1ReferenceClass {
	LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_wsse_reference_get_type(void);
LASSO_EXPORT LassoWsSec1Reference* lasso_wsse_reference_new(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_WSSE_REFERENCE_H__ */
