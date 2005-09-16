/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class LibAuthnResponse extends SamlpResponse {
  protected LibAuthnResponse(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(LibAuthnResponse obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected LibAuthnResponse() {
    this(0, false);
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setConsent(String consent) {
    lassoJNI.set_LibAuthnResponse_consent(swigCPtr, consent);
  }

  public String getConsent() {
    return lassoJNI.get_LibAuthnResponse_consent(swigCPtr);
  }

  public void setProviderId(String ProviderID) {
    lassoJNI.set_LibAuthnResponse_providerId(swigCPtr, ProviderID);
  }

  public String getProviderId() {
    return lassoJNI.get_LibAuthnResponse_providerId(swigCPtr);
  }

  public void setRelayState(String RelayState) {
    lassoJNI.set_LibAuthnResponse_relayState(swigCPtr, RelayState);
  }

  public String getRelayState() {
    return lassoJNI.get_LibAuthnResponse_relayState(swigCPtr);
  }

  public void setExtension(StringList Extension) {
    lassoJNI.set_LibAuthnResponse_extension(swigCPtr, StringList.getCPtr(Extension));
  }

  public StringList getExtension() {
    long cPtr = lassoJNI.get_LibAuthnResponse_extension(swigCPtr);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public void setStatus(SamlpStatus Status) {
    lassoJNI.set_LibAuthnResponse_status(swigCPtr, SamlpStatus.getCPtr(Status));
  }

  public SamlpStatus getStatus() {
    long cPtr = lassoJNI.get_LibAuthnResponse_status(swigCPtr);
    return (cPtr == 0) ? null : new SamlpStatus(cPtr, false);
  }

  public LibAuthnResponse(String providerID, LibAuthnRequest request) {
    this(lassoJNI.new_LibAuthnResponse(providerID, LibAuthnRequest.getCPtr(request)), true);
  }

  public String dump() {
    return lassoJNI.LibAuthnResponse_dump(swigCPtr);
  }

}
