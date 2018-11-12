/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  IomTst_LCfg.c                                                **
**                                                                            **
**  VERSION   : 0.0.2                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Iom.bmd/xdm                                       **
**                                                                            **
**  VARIANT   : VariantLinkTime                                                    **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : IomTst configuration generated out of ECU configuration    **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "IomTst.h"

#define IFX_IOMTST_START_SEC_LINKTIMECFG_ASIL_B
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
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('IomTst')[1]"!][!//
[!//
[!VAR "TotalConfig" = "num:i(count(IomTstConfigSet/*))"!][!//
[!VAR "TotalLamBlocks" = "num:i(count(IomTstConfigSet/*[num:i(1)]/IomTstLamBlock/*))"!][!//

/* IOM Module Configuration */
const IomTst_ConfigType IomTst_ConfigRoot[IOMTST_CFG_PARAM_COUNT] =
{
  [!FOR "ModuleIndex" = "1" TO "num:i($TotalConfig)"!][!//
  {
   [!SELECT "IomTstConfigSet/*[num:i($ModuleIndex)]"!][!//
    [!IF "IomTstMonitorGpio = 'P33_0'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(0)"!][!//
	[!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(0)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(3)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_1'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(1)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(0)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(11)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_2'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(2)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(0)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(19)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_3'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(3)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(0)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(27)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_4'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(4)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(1)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(3)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_5'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(5)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(1)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(11)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_6'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(6)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(1)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(19)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_7'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(7)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(1)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(27)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_8'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(8)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(2)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(3)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_9'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(9)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(2)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(11)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_10'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(10)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(2)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(19)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_11'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(11)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(2)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(27)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P33_12'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(12)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(51)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(3)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(3)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P20_12'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(13)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(32)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(3)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(3)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P20_13'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(14)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(32)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(3)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(11)"!][!//
    [!ELSEIF "IomTstMonitorGpio = 'P20_14'"!][!//	
    [!VAR "IomFpcMonBlockIndex" = "num:i(15)"!][!//
    [!VAR "IomFpcMonPortIndex" = "num:i(32)"!][!//
    [!VAR "IomFpcMonPortCtrlRegIndex" = "num:i(3)"!][!//
    [!VAR "IomFpcMonPortCtrlBitsOff" = "num:i(19)"!][!//
    [!ENDIF!][!//

    /* IomFpcMonBlockIndex */
	(uint8)([!"num:inttohex($IomFpcMonBlockIndex)"!]U),
	
    /* IomFpcMonPortIndex */
    (uint8)([!"num:inttohex($IomFpcMonPortIndex)"!]U),

    /* IomFpcMonPortCtrlRegIndex */
    (uint8)([!"num:inttohex($IomFpcMonPortCtrlRegIndex)"!]U),

    /* IomFpcMonPortCtrlBitsOff */
    (uint8)([!"num:inttohex($IomFpcMonPortCtrlBitsOff)"!]U),

    /* IomLamBlockIndex */
    {
      [!FOR "ModuleLamIndex" = "0" TO "num:i($TotalLamBlocks - num:i(1))"!][!//
      (uint8)([!"num:inttohex(IomTstLamBlock/*[num:i($ModuleLamIndex + num:i(1))]/IomTstLamBlock)"!]U)[!//
      [!IF "($ModuleLamIndex)!= num:i($TotalLamBlocks - num:i(1))"!],[!ENDIF!][!//

      [!ENDFOR!][!//
    },

    /* Dummy variable to ensure even address alignment */
    (uint32)(0x00U)
[!//
    [!ENDSELECT!][!//
  }[!IF "($ModuleIndex)!= num:i($TotalConfig)"!],[!ENDIF!]

  [!ENDFOR!][!//
};
#define IFX_IOMTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

[!ENDSELECT!][!//
[!AUTOSPACING!][!//
