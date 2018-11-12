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
 *              File: Os_XSignal_Lcfg.h
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
#if !defined (OS_XSIGNAL_LCFG_H)                                                     /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_XSIGNAL_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_XSignal_Types.h"

/* Os kernel module dependencies */
# include "Os_Error_Types.h"
# include "OsInt.h"

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

/*! Cross-core function identifiers. */
typedef enum
{
  /* USED */
  XSigFunctionIdx_ShutdownAllCores = 0,
  OS_XSIGFUNCTIONIDX_USEDCOUNT = 1,
  /* UNUSED */
  XSigFunctionIdx_ActivateTask = 1,
  XSigFunctionIdx_CancelAlarm = 2,
  XSigFunctionIdx_ControlIdle = 3,
  XSigFunctionIdx_GetAlarm = 4,
  XSigFunctionIdx_GetApplicationState = 5,
  XSigFunctionIdx_GetCounterValue = 6,
  XSigFunctionIdx_GetErrorHookStackUsage = 7,
  XSigFunctionIdx_GetEvent = 8,
  XSigFunctionIdx_GetISRStackUsage = 9,
  XSigFunctionIdx_GetKernelStackUsage = 10,
  XSigFunctionIdx_GetProtectionHookStackUsage = 11,
  XSigFunctionIdx_GetScheduleTableStatus = 12,
  XSigFunctionIdx_GetShutdownHookStackUsage = 13,
  XSigFunctionIdx_GetStartupHookStackUsage = 14,
  XSigFunctionIdx_GetTaskStackUsage = 15,
  XSigFunctionIdx_GetTaskState = 16,
  XSigFunctionIdx_HookCallCallback = 17,
  XSigFunctionIdx_NextScheduleTable = 18,
  XSigFunctionIdx_SetAbsAlarm = 19,
  XSigFunctionIdx_SetEvent = 20,
  XSigFunctionIdx_SetRelAlarm = 21,
  XSigFunctionIdx_StartScheduleTableAbs = 22,
  XSigFunctionIdx_StartScheduleTableRel = 23,
  XSigFunctionIdx_StopScheduleTable = 24,
  XSigFunctionIdx_TerminateApplication = 25,
  OS_XSIGFUNCTIONIDX_COUNT = 26
} Os_XSigFunctionIdx;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* X-Signal configuration data: OsCore_Core0 */
extern CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core0_FuncTable;
extern CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core0_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE_CORE0_PORTS + 1];
extern CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore_Core0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* X-Signal configuration data: OsCore_Core1 */
extern CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core1_FuncTable;
extern CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core1_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE_CORE1_PORTS + 1];
extern CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore_Core1;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* X-Signal configuration data: OsCore_Core2 */
extern CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core2_FuncTable;
extern CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core2_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE_CORE2_PORTS + 1];
extern CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore_Core2;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! X-Signal used services map. */
extern CONST(OSServiceIdType, OS_CONST) OsCfg_XSig_ServiceMap[OS_XSIGFUNCTIONIDX_USEDCOUNT + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_XSIGNAL_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_XSignal_Lcfg.h
 *********************************************************************************************************************/
