/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Saml2AudienceRestriction extends Saml2ConditionAbstract {
  protected Saml2AudienceRestriction(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Saml2AudienceRestriction obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setAudience(String value) {
    lassoJNI.Saml2AudienceRestriction_Audience_set(swigCPtr, value);
  }

  public String getAudience() {
    return lassoJNI.Saml2AudienceRestriction_Audience_get(swigCPtr);
  }

  public Saml2AudienceRestriction() {
    this(lassoJNI.new_Saml2AudienceRestriction(), true);
  }

  public String dump() {
    return lassoJNI.Saml2AudienceRestriction_dump(swigCPtr);
  }

}
