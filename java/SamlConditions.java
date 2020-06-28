/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class SamlConditions extends Node {
  protected SamlConditions(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(SamlConditions obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setNotBefore(String value) {
    lassoJNI.SamlConditions_notBefore_set(swigCPtr, this, value);
  }

  public String getNotBefore() {
    return lassoJNI.SamlConditions_notBefore_get(swigCPtr, this);
  }

  public void setNotOnOrAfter(String value) {
    lassoJNI.SamlConditions_notOnOrAfter_set(swigCPtr, this, value);
  }

  public String getNotOnOrAfter() {
    return lassoJNI.SamlConditions_notOnOrAfter_get(swigCPtr, this);
  }

  public void setAudienceRestrictionCondition(NodeList value) {
    lassoJNI.SamlConditions_audienceRestrictionCondition_set(swigCPtr, this, NodeList.getCPtr(value), value);
  }

  public NodeList getAudienceRestrictionCondition() {
    long cPtr = lassoJNI.SamlConditions_audienceRestrictionCondition_get(swigCPtr, this);
    return (cPtr == 0) ? null : new NodeList(cPtr, false);
  }

  public void setCondition(NodeList value) {
    lassoJNI.SamlConditions_condition_set(swigCPtr, this, NodeList.getCPtr(value), value);
  }

  public NodeList getCondition() {
    long cPtr = lassoJNI.SamlConditions_condition_get(swigCPtr, this);
    return (cPtr == 0) ? null : new NodeList(cPtr, false);
  }

  public SamlConditions() {
    this(lassoJNI.new_SamlConditions(), true);
  }

  public String dump() {
    return lassoJNI.SamlConditions_dump(swigCPtr, this);
  }

}
