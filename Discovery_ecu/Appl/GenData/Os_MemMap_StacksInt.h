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
 *              File: Os_MemMap_StacksInt.h
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

#ifdef OS_START_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_CORE0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE1_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE1_INIT_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE1_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE1_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE1_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE1_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE1_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE1_TASK_PRIO1_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE1_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE1_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE1_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE1_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE1_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE1_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE1_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE1_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE1_TASK_PRIO4_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE1_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE1_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE1_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE1_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE1_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE1_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE1_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE1_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE1_TASK_PRIO6_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE1_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE1_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE1_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE1_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE1_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE1_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE2_ERROR_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE2_INIT_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE2_INIT_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE2_KERNEL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE2_SHUTDOWN_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE2_STARTUP_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE2_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE2_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE2_TASK_PRIO2_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE2_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE2_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE2_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE2_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE2_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE2_TASK_PRIO2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE2_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STACK_OSCORE_CORE2_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STACK_OSCORE_CORE2_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_STACK_OSCORE_CORE2_TASK_PRIO6_VAR_NOINIT" awB 8
# undef OS_START_SEC_STACK_OSCORE_CORE2_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STACK_OSCORE_CORE2_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STACK_OSCORE_CORE2_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_STACK_OSCORE_CORE2_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_STACK_OSCORE_CORE2_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STACK_OSCORE_CORE2_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


