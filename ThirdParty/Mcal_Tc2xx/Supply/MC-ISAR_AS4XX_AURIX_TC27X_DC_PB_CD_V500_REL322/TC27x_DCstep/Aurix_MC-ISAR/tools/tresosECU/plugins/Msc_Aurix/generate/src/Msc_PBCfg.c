[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Msc_PBCfg.c $                                              **
**                                                                           **
**  $CC VERSION : \main\19 $                                                 **
**                                                                           **
**  $DATE       : 2014-10-29 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Msc_PBCfg.c file                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
[!//
/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Msc_PBCfg.c                                                  **
**                                                                           **
**  $CC VERSION : \main\19 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : MSC configuration generated out of ECU configuration      **
**                 file (Msc.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEBILITY : 
    [cover parentID = DS_NAS_MSC_PR69_PR469_PR122_PR123,DS_NAS_MSC_PR647,
    SAS_NAS_MSC_PR1071,DS_NAS_MSC_PR446,DS_NAS_MSC_PR699,DS_NAS_MSC_PR709,
    SAS_NAS_MSC_PR914,SAS_NAS_MSC_PR915,SAS_NAS_MSC_PR916,SAS_NAS_MSC_PR60,
    SAS_NAS_MSC_PR82, DS_NAS_MSC_PR704,DS_NAS_MSC_PR707,DS_NAS_MSC_PR708,
    DS_NAS_MSC_PR712]
**  [/cover]                                                                 **
*******************************************************************************/
[!NOCODE!][!//
[!INCLUDE "Msc.m"!][!//
[!ENDNOCODE!][!//
/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/
/* Include module header file */
#include "Msc.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                    Call Back Function Prototype                            **
*******************************************************************************/
[!VAR "PostBuildLoadable" = "num:i(0)"!][!//
[!SELECT "as:modconf('EcuM')[1]"!][!//
[!IF "EcuMConfiguration/*[1]/EcuMPostBuildConfigType = 'LOADABLE'"!][!//
[!VAR "PostBuildLoadable" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Msc')[1]"!][!//
[!IF "$PostBuildLoadable = num:i(0)"!][!//
[!CALL "Msc_GenerateCallbackApi"!][!//
[!ENDIF!][!//
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* Memory Mapping the configuration constant */
#define MSC_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


[!//
[!VAR "SettingsIndex" = "num:i(0)"!][!//
[!VAR "NoOfSettings" = "num:i(count(MscConfigSet/*))"!][!//
/*
        Container: MscConfigSet
        Multilplicity : 1 - *
*/
[!FOR "SettingsIndex" = "0" TO "(num:i($NoOfSettings)- 1)"!][!//
static const Msc_ModuleConfigType Msc_kModuleConfiguration[!"string($SettingsIndex)"!][] = 
{
  /***** Configuration Set [!"$SettingsIndex"!] for MSC *****/
[!VAR "ModuleIndex" = "num:i(0)"!][!//
[!VAR "NoOfModules" = "num:i(count(MscConfigSet/*[@index = $SettingsIndex]/MscModuleConfiguration/*))"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i($NoOfModules)- 1)"!][!//
  /***** Configuration for MSC[!"$ModuleIndex"!] *****/
{
[!SELECT "MscConfigSet/*[@index = $SettingsIndex]/MscModuleConfiguration/*[@index = $ModuleIndex]/MscTxConfiguration"!][!//
[!NOCODE!][!//
[!VAR "DataBitsCountLow" = "num:i(count(MscDataFrameConfiguration/MscDataBitLowConfiguration/*))"!][!//
[!VAR "DataBitsCountHigh" = "num:i(count(MscDataFrameConfiguration/MscDataBitHighConfiguration/*))"!][!//
[!CALL "Msc_DscConfig", "TxMode" = "MscDataFrameConfiguration/MscDataFrameTxMode","DataBitsLow"="$DataBitsCountLow","DataBitsHigh"="$DataBitsCountHigh","EnsellLow"="MscDataFrameConfiguration/MscSelectionBitLowEnable","EnsellHigh"="MscDataFrameConfiguration/MscSelectionBitHighEnable","CmdLen"="MscCmdFrameConfiguration/MscCmdFrameLen", "CmdPassiveLen"="MscCmdFrameConfiguration/MscCmdPassivePhaseLen", "PassiveLen"="MscDataFrameConfiguration/MscPassivePhaseLen ","TxConfig"="num:i(0)", "TxConfigExtn"="num:i(0)"!][!//
[!VAR "DsdsConfig" = "num:i(0)"!][!//
[!VAR "DsdsConfigExtension" = "num:i(0)"!][!//
[!VAR "DsdsMask" = "num:i(0)"!][!//
[!VAR "DsdsMaskExtn" = "num:i(0)"!][!//
[!VAR "EmgStopConfig" = "num:i(0)"!][!//
[!VAR "EmgExtnStopConfig" = "num:i(0)"!][!//
[!VAR "EmgStopConfigVal" = "num:i(0)"!][!//
[!VAR "EmgExtnStopConfigVal" = "num:i(0)"!][!//
[!SELECT "MscDataFrameConfiguration"!][!//
[!FOR "BitIndex" = "0" TO "(num:i($DataBitsCountLow)- 1)"!][!//
[!VAR "CurrentBit" = "num:i(0)"!][!//
[!VAR "CurrentBit" = "MscDataBitLowConfiguration/*[@index = $BitIndex]/MscDataBitIndex"!][!//
[!CALL "Msc_DsdsConfig", "BitNo" = "$CurrentBit", "SourceSel"="MscDataBitLowConfiguration/*[@index = $BitIndex]/MscDataBitSrc", "EmgStopEnb"="MscDataBitLowConfiguration/*[@index = $BitIndex]/MscDataBitEmergencyStopActive", "EmgStopVal"="MscDataBitLowConfiguration/*[@index = $BitIndex]/MscDataBitEmergencyValue", "EmgStopConfig"="$EmgStopConfig", "EmgExtnStopConfig"="$EmgExtnStopConfig", "EmgStopConfigVal"="$EmgStopConfigVal", "EmgExtnStopConfigVal"="$EmgExtnStopConfigVal", "DsdsConfig"="$DsdsConfig", "DsdsMask"="$DsdsMask", "DsdsMaskExtn"="$DsdsMaskExtn", "DsdsConfigExtension"="$DsdsConfigExtension"!][!//
[!ENDFOR!][!//
[!VAR "DsdsConfigLow" = "$DsdsConfig"!][!//
[!VAR "DsdsConfigLowExtension" = "$DsdsConfigExtension"!][!//
[!VAR "DsdsMaskLow" = "$DsdsMask"!][!//
[!VAR "DsdsMaskLowExtn" = "$DsdsMaskExtn"!][!//
[!VAR "EmgStopConfigLow" = "$EmgStopConfig"!][!//
[!VAR "EmgExtnStopConfigLow" = "$EmgExtnStopConfig"!][!//
[!VAR "EmgStopConfigValLow" = "$EmgStopConfigVal"!][!//
[!VAR "EmgExtnStopConfigValLow" = "$EmgExtnStopConfigVal"!][!//
[!VAR "DsdsConfig" = "num:i(0)"!][!//
[!VAR "DsdsConfigExtension" = "num:i(0)"!][!//
[!VAR "DsdsMask" = "num:i(0)"!][!//
[!VAR "DsdsMaskExtn" = "num:i(0)"!][!//
[!VAR "EmgStopConfigVal" = "num:i(0)"!][!//
[!VAR "EmgStopConfig" = "num:i(0)"!][!//
[!VAR "EmgExtnStopConfig" = "num:i(0)"!][!//
[!VAR "EmgExtnStopConfigVal" = "num:i(0)"!][!//
[!FOR "BitIndex" = "0" TO "(num:i($DataBitsCountHigh)- 1)"!][!//
[!VAR "CurrentBit" = "num:i(0)"!][!//
[!VAR "CurrentBit" = "MscDataBitHighConfiguration/*[@index = $BitIndex]/MscDataBitIndex"!][!//
[!CALL "Msc_DsdsConfig", "BitNo" = "$CurrentBit", "SourceSel"="MscDataBitHighConfiguration/*[@index = $BitIndex]/MscDataBitSrc", "EmgStopEnb"="MscDataBitHighConfiguration/*[@index = $BitIndex]/MscDataBitEmergencyStopActive", "EmgStopVal"="MscDataBitHighConfiguration/*[@index = $BitIndex]/MscDataBitEmergencyValue", "EmgStopConfig"="$EmgStopConfig", "EmgExtnStopConfig"="$EmgExtnStopConfig","EmgStopConfigVal"="$EmgStopConfigVal", "EmgExtnStopConfigVal"="$EmgExtnStopConfigVal", "DsdsConfig"="$DsdsConfig", "DsdsMask" = "$DsdsMask", "DsdsMaskExtn" = "$DsdsMaskExtn", "DsdsConfigExtension"="$DsdsConfigExtension"!][!//
[!ENDFOR!][!//
[!VAR "DsdsConfigHigh" = "$DsdsConfig"!][!//
[!VAR "DsdsConfigHighExtension" = "$DsdsConfigExtension"!][!//
[!VAR "DsdsMaskHigh" = "$DsdsMask"!][!//
[!VAR "DsdsMaskHighExtn" = "$DsdsMaskExtn"!][!//
[!VAR "EmgStopConfigValHigh" = "$EmgStopConfigVal"!][!//
[!VAR "EmgExtnStopConfigValHigh" = "$EmgExtnStopConfigVal"!][!//
[!VAR "EmgStopConfigHigh" = "$EmgStopConfig"!][!//
[!VAR "EmgExtnStopConfigHigh" = "$EmgExtnStopConfig"!][!//
[!VAR "DsceConfig" = "num:i(0)"!][!//
[!VAR "ExtnValue" = "num:i(0)"!][!//
[!IF "MscExtensionEnableValue = 'EXTENSION_ENABLE'"!][!//
[!VAR "ExtnValue" = "num:i(1)"!][!//
[!ENDIF!][!//
[!CALL "Msc_DsceConfig", "P0Enb" = "MscInjP0Enable", "P1Enb"="MscInjP1Enable", "P0Pos"="MscInjP0Pos", "P1Pos"="MscInjP1Pos", "DataIns"="../MscCmdFrameConfiguration/MscAutomaticDataInsertionEnable", "DsceConfig"="$DsceConfig","ExenStatus"="MscExtensionEnableValue", "DataBitsLow"="$DataBitsCountLow","DataBitsHigh"="$DataBitsCountHigh"!][!//
[!IF "MscInjP1Enable = 'PIN1_INJECTION_ENABLE'"!][!//
  [!IF "MscInjP1Pos <= num:i(15)"!][!//  
   [!IF "MscInjP1EmergencyValue = 'INJP1_EMERGENCY_LOGICAL_HIGH'"!][!//
    [!VAR "EmgStopConfigValLow" = "bit:bitset($EmgStopConfigValLow,num:i(MscInjP1Pos))"!][!//
   [!ELSE!][!//
    [!VAR "EmgStopConfigValLow" = "bit:bitclear($EmgStopConfigValLow,num:i(MscInjP1Pos))"!][!//
   [!ENDIF!][!//
  [!ELSEIF "MscInjP1Pos <= num:i(31) and MscInjP1Pos >= num:i(16)"!][!//
   [!IF "MscInjP1EmergencyValue = 'INJP1_EMERGENCY_LOGICAL_HIGH'"!][!//
    [!VAR "EmgStopConfigValHigh" = "bit:bitset($EmgStopConfigValHigh,(num:i(MscInjP1Pos)-16))"!][!//
   [!ELSE!][!//
    [!VAR "EmgStopConfigValHigh" = "bit:bitclear($EmgStopConfigValHigh,(num:i(MscInjP1Pos)-16))"!][!//
   [!ENDIF!][!// 
  [!ELSEIF "MscInjP1Pos <= num:i(47) and MscInjP1Pos >= num:i(32)"!][!//
   [!IF "MscInjP1EmergencyValue = 'INJP1_EMERGENCY_LOGICAL_HIGH'"!][!//
    [!VAR "EmgExtnStopConfigValLow" = "bit:bitset($EmgExtnStopConfigValLow,(num:i(MscInjP1Pos)-32))"!][!//
   [!ELSE!][!//
    [!VAR "EmgExtnStopConfigValLow" = "bit:bitclear($EmgExtnStopConfigValLow,(num:i(MscInjP1Pos)-32))"!][!//
   [!ENDIF!][!//
  [!ELSEIF "MscInjP1Pos <= num:i(63) and MscInjP1Pos >= num:i(48)"!][!//
   [!IF "MscInjP1EmergencyValue = 'INJP1_EMERGENCY_LOGICAL_HIGH'"!][!//
    [!VAR "EmgExtnStopConfigValHigh" = "bit:bitset($EmgExtnStopConfigValHigh,(num:i(MscInjP1Pos)-48))"!][!//
   [!ELSE!][!//
    [!VAR "EmgExtnStopConfigValHigh" = "bit:bitclear($EmgExtnStopConfigValHigh,(num:i(MscInjP1Pos)-48))"!][!//
   [!ENDIF!][!//  
 [!ENDIF!][!//
[!ENDIF!][!//

[!IF "MscInjP0Enable = 'PIN0_INJECTION_ENABLE'"!][!//
  [!IF "MscInjP0Pos <= num:i(15)"!][!//  
   [!IF "MscInjP0EmergencyValue = 'INJP0_EMERGENCY_LOGICAL_HIGH'"!][!//
    [!VAR "EmgStopConfigValLow" = "bit:bitset($EmgStopConfigValLow,num:i(MscInjP0Pos))"!][!//
   [!ELSE!][!//
    [!VAR "EmgStopConfigValLow" = "bit:bitclear($EmgStopConfigValLow,num:i(MscInjP0Pos))"!][!//
   [!ENDIF!][!//
  [!ELSEIF "MscInjP0Pos <= num:i(31) and MscInjP0Pos >= num:i(16)"!][!//
   [!IF "MscInjP0EmergencyValue = 'INJP0_EMERGENCY_LOGICAL_HIGH'"!][!//
    [!VAR "EmgStopConfigValHigh" = "bit:bitset($EmgStopConfigValHigh,(num:i(MscInjP0Pos)-16))"!][!//
   [!ELSE!][!//
    [!VAR "EmgStopConfigValHigh" = "bit:bitclear($EmgStopConfigValHigh,(num:i(MscInjP0Pos)-16))"!][!//
   [!ENDIF!][!// 
  [!ELSEIF "MscInjP0Pos <= num:i(47) and MscInjP0Pos >= num:i(32)"!][!//
   [!IF "MscInjP0EmergencyValue = 'INJP0_EMERGENCY_LOGICAL_HIGH'"!][!//
    [!VAR "EmgExtnStopConfigValLow" = "bit:bitset($EmgExtnStopConfigValLow,(num:i(MscInjP0Pos)-32))"!][!//
   [!ELSE!][!//
    [!VAR "EmgExtnStopConfigValLow" = "bit:bitclear($EmgExtnStopConfigValLow,(num:i(MscInjP0Pos)-32))"!][!//
   [!ENDIF!][!//
  [!ELSEIF "MscInjP0Pos <= num:i(63) and MscInjP0Pos >= num:i(48)"!][!//
   [!IF "MscInjP0EmergencyValue = 'INJP0_EMERGENCY_LOGICAL_HIGH'"!][!//
    [!VAR "EmgExtnStopConfigValHigh" = "bit:bitset($EmgExtnStopConfigValHigh,(num:i(MscInjP0Pos)-48))"!][!//
   [!ELSE!][!//
    [!VAR "EmgExtnStopConfigValHigh" = "bit:bitclear($EmgExtnStopConfigValHigh,(num:i(MscInjP0Pos)-48))"!][!//
   [!ENDIF!][!//  
 [!ENDIF!][!//
[!ENDIF!][!//

[!ENDSELECT!][!//
[!VAR "ClkConfig" = "num:i(../MscClockConfiguration/MscClockStepValue)"!][!//
[!IF "../MscClockConfiguration/MscClockDividerMode = 'NORMAL_DIVIDER_MODE'"!][!//
[!VAR "ClkConfig" = "bit:or($ClkConfig,bit:shl(1,14))"!][!//
[!ELSEIF "../MscClockConfiguration/MscClockDividerMode = 'FRACTIONAL_DIVIDER_MODE'"!][!//
[!VAR "ClkConfig" = "bit:or($ClkConfig,bit:shl(2,14))"!][!//
[!ENDIF!][!//
[!VAR "SignalConfig" = "num:i(0)"!][!//
[!CALL "Msc_OcrConfig", "ClkLinePol" = "MscTxSignalTypeConfiguration/MscTxClockSignalType", "ClockType"="MscTxClockType", "SoLinePol"="MscTxSignalTypeConfiguration/MscTxDataSignalType", "CsLinePol"="MscTxSignalTypeConfiguration/MscTxChipSelectSignalType", "RxLinePol"="../MscRxConfiguration/MscRxDataSignalType", "SignalConfig"="$SignalConfig"!][!//
[!VAR "RxConfig" = "num:i(0)"!][!//
[!CALL "Msc_UsrConfig", "FrameType" = "../MscRxConfiguration/MscRxFrameType", "RxBaud"="../MscRxConfiguration/MscRxBaudRate", "ParityType"="../MscRxConfiguration/MscRxParityType", "ServDelay"="../MscRxConfiguration/MscRxIntDelayEnabled", "Rxconfig"="$RxConfig"!][!//
[!VAR "InterruptControl" = "num:i(0)"!][!//
[!VAR "InterruptServiceConfig" = "num:i(0)"!][!//
[!CALL "Msc_IcrConfig", "TimeIntrPtr" = "MscTimeFrameConfiguration/MscTimeFrameIntPtr","CmdIntrPtr"="MscCmdFrameConfiguration/MscCmdFrameIntPtr","DataIntrEnb"="MscDataFrameConfiguration/MscDataFrameIntrInput","DataIntrPtr"="MscDataFrameConfiguration/MscDataFrameIntrPtr","RxIntrEnb"="../MscRxConfiguration/MscRxFrameIntrInput","RxIntrPtr"="../MscRxConfiguration/MscRxFrameIntrPtr","InterruptControl"="$InterruptControl","InterruptServiceConfig"="$InterruptServiceConfig"!][!//
[!VAR "UpstreamTimeoutConfig" = "../MscRxConfiguration/MscUpstreamTimeoutPrescalar"!][!//
[!VAR "UpstreamTimeoutConfig" = "bit:or($UpstreamTimeoutConfig,bit:shl(../MscRxConfiguration/MscUpstreamTimeoutValue,4))"!][!//
[!VAR "SleepMode" = "num:i(0)"!][!//
[!IF "../MscClockConfiguration/MscSleepMode = 'SLEEP_DISABLE'"!][!//
[!VAR "SleepMode" = "num:i(8)"!][!//
[!ENDIF!]
[!VAR "TimeFrmCnt" = "MscTimeFrameConfiguration/MscTimeFrameCount"!][!//
[!ENDNOCODE!][!//
[!AUTOSPACING!][!//
  [!"num:inttohex($TxConfig,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DSC */
  [!"num:inttohex($TxConfigExtn,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DSTE */
  [!"num:inttohex($DsdsConfigLow,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DSDSL */
  [!"num:inttohex($DsdsConfigLowExtension,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DSDSLE */
  [!"num:inttohex($DsdsConfigHigh,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DSDSH */
  [!"num:inttohex($DsdsConfigHighExtension,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DSDSHE */
  [!"num:inttohex(bit:or($DsdsMaskLow,bit:shl($DsdsMaskHigh,16)),8)"!]U, /* Mask for bits selected Downstream Data Register as source */
  [!"num:inttohex(bit:or($DsdsMaskLowExtn,bit:shl($DsdsMaskHighExtn,16)),8)"!]U, /* Extension Mask for bits selected Downstream Data Register as source */
  [!"num:inttohex(bit:or($EmgStopConfigLow,bit:shl($EmgStopConfigHigh,16)),8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register ESR */
  [!"num:inttohex(bit:or($EmgExtnStopConfigLow,bit:shl($EmgExtnStopConfigHigh,16)),8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register ESRE */
  [!"num:inttohex($EmgStopConfigValLow,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DD.DDL */
  [!"num:inttohex($EmgExtnStopConfigValLow,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DDE.DDLE */
  [!"num:inttohex($EmgStopConfigValHigh,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DD.DDH */
  [!"num:inttohex($EmgExtnStopConfigValHigh,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DDE.DDHE */
  [!"num:inttohex($DsceConfig,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DSCE */
  [!"num:inttohex($ClkConfig,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register FDR */
  [!"num:inttohex($RxConfig,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register USR */
  [!"num:inttohex($SignalConfig,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register OCR */
  [!"num:inttohex($UpstreamTimeoutConfig,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register USCE */
  [!"num:inttohex($TimeFrmCnt,2)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DSS */
  [!"num:inttohex($SleepMode,2)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register CLC */
  [!"num:inttohex($ExtnValue,2)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register DSCE Extension Enable Value */
  /* Interrupt configration for MSC[!"$ModuleIndex"!] Module */
  {
    [!"num:inttohex($InterruptControl,8)"!]U, /* Configuration for MSC[!"$ModuleIndex"!] register ICR */
    /* Application Notifier Function for Time Frame Interrupt */
    [!IF "MscTimeFrameConfiguration/MscTimeFrameNotification = 'NULL_PTR'"!][!//
    [!"MscTimeFrameConfiguration/MscTimeFrameNotification"!],
    [!ELSE!][!//
    [!IF "$PostBuildLoadable = num:i(0)"!][!//
    &[!"MscTimeFrameConfiguration/MscTimeFrameNotification"!],
    [!ELSE!][!//
    [!"MscTimeFrameConfiguration/MscTimeFrameNotification"!]U,
    [!ENDIF!][!//
    [!ENDIF!]
    /* Application Notifier Function for Command Frame Interrupt */
    [!IF "MscCmdFrameConfiguration/MscCmdFrameNotification = 'NULL_PTR'"!][!//
    [!"MscCmdFrameConfiguration/MscCmdFrameNotification"!],
    [!ELSE!][!//
    [!IF "$PostBuildLoadable = num:i(0)"!][!//
    &[!"MscCmdFrameConfiguration/MscCmdFrameNotification"!],
    [!ELSE!][!//
    [!"MscCmdFrameConfiguration/MscCmdFrameNotification"!]U,
    [!ENDIF!][!//
    [!ENDIF!]
    /* Application Notifier Function for Data Frame Interrupt */
    [!IF "MscDataFrameConfiguration/MscDataFrameNotification = 'NULL_PTR'"!][!//
    [!"MscDataFrameConfiguration/MscDataFrameNotification"!],
    [!ELSE!][!//
    [!IF "$PostBuildLoadable = num:i(0)"!][!//
    &[!"MscDataFrameConfiguration/MscDataFrameNotification"!],
    [!ELSE!][!//
    [!"MscDataFrameConfiguration/MscDataFrameNotification"!]U,
    [!ENDIF!][!//
    [!ENDIF!]
    /* Application Notifier Function for Rx Frame Interrupt */
    [!IF "../MscRxConfiguration/MscRxFrameNotification = 'NULL_PTR'"!][!//
    [!"../MscRxConfiguration/MscRxFrameNotification"!],
    [!ELSE!][!//
    [!IF "$PostBuildLoadable = num:i(0)"!][!//
    &[!"../MscRxConfiguration/MscRxFrameNotification"!],
    [!ELSE!][!//
    [!"../MscRxConfiguration/MscRxFrameNotification"!]U,
    [!ENDIF!][!//
    [!ENDIF!]
    /* Configuration for Service Requests SR0, SR1, SR2 and SR3*/
    [!"num:inttohex($InterruptServiceConfig,2)"!]U
  }
[!ENDSELECT!][!//
[!AUTOSPACING!][!//
}[!IF "$ModuleIndex != $NoOfModules -1"!],[!ENDIF!]

[!ENDFOR!][!//
};
[!ENDFOR!][!//

/*     MSC Config Root    */
const Msc_ConfigType Msc_ConfigRoot[]=
{
[!VAR "SettingsIndex" = "num:i(0)"!][!//
[!VAR "NoOfSettings" = "num:i(count(MscConfigSet/*))"!][!//
[!FOR "SettingsIndex" = "0" TO "(num:i($NoOfSettings)- 1)"!][!//
{
[!AUTOSPACING!]
  /* Configuration Set [!"$SettingsIndex"!] for MSC */
  {
    [!VAR "NoOfModules" = "num:i(count(MscConfigSet/*[@index = $SettingsIndex]/MscModuleConfiguration/*))"!][!//
    [!"'&Msc_kModuleConfiguration'"!][!"string($SettingsIndex)"!][!"'[0]'"!][!//
    [!IF "ecu:get('Msc.NoOfModules') > 1"!][!//
,
    [!IF "$NoOfModules > 1"!]
    [!"'&Msc_kModuleConfiguration'"!][!"string($SettingsIndex)"!][!"'[1]'"!][!//
    [!ELSE!][!//
    [!"'NULL_PTR'"!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "ecu:get('Msc.NoOfModules') > 2"!][!//
,
    [!IF "$NoOfModules > 2"!]
    [!"'&Msc_kModuleConfiguration'"!][!"string($SettingsIndex)"!][!"'[2]'"!]
    [!ELSE!][!//
    [!"'NULL_PTR'"!]
    [!ENDIF!][!//
    [!ENDIF!][!//

  }
}[!IF "$SettingsIndex != $NoOfSettings -1"!],[!ENDIF!]

[!AUTOSPACING!]
[!ENDFOR!]
};
[!ENDSELECT!][!//

#define MSC_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"



