/* $Id: providerprivate.h,v 1.2 2005/11/21 18:51:52 fpeters Exp $
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

#ifndef __LASSO_SAML20_PROVIDER_PRIVATE_H__
#define __LASSO_SAML20_PROVIDER_PRIVATE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <lasso/xml/xml.h>
#include <lasso/id-ff/provider.h>

gboolean lasso_saml20_provider_load_metadata(LassoProvider *provider, xmlNode *root_node);

LassoHttpMethod lasso_saml20_provider_get_first_http_method(LassoProvider *provider,
		LassoProvider *remote_provider, LassoMdProtocolType protocol_type);

gboolean lasso_saml20_provider_accept_http_method(LassoProvider *provider,
		LassoProvider *remote_provider, LassoMdProtocolType protocol_type,
		LassoHttpMethod http_method, gboolean initiate_profile);

char* lasso_saml20_provider_build_artifact(LassoProvider *provider);

gchar* lasso_saml20_provider_get_assertion_consumer_service_url(LassoProvider *provider,
		int service_id);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAML20_PROVIDER_PRIVATE_H__ */
