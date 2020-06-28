# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _lasso

def _swig_setattr(self,class_type,name,value):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    self.__dict__[name] = value

def _swig_getattr(self,class_type,name):
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


Error = _lasso.Error
SyntaxError = _lasso.SyntaxError


init = _lasso.init

shutdown = _lasso.shutdown
httpMethodAny = _lasso.httpMethodAny
httpMethodGet = _lasso.httpMethodGet
httpMethodPost = _lasso.httpMethodPost
httpMethodRedirect = _lasso.httpMethodRedirect
httpMethodSoap = _lasso.httpMethodSoap
libConsentObtained = _lasso.libConsentObtained
libConsentUnavailable = _lasso.libConsentUnavailable
libConsentInapplicable = _lasso.libConsentInapplicable
libNameIdPolicyTypeNone = _lasso.libNameIdPolicyTypeNone
libNameIdPolicyTypeOneTime = _lasso.libNameIdPolicyTypeOneTime
libNameIdPolicyTypeFederated = _lasso.libNameIdPolicyTypeFederated
libNameIdPolicyTypeAny = _lasso.libNameIdPolicyTypeAny
libProtocolProfileBrwsArt = _lasso.libProtocolProfileBrwsArt
libProtocolProfileBrwsPost = _lasso.libProtocolProfileBrwsPost
libProtocolProfileFedTermIdpHttp = _lasso.libProtocolProfileFedTermIdpHttp
libProtocolProfileFedTermIdpSoap = _lasso.libProtocolProfileFedTermIdpSoap
libProtocolProfileFedTermSpHttp = _lasso.libProtocolProfileFedTermSpHttp
libProtocolProfileFedTermSpSoap = _lasso.libProtocolProfileFedTermSpSoap
libProtocolProfileRniIdpHttp = _lasso.libProtocolProfileRniIdpHttp
libProtocolProfileRniIdpSoap = _lasso.libProtocolProfileRniIdpSoap
libProtocolProfileRniSpHttp = _lasso.libProtocolProfileRniSpHttp
libProtocolProfileRniSpSoap = _lasso.libProtocolProfileRniSpSoap
libProtocolProfileSloIdpHttp = _lasso.libProtocolProfileSloIdpHttp
libProtocolProfileSloIdpSoap = _lasso.libProtocolProfileSloIdpSoap
libProtocolProfileSloSpHttp = _lasso.libProtocolProfileSloSpHttp
libProtocolProfileSloSpSoap = _lasso.libProtocolProfileSloSpSoap
loginProtocolProfileBrwsArt = _lasso.loginProtocolProfileBrwsArt
loginProtocolProfileBrwsPost = _lasso.loginProtocolProfileBrwsPost
messageTypeNone = _lasso.messageTypeNone
messageTypeAuthnRequest = _lasso.messageTypeAuthnRequest
messageTypeAuthnResponse = _lasso.messageTypeAuthnResponse
messageTypeRequest = _lasso.messageTypeRequest
messageTypeResponse = _lasso.messageTypeResponse
messageTypeArtifact = _lasso.messageTypeArtifact
providerTypeNone = _lasso.providerTypeNone
providerTypeSp = _lasso.providerTypeSp
providerTypeIdp = _lasso.providerTypeIdp
requestTypeInvalid = _lasso.requestTypeInvalid
requestTypeLogin = _lasso.requestTypeLogin
requestTypeLogout = _lasso.requestTypeLogout
requestTypeDefederation = _lasso.requestTypeDefederation
requestTypeRegisterNameIdentifier = _lasso.requestTypeRegisterNameIdentifier
requestTypeNameIdentifierMapping = _lasso.requestTypeNameIdentifierMapping
requestTypeLecp = _lasso.requestTypeLecp
samlAuthenticationMethodPassword = _lasso.samlAuthenticationMethodPassword
samlAuthenticationMethodKerberos = _lasso.samlAuthenticationMethodKerberos
samlAuthenticationMethodSecureRemotePassword = _lasso.samlAuthenticationMethodSecureRemotePassword
samlAuthenticationMethodHardwareToken = _lasso.samlAuthenticationMethodHardwareToken
samlAuthenticationMethodSmartcardPki = _lasso.samlAuthenticationMethodSmartcardPki
samlAuthenticationMethodSoftwarePki = _lasso.samlAuthenticationMethodSoftwarePki
samlAuthenticationMethodPgp = _lasso.samlAuthenticationMethodPgp
samlAuthenticationMethodSpki = _lasso.samlAuthenticationMethodSpki
samlAuthenticationMethodXkms = _lasso.samlAuthenticationMethodXkms
samlAuthenticationMethodXmlDsig = _lasso.samlAuthenticationMethodXmlDsig
samlAuthenticationMethodUnspecified = _lasso.samlAuthenticationMethodUnspecified
signatureMethodRsaSha1 = _lasso.signatureMethodRsaSha1
signatureMethodDsaSha1 = _lasso.signatureMethodDsaSha1
XML_ERROR_NODE_NOT_FOUND = _lasso.XML_ERROR_NODE_NOT_FOUND
XML_ERROR_NODE_CONTENT_NOT_FOUND = _lasso.XML_ERROR_NODE_CONTENT_NOT_FOUND
XML_ERROR_ATTR_NOT_FOUND = _lasso.XML_ERROR_ATTR_NOT_FOUND
XML_ERROR_ATTR_VALUE_NOT_FOUND = _lasso.XML_ERROR_ATTR_VALUE_NOT_FOUND
DS_ERROR_SIGNATURE_TMPL_CREATION_FAILED = _lasso.DS_ERROR_SIGNATURE_TMPL_CREATION_FAILED
DS_ERROR_CONTEXT_CREATION_FAILED = _lasso.DS_ERROR_CONTEXT_CREATION_FAILED
DS_ERROR_PUBLIC_KEY_LOAD_FAILED = _lasso.DS_ERROR_PUBLIC_KEY_LOAD_FAILED
DS_ERROR_PRIVATE_KEY_LOAD_FAILED = _lasso.DS_ERROR_PRIVATE_KEY_LOAD_FAILED
DS_ERROR_CERTIFICATE_LOAD_FAILED = _lasso.DS_ERROR_CERTIFICATE_LOAD_FAILED
DS_ERROR_SIGNATURE_FAILED = _lasso.DS_ERROR_SIGNATURE_FAILED
DS_ERROR_SIGNATURE_NOT_FOUND = _lasso.DS_ERROR_SIGNATURE_NOT_FOUND
DS_ERROR_KEYS_MNGR_CREATION_FAILED = _lasso.DS_ERROR_KEYS_MNGR_CREATION_FAILED
DS_ERROR_KEYS_MNGR_INIT_FAILED = _lasso.DS_ERROR_KEYS_MNGR_INIT_FAILED
DS_ERROR_SIGNATURE_VERIFICATION_FAILED = _lasso.DS_ERROR_SIGNATURE_VERIFICATION_FAILED
DS_ERROR_INVALID_SIGNATURE = _lasso.DS_ERROR_INVALID_SIGNATURE
SERVER_ERROR_PROVIDER_NOT_FOUND = _lasso.SERVER_ERROR_PROVIDER_NOT_FOUND
SERVER_ERROR_ADD_PROVIDER_FAILED = _lasso.SERVER_ERROR_ADD_PROVIDER_FAILED
LOGOUT_ERROR_UNSUPPORTED_PROFILE = _lasso.LOGOUT_ERROR_UNSUPPORTED_PROFILE
PROFILE_ERROR_INVALID_QUERY = _lasso.PROFILE_ERROR_INVALID_QUERY
PROFILE_ERROR_MISSING_REQUEST = _lasso.PROFILE_ERROR_MISSING_REQUEST
PARAM_ERROR_BADTYPE_OR_NULL_OBJ = _lasso.PARAM_ERROR_BADTYPE_OR_NULL_OBJ
PARAM_ERROR_INVALID_VALUE = _lasso.PARAM_ERROR_INVALID_VALUE
PARAM_ERROR_ERR_CHECK_FAILED = _lasso.PARAM_ERROR_ERR_CHECK_FAILED
ERROR_UNDEFINED = _lasso.ERROR_UNDEFINED
class Assertion(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Assertion, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Assertion, name)
    def __repr__(self):
        return "<C LassoAssertion instance at %s>" % (self.this,)
    def __init__(self, *args):
        _swig_setattr(self, Assertion, 'this', _lasso.new_Assertion(*args))
        _swig_setattr(self, Assertion, 'thisown', 1)
    def __del__(self, destroy=_lasso.delete_Assertion):
        try:
            if self.thisown: destroy(self)
        except: pass
    def dump(*args): return _lasso.Assertion_dump(*args)

class AssertionPtr(Assertion):
    def __init__(self, this):
        _swig_setattr(self, Assertion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Assertion, 'thisown', 0)
        _swig_setattr(self, Assertion,self.__class__,Assertion)
_lasso.Assertion_swigregister(AssertionPtr)

class AuthnRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, AuthnRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, AuthnRequest, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<C LassoAuthnRequest instance at %s>" % (self.this,)
    __swig_setmethods__["affiliationId"] = _lasso.AuthnRequest_affiliationId_set
    __swig_getmethods__["affiliationId"] = _lasso.AuthnRequest_affiliationId_get
    if _newclass:affiliationId = property(_lasso.AuthnRequest_affiliationId_get, _lasso.AuthnRequest_affiliationId_set)
    __swig_setmethods__["assertionConsumerServiceId"] = _lasso.AuthnRequest_assertionConsumerServiceId_set
    __swig_getmethods__["assertionConsumerServiceId"] = _lasso.AuthnRequest_assertionConsumerServiceId_get
    if _newclass:assertionConsumerServiceId = property(_lasso.AuthnRequest_assertionConsumerServiceId_get, _lasso.AuthnRequest_assertionConsumerServiceId_set)
    __swig_setmethods__["consent"] = _lasso.AuthnRequest_consent_set
    __swig_getmethods__["consent"] = _lasso.AuthnRequest_consent_get
    if _newclass:consent = property(_lasso.AuthnRequest_consent_get, _lasso.AuthnRequest_consent_set)
    __swig_setmethods__["forceAuthn"] = _lasso.AuthnRequest_forceAuthn_set
    __swig_getmethods__["forceAuthn"] = _lasso.AuthnRequest_forceAuthn_get
    if _newclass:forceAuthn = property(_lasso.AuthnRequest_forceAuthn_get, _lasso.AuthnRequest_forceAuthn_set)
    __swig_setmethods__["isPassive"] = _lasso.AuthnRequest_isPassive_set
    __swig_getmethods__["isPassive"] = _lasso.AuthnRequest_isPassive_get
    if _newclass:isPassive = property(_lasso.AuthnRequest_isPassive_get, _lasso.AuthnRequest_isPassive_set)
    __swig_setmethods__["nameIdPolicy"] = _lasso.AuthnRequest_nameIdPolicy_set
    __swig_getmethods__["nameIdPolicy"] = _lasso.AuthnRequest_nameIdPolicy_get
    if _newclass:nameIdPolicy = property(_lasso.AuthnRequest_nameIdPolicy_get, _lasso.AuthnRequest_nameIdPolicy_set)
    __swig_setmethods__["protocolProfile"] = _lasso.AuthnRequest_protocolProfile_set
    __swig_getmethods__["protocolProfile"] = _lasso.AuthnRequest_protocolProfile_get
    if _newclass:protocolProfile = property(_lasso.AuthnRequest_protocolProfile_get, _lasso.AuthnRequest_protocolProfile_set)
    __swig_setmethods__["providerId"] = _lasso.AuthnRequest_providerId_set
    __swig_getmethods__["providerId"] = _lasso.AuthnRequest_providerId_get
    if _newclass:providerId = property(_lasso.AuthnRequest_providerId_get, _lasso.AuthnRequest_providerId_set)
    __swig_setmethods__["relayState"] = _lasso.AuthnRequest_relayState_set
    __swig_getmethods__["relayState"] = _lasso.AuthnRequest_relayState_get
    if _newclass:relayState = property(_lasso.AuthnRequest_relayState_get, _lasso.AuthnRequest_relayState_set)

class AuthnRequestPtr(AuthnRequest):
    def __init__(self, this):
        _swig_setattr(self, AuthnRequest, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, AuthnRequest, 'thisown', 0)
        _swig_setattr(self, AuthnRequest,self.__class__,AuthnRequest)
_lasso.AuthnRequest_swigregister(AuthnRequestPtr)

class AuthnResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, AuthnResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, AuthnResponse, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<C LassoAuthnResponse instance at %s>" % (self.this,)

class AuthnResponsePtr(AuthnResponse):
    def __init__(self, this):
        _swig_setattr(self, AuthnResponse, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, AuthnResponse, 'thisown', 0)
        _swig_setattr(self, AuthnResponse,self.__class__,AuthnResponse)
_lasso.AuthnResponse_swigregister(AuthnResponsePtr)

class FederationTerminationNotification(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, FederationTerminationNotification, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, FederationTerminationNotification, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<C LassoFederationTerminationNotification instance at %s>" % (self.this,)

class FederationTerminationNotificationPtr(FederationTerminationNotification):
    def __init__(self, this):
        _swig_setattr(self, FederationTerminationNotification, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, FederationTerminationNotification, 'thisown', 0)
        _swig_setattr(self, FederationTerminationNotification,self.__class__,FederationTerminationNotification)
_lasso.FederationTerminationNotification_swigregister(FederationTerminationNotificationPtr)

class LogoutRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LogoutRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LogoutRequest, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<C LassoLogoutRequest instance at %s>" % (self.this,)
    __swig_setmethods__["relayState"] = _lasso.LogoutRequest_relayState_set
    __swig_getmethods__["relayState"] = _lasso.LogoutRequest_relayState_get
    if _newclass:relayState = property(_lasso.LogoutRequest_relayState_get, _lasso.LogoutRequest_relayState_set)

class LogoutRequestPtr(LogoutRequest):
    def __init__(self, this):
        _swig_setattr(self, LogoutRequest, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, LogoutRequest, 'thisown', 0)
        _swig_setattr(self, LogoutRequest,self.__class__,LogoutRequest)
_lasso.LogoutRequest_swigregister(LogoutRequestPtr)

class LogoutResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LogoutResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LogoutResponse, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<C LassoLogoutResponse instance at %s>" % (self.this,)

class LogoutResponsePtr(LogoutResponse):
    def __init__(self, this):
        _swig_setattr(self, LogoutResponse, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, LogoutResponse, 'thisown', 0)
        _swig_setattr(self, LogoutResponse,self.__class__,LogoutResponse)
_lasso.LogoutResponse_swigregister(LogoutResponsePtr)

class Request(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Request, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Request, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<C LassoRequest instance at %s>" % (self.this,)

class RequestPtr(Request):
    def __init__(self, this):
        _swig_setattr(self, Request, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Request, 'thisown', 0)
        _swig_setattr(self, Request,self.__class__,Request)
_lasso.Request_swigregister(RequestPtr)

class Response(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Response, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Response, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<C LassoResponse instance at %s>" % (self.this,)

class ResponsePtr(Response):
    def __init__(self, this):
        _swig_setattr(self, Response, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Response, 'thisown', 0)
        _swig_setattr(self, Response,self.__class__,Response)
_lasso.Response_swigregister(ResponsePtr)

class Server(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Server, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Server, name)
    def __repr__(self):
        return "<C LassoServer instance at %s>" % (self.this,)
    __swig_getmethods__["providerId"] = _lasso.Server_providerId_get
    if _newclass:providerId = property(_lasso.Server_providerId_get)
    def __init__(self, *args):
        _swig_setattr(self, Server, 'this', _lasso.new_Server(*args))
        _swig_setattr(self, Server, 'thisown', 1)
    def __del__(self, destroy=_lasso.delete_Server):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Server_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Server_newFromDump)
    def addProvider(*args): return _lasso.Server_addProvider(*args)
    def dump(*args): return _lasso.Server_dump(*args)

class ServerPtr(Server):
    def __init__(self, this):
        _swig_setattr(self, Server, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Server, 'thisown', 0)
        _swig_setattr(self, Server,self.__class__,Server)
_lasso.Server_swigregister(ServerPtr)

Server_newFromDump = _lasso.Server_newFromDump

class Identity(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Identity, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Identity, name)
    def __repr__(self):
        return "<C LassoIdentity instance at %s>" % (self.this,)
    __swig_getmethods__["isDirty"] = _lasso.Identity_isDirty_get
    if _newclass:isDirty = property(_lasso.Identity_isDirty_get)
    def __init__(self, *args):
        _swig_setattr(self, Identity, 'this', _lasso.new_Identity(*args))
        _swig_setattr(self, Identity, 'thisown', 1)
    def __del__(self, destroy=_lasso.delete_Identity):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Identity_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Identity_newFromDump)
    def dump(*args): return _lasso.Identity_dump(*args)

class IdentityPtr(Identity):
    def __init__(self, this):
        _swig_setattr(self, Identity, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Identity, 'thisown', 0)
        _swig_setattr(self, Identity,self.__class__,Identity)
_lasso.Identity_swigregister(IdentityPtr)

Identity_newFromDump = _lasso.Identity_newFromDump

class Session(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Session, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Session, name)
    def __repr__(self):
        return "<C LassoSession instance at %s>" % (self.this,)
    __swig_getmethods__["isDirty"] = _lasso.Session_isDirty_get
    if _newclass:isDirty = property(_lasso.Session_isDirty_get)
    def __init__(self, *args):
        _swig_setattr(self, Session, 'this', _lasso.new_Session(*args))
        _swig_setattr(self, Session, 'thisown', 1)
    def __del__(self, destroy=_lasso.delete_Session):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Session_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Session_newFromDump)
    def dump(*args): return _lasso.Session_dump(*args)
    def getAuthenticationMethod(*args): return _lasso.Session_getAuthenticationMethod(*args)

class SessionPtr(Session):
    def __init__(self, this):
        _swig_setattr(self, Session, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Session, 'thisown', 0)
        _swig_setattr(self, Session,self.__class__,Session)
_lasso.Session_swigregister(SessionPtr)

Session_newFromDump = _lasso.Session_newFromDump


getRequestTypeFromSoapMsg = _lasso.getRequestTypeFromSoapMsg
class Defederation(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Defederation, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Defederation, name)
    def __repr__(self):
        return "<C LassoDefederation instance at %s>" % (self.this,)
    __swig_setmethods__["identity"] = _lasso.Defederation_identity_set
    __swig_getmethods__["identity"] = _lasso.Defederation_identity_get
    if _newclass:identity = property(_lasso.Defederation_identity_get, _lasso.Defederation_identity_set)
    __swig_getmethods__["isIdentityDirty"] = _lasso.Defederation_isIdentityDirty_get
    if _newclass:isIdentityDirty = property(_lasso.Defederation_isIdentityDirty_get)
    __swig_getmethods__["isSessionDirty"] = _lasso.Defederation_isSessionDirty_get
    if _newclass:isSessionDirty = property(_lasso.Defederation_isSessionDirty_get)
    __swig_getmethods__["msgBody"] = _lasso.Defederation_msgBody_get
    if _newclass:msgBody = property(_lasso.Defederation_msgBody_get)
    __swig_getmethods__["msgRelayState"] = _lasso.Defederation_msgRelayState_get
    if _newclass:msgRelayState = property(_lasso.Defederation_msgRelayState_get)
    __swig_getmethods__["msgUrl"] = _lasso.Defederation_msgUrl_get
    if _newclass:msgUrl = property(_lasso.Defederation_msgUrl_get)
    __swig_getmethods__["nameIdentifier"] = _lasso.Defederation_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.Defederation_nameIdentifier_get)
    __swig_setmethods__["remoteProviderId"] = _lasso.Defederation_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.Defederation_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.Defederation_remoteProviderId_get, _lasso.Defederation_remoteProviderId_set)
    __swig_getmethods__["request"] = _lasso.Defederation_request_get
    if _newclass:request = property(_lasso.Defederation_request_get)
    __swig_setmethods__["session"] = _lasso.Defederation_session_set
    __swig_getmethods__["session"] = _lasso.Defederation_session_get
    if _newclass:session = property(_lasso.Defederation_session_get, _lasso.Defederation_session_set)
    def __init__(self, *args):
        _swig_setattr(self, Defederation, 'this', _lasso.new_Defederation(*args))
        _swig_setattr(self, Defederation, 'thisown', 1)
    def __del__(self, destroy=_lasso.delete_Defederation):
        try:
            if self.thisown: destroy(self)
        except: pass
    def setIdentityFromDump(*args): return _lasso.Defederation_setIdentityFromDump(*args)
    def setSessionFromDump(*args): return _lasso.Defederation_setSessionFromDump(*args)
    def buildNotificationMsg(*args): return _lasso.Defederation_buildNotificationMsg(*args)
    def initNotification(*args): return _lasso.Defederation_initNotification(*args)
    def processNotificationMsg(*args): return _lasso.Defederation_processNotificationMsg(*args)
    def validateNotification(*args): return _lasso.Defederation_validateNotification(*args)

class DefederationPtr(Defederation):
    def __init__(self, this):
        _swig_setattr(self, Defederation, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Defederation, 'thisown', 0)
        _swig_setattr(self, Defederation,self.__class__,Defederation)
_lasso.Defederation_swigregister(DefederationPtr)

class Login(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Login, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Login, name)
    def __repr__(self):
        return "<C LassoLogin instance at %s>" % (self.this,)
    __swig_getmethods__["assertionArtifact"] = _lasso.Login_assertionArtifact_get
    if _newclass:assertionArtifact = property(_lasso.Login_assertionArtifact_get)
    __swig_getmethods__["protocolProfile"] = _lasso.Login_protocolProfile_get
    if _newclass:protocolProfile = property(_lasso.Login_protocolProfile_get)
    __swig_getmethods__["authnRequest"] = _lasso.Login_authnRequest_get
    if _newclass:authnRequest = property(_lasso.Login_authnRequest_get)
    __swig_getmethods__["authnResponse"] = _lasso.Login_authnResponse_get
    if _newclass:authnResponse = property(_lasso.Login_authnResponse_get)
    __swig_setmethods__["identity"] = _lasso.Login_identity_set
    __swig_getmethods__["identity"] = _lasso.Login_identity_get
    if _newclass:identity = property(_lasso.Login_identity_get, _lasso.Login_identity_set)
    __swig_getmethods__["isIdentityDirty"] = _lasso.Login_isIdentityDirty_get
    if _newclass:isIdentityDirty = property(_lasso.Login_isIdentityDirty_get)
    __swig_getmethods__["isSessionDirty"] = _lasso.Login_isSessionDirty_get
    if _newclass:isSessionDirty = property(_lasso.Login_isSessionDirty_get)
    __swig_getmethods__["msgBody"] = _lasso.Login_msgBody_get
    if _newclass:msgBody = property(_lasso.Login_msgBody_get)
    __swig_getmethods__["msgRelayState"] = _lasso.Login_msgRelayState_get
    if _newclass:msgRelayState = property(_lasso.Login_msgRelayState_get)
    __swig_getmethods__["msgUrl"] = _lasso.Login_msgUrl_get
    if _newclass:msgUrl = property(_lasso.Login_msgUrl_get)
    __swig_getmethods__["nameIdentifier"] = _lasso.Login_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.Login_nameIdentifier_get)
    __swig_setmethods__["remoteProviderId"] = _lasso.Login_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.Login_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.Login_remoteProviderId_get, _lasso.Login_remoteProviderId_set)
    __swig_getmethods__["request"] = _lasso.Login_request_get
    if _newclass:request = property(_lasso.Login_request_get)
    __swig_getmethods__["response"] = _lasso.Login_response_get
    if _newclass:response = property(_lasso.Login_response_get)
    __swig_setmethods__["responseStatus"] = _lasso.Login_responseStatus_set
    __swig_getmethods__["responseStatus"] = _lasso.Login_responseStatus_get
    if _newclass:responseStatus = property(_lasso.Login_responseStatus_get, _lasso.Login_responseStatus_set)
    __swig_setmethods__["session"] = _lasso.Login_session_set
    __swig_getmethods__["session"] = _lasso.Login_session_get
    if _newclass:session = property(_lasso.Login_session_get, _lasso.Login_session_set)
    __swig_setmethods__["assertion"] = _lasso.Login_assertion_set
    __swig_getmethods__["assertion"] = _lasso.Login_assertion_get
    if _newclass:assertion = property(_lasso.Login_assertion_get, _lasso.Login_assertion_set)
    def __init__(self, *args):
        _swig_setattr(self, Login, 'this', _lasso.new_Login(*args))
        _swig_setattr(self, Login, 'thisown', 1)
    def __del__(self, destroy=_lasso.delete_Login):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Login_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Login_newFromDump)
    def setAssertionFromDump(*args): return _lasso.Login_setAssertionFromDump(*args)
    def setIdentityFromDump(*args): return _lasso.Login_setIdentityFromDump(*args)
    def setSessionFromDump(*args): return _lasso.Login_setSessionFromDump(*args)
    def acceptSso(*args): return _lasso.Login_acceptSso(*args)
    def buildArtifactMsg(*args): return _lasso.Login_buildArtifactMsg(*args)
    def buildAuthnRequestMsg(*args): return _lasso.Login_buildAuthnRequestMsg(*args)
    def buildAuthnResponseMsg(*args): return _lasso.Login_buildAuthnResponseMsg(*args)
    def buildRequestMsg(*args): return _lasso.Login_buildRequestMsg(*args)
    def buildResponseMsg(*args): return _lasso.Login_buildResponseMsg(*args)
    def dump(*args): return _lasso.Login_dump(*args)
    def initAuthnRequest(*args): return _lasso.Login_initAuthnRequest(*args)
    def initFromAuthnRequestMsg(*args): return _lasso.Login_initFromAuthnRequestMsg(*args)
    def initRequest(*args): return _lasso.Login_initRequest(*args)
    def mustAuthenticate(*args): return _lasso.Login_mustAuthenticate(*args)
    def processAuthnResponseMsg(*args): return _lasso.Login_processAuthnResponseMsg(*args)
    def processRequestMsg(*args): return _lasso.Login_processRequestMsg(*args)
    def processResponseMsg(*args): return _lasso.Login_processResponseMsg(*args)

class LoginPtr(Login):
    def __init__(self, this):
        _swig_setattr(self, Login, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Login, 'thisown', 0)
        _swig_setattr(self, Login,self.__class__,Login)
_lasso.Login_swigregister(LoginPtr)

Login_newFromDump = _lasso.Login_newFromDump

class Logout(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Logout, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Logout, name)
    def __repr__(self):
        return "<C LassoLogout instance at %s>" % (self.this,)
    __swig_setmethods__["identity"] = _lasso.Logout_identity_set
    __swig_getmethods__["identity"] = _lasso.Logout_identity_get
    if _newclass:identity = property(_lasso.Logout_identity_get, _lasso.Logout_identity_set)
    __swig_getmethods__["isIdentityDirty"] = _lasso.Logout_isIdentityDirty_get
    if _newclass:isIdentityDirty = property(_lasso.Logout_isIdentityDirty_get)
    __swig_getmethods__["isSessionDirty"] = _lasso.Logout_isSessionDirty_get
    if _newclass:isSessionDirty = property(_lasso.Logout_isSessionDirty_get)
    __swig_getmethods__["msgBody"] = _lasso.Logout_msgBody_get
    if _newclass:msgBody = property(_lasso.Logout_msgBody_get)
    __swig_getmethods__["msgRelayState"] = _lasso.Logout_msgRelayState_get
    if _newclass:msgRelayState = property(_lasso.Logout_msgRelayState_get)
    __swig_getmethods__["msgUrl"] = _lasso.Logout_msgUrl_get
    if _newclass:msgUrl = property(_lasso.Logout_msgUrl_get)
    __swig_getmethods__["nameIdentifier"] = _lasso.Logout_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.Logout_nameIdentifier_get)
    __swig_setmethods__["remoteProviderId"] = _lasso.Logout_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.Logout_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.Logout_remoteProviderId_get, _lasso.Logout_remoteProviderId_set)
    __swig_getmethods__["request"] = _lasso.Logout_request_get
    if _newclass:request = property(_lasso.Logout_request_get)
    __swig_getmethods__["response"] = _lasso.Logout_response_get
    if _newclass:response = property(_lasso.Logout_response_get)
    __swig_setmethods__["responseStatus"] = _lasso.Logout_responseStatus_set
    __swig_getmethods__["responseStatus"] = _lasso.Logout_responseStatus_get
    if _newclass:responseStatus = property(_lasso.Logout_responseStatus_get, _lasso.Logout_responseStatus_set)
    __swig_setmethods__["session"] = _lasso.Logout_session_set
    __swig_getmethods__["session"] = _lasso.Logout_session_get
    if _newclass:session = property(_lasso.Logout_session_get, _lasso.Logout_session_set)
    def __init__(self, *args):
        _swig_setattr(self, Logout, 'this', _lasso.new_Logout(*args))
        _swig_setattr(self, Logout, 'thisown', 1)
    def __del__(self, destroy=_lasso.delete_Logout):
        try:
            if self.thisown: destroy(self)
        except: pass
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Logout_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Logout_newFromDump)
    def setIdentityFromDump(*args): return _lasso.Logout_setIdentityFromDump(*args)
    def setSessionFromDump(*args): return _lasso.Logout_setSessionFromDump(*args)
    def buildRequestMsg(*args): return _lasso.Logout_buildRequestMsg(*args)
    def buildResponseMsg(*args): return _lasso.Logout_buildResponseMsg(*args)
    def dump(*args): return _lasso.Logout_dump(*args)
    def getNextProviderId(*args): return _lasso.Logout_getNextProviderId(*args)
    def initRequest(*args): return _lasso.Logout_initRequest(*args)
    def processRequestMsg(*args): return _lasso.Logout_processRequestMsg(*args)
    def processResponseMsg(*args): return _lasso.Logout_processResponseMsg(*args)
    def resetProviderIdIndex(*args): return _lasso.Logout_resetProviderIdIndex(*args)
    def validateRequest(*args): return _lasso.Logout_validateRequest(*args)

class LogoutPtr(Logout):
    def __init__(self, this):
        _swig_setattr(self, Logout, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Logout, 'thisown', 0)
        _swig_setattr(self, Logout,self.__class__,Logout)
_lasso.Logout_swigregister(LogoutPtr)

Logout_newFromDump = _lasso.Logout_newFromDump

class Lecp(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Lecp, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Lecp, name)
    def __repr__(self):
        return "<C LassoLecp instance at %s>" % (self.this,)
    __swig_getmethods__["authnRequest"] = _lasso.Lecp_authnRequest_get
    if _newclass:authnRequest = property(_lasso.Lecp_authnRequest_get)
    __swig_getmethods__["authnResponse"] = _lasso.Lecp_authnResponse_get
    if _newclass:authnResponse = property(_lasso.Lecp_authnResponse_get)
    __swig_setmethods__["identity"] = _lasso.Lecp_identity_set
    __swig_getmethods__["identity"] = _lasso.Lecp_identity_get
    if _newclass:identity = property(_lasso.Lecp_identity_get, _lasso.Lecp_identity_set)
    __swig_getmethods__["isIdentityDirty"] = _lasso.Lecp_isIdentityDirty_get
    if _newclass:isIdentityDirty = property(_lasso.Lecp_isIdentityDirty_get)
    __swig_getmethods__["isSessionDirty"] = _lasso.Lecp_isSessionDirty_get
    if _newclass:isSessionDirty = property(_lasso.Lecp_isSessionDirty_get)
    __swig_getmethods__["msgBody"] = _lasso.Lecp_msgBody_get
    if _newclass:msgBody = property(_lasso.Lecp_msgBody_get)
    __swig_getmethods__["msgRelayState"] = _lasso.Lecp_msgRelayState_get
    if _newclass:msgRelayState = property(_lasso.Lecp_msgRelayState_get)
    __swig_getmethods__["msgUrl"] = _lasso.Lecp_msgUrl_get
    if _newclass:msgUrl = property(_lasso.Lecp_msgUrl_get)
    __swig_getmethods__["nameIdentifier"] = _lasso.Lecp_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.Lecp_nameIdentifier_get)
    __swig_setmethods__["remoteProviderId"] = _lasso.Lecp_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.Lecp_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.Lecp_remoteProviderId_get, _lasso.Lecp_remoteProviderId_set)
    __swig_getmethods__["request"] = _lasso.Lecp_request_get
    if _newclass:request = property(_lasso.Lecp_request_get)
    __swig_getmethods__["response"] = _lasso.Lecp_response_get
    if _newclass:response = property(_lasso.Lecp_response_get)
    __swig_setmethods__["responseStatus"] = _lasso.Lecp_responseStatus_set
    __swig_getmethods__["responseStatus"] = _lasso.Lecp_responseStatus_get
    if _newclass:responseStatus = property(_lasso.Lecp_responseStatus_get, _lasso.Lecp_responseStatus_set)
    __swig_setmethods__["session"] = _lasso.Lecp_session_set
    __swig_getmethods__["session"] = _lasso.Lecp_session_get
    if _newclass:session = property(_lasso.Lecp_session_get, _lasso.Lecp_session_set)
    def __init__(self, *args):
        _swig_setattr(self, Lecp, 'this', _lasso.new_Lecp(*args))
        _swig_setattr(self, Lecp, 'thisown', 1)
    def __del__(self, destroy=_lasso.delete_Lecp):
        try:
            if self.thisown: destroy(self)
        except: pass
    def setIdentityFromDump(*args): return _lasso.Lecp_setIdentityFromDump(*args)
    def setSessionFromDump(*args): return _lasso.Lecp_setSessionFromDump(*args)
    def buildAuthnRequestEnvelopeMsg(*args): return _lasso.Lecp_buildAuthnRequestEnvelopeMsg(*args)
    def buildAuthnRequestMsg(*args): return _lasso.Lecp_buildAuthnRequestMsg(*args)
    def buildAuthnResponseEnvelopeMsg(*args): return _lasso.Lecp_buildAuthnResponseEnvelopeMsg(*args)
    def buildAuthnResponseMsg(*args): return _lasso.Lecp_buildAuthnResponseMsg(*args)
    def initAuthnRequest(*args): return _lasso.Lecp_initAuthnRequest(*args)
    def initFromAuthnRequestMsg(*args): return _lasso.Lecp_initFromAuthnRequestMsg(*args)
    def processAuthnRequestEnvelopeMsg(*args): return _lasso.Lecp_processAuthnRequestEnvelopeMsg(*args)
    def processAuthnResponseEnvelopeMsg(*args): return _lasso.Lecp_processAuthnResponseEnvelopeMsg(*args)

class LecpPtr(Lecp):
    def __init__(self, this):
        _swig_setattr(self, Lecp, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Lecp, 'thisown', 0)
        _swig_setattr(self, Lecp,self.__class__,Lecp)
_lasso.Lecp_swigregister(LecpPtr)


