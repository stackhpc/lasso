/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
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

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      lassoJNI.delete_Defederation(swigCPtr);
    }
    swigCPtr = 0;
  }

  public String getArtifact() {
    return lassoJNI.Defederation_artifact_get(swigCPtr, this);
  }

  public void setArtifactMessage(String value) {
    lassoJNI.Defederation_artifactMessage_set(swigCPtr, this, value);
  }

  public String getArtifactMessage() {
    return lassoJNI.Defederation_artifactMessage_get(swigCPtr, this);
  }

  public void setIdentity(Identity value) {
    lassoJNI.Defederation_identity_set(swigCPtr, this, Identity.getCPtr(value), value);
  }

  public Identity getIdentity() {
    long cPtr = lassoJNI.Defederation_identity_get(swigCPtr, this);
    return (cPtr == 0) ? null : new Identity(cPtr, false);
  }

  public boolean getIsIdentityDirty() {
    return lassoJNI.Defederation_isIdentityDirty_get(swigCPtr, this);
  }

  public boolean getIsSessionDirty() {
    return lassoJNI.Defederation_isSessionDirty_get(swigCPtr, this);
  }

  public String getMsgBody() {
    return lassoJNI.Defederation_msgBody_get(swigCPtr, this);
  }

  public String getMsgRelayState() {
    return lassoJNI.Defederation_msgRelayState_get(swigCPtr, this);
  }

  public String getMsgUrl() {
    return lassoJNI.Defederation_msgUrl_get(swigCPtr, this);
  }

  public void setNameIdentifier(Node value) {
    lassoJNI.Defederation_nameIdentifier_set(swigCPtr, this, Node.getCPtr(value), value);
  }

  public Node getNameIdentifier() {
	long cPtr = lassoJNI.Defederation_nameIdentifier_get(swigCPtr, this);
	return (cPtr == 0) ? null : (Node) lassoJNI.downcast_node(cPtr, null);
}

  public void setRemoteProviderId(String value) {
    lassoJNI.Defederation_remoteProviderId_set(swigCPtr, this, value);
  }

  public String getRemoteProviderId() {
    return lassoJNI.Defederation_remoteProviderId_get(swigCPtr, this);
  }

  public void setRequest(Node value) {
    lassoJNI.Defederation_request_set(swigCPtr, this, Node.getCPtr(value), value);
  }

  public Node getRequest() {
	long cPtr = lassoJNI.Defederation_request_get(swigCPtr, this);
	return (cPtr == 0) ? null : (Node) lassoJNI.downcast_node(cPtr, null);
}

  public void setResponse(Node value) {
    lassoJNI.Defederation_response_set(swigCPtr, this, Node.getCPtr(value), value);
  }

  public Node getResponse() {
	long cPtr = lassoJNI.Defederation_response_get(swigCPtr, this);
	return (cPtr == 0) ? null : (Node) lassoJNI.downcast_node(cPtr, null);
}

  public void setServer(Server value) {
    lassoJNI.Defederation_server_set(swigCPtr, this, Server.getCPtr(value), value);
  }

  public Server getServer() {
    long cPtr = lassoJNI.Defederation_server_get(swigCPtr, this);
    return (cPtr == 0) ? null : new Server(cPtr, false);
  }

  public void setSession(Session value) {
    lassoJNI.Defederation_session_set(swigCPtr, this, Session.getCPtr(value), value);
  }

  public Session getSession() {
    long cPtr = lassoJNI.Defederation_session_get(swigCPtr, this);
    return (cPtr == 0) ? null : new Session(cPtr, false);
  }

  public Defederation(Server server) {
    this(lassoJNI.new_Defederation(Server.getCPtr(server), server), true);
  }

  public int setIdentityFromDump(String dump) {
    return lassoJNI.Defederation_setIdentityFromDump(swigCPtr, this, dump);
  }

  public int setSessionFromDump(String dump) {
    return lassoJNI.Defederation_setSessionFromDump(swigCPtr, this, dump);
  }

  public int buildNotificationMsg() {
    return lassoJNI.Defederation_buildNotificationMsg(swigCPtr, this);
  }

  public int initNotification(String remoteProviderId, int httpMethod) {
    return lassoJNI.Defederation_initNotification(swigCPtr, this, remoteProviderId, httpMethod);
  }

  public int processNotificationMsg(String notificationMsg) {
    return lassoJNI.Defederation_processNotificationMsg(swigCPtr, this, notificationMsg);
  }

  public int validateNotification() {
    return lassoJNI.Defederation_validateNotification(swigCPtr, this);
  }

}
