/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Samlp2Scoping extends Node {
  protected Samlp2Scoping(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Samlp2Scoping obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setRequesterID(String value) {
    lassoJNI.Samlp2Scoping_RequesterID_set(swigCPtr, value);
  }

  public String getRequesterID() {
    return lassoJNI.Samlp2Scoping_RequesterID_get(swigCPtr);
  }

  public void setProxyCount(String value) {
    lassoJNI.Samlp2Scoping_ProxyCount_set(swigCPtr, value);
  }

  public String getProxyCount() {
    return lassoJNI.Samlp2Scoping_ProxyCount_get(swigCPtr);
  }

  public void setIDPList(Samlp2IDPList value) {
    lassoJNI.Samlp2Scoping_iDPList_set(swigCPtr, Samlp2IDPList.getCPtr(value));
  }

  public Samlp2IDPList getIDPList() {
    long cPtr = lassoJNI.Samlp2Scoping_iDPList_get(swigCPtr);
    return (cPtr == 0) ? null : new Samlp2IDPList(cPtr, false);
  }

  public Samlp2Scoping() {
    this(lassoJNI.new_Samlp2Scoping(), true);
  }

  public String dump() {
    return lassoJNI.Samlp2Scoping_dump(swigCPtr);
  }

}