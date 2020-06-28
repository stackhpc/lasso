/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class SamlSubjectConfirmation extends Node {
  protected SamlSubjectConfirmation(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(SamlSubjectConfirmation obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setSubjectConfirmationData(String SubjectConfirmationData) {
    lassoJNI.set_SamlSubjectConfirmation_subjectConfirmationData(swigCPtr, SubjectConfirmationData);
  }

  public String getSubjectConfirmationData() {
    return lassoJNI.get_SamlSubjectConfirmation_subjectConfirmationData(swigCPtr);
  }

  public void setConfirmationMethod(StringList confirmationMethod) {
    lassoJNI.set_SamlSubjectConfirmation_confirmationMethod(swigCPtr, StringList.getCPtr(confirmationMethod));
  }

  public StringList getConfirmationMethod() {
    long cPtr = lassoJNI.get_SamlSubjectConfirmation_confirmationMethod(swigCPtr);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public SamlSubjectConfirmation() {
    this(lassoJNI.new_SamlSubjectConfirmation(), true);
  }

  public String dump() {
    return lassoJNI.SamlSubjectConfirmation_dump(swigCPtr);
  }

}
