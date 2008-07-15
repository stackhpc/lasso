/* $Id: samlp2_idp_list.i 3378 2007-08-13 10:43:37Z fpeters $ 
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

#ifndef SWIG_PHP_RENAMES
%rename(Samlp2IDPList) LassoSamlp2IDPList;
#endif
typedef struct {
#ifndef SWIG_PHP_RENAMES
	%rename(getComplete) GetComplete;
#endif
	char *GetComplete;
} LassoSamlp2IDPList;
%extend LassoSamlp2IDPList {

#ifndef SWIG_PHP_RENAMES
	%rename(iDPEntry) IDPEntry;
#endif
	%newobject IDPEntry_get;
	LassoSamlp2IDPEntry *IDPEntry;


	/* Constructor, Destructor & Static Methods */
	LassoSamlp2IDPList();
	~LassoSamlp2IDPList();

	/* Method inherited from LassoNode */
	%newobject dump;
	char* dump();
}

%{

/* IDPEntry */

#define LassoSamlp2IDPList_get_IDPEntry(self) get_node((self)->IDPEntry)
#define LassoSamlp2IDPList_IDPEntry_get(self) get_node((self)->IDPEntry)
#define LassoSamlp2IDPList_set_IDPEntry(self,value) set_node((gpointer*)&(self)->IDPEntry, (value))
#define LassoSamlp2IDPList_IDPEntry_set(self,value) set_node((gpointer*)&(self)->IDPEntry, (value))
                    


/* Constructors, destructors & static methods implementations */

#define new_LassoSamlp2IDPList lasso_samlp2_idp_list_new
#define delete_LassoSamlp2IDPList(self) lasso_node_destroy(LASSO_NODE(self))

/* Implementations of methods inherited from LassoNode */

#define LassoSamlp2IDPList_dump(self) lasso_node_dump(LASSO_NODE(self))

%}

