[!/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : TstHandler_Cfg.h $                                         **
**                                                                            **
**   $CC VERSION : \main\35 $                                                 **
**                                                                            **
**   $DATE       : 2015-07-22 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : TstHandler.bmd                                    **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for TstHandler_Cfg.h file                    **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
**************************************************************************/!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  TstHandler_Cfg.h                                             **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : TstHandler.bmd                                    **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU / Diab                                          **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : TstHandler configuration header file                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef TSTHANDLER_CFG_H
#define TSTHANDLER_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
[!VAR "ModuleConcate" = "''"!][!//
[!SELECT "as:modconf('TstHandler')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SlConfigSet/*))"!][!//
[!FOR "PBConfigIdx" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SlConfigSet/*[num:i($PBConfigIdx)]"!][!//
[!VAR "CountCPUxTestList" = "num:i(count(SlCPUxTestList/*))"!][!//
[!FOR "TestIndex" ="num:i(1)" TO "(num:i($CountCPUxTestList))"!][!//
[!SELECT "SlCPUxTestList/*[num:i($TestIndex)]"!][!//
[!VAR "TestName" = "node:value(./SlTestName)"!][!//
[!VAR "ModuleUsed" = "substring-before($TestName, "_")"!][!//
[!VAR "ModHeaderIncl" = "$ModuleUsed"!][!//
[!VAR "ModuleUsedUpper" = "text:toupper($ModuleUsed)"!][!//
[!VAR "ModuleConfigured" = "'OFF'"!][!//
[!SELECT "as:modconf($ModuleUsed)[1]"!][!//
[!VAR "ModuleConfigured" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$ModuleUsed = 'LmuRegAccProtTst'"!][!//
[!VAR "ModuleUsed" = "'LocalMemoryUnit'"!][!//
[!VAR "ModHeaderIncl" = "'LocalMemoryUnit'"!][!//
[!ENDIF!][!//
[!VAR "ModuleUsedUpper" = "text:toupper($ModuleUsed)"!][!//
[!IF "contains($ModuleConcate,$ModuleUsed) != 'true'"!][!//
[!VAR "ModuleConcate" = "concat($ModuleConcate,$ModuleUsed)"!][!//
[!IF "$ModuleConfigured = 'ON'"!][!//
[!IF "$ModHeaderIncl = 'SfrTst'"!]
#include "SfrCmpTst.h"
#include "SfrCrcTst.h"[!//
[!ENDIF!][!//
[!IF "$ModHeaderIncl = 'PmuEccEdcTst'"!]
#include "PmuEccEdcTst.h"
#include "PflashMonTst.h"[!//
[!ENDIF!][!//
[!IF "$ModHeaderIncl != 'SfrTst' and $ModHeaderIncl != 'PmuEccEdcTst'"!]
#include "[!"$ModHeaderIncl"!].h"[!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "$ModuleUsed != 'TrapTst' and $ModuleUsed != 'PflashMonTst' and $ModuleUsed != 'LockStepTst' and $ModuleUsed != 'CpuTst' and $ModuleUsed != 'RegAccProtTst' and $ModuleUsed != 'LocalMemoryUnit' and $ModuleUsed != 'Test' and $ModuleUsed != 'VltmTst' and $ModuleUsed != 'ClkmTst' and $ModuleUsed != 'SffTst' and $ModuleUsed != 'SmuTst'"!][!//
[!ERROR!][!//
[!"$ModuleUsed"!] is called from TstHandler configuration however [!"$ModuleUsed"!] module is not configured/added in tresos tool.
Add [!"$ModuleUsed"!] Module configuration in the tresos project.
[!ENDERROR!]
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$ModuleUsed = 'TrapTst' or $ModuleUsed = 'LockStepTst' or $ModuleUsed = 'CpuTst' or $ModuleUsed = 'RegAccProtTst' or $ModuleUsed = 'LocalMemoryUnit' or $ModuleUsed = 'Test' or $ModuleUsed = 'VltmTst' or $ModuleUsed = 'ClkmTst' or $ModuleUsed = 'SffTst' or $ModuleUsed = 'SmuTst'"!]
[!IF "$ModHeaderIncl = 'CpuTst'"!][!//
[!VAR "ModHeaderIncl" = "'CpuSbstTst'"!][!//	
[!ENDIF!][!//
[!IF "$ModHeaderIncl = 'LocalMemoryUnit'"!][!//
[!VAR "ModHeaderIncl" = "'LmuRegAccProtTst'"!][!//	
[!ENDIF!][!//
[!IF "$ModuleUsed != 'Test'"!][!//
#include "[!"$ModHeaderIncl"!].h"[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!]

[!VAR "TestList" = "ecu:list('TstHandler.TestList')"!][!//
[!IF "contains($TestList,'Test_Automation')"!][!//
#ifdef UVP_TEST_AUTO
#include "Test_Main.h"
#endif
[!ENDIF!]
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!SELECT "as:modconf('TstHandler')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SlConfigSet/*))"!][!//

/* Master core Id */
[!VAR "MasterCoreId" = "num:i(SlGeneral/SlMasterCoreId)"!][!//
#define SL_MASTER_CORE_ID ([!"(num:i($MasterCoreId))"!]U)
[!IF "(num:i($MasterCoreId)) = num:i(0)"!][!//
[!VAR "IsCoreLockStepped" = "ecu:get('Cpu0LockStep')"!][!//
[!ENDIF!][!//
[!IF "(num:i($MasterCoreId)) = num:i(1)"!][!//
[!VAR "IsCoreLockStepped" = "ecu:get('Cpu1LockStep')"!][!//
[!ENDIF!][!//
[!IF "(num:i($MasterCoreId)) = num:i(2)"!][!//
[!VAR "IsCoreLockStepped" = "ecu:get('Cpu2LockStep')"!][!//
[!ENDIF!][!//
[!IF "$IsCoreLockStepped = 'false'"!][!//
[!WARNING "Warning: SlMasterCoreId: Configured master core is not a lock step core."!][!//
[!ENDIF!][!//

[!VAR "MaxTestsEarlyPreRun" = "ecu:get('TstHandler.MaxTestsEarlyPreRunGrp')"!][!//
[!VAR "MaxTestsPreRun" = "ecu:get('TstHandler.MaxTestsPreRunGrp')"!][!//
[!VAR "MaxTestsRunTime" = "ecu:get('TstHandler.MaxTestsRunTimeGrp')"!][!//
[!VAR "MaxTestsPostRun" = "ecu:get('TstHandler.MaxTestsPostRunGrp')"!][!//

/* Maximum tests configured per group */
#define SL_MAX_TESTS_EARLY_PRE_RUN_GRP  ([!"num:i($MaxTestsEarlyPreRun)"!]U)
#define SL_MAX_TESTS_PRE_RUN_GRP        ([!"num:i($MaxTestsPreRun)"!]U)
#define SL_MAX_TESTS_RUN_TIME_GRP       ([!"num:i($MaxTestsRunTime)"!]U)
#define SL_MAX_TESTS_POST_RUN_GRP       ([!"num:i($MaxTestsPostRun)"!]U)

[!NOCODE!][!//
[!VAR "TestCountMax" = "num:i(0)"!][!//
[!FOR "PBConfigIdx" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SlConfigSet/*[num:i($PBConfigIdx)]"!]
[!VAR "CountCPUxTestList" = "num:i(count(SlCPUxTestList/*))"!]
[!IF "$TestCountMax < $CountCPUxTestList"!][!//
[!VAR "TestCountMax" = "num:i($CountCPUxTestList)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//

#define SL_CFG_COUNT ([!"(num:i($TotalConfig))"!]U)

/* Maximum number of tests among arrays Th_MTLFuncList_Core<x> {x: Core id} */
#define TH_TOTAL_TESTS ([!"num:i($TestCountMax)"!]U)

[!FOR "PBConfigIdx" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SlConfigSet/*[num:i($PBConfigIdx)]"!][!//
[!VAR "SlConfigSetIndex" = "@index"!]
/* Test index macros used to represent tests in array Th_MTLFuncList_Core[!"num:i(SlCoreId)"!] */[!//
[!VAR "CountCPUxTestList" = "num:i(count(SlCPUxTestList/*))"!][!//
[!FOR "TestIndex" ="num:i(1)" TO "(num:i($CountCPUxTestList))"!][!//
[!SELECT "SlCPUxTestList/*[num:i($TestIndex)]"!][!// Select based on "TestId" so that the array is correctly indexed on TestId and not randomly as configured in Tresos
#define  [!"node:name(.)"!]_ConfigSet[!"$SlConfigSetIndex"!]  ([!"node:value(./SlTestIndex)"!]U)[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//


[!ENDSELECT!][!//
[!ENDFOR!][!//

[!ENDSELECT!][!//

#endif  /* TSTHANDLER_CFG_H */
