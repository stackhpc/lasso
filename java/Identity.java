/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Identity {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected Identity(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Identity obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      lassoJNI.delete_Identity(swigCPtr);
    }
    swigCPtr = 0;
  }

  public boolean getIsDirty() {
    return lassoJNI.Identity_isDirty_get(swigCPtr, this);
  }

  public StringList getProviderIds() {
    long cPtr = lassoJNI.Identity_providerIds_get(swigCPtr, this);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public Identity() {
    this(lassoJNI.new_Identity(), true);
  }

  public static Identity newFromDump(String dump) {
    long cPtr = lassoJNI.Identity_newFromDump(dump);
    return (cPtr == 0) ? null : new Identity(cPtr, true);
  }

  public String dump() {
    return lassoJNI.Identity_dump(swigCPtr, this);
  }

  public Federation getFederation(String providerId) {
    long cPtr = lassoJNI.Identity_getFederation(swigCPtr, this, providerId);
    return (cPtr == 0) ? null : new Federation(cPtr, false);
  }

}
