/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace lasso {

using System;

public class SamlAttribute : SamlAttributeDesignator, IDisposable {
  internal SamlAttribute(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static IntPtr getCPtr(SamlAttribute obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  ~SamlAttribute() {
    Dispose();
  }

  public virtual void Dispose() {
  base.Dispose();
}

  public string attributeName {
    set {
      lassoPINVOKE.set_SamlAttribute_attributeName(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlAttribute_attributeName(swigCPtr);
    } 
  }

  public string attributeNamespace {
    set {
      lassoPINVOKE.set_SamlAttribute_attributeNamespace(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_SamlAttribute_attributeNamespace(swigCPtr);
    } 
  }

  public NodeList attributeValue {
    set {
      lassoPINVOKE.set_SamlAttribute_attributeValue(swigCPtr, NodeList.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_SamlAttribute_attributeValue(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new NodeList(cPtr, false);
    } 
  }

  public SamlAttribute() : this(lassoPINVOKE.new_SamlAttribute(), true) {
  }

  public string dump() {
    return lassoPINVOKE.SamlAttribute_dump(swigCPtr);
  }

}

}
