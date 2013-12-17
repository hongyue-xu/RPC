# Auto-generated by EclipseNSIS Script Wizard
# 30-nov-2012 15:13:07

Name "RPC"

### Necesario para tener permisos de borrar ciertos ficheros al desinstalar
RequestExecutionLevel admin

# General Symbol Definitions
!define REGKEY "SOFTWARE\$(^Name)"
!define COMPANY eProsima
!define URL www.eprosima.com

# MUI Symbol Definitions
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install-colorful.ico"
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall-colorful.ico"
!define MUI_UNFINISHPAGE_NOAUTOCLOSE
!define MUI_STARTMENUPAGE_REGISTRY_ROOT HKLM
!define MUI_STARTMENUPAGE_REGISTRY_KEY ${REGKEY}
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME StartMenuGroup
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "eProsima\RPC"

# Included files
!include Sections.nsh
!include MUI2.nsh
!include EnvVarUpdate.nsh
!include x64.nsh

# Installer sections Has to be defined at the beginning because they are used by EnvVarPage.nsh
SectionGroup "Libraries" SECGRP0000
    Section "x64 libraries" SEC_LIB_x64
        SetOutPath $INSTDIR\lib\x64Win64VS2010
        SetOverwrite on
        File /r ..\..\..\..\lib\x64Win64VS2010\*
        WriteRegStr HKLM "${REGKEY}\Components" "x64 libraries" 1
    SectionEnd

    Section "i86 libraries" SEC_LIB_i86
        SetOutPath $INSTDIR\lib\i86Win32VS2010
        SetOverwrite on
        File /r ..\..\..\..\lib\i86Win32VS2010\*
        WriteRegStr HKLM "${REGKEY}\Components" "i86 libraries" 1
    SectionEnd
SectionGroupEnd

!include EnvVarPage.nsh

# Variables
Var StartMenuGroup

# Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE ..\..\..\..\doc\licencias\RPC_LICENSE.txt
!insertmacro MUI_PAGE_STARTMENU Application $StartMenuGroup
!insertmacro MUI_PAGE_COMPONENTS
Page custom VariablesEntornoPage
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
var /GLOBAL RICHI_FINISH_MESSAGE
!define MUI_FINISHPAGE_TEXT $RICHI_FINISH_MESSAGE
!define MUI_FINISHPAGE_SHOWREADME $INSTDIR\README.html
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

# Installer languages
!insertmacro MUI_LANGUAGE English

# Installer attributes
OutFile eProsima_RPC_${VERSION}.exe
InstallDir "$PROGRAMFILES\eProsima\rpc"
CRCCheck on
XPStyle on
ShowInstDetails show
VIProductVersion ${VERSION}.0
VIAddVersionKey ProductName RPC
VIAddVersionKey ProductVersion "${VERSION}"
VIAddVersionKey CompanyName "${COMPANY}"
VIAddVersionKey CompanyWebsite "${URL}"
VIAddVersionKey FileVersion "${VERSION}"
VIAddVersionKey FileDescription ""
VIAddVersionKey LegalCopyright ""
InstallDirRegKey HKLM "${REGKEY}" Path
ShowUninstDetails show

# Installer sections. 
Section -post SEC0006
    SetShellVarContext all
    
    # Copy documentation.
    SetOutPath $INSTDIR\doc\html
    SetOverwrite on
    File /r ..\..\..\doxygen\output\doxygen\html\*
    
    # Copy documentation.
    SetOutPath $INSTDIR\doc\pdf
    SetOverwrite on
    File /r ..\..\..\..\doc\pdf\*
    File /r "..\..\..\doxygen\output\doxygen\latex\RPC - API C++ Manual.pdf"
    
    # Copy examples.
    SetOutPath $INSTDIR\examples
    SetOverwrite on
    File /r ..\..\..\..\examples\*
    
    # Copy rpcddsgen java classes.
    SetOutPath $INSTDIR\classes
    SetOverwrite on
    File /r ..\..\..\..\rpcddsgen\lib\*
        
    # Copy rpcddsgen script.
    SetOutPath $INSTDIR\scripts
    SetOverwrite on
    File ..\..\..\..\scripts\rpcddsgen.bat
    
    # Copy IDL.
    SetOutPath $INSTDIR\idl
    SetOverwrite on
    File ..\..\..\..\idl\MessageHeader.idl
    
    # Copy header files.
    SetOutPath $INSTDIR\include
    SetOverwrite on
    File /r ..\..\..\..\include\*
    
    # Copy licensies
    SetOutPath $INSTDIR
    SetOverwrite on
    File /r ..\..\..\..\doc\licencias\*
    File ..\..\..\..\README.html
    
    WriteRegStr HKLM "${REGKEY}" Path $INSTDIR
    SetOutPath $INSTDIR
    WriteUninstaller $INSTDIR\uninstall.exe
    !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
    SetOutPath $SMPROGRAMS\$StartMenuGroup
    CreateShortcut "$SMPROGRAMS\$StartMenuGroup\README.lnk" $INSTDIR\README.html
    CreateShortcut "$SMPROGRAMS\$StartMenuGroup\Uninstall $(^Name).lnk" $INSTDIR\uninstall.exe
    !insertmacro MUI_STARTMENU_WRITE_END
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayName "$(^Name)"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayVersion "${VERSION}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" Publisher "${COMPANY}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" URLInfoAbout "${URL}"
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayIcon $INSTDIR\uninstall.exe
    WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" UninstallString $INSTDIR\uninstall.exe
    WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoModify 1
    WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoRepair 1
    
    ### Actualizamos las variables de entorno que se hayan marcado
    ${If} $CheckboxRPCDDSHOME_State == ${BST_CHECKED}
       ${EnvVarUpdate} $0 "RPCDDSHOME" "P" "HKLM" "$INSTDIR"
       WriteRegStr HKLM "${REGKEY}\Components" "RPCDDSHOME" 1
    ${EndIf}
    ${If} $CheckboxScripts_State == ${BST_CHECKED}
       ${EnvVarUpdate} $0 "PATH" "A" "HKLM" "$INSTDIR\scripts"
       WriteRegStr HKLM "${REGKEY}\Components" "Script location" 1
    ${EndIf}
    ${If} ${SectionIsSelected} ${SEC_LIB_x64}
        ${If} $CheckboxX64_State == ${BST_CHECKED}
             ${EnvVarUpdate} $0 "PATH" "A" "HKLM" "$INSTDIR\lib\x64Win64VS2010"
             WriteRegStr HKLM "${REGKEY}\Components" "x64 libraries location" 1
        ${EndIf}
    ${EndIf}
    ${If} ${SectionIsSelected} ${SEC_LIB_i86}
        ${If} $CheckboxI86_State == ${BST_CHECKED}
             ${EnvVarUpdate} $0 "PATH" "A" "HKLM" "$INSTDIR\lib\i86Win32VS2010"
             WriteRegStr HKLM "${REGKEY}\Components" "i86 libraries location" 1
        ${EndIf}
    ${EndIf}
SectionEnd

# Macro for selecting uninstaller sections
!macro SELECT_UNSECTION SECTION_NAME UNSECTION_ID
    Push $R0
    ReadRegStr $R0 HKLM "${REGKEY}\Components" "${SECTION_NAME}"
    StrCmp $R0 1 0 next${UNSECTION_ID}
    !insertmacro SelectSection "${UNSECTION_ID}"
    GoTo done${UNSECTION_ID}
next${UNSECTION_ID}:
    !insertmacro UnselectSection "${UNSECTION_ID}"
done${UNSECTION_ID}:
    Pop $R0
!macroend

Section /o "-un.i86 libraries" UNSEC_LIB_i86
    RmDir /r /REBOOTOK $INSTDIR\lib\i86Win32VS2010
    DeleteRegValue HKLM "${REGKEY}\Components" "i86 libraries"
SectionEnd

Section /o "-un.x64 libraries" UNSEC_LIB_x64
    RmDir /r /REBOOTOK $INSTDIR\lib\x64Win64VS2010
    DeleteRegValue HKLM "${REGKEY}\Components" "x64 libraries"
SectionEnd

Section -un.post UNSEC0006
    SetShellVarContext all
    
    DeleteRegKey HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)"
    Delete /REBOOTOK "$SMPROGRAMS\$StartMenuGroup\Uninstall $(^Name).lnk"
    Delete /REBOOTOK "$SMPROGRAMS\$StartMenuGroup\README.lnk"
    Delete /REBOOTOK $INSTDIR\uninstall.exe
    DeleteRegValue HKLM "${REGKEY}" StartMenuGroup
    DeleteRegValue HKLM "${REGKEY}" Path
    DeleteRegKey /IfEmpty HKLM "${REGKEY}\Components"
    DeleteRegKey /IfEmpty HKLM "${REGKEY}"
    RmDir /REBOOTOK $SMPROGRAMS\$StartMenuGroup
    RmDir /REBOOTOK $INSTDIR\lib
    RmDir /r /REBOOTOK $INSTDIR\include
    RmDir /r /REBOOTOK $INSTDIR\idl
    RmDir /r /REBOOTOK $INSTDIR\scripts
    RmDir /r /REBOOTOK $INSTDIR\classes
    RmDir /r /REBOOTOK $INSTDIR\examples
    RmDir /r /REBOOTOK $INSTDIR\doc
    RmDir /r /REBOOTOK $INSTDIR
    
    ### Quitamos las variables de entorno
    DeleteRegValue HKLM "${REGKEY}\Components" "i86 libraries location"
    DeleteRegValue HKLM "${REGKEY}\Components" "x64 libraries location"
    DeleteRegValue HKLM "${REGKEY}\Components" "Script location"
    DeleteRegValue HKLM "${REGKEY}\Components" "RPCDDSHOME"
    
    ${un.EnvVarUpdate} $0 "RPCDDSHOME" "R" "HKLM" "$INSTDIR"
    ${un.EnvVarUpdate} $0 "PATH" "R" "HKLM" "$INSTDIR\scripts"
    ${un.EnvVarUpdate} $0 "PATH" "R" "HKLM" "$INSTDIR\lib\x64Win64VS2010"
    ${un.EnvVarUpdate} $0 "PATH" "R" "HKLM" "$INSTDIR\lib\i86Win32VS2010"
SectionEnd

# Installer functions
Function .onInit
    ReadEnvStr $0 NDDSHOME
    StrCmp $0 "" 0 +3
    StrCpy $RICHI_FINISH_MESSAGE "RPCDDS has been installed on your computer.$\n$\nNote: NDDSHOME environment variable is not set in your system. RPCDDS uses this environment variable to find the RTI DDS middleware. See the User Manual document.$\n$\nClick Finish to close this wizard."
    goto +3
    strcpy $INSTDIR $0\rpcdds
    Strcpy $RICHI_FINISH_MESSAGE "RPCDDS has been installed on your computer.$\n$\nClick Finish to close this wizard."
    InitPluginsDir
    #StrCpy $1 ${SEC0004}
FunctionEnd

# Uninstaller functions
Function un.onInit

    ReadRegStr $INSTDIR HKLM "${REGKEY}" Path
    !insertmacro MUI_STARTMENU_GETFOLDER Application $StartMenuGroup
    !insertmacro SELECT_UNSECTION "x64 libraries" ${UNSEC_LIB_x64}
    !insertmacro SELECT_UNSECTION "i86 libraries" ${UNSEC_LIB_i86}
FunctionEnd

# Section Descriptions
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
!insertmacro MUI_DESCRIPTION_TEXT ${SECGRP0000} "RPCDDS libraries."
!insertmacro MUI_DESCRIPTION_TEXT ${SEC_LIB_x64} "Libraries for x64 platform."
!insertmacro MUI_DESCRIPTION_TEXT ${SEC_LIB_i86} "Libraries for i86 platform."
!insertmacro MUI_FUNCTION_DESCRIPTION_END


