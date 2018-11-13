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
 *              File: Os_Scheduler_Cfg.h
 *   Generation Time: 2018-11-11 09:44:57
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
#if !defined (OS_SCHEDULER_CFG_H)                                                    /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_SCHEDULER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines the number of all task queues. */
# define OS_CFG_NUM_TASKQUEUES                   (8UL)

/* Number of task queue activation slots: OsCore_Core0 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE0_SLOTS     (3UL)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE0_SLOTS     (3UL)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE0_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE0_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE0_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE0_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE7_OSCORE_CORE0_SLOTS     (2UL)

/* Number of task queue activation slots: OsCore_Core1 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE1_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE1_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE1_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE1_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE1_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE1_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE1_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE7_OSCORE_CORE1_SLOTS     (2UL)

/* Number of task queue activation slots: OsCore_Core2 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE2_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE2_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE2_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE2_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE2_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE2_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE2_SLOTS     (1UL)
# define OS_CFG_NUM_TASKQUEUE7_OSCORE_CORE2_SLOTS     (2UL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_SCHEDULER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Cfg.h
 *********************************************************************************************************************/
