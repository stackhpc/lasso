/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class lasso implements lassoConstants {
  public static DowncastableNode downcast_node(Node node) {
	return lassoJNI.downcast_node(Node.getCPtr(node));
}

  public static int init() {
    return lassoJNI.init();
  }

  public static int shutdown() {
    return lassoJNI.shutdown();
  }

  public static int checkVersion(int major, int minor, int subminor, int mode) {
    return lassoJNI.checkVersion(major, minor, subminor, mode);
  }

  public static int getRequestTypeFromSoapMsg(String soap) {
    return lassoJNI.getRequestTypeFromSoapMsg(soap);
  }

  public static boolean isLibertyQuery(String query) {
    return lassoJNI.isLibertyQuery(query);
  }

}
