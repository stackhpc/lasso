/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class LibRequestAuthnContext extends Node {
  protected LibRequestAuthnContext(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(LibRequestAuthnContext obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setAuthnContextComparison(String value) {
    lassoJNI.LibRequestAuthnContext_authnContextComparison_set(swigCPtr, value);
  }

  public String getAuthnContextComparison() {
    return lassoJNI.LibRequestAuthnContext_authnContextComparison_get(swigCPtr);
  }

  public void setAuthnContextClassRef(StringList value) {
    lassoJNI.LibRequestAuthnContext_authnContextClassRef_set(swigCPtr, StringList.getCPtr(value));
  }

  public StringList getAuthnContextClassRef() {
    long cPtr = lassoJNI.LibRequestAuthnContext_authnContextClassRef_get(swigCPtr);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public void setAuthnContextStatementRef(StringList value) {
    lassoJNI.LibRequestAuthnContext_authnContextStatementRef_set(swigCPtr, StringList.getCPtr(value));
  }

  public StringList getAuthnContextStatementRef() {
    long cPtr = lassoJNI.LibRequestAuthnContext_authnContextStatementRef_get(swigCPtr);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public LibRequestAuthnContext() {
    this(lassoJNI.new_LibRequestAuthnContext(), true);
  }

  public String dump() {
    return lassoJNI.LibRequestAuthnContext_dump(swigCPtr);
  }

}
