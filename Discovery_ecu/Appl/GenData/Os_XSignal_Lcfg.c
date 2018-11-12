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
 *              File: Os_XSignal_Lcfg.c
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

#define OS_XSIGNAL_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os kernel module dependencies */
#include "Os_Common.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"

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

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! X-Signal send port configuration data: OsCore_Core0 -> OsCore_Core1/XSignalIsr_OsCore_Core1_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core0_Send0;

/*! X-Signal send port configuration data: OsCore_Core0 -> OsCore_Core2/XSignalIsr_OsCore_Core2_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core0_Send1;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core0_Recv0 <- OsCore_Core1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core0_Recv0;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core0_Recv1 <- OsCore_Core2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core0_Recv1;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! X-Signal send port configuration data: OsCore_Core1 -> OsCore_Core0/XSignalIsr_OsCore_Core0_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core1_Send0;

/*! X-Signal send port configuration data: OsCore_Core1 -> OsCore_Core2/XSignalIsr_OsCore_Core2_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core1_Send1;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core1_Recv0 <- OsCore_Core0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core1_Recv0;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core1_Recv1 <- OsCore_Core2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core1_Recv1;

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! X-Signal send port configuration data: OsCore_Core2 -> OsCore_Core0/XSignalIsr_OsCore_Core0_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core2_Send0;

/*! X-Signal send port configuration data: OsCore_Core2 -> OsCore_Core1/XSignalIsr_OsCore_Core1_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core2_Send1;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core2_Recv0 <- OsCore_Core0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core2_Recv0;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core2_Recv1 <- OsCore_Core1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core2_Recv1;

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Dynamic X-Signal send port data: OsCore_Core0 -> OsCore_Core1/XSignalIsr_OsCore_Core1_Recv0 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core0_Send0_XSignalIsr_OsCore_Core1_Recv0_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore_Core0_Send0_Data[OS_CFG_SIZE_OSCORE_CORE0_SEND0_XSIGNALISR_OSCORE_CORE1_RECV0_BUFFER];

/* Dynamic X-Signal send port data: OsCore_Core0 -> OsCore_Core2/XSignalIsr_OsCore_Core2_Recv0 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core0_Send1_XSignalIsr_OsCore_Core2_Recv0_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore_Core0_Send1_Data[OS_CFG_SIZE_OSCORE_CORE0_SEND1_XSIGNALISR_OSCORE_CORE2_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore_Core0_Recv0 <- OsCore_Core1 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core1_Send0_XSignalIsr_OsCore_Core0_Recv0_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore_Core0_Recv0_Data[OS_CFG_SIZE_OSCORE_CORE1_SEND0_XSIGNALISR_OSCORE_CORE0_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore_Core0_Recv1 <- OsCore_Core2 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core2_Send0_XSignalIsr_OsCore_Core0_Recv1_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore_Core0_Recv1_Data[OS_CFG_SIZE_OSCORE_CORE2_SEND0_XSIGNALISR_OSCORE_CORE0_RECV1_BUFFER];

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Dynamic X-Signal send port data: OsCore_Core1 -> OsCore_Core0/XSignalIsr_OsCore_Core0_Recv0 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core1_Send0_XSignalIsr_OsCore_Core0_Recv0_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore_Core1_Send0_Data[OS_CFG_SIZE_OSCORE_CORE1_SEND0_XSIGNALISR_OSCORE_CORE0_RECV0_BUFFER];

/* Dynamic X-Signal send port data: OsCore_Core1 -> OsCore_Core2/XSignalIsr_OsCore_Core2_Recv1 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core1_Send1_XSignalIsr_OsCore_Core2_Recv1_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore_Core1_Send1_Data[OS_CFG_SIZE_OSCORE_CORE1_SEND1_XSIGNALISR_OSCORE_CORE2_RECV1_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore_Core1_Recv0 <- OsCore_Core0 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core0_Send0_XSignalIsr_OsCore_Core1_Recv0_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore_Core1_Recv0_Data[OS_CFG_SIZE_OSCORE_CORE0_SEND0_XSIGNALISR_OSCORE_CORE1_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore_Core1_Recv1 <- OsCore_Core2 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core2_Send1_XSignalIsr_OsCore_Core1_Recv1_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore_Core1_Recv1_Data[OS_CFG_SIZE_OSCORE_CORE2_SEND1_XSIGNALISR_OSCORE_CORE1_RECV1_BUFFER];

#define OS_STOP_SEC_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Dynamic X-Signal send port data: OsCore_Core2 -> OsCore_Core0/XSignalIsr_OsCore_Core0_Recv1 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core2_Send0_XSignalIsr_OsCore_Core0_Recv1_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore_Core2_Send0_Data[OS_CFG_SIZE_OSCORE_CORE2_SEND0_XSIGNALISR_OSCORE_CORE0_RECV1_BUFFER];

/* Dynamic X-Signal send port data: OsCore_Core2 -> OsCore_Core1/XSignalIsr_OsCore_Core1_Recv1 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core2_Send1_XSignalIsr_OsCore_Core1_Recv1_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore_Core2_Send1_Data[OS_CFG_SIZE_OSCORE_CORE2_SEND1_XSIGNALISR_OSCORE_CORE1_RECV1_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore_Core2_Recv0 <- OsCore_Core0 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core0_Send1_XSignalIsr_OsCore_Core2_Recv0_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore_Core2_Recv0_Data[OS_CFG_SIZE_OSCORE_CORE0_SEND1_XSIGNALISR_OSCORE_CORE2_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore_Core2_Recv1 <- OsCore_Core1 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore_Core1_Send1_XSignalIsr_OsCore_Core2_Recv1_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore_Core2_Recv1_Data[OS_CFG_SIZE_OSCORE_CORE1_SEND1_XSIGNALISR_OSCORE_CORE2_RECV1_BUFFER];

#define OS_STOP_SEC_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! X-Signal used services map. */
CONST(OSServiceIdType, OS_CONST) OsCfg_XSig_ServiceMap[OS_XSIGFUNCTIONIDX_USEDCOUNT + 1] =
{
  OSServiceId_ShutdownAllCores,
  OSSERVICEID_COUNT
};

/*! X-Signal data buffer: OsCore_Core0 -> OsCore_Core1/XSignalIsr_OsCore_Core1_Recv0 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore_Core0_Send0_XSignalIsr_OsCore_Core1_Recv0_Buffer_Dyn[OS_CFG_SIZE_OSCORE_CORE0_SEND0_XSIGNALISR_OSCORE_CORE1_RECV0_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore_Core0_Send0_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core1_Recv0_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore_Core0_Send0_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core1_Recv0_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore_Core0 -> OsCore_Core2/XSignalIsr_OsCore_Core2_Recv0 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore_Core0_Send1_XSignalIsr_OsCore_Core2_Recv0_Buffer_Dyn[OS_CFG_SIZE_OSCORE_CORE0_SEND1_XSIGNALISR_OSCORE_CORE2_RECV0_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore_Core0_Send1_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core2_Recv0_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore_Core0_Send1_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core2_Recv0_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore_Core1 -> OsCore_Core0/XSignalIsr_OsCore_Core0_Recv0 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore_Core1_Send0_XSignalIsr_OsCore_Core0_Recv0_Buffer_Dyn[OS_CFG_SIZE_OSCORE_CORE1_SEND0_XSIGNALISR_OSCORE_CORE0_RECV0_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore_Core1_Send0_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core0_Recv0_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore_Core1_Send0_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core0_Recv0_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore_Core1 -> OsCore_Core2/XSignalIsr_OsCore_Core2_Recv1 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore_Core1_Send1_XSignalIsr_OsCore_Core2_Recv1_Buffer_Dyn[OS_CFG_SIZE_OSCORE_CORE1_SEND1_XSIGNALISR_OSCORE_CORE2_RECV1_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore_Core1_Send1_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core2_Recv1_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore_Core1_Send1_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core2_Recv1_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore_Core2 -> OsCore_Core0/XSignalIsr_OsCore_Core0_Recv1 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore_Core2_Send0_XSignalIsr_OsCore_Core0_Recv1_Buffer_Dyn[OS_CFG_SIZE_OSCORE_CORE2_SEND0_XSIGNALISR_OSCORE_CORE0_RECV1_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore_Core2_Send0_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core0_Recv1_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore_Core2_Send0_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core0_Recv1_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore_Core2 -> OsCore_Core1/XSignalIsr_OsCore_Core1_Recv1 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore_Core2_Send1_XSignalIsr_OsCore_Core1_Recv1_Buffer_Dyn[OS_CFG_SIZE_OSCORE_CORE2_SEND1_XSIGNALISR_OSCORE_CORE1_RECV1_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore_Core2_Send1_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core1_Recv1_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore_Core2_Send1_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore_Core1_Recv1_Data[1]),
    /* .Idx      = */ 1
  }
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! X-Signal send port configuration data: OsCore_Core0 -> OsCore_Core1/XSignalIsr_OsCore_Core1_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core0_Send0 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core0_Send0_XSignalIsr_OsCore_Core1_Recv0_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore_Core0_Send0_XSignalIsr_OsCore_Core1_Recv0_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core0_Send0_XSignalIsr_OsCore_Core1_Recv0_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE0_SEND0_XSIGNALISR_OSCORE_CORE1_RECV0_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore_Core1,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore_Core1_Recv0,
  /* .SendCore    = */ &OsCfg_Core_OsCore_Core0
};

/*! X-Signal send port configuration data: OsCore_Core0 -> OsCore_Core2/XSignalIsr_OsCore_Core2_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core0_Send1 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core0_Send1_XSignalIsr_OsCore_Core2_Recv0_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore_Core0_Send1_XSignalIsr_OsCore_Core2_Recv0_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core0_Send1_XSignalIsr_OsCore_Core2_Recv0_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE0_SEND1_XSIGNALISR_OSCORE_CORE2_RECV0_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore_Core2,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore_Core2_Recv0,
  /* .SendCore    = */ &OsCfg_Core_OsCore_Core0
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core0_Recv0 <- OsCore_Core1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core0_Recv0 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core1_Send0_XSignalIsr_OsCore_Core0_Recv0_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore_Core1_Send0_XSignalIsr_OsCore_Core0_Recv0_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core1_Send0_XSignalIsr_OsCore_Core0_Recv0_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE1_SEND0_XSIGNALISR_OSCORE_CORE0_RECV0_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore_Core1_Send0
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core0_Recv1 <- OsCore_Core2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core0_Recv1 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core2_Send0_XSignalIsr_OsCore_Core0_Recv1_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore_Core2_Send0_XSignalIsr_OsCore_Core0_Recv1_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core2_Send0_XSignalIsr_OsCore_Core0_Recv1_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE2_SEND0_XSIGNALISR_OSCORE_CORE0_RECV1_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore_Core2_Send0
};

/*! X-Signal ISR function table: XSignalIsr_OsCore_Core0 */
CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core0_FuncTable =
{
  /* .FunctionDescription = */
  {
    { Os_XSigRecv_ShutdownAllCores }, /* OSServiceId_ShutdownAllCores */
    { NULL_PTR }
  }
};

/*! X-Signal ISR receive ports reference table: XSignalIsr_OsCore_Core0 */
CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core0_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE_CORE0_PORTS + 1] =
{
  &OsCfg_XSig_XSignalIsr_OsCore_Core0_Recv0,
  &OsCfg_XSig_XSignalIsr_OsCore_Core0_Recv1,
  NULL_PTR
};

/*! X-Signal receiver ISRs reference table: OsCore_Core0 */
OS_LOCAL CONST(Os_XSigIsrConfigRefType, OS_CONST) OsCfg_XSig_OsCore_Core0_IsrRefs[OS_CFG_NUM_XSIG_OSCORE_CORE0_ISRS + 1] =
{
  &OsCfg_Isr_XSignalIsr_OsCore_Core0,
  NULL_PTR
};

/*! X-Signal configuration data: OsCore_Core0 */
CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore_Core0 =
{
  /* .XSigSendPorts    = */ 
  {
    /* [0] = */ NULL_PTR, /* OsCore_Core0 */
    /* [1] = */ &OsCfg_XSig_OsCore_Core0_Send0, /* OsCore_Core1 */
    /* [2] = */ &OsCfg_XSig_OsCore_Core0_Send1 /* OsCore_Core2 */
  },
  /* .XSigRecvIsrRefs  = */ OsCfg_XSig_OsCore_Core0_IsrRefs,
  /* .XSigRecvIsrCount = */ OS_CFG_NUM_XSIG_OSCORE_CORE0_ISRS
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! X-Signal send port configuration data: OsCore_Core1 -> OsCore_Core0/XSignalIsr_OsCore_Core0_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core1_Send0 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core1_Send0_XSignalIsr_OsCore_Core0_Recv0_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore_Core1_Send0_XSignalIsr_OsCore_Core0_Recv0_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core1_Send0_XSignalIsr_OsCore_Core0_Recv0_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE1_SEND0_XSIGNALISR_OSCORE_CORE0_RECV0_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore_Core0,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore_Core0_Recv0,
  /* .SendCore    = */ &OsCfg_Core_OsCore_Core1
};

/*! X-Signal send port configuration data: OsCore_Core1 -> OsCore_Core2/XSignalIsr_OsCore_Core2_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core1_Send1 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core1_Send1_XSignalIsr_OsCore_Core2_Recv1_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore_Core1_Send1_XSignalIsr_OsCore_Core2_Recv1_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core1_Send1_XSignalIsr_OsCore_Core2_Recv1_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE1_SEND1_XSIGNALISR_OSCORE_CORE2_RECV1_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore_Core2,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore_Core2_Recv1,
  /* .SendCore    = */ &OsCfg_Core_OsCore_Core1
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core1_Recv0 <- OsCore_Core0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core1_Recv0 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core0_Send0_XSignalIsr_OsCore_Core1_Recv0_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore_Core0_Send0_XSignalIsr_OsCore_Core1_Recv0_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core0_Send0_XSignalIsr_OsCore_Core1_Recv0_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE0_SEND0_XSIGNALISR_OSCORE_CORE1_RECV0_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore_Core0_Send0
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core1_Recv1 <- OsCore_Core2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core1_Recv1 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core2_Send1_XSignalIsr_OsCore_Core1_Recv1_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore_Core2_Send1_XSignalIsr_OsCore_Core1_Recv1_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core2_Send1_XSignalIsr_OsCore_Core1_Recv1_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE2_SEND1_XSIGNALISR_OSCORE_CORE1_RECV1_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore_Core2_Send1
};

/*! X-Signal ISR function table: XSignalIsr_OsCore_Core1 */
CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core1_FuncTable =
{
  /* .FunctionDescription = */
  {
    { Os_XSigRecv_ShutdownAllCores }, /* OSServiceId_ShutdownAllCores */
    { NULL_PTR }
  }
};

/*! X-Signal ISR receive ports reference table: XSignalIsr_OsCore_Core1 */
CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core1_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE_CORE1_PORTS + 1] =
{
  &OsCfg_XSig_XSignalIsr_OsCore_Core1_Recv0,
  &OsCfg_XSig_XSignalIsr_OsCore_Core1_Recv1,
  NULL_PTR
};

/*! X-Signal receiver ISRs reference table: OsCore_Core1 */
OS_LOCAL CONST(Os_XSigIsrConfigRefType, OS_CONST) OsCfg_XSig_OsCore_Core1_IsrRefs[OS_CFG_NUM_XSIG_OSCORE_CORE1_ISRS + 1] =
{
  &OsCfg_Isr_XSignalIsr_OsCore_Core1,
  NULL_PTR
};

/*! X-Signal configuration data: OsCore_Core1 */
CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore_Core1 =
{
  /* .XSigSendPorts    = */ 
  {
    /* [0] = */ &OsCfg_XSig_OsCore_Core1_Send0, /* OsCore_Core0 */
    /* [1] = */ NULL_PTR, /* OsCore_Core1 */
    /* [2] = */ &OsCfg_XSig_OsCore_Core1_Send1 /* OsCore_Core2 */
  },
  /* .XSigRecvIsrRefs  = */ OsCfg_XSig_OsCore_Core1_IsrRefs,
  /* .XSigRecvIsrCount = */ OS_CFG_NUM_XSIG_OSCORE_CORE1_ISRS
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! X-Signal send port configuration data: OsCore_Core2 -> OsCore_Core0/XSignalIsr_OsCore_Core0_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core2_Send0 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core2_Send0_XSignalIsr_OsCore_Core0_Recv1_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore_Core2_Send0_XSignalIsr_OsCore_Core0_Recv1_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core2_Send0_XSignalIsr_OsCore_Core0_Recv1_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE2_SEND0_XSIGNALISR_OSCORE_CORE0_RECV1_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore_Core0,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore_Core0_Recv1,
  /* .SendCore    = */ &OsCfg_Core_OsCore_Core2
};

/*! X-Signal send port configuration data: OsCore_Core2 -> OsCore_Core1/XSignalIsr_OsCore_Core1_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore_Core2_Send1 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core2_Send1_XSignalIsr_OsCore_Core1_Recv1_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore_Core2_Send1_XSignalIsr_OsCore_Core1_Recv1_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core2_Send1_XSignalIsr_OsCore_Core1_Recv1_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE2_SEND1_XSIGNALISR_OSCORE_CORE1_RECV1_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore_Core1,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore_Core1_Recv1,
  /* .SendCore    = */ &OsCfg_Core_OsCore_Core2
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core2_Recv0 <- OsCore_Core0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core2_Recv0 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core0_Send1_XSignalIsr_OsCore_Core2_Recv0_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore_Core0_Send1_XSignalIsr_OsCore_Core2_Recv0_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core0_Send1_XSignalIsr_OsCore_Core2_Recv0_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE0_SEND1_XSIGNALISR_OSCORE_CORE2_RECV0_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore_Core0_Send1
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore_Core2_Recv1 <- OsCore_Core1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore_Core2_Recv1 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore_Core1_Send1_XSignalIsr_OsCore_Core2_Recv1_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore_Core1_Send1_XSignalIsr_OsCore_Core2_Recv1_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore_Core1_Send1_XSignalIsr_OsCore_Core2_Recv1_Buffer_Dyn,
    /* .BufferSize = */ OS_CFG_SIZE_OSCORE_CORE1_SEND1_XSIGNALISR_OSCORE_CORE2_RECV1_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore_Core1_Send1
};

/*! X-Signal ISR function table: XSignalIsr_OsCore_Core2 */
CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core2_FuncTable =
{
  /* .FunctionDescription = */
  {
    { Os_XSigRecv_ShutdownAllCores }, /* OSServiceId_ShutdownAllCores */
    { NULL_PTR }
  }
};

/*! X-Signal ISR receive ports reference table: XSignalIsr_OsCore_Core2 */
CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore_Core2_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE_CORE2_PORTS + 1] =
{
  &OsCfg_XSig_XSignalIsr_OsCore_Core2_Recv0,
  &OsCfg_XSig_XSignalIsr_OsCore_Core2_Recv1,
  NULL_PTR
};

/*! X-Signal receiver ISRs reference table: OsCore_Core2 */
OS_LOCAL CONST(Os_XSigIsrConfigRefType, OS_CONST) OsCfg_XSig_OsCore_Core2_IsrRefs[OS_CFG_NUM_XSIG_OSCORE_CORE2_ISRS + 1] =
{
  &OsCfg_Isr_XSignalIsr_OsCore_Core2,
  NULL_PTR
};

/*! X-Signal configuration data: OsCore_Core2 */
CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore_Core2 =
{
  /* .XSigSendPorts    = */ 
  {
    /* [0] = */ &OsCfg_XSig_OsCore_Core2_Send0, /* OsCore_Core0 */
    /* [1] = */ &OsCfg_XSig_OsCore_Core2_Send1, /* OsCore_Core1 */
    /* [2] = */ NULL_PTR /* OsCore_Core2 */
  },
  /* .XSigRecvIsrRefs  = */ OsCfg_XSig_OsCore_Core2_IsrRefs,
  /* .XSigRecvIsrCount = */ OS_CFG_NUM_XSIG_OSCORE_CORE2_ISRS
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
 *  END OF FILE: Os_XSignal_Lcfg.c
 *********************************************************************************************************************/
