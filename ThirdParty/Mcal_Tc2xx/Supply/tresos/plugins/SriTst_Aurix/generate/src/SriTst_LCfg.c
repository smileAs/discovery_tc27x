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
**   $FILENAME   : SriTst_LCfg.c $                                            **
**                                                                            **
**   $CC VERSION : \main\20 $                                                 **
**                                                                            **
**   $DATE       : 2014-10-21 $                                               **
**                                                                            **
**  BSW MODULE DESCRIPTION : SriTst.bmd/xdm                                   **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for Sri_LCfg.c file                          **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
**************************************************************************/!][!//
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
**  FILENAME  : SriTst_LCfg.c                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DESCRIPTION : SriTst.bmd/xdm                                   **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SriTst configuration                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include module header File */ 
#include "SriTst_Cfg.h"
#include "SriTst.h"
/*******************************************************************************
**                      Inclusion File Check                                  **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
[!/*
MACRO: CG_ConfigSwitch 
Macro to generate configuration switch Values 1U/0U based on configuration
true/false
*/!][!//
[!MACRO "CG_ConfigSwitch", "nodeval" = ""!][!//
[!//
[!IF "$nodeval = 'true'"!][!//
1U[!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
[!ENDMACRO!][!//

/* Memory mapping of the SRI configuration */
#define IFX_SRI_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/* SRI test configuration:                                                  */
[!SELECT "as:modconf('SriTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SriTstConfigSet/*))"!][!//
const SriTst_ConfigType SriTst_ConfigRoot[SRI_EDC_BUSERR_TST_CFG_PARAM_COUNT] =
{
[!FOR "SriTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
  [!SELECT "SriTstConfigSet/*[num:i($SriTstId)]"!][!//
/* SriTst_ConfigRoot[[!"num:i(($SriTstId)- 1)"!]]:*/
  {
    {      
      /* LMU Test */
[!IF "node:exists(LMUTestEnCpu0) = 'true'"!][!//
      [!CALL "CG_ConfigSwitch","nodeval" = "./LMUTestEnCpu0"!],  /* LMU Test CPU0 Enabled  */[!//
[!ELSE!][!//
      0U,  /* LMU Test CPU0 Disabled  */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(LMUTestEnCpu1) = 'true'"!][!//      
      [!CALL "CG_ConfigSwitch","nodeval" = "./LMUTestEnCpu1"!],  /* LMU Test CPU1 Enabled  */[!//
[!ELSE!][!//
      0U,  /* LMU Test CPU1 Disabled  */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(LMUTestEnCpu2) = 'true'"!][!//      
      [!CALL "CG_ConfigSwitch","nodeval" = "./LMUTestEnCpu2"!],  /* LMU Test CPU2 Enabled  */[!//
[!ELSE!][!//
      0U,  /* LMU Test CPU2 Disabled  */[!//
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */
    },
    
    {
      /* PMUDFlash Test */
      [!CALL "CG_ConfigSwitch","nodeval" = "./PMUDFlashTestEnCpu0"!],  /* PMUDFlash Test CPU0 Enabled */
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(PMUDFlashTestEnCpu1) = 'true'"!][!//      
      [!CALL "CG_ConfigSwitch","nodeval" = "./PMUDFlashTestEnCpu1"!],  /* PMUDFlash Test CPU1 Enabled */[!//
[!ELSE!][!//
      0U,  /* PMUDflash Test CPU1 Disabled  */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(PMUDFlashTestEnCpu2) = 'true'"!][!//      
      [!CALL "CG_ConfigSwitch","nodeval" = "./PMUDFlashTestEnCpu2"!],  /* PMUDFlash Test CPU2 Enabled */[!//
[!ELSE!][!//
      0U,  /* PMUDflash Test CPU2 Disabled  */[!//
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },

    {
      /* PMUPFlash Test */
      [!CALL "CG_ConfigSwitch","nodeval" = "./PMUPFlashTestEnCpu0"!],  /* PMUPFlash Test CPU0 Enabled */
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(PMUPFlashTestEnCpu1) = 'true'"!][!//      
      [!CALL "CG_ConfigSwitch","nodeval" = "./PMUPFlashTestEnCpu1"!],  /* PMUPFlash Test CPU1 Enabled */[!//
[!ELSE!][!//
      0U,  /* LMU Test CPU0 Disabled  */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(PMUPFlashTestEnCpu2) = 'true'"!][!//      
      [!CALL "CG_ConfigSwitch","nodeval" = "./PMUPFlashTestEnCpu2"!],  /* PMUPFlash Test CPU2 Enabled */[!//
[!ELSE!][!//
      0U,  /* LMU Test CPU0 Disabled  */[!//
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },
    
    {
      /* DMA Test */
      [!CALL "CG_ConfigSwitch","nodeval" = "./DMATestEnCpu0"!],        /* DMA Test CPU0 Enabled */
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(DMATestEnCpu1) = 'true'"!][!//  
      [!CALL "CG_ConfigSwitch","nodeval" = "./DMATestEnCpu1"!],        /* DMA Test CPU1 Enabled */[!//
[!ELSE!][!//
      0U,  /* DMA Test CPU1 Disabled  */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(DMATestEnCpu2) = 'true'"!][!//      
      [!CALL "CG_ConfigSwitch","nodeval" = "./DMATestEnCpu2"!],        /* DMA Test CPU2 Enabled */[!//
[!ELSE!][!//
      0U,  /* DMA Test CPU2 Disabled  */[!//
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },

    {
      /* XBAR Test */
      [!CALL "CG_ConfigSwitch","nodeval" = "./XBARTestEnCpu0"!],       /* SRI XBAR Test CPU0 Enabled  */
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(DMATestEnCpu1) = 'true'"!][!//  
      [!CALL "CG_ConfigSwitch","nodeval" = "./XBARTestEnCpu1"!],       /* SRI XBAR Test CPU1 Enabled  */[!//
[!ELSE!]0U,  /* XBAR Test CPU1 Disabled  */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(DMATestEnCpu2) = 'true'"!][!//      
      [!CALL "CG_ConfigSwitch","nodeval" = "./XBARTestEnCpu2"!],       /* SRI XBAR Test CPU2 Enabled  */[!//
[!ELSE!][!//
      0U,  /* XBAR Test CPU2 Disabled  */[!//
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },
    
    {
      /* PSPR Test Address      */
      (uint32*)[!"num:inttohex(./SriTstPSPRTstAdrCpu0)"!]U,   /* PSPR Test Address CPU0    */
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(SriTstPSPRTstAdrCpu1) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstPSPRTstAdrCpu1)"!]U,   /* PSPR Test Address CPU1    */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,          /* PSPR Test Address CPU1    */
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(SriTstPSPRTstAdrCpu2) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstPSPRTstAdrCpu2)"!]U,   /* PSPR Test Address CPU2    */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,          /* PSPR Test Address CPU2    */
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },
    
    {
      /* DSPR Test Address    */
      (uint32*)[!"num:inttohex(./SriTstDSPRTstAdrCpu0)"!]U,   /* DSPR Test Address CPU0    */
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(SriTstDSPRTstAdrCpu1) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstDSPRTstAdrCpu1)"!]U,   /* DSPR Test Address CPU1    */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,          /* DSPR Test Address CPU1    */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(SriTstDSPRTstAdrCpu2) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstDSPRTstAdrCpu2)"!]U,   /* DSPR Test Address CPU2    */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,          /* DSPR Test Address CPU2    */[!//
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    },
    
    {
      /* LMU Test Address */[!//
[!IF "node:exists(SriTstLMUTstAdrCpu0) = 'true'"!][!//     
      (uint32*)[!"num:inttohex(./SriTstLMUTstAdrCpu0)"!]U,    /* LMU Test Address CPU0   */[!//
[!ELSE!][!//
      (uint32*)[!"num:inttohex(0)"!]U,                        /* LMU Test Address CPU0   */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(SriTstLMUTstAdrCpu1) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstLMUTstAdrCpu1)"!]U,    /* LMU Test Address CPU1   */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,                        /* LMU Test Address CPU1   */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(SriTstLMUTstAdrCpu2) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstLMUTstAdrCpu2)"!]U,    /* LMU Test Address CPU2   */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,                        /* LMU Test Address CPU2   */[!//
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    }, 
    
    {
      /* DFlash Test Address */
      (uint32*)[!"num:inttohex(./SriTstDFlashTstAdrCpu0)"!]U,  /* DFlash Test Address CPU0  */
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(SriTstDFlashTstAdrCpu1) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstDFlashTstAdrCpu1)"!]U,    /* DFlash Test Address CPU1   */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,                        /* DFlash Test Address CPU1   */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(SriTstDFlashTstAdrCpu2) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstDFlashTstAdrCpu2)"!]U,    /* DFlash Test Address CPU2    */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,                        /* DFlash Test Address CPU2   */[!//
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    }, 
    
    {
      /* PFlash Test Address */
      (uint32*)[!"num:inttohex(./SriTstPFlashTstAdrCpu0)"!]U,  /* PFlash Test Address CPU0  */
#if(MCAL_NO_OF_CORES > 1U)
[!IF "node:exists(SriTstPFlashTstAdrCpu1) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstPFlashTstAdrCpu1)"!]U, /* PFlash Test Address CPU1   */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,                        /* PFlash Test Address CPU1   */[!//
[!ENDIF!][!//  
#if(MCAL_NO_OF_CORES == 3U)
[!IF "node:exists(SriTstPFlashTstAdrCpu2) = 'true'"!][!//      
      (uint32*)[!"num:inttohex(./SriTstPFlashTstAdrCpu2)"!]U, /* PFlash Test Address CPU2    */[!//
[!ELSE!][!// 
      (uint32*)[!"num:inttohex(0)"!]U,                        /* PFlash Test Address CPU2   */[!//
[!ENDIF!][!//  
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */      
    } 
  }[!IF "$SriTstId < $TotalConfig"!],[!ENDIF!][!//
  [!ENDSELECT!][!//
[!ENDFOR!]
};
[!ENDSELECT!][!//
#define IFX_SRI_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

