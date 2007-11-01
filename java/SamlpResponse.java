/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class SamlpResponse extends SamlpResponseAbstract {
  protected SamlpResponse(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(SamlpResponse obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setCertificateFile(String value) {
    lassoJNI.SamlpResponse_certificateFile_set(swigCPtr, this, value);
  }

  public String getCertificateFile() {
    return lassoJNI.SamlpResponse_certificateFile_get(swigCPtr, this);
  }

  public void setInResponseTo(String value) {
    lassoJNI.SamlpResponse_inResponseTo_set(swigCPtr, this, value);
  }

  public String getInResponseTo() {
    return lassoJNI.SamlpResponse_inResponseTo_get(swigCPtr, this);
  }

  public void setIssueInstant(String value) {
    lassoJNI.SamlpResponse_issueInstant_set(swigCPtr, this, value);
  }

  public String getIssueInstant() {
    return lassoJNI.SamlpResponse_issueInstant_get(swigCPtr, this);
  }

  public void setMajorVersion(int value) {
    lassoJNI.SamlpResponse_majorVersion_set(swigCPtr, this, value);
  }

  public int getMajorVersion() {
    return lassoJNI.SamlpResponse_majorVersion_get(swigCPtr, this);
  }

  public void setMinorVersion(int value) {
    lassoJNI.SamlpResponse_minorVersion_set(swigCPtr, this, value);
  }

  public int getMinorVersion() {
    return lassoJNI.SamlpResponse_minorVersion_get(swigCPtr, this);
  }

  public void setPrivateKeyFile(String value) {
    lassoJNI.SamlpResponse_privateKeyFile_set(swigCPtr, this, value);
  }

  public String getPrivateKeyFile() {
    return lassoJNI.SamlpResponse_privateKeyFile_get(swigCPtr, this);
  }

  public void setRecipient(String value) {
    lassoJNI.SamlpResponse_recipient_set(swigCPtr, this, value);
  }

  public String getRecipient() {
    return lassoJNI.SamlpResponse_recipient_get(swigCPtr, this);
  }

  public void setResponseId(String value) {
    lassoJNI.SamlpResponse_responseId_set(swigCPtr, this, value);
  }

  public String getResponseId() {
    return lassoJNI.SamlpResponse_responseId_get(swigCPtr, this);
  }

  public void setSignMethod(int value) {
    lassoJNI.SamlpResponse_signMethod_set(swigCPtr, this, value);
  }

  public int getSignMethod() {
    return lassoJNI.SamlpResponse_signMethod_get(swigCPtr, this);
  }

  public void setSignType(int value) {
    lassoJNI.SamlpResponse_signType_set(swigCPtr, this, value);
  }

  public int getSignType() {
    return lassoJNI.SamlpResponse_signType_get(swigCPtr, this);
  }

  public void setAssertion(NodeList value) {
    lassoJNI.SamlpResponse_assertion_set(swigCPtr, this, NodeList.getCPtr(value), value);
  }

  public NodeList getAssertion() {
    long cPtr = lassoJNI.SamlpResponse_assertion_get(swigCPtr, this);
    return (cPtr == 0) ? null : new NodeList(cPtr, false);
  }

  public void setStatus(SamlpStatus value) {
    lassoJNI.SamlpResponse_status_set(swigCPtr, this, SamlpStatus.getCPtr(value), value);
  }

  public SamlpStatus getStatus() {
    long cPtr = lassoJNI.SamlpResponse_status_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SamlpStatus(cPtr, false);
  }

  public SamlpResponse() {
    this(lassoJNI.new_SamlpResponse(), true);
  }

  public String dump() {
    return lassoJNI.SamlpResponse_dump(swigCPtr, this);
  }

}
