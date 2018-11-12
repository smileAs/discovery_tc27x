#******************************************************************************* 
#                                                                             ** 
#* Copyright (C) Infineon Technologies (2014)                                 **
#*                                                                            ** 
#* All rights reserved.                                                       ** 
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       ** 
#* Technologies. Passing on and copying of this document, and communication   ** 
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            ** 
#******************************************************************************* 
#*                                                                            ** 
#*  $FILENAME   : SafeTlibCD_Cfg.mak $                                       **
#*                                                                            **
#*  $CC VERSION : \main\15 $                                                 **
#*                                                                            **
#*  $DATE       : 2015-07-22 $                                               **
#*                                                                            ** 
#*  AUTHOR    : SafeTlib Team                                                 **
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file defines safety lib CD modules delivery ON/OFF    ** 
#*         - Based on this delivery type values modules will be compiled      **
#*                                                                            ** 
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      ** 
#*                                                                            ** 
#******************************************************************************/ 

[!VAR "ModuleConcate" = "''"!][!//
[!VAR "TstHandlerModuleUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('TstHandler')[1]"!][!//
[!VAR "TstHandlerModuleUsed" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$TstHandlerModuleUsed = 'ON'"!][!/*
*/!]TSTHANDLER_DELIVERY = ON
[!ELSE!][!/*
*/!]TSTHANDLER_DELIVERY = OFF
[!ENDIF!][!//
[!SELECT "as:modconf('TstHandler')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SlConfigSet/*))"!][!//
[!FOR "PBConfigIdx" ="num:i(1)" TO "(num:i($TotalConfig))"!]
[!SELECT "SlConfigSet/*[num:i($PBConfigIdx)]"!][!//
[!VAR "CountCPUxTestList" = "num:i(count(SlCPUxTestList/*))"!][!//
[!FOR "TestIndex" ="num:i(1)" TO "(num:i($CountCPUxTestList))"!][!//
[!SELECT "SlCPUxTestList/*[num:i($TestIndex)]"!][!//
[!VAR "TestName" = "node:value(./SlTestName)"!][!//
[!IF "$TestName != 'CpuTst_CpuSbstETst' and $TestName != 'CpuTst_CpuSbstPTst'"!][!//
[!VAR "ModuleUsed" = "substring-before($TestName, "_")"!][!//
[!ELSE!][!//
[!VAR "ModuleUsed" = "'CpuSbstTst'"!][!//
[!ENDIF!][!//
[!VAR "ModuleUsedUpper" = "text:toupper($ModuleUsed)"!][!//
[!VAR "ModuleConfigured" = "'OFF'"!][!//
[!SELECT "as:modconf($ModuleUsed)[1]"!][!//
[!VAR "ModuleConfigured" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$ModuleUsed = 'LmuRegAccProtTst'"!][!//
[!VAR "ModuleUsed" = "'LocalMemoryUnit'"!][!//
[!ENDIF!][!//
[!VAR "ModuleUsedUpper" = "text:toupper($ModuleUsed)"!][!//
[!IF "contains($ModuleConcate,$ModuleUsed) != 'true'"!][!//
[!VAR "ModuleConcate" = "concat($ModuleConcate,$ModuleUsed)"!][!//
[!IF "$ModuleConfigured = 'ON'"!]
[!"$ModuleUsedUpper"!]_DELIVERY = ON[!//
[!ELSE!][!//
[!IF "$ModuleUsed != 'TrapTst' and $ModuleUsed != 'PflashMonTst' and $ModuleUsed != 'LockStepTst' and $ModuleUsed != 'RegAccProtTst' and $ModuleUsed != 'LocalMemoryUnit' and $ModuleUsed != 'Test' and $ModuleUsed != 'VltmTst' and $ModuleUsed != 'SffTst' and $ModuleUsed != 'ClkmTst' and $ModuleUsed != 'SmuTst'"!][!//
[!ERROR!][!//
[!"$ModuleUsed"!] is called from TstHandler configuration however [!"$ModuleUsed"!] module is not configured/added in tresos tool.
Add [!"$ModuleUsed"!] Module configuration in the tresos project.
[!ENDERROR!]
[!"$ModuleUsedUpper"!]_DELIVERY = OFF[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$ModuleUsed = 'TrapTst' or $ModuleUsed = 'LockStepTst' or $ModuleUsed = 'RegAccProtTst' or $ModuleUsed = 'LocalMemoryUnit' or $ModuleUsed = 'Test' or $ModuleUsed = 'VltmTst' or $ModuleUsed = 'SffTst' or $ModuleUsed = 'ClkmTst' or $ModuleUsed = 'SmuTst'"!]
[!IF "$ModuleUsed = 'LocalMemoryUnit'"!][!//
[!VAR "ModuleUsed" = "'LmuRegAccProtTst'"!][!//
[!VAR "ModuleUsedUpper" = "text:toupper($ModuleUsed)"!][!//
[!ENDIF!][!//
[!"$ModuleUsedUpper"!]_DELIVERY = ON[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//