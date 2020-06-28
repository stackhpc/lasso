/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class SamlpRequest extends SamlpRequestAbstract {
  protected SamlpRequest(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(SamlpRequest obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setAssertionArtifact(String value) {
    lassoJNI.SamlpRequest_assertionArtifact_set(swigCPtr, this, value);
  }

  public String getAssertionArtifact() {
    return lassoJNI.SamlpRequest_assertionArtifact_get(swigCPtr, this);
  }

  public void setCertificateFile(String value) {
    lassoJNI.SamlpRequest_certificateFile_set(swigCPtr, this, value);
  }

  public String getCertificateFile() {
    return lassoJNI.SamlpRequest_certificateFile_get(swigCPtr, this);
  }

  public void setIssueInstant(String value) {
    lassoJNI.SamlpRequest_issueInstant_set(swigCPtr, this, value);
  }

  public String getIssueInstant() {
    return lassoJNI.SamlpRequest_issueInstant_get(swigCPtr, this);
  }

  public void setMajorVersion(int value) {
    lassoJNI.SamlpRequest_majorVersion_set(swigCPtr, this, value);
  }

  public int getMajorVersion() {
    return lassoJNI.SamlpRequest_majorVersion_get(swigCPtr, this);
  }

  public void setMinorVersion(int value) {
    lassoJNI.SamlpRequest_minorVersion_set(swigCPtr, this, value);
  }

  public int getMinorVersion() {
    return lassoJNI.SamlpRequest_minorVersion_get(swigCPtr, this);
  }

  public void setPrivateKeyFile(String value) {
    lassoJNI.SamlpRequest_privateKeyFile_set(swigCPtr, this, value);
  }

  public String getPrivateKeyFile() {
    return lassoJNI.SamlpRequest_privateKeyFile_get(swigCPtr, this);
  }

  public void setRequestId(String value) {
    lassoJNI.SamlpRequest_requestId_set(swigCPtr, this, value);
  }

  public String getRequestId() {
    return lassoJNI.SamlpRequest_requestId_get(swigCPtr, this);
  }

  public void setRespondWith(StringList value) {
    lassoJNI.SamlpRequest_respondWith_set(swigCPtr, this, StringList.getCPtr(value), value);
  }

  public StringList getRespondWith() {
    long cPtr = lassoJNI.SamlpRequest_respondWith_get(swigCPtr, this);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public void setSignMethod(int value) {
    lassoJNI.SamlpRequest_signMethod_set(swigCPtr, this, value);
  }

  public int getSignMethod() {
    return lassoJNI.SamlpRequest_signMethod_get(swigCPtr, this);
  }

  public void setSignType(int value) {
    lassoJNI.SamlpRequest_signType_set(swigCPtr, this, value);
  }

  public int getSignType() {
    return lassoJNI.SamlpRequest_signType_get(swigCPtr, this);
  }

  public SamlpRequest() {
    this(lassoJNI.new_SamlpRequest(), true);
  }

  public String dump() {
    return lassoJNI.SamlpRequest_dump(swigCPtr, this);
  }

}
