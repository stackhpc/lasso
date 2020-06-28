/* $Id: lib_old_provided_name_identifier.h,v 1.4 2004/07/22 06:59:03 eraviart Exp $ 
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004 Entr'ouvert
 * http://lasso.entrouvert.org
 * 
 * Authors: Nicolas Clapies <nclapies@entrouvert.com>
 *          Valery Febvre <vfebvre@easter-eggs.com>
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

#ifndef __LASSO_LIB_OLD_PROVIDED_NAME_IDENTIFIER_H__
#define __LASSO_LIB_OLD_PROVIDED_NAME_IDENTIFIER_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/saml_name_identifier.h>

#define LASSO_TYPE_LIB_OLD_PROVIDED_NAME_IDENTIFIER (lasso_lib_old_provided_name_identifier_get_type())
#define LASSO_LIB_OLD_PROVIDED_NAME_IDENTIFIER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_LIB_OLD_PROVIDED_NAME_IDENTIFIER, LassoLibOLDProvidedNameIdentifier))
#define LASSO_LIB_OLD_PROVIDED_NAME_IDENTIFIER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_LIB_OLD_PROVIDED_NAME_IDENTIFIER, LassoLibOLDProvidedNameIdentifierClass))
#define LASSO_IS_LIB_OLD_PROVIDED_NAME_IDENTIFIER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_LIB_OLD_PROVIDED_NAME_IDENTIFIER))
#define LASSO_IS_LIB_OLD_PROVIDED_NAME_IDENTIFIER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_LIB_OLD_PROVIDED_NAME_IDENTIFIER))
#define LASSO_LIB_OLD_PROVIDED_NAME_IDENTIFIER_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_LIB_OLD_PROVIDED_NAME_IDENTIFIER, LassoLibOLDProvidedNameIdentifierClass))

typedef struct _LassoLibOLDProvidedNameIdentifier LassoLibOLDProvidedNameIdentifier;
typedef struct _LassoLibOLDProvidedNameIdentifierClass LassoLibOLDProvidedNameIdentifierClass;

struct _LassoLibOLDProvidedNameIdentifier {
  LassoSamlNameIdentifier parent;
  /*< private >*/
};

struct _LassoLibOLDProvidedNameIdentifierClass {
  LassoSamlNameIdentifierClass parent;
};

LASSO_EXPORT GType lasso_lib_old_provided_name_identifier_get_type(void);
LASSO_EXPORT LassoNode* lasso_lib_old_provided_name_identifier_new(const xmlChar *content);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_LIB_OLD_PROVIDED_NAME_IDENTIFIER_H__ */