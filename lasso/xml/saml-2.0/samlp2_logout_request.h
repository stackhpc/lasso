/* $Id: samlp2_logout_request.h 3237 2007-05-30 17:17:45Z dlaniel $ 
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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LASSO_SAMLP2_LOGOUT_REQUEST_H__
#define __LASSO_SAMLP2_LOGOUT_REQUEST_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "samlp2_request_abstract.h"
#include "saml2_encrypted_element.h"
#include "saml2_name_id.h"
#include "saml2_base_idabstract.h"

#define LASSO_TYPE_SAMLP2_LOGOUT_REQUEST (lasso_samlp2_logout_request_get_type())
#define LASSO_SAMLP2_LOGOUT_REQUEST(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAMLP2_LOGOUT_REQUEST, \
				LassoSamlp2LogoutRequest))
#define LASSO_SAMLP2_LOGOUT_REQUEST_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAMLP2_LOGOUT_REQUEST, \
				LassoSamlp2LogoutRequestClass))
#define LASSO_IS_SAMLP2_LOGOUT_REQUEST(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAMLP2_LOGOUT_REQUEST))
#define LASSO_IS_SAMLP2_LOGOUT_REQUEST_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAMLP2_LOGOUT_REQUEST))
#define LASSO_SAMLP2_LOGOUT_REQUEST_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAMLP2_LOGOUT_REQUEST, \
				LassoSamlp2LogoutRequestClass)) 

typedef struct _LassoSamlp2LogoutRequest LassoSamlp2LogoutRequest;
typedef struct _LassoSamlp2LogoutRequestClass LassoSamlp2LogoutRequestClass;


struct _LassoSamlp2LogoutRequest {
	LassoSamlp2RequestAbstract parent;

	/*< public >*/
	/* elements */
	LassoSaml2BaseIDAbstract *BaseID;
	LassoSaml2NameID *NameID;
	LassoSaml2EncryptedElement *EncryptedID;
	char *SessionIndex;
	/* attributes */
	char *Reason;
	char *NotOnOrAfter;

	char *relayState;
};


struct _LassoSamlp2LogoutRequestClass {
	LassoSamlp2RequestAbstractClass parent;
};

LASSO_EXPORT GType lasso_samlp2_logout_request_get_type(void);
LASSO_EXPORT LassoNode* lasso_samlp2_logout_request_new(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAMLP2_LOGOUT_REQUEST_H__ */
