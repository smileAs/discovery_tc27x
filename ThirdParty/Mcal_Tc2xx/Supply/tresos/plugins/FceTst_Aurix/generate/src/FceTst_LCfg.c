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
**   $FILENAME   : FceTst_LCfg.c $                                            **
**                                                                            **
**   $CC VERSION : \main\7 $                                                  **
**                                                                            **
**   $DATE       : 2015-04-13 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : FceTst.bmd/xdm                                    **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for FceTst_LCfg.c file                       **
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
**  FILENAME  :  FceTst_LCfg.c                                               **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : FceTst.bmd/xdm                                   **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : FceTst configuration                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "FceTst.h"

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
 
/* Memory mapping of the FCE configuration */
#define IFX_FCETST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
[!SELECT "as:modconf('FceTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(FceTstConfigSet/*))"!][!//

/* FceTst Module Configuration */
const FceTst_ConfigType FceTst_ConfigRoot[FCE_TST_CFG_PARAM_COUNT] = 
{
[!FOR "FceTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "FceTstConfigSet/*[num:i($FceTstId)]"!][!//
  {
[!VAR "FceTestModeSelection" = "FceTestKernelSelection"!][!//
   [!"$FceTestModeSelection"!]
  }[!IF "$FceTstId < $TotalConfig"!],[!ENDIF!][!//
  
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!AUTOSPACING!]
#define IFX_FCETST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
