; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "Liberty Alliance Single Sign On and all dependencies"
!define PRODUCT_VERSION "2.4.1"
!define PRODUCT_PUBLISHER "Entr'ouvert"
!define PRODUCT_WEB_SITE "http://www.entrouvert.org"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

SetCompressor bzip2

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; Language Selection Dialog Settings
!define MUI_LANGDLL_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_LANGDLL_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_LANGDLL_REGISTRY_VALUENAME "NSIS:Language"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!define MUI_LICENSEPAGE_RADIOBUTTONS
!insertmacro MUI_PAGE_LICENSE "..\..\COPYING"
; Components page
!insertmacro MUI_PAGE_COMPONENTS
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "French"

; Reserve files
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "Install-full-2_4_1.exe"
InstallDir "$SYSDIR"
ShowInstDetails show
ShowUnInstDetails show
AutoCloseWindow false
Function .onInit
  !insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

Section "GLIB: Low-level core library that forms the basis for projects such as GTK+ and GNOME." SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "c:\cygwin\usr\local\lib\libglib-2.0-0.dll"
  File "H:\lasso-deps\bin\libgobject-2.0-0.dll"
  File "H:\lasso-deps\bin\libgmodule-2.0-0.dll"
  File "H:\lasso-deps\bin\libgthread-2.0-0.dll"
SectionEnd

Section "LIBXML2: XML C parser and toolkit version 2.6.17." SEC02
  File "H:\lasso-deps\bin\libxml2.dll"
SectionEnd

Section "LIBXSLT: The XSLT C library version 1.2.12+." SEC03
  File "H:\lasso-deps\bin\libxslt.dll"
  File "H:\lasso-deps\bin\libexslt.dll"
SectionEnd

Section "LIBXMLSEC: XML Security Library C library (based on LibXML2) version 1.2.6." SEC04
  File "H:\lasso-deps\bin\libxmlsec.dll"
  File "H:\lasso-deps\bin\libxmlsec-mscrypto.dll"
  File "H:\lasso-deps\bin\libxmlsec-openssl.dll"
SectionEnd

Section "LIBOPENSSL: A  full-strength general purpose cryptography library version 0.9.7e." SEC05
  File "H:\lasso-deps\bin\libeay32.dll"
  File "H:\lasso-deps\bin\libssl32.dll"
SectionEnd

Section "ZLIB: A free, general-purpose, legally unencumbered -- that is, not covered by any patents -- lossless data-compression library version 1.2.1." SEC06
#  File "H:\lasso-deps\bin\zlib.dll"
  File "H:\lasso-deps\bin\zlib1.dll"
SectionEnd

Section "LIBICONV: Free iconv() implementation version 1.9.1." SEC07
  File "H:\lasso-deps\bin\iconv.dll"
SectionEnd

Section "LIBINTL: Library for native language support." SEC08
  File "H:\lasso-deps\bin\intl.dll"
SectionEnd

Section "Lasso version 2.4.1" SEC09
  File "..\msvc\Release\liblasso-3.dll"
SectionEnd

Section -AdditionalIcons
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateDirectory "$SMPROGRAMS\Liberty Alliance Single Sign On & Dependencies"
  CreateShortCut "$SMPROGRAMS\Liberty Alliance Single Sign On & Dependencies\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\Liberty Alliance Single Sign On & Dependencies\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd

; Section descriptions
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC01} "GLIB: Low-level core library that forms the basis for projects such as GTK+ and GNOME."
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC02} "LIBXML2: XML C parser and toolkit version 2.5.15."
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC03} "LIBXSLT: The XSLT C library version 1.2.12."
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC04} "LIBXMLSEC: XML Security Library C library version 1.2.6 (based on LibXML2) with openssl and mscrypto modules."
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC05} "LIBOPENSSL: A  full-strength general purpose cryptography library version 0.9.7e."
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC06} "ZLIB: A free, general-purpose, legally unencumbered -- that is, not covered by any patents -- lossless data-compression library version 1.2.1."
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC07} "LIBICONV: Free iconv() implementation."
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC08} "LIBINTL: Library for native language support."
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC09} "LIBLASSO: Free implementation of the Liberty Alliance specifications."
!insertmacro MUI_FUNCTION_DESCRIPTION_END


Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name) a �t� d�sinstall� avec succ�s de votre ordinateur."
FunctionEnd

Function un.onInit
!insertmacro MUI_UNGETLANGUAGE
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "�tes-vous certains de vouloir d�sinstaller totalement $(^Name) et tous ses composants ?" IDYES +2
  Abort
FunctionEnd

Section Uninstall
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\liblasso-3.dll"
  Delete "$INSTDIR\iconv.dll"
  Delete "$INSTDIR\zlib.dll"
  Delete "$INSTDIR\zlib1.dll"
  Delete "$INSTDIR\libssleay32.dll"
  Delete "$INSTDIR\libeay32.dll"
  Delete "$INSTDIR\libxmlsec-openssl.dll"
  Delete "$INSTDIR\libxmlsec-mscrypto.dll"
  Delete "$INSTDIR\libxmlsec.dll"
  Delete "$INSTDIR\libexslt.dll"
  Delete "$INSTDIR\libxslt.dll"
  Delete "$INSTDIR\libxml2.dll"
  Delete "$INSTDIR\libgthread-2.0-0.dll"
  Delete "$INSTDIR\libgmodule-2.0-0.dll"
  Delete "$INSTDIR\libgobject-2.0-0.dll"
  Delete "$INSTDIR\libglib-2.0-0.dll"
  Delete "$INSTDIR\intl.dll"

  Delete "$SMPROGRAMS\Liberty Alliance Single Sign On & Dependencies\Uninstall.lnk"
  Delete "$SMPROGRAMS\Liberty Alliance Single Sign On & Dependencies\Website.lnk"

  RMDir "$SMPROGRAMS\Liberty Alliance Single Sign On & Dependencies"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  SetAutoClose true
SectionEnd
