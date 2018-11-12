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
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DoIP.h
 *      Project:  TcpIp-Stack
 *       Module:  Diagnostic over Internet Protocol
 *    Generator:  -
 *
 *  Description:  Header file of Diagnostic over IP
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Michael Dangelmaier           vismda        Vector Informatik GmbH
 *  Alex Lunkenheimer             visalr        Vector Informatik GmbH
 *  Philipp Christmann            vispcn        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *   1.00.00  2013-10-18  vismda  -             Moved from SoAd
 *   1.00.01  2013-11-07  vismda  -             Issues in PduR_DoIP
 *            2013-11-18  vismda  ESCAN00071981 Diagnostic Message Ack/Nack with invalid length
 *            2013-11-18  vismda  ESCAN00071841 Issue: DoIP PduR Api and If
 *   1.01.00  2014-02-07  vismda  ESCAN00072620 DoIP module shall perform version check against DoIP version
 *            2014-02-07  vismda  ESCAN00072387 Compiler warning: inconsistent storage class specification for 
 *                                              DoIP_VReSetVehicleAnnounce
 *            2014-02-07  vismda  ESCAN00072329 Issue when sending generic header nack and alive check request
 *            2014-02-07  vismda  ESCAN00072323 DET in DoIP_SoAdTpCopyRxData
 *   1.01.01  2014-04-30  vismda  ESCAN00075331 Endless loop at TcpIp buffer wrap around
 *   1.02.00  2014-05-08  vismda  ESCAN00074362 DoIP does not send expected Generic Header Negative Acknowledge
 *            2014-05-09  vismda  ESCAN00074459 AR4-650: Support ChangeParameter without Confirmation
 *            2014-05-09  vismda  ESCAN00071915 AR4-619: Support the StartOfReception API (with the PduInfoType), 
 *                                              TxConfirmation and RxIndication according ASR4.1.2
 *            2014-05-14  vismda  ESCAN00074082 AR4-582: DoIP functionality to mirror request data in response data
 *            2014-06-13  vismda  ESCAN00076206 Local define for STATIC
 *   1.02.01  2014-06-20  visalr  ESCAN00076350 DoIP_Init: Signatures inconsistent in DoIP.c and DoIP.h
 *   1.02.02  2014-07-02  vismda  ESCAN00076643 No generic header negative acknowledge with error code 0x02
 *            2014-07-02  vismda  ESCAN00076645 Default Protocol Version 0xFF is not accepted
 *            2014-07-03  vismda  ESCAN00076712 No response to segmented TCP message
 *   1.03.00  2014-08-21  vismda  ESCAN00077970 Add DoIPGw support
 *   1.04.00  2014-07-22  vismda  ESCAN00071768 The EID in Vehicle Announcement messages has the invalid value
 *            2014-07-22  vismda  ESCAN00073293 Feature: Implement UDP zero copy for transmission
 *            2014-07-22  vismda  ESCAN00076651 Vehicle Identification Response sent before A_DoIP_Announce_Wait
 *            2014-09-18  vismda  ESCAN00078453 Wrong routing activation response SA when all sockets are registered 
 *                                              and active
 *            2014-09-19  vismda  ESCAN00078472 Same diagnostic message negative acknowledgement is sent
 *            2014-09-25  vismda  ESCAN00077694 Compiler warning: Several warnings when the component is compiled with 
 *                                              Visual Studio
 *            2014-09-25  vismda  ESCAN00073340 Extract DoIP from SoAd
 *            2014-09-25  vismda  ESCAN00078431 No alive check requests are sent
 *            2014-09-25  vismda  ESCAN00078446 No routing activation response code 0x03 is sent
 *            2014-09-26  vismda  ESCAN00078601 T_TCP_General_Inactivity timeout is not reset when ECU sends messages
 *            2014-09-30  vismda  ESCAN00078645 Wrong DET check in DoIP_SoAdTpCopyTxData
 *            2014-10-06  vismda  ESCAN00078770 Unexpected behavior if PduR_DoIPCopyRxData() returns BUFREQ_E_NOT_OK
 *            2014-10-06  vismda  ESCAN00078777 DoIP_CancelReceive() does not DET-check DoIPPduRRxId properly
 *            2014-10-16  vismda  ESCAN00078921 No routing activation response code 0x02
 *            2014-10-16  vismda  ESCAN00078975 EnableTxBeforeRx and Shutdown issues
 *            2014-10-16  vismda  ESCAN00078974 ECU shall discard DoIP payload types on wrong transport layer
 *            2014-10-24  vismda  ESCAN00078217 DoIP causes alignment exception on sending Vehicle Announcement
 *   1.05.00  2015-03-12  vismda  ESCAN00081759 Adjustments to support ASR 4.2.1 SoAd
 *   1.05.01  2015-04-28  vismda  ESCAN00082732 Parameter bufferSizePtr in PduR_SoAdTpCopyRxData not checked
 *   1.06.00  2015-07-10  vismda  ESCAN00079233 Incorrect behavior when ECU receives an empty diagnostic message
 *            2015-07-15  vismda  ESCAN00079880 Compiler error: DoIP_VCfgEId is undefined
 *            2015-07-15  vismda  ESCAN00079168 Call DoIP_SoAdTpCopyRxData() with invalid SduLength
 *            2015-07-16  vismda  ESCAN00079049 No communication after transmission cancellation
 *            2015-07-16  vismda  ESCAN00084033 Alignment exception on sending initial Vehicle Announcements
 *   1.06.01  2015-08-17  vismda  ESCAN00084562 MISRA/PClint warnings
 *   1.06.02  2015-11-05  vismda  ESCAN00086288 CoreException "misaligned access exception (MAE)" occurs
 *   2.00.00  2015-11-05  vismda  ESCAN00084454 Socket not closed after reception of Alive Check Response with invalid
 *                                              logical address
 *            2015-11-20  vismda  ESCAN00085184 FEAT-10: Implementation of DoIP according to AR 4.2.1 [AR4-507]
 *   2.00.01  2016-02-04  vismda  ESCAN00088064 No Activation Line switch to active in case DHCP address only
 *   2.01.00  2016-02-16  vismda  ESCAN00088317 Vehicle Identification returned unexpected Further Action value
 *            2016-02-17  vismda  ESCAN00088344 Unexpected power mode if <User>_DoIPGetPowerModeStatus fails
 *            2016-02-17  vismda  ESCAN00088351 TCP socket closed on routing activation authentication callback return
 *                                              value switch from DOIP_E_PENDING to E_OK
 *            2016-02-18  vismda  ESCAN00088393 Implement inactivity timer as specified in AUTOSAR
 *            2016-02-18  vismda  ESCAN00088393 No response to Routing Activation Request if confirmation is used
 *            2016-02-24  vismda  ESCAN00087700 FEAT-1698: Support UUDT on DoIP according to AR 4.2.2
 *            2016-02-25  vismda  ESCAN00087683 FEAT-1449: Release of FEAT-1253 (ETH Stack)
 *            2016-03-21  vismda  ESCAN00089003 Out-of-bounds access around DoIP_VSoAdRxPduId2SoConClosing[]
 *            2016-03-22  vismda  ESCAN00087995 Activation Line cannot be set to inactive
 *   2.01.01  2016-04-12  vismda  ESCAN00089407 Unexpected DET in DoIP_SoAdTpCopyTxData()
 *   2.02.00  2016-05-19  vismda  ESCAN00089429 Compiler warning: 'DoIP_VHandleGidSync' declared 'static' but never
 *                                              defined
 *            2016-05-19  vismda  ESCAN00089348 FEAT-1820: DoIP: Improved Vehicle Announcement Handling
 *            2016-06-16  vismda  ESCAN00090504 Vehicle Announcement with unexpected GID caused by misinterpretation of
 *                                              <User>_DoIPGetGidCallback return value
 *   3.00.00  2016-08-25  vismda  ESCAN00091628 DoIP discards first TCP DoIP message
 *            2016-09-05  vismda  FEATC-259     FEAT-1706: DoIP: Support call-outs for OEM-specific DoIP payload types
 *            2016-09-12  vismda  ESCAN00091842 No response to Routing Activation Request
 *            2016-10-14  vismda  ESCAN00092319 Missing support of required IP address assignment methods
 *            2016-10-20  vismda  FEATC-261     FEAT-1666: Adapted DoIP channel selection (DoIP address masking)
 *            2016-10-25  vismda  FEATC-256     FEAT-1816: Split MainFunctions to optimize gateway use-case
 *   3.00.01  2016-12-02  vismda  ESCAN00093151 Vehicle Identification Request with EID and invalid length is responded
 *                                              with unexpected error code
 *   3.01.00  2017-01-09  vispcn  FEATC-940     FEAT-1824: Support a component-specific SafeBSW configuration switch
 *            2017-01-25  vismda  ESCAN00093714 Compiler error around DoIP_VRequestIpAddrAssignment()
 *            2017-01-29  vismda  ESCAN00093879 FEAT-2750: Support multiple testers on different VLANs
 *            2017-02-08  vismda  FEATC-1143    FEAT-2778: Support Buffer Size up to 128kB for FBL use case
 *********************************************************************************************************************/


#if !defined(DOIP_H)
#define DOIP_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SoAd.h"
#include "ComStack_Types.h"
#include "DoIP_Lcfg.h"

#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
#include "DoIPGw_Cbk.h"
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* DoIP ModuleId */
#define DOIP_VENDOR_ID                            30u  /* Vector ID */
#define DOIP_MODULE_ID                            173u /* DoIP ID */

/* DoIP supported Autosar version */
#define DOIP_AR_RELEASE_MAJOR_VERSION             4u
#define DOIP_AR_RELEASE_MINOR_VERSION             2u
#define DOIP_AR_RELEASE_PATCH_VERSION             2u

/* DoIP software version */
#define DOIP_SW_MAJOR_VERSION                     3u
#define DOIP_SW_MINOR_VERSION                     1u
#define DOIP_SW_PATCH_VERSION                     0u

/* ##V_CFG_MANAGEMENT ##CQProject :   Tp_AsrTpDoIP CQComponent : Implementation */
#define TP_ASRTPDOIP_VERSION                      (0x0301u) /* BCD coded version number */
#define TP_ASRTPDOIP_RELEASE_VERSION              (0x00u)   /* BCD coded release version number */

/* DoIP AUTOSAR ApiIds */
#define DOIP_API_ID_GET_VERSION_INFO              0x00u
#define DOIP_API_ID_INIT                          0x01u
#define DOIP_API_ID_MAIN_FUNCTION                 0x02u
#define DOIP_API_ID_TP_TRANSMIT                   0x03u
#define DOIP_API_ID_TP_CANCEL_TRANSMIT            0x04u
#define DOIP_API_ID_TP_CANCEL_RECEIVE             0x05u
#define DOIP_API_ID_SO_CON_MODE_CHG               0x0Bu
#define DOIP_API_ID_LOC_IP_ADDR_ASSIGN_CHG        0x0Cu
#define DOIP_API_ID_ACTIVATION_LINE_SWITCH        0x0Fu
#define DOIP_API_ID_IF_TX_CONFIRMATION            0x40u
#define DOIP_API_ID_IF_RX_INDICATION              0x42u
#define DOIP_API_ID_TP_COPY_TX_DATA               0x43u
#define DOIP_API_ID_TP_COPY_RX_DATA               0x44u
#define DOIP_API_ID_TP_RX_INDICATION              0x45u
#define DOIP_API_ID_TP_START_OF_RECEPTION         0x46u
#define DOIP_API_ID_TP_TX_CONFIRMATION            0x48u
#define DOIP_API_ID_IF_TRANSMIT                   0x49u
#define DOIP_API_ID_IF_CANCEL_TRANSMIT            0x4Au

/* DoIP Vector ApiIds */
#define DOIP_API_ID_VACT_LINE_STATE_TRANS_TO_ACT  0xEBu
#define DOIP_API_ID_ENABLE_PDU_SIZE_ROUTING       0xECu
#define DOIP_API_ID_DISABLE_PDU_SIZE_ROUTING      0xEDu
#define DOIP_API_ID_VUDP_SINGLE_TRANSMIT          0xEEu
#define DOIP_API_ID_VTCP_TRANSMIT                 0xEFu

/* DoIP AUTOSAR DET errors */
#define DOIP_E_UNINIT                             0x01u
#define DOIP_E_PARAM_POINTER                      0x02u
#define DOIP_E_INVALID_PDU_SDU_ID                 0x03u
#define DOIP_E_INVALID_PARAMETER                  0x04u
#define DOIP_E_INIT_FAILED                        0x05u

/* DoIP Vector DET errors */
#define DOIP_E_ACTIVATION_LINE                    0xECu
#define DOIP_E_SOAD_CALL_FAILED                   0xEDu
#define DOIP_E_UNEXPECTED_ASSIGNMENT              0xEEu
#define DOIP_E_NOBUFS                             0xEFu

/* DoIP state */
#define DOIP_STATE_UNINIT                         0x00u
#define DOIP_STATE_INIT                           0x01u
#define DOIP_STATE_SHUTDOWN                       0x02u

/* DoIP header types */
#define DOIP_HDR_TYPE_GEN_NACK                      (uint16)0x0000u
#define DOIP_HDR_TYPE_VEHICLE_IDENT_REQ             (uint16)0x0001u
#define DOIP_HDR_TYPE_VEHICLE_IDENT_REQ_EID         (uint16)0x0002u
#define DOIP_HDR_TYPE_VEHICLE_IDENT_REQ_VIN         (uint16)0x0003u
#define DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT          (uint16)0x0004u
#define DOIP_HDR_TYPE_ROUT_ACTIV_REQ                (uint16)0x0005u
#define DOIP_HDR_TYPE_ROUT_ACTIV_ACK                (uint16)0x0006u
#define DOIP_HDR_TYPE_ALIVE_CHECK_REQ               (uint16)0x0007u
#define DOIP_HDR_TYPE_ALIVE_CHECK_ACK               (uint16)0x0008u
#define DOIP_HDR_TYPE_ENTITY_STATE_REQ              (uint16)0x4001u
#define DOIP_HDR_TYPE_ENTITY_STATE_ACK              (uint16)0x4002u
#define DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_REQ      (uint16)0x4003u
#define DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_ACK      (uint16)0x4004u
#define DOIP_HDR_TYPE_DIAG_REQ                      (uint16)0x8001u
#define DOIP_HDR_TYPE_DIAG_ACK                      (uint16)0x8002u
#define DOIP_HDR_TYPE_DIAG_NACK                     (uint16)0x8003u
#define DOIP_HDR_TYPE_OEM_SPECIFIC                  (uint16)0xEEEEu
#define DOIP_HDR_TYPE_INVALID                       (uint16)0xEFFFu

/* DoIP protocol versions */
#define DOIP_PROTOCOL_VERSION_2010                     (uint8)0x01u
#define DOIP_PROTOCOL_VERSION_2011                     (uint8)0x01u
#define DOIP_PROTOCOL_VERSION_2012                     (uint8)0x02u
#define DOIP_PROTOCOL_VERSION_DEFAULT                  (uint8)0xFFu

/* DoIP generic nack codes */
#define DOIP_GEN_NACK_FORMAT                           (uint8)0x00u
#define DOIP_GEN_NACK_TYPE                             (uint8)0x01u
#define DOIP_GEN_NACK_MAX_LEN                          (uint8)0x02u
#define DOIP_GEN_NACK_OUT_OF_MEM                       (uint8)0x03u
#define DOIP_GEN_NACK_INV_LEN                          (uint8)0x04u
#define DOIP_GEN_NACK_OK                               (uint8)0xFFu
#define DOIP_GEN_NACK_LEN_BYTE                         (uint8)0x01u

/* DoIP routing activation nack codes */
#define DOIP_ROUT_ACTIV_RES_CODE_UNKNOWN_TESTER        (uint8)0x00u
#define DOIP_ROUT_ACTIV_RES_CODE_SOCKETS_IN_USE        (uint8)0x01u
#define DOIP_ROUT_ACTIV_RES_CODE_DIFFERENT_TESTER      (uint8)0x02u
#define DOIP_ROUT_ACTIV_RES_CODE_ALREADY_ACTIV         (uint8)0x03u
#define DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT       (uint8)0x04u
#define DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REJECTED      (uint8)0x05u
#define DOIP_ROUT_ACTIV_RES_CODE_INV_ACTIV_TYPE        (uint8)0x06u
#define DOIP_ROUT_ACTIV_RES_CODE_SUCCESS               (uint8)0x10u
#define DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REQUIRED      (uint8)0x11u

/* DoIP diagnostic request nack codes */
#define DOIP_DIAG_MSG_RES_CODE_ACK                     (uint8)0x00u
#define DOIP_DIAG_MSG_RES_CODE_UNKNOWN_SRC_ADDR        (uint8)0x01u /* described in ISO/CD 13400 - not used */
#define DOIP_DIAG_MSG_RES_CODE_INVALID_SRC_ADDR        (uint8)0x02u
#define DOIP_DIAG_MSG_RES_CODE_UNKNOWN_TGT_ADDR        (uint8)0x03u
#define DOIP_DIAG_MSG_RES_CODE_MSG_TOO_LARGE           (uint8)0x04u
#define DOIP_DIAG_MSG_RES_CODE_OUT_OF_MEMORY           (uint8)0x05u
#define DOIP_DIAG_MSG_RES_CODE_TGT_UNREACHABLE         (uint8)0x06u
#define DOIP_DIAG_MSG_RES_CODE_UNKNOWN_NETWORK         (uint8)0x07u
#define DOIP_DIAG_MSG_RES_CODE_NETWORK_TRANSPROT       (uint8)0x08u

/* DoIP diagnostic power mode ack codes */
#define DOIP_DIAG_POWER_MODE_RES_CODE_NOT_READY        (uint8)0x00u
#define DOIP_DIAG_POWER_MODE_RES_CODE_READY            (uint8)0x01u

/* DHCP-Option DoIP-Tester */
#define DOIP_DHCP_OPT_TABLE_SIZE                       (uint8)0x04u
#define DOIP_DHCP_OPT_SUB_LEN                          (uint8)0x05u /* enterNum + subOptionLen */
#define DOIP_DHCP_OPT_CODE                             (uint8)0x01u
#define DOIP_DHCP_OPT_LEN                              (uint8)0x05u
#define DOIP_DHCP_OPT_IPV4_ADDR_SIZE                   (uint8)0x04u
#define DOIP_DHCP_OPT_IPV6_ADDR_SIZE                   (uint8)0x10u 
#define DOIP_DHCP_OPT_125_MIN_LEN                      (uint8)0x0Bu /* enterNum + subOptionLen + hdr + addrSize */
#define DOIP_DHCP_OPT_17_MIN_LEN                       (uint8)0x17u /* enterNum + subOptionLen + hdr + addrSize */
#define DOIP_DHCP_OPT_ENTERPRISE_NUM                   (uint32)0x00000C7Bu

/* Announcement reset types */
#define DOIP_ANNOUNCE_SET                              (uint8)0x00u
#define DOIP_ANNOUNCE_RESET                            (uint8)0x01u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  DoIP_InitMemory
 *********************************************************************************************************************/
/*! \brief      Initializes global variables
 *  \param[in]  void none
 *  \return     none
 *  \pre        Has to be called before any other calls to the module
 *  \context    Task level
 *  \context    Initialization
 *  \note       AUTOSAR extension
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_InitMemory(void);

/**********************************************************************************************************************
 *  DoIP_Init
 *********************************************************************************************************************/
/*! \brief      Initialize the data structures
 *  \param[in]  DoIPConfigPtr      Pointer to module configuration
 *  \return     none
 *  \pre        Has to be called before usage of the module
 *  \context    Task level
 *  \context    Initialization
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_Init(P2CONST(DoIP_ConfigType, AUTOMATIC, DOIP_CONST) DoIPConfigPtr);

#if ( defined(DOIP_VERSION_INFO_API) && (STD_ON == DOIP_VERSION_INFO_API) )
/**********************************************************************************************************************
 *  DoIP_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief      Get version information
 *  \param[out] versionInfo        Pointer for version information
 *  \return     none
 *  \context    Task level
 *  \context    Initialization
 *  \note       none
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, DOIP_APPL_VAR) versionInfo);
#endif /* defined(DOIP_VERSION_INFO_API) && (STD_ON == DOIP_VERSION_INFO_API) */

/**********************************************************************************************************************
 *  DoIP_TpTransmit
 *********************************************************************************************************************/
/*! \brief      Transmission request
 *  \param[in]  DoIPPduRTxId       PDU identifier
 *  \param[in]  DoIPPduRTxInfoPtr  Pointer to message structure
 *  \return     E_OK               Transmission requested
 *  \return     E_NOT_OK           Transmission request failed
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpTransmit(PduIdType DoIPPduRTxId,
                                  P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) DoIPPduRTxInfoPtr);

/**********************************************************************************************************************
 *  DoIP_TpCancelTransmit
 *********************************************************************************************************************/
/*! \brief      Requests transmission cancellation of a specific TP PDU
 *  \param[in]  DoIPPduRTxId          PDU identifier
 *  \return     E_OK                  Cancellation request is accepted 
 *  \return     E_NOT_OK              Cancellation not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpCancelTransmit(PduIdType DoIPPduRTxId);

/**********************************************************************************************************************
 *  DoIP_TpCancelReceive
 *********************************************************************************************************************/
/*! \brief      Requests reception cancellation of a specific TP PDU
 *  \param[in]  DoIPPduRRxId          PDU identifier
 *  \return     E_OK                  Cancellation request is accepted 
 *  \return     E_NOT_OK              Cancellation not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpCancelReceive(PduIdType DoIPPduRRxId);

/**********************************************************************************************************************
 *  DoIP_IfTransmit
 *********************************************************************************************************************/
/*! \brief      Transmission request
 *  \param[in]  id          PDU identifier
 *  \param[in]  info        Pointer to message structure
 *  \return     E_OK        Transmission requested
 *  \return     E_NOT_OK    Transmission request failed
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_IfTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) info);

/**********************************************************************************************************************
 *  DoIP_IfCancelTransmit
 *********************************************************************************************************************/
/*! \brief      Transmission cancellation of a specific IF PDU
 *  \param[in]  id          PDU identifier
 *  \return     E_OK        Cancellation was executed successfully
 *  \return     E_NOT_OK    Cancellation was rejected
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_IfCancelTransmit(PduIdType id);

/**********************************************************************************************************************
 *  DoIP_TpChangeParameter
 *********************************************************************************************************************/
/*! \brief      Implemented to support generic PduR modules - no functionality
 *  \param[in]  id              PDU identifier
 *  \param[in]  parameter       Parameter identifier
 *  \param[in]  value           New parameter value
 *  \return     E_OK            Request is accepted
 *  \return     E_NOT_OK        Request is not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *  \note       No functionality - always returns E_NOT_OK
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);

#if ( defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) )
/**********************************************************************************************************************
 *  DoIP_EnablePduSizeRouting
 *********************************************************************************************************************/
/*! \brief      Activates the DoIP packet size dependent routing
 *  \param[in]  void none
 *  \return     none
 *  \pre        Module initialized and DoIP PduSizeRouting must be enabled
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_EnablePduSizeRouting(void);

/**********************************************************************************************************************
 *  DoIP_DisablePduSizeRouting
 *********************************************************************************************************************/
/*! \brief      Deactivates the DoIP packet size dependent routing
 *  \param[in]  void none
 *  \return     none
 *  \pre        Module initialized and DoIP PduSizeRouting must be enabled
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_DisablePduSizeRouting(void);
#endif /* defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) */

#if ( defined(DOIP_VSUPPORT_SHUTDOWN) && (STD_ON == DOIP_VSUPPORT_SHUTDOWN) )
/**********************************************************************************************************************
 *  DoIP_Shutdown
 *********************************************************************************************************************/
/*! \brief      Shutdown TcpIp stack (i.e. all sockets will be closed and modules change to special shutdown state)
 *  \param[in]  void none
 *  \return     E_OK                Successful
 *  \return     E_NOT_OK            Not successful
 *  \return     SOAD_E_INPROGRESS   Shutdown in progress
 *  \pre        Module initialized and DoIP Shutdown must be enabled
 *  \context    Task level
 *  \note       Vector specific API
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_Shutdown(void);
#endif /* defined(DOIP_VSUPPORT_SHUTDOWN) && (STD_ON == DOIP_VSUPPORT_SHUTDOWN) */

#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
/**********************************************************************************************************************
 *  DoIP_DoIPGwReceived
 *********************************************************************************************************************/
/*! \brief      Informs DoIP about a processed diagnostic message within DoIPGw module
 *  \param[in]  EntityAddr    DoIP entity address (target address in diagnostic message sent by tester)
 *  \return     none
 *  \pre        Module initialized and DoIP Gateway must be enabled
 *  \context    Task level
 *  \note       Vector specific API
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_DoIPGwReceived(uint16 EntityAddr);
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */

#define DOIP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* !defined(DOIP_H) */

/**********************************************************************************************************************
 *  END OF FILE: DoIP.h
 *********************************************************************************************************************/
