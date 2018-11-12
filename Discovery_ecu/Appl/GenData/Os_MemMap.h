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
 *              File: Os_MemMap.h
 *   Generation Time: 2018-09-29 15:39:32
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

#include "Os_MemMap_OsCodeInt.h"
#include "Os_MemMap_OsSectionsInt.h"
#include "Os_MemMap_StacksInt.h"

/**********************************************************************************************************************
 *  CODE SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_ERRORHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_ERRORHOOK_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_ERRORHOOK_CODE" ax
# undef OS_START_SEC_ERRORHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_ERRORHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_ERRORHOOK_CODE_OPEN
#  error Section OS_ERRORHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_ERRORHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_ERRORHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_OS_COREINITHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_OS_COREINITHOOK_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_OS_COREINITHOOK_CODE" ax
# undef OS_START_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_OS_COREINITHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_OS_COREINITHOOK_CODE_OPEN
#  error Section OS_OS_COREINITHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_OS_COREINITHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_OS_COREINITHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_PANICHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_PANICHOOK_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_PANICHOOK_CODE" ax
# undef OS_START_SEC_PANICHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_PANICHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_PANICHOOK_CODE_OPEN
#  error Section OS_PANICHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_PANICHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_PANICHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SHUTDOWNHOOK_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_SHUTDOWNHOOK_CODE" ax
# undef OS_START_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SHUTDOWNHOOK_CODE_OPEN
#  error Section OS_SHUTDOWNHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_SHUTDOWNHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SHUTDOWNHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_STARTUPHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_STARTUPHOOK_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_STARTUPHOOK_CODE" ax
# undef OS_START_SEC_STARTUPHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_STARTUPHOOK_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_STARTUPHOOK_CODE_OPEN
#  error Section OS_STARTUPHOOK_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_STARTUPHOOK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_STARTUPHOOK_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_CanIsr_0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CanIsr_0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_CanIsr_0_CODE" ax
# undef OS_START_SEC_CanIsr_0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_CanIsr_0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_CanIsr_0_CODE_OPEN
#  error Section OS_CanIsr_0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CanIsr_0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_CanIsr_0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_CanIsr_1_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CanIsr_1_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_CanIsr_1_CODE" ax
# undef OS_START_SEC_CanIsr_1_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_CanIsr_1_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_CanIsr_1_CODE_OPEN
#  error Section OS_CanIsr_1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CanIsr_1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_CanIsr_1_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_CanIsr_2_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_CanIsr_2_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_CanIsr_2_CODE" ax
# undef OS_START_SEC_CanIsr_2_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_CanIsr_2_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_CanIsr_2_CODE_OPEN
#  error Section OS_CanIsr_2_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_CanIsr_2_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_CanIsr_2_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Default_BSW_Async_Task_Core0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Default_BSW_Async_Task_Core0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_Default_BSW_Async_Task_Core0_CODE" ax
# undef OS_START_SEC_Default_BSW_Async_Task_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Default_BSW_Async_Task_Core0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Default_BSW_Async_Task_Core0_CODE_OPEN
#  error Section OS_Default_BSW_Async_Task_Core0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Default_BSW_Async_Task_Core0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Default_BSW_Async_Task_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Default_BSW_Async_Task_Core1_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Default_BSW_Async_Task_Core1_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_Default_BSW_Async_Task_Core1_CODE" ax
# undef OS_START_SEC_Default_BSW_Async_Task_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Default_BSW_Async_Task_Core1_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Default_BSW_Async_Task_Core1_CODE_OPEN
#  error Section OS_Default_BSW_Async_Task_Core1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Default_BSW_Async_Task_Core1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Default_BSW_Async_Task_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Default_BSW_Async_Task_Core2_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Default_BSW_Async_Task_Core2_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_Default_BSW_Async_Task_Core2_CODE" ax
# undef OS_START_SEC_Default_BSW_Async_Task_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Default_BSW_Async_Task_Core2_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Default_BSW_Async_Task_Core2_CODE_OPEN
#  error Section OS_Default_BSW_Async_Task_Core2_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Default_BSW_Async_Task_Core2_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Default_BSW_Async_Task_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Default_Init_Task_Core0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Default_Init_Task_Core0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_Default_Init_Task_Core0_CODE" ax
# undef OS_START_SEC_Default_Init_Task_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Default_Init_Task_Core0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Default_Init_Task_Core0_CODE_OPEN
#  error Section OS_Default_Init_Task_Core0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Default_Init_Task_Core0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Default_Init_Task_Core0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Default_Init_Task_Core1_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Default_Init_Task_Core1_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_Default_Init_Task_Core1_CODE" ax
# undef OS_START_SEC_Default_Init_Task_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Default_Init_Task_Core1_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Default_Init_Task_Core1_CODE_OPEN
#  error Section OS_Default_Init_Task_Core1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Default_Init_Task_Core1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Default_Init_Task_Core1_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Default_Init_Task_Core2_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Default_Init_Task_Core2_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_Default_Init_Task_Core2_CODE" ax
# undef OS_START_SEC_Default_Init_Task_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Default_Init_Task_Core2_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Default_Init_Task_Core2_CODE_OPEN
#  error Section OS_Default_Init_Task_Core2_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Default_Init_Task_Core2_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Default_Init_Task_Core2_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_KEY_EVENT_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_KEY_EVENT_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_KEY_EVENT_CODE" ax
# undef OS_START_SEC_KEY_EVENT_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_KEY_EVENT_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_KEY_EVENT_CODE_OPEN
#  error Section OS_KEY_EVENT_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_KEY_EVENT_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_KEY_EVENT_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_LinIsr_1_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_LinIsr_1_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_LinIsr_1_CODE" ax
# undef OS_START_SEC_LinIsr_1_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_LinIsr_1_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_LinIsr_1_CODE_OPEN
#  error Section OS_LinIsr_1_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_LinIsr_1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_LinIsr_1_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Uart_IsrError0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Uart_IsrError0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_Uart_IsrError0_CODE" ax
# undef OS_START_SEC_Uart_IsrError0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Uart_IsrError0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Uart_IsrError0_CODE_OPEN
#  error Section OS_Uart_IsrError0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Uart_IsrError0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Uart_IsrError0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Uart_IsrReceive0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Uart_IsrReceive0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_Uart_IsrReceive0_CODE" ax
# undef OS_START_SEC_Uart_IsrReceive0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Uart_IsrReceive0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Uart_IsrReceive0_CODE_OPEN
#  error Section OS_Uart_IsrReceive0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Uart_IsrReceive0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Uart_IsrReceive0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Uart_IsrTransmit0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Uart_IsrTransmit0_CODE_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".text.OS_Uart_IsrTransmit0_CODE" ax
# undef OS_START_SEC_Uart_IsrTransmit0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Uart_IsrTransmit0_CODE /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Uart_IsrTransmit0_CODE_OPEN
#  error Section OS_Uart_IsrTransmit0_CODE is currently not opened and so cannot be closed.
# endif
# undef OS_Uart_IsrTransmit0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Uart_IsrTransmit0_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_GLOBALSHARED_CONST" a
# undef OS_START_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_GLOBALSHARED_CONST" a
# undef OS_START_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_GLOBALSHARED_CONST" a
# undef OS_START_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_GLOBALSHARED_CONST" a
# undef OS_START_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_GLOBALSHARED_CONST" a
# undef OS_START_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_GLOBALSHARED_CONST_FAST" az
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_GLOBALSHARED_CONST_FAST" az
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_GLOBALSHARED_CONST_FAST" az
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_GLOBALSHARED_CONST_FAST" az
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_GLOBALSHARED_CONST_FAST" az
# undef OS_START_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core0_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core0_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core0_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core0_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core0_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core0_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core0_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core0_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core0_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core0_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core1_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core1_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core1_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core1_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core1_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core1_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core1_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core1_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core1_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core1_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core1_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core2_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core2_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core2_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core2_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_SystemApplication_OsCore_Core2_CONST" a
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core2_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core2_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core2_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core2_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_SystemApplication_OsCore_Core2_CONST_FAST" az
# undef OS_START_SEC_SystemApplication_OsCore_Core2_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core0_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core0_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core0_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core0_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core0_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core0_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core0_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_FAST_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core0_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_FAST_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core0_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_FAST_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core0_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core1_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core1_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core1_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core1_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core1_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core1_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core1_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_FAST_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core1_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_FAST_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core1_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_FAST_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core1_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core1_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core2_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core2_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core2_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core2_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".rodata.OS_Untrusted_BSW_Core2_CONST" a
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core2_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_FAST_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core2_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_FAST_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core2_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_FAST_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core2_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_FAST_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_CONST_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zrodata.OS_Untrusted_BSW_Core2_CONST_FAST" az
# undef OS_START_SEC_Untrusted_BSW_Core2_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_CONST_FAST_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_CONST_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_CONST_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_GLOBALSHARED_VAR_FAST" awz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_GLOBALSHARED_VAR_FAST" awz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_GLOBALSHARED_VAR_FAST" awz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_GLOBALSHARED_VAR_FAST" awz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_GLOBALSHARED_VAR_FAST" awz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR_NOCACHE" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR_NOCACHE" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR_NOCACHE" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR_NOCACHE" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_GLOBALSHARED_VAR_NOCACHE" aw
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core0_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core1_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core1_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core1_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core1_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core1_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core2_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core2_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core2_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core2_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_SystemApplication_OsCore_Core2_VAR_FAST" awz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_SystemApplication_OsCore_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOINIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOINIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOINIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core0_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core0_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core0_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core0_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core0_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core0_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core0_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOINIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOINIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOINIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core1_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core1_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core1_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core1_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core1_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core1_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOINIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOINIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOINIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOINIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core2_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core2_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core2_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core2_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zdata.OS_Untrusted_BSW_Core2_VAR_FAST" awz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".zbss.OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT" awBz
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".data.OS_Untrusted_BSW_Core2_VAR_NOCACHE" aw
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_BOOLEAN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_8BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_16BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_16BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_32BIT is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_32BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifdef OS_MEMMAP_SECTION_OPEN
#  error A MemMap section is already open. Nesting is not supported.
# endif
# define OS_MEMMAP_SECTION_OPEN
# define OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
# ifndef MEMMAP_ERROR
#  error Each MemMap include may only perform one action. Include MemMap.h separately for each action.
# endif
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section ".bss.OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT" awB
# undef OS_START_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif

#ifdef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0883 */ /* MD_Os_0883 */
# ifndef OS_MEMMAP_SECTION_OPEN
#  error No MemMap section is currently opened.
# endif
# undef OS_MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# ifndef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Section OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is currently not opened and so cannot be closed.
# endif
# undef OS_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_19.6 */
# pragma section
# undef OS_STOP_SEC_Untrusted_BSW_Core2_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_19.6 */
#endif



