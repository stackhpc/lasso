/* $Id: samlp2_manage_name_id_request.i,v 1.0 2005/10/14 15:17:55 fpeters Exp $ 
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
%rename(Samlp2ManageNameIDRequest) LassoSamlp2ManageNameIDRequest;
#endif
typedef struct {
#ifndef SWIG_PHP_RENAMES
	%rename(newID) NewID;
#endif
	char *NewID;
} LassoSamlp2ManageNameIDRequest;
%extend LassoSamlp2ManageNameIDRequest {

#ifndef SWIG_PHP_RENAMES
	%rename(nameID) NameID;
#endif
	%newobject NameID_get;
	LassoSaml2NameID *NameID;

#ifndef SWIG_PHP_RENAMES
	%rename(encryptedID) EncryptedID;
#endif
	%newobject EncryptedID_get;
	LassoSaml2EncryptedElement *EncryptedID;

#ifndef SWIG_PHP_RENAMES
	%rename(newEncryptedID) NewEncryptedID;
#endif
	%newobject NewEncryptedID_get;
	LassoSaml2EncryptedElement *NewEncryptedID;

#ifndef SWIG_PHP_RENAMES
	%rename(terminate) Terminate;
#endif
	%newobject Terminate_get;
	LassoSamlp2Terminate *Terminate;

	/* inherited from Samlp2RequestAbstract */
#ifndef SWIG_PHP_RENAMES
	%rename(issuer) Issuer;
#endif
	%newobject *Issuer_get;
	LassoSaml2NameID *Issuer;

#ifndef SWIG_PHP_RENAMES
	%rename(extensions) Extensions;
#endif
	%newobject *Extensions_get;
	LassoSamlp2Extensions *Extensions;

#ifndef SWIG_PHP_RENAMES
	%rename(iD) ID;
#endif
	char *ID;
#ifndef SWIG_PHP_RENAMES
	%rename(version) Version;
#endif
	char *Version;
#ifndef SWIG_PHP_RENAMES
	%rename(issueInstant) IssueInstant;
#endif
	char *IssueInstant;
#ifndef SWIG_PHP_RENAMES
	%rename(destination) Destination;
#endif
	char *Destination;
#ifndef SWIG_PHP_RENAMES
	%rename(consent) Consent;
#endif
	char *Consent;

	/* Constructor, Destructor & Static Methods */
	LassoSamlp2ManageNameIDRequest();
	~LassoSamlp2ManageNameIDRequest();

	/* Method inherited from LassoNode */
	%newobject dump;
	char* dump();
}

%{

/* NameID */

#define LassoSamlp2ManageNameIDRequest_get_NameID(self) get_node((self)->NameID)
#define LassoSamlp2ManageNameIDRequest_NameID_get(self) get_node((self)->NameID)
#define LassoSamlp2ManageNameIDRequest_set_NameID(self,value) set_node((gpointer*)&(self)->NameID, (value))
#define LassoSamlp2ManageNameIDRequest_NameID_set(self,value) set_node((gpointer*)&(self)->NameID, (value))
                    

/* EncryptedID */

#define LassoSamlp2ManageNameIDRequest_get_EncryptedID(self) get_node((self)->EncryptedID)
#define LassoSamlp2ManageNameIDRequest_EncryptedID_get(self) get_node((self)->EncryptedID)
#define LassoSamlp2ManageNameIDRequest_set_EncryptedID(self,value) set_node((gpointer*)&(self)->EncryptedID, (value))
#define LassoSamlp2ManageNameIDRequest_EncryptedID_set(self,value) set_node((gpointer*)&(self)->EncryptedID, (value))
                    

/* NewEncryptedID */

#define LassoSamlp2ManageNameIDRequest_get_NewEncryptedID(self) get_node((self)->NewEncryptedID)
#define LassoSamlp2ManageNameIDRequest_NewEncryptedID_get(self) get_node((self)->NewEncryptedID)
#define LassoSamlp2ManageNameIDRequest_set_NewEncryptedID(self,value) set_node((gpointer*)&(self)->NewEncryptedID, (value))
#define LassoSamlp2ManageNameIDRequest_NewEncryptedID_set(self,value) set_node((gpointer*)&(self)->NewEncryptedID, (value))
                    

/* Terminate */

#define LassoSamlp2ManageNameIDRequest_get_Terminate(self) get_node((self)->Terminate)
#define LassoSamlp2ManageNameIDRequest_Terminate_get(self) get_node((self)->Terminate)
#define LassoSamlp2ManageNameIDRequest_set_Terminate(self,value) set_node((gpointer*)&(self)->Terminate, (value))
#define LassoSamlp2ManageNameIDRequest_Terminate_set(self,value) set_node((gpointer*)&(self)->Terminate, (value))
                    

/* inherited from RequestAbstract */

/* Issuer */

#define LassoSamlp2ManageNameIDRequest_get_Issuer(self) get_node(LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Issuer)
#define LassoSamlp2ManageNameIDRequest_Issuer_get(self) get_node(LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Issuer)
#define LassoSamlp2ManageNameIDRequest_set_Issuer(self,value) set_node((gpointer*)&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Issuer, (value))
#define LassoSamlp2ManageNameIDRequest_Issuer_set(self,value) set_node((gpointer*)&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Issuer, (value))
                    

/* Extensions */

#define LassoSamlp2ManageNameIDRequest_get_Extensions(self) get_node(LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Extensions)
#define LassoSamlp2ManageNameIDRequest_Extensions_get(self) get_node(LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Extensions)
#define LassoSamlp2ManageNameIDRequest_set_Extensions(self,value) set_node((gpointer*)&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Extensions, (value))
#define LassoSamlp2ManageNameIDRequest_Extensions_set(self,value) set_node((gpointer*)&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Extensions, (value))
                    

/* ID */

#define LassoSamlp2ManageNameIDRequest_get_ID(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->ID
#define LassoSamlp2ManageNameIDRequest_ID_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->ID

#define LassoSamlp2ManageNameIDRequest_set_ID(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->ID, (value))
#define LassoSamlp2ManageNameIDRequest_ID_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->ID, (value))

/* Version */

#define LassoSamlp2ManageNameIDRequest_get_Version(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Version
#define LassoSamlp2ManageNameIDRequest_Version_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Version

#define LassoSamlp2ManageNameIDRequest_set_Version(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Version, (value))
#define LassoSamlp2ManageNameIDRequest_Version_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Version, (value))

/* IssueInstant */

#define LassoSamlp2ManageNameIDRequest_get_IssueInstant(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->IssueInstant
#define LassoSamlp2ManageNameIDRequest_IssueInstant_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->IssueInstant

#define LassoSamlp2ManageNameIDRequest_set_IssueInstant(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->IssueInstant, (value))
#define LassoSamlp2ManageNameIDRequest_IssueInstant_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->IssueInstant, (value))

/* Destination */

#define LassoSamlp2ManageNameIDRequest_get_Destination(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Destination
#define LassoSamlp2ManageNameIDRequest_Destination_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Destination

#define LassoSamlp2ManageNameIDRequest_set_Destination(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Destination, (value))
#define LassoSamlp2ManageNameIDRequest_Destination_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Destination, (value))

/* Consent */

#define LassoSamlp2ManageNameIDRequest_get_Consent(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Consent
#define LassoSamlp2ManageNameIDRequest_Consent_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Consent

#define LassoSamlp2ManageNameIDRequest_set_Consent(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Consent, (value))
#define LassoSamlp2ManageNameIDRequest_Consent_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Consent, (value))


/* Constructors, destructors & static methods implementations */

#define new_LassoSamlp2ManageNameIDRequest lasso_samlp2_manage_name_id_request_new
#define delete_LassoSamlp2ManageNameIDRequest(self) lasso_node_destroy(LASSO_NODE(self))

/* Implementations of methods inherited from LassoNode */

#define LassoSamlp2ManageNameIDRequest_dump(self) lasso_node_dump(LASSO_NODE(self))

%}

