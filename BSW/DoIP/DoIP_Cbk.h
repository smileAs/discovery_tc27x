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
 *         File:  DoIP_Cbk.h
 *      Project:  TcpIp-Stack
 *       Module:  Diagnostic over Internet Protocol
 *    Generator:  -
 *
 *  Description:  Callback header Diagnostic over IP
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/


#if !defined(DOIP_CBK_H)
#define DOIP_CBK_H


/**********************************************************************************************************************
* Include files
 *********************************************************************************************************************/
#include "SoAd_Types.h"
#include "DoIP_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  DoIP_SoAdIfRxIndication
 *********************************************************************************************************************/
/*! \brief      Receive indication callback for IF
 *  \param[in]  RxPduId        RX indication PDU ID
 *  \param[in]  PduInfoPtr     Pointer to received data and length
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdIfRxIndication(PduIdType RxPduId, \
                        P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr);

/**********************************************************************************************************************
 *  DoIP_SoAdTpStartOfReception
 *********************************************************************************************************************/
/*! \brief      Receive indication callback for TP
 *  \param[in]  RxPduId           Rx PDU ID 
 *  \param[in]  info              Pointer to data to support first or single frames (not used by SoAd)
 *  \param[in]  TpSduLength       Total length of the received PDU
 *  \param[out] bufferSizePtr     Available receive buffer
 *  \return     BUFREQ_OK         Connection has been accepted
 *  \return     BUFREQ_E_NOT_OK   Connection has not been accepted
 *  \return     BUFREQ_E_OVFL     No buffer of the required length can be provided
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpStartOfReception(PduIdType RxPduId, 
                        P2VAR(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) info,
                        PduLengthType TpSduLength, 
                        P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) bufferSizePtr);

/**********************************************************************************************************************
 *  DoIP_SoAdTpCopyRxData
 *********************************************************************************************************************/
/*! \brief      Called when SoAd has data to copy
 *  \param[in]  RxPduId           Rx PDU ID
 *  \param[in]  PduInfoPtr        Pointer to received data and length
 *  \param[out] bufferSizePtr     Available buffer after data has been copy
 *  \return     BUFREQ_OK         Buffer request successful
 *  \return     BUFREQ_E_NOT_OK   Buffer request not successful
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyRxData(PduIdType RxPduId, \
                        P2VAR(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr, \
                        P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) bufferSizePtr);

/**********************************************************************************************************************
 *  DoIP_SoAdTpRxIndication
 *********************************************************************************************************************/
/*! \brief      Receive indication callback for TP
 *  \param[in]  RxPduId        RX indication PDU ID
 *  \param[in]  result         Result of reception
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdTpRxIndication(PduIdType RxPduId, Std_ReturnType result);

/**********************************************************************************************************************
 *  DoIP_SoAdIfTxConfirmation
 *********************************************************************************************************************/
/*! \brief      Transmission confirmation callback for IF
 *  \param[in]  TxPduId        TX confirmation PDU ID
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdIfTxConfirmation(PduIdType TxPduId);

/**********************************************************************************************************************
 *  DoIP_SoAdTpCopyTxData
 *********************************************************************************************************************/
/*! \brief      Queries transmit data of a PDU
 *  \param[in]  TxPduId             TX confirmation PDU ID
 *  \param[in]  PduInfoPtr          Pointer to destination buffer and length
 *  \param[in]  retry               Retry is not by SoAd supported ( NULL_PTR )
 *  \param[out] availableDataPtr    Remaining buffer length in DoIP Tx Buffer
 *  \return     BUFREQ_OK           Data has been copied successful
 *  \return     BUFREQ_E_BUSY       Data could temporarily not be copied
 *  \return     BUFREQ_E_NOT_OK     Data has not been copied
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyTxData(PduIdType TxPduId, \
                        P2VAR(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr, \
                        P2VAR(RetryInfoType, AUTOMATIC, DOIP_APPL_VAR) retry, \
                        P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) availableDataPtr);

/**********************************************************************************************************************
 *  DoIP_SoAdTpTxConfirmation
 *********************************************************************************************************************/
/*! \brief      Transmission confirmation callback for TP
 *  \param[in]  TxPduId        TX confirmation PDU ID
 *  \param[in]  result         Result of TP session
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdTpTxConfirmation(PduIdType TxPduId, Std_ReturnType result);

/**********************************************************************************************************************
 *  DoIP_SoConModeChg
 *********************************************************************************************************************/
/*! \brief      Socket state change callback
 *  \param[in]  SoConId            Socket connection identifier
 *  \param[in]  Mode               New mode
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoConModeChg(SoAd_SoConIdType SoConId, SoAd_SoConModeType Mode);

/**********************************************************************************************************************
 *  DoIP_LocalIpAddrAssignmentChg
 *********************************************************************************************************************/
/*! \brief      IP address assignment change callback
 *  \param[in]  SoConId            Socket connection identifier
 *  \param[in]  State              State
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_LocalIpAddrAssignmentChg(SoAd_SoConIdType SoConId, \
                        SoAd_IpAddrStateType State);

/**********************************************************************************************************************
 *  DoIP_ActivationLineSwitch
 *********************************************************************************************************************/
/*! \brief      Notifies DoIP on a switch of the DoIPActivationLine
 *  \param[in]  void none
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_ActivationLineSwitch(void);

#if ( defined(DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) )
/**********************************************************************************************************************
 *  DoIP_ShutdownFinished
 *********************************************************************************************************************/
/*! \brief      Indicates shutdown of SoAd
 *  \param[in]  void none
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *  \note       Vector specific callback
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_ShutdownFinished(void);
#endif /* defined(DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) */

#define DOIP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* !defined(DOIP_CBK_H) */

/**********************************************************************************************************************
 *  END OF FILE: DoIP_Cbk.h
 *********************************************************************************************************************/
