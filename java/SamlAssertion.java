/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
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
    lassoJNI.SamlAssertion_assertionId_set(swigCPtr, value);
  }

  public String getAssertionId() {
    return lassoJNI.SamlAssertion_assertionId_get(swigCPtr);
  }

  public void setCertificateFile(String value) {
    lassoJNI.SamlAssertion_certificateFile_set(swigCPtr, value);
  }

  public String getCertificateFile() {
    return lassoJNI.SamlAssertion_certificateFile_get(swigCPtr);
  }

  public void setIssueInstant(String value) {
    lassoJNI.SamlAssertion_issueInstant_set(swigCPtr, value);
  }

  public String getIssueInstant() {
    return lassoJNI.SamlAssertion_issueInstant_get(swigCPtr);
  }

  public void setIssuer(String value) {
    lassoJNI.SamlAssertion_issuer_set(swigCPtr, value);
  }

  public String getIssuer() {
    return lassoJNI.SamlAssertion_issuer_get(swigCPtr);
  }

  public void setMajorVersion(int value) {
    lassoJNI.SamlAssertion_majorVersion_set(swigCPtr, value);
  }

  public int getMajorVersion() {
    return lassoJNI.SamlAssertion_majorVersion_get(swigCPtr);
  }

  public void setMinorVersion(int value) {
    lassoJNI.SamlAssertion_minorVersion_set(swigCPtr, value);
  }

  public int getMinorVersion() {
    return lassoJNI.SamlAssertion_minorVersion_get(swigCPtr);
  }

  public void setPrivateKeyFile(String value) {
    lassoJNI.SamlAssertion_privateKeyFile_set(swigCPtr, value);
  }

  public String getPrivateKeyFile() {
    return lassoJNI.SamlAssertion_privateKeyFile_get(swigCPtr);
  }

  public void setSignMethod(int value) {
    lassoJNI.SamlAssertion_signMethod_set(swigCPtr, value);
  }

  public int getSignMethod() {
    return lassoJNI.SamlAssertion_signMethod_get(swigCPtr);
  }

  public void setSignType(SWIGTYPE_p_LassoSignatureType value) {
    lassoJNI.SamlAssertion_signType_set(swigCPtr, SWIGTYPE_p_LassoSignatureType.getCPtr(value));
  }

  public SWIGTYPE_p_LassoSignatureType getSignType() {
    return new SWIGTYPE_p_LassoSignatureType(lassoJNI.SamlAssertion_signType_get(swigCPtr), true);
  }

  public void setAdvice(SamlAdvice value) {
    lassoJNI.SamlAssertion_advice_set(swigCPtr, SamlAdvice.getCPtr(value));
  }

  public SamlAdvice getAdvice() {
    long cPtr = lassoJNI.SamlAssertion_advice_get(swigCPtr);
    return (cPtr == 0) ? null : new SamlAdvice(cPtr, false);
  }

  public void setAttributeStatement(SamlAttributeStatement value) {
    lassoJNI.SamlAssertion_attributeStatement_set(swigCPtr, SamlAttributeStatement.getCPtr(value));
  }

  public SamlAttributeStatement getAttributeStatement() {
    long cPtr = lassoJNI.SamlAssertion_attributeStatement_get(swigCPtr);
    return (cPtr == 0) ? null : new SamlAttributeStatement(cPtr, false);
  }

  public void setAuthenticationStatement(SamlAuthenticationStatement value) {
    lassoJNI.SamlAssertion_authenticationStatement_set(swigCPtr, SamlAuthenticationStatement.getCPtr(value));
  }

  public SamlAuthenticationStatement getAuthenticationStatement() {
    long cPtr = lassoJNI.SamlAssertion_authenticationStatement_get(swigCPtr);
    return (cPtr == 0) ? null : new SamlAuthenticationStatement(cPtr, false);
  }

  public void setConditions(SamlConditions value) {
    lassoJNI.SamlAssertion_conditions_set(swigCPtr, SamlConditions.getCPtr(value));
  }

  public SamlConditions getConditions() {
    long cPtr = lassoJNI.SamlAssertion_conditions_get(swigCPtr);
    return (cPtr == 0) ? null : new SamlConditions(cPtr, false);
  }

  public void setSubjectStatement(SamlSubjectStatement value) {
    lassoJNI.SamlAssertion_subjectStatement_set(swigCPtr, SamlSubjectStatement.getCPtr(value));
  }

  public SamlSubjectStatement getSubjectStatement() {
    long cPtr = lassoJNI.SamlAssertion_subjectStatement_get(swigCPtr);
    return (cPtr == 0) ? null : new SamlSubjectStatement(cPtr, false);
  }

  public SamlAssertion() {
    this(lassoJNI.new_SamlAssertion(), true);
  }

  public String dump() {
    return lassoJNI.SamlAssertion_dump(swigCPtr);
  }

}