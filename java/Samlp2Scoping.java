/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
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
    lassoJNI.Samlp2Scoping_requesterID_set(swigCPtr, this, value);
  }

  public String getRequesterID() {
    return lassoJNI.Samlp2Scoping_requesterID_get(swigCPtr, this);
  }

  public void setProxyCount(String value) {
    lassoJNI.Samlp2Scoping_proxyCount_set(swigCPtr, this, value);
  }

  public String getProxyCount() {
    return lassoJNI.Samlp2Scoping_proxyCount_get(swigCPtr, this);
  }

  public void setIDPList(Samlp2IDPList value) {
    lassoJNI.Samlp2Scoping_iDPList_set(swigCPtr, this, Samlp2IDPList.getCPtr(value), value);
  }

  public Samlp2IDPList getIDPList() {
    long cPtr = lassoJNI.Samlp2Scoping_iDPList_get(swigCPtr, this);
    return (cPtr == 0) ? null : new Samlp2IDPList(cPtr, false);
  }

  public Samlp2Scoping() {
    this(lassoJNI.new_Samlp2Scoping(), true);
  }

  public String dump() {
    return lassoJNI.Samlp2Scoping_dump(swigCPtr, this);
  }

}
