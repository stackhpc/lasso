/* $Id
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

#ifndef __LASSO_DS_KEY_INFO_H__
#define __LASSO_DS_KEY_INFO_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../xml.h"
#include "ds_key_value.h"

#define LASSO_TYPE_DS_KEY_INFO (lasso_ds_key_info_get_type())
#define LASSO_DS_KEY_INFO(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_DS_KEY_INFO, \
				    LassoDsKeyInfo))
#define LASSO_DS_KEY_INFO_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_DS_KEY_INFO, \
				 LassoDsKeyInfoClass))
#define LASSO_IS_DS_KEY_INFO(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_DS_KEY_INFO))
#define LASSO_IS_DS_KEY_INFO_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_DS_KEY_INFO))
#define LASSO_DS_KEY_INFO_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_DS_KEY_INFO, \
				    LassoDsKeyInfoClass))

typedef struct _LassoDsKeyInfo LassoDsKeyInfo;
typedef struct _LassoDsKeyInfoClass LassoDsKeyInfoClass;

struct _LassoDsKeyInfo {
	LassoNode parent;

	LassoDsKeyValue *KeyValue;
};

struct _LassoDsKeyInfoClass {
	LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_ds_key_info_get_type(void);
LASSO_EXPORT LassoDsKeyInfo* lasso_ds_key_info_new(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_DS_KEY_INFO_H__ */
