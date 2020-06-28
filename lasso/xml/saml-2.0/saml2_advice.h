/* $Id: saml2_advice.h,v 1.2 2005/11/21 18:51:52 fpeters Exp $ 
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

#ifndef __LASSO_SAML2_ADVICE_H__
#define __LASSO_SAML2_ADVICE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <lasso/xml/xml.h>

#ifndef __LASSO_SAML2_ASSERTION_H__
/* to avoid circular inclusion of saml2_assertion.h */
typedef struct _LassoSaml2Assertion LassoSaml2Assertion;
#endif


#define LASSO_TYPE_SAML2_ADVICE (lasso_saml2_advice_get_type())
#define LASSO_SAML2_ADVICE(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAML2_ADVICE, \
				LassoSaml2Advice))
#define LASSO_SAML2_ADVICE_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAML2_ADVICE, \
				LassoSaml2AdviceClass))
#define LASSO_IS_SAML2_ADVICE(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAML2_ADVICE))
#define LASSO_IS_SAML2_ADVICE_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAML2_ADVICE))
#define LASSO_SAML2_ADVICE_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAML2_ADVICE, \
				LassoSaml2AdviceClass)) 

typedef struct _LassoSaml2Advice LassoSaml2Advice;
typedef struct _LassoSaml2AdviceClass LassoSaml2AdviceClass;


struct _LassoSaml2Advice {
	LassoNode parent;

	/*< public >*/
	/* elements */
	GList *AssertionIDRef;
	GList *AssertionURIRef;
	GList *Assertion; /* of LassoSaml2Assertion */
	GList *EncryptedAssertion; /* of LassoSaml2EncryptedElement */
};


struct _LassoSaml2AdviceClass {
	LassoNodeClass parent;
};

LASSO_EXPORT GType lasso_saml2_advice_get_type(void);
LASSO_EXPORT LassoNode* lasso_saml2_advice_new(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAML2_ADVICE_H__ */
