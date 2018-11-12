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
**  FILENAME  : Gpt_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\23 $                                                 **
**                                                                            **
**  DATE, TIME: 2018-08-21, 08:47:50                                         **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Gpt.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GPT configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_GPT_Driver, Release AS4.0.3                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include module header File */ 
#include "Gpt.h"

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

#define GPT_START_SEC_CODE
#include "MemMap.h"




/* 
   Channel Notification Function Declaration 
*/



#define GPT_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* Memory Mapping the configuration constant */
#define GPT_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/* 
   Channel Configuration Instance GptChannelConfigSet
*/ 
static const Gpt_ChannelConfigType Gpt_kChannelConfig0[ ] =
{

  /* Channel Symbolic Name(ChannelId) : GptChannelConfiguration 
     GTM TOM/ATOM Channel : GTM_ATOM0_CHANNEL0 in GPT_MODE_CONTINUOUS
  */ 
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    NULL_PTR, /* Notification Function */
    #endif
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
        && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    /* Assigned Hardware Unit */
    GTM_ATOM0_CHANNEL0,
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    GPT_MODE_CONTINUOUS, /* Channel Mode */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    GPT_QM_SIGNAL, /* Channel Signal Type */
    #endif
    GTM_CONFIGURABLE_CLOCK_0 /* Channel Clock frequency */
  }
};




/* 
Configuration: Configuration  
 Definition of Gpt_ConfigType structure
*/
const Gpt_ConfigType Gpt_ConfigRoot[1] = 
{

  {  
    #if (GPT_SAFETY_ENABLE == STD_ON)
    (uint32)GPT_MODULE_ID << 16U,  
    #endif
    Gpt_kChannelConfig0,

    1U,
}
};

#define GPT_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
