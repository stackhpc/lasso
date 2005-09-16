/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.24
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

/*
  +----------------------------------------------------------------------+
  | PHP version 4.0                                                      |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997, 1998, 1999, 2000, 2001 The PHP Group             |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.02 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available at through the world-wide-web at                           |
  | http://www.php.net/license/2_02.txt.                                 |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors:                                                             |
  |                                                                      |
  +----------------------------------------------------------------------+
 */


#ifndef PHP_LASSO_H
#define PHP_LASSO_H

extern zend_module_entry lasso_module_entry;
#define phpext_lasso_ptr &lasso_module_entry

#ifdef PHP_WIN32
# define PHP_LASSO_API __declspec(dllexport)
#else
# define PHP_LASSO_API
#endif

PHP_MINIT_FUNCTION(lasso);
PHP_MSHUTDOWN_FUNCTION(lasso);
PHP_RINIT_FUNCTION(lasso);
PHP_RSHUTDOWN_FUNCTION(lasso);
PHP_MINFO_FUNCTION(lasso);

ZEND_NAMED_FUNCTION(_wrap_lasso_init);
ZEND_NAMED_FUNCTION(_wrap_lasso_shutdown);
ZEND_NAMED_FUNCTION(_wrap_lasso_check_version);
ZEND_NAMED_FUNCTION(_wrap_new_LassoNode);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoNode);
ZEND_NAMED_FUNCTION(_wrap_LassoNode_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoNodeList);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoNodeList);
ZEND_NAMED_FUNCTION(_wrap_LassoNodeList_append);
ZEND_NAMED_FUNCTION(_wrap_LassoNodeList_cast);
ZEND_NAMED_FUNCTION(_wrap_LassoNodeList_frompointer);
ZEND_NAMED_FUNCTION(_wrap_LassoNodeList_getItem);
ZEND_NAMED_FUNCTION(_wrap_LassoNodeList_length);
ZEND_NAMED_FUNCTION(_wrap_LassoNodeList_setItem);
ZEND_NAMED_FUNCTION(_wrap_new_LassoStringList);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoStringList);
ZEND_NAMED_FUNCTION(_wrap_LassoStringList_append);
ZEND_NAMED_FUNCTION(_wrap_LassoStringList_cast);
ZEND_NAMED_FUNCTION(_wrap_LassoStringList_frompointer);
ZEND_NAMED_FUNCTION(_wrap_LassoStringList_getItem);
ZEND_NAMED_FUNCTION(_wrap_LassoStringList_length);
ZEND_NAMED_FUNCTION(_wrap_LassoStringList_setItem);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlAdvice);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlAdvice);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlAdvice_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlAssertion);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlAssertion);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlAssertion_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlAttribute);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlAttribute);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlAttribute_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlAttributeDesignator);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlAttributeDesignator);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlAttributeDesignator_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlAttributeStatement);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlAttributeStatement);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlAttributeStatement_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlAttributeValue);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlAttributeValue);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlAttributeValue_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlAudienceRestrictionCondition);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlAudienceRestrictionCondition);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlAudienceRestrictionCondition_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlAuthenticationStatement);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlAuthenticationStatement);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlAuthenticationStatement_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlAuthorityBinding);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlAuthorityBinding);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlAuthorityBinding_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlConditionAbstract_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlConditionAbstract);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlConditions);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlConditions);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlConditions_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlNameIdentifier);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlNameIdentifier);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlNameIdentifier_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlStatementAbstract_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlStatementAbstract);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlSubject);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlSubject);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlSubject_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlSubjectConfirmation);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlSubjectConfirmation);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlSubjectConfirmation_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlSubjectLocality);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlSubjectLocality);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlSubjectLocality_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlSubjectStatement);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlSubjectStatement);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlSubjectStatement_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlSubjectStatementAbstract_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlSubjectStatementAbstract);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlpRequest);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlpRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlpRequest_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlpRequestAbstract_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlpRequestAbstract);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlpResponse);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlpResponse);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlpResponse_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlpResponseAbstract_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlpResponseAbstract);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlpStatus);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlpStatus);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlpStatus_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSamlpStatusCode);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSamlpStatusCode);
ZEND_NAMED_FUNCTION(_wrap_LassoSamlpStatusCode_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibAssertion);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibAssertion);
ZEND_NAMED_FUNCTION(_wrap_LassoLibAssertion_newFull);
ZEND_NAMED_FUNCTION(_wrap_LassoLibAssertion_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibAuthnRequest);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibAuthnRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoLibAuthnRequest_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibAuthnResponse);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibAuthnResponse);
ZEND_NAMED_FUNCTION(_wrap_LassoLibAuthnResponse_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibFederationTerminationNotification);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibFederationTerminationNotification);
ZEND_NAMED_FUNCTION(_wrap_LassoLibFederationTerminationNotification_newFull);
ZEND_NAMED_FUNCTION(_wrap_LassoLibFederationTerminationNotification_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibLogoutRequest);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibLogoutRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoLibLogoutRequest_newFull);
ZEND_NAMED_FUNCTION(_wrap_LassoLibLogoutRequest_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibLogoutResponse);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibLogoutResponse);
ZEND_NAMED_FUNCTION(_wrap_LassoLibLogoutResponse_newFull);
ZEND_NAMED_FUNCTION(_wrap_LassoLibLogoutResponse_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibRegisterNameIdentifierRequest);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibRegisterNameIdentifierRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoLibRegisterNameIdentifierRequest_newFull);
ZEND_NAMED_FUNCTION(_wrap_LassoLibRegisterNameIdentifierRequest_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibRegisterNameIdentifierResponse);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibRegisterNameIdentifierResponse);
ZEND_NAMED_FUNCTION(_wrap_LassoLibRegisterNameIdentifierResponse_newFull);
ZEND_NAMED_FUNCTION(_wrap_LassoLibRegisterNameIdentifierResponse_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibRequestAuthnContext);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibRequestAuthnContext);
ZEND_NAMED_FUNCTION(_wrap_LassoLibRequestAuthnContext_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLibStatusResponse);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLibStatusResponse);
ZEND_NAMED_FUNCTION(_wrap_LassoLibStatusResponse_dump);
ZEND_NAMED_FUNCTION(_wrap_new_LassoProvider);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoProvider);
ZEND_NAMED_FUNCTION(_wrap_LassoProvider_newFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoProvider_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoProvider_acceptHttpMethod);
ZEND_NAMED_FUNCTION(_wrap_LassoProvider_getAssertionConsumerServiceUrl);
ZEND_NAMED_FUNCTION(_wrap_LassoProvider_getBase64SuccinctId);
ZEND_NAMED_FUNCTION(_wrap_LassoProvider_getOrganization);
ZEND_NAMED_FUNCTION(_wrap_LassoProvider_getFirstHttpMethod);
ZEND_NAMED_FUNCTION(_wrap_LassoProvider_getMetadataOne);
ZEND_NAMED_FUNCTION(_wrap_LassoProvider_hasProtocolProfile);
ZEND_NAMED_FUNCTION(_wrap_new_LassoServer);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoServer);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_newFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_acceptHttpMethod);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_getAssertionConsumerServiceUrl);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_getBase64SuccinctId);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_getOrganization);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_getFirstHttpMethod);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_getMetadataOne);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_hasProtocolProfile);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_addProvider);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoServer_getProvider);
ZEND_NAMED_FUNCTION(_wrap_new_LassoFederation);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoFederation);
ZEND_NAMED_FUNCTION(_wrap_LassoFederation_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoFederation_buildLocalNameIdentifier);
ZEND_NAMED_FUNCTION(_wrap_LassoFederation_verifyNameIdentifier);
ZEND_NAMED_FUNCTION(_wrap_new_LassoIdentity);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoIdentity);
ZEND_NAMED_FUNCTION(_wrap_LassoIdentity_newFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoIdentity_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoIdentity_getFederation);
ZEND_NAMED_FUNCTION(_wrap_new_LassoSession);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoSession);
ZEND_NAMED_FUNCTION(_wrap_LassoSession_newFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoSession_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoSession_getAssertions);
ZEND_NAMED_FUNCTION(_wrap_lasso_getRequestTypeFromSoapMsg);
ZEND_NAMED_FUNCTION(_wrap_lasso_isLibertyQuery);
ZEND_NAMED_FUNCTION(_wrap_new_LassoDefederation);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoDefederation);
ZEND_NAMED_FUNCTION(_wrap_LassoDefederation_setIdentityFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoDefederation_setSessionFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoDefederation_buildNotificationMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoDefederation_initNotification);
ZEND_NAMED_FUNCTION(_wrap_LassoDefederation_processNotificationMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoDefederation_validateNotification);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLogin);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLogin);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_newFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_setIdentityFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_setSessionFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_acceptSso);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_buildArtifactMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_buildAssertion);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_buildAuthnRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_buildAuthnResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_buildRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_buildResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_initAuthnRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_initRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_initIdpInitiatedAuthnRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_mustAskForConsent);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_mustAuthenticate);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_processAuthnRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_processAuthnResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_processRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_processResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_setResourceId);
ZEND_NAMED_FUNCTION(_wrap_LassoLogin_validateRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLogout);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLogout);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_newFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_setIdentityFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_setSessionFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_buildRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_buildResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_getNextProviderId);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_initRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_processRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_processResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_resetProviderIdIndex);
ZEND_NAMED_FUNCTION(_wrap_LassoLogout_validateRequest);
ZEND_NAMED_FUNCTION(_wrap_new_LassoLecp);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoLecp);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_setIdentityFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_setSessionFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_buildAssertion);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_setResourceId);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_validateRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_buildAuthnRequestEnvelopeMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_buildAuthnRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_buildAuthnResponseEnvelopeMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_buildAuthnResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_initAuthnRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_processAuthnRequestEnvelopeMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_processAuthnRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoLecp_processAuthnResponseEnvelopeMsg);
ZEND_NAMED_FUNCTION(_wrap_new_LassoNameIdentifierMapping);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoNameIdentifierMapping);
ZEND_NAMED_FUNCTION(_wrap_LassoNameIdentifierMapping_setIdentityFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoNameIdentifierMapping_setSessionFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoNameIdentifierMapping_buildRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoNameIdentifierMapping_buildResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoNameIdentifierMapping_initRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoNameIdentifierMapping_processRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoNameIdentifierMapping_processResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoNameIdentifierMapping_validateRequest);
ZEND_NAMED_FUNCTION(_wrap_new_LassoNameRegistration);
ZEND_NAMED_FUNCTION(_wrap_delete_LassoNameRegistration);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_newFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_setIdentityFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_setSessionFromDump);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_buildRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_buildResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_dump);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_initRequest);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_processRequestMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_processResponseMsg);
ZEND_NAMED_FUNCTION(_wrap_LassoNameRegistration_validateRequest);
/*If you declare any globals in php_lasso.h uncomment this:
ZEND_BEGIN_MODULE_GLOBALS(lasso)
ZEND_END_MODULE_GLOBALS(lasso)
*/
#ifdef ZTS
#define LASSO_D  zend_lasso_globals *lasso_globals
#define LASSO_DC  , LASSO_D
#define LASSO_C  lasso_globals
#define LASSO_CC  , LASSO_C
#define LASSO_SG(v)  (lasso_globals->v)
#define LASSO_FETCH()  zend_lasso_globals *lasso_globals = ts_resource(lasso_globals_id)
#else
#define LASSO_D
#define LASSO_DC
#define LASSO_C
#define LASSO_CC
#define LASSO_SG(v)  (lasso_globals.v)
#define LASSO_FETCH()
#endif

#endif /* PHP_LASSO_H */
