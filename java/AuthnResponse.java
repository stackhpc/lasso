/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version: 1.3.21
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;


public class AuthnResponse {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected AuthnResponse(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected AuthnResponse() {
    this(0, false);
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      throw new UnsupportedOperationException("C++ destructor does not have public access");
    }
    swigCPtr = 0;
  }

  protected static long getCPtr(AuthnResponse obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

}
