#include <lasso/lasso.h>

lasso_init();

/*
 * Logout initiated by service provider: Send a logout request to identity provider.
 *
 * Called when the user press logout button on service provider.
 */

server_dump = [...] /* Load string server_dump from file or database or... */
server = lasso_server_new_from_dump(server_dump);
g_free(server_dump);
logout = lasso_logout_new(server, lassoProviderTypeSp);
user_dump = [...] /* Load string user_dump from logged user account. */
if (lasso_profile_set_user_dump(logout, user_dump))
	[...] /* Handle error. */
g_free(user_dump);
if (lasso_logout_init_request(logout) != 0)
	[...] /* Handle error. */
if (lasso_logout_build_request_msg(logout) != 0)
	[...] /* Handle error. */
if (logout->msg_body == NULL)
	[...] /* Reply an HTTP redirect to logout->msg_url. */
else {
	/* Send a logout SOAP message to identity provider. */
	soap_response = [...] /* Send SOAP message logout->msg_body to URL logout->msg_url. */
	if (lasso_logout_handle_response(logout, soap_response, lassoHttpSoap) != 0)
		[...] /* Handle error. */
	/* Save the updated user_dump into account. */
	user_dump = lasso_user_dump(login->user);
	[...] /* Store string user_dump into account (replace the previous one). */
	g_free(user_dump);
	/* User is now logged out => delete session, cookie... */
	[...]
}
lasso_logout_destroy(logout);
lasso_node_destroy(user);
lasso_node_destroy(server);

lasso_shutdown();
