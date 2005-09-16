/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace lasso {

using System;

public class Federation : IDisposable {
  private IntPtr swigCPtr;
  protected bool swigCMemOwn;

  internal Federation(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  internal static IntPtr getCPtr(Federation obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  protected Federation() : this(IntPtr.Zero, false) {
  }

  ~Federation() {
    Dispose();
  }

  public virtual void Dispose() {
    if(swigCPtr != IntPtr.Zero && swigCMemOwn) {
      swigCMemOwn = false;
      lassoPINVOKE.delete_Federation(swigCPtr);
    }
    swigCPtr = IntPtr.Zero;
    GC.SuppressFinalize(this);
  }

  public string remoteProviderId {
    set {
      lassoPINVOKE.set_Federation_remoteProviderId(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_Federation_remoteProviderId(swigCPtr);
    } 
  }

  public SamlNameIdentifier localNameIdentifier {
    set {
      lassoPINVOKE.set_Federation_localNameIdentifier(swigCPtr, SamlNameIdentifier.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Federation_localNameIdentifier(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new SamlNameIdentifier(cPtr, false);
    } 
  }

  public SamlNameIdentifier remoteNameIdentifier {
    set {
      lassoPINVOKE.set_Federation_remoteNameIdentifier(swigCPtr, SamlNameIdentifier.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Federation_remoteNameIdentifier(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new SamlNameIdentifier(cPtr, false);
    } 
  }

  public Federation(string remoteProviderId) : this(lassoPINVOKE.new_Federation(remoteProviderId), true) {
  }

  public string dump() {
    return lassoPINVOKE.Federation_dump(swigCPtr);
  }

  public void buildLocalNameIdentifier(string nameQualifier, string format, string content) {
    lassoPINVOKE.Federation_buildLocalNameIdentifier(swigCPtr, nameQualifier, format, content);
  }

  public bool verifyNameIdentifier(SamlNameIdentifier nameIdentifier) {
    return lassoPINVOKE.Federation_verifyNameIdentifier(swigCPtr, SamlNameIdentifier.getCPtr(nameIdentifier));
  }

}

}
