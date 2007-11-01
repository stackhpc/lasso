/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Saml2Advice extends Node {
  protected Saml2Advice(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Saml2Advice obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setAssertionIDRef(NodeList value) {
    lassoJNI.Saml2Advice_assertionIDRef_set(swigCPtr, this, NodeList.getCPtr(value), value);
  }

  public NodeList getAssertionIDRef() {
    long cPtr = lassoJNI.Saml2Advice_assertionIDRef_get(swigCPtr, this);
    return (cPtr == 0) ? null : new NodeList(cPtr, false);
  }

  public void setAssertionURIRef(StringList value) {
    lassoJNI.Saml2Advice_assertionURIRef_set(swigCPtr, this, StringList.getCPtr(value), value);
  }

  public StringList getAssertionURIRef() {
    long cPtr = lassoJNI.Saml2Advice_assertionURIRef_get(swigCPtr, this);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public void setAssertion(NodeList value) {
    lassoJNI.Saml2Advice_assertion_set(swigCPtr, this, NodeList.getCPtr(value), value);
  }

  public NodeList getAssertion() {
    long cPtr = lassoJNI.Saml2Advice_assertion_get(swigCPtr, this);
    return (cPtr == 0) ? null : new NodeList(cPtr, false);
  }

  public void setEncryptedAssertion(NodeList value) {
    lassoJNI.Saml2Advice_encryptedAssertion_set(swigCPtr, this, NodeList.getCPtr(value), value);
  }

  public NodeList getEncryptedAssertion() {
    long cPtr = lassoJNI.Saml2Advice_encryptedAssertion_get(swigCPtr, this);
    return (cPtr == 0) ? null : new NodeList(cPtr, false);
  }

  public Saml2Advice() {
    this(lassoJNI.new_Saml2Advice(), true);
  }

  public String dump() {
    return lassoJNI.Saml2Advice_dump(swigCPtr, this);
  }

}
