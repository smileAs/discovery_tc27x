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
 *              File: Os_Stack_Lcfg.h
 *   Generation Time: 2018-11-11 09:44:58
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
#if !defined (OS_STACK_LCFG_H)                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_STACK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_Stack_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


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

# define OS_START_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: Default_BSW_Async_Task_Core0 */
/* User: [Default_BSW_Async_Task_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_Default_BSW_Async_Task_Core0_Dyn, OS_CFG_SIZE_DEFAULT_BSW_ASYNC_TASK_CORE0_STACK);

# define OS_STOP_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core error stack: OsCore_Core0_Error */
/* User: [ErrorHook_OsCore_Core0, OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Error_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core init stack: OsCore_Core0_Init */
/* User: [OsCore_Core0, Os_CoreInitHook_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Init_Dyn, OS_CFG_SIZE_OSCORE_CORE0_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ISR core global stack: OsCore_Core0_Isr_Core */
/* User: [CanIsr_1, CounterIsr_SystemTimerCore0, CanIsr_2, Lin_Channel_1_RX_Receive_Interrupt, CanIsr_0, Lin_Channel_1_EX_Extended_Error_Interrupt, Lin_Channel_1_TX_Transmit_Interrupt, Uart0_Rx_Isr, Uart0_Tx_Isr, Uart0_Err_Isr, XSignalIsr_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core kernel stack: OsCore_Core0_Kernel */
/* User: [OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Kernel_Dyn, OS_CFG_SIZE_OSCORE_CORE0_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core shutdown stack: OsCore_Core0_Shutdown */
/* User: [OsCore_Core0, ShutdownHook_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Shutdown_Dyn, OS_CFG_SIZE_OSCORE_CORE0_SHUTDOWN_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core startup stack: OsCore_Core0_Startup */
/* User: [OsCore_Core0, StartupHook_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Startup_Dyn, OS_CFG_SIZE_OSCORE_CORE0_STARTUP_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio0 */
/* User: [Core0_OsTask_1ms] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio0_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO0_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio6 */
/* User: [Default_Init_Task_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio6_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO6_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio7 */
/* User: [IdleTask_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio7_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO7_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core error stack: OsCore_Core1_Error */
/* User: [ErrorHook_OsCore_Core1, OsCore_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core1_Error_Dyn, OS_CFG_SIZE_OSCORE_CORE1_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core init stack: OsCore_Core1_Init */
/* User: [OsCore_Core1, Os_CoreInitHook_OsCore_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core1_Init_Dyn, OS_CFG_SIZE_OSCORE_CORE1_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ISR core global stack: OsCore_Core1_Isr_Core */
/* User: [CounterIsr_SystemTimerCore1, KEY_EVENT_Isr, XSignalIsr_OsCore_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core1_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE_CORE1_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core kernel stack: OsCore_Core1_Kernel */
/* User: [OsCore_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core1_Kernel_Dyn, OS_CFG_SIZE_OSCORE_CORE1_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core shutdown stack: OsCore_Core1_Shutdown */
/* User: [OsCore_Core1, ShutdownHook_OsCore_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core1_Shutdown_Dyn, OS_CFG_SIZE_OSCORE_CORE1_SHUTDOWN_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core startup stack: OsCore_Core1_Startup */
/* User: [OsCore_Core1, StartupHook_OsCore_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core1_Startup_Dyn, OS_CFG_SIZE_OSCORE_CORE1_STARTUP_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE1_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core1_Task_Prio2 */
/* User: [Default_BSW_Async_Task_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core1_Task_Prio2_Dyn, OS_CFG_SIZE_OSCORE_CORE1_TASK_PRIO2_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE1_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE1_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core1_Task_Prio5 */
/* User: [Default_Init_Task_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core1_Task_Prio5_Dyn, OS_CFG_SIZE_OSCORE_CORE1_TASK_PRIO5_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE1_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE1_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core1_Task_Prio7 */
/* User: [IdleTask_OsCore_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core1_Task_Prio7_Dyn, OS_CFG_SIZE_OSCORE_CORE1_TASK_PRIO7_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE1_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core error stack: OsCore_Core2_Error */
/* User: [ErrorHook_OsCore_Core2, OsCore_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core2_Error_Dyn, OS_CFG_SIZE_OSCORE_CORE2_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core init stack: OsCore_Core2_Init */
/* User: [OsCore_Core2, Os_CoreInitHook_OsCore_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core2_Init_Dyn, OS_CFG_SIZE_OSCORE_CORE2_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ISR core global stack: OsCore_Core2_Isr_Core */
/* User: [XSignalIsr_OsCore_Core2, CounterIsr_SystemTimerCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core2_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE_CORE2_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core kernel stack: OsCore_Core2_Kernel */
/* User: [OsCore_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core2_Kernel_Dyn, OS_CFG_SIZE_OSCORE_CORE2_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core shutdown stack: OsCore_Core2_Shutdown */
/* User: [OsCore_Core2, ShutdownHook_OsCore_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core2_Shutdown_Dyn, OS_CFG_SIZE_OSCORE_CORE2_SHUTDOWN_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core startup stack: OsCore_Core2_Startup */
/* User: [OsCore_Core2, StartupHook_OsCore_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core2_Startup_Dyn, OS_CFG_SIZE_OSCORE_CORE2_STARTUP_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core2_Task_Prio3 */
/* User: [Default_BSW_Async_Task_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core2_Task_Prio3_Dyn, OS_CFG_SIZE_OSCORE_CORE2_TASK_PRIO3_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE2_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core2_Task_Prio4 */
/* User: [Default_Init_Task_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core2_Task_Prio4_Dyn, OS_CFG_SIZE_OSCORE_CORE2_TASK_PRIO4_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE2_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE2_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core2_Task_Prio7 */
/* User: [IdleTask_OsCore_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core2_Task_Prio7_Dyn, OS_CFG_SIZE_OSCORE_CORE2_TASK_PRIO7_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE2_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Stack configuration data: Default_BSW_Async_Task_Core0 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Default_BSW_Async_Task_Core0;

/*! Stack configuration data: OsCore_Core0_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Error;

/*! Stack configuration data: OsCore_Core0_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Init;

/*! Stack configuration data: OsCore_Core0_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Isr_Core;

/*! Stack configuration data: OsCore_Core0_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Kernel;

/*! Stack configuration data: OsCore_Core0_Shutdown */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Shutdown;

/*! Stack configuration data: OsCore_Core0_Startup */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Startup;

/*! Stack configuration data: OsCore_Core0_Task_Prio0 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio0;

/*! Stack configuration data: OsCore_Core0_Task_Prio6 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio6;

/*! Stack configuration data: OsCore_Core0_Task_Prio7 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio7;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Stack configuration data: OsCore_Core1_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core1_Error;

/*! Stack configuration data: OsCore_Core1_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core1_Init;

/*! Stack configuration data: OsCore_Core1_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core1_Isr_Core;

/*! Stack configuration data: OsCore_Core1_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core1_Kernel;

/*! Stack configuration data: OsCore_Core1_Shutdown */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core1_Shutdown;

/*! Stack configuration data: OsCore_Core1_Startup */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core1_Startup;

/*! Stack configuration data: OsCore_Core1_Task_Prio2 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core1_Task_Prio2;

/*! Stack configuration data: OsCore_Core1_Task_Prio5 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core1_Task_Prio5;

/*! Stack configuration data: OsCore_Core1_Task_Prio7 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core1_Task_Prio7;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Stack configuration data: OsCore_Core2_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core2_Error;

/*! Stack configuration data: OsCore_Core2_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core2_Init;

/*! Stack configuration data: OsCore_Core2_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core2_Isr_Core;

/*! Stack configuration data: OsCore_Core2_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core2_Kernel;

/*! Stack configuration data: OsCore_Core2_Shutdown */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core2_Shutdown;

/*! Stack configuration data: OsCore_Core2_Startup */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core2_Startup;

/*! Stack configuration data: OsCore_Core2_Task_Prio3 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core2_Task_Prio3;

/*! Stack configuration data: OsCore_Core2_Task_Prio4 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core2_Task_Prio4;

/*! Stack configuration data: OsCore_Core2_Task_Prio7 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core2_Task_Prio7;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_STACK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.h
 *********************************************************************************************************************/
