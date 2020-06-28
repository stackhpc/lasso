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

#ifndef __LASSO_WSF_ID_FF_EXTENSIONS_H__
#define __LASSO_WSF_ID_FF_EXTENSIONS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "../id-ff/login.h"
#include "../xml/saml_assertion.h"

void lasso_login_assertion_add_discovery(LassoLogin *login, LassoSamlAssertion *assertion);

void lasso_server_dump_id_wsf_services(LassoServer *server, xmlNode *xmlnode);

void lasso_server_init_id_wsf_services(LassoServer *server, xmlNode *t);

gint lasso_server_add_service(LassoServer *server, LassoNode *service);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_WSF_ID_FF_EXTENSIONS_H__ */
