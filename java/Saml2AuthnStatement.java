/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Saml2AuthnStatement extends Saml2StatementAbstract {
  protected Saml2AuthnStatement(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Saml2AuthnStatement obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setAuthnInstant(String value) {
    lassoJNI.Saml2AuthnStatement_AuthnInstant_set(swigCPtr, value);
  }

  public String getAuthnInstant() {
    return lassoJNI.Saml2AuthnStatement_AuthnInstant_get(swigCPtr);
  }

  public void setSessionIndex(String value) {
    lassoJNI.Saml2AuthnStatement_sessionIndex_set(swigCPtr, value);
  }

  public String getSessionIndex() {
    return lassoJNI.Saml2AuthnStatement_sessionIndex_get(swigCPtr);
  }

  public void setSessionNotOnOrAfter(String value) {
    lassoJNI.Saml2AuthnStatement_SessionNotOnOrAfter_set(swigCPtr, value);
  }

  public String getSessionNotOnOrAfter() {
    return lassoJNI.Saml2AuthnStatement_SessionNotOnOrAfter_get(swigCPtr);
  }

  public void setSubjectLocality(Saml2SubjectLocality value) {
    lassoJNI.Saml2AuthnStatement_subjectLocality_set(swigCPtr, Saml2SubjectLocality.getCPtr(value));
  }

  public Saml2SubjectLocality getSubjectLocality() {
    long cPtr = lassoJNI.Saml2AuthnStatement_subjectLocality_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2SubjectLocality(cPtr, false);
  }

  public void setAuthnContext(Saml2AuthnContext value) {
    lassoJNI.Saml2AuthnStatement_authnContext_set(swigCPtr, Saml2AuthnContext.getCPtr(value));
  }

  public Saml2AuthnContext getAuthnContext() {
    long cPtr = lassoJNI.Saml2AuthnStatement_authnContext_get(swigCPtr);
    return (cPtr == 0) ? null : new Saml2AuthnContext(cPtr, false);
  }

  public Saml2AuthnStatement() {
    this(lassoJNI.new_Saml2AuthnStatement(), true);
  }

  public String dump() {
    return lassoJNI.Saml2AuthnStatement_dump(swigCPtr);
  }

}