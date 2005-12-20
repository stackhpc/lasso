/* $Id: saml_name_identifier.h,v 1.4 2004/07/22 06:59:03 eraviart Exp $ 
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

#ifndef __LASSO_SAML_NAME_IDENTIFIER_H__
#define __LASSO_SAML_NAME_IDENTIFIER_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>

#define LASSO_TYPE_SAML_NAME_IDENTIFIER (lasso_saml_name_identifier_get_type())
#define LASSO_SAML_NAME_IDENTIFIER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAML_NAME_IDENTIFIER, LassoSamlNameIdentifier))
#define LASSO_SAML_NAME_IDENTIFIER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAML_NAME_IDENTIFIER, LassoSamlNameIdentifierClass))
#define LASSO_IS_SAML_NAME_IDENTIFIER(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAML_NAME_IDENTIFIER))
#define LASSO_IS_SAML_NAME_IDENTIFIER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAML_NAME_IDENTIFIER))
#define LASSO_SAML_NAME_IDENTIFIER_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAML_NAME_IDENTIFIER, LassoSamlNameIdentifierClass)) 

typedef struct _LassoSamlNameIdentifier LassoSamlNameIdentifier;
typedef struct _LassoSamlNameIdentifierClass LassoSamlNameIdentifierClass;

struct _LassoSamlNameIdentifier {
  LassoNode parent;
  /*< private >*/
};

struct _LassoSamlNameIdentifierClass {
  LassoNodeClass parent;
  /*< vtable >*/
};

LASSO_EXPORT GType lasso_saml_name_identifier_get_type(void);
LASSO_EXPORT LassoNode* lasso_saml_name_identifier_new(const xmlChar *content);

LASSO_EXPORT void lasso_saml_name_identifier_set_format        (LassoSamlNameIdentifier *node,
								const xmlChar *format);

LASSO_EXPORT void lasso_saml_name_identifier_set_nameQualifier (LassoSamlNameIdentifier *node,
								const xmlChar *nameQualifier);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAML_NAME_IDENTIFIER_H__ */
