/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Samlp2AssertionIDRequest extends Samlp2RequestAbstract {
  protected Samlp2AssertionIDRequest(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Samlp2AssertionIDRequest obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setAssertionIDRef(String value) {
    lassoJNI.Samlp2AssertionIDRequest_AssertionIDRef_set(swigCPtr, value);
  }

  public String getAssertionIDRef() {
    return lassoJNI.Samlp2AssertionIDRequest_AssertionIDRef_get(swigCPtr);
  }

  public void setIssuer(Saml2NameID value) {
    lassoJNI.Samlp2AssertionIDRequest_issuer_set(swigCPtr, Saml2NameID.getCPtr(value));
  }

  public Saml2NameID getIssuer() {
    long cPtr = lassoJNI.Samlp2AssertionIDRequest_issuer_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2NameID(cPtr, false);
  }

  public void setExtensions(Samlp2Extensions value) {
    lassoJNI.Samlp2AssertionIDRequest_Extensions_set(swigCPtr, Samlp2Extensions.getCPtr(value));
  }

  public Samlp2Extensions getExtensions() {
    long cPtr = lassoJNI.Samlp2AssertionIDRequest_Extensions_get(swigCPtr);
    return (cPtr == 0) ? null : new Samlp2Extensions(cPtr, false);
  }

  public void setID(String value) {
    lassoJNI.Samlp2AssertionIDRequest_ID_set(swigCPtr, value);
  }

  public String getID() {
    return lassoJNI.Samlp2AssertionIDRequest_ID_get(swigCPtr);
  }

  public void setVersion(String value) {
    lassoJNI.Samlp2AssertionIDRequest_Version_set(swigCPtr, value);
  }

  public String getVersion() {
    return lassoJNI.Samlp2AssertionIDRequest_Version_get(swigCPtr);
  }

  public void setIssueInstant(String value) {
    lassoJNI.Samlp2AssertionIDRequest_issueInstant_set(swigCPtr, value);
  }

  public String getIssueInstant() {
    return lassoJNI.Samlp2AssertionIDRequest_issueInstant_get(swigCPtr);
  }

  public void setDestination(String value) {
    lassoJNI.Samlp2AssertionIDRequest_Destination_set(swigCPtr, value);
  }

  public String getDestination() {
    return lassoJNI.Samlp2AssertionIDRequest_Destination_get(swigCPtr);
  }

  public void setConsent(String value) {
    lassoJNI.Samlp2AssertionIDRequest_Consent_set(swigCPtr, value);
  }

  public String getConsent() {
    return lassoJNI.Samlp2AssertionIDRequest_Consent_get(swigCPtr);
  }

  public Samlp2AssertionIDRequest() {
    this(lassoJNI.new_Samlp2AssertionIDRequest(), true);
  }

  public String dump() {
    return lassoJNI.Samlp2AssertionIDRequest_dump(swigCPtr);
  }

}