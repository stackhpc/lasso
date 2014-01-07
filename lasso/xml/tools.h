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

#ifndef __LASSO_TOOLS_H__
#define __LASSO_TOOLS_H__

LASSO_EXPORT char* lasso_build_unique_id(unsigned int size);
LASSO_EXPORT guint lasso_log_set_handler(GLogLevelFlags log_levels, GLogFunc log_func, gpointer user_data);
LASSO_EXPORT void lasso_log_remove_handler(guint handler_id);

#endif /* __LASSO_TOOLS_H__ */
