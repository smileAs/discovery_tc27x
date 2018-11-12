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
 *          File:  Os_Cfg.h
 *        Config:  discovery_ecu.dpa
 *   ECU-Project:  P2P
 *
 *     Generator:  MICROSAR RTE Generator Version 4.14.0
 *                 RTE Core Version 1.14.0
 *       License:  Unlimited license CBD1800319 for Tong Ji University
 *
 *   Description:  Os definitions
 *********************************************************************************************************************/

#ifndef _OS_CFG_H_
# define _OS_CFG_H_

/* Os definitions */

/* Tasks */
# define Default_BSW_Async_Task_Core0 (0U)
# define Default_BSW_Async_Task_Core1 (1U)
# define Default_BSW_Async_Task_Core2 (2U)

/* Alarms */
# define Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_10ms (0U)
# define Rte_Al_TE2_Default_BSW_Async_Task_Core0_0_20ms (1U)
# define Rte_Al_TE_LinIf_LinIf_MainFunction (2U)
# define Rte_Al_TE_disc_ecu_Core0_Task_100ms (3U)
# define Rte_Al_TE_disc_ecu_Core0_Task_10ms (4U)
# define Rte_Al_TE_disc_ecu_Core0_Task_20ms (5U)
# define Rte_Al_TE_disc_ecu_Core0_Task_50ms (6U)
# define Rte_Al_TE2_EcuM_EcuM_MainFunction (7U)
# define Rte_Al_TE3_EcuM_EcuM_MainFunction (8U)

/* Events */
# define Rte_Ev_Cyclic2_Default_BSW_Async_Task_Core0_0_10ms (0x01)
# define Rte_Ev_Cyclic2_Default_BSW_Async_Task_Core0_0_20ms (0x04)
# define Rte_Ev_Run_LinIf_LinIf_MainFunction (0x40)
# define Rte_Ev_Run_disc_ecu_Core0_Task_100ms (0x02)
# define Rte_Ev_Run_disc_ecu_Core0_Task_10ms (0x20)
# define Rte_Ev_Run_disc_ecu_Core0_Task_20ms (0x10)
# define Rte_Ev_Run_disc_ecu_Core0_Task_50ms (0x08)

/* Spinlocks */

/* Resources */

/* ScheduleTables */

/* Cores */
# define OS_CORE_ID_0 (0U)
# define OS_CORE_ID_1 (1U)
# define OS_CORE_ID_2 (2U)
# include "usrostyp.h"

/* Trusted Functions */


#endif /* _OS_CFG_H_ */
