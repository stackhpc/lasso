/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Saml2NameID extends Node {
  protected Saml2NameID(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Saml2NameID obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setContent(String value) {
    lassoJNI.Saml2NameID_content_set(swigCPtr, this, value);
  }

  public String getContent() {
    return lassoJNI.Saml2NameID_content_get(swigCPtr, this);
  }

  public void setFormat(String value) {
    lassoJNI.Saml2NameID_format_set(swigCPtr, this, value);
  }

  public String getFormat() {
    return lassoJNI.Saml2NameID_format_get(swigCPtr, this);
  }

  public void setSPProvidedID(String value) {
    lassoJNI.Saml2NameID_SPProvidedID_set(swigCPtr, this, value);
  }

  public String getSPProvidedID() {
    return lassoJNI.Saml2NameID_SPProvidedID_get(swigCPtr, this);
  }

  public void setNameQualifier(String value) {
    lassoJNI.Saml2NameID_nameQualifier_set(swigCPtr, this, value);
  }

  public String getNameQualifier() {
    return lassoJNI.Saml2NameID_nameQualifier_get(swigCPtr, this);
  }

  public void setSpNameQualifier(String value) {
    lassoJNI.Saml2NameID_spNameQualifier_set(swigCPtr, this, value);
  }

  public String getSpNameQualifier() {
    return lassoJNI.Saml2NameID_spNameQualifier_get(swigCPtr, this);
  }

  public Saml2NameID() {
    this(lassoJNI.new_Saml2NameID(), true);
  }

  public String dump() {
    return lassoJNI.Saml2NameID_dump(swigCPtr, this);
  }

}
