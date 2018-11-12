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
**   $FILENAME   : CpuMpuTst_LCfg.c $                                         **
**                                                                            **
**   $CC VERSION : \main\9 $                                                  **
**                                                                            **
**   $DATE       : 2014-08-09 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuMpuTst.bmd/xdm                                 **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for CpuMpuTst_LCfg.c file                    **
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
**  FILENAME  :  CpuMpuTst_LCfg.c                                             **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuMpuTst.bmd/xdm                                 **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains configuration settings for CPU MPU test **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include module header File */ 
#include "CpuMpuTst.h"

[!NOCODE!][!//
[!INCLUDE "CpuMpuTst.m"!][!//
[!ENDNOCODE!][!//

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
/* Memory mapping of the CPUMPU configuration */
#define IFX_CPUMPUTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

[!SELECT "as:modconf('CpuMpuTst')[1]"!][!//

[!VAR "TotalConfig" = "num:i(count(CpuMpuTstConfigSet/*))"!][!//

/* CPU MPU test configuration  */
const CpuMpuTst_TestCfgType CpuMpuTst_ConfigRoot[CPU_MPU_TST_CFG_PARAM_COUNT] =
{
[!FOR "CpuMpuTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "CpuMpuTstConfigSet/*[num:i($CpuMpuTstId)]"!][!//
    /* CpuMpuTst_ConfigRoot[[!"num:i($CpuMpuTstId - 1)"!]]: */
    {
      /*  .DataRangeEn:  */
      [!NOCODE!][!//      
      [!VAR "DataProt" = "num:i(0)"!][!//
               
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange00TstEn"!],/*  .Range00  */
      [!/* bit 0 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,0)"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange01TstEn"!],/*  .Range01  */
      [!/* bit 1 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,1)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange02TstEn"!],/*  .Range02  */
      [!/* bit 2 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,2)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange03TstEn"!],/*  .Range03  */
      [!/* bit 3 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,3)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange04TstEn"!],/*  .Range04  */
      [!/* bit 4 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,4)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange05TstEn"!],/*  .Range05  */
      [!/* bit 5 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,5)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange06TstEn"!],/*  .Range06  */
      [!/* bit 6 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,6)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange07TstEn"!],/*  .Range07  */
      [!/* bit 7 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,7)+ $DataProt"!][!//
               
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange08TstEn"!],/*  .Range08  */
      [!/* bit 8 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,8)+ $DataProt"!][!//
               
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange09TstEn"!],/*  .Range09  */
      [!/* bit 9 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,9)+ $DataProt"!][!//
            
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange10TstEn"!],/*  .Range10  */
      [!/* bit 10 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,10)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange11TstEn"!],/*  .Range11  */
      [!/* bit 11 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,11)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange12TstEn"!],/*  .Range12  */
      [!/* bit 12 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,12)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange13TstEn"!],/*  .Range13  */
      [!/* bit 13 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,13)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange14TstEn"!],/*  .Range14  */
      [!/* bit 14 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,14)+ $DataProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstDataProtectionTest/CpuMpuTstDataRange15TstEn"!],/*  .Range15  */
      [!/* bit 15 */!][!//
      [!VAR "DataProt" = "bit:shl($OutMacVal,15)+ $DataProt"!][!//
      [!ENDNOCODE!][!//
      (CpuMpuTst_RangeEnType)[!"num:inttohex($DataProt)"!]U,

      /*  .CodeRangeEn:  */
      [!NOCODE!][!//      
      [!VAR "CodeProt" = "num:i(0)"!][!//
               
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstCodeProtectionTest/CpuMpuTstCodeRange00TstEn"!],/*  .Range00  */
      [!/* bit 0 */!][!//
      [!VAR "CodeProt" = "bit:shl($OutMacVal,0)"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstCodeProtectionTest/CpuMpuTstCodeRange01TstEn"!],/*  .Range01  */
      [!/* bit 1 */!][!//
      [!VAR "CodeProt" = "bit:shl($OutMacVal,1)+ $CodeProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstCodeProtectionTest/CpuMpuTstCodeRange02TstEn"!],/*  .Range02  */
      [!/* bit 2 */!][!//
      [!VAR "CodeProt" = "bit:shl($OutMacVal,2)+ $CodeProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstCodeProtectionTest/CpuMpuTstCodeRange03TstEn"!],/*  .Range03  */
      [!/* bit 3 */!][!//
      [!VAR "CodeProt" = "bit:shl($OutMacVal,3)+ $CodeProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstCodeProtectionTest/CpuMpuTstCodeRange04TstEn"!],/*  .Range04  */
      [!/* bit 4 */!][!//
      [!VAR "CodeProt" = "bit:shl($OutMacVal,4)+ $CodeProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstCodeProtectionTest/CpuMpuTstCodeRange05TstEn"!],/*  .Range05  */
      [!/* bit 5 */!][!//
      [!VAR "CodeProt" = "bit:shl($OutMacVal,5)+ $CodeProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstCodeProtectionTest/CpuMpuTstCodeRange06TstEn"!],/*  .Range06  */
      [!/* bit 6 */!][!//
      [!VAR "CodeProt" = "bit:shl($OutMacVal,6)+ $CodeProt"!][!//
                
      [!CALL "CG_ConfigSwitch","MacInputVal" = "CpuMpuTstCodeProtectionTest/CpuMpuTstCodeRange07TstEn"!],/*  .Range07  */
      [!/* bit 7 */!][!//
      [!VAR "CodeProt" = "bit:shl($OutMacVal,7)+ $CodeProt"!][!//
      [!ENDNOCODE!][!//
      (CpuMpuTst_RangeEnType)[!"num:inttohex($CodeProt)"!]U
    }[!IF "$CpuMpuTstId < $TotalConfig"!],[!ENDIF!][!//
[!ENDSELECT!][!//    
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!AUTOSPACING!]
#define IFX_CPUMPUTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"