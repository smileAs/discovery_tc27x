/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Interrupt_Lcfg.c
 *   Generation Time: 2018-09-29 15:39:31
 *           Project: discovery_ecu - Version 1.0
 *          Delivery: CBD1800319_D00
 *      Tool Version: DaVinci Configurator (beta) 5.15.11 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Os/IdleTask_OsCore_Core0[0:OsTaskPriority](value=-1) is not in range [0, 4294967295].
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/IdleTask_OsCore_Core0[0:OsTaskPriority](value=-1) (DefRef: /MICROSAR/Os/OsTask/OsTaskPriority)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Os/IdleTask_OsCore_Core1[0:OsTaskPriority](value=-1) is not in range [0, 4294967295].
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/IdleTask_OsCore_Core1[0:OsTaskPriority](value=-1) (DefRef: /MICROSAR/Os/OsTask/OsTaskPriority)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Os/IdleTask_OsCore_Core2[0:OsTaskPriority](value=-1) is not in range [0, 4294967295].
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/IdleTask_OsCore_Core2[0:OsTaskPriority](value=-1) (DefRef: /MICROSAR/Os/OsTask/OsTaskPriority)
 * 
 * [Warning] Cfg95301 - Os Interrupt Service Routine parameter invalid or different to configuration in BSW module 
 * - [Reduced Severity due to User-Defined Parameter] Either this parameter deviates from its definition in the /ActiveEcuC/Can Os Interrupt Service Routine or the definition of this parameter is invalid.
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/CanIsr_1 (DefRef: /MICROSAR/Os/OsIsr)
 * /ActiveEcuC/Os/CanIsr_1[0:OsIsrInterruptPriority](value=11) (DefRef: /MICROSAR/Os/OsIsr/OsIsrInterruptPriority)
 * 
 * [Warning] Cfg95301 - Os Interrupt Service Routine parameter invalid or different to configuration in BSW module 
 * - [Reduced Severity due to User-Defined Parameter] Either this parameter deviates from its definition in the /ActiveEcuC/Can Os Interrupt Service Routine or the definition of this parameter is invalid.
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/CanIsr_2 (DefRef: /MICROSAR/Os/OsIsr)
 * /ActiveEcuC/Os/CanIsr_2[0:OsIsrInterruptPriority](value=12) (DefRef: /MICROSAR/Os/OsIsr/OsIsrInterruptPriority)
 *********************************************************************************************************************/
/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HAL_INTERRUPT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL ISR configuration data: CanIsr_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_0 =
{
  /* .Level          = */ 10,
  /* .Source         = */ 0x900UL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: CanIsr_1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_1 =
{
  /* .Level          = */ 11,
  /* .Source         = */ 0x904UL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: CanIsr_2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_2 =
{
  /* .Level          = */ 12,
  /* .Source         = */ 0x908UL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: CounterIsr_SystemTimerCore0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore0 =
{
  /* .Level          = */ 5,
  /* .Source         = */ 0x490UL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: Lin_Channel_1_EX_Extended_Error_Interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Lin_Channel_1_EX_Extended_Error_Interrupt =
{
  /* .Level          = */ 22,
  /* .Source         = */ 0x94UL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: Lin_Channel_1_RX_Receive_Interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Lin_Channel_1_RX_Receive_Interrupt =
{
  /* .Level          = */ 23,
  /* .Source         = */ 0x90UL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: Lin_Channel_1_TX_Transmit_Interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Lin_Channel_1_TX_Transmit_Interrupt =
{
  /* .Level          = */ 24,
  /* .Source         = */ 0x8cUL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: Uart0_Err_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart0_Err_Isr =
{
  /* .Level          = */ 32,
  /* .Source         = */ 0x88UL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: Uart0_Rx_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart0_Rx_Isr =
{
  /* .Level          = */ 31,
  /* .Source         = */ 0x84UL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: Uart0_Tx_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart0_Tx_Isr =
{
  /* .Level          = */ 30,
  /* .Source         = */ 0x80UL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: XSignalIsr_OsCore_Core0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core0 =
{
  /* .Level          = */ 0,
  /* .Source         = */ 0x1000UL,
  /* .CoreAssignment = */ 0
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore_Core0 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore_Core0 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core0,
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL ISR configuration data: CounterIsr_SystemTimerCore1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore1 =
{
  /* .Level          = */ 17,
  /* .Source         = */ 0x498UL,
  /* .CoreAssignment = */ 1
};

/*! HAL ISR configuration data: KEY_EVENT_Isr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_KEY_EVENT_Isr =
{
  /* .Level          = */ 33,
  /* .Source         = */ 0xcd4UL,
  /* .CoreAssignment = */ 1
};

/*! HAL ISR configuration data: XSignalIsr_OsCore_Core1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core1 =
{
  /* .Level          = */ 0,
  /* .Source         = */ 0x1020UL,
  /* .CoreAssignment = */ 1
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore_Core1 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore_Core1 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core1,
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL ISR configuration data: CounterIsr_SystemTimerCore2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore2 =
{
  /* .Level          = */ 18,
  /* .Source         = */ 0x4a0UL,
  /* .CoreAssignment = */ 2
};

/*! HAL ISR configuration data: XSignalIsr_OsCore_Core2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core2 =
{
  /* .Level          = */ 0,
  /* .Source         = */ 0x1040UL,
  /* .CoreAssignment = */ 2
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore_Core2 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore_Core2 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core2,
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.c
 *********************************************************************************************************************/
