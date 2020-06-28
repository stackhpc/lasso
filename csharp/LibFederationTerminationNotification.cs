/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace lasso {

using System;

public class LibFederationTerminationNotification : SamlpRequestAbstract, IDisposable {
  internal LibFederationTerminationNotification(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static IntPtr getCPtr(LibFederationTerminationNotification obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  ~LibFederationTerminationNotification() {
    Dispose();
  }

  public virtual void Dispose() {
  base.Dispose();
}

  public string consent {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_consent(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibFederationTerminationNotification_consent(swigCPtr);
    } 
  }

  public string providerId {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_providerId(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibFederationTerminationNotification_providerId(swigCPtr);
    } 
  }

  public string relayState {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_relayState(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibFederationTerminationNotification_relayState(swigCPtr);
    } 
  }

  public string certificateFile {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_certificateFile(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibFederationTerminationNotification_certificateFile(swigCPtr);
    } 
  }

  public string issueInstant {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_issueInstant(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibFederationTerminationNotification_issueInstant(swigCPtr);
    } 
  }

  public int majorVersion {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_majorVersion(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibFederationTerminationNotification_majorVersion(swigCPtr);
    } 
  }

  public int minorVersion {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_minorVersion(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibFederationTerminationNotification_minorVersion(swigCPtr);
    } 
  }

  public string privateKeyFile {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_privateKeyFile(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibFederationTerminationNotification_privateKeyFile(swigCPtr);
    } 
  }

  public string requestId {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_requestId(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LibFederationTerminationNotification_requestId(swigCPtr);
    } 
  }

  public StringList respondWith {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_respondWith(swigCPtr, StringList.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_LibFederationTerminationNotification_respondWith(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new StringList(cPtr, false);
    } 
  }

  public SignatureMethod signMethod {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_signMethod(swigCPtr, (int)value);
    } 
    get {
      return (SignatureMethod)lassoPINVOKE.get_LibFederationTerminationNotification_signMethod(swigCPtr);
    } 
  }

  public SWIGTYPE_p_LassoSignatureType signType {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_signType(swigCPtr, SWIGTYPE_p_LassoSignatureType.getCPtr(value));
    } 
    get {
      return new SWIGTYPE_p_LassoSignatureType(lassoPINVOKE.get_LibFederationTerminationNotification_signType(swigCPtr), true);
    } 
  }

  public StringList extension {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_extension(swigCPtr, StringList.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_LibFederationTerminationNotification_extension(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new StringList(cPtr, false);
    } 
  }

  public SamlNameIdentifier nameIdentifier {
    set {
      lassoPINVOKE.set_LibFederationTerminationNotification_nameIdentifier(swigCPtr, SamlNameIdentifier.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_LibFederationTerminationNotification_nameIdentifier(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new SamlNameIdentifier(cPtr, false);
    } 
  }

  public LibFederationTerminationNotification() : this(lassoPINVOKE.new_LibFederationTerminationNotification(), true) {
  }

  public static LibFederationTerminationNotification newFull(string providerID, SamlNameIdentifier nameIdentifier, SWIGTYPE_p_LassoSignatureType sign_type, SignatureMethod sign_method) {
    IntPtr cPtr = lassoPINVOKE.LibFederationTerminationNotification_newFull(providerID, SamlNameIdentifier.getCPtr(nameIdentifier), SWIGTYPE_p_LassoSignatureType.getCPtr(sign_type), (int)sign_method);
    return (cPtr == IntPtr.Zero) ? null : new LibFederationTerminationNotification(cPtr, true);
  }

  public string dump() {
    return lassoPINVOKE.LibFederationTerminationNotification_dump(swigCPtr);
  }

}

}
