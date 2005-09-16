/* $Id: is_select.h,v 1.2 2005/01/22 15:57:55 eraviart Exp $ 
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

#ifndef __LASSO_IS_SELECT_H__
#define __LASSO_IS_SELECT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/is_item.h>
#include <lasso/xml/xml.h>

#define LASSO_TYPE_IS_SELECT (lasso_is_select_get_type())
#define LASSO_IS_SELECT(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_IS_SELECT, LassoIsSelect))
#define LASSO_IS_SELECT_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_IS_SELECT, LassoIsSelectClass))
#define LASSO_IS_IS_SELECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_IS_SELECT))
#define LASSO_IS_IS_SELECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_IS_SELECT))
#define LASSO_IS_SELECT_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_IS_SELECT, LassoIsSelectClass))

typedef struct _LassoIsSelect LassoIsSelect;
typedef struct _LassoIsSelectClass LassoIsSelectClass;

struct _LassoIsSelect {
	LassoNode parent; /* FIXME : must inherit of InquiryElement class */

	GList *Item;

	gboolean multiple;
};

struct _LassoIsSelectClass {
	LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_is_select_get_type(void);

LASSO_EXPORT LassoIsSelect* lasso_is_select_new(LassoIsItem *item1, LassoIsItem *item2);
	/* FIXME : choose proper names */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_IS_SELECT_H__ */
