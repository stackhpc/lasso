/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace lasso {

using System;

public class SamlpResponse : SamlpResponseAbstract, IDisposable {
  internal SamlpResponse(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static IntPtr getCPtr(SamlpResponse obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  ~SamlpResponse() {
    Dispose();
  }

  public virtual void Dispose() {
  base.Dispose();
}

  public string certificateFile {
    set {
      lassoPINVOKE.set_SamlpResponse_certificateFile(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlpResponse_certificateFile(swigCPtr);
    } 
  }

  public string inResponseTo {
    set {
      lassoPINVOKE.set_SamlpResponse_inResponseTo(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlpResponse_inResponseTo(swigCPtr);
    } 
  }

  public string issueInstant {
    set {
      lassoPINVOKE.set_SamlpResponse_issueInstant(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlpResponse_issueInstant(swigCPtr);
    } 
  }

  public int majorVersion {
    set {
      lassoPINVOKE.set_SamlpResponse_majorVersion(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlpResponse_majorVersion(swigCPtr);
    } 
  }

  public int minorVersion {
    set {
      lassoPINVOKE.set_SamlpResponse_minorVersion(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlpResponse_minorVersion(swigCPtr);
    } 
  }

  public string privateKeyFile {
    set {
      lassoPINVOKE.set_SamlpResponse_privateKeyFile(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlpResponse_privateKeyFile(swigCPtr);
    } 
  }

  public string recipient {
    set {
      lassoPINVOKE.set_SamlpResponse_recipient(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlpResponse_recipient(swigCPtr);
    } 
  }

  public string responseId {
    set {
      lassoPINVOKE.set_SamlpResponse_responseId(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlpResponse_responseId(swigCPtr);
    } 
  }

  public SignatureMethod signMethod {
    set {
      lassoPINVOKE.set_SamlpResponse_signMethod(swigCPtr, (int)value);
    } 
    get {
      return (SignatureMethod)lassoPINVOKE.get_SamlpResponse_signMethod(swigCPtr);
    } 
  }

  public SWIGTYPE_p_LassoSignatureType signType {
    set {
      lassoPINVOKE.set_SamlpResponse_signType(swigCPtr, SWIGTYPE_p_LassoSignatureType.getCPtr(value));
    } 
    get {
      return new SWIGTYPE_p_LassoSignatureType(lassoPINVOKE.get_SamlpResponse_signType(swigCPtr), true);
    } 
  }

  public NodeList assertion {
    set {
      lassoPINVOKE.set_SamlpResponse_assertion(swigCPtr, NodeList.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_SamlpResponse_assertion(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new NodeList(cPtr, false);
    } 
  }

  public SamlpStatus status {
    set {
      lassoPINVOKE.set_SamlpResponse_status(swigCPtr, SamlpStatus.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_SamlpResponse_status(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new SamlpStatus(cPtr, false);
    } 
  }

  public SamlpResponse() : this(lassoPINVOKE.new_SamlpResponse(), true) {
  }

  public string dump() {
    return lassoPINVOKE.SamlpResponse_dump(swigCPtr);
  }

}

}
