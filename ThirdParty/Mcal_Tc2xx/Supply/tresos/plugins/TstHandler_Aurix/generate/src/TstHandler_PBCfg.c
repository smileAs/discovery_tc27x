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
**   $FILENAME   : TstHandler_PBCfg.c $                                       **
**                                                                            **
**   $CC VERSION : \main\33 $                                                 **
**                                                                            **
**   $DATE       : 2015-04-15 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : TstHandler.bmd                                    **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=DS_NAS_TstHandler_PR1693_3,                 **
**                                DS_NAS_TstHandler_PR1693_4]                 **
**                                                                            **
**  DESCRIPTION  : Code generator template for TstHandler_PBCfg.c file        **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*************************************************************************/!][!//
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
**  FILENAME  :  TstHandler_PBCfg.c                                           **
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
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Test Handler configuration generated out of ECU            **
**                 configuration file                                         **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "TstHandler_Cfg.h"

#define IFX_TSTHANDLER_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
[!AUTOSPACING!]
[!SELECT "as:modconf('TstHandler')[1]"!]
#include "TstHandler.h"
[!VAR "TotalConfig" = "num:i(count(SlConfigSet/*))"!]
[!VAR "AllowedTestsEarlyPreRun" = "ecu:list('TstHandler.EarlyPreRunTestList')"!]
[!VAR "AllowedTestsRunTime" = "ecu:list('TstHandler.RunTimeTestList')"!]

[!VAR "MaxTestsEarlyPreRun" = "ecu:get('TstHandler.MaxTestsEarlyPreRunGrp')"!][!//
[!VAR "MaxTestsPreRun" = "ecu:get('TstHandler.MaxTestsPreRunGrp')"!][!//
[!VAR "MaxTestsRunTime" = "ecu:get('TstHandler.MaxTestsRunTimeGrp')"!][!//
[!VAR "MaxTestsPostRun" = "ecu:get('TstHandler.MaxTestsPostRunGrp')"!][!//

[!FOR "PBConfigIdx" ="num:i(1)" TO "(num:i($TotalConfig))"!]
[!SELECT "SlConfigSet/*[num:i($PBConfigIdx)]"!]
[!VAR "SlConfigSetIndex" = "@index"!]
[!VAR "CountCPUxTestList" = "num:i(count(SlCPUxTestList/*))"!]
[!VAR "TestCount" = "((num:i($CountCPUxTestList))-num:i(1))"!]
[!VAR "CoreId" = "num:i(SlCoreId)"!]
static const Th_TestLibFuncPtrType Th_MTLFuncList_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!][TH_TOTAL_TESTS] =
{
[!FOR "TestIndex" ="num:i(0)" TO "(num:i($TestCount))"!]
[!FOR "LoopIndex" ="num:i(1)" TO "(num:i($CountCPUxTestList))"!]
[!SELECT "SlCPUxTestList/*[num:i($LoopIndex)]"!][!// Select based on "SlLoopIndex" so that the array is correctly indexed on SlLoopIndex and not randomly as configured in Tresos
[!VAR "MasterListName" = "node:name(.)"!]
[!IF "node:value(./SlTestIndex) = num:i($TestIndex)"!][!//
  /* [!"num:i($TestIndex)"!] */ &[!"node:value(./SlTestName)"!],
[!VAR "TestName" = "node:value(./SlTestName)"!][!//
[!VAR "ParamSetIndex" = "node:value(./SlParamSetIndex)"!][!//
[!IF "$TestName != 'CpuTst_CpuSbstETst' and $TestName != 'CpuTst_CpuSbstPTst'"!][!//
[!VAR "ModuleUsed" = "substring-before($TestName, "_")"!][!//
[!ELSE!][!//
[!VAR "ModuleUsed" = "'CpuSbstTst'"!][!//
[!ENDIF!][!//
[!VAR "ModuleConfigured" = "'OFF'"!][!//
[!IF "$ModuleUsed != 'TrapTst' and $ModuleUsed != 'PflashMonTst' and $ModuleUsed != 'LockStepTst' and $ModuleUsed != 'RegAccProtTst' and $ModuleUsed != 'IomTst' and $ModuleUsed != 'LmuRegAccProtTst' and $ModuleUsed != 'Test' and $ModuleUsed != 'VltmTst' and $ModuleUsed != 'ClkmTst' and $ModuleUsed != 'SffTst' and $ModuleUsed != 'LmuRegAccProtTst' and $ModuleUsed != 'PhlSramTst' and $ModuleUsed != 'IomTst' and $ModuleUsed != 'SmuTst'"!][!//
[!SELECT "as:modconf($ModuleUsed)[1]"!][!//
[!VAR "ModuleConfigured" = "'ON'"!][!//
[!IF "$ModuleUsed != 'CpuSbstTst'"!][!//
[!VAR "ModConfigSetName" = "concat($ModuleUsed,'ConfigSet')"!][!//
[!VAR "TotalNumberOfConfig" = "num:i(count(node:ref($ModConfigSetName)/*))"!][!//
[!VAR "TotalNumberOfConfig" = "num:i($TotalNumberOfConfig - num:i(1))"!][!//
[!IF "$ParamSetIndex > $TotalNumberOfConfig"!][!//
[!ERROR!][!//
Wrong configuration, [!"$MasterListName"!] the configured [!"$ModuleUsed"!] module TstHandler SlParamSetIndex value is more than the actual total number of configuration configured in the [!"$ModuleUsed"!] module configuration.
SlParamSetIndex value should be less than or equal to total number of configuration configured in the Test Name [!"$TestName"!].
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!IF "$ModuleConfigured = 'ON'"!][!//
[!ELSE!][!//
[!IF "$ModuleUsed != 'TrapTst' and $ModuleUsed != 'PflashMonTst' and $ModuleUsed != 'LockStepTst' and $ModuleUsed != 'RegAccProtTst' and $ModuleUsed != 'IomTst' and $ModuleUsed != 'LmuRegAccProtTst' and $ModuleUsed != 'Test' and $ModuleUsed != 'VltmTst' and $ModuleUsed != 'ClkmTst' and $ModuleUsed != 'SffTst' and $ModuleUsed != 'LmuRegAccProtTst' and $ModuleUsed != 'PhlSramTst' and $ModuleUsed != 'IomTst' and $ModuleUsed != 'SmuTst'"!][!//
[!ERROR!]
[!"$ModuleUsed"!] is called from TstHandler configuration however [!"$ModuleUsed"!] module is not configured/added in tresos tool.
Add [!"$ModuleUsed"!] Module configuration in the tresos project.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDFOR!]
};
[!ENDSELECT!]
[!ENDFOR!]

[!FOR "PBConfigIdx" ="num:i(1)" TO "(num:i($TotalConfig))"!]
[!SELECT "SlConfigSet/*[num:i($PBConfigIdx)]"!]
[!VAR "SlConfigSetName" = "node:name(.)"!]
[!VAR "SlConfigSetIndex" = "@index"!]
[!VAR "GroupCountEarlyPrerun" = "num:i(count(SlEarlyPrerun/SlTestGroupEarlyPrerun/*))"!]
[!VAR "CoreId" = "num:i(SlCoreId)"!]
[!IF "num:i($GroupCountEarlyPrerun) != num:i(0)"!]
static const Th_TestlibTestSetType Th_EarlyPreRunTests_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!][[!"num:i($GroupCountEarlyPrerun)"!]][SL_MAX_TESTS_EARLY_PRE_RUN_GRP]=
{
[!FOR "GroupCount" ="num:i(1)" TO "(num:i($GroupCountEarlyPrerun))"!]
  {
[!FOR "TestCount" ="num:i(1)" TO "(num:i($MaxTestsEarlyPreRun))"!]
[!IF "node:exists(SlEarlyPrerun/SlTestGroupEarlyPrerun/*[num:i($GroupCount)]/SlTestEntry/*[num:i($TestCount)])"!]
[!SELECT "SlEarlyPrerun/SlTestGroupEarlyPrerun/*[num:i($GroupCount)]/SlTestEntry/*[num:i($TestCount)]"!]
[!ASSERT "node:refexists(./Test)"!]
Error: Reference [!"substring-after(node:path(.),'ELEMENTS')"!]/Test is empty. Test is not configured.
[!ENDASSERT!][!//
[!VAR "EarlyPreRunTestPath" = "node:path(node:value(./Test))"!][!//
[!VAR "EarlyPreRunConfigSetName" = "substring-after($EarlyPreRunTestPath, "SlConfigSet/")"!][!//
[!VAR "EarlyPreRunConfigSetName" = "substring-before($EarlyPreRunConfigSetName, "/")"!][!//
[!IF "$EarlyPreRunConfigSetName != $SlConfigSetName"!][!//
[!ERROR!]	[!//
Wrong Configuration, Configured SlTestGroupEarlyPreRun_[!"num:i($GroupCount - num:i(1))"!] SlTestEntry_[!"num:i($TestCount - num:i(1))"!] Test reference is wrong, Module selection has to be done within the core master test
Ex: within ConfigSet 0 EarlyPrerun configuration only the modules available in set 0 to be configured. Other configuration set module reference selections are not allowed. 
[!ENDERROR!][!//
[!ENDIF!][!//
[!SELECT "node:ref(./Test)"!]
[!VAR "TestName" = "node:value(SlTestName)"!]
[!ASSERT "contains($AllowedTestsEarlyPreRun,$TestName)"!]
Error: Test "[!"$TestName"!]" referred by [!"node:name(.)"!] can not be run in early pre-run phase.
[!ENDASSERT!]
    {[!"node:name(.)"!]_ConfigSet[!"$SlConfigSetIndex"!], [!"num:i(node:value(./SlParamSetIndex))"!]U, [!"node:value(./SlSmuAlarm)"!]U},
[!ENDSELECT!]    
[!ENDSELECT!]    
[!ELSE!]    {TH_INVALID_TEST_ID, 0U, 0U},
[!ENDIF!]    
[!ENDFOR!]
  },
[!ENDFOR!]
};
[!ENDIF!]

[!VAR "GroupCountPrerun" = "num:i(count(SlPrerun/SlTestGroupPrerun/*))"!]
[!VAR "CoreId" = "num:i(SlCoreId)"!]
[!IF "num:i($GroupCountPrerun) != num:i(0)"!]
static const Th_TestlibTestSetType Th_PreRunTests_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!][[!"num:i($GroupCountPrerun)"!]][SL_MAX_TESTS_PRE_RUN_GRP]=
{
[!FOR "GroupCount" ="num:i(1)" TO "(num:i($GroupCountPrerun))"!]
  {
[!FOR "TestCount" ="num:i(1)" TO "(num:i($MaxTestsPreRun))"!]
[!IF "node:exists(SlPrerun/SlTestGroupPrerun/*[num:i($GroupCount)]/SlTestEntry/*[num:i($TestCount)])"!]
[!SELECT "SlPrerun/SlTestGroupPrerun/*[num:i($GroupCount)]/SlTestEntry/*[num:i($TestCount)]"!]
[!ASSERT "node:refexists(./Test)"!]
Error: Reference [!"substring-after(node:path(.),'ELEMENTS')"!]/Test is empty. Test is not configured.
[!ENDASSERT!]
[!VAR "PreRunTestPath" = "node:path(node:value(./Test))"!][!//
[!VAR "PreRunConfigSetName" = "substring-after($PreRunTestPath, "SlConfigSet/")"!][!//
[!VAR "PreRunConfigSetName" = "substring-before($PreRunConfigSetName, "/")"!][!//
[!IF "$PreRunConfigSetName != $SlConfigSetName"!][!//
[!ERROR!]	[!//
Wrong Configuration, Configured SlTestGroupPreRun_[!"num:i($GroupCount - num:i(1))"!] SlTestEntry_[!"num:i($TestCount - num:i(1))"!] Test reference is wrong, Module selection has to be done within the core master list
Ex: within ConfigSet 0 Prerun configuration only the modules available in set 0 to be configured. Other configuration set module reference selections are not allowed. 
[!ENDERROR!][!//
[!ENDIF!][!//
[!SELECT "node:ref(./Test)"!]
    {[!"node:name(.)"!]_ConfigSet[!"$SlConfigSetIndex"!], [!"num:i(node:value(./SlParamSetIndex))"!]U, [!"node:value(./SlSmuAlarm)"!]U},
[!ENDSELECT!]    
[!ENDSELECT!]    
[!ELSE!]    {TH_INVALID_TEST_ID, 0U, 0U},
[!ENDIF!]    
[!ENDFOR!]
  },
[!ENDFOR!]
};
[!ENDIF!]

[!VAR "GroupCountRuntime" = "num:i(count(SlRuntime/SlTestGroupRuntime/*))"!]
[!VAR "CoreId" = "num:i(SlCoreId)"!]
[!IF "num:i($GroupCountRuntime) != num:i(0)"!]
static const Th_TestlibTestSetType Th_RuntimeTests_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!][[!"num:i($GroupCountRuntime)"!]][SL_MAX_TESTS_RUN_TIME_GRP]=
{
[!FOR "GroupCount" ="num:i(1)" TO "(num:i($GroupCountRuntime))"!]
  {
[!FOR "TestCount" ="num:i(1)" TO "(num:i($MaxTestsRunTime))"!]
[!IF "node:exists(SlRuntime/SlTestGroupRuntime/*[num:i($GroupCount)]/SlTestEntry/*[num:i($TestCount)])"!]
[!SELECT "SlRuntime/SlTestGroupRuntime/*[num:i($GroupCount)]/SlTestEntry/*[num:i($TestCount)]"!]
[!ASSERT "node:refexists(./Test)"!]
Error: Reference [!"substring-after(node:path(.),'ELEMENTS')"!]/Test is empty. Test is not configured.
[!ENDASSERT!][!//
[!VAR "RunTestPath" = "node:path(node:value(./Test))"!][!//
[!VAR "RunConfigSetName" = "substring-after($RunTestPath, "SlConfigSet/")"!][!//
[!VAR "RunConfigSetName" = "substring-before($RunConfigSetName, "/")"!][!//
[!IF "$RunConfigSetName != $SlConfigSetName"!][!//
[!ERROR!]	[!//
Wrong Configuration, Configured SlTestGroupRun__[!"num:i($GroupCount - num:i(1))"!] SlTestEntry_[!"num:i($TestCount - num:i(1))"!] Test reference is wrong, Module selection has to be done within the core master list
Ex: within ConfigSet 0 RunTime configuration only the modules available in set 0 to be configured. Other configuration set module reference selections are not allowed. 
[!ENDERROR!][!//
[!ENDIF!][!//
[!SELECT "node:ref(./Test)"!]
[!VAR "TestName" = "node:value(SlTestName)"!]
[!ASSERT "contains($AllowedTestsRunTime,$TestName)"!]
Error: Test "[!"$TestName"!]" referred by [!"node:name(.)"!] can not be run in run-time phase.
[!ENDASSERT!]
    {[!"node:name(.)"!]_ConfigSet[!"$SlConfigSetIndex"!], [!"num:i(node:value(./SlParamSetIndex))"!]U, [!"node:value(./SlSmuAlarm)"!]U},
[!ENDSELECT!]    
[!ENDSELECT!]    
[!ELSE!]    {TH_INVALID_TEST_ID, 0U, 0U},
[!ENDIF!]    
[!ENDFOR!]
  },
[!ENDFOR!]
};
[!ENDIF!]

[!VAR "GroupCountPostrun" = "num:i(count(SlPostrun/SlTestGroupPostrun/*))"!]
[!VAR "CoreId" = "num:i(SlCoreId)"!]
[!IF "num:i($GroupCountPostrun) != num:i(0)"!]
static const Th_TestlibTestSetType Th_PostRunTests_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!][[!"num:i($GroupCountPostrun)"!]][SL_MAX_TESTS_POST_RUN_GRP]=
{
[!FOR "GroupCount" ="num:i(1)" TO "(num:i($GroupCountPostrun))"!]
  {
[!FOR "TestCount" ="num:i(1)" TO "(num:i($MaxTestsPostRun))"!]
[!IF "node:exists(SlPostrun/SlTestGroupPostrun/*[num:i($GroupCount)]/SlTestEntry/*[num:i($TestCount)])"!]
[!SELECT "SlPostrun/SlTestGroupPostrun/*[num:i($GroupCount)]/SlTestEntry/*[num:i($TestCount)]"!]
[!ASSERT "node:refexists(./Test)"!]
Error: Reference [!"substring-after(node:path(.),'ELEMENTS')"!]/Test is empty. Test is not configured.
[!ENDASSERT!]
[!VAR "PostRunTestPath" = "node:path(node:value(./Test))"!][!//
[!VAR "PostRunConfigSetName" = "substring-after($PostRunTestPath, "SlConfigSet/")"!][!//
[!VAR "PostRunConfigSetName" = "substring-before($PostRunConfigSetName, "/")"!][!//
[!IF "$PostRunConfigSetName != $SlConfigSetName"!][!//
[!ERROR!]	[!//
Wrong Configuration, Configured SlTestGroupPostRun_[!"num:i($GroupCount - num:i(1))"!] SlTestEntry_[!"num:i($TestCount - num:i(1))"!] Test reference is wrong, Module selection has to be done within the core master list
Ex: within ConfigSet 0 Postrun configuration only the modules available in set 0 to be configured. Other configuration set module reference selections are not allowed. 
[!ENDERROR!][!//
[!ENDIF!][!//
[!SELECT "node:ref(./Test)"!]
    {[!"node:name(.)"!]_ConfigSet[!"$SlConfigSetIndex"!], [!"num:i(node:value(./SlParamSetIndex))"!]U, [!"node:value(./SlSmuAlarm)"!]U},
[!ENDSELECT!]
[!ENDSELECT!]
[!ELSE!]    {TH_INVALID_TEST_ID, 0U, 0U},
[!ENDIF!]
[!ENDFOR!]
  },
[!ENDFOR!]
};
[!ELSE!][!ENDIF!]
[!ENDSELECT!]
[!ENDFOR!]
/* Test Handler Module Configuration */
const Sl_ConfigType Sl_ConfigRoot[[!"num:i($TotalConfig)"!]] = 
{
[!NOCODE!][!//
[!VAR "MasterCoreId" = "num:i(SlGeneral/SlMasterCoreId)"!][!//
[!ENDNOCODE!][!//
[!FOR "PBConfigIdx" ="num:i(1)" TO "(num:i($TotalConfig))"!]
[!SELECT "SlConfigSet/*[num:i($PBConfigIdx)]"!]
[!VAR "SlConfigSetIndex" = "@index"!]
[!VAR "CoreId" = "num:i(SlCoreId)"!]
  /* ConfigSet for core [!"num:i($CoreId)"!]*/
  {[!INDENT "4"!][!CR!]
    [!VAR "GroupCountEarlyPrerun" = "num:i(count(SlEarlyPrerun/SlTestGroupEarlyPrerun/*))"!][!//
    [!VAR "GroupCountPrerun" = "num:i(count(SlPrerun/SlTestGroupPrerun/*))"!][!//
    [!VAR "GroupCountRuntime" = "num:i(count(SlRuntime/SlTestGroupRuntime/*))"!][!//
    [!VAR "GroupCountPostrun" = "num:i(count(SlPostrun/SlTestGroupPostrun/*))"!][!//
    /* Pointer to Early Pre-run Test configuration */
    [!IF "num:i($GroupCountEarlyPrerun) = num:i(0)"!]NULL_PTR,[!ELSE!]*Th_EarlyPreRunTests_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!],[!ENDIF!][!CR!]
    /* Pointer to Pre-run Test configuration */
    [!IF "num:i($GroupCountPrerun) = num:i(0)"!]NULL_PTR,[!ELSE!]*Th_PreRunTests_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!],[!ENDIF!][!CR!]
    /* Pointer to Run time Test configuration */
    [!IF "num:i($GroupCountRuntime) = num:i(0)"!]NULL_PTR,[!ELSE!]*Th_RuntimeTests_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!],[!ENDIF!][!CR!]
    /* Pointer to Post-run Test configuration */
    [!IF "num:i($GroupCountPostrun) = num:i(0)"!]NULL_PTR,[!ELSE!]*Th_PostRunTests_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!],[!ENDIF!][!CR!]
    /* Start of array of TestLib function pointers  */
    &Th_MTLFuncList_ConfigSet[!"$SlConfigSetIndex"!]_Core[!"num:i($CoreId)"!][0],
    [!IF "$MasterCoreId = $CoreId"!][!//
[!NOCODE!]
[!ASSERT "node:refexists(SlPrerun/SlSmuConfigPrerunRef)", "SlConfigSet/*/SlPrerun/SlSmuConfigPrerunRef: Reference to SMU configuration is empty"!]
[!VAR "SmuConfigRef" = "node:value(SlPrerun/SlSmuConfigPrerunRef)"!]
[!VAR "SmuConfigRef" = "substring-after($SmuConfigRef, "/")"!]
[!VAR "SmuConfigRef" = "substring-after($SmuConfigRef, "/")"!]
[!VAR "SmuConfigRef" = "substring-after($SmuConfigRef, "/")"!]
[!ENDNOCODE!]
    /* Address of SMU configuration for pre-run phase */
    &Smu_ConfigRoot[[!"$SmuConfigRef"!]],
    [!ELSE!][!//
    /* Address of SMU configuration for pre-run phase For Slave core, it is NULL_PTR */
    NULL_PTR,
    [!ENDIF!][!//
    [!IF "$MasterCoreId = $CoreId"!][!//
[!NOCODE!]
[!ASSERT "node:refexists(SlRuntime/SlSmuConfigRuntimeRef)", "SlConfigSet/*/SlRuntime/SlSmuConfigRuntimeRef: Reference to SMU configuration is empty"!]
[!VAR "SmuConfigRef" = "node:value(SlRuntime/SlSmuConfigRuntimeRef)"!]
[!VAR "SmuConfigRef" = "substring-after($SmuConfigRef, "/")"!]
[!VAR "SmuConfigRef" = "substring-after($SmuConfigRef, "/")"!]
[!VAR "SmuConfigRef" = "substring-after($SmuConfigRef, "/")"!]
[!ENDNOCODE!]
    /* Address of SMU configuration for runtime phase*/
    &Smu_ConfigRoot[[!"$SmuConfigRef"!]],
    [!ELSE!][!//
    /* Address of SMU configuration for pre-run phase For Slave core, it is NULL_PTR */
    NULL_PTR,
    [!ENDIF!][!//
    /* Number of early pre-run test groups  */
    [!"num:i(count(SlEarlyPrerun/SlTestGroupEarlyPrerun/*))"!]U,
    /* Number of pre-run test groups  */
    [!"num:i(count(SlPrerun/SlTestGroupPrerun/*))"!]U,
    /* Number of run-time test groups  */
    [!"num:i(num:i(count(SlRuntime/SlTestGroupRuntime/*)))"!]U,
    /* Number of post-run test groups  */
    [!"num:i(count(SlPostrun/SlTestGroupPostrun/*))"!]U,
    /* Core Id to which this config set corresponds to */
    [!"num:i($CoreId)"!]U
[!ENDINDENT!]    
[!ENDSELECT!]
  },
[!ENDFOR!]
};
[!ENDSELECT!]
#define IFX_TSTHANDLER_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
