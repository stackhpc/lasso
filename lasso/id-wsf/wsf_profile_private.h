/* $Id$
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LASSO_WSF_PROFILE_PRIVATE_H__
#define __LASSO_WSF_PROFILE_PRIVATE_H__

#ifdef __cplusplus
extern "C" {

#endif /* __cplusplus */

#include "../xml/soap-1.1/soap_fault.h"

struct _LassoWsfProfilePrivate
{
	gboolean dispose_has_run;
	char *security_mech_id;
	LassoDiscoResourceOffering *offering;
	LassoDiscoDescription *description;
	char *remote_provider_id;
	LassoSoapFault *soap_fault;
	char *status_code;
};

LassoSoapFault* lasso_wsf_profile_get_fault(const LassoWsfProfile *profile);
void lasso_wsf_profile_set_resource_offering(LassoWsfProfile *profile,
	LassoDiscoResourceOffering *offering);
gint lasso_wsf_profile_set_msg_url_from_description(LassoWsfProfile *wsf_profile);
gint lasso_wsf_profile_build_soap_fault_response_msg(LassoWsfProfile *profile, gint rc);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_WSF_PROFILE_PRIVATE_H__ */
