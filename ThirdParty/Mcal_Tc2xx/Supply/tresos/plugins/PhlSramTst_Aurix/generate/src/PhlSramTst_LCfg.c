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
**   $FILENAME   : PhlSramTst_LCfg.c $                                        **
**                                                                            **
**   $CC VERSION : \main\9 $                                                  **
**                                                                            **
**   $DATE       : 2015-09-09 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : PhlSramTst.bmd/xdm                                **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for PhlSramTst_LCfg.c file                   **
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
**  FILENAME  :  PhlSramTst_LCfg.c                                            **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : PhlSramTst.bmd/xdm                                **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec                                             **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : PhlSramTst configuration                                   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PhlSramTst.h"

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
#define IFX_PHL_SRAM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
[!SELECT "as:modconf('PhlSramTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(PhlSramTstConfigSet/*))"!][!//
[!VAR "PhlSramTstMiniMCDSSelect" = "'false'"!][!//
[!VAR "PhlSramTstEtherMac" = "'false'"!][!//
[!VAR "PhlSramTstGtmFifo" = "'false'"!][!//
[!VAR "PhlSramTstGtmMcs" = "'false'"!][!//
[!VAR "PhlSramTstDPLL" = "'false'"!][!//
[!VAR "PhlSramTstPSI5" = "'false'"!][!//
[!VAR "PhlSramTstSADMA" = "'false'"!][!//
[!VAR "PhlSramTstMCAN0" = "'false'"!][!//
[!VAR "PhlSramTstMCAN1" = "'false'"!][!//
[!VAR "PhlSramTstEray0" = "'false'"!][!//
[!VAR "PhlSramTstEray1" = "'false'"!][!//
[!VAR "PhlSramTstMcds" = "'false'"!][!//
[!VAR "PhlSramTstEmemLower" = "'false'"!][!//
[!VAR "PhlSramTstEmemUpper" = "'false'"!][!//
[!VAR "PhlSramTstCif" = "'false'"!][!//
[!VAR "PhlSramTstEmemXtm" = "'false'"!][!//
[!VAR "PhlSramTstFft" = "'false'"!][!//
[!VAR "PhlSramTstClearMemory" = "'false'"!][!//
/* SramEccTst Module Configuration */
const PhlSramTst_ConfigType PhlSramTst_ConfigRoot[PHLSRAM_TST_CFG_PARAM_COUNT] = 
{
[!FOR "PhlSramTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "PhlSramTstConfigSet/*[num:i($PhlSramTstId)]"!][!//
  {
    {
    /* Memory select: */
    [!VAR "MemorySelect0" = "num:i(0)"!][!//
    [!IF "node:exists(PhlSramTstMiniMCDSSelect) = 'true'"!][!//
    [!VAR "PhlSramTstMiniMCDSSelect" = "PhlSramTstMiniMCDSSelect"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstMiniMCDSSelect = 'true'"!][!//
    [!VAR "Var0_0" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_0" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstEtherMac) = 'true'"!][!//
    [!VAR "PhlSramTstEtherMac" = "PhlSramTstEtherMac"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstEtherMac = 'true'"!][!//
    [!VAR "Var0_1" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_1" = "num:i(0)"!][!//
    [!ENDIF!][!//  
    [!IF "node:exists(PhlSramTstGtmFifo) = 'true'"!][!//
    [!VAR "PhlSramTstGtmFifo" = "PhlSramTstGtmFifo"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstGtmFifo = 'true'"!][!//
    [!VAR "Var0_2" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_2" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstGtmMcs) = 'true'"!][!//
    [!VAR "PhlSramTstGtmMcs" = "PhlSramTstGtmMcs"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstGtmMcs = 'true'"!][!//
    [!VAR "Var0_3" = "num:i(1)"!][!//
    [!VAR "Var0_4" = "num:i(1)"!][!//    
    [!ELSE!][!//
    [!VAR "Var0_3" = "num:i(0)"!][!//
    [!VAR "Var0_4" = "num:i(0)"!][!//    
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstDPLL) = 'true'"!][!//
    [!VAR "PhlSramTstDPLL" = "PhlSramTstDPLL"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstDPLL = 'true'"!][!//
    [!VAR "Var0_5" = "num:i(1)"!][!//
    [!VAR "Var0_6" = "num:i(1)"!][!//
    [!VAR "Var0_7" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_5" = "num:i(0)"!][!//
    [!VAR "Var0_6" = "num:i(0)"!][!//
    [!VAR "Var0_7" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstPSI5) = 'true'"!][!//
    [!VAR "PhlSramTstPSI5" = "PhlSramTstPSI5"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstPSI5 = 'true'"!][!//
    [!VAR "Var0_8" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_8" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstSADMA) = 'true'"!][!//
    [!VAR "PhlSramTstSADMA" = "PhlSramTstSADMA"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstSADMA = 'true'"!][!//
    [!VAR "Var0_9" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_9" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstMCAN0) = 'true'"!][!//
    [!VAR "PhlSramTstMCAN0" = "PhlSramTstMCAN0"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstMCAN0 = 'true'"!][!//
    [!VAR "Var0_10" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_10" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstMCAN1) = 'true'"!][!//
    [!VAR "PhlSramTstMCAN1" = "PhlSramTstMCAN1"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstMCAN1 = 'true'"!][!//
    [!VAR "Var0_11" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_11" = "num:i(0)"!][!//
    [!ENDIF!][!//    
    [!IF "node:exists(PhlSramTstEray0) = 'true'"!][!//
    [!VAR "PhlSramTstEray0" = "PhlSramTstEray0"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstEray0 = 'true'"!][!//
    [!VAR "Var0_12" = "num:i(1)"!][!//
    [!VAR "Var0_13" = "num:i(1)"!][!//
    [!VAR "Var0_14" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_12" = "num:i(0)"!][!//
    [!VAR "Var0_13" = "num:i(0)"!][!//
    [!VAR "Var0_14" = "num:i(0)"!][!//        
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstEray1) = 'true'"!][!//
    [!VAR "PhlSramTstEray1" = "PhlSramTstEray1"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstEray1 = 'true'"!][!//
    [!VAR "Var0_15" = "num:i(1)"!][!//
    [!VAR "Var0_16" = "num:i(1)"!][!//
    [!VAR "Var0_17" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_15" = "num:i(0)"!][!//
    [!VAR "Var0_16" = "num:i(0)"!][!//
    [!VAR "Var0_17" = "num:i(0)"!][!// 
    [!ENDIF!][!//  
    [!IF "node:exists(PhlSramTstMcds) = 'true'"!][!//
    [!VAR "PhlSramTstMcds" = "PhlSramTstMcds"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstMcds = 'true'"!][!//
    [!VAR "Var0_18" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_18" = "num:i(0)"!][!// 
    [!ENDIF!][!//     
    [!IF "node:exists(PhlSramTstEmemLower) = 'true'"!][!//
    [!VAR "PhlSramTstEmemLower" = "PhlSramTstEmemLower"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstEmemLower = 'true'"!][!//
	[!IF "ecu:get('PhlSramTstEmemLower0to3') = 'true'"!]
    [!VAR "Var0_19" = "num:i(1)"!][!//
    [!VAR "Var0_20" = "num:i(1)"!][!//
    [!VAR "Var0_21" = "num:i(1)"!][!//
    [!VAR "Var0_22" = "num:i(1)"!][!//
    [!ELSE!][!//	
    [!VAR "Var0_19" = "num:i(0)"!][!//
    [!VAR "Var0_20" = "num:i(0)"!][!//
    [!VAR "Var0_21" = "num:i(0)"!][!//
    [!VAR "Var0_22" = "num:i(0)"!][!//	
    [!ENDIF!][!//
	[!ELSE!][!//	
    [!VAR "Var0_19" = "num:i(0)"!][!//
    [!VAR "Var0_20" = "num:i(0)"!][!//
    [!VAR "Var0_21" = "num:i(0)"!][!//
    [!VAR "Var0_22" = "num:i(0)"!][!//	
    [!ENDIF!][!//
	[!IF "$PhlSramTstEmemLower = 'true'"!][!//
    [!IF "ecu:get('PhlSramTstEmemLower4to7') = 'true'"!]
    [!VAR "Var0_23" = "num:i(1)"!][!//
    [!VAR "Var0_24" = "num:i(1)"!][!//
    [!VAR "Var0_25" = "num:i(1)"!][!//    
    [!VAR "Var0_26" = "num:i(1)"!][!//
    [!ELSE!][!//	
    [!VAR "Var0_23" = "num:i(0)"!][!//
    [!VAR "Var0_24" = "num:i(0)"!][!//
    [!VAR "Var0_25" = "num:i(0)"!][!//    
    [!VAR "Var0_26" = "num:i(0)"!][!//	
    [!ENDIF!][!//
    [!ELSE!][!//	
    [!VAR "Var0_23" = "num:i(0)"!][!//
    [!VAR "Var0_24" = "num:i(0)"!][!//
    [!VAR "Var0_25" = "num:i(0)"!][!//    
    [!VAR "Var0_26" = "num:i(0)"!][!//		
	[!ENDIF!][!//
    [!IF "$PhlSramTstEmemLower = 'true'"!][!//	
    [!IF "ecu:get('PhlSramTstEmemLower8to15') = 'true'"!]
    [!VAR "Var0_27" = "num:i(1)"!][!//
    [!VAR "Var0_28" = "num:i(1)"!][!//
    [!VAR "Var0_29" = "num:i(1)"!][!//
    [!VAR "Var0_30" = "num:i(1)"!][!//
    [!VAR "Var0_31" = "num:i(1)"!][!//
    [!ELSE!][!//
    [!VAR "Var0_27" = "num:i(0)"!][!//
    [!VAR "Var0_28" = "num:i(0)"!][!//
    [!VAR "Var0_29" = "num:i(0)"!][!//
    [!VAR "Var0_30" = "num:i(0)"!][!//
    [!VAR "Var0_31" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!ELSE!][!//
    [!VAR "Var0_27" = "num:i(0)"!][!//
    [!VAR "Var0_28" = "num:i(0)"!][!//
    [!VAR "Var0_29" = "num:i(0)"!][!//
    [!VAR "Var0_30" = "num:i(0)"!][!//
    [!VAR "Var0_31" = "num:i(0)"!][!//	
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
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_15,15))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_16,16))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_17,17))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_18,18))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_19,19))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_20,20))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_21,21))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_22,22))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_23,23))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_24,24))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_25,25))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_26,26))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_27,27))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_28,28))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_29,29))"!][!//   
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_30,30))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_31,31))"!][!//    
    [!"text:toupper(num:inttohex($MemorySelect0,8))"!]U,

    [!VAR "MemorySelect0" = "num:i(0)"!][!//
    [!IF "node:exists(PhlSramTstEmemLower) = 'true'"!][!//
    [!VAR "PhlSramTstEmemLower" = "PhlSramTstEmemLower"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstEmemLower = 'true'"!][!//	
    [!IF "ecu:get('PhlSramTstEmemLower8to15') = 'true'"!]	
    [!VAR "Var0_0" = "num:i(1)"!][!//  
    [!VAR "Var0_1" = "num:i(1)"!][!//
    [!VAR "Var0_2" = "num:i(1)"!][!//      
    [!ELSE!][!//
    [!VAR "Var0_0" = "num:i(0)"!][!//  
    [!VAR "Var0_1" = "num:i(0)"!][!//
    [!VAR "Var0_2" = "num:i(0)"!][!// 
    [!ENDIF!][!// 
    [!ELSE!][!//
    [!VAR "Var0_0" = "num:i(0)"!][!//  
    [!VAR "Var0_1" = "num:i(0)"!][!//
    [!VAR "Var0_2" = "num:i(0)"!][!// 	
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstEmemUpper) = 'true'"!][!//
    [!VAR "PhlSramTstEmemUpper" = "PhlSramTstEmemUpper"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstEmemUpper = 'true'"!][!//    
    [!VAR "Var0_3" = "num:i(1)"!][!//
    [!VAR "Var0_4" = "num:i(1)"!][!//
    [!VAR "Var0_5" = "num:i(1)"!][!//
    [!VAR "Var0_6" = "num:i(1)"!][!//
    [!VAR "Var0_7" = "num:i(1)"!][!//
    [!VAR "Var0_8" = "num:i(1)"!][!//
    [!VAR "Var0_9" = "num:i(1)"!][!//    
    [!VAR "Var0_10" = "num:i(1)"!][!//
    [!VAR "Var0_11" = "num:i(1)"!][!//
    [!VAR "Var0_12" = "num:i(1)"!][!//
    [!VAR "Var0_13" = "num:i(1)"!][!//
    [!VAR "Var0_14" = "num:i(1)"!][!//
    [!VAR "Var0_15" = "num:i(1)"!][!//
    [!VAR "Var0_16" = "num:i(1)"!][!//  
    [!VAR "Var0_17" = "num:i(1)"!][!//
    [!VAR "Var0_18" = "num:i(1)"!][!//      
    [!ELSE!][!//
    [!VAR "Var0_3" = "num:i(0)"!][!//
    [!VAR "Var0_4" = "num:i(0)"!][!//
    [!VAR "Var0_5" = "num:i(0)"!][!//
    [!VAR "Var0_6" = "num:i(0)"!][!//
    [!VAR "Var0_7" = "num:i(0)"!][!//
    [!VAR "Var0_8" = "num:i(0)"!][!//
    [!VAR "Var0_9" = "num:i(0)"!][!//    
    [!VAR "Var0_10" = "num:i(0)"!][!//
    [!VAR "Var0_11" = "num:i(0)"!][!//
    [!VAR "Var0_12" = "num:i(0)"!][!//
    [!VAR "Var0_13" = "num:i(0)"!][!//
    [!VAR "Var0_14" = "num:i(0)"!][!//
    [!VAR "Var0_15" = "num:i(0)"!][!//
    [!VAR "Var0_16" = "num:i(0)"!][!//  
    [!VAR "Var0_17" = "num:i(0)"!][!//
    [!VAR "Var0_18" = "num:i(0)"!][!// 
    [!ENDIF!][!//    
    [!IF "node:exists(PhlSramTstCif) = 'true'"!][!//
    [!VAR "PhlSramTstCif" = "PhlSramTstCif"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstCif = 'true'"!][!//
    [!VAR "Var0_19" = "num:i(1)"!][!//
    [!VAR "Var0_20" = "num:i(1)"!][!//  
    [!VAR "Var0_21" = "num:i(1)"!][!//     
    [!ELSE!][!//
    [!VAR "Var0_19" = "num:i(0)"!][!//
    [!VAR "Var0_20" = "num:i(0)"!][!//    
    [!VAR "Var0_21" = "num:i(0)"!][!//      
    [!ENDIF!][!//  
    [!IF "node:exists(PhlSramTstEmemXtm) = 'true'"!][!//
    [!VAR "PhlSramTstEmemXtm" = "PhlSramTstEmemXtm"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstEmemXtm = 'true'"!][!//
    [!VAR "Var0_22" = "num:i(1)"!][!//
    [!VAR "Var0_23" = "num:i(1)"!][!//    
    [!ELSE!][!//
    [!VAR "Var0_22" = "num:i(0)"!][!//
    [!VAR "Var0_23" = "num:i(0)"!][!//    
    [!ENDIF!][!//
    [!IF "node:exists(PhlSramTstFft) = 'true'"!][!//
    [!VAR "PhlSramTstFft" = "PhlSramTstFft"!][!//
    [!ENDIF!][!//
    [!IF "$PhlSramTstFft = 'true'"!][!//
    [!VAR "Var0_24" = "num:i(1)"!][!//
    [!VAR "Var0_25" = "num:i(1)"!][!//    
    [!ELSE!][!//
    [!VAR "Var0_24" = "num:i(0)"!][!//
    [!VAR "Var0_25" = "num:i(0)"!][!//    
    [!ENDIF!][!//
    [!VAR "Var0_26" = "num:i(0)"!][!//
    [!VAR "Var0_27" = "num:i(0)"!][!//
    [!VAR "Var0_28" = "num:i(0)"!][!//
    [!VAR "Var0_29" = "num:i(0)"!][!//
    [!VAR "Var0_30" = "num:i(0)"!][!//
    [!VAR "Var0_31" = "num:i(0)"!][!//
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
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_15,15))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_16,16))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_17,17))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_18,18))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_19,19))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_20,20))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_21,21))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_22,22))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_23,23))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_24,24))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_25,25))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_26,26))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_27,27))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_28,28))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_29,29))"!][!//   
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_30,30))"!][!//
    [!VAR "MemorySelect0" = "bit:or($MemorySelect0,bit:shl($Var0_31,31))"!][!//    
    [!"text:toupper(num:inttohex($MemorySelect0,8))"!]U,    
    
    },
    /* Backup Memory: */
    [!IF "node:exists(PhlSramTstClearMemory) = 'true'"!][!//
    [!VAR "PhlSramTstClearMemory" = "PhlSramTstClearMemory"!][!//
    [!IF "$PhlSramTstClearMemory = 'true'"!][!//
    (boolean)TRUE,[!//
    [!ELSE!][!//
    (boolean)FALSE,[!//
    [!ENDIF!][!//
    [!ENDIF!][!//
       
  }[!IF "$PhlSramTstId < $TotalConfig"!],[!ENDIF!][!//
  
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!AUTOSPACING!]
#define IFX_PHL_SRAM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
