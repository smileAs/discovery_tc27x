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
 *              File: Os_Task_Lcfg.c
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
/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_TASK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Error.h"
#include "Os_Ioc.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"

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

/*! Dynamic task data: Core0_OsTask_1ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Core0_OsTask_1ms_Dyn;

/*! Dynamic task data: Default_BSW_Async_Task_Core0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Default_BSW_Async_Task_Core0_Dyn;

/*! Dynamic task data: Default_Init_Task_Core0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Default_Init_Task_Core0_Dyn;

/*! Dynamic task data: IdleTask_OsCore_Core0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_IdleTask_OsCore_Core0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic task data: Default_BSW_Async_Task_Core1 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Default_BSW_Async_Task_Core1_Dyn;

/*! Dynamic task data: Default_Init_Task_Core1 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Default_Init_Task_Core1_Dyn;

/*! Dynamic task data: IdleTask_OsCore_Core1 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_IdleTask_OsCore_Core1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic task data: Default_BSW_Async_Task_Core2 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Default_BSW_Async_Task_Core2_Dyn;

/*! Dynamic task data: Default_Init_Task_Core2 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Default_Init_Task_Core2_Dyn;

/*! Dynamic task data: IdleTask_OsCore_Core2 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_IdleTask_OsCore_Core2_Dyn;

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

/*! Task configuration data: Core0_OsTask_1ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Core0_OsTask_1ms =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Core0_OsTask_1ms,
    /* .Context               = */ &OsCfg_Hal_Context_Core0_OsTask_1ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Task_Prio0,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Core0_OsTask_1ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 0UL,
  /* .TaskId                = */ Core0_OsTask_1ms,
  /* .RunningPriority       = */ 0UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_NONE,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: Default_BSW_Async_Task_Core0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_BSW_Async_Task_Core0 =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Default_BSW_Async_Task_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_Default_BSW_Async_Task_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Default_BSW_Async_Task_Core0,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Default_BSW_Async_Task_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 1UL,
  /* .TaskId                = */ Default_BSW_Async_Task_Core0,
  /* .RunningPriority       = */ 0UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_NONE,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
  /* .IsExtended            = */ TRUE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: Default_Init_Task_Core0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task_Core0 =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Default_Init_Task_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_Default_Init_Task_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Task_Prio6,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Default_Init_Task_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 6UL,
  /* .TaskId                = */ Default_Init_Task_Core0,
  /* .RunningPriority       = */ 0UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_ANY,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: IdleTask_OsCore_Core0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore_Core0 =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IdleTask_OsCore_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_IdleTask_OsCore_Core0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Task_Prio7,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_IdleTask_OsCore_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 7UL,
  /* .TaskId                = */ IdleTask_OsCore_Core0,
  /* .RunningPriority       = */ 7UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_ANY,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Task configuration data: Default_BSW_Async_Task_Core1 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_BSW_Async_Task_Core1 =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Default_BSW_Async_Task_Core1,
    /* .Context               = */ &OsCfg_Hal_Context_Default_BSW_Async_Task_Core1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Task_Prio2,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Default_BSW_Async_Task_Core1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 2UL,
  /* .TaskId                = */ Default_BSW_Async_Task_Core1,
  /* .RunningPriority       = */ 0UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_NONE,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: Default_Init_Task_Core1 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task_Core1 =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Default_Init_Task_Core1,
    /* .Context               = */ &OsCfg_Hal_Context_Default_Init_Task_Core1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Task_Prio5,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Default_Init_Task_Core1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 5UL,
  /* .TaskId                = */ Default_Init_Task_Core1,
  /* .RunningPriority       = */ 0UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_ANY,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core1)),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: IdleTask_OsCore_Core1 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore_Core1 =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IdleTask_OsCore_Core1,
    /* .Context               = */ &OsCfg_Hal_Context_IdleTask_OsCore_Core1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Task_Prio7,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_IdleTask_OsCore_Core1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 7UL,
  /* .TaskId                = */ IdleTask_OsCore_Core1,
  /* .RunningPriority       = */ 7UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_ANY,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Task configuration data: Default_BSW_Async_Task_Core2 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_BSW_Async_Task_Core2 =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Default_BSW_Async_Task_Core2,
    /* .Context               = */ &OsCfg_Hal_Context_Default_BSW_Async_Task_Core2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core2_Task_Prio3,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Default_BSW_Async_Task_Core2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core2,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 3UL,
  /* .TaskId                = */ Default_BSW_Async_Task_Core2,
  /* .RunningPriority       = */ 0UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_NONE,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: Default_Init_Task_Core2 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task_Core2 =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Default_Init_Task_Core2,
    /* .Context               = */ &OsCfg_Hal_Context_Default_Init_Task_Core2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core2_Task_Prio4,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Default_Init_Task_Core2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core2,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 4UL,
  /* .TaskId                = */ Default_Init_Task_Core2,
  /* .RunningPriority       = */ 0UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_ANY,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: IdleTask_OsCore_Core2 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore_Core2 =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IdleTask_OsCore_Core2,
    /* .Context               = */ &OsCfg_Hal_Context_IdleTask_OsCore_Core2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core2_Task_Prio7,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_IdleTask_OsCore_Core2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core2,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 7UL,
  /* .TaskId                = */ IdleTask_OsCore_Core2,
  /* .RunningPriority       = */ 7UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_ANY,
  /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for tasks. */
CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Core0_OsTask_1ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_BSW_Async_Task_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_BSW_Async_Task_Core1),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_BSW_Async_Task_Core2),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Core1),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Core2),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore_Core1),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore_Core2),
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
 *  END OF FILE: Os_Task_Lcfg.c
 *********************************************************************************************************************/
