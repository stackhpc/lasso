/* $Id: lib_authn_context.h,v 1.2 2004/07/22 06:59:02 eraviart Exp $ 
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

#ifndef __LASSO_LIB_AUTHN_CONTEXT_H__
#define __LASSO_LIB_AUTHN_CONTEXT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>

#define LASSO_TYPE_LIB_AUTHN_CONTEXT (lasso_lib_authn_context_get_type())
#define LASSO_LIB_AUTHN_CONTEXT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_LIB_AUTHN_CONTEXT, LassoLibAuthnContext))
#define LASSO_LIB_AUTHN_CONTEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_LIB_AUTHN_CONTEXT, LassoLibAuthnContextClass))
#define LASSO_IS_LIB_AUTHN_CONTEXT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_LIB_AUTHN_CONTEXT))
#define LASSO_IS_LIB_AUTHN_CONTEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_LIB_AUTHN_CONTEXT))
#define LASSO_LIB_AUTHN_CONTEXT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_LIB_AUTHN_CONTEXT, LassoLibAuthnContextClass)) 

typedef struct _LassoLibAuthnContext LassoLibAuthnContext;
typedef struct _LassoLibAuthnContextClass LassoLibAuthnContextClass;

struct _LassoLibAuthnContext {
  LassoNode parent;
  /*< private >*/
};

struct _LassoLibAuthnContextClass {
  LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_lib_authn_context_get_type(void);
LASSO_EXPORT LassoNode* lasso_lib_authn_context_new(void);

LASSO_EXPORT void lasso_lib_authn_context_set_authnContextClassRef     (LassoLibAuthnContext *node,
									const xmlChar *authnContextClassRef);

LASSO_EXPORT void lasso_lib_authn_context_set_authnContextStatementRef (LassoLibAuthnContext *node,
									const xmlChar *authnContextStatementRef);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_LIB_AUTHN_CONTEXT_H__ */
