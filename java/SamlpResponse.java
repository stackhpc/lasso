/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
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

  public void setCertificateFile(String certificate_file) {
    lassoJNI.set_SamlpResponse_certificateFile(swigCPtr, certificate_file);
  }

  public String getCertificateFile() {
    return lassoJNI.get_SamlpResponse_certificateFile(swigCPtr);
  }

  public void setInResponseTo(String InResponseTo) {
    lassoJNI.set_SamlpResponse_inResponseTo(swigCPtr, InResponseTo);
  }

  public String getInResponseTo() {
    return lassoJNI.get_SamlpResponse_inResponseTo(swigCPtr);
  }

  public void setIssueInstant(String IssueInstant) {
    lassoJNI.set_SamlpResponse_issueInstant(swigCPtr, IssueInstant);
  }

  public String getIssueInstant() {
    return lassoJNI.get_SamlpResponse_issueInstant(swigCPtr);
  }

  public void setMajorVersion(int MajorVersion) {
    lassoJNI.set_SamlpResponse_majorVersion(swigCPtr, MajorVersion);
  }

  public int getMajorVersion() {
    return lassoJNI.get_SamlpResponse_majorVersion(swigCPtr);
  }

  public void setMinorVersion(int MinorVersion) {
    lassoJNI.set_SamlpResponse_minorVersion(swigCPtr, MinorVersion);
  }

  public int getMinorVersion() {
    return lassoJNI.get_SamlpResponse_minorVersion(swigCPtr);
  }

  public void setPrivateKeyFile(String private_key_file) {
    lassoJNI.set_SamlpResponse_privateKeyFile(swigCPtr, private_key_file);
  }

  public String getPrivateKeyFile() {
    return lassoJNI.get_SamlpResponse_privateKeyFile(swigCPtr);
  }

  public void setRecipient(String Recipient) {
    lassoJNI.set_SamlpResponse_recipient(swigCPtr, Recipient);
  }

  public String getRecipient() {
    return lassoJNI.get_SamlpResponse_recipient(swigCPtr);
  }

  public void setResponseId(String ResponseID) {
    lassoJNI.set_SamlpResponse_responseId(swigCPtr, ResponseID);
  }

  public String getResponseId() {
    return lassoJNI.get_SamlpResponse_responseId(swigCPtr);
  }

  public void setSignMethod(int sign_method) {
    lassoJNI.set_SamlpResponse_signMethod(swigCPtr, sign_method);
  }

  public int getSignMethod() {
    return lassoJNI.get_SamlpResponse_signMethod(swigCPtr);
  }

  public void setSignType(SWIGTYPE_p_LassoSignatureType sign_type) {
    lassoJNI.set_SamlpResponse_signType(swigCPtr, SWIGTYPE_p_LassoSignatureType.getCPtr(sign_type));
  }

  public SWIGTYPE_p_LassoSignatureType getSignType() {
    return new SWIGTYPE_p_LassoSignatureType(lassoJNI.get_SamlpResponse_signType(swigCPtr), true);
  }

  public void setAssertion(NodeList Assertion) {
    lassoJNI.set_SamlpResponse_assertion(swigCPtr, NodeList.getCPtr(Assertion));
  }

  public NodeList getAssertion() {
    long cPtr = lassoJNI.get_SamlpResponse_assertion(swigCPtr);
    return (cPtr == 0) ? null : new NodeList(cPtr, false);
  }

  public void setStatus(SamlpStatus Status) {
    lassoJNI.set_SamlpResponse_status(swigCPtr, SamlpStatus.getCPtr(Status));
  }

  public SamlpStatus getStatus() {
    long cPtr = lassoJNI.get_SamlpResponse_status(swigCPtr);
    return (cPtr == 0) ? null : new SamlpStatus(cPtr, false);
  }

  public SamlpResponse() {
    this(lassoJNI.new_SamlpResponse(), true);
  }

  public String dump() {
    return lassoJNI.SamlpResponse_dump(swigCPtr);
  }

}
