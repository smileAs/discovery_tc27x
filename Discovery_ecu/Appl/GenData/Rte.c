/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte.c
 *        Config:  discovery_ecu.dpa
 *   ECU-Project:  P2P
 *
 *     Generator:  MICROSAR RTE Generator Version 4.14.0
 *                 RTE Core Version 1.14.0
 *       License:  Unlimited license CBD1800319 for Tong Ji University
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0781, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_Rte_0781, MD_MSR_1.1_857 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_BswM.h"
#include "Rte_ComM.h"
#include "Rte_Dcm.h"
#include "Rte_EcuM.h"
#include "Rte_Os_OsCore_Core0_swc.h"
#include "Rte_Os_OsCore_Core1_swc.h"
#include "Rte_Os_OsCore_Core2_swc.h"
#include "Rte_disc_ecu.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanSM.h"
#include "SchM_CanTp.h"
#include "SchM_CanTrcv_30_Tja1043.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Dcm.h"
#include "SchM_Dio.h"
#include "SchM_EcuM.h"
#include "SchM_Gpt.h"
#include "SchM_Icu_17_GtmCcu6.h"
#include "SchM_Irq.h"
#include "SchM_Lin.h"
#include "SchM_LinIf.h"
#include "SchM_LinSM.h"
#include "SchM_Mcu.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"
#include "SchM_Pwm.h"
#include "SchM_Spi.h"

#include "Rte_Hook.h"

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer_Core0
# define RTE_USEC_SystemTimer_Core0 OS_US2TICKS_SystemTimer_Core0
#else
# define RTE_USEC_SystemTimer_Core0(val) ((TickType)RTE_CONST_USEC_SystemTimer_Core0_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer_Core0
# define RTE_MSEC_SystemTimer_Core0 OS_MS2TICKS_SystemTimer_Core0
#else
# define RTE_MSEC_SystemTimer_Core0(val) ((TickType)RTE_CONST_MSEC_SystemTimer_Core0_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer_Core0
# define RTE_SEC_SystemTimer_Core0 OS_SEC2TICKS_SystemTimer_Core0
#else
# define RTE_SEC_SystemTimer_Core0(val)  ((TickType)RTE_CONST_SEC_SystemTimer_Core0_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer_Core1
# define RTE_USEC_SystemTimer_Core1 OS_US2TICKS_SystemTimer_Core1
#else
# define RTE_USEC_SystemTimer_Core1(val) ((TickType)RTE_CONST_USEC_SystemTimer_Core1_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer_Core1
# define RTE_MSEC_SystemTimer_Core1 OS_MS2TICKS_SystemTimer_Core1
#else
# define RTE_MSEC_SystemTimer_Core1(val) ((TickType)RTE_CONST_MSEC_SystemTimer_Core1_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer_Core1
# define RTE_SEC_SystemTimer_Core1 OS_SEC2TICKS_SystemTimer_Core1
#else
# define RTE_SEC_SystemTimer_Core1(val)  ((TickType)RTE_CONST_SEC_SystemTimer_Core1_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer_Core2
# define RTE_USEC_SystemTimer_Core2 OS_US2TICKS_SystemTimer_Core2
#else
# define RTE_USEC_SystemTimer_Core2(val) ((TickType)RTE_CONST_USEC_SystemTimer_Core2_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer_Core2
# define RTE_MSEC_SystemTimer_Core2 OS_MS2TICKS_SystemTimer_Core2
#else
# define RTE_MSEC_SystemTimer_Core2(val) ((TickType)RTE_CONST_MSEC_SystemTimer_Core2_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer_Core2
# define RTE_SEC_SystemTimer_Core2 OS_SEC2TICKS_SystemTimer_Core2
#else
# define RTE_SEC_SystemTimer_Core2(val)  ((TickType)RTE_CONST_SEC_SystemTimer_Core2_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer_Core0_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_Core1_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_Core2_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_Core0_10 (800000UL)
#define RTE_CONST_MSEC_SystemTimer_Core1_10 (400000UL)
#define RTE_CONST_MSEC_SystemTimer_Core2_10 (400000UL)
#define RTE_CONST_MSEC_SystemTimer_Core0_100 (8000000UL)
#define RTE_CONST_MSEC_SystemTimer_Core0_20 (1600000UL)
#define RTE_CONST_MSEC_SystemTimer_Core0_5 (400000UL)
#define RTE_CONST_MSEC_SystemTimer_Core0_50 (4000000UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Init(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    /* activate the tasks */
    (void)ActivateTask(Default_BSW_Async_Task_Core0); /* PRQA S 3417 */ /* MD_Rte_Os */

    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_LinIf_LinIf_MainFunction, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(5)); /* PRQA S 3417 */ /* MD_Rte_Os */

  }
  if (id == OS_CORE_ID_1)
  {
    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE2_EcuM_EcuM_MainFunction, RTE_MSEC_SystemTimer_Core1(0) + (TickType)1, RTE_MSEC_SystemTimer_Core1(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

  }
  if (id == OS_CORE_ID_2)
  {
    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE3_EcuM_EcuM_MainFunction, RTE_MSEC_SystemTimer_Core2(0) + (TickType)1, RTE_MSEC_SystemTimer_Core2(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

  }
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE_disc_ecu_Core0_Task_20ms, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_disc_ecu_Core0_Task_10ms, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_disc_ecu_Core0_Task_50ms, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(50)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_disc_ecu_Core0_Task_100ms, RTE_MSEC_SystemTimer_Core0(0) + (TickType)1, RTE_MSEC_SystemTimer_Core0(100)); /* PRQA S 3417 */ /* MD_Rte_Os */

  }
  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE_disc_ecu_Core0_Task_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_disc_ecu_Core0_Task_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_disc_ecu_Core0_Task_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_disc_ecu_Core0_Task_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  }
  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_LinIf_LinIf_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  }
  if (id == OS_CORE_ID_1)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE2_EcuM_EcuM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  }
  if (id == OS_CORE_ID_2)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE3_EcuM_EcuM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  }
}

FUNC(void, RTE_CODE) Rte_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  uint32 id;
  id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    Rte_InitMemory_Untrusted_BSW_Core0();
  }
  else if (id == OS_CORE_ID_1) /* PRQA S 2004 */ /* MD_Rte_2004 */
  {
    Rte_InitMemory_Untrusted_BSW_Core1();
  }
  else if (id == OS_CORE_ID_2) /* PRQA S 2004 */ /* MD_Rte_2004 */
  {
    Rte_InitMemory_Untrusted_BSW_Core2();
  }
}


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_Ccu6IenUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_Ccu6IenUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_CcuInterruptHandle(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_CcuInterruptHandle(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_CcuVariableupdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_CcuVariableupdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_EnableNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_EnableNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_EnableWakeup(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_EnableWakeup(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_ResetEdgeCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_ResetEdgeCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_AsyncTransmit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_AsyncTransmit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Cancel(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Cancel(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_DeInit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_DeInit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_GetSequenceResult(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_GetSequenceResult(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Init(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Init(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SyncTransmit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SyncTransmit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_WriteIB(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_WriteIB(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0781:  MISRA rule: 5.6
     Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

   MD_Rte_2004:  MISRA rule: 14.10
     Reason:     The concluding else is not needed and an empty else makes the code more difficult to understand.
     Risk:       Wrong implementations could remain undetected.
     Prevention: Code inspection and test of different source code variants by the component test suites.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
