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
 *              File: Os_Alarm_Lcfg.c
 *   Generation Time: 2018-08-10 15:06:43
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

#define OS_ALARM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

/* Os hal dependencies */


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

/*! Dynamic alarm data: Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE2_Default_BSW_Async_Task_Core0_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_LinIf_LinIf_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_LinIf_LinIf_MainFunction_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_disc_ecu_Core0_Task_100ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_100ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_disc_ecu_Core0_Task_10ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_10ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_disc_ecu_Core0_Task_20ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_20ms_Dyn;

/*! Dynamic alarm data: Rte_Al_TE_disc_ecu_Core0_Task_50ms */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_50ms_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic alarm data: Rte_Al_TE2_EcuM_EcuM_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic alarm data: Rte_Al_TE3_EcuM_EcuM_MainFunction */
OS_LOCAL VAR(Os_AlarmType, OS_VAR_NOINIT) OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction_Dyn;

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

/*! Alarm configuration data: Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core0,
  /* .Mask  = */ Rte_Ev_Cyclic2_Default_BSW_Async_Task_Core0_0_10ms
};

/*! Alarm configuration data: Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core0,
  /* .Mask  = */ Rte_Ev_Cyclic2_Default_BSW_Async_Task_Core0_0_20ms
};

/*! Alarm configuration data: Rte_Al_TE2_Default_BSW_Async_Task_Core0_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core0,
  /* .Mask  = */ Rte_Ev_Cyclic2_Default_BSW_Async_Task_Core0_10ms
};

/*! Alarm configuration data: Rte_Al_TE_LinIf_LinIf_MainFunction */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_LinIf_LinIf_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_LinIf_LinIf_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core0,
  /* .Mask  = */ Rte_Ev_Run_LinIf_LinIf_MainFunction
};

/*! Alarm configuration data: Rte_Al_TE_disc_ecu_Core0_Task_100ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_100ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_100ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core0,
  /* .Mask  = */ Rte_Ev_Run_disc_ecu_Core0_Task_100ms
};

/*! Alarm configuration data: Rte_Al_TE_disc_ecu_Core0_Task_10ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_10ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_10ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core0,
  /* .Mask  = */ Rte_Ev_Run_disc_ecu_Core0_Task_10ms
};

/*! Alarm configuration data: Rte_Al_TE_disc_ecu_Core0_Task_20ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_20ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_20ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core0,
  /* .Mask  = */ Rte_Ev_Run_disc_ecu_Core0_Task_20ms
};

/*! Alarm configuration data: Rte_Al_TE_disc_ecu_Core0_Task_50ms */
CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_50ms =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_50ms_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
      /* .Callback = */ Os_AlarmActionSetEvent
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core0,
  /* .Mask  = */ Rte_Ev_Run_disc_ecu_Core0_Task_50ms
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Alarm configuration data: Rte_Al_TE2_EcuM_EcuM_MainFunction */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core1),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core1
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core1
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Alarm configuration data: Rte_Al_TE3_EcuM_EcuM_MainFunction */
CONST(Os_AlarmActivateTaskConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction =
{
  /* .Alarm = */
  {
    /* .Job                   = */
    {
      /* .Dyn      = */ OS_ALARM_CASTDYN_ALARM_2_JOB(OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction_Dyn),
      /* .Counter  = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core2),
      /* .Callback = */ Os_AlarmActionActivateTask
    },
    /* .Autostart             = */
    {
      /* .AlarmTime        = */ 0UL, /* 0.0 sec */
      /* .Cycle            = */ 0UL, /* 0.0 sec */
      /* .ApplicationModes = */ OS_APPMODE_NONE,
      /* .AlarmMode        = */ OS_ALARMMODE_ABSOLUTE
    },
    /* .AccessingApplications = */ (OS_APPID2MASK(SystemApplication_OsCore_Core0)
        | OS_APPID2MASK(SystemApplication_OsCore_Core1)
        | OS_APPID2MASK(SystemApplication_OsCore_Core2)
        | OS_APPID2MASK(Untrusted_BSW_Core0)
        | OS_APPID2MASK(Untrusted_BSW_Core1)
        | OS_APPID2MASK(Untrusted_BSW_Core2)),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core2
  },
  /* .Task  = */ &OsCfg_Task_Default_BSW_Async_Task_Core2
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for alarms. */
CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_LinIf_LinIf_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_100ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_20ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_50ms),
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
 *  END OF FILE: Os_Alarm_Lcfg.c
 *********************************************************************************************************************/
