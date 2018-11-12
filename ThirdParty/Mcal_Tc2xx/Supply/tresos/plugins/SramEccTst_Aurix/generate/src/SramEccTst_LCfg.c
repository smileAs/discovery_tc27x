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
**   $FILENAME   : SramEccTst_LCfg.c $                                        **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
**                                                                            **
**   $DATE       : 2014-07-30 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SramEccTst.bmd/xdm                                **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for SramEccTst_LCfg.c file                   **
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
**  FILENAME  :  SramEccTst_LCfg.c                                            **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SramEccTst.bmd/xdm                                **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec                                             **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SramEccTst configuration                                   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SramEccTst.h"

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
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
 
/* Memory mapping of the SRAMECC configuration */
#define IFX_SRAM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
[!SELECT "as:modconf('SramEccTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SramEccTstConfigSet/*))"!][!//
[!VAR "SramEccTstCpu2DsprSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu2DtagSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu2PsprSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu2PtagSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu1DsprSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu1DtagSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu1PsprSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu1PtagSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu0DsprSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu0PsprSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu0PtagSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu0DtagSelect" = "'false'"!][!//
[!VAR "SramEccTstCpu1Dspr2Select" = "'false'"!][!//
[!VAR "SramEccTstCpu2Dspr2Select" = "'false'"!][!//
[!VAR "SramEccTstDamSelect" = "'false'"!][!//
[!VAR "SramEccTstBackupMemory" = "'false'"!][!//
/* SramEccTst Module Configuration */
const SramEccTst_ConfigType SramEccTst_ConfigRoot[SRAMECC_TST_CFG_PARAM_COUNT] = 
{
[!FOR "SramEccTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SramEccTstConfigSet/*[num:i($SramEccTstId)]"!][!//
  {
    /* Memory select: */
    [!VAR "MemorySelect0" = "num:i(0)"!][!//
    [!IF "node:exists(SramEccTstCpu0DsprSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu0DsprSelect" = "SramEccTstCpu0DsprSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu0DsprSelect = 'true'"!][!//
    [!VAR "Var0_0" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_0" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu0DtagSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu0DtagSelect" = "SramEccTstCpu0DtagSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu0DtagSelect = 'true'"!][!//
    [!VAR "Var0_1" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_1" = "num:i(0)"!][!//
    [!ENDIF!][!//  
    [!IF "node:exists(SramEccTstCpu0PsprSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu0PsprSelect" = "SramEccTstCpu0PsprSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu0PsprSelect = 'true'"!][!//
    [!VAR "Var0_2" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_2" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu0PtagSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu0PtagSelect" = "SramEccTstCpu0PtagSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu0PtagSelect = 'true'"!][!//
    [!VAR "Var0_3" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_3" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu1DsprSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu1DsprSelect" = "SramEccTstCpu1DsprSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu1DsprSelect = 'true'"!][!//
    [!VAR "Var0_4" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_4" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu1Dspr2Select) = 'true'"!][!//
    [!VAR "SramEccTstCpu1Dspr2Select" = "SramEccTstCpu1Dspr2Select"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu1Dspr2Select = 'true'"!][!//
    [!VAR "Var0_5" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_5" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu1DtagSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu1DtagSelect" = "SramEccTstCpu1DtagSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu1DtagSelect = 'true'"!][!//
    [!VAR "Var0_6" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_6" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu1PsprSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu1PsprSelect" = "SramEccTstCpu1PsprSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu1PsprSelect = 'true'"!][!//
    [!VAR "Var0_7" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_7" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu1PtagSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu1PtagSelect" = "SramEccTstCpu1PtagSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu1PtagSelect = 'true'"!][!//
    [!VAR "Var0_8" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_8" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu2DsprSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu2DsprSelect" = "SramEccTstCpu2DsprSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu2DsprSelect = 'true'"!][!//
    [!VAR "Var0_9" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_9" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu2Dspr2Select) = 'true'"!][!//
    [!VAR "SramEccTstCpu2Dspr2Select" = "SramEccTstCpu2Dspr2Select"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu2Dspr2Select = 'true'"!][!//
    [!VAR "Var0_10" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_10" = "num:i(0)"!][!//
    [!ENDIF!][!//  
    [!IF "node:exists(SramEccTstCpu2DtagSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu2DtagSelect" = "SramEccTstCpu2DtagSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu2DtagSelect = 'true'"!][!//
    [!VAR "Var0_11" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_11" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu2PsprSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu2PsprSelect" = "SramEccTstCpu2PsprSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu2PsprSelect = 'true'"!][!//
    [!VAR "Var0_12" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_12" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstCpu2PtagSelect) = 'true'"!][!//
    [!VAR "SramEccTstCpu2PtagSelect" = "SramEccTstCpu2PtagSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstCpu2PtagSelect = 'true'"!][!//
    [!VAR "Var0_13" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_13" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(SramEccTstDamSelect) = 'true'"!][!//
    [!VAR "SramEccTstDamSelect" = "SramEccTstDamSelect"!][!//
    [!ENDIF!][!//
    [!IF "$SramEccTstDamSelect = 'true'"!][!//
    [!VAR "Var0_14" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_14" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_0,0))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_1,1))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_2,2))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_3,3))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_4,4))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_5,5))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_6,6))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_7,7))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_8,8))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_9,9))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_10,10))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_11,11))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_12,12))"!][!//
     [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_13,13))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_14,14))"!][!//    
    [!"text:toupper(num:inttohex($MemorySelect0,8))"!]U,
    
    /* Backup Memory: */
    [!IF "node:exists(SramEccTstBackupMemory) = 'true'"!][!//
    [!VAR "SramEccTstBackupMemory" = "SramEccTstBackupMemory"!][!//
    [!IF "$SramEccTstBackupMemory = 'true'"!][!//
    (boolean)TRUE,[!//
    [!ELSE!][!//
    (boolean)FALSE,[!//
    [!ENDIF!][!//
    [!ENDIF!][!//
       
  }[!IF "$SramEccTstId < $TotalConfig"!],[!ENDIF!][!//
  
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!AUTOSPACING!]
#define IFX_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
