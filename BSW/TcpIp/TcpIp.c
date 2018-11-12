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
 *         \file  TcpIp.c
 *        \brief  Implementation of TcpIp Module
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

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

#define TCPIP_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp.h"
#include "TcpIp_Cbk.h"
#include "TcpIp_Priv.h"
#include "TcpIp_Lcfg.h"

#include "IpBase.h"

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
#include "TcpIp_IpV4.h"
#include "TcpIp_IpV4_Cbk.h"   /* needed to forward the RxIndication */
#include "TcpIp_Arp.h"
#include "TcpIp_Arp_Cbk.h"  /* needed to forward the RxIndication */
#endif

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
#include "TcpIp_IpV6.h"
#include "TcpIp_IpV6_Cbk.h"      /* needed to forward the RxIndication */
#endif

#include "TcpIp_Udp.h"

#if (TCPIP_SUPPORT_TCP == STD_ON)
# include "TcpIp_Tcp.h"
#endif

#if (TCPIP_SUPPORT_DHCPV4 == STD_ON)
# include "TcpIp_DhcpV4.h"
#endif

#if (TCPIP_SUPPORT_DHCPV6 == STD_ON)
# include "TcpIp_DhcpV6.h"
#endif

#if (TCPIP_DHCPV4SERVER_ENABLED == STD_ON)
# include "TcpIp_DhcpV4Server.h"
#endif

#if (TCPIP_SUPPORT_TLS == STD_ON)
#include "Tls.h"
#include "Tls_Cbk.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of TcpIp.h file */
#if (  (TCPIP_SW_MAJOR_VERSION != 5u) \
    || (TCPIP_SW_MINOR_VERSION != 0u) \
    || (TCPIP_SW_PATCH_VERSION != 1u) )
  #error "TcpIp.c: Source and Header file are inconsistent!"
#endif

/* Check configuration variant for building the library */
#if ( (defined V_EXTENDED_BUILD_LIB_CHECK) && (TCPIP_CONFIGURATION_VARIANT_PRECOMPILE == TCPIP_CONFIGURATION_VARIANT) )
  #error "TcpIp.c: Switch configuration variant to link-time or post-build for library build!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#define TCPIP_USE_RANDOM_LOCAL_PORTS    STD_ON

#if !defined (TCPIP_LOCAL)
# define TCPIP_LOCAL static
#endif

#if !defined (TCPIP_LOCAL_INLINE)
# define TCPIP_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/* ----- */
#define TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(TcpIp_TcpIpErrorType, TCPIP_VAR_NOINIT) TcpIp_LastSockError;

#define TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ----- */
#define TCPIP_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(TcpIp_StateType, TCPIP_VAR_ZERO_INIT) TcpIp_State = TCPIP_STATE_UNINIT;

#define TCPIP_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  TcpIp_VSocketAccessExclusive
 **********************************************************************************************************************/
/*! \brief      Checks if another TX request is currently processed on a socket.
 *              If not, the socket will be locked for other TX requests.
 *  \param[in]  socketId              Socket identifier.
 *  \return     TRUE                  Socket has been locked and can be used for transmit.
 *  \return     FALSE                 Socket is already locked and must not be used for transmit.
 *  \context    task level
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(boolean, TCPIP_CODE) TcpIp_VSocketAccessExclusive(TcpIp_SocketIdType socketId);

/***********************************************************************************************************************
 *  TcpIp_UdpTransmitInternal
 **********************************************************************************************************************/
/*! \brief      AUTOSAR Transmission Request
 *  \param[in]  sockIdx               Index of the UDP socket.
 *  \param[in]  dataPtr               Pointer to data or NULL_PTR if CopyTxData shall be called.
 *  \param[in]  remoteSockAddrPtr     Remote socket address.
 *  \param[in]  TotalLength           Total length of data to transmit.
 *  \return     TCPIP_OK              Data transmitted.
 *  \return     TCPIP_E_NOT_OK        Data could not be transmitted.
 *  \context    task level
 **********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_UdpTransmitInternal(
  TcpIp_SockIdxType             sockIdx,
  TCPIP_P2C(uint8)              dataPtr,            /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
  TCPIP_P2C(TcpIp_SockAddrType) remoteSockAddrPtr,  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
  uint16                        TotalLength);

#if (TCPIP_SINGLE_MAIN_FUNCTION_ENABLED == STD_ON)
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_MainFunctionRx(void);
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_MainFunctionState(void);
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_MainFunctionTx(void);
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  TcpIp_InitMemory
 **********************************************************************************************************************/
/*! \brief         Initialize the TcpIp-internal global module state variable.
 *  \param[in]     void             none
 *  \return        void
 *  \context       initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_InitMemory(void)
{
  TcpIp_State = TCPIP_STATE_UNINIT;

#if (TCPIP_DHCPV4SERVER_ENABLED == STD_ON)
  TcpIp_DhcpV4Server_InitMemory();
#endif

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
  IpV4_InitMemory();
#endif

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  IpV6_InitMemory();
#endif
}

/***********************************************************************************************************************
 *  TcpIp_Init
 **********************************************************************************************************************/
/*! \brief         Initialize the TcpIp module.
 *  \description   <br>Calls all TcpIp internal init functions and sets state to 'initialized'.
 *  \param[in]     ConfigPtr        pointer to module configuration
 *  \return        void
 *  \note          No configuration variant support implemented, so only TCPIP_CONFIG_VARIANT_1 (compile time) is available.
 *  \context       initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Init(
    P2CONST(TcpIp_ConfigType, TCPIP_PBCFG, TCPIP_CONST) ConfigPtr )  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
{
  TcpIp_ActiveState = TCPIP_ACTIVE_STATE_ONLINE;

  TCPIP_UNUSED_PARAMETER(ConfigPtr);  /* PRQA S 3112 */ /* MD_MSR_14.2 */

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
  IpV4_Init(NULL_PTR);
#endif

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  IpV6_Init(NULL_PTR);
#endif

#if (TCPIP_SUPPORT_TCP == STD_ON)
  TcpIp_Tcp_Init();
#endif
  TcpIp_Udp_Init();

/* ----- */

  TcpIp_VInitSockets();

  {
    /* init/reset IP address assignment state */
    uint8 IpAddrId;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
    for(IpAddrId = 0; IpAddrId < TCPIP_MAX_NUM_IP_ADDR_IDS; IpAddrId++)
    {
      TcpIp_IpAddrAssignmentState[IpAddrId] = TCPIP_IPADDR_STATE_UNASSIGNED;
    }
  }

/* ----- */

#if (TCPIP_SUPPORT_DHCPV4 == STD_ON)
  TcpIp_DhcpV4_Init();
#endif  /* TCPIP_SUPPORT_DHCPV4 == STD_ON */

#if (TCPIP_SUPPORT_DHCPV6 == STD_ON)
  TcpIp_DhcpV6_Init(NULL_PTR);
#endif  /* TCPIP_SUPPORT_DHCPV6 == STD_ON */

#if (TCPIP_DHCPV4SERVER_ENABLED == STD_ON)
  TcpIp_DhcpV4Server_Init(NULL_PTR);
#endif

  TcpIp_State = TCPIP_STATE_INIT;
}

/***********************************************************************************************************************
 *  TcpIp_Shutdown
 **********************************************************************************************************************/
/*! \brief         Shutdown the module TcpIp.
 *  \param[in]     void             none
 *  \return        void
 *  \context       task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Shutdown( void )
{
  TcpIp_ActiveState = TCPIP_ACTIVE_STATE_OFFLINE;
}

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
    uint16 LenByte )
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT, TCPIP_API_ID_RXINDICATION, TCPIP_E_NOTINIT )
  /* ------------------------------------------------- */

  switch(FrameType)
  {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
  case TCPIP_ETH_FRAME_TYPE_IPV4:
    {
      /* call IPv4 RxIndication */
      IpV4_Ip_RxIndication(CtrlIdx, FrameType, IsBroadcast, PhysAddrPtr, DataPtr, LenByte);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_x */
      break;
    }
  case TCPIP_ETH_FRAME_TYPE_ARP:
    {
      /* call ARP RxIndication */
      IpV4_Arp_RxIndication(CtrlIdx, FrameType, IsBroadcast, PhysAddrPtr, DataPtr, LenByte);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_x */
      break;
    }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  case TCPIP_ETH_FRAME_TYPE_IPV6:
    {
      /* call IPv6 RxIndication */
      IpV6_RxIndication(CtrlIdx, FrameType, IsBroadcast, PhysAddrPtr, DataPtr, LenByte);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_x */
      break;
    }
#endif
  default:
    /* error, this may not happen -> ignore this message */
    break;
  }
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6060 */ /* MD_TCPIP_TCP_STPAR_6060 */

/***********************************************************************************************************************
 *  TcpIp_GetSocketForUser
 **********************************************************************************************************************/
/*! \brief      Request a socket (TCP or UDP).
 *  \description   By this API service the TCP/IP stack is requested to allocate a new socket.
 *  \param[in]  Domain             IP address family (IPv4 or IPv6)
 *  \param[in]  Protocol           Socket protocol as sub-family of parameter type (TCP or UDP)
 *  \param[out  SocketIdPtr        Pointer to socket identifier representing the requested socket.
 *                                 This socket identifier must be provided for all further API calls which requires a SocketId.
 *  \param[in]  UserIndex          Identifier for the socket user (e.g. TLS or HTTP)
 *  \return     E_OK               The request has been accepted <br>
 *              E_NOT_OK           The request has not been accepted: no free socket
 *  \note       SocketIdPtr is only valid if return value is E_OK. <br>
 *              Each accepted incoming TCP connection also allocates a socket resource. <br>
 *              Server sockets are special because they do not need any rx and tx buffer and a lot less socket description parameters.
 *  \context    task level
 **********************************************************************************************************************/
Std_ReturnType TcpIp_GetSocketForUser(
    TcpIp_DomainType Domain,
    TcpIp_ProtocolType Protocol,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, TCPIP_APPL_DATA) SocketIdPtr,
    uint8 UserIndex )
{
  /* The parameter 'Domain' can be ignored since our sockets always support both IP versions. */

  TcpIp_SocketIdType SocketId;
  TcpIp_SocketIdType MinSockId;
  TcpIp_SocketIdType MaxSockId;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                   TCPIP_API_ID_GET_SOCKET, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_DOMAIN(Domain),   TCPIP_API_ID_GET_SOCKET, TCPIP_E_AFNOSUPPORT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PROT(Protocol),   TCPIP_API_ID_GET_SOCKET, TCPIP_E_INV_ARG, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(SocketIdPtr), TCPIP_API_ID_GET_SOCKET, TCPIP_E_PARAM_POINTER, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( (TCPIP_UNDEFINED_SOCK_OWNER_IDX > UserIndex),  TCPIP_API_ID_GET_SOCKET, TCPIP_E_INV_ARG, E_NOT_OK )
  /* ------------------------------------------------- */

  /* find a free / the matching socket */
  if(TCPIP_IPPROTO_UDP == Protocol)
  {
    /* UDP */
    MinSockId = 0;
    MaxSockId = TcpIp_VCfgGetMaxNumUdpSocks();
  }
#if (TCPIP_SUPPORT_TCP == STD_ON)
  else if(TCPIP_IPPROTO_TCP == Protocol)  /* PRQA S 3355, 3358 */ /* MD_TCPIP_13.7_3355_3358 */
  {
    /* TCP */
    MinSockId = TcpIp_VCfgGetMaxNumUdpSocks();
    MaxSockId = TcpIp_VCfgGetMaxNumSocks();
  }
#endif  /* (TCPIP_SUPPORT_TCP == STD_ON) */
  else
  {  /* PRQA S 3201 */ /* MS_MSR_14.1 */
    /* protocol not supported */
    return E_NOT_OK;
  }

  /* go through all sockets for the specified protocol, looking for a free socket */
  for(SocketId = MinSockId; SocketId < MaxSockId; SocketId++)
  {
    if(TcpIp_SockUserIdx[SocketId] == TCPIP_UNDEFINED_SOCK_OWNER_IDX)
    {
      /* free socket found */
      break;  /* leave the for-loop, SocketId contains the index of the free socket */
    }
  }
  if(SocketId == MaxSockId)
  {
    /* no free socket found */
    return E_NOT_OK;
  }

  /* allocate the socket for this user */
  TcpIp_VPreconfigSocket(SocketId);
  TcpIp_SockListenActive[SocketId].ConnStat = TCPIP_SOCK_CONN_ALLOCATED;

  ((IpBase_SockAddrType*)(&TcpIp_SocketList[SocketId].LocSock))->sa_family = Domain;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */

#if (TCPIP_SUPPORT_TCP == STD_ON)
  if(TCPIP_IPPROTO_TCP == Protocol)
  {
    TcpIp_Tcp_InitSock(SocketId);
  }
#endif

  *SocketIdPtr = SocketId;
  TcpIp_SockUserIdx[SocketId] = UserIndex;

  return E_OK;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */

#if (TCPIP_SUPPORT_TCP == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_TcpListen
 **********************************************************************************************************************/
/*! \brief      Set TCP socket into listen mode. <br>
 *  \description  By this API service the TCP/IP stack is requested to listen on the TCP socket specified by the socket identifier.
 *  \param[in]  SocketId            Socket identifier of the related local socket resource.
 *  \param[in]  MaxChannels         Maximum number of new parallel connections established on this listen connection.
 *  \return     E_OK               The request has been accepted <br>
 *              E_NOT_OK           The request has not been accepted
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpListen(
    TcpIp_SocketIdType SocketId,
    uint16 MaxChannels )
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_TCP_LISTEN, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_TCPSOCKIDX(SocketId), TCPIP_API_ID_TCP_LISTEN, TCPIP_E_INV_ARG, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( (MaxChannels < TcpIp_VCfgGetMaxNumTcpSocks()), TCPIP_API_ID_TCP_LISTEN, TCPIP_E_INV_ARG, E_NOT_OK )
  /* ------------------------------------------------- */

  if(TCPIP_SOCK_CONN_LISTEN_ENABLED == TcpIp_SockListenActive[SocketId].ConnStat)
  {
    /* socket already is in listen state */

    /* maybe MaxChannels has changed */
    if(MaxChannels != TcpIp_SocketList[SocketId].TcpMaxNumListenSockets)
    {
      if(MaxChannels < TcpIp_SocketList[SocketId].TcpMaxNumListenSockets)
      {
        /* check if more than MaxChannels sockets are derived from the current socket */
        TcpIp_SocketIdType SockCnt = 0;
        TcpIp_SocketIdType LocSockId;
        for(LocSockId = TcpIp_VCfgGetMaxNumUdpSocks(); LocSockId < TcpIp_VCfgGetMaxNumSocks(); LocSockId++)
        {
          if(TcpIp_SocketList[LocSockId].TcpMasterListenSockId == SocketId)
          {
            SockCnt++;
          }
        }
        if(MaxChannels < SockCnt)
        {
          /* error */
          return E_NOT_OK;
        }
        else
        {
          /* set limit to new value */
          TcpIp_SocketList[SocketId].TcpMaxNumListenSockets = MaxChannels;
          return E_OK;
        }
      }
      else
      {
        /* MaxChannels is bigger than the currently configured value */
        /* set limit to new value */
        TcpIp_SocketList[SocketId].TcpMaxNumListenSockets = MaxChannels;
        return E_OK;
      }
    }
    else
    {
      return E_OK;  /* nothing to be done */
    }
  }

  if(TCPIP_SOCK_CONN_ALLOCATED != TcpIp_SockListenActive[SocketId].ConnStat)
  {
    /* socket is in wrong state */
    return E_NOT_OK;
  }

  {
    /* TCP */
    /* TCP passive open: */
    TcpIp_TcpIdxType      TcpIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
    TcpIp_SockAddrInXType SockAddrRem;  /* remote socket */

    /* set remote address to undefined */
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
    (void)IpBase_DelSockAddr( ((IpBase_SockAddrType *)&SockAddrRem), IPBASE_AF_INET6 );  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
#else
    (void)IpBase_DelSockAddr( ((IpBase_SockAddrType *)&SockAddrRem), IPBASE_AF_INET );  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
#endif

    /* open the TCP socket */
    TcpIdx = TcpIp_Tcp_Open(SocketId, (IpBase_SockAddrType*)&SockAddrRem, TCPIP_TCP_PASSIVE_OPEN);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
    if(TCPIP_TCP_INV_IDX != TcpIdx)
    {
      TcpIp_SockListenActive[SocketId].ConnStat = TCPIP_SOCK_CONN_LISTEN_ENABLED;
      TcpIp_SocketList[SocketId].IsTcpListenSocket = TRUE;
      TcpIp_SocketList[SocketId].TcpMaxNumListenSockets = MaxChannels;  /* set limit */
    }
    else
    {
      /* open failed */
      return E_NOT_OK;
    }
  }

  return E_OK;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

/***********************************************************************************************************************
 *  TcpIp_TcpConnect
 **********************************************************************************************************************/
/*! \brief      By this API service the TCP/IP stack is requested to establish a TCP connection to the configured peer.
 *  \param[in]  SocketId           Socket identifier of the related local socket resource
 *  \param[in]  RemoteAddrPtr      IP address and port of the remote host to connect to
 *  \return     E_OK               Connect could be triggered <br>
 *              E_NOT_OK           Connect could be triggered
 *  \context    task level
 **********************************************************************************************************************/
#if (TCPIP_SUPPORT_TCP == STD_ON)
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpConnect(
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RemoteAddrPtr )
{
  Std_ReturnType    RetValue = E_NOT_OK;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_TCP_CONNECT, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_TCPSOCKIDX(SocketId), TCPIP_API_ID_TCP_CONNECT, TCPIP_E_INV_ARG, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(RemoteAddrPtr), TCPIP_API_ID_TCP_CONNECT, TCPIP_E_INV_ARG, E_NOT_OK )
  /* ------------------------------------------------- */

  if(TRUE != TcpIp_VNetAddrIsUnicast((const IpBase_SockAddrType*)RemoteAddrPtr))  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  {
    TcpIp_CallDetReportError( TCPIP_API_ID_TCP_CONNECT, TCPIP_E_INV_ARG )
    return E_NOT_OK;
  }

  /* check that socket is bound */
  if(TCPIP_SOCK_CONN_ALLOCATED == TcpIp_SockListenActive[SocketId].ConnStat)
  {
    /* connect socket: */

#if (TCPIP_USE_RANDOM_LOCAL_PORTS == STD_ON)  /* static enabled */
    if(0 == ((IpBase_SockAddrInType *)(&TcpIp_SocketList[SocketId].LocSock))->sin_port)  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
    {
      uint16 Rand = 0;
      uint8 LocalSocketId;
      uint8 SocketIdMin = TcpIp_VCfgGetMaxNumUdpSocks();
      uint8 SocketIdMax = TcpIp_VCfgGetMaxNumSocks() -1;

      while(Rand == 0)
      {
        Rand = TcpIp_GetRandNoFct();
        if(IPBASE_HTON16(Rand) == ((IpBase_SockAddrInType *)(&TcpIp_SocketList[SocketId].LocSock))->sin_port)  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
        {
          Rand += 1;
        }
        if(Rand < 0xC000u)
        {
          /* Use the dynamic port range defined by IANA. Min value is 0xC000, max 0xFFFF. */
          Rand |= (uint16)0xC000u;
        }
        ((IpBase_SockAddrInType *)(&TcpIp_SocketList[SocketId].LocSock))->sin_port = IPBASE_HTON16(Rand);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */

        /* check that the new port number is not used on any other TCP socket */
        for(LocalSocketId = SocketIdMin; LocalSocketId <= SocketIdMax; LocalSocketId++)
        {
          /* check if port of the socket is the same as current new random value or is '0' */
          if( (LocalSocketId != SocketId) &&  (((TcpIp_SockAddrInetType*)(&TcpIp_SocketList[LocalSocketId].LocSock))->port == Rand) )  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
          {
            /* error, a socket with the same local port already exists */
            Rand = 0;  /* set to invalid value */
            break;
          }
        }
      }
    }
#endif

    if( TCPIP_TCP_INV_IDX != TcpIp_Tcp_Open(SocketId, (const IpBase_SockAddrType *)RemoteAddrPtr, TCPIP_TCP_ACTIVE_OPEN))  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
    {
      TcpIp_SockListenActive[SocketId].ConnStat = TCPIP_SOCK_CONN_CONNECTED;
      RetValue = E_OK;
    }
  }

  return RetValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (TCPIP_SUPPORT_TCP == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_TcpTransmit
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpTransmit(
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr,  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
    uint32 AvailableLength,
    boolean ForceRetrieve )  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = TCPIP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check component initialization state and input parameters. */
  /* Check initialization state of the component */
  if (TcpIp_State == TCPIP_STATE_UNINIT)
  {
    errorId = TCPIP_E_NOTINIT;
  }
  /* Check parameter 'SocketId' */
  else if (TCPIP_COND_VALID_TCPSOCKIDX(SocketId) == FALSE)
  {
    errorId = TCPIP_E_INV_ARG;
  }
  /* Check parameter 'AvailableLength' */
  else if (AvailableLength > 0xFFFFu)
  {
    /* This implementation is limited to 64k per transmit. */
    errorId = TCPIP_E_INV_ARG;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    BufReq_ReturnType  bufReqRetVal;
    IpBase_PbufType   *pbufPtr;

    TCPIP_UNUSED_PARAMETER(ForceRetrieve);  /* PRQA S 3112 */ /* MD_MSR_14.2 */

    /* This implementation only accepts a transmit request if the whole data indicated by 'AvailableLength' can be stored into the TCP tx buffer. 
     * Therefore the value of 'ForceRetrieve' == FALSE is ignored.
     */

    /* #20 Try to obtain buffer segment from TCP TX ring-buffer. */
    bufReqRetVal = TcpIp_ProvideTxBuffer(SocketId, (P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA))NULL_PTR, &pbufPtr, AvailableLength);

    if (bufReqRetVal == BUFREQ_OK)
    {
      /* TCP TxBuffer is available. */
      /* #30 If indirect data Provision is used (DataPtr == NULL_PTR). */
      if (NULL_PTR == DataPtr)
      {
        uint16 copyTxDataLen = pbufPtr->len;

        /* #40 Call <Up>_CopyTxData() of upper-layer. */
        bufReqRetVal = TcpIp_CopyTxDataFunctions(TcpIp_SockUserIdx[SocketId], SocketId, pbufPtr->payload, &copyTxDataLen);

        if (bufReqRetVal == BUFREQ_OK)
        {
          if (copyTxDataLen < pbufPtr->len)
          {
            /* Upper layer provided less data than requested. */
            pbufPtr->len    = copyTxDataLen;
            pbufPtr->totLen = copyTxDataLen;
          }
          else if (pbufPtr->len < pbufPtr->totLen)
          {
            /* Another chuck of data is required due to a buffer wrap around in the TCP ring buffer. */
            copyTxDataLen = pbufPtr[1].len;
            /* #50 Call <Up>_CopyTxData() of upper-layer again for second TCP buffer segment, if wrap-around in TCP ring-buffer occurred. */
            /* assumption: TCP uses a ring buffer and therefore a maximum of two buffer fragments can occurr in the PBuf. Otherwise a loop would be needed here. */
            bufReqRetVal = TcpIp_CopyTxDataFunctions(TcpIp_SockUserIdx[SocketId], SocketId, (&pbufPtr[1])->payload, &copyTxDataLen);

            if ((bufReqRetVal == BUFREQ_OK) && (copyTxDataLen < pbufPtr[1].len))
            {
              /* Upper layer provided less data than requested. */
              pbufPtr[1].len  = copyTxDataLen;
              pbufPtr->totLen = pbufPtr->len + copyTxDataLen;
            }
          }
          else
          {
            /* User provided expected length of data. */
          }
        }
      }
      else
      {
        /* copy data to the buffer */
        /* data is already provided in this function call, so send in the same way as in ASR 4.0.x */
        /* copy */
        (void)IpBase_CopyString2PbufAt(DataPtr, (uint16)AvailableLength, pbufPtr, 0);
      }

      /* #60 Trigger transmission of data or free TX buffer if an error occured. */
      if (bufReqRetVal == BUFREQ_OK)
      {
        retVal = TcpIp_TransmitTo(SocketId, pbufPtr, NULL_PTR);  /* destination is ignored since it is already set during connection setup */
      }
      else
      {
        /* CopyTxData returned negative result. Cancel transmit. */
        pbufPtr->totLen = 0;
        (void)TcpIp_TransmitTo(SocketId, pbufPtr, NULL_PTR);  /* destination is ignored since it is already set during connection setup */
        /* Do not change retVal. Return E_NOT_OK. */
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
  /* #70 Report errors to Det. */
#if (TCPIP_DEV_ERROR_REPORT == STD_ON)
  if (errorId != TCPIP_E_NO_ERROR)
  {
    (void)Det_ReportError(TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, TCPIP_API_ID_REL_IP_ADDR_ASSIGN, errorId);
  }
#else
  TCPIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif  /* (TCPIP_SUPPORT_TCP == STD_ON) */ 

/***********************************************************************************************************************
 *  TcpIp_UdpTransmit
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_UdpTransmit(
    TcpIp_SocketIdType                                    SocketId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA)              DataPtr,        /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RemoteAddrPtr,  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
    uint16                                                TotalLength )
{
  /* ----- Local Variables ---------------------------------------------- */
  TcpIp_ReturnType  retVal  = TCPIP_E_NOT_OK;
  TcpIp_SockIdxType sockIdx = TCPIP_SOCKHND2SOCKIDX(SocketId);  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
  uint8             errorId = TCPIP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check component initialization state and input parameters. */
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check component initialization state and input parameters. */
  /* Check initialization state of the component */
  if (TcpIp_State == TCPIP_STATE_UNINIT)
  {
    errorId = TCPIP_E_NOTINIT;
  }
  /* Check parameter 'SocketId' */
  else if (TCPIP_COND_VALID_UDPSOCKIDX(sockIdx) == FALSE)
  {
    /* Passed socket Id does not represent a UDP sockett. */
    errorId = TCPIP_E_INV_ARG;
  }
  /* Check parameter 'RemoteAddrPtr' */
  else if (RemoteAddrPtr == NULL_PTR)
  {
    /* RemoteAddrPtr not set. */
    errorId = TCPIP_E_PARAM_POINTER;
  }
  else if (TCPIP_COND_VALID_ADDR_FAM(RemoteAddrPtr) == FALSE)  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  {
    /* RemoteAddrPtr has invalid address family. */
    errorId = TCPIP_E_INV_ARG;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
    /* #20 Try to send queued UDP packets that are waiting for link layer address resolution. */
    (void)TcpIp_Udp_SendRetryQueueIfPossible(SocketId, RemoteAddrPtr);
#endif

    if (TcpIp_ActiveState != TCPIP_ACTIVE_STATE_ONLINE)
    {
      /* Reject Transmit because TcpIp module is OFFLINE. */
    }
    else if (TcpIp_SockListenActive[sockIdx].ConnStat == TCPIP_SOCK_CONN_NONE)
    {
      /* Reject Transmit because socket is not open. */
    }
    else
    {
      /* #30 Check if UDP socket is bound. If not, try to bind the socket to a dynamic port and specified remote address. */
      boolean socketIsBound;
      
      if (((TCPIP_P2C(IpBase_SockAddrInType))&TcpIp_SocketList[sockIdx].LocSock)->sin_port > 0)  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
      {
        socketIsBound = TRUE;
      }
      /* Socket is unbound. Implicit bind to dynamic port. \trace SPEC-50982 */
      else if (TcpIp_Bind(SocketId, TcpIp_SocketList[sockIdx].BindLocalAddrId, &(((TCPIP_P2V(IpBase_SockAddrInType))&TcpIp_SocketList[sockIdx].LocSock)->sin_port)) == E_OK)  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
      {
        socketIsBound = TRUE;
      }
      else
      {
        socketIsBound = FALSE;
      }

      if (socketIsBound == TRUE)
      {
        /* #40 Obtain semaphore for the socket. */
        if (TcpIp_VSocketAccessExclusive(sockIdx) == TRUE)
        {
          /* #50 Call UdpTransmitInternal function. */
          retVal = TcpIp_UdpTransmitInternal(sockIdx, DataPtr, RemoteAddrPtr, TotalLength);

          /* #60 Release semaphore for the socket. */
          TcpIp_TxBufRequested[sockIdx] = FALSE;
        }
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (TCPIP_DEV_ERROR_REPORT == STD_ON)
  if (errorId != TCPIP_E_NO_ERROR)
  {
    (void)Det_ReportError(TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, TCPIP_API_ID_UDP_TRANSMIT, errorId);
  }
#else
  TCPIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* TcpIp_UdpTransmit() */  /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STMIF, MD_MSR_STCAL, MD_MSR_STIMF */

/***********************************************************************************************************************
 *  TcpIp_UdpTransmitInternal
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
TCPIP_LOCAL FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_UdpTransmitInternal(
  TcpIp_SockIdxType             sockIdx,
  TCPIP_P2C(uint8)              dataPtr,            /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
  TCPIP_P2C(TcpIp_SockAddrType) remoteSockAddrPtr,  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
  uint16                        TotalLength)
{
  Std_ReturnType retVal = TCPIP_E_NOT_OK;

  /* #10 Request TX buffer for UDP packet from lower layer.
   *     Multiple buffer segments may be provided by the IP if fragmentation is required. */
  /* If TotalLength exceeds the payload that fits into one IP packet TcpIp_Udp_RequestTxBuffer() may only provide a buffer for the first payload fragment.
   * Additional buffers for the other payload fragments are obtained by TcpIp_Udp_RequestNextTxBufferFragment() later.
   */
  uint16            udpPayloadLen = TotalLength;
  BufReq_ReturnType udpBufReqRetVal;
  TCPIP_P2V(uint8)  udpPayloadPtr;

  udpBufReqRetVal = TcpIp_Udp_RequestTxBuffer(sockIdx, (TCPIP_P2C(IpBase_SockAddrType))remoteSockAddrPtr, &udpPayloadPtr, &udpPayloadLen);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */

  if (udpBufReqRetVal == BUFREQ_OK)
  {
    boolean copyDataSuccessful = TRUE;
    uint16  dataPos = 0;

    /* a buffer could be provided successfully */
    TcpIp_TxRequestedLen[sockIdx] = TotalLength;

    /* #20 Iterate over all provided UDP payload buffer fragments and copy upper layer data. */
    while (TotalLength > 0)
    {
      if (TotalLength < udpPayloadLen)
      {
        udpPayloadLen = TotalLength;
      }

      /* #30 Copy data from upper layer into TX buffer if data was provided. */
      if (NULL_PTR != dataPtr)
      {
        /* directly copy provided data from user into provided UDP buffer */
        IpBase_Copy((IpBase_CopyDataType*)udpPayloadPtr, (const IpBase_CopyDataType*)&dataPtr[dataPos], udpPayloadLen);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_copy */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
        dataPos += udpPayloadLen;
        TotalLength -= udpPayloadLen;
      }
      /* #40 ELSE: Trigger upper layer to copy TX data into buffer by calling CopyTxData. */
      else
      {
        uint16 udpTxDataLen = udpPayloadLen;

        /* call CopyTxData function of user */
        if (TcpIp_CopyTxDataFunctions(TcpIp_SockUserIdx[sockIdx], sockIdx, udpPayloadPtr, &udpTxDataLen) == BUFREQ_OK)
        {
          if (udpTxDataLen < udpPayloadLen)
          {
            /* Upper layer provided less data than requested. Adapt requested length and do not copy more data. */
            TcpIp_TxRequestedLen[sockIdx] -= (TotalLength - udpTxDataLen);
            TotalLength = 0;
          }
          else
          {
            TotalLength -= udpPayloadLen;
          }
        }
        else
        {
          /* ERROR: CopyTxData of upper layer failed. Transmit will be aborted. */
          copyDataSuccessful = FALSE;
          TotalLength = 0;
        }
      }

      /* #50 Request next TX buffer segment from lower layer if required. */
      if (TotalLength > 0)
      {
        /* Request next UDP paylaod buffer fragement */
        if (E_OK != TcpIp_Udp_RequestNextTxBufferFragment(sockIdx, remoteSockAddrPtr->domain, &udpPayloadPtr, &udpPayloadLen))
        {
          /* ERROR: This should not happen. If TcpIp_Udp_RequestTxBuffer() retuns BUFREQ_OK there should be sufficient buffer space */
          TcpIp_CallDetReportError(TCPIP_API_ID_UDP_TRANSMIT, TCPIP_E_NOBUFS)
        }
      }
    }

    /* #60 Transmit UDP packet if payload was successfully copied into TX buffer. */
    if (copyDataSuccessful == TRUE)
    {
      IpBase_PbufType PBuf;

      TCPIP_VENTER_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

      PBuf.len     = (uint16)TcpIp_TxRequestedLen[sockIdx];
      PBuf.payload = NULL_PTR; /* TcpIp_Udp_TransmitAsr() will not use payload pointer */
      PBuf.totLen  = TcpIp_TxRequestedLen[sockIdx];

      if (TcpIp_Udp_TransmitAsr(sockIdx, &PBuf, (TCPIP_P2C(IpBase_SockAddrType))remoteSockAddrPtr) == E_OK)  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
      {
        retVal = TCPIP_OK;
      }

      TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
    /* #70 ELSE: Release TX buffer. */
    else
    {
      IpBase_PbufType PBuf;
      /* CopyTxData failed, so release the TxBuffer */
      PBuf.totLen = 0;
      PBuf.len    = 1;  /* use an inconsitent length value to cancel the transmission */
      (void)TcpIp_TransmitTo(sockIdx, &PBuf, (P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA))remoteSockAddrPtr);
    }
  }
  else
  {
    /* No Ethernet buffer available or link-layer address resolution pending and no free element in UDP retry queue. */
    retVal = TCPIP_E_NOT_OK;
  }

  return retVal;
} /* TcpIp_UdpTransmitInternal() */  /* PRQA S 6010, 6030, 6080, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF, MD_MSR_STCAL */

/***********************************************************************************************************************
 *  TcpIp_ProvideTxBuffer
 **********************************************************************************************************************/
/*! \brief      Request a tx buffer for sending data.
 *  \param[in]  SockHnd               socket handle
 *  \param[in]  Destination           destination network address and port
 *  \param[out] PbufPtr               pointer for the data
 *  \param[in]  Length                data length in bytes
 *  \return     BUFREQ_OK             buffer provided <br>
 *              BUFREQ_E_NOT_OK       provide buffer failed
 *  \note       This API is deprecated and will be removed in future revisions of this module. This is the old API
 *                according to AUTOSAR 4.0.3, do not use it any longer.
 *  \context    task level
 **********************************************************************************************************************/
FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_ProvideTxBuffer(
    TcpIp_SockHndType SockHnd,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) DestinationPtr,
    P2VAR(TcpIp_PbufType, AUTOMATIC, TCPIP_APPL_DATA) *PbufPtr,
    uint32 Length )
{
#if (TCPIP_SUPPORT_TLS == STD_ON)
  TcpIp_SockIdxType SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
  uint8 Prot;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
#endif

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_PROVIDE_TX_BUFFER, TCPIP_E_NOTINIT, BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(PbufPtr), TCPIP_API_ID_PROVIDE_TX_BUFFER, TCPIP_E_PARAM_POINTER, BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKHND(SockHnd), TCPIP_API_ID_PROVIDE_TX_BUFFER, TCPIP_E_INV_ARG, BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_LEN_MAX_UINT16(Length), TCPIP_API_ID_PROVIDE_TX_BUFFER, TCPIP_E_INV_ARG, BUFREQ_E_OVFL )
  /* ------------------------------------------------- */

  CANOE_WRITE_STRING_2("TcpIp_ProvideTxBuffer: providetxbuffer function called (SockHnd is %d, Length is %d)", SockHnd, Length)

#if (TCPIP_SUPPORT_TLS == STD_ON)
  SockIdx = TCPIP_SOCKHND2SOCKIDX(SockHnd);

  if(TcpIp_VCfgGetMaxNumUdpSocks() > SockIdx)
  {
    Prot = TCPIP_SOCK_PROT_UDP;
  }
  else
  {
    Prot = TCPIP_SOCK_PROT_TCP;
  }
#endif

  if(TCPIP_ACTIVE_STATE_ONLINE != TcpIp_ActiveState)
  {
    /* while module is not online, no buffer shall be provided */
    return BUFREQ_E_NOT_OK;
  }

#if (TCPIP_SUPPORT_TLS == STD_ON)
  if( (Prot == TCPIP_SOCK_PROT_TCP) && (TcpIp_Tcp_UseTls[TCPIP_SOCKIDX2TCPIDX(SockIdx)] == TRUE) )
  {
    /* forward request to TLS */
    return Tls_ProvideTxBuffer(SockIdx, PbufPtr, Length);
  }
  else
#endif
  {
    return TcpIp_ProvideTxBufferInt(SockHnd, DestinationPtr, PbufPtr, Length);
  }
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_ProvideTxBufferInt
 **********************************************************************************************************************/
/*! \brief      Request a tx buffer for sending data (internal).
 *  \param[in]  SockHnd               socket handle
 *  \param[in]  Destination           destination network address and port
 *  \param[out] PbufPtr               pointer for the data
 *  \param[in]  Length                data length in bytes
 *  \return     BUFREQ_OK             buffer provided <br>
 *              BUFREQ_E_NOT_OK       provide buffer failed
 *  \note       This API is deprecated and will be removed in future revisions of this module. This is the old API
 *                according to AUTOSAR 4.0.3, do not use it any longer.
 *  \context    task level
 **********************************************************************************************************************/
FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_ProvideTxBufferInt(
    TcpIp_SockHndType SockHnd,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) DestinationPtr,
    P2VAR(TcpIp_PbufType, AUTOMATIC, TCPIP_APPL_DATA) *PbufPtr,
    uint32 Length )
{
  BufReq_ReturnType RetValue = BUFREQ_E_NOT_OK;
  TcpIp_SockIdxType SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
  uint8 PbufArrayIdx;
  uint8 Prot;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_PROVIDE_TX_BUFFER_INT, TCPIP_E_NOTINIT, BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(PbufPtr), TCPIP_API_ID_PROVIDE_TX_BUFFER_INT, TCPIP_E_PARAM_POINTER, BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKHND(SockHnd), TCPIP_API_ID_PROVIDE_TX_BUFFER_INT, TCPIP_E_INV_ARG, BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_LEN_MAX_UINT16(Length), TCPIP_API_ID_PROVIDE_TX_BUFFER_INT, TCPIP_E_INV_ARG, BUFREQ_E_OVFL )
  /* ------------------------------------------------- */

  CANOE_WRITE_STRING_2("TcpIp_ProvideTxBuffer: providetxbuffer function called (SockHnd is %d, Length is %d)", SockHnd, Length)

  SockIdx = TCPIP_SOCKHND2SOCKIDX(SockHnd);
  PbufArrayIdx = (uint8)(2 * SockIdx);

  if(TcpIp_VCfgGetMaxNumUdpSocks() > SockIdx)
  {
    Prot = TCPIP_SOCK_PROT_UDP;
  }
  else
  {
    Prot = TCPIP_SOCK_PROT_TCP;
  }

  if( (0 == Length) && (TCPIP_SOCK_PROT_TCP == Prot) )
  {
    /* providing a buffer of size '0' makes no sense for TCP */
    return BUFREQ_E_NOT_OK;
  }

#if (TCPIP_SUPPORT_TCP == STD_ON)
  if((TCPIP_SOCK_PROT_TCP == Prot) && ((uint32)(TcpIp_VCfgGetTxBufSizeByte(TCPIP_SOCKIDX2TCPIDX(SockIdx))) < Length))  /* PRQA S 3382 */ /* MD_TCPIP_21.1_3382 */
  {
    /* requested length is bigger than total available TxBuffer */
    return BUFREQ_E_OVFL;
  }
#endif

  /* check that socket is open */
  if(TcpIp_SockListenActive[SockIdx].ConnStat  == TCPIP_SOCK_CONN_NONE)
  {
    /* conn state == none */
    return BUFREQ_E_NOT_OK;
  }

  /* check if buffer is already requested */
  TCPIP_VENTER_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */  /* lock interrupts */
  if(FALSE != TcpIp_TxBufRequested[SockIdx])
  {
    /* buffer is already locked by a previous call of ProvideTxBuffer() */
    TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */  /* unlock interrupts */
    return BUFREQ_E_BUSY;
  }
  else
  {
    TcpIp_TxBufRequested[SockIdx] = TRUE;
  }
  TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */  /* unlock interrupts */

  /* ------------------------------------------------------------------------------------------- */

  switch(Prot)
  {
#if (TCPIP_SUPPORT_TCP == STD_ON)
  case TCPIP_SOCK_PROT_TCP:
    {
      if((uint32)(TcpIp_VCfgGetTxBufSizeByte(TCPIP_SOCKIDX2TCPIDX(SockIdx)) - TcpIp_TxBufFillLevel[SockIdx]) >= Length)  /* PRQA S 3382 */ /* MD_TCPIP_21.1_3382 */
      {
        /* data fits into ring buffer */

        /* TCP: check tx requ handling array */
        if(E_OK != TcpIp_Tcp_TxCheckAndPrepBuf(TCPIP_SOCKIDX2TCPIDX(SockIdx)))  /* PRQA S 3382 */ /* MD_TCPIP_21.1_3382 */
        {
          TcpIp_TxBufRequested[SockIdx] = FALSE;  /* reset request to enable further requests */
          return BUFREQ_E_NOT_OK;
        }

        /* a buffer is available */
        {
          /* provide buffer using Pbuf struct */
          uint32 RemBufLenByte; /* remaining length from write postion to end of buffer */

          RemBufLenByte = TcpIp_VCfgGetTxBufSizeByte(TCPIP_SOCKIDX2TCPIDX(SockIdx)) - TcpIp_TxBufWritePos[SockIdx];  /* PRQA S 3382 */ /* MD_TCPIP_21.1_3382 */
          *PbufPtr      = &TcpIp_TxPbufArray[PbufArrayIdx];

          TcpIp_TxPbufArray[PbufArrayIdx].totLen  = (uint16)Length;
          TcpIp_TxPbufArray[PbufArrayIdx].payload = TcpIp_GetTxBuffersElemPtr(SockIdx, TcpIp_TxBufWritePos[SockIdx]);  /* PRQA S 3382 */ /* MD_TCPIP_21.1_3382 */
          if(RemBufLenByte < Length)
          {
            /* ring buffer wraparound has to be handled */
            TcpIp_TxPbufArray[PbufArrayIdx].len = (uint16)RemBufLenByte;

            TcpIp_TxPbufArray[PbufArrayIdx +1].totLen  = (uint16)Length;
            TcpIp_TxPbufArray[PbufArrayIdx +1].payload = TcpIp_GetTxBuffersElemPtr(SockIdx, 0);  /* PRQA S 3382 */ /* MD_TCPIP_21.1_3382 */
            TcpIp_TxPbufArray[PbufArrayIdx +1].len     = (uint16)Length - (uint16)RemBufLenByte;

            TcpIp_TxBufWritePos[SockIdx] = (uint16)Length - RemBufLenByte;
          }
          else
          {
            /* no ring buffer wraparound, so all memory is in one block */
            TcpIp_TxPbufArray[PbufArrayIdx].len = (uint16)Length;

            TcpIp_TxBufWritePos[SockIdx] += (uint16)Length;
            if(TcpIp_VCfgGetTxBufSizeByte(TCPIP_SOCKIDX2TCPIDX(SockIdx)) == TcpIp_TxBufWritePos[SockIdx])  /* PRQA S 3382 */ /* MD_TCPIP_21.1_3382 */
            {
              TcpIp_TxBufWritePos[SockIdx] = 0;
            }
          }

          TCPIP_VENTER_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */
          TcpIp_TxRequestedLen[SockIdx] = Length;
          TcpIp_TxBufFillLevel[SockIdx] += (uint16)Length;
          TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }

        RetValue = BUFREQ_OK;
      }
      else
      {
        /* currently the remaining TxBuffer size is too small for this request */
        TcpIp_TxBufRequested[SockIdx] = FALSE;  /* reset length to enable further requests */
        RetValue = BUFREQ_E_BUSY;
      }
      break;
    }
#endif
  case TCPIP_SOCK_PROT_UDP:
    {
      /* UDP: check tx requ handling array */
      uint8 *UdpPayloadPtr;
      uint16 UdpPayloadLen = (uint16)Length;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

      RetValue = TcpIp_Udp_RequestTxBuffer(SockIdx, (const IpBase_SockAddrType*)DestinationPtr, &UdpPayloadPtr, &UdpPayloadLen);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */

      if(BUFREQ_OK != RetValue)
      {
        TcpIp_TxBufRequested[SockIdx] = FALSE;  /* unlock socket to enable further requests */
      }
      else
      {
        /* a buffer could be provided successfully */
        *PbufPtr = &TcpIp_TxPbufArray[PbufArrayIdx];
        TcpIp_TxPbufArray[PbufArrayIdx].payload = UdpPayloadPtr;
        TcpIp_TxPbufArray[PbufArrayIdx].len     = (uint16)Length;
        TcpIp_TxPbufArray[PbufArrayIdx].totLen  = Length;

        TcpIp_TxBufRequested[SockIdx] = TRUE;  /* lock socket to prevent further requests */
        TcpIp_TxRequestedLen[SockIdx] = Length;
      }
      break;
    }
  default:  /* PRQA S 2018 */ /* MS_MSR_14.1 */
    {
      /* invalid protocol, do nothing */
      break;
    }
  }

  return RetValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *  TcpIp_TransmitTo
 **********************************************************************************************************************/
/*! \brief      Trigger sending of data
 *  \param[in]  SockHnd               socket handle
 *  \param[out] PbufPtr               pointer for the data
 *  \param[in]  Destination           destination network address and port
 *  \return     E_OK                  data transmit requested <br>
 *              E_NOT_OK              data transmission request failed
 *  \note       This API is deprecated and will be removed in future revisions of this module. This is the old API
 *                according to AUTOSAR 4.0.3, do not use it any longer.
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TransmitTo(
    TcpIp_SockHndType SockHnd,
    P2CONST(TcpIp_PbufType, TCPIP_APPL_DATA, TCPIP_CONST) PbufPtr,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) DestinationPtr )
{
  TcpIp_SockIdxType SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
  Std_ReturnType RetVal = E_NOT_OK;
  boolean ErrorOccurred = FALSE;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_TRANSMIT_TO, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(PbufPtr), TCPIP_API_ID_TRANSMIT_TO, TCPIP_E_PARAM_POINTER, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKHND(SockHnd), TCPIP_API_ID_TRANSMIT_TO, TCPIP_E_INV_ARG, E_NOT_OK )
  /* ------------------------------------------------- */

  SockIdx  = TCPIP_SOCKHND2SOCKIDX(SockHnd);

  /* check that socket is open */
  if(TcpIp_SockListenActive[SockIdx].ConnStat  == TCPIP_SOCK_CONN_NONE)
  {
    /* there is no active connection, so leave this function here */
    ErrorOccurred = TRUE;
  }
  else
  {
#if ((TCPIP_SUPPORT_TCP == STD_ON) && (TCPIP_SUPPORT_TLS == STD_ON))
    if((SockIdx >= TcpIp_VCfgGetMaxNumUdpSocks()) && (TcpIp_Tcp_UseTls[TCPIP_SOCKIDX2TCPIDX(SockIdx)] == TRUE))
    {
      /* this is a TCP socket and TLS is enabled for this socket */
      /* size has to be checked in TLS, nothing to do here */
    }
    else
#endif
    {
      if(TcpIp_TxRequestedLen[SockIdx] < PbufPtr->totLen)
      {
        /* the buffer requested in _ProvideTxBuffer is smaller than the data that shall be transmitted now */
        ErrorOccurred = TRUE;
      }
    }
  }

  if(ErrorOccurred == TRUE)
  {
    /* RetVal is already set to E_NOT_OK */
  }
  else
  {
#if ((TCPIP_SUPPORT_TCP == STD_ON) && (TCPIP_SUPPORT_TLS == STD_ON))
    if(SockIdx >= TcpIp_VCfgGetMaxNumUdpSocks())
    {
      /* This is a TCP socket */
      if(TcpIp_Tcp_UseTls[TCPIP_SOCKIDX2TCPIDX(SockIdx)] == TRUE)
      {
        /* forward request to TLS */
        RetVal = Tls_TransmitTo(SockIdx, PbufPtr);
      }
      else
      {
        /* forward request to TcpIp internal function */
        RetVal = TcpIp_TransmitToInt(SockHnd, PbufPtr, DestinationPtr);
      }
    }
    else
#endif
    {
      /* This is a UDP socket */
      /* forward request to TcpIp internal function */
      RetVal = TcpIp_TransmitToInt(SockHnd, PbufPtr, DestinationPtr);
    }
  }

  return RetVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_TransmitToInt
 **********************************************************************************************************************/
/*! \brief      Trigger sending of data (internal)
 *  \param[in]  SockHnd               socket handle
 *  \param[out] PbufPtr               pointer for the data
 *  \param[in]  Destination           destination network address and port
 *  \return     E_OK                  data transmit requested <br>
 *              E_NOT_OK              data transmission request failed
 *  \note       This API is deprecated and will be removed in future revisions of this module. This is the old API
 *                according to AUTOSAR 4.0.3, do not use it any longer.
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TransmitToInt(
    TcpIp_SockHndType SockHnd,
    P2CONST(TcpIp_PbufType, TCPIP_APPL_DATA, TCPIP_CONST) PbufPtr,
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) DestinationPtr )
{
  Std_ReturnType    RetValue;
  TcpIp_SockIdxType SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_TRANSMIT_TO_INT, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(PbufPtr), TCPIP_API_ID_TRANSMIT_TO_INT, TCPIP_E_PARAM_POINTER, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKHND(SockHnd), TCPIP_API_ID_TRANSMIT_TO_INT, TCPIP_E_INV_ARG, E_NOT_OK )
  /* ------------------------------------------------- */

  SockIdx  = TCPIP_SOCKHND2SOCKIDX(SockHnd);

  TCPIP_VENTER_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if(TCPIP_COND_VALID_UDPSOCKIDX(SockIdx))
  {
    /* UDP: */
    RetValue = TcpIp_Udp_TransmitAsr(SockIdx, (const IpBase_PbufType *)(PbufPtr), (const IpBase_SockAddrType*)DestinationPtr);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */

    /* free buffer request lock */
    TcpIp_TxBufRequested[SockIdx] = FALSE;
  }
  else
  {
#if (TCPIP_SUPPORT_TCP == STD_ON)
    /* TCP: */
    /* ignore destination */

    if(0 != PbufPtr->totLen)
    {
      if(TcpIp_TxRequestedLen[SockIdx] != PbufPtr->totLen)
      {
        /* transmitted length is smaller than the requested length -> decrease the buffer fill level */
        uint32 LenDiff = TcpIp_TxRequestedLen[SockIdx] - PbufPtr->totLen;
        TcpIp_DecTxBufIdx(SockIdx, TcpIp_TxBufWritePos[SockIdx], LenDiff);
        TcpIp_TxBufFillLevel[SockIdx] -= LenDiff;
      }
      RetValue = TcpIp_Tcp_SendAsr(TCPIP_SOCKIDX2TCPIDX(SockIdx), PbufPtr->totLen);
    }
    else
    {
      /* nothing to be sent, DataLen is '0' */
      /* cancel / free the provided tx buffer */
      TcpIp_DecTxBufIdx(SockIdx, TcpIp_TxBufWritePos[SockIdx], TcpIp_TxRequestedLen[SockIdx]);
      TcpIp_TxBufFillLevel[SockIdx] -= TcpIp_TxRequestedLen[SockIdx];
      RetValue = E_OK;
    }

    /* free Pbuf element */
    TcpIp_TxBufRequested[SockIdx] = FALSE;
#else
    RetValue = FALSE;
#endif
  }

  TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return RetValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */

#if (TCPIP_SUPPORT_TCP == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_TcpReceived
 **********************************************************************************************************************/
/*! \brief      By this API service the reception of socket data is confirmed to the TCP/IP stack.
 *  \param[in]  SocketId              Socket identifier of the related local socket resource
 *  \param[in]  Length                Number of bytes finally consumed by the upper layer
 *  \return     E_OK                  The request has been accepted <br>
 *              E_NOT_OK              The request has not been accepted
 *  \note       Increase the TCP receive window of the socket specified by SocketId considering the number of finally
 *                consumed bytes specified by Length.
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpReceived(
    TcpIp_SocketIdType SocketId,
    uint32 Length )
{
  Std_ReturnType RetVal = E_NOT_OK;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_TCP_RECEIVED, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_LEN_MAX_UINT16(Length), TCPIP_API_ID_TCP_RECEIVED, TCPIP_E_INV_ARG, E_NOT_OK )
  /* ------------------------------------------------- */

  if(TcpIp_SockUserIdx[SocketId] == TCPIP_UNDEFINED_SOCK_OWNER_IDX)
  {
    /* socket is not requested by a user */
  }
  else
  {
    if(TCPIP_COND_VALID_TCPSOCKIDX(SocketId))
    {
#if (TCPIP_SUPPORT_TLS == STD_ON)
      if(TcpIp_Tcp_UseTls[TCPIP_SOCKHND2TCPIDX(SocketId)] == TRUE)
      {
        /* TLS reveived */
        Tls_Received(SocketId, Length);
      }
      else
#endif
      {
        /* TCP reveived */
        TcpIp_Tcp_Received(TCPIP_SOCKIDX2TCPIDX(SocketId), Length);
      }
      RetVal = E_OK;
    }
    else
    {
      /* invalid socket id */
    }
  }

  return RetVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif

/***********************************************************************************************************************
 *  TcpIp_Close
 **********************************************************************************************************************/
/*! \brief      Close the socket.
 *  \description  By this API service the TCP/IP stack is requested to close the socket and release all related resources. <br>
 *              The service TcpIp_Close() shall perform the following actions for the socket specified by SocketId in case it is a TCP socket: <br>
 *              (a) if the connection is active and <br>
 *              (a1) abort = FALSE: the connection shall be terminated after performing a regular connection termination handshake and releasing all related resources. <br>
 *              (a2) abort = TRUE: connection shall immediately be terminated by sending a RST-Segment and releasing all related resources. <br>
 *              (b) if the socket is in the Listen state, the Listen state shall be left immediately and related resources shall be released.
 *  \param[in]  SocketId       Socket handle identifying the local socket resource.
 *  \param[in]  Abort          TRUE: connection will immediately be terminated by sending a RST-Segment and releasing
 *                               all related resources. <br>
 *                             FALSE: connection will be terminated after performing a regular connection termination
 *                               handshake and releasing all related resources.
 *  \return     E_OK           The request has been accepted. <br>
 *              E_NOT_OK       The request has not been accepted.
 *  \context    task level
 **********************************************************************************************************************/
Std_ReturnType TcpIp_Close(
    TcpIp_SocketIdType SocketId,
    boolean Abort )
{
  Std_ReturnType RetValue;
  uint8 TempUserIdx;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_CLOSE, TCPIP_E_NOTINIT, E_NOT_OK )
  /* ------------------------------------------------- */

#if (TCPIP_SUPPORT_TCP == STD_OFF)
  TCPIP_UNUSED_PARAMETER(Abort);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

  if(TCPIP_SOCK_CONN_NONE == TcpIp_SockListenActive[SocketId].ConnStat)
  {
    /* socket is already closed */
    return E_OK;
  }

  TempUserIdx = TcpIp_SockUserIdx[SocketId];

#if (TCPIP_SUPPORT_TCP == STD_ON)
  if(TCPIP_COND_VALID_TCPSOCKIDX(SocketId))
  {
    /* TCP */
    boolean IsTcpListenSocket = TcpIp_SocketList[SocketId].IsTcpListenSocket;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

    if(FALSE == Abort)
    {
      /* trigger closing of socket */
      TcpIp_Tcp_Close(TCPIP_SOCKHND2TCPIDX(SocketId));
      RetValue = E_OK;
    }
    else
    {
      /* trigger closing of socket */
      TcpIp_Tcp_Abort(TCPIP_SOCKHND2TCPIDX(SocketId));

      /* delete socket */
      TcpIp_SockUserIdx[SocketId] = TCPIP_UNDEFINED_SOCK_OWNER_IDX;
      TcpIp_SockListenActive[SocketId].ConnStat = TCPIP_SOCK_CONN_NONE;
      RetValue = E_OK;
    }

    /* If the socket was a listen socket, eventually delete the reference to this master socket in all sockets derived from this listen socket. */
    if(TRUE == IsTcpListenSocket)
    {
      uint8 TempSockIdx;
      for(TempSockIdx = TCPIP_MAX_NUM_UDP_SOCKETS; TempSockIdx < TCPIP_MAX_NUM_SOCKETS; TempSockIdx++)
      {
        if(SocketId == TcpIp_SocketList[TempSockIdx].TcpMasterListenSockId)
        {
          /* delete reference to the master socket */
          TcpIp_SocketList[TempSockIdx].TcpMasterListenSockId = TCPIP_INV_SOCKET_ID;  /* set to invalid index */
        }
      }
    }

    if(TRUE == Abort)
    {
#if (TCPIP_SUPPORT_TLS == STD_ON)
      if(TcpIp_Tcp_UseTls[TCPIP_SOCKHND2TCPIDX(SocketId)] == TRUE)
      {
        Tls_TcpIpEvent(SocketId, TCPIP_TCP_CLOSED);  /* trigger 'CLOSED' event */
      }
      else
#endif
      {
        TcpIp_TcpIpEventFunctions(TempUserIdx, SocketId, TCPIP_TCP_CLOSED);  /* trigger 'CLOSED' event */
      }
    }
    else
    {
      if(TCPIP_SOCK_CONN_CONNECTED != TcpIp_SockListenActive[SocketId].ConnStat)
      {
        /* delete socket */
        TcpIp_SockUserIdx[SocketId] = TCPIP_UNDEFINED_SOCK_OWNER_IDX;
        TcpIp_SockListenActive[SocketId].ConnStat = TCPIP_SOCK_CONN_NONE;

#if (TCPIP_SUPPORT_TLS == STD_ON)
        if(TcpIp_Tcp_UseTls[TCPIP_SOCKHND2TCPIDX(SocketId)] == TRUE)
        {
          Tls_TcpIpEvent(SocketId, TCPIP_TCP_CLOSED);  /* trigger 'CLOSED' event */
        }
        else
#endif
        {
          TcpIp_TcpIpEventFunctions(TempUserIdx, SocketId, TCPIP_TCP_CLOSED);  /* trigger 'CLOSED' event */
        }
      }
    }
  }
  else
#endif  /* (TCPIP_SUPPORT_TCP == STD_ON) */
  if(TCPIP_COND_VALID_UDPSOCKIDX(SocketId))
  {
    /* UDP */
    /* delete socket */
    TcpIp_SockUserIdx[SocketId]               = TCPIP_UNDEFINED_SOCK_OWNER_IDX;
    TcpIp_SockListenActive[SocketId].ConnStat = TCPIP_SOCK_CONN_NONE;

    TcpIp_VDelSockAddrMapping(SocketId);

    TcpIp_Udp_CloseSocket(SocketId);

    TcpIp_TcpIpEventFunctions(TempUserIdx, SocketId, TCPIP_UDP_CLOSED);  /* trigger 'CLOSED' event */

    RetValue = E_OK;
  }
  else
  {
    RetValue = E_NOT_OK;
  }

  return RetValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *  TcpIp_Bind
 **********************************************************************************************************************/
/*! \brief      By this API service the TCP/IP stack is requested to bind a UDP or TCP socket to a local resource
 *  \param[in]    SocketId            Socket identifier of the related local socket resource.
 *  \param[in]    LocalAddrId         IP address identifier representing the local IP address and EthIf
 *                                    controller to bind the socket to.
 *
 *                                    Note: to listen to all EthIf controller, TCPIP_LOCALADDRID_ANY
 *                                    has to be specified as LocalAddrId.
 *
 *                                    Note: to listen on any IP addresss of a EthIf controller, the
 *                                    configuration parameter TcpIpStaticIpAddress referenced by
 *                                    LocalAddrId must be set to 'ANY'. The remote IP address of an
 *                                    incoming packet has no effect then.
 *
 *                                    In case the socket shall be used as client socket, the IP address
 *                                    and EthIf controller represented by LocalAddrId is used for
 *                                    transmission.
 *
 *                                    Note: for an automatic selection of the Local IP address and EthIf
 *                                    Controller, TCPIP_LOCALADDRID_ANY has to be specified as
 *                                    LocalAddrId.
 *  \param[inout] PortPtr             Pointer to memory where the local port to which the socket shall
 *                                    be bound is specified. In case the parameter is specified as
 *                                    TCPIP_PORT_ANY, the TCP/IP stack shall choose the local port
 *                                    automatically from the range 49152 to 65535 and shall update the
 *                                    parameter to the chosen value.
 *  \return       E_OK                The request has been accepted <br>
 *                E_NOT_OK            The request has not been accepted (e.g. address in use)
 *  \context      task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Bind(
    TcpIp_SocketIdType           SocketId,
    TcpIp_LocalAddrIdType        LocalAddrId,
    P2VAR(uint16, AUTOMATIC, TCPIP_APPL_VAR) PortPtr )
{
  TcpIp_LocalAddrIdType IpAddrId;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKHND(SocketId),               TCPIP_API_ID_BIND, TCPIP_E_INV_ARG, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_OR_ANY_LOCALADDRID(LocalAddrId), TCPIP_API_ID_BIND, TCPIP_E_INV_ARG, E_NOT_OK )
  /* ------------------------------------------------- */

  if((LocalAddrId != TCPIP_LOCALADDRID_ANY) && (TCPIP_IPADDR_STATE_ASSIGNED != TcpIp_IpAddrAssignmentState[LocalAddrId]))
  {
    /* reject the bind request if no valid address is available for the LocalAddrId */
    TcpIp_CallDetReportError(TCPIP_API_ID_BIND, TCPIP_E_ADDRNOTAVAIL)
    return E_NOT_OK;
  }

  /* Set IpAddrId used for transmission. This Id may be updated by (IpV4_Ip|IpV6)_ProvideTxBuffer().
   * E.g. If IpAddrId is an AsBc address the IP will return the id of the auto-selected source address.
   */
  if (TCPIP_COND_VALID_LOCALADDRID(LocalAddrId))
  {
    /* Socket has Unicast or AutoSelect binding. This means use concrete or any IP on concrete controller for transmission */
    IpAddrId = TCPIP_LOCAL_ADDR_ID_2_IPVX_ID(LocalAddrId);
  }
  else
#if ( TCPIP_DEV_ERROR_DETECT == STD_OFF )
  if (TCPIP_LOCALADDRID_ANY == LocalAddrId)  /* PRQA S 3355, 3358 */ /* MD_TCPIP_13.7_3355_3358 */
#endif
  {
    /* Socket has ANY binding. This means use any IP on any controller for transmission */
    IpAddrId = TCPIP_IP_ADDR_ID_ANY;
  }
#if ( TCPIP_DEV_ERROR_DETECT == STD_OFF )  /* condition is already check with a DET-check */
  else if (TCPIP_LOCALADDRID_INV == LocalAddrId)  /* PRQA S 3201 */ /* MS_MSR_14.1 */
  {
    /* Unbind socket / IpAddrId shall not be invalid -> set to ANY */
    IpAddrId = TCPIP_IP_ADDR_ID_ANY;
  }
  else
  {
    return E_NOT_OK;
  }
#endif

  /* [SWS_TCPIP_00146]:  TcpIp_Bind() shall check if there is another socket already bound to the same port, protocol
     and local address and if that is the case refuse the request and return E_NOT_OK. If development error detection
     is enabled, the service TcpIp_Bind() shall also raise the development error code TCPIP_E_ADDRINUSE. () \trace SPEC-66326 */
  {
    uint8  SocketIdMin;
    uint8  SocketIdMax;
    uint8  LocalSocketId;
    uint16 PortNbo;

#if (TCPIP_SUPPORT_TCP == STD_ON)
    if (SocketId < TcpIp_VCfgGetMaxNumUdpSocks())
#endif
    {
      /* UDP */
      SocketIdMin = 0;
      SocketIdMax = TcpIp_VCfgGetMaxNumUdpSocks() - 1;

      if (*PortPtr == 0)
      {
        *PortPtr = TCPIP_GET_NEXT_DYNAMIC_PORT(TcpIp_Udp_DynamicPortCount);
      }
    }
#if (TCPIP_SUPPORT_TCP == STD_ON)
    else
    {
      /* TCP */
      SocketIdMin = TcpIp_VCfgGetMaxNumUdpSocks();
      SocketIdMax = TcpIp_VCfgGetMaxNumSocks() -1;

      if (*PortPtr == 0)
      {
        *PortPtr = TCPIP_GET_NEXT_DYNAMIC_PORT(TcpIp_Tcp_DynamicPortCount);
      }
    }
#endif

    PortNbo = IPBASE_HTON16(*PortPtr);

    for(LocalSocketId = SocketIdMin; LocalSocketId <= SocketIdMax; LocalSocketId++)
    {
      /* check if port and local address are the same as for the new request */
      if (TcpIp_SockListenActive[LocalSocketId].ConnStat != TCPIP_SOCK_CONN_NONE)
      {
        if( (LocalSocketId != SocketId) && (0 != PortNbo) && ( (TcpIp_SocketList[LocalSocketId].BindLocalAddrId == LocalAddrId) && (((TcpIp_SockAddrInetType*)(&TcpIp_SocketList[LocalSocketId].LocSock))->port == PortNbo) ) )  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
        {
          /* error, a socket with the requested protocol, port and IpAddrId is already requested */
          TcpIp_CallDetReportError( TCPIP_API_ID_BIND, TCPIP_E_ADDRINUSE )
          return E_NOT_OK;
        }
      }
    }

    ((IpBase_SockAddrInType*)(&TcpIp_SocketList[SocketId].LocSock))->sin_port = PortNbo;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  }

  TcpIp_SocketList[SocketId].TxIpAddrId      = IpAddrId;
  TcpIp_SocketList[SocketId].BindLocalAddrId = LocalAddrId;

  if (TCPIP_COND_VALID_UDPSOCKIDX(SocketId))
  {
    /* Bound UDP socket is always handled as listening socket. */
    TcpIp_SockListenActive[SocketId].ConnStat  = TCPIP_SOCK_CONN_LISTEN_ENABLED;
  }

  return E_OK;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *  TcpIp_RequestIpAddrAssignment
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_RequestIpAddrAssignment(
    TcpIp_LocalAddrIdType LocalAddrId,
    TcpIp_IpAddrAssignmentType Type,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_VAR) LocalIpAddrPtr,  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
    uint8 Netmask,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_VAR) DefaultRouterPtr )  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = TCPIP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component. */
  if (TcpIp_State == TCPIP_STATE_UNINIT)
  {
    errorId = TCPIP_E_NOTINIT;
  }
  /* #20 Check input parameters. */
  else if (LocalAddrId > TcpIp_VCfgGetMaxLocalAddrId())
  {
    errorId = TCPIP_E_INV_ARG;
  }
  else if ((Type > TCPIP_IPADDR_ASSIGNMENT_MAX_VALUE) && (Type != TCPIP_IPADDR_ASSIGNMENT_ANY))
  {
    errorId = TCPIP_E_INV_ARG;
  }
  /* Values of 'LocalIpAddrPtr', 'Netmask' and 'DefaultRouterPtr' are checked below. */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    if ((Type != TCPIP_IPADDR_ASSIGNMENT_STATIC) || (LocalIpAddrPtr != NULL_PTR))
    {
      /* Forward the request to the IP */
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# if (TCPIP_SUPPORT_IPV6 == STD_ON)
      if(TCPIP_LOCAL_ADDR_IS_AF_INET(LocalAddrId))
# endif
      {
        /* LocalAddrId is an IPv4 address id */
        if (Netmask <= 32)
        {
          uint8 ipAddrId = TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(LocalAddrId);
          IpBase_AddrInType localIpAddr       = IPV4_ADDR_ANY;
          IpBase_AddrInType defaultRouterAddr = IPV4_ADDR_ANY;

          if (LocalIpAddrPtr != NULL_PTR)
          {
            localIpAddr = ((TCPIP_P2C(IpBase_SockAddrInType))LocalIpAddrPtr)->sin_addr;          /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
          }

          if (DefaultRouterPtr != NULL_PTR)
          {
            defaultRouterAddr = ((TCPIP_P2C(IpBase_SockAddrInType))DefaultRouterPtr)->sin_addr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
          }

          retVal = IpV4_Ip_RequestIpAddrAssignment(ipAddrId, Type, localIpAddr, Netmask, defaultRouterAddr);
        }
        else
        {
          /* ERROR: Netmask is invalid. */
          errorId = TCPIP_E_INV_ARG;
        }
      }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
# if (TCPIP_SUPPORT_IPV4 == STD_ON)
      else
# endif
      {
        if (Netmask <= 128)
        {
          /* LocalAddrId is an IPv6 address id */
          uint8 ipAddrId = TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(LocalAddrId);
          retVal = IpV6_Ip_RequestIpAddrAssignment(ipAddrId, Type, LocalIpAddrPtr, Netmask, DefaultRouterPtr);
        }
        else
        {
          /* ERROR: Netmask is invalid. */
          errorId = TCPIP_E_INV_ARG;
        }
      }
#endif
    }
    else
    {
      /* ERROR: LocalIpAddrPtr must not be NULL_PTR if assignment type is STATIC. */
      errorId = TCPIP_E_INV_ARG;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (TCPIP_DEV_ERROR_REPORT == STD_ON)
  if (errorId != TCPIP_E_NO_ERROR)
  {
    (void)Det_ReportError(TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, TCPIP_API_ID_REQ_IP_ADDR_ASSIGN, errorId);
  }
#else
  TCPIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  TcpIp_ReleaseIpAddrAssignment
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_ReleaseIpAddrAssignment (
    TcpIp_LocalAddrIdType LocalAddrId )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = TCPIP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (TcpIp_State == TCPIP_STATE_UNINIT)
  {
    errorId = TCPIP_E_NOTINIT;
  }
  /* #20 Check parameter 'LocalAddrId' */
  else if (LocalAddrId > TcpIp_VCfgGetMaxLocalAddrId())
  {
    errorId = TCPIP_E_INV_ARG;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #30 Call TcpIp_ReleaseSpecificIpAddrAssignment with all assignment methods. */
    retVal = TcpIp_ReleaseSpecificIpAddrAssignment(LocalAddrId, TCPIP_IPADDR_ASSIGNMENT_ANY);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (TCPIP_DEV_ERROR_REPORT == STD_ON)
  if (errorId != TCPIP_E_NO_ERROR)
  {
    (void)Det_ReportError(TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, TCPIP_API_ID_REL_IP_ADDR_ASSIGN, errorId);
  }
#else
  TCPIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_ReleaseSpecificIpAddrAssignment
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_ReleaseSpecificIpAddrAssignment (
    TcpIp_LocalAddrIdType      localAddrId,
    TcpIp_IpAddrAssignmentType assignmentType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = TCPIP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (TcpIp_State == TCPIP_STATE_UNINIT)
  {
    errorId = TCPIP_E_NOTINIT;
  }
  /* #20 Check parameter 'localAddrId' */
  else if (localAddrId > TcpIp_VCfgGetMaxLocalAddrId())
  {
    errorId = TCPIP_E_INV_ARG;
  }
  /* #30 Check parameter 'assignmentType' */
  else if ((assignmentType > TCPIP_IPADDR_ASSIGNMENT_MAX_VALUE) && (assignmentType != TCPIP_IPADDR_ASSIGNMENT_ANY))
  {
    errorId = TCPIP_E_INV_ARG;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# if (TCPIP_SUPPORT_IPV6 == STD_ON)
  if(TCPIP_LOCAL_ADDR_IS_AF_INET(localAddrId))
# endif
    {
      /* LocalAddrId is an IPV4 address id */
      retVal = IpV4_Ip_ReleaseIpAddrAssignment(TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(localAddrId), assignmentType);
    }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
# if (TCPIP_SUPPORT_IPV4 == STD_ON)
    else
# endif
    {
      /* LocalAddrId is an IPV6 address id */
      uint32  PreferredLifetime = 0;
      uint32  ValidLifetime     = 0;
      boolean NoDad             = FALSE;

      retVal = IpV6_SetAddress(TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(localAddrId), NULL_PTR, PreferredLifetime, ValidLifetime, NoDad);
    }
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (TCPIP_DEV_ERROR_REPORT == STD_ON)
  if (errorId != TCPIP_E_NO_ERROR)
  {
    (void)Det_ReportError(TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, TCPIP_API_ID_REL_IP_ADDR_ASSIGN, errorId);
  }
#else
  TCPIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* TcpIp_ReleaseSpecificIpAddrAssignment() */

/***********************************************************************************************************************
 *  TcpIp_GetPhysAddr
 **********************************************************************************************************************/
/*! \brief        Obtains the physical source address used by the EthIf controller implicitly specified via LocalAddrId.
 *  \param[in]    LocalAddrId        Local address identifier implicitly specifing the EthIf controller for which the
 *                                   physical address shall be obtained.
 *  \param[out]   PhysAddrPtr        Pointer to the memory where the physical source address (MAC address) in network
 *                                   byte order is stored
 *  \return       E_OK               The request was successful <br>
 *                E_NOT_OK           The request was not successful, e.g. no unique Ctrl specified via IpAddrId.
 *  \context      task level
 *  \trace        SPEC-51037
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetPhysAddr(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) PhysAddrPtr )
{
  Std_ReturnType RetVal;
  uint8 IpVxAddrId;

  /* DET checks */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                   TCPIP_API_ID_GET_PHYS_ADDR, TCPIP_E_NOTINIT,       E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(PhysAddrPtr), TCPIP_API_ID_GET_PHYS_ADDR, TCPIP_E_PARAM_POINTER, E_NOT_OK )

  if(FALSE == TCPIP_COND_VALID_LOCALADDRID(LocalAddrId))
  {
    TcpIp_CallDetReportError( TCPIP_API_ID_GET_PHYS_ADDR, TCPIP_E_INV_ARG )
    return E_NOT_OK;
  }

  /* Forward request to IP */
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# if (TCPIP_SUPPORT_IPV6 == STD_ON)
  if(TCPIP_LOCAL_ADDR_IS_AF_INET(LocalAddrId))
# endif
  {
    /* IpV4 */
    IpVxAddrId = TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(LocalAddrId);
    RetVal     = IpV4_Ip_GetPhysAddr((IpV4_AddrIdType)IpVxAddrId, PhysAddrPtr);
  }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
# if (TCPIP_SUPPORT_IPV4 == STD_ON)
  else
# endif
  {
    /* IpV6 */
    IpVxAddrId = TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(LocalAddrId);
    RetVal     = IpV6_GetPhysAddrByIpAddrId((IpV6_AddrIdType)IpVxAddrId, PhysAddrPtr);
  }
#endif

  return RetVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_GetRemotePhysAddr
 **********************************************************************************************************************/
/*! \brief        Lookup the physical address for a remote network address. <br>
 *  \description  TcpIp_GetRemotePhysAddr queries the IP/physical address translation table specified by CtrlIdx and
 *                returns the physical address related to the IP address specified by IpAddrPtr. In case no physical
 *                address can be retrieved and parameter initRes is TRUE, address resolution for the specified IP
 *                address is initiated on the local network.
 *  \param[in]    CtrlIdx             EthIf controller index to identify the related ARP/NDP table.
 *  \param[in]    IpAddrPtr           specifies the IP address for which the physical address shall be retrieved
 *  \param[in]    initRes             specifies if the address resolution shall be initiated (TRUE) or not (FALSE) in
 *                                    case the physical address related to the specified IP address is currently
 *                                    unknown.
 *  \param[out]   PhysAddrPtr         Pointer to the memory where the physical address (MAC address) related to the
 *                                    specified IP address is stored in network byte order.
 *  \return       TCPIP_E_OK               specified IP address resolved, physical address provided via PhysAddrPtr <br>
 *                TCPIP_E_PHYS_ADDR_MISS   physical address currently unknown (address resolution initiated if initRes set to TRUE)
 *  \context      task level
 *  \trace        SPEC-66244
 **********************************************************************************************************************/
FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_GetRemotePhysAddr(
    uint8 CtrlIdx,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_VAR) IpAddrPtr,  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) PhysAddrPtr,
    boolean initRes)
{
  TcpIp_ReturnType RetVal;

  /* DET checks */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                   TCPIP_API_ID_GET_REMOTE_PHYS_ADDR, TCPIP_E_NOTINIT,       TCPIP_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(IpAddrPtr),   TCPIP_API_ID_GET_REMOTE_PHYS_ADDR, TCPIP_E_PARAM_POINTER, TCPIP_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(PhysAddrPtr), TCPIP_API_ID_GET_REMOTE_PHYS_ADDR, TCPIP_E_PARAM_POINTER, TCPIP_E_NOT_OK )

  /* Forward request to IP */
  switch(IpAddrPtr->domain)
  {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
  case TCPIP_AF_INET:
    {
      /* IpV4 */
      RetVal = IpV4_Ip_GetRemotePhysAddr( CtrlIdx, (TCPIP_P2C(TcpIp_SockAddrInetType))IpAddrPtr, PhysAddrPtr, initRes ); /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      break;
    }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  case TCPIP_AF_INET6:
    {
      /* IpV6 */
      RetVal = IpV6_GetRemotePhysAddr( CtrlIdx, (TCPIP_P2C(TcpIp_SockAddrInet6Type))IpAddrPtr, PhysAddrPtr, initRes );   /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      break;
    }
#endif
  default:
    {
      /* error, invalid domain type */
      RetVal = TCPIP_E_NOT_OK;
      break;
    }
  }

  return RetVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_GetCtrlIdx
 **********************************************************************************************************************/
/*! \brief        TcpIp_GetCtrlIdx returns the index of the EthIf controller related to LocalAddrId.
 *  \param[in]    LocalAddrId         Local address identifier implicitely specifing the EthIf controller that shall be
 *                                    returned
 *  \param[out]   CtrlIdxPtr          Pointer to the memory where the index of the EthIf controller related to
 *                                    LocalAddrId is stored
 *  \return       E_OK                The request was successful <br>
 *                E_NOT_OK            The request was not successful
 *  \context      task level
 *  \note
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetCtrlIdx(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) CtrlIdxPtr )  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
{
  uint8 IpVxAddrId;
  Std_ReturnType RetVal = E_NOT_OK;

  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                  TCPIP_API_ID_GET_CTRL_IDX, TCPIP_E_NOTINIT,       E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(CtrlIdxPtr), TCPIP_API_ID_GET_CTRL_IDX, TCPIP_E_PARAM_POINTER, E_NOT_OK )

  /* check that only valid address IDs are used */
  if(FALSE == TCPIP_COND_VALID_LOCALADDRID(LocalAddrId))
  {
    TcpIp_CallDetReportError( TCPIP_API_ID_GET_CTRL_IDX, TCPIP_E_INV_ARG )
    /* RetVal is already set to E_NOT_OK */
  }
  else
  {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# if (TCPIP_SUPPORT_IPV6 == STD_ON)
  if(TCPIP_LOCAL_ADDR_IS_AF_INET(LocalAddrId))
# endif
  {
    /* v4 */
    IpVxAddrId    = TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(LocalAddrId);
    (*CtrlIdxPtr) = IpV4_CtrlIdxIp2EthIf[IpV4_Ip_AddrId2CtrlAddrMap[IpVxAddrId].IpCtrlIdx];
    RetVal = E_OK;
  }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
# if (TCPIP_SUPPORT_IPV4 == STD_ON)
  else
# endif
  {
    /* v6 */
    IpVxAddrId    = TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(LocalAddrId);
    (*CtrlIdxPtr) = IpV6_CtrlIdxIp2EthIf[IpV6_AddrId2CtrlAddrMap[IpVxAddrId].IpCtrlIdx];
    RetVal = E_OK;
  }
#endif
  }

  return RetVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_MainFunctionRx
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
#if (TCPIP_SINGLE_MAIN_FUNCTION_ENABLED == STD_ON)
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_MainFunctionRx(void)
#else
FUNC(void, TCPIP_CODE) TcpIp_MainFunctionRx(void)
#endif
{
#if (TCPIP_SINGLE_MAIN_FUNCTION_ENABLED == STD_OFF)
  /* #10 Check initialization and active state of the component. */
  if ((TcpIp_State == TCPIP_STATE_UNINIT) || (TcpIp_ActiveState == TCPIP_ACTIVE_STATE_OFFLINE))
  {
    /* module is not initialized or offline, so do nothing here but just return */
  }
  else
#endif
  {
    /* IPv4 submodule does not have RX MainFunction. */

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
    /* #20 Call RX MainFunction of IPv6 submodule. */
    IpV6_MainFunctionRx();
#endif

    /* #30 Call RX MainFunction of UDP submodule. */
    TcpIp_Udp_MainFunctionRx();

#if (TCPIP_SUPPORT_TCP == STD_ON)
    /* #40 Call RX MainFunction of TCP submodule. */
    TcpIp_Tcp_MainFunctionRx();
#endif
  }
} /* TcpIp_MainFunctionRx() */

/***********************************************************************************************************************
 *  TcpIp_MainFunctionState
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
#if (TCPIP_SINGLE_MAIN_FUNCTION_ENABLED == STD_ON)
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_MainFunctionState(void)
#else
FUNC(void, TCPIP_CODE) TcpIp_MainFunctionState(void)
#endif
{
#if (TCPIP_SINGLE_MAIN_FUNCTION_ENABLED == STD_OFF)
  /* #10 Check initialization and active state of the component. */
  if ((TcpIp_State == TCPIP_STATE_UNINIT) || (TcpIp_ActiveState == TCPIP_ACTIVE_STATE_OFFLINE))
  {
    /* module is not initialized or offline, so do nothing here but just return */
  }
  else
#endif
  {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
    /* #20 Call MainFunction of IPv4 submodule. */
    IpV4_MainFunction();
#endif

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
    /* #30 Call State MainFunction of IPv6 submodule. */
    IpV6_MainFunctionState();
#endif

#if (TCPIP_DHCPV4SERVER_ENABLED == STD_ON)
    /* #40 Call MainFunction of DHCPv4 Server submodule. */
    TcpIp_DhcpV4Server_MainFunction();
#endif

    /* UDP submodule only has RX and TX MainFunctions. */

#if (TCPIP_SUPPORT_TCP == STD_ON)
    /* #50 Call State MainFunction of TCP submodule. */
    TcpIp_Tcp_MainFunctionState();
#endif
  }
} /* TcpIp_MainFunctionState() */

/***********************************************************************************************************************
 *  TcpIp_MainFunctionTx
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
#if (TCPIP_SINGLE_MAIN_FUNCTION_ENABLED == STD_ON)
TCPIP_LOCAL FUNC(void, TCPIP_CODE) TcpIp_MainFunctionTx(void)
#else
FUNC(void, TCPIP_CODE) TcpIp_MainFunctionTx(void)
#endif
{
#if (TCPIP_SINGLE_MAIN_FUNCTION_ENABLED == STD_OFF)
  /* #10 Check initialization and active state of the component. */
  if ((TcpIp_State == TCPIP_STATE_UNINIT) || (TcpIp_ActiveState == TCPIP_ACTIVE_STATE_OFFLINE))
  {
    /* module is not initialized or offline, so do nothing here but just return */
  }
  else
#endif
  {
    /* IPv4 submodule does not have a TX MainFunction. */

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
    /* #20 Call TX MainFunction of IPv6 submodule. */
    IpV6_MainFunctionTx();
#endif

    /* #30 Call TX MainFunction of UDP submodule. */
    TcpIp_Udp_MainFunctionTx();

#if (TCPIP_SUPPORT_TCP == STD_ON)
    /* #40 Call TX MainFunction of TCP submodule. */
    TcpIp_Tcp_MainFunctionTx();
#endif
  }
} /* TcpIp_MainFunctionTx() */

#if (TCPIP_SINGLE_MAIN_FUNCTION_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_MainFunction
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_MainFunction(void)
{
  /* #10 Check initialization and active state of the component. */
  if ((TcpIp_State == TCPIP_STATE_UNINIT) || (TcpIp_ActiveState == TCPIP_ACTIVE_STATE_OFFLINE))
  {
    /* module is not initialized or offline, so do nothing here but just return */
  }
  else
  {
    /* #20 Call RX MainFunction. */
    TcpIp_MainFunctionRx();

    /* #30 Call State MainFunction. */
    TcpIp_MainFunctionState();

    /* #40 Call TX MainFunction. */
    TcpIp_MainFunctionTx();
  }
}
#endif

/***********************************************************************************************************************
 *  TcpIp_ChangeParameter
 **********************************************************************************************************************/
/*! \brief      change socket parameter configuration
 *  \param[in]  SockHnd               socket handle
 *  \param[in]  ParameterId           parameter identification
 *  \param[in]  ParameterValue        parameter value
 *  \return     E_OK                  parameter changed <br>
 *              E_NOT_OK              parameter change failed
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_ChangeParameter(
    TcpIp_SocketIdType SocketId,
    TcpIp_ParamIdType ParameterId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) ParameterValue )  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
{
  Std_ReturnType RetValue = E_OK;
  uint8 SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_CHANGE_PARAM, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKIDX(SocketId), TCPIP_API_ID_CHANGE_PARAM, TCPIP_E_INV_ARG, E_NOT_OK )
  /* impl decission: ParameterId and ParameterValue are not checked for DET */
  /* ------------------------------------------------- */

  SockIdx = SocketId;

  switch(ParameterId)
  {
#if (TCPIP_SUPPORT_TCP == STD_ON)
  case TCPIP_PARAMID_TCP_NAGLE:                /* fall through. */
  case TCPIP_PARAMID_V_TCP_UTOENABLED:         /* fall through. */
  case TCPIP_PARAMID_V_TCP_UTOCHANGEABLE:      /* fall through. */
  case TCPIP_PARAMID_TCP_KEEPALIVE:
    {
      uint8 TcpOptParameterValue = *ParameterValue;
      RetValue = TcpIp_Tcp_SetSockOpt(TCPIP_SOCKHND2TCPIDX(SockIdx), ParameterId, TcpOptParameterValue);
      break;
    }
  case TCPIP_PARAMID_TCP_KEEPALIVE_PROBES_MAX: /* fall through. */
  case TCPIP_PARAMID_V_TCP_UTOUPDATE:
    {
      uint16 TcpOptParameterValue = *((uint16*)(ParameterValue));  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_parameter */  /* PRQA S 3305 */ /* MD_TCPIP_3305_param */
      RetValue = TcpIp_Tcp_SetSockOpt(TCPIP_SOCKHND2TCPIDX(SockIdx), ParameterId, TcpOptParameterValue);
      break;
    }
  case TCPIP_PARAMID_TCP_RXWND_MAX:            /* fall through. */
  case TCPIP_PARAMID_V_TCP_TXBUFSIZE:          /* fall through. */
  case TCPIP_PARAMID_TCP_KEEPALIVE_INTERVAL:   /* fall through. */
  case TCPIP_PARAMID_TCP_KEEPALIVE_TIME:
    {
      uint32 TcpOptParameterValue = *((uint32*)(ParameterValue));  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_parameter */  /* PRQA S 3305 */ /* MD_TCPIP_3305_param */
      /* choose a matching buffer from the pool, and assign it to the socket */
      RetValue = TcpIp_Tcp_SetSockOpt(TCPIP_SOCKHND2TCPIDX(SockIdx), ParameterId, TcpOptParameterValue);
      break;
    }

#if (TCPIP_SUPPORT_TLS == STD_ON)
  case TCPIP_PARAMID_V_USE_TLS:
    {
      TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_TCPSOCKIDX(SocketId), TCPIP_API_ID_CHANGE_PARAM, TCPIP_E_INV_ARG, E_NOT_OK )

      RetValue = Tls_GetSocket(SocketId);  /* get a free connection mapper element */
      if(RetValue == E_OK)
      {
        TcpIp_Tcp_UseTls[TCPIP_SOCKHND2TCPIDX(SockIdx)] = TRUE;
      }
      break;
    }
  case TCPIP_PARAMID_V_TLS_TXBUFSIZE:
  case TCPIP_PARAMID_V_TLS_RXBUFSIZE:
  case TCPIP_PARAMID_V_TLS_SELECT_OCSP_REQEST:
    {
      RetValue = Tls_ChangeParameter(SocketId, ParameterId, ParameterValue);  /* set TLS buffer sizes */
      break;
    }
#endif  /* (TCPIP_SUPPORT_TLS == STD_ON) */

#endif
  case TCPIP_PARAMID_V_UDP_TXREQLISTSIZE:
    {
      /* choose a matching buffer from the pool, and assign it to the socket */
      RetValue = TcpIp_Udp_SetSockOpt(SockIdx, ParameterId, ParameterValue);
      break;
    }
#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
  case TCPIP_PARAMID_V_UDP_TXRETRYLISTSIZE:
    {
      /* set the maximum number of Eth tx buffers used for buffering messages in case the remote address is not yet resolved */
      RetValue = TcpIp_Udp_SetSockOpt(SockIdx, ParameterId, ParameterValue);
      break;
    }
#endif
  case TCPIP_PARAMID_FRAMEPRIO:
    {
      /* uint8 FramePrio value, forward to IpV4 and IpV6 */
      uint8 TempValue = *ParameterValue;
#if(TCPIP_SUPPORT_IPV4 == STD_ON)
      if(E_NOT_OK == IpV4_Ip_SetEthIfFramePrio(SocketId, TempValue))
      {
        RetValue = E_NOT_OK;
      }
#endif
#if(TCPIP_SUPPORT_IPV6 == STD_ON)
      if(E_NOT_OK == IpV6_SetEthIfFramePrio(SocketId, TempValue))
      {
        RetValue = E_NOT_OK;
      }
#endif
      break;
    }
  case TCPIP_PARAMID_TTL:
    {
      /* forward to IpV4 and IpV6 */
      uint8 TempValue = *ParameterValue;
#if(TCPIP_SUPPORT_IPV4 == STD_ON)
      IpV4_Ip_SetTimeToLive(SocketId, TempValue);
#endif
#if(TCPIP_SUPPORT_IPV6 == STD_ON)
      IpV6_SetHopLimit(SocketId, TempValue);
#endif
      break;
    }
#if(TCPIP_SUPPORT_IPV4 == STD_ON)
  case TCPIP_PARAMID_V_IPV4_TYPE_OF_SERVICE:
    {
      /* uint8 FramePrio value, forward to IpV4 */
      uint8 TempValue = *ParameterValue;
      IpV4_Ip_SetTypeOfService(SocketId, TempValue);
      break;
    }
#endif
#if(TCPIP_SUPPORT_IPV6 == STD_ON)
  case TCPIP_PARAMID_V_IPV6_FLOW_LABEL:
    {
      /* uint32 FlowLabel value, forward to IpV6 */
      uint32 TempValue = *((uint32*)(ParameterValue));  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_parameter */  /* PRQA S 3305 */ /* MD_TCPIP_3305_param */
      IpV6_SetFlowLabel(SocketId, TempValue);
      break;
    }
  case TCPIP_PARAMID_V_IPV6_TRAFFIC_CLASS:
    {
      /* uint8 Traffic Class value, forward to IpV6 */
      uint8 TempValue = *ParameterValue;
      IpV6_SetTrafficClass(SocketId, TempValue);
      break;
    }
#endif

  case TCPIP_PARAMID_V_PHYS_DEST_ADDR:
    /* This parameter is currently only supported for IPv4. */
#if(TCPIP_SUPPORT_IPV4 == STD_ON)
      IpV4_Ip_SetPhysDestAddr(SocketId, ParameterValue);
#else
      RetValue = E_NOT_OK;
#endif
    break;

#if (TCPIP_SUPPORT_TLS == STD_ON)
  case TCPIP_PARAMID_V_TLS_HEARTBEAT_MODE:
  case TCPIP_PARAMID_V_TLS_HEARTBEAT_PERIOD_S:
    {
      RetValue = Tls_ChangeParameter(SocketId, ParameterId, ParameterValue);  /* forward change request to TLS */
      break;
    }
#endif

  default:
    {
      /* do nothing */
      RetValue = E_NOT_OK;
    }
  }

  return RetValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6050 */ /* MD_MSR_STCAL */

#if (TCPIP_SUPPORT_TLS == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_Tls_SetClientCertInfo
 **********************************************************************************************************************/
/*! \brief         Set the client certificate and key block ids for a TLS connection (necessary for client authentication).
 *  \param[in]     SocketId       socket handle
 *  \param[in]     CertPtr        pointer to client certificate (RAM block)
 *  \param[in]     KeyPtr         pointer to client private key (RAM block)
 *  \param[in]     CertLen        length of client certigicate
 *  \param[in]     KeyLen         length of client private key
 *  \return        E_OK           cert info could be set<br>
 *                 E_NOT_OK       cert info could NOT be set
 *  \context       task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls_SetClientCertInfo(
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) CertPtr,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) KeyPtr,
    uint16 CertLen,
    uint16 KeyLen )
{
  Std_ReturnType RetVal;

  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                       TCPIP_API_ID_SET_CLIENT_CERT_INFO, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_TCPSOCKIDX(SocketId), TCPIP_API_ID_SET_CLIENT_CERT_INFO, TCPIP_E_INV_SOCK_ID, E_NOT_OK )

  if(TcpIp_Tcp_UseTls[TCPIP_SOCKHND2TCPIDX(SocketId)] == TRUE)
  {
    RetVal = Tls_SetClientCertInfo( SocketId, CertPtr, KeyPtr, CertLen, KeyLen );
  }
  else
  {
    /* error, TLS is not enabled for this socket */
    RetVal = E_NOT_OK;
  }

  return RetVal;
}

/***********************************************************************************************************************
 *  TcpIp_Tls_GetNvmBlockIdForUsedRootCert
 **********************************************************************************************************************/
/*! \brief         Get the NVM block ID of the root certificate used for a TLS connection
 *  \param[in]     SocketId              Socket id
 *  \param[out]    RootCertBlockIdPtr    Pointer to the block ID
 *  \return        E_OK                  Block ID can be provided <br>
 *                 E_NOT_OK              request failed
 *  \context       task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls_GetNvmBlockIdForUsedRootCert(
    TcpIp_SocketIdType SocketId,
    P2VAR(NvM_BlockIdType, AUTOMATIC, TCPIP_APPL_DATA) RootCertBlockIdPtr )
{
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_GET_NVM_BLOCK_FOR_USED_ROOT_CERT, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_TCPSOCKIDX(SocketId), TCPIP_API_ID_GET_NVM_BLOCK_FOR_USED_ROOT_CERT, TCPIP_E_INV_ARG, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(RootCertBlockIdPtr), TCPIP_API_ID_GET_NVM_BLOCK_FOR_USED_ROOT_CERT, TCPIP_E_PARAM_POINTER, E_NOT_OK )

  /* forward request to TLS */
  return Tls_GetNvmBlockIdForUsedRootCert( SocketId, RootCertBlockIdPtr );
}

/***********************************************************************************************************************
 *  TcpIp_Tls_RootCertWasModified
 **********************************************************************************************************************/
/*! \brief         Inform the TLS that a root cert has been updated in NVM.
 *  \param[in]     NvmBlockId            BlockId of the NVM block that has changed
 *  \return        E_OK                  Block is used as a root certificate <br>
 *                 E_NOT_OK              request failed, block is not used as a root certificate
 *  \context       task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Tls_RootCertWasModified(
    NvM_BlockIdType NvmBlockId )
{
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_ROOT_CERT_WAS_MODIFIED, TCPIP_E_NOTINIT, E_NOT_OK )

  /* forward request to TLS */
  return Tls_RootCertWasModified( NvmBlockId );
}
#endif  /* (TCPIP_SUPPORT_TLS == STD_ON) */

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_GetLocNetAddr                                                                                    [DEPRECATED]
 **********************************************************************************************************************/
/*! \brief      This function returns the current IP address for a given controller
 *  \param[in]  LocalAddrId           local address identifier
 *  \param[out] NetAddrPtr            pointer for the local network address
 *  \return     E_OK                  local network address returned <br>
 *              E_NOT_OK              local network address access failed
 *  \note       This API is deprecated and will be removed in future revisions of this module. (see TcpIp_GetIpAddr)
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetLocNetAddr(
  TcpIp_LocalAddrIdType                                LocalAddrId,
  P2VAR(TcpIp_NetAddrType, AUTOMATIC, TCPIP_APPL_DATA) NetAddrPtr )
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                           TCPIP_API_ID_GET_LOC_NET_ADDR, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_LOCALADDRID(LocalAddrId), TCPIP_API_ID_GET_LOC_NET_ADDR, TCPIP_E_INV_ARG, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_LOCAL_ADDR_IS_AF_INET(LocalAddrId),  TCPIP_API_ID_GET_LOC_NET_ADDR, TCPIP_E_INV_ARG, E_NOT_OK )
  /* ------------------------------------------------- */

  return IpV4_Ip_GetLocNetAddr(TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(LocalAddrId), NetAddrPtr);
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_GetLocNetMask                                                                                    [DEPRECATED]
 **********************************************************************************************************************/
/*! \brief      This function returns the current network mask for a given controller
 *  \param[in]  LocalAddrId           local address identifier
 *  \param[out] NetMaskPtr            pointer for the local network mask
 *  \return     E_OK                  local network mask returned <br>
 *              E_NOT_OK              local network mask access failed
 *  \note       This API is deprecated and will be removed in future revisions of this module. (see TcpIp_GetIpAddr)
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetLocNetMask(
    TcpIp_LocalAddrIdType                                LocalAddrId,
    P2VAR(TcpIp_NetAddrType, AUTOMATIC, TCPIP_APPL_DATA) NetMaskPtr )
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                           TCPIP_API_ID_GET_LOC_NET_MASK, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_LOCALADDRID(LocalAddrId), TCPIP_API_ID_GET_LOC_NET_MASK, TCPIP_E_INV_ARG, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_LOCAL_ADDR_IS_AF_INET(LocalAddrId),  TCPIP_API_ID_GET_LOC_NET_ADDR, TCPIP_E_INV_ARG, E_NOT_OK )
  /* ------------------------------------------------- */

  return IpV4_Ip_GetLocNetMask(TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(LocalAddrId), NetMaskPtr);
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif

/***********************************************************************************************************************
 *  TcpIp_GetIpAddr
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetIpAddr(
  TcpIp_LocalAddrIdType         LocalAddrId,
  TCPIP_P2V(TcpIp_SockAddrType) IpAddrPtr,
  TCPIP_P2V(uint8)              NetmaskPtr,
  TCPIP_P2V(TcpIp_SockAddrType) DefaultRouterPtr )  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = TCPIP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (TcpIp_State == (uint8)TCPIP_STATE_UNINIT)
  {
    errorId = TCPIP_E_NOTINIT;
  }
  else
#endif
    /* ----- Implementation ----------------------------------------------- */
  {
    if (!TCPIP_COND_VALID_LOCALADDRID(LocalAddrId))  /* Check parameter 'LocalAddrId' */
    {
      /* invalid or any address id */
      /* retVal already is set to E_NOT_OK */
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
      errorId = TCPIP_E_INV_ARG;
#endif
    }
    else
    {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# if (TCPIP_SUPPORT_IPV6 == STD_ON)
      if(TCPIP_LOCAL_ADDR_IS_AF_INET(LocalAddrId))
#endif
      {
        /* IPBASE_AF_INET */
        IpV4_AddrIdType ipAddrId = TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(LocalAddrId);

        if (NULL_PTR != IpAddrPtr)
        {
          TCPIP_P2V(IpBase_SockAddrInType) IpAddrInPtr = (TCPIP_P2V(IpBase_SockAddrInType))IpAddrPtr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
          IpAddrInPtr->sin_family = IPBASE_AF_INET;
          retVal = IpV4_Ip_GetLocNetAddr(ipAddrId, &IpAddrInPtr->sin_addr);  /* PRQA S 3689 */ /* MD_TCPIP_21.1_3689_arrayusage */
        }
        else
        {
          retVal = E_OK;
        }

        if ((retVal == E_OK) && (NetmaskPtr != NULL_PTR))
        {
          IpBase_AddrInType netmask;
          retVal = IpV4_Ip_GetLocNetMask(ipAddrId, &netmask);

          if (retVal == E_OK)
          {
            /* convert network mask to CIDR format */
            uint8 shiftCnt = 0u;
            uint32 netmaskShifted = IPBASE_HTON32(netmask);
            while((shiftCnt < 32u) && ((netmaskShifted & 0x01) == 0u))
            {
              netmaskShifted = netmaskShifted >> 1;
              shiftCnt++;
            }
            *NetmaskPtr = (uint8)(32u - shiftCnt);
          }
        }

        if ((retVal == E_OK) && (DefaultRouterPtr != NULL_PTR))
        {
          TCPIP_P2V(IpBase_SockAddrInType) sockAddrAddrInPtr = (TCPIP_P2V(IpBase_SockAddrInType))DefaultRouterPtr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
          sockAddrAddrInPtr->sin_family = IPBASE_AF_INET;
          /* Ignore return value of IpV4_Ip_GetDefaultRouterNetAddr() because TcpIp_GetIpAddr() should not return an error if there is no default router. */
          (void)IpV4_Ip_GetDefaultRouterNetAddr(ipAddrId, &sockAddrAddrInPtr->sin_addr);
        }
      }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
# if (TCPIP_SUPPORT_IPV4 == STD_ON)
      else
#endif
      {
        /* IPBASE_AF_INET6 */
        if (IpAddrPtr != NULL_PTR)
        {
          TCPIP_P2V(IpBase_SockAddrIn6Type) sockAddrAddrIn6Ptr = (TCPIP_P2V(IpBase_SockAddrIn6Type))IpAddrPtr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
          sockAddrAddrIn6Ptr->sin6_family = IPBASE_AF_INET6;
          retVal = IpV6_GetLocalAddress(TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(LocalAddrId), &sockAddrAddrIn6Ptr->sin6_addr, NetmaskPtr);  /* PRQA S 291 */ /* MD_TCPIP_21.1_3689_arrayusage */
        }
        else
        {
          retVal = E_OK;
        }

        if ((retVal == E_OK) && (DefaultRouterPtr != NULL_PTR))
        {
          boolean routerIsReachable;
          TCPIP_P2V(IpBase_SockAddrIn6Type) sockAddrAddrIn6Ptr = (TCPIP_P2V(IpBase_SockAddrIn6Type))DefaultRouterPtr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
          sockAddrAddrIn6Ptr->sin6_family = IPBASE_AF_INET6;
          /* Ignore return value of IpV6_GetDefaultRouterAddress() because TcpIp_GetIpAddr() should not return an error if there is no default router. */
          (void)IpV6_GetDefaultRouterAddress(TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(LocalAddrId), &sockAddrAddrIn6Ptr->sin6_addr, &routerIsReachable);  /* PRQA S 3382 */ /* MD_TCPIP_21.1_3382 */
        }
      }
#endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (TCPIP_DEV_ERROR_REPORT == STD_ON)
  if (errorId != TCPIP_E_NO_ERROR)
  {
    (void)Det_ReportError(TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, TCPIP_API_ID_GET_IP_ADDR, errorId);
  }
#else
  TCPIP_UNUSED_PARAMETER(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
}  /* PRQA S 2006, 6030, 6080 */ /* MD_MSR_14.7, MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  TcpIp_GetRemNetAddr
 **********************************************************************************************************************/
/*! \brief      The API provides the remote address of an established TCP socket connection.
 *  \param[in]  SockHnd               socket handle
 *  \param[out] SockAddrPtr           Pointer to a socket address element
 *  \return     E_OK                  reading the socket address was successful <br>
 *              E_NOT_OK              remote IP address could not be obtained
 *  \note       SockAddrPtr is a pointer to a TcpIp memory area where the remote address is stored. The pointer is
 *                valid until the socket is closed.
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetRemNetAddr(
  TcpIp_SockHndType SockHnd,
  TCPIP_P2V(TcpIp_SockAddrType) *SockAddrPtr)
{
#if (TCPIP_SUPPORT_TCP == STD_ON)
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_GET_REM_NET_ADDR, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(SockAddrPtr), TCPIP_API_ID_GET_REM_NET_ADDR, TCPIP_E_PARAM_POINTER, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKHND(SockHnd), TCPIP_API_ID_GET_REM_NET_ADDR, TCPIP_E_INV_SOCK_ID, E_NOT_OK )
  /* ------------------------------------------------- */

  if(TcpIp_VCfgGetMaxNumUdpSocks() > (TcpIp_SockIdxType)SockHnd)
  {
    /* there is no remote socket address stored for UDP sockets */
    return E_NOT_OK;
  }
  if(FALSE == TcpIp_Tcp_GetSockIsConnected(TCPIP_SOCKHND2TCPIDX(SockHnd)))
  {
    /* TCP socket is not connected */
    return E_NOT_OK;
  }

  *SockAddrPtr = (TcpIp_SockAddrType*)&TcpIp_SocketList[SockHnd].RemSock;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  return E_OK;
#else
  TCPIP_UNUSED_PARAMETER(SockHnd);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
  TCPIP_UNUSED_PARAMETER(SockAddrPtr);  /* PRQA S 3112 */ /* MD_MSR_14.2 */

  /* only UDP is enabled, and for UDP there is never a remote address stored */
  return E_NOT_OK;
#endif
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief      Get Tcp/Ip Version
 *  \param[in]  versioninfo           pointer for version information
 *  \return     void
 *  \context    task level
 *  \note       The module version is given decimal coded.
 **********************************************************************************************************************/
#if (TCPIP_VERSION_INFO_API == STD_ON)
FUNC(void, TCPIP_CODE) TcpIp_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, TCPIP_APPL_DATA) versioninfo )
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_PTR(versioninfo), TCPIP_API_ID_GET_VERSION_INFO, TCPIP_E_PARAM_POINTER )
  /* ------------------------------------------------- */

  versioninfo->vendorID         = TCPIP_VENDOR_ID;
  versioninfo->moduleID         = TCPIP_MODULE_ID;
  versioninfo->sw_major_version = TCPIP_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version = TCPIP_SW_MINOR_VERSION;
  versioninfo->sw_patch_version = TCPIP_SW_PATCH_VERSION;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif
  /* TCPIP_VERSION_INFO_API */

#if TCPIP_SUPPORT_DHCPV4 == STD_ON
# if ((TCPIP_DHCPV4_SUPPORT_OPTIONS == STD_ON) && (TCPIP_DHCPV4_TX_OPTION_CNT > 0))  /* PRQA S 3332 */ /* MD_TCPIP_19.11_3332 */
/***********************************************************************************************************************
 *  TcpIp_DhcpReadOption
 **********************************************************************************************************************/
/*! \brief      Read user option data for outgoing DHCPv4 messages. <br>
 *  \description  By this API service the TCP/IP stack retrieves DHCP option data identified by parameter option for
 *                already received DHCP options.
 *  \param[in]      LocalIpAddrId  IP address identifier representing the local IP address and EthIf controller for
*                                  which the DHCP option shall be read.
 *  \param[in]      Option         DHCP option, e.g. Host Name
 *  \param[in]      DataLength     length of DHCP option data
 *  \param[in,out]  DataPtr        As input parameter, contains the length of the provided data buffer.
 *                                 Will be overwritten with the length of the actual data.
 *  \return     E_OK           requested data retrieved successfully. <br>
 *              E_NOT_OK       requested data could not be retrieved.
 *  \note       Currently only the option 'TCPIP_DHCPV4_OPT_ID_CLIENT_FQDN' is supported.
 *  \context    interrupt or task level
 *  \trace      SPEC-66254, SPEC-51122
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpReadOption(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint8 Option,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataLength,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr )
{
  uint8 IpAddrId;
  Std_ReturnType RetValue;

  /* DET */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,               TCPIP_API_ID_SET_DHCP_READ_OPT, TCPIP_E_NOTINIT,  E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(DataPtr), TCPIP_API_ID_SET_DHCP_READ_OPT, TCPIP_E_PARAM_POINTER, E_NOT_OK )

  /* check IP address id */
  if(TCPIP_LOCAL_ADDR_IS_AF_INET(LocalIpAddrId))
  {
    uint8 MsgFlags;

    /* Socket has Unicast or AutoSelect binding. This means use concrete or any IP on concrete controller for transmission */
    IpAddrId = TCPIP_LOCAL_ADDR_ID_2_IPVX_ID(LocalIpAddrId);
    /* forward request to DHCP */
    RetValue = TcpIp_DhcpV4_VGetTxOption(IpAddrId, Option, DataLength, DataPtr, &MsgFlags);
  }
  else
  {
    TcpIp_CallDetReportError( TCPIP_API_ID_SET_DHCP_READ_OPT, TCPIP_E_INV_ARG )
    RetValue = E_NOT_OK;  /* error, no valid address id selected, TCPIP_LOCALADDRID_ANY is not allowed */
  }

  return RetValue;
}

/***********************************************************************************************************************
 *  TcpIp_DhcpWriteOption
 **********************************************************************************************************************/
/*! \brief      Set user option data for outgoing DHCPv4 messages. <br>
 *  \description  By this API service the TCP/IP stack writes the DHCP option data identified by parameter option.
 *  \param[in]  LocalIpAddrId  IP address identifier representing the local IP address and EthIf controller for which
*                              the DHCP option shall be written.
 *  \param[in]  Option         DHCP option, e.g. Host Name
 *  \param[in]  DataLength     length of DHCP option data
 *  \param[in]  DataPtr        Pointer to memory containing DHCP option data
 *  \return     E_OK           no error occured. <br>
 *              E_NOT_OK       DHCP option data could not be written.
 *  \note       Old similar Vector API was TcpIp_SetDhcpV4TxOption. <br>
 *              Currently only the option 'TCPIP_DHCPV4_OPT_ID_CLIENT_FQDN' is supported.
 *  \context    interrupt or task level
 *  \trace      SPEC-66254, SPEC-51088
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpWriteOption(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint8 Option,
    uint8 DataLength,
    P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr )
{
  uint8 IpAddrId;
  Std_ReturnType RetValue;

  /* DET */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,               TCPIP_API_ID_SET_DHCP_WRITE_OPT, TCPIP_E_NOTINIT,  E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(DataPtr), TCPIP_API_ID_SET_DHCP_WRITE_OPT, TCPIP_E_PARAM_POINTER, E_NOT_OK )

  /* check IP address id */
  if(TCPIP_LOCAL_ADDR_IS_AF_INET(LocalIpAddrId))
  {
    /* Socket has Unicast or AutoSelect binding. This means use concrete or any IP on concrete controller for transmission */
    IpAddrId = TCPIP_LOCAL_ADDR_ID_2_IPVX_ID(LocalIpAddrId);
    /* forward request to DHCP */
    RetValue = TcpIp_DhcpV4_VSetTxOption(IpAddrId, Option, DataLength, DataPtr, TCPIP_DHCPV4_MSG_FLAG_ALLWAYS);
  }
  else
  {
    TcpIp_CallDetReportError( TCPIP_API_ID_SET_DHCP_WRITE_OPT, TCPIP_E_INV_ARG )
    RetValue = E_NOT_OK;  /* error, no valid address id selected, TCPIP_LOCALADDRID_ANY is not allowed */
  }

  return RetValue;
}
# endif
#endif
  /* TCPIP_SUPPORT_DHCPV4 == STD_ON */

#if (TCPIP_SUPPORT_DHCPV6 == STD_ON)
# if ((TCPIP_DHCPV6_SUPPORT_OPTIONS == STD_ON) && (TCPIP_DHCPV6_TX_OPTION_CNT > 0))
/***********************************************************************************************************************
 *  TcpIp_DhcpV6ReadOption
 **********************************************************************************************************************/
/*! \brief      Read user option data for outgoing DHCPv6 messages. <br>
 *  \description  By this API service the TCP/IP stack retrieves DHCP option data identified by parameter option for
 *                already received DHCP options.
 *  \param[in]      LocalIpAddrId  IP address identifier representing the local IP address and EthIf controller for
*                                  which the DHCP option shall be read.
 *  \param[in]      Option         DHCP option, e.g. Host Name
 *  \param[in]      DataLength     length of DHCP option data
 *  \param[in,out]  DataPtr        As input parameter, contains the length of the provided data buffer.
 *                                 Will be overwritten with the length of the actual data.
 *  \return     E_OK           requested data retrieved successfully. <br>
 *              E_NOT_OK       requested data could not be retrieved.
 *  \note       Currently only the option 'TCPIP_DHCPV6_OPT_ID_CLIENT_FQDN' is supported.
 *  \context    interrupt or task level
 *  \trace      SPEC-66373, SPEC-66297
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6ReadOption(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint16 Option,
    P2VAR(uint16, AUTOMATIC, TCPIP_APPL_DATA) DataLength,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr )
{
  uint8 IpAddrId;
  Std_ReturnType RetValue;

  /* DET */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,               TCPIP_API_ID_SET_DHCP_V6_READ_OPT, TCPIP_E_NOTINIT,  E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(DataPtr), TCPIP_API_ID_SET_DHCP_V6_READ_OPT, TCPIP_E_PARAM_POINTER, E_NOT_OK )

  /* check IP address id */
  if(TCPIP_LOCAL_ADDR_IS_AF_INET6(LocalIpAddrId))
  {
    uint8 MsgFlags;

    /* Socket has Unicast or AutoSelect binding. This means use concrete or any IP on concrete controller for transmission */
    IpAddrId = TCPIP_LOCAL_ADDR_ID_2_IPVX_ID(LocalIpAddrId);
    /* forward request to DHCP */
    RetValue = TcpIp_DhcpV6_VGetTxOption(IpAddrId, Option, DataLength, DataPtr, &MsgFlags);
  }
  else
  {
    TcpIp_CallDetReportError( TCPIP_API_ID_SET_DHCP_V6_READ_OPT, TCPIP_E_INV_ARG )
    RetValue = E_NOT_OK;  /* error, no valid address id selected, TCPIP_LOCALADDRID_ANY is not allowed */
  }

  return RetValue;
}

/***********************************************************************************************************************
 *  TcpIp_DhcpV6WriteOption
 **********************************************************************************************************************/
/*! \brief      Set user option data for outgoing DHCPv6 messages.
 *  \param[in]  OptSelector  Selector id of configured option. (Not the option id) Use configured access define.
 *  \param[in]  OptLen       Length of option data in bytes. Set to 0 to inhibit sending of the option.
 *  \param[in]  OptPtr       Payload of the option. Pointer must be valid until it is updated by calling this function.
 *                           (Ignored if OptLen is 0)
 *  \param[in]  MsgFlags     Defines in which messages the option shall be sent.
 *                           One or more flags of TCPIP_DHCPV6_MSG_FLAG_*
 *  \return     E_OK         Success <br>
 *              E_NOT_OK     Invalid OptSelector
 *  \note       Old similar Vector API was TcpIp_SetDhcpV6TxOption. <br>
 *              Currently only the option 'TCPIP_DHCPV6_OPT_ID_CLIENT_FQDN' is supported.
 *  \context    interrupt or task level
 *  \trace      SPEC-66373, SPEC-66209
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6WriteOption(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint16 Option,
    uint16 DataLength,
    P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr )
{
  uint8 IpAddrId;
  Std_ReturnType RetValue;

  /* DET */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,               TCPIP_API_ID_SET_DHCP_WRITE_OPT, TCPIP_E_NOTINIT,  E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(DataPtr), TCPIP_API_ID_SET_DHCP_WRITE_OPT, TCPIP_E_PARAM_POINTER, E_NOT_OK )

  /* check IP address id */
  if(TCPIP_LOCAL_ADDR_IS_AF_INET6(LocalIpAddrId))
  {
    /* Socket has Unicast or AutoSelect binding. This means use concrete or any IP on concrete controller for transmission */
    IpAddrId = TCPIP_LOCAL_ADDR_ID_2_IPVX_ID(LocalIpAddrId);
    /* forward request to DHCP */
    RetValue = TcpIp_DhcpV6_VSetTxOption(IpAddrId, Option, DataLength, DataPtr, TCPIP_DHCPV6_MSG_FLAG_ALLWAYS);
  }
  else
  {
    TcpIp_CallDetReportError( TCPIP_API_ID_SET_DHCP_WRITE_OPT, TCPIP_E_INV_ARG )
    RetValue = E_NOT_OK;  /* error, no valid address id selected, TCPIP_LOCALADDRID_ANY is not allowed */
  }

  return RetValue;
}
# endif
#endif
  /* TCPIP_SUPPORT_DHCPV6 == STD_ON */

/***********************************************************************************************************************
 *  TcpIp_GetDhcpTimeoutInfo
 **********************************************************************************************************************/
/*! \brief      check if a DHCP address finding timeout occurred
 *  \param[in]  CtrlIdx               controller index
 *  \param[in]  IpVer                 IP version
 *  \return     TRUE                  there was a DHCP timeout <br>
 *              FALSE                 there was no DHCP timeout
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_GetDhcpTimeoutInfo(
    uint8 CtrlIdx,  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
    uint8 IpVer )   /* PRQA S 3206 */ /* MD_TCPIP_3206 */
{
#if (TCPIP_SUPPORT_DHCPV4 == STD_ON)
  if(IpVer != TCPIP_IP_PROT_VER_4)
  {
    return FALSE;  /* this case is currently not supported */
  }

  if(FALSE == TcpIp_DhcpV4_GetDhcpTimeoutInfo(CtrlIdx))
  {
    /* no DHCP timeout occurred */
    return FALSE;
  }
  else
  {
    /* a DHCP timeout occurred */
    return TRUE;
  }
#else
  TCPIP_UNUSED_PARAMETER(IpVer);    /* PRQA S 3112 */ /* MD_MSR_14.2 */
  TCPIP_UNUSED_PARAMETER(CtrlIdx);  /* PRQA S 3112 */ /* MD_MSR_14.2 */

  /* DHCP is not activated, so no timeout can occur */
  return FALSE;
#endif
  /* TCPIP_SUPPORT_DHCPV4 == STD_ON */
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_GetIpAddrCfgSrc
 **********************************************************************************************************************/
/*! \brief      Get the configuration source of an IP address
 *  \param[in]  LocalAddrId           local address identifier
 *  \param[in]  AddrPtr               address for which the configuration source shall be returned
 *  \param[out] CfgSrcPtr             configuration source of the address
 *  \return     E_OK                  address is valid and *CfgSrcPtr has be set <br>
 *              E_NOT_OK              address invalid or not assigned to this node. *CfgSrcPtr not modified.
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetIpAddrCfgSrc(
    TcpIp_LocalAddrIdType                   LocalAddrId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) CfgSrcPtr)
{
  Std_ReturnType Result;

  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                           TCPIP_API_ID_GET_IP_ADDR_CFG_SRC, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(CfgSrcPtr),           TCPIP_API_ID_GET_IP_ADDR_CFG_SRC, TCPIP_E_PARAM_POINTER,     E_NOT_OK )

  if(!TCPIP_COND_VALID_LOCALADDRID(LocalAddrId))
  {
    TcpIp_CallDetReportError( TCPIP_API_ID_GET_IP_ADDR_CFG_SRC, TCPIP_E_INV_ARG )
    Result = E_NOT_OK;
  }
  else
  {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# if (TCPIP_SUPPORT_IPV6 == STD_ON)
    if (TCPIP_LOCAL_ADDR_IS_AF_INET(LocalAddrId))  /* PRQA S 3689 */ /* MD_TCPIP_21.1_3689_arrayusage */
#endif
    {
      uint8 ipAddrAssignmentMethod = IpV4_Ip_GetActiveAddrAssignmentMethod(TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(LocalAddrId));  /* PRQA S 3689 */ /* MD_TCPIP_21.1_3689_arrayusage */

      /* map IpV4 address configuration source to TcpIp configuration source */
      switch (ipAddrAssignmentMethod)
      {
      case IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC:
        (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_FIX;
        break;

      case IPV4_IP_ADDR_ASSIGNMENT_METHOD_DHCP:
        (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_DHCP;
        break;

      case IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL:
        (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_LL;
        break;

      default:
        (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_NONE;
        break;
      }

      Result = E_OK;
    }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
# if (TCPIP_SUPPORT_IPV4 == STD_ON)
    else
#endif
    {
      uint8 IpV6CfgSrc;
      Result = IpV6_GetLocalAddressCfgSrc(TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(LocalAddrId), &IpV6CfgSrc);  /* PRQA S 3689 */ /* MD_TCPIP_21.1_3689_arrayusage */

      if (E_OK == Result)
      {
        /* map IpV6 address configuration source to TcpIp configuration source */
        switch (IpV6CfgSrc)
        {
        case IPV6_ADDR_CFG_SRC_LL:
          (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_LL;
          break;

        case IPV6_ADDR_CFG_SRC_STATIC:
          (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_FIX;
          break;

        case IPV6_ADDR_CFG_SRC_RA:
          (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_RA;
          break;

        case IPV6_ADDR_CFG_SRC_DHCP:
          (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_DHCP;
          break;

#if defined(IPV6_ADDR_CFG_SRC_PRIV_EXT)
        case IPV6_ADDR_CFG_SRC_PRIV_EXT:
          (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_PRIV_EXT;
          break;
#endif

        default:
          (*CfgSrcPtr) = TCPIP_IP_CFG_SRC_NONE;
          break;
        }
      }
    }
#endif

  }

  return Result;
} /* End of TcpIp_GetIpAddrCfgSrc() */  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *  TcpIp_RequestComMode
 **********************************************************************************************************************/
/*! \brief      By this API service the TCP/IP stack is requested to change the TcpIp state of the communication network
 *                identified by EthIf controller index.
 *  \param[in]  CtrlIdx               EthIf controller index to identify the communication network where the TcpIp state
 *                                      is requested
 *  \param[in]  State                 Requested TcpIp state
 *  \return     E_OK                  request was accepted <br>
 *              E_NOT_OK              request was not accepted
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_RequestComMode(
    uint8            CtrlIdx,  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
    TcpIp_StateType  State)  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
{
  /* dummy function for inter-module compatibility */

  TCPIP_UNUSED_PARAMETER(CtrlIdx);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
  TCPIP_UNUSED_PARAMETER(State);    /* PRQA S 3112 */ /* MD_MSR_14.2 */

  return E_OK;
}

/***********************************************************************************************************************
 *  TcpIp_GetLocSockAddr
 **********************************************************************************************************************/
/*! \brief      Read the local socket address of one socket
 *  \param[in]  SockHnd               socket handle
 *  \param[out] SockPtr               pointer were the local socket address shall be written to
 *  \return     E_OK                  socket address was written successfully <br>
 *              E_NOT_OK              error, socket address is not updated
 *  \note: This is a Vector extension
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetLocSockAddr(
    TcpIp_SockHndType            SockHnd,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_VAR) SockPtr)
{
  Std_ReturnType RetValue;
  IpBase_SockAddrType *LocSockPtr;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                   TCPIP_API_ID_GET_LOCAL_SOCK_ADDR, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKHND(SockHnd), TCPIP_API_ID_GET_LOCAL_SOCK_ADDR, TCPIP_E_INV_ARG,       E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(SockPtr),     TCPIP_API_ID_GET_LOCAL_SOCK_ADDR, TCPIP_E_PARAM_POINTER,     E_NOT_OK )
  /* ------------------------------------------------- */

  LocSockPtr = (IpBase_SockAddrType*)(&TcpIp_SocketList[SockHnd].LocSock);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  RetValue   = IpBase_CopySockAddr((IpBase_SockAddrType*)SockPtr, LocSockPtr);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */

  return RetValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if (STD_ON == TCPIP_DIAG_ACCESS_EXTENSIONS_SUPPORT)
/**********************************************************************************************************************
 *  TcpIp_DiagDataReadAccess
 *********************************************************************************************************************/
/*! \brief          diagnostic data read access
 *  \param[in]      SockHnd        socket handle
 *  \param[in]      DataID         data identifier
 *  \param[out]     DataPtr        pointer for diagnostic data
 *  \param[in,out]  DataLenPtr     pointer for maximum / actual length of diagnostic data in bytes
 *  \return         E_OK           diagnostic data written <br>
 *                  E_NOT_OK       invalid parameter (data identifier not found, NULL_PTR parameter, invalid length)
 *  \note           The memory fragment DataPtr points to should be aligned properly regarding the expected returned
 *                    type / struct. Data is only written if RetValue is E_OK. <br>
 *                    This is a Vector extension.
 *  \context        task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DiagDataReadAccess(
    TcpIp_SockHndType    SockHnd,
    TcpIp_DiagParamsType DataID,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR)  DataPtr,
    P2VAR(uint16, AUTOMATIC, TCPIP_APPL_VAR) DataLenPtr )
{
  Std_ReturnType RetValue = E_NOT_OK;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                    TCPIP_API_ID_DIAG_DATA_READ_ACCESS, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKHND(SockHnd),  TCPIP_API_ID_DIAG_DATA_READ_ACCESS, TCPIP_E_INV_SOCK_ID,    E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( (DataID < TCPIP_DP_INVALID),        TCPIP_API_ID_DIAG_DATA_READ_ACCESS, TCPIP_E_INV_ARG,       E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(DataPtr),      TCPIP_API_ID_DIAG_DATA_READ_ACCESS, TCPIP_E_PARAM_POINTER,     E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(DataLenPtr),   TCPIP_API_ID_DIAG_DATA_READ_ACCESS, TCPIP_E_PARAM_POINTER,     E_NOT_OK )
  /* ------------------------------------------------- */

  switch(DataID)
  {
  case TCPIP_DP_SOCKET_LOCAL_PORT:
    /* ----------------------------------------------------------------------------------------- */
    /* Read the current local port number for a given socket. */
    if(*DataLenPtr >= 2)
    {
      *((IpBase_PortType*)DataPtr) = IPBASE_HTON16(((IpBase_SockAddrInType*)(&TcpIp_SocketList[SockHnd].LocSock))->sin_port);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_parameter */  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      *DataLenPtr = 2;
      RetValue = E_OK;
    }
    break;
#if ((TCPIP_SUPPORT_TCP == STD_ON) && (TCPIP_TCP_DIAG_READ_ACK_SEQ_NUM_ENABLED == STD_ON))
  case TCPIP_DP_SOCKET_TCP_CURRENT_ACK_NUM:
    /* ----------------------------------------------------------------------------------------- */
    /* Read the TCP acknowledgement number that would be used for the next segment for sending */
    if((*DataLenPtr >= 4) && (SockHnd >= TcpIp_VCfgGetMaxNumUdpSocks())  /* PRQA S 3355 */ /* MD_TCPIP_13.7_3355_3358 */
#if ( TCPIP_DEV_ERROR_DETECT == STD_OFF )
      && (SockHnd < TcpIp_VCfgGetMaxNumSocks())
#endif
      )
    {
      TcpIp_TcpIdxType TcpId = (TcpIp_TcpIdxType)((TcpIp_TcpIdxType)SockHnd - (TcpIp_TcpIdxType)TcpIp_VCfgGetMaxNumUdpSocks());
      *((uint32*)DataPtr) = TcpIp_Tcp_RcvNxt[TcpId];  /* dirct access to a TCP variable */  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_parameter */  /* PRQA S 3305 */ /* MD_TCPIP_3305_param */
      RetValue = E_OK;
    }
    break;
  case TCPIP_DP_SOCKET_TCP_NEXT_SEQ_NUM:
    /* ----------------------------------------------------------------------------------------- */
    /* Read the TCP sequence number that would be used for the next data segment for sending. */
    if((*DataLenPtr >= 4) && (SockHnd >= TcpIp_VCfgGetMaxNumUdpSocks())  /* PRQA S 3355, 3358 */ /* MD_TCPIP_13.7_3355_3358 */
#if ( TCPIP_DEV_ERROR_DETECT == STD_OFF )
      && (SockHnd < TcpIp_VCfgGetMaxNumSocks())
#endif
      )
    {
      TcpIp_TcpIdxType TcpId = (TcpIp_TcpIdxType)((TcpIp_TcpIdxType)SockHnd - (TcpIp_TcpIdxType)TcpIp_VCfgGetMaxNumUdpSocks());
      *((uint32*)DataPtr) = TcpIp_Tcp_TxNextSendSeqNo[TcpId];  /* dirct access to a TCP variable */  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_parameter */  /* PRQA S 3305 */ /* MD_TCPIP_3305_struct */
      RetValue = E_OK;
    }
    break;
#endif  /* ((TCPIP_SUPPORT_TCP == STD_ON) && (TCPIP_TCP_DIAG_READ_ACK_SEQ_NUM_ENABLED == STD_ON)) */
  default:  /* PRQA S 2018 */ /* MS_MSR_14.1 */
    /* do nothing */
    break;
  }

  return RetValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */
#endif  /* (STD_ON == TCPIP_SUPPORT_DIAG_ACCESS_EXTENSIONS) */

/***********************************************************************************************************************
 *  Call back functions
 **********************************************************************************************************************/

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
    P2VAR(IpBase_PbufType, AUTOMATIC, TCPIP_APPL_DATA) DataDescPtr )
{
  TcpIp_SockUserIdxType  SoUserIdx;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT, TCPIP_API_ID_RX_INDICATION, TCPIP_E_NOTINIT )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_SOCKIDX(SockIdx), TCPIP_API_ID_RX_INDICATION, TCPIP_E_INV_SOCK_ID )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_PTR(RxSockAddrPtr), TCPIP_API_ID_RX_INDICATION, TCPIP_E_PARAM_POINTER )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_PTR(DataDescPtr), TCPIP_API_ID_RX_INDICATION, TCPIP_E_PARAM_POINTER )
  /* ------------------------------------------------- */

  SoUserIdx = TcpIp_SockUserIdx[SockIdx];
  if(TCPIP_UNDEFINED_SOCK_OWNER_IDX <= SoUserIdx)
  {
    return;
  }

  /* trigger corresponding rx indication */
  TcpIp_RxIndicationFunctions(SoUserIdx, (TcpIp_SocketIdType)SockIdx, (TcpIp_SockAddrType*)RxSockAddrPtr, DataDescPtr->payload, DataDescPtr->len);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 0311 */ /* MD_TCPIP_11.5_0311_ASR */
  if(DataDescPtr->len != DataDescPtr->totLen)
  {
    TcpIp_PbufType *LocPbufPtr = &DataDescPtr[1];
    TcpIp_RxIndicationFunctions(SoUserIdx, (TcpIp_SocketIdType)SockIdx, (TcpIp_SockAddrType*)RxSockAddrPtr, LocPbufPtr->payload, LocPbufPtr->len);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 0311 */ /* MD_TCPIP_11.5_0311_ASR */
  }

  /* consumed length will be ACKed by TcpIp_TcpReceived() later */

  return;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

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
    uint32 DataLenByte )
{
  TcpIp_SockUserIdxType  SoUserIdx;
  const uint32 TxConfLenMax = 0xFFFF;

  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT, TCPIP_API_ID_TX_CONFIRMATION, TCPIP_E_NOTINIT )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_SOCKIDX(SockIdx), TCPIP_API_ID_TX_CONFIRMATION, TCPIP_E_INV_SOCK_ID )
  /* ------------------------------------------------- */

  SoUserIdx = TcpIp_SockUserIdx[SockIdx];
  if(TCPIP_UNDEFINED_SOCK_OWNER_IDX <= SoUserIdx)
  {
    return;
  }

  if(DataLenByte <= TxConfLenMax)
  {
    /* forward confirmation to UL: */
    TcpIp_TxConfirmationFunctions(TcpIp_SockUserIdx[SockIdx], (TcpIp_SockHndType)(SockIdx), (uint16)DataLenByte);
  }
  else
  {
    uint16 TxConfLen;
    uint32 RemainingTxConfLen = DataLenByte;
    while(RemainingTxConfLen != 0)
    {
      /* forward confirmation to UL: */
      if(RemainingTxConfLen > TxConfLenMax)
      {
        TxConfLen = (uint16)TxConfLenMax;
      }
      else
      {
        TxConfLen = (uint16)RemainingTxConfLen;
      }
      TcpIp_TxConfirmationFunctions(TcpIp_SockUserIdx[SockIdx], (TcpIp_SockHndType)(SockIdx), TxConfLen);
      RemainingTxConfLen -= TxConfLen;
    }
  }

  /* decrease buffer fill level: */
  if(0 != DataLenByte)
  {
    TcpIp_TxBufFillLevel[SockIdx] -= (uint16)DataLenByte;
  }
  else
  {
    /* negative TxConfirmation */
    TcpIp_TxBufFillLevel[SockIdx] = 0;
    CANOE_WRITE_STRING("TcpIp_TxConfirmation: negative TxConfirmation")
  }
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

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
  TcpIp_IpAddrStateType State)
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT, TCPIP_API_ID_LOC_IP_ASS_CHG, TCPIP_E_NOTINIT )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_LOCALADDRID(LocalAddrId), TCPIP_API_ID_LOC_IP_ASS_CHG, TCPIP_E_INV_ARG )
  /* ------------------------------------------------- */

  TcpIp_IpAddrAssignmentState[LocalAddrId] = State;

  if(TCPIP_IPADDR_STATE_UNASSIGNED == State)
  {
    TcpIp_VRstCtrl(LocalAddrId);
  }

  TcpIp_LocalIpAssignmentChgFunctions(LocalAddrId, State);
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

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
  uint8 IpCtrlIdx,                 /* PRQA S 3206 */ /* MD_TCPIP_3206 */
  IpBase_FamilyType IpCtrlFamily,  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
  boolean Assigned )               /* PRQA S 3206 */ /* MD_TCPIP_3206 */
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT, TCPIP_API_ID_TRCV_LINK_STATE_CHG, TCPIP_E_NOTINIT )
  /* ------------------------------------------------- */

  TCPIP_UNUSED_PARAMETER(IpCtrlIdx);     /* PRQA S 3112 */ /* MD_MSR_14.2 */
  TCPIP_UNUSED_PARAMETER(IpCtrlFamily);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
  TCPIP_UNUSED_PARAMETER(Assigned);      /* PRQA S 3112 */ /* MD_MSR_14.2 */

}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

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
  uint8 CtrlIdx,  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
  P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockAddrPtr,
  uint16 PathMtuSize )
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid(TCPIP_COND_INIT,                   TCPIP_API_ID_PATH_MTU_CHG, TCPIP_E_NOTINIT )
  TcpIp_CheckDetErrorReturnVoid(TCPIP_COND_VALID_PTR(SockAddrPtr), TCPIP_API_ID_PATH_MTU_CHG, TCPIP_E_PARAM_POINTER )
  /* ------------------------------------------------- */

  TCPIP_UNUSED_PARAMETER(CtrlIdx);  /* PRQA S 3112 */ /* MD_MSR_14.2 */

  /* forward path-MTU callback to TCP */
#if (TCPIP_SUPPORT_TCP == STD_ON)
  TcpIp_Tcp_CbkPathMtuChg(SockAddrPtr, PathMtuSize);
#else
  TCPIP_UNUSED_PARAMETER(SockAddrPtr);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
  TCPIP_UNUSED_PARAMETER(PathMtuSize);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

  /* forward path-MTU callback to TCP */
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

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
  P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) DestAddrPtr )
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT,                           TCPIP_API_ID_ADDR_RES_TIMEOUT, TCPIP_E_NOTINIT )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_LOCALADDRID(LocalAddrId), TCPIP_API_ID_ADDR_RES_TIMEOUT, TCPIP_E_INV_ARG )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_PTR(DestAddrPtr),         TCPIP_API_ID_ADDR_RES_TIMEOUT, TCPIP_E_PARAM_POINTER )
  /* ------------------------------------------------- */

  CANOE_WRITE_STRING_2("TcpIp_Cbk_VAddrResTimeout: function called, LocalAddrId = %d, AddrType = %d", LocalAddrId, DestAddrPtr->sa_family);

  /* check the addr to find out the corresponding socket, then stop the retry mechanism on the socket and indicate an
     error to the user */

#if (TCPIP_SUPPORT_TCP == STD_ON)
  /* check all sockets in TCP */
  TcpIp_Tcp_VAddrResTimeout(DestAddrPtr);
#endif

  /* check all sockets in UDP */
  /* nothing to be done */
  /* There is no stored UDP TxRequest if no ARP resolution was available (and therefore no IP buffer was provided). So
     this function should never be called after all. */

}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

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
  boolean SocketUsesTls )  /* PRQA S 3206 */ /* MD_TCPIP_3206 */
{
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT, TCPIP_API_ID_TCP_STATE_CHG, TCPIP_E_NOTINIT )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_TCPSOCKIDX(SockIdx), TCPIP_API_ID_TCP_STATE_CHG, TCPIP_E_INV_SOCK_ID )
  /* ------------------------------------------------- */

#if (TCPIP_SUPPORT_TLS == STD_OFF)
  TCPIP_UNUSED_PARAMETER(SocketUsesTls);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

  /* check owner of the socket */
  if(TCPIP_UNDEFINED_SOCK_OWNER_IDX <= SoUserIdx)
  {
    /* invalid user idx */
    return;
  }

  if(TCPIP_TCP_STATE_CONN_ESTAB == State)
  {
    TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_CONNECTED;
  }
  else if(TCPIP_TCP_STATE_CONNECTED == State)
  {
    TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_CONNECTED;

#if (TCPIP_SUPPORT_TLS == STD_ON)
    if(SocketUsesTls == TRUE)
    {
      Tls_TcpConnected(SockIdx);
    }
    else
#endif
    {
      TcpIp_TcpConnectedFunctions(SoUserIdx, SockIdx);
    }
  }
  else if(TCPIP_TCP_STATE_CLOSED == State)
  {
    TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_NONE;

#if (TCPIP_SUPPORT_TLS == STD_ON)
    if(SocketUsesTls == TRUE)
    {
      Tls_TcpIpEvent(SockIdx, IPBASE_TCP_EVENT_CLOSED);
      TcpIp_TcpIpEventFunctions(SoUserIdx, SockIdx, IPBASE_TCP_EVENT_CLOSED);
    }
    else
#endif
    {
      TcpIp_TcpIpEventFunctions(SoUserIdx, SockIdx, IPBASE_TCP_EVENT_CLOSED);
    }
  }
  else if(TCPIP_TCP_STATE_RST_REC == State)
  {
    TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_NONE;
#if (TCPIP_SUPPORT_TLS == STD_ON)
    if(SocketUsesTls == TRUE)
    {
      Tls_TcpIpEvent(SockIdx, IPBASE_TCP_EVENT_RESET);
      TcpIp_TcpIpEventFunctions(SoUserIdx, SockIdx, IPBASE_TCP_EVENT_RESET);
    }
    else
#endif
    {
      TcpIp_TcpIpEventFunctions(SoUserIdx, SockIdx, IPBASE_TCP_EVENT_RESET);
    }
  }
  else if(TCPIP_TCP_STATE_CONN_REQ_REC == State)
  {
    /* allways accept the incoming connection, do not forward callback to upper layers */
  }
  else if(TCPIP_TCP_STATE_FIN_REC == State)
  {
    /* remote side starts to close the connection */

#if (TCPIP_SUPPORT_TLS == STD_ON)
    if(SocketUsesTls == TRUE)
    {
      Tls_TcpIpEvent(SockIdx, IPBASE_TCP_EVENT_FIN_RECEIVED);
    }
    else
#endif
    {
      TcpIp_TcpIpEventFunctions(SoUserIdx, SockIdx, IPBASE_TCP_EVENT_FIN_RECEIVED);
    }
  }
  else if(TCPIP_TCP_STATE_CONN_REFUSED == State)
  {
    TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_NONE;
    {
#if (TCPIP_SUPPORT_TLS == STD_ON)
      if(SocketUsesTls == TRUE)
      {
        Tls_TcpIpEvent(SockIdx, IPBASE_TCP_EVENT_RESET);
      }
      else
#endif
      {
        TcpIp_TcpIpEventFunctions(SoUserIdx, SockIdx, IPBASE_TCP_EVENT_RESET);
      }
    }
  }
  else
  {
    /* (TCPIP_TCP_STATE_ACCEPTED == State) should not happen (a separate function is used), all other states are invalid */
    /* nothing to do (required by MISRA) */
  }
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  TcpIp_VSockTcpStateChgAccepted
 **********************************************************************************************************************/
/*! \brief      TCP state change / event Callback.
 *  \description   This function is derived from TcpIp_VSockTcpStateChg but implements a special handling including a return type.
 *  \param[in]  SockIdx               socket index
 *  \param[in]  SoUserIdx             socket user
 *  \return     E_OK                  The user accepted the accepted connection <br>
 *              E_NOT_OK              The user refused the accepted connection
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_VSockTcpStateChgAccepted(
  TcpIp_SockIdxType SockIdx,
  uint8 SoUserIdx )
{
  uint8 ListenSockIdx;
  /* ------------------------------------------------- */
  /* DET: */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT, TCPIP_API_ID_TCP_STATE_CHG, TCPIP_E_NOTINIT, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_SOCKIDX(SockIdx), TCPIP_API_ID_TCP_STATE_CHG, TCPIP_E_INV_SOCK_ID, E_NOT_OK )
  /* ------------------------------------------------- */

  /* check owner of the socket */
  if(TCPIP_UNDEFINED_SOCK_OWNER_IDX <= SoUserIdx)
  {
    /* invalid user idx */
    return E_NOT_OK;
  }

  /* 'SockIdx' is the new derived socket that is used for the TCP connection (not the listen socket!) */
  ListenSockIdx = TcpIp_SocketList[SockIdx].TcpMasterListenSockId;
  TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_CONNECTED;

  return TcpIp_TcpAcceptedFunctions(SoUserIdx, ListenSockIdx, TCPIP_SOCKIDX2SOCKHND(SockIdx), (TcpIp_SockAddrType*)&(TcpIp_SocketList[SockIdx].RemSock));  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */
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
FUNC(void, TCPIP_CODE) TcpIp_VRstCtrl(TcpIp_LocalAddrIdType localAddrId)
{
  TcpIp_SockIdxType sockIdx;

#if (TCPIP_SUPPORT_TCP == STD_ON)
  TcpIp_SockAddrInXType sockAddr;

  (void)TcpIp_GetIpAddr(localAddrId, (TCPIP_P2V(TcpIp_SockAddrType))&sockAddr, NULL_PTR, NULL_PTR);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
#endif

  for (sockIdx = 0; sockIdx < TcpIp_VCfgGetMaxNumSocks(); sockIdx++)
  {
    boolean initSocket = FALSE;

    switch (TcpIp_SockListenActive[sockIdx].ConnStat)
    {
    case TCPIP_SOCK_CONN_LISTEN_ENABLED:
      /* Reset TCP/UDP listen socket if it is bound to the LocalAddrId. */
      if (TcpIp_SocketList[sockIdx].BindLocalAddrId == localAddrId)
      {
#if (TCPIP_SUPPORT_TCP == STD_ON)
        if (sockIdx >= TcpIp_VCfgGetMaxNumUdpSocks())
        {
          TcpIp_Tcp_ResetSocket(sockIdx);
        }
        else
#endif
        {
          TcpIp_Udp_ResetSocket(sockIdx);
        }

        initSocket = TRUE;
      }
      break;

#if (TCPIP_SUPPORT_TCP == STD_ON)
    case TCPIP_SOCK_CONN_CONNECTED:
      if (TcpIp_VSockIpAddrIsEqual((const IpBase_SockAddrType*)(&TcpIp_SocketList[sockIdx].LocSock), (const IpBase_SockAddrType*)&sockAddr) == TRUE)  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
      {
        /* TCP Socket. */
        TcpIp_Tcp_ResetSocket(sockIdx);
        initSocket = TRUE;
      }
      break;
#endif

    default:
      /* Socket not bound or established. -> Nothing to do. */
      break;
    }

    if (initSocket == TRUE)
    {
      TcpIp_VInitSocket(sockIdx);
    }
  }
}

/***********************************************************************************************************************
 *  TcpIp_VIpGetRandNoFct
 **********************************************************************************************************************/
/*! \brief      This API provides a random number to the lower layer (IPv4, IPv6)
 *  \param[in]  void
 *  \return     RandNo              random number
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(uint16, TCPIP_CODE) TcpIp_VIpGetRandNoFct(void )
{
  return TcpIp_GetRandNoFct();
}

/***********************************************************************************************************************
 *  INTERNAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  TcpIp_VPreconfigSocket
 **********************************************************************************************************************/
/*! \brief      pre-configure socket
 *  \param[in]  SockIdx               socket index
 *  \context    initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE)  TcpIp_VPreconfigSocket(TcpIp_SockIdxType SockIdx)
{

  if(TCPIP_ACTIVE_STATE_ONLINE != TcpIp_ActiveState)
  {
    /* do not prepare socket if OFFLINE or IN_SHUTDOWN */
    return;
  }

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  (void)IpBase_DelSockAddr( ((IpBase_SockAddrType *)(&TcpIp_SocketList[SockIdx].RemSock)), IPBASE_AF_INET6 );  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  (void)IpBase_DelSockAddr( ((IpBase_SockAddrType *)(&TcpIp_SocketList[SockIdx].LocSock)), IPBASE_AF_INET6 );  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
#else
  (void)IpBase_DelSockAddr( ((IpBase_SockAddrType *)(&TcpIp_SocketList[SockIdx].RemSock)), IPBASE_AF_INET );  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  (void)IpBase_DelSockAddr( ((IpBase_SockAddrType *)(&TcpIp_SocketList[SockIdx].LocSock)), IPBASE_AF_INET );  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
#endif

  TcpIp_SockUserIdx[SockIdx]               = TCPIP_UNDEFINED_SOCK_OWNER_IDX;

#if (TCPIP_SUPPORT_TCP == STD_ON)
  if(TcpIp_VCfgGetMaxNumUdpSocks() <= SockIdx)
  {
    /* TCP */
    TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_NONE;
  }
  else
#endif  /* (STD_ON == TCPIP_SUPPORT_TCP) */
  {
    /* UDP */
    TcpIp_SockListenActive[SockIdx].ConnStat = TCPIP_SOCK_CONN_NONE;
  }
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_VNetAddrIsUnicast
 **********************************************************************************************************************/
/*! \brief          Check whether the given SockAddr is a unicast address
 *  \description
 *  \param[in]      SockAddrPtr      Socket address containing the IP address
 *  \return         TRUE             The socket address contains a unicast IP address
 *  \return         FALSE            The socket address does not contain a unicast IP address
 *  \note           -
 *  \context        task level
 **********************************************************************************************************************/
FUNC(boolean, TCPIP_CODE) TcpIp_VNetAddrIsUnicast(
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockAddrPtr )
{
  boolean RetVal;

  switch(SockAddrPtr->sa_family)
  {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
  case IPBASE_AF_INET:
    {
      /* socket address struct is always filled in network byte order */
      TcpIp_NetAddrType SockNetAddr = (((const IpBase_SockAddrInType*)SockAddrPtr)->sin_addr);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */

      if( (0 != SockNetAddr) /* invalid global '0' address */ &&
          (!IPV4_ADDR_IS_MULTICAST(SockNetAddr)) /* multicast address */ &&
          (SockNetAddr != TCPIP_INADDR_BROADCAST) /* global broadcast */
          /* subnet broadcasts can not be detected here */ )
      {
        RetVal = TRUE;
      }
      else
      {
        RetVal = FALSE;
      }
      break;
    }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  case IPBASE_AF_INET6:
    {
      const uint8 *FirstBytePtr;  /* first by of the address (network byte order) */

      FirstBytePtr = (const uint8*)(&(((const IpBase_SockAddrIn6Type*)SockAddrPtr)->sin6_addr));  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_compare */  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      if( (*FirstBytePtr  != 0xFF) )
      {
        RetVal = TRUE;
      }
      else
      {
        RetVal = FALSE;
      }
      break;
    }
#endif
  default:
    {
      RetVal = FALSE;  /* no valid domain type */
      break;
    }
  }

  return RetVal;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_VSocketAccessExclusive()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(boolean, TCPIP_CODE) TcpIp_VSocketAccessExclusive(TcpIp_SocketIdType socketId)
{
  boolean retVal;

  /* check if buffer is already requested */
  TCPIP_VENTER_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */  /* lock interrupts */
  
  if (TcpIp_TxBufRequested[socketId] == TRUE)
  {
    /* buffer is already locked by a previous call of ProvideTxBuffer() */
    retVal = FALSE;
  }
  else
  {
    TcpIp_TxBufRequested[socketId] = TRUE;
    retVal = TRUE;
  }
  TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */  /* unlock interrupts */
  
  return retVal;
} /* TcpIp_VSocketAccessExclusive() */

#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*
   MICROSAR global MISRA deviations:
   - see file 'WI_MISRA_Compliance_MSR.pdf'

   module specific MISRA deviations:
   MD_TCPIP_14.5_0770: A continue statement has been used.
     Reason:     Avoiding continue statement here would decrease the code readability.
     Risk:       None.
     Prevention: Covered by code review.
   MD_TCPIP_1.1_0857:
     Reason:     Number of macro definitions is huge but improves readablitiy. (rule 0857)
     Risk:       Some compilers might have a problem with too many macro definitions.
     Prevention: Use only compilers supporting more than 1024 macro definitions.
   MD_MSR_5.1_777_779:
     Reason:     A generated set of buffers uses the same name for all buffers and just appends a numbering suffix
     Risk:       None, since these buffers are not used manually but only used as elements in a generated array of
                 buffer pointers.
     Prevention: None.
   MD_TCPIP_5.6_0781:
     Reason:     Readability is increased by using well known names.
     Risk:       Elements can be confused with each other.
     Prevention: Covered by code review.
   MD_TCPIP_6.3_5013:
     Reason:     Usage of basic types is defined in SWS_SoAd
     Risk:       problem with different platforms
     Prevention: not possible
   MD_TCPIP_8.12_3684:
     Reason:     The arrays in file TcpIp_PBcfg.h and TcpIp_Lcfg.h are declared as extern without size specification
                 since their size depend on the configuration (e.g. in GENy).
     Risk:       There is no risk because these arrays are only used by TcpIp.
     Prevention: Covered by code review.
   MD_TCPIP_11.4_0310_sock:
     Reason:     IpBase_SockAddrType includes address family to differ between IPv4 and IPv6. The corresponding
                 structs also start with the family field so casting is possible.
     Risk:       Only casting from IpBase_SockAddrInType or IpBase_SockAddrIn6Type to IpBase_SockAddrType is allowed.
     Prevention: Covered by code review.
   MD_TCPIP_11.4_0310_copy:
     Reason:     The copy function uses a different base type as the local element.
     Risk:       The copy function might cause access problems on some platforms if elements are not aligned properly.
     Prevention: Covered by code review.
   MD_TCPIP_11.4_0310_compare:
     Reason:     The compare function uses a different base type as the local element.
     Risk:       The compare function might cause access problems on some platforms if elements are not aligned properly.
     Prevention: Covered by code review.
   MD_TCPIP_11.4_0310_struct:
     Reason:     Struct-mapping on a byte array element (e.g. a stream)
     Risk:       This might cause access problems on some platforms if elements are not aligned properly.
     Prevention: Covered by code review.
   MD_TCPIP_11.4_0310_parameter:
     Reason:     An API uses a uint8 array to forward data to the function, and depending on another parameter (e.g. ParameterId) the data is interpreted in different ways.
     Risk:       This might cause access problems on some platforms if the data pointer is not set properly.
     Prevention: Covered by code review.
   MD_TCPIP_11.4_0310_x:
     Reason:     others
     Risk:       not analyzed
     Prevention: Covered by code review.
   MD_TCPIP_11.5_0311_ASR:
     Reason:     AUTOSAR does not specify a const qualifier, so the const attribute has to be removed by a type cast
     Risk:       A user might try to access and change the struct, but this would not be detected during compile time
     Prevention: Covered by code review.
   MD_TCPIP_12.4_3415:
     Reason:     A concatenation of conditions may break without checking the later conditions if a previous one
                 already failed.
     Risk:       The concatenation of conditions might have a different effect as expected.
     Prevention: Covered by code review.
   MD_TCPIP_13.7_3355_3358:
     Reason:     This condition is always true only in case Det is enabled. To protect code against stack corruption
                 in case Det is disabled this if condition is added.
     Risk:       No risk.
     Prevention: Covered by code review.
   MD_TCPIP_13.7_3356_3359:
     Reason:     This condition is always false only in case Det is enabled. To protect code against stack corruption
                 in case Det is disabled this if condition is added.
     Risk:       No risk.
     Prevention: Covered by code review.
   MD_TCPIP_18.4_0759:
     Reason:     Unions shall not be used. Here a union is used to enable efficient access to the address data.
     Risk:       using unions has to be done very carefully since data might be misinterpreted.
     Prevention: Covered by code review.
   MD_TCPIP_19.11_3332:
     Reason:     A concurrent chain of preprocessor-checks connected with 'AND' can be stopped when a check fails, the
                 following checks can be omitted
     Risk:       Checks could be combined in a different way as expected
     Prevention: Covered by code review.
   MD_TCPIP_19.15_0883:
     Reason:     QA-C MISRA checker does not recognize the protection against multiple header include correctly.
     Risk:       No Risk.
     Prevention: Covered by code review.
   MD_TCPIP_21.1_3382:
     Reason:     The socket index of a TCP socket has always a higher or equal value than the number of UDP socket,
                 since the consecutive null-based list of sockets starts with UDP sockets followed by TCP sockets
     Risk:       The macro TCPIP_SOCKIDX2TCPIDX would cause an index wrap-around if it is used for UDP sockets, but the
                 macro is only meant to be used for TCP sockets (as the macro's name implies)
     Prevention: Covered by code review.
   MD_TCPIP_3199:
     Reason:     Dummy statement to avoid compiler warnings.
     Risk:       There is no risk as such statements have no effect on the code.
     Prevention: Covered by code review.
   MD_TCPIP_3205:
      Reason:     The defined type is only used in some configurations.
      Risk:       There is no risk.
      Prevention: Covered by code review.
   MD_TCPIP_3206:
      Reason:     API parameter is only used in some configurations.
      Risk:       There is no risk.
      Prevention: Covered by code review.
   MD_TCPIP_3305:
     Reason:     The different socket address types do all base on the same structure, the alignment should always be
                 the same so that mapping from one type to an other one should not be a problem.
     Risk:       Only casting between different variants of the socket type is allowed.
     Prevention: Covered by code review.
   MD_TCPIP_3305_param:
     Reason:     The API transfers parameters of different types but points to them using an uint8 pointer and a
                 parameter ID. The parameter type is specified for each parameter ID, so no false alignments should
                 occur.
     Risk:       Parameters could be casted to the wrong type accidently.
     Prevention: Covered by code review.
   MD_TCPIP_3305_struct:
     Reason:     TcpIp protocol headers are mapped to data arrays. The arrays should usually be aligned correctly.
     Risk:       Arrays could be misaligned accidently.
     Prevention: Covered by code review.
  MD_TCPIP_3198:
      Reason:     The parameter is used after this manipulation only in some configurations.
      Risk:       There is no risk.
      Prevention: Covered by code review.

   TCPIP-specific deviations:
   MD_TCPIP_16.7_3673:
     Reason:     Pointer could be const, but API has to be AUTOSAR-conform
     Risk:       Function could try to change the element the pointer points to, but this should not be allowed.
     Prevention: Covered by code review.
   MD_TCPIP_21.1_3689_arrayusage:
     Reason:     The array access cannot be out of bounds because only the defined enumerations for the address family are used
     Risk:       n/a
     Prevention: reviews and tests ensure the valid usage
*/

/**********************************************************************************************************************
 *  END OF FILE: TcpIp.c
 *********************************************************************************************************************/
