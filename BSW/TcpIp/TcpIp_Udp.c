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
 *         \file  TcpIp_Udp.c
 *        \brief  Implementation of User Datagram Protocol (UDP)
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

#define TCPIP_UDP_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_Cfg.h"
#include "TcpIp_Udp.h"
#include "TcpIp_Lcfg.h"
#include "TcpIp_Udp_Cbk.h"
#include "TcpIp_Priv.h"
#include "TcpIp_Cbk.h"
#include "IpBase.h"
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# include "TcpIp_IpV4.h"
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
# include "TcpIp_IpV6.h"
#endif
#include "IpBase_Copy.h"
#include "IpBase_Sock.h"

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# if (IPV4_ADDR_ID_ANY != TCPIP_IP_ADDR_ID_ANY)
#  error "Error: IPV4_ADDR_ID_ANY != TCPIP_IP_ADDR_ID_ANY"
# endif
#endif

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
# if (IPV6_ADDR_ID_ANY != TCPIP_IP_ADDR_ID_ANY)
#  error "Error: IPV6_ADDR_ID_ANY != TCPIP_IP_ADDR_ID_ANY"
# endif
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if defined (STATIC)
#else
# define STATIC static
#endif

#define TCPIP_UDP_EMPTY_PORT     0x0000u
#define TCPIP_UDP_EMPTY_CHKSUM   0x0000u

#define TCPIP_UDP_HDR_LEN_BYTE        8u

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#define TCPIP_UDP_INC_TXQUEUE_WRITE_POS()        TcpIp_Udp_TxQueueWritePos = (uint8)(TcpIp_Udp_TxQueueWritePos +1u) & (uint8)((TcpIp_Udp_VCfgGetMaxTxQueueSize())-1u)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
  uint8                *IpPayloadPtr;  /* pointer to the IP payload */
  TcpIp_SockIdxType     SockIdx;
  uint16                DataLenByte;  /* first Pbuf element length */
  TcpIp_SockAddrInXType Dest;
  uint8                 BufIdx;
  uint8                 UdpTxReqTabIdx;
} TcpIp_Udp_TxReqType;

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
#define TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( defined TCPIP_ENABLE_INT_DEBUG_COUNTERS )
STATIC VAR(uint32, TCPIP_VAR_NOINIT) TcpIp_Udp_RxIndCounter;
STATIC VAR(uint32, TCPIP_VAR_NOINIT) TcpIp_Udp_TransmitCounter;
#endif  /* ( defined TCPIP_ENABLE_INT_DEBUG_COUNTERS ) */

#define TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VSendMsg(
    P2CONST(TcpIp_Udp_TxReqType, TCPIP_APPL_DATA, TCPIP_CONST) TxReqPtr,
    boolean                                                    IsRetryAttempt,
    uint8                                                      RetrQueueListIdx);

STATIC FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_Udp_CancelIpTransmit(
    TcpIp_SockIdxType                                                 SockIdx,
    P2VAR(TcpIp_IpTxRequestDescriptorType, AUTOMATIC, TCPIP_APPL_VAR) TxReqDescrPtr,
    TcpIp_DomainType                                                  Domain,
    uint8                                                             UlTxReqTabIdx );

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  TcpIp_Udp_Init
 **********************************************************************************************************************/
/*! \brief      This API call stores the start address of the post build time configuration of the User Datagram
 *              Protocol and may be used to initialize the data structures.
 *  \param[in]  CfgPtr             pointer to module configuration
 *  \note       No configuration variant support implemented, so only TCPIP_CONFIG_VARIANT_1 (compile time) is available.
 *  \context    initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Udp_Init( void )
{
  TcpIp_SockIdxType SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  uint8 TxReqListIdx;
#endif

#if ( defined TCPIP_ENABLE_INT_DEBUG_COUNTERS )
  /* Debug variables: */
  TcpIp_Udp_RxIndCounter = 0;
  TcpIp_Udp_TransmitCounter = 0;
#endif
  /* TCPIP_DEV_ERROR_DETECT == STD_ON */

  TcpIp_Udp_DynamicPortCount = 0;

#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  for(TxReqListIdx = 0; TcpIp_VCfgGetUdpTxReqListNum() > TxReqListIdx; TxReqListIdx++)
  {
    TcpIp_Udp_TxReqListFillNum[TxReqListIdx]         = 0;
    TcpIp_Udp_TxReqListWritePos[TxReqListIdx]        = 0;
    TcpIp_Udp_TxReqListReadPos[TxReqListIdx]         = 0;
    TcpIp_Udp_TxReqList_IsUsedBySocket[TxReqListIdx] = TCPIP_INV_SOCK_IDX;
  }
#endif

  for(SockIdx = 0; ((TcpIp_SockIdxType)TcpIp_VCfgGetMaxNumUdpSocks()) > SockIdx; SockIdx++)
  {
#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
    TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx] = 0xFF;  /* invalid index */
#endif
  }

#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
  TcpIp_DListInitDesc(&TcpIp_Udp_TxRetrQueuePoolDesc, &TcpIp_Udp_TxRetrQueueElementChain[0], TCPIP_UDP_TX_RETRY_QUEUE_NUM_TOTAL);
  for(SockIdx = 0; ((TcpIp_SockIdxType)TcpIp_VCfgGetMaxNumUdpSocks()) > SockIdx; SockIdx++)
  {
    TcpIp_DListInit(&TcpIp_Udp_TxRetrQueueForSock[SockIdx], &TcpIp_Udp_TxRetrQueuePoolDesc);
    TcpIp_Udp_TxRetrQueueMaxNum[SockIdx] = TCPIP_UDP_TX_RETRY_QUEUE_NUM_TOTAL;  /* init with size TCPIP_UDP_TX_RETRY_QUEUE_NUM_TOTAL, can be changed or disables using SetSocketOption */
  }
#endif

  return;
}

/***********************************************************************************************************************
 *  TcpIp_Udp_CloseSocket
 **********************************************************************************************************************/
/*! \brief      This API call closes the UDP socket and resets all relevant internal variables.
 *  \param[in]  SockIdx             socket index
 *  \note
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Udp_CloseSocket(
    TcpIp_SocketIdType SockIdx )
{
  /* ------------------------------------------------- */
  /* DET */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT,                      TCPIP_UDP_API_ID_CLOSE_SOCKET, TCPIP_E_NOTINIT )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_UDPSOCKIDX(SockIdx), TCPIP_UDP_API_ID_CLOSE_SOCKET, TCPIP_E_INV_SOCK_ID )
  /* ------------------------------------------------- */

#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  {
    if(TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx] != 0xFF)  /* TxConfirmation is enabled */
    {
      uint8 TxReqListIdx;

      /* reset variables */
      TxReqListIdx = TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx];

      TcpIp_Udp_TxReqListFillNum[TxReqListIdx]         = 0;
      TcpIp_Udp_TxReqListWritePos[TxReqListIdx]        = 0;
      TcpIp_Udp_TxReqListReadPos[TxReqListIdx]         = 0;
      TcpIp_Udp_TxReqList_IsUsedBySocket[TxReqListIdx] = TCPIP_INV_SOCK_IDX;

      TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx] = 0xFF;  /* invalid index */
    }
    else
    {
      /* nothing to do */
    }
  }
#endif

#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)

  if(!TCPIP_DLIST_IS_EMPTY(TcpIp_Udp_TxRetrQueueForSock[SockIdx]))
  {
    /* cancel transmit of all retry elements for this socket (release ethernet buffers) */
    TcpIp_DListIdxType ListIdx = TcpIp_Udp_TxRetrQueueForSock[SockIdx].FirstIdx;

    while (TCPIP_DLIST_END_IDX != ListIdx)
    {
      (void)TcpIp_Udp_CancelIpTransmit(SockIdx, &TcpIp_Udp_TxRetrQueueElements[ListIdx].TxRequestDesc, ((TCPIP_P2C(TcpIp_SockAddrType))&TcpIp_Udp_TxRetrQueueElements[ListIdx].Destination)->domain, 0);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */

      TCPIP_DLIST_SET_NEXT(ListIdx, TcpIp_Udp_TxRetrQueueForSock[SockIdx]);
    }
  }

  TcpIp_DListClear(&TcpIp_Udp_TxRetrQueueForSock[SockIdx]);
  TcpIp_Udp_TxRetrQueueMaxNum[SockIdx] = TCPIP_UDP_TX_RETRY_QUEUE_NUM_TOTAL;  /* init with size TCPIP_UDP_TX_RETRY_QUEUE_NUM_TOTAL, can be changed or disables using SetSocketOption */
#endif
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_Udp_RxIndication
 **********************************************************************************************************************/
/*! \brief         Receive Indication
 *  \param[in]     LocalAddrId           local address identifier
 *  \param[in]     RxSockRemAddrPtr      pointer to the remote socket address
 *  \param[in]     DataPtr               pointer to the received data
 *  \param[in]     LenByte               length of received data in bytes
 *  \param[in]     ChecksumCalculated    indicates if the UDP checksum is already checked by lower layer
 *  \context       interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Udp_RxIndication(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RxSockRemAddrPtr,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr,
    uint16 LenByte
#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
    , boolean ChecksumCalculated
#endif
    )
{
  TcpIp_Udp_HdrType *HdrPtr;
  TcpIp_SockIdxType SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
  TcpIp_SockAddrInXType RxSockLocAddr;
  P2VAR(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_VAR) RxSockLocAddrPtr = (IpBase_SockAddrType*)&RxSockLocAddr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */

  /* ------------------------------------------------- */
  /* DET */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT, TCPIP_UDP_API_ID_RX_INDICATION, TCPIP_E_NOTINIT )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_LOCALADDRID(LocalAddrId), TCPIP_UDP_API_ID_RX_INDICATION, TCPIP_E_INV_ARG )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_PTR(RxSockRemAddrPtr), TCPIP_UDP_API_ID_RX_INDICATION, TCPIP_E_PARAM_POINTER )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_PTR(DataPtr), TCPIP_UDP_API_ID_RX_INDICATION, TCPIP_E_PARAM_POINTER )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_MIN_SIZE(LenByte, TCPIP_UDP_HDR_LEN_BYTE), TCPIP_UDP_API_ID_RX_INDICATION, TCPIP_E_INV_ARG )
  /* ------------------------------------------------- */

#if ( defined TCPIP_ENABLE_INT_DEBUG_COUNTERS )
  /* Debug variable: */
  TcpIp_Udp_RxIndCounter++;
#endif
  /* TCPIP_DEV_ERROR_DETECT == STD_ON */

  if (E_OK != TcpIp_GetIpAddr(LocalAddrId, (TcpIp_SockAddrType*)RxSockLocAddrPtr, NULL_PTR, NULL_PTR))  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  {
    return;
  }

  HdrPtr = (TcpIp_Udp_HdrType *) DataPtr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
  if ( TCPIP_UDP_HDR_LEN_BYTE < LenByte )
  {
    uint16 HdrLenByte = IPBASE_HTON16(HdrPtr->LenByte);
    if ((HdrLenByte > TCPIP_UDP_HDR_LEN_BYTE) && (HdrLenByte <= LenByte))
    {
#if (TCPIP_UDP_CHECK_RX_CHECKSUM == STD_ON)

#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
      if(ChecksumCalculated == TRUE)
      {
        /* The UDP checksum was already checked by the lower layer / hardware. If the checksum was wrong the packet will not reach the UDP at all, so no further check is necessary here. */
      }
      else
      {
#endif
        /* check the received UDP checksum */
        if(0 != HdrPtr->Checksum)
        {
          uint16_least Checksum;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

          Checksum = (uint16_least)TcpIp_VCalcPseudoHdrAndChecksum( ((const IpBase_SockAddrType*)(RxSockRemAddrPtr)),
            ((const IpBase_SockAddrType*)(RxSockLocAddrPtr)), (const uint8 *)HdrPtr, LenByte, TCPIP_SOCK_PROT_UDP);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */

          /* If the calcukated checksum on the sender side was 0 and transmitted as 0xFFFF
          no special treatment on receiver side is necessary. */
          if(0 == Checksum)
          {
            /* checksum is valid -> OK */
          }
          else
          {
            /* checksum is invalid -> drop message silently */
            return;
          }
        }
        else
        {
          /* UDP checksum in received packet is deactivated -> OK */
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
          if(IPBASE_AF_INET6 == RxSockRemAddrPtr->sa_family)
          {
            /* for IpV6 the checksum is mandatory -> drop the message */
            return;
          }
#endif
        }
#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
      }
#endif

#endif /* TCPIP_UDP_CHECK_RX_CHECKSUM */

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
      if(IPBASE_AF_INET == RxSockRemAddrPtr->sa_family)
#endif
      {
        ((IpBase_SockAddrInType*)RxSockLocAddrPtr)->sin_port = HdrPtr->TgtPort;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
        ((IpBase_SockAddrInType*)RxSockRemAddrPtr)->sin_port = HdrPtr->SrcPort;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      }
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
      else
#endif
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
      {
        ((IpBase_SockAddrIn6Type*)RxSockLocAddrPtr)->sin6_port = HdrPtr->TgtPort;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
        ((IpBase_SockAddrIn6Type*)RxSockRemAddrPtr)->sin6_port = HdrPtr->SrcPort;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      }
#endif

      SockIdx = TcpIp_VRxUdpSockIdxIdent(RxSockLocAddrPtr, LocalAddrId);  /* Identify socket */

      if(TCPIP_INV_SOCK_IDX == SockIdx)
      {
        /* there is no corresponding socket found -> drop message, or send ICMP message */
        return;
      }

      /* proceed message handling */
      {
        uint16 udpPayloadLen = (uint16)(LenByte - TCPIP_UDP_HDR_LEN_BYTE);
        /* ASR-API */
        /* forward message to upper layer (socket) */

        IpBase_PbufType DataDesc;
        DataDesc.payload = (uint8*) (&(HdrPtr[1]));  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */
        DataDesc.len     = udpPayloadLen;
        DataDesc.totLen  = udpPayloadLen;

        TcpIp_VSockRxIndicationAsr42x( SockIdx, (const IpBase_SockAddrType *)RxSockRemAddrPtr, &DataDesc );
      }
    }
  }
  return;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  TcpIp_Udp_RequestTxBuffer
 **********************************************************************************************************************/
/*! \brief         Provides a UDP TX buffer.
 *  \details       This function calls the ProvideTxBuffer service of the IP layer (IPv4 or IPv6) based on the destination
 *                 address and retuns a buffer for the UDP payload.
 *  \param[in]     SockIdx               UDP socket index.
 *  \param[in]     DestinationPtr        Pointer to the destination socket address.
 *  \param[out]    BufPtr                Pointer to the (first) UDP payload buffer.
 *  \param[in,out] BufLenPtr             In:  Length of the UDP payload in bytes.
 *                                       Out: Length of the first UDP payload buffer in bytes (see notes).
 *  \return        BUFREQ_OK             Buffer prepared.
 *  \return        BUFREQ_E_NOT_OK       Buffer could not be provided.
 *  \return        BUFREQ_E_BUSY         IP layer is currently not able to provide buffer. Try again later.
 *  \note                                If IPv4 is used this function may provide more than one buffer if the requested
 *                                       payload size is too large to fit into one IP packet. In that case only the first
 *                                       buffer fragment is returned by this function. The additional buffer fragments
 *                                       can be obtained via TcpIp_Udp_RequestNextTxBufferFragment().
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 **********************************************************************************************************************/
FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_Udp_RequestTxBuffer(
    TcpIp_SockIdxType                                         SockIdx,
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA)  DestinationPtr,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA)                 *BufPtr,
    P2VAR(uint16, AUTOMATIC, TCPIP_APPL_VAR)                  BufLenPtr)
{
  uint8*            IpBufferPtr;
  uint8*            UdpPayloadPtr;
  uint16            IpBufferLen;
  BufReq_ReturnType BufRetValue;
  boolean           ForceProvidePuffer;

  /* ------------------------------------------------- */
  /* DET */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                      TCPIP_UDP_API_ID_REQUEST_TX_BUFFER, TCPIP_E_NOTINIT,       BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_UDPSOCKIDX(SockIdx), TCPIP_UDP_API_ID_REQUEST_TX_BUFFER, TCPIP_E_INV_SOCK_ID,   BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(DestinationPtr), TCPIP_UDP_API_ID_REQUEST_TX_BUFFER, TCPIP_E_PARAM_POINTER, BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(BufPtr),         TCPIP_UDP_API_ID_REQUEST_TX_BUFFER, TCPIP_E_PARAM_POINTER, BUFREQ_E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(BufLenPtr),      TCPIP_UDP_API_ID_REQUEST_TX_BUFFER, TCPIP_E_PARAM_POINTER, BUFREQ_E_NOT_OK )
  /* ------------------------------------------------- */

#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  if(TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx] != 0xFF)  /* TxConfirmation is enabled */
  {
    uint8 TxReqListIdx = TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx];

    /* find free TcpIp_Udp_TxReqTab element. */
    if(TcpIp_Udp_TxReqListFillNum[TxReqListIdx] == TcpIp_Udp_VCfgGetTxReqListSize(TxReqListIdx))
    {
      /* TcpIp_Udp_TxReqList is full */
      return BUFREQ_E_BUSY;
    }
  }
#endif

  /* there is a valid free request table element available */
  /* -> check if IP can provide a buffer / has already resolved the address */

  IpBufferLen = (*BufLenPtr) + TCPIP_UDP_HDR_LEN_BYTE;

#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
  if(TcpIp_Udp_TxRetrQueueMaxNum[SockIdx] != 0)
  {
    ForceProvidePuffer = TRUE;
  }
  else
#endif
  {
    ForceProvidePuffer = FALSE;
  }

  switch(DestinationPtr->sa_family)
  {
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
  case IPBASE_AF_INET:
    {
      IpV4_AddrIdType IpAddrId = TcpIp_SocketList[SockIdx].TxIpAddrId;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

      BufRetValue = IpV4_Ip_ProvideTxBuffer(&IpAddrId, SockIdx, (const IpBase_SockAddrInType*) DestinationPtr, &IpBufferPtr, &IpBufferLen,  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
        &TcpIp_Udp_IpTxRequestDescriptor[SockIdx], ForceProvidePuffer);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
      TcpIp_Udp_TxLocIpAddrId[SockIdx] = (TcpIp_GlobalIpAddrIdType)IpAddrId;
      break;
    }
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  case IPBASE_AF_INET6:
    {
      IpV6_AddrIdType IpAddrId = TcpIp_SocketList[SockIdx].TxIpAddrId;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

      BufRetValue = IpV6_ProvideTxBuffer(&IpAddrId, SockIdx, (const IpV6_AddrType*)&(((const IpBase_SockAddrIn6Type*)DestinationPtr)->sin6_addr), &IpBufferPtr, &IpBufferLen,  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
        &TcpIp_Udp_IpTxRequestDescriptor[SockIdx], ForceProvidePuffer);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
      TcpIp_Udp_TxLocIpAddrId[SockIdx] = (TcpIp_GlobalIpAddrIdType)IpAddrId;
      break;
    }
#endif
  default:
    {
      /* invalid address family */
      return BUFREQ_E_NOT_OK;
    }
  }

  if(BUFREQ_OK == BufRetValue)
  {
    (*BufLenPtr)  = (uint16)(IpBufferLen - TCPIP_UDP_HDR_LEN_BYTE);
    UdpPayloadPtr = &IpBufferPtr[TCPIP_UDP_HDR_LEN_BYTE];
    *BufPtr = UdpPayloadPtr;
    TcpIp_Udp_TxReqIpBufIdx[SockIdx] = TcpIp_Udp_IpTxRequestDescriptor[SockIdx].BufIdx;
    TcpIp_Udp_TxReqIpBufPtr[SockIdx] = IpBufferPtr;
  }

  return BufRetValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *  TcpIp_Udp_RequestNextTxBufferFragment
 **********************************************************************************************************************/
/*! \brief       Provides an additional UDP TX buffer fragment.
 *  \details     TcpIp_Udp_RequestTxBuffer() may return a buffer that is smaller than the requested length.
 *               In that case additional buffer fragments can be obtained via this function.
 *  \param[in]   SockIdx                Index of the UDP socket.
 *  \param[in]   AddrFamily             Address Family of destination used at previous TcpIp_Udp_RequestTxBuffer() call.
 *  \param[out]  BufPtrPtr              Pointer to the next UDP buffer fragment.
 *  \param[out]  BufLenPtr              Length of the next UDP buffer fragment in bytes.
 *  \pre         TcpIp_Udp_RequestTxBuffer() must be called first.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_RequestNextTxBufferFragment(
  TcpIp_SockIdxType   SockIdx,
  IpBase_FamilyType   AddrFamily,
  TCPIP_P2V(uint8)   *BufPtrPtr,
  TCPIP_P2V(uint16)   BufLenPtr)
{
  Std_ReturnType RetVal;

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
  if (IPBASE_AF_INET == AddrFamily)
  {
    RetVal = IpV4_Ip_ProvideNextTxBuffer(&TcpIp_Udp_IpTxRequestDescriptor[SockIdx], BufPtrPtr, BufLenPtr);
  }
  else
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  if (IPBASE_AF_INET6 == AddrFamily)
  {
    TCPIP_UNUSED_PARAMETER(SockIdx);    /* PRQA S 3112 */ /* MD_MSR_14.2 */
    TCPIP_UNUSED_PARAMETER(BufPtrPtr);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
    TCPIP_UNUSED_PARAMETER(BufLenPtr);  /* PRQA S 3112 */ /* MD_MSR_14.2 */

    /* IPv6 does not provide multiple TX buffer fragments */
    RetVal = E_NOT_OK;
  }
  else
#endif
  {
    TCPIP_UNUSED_PARAMETER(SockIdx);    /* PRQA S 3112 */ /* MD_MSR_14.2 */
    TCPIP_UNUSED_PARAMETER(BufPtrPtr);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
    TCPIP_UNUSED_PARAMETER(BufLenPtr);  /* PRQA S 3112 */ /* MD_MSR_14.2 */

    /* Unsupported address family/protocol. */
    RetVal = E_NOT_OK;
  }

  return RetVal;
} /* TcpIp_Udp_RequestNextTxBufferFragment() */

/***********************************************************************************************************************
 *  TcpIp_Udp_TransmitAsr
 **********************************************************************************************************************/
/*! \brief      AUTOSAR Transmission Request
 *  \param[in]  SockIdx               socket index
 *  \param[in]  PbufPtr               pointer to tx data
 *  \param[in]  Destination           destination socket address
 *  \return     E_OK                  buffer prepared
 *  \return     E_NOT_OK              preparing buffer failed
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_TransmitAsr(
    TcpIp_SockIdxType SockIdx,
    P2CONST(IpBase_PbufType, TCPIP_APPL_DATA, TCPIP_CONST) PbufPtr,
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) DestinationPtr )
{
  TcpIp_Udp_TxReqType CurTxReq;  /* current tx request */
  Std_ReturnType      RetValue;
#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  uint8                   GlobTxReqTabIdx;
  TcpIp_Udp_TxReqEleType *TxReqListElePtr = NULL_PTR;  /* Initialize variable to avoid compiler warnings. The variable will be initialized properly before usage! */
  uint8                   TxReqListIdx;
#endif
  /* ------------------------------------------------- */
  /* DET */
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_INIT,                      TCPIP_UDP_API_ID_TRANSMIT_ASR, TCPIP_E_NOTINIT,       E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_UDPSOCKIDX(SockIdx), TCPIP_UDP_API_ID_TRANSMIT_ASR, TCPIP_E_INV_SOCK_ID,   E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(PbufPtr),        TCPIP_UDP_API_ID_TRANSMIT_ASR, TCPIP_E_PARAM_POINTER, E_NOT_OK )
  TcpIp_CheckDetErrorReturnValue( TCPIP_COND_VALID_PTR(DestinationPtr), TCPIP_UDP_API_ID_TRANSMIT_ASR, TCPIP_E_PARAM_POINTER, E_NOT_OK )
  /* ------------------------------------------------- */

#if ( defined TCPIP_ENABLE_INT_DEBUG_COUNTERS )
  TcpIp_Udp_TransmitCounter++;  /* for debugging purposes only */
#endif
  /* TCPIP_DEV_ERROR_DETECT == STD_ON */

  /* check if transmit shall be canceled */
  if((PbufPtr->totLen == 0) && (PbufPtr->len != 0))
  {
    /* inconsistent length encoding -> this indicates that the transmission of the packet shall be canceled */
    /* free the IP buffer without sending a packet by calling Transmit with Length '0' */

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
    if(IPBASE_AF_INET == DestinationPtr->sa_family)
#endif
    {
      (void)IpV4_Ip_Transmit(SockIdx, &TcpIp_Udp_IpTxRequestDescriptor[SockIdx], 0, TCPIP_PROTOCOL_UDP, ((const IpBase_SockAddrInType *)DestinationPtr)->sin_addr, FALSE, 0, FALSE);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */  /* PRQA S 3305 */ /* MD_TCPIP_3305 */
      return E_OK;
    }
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
    else
#endif
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
    {
      (void)IpV6_Transmit(SockIdx, &TcpIp_Udp_IpTxRequestDescriptor[SockIdx], TCPIP_PROTOCOL_UDP, 0, FALSE, 0, FALSE);
      return E_OK;
    }
#endif
  }

  TCPIP_VENTER_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* store values in TcpIp_Udp_TxReqTab */

  /* prepare struct to send message */
  CurTxReq.BufIdx           = TcpIp_Udp_TxReqIpBufIdx[SockIdx];
  CurTxReq.DataLenByte      = PbufPtr->len;
  (void)IpBase_CopySockAddr( ((IpBase_SockAddrType *)&CurTxReq.Dest), DestinationPtr);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
  CurTxReq.IpPayloadPtr     = TcpIp_Udp_TxReqIpBufPtr[SockIdx];
  CurTxReq.SockIdx          = SockIdx;

#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  TxReqListIdx = TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx];

  if(TxReqListIdx != 0xFF)  /* TxConfirmation is enabled */
  {
    /* take free TcpIp_Udp_TxReqList element. */
    GlobTxReqTabIdx = TcpIp_Udp_TxReqListWritePos[TxReqListIdx];
    CurTxReq.UdpTxReqTabIdx   = GlobTxReqTabIdx;
    TxReqListElePtr = &((TcpIp_Udp_TxReqList[TxReqListIdx])[GlobTxReqTabIdx]);

    TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* fill TxReqList element */
    TxReqListElePtr->TxDataLenByte = (uint16)PbufPtr->totLen;
    TxReqListElePtr->Transmitted   = FALSE;
  }
  else
  {
    TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  /* send message */
  RetValue = TcpIp_Udp_VSendMsg(&CurTxReq, FALSE, 0);

  if((TxReqListIdx != 0xFF) && (TxReqListElePtr != NULL_PTR))  /* TxConfirmation is enabled */
  {
    if(E_OK == RetValue)
    {
      TCPIP_VENTER_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* inc list variables */
      TcpIp_Udp_TxReqListWritePos[TxReqListIdx]++;
      if(TcpIp_Udp_VCfgGetTxReqListSize(TxReqListIdx) == TcpIp_Udp_TxReqListWritePos[TxReqListIdx])
      {
        TcpIp_Udp_TxReqListWritePos[TxReqListIdx] = 0;
      }
      TcpIp_Udp_TxReqListFillNum[TxReqListIdx]++;

      TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
    else
    {
      /* empty TxReqList element */
      TxReqListElePtr->TxDataLenByte = 0;  /* PRQA S 0505 */ /* MD_TCPIP_UDP_1.2_0505_a */
    }
  }

#else
  TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* send message */
  RetValue = TcpIp_Udp_VSendMsg(&CurTxReq, FALSE, 0);
#endif

  return RetValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6050 */ /* MD_MSR_STCAL */

/***********************************************************************************************************************
 *  TcpIp_Udp_TxConfirmation
 **********************************************************************************************************************/
/*! \brief      Transmission Confirmation Callback
 *  \param[in]  SockIdx               socket index
 *  \param[in]  TxReqTabIdx           tx request table index
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Udp_TxConfirmation(
    TcpIp_SockIdxType SockIdx,
    uint8 TxReqTabIdx )
{
#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  uint8 TxReqListIdx;
#endif

  /* ------------------------------------------------- */
  /* DET */
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_INIT, TCPIP_UDP_API_ID_TX_CONFIRMATION, TCPIP_E_NOTINIT )
  TcpIp_CheckDetErrorReturnVoid( TCPIP_COND_VALID_UDPSOCKIDX(SockIdx), TCPIP_UDP_API_ID_TX_CONFIRMATION, TCPIP_E_INV_SOCK_ID )
  /* ------------------------------------------------- */

#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  TxReqListIdx = TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx];

  if(TxReqListIdx != 0xFF)  /* TxConfirmation is enabled */
  {
    uint8 LocTxReqTabIdx;  /* socket specific TxReqList index */

    LocTxReqTabIdx = TxReqTabIdx;

    if(TcpIp_Udp_TxReqListReadPos[TxReqListIdx] == LocTxReqTabIdx)
    {
      /* this is the first element in the TxReqList */

      /* get values from TcpIp_Udp_TxReqTab, and confirm tx */
      TcpIp_VSockTxConfirmation(SockIdx, (TcpIp_Udp_TxReqList[TxReqListIdx])[TxReqTabIdx].TxDataLenByte);
      (TcpIp_Udp_TxReqList[TxReqListIdx])[TxReqTabIdx].TxDataLenByte = 0;

      TCPIP_VENTER_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* inc readpos */
      TcpIp_Udp_TxReqListReadPos[TxReqListIdx]++;
      if(TcpIp_Udp_TxReqListReadPos[TxReqListIdx] == TcpIp_Udp_VCfgGetTxReqListSize(TxReqListIdx))
      {
        TcpIp_Udp_TxReqListReadPos[TxReqListIdx] = 0;
      }
      TcpIp_Udp_TxReqListFillNum[TxReqListIdx]--;

      TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
    else
    {
      /* mark element for later confirmation */
      (TcpIp_Udp_TxReqList[TxReqListIdx])[TxReqTabIdx].Transmitted = TRUE;
    }
  }
#else
  TCPIP_UNUSED_PARAMETER(TxReqTabIdx);    /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_Udp_MainFunctionRx
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
FUNC(void, TCPIP_CODE) TcpIp_Udp_MainFunctionRx(void)
{
#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  /* #10 Iterate over all UDP sockets. */
  TcpIp_SockIdxType SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

  for(SockIdx = 0; SockIdx < TcpIp_VCfgGetMaxNumUdpSocks(); SockIdx++)
  {
    /* #20 Check if TxReqList is assigned to the socket (Socket uses optional TxConfirmation feature). */
    uint8 TxReqListIdx = TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx];

    if(TxReqListIdx != 0xFF)  /* TxConfirmation is enabled */
    {
      /* #30 Iterate over entries in the TxReqList. */
      while(0 != TcpIp_Udp_TxReqListFillNum[TxReqListIdx])
      {
        uint8   FillNum;
        uint16  LocalTxReqTabIdx;
        uint16  TxConfLen;
        boolean Transmitted;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
        boolean IssueTxConf = FALSE;

        TCPIP_VENTER_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

        /* #40 Remove entry from the ReqList, if transmission of request has been confirmend. */
        FillNum = TcpIp_Udp_TxReqListFillNum[TxReqListIdx];
        if(0 != FillNum)
        {
          LocalTxReqTabIdx =  TcpIp_Udp_TxReqListReadPos[TxReqListIdx];
          Transmitted      = (TcpIp_Udp_TxReqList[TxReqListIdx])[LocalTxReqTabIdx].Transmitted;
          TxConfLen        = (TcpIp_Udp_TxReqList[TxReqListIdx])[LocalTxReqTabIdx].TxDataLenByte;

          if(TRUE == Transmitted)
          {
            IssueTxConf = TRUE;

            /* inc ReadPos */
            TcpIp_Udp_TxReqListReadPos[TxReqListIdx]++;
            if(TcpIp_Udp_TxReqListReadPos[TxReqListIdx] == TcpIp_Udp_VCfgGetTxReqListSize(TxReqListIdx))
            {
              /* wraparound */
              TcpIp_Udp_TxReqListReadPos[TxReqListIdx] = 0;
            }
            /* decrease FillNum */
            TcpIp_Udp_TxReqListFillNum[TxReqListIdx]--;
          }
        }
        else
        {
          /* no list element available */
          TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */
          break;  /* leave the while-loop */
        }

        TCPIP_VLEAVE_CRITICAL_SECTION();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

        if(IssueTxConf == TRUE)
        {
          /* confirm tx */
          /* #50 Forward TxConfirmation to TcpIpSocketOwner. */
          TcpIp_VSockTxConfirmation(SockIdx, TxConfLen);
        }
        else
        {
          /* no pending element at the start of the list */
          break;  /* PRQA S 0771 */ /* MD_TCPIP_UDP_14.6_0771_a */
        }
      }
    }
  }
#endif
} /* TcpIp_Udp_MainFunctionRx() */  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 * TcpIp_Udp_MainFunctionTx()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, TCPIP_CODE) TcpIp_Udp_MainFunctionTx(void)
{
#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
  /* #10 Try to send UDP packets that have been queued because link-layer address resolution was not completed. */
  TcpIp_SockIdxType SockIdx;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */

  for(SockIdx = 0; SockIdx < TcpIp_VCfgGetMaxNumUdpSocks(); SockIdx++)
  {
    if(0 != TcpIp_Udp_TxRetrQueueForSock[SockIdx].ElementCount)
    {
      (void)TcpIp_Udp_SendRetryQueueIfPossible(SockIdx, NULL_PTR /* any address */);
    }
  }
#endif
} /* TcpIp_Udp_MainFunctionTx() */

/***********************************************************************************************************************
 *  TcpIp_Udp_ResetSocket
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Udp_ResetSocket(TcpIp_SocketIdType socketId)
{
  TcpIp_Udp_CloseSocket(socketId);  /* reset tx confirmation depending elements */

  TcpIp_TcpIpEventFunctions(TcpIp_SockUserIdx[socketId], socketId, TCPIP_UDP_CLOSED);  /* trigger 'CLOSED' event */
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  TcpIp_Udp_SetSockOpt
 **********************************************************************************************************************/
/*! \brief       set UDP socket option
 *  \param[in]   SockIdx                socket index
 *  \param[in]   ParameterId            option name
 *  \param[in]   ParameterValuePtr      option parameter pointer
 *  \return      E_OK                   socket option change
 *  \return      E_NOT_OK               socket option change request failed
 *  \context     task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_SetSockOpt(
    TcpIp_SocketIdType SockIdx,
    TcpIp_ParamIdType ParameterId,
    P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) ParameterValuePtr )
{
  Std_ReturnType RetValue = E_NOT_OK;

  if(TcpIp_VCfgGetMaxNumUdpSocks() > SockIdx)  /* only for UDP sockets */
  {
    switch(ParameterId)
    {
#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
    case TCPIP_PARAMID_V_UDP_TXREQLISTSIZE:
      {
        uint8 RequestedListSize = *ParameterValuePtr;
        uint8 TxReqListIdx;

        /* choose a matching rx buffer and assign it to the socket / TCP connection */
        for(TxReqListIdx = 0; TxReqListIdx < TcpIp_VCfgGetUdpTxReqListNum(); TxReqListIdx++)
        {
          if((TcpIp_Udp_TxReqList_IsUsedBySocket[TxReqListIdx] == TCPIP_INV_SOCK_IDX) && (RequestedListSize == TcpIp_Udp_TxReqListSize[TxReqListIdx]))
          {
            /* found a free and matching TxReqList */
            TcpIp_Udp_TxReqList_IsUsedBySocket[TxReqListIdx] = SockIdx;
            TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx] = TxReqListIdx;
            RetValue = E_OK;
            break;  /* stop the for-loop */
          }
        }
        break;
      }
#endif  /* (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON) */

#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
    case TCPIP_PARAMID_V_UDP_TXRETRYLISTSIZE:
      {
        /* set the maximum number of Eth tx buffers used for buffering messages in case the remote address is not yet resolved */
        uint8 RetryListSizeMax = *ParameterValuePtr;
        if(TCPIP_UDP_TX_RETRY_QUEUE_NUM_TOTAL >= RetryListSizeMax)
        {
          TcpIp_Udp_TxRetrQueueMaxNum[SockIdx] = RetryListSizeMax;
          RetValue = E_OK;
        }
        break;
      }
#endif

    default:
      {
        /* error, do nothing */
        TCPIP_UNUSED_PARAMETER(ParameterValuePtr);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
        break;
      }
    }
  }

  return RetValue;
}

/***********************************************************************************************************************
 *  TcpIp_Udp_VSendMsg
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_VSendMsg(
    P2CONST(TcpIp_Udp_TxReqType, TCPIP_APPL_DATA, TCPIP_CONST) TxReqPtr,
    boolean IsRetryAttempt,
    uint8 RetrQueueListIdx )
{
  TcpIp_Udp_HdrType  *HdrPtr;
  TcpIp_SockIdxType   LocSockIdx;
  uint16              TxDataLenByte;  /* PRQA S 0781 */ /* MD_TCPIP_5.6_0781 */
  Std_ReturnType      ReturnValue;
  TcpIp_ReturnType    TransmitReturnValue;
  boolean             ReqTxConf            = FALSE;
  uint8               TxReqTabIdx          = 0;

#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_OFF)
  TCPIP_UNUSED_PARAMETER(IsRetryAttempt);    /* PRQA S 3112 */ /* MD_MSR_14.2 */
  TCPIP_UNUSED_PARAMETER(RetrQueueListIdx);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

  LocSockIdx    = TxReqPtr->SockIdx;
  TxDataLenByte = TxReqPtr->DataLenByte;

#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
  if(IsRetryAttempt == FALSE)
#endif
  {
    /* fill UDP header elements */
    HdrPtr = (TcpIp_Udp_HdrType *)(TxReqPtr->IpPayloadPtr);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */  /* PRQA S 3305 */ /* MD_TCPIP_3305_struct */
    HdrPtr->SrcPort  = ((IpBase_SockAddrInType *)&(TcpIp_SocketList[LocSockIdx].LocSock))->sin_port;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
    HdrPtr->TgtPort  = ((const IpBase_SockAddrInType *)&(TxReqPtr->Dest))->sin_port;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
    HdrPtr->LenByte  = IPBASE_HTON16((uint16)(TxDataLenByte + TCPIP_UDP_HDR_LEN_BYTE));
    HdrPtr->Checksum = TCPIP_UDP_EMPTY_CHKSUM;

    TxDataLenByte  += TCPIP_UDP_HDR_LEN_BYTE;

    /* checksum will be calculated by lower layer, value is already set to '0' */
  }
#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
  else
  {
    /* (IsRetryAttempt == TRUE) */
    TcpIp_Udp_RetryQueueElementType  *RetryQueueElePtr;  /* pointer to the new retry queue element */

    TxDataLenByte  += TCPIP_UDP_HDR_LEN_BYTE;

    RetryQueueElePtr = &TcpIp_Udp_TxRetrQueueElements[RetrQueueListIdx];
    TcpIp_Udp_IpTxRequestDescriptor[LocSockIdx] = RetryQueueElePtr->TxRequestDesc;
  }
#endif  /* (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON) */

#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
  if(TcpIp_Udp_Socket_AssignedTxReqListIndex[TxReqPtr->SockIdx] != 0xFF)  /* TxConfirmation is enabled */
  {
    ReqTxConf   = TRUE;
    TxReqTabIdx = TxReqPtr->UdpTxReqTabIdx;
  }
#endif

  /* transmit message and return */
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  if(IPBASE_AF_INET == ((const IpBase_SockAddrType *)&(TxReqPtr->Dest))->sa_family)  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
#endif
  {
    TransmitReturnValue = IpV4_Ip_Transmit(LocSockIdx, &TcpIp_Udp_IpTxRequestDescriptor[LocSockIdx], TxDataLenByte, TCPIP_PROTOCOL_UDP, ((const IpBase_SockAddrInType *)&(TxReqPtr->Dest))->sin_addr,  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
                                           ReqTxConf, TxReqTabIdx, TRUE);
  }
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  else
#endif
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  {
    TransmitReturnValue = IpV6_Transmit(LocSockIdx, &TcpIp_Udp_IpTxRequestDescriptor[LocSockIdx], TCPIP_PROTOCOL_UDP, TxDataLenByte, ReqTxConf, TxReqTabIdx, TRUE);
  }
#endif

  if(TCPIP_OK == TransmitReturnValue)
  {
    ReturnValue = E_OK;
  }
  else if(TCPIP_E_PHYS_ADDR_MISS == TransmitReturnValue)
  {
#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
    if(FALSE == IsRetryAttempt)
    {
      /* add request to the retry list if possible */
      if((0 != TcpIp_Udp_TxRetrQueueMaxNum[LocSockIdx]) && (TcpIp_Udp_TxRetrQueueMaxNum[LocSockIdx] != TcpIp_Udp_TxRetrQueueForSock[LocSockIdx].ElementCount))
      {  /* for this socket the retry queue is enabled an not full */
        TcpIp_DListIdxType                RetryQueueEleIdx;  /* index of the new retry queue element */
        TcpIp_Udp_RetryQueueElementType  *RetryQueueElePtr;  /* pointer to the new retry queue element */

        if(E_OK == TcpIp_DListAddElement(&TcpIp_Udp_TxRetrQueueForSock[LocSockIdx], TcpIp_Udp_TxRetrQueueForSock[LocSockIdx].LastIdx, &RetryQueueEleIdx))
        {
          /* a new element could be added */
          RetryQueueElePtr = &TcpIp_Udp_TxRetrQueueElements[RetryQueueEleIdx];

          /* fill retry queue element */
          (void)IpBase_CopySockAddr((IpBase_SockAddrType*)&(RetryQueueElePtr->Destination), (const IpBase_SockAddrType*)&(TxReqPtr->Dest));  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
          RetryQueueElePtr->UdpPayloadLen     = TxReqPtr->DataLenByte;
          RetryQueueElePtr->UdpTxReqTabIdx    = TxReqPtr->UdpTxReqTabIdx;
          RetryQueueElePtr->TxRequestDesc     = TcpIp_Udp_IpTxRequestDescriptor[LocSockIdx];

          /* accept this first send attempt */
          ReturnValue = E_OK;
        }
        else
        {
          /* no new element could be added (probably no element was available) */
          (void)TcpIp_Udp_CancelIpTransmit(LocSockIdx, &TcpIp_Udp_IpTxRequestDescriptor[LocSockIdx], ((const IpBase_SockAddrInType *)&(TxReqPtr->Dest))->sin_family, TxReqPtr->UdpTxReqTabIdx);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
          ReturnValue = E_NOT_OK;
        }
      }
      else
      {
        /* the transmit has to be canceled because there is no queue element to store the request */
        (void)TcpIp_Udp_CancelIpTransmit(LocSockIdx, &TcpIp_Udp_IpTxRequestDescriptor[LocSockIdx], ((const IpBase_SockAddrInType *)&(TxReqPtr->Dest))->sin_family, TxReqPtr->UdpTxReqTabIdx);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
        ReturnValue = E_NOT_OK;
      }
    }
    else
    {
      /* a retry attempt failed, the physical address is still missing */
      ReturnValue = E_NOT_OK;
    }
#else  /* (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_OFF) */
    /* This should never happen since the address availability is already testet in ProvideBuffer */
    ReturnValue = E_NOT_OK;
#endif  /* (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON) */
  }
  else /* (TCPIP_E_NOT_OK == TransmitReturnValue) */
  {
    ReturnValue = E_NOT_OK;
  }

  return ReturnValue;
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6050 */ /* MD_MSR_STCAL */  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  TcpIp_Udp_StoreChecksumInHeader
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Udp_StoreChecksumInHeader(
    uint16           Checksum,
    TCPIP_P2V(uint8) UdpHdrPtr)
{
  TcpIp_Udp_HdrType *HdrPtr = (TcpIp_Udp_HdrType*)UdpHdrPtr;  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_struct */  /* PRQA S 3305 */ /* MD_TCPIP_3305_struct */

  if(0 == Checksum)
  {
    HdrPtr->Checksum = 0xFFFF;
  }
  else
  {
    HdrPtr->Checksum = Checksum;
  }
} /* TcpIp_Udp_StoreChecksumInHeader() */

/***********************************************************************************************************************
 *  TcpIp_Udp_CancelIpTransmit
 **********************************************************************************************************************/
/*! \brief        Cancel the transmit after a preceiding ProvideTxBuffer
 *  \param[in]    SockIdx               socket index
 *  \param[in]    TxReqDescrPtr         pointer to the used transmit request descriptor
 *  \param[in]    Domain                address domain
 *  \param[in]    UlTxReqTabIdx         transmission request table index
 *  \return       TCPIP_OK                  operation completed successfully <br>
 *                TCPIP_E_NOT_OK            operation failed
 *  \note         A previous call of IpVx _ProvideTxBuffer() must have been successful.
 *  \context      task level
 **********************************************************************************************************************/
STATIC FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_Udp_CancelIpTransmit(
    TcpIp_SockIdxType                                                 SockIdx,
    P2VAR(TcpIp_IpTxRequestDescriptorType, AUTOMATIC, TCPIP_APPL_VAR) TxReqDescrPtr,
    TcpIp_DomainType                                                  Domain,
    uint8                                                             UlTxReqTabIdx )
{
  /* TxConfirmation is always set to 'FALSE' */

#if (TCPIP_SUPPORT_IPV4 != TCPIP_SUPPORT_IPV6)
  TCPIP_UNUSED_PARAMETER(Domain);  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# if (TCPIP_SUPPORT_IPV6 == STD_ON)
  if(IPBASE_AF_INET == Domain)  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
# endif
  {
    /* IPv4 destination address is set to '0' since it is not used in IpV4 for this usecase */
    (void)IpV4_Ip_Transmit(SockIdx, TxReqDescrPtr, 0, TCPIP_PROTOCOL_UDP, 0, FALSE, UlTxReqTabIdx, FALSE);
  }
# if (TCPIP_SUPPORT_IPV6 == STD_ON)
  else
# endif
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
  {
    TCPIP_UNUSED_PARAMETER(UlTxReqTabIdx);  /* PRQA S 3112 */ /* MD_MSR_14.2 */

    IpV6_CancelTransmit(SockIdx, TxReqDescrPtr);
  }
#endif

  return TCPIP_OK;
}

#if (TCPIP_UDP_TX_QUEUE_ADDR_MISS_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_Udp_SendRetryQueueIfPossible
 **********************************************************************************************************************/
/*! \brief         Transmit stored messages if possible
 *  \param[in]     SocketId           socket index
 *  \param[in]     RemoteAddrPtr      IP address and port of the remote host to transmit to.
 *  \return        E_OK               OK <br>
 *                 E_NOT_OK           Something went wrong
 *  \note
 *  \context       TcpIp_UdpTransmit
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Udp_SendRetryQueueIfPossible(
    TcpIp_SocketIdType SocketId,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RemoteAddrPtr)  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
{
  if(TcpIp_Udp_TxRetrQueueForSock[SocketId].ElementCount != 0)
  {
    /* try to send the stored elements first if they have the same destination and try to send only those ones */
    TcpIp_DListIdxType ListIdx      = TcpIp_Udp_TxRetrQueueForSock[SocketId].FirstIdx;
    TcpIp_DListIdxType NextListIdx;
    uint8 TotElementCount           = TcpIp_Udp_TxRetrQueueForSock[SocketId].ElementCount;
    uint8 CurrentElementCounter;

    for(CurrentElementCounter = 0; CurrentElementCounter < TotElementCount; CurrentElementCounter++)
    {
      if( (RemoteAddrPtr == NULL_PTR) /* any address */ ||  /* PRQA S 3415 */ /* MD_TCPIP_12.4_3415 */
          (TRUE == IpBase_SockIpAddrIsEqual((IpBase_SockAddrType*)RemoteAddrPtr, (IpBase_SockAddrType*)&TcpIp_Udp_TxRetrQueueElements[ListIdx].Destination)) )  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
      {
        /* the element has the same destination address as the current send request, or all elemts have to be sent */
        TcpIp_Udp_TxReqType TxReqEle;

        TxReqEle.DataLenByte     = TcpIp_Udp_TxRetrQueueElements[ListIdx].UdpPayloadLen;
        TxReqEle.BufIdx          = TcpIp_Udp_TxRetrQueueElements[ListIdx].TxRequestDesc.BufIdx;
        TxReqEle.UdpTxReqTabIdx  = TcpIp_Udp_TxRetrQueueElements[ListIdx].UdpTxReqTabIdx;
        TxReqEle.SockIdx         = SocketId;
        (void)IpBase_CopySockAddr((IpBase_SockAddrType*)&(TxReqEle.Dest), (IpBase_SockAddrType*)&TcpIp_Udp_TxRetrQueueElements[ListIdx].Destination);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
        TxReqEle.IpPayloadPtr    = &TcpIp_Udp_TxRetrQueueElements[ListIdx].TxRequestDesc.EthPayloadPtr[TcpIp_Udp_TxRetrQueueElements[ListIdx].TxRequestDesc.IpPayloadOfs];

        NextListIdx = TcpIp_Udp_TxRetrQueueElementChain[ListIdx].NextIdx;
        if(E_OK == TcpIp_Udp_VSendMsg(&TxReqEle, TRUE, ListIdx))
        {
          /* element could be sent, so remove it from retry list */
          TcpIp_DListRemoveElement(&TcpIp_Udp_TxRetrQueueForSock[SocketId], ListIdx);
        }

        ListIdx = NextListIdx;
      }
      else
      {
        /* get the next list element */
        ListIdx = TcpIp_Udp_TxRetrQueueElementChain[ListIdx].NextIdx;
      }
    }
  }
  return E_OK;
}

/***********************************************************************************************************************
 *  TcpIp_Udp_CancelRetriesForDestination
 **********************************************************************************************************************/
/*! \brief         Cancel all pending retries for a specific destination
 *  \param[in]     CtrlIdx            EthIf controller index
 *  \param[in]     RemoteAddrPtr      IP address of the remote host
 *  \context
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Udp_CancelRetriesForDestination(
  uint8                         CtrlIdx,
  TCPIP_P2V(TcpIp_SockAddrType) RemoteAddrPtr)  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
{
  TcpIp_SockIdxType UdpSockIdx;

  for(UdpSockIdx = 0; UdpSockIdx < TcpIp_VCfgGetMaxNumUdpSocks(); UdpSockIdx++)
  {
    if(!TCPIP_DLIST_IS_EMPTY(TcpIp_Udp_TxRetrQueueForSock[UdpSockIdx]))
    {
      /* cancel transmit of all retry elements for this socket that should be sent to the unreachable destination */
      TcpIp_DListIdxType ListIdx = TcpIp_Udp_TxRetrQueueForSock[UdpSockIdx].FirstIdx;

      while (TCPIP_DLIST_END_IDX != ListIdx)
      {
        TcpIp_DListIdxType NextListIdx = TCPIP_DLIST_GET_NEXT(ListIdx, TcpIp_Udp_TxRetrQueueForSock[UdpSockIdx]);

        if (TcpIp_Udp_TxRetrQueueElements[ListIdx].TxRequestDesc.CtrlIdx == CtrlIdx)
        {
          if (TRUE == TcpIp_VSockIpAddrIsEqual((TCPIP_P2C(IpBase_SockAddrType))&TcpIp_Udp_TxRetrQueueElements[ListIdx].Destination, (TCPIP_P2C(IpBase_SockAddrType))RemoteAddrPtr))  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
          {
            (void)TcpIp_Udp_CancelIpTransmit(UdpSockIdx, &TcpIp_Udp_TxRetrQueueElements[ListIdx].TxRequestDesc, RemoteAddrPtr->domain, 0);
            TcpIp_DListRemoveElement(&TcpIp_Udp_TxRetrQueueForSock[UdpSockIdx], ListIdx);
          }
        }

        ListIdx = NextListIdx;
      }
    }
  }
} /* TcpIp_Udp_CancelRetriesForDestination() */  /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* module specific MISRA deviations:
   MD_TCPIP_UDP_1.2_0505_a:
      Reason:     'ReqListElePtr' is always properly initialized if (TcpIp_Udp_Socket_AssignedTxReqListIndex[SockIdx] != 0xFF)
      Risk:       The init sequence for the variable might change after a code change / rework.
      Prevention: Covered by code review.
   MD_TCPIP_UDP_14.6_0771_a:
      Reason:     The break statement is used multiple (two) times in a while struct to stop the function
                  TcpIp_Udp_MainFunction from issuing further TxConfirmations This seems to be the most efficient way
                  to do that.
      Risk:       Unstructured code should be avoided.
      Prevention: Covered by code review.

*/

/**********************************************************************************************************************
 *  END OF FILE: Udp.c
 *********************************************************************************************************************/
