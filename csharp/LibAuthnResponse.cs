/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace lasso {

using System;

public class LibAuthnResponse : SamlpResponse, IDisposable {
  internal LibAuthnResponse(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static IntPtr getCPtr(LibAuthnResponse obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  protected LibAuthnResponse() : this(IntPtr.Zero, false) {
  }

  ~LibAuthnResponse() {
    Dispose();
  }

  public virtual void Dispose() {
  base.Dispose();
}

  public string consent {
    set {
      lassoPINVOKE.set_LibAuthnResponse_consent(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibAuthnResponse_consent(swigCPtr);
    } 
  }

  public string providerId {
    set {
      lassoPINVOKE.set_LibAuthnResponse_providerId(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibAuthnResponse_providerId(swigCPtr);
    } 
  }

  public string relayState {
    set {
      lassoPINVOKE.set_LibAuthnResponse_relayState(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibAuthnResponse_relayState(swigCPtr);
    } 
  }

  public StringList extension {
    set {
      lassoPINVOKE.set_LibAuthnResponse_extension(swigCPtr, StringList.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_LibAuthnResponse_extension(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new StringList(cPtr, false);
    } 
  }

  public SamlpStatus status {
    set {
      lassoPINVOKE.set_LibAuthnResponse_status(swigCPtr, SamlpStatus.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_LibAuthnResponse_status(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new SamlpStatus(cPtr, false);
    } 
  }

  public LibAuthnResponse(string providerID, LibAuthnRequest request) : this(lassoPINVOKE.new_LibAuthnResponse(providerID, LibAuthnRequest.getCPtr(request)), true) {
  }

  public string dump() {
    return lassoPINVOKE.LibAuthnResponse_dump(swigCPtr);
  }

}

}
