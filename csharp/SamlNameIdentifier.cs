/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace lasso {

using System;

public class SamlNameIdentifier : Node, IDisposable {
  internal SamlNameIdentifier(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static IntPtr getCPtr(SamlNameIdentifier obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  ~SamlNameIdentifier() {
    Dispose();
  }

  public virtual void Dispose() {
  base.Dispose();
}

  public string content {
    set {
      lassoPINVOKE.set_SamlNameIdentifier_content(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlNameIdentifier_content(swigCPtr);
    } 
  }

  public string format {
    set {
      lassoPINVOKE.set_SamlNameIdentifier_format(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlNameIdentifier_format(swigCPtr);
    } 
  }

  public string nameQualifier {
    set {
      lassoPINVOKE.set_SamlNameIdentifier_nameQualifier(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlNameIdentifier_nameQualifier(swigCPtr);
    } 
  }

  public SamlNameIdentifier() : this(lassoPINVOKE.new_SamlNameIdentifier(), true) {
  }

  public string dump() {
    return lassoPINVOKE.SamlNameIdentifier_dump(swigCPtr);
  }

}

}
