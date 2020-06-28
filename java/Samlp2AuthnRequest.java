/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Samlp2AuthnRequest extends Samlp2RequestAbstract {
  protected Samlp2AuthnRequest(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Samlp2AuthnRequest obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setForceAuthn(boolean value) {
    lassoJNI.Samlp2AuthnRequest_forceAuthn_set(swigCPtr, value);
  }

  public boolean getForceAuthn() {
    return lassoJNI.Samlp2AuthnRequest_forceAuthn_get(swigCPtr);
  }

  public void setIsPassive(boolean value) {
    lassoJNI.Samlp2AuthnRequest_isPassive_set(swigCPtr, value);
  }

  public boolean getIsPassive() {
    return lassoJNI.Samlp2AuthnRequest_isPassive_get(swigCPtr);
  }

  public void setProtocolBinding(String value) {
    lassoJNI.Samlp2AuthnRequest_ProtocolBinding_set(swigCPtr, value);
  }

  public String getProtocolBinding() {
    return lassoJNI.Samlp2AuthnRequest_ProtocolBinding_get(swigCPtr);
  }

  public void setAssertionConsumerServiceIndex(int value) {
    lassoJNI.Samlp2AuthnRequest_assertionConsumerServiceIndex_set(swigCPtr, value);
  }

  public int getAssertionConsumerServiceIndex() {
    return lassoJNI.Samlp2AuthnRequest_assertionConsumerServiceIndex_get(swigCPtr);
  }

  public void setAssertionConsumerServiceURL(String value) {
    lassoJNI.Samlp2AuthnRequest_AssertionConsumerServiceURL_set(swigCPtr, value);
  }

  public String getAssertionConsumerServiceURL() {
    return lassoJNI.Samlp2AuthnRequest_AssertionConsumerServiceURL_get(swigCPtr);
  }

  public void setAttributeConsumingServiceIndex(int value) {
    lassoJNI.Samlp2AuthnRequest_attributeConsumingServiceIndex_set(swigCPtr, value);
  }

  public int getAttributeConsumingServiceIndex() {
    return lassoJNI.Samlp2AuthnRequest_attributeConsumingServiceIndex_get(swigCPtr);
  }

  public void setProviderName(String value) {
    lassoJNI.Samlp2AuthnRequest_ProviderName_set(swigCPtr, value);
  }

  public String getProviderName() {
    return lassoJNI.Samlp2AuthnRequest_ProviderName_get(swigCPtr);
  }

  public void setSubject(Saml2Subject value) {
    lassoJNI.Samlp2AuthnRequest_subject_set(swigCPtr, Saml2Subject.getCPtr(value));
  }

  public Saml2Subject getSubject() {
    long cPtr = lassoJNI.Samlp2AuthnRequest_subject_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2Subject(cPtr, false);
  }

  public void setNameIDPolicy(Samlp2NameIDPolicy value) {
    lassoJNI.Samlp2AuthnRequest_nameIDPolicy_set(swigCPtr, Samlp2NameIDPolicy.getCPtr(value));
  }

  public Samlp2NameIDPolicy getNameIDPolicy() {
    long cPtr = lassoJNI.Samlp2AuthnRequest_nameIDPolicy_get(swigCPtr);
    return (cPtr == 0) ? null : new Samlp2NameIDPolicy(cPtr, false);
  }

  public void setConditions(Saml2Conditions value) {
    lassoJNI.Samlp2AuthnRequest_conditions_set(swigCPtr, Saml2Conditions.getCPtr(value));
  }

  public Saml2Conditions getConditions() {
    long cPtr = lassoJNI.Samlp2AuthnRequest_conditions_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2Conditions(cPtr, false);
  }

  public void setRequestedAuthnContext(Samlp2RequestedAuthnContext value) {
    lassoJNI.Samlp2AuthnRequest_requestedAuthnContext_set(swigCPtr, Samlp2RequestedAuthnContext.getCPtr(value));
  }

  public Samlp2RequestedAuthnContext getRequestedAuthnContext() {
    long cPtr = lassoJNI.Samlp2AuthnRequest_requestedAuthnContext_get(swigCPtr);
    return (cPtr == 0) ? null : new Samlp2RequestedAuthnContext(cPtr, false);
  }

  public void setScoping(Samlp2Scoping value) {
    lassoJNI.Samlp2AuthnRequest_scoping_set(swigCPtr, Samlp2Scoping.getCPtr(value));
  }

  public Samlp2Scoping getScoping() {
    long cPtr = lassoJNI.Samlp2AuthnRequest_scoping_get(swigCPtr);
    return (cPtr == 0) ? null : new Samlp2Scoping(cPtr, false);
  }

  public void setIssuer(Saml2NameID value) {
    lassoJNI.Samlp2AuthnRequest_issuer_set(swigCPtr, Saml2NameID.getCPtr(value));
  }

  public Saml2NameID getIssuer() {
    long cPtr = lassoJNI.Samlp2AuthnRequest_issuer_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2NameID(cPtr, false);
  }

  public void setExtensions(Samlp2Extensions value) {
    lassoJNI.Samlp2AuthnRequest_Extensions_set(swigCPtr, Samlp2Extensions.getCPtr(value));
  }

  public Samlp2Extensions getExtensions() {
    long cPtr = lassoJNI.Samlp2AuthnRequest_Extensions_get(swigCPtr);
    return (cPtr == 0) ? null : new Samlp2Extensions(cPtr, false);
  }

  public void setID(String value) {
    lassoJNI.Samlp2AuthnRequest_ID_set(swigCPtr, value);
  }

  public String getID() {
    return lassoJNI.Samlp2AuthnRequest_ID_get(swigCPtr);
  }

  public void setVersion(String value) {
    lassoJNI.Samlp2AuthnRequest_Version_set(swigCPtr, value);
  }

  public String getVersion() {
    return lassoJNI.Samlp2AuthnRequest_Version_get(swigCPtr);
  }

  public void setIssueInstant(String value) {
    lassoJNI.Samlp2AuthnRequest_issueInstant_set(swigCPtr, value);
  }

  public String getIssueInstant() {
    return lassoJNI.Samlp2AuthnRequest_issueInstant_get(swigCPtr);
  }

  public void setDestination(String value) {
    lassoJNI.Samlp2AuthnRequest_Destination_set(swigCPtr, value);
  }

  public String getDestination() {
    return lassoJNI.Samlp2AuthnRequest_Destination_get(swigCPtr);
  }

  public void setConsent(String value) {
    lassoJNI.Samlp2AuthnRequest_Consent_set(swigCPtr, value);
  }

  public String getConsent() {
    return lassoJNI.Samlp2AuthnRequest_Consent_get(swigCPtr);
  }

  public Samlp2AuthnRequest() {
    this(lassoJNI.new_Samlp2AuthnRequest(), true);
  }

  public String dump() {
    return lassoJNI.Samlp2AuthnRequest_dump(swigCPtr);
  }

}
