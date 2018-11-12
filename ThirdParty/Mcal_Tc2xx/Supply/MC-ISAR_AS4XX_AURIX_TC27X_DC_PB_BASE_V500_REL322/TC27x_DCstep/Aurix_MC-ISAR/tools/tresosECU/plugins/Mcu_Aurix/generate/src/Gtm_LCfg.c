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
**  $FILENAME   : Gtm_LCfg.c $                                               **
**                                                                           **
**  $CC VERSION : \main\22 $                                                 **
**                                                                           **
**  $DATE       : 2014-12-03 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Gtm_LCfg.c file                          **
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
**  FILENAME  : Gtm_LCfg.c                                                   **
**                                                                           **
**  $CC VERSION : \main\22 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file (Mcu.bmd/.xdm)                                       **
**                                                                           **
**  TRACEABILITY: 
    [cover parentID=SAS_AS4XX_GTM_PR679_1,SAS_AS4XX_GTM_PR679_2,
    SAS_AS4XX_GTM_PR679_3]
[/cover]                                                                     **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
*******************************************************************************/
[!/* Select MODULE-CONFIGURATION as context-node */!][!/*
*/!][!INCLUDE "Gtm.m"!][!/*
*/!][!SELECT "as:modconf('Mcu')[1]"!][!/*
*/!][!/* Generate this file only if Gtm is configured
*/!][!VAR "RelDerivate" = "ecu:get('Rel.Derivate')"!][!/* 
*/!][!IF "($RelDerivate = '_TRICORE_TC297') or ($RelDerivate = '_TRICORE_TC298') or ($RelDerivate = '_TRICORE_TC299')"!][!/*
*/!][!VAR "RelDerivate" = "'TC29x'"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "($RelDerivate = '_TRICORE_TC264') or ($RelDerivate = '_TRICORE_TC265') or ($RelDerivate = '_TRICORE_TC267')"!][!/*
*/!][!VAR "RelDerivate" = "'TC26x'"!][!/*
*/!][!ENDIF!][!/*
*/!][!NOCODE!][!/*
*/!][!/* To Count the Number of Gtm Configurations inside all the Mcu PB Containers */!][!/*
*/!][!VAR "TotalGtmConfig" = "num:i(0)"!][!/*
*/!][!VAR "McuSelect" = "'McuModuleConfiguration'"!][!/*
*/!][!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($McuSelect)/*))- 1)"!][!/*
*/!][!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleIndex + 1,']')"!][!/*
*/!][!VAR "Count" = "num:i(count(node:ref($McuSelectIndex)/GtmConfiguration/*))"!][!/*
*/!][!IF "$Count > num:i(0)"!][!/*    
*/!][!VAR "TotalGtmConfig" = "$TotalGtmConfig + $Count"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TotalGtmConfigInAllContainers" = "num:i(count(McuModuleConfiguration/*/GtmConfiguration/*))"!][!/*
*/!][!ASSERT "($TotalGtmConfigInAllContainers = num:i(0)) or ($TotalGtmConfigInAllContainers =  (num:i(count(McuModuleConfiguration/*))))"!][!/*
*/!]Configuration Error: If any one MCU config set has GTM configured, then all the MCU config sets should have GTM configured
[!ENDASSERT!][!/*
To determine the Post Build Type
*/!][!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$TotalGtmConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!IF "node:exists(EcuMPostBuildConfigType) ='true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!/*
*/!][!ENDNOCODE!][!/*
*/!][!/* Run the Code generator only if there is atleast 1 Gtm Configuration among the containers
*/!][!IF "$TotalGtmConfig > num:i(0)"!][!/*
*/!]

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
#include "Gtm.h"



/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Note:
The user can configure the parameters with the tag Configuration:
The user should not change anything under the tag Configuration Options:
*/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/
[!CALL "Gtm_GenNotifExterns"!][!//
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
[!NOCODE!][!/*
*/!][!VAR "IsBmdUsed" = "'false'"!][!/*
*/!][!VAR "TotalMcuConfig" = "num:i(count(node:ref($McuSelect)/*))"!][!/*
*/!][!ENDNOCODE!][!/*
*/!][!VAR "PortConfigPresent" = "num:i(0)"!][!/*
*/!][!VAR "ClockConfigExist" = "num:i(0)"!][!/*
*/!][!VAR "ModuleId" = "num:i(0)"!][!/*
*/!][!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleId + 1,']')"!][!/*
*/!][!SELECT "node:ref($McuSelectIndex)"!][!/*
       Validation of TOM and ATOM Channels
*/!][!VAR "TomModuleLookUp1"	= "num:i(0)"!][!/*
*/!][!VAR "TomModuleLookUp2"	= "num:i(0)"!][!/*
*/!][!VAR "TomModuleLookUp3"	= "num:i(0)"!][!/*
*/!][!VAR "TomModuleLookUp4"	= "num:i(0)"!][!/*
*/!][!VAR "TomModuleLookUp5"	= "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp1"	= "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp2"	= "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp3"	= "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp4"	= "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp5"	= "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp6"	= "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp7"	= "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp8"	= "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp9"	= "num:i(0)"!][!/*
*/!][!VAR "TomUsage0"	= "num:i(0)"!][!/*
*/!][!VAR "TomUsage1"	= "num:i(0)"!][!/*
*/!][!VAR "AtomUsage0"	= "num:i(0)"!][!/*
*/!][!VAR "AtomUsage1"	= "num:i(0)"!][!/*
*/!][!VAR "TomTGCUsage0"	= "num:i(0)"!][!/*
*/!][!VAR "AtomAGCUsage0"	= "num:i(0)"!][!/*
*/!][!VAR "PwmId" = "$ModuleId"!][!/*
*/!][!SELECT "as:modconf('Pwm')[1]"!][!/*
*/!][!SELECT "PwmChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "PwmChannel/*"!][!/*
*/!][!ASSERT "node:refexists(./PwmAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: PWM: PWMAssignedHwUnit is not configured.[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./PwmAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./PwmAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "$ModuleType = 'Tom'"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp1"	= "bit:bitset($TomModuleLookUp1, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp2"	= "bit:bitset($TomModuleLookUp2, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp3"	= "bit:bitset($TomModuleLookUp3, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSE!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp1"	= "bit:bitset($AtomModuleLookUp1, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp2"	= "bit:bitset($AtomModuleLookUp2, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp3"	= "bit:bitset($AtomModuleLookUp3, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp4"	= "bit:bitset($AtomModuleLookUp4, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp5"	= "bit:bitset($AtomModuleLookUp5, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*	
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ENDSELECT!][!/*
*/!][!/*
*/!][!/*
*/!][!/* Information from GPT
*/!][!SELECT "as:modconf('Gpt')[1]"!][!/*
*/!][!SELECT "GptChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "GptChannelConfiguration/*"!][!/*
*/!][!ASSERT "node:refexists(./GptAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: GPT: GptAssignedHwUnit is not configured.[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./GptAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./GptAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "$ModuleType = 'Tom'"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp1"	= "bit:bitset($TomModuleLookUp1, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TomModuleLookUp2"	= "bit:bitset($TomModuleLookUp2, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TomModuleLookUp3"	= "bit:bitset($TomModuleLookUp3, $SetPosition + 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSE!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*		
*/!][!VAR "AtomModuleLookUp1"	= "bit:bitset($AtomModuleLookUp1, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp2"	= "bit:bitset($AtomModuleLookUp2, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp3"	= "bit:bitset($AtomModuleLookUp3, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp4"	= "bit:bitset($AtomModuleLookUp4, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp5"	= "bit:bitset($AtomModuleLookUp5, $SetPosition + 1)"!][!/*
*/!][!ENDIF!][!/*	
*/!][!ENDIF!][!/*	
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ENDSELECT!][!/*
*/!][!/*
*/!][!/* Information in GTM as Complex
*/!][!VAR "ComplexDriverTomConfig" = "num:i(0)"!][!/*
*/!][!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!LOOP "Tom/*"!][!/*
*/!][!LOOP "TomChannel/*"!][!/*
*/!][!IF "./TomChannelUsage/TomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "ComplexDriverTomConfig" = "1"!][!/*	
*/!][!VAR "ChannelLocation" = "node:name(.)"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(./../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TomModuleLookUp1"	= "bit:or($TomModuleLookUp1, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TomModuleLookUp2"	= "bit:or($TomModuleLookUp2, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TomModuleLookUp3"	= "bit:or($TomModuleLookUp3, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TomModuleLookUp4"	= "bit:or($TomModuleLookUp4, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TomModuleLookUp5"	= "bit:or($TomModuleLookUp5, bit:shl(3,$SetPosition))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*	
*/!][!ENDLOOP!][!/*
*/!][!ENDLOOP!][!/*
*/!][!/* For ATOM
*/!][!VAR "ComplexDriverAtomConfig" = "num:i(0)"!][!/*
*/!][!LOOP "Atom/*"!][!/*
*/!][!LOOP "AtomChannel/*"!][!/*
*/!][!IF "./AtomChannelUsage/AtomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "ComplexDriverAtomConfig" = "1"!][!/*	
*/!][!VAR "ChannelLocation" = "node:name(.)"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(./../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*		
*/!][!VAR "AtomModuleLookUp1"	= "bit:or($AtomModuleLookUp1, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp2"	= "bit:or($AtomModuleLookUp2, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp3"	= "bit:or($AtomModuleLookUp3, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp4"	= "bit:or($AtomModuleLookUp4, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp5"	= "bit:or($AtomModuleLookUp5, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(5)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp6, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp6"	= "bit:or($AtomModuleLookUp6, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(6)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp7, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp7"	= "bit:or($AtomModuleLookUp7, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(7)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp8, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp8"	= "bit:or($AtomModuleLookUp8, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(8)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp9, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "AtomModuleLookUp9"	= "bit:or($AtomModuleLookUp9, bit:shl(3,$SetPosition))"!][!/*
*/!][!ENDIF!][!/*	
*/!][!ENDIF!][!/*	
*/!][!ENDLOOP!][!/*
*/!][!ENDLOOP!][!/*
*/!][!/* For Debug
Tom Lookup1 is [!"num:inttohex($TomModuleLookUp1)"!]
Tom Lookup2 is [!"num:inttohex($TomModuleLookUp2)"!]
Atom Lookup1 is [!"num:inttohex($AtomModuleLookUp1)"!]
Atom Lookup2 is [!"num:inttohex($AtomModuleLookUp2)"!]
*/!][!/* Validation of TIM from ICU */!][!/*
*/!][!VAR "IcuId" = "$ModuleId"!][!/*
*/!][!VAR "TimModuleLookUp1" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp2" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp3" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp4" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp5" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp6" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup1" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup2" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup3" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup4" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup5" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup6" = "num:i(0)"!][!/*
*/!][!SELECT "as:modconf('Icu')[1]"!][!/*
*/!][!LOOP "IcuConfigSet/*[@index= $IcuId]/IcuChannel/*"!][!/*
*/!][!ASSERT "node:refexists(./IcuAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: ICU: Reference cell [!"@name"!] not provided - configure AssignedHwUnit
[!ENDASSERT!][!/*
*/!][!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!IF "contains($ChannelLocation, "TimChannel") = 'true'"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./IcuAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp1"	= "bit:bitset($TimModuleLookUp1, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup1"	= "bit:bitset($TimTimeStampLookup1, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp2"	= "bit:bitset($TimModuleLookUp2, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup2"	= "bit:bitset($TimTimeStampLookup2, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp3"	= "bit:bitset($TimModuleLookUp3, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup3"	= "bit:bitset($TimTimeStampLookup3, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp4"	= "bit:bitset($TimModuleLookUp4, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup4"	= "bit:bitset($TimTimeStampLookup4, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp5"	= "bit:bitset($TimModuleLookUp5, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup5"	= "bit:bitset($TimTimeStampLookup5, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(5)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp6, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp6"	= "bit:bitset($TimModuleLookUp6, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup6"	= "bit:bitset($TimTimeStampLookup6, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/* IF "contains($ChannelLocation, "TimChannel") = 'true'"
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!/* Validation of TIM from Complex */!][!/*
*/!][!VAR "ComplexDriverTimConfig" = "num:i(0)"!][!/*
*/!][!LOOP "Tim/*"!][!/*
*/!][!LOOP "TimChannel/*"!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "ComplexDriverTimConfig" = "1"!][!/*	
*/!][!VAR "ChannelLocation" = "node:name(.)"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(./../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TimModuleLookUp1"	= "bit:bitset($TimModuleLookUp1, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TimModuleLookUp2"	= "bit:bitset($TimModuleLookUp2, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TimModuleLookUp3"	= "bit:bitset($TimModuleLookUp3, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TimModuleLookUp4"	= "bit:bitset($TimModuleLookUp4, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TimModuleLookUp5"	= "bit:bitset($TimModuleLookUp5, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(5)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp6, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*	
*/!][!VAR "TimModuleLookUp6"	= "bit:bitset($TimModuleLookUp6, num:i($SetPosition + 1))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDLOOP!]
#define GTM_START_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"

#ifdef GTM_MOD_CH_CONFIGURED
#if (GTM_MOD_CH_CONFIGURED == (STD_ON))

const Gtm_NotificationConfigType Gtm_kNotifConfig0 =
{
#if (GTM_NO_OF_TIM_CH_CONF_NOTIF > 0U)
	
{
  /*TIM Notification pointers*/
[!CALL "Gtm_TimNotifConfig", "TimModuleLookUp"="$TimModuleLookUp1", "ModuleNumber"="0"!][!/*	
*/!][!CALL "Gtm_TimNotifConfig", "TimModuleLookUp"="$TimModuleLookUp2", "ModuleNumber"="1"!][!/*		
*/!][!CALL "Gtm_TimNotifConfig", "TimModuleLookUp"="$TimModuleLookUp3", "ModuleNumber"="2"!][!/*		
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_TimNotifConfig", "TimModuleLookUp"="$TimModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_TimNotifConfig", "TimModuleLookUp"="$TimModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!CALL "Gtm_TimNotifConfig", "TimModuleLookUp"="$TimModuleLookUp6", "ModuleNumber"="5"!][!/*
*/!][!ENDIF!]
},
#endif 
  
#if (GTM_NO_OF_TOM_CH_CONF_NOTIF > 0U)
{
	/*TOM Notification pointers*/
[!CALL "Gtm_TomNotifConfig", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!][!/*	
*/!][!CALL "Gtm_TomNotifConfig", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!][!/*		
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_TomNotifConfig", "TomModuleLookUp"="$TomModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_TomNotifConfig", "TomModuleLookUp"="$TomModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!CALL "Gtm_TomNotifConfig", "TomModuleLookUp"="$TomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!]

},
#endif
[!VAR "MutiNotifUsed" = "num:i(0)"!][!//
[!CALL "IsMultiNotifUsed"!][!//
[!IF "$MutiNotifUsed = num:i(0)"!][!//
#if (GTM_NO_OF_ATOM_CH_CONF_NOTIF > 0U)
{
  /*ATOM Notification pointers*/
[!CALL "Gtm_AtomNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp1", "ModuleNumber"="0"!][!/*	
*/!][!CALL "Gtm_AtomNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp2", "ModuleNumber"="1"!][!/*		
*/!][!CALL "Gtm_AtomNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp3", "ModuleNumber"="2"!][!/*		
*/!][!CALL "Gtm_AtomNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp4", "ModuleNumber"="3"!][!/*		
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_AtomNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_AtomNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp6", "ModuleNumber"="5"!][!/*		
*/!][!CALL "Gtm_AtomNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp7", "ModuleNumber"="6"!][!/*
*/!][!CALL "Gtm_AtomNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp8", "ModuleNumber"="7"!][!/*
*/!][!CALL "Gtm_AtomNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp9", "ModuleNumber"="8"!][!/*
*/!][!ENDIF!]
}
#endif
[!ELSE!]
{
  /*ATOM CCU0 Notification pointers*/
[!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp1", "ModuleNumber"="0", "CcuNumber"="0"!][!/*	
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp2", "ModuleNumber"="1", "CcuNumber"="0"!][!/*		
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp3", "ModuleNumber"="2", "CcuNumber"="0"!][!/*		
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp4", "ModuleNumber"="3", "CcuNumber"="0"!][!/*		
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp5", "ModuleNumber"="4", "CcuNumber"="0"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp6", "ModuleNumber"="5", "CcuNumber"="0"!][!/*		
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp7", "ModuleNumber"="6", "CcuNumber"="0"!][!/*
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp8", "ModuleNumber"="7", "CcuNumber"="0"!][!/*
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp9", "ModuleNumber"="8", "CcuNumber"="0"!][!/*
*/!][!ENDIF!]
},
{
  /*ATOM CCU1 Notification pointers*/
[!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp1", "ModuleNumber"="0", "CcuNumber"="1"!][!/*	
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp2", "ModuleNumber"="1", "CcuNumber"="1"!][!/*		
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp3", "ModuleNumber"="2", "CcuNumber"="1"!][!/*		
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp4", "ModuleNumber"="3", "CcuNumber"="1"!][!/*		
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp5", "ModuleNumber"="4", "CcuNumber"="1"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp6", "ModuleNumber"="5", "CcuNumber"="1"!][!/*		
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp7", "ModuleNumber"="6", "CcuNumber"="1"!][!/*
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp8", "ModuleNumber"="7", "CcuNumber"="1"!][!/*
*/!][!CALL "Gtm_AtomCCUNotifConfig", "AtomModuleLookUp"="$AtomModuleLookUp9", "ModuleNumber"="8", "CcuNumber"="1"!][!/*
*/!][!ENDIF!]
}
[!ENDIF!][!//	[!IF "$MutiNotifUsed = num:i(0)"!]
};
#endif 
/*#ifdef GTM_MOD_CH_CONFIGURED*/
#endif 
/*#if (GTM_MOD_CH_CONFIGURED == (STD_ON))*/

#define GTM_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"

[!/*
*/!][!ENDSELECT!][!/*[!SELECT "GtmConfiguration/*[1]"!]
*/!][!ENDSELECT!][!/* [!SELECT "node:ref($McuSelectIndex)"!]
*/!][!ENDIF!][!/*  [!IF "$TotalGtmConfig > num:i(0)"!]
*/!][!ENDSELECT!][!//[!SELECT "as:modconf('Mcu')[1]"!][!//
