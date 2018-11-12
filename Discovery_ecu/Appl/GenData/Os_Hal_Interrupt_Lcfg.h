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
 *              File: Os_Hal_Interrupt_Lcfg.h
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
#if !defined (OS_HAL_INTERRUPT_LCFG_H)                                               /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_INTERRUPT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Interrupt_Cfg.h"
# include "Os_Hal_Interrupt_Types.h"

/* Os kernel module dependencies */
# include "Os_Interrupt_Types.h"

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL ISR configuration data: CanIsr_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_0;

/*! HAL ISR configuration data: CanIsr_1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_1;

/*! HAL ISR configuration data: CanIsr_2 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_2;

/*! HAL ISR configuration data: CounterIsr_SystemTimerCore0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore0;

/*! HAL ISR configuration data: Lin_Channel_1_EX_Extended_Error_Interrupt */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Lin_Channel_1_EX_Extended_Error_Interrupt;

/*! HAL ISR configuration data: Lin_Channel_1_RX_Receive_Interrupt */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Lin_Channel_1_RX_Receive_Interrupt;

/*! HAL ISR configuration data: Lin_Channel_1_TX_Transmit_Interrupt */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Lin_Channel_1_TX_Transmit_Interrupt;

/*! HAL ISR configuration data: Uart0_Err_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart0_Err_Isr;

/*! HAL ISR configuration data: Uart0_Rx_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart0_Rx_Isr;

/*! HAL ISR configuration data: Uart0_Tx_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart0_Tx_Isr;

/*! HAL ISR configuration data: XSignalIsr_OsCore_Core0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core0;

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore_Core0 */
extern CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore_Core0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL ISR configuration data: CounterIsr_SystemTimerCore1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore1;

/*! HAL ISR configuration data: KEY_EVENT_Isr */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_KEY_EVENT_Isr;

/*! HAL ISR configuration data: XSignalIsr_OsCore_Core1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core1;

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore_Core1 */
extern CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore_Core1;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL ISR configuration data: CounterIsr_SystemTimerCore2 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore2;

/*! HAL ISR configuration data: XSignalIsr_OsCore_Core2 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core2;

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore_Core2 */
extern CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore_Core2;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_INTERRUPT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.h
 *********************************************************************************************************************/
