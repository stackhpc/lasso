/* $Id: saml_subject_confirmation.h,v 1.2 2004/07/22 06:59:03 eraviart Exp $ 
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

#ifndef __LASSO_SAML_SUBJECT_CONFIRMATION_H__
#define __LASSO_SAML_SUBJECT_CONFIRMATION_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>

#define LASSO_TYPE_SAML_SUBJECT_CONFIRMATION (lasso_saml_subject_confirmation_get_type())
#define LASSO_SAML_SUBJECT_CONFIRMATION(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAML_SUBJECT_CONFIRMATION, LassoSamlSubjectConfirmation))
#define LASSO_SAML_SUBJECT_CONFIRMATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAML_SUBJECT_CONFIRMATION, LassoSamlSubjectConfirmationClass))
#define LASSO_IS_SAML_SUBJECT_CONFIRMATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAML_SUBJECT_CONFIRMATION))
#define LASSO_IS_SAML_SUBJECT_CONFIRMATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAML_SUBJECT_CONFIRMATION))
#define LASSO_SAML_SUBJECT_CONFIRMATION_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAML_SUBJECT_CONFIRMATION, LassoSamlSubjectConfirmationClass)) 

typedef struct _LassoSamlSubjectConfirmation LassoSamlSubjectConfirmation;
typedef struct _LassoSamlSubjectConfirmationClass LassoSamlSubjectConfirmationClass;

struct _LassoSamlSubjectConfirmation {
  LassoNode parent;
  /*< private >*/
};

struct _LassoSamlSubjectConfirmationClass {
  LassoNodeClass parent;
  /*< vtable >*/
};

LASSO_EXPORT GType lasso_saml_subject_confirmation_get_type(void);
LASSO_EXPORT LassoNode* lasso_saml_subject_confirmation_new(void);

LASSO_EXPORT void lasso_saml_subject_confirmation_add_confirmationMethod        (LassoSamlSubjectConfirmation *node,
										 const xmlChar *confirmationMethod);

LASSO_EXPORT void lasso_saml_subject_confirmation_set_subjectConfirmationMethod (LassoSamlSubjectConfirmation *node,
										 const xmlChar *subjectConfirmationMethod);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAML_SUBJECT_CONFIRMATION_H__ */
