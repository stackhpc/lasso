/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Saml2OneTimeUse extends Saml2ConditionAbstract {
  protected Saml2OneTimeUse(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Saml2OneTimeUse obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public Saml2OneTimeUse() {
    this(lassoJNI.new_Saml2OneTimeUse(), true);
  }

  public String dump() {
    return lassoJNI.Saml2OneTimeUse_dump(swigCPtr);
  }

}