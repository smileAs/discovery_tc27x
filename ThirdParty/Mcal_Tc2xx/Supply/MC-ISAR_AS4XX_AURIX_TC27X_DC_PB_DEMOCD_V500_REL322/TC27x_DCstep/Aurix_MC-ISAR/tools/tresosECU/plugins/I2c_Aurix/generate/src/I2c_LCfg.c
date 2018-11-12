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
**  $FILENAME   : I2c_LCfg.c $                                               **
**                                                                            **
**  $CC VERSION : \main\4 $                                                  **
**                                                                            **
**  $DATE       : 2014-11-14 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                Code template for I2c_LCfg.c file                           **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*************************************************************************/!][!//
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
**  FILENAME  : I2c_LCfg.c                                                    **
**                                                                            **
**  $CC VERSION : \main\4 $                                                  **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : I2C configuration generated out of ECU configuration       **
**                 file (I2c.bmd/.xdm)                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEBILITY :                                                             **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
[!AUTOSPACING!]
#include "I2c.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
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
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define I2C_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* IFX_MISRA_RULE_08_10_STATUS=Variable 
   I2c_NotifFunctionPtrType is declared as extern in I2c.h, 
   which will be included application for debugging */
[!VAR "I2cPacketName" = "'I2cPacket'"!]

[!SELECT "I2cDriver/*[num:i(1)]"!][!//
[!VAR "TotalPackets" = "num:i(count(node:ref($I2cPacketName)/*))"!]
const I2c_NotifFunctionPtrType I2c_NotifFunctionPtrArray[[!"num:i($TotalPackets)"!]] =
{
  [!FOR "Packet" = "0" TO "num:i($TotalPackets)"!]
  [!SELECT "I2cPacket/*[num:i($Packet)]"!]
  [!IF "I2cPacketEndNotification = 'NULL_PTR'"!]
  NULL_PTR,
  [!ELSE!]
  &[!"I2cPacketEndNotification"!],
  [!ENDIF!]
  [!ENDSELECT!]
  [!ENDFOR!]
};
[!ENDSELECT!]

#define I2C_STOP_SEC_POSTBUILDCFG
/* IFX_MISRA_RULE_19_01_STATUS= Memmap file included as per AUTOSAR */
#include "MemMap.h"
