/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Samlp2LogoutRequest extends Samlp2RequestAbstract {
  protected Samlp2LogoutRequest(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Samlp2LogoutRequest obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setSessionIndex(String value) {
    lassoJNI.Samlp2LogoutRequest_sessionIndex_set(swigCPtr, value);
  }

  public String getSessionIndex() {
    return lassoJNI.Samlp2LogoutRequest_sessionIndex_get(swigCPtr);
  }

  public void setReason(String value) {
    lassoJNI.Samlp2LogoutRequest_Reason_set(swigCPtr, value);
  }

  public String getReason() {
    return lassoJNI.Samlp2LogoutRequest_Reason_get(swigCPtr);
  }

  public void setNotOnOrAfter(String value) {
    lassoJNI.Samlp2LogoutRequest_notOnOrAfter_set(swigCPtr, value);
  }

  public String getNotOnOrAfter() {
    return lassoJNI.Samlp2LogoutRequest_notOnOrAfter_get(swigCPtr);
  }

  public void setBaseID(Saml2BaseIDAbstract value) {
    lassoJNI.Samlp2LogoutRequest_baseID_set(swigCPtr, Saml2BaseIDAbstract.getCPtr(value));
  }

  public Saml2BaseIDAbstract getBaseID() {
    long cPtr = lassoJNI.Samlp2LogoutRequest_baseID_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2BaseIDAbstract(cPtr, false);
  }

  public void setNameID(Saml2NameID value) {
    lassoJNI.Samlp2LogoutRequest_nameID_set(swigCPtr, Saml2NameID.getCPtr(value));
  }

  public Saml2NameID getNameID() {
    long cPtr = lassoJNI.Samlp2LogoutRequest_nameID_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2NameID(cPtr, false);
  }

  public void setEncryptedID(Saml2EncryptedElement value) {
    lassoJNI.Samlp2LogoutRequest_encryptedID_set(swigCPtr, Saml2EncryptedElement.getCPtr(value));
  }

  public Saml2EncryptedElement getEncryptedID() {
    long cPtr = lassoJNI.Samlp2LogoutRequest_encryptedID_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2EncryptedElement(cPtr, false);
  }

  public void setIssuer(Saml2NameID value) {
    lassoJNI.Samlp2LogoutRequest_issuer_set(swigCPtr, Saml2NameID.getCPtr(value));
  }

  public Saml2NameID getIssuer() {
    long cPtr = lassoJNI.Samlp2LogoutRequest_issuer_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2NameID(cPtr, false);
  }

  public void setExtensions(Samlp2Extensions value) {
    lassoJNI.Samlp2LogoutRequest_Extensions_set(swigCPtr, Samlp2Extensions.getCPtr(value));
  }

  public Samlp2Extensions getExtensions() {
    long cPtr = lassoJNI.Samlp2LogoutRequest_Extensions_get(swigCPtr);
    return (cPtr == 0) ? null : new Samlp2Extensions(cPtr, false);
  }

  public void setID(String value) {
    lassoJNI.Samlp2LogoutRequest_ID_set(swigCPtr, value);
  }

  public String getID() {
    return lassoJNI.Samlp2LogoutRequest_ID_get(swigCPtr);
  }

  public void setVersion(String value) {
    lassoJNI.Samlp2LogoutRequest_Version_set(swigCPtr, value);
  }

  public String getVersion() {
    return lassoJNI.Samlp2LogoutRequest_Version_get(swigCPtr);
  }

  public void setIssueInstant(String value) {
    lassoJNI.Samlp2LogoutRequest_issueInstant_set(swigCPtr, value);
  }

  public String getIssueInstant() {
    return lassoJNI.Samlp2LogoutRequest_issueInstant_get(swigCPtr);
  }

  public void setDestination(String value) {
    lassoJNI.Samlp2LogoutRequest_Destination_set(swigCPtr, value);
  }

  public String getDestination() {
    return lassoJNI.Samlp2LogoutRequest_Destination_get(swigCPtr);
  }

  public void setConsent(String value) {
    lassoJNI.Samlp2LogoutRequest_Consent_set(swigCPtr, value);
  }

  public String getConsent() {
    return lassoJNI.Samlp2LogoutRequest_Consent_get(swigCPtr);
  }

  public Samlp2LogoutRequest() {
    this(lassoJNI.new_Samlp2LogoutRequest(), true);
  }

  public String dump() {
    return lassoJNI.Samlp2LogoutRequest_dump(swigCPtr);
  }

}
