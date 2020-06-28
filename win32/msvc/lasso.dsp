# Microsoft Developer Studio Project File - Name="lasso" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=LASSO - WIN32 DEBUG
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lasso.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lasso.mak" CFG="LASSO - WIN32 DEBUG"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lasso - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "lasso - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lasso - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Build"
# PROP Intermediate_Dir "Build"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "LASSO_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "h:\lasso-deps\include" /I "h:\lasso-deps\include\glib-2.0" /I "h:\lasso-deps\lib\glib-2.0\include" /I "..\.." /I ".." /I "..\..\.." /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "IN_LASSO" /D XMLSEC_CRYPTO=\"openssl\" /D XMLSEC_LIBXML_260=1 /D XMLSEC_NO_XKMS=1 /D XMLSEC_CRYPTO_OPENSSL=1 /D "LASSO_INTERNALS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "NDEBUG"
# ADD RSC /l 0x40c /i "..\..\lasso" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib libxmlsec.lib glib-2.0.lib gobject-2.0.lib libxmlsec-openssl.lib libxml2.lib libeay32.lib ssleay32.lib libxslt.lib zdll.lib /nologo /dll /machine:I386 /out:"Release/liblasso-3.dll" /libpath:"h:\lasso-deps\lib"

!ELSEIF  "$(CFG)" == "lasso - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "LASSO_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "lasso" /I "h:\lasso-deps\include" /I "h:\lasso-deps\include\glib-2.0" /I "h:\lasso-deps\lib\glib-2.0\include" /I "..\.." /I ".." /I "..\..\.." /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "IN_LASSO" /D XMLSEC_CRYPTO=\"openssl\" /D XMLSEC_LIBXML_260=1 /D XMLSEC_NO_XKMS=1 /D XMLSEC_CRYPTO_OPENSSL=1 /D "LASSO_INTERNALS" /D "LASSO_DEBUG" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "_DEBUG"
# ADD RSC /l 0x40c /i "..\..\lasso" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib libxmlsec.lib glib-2.0.lib gobject-2.0.lib libxmlsec-openssl.lib libxml2.lib libeay32.lib ssleay32.lib libxslt.lib zdll.lib /nologo /dll /debug /machine:I386 /out:"Debug/liblasso-3.dll" /pdbtype:sept /libpath:"h:\lasso-deps\lib"

!ENDIF 

# Begin Target

# Name "lasso - Win32 Release"
# Name "lasso - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "c"
# Begin Group "xml C"

# PROP Default_Filter "c"
# Begin Group "xml saml-2.0 C"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_action.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_advice.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_assertion.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_attribute.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_attribute_statement.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_attribute_value.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_audience_restriction.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_authn_context.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_authn_statement.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_authz_decision_statement.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_base_idabstract.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_condition_abstract.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_conditions.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_encrypted_element.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_evidence.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_key_info_confirmation_data.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_name_id.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_one_time_use.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_proxy_restriction.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_statement_abstract.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_subject.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_subject_confirmation.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_subject_confirmation_data.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_subject_locality.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_artifact_resolve.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_artifact_response.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_assertion_idrequest.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_attribute_query.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_authn_query.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_authn_request.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_authz_decision_query.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_extensions.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_idp_entry.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_idp_list.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_logout_request.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_logout_response.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_manage_name_id_request.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_manage_name_id_response.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_name_id_mapping_request.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_name_id_mapping_response.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_name_id_policy.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_request_abstract.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_requested_authn_context.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_response.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_scoping.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_status.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_status_code.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_status_detail.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_status_response.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_subject_query_abstract.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_terminate.c"
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\lasso\xml\lib_assertion.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authentication_statement.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_context.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_request.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_request_envelope.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_response.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_response_envelope.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_federation_termination_notification.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_idp_entries.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_idp_entry.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_idp_list.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_logout_request.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_logout_response.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_name_identifier_mapping_request.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_name_identifier_mapping_response.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_register_name_identifier_request.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_register_name_identifier_response.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_request_authn_context.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_scoping.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_status_response.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_subject.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\misc_text_node.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_advice.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_assertion.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_attribute.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_attribute_designator.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_attribute_statement.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_attribute_value.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_audience_restriction_condition.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_authentication_statement.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_authority_binding.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_condition_abstract.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_conditions.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_name_identifier.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_statement_abstract.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject_confirmation.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject_locality.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject_statement.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject_statement_abstract.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_request.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_request_abstract.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_response.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_response_abstract.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_status.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_status_code.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\tools.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\utility_status.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\xml.c
# End Source File
# End Group
# Begin Group "id-ff C"

# PROP Default_Filter "c"
# Begin Source File

SOURCE="..\..\lasso\id-ff\defederation.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\federation.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\identity.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\lecp.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\login.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\logout.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\name_identifier_mapping.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\name_registration.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\profile.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\provider.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\server.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\session.c"
# End Source File
# End Group
# Begin Group "saml-2.0 C"

# PROP Default_Filter "c"
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\ecp.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\federation2.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\login2.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\logout2.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\name_id_management.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\profile2.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\provider2.c"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\server2.c"
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\lasso\errors.c
# End Source File
# Begin Source File

SOURCE=..\..\lasso\lasso.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h"
# Begin Group "xml H"

# PROP Default_Filter "h"
# Begin Group "xml saml-2.0 H"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_action.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_advice.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_assertion.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_attribute.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_attribute_statement.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_attribute_value.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_audience_restriction.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_authn_context.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_authn_statement.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_authz_decision_statement.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_base_idabstract.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_condition_abstract.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_conditions.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_encrypted_element.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_evidence.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_key_info_confirmation_data.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_name_id.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_one_time_use.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_proxy_restriction.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_statement_abstract.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_subject.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_subject_confirmation.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_subject_confirmation_data.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\saml2_subject_locality.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_artifact_resolve.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_artifact_response.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_assertion_idrequest.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_attribute_query.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_authn_query.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_authn_request.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_authz_decision_query.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_extensions.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_idp_entry.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_idp_list.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_logout_request.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_logout_response.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_manage_name_id_request.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_manage_name_id_response.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_name_id_mapping_request.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_name_id_mapping_response.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_name_id_policy.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_request_abstract.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_requested_authn_context.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_response.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_scoping.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_status.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_status_code.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_status_detail.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_status_response.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_subject_query_abstract.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\xml\saml-2.0\samlp2_terminate.h"
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\lasso\xml\lib_assertion.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authentication_statement.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_context.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_request.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_request_envelope.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_response.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_authn_response_envelope.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_federation_termination_notification.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_idp_entries.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_idp_entry.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_idp_list.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_logout_request.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_logout_response.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_name_identifier_mapping_request.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_name_identifier_mapping_response.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_register_name_identifier_request.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_register_name_identifier_response.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_request_authn_context.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_scoping.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_status_response.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\lib_subject.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\misc_text_node.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\private.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_advice.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_assertion.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_attribute.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_attribute_designator.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_attribute_statement.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_attribute_value.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_audience_restriction_condition.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_authentication_statement.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_authority_binding.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_condition_abstract.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_conditions.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_name_identifier.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_statement_abstract.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject_confirmation.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject_locality.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject_statement.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\saml_subject_statement_abstract.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_request.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_request_abstract.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_response.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_response_abstract.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_status.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\samlp_status_code.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\strings.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\utility_status.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\xml.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\xml\xml_enc.h
# End Source File
# End Group
# Begin Group "id-ff H"

# PROP Default_Filter "h"
# Begin Source File

SOURCE="..\..\lasso\id-ff\defederation.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\federation.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\identity.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\identityprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\lecp.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\login.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\logout.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\name_identifier_mapping.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\name_registration.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\profile.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\profileprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\provider.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\providerprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\server.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\serverprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\session.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\id-ff\sessionprivate.h"
# End Source File
# End Group
# Begin Group "saml-2.0 H"

# PROP Default_Filter "h"
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\ecp.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\ecpprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\federationprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\loginprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\logoutprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\name_id_management.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\profile.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\profileprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\providerprivate.h"
# End Source File
# Begin Source File

SOURCE="..\..\lasso\saml-2.0\serverprivate.h"
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\lasso\errors.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\export.h
# End Source File
# Begin Source File

SOURCE=..\..\lasso\lasso.h
# End Source File
# Begin Source File

SOURCE=.\lasso_config.h

!IF  "$(CFG)" == "lasso - Win32 Release"

# Begin Custom Build
InputPath=.\lasso_config.h
InputName=lasso_config

"..\..\$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) ..\..\lasso

# End Custom Build

!ELSEIF  "$(CFG)" == "lasso - Win32 Debug"

# Begin Custom Build
InputPath=.\lasso_config.h
InputName=lasso_config

"..\..\$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) ..\..\lasso

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\lasso.rc
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\lasso\extract_types.py

!IF  "$(CFG)" == "lasso - Win32 Release"

# Begin Custom Build
InputDir=\lasso\lasso-2.5.1\lasso
InputPath=..\..\lasso\extract_types.py

"$(InputDir)\types.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cd $(InputDir) 
	I:\Python24\python.exe extract_types.py 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "lasso - Win32 Debug"

# Begin Custom Build
InputDir=\lasso\lasso-2.5.1\lasso
InputPath=..\..\lasso\extract_types.py

"$(InputDir)\types.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cd $(InputDir) 
	I:\Python24\python.exe extract_types.py 
	
# End Custom Build

!ENDIF 

# End Source File
# End Target
# End Project
