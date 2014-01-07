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

#ifndef __LASSO_IDSWF_UTILS_H__
#define __LASSO_IDSWF_UTILS_H__

LASSO_EXPORT gboolean lasso_security_mech_id_is_null_authentication(const gchar *security_mech_id);
LASSO_EXPORT gboolean lasso_security_mech_id_is_x509_authentication(const gchar *security_mech_id);
LASSO_EXPORT gboolean lasso_security_mech_id_is_saml_authentication(const gchar *security_mech_id);
LASSO_EXPORT gboolean lasso_security_mech_id_is_bearer_authentication(
		const gchar *security_mech_id);

#endif
