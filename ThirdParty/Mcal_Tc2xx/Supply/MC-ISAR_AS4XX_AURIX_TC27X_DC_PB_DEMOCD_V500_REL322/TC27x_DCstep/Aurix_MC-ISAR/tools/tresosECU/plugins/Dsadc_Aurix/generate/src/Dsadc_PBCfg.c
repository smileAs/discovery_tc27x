[!/****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Dsadc_PBCfg.c $                                             **
**                                                                            **
**  $CC VERSION : \main\13 $                                                 **
**                                                                            **
**  $DATE       : 2014-11-07 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                Code template for Dsadc_PBCfg.c file                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/!][!//
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
**  FILENAME  : Dsadc_PBCfg.c                                                **
**                                                                           **
**  $CC VERSION : \main\13 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                     **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                         **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : Dsadc configuration generated out of ECU configuration    **
**                 file(Dsadc.bmd/.xdm)                                      **
**                                                                           **
**  SPECIFICATION(S) :                                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                                                                           **
**  TRACEBILITY :                                                            **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/
/* Include module header file */
#include "Dsadc.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                    Call Back Function Prototype                            **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* Memory Mapping the configuration constant */
#define DSADC_START_SEC_POSTBUILDCFG
#include "MemMap.h"    

/*
        Container: DsadcChannelConfigSet
        Multilplicity : 1 - *
*/
[!SELECT "as:modconf('Mcu')[1]"!][!//

[!VAR "McuOscillatorClk" = "McuGeneralConfiguration/McuMainOscillatorFrequency"!]

[!ENDSELECT!][!//

[!SELECT "as:modconf('Dsadc')[1]"!][!//

[!VAR "DsadcMaxCMHVRegs" = "ecu:get('Dsadc.NoOfCMHVRegisters')"!][!//

[!IF "DsadcGeneral/DsadcEnableLimitCheck = 'true'"!]
[!VAR "AuxiChainUsed" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "AuxiChainUsed" = "num:i(0)"!][!//
[!ENDIF!]


[!VAR "Dsadc_MaxChannels" = "ecu:get('Dsadc.NoOfChannels')"!]
[!VAR "SettingsIndex" = "num:i(0)"!][!//
[!VAR "NoOfSettings" = "num:i(count(DsadcConfigSet/*))"!][!//

[!IF "DsadcGeneral/DsadcInitialConfigEnable = 'true'"!][!//
[!VAR "InitialConfigEnable" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "InitialConfigEnable" = "num:i(0)"!][!//
[!ENDIF!]



[!IF "ecu:get('Dsadc.CommonModeHoldVolExits') = 'true'"!][!//
[!VAR "DsadcCommonModeHold" = "num:i(1)"!][!//
[!ELSE!]
[!VAR "DsadcCommonModeHold" = "num:i(0)"!][!//
[!ENDIF!]

[!FOR "SettingsIndex" = "0" TO "(num:i($NoOfSettings)- 1)"!][!//

[!NOCODE!][!//
/*Code for calculating system clock*/

[!VAR "SPBClockFreq" = "(node:ref(DsadcConfigSet/*[@index = $SettingsIndex]/DsadcSystemClockRef)/McuClockSPBFrequency)"!][!//
[!VAR "ErayClockFreq" = "(node:ref(DsadcConfigSet/*[@index = $SettingsIndex]/DsadcSystemClockRef)/McuClockErayFrequency)"!][!//

[!ENDNOCODE!][!//

[!SELECT "DsadcConfigSet/*[@index = $SettingsIndex]"!][!//

/*     DSADC Channel Configuration    */
static const Dsadc_ChannelConfigType Dsadc_kChannelConfiguration[!"string($SettingsIndex)"!][]=
{
[!AUTOSPACING!]

[!VAR "NoOfChSettings" = "num:i(count(DsadcChannelConfigSet/*))"!][!//
[!VAR "CommonModeHoldReg0Config" = "num:i(0)"!][!//
[!VAR "CommonModeHoldReg1Config" = "num:i(0)"!][!//
[!VAR "CommonModeHoldReg2Config" = "num:i(0)"!][!//

[!FOR "SettingsChIndex" = "0" TO "(num:i($NoOfChSettings)- 1)"!][!//
  {
 
[!VAR "ChannelId" = "num:i(DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcChannelID)"!][!//
[!NOCODE!]
[!IF "$DsadcCommonModeHold = num:i(1)"!]
[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcModulatorConfiguration/DsadcCMHVoltageInputSelect"!][!//

[!IF "$ChannelId = num:i(0)"!]

[!IF "((DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A'))"!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,0))"!][!//
[!VAR "CommonModeHoldReg0Config" = "num:i(1)"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,4))"!][!//
[!ENDIF!]

[!IF "$Dsadc_MaxChannels = num:i(3)"!]

[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B')"!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,1))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,5))"!][!//
[!ENDIF!]

[!ENDIF!]

[!ENDIF!]



[!IF "$ChannelId = num:i(1)"!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A')"!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,8))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,12))"!][!//
[!ENDIF!]
[!ENDIF!]



[!IF "$ChannelId = num:i(2)"!]

[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,16))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,20))"!][!//
[!ENDIF!]

[!IF "$Dsadc_MaxChannels != num:i(3)"!]

[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B')"!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,17))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B')"!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,21))"!][!//
[!ENDIF!]

[!ENDIF!]

[!ENDIF!]




[!IF "$ChannelId = num:i(3)"!]

[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,24))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,28))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,25))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,29))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_C') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,26))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_C') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,30))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_D') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,27))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_D') "!][!//
[!VAR "CommonModeHoldReg0Config" = "bit:or($CommonModeHoldReg0Config,bit:shl(1,31))"!][!//
[!ENDIF!]

[!ENDIF!]



[!IF "$ChannelId = num:i(4)"!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,0))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,4))"!][!//
[!ENDIF!]
[!ENDIF!]




[!IF "$ChannelId = num:i(5)"!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,8))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,12))"!][!//
[!ENDIF!]
[!ENDIF!]


[!IF "$Dsadc_MaxChannels = num:i(10)"!]

[!IF "$ChannelId = num:i(6)"!]

[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,16))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,20))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,17))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,21))"!][!//
[!ENDIF!]

[!ENDIF!]

[!IF "$ChannelId = num:i(7)"!]

[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,24))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,28))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,25))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B') "!][!//
[!VAR "CommonModeHoldReg1Config" = "bit:or($CommonModeHoldReg1Config,bit:shl(1,29))"!][!//
[!ENDIF!]

[!ENDIF!][!//


[!IF "$ChannelId = num:i(8)"!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl(1,0))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl(1,4))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B') "!][!//
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl(1,1))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_B') "!][!//
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl(1,5))"!][!//
[!ENDIF!]
[!ENDIF!]


[!IF "$ChannelId = num:i(9)"!]
[!IF "(DsadcVoltageControlPositiveInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl(1,8))"!][!//
[!ENDIF!]
[!IF "(DsadcVoltageControlNegativeInput = 'true') and (../DsadcInputPinSelection = 'INPUTPIN_A') "!][!//
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl(1,12))"!][!//
[!ENDIF!]
[!ENDIF!]

[!ENDIF!]

[!ENDSELECT!][!// 

[!ENDIF!]  
[!ENDNOCODE!]



[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcModulatorConfiguration"!][!//  	
[!VAR "ModConfig" = "num:i(2155905024)"!][!//
[!IF "DsadcPositiveInputLine = 'INPUT_PIN'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,num:i(0))"!][!//
[!ELSEIF "DsadcPositiveInputLine = 'SUPPLY_VOLTAGE'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,num:i(1))"!][!//
[!ELSEIF "DsadcPositiveInputLine = 'COMMON_MODE_VOLTAGE'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,num:i(2))"!][!//
[!ELSEIF "DsadcPositiveInputLine = 'REFERENCE_GROUND'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,num:i(3))"!][!//
[!ENDIF!]
[!IF "DsadcNegativeInputLine = 'INPUT_PIN'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(0,2))"!][!//
[!ELSEIF "DsadcNegativeInputLine = 'SUPPLY_VOLTAGE'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(1,2))"!][!//
[!ELSEIF "DsadcNegativeInputLine = 'COMMON_MODE_VOLTAGE'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(2,2))"!][!//
[!ELSEIF "DsadcNegativeInputLine = 'REFERENCE_GROUND'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(3,2))"!][!//
[!ENDIF!]
[!IF "DsadcInputPinSelection = 'INPUTPIN_A'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(0,8))"!][!//
[!ELSEIF "DsadcInputPinSelection = 'INPUTPIN_B'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(1,8))"!][!//
[!ELSEIF "DsadcInputPinSelection = 'INPUTPIN_C'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(2,8))"!][!//
[!ELSEIF "DsadcInputPinSelection = 'INPUTPIN_D'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(3,8))"!][!//
[!ENDIF!]
[!IF "DsadcInputGain = 'GAIN_FACTOR1'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(0,4))"!][!//
[!ELSEIF "DsadcInputGain = 'GAIN_FACTOR2'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(1,4))"!][!//
[!ELSEIF "DsadcInputGain = 'GAIN_FACTOR4'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(2,4))"!][!//
[!ELSEIF "DsadcInputGain = 'GAIN_FACTOR8'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(3,4))"!][!//
[!ELSEIF "DsadcInputGain = 'GAIN_FACTOR16'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(4,4))"!][!//
[!ENDIF!]
[!IF "DsadcCommonModeVoltage = 'COMMONMODEVOLTAGE_A'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(0,24))"!][!//
[!ELSEIF "DsadcCommonModeVoltage = 'COMMONMODEVOLTAGE_B'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(1,24))"!][!//
[!ELSEIF "DsadcCommonModeVoltage = 'COMMONMODEVOLTAGE_C'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(2,24))"!][!//
[!ENDIF!]
[!IF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV2'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(0,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV4'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(1,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV6'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(2,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV8'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(3,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV10'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(4,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV12'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(5,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV14'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(6,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV16'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(7,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV18'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(8,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV20'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(9,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV22'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(10,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV24'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(11,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV26'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(12,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV28'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(13,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV30'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(14,16))"!][!//
[!ELSEIF "DsadcDividerFactor = 'CLOCKDIVIDER_DIV32'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(15,16))"!][!//
[!ENDIF!]
[!IF "DsadcInputMuxControlMode = 'SOFTWARE_CONTROL'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(0,12))"!][!//
[!ELSEIF "DsadcInputMuxControlMode = 'TRIGGER_EVENT_FALLING_EDGE'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(1,12))"!][!//
[!ELSEIF "DsadcInputMuxControlMode = 'TRIGGER_EVENT_RISING_EDGE'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(2,12))"!][!//
[!ELSEIF "DsadcInputMuxControlMode = 'TRIGGER_EVENT_ANY_EDGE'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(3,12))"!][!//
[!ENDIF!]
[!IF "DsadcInputMuxActionMode = 'SINGLE_STEP_MODE'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(1,14))"!][!//
[!ENDIF!]
[!IF "DsadcAutomaticPowerControl = 'true'"!][!//
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(1,29))"!][!//
[!ENDIF!]
[!VAR "ModConfig" = "bit:or($ModConfig,bit:shl(1,26))"!][!//
  [!"num:inttohex($ModConfig,8)"!]U, /* Configuration for DSADC register MODCFGx */
[!ENDSELECT!][!// 
[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcDeModulatorConfiguration"!][!//
[!VAR "DeModConfig" = "num:i(2147516544)"!][!//
[!IF "DsadcInputDataSourceSelect = 'ONCHIPSTANDALONE_3RDORDER'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(0,0))"!][!//
[!ELSEIF "DsadcInputDataSourceSelect = 'ONCHIPCOMBINED_2NDORDER'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(1,0))"!][!//
[!ELSEIF "DsadcInputDataSourceSelect = 'EXTERNAL_DIRECTINPUTA'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(2,0))"!][!//
[!ELSEIF "DsadcInputDataSourceSelect = 'EXTERNAL_INVERTEDINPUTA'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(3,0))"!][!//
[!ELSEIF "DsadcInputDataSourceSelect = 'EXTERNAL_DIRECTINPUTB'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(4,0))"!][!//
[!ELSEIF "DsadcInputDataSourceSelect = 'EXTERNAL_INVERTEDINPUTB'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(5,0))"!][!//
[!ELSEIF "DsadcInputDataSourceSelect = 'EXTERNAL_INVERTEDINPUTB'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(5,0))"!][!//
[!ELSEIF "DsadcInputDataSourceSelect = 'ONCHIPCOMBINED_4THORDER'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(8,0))"!][!//
[!ENDIF!]
[!IF "DsadcTriggerSelect = 'TRIGGERINPUT_A'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(0,12))"!][!//
[!ELSEIF "DsadcTriggerSelect = 'TRIGGERINPUT_B'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(1,12))"!][!//
[!ELSEIF "DsadcTriggerSelect = 'TRIGGERINPUT_C'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(2,12))"!][!//
[!ELSEIF "DsadcTriggerSelect = 'TRIGGERINPUT_D'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(3,12))"!][!//
[!ELSEIF "DsadcTriggerSelect = 'TRIGGERINPUT_E'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(4,12))"!][!//
[!ELSEIF "DsadcTriggerSelect = 'TRIGGERINPUT_F'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(5,12))"!][!//
[!ELSEIF "DsadcTriggerSelect = 'TRIGGERINPUT_G'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(6,12))"!][!//
[!ELSEIF "DsadcTriggerSelect = 'TRIGGERINPUT_H'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(7,12))"!][!//
[!ENDIF!]
[!IF "DsadcIntegrationTriggerMode = 'BYPASSED'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(0,8))"!][!//
[!ELSEIF "DsadcIntegrationTriggerMode = 'FALLINGEDGE'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(1,8))"!][!//
[!ELSEIF "DsadcIntegrationTriggerMode = 'RISINGEDGE'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(2,8))"!][!//
[!ELSEIF "DsadcIntegrationTriggerMode = 'ALWAYSACTIVE'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(3,8))"!][!//
[!ENDIF!]
[!IF "DsadcTimestampTriggerMode = 'NOTRIGGER'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(0,10))"!][!//
[!ELSEIF "DsadcTimestampTriggerMode = 'FALLINGEDGE'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(1,10))"!][!//
[!ELSEIF "DsadcTimestampTriggerMode = 'RISINGEDGE'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(2,10))"!][!//
[!ELSEIF "DsadcTimestampTriggerMode = 'EACHEDGE'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(3,10))"!][!//
[!ENDIF!]
[!IF "DsadcSampleClockSourceSelect = 'INTERNAL'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(0,16))"!][!//
[!ELSEIF "DsadcSampleClockSourceSelect = 'INPUTA'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(1,16))"!][!//
[!ELSEIF "DsadcSampleClockSourceSelect = 'INPUTB'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(2,16))"!][!//
[!ELSEIF "DsadcSampleClockSourceSelect = 'INPUTC'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(3,16))"!][!//
[!ENDIF!]
[!IF "DsadcDataStrobeGenerationMode = 'NODATASTROBE'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(0,20))"!][!//
[!ELSEIF "DsadcDataStrobeGenerationMode = 'SAMPLEONRISINGEDGE'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(1,20))"!][!//
[!ELSEIF "DsadcDataStrobeGenerationMode = 'SAMPLEONFALLINGEDGE'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(2,20))"!][!//
[!ELSEIF "DsadcDataStrobeGenerationMode = 'SAMPLEONBOTHEDGES'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(3,20))"!][!//
[!ELSEIF "DsadcDataStrobeGenerationMode = 'SAMPLEONTWORISINGEDGES'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(5,20))"!][!//
[!ELSEIF "DsadcDataStrobeGenerationMode = 'SAMPLEONTWOFALLINGEDGES'"!][!//
[!VAR "DeModConfig" = "bit:or($DeModConfig,bit:shl(6,20))"!][!//
[!ENDIF!]
  [!"num:inttohex($DeModConfig,8)"!]U, /* Configuration for DSADC register DICFGx */
[!ENDSELECT!][!//  
[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcMainCICFilterConfiguration"!][!//  	
[!VAR "MainCICConfig" = "num:i(0)"!][!//
[!IF "DsadcMainCombFilterEnable = 'true'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(1,10))"!][!//
[!ENDIF!]
[!IF "DsadcMainCombFilterType = 'CIC1'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(0,8))"!][!//
[!ELSEIF "DsadcMainCombFilterType = 'CIC2'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(1,8))"!][!//
[!ELSEIF "DsadcMainCombFilterType = 'CIC3'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(2,8))"!][!//
[!ELSEIF "DsadcMainCombFilterType = 'CICF'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(3,8))"!][!//
[!ENDIF!]
[!IF "DsadcMainCombFilterShift = 'NOSHIFT'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(0,12))"!][!//
[!ELSEIF "DsadcMainCombFilterShift = 'SHIFTBY1'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(1,12))"!][!//
[!ELSEIF "DsadcMainCombFilterShift = 'SHIFTBY2'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(2,12))"!][!//
[!ELSEIF "DsadcMainCombFilterShift = 'SHIFTBY3'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(3,12))"!][!//
[!ENDIF!]
[!IF "DsadcServiceRequestMode = 'NEVER'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(0,14))"!][!//
[!ELSEIF "DsadcServiceRequestMode = 'HIGH_GATE_SIGNAL'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(1,14))"!][!//
[!ELSEIF "DsadcServiceRequestMode = 'LOW_GATES_IGNAL'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(2,14))"!][!//
[!ELSEIF "DsadcServiceRequestMode = 'EVERY_NEW_RESULT'"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl(3,14))"!][!//
[!ENDIF!]
[!VAR "CICDF" = "num:i(DsadcDecimationFactor) - 1"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,$CICDF)"!][!//
[!VAR "CICDF" = "num:i(DsadcDecimationStartValue)"!][!//
[!VAR "MainCICConfig" = "bit:or($MainCICConfig,bit:shl($CICDF,16))"!][!//
  [!"num:inttohex($MainCICConfig,8)"!]U, /* Configuration for DSADC register FCFGCx */
[!ENDSELECT!][!//
[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcFIRFilterChainConfiguration"!][!//  	
[!VAR "MainFIRConfig" = "num:i(0)"!][!//
[!IF "DsadcFirFilter0Enabled = 'true'"!][!//
[!VAR "MainFIRConfig" = "bit:or($MainFIRConfig,bit:shl(1,0))"!][!//
[!ENDIF!]
[!IF "DsadcFirInternalShift = 'SHIFTBY1'"!][!//
[!VAR "MainFIRConfig" = "bit:or($MainFIRConfig,bit:shl(1,5))"!][!//
[!ENDIF!]
[!IF "DsadcFirFilter1Enabled = 'true'"!][!//
[!VAR "MainFIRConfig" = "bit:or($MainFIRConfig,bit:shl(1,1))"!][!//
[!ENDIF!]
[!IF "DsadcFirDataShift = 'NOSHIFT'"!][!//
[!VAR "MainFIRConfig" = "bit:or($MainFIRConfig,bit:shl(0,3))"!][!//
[!ELSEIF "DsadcFirDataShift = 'SHIFTBY1'"!][!//
[!VAR "MainFIRConfig" = "bit:or($MainFIRConfig,bit:shl(1,3))"!][!//
[!ELSEIF "DsadcFirDataShift = 'SHIFTBY2'"!][!//
[!VAR "MainFIRConfig" = "bit:or($MainFIRConfig,bit:shl(2,3))"!][!//
[!ELSEIF "DsadcFirDataShift = 'SHIFTBY3'"!][!//
[!VAR "MainFIRConfig" = "bit:or($MainFIRConfig,bit:shl(3,3))"!][!//
[!ENDIF!]
[!IF "DsadcDCOffsetFilterEnabled = 'true'"!][!//
[!VAR "MainFIRConfig" = "bit:or($MainFIRConfig,bit:shl(1,2))"!][!//
[!ENDIF!]
  [!"num:inttohex($MainFIRConfig,8)"!]U, /* Configuration for DSADC register FCFGMx */
[!VAR "Offsetvalue" = "bit:and(num:i(DsadcOffsetValue),65535)"!][!//  
  [!"num:inttohex($Offsetvalue,8)"!]U, /* Configuration for DSADC register OFFMx */  
[!ENDSELECT!][!//
[!IF "$AuxiChainUsed = num:i(1)"!][!//
[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcAuxFilterConfiguration"!][!//  	
[!VAR "AuxCICConfig" = "num:i(0)"!][!//
[!IF "DsadcAuxCombFilterType = 'CIC1'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(0,8))"!][!//
[!ELSEIF "DsadcAuxCombFilterType = 'CIC2'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(1,8))"!][!//
[!ELSEIF "DsadcAuxCombFilterType = 'CIC3'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(2,8))"!][!//
[!ELSEIF "DsadcAuxCombFilterType = 'CICF'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(3,8))"!][!//
[!ENDIF!]
[!IF "DsadcAuxCombFilterShift = 'NOSHIFT'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(0,16))"!][!//
[!ELSEIF "DsadcAuxCombFilterShift = 'SHIFTBY1'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(1,16))"!][!//
[!ELSEIF "DsadcAuxCombFilterShift = 'SHIFTBY2'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(2,16))"!][!//
[!ELSEIF "DsadcAuxCombFilterShift = 'SHIFTBY3'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(3,16))"!][!//
[!ENDIF!]
[!IF "DsadcAuxServiceRequestMode = 'NEVER'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(0,10))"!][!//
[!ELSEIF "DsadcAuxServiceRequestMode = 'AUXILARY_FILTER'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(1,10))"!][!//
[!ELSEIF "DsadcAuxServiceRequestMode = 'ALTERNATE_SOURCE'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(2,10))"!][!//
[!ENDIF!]
[!IF "DsadcAuxEventSelect = 'EVERY_NEW_RESULT'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(0,12))"!][!//
[!ELSEIF "DsadcAuxEventSelect = 'INSIDE_BOUNDARY'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(1,12))"!][!//
[!ELSEIF "DsadcAuxEventSelect = 'OUTSIDE_BOUNDARY'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(2,12))"!][!//
[!ENDIF!]
[!IF "DsadcAuxEventGate = 'COUPLED_TO_INTEGRATOR'"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,bit:shl(1,14))"!][!//
[!ENDIF!]
[!VAR "CICDF" = "num:i(DsadcAuxDecimationFactor) - 1"!][!//
[!VAR "AuxCICConfig" = "bit:or($AuxCICConfig,$CICDF)"!][!//
  [!"num:inttohex($AuxCICConfig,8)"!]U, /* Configuration for DSADC register FCFGAx */ 
[!VAR "Boundaryvalue" = "num:i(0)"!][!// 
[!VAR "Lowvalue" = "bit:and(num:i(DsadcLowerBoundaryValue),65535)"!][!//
[!VAR "Uppvalue" = "bit:and(num:i(DsadcUpperBoundaryValue),65535)"!][!//
[!VAR "Boundaryvalue" = "bit:or($Lowvalue,bit:shl($Uppvalue,16))"!][!//  
  [!"num:inttohex($Boundaryvalue,8)"!]U, /* Configuration for DSADC register BOUNDSELx */ 
[!ENDSELECT!][!//
[!ENDIF!]
[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcRecificationConfiguration"!][!//  
[!VAR "RectConfig" = "num:i(0)"!][!//
[!IF "DsadcRectifierEnabled = 'true'"!][!//
[!VAR "RectConfig" = "bit:or($RectConfig,bit:shl(1,0))"!][!//
[!ENDIF!]
[!IF "DsadcRectifierSignSource = 'ONCHIPGENERATOR'"!][!//
[!VAR "RectConfig" = "bit:or($RectConfig,bit:shl(0,4))"!][!//
[!ELSEIF "DsadcRectifierSignSource = 'NEXTCHANNEL'"!][!//
[!VAR "RectConfig" = "bit:or($RectConfig,bit:shl(1,4))"!][!//
[!ELSEIF "DsadcRectifierSignSource = 'EXTERNALA'"!][!//
[!VAR "RectConfig" = "bit:or($RectConfig,bit:shl(2,4))"!][!//
[!ELSEIF "DsadcRectifierSignSource = 'EXTERNALB'"!][!//
[!VAR "RectConfig" = "bit:or($RectConfig,bit:shl(3,4))"!][!//
[!ENDIF!]
  [!"num:inttohex($RectConfig,8)"!]U, /* Configuration for DSADC register RECTCFGx */ 
[!VAR "SyncConfig" = "bit:or(bit:shl(DsadcSyncNegSignDelayValue,24), bit:shl(DsadcSyncPosSignDelayValue,16))"!][!//
  [!"num:inttohex($SyncConfig,8)"!]U, /* Configuration for DSADC register CGSYNCx */   
[!ENDSELECT!][!//
[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcIntegrationConfiguration"!][!//  	
[!VAR "IntConfig" = "num:i(0)"!][!//
[!IF "DsadcIntegrationWindowSize = 'EXTERNAL_CONTROL'"!][!//
[!VAR "IntConfig" = "bit:or($IntConfig,bit:shl(1,23))"!][!//
[!ENDIF!]
[!VAR "IntConfig" = "bit:or($IntConfig, bit:shl(DsadcDiscardCount,16))"!][!//
[!VAR "IntConfig" = "bit:or($IntConfig, bit:shl(DsadcIntegrationCount,24))"!][!//
[!VAR "IntConfig" = "bit:or($IntConfig, bit:shl(DsadcIntegrationCycleCount,12))"!][!//
  [!"num:inttohex($IntConfig,8)"!]U, /* Configuration for DSADC register IWCTRx */ 
[!ENDSELECT!][!//
[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcTimeStampConfiguration"!][!//
[!VAR "TimeStampConfig" = "num:i(0)"!][!//
[!IF "DsadcTimestampServiceRequest = 'GENERATE_SERVICE_REQUEST'"!][!//
[!VAR "TimeStampConfig" = "bit:or($TimeStampConfig,bit:shl(1,31))"!][!//
[!ENDIF!]
  [!"num:inttohex($TimeStampConfig,8)"!]U, /* Configuration for DSADC register TSTMPx */
[!ENDSELECT!][!// 
[!IF "$InitialConfigEnable = num:i(1)"!]
[!SELECT "DsadcChannelConfigSet/*[@index = $SettingsChIndex]"!][!//
[!IF "DsadcDitheringEnable0 = 'true'"!]
[!VAR "DitherEn0" = "num:i(1)"!][!//
[!ELSE!]
[!VAR "DitherEn0" = "num:i(0)"!][!//
[!ENDIF!]
[!IF "DsadcDitheringEnable1 = 'true'"!]
[!VAR "DitherEn1" = "num:i(1)"!][!//
[!ELSE!]
[!VAR "DitherEn1" = "num:i(0)"!][!//
[!ENDIF!]
[!IF "DsadcIntegratorResetEnable = 'true'"!]
[!VAR "IntegratorResetEn" = "num:i(1)"!][!//
[!ELSE!]
[!VAR "IntegratorResetEn" = "num:i(0)"!][!//
[!ENDIF!]
[!VAR "InitialChannelConfig" = "num:i(0)"!][!//
[!VAR "InitialChannelConfig0" = "bit:or(bit:shl(num:i(1),31),$DitherEn0)"!]
[!VAR "InitialChannelConfig1" = "bit:or(bit:shl($DitherEn1,1),bit:shl($IntegratorResetEn,4))"!]
[!VAR "InitialChannelConfig" = "bit:or($InitialChannelConfig0,$InitialChannelConfig1)"!]
  [!"num:inttohex($InitialChannelConfig,8)"!]U, /* Configuration for DSADC register ICCFGx */
[!ENDSELECT!][!// 
[!ENDIF!]
  [!"num:inttohex(DsadcChannelConfigSet/*[@index = $SettingsChIndex]/DsadcChannelID,2)"!]U, /* Configuration for ChannelID */  
  }[!IF "$SettingsChIndex != $NoOfChSettings -1"!],[!ENDIF!][!//
  
[!ENDFOR!]
[!AUTOSPACING!]
[!ENDSELECT!][!//
};
[!ENDFOR!]
[!ENDSELECT!][!//


/*
        Container: DSADC Config Root
        Multilplicity : 1 - *
*/
const Dsadc_ConfigType Dsadc_ConfigRoot[]=
{
[!SELECT "as:modconf('Dsadc')[1]"!][!//
[!VAR "SettingsIndex" = "num:i(0)"!][!//
[!VAR "NoOfSettings" = "num:i(count(DsadcConfigSet/*))"!][!//
[!FOR "SettingsIndex" = "0" TO "(num:i($NoOfSettings)- 1)"!][!//
[!SELECT "DsadcConfigSet/*[@index = $SettingsIndex]"!][!//
{
[!AUTOSPACING!]
  /* Configuration Set [!"$SettingsIndex"!] for DSADC */
[!VAR "ClkConfig" = "num:i(8388608)"!][!//
[!IF "DsadcClockConfiguration/DsadcPowerSupply = 'LOWPOWERSUPPLY_3_3V'"!][!//
[!VAR "ClkConfig" = "bit:or($ClkConfig,bit:shl(1,20))"!][!//
[!ENDIF!] 
[!IF "DsadcClockConfiguration/DsadcClockSource = 'CLOCK_OFF'"!][!//
[!VAR "ClkConfig" = "bit:or($ClkConfig,num:i(0))"!][!//
[!VAR "SourceClk" = "num:f(0)"!][!//
[!ELSEIF "DsadcClockConfiguration/DsadcClockSource = 'CLOCK_FDSD'"!][!//
[!VAR "ClkConfig" = "bit:or($ClkConfig,num:i(1))"!][!//
[!VAR "SourceClk" = "num:f($SPBClockFreq)"!][!//
[!ELSEIF "DsadcClockConfiguration/DsadcClockSource = 'CLOCK_FERAY'"!][!//
[!VAR "ClkConfig" = "bit:or($ClkConfig,num:i(2))"!][!//
[!VAR "SourceClk" = "num:f($ErayClockFreq)"!][!//
[!ELSEIF "DsadcClockConfiguration/DsadcClockSource = 'CLOCK_FOSC0'"!][!//
[!VAR "ClkConfig" = "bit:or($ClkConfig,num:i(3))"!][!//
[!VAR "SourceClk" = "num:f($McuOscillatorClk)"!][!//
[!ENDIF!] 
[!IF "$DsadcCommonModeHold = num:i(1)"!]
[!IF "DsadcCMHVoltage/DsadcCMHVoltageEnableAlways = 'true'"!][!//
[!VAR "CMHVolEnAlways" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "CMHVolEnAlways" = "num:i(0)"!][!//
[!ENDIF!]
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl($CMHVolEnAlways,29))"!][!//
[!IF "DsadcCMHVoltage/DsadcCMHVoltageSelect = 'CMHVOLTAGE_A'"!][!//
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl(0,30))"!][!//
[!ELSEIF "DsadcCMHVoltage/DsadcCMHVoltageSelect = 'CMHVOLTAGE_B'"!][!//
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl(1,30))"!][!//
[!ELSEIF "DsadcCMHVoltage/DsadcCMHVoltageSelect = 'CMHVOLTAGE_C'"!][!//
[!VAR "CommonModeHoldReg2Config" = "bit:or($CommonModeHoldReg2Config,bit:shl(2,30))"!][!//
[!ENDIF!]
[!ENDIF!]
[!IF "$InitialConfigEnable = num:i(1)"!]
[!VAR "InitialGlobalConfig" = "num:i(0)"!][!//
[!IF "DsadcTrimmingValue > num:i(0)"!][!//
[!VAR "InitialGlobalConfig" = "bit:or(DsadcTrimmingValue,bit:shl(1,31))"!]
[!ELSE!][!//
[!VAR "InitialGlobalConfig" = "bit:or(num:i(0),bit:shl(1,31))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!VAR "SleepMode" = "num:i(0)"!][!//
[!IF "DsadcClockConfiguration/DsadcSleepMode = 'SLEEP_DISABLE'"!][!//
[!VAR "SleepMode" = "num:i('1')"!][!//
[!ENDIF!] 
[!VAR "CGConfig" = "num:i(0)"!][!//
[!IF "DsadcCarrierGenConfiguration/DsadcCarrierWaveformMode = 'STOPPED'"!][!//
[!VAR "CGConfig" = "bit:or($CGConfig,num:i(0))"!][!//
[!ELSEIF "DsadcCarrierGenConfiguration/DsadcCarrierWaveformMode = 'WAVEFORMMODE_SQUARE'"!][!//
[!VAR "CGConfig" = "bit:or($CGConfig,num:i(1))"!][!//
[!ELSEIF "DsadcCarrierGenConfiguration/DsadcCarrierWaveformMode = 'WAVEFORMMODE_TRIANGLE'"!][!//
[!VAR "CGConfig" = "bit:or($CGConfig,num:i(2))"!][!//
[!ELSEIF "DsadcCarrierGenConfiguration/DsadcCarrierWaveformMode = 'WAVEFORMMODE_SINE'"!][!//
[!VAR "CGConfig" = "bit:or($CGConfig,num:i(3))"!][!//
[!ENDIF!]
[!IF "DsadcCarrierGenConfiguration/DsadcBitReversePWM = 'BIT_REVERSE_MODE'"!][!//
[!VAR "CGConfig" = "bit:or($CGConfig,bit:shl(1,2))"!][!//
[!ENDIF!]
[!IF "DsadcCarrierGenConfiguration/DsadcCarrierSignalPolarity = 'INVERTED'"!][!//
[!VAR "CGConfig" = "bit:or($CGConfig,bit:shl(1,3))"!][!//
[!ENDIF!]
[!VAR "CGdiv" = "num:i(0)"!][!//
[!VAR "CGdiv" = "bit:shl(num:i(DsadcCarrierGenConfiguration/DsadcCGDividerFactor),4)"!][!//
[!VAR "CGConfig" = "bit:or($CGConfig,$CGdiv)"!][!//
  [!"num:f($SourceClk)"!]f,
  [!"num:inttohex($ClkConfig,8)"!]U, /* Configuration for DSADC register GLOBCFG */
  [!IF "$InitialConfigEnable = num:i(1)"!]
  [!"num:inttohex($InitialGlobalConfig,8)"!]U, /* DSADC register IGCFG */
  [!ENDIF!]
  [!"num:inttohex($CGConfig,8)"!]U, /* Configuration for DSADC register CGCFG */ 
  
[!IF "$DsadcCommonModeHold = num:i(1)"!]
{
  [!"num:inttohex($CommonModeHoldReg0Config,8)"!]U, /* Configuration for DSADC register GLOBVCMH0 */
  [!IF "$DsadcMaxCMHVRegs != num:i(2)"!]
  [!"num:inttohex($CommonModeHoldReg1Config,8)"!]U, /* Configuration for DSADC register GLOBVCMH1 */
  [!ENDIF!]
  [!"num:inttohex($CommonModeHoldReg2Config,8)"!]U /* Configuration for DSADC register GLOBVCMH2 */
  
},
[!ENDIF!]

  
  [!"num:inttohex($SleepMode,2)"!]U, /* Configuration for DSADC register CLC */
  {
[!VAR "NoOfChSettings" = "num:i(count(DsadcChannelConfigSet/*))"!][!//	
[!FOR "SettingsChIndex" = "0" TO "(num:i(ecu:get('Dsadc.NoOfChannels'))- 1)"!][!//
    [!IF "$NoOfChSettings > $SettingsChIndex"!]
    [!"'&Dsadc_kChannelConfiguration'"!][!"string($SettingsIndex)"!][!"'['"!][!"string($SettingsChIndex)"!][!"'],'"!][!//
    [!ELSE!][!//
    [!"'NULL_PTR'"!],[!//
    [!ENDIF!][!//
      	 
[!ENDFOR!]
  }
}[!IF "$SettingsIndex != $NoOfSettings -1"!],[!ENDIF!]

[!AUTOSPACING!]
[!ENDSELECT!][!//
[!ENDFOR!]
};
[!ENDSELECT!][!//

#define DSADC_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS= Memmap file included as per AUTOSAR*/
#include "MemMap.h"



