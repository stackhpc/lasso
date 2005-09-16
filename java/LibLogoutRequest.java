/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
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

  public void setConsent(String consent) {
    lassoJNI.set_LibLogoutRequest_consent(swigCPtr, consent);
  }

  public String getConsent() {
    return lassoJNI.get_LibLogoutRequest_consent(swigCPtr);
  }

  public void setNotOnOrAfter(String NotOnOrAfter) {
    lassoJNI.set_LibLogoutRequest_notOnOrAfter(swigCPtr, NotOnOrAfter);
  }

  public String getNotOnOrAfter() {
    return lassoJNI.get_LibLogoutRequest_notOnOrAfter(swigCPtr);
  }

  public void setProviderId(String ProviderID) {
    lassoJNI.set_LibLogoutRequest_providerId(swigCPtr, ProviderID);
  }

  public String getProviderId() {
    return lassoJNI.get_LibLogoutRequest_providerId(swigCPtr);
  }

  public void setRelayState(String RelayState) {
    lassoJNI.set_LibLogoutRequest_relayState(swigCPtr, RelayState);
  }

  public String getRelayState() {
    return lassoJNI.get_LibLogoutRequest_relayState(swigCPtr);
  }

  public void setSessionIndex(String SessionIndex) {
    lassoJNI.set_LibLogoutRequest_sessionIndex(swigCPtr, SessionIndex);
  }

  public String getSessionIndex() {
    return lassoJNI.get_LibLogoutRequest_sessionIndex(swigCPtr);
  }

  public void setCertificateFile(String certificate_file) {
    lassoJNI.set_LibLogoutRequest_certificateFile(swigCPtr, certificate_file);
  }

  public String getCertificateFile() {
    return lassoJNI.get_LibLogoutRequest_certificateFile(swigCPtr);
  }

  public void setIssueInstant(String IssueInstant) {
    lassoJNI.set_LibLogoutRequest_issueInstant(swigCPtr, IssueInstant);
  }

  public String getIssueInstant() {
    return lassoJNI.get_LibLogoutRequest_issueInstant(swigCPtr);
  }

  public void setMajorVersion(int MajorVersion) {
    lassoJNI.set_LibLogoutRequest_majorVersion(swigCPtr, MajorVersion);
  }

  public int getMajorVersion() {
    return lassoJNI.get_LibLogoutRequest_majorVersion(swigCPtr);
  }

  public void setMinorVersion(int MinorVersion) {
    lassoJNI.set_LibLogoutRequest_minorVersion(swigCPtr, MinorVersion);
  }

  public int getMinorVersion() {
    return lassoJNI.get_LibLogoutRequest_minorVersion(swigCPtr);
  }

  public void setPrivateKeyFile(String private_key_file) {
    lassoJNI.set_LibLogoutRequest_privateKeyFile(swigCPtr, private_key_file);
  }

  public String getPrivateKeyFile() {
    return lassoJNI.get_LibLogoutRequest_privateKeyFile(swigCPtr);
  }

  public void setRequestId(String RequestID) {
    lassoJNI.set_LibLogoutRequest_requestId(swigCPtr, RequestID);
  }

  public String getRequestId() {
    return lassoJNI.get_LibLogoutRequest_requestId(swigCPtr);
  }

  public void setRespondWith(StringList RespondWith) {
    lassoJNI.set_LibLogoutRequest_respondWith(swigCPtr, StringList.getCPtr(RespondWith));
  }

  public StringList getRespondWith() {
    long cPtr = lassoJNI.get_LibLogoutRequest_respondWith(swigCPtr);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public void setSignMethod(int sign_method) {
    lassoJNI.set_LibLogoutRequest_signMethod(swigCPtr, sign_method);
  }

  public int getSignMethod() {
    return lassoJNI.get_LibLogoutRequest_signMethod(swigCPtr);
  }

  public void setSignType(SWIGTYPE_p_LassoSignatureType sign_type) {
    lassoJNI.set_LibLogoutRequest_signType(swigCPtr, SWIGTYPE_p_LassoSignatureType.getCPtr(sign_type));
  }

  public SWIGTYPE_p_LassoSignatureType getSignType() {
    return new SWIGTYPE_p_LassoSignatureType(lassoJNI.get_LibLogoutRequest_signType(swigCPtr), true);
  }

  public void setExtension(StringList Extension) {
    lassoJNI.set_LibLogoutRequest_extension(swigCPtr, StringList.getCPtr(Extension));
  }

  public StringList getExtension() {
    long cPtr = lassoJNI.get_LibLogoutRequest_extension(swigCPtr);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public void setNameIdentifier(SamlNameIdentifier NameIdentifier) {
    lassoJNI.set_LibLogoutRequest_nameIdentifier(swigCPtr, SamlNameIdentifier.getCPtr(NameIdentifier));
  }

  public SamlNameIdentifier getNameIdentifier() {
    long cPtr = lassoJNI.get_LibLogoutRequest_nameIdentifier(swigCPtr);
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
