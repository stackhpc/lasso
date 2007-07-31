/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Saml2AuthzDecisionStatement extends Saml2StatementAbstract {
  protected Saml2AuthzDecisionStatement(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Saml2AuthzDecisionStatement obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setResource(String value) {
    lassoJNI.Saml2AuthzDecisionStatement_resource_set(swigCPtr, this, value);
  }

  public String getResource() {
    return lassoJNI.Saml2AuthzDecisionStatement_resource_get(swigCPtr, this);
  }

  public void setDecision(String value) {
    lassoJNI.Saml2AuthzDecisionStatement_decision_set(swigCPtr, this, value);
  }

  public String getDecision() {
    return lassoJNI.Saml2AuthzDecisionStatement_decision_get(swigCPtr, this);
  }

  public void setAction(Saml2Action value) {
    lassoJNI.Saml2AuthzDecisionStatement_action_set(swigCPtr, this, Saml2Action.getCPtr(value), value);
  }

  public Saml2Action getAction() {
    long cPtr = lassoJNI.Saml2AuthzDecisionStatement_action_get(swigCPtr, this);
    return (cPtr == 0) ? null : new Saml2Action(cPtr, false);
  }

  public void setEvidence(Saml2Evidence value) {
    lassoJNI.Saml2AuthzDecisionStatement_evidence_set(swigCPtr, this, Saml2Evidence.getCPtr(value), value);
  }

  public Saml2Evidence getEvidence() {
    long cPtr = lassoJNI.Saml2AuthzDecisionStatement_evidence_get(swigCPtr, this);
    return (cPtr == 0) ? null : new Saml2Evidence(cPtr, false);
  }

  public Saml2AuthzDecisionStatement() {
    this(lassoJNI.new_Saml2AuthzDecisionStatement(), true);
  }

  public String dump() {
    return lassoJNI.Saml2AuthzDecisionStatement_dump(swigCPtr, this);
  }

}
