/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Server {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected Server(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Server obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      lassoJNI.delete_Server(swigCPtr);
    }
    swigCPtr = 0;
  }

  public void setCertificate(String value) {
    lassoJNI.Server_certificate_set(swigCPtr, value);
  }

  public String getCertificate() {
    return lassoJNI.Server_certificate_get(swigCPtr);
  }

  public void setPrivateKey(String value) {
    lassoJNI.Server_privateKey_set(swigCPtr, value);
  }

  public String getPrivateKey() {
    return lassoJNI.Server_privateKey_get(swigCPtr);
  }

  public void setPrivateKeyPassword(String value) {
    lassoJNI.Server_privateKeyPassword_set(swigCPtr, value);
  }

  public String getPrivateKeyPassword() {
    return lassoJNI.Server_privateKeyPassword_get(swigCPtr);
  }

  public void setSignatureMethod(int value) {
    lassoJNI.Server_signatureMethod_set(swigCPtr, value);
  }

  public int getSignatureMethod() {
    return lassoJNI.Server_signatureMethod_get(swigCPtr);
  }

  public void setCaCertChain(String value) {
    lassoJNI.Server_caCertChain_set(swigCPtr, value);
  }

  public String getCaCertChain() {
    return lassoJNI.Server_caCertChain_get(swigCPtr);
  }

  public void setMetadataFilename(String value) {
    lassoJNI.Server_metadataFilename_set(swigCPtr, value);
  }

  public String getMetadataFilename() {
    return lassoJNI.Server_metadataFilename_get(swigCPtr);
  }

  public void setProviderId(String value) {
    lassoJNI.Server_providerId_set(swigCPtr, value);
  }

  public String getProviderId() {
    return lassoJNI.Server_providerId_get(swigCPtr);
  }

  public void setPublicKey(String value) {
    lassoJNI.Server_publicKey_set(swigCPtr, value);
  }

  public String getPublicKey() {
    return lassoJNI.Server_publicKey_get(swigCPtr);
  }

  public void setRole(int value) {
    lassoJNI.Server_role_set(swigCPtr, value);
  }

  public int getRole() {
    return lassoJNI.Server_role_get(swigCPtr);
  }

  public StringList getProviderIds() {
    long cPtr = lassoJNI.Server_providerIds_get(swigCPtr);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public Server(String metadata, String privateKey, String privateKeyPassword, String certificate) {
    this(lassoJNI.new_Server(metadata, privateKey, privateKeyPassword, certificate), true);
  }

  public static Server newFromDump(String dump) {
    long cPtr = lassoJNI.Server_newFromDump(dump);
    return (cPtr == 0) ? null : new Server(cPtr, true);
  }

  public boolean acceptHttpMethod(Provider remote_provider, int protocol_type, int http_method, boolean initiate_profile) {
    return lassoJNI.Server_acceptHttpMethod(swigCPtr, Provider.getCPtr(remote_provider), protocol_type, http_method, initiate_profile);
  }

  public String getAssertionConsumerServiceUrl(String service_id) {
    return lassoJNI.Server_getAssertionConsumerServiceUrl(swigCPtr, service_id);
  }

  public String getBase64SuccinctId() {
    return lassoJNI.Server_getBase64SuccinctId(swigCPtr);
  }

  public String getOrganization() {
    return lassoJNI.Server_getOrganization(swigCPtr);
  }

  public int getFirstHttpMethod(Provider remote_provider, int protocol_type) {
    return lassoJNI.Server_getFirstHttpMethod(swigCPtr, Provider.getCPtr(remote_provider), protocol_type);
  }

  public String getMetadataOne(String name) {
    return lassoJNI.Server_getMetadataOne(swigCPtr, name);
  }

  public boolean hasProtocolProfile(int protocol_type, String protocol_profile) {
    return lassoJNI.Server_hasProtocolProfile(swigCPtr, protocol_type, protocol_profile);
  }

  public int getProtocolConformance() {
    return lassoJNI.Server_getProtocolConformance(swigCPtr);
  }

  public int addProvider(int role, String metadata, String publicKey, String caCertChain) {
    return lassoJNI.Server_addProvider(swigCPtr, role, metadata, publicKey, caCertChain);
  }

  public String dump() {
    return lassoJNI.Server_dump(swigCPtr);
  }

  public Provider getProvider(String providerId) {
    long cPtr = lassoJNI.Server_getProvider(swigCPtr, providerId);
    return (cPtr == 0) ? null : new Provider(cPtr, false);
  }

}
