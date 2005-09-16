/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace lasso {

using System;

public class SamlpStatusCode : Node, IDisposable {
  internal SamlpStatusCode(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static IntPtr getCPtr(SamlpStatusCode obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  ~SamlpStatusCode() {
    Dispose();
  }

  public virtual void Dispose() {
  base.Dispose();
}

  public string value {
    set {
      lassoPINVOKE.set_SamlpStatusCode_value(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlpStatusCode_value(swigCPtr);
    } 
  }

  public SamlpStatusCode statusCode {
    set {
      lassoPINVOKE.set_SamlpStatusCode_statusCode(swigCPtr, SamlpStatusCode.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_SamlpStatusCode_statusCode(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new SamlpStatusCode(cPtr, false);
    } 
  }

  public SamlpStatusCode() : this(lassoPINVOKE.new_SamlpStatusCode(), true) {
  }

  public string dump() {
    return lassoPINVOKE.SamlpStatusCode_dump(swigCPtr);
  }

}

}
