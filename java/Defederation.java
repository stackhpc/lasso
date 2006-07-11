/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.28
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.entrouvert.lasso;

public class Defederation {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected Defederation(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Defederation obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      lassoJNI.delete_Defederation(swigCPtr);
    }
    swigCPtr = 0;
  }

  public String getArtifact() {
    return lassoJNI.Defederation_artifact_get(swigCPtr);
  }

  public void setArtifactMessage(String value) {
    lassoJNI.Defederation_artifactMessage_set(swigCPtr, value);
  }

  public String getArtifactMessage() {
    return lassoJNI.Defederation_artifactMessage_get(swigCPtr);
  }

  public void setIdentity(Identity value) {
    lassoJNI.Defederation_identity_set(swigCPtr, Identity.getCPtr(value));
  }

  public Identity getIdentity() {
    long cPtr = lassoJNI.Defederation_identity_get(swigCPtr);
    return (cPtr == 0) ? null : new Identity(cPtr, false);
  }

  public boolean getIsIdentityDirty() {
    return lassoJNI.Defederation_isIdentityDirty_get(swigCPtr);
  }

  public boolean getIsSessionDirty() {
    return lassoJNI.Defederation_isSessionDirty_get(swigCPtr);
  }

  public String getMsgBody() {
    return lassoJNI.Defederation_msgBody_get(swigCPtr);
  }

  public String getMsgRelayState() {
    return lassoJNI.Defederation_msgRelayState_get(swigCPtr);
  }

  public String getMsgUrl() {
    return lassoJNI.Defederation_msgUrl_get(swigCPtr);
  }

  public void setNameIdentifier(Node value) {
    lassoJNI.Defederation_nameIdentifier_set(swigCPtr, Node.getCPtr(value));
  }

  public Node getNameIdentifier() {
	long cPtr = lassoJNI.Defederation_nameIdentifier_get(swigCPtr);
	return (cPtr == 0) ? null : (Node) lassoJNI.downcast_node(cPtr);
}

  public void setRemoteProviderId(String value) {
    lassoJNI.Defederation_remoteProviderId_set(swigCPtr, value);
  }

  public String getRemoteProviderId() {
    return lassoJNI.Defederation_remoteProviderId_get(swigCPtr);
  }

  public void setRequest(Node value) {
    lassoJNI.Defederation_request_set(swigCPtr, Node.getCPtr(value));
  }

  public Node getRequest() {
	long cPtr = lassoJNI.Defederation_request_get(swigCPtr);
	return (cPtr == 0) ? null : (Node) lassoJNI.downcast_node(cPtr);
}

  public void setResponse(Node value) {
    lassoJNI.Defederation_response_set(swigCPtr, Node.getCPtr(value));
  }

  public Node getResponse() {
	long cPtr = lassoJNI.Defederation_response_get(swigCPtr);
	return (cPtr == 0) ? null : (Node) lassoJNI.downcast_node(cPtr);
}

  public void setServer(Server value) {
    lassoJNI.Defederation_server_set(swigCPtr, Server.getCPtr(value));
  }

  public Server getServer() {
    long cPtr = lassoJNI.Defederation_server_get(swigCPtr);
    return (cPtr == 0) ? null : new Server(cPtr, false);
  }

  public void setSession(Session value) {
    lassoJNI.Defederation_session_set(swigCPtr, Session.getCPtr(value));
  }

  public Session getSession() {
    long cPtr = lassoJNI.Defederation_session_get(swigCPtr);
    return (cPtr == 0) ? null : new Session(cPtr, false);
  }

  public Defederation(Server server) {
    this(lassoJNI.new_Defederation(Server.getCPtr(server)), true);
  }

  public int setIdentityFromDump(String dump) {
    return lassoJNI.Defederation_setIdentityFromDump(swigCPtr, dump);
  }

  public int setSessionFromDump(String dump) {
    return lassoJNI.Defederation_setSessionFromDump(swigCPtr, dump);
  }

  public int buildNotificationMsg() {
    return lassoJNI.Defederation_buildNotificationMsg(swigCPtr);
  }

  public int initNotification(String remoteProviderId, int httpMethod) {
    return lassoJNI.Defederation_initNotification(swigCPtr, remoteProviderId, httpMethod);
  }

  public int processNotificationMsg(String notificationMsg) {
    return lassoJNI.Defederation_processNotificationMsg(swigCPtr, notificationMsg);
  }

  public int validateNotification() {
    return lassoJNI.Defederation_validateNotification(swigCPtr);
  }

}
