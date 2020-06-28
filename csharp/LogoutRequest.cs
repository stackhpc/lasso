/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version: 1.3.21
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

//package lasso;

using System;
public class LogoutRequest : IDisposable {
  private IntPtr swigCPtr;
  protected bool swigCMemOwn;

  internal LogoutRequest(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected LogoutRequest() : this(IntPtr.Zero, false) {
  }

  public virtual void Dispose() {
    if(swigCPtr != IntPtr.Zero && swigCMemOwn) {
      swigCMemOwn = false;
      throw new MethodAccessException("C++ destructor does not have public access");
    }
    swigCPtr = IntPtr.Zero;
    GC.SuppressFinalize(this);
  }

  internal static IntPtr getCPtr(LogoutRequest obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  public string relayState {
    set {
      lassoPINVOKE.set_LogoutRequest_relayState(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_LogoutRequest_relayState(swigCPtr);
    } 
  }

}
