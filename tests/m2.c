/*
 * Lasso library mini tests
 *
 * Copyright (C) 2004 Entr'ouvert
 * http://lasso.entrouvert.org
 *
 * Author: Frederic Peters <fpeters@entrouvert.com>
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

#include <lasso.h>
#include <xml/lib_register_name_identifier_request.h>

#if 0
int
main(int argc, char *argv[])
{
	LassoNode *request, *request_new;
	LassoSamlNameIdentifier *idpNameIdentifier;
	LassoSamlNameIdentifier *spNameIdentifier;
	LassoSamlNameIdentifier *oldNameIdentifier;
	char *query;

	lasso_init();

	idpNameIdentifier = lasso_saml_name_identifier_new();
	idpNameIdentifier->NameQualifier = strdup("idp-name-qualifier");
	idpNameIdentifier->Format = strdup("idp-format");
	idpNameIdentifier->content = strdup("idp-content");

	spNameIdentifier = lasso_saml_name_identifier_new();
	spNameIdentifier->NameQualifier = strdup("sp-name-qualifier");
	spNameIdentifier->Format = strdup("sp-format");
	spNameIdentifier->content = strdup("sp-content");

	oldNameIdentifier = lasso_saml_name_identifier_new();
	oldNameIdentifier->NameQualifier = strdup("old-name-qualifier");
	oldNameIdentifier->Format = strdup("old-format");
	oldNameIdentifier->content = strdup("old-content");

	request = lasso_lib_register_name_identifier_request_new_full(
			"http://providerID",
			idpNameIdentifier, spNameIdentifier, oldNameIdentifier,
			0, 0);
	query = lasso_node_build_query(request);
	fprintf(stderr, "%s\n", query);

	request_new = lasso_lib_register_name_identifier_request_new();
	lasso_node_init_from_query(request_new, query);

	fprintf(stderr, "\n%s\n", lasso_node_build_query(request_new));
	
	return 0;
}

/*
gcc -g -O2 -I../lasso `pkg-config gobject-2.0 --cflags` `pkg-config libxml-2.0 --cflags` -L../lasso/lasso/.libs -llasso `pkg-config gobject-2.0 --libs` `pkg-config libxml-2.0 --libs` -DXMLSEC_CRYPTO=\"openssl\" -DXMLSEC_LIBXML_260=1 -D__XMLSEC_FUNCTION__=__FUNCTION__ -DXMLSEC_NO_XKMS=1 -DXMLSEC_NO_CRYPTO_DYNAMIC_LOADING=1 -DXMLSEC_CRYPTO_OPENSSL=1 -I/usr/include/xmlsec1 -I/usr/include/libxml2 -L/usr/lib -lxmlsec1-openssl -lxmlsec1 -lxslt -lxml2 -lz -lpthread -lm -lssl -lcrypto -ldl pp_query_request.c -o pp_query_request
*/

/*
 * This example simulates a request of an email attribute :
 *     Service Provider sends a Query message to an Attribute Provider about email attribute.
 *     Attribute Provider returns a QueryResponse message with the requested attribute's value. 
*/

#include <lasso/id-wsf/personal_profile_service.h>
#include <lasso/xml/disco_resource_offering.h>
#include <lasso/xml/pp_msg_contact.h>

int main(int argc, char *argv[])
{
	LassoServer *server;
	LassoPersonalProfileService *pp1, *pp2, *pp3;
	LassoDiscoResourceOffering *ro;
	LassoDiscoServiceInstance *si;
	LassoDiscoResourceID *rid;
	GList *l_desc = NULL;
	LassoDiscoDescription *desc;
	LassoDstQueryItem *qi;
	LassoPPMsgContact *msgContact;
	char *soap_msg;

	lasso_init();

	server = lasso_server_new(NULL, NULL, NULL, NULL);

	/* build ResourceOffering */
	desc = lasso_disco_description_new("xxxxxxxx", /* securityMechID : not supported for now */
			"xxxxxxxx", /* wsdlURI : not supported for now */
			"xxxxxxxx", /* serviceNameRef not supported now */
			"http://service.com/pp/endPoint", /* SOAP end point */
			"Endpoint accepting PP attributes requests."); /* SOAP action */
	l_desc = g_list_append(l_desc, desc);
	si = lasso_disco_service_instance_new(LASSO_PP_HREF,
			"http://attribute-service-provider.com", /* ProviderID */
			l_desc);

	/* http://attribute-service-domain/cds8cdslcmslclmds8 is a resource identifier */
	rid = lasso_disco_resource_id_new("http://attribute-service-domain/cds8cdslcmslclmds8");

	ro = lasso_disco_resource_offering_new(si);
	ro->ResourceID = rid;

	/* build Query */
	pp1 = lasso_personal_profile_service_new(server);
	lasso_personal_profile_service_init_query(pp1, ro, desc, "/pp:PP/pp:MsgContact");

	/* Other attributes could be requested too with a call to the method :
	   lasso_personal_profile_service_add_query_item(pp1, "/pp:PP/pp:Contact"); */

	lasso_wsf_profile_build_request_msg(LASSO_WSF_PROFILE(pp1));
	soap_msg = LASSO_WSF_PROFILE(pp1)->msg_body;

	printf("%s\n\n", lasso_node_dump(LASSO_WSF_PROFILE(pp1)->request, NULL, 1));

	/* msg_url contains the end point url to send the request 
	   msg_body contains the SOAP message */
	printf("- PP Query request ...\nurl : %s\nbody : %s\n",
			LASSO_WSF_PROFILE(pp1)->msg_url,
			LASSO_WSF_PROFILE(pp1)->msg_body);

	/* process query */
	pp2 = lasso_personal_profile_service_new(server);
	lasso_personal_profile_service_process_query_msg(pp2, soap_msg);

	/* After a call to lasso_personal_profile_service_process_request_msg, lasso set the ResourceID
	   and the requested attributes (QueryItems) found in the Query message.
	   The application hosting the service can retrieve the value(s). */

	/* Lasso builds add a Data response containing atribute's value. */
	msgContact = lasso_pp_msg_contact_new();
	msgContact->MsgProvider = "entrouvert.com";
	msgContact->MsgAccount = "nclapies";
	lasso_personal_profile_service_add_data(pp2, LASSO_NODE(msgContact));

	/* build the query response */
	lasso_wsf_profile_build_response_msg(LASSO_WSF_PROFILE(pp2));
	printf("- PP QueryResponse ...\nbody : \n%s\n", LASSO_WSF_PROFILE(pp2)->msg_body);
	soap_msg = LASSO_WSF_PROFILE(pp2)->msg_body;

	printf("%s\n\n", lasso_node_dump(LASSO_WSF_PROFILE(pp2)->response, NULL, 1));
	{
		char *s = lasso_node_dump(LASSO_WSF_PROFILE(pp2)->response, NULL, 1);
		LassoDstQueryResponse *n;
		n = lasso_node_new_from_dump(s);
		printf("type: %s\n", G_OBJECT_TYPE_NAME(n));
	}


	return 0;
}
#endif

#if 0
#include <lasso/xml/lib_assertion.h>
#include <lasso/xml/lib_authentication_statement.h>
#include <lasso/xml/saml_name_identifier.h>

int main(int argc, char *argv[])
{
	LassoSamlAssertion *assertion;

	lasso_init();

	assertion = LASSO_SAML_ASSERTION(lasso_lib_assertion_new_full("", "", "", "", ""));
	assertion->AuthenticationStatement = lasso_lib_authentication_statement_new_full(
			"toto", "toto", "toto",
			NULL,
			lasso_saml_name_identifier_new());
	LASSO_LIB_AUTHENTICATION_STATEMENT(assertion->AuthenticationStatement)->AuthnContext =
		lasso_lib_authn_context_new();
	LASSO_LIB_AUTHENTICATION_STATEMENT(assertion->AuthenticationStatement)->AuthnContext->AuthnContextClassRef = g_strdup("urn:toto");

	printf("%s\n", lasso_node_dump(LASSO_NODE(assertion)));

	return 0;
}
#endif

char**
urlencoded_to_strings(const char *str)
{
        int n=1;
        char **result;

        result = g_malloc(sizeof(char*)*(n+2));
        result[1] = NULL;
        return result;
}


int main(int argc, char *argv[])
{
	char *s = "toto";
	char **result;

	result = urlencoded_to_strings(s);
	g_free(result);

	return 0;
}


