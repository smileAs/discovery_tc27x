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
 *              File: Os_Stack_Cfg.h
 *   Generation Time: 2018-08-04 14:15:27
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
#if !defined (OS_STACK_CFG_H)                                                        /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_STACK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether stack monitoring is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMONITORING                  (STD_ON)

/*! Defines whether stack measurement is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMEASUREMENT                 (STD_OFF)

/* Configured stack sizes (Total: 41728 Byte) */
# define OS_CFG_SIZE_DEFAULT_BSW_ASYNC_TASK_CORE0_STACK     (16384UL)
# define OS_CFG_SIZE_OSCORE_CORE0_ERROR_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE0_INIT_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_ISR_CORE_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE0_KERNEL_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE0_SHUTDOWN_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE0_STARTUP_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO5_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO6_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE1_ERROR_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE1_INIT_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE1_ISR_CORE_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE1_KERNEL_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE1_SHUTDOWN_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE1_STARTUP_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE1_TASK_PRIO1_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE1_TASK_PRIO4_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE1_TASK_PRIO6_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE2_ERROR_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE2_INIT_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE2_ISR_CORE_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE2_KERNEL_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE2_SHUTDOWN_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE2_STARTUP_STACK     (256UL)
# define OS_CFG_SIZE_OSCORE_CORE2_TASK_PRIO2_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE2_TASK_PRIO3_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE2_TASK_PRIO6_STACK     (2048UL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
