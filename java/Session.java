/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Session {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected Session(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Session obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      lassoJNI.delete_Session(swigCPtr);
    }
    swigCPtr = 0;
  }

  public boolean getIsDirty() {
    return lassoJNI.Session_isDirty_get(swigCPtr, this);
  }

  public StringList getProviderIds() {
    long cPtr = lassoJNI.Session_providerIds_get(swigCPtr, this);
    return (cPtr == 0) ? null : new StringList(cPtr, false);
  }

  public Session() {
    this(lassoJNI.new_Session(), true);
  }

  public static Session newFromDump(String dump) {
    long cPtr = lassoJNI.Session_newFromDump(dump);
    return (cPtr == 0) ? null : new Session(cPtr, true);
  }

  public String dump() {
    return lassoJNI.Session_dump(swigCPtr, this);
  }

  public NodeList getAssertions(String providerId) {
    long cPtr = lassoJNI.Session_getAssertions(swigCPtr, this, providerId);
    return (cPtr == 0) ? null : new NodeList(cPtr, true);
  }

}
