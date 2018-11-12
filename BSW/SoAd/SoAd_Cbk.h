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
 *         File:  SoAd_Cbk.h
 *      Project:  TcpIp-Stack
 *       Module:  Socket Adapter
 *    Generator:  If_AsrIfSoAd.dll
 *
 *  Description:  callback header
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/


#if !defined(SOAD_CBK_H)
#define SOAD_CBK_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SoAd_Types.h"

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  SoAd_RxIndication
 *********************************************************************************************************************/
/*! \brief      receive indication
 *  \param[in]  SocketId        socket identifier
 *  \param[in]  RemoteAddrPtr   address the message is received from
 *  \param[in]  BufPtr          pointer to received data
 *  \param[in]  Length          length of received data
 *  \context    task level
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RxIndication(SoAd_SocketIdType SocketId, SoAd_SockAddrType* RemoteAddrPtr, uint8* BufPtr,
                                        uint16 Length);

/**********************************************************************************************************************
 *  SoAd_CopyTxData
 *********************************************************************************************************************/
/*! \brief          service request to copy data for transmission to the buffer provided by TcpIp
 *  \param[in]      SocketId                socket identifier of the related local socket
 *  \param[in]      BufPtr                  pointer to provided transmission buffer
 *  \param[in/out]  BufLength|BufLengthPtr  length of provided transmission buffer
 *  \context        interrupt or task level
 *  \note           with SoAdTxDynamicLengthEnabled last parameter is used as in/out parameter to return length of
 *                  copied data
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_CopyTxData(SoAd_SocketIdType SocketId,
                                                   uint8* BufPtr,
#if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
                                                   uint16* BufLengthPtr
#else
                                                   uint16 BufLength
#endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
                                                   );

/**********************************************************************************************************************
 *  SoAd_TxConfirmation
 *********************************************************************************************************************/
/*! \brief      transmission confirmation callback
 *  \param[in]  SocketId              TcpIp local socket identifier
 *  \param[in]  Length                length of confirmed data
 *  \context    interrupt or task level
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxConfirmation(SoAd_SocketIdType SocketId, uint16 Length);

/**********************************************************************************************************************
 *  SoAd_LocalIpAddrAssignmentChg
 *********************************************************************************************************************/
/*! \brief      IP address assignment change callback
 *  \param[in]  IpAddrId           IP address identifier
 *  \param[in]  State              state of IP address assignment
 *  \context    task level
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_LocalIpAddrAssignmentChg(SoAd_LocalAddrIdType IpAddrId, SoAd_IpAddrStateType State);

/**********************************************************************************************************************
 *  SoAd_TcpAccepted
 *********************************************************************************************************************/
/*! \brief      TCP connection accepted callback on listen socket
 *  \param[in]  SocketId            socket identifier used at bind (listen socket)
 *  \param[in]  SocketIdConnected   socket identifier of connected remote peer (data socket)
 *  \param[in]  RemoteAddrPtr       remote address of connected remote peer
 *  \return     E_OK                established connection accepted
 *  \return     E_NOT_OK            established connection rejected
 *  \context    task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpAccepted(SoAd_SocketIdType SocketId,
                                        SoAd_SocketIdType SocketIdConnected,
                                        SoAd_SockAddrType* RemoteAddrPtr);

/**********************************************************************************************************************
 *  SoAdTp_TcpConnected
 *********************************************************************************************************************/
/*! \brief      TCP connection connected
 *  \param[in]  SockHnd               socket handle
 *  \context    task level
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpConnected(SoAd_SocketIdType SocketId);

/**********************************************************************************************************************
 *  SoAd_TcpIpEvent
 *********************************************************************************************************************/
/*! \brief      TCP event handler (state change)
 *  \param[in]  SocketId       socket identifier of TcpIp socket
 *  \param[in]  Event          event type
 *  \context    task level
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpEvent(SoAd_SocketIdType SocketId, SoAd_EventType Event);

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* !defined(SOAD_CBK_H) */

/**********************************************************************************************************************
 *  END OF FILE: SoAd_Cbk.h
 *********************************************************************************************************************/
