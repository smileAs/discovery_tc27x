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
**   $FILENAME   : PflashMonTst_LCfg.c $                                      **
**                                                                            **
**   $CC VERSION : \main\5 $                                                  **
**                                                                            **
**   $DATE       : 2015-07-07 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : PmuEccEdcTst.bmd/xdm                              **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**  DESCRIPTION  : Code template for PflashMonTst_LCfg.c file                 **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*****************************************************************************/!]
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
**  FILENAME  :  PflashMonTst_LCfg.c                                               **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : PmuEccEdcTst.bmd/xdm                              **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec                                             **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : PflashMonTst configuration                                 **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "PflashMonTst.h"


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

#define IFX_PFLASHMON_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
[!SELECT "as:modconf('PmuEccEdcTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(PmuEccEdcTstConfigSet/*))"!][!//

/* PFLASH monitor test configuration: */
const PflashMonTst_ConfigType
      PflashMonTst_ConfigRoot[PFLASH_MON_TST_CFG_PARAM_COUNT] =
{
[!FOR "PmuEccEdcTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "PmuEccEdcTstConfigSet/*[num:i($PmuEccEdcTstId)]"!][!//
  {
  	{
      (uint32)[!"PmuEccEdcTstPF0Selection"!]u,  /* Enable test for PFLASH bank 0 */
      [!IF "ecu:get('PmuEccEdcTstPF1Select')='true'"!]
      (uint32)[!"PmuEccEdcTstPF1Selection"!]u,  /* Enable test for PFLASH bank 1 */
      [!ENDIF!]
      [!IF "ecu:get('PmuEccEdcTstPF2Select')='true'"!]
      (uint32)[!"PmuEccEdcTstPF2Selection"!]u,  /* Enable test for PFLASH bank 2 */
      [!ENDIF!]
      [!IF "ecu:get('PmuEccEdcTstPF3Select')='true'"!]
      (uint32)[!"PmuEccEdcTstPF3Selection"!]u,  /* Enable test for PFLASH bank 3 */
      [!ENDIF!]
    }
  }[!IF "$PmuEccEdcTstId < $TotalConfig"!],[!ENDIF!][!//  
[!ENDSELECT!][!//
[!ENDFOR!][!//	
};
[!ENDSELECT!]
#define IFX_PFLASHMON_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

