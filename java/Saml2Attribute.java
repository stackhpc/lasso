/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Saml2Attribute extends Node {
  protected Saml2Attribute(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Saml2Attribute obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setName(String value) {
    lassoJNI.Saml2Attribute_Name_set(swigCPtr, value);
  }

  public String getName() {
    return lassoJNI.Saml2Attribute_Name_get(swigCPtr);
  }

  public void setNameFormat(String value) {
    lassoJNI.Saml2Attribute_NameFormat_set(swigCPtr, value);
  }

  public String getNameFormat() {
    return lassoJNI.Saml2Attribute_NameFormat_get(swigCPtr);
  }

  public void setFriendlyName(String value) {
    lassoJNI.Saml2Attribute_FriendlyName_set(swigCPtr, value);
  }

  public String getFriendlyName() {
    return lassoJNI.Saml2Attribute_FriendlyName_get(swigCPtr);
  }

  public Saml2Attribute() {
    this(lassoJNI.new_Saml2Attribute(), true);
  }

  public String dump() {
    return lassoJNI.Saml2Attribute_dump(swigCPtr);
  }

}