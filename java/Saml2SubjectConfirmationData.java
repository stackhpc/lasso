/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Saml2SubjectConfirmationData extends Node {
  protected Saml2SubjectConfirmationData(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Saml2SubjectConfirmationData obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setNotBefore(String value) {
    lassoJNI.Saml2SubjectConfirmationData_notBefore_set(swigCPtr, value);
  }

  public String getNotBefore() {
    return lassoJNI.Saml2SubjectConfirmationData_notBefore_get(swigCPtr);
  }

  public void setNotOnOrAfter(String value) {
    lassoJNI.Saml2SubjectConfirmationData_notOnOrAfter_set(swigCPtr, value);
  }

  public String getNotOnOrAfter() {
    return lassoJNI.Saml2SubjectConfirmationData_notOnOrAfter_get(swigCPtr);
  }

  public void setRecipient(String value) {
    lassoJNI.Saml2SubjectConfirmationData_recipient_set(swigCPtr, value);
  }

  public String getRecipient() {
    return lassoJNI.Saml2SubjectConfirmationData_recipient_get(swigCPtr);
  }

  public void setInResponseTo(String value) {
    lassoJNI.Saml2SubjectConfirmationData_inResponseTo_set(swigCPtr, value);
  }

  public String getInResponseTo() {
    return lassoJNI.Saml2SubjectConfirmationData_inResponseTo_get(swigCPtr);
  }

  public void setAddress(String value) {
    lassoJNI.Saml2SubjectConfirmationData_Address_set(swigCPtr, value);
  }

  public String getAddress() {
    return lassoJNI.Saml2SubjectConfirmationData_Address_get(swigCPtr);
  }

  public Saml2SubjectConfirmationData() {
    this(lassoJNI.new_Saml2SubjectConfirmationData(), true);
  }

  public String dump() {
    return lassoJNI.Saml2SubjectConfirmationData_dump(swigCPtr);
  }

}