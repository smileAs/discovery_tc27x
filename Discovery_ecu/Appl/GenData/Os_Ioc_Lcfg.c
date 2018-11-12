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
 *              File: Os_Ioc_Lcfg.c
 *   Generation Time: 2018-08-07 08:44:58
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

#define OS_IOC_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"
#include "vstdlib.h"

/* Os module declarations */
#include "Os_Ioc_Cfg.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Ioc_Types.h"
#include "Os_Ioc.h"
#include "Ioc.h"

/* Os kernel module dependencies */
#include "Os_Fifo08.h"
#include "Os_Fifo16.h"
#include "Os_Fifo32.h"
#include "Os_FifoPtr.h"
#include "Os_Hook.h"
#include "Os_Spinlock_Lcfg.h"
#include "OsInt.h"

/* Os hal dependencies */

/* User file includes */
# include "Rte.h"


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
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic IOC receive data: OsIocCommunication */
OS_LOCAL VAR(Os_Ioc32ReceiveType, OS_VAR_NOINIT) OsCfg_IocRecv_OsIocCommunication_Dyn;

#define OS_STOP_SEC_SystemApplication_OsCore_Core1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic IOC send data: OsIocCommunication */
OS_LOCAL VAR(Os_Ioc32SendType, OS_VAR_NOINIT) OsCfg_IocSend_OsIocCommunication_Dyn;

/*! IOC communication data queue: OsIocCommunication */
OS_LOCAL VAR(Os_Fifo32NodeType, OS_APPL_DATA)
  OsCfg_Ioc_OsIocCommunication_Buffer_Dyn[OS_CFG_SIZE_IOC_OSIOCCOMMUNICATION_BUFFER];

#define OS_STOP_SEC_SystemApplication_OsCore_Core0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! IOC receive configuration data: OsIocCommunication */
CONST(Os_Ioc32ReceiveConfigType, OS_CONST) OsCfg_IocRecv_OsIocCommunication =
{
  /* .Ioc      = */
  {
    /* .Base     = */
    {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_NONE,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOC32RECEIVE_2_IOC(OsCfg_IocRecv_OsIocCommunication_Dyn),
      /* .SubClass              = */ Ioc32Receive,
      /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore_Core1)
    },
    /* .Send     = */ &(OsCfg_IocSend_OsIocCommunication.Ioc)
  },
  /* .FifoRead = */
  {
    /* .Dyn     = */ &(OsCfg_IocRecv_OsIocCommunication_Dyn.FifoRead),
    /* .Read    = */ &(OsCfg_IocSend_OsIocCommunication_Dyn.FifoWrite),
    /* .Data    = */ OsCfg_Ioc_OsIocCommunication_Buffer_Dyn,
    /* .Size    = */ OS_CFG_SIZE_IOC_OSIOCCOMMUNICATION_BUFFER
  }
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! IOC send configuration data: OsIocCommunication */
CONST(Os_Ioc32SendConfigType, OS_CONST) OsCfg_IocSend_OsIocCommunication =
{
  /* .Ioc       = */
  {
    /* .Base     = */
    {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_NONE,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOC32SEND_2_IOC(OsCfg_IocSend_OsIocCommunication_Dyn),
      /* .SubClass              = */ Ioc32Send,
      /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore_Core0)
    },
    /* .Callback = */
    {
      /* .CallbackRefs  = */ NULL_PTR,
      /* .CallbackCount = */ OS_CFG_NUM_IOC_OSIOCCOMMUNICATION_CALLBACKS
    },
    /* .Receive  = */ &(OsCfg_IocRecv_OsIocCommunication.Ioc)
  },
  /* .FifoWrite = */
  {
    /* .Dyn      = */ &(OsCfg_IocSend_OsIocCommunication_Dyn.FifoWrite),
    /* .Read     = */ &(OsCfg_IocRecv_OsIocCommunication_Dyn.FifoRead),
    /* .Data     = */ OsCfg_Ioc_OsIocCommunication_Buffer_Dyn,
    /* .Size     = */ OS_CFG_SIZE_IOC_OSIOCCOMMUNICATION_BUFFER
  }
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  IocReceive_OsIocCommunication()
 *********************************************************************************************************************/
Std_ReturnType IocReceive_OsIocCommunication /* PRQA S 3219 */ /* MD_Os_3219 */
(
  uint32 *Arg0
)
{
  Std_ReturnType status;
  uint32 localVar;

  /* Redirect call to the general receive function. */
  status = Os_TrapIoc32Receive(FALSE, &OsCfg_IocRecv_OsIocCommunication, (P2VAR(uint32, AUTOMATIC, OS_APPL_DATA)) &localVar); /* PRQA S 0310 */ /* MD_Os_0310 */
  (*Arg0) = localVar;

  return status;
}

/**********************************************************************************************************************
 *  IocSend_OsIocCommunication()
 *********************************************************************************************************************/
Std_ReturnType IocSend_OsIocCommunication /* PRQA S 3219 */ /* MD_Os_3219 */
(
  uint32 Arg0
)
{
  /* Redirect call to the general send function. */
  return Os_TrapIoc32Send(FALSE, &OsCfg_IocSend_OsIocCommunication, (uint32) Arg0);
}

/**********************************************************************************************************************
 *  IocEmptyQueue_OsIocCommunication()
 *********************************************************************************************************************/
Std_ReturnType IocEmptyQueue_OsIocCommunication(void)
{
  /* Redirect call to the general empty function. */
  return Os_TrapIoc32EmptyQueue(FALSE, &OsCfg_IocRecv_OsIocCommunication);
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  END OF FILE: Os_Ioc_Lcfg.c
 *********************************************************************************************************************/
