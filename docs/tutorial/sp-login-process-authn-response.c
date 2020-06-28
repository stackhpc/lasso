#include <lasso/lasso.h>

lasso_init();

/*
 * Process the authentication response returned by identity provider and send received artifact to
 * identity provider.
 */

query = [...] /* Get current URL query. */
server_dump = [...] /* Load string server_dump from file or database or... */
server = lasso_server_new_from_dump(server_dump);
g_free(server_dump);
login = lasso_login_new(server);
if (lasso_login_init_request(login, query, lassoHttpRedirect) != 0)
	[...] /* Handle error. */
if (lasso_login_build_request_msg(login) != 0)
	[...] /* Handle error. */
soap_response = [...] /* Send SOAP message login->msg_body to URL login->msg_url. */
if (lasso_login_process_response(login, soap_response) != 0)
	[...] /* Handle error. */
name_identifier = lasso_response_get_name_identifier(login->response);
account = [...] /* Retrieve user account having this name_identifier. */
if (account == NULL) {
	account = [...] /* Create new account. */
	user_dump = NULL;
}
else
	user_dump = [...] /* Retrieve string user_dump from account. */
lasso_login_set_user_from_dump(login, user_dump);
if (user_dump != NULL)
	g_free(user_dump);
user_dump = lasso_user_dump(login->user);
[...] /* Store string user_dump into account. */
g_free(user_dump);
g_free(name_identifier);
lasso_login_destroy(login);
lasso_node_destroy(server);
/* User is now authenticated => create session, cookie... */
[...]

lasso_shutdown();
