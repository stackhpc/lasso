/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version: 1.3.21
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

//package lasso;

using System;
public class Defederation : IDisposable {
  private IntPtr swigCPtr;
  protected bool swigCMemOwn;

  internal Defederation(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected Defederation() : this(IntPtr.Zero, false) {
  }

  ~Defederation() {
    Dispose();
  }

  public virtual void Dispose() {
    if(swigCPtr != IntPtr.Zero && swigCMemOwn) {
      swigCMemOwn = false;
      lassoPINVOKE.delete_Defederation(swigCPtr);
    }
    swigCPtr = IntPtr.Zero;
    GC.SuppressFinalize(this);
  }

  internal static IntPtr getCPtr(Defederation obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  public Identity identity {
    set {
      lassoPINVOKE.set_Defederation_identity(swigCPtr, Identity.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Defederation_identity(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new Identity(cPtr, false);
    } 
  }

  public bool isIdentityDirty {
    get {
      return lassoPINVOKE.get_Defederation_isIdentityDirty(swigCPtr);
    } 
  }

  public bool isSessionDirty {
    get {
      return lassoPINVOKE.get_Defederation_isSessionDirty(swigCPtr);
    } 
  }

  public string msgBody {
    get {
      return lassoPINVOKE.get_Defederation_msgBody(swigCPtr);
    } 
  }

  public string msgRelayState {
    get {
      return lassoPINVOKE.get_Defederation_msgRelayState(swigCPtr);
    } 
  }

  public string msgUrl {
    get {
      return lassoPINVOKE.get_Defederation_msgUrl(swigCPtr);
    } 
  }

  public string nameIdentifier {
    get {
      return lassoPINVOKE.get_Defederation_nameIdentifier(swigCPtr);
    } 
  }

  public string remoteProviderId {
    set {
      lassoPINVOKE.set_Defederation_remoteProviderId(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_Defederation_remoteProviderId(swigCPtr);
    } 
  }

  public FederationTerminationNotification request {
    get {
      IntPtr cPtr = lassoPINVOKE.get_Defederation_request(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new FederationTerminationNotification(cPtr, false);
    } 
  }

  public Session session {
    set {
      lassoPINVOKE.set_Defederation_session(swigCPtr, Session.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Defederation_session(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new Session(cPtr, false);
    } 
  }

  public Defederation(Server server, int providerType) : this(lassoPINVOKE.new_Defederation(Server.getCPtr(server), providerType), true) {
  }

  public void setIdentityFromDump(string dump) {
    lassoPINVOKE.Defederation_setIdentityFromDump(swigCPtr, dump);
  }

  public void setSessionFromDump(string dump) {
    lassoPINVOKE.Defederation_setSessionFromDump(swigCPtr, dump);
  }

  public void buildNotificationMsg() {
    lassoPINVOKE.Defederation_buildNotificationMsg(swigCPtr);
  }

  public void initNotification(string remoteProviderId, int httpMethod) {
    lassoPINVOKE.Defederation_initNotification(swigCPtr, remoteProviderId, httpMethod);
  }

  public void processNotificationMsg(string notificationMsg, int httpMethod) {
    lassoPINVOKE.Defederation_processNotificationMsg(swigCPtr, notificationMsg, httpMethod);
  }

  public void validateNotification() {
    lassoPINVOKE.Defederation_validateNotification(swigCPtr);
  }

}