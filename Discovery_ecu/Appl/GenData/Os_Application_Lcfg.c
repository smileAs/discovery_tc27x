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
 *              File: Os_Application_Lcfg.c
 *   Generation Time: 2018-09-29 15:39:31
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

#define OS_APPLICATION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Application_Cfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Application.h"

/* Os kernel module dependencies */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_ScheduleTable_Lcfg.h"
#include "Os_ScheduleTable.h"
#include "Os_ServiceFunction_Lcfg.h"
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

/*! Dynamic application data: SystemApplication_OsCore_Core0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore_Core0_Dyn;

/*! Dynamic application data: Untrusted_BSW_Core0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_Untrusted_BSW_Core0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic application data: SystemApplication_OsCore_Core1 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore_Core1_Dyn;

/*! Dynamic application data: Untrusted_BSW_Core1 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_Untrusted_BSW_Core1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic application data: SystemApplication_OsCore_Core2 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore_Core2_Dyn;

/*! Dynamic application data: Untrusted_BSW_Core2 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_Untrusted_BSW_Core2_Dyn;

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

/*! Object reference table for application alarms: SystemApplication_OsCore_Core0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core0_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_ALARMS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore_Core0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core0_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_COUNTERS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore_Core0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core0_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_HOOKS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore_Core0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core0_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_ISRS + 1] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_2),
  OS_TIMER_CASTCONFIG_TIMEREISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimerCore0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart0_Err_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart0_Rx_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart0_Tx_Isr),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore_Core0),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore_Core0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core0_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_CAT1ISRS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore_Core0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core0_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_SCHTS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore_Core0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core0_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_TASKS + 1] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore_Core0),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore_Core0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core0_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_SERVICES + 1] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore_Core0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core0 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore_Core0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore_Core0,
  /* .AccessRightId        = */ OS_APPID2MASK(SystemApplication_OsCore_Core0),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore_Core0_TaskRefs,
  /* .TaskCount            = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore_Core0_IsrRefs,
  /* .IsrCat2Count         = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore_Core0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore_Core0_CounterRefs,
  /* .CounterCount         = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore_Core0_AlarmRefs,
  /* .AlarmCount           = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore_Core0_SchTRefs,
  /* .SchTCount            = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore_Core0_ServiceRefs,
  /* .ServiceFunctionCount = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore_Core0_HookRefs,
  /* .HookCount            = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore_Core0
};

/*! Object reference table for application alarms: Untrusted_BSW_Core0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core0_AlarmRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_ALARMS + 1] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_Async_Task_Core0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_LinIf_LinIf_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_100ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_20ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_disc_ecu_Core0_Task_50ms),
  NULL_PTR
};

/*! Object reference table for application counters: Untrusted_BSW_Core0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core0_CounterRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_COUNTERS + 1] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0),
  NULL_PTR
};

/*! Object reference table for application hooks: Untrusted_BSW_Core0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core0_HookRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_HOOKS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: Untrusted_BSW_Core0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core0_IsrRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_ISRS + 1] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_Channel_1_EX_Extended_Error_Interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_Channel_1_RX_Receive_Interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_Channel_1_TX_Transmit_Interrupt),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: Untrusted_BSW_Core0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core0_Cat1IsrRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_CAT1ISRS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: Untrusted_BSW_Core0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core0_SchTRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_SCHTS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: Untrusted_BSW_Core0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core0_TaskRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_TASKS + 1] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_BSW_Async_Task_Core0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Core0),
  NULL_PTR
};

/*! Object reference table for application trusted functions: Untrusted_BSW_Core0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core0_ServiceRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_SERVICES + 1] =
{
  NULL_PTR
};

/*! Application configuration data: Untrusted_BSW_Core0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_Untrusted_BSW_Core0 =
{
  /* .Dyn                  = */ &OsCfg_App_Untrusted_BSW_Core0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore_Core0,
  /* .AccessRightId        = */ OS_APPID2MASK(Untrusted_BSW_Core0),
  /* .TaskRefs             = */ OsCfg_App_Untrusted_BSW_Core0_TaskRefs,
  /* .TaskCount            = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_Untrusted_BSW_Core0_IsrRefs,
  /* .IsrCat2Count         = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_Untrusted_BSW_Core0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_Untrusted_BSW_Core0_CounterRefs,
  /* .CounterCount         = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_Untrusted_BSW_Core0_AlarmRefs,
  /* .AlarmCount           = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_Untrusted_BSW_Core0_SchTRefs,
  /* .SchTCount            = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_Untrusted_BSW_Core0_ServiceRefs,
  /* .ServiceFunctionCount = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_Untrusted_BSW_Core0_HookRefs,
  /* .HookCount            = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE0_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ Untrusted_BSW_Core0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for application alarms: SystemApplication_OsCore_Core1 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core1_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_ALARMS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore_Core1 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core1_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_COUNTERS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore_Core1 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core1_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_HOOKS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore_Core1 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core1_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_ISRS + 1] =
{
  OS_TIMER_CASTCONFIG_TIMEREISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimerCore1),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore_Core1),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore_Core1 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core1_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_CAT1ISRS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore_Core1 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core1_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_SCHTS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore_Core1 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core1_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_TASKS + 1] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore_Core1),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore_Core1 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core1_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_SERVICES + 1] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore_Core1 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core1 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore_Core1_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore_Core1,
  /* .AccessRightId        = */ OS_APPID2MASK(SystemApplication_OsCore_Core1),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore_Core1_TaskRefs,
  /* .TaskCount            = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore_Core1_IsrRefs,
  /* .IsrCat2Count         = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore_Core1_Cat1IsrRefs,
  /* .IsrCat1Count         = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore_Core1_CounterRefs,
  /* .CounterCount         = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore_Core1_AlarmRefs,
  /* .AlarmCount           = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore_Core1_SchTRefs,
  /* .SchTCount            = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore_Core1_ServiceRefs,
  /* .ServiceFunctionCount = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore_Core1_HookRefs,
  /* .HookCount            = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE1_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore_Core1
};

/*! Object reference table for application alarms: Untrusted_BSW_Core1 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core1_AlarmRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_ALARMS + 1] =
{
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_EcuM_EcuM_MainFunction),
  NULL_PTR
};

/*! Object reference table for application counters: Untrusted_BSW_Core1 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core1_CounterRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_COUNTERS + 1] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core1),
  NULL_PTR
};

/*! Object reference table for application hooks: Untrusted_BSW_Core1 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core1_HookRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_HOOKS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: Untrusted_BSW_Core1 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core1_IsrRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_ISRS + 1] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_KEY_EVENT_Isr),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: Untrusted_BSW_Core1 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core1_Cat1IsrRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_CAT1ISRS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: Untrusted_BSW_Core1 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core1_SchTRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_SCHTS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: Untrusted_BSW_Core1 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core1_TaskRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_TASKS + 1] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_BSW_Async_Task_Core1),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Core1),
  NULL_PTR
};

/*! Object reference table for application trusted functions: Untrusted_BSW_Core1 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core1_ServiceRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_SERVICES + 1] =
{
  NULL_PTR
};

/*! Application configuration data: Untrusted_BSW_Core1 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_Untrusted_BSW_Core1 =
{
  /* .Dyn                  = */ &OsCfg_App_Untrusted_BSW_Core1_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore_Core1,
  /* .AccessRightId        = */ OS_APPID2MASK(Untrusted_BSW_Core1),
  /* .TaskRefs             = */ OsCfg_App_Untrusted_BSW_Core1_TaskRefs,
  /* .TaskCount            = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_Untrusted_BSW_Core1_IsrRefs,
  /* .IsrCat2Count         = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_Untrusted_BSW_Core1_Cat1IsrRefs,
  /* .IsrCat1Count         = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_Untrusted_BSW_Core1_CounterRefs,
  /* .CounterCount         = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_Untrusted_BSW_Core1_AlarmRefs,
  /* .AlarmCount           = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_Untrusted_BSW_Core1_SchTRefs,
  /* .SchTCount            = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_Untrusted_BSW_Core1_ServiceRefs,
  /* .ServiceFunctionCount = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_Untrusted_BSW_Core1_HookRefs,
  /* .HookCount            = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE1_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ Untrusted_BSW_Core1
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for application alarms: SystemApplication_OsCore_Core2 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core2_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_ALARMS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore_Core2 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core2_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_COUNTERS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore_Core2 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core2_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_HOOKS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore_Core2 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core2_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_ISRS + 1] =
{
  OS_TIMER_CASTCONFIG_TIMEREISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimerCore2),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore_Core2),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore_Core2 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core2_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_CAT1ISRS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore_Core2 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core2_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_SCHTS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore_Core2 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core2_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_TASKS + 1] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore_Core2),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore_Core2 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core2_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_SERVICES + 1] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore_Core2 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore_Core2 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore_Core2_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore_Core2,
  /* .AccessRightId        = */ OS_APPID2MASK(SystemApplication_OsCore_Core2),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore_Core2_TaskRefs,
  /* .TaskCount            = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore_Core2_IsrRefs,
  /* .IsrCat2Count         = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore_Core2_Cat1IsrRefs,
  /* .IsrCat1Count         = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore_Core2_CounterRefs,
  /* .CounterCount         = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore_Core2_AlarmRefs,
  /* .AlarmCount           = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore_Core2_SchTRefs,
  /* .SchTCount            = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore_Core2_ServiceRefs,
  /* .ServiceFunctionCount = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore_Core2_HookRefs,
  /* .HookCount            = */ OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE2_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore_Core2
};

/*! Object reference table for application alarms: Untrusted_BSW_Core2 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core2_AlarmRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_ALARMS + 1] =
{
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE3_EcuM_EcuM_MainFunction),
  NULL_PTR
};

/*! Object reference table for application counters: Untrusted_BSW_Core2 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core2_CounterRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_COUNTERS + 1] =
{
  OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core2),
  NULL_PTR
};

/*! Object reference table for application hooks: Untrusted_BSW_Core2 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core2_HookRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_HOOKS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: Untrusted_BSW_Core2 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core2_IsrRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_ISRS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: Untrusted_BSW_Core2 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core2_Cat1IsrRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_CAT1ISRS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: Untrusted_BSW_Core2 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core2_SchTRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_SCHTS + 1] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: Untrusted_BSW_Core2 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core2_TaskRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_TASKS + 1] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_BSW_Async_Task_Core2),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Core2),
  NULL_PTR
};

/*! Object reference table for application trusted functions: Untrusted_BSW_Core2 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_Untrusted_BSW_Core2_ServiceRefs[OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_SERVICES + 1] =
{
  NULL_PTR
};

/*! Application configuration data: Untrusted_BSW_Core2 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_Untrusted_BSW_Core2 =
{
  /* .Dyn                  = */ &OsCfg_App_Untrusted_BSW_Core2_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore_Core2,
  /* .AccessRightId        = */ OS_APPID2MASK(Untrusted_BSW_Core2),
  /* .TaskRefs             = */ OsCfg_App_Untrusted_BSW_Core2_TaskRefs,
  /* .TaskCount            = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_Untrusted_BSW_Core2_IsrRefs,
  /* .IsrCat2Count         = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_Untrusted_BSW_Core2_Cat1IsrRefs,
  /* .IsrCat1Count         = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_Untrusted_BSW_Core2_CounterRefs,
  /* .CounterCount         = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_Untrusted_BSW_Core2_AlarmRefs,
  /* .AlarmCount           = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_Untrusted_BSW_Core2_SchTRefs,
  /* .SchTCount            = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_Untrusted_BSW_Core2_ServiceRefs,
  /* .ServiceFunctionCount = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_Untrusted_BSW_Core2_HookRefs,
  /* .HookCount            = */ OS_CFG_NUM_APP_UNTRUSTED_BSW_CORE2_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ Untrusted_BSW_Core2
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for applications. */
CONSTP2CONST(Os_AppConfigType, OS_CONST, OS_CONST) OsCfg_AppRefs[OS_APPID_COUNT + 1] =
{
  &OsCfg_App_SystemApplication_OsCore_Core0,
  &OsCfg_App_SystemApplication_OsCore_Core1,
  &OsCfg_App_SystemApplication_OsCore_Core2,
  &OsCfg_App_Untrusted_BSW_Core0,
  &OsCfg_App_Untrusted_BSW_Core1,
  &OsCfg_App_Untrusted_BSW_Core2,
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
 *  END OF FILE: Os_Application_Lcfg.c
 *********************************************************************************************************************/
