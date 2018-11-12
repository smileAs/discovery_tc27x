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
 *         \file  TcpIp_Cbk.h
 *        \brief  Implementation of TcpIp Module - Callback Header
 *
 *      \details  This file is part of the TcpIp module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

#if !defined (TCPIP_CBK_H)
# define TCPIP_CBK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "TcpIp_Cfg.h"
#include "TcpIp_Priv_Types.h"
#include "Eth_GeneralTypes.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  TcpIp_RxIndication
 **********************************************************************************************************************/
/*! \brief      RxIndication from the EthIf.
 *  \description   By this API service the TCP/IP stack gets an indication and the data of a received frame.
 *  \param[in]  CtrlIdx       Index of the EthIf controller.
 *  \param[in]  FrameType     frame type of received Ethernet frame
 *  \param[in]  IsBroadcast   parameter to indicate a broadcast frame
 *  \param[in]  PhysAddrPtr   pointer to Physical source address (MAC address in network byte order) of received Ethernet frame
 *  \param[in]  DataPtr       Pointer to payload of the received Ethernet frame (i.e. Ethernet header is not provided).
 *  \param[in]  LenByte       Length of received data.
 *  \return     void
 *  \note       This function will simply forward the incoming RxIndication to the corresponding RxIndications in the
 *              modules IpV4 and IpV6.
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_RxIndication(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) PhysAddrPtr,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr,
    uint16 LenByte );

/***********************************************************************************************************************
 *  TcpIp_VSockRxIndicationAsr42x
 **********************************************************************************************************************/
/*! \brief      Receive Indication Callback
 *  \param[in]  SockIdx               socket index
 *  \param[in]  RxSockPtr             pointer to socket
 *  \param[in]  DataDescPtr           pointer to received data
 *  \return     void
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VSockRxIndicationAsr42x(
    TcpIp_SockIdxType SockIdx,
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_CONST) RxSockAddrPtr,
    P2VAR(IpBase_PbufType, AUTOMATIC, TCPIP_APPL_DATA) DataDescPtr );

/***********************************************************************************************************************
 *  TcpIp_VSockTxConfirmation
 **********************************************************************************************************************/
/*! \brief      tx confirmation callback for socket
 *  \param[in]  SockIdx               socket index
 *  \param[in]  DataLenByte           length of confirmed data in bytes
 *  \return     void
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VSockTxConfirmation(
    TcpIp_SockIdxType SockIdx,
    uint32 DataLenByte );

/***********************************************************************************************************************
 *  TcpIp_Cbk_VLocalIpAssignmentChg
 **********************************************************************************************************************/
/*! \brief      IP state change / event Callback
 *  \param[in]  LocalAddrId           local address identifier
 *  \param[in]  State                 new state of address (ASSIGNED, UNASSIGNED, ONHOLD)
 *  \return     void
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Cbk_VLocalIpAssignmentChg(
  TcpIp_LocalAddrIdType LocalAddrId,
  TcpIp_IpAddrStateType State );

/***********************************************************************************************************************
 *  TcpIp_Cbk_VTrcvLinkStateChg
 **********************************************************************************************************************/
/*! \brief      IP state change / event Callback
 *  \param[in]  IpCtrlIdx             IP controller / transceiver index
 *  \param[in]  IpCtrlFamily          Family of the IP controller (AF_INET or AF_INET6)
 *  \param[in]  Assigned              assignment flag
 *  \return     void
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Cbk_VTrcvLinkStateChg(
  uint8 IpCtrlIdx,
  IpBase_FamilyType IpCtrlFamily,
  boolean Assigned );

/***********************************************************************************************************************
 *  TcpIp_Cbk_VPathMtuChg
 **********************************************************************************************************************/
/*! \brief      The Path-MTU has changed for a certain destination address
 *  \param[in]  CtrlIdx               controller index
 *  \param[in]  SockAddrPtr           net address that changed its state
 *  \param[in]  PathMtuSize           new size of the Path-MTU (transport layer part)
 *  \return     void
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Cbk_VPathMtuChg(
  uint8 CtrlIdx,
  P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockAddrPtr,
  uint16 PathMtuSize );

/***********************************************************************************************************************
 *  TcpIp_Cbk_VAddrResTimeout
 **********************************************************************************************************************/
/*! \brief      Address resolution timout Callback
 *  \param[in]  LocalAddrId           local address identifier
 *  \param[in]  DestAddrPtr           Pointer to destination address
 *  \return     void
 *  \context    interrupt or task level
 *  \note       The address resolution for the given address timed out on the given controller, after the address
 *              resolution request was accepted earlier.
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Cbk_VAddrResTimeout(
  TcpIp_LocalAddrIdType LocalAddrId,
  P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) DestAddrPtr );

#if (TCPIP_SUPPORT_TCP == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_VSockTcpStateChg
 **********************************************************************************************************************/
/*! \brief      TCP state change / event Callback
 *  \param[in]  SockIdx               socket index
 *  \param[in]  SoUserIdx             socket user
 *  \param[in]  State                 new socket state
 *  \param[in]  SocketUsesTls         indicates wether the socket uses TLS
 *  \return     void
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VSockTcpStateChg(
  TcpIp_SockIdxType SockIdx,
  uint8 SoUserIdx,
  TcpIp_StateType State,
  boolean SocketUsesTls );

/***********************************************************************************************************************
 *  TcpIp_VSockTcpStateChgAccepted
 **********************************************************************************************************************/
/*! \brief      TCP state change / event Callback
 *  \description   This function is derived from TcpIp_VSockTcpStateChg but implements a special handling including a return type.
 *  \param[in]  SockIdx               socket index
 *  \param[in]  SoUserIdx             socket user
 *  \return     E_OK                  The user accepted the accepted connection <br>
 *              E_NOT_OK              The user refused the accepted connection
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_VSockTcpStateChgAccepted(
  TcpIp_SockIdxType SockIdx,
  uint8 SoUserIdx );
#endif
  /* (STD_ON == TCPIP_SUPPORT_TCP) */

/***********************************************************************************************************************
 *  TcpIp_VRstCtrl
 **********************************************************************************************************************/
/*! \brief      This API call resets some variables for one controller
 *  \param[in]  localAddrId      IP address identifier of the address that triggered the reset.
 *  \return     void
 *  \context    transceiver link loss, or IP address expiration
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VRstCtrl(TcpIp_LocalAddrIdType localAddrId);

/***********************************************************************************************************************
 *  TcpIp_VIpGetRandNoFct
 **********************************************************************************************************************/
/*! \brief      This API provides a random number to the lower layer (IPv4, IPv6)
 *  \param[in]  void
 *  \return     RandNo              random number
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(uint16, TCPIP_CODE) TcpIp_VIpGetRandNoFct(void );

#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif
  /* TCPIP_CBK_H */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Cbk.h
 *********************************************************************************************************************/
