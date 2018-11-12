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
 *              File: Os_Hook_Lcfg.c
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
/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HOOK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "OsInt.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"


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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic hook data: Os_CoreInitHook_OsCore_Core0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_Os_CoreInitHook_OsCore_Core0_Dyn;

/*! Dynamic hook data: StartupHook_OsCore_Core0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_StartupHook_OsCore_Core0_Dyn;

/*! Dynamic hook data: ShutdownHook_OsCore_Core0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ShutdownHook_OsCore_Core0_Dyn;

/*! Dynamic hook data: ErrorHook_OsCore_Core0 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ErrorHook_OsCore_Core0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic hook data: Os_CoreInitHook_OsCore_Core1 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_Os_CoreInitHook_OsCore_Core1_Dyn;

/*! Dynamic hook data: StartupHook_OsCore_Core1 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_StartupHook_OsCore_Core1_Dyn;

/*! Dynamic hook data: ShutdownHook_OsCore_Core1 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ShutdownHook_OsCore_Core1_Dyn;

/*! Dynamic hook data: ErrorHook_OsCore_Core1 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ErrorHook_OsCore_Core1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic hook data: Os_CoreInitHook_OsCore_Core2 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_Os_CoreInitHook_OsCore_Core2_Dyn;

/*! Dynamic hook data: StartupHook_OsCore_Core2 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_StartupHook_OsCore_Core2_Dyn;

/*! Dynamic hook data: ShutdownHook_OsCore_Core2 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ShutdownHook_OsCore_Core2_Dyn;

/*! Dynamic hook data: ErrorHook_OsCore_Core2 */
OS_LOCAL VAR(Os_HookType, OS_VAR_NOINIT) OsCfg_Hook_ErrorHook_OsCore_Core2_Dyn;

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Hook configuration data: Os_CoreInitHook_OsCore_Core0 */
CONST(Os_HookInitHookConfigType, OS_CONST) OsCfg_Hook_Os_CoreInitHook_OsCore_Core0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Init,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_Os_CoreInitHook_OsCore_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_INITHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ TRUE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_INITHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_INITHOOK,
    /* .Id           = */ (Os_HookIdType)0,
    /* .TaskReturn   = */ Os_HookTaskReturn_BeginScheduling
  },
  /* .Callback = */ &Os_CoreInitHook
};

/*! Hook configuration data: StartupHook_OsCore_Core0 */
CONST(Os_HookCallbackConfigType, OS_CONST) OsCfg_Hook_StartupHook_OsCore_Core0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_StartupHook_OsCore_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_StartupHook_OsCore_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Startup,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_StartupHook_OsCore_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_STARTUPHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_STARTUPHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_STARTUPHOOK,
    /* .Id           = */ (Os_HookIdType)1,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &StartupHook
};

/*! Hook configuration data: ShutdownHook_OsCore_Core0 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ShutdownHook_OsCore_Core0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ShutdownHook_OsCore_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_ShutdownHook_OsCore_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Shutdown,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ShutdownHook_OsCore_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_SHUTDOWNHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_SHUTDOWNHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_SHUTDOWNHOOK,
    /* .Id           = */ (Os_HookIdType)2,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &ShutdownHook
};

/*! Hook configuration data: ErrorHook_OsCore_Core0 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ErrorHook_OsCore_Core0 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ErrorHook_OsCore_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_ErrorHook_OsCore_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Error,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ErrorHook_OsCore_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ERRORHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_ERRORHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_ERRORHOOK,
    /* .Id           = */ (Os_HookIdType)3,
    /* .TaskReturn   = */ Os_HookTaskReturn_WithSchedule
  },
  /* .Callback = */ &ErrorHook
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Hook configuration data: Os_CoreInitHook_OsCore_Core1 */
CONST(Os_HookInitHookConfigType, OS_CONST) OsCfg_Hook_Os_CoreInitHook_OsCore_Core1 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core1,
    /* .Context               = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Init,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_Os_CoreInitHook_OsCore_Core1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_INITHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ TRUE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_INITHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_INITHOOK,
    /* .Id           = */ (Os_HookIdType)4,
    /* .TaskReturn   = */ Os_HookTaskReturn_BeginScheduling
  },
  /* .Callback = */ &Os_CoreInitHook
};

/*! Hook configuration data: StartupHook_OsCore_Core1 */
CONST(Os_HookCallbackConfigType, OS_CONST) OsCfg_Hook_StartupHook_OsCore_Core1 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_StartupHook_OsCore_Core1,
    /* .Context               = */ &OsCfg_Hal_Context_StartupHook_OsCore_Core1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Startup,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_StartupHook_OsCore_Core1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_STARTUPHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_STARTUPHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_STARTUPHOOK,
    /* .Id           = */ (Os_HookIdType)5,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &StartupHook
};

/*! Hook configuration data: ShutdownHook_OsCore_Core1 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ShutdownHook_OsCore_Core1 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ShutdownHook_OsCore_Core1,
    /* .Context               = */ &OsCfg_Hal_Context_ShutdownHook_OsCore_Core1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Shutdown,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ShutdownHook_OsCore_Core1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_SHUTDOWNHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_SHUTDOWNHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_SHUTDOWNHOOK,
    /* .Id           = */ (Os_HookIdType)6,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &ShutdownHook
};

/*! Hook configuration data: ErrorHook_OsCore_Core1 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ErrorHook_OsCore_Core1 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ErrorHook_OsCore_Core1,
    /* .Context               = */ &OsCfg_Hal_Context_ErrorHook_OsCore_Core1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Error,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ErrorHook_OsCore_Core1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ERRORHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_ERRORHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_ERRORHOOK,
    /* .Id           = */ (Os_HookIdType)7,
    /* .TaskReturn   = */ Os_HookTaskReturn_WithSchedule
  },
  /* .Callback = */ &ErrorHook
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Hook configuration data: Os_CoreInitHook_OsCore_Core2 */
CONST(Os_HookInitHookConfigType, OS_CONST) OsCfg_Hook_Os_CoreInitHook_OsCore_Core2 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core2,
    /* .Context               = */ &OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core2_Init,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_Os_CoreInitHook_OsCore_Core2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core2,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_INITHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ TRUE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_INITHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_INITHOOK,
    /* .Id           = */ (Os_HookIdType)8,
    /* .TaskReturn   = */ Os_HookTaskReturn_BeginScheduling
  },
  /* .Callback = */ &Os_CoreInitHook
};

/*! Hook configuration data: StartupHook_OsCore_Core2 */
CONST(Os_HookCallbackConfigType, OS_CONST) OsCfg_Hook_StartupHook_OsCore_Core2 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_StartupHook_OsCore_Core2,
    /* .Context               = */ &OsCfg_Hal_Context_StartupHook_OsCore_Core2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core2_Startup,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_StartupHook_OsCore_Core2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core2,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_STARTUPHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_STARTUPHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_STARTUPHOOK,
    /* .Id           = */ (Os_HookIdType)9,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &StartupHook
};

/*! Hook configuration data: ShutdownHook_OsCore_Core2 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ShutdownHook_OsCore_Core2 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ShutdownHook_OsCore_Core2,
    /* .Context               = */ &OsCfg_Hal_Context_ShutdownHook_OsCore_Core2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core2_Shutdown,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ShutdownHook_OsCore_Core2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core2,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_SHUTDOWNHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_SHUTDOWNHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_SHUTDOWNHOOK,
    /* .Id           = */ (Os_HookIdType)10,
    /* .TaskReturn   = */ Os_HookTaskReturn_ToCallerTask
  },
  /* .Callback = */ &ShutdownHook
};

/*! Hook configuration data: ErrorHook_OsCore_Core2 */
CONST(Os_HookStatusHookConfigType, OS_CONST) OsCfg_Hook_ErrorHook_OsCore_Core2 =
{
  /* .Hook     = */
  {
    /* .Thread       = */
    {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ErrorHook_OsCore_Core2,
    /* .Context               = */ &OsCfg_Hal_Context_ErrorHook_OsCore_Core2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core2_Error,
    /* .Dyn                   = */ OS_HOOK_CASTDYN_HOOK_2_THREAD(OsCfg_Hook_ErrorHook_OsCore_Core2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core2,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ERRORHOOK,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
    /* .HookTypeFlag = */ OS_HOOKFLAG_ERRORHOOK,
    /* .NestingMask  = */ OS_HOOKNESTINGMASK_ERRORHOOK,
    /* .Id           = */ (Os_HookIdType)11,
    /* .TaskReturn   = */ Os_HookTaskReturn_WithSchedule
  },
  /* .Callback = */ &ErrorHook
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for hook callbacks. */
CONSTP2CONST(Os_HookConfigType, OS_CONST, OS_CONST) OsCfg_HookRefs[OS_CFG_NUM_HOOKS + 1] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore_Core0),
  OS_HOOK_CASTCONFIG_CALLBACK_2_HOOK(OsCfg_Hook_StartupHook_OsCore_Core0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore_Core0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore_Core0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore_Core1),
  OS_HOOK_CASTCONFIG_CALLBACK_2_HOOK(OsCfg_Hook_StartupHook_OsCore_Core1),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore_Core1),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore_Core1),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore_Core2),
  OS_HOOK_CASTCONFIG_CALLBACK_2_HOOK(OsCfg_Hook_StartupHook_OsCore_Core2),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore_Core2),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore_Core2),
  NULL_PTR
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
 *  END OF FILE: Os_Hook_Lcfg.c
 *********************************************************************************************************************/
