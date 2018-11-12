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
 *              File: Os_Scheduler_Lcfg.c
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

#define OS_SCHEDULER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Scheduler_Cfg.h"
#include "Os_Scheduler_Lcfg.h"
#include "Os_Scheduler.h"

/* Os kernel module dependencies */
#include "Os_BitArray.h"
#include "Os_Common.h"
#include "Os_Deque.h"

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

/*! Dynamic scheduler data: OsCore_Core0 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore_Core0_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore_Core0_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore_Core0_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore_Core0 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore_Core0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore_Core0_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore_Core0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore_Core0_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore_Core0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore_Core0_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore_Core0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore_Core0_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore_Core0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore_Core0_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore_Core0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore_Core0_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore_Core0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore_Core0_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE0_SLOTS];

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic scheduler data: OsCore_Core1 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore_Core1_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore_Core1_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore_Core1_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore_Core1 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore_Core1_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore_Core1_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore_Core1_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore_Core1_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore_Core1_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore_Core1_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore_Core1_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore_Core1_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore_Core1_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore_Core1_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore_Core1_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore_Core1_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore_Core1_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore_Core1_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE1_SLOTS];

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic scheduler data: OsCore_Core2 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore_Core2_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore_Core2_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore_Core2_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore_Core2 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore_Core2_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore_Core2_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore_Core2_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore_Core2_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore_Core2_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore_Core2_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore_Core2_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore_Core2_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore_Core2_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore_Core2_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore_Core2_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore_Core2_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore_Core2_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore_Core2_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE2_SLOTS];

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

/*! Task queues configuration data: OsCore_Core0 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore_Core0_TaskQueues[OS_CFG_NUM_TASKQUEUES];
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore_Core0_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue0_OsCore_Core0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue0_OsCore_Core0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes0_OsCore_Core0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue0_OsCore_Core0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue0_OsCore_Core0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes0_OsCore_Core0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE0_SLOTS
    }
  },
  /* [1] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue1_OsCore_Core0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue1_OsCore_Core0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes1_OsCore_Core0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue1_OsCore_Core0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue1_OsCore_Core0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes1_OsCore_Core0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE0_SLOTS
    }
  },
  /* [2] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue2_OsCore_Core0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue2_OsCore_Core0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes2_OsCore_Core0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue2_OsCore_Core0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue2_OsCore_Core0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes2_OsCore_Core0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE0_SLOTS
    }
  },
  /* [3] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue3_OsCore_Core0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue3_OsCore_Core0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes3_OsCore_Core0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue3_OsCore_Core0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue3_OsCore_Core0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes3_OsCore_Core0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE0_SLOTS
    }
  },
  /* [4] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue4_OsCore_Core0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue4_OsCore_Core0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes4_OsCore_Core0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue4_OsCore_Core0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue4_OsCore_Core0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes4_OsCore_Core0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE0_SLOTS
    }
  },
  /* [5] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue5_OsCore_Core0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue5_OsCore_Core0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes5_OsCore_Core0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue5_OsCore_Core0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue5_OsCore_Core0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes5_OsCore_Core0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE0_SLOTS
    }
  },
  /* [6] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue6_OsCore_Core0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue6_OsCore_Core0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes6_OsCore_Core0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue6_OsCore_Core0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue6_OsCore_Core0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes6_OsCore_Core0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE0_SLOTS
    }
  }
};

/*! Scheduler configuration data: OsCore_Core0 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore_Core0 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore_Core0_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore_Core0_BitField_Dyn,
    /* .Size      = */ OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore_Core0_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore_Core0_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Task queues configuration data: OsCore_Core1 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore_Core1_TaskQueues[OS_CFG_NUM_TASKQUEUES];
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore_Core1_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue0_OsCore_Core1_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue0_OsCore_Core1_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes0_OsCore_Core1_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE1_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue0_OsCore_Core1_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue0_OsCore_Core1_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes0_OsCore_Core1_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE1_SLOTS
    }
  },
  /* [1] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue1_OsCore_Core1_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue1_OsCore_Core1_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes1_OsCore_Core1_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE1_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue1_OsCore_Core1_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue1_OsCore_Core1_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes1_OsCore_Core1_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE1_SLOTS
    }
  },
  /* [2] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue2_OsCore_Core1_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue2_OsCore_Core1_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes2_OsCore_Core1_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE1_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue2_OsCore_Core1_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue2_OsCore_Core1_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes2_OsCore_Core1_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE1_SLOTS
    }
  },
  /* [3] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue3_OsCore_Core1_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue3_OsCore_Core1_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes3_OsCore_Core1_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE1_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue3_OsCore_Core1_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue3_OsCore_Core1_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes3_OsCore_Core1_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE1_SLOTS
    }
  },
  /* [4] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue4_OsCore_Core1_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue4_OsCore_Core1_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes4_OsCore_Core1_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE1_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue4_OsCore_Core1_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue4_OsCore_Core1_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes4_OsCore_Core1_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE1_SLOTS
    }
  },
  /* [5] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue5_OsCore_Core1_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue5_OsCore_Core1_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes5_OsCore_Core1_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE1_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue5_OsCore_Core1_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue5_OsCore_Core1_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes5_OsCore_Core1_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE1_SLOTS
    }
  },
  /* [6] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue6_OsCore_Core1_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue6_OsCore_Core1_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes6_OsCore_Core1_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE1_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue6_OsCore_Core1_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue6_OsCore_Core1_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes6_OsCore_Core1_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE1_SLOTS
    }
  }
};

/*! Scheduler configuration data: OsCore_Core1 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore_Core1 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore_Core1_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore_Core1_BitField_Dyn,
    /* .Size      = */ OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore_Core1_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore_Core1_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Task queues configuration data: OsCore_Core2 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore_Core2_TaskQueues[OS_CFG_NUM_TASKQUEUES];
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore_Core2_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue0_OsCore_Core2_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue0_OsCore_Core2_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes0_OsCore_Core2_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE2_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue0_OsCore_Core2_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue0_OsCore_Core2_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes0_OsCore_Core2_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE2_SLOTS
    }
  },
  /* [1] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue1_OsCore_Core2_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue1_OsCore_Core2_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes1_OsCore_Core2_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE2_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue1_OsCore_Core2_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue1_OsCore_Core2_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes1_OsCore_Core2_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE2_SLOTS
    }
  },
  /* [2] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue2_OsCore_Core2_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue2_OsCore_Core2_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes2_OsCore_Core2_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE2_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue2_OsCore_Core2_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue2_OsCore_Core2_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes2_OsCore_Core2_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE2_SLOTS
    }
  },
  /* [3] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue3_OsCore_Core2_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue3_OsCore_Core2_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes3_OsCore_Core2_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE2_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue3_OsCore_Core2_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue3_OsCore_Core2_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes3_OsCore_Core2_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE2_SLOTS
    }
  },
  /* [4] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue4_OsCore_Core2_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue4_OsCore_Core2_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes4_OsCore_Core2_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE2_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue4_OsCore_Core2_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue4_OsCore_Core2_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes4_OsCore_Core2_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE2_SLOTS
    }
  },
  /* [5] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue5_OsCore_Core2_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue5_OsCore_Core2_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes5_OsCore_Core2_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE2_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue5_OsCore_Core2_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue5_OsCore_Core2_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes5_OsCore_Core2_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE2_SLOTS
    }
  },
  /* [6] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue6_OsCore_Core2_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue6_OsCore_Core2_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes6_OsCore_Core2_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE2_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue6_OsCore_Core2_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue6_OsCore_Core2_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes6_OsCore_Core2_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE2_SLOTS
    }
  }
};

/*! Scheduler configuration data: OsCore_Core2 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore_Core2 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore_Core2_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore_Core2_BitField_Dyn,
    /* .Size      = */ OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore_Core2_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore_Core2_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
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
 *  END OF FILE: Os_Scheduler_Lcfg.c
 *********************************************************************************************************************/
