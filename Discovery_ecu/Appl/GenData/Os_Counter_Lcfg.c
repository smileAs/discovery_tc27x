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
 *              File: Os_Counter_Lcfg.c
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

#define OS_COUNTER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Counter_Cfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_PriorityQueue.h"
#include "Os_Timer.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Timer_Lcfg.h"


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

/*! Dynamic counter data: SystemTimer_Core0 */
OS_LOCAL VAR(Os_TimerHrtType, OS_VAR_NOINIT) OsCfg_Counter_SystemTimer_Core0_Dyn;
OS_LOCAL VAR(Os_PriorityQueueType, OS_VAR_NOINIT) OsCfg_Counter_SystemTimer_Core0_JobQueue_Dyn;
OS_LOCAL VAR(Os_PriorityQueueNodeType, OS_VAR_NOINIT)
  OsCfg_Counter_SystemTimer_Core0_JobQueueNodes_Dyn[OS_CFG_NUM_COUNTER_SYSTEMTIMER_CORE0_JOBS + 1];

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic counter data: SystemTimer_Core1 */
OS_LOCAL VAR(Os_TimerHrtType, OS_VAR_NOINIT) OsCfg_Counter_SystemTimer_Core1_Dyn;
OS_LOCAL VAR(Os_PriorityQueueType, OS_VAR_NOINIT) OsCfg_Counter_SystemTimer_Core1_JobQueue_Dyn;
OS_LOCAL VAR(Os_PriorityQueueNodeType, OS_VAR_NOINIT)
  OsCfg_Counter_SystemTimer_Core1_JobQueueNodes_Dyn[OS_CFG_NUM_COUNTER_SYSTEMTIMER_CORE1_JOBS + 1];

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic counter data: SystemTimer_Core2 */
OS_LOCAL VAR(Os_TimerHrtType, OS_VAR_NOINIT) OsCfg_Counter_SystemTimer_Core2_Dyn;
OS_LOCAL VAR(Os_PriorityQueueType, OS_VAR_NOINIT) OsCfg_Counter_SystemTimer_Core2_JobQueue_Dyn;
OS_LOCAL VAR(Os_PriorityQueueNodeType, OS_VAR_NOINIT)
  OsCfg_Counter_SystemTimer_Core2_JobQueueNodes_Dyn[OS_CFG_NUM_COUNTER_SYSTEMTIMER_CORE2_JOBS + 1];

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

/*! Counter configuration data: SystemTimer_Core0 */
CONST(Os_TimerHrtConfigType, OS_CONST) OsCfg_Counter_SystemTimer_Core0 =
{
  /* .Counter  = */
  {
    /* .Characteristics       = */
    {
      /* .MaxAllowedValue      = */ OSMAXALLOWEDVALUE_SystemTimer_Core0,
      /* .MaxCountingValue     = */ OS_TIMERHRT_GETMAXCOUNTINGVALUE(OSMAXALLOWEDVALUE_SystemTimer_Core0),
      /* .MaxDifferentialValue = */ OS_TIMERHRT_GETMAXDIFFERENTIALVALUE(OSMAXALLOWEDVALUE_SystemTimer_Core0),
      /* .MinCycle             = */ OSMINCYCLE_SystemTimer_Core0,
      /* .TicksPerBase         = */ OSTICKSPERBASE_SystemTimer_Core0
    },
    /* .JobQueue              = */
    {
      /* .Queue     = */ OsCfg_Counter_SystemTimer_Core0_JobQueueNodes_Dyn,
      /* .Dyn       = */ &OsCfg_Counter_SystemTimer_Core0_JobQueue_Dyn,
      /* .QueueSize = */ OS_CFG_NUM_COUNTER_SYSTEMTIMER_CORE0_JOBS
    },
    /* .DriverType            = */ OS_TIMERTYPE_HIGH_RESOLUTION,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0,
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2))
  },
  /* .Dyn      = */ &OsCfg_Counter_SystemTimer_Core0_Dyn,
  /* .HwConfig = */ &OsCfg_Hal_TimerFrt_SystemTimer_Core0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Counter configuration data: SystemTimer_Core1 */
CONST(Os_TimerHrtConfigType, OS_CONST) OsCfg_Counter_SystemTimer_Core1 =
{
  /* .Counter  = */
  {
    /* .Characteristics       = */
    {
      /* .MaxAllowedValue      = */ OSMAXALLOWEDVALUE_SystemTimer_Core1,
      /* .MaxCountingValue     = */ OS_TIMERHRT_GETMAXCOUNTINGVALUE(OSMAXALLOWEDVALUE_SystemTimer_Core1),
      /* .MaxDifferentialValue = */ OS_TIMERHRT_GETMAXDIFFERENTIALVALUE(OSMAXALLOWEDVALUE_SystemTimer_Core1),
      /* .MinCycle             = */ OSMINCYCLE_SystemTimer_Core1,
      /* .TicksPerBase         = */ OSTICKSPERBASE_SystemTimer_Core1
    },
    /* .JobQueue              = */
    {
      /* .Queue     = */ OsCfg_Counter_SystemTimer_Core1_JobQueueNodes_Dyn,
      /* .Dyn       = */ &OsCfg_Counter_SystemTimer_Core1_JobQueue_Dyn,
      /* .QueueSize = */ OS_CFG_NUM_COUNTER_SYSTEMTIMER_CORE1_JOBS
    },
    /* .DriverType            = */ OS_TIMERTYPE_HIGH_RESOLUTION,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core1,
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2))
  },
  /* .Dyn      = */ &OsCfg_Counter_SystemTimer_Core1_Dyn,
  /* .HwConfig = */ &OsCfg_Hal_TimerFrt_SystemTimer_Core1
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Counter configuration data: SystemTimer_Core2 */
CONST(Os_TimerHrtConfigType, OS_CONST) OsCfg_Counter_SystemTimer_Core2 =
{
  /* .Counter  = */
  {
    /* .Characteristics       = */
    {
      /* .MaxAllowedValue      = */ OSMAXALLOWEDVALUE_SystemTimer_Core2,
      /* .MaxCountingValue     = */ OS_TIMERHRT_GETMAXCOUNTINGVALUE(OSMAXALLOWEDVALUE_SystemTimer_Core2),
      /* .MaxDifferentialValue = */ OS_TIMERHRT_GETMAXDIFFERENTIALVALUE(OSMAXALLOWEDVALUE_SystemTimer_Core2),
      /* .MinCycle             = */ OSMINCYCLE_SystemTimer_Core2,
      /* .TicksPerBase         = */ OSTICKSPERBASE_SystemTimer_Core2
    },
    /* .JobQueue              = */
    {
      /* .Queue     = */ OsCfg_Counter_SystemTimer_Core2_JobQueueNodes_Dyn,
      /* .Dyn       = */ &OsCfg_Counter_SystemTimer_Core2_JobQueue_Dyn,
      /* .QueueSize = */ OS_CFG_NUM_COUNTER_SYSTEMTIMER_CORE2_JOBS
    },
    /* .DriverType            = */ OS_TIMERTYPE_HIGH_RESOLUTION,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core2,
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2))
  },
  /* .Dyn      = */ &OsCfg_Counter_SystemTimer_Core2_Dyn,
  /* .HwConfig = */ &OsCfg_Hal_TimerFrt_SystemTimer_Core2
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for counters. */
CONSTP2CONST(Os_CounterConfigType, OS_CONST, OS_CONST) OsCfg_CounterRefs[OS_COUNTERID_COUNT + 1] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core1),
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core2),
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
 *  END OF FILE: Os_Counter_Lcfg.c
 *********************************************************************************************************************/
