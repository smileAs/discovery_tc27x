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
**   $FILENAME   : WdgTst_LCfg.c $                                            **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2015-07-07 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : WdgTst.bmd/xdm                                    **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for WdgTst_LCfg.c file                       **
**                                                                            **
**  [/cover]                                                                  **
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
**  FILENAME  :  WdgTst_LCfg.c                                                **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : WdgTst.bmd/xdm                                    **
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
**  DESCRIPTION  : WdgTst configuration                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "WdgTst.h"

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
/* Memory mapping of the WDG configuration */
#define IFX_WDG_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

[!SELECT "as:modconf('WdgTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(WdgTstConfigSet/*))"!][!//

/* WdgTst Module Configuration */
const WdgTst_ConfigType WdgTstCpu_ConfigRoot[WDGCPU_TST_CFG_PARAM_COUNT] =
{
[!FOR "WdgTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "WdgTstConfigSet/*[num:i($WdgTstId)]"!][!//
  {
  [!IF "WdgTstPflowmEn = 'true'"!][!//
    TRUE,[!//
  [!ELSE!][!//
    FALSE,[!//
  [!ENDIF!][!//
   (uint32)(0x00U)[!//
  }[!IF "$WdgTstId < $TotalConfig"!],[!ENDIF!][!//

[!ENDSELECT!][!//
[!ENDFOR!][!//
};

const WdgTst_ConfigType WdgTstSafety_ConfigRoot[WDGSAFETY_TST_CFG_PARAM_COUNT] =
{
[!FOR "WdgTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "WdgTstConfigSet/*[num:i($WdgTstId)]"!][!//
  {
  [!IF "WdgTstPflowmEn = 'true'"!][!//
    TRUE,[!//
  [!ELSE!][!//
    FALSE,[!//
  [!ENDIF!][!//
  (uint32)(0x00U)[!// 
  }[!IF "$WdgTstId < $TotalConfig"!],[!ENDIF!][!//

[!ENDSELECT!][!//
[!ENDFOR!][!//
};


[!ENDSELECT!][!//
[!AUTOSPACING!]

#define IFX_WDG_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
