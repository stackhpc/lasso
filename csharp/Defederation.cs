/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace lasso {

using System;

public class Defederation : IDisposable {
  private IntPtr swigCPtr;
  protected bool swigCMemOwn;

  internal Defederation(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  internal static IntPtr getCPtr(Defederation obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
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

  public SamlNameIdentifier nameIdentifier {
    set {
      lassoPINVOKE.set_Defederation_nameIdentifier(swigCPtr, SamlNameIdentifier.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Defederation_nameIdentifier(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new SamlNameIdentifier(cPtr, false);
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

  public SamlpRequestAbstract request {
    set {
      lassoPINVOKE.set_Defederation_request(swigCPtr, SamlpRequestAbstract.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Defederation_request(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new SamlpRequestAbstract(cPtr, false);
    } 
  }

  public SamlpResponseAbstract response {
    set {
      lassoPINVOKE.set_Defederation_response(swigCPtr, SamlpResponseAbstract.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Defederation_response(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new SamlpResponseAbstract(cPtr, false);
    } 
  }

  public Server server {
    set {
      lassoPINVOKE.set_Defederation_server(swigCPtr, Server.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Defederation_server(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new Server(cPtr, false);
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

  public Defederation(Server server) : this(lassoPINVOKE.new_Defederation(Server.getCPtr(server)), true) {
  }

  public int setIdentityFromDump(string dump) {
    return lassoPINVOKE.Defederation_setIdentityFromDump(swigCPtr, dump);
  }

  public int setSessionFromDump(string dump) {
    return lassoPINVOKE.Defederation_setSessionFromDump(swigCPtr, dump);
  }

  public int buildNotificationMsg() {
    return lassoPINVOKE.Defederation_buildNotificationMsg(swigCPtr);
  }

  public int initNotification(string remoteProviderId, HttpMethod httpMethod) {
    return lassoPINVOKE.Defederation_initNotification(swigCPtr, remoteProviderId, (int)httpMethod);
  }

  public int processNotificationMsg(string notificationMsg) {
    return lassoPINVOKE.Defederation_processNotificationMsg(swigCPtr, notificationMsg);
  }

  public int validateNotification() {
    return lassoPINVOKE.Defederation_validateNotification(swigCPtr);
  }

}

}
