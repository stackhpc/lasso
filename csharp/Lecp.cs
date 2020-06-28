/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version: 1.3.21
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

//package lasso;

using System;
public class Lecp : IDisposable {
  private IntPtr swigCPtr;
  protected bool swigCMemOwn;

  internal Lecp(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected Lecp() : this(IntPtr.Zero, false) {
  }

  ~Lecp() {
    Dispose();
  }

  public virtual void Dispose() {
    if(swigCPtr != IntPtr.Zero && swigCMemOwn) {
      swigCMemOwn = false;
      lassoPINVOKE.delete_Lecp(swigCPtr);
    }
    swigCPtr = IntPtr.Zero;
    GC.SuppressFinalize(this);
  }

  internal static IntPtr getCPtr(Lecp obj) {
    return (obj == null) ? IntPtr.Zero : obj.swigCPtr;
  }

  public AuthnRequest authnRequest {
    get {
      IntPtr cPtr = lassoPINVOKE.get_Lecp_authnRequest(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new AuthnRequest(cPtr, false);
    } 
  }

  public AuthnResponse authnResponse {
    get {
      IntPtr cPtr = lassoPINVOKE.get_Lecp_authnResponse(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new AuthnResponse(cPtr, false);
    } 
  }

  public Identity identity {
    set {
      lassoPINVOKE.set_Lecp_identity(swigCPtr, Identity.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Lecp_identity(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new Identity(cPtr, false);
    } 
  }

  public bool isIdentityDirty {
    get {
      return lassoPINVOKE.get_Lecp_isIdentityDirty(swigCPtr);
    } 
  }

  public bool isSessionDirty {
    get {
      return lassoPINVOKE.get_Lecp_isSessionDirty(swigCPtr);
    } 
  }

  public string msgBody {
    get {
      return lassoPINVOKE.get_Lecp_msgBody(swigCPtr);
    } 
  }

  public string msgRelayState {
    get {
      return lassoPINVOKE.get_Lecp_msgRelayState(swigCPtr);
    } 
  }

  public string msgUrl {
    get {
      return lassoPINVOKE.get_Lecp_msgUrl(swigCPtr);
    } 
  }

  public string nameIdentifier {
    get {
      return lassoPINVOKE.get_Lecp_nameIdentifier(swigCPtr);
    } 
  }

  public string remoteProviderId {
    set {
      lassoPINVOKE.set_Lecp_remoteProviderId(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_Lecp_remoteProviderId(swigCPtr);
    } 
  }

  public Request request {
    get {
      IntPtr cPtr = lassoPINVOKE.get_Lecp_request(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new Request(cPtr, false);
    } 
  }

  public Response response {
    get {
      IntPtr cPtr = lassoPINVOKE.get_Lecp_response(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new Response(cPtr, false);
    } 
  }

  public string responseStatus {
    set {
      lassoPINVOKE.set_Lecp_responseStatus(swigCPtr, value);
    } 
    get {
      return lassoPINVOKE.get_Lecp_responseStatus(swigCPtr);
    } 
  }

  public Session session {
    set {
      lassoPINVOKE.set_Lecp_session(swigCPtr, Session.getCPtr(value));
    } 
    get {
      IntPtr cPtr = lassoPINVOKE.get_Lecp_session(swigCPtr);
      return (cPtr == IntPtr.Zero) ? null : new Session(cPtr, false);
    } 
  }

  public Lecp(Server server) : this(lassoPINVOKE.new_Lecp(Server.getCPtr(server)), true) {
  }

  public void setIdentityFromDump(string dump) {
    lassoPINVOKE.Lecp_setIdentityFromDump(swigCPtr, dump);
  }

  public void setSessionFromDump(string dump) {
    lassoPINVOKE.Lecp_setSessionFromDump(swigCPtr, dump);
  }

  public void buildAuthnRequestEnvelopeMsg() {
    lassoPINVOKE.Lecp_buildAuthnRequestEnvelopeMsg(swigCPtr);
  }

  public void buildAuthnRequestMsg(string remoteProviderId) {
    lassoPINVOKE.Lecp_buildAuthnRequestMsg(swigCPtr, remoteProviderId);
  }

  public void buildAuthnResponseEnvelopeMsg(int authenticationResult, string authenticationMethod, string reauthenticateOnOrAfter) {
    lassoPINVOKE.Lecp_buildAuthnResponseEnvelopeMsg(swigCPtr, authenticationResult, authenticationMethod, reauthenticateOnOrAfter);
  }

  public void buildAuthnResponseMsg() {
    lassoPINVOKE.Lecp_buildAuthnResponseMsg(swigCPtr);
  }

  public void initAuthnRequest() {
    lassoPINVOKE.Lecp_initAuthnRequest(swigCPtr);
  }

  public void initFromAuthnRequestMsg(string authnRequestMsg, int httpMethod) {
    lassoPINVOKE.Lecp_initFromAuthnRequestMsg(swigCPtr, authnRequestMsg, httpMethod);
  }

  public void processAuthnRequestEnvelopeMsg(string requestMsg) {
    lassoPINVOKE.Lecp_processAuthnRequestEnvelopeMsg(swigCPtr, requestMsg);
  }

  public void processAuthnResponseEnvelopeMsg(string responseMsg) {
    lassoPINVOKE.Lecp_processAuthnResponseEnvelopeMsg(swigCPtr, responseMsg);
  }

}