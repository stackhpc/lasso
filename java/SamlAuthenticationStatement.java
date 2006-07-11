/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class SamlAuthenticationStatement extends SamlSubjectStatementAbstract {
  protected SamlAuthenticationStatement(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(SamlAuthenticationStatement obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setAuthenticationInstant(String value) {
    lassoJNI.SamlAuthenticationStatement_authenticationInstant_set(swigCPtr, value);
  }

  public String getAuthenticationInstant() {
    return lassoJNI.SamlAuthenticationStatement_authenticationInstant_get(swigCPtr);
  }

  public void setAuthenticationMethod(String value) {
    lassoJNI.SamlAuthenticationStatement_authenticationMethod_set(swigCPtr, value);
  }

  public String getAuthenticationMethod() {
    return lassoJNI.SamlAuthenticationStatement_authenticationMethod_get(swigCPtr);
  }

  public void setAuthorityBinding(NodeList value) {
    lassoJNI.SamlAuthenticationStatement_authorityBinding_set(swigCPtr, NodeList.getCPtr(value));
  }

  public NodeList getAuthorityBinding() {
    long cPtr = lassoJNI.SamlAuthenticationStatement_authorityBinding_get(swigCPtr);
    return (cPtr == 0) ? null : new NodeList(cPtr, false);
  }

  public void setSubjectLocality(SamlSubjectLocality value) {
    lassoJNI.SamlAuthenticationStatement_subjectLocality_set(swigCPtr, SamlSubjectLocality.getCPtr(value));
  }

  public SamlSubjectLocality getSubjectLocality() {
    long cPtr = lassoJNI.SamlAuthenticationStatement_subjectLocality_get(swigCPtr);
    return (cPtr == 0) ? null : new SamlSubjectLocality(cPtr, false);
  }

  public SamlAuthenticationStatement() {
    this(lassoJNI.new_SamlAuthenticationStatement(), true);
  }

  public String dump() {
    return lassoJNI.SamlAuthenticationStatement_dump(swigCPtr);
  }

}
