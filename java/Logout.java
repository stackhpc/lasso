/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Logout {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected Logout(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Logout obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      lassoJNI.delete_Logout(swigCPtr);
    }
    swigCPtr = 0;
  }

  public String getArtifact() {
    return lassoJNI.Logout_artifact_get(swigCPtr);
  }

  public void setArtifactMessage(String value) {
    lassoJNI.Logout_artifactMessage_set(swigCPtr, value);
  }

  public String getArtifactMessage() {
    return lassoJNI.Logout_artifactMessage_get(swigCPtr);
  }

  public void setIdentity(Identity value) {
    lassoJNI.Logout_identity_set(swigCPtr, Identity.getCPtr(value));
  }

  public Identity getIdentity() {
    long cPtr = lassoJNI.Logout_identity_get(swigCPtr);
    return (cPtr == 0) ? null : new Identity(cPtr, false);
  }

  public boolean getIsIdentityDirty() {
    return lassoJNI.Logout_isIdentityDirty_get(swigCPtr);
  }

  public boolean getIsSessionDirty() {
    return lassoJNI.Logout_isSessionDirty_get(swigCPtr);
  }

  public String getMsgBody() {
    return lassoJNI.Logout_msgBody_get(swigCPtr);
  }

  public String getMsgRelayState() {
    return lassoJNI.Logout_msgRelayState_get(swigCPtr);
  }

  public String getMsgUrl() {
    return lassoJNI.Logout_msgUrl_get(swigCPtr);
  }

  public void setNameIdentifier(Node value) {
    lassoJNI.Logout_nameIdentifier_set(swigCPtr, Node.getCPtr(value));
  }

  public Node getNameIdentifier() {
	long cPtr = lassoJNI.Logout_nameIdentifier_get(swigCPtr);
	return (cPtr == 0) ? null : (Node) lassoJNI.downcast_node(cPtr);
}

  public void setRemoteProviderId(String value) {
    lassoJNI.Logout_remoteProviderId_set(swigCPtr, value);
  }

  public String getRemoteProviderId() {
    return lassoJNI.Logout_remoteProviderId_get(swigCPtr);
  }

  public void setRequest(Node value) {
    lassoJNI.Logout_request_set(swigCPtr, Node.getCPtr(value));
  }

  public Node getRequest() {
	long cPtr = lassoJNI.Logout_request_get(swigCPtr);
	return (cPtr == 0) ? null : (Node) lassoJNI.downcast_node(cPtr);
}

  public void setResponse(Node value) {
    lassoJNI.Logout_response_set(swigCPtr, Node.getCPtr(value));
  }

  public Node getResponse() {
	long cPtr = lassoJNI.Logout_response_get(swigCPtr);
	return (cPtr == 0) ? null : (Node) lassoJNI.downcast_node(cPtr);
}

  public void setServer(Server value) {
    lassoJNI.Logout_server_set(swigCPtr, Server.getCPtr(value));
  }

  public Server getServer() {
    long cPtr = lassoJNI.Logout_server_get(swigCPtr);
    return (cPtr == 0) ? null : new Server(cPtr, false);
  }

  public void setSession(Session value) {
    lassoJNI.Logout_session_set(swigCPtr, Session.getCPtr(value));
  }

  public Session getSession() {
    long cPtr = lassoJNI.Logout_session_get(swigCPtr);
    return (cPtr == 0) ? null : new Session(cPtr, false);
  }

  public Logout(Server server) {
    this(lassoJNI.new_Logout(Server.getCPtr(server)), true);
  }

  public static Logout newFromDump(Server server, String dump) {
    long cPtr = lassoJNI.Logout_newFromDump(Server.getCPtr(server), dump);
    return (cPtr == 0) ? null : new Logout(cPtr, true);
  }

  public int setIdentityFromDump(String dump) {
    return lassoJNI.Logout_setIdentityFromDump(swigCPtr, dump);
  }

  public int setSessionFromDump(String dump) {
    return lassoJNI.Logout_setSessionFromDump(swigCPtr, dump);
  }

  public int buildRequestMsg() {
    return lassoJNI.Logout_buildRequestMsg(swigCPtr);
  }

  public int buildResponseMsg() {
    return lassoJNI.Logout_buildResponseMsg(swigCPtr);
  }

  public String dump() {
    return lassoJNI.Logout_dump(swigCPtr);
  }

  public String getNextProviderId() {
    return lassoJNI.Logout_getNextProviderId(swigCPtr);
  }

  public int initRequest(String remoteProviderId, int httpMethod) {
    return lassoJNI.Logout_initRequest(swigCPtr, remoteProviderId, httpMethod);
  }

  public int processRequestMsg(String requestMsg) {
    return lassoJNI.Logout_processRequestMsg(swigCPtr, requestMsg);
  }

  public int processResponseMsg(String responseMsg) {
    return lassoJNI.Logout_processResponseMsg(swigCPtr, responseMsg);
  }

  public int resetProviderIdIndex() {
    return lassoJNI.Logout_resetProviderIdIndex(swigCPtr);
  }

  public int validateRequest() {
    return lassoJNI.Logout_validateRequest(swigCPtr);
  }

}
