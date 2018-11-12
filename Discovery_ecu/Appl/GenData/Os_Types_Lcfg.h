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
 *              File: Os_Types_Lcfg.h
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
#if !defined (OS_TYPES_LCFG_H)                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! OS-Application identifier. */
typedef enum
{
  SystemApplication_OsCore_Core0 = 0, /* 0x00000001 */
  SystemApplication_OsCore_Core1 = 1, /* 0x00000002 */
  SystemApplication_OsCore_Core2 = 2, /* 0x00000004 */
  Untrusted_BSW_Core0 = 3, /* 0x00000008 */
  Untrusted_BSW_Core1 = 4, /* 0x00000010 */
  Untrusted_BSW_Core2 = 5, /* 0x00000020 */
  OS_APPID_COUNT = 6,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifier. */
typedef enum
{
  OS_TRUSTEDFUNCTIONID_COUNT = 0
} TrustedFunctionIndexType;

/*! Non-Trusted function identifier. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast Trusted function identifier. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifier. */
typedef enum
{
  Default_BSW_Async_Task_Core0 = 0,
  Default_BSW_Async_Task_Core1 = 1,
  Default_BSW_Async_Task_Core2 = 2,
  Default_Init_Task_Core0 = 3,
  Default_Init_Task_Core1 = 4,
  Default_Init_Task_Core2 = 5,
  IdleTask_OsCore_Core0 = 6,
  IdleTask_OsCore_Core1 = 7,
  IdleTask_OsCore_Core2 = 8,
  OS_TASKID_COUNT = 9,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifier. */
typedef enum
{
  CanIsr_0 = 0,
  CanIsr_1 = 1,
  CanIsr_2 = 2,
  CounterIsr_SystemTimerCore0 = 3,
  CounterIsr_SystemTimerCore1 = 4,
  CounterIsr_SystemTimerCore2 = 5,
  KEY_EVENT_Isr = 6,
  Lin_Channel_1_EX_Extended_Error_Interrupt = 7,
  Lin_Channel_1_RX_Receive_Interrupt = 8,
  Lin_Channel_1_TX_Transmit_Interrupt = 9,
  Uart0_Err_Isr = 10,
  Uart0_Rx_Isr = 11,
  Uart0_Tx_Isr = 12,
  XSignalIsr_OsCore_Core0 = 13,
  XSignalIsr_OsCore_Core1 = 14,
  XSignalIsr_OsCore_Core2 = 15,
  OS_ISRID_COUNT = 16,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifier. */
typedef enum
{
  Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms = 0,
  Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms = 1,
  Rte_Al_TE2_Default_BSW_Async_Task_Core0_10ms = 2,
  Rte_Al_TE2_EcuM_EcuM_MainFunction = 3,
  Rte_Al_TE3_EcuM_EcuM_MainFunction = 4,
  Rte_Al_TE_LinIf_LinIf_MainFunction = 5,
  Rte_Al_TE_disc_ecu_Core0_Task_100ms = 6,
  Rte_Al_TE_disc_ecu_Core0_Task_10ms = 7,
  Rte_Al_TE_disc_ecu_Core0_Task_20ms = 8,
  Rte_Al_TE_disc_ecu_Core0_Task_50ms = 9,
  OS_ALARMID_COUNT = 10
} AlarmType;

/*! Counter identifier. */
typedef enum
{
  SystemTimer_Core0 = 0,
  SystemTimer_Core1 = 1,
  SystemTimer_Core2 = 2,
  OS_COUNTERID_COUNT = 3
} CounterType;

/*! ScheduleTable identifier. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifier. */
typedef enum
{
  OsResource = 0,
  OS_RESOURCEID_COUNT = 1
} ResourceType;

/*! Spinlock identifier. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifier. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Trace thread identifier (Tasks and ISRs inclusive system objects). */
typedef enum
{
  OS_TRACE_THREADID_COUNT = 0,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifier (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = OS_SPINLOCKID_COUNT,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = OS_SPINLOCKID_COUNT + 0,
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/*! Barrier identifiers. */
typedef enum
{
  OsBarrier = 0,
  OS_BARRIERID_COUNT = 1
} Os_BarrierIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
