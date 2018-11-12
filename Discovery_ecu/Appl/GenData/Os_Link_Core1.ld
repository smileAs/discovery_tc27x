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
 *              File: Os_Link_Core1.ld
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
/**********************************************************************************************************************
 *  CODE SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_INTVEC_CODE )
. = ALIGN(32);
_OS_INTVEC_CORE1_CODE_START = ABSOLUTE(.);
*(*.OS_INTVEC_CORE1_CODE)
. = ALIGN(32);
_OS_INTVEC_CORE1_CODE_END = ABSOLUTE(.);
#endif

#if defined ( OS_LINK_EXCVEC_CODE )
. = ALIGN(32);
_OS_EXCVEC_CORE1_CODE_START = ABSOLUTE(.);
*(*.OS_EXCVEC_CORE1_CODE)
. = ALIGN(32);
_OS_EXCVEC_CORE1_CODE_END = ABSOLUTE(.);
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_CODE_START = ABSOLUTE(.);
*(*.OS_Default_BSW_Async_Task_Core1_CODE)
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_CODE_END = ABSOLUTE(.);
. += 16;
. = ALIGN(8);
_OS_Default_Init_Task_Core1_CODE_START = ABSOLUTE(.);
*(*.OS_Default_Init_Task_Core1_CODE)
. = ALIGN(8);
_OS_Default_Init_Task_Core1_CODE_END = ABSOLUTE(.);
. += 16;
. = ALIGN(8);
_OS_KEY_EVENT_CODE_START = ABSOLUTE(.);
*(*.OS_KEY_EVENT_CODE)
. = ALIGN(8);
_OS_KEY_EVENT_CODE_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_EXCVEC_CODE
# undef OS_LINK_EXCVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_FAR )
. = ALIGN(8);
_OS_CORE1_CONST_START = ABSOLUTE(.);
*(*.OS_CORE1_CONST)
. = ALIGN(8);
_OS_CORE1_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_NEAR )
. = ALIGN(8);
_OS_CORE1_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_CORE1_CONST_FAST)
. = ALIGN(8);
_OS_CORE1_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_INTVEC_CONST )
. = ALIGN(8);
_OS_INTVEC_CORE1_CONST_START = ABSOLUTE(.);
*(*.OS_INTVEC_CORE1_CONST)
. = ALIGN(8);
_OS_INTVEC_CORE1_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_EXCVEC_CONST )
. = ALIGN(8);
_OS_EXCVEC_CORE1_CONST_START = ABSOLUTE(.);
*(*.OS_EXCVEC_CORE1_CONST)
. = ALIGN(8);
_OS_EXCVEC_CORE1_CONST_END = ABSOLUTE(.);
. += 16;
#endif


#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_CONST_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_CONST)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_CONST_FAST)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1_FAR )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_CONST_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_CONST)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1_NEAR )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_CONST_FAST)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1
# undef OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1
#endif

#ifdef OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1_FAR
# undef OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1_FAR
#endif

#ifdef OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1_NEAR
# undef OS_LINK_CONST_APP_UNTRUSTED_BSW_CORE1_NEAR
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1 ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR )
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_CONST_START = ABSOLUTE(.);
*(*.OS_Default_BSW_Async_Task_Core1_CONST)
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1 ) || defined ( OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR )
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_Default_BSW_Async_Task_Core1_CONST_FAST)
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_FAR )
. = ALIGN(8);
_OS_Default_Init_Task_Core1_CONST_START = ABSOLUTE(.);
*(*.OS_Default_Init_Task_Core1_CONST)
. = ALIGN(8);
_OS_Default_Init_Task_Core1_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_NEAR )
. = ALIGN(8);
_OS_Default_Init_Task_Core1_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_Default_Init_Task_Core1_CONST_FAST)
. = ALIGN(8);
_OS_Default_Init_Task_Core1_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_NEAR
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1_FAR )
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_CONST_START = ABSOLUTE(.);
*(*.OS_IdleTask_OsCore_Core1_CONST)
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1_NEAR )
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_IdleTask_OsCore_Core1_CONST_FAST)
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1_FAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1_FAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1_NEAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_CORE1_NEAR
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1 ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR )
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_CONST_START = ABSOLUTE(.);
*(*.OS_CounterIsr_SystemTimerCore1_CONST)
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1 ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR )
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_CounterIsr_SystemTimerCore1_CONST_FAST)
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_KEY_EVENT_ISR ) || defined ( OS_LINK_CONST_ISR_KEY_EVENT_ISR_FAR )
. = ALIGN(8);
_OS_KEY_EVENT_Isr_CONST_START = ABSOLUTE(.);
*(*.OS_KEY_EVENT_Isr_CONST)
. = ALIGN(8);
_OS_KEY_EVENT_Isr_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_KEY_EVENT_ISR ) || defined ( OS_LINK_CONST_ISR_KEY_EVENT_ISR_NEAR )
. = ALIGN(8);
_OS_KEY_EVENT_Isr_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_KEY_EVENT_Isr_CONST_FAST)
. = ALIGN(8);
_OS_KEY_EVENT_Isr_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CONST_ISR_KEY_EVENT_ISR
# undef OS_LINK_CONST_ISR_KEY_EVENT_ISR
#endif

#ifdef OS_LINK_CONST_ISR_KEY_EVENT_ISR_FAR
# undef OS_LINK_CONST_ISR_KEY_EVENT_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_KEY_EVENT_ISR_NEAR
# undef OS_LINK_CONST_ISR_KEY_EVENT_ISR_NEAR
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1 ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1_FAR )
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_CONST_START = ABSOLUTE(.);
*(*.OS_XSignalIsr_OsCore_Core1_CONST)
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1 ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1_NEAR )
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_XSignalIsr_OsCore_Core1_CONST_FAST)
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1
# undef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1
#endif

#ifdef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1_FAR
# undef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1_FAR
#endif

#ifdef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1_NEAR
# undef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE_CORE1_NEAR
#endif



#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_APP
# undef OS_LINK_CONST_APP
#endif

#ifdef OS_LINK_CONST_TASK
# undef OS_LINK_CONST_TASK
#endif

#ifdef OS_LINK_CONST_ISR
# undef OS_LINK_CONST_ISR
#endif

#ifdef OS_LINK_CONST_KERNEL
# undef OS_LINK_CONST_KERNEL
#endif

#ifdef OS_LINK_CONST_KERNEL_FAR
# undef OS_LINK_CONST_KERNEL_FAR
#endif

#ifdef OS_LINK_CONST_KERNEL_NEAR
# undef OS_LINK_CONST_KERNEL_NEAR
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif

#ifdef OS_LINK_EXCVEC_CONST
# undef OS_LINK_EXCVEC_CONST
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_INIT )
. = ALIGN(8);
_OS_CORE1_VAR_START = ABSOLUTE(.);
*(*.OS_CORE1_VAR)
. = ALIGN(8);
_OS_CORE1_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT )
. = ALIGN(8);
_OS_CORE1_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_CORE1_VAR_NOINIT)
. = ALIGN(8);
_OS_CORE1_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT )
. = ALIGN(8);
_OS_CORE1_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_CORE1_VAR_FAST)
. = ALIGN(8);
_OS_CORE1_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT )
. = ALIGN(8);
_OS_CORE1_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_CORE1_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_CORE1_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT )
. = ALIGN(8);
_OS_CORE1_VAR_NOCACHE_START = ABSOLUTE(.);
*(*.OS_CORE1_VAR_NOCACHE)
. = ALIGN(8);
_OS_CORE1_VAR_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT )
. = ALIGN(8);
_OS_CORE1_VAR_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_CORE1_VAR_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_CORE1_VAR_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT )
. = ALIGN(8);
_OS_CORE1_VAR_FAST_NOCACHE_START = ABSOLUTE(.);
*(*.OS_CORE1_VAR_FAST_NOCACHE)
. = ALIGN(8);
_OS_CORE1_VAR_FAST_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT )
. = ALIGN(8);
_OS_CORE1_VAR_FAST_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_CORE1_VAR_FAST_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_CORE1_VAR_FAST_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_FAR )
. = ALIGN(8);
_OS_PUBLIC_CORE1_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_PUBLIC_CORE1_VAR_NOINIT)
. = ALIGN(8);
_OS_PUBLIC_CORE1_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_NEAR )
. = ALIGN(8);
_OS_PUBLIC_CORE1_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_PUBLIC_CORE1_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_PUBLIC_CORE1_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_FAR )
. = ALIGN(8);
_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_NEAR )
. = ALIGN(8);
_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_FAR )
. = ALIGN(8);
_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_NEAR )
. = ALIGN(8);
_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_ALL_START = ABSOLUTE(.);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE_INIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE_NOINIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_NOINIT)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE_ZERO_INIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE_INIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_FAST)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE_NOINIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE_ZERO_INIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE_INIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE_NOINIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE_ZERO_INIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_NOCACHE_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE_INIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_NOCACHE_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_FAST_NOCACHE)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE_NOINIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_FAST_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE_ZERO_INIT )
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_NOCACHE_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_SystemApplication_OsCore_Core1_VAR_FAST_NOCACHE_ZERO_INIT)
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_FAST_NOCACHE_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1
. = ALIGN(8);
_OS_SystemApplication_OsCore_Core1_VAR_ALL_END = ABSOLUTE(.);
. += 16;
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE1_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_ALL_START = ABSOLUTE(.);
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE_INIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE_NOINIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_NOINIT)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE_ZERO_INIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_ZERO_INIT)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE_INIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_FAST)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE_NOINIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE_ZERO_INIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE_INIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_NOCACHE_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_NOCACHE)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE_NOINIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE_ZERO_INIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_NOCACHE_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE_INIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_NOCACHE_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_FAST_NOCACHE)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE_NOINIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_FAST_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1 ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE_ZERO_INIT )
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_NOCACHE_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_Untrusted_BSW_Core1_VAR_FAST_NOCACHE_ZERO_INIT)
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_FAST_NOCACHE_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1
. = ALIGN(8);
_OS_Untrusted_BSW_Core1_VAR_ALL_END = ABSOLUTE(.);
. += 16;
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE_INIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE_INIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_UNTRUSTED_BSW_CORE1_NEAR_NOCACHE_ZERO_INIT
#endif




#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR_INIT )
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_START = ABSOLUTE(.);
*(*.OS_Default_BSW_Async_Task_Core1_VAR)
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR_NOINIT )
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_Default_BSW_Async_Task_Core1_VAR_NOINIT)
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR_ZERO_INIT )
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_Default_BSW_Async_Task_Core1_VAR_ZERO_INIT)
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR_INIT )
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_Default_BSW_Async_Task_Core1_VAR_FAST)
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR_NOINIT )
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_Default_BSW_Async_Task_Core1_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR_ZERO_INIT )
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_FAST_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_Default_BSW_Async_Task_Core1_VAR_FAST_ZERO_INIT)
. = ALIGN(8);
_OS_Default_BSW_Async_Task_Core1_VAR_FAST_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_FAR_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_BSW_ASYNC_TASK_CORE1_NEAR_ZERO_INIT
#endif




#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_INIT )
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_START = ABSOLUTE(.);
*(*.OS_Default_Init_Task_Core1_VAR)
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOINIT )
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_Default_Init_Task_Core1_VAR_NOINIT)
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_ZERO_INIT )
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_Default_Init_Task_Core1_VAR_ZERO_INIT)
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_INIT )
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_Default_Init_Task_Core1_VAR_FAST)
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOINIT )
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_Default_Init_Task_Core1_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_ZERO_INIT )
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT)
. = ALIGN(8);
_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_ZERO_INIT
#endif




#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR_INIT )
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_START = ABSOLUTE(.);
*(*.OS_IdleTask_OsCore_Core1_VAR)
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR_NOINIT )
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_IdleTask_OsCore_Core1_VAR_NOINIT)
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR_ZERO_INIT )
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_IdleTask_OsCore_Core1_VAR_ZERO_INIT)
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR_INIT )
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_IdleTask_OsCore_Core1_VAR_FAST)
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR_NOINIT )
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_IdleTask_OsCore_Core1_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR_ZERO_INIT )
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_FAST_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_IdleTask_OsCore_Core1_VAR_FAST_ZERO_INIT)
. = ALIGN(8);
_OS_IdleTask_OsCore_Core1_VAR_FAST_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_FAR_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_CORE1_NEAR_ZERO_INIT
#endif




#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR_INIT )
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_START = ABSOLUTE(.);
*(*.OS_CounterIsr_SystemTimerCore1_VAR)
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR_NOINIT )
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_CounterIsr_SystemTimerCore1_VAR_NOINIT)
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR_ZERO_INIT )
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_CounterIsr_SystemTimerCore1_VAR_ZERO_INIT)
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR_INIT )
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_CounterIsr_SystemTimerCore1_VAR_FAST)
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR_NOINIT )
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_CounterIsr_SystemTimerCore1_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR_ZERO_INIT )
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_FAST_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_CounterIsr_SystemTimerCore1_VAR_FAST_ZERO_INIT)
. = ALIGN(8);
_OS_CounterIsr_SystemTimerCore1_VAR_FAST_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_FAR_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMERCORE1_NEAR_ZERO_INIT
#endif




#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR_INIT )
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_START = ABSOLUTE(.);
*(*.OS_KEY_EVENT_Isr_VAR)
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR_NOINIT )
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_KEY_EVENT_Isr_VAR_NOINIT)
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR_ZERO_INIT )
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_KEY_EVENT_Isr_VAR_ZERO_INIT)
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR_INIT )
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_KEY_EVENT_Isr_VAR_FAST)
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR_NOINIT )
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_KEY_EVENT_Isr_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR_ZERO_INIT )
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_FAST_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_KEY_EVENT_Isr_VAR_FAST_ZERO_INIT)
. = ALIGN(8);
_OS_KEY_EVENT_Isr_VAR_FAST_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR_INIT
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR_INIT
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR_NOINIT
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR_ZERO_INIT
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR_FAR_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR_INIT
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR_NOINIT
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR_ZERO_INIT
# undef OS_LINK_VAR_ISR_KEY_EVENT_ISR_NEAR_ZERO_INIT
#endif




#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR_INIT )
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_START = ABSOLUTE(.);
*(*.OS_XSignalIsr_OsCore_Core1_VAR)
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR_NOINIT )
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_XSignalIsr_OsCore_Core1_VAR_NOINIT)
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR_ZERO_INIT )
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_XSignalIsr_OsCore_Core1_VAR_ZERO_INIT)
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR_INIT )
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_XSignalIsr_OsCore_Core1_VAR_FAST)
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR_NOINIT )
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_XSignalIsr_OsCore_Core1_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR_ZERO_INIT )
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_FAST_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_XSignalIsr_OsCore_Core1_VAR_FAST_ZERO_INIT)
. = ALIGN(8);
_OS_XSignalIsr_OsCore_Core1_VAR_FAST_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR_NOINIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR_ZERO_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_FAR_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR_NOINIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR_ZERO_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE_CORE1_NEAR_ZERO_INIT
#endif



#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif

#ifdef OS_LINK_VAR_APP
# undef OS_LINK_VAR_APP
#endif

#ifdef OS_LINK_VAR_TASK
# undef OS_LINK_VAR_TASK
#endif

#ifdef OS_LINK_VAR_ISR
# undef OS_LINK_VAR_ISR
#endif

#ifdef OS_LINK_KERNEL_TRACE
# undef OS_LINK_KERNEL_TRACE
#endif

#ifdef OS_LINK_KERNEL_TRACE_FAR
# undef OS_LINK_KERNEL_TRACE_FAR
#endif

#ifdef OS_LINK_KERNEL_TRACE_NEAR
# undef OS_LINK_KERNEL_TRACE_NEAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS
# undef OS_LINK_KERNEL_BARRIERS
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_FAR
# undef OS_LINK_KERNEL_BARRIERS_FAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_NEAR
# undef OS_LINK_KERNEL_BARRIERS_NEAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS
# undef OS_LINK_KERNEL_CORESTATUS
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_FAR
# undef OS_LINK_KERNEL_CORESTATUS_FAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_NEAR
# undef OS_LINK_KERNEL_CORESTATUS_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE
# undef OS_LINK_VAR_KERNEL_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif


