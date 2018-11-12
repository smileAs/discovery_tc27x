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
 *              File: Os_Isr_Lcfg.c
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

#define OS_ISR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Isr_Lcfg.h"
#include "Os_Isr.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_Timer.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"


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

/*! Dynamic ISR data: CanIsr_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_0_Dyn;

/*! Dynamic ISR data: CanIsr_1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_1_Dyn;

/*! Dynamic ISR data: CanIsr_2 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_2_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimerCore0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimerCore0_Dyn;

/*! Dynamic ISR data: Lin_Channel_1_EX_Extended_Error_Interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Lin_Channel_1_EX_Extended_Error_Interrupt_Dyn;

/*! Dynamic ISR data: Lin_Channel_1_RX_Receive_Interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Lin_Channel_1_RX_Receive_Interrupt_Dyn;

/*! Dynamic ISR data: Lin_Channel_1_TX_Transmit_Interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Lin_Channel_1_TX_Transmit_Interrupt_Dyn;

/*! Dynamic ISR data: Uart0_Err_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Uart0_Err_Isr_Dyn;

/*! Dynamic ISR data: Uart0_Rx_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Uart0_Rx_Isr_Dyn;

/*! Dynamic ISR data: Uart0_Tx_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Uart0_Tx_Isr_Dyn;

/*! Dynamic ISR data: XSignalIsr_OsCore_Core0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_XSignalIsr_OsCore_Core0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic ISR data: CounterIsr_SystemTimerCore1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimerCore1_Dyn;

/*! Dynamic ISR data: KEY_EVENT_Isr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_KEY_EVENT_Isr_Dyn;

/*! Dynamic ISR data: XSignalIsr_OsCore_Core1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_XSignalIsr_OsCore_Core1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic ISR data: CounterIsr_SystemTimerCore2 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimerCore2_Dyn;

/*! Dynamic ISR data: XSignalIsr_OsCore_Core2 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_XSignalIsr_OsCore_Core2_Dyn;

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

/*! ISR configuration data: CanIsr_0 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_CanIsr_0,
  /* .IsrId    = */ CanIsr_0
};

/*! ISR configuration data: CanIsr_1 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level4_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_CanIsr_1,
  /* .IsrId    = */ CanIsr_1
};

/*! ISR configuration data: CanIsr_2 */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_2 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_2,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level5_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_CanIsr_2,
  /* .IsrId    = */ CanIsr_2
};

/*! ISR configuration data: CounterIsr_SystemTimerCore0 */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimerCore0 =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimerCore0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimerCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore0,
  /* .IsrId    = */ CounterIsr_SystemTimerCore0
},
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core0)
};

/*! ISR configuration data: Lin_Channel_1_EX_Extended_Error_Interrupt */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Lin_Channel_1_EX_Extended_Error_Interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Lin_Channel_1_EX_Extended_Error_Interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Lin_Channel_1_EX_Extended_Error_Interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_Lin_Channel_1_EX_Extended_Error_Interrupt,
  /* .IsrId    = */ Lin_Channel_1_EX_Extended_Error_Interrupt
};

/*! ISR configuration data: Lin_Channel_1_RX_Receive_Interrupt */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Lin_Channel_1_RX_Receive_Interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Lin_Channel_1_RX_Receive_Interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Lin_Channel_1_RX_Receive_Interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_Lin_Channel_1_RX_Receive_Interrupt,
  /* .IsrId    = */ Lin_Channel_1_RX_Receive_Interrupt
};

/*! ISR configuration data: Lin_Channel_1_TX_Transmit_Interrupt */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Lin_Channel_1_TX_Transmit_Interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Lin_Channel_1_TX_Transmit_Interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level8_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Lin_Channel_1_TX_Transmit_Interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_Lin_Channel_1_TX_Transmit_Interrupt,
  /* .IsrId    = */ Lin_Channel_1_TX_Transmit_Interrupt
};

/*! ISR configuration data: Uart0_Err_Isr */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart0_Err_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Uart0_Err_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level11_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Uart0_Err_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_Uart0_Err_Isr,
  /* .IsrId    = */ Uart0_Err_Isr
};

/*! ISR configuration data: Uart0_Rx_Isr */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart0_Rx_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Uart0_Rx_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level10_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Uart0_Rx_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_Uart0_Rx_Isr,
  /* .IsrId    = */ Uart0_Rx_Isr
};

/*! ISR configuration data: Uart0_Tx_Isr */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart0_Tx_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Uart0_Tx_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level9_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Uart0_Tx_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_Uart0_Tx_Isr,
  /* .IsrId    = */ Uart0_Tx_Isr
};

/*! ISR configuration data: XSignalIsr_OsCore_Core0 */
CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core0 =
{
  /* .Isr           = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_XSignalIsr_OsCore_Core0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_XSignalIsr_OsCore_Core0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core0,
  /* .IsrId    = */ XSignalIsr_OsCore_Core0
},
  /* .FunctionTable = */ &OsCfg_Isr_XSignalIsr_OsCore_Core0_FuncTable,
  /* .RecvPortRefs  = */ OsCfg_Isr_XSignalIsr_OsCore_Core0_PortRefs,
  /* .RecvPortCount = */ OS_CFG_NUM_ISR_XSIGNALISR_OSCORE_CORE0_PORTS,
  /* .IntTrigger    = */ &OsCfg_Hal_XSig_XSignalIsr_OsCore_Core0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! ISR configuration data: CounterIsr_SystemTimerCore1 */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimerCore1 =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimerCore1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core1_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimerCore1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore1,
  /* .IsrId    = */ CounterIsr_SystemTimerCore1
},
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core1)
};

/*! ISR configuration data: KEY_EVENT_Isr */
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_KEY_EVENT_Isr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_KEY_EVENT_Isr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core1_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_KEY_EVENT_Isr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_Untrusted_BSW_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_KEY_EVENT_Isr,
  /* .IsrId    = */ KEY_EVENT_Isr
};

/*! ISR configuration data: XSignalIsr_OsCore_Core1 */
CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core1 =
{
  /* .Isr           = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_XSignalIsr_OsCore_Core1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core1_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core1_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_XSignalIsr_OsCore_Core1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core1,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core1,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core1_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core1,
  /* .IsrId    = */ XSignalIsr_OsCore_Core1
},
  /* .FunctionTable = */ &OsCfg_Isr_XSignalIsr_OsCore_Core1_FuncTable,
  /* .RecvPortRefs  = */ OsCfg_Isr_XSignalIsr_OsCore_Core1_PortRefs,
  /* .RecvPortCount = */ OS_CFG_NUM_ISR_XSIGNALISR_OSCORE_CORE1_PORTS,
  /* .IntTrigger    = */ &OsCfg_Hal_XSig_XSignalIsr_OsCore_Core1
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! ISR configuration data: CounterIsr_SystemTimerCore2 */
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimerCore2 =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimerCore2,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core2_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core2_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimerCore2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core2,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore2,
  /* .IsrId    = */ CounterIsr_SystemTimerCore2
},
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(OsCfg_Counter_SystemTimer_Core2)
};

/*! ISR configuration data: XSignalIsr_OsCore_Core2 */
CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core2 =
{
  /* .Isr           = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_XSignalIsr_OsCore_Core2,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore_Core2_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_Core2_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_XSignalIsr_OsCore_Core2_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_Core2,
    /* .Core                  = */ &OsCfg_Core_OsCore_Core2,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_Core2_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE
  },
  /* .HwConfig = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core2,
  /* .IsrId    = */ XSignalIsr_OsCore_Core2
},
  /* .FunctionTable = */ &OsCfg_Isr_XSignalIsr_OsCore_Core2_FuncTable,
  /* .RecvPortRefs  = */ OsCfg_Isr_XSignalIsr_OsCore_Core2_PortRefs,
  /* .RecvPortCount = */ OS_CFG_NUM_ISR_XSIGNALISR_OSCORE_CORE2_PORTS,
  /* .IntTrigger    = */ &OsCfg_Hal_XSig_XSignalIsr_OsCore_Core2
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for category 2 ISRs. */
CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_2),
  OS_TIMER_CASTCONFIG_TIMEREISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimerCore0),
  OS_TIMER_CASTCONFIG_TIMEREISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimerCore1),
  OS_TIMER_CASTCONFIG_TIMEREISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimerCore2),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_KEY_EVENT_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_Channel_1_EX_Extended_Error_Interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_Channel_1_RX_Receive_Interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_Channel_1_TX_Transmit_Interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart0_Err_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart0_Rx_Isr),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart0_Tx_Isr),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore_Core0),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore_Core1),
  OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(OsCfg_Isr_XSignalIsr_OsCore_Core2),
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
 *  END OF FILE: Os_Isr_Lcfg.c
 *********************************************************************************************************************/
