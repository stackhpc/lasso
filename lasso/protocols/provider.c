/* $Id: provider.c,v 1.45 2004/09/01 09:59:53 fpeters Exp $
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004 Entr'ouvert
 * http://lasso.entrouvert.org
 * 
 * Authors: Nicolas Clapies <nclapies@entrouvert.com>
 *          Valery Febvre <vfebvre@easter-eggs.com>
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

#include <lasso/protocols/provider.h>
#include <lasso/xml/errors.h>

struct _LassoProviderPrivate
{
  gboolean dispose_has_run;
};

static GObjectClass *parent_class = NULL;

/*****************************************************************************/
/* public methods                                                            */
/*****************************************************************************/

LassoProvider*
lasso_provider_copy(LassoProvider *provider)
{
  LassoProvider *copy;

  g_return_val_if_fail(LASSO_IS_PROVIDER(provider), NULL);

  copy = LASSO_PROVIDER(g_object_new(LASSO_TYPE_PROVIDER, NULL));
  copy->metadata = lasso_node_copy(provider->metadata);
  copy->public_key     = g_strdup(provider->public_key);
  copy->ca_certificate = g_strdup(provider->ca_certificate);

  return copy;
}

void
lasso_provider_destroy(LassoProvider *provider)
{
  g_object_unref(G_OBJECT(provider));
}

gchar *
lasso_provider_dump(LassoProvider *provider)
{
  LassoNode *provider_node, *metadata_node;
  LassoNodeClass *provider_class;
  gchar *provider_dump;

  provider_node = lasso_node_new();

  /* set the public key, ca_certificate, metadata */
  provider_class = LASSO_NODE_GET_CLASS(provider_node);
  provider_class->set_name(provider_node, LASSO_PROVIDER_NODE);
  provider_class->set_ns(provider_node, lassoLassoHRef, NULL);
  
  metadata_node = lasso_node_copy(provider->metadata);
  provider_class->add_child(provider_node, metadata_node, FALSE);
  lasso_node_destroy(metadata_node);
  if(provider->public_key != NULL) {
    provider_class->set_prop(provider_node, LASSO_PROVIDER_PUBLIC_KEY_NODE,
			     provider->public_key);
  }
  if(provider->ca_certificate != NULL) {
    provider_class->set_prop(provider_node, LASSO_PROVIDER_CA_CERTIFICATE_NODE,
			     provider->ca_certificate);
  }
  provider_dump = lasso_node_export(provider_node);

  lasso_node_destroy(provider_node);

  return provider_dump;
}

gchar *
lasso_provider_get_metadata_value(LassoProvider      *provider,
				  lassoProviderType   provider_type,
				  gchar              *name,
				  GError            **err)
{
  xmlChar *content;
  LassoNode *descriptor;
  GError *tmp_err = NULL;
  gchar *result = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  if (LASSO_IS_PROVIDER(provider) == FALSE) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ,
		lasso_strerror(LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ));
    g_return_val_if_fail(LASSO_IS_PROVIDER(provider), NULL);
  }
  if (name == NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_INVALID_VALUE,
		lasso_strerror(LASSO_PARAM_ERROR_INVALID_VALUE));
    g_return_val_if_fail(name != NULL, NULL);
  }

  switch (provider_type) {
  case lassoProviderTypeSp:
    descriptor = lasso_node_get_child(provider->metadata,
				      "SPDescriptor", NULL, &tmp_err);
    break;
  case lassoProviderTypeIdp:
    descriptor = lasso_node_get_child(provider->metadata,
				      "IDPDescriptor", NULL, &tmp_err);
    break;
  default:
    descriptor = NULL;
    break;
  }
  if (descriptor == NULL) {
    g_propagate_error (err, tmp_err);
    return NULL;
  }

  content = lasso_node_get_child_content(descriptor, name, NULL, &tmp_err);
  lasso_node_destroy(descriptor);

  if (content == NULL) {
    g_propagate_error (err, tmp_err);
  } else {
    result = g_strdup(g_strstrip(content));
    xmlFree(content);
  }

  return result;
}

gchar *
lasso_provider_get_assertionConsumerServiceURL(LassoProvider      *provider,
					       lassoProviderType   provider_type,
					       GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }

  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "AssertionConsumerServiceURL",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_authnRequestsSigned(LassoProvider  *provider,
				       GError        **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }

  value = lasso_provider_get_metadata_value(provider,
					    lassoProviderTypeSp,
					    "AuthnRequestsSigned",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_federationTerminationNotificationProtocolProfile(LassoProvider      *provider,
								    lassoProviderType   provider_type,
								    GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }

  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "FederationTerminationNotificationProtocolProfile",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_federationTerminationServiceReturnURL(LassoProvider      *provider,
							 lassoProviderType   provider_type,
							 GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }

  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "FederationTerminationServiceReturnURL",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_federationTerminationServiceURL(LassoProvider      *provider,
						   lassoProviderType   provider_type,
						   GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }

  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "FederationTerminationServiceURL",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_nameIdentifierMappingProtocolProfile(LassoProvider      *provider,
							lassoProviderType   provider_type,
							GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  
  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "NameIdentifierMappingProtocolProfile",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_providerID(LassoProvider  *provider)
{
  LassoNode *descriptor;
  xmlChar *value;
  GError  *err = NULL;

  descriptor = lasso_node_get_child(provider->metadata,
				    "EntityDescriptor", NULL, &err);    
  if (descriptor == NULL) {
    message(G_LOG_LEVEL_CRITICAL, err->message);
    g_error_free(err);
    return NULL;
  }

  value = lasso_node_get_attr_value(descriptor, "providerID", &err);
  lasso_node_destroy(descriptor);

  if (value == NULL) {
    /* providerID attr is required */
    message(G_LOG_LEVEL_CRITICAL, err->message);
    g_error_free(err);
  }

  return value;
}

gchar *
lasso_provider_get_registerNameIdentifierProtocolProfile(LassoProvider      *provider,
							 lassoProviderType   provider_type,
							 GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  
  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "RegisterNameIdentifierProtocolProfile",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_registerNameIdentifierServiceURL(LassoProvider      *provider,
						    lassoProviderType   provider_type,
						    GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  
  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "RegisterNameIdentifierServiceURL",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_singleSignOnProtocolProfile(LassoProvider  *provider,
					       GError        **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  
  value = lasso_provider_get_metadata_value(provider,
					    lassoProviderTypeIdp,
					    "SingleSignOnProtocolProfile",
					    &tmp_err);
  if (tmp_err != NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_singleSignOnServiceURL(LassoProvider  *provider,
					  GError        **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  
  value = lasso_provider_get_metadata_value(provider,
					    lassoProviderTypeIdp,
					    "SingleSignOnServiceURL",
					    &tmp_err);
  if (tmp_err != NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_singleLogoutProtocolProfile(LassoProvider      *provider,
					       lassoProviderType   provider_type,
					       GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  
  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "SingleLogoutProtocolProfile",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_singleLogoutServiceURL(LassoProvider      *provider,
					  lassoProviderType   provider_type,
					  GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  
  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "SingleLogoutServiceURL",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_singleLogoutServiceReturnURL(LassoProvider      *provider,
						lassoProviderType   provider_type,
						GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  
  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "SingleLogoutServiceReturnURL",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

gchar *
lasso_provider_get_soapEndpoint(LassoProvider      *provider,
				lassoProviderType   provider_type,
				GError            **err)
{
  xmlChar *value;
  GError  *tmp_err = NULL;

  if (err != NULL && *err != NULL) {
    g_set_error(err, g_quark_from_string("Lasso"),
		LASSO_PARAM_ERROR_CHECK_FAILED,
		lasso_strerror(LASSO_PARAM_ERROR_CHECK_FAILED));
    g_return_val_if_fail (err == NULL || *err == NULL, NULL);
  }
  
  value = lasso_provider_get_metadata_value(provider,
					    provider_type,
					    "SoapEndpoint",
					    &tmp_err);
  if (value == NULL) {
    g_propagate_error (err, tmp_err);
  }

  return value;
}

void
lasso_provider_set_public_key(LassoProvider *provider,
			      gchar         *public_key)
{
  provider->public_key = g_strdup(public_key);
}

void
lasso_provider_set_ca_certificate(LassoProvider *provider,
				  gchar *ca_certificate)
{
  provider->ca_certificate = g_strdup(ca_certificate);
}

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/

static gchar *lasso_provider_get_direct_child_content(LassoProvider *provider, 
						      const gchar   *name)
{
  LassoNode *node;
  xmlChar *content;

  node = lasso_node_get_child(LASSO_NODE(provider), name, NULL, NULL);
  if(node == NULL) {
    return NULL;
  }
  content = lasso_node_get_content(node, NULL);
  lasso_node_destroy(node);

  return content;
}

/*****************************************************************************/
/* overrided parent class methods                                            */
/*****************************************************************************/

static void
lasso_provider_dispose(LassoProvider *provider)
{
  if (provider->private->dispose_has_run) {
    return;
  }
  provider->private->dispose_has_run = TRUE;

  debug("Provider object 0x%x disposed ...\n", provider);

  /* unref reference counted objects */
  lasso_node_destroy(provider->metadata);

  parent_class->dispose(G_OBJECT(provider));
}

static void
lasso_provider_finalize(LassoProvider *provider)
{
  debug("Provider object 0x%x finalized ...\n", provider);

  g_free(provider->public_key);
  g_free(provider->ca_certificate);
  g_free(provider->private);

  parent_class->finalize(G_OBJECT(provider));
}

/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
lasso_provider_instance_init(LassoProvider *provider)
{
  provider->private = g_new (LassoProviderPrivate, 1);
  provider->private->dispose_has_run = FALSE;
  provider->metadata       = NULL;
  provider->public_key     = NULL;
  provider->ca_certificate = NULL;
}

static void
lasso_provider_class_init(LassoProviderClass *class) {
  GObjectClass *gobject_class = G_OBJECT_CLASS(class);
  
  parent_class = g_type_class_peek_parent(class);
  /* override parent class methods */
  gobject_class->dispose  = (void *)lasso_provider_dispose;
  gobject_class->finalize = (void *)lasso_provider_finalize;
}

GType lasso_provider_get_type() {
  static GType this_type = 0;

  if (!this_type) {
    static const GTypeInfo this_info = {
      sizeof (LassoProviderClass),
      NULL,
      NULL,
      (GClassInitFunc) lasso_provider_class_init,
      NULL,
      NULL,
      sizeof(LassoProvider),
      0,
      (GInstanceInitFunc) lasso_provider_instance_init,
    };
    
    this_type = g_type_register_static(G_TYPE_OBJECT,
				       "LassoProvider",
				       &this_info, 0);
  }
  return this_type;
}

LassoProvider*
lasso_provider_new(gchar *metadata,
		   gchar *public_key,
		   gchar *ca_certificate)
{
  LassoProvider *provider;
  
  provider = lasso_provider_new_metadata_filename(metadata);
  if (provider != NULL) {
    provider->public_key = g_strdup(public_key);
    provider->ca_certificate = g_strdup(ca_certificate);
  }

  return provider;
}


LassoProvider*
lasso_provider_new_from_metadata_node(LassoNode *metadata_node)
{
  LassoProvider *provider;
  
  provider = LASSO_PROVIDER(g_object_new(LASSO_TYPE_PROVIDER, NULL));
  provider->metadata = lasso_node_copy(metadata_node);
  
  return provider;
}

LassoProvider*
lasso_provider_new_metadata_filename(gchar *metadata_filename)
{
  LassoProvider *provider = NULL;
  xmlDocPtr  doc;
  xmlNodePtr root;
  
  doc = xmlParseFile(metadata_filename);
  if (doc != NULL) {
    /* get root element of doc and duplicate it */
    root = xmlCopyNode(xmlDocGetRootElement(doc), 1);
    xmlFreeDoc(doc);

    provider = LASSO_PROVIDER(g_object_new(LASSO_TYPE_PROVIDER, NULL));
    provider->metadata = lasso_node_new();
    LASSO_NODE_GET_CLASS(provider->metadata)->set_xmlNode(provider->metadata, root);
  }
  else {
    message(G_LOG_LEVEL_CRITICAL,
	    "Failed to build LassoProvider: invalid metadata file.\n");
  }

  return provider;
}
