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
**  $FILENAME   : Uart_PBCfg.c $                                             **
**                                                                            **
**  $CC VERSION : \main\24 $                                                 **
**                                                                            **
**  DATE, TIME: 2018-08-21, 08:49:53                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Uart configuration generated out of ECU configuration      **
**                 file(Uart.bmd/.xdm)                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include UART Module File */
#include "Uart.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*
               Container: UartConfigSet
*/
#include "Os.h"
#define UART_START_SEC_CODE_ISR
#include "MemMap.h"


ISR(Uart_IsrTransmit0){ Uart_IsrTransmit( 0 ); }
ISR(Uart_IsrError0){ Uart_IsrError( 0 ); }
ISR(Uart_IsrReceive0){ Uart_IsrReceive( 0 ); }

#define UART_STOP_SEC_CODE_ISR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define UART_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"

/* Uart Channel Initialization Data */

static const Uart_ChannelType  Uart_kChannelConfig0[1] = 
{
  {  /* Notification function pointers for UART Module */
    {
      /* Call-back Notification Function for Write operation */
      NULL_PTR,
      /* Call-back Notification Function for Read operation */
      NULL_PTR,
      /* Call-back Notification Function for AbortWrite operation */
      NULL_PTR,
      /* Call-back Notification Function for AbortRead operation */
      NULL_PTR,
    },
  	/* BaudRate : 115200 Hz  */
    72U,       /* BRG.NUMERATOR value */
    1000U,     /* BRG.DENOMINATOR value */
    4U,       /* BITCON.PRESCALAR value */
    9U,       /* BITCON.Oversampling value */
    UART_ASCLIN0,    /* HW Unit used */
    1U,      /* Number of Stop Bits*/
    8U,      /* DataLength*/
    0U,      /* UartRxPinSelection */
    0U,      /*Parity Enable*/ 
    0U,      /* Odd or Even Parity */ 
    0U,      /*CTS Enable*/
    0U,      /*RTS/CTS Polarity*/
  },
};

/* Uart Module Initialization Data */

const Uart_ConfigType  Uart_ConfigRoot[1] = 
 {
   {
      Uart_kChannelConfig0,
      1U,
   }  
 };

#define UART_STOP_SEC_POSTBUILDCFG
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

