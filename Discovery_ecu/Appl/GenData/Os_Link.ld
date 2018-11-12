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
 *              File: Os_Link.ld
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
 *  CODE SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CODE )
. = ALIGN(8);
_OS_CODE_START = ABSOLUTE(.);
*(*.OS_CODE)
. = ALIGN(8);
_OS_CODE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_INTVEC_CODE )
. = ALIGN(32);
_OS_INTVEC_CODE_START = ABSOLUTE(.);
*(*.OS_INTVEC_CODE)
. = ALIGN(32);
_OS_INTVEC_CODE_END = ABSOLUTE(.);
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
. = ALIGN(8);
_OS_ERRORHOOK_CODE_START = ABSOLUTE(.);
*(*.OS_ERRORHOOK_CODE)
. = ALIGN(8);
_OS_ERRORHOOK_CODE_END = ABSOLUTE(.);
. += 16;
. = ALIGN(8);
_OS_OS_COREINITHOOK_CODE_START = ABSOLUTE(.);
*(*.OS_OS_COREINITHOOK_CODE)
. = ALIGN(8);
_OS_OS_COREINITHOOK_CODE_END = ABSOLUTE(.);
. += 16;
. = ALIGN(8);
_OS_PANICHOOK_CODE_START = ABSOLUTE(.);
*(*.OS_PANICHOOK_CODE)
. = ALIGN(8);
_OS_PANICHOOK_CODE_END = ABSOLUTE(.);
. += 16;
. = ALIGN(8);
_OS_SHUTDOWNHOOK_CODE_START = ABSOLUTE(.);
*(*.OS_SHUTDOWNHOOK_CODE)
. = ALIGN(8);
_OS_SHUTDOWNHOOK_CODE_END = ABSOLUTE(.);
. += 16;
. = ALIGN(8);
_OS_STARTUPHOOK_CODE_START = ABSOLUTE(.);
*(*.OS_STARTUPHOOK_CODE)
. = ALIGN(8);
_OS_STARTUPHOOK_CODE_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CODE
# undef OS_LINK_CODE
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_FAR )
. = ALIGN(8);
_OS_CONST_START = ABSOLUTE(.);
*(*.OS_CONST)
. = ALIGN(8);
_OS_CONST_END = ABSOLUTE(.);
. += 16;
. = ALIGN(8);
_OS_GLOBALSHARED_CONST_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_CONST)
. = ALIGN(8);
_OS_GLOBALSHARED_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_GLOBALSHARED ) || defined ( OS_LINK_CONST_GLOBALSHARED_NEAR )
. = ALIGN(8);
_OS_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_CONST_FAST)
. = ALIGN(8);
_OS_CONST_FAST_END = ABSOLUTE(.);
. += 16;
. = ALIGN(8);
_OS_GLOBALSHARED_CONST_FAST_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_CONST_FAST)
. = ALIGN(8);
_OS_GLOBALSHARED_CONST_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_INTVEC_CONST )
. = ALIGN(8);
_OS_INTVEC_CONST_START = ABSOLUTE(.);
*(*.OS_INTVEC_CONST)
. = ALIGN(8);
_OS_INTVEC_CONST_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED
# undef OS_LINK_CONST_GLOBALSHARED
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_NEAR
# undef OS_LINK_CONST_GLOBALSHARED_NEAR
#endif

#ifdef OS_LINK_CONST_GLOBALSHARED_FAR
# undef OS_LINK_CONST_GLOBALSHARED_FAR
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif


/**********************************************************************************************************************
 *  KERNEL VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_INIT )
. = ALIGN(8);
_OS_VAR_NOCACHE_START = ABSOLUTE(.);
*(*.OS_VAR_NOCACHE)
. = ALIGN(8);
_OS_VAR_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOINIT )
. = ALIGN(8);
_OS_VAR_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_VAR_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_VAR_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_INIT )
. = ALIGN(8);
_OS_VAR_FAST_NOCACHE_START = ABSOLUTE(.);
*(*.OS_VAR_FAST_NOCACHE)
. = ALIGN(8);
_OS_VAR_FAST_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOINIT )
. = ALIGN(8);
_OS_VAR_FAST_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_VAR_FAST_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_VAR_FAST_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_INIT
# undef OS_LINK_VAR_KERNEL_FAR_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOINIT
#endif


/**********************************************************************************************************************
 *  GLOBALSHARED VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_INIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_INIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_NOCACHE_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_NOCACHE)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_NOINIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_NOINIT_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_NOINIT)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_NOINIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_ZERO_INIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_ZERO_INIT)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_ZERO_INIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_INIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_FAST)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_INIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_NOCACHE_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_FAST_NOCACHE)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_NOCACHE_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_NOINIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_NOINIT_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_FAST_NOINIT)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_NOINIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_ZERO_INIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_GLOBALSHARED ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_ZERO_INIT )
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_START = ABSOLUTE(.);
*(*.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT)
. = ALIGN(8);
_OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_END = ABSOLUTE(.);
. += 16;
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED
# undef OS_LINK_VAR_GLOBALSHARED
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR
# undef OS_LINK_VAR_GLOBALSHARED_NEAR
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_NEAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR
# undef OS_LINK_VAR_GLOBALSHARED_FAR
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_GLOBALSHARED_FAR_NOCACHE_ZERO_INIT
#endif


/**********************************************************************************************************************
 *  CORESHARED VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_LINK_VAR_CORESHARED
# undef OS_LINK_VAR_CORESHARED
#endif


/**********************************************************************************************************************
 *  APPSHARED VAR SECTIONS
 *********************************************************************************************************************/

#ifdef OS_LINK_VAR_APPSHARED
# undef OS_LINK_VAR_APPSHARED
#endif

#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif


