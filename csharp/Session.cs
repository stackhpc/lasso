/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version: 1.3.21
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

//package lasso;

using System;
public class Session : IDisposable {
  private IntPtr swigCPtr;
  protected bool swigCMemOwn;

  internal Session(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  ~Session() {
    Dispose();
  }

  public virtual void Dispose() {
    if(swigCPtr != IntPtr.Zero && swigCMemOwn) {
      swigCMemOwn = false;
      lassoPINVOKE.delete_Session(swigCPtr);
    }
    swigCPtr = IntPtr.Zero;
    GC.SuppressFinalize(this);
  }

  internal static IntPtr getCPtr(Session obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  public bool isDirty {
    get {
      return lassoPINVOKE.get_Session_isDirty(swigCPtr);
    } 
  }

  public Session() : this(lassoPINVOKE.new_Session(), true) {
  }

  public static Session newFromDump(string dump) {
    IntPtr cPtr = lassoPINVOKE.Session_newFromDump(dump);
    return (cPtr == IntPtr.Zero) ? null : new Session(cPtr, true);
  }

  public string dump() {
    return lassoPINVOKE.Session_dump(swigCPtr);
  }

  public string getAuthenticationMethod(string remoteProviderId) {
    return lassoPINVOKE.Session_getAuthenticationMethod(swigCPtr, remoteProviderId);
  }

}
