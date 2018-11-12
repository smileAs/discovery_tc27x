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
 *         \file  TcpIp_Priv.c
 *        \brief  Implementation of TcpIp Module - Internal Functions
 *
 *      \details  This file is part of the TcpIp module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp module. >> TcpIp.h
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */

#define TCPIP_PRIV_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_Priv.h"
#include "TcpIp.h"

#include "IpBase.h"

#if (TCPIP_SUPPORT_TCP == STD_ON)
#include "TcpIp_Tcp.h"
#endif

#include "TcpIp_Udp.h"

#if (TCPIP_SUPPORT_DHCPV4 == STD_ON)
#include "TcpIp_DhcpV4.h"
#endif

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
#include "TcpIp_IpV4.h"
#endif

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
#include "TcpIp_IpV6.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if defined (STATIC)
#else
# define STATIC static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/* ----- */
#define TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ----- */
#define TCPIP_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
VAR(uint8, TCPIP_VAR_NOINIT) TcpIp_ActiveState;

#if ( TCPIP_VENABLE_CANOE_WRITE_STRING == STD_ON )
VAR(sint8, TCPIP_VAR_NOINIT)                TcpIp_CanoeWriteStr[256];
#endif
  /* TCPIP_VENABLE_CANOE_WRITE_STRING */

#define TCPIP_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ----- */
#define TCPIP_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if (TCPIP_SUPPORT_TCP == STD_ON)
VAR(uint16, TCPIP_VAR_NOINIT)               TcpIp_Tcp_DynamicPortCount;
# endif
VAR(uint16, TCPIP_VAR_NOINIT)               TcpIp_Udp_DynamicPortCount;

#define TCPIP_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define TCPIP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
CONST(IpBase_AddrIn6Type, TCPIP_CONST) TcpIp_Ipv6NullAddr =  /* PRQA S 0759 */ /* MD_TCPIP_18.4_0759 */
{
  {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  }
};
#endif

#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  TcpIp_VMatchLocalIpAddrIdAndPort()
 **********************************************************************************************************************/
STATIC FUNC(boolean, TCPIP_CODE) TcpIp_VMatchLocalIpAddrIdAndPort(
    TcpIp_SockIdxType              sockIdx,
    TCPIP_P2C(IpBase_SockAddrType) rxSockLocAddrPtr,
    TcpIp_LocalAddrIdType          localAddrId);

#if (TCPIP_ENABLE_DLISTS == STD_ON)
/* Doubly Linked List (DList) Data Structure */

/* DList raw functions */

/**********************************************************************************************************************
 *  TcpIp_DListRawAddAfter()
 **********************************************************************************************************************/
STATIC FUNC(void, TCPIP_CODE) TcpIp_DListRawAddAfter(
  TCPIP_P2V(TcpIp_DListNodeType) NodeSetPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  FirstIdxPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  LastIdxPtr,
  TcpIp_DListIdxType            NewIdx,
  TcpIp_DListIdxType            AfterIdx);

/**********************************************************************************************************************
 *  TcpIp_DListRawAddRangeAfter()
 **********************************************************************************************************************/
STATIC FUNC(void, TCPIP_CODE) TcpIp_DListRawAddRangeAfter(
  TCPIP_P2V(TcpIp_DListNodeType) NodeSetPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  FirstIdxPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  LastIdxPtr,
  TcpIp_DListIdxType            NewStartIdx,
  TcpIp_DListIdxType            NewEndIdx,
  TcpIp_DListIdxType            AfterIdx);

/**********************************************************************************************************************
 *  TcpIp_DListRawRemove()
 **********************************************************************************************************************/
STATIC FUNC(void, TCPIP_CODE) TcpIp_DListRawRemove(
  TCPIP_P2V(TcpIp_DListNodeType) NodeSetPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  FirstIdxPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  LastIdxPtr,
  TcpIp_DListIdxType            RemIdx);

/**********************************************************************************************************************
 *  TcpIp_DListRawRemoveRange()
 **********************************************************************************************************************/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp_DListRawRemoveRange(
  TCPIP_P2V(TcpIp_DListNodeType)  NodeSetPtr,
  TCPIP_P2V(TcpIp_DListIdxType)   FirstIdxPtr,
  TCPIP_P2V(TcpIp_DListIdxType)   LastIdxPtr,
  TcpIp_DListIdxType             RemStartIdx,
  TcpIp_DListIdxType             RemEndIdx);

#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  TcpIp_ComparePhysAddr
 **********************************************************************************************************************/
/*! \brief       This API compares two physical addresses
 *  \param[in]   PhysAddrOnePtr         pointer to physical address one
 *  \param[in]   PhysAddrTwoPtr         pointer to physical address two
 *  \return      TRUE                   identical physical addresses (one == two)
 *  \return      FALSE                  different physical addresses (one != two)
 *  \context     interrupt or task level
 **********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_ComparePhysAddr(
    P2CONST(uint8, TCPIP_APPL_DATA, TCPIP_CONST) PhysAddrOnePtr,
    P2CONST(uint8, TCPIP_APPL_DATA, TCPIP_CONST) PhysAddrTwoPtr )
{
  boolean Identical = TRUE;
  uint8 Idx = TCPIP_PHYS_ADDR_LEN_BYTE;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

  if( (NULL_PTR == PhysAddrOnePtr) || (NULL_PTR == PhysAddrTwoPtr) )
  {
    Identical = FALSE;
    return Identical;
  }

  while(0 < Idx)
  {
    Idx--;
    if(PhysAddrOnePtr[Idx] != PhysAddrTwoPtr[Idx])
    {
      Identical = FALSE;
      break;
    }
  }

  return Identical;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */
/***********************************************************************************************************************
 *  TcpIp_VMatchLocalIpAddrIdAndPort
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
/* PRQA S 0715 CTRL_NEST_LIMIT */ /* MD_MSR_1.1_0715 */
STATIC FUNC(boolean, TCPIP_CODE) TcpIp_VMatchLocalIpAddrIdAndPort(
    TcpIp_SockIdxType              sockIdx,
    TCPIP_P2C(IpBase_SockAddrType) rxSockLocAddrPtr,
    TcpIp_LocalAddrIdType          localAddrId)
{
  boolean retVal = FALSE;

  /* #10 Check if socket is bound the ANY controller/IP address. */
  if (TcpIp_SocketList[sockIdx].BindLocalAddrId == TCPIP_LOCALADDRID_ANY)
  {
    retVal = TRUE;
  }
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
  /* #20 Check if address specified by localAddrId is an IPv4 address. */
  else if (TCPIP_LOCAL_ADDR_IS_AF_INET(localAddrId))
  {
    /* Received packet via IPv4 */

    /* #30 Check if socket is bound to an IPv4 address. */
    if (TCPIP_LOCAL_ADDR_IS_AF_INET(TcpIp_SocketList[sockIdx].BindLocalAddrId))
    {
      /* #40 Ask IPv4 layer whether localAddrId of received packet matches the localAddrId to which the socket is bound. */
      uint8 matchType;

      /* Socket is bound to IPv4 address */
      IpV4_AddrIdType IpV4AddrId = TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(TcpIp_SocketList[sockIdx].BindLocalAddrId);

      if (IpV4_Ip_IsAddrIdAcceptable(IpV4AddrId, TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(localAddrId), &matchType) == TRUE)
      {
        /* MATCH */
        retVal = TRUE;
      }
    }
    else
    {
      /* Socket is unbound or bound to other address family. -> This socket does not match. */
    }
  }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  /* #50 Check if address specified by localAddrId is an IPv6 address. */
  else if (TCPIP_COND_VALID_LOCALADDRID(localAddrId)) /* Just check for valid ID instead of INET6 because it would be redundant (produce MISRA warning) since INET is already checked above. */
  {
    /* #60 Check if socket is bound to an IPv6 address. */
    if (TCPIP_LOCAL_ADDR_IS_AF_INET6(TcpIp_SocketList[sockIdx].BindLocalAddrId))
    {
      /* #70 Ask IPv4 layer whether localAddrId of received packet matches the localAddrId to which the socket is bound. */
      uint8 matchType;

      IpV6_AddrIdType IpV6AddrId = TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(TcpIp_SocketList[sockIdx].BindLocalAddrId);

      if (IpV6_IsAddrIdAcceptable(IpV6AddrId, TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(localAddrId), &matchType) == TRUE)
      {
        /* MATCH */
        retVal = TRUE;
      }
    }
    else
    {
      /* socket is unbound or bound to other address family. -> This socket does not match. */
    }
  }
#endif
  else
  {
    /* invalid or unsupported address family! */
    TcpIp_CallDetReportError(TCPIP_API_ID_RX_SOCK_IDENT, TCPIP_E_AFNOSUPPORT)
  }

  /* #80 If IP address matches to bound IP address return TRUE if port is equal to the bound port of the socket. */
  if (retVal == TRUE)
  {
    retVal = IpBase_SockPortIsEqual((TCPIP_P2C(IpBase_SockAddrType))&TcpIp_SocketList[sockIdx].LocSock, rxSockLocAddrPtr); /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  TcpIp_VRxUdpSockIdxIdent
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
/* PRQA S 0715 CTRL_NEST_LIMIT */ /* MD_MSR_1.1_0715 */
FUNC(boolean, TCPIP_CODE) TcpIp_VRxUdpSockIdxIdent(
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_CONST) RxSockLocAddrPtr,
    TcpIp_LocalAddrIdType                                LocalAddrId)
{
  TcpIp_SockIdxType udpSockIdx;
  TcpIp_SockIdxType udpSockIdxMatch = TCPIP_INV_SOCK_IDX;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                           TCPIP_API_ID_RX_SOCK_IDENT, TCPIP_E_NOTINIT,       TCPIP_INV_SOCK_IDX )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(RxSockLocAddrPtr),    TCPIP_API_ID_RX_SOCK_IDENT, TCPIP_E_PARAM_POINTER, TCPIP_INV_SOCK_IDX )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_LOCALADDRID(LocalAddrId), TCPIP_API_ID_RX_SOCK_IDENT, TCPIP_E_INV_ARG,       TCPIP_INV_SOCK_IDX )
  /* ------------------------------------------------- */

  /* #10 Iterate over all UDP sockets and match IP address and port information. */

  for(udpSockIdx = 0; udpSockIdx < TcpIp_VCfgGetMaxNumUdpSocks(); udpSockIdx++)
  {
    /* #20 Check if UDP socket is bound. */
    if (TcpIp_SockListenActive[udpSockIdx].ConnStat == TCPIP_SOCK_CONN_LISTEN_ENABLED)
    {
      /* #30 Check if socket is bound to a LocalAddrId and port that matches to the LocalAddrId and port of received packet. */
      if (TcpIp_VMatchLocalIpAddrIdAndPort(udpSockIdx, RxSockLocAddrPtr, LocalAddrId) == TRUE)
      {
        udpSockIdxMatch = udpSockIdx;
        break;
      }
    }
  }

  return udpSockIdxMatch;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6080 */ /* MD_MSR_STMIF */
/* PRQA L:CTRL_NEST_LIMIT */

#if (TCPIP_SUPPORT_TCP == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_VRxTcpSockIdxIdent
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
/* PRQA S 0715 CTRL_NEST_LIMIT */ /* MD_MSR_1.1_0715 */
FUNC(TcpIp_SockIdxType, TCPIP_CODE) TcpIp_VRxTcpSockIdxIdent(
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_CONST) RxSockRemAddrPtr,
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_CONST) RxSockLocAddrPtr,
    TcpIp_LocalAddrIdType                                LocalAddrId)
{
  TcpIp_SockIdxType tcpSockIdx;
  TcpIp_SockIdxType tcpSockIdxMatch = TCPIP_INV_SOCK_IDX;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                           TCPIP_API_ID_RX_SOCK_IDENT, TCPIP_E_NOTINIT,       TCPIP_INV_SOCK_IDX )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(RxSockRemAddrPtr),    TCPIP_API_ID_RX_SOCK_IDENT, TCPIP_E_PARAM_POINTER, TCPIP_INV_SOCK_IDX )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(RxSockLocAddrPtr),    TCPIP_API_ID_RX_SOCK_IDENT, TCPIP_E_PARAM_POINTER, TCPIP_INV_SOCK_IDX )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_LOCALADDRID(LocalAddrId), TCPIP_API_ID_RX_SOCK_IDENT, TCPIP_E_INV_ARG,       TCPIP_INV_SOCK_IDX )
  /* ------------------------------------------------- */

  /* #10 Iterate over all TCP sockets and match IP address and Port information. */
  for(tcpSockIdx = TcpIp_VCfgGetMaxNumUdpSocks(); tcpSockIdx < TcpIp_VCfgGetMaxNumSocks(); tcpSockIdx++)
  {
    if (TcpIp_SockListenActive[tcpSockIdx].ConnStat == TCPIP_SOCK_CONN_CONNECTED)
    {
      /* #20 Check if socket is a connected TCP socket and (Remote IP, Remote Port, Local IP, Local Port) match exactly. */

      if (TcpIp_VSockAddrIpAndPortIsEqual((TCPIP_P2C(IpBase_SockAddrType))&TcpIp_SocketList[tcpSockIdx].LocSock, RxSockLocAddrPtr) == TRUE) /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
      {
        /* Local IP address and Port match. */
        if (TcpIp_VSockAddrIpAndPortIsEqual((TCPIP_P2C(IpBase_SockAddrType))&TcpIp_SocketList[tcpSockIdx].RemSock, RxSockRemAddrPtr) == TRUE) /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
        {
          /* Local and Remote IP address and Port match. */
          tcpSockIdxMatch = tcpSockIdx;
          break;
        }
      }
    }
    else if (TcpIp_SockListenActive[tcpSockIdx].ConnStat == TCPIP_SOCK_CONN_LISTEN_ENABLED)
    {
      /* #30 If TCP socket is in state bound match IP address. */
      if (TcpIp_VMatchLocalIpAddrIdAndPort(tcpSockIdx, RxSockLocAddrPtr, LocalAddrId) == TRUE)
      {
        tcpSockIdxMatch = tcpSockIdx;
        /* Listen socket matches but continue search because there may be an established socket for this connection. */
      }
    }
    else
    {
      /* This socket does not match. */
    }
  }

  return tcpSockIdxMatch;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6080 */ /* MD_MSR_STMIF */
/* PRQA L:CTRL_NEST_LIMIT */
#endif

/***********************************************************************************************************************
 *  TcpIp_SetLastSockError
 **********************************************************************************************************************/
/*! \brief       set last socket error
 *  \param[in]   Error                  error code
 *  \context     interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_SetLastSockError(
    uint16 Error )
{
  TcpIp_LastSockError = Error;
}

/***********************************************************************************************************************
 *  TcpIp_VInitSockets
 **********************************************************************************************************************/
/*! \brief       init of all sockets
 *  \context     initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VInitSockets(void)
{
  TcpIp_SockIdxType SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

  TcpIp_LastSockError = 0;

  for(SockIdx=0; SockIdx < (TcpIp_VCfgGetMaxNumSocks()); SockIdx++)
  {
    TcpIp_VInitSocket(SockIdx);
  }
}

/***********************************************************************************************************************
 *  TcpIp_VInitSocket
 **********************************************************************************************************************/
/*! \brief       init of one single socket
 *  \param[in]   SockIdx                socket index
 *  \context     initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VInitSocket(
    TcpIp_SockIdxType SockIdx )
{
  TcpIp_VDelSockAddrMapping(SockIdx);
  TcpIp_VInitTxSocket(SockIdx);
  TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_NONE;
  TcpIp_SockUserIdx[SockIdx]               = TCPIP_UNDEFINED_SOCK_OWNER_IDX;
  TcpIp_VPreconfigSocket(SockIdx);
}

/***********************************************************************************************************************
 *  TcpIp_VInitTxSocket
 **********************************************************************************************************************/
/*! \brief       init some variables of a tx socket
 *  \param[in]   SockIdx                socket index
 *  \context     initialization / reset
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VInitTxSocket(TcpIp_SockIdxType SockIdx)
{
  TcpIp_TxBufFillLevel[SockIdx] = 0;
  TcpIp_TxBufWritePos[SockIdx]  = 0;
  TcpIp_TxBufRequested[SockIdx] = FALSE;

  /* init Pbuf element */
  TcpIp_TxPbufArray[SockIdx <<1].totLen = 0;
}

/***********************************************************************************************************************
 *  TcpIp_VDelSockAddrMapping
 **********************************************************************************************************************/
/*! \brief       delete socket address mapping
 *  \param[in]   SockIdx                socket index
 *  \context     task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VDelSockAddrMapping(
    TcpIp_SockIdxType SockIdx )
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_SOCKIDX(SockIdx), TCPIP_API_ID_V_DEL_SOCK_ADDR_MAPPING, TCPIP_E_INV_SOCK_ID )
  /* ------------------------------------------------- */

  ((IpBase_SockAddrInType *)(&TcpIp_SocketList[SockIdx].RemSock))->sin_family = IPBASE_AF_UNSPEC;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  ((IpBase_SockAddrInType *)(&TcpIp_SocketList[SockIdx].LocSock))->sin_family = IPBASE_AF_UNSPEC;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  (void)IpBase_CopyIpV6Addr( &((IpBase_SockAddrIn6Type *)(&TcpIp_SocketList[SockIdx].RemSock))->sin6_addr, &TcpIp_Ipv6NullAddr);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  (void)IpBase_CopyIpV6Addr( &((IpBase_SockAddrIn6Type *)(&TcpIp_SocketList[SockIdx].LocSock))->sin6_addr, &TcpIp_Ipv6NullAddr);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
#else
  ((IpBase_SockAddrInType *)(&TcpIp_SocketList[SockIdx].RemSock))->sin_addr   = TCPIP_INADDR_ANY;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  ((IpBase_SockAddrInType *)(&TcpIp_SocketList[SockIdx].LocSock))->sin_addr   = TCPIP_INADDR_ANY;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
#endif
  ((IpBase_SockAddrInType *)(&TcpIp_SocketList[SockIdx].RemSock))->sin_port   = 0;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  ((IpBase_SockAddrInType *)(&TcpIp_SocketList[SockIdx].LocSock))->sin_port   = 0;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */

  TcpIp_SockUserIdx[SockIdx] = TCPIP_UNDEFINED_SOCK_OWNER_IDX;

  TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_NONE;

  TcpIp_SocketList[SockIdx].IsTcpListenSocket      = FALSE;
  TcpIp_SocketList[SockIdx].TcpMaxNumListenSockets = 0;
  TcpIp_SocketList[SockIdx].TcpMasterListenSockId  = TCPIP_INV_SOCKET_ID;  /* invalid */

  /* Reset TX IpAddrId */
  {
    /* Socket has ANY binding. This means use any IP on any controller for transmission */
    TcpIp_SocketList[SockIdx].TxIpAddrId      = TCPIP_IPVX_ADDR_ID_ANY; /* 0xFF */
    TcpIp_SocketList[SockIdx].BindLocalAddrId = TCPIP_LOCALADDRID_ANY;  /* 0xFE */
  }

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
  IpV4_Ip_ResetSocket(SockIdx);
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  IpV6_ResetSocket(SockIdx);
#endif

}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_VSockIpAddrIsEqual
 **********************************************************************************************************************/
/*! \brief         check if ip addr of sockets is equal
 *  \param[inout]  SockAPtr             target socket address
 *  \param[in]     SockBPtr             source socket address
 *  \return        TRUE                 IP addr is equal
 *  \return        FALSE                IP addr is not equal
 *  \context       interrupt or task level
 **********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_VSockIpAddrIsEqual(
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockAPtr,
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockBPtr )
{
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(SockAPtr), TCPIP_API_ID_SOCK_ADDR_IS_EQ, TCPIP_E_PARAM_POINTER, FALSE )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(SockBPtr), TCPIP_API_ID_SOCK_ADDR_IS_EQ, TCPIP_E_PARAM_POINTER, FALSE )

  if(SockAPtr->sa_family != SockBPtr->sa_family)
  {
    return FALSE;
  }

  if(IPBASE_AF_INET == SockAPtr->sa_family)
  {
    if( ((const IpBase_SockAddrInType*)SockAPtr)->sin_addr == ((const IpBase_SockAddrInType*)SockBPtr)->sin_addr )  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
    {
      return TRUE;
    }
    else
    {
      return FALSE;
    }
  }

  if(IPBASE_AF_INET6 == SockAPtr->sa_family)
  {
    uint16 i = sizeof(IpBase_AddrIn6Type);
    while(i != 0)
    {
      i--;
      if( ((const uint8*)&((const IpBase_SockAddrIn6Type*)SockAPtr)->sin6_addr)[i] !=  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_compare */  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
          ((const uint8*)&((const IpBase_SockAddrIn6Type*)SockBPtr)->sin6_addr)[i] )   /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_compare */  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      {
        return FALSE;
      }
    }
    return TRUE;
  }

  /* error, no valid sa_family */
  return FALSE;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */

/***********************************************************************************************************************
 *  TcpIp_VSockAddrIpAndPortIsEqual
 **********************************************************************************************************************/
/*! \brief         check if ip addr and port of sockets are equal
 *  \param[inout]  SockAPtr             target socket address
 *  \param[in]     SockBPtr             source socket address
 *  \return        TRUE                 IP addr and port are equal
 *  \return        FALSE                IP addr and port are not equal
 *  \context       interrupt or task level
 **********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_VSockAddrIpAndPortIsEqual(
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockAPtr,
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockBPtr )
{
  boolean Match = FALSE;
  
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(SockAPtr), TCPIP_API_ID_SOCK_ADDR_IS_EQ, TCPIP_E_PARAM_POINTER, FALSE )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(SockBPtr), TCPIP_API_ID_SOCK_ADDR_IS_EQ, TCPIP_E_PARAM_POINTER, FALSE )

  if(SockAPtr->sa_family == SockBPtr->sa_family)
  {
    switch (SockAPtr->sa_family)
    {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
    case IPBASE_AF_INET:
      {
        TCPIP_P2C(IpBase_SockAddrInType) SockAddrInAPtr = (TCPIP_P2C(IpBase_SockAddrInType))SockAPtr; /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
        TCPIP_P2C(IpBase_SockAddrInType) SockAddrInBPtr = (TCPIP_P2C(IpBase_SockAddrInType))SockBPtr; /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      
        if (SockAddrInAPtr->sin_addr == SockAddrInBPtr->sin_addr)
        {
          if (SockAddrInAPtr->sin_port == SockAddrInBPtr->sin_port)
          {
            Match = TRUE;
          }
        }
      }
      break;
#endif

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
    case IPBASE_AF_INET6:
      {
        TCPIP_P2C(IpBase_SockAddrIn6Type) SockAddrInAPtr = (TCPIP_P2C(IpBase_SockAddrIn6Type))SockAPtr; /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
        TCPIP_P2C(IpBase_SockAddrIn6Type) SockAddrInBPtr = (TCPIP_P2C(IpBase_SockAddrIn6Type))SockBPtr; /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      
        if ((SockAddrInAPtr->sin6_addr.addr32[0] == SockAddrInBPtr->sin6_addr.addr32[0]) &&
            (SockAddrInAPtr->sin6_addr.addr32[1] == SockAddrInBPtr->sin6_addr.addr32[1]) &&
            (SockAddrInAPtr->sin6_addr.addr32[2] == SockAddrInBPtr->sin6_addr.addr32[2]) &&
            (SockAddrInAPtr->sin6_addr.addr32[3] == SockAddrInBPtr->sin6_addr.addr32[3]))
        {
          if (SockAddrInAPtr->sin6_port == SockAddrInBPtr->sin6_port)
          {
            Match = TRUE;
          }
        }
      }
      break;
#endif

    default:
      /* no match */
      break;
    }
  }

  return Match;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */

/***********************************************************************************************************************
 *  TcpIp_VCalcPseudoHdrAndChecksum
 **********************************************************************************************************************/
/*! \brief      Calculates IP pseudo header and payload checksum and returns a partial or finalized result.
 *  \param[in]  RxSockRemAddrPtr      pointer to remote address value
 *  \param[in]  RxSockLocAddrPtr      pointer to local address value
 *  \param[in]  DataPtr               pointer to payload data
 *  \param[in]  DataLen               length payload data in bytes
 *  \param[in]  Protocol              protocol identifier
 *  \return     DataPtr != NULL_PTR: Checksum value finalized to uint16 range.
 *  \return     DataPtr == NULL_PTR: Partial uint32 checksum value that can be passed to IpBase_TcpIpChecksumAdd()
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(uint32, TCPIP_CODE) TcpIp_VCalcPseudoHdrAndChecksum(
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RxSockRemAddrPtr,
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RxSockLocAddrPtr,
    P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr,
    CONST(uint16, AUTOMATIC) DataLen,
    CONST(uint8, AUTOMATIC) Protocol )
{
  uint32 Checksum; /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  if(IPBASE_AF_INET == RxSockRemAddrPtr->sa_family)
#endif
  {
    /* V4 */
    TcpIp_PseudoHdrBlockV4Type PseudoHdr;
    TcpIp_PseudoHdrV4Type *PseudoHdrPtr = (TcpIp_PseudoHdrV4Type*)&PseudoHdr[0];  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */

    PseudoHdrPtr->RemAddr  = ((const IpBase_SockAddrInType*)RxSockRemAddrPtr)->sin_addr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
    PseudoHdrPtr->LocAddr  = ((const IpBase_SockAddrInType*)RxSockLocAddrPtr)->sin_addr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
    PseudoHdrPtr->Null     = 0;
    PseudoHdrPtr->Protocol = Protocol;
    PseudoHdrPtr->LenByte  = IPBASE_HTON16(DataLen);
    Checksum = IpBase_TcpIpChecksumAdd((TCPIP_P2V(uint8))PseudoHdrPtr, (sizeof(PseudoHdr)), 0, FALSE);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */
    if (DataPtr != NULL_PTR)
    {
      /* Payload provided. Add payload checksum and finalize result. */
      Checksum = IpBase_TcpIpChecksumAdd(DataPtr, DataLen, Checksum, TRUE);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */
    }
  }
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  else
#endif
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  {
    /* V6 */
    TcpIp_PseudoHdrBlockV6Type PseudoHdr;
    TcpIp_PseudoHdrV6Type *PseudoHdrPtr = (TcpIp_PseudoHdrV6Type*)&PseudoHdr[0];  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */

    (void)IpBase_CopyIpV6Addr(&PseudoHdrPtr->RemAddr, &((const IpBase_SockAddrIn6Type*)RxSockRemAddrPtr)->sin6_addr);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
    (void)IpBase_CopyIpV6Addr(&PseudoHdrPtr->LocAddr, &((const IpBase_SockAddrIn6Type*)RxSockLocAddrPtr)->sin6_addr);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
    PseudoHdrPtr->Null     = 0;
    PseudoHdrPtr->Protocol = Protocol;
    PseudoHdrPtr->LenByte  = IPBASE_HTON16(DataLen);
    Checksum = IpBase_TcpIpChecksumAdd((TCPIP_P2V(uint8))PseudoHdrPtr, (sizeof(PseudoHdr)), 0, FALSE);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */
    if (DataPtr != NULL_PTR)
    {
      /* Payload provided. Add payload checksum and finalize result. */
      Checksum = IpBase_TcpIpChecksumAdd(DataPtr, DataLen, Checksum, TRUE);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */
    }
  }
#endif

  return Checksum;
}

/**********************************************************************************************************************
 *  TcpIp_VPhysAddrTableChg()
 **********************************************************************************************************************/
/*! \brief      This API is called by the IpV4 or IpV6 in case of a change in the ARP/NDP table related to the
 *              controller specified by CtrlIdx.
 *  \param[in]  CtrlIdx     EthIf controller index of the related ARP/NDP table.
 *  \param[in]  IpAddrPtr   specifies the IP address of the changed ARP/NDP table entry
 *  \param[in]  PhysAddrPtr specifies the physical address of the changed ARP/NDP table entry
 *  \param[in]  valid       specifies if the ARP/NDP table entry is added or changed (TRUE) or has been removed (FALSE)
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VPhysAddrTableChg(
  uint8                         CtrlIdx,
  TCPIP_P2V(TcpIp_SockAddrType) IpAddrPtr,
  TCPIP_P2V(uint8)              PhysAddrPtr,  /* PRQA S 3206, 3673 */ /* MD_TCPIP_3206, MD_TCPIP_16.7_3673 */
  boolean                       Valid)
{
#if (TCPIP_PHYS_ADDR_TABLE_CHG_FUNCTION_CNT > 0)
  uint8_least cbkIdx;
#endif

#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
  if (FALSE == Valid)
  {
    /* clear pending UDP retry elements for unresolved destinations */
    TcpIp_Udp_CancelRetriesForDestination(CtrlIdx, IpAddrPtr);
  }
#endif

#if (TCPIP_PHYS_ADDR_TABLE_CHG_FUNCTION_CNT > 0)
  for (cbkIdx = 0; cbkIdx < TcpIp_VCfgGetPhysAddrTableChgFuncCount(); cbkIdx++)
  {
    TcpIp_PhysAddrTableChgCallbacks[cbkIdx](CtrlIdx, IpAddrPtr, PhysAddrPtr, Valid);
  }
#else
  TCPIP_UNUSED_PARAMETER(PhysAddrPtr);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
# if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_OFF)
  TCPIP_UNUSED_PARAMETER(CtrlIdx);      /* PRQA S 3112 */ /* MD_MSR_14.2 */
  TCPIP_UNUSED_PARAMETER(IpAddrPtr);    /* PRQA S 3112 */ /* MD_MSR_14.2 */
  TCPIP_UNUSED_PARAMETER(Valid);        /* PRQA S 3112 */ /* MD_MSR_14.2 */
# endif 
#endif

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of TcpIp_VPhysAddrTableChg() */

FUNC(void, TCPIP_CODE) TcpIp_RxIndicationFunctions(
    uint8                         userIndex,
    TcpIp_SocketIdType            socketId,
    TCPIP_P2V(TcpIp_SockAddrType) remoteSockAddrPtr,
    TCPIP_P2V(uint8)              dataPtr, /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
    uint16                        dataLenByte)
{
  if (userIndex < TcpIp_VCfgGetNumSocketOwners())
  {
    if (TcpIp_SocketOwnerConfig[userIndex].RxIndicationFuncPtr != NULL_PTR)
    {
      TcpIp_SocketOwnerConfig[userIndex].RxIndicationFuncPtr(socketId, remoteSockAddrPtr, dataPtr, dataLenByte);
    }
    else
    {
      /* ERROR: Callback is mandatory. */
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_CBK_REQUIRED)
    }
  }
  else
  {
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_RX_INDICATION, TCPIP_E_INV_ARG)
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(void, TCPIP_CODE) TcpIp_TxConfirmationFunctions(
    uint8              userIndex,
    TcpIp_SocketIdType socketId,
    uint16             dataLenByte)
{
  if (userIndex < TcpIp_VCfgGetNumSocketOwners())
  {
    if (TcpIp_SocketOwnerConfig[userIndex].TxConfirmationFuncPtr != NULL_PTR)
    {
      TcpIp_SocketOwnerConfig[userIndex].TxConfirmationFuncPtr(socketId, dataLenByte);
    }
    else
    {
      /* OK: Callback is optional. */
    }
  }
  else
  {
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_TX_CONFIRMATION, TCPIP_E_INV_ARG)
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpAcceptedFunctions(
    uint8                         userIndex,
    TcpIp_SocketIdType            socketId,
    TcpIp_SocketIdType            socketIdConnected,
    TCPIP_P2V(TcpIp_SockAddrType) remoteSockAddrPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (userIndex < TcpIp_VCfgGetNumSocketOwners())
  {
    if (TcpIp_SocketOwnerConfig[userIndex].TcpAcceptedFuncPtr != NULL_PTR)
    {
      retVal = TcpIp_SocketOwnerConfig[userIndex].TcpAcceptedFuncPtr(socketId, socketIdConnected, remoteSockAddrPtr);
    }
    else
    {
      /* ERROR: Callback is mandatory. */
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_TCP_ACCEPTED, TCPIP_E_CBK_REQUIRED)
    }
  }
  else
  {
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_TCP_ACCEPTED, TCPIP_E_INV_ARG)
  }

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(void, TCPIP_CODE) TcpIp_TcpConnectedFunctions(
    uint8              userIndex,
    TcpIp_SocketIdType socketId)
{
  if (userIndex < TcpIp_VCfgGetNumSocketOwners())
  {
    if (TcpIp_SocketOwnerConfig[userIndex].TcpConnectedFuncPtr != NULL_PTR)
    {
      TcpIp_SocketOwnerConfig[userIndex].TcpConnectedFuncPtr(socketId);
    }
    else
    {
      /* ERROR: Callback is mandatory. */
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_TCP_CONNECTED, TCPIP_E_CBK_REQUIRED)
    }
  }
  else
  {
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_TCP_CONNECTED, TCPIP_E_INV_ARG)
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(void, TCPIP_CODE) TcpIp_TcpIpEventFunctions(
    uint8                 userIndex,
    TcpIp_SocketIdType    socketId,
    IpBase_TcpIpEventType eventType)
{
  if (userIndex < TcpIp_VCfgGetNumSocketOwners())
  {
    if (TcpIp_SocketOwnerConfig[userIndex].TcpIpEventFuncPtr != NULL_PTR)
    {
      TcpIp_SocketOwnerConfig[userIndex].TcpIpEventFuncPtr(socketId, eventType);
    }
    else
    {
      /* ERROR: Callback is mandatory. */
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_TCP_IP_EVENT, TCPIP_E_CBK_REQUIRED)
    }
  }
  else
  {
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_TCP_IP_EVENT, TCPIP_E_INV_ARG)
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_CopyTxDataFunctions(
    uint8               userIndex,
    TcpIp_SocketIdType  socketId,
    TCPIP_P2V(uint8)    bufferPtr,    /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
    TCPIP_P2V(uint16)   bufferLenBytePtr)
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

  if (userIndex < TcpIp_VCfgGetNumSocketOwners())
  {
    if (TcpIp_SocketOwnerConfig[userIndex].CopyTxDataDynFuncPtr != NULL_PTR)
    {
      retVal = TcpIp_SocketOwnerConfig[userIndex].CopyTxDataDynFuncPtr(socketId, bufferPtr, bufferLenBytePtr);
    }
    else if (TcpIp_SocketOwnerConfig[userIndex].CopyTxDataFuncPtr != NULL_PTR)
    {
      retVal = TcpIp_SocketOwnerConfig[userIndex].CopyTxDataFuncPtr(socketId, bufferPtr, *bufferLenBytePtr);
    }
    else
    {
      /* ERROR: Callback is mandatory. */
      TcpIp_CallDetReportError(TCPIP_API_ID_CBK_TCP_ACCEPTED, TCPIP_E_CBK_REQUIRED)
    }
  }
  else
  {
    TcpIp_CallDetReportError(TCPIP_API_ID_CBK_TCP_ACCEPTED, TCPIP_E_INV_ARG)
  }

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(void, TCPIP_CODE) TcpIp_LocalIpAssignmentChgFunctions(
    TcpIp_LocalAddrIdType ipAddrId,   /* PRQA S 3206 */ /* MD_TCPIP_3206 */
    TcpIp_IpAddrStateType addrState)  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
{
#if (TcpIp_VCfgGetLocalIpAssignmentChgFuncCount() > 0)
  uint8_least cbkIdx;

  for (cbkIdx = 0; cbkIdx < TcpIp_VCfgGetLocalIpAssignmentChgFuncCount(); cbkIdx++)
  {
    TcpIp_LocalIpAddrAssignmentCallbacks[cbkIdx](ipAddrId, addrState);
  }
#else
  TCPIP_UNUSED_PARAMETER(ipAddrId);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  TCPIP_UNUSED_PARAMETER(addrState); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if (TCPIP_ENABLE_DLISTS == STD_ON)

/**********************************************************************************************************************
 *  TcpIp_DListRawAddAfter()
 **********************************************************************************************************************/
/*! \brief Insert a node into a node chain.
 *  \param[in]    NodeSetPtr  Storage array of the elements of the node chain.
 *  \param[inout] FirstIdxPtr Index of the first element of the node chain.
 *  \param[inout] LastIdxPtr  Index of the last element of the node chain.
 *  \param[in]    NewIdx      Index of the new element that shall be insterted into the node chain
 *  \param[in]    AfterIdx    Index of the pedecessor of the newly inserted element. (must be in chain FirstIdx...LastIdx)
 *                            If AfterIdx is TCPIP_DLIST_END_IDX the new item will be inserted at the beginning.
 **********************************************************************************************************************/
STATIC FUNC(void, TCPIP_CODE) TcpIp_DListRawAddAfter(
  TCPIP_P2V(TcpIp_DListNodeType) NodeSetPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  FirstIdxPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  LastIdxPtr,
  TcpIp_DListIdxType            NewIdx,
  TcpIp_DListIdxType            AfterIdx)
{
#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != NodeSetPtr,  TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != FirstIdxPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != LastIdxPtr,  TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
#endif

  NodeSetPtr[NewIdx].PrevIdx = AfterIdx;

  if (TCPIP_DLIST_END_IDX != AfterIdx)
  {
    /* insert after existing node */
    NodeSetPtr[NewIdx].NextIdx = NodeSetPtr[AfterIdx].NextIdx;
    NodeSetPtr[AfterIdx].NextIdx = NewIdx;
  }
  else
  {
    /* insert as first node */
    NodeSetPtr[NewIdx].NextIdx = (*FirstIdxPtr);
    (*FirstIdxPtr) = NewIdx;
  }

  if (TCPIP_DLIST_END_IDX != NodeSetPtr[NewIdx].NextIdx)
  {
    /* new node is not last node */
    NodeSetPtr[NodeSetPtr[NewIdx].NextIdx].PrevIdx = NewIdx;
  }
  else
  {
    /* new node is last node */
    (*LastIdxPtr) = NewIdx;
  }

} /* End of TcpIp_DListRawAddAfter() */

/**********************************************************************************************************************
 *  TcpIp_DListRawAddRangeAfter()
 **********************************************************************************************************************/
/*! \brief        Insert a node chain into another node chain.
 *  \param[in]    NodeSetPtr    Storage array of the elements of the node chain.
 *  \param[inout] FirstIdxPtr   Index of the first element of the node chain.
 *  \param[inout] LastIdxPtr    Index of the last element of the node chain.
 *  \param[in]    NewStartIdx   Index of the first element of the node chain that shall be inserted
 *  \param[in]    NewEndIdx     Index of the last element of the node chain that shall be inserted
 *  \param[in]    AfterIdx      Index of the pedecessor of the newly inserted node chain.
 *                              If AfterIdx is TCPIP_DLIST_END_IDX the chain will be inserted at the beginning.
 **********************************************************************************************************************/
STATIC FUNC(void, TCPIP_CODE) TcpIp_DListRawAddRangeAfter(
  TCPIP_P2V(TcpIp_DListNodeType) NodeSetPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  FirstIdxPtr,
  TCPIP_P2V(TcpIp_DListIdxType)  LastIdxPtr,
  TcpIp_DListIdxType            NewStartIdx,
  TcpIp_DListIdxType            NewEndIdx,
  TcpIp_DListIdxType            AfterIdx)
{
#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != NodeSetPtr,  TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != FirstIdxPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != LastIdxPtr,  TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);

  if (E_OK != TcpIp_VDbgDListCheckChain(NodeSetPtr, NewStartIdx, NewEndIdx, (TCPIP_P2V(uint8))NULL_PTR))
  {
    TcpIp_DetReportError(TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_PARAM);
    return;
  }
#endif

  NodeSetPtr[NewStartIdx].PrevIdx = AfterIdx;

  if (TCPIP_DLIST_END_IDX != AfterIdx)
  {
    /* insert after existing node */
    NodeSetPtr[NewEndIdx].NextIdx = NodeSetPtr[AfterIdx].NextIdx;
    NodeSetPtr[AfterIdx].NextIdx  = NewStartIdx;
  }
  else
  {
    /* insert as first node */
    NodeSetPtr[NewEndIdx].NextIdx = (*FirstIdxPtr);
    (*FirstIdxPtr) = NewStartIdx;
  }

  if (TCPIP_DLIST_END_IDX != NodeSetPtr[NewEndIdx].NextIdx)
  {
    /* new node is not last node */
    NodeSetPtr[NodeSetPtr[NewEndIdx].NextIdx].PrevIdx = NewEndIdx;
  }
  else
  {
    /* new node is last node */
    (*LastIdxPtr) = NewEndIdx;
  }

} /* End of TcpIp_DListRawAddRangeAfter() */  /* PRQA S 6060 */ /* MD_TCPIP_TCP_STPAR_6060 */

/**********************************************************************************************************************
 *  TcpIp_DListRawRemove()
 **********************************************************************************************************************/
/*! \brief      Removes a node from a node chain.
 *  \param[in]  NodeSetPtr    Storage array of the elements of the node chain.
 *  \param[in]  FirstIdxPtr   Index of the first element of the node chain.
 *  \param[in]  LastIdxPtr    Index of the last element of the node chain.
 *  \param[in]  RemIdx        Index of the element that shall be removed.
 **********************************************************************************************************************/
STATIC FUNC(void, TCPIP_CODE) TcpIp_DListRawRemove(
  TCPIP_P2V(TcpIp_DListNodeType)  NodeSetPtr,
  TCPIP_P2V(TcpIp_DListIdxType)   FirstIdxPtr,
  TCPIP_P2V(TcpIp_DListIdxType)   LastIdxPtr,
  TcpIp_DListIdxType             RemIdx)
{
#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != NodeSetPtr,               TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != FirstIdxPtr,              TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != LastIdxPtr,               TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(TCPIP_DLIST_END_IDX != (*FirstIdxPtr), TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(TCPIP_DLIST_END_IDX != (*LastIdxPtr),  TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(TCPIP_DLIST_END_IDX != RemIdx,         TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
#endif

  if (TCPIP_DLIST_END_IDX != NodeSetPtr[RemIdx].PrevIdx)
  {
    /* node is not first node */
    NodeSetPtr[NodeSetPtr[RemIdx].PrevIdx].NextIdx = NodeSetPtr[RemIdx].NextIdx;
  }
  else
  {
    /* remove first node */
    (*FirstIdxPtr) = NodeSetPtr[RemIdx].NextIdx;
  }

  if (TCPIP_DLIST_END_IDX != NodeSetPtr[RemIdx].NextIdx)
  {
    /* node is not last node */
    NodeSetPtr[NodeSetPtr[RemIdx].NextIdx].PrevIdx = NodeSetPtr[RemIdx].PrevIdx;
  }
  else
  {
    /* remove last node */
    (*LastIdxPtr) = NodeSetPtr[RemIdx].PrevIdx;
  }

  NodeSetPtr[RemIdx].PrevIdx = TCPIP_DLIST_END_IDX;
  NodeSetPtr[RemIdx].NextIdx = TCPIP_DLIST_END_IDX;

} /* End of TcpIp_DListRawRemove() */

/**********************************************************************************************************************
 *  TcpIp_DListRawRemoveRange()
 **********************************************************************************************************************/
/*! \brief        Removes a sub chain from a node chain.
 *  \param[in]    NodeSetPtr    Storage array of the elements of the node chain.
 *  \param[inout] FirstIdxPtr   Index of the first element of the node chain.
 *  \param[inout] LastIdxPtr    Index of the last element of the node chain.
 *  \param[in]    RemStartIdx   Index of the first element that shall be removed.
 *  \param[in]    RemEndIdx     Index of the last element that shall be removed.
 **********************************************************************************************************************/
STATIC FUNC(uint8, TCPIP_CODE) TcpIp_DListRawRemoveRange(
  TCPIP_P2V(TcpIp_DListNodeType)  NodeSetPtr,
  TCPIP_P2V(TcpIp_DListIdxType)   FirstIdxPtr,
  TCPIP_P2V(TcpIp_DListIdxType)   LastIdxPtr,
  TcpIp_DListIdxType             RemStartIdx,
  TcpIp_DListIdxType             RemEndIdx)
{
  TcpIp_DListIdxType Idx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
  uint8 ChainLength = 1;

#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnValue(NULL_PTR != NodeSetPtr,  TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER, 0);
  TcpIp_CheckDetErrorReturnValue(NULL_PTR != FirstIdxPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER, 0);
  TcpIp_CheckDetErrorReturnValue(NULL_PTR != LastIdxPtr,  TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER, 0);
#endif

#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  if (E_OK != TcpIp_VDbgDListCheckChain(NodeSetPtr, RemStartIdx, RemEndIdx, (TCPIP_P2V(uint8))NULL_PTR))
  {
    TcpIp_DetReportError(TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_PARAM);
    return 0;
  }
#endif

  /* count number of elements in chain */
  Idx = RemStartIdx;

  while (RemEndIdx != Idx)
  {
    ChainLength++;
    Idx = NodeSetPtr[Idx].NextIdx;
  }

  if (TCPIP_DLIST_END_IDX != NodeSetPtr[RemStartIdx].PrevIdx)
  {
    /* node is not first node */
    NodeSetPtr[NodeSetPtr[RemStartIdx].PrevIdx].NextIdx = NodeSetPtr[RemEndIdx].NextIdx;
  }
  else
  {
    /* remove first node */
    (*FirstIdxPtr) = NodeSetPtr[RemEndIdx].NextIdx;
  }

  if (TCPIP_DLIST_END_IDX != NodeSetPtr[RemEndIdx].NextIdx)
  {
    /* node is not last node */
    NodeSetPtr[NodeSetPtr[RemEndIdx].NextIdx].PrevIdx = NodeSetPtr[RemStartIdx].PrevIdx;
  }
  else
  {
    /* remove last node */
    (*LastIdxPtr) = NodeSetPtr[RemStartIdx].PrevIdx;
  }

  NodeSetPtr[RemStartIdx].PrevIdx = TCPIP_DLIST_END_IDX;
  NodeSetPtr[RemEndIdx].NextIdx   = TCPIP_DLIST_END_IDX;

  return ChainLength;
} /* End of TcpIp_DListRawRemoveRange() */

/**********************************************************************************************************************
 *  TcpIp_DListInitDesc()
 **********************************************************************************************************************/
/*! \brief        Initializes a Dlist descriptor. All nodes from the node storage array will be linked and inserted
 *                into the free list. This descriptor can be used by multiple DList instances. See TcpIp_DListInit().
 *  \param[in]    DescPtr       Descriptor to be initialized.
 *  \param[in]    NodePtr       Node storage array
 *  \param[in]    NodeCount     Number of nodes in node storage array
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListInitDesc(
  TCPIP_P2V(TcpIp_DListDescType) DescPtr,
  TCPIP_P2V(TcpIp_DListNodeType) NodePtr,
  uint8                        NodeCount)
{
  uint8 DataIdx = NodeCount;
  DescPtr->NodePtr = NodePtr;

#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != DescPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != NodePtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
#endif

  if (0 < NodeCount)
  {
    DescPtr->FirstFreeIdx = 0;
    DescPtr->LastFreeIdx  = (TcpIp_DListIdxType)(NodeCount - 1);

    while (0 < DataIdx)
    {
      DataIdx--;

      if (DescPtr->FirstFreeIdx < DataIdx)
      {
        NodePtr[DataIdx].PrevIdx = (TcpIp_DListIdxType)(DataIdx - 1);
      }
      else
      {
        NodePtr[DataIdx].PrevIdx = TCPIP_DLIST_END_IDX;
      }

      if (DescPtr->LastFreeIdx > DataIdx)
      {
        NodePtr[DataIdx].NextIdx = (TcpIp_DListIdxType)(DataIdx + 1);
      }
      else
      {
        NodePtr[DataIdx].NextIdx = TCPIP_DLIST_END_IDX;
      }
    }
  }
  else
  {
    DescPtr->FirstFreeIdx = TCPIP_DLIST_END_IDX;
    DescPtr->LastFreeIdx  = TCPIP_DLIST_END_IDX;
  }

  DescPtr->ElementCount = NodeCount;

} /* End of TcpIp_DListInitDesc() */

/**********************************************************************************************************************
 *  TcpIp_DListInit()
 **********************************************************************************************************************/
/*! \brief        Initializes a DList instance. After initialization the list is empty.
 *                New elements can be inserted by TcpIp_DListAddElement().
 *  \param[in]    ListPtr       DList instnace
 *  \param[in]    DescPtr       DList descriptor that will by used by this instnace.
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListInit(
  TCPIP_P2V(TcpIp_DListType)     ListPtr,
  TCPIP_P2V(TcpIp_DListDescType) DescPtr)
{
#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != ListPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != DescPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
#endif

  ListPtr->DescPtr      = DescPtr;
  ListPtr->FirstIdx     = TCPIP_DLIST_END_IDX;
  ListPtr->LastIdx      = TCPIP_DLIST_END_IDX;
  ListPtr->ElementCount = 0;

} /* End of TcpIp_DListInit() */

/**********************************************************************************************************************
 *  TcpIp_DListAddElement()
 **********************************************************************************************************************/
/*! \brief      Adds an element to a DList instnace by moving it from the free list.
 *  \param[in]  DListPtr   Handle to the list into that the new element should be inserted.
 *  \param[in]  AfterIdx   Index of a list item that shall be the predecessor of the new item.
 *                         If the index is TCPIP_DLIST_END_IDX the new item will be inserted at the beginning of the list.
 *  \param[out] NewIdxPtr  Index of the inserted item. Only valid if result is E_OK.
 *  \retval     E_OK       success
 *  \retval     E_NOT_OK   No elements in free list. (NewIdxPtr not modified)
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DListAddElement(
  TCPIP_P2V(TcpIp_DListType)    DListPtr,
  TcpIp_DListIdxType           AfterIdx,
  TCPIP_P2V(TcpIp_DListIdxType) NewIdxPtr)
{
  /* get first element from free list */
  TcpIp_DListIdxType NewIdx = DListPtr->DescPtr->FirstFreeIdx;

#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnValue(NULL_PTR != DListPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER, E_NOT_OK);
#endif

  if (TCPIP_DLIST_END_IDX == DListPtr->DescPtr->FirstFreeIdx)
  {
    /* no free elements */
#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
    TcpIp_DetReportError(TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_DLIST_BUFFER_EMPTY);
#endif
    return E_NOT_OK;
  }

  TcpIp_DListRawRemove(DListPtr->DescPtr->NodePtr, &DListPtr->DescPtr->FirstFreeIdx, &DListPtr->DescPtr->LastFreeIdx, NewIdx);
  DListPtr->DescPtr->ElementCount--;

  /* add new element to list */
  TcpIp_DListRawAddAfter(DListPtr->DescPtr->NodePtr, &DListPtr->FirstIdx, &DListPtr->LastIdx, NewIdx, AfterIdx);
  DListPtr->ElementCount++;

  (*NewIdxPtr) = NewIdx;

  return E_OK;
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of TcpIp_DListAddElement() */

/**********************************************************************************************************************
 *  TcpIp_DListRemoveElementRange()
 **********************************************************************************************************************/
/*! \brief      Removes a chain of linked elements from the list and adds them to the free list of the descriptor.
 *  \param[in]  DListPtr    Handle to the DList instnace containing the elements to be removed.
 *  \param[in]  RemStartIdx Index of the first item of the element chain that shall be removed.
 *  \param[in]  RemEndIdx   Index of the lest item of the element chain that shall be removed.
 *  \note       RemStartIdx and RemEndIdx may be equal but for performance reasons TcpIp_DListRemoveElement() should be
 *              used for removing single elements.
 *  \warning    For performance reasons this function does not check if the elements to be removed are correctly linked
 *              when TCPIP_VENABLE_INTERNAL_DET_CHECKS are not enabled!
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListRemoveElementRange(
  TCPIP_P2V(TcpIp_DListType) DListPtr,
  TcpIp_DListIdxType        RemStartIdx,
  TcpIp_DListIdxType        RemEndIdx)
{
  uint8 ChainCount;

#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != DListPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
#endif

  /* remove element from list */
  ChainCount = TcpIp_DListRawRemoveRange(DListPtr->DescPtr->NodePtr, &DListPtr->FirstIdx, &DListPtr->LastIdx, RemStartIdx, RemEndIdx);
  DListPtr->ElementCount -= ChainCount;

  /* add removed element to beginning of free list */
  TcpIp_DListRawAddRangeAfter(DListPtr->DescPtr->NodePtr, &DListPtr->DescPtr->FirstFreeIdx, &DListPtr->DescPtr->LastFreeIdx, RemStartIdx, RemEndIdx, DListPtr->DescPtr->FirstFreeIdx);
  DListPtr->DescPtr->ElementCount += ChainCount;

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of TcpIp_DListRemoveElementRange() */

/**********************************************************************************************************************
 *  TcpIp_DListRemoveElement()
 **********************************************************************************************************************/
/*! \brief      Removes a single element from a DList instance and adds it to the free list of the descriptor
 *  \param[in]  DListPtr  Handle to the DList instnace containing the element to be removed.
 *  \param[in]  RemIdx    Index of the element that shall be removed.
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListRemoveElement(
  TCPIP_P2V(TcpIp_DListType) DListPtr,
  TcpIp_DListIdxType        RemIdx)
{
#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != DListPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
#endif

  /* remove element from list */
  TcpIp_DListRawRemove(DListPtr->DescPtr->NodePtr, &DListPtr->FirstIdx, &DListPtr->LastIdx, RemIdx);
  DListPtr->ElementCount--;

  /* add removed element to beginning of free list */
  TcpIp_DListRawAddAfter(DListPtr->DescPtr->NodePtr, &DListPtr->DescPtr->FirstFreeIdx, &DListPtr->DescPtr->LastFreeIdx, RemIdx, DListPtr->DescPtr->FirstFreeIdx);
  DListPtr->DescPtr->ElementCount++;

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of TcpIp_DListRemoveElement() */

/**********************************************************************************************************************
 *  TcpIp_DListMoveElement()
 **********************************************************************************************************************/
/*! \brief      Moves a single element from a DList instance into another DList instance.
 *  \note       Both DList instances MUST have been initialized with the same DList descriptor.
 *  \param[in]  SrcListPtr Handle to the DList instance containing the element to be moved.
 *  \param[in]  SrcListIdx Index of the element that shall be moved.
 *  \param[in]  TgtListPtr Handle to the DList instance to which the element shall be added.
 *  \param[in]  TgtPrevIdx Index of the new predecessor of the moved element in the target list.
 *                         If AfterIdx is TCPIP_DLIST_END_IDX the new item will be inserted at the beginning.
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListMoveElement(
  TCPIP_P2V(TcpIp_DListType) SrcListPtr,
  TcpIp_DListIdxType        SrcListIdx,
  TCPIP_P2V(TcpIp_DListType) TgtListPtr,
  TcpIp_DListIdxType        TgtPrevIdx)
{
#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != SrcListPtr,                     TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != TgtListPtr,                     TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(TCPIP_DLIST_END_IDX != SrcListIdx,           TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(SrcListPtr->DescPtr == TgtListPtr->DescPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_PARAM);
#endif

  /* remove element from source list */
  TcpIp_DListRawRemove(SrcListPtr->DescPtr->NodePtr, &SrcListPtr->FirstIdx, &SrcListPtr->LastIdx, SrcListIdx);
  SrcListPtr->ElementCount--;

  /* add removed element to beginning of free list */
  TcpIp_DListRawAddAfter(TgtListPtr->DescPtr->NodePtr, &TgtListPtr->FirstIdx, &TgtListPtr->LastIdx, SrcListIdx, TgtPrevIdx);
  TgtListPtr->ElementCount++;

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of TcpIp_DListMoveElement() */

/**********************************************************************************************************************
 *  TcpIp_DListMoveElementRange()
 **********************************************************************************************************************/
/*! \brief      Moves an element chain from one DList instance into another DList instance
 *  \note       Both DList instances MUST have been initialized with the same DList descriptor.
 *  \param[in]  SrcListPtr      Handle to the DList instance containing the element chain to be moved.
 *  \param[in]  SrcListStartIdx Index of the first element that shall be moved.
 *  \param[in]  SrcListEndIdx   Index of the last element that shall be moved.
 *  \param[in]  TgtListPtr      Handle to the DList instance to which the element chain shall be added.
 *  \param[in]  TgtPrevIdx      Index of the new predecessor of the moved element chain in the target list.
 *                              If AfterIdx is TCPIP_DLIST_END_IDX the chain will be inserted at the beginning.
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListMoveElementRange(
  TCPIP_P2V(TcpIp_DListType) SrcListPtr,
  TcpIp_DListIdxType        SrcListStartIdx,
  TcpIp_DListIdxType        SrcListEndIdx,
  TCPIP_P2V(TcpIp_DListType) TgtListPtr,
  TcpIp_DListIdxType        TgtPrevIdx)
{
  uint8 ChainCount;

#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != SrcListPtr,                     TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != TgtListPtr,                     TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(TCPIP_DLIST_END_IDX != SrcListStartIdx,      TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(TCPIP_DLIST_END_IDX != SrcListEndIdx,        TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(SrcListPtr->DescPtr == TgtListPtr->DescPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_PARAM);
#endif

  /* remove element from source list */
  ChainCount = TcpIp_DListRawRemoveRange(SrcListPtr->DescPtr->NodePtr, &SrcListPtr->FirstIdx, &SrcListPtr->LastIdx, SrcListStartIdx, SrcListEndIdx);
  SrcListPtr->ElementCount -= ChainCount;

  /* add removed element to beginning of free list */
  TcpIp_DListRawAddRangeAfter(             TgtListPtr->DescPtr->NodePtr, &TgtListPtr->FirstIdx, &TgtListPtr->LastIdx, SrcListStartIdx, SrcListEndIdx, TgtPrevIdx);
  TgtListPtr->ElementCount += ChainCount;

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of TcpIp_DListMoveElementRange() */

/**********************************************************************************************************************
 *  TcpIp_DListClear()
 **********************************************************************************************************************/
/*! \brief      Clears a DList instance by moving all elements to the free list of the descriptor.
 *  \param[in]  DListPtr  Handle to the DList instance
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListClear(
  TCPIP_P2V(TcpIp_DListType) DListPtr)
{
#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != DListPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
#endif

  if (!TCPIP_DLIST_IS_EMPTY(*DListPtr))
  {
    TcpIp_DListRemoveElementRange(DListPtr, DListPtr->FirstIdx, DListPtr->LastIdx);
  }

} /* End of TcpIp_DListClear() */

/**********************************************************************************************************************
 *  TcpIp_DListSwap()
 **********************************************************************************************************************/
/*! \brief      Swaps the content of two DList instances.
 *  \note       Both DList instances MUST have been initialized with the same DList descriptor.
 *  \param[in]  ListAPtr Handle to DList instance
 *  \param[in]  ListBPtr Handle to DList instance
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListSwap(
  TCPIP_P2V(TcpIp_DListType) ListAPtr,
  TCPIP_P2V(TcpIp_DListType) ListBPtr)
{
  TcpIp_DListIdxType TmpFirstIdx, TmpLastIdx;
  uint8 TmpCount;

#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != ListAPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
  TcpIp_CheckDetErrorReturnVoid(NULL_PTR != ListBPtr, TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_POINTER);
#endif

  if (ListAPtr->DescPtr != ListBPtr->DescPtr)
  {
    /* swapping lists is only allowd for lists with same descriptor */
#if (TCPIP_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
    TcpIp_DetReportError(TCPIP_API_ID_V_INTERNAL_FUNCTION, TCPIP_E_INV_PARAM);
#endif
    return;
  }

  TmpFirstIdx = ListAPtr->FirstIdx;
  TmpLastIdx  = ListAPtr->LastIdx;
  TmpCount    = ListAPtr->ElementCount;

  ListAPtr->FirstIdx     = ListBPtr->FirstIdx;
  ListAPtr->LastIdx      = ListBPtr->LastIdx;
  ListAPtr->ElementCount = ListBPtr->ElementCount;

  ListBPtr->FirstIdx     = TmpFirstIdx;
  ListBPtr->LastIdx      = TmpLastIdx;
  ListBPtr->ElementCount = TmpCount;

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of TcpIp_DListSwap() */

#endif

#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* module specific MISRA deviations:

   module global deviations -> see file TcpIp.c

   TCPIP_PRIV-specific deviations:
   (none)
*/

/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Priv.c
 *********************************************************************************************************************/
