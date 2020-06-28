/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Samlp2Response extends Samlp2StatusResponse {
  protected Samlp2Response(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Samlp2Response obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setIssuer(Saml2NameID value) {
    lassoJNI.Samlp2Response_issuer_set(swigCPtr, this, Saml2NameID.getCPtr(value), value);
  }

  public Saml2NameID getIssuer() {
    long cPtr = lassoJNI.Samlp2Response_issuer_get(swigCPtr, this);
    return (cPtr == 0) ? null : new Saml2NameID(cPtr, false);
  }

  public void setExtensions(Samlp2Extensions value) {
    lassoJNI.Samlp2Response_extensions_set(swigCPtr, this, Samlp2Extensions.getCPtr(value), value);
  }

  public Samlp2Extensions getExtensions() {
    long cPtr = lassoJNI.Samlp2Response_extensions_get(swigCPtr, this);
    return (cPtr == 0) ? null : new Samlp2Extensions(cPtr, false);
  }

  public void setStatus(Samlp2Status value) {
    lassoJNI.Samlp2Response_status_set(swigCPtr, this, Samlp2Status.getCPtr(value), value);
  }

  public Samlp2Status getStatus() {
    long cPtr = lassoJNI.Samlp2Response_status_get(swigCPtr, this);
    return (cPtr == 0) ? null : new Samlp2Status(cPtr, false);
  }

  public void setID(String value) {
    lassoJNI.Samlp2Response_iD_set(swigCPtr, this, value);
  }

  public String getID() {
    return lassoJNI.Samlp2Response_iD_get(swigCPtr, this);
  }

  public void setInResponseTo(String value) {
    lassoJNI.Samlp2Response_inResponseTo_set(swigCPtr, this, value);
  }

  public String getInResponseTo() {
    return lassoJNI.Samlp2Response_inResponseTo_get(swigCPtr, this);
  }

  public void setVersion(String value) {
    lassoJNI.Samlp2Response_version_set(swigCPtr, this, value);
  }

  public String getVersion() {
    return lassoJNI.Samlp2Response_version_get(swigCPtr, this);
  }

  public void setIssueInstant(String value) {
    lassoJNI.Samlp2Response_issueInstant_set(swigCPtr, this, value);
  }

  public String getIssueInstant() {
    return lassoJNI.Samlp2Response_issueInstant_get(swigCPtr, this);
  }

  public void setDestination(String value) {
    lassoJNI.Samlp2Response_destination_set(swigCPtr, this, value);
  }

  public String getDestination() {
    return lassoJNI.Samlp2Response_destination_get(swigCPtr, this);
  }

  public void setConsent(String value) {
    lassoJNI.Samlp2Response_consent_set(swigCPtr, this, value);
  }

  public String getConsent() {
    return lassoJNI.Samlp2Response_consent_get(swigCPtr, this);
  }

  public void setAssertion(NodeList value) {
    lassoJNI.Samlp2Response_assertion_set(swigCPtr, this, NodeList.getCPtr(value), value);
  }

  public NodeList getAssertion() {
    long cPtr = lassoJNI.Samlp2Response_assertion_get(swigCPtr, this);
    return (cPtr == 0) ? null : new NodeList(cPtr, false);
  }

  public Samlp2Response() {
    this(lassoJNI.new_Samlp2Response(), true);
  }

  public String dump() {
    return lassoJNI.Samlp2Response_dump(swigCPtr, this);
  }

}
