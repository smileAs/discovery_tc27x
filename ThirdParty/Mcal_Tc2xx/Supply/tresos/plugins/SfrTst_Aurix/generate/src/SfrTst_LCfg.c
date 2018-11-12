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
**   $FILENAME   : SfrTst_LCfg.c $                                            **
**                                                                            **
**   $CC VERSION : \main\14 $                                                 **
**                                                                            **
**   $DATE       : 2015-11-02 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SfrTst.bmd/xdm                                    **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SfrTst_LCfg.c file                       **
**                                                                            **
**  [/cover]                                                                  **
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
**  FILENAME  :  SfrTst_LCfg.c                                                **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SfrTst.bmd/xdm                                    **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains configuration settings for SFR test     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SfrTst_Cfg.h"
#include "Ifx_reg.h"

#define IFX_SFRTST_START_SEC_LINKTIMECFG_ASIL_B
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
[!SELECT "as:modconf('SfrTst')[1]"!][!//

[!VAR "TotalConfig" = "num:i(count(SfrTstConfigSet/*))"!][!//

[!FOR "SfrTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SfrTstConfigSet/*[num:i($SfrTstId)]"!][!//
[!VAR "TotalSFRConfig" = "num:i(count(SfrTstRegister/*))"!][!// 
/* SfrTest configuration  */
const SfrTst_ConfigType RegisterConfig[!"num:i($SfrTstId)"!][[!"num:i($TotalSFRConfig)"!]] =
{
  /* Register Address,  Value,  Mask , BitWidth        */
[!FOR "SFRId" ="num:i(1)" TO "(num:i($TotalSFRConfig))"!][!//
[!SELECT "SfrTstRegister/*[num:i($SFRId)]"!][!//
  {&[!"SfrTstRegisterName"!].U, [!"num:inttohex(SfrTstRegisterValue)"!]U,  [!"num:inttohex(SfrTstRegisterMask)"!]U, [!"SfrTstRegisterBitWidth"!]}, 
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//    
[!ENDFOR!][!//

/* The index given in the API function is used to choose which */
/* configuration is used from AllAvailableSets                 */
const SfrTst_ParamSetType AllAvailableSets[SFR_TST_CFG_PARAM_COUNT] =
{
[!VAR "CRCValue" = "num:i(0)"!][!//
[!FOR "SfrTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SfrTstConfigSet/*[num:i($SfrTstId)]"!][!//
[!VAR "TotalSFRConfig" = "num:i(count(SfrTstRegister/*))"!][!// 
[!VAR "CRCValue" = "SfrTstExpectedCrcResult"!][!//

  {[!"$TotalSFRConfig"!]U,  [!"num:inttohex($CRCValue)"!]U, RegisterConfig[!"$SfrTstId"!]}[!IF "$SfrTstId < $TotalConfig"!],
 [!ELSE!]
 [!VAR "SfrTstId" = "num:i(0)"!] 
 [!ENDIF!][!//  
[!ENDSELECT!][!//    
[!ENDFOR!][!// 
};
[!ENDSELECT!][!//
[!AUTOSPACING!]
#define IFX_SFRTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"    