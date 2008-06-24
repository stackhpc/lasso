/* $Id: samlp2_status.i,v 1.0 2005/10/14 15:17:55 fpeters Exp $ 
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
%rename(Samlp2Status) LassoSamlp2Status;
#endif
typedef struct {
#ifndef SWIG_PHP_RENAMES
	%rename(statusMessage) StatusMessage;
#endif
	char *StatusMessage;
} LassoSamlp2Status;
%extend LassoSamlp2Status {

#ifndef SWIG_PHP_RENAMES
	%rename(statusCode) StatusCode;
#endif
	%newobject StatusCode_get;
	LassoSamlp2StatusCode *StatusCode;

#ifndef SWIG_PHP_RENAMES
	%rename(statusDetail) StatusDetail;
#endif
	%newobject StatusDetail_get;
	LassoSamlp2StatusDetail *StatusDetail;


	/* Constructor, Destructor & Static Methods */
	LassoSamlp2Status();
	~LassoSamlp2Status();

	/* Method inherited from LassoNode */
	%newobject dump;
	char* dump();
}

%{

/* StatusCode */

#define LassoSamlp2Status_get_StatusCode(self) get_node((self)->StatusCode)
#define LassoSamlp2Status_StatusCode_get(self) get_node((self)->StatusCode)
#define LassoSamlp2Status_set_StatusCode(self,value) set_node((gpointer*)&(self)->StatusCode, (value))
#define LassoSamlp2Status_StatusCode_set(self,value) set_node((gpointer*)&(self)->StatusCode, (value))
                    

/* StatusDetail */

#define LassoSamlp2Status_get_StatusDetail(self) get_node((self)->StatusDetail)
#define LassoSamlp2Status_StatusDetail_get(self) get_node((self)->StatusDetail)
#define LassoSamlp2Status_set_StatusDetail(self,value) set_node((gpointer*)&(self)->StatusDetail, (value))
#define LassoSamlp2Status_StatusDetail_set(self,value) set_node((gpointer*)&(self)->StatusDetail, (value))
                    


/* Constructors, destructors & static methods implementations */

#define new_LassoSamlp2Status lasso_samlp2_status_new
#define delete_LassoSamlp2Status(self) lasso_node_destroy(LASSO_NODE(self))

/* Implementations of methods inherited from LassoNode */

#define LassoSamlp2Status_dump(self) lasso_node_dump(LASSO_NODE(self))

%}

