#include <lasso/lasso.h>

lasso_init();

/*
 * Send an authentication request to identity provider.
 *
 * Called when the user press login button on service provider.
 */

server_dump = [...] /* Load server_dump from file or database or... */
server = lasso_server_new_from_dump(server_dump);
g_free(server_dump);
login = lasso_login_new(server);
if (lasso_login_init_authn_request(login, "http://identification.entrouvert.org") != 0)
	[...] /* Handle error. */

/* Identity provider will ask user to authenticate himself. */
lasso_lib_authn_request_set_isPassive(login->request, FALSE);

/* Identity provider will not ask user to authenticate himself if he has already done it recently. */
/* lasso_lib_authn_request_set_forceAuthn(login->request, FALSE); */

/* Identity provider will create a federation with this service provider and this user, if this was */
/* not already done. */
lasso_lib_authn_request_set_nameIDPolicy(login->request, lassoLibNameIDPolicyTypeFederated);

if (lasso_login_build_authn_request_msg(login) != 0)
	[...] /* Handle error. */
[...] /* Reply a HTTP redirect to login->msg_url. */
lasso_login_destroy(login);
lasso_node_destroy(server);

lasso_shutdown();
