#include <lasso/lasso.h>

lasso_init();

/*
 * Redirect Logout initiated by identity provider.
 */

query = [...] /* Get current URL query. */
server_dump = [...] /* Load string server_dump from file or database or... */
server = lasso_server_new_from_dump(server_dump);
g_free(server_dump);
logout = lasso_logout_new(server, lassoProviderTypeSp);
if (lasso_logout_handle_request(logout, query, lassoHttpRedirect) != 0)
	[...] /* Handle error. */
name_identifier = lasso_response_get_name_identifier(logout->response);
account = [...] /* Retrieve user account having this name_identifier. */
if (account == NULL)
	/* Unknown account. */
	lasso_profile_set_response_status(logout, lassoLibStatusCodeUnknownPrincipal);
else {
	user_dump = [...] /* Retrieve string user_dump from account. */
	if (user_dump == NULL)
		lasso_profile_set_response_status(logout, lassoLibStatusCodeUnknownPrincipal);
	else {
		user = lasso_user_new_from_dump(user_dump);
		g_free(user_dump);
		lasso_user_remove_authn_assertion(user);
		user_dump = lasso_user_dump(user);
		[...] /* Store string user_dump into account (replace the previous one). */
		g_free(user_dump);
		lasso_node_destroy(user);
		/* User is now logged out => delete session, cookie... */
		[...]
	}
}
if (lasso_logout_build_response_msg(logout) != 0)
	[...] /* Handle error. */
[...] /* Reply a HTTP redirect to logout->msg_url. */
lasso_logout_destroy(logout);
lasso_node_destroy(server);

lasso_shutdown();
