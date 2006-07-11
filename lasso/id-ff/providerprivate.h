/* $Id: providerprivate.h,v 1.7 2005/11/20 15:38:19 fpeters Exp $ 
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

#ifndef __LASSO_PROVIDER_PRIVATE_H__
#define __LASSO_PROVIDER_PRIVATE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

struct _LassoProviderPrivate
{
	gboolean dispose_has_run;
	LassoProtocolConformance conformance;
	GHashTable *SPDescriptor;
	char *default_assertion_consumer;
	GHashTable *IDPDescriptor;
	xmlNode *organization;
	xmlSecKey *public_key;
	xmlNode *signing_key_descriptor;
};


gboolean lasso_provider_load_metadata(LassoProvider *provider, const gchar *metadata);
int lasso_provider_verify_signature(LassoProvider *provider,
		const char *message, const char *id_attr_name, LassoMessageFormat format);
gboolean lasso_provider_load_public_key(LassoProvider *provider);
xmlSecKey* lasso_provider_get_public_key(LassoProvider *provider);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_PROVIDER_PRIVATE_H__ */
