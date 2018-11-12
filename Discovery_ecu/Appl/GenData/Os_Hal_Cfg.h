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
 *              File: Os_Hal_Cfg.h
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
#if !defined (OS_HAL_CFG_H)                                                          /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (2U)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (3U)

/* ISR core and level definitions */
# define OS_ISR_CANISR_0_CORE      (0)
# define OS_ISR_CANISR_0_LEVEL     (10)
# define OS_ISR_CANISR_1_CORE      (0)
# define OS_ISR_CANISR_1_LEVEL     (11)
# define OS_ISR_CANISR_2_CORE      (0)
# define OS_ISR_CANISR_2_LEVEL     (12)
# define OS_ISR_COUNTERISR_SYSTEMTIMERCORE0_CORE      (0)
# define OS_ISR_COUNTERISR_SYSTEMTIMERCORE0_LEVEL     (5)
# define OS_ISR_COUNTERISR_SYSTEMTIMERCORE1_CORE      (1)
# define OS_ISR_COUNTERISR_SYSTEMTIMERCORE1_LEVEL     (17)
# define OS_ISR_COUNTERISR_SYSTEMTIMERCORE2_CORE      (2)
# define OS_ISR_COUNTERISR_SYSTEMTIMERCORE2_LEVEL     (18)
# define OS_ISR_KEY_EVENT_ISR_CORE      (1)
# define OS_ISR_KEY_EVENT_ISR_LEVEL     (33)
# define OS_ISR_LIN_CHANNEL_1_EX_EXTENDED_ERROR_INTERRUPT_CORE      (0)
# define OS_ISR_LIN_CHANNEL_1_EX_EXTENDED_ERROR_INTERRUPT_LEVEL     (22)
# define OS_ISR_LIN_CHANNEL_1_RX_RECEIVE_INTERRUPT_CORE      (0)
# define OS_ISR_LIN_CHANNEL_1_RX_RECEIVE_INTERRUPT_LEVEL     (23)
# define OS_ISR_LIN_CHANNEL_1_TX_TRANSMIT_INTERRUPT_CORE      (0)
# define OS_ISR_LIN_CHANNEL_1_TX_TRANSMIT_INTERRUPT_LEVEL     (24)
# define OS_ISR_UART0_ERR_ISR_CORE      (0)
# define OS_ISR_UART0_ERR_ISR_LEVEL     (32)
# define OS_ISR_UART0_RX_ISR_CORE      (0)
# define OS_ISR_UART0_RX_ISR_LEVEL     (31)
# define OS_ISR_UART0_TX_ISR_CORE      (0)
# define OS_ISR_UART0_TX_ISR_LEVEL     (30)
# define OS_ISR_XSIGNALISR_OSCORE_CORE0_CORE      (0)
# define OS_ISR_XSIGNALISR_OSCORE_CORE0_LEVEL     (0)
# define OS_ISR_XSIGNALISR_OSCORE_CORE1_CORE      (1)
# define OS_ISR_XSIGNALISR_OSCORE_CORE1_LEVEL     (0)
# define OS_ISR_XSIGNALISR_OSCORE_CORE2_CORE      (2)
# define OS_ISR_XSIGNALISR_OSCORE_CORE2_LEVEL     (0)

/* Hardware counter timing macros */

/* Counter timing macros and constants: SystemTimer_Core0 */
# define OSMAXALLOWEDVALUE_SystemTimer_Core0     (1073741823UL) /* 0x3FFFFFFFUL */
# define OSMINCYCLE_SystemTimer_Core0            (1UL)
# define OSTICKSPERBASE_SystemTimer_Core0        (1UL)
# define OSTICKDURATION_SystemTimer_Core0        (12UL)

/* OSEK compatibility for the system timer. */
# define OSMAXALLOWEDVALUE     (OSMAXALLOWEDVALUE_SystemTimer_Core0)
# define OSMINCYCLE            (OSMINCYCLE_SystemTimer_Core0)
# define OSTICKSPERBASE        (OSTICKSPERBASE_SystemTimer_Core0)
# define OSTICKDURATION        (OSTICKDURATION_SystemTimer_Core0)

/*! Macro OS_NS2TICKS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer_Core0(x)     ( (TickType) (((((uint32)(x)) * 2) + 12) / 25) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2NS_SystemTimer_Core0 was approximated with a deviation of 2.220446049250313E-10ppm. */
# define OS_TICKS2NS_SystemTimer_Core0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 25) + 1) / 2) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_US2TICKS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer_Core0(x)     ( (TickType) (((((uint32)(x)) * 80) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2US_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_SystemTimer_Core0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 40) / 80) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_MS2TICKS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer_Core0(x)     ( (TickType) (((((uint32)(x)) * 80000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2MS_SystemTimer_Core0 was approximated with a deviation of 2.220446049250313E-10ppm. */
# define OS_TICKS2MS_SystemTimer_Core0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 40000) / 80000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_SEC2TICKS_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer_Core0(x)     ( (TickType) (((((uint32)(x)) * 80000000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2SEC_SystemTimer_Core0 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer_Core0(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 40000000) / 80000000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */


/* Counter timing macros and constants: SystemTimer_Core1 */
# define OSMAXALLOWEDVALUE_SystemTimer_Core1     (1073741823UL) /* 0x3FFFFFFFUL */
# define OSMINCYCLE_SystemTimer_Core1            (1UL)
# define OSTICKSPERBASE_SystemTimer_Core1        (1UL)
# define OSTICKDURATION_SystemTimer_Core1        (25UL)

/*! Macro OS_NS2TICKS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer_Core1(x)     ( (TickType) (((((uint32)(x)) * 1) + 12) / 25) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2NS_SystemTimer_Core1 was approximated with a deviation of 2.220446049250313E-10ppm. */
# define OS_TICKS2NS_SystemTimer_Core1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 25) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_US2TICKS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer_Core1(x)     ( (TickType) (((((uint32)(x)) * 40) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2US_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_SystemTimer_Core1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 20) / 40) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_MS2TICKS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer_Core1(x)     ( (TickType) (((((uint32)(x)) * 40000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2MS_SystemTimer_Core1 was approximated with a deviation of 2.220446049250313E-10ppm. */
# define OS_TICKS2MS_SystemTimer_Core1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 20000) / 40000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_SEC2TICKS_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer_Core1(x)     ( (TickType) (((((uint32)(x)) * 40000000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2SEC_SystemTimer_Core1 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer_Core1(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 20000000) / 40000000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */


/* Counter timing macros and constants: SystemTimer_Core2 */
# define OSMAXALLOWEDVALUE_SystemTimer_Core2     (1073741823UL) /* 0x3FFFFFFFUL */
# define OSMINCYCLE_SystemTimer_Core2            (1UL)
# define OSTICKSPERBASE_SystemTimer_Core2        (1UL)
# define OSTICKDURATION_SystemTimer_Core2        (25UL)

/*! Macro OS_NS2TICKS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer_Core2(x)     ( (TickType) (((((uint32)(x)) * 1) + 12) / 25) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2NS_SystemTimer_Core2 was approximated with a deviation of 2.220446049250313E-10ppm. */
# define OS_TICKS2NS_SystemTimer_Core2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 25) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_US2TICKS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer_Core2(x)     ( (TickType) (((((uint32)(x)) * 40) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2US_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_SystemTimer_Core2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 20) / 40) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_MS2TICKS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer_Core2(x)     ( (TickType) (((((uint32)(x)) * 40000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2MS_SystemTimer_Core2 was approximated with a deviation of 2.220446049250313E-10ppm. */
# define OS_TICKS2MS_SystemTimer_Core2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 20000) / 40000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_SEC2TICKS_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer_Core2(x)     ( (TickType) (((((uint32)(x)) * 40000000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2SEC_SystemTimer_Core2 was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer_Core2(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 20000000) / 40000000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */







/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
