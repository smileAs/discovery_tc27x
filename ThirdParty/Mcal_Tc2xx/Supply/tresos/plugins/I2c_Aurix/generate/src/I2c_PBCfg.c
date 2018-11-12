[!/*****************************************************************************
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
**  FILENAME    : I2c_PBCfg.c $                                               **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  $DATE       : 2016-07-22 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                Code template for I2c_PBCfg.c file                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/!][!//
[!//
/*******************************************************************************
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
**  FILENAME  : I2c_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : I2c configuration generated out of ECU configuration       **
**                 file(I2c.bmd/.xdm)                                         **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEBILITY :                                                             **
**                                                                            **
*******************************************************************************/
[!AUTOSPACING!]
[!//
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!]
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!]
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!]
[!//
[!VAR "I2cDriverName" = "'I2cDriver'"!]
[!VAR "I2cPacketName" = "'I2cPacket'"!]
[!VAR "I2cDeviceAssignmentName" = "'I2cDeviceAssignment'"!]
[!VAR "I2cExternalDeviceName" = "'I2cExternalDevice'"!]
[!//
[!SELECT "as:modconf('I2c')[1]"!]
  [!VAR "TotalConfig" = "num:i(count(node:ref($I2cDriverName)/*))"!]
[!ENDSELECT!]
[!//
[!//
[!/*
Get No of Packets Configured
*/!][!//
[!SELECT "as:modconf('I2c')[1]"!]
  [!VAR "MaxTotalPackets" = "num:i(0)"!]
  [!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!]
    [!SELECT "node:ref($I2cDriverName)/*[@index = num:i($ModuleId - 1)]"!]
      [!VAR "TotalPackets" = "num:i(count(node:ref($I2cPacketName)/*))"!]
      [!IF "$TotalPackets > $MaxTotalPackets"!]
        [!VAR "MaxTotalPackets" = "$TotalPackets"!]
      [!ENDIF!]
    [!ENDSELECT!]
  [!ENDFOR!]
[!ENDSELECT!]
[!//
[!// Get No of packets with HwUnit0
[!VAR "TotalPackets_HwUnit0" = "num:i(0)"!]
[!VAR "TotalPackets_HwUnit1" = "num:i(0)"!]
[!//
[!SELECT "as:modconf('I2c')[1]"!]
  [!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!]
    [!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($I2cDriverName)/*)) - num:i(1)"!]
      [!SELECT "node:ref($I2cDriverName)/*[@index =$Index]"!]
        [!FOR "Index2" = "num:i(0)" TO "num:i(count(node:ref($I2cPacketName)/*)) - num:i(1)"!]
          [!SELECT "node:ref($I2cPacketName)/*[@index = $Index2]"!]
            [!VAR "DeviceNumber" = "text:split($I2cDeviceAssignmentName, '_')[position()-1 = 2]"!]
            [!//#define Test_DeviceNumber  ([!"($DeviceNumber)"!])
          [!ENDSELECT!]
          [!SELECT "node:ref($I2cExternalDeviceName)/*[@index = 0]"!]
            [!VAR "HwUnitNumber" = "text:split(I2cPortSelect, '_')[position()-1 = 2]"!]
            [!//#define Test_HwUnitNumber  ([!"($HwUnitNumber)"!])
            [!IF "$HwUnitNumber = num:i(0)"!]
              [!VAR "TotalPackets_HwUnit0" = "$TotalPackets_HwUnit0 + 1"!]
            [!ENDIF!]
            [!IF "$HwUnitNumber = 1"!]
              [!VAR "TotalPackets_HwUnit1" = "$TotalPackets_HwUnit1 + 1"!]
            [!ENDIF!]
          [!ENDSELECT!]
        [!ENDFOR!]
      [!ENDSELECT!]
    [!ENDFOR!]
  [!ENDFOR!]
[!ENDSELECT!]
[!//
[!//#define Test_HwUnitPackets_0  ([!"num:i($TotalPackets_HwUnit0)"!])
[!//#define Test_HwUnitPackets_1  ([!"num:i($TotalPackets_HwUnit1)"!])
[!//
[!VAR "QueueIndex_HwUnit_Tracker" = "num:i(0)"!]
[!IF "node:exists(I2cHwConfiguration/*[1]) = 'true'"!]
  [!IF "I2cHwConfiguration/*[1]/I2cCommunicationType = 'SYNCHRONOUS'"!]
    [!VAR "QueueIndex_HwUnit0" = "num:i(255)"!]
  [!ELSE!]
    [!VAR "QueueIndex_HwUnit0" = "$QueueIndex_HwUnit_Tracker"!]
    [!VAR "QueueIndex_HwUnit_Tracker" = "$QueueIndex_HwUnit_Tracker + 1"!]
  [!ENDIF!]
[!ENDIF!]
[!IF "node:exists(I2cHwConfiguration/*[2]) = 'true'"!]
  [!IF "I2cHwConfiguration/*[2]/I2cCommunicationType = 'SYNCHRONOUS'"!]
    [!VAR "QueueIndex_HwUnit1" = "num:i(255)"!]
  [!ELSE!]
    [!VAR "QueueIndex_HwUnit1" = "$QueueIndex_HwUnit_Tracker"!]
    [!VAR "QueueIndex_HwUnit_Tracker" = "$QueueIndex_HwUnit_Tracker + 1"!]
  [!ENDIF!]
[!ENDIF!]
[!//
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include I2C Module File */
#include "I2c.h"
/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define I2C_START_SEC_POSTBUILDCFG
#include "MemMap.h"

[!SELECT "as:modconf('I2c')[1]"!]
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($I2cDriverName)/*)) - num:i(1)"!]
static const I2c_PacketConfigType I2c_kPacketConfig[!"string(($Index))"!][] =
{
  [!SELECT "node:ref($I2cDriverName)/*[@index = $Index]"!]
  [!LOOP "node:ref($I2cPacketName)/*"!]
  {
    /* Address */
    [!"num:inttohex(num:i(I2cPacketAddress ))"!]U,
    [!//
    [!//

    /* Length */
    [!"num:inttohex(num:i(I2cPacketLength ))"!]U,
    [!//
    [!//

    [!VAR "ExterDevPath" = "node:path(node:ref(node:ref($I2cDeviceAssignmentName)))"!]
    [!VAR "PortSelect" = "node:value(node:ref(concat($ExterDevPath, '/I2cPortSelect')))"!]
    [!VAR "HwUnitNumber" = "text:split($PortSelect, '_')[position()-1 = 2]"!]
    /* HwUnit */
    [!"num:inttohex(num:i($HwUnitNumber ))"!]U,
    [!//
    [!//

	/* ExternalDeviceAddress */
    [!VAR "ExternalDeviceAddress" = "node:value(node:ref(concat($ExterDevPath, '/I2cExternalDeviceAddress')))"!]
    [!"num:inttohex(num:i($ExternalDeviceAddress))"!]U,
    [!//
    [!//

    [!VAR "AdrValue" = "num:i(0)"!]
    [!VAR "AdddressCfgValue_Adr" = "$AdrValue"!]
    [!//
    [!VAR "TBAM_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cAddressingMode')))"!]
    [!VAR "TBAM_Value" = "num:i(0)"!]
    [!IF "$TBAM_Cfg = 'ADDRESSING_MODE_7_BIT' "!]
      [!VAR "TBAM_Value" = "num:i(0)"!]
    [!ENDIF!]
    [!VAR "AdddressCfgValue_TBAM" = "bit:shl( $TBAM_Value, 16)"!]
    [!//
    [!VAR "GCE_Value" = "num:i(0)"!]
    [!VAR "AdddressCfgValue_GCE" = "bit:shl( $GCE_Value, 17)"!]
    [!//
    [!VAR "MCE_Value" = "num:i(0)"!]
    [!VAR "AdddressCfgValue_MCE" = "bit:shl( $MCE_Value, 18)"!]
    [!//
    [!VAR "MnS_Value" = "num:i(1)"!]
    [!VAR "AdddressCfgValue_MnS" = "bit:shl( $MnS_Value, 19)"!]
    [!//
    [!VAR "SONA_Value" = "num:i(1)"!]
    [!VAR "AdddressCfgValue_SONA" = "bit:shl( $SONA_Value, 20)"!]
    [!//
    [!VAR "SOPE_Value" = "num:i(1)"!]
    [!VAR "AdddressCfgValue_SOPE" = "bit:shl( $SOPE_Value, 21)"!]
    [!//
    [!VAR "AdddressCfgValue" = "num:inttohex(num:i(0))"!]
    [!VAR "AdddressCfgValue" = "bit:or($AdddressCfgValue, $AdddressCfgValue_Adr)"!]
    [!VAR "AdddressCfgValue" = "bit:or($AdddressCfgValue, $AdddressCfgValue_TBAM)"!]
    [!VAR "AdddressCfgValue" = "bit:or($AdddressCfgValue, $AdddressCfgValue_GCE)"!]
    [!VAR "AdddressCfgValue" = "bit:or($AdddressCfgValue, $AdddressCfgValue_MCE)"!]
    [!VAR "AdddressCfgValue" = "bit:or($AdddressCfgValue, $AdddressCfgValue_MnS)"!]
    [!VAR "AdddressCfgValue" = "bit:or($AdddressCfgValue, $AdddressCfgValue_SONA)"!]
    [!VAR "AdddressCfgValue" = "bit:or($AdddressCfgValue, $AdddressCfgValue_SOPE)"!]
    [!//
    /* AdddressCfgValue */
    [!"num:inttohex(num:i($AdddressCfgValue ))"!]U,
    [!//
    [!//

    [!VAR "DEC_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cFractionalDividerDec')))"!]
    [!VAR "DEC_Value" = "$DEC_Cfg"!]
    [!VAR "FracDividerCfgValue_DEC" = "$DEC_Value"!]
    [!//
    [!VAR "INC_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cFractionalDividerInc')))"!]
    [!VAR "INC_Value" = "$INC_Cfg"!]
    [!VAR "FracDividerCfgValue_INC" = "bit:shl($INC_Value, 16)"!]
    [!//
    [!VAR "FracDividerCfgValue" = "num:inttohex(num:i(0))"!]
    [!VAR "FracDividerCfgValue" = "bit:or($FracDividerCfgValue, $FracDividerCfgValue_DEC)"!]
    [!VAR "FracDividerCfgValue" = "bit:or($FracDividerCfgValue, $FracDividerCfgValue_INC)"!]
    [!//
    /* FracDividerCfgValue */
    [!"num:inttohex(num:i($FracDividerCfgValue))"!]U,
    [!//
    [!//

    [!VAR "SDA_DEL_HD_DAT_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cSdaDelayStageDataHoldTime')))"!]
    [!VAR "SDA_DEL_HD_DAT_Value" = "$SDA_DEL_HD_DAT_Cfg"!]
    [!VAR "TimingCfgvalue_SDA_DEL_HD_DAT" = "$SDA_DEL_HD_DAT_Value"!]
    [!//
    [!VAR "HS_SDA_DEL_HD_DAT_Value" = "num:i(0)"!]
    [!VAR "TimingCfgvalue_HS_SDA_DEL_HD_DAT" = "bit:shl( $HS_SDA_DEL_HD_DAT_Value, 6)"!]
    [!//
    [!VAR "SCL_DEL_HD_STA_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cSclDelayStageHoldTimeStartBit')))"!]
    [!VAR "SCL_DEL_HD_STA_Value" = "$SCL_DEL_HD_STA_Cfg"!]
    [!VAR "TimingCfgvalue_SCL_DEL_HD_STA" = "bit:shl( $SCL_DEL_HD_STA_Value, 9)"!]
    [!//
    [!VAR "EN_SCL_LOW_LEN_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cEnCfgFastModeSclLowLength')))"!]
    [!VAR "EN_SCL_LOW_LEN_Value" = "num:i(0)"!]
    [!IF "$EN_SCL_LOW_LEN_Cfg = 'true' "!]
      [!VAR "EN_SCL_LOW_LEN_Value" = "num:i(1)"!]
    [!ELSE!]
      [!VAR "EN_SCL_LOW_LEN_Value" = "num:i(0)"!]
    [!ENDIF!]
    [!VAR "TimingCfgvalue_EN_SCL_LOW_LEN" = "bit:shl($EN_SCL_LOW_LEN_Value, 14)"!]
    [!//
    [!VAR "FS_SCL_LOW_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cSetFastModeSclLowPerTime')))"!]
    [!VAR "FS_SCL_LOW_Value" = "num:i(0)"!]
    [!IF "$FS_SCL_LOW_Cfg = 'true' "!]
      [!VAR "FS_SCL_LOW_Value" = "num:i(1)"!]
    [!ELSE!]
      [!VAR "FS_SCL_LOW_Value" = "num:i(0)"!]
    [!ENDIF!]
    [!VAR "TimingCfgvalue_FS_SCL_LOW" = "bit:shl( $FS_SCL_LOW_Value, 15)"!]
    [!//
    [!VAR "HS_SDA_DEL_Value" = "num:i(0)"!]
    [!VAR "TimingCfgvalue_HS_SDA_DEL" = "bit:shl( $HS_SDA_DEL_Value, 16)"!]
    [!//
    [!VAR "SCL_LOW_LEN_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cFastModeSclLowLength')))"!]
    [!VAR "SCL_LOW_LEN_Value" = "$SCL_LOW_LEN_Cfg"!]
    [!VAR "TimingCfgvalue_SCL_LOW_LEN" = "bit:shl( $SCL_LOW_LEN_Value, 21)"!]
    [!//
    [!VAR "TimingCfgvalue" = "num:inttohex(num:i(0))"!]
    [!VAR "TimingCfgvalue" = "bit:or($TimingCfgvalue, $TimingCfgvalue_SDA_DEL_HD_DAT)"!]
    [!VAR "TimingCfgvalue" = "bit:or($TimingCfgvalue, $TimingCfgvalue_HS_SDA_DEL_HD_DAT)"!]
    [!VAR "TimingCfgvalue" = "bit:or($TimingCfgvalue, $TimingCfgvalue_SCL_DEL_HD_STA)"!]
    [!VAR "TimingCfgvalue" = "bit:or($TimingCfgvalue, $TimingCfgvalue_EN_SCL_LOW_LEN)"!]
    [!VAR "TimingCfgvalue" = "bit:or($TimingCfgvalue, $TimingCfgvalue_FS_SCL_LOW)"!]
    [!VAR "TimingCfgvalue" = "bit:or($TimingCfgvalue, $TimingCfgvalue_HS_SDA_DEL)"!]
    [!VAR "TimingCfgvalue" = "bit:or($TimingCfgvalue, $TimingCfgvalue_SCL_LOW_LEN)"!]
    [!//
    /* TimingCfgvalue */
    [!"num:inttohex(num:i($TimingCfgvalue ))"!]U,
    [!//
    [!//

    [!VAR "RXBS_Value" = "num:i(3)"!]
    [!VAR "FIFOCfgValue_RXBS" = "$RXBS_Value"!]
    [!//
    [!VAR "TXBS_Value" = "num:i(3)"!]
    [!VAR "FIFOCfgValue_TXBS" = "bit:shl($TXBS_Value, 4)"!]
    [!//
    [!VAR "RXFA_Value" = "num:i(2)"!]
    [!VAR "FIFOCfgValue_RXFA" = "bit:shl($RXFA_Value, 8)"!]
    [!//
    [!VAR "TXFA_Value" = "num:i(2)"!]
    [!VAR "FIFOCfgValue_TXFA" = "bit:shl($TXFA_Value, 12)"!]
    [!//
    [!VAR "RXFC_Value" = "num:i(1)"!]
    [!VAR "FIFOCfgValue_RXFC" = "bit:shl($RXFC_Value, 16)"!]
    [!//
    [!VAR "TXFC_Value" = "num:i(1)"!]
    [!VAR "FIFOCfgValue_TXFC" = "bit:shl($TXFC_Value, 17)"!]
    [!//
    [!VAR "FIFOCfgValue" = "num:inttohex(num:i(0))"!]
    [!VAR "FIFOCfgValue" = "bit:or($FIFOCfgValue, $FIFOCfgValue_RXBS)"!]
    [!VAR "FIFOCfgValue" = "bit:or($FIFOCfgValue, $FIFOCfgValue_TXBS)"!]
    [!VAR "FIFOCfgValue" = "bit:or($FIFOCfgValue, $FIFOCfgValue_RXFA)"!]
    [!VAR "FIFOCfgValue" = "bit:or($FIFOCfgValue, $FIFOCfgValue_TXFA)"!]
    [!VAR "FIFOCfgValue" = "bit:or($FIFOCfgValue, $FIFOCfgValue_RXFC)"!]
    [!VAR "FIFOCfgValue" = "bit:or($FIFOCfgValue, $FIFOCfgValue_TXFC)"!]
    [!//
    /* FIFOCfgValue */
    [!"num:inttohex(num:i($FIFOCfgValue))"!]U,
    [!//
    [!//

    [!VAR "PortPinID" = "text:split($PortSelect, '_')[position()-1 = 3]"!]
    [!VAR "PISEL_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cFractionalDividerDec')))"!]
    [!IF "$PortPinID = 'A'"!]
      [!VAR "PISEL_Value" = "num:i(0)"!]
    [!ELSEIF "$PortPinID = 'B'"!]
      [!VAR "PISEL_Value" = "num:i(0)"!]
    [!ELSEIF "$PortPinID = 'C'"!]
      [!VAR "PISEL_Value" = "num:i(2)"!]
    [!ELSEIF "$PortPinID = 'D'"!]
      [!VAR "PISEL_Value" = "num:i(3)"!]
    [!ELSEIF "$PortPinID = 'E'"!]
      [!VAR "PISEL_Value" = "num:i(4)"!]
    [!ELSEIF "$PortPinID = 'F'"!]
      [!VAR "PISEL_Value" = "num:i(5)"!]
    [!ELSEIF "$PortPinID = 'G'"!]
      [!VAR "PISEL_Value" = "num:i(6)"!]
    [!ELSEIF "$PortPinID = 'H'"!]
      [!VAR "PISEL_Value" = "num:i(7)"!]
    [!ENDIF!]
    [!VAR "PortPinCfgvalue_PISEL" = "$PISEL_Value"!]
    [!//
    [!VAR "PortPinCfgvalue" = "num:inttohex(num:i(0))"!]
    [!VAR "PortPinCfgvalue" = "bit:or($PortPinCfgvalue, $PortPinCfgvalue_PISEL)"!]
    [!//
    /* PortPinCfgvalue */
    [!"num:inttohex(num:i($PortPinCfgvalue))"!]U,
    [!//
    [!//
  },
  [!ENDLOOP!]
  [!ENDSELECT!]
};
[!ENDFOR!]
[!ENDSELECT!]



[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($I2cDriverName)/*)) - num:i(1)"!]
static const I2c_HWModuleConfigType I2c_kModuleConfig[!"string(($Index))"!][]=
{
  [!IF "node:exists(I2cHwConfiguration/*[1]) = 'true'"!]
  /* I2C0 Module */
  {
	[!VAR "I2cSleepEnable" = "node:value(I2cHwConfiguration/*[1]/I2cSleepEnable)"!]
    [!IF "$I2cSleepEnable = 'false'"!]
	[!VAR "EDIS_Cfg" = "1"!]
    [!VAR "EDIS_Value" = "$EDIS_Cfg"!]
    [!VAR "HWClkSetting_EDIS" = "bit:shl($EDIS_Value,3)"!]
	[!ENDIF!]
    [!//
	[!VAR "RMC_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cRmc')))"!]
    [!VAR "RMC_Value" = "$RMC_Cfg"!]
    [!VAR "HWClkSetting_RMC" = "bit:shl($RMC_Value, 8)"!]
    [!//
    [!VAR "HWClkSetting" = "num:inttohex(num:i(0))"!]
	[!IF "$I2cSleepEnable = 'false'"!]
	[!VAR "HWClkSetting" = "bit:or($HWClkSetting, $HWClkSetting_EDIS)"!]
    [!ENDIF!]
    [!VAR "HWClkSetting" = "bit:or($HWClkSetting, $HWClkSetting_RMC)"!]
    [!//
    [!"num:inttohex(num:i($HWClkSetting))"!]U,
    [!//
    [!//
  },
  [!ENDIF!]
  [!IF "node:exists(I2cHwConfiguration/*[2]) = 'true'"!]
  /* I2C1 Module */
  {
	[!VAR "I2cSleepEnable" = "node:value(I2cHwConfiguration/*[2]/I2cSleepEnable)"!]
    [!IF "$I2cSleepEnable = 'false'"!]
	[!VAR "EDIS_Cfg" = "1"!]
    [!VAR "EDIS_Value" = "$EDIS_Cfg"!]
    [!VAR "HWClkSetting_EDIS" = "bit:shl($EDIS_Value,3)"!]
	[!ENDIF!]
    [!//
	[!VAR "RMC_Cfg" = "node:value(node:ref(concat($ExterDevPath, '/I2cRmc')))"!]
    [!VAR "RMC_Value" = "$RMC_Cfg"!]
    [!VAR "HWClkSetting_RMC" = "bit:shl($RMC_Value, 8)"!]
    [!//
    [!VAR "HWClkSetting" = "num:inttohex(num:i(0))"!]
	[!IF "$I2cSleepEnable = 'false'"!]
	[!VAR "HWClkSetting" = "bit:or($HWClkSetting, $HWClkSetting_EDIS)"!]
    [!ENDIF!]
    [!VAR "HWClkSetting" = "bit:or($HWClkSetting, $HWClkSetting_RMC)"!]
    [!//
    [!"num:inttohex(num:i($HWClkSetting))"!]U,
    [!//
    [!//
  },
  [!ENDIF!]
};
[!ENDFOR!]

const I2c_ConfigType I2c_ConfigRoot[[!"string(num:i($TotalConfig))"!]] =
{
  [!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!]
  [!/* Select MODULE-CONFIGURATION as context-node */!][!//
  [!SELECT "as:modconf('I2c')[1]"!]
  [!//
  {
    &I2c_kPacketConfig[!"string(($ModuleId)-num:i(1))"!][0],

    &I2c_kModuleConfig[!"string(($ModuleId)-num:i(1))"!][0],

    {
      [!IF "node:exists(I2cHwConfiguration/*[1]) = 'true'"!]
      [!"num:inttohex(num:i(0 ))"!]U,
      [!ENDIF!]
      [!IF "node:exists(I2cHwConfiguration/*[2]) = 'true'"!]
      [!"num:inttohex(num:i($TotalPackets_HwUnit1 ))"!]U,
      [!ENDIF!]
    },
    {
      [!IF "node:exists(I2cHwConfiguration/*[1]) = 'true'"!]
      [!"num:inttohex(num:i($QueueIndex_HwUnit0))"!]U,
      [!ENDIF!]
      [!IF "node:exists(I2cHwConfiguration/*[2]) = 'true'"!]
      [!"num:inttohex(num:i($QueueIndex_HwUnit1))"!]U,
      [!ENDIF!]
    },
    (I2c_PacketType)(sizeof(I2c_kPacketConfig[!"string(($ModuleId)-num:i(1))"!]) / sizeof(I2c_PacketConfigType)),
  }
  [!//
  [!IF "$ModuleId != $TotalConfig"!],[!ENDIF!][!//
  [!ENDSELECT!]
  [!ENDFOR!]
};

#define I2C_STOP_SEC_POSTBUILDCFG
/* IFX_MISRA_RULE_19_01_STATUS= Memmap file included as per AUTOSAR */
#include "MemMap.h"



