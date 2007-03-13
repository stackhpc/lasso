/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Samlp2Status extends Node {
  protected Samlp2Status(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Samlp2Status obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setStatusMessage(String value) {
    lassoJNI.Samlp2Status_statusMessage_set(swigCPtr, value);
  }

  public String getStatusMessage() {
    return lassoJNI.Samlp2Status_statusMessage_get(swigCPtr);
  }

  public void setStatusCode(Samlp2StatusCode value) {
    lassoJNI.Samlp2Status_statusCode_set(swigCPtr, Samlp2StatusCode.getCPtr(value));
  }

  public Samlp2StatusCode getStatusCode() {
    long cPtr = lassoJNI.Samlp2Status_statusCode_get(swigCPtr);
    return (cPtr == 0) ? null : new Samlp2StatusCode(cPtr, false);
  }

  public void setStatusDetail(Samlp2StatusDetail value) {
    lassoJNI.Samlp2Status_statusDetail_set(swigCPtr, Samlp2StatusDetail.getCPtr(value));
  }

  public Samlp2StatusDetail getStatusDetail() {
    long cPtr = lassoJNI.Samlp2Status_statusDetail_get(swigCPtr);
    return (cPtr == 0) ? null : new Samlp2StatusDetail(cPtr, false);
  }

  public Samlp2Status() {
    this(lassoJNI.new_Samlp2Status(), true);
  }

  public String dump() {
    return lassoJNI.Samlp2Status_dump(swigCPtr);
  }

}