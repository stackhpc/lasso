/* $Id: server.c,v 1.106 2005/08/24 16:28:46 fpeters Exp $
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004, 2005 Entr'ouvert
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

#include <xmlsec/base64.h>

#include <lasso/lasso_config.h>
#include <lasso/id-ff/server.h>

#include <lasso/id-ff/providerprivate.h>
#include <lasso/id-ff/serverprivate.h>

struct _LassoServerPrivate
{
	gboolean dispose_has_run;
};

/*****************************************************************************/
/* public methods                                                            */
/*****************************************************************************/

/**
 * lasso_server_add_provider:
 * @server: a #LassoServer
 * @role: provider role, identity provider or service provider
 * @metadata: path to the provider metadata file
 * @public_key: provider public key file (may be a certificate) or NULL
 * @ca_cert_chain: provider CA certificate chain file or NULL
 * 
 * Creates a new #LassoProvider and makes it known to the @server
 * 
 * Return value: 0 on success; a negative value if an error occured.
 **/
gint
lasso_server_add_provider(LassoServer *server, LassoProviderRole role,
		const gchar *metadata, const gchar *public_key, const gchar *ca_cert_chain)
{
	LassoProvider *provider;

	g_return_val_if_fail(LASSO_IS_SERVER(server), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(metadata != NULL, LASSO_PARAM_ERROR_INVALID_VALUE);

	provider = lasso_provider_new(role, metadata, public_key, ca_cert_chain);
	if (provider == NULL) {
		return critical_error(LASSO_SERVER_ERROR_ADD_PROVIDER_FAILED);
	}

	g_hash_table_insert(server->providers, g_strdup(provider->ProviderID), provider);

	return 0;
}


/**
 * lasso_server_add_service:
 * @server: a #LassoServer
 * @service:
 * 
 * ...
 * 
 * Return value: 0 on success; a negative value if an error occured.
 **/
gint
lasso_server_add_service(LassoServer *server, LassoDiscoServiceInstance *service)
{
#ifdef LASSO_WSF_ENABLED
	g_return_val_if_fail(LASSO_IS_SERVER(server), LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);
	g_return_val_if_fail(LASSO_IS_DISCO_SERVICE_INSTANCE(service),
			LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ);

	g_hash_table_insert(server->services, g_strdup(service->ServiceType),
			g_object_ref(service));
#endif

	return 0;
}


/**
 * lasso_server_destroy:
 * @server: a #LassoServer
 *
 * Destroys a server.
 **/
void
lasso_server_destroy(LassoServer *server)
{
	lasso_node_destroy(LASSO_NODE(server));
}


/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static struct XmlSnippet schema_snippets[] = {
	{ "PrivateKeyFilePath", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoServer, private_key) },
	{ "PrivateKeyPassword", SNIPPET_CONTENT,
		G_STRUCT_OFFSET(LassoServer, private_key_password) },
	{ "CertificateFilePath", SNIPPET_CONTENT, G_STRUCT_OFFSET(LassoServer, certificate) },
	{ NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;

static void
add_provider_childnode(gchar *key, LassoProvider *value, xmlNode *xmlnode)
{
	xmlAddChild(xmlnode, lasso_node_get_xmlNode(LASSO_NODE(value), TRUE));
}

static void
add_service_childnode(gchar *key, LassoNode *value, xmlNode *xmlnode)
{
	xmlAddChild(xmlnode, lasso_node_get_xmlNode(LASSO_NODE(value), TRUE));
}

static xmlNode*
get_xmlNode(LassoNode *node, gboolean lasso_dump)
{
	LassoServer *server = LASSO_SERVER(node);
	char *signature_methods[] = { NULL, "RSA_SHA1", "DSA_SHA1"};
	xmlNode *xmlnode;

	xmlnode = parent_class->get_xmlNode(node, lasso_dump);
	xmlSetProp(xmlnode, (xmlChar*)"ServerDumpVersion", (xmlChar*)"2");
	xmlSetProp(xmlnode, (xmlChar*)"SignatureMethod",
			(xmlChar*)signature_methods[server->signature_method]);

	/* Providers */
	if (g_hash_table_size(server->providers)) {
		xmlNode *t;
		t = xmlNewTextChild(xmlnode, NULL, (xmlChar*)"Providers", NULL);
		g_hash_table_foreach(server->providers,
				(GHFunc)add_provider_childnode, t);
	}

	/* Services */
	if (g_hash_table_size(server->services)) {
		xmlNode *t;
		t = xmlNewTextChild(xmlnode, NULL, (xmlChar*)"Services", NULL);
		g_hash_table_foreach(server->services,
				(GHFunc)add_service_childnode, t);
	}

	xmlCleanNs(xmlnode);

	return xmlnode;
}


static int
init_from_xml(LassoNode *node, xmlNode *xmlnode)
{
	LassoServer *server = LASSO_SERVER(node);
	xmlNode *t;
	xmlChar *s;
	int rc;

	rc = parent_class->init_from_xml(node, xmlnode);
	if (rc)
		return rc;

	s = xmlGetProp(xmlnode, (xmlChar*)"SignatureMethod");
	if (s && strcmp((char*)s, "RSA_SHA1") == 0)
		server->signature_method = LASSO_SIGNATURE_METHOD_RSA_SHA1;
	if (s && strcmp((char*)s, "DSA_SHA1") == 0)
		server->signature_method = LASSO_SIGNATURE_METHOD_DSA_SHA1;
	if (s)
		xmlFree(s);

	t = xmlnode->children;
	while (t) {
		xmlNode *t2 = t->children;

		if (t->type != XML_ELEMENT_NODE) {
			t = t->next;
			continue;
		}

		if (strcmp((char*)t->name, "Providers") == 0) {
			while (t2) {
				LassoProvider *p;
				if (t2->type != XML_ELEMENT_NODE) {
					t2 = t2->next;
					continue;
				}
				p = g_object_new(LASSO_TYPE_PROVIDER, NULL);
				LASSO_NODE_GET_CLASS(p)->init_from_xml(LASSO_NODE(p), t2);
				if (lasso_provider_load_public_key(p) == TRUE) {
					g_hash_table_insert(server->providers,
							g_strdup(p->ProviderID), p);
				} else {
					message(G_LOG_LEVEL_CRITICAL,
							"Failed to load public key for %s.",
							p->ProviderID);
				}
				t2 = t2->next;
			}
		}
		
#ifdef LASSO_WSF_ENABLED
		if (strcmp((char*)t->name, "Services") == 0) {
			while (t2) {
				LassoDiscoServiceInstance *s;
				if (t2->type != XML_ELEMENT_NODE) {
					t2 = t2->next;
					continue;
				}
				s = g_object_new(LASSO_TYPE_DISCO_SERVICE_INSTANCE, NULL);
				LASSO_NODE_GET_CLASS(s)->init_from_xml(LASSO_NODE(s), t2);
				g_hash_table_insert(server->services, g_strdup(s->ServiceType), s);
				t2 = t2->next;
			}
		}
#endif

		t = t->next;
	}

	return 0;
}


static gboolean
get_first_providerID(gchar *key, gpointer value, char **providerID)
{
	*providerID = key;
	return TRUE;
}

/**
 * lasso_server_get_first_providerID:
 * @server: a #LassoServer
 *
 * Looks up and returns the provider ID of a known provider
 *
 * Return value: the provider ID, NULL if there are no providers.  This string
 *      must be freed by the caller.
 **/
gchar*
lasso_server_get_first_providerID(LassoServer *server)
{
	gchar *providerID = NULL;

	g_hash_table_find(server->providers, (GHRFunc)get_first_providerID, &providerID);
	return g_strdup(providerID);
}


/**
 * lasso_server_get_provider:
 * @server: a #LassoServer
 * @providerID: the provider ID
 *
 * Looks up for a #LassoProvider whose ID is @providerID and returns it.
 *
 * Return value: the #LassoProvider, NULL if it was not found.  The
 *     #LassoProvider is owned by Lasso and should not be freed.
 **/
LassoProvider*
lasso_server_get_provider(LassoServer *server, gchar *providerID)
{
	return g_hash_table_lookup(server->providers, providerID);
}


/**
 * lasso_server_get_service:
 * @server: a #LassoServer
 * @serviceType:
 *
 * ...
 *
 * Return value: the #LassoDiscoServiceInstance, NULL if it was not found.
 *     The #LassoDiscoServiceInstance is owned by Lasso and should not be
 *     freed.
 **/
LassoDiscoServiceInstance*
lasso_server_get_service(LassoServer *server, gchar *serviceType)
{
	return g_hash_table_lookup(server->services, serviceType);
}


static gboolean
get_providerID_with_hash(gchar *key, gpointer value, char **providerID)
{
	char *hash = *providerID;
	xmlChar *hash_providerID;
	char *b64_hash_providerID;

	hash_providerID = (xmlChar*)lasso_sha1(key);
	b64_hash_providerID = (char*)xmlSecBase64Encode(hash_providerID, 20, 0);
	xmlFree(hash_providerID);

	if (strcmp(b64_hash_providerID, hash) == 0) {
		xmlFree(b64_hash_providerID);
		*providerID = key;
		return TRUE;
	}
	xmlFree(b64_hash_providerID);

	return FALSE;
}


/**
 * lasso_server_get_providerID_from_hash:
 * @server: a #LassoServer
 * @b64_hash: the base64-encoded provider ID hash
 *
 * Looks up a #LassoProvider whose ID hash is @b64_hash and returns its
 * provider ID.
 *
 * Return value: the provider ID, NULL if it was not found.
 **/
gchar*
lasso_server_get_providerID_from_hash(LassoServer *server, gchar *b64_hash)
{
	gchar *providerID = b64_hash; /* kludge */

	if (g_hash_table_find(server->providers, (GHRFunc)get_providerID_with_hash, &providerID))
		return g_strdup(providerID);
	return NULL;
}

/*****************************************************************************/
/* overridden parent class methods                                           */
/*****************************************************************************/

static void
dispose(GObject *object)
{
	LassoServer *server = LASSO_SERVER(object);

	if (server->private_data->dispose_has_run == TRUE) {
		return;
	}
	server->private_data->dispose_has_run = TRUE;

	/* free allocated memory for hash tables */
	g_hash_table_destroy(server->providers);
	server->providers = NULL;

	G_OBJECT_CLASS(parent_class)->dispose(G_OBJECT(server));
}

static void
finalize(GObject *object)
{
	LassoServer *server = LASSO_SERVER(object);
	int i = 0;

	g_free(server->private_key);
	if (server->private_key_password) {
		while (server->private_key_password[i])
			server->private_key_password[i++] = 0;
	}
	g_free(server->private_key_password);
	g_free(server->certificate);
	g_free(server->private_data);

	G_OBJECT_CLASS(parent_class)->finalize(G_OBJECT(server));
}

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoServer *server)
{
	server->private_data = g_new(LassoServerPrivate, 1);
	server->private_data->dispose_has_run = FALSE;

	server->providers = g_hash_table_new_full(
			g_str_hash, g_str_equal, g_free,
			(GDestroyNotify)lasso_node_destroy);

	server->private_key = NULL;
	server->private_key_password = NULL;
	server->certificate = NULL;
	server->signature_method = LASSO_SIGNATURE_METHOD_RSA_SHA1;

	/* FIXME: set the value_destroy_func */
	server->services = g_hash_table_new_full(g_str_hash, g_str_equal,
						 (GDestroyNotify)g_free, NULL);
}

static void
class_init(LassoServerClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);
	
	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Server");
	lasso_node_class_set_ns(nclass, LASSO_LASSO_HREF, LASSO_LASSO_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);

	nclass->get_xmlNode = get_xmlNode;
	nclass->init_from_xml = init_from_xml;

	G_OBJECT_CLASS(klass)->dispose = dispose;
	G_OBJECT_CLASS(klass)->finalize = finalize;
}

GType
lasso_server_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoServerClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoServer),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_PROVIDER,
				"LassoServer", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_server_new:
 * @metadata: path to the provider metadata file
 * @private_key: path to the the server private key file or NULL
 * @private_key_password: password to private key (if it is encrypted)
 * @certificate: path to the server certificate file
 * 
 * Creates a new #LassoServer.
 * 
 * Return value: a newly created #LassoServer object; or NULL if an error
 *      occured
 **/
LassoServer*
lasso_server_new(const gchar *metadata,
		 const gchar *private_key,
		 const gchar *private_key_password,
		 const gchar *certificate)
{
	LassoServer *server;

	server = g_object_new(LASSO_TYPE_SERVER, NULL);

	/* metadata can be NULL (if server is a LECP) */
	if (metadata != NULL) {
		if (lasso_provider_load_metadata(LASSO_PROVIDER(server), metadata) == FALSE) {
			message(G_LOG_LEVEL_CRITICAL,
					"Failed to load metadata from %s.", metadata);
			lasso_node_destroy(LASSO_NODE(server));
			return NULL;
		}
	}

	server->private_key = g_strdup(private_key);
	server->private_key_password = g_strdup(private_key_password);
	server->certificate = g_strdup(certificate);

	return server;
}

/**
 * lasso_server_new_from_dump:
 * @dump: XML server dump
 *
 * Restores the @dump to a new #LassoServer.
 *
 * Return value: a newly created #LassoServer; or NULL if an error occured
 **/
LassoServer*
lasso_server_new_from_dump(const gchar *dump)
{
	LassoNode *server;
	server = lasso_node_new_from_dump(dump);
	if (server == NULL)
		return NULL;

	if (LASSO_IS_SERVER(server) == FALSE) {
		lasso_node_destroy(LASSO_NODE(server));
		return NULL;
	}
	return LASSO_SERVER(server);
}

/**
 * lasso_server_dump:
 * @server: a #LassoServer
 *
 * Dumps @server content to an XML string.
 *
 * Return value: the dump string.  It must be freed by the caller.
 **/
gchar*
lasso_server_dump(LassoServer *server)
{
	return lasso_node_dump(LASSO_NODE(server));
}
