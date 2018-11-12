/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Etm.h
 *        \brief  Etm header file
 *
 *      \details  Implementation of the Etm module
 *                (Ethernet Testability Module for TCP/IP for interaction with IxANVL from Ixia)
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Bauer Jens                    visjsb        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *   1.00.00  2014-11-19  visjsb  -             Initial creation
 *   1.01.00  2014-12-12  visjsb  ESCAN00080171 MSN renamed from "Eti"/"EtiTcpIpX" to "EtiTcpIpIx"
 *            2015-02-09  visjsb  ESCAN00081103 Add Basic Features and IxANVL compatibility
 *   1.02.00  2015-03-24  visjsb  ESCAN00081641 Update to R12
 *   1.02.01  2015-09-14  visjsb  ESCAN00082279 Added script integration for IxANVL (partly)
 *   1.03.00  2015-09-14  visjsb  ESCAN00085197 Update to R13
 *   2.00.00  2015-09-24  visjsb  ESCAN00085422 Implement ETM protocol support
 *   2.00.01  2015-09-24  visjsb  ESCAN00085422 Implement ETM protocol support
 *   3.00.00  2015-11-26  visjsb  ESCAN00086773 FEAT-1711: Update to R14
 *   4.00.00  2015-12-21  visjsb  ESCAN00087257 FEAT-1776: Module renaming: TestApp_EtiTcpIp_Ixia --> SysService_AsrEtm
 *   4.00.01  2016-01-15  visjsb  ESCAN00087493 Optimized internal user script interface
 *   4.00.02  2016-02-25  visjsb  ESCAN00088546 Etm call TcpIp_TcpListen() with unchecked parameters who force DETs
 *   4.01.00  2016-04-14  visjsb  ESCAN00089466 Improved UserScript configuration
 *   4.02.00  2016-08-17  visjsb  ESCAN00091507 Extend user dependent configuration
 *   4.02.01  2017-01-13  visjsb  ESCAN00093349 Stackoverflow during TCP handshake
 *            2017-01-13  visjsb  ESCAN00093515 Etm send random data using SendData command
 *            2017-01-13  visjsb  ESCAN00093518 Sending data with 400 bytes in the SendData command are restricted by an OS stackprotaction
 *            2017-01-13  visjsb  ESCAN00093520 ECU does not response to tester after reboot
 *********************************************************************************************************************/

#if !defined (ETM_H)
#define ETM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Etm_Cbk.h"
#include "Etm_Cfg.h"
#include "Etm_Types.h"

#if (ETM_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif /* (ETM_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
#define ETM_VENDOR_ID                       (30U)
#define ETM_MODULE_ID                       (170U)

/* AUTOSAR Software specification version information */
#define ETM_AR_RELEASE_MAJOR_VERSION        (4U)
#define ETM_AR_RELEASE_MINOR_VERSION        (2U)
#define ETM_AR_RELEASE_REVISION_VERSION     (1U)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
#define ETM_SW_MAJOR_VERSION                (4U)
#define ETM_SW_MINOR_VERSION                (2U)
#define ETM_SW_PATCH_VERSION                (1U)

/* ----- DET instance id ----- */
#define ETM_INSTANCE_ID_DET                 (0x05U)

/* ----- ETM Protocol Version (SOME/IP) ----- */
#define ETM_SOMEIP_PROTOCOL_VERSION         (1U)  /* \trace SPEC-2171512, SPEC-2171513 */
#define ETM_SOMEIP_INTERFACE_VERSION        (1U)  /* \trace SPEC-2171512, SPEC-2171513 */

/* ----- API service IDs ----- */
#define ETM_SID_INIT                        0x00U /* Service ID: Etm_Init() */
#define ETM_SID_GET_VERSION_INFO            0x01U /* Service ID: Etm_GetVersionInfo() */
#define ETM_SID_MAIN_FUNCTION               0x02U /* Service ID: Etm_MainFunction() */
#define ETM_SID_RX_INDICATION               0x03U /* Service ID: Etm_RxIndication() */
#define ETM_SID_TX_CONFIRMATION             0x04U /* Service ID: not yet used */
#define ETM_SID_CBK_TCP_ACCEPTED            0x05U /* Service ID: not yet used */
#define ETM_SID_CBK_TCP_CONNECTED           0x06U /* Service ID: not yet used */
#define ETM_SID_CBK_TCPIP_EVENT             0x07U /* Service ID: not yet used */
#define ETM_SID_INTERNAL_FUNCTION           0xFFU /* Service ID: internal functions */

/* ----- Error code IDs ----- */
#define ETM_E_NOT_INITIALIZED               0x01U /*! \brief Error code: API service used without module initialization */
#define ETM_E_ALREADY_INITIALIZED           0x02U /*! \brief Error code: The service Etm_Init() is called while the module is already initialized */
#define ETM_E_INV_CONFIG                    0x03U /*! \brief Error code: API service Etm_Init() called with wrong configuration */
#define ETM_E_NULL_POINTER                  0x04U /*! \brief Error code: API service called with NULL_PTR */
#define ETM_E_INV_POINTER                   0x05U /*! \brief Error code: API service called with invalid pointer */
#define ETM_E_INV_PARAM                     0x06U /*! \brief Error code: API service called with invalid parameter */
#define ETM_E_INV_SOCK_HND                  0x07U /*! \brief Error code: API service called with invalid socket handle */
#define ETM_E_INV_SOCK_ADDR_FAMILY          0x08U /*! \brief Error code: API service called with invalid address family */

/* ----- Mapping of error reporting macro ----- */
#if (ETM_DEV_ERROR_DETECT == STD_ON)
# define Etm_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE)             { if (!(CONDITION)){ (void)Det_ReportError((uint16)ETM_MODULE_ID, (uint8)ETM_INSTANCE_ID_DET, (uint8)(API_ID), (uint8)(ERROR_CODE)); return; } }            /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Etm_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL)   { if (!(CONDITION)){ (void)Det_ReportError((uint16)ETM_MODULE_ID, (uint8)ETM_INSTANCE_ID_DET, (uint8)(API_ID), (uint8)(ERROR_CODE)); return (RET_VAL); } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Etm_ReportDetError(API_ID, ERROR_CODE)                                 {                    (void)Det_ReportError((uint16)ETM_MODULE_ID, (uint8)ETM_INSTANCE_ID_DET, (uint8)(API_ID), (uint8)(ERROR_CODE)); }                      /* PRQA S 3458 */ /* MD_MSR_19.4 */
#else 
# define Etm_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE)
# define Etm_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL)
# define Etm_ReportDetError(API_ID, ERROR_CODE)
#endif

/* ----- ETM Check Conditions ----- */
#define ETM_COND_VALID_PTR(Pointer)              ( NULL_PTR != (Pointer) )                          /* ETM_E_INV_POINTER */ /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define ETM_COND_VALID_DOMAIN(SockAddrPtr)       ( ((SockAddrPtr)->domain == TCPIP_AF_INET) || \
                                                   ((SockAddrPtr)->domain == TCPIP_AF_INET6) )      /* ETM_E_INV_SOCK_ADDR_FAMILY */ /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define ETM_COND_VALID_SOCKET_ID(SocketId)       (ETM_TCPIP_MAX_TCP_SOCKET_ID > (SocketId))         /* ETM_RID_E_ISD */ /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define ETM_COND_VALID_UDP_SOCKET_ID(SocketId)   (ETM_TCPIP_MAX_UDP_SOCKET_ID > (SocketId))         /* ETM_RID_E_ISD */ /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define ETM_COND_VALID_TCP_SOCKET_ID(SocketId)   ( (ETM_TCPIP_MAX_TCP_SOCKET_ID > (SocketId)) && \
                                                   (ETM_TCPIP_MAX_UDP_SOCKET_ID <= (SocketId)) )    /* ETM_RID_E_ISD */ /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define ETM_P2V(ptrtype) P2VAR(ptrtype, AUTOMATIC, ETM_APPL_VAR)    /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define ETM_P2C(ptrtype) P2CONST(ptrtype, AUTOMATIC, ETM_APPL_CONST) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define ETM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  Etm_InitMemory()
 **********************************************************************************************************************/
/*! \brief        Function for *_INIT_*-variable initialization
 *  \details      Service to initialize module global variables at power up. This function initializes the
 *                variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \param        void none
 *  \return       none
 *  \pre          Module is uninitialized.
 *  \context      TASK
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_InitMemory(void);

/***********************************************************************************************************************
 *  Etm_Init()
 **********************************************************************************************************************/
/*! \brief        Initialization function
 *  \details      This function initializes the module Etm. It initializes all variables and sets the module state to
 *                initialized.
 *  \param[in]    ConfigPtr Configuration structure for initializing the module.
 *  \return       none
 *  \pre          Interrupts are disabled.
 *  \pre          Module is uninitialized.
 *  \pre          Etm_InitMemory has been called unless Etm_ModuleInitialized is initialized by start-up code.
 *  \context      TASK
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 *  \note         Specification of module initialization
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_Init(ETM_P2C(Etm_ConfigType) ConfigPtr);

#if (ETM_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  Etm_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief        Returns the version information
 *  \details      Etm_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]   VersionInfoPtr Pointer to where to store the version information. Parameter must not be NULL.
 *  \return       none
 *  \pre          none
 *  \context      TASK
 *  \reentrant    Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_GetVersionInfo(ETM_P2V(Std_VersionInfoType) VersionInfoPtr);
#endif /* (ETM_VERSION_INFO_API == STD_ON) */

/***********************************************************************************************************************
 *  Etm_MainFunction()
 **********************************************************************************************************************/
/*! \brief        Schedules the Etm module. (Entry point for scheduling) 
 *  \param        void none
 *  \return       none
 *  \pre          Module is uninitialized.
 *  \context      TASK
 *  \reentrant    Non Reentrant.
 *  \synchronous  Synchronous.
 **********************************************************************************************************************/
FUNC(void, ETM_CODE) Etm_MainFunction(void);

#define ETM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* ETM_H */

/**********************************************************************************************************************
 *  END OF FILE: Etm.h
 *********************************************************************************************************************/
