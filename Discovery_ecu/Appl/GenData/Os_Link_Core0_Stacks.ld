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
 *              File: Os_Link_Core0_Stacks.ld
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
/**********************************************************************************************************************
 *  STACK SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_KERNEL_STACKS )
_OS_CORE0_STACKS_START = ABSOLUTE(.);

/* Stack: Default_BSW_Async_Task_Core0 (16384 Byte) */
. = ALIGN(8);
_OS_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT)
. = ALIGN(8);
_OS_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;

/* Stack: OsCore_Core0_Error (256 Byte) */
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT)
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;

/* Stack: OsCore_Core0_Init (1024 Byte) */
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT)
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;

/* Stack: OsCore_Core0_Isr_Core (2048 Byte) */
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT)
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;

/* Stack: OsCore_Core0_Kernel (2048 Byte) */
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT)
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;

/* Stack: OsCore_Core0_Shutdown (256 Byte) */
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT)
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;

/* Stack: OsCore_Core0_Startup (256 Byte) */
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT)
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;

/* Stack: OsCore_Core0_Task_Prio5 (1024 Byte) */
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT)
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;

/* Stack: OsCore_Core0_Task_Prio6 (2048 Byte) */
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT)
. = ALIGN(8);
_OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;

_OS_CORE0_STACKS_END = ABSOLUTE(.);
_OS_CORE0_STACKS_END_ALIAS = (_OS_CORE0_STACKS_END & ~ 0xF0000000) | 0xD0000000;

#endif

#ifdef OS_LINK_KERNEL_STACKS
# undef OS_LINK_KERNEL_STACKS
#endif


