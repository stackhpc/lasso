/* $Id: samlp2_authn_request.i 3378 2007-08-13 10:43:37Z fpeters $ 
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
%rename(Samlp2AuthnRequest) LassoSamlp2AuthnRequest;
#endif
typedef struct {
#ifndef SWIG_PHP_RENAMES
	%rename(forceAuthn) ForceAuthn;
#endif
	gboolean ForceAuthn;
#ifndef SWIG_PHP_RENAMES
	%rename(isPassive) IsPassive;
#endif
	gboolean IsPassive;
#ifndef SWIG_PHP_RENAMES
	%rename(protocolBinding) ProtocolBinding;
#endif
	char *ProtocolBinding;
#ifndef SWIG_PHP_RENAMES
	%rename(assertionConsumerServiceIndex) AssertionConsumerServiceIndex;
#endif
	int AssertionConsumerServiceIndex;
#ifndef SWIG_PHP_RENAMES
	%rename(assertionConsumerServiceURL) AssertionConsumerServiceURL;
#endif
	char *AssertionConsumerServiceURL;
#ifndef SWIG_PHP_RENAMES
	%rename(attributeConsumingServiceIndex) AttributeConsumingServiceIndex;
#endif
	int AttributeConsumingServiceIndex;
#ifndef SWIG_PHP_RENAMES
	%rename(providerName) ProviderName;
#endif
	char *ProviderName;
} LassoSamlp2AuthnRequest;
%extend LassoSamlp2AuthnRequest {

#ifndef SWIG_PHP_RENAMES
	%rename(subject) Subject;
#endif
	%newobject Subject_get;
	LassoSaml2Subject *Subject;

#ifndef SWIG_PHP_RENAMES
	%rename(nameIDPolicy) NameIDPolicy;
#endif
	%newobject NameIDPolicy_get;
	LassoSamlp2NameIDPolicy *NameIDPolicy;

#ifndef SWIG_PHP_RENAMES
	%rename(conditions) Conditions;
#endif
	%newobject Conditions_get;
	LassoSaml2Conditions *Conditions;

#ifndef SWIG_PHP_RENAMES
	%rename(requestedAuthnContext) RequestedAuthnContext;
#endif
	%newobject RequestedAuthnContext_get;
	LassoSamlp2RequestedAuthnContext *RequestedAuthnContext;

#ifndef SWIG_PHP_RENAMES
	%rename(scoping) Scoping;
#endif
	%newobject Scoping_get;
	LassoSamlp2Scoping *Scoping;

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
	LassoSamlp2AuthnRequest();
	~LassoSamlp2AuthnRequest();

	/* Method inherited from LassoNode */
	%newobject dump;
	char* dump();
}

%{

/* Subject */

#define LassoSamlp2AuthnRequest_get_Subject(self) get_node((self)->Subject)
#define LassoSamlp2AuthnRequest_Subject_get(self) get_node((self)->Subject)
#define LassoSamlp2AuthnRequest_set_Subject(self,value) set_node((gpointer*)&(self)->Subject, (value))
#define LassoSamlp2AuthnRequest_Subject_set(self,value) set_node((gpointer*)&(self)->Subject, (value))
                    

/* NameIDPolicy */

#define LassoSamlp2AuthnRequest_get_NameIDPolicy(self) get_node((self)->NameIDPolicy)
#define LassoSamlp2AuthnRequest_NameIDPolicy_get(self) get_node((self)->NameIDPolicy)
#define LassoSamlp2AuthnRequest_set_NameIDPolicy(self,value) set_node((gpointer*)&(self)->NameIDPolicy, (value))
#define LassoSamlp2AuthnRequest_NameIDPolicy_set(self,value) set_node((gpointer*)&(self)->NameIDPolicy, (value))
                    

/* Conditions */

#define LassoSamlp2AuthnRequest_get_Conditions(self) get_node((self)->Conditions)
#define LassoSamlp2AuthnRequest_Conditions_get(self) get_node((self)->Conditions)
#define LassoSamlp2AuthnRequest_set_Conditions(self,value) set_node((gpointer*)&(self)->Conditions, (value))
#define LassoSamlp2AuthnRequest_Conditions_set(self,value) set_node((gpointer*)&(self)->Conditions, (value))
                    

/* RequestedAuthnContext */

#define LassoSamlp2AuthnRequest_get_RequestedAuthnContext(self) get_node((self)->RequestedAuthnContext)
#define LassoSamlp2AuthnRequest_RequestedAuthnContext_get(self) get_node((self)->RequestedAuthnContext)
#define LassoSamlp2AuthnRequest_set_RequestedAuthnContext(self,value) set_node((gpointer*)&(self)->RequestedAuthnContext, (value))
#define LassoSamlp2AuthnRequest_RequestedAuthnContext_set(self,value) set_node((gpointer*)&(self)->RequestedAuthnContext, (value))
                    

/* Scoping */

#define LassoSamlp2AuthnRequest_get_Scoping(self) get_node((self)->Scoping)
#define LassoSamlp2AuthnRequest_Scoping_get(self) get_node((self)->Scoping)
#define LassoSamlp2AuthnRequest_set_Scoping(self,value) set_node((gpointer*)&(self)->Scoping, (value))
#define LassoSamlp2AuthnRequest_Scoping_set(self,value) set_node((gpointer*)&(self)->Scoping, (value))
                    

/* inherited from RequestAbstract */

/* Issuer */

#define LassoSamlp2AuthnRequest_get_Issuer(self) get_node(LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Issuer)
#define LassoSamlp2AuthnRequest_Issuer_get(self) get_node(LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Issuer)
#define LassoSamlp2AuthnRequest_set_Issuer(self,value) set_node((gpointer*)&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Issuer, (value))
#define LassoSamlp2AuthnRequest_Issuer_set(self,value) set_node((gpointer*)&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Issuer, (value))
                    

/* Extensions */

#define LassoSamlp2AuthnRequest_get_Extensions(self) get_node(LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Extensions)
#define LassoSamlp2AuthnRequest_Extensions_get(self) get_node(LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Extensions)
#define LassoSamlp2AuthnRequest_set_Extensions(self,value) set_node((gpointer*)&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Extensions, (value))
#define LassoSamlp2AuthnRequest_Extensions_set(self,value) set_node((gpointer*)&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Extensions, (value))
                    

/* ID */

#define LassoSamlp2AuthnRequest_get_ID(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->ID
#define LassoSamlp2AuthnRequest_ID_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->ID

#define LassoSamlp2AuthnRequest_set_ID(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->ID, (value))
#define LassoSamlp2AuthnRequest_ID_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->ID, (value))

/* Version */

#define LassoSamlp2AuthnRequest_get_Version(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Version
#define LassoSamlp2AuthnRequest_Version_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Version

#define LassoSamlp2AuthnRequest_set_Version(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Version, (value))
#define LassoSamlp2AuthnRequest_Version_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Version, (value))

/* IssueInstant */

#define LassoSamlp2AuthnRequest_get_IssueInstant(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->IssueInstant
#define LassoSamlp2AuthnRequest_IssueInstant_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->IssueInstant

#define LassoSamlp2AuthnRequest_set_IssueInstant(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->IssueInstant, (value))
#define LassoSamlp2AuthnRequest_IssueInstant_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->IssueInstant, (value))

/* Destination */

#define LassoSamlp2AuthnRequest_get_Destination(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Destination
#define LassoSamlp2AuthnRequest_Destination_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Destination

#define LassoSamlp2AuthnRequest_set_Destination(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Destination, (value))
#define LassoSamlp2AuthnRequest_Destination_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Destination, (value))

/* Consent */

#define LassoSamlp2AuthnRequest_get_Consent(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Consent
#define LassoSamlp2AuthnRequest_Consent_get(self) LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Consent

#define LassoSamlp2AuthnRequest_set_Consent(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Consent, (value))
#define LassoSamlp2AuthnRequest_Consent_set(self,value) set_string(&LASSO_SAMLP2_REQUEST_ABSTRACT(self)->Consent, (value))


/* Constructors, destructors & static methods implementations */

#define new_LassoSamlp2AuthnRequest lasso_samlp2_authn_request_new
#define delete_LassoSamlp2AuthnRequest(self) lasso_node_destroy(LASSO_NODE(self))

/* Implementations of methods inherited from LassoNode */

#define LassoSamlp2AuthnRequest_dump(self) lasso_node_dump(LASSO_NODE(self))

%}

