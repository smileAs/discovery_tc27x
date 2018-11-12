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
 *              File: Os_Barrier_Lcfg.c
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

#define OS_BARRIER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Barrier_Lcfg.h"
#include "Os_Barrier.h"

/* Os kernel module dependencies */
#include "Os_Common.h"

/* Os hal dependencies */
#include "Os_Hal_Kernel_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Defines the number of attendees for barrier OsBarrier. */
# define OS_CFG_NUM_BARRIER_OSBARRIER_ATTENDEE       (3UL)


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic barrier of core: OsCore_Core0 */
OS_LOCAL VAR(volatile Os_BarrierBaseType, OS_VAR_NOINIT) OsCfg_Barrier_OsCore_Core0_Dyn;

/*! Dynamic barrier of OsBarrier on OsCore_Core0 ( Default_BSW_Async_Task_Core0 ) */
OS_LOCAL VAR(volatile Os_BarrierBaseType, OS_VAR_NOINIT) OsCfg_Barrier_OsBarrier_OsCore_Core0_Dyn;

#define OS_STOP_SEC_BARRIER_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_BARRIER_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic barrier of core: OsCore_Core1 */
OS_LOCAL VAR(volatile Os_BarrierBaseType, OS_VAR_NOINIT) OsCfg_Barrier_OsCore_Core1_Dyn;

/*! Dynamic barrier of OsBarrier on OsCore_Core1 ( Default_BSW_Async_Task_Core1 ) */
OS_LOCAL VAR(volatile Os_BarrierBaseType, OS_VAR_NOINIT) OsCfg_Barrier_OsBarrier_OsCore_Core1_Dyn;

#define OS_STOP_SEC_BARRIER_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_BARRIER_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic barrier of core: OsCore_Core2 */
OS_LOCAL VAR(volatile Os_BarrierBaseType, OS_VAR_NOINIT) OsCfg_Barrier_OsCore_Core2_Dyn;

/*! Dynamic barrier of OsBarrier on OsCore_Core2 ( Default_BSW_Async_Task_Core2 ) */
OS_LOCAL VAR(volatile Os_BarrierBaseType, OS_VAR_NOINIT) OsCfg_Barrier_OsBarrier_OsCore_Core2_Dyn;

#define OS_STOP_SEC_BARRIER_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

OS_LOCAL CONST(Os_BarrierAttendeeRefType, OS_CONST) OsCfg_Barrier_AttendeeRefs[OS_COREASRCOREIDX_COUNT] =
{
  &OsCfg_Barrier_OsCore_Core0,
  &OsCfg_Barrier_OsCore_Core1,
  &OsCfg_Barrier_OsCore_Core2,
};

OS_LOCAL CONST(Os_BarrierAttendeeRefType, OS_CONST) OsCfg_Barrier_OsBarrier_AttendeeRefs[OS_CFG_NUM_BARRIER_OSBARRIER_ATTENDEE] =
{
  &OsCfg_Barrier_OsBarrier_OsCore_Core0,
  &OsCfg_Barrier_OsBarrier_OsCore_Core1,
  &OsCfg_Barrier_OsBarrier_OsCore_Core2
};


#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Barrier configuration data: OsCore_Core0 */
CONST(Os_BarrierBaseConfigType, OS_CONST) OsCfg_Barrier_OsCore_Core0 =
{
  /* .Dyn           = */ &OsCfg_Barrier_OsCore_Core0_Dyn,
  /* .AttendeeRefs  = */ OsCfg_Barrier_AttendeeRefs,
  /* .AttendeeCount = */ OS_COREASRCOREIDX_COUNT,
  /* .TaskPtr       = */ NULL_PTR,
  /* .CheckOsStart  = */ FALSE
};

/*! Barrier configuration data: OsBarrier on OsCore_Core0 ( Default_BSW_Async_Task_Core0 ) */
CONST(Os_BarrierBaseConfigType, OS_CONST) OsCfg_Barrier_OsBarrier_OsCore_Core0 =
{
  /* .Dyn           = */ &OsCfg_Barrier_OsBarrier_OsCore_Core0_Dyn,
  /* .AttendeeRefs  = */ OsCfg_Barrier_OsBarrier_AttendeeRefs,
  /* .AttendeeCount = */ OS_CFG_NUM_BARRIER_OSBARRIER_ATTENDEE,
  /* .TaskPtr       = */ &OsCfg_Task_Default_BSW_Async_Task_Core0,
  /* .CheckOsStart  = */ TRUE
};


#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Barrier configuration data: OsCore_Core1 */
CONST(Os_BarrierBaseConfigType, OS_CONST) OsCfg_Barrier_OsCore_Core1 =
{
  /* .Dyn           = */ &OsCfg_Barrier_OsCore_Core1_Dyn,
  /* .AttendeeRefs  = */ OsCfg_Barrier_AttendeeRefs,
  /* .AttendeeCount = */ OS_COREASRCOREIDX_COUNT,
  /* .TaskPtr       = */ NULL_PTR,
  /* .CheckOsStart  = */ FALSE
};

/*! Barrier configuration data: OsBarrier on OsCore_Core1 ( Default_BSW_Async_Task_Core1 ) */
CONST(Os_BarrierBaseConfigType, OS_CONST) OsCfg_Barrier_OsBarrier_OsCore_Core1 =
{
  /* .Dyn           = */ &OsCfg_Barrier_OsBarrier_OsCore_Core1_Dyn,
  /* .AttendeeRefs  = */ OsCfg_Barrier_OsBarrier_AttendeeRefs,
  /* .AttendeeCount = */ OS_CFG_NUM_BARRIER_OSBARRIER_ATTENDEE,
  /* .TaskPtr       = */ &OsCfg_Task_Default_BSW_Async_Task_Core1,
  /* .CheckOsStart  = */ TRUE
};


#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Barrier configuration data: OsCore_Core2 */
CONST(Os_BarrierBaseConfigType, OS_CONST) OsCfg_Barrier_OsCore_Core2 =
{
  /* .Dyn           = */ &OsCfg_Barrier_OsCore_Core2_Dyn,
  /* .AttendeeRefs  = */ OsCfg_Barrier_AttendeeRefs,
  /* .AttendeeCount = */ OS_COREASRCOREIDX_COUNT,
  /* .TaskPtr       = */ NULL_PTR,
  /* .CheckOsStart  = */ FALSE
};

/*! Barrier configuration data: OsBarrier on OsCore_Core2 ( Default_BSW_Async_Task_Core2 ) */
CONST(Os_BarrierBaseConfigType, OS_CONST) OsCfg_Barrier_OsBarrier_OsCore_Core2 =
{
  /* .Dyn           = */ &OsCfg_Barrier_OsBarrier_OsCore_Core2_Dyn,
  /* .AttendeeRefs  = */ OsCfg_Barrier_OsBarrier_AttendeeRefs,
  /* .AttendeeCount = */ OS_CFG_NUM_BARRIER_OSBARRIER_ATTENDEE,
  /* .TaskPtr       = */ &OsCfg_Task_Default_BSW_Async_Task_Core2,
  /* .CheckOsStart  = */ TRUE
};


#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Barrier_Lcfg.c
 *********************************************************************************************************************/
