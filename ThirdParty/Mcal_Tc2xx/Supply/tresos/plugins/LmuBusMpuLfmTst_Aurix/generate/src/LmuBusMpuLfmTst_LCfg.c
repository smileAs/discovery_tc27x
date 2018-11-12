[!/*****************************************************************************
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
**   $FILENAME   : LmuBusMpuLfmTst_LCfg.c $                                   **
**                                                                            **
**   $CC VERSION : \main\7 $                                                  **
**                                                                            **
**   $DATE       : 2015-04-13 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : LmuBusMpuLfmTst.bmd/xdm                           **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for LmuBusMpuLfmTst_LCfg.c file              **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*****************************************************************************/!]
[!//
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
**  FILENAME  :  LmuBusMpuLfmTst_LCfg.c                                       **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : LmuBusMpuLfmTst.bmd/xdm                           **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : LmuBusMpuLfmTst configuration                              **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "LmuBusMpuLfmTst.h"

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

#define IFX_LMUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

[!SELECT "as:modconf('LmuBusMpuLfmTst')[1]"!][!//

[!VAR "TotalConfig" = "num:i(count(LmuBusMpuLfmTstConfigSet/*))"!][!//

/* LMU Bus MPU LFM test configuration: */
const LmuBusMpuLfmTst_ConfigType
LmuBusMpuLfmTst_ConfigRoot[LMUBUSMPU_LFM_TST_CFG_PARAM_COUNT] =
{
[!FOR "LmuBusMpuTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "LmuBusMpuLfmTstConfigSet/*[num:i($LmuBusMpuTstId)]"!]
  
  /* LmuBusMpuLfmTst_ConfigRoot[[!"num:i($LmuBusMpuTstId - 1)"!]]:*/
  {

      /* LmuBusMpuLfmTstTest Memory */
      [!SELECT "LmuBusMpuLfmTstTestMemory"!][!//
      (uint32*)[!"num:inttohex(LmuBusMpuLfmTstTestMemory, 8)"!]U,
      [!ENDSELECT!]      
   
      [!SELECT "LmuBusMpuLfmTstUnauthorizedAddr"!][!//
      /* LmuBusMpuLfmTst Unauthorized Address */
      {
        (uint32*)[!"num:inttohex(LmuBusMpuLfmTstUnauthorizedAddr)"!]U
      }
      [!ENDSELECT!][!//
      
    }[!IF "$LmuBusMpuTstId < num:i($TotalConfig)"!],[!ELSE!][!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

};

[!ENDSELECT!][!//
[!AUTOSPACING!]    

#define IFX_LMUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
