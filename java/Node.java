/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Node extends DowncastableNode {
  protected Node(long cPtr, boolean cMemoryOwn) {
    super(cPtr, cMemoryOwn);
  }

  protected static long getCPtr(Node obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
  super.delete();
}

  public Node() {
    this(lassoJNI.new_Node(), true);
  }

  public String dump() {
    return lassoJNI.Node_dump(swigCPtr);
  }

}