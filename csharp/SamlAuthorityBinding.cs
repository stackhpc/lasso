/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace lasso {

using System;

public class SamlAuthorityBinding : Node, IDisposable {
  internal SamlAuthorityBinding(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static IntPtr getCPtr(SamlAuthorityBinding obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  ~SamlAuthorityBinding() {
    Dispose();
  }

  public virtual void Dispose() {
  base.Dispose();
}

  public string authorityKind {
    set {
      lassoPINVOKE.set_SamlAuthorityBinding_authorityKind(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlAuthorityBinding_authorityKind(swigCPtr);
    } 
  }

  public string location {
    set {
      lassoPINVOKE.set_SamlAuthorityBinding_location(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlAuthorityBinding_location(swigCPtr);
    } 
  }

  public string binding {
    set {
      lassoPINVOKE.set_SamlAuthorityBinding_binding(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlAuthorityBinding_binding(swigCPtr);
    } 
  }

  public SamlAuthorityBinding() : this(lassoPINVOKE.new_SamlAuthorityBinding(), true) {
  }

  public string dump() {
    return lassoPINVOKE.SamlAuthorityBinding_dump(swigCPtr);
  }

}

}
