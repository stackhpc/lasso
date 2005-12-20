/* $Id: export.h,v 1.3 2004/08/03 15:12:44 rchantereau Exp $ 
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

#ifndef __LASSO_EXPORT_H__
#define __LASSO_EXPORT_H__    

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

/* Now, the export orgy begins. The following we must do for the 
   Windows platform with MSVC compiler. */

#if !defined LASSO_EXPORT
#  if (defined _MSC_VER || defined MINGW32)
     /* if we compile libxmlsec itself: */
#    if defined(IN_LASSO)
#      if !defined(LASSO_STATIC)
#        define LASSO_EXPORT __declspec(dllexport) 
#      else
#        define LASSO_EXPORT extern
#      endif
     /* if a client program includes this file: */
#    else
#      if !defined(LASSO_STATIC)
#        define LASSO_EXPORT __declspec(dllimport) 
#      else
#        define LASSO_EXPORT 
#      endif
#    endif
   /* This holds on all other platforms/compilers, which are easier to
      handle in regard to this. */
#  else
#    define LASSO_EXPORT
#  endif
#endif

#if !defined LASSO_EXPORT_VAR
#  if (defined _MSC_VER || defined MINGW32)
     /* if we compile libxmlsec itself: */
#    if defined(IN_LASSO)
#      if !defined(LASSO_STATIC)
#        define LASSO_EXPORT_VAR __declspec(dllexport) extern
#      else
#        define LASSO_EXPORT_VAR extern
#      endif
     /* if we compile libxmlsec-crypto itself: */
#    elif defined(IN_LASSO_CRYPTO)
#        define LASSO_EXPORT_VAR extern
     /* if a client program includes this file: */
#    else
#      if !defined(LASSO_STATIC)
#        define LASSO_EXPORT_VAR __declspec(dllimport) extern
#      else
#        define LASSO_EXPORT_VAR extern
#      endif
#    endif
   /* This holds on all other platforms/compilers, which are easier to
      handle in regard to this. */
#  else
#    define LASSO_EXPORT_VAR extern
#  endif
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_EXPORT_H__ */
