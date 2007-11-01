/* $Id: loginprivate.h 3237 2007-05-30 17:17:45Z dlaniel $ 
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

#ifndef __LASSO_LOGIN_PRIVATE_H__
#define __LASSO_LOGIN_PRIVATE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 


#include <lasso/lasso_config.h>
#include <lasso/xml/saml-2.0/saml2_assertion.h>

#ifdef LASSO_WSF_ENABLED
#include <lasso/xml/disco_description.h>
#include <lasso/xml/disco_resource_offering.h>
#include <lasso/xml/disco_service_instance.h>
#endif



struct _LassoLoginPrivate
{
	char *soap_request_msg;
	LassoSaml2Assertion *saml2_assertion;
#ifdef LASSO_WSF_ENABLED
	LassoDiscoResourceID *resourceId;
	LassoDiscoEncryptedResourceID *encryptedResourceId;
#endif
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_LOGIN_PRIVATE_H__ */
