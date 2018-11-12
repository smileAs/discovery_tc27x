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
 *              File: Os_Core_Lcfg.c
 *   Generation Time: 2018-08-07 08:44:58
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

#define OS_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Core_Cfg.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Barrier_Lcfg.h"
#include "Os_Common.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Resource_Lcfg.h"
#include "Os_Scheduler_Lcfg.h"
#include "Os_Spinlock_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Core_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Kernel_Lcfg.h"


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

#define OS_START_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic core status: OsCore_Core0 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore_Core0_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic core status: OsCore_Core1 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore_Core1_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORESTATUS_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic core status: OsCore_Core2 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore_Core2_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic core boot barrier: OsCore_Core0 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore_Core0_BootBarrier_Dyn;

/*! Dynamic core boot barrier: OsCore_Core1 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore_Core1_BootBarrier_Dyn;

/*! Dynamic core boot barrier: OsCore_Core2 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore_Core2_BootBarrier_Dyn;

#define OS_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic core data: OsCore_Core0 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore_Core0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic core data: OsCore_Core1 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore_Core1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic core data: OsCore_Core2 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore_Core2_Dyn;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for core hooks: OsCore_Core0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core0_HookRefs[OS_CFG_NUM_CORE_OSCORE_CORE0_HOOKS + 1] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore_Core0),
  OS_HOOK_CASTCONFIG_CALLBACK_2_HOOK(OsCfg_Hook_StartupHook_OsCore_Core0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore_Core0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore_Core0),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore_Core0 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core0_AppRefs[OS_CFG_NUM_CORE_OSCORE_CORE0_APPS + 1] =
{
  (Os_AppConfigRefType) &OsCfg_App_Untrusted_BSW_Core0,
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore_Core0 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core0_IocRefs[OS_CFG_NUM_CORE_OSCORE_CORE0_IOCS + 1] =
{
  OS_IOC_CASTCONFIG_IOC32SEND_2_IOC(OsCfg_IocSend_OsIocCommunication),
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore_Core0 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core0_BarrierRefs[OS_CFG_NUM_BARRIERS + 1] =
{
  (Os_BarrierBaseConfigRefType) &OsCfg_Barrier_OsBarrier_OsCore_Core0,
  NULL_PTR
};

/*! Object reference table for core resources: OsCore_Core0 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core0_ResourceRefs[OS_CFG_NUM_CORE_OSCORE_CORE0_RESOURCES + 1] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_OsResource),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore_Core0 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core0_StackRefs[OS_CFG_NUM_CORE_OSCORE_CORE0_STACKS + 1] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_Default_BSW_Async_Task_Core0,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core0_Error,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core0_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core0_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core0_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core0_Shutdown,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core0_Startup,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core0_Task_Prio5,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core0_Task_Prio6,
  NULL_PTR
};

/*! Core configuration data: OsCore_Core0 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore_Core0 =
{
  /* .Core              = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore_Core0_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore_Core0,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore_Core0_InterruptSourceRefs,
    /* .InterruptSourceCount = */ OS_CFG_NUM_CORE_OSCORE_CORE0_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_0,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ TRUE,
    /* .IsMasterStartAllowed = */ TRUE,
    /* .HasPrivilegedHardwareAccess = */ TRUE
  },
  /* .Dyn               = */ &OsCfg_Core_OsCore_Core0_Dyn,
  /* .Scheduler         = */ &OsCfg_Scheduler_OsCore_Core0,
  /* .IdleTask          = */ &OsCfg_Task_IdleTask_OsCore_Core0,
  /* .KernelApp         = */ &OsCfg_App_SystemApplication_OsCore_Core0,
  /* .KernelStack       = */ &OsCfg_Stack_OsCore_Core0_Kernel,
  /* .PreStartTask      = */ NULL_PTR,
  /* .StartupHookRef    = */ &OsCfg_Hook_StartupHook_OsCore_Core0,
  /* .ShutdownHookRef   = */ &OsCfg_Hook_ShutdownHook_OsCore_Core0,
  /* .ErrorHookRef      = */ &OsCfg_Hook_ErrorHook_OsCore_Core0,
  /* .ProtectionHookRef = */ NULL_PTR,
  /* .InitHookRef       = */ &OsCfg_Hook_Os_CoreInitHook_OsCore_Core0,
  /* .HookRefs          = */ OsCfg_Core_OsCore_Core0_HookRefs,
  /* .HookCount         = */ OS_CFG_NUM_CORE_OSCORE_CORE0_HOOKS,
  /* .AppRefs           = */ OsCfg_Core_OsCore_Core0_AppRefs,
  /* .AppCount          = */ OS_CFG_NUM_CORE_OSCORE_CORE0_APPS,
  /* .ResourceRefs      = */ OsCfg_Core_OsCore_Core0_ResourceRefs,
  /* .ResourceCount     = */ OS_CFG_NUM_CORE_OSCORE_CORE0_RESOURCES,
  /* .HwConfig          = */ &OsCfg_Hal_CoreAsr_OsCore_Core0,
  /* .MemoryProtection  = */ NULL_PTR,
  /* .OsMpAccessRights  = */ NULL_PTR,
  /* .TimingProtection  = */ NULL_PTR,
  /* .StackRefs         = */ OsCfg_Core_OsCore_Core0_StackRefs,
  /* .StackCount        = */ OS_CFG_NUM_CORE_OSCORE_CORE0_STACKS,
  /* .CoreIdx           = */ OS_COREASRCOREIDX_0,
  /* .XSignal           = */ &OsCfg_XSig_OsCore_Core0,
  /* .IocRefs           = */ OsCfg_Core_OsCore_Core0_IocRefs,
  /* .IocCount          = */ OS_CFG_NUM_CORE_OSCORE_CORE0_IOCS,
  /* .Trace             = */ NULL_PTR,
  /* .Barrier           = */ &OsCfg_Barrier_OsCore_Core0,
  /* .BarrierRefs       = */ OsCfg_Core_OsCore_Core0_BarrierRefs,
  /* .BarrierCount      = */ OS_CFG_NUM_BARRIERS
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for core hooks: OsCore_Core1 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core1_HookRefs[OS_CFG_NUM_CORE_OSCORE_CORE1_HOOKS + 1] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore_Core1),
  OS_HOOK_CASTCONFIG_CALLBACK_2_HOOK(OsCfg_Hook_StartupHook_OsCore_Core1),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore_Core1),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore_Core1),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore_Core1 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core1_AppRefs[OS_CFG_NUM_CORE_OSCORE_CORE1_APPS + 1] =
{
  (Os_AppConfigRefType) &OsCfg_App_Untrusted_BSW_Core1,
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore_Core1 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core1_IocRefs[OS_CFG_NUM_CORE_OSCORE_CORE1_IOCS + 1] =
{
  OS_IOC_CASTCONFIG_IOC32RECEIVE_2_IOC(OsCfg_IocRecv_OsIocCommunication),
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore_Core1 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core1_BarrierRefs[OS_CFG_NUM_BARRIERS + 1] =
{
  (Os_BarrierBaseConfigRefType) &OsCfg_Barrier_OsBarrier_OsCore_Core1,
  NULL_PTR
};

/*! Object reference table for core resources: OsCore_Core1 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core1_ResourceRefs[OS_CFG_NUM_CORE_OSCORE_CORE1_RESOURCES + 1] =
{
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore_Core1 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core1_StackRefs[OS_CFG_NUM_CORE_OSCORE_CORE1_STACKS + 1] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core1_Error,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core1_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core1_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core1_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core1_Shutdown,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core1_Startup,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core1_Task_Prio1,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core1_Task_Prio4,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core1_Task_Prio6,
  NULL_PTR
};

/*! Core configuration data: OsCore_Core1 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore_Core1 =
{
  /* .Core              = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore_Core1_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore_Core1,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore_Core1_InterruptSourceRefs,
    /* .InterruptSourceCount = */ OS_CFG_NUM_CORE_OSCORE_CORE1_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_1,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ FALSE,
    /* .IsMasterStartAllowed = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ FALSE
  },
  /* .Dyn               = */ &OsCfg_Core_OsCore_Core1_Dyn,
  /* .Scheduler         = */ &OsCfg_Scheduler_OsCore_Core1,
  /* .IdleTask          = */ &OsCfg_Task_IdleTask_OsCore_Core1,
  /* .KernelApp         = */ &OsCfg_App_SystemApplication_OsCore_Core1,
  /* .KernelStack       = */ &OsCfg_Stack_OsCore_Core1_Kernel,
  /* .PreStartTask      = */ NULL_PTR,
  /* .StartupHookRef    = */ &OsCfg_Hook_StartupHook_OsCore_Core1,
  /* .ShutdownHookRef   = */ &OsCfg_Hook_ShutdownHook_OsCore_Core1,
  /* .ErrorHookRef      = */ &OsCfg_Hook_ErrorHook_OsCore_Core1,
  /* .ProtectionHookRef = */ NULL_PTR,
  /* .InitHookRef       = */ &OsCfg_Hook_Os_CoreInitHook_OsCore_Core1,
  /* .HookRefs          = */ OsCfg_Core_OsCore_Core1_HookRefs,
  /* .HookCount         = */ OS_CFG_NUM_CORE_OSCORE_CORE1_HOOKS,
  /* .AppRefs           = */ OsCfg_Core_OsCore_Core1_AppRefs,
  /* .AppCount          = */ OS_CFG_NUM_CORE_OSCORE_CORE1_APPS,
  /* .ResourceRefs      = */ OsCfg_Core_OsCore_Core1_ResourceRefs,
  /* .ResourceCount     = */ OS_CFG_NUM_CORE_OSCORE_CORE1_RESOURCES,
  /* .HwConfig          = */ &OsCfg_Hal_CoreAsr_OsCore_Core1,
  /* .MemoryProtection  = */ NULL_PTR,
  /* .OsMpAccessRights  = */ NULL_PTR,
  /* .TimingProtection  = */ NULL_PTR,
  /* .StackRefs         = */ OsCfg_Core_OsCore_Core1_StackRefs,
  /* .StackCount        = */ OS_CFG_NUM_CORE_OSCORE_CORE1_STACKS,
  /* .CoreIdx           = */ OS_COREASRCOREIDX_1,
  /* .XSignal           = */ &OsCfg_XSig_OsCore_Core1,
  /* .IocRefs           = */ OsCfg_Core_OsCore_Core1_IocRefs,
  /* .IocCount          = */ OS_CFG_NUM_CORE_OSCORE_CORE1_IOCS,
  /* .Trace             = */ NULL_PTR,
  /* .Barrier           = */ &OsCfg_Barrier_OsCore_Core1,
  /* .BarrierRefs       = */ OsCfg_Core_OsCore_Core1_BarrierRefs,
  /* .BarrierCount      = */ OS_CFG_NUM_BARRIERS
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for core hooks: OsCore_Core2 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core2_HookRefs[OS_CFG_NUM_CORE_OSCORE_CORE2_HOOKS + 1] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore_Core2),
  OS_HOOK_CASTCONFIG_CALLBACK_2_HOOK(OsCfg_Hook_StartupHook_OsCore_Core2),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore_Core2),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore_Core2),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore_Core2 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core2_AppRefs[OS_CFG_NUM_CORE_OSCORE_CORE2_APPS + 1] =
{
  (Os_AppConfigRefType) &OsCfg_App_Untrusted_BSW_Core2,
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore_Core2 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core2_IocRefs[OS_CFG_NUM_CORE_OSCORE_CORE2_IOCS + 1] =
{
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore_Core2 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core2_BarrierRefs[OS_CFG_NUM_BARRIERS + 1] =
{
  (Os_BarrierBaseConfigRefType) &OsCfg_Barrier_OsBarrier_OsCore_Core2,
  NULL_PTR
};

/*! Object reference table for core resources: OsCore_Core2 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core2_ResourceRefs[OS_CFG_NUM_CORE_OSCORE_CORE2_RESOURCES + 1] =
{
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore_Core2 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore_Core2_StackRefs[OS_CFG_NUM_CORE_OSCORE_CORE2_STACKS + 1] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core2_Error,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core2_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core2_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core2_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core2_Shutdown,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core2_Startup,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core2_Task_Prio2,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core2_Task_Prio3,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore_Core2_Task_Prio6,
  NULL_PTR
};

/*! Core configuration data: OsCore_Core2 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore_Core2 =
{
  /* .Core              = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore_Core2_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore_Core2,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore_Core2_InterruptSourceRefs,
    /* .InterruptSourceCount = */ OS_CFG_NUM_CORE_OSCORE_CORE2_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_2,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ FALSE,
    /* .IsMasterStartAllowed = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ FALSE
  },
  /* .Dyn               = */ &OsCfg_Core_OsCore_Core2_Dyn,
  /* .Scheduler         = */ &OsCfg_Scheduler_OsCore_Core2,
  /* .IdleTask          = */ &OsCfg_Task_IdleTask_OsCore_Core2,
  /* .KernelApp         = */ &OsCfg_App_SystemApplication_OsCore_Core2,
  /* .KernelStack       = */ &OsCfg_Stack_OsCore_Core2_Kernel,
  /* .PreStartTask      = */ NULL_PTR,
  /* .StartupHookRef    = */ &OsCfg_Hook_StartupHook_OsCore_Core2,
  /* .ShutdownHookRef   = */ &OsCfg_Hook_ShutdownHook_OsCore_Core2,
  /* .ErrorHookRef      = */ &OsCfg_Hook_ErrorHook_OsCore_Core2,
  /* .ProtectionHookRef = */ NULL_PTR,
  /* .InitHookRef       = */ &OsCfg_Hook_Os_CoreInitHook_OsCore_Core2,
  /* .HookRefs          = */ OsCfg_Core_OsCore_Core2_HookRefs,
  /* .HookCount         = */ OS_CFG_NUM_CORE_OSCORE_CORE2_HOOKS,
  /* .AppRefs           = */ OsCfg_Core_OsCore_Core2_AppRefs,
  /* .AppCount          = */ OS_CFG_NUM_CORE_OSCORE_CORE2_APPS,
  /* .ResourceRefs      = */ OsCfg_Core_OsCore_Core2_ResourceRefs,
  /* .ResourceCount     = */ OS_CFG_NUM_CORE_OSCORE_CORE2_RESOURCES,
  /* .HwConfig          = */ &OsCfg_Hal_CoreAsr_OsCore_Core2,
  /* .MemoryProtection  = */ NULL_PTR,
  /* .OsMpAccessRights  = */ NULL_PTR,
  /* .TimingProtection  = */ NULL_PTR,
  /* .StackRefs         = */ OsCfg_Core_OsCore_Core2_StackRefs,
  /* .StackCount        = */ OS_CFG_NUM_CORE_OSCORE_CORE2_STACKS,
  /* .CoreIdx           = */ OS_COREASRCOREIDX_2,
  /* .XSignal           = */ &OsCfg_XSig_OsCore_Core2,
  /* .IocRefs           = */ OsCfg_Core_OsCore_Core2_IocRefs,
  /* .IocCount          = */ OS_CFG_NUM_CORE_OSCORE_CORE2_IOCS,
  /* .Trace             = */ NULL_PTR,
  /* .Barrier           = */ &OsCfg_Barrier_OsCore_Core2,
  /* .BarrierRefs       = */ OsCfg_Core_OsCore_Core2_BarrierRefs,
  /* .BarrierCount      = */ OS_CFG_NUM_BARRIERS
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for system spinlocks. */
OS_LOCAL CONST(Os_SpinlockConfigRefType, OS_CONST) OsCfg_SystemSpinlockRefs[OS_CFG_NUM_SYSTEM_SPINLOCKS + 1] =
{
  NULL_PTR
};

/*! Object reference table for core boot barriers. */
CONSTP2VAR(Os_CoreBootBarrierType, AUTOMATIC, OS_CONST) OsCfg_CoreBootBarrierRefs[OS_COREID_COUNT + 1] =
{
  &OsCfg_Core_OsCore_Core0_BootBarrier_Dyn,
  &OsCfg_Core_OsCore_Core1_BootBarrier_Dyn,
  &OsCfg_Core_OsCore_Core2_BootBarrier_Dyn,
  NULL_PTR
};

/*! System configuration data. */
CONST(Os_SystemConfigType, OS_CONST) OsCfg_System =
{
  /* .VersionInfo      = */
  {
    /* .vendorID         = */ OS_VENDOR_ID,
    /* .moduleID         = */ OS_MODULE_ID,
    /* .sw_major_version = */ OS_SW_MAJOR_VERSION,
    /* .sw_minor_version = */ OS_SW_MINOR_VERSION,
    /* .sw_patch_version = */ OS_SW_PATCH_VERSION
  },
  /* .NumberOfAsrCores = */ OS_COREASRCOREIDX_COUNT,
  /* .SpinlockRefs     = */ OsCfg_SystemSpinlockRefs,
  /* .SpinlockCount    = */ OS_CFG_NUM_SYSTEM_SPINLOCKS,
  /* .HwConfig         = */ &OsCfg_Hal_System,
  /* .MemoryProtection = */ NULL_PTR,
  /* .InterruptSourceRefs  = */ OsCfg_Hal_System_InterruptSourceRefs,
  /* .InterruptSourceCount = */ OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS,
  /* .Core2Thread      = */ &OsCfg_Hal_Core2Thread
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Core_Lcfg.c
 *********************************************************************************************************************/
