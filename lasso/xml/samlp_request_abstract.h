/* $Id: samlp_request_abstract.h,v 1.7 2004/08/23 14:05:20 nclapies Exp $ 
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

#ifndef __LASSO_SAMLP_REQUEST_ABSTRACT_H__
#define __LASSO_SAMLP_REQUEST_ABSTRACT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>

#define LASSO_TYPE_SAMLP_REQUEST_ABSTRACT (lasso_samlp_request_abstract_get_type())
#define LASSO_SAMLP_REQUEST_ABSTRACT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAMLP_REQUEST_ABSTRACT, LassoSamlpRequestAbstract))
#define LASSO_SAMLP_REQUEST_ABSTRACT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAMLP_REQUEST_ABSTRACT, LassoSamlpRequestAbstractClass))
#define LASSO_IS_SAMLP_REQUEST_ABSTRACT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAMLP_REQUEST_ABSTRACT))
#define LASSO_IS_SAMLP_REQUEST_ABSTRACT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAMLP_REQUEST_ABSTRACT))
#define LASSO_SAMLP_REQUEST_ABSTRACT_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAMLP_REQUEST_ABSTRACT, LassoSamlpRequestAbstractClass)) 

typedef struct _LassoSamlpRequestAbstract LassoSamlpRequestAbstract;
typedef struct _LassoSamlpRequestAbstractClass LassoSamlpRequestAbstractClass;

struct _LassoSamlpRequestAbstract {
  LassoNode parent;
  /*< private >*/
};

struct _LassoSamlpRequestAbstractClass {
  LassoNodeClass parent;
  /*< vtable >*/
};

LASSO_EXPORT GType lasso_samlp_request_abstract_get_type           (void);

LASSO_EXPORT LassoNode* lasso_samlp_request_abstract_new           (void);

LASSO_EXPORT void lasso_samlp_request_abstract_add_respondWith     (LassoSamlpRequestAbstract *node,
								    const xmlChar *respondWith);

LASSO_EXPORT void lasso_samlp_request_abstract_set_issueInstant    (LassoSamlpRequestAbstract *node,
								    const xmlChar *issueInstant);

LASSO_EXPORT void lasso_samlp_request_abstract_set_majorVersion    (LassoSamlpRequestAbstract *node,
								    const xmlChar *majorVersion);

LASSO_EXPORT void lasso_samlp_request_abstract_set_minorVersion    (LassoSamlpRequestAbstract *node,
								    const xmlChar *minorVersion);

LASSO_EXPORT void lasso_samlp_request_abstract_set_requestID       (LassoSamlpRequestAbstract *node,
								    const xmlChar *requestID);

LASSO_EXPORT gint lasso_samlp_request_abstract_set_signature       (LassoSamlpRequestAbstract *node,
								    gint                       sign_method,
								    const xmlChar             *private_key_file,
								    const xmlChar             *certificate_file);

LASSO_EXPORT gint lasso_samlp_request_abstract_set_signature_tmpl  (LassoSamlpRequestAbstract *node,
								    lassoSignatureType         sign_type,
								    lassoSignatureMethod       sign_method,
								    xmlChar                   *reference_id);

LASSO_EXPORT gint lasso_samlp_request_abstract_sign_signature_tmpl (LassoSamlpRequestAbstract *node,
								    const xmlChar             *private_key_file,
								    const xmlChar             *certificate_file);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAMLP_REQUEST_ABSTRACT_H__ */
