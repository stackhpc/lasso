#include <lasso/lasso.h>

lasso_init();

/*
 * Logout initiated by service provider (continued): Process the HTTP redirect logout response
 * returned by identity provider.
 */

query = [...] /* Get current URL query. */
server_dump = [...] /* Load string server_dump from file or database or... */
server = lasso_server_new_from_dump(server_dump);
g_free(server_dump);
logout = lasso_logout_new(server, lassoProviderTypeSp);
user_dump = [...] /* Load string user_dump from logged user account. */
if (lasso_profile_set_user_dump(logout, user_dump))
	[...] /* Handle error. */
g_free(user_dump);
if (lasso_logout_handle_response(logout, query, lassoHttpRedirect) != 0)
	[...] /* Handle error. */
/* Save the updated user_dump into account. */
user_dump = lasso_user_dump(login->user);
[...] /* Store string user_dump into account (replace the previous one). */
g_free(user_dump);
lasso_logout_destroy(logout);
lasso_node_destroy(user);
lasso_node_destroy(server);
/* User is now logged out => delete session, cookie... */
[...]

lasso_shutdown();
