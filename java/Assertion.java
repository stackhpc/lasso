/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version: 1.3.21
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;


public class Assertion {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected Assertion(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected Assertion() {
    this(0, false);
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      lassoJNI.delete_Assertion(swigCPtr);
    }
    swigCPtr = 0;
  }

  protected static long getCPtr(Assertion obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  public Assertion(String issuer, String requestId) {
    this(lassoJNI.new_Assertion(issuer, requestId), true);
  }

  public String dump() {
    return lassoJNI.Assertion_dump(swigCPtr);
  }

}
