#include <lasso/lasso.h>

lasso_init();

/*
 * Initialize service provider context.
 *
 * This initialization can be done at service provider configuration or launch.
 * Once inited, this service provider context is never changed.
 */

char *metadata_file_path, *public_key_file_path, *private_key_file_path, *certificate_file_path;
char *idp_metadata_file_path, *idp_public_key_file_path, *idp_ca_certificate_file_path;
LassoServer *server;
char *server_dump;

/* Initialize with service provider informations. */
[...] /* Get metadata_file_path, public_key_file_path, private_key_file_path &
         certificate_file_path. */
/* The last argument lassoSignatureMethod... must be the method used to crypt the private key. */
server = lasso_server_new(metadata_file_path, public_key_file_path, private_key_file_path,
			  certificate_file_path, lassoSignatureMethodRsaSha1);

/* Add identity provider informations. */
[...] /* Get idp_metadata_file_path, idp_public_key_file_path & idp_ca_certificate_file_path. */
lasso_server_add_provider(server, idp_metadata_file_path, idp_public_key_file_path,
			  idp_ca_certificate_file_path);

/* Dump server context to a string and store it in a file. */
server_dump = lasso_server_dump(server);
lasso_node_destroy(server);
[...] /* Save server_dump in a file or database or... */
g_free(server_dump);

lasso_shutdown();
