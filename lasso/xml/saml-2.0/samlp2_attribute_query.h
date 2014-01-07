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

#ifndef __LASSO_SAMLP2_ATTRIBUTE_QUERY_H__
#define __LASSO_SAMLP2_ATTRIBUTE_QUERY_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "samlp2_subject_query_abstract.h"
#include "saml2_attribute.h"

#define LASSO_TYPE_SAMLP2_ATTRIBUTE_QUERY (lasso_samlp2_attribute_query_get_type())
#define LASSO_SAMLP2_ATTRIBUTE_QUERY(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), LASSO_TYPE_SAMLP2_ATTRIBUTE_QUERY, \
				LassoSamlp2AttributeQuery))
#define LASSO_SAMLP2_ATTRIBUTE_QUERY_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_CAST((klass), LASSO_TYPE_SAMLP2_ATTRIBUTE_QUERY, \
				LassoSamlp2AttributeQueryClass))
#define LASSO_IS_SAMLP2_ATTRIBUTE_QUERY(obj) \
	(G_TYPE_CHECK_INSTANCE_TYPE((obj), LASSO_TYPE_SAMLP2_ATTRIBUTE_QUERY))
#define LASSO_IS_SAMLP2_ATTRIBUTE_QUERY_CLASS(klass) \
	(G_TYPE_CHECK_CLASS_TYPE ((klass), LASSO_TYPE_SAMLP2_ATTRIBUTE_QUERY))
#define LASSO_SAMLP2_ATTRIBUTE_QUERY_GET_CLASS(o) \
	(G_TYPE_INSTANCE_GET_CLASS ((o), LASSO_TYPE_SAMLP2_ATTRIBUTE_QUERY, \
				LassoSamlp2AttributeQueryClass))

typedef struct _LassoSamlp2AttributeQuery LassoSamlp2AttributeQuery;
typedef struct _LassoSamlp2AttributeQueryClass LassoSamlp2AttributeQueryClass;


struct _LassoSamlp2AttributeQuery {
	LassoSamlp2SubjectQueryAbstract parent;

	/*< public >*/
	/* elements */
	GList *Attribute; /* of LassoSaml2Attribute */
};


struct _LassoSamlp2AttributeQueryClass {
	LassoSamlp2SubjectQueryAbstractClass parent;
};

LASSO_EXPORT GType lasso_samlp2_attribute_query_get_type(void);
LASSO_EXPORT LassoNode* lasso_samlp2_attribute_query_new(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LASSO_SAMLP2_ATTRIBUTE_QUERY_H__ */
