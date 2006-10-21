# This file was created automatically by SWIG 1.3.28.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _lasso
import new
new_instancemethod = new.instancemethod
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
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


WSF_SUPPORT = _lasso.WSF_SUPPORT
SAML2_SUPPORT = _lasso.SAML2_SUPPORT
SAML2_NAME_IDENTIFIER_FORMAT_PERSISTENT = _lasso.SAML2_NAME_IDENTIFIER_FORMAT_PERSISTENT
SAML2_NAME_IDENTIFIER_FORMAT_TRANSIENT = _lasso.SAML2_NAME_IDENTIFIER_FORMAT_TRANSIENT
Error = _lasso.Error
Warning = _lasso.Warning

HTTP_METHOD_NONE = _lasso.HTTP_METHOD_NONE
HTTP_METHOD_ANY = _lasso.HTTP_METHOD_ANY
HTTP_METHOD_IDP_INITIATED = _lasso.HTTP_METHOD_IDP_INITIATED
HTTP_METHOD_GET = _lasso.HTTP_METHOD_GET
HTTP_METHOD_POST = _lasso.HTTP_METHOD_POST
HTTP_METHOD_REDIRECT = _lasso.HTTP_METHOD_REDIRECT
HTTP_METHOD_SOAP = _lasso.HTTP_METHOD_SOAP
HTTP_METHOD_ARTIFACT_GET = _lasso.HTTP_METHOD_ARTIFACT_GET
HTTP_METHOD_ARTIFACT_POST = _lasso.HTTP_METHOD_ARTIFACT_POST
MD_PROTOCOL_TYPE_FEDERATION_TERMINATION = _lasso.MD_PROTOCOL_TYPE_FEDERATION_TERMINATION
MD_PROTOCOL_TYPE_NAME_IDENTIFIER_MAPPING = _lasso.MD_PROTOCOL_TYPE_NAME_IDENTIFIER_MAPPING
MD_PROTOCOL_TYPE_REGISTER_NAME_IDENTIFIER = _lasso.MD_PROTOCOL_TYPE_REGISTER_NAME_IDENTIFIER
MD_PROTOCOL_TYPE_SINGLE_LOGOUT = _lasso.MD_PROTOCOL_TYPE_SINGLE_LOGOUT
MD_PROTOCOL_TYPE_SINGLE_SIGN_ON = _lasso.MD_PROTOCOL_TYPE_SINGLE_SIGN_ON
MD_PROTOCOL_TYPE_ARTIFACT_RESOLUTION = _lasso.MD_PROTOCOL_TYPE_ARTIFACT_RESOLUTION
MD_PROTOCOL_TYPE_MANAGE_NAME_ID = _lasso.MD_PROTOCOL_TYPE_MANAGE_NAME_ID
LASSO_MD_PROTOCOL_TYPE_ASSERTION_ID_REQUEST = _lasso.LASSO_MD_PROTOCOL_TYPE_ASSERTION_ID_REQUEST
LIB_CONSENT_OBTAINED = _lasso.LIB_CONSENT_OBTAINED
LIB_CONSENT_OBTAINED_PRIOR = _lasso.LIB_CONSENT_OBTAINED_PRIOR
LIB_CONSENT_OBTAINED_CURRENT_IMPLICIT = _lasso.LIB_CONSENT_OBTAINED_CURRENT_IMPLICIT
LIB_CONSENT_OBTAINED_CURRENT_EXPLICIT = _lasso.LIB_CONSENT_OBTAINED_CURRENT_EXPLICIT
LIB_CONSENT_UNAVAILABLE = _lasso.LIB_CONSENT_UNAVAILABLE
LIB_CONSENT_INAPPLICABLE = _lasso.LIB_CONSENT_INAPPLICABLE
LIB_NAMEID_POLICY_TYPE_NONE = _lasso.LIB_NAMEID_POLICY_TYPE_NONE
LIB_NAMEID_POLICY_TYPE_ONE_TIME = _lasso.LIB_NAMEID_POLICY_TYPE_ONE_TIME
LIB_NAMEID_POLICY_TYPE_FEDERATED = _lasso.LIB_NAMEID_POLICY_TYPE_FEDERATED
LIB_NAMEID_POLICY_TYPE_ANY = _lasso.LIB_NAMEID_POLICY_TYPE_ANY
LIB_PROTOCOL_PROFILE_BRWS_ART = _lasso.LIB_PROTOCOL_PROFILE_BRWS_ART
LIB_PROTOCOL_PROFILE_BRWS_POST = _lasso.LIB_PROTOCOL_PROFILE_BRWS_POST
LIB_PROTOCOL_PROFILE_BRWS_LECP = _lasso.LIB_PROTOCOL_PROFILE_BRWS_LECP
LIB_PROTOCOL_PROFILE_FED_TERM_IDP_HTTP = _lasso.LIB_PROTOCOL_PROFILE_FED_TERM_IDP_HTTP
LIB_PROTOCOL_PROFILE_FED_TERM_IDP_SOAP = _lasso.LIB_PROTOCOL_PROFILE_FED_TERM_IDP_SOAP
LIB_PROTOCOL_PROFILE_FED_TERM_SP_HTTP = _lasso.LIB_PROTOCOL_PROFILE_FED_TERM_SP_HTTP
LIB_PROTOCOL_PROFILE_FED_TERM_SP_SOAP = _lasso.LIB_PROTOCOL_PROFILE_FED_TERM_SP_SOAP
LIB_PROTOCOL_PROFILE_RNI_IDP_HTTP = _lasso.LIB_PROTOCOL_PROFILE_RNI_IDP_HTTP
LIB_PROTOCOL_PROFILE_RNI_IDP_SOAP = _lasso.LIB_PROTOCOL_PROFILE_RNI_IDP_SOAP
LIB_PROTOCOL_PROFILE_RNI_SP_HTTP = _lasso.LIB_PROTOCOL_PROFILE_RNI_SP_HTTP
LIB_PROTOCOL_PROFILE_RNI_SP_SOAP = _lasso.LIB_PROTOCOL_PROFILE_RNI_SP_SOAP
LIB_PROTOCOL_PROFILE_SLO_IDP_HTTP = _lasso.LIB_PROTOCOL_PROFILE_SLO_IDP_HTTP
LIB_PROTOCOL_PROFILE_SLO_IDP_SOAP = _lasso.LIB_PROTOCOL_PROFILE_SLO_IDP_SOAP
LIB_PROTOCOL_PROFILE_SLO_SP_HTTP = _lasso.LIB_PROTOCOL_PROFILE_SLO_SP_HTTP
LIB_PROTOCOL_PROFILE_SLO_SP_SOAP = _lasso.LIB_PROTOCOL_PROFILE_SLO_SP_SOAP
LOGIN_PROTOCOL_PROFILE_BRWS_ART = _lasso.LOGIN_PROTOCOL_PROFILE_BRWS_ART
LOGIN_PROTOCOL_PROFILE_BRWS_POST = _lasso.LOGIN_PROTOCOL_PROFILE_BRWS_POST
LOGIN_PROTOCOL_PROFILE_BRWS_LECP = _lasso.LOGIN_PROTOCOL_PROFILE_BRWS_LECP
PROVIDER_ROLE_NONE = _lasso.PROVIDER_ROLE_NONE
PROVIDER_ROLE_SP = _lasso.PROVIDER_ROLE_SP
PROVIDER_ROLE_IDP = _lasso.PROVIDER_ROLE_IDP
PROTOCOL_LIBERTY_1_0 = _lasso.PROTOCOL_LIBERTY_1_0
PROTOCOL_LIBERTY_1_1 = _lasso.PROTOCOL_LIBERTY_1_1
PROTOCOL_LIBERTY_1_2 = _lasso.PROTOCOL_LIBERTY_1_2
PROTOCOL_SAML_2_0 = _lasso.PROTOCOL_SAML_2_0
REQUEST_TYPE_INVALID = _lasso.REQUEST_TYPE_INVALID
REQUEST_TYPE_LOGIN = _lasso.REQUEST_TYPE_LOGIN
REQUEST_TYPE_LOGOUT = _lasso.REQUEST_TYPE_LOGOUT
REQUEST_TYPE_DEFEDERATION = _lasso.REQUEST_TYPE_DEFEDERATION
REQUEST_TYPE_NAME_REGISTRATION = _lasso.REQUEST_TYPE_NAME_REGISTRATION
REQUEST_TYPE_NAME_IDENTIFIER_MAPPING = _lasso.REQUEST_TYPE_NAME_IDENTIFIER_MAPPING
REQUEST_TYPE_LECP = _lasso.REQUEST_TYPE_LECP
REQUEST_TYPE_DISCO_QUERY = _lasso.REQUEST_TYPE_DISCO_QUERY
REQUEST_TYPE_DISCO_MODIFY = _lasso.REQUEST_TYPE_DISCO_MODIFY
REQUEST_TYPE_DST_QUERY = _lasso.REQUEST_TYPE_DST_QUERY
REQUEST_TYPE_DST_MODIFY = _lasso.REQUEST_TYPE_DST_MODIFY
REQUEST_TYPE_SASL_REQUEST = _lasso.REQUEST_TYPE_SASL_REQUEST
LIB_AUTHN_CONTEXT_CLASS_REF_INTERNET_PROTOCOL = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_INTERNET_PROTOCOL
LIB_AUTHN_CONTEXT_CLASS_REF_INTERNET_PROTOCOL_PASSWORD = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_INTERNET_PROTOCOL_PASSWORD
LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_ONE_FACTOR_UNREGISTERED = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_ONE_FACTOR_UNREGISTERED
LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_TWO_FACTOR_UNREGISTERED = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_TWO_FACTOR_UNREGISTERED
LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_ONE_FACTOR_CONTRACT = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_ONE_FACTOR_CONTRACT
LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_TWO_FACTOR_CONTRACT = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_MOBILE_TWO_FACTOR_CONTRACT
LIB_AUTHN_CONTEXT_CLASS_REF_PASSWORD = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_PASSWORD
LIB_AUTHN_CONTEXT_CLASS_REF_PASSWORD_PROTECTED_TRANSPORT = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_PASSWORD_PROTECTED_TRANSPORT
LIB_AUTHN_CONTEXT_CLASS_REF_PREVIOUS_SESSION = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_PREVIOUS_SESSION
LIB_AUTHN_CONTEXT_CLASS_REF_SMARTCARD = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_SMARTCARD
LIB_AUTHN_CONTEXT_CLASS_REF_SMARTCARD_PKI = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_SMARTCARD_PKI
LIB_AUTHN_CONTEXT_CLASS_REF_SOFTWARE_PKI = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_SOFTWARE_PKI
LIB_AUTHN_CONTEXT_CLASS_REF_TIME_SYNC_TOKEN = _lasso.LIB_AUTHN_CONTEXT_CLASS_REF_TIME_SYNC_TOKEN
LIB_AUTHN_CONTEXT_COMPARISON_EXACT = _lasso.LIB_AUTHN_CONTEXT_COMPARISON_EXACT
LIB_AUTHN_CONTEXT_COMPARISON_MINIMUM = _lasso.LIB_AUTHN_CONTEXT_COMPARISON_MINIMUM
LIB_AUTHN_CONTEXT_COMPARISON_MAXIMUM = _lasso.LIB_AUTHN_CONTEXT_COMPARISON_MAXIMUM
LIB_AUTHN_CONTEXT_COMPARISON_BETTER = _lasso.LIB_AUTHN_CONTEXT_COMPARISON_BETTER
SAML_AUTHENTICATION_METHOD_PASSWORD = _lasso.SAML_AUTHENTICATION_METHOD_PASSWORD
SAML_AUTHENTICATION_METHOD_KERBEROS = _lasso.SAML_AUTHENTICATION_METHOD_KERBEROS
SAML_AUTHENTICATION_METHOD_SECURE_REMOTE_PASSWORD = _lasso.SAML_AUTHENTICATION_METHOD_SECURE_REMOTE_PASSWORD
SAML_AUTHENTICATION_METHOD_HARDWARE_TOKEN = _lasso.SAML_AUTHENTICATION_METHOD_HARDWARE_TOKEN
SAML_AUTHENTICATION_METHOD_SMARTCARD_PKI = _lasso.SAML_AUTHENTICATION_METHOD_SMARTCARD_PKI
SAML_AUTHENTICATION_METHOD_SOFTWARE_PKI = _lasso.SAML_AUTHENTICATION_METHOD_SOFTWARE_PKI
SAML_AUTHENTICATION_METHOD_PGP = _lasso.SAML_AUTHENTICATION_METHOD_PGP
SAML_AUTHENTICATION_METHODS_PKI = _lasso.SAML_AUTHENTICATION_METHODS_PKI
SAML_AUTHENTICATION_METHOD_XKMS = _lasso.SAML_AUTHENTICATION_METHOD_XKMS
SAML_AUTHENTICATION_METHOD_XMLD_SIG = _lasso.SAML_AUTHENTICATION_METHOD_XMLD_SIG
SAML_AUTHENTICATION_METHOD_UNSPECIFIED = _lasso.SAML_AUTHENTICATION_METHOD_UNSPECIFIED
SAML_AUTHENTICATION_METHOD_LIBERTY = _lasso.SAML_AUTHENTICATION_METHOD_LIBERTY
SIGNATURE_METHOD_RSA_SHA1 = _lasso.SIGNATURE_METHOD_RSA_SHA1
SIGNATURE_METHOD_DSA_SHA1 = _lasso.SIGNATURE_METHOD_DSA_SHA1
ERROR_UNDEFINED = _lasso.ERROR_UNDEFINED
ERROR_UNIMPLEMENTED = _lasso.ERROR_UNIMPLEMENTED
XML_ERROR_NODE_NOT_FOUND = _lasso.XML_ERROR_NODE_NOT_FOUND
XML_ERROR_NODE_CONTENT_NOT_FOUND = _lasso.XML_ERROR_NODE_CONTENT_NOT_FOUND
XML_ERROR_ATTR_NOT_FOUND = _lasso.XML_ERROR_ATTR_NOT_FOUND
XML_ERROR_ATTR_VALUE_NOT_FOUND = _lasso.XML_ERROR_ATTR_VALUE_NOT_FOUND
DS_ERROR_SIGNATURE_NOT_FOUND = _lasso.DS_ERROR_SIGNATURE_NOT_FOUND
DS_ERROR_INVALID_SIGNATURE = _lasso.DS_ERROR_INVALID_SIGNATURE
DS_ERROR_SIGNATURE_TMPL_CREATION_FAILED = _lasso.DS_ERROR_SIGNATURE_TMPL_CREATION_FAILED
DS_ERROR_CONTEXT_CREATION_FAILED = _lasso.DS_ERROR_CONTEXT_CREATION_FAILED
DS_ERROR_PUBLIC_KEY_LOAD_FAILED = _lasso.DS_ERROR_PUBLIC_KEY_LOAD_FAILED
DS_ERROR_PRIVATE_KEY_LOAD_FAILED = _lasso.DS_ERROR_PRIVATE_KEY_LOAD_FAILED
DS_ERROR_CERTIFICATE_LOAD_FAILED = _lasso.DS_ERROR_CERTIFICATE_LOAD_FAILED
DS_ERROR_SIGNATURE_FAILED = _lasso.DS_ERROR_SIGNATURE_FAILED
DS_ERROR_KEYS_MNGR_CREATION_FAILED = _lasso.DS_ERROR_KEYS_MNGR_CREATION_FAILED
DS_ERROR_KEYS_MNGR_INIT_FAILED = _lasso.DS_ERROR_KEYS_MNGR_INIT_FAILED
DS_ERROR_SIGNATURE_VERIFICATION_FAILED = _lasso.DS_ERROR_SIGNATURE_VERIFICATION_FAILED
DS_ERROR_CA_CERT_CHAIN_LOAD_FAILED = _lasso.DS_ERROR_CA_CERT_CHAIN_LOAD_FAILED
DS_ERROR_INVALID_SIGALG = _lasso.DS_ERROR_INVALID_SIGALG
DS_ERROR_DIGEST_COMPUTE_FAILED = _lasso.DS_ERROR_DIGEST_COMPUTE_FAILED
LASSO_DS_ERROR_SIGNATURE_TEMPLATE_NOT_FOUND = _lasso.LASSO_DS_ERROR_SIGNATURE_TEMPLATE_NOT_FOUND
SERVER_ERROR_PROVIDER_NOT_FOUND = _lasso.SERVER_ERROR_PROVIDER_NOT_FOUND
SERVER_ERROR_ADD_PROVIDER_FAILED = _lasso.SERVER_ERROR_ADD_PROVIDER_FAILED
LASSO_SERVER_ERROR_ADD_PROVIDER_PROTOCOL_MISMATCH = _lasso.LASSO_SERVER_ERROR_ADD_PROVIDER_PROTOCOL_MISMATCH
LOGOUT_ERROR_UNSUPPORTED_PROFILE = _lasso.LOGOUT_ERROR_UNSUPPORTED_PROFILE
LOGOUT_ERROR_REQUEST_DENIED = _lasso.LOGOUT_ERROR_REQUEST_DENIED
PROFILE_ERROR_INVALID_QUERY = _lasso.PROFILE_ERROR_INVALID_QUERY
PROFILE_ERROR_INVALID_POST_MSG = _lasso.PROFILE_ERROR_INVALID_POST_MSG
PROFILE_ERROR_INVALID_SOAP_MSG = _lasso.PROFILE_ERROR_INVALID_SOAP_MSG
PROFILE_ERROR_MISSING_REQUEST = _lasso.PROFILE_ERROR_MISSING_REQUEST
PROFILE_ERROR_INVALID_HTTP_METHOD = _lasso.PROFILE_ERROR_INVALID_HTTP_METHOD
PROFILE_ERROR_INVALID_PROTOCOLPROFILE = _lasso.PROFILE_ERROR_INVALID_PROTOCOLPROFILE
PROFILE_ERROR_INVALID_MSG = _lasso.PROFILE_ERROR_INVALID_MSG
PROFILE_ERROR_MISSING_REMOTE_PROVIDERID = _lasso.PROFILE_ERROR_MISSING_REMOTE_PROVIDERID
PROFILE_ERROR_UNSUPPORTED_PROFILE = _lasso.PROFILE_ERROR_UNSUPPORTED_PROFILE
PROFILE_ERROR_UNKNOWN_PROFILE_URL = _lasso.PROFILE_ERROR_UNKNOWN_PROFILE_URL
PROFILE_ERROR_IDENTITY_NOT_FOUND = _lasso.PROFILE_ERROR_IDENTITY_NOT_FOUND
PROFILE_ERROR_FEDERATION_NOT_FOUND = _lasso.PROFILE_ERROR_FEDERATION_NOT_FOUND
PROFILE_ERROR_NAME_IDENTIFIER_NOT_FOUND = _lasso.PROFILE_ERROR_NAME_IDENTIFIER_NOT_FOUND
PROFILE_ERROR_BUILDING_QUERY_FAILED = _lasso.PROFILE_ERROR_BUILDING_QUERY_FAILED
PROFILE_ERROR_BUILDING_REQUEST_FAILED = _lasso.PROFILE_ERROR_BUILDING_REQUEST_FAILED
PROFILE_ERROR_BUILDING_MESSAGE_FAILED = _lasso.PROFILE_ERROR_BUILDING_MESSAGE_FAILED
PROFILE_ERROR_BUILDING_RESPONSE_FAILED = _lasso.PROFILE_ERROR_BUILDING_RESPONSE_FAILED
PROFILE_ERROR_SESSION_NOT_FOUND = _lasso.PROFILE_ERROR_SESSION_NOT_FOUND
PROFILE_ERROR_BAD_IDENTITY_DUMP = _lasso.PROFILE_ERROR_BAD_IDENTITY_DUMP
PROFILE_ERROR_BAD_SESSION_DUMP = _lasso.PROFILE_ERROR_BAD_SESSION_DUMP
LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ = _lasso.LASSO_PARAM_ERROR_BAD_TYPE_OR_NULL_OBJ
PARAM_ERROR_INVALID_VALUE = _lasso.PARAM_ERROR_INVALID_VALUE
LASSO_PARAM_ERROR_CHECK_FAILED = _lasso.LASSO_PARAM_ERROR_CHECK_FAILED
LOGIN_ERROR_FEDERATION_NOT_FOUND = _lasso.LOGIN_ERROR_FEDERATION_NOT_FOUND
LOGIN_ERROR_CONSENT_NOT_OBTAINED = _lasso.LOGIN_ERROR_CONSENT_NOT_OBTAINED
LOGIN_ERROR_INVALID_NAMEIDPOLICY = _lasso.LOGIN_ERROR_INVALID_NAMEIDPOLICY
LOGIN_ERROR_REQUEST_DENIED = _lasso.LOGIN_ERROR_REQUEST_DENIED
LOGIN_ERROR_INVALID_SIGNATURE = _lasso.LOGIN_ERROR_INVALID_SIGNATURE
LOGIN_ERROR_UNSIGNED_AUTHN_REQUEST = _lasso.LOGIN_ERROR_UNSIGNED_AUTHN_REQUEST
LOGIN_ERROR_STATUS_NOT_SUCCESS = _lasso.LOGIN_ERROR_STATUS_NOT_SUCCESS
LOGIN_ERROR_UNKNOWN_PRINCIPAL = _lasso.LOGIN_ERROR_UNKNOWN_PRINCIPAL
DEFEDERATION_ERROR_MISSING_NAME_IDENTIFIER = _lasso.DEFEDERATION_ERROR_MISSING_NAME_IDENTIFIER
LASSO_SOAP_FAULT_REDIRECT_REQUEST = _lasso.LASSO_SOAP_FAULT_REDIRECT_REQUEST

init = _lasso.init

shutdown = _lasso.shutdown
CHECK_VERSION_EXACT = _lasso.CHECK_VERSION_EXACT
CHECK_VERSIONABI_COMPATIBLE = _lasso.CHECK_VERSIONABI_COMPATIBLE
CHECK_VERSION_NUMERIC = _lasso.CHECK_VERSION_NUMERIC

checkVersion = _lasso.checkVersion

registerDstService = _lasso.registerDstService
class Node(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Node, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Node, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoNode instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Node(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Node
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Node_dump(*args)
_lasso.Node_swigregister(Node)

class NodeList(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, NodeList, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, NodeList, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoNodeList instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_NodeList(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_NodeList
    __del__ = lambda self : None;
    def append(*args): return _lasso.NodeList_append(*args)
    def cast(*args): return _lasso.NodeList_cast(*args)
    __swig_getmethods__["frompointer"] = lambda x: _lasso.NodeList_frompointer
    if _newclass:frompointer = staticmethod(_lasso.NodeList_frompointer)
    def __getitem__(*args): return _lasso.NodeList___getitem__(*args)
    def __len__(*args): return _lasso.NodeList___len__(*args)
    def __setitem__(*args): return _lasso.NodeList___setitem__(*args)
_lasso.NodeList_swigregister(NodeList)

NodeList_frompointer = _lasso.NodeList_frompointer

class StringList(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, StringList, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, StringList, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoStringList instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_StringList(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_StringList
    __del__ = lambda self : None;
    def append(*args): return _lasso.StringList_append(*args)
    def cast(*args): return _lasso.StringList_cast(*args)
    __swig_getmethods__["frompointer"] = lambda x: _lasso.StringList_frompointer
    if _newclass:frompointer = staticmethod(_lasso.StringList_frompointer)
    def __getitem__(*args): return _lasso.StringList___getitem__(*args)
    def __len__(*args): return _lasso.StringList___len__(*args)
    def __setitem__(*args): return _lasso.StringList___setitem__(*args)
_lasso.StringList_swigregister(StringList)

StringList_frompointer = _lasso.StringList_frompointer

class SamlAdvice(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlAdvice, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlAdvice, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlAdvice instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["assertion"] = _lasso.SamlAdvice_assertion_set
    __swig_getmethods__["assertion"] = _lasso.SamlAdvice_assertion_get
    if _newclass:assertion = property(_lasso.SamlAdvice_assertion_get, _lasso.SamlAdvice_assertion_set)
    __swig_setmethods__["assertionIdReference"] = _lasso.SamlAdvice_assertionIdReference_set
    __swig_getmethods__["assertionIdReference"] = _lasso.SamlAdvice_assertionIdReference_get
    if _newclass:assertionIdReference = property(_lasso.SamlAdvice_assertionIdReference_get, _lasso.SamlAdvice_assertionIdReference_set)
    def __init__(self, *args):
        this = _lasso.new_SamlAdvice(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlAdvice
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlAdvice_dump(*args)
_lasso.SamlAdvice_swigregister(SamlAdvice)

class SamlAssertion(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlAssertion, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlAssertion, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlAssertion instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["assertionId"] = _lasso.SamlAssertion_assertionId_set
    __swig_getmethods__["assertionId"] = _lasso.SamlAssertion_assertionId_get
    if _newclass:assertionId = property(_lasso.SamlAssertion_assertionId_get, _lasso.SamlAssertion_assertionId_set)
    __swig_setmethods__["certificateFile"] = _lasso.SamlAssertion_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.SamlAssertion_certificateFile_get
    if _newclass:certificateFile = property(_lasso.SamlAssertion_certificateFile_get, _lasso.SamlAssertion_certificateFile_set)
    __swig_setmethods__["issueInstant"] = _lasso.SamlAssertion_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.SamlAssertion_issueInstant_get
    if _newclass:issueInstant = property(_lasso.SamlAssertion_issueInstant_get, _lasso.SamlAssertion_issueInstant_set)
    __swig_setmethods__["issuer"] = _lasso.SamlAssertion_issuer_set
    __swig_getmethods__["issuer"] = _lasso.SamlAssertion_issuer_get
    if _newclass:issuer = property(_lasso.SamlAssertion_issuer_get, _lasso.SamlAssertion_issuer_set)
    __swig_setmethods__["majorVersion"] = _lasso.SamlAssertion_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.SamlAssertion_majorVersion_get
    if _newclass:majorVersion = property(_lasso.SamlAssertion_majorVersion_get, _lasso.SamlAssertion_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.SamlAssertion_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.SamlAssertion_minorVersion_get
    if _newclass:minorVersion = property(_lasso.SamlAssertion_minorVersion_get, _lasso.SamlAssertion_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.SamlAssertion_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.SamlAssertion_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.SamlAssertion_privateKeyFile_get, _lasso.SamlAssertion_privateKeyFile_set)
    __swig_setmethods__["signMethod"] = _lasso.SamlAssertion_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.SamlAssertion_signMethod_get
    if _newclass:signMethod = property(_lasso.SamlAssertion_signMethod_get, _lasso.SamlAssertion_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.SamlAssertion_signType_set
    __swig_getmethods__["signType"] = _lasso.SamlAssertion_signType_get
    if _newclass:signType = property(_lasso.SamlAssertion_signType_get, _lasso.SamlAssertion_signType_set)
    __swig_setmethods__["advice"] = _lasso.SamlAssertion_advice_set
    __swig_getmethods__["advice"] = _lasso.SamlAssertion_advice_get
    if _newclass:advice = property(_lasso.SamlAssertion_advice_get, _lasso.SamlAssertion_advice_set)
    __swig_setmethods__["attributeStatement"] = _lasso.SamlAssertion_attributeStatement_set
    __swig_getmethods__["attributeStatement"] = _lasso.SamlAssertion_attributeStatement_get
    if _newclass:attributeStatement = property(_lasso.SamlAssertion_attributeStatement_get, _lasso.SamlAssertion_attributeStatement_set)
    __swig_setmethods__["authenticationStatement"] = _lasso.SamlAssertion_authenticationStatement_set
    __swig_getmethods__["authenticationStatement"] = _lasso.SamlAssertion_authenticationStatement_get
    if _newclass:authenticationStatement = property(_lasso.SamlAssertion_authenticationStatement_get, _lasso.SamlAssertion_authenticationStatement_set)
    __swig_setmethods__["conditions"] = _lasso.SamlAssertion_conditions_set
    __swig_getmethods__["conditions"] = _lasso.SamlAssertion_conditions_get
    if _newclass:conditions = property(_lasso.SamlAssertion_conditions_get, _lasso.SamlAssertion_conditions_set)
    __swig_setmethods__["subjectStatement"] = _lasso.SamlAssertion_subjectStatement_set
    __swig_getmethods__["subjectStatement"] = _lasso.SamlAssertion_subjectStatement_get
    if _newclass:subjectStatement = property(_lasso.SamlAssertion_subjectStatement_get, _lasso.SamlAssertion_subjectStatement_set)
    def __init__(self, *args):
        this = _lasso.new_SamlAssertion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlAssertion
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlAssertion_dump(*args)
_lasso.SamlAssertion_swigregister(SamlAssertion)

class SamlAttribute(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlAttribute, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlAttribute, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlAttribute instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["attributeName"] = _lasso.SamlAttribute_attributeName_set
    __swig_getmethods__["attributeName"] = _lasso.SamlAttribute_attributeName_get
    if _newclass:attributeName = property(_lasso.SamlAttribute_attributeName_get, _lasso.SamlAttribute_attributeName_set)
    __swig_setmethods__["attributeNamespace"] = _lasso.SamlAttribute_attributeNamespace_set
    __swig_getmethods__["attributeNamespace"] = _lasso.SamlAttribute_attributeNamespace_get
    if _newclass:attributeNamespace = property(_lasso.SamlAttribute_attributeNamespace_get, _lasso.SamlAttribute_attributeNamespace_set)
    __swig_setmethods__["attributeValue"] = _lasso.SamlAttribute_attributeValue_set
    __swig_getmethods__["attributeValue"] = _lasso.SamlAttribute_attributeValue_get
    if _newclass:attributeValue = property(_lasso.SamlAttribute_attributeValue_get, _lasso.SamlAttribute_attributeValue_set)
    def __init__(self, *args):
        this = _lasso.new_SamlAttribute(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlAttribute
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlAttribute_dump(*args)
_lasso.SamlAttribute_swigregister(SamlAttribute)

class SamlAttributeDesignator(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlAttributeDesignator, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlAttributeDesignator, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlAttributeDesignator instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["attributeName"] = _lasso.SamlAttributeDesignator_attributeName_set
    __swig_getmethods__["attributeName"] = _lasso.SamlAttributeDesignator_attributeName_get
    if _newclass:attributeName = property(_lasso.SamlAttributeDesignator_attributeName_get, _lasso.SamlAttributeDesignator_attributeName_set)
    __swig_setmethods__["attributeNamespace"] = _lasso.SamlAttributeDesignator_attributeNamespace_set
    __swig_getmethods__["attributeNamespace"] = _lasso.SamlAttributeDesignator_attributeNamespace_get
    if _newclass:attributeNamespace = property(_lasso.SamlAttributeDesignator_attributeNamespace_get, _lasso.SamlAttributeDesignator_attributeNamespace_set)
    def __init__(self, *args):
        this = _lasso.new_SamlAttributeDesignator(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlAttributeDesignator
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlAttributeDesignator_dump(*args)
_lasso.SamlAttributeDesignator_swigregister(SamlAttributeDesignator)

class SamlAttributeStatement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlAttributeStatement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlAttributeStatement, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlAttributeStatement instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["subject"] = _lasso.SamlAttributeStatement_subject_set
    __swig_getmethods__["subject"] = _lasso.SamlAttributeStatement_subject_get
    if _newclass:subject = property(_lasso.SamlAttributeStatement_subject_get, _lasso.SamlAttributeStatement_subject_set)
    __swig_setmethods__["attribute"] = _lasso.SamlAttributeStatement_attribute_set
    __swig_getmethods__["attribute"] = _lasso.SamlAttributeStatement_attribute_get
    if _newclass:attribute = property(_lasso.SamlAttributeStatement_attribute_get, _lasso.SamlAttributeStatement_attribute_set)
    def __init__(self, *args):
        this = _lasso.new_SamlAttributeStatement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlAttributeStatement
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlAttributeStatement_dump(*args)
_lasso.SamlAttributeStatement_swigregister(SamlAttributeStatement)

class SamlAttributeValue(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlAttributeValue, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlAttributeValue, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlAttributeValue instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["any"] = _lasso.SamlAttributeValue_any_set
    __swig_getmethods__["any"] = _lasso.SamlAttributeValue_any_get
    if _newclass:any = property(_lasso.SamlAttributeValue_any_get, _lasso.SamlAttributeValue_any_set)
    def __init__(self, *args):
        this = _lasso.new_SamlAttributeValue(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlAttributeValue
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlAttributeValue_dump(*args)
_lasso.SamlAttributeValue_swigregister(SamlAttributeValue)

class SamlAudienceRestrictionCondition(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlAudienceRestrictionCondition, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlAudienceRestrictionCondition, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlAudienceRestrictionCondition instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["audience"] = _lasso.SamlAudienceRestrictionCondition_audience_set
    __swig_getmethods__["audience"] = _lasso.SamlAudienceRestrictionCondition_audience_get
    if _newclass:audience = property(_lasso.SamlAudienceRestrictionCondition_audience_get, _lasso.SamlAudienceRestrictionCondition_audience_set)
    def __init__(self, *args):
        this = _lasso.new_SamlAudienceRestrictionCondition(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlAudienceRestrictionCondition
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlAudienceRestrictionCondition_dump(*args)
_lasso.SamlAudienceRestrictionCondition_swigregister(SamlAudienceRestrictionCondition)

class SamlAuthenticationStatement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlAuthenticationStatement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlAuthenticationStatement, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlAuthenticationStatement instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["authenticationInstant"] = _lasso.SamlAuthenticationStatement_authenticationInstant_set
    __swig_getmethods__["authenticationInstant"] = _lasso.SamlAuthenticationStatement_authenticationInstant_get
    if _newclass:authenticationInstant = property(_lasso.SamlAuthenticationStatement_authenticationInstant_get, _lasso.SamlAuthenticationStatement_authenticationInstant_set)
    __swig_setmethods__["authenticationMethod"] = _lasso.SamlAuthenticationStatement_authenticationMethod_set
    __swig_getmethods__["authenticationMethod"] = _lasso.SamlAuthenticationStatement_authenticationMethod_get
    if _newclass:authenticationMethod = property(_lasso.SamlAuthenticationStatement_authenticationMethod_get, _lasso.SamlAuthenticationStatement_authenticationMethod_set)
    __swig_setmethods__["authorityBinding"] = _lasso.SamlAuthenticationStatement_authorityBinding_set
    __swig_getmethods__["authorityBinding"] = _lasso.SamlAuthenticationStatement_authorityBinding_get
    if _newclass:authorityBinding = property(_lasso.SamlAuthenticationStatement_authorityBinding_get, _lasso.SamlAuthenticationStatement_authorityBinding_set)
    __swig_setmethods__["subjectLocality"] = _lasso.SamlAuthenticationStatement_subjectLocality_set
    __swig_getmethods__["subjectLocality"] = _lasso.SamlAuthenticationStatement_subjectLocality_get
    if _newclass:subjectLocality = property(_lasso.SamlAuthenticationStatement_subjectLocality_get, _lasso.SamlAuthenticationStatement_subjectLocality_set)
    def __init__(self, *args):
        this = _lasso.new_SamlAuthenticationStatement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlAuthenticationStatement
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlAuthenticationStatement_dump(*args)
_lasso.SamlAuthenticationStatement_swigregister(SamlAuthenticationStatement)

class SamlAuthorityBinding(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlAuthorityBinding, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlAuthorityBinding, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlAuthorityBinding instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["authorityKind"] = _lasso.SamlAuthorityBinding_authorityKind_set
    __swig_getmethods__["authorityKind"] = _lasso.SamlAuthorityBinding_authorityKind_get
    if _newclass:authorityKind = property(_lasso.SamlAuthorityBinding_authorityKind_get, _lasso.SamlAuthorityBinding_authorityKind_set)
    __swig_setmethods__["location"] = _lasso.SamlAuthorityBinding_location_set
    __swig_getmethods__["location"] = _lasso.SamlAuthorityBinding_location_get
    if _newclass:location = property(_lasso.SamlAuthorityBinding_location_get, _lasso.SamlAuthorityBinding_location_set)
    __swig_setmethods__["binding"] = _lasso.SamlAuthorityBinding_binding_set
    __swig_getmethods__["binding"] = _lasso.SamlAuthorityBinding_binding_get
    if _newclass:binding = property(_lasso.SamlAuthorityBinding_binding_get, _lasso.SamlAuthorityBinding_binding_set)
    def __init__(self, *args):
        this = _lasso.new_SamlAuthorityBinding(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlAuthorityBinding
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlAuthorityBinding_dump(*args)
_lasso.SamlAuthorityBinding_swigregister(SamlAuthorityBinding)

class SamlConditionAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlConditionAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlConditionAbstract, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlConditionAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def dump(*args): return _lasso.SamlConditionAbstract_dump(*args)
_lasso.SamlConditionAbstract_swigregister(SamlConditionAbstract)

class SamlConditions(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlConditions, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlConditions, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlConditions instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["notBefore"] = _lasso.SamlConditions_notBefore_set
    __swig_getmethods__["notBefore"] = _lasso.SamlConditions_notBefore_get
    if _newclass:notBefore = property(_lasso.SamlConditions_notBefore_get, _lasso.SamlConditions_notBefore_set)
    __swig_setmethods__["notOnOrAfter"] = _lasso.SamlConditions_notOnOrAfter_set
    __swig_getmethods__["notOnOrAfter"] = _lasso.SamlConditions_notOnOrAfter_get
    if _newclass:notOnOrAfter = property(_lasso.SamlConditions_notOnOrAfter_get, _lasso.SamlConditions_notOnOrAfter_set)
    __swig_setmethods__["audienceRestrictionCondition"] = _lasso.SamlConditions_audienceRestrictionCondition_set
    __swig_getmethods__["audienceRestrictionCondition"] = _lasso.SamlConditions_audienceRestrictionCondition_get
    if _newclass:audienceRestrictionCondition = property(_lasso.SamlConditions_audienceRestrictionCondition_get, _lasso.SamlConditions_audienceRestrictionCondition_set)
    __swig_setmethods__["condition"] = _lasso.SamlConditions_condition_set
    __swig_getmethods__["condition"] = _lasso.SamlConditions_condition_get
    if _newclass:condition = property(_lasso.SamlConditions_condition_get, _lasso.SamlConditions_condition_set)
    def __init__(self, *args):
        this = _lasso.new_SamlConditions(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlConditions
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlConditions_dump(*args)
_lasso.SamlConditions_swigregister(SamlConditions)

class SamlNameIdentifier(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlNameIdentifier, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlNameIdentifier, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlNameIdentifier instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["content"] = _lasso.SamlNameIdentifier_content_set
    __swig_getmethods__["content"] = _lasso.SamlNameIdentifier_content_get
    if _newclass:content = property(_lasso.SamlNameIdentifier_content_get, _lasso.SamlNameIdentifier_content_set)
    __swig_setmethods__["format"] = _lasso.SamlNameIdentifier_format_set
    __swig_getmethods__["format"] = _lasso.SamlNameIdentifier_format_get
    if _newclass:format = property(_lasso.SamlNameIdentifier_format_get, _lasso.SamlNameIdentifier_format_set)
    __swig_setmethods__["nameQualifier"] = _lasso.SamlNameIdentifier_nameQualifier_set
    __swig_getmethods__["nameQualifier"] = _lasso.SamlNameIdentifier_nameQualifier_get
    if _newclass:nameQualifier = property(_lasso.SamlNameIdentifier_nameQualifier_get, _lasso.SamlNameIdentifier_nameQualifier_set)
    def __init__(self, *args):
        this = _lasso.new_SamlNameIdentifier(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlNameIdentifier
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlNameIdentifier_dump(*args)
_lasso.SamlNameIdentifier_swigregister(SamlNameIdentifier)

class SamlStatementAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlStatementAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlStatementAbstract, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlStatementAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def dump(*args): return _lasso.SamlStatementAbstract_dump(*args)
_lasso.SamlStatementAbstract_swigregister(SamlStatementAbstract)

class SamlSubject(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlSubject, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlSubject, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlSubject instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["nameIdentifier"] = _lasso.SamlSubject_nameIdentifier_set
    __swig_getmethods__["nameIdentifier"] = _lasso.SamlSubject_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.SamlSubject_nameIdentifier_get, _lasso.SamlSubject_nameIdentifier_set)
    __swig_setmethods__["subjectConfirmation"] = _lasso.SamlSubject_subjectConfirmation_set
    __swig_getmethods__["subjectConfirmation"] = _lasso.SamlSubject_subjectConfirmation_get
    if _newclass:subjectConfirmation = property(_lasso.SamlSubject_subjectConfirmation_get, _lasso.SamlSubject_subjectConfirmation_set)
    def __init__(self, *args):
        this = _lasso.new_SamlSubject(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlSubject
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlSubject_dump(*args)
_lasso.SamlSubject_swigregister(SamlSubject)

class SamlSubjectConfirmation(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlSubjectConfirmation, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlSubjectConfirmation, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlSubjectConfirmation instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["subjectConfirmationData"] = _lasso.SamlSubjectConfirmation_subjectConfirmationData_set
    __swig_getmethods__["subjectConfirmationData"] = _lasso.SamlSubjectConfirmation_subjectConfirmationData_get
    if _newclass:subjectConfirmationData = property(_lasso.SamlSubjectConfirmation_subjectConfirmationData_get, _lasso.SamlSubjectConfirmation_subjectConfirmationData_set)
    __swig_setmethods__["confirmationMethod"] = _lasso.SamlSubjectConfirmation_confirmationMethod_set
    __swig_getmethods__["confirmationMethod"] = _lasso.SamlSubjectConfirmation_confirmationMethod_get
    if _newclass:confirmationMethod = property(_lasso.SamlSubjectConfirmation_confirmationMethod_get, _lasso.SamlSubjectConfirmation_confirmationMethod_set)
    def __init__(self, *args):
        this = _lasso.new_SamlSubjectConfirmation(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlSubjectConfirmation
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlSubjectConfirmation_dump(*args)
_lasso.SamlSubjectConfirmation_swigregister(SamlSubjectConfirmation)

class SamlSubjectLocality(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlSubjectLocality, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlSubjectLocality, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlSubjectLocality instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["dnsAddress"] = _lasso.SamlSubjectLocality_dnsAddress_set
    __swig_getmethods__["dnsAddress"] = _lasso.SamlSubjectLocality_dnsAddress_get
    if _newclass:dnsAddress = property(_lasso.SamlSubjectLocality_dnsAddress_get, _lasso.SamlSubjectLocality_dnsAddress_set)
    __swig_setmethods__["ipAddress"] = _lasso.SamlSubjectLocality_ipAddress_set
    __swig_getmethods__["ipAddress"] = _lasso.SamlSubjectLocality_ipAddress_get
    if _newclass:ipAddress = property(_lasso.SamlSubjectLocality_ipAddress_get, _lasso.SamlSubjectLocality_ipAddress_set)
    def __init__(self, *args):
        this = _lasso.new_SamlSubjectLocality(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlSubjectLocality
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlSubjectLocality_dump(*args)
_lasso.SamlSubjectLocality_swigregister(SamlSubjectLocality)

class SamlSubjectStatement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlSubjectStatement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlSubjectStatement, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlSubjectStatement instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["subject"] = _lasso.SamlSubjectStatement_subject_set
    __swig_getmethods__["subject"] = _lasso.SamlSubjectStatement_subject_get
    if _newclass:subject = property(_lasso.SamlSubjectStatement_subject_get, _lasso.SamlSubjectStatement_subject_set)
    def __init__(self, *args):
        this = _lasso.new_SamlSubjectStatement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlSubjectStatement
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlSubjectStatement_dump(*args)
_lasso.SamlSubjectStatement_swigregister(SamlSubjectStatement)

class SamlSubjectStatementAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlSubjectStatementAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlSubjectStatementAbstract, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlSubjectStatementAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["subject"] = _lasso.SamlSubjectStatementAbstract_subject_set
    __swig_getmethods__["subject"] = _lasso.SamlSubjectStatementAbstract_subject_get
    if _newclass:subject = property(_lasso.SamlSubjectStatementAbstract_subject_get, _lasso.SamlSubjectStatementAbstract_subject_set)
    def dump(*args): return _lasso.SamlSubjectStatementAbstract_dump(*args)
_lasso.SamlSubjectStatementAbstract_swigregister(SamlSubjectStatementAbstract)

class SamlpRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlpRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlpRequest, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlpRequest instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["assertionArtifact"] = _lasso.SamlpRequest_assertionArtifact_set
    __swig_getmethods__["assertionArtifact"] = _lasso.SamlpRequest_assertionArtifact_get
    if _newclass:assertionArtifact = property(_lasso.SamlpRequest_assertionArtifact_get, _lasso.SamlpRequest_assertionArtifact_set)
    __swig_setmethods__["certificateFile"] = _lasso.SamlpRequest_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.SamlpRequest_certificateFile_get
    if _newclass:certificateFile = property(_lasso.SamlpRequest_certificateFile_get, _lasso.SamlpRequest_certificateFile_set)
    __swig_setmethods__["issueInstant"] = _lasso.SamlpRequest_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.SamlpRequest_issueInstant_get
    if _newclass:issueInstant = property(_lasso.SamlpRequest_issueInstant_get, _lasso.SamlpRequest_issueInstant_set)
    __swig_setmethods__["majorVersion"] = _lasso.SamlpRequest_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.SamlpRequest_majorVersion_get
    if _newclass:majorVersion = property(_lasso.SamlpRequest_majorVersion_get, _lasso.SamlpRequest_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.SamlpRequest_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.SamlpRequest_minorVersion_get
    if _newclass:minorVersion = property(_lasso.SamlpRequest_minorVersion_get, _lasso.SamlpRequest_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.SamlpRequest_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.SamlpRequest_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.SamlpRequest_privateKeyFile_get, _lasso.SamlpRequest_privateKeyFile_set)
    __swig_setmethods__["requestId"] = _lasso.SamlpRequest_requestId_set
    __swig_getmethods__["requestId"] = _lasso.SamlpRequest_requestId_get
    if _newclass:requestId = property(_lasso.SamlpRequest_requestId_get, _lasso.SamlpRequest_requestId_set)
    __swig_setmethods__["respondWith"] = _lasso.SamlpRequest_respondWith_set
    __swig_getmethods__["respondWith"] = _lasso.SamlpRequest_respondWith_get
    if _newclass:respondWith = property(_lasso.SamlpRequest_respondWith_get, _lasso.SamlpRequest_respondWith_set)
    __swig_setmethods__["signMethod"] = _lasso.SamlpRequest_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.SamlpRequest_signMethod_get
    if _newclass:signMethod = property(_lasso.SamlpRequest_signMethod_get, _lasso.SamlpRequest_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.SamlpRequest_signType_set
    __swig_getmethods__["signType"] = _lasso.SamlpRequest_signType_get
    if _newclass:signType = property(_lasso.SamlpRequest_signType_get, _lasso.SamlpRequest_signType_set)
    def __init__(self, *args):
        this = _lasso.new_SamlpRequest(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlpRequest
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlpRequest_dump(*args)
_lasso.SamlpRequest_swigregister(SamlpRequest)

class SamlpRequestAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlpRequestAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlpRequestAbstract, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlpRequestAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["certificateFile"] = _lasso.SamlpRequestAbstract_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.SamlpRequestAbstract_certificateFile_get
    if _newclass:certificateFile = property(_lasso.SamlpRequestAbstract_certificateFile_get, _lasso.SamlpRequestAbstract_certificateFile_set)
    __swig_setmethods__["issueInstant"] = _lasso.SamlpRequestAbstract_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.SamlpRequestAbstract_issueInstant_get
    if _newclass:issueInstant = property(_lasso.SamlpRequestAbstract_issueInstant_get, _lasso.SamlpRequestAbstract_issueInstant_set)
    __swig_setmethods__["majorVersion"] = _lasso.SamlpRequestAbstract_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.SamlpRequestAbstract_majorVersion_get
    if _newclass:majorVersion = property(_lasso.SamlpRequestAbstract_majorVersion_get, _lasso.SamlpRequestAbstract_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.SamlpRequestAbstract_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.SamlpRequestAbstract_minorVersion_get
    if _newclass:minorVersion = property(_lasso.SamlpRequestAbstract_minorVersion_get, _lasso.SamlpRequestAbstract_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.SamlpRequestAbstract_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.SamlpRequestAbstract_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.SamlpRequestAbstract_privateKeyFile_get, _lasso.SamlpRequestAbstract_privateKeyFile_set)
    __swig_setmethods__["requestId"] = _lasso.SamlpRequestAbstract_requestId_set
    __swig_getmethods__["requestId"] = _lasso.SamlpRequestAbstract_requestId_get
    if _newclass:requestId = property(_lasso.SamlpRequestAbstract_requestId_get, _lasso.SamlpRequestAbstract_requestId_set)
    __swig_setmethods__["signMethod"] = _lasso.SamlpRequestAbstract_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.SamlpRequestAbstract_signMethod_get
    if _newclass:signMethod = property(_lasso.SamlpRequestAbstract_signMethod_get, _lasso.SamlpRequestAbstract_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.SamlpRequestAbstract_signType_set
    __swig_getmethods__["signType"] = _lasso.SamlpRequestAbstract_signType_get
    if _newclass:signType = property(_lasso.SamlpRequestAbstract_signType_get, _lasso.SamlpRequestAbstract_signType_set)
    __swig_setmethods__["respondWith"] = _lasso.SamlpRequestAbstract_respondWith_set
    __swig_getmethods__["respondWith"] = _lasso.SamlpRequestAbstract_respondWith_get
    if _newclass:respondWith = property(_lasso.SamlpRequestAbstract_respondWith_get, _lasso.SamlpRequestAbstract_respondWith_set)
    def dump(*args): return _lasso.SamlpRequestAbstract_dump(*args)
_lasso.SamlpRequestAbstract_swigregister(SamlpRequestAbstract)

class SamlpResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlpResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlpResponse, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlpResponse instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["certificateFile"] = _lasso.SamlpResponse_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.SamlpResponse_certificateFile_get
    if _newclass:certificateFile = property(_lasso.SamlpResponse_certificateFile_get, _lasso.SamlpResponse_certificateFile_set)
    __swig_setmethods__["inResponseTo"] = _lasso.SamlpResponse_inResponseTo_set
    __swig_getmethods__["inResponseTo"] = _lasso.SamlpResponse_inResponseTo_get
    if _newclass:inResponseTo = property(_lasso.SamlpResponse_inResponseTo_get, _lasso.SamlpResponse_inResponseTo_set)
    __swig_setmethods__["issueInstant"] = _lasso.SamlpResponse_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.SamlpResponse_issueInstant_get
    if _newclass:issueInstant = property(_lasso.SamlpResponse_issueInstant_get, _lasso.SamlpResponse_issueInstant_set)
    __swig_setmethods__["majorVersion"] = _lasso.SamlpResponse_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.SamlpResponse_majorVersion_get
    if _newclass:majorVersion = property(_lasso.SamlpResponse_majorVersion_get, _lasso.SamlpResponse_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.SamlpResponse_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.SamlpResponse_minorVersion_get
    if _newclass:minorVersion = property(_lasso.SamlpResponse_minorVersion_get, _lasso.SamlpResponse_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.SamlpResponse_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.SamlpResponse_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.SamlpResponse_privateKeyFile_get, _lasso.SamlpResponse_privateKeyFile_set)
    __swig_setmethods__["recipient"] = _lasso.SamlpResponse_recipient_set
    __swig_getmethods__["recipient"] = _lasso.SamlpResponse_recipient_get
    if _newclass:recipient = property(_lasso.SamlpResponse_recipient_get, _lasso.SamlpResponse_recipient_set)
    __swig_setmethods__["responseId"] = _lasso.SamlpResponse_responseId_set
    __swig_getmethods__["responseId"] = _lasso.SamlpResponse_responseId_get
    if _newclass:responseId = property(_lasso.SamlpResponse_responseId_get, _lasso.SamlpResponse_responseId_set)
    __swig_setmethods__["signMethod"] = _lasso.SamlpResponse_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.SamlpResponse_signMethod_get
    if _newclass:signMethod = property(_lasso.SamlpResponse_signMethod_get, _lasso.SamlpResponse_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.SamlpResponse_signType_set
    __swig_getmethods__["signType"] = _lasso.SamlpResponse_signType_get
    if _newclass:signType = property(_lasso.SamlpResponse_signType_get, _lasso.SamlpResponse_signType_set)
    __swig_setmethods__["assertion"] = _lasso.SamlpResponse_assertion_set
    __swig_getmethods__["assertion"] = _lasso.SamlpResponse_assertion_get
    if _newclass:assertion = property(_lasso.SamlpResponse_assertion_get, _lasso.SamlpResponse_assertion_set)
    __swig_setmethods__["status"] = _lasso.SamlpResponse_status_set
    __swig_getmethods__["status"] = _lasso.SamlpResponse_status_get
    if _newclass:status = property(_lasso.SamlpResponse_status_get, _lasso.SamlpResponse_status_set)
    def __init__(self, *args):
        this = _lasso.new_SamlpResponse(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlpResponse
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlpResponse_dump(*args)
_lasso.SamlpResponse_swigregister(SamlpResponse)

class SamlpResponseAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlpResponseAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlpResponseAbstract, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlpResponseAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["certificateFile"] = _lasso.SamlpResponseAbstract_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.SamlpResponseAbstract_certificateFile_get
    if _newclass:certificateFile = property(_lasso.SamlpResponseAbstract_certificateFile_get, _lasso.SamlpResponseAbstract_certificateFile_set)
    __swig_setmethods__["inResponseTo"] = _lasso.SamlpResponseAbstract_inResponseTo_set
    __swig_getmethods__["inResponseTo"] = _lasso.SamlpResponseAbstract_inResponseTo_get
    if _newclass:inResponseTo = property(_lasso.SamlpResponseAbstract_inResponseTo_get, _lasso.SamlpResponseAbstract_inResponseTo_set)
    __swig_setmethods__["issueInstant"] = _lasso.SamlpResponseAbstract_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.SamlpResponseAbstract_issueInstant_get
    if _newclass:issueInstant = property(_lasso.SamlpResponseAbstract_issueInstant_get, _lasso.SamlpResponseAbstract_issueInstant_set)
    __swig_setmethods__["majorVersion"] = _lasso.SamlpResponseAbstract_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.SamlpResponseAbstract_majorVersion_get
    if _newclass:majorVersion = property(_lasso.SamlpResponseAbstract_majorVersion_get, _lasso.SamlpResponseAbstract_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.SamlpResponseAbstract_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.SamlpResponseAbstract_minorVersion_get
    if _newclass:minorVersion = property(_lasso.SamlpResponseAbstract_minorVersion_get, _lasso.SamlpResponseAbstract_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.SamlpResponseAbstract_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.SamlpResponseAbstract_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.SamlpResponseAbstract_privateKeyFile_get, _lasso.SamlpResponseAbstract_privateKeyFile_set)
    __swig_setmethods__["recipient"] = _lasso.SamlpResponseAbstract_recipient_set
    __swig_getmethods__["recipient"] = _lasso.SamlpResponseAbstract_recipient_get
    if _newclass:recipient = property(_lasso.SamlpResponseAbstract_recipient_get, _lasso.SamlpResponseAbstract_recipient_set)
    __swig_setmethods__["responseId"] = _lasso.SamlpResponseAbstract_responseId_set
    __swig_getmethods__["responseId"] = _lasso.SamlpResponseAbstract_responseId_get
    if _newclass:responseId = property(_lasso.SamlpResponseAbstract_responseId_get, _lasso.SamlpResponseAbstract_responseId_set)
    __swig_setmethods__["signMethod"] = _lasso.SamlpResponseAbstract_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.SamlpResponseAbstract_signMethod_get
    if _newclass:signMethod = property(_lasso.SamlpResponseAbstract_signMethod_get, _lasso.SamlpResponseAbstract_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.SamlpResponseAbstract_signType_set
    __swig_getmethods__["signType"] = _lasso.SamlpResponseAbstract_signType_get
    if _newclass:signType = property(_lasso.SamlpResponseAbstract_signType_get, _lasso.SamlpResponseAbstract_signType_set)
    def dump(*args): return _lasso.SamlpResponseAbstract_dump(*args)
_lasso.SamlpResponseAbstract_swigregister(SamlpResponseAbstract)

class SamlpStatus(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlpStatus, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlpStatus, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlpStatus instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["statusMessage"] = _lasso.SamlpStatus_statusMessage_set
    __swig_getmethods__["statusMessage"] = _lasso.SamlpStatus_statusMessage_get
    if _newclass:statusMessage = property(_lasso.SamlpStatus_statusMessage_get, _lasso.SamlpStatus_statusMessage_set)
    __swig_setmethods__["statusCode"] = _lasso.SamlpStatus_statusCode_set
    __swig_getmethods__["statusCode"] = _lasso.SamlpStatus_statusCode_get
    if _newclass:statusCode = property(_lasso.SamlpStatus_statusCode_get, _lasso.SamlpStatus_statusCode_set)
    def __init__(self, *args):
        this = _lasso.new_SamlpStatus(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlpStatus
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlpStatus_dump(*args)
_lasso.SamlpStatus_swigregister(SamlpStatus)

class SamlpStatusCode(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SamlpStatusCode, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SamlpStatusCode, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlpStatusCode instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["value"] = _lasso.SamlpStatusCode_value_set
    __swig_getmethods__["value"] = _lasso.SamlpStatusCode_value_get
    if _newclass:value = property(_lasso.SamlpStatusCode_value_get, _lasso.SamlpStatusCode_value_set)
    __swig_setmethods__["statusCode"] = _lasso.SamlpStatusCode_statusCode_set
    __swig_getmethods__["statusCode"] = _lasso.SamlpStatusCode_statusCode_get
    if _newclass:statusCode = property(_lasso.SamlpStatusCode_statusCode_get, _lasso.SamlpStatusCode_statusCode_set)
    def __init__(self, *args):
        this = _lasso.new_SamlpStatusCode(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_SamlpStatusCode
    __del__ = lambda self : None;
    def dump(*args): return _lasso.SamlpStatusCode_dump(*args)
_lasso.SamlpStatusCode_swigregister(SamlpStatusCode)

class LibAssertion(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibAssertion, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibAssertion, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibAssertion instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["advice"] = _lasso.LibAssertion_advice_set
    __swig_getmethods__["advice"] = _lasso.LibAssertion_advice_get
    if _newclass:advice = property(_lasso.LibAssertion_advice_get, _lasso.LibAssertion_advice_set)
    __swig_setmethods__["assertionId"] = _lasso.LibAssertion_assertionId_set
    __swig_getmethods__["assertionId"] = _lasso.LibAssertion_assertionId_get
    if _newclass:assertionId = property(_lasso.LibAssertion_assertionId_get, _lasso.LibAssertion_assertionId_set)
    __swig_setmethods__["attributeStatement"] = _lasso.LibAssertion_attributeStatement_set
    __swig_getmethods__["attributeStatement"] = _lasso.LibAssertion_attributeStatement_get
    if _newclass:attributeStatement = property(_lasso.LibAssertion_attributeStatement_get, _lasso.LibAssertion_attributeStatement_set)
    __swig_setmethods__["authenticationStatement"] = _lasso.LibAssertion_authenticationStatement_set
    __swig_getmethods__["authenticationStatement"] = _lasso.LibAssertion_authenticationStatement_get
    if _newclass:authenticationStatement = property(_lasso.LibAssertion_authenticationStatement_get, _lasso.LibAssertion_authenticationStatement_set)
    __swig_setmethods__["certificateFile"] = _lasso.LibAssertion_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.LibAssertion_certificateFile_get
    if _newclass:certificateFile = property(_lasso.LibAssertion_certificateFile_get, _lasso.LibAssertion_certificateFile_set)
    __swig_setmethods__["conditions"] = _lasso.LibAssertion_conditions_set
    __swig_getmethods__["conditions"] = _lasso.LibAssertion_conditions_get
    if _newclass:conditions = property(_lasso.LibAssertion_conditions_get, _lasso.LibAssertion_conditions_set)
    __swig_setmethods__["issueInstant"] = _lasso.LibAssertion_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.LibAssertion_issueInstant_get
    if _newclass:issueInstant = property(_lasso.LibAssertion_issueInstant_get, _lasso.LibAssertion_issueInstant_set)
    __swig_setmethods__["issuer"] = _lasso.LibAssertion_issuer_set
    __swig_getmethods__["issuer"] = _lasso.LibAssertion_issuer_get
    if _newclass:issuer = property(_lasso.LibAssertion_issuer_get, _lasso.LibAssertion_issuer_set)
    __swig_setmethods__["majorVersion"] = _lasso.LibAssertion_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.LibAssertion_majorVersion_get
    if _newclass:majorVersion = property(_lasso.LibAssertion_majorVersion_get, _lasso.LibAssertion_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.LibAssertion_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.LibAssertion_minorVersion_get
    if _newclass:minorVersion = property(_lasso.LibAssertion_minorVersion_get, _lasso.LibAssertion_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.LibAssertion_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.LibAssertion_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.LibAssertion_privateKeyFile_get, _lasso.LibAssertion_privateKeyFile_set)
    __swig_setmethods__["signMethod"] = _lasso.LibAssertion_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.LibAssertion_signMethod_get
    if _newclass:signMethod = property(_lasso.LibAssertion_signMethod_get, _lasso.LibAssertion_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.LibAssertion_signType_set
    __swig_getmethods__["signType"] = _lasso.LibAssertion_signType_get
    if _newclass:signType = property(_lasso.LibAssertion_signType_get, _lasso.LibAssertion_signType_set)
    __swig_setmethods__["subjectStatement"] = _lasso.LibAssertion_subjectStatement_set
    __swig_getmethods__["subjectStatement"] = _lasso.LibAssertion_subjectStatement_get
    if _newclass:subjectStatement = property(_lasso.LibAssertion_subjectStatement_get, _lasso.LibAssertion_subjectStatement_set)
    def __init__(self, *args):
        this = _lasso.new_LibAssertion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibAssertion
    __del__ = lambda self : None;
    __swig_getmethods__["newFull"] = lambda x: _lasso.LibAssertion_newFull
    if _newclass:newFull = staticmethod(_lasso.LibAssertion_newFull)
    def dump(*args): return _lasso.LibAssertion_dump(*args)
_lasso.LibAssertion_swigregister(LibAssertion)

LibAssertion_newFull = _lasso.LibAssertion_newFull

class LibAuthnRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibAuthnRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibAuthnRequest, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibAuthnRequest instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["affiliationId"] = _lasso.LibAuthnRequest_affiliationId_set
    __swig_getmethods__["affiliationId"] = _lasso.LibAuthnRequest_affiliationId_get
    if _newclass:affiliationId = property(_lasso.LibAuthnRequest_affiliationId_get, _lasso.LibAuthnRequest_affiliationId_set)
    __swig_setmethods__["assertionConsumerServiceId"] = _lasso.LibAuthnRequest_assertionConsumerServiceId_set
    __swig_getmethods__["assertionConsumerServiceId"] = _lasso.LibAuthnRequest_assertionConsumerServiceId_get
    if _newclass:assertionConsumerServiceId = property(_lasso.LibAuthnRequest_assertionConsumerServiceId_get, _lasso.LibAuthnRequest_assertionConsumerServiceId_set)
    __swig_setmethods__["consent"] = _lasso.LibAuthnRequest_consent_set
    __swig_getmethods__["consent"] = _lasso.LibAuthnRequest_consent_get
    if _newclass:consent = property(_lasso.LibAuthnRequest_consent_get, _lasso.LibAuthnRequest_consent_set)
    __swig_setmethods__["forceAuthn"] = _lasso.LibAuthnRequest_forceAuthn_set
    __swig_getmethods__["forceAuthn"] = _lasso.LibAuthnRequest_forceAuthn_get
    if _newclass:forceAuthn = property(_lasso.LibAuthnRequest_forceAuthn_get, _lasso.LibAuthnRequest_forceAuthn_set)
    __swig_setmethods__["isPassive"] = _lasso.LibAuthnRequest_isPassive_set
    __swig_getmethods__["isPassive"] = _lasso.LibAuthnRequest_isPassive_get
    if _newclass:isPassive = property(_lasso.LibAuthnRequest_isPassive_get, _lasso.LibAuthnRequest_isPassive_set)
    __swig_setmethods__["nameIdPolicy"] = _lasso.LibAuthnRequest_nameIdPolicy_set
    __swig_getmethods__["nameIdPolicy"] = _lasso.LibAuthnRequest_nameIdPolicy_get
    if _newclass:nameIdPolicy = property(_lasso.LibAuthnRequest_nameIdPolicy_get, _lasso.LibAuthnRequest_nameIdPolicy_set)
    __swig_setmethods__["protocolProfile"] = _lasso.LibAuthnRequest_protocolProfile_set
    __swig_getmethods__["protocolProfile"] = _lasso.LibAuthnRequest_protocolProfile_get
    if _newclass:protocolProfile = property(_lasso.LibAuthnRequest_protocolProfile_get, _lasso.LibAuthnRequest_protocolProfile_set)
    __swig_setmethods__["providerId"] = _lasso.LibAuthnRequest_providerId_set
    __swig_getmethods__["providerId"] = _lasso.LibAuthnRequest_providerId_get
    if _newclass:providerId = property(_lasso.LibAuthnRequest_providerId_get, _lasso.LibAuthnRequest_providerId_set)
    __swig_setmethods__["relayState"] = _lasso.LibAuthnRequest_relayState_set
    __swig_getmethods__["relayState"] = _lasso.LibAuthnRequest_relayState_get
    if _newclass:relayState = property(_lasso.LibAuthnRequest_relayState_get, _lasso.LibAuthnRequest_relayState_set)
    __swig_setmethods__["certificateFile"] = _lasso.LibAuthnRequest_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.LibAuthnRequest_certificateFile_get
    if _newclass:certificateFile = property(_lasso.LibAuthnRequest_certificateFile_get, _lasso.LibAuthnRequest_certificateFile_set)
    __swig_setmethods__["issueInstant"] = _lasso.LibAuthnRequest_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.LibAuthnRequest_issueInstant_get
    if _newclass:issueInstant = property(_lasso.LibAuthnRequest_issueInstant_get, _lasso.LibAuthnRequest_issueInstant_set)
    __swig_setmethods__["majorVersion"] = _lasso.LibAuthnRequest_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.LibAuthnRequest_majorVersion_get
    if _newclass:majorVersion = property(_lasso.LibAuthnRequest_majorVersion_get, _lasso.LibAuthnRequest_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.LibAuthnRequest_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.LibAuthnRequest_minorVersion_get
    if _newclass:minorVersion = property(_lasso.LibAuthnRequest_minorVersion_get, _lasso.LibAuthnRequest_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.LibAuthnRequest_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.LibAuthnRequest_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.LibAuthnRequest_privateKeyFile_get, _lasso.LibAuthnRequest_privateKeyFile_set)
    __swig_setmethods__["requestId"] = _lasso.LibAuthnRequest_requestId_set
    __swig_getmethods__["requestId"] = _lasso.LibAuthnRequest_requestId_get
    if _newclass:requestId = property(_lasso.LibAuthnRequest_requestId_get, _lasso.LibAuthnRequest_requestId_set)
    __swig_setmethods__["respondWith"] = _lasso.LibAuthnRequest_respondWith_set
    __swig_getmethods__["respondWith"] = _lasso.LibAuthnRequest_respondWith_get
    if _newclass:respondWith = property(_lasso.LibAuthnRequest_respondWith_get, _lasso.LibAuthnRequest_respondWith_set)
    __swig_setmethods__["signMethod"] = _lasso.LibAuthnRequest_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.LibAuthnRequest_signMethod_get
    if _newclass:signMethod = property(_lasso.LibAuthnRequest_signMethod_get, _lasso.LibAuthnRequest_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.LibAuthnRequest_signType_set
    __swig_getmethods__["signType"] = _lasso.LibAuthnRequest_signType_get
    if _newclass:signType = property(_lasso.LibAuthnRequest_signType_get, _lasso.LibAuthnRequest_signType_set)
    __swig_setmethods__["extension"] = _lasso.LibAuthnRequest_extension_set
    __swig_getmethods__["extension"] = _lasso.LibAuthnRequest_extension_get
    if _newclass:extension = property(_lasso.LibAuthnRequest_extension_get, _lasso.LibAuthnRequest_extension_set)
    __swig_setmethods__["requestAuthnContext"] = _lasso.LibAuthnRequest_requestAuthnContext_set
    __swig_getmethods__["requestAuthnContext"] = _lasso.LibAuthnRequest_requestAuthnContext_get
    if _newclass:requestAuthnContext = property(_lasso.LibAuthnRequest_requestAuthnContext_get, _lasso.LibAuthnRequest_requestAuthnContext_set)
    def __init__(self, *args):
        this = _lasso.new_LibAuthnRequest(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibAuthnRequest
    __del__ = lambda self : None;
    def dump(*args): return _lasso.LibAuthnRequest_dump(*args)
_lasso.LibAuthnRequest_swigregister(LibAuthnRequest)

class LibAuthnResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibAuthnResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibAuthnResponse, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibAuthnResponse instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["consent"] = _lasso.LibAuthnResponse_consent_set
    __swig_getmethods__["consent"] = _lasso.LibAuthnResponse_consent_get
    if _newclass:consent = property(_lasso.LibAuthnResponse_consent_get, _lasso.LibAuthnResponse_consent_set)
    __swig_setmethods__["providerId"] = _lasso.LibAuthnResponse_providerId_set
    __swig_getmethods__["providerId"] = _lasso.LibAuthnResponse_providerId_get
    if _newclass:providerId = property(_lasso.LibAuthnResponse_providerId_get, _lasso.LibAuthnResponse_providerId_set)
    __swig_setmethods__["relayState"] = _lasso.LibAuthnResponse_relayState_set
    __swig_getmethods__["relayState"] = _lasso.LibAuthnResponse_relayState_get
    if _newclass:relayState = property(_lasso.LibAuthnResponse_relayState_get, _lasso.LibAuthnResponse_relayState_set)
    __swig_setmethods__["extension"] = _lasso.LibAuthnResponse_extension_set
    __swig_getmethods__["extension"] = _lasso.LibAuthnResponse_extension_get
    if _newclass:extension = property(_lasso.LibAuthnResponse_extension_get, _lasso.LibAuthnResponse_extension_set)
    __swig_setmethods__["status"] = _lasso.LibAuthnResponse_status_set
    __swig_getmethods__["status"] = _lasso.LibAuthnResponse_status_get
    if _newclass:status = property(_lasso.LibAuthnResponse_status_get, _lasso.LibAuthnResponse_status_set)
    def __init__(self, *args):
        this = _lasso.new_LibAuthnResponse(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibAuthnResponse
    __del__ = lambda self : None;
    def dump(*args): return _lasso.LibAuthnResponse_dump(*args)
_lasso.LibAuthnResponse_swigregister(LibAuthnResponse)

class LibFederationTerminationNotification(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibFederationTerminationNotification, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibFederationTerminationNotification, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibFederationTerminationNotification instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["consent"] = _lasso.LibFederationTerminationNotification_consent_set
    __swig_getmethods__["consent"] = _lasso.LibFederationTerminationNotification_consent_get
    if _newclass:consent = property(_lasso.LibFederationTerminationNotification_consent_get, _lasso.LibFederationTerminationNotification_consent_set)
    __swig_setmethods__["providerId"] = _lasso.LibFederationTerminationNotification_providerId_set
    __swig_getmethods__["providerId"] = _lasso.LibFederationTerminationNotification_providerId_get
    if _newclass:providerId = property(_lasso.LibFederationTerminationNotification_providerId_get, _lasso.LibFederationTerminationNotification_providerId_set)
    __swig_setmethods__["relayState"] = _lasso.LibFederationTerminationNotification_relayState_set
    __swig_getmethods__["relayState"] = _lasso.LibFederationTerminationNotification_relayState_get
    if _newclass:relayState = property(_lasso.LibFederationTerminationNotification_relayState_get, _lasso.LibFederationTerminationNotification_relayState_set)
    __swig_setmethods__["certificateFile"] = _lasso.LibFederationTerminationNotification_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.LibFederationTerminationNotification_certificateFile_get
    if _newclass:certificateFile = property(_lasso.LibFederationTerminationNotification_certificateFile_get, _lasso.LibFederationTerminationNotification_certificateFile_set)
    __swig_setmethods__["issueInstant"] = _lasso.LibFederationTerminationNotification_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.LibFederationTerminationNotification_issueInstant_get
    if _newclass:issueInstant = property(_lasso.LibFederationTerminationNotification_issueInstant_get, _lasso.LibFederationTerminationNotification_issueInstant_set)
    __swig_setmethods__["majorVersion"] = _lasso.LibFederationTerminationNotification_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.LibFederationTerminationNotification_majorVersion_get
    if _newclass:majorVersion = property(_lasso.LibFederationTerminationNotification_majorVersion_get, _lasso.LibFederationTerminationNotification_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.LibFederationTerminationNotification_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.LibFederationTerminationNotification_minorVersion_get
    if _newclass:minorVersion = property(_lasso.LibFederationTerminationNotification_minorVersion_get, _lasso.LibFederationTerminationNotification_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.LibFederationTerminationNotification_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.LibFederationTerminationNotification_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.LibFederationTerminationNotification_privateKeyFile_get, _lasso.LibFederationTerminationNotification_privateKeyFile_set)
    __swig_setmethods__["requestId"] = _lasso.LibFederationTerminationNotification_requestId_set
    __swig_getmethods__["requestId"] = _lasso.LibFederationTerminationNotification_requestId_get
    if _newclass:requestId = property(_lasso.LibFederationTerminationNotification_requestId_get, _lasso.LibFederationTerminationNotification_requestId_set)
    __swig_setmethods__["respondWith"] = _lasso.LibFederationTerminationNotification_respondWith_set
    __swig_getmethods__["respondWith"] = _lasso.LibFederationTerminationNotification_respondWith_get
    if _newclass:respondWith = property(_lasso.LibFederationTerminationNotification_respondWith_get, _lasso.LibFederationTerminationNotification_respondWith_set)
    __swig_setmethods__["signMethod"] = _lasso.LibFederationTerminationNotification_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.LibFederationTerminationNotification_signMethod_get
    if _newclass:signMethod = property(_lasso.LibFederationTerminationNotification_signMethod_get, _lasso.LibFederationTerminationNotification_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.LibFederationTerminationNotification_signType_set
    __swig_getmethods__["signType"] = _lasso.LibFederationTerminationNotification_signType_get
    if _newclass:signType = property(_lasso.LibFederationTerminationNotification_signType_get, _lasso.LibFederationTerminationNotification_signType_set)
    __swig_setmethods__["extension"] = _lasso.LibFederationTerminationNotification_extension_set
    __swig_getmethods__["extension"] = _lasso.LibFederationTerminationNotification_extension_get
    if _newclass:extension = property(_lasso.LibFederationTerminationNotification_extension_get, _lasso.LibFederationTerminationNotification_extension_set)
    __swig_setmethods__["nameIdentifier"] = _lasso.LibFederationTerminationNotification_nameIdentifier_set
    __swig_getmethods__["nameIdentifier"] = _lasso.LibFederationTerminationNotification_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.LibFederationTerminationNotification_nameIdentifier_get, _lasso.LibFederationTerminationNotification_nameIdentifier_set)
    def __init__(self, *args):
        this = _lasso.new_LibFederationTerminationNotification(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibFederationTerminationNotification
    __del__ = lambda self : None;
    __swig_getmethods__["newFull"] = lambda x: _lasso.LibFederationTerminationNotification_newFull
    if _newclass:newFull = staticmethod(_lasso.LibFederationTerminationNotification_newFull)
    def dump(*args): return _lasso.LibFederationTerminationNotification_dump(*args)
_lasso.LibFederationTerminationNotification_swigregister(LibFederationTerminationNotification)

LibFederationTerminationNotification_newFull = _lasso.LibFederationTerminationNotification_newFull

class LibLogoutRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibLogoutRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibLogoutRequest, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibLogoutRequest instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["consent"] = _lasso.LibLogoutRequest_consent_set
    __swig_getmethods__["consent"] = _lasso.LibLogoutRequest_consent_get
    if _newclass:consent = property(_lasso.LibLogoutRequest_consent_get, _lasso.LibLogoutRequest_consent_set)
    __swig_setmethods__["notOnOrAfter"] = _lasso.LibLogoutRequest_notOnOrAfter_set
    __swig_getmethods__["notOnOrAfter"] = _lasso.LibLogoutRequest_notOnOrAfter_get
    if _newclass:notOnOrAfter = property(_lasso.LibLogoutRequest_notOnOrAfter_get, _lasso.LibLogoutRequest_notOnOrAfter_set)
    __swig_setmethods__["providerId"] = _lasso.LibLogoutRequest_providerId_set
    __swig_getmethods__["providerId"] = _lasso.LibLogoutRequest_providerId_get
    if _newclass:providerId = property(_lasso.LibLogoutRequest_providerId_get, _lasso.LibLogoutRequest_providerId_set)
    __swig_setmethods__["relayState"] = _lasso.LibLogoutRequest_relayState_set
    __swig_getmethods__["relayState"] = _lasso.LibLogoutRequest_relayState_get
    if _newclass:relayState = property(_lasso.LibLogoutRequest_relayState_get, _lasso.LibLogoutRequest_relayState_set)
    __swig_setmethods__["sessionIndex"] = _lasso.LibLogoutRequest_sessionIndex_set
    __swig_getmethods__["sessionIndex"] = _lasso.LibLogoutRequest_sessionIndex_get
    if _newclass:sessionIndex = property(_lasso.LibLogoutRequest_sessionIndex_get, _lasso.LibLogoutRequest_sessionIndex_set)
    __swig_setmethods__["certificateFile"] = _lasso.LibLogoutRequest_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.LibLogoutRequest_certificateFile_get
    if _newclass:certificateFile = property(_lasso.LibLogoutRequest_certificateFile_get, _lasso.LibLogoutRequest_certificateFile_set)
    __swig_setmethods__["issueInstant"] = _lasso.LibLogoutRequest_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.LibLogoutRequest_issueInstant_get
    if _newclass:issueInstant = property(_lasso.LibLogoutRequest_issueInstant_get, _lasso.LibLogoutRequest_issueInstant_set)
    __swig_setmethods__["majorVersion"] = _lasso.LibLogoutRequest_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.LibLogoutRequest_majorVersion_get
    if _newclass:majorVersion = property(_lasso.LibLogoutRequest_majorVersion_get, _lasso.LibLogoutRequest_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.LibLogoutRequest_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.LibLogoutRequest_minorVersion_get
    if _newclass:minorVersion = property(_lasso.LibLogoutRequest_minorVersion_get, _lasso.LibLogoutRequest_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.LibLogoutRequest_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.LibLogoutRequest_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.LibLogoutRequest_privateKeyFile_get, _lasso.LibLogoutRequest_privateKeyFile_set)
    __swig_setmethods__["requestId"] = _lasso.LibLogoutRequest_requestId_set
    __swig_getmethods__["requestId"] = _lasso.LibLogoutRequest_requestId_get
    if _newclass:requestId = property(_lasso.LibLogoutRequest_requestId_get, _lasso.LibLogoutRequest_requestId_set)
    __swig_setmethods__["respondWith"] = _lasso.LibLogoutRequest_respondWith_set
    __swig_getmethods__["respondWith"] = _lasso.LibLogoutRequest_respondWith_get
    if _newclass:respondWith = property(_lasso.LibLogoutRequest_respondWith_get, _lasso.LibLogoutRequest_respondWith_set)
    __swig_setmethods__["signMethod"] = _lasso.LibLogoutRequest_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.LibLogoutRequest_signMethod_get
    if _newclass:signMethod = property(_lasso.LibLogoutRequest_signMethod_get, _lasso.LibLogoutRequest_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.LibLogoutRequest_signType_set
    __swig_getmethods__["signType"] = _lasso.LibLogoutRequest_signType_get
    if _newclass:signType = property(_lasso.LibLogoutRequest_signType_get, _lasso.LibLogoutRequest_signType_set)
    __swig_setmethods__["extension"] = _lasso.LibLogoutRequest_extension_set
    __swig_getmethods__["extension"] = _lasso.LibLogoutRequest_extension_get
    if _newclass:extension = property(_lasso.LibLogoutRequest_extension_get, _lasso.LibLogoutRequest_extension_set)
    __swig_setmethods__["nameIdentifier"] = _lasso.LibLogoutRequest_nameIdentifier_set
    __swig_getmethods__["nameIdentifier"] = _lasso.LibLogoutRequest_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.LibLogoutRequest_nameIdentifier_get, _lasso.LibLogoutRequest_nameIdentifier_set)
    def __init__(self, *args):
        this = _lasso.new_LibLogoutRequest(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibLogoutRequest
    __del__ = lambda self : None;
    __swig_getmethods__["newFull"] = lambda x: _lasso.LibLogoutRequest_newFull
    if _newclass:newFull = staticmethod(_lasso.LibLogoutRequest_newFull)
    def dump(*args): return _lasso.LibLogoutRequest_dump(*args)
_lasso.LibLogoutRequest_swigregister(LibLogoutRequest)

LibLogoutRequest_newFull = _lasso.LibLogoutRequest_newFull

class LibLogoutResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibLogoutResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibLogoutResponse, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibLogoutResponse instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["extension"] = _lasso.LibLogoutResponse_extension_set
    __swig_getmethods__["extension"] = _lasso.LibLogoutResponse_extension_get
    if _newclass:extension = property(_lasso.LibLogoutResponse_extension_get, _lasso.LibLogoutResponse_extension_set)
    __swig_setmethods__["providerId"] = _lasso.LibLogoutResponse_providerId_set
    __swig_getmethods__["providerId"] = _lasso.LibLogoutResponse_providerId_get
    if _newclass:providerId = property(_lasso.LibLogoutResponse_providerId_get, _lasso.LibLogoutResponse_providerId_set)
    __swig_setmethods__["relayState"] = _lasso.LibLogoutResponse_relayState_set
    __swig_getmethods__["relayState"] = _lasso.LibLogoutResponse_relayState_get
    if _newclass:relayState = property(_lasso.LibLogoutResponse_relayState_get, _lasso.LibLogoutResponse_relayState_set)
    __swig_setmethods__["status"] = _lasso.LibLogoutResponse_status_set
    __swig_getmethods__["status"] = _lasso.LibLogoutResponse_status_get
    if _newclass:status = property(_lasso.LibLogoutResponse_status_get, _lasso.LibLogoutResponse_status_set)
    def __init__(self, *args):
        this = _lasso.new_LibLogoutResponse(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibLogoutResponse
    __del__ = lambda self : None;
    __swig_getmethods__["newFull"] = lambda x: _lasso.LibLogoutResponse_newFull
    if _newclass:newFull = staticmethod(_lasso.LibLogoutResponse_newFull)
    def dump(*args): return _lasso.LibLogoutResponse_dump(*args)
_lasso.LibLogoutResponse_swigregister(LibLogoutResponse)

LibLogoutResponse_newFull = _lasso.LibLogoutResponse_newFull

class LibRegisterNameIdentifierRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibRegisterNameIdentifierRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibRegisterNameIdentifierRequest, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibRegisterNameIdentifierRequest instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["providerId"] = _lasso.LibRegisterNameIdentifierRequest_providerId_set
    __swig_getmethods__["providerId"] = _lasso.LibRegisterNameIdentifierRequest_providerId_get
    if _newclass:providerId = property(_lasso.LibRegisterNameIdentifierRequest_providerId_get, _lasso.LibRegisterNameIdentifierRequest_providerId_set)
    __swig_setmethods__["relayState"] = _lasso.LibRegisterNameIdentifierRequest_relayState_set
    __swig_getmethods__["relayState"] = _lasso.LibRegisterNameIdentifierRequest_relayState_get
    if _newclass:relayState = property(_lasso.LibRegisterNameIdentifierRequest_relayState_get, _lasso.LibRegisterNameIdentifierRequest_relayState_set)
    __swig_setmethods__["certificateFile"] = _lasso.LibRegisterNameIdentifierRequest_certificateFile_set
    __swig_getmethods__["certificateFile"] = _lasso.LibRegisterNameIdentifierRequest_certificateFile_get
    if _newclass:certificateFile = property(_lasso.LibRegisterNameIdentifierRequest_certificateFile_get, _lasso.LibRegisterNameIdentifierRequest_certificateFile_set)
    __swig_setmethods__["issueInstant"] = _lasso.LibRegisterNameIdentifierRequest_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.LibRegisterNameIdentifierRequest_issueInstant_get
    if _newclass:issueInstant = property(_lasso.LibRegisterNameIdentifierRequest_issueInstant_get, _lasso.LibRegisterNameIdentifierRequest_issueInstant_set)
    __swig_setmethods__["majorVersion"] = _lasso.LibRegisterNameIdentifierRequest_majorVersion_set
    __swig_getmethods__["majorVersion"] = _lasso.LibRegisterNameIdentifierRequest_majorVersion_get
    if _newclass:majorVersion = property(_lasso.LibRegisterNameIdentifierRequest_majorVersion_get, _lasso.LibRegisterNameIdentifierRequest_majorVersion_set)
    __swig_setmethods__["minorVersion"] = _lasso.LibRegisterNameIdentifierRequest_minorVersion_set
    __swig_getmethods__["minorVersion"] = _lasso.LibRegisterNameIdentifierRequest_minorVersion_get
    if _newclass:minorVersion = property(_lasso.LibRegisterNameIdentifierRequest_minorVersion_get, _lasso.LibRegisterNameIdentifierRequest_minorVersion_set)
    __swig_setmethods__["privateKeyFile"] = _lasso.LibRegisterNameIdentifierRequest_privateKeyFile_set
    __swig_getmethods__["privateKeyFile"] = _lasso.LibRegisterNameIdentifierRequest_privateKeyFile_get
    if _newclass:privateKeyFile = property(_lasso.LibRegisterNameIdentifierRequest_privateKeyFile_get, _lasso.LibRegisterNameIdentifierRequest_privateKeyFile_set)
    __swig_setmethods__["requestId"] = _lasso.LibRegisterNameIdentifierRequest_requestId_set
    __swig_getmethods__["requestId"] = _lasso.LibRegisterNameIdentifierRequest_requestId_get
    if _newclass:requestId = property(_lasso.LibRegisterNameIdentifierRequest_requestId_get, _lasso.LibRegisterNameIdentifierRequest_requestId_set)
    __swig_setmethods__["respondWith"] = _lasso.LibRegisterNameIdentifierRequest_respondWith_set
    __swig_getmethods__["respondWith"] = _lasso.LibRegisterNameIdentifierRequest_respondWith_get
    if _newclass:respondWith = property(_lasso.LibRegisterNameIdentifierRequest_respondWith_get, _lasso.LibRegisterNameIdentifierRequest_respondWith_set)
    __swig_setmethods__["signMethod"] = _lasso.LibRegisterNameIdentifierRequest_signMethod_set
    __swig_getmethods__["signMethod"] = _lasso.LibRegisterNameIdentifierRequest_signMethod_get
    if _newclass:signMethod = property(_lasso.LibRegisterNameIdentifierRequest_signMethod_get, _lasso.LibRegisterNameIdentifierRequest_signMethod_set)
    __swig_setmethods__["signType"] = _lasso.LibRegisterNameIdentifierRequest_signType_set
    __swig_getmethods__["signType"] = _lasso.LibRegisterNameIdentifierRequest_signType_get
    if _newclass:signType = property(_lasso.LibRegisterNameIdentifierRequest_signType_get, _lasso.LibRegisterNameIdentifierRequest_signType_set)
    __swig_setmethods__["extension"] = _lasso.LibRegisterNameIdentifierRequest_extension_set
    __swig_getmethods__["extension"] = _lasso.LibRegisterNameIdentifierRequest_extension_get
    if _newclass:extension = property(_lasso.LibRegisterNameIdentifierRequest_extension_get, _lasso.LibRegisterNameIdentifierRequest_extension_set)
    __swig_setmethods__["idpProvidedNameIdentifier"] = _lasso.LibRegisterNameIdentifierRequest_idpProvidedNameIdentifier_set
    __swig_getmethods__["idpProvidedNameIdentifier"] = _lasso.LibRegisterNameIdentifierRequest_idpProvidedNameIdentifier_get
    if _newclass:idpProvidedNameIdentifier = property(_lasso.LibRegisterNameIdentifierRequest_idpProvidedNameIdentifier_get, _lasso.LibRegisterNameIdentifierRequest_idpProvidedNameIdentifier_set)
    __swig_setmethods__["oldProvidedNameIdentifier"] = _lasso.LibRegisterNameIdentifierRequest_oldProvidedNameIdentifier_set
    __swig_getmethods__["oldProvidedNameIdentifier"] = _lasso.LibRegisterNameIdentifierRequest_oldProvidedNameIdentifier_get
    if _newclass:oldProvidedNameIdentifier = property(_lasso.LibRegisterNameIdentifierRequest_oldProvidedNameIdentifier_get, _lasso.LibRegisterNameIdentifierRequest_oldProvidedNameIdentifier_set)
    __swig_setmethods__["spProvidedNameIdentifier"] = _lasso.LibRegisterNameIdentifierRequest_spProvidedNameIdentifier_set
    __swig_getmethods__["spProvidedNameIdentifier"] = _lasso.LibRegisterNameIdentifierRequest_spProvidedNameIdentifier_get
    if _newclass:spProvidedNameIdentifier = property(_lasso.LibRegisterNameIdentifierRequest_spProvidedNameIdentifier_get, _lasso.LibRegisterNameIdentifierRequest_spProvidedNameIdentifier_set)
    def __init__(self, *args):
        this = _lasso.new_LibRegisterNameIdentifierRequest(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibRegisterNameIdentifierRequest
    __del__ = lambda self : None;
    __swig_getmethods__["newFull"] = lambda x: _lasso.LibRegisterNameIdentifierRequest_newFull
    if _newclass:newFull = staticmethod(_lasso.LibRegisterNameIdentifierRequest_newFull)
    def dump(*args): return _lasso.LibRegisterNameIdentifierRequest_dump(*args)
_lasso.LibRegisterNameIdentifierRequest_swigregister(LibRegisterNameIdentifierRequest)

LibRegisterNameIdentifierRequest_newFull = _lasso.LibRegisterNameIdentifierRequest_newFull

class LibRegisterNameIdentifierResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibRegisterNameIdentifierResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibRegisterNameIdentifierResponse, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibRegisterNameIdentifierResponse instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["extension"] = _lasso.LibRegisterNameIdentifierResponse_extension_set
    __swig_getmethods__["extension"] = _lasso.LibRegisterNameIdentifierResponse_extension_get
    if _newclass:extension = property(_lasso.LibRegisterNameIdentifierResponse_extension_get, _lasso.LibRegisterNameIdentifierResponse_extension_set)
    __swig_setmethods__["providerId"] = _lasso.LibRegisterNameIdentifierResponse_providerId_set
    __swig_getmethods__["providerId"] = _lasso.LibRegisterNameIdentifierResponse_providerId_get
    if _newclass:providerId = property(_lasso.LibRegisterNameIdentifierResponse_providerId_get, _lasso.LibRegisterNameIdentifierResponse_providerId_set)
    __swig_setmethods__["relayState"] = _lasso.LibRegisterNameIdentifierResponse_relayState_set
    __swig_getmethods__["relayState"] = _lasso.LibRegisterNameIdentifierResponse_relayState_get
    if _newclass:relayState = property(_lasso.LibRegisterNameIdentifierResponse_relayState_get, _lasso.LibRegisterNameIdentifierResponse_relayState_set)
    __swig_setmethods__["status"] = _lasso.LibRegisterNameIdentifierResponse_status_set
    __swig_getmethods__["status"] = _lasso.LibRegisterNameIdentifierResponse_status_get
    if _newclass:status = property(_lasso.LibRegisterNameIdentifierResponse_status_get, _lasso.LibRegisterNameIdentifierResponse_status_set)
    def __init__(self, *args):
        this = _lasso.new_LibRegisterNameIdentifierResponse(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibRegisterNameIdentifierResponse
    __del__ = lambda self : None;
    __swig_getmethods__["newFull"] = lambda x: _lasso.LibRegisterNameIdentifierResponse_newFull
    if _newclass:newFull = staticmethod(_lasso.LibRegisterNameIdentifierResponse_newFull)
    def dump(*args): return _lasso.LibRegisterNameIdentifierResponse_dump(*args)
_lasso.LibRegisterNameIdentifierResponse_swigregister(LibRegisterNameIdentifierResponse)

LibRegisterNameIdentifierResponse_newFull = _lasso.LibRegisterNameIdentifierResponse_newFull

class LibRequestAuthnContext(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibRequestAuthnContext, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibRequestAuthnContext, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibRequestAuthnContext instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["authnContextComparison"] = _lasso.LibRequestAuthnContext_authnContextComparison_set
    __swig_getmethods__["authnContextComparison"] = _lasso.LibRequestAuthnContext_authnContextComparison_get
    if _newclass:authnContextComparison = property(_lasso.LibRequestAuthnContext_authnContextComparison_get, _lasso.LibRequestAuthnContext_authnContextComparison_set)
    __swig_setmethods__["authnContextClassRef"] = _lasso.LibRequestAuthnContext_authnContextClassRef_set
    __swig_getmethods__["authnContextClassRef"] = _lasso.LibRequestAuthnContext_authnContextClassRef_get
    if _newclass:authnContextClassRef = property(_lasso.LibRequestAuthnContext_authnContextClassRef_get, _lasso.LibRequestAuthnContext_authnContextClassRef_set)
    __swig_setmethods__["authnContextStatementRef"] = _lasso.LibRequestAuthnContext_authnContextStatementRef_set
    __swig_getmethods__["authnContextStatementRef"] = _lasso.LibRequestAuthnContext_authnContextStatementRef_get
    if _newclass:authnContextStatementRef = property(_lasso.LibRequestAuthnContext_authnContextStatementRef_get, _lasso.LibRequestAuthnContext_authnContextStatementRef_set)
    def __init__(self, *args):
        this = _lasso.new_LibRequestAuthnContext(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibRequestAuthnContext
    __del__ = lambda self : None;
    def dump(*args): return _lasso.LibRequestAuthnContext_dump(*args)
_lasso.LibRequestAuthnContext_swigregister(LibRequestAuthnContext)

class LibStatusResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LibStatusResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LibStatusResponse, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLibStatusResponse instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["providerId"] = _lasso.LibStatusResponse_providerId_set
    __swig_getmethods__["providerId"] = _lasso.LibStatusResponse_providerId_get
    if _newclass:providerId = property(_lasso.LibStatusResponse_providerId_get, _lasso.LibStatusResponse_providerId_set)
    __swig_setmethods__["relayState"] = _lasso.LibStatusResponse_relayState_set
    __swig_getmethods__["relayState"] = _lasso.LibStatusResponse_relayState_get
    if _newclass:relayState = property(_lasso.LibStatusResponse_relayState_get, _lasso.LibStatusResponse_relayState_set)
    __swig_setmethods__["extension"] = _lasso.LibStatusResponse_extension_set
    __swig_getmethods__["extension"] = _lasso.LibStatusResponse_extension_get
    if _newclass:extension = property(_lasso.LibStatusResponse_extension_get, _lasso.LibStatusResponse_extension_set)
    __swig_setmethods__["status"] = _lasso.LibStatusResponse_status_set
    __swig_getmethods__["status"] = _lasso.LibStatusResponse_status_get
    if _newclass:status = property(_lasso.LibStatusResponse_status_get, _lasso.LibStatusResponse_status_set)
    def __init__(self, *args):
        this = _lasso.new_LibStatusResponse(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_LibStatusResponse
    __del__ = lambda self : None;
    def dump(*args): return _lasso.LibStatusResponse_dump(*args)
_lasso.LibStatusResponse_swigregister(LibStatusResponse)

class Provider(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Provider, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Provider, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoProvider instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["caCertChain"] = _lasso.Provider_caCertChain_set
    __swig_getmethods__["caCertChain"] = _lasso.Provider_caCertChain_get
    if _newclass:caCertChain = property(_lasso.Provider_caCertChain_get, _lasso.Provider_caCertChain_set)
    __swig_setmethods__["metadataFilename"] = _lasso.Provider_metadataFilename_set
    __swig_getmethods__["metadataFilename"] = _lasso.Provider_metadataFilename_get
    if _newclass:metadataFilename = property(_lasso.Provider_metadataFilename_get, _lasso.Provider_metadataFilename_set)
    __swig_setmethods__["providerId"] = _lasso.Provider_providerId_set
    __swig_getmethods__["providerId"] = _lasso.Provider_providerId_get
    if _newclass:providerId = property(_lasso.Provider_providerId_get, _lasso.Provider_providerId_set)
    __swig_setmethods__["publicKey"] = _lasso.Provider_publicKey_set
    __swig_getmethods__["publicKey"] = _lasso.Provider_publicKey_get
    if _newclass:publicKey = property(_lasso.Provider_publicKey_get, _lasso.Provider_publicKey_set)
    __swig_setmethods__["role"] = _lasso.Provider_role_set
    __swig_getmethods__["role"] = _lasso.Provider_role_get
    if _newclass:role = property(_lasso.Provider_role_get, _lasso.Provider_role_set)
    def __init__(self, *args):
        this = _lasso.new_Provider(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Provider
    __del__ = lambda self : None;
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Provider_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Provider_newFromDump)
    def dump(*args): return _lasso.Provider_dump(*args)
    def acceptHttpMethod(*args): return _lasso.Provider_acceptHttpMethod(*args)
    def getAssertionConsumerServiceUrl(*args): return _lasso.Provider_getAssertionConsumerServiceUrl(*args)
    def getBase64SuccinctId(*args): return _lasso.Provider_getBase64SuccinctId(*args)
    def getOrganization(*args): return _lasso.Provider_getOrganization(*args)
    def getFirstHttpMethod(*args): return _lasso.Provider_getFirstHttpMethod(*args)
    def getMetadataOne(*args): return _lasso.Provider_getMetadataOne(*args)
    def hasProtocolProfile(*args): return _lasso.Provider_hasProtocolProfile(*args)
    def getProtocolConformance(*args): return _lasso.Provider_getProtocolConformance(*args)
_lasso.Provider_swigregister(Provider)

Provider_newFromDump = _lasso.Provider_newFromDump

class Server(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Server, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Server, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoServer instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["certificate"] = _lasso.Server_certificate_set
    __swig_getmethods__["certificate"] = _lasso.Server_certificate_get
    if _newclass:certificate = property(_lasso.Server_certificate_get, _lasso.Server_certificate_set)
    __swig_setmethods__["privateKey"] = _lasso.Server_privateKey_set
    __swig_getmethods__["privateKey"] = _lasso.Server_privateKey_get
    if _newclass:privateKey = property(_lasso.Server_privateKey_get, _lasso.Server_privateKey_set)
    __swig_setmethods__["privateKeyPassword"] = _lasso.Server_privateKeyPassword_set
    __swig_getmethods__["privateKeyPassword"] = _lasso.Server_privateKeyPassword_get
    if _newclass:privateKeyPassword = property(_lasso.Server_privateKeyPassword_get, _lasso.Server_privateKeyPassword_set)
    __swig_setmethods__["signatureMethod"] = _lasso.Server_signatureMethod_set
    __swig_getmethods__["signatureMethod"] = _lasso.Server_signatureMethod_get
    if _newclass:signatureMethod = property(_lasso.Server_signatureMethod_get, _lasso.Server_signatureMethod_set)
    __swig_setmethods__["caCertChain"] = _lasso.Server_caCertChain_set
    __swig_getmethods__["caCertChain"] = _lasso.Server_caCertChain_get
    if _newclass:caCertChain = property(_lasso.Server_caCertChain_get, _lasso.Server_caCertChain_set)
    __swig_setmethods__["metadataFilename"] = _lasso.Server_metadataFilename_set
    __swig_getmethods__["metadataFilename"] = _lasso.Server_metadataFilename_get
    if _newclass:metadataFilename = property(_lasso.Server_metadataFilename_get, _lasso.Server_metadataFilename_set)
    __swig_setmethods__["providerId"] = _lasso.Server_providerId_set
    __swig_getmethods__["providerId"] = _lasso.Server_providerId_get
    if _newclass:providerId = property(_lasso.Server_providerId_get, _lasso.Server_providerId_set)
    __swig_setmethods__["publicKey"] = _lasso.Server_publicKey_set
    __swig_getmethods__["publicKey"] = _lasso.Server_publicKey_get
    if _newclass:publicKey = property(_lasso.Server_publicKey_get, _lasso.Server_publicKey_set)
    __swig_setmethods__["role"] = _lasso.Server_role_set
    __swig_getmethods__["role"] = _lasso.Server_role_get
    if _newclass:role = property(_lasso.Server_role_get, _lasso.Server_role_set)
    __swig_getmethods__["providerIds"] = _lasso.Server_providerIds_get
    if _newclass:providerIds = property(_lasso.Server_providerIds_get)
    def __init__(self, *args):
        this = _lasso.new_Server(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Server
    __del__ = lambda self : None;
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Server_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Server_newFromDump)
    def acceptHttpMethod(*args): return _lasso.Server_acceptHttpMethod(*args)
    def getAssertionConsumerServiceUrl(*args): return _lasso.Server_getAssertionConsumerServiceUrl(*args)
    def getBase64SuccinctId(*args): return _lasso.Server_getBase64SuccinctId(*args)
    def getOrganization(*args): return _lasso.Server_getOrganization(*args)
    def getFirstHttpMethod(*args): return _lasso.Server_getFirstHttpMethod(*args)
    def getMetadataOne(*args): return _lasso.Server_getMetadataOne(*args)
    def hasProtocolProfile(*args): return _lasso.Server_hasProtocolProfile(*args)
    def getProtocolConformance(*args): return _lasso.Server_getProtocolConformance(*args)
    def addProvider(*args): return _lasso.Server_addProvider(*args)
    def dump(*args): return _lasso.Server_dump(*args)
    def getProvider(*args): return _lasso.Server_getProvider(*args)
_lasso.Server_swigregister(Server)

Server_newFromDump = _lasso.Server_newFromDump

class Federation(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Federation, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Federation, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoFederation instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["remoteProviderId"] = _lasso.Federation_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.Federation_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.Federation_remoteProviderId_get, _lasso.Federation_remoteProviderId_set)
    __swig_setmethods__["localNameIdentifier"] = _lasso.Federation_localNameIdentifier_set
    __swig_getmethods__["localNameIdentifier"] = _lasso.Federation_localNameIdentifier_get
    if _newclass:localNameIdentifier = property(_lasso.Federation_localNameIdentifier_get, _lasso.Federation_localNameIdentifier_set)
    __swig_setmethods__["remoteNameIdentifier"] = _lasso.Federation_remoteNameIdentifier_set
    __swig_getmethods__["remoteNameIdentifier"] = _lasso.Federation_remoteNameIdentifier_get
    if _newclass:remoteNameIdentifier = property(_lasso.Federation_remoteNameIdentifier_get, _lasso.Federation_remoteNameIdentifier_set)
    def __init__(self, *args):
        this = _lasso.new_Federation(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Federation
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Federation_dump(*args)
    def buildLocalNameIdentifier(*args): return _lasso.Federation_buildLocalNameIdentifier(*args)
    def verifyNameIdentifier(*args): return _lasso.Federation_verifyNameIdentifier(*args)
_lasso.Federation_swigregister(Federation)

class Identity(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Identity, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Identity, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoIdentity instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_getmethods__["isDirty"] = _lasso.Identity_isDirty_get
    if _newclass:isDirty = property(_lasso.Identity_isDirty_get)
    __swig_getmethods__["providerIds"] = _lasso.Identity_providerIds_get
    if _newclass:providerIds = property(_lasso.Identity_providerIds_get)
    def __init__(self, *args):
        this = _lasso.new_Identity(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Identity
    __del__ = lambda self : None;
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Identity_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Identity_newFromDump)
    def dump(*args): return _lasso.Identity_dump(*args)
    def getFederation(*args): return _lasso.Identity_getFederation(*args)
_lasso.Identity_swigregister(Identity)

Identity_newFromDump = _lasso.Identity_newFromDump

class Session(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Session, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Session, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSession instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_getmethods__["isDirty"] = _lasso.Session_isDirty_get
    if _newclass:isDirty = property(_lasso.Session_isDirty_get)
    __swig_getmethods__["providerIds"] = _lasso.Session_providerIds_get
    if _newclass:providerIds = property(_lasso.Session_providerIds_get)
    def __init__(self, *args):
        this = _lasso.new_Session(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Session
    __del__ = lambda self : None;
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Session_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Session_newFromDump)
    def dump(*args): return _lasso.Session_dump(*args)
    def getAssertions(*args): return _lasso.Session_getAssertions(*args)
_lasso.Session_swigregister(Session)

Session_newFromDump = _lasso.Session_newFromDump


getRequestTypeFromSoapMsg = _lasso.getRequestTypeFromSoapMsg

isLibertyQuery = _lasso.isLibertyQuery
class Defederation(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Defederation, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Defederation, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoDefederation instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_getmethods__["artifact"] = _lasso.Defederation_artifact_get
    if _newclass:artifact = property(_lasso.Defederation_artifact_get)
    __swig_setmethods__["artifactMessage"] = _lasso.Defederation_artifactMessage_set
    __swig_getmethods__["artifactMessage"] = _lasso.Defederation_artifactMessage_get
    if _newclass:artifactMessage = property(_lasso.Defederation_artifactMessage_get, _lasso.Defederation_artifactMessage_set)
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
    __swig_setmethods__["nameIdentifier"] = _lasso.Defederation_nameIdentifier_set
    __swig_getmethods__["nameIdentifier"] = _lasso.Defederation_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.Defederation_nameIdentifier_get, _lasso.Defederation_nameIdentifier_set)
    __swig_setmethods__["remoteProviderId"] = _lasso.Defederation_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.Defederation_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.Defederation_remoteProviderId_get, _lasso.Defederation_remoteProviderId_set)
    __swig_setmethods__["request"] = _lasso.Defederation_request_set
    __swig_getmethods__["request"] = _lasso.Defederation_request_get
    if _newclass:request = property(_lasso.Defederation_request_get, _lasso.Defederation_request_set)
    __swig_setmethods__["response"] = _lasso.Defederation_response_set
    __swig_getmethods__["response"] = _lasso.Defederation_response_get
    if _newclass:response = property(_lasso.Defederation_response_get, _lasso.Defederation_response_set)
    __swig_setmethods__["server"] = _lasso.Defederation_server_set
    __swig_getmethods__["server"] = _lasso.Defederation_server_get
    if _newclass:server = property(_lasso.Defederation_server_get, _lasso.Defederation_server_set)
    __swig_setmethods__["session"] = _lasso.Defederation_session_set
    __swig_getmethods__["session"] = _lasso.Defederation_session_get
    if _newclass:session = property(_lasso.Defederation_session_get, _lasso.Defederation_session_set)
    def __init__(self, *args):
        this = _lasso.new_Defederation(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Defederation
    __del__ = lambda self : None;
    def setIdentityFromDump(*args): return _lasso.Defederation_setIdentityFromDump(*args)
    def setSessionFromDump(*args): return _lasso.Defederation_setSessionFromDump(*args)
    def buildNotificationMsg(*args): return _lasso.Defederation_buildNotificationMsg(*args)
    def initNotification(*args): return _lasso.Defederation_initNotification(*args)
    def processNotificationMsg(*args): return _lasso.Defederation_processNotificationMsg(*args)
    def validateNotification(*args): return _lasso.Defederation_validateNotification(*args)
_lasso.Defederation_swigregister(Defederation)

class Login(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Login, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Login, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLogin instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_getmethods__["assertionArtifact"] = _lasso.Login_assertionArtifact_get
    if _newclass:assertionArtifact = property(_lasso.Login_assertionArtifact_get)
    __swig_getmethods__["protocolProfile"] = _lasso.Login_protocolProfile_get
    if _newclass:protocolProfile = property(_lasso.Login_protocolProfile_get)
    __swig_getmethods__["artifact"] = _lasso.Login_artifact_get
    if _newclass:artifact = property(_lasso.Login_artifact_get)
    __swig_setmethods__["artifactMessage"] = _lasso.Login_artifactMessage_set
    __swig_getmethods__["artifactMessage"] = _lasso.Login_artifactMessage_get
    if _newclass:artifactMessage = property(_lasso.Login_artifactMessage_get, _lasso.Login_artifactMessage_set)
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
    __swig_setmethods__["nameIdentifier"] = _lasso.Login_nameIdentifier_set
    __swig_getmethods__["nameIdentifier"] = _lasso.Login_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.Login_nameIdentifier_get, _lasso.Login_nameIdentifier_set)
    __swig_setmethods__["remoteProviderId"] = _lasso.Login_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.Login_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.Login_remoteProviderId_get, _lasso.Login_remoteProviderId_set)
    __swig_setmethods__["request"] = _lasso.Login_request_set
    __swig_getmethods__["request"] = _lasso.Login_request_get
    if _newclass:request = property(_lasso.Login_request_get, _lasso.Login_request_set)
    __swig_setmethods__["response"] = _lasso.Login_response_set
    __swig_getmethods__["response"] = _lasso.Login_response_get
    if _newclass:response = property(_lasso.Login_response_get, _lasso.Login_response_set)
    __swig_setmethods__["server"] = _lasso.Login_server_set
    __swig_getmethods__["server"] = _lasso.Login_server_get
    if _newclass:server = property(_lasso.Login_server_get, _lasso.Login_server_set)
    __swig_setmethods__["session"] = _lasso.Login_session_set
    __swig_getmethods__["session"] = _lasso.Login_session_get
    if _newclass:session = property(_lasso.Login_session_get, _lasso.Login_session_set)
    def __init__(self, *args):
        this = _lasso.new_Login(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Login
    __del__ = lambda self : None;
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.Login_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.Login_newFromDump)
    def setIdentityFromDump(*args): return _lasso.Login_setIdentityFromDump(*args)
    def setSessionFromDump(*args): return _lasso.Login_setSessionFromDump(*args)
    def acceptSso(*args): return _lasso.Login_acceptSso(*args)
    def buildArtifactMsg(*args): return _lasso.Login_buildArtifactMsg(*args)
    def buildAssertion(*args): return _lasso.Login_buildAssertion(*args)
    def buildAuthnRequestMsg(*args): return _lasso.Login_buildAuthnRequestMsg(*args)
    def buildAuthnResponseMsg(*args): return _lasso.Login_buildAuthnResponseMsg(*args)
    def buildRequestMsg(*args): return _lasso.Login_buildRequestMsg(*args)
    def buildResponseMsg(*args): return _lasso.Login_buildResponseMsg(*args)
    def dump(*args): return _lasso.Login_dump(*args)
    def initAuthnRequest(*args): return _lasso.Login_initAuthnRequest(*args)
    def initRequest(*args): return _lasso.Login_initRequest(*args)
    def initIdpInitiatedAuthnRequest(*args): return _lasso.Login_initIdpInitiatedAuthnRequest(*args)
    def mustAskForConsent(*args): return _lasso.Login_mustAskForConsent(*args)
    def mustAuthenticate(*args): return _lasso.Login_mustAuthenticate(*args)
    def processAuthnRequestMsg(*args): return _lasso.Login_processAuthnRequestMsg(*args)
    def processAuthnResponseMsg(*args): return _lasso.Login_processAuthnResponseMsg(*args)
    def processRequestMsg(*args): return _lasso.Login_processRequestMsg(*args)
    def processResponseMsg(*args): return _lasso.Login_processResponseMsg(*args)
    def setResourceId(*args): return _lasso.Login_setResourceId(*args)
    def validateRequestMsg(*args): return _lasso.Login_validateRequestMsg(*args)
_lasso.Login_swigregister(Login)

Login_newFromDump = _lasso.Login_newFromDump

class Logout(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Logout, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Logout, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLogout instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_getmethods__["artifact"] = _lasso.Logout_artifact_get
    if _newclass:artifact = property(_lasso.Logout_artifact_get)
    __swig_setmethods__["artifactMessage"] = _lasso.Logout_artifactMessage_set
    __swig_getmethods__["artifactMessage"] = _lasso.Logout_artifactMessage_get
    if _newclass:artifactMessage = property(_lasso.Logout_artifactMessage_get, _lasso.Logout_artifactMessage_set)
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
    __swig_setmethods__["nameIdentifier"] = _lasso.Logout_nameIdentifier_set
    __swig_getmethods__["nameIdentifier"] = _lasso.Logout_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.Logout_nameIdentifier_get, _lasso.Logout_nameIdentifier_set)
    __swig_setmethods__["remoteProviderId"] = _lasso.Logout_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.Logout_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.Logout_remoteProviderId_get, _lasso.Logout_remoteProviderId_set)
    __swig_setmethods__["request"] = _lasso.Logout_request_set
    __swig_getmethods__["request"] = _lasso.Logout_request_get
    if _newclass:request = property(_lasso.Logout_request_get, _lasso.Logout_request_set)
    __swig_setmethods__["response"] = _lasso.Logout_response_set
    __swig_getmethods__["response"] = _lasso.Logout_response_get
    if _newclass:response = property(_lasso.Logout_response_get, _lasso.Logout_response_set)
    __swig_setmethods__["server"] = _lasso.Logout_server_set
    __swig_getmethods__["server"] = _lasso.Logout_server_get
    if _newclass:server = property(_lasso.Logout_server_get, _lasso.Logout_server_set)
    __swig_setmethods__["session"] = _lasso.Logout_session_set
    __swig_getmethods__["session"] = _lasso.Logout_session_get
    if _newclass:session = property(_lasso.Logout_session_get, _lasso.Logout_session_set)
    def __init__(self, *args):
        this = _lasso.new_Logout(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Logout
    __del__ = lambda self : None;
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
_lasso.Logout_swigregister(Logout)

Logout_newFromDump = _lasso.Logout_newFromDump

class Lecp(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Lecp, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Lecp, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoLecp instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_getmethods__["artifact"] = _lasso.Lecp_artifact_get
    if _newclass:artifact = property(_lasso.Lecp_artifact_get)
    __swig_setmethods__["artifactMessage"] = _lasso.Lecp_artifactMessage_set
    __swig_getmethods__["artifactMessage"] = _lasso.Lecp_artifactMessage_get
    if _newclass:artifactMessage = property(_lasso.Lecp_artifactMessage_get, _lasso.Lecp_artifactMessage_set)
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
    __swig_setmethods__["nameIdentifier"] = _lasso.Lecp_nameIdentifier_set
    __swig_getmethods__["nameIdentifier"] = _lasso.Lecp_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.Lecp_nameIdentifier_get, _lasso.Lecp_nameIdentifier_set)
    __swig_setmethods__["remoteProviderId"] = _lasso.Lecp_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.Lecp_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.Lecp_remoteProviderId_get, _lasso.Lecp_remoteProviderId_set)
    __swig_setmethods__["request"] = _lasso.Lecp_request_set
    __swig_getmethods__["request"] = _lasso.Lecp_request_get
    if _newclass:request = property(_lasso.Lecp_request_get, _lasso.Lecp_request_set)
    __swig_setmethods__["response"] = _lasso.Lecp_response_set
    __swig_getmethods__["response"] = _lasso.Lecp_response_get
    if _newclass:response = property(_lasso.Lecp_response_get, _lasso.Lecp_response_set)
    __swig_setmethods__["server"] = _lasso.Lecp_server_set
    __swig_getmethods__["server"] = _lasso.Lecp_server_get
    if _newclass:server = property(_lasso.Lecp_server_get, _lasso.Lecp_server_set)
    __swig_setmethods__["session"] = _lasso.Lecp_session_set
    __swig_getmethods__["session"] = _lasso.Lecp_session_get
    if _newclass:session = property(_lasso.Lecp_session_get, _lasso.Lecp_session_set)
    def __init__(self, *args):
        this = _lasso.new_Lecp(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Lecp
    __del__ = lambda self : None;
    def setIdentityFromDump(*args): return _lasso.Lecp_setIdentityFromDump(*args)
    def setSessionFromDump(*args): return _lasso.Lecp_setSessionFromDump(*args)
    def buildAssertion(*args): return _lasso.Lecp_buildAssertion(*args)
    def setResourceId(*args): return _lasso.Lecp_setResourceId(*args)
    def validateRequestMsg(*args): return _lasso.Lecp_validateRequestMsg(*args)
    def buildAuthnRequestEnvelopeMsg(*args): return _lasso.Lecp_buildAuthnRequestEnvelopeMsg(*args)
    def buildAuthnRequestMsg(*args): return _lasso.Lecp_buildAuthnRequestMsg(*args)
    def buildAuthnResponseEnvelopeMsg(*args): return _lasso.Lecp_buildAuthnResponseEnvelopeMsg(*args)
    def buildAuthnResponseMsg(*args): return _lasso.Lecp_buildAuthnResponseMsg(*args)
    def initAuthnRequest(*args): return _lasso.Lecp_initAuthnRequest(*args)
    def processAuthnRequestEnvelopeMsg(*args): return _lasso.Lecp_processAuthnRequestEnvelopeMsg(*args)
    def processAuthnRequestMsg(*args): return _lasso.Lecp_processAuthnRequestMsg(*args)
    def processAuthnResponseEnvelopeMsg(*args): return _lasso.Lecp_processAuthnResponseEnvelopeMsg(*args)
_lasso.Lecp_swigregister(Lecp)

class NameIdentifierMapping(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, NameIdentifierMapping, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, NameIdentifierMapping, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoNameIdentifierMapping instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_getmethods__["targetNameIdentifier"] = _lasso.NameIdentifierMapping_targetNameIdentifier_get
    if _newclass:targetNameIdentifier = property(_lasso.NameIdentifierMapping_targetNameIdentifier_get)
    __swig_getmethods__["artifact"] = _lasso.NameIdentifierMapping_artifact_get
    if _newclass:artifact = property(_lasso.NameIdentifierMapping_artifact_get)
    __swig_setmethods__["artifactMessage"] = _lasso.NameIdentifierMapping_artifactMessage_set
    __swig_getmethods__["artifactMessage"] = _lasso.NameIdentifierMapping_artifactMessage_get
    if _newclass:artifactMessage = property(_lasso.NameIdentifierMapping_artifactMessage_get, _lasso.NameIdentifierMapping_artifactMessage_set)
    __swig_setmethods__["identity"] = _lasso.NameIdentifierMapping_identity_set
    __swig_getmethods__["identity"] = _lasso.NameIdentifierMapping_identity_get
    if _newclass:identity = property(_lasso.NameIdentifierMapping_identity_get, _lasso.NameIdentifierMapping_identity_set)
    __swig_getmethods__["isIdentityDirty"] = _lasso.NameIdentifierMapping_isIdentityDirty_get
    if _newclass:isIdentityDirty = property(_lasso.NameIdentifierMapping_isIdentityDirty_get)
    __swig_getmethods__["isSessionDirty"] = _lasso.NameIdentifierMapping_isSessionDirty_get
    if _newclass:isSessionDirty = property(_lasso.NameIdentifierMapping_isSessionDirty_get)
    __swig_getmethods__["msgBody"] = _lasso.NameIdentifierMapping_msgBody_get
    if _newclass:msgBody = property(_lasso.NameIdentifierMapping_msgBody_get)
    __swig_getmethods__["msgUrl"] = _lasso.NameIdentifierMapping_msgUrl_get
    if _newclass:msgUrl = property(_lasso.NameIdentifierMapping_msgUrl_get)
    __swig_setmethods__["nameIdentifier"] = _lasso.NameIdentifierMapping_nameIdentifier_set
    __swig_getmethods__["nameIdentifier"] = _lasso.NameIdentifierMapping_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.NameIdentifierMapping_nameIdentifier_get, _lasso.NameIdentifierMapping_nameIdentifier_set)
    __swig_setmethods__["remoteProviderId"] = _lasso.NameIdentifierMapping_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.NameIdentifierMapping_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.NameIdentifierMapping_remoteProviderId_get, _lasso.NameIdentifierMapping_remoteProviderId_set)
    __swig_setmethods__["request"] = _lasso.NameIdentifierMapping_request_set
    __swig_getmethods__["request"] = _lasso.NameIdentifierMapping_request_get
    if _newclass:request = property(_lasso.NameIdentifierMapping_request_get, _lasso.NameIdentifierMapping_request_set)
    __swig_setmethods__["response"] = _lasso.NameIdentifierMapping_response_set
    __swig_getmethods__["response"] = _lasso.NameIdentifierMapping_response_get
    if _newclass:response = property(_lasso.NameIdentifierMapping_response_get, _lasso.NameIdentifierMapping_response_set)
    __swig_setmethods__["server"] = _lasso.NameIdentifierMapping_server_set
    __swig_getmethods__["server"] = _lasso.NameIdentifierMapping_server_get
    if _newclass:server = property(_lasso.NameIdentifierMapping_server_get, _lasso.NameIdentifierMapping_server_set)
    __swig_setmethods__["session"] = _lasso.NameIdentifierMapping_session_set
    __swig_getmethods__["session"] = _lasso.NameIdentifierMapping_session_get
    if _newclass:session = property(_lasso.NameIdentifierMapping_session_get, _lasso.NameIdentifierMapping_session_set)
    def __init__(self, *args):
        this = _lasso.new_NameIdentifierMapping(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_NameIdentifierMapping
    __del__ = lambda self : None;
    def setIdentityFromDump(*args): return _lasso.NameIdentifierMapping_setIdentityFromDump(*args)
    def setSessionFromDump(*args): return _lasso.NameIdentifierMapping_setSessionFromDump(*args)
    def buildRequestMsg(*args): return _lasso.NameIdentifierMapping_buildRequestMsg(*args)
    def buildResponseMsg(*args): return _lasso.NameIdentifierMapping_buildResponseMsg(*args)
    def initRequest(*args): return _lasso.NameIdentifierMapping_initRequest(*args)
    def processRequestMsg(*args): return _lasso.NameIdentifierMapping_processRequestMsg(*args)
    def processResponseMsg(*args): return _lasso.NameIdentifierMapping_processResponseMsg(*args)
    def validateRequest(*args): return _lasso.NameIdentifierMapping_validateRequest(*args)
_lasso.NameIdentifierMapping_swigregister(NameIdentifierMapping)

class NameRegistration(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, NameRegistration, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, NameRegistration, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoNameRegistration instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_getmethods__["artifact"] = _lasso.NameRegistration_artifact_get
    if _newclass:artifact = property(_lasso.NameRegistration_artifact_get)
    __swig_setmethods__["artifactMessage"] = _lasso.NameRegistration_artifactMessage_set
    __swig_getmethods__["artifactMessage"] = _lasso.NameRegistration_artifactMessage_get
    if _newclass:artifactMessage = property(_lasso.NameRegistration_artifactMessage_get, _lasso.NameRegistration_artifactMessage_set)
    __swig_setmethods__["identity"] = _lasso.NameRegistration_identity_set
    __swig_getmethods__["identity"] = _lasso.NameRegistration_identity_get
    if _newclass:identity = property(_lasso.NameRegistration_identity_get, _lasso.NameRegistration_identity_set)
    __swig_getmethods__["isIdentityDirty"] = _lasso.NameRegistration_isIdentityDirty_get
    if _newclass:isIdentityDirty = property(_lasso.NameRegistration_isIdentityDirty_get)
    __swig_getmethods__["isSessionDirty"] = _lasso.NameRegistration_isSessionDirty_get
    if _newclass:isSessionDirty = property(_lasso.NameRegistration_isSessionDirty_get)
    __swig_getmethods__["msgBody"] = _lasso.NameRegistration_msgBody_get
    if _newclass:msgBody = property(_lasso.NameRegistration_msgBody_get)
    __swig_getmethods__["msgRelayState"] = _lasso.NameRegistration_msgRelayState_get
    if _newclass:msgRelayState = property(_lasso.NameRegistration_msgRelayState_get)
    __swig_getmethods__["msgUrl"] = _lasso.NameRegistration_msgUrl_get
    if _newclass:msgUrl = property(_lasso.NameRegistration_msgUrl_get)
    __swig_setmethods__["nameIdentifier"] = _lasso.NameRegistration_nameIdentifier_set
    __swig_getmethods__["nameIdentifier"] = _lasso.NameRegistration_nameIdentifier_get
    if _newclass:nameIdentifier = property(_lasso.NameRegistration_nameIdentifier_get, _lasso.NameRegistration_nameIdentifier_set)
    __swig_setmethods__["remoteProviderId"] = _lasso.NameRegistration_remoteProviderId_set
    __swig_getmethods__["remoteProviderId"] = _lasso.NameRegistration_remoteProviderId_get
    if _newclass:remoteProviderId = property(_lasso.NameRegistration_remoteProviderId_get, _lasso.NameRegistration_remoteProviderId_set)
    __swig_setmethods__["request"] = _lasso.NameRegistration_request_set
    __swig_getmethods__["request"] = _lasso.NameRegistration_request_get
    if _newclass:request = property(_lasso.NameRegistration_request_get, _lasso.NameRegistration_request_set)
    __swig_setmethods__["response"] = _lasso.NameRegistration_response_set
    __swig_getmethods__["response"] = _lasso.NameRegistration_response_get
    if _newclass:response = property(_lasso.NameRegistration_response_get, _lasso.NameRegistration_response_set)
    __swig_setmethods__["server"] = _lasso.NameRegistration_server_set
    __swig_getmethods__["server"] = _lasso.NameRegistration_server_get
    if _newclass:server = property(_lasso.NameRegistration_server_get, _lasso.NameRegistration_server_set)
    __swig_setmethods__["session"] = _lasso.NameRegistration_session_set
    __swig_getmethods__["session"] = _lasso.NameRegistration_session_get
    if _newclass:session = property(_lasso.NameRegistration_session_get, _lasso.NameRegistration_session_set)
    __swig_setmethods__["oldNameIdentifier"] = _lasso.NameRegistration_oldNameIdentifier_set
    __swig_getmethods__["oldNameIdentifier"] = _lasso.NameRegistration_oldNameIdentifier_get
    if _newclass:oldNameIdentifier = property(_lasso.NameRegistration_oldNameIdentifier_get, _lasso.NameRegistration_oldNameIdentifier_set)
    def __init__(self, *args):
        this = _lasso.new_NameRegistration(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_NameRegistration
    __del__ = lambda self : None;
    __swig_getmethods__["newFromDump"] = lambda x: _lasso.NameRegistration_newFromDump
    if _newclass:newFromDump = staticmethod(_lasso.NameRegistration_newFromDump)
    def setIdentityFromDump(*args): return _lasso.NameRegistration_setIdentityFromDump(*args)
    def setSessionFromDump(*args): return _lasso.NameRegistration_setSessionFromDump(*args)
    def buildRequestMsg(*args): return _lasso.NameRegistration_buildRequestMsg(*args)
    def buildResponseMsg(*args): return _lasso.NameRegistration_buildResponseMsg(*args)
    def dump(*args): return _lasso.NameRegistration_dump(*args)
    def initRequest(*args): return _lasso.NameRegistration_initRequest(*args)
    def processRequestMsg(*args): return _lasso.NameRegistration_processRequestMsg(*args)
    def processResponseMsg(*args): return _lasso.NameRegistration_processResponseMsg(*args)
    def validateRequest(*args): return _lasso.NameRegistration_validateRequest(*args)
_lasso.NameRegistration_swigregister(NameRegistration)

NameRegistration_newFromDump = _lasso.NameRegistration_newFromDump

class Samlp2NameIDPolicy(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2NameIDPolicy, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2NameIDPolicy, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2NameIDPolicy instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["format"] = _lasso.Samlp2NameIDPolicy_format_set
    __swig_getmethods__["format"] = _lasso.Samlp2NameIDPolicy_format_get
    if _newclass:format = property(_lasso.Samlp2NameIDPolicy_format_get, _lasso.Samlp2NameIDPolicy_format_set)
    __swig_setmethods__["SPNameQualifier"] = _lasso.Samlp2NameIDPolicy_SPNameQualifier_set
    __swig_getmethods__["SPNameQualifier"] = _lasso.Samlp2NameIDPolicy_SPNameQualifier_get
    if _newclass:SPNameQualifier = property(_lasso.Samlp2NameIDPolicy_SPNameQualifier_get, _lasso.Samlp2NameIDPolicy_SPNameQualifier_set)
    __swig_setmethods__["allowCreate"] = _lasso.Samlp2NameIDPolicy_allowCreate_set
    __swig_getmethods__["allowCreate"] = _lasso.Samlp2NameIDPolicy_allowCreate_get
    if _newclass:allowCreate = property(_lasso.Samlp2NameIDPolicy_allowCreate_get, _lasso.Samlp2NameIDPolicy_allowCreate_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2NameIDPolicy(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2NameIDPolicy
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2NameIDPolicy_dump(*args)
_lasso.Samlp2NameIDPolicy_swigregister(Samlp2NameIDPolicy)

class Samlp2RequestedAuthnContext(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2RequestedAuthnContext, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2RequestedAuthnContext, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2RequestedAuthnContext instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["AuthnContextClassRef"] = _lasso.Samlp2RequestedAuthnContext_AuthnContextClassRef_set
    __swig_getmethods__["AuthnContextClassRef"] = _lasso.Samlp2RequestedAuthnContext_AuthnContextClassRef_get
    if _newclass:AuthnContextClassRef = property(_lasso.Samlp2RequestedAuthnContext_AuthnContextClassRef_get, _lasso.Samlp2RequestedAuthnContext_AuthnContextClassRef_set)
    __swig_setmethods__["AuthnContextDeclRef"] = _lasso.Samlp2RequestedAuthnContext_AuthnContextDeclRef_set
    __swig_getmethods__["AuthnContextDeclRef"] = _lasso.Samlp2RequestedAuthnContext_AuthnContextDeclRef_get
    if _newclass:AuthnContextDeclRef = property(_lasso.Samlp2RequestedAuthnContext_AuthnContextDeclRef_get, _lasso.Samlp2RequestedAuthnContext_AuthnContextDeclRef_set)
    __swig_setmethods__["Comparison"] = _lasso.Samlp2RequestedAuthnContext_Comparison_set
    __swig_getmethods__["Comparison"] = _lasso.Samlp2RequestedAuthnContext_Comparison_get
    if _newclass:Comparison = property(_lasso.Samlp2RequestedAuthnContext_Comparison_get, _lasso.Samlp2RequestedAuthnContext_Comparison_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2RequestedAuthnContext(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2RequestedAuthnContext
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2RequestedAuthnContext_dump(*args)
_lasso.Samlp2RequestedAuthnContext_swigregister(Samlp2RequestedAuthnContext)

class Saml2Assertion(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2Assertion, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2Assertion, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2Assertion instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["Version"] = _lasso.Saml2Assertion_Version_set
    __swig_getmethods__["Version"] = _lasso.Saml2Assertion_Version_get
    if _newclass:Version = property(_lasso.Saml2Assertion_Version_get, _lasso.Saml2Assertion_Version_set)
    __swig_setmethods__["ID"] = _lasso.Saml2Assertion_ID_set
    __swig_getmethods__["ID"] = _lasso.Saml2Assertion_ID_get
    if _newclass:ID = property(_lasso.Saml2Assertion_ID_get, _lasso.Saml2Assertion_ID_set)
    __swig_setmethods__["issueInstant"] = _lasso.Saml2Assertion_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Saml2Assertion_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Saml2Assertion_issueInstant_get, _lasso.Saml2Assertion_issueInstant_set)
    __swig_setmethods__["issuer"] = _lasso.Saml2Assertion_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Saml2Assertion_issuer_get
    if _newclass:issuer = property(_lasso.Saml2Assertion_issuer_get, _lasso.Saml2Assertion_issuer_set)
    __swig_setmethods__["subject"] = _lasso.Saml2Assertion_subject_set
    __swig_getmethods__["subject"] = _lasso.Saml2Assertion_subject_get
    if _newclass:subject = property(_lasso.Saml2Assertion_subject_get, _lasso.Saml2Assertion_subject_set)
    __swig_setmethods__["conditions"] = _lasso.Saml2Assertion_conditions_set
    __swig_getmethods__["conditions"] = _lasso.Saml2Assertion_conditions_get
    if _newclass:conditions = property(_lasso.Saml2Assertion_conditions_get, _lasso.Saml2Assertion_conditions_set)
    __swig_setmethods__["advice"] = _lasso.Saml2Assertion_advice_set
    __swig_getmethods__["advice"] = _lasso.Saml2Assertion_advice_get
    if _newclass:advice = property(_lasso.Saml2Assertion_advice_get, _lasso.Saml2Assertion_advice_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2Assertion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2Assertion
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2Assertion_dump(*args)
_lasso.Saml2Assertion_swigregister(Saml2Assertion)

class Samlp2IDPList(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2IDPList, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2IDPList, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2IDPList instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["GetComplete"] = _lasso.Samlp2IDPList_GetComplete_set
    __swig_getmethods__["GetComplete"] = _lasso.Samlp2IDPList_GetComplete_get
    if _newclass:GetComplete = property(_lasso.Samlp2IDPList_GetComplete_get, _lasso.Samlp2IDPList_GetComplete_set)
    __swig_setmethods__["iDPEntry"] = _lasso.Samlp2IDPList_iDPEntry_set
    __swig_getmethods__["iDPEntry"] = _lasso.Samlp2IDPList_iDPEntry_get
    if _newclass:iDPEntry = property(_lasso.Samlp2IDPList_iDPEntry_get, _lasso.Samlp2IDPList_iDPEntry_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2IDPList(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2IDPList
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2IDPList_dump(*args)
_lasso.Samlp2IDPList_swigregister(Samlp2IDPList)

class Saml2KeyInfoConfirmationData(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2KeyInfoConfirmationData, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2KeyInfoConfirmationData, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2KeyInfoConfirmationData instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Saml2KeyInfoConfirmationData(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2KeyInfoConfirmationData
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2KeyInfoConfirmationData_dump(*args)
_lasso.Saml2KeyInfoConfirmationData_swigregister(Saml2KeyInfoConfirmationData)

class Saml2Conditions(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2Conditions, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2Conditions, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2Conditions instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["notBefore"] = _lasso.Saml2Conditions_notBefore_set
    __swig_getmethods__["notBefore"] = _lasso.Saml2Conditions_notBefore_get
    if _newclass:notBefore = property(_lasso.Saml2Conditions_notBefore_get, _lasso.Saml2Conditions_notBefore_set)
    __swig_setmethods__["notOnOrAfter"] = _lasso.Saml2Conditions_notOnOrAfter_set
    __swig_getmethods__["notOnOrAfter"] = _lasso.Saml2Conditions_notOnOrAfter_get
    if _newclass:notOnOrAfter = property(_lasso.Saml2Conditions_notOnOrAfter_get, _lasso.Saml2Conditions_notOnOrAfter_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2Conditions(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2Conditions
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2Conditions_dump(*args)
_lasso.Saml2Conditions_swigregister(Saml2Conditions)

class Saml2Evidence(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2Evidence, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2Evidence, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2Evidence instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Saml2Evidence(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2Evidence
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2Evidence_dump(*args)
_lasso.Saml2Evidence_swigregister(Saml2Evidence)

class Saml2NameID(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2NameID, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2NameID, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2NameID instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["content"] = _lasso.Saml2NameID_content_set
    __swig_getmethods__["content"] = _lasso.Saml2NameID_content_get
    if _newclass:content = property(_lasso.Saml2NameID_content_get, _lasso.Saml2NameID_content_set)
    __swig_setmethods__["format"] = _lasso.Saml2NameID_format_set
    __swig_getmethods__["format"] = _lasso.Saml2NameID_format_get
    if _newclass:format = property(_lasso.Saml2NameID_format_get, _lasso.Saml2NameID_format_set)
    __swig_setmethods__["SPProvidedID"] = _lasso.Saml2NameID_SPProvidedID_set
    __swig_getmethods__["SPProvidedID"] = _lasso.Saml2NameID_SPProvidedID_get
    if _newclass:SPProvidedID = property(_lasso.Saml2NameID_SPProvidedID_get, _lasso.Saml2NameID_SPProvidedID_set)
    __swig_setmethods__["nameQualifier"] = _lasso.Saml2NameID_nameQualifier_set
    __swig_getmethods__["nameQualifier"] = _lasso.Saml2NameID_nameQualifier_get
    if _newclass:nameQualifier = property(_lasso.Saml2NameID_nameQualifier_get, _lasso.Saml2NameID_nameQualifier_set)
    __swig_setmethods__["SPNameQualifier"] = _lasso.Saml2NameID_SPNameQualifier_set
    __swig_getmethods__["SPNameQualifier"] = _lasso.Saml2NameID_SPNameQualifier_get
    if _newclass:SPNameQualifier = property(_lasso.Saml2NameID_SPNameQualifier_get, _lasso.Saml2NameID_SPNameQualifier_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2NameID(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2NameID
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2NameID_dump(*args)
_lasso.Saml2NameID_swigregister(Saml2NameID)

class Samlp2StatusCode(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2StatusCode, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2StatusCode, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2StatusCode instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["value"] = _lasso.Samlp2StatusCode_value_set
    __swig_getmethods__["value"] = _lasso.Samlp2StatusCode_value_get
    if _newclass:value = property(_lasso.Samlp2StatusCode_value_get, _lasso.Samlp2StatusCode_value_set)
    __swig_setmethods__["statusCode"] = _lasso.Samlp2StatusCode_statusCode_set
    __swig_getmethods__["statusCode"] = _lasso.Samlp2StatusCode_statusCode_get
    if _newclass:statusCode = property(_lasso.Samlp2StatusCode_statusCode_get, _lasso.Samlp2StatusCode_statusCode_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2StatusCode(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2StatusCode
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2StatusCode_dump(*args)
_lasso.Samlp2StatusCode_swigregister(Samlp2StatusCode)

class Samlp2Status(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2Status, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2Status, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2Status instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["statusMessage"] = _lasso.Samlp2Status_statusMessage_set
    __swig_getmethods__["statusMessage"] = _lasso.Samlp2Status_statusMessage_get
    if _newclass:statusMessage = property(_lasso.Samlp2Status_statusMessage_get, _lasso.Samlp2Status_statusMessage_set)
    __swig_setmethods__["statusCode"] = _lasso.Samlp2Status_statusCode_set
    __swig_getmethods__["statusCode"] = _lasso.Samlp2Status_statusCode_get
    if _newclass:statusCode = property(_lasso.Samlp2Status_statusCode_get, _lasso.Samlp2Status_statusCode_set)
    __swig_setmethods__["statusDetail"] = _lasso.Samlp2Status_statusDetail_set
    __swig_getmethods__["statusDetail"] = _lasso.Samlp2Status_statusDetail_get
    if _newclass:statusDetail = property(_lasso.Samlp2Status_statusDetail_get, _lasso.Samlp2Status_statusDetail_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2Status(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2Status
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2Status_dump(*args)
_lasso.Samlp2Status_swigregister(Samlp2Status)

class Saml2ConditionAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2ConditionAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2ConditionAbstract, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2ConditionAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Saml2ConditionAbstract(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2ConditionAbstract
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2ConditionAbstract_dump(*args)
_lasso.Saml2ConditionAbstract_swigregister(Saml2ConditionAbstract)

class Saml2OneTimeUse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2OneTimeUse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2OneTimeUse, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2OneTimeUse instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Saml2OneTimeUse(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2OneTimeUse
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2OneTimeUse_dump(*args)
_lasso.Saml2OneTimeUse_swigregister(Saml2OneTimeUse)

class Saml2Advice(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2Advice, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2Advice, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2Advice instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Saml2Advice(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2Advice
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2Advice_dump(*args)
_lasso.Saml2Advice_swigregister(Saml2Advice)

class Saml2BaseIDAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2BaseIDAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2BaseIDAbstract, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2BaseIDAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["nameQualifier"] = _lasso.Saml2BaseIDAbstract_nameQualifier_set
    __swig_getmethods__["nameQualifier"] = _lasso.Saml2BaseIDAbstract_nameQualifier_get
    if _newclass:nameQualifier = property(_lasso.Saml2BaseIDAbstract_nameQualifier_get, _lasso.Saml2BaseIDAbstract_nameQualifier_set)
    __swig_setmethods__["SPNameQualifier"] = _lasso.Saml2BaseIDAbstract_SPNameQualifier_set
    __swig_getmethods__["SPNameQualifier"] = _lasso.Saml2BaseIDAbstract_SPNameQualifier_get
    if _newclass:SPNameQualifier = property(_lasso.Saml2BaseIDAbstract_SPNameQualifier_get, _lasso.Saml2BaseIDAbstract_SPNameQualifier_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2BaseIDAbstract(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2BaseIDAbstract
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2BaseIDAbstract_dump(*args)
_lasso.Saml2BaseIDAbstract_swigregister(Saml2BaseIDAbstract)

class Saml2AuthnContext(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2AuthnContext, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2AuthnContext, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2AuthnContext instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["AuthnContextClassRef"] = _lasso.Saml2AuthnContext_AuthnContextClassRef_set
    __swig_getmethods__["AuthnContextClassRef"] = _lasso.Saml2AuthnContext_AuthnContextClassRef_get
    if _newclass:AuthnContextClassRef = property(_lasso.Saml2AuthnContext_AuthnContextClassRef_get, _lasso.Saml2AuthnContext_AuthnContextClassRef_set)
    __swig_setmethods__["AuthnContextDeclRef"] = _lasso.Saml2AuthnContext_AuthnContextDeclRef_set
    __swig_getmethods__["AuthnContextDeclRef"] = _lasso.Saml2AuthnContext_AuthnContextDeclRef_get
    if _newclass:AuthnContextDeclRef = property(_lasso.Saml2AuthnContext_AuthnContextDeclRef_get, _lasso.Saml2AuthnContext_AuthnContextDeclRef_set)
    __swig_setmethods__["AuthenticatingAuthority"] = _lasso.Saml2AuthnContext_AuthenticatingAuthority_set
    __swig_getmethods__["AuthenticatingAuthority"] = _lasso.Saml2AuthnContext_AuthenticatingAuthority_get
    if _newclass:AuthenticatingAuthority = property(_lasso.Saml2AuthnContext_AuthenticatingAuthority_get, _lasso.Saml2AuthnContext_AuthenticatingAuthority_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2AuthnContext(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2AuthnContext
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2AuthnContext_dump(*args)
_lasso.Saml2AuthnContext_swigregister(Saml2AuthnContext)

class Saml2SubjectLocality(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2SubjectLocality, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2SubjectLocality, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2SubjectLocality instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["Address"] = _lasso.Saml2SubjectLocality_Address_set
    __swig_getmethods__["Address"] = _lasso.Saml2SubjectLocality_Address_get
    if _newclass:Address = property(_lasso.Saml2SubjectLocality_Address_get, _lasso.Saml2SubjectLocality_Address_set)
    __swig_setmethods__["DNSName"] = _lasso.Saml2SubjectLocality_DNSName_set
    __swig_getmethods__["DNSName"] = _lasso.Saml2SubjectLocality_DNSName_get
    if _newclass:DNSName = property(_lasso.Saml2SubjectLocality_DNSName_get, _lasso.Saml2SubjectLocality_DNSName_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2SubjectLocality(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2SubjectLocality
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2SubjectLocality_dump(*args)
_lasso.Saml2SubjectLocality_swigregister(Saml2SubjectLocality)

class Saml2SubjectConfirmationData(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2SubjectConfirmationData, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2SubjectConfirmationData, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2SubjectConfirmationData instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["notBefore"] = _lasso.Saml2SubjectConfirmationData_notBefore_set
    __swig_getmethods__["notBefore"] = _lasso.Saml2SubjectConfirmationData_notBefore_get
    if _newclass:notBefore = property(_lasso.Saml2SubjectConfirmationData_notBefore_get, _lasso.Saml2SubjectConfirmationData_notBefore_set)
    __swig_setmethods__["notOnOrAfter"] = _lasso.Saml2SubjectConfirmationData_notOnOrAfter_set
    __swig_getmethods__["notOnOrAfter"] = _lasso.Saml2SubjectConfirmationData_notOnOrAfter_get
    if _newclass:notOnOrAfter = property(_lasso.Saml2SubjectConfirmationData_notOnOrAfter_get, _lasso.Saml2SubjectConfirmationData_notOnOrAfter_set)
    __swig_setmethods__["recipient"] = _lasso.Saml2SubjectConfirmationData_recipient_set
    __swig_getmethods__["recipient"] = _lasso.Saml2SubjectConfirmationData_recipient_get
    if _newclass:recipient = property(_lasso.Saml2SubjectConfirmationData_recipient_get, _lasso.Saml2SubjectConfirmationData_recipient_set)
    __swig_setmethods__["inResponseTo"] = _lasso.Saml2SubjectConfirmationData_inResponseTo_set
    __swig_getmethods__["inResponseTo"] = _lasso.Saml2SubjectConfirmationData_inResponseTo_get
    if _newclass:inResponseTo = property(_lasso.Saml2SubjectConfirmationData_inResponseTo_get, _lasso.Saml2SubjectConfirmationData_inResponseTo_set)
    __swig_setmethods__["Address"] = _lasso.Saml2SubjectConfirmationData_Address_set
    __swig_getmethods__["Address"] = _lasso.Saml2SubjectConfirmationData_Address_get
    if _newclass:Address = property(_lasso.Saml2SubjectConfirmationData_Address_get, _lasso.Saml2SubjectConfirmationData_Address_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2SubjectConfirmationData(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2SubjectConfirmationData
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2SubjectConfirmationData_dump(*args)
_lasso.Saml2SubjectConfirmationData_swigregister(Saml2SubjectConfirmationData)

class Saml2SubjectConfirmation(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2SubjectConfirmation, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2SubjectConfirmation, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2SubjectConfirmation instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["Method"] = _lasso.Saml2SubjectConfirmation_Method_set
    __swig_getmethods__["Method"] = _lasso.Saml2SubjectConfirmation_Method_get
    if _newclass:Method = property(_lasso.Saml2SubjectConfirmation_Method_get, _lasso.Saml2SubjectConfirmation_Method_set)
    __swig_setmethods__["baseID"] = _lasso.Saml2SubjectConfirmation_baseID_set
    __swig_getmethods__["baseID"] = _lasso.Saml2SubjectConfirmation_baseID_get
    if _newclass:baseID = property(_lasso.Saml2SubjectConfirmation_baseID_get, _lasso.Saml2SubjectConfirmation_baseID_set)
    __swig_setmethods__["nameID"] = _lasso.Saml2SubjectConfirmation_nameID_set
    __swig_getmethods__["nameID"] = _lasso.Saml2SubjectConfirmation_nameID_get
    if _newclass:nameID = property(_lasso.Saml2SubjectConfirmation_nameID_get, _lasso.Saml2SubjectConfirmation_nameID_set)
    __swig_setmethods__["encryptedID"] = _lasso.Saml2SubjectConfirmation_encryptedID_set
    __swig_getmethods__["encryptedID"] = _lasso.Saml2SubjectConfirmation_encryptedID_get
    if _newclass:encryptedID = property(_lasso.Saml2SubjectConfirmation_encryptedID_get, _lasso.Saml2SubjectConfirmation_encryptedID_set)
    __swig_setmethods__["subjectConfirmationData"] = _lasso.Saml2SubjectConfirmation_subjectConfirmationData_set
    __swig_getmethods__["subjectConfirmationData"] = _lasso.Saml2SubjectConfirmation_subjectConfirmationData_get
    if _newclass:subjectConfirmationData = property(_lasso.Saml2SubjectConfirmation_subjectConfirmationData_get, _lasso.Saml2SubjectConfirmation_subjectConfirmationData_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2SubjectConfirmation(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2SubjectConfirmation
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2SubjectConfirmation_dump(*args)
_lasso.Saml2SubjectConfirmation_swigregister(Saml2SubjectConfirmation)

class Saml2ProxyRestriction(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2ProxyRestriction, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2ProxyRestriction, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2ProxyRestriction instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["Audience"] = _lasso.Saml2ProxyRestriction_Audience_set
    __swig_getmethods__["Audience"] = _lasso.Saml2ProxyRestriction_Audience_get
    if _newclass:Audience = property(_lasso.Saml2ProxyRestriction_Audience_get, _lasso.Saml2ProxyRestriction_Audience_set)
    __swig_setmethods__["Count"] = _lasso.Saml2ProxyRestriction_Count_set
    __swig_getmethods__["Count"] = _lasso.Saml2ProxyRestriction_Count_get
    if _newclass:Count = property(_lasso.Saml2ProxyRestriction_Count_get, _lasso.Saml2ProxyRestriction_Count_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2ProxyRestriction(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2ProxyRestriction
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2ProxyRestriction_dump(*args)
_lasso.Saml2ProxyRestriction_swigregister(Saml2ProxyRestriction)

class Saml2StatementAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2StatementAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2StatementAbstract, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2StatementAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Saml2StatementAbstract(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2StatementAbstract
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2StatementAbstract_dump(*args)
_lasso.Saml2StatementAbstract_swigregister(Saml2StatementAbstract)

class Saml2AuthnStatement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2AuthnStatement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2AuthnStatement, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2AuthnStatement instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["AuthnInstant"] = _lasso.Saml2AuthnStatement_AuthnInstant_set
    __swig_getmethods__["AuthnInstant"] = _lasso.Saml2AuthnStatement_AuthnInstant_get
    if _newclass:AuthnInstant = property(_lasso.Saml2AuthnStatement_AuthnInstant_get, _lasso.Saml2AuthnStatement_AuthnInstant_set)
    __swig_setmethods__["sessionIndex"] = _lasso.Saml2AuthnStatement_sessionIndex_set
    __swig_getmethods__["sessionIndex"] = _lasso.Saml2AuthnStatement_sessionIndex_get
    if _newclass:sessionIndex = property(_lasso.Saml2AuthnStatement_sessionIndex_get, _lasso.Saml2AuthnStatement_sessionIndex_set)
    __swig_setmethods__["SessionNotOnOrAfter"] = _lasso.Saml2AuthnStatement_SessionNotOnOrAfter_set
    __swig_getmethods__["SessionNotOnOrAfter"] = _lasso.Saml2AuthnStatement_SessionNotOnOrAfter_get
    if _newclass:SessionNotOnOrAfter = property(_lasso.Saml2AuthnStatement_SessionNotOnOrAfter_get, _lasso.Saml2AuthnStatement_SessionNotOnOrAfter_set)
    __swig_setmethods__["subjectLocality"] = _lasso.Saml2AuthnStatement_subjectLocality_set
    __swig_getmethods__["subjectLocality"] = _lasso.Saml2AuthnStatement_subjectLocality_get
    if _newclass:subjectLocality = property(_lasso.Saml2AuthnStatement_subjectLocality_get, _lasso.Saml2AuthnStatement_subjectLocality_set)
    __swig_setmethods__["authnContext"] = _lasso.Saml2AuthnStatement_authnContext_set
    __swig_getmethods__["authnContext"] = _lasso.Saml2AuthnStatement_authnContext_get
    if _newclass:authnContext = property(_lasso.Saml2AuthnStatement_authnContext_get, _lasso.Saml2AuthnStatement_authnContext_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2AuthnStatement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2AuthnStatement
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2AuthnStatement_dump(*args)
_lasso.Saml2AuthnStatement_swigregister(Saml2AuthnStatement)

class Saml2AttributeStatement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2AttributeStatement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2AttributeStatement, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2AttributeStatement instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Saml2AttributeStatement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2AttributeStatement
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2AttributeStatement_dump(*args)
_lasso.Saml2AttributeStatement_swigregister(Saml2AttributeStatement)

class Samlp2IDPEntry(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2IDPEntry, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2IDPEntry, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2IDPEntry instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["providerId"] = _lasso.Samlp2IDPEntry_providerId_set
    __swig_getmethods__["providerId"] = _lasso.Samlp2IDPEntry_providerId_get
    if _newclass:providerId = property(_lasso.Samlp2IDPEntry_providerId_get, _lasso.Samlp2IDPEntry_providerId_set)
    __swig_setmethods__["Name"] = _lasso.Samlp2IDPEntry_Name_set
    __swig_getmethods__["Name"] = _lasso.Samlp2IDPEntry_Name_get
    if _newclass:Name = property(_lasso.Samlp2IDPEntry_Name_get, _lasso.Samlp2IDPEntry_Name_set)
    __swig_setmethods__["Loc"] = _lasso.Samlp2IDPEntry_Loc_set
    __swig_getmethods__["Loc"] = _lasso.Samlp2IDPEntry_Loc_get
    if _newclass:Loc = property(_lasso.Samlp2IDPEntry_Loc_get, _lasso.Samlp2IDPEntry_Loc_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2IDPEntry(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2IDPEntry
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2IDPEntry_dump(*args)
_lasso.Samlp2IDPEntry_swigregister(Samlp2IDPEntry)

class Samlp2Extensions(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2Extensions, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2Extensions, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2Extensions instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Samlp2Extensions(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2Extensions
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2Extensions_dump(*args)
_lasso.Samlp2Extensions_swigregister(Samlp2Extensions)

class Saml2Action(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2Action, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2Action, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2Action instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["content"] = _lasso.Saml2Action_content_set
    __swig_getmethods__["content"] = _lasso.Saml2Action_content_get
    if _newclass:content = property(_lasso.Saml2Action_content_get, _lasso.Saml2Action_content_set)
    __swig_setmethods__["Namespace"] = _lasso.Saml2Action_Namespace_set
    __swig_getmethods__["Namespace"] = _lasso.Saml2Action_Namespace_get
    if _newclass:Namespace = property(_lasso.Saml2Action_Namespace_get, _lasso.Saml2Action_Namespace_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2Action(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2Action
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2Action_dump(*args)
_lasso.Saml2Action_swigregister(Saml2Action)

class Samlp2StatusResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2StatusResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2StatusResponse, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2StatusResponse instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["ID"] = _lasso.Samlp2StatusResponse_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2StatusResponse_ID_get
    if _newclass:ID = property(_lasso.Samlp2StatusResponse_ID_get, _lasso.Samlp2StatusResponse_ID_set)
    __swig_setmethods__["inResponseTo"] = _lasso.Samlp2StatusResponse_inResponseTo_set
    __swig_getmethods__["inResponseTo"] = _lasso.Samlp2StatusResponse_inResponseTo_get
    if _newclass:inResponseTo = property(_lasso.Samlp2StatusResponse_inResponseTo_get, _lasso.Samlp2StatusResponse_inResponseTo_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2StatusResponse_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2StatusResponse_Version_get
    if _newclass:Version = property(_lasso.Samlp2StatusResponse_Version_get, _lasso.Samlp2StatusResponse_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2StatusResponse_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2StatusResponse_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2StatusResponse_issueInstant_get, _lasso.Samlp2StatusResponse_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2StatusResponse_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2StatusResponse_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2StatusResponse_Destination_get, _lasso.Samlp2StatusResponse_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2StatusResponse_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2StatusResponse_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2StatusResponse_Consent_get, _lasso.Samlp2StatusResponse_Consent_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2StatusResponse_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2StatusResponse_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2StatusResponse_issuer_get, _lasso.Samlp2StatusResponse_issuer_set)
    __swig_setmethods__["extensions"] = _lasso.Samlp2StatusResponse_extensions_set
    __swig_getmethods__["extensions"] = _lasso.Samlp2StatusResponse_extensions_get
    if _newclass:extensions = property(_lasso.Samlp2StatusResponse_extensions_get, _lasso.Samlp2StatusResponse_extensions_set)
    __swig_setmethods__["status"] = _lasso.Samlp2StatusResponse_status_set
    __swig_getmethods__["status"] = _lasso.Samlp2StatusResponse_status_get
    if _newclass:status = property(_lasso.Samlp2StatusResponse_status_get, _lasso.Samlp2StatusResponse_status_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2StatusResponse(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2StatusResponse
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2StatusResponse_dump(*args)
_lasso.Samlp2StatusResponse_swigregister(Samlp2StatusResponse)

class Samlp2Response(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2Response, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2Response, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2Response instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["issuer"] = _lasso.Samlp2Response_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2Response_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2Response_issuer_get, _lasso.Samlp2Response_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2Response_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2Response_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2Response_Extensions_get, _lasso.Samlp2Response_Extensions_set)
    __swig_setmethods__["Status"] = _lasso.Samlp2Response_Status_set
    __swig_getmethods__["Status"] = _lasso.Samlp2Response_Status_get
    if _newclass:Status = property(_lasso.Samlp2Response_Status_get, _lasso.Samlp2Response_Status_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2Response_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2Response_ID_get
    if _newclass:ID = property(_lasso.Samlp2Response_ID_get, _lasso.Samlp2Response_ID_set)
    __swig_setmethods__["inResponseTo"] = _lasso.Samlp2Response_inResponseTo_set
    __swig_getmethods__["inResponseTo"] = _lasso.Samlp2Response_inResponseTo_get
    if _newclass:inResponseTo = property(_lasso.Samlp2Response_inResponseTo_get, _lasso.Samlp2Response_inResponseTo_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2Response_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2Response_Version_get
    if _newclass:Version = property(_lasso.Samlp2Response_Version_get, _lasso.Samlp2Response_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2Response_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2Response_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2Response_issueInstant_get, _lasso.Samlp2Response_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2Response_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2Response_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2Response_Destination_get, _lasso.Samlp2Response_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2Response_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2Response_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2Response_Consent_get, _lasso.Samlp2Response_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2Response(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2Response
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2Response_dump(*args)
_lasso.Samlp2Response_swigregister(Samlp2Response)

class Samlp2ArtifactResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2ArtifactResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2ArtifactResponse, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2ArtifactResponse instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["any"] = _lasso.Samlp2ArtifactResponse_any_set
    __swig_getmethods__["any"] = _lasso.Samlp2ArtifactResponse_any_get
    if _newclass:any = property(_lasso.Samlp2ArtifactResponse_any_get, _lasso.Samlp2ArtifactResponse_any_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2ArtifactResponse_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2ArtifactResponse_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2ArtifactResponse_issuer_get, _lasso.Samlp2ArtifactResponse_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2ArtifactResponse_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2ArtifactResponse_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2ArtifactResponse_Extensions_get, _lasso.Samlp2ArtifactResponse_Extensions_set)
    __swig_setmethods__["Status"] = _lasso.Samlp2ArtifactResponse_Status_set
    __swig_getmethods__["Status"] = _lasso.Samlp2ArtifactResponse_Status_get
    if _newclass:Status = property(_lasso.Samlp2ArtifactResponse_Status_get, _lasso.Samlp2ArtifactResponse_Status_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2ArtifactResponse_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2ArtifactResponse_ID_get
    if _newclass:ID = property(_lasso.Samlp2ArtifactResponse_ID_get, _lasso.Samlp2ArtifactResponse_ID_set)
    __swig_setmethods__["inResponseTo"] = _lasso.Samlp2ArtifactResponse_inResponseTo_set
    __swig_getmethods__["inResponseTo"] = _lasso.Samlp2ArtifactResponse_inResponseTo_get
    if _newclass:inResponseTo = property(_lasso.Samlp2ArtifactResponse_inResponseTo_get, _lasso.Samlp2ArtifactResponse_inResponseTo_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2ArtifactResponse_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2ArtifactResponse_Version_get
    if _newclass:Version = property(_lasso.Samlp2ArtifactResponse_Version_get, _lasso.Samlp2ArtifactResponse_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2ArtifactResponse_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2ArtifactResponse_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2ArtifactResponse_issueInstant_get, _lasso.Samlp2ArtifactResponse_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2ArtifactResponse_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2ArtifactResponse_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2ArtifactResponse_Destination_get, _lasso.Samlp2ArtifactResponse_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2ArtifactResponse_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2ArtifactResponse_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2ArtifactResponse_Consent_get, _lasso.Samlp2ArtifactResponse_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2ArtifactResponse(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2ArtifactResponse
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2ArtifactResponse_dump(*args)
_lasso.Samlp2ArtifactResponse_swigregister(Samlp2ArtifactResponse)

class Samlp2RequestAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2RequestAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2RequestAbstract, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2RequestAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["ID"] = _lasso.Samlp2RequestAbstract_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2RequestAbstract_ID_get
    if _newclass:ID = property(_lasso.Samlp2RequestAbstract_ID_get, _lasso.Samlp2RequestAbstract_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2RequestAbstract_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2RequestAbstract_Version_get
    if _newclass:Version = property(_lasso.Samlp2RequestAbstract_Version_get, _lasso.Samlp2RequestAbstract_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2RequestAbstract_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2RequestAbstract_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2RequestAbstract_issueInstant_get, _lasso.Samlp2RequestAbstract_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2RequestAbstract_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2RequestAbstract_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2RequestAbstract_Destination_get, _lasso.Samlp2RequestAbstract_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2RequestAbstract_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2RequestAbstract_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2RequestAbstract_Consent_get, _lasso.Samlp2RequestAbstract_Consent_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2RequestAbstract_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2RequestAbstract_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2RequestAbstract_issuer_get, _lasso.Samlp2RequestAbstract_issuer_set)
    __swig_setmethods__["extensions"] = _lasso.Samlp2RequestAbstract_extensions_set
    __swig_getmethods__["extensions"] = _lasso.Samlp2RequestAbstract_extensions_get
    if _newclass:extensions = property(_lasso.Samlp2RequestAbstract_extensions_get, _lasso.Samlp2RequestAbstract_extensions_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2RequestAbstract(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2RequestAbstract
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2RequestAbstract_dump(*args)
_lasso.Samlp2RequestAbstract_swigregister(Samlp2RequestAbstract)

class Samlp2AssertionIDRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2AssertionIDRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2AssertionIDRequest, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2AssertionIDRequest instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["AssertionIDRef"] = _lasso.Samlp2AssertionIDRequest_AssertionIDRef_set
    __swig_getmethods__["AssertionIDRef"] = _lasso.Samlp2AssertionIDRequest_AssertionIDRef_get
    if _newclass:AssertionIDRef = property(_lasso.Samlp2AssertionIDRequest_AssertionIDRef_get, _lasso.Samlp2AssertionIDRequest_AssertionIDRef_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2AssertionIDRequest_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2AssertionIDRequest_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2AssertionIDRequest_issuer_get, _lasso.Samlp2AssertionIDRequest_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2AssertionIDRequest_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2AssertionIDRequest_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2AssertionIDRequest_Extensions_get, _lasso.Samlp2AssertionIDRequest_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2AssertionIDRequest_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2AssertionIDRequest_ID_get
    if _newclass:ID = property(_lasso.Samlp2AssertionIDRequest_ID_get, _lasso.Samlp2AssertionIDRequest_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2AssertionIDRequest_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2AssertionIDRequest_Version_get
    if _newclass:Version = property(_lasso.Samlp2AssertionIDRequest_Version_get, _lasso.Samlp2AssertionIDRequest_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2AssertionIDRequest_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2AssertionIDRequest_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2AssertionIDRequest_issueInstant_get, _lasso.Samlp2AssertionIDRequest_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2AssertionIDRequest_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2AssertionIDRequest_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2AssertionIDRequest_Destination_get, _lasso.Samlp2AssertionIDRequest_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2AssertionIDRequest_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2AssertionIDRequest_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2AssertionIDRequest_Consent_get, _lasso.Samlp2AssertionIDRequest_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2AssertionIDRequest(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2AssertionIDRequest
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2AssertionIDRequest_dump(*args)
_lasso.Samlp2AssertionIDRequest_swigregister(Samlp2AssertionIDRequest)

class Samlp2ArtifactResolve(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2ArtifactResolve, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2ArtifactResolve, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2ArtifactResolve instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["Artifact"] = _lasso.Samlp2ArtifactResolve_Artifact_set
    __swig_getmethods__["Artifact"] = _lasso.Samlp2ArtifactResolve_Artifact_get
    if _newclass:Artifact = property(_lasso.Samlp2ArtifactResolve_Artifact_get, _lasso.Samlp2ArtifactResolve_Artifact_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2ArtifactResolve_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2ArtifactResolve_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2ArtifactResolve_issuer_get, _lasso.Samlp2ArtifactResolve_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2ArtifactResolve_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2ArtifactResolve_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2ArtifactResolve_Extensions_get, _lasso.Samlp2ArtifactResolve_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2ArtifactResolve_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2ArtifactResolve_ID_get
    if _newclass:ID = property(_lasso.Samlp2ArtifactResolve_ID_get, _lasso.Samlp2ArtifactResolve_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2ArtifactResolve_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2ArtifactResolve_Version_get
    if _newclass:Version = property(_lasso.Samlp2ArtifactResolve_Version_get, _lasso.Samlp2ArtifactResolve_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2ArtifactResolve_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2ArtifactResolve_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2ArtifactResolve_issueInstant_get, _lasso.Samlp2ArtifactResolve_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2ArtifactResolve_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2ArtifactResolve_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2ArtifactResolve_Destination_get, _lasso.Samlp2ArtifactResolve_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2ArtifactResolve_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2ArtifactResolve_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2ArtifactResolve_Consent_get, _lasso.Samlp2ArtifactResolve_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2ArtifactResolve(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2ArtifactResolve
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2ArtifactResolve_dump(*args)
_lasso.Samlp2ArtifactResolve_swigregister(Samlp2ArtifactResolve)

class Samlp2NameIDMappingRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2NameIDMappingRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2NameIDMappingRequest, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2NameIDMappingRequest instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["baseID"] = _lasso.Samlp2NameIDMappingRequest_baseID_set
    __swig_getmethods__["baseID"] = _lasso.Samlp2NameIDMappingRequest_baseID_get
    if _newclass:baseID = property(_lasso.Samlp2NameIDMappingRequest_baseID_get, _lasso.Samlp2NameIDMappingRequest_baseID_set)
    __swig_setmethods__["nameID"] = _lasso.Samlp2NameIDMappingRequest_nameID_set
    __swig_getmethods__["nameID"] = _lasso.Samlp2NameIDMappingRequest_nameID_get
    if _newclass:nameID = property(_lasso.Samlp2NameIDMappingRequest_nameID_get, _lasso.Samlp2NameIDMappingRequest_nameID_set)
    __swig_setmethods__["encryptedID"] = _lasso.Samlp2NameIDMappingRequest_encryptedID_set
    __swig_getmethods__["encryptedID"] = _lasso.Samlp2NameIDMappingRequest_encryptedID_get
    if _newclass:encryptedID = property(_lasso.Samlp2NameIDMappingRequest_encryptedID_get, _lasso.Samlp2NameIDMappingRequest_encryptedID_set)
    __swig_setmethods__["nameIDPolicy"] = _lasso.Samlp2NameIDMappingRequest_nameIDPolicy_set
    __swig_getmethods__["nameIDPolicy"] = _lasso.Samlp2NameIDMappingRequest_nameIDPolicy_get
    if _newclass:nameIDPolicy = property(_lasso.Samlp2NameIDMappingRequest_nameIDPolicy_get, _lasso.Samlp2NameIDMappingRequest_nameIDPolicy_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2NameIDMappingRequest_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2NameIDMappingRequest_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2NameIDMappingRequest_issuer_get, _lasso.Samlp2NameIDMappingRequest_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2NameIDMappingRequest_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2NameIDMappingRequest_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2NameIDMappingRequest_Extensions_get, _lasso.Samlp2NameIDMappingRequest_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2NameIDMappingRequest_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2NameIDMappingRequest_ID_get
    if _newclass:ID = property(_lasso.Samlp2NameIDMappingRequest_ID_get, _lasso.Samlp2NameIDMappingRequest_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2NameIDMappingRequest_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2NameIDMappingRequest_Version_get
    if _newclass:Version = property(_lasso.Samlp2NameIDMappingRequest_Version_get, _lasso.Samlp2NameIDMappingRequest_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2NameIDMappingRequest_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2NameIDMappingRequest_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2NameIDMappingRequest_issueInstant_get, _lasso.Samlp2NameIDMappingRequest_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2NameIDMappingRequest_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2NameIDMappingRequest_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2NameIDMappingRequest_Destination_get, _lasso.Samlp2NameIDMappingRequest_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2NameIDMappingRequest_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2NameIDMappingRequest_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2NameIDMappingRequest_Consent_get, _lasso.Samlp2NameIDMappingRequest_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2NameIDMappingRequest(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2NameIDMappingRequest
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2NameIDMappingRequest_dump(*args)
_lasso.Samlp2NameIDMappingRequest_swigregister(Samlp2NameIDMappingRequest)

class Samlp2AuthnRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2AuthnRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2AuthnRequest, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2AuthnRequest instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["forceAuthn"] = _lasso.Samlp2AuthnRequest_forceAuthn_set
    __swig_getmethods__["forceAuthn"] = _lasso.Samlp2AuthnRequest_forceAuthn_get
    if _newclass:forceAuthn = property(_lasso.Samlp2AuthnRequest_forceAuthn_get, _lasso.Samlp2AuthnRequest_forceAuthn_set)
    __swig_setmethods__["isPassive"] = _lasso.Samlp2AuthnRequest_isPassive_set
    __swig_getmethods__["isPassive"] = _lasso.Samlp2AuthnRequest_isPassive_get
    if _newclass:isPassive = property(_lasso.Samlp2AuthnRequest_isPassive_get, _lasso.Samlp2AuthnRequest_isPassive_set)
    __swig_setmethods__["ProtocolBinding"] = _lasso.Samlp2AuthnRequest_ProtocolBinding_set
    __swig_getmethods__["ProtocolBinding"] = _lasso.Samlp2AuthnRequest_ProtocolBinding_get
    if _newclass:ProtocolBinding = property(_lasso.Samlp2AuthnRequest_ProtocolBinding_get, _lasso.Samlp2AuthnRequest_ProtocolBinding_set)
    __swig_setmethods__["assertionConsumerServiceIndex"] = _lasso.Samlp2AuthnRequest_assertionConsumerServiceIndex_set
    __swig_getmethods__["assertionConsumerServiceIndex"] = _lasso.Samlp2AuthnRequest_assertionConsumerServiceIndex_get
    if _newclass:assertionConsumerServiceIndex = property(_lasso.Samlp2AuthnRequest_assertionConsumerServiceIndex_get, _lasso.Samlp2AuthnRequest_assertionConsumerServiceIndex_set)
    __swig_setmethods__["AssertionConsumerServiceURL"] = _lasso.Samlp2AuthnRequest_AssertionConsumerServiceURL_set
    __swig_getmethods__["AssertionConsumerServiceURL"] = _lasso.Samlp2AuthnRequest_AssertionConsumerServiceURL_get
    if _newclass:AssertionConsumerServiceURL = property(_lasso.Samlp2AuthnRequest_AssertionConsumerServiceURL_get, _lasso.Samlp2AuthnRequest_AssertionConsumerServiceURL_set)
    __swig_setmethods__["attributeConsumingServiceIndex"] = _lasso.Samlp2AuthnRequest_attributeConsumingServiceIndex_set
    __swig_getmethods__["attributeConsumingServiceIndex"] = _lasso.Samlp2AuthnRequest_attributeConsumingServiceIndex_get
    if _newclass:attributeConsumingServiceIndex = property(_lasso.Samlp2AuthnRequest_attributeConsumingServiceIndex_get, _lasso.Samlp2AuthnRequest_attributeConsumingServiceIndex_set)
    __swig_setmethods__["ProviderName"] = _lasso.Samlp2AuthnRequest_ProviderName_set
    __swig_getmethods__["ProviderName"] = _lasso.Samlp2AuthnRequest_ProviderName_get
    if _newclass:ProviderName = property(_lasso.Samlp2AuthnRequest_ProviderName_get, _lasso.Samlp2AuthnRequest_ProviderName_set)
    __swig_setmethods__["subject"] = _lasso.Samlp2AuthnRequest_subject_set
    __swig_getmethods__["subject"] = _lasso.Samlp2AuthnRequest_subject_get
    if _newclass:subject = property(_lasso.Samlp2AuthnRequest_subject_get, _lasso.Samlp2AuthnRequest_subject_set)
    __swig_setmethods__["nameIDPolicy"] = _lasso.Samlp2AuthnRequest_nameIDPolicy_set
    __swig_getmethods__["nameIDPolicy"] = _lasso.Samlp2AuthnRequest_nameIDPolicy_get
    if _newclass:nameIDPolicy = property(_lasso.Samlp2AuthnRequest_nameIDPolicy_get, _lasso.Samlp2AuthnRequest_nameIDPolicy_set)
    __swig_setmethods__["conditions"] = _lasso.Samlp2AuthnRequest_conditions_set
    __swig_getmethods__["conditions"] = _lasso.Samlp2AuthnRequest_conditions_get
    if _newclass:conditions = property(_lasso.Samlp2AuthnRequest_conditions_get, _lasso.Samlp2AuthnRequest_conditions_set)
    __swig_setmethods__["requestedAuthnContext"] = _lasso.Samlp2AuthnRequest_requestedAuthnContext_set
    __swig_getmethods__["requestedAuthnContext"] = _lasso.Samlp2AuthnRequest_requestedAuthnContext_get
    if _newclass:requestedAuthnContext = property(_lasso.Samlp2AuthnRequest_requestedAuthnContext_get, _lasso.Samlp2AuthnRequest_requestedAuthnContext_set)
    __swig_setmethods__["scoping"] = _lasso.Samlp2AuthnRequest_scoping_set
    __swig_getmethods__["scoping"] = _lasso.Samlp2AuthnRequest_scoping_get
    if _newclass:scoping = property(_lasso.Samlp2AuthnRequest_scoping_get, _lasso.Samlp2AuthnRequest_scoping_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2AuthnRequest_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2AuthnRequest_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2AuthnRequest_issuer_get, _lasso.Samlp2AuthnRequest_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2AuthnRequest_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2AuthnRequest_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2AuthnRequest_Extensions_get, _lasso.Samlp2AuthnRequest_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2AuthnRequest_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2AuthnRequest_ID_get
    if _newclass:ID = property(_lasso.Samlp2AuthnRequest_ID_get, _lasso.Samlp2AuthnRequest_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2AuthnRequest_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2AuthnRequest_Version_get
    if _newclass:Version = property(_lasso.Samlp2AuthnRequest_Version_get, _lasso.Samlp2AuthnRequest_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2AuthnRequest_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2AuthnRequest_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2AuthnRequest_issueInstant_get, _lasso.Samlp2AuthnRequest_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2AuthnRequest_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2AuthnRequest_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2AuthnRequest_Destination_get, _lasso.Samlp2AuthnRequest_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2AuthnRequest_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2AuthnRequest_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2AuthnRequest_Consent_get, _lasso.Samlp2AuthnRequest_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2AuthnRequest(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2AuthnRequest
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2AuthnRequest_dump(*args)
_lasso.Samlp2AuthnRequest_swigregister(Samlp2AuthnRequest)

class Samlp2SubjectQueryAbstract(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2SubjectQueryAbstract, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2SubjectQueryAbstract, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2SubjectQueryAbstract instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["subject"] = _lasso.Samlp2SubjectQueryAbstract_subject_set
    __swig_getmethods__["subject"] = _lasso.Samlp2SubjectQueryAbstract_subject_get
    if _newclass:subject = property(_lasso.Samlp2SubjectQueryAbstract_subject_get, _lasso.Samlp2SubjectQueryAbstract_subject_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2SubjectQueryAbstract_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2SubjectQueryAbstract_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2SubjectQueryAbstract_issuer_get, _lasso.Samlp2SubjectQueryAbstract_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2SubjectQueryAbstract_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2SubjectQueryAbstract_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2SubjectQueryAbstract_Extensions_get, _lasso.Samlp2SubjectQueryAbstract_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2SubjectQueryAbstract_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2SubjectQueryAbstract_ID_get
    if _newclass:ID = property(_lasso.Samlp2SubjectQueryAbstract_ID_get, _lasso.Samlp2SubjectQueryAbstract_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2SubjectQueryAbstract_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2SubjectQueryAbstract_Version_get
    if _newclass:Version = property(_lasso.Samlp2SubjectQueryAbstract_Version_get, _lasso.Samlp2SubjectQueryAbstract_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2SubjectQueryAbstract_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2SubjectQueryAbstract_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2SubjectQueryAbstract_issueInstant_get, _lasso.Samlp2SubjectQueryAbstract_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2SubjectQueryAbstract_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2SubjectQueryAbstract_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2SubjectQueryAbstract_Destination_get, _lasso.Samlp2SubjectQueryAbstract_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2SubjectQueryAbstract_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2SubjectQueryAbstract_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2SubjectQueryAbstract_Consent_get, _lasso.Samlp2SubjectQueryAbstract_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2SubjectQueryAbstract(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2SubjectQueryAbstract
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2SubjectQueryAbstract_dump(*args)
_lasso.Samlp2SubjectQueryAbstract_swigregister(Samlp2SubjectQueryAbstract)

class Samlp2AuthzDecisionQuery(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2AuthzDecisionQuery, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2AuthzDecisionQuery, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2AuthzDecisionQuery instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["Resource"] = _lasso.Samlp2AuthzDecisionQuery_Resource_set
    __swig_getmethods__["Resource"] = _lasso.Samlp2AuthzDecisionQuery_Resource_get
    if _newclass:Resource = property(_lasso.Samlp2AuthzDecisionQuery_Resource_get, _lasso.Samlp2AuthzDecisionQuery_Resource_set)
    __swig_setmethods__["action"] = _lasso.Samlp2AuthzDecisionQuery_action_set
    __swig_getmethods__["action"] = _lasso.Samlp2AuthzDecisionQuery_action_get
    if _newclass:action = property(_lasso.Samlp2AuthzDecisionQuery_action_get, _lasso.Samlp2AuthzDecisionQuery_action_set)
    __swig_setmethods__["evidence"] = _lasso.Samlp2AuthzDecisionQuery_evidence_set
    __swig_getmethods__["evidence"] = _lasso.Samlp2AuthzDecisionQuery_evidence_get
    if _newclass:evidence = property(_lasso.Samlp2AuthzDecisionQuery_evidence_get, _lasso.Samlp2AuthzDecisionQuery_evidence_set)
    __swig_setmethods__["Subject"] = _lasso.Samlp2AuthzDecisionQuery_Subject_set
    __swig_getmethods__["Subject"] = _lasso.Samlp2AuthzDecisionQuery_Subject_get
    if _newclass:Subject = property(_lasso.Samlp2AuthzDecisionQuery_Subject_get, _lasso.Samlp2AuthzDecisionQuery_Subject_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2AuthzDecisionQuery_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2AuthzDecisionQuery_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2AuthzDecisionQuery_issuer_get, _lasso.Samlp2AuthzDecisionQuery_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2AuthzDecisionQuery_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2AuthzDecisionQuery_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2AuthzDecisionQuery_Extensions_get, _lasso.Samlp2AuthzDecisionQuery_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2AuthzDecisionQuery_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2AuthzDecisionQuery_ID_get
    if _newclass:ID = property(_lasso.Samlp2AuthzDecisionQuery_ID_get, _lasso.Samlp2AuthzDecisionQuery_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2AuthzDecisionQuery_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2AuthzDecisionQuery_Version_get
    if _newclass:Version = property(_lasso.Samlp2AuthzDecisionQuery_Version_get, _lasso.Samlp2AuthzDecisionQuery_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2AuthzDecisionQuery_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2AuthzDecisionQuery_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2AuthzDecisionQuery_issueInstant_get, _lasso.Samlp2AuthzDecisionQuery_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2AuthzDecisionQuery_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2AuthzDecisionQuery_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2AuthzDecisionQuery_Destination_get, _lasso.Samlp2AuthzDecisionQuery_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2AuthzDecisionQuery_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2AuthzDecisionQuery_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2AuthzDecisionQuery_Consent_get, _lasso.Samlp2AuthzDecisionQuery_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2AuthzDecisionQuery(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2AuthzDecisionQuery
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2AuthzDecisionQuery_dump(*args)
_lasso.Samlp2AuthzDecisionQuery_swigregister(Samlp2AuthzDecisionQuery)

class Samlp2AttributeQuery(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2AttributeQuery, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2AttributeQuery, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2AttributeQuery instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["attribute"] = _lasso.Samlp2AttributeQuery_attribute_set
    __swig_getmethods__["attribute"] = _lasso.Samlp2AttributeQuery_attribute_get
    if _newclass:attribute = property(_lasso.Samlp2AttributeQuery_attribute_get, _lasso.Samlp2AttributeQuery_attribute_set)
    __swig_setmethods__["Subject"] = _lasso.Samlp2AttributeQuery_Subject_set
    __swig_getmethods__["Subject"] = _lasso.Samlp2AttributeQuery_Subject_get
    if _newclass:Subject = property(_lasso.Samlp2AttributeQuery_Subject_get, _lasso.Samlp2AttributeQuery_Subject_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2AttributeQuery_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2AttributeQuery_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2AttributeQuery_issuer_get, _lasso.Samlp2AttributeQuery_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2AttributeQuery_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2AttributeQuery_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2AttributeQuery_Extensions_get, _lasso.Samlp2AttributeQuery_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2AttributeQuery_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2AttributeQuery_ID_get
    if _newclass:ID = property(_lasso.Samlp2AttributeQuery_ID_get, _lasso.Samlp2AttributeQuery_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2AttributeQuery_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2AttributeQuery_Version_get
    if _newclass:Version = property(_lasso.Samlp2AttributeQuery_Version_get, _lasso.Samlp2AttributeQuery_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2AttributeQuery_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2AttributeQuery_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2AttributeQuery_issueInstant_get, _lasso.Samlp2AttributeQuery_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2AttributeQuery_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2AttributeQuery_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2AttributeQuery_Destination_get, _lasso.Samlp2AttributeQuery_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2AttributeQuery_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2AttributeQuery_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2AttributeQuery_Consent_get, _lasso.Samlp2AttributeQuery_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2AttributeQuery(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2AttributeQuery
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2AttributeQuery_dump(*args)
_lasso.Samlp2AttributeQuery_swigregister(Samlp2AttributeQuery)

class Saml2AudienceRestriction(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2AudienceRestriction, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2AudienceRestriction, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2AudienceRestriction instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["Audience"] = _lasso.Saml2AudienceRestriction_Audience_set
    __swig_getmethods__["Audience"] = _lasso.Saml2AudienceRestriction_Audience_get
    if _newclass:Audience = property(_lasso.Saml2AudienceRestriction_Audience_get, _lasso.Saml2AudienceRestriction_Audience_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2AudienceRestriction(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2AudienceRestriction
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2AudienceRestriction_dump(*args)
_lasso.Saml2AudienceRestriction_swigregister(Saml2AudienceRestriction)

class Samlp2LogoutRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2LogoutRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2LogoutRequest, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2LogoutRequest instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["sessionIndex"] = _lasso.Samlp2LogoutRequest_sessionIndex_set
    __swig_getmethods__["sessionIndex"] = _lasso.Samlp2LogoutRequest_sessionIndex_get
    if _newclass:sessionIndex = property(_lasso.Samlp2LogoutRequest_sessionIndex_get, _lasso.Samlp2LogoutRequest_sessionIndex_set)
    __swig_setmethods__["Reason"] = _lasso.Samlp2LogoutRequest_Reason_set
    __swig_getmethods__["Reason"] = _lasso.Samlp2LogoutRequest_Reason_get
    if _newclass:Reason = property(_lasso.Samlp2LogoutRequest_Reason_get, _lasso.Samlp2LogoutRequest_Reason_set)
    __swig_setmethods__["notOnOrAfter"] = _lasso.Samlp2LogoutRequest_notOnOrAfter_set
    __swig_getmethods__["notOnOrAfter"] = _lasso.Samlp2LogoutRequest_notOnOrAfter_get
    if _newclass:notOnOrAfter = property(_lasso.Samlp2LogoutRequest_notOnOrAfter_get, _lasso.Samlp2LogoutRequest_notOnOrAfter_set)
    __swig_setmethods__["baseID"] = _lasso.Samlp2LogoutRequest_baseID_set
    __swig_getmethods__["baseID"] = _lasso.Samlp2LogoutRequest_baseID_get
    if _newclass:baseID = property(_lasso.Samlp2LogoutRequest_baseID_get, _lasso.Samlp2LogoutRequest_baseID_set)
    __swig_setmethods__["nameID"] = _lasso.Samlp2LogoutRequest_nameID_set
    __swig_getmethods__["nameID"] = _lasso.Samlp2LogoutRequest_nameID_get
    if _newclass:nameID = property(_lasso.Samlp2LogoutRequest_nameID_get, _lasso.Samlp2LogoutRequest_nameID_set)
    __swig_setmethods__["encryptedID"] = _lasso.Samlp2LogoutRequest_encryptedID_set
    __swig_getmethods__["encryptedID"] = _lasso.Samlp2LogoutRequest_encryptedID_get
    if _newclass:encryptedID = property(_lasso.Samlp2LogoutRequest_encryptedID_get, _lasso.Samlp2LogoutRequest_encryptedID_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2LogoutRequest_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2LogoutRequest_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2LogoutRequest_issuer_get, _lasso.Samlp2LogoutRequest_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2LogoutRequest_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2LogoutRequest_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2LogoutRequest_Extensions_get, _lasso.Samlp2LogoutRequest_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2LogoutRequest_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2LogoutRequest_ID_get
    if _newclass:ID = property(_lasso.Samlp2LogoutRequest_ID_get, _lasso.Samlp2LogoutRequest_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2LogoutRequest_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2LogoutRequest_Version_get
    if _newclass:Version = property(_lasso.Samlp2LogoutRequest_Version_get, _lasso.Samlp2LogoutRequest_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2LogoutRequest_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2LogoutRequest_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2LogoutRequest_issueInstant_get, _lasso.Samlp2LogoutRequest_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2LogoutRequest_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2LogoutRequest_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2LogoutRequest_Destination_get, _lasso.Samlp2LogoutRequest_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2LogoutRequest_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2LogoutRequest_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2LogoutRequest_Consent_get, _lasso.Samlp2LogoutRequest_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2LogoutRequest(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2LogoutRequest
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2LogoutRequest_dump(*args)
_lasso.Samlp2LogoutRequest_swigregister(Samlp2LogoutRequest)

class Samlp2AuthnQuery(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2AuthnQuery, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2AuthnQuery, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2AuthnQuery instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["sessionIndex"] = _lasso.Samlp2AuthnQuery_sessionIndex_set
    __swig_getmethods__["sessionIndex"] = _lasso.Samlp2AuthnQuery_sessionIndex_get
    if _newclass:sessionIndex = property(_lasso.Samlp2AuthnQuery_sessionIndex_get, _lasso.Samlp2AuthnQuery_sessionIndex_set)
    __swig_setmethods__["requestedAuthnContext"] = _lasso.Samlp2AuthnQuery_requestedAuthnContext_set
    __swig_getmethods__["requestedAuthnContext"] = _lasso.Samlp2AuthnQuery_requestedAuthnContext_get
    if _newclass:requestedAuthnContext = property(_lasso.Samlp2AuthnQuery_requestedAuthnContext_get, _lasso.Samlp2AuthnQuery_requestedAuthnContext_set)
    __swig_setmethods__["Subject"] = _lasso.Samlp2AuthnQuery_Subject_set
    __swig_getmethods__["Subject"] = _lasso.Samlp2AuthnQuery_Subject_get
    if _newclass:Subject = property(_lasso.Samlp2AuthnQuery_Subject_get, _lasso.Samlp2AuthnQuery_Subject_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2AuthnQuery_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2AuthnQuery_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2AuthnQuery_issuer_get, _lasso.Samlp2AuthnQuery_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2AuthnQuery_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2AuthnQuery_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2AuthnQuery_Extensions_get, _lasso.Samlp2AuthnQuery_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2AuthnQuery_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2AuthnQuery_ID_get
    if _newclass:ID = property(_lasso.Samlp2AuthnQuery_ID_get, _lasso.Samlp2AuthnQuery_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2AuthnQuery_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2AuthnQuery_Version_get
    if _newclass:Version = property(_lasso.Samlp2AuthnQuery_Version_get, _lasso.Samlp2AuthnQuery_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2AuthnQuery_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2AuthnQuery_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2AuthnQuery_issueInstant_get, _lasso.Samlp2AuthnQuery_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2AuthnQuery_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2AuthnQuery_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2AuthnQuery_Destination_get, _lasso.Samlp2AuthnQuery_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2AuthnQuery_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2AuthnQuery_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2AuthnQuery_Consent_get, _lasso.Samlp2AuthnQuery_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2AuthnQuery(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2AuthnQuery
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2AuthnQuery_dump(*args)
_lasso.Samlp2AuthnQuery_swigregister(Samlp2AuthnQuery)

class Saml2Attribute(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2Attribute, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2Attribute, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2Attribute instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["Name"] = _lasso.Saml2Attribute_Name_set
    __swig_getmethods__["Name"] = _lasso.Saml2Attribute_Name_get
    if _newclass:Name = property(_lasso.Saml2Attribute_Name_get, _lasso.Saml2Attribute_Name_set)
    __swig_setmethods__["NameFormat"] = _lasso.Saml2Attribute_NameFormat_set
    __swig_getmethods__["NameFormat"] = _lasso.Saml2Attribute_NameFormat_get
    if _newclass:NameFormat = property(_lasso.Saml2Attribute_NameFormat_get, _lasso.Saml2Attribute_NameFormat_set)
    __swig_setmethods__["FriendlyName"] = _lasso.Saml2Attribute_FriendlyName_set
    __swig_getmethods__["FriendlyName"] = _lasso.Saml2Attribute_FriendlyName_get
    if _newclass:FriendlyName = property(_lasso.Saml2Attribute_FriendlyName_get, _lasso.Saml2Attribute_FriendlyName_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2Attribute(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2Attribute
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2Attribute_dump(*args)
_lasso.Saml2Attribute_swigregister(Saml2Attribute)

class Samlp2Terminate(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2Terminate, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2Terminate, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2Terminate instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Samlp2Terminate(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2Terminate
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2Terminate_dump(*args)
_lasso.Samlp2Terminate_swigregister(Samlp2Terminate)

class Samlp2StatusDetail(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2StatusDetail, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2StatusDetail, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2StatusDetail instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Samlp2StatusDetail(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2StatusDetail
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2StatusDetail_dump(*args)
_lasso.Samlp2StatusDetail_swigregister(Samlp2StatusDetail)

class Saml2AuthzDecisionStatement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2AuthzDecisionStatement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2AuthzDecisionStatement, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2AuthzDecisionStatement instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["Resource"] = _lasso.Saml2AuthzDecisionStatement_Resource_set
    __swig_getmethods__["Resource"] = _lasso.Saml2AuthzDecisionStatement_Resource_get
    if _newclass:Resource = property(_lasso.Saml2AuthzDecisionStatement_Resource_get, _lasso.Saml2AuthzDecisionStatement_Resource_set)
    __swig_setmethods__["Decision"] = _lasso.Saml2AuthzDecisionStatement_Decision_set
    __swig_getmethods__["Decision"] = _lasso.Saml2AuthzDecisionStatement_Decision_get
    if _newclass:Decision = property(_lasso.Saml2AuthzDecisionStatement_Decision_get, _lasso.Saml2AuthzDecisionStatement_Decision_set)
    __swig_setmethods__["action"] = _lasso.Saml2AuthzDecisionStatement_action_set
    __swig_getmethods__["action"] = _lasso.Saml2AuthzDecisionStatement_action_get
    if _newclass:action = property(_lasso.Saml2AuthzDecisionStatement_action_get, _lasso.Saml2AuthzDecisionStatement_action_set)
    __swig_setmethods__["evidence"] = _lasso.Saml2AuthzDecisionStatement_evidence_set
    __swig_getmethods__["evidence"] = _lasso.Saml2AuthzDecisionStatement_evidence_get
    if _newclass:evidence = property(_lasso.Saml2AuthzDecisionStatement_evidence_get, _lasso.Saml2AuthzDecisionStatement_evidence_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2AuthzDecisionStatement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2AuthzDecisionStatement
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2AuthzDecisionStatement_dump(*args)
_lasso.Saml2AuthzDecisionStatement_swigregister(Saml2AuthzDecisionStatement)

class Samlp2NameIDMappingResponse(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2NameIDMappingResponse, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2NameIDMappingResponse, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2NameIDMappingResponse instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["nameID"] = _lasso.Samlp2NameIDMappingResponse_nameID_set
    __swig_getmethods__["nameID"] = _lasso.Samlp2NameIDMappingResponse_nameID_get
    if _newclass:nameID = property(_lasso.Samlp2NameIDMappingResponse_nameID_get, _lasso.Samlp2NameIDMappingResponse_nameID_set)
    __swig_setmethods__["encryptedID"] = _lasso.Samlp2NameIDMappingResponse_encryptedID_set
    __swig_getmethods__["encryptedID"] = _lasso.Samlp2NameIDMappingResponse_encryptedID_get
    if _newclass:encryptedID = property(_lasso.Samlp2NameIDMappingResponse_encryptedID_get, _lasso.Samlp2NameIDMappingResponse_encryptedID_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2NameIDMappingResponse_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2NameIDMappingResponse_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2NameIDMappingResponse_issuer_get, _lasso.Samlp2NameIDMappingResponse_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2NameIDMappingResponse_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2NameIDMappingResponse_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2NameIDMappingResponse_Extensions_get, _lasso.Samlp2NameIDMappingResponse_Extensions_set)
    __swig_setmethods__["Status"] = _lasso.Samlp2NameIDMappingResponse_Status_set
    __swig_getmethods__["Status"] = _lasso.Samlp2NameIDMappingResponse_Status_get
    if _newclass:Status = property(_lasso.Samlp2NameIDMappingResponse_Status_get, _lasso.Samlp2NameIDMappingResponse_Status_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2NameIDMappingResponse_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2NameIDMappingResponse_ID_get
    if _newclass:ID = property(_lasso.Samlp2NameIDMappingResponse_ID_get, _lasso.Samlp2NameIDMappingResponse_ID_set)
    __swig_setmethods__["inResponseTo"] = _lasso.Samlp2NameIDMappingResponse_inResponseTo_set
    __swig_getmethods__["inResponseTo"] = _lasso.Samlp2NameIDMappingResponse_inResponseTo_get
    if _newclass:inResponseTo = property(_lasso.Samlp2NameIDMappingResponse_inResponseTo_get, _lasso.Samlp2NameIDMappingResponse_inResponseTo_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2NameIDMappingResponse_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2NameIDMappingResponse_Version_get
    if _newclass:Version = property(_lasso.Samlp2NameIDMappingResponse_Version_get, _lasso.Samlp2NameIDMappingResponse_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2NameIDMappingResponse_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2NameIDMappingResponse_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2NameIDMappingResponse_issueInstant_get, _lasso.Samlp2NameIDMappingResponse_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2NameIDMappingResponse_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2NameIDMappingResponse_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2NameIDMappingResponse_Destination_get, _lasso.Samlp2NameIDMappingResponse_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2NameIDMappingResponse_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2NameIDMappingResponse_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2NameIDMappingResponse_Consent_get, _lasso.Samlp2NameIDMappingResponse_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2NameIDMappingResponse(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2NameIDMappingResponse
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2NameIDMappingResponse_dump(*args)
_lasso.Samlp2NameIDMappingResponse_swigregister(Samlp2NameIDMappingResponse)

class Saml2EncryptedElement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2EncryptedElement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2EncryptedElement, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2EncryptedElement instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    def __init__(self, *args):
        this = _lasso.new_Saml2EncryptedElement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2EncryptedElement
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2EncryptedElement_dump(*args)
_lasso.Saml2EncryptedElement_swigregister(Saml2EncryptedElement)

class Samlp2ManageNameIDRequest(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2ManageNameIDRequest, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2ManageNameIDRequest, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2ManageNameIDRequest instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["NewID"] = _lasso.Samlp2ManageNameIDRequest_NewID_set
    __swig_getmethods__["NewID"] = _lasso.Samlp2ManageNameIDRequest_NewID_get
    if _newclass:NewID = property(_lasso.Samlp2ManageNameIDRequest_NewID_get, _lasso.Samlp2ManageNameIDRequest_NewID_set)
    __swig_setmethods__["nameID"] = _lasso.Samlp2ManageNameIDRequest_nameID_set
    __swig_getmethods__["nameID"] = _lasso.Samlp2ManageNameIDRequest_nameID_get
    if _newclass:nameID = property(_lasso.Samlp2ManageNameIDRequest_nameID_get, _lasso.Samlp2ManageNameIDRequest_nameID_set)
    __swig_setmethods__["encryptedID"] = _lasso.Samlp2ManageNameIDRequest_encryptedID_set
    __swig_getmethods__["encryptedID"] = _lasso.Samlp2ManageNameIDRequest_encryptedID_get
    if _newclass:encryptedID = property(_lasso.Samlp2ManageNameIDRequest_encryptedID_get, _lasso.Samlp2ManageNameIDRequest_encryptedID_set)
    __swig_setmethods__["newEncryptedID"] = _lasso.Samlp2ManageNameIDRequest_newEncryptedID_set
    __swig_getmethods__["newEncryptedID"] = _lasso.Samlp2ManageNameIDRequest_newEncryptedID_get
    if _newclass:newEncryptedID = property(_lasso.Samlp2ManageNameIDRequest_newEncryptedID_get, _lasso.Samlp2ManageNameIDRequest_newEncryptedID_set)
    __swig_setmethods__["terminate"] = _lasso.Samlp2ManageNameIDRequest_terminate_set
    __swig_getmethods__["terminate"] = _lasso.Samlp2ManageNameIDRequest_terminate_get
    if _newclass:terminate = property(_lasso.Samlp2ManageNameIDRequest_terminate_get, _lasso.Samlp2ManageNameIDRequest_terminate_set)
    __swig_setmethods__["issuer"] = _lasso.Samlp2ManageNameIDRequest_issuer_set
    __swig_getmethods__["issuer"] = _lasso.Samlp2ManageNameIDRequest_issuer_get
    if _newclass:issuer = property(_lasso.Samlp2ManageNameIDRequest_issuer_get, _lasso.Samlp2ManageNameIDRequest_issuer_set)
    __swig_setmethods__["Extensions"] = _lasso.Samlp2ManageNameIDRequest_Extensions_set
    __swig_getmethods__["Extensions"] = _lasso.Samlp2ManageNameIDRequest_Extensions_get
    if _newclass:Extensions = property(_lasso.Samlp2ManageNameIDRequest_Extensions_get, _lasso.Samlp2ManageNameIDRequest_Extensions_set)
    __swig_setmethods__["ID"] = _lasso.Samlp2ManageNameIDRequest_ID_set
    __swig_getmethods__["ID"] = _lasso.Samlp2ManageNameIDRequest_ID_get
    if _newclass:ID = property(_lasso.Samlp2ManageNameIDRequest_ID_get, _lasso.Samlp2ManageNameIDRequest_ID_set)
    __swig_setmethods__["Version"] = _lasso.Samlp2ManageNameIDRequest_Version_set
    __swig_getmethods__["Version"] = _lasso.Samlp2ManageNameIDRequest_Version_get
    if _newclass:Version = property(_lasso.Samlp2ManageNameIDRequest_Version_get, _lasso.Samlp2ManageNameIDRequest_Version_set)
    __swig_setmethods__["issueInstant"] = _lasso.Samlp2ManageNameIDRequest_issueInstant_set
    __swig_getmethods__["issueInstant"] = _lasso.Samlp2ManageNameIDRequest_issueInstant_get
    if _newclass:issueInstant = property(_lasso.Samlp2ManageNameIDRequest_issueInstant_get, _lasso.Samlp2ManageNameIDRequest_issueInstant_set)
    __swig_setmethods__["Destination"] = _lasso.Samlp2ManageNameIDRequest_Destination_set
    __swig_getmethods__["Destination"] = _lasso.Samlp2ManageNameIDRequest_Destination_get
    if _newclass:Destination = property(_lasso.Samlp2ManageNameIDRequest_Destination_get, _lasso.Samlp2ManageNameIDRequest_Destination_set)
    __swig_setmethods__["Consent"] = _lasso.Samlp2ManageNameIDRequest_Consent_set
    __swig_getmethods__["Consent"] = _lasso.Samlp2ManageNameIDRequest_Consent_get
    if _newclass:Consent = property(_lasso.Samlp2ManageNameIDRequest_Consent_get, _lasso.Samlp2ManageNameIDRequest_Consent_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2ManageNameIDRequest(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2ManageNameIDRequest
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2ManageNameIDRequest_dump(*args)
_lasso.Samlp2ManageNameIDRequest_swigregister(Samlp2ManageNameIDRequest)

class Samlp2Scoping(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Samlp2Scoping, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Samlp2Scoping, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSamlp2Scoping instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["RequesterID"] = _lasso.Samlp2Scoping_RequesterID_set
    __swig_getmethods__["RequesterID"] = _lasso.Samlp2Scoping_RequesterID_get
    if _newclass:RequesterID = property(_lasso.Samlp2Scoping_RequesterID_get, _lasso.Samlp2Scoping_RequesterID_set)
    __swig_setmethods__["ProxyCount"] = _lasso.Samlp2Scoping_ProxyCount_set
    __swig_getmethods__["ProxyCount"] = _lasso.Samlp2Scoping_ProxyCount_get
    if _newclass:ProxyCount = property(_lasso.Samlp2Scoping_ProxyCount_get, _lasso.Samlp2Scoping_ProxyCount_set)
    __swig_setmethods__["iDPList"] = _lasso.Samlp2Scoping_iDPList_set
    __swig_getmethods__["iDPList"] = _lasso.Samlp2Scoping_iDPList_get
    if _newclass:iDPList = property(_lasso.Samlp2Scoping_iDPList_get, _lasso.Samlp2Scoping_iDPList_set)
    def __init__(self, *args):
        this = _lasso.new_Samlp2Scoping(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Samlp2Scoping
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Samlp2Scoping_dump(*args)
_lasso.Samlp2Scoping_swigregister(Samlp2Scoping)

class Saml2Subject(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Saml2Subject, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Saml2Subject, name)
    def __repr__(self):
        try: strthis = "at 0x%x" %( self.this, ) 
        except: strthis = "" 
        return "<%s.%s; proxy of C LassoSaml2Subject instance %s>" % (self.__class__.__module__, self.__class__.__name__, strthis,)
    __swig_setmethods__["baseID"] = _lasso.Saml2Subject_baseID_set
    __swig_getmethods__["baseID"] = _lasso.Saml2Subject_baseID_get
    if _newclass:baseID = property(_lasso.Saml2Subject_baseID_get, _lasso.Saml2Subject_baseID_set)
    __swig_setmethods__["nameID"] = _lasso.Saml2Subject_nameID_set
    __swig_getmethods__["nameID"] = _lasso.Saml2Subject_nameID_get
    if _newclass:nameID = property(_lasso.Saml2Subject_nameID_get, _lasso.Saml2Subject_nameID_set)
    __swig_setmethods__["encryptedID"] = _lasso.Saml2Subject_encryptedID_set
    __swig_getmethods__["encryptedID"] = _lasso.Saml2Subject_encryptedID_get
    if _newclass:encryptedID = property(_lasso.Saml2Subject_encryptedID_get, _lasso.Saml2Subject_encryptedID_set)
    __swig_setmethods__["subjectConfirmation"] = _lasso.Saml2Subject_subjectConfirmation_set
    __swig_getmethods__["subjectConfirmation"] = _lasso.Saml2Subject_subjectConfirmation_get
    if _newclass:subjectConfirmation = property(_lasso.Saml2Subject_subjectConfirmation_get, _lasso.Saml2Subject_subjectConfirmation_set)
    def __init__(self, *args):
        this = _lasso.new_Saml2Subject(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _lasso.delete_Saml2Subject
    __del__ = lambda self : None;
    def dump(*args): return _lasso.Saml2Subject_dump(*args)
_lasso.Saml2Subject_swigregister(Saml2Subject)



