/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class SamlNameIdentifier extends Node {
  protected SamlNameIdentifier(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(SamlNameIdentifier obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public void setContent(String content) {
    lassoJNI.set_SamlNameIdentifier_content(swigCPtr, content);
  }

  public String getContent() {
    return lassoJNI.get_SamlNameIdentifier_content(swigCPtr);
  }

  public void setFormat(String Format) {
    lassoJNI.set_SamlNameIdentifier_format(swigCPtr, Format);
  }

  public String getFormat() {
    return lassoJNI.get_SamlNameIdentifier_format(swigCPtr);
  }

  public void setNameQualifier(String NameQualifier) {
    lassoJNI.set_SamlNameIdentifier_nameQualifier(swigCPtr, NameQualifier);
  }

  public String getNameQualifier() {
    return lassoJNI.get_SamlNameIdentifier_nameQualifier(swigCPtr);
  }

  public SamlNameIdentifier() {
    this(lassoJNI.new_SamlNameIdentifier(), true);
  }

  public String dump() {
    return lassoJNI.SamlNameIdentifier_dump(swigCPtr);
  }

}
