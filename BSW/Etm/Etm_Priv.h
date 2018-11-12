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
/**        \file  Etm_Priv.h
 *        \brief  Etm header file
 *
 *      \details  Implementation of the Etm module
 *                (Ethernet Testability Module for TCP/IP for interaction with IxANVL from Ixia)
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#if !defined (ETM_PRIV_H)
#define ETM_PRIV_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Etm_Types_Priv.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ETM_CMD_CHAN_IDX_UDP_V4             0x0U /* Command channel UDPv4 connetcion */
#define ETM_CMD_CHAN_IDX_UDP_V6             0x1U /* Command channel UDPv6 connetcion */
#define ETM_CMD_CHAN_IDX_TCP_V4             0x2U /* Command channel TCPv4 listen port */
#define ETM_CMD_CHAN_IDX_TCP_V6             0x3U /* Command channel TCPv6 listen port */
#define ETM_CMD_CHAN_IDX_TCP_C4             0x4U /* Command channel TCPv4 connetcion */
#define ETM_CMD_CHAN_IDX_TCP_C6             0x5U /* Command channel TCPv6 connetcion */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

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

/* General -- Buffer Handling */
FUNC(Std_ReturnType, ETM_CODE) Etm_VCheckLength(const uint32 TotalDataLength, const uint32 Offset, const uint32 LengthToReadOrWrite);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetNext8Bit(const uint8 Data, const uint32 Offset, ETM_P2V(uint8) ResultDataPtr, const uint32 ResultDataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetNext16Bit(const uint16 Data, const uint32 Offset, ETM_P2V(uint8) ResultDataPtr, const uint32 ResultDataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetNext32Bit(const uint32 Data, const uint32 Offset, ETM_P2V(uint8) ResultDataPtr, const uint32 ResultDataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetNext8Bit(ETM_P2C(uint8) DataPtr, const uint32 DataLength, const uint32 Offset, ETM_P2V(uint8) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetNext16Bit(ETM_P2C(uint8) DataPtr, const uint32 DataLength, const uint32 Offset, ETM_P2V(uint16) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetNext32Bit(ETM_P2C(uint8) DataPtr, const uint32 DataLength, const uint32 Offset, ETM_P2V(uint32) ResultPtr);

/* Etm Helpers -- General */
FUNC(void, ETM_CODE) Etm_VOpenCommandChannel(const uint8 ChannelIdx);
FUNC(void, ETM_CODE) Etm_VCloseCommandChannel(const uint8 ChannelIdx);
FUNC(uint8, ETM_CODE) Etm_VFindTestChannelIndex(const TcpIp_SocketIdType SocketId);
FUNC(boolean, ETM_CODE) Etm_VTestChannelActive(const TcpIp_SocketIdType SocketId);
FUNC(TcpIp_LocalAddrIdType, ETM_CODE) Etm_VGetLocAddrIdFromAddr(ETM_P2C(TcpIp_SockAddrType) Addr);

/* Etm Helpers -- Message Handling */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetVIntDataPtr(ETM_P2C(uint8) DataPtr, const uint32 DataLength, const uint32 Offset, ETM_P2V(uint8*) ResultPtrPtr, ETM_P2V(uint16) ResultLengthPtr, const boolean CopyData);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetVIntAddr(ETM_P2C(uint8) DataPtr, const uint32 DataLength, const uint32 Offset, ETM_P2V(TcpIp_SockAddrType) ResultPtr, ETM_P2V(uint16) ResultLengthPtr /* can be used to calculate data offset for next parameter access */);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderSid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint16) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderEvb(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(boolean) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderGid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint8) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderPid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint8) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderLen(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint32) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderTid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint8) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGetHeaderRid(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(uint8) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetSidInBuffer(const uint16 Sid, ETM_P2V(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetEvbInBuffer(const boolean Evb, ETM_P2V(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetGidInBuffer(const uint8 Gid, ETM_P2V(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetPidInBuffer(const uint8 Pid, ETM_P2V(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetLenInBuffer(const uint32 Len, ETM_P2V(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetTidInBuffer(const Etm_TypeIdType Tid, ETM_P2V(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetRidInBuffer(const Etm_ResultIdType Rid, ETM_P2V(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSetVersionsInBuffer(ETM_P2V(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VParseHeader(ETM_P2C(uint8) DataPtr, const uint32 DataLength, ETM_P2V(Etm_HeaderType) ResultPtr);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSendMessage(ETM_P2C(Etm_HeaderType) Header, const Etm_TypeIdType Tid, const Etm_ResultIdType Rid, ETM_P2C(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSendResponse(ETM_P2C(Etm_HeaderType) Header, const Etm_ResultIdType Rid, ETM_P2C(uint8) DataPtr, const uint32 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSendResponseWithoutPayload(ETM_P2C(Etm_HeaderType) Header, const Etm_ResultIdType Rid);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSendEvent(ETM_P2V(Etm_HeaderType) Header);
/* Etm Helpers -- Command Handling */
FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessEtmCommands(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessGerneralCommands(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessUdpCommands(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessTcpCommands(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessUserScriptCommands(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VProcessUserScriptCommandsPending(void);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSaveUserScriptCommand(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VSaveCommand(ETM_P2C(Etm_HeaderType) Header);
/* Etm Helpers -- Command Handling -- Group: GENERAL */
FUNC(Std_ReturnType, ETM_CODE) Etm_VGeneralGetVersion(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGeneralStartTest(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VGeneralEndTest(ETM_P2C(Etm_HeaderType) Header);
/* Etm Helpers -- Command Handling -- Group: UDP */
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpCloseSocket(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpCreateAndBind(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpSendData(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpReceiveAndForward(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpConfigureSocket(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VUdpShutdown(ETM_P2C(Etm_HeaderType) Header);
/* Etm Helpers -- Command Handling -- Group: TCP */
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpCloseSocket(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpCreateAndBind(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpSendData(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpReceiveAndForward(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpListenAndAccept(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpConnect(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpConfigureSocket(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VTcpShutdown(ETM_P2C(Etm_HeaderType) Header);
/* Etm Helpers -- Command Handling -- Common APIs */
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiCloseSocket(ETM_P2C(Etm_HeaderType) Header, const TcpIp_SocketIdType SocketId, const boolean Abort);
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiCreateAndBind(ETM_P2C(Etm_HeaderType) Header, const TcpIp_ProtocolType Protocol);
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiSendData(ETM_P2C(Etm_HeaderType) Header, const TcpIp_SocketIdType SocketId, const uint16 TotalLength, ETM_P2C(TcpIp_SockAddrType) DestinationAddressPtr, const uint16 DataLength);
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiSendDataPending(void);
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiReceiveAndForward(ETM_P2C(Etm_HeaderType) Header, const TcpIp_ProtocolType Protocol);
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiConfigureSocket(ETM_P2C(Etm_HeaderType) Header);
FUNC(Std_ReturnType, ETM_CODE) Etm_VApiShutdown(ETM_P2C(Etm_HeaderType) Header);

#define ETM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* ETM_PRIV_H */

/**********************************************************************************************************************
 *  END OF FILE: Etm_Priv.h
 *********************************************************************************************************************/
