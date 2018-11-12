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
 *         \file  TcpIp_IcmpV4.c
 *        \brief  Implementation of Internet Control Message Protocol for IPv4 (ICMPv4)
 *
 *      \details  This file is part of the TcpIp IPv4 submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp IPv4 submodule. >> TcpIp_IpV4.h
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */

#define TCPIP_ICMPV4_SOURCE

#include "TcpIp_Cfg.h"
#if (TCPIP_SUPPORT_IPV4 == STD_ON)

#include "TcpIp_IpV4_Cfg.h"
#if (IPV4_SUPPORT_ICMP  == STD_ON)
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ComStack_Types.h"

#include "TcpIp_IcmpV4.h"
#include "TcpIp_IcmpV4_Cbk.h"
#include "TcpIp_IpV4_Priv.h"
#include "TcpIp_IpV4_Lcfg.h"

#include "TcpIp_IpV4.h"

#include "IpBase_Copy.h"
#include "IpBase.h"

#if !defined (STATIC)
# define STATIC static
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define IPV4_ICMP_ECHO_MSG_HDR_LEN             8

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
  uint8    Type;
  uint8    Code;
  uint16   Checksum;
} IpV4_Icmp_HdrStartType;

typedef struct
{
  uint8    Type;
  uint8    Code;
  uint16   Checksum;
  uint16   Identifier;
  uint16   SequNum;
} IpV4_Icmp_EchoMsgType; /* Echo or Echo Request */

typedef struct
{
  IpBase_AddrInType  Dest;
  uint16          Identifier;
  uint16          SequNum;
  IpV4_AddrIdType IpAddrId;
} IpV4_Icmp_PongRetryType; /* data to retry sending a PONG */

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/* ----- */
#define IPV4_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

STATIC VAR(IpV4_Icmp_PongRetryType, IPV4_VAR_NOINIT) IpV4_Icmp_EchoReplyPendingMsg;
STATIC VAR(boolean,                 IPV4_VAR_NOINIT) IpV4_Icmp_EchoReplyIsPending;

#define IPV4_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/* ----- */
#define IPV4_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

STATIC VAR(uint16, IPV4_VAR_NOINIT) IpV4_Icmp_SeqNum;
STATIC VAR(uint16, IPV4_VAR_NOINIT) IpV4_Icmp_EchoReplyDataLen;

#define IPV4_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define IPV4_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */
STATIC FUNC(void, IPV4_CODE) IpV4_Icmp_VSendPendingEchoReply(void);

/***********************************************************************************************************************
 *  IpV4_Icmp_SendEchoMessage
 **********************************************************************************************************************/
/*! \brief        Send ICMP Echo (Request/Reply) message.
 *  \param[in]    AddrId          Source IP address identifier.
 *  \param[in]    DestIpAddr      Destination IP address.
 *  \param[in]    IcmpType        Type of the ICMP message (ECHO_REQUEST, ECHO_REPLY).
 *  \param[in]    IcmpCode        Code of the ICMP message (usually 0).
 *  \param[in]    Identifier      Identifier of the Echo message
 *  \param[in]    SequenceNumber  Sequence Number of the ICMP message.
 *  \param[in]    DataPtr         Pointer to the payload od the Echo message.
 *  \param[in]    DataPtr         Length of the payload in bytes.
 *  \return       BUFREQ_OK       Transmit triggered.
 *  \return       BUFREQ_E_BUSY   Transmit curretly not possible. Retry later.
 *  \return       BUFREQ_E_NOT_OK Transmit not possible.
 *  \context                      TASK|ISR
 *  \reentrant                    FALSE
 *  \synchronous                  TRUE
 **********************************************************************************************************************/
STATIC FUNC(BufReq_ReturnType, IPV4_CODE) IpV4_Icmp_SendEchoMessage(
   IpV4_AddrIdType          AddrId,
   IpBase_AddrInType        DestIpAddr,
   uint8                    IcmpType,
   uint8                    IcmpCode,
   uint16                   Identifier,
   uint16                   SequenceNumber,
   IPV4_P2C(uint8)          DataPtr,
   uint16                   DataLenByte);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  IpV4_Icmp_Init
 **********************************************************************************************************************/
/*! \brief      This API call stores the start address of the post build time configuration of the ICMP and may be used
 *              to initialize the data structures.
 *  \param[in]  CfgPtr             pointer to module configuration
 *  \context    initialization
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Icmp_Init(
    P2CONST(IpV4_Icmp_ConfigType, IPV4_CONST, IPV4_CONST) CfgPtr )
{
  IPV4_UNUSED_PARAMETER(CfgPtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  

  IpV4_Icmp_EchoReplyIsPending = FALSE;
  IpV4_Icmp_SeqNum = 0;
}

/***********************************************************************************************************************
 *  IpV4_Icmp_MainFunction
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, IPV4_CODE) IpV4_Icmp_MainFunction(void)
{
  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT, IPV4_ICMP_API_ID_MAIN_FUNCTION, IPV4_E_NOT_INITIALIZED )
  /* ------------------------------------------------- */

  /* #10 Send pending ICMPv4 Echo Replies. */
  if(TRUE == IpV4_Icmp_EchoReplyIsPending)
  {
    IpV4_Icmp_VSendPendingEchoReply();
  }

} /* IpV4_Icmp_MainFunction() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Icmp_RxIndication
 **********************************************************************************************************************/
/*! \brief      Receive Indication Callback
 *  \param[in]  AddrId                ip address identifier
 *  \param[in]  RemNetAddr            remote network address
 *  \param[in]  DataPtr               pointer to the received data
 *  \param[in]  LenByte               length of received data in bytes
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Icmp_RxIndication(
    IpV4_AddrIdType AddrId,
    IpBase_AddrInType RemNetAddr,
    P2VAR(uint8, AUTOMATIC, IPV4_APPL_DATA) DataPtr,
    uint16 LenByte )
{
#if (STD_ON != IPV4_ICMP_SILENT_MODE)
  IPV4_P2C(IpV4_Icmp_HdrStartType) IcmpHdrStartPtr;

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT,                   IPV4_ICMP_API_ID_RX_INDICATION, IPV4_E_NOT_INITIALIZED )
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_VALID_IPADDRID(AddrId), IPV4_ICMP_API_ID_RX_INDICATION, IPV4_E_INV_PARAM )
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_VALID_PTR(DataPtr),     IPV4_ICMP_API_ID_RX_INDICATION, IPV4_E_INV_POINTER )
  /* ------------------------------------------------- */

# if (IPV4_ICMP_CHECK_RX_CHECKSUM == STD_ON)
#  if(TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
  if(IPV4_CTRL_VAR(TcpIp_IpV4_ChecksumOffloadingSupport).Icmp == TRUE)
  {
    /* checksum was already checked by the hardware, so no further checking is necessary */
  }
  else
#  endif
  {
    /* calculate checksum */
    if(0 != IpBase_TcpIpChecksumAdd(DataPtr, (uint32)(LenByte), 0, TRUE))
    {
      /* checksum error */
      /* discard message */
      return;
    }
  }
# endif /* IPV4_ICMP_CHECK_RX_CHECKSUM */

  IcmpHdrStartPtr = (IPV4_P2V(IpV4_Icmp_HdrStartType))DataPtr; /* PRQA S 0310 */ /* MD_IpV4_11.04 */

  if(IPV4_ICMP_TYPE_ECHO == IcmpHdrStartPtr->Type)
  {
    IPV4_P2V(IpV4_Icmp_EchoMsgType) EchoRequMsg = (IPV4_P2V(IpV4_Icmp_EchoMsgType))DataPtr; /* PRQA S 0310 */ /* MD_IpV4_11.04 */

    if(0 == IcmpHdrStartPtr->Code)
    {
      uint16 EchoIdentifierHbo = (uint16)IPBASE_HTON16(EchoRequMsg->Identifier);
      uint16 EchoSeqNumHbo     = (uint16)IPBASE_HTON16(EchoRequMsg->SequNum);
      LenByte -= sizeof(IpV4_Icmp_EchoMsgType);
      DataPtr  = &DataPtr[sizeof(IpV4_Icmp_EchoMsgType)];

      if (BUFREQ_E_BUSY == IpV4_Icmp_SendEchoMessage(AddrId, RemNetAddr, IPV4_ICMP_TYPE_ECHO_REPLY, 0, EchoIdentifierHbo, EchoSeqNumHbo, DataPtr, LenByte))
      {
        IpV4_Icmp_EchoReplyPendingMsg.IpAddrId   = AddrId;
        IpV4_Icmp_EchoReplyPendingMsg.Dest       = RemNetAddr;
        IpV4_Icmp_EchoReplyPendingMsg.Identifier = EchoIdentifierHbo;
        IpV4_Icmp_EchoReplyPendingMsg.SequNum    = EchoSeqNumHbo;

        if(LenByte > IpV4_Icmp_VCfgGetEchoReplyPendLenMax())
        {
          LenByte = IpV4_Icmp_VCfgGetEchoReplyPendLenMax();
        }

        /* copy data that was received with incoming message */
        IpBase_Copy((IPV4_P2V(IpBase_CopyDataType))&IpV4_Icmp_EchoReplyData[0], (IPV4_P2V(IpBase_CopyDataType))DataPtr, LenByte); /* PRQA S 0310 */ /* MD_IpV4_11.04 */

        IpV4_Icmp_EchoReplyDataLen = LenByte;
        IpV4_Icmp_EchoReplyIsPending = TRUE;
      }
    }
    else
    {
      /* '0' is the only valid code for this message type
         -> drop message silently */
    }
  }
  else if(IPV4_ICMP_TYPE_ECHO_REPLY == IcmpHdrStartPtr->Type)
  {
    /* incoming echo reply */
    /* do nothing */
  }
  else
  {
    /* ICMP type not supported -> silently discard message */
  }
#endif  /* STD_ON != IPV4_ICMP_SILENT_MODE */
} /* PRQA S 2006, 6010, 6030 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC */

/***********************************************************************************************************************
 *  IpV4_Icmp_SendEcho
 **********************************************************************************************************************/
/*! \brief        Trigger the sending of a PING message
 *  \param[in]    AddrId      ip address identifier
 *  \param[in]    Dest        remote network address
 *  \param[in]    DataPtr     pointer to the data
 *  \param[in]    LenByte     length of received data in bytes
 *  \return       E_OK        Send request could be accepted
 *  \return       E_NOT_OK    Send request could not be accepted
 *  \note
 *  \context      interrupt or task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Icmp_SendEcho(
   IpV4_AddrIdType          AddrId,
   IpBase_AddrInType        Dest,
   IPV4_P2C(uint8)          DataPtr,
   uint16                   LenByte )
{
  Std_ReturnType RetVal;

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT,                          IPV4_ICMP_API_ID_SEND_ECHO, IPV4_E_NOT_INITIALIZED, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_OR_ANY_IPADDRID(AddrId), IPV4_ICMP_API_ID_SEND_ECHO, IPV4_E_INV_PARAM, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(DataPtr),            IPV4_ICMP_API_ID_SEND_ECHO, IPV4_E_INV_POINTER, E_NOT_OK )
  /* ------------------------------------------------- */

  IpV4_Icmp_SeqNum++;

  if (BUFREQ_OK == IpV4_Icmp_SendEchoMessage(AddrId, Dest, IPV4_ICMP_TYPE_ECHO, 0, 0, IpV4_Icmp_SeqNum, DataPtr, LenByte))
  {
    RetVal = E_OK;
  }
  else
  {
    RetVal = E_NOT_OK;
  }

  return RetVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Icmp_SendEchoMessage
 **********************************************************************************************************************/
STATIC FUNC(BufReq_ReturnType, IPV4_CODE) IpV4_Icmp_SendEchoMessage(
   IpV4_AddrIdType          AddrId,
   IpBase_AddrInType        DestIpAddr,
   uint8                    IcmpType,
   uint8                    IcmpCode,
   uint16                   Identifier,
   uint16                   SequenceNumber,
   IPV4_P2C(uint8)          DataPtr,
   uint16                   DataLenByte)
{
  BufReq_ReturnType               RetVal;
  TcpIp_IpTxRequestDescriptorType IpTxReqestDescr;
  uint16                          IpPayloadLen     = IPV4_ICMP_ECHO_MSG_HDR_LEN + DataLenByte;
  IPV4_P2V(uint8)                 IpBufPtr; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
  uint16                          IpBufLen         = IpPayloadLen;
  IpBase_SockAddrInType           DestSockAddr;

  DestSockAddr.sin_family = IPBASE_AF_INET;
  DestSockAddr.sin_addr   = DestIpAddr;
  DestSockAddr.sin_port   = 0;

  RetVal = IpV4_Ip_ProvideTxBuffer(&AddrId, (TcpIp_SockIdxType)(IpV4_Icmp_VCfgGetTxSockIdx()),
                                             &DestSockAddr, &IpBufPtr, &IpBufLen, &IpTxReqestDescr, FALSE);

  if (BUFREQ_OK == RetVal)
  {
    boolean                         CopyTxData     = TRUE;
    uint16                          DataRemain     = DataLenByte;
    uint16                          DataPos        = 0;
    IPV4_P2V(IpV4_Icmp_EchoMsgType) EchoRespMsg    = (IPV4_P2V(IpV4_Icmp_EchoMsgType))IpBufPtr; /* PRQA S 0310 */ /* MD_IpV4_11.04 */

    /* IPv4 may provide multiple buffers if message exceeds link MTU,
     * but the first buffer will always be large enough for ICMP header.
     */

    /* write ICMP message header */
    EchoRespMsg->Type       = IcmpType;
    EchoRespMsg->Code       = IcmpCode;
    EchoRespMsg->Checksum   = 0;  /* to be calculated later */
    EchoRespMsg->Identifier = (uint16)IPBASE_HTON16(Identifier);
    EchoRespMsg->SequNum    = (uint16)IPBASE_HTON16(SequenceNumber);

    IpBufPtr  = &IpBufPtr[sizeof(IpV4_Icmp_EchoMsgType)];
    IpBufLen -= sizeof(IpV4_Icmp_EchoMsgType);

    while ((TRUE == CopyTxData) && (0 < DataRemain))
    {
      if (IpBufLen > DataRemain)
      {
        IpBufLen = DataRemain;
      }

      /* copy data given by the calling function */
      IpBase_Copy((IpBase_CopyDataType*)IpBufPtr, (const IpBase_CopyDataType*)&DataPtr[DataPos], IpBufLen); /* PRQA S 0310 */ /* MD_IpV4_11.04 */

      DataRemain -= IpBufLen;
      DataPos    += IpBufLen;

      if (0 < DataRemain)
      {
        /* Request next buffer fragement */
        if (E_OK != IpV4_Ip_ProvideNextTxBuffer(&IpTxReqestDescr, &IpBufPtr, &IpBufLen))
        {
          /* ERROR: This should not happen. If IpV4_Ip_ProvideTxBuffer() returns BUFREQ_OK there should be sufficient buffer space. */
          IpV4_ReportDetError(IPV4_IP_API_ID_V_INTERNAL_FUNCTION, IPV4_E_INV_PARAM);
          CopyTxData = FALSE;
        }
      }
    }

    /* send message by IP: */
    if(E_OK != IpV4_Ip_Transmit((TcpIp_SockIdxType)(IpV4_Icmp_VCfgGetTxSockIdx()), &IpTxReqestDescr, IpPayloadLen,
                            IPV4_IP_PROTOCOL_ICMP, DestIpAddr, FALSE, 0, FALSE))
    {
      /* transmit failed */
      RetVal = BUFREQ_E_NOT_OK;
    }
  }

  return RetVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/***********************************************************************************************************************
 *  IpV4_Icmp_VSendPendingEchoReply
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Icmp_VSendPendingEchoReply(void)
{
  if (TRUE == IpV4_Icmp_EchoReplyIsPending)
  {
    if (BUFREQ_E_BUSY != IpV4_Icmp_SendEchoMessage(IpV4_Icmp_EchoReplyPendingMsg.IpAddrId,   IpV4_Icmp_EchoReplyPendingMsg.Dest, IPV4_ICMP_TYPE_ECHO_REPLY, 0,
                                          IpV4_Icmp_EchoReplyPendingMsg.Identifier, IpV4_Icmp_EchoReplyPendingMsg.SequNum,
                                          IpV4_Icmp_EchoReplyData, IpV4_Icmp_EchoReplyDataLen))
    {
      /* Echo Reply sent or error occured. No retry required. */
      IpV4_Icmp_EchoReplyIsPending = FALSE;
    }
    else
    {
      /* Retry later */
    }
  }
}

/***********************************************************************************************************************
 *  IpV4_Icmp_Cbk_VAddrResTimeout
 **********************************************************************************************************************/
/*! \brief      Address resolution timout Callback
 *  \param[in]  CtrlIdx               controller index
 *  \param[in]  DestAddrPtr           Pointer to destination address
 *  \context    interrupt or task level
 *  \note       The address resolution for the given address timed out on the given controller, after the address
 *              resolution request was accepted earlier.
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Icmp_Cbk_VAddrResTimeout(
  uint8 IpCtrlIdx,
  P2CONST(IpBase_SockAddrType, AUTOMATIC, IPV4_APPL_DATA) DestAddrPtr )
{
  IPV4_UNUSED_PARAMETER(IpCtrlIdx);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  if ( IpV4_Icmp_EchoReplyPendingMsg.Dest == ((const IpBase_SockAddrInType*)DestAddrPtr)->sin_addr) /* PRQA S 0310 */ /* MD_IpV4_11.04 */
  {
    /* cancel ICMP echo reply */
    IpV4_Icmp_EchoReplyIsPending = FALSE;
  }
}

/***********************************************************************************************************************
 *  IpV4_Icmp_StoreChecksumInHeader
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Icmp_StoreChecksumInHeader(
    uint16          Checksum,
    IPV4_P2V(uint8) IcmpHdrPtr)
{
  IPV4_P2V(IpV4_Icmp_HdrStartType) MsgPtr = (IPV4_P2V(IpV4_Icmp_HdrStartType))IcmpHdrPtr; /* PRQA S 0310 */ /* MD_IpV4_11.04 */

  /* calculate checksum */
  MsgPtr->Checksum = Checksum;

} /* IpV4_Icmp_StoreChecksumInHeader() */

/***********************************************************************************************************************
 *  IpV4_Icmp_VLocalIpAddrAssignmentChange()
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Icmp_VLocalIpAddrAssignmentChange(
  IpV4_AddrIdType       IpAddrId,
  TcpIp_IpAddrStateType State)
{
  if (TCPIP_IPADDR_STATE_ASSIGNED != State)
  {
    if (IpV4_Icmp_EchoReplyPendingMsg.IpAddrId == IpAddrId)
    {
      /* cancel ICMP echo reply */
      IpV4_Icmp_EchoReplyIsPending = FALSE;
    }
  }
}

#define IPV4_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

#endif  /* (IPV4_SUPPORT_ICMP == STD_ON) */
#endif  /* (TCPIP_SUPPORT_IPV4 == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: IpV4_Icmp.c
 *********************************************************************************************************************/
