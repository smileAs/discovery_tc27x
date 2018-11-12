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
**   $FILENAME   : SafeWdgIf_PBCfg.c $                                        **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
**                                                                            **
**   $DATE       : 2015-06-01 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgIf.bmd/xdm                                 **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    :  DL-BLR-ATV-STC                                               **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SafeWdgIf_PBCfg.c file                   **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : Aurix-HE_SafeTlib_DS_SafeWdgIf.docm, Ver 1.1           **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*****************************************************************************/!]
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
**  FILENAME  :  SafeWdgIf_PBCfg.c                                            **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgIf.bmd/xdm                                 **
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
**  DESCRIPTION  : SafeWdgIf configuration generated file.                    **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SafeWdgIf.h"

[!SELECT "as:modconf('SafeWdgIf')[1]"!][!//
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
**                      Global Constant Definitions                           **
*******************************************************************************/
#define IFX_SWDG_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

[!VAR "TotalConfig" = "num:i(count(SafeWdgIfConfigSet/*))"!][!//
[!VAR "WdgConfig" = "SafeWdgIfGeneral/SafeWdgIfWdgCombination"!][!//
/* configuration(s) for underlying watchdogs used by SafeWdgIf */

const SafeWdgIf_ConfigType SafeWdgIf_ConfigRoot[SAFEWDGIF_CFG_COUNT] = 
{
[!FOR "SafeWdgIf" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SafeWdgIfConfigSet/*[num:i($SafeWdgIf)]"!][!//
  {
	/* Internal watchdog configuration*/
  [!IF "$WdgConfig= 'SWDG_INT_WDG_ONLY'"!][!//
		&SafeWdgInt_ConfigRoot[[!"num:i(SafeWdgIfIntWdgConfigIndex)"!]],
		NULL_PTR
  [!ELSEIF "$WdgConfig = 'SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG' "!][!//
		&SafeWdgInt_ConfigRoot[[!"num:i(SafeWdgIfIntWdgConfigIndex)"!]],
		&SafeWdgExtTlf_ConfigRoot[[!"num:i(SafeWdgIfExtWdgTlfConfigIndex)"!]]
  [!ELSEIF "$WdgConfig = 'SWDG_EXT_CIC_WDG_ONLY' "!][!//
		NULL_PTR,
		&SafeWdgExtCic_ConfigRoot[[!"num:i(SafeWdgIfExtWdgCicConfigIndex)"!]]
	[!ELSE!][!//
		NULL_PTR,
		&SafeWdgExtTlf_ConfigRoot[[!"num:i(SafeWdgIfExtWdgTlfConfigIndex)"!]]
  [!ENDIF!][!//
  }[!IF "$SafeWdgIf < $TotalConfig"!],[!ENDIF!][!//

[!ENDSELECT!][!//
[!ENDFOR!][!//  
};
#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
[!ENDSELECT!][!//
[!AUTOSPACING!] 