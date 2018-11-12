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
 *              File: Os_Hal_Core_Lcfg.c
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

#define OS_HAL_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Core.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"
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

#define OS_START_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL dynamic core to thread data: OsCore_Core0 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore_Core0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL dynamic core to thread data: OsCore_Core1 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore_Core1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL dynamic core to thread data: OsCore_Core2 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore_Core2_Dyn;

#define OS_STOP_SEC_CORE2_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL core initialized interrupt sources: OsCore_Core0 */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore_Core0_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE_CORE0_INTERRUPTSOURCEREFS + 1] =
{
  /* No core exclusive interrupt sources to be initialized by OsCore_Core0. */
  NULL_PTR
};


/*! HAL core configuration data: OsCore_Core0 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore_Core0 =
{
  /* .CoreId                  = */ 0, /* Physical id of OsCore_Core0 */
  /* .ProgramCounterRegister  = */ 0,
  /* .StartLabelAddress       = */ 0,
  /* .DBGSRRegister           = */ 0,
  /* .SYSCONRegister          = */ 0
}
;

/*! HAL AUTOSAR core configuration data: OsCore_Core0 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore_Core0 =
{
  /* .CoreId        = */ 0, /* This is the logical id of the core */
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL core initialized interrupt sources: OsCore_Core1 */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore_Core1_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE_CORE1_INTERRUPTSOURCEREFS + 1] =
{
  /* No core exclusive interrupt sources to be initialized by OsCore_Core1. */
  NULL_PTR
};


/*! HAL core configuration data: OsCore_Core1 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore_Core1 =
{
  /* .CoreId                  = */ 1, /* Physical id of OsCore_Core1 */
  /* .ProgramCounterRegister  = */ OS_HAL_CORE1_PC,
  /* .StartLabelAddress       = */ (uint32)&(_start_tc1), /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .DBGSRRegister           = */ OS_HAL_CORE1_DBGSR,
  /* .SYSCONRegister          = */ OS_HAL_CORE1_SYSCON
}
;

/*! HAL AUTOSAR core configuration data: OsCore_Core1 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore_Core1 =
{
  /* .CoreId        = */ 1, /* This is the logical id of the core */
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL core initialized interrupt sources: OsCore_Core2 */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore_Core2_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE_CORE2_INTERRUPTSOURCEREFS + 1] =
{
  /* No core exclusive interrupt sources to be initialized by OsCore_Core2. */
  NULL_PTR
};


/*! HAL core configuration data: OsCore_Core2 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore_Core2 =
{
  /* .CoreId                  = */ 2, /* Physical id of OsCore_Core2 */
  /* .ProgramCounterRegister  = */ OS_HAL_CORE2_PC,
  /* .StartLabelAddress       = */ (uint32)&(_start_tc2), /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .DBGSRRegister           = */ OS_HAL_CORE2_DBGSR,
  /* .SYSCONRegister          = */ OS_HAL_CORE2_SYSCON
}
;

/*! HAL AUTOSAR core configuration data: OsCore_Core2 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore_Core2 =
{
  /* .CoreId        = */ 2, /* This is the logical id of the core */
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL core to thread configuration data. */
CONST(Os_Hal_Core2ThreadConfigType, OS_CONST) OsCfg_Hal_Core2Thread =
{
  /* .Core2Thread = */
  {
    &OsCfg_Hal_Core2Thread_OsCore_Core0_Dyn, /* OS_CORE_ID_0 */
    &OsCfg_Hal_Core2Thread_OsCore_Core1_Dyn, /* OS_CORE_ID_1 */
    &OsCfg_Hal_Core2Thread_OsCore_Core2_Dyn, /* OS_CORE_ID_2 */
  }
};

/*! HAL system configuration data. */
CONST(Os_Hal_SystemConfigType, OS_CONST) OsCfg_Hal_System =
0;

/*! Interrupt sources which are initialized by the hardware init core. */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_System_InterruptSourceRefs[OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS + 1] =
{
  &OsCfg_Hal_IntIsr_CanIsr_0,
  &OsCfg_Hal_IntIsr_CanIsr_1,
  &OsCfg_Hal_IntIsr_CanIsr_2,
  &OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore0,
  &OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore1,
  &OsCfg_Hal_IntIsr_CounterIsr_SystemTimerCore2,
  &OsCfg_Hal_IntIsr_KEY_EVENT_Isr,
  &OsCfg_Hal_IntIsr_Lin_Channel_1_EX_Extended_Error_Interrupt,
  &OsCfg_Hal_IntIsr_Lin_Channel_1_RX_Receive_Interrupt,
  &OsCfg_Hal_IntIsr_Lin_Channel_1_TX_Transmit_Interrupt,
  &OsCfg_Hal_IntIsr_Uart0_Err_Isr,
  &OsCfg_Hal_IntIsr_Uart0_Rx_Isr,
  &OsCfg_Hal_IntIsr_Uart0_Tx_Isr,
  &OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core0,
  &OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core1,
  &OsCfg_Hal_IntIsr_XSignalIsr_OsCore_Core2,
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
 *  END OF FILE: Os_Hal_Core_Lcfg.c
 *********************************************************************************************************************/

