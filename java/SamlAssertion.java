/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class SamlAssertion extends Node {
  protected SamlAssertion(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(SamlAssertion obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setAssertionId(String value) {
    lassoJNI.SamlAssertion_assertionId_set(swigCPtr, this, value);
  }

  public String getAssertionId() {
    return lassoJNI.SamlAssertion_assertionId_get(swigCPtr, this);
  }

  public void setCertificateFile(String value) {
    lassoJNI.SamlAssertion_certificateFile_set(swigCPtr, this, value);
  }

  public String getCertificateFile() {
    return lassoJNI.SamlAssertion_certificateFile_get(swigCPtr, this);
  }

  public void setIssueInstant(String value) {
    lassoJNI.SamlAssertion_issueInstant_set(swigCPtr, this, value);
  }

  public String getIssueInstant() {
    return lassoJNI.SamlAssertion_issueInstant_get(swigCPtr, this);
  }

  public void setIssuer(String value) {
    lassoJNI.SamlAssertion_issuer_set(swigCPtr, this, value);
  }

  public String getIssuer() {
    return lassoJNI.SamlAssertion_issuer_get(swigCPtr, this);
  }

  public void setMajorVersion(int value) {
    lassoJNI.SamlAssertion_majorVersion_set(swigCPtr, this, value);
  }

  public int getMajorVersion() {
    return lassoJNI.SamlAssertion_majorVersion_get(swigCPtr, this);
  }

  public void setMinorVersion(int value) {
    lassoJNI.SamlAssertion_minorVersion_set(swigCPtr, this, value);
  }

  public int getMinorVersion() {
    return lassoJNI.SamlAssertion_minorVersion_get(swigCPtr, this);
  }

  public void setPrivateKeyFile(String value) {
    lassoJNI.SamlAssertion_privateKeyFile_set(swigCPtr, this, value);
  }

  public String getPrivateKeyFile() {
    return lassoJNI.SamlAssertion_privateKeyFile_get(swigCPtr, this);
  }

  public void setSignMethod(int value) {
    lassoJNI.SamlAssertion_signMethod_set(swigCPtr, this, value);
  }

  public int getSignMethod() {
    return lassoJNI.SamlAssertion_signMethod_get(swigCPtr, this);
  }

  public void setSignType(int value) {
    lassoJNI.SamlAssertion_signType_set(swigCPtr, this, value);
  }

  public int getSignType() {
    return lassoJNI.SamlAssertion_signType_get(swigCPtr, this);
  }

  public void setAdvice(SamlAdvice value) {
    lassoJNI.SamlAssertion_advice_set(swigCPtr, this, SamlAdvice.getCPtr(value), value);
  }

  public SamlAdvice getAdvice() {
    long cPtr = lassoJNI.SamlAssertion_advice_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SamlAdvice(cPtr, false);
  }

  public void setAttributeStatement(SamlAttributeStatement value) {
    lassoJNI.SamlAssertion_attributeStatement_set(swigCPtr, this, SamlAttributeStatement.getCPtr(value), value);
  }

  public SamlAttributeStatement getAttributeStatement() {
    long cPtr = lassoJNI.SamlAssertion_attributeStatement_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SamlAttributeStatement(cPtr, false);
  }

  public void setAuthenticationStatement(SamlAuthenticationStatement value) {
    lassoJNI.SamlAssertion_authenticationStatement_set(swigCPtr, this, SamlAuthenticationStatement.getCPtr(value), value);
  }

  public SamlAuthenticationStatement getAuthenticationStatement() {
    long cPtr = lassoJNI.SamlAssertion_authenticationStatement_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SamlAuthenticationStatement(cPtr, false);
  }

  public void setConditions(SamlConditions value) {
    lassoJNI.SamlAssertion_conditions_set(swigCPtr, this, SamlConditions.getCPtr(value), value);
  }

  public SamlConditions getConditions() {
    long cPtr = lassoJNI.SamlAssertion_conditions_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SamlConditions(cPtr, false);
  }

  public void setSubjectStatement(SamlSubjectStatement value) {
    lassoJNI.SamlAssertion_subjectStatement_set(swigCPtr, this, SamlSubjectStatement.getCPtr(value), value);
  }

  public SamlSubjectStatement getSubjectStatement() {
    long cPtr = lassoJNI.SamlAssertion_subjectStatement_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SamlSubjectStatement(cPtr, false);
  }

  public SamlAssertion() {
    this(lassoJNI.new_SamlAssertion(), true);
  }

  public String dump() {
    return lassoJNI.SamlAssertion_dump(swigCPtr, this);
  }

}
