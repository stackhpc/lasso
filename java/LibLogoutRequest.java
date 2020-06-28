/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class LibLogoutRequest extends SamlpRequestAbstract {
  protected LibLogoutRequest(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(LibLogoutRequest obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setConsent(String value) {
    lassoJNI.LibLogoutRequest_consent_set(swigCPtr, value);
  }

  public String getConsent() {
    return lassoJNI.LibLogoutRequest_consent_get(swigCPtr);
  }

  public void setNotOnOrAfter(String value) {
    lassoJNI.LibLogoutRequest_notOnOrAfter_set(swigCPtr, value);
  }

  public String getNotOnOrAfter() {
    return lassoJNI.LibLogoutRequest_notOnOrAfter_get(swigCPtr);
  }

  public void setProviderId(String value) {
    lassoJNI.LibLogoutRequest_providerId_set(swigCPtr, value);
  }

  public String getProviderId() {
    return lassoJNI.LibLogoutRequest_providerId_get(swigCPtr);
  }

  public void setRelayState(String value) {
    lassoJNI.LibLogoutRequest_relayState_set(swigCPtr, value);
  }

  public String getRelayState() {
    return lassoJNI.LibLogoutRequest_relayState_get(swigCPtr);
  }

  public void setSessionIndex(String value) {
    lassoJNI.LibLogoutRequest_sessionIndex_set(swigCPtr, value);
  }

  public String getSessionIndex() {
    return lassoJNI.LibLogoutRequest_sessionIndex_get(swigCPtr);
  }

  public void setCertificateFile(String value) {
    lassoJNI.LibLogoutRequest_certificateFile_set(swigCPtr, value);
  }

  public String getCertificateFile() {
    return lassoJNI.LibLogoutRequest_certificateFile_get(swigCPtr);
  }

  public void setIssueInstant(String value) {
    lassoJNI.LibLogoutRequest_issueInstant_set(swigCPtr, value);
  }

  public String getIssueInstant() {
    return lassoJNI.LibLogoutRequest_issueInstant_get(swigCPtr);
  }

  public void setMajorVersion(int value) {
    lassoJNI.LibLogoutRequest_majorVersion_set(swigCPtr, value);
  }

  public int getMajorVersion() {
    return lassoJNI.LibLogoutRequest_majorVersion_get(swigCPtr);
  }

  public void setMinorVersion(int value) {
    lassoJNI.LibLogoutRequest_minorVersion_set(swigCPtr, value);
  }

  public int getMinorVersion() {
    return lassoJNI.LibLogoutRequest_minorVersion_get(swigCPtr);
  }

  public void setPrivateKeyFile(String value) {
    lassoJNI.LibLogoutRequest_privateKeyFile_set(swigCPtr, value);
  }

  public String getPrivateKeyFile() {
    return lassoJNI.LibLogoutRequest_privateKeyFile_get(swigCPtr);
  }

  public void setRequestId(String value) {
    lassoJNI.LibLogoutRequest_requestId_set(swigCPtr, value);
  }

  public String getRequestId() {
    return lassoJNI.LibLogoutRequest_requestId_get(swigCPtr);
  }

  public void setRespondWith(StringList value) {
    lassoJNI.LibLogoutRequest_respondWith_set(swigCPtr, StringList.getCPtr(value));
  }

  public StringList getRespondWith() {
    long cPtr = lassoJNI.LibLogoutRequest_respondWith_get(swigCPtr);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public void setSignMethod(int value) {
    lassoJNI.LibLogoutRequest_signMethod_set(swigCPtr, value);
  }

  public int getSignMethod() {
    return lassoJNI.LibLogoutRequest_signMethod_get(swigCPtr);
  }

  public void setSignType(SWIGTYPE_p_LassoSignatureType value) {
    lassoJNI.LibLogoutRequest_signType_set(swigCPtr, SWIGTYPE_p_LassoSignatureType.getCPtr(value));
  }

  public SWIGTYPE_p_LassoSignatureType getSignType() {
    return new SWIGTYPE_p_LassoSignatureType(lassoJNI.LibLogoutRequest_signType_get(swigCPtr), true);
  }

  public void setExtension(StringList value) {
    lassoJNI.LibLogoutRequest_extension_set(swigCPtr, StringList.getCPtr(value));
  }

  public StringList getExtension() {
    long cPtr = lassoJNI.LibLogoutRequest_extension_get(swigCPtr);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public void setNameIdentifier(SamlNameIdentifier value) {
    lassoJNI.LibLogoutRequest_nameIdentifier_set(swigCPtr, SamlNameIdentifier.getCPtr(value));
  }

  public SamlNameIdentifier getNameIdentifier() {
    long cPtr = lassoJNI.LibLogoutRequest_nameIdentifier_get(swigCPtr);
    return (cPtr == 0) ? null : new SamlNameIdentifier(cPtr, false);
  }

  public LibLogoutRequest() {
    this(lassoJNI.new_LibLogoutRequest(), true);
  }

  public static LibLogoutRequest newFull(String providerID, SamlNameIdentifier nameIdentifier, SWIGTYPE_p_LassoSignatureType sign_type, int sign_method) {
    long cPtr = lassoJNI.LibLogoutRequest_newFull(providerID, SamlNameIdentifier.getCPtr(nameIdentifier), SWIGTYPE_p_LassoSignatureType.getCPtr(sign_type), sign_method);
    return (cPtr == 0) ? null : new LibLogoutRequest(cPtr, true);
  }

  public String dump() {
    return lassoJNI.LibLogoutRequest_dump(swigCPtr);
  }

}