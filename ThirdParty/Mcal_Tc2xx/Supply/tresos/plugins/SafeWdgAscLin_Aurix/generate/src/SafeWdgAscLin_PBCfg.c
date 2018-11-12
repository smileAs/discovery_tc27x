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
**   $FILENAME   : SafeWdgAscLin_PBCfg.c $                                    **
**                                                                            **
**   $CC VERSION : \main\18 $                                                 **
**                                                                            **
**   $DATE       : 2015-09-03 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgAscLin.bmd/xdm                             **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SafeWdgAscLin_PBCfg.c file               **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgAscLin.docm, Ver 0.1        **
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
**  FILENAME  :  SafeWdgAscLin_PBCfg.c                                        **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgAscLin.bmd/xdm                             **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/HighTec/WindRiver                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **                                                                      
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgAscLin configuration generated file                 **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgAscLin.docm, Ver 0.1        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SafeWdgIf.h"
#include "IfxAsclin_reg.h"
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

[!SELECT "as:modconf('SafeWdgAscLin')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SafeWdgAscLinConfigSet/*))"!][!//

/* external CiC watchdog configuration */
const SafeWdgAscLin_ConfigType SafeWdgAscLin_ConfigRoot[[!"num:i($TotalConfig)"!]] =
{
 [!FOR "SafeWdgAscLin" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
 [!SELECT "SafeWdgAscLinConfigSet/*[num:i($SafeWdgAscLin)]"!][!//
 [!VAR "GroupId" = "num:i(0)"!][!//
  { 
    
        /* ASCLIN selection */
       &MODULE_ASCLIN[!"SafeWdgAscLinAscLinModule"!],     /* selected ASCLIN module */     
       [!"SafeWdgAscLinDmaTxChannel"!]u,             /* DMA Tx channel */          
       /* Baudrate configuration */
       [!"SafeWdgAscLinBConOversample"!]u,          /* oversampling (4-16)*/
       [!"SafeWdgAscLinBConSamplePoint"!]u,          /* Defines the length of the first SCLK half period (1 -15)*/
       [!"SafeWdgAscLinBConPreScaler"!]u,          /* prescaler value (1-4096) */
       [!"SafeWdgAscLinBrgDenominator"!]u,         /* baudrate denominator (1-4095)*/
       [!"SafeWdgAscLinBrgNumerator"!]u,         /* baudrate numerator (1-4095) */
       
       /* Frame configuration */
       [!"SafeWdgAscLinFConIdleCnt"!]u,          /* idle cycles between two transmissions  (0-7) */
       [!"SafeWdgAscLinFConTrailCnt"!]u,          /* trail cycles after transmission (0-7) */
       [!"SafeWdgAscLinFConLeadCnt"!]u,          /* leading cycles before transmission (0-7) */
       [!"SafeWdgAscLinFConMsb"!]u,          /* MSB first (0: no, 1: yes) */
       
       /* IOCR configuration */
       [!"SafeWdgAscLinCsPolarity"!]u,          /* slave CS polarity (0: high active, 1: low active) */
       [!"SafeWdgAscLinRxInputSelect"!]u,          /* receiver port input selector (0-7) */ 
     
       /* Functions configuration */
     
       &[!"SafeWdgAscLinEnIfmDlayTmrFunc"!],        /* Enable TOM Channel */ 
       &[!"SafeWdgAscLinDisIfmDlayTmrFunc"!],       /* Disable TOM Channel */
    
        
    }[!IF "$SafeWdgAscLin < $TotalConfig"!],[!ENDIF!][!//               
    
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
