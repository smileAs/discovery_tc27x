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
 *         \file  TcpIp_IcmpV6.c
 *        \brief  Implementation of Internet Control Message Protocol for IPv6 (ICMPv6)
 *
 *      \details  This file is part of the TcpIp IPv6 submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp IPv6 submodule. >> TcpIp_IpV6.h
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */

#define TCPIP_ICMPV6_SOURCE

#include "TcpIp_Cfg.h"
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "TcpIp_IpV6_Priv.h"
#include "TcpIp_IcmpV6.h"
#include "TcpIp_Ndp.h"
#if (IPV6_ENABLE_MLD == STD_ON)
# include "TcpIp_Mld.h"
#endif

#include "IpBase_Sock.h"

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if defined (STATIC)
#else
# define STATIC static
#endif

#define IPV6_ICMP_ENABLE_NDP                             STD_ON

#if (0 < IPV6_ICMP_DEST_UNREACHABLE_MSG_CBK_COUNT)
# define IPV6_ICMP_ENABLE_ERR_MSG_DESTINATION_UNREACHABLE STD_ON
#else
# define IPV6_ICMP_ENABLE_ERR_MSG_DESTINATION_UNREACHABLE STD_OFF
#endif

#if (0 < IPV6_ICMP_TIME_EXCEEDED_MSG_CBK_COUNT)
# define IPV6_ICMP_ENABLE_ERR_MSG_TIME_EXCEEDED STD_ON
#else
# define IPV6_ICMP_ENABLE_ERR_MSG_TIME_EXCEEDED STD_OFF
#endif

#define IPV6_ICMP_ENABLE_ERR_MSG_PARAMETER_PROBLEM       STD_OFF

/* "In order to achieve backwards compatibility, when the ICMP Extension Structure is
 *  appended to an ICMP message and that ICMP message contains an "original datagram"
 *  field, the "original datagram" field MUST contain at least 128 octets.
 *  If the original datagram did not contain 128 octets, the "original datagram"
 *  field MUST be zero padded to 128 octets.  (See Section 5.1 for rationale.)
 *  [RFC4884 4. ICMP Extensibility]
 */
#define IPV6_ICMP_MIN_ORIG_PKT_LEN                          128U

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
/* PRQA S 3453 FctLikeMacros */ /* MD_MSR_19.7 */

/* PRQA L:FctLikeMacros */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#if ((IPV6_ENABLE_ICMP_ERR_MSGS == STD_ON) || (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON))
typedef struct
{
  IpV6_AddrType    DstAddr;
  IpV6_AddrIdType  SrcAddrId;
  uint8            Type;
  uint8            Code;
  uint8            *PayloadPtr;
  uint16           PayloadLen;
  boolean          Pending;
} IpV6_Icmp_MsgInstanceType;
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define IPV6_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC P2VAR(uint8, AUTOMATIC, IPV6_APPL_VAR) IpV6_Icmp_EthBufPtr;

#define IPV6_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**/

#define IPV6_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (IPV6_ENABLE_ICMP_ERR_MSGS == STD_ON)
STATIC VAR(IpV6_Icmp_MsgInstanceType, IPV6_VAR_NOINIT) IpV6_Icmp_PendingMsg;
#endif

#if (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON)
STATIC VAR(IpV6_Icmp_MsgInstanceType, IPV6_VAR_NOINIT) IpV6_Icmp_PendingEchoReply;
#endif

#define IPV6_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define IPV6_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxEchoRequest()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxEchoRequest(
  IpV6_AddrIdType         AddrId,
  IPV6_P2C(IpV6_AddrType) SrcAddrPtr,
  IPV6_P2C(uint8)         DataPtr,
  uint16 LenByte);
#endif

#if (IPV6_ICMP_ENABLE_ERR_MSG_DESTINATION_UNREACHABLE == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxErrDestinationUnreachable()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxErrDestinationUnreachable(
  uint8 Code,
  P2CONST(IpV6_AddrType, AUTOMATIC, IPV6_APPL_DATA) SrcAddrPtr,
  P2CONST(uint8, AUTOMATIC, IPV6_APPL_DATA) DataPtr,
  uint16 LenByte);
#endif

#if (IPV6_ENABLE_PATH_MTU == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxErrPacketTooBig()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxErrPacketTooBig(
  uint8                   AddrId,
  IPV6_P2C(IpV6_AddrType) SrcAddrPtr,
  IPV6_P2C(uint8)         DataPtr,
  uint16                  LenByte);
#endif

#if (IPV6_ICMP_ENABLE_ERR_MSG_TIME_EXCEEDED == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxErrTimeExceeded()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxErrTimeExceeded(
  uint8 Code,
  P2CONST(IpV6_AddrType, AUTOMATIC, IPV6_APPL_DATA) SrcAddrPtr,
  P2CONST(uint8, AUTOMATIC, IPV6_APPL_DATA) DataPtr,
  uint16 LenByte);
#endif

#if (IPV6_ICMP_ENABLE_ERR_MSG_PARAMETER_PROBLEM == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxErrParameterProblem()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxErrParameterProblem(
  uint8 Code,
  P2CONST(IpV6_AddrType, AUTOMATIC, IPV6_APPL_DATA) SrcAddrPtr,
  P2CONST(uint8, AUTOMATIC, IPV6_APPL_DATA) DataPtr,
  uint16 LenByte);
#endif

#if ((IPV6_ENABLE_ICMP_ERR_MSGS == STD_ON) || (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON))
/**********************************************************************************************************************
 *  IpV6_Icmp_VTxPendingMessage()
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, IPV6_CODE) IpV6_Icmp_VTxPendingMessage(
  P2CONST(IpV6_Icmp_MsgInstanceType, AUTOMATIC, IPV6_APPL_DATA) PendingMsgPtr);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  IpV6_Icmp_VCalculateChecksumNbo()
 **********************************************************************************************************************/
FUNC(uint16, IPV6_CODE) IpV6_Icmp_VCalculateChecksumNbo(
  IPV6_P2C(IpV6_AddrType) SrcNetAddrPtr,
  IPV6_P2C(IpV6_AddrType) DstNetAddrPtr,
  IPV6_P2C(uint8)         DataPtr,
  uint16                  LenByte)
{
  uint32 Checksum; /* PRQA S 0781 */ /* MD_IpV6_05.06 */
  uint32 PseudoHdrInfo;

#if (IPV6_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnValue((NULL_PTR != SrcNetAddrPtr), IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER, 0);
  IpV6_CheckDetErrorReturnValue((NULL_PTR != DstNetAddrPtr), IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER, 0);
  IpV6_CheckDetErrorReturnValue((NULL_PTR != DataPtr),       IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER, 0);
#endif

  /*         IPv6 Pseudo Header
   * [RFC2460 8.1 Upper-Layer Checksums]
   *  +-------+-------+-------+-------+
   *  +                               + \
   *  +         Source Address        +  } 16 bytes (128bit)
   *  +                               + /
   *  +-------+-------+-------+-------+
   *  +                               + \
   *  +      Destination Address      +  } 16 bytes (128bit)
   *  +                               + /
   *  +-------+-------+-------+-------+
   *  |   Upper-Layer Packet Length   |  }  4 bytes  (32bit)
   *  +-------+-------+-------+-------+
   *  |          zero         | NxtHdr|  }  4 bytes  (32bit)
   *  +-------+-------+-------+-------+
   *
   *            ICMPv6 Header
   *  +-------+-------+-------+-------+
   *  |  Type |  Code | Checksum == 0 |  }  4 bytes  (32bit)
   *  +-------+-------+-------+-------+
   */

  /* calculate checksum of ICMPv6 pseudo header */
  Checksum = IpBase_TcpIpChecksumAdd((IPV6_P2C(uint8))SrcNetAddrPtr, IPV6_ADDRESS_LEN_BYTE,        0, FALSE);  /* PRQA S 0310 */ /* MD_IpV6_0310 */
  Checksum = IpBase_TcpIpChecksumAdd((IPV6_P2C(uint8))DstNetAddrPtr, IPV6_ADDRESS_LEN_BYTE, Checksum, FALSE);  /* PRQA S 0310 */ /* MD_IpV6_0310 */

  /* Add Upper-Layer Packet Length and Next Header values */
  PseudoHdrInfo = IPV6_HTONS(LenByte) + IPV6_UINT8_HTONS(IPV6_HDR_ID_ICMP);

  /* Add Type and Code of ICMPv6 Header */
  PseudoHdrInfo += *((IPV6_P2C(uint16))DataPtr); /* PRQA S 0310 */ /* MD_IpV6_0310 */

  Checksum = IpBase_TcpIpChecksumAdd((IPV6_P2C(uint8))&PseudoHdrInfo, sizeof(PseudoHdrInfo), Checksum, FALSE); /* PRQA S 0310 */ /* MD_IpV6_0310 */

  /* add ICMPv6 payload */
  Checksum = IpBase_TcpIpChecksumAdd(&DataPtr[sizeof(IpV6_IcmpHeaderType)], (LenByte-sizeof(IpV6_IcmpHeaderType)), Checksum, TRUE);

  return (uint16)Checksum;
} /* End of IpV6_Icmp_VCalculateChecksumNbo() */

#if (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxEchoRequest()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxEchoRequest(
  IpV6_AddrIdType         AddrId,
  IPV6_P2C(IpV6_AddrType) SrcAddrPtr,
  IPV6_P2C(uint8)         DataPtr,
  uint16                  LenByte)
{
  P2CONST(IpV6_IcmpEchoRequestType, AUTOMATIC, IPV6_APPL_VAR)   IcmpEchoReqPtr;
  P2VAR(IpV6_IcmpEchoReplyType,     AUTOMATIC, IPV6_VAR_NOINIT) IcmpEchoReplyPtr;

#if (IPV6_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnVoid(IPV6_IS_VALID_ADDR_ID(AddrId), IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_ADDR_ID);
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != DataPtr),         IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
#endif

  /* The source address of an Echo Reply sent in response to a unicast
     Echo Request message MUST be the same as the destination address of that Echo Request message.
     [RFC4443 4.2.] */

  if (LenByte < sizeof(IpV6_IcmpEchoRequestType))
  {
    /* Silently discard Echo Request with incomplete header */
    return; 
  }

  IcmpEchoReqPtr = (P2CONST(IpV6_IcmpEchoRequestType, AUTOMATIC, IPV6_APPL_VAR))&DataPtr[0]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

  IpV6_Icmp_PendingEchoReply.SrcAddrId = AddrId;

  /* send echo reply to the sender of the request */
  IPV6_ADDR_COPY(IpV6_Icmp_PendingEchoReply.DstAddr, *SrcAddrPtr); /* PRQA S 0310 */ /* MD_IpV6_0310 */

  IcmpEchoReplyPtr = (P2VAR(IpV6_IcmpEchoReplyType, AUTOMATIC, IPV6_VAR_NOINIT))&IpV6_IcmpEchoDataBuffer[0]; /* PRQA S 0310 */ /* MD_IpV6_0310 */
  IcmpEchoReplyPtr->IdentifierNbo     = IcmpEchoReqPtr->IdentifierNbo;
  IcmpEchoReplyPtr->SequenceNumberNbo = IcmpEchoReqPtr->SequenceNumberNbo;

  IpV6_Icmp_PendingEchoReply.Type = IPV6_ICMP_MSG_TYPE_ECHO_REPLY;
  IpV6_Icmp_PendingEchoReply.Code = 0;

  if (LenByte > IPV6_ICMP_ECHO_BUFFER_SIZE)
  {
    /* truncate echo request data to configured maximum size */
    LenByte = IPV6_ICMP_ECHO_BUFFER_SIZE;
  }

  IpV6_MemCpy(&IpV6_IcmpEchoDataBuffer[sizeof(IpV6_IcmpEchoReplyType)], &DataPtr[sizeof(IpV6_IcmpEchoRequestType)], (LenByte - sizeof(IpV6_IcmpEchoRequestType))); /* PRQA S 0310 */ /* MD_IpV6_0310 */
  IpV6_Icmp_PendingEchoReply.PayloadPtr = &IpV6_IcmpEchoDataBuffer[0];
  IpV6_Icmp_PendingEchoReply.PayloadLen = LenByte;
  IpV6_Icmp_PendingEchoReply.Pending    = TRUE;

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_VRxEchoRequest() */
#endif

#if (IPV6_ICMP_ENABLE_ERR_MSG_DESTINATION_UNREACHABLE == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxErrDestinationUnreachable()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxErrDestinationUnreachable(
  uint8                                             Code,
  P2CONST(IpV6_AddrType, AUTOMATIC, IPV6_APPL_DATA) SrcAddrPtr,
  P2CONST(uint8, AUTOMATIC, IPV6_APPL_DATA)         DataPtr,
  uint16                                            LenByte)
{
  IPV6_P2C(uint8)                           OrigPktPtr;
  uint16                                    OrigPktLen;
  IPV6_P2C(uint8)                           MultiPartExtPtr;
  uint16                                    MultiPartExtLen;
  IPV6_P2C(IpV6_IcmpDestUnreachableMsgType) DestUnreachableMsgHdrPtr;

#if (IPV6_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != SrcAddrPtr), IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != DataPtr),    IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
#else
  IPV6_UNUSED_PARAMETER(SrcAddrPtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  if ((LenByte < sizeof(IpV6_IcmpDestUnreachableMsgType)) || (IPV6_ICMP_ERR_MSG_MAX_PAYLOAD_SIZE < LenByte))
  {
    /* invalid message length */
    return; /* silently ignore invalid packet */
  }

  /* The Destination Unreachable message defined in [RFC4443 3.1.] starts with 4 unused bytes.
   * [RFC4884 4.4.] maps a length field on the first byte and holds the length of the original packet payload in 64-bit words.
   */
  DestUnreachableMsgHdrPtr = (IPV6_P2C(IpV6_IcmpDestUnreachableMsgType))&DataPtr[0]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

  OrigPktPtr = (IPV6_P2C(uint8))&DataPtr[sizeof(IpV6_IcmpDestUnreachableMsgType)];

  if (0 == DestUnreachableMsgHdrPtr->Length)
  {
    /* [RFC4884 5.4. Compliant Application Receives ICMP Message with No Extensions] */
    OrigPktLen = (uint16)(LenByte - sizeof(IpV6_IcmpDestUnreachableMsgType));
    MultiPartExtLen = 0;
    MultiPartExtPtr = (IPV6_P2C(uint8))NULL_PTR;
  }
  else
  {
    /* message seems to be a multi-part message */
    uint16 OrigPktEndOfs;
    IPV6_P2C(IpV6_IcmpMultiPartExtHdr) MultiPartExtHdrPtr;

    OrigPktLen = (DestUnreachableMsgHdrPtr->Length * 8); /* length is number of 64bit words */

    if (IPV6_ICMP_MIN_ORIG_PKT_LEN > OrigPktLen)
    {
      /* original packet payload length must be at least 128 byte (zero-padded if necessary) */
      return; /* silently ignore invalid packet */
    }

    OrigPktEndOfs = sizeof(IpV6_IcmpDestUnreachableMsgType) + OrigPktLen;

    if (OrigPktEndOfs > LenByte)
    {
      /* original packet payload length exceeds ICMP payload length. */
      return; /* silently ignore invalid packet */
    }

    MultiPartExtLen = (LenByte - OrigPktEndOfs);

    /* check for ICMP Extension Structure [RFC4884 7.] */
    if (MultiPartExtLen < sizeof(IpV6_IcmpMultiPartExtHdr))
    {
      /* incomplete multi-part extension header */
      return; /* silently ignore invalid packet */
    }

    MultiPartExtHdrPtr = (IPV6_P2C(IpV6_IcmpMultiPartExtHdr))&DataPtr[OrigPktEndOfs]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

    if (2 != (MultiPartExtHdrPtr->VerReserved >> 4))
    {
      /* Unknown multi-part extension header version. */
      return; /* silently ignore invalid packet */
    }

    MultiPartExtPtr = &DataPtr[OrigPktEndOfs + sizeof(IpV6_IcmpMultiPartExtHdr)];
    MultiPartExtLen -= sizeof(IpV6_IcmpMultiPartExtHdr);

    if (0 != MultiPartExtHdrPtr->ChecksumNbo)
    {
      uint16 CalculatedChecksumNbo;

      /* validate checksum */
      CalculatedChecksumNbo = (uint16)IpBase_TcpIpChecksumAdd(MultiPartExtPtr, MultiPartExtLen, (((uint32)MultiPartExtHdrPtr->VerReserved) << IPV6_BITS_IN_BYTE), TRUE);

      if (0 == CalculatedChecksumNbo)
      {
        CalculatedChecksumNbo = 0xFFFFU; /* one's complement checksum has two values for zero */
      }

      if (MultiPartExtHdrPtr->ChecksumNbo != CalculatedChecksumNbo)
      {
        /* invalid extension options checksum */
        return; /* silently ignore invalid packet */
      }
    }
    else
    {
      /* An all-zero value means that no checksum was transmitted.
       * [RFC4884 7. The ICMP Extension Structure]
       */
      return; /* silently ignore invalid packet */
    }
  }

  /* notify upper-layers */
  IpV6_Icmp_HandleDestinationUnreachableMsg(Code, OrigPktPtr, OrigPktLen, MultiPartExtPtr, MultiPartExtLen);

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_VRxErrDestinationUnreachable() */ /* PRQA S 6010 */ /* MD_MSR_STPTH */
#endif

#if (IPV6_ENABLE_PATH_MTU == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxErrPacketTooBig()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxErrPacketTooBig(
  uint8                   AddrId,
  IPV6_P2C(IpV6_AddrType) SrcAddrPtr,
  IPV6_P2C(uint8)         DataPtr,
  uint16                  LenByte)
{
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV6_05.06 */
  P2CONST(IpV6_IcmpPacketTooBigMsgType, AUTOMATIC, IPV6_APPL_DATA) PktTooBigMsgPtr;
  P2CONST(IpV6_HdrType, AUTOMATIC, IPV6_APPL_DATA) OrgIpV6HdrPtr;
  IpV6_ListIdxType DcEntryIdx;

#if (IPV6_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnVoid(IPV6_IS_VALID_ADDR_ID(AddrId), IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_ADDR_ID);
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != SrcAddrPtr),      IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != DataPtr),         IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
#else
  IPV6_UNUSED_PARAMETER(SrcAddrPtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  IPV6_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx,   AddrId);

  if (!IpV6_VCfgIsPathMtuEnabled())
  {
    return;
  }

  if ((LenByte < sizeof(IpV6_IcmpPacketTooBigMsgType)) || (IPV6_ICMP_ERR_MSG_MAX_PAYLOAD_SIZE < LenByte))
  {
    /* invalid message length */
    return; /* silently ignore invalid packet */
  }

  /* PRQA S 0310 2 */ /* MD_IpV6_0310 */
  PktTooBigMsgPtr = (P2CONST(IpV6_IcmpPacketTooBigMsgType, AUTOMATIC, IPV6_APPL_DATA))&DataPtr[0];
  OrgIpV6HdrPtr   = (P2CONST(IpV6_HdrType,                 AUTOMATIC, IPV6_APPL_DATA))&DataPtr[sizeof(IpV6_IcmpPacketTooBigMsgType)];

  /* MTU available for upper layer = MTU - 40 (IPv6 Hdr) - x (IPv6 Ext Hdrs) */

  if (E_OK == IpV6_Ndp_VDCLookup(IpCtrlIdx, &OrgIpV6HdrPtr->DstAddr, &DcEntryIdx))
  {
    /* destination cache entry found */
    IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].MtuReported = IPV6_NTOHS((uint16)PktTooBigMsgPtr->MtuNbo);

    if ((IPV6_MINIMUM_MTU < IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].Mtu) && (IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].MtuReported < IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].Mtu))
    {
      if (IPV6_MINIMUM_MTU <= IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].MtuReported)
      {
        IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].Mtu = IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].MtuReported;
      }
      else
      {
        IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].Mtu = IPV6_MINIMUM_MTU;
      }

      IPV6_SET_LIFETIME_S(IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].MtuTimeout, IpV6_VCfgGetPathMtuTimeout(), (IPV6_P2V(IpV6_TimeType))NULL_PTR);

      {
        uint16 UpperLayerPayloadLen = (uint16)(IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].Mtu - IPV6_HDR_LEN);
        IpBase_SockAddrIn6Type SockAddrIn6;

        if (IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].MtuReported < IPV6_MINIMUM_MTU)
        {
          /* See [RFC2460 5. Packet Size Issues] */
          UpperLayerPayloadLen -= IPV6_FRAGMENT_EXT_HDR_LEN;
        }

        SockAddrIn6.sin6_family = IPBASE_AF_INET6;
        SockAddrIn6.sin6_port   = 0;
        IPV6_ADDR_COPY(SockAddrIn6.sin6_addr, IPV6_CTRL_VAR(IpV6_DestinationCache)[DcEntryIdx].DestinationAddress); /* PRQA S 0310 */ /* MD_IpV6_0310 */

        TcpIp_Cbk_VPathMtuChg(    IPV6_CTRLIDX_IP_2_ETHIF(IpCtrlIdx), (IPV6_P2C(IpBase_SockAddrType))&SockAddrIn6, UpperLayerPayloadLen); /* PRQA S 0310 */ /* MD_IpV6_0310 */

# if (0 < IPV6_MAX_PAYLOAD_LEN_CHG_CBK_COUNT)
        IpV6_MaxPayloadLenChgCbks(IPV6_CTRLIDX_IP_2_ETHIF(IpCtrlIdx), (IPV6_P2C(IpBase_SockAddrType))&SockAddrIn6, UpperLayerPayloadLen); /* PRQA S 0310 */ /* MD_IpV6_0310 */
# endif
      }
    }
  }

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_VRxErrPacketTooBig() */
#endif

#if (IPV6_ICMP_ENABLE_ERR_MSG_TIME_EXCEEDED == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxErrTimeExceeded()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxErrTimeExceeded(
  uint8 Code,
  P2CONST(IpV6_AddrType, AUTOMATIC, IPV6_APPL_DATA) SrcAddrPtr,
  P2CONST(uint8, AUTOMATIC, IPV6_APPL_DATA) DataPtr,
  uint16 LenByte)
{
  IPV6_P2C(uint8)                        OrigPktPtr;
  uint16                                 OrigPktLen;
  IPV6_P2C(uint8)                        MultiPartExtPtr;
  uint16                                 MultiPartExtLen;
  IPV6_P2C(IpV6_IcmpTimeExceededMsgType) TimeExceededMsgHdrPtr;

#if (IPV6_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != SrcAddrPtr), IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != DataPtr),    IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
#else
  IPV6_UNUSED_PARAMETER(SrcAddrPtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  if ((LenByte < sizeof(IpV6_IcmpTimeExceededMsgType)) || (IPV6_ICMP_ERR_MSG_MAX_PAYLOAD_SIZE < LenByte))
  {
    /* invalid message length */
    return; /* silently ignore invalid packet */
  }

  /* The Time Exceeded message defined in [RFC4443 3.1.] starts with 4 unused bytes.
   * [RFC4884 4.4.] maps a length field on the first byte and holds the length of the original packet payload in 64-bit words.
   */
  TimeExceededMsgHdrPtr = (IPV6_P2C(IpV6_IcmpTimeExceededMsgType))&DataPtr[0]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

  OrigPktPtr = (IPV6_P2C(uint8))&DataPtr[sizeof(IpV6_IcmpTimeExceededMsgType)];

  if (0 == TimeExceededMsgHdrPtr->Length)
  {
    /* [RFC4884 5.4. Compliant Application Receives ICMP Message with No Extensions] */
    OrigPktLen = (uint16)(LenByte - sizeof(IpV6_IcmpTimeExceededMsgType));
    MultiPartExtLen = 0;
    MultiPartExtPtr = (IPV6_P2C(uint8))NULL_PTR;
  }
  else
  {
    /* message seems to be a multi-part message */
    uint16 OrigPktEndOfs;
    IPV6_P2C(IpV6_IcmpMultiPartExtHdr) MultiPartExtHdrPtr;

    OrigPktLen = (TimeExceededMsgHdrPtr->Length * 8); /* length is number of 64bit words */

    if (IPV6_ICMP_MIN_ORIG_PKT_LEN > OrigPktLen)
    {
      /* original packet payload length must be at least 128 byte (zero-padded if necessary) */
      return; /* silently ignore invalid packet */
    }

    OrigPktEndOfs = sizeof(IpV6_IcmpTimeExceededMsgType) + OrigPktLen;

    if (OrigPktEndOfs > LenByte)
    {
      /* original packet payload length exceeds ICMP payload length. */
      return; /* silently ignore invalid packet */
    }

    MultiPartExtLen = (LenByte - OrigPktEndOfs);

    /* check for ICMP Extension Structure [RFC4884 7.] */
    if (MultiPartExtLen < sizeof(IpV6_IcmpMultiPartExtHdr))
    {
      /* incomplete multi-part extension header */
      return; /* silently ignore invalid packet */
    }

    MultiPartExtHdrPtr = (IPV6_P2C(IpV6_IcmpMultiPartExtHdr))&DataPtr[OrigPktEndOfs]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

    if (2 != (MultiPartExtHdrPtr->VerReserved >> 4))
    {
      /* Unknown multi-part extension header version. */
      return; /* silently ignore invalid packet */
    }

    MultiPartExtPtr = &DataPtr[OrigPktEndOfs + sizeof(IpV6_IcmpMultiPartExtHdr)]; /* PRQA S 0310 */ /* MD_IpV6_0310 */
    MultiPartExtLen -= sizeof(IpV6_IcmpMultiPartExtHdr);

    if (0 != MultiPartExtHdrPtr->ChecksumNbo)
    {
      uint16 CalculatedChecksumNbo;

      /* validate checksum */
      CalculatedChecksumNbo = (uint16)IpBase_TcpIpChecksumAdd(MultiPartExtPtr, MultiPartExtLen, (((uint32)MultiPartExtHdrPtr->VerReserved) << IPV6_BITS_IN_BYTE), TRUE);

      if (0 == CalculatedChecksumNbo)
      {
        CalculatedChecksumNbo = 0xFFFFU; /* one's complement checksum has two values for zero */
      }

      if (MultiPartExtHdrPtr->ChecksumNbo != CalculatedChecksumNbo)
      {
        /* invalid extension options checksum */
        return; /* silently ignore invalid packet */
      }
    }
    else
    {
      /* An all-zero value means that no checksum was transmitted.
       * [RFC4884 7. The ICMP Extension Structure]
       */
      return; /* silently ignore invalid packet */
    }
  }

  /* notify upper-layers */
  IpV6_Icmp_HandleTimeExceededMsg(Code, OrigPktPtr, OrigPktLen, MultiPartExtPtr, MultiPartExtLen);

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_VRxErrTimeExceeded() */ /* PRQA S 6010 */ /* MD_MSR_STPTH */
#endif

#if (IPV6_ICMP_ENABLE_ERR_MSG_PARAMETER_PROBLEM == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VRxErrParameterProblem()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV6_CODE) IpV6_Icmp_VRxErrParameterProblem(
  uint8 Code,
  P2CONST(IpV6_AddrType, AUTOMATIC, IPV6_APPL_DATA) SrcAddrPtr,
  P2CONST(uint8, AUTOMATIC, IPV6_APPL_DATA) DataPtr,
  uint16 LenByte)
{

#if (IPV6_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != SrcAddrPtr), IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != DataPtr),    IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
#endif

  if ((LenByte < sizeof(IpV6_IcmpParameterProblemErrMsgType)) || (IPV6_ICMP_ERR_MSG_MAX_PAYLOAD_SIZE < LenByte))
  {
    /* invalid message length */
    return; /* silently ignore invalid packet */
  }

} /* End of IpV6_Icmp_VRxErrParameterProblem() */
#endif

#if ((IPV6_ENABLE_ICMP_ERR_MSGS == STD_ON) || (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON))
/**********************************************************************************************************************
 *  IpV6_Icmp_VTxPendingMessage()
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, IPV6_CODE) IpV6_Icmp_VTxPendingMessage(
  P2CONST(IpV6_Icmp_MsgInstanceType, AUTOMATIC, IPV6_APPL_DATA) PendingMsgPtr)
{
  TcpIp_IpTxRequestDescriptorType IpTxReqDesc;
  IPV6_P2V(uint8)                 IcmpBufPtr;
  uint16                          IcmpBufLen;
  IpV6_AddrIdType                 AddrId;

  IcmpBufLen = PendingMsgPtr->PayloadLen;

  AddrId    = PendingMsgPtr->SrcAddrId;

  /* try to send response */
  if (BUFREQ_OK != IpV6_Icmp_ProvideTxBuffer(&AddrId, IPV6_SOCK_IDX_ICMP, &IpTxReqDesc, &PendingMsgPtr->DstAddr, &IcmpBufPtr, &IcmpBufLen))
  {
    return E_NOT_OK;
  }

  IpV6_MemCpy(&IcmpBufPtr[0], &PendingMsgPtr->PayloadPtr[0], PendingMsgPtr->PayloadLen); /* PRQA S 0310 */ /* MD_IpV6_0310 */

  return IpV6_Icmp_Transmit(IPV6_SOCK_IDX_ICMP, &IpTxReqDesc, PendingMsgPtr->Type, PendingMsgPtr->Code, PendingMsgPtr->PayloadLen);

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_VTxPendingMessage() */
#endif

#if (IPV6_ENABLE_ICMP_TX_PARAM_PROBLEM == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VTxErrParameterProblem()
 **********************************************************************************************************************/
FUNC(void, IPV6_CODE) IpV6_Icmp_VTxErrParameterProblem(
  IpV6_AddrIdType                           AddrId,
  uint8 Code,
  P2CONST(uint8, AUTOMATIC, IPV6_APPL_DATA) IpV6PktDataPtr,
  uint16 IpV6PktDataLen,
  uint16 IpV6PktDataOffs)
{
  uint16 MaxOrgPktLen;
  P2CONST(IpV6_HdrType, AUTOMATIC, IPV6_APPL_DATA)                       IpV6HdrPtr;
  P2VAR(IpV6_IcmpParameterProblemErrMsgType, AUTOMATIC, IPV6_VAR_NOINIT) MsgPtr;

  /* Total length of ICMP message MUST NOT exceed the minimum reassembly buffer size. */
#if (IpV6_VCfgGetIcmpTxMsgBufferSize() > IPV6_ICMP_ERR_MSG_MAX_PAYLOAD_SIZE)
  MaxOrgPktLen = IPV6_ICMP_ERR_MSG_MAX_PAYLOAD_SIZE;
#else
  /* Size of message is limited by IcmpTxMsgBufferSize */
  MaxOrgPktLen = IpV6_VCfgGetIcmpTxMsgBufferSize();
#endif

  MaxOrgPktLen -= sizeof(IpV6_IcmpParameterProblemErrMsgType);

  if (IpV6PktDataLen > MaxOrgPktLen)
  {
    IpV6PktDataLen = MaxOrgPktLen;
  }

  MsgPtr = (P2VAR(IpV6_IcmpParameterProblemErrMsgType, AUTOMATIC, IPV6_VAR_NOINIT))&IpV6_IcmpTxMsgBuffer[0]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

  MsgPtr->PointerNbo = IPV6_UINT16_HTONL(IpV6PktDataOffs);

  IpV6_MemCpy(&IpV6_IcmpTxMsgBuffer[sizeof(IpV6_IcmpParameterProblemErrMsgType)], IpV6PktDataPtr, IpV6PktDataLen); /* PRQA S 0310 */ /* MD_IpV6_0310 */

  IpV6HdrPtr = (P2CONST(IpV6_HdrType, AUTOMATIC, IPV6_APPL_DATA))&IpV6PktDataPtr[0]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

  if ((IPV6_ADDR_IS_MULTICAST(IpV6HdrPtr->DstAddr) && (Code != 2)) || IPV6_ADDR_IS_MULTICAST(IpV6HdrPtr->SrcAddr) || IPV6_ADDR_IS_UNSPECIFIED(IpV6HdrPtr->SrcAddr)) /* PRQA S 3415 */ /* MD_IpV6_3415 */
  {
    /* [RFC4443 2.4. Message Processing Rules]
       "(e) An ICMPv6 error message MUST NOT be originated as a result of
           receiving the following:"
       "(e.3) A packet destined to an IPv6 multicast address.  (There are
              two exceptions to this rule: (1) the Packet Too Big Message
              (Section 3.2) to allow Path MTU discovery to work for IPv6
              multicast, and (2) the Parameter Problem Message, Code 2
              (Section 3.4) reporting an unrecognized IPv6 option (see
              Section 4.2 of [IPv6]) that has the Option Type highest-
              order two bits set to 10).
              [...]
        (e.6) A packet whose source address does not uniquely identify a
              single node -- e.g., the IPv6 Unspecified Address, an IPv6
              multicast address, or an address known by the ICMP message
              originator to be an IPv6 anycast address." */

    return; /* abort sending ICMP error message */
  }

  IPV6_ADDR_COPY(IpV6_Icmp_PendingMsg.DstAddr, IpV6HdrPtr->SrcAddr); /* PRQA S 0310 */ /* MD_IpV6_0310 */

  /* If the original packet has been sent to a multicast address, AddrId will be an AutoSelect_Multicast id.
   * This id can be used for the response as well since the IpV6 will automatically select a suitable source address.
   */
  IpV6_Icmp_PendingMsg.SrcAddrId  = AddrId;
  IpV6_Icmp_PendingMsg.Type       = IPV6_ICMP_MSG_TYPE_PARAM_PROBLEM;
  IpV6_Icmp_PendingMsg.Code       = Code;
  IpV6_Icmp_PendingMsg.PayloadPtr = &IpV6_IcmpTxMsgBuffer[0];
  IpV6_Icmp_PendingMsg.PayloadLen = sizeof(IpV6_IcmpParameterProblemErrMsgType) + IpV6PktDataLen;
  IpV6_Icmp_PendingMsg.Pending    = TRUE;

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_VTxErrParameterProblem() */
#endif

#if (IPV6_ENABLE_RX_FRAGMENTATION == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_VTxTimeExceeded()
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV6_CODE) IpV6_Icmp_VTxTimeExceeded(
  IpV6_AddrIdType         AddrId,
  IPV6_P2C(IpV6_AddrType) SrcAddrPtr,
  uint8                   Code,
  IPV6_P2V(uint8*)        OrigPktDataPtr,
  IPV6_P2V(uint16)        OrigPktDataLenPtr,
  IPV6_P2C(uint8)         MultiPartExtPtr,
  uint16                  MultiPartExtLen)
{
  uint16                                 MaxOrigPktLen;
  uint8_least                            PaddingByteCount = 0;
  IPV6_P2V(IpV6_IcmpTimeExceededMsgType) TimeExceededMsgHdrPtr;
  uint16                                 IcmpPayloadOfs;
  uint16                                 OrigPktDataLen = (*OrigPktDataLenPtr);

  if (OrigPktDataLen < sizeof(IpV6_HdrType))
  {
    /* invalid original packet length */
    return E_NOT_OK;
  }

  if ((IPV6_CTRL_ADDR_IDX_INV_OR_ANY == IPV6_ADDR_ID_2_ADDR_IDX(AddrId)) || IPV6_ADDR_IS_MULTICAST(*SrcAddrPtr) || IPV6_ADDR_IS_UNSPECIFIED(*SrcAddrPtr)) /* PRQA S 3415 */ /* MD_IpV6_3415 */
  {
    /* [RFC4443 2.4. Message Processing Rules]
       "(e) An ICMPv6 error message MUST NOT be originated as a result of
           receiving the following:"
       "(e.3) A packet destined to an IPv6 multicast address. [...]
        (e.6) A packet whose source address does not uniquely identify a
              single node -- e.g., the IPv6 Unspecified Address, an IPv6
              multicast address, or an address known by the ICMP message
              originator to be an IPv6 anycast address." */

    return E_NOT_OK; /* abort sending ICMP error message */
  }

  /* "[...] the total length of the ICMP message, including extensions,
   *  MUST NOT exceed the minimum reassembly buffer size."
   *  [RFC4884 7. The ICMP Extension Structure]
   */

#if (IpV6_VCfgGetIcmpTxMsgBufferSize() > IPV6_ICMP_ERR_MSG_MAX_PAYLOAD_SIZE)
  MaxOrigPktLen = IPV6_ICMP_ERR_MSG_MAX_PAYLOAD_SIZE;
#else
  /* Size of message is limited by IcmpTxMsgBufferSize */
  MaxOrigPktLen = IpV6_VCfgGetIcmpTxMsgBufferSize();
#endif

  MaxOrigPktLen -= sizeof(IpV6_IcmpTimeExceededMsgType);

  if (0 < MultiPartExtLen)
  {
    /* Check if original packet und multi part data fit into ICMP message buffer.
     * In multi-part messages the original packet must be at least 128 bytes (zero-padded if necessary)
     */
    if (MaxOrigPktLen < (IPV6_ICMP_MIN_ORIG_PKT_LEN + sizeof(IpV6_IcmpMultiPartExtHdr) + MultiPartExtLen))
    {
      /* too much payload */
      return E_NOT_OK;
    }

    /* keep space for multi-part data after the original packet */
    MaxOrigPktLen -= (sizeof(IpV6_IcmpMultiPartExtHdr) + MultiPartExtLen);

    /* maximum original packet length must be a multiple of 8 byte (64 bit) */
    MaxOrigPktLen -= (MaxOrigPktLen % 8);
  }

  if (OrigPktDataLen > MaxOrigPktLen)
  {
    /* truncate original packet */
    OrigPktDataLen = MaxOrigPktLen;
  }

  TimeExceededMsgHdrPtr = (IPV6_P2V(IpV6_IcmpTimeExceededMsgType))&IpV6_IcmpTxMsgBuffer[0]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

  if (0 < MultiPartExtLen)
  {
    /* according to [RFC4884 4.5. ICMPv6 Time Exceeded] we have to pad the original packet to a multiple of 8 octets. */
    if (OrigPktDataLen < IPV6_ICMP_MIN_ORIG_PKT_LEN)
    {
      PaddingByteCount = (uint8_least)(IPV6_ICMP_MIN_ORIG_PKT_LEN - OrigPktDataLen);
    }
    else if (0 < (OrigPktDataLen % 8))
    {
      PaddingByteCount = (uint8_least)(8 - (OrigPktDataLen % 8));
    }
    else
    {
      /* leave PaddingByteCount zero */
    }

    /* write length of original packet data to first */
    TimeExceededMsgHdrPtr->Length = (uint8)((OrigPktDataLen + PaddingByteCount) / 8);
  }
  else
  {
    /* In non-multi-part messages the length field is unused */
    TimeExceededMsgHdrPtr->Length = 0;
  }

  TimeExceededMsgHdrPtr->Reserved = 0;
  TimeExceededMsgHdrPtr->Reserved16 = 0;

  IcmpPayloadOfs = sizeof(IpV6_IcmpTimeExceededMsgType);

  /* return buffer and length for original packet payload. Caller will copy data directly into the buffer */
  (*OrigPktDataPtr)    = &IpV6_IcmpTxMsgBuffer[IcmpPayloadOfs];
  (*OrigPktDataLenPtr) = OrigPktDataLen;

  IcmpPayloadOfs += OrigPktDataLen;

  if (0 < MultiPartExtLen)
  {
    uint16 MultiPartExtHdrOfs;
    IPV6_P2V(IpV6_IcmpMultiPartExtHdr) MultiPartExtHdrPtr;

    /* add padding bytes to original packet if necessary */
    while (PaddingByteCount > 0)
    {
      PaddingByteCount--;
      IpV6_IcmpTxMsgBuffer[IcmpPayloadOfs] = 0;
      IcmpPayloadOfs++;
    }

    MultiPartExtHdrOfs = IcmpPayloadOfs;

    MultiPartExtHdrPtr = (IPV6_P2V(IpV6_IcmpMultiPartExtHdr))&IpV6_IcmpTxMsgBuffer[MultiPartExtHdrOfs]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

    MultiPartExtHdrPtr->VerReserved = 0x20; /* MSB nibble = 2, indicates version 2 */
    MultiPartExtHdrPtr->Reserved = 0;
    MultiPartExtHdrPtr->ChecksumNbo = 0; /* Set to zero for calculation. */

    IcmpPayloadOfs += sizeof(IpV6_IcmpMultiPartExtHdr);

    /* copy multi-part data into icmp tx buffer */
    IpV6_MemCpy(&IpV6_IcmpTxMsgBuffer[IcmpPayloadOfs], MultiPartExtPtr, MultiPartExtLen); /* PRQA S 0310 */ /* MD_IpV6_0310 */

    IcmpPayloadOfs += MultiPartExtLen;

    /* calculate checksum over multi-part data */
    MultiPartExtHdrPtr->ChecksumNbo = (uint16)IpBase_TcpIpChecksumAdd(&IpV6_IcmpTxMsgBuffer[MultiPartExtHdrOfs], ((uint32)sizeof(IpV6_IcmpMultiPartExtHdr) + MultiPartExtLen), 0, TRUE);

    if (0 == MultiPartExtHdrPtr->ChecksumNbo)
    {
      /* one's complement checksum has two values for zero.
       * An all-zero value would mean that no checksum was transmitted.
       * So we use 0xFFFF to indicate a valid zero checksum.
       * [RFC4884 7. The ICMP Extension Structure]
       */
      MultiPartExtHdrPtr->ChecksumNbo = 0xFFFFU;
    }
  }

  IPV6_ADDR_COPY(IpV6_Icmp_PendingMsg.DstAddr, *SrcAddrPtr); /* PRQA S 0310 */ /* MD_IpV6_0310 */

  IpV6_Icmp_PendingMsg.SrcAddrId  = AddrId;
  IpV6_Icmp_PendingMsg.Type       = IPV6_ICMP_MSG_TYPE_TIME_EXCEEDED;
  IpV6_Icmp_PendingMsg.Code       = Code;
  IpV6_Icmp_PendingMsg.PayloadPtr = &IpV6_IcmpTxMsgBuffer[0];
  IpV6_Icmp_PendingMsg.PayloadLen = IcmpPayloadOfs;
  IpV6_Icmp_PendingMsg.Pending    = TRUE;

  return E_OK;
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_VTxTimeExceeded() */ /* PRQA S 6010, 6030, 6050, 6060 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR */
#endif

#if (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_Cbk_DestinationUnreachable()
 **********************************************************************************************************************/
FUNC(void, IPV6_CODE) IpV6_Icmp_Cbk_DestinationUnreachable(
  P2CONST(IpV6_AddrType, AUTOMATIC, IPV6_APPL_DATA) DstAddrPtr)
{
  if (TRUE == IpV6_Icmp_PendingEchoReply.Pending)
  {
    if (IPV6_ADDR_EQUALS(IpV6_Icmp_PendingEchoReply.DstAddr, *DstAddrPtr))
    {
      /* cancel sending of pending echo request, since the destination is unreachable */
      IpV6_Icmp_PendingEchoReply.Pending = FALSE;
    }
  }
} /* End of IpV6_Icmp_Cbk_DestinationUnreachable() */
#endif

/**********************************************************************************************************************
 *  IpV6_Icmp_VPacketReceived()
 **********************************************************************************************************************/
FUNC(void, IPV6_CODE) IpV6_Icmp_VPacketReceived(
  IpV6_AddrIdType        AddrId,
  IPV6_P2C(IpV6_HdrType) IpV6HdrPtr,
  IPV6_P2C(uint8)        DataPtr,
  uint16                 IcmpHdrPos,
  uint16                 LenByte
#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
  , boolean ChecksumCalculated
#endif
  )
{
  uint8  IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV6_05.06 */
  uint16 CalculatedChecksumNbo;
  uint16 IcmpPayloadLen;
  uint16 IcmpPayloadOfs;

  IPV6_P2C(IpV6_IcmpHeaderType) IcmpHdrPtr;
  IPV6_P2C(uint8)               IcmpPayloadPtr;

#if (IPV6_VENABLE_INTERNAL_DET_CHECKS == STD_ON)
  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnVoid(IPV6_IS_VALID_ADDR_ID(AddrId), IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_ADDR_ID);
  IpV6_CheckDetErrorReturnVoid(LenByte > IcmpHdrPos,          IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_PARAM);
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != IpV6HdrPtr),      IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
  IpV6_CheckDetErrorReturnVoid((NULL_PTR != DataPtr),         IPV6_API_ID_V_INTERNAL_FUNCTION, IPV6_E_INV_POINTER);
#endif

  if (LenByte < (IcmpHdrPos + sizeof(IpV6_IcmpHeaderType)))
  {
    return; /* ignore invalid message with incomplete ICMPv6 header. */
  }

  IPV6_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx,   AddrId);

  IcmpHdrPtr = (IPV6_P2C(IpV6_IcmpHeaderType))&DataPtr[IcmpHdrPos]; /* PRQA S 0310 */ /* MD_IpV6_0310 */

#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
  if(ChecksumCalculated == FALSE)
#endif
  {
    CalculatedChecksumNbo = IpV6_Icmp_VCalculateChecksumNbo(&IpV6HdrPtr->SrcAddr, &IpV6HdrPtr->DstAddr, &DataPtr[IcmpHdrPos], LenByte - IcmpHdrPos);

    if (IcmpHdrPtr->ChecksumNbo != CalculatedChecksumNbo)
    {
      /* invalid cecksum, drop packet */
      return;
    }
  }

  IcmpPayloadOfs = IcmpHdrPos + sizeof(IpV6_IcmpHeaderType);
  IcmpPayloadPtr = &DataPtr[IcmpPayloadOfs];
  IcmpPayloadLen = LenByte - IcmpPayloadOfs;

  switch (IcmpHdrPtr->Type)
  {
#if (IPV6_ICMP_ENABLE_ERR_MSG_DESTINATION_UNREACHABLE == STD_ON)

  case IPV6_ICMP_MSG_TYPE_DEST_UNREACHABLE: /* Type 1 */
    IpV6_Icmp_VRxErrDestinationUnreachable(IcmpHdrPtr->Code, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    break;
#endif

    /* Type 2 */
#if (IPV6_ENABLE_PATH_MTU == STD_ON)
  case IPV6_ICMP_MSG_TYPE_PKT_TOO_BIG:      /* Type 2 */
      if (IpV6_VCfgIsPathMtuEnabled())
      {
        IpV6_Icmp_VRxErrPacketTooBig(AddrId, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
      }
    break;
#endif

    /* Type 3 */
#if (IPV6_ICMP_ENABLE_ERR_MSG_TIME_EXCEEDED == STD_ON)
  case IPV6_ICMP_MSG_TYPE_TIME_EXCEEDED:    /* Type 3 */
      IpV6_Icmp_VRxErrTimeExceeded(IcmpHdrPtr->Code, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    break;
#endif

    /* Type 4 */
#if (IPV6_ICMP_ENABLE_ERR_MSG_PARAMETER_PROBLEM == STD_ON)
  case IPV6_ICMP_MSG_TYPE_PARAM_PROBLEM:    /* Type 4 */
      IpV6_Icmp_VRxErrParameterProblem(IcmpHdrPtr->Code, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    break;
#endif

#if (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON)
  case IPV6_ICMP_MSG_TYPE_ECHO_REQ:         /* Type 128 */
    IpV6_Icmp_VRxEchoRequest(AddrId, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    break;
#endif

#if (IPV6_ENABLE_ICMP_ECHO_REQUEST_API == STD_ON)
  case IPV6_ICMP_MSG_TYPE_ECHO_REPLY:       /* Type 129 */
    /* Processing and forwarding received ICMPv6 Echo Reply to upper-layer is currently not implemented */
    break;
#endif

#if (IPV6_ICMP_ENABLE_NDP == STD_ON)

  case IPV6_ICMP_MSG_TYPE_NDP_RA:           /* Type 134 */

    /* perform basic validation of RA (RFC4861 6.1.2) */
    if ((IPV6_NDP_MSG_HOP_LIMIT == IpV6HdrPtr->HopLimit) && (0 == IcmpHdrPtr->Code) && (IPV6_NDP_RA_MIN_PAYLOAD_LEN <= IcmpPayloadLen))
    {
      IpV6_Ndp_VRxRouterAdvertisement(AddrId, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    }

    break;

  case IPV6_ICMP_MSG_TYPE_NDP_NS:           /* Type 135 */

    /* perform basic validation of NS (RFC4861 7.1.1) */
    if ((IPV6_NDP_MSG_HOP_LIMIT == IpV6HdrPtr->HopLimit) && (0 == IcmpHdrPtr->Code) && (IPV6_NDP_NS_MIN_PAYLOAD_LEN <= IcmpPayloadLen))
    {
      IpV6_Ndp_VRxNeighborSolicitation(AddrId, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    }

    break;

  case IPV6_ICMP_MSG_TYPE_NDP_NA:           /* Type 136 */

    /* perform basic validation of NA (RFC4861 7.1.2) */
    if ((IPV6_NDP_MSG_HOP_LIMIT == IpV6HdrPtr->HopLimit) && (0 == IcmpHdrPtr->Code) && (IPV6_NDP_NA_MIN_PAYLOAD_LEN <= IcmpPayloadLen))
    {
      IpV6_Ndp_VRxNeighborAdvertisement(AddrId, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    }

    break;

  case IPV6_ICMP_MSG_TYPE_NDP_REDIR:        /* Type 137 */

    /* perform basic validation of Redirect (RFC4861 8.1) */
    if ((IPV6_NDP_MSG_HOP_LIMIT == IpV6HdrPtr->HopLimit) && (0 == IcmpHdrPtr->Code) && (IPV6_NDP_REDIR_MIN_PAYLOAD_LEN <= IcmpPayloadLen))
    {
      IpV6_Ndp_VRxRedirect(AddrId, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    }

    break;

#endif /* (IPV6_ICMP_ENABLE_NDP == STD_ON) */

#if (IPV6_ENABLE_MLD == STD_ON)

  case IPV6_ICMP_MSG_TYPE_MLD_QUERY:        /* Type 130 */
    if (IpV6_VCfgHasMldConfig())
    {
      /* perform basic validation of MLDv2 Query [RFC3810 6.2. Action on Reception of a Query]
       * "All MLDv2 Queries MUST be sent with a valid IPv6 link-local source address."
       * [RFC3810 5.1.14. Source Addresses for Queries]
       */
      if (IPV6_ADDR_IS_LINK_LOCAL(IpV6HdrPtr->SrcAddr) && (IPV6_MLD_MSG_HOP_LIMIT == IpV6HdrPtr->HopLimit))
      {
        IpV6_Mld_VRxQuery(IpCtrlIdx, IpV6HdrPtr, &DataPtr[sizeof(IpV6_HdrType)], (IcmpHdrPos + sizeof(IpV6_IcmpHeaderType)) - sizeof(IpV6_HdrType), LenByte - sizeof(IpV6_HdrType));
      }
    }
    break;

#endif

#if (IPV6_ENABLE_NDP_INV_NA == STD_ON)

  case IPV6_ICMP_MSG_TYPE_NDP_INV_NS:          /* Type 141 */

    /* perform basic validation of IND Solicitation [RFC3122 4.3.1 Validation of Inverse Neighbor Discovery Solicitations] */
    if (IpV6_VCfgIsNdpInvNaEnabled() && (IPV6_NDP_IS_MIN_PAYLOAD_LEN <= IcmpPayloadLen) && (0 == IcmpHdrPtr->Code) && (IPV6_NDP_MSG_HOP_LIMIT == IpV6HdrPtr->HopLimit)) /*lint !e506 */ /* "Constant value Boolean" (only in some configuration variants) */
    {
      IpV6_Ndp_VRxInverseSolicitation(AddrId, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    }
    break;

#endif

#if (IPV6_ENABLE_NDP_INV_NS == STD_ON)

  case IPV6_ICMP_MSG_TYPE_NDP_INV_NA:          /* Type 141 */

    /* perform basic validation of IND Advertisement [RFC3122 4.3.2 Validation of Inverse Neighbor Discovery Advertisements] */
    if (IpV6_VCfgIsNdpInvNsEnabled() && (IPV6_NDP_IA_MIN_PAYLOAD_LEN <= IcmpPayloadLen) && (0 == IcmpHdrPtr->Code) && (IPV6_NDP_MSG_HOP_LIMIT == IpV6HdrPtr->HopLimit)) /*lint !e506 */ /* "Constant value Boolean" (only in some configuration variants) */
    {
      IpV6_Ndp_VRxInverseAdvertisement(AddrId, &IpV6HdrPtr->SrcAddr, IcmpPayloadPtr, IcmpPayloadLen);
    }
    break;

#endif

  default:
    break;
  }

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_VPacketReceived() */ /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  IpV6_Icmp_Init()
 **********************************************************************************************************************/
FUNC(void, IPV6_CODE) IpV6_Icmp_Init(uint8 IpCtrlIdx)
{
  IPV6_UNUSED_PARAMETER(IpCtrlIdx);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

#if (IPV6_ENABLE_ICMP_ERR_MSGS == STD_ON)
  IpV6_Icmp_PendingMsg.Pending = FALSE;
#endif

#if (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON)
  IpV6_Icmp_PendingEchoReply.Pending = FALSE;
#endif

} /* End of IpV6_Icmp_Init() */

#if (IPV6_ENABLE_ICMP_ECHO_REQUEST_API == STD_ON)
/**********************************************************************************************************************
 *  IpV6_Icmp_TxEchoRequest()
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV6_CODE) IpV6_Icmp_TxEchoRequest(
  IPV6_P2V(IpV6_AddrIdType) AddrIdPtr,
  IPV6_P2C(IpV6_AddrType)   DstAddrPtr,
  uint16                    Identifier,
  uint16                    SequenceNumber,
  IPV6_P2C(uint8)           DataPtr,
  uint16                    DataLen)
{
  TcpIp_IpTxRequestDescriptorType                            IpTxReqDesc;
  P2VAR(uint8, AUTOMATIC, IPV6_APPL_VAR)                     IcmpBufPtr;
  uint16                                                     IcmpBufLen;
  uint16                                                     IcmpPayloadLen;
  P2VAR(IpV6_IcmpEchoRequestType, AUTOMATIC, IPV6_APPL_DATA) IcmpEchoReqPtr;

  /* Det checks */
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnValue((NULL_PTR != AddrIdPtr),           IPV6_API_ID_ICMP_TX_ECHO_REQUEST, IPV6_E_INV_POINTER, E_NOT_OK);
  IpV6_CheckDetErrorReturnValue(IPV6_IS_VALID_ADDR_ID(*AddrIdPtr), IPV6_API_ID_ICMP_TX_ECHO_REQUEST, IPV6_E_INV_ADDR_ID, E_NOT_OK);
  IpV6_CheckDetErrorReturnValue((NULL_PTR != DstAddrPtr),          IPV6_API_ID_ICMP_TX_ECHO_REQUEST, IPV6_E_INV_POINTER, E_NOT_OK);
  /**/

  IcmpBufLen = sizeof(IpV6_IcmpEchoRequestType) + DataLen;

  if (BUFREQ_OK != IpV6_Icmp_ProvideTxBuffer(AddrIdPtr, IPV6_SOCK_IDX_ICMP, &IpTxReqDesc, DstAddrPtr, &IcmpBufPtr, &IcmpBufLen))
  {
    return E_NOT_OK;
  }

  IcmpEchoReqPtr = (P2VAR(IpV6_IcmpEchoRequestType, AUTOMATIC, IPV6_APPL_VAR))&IcmpBufPtr[0]; /* PRQA S 0310 */ /* MD_IpV6_0310 */
  IcmpEchoReqPtr->IdentifierNbo     = IPV6_HTONS(Identifier);
  IcmpEchoReqPtr->SequenceNumberNbo = IPV6_HTONS(SequenceNumber);

  IcmpPayloadLen = sizeof(IpV6_IcmpEchoRequestType);

  IpV6_MemCpy(&IcmpBufPtr[IcmpPayloadLen], DataPtr, DataLen); /* PRQA S 0310 */ /* MD_IpV6_0310 */

  IcmpPayloadLen += DataLen;

  return IpV6_Icmp_Transmit(IPV6_SOCK_IDX_ICMP, &IpTxReqDesc, IPV6_ICMP_MSG_TYPE_ECHO_REQ, 0, IcmpPayloadLen);

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_TxEchoRequest() */ /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif

/**********************************************************************************************************************
 *  IpV6_Icmp_Transmit()
 **********************************************************************************************************************/
/*! \brief      transmits an ICMPv6 packet
 *  \param[in]  IpTxReqDescPtr pointer to IP tx request descriptor (initialized by IpV6_Icmp_ProvideTxBuffer())
 *  \param[in]  Type           icmp message type
 *  \param[in]  Code           icmp message code
 *  \param[in]  PayloadLen     length of the ICMPv6 payload
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV6_CODE) IpV6_Icmp_Transmit(
  TcpIp_SockIdxType                         SockIdx,
  IPV6_P2V(TcpIp_IpTxRequestDescriptorType) IpTxReqDescPtr,
  uint8                                     Type,
  uint8                                     Code,
  uint16                                    PayloadLen)
{
  P2VAR(IpV6_IcmpHeaderType, AUTOMATIC, IPV6_APPL_VAR) IcmpV6HdrPtr;

  /* Det checks */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnValue(IPV6_IS_INITIALIZED,        IPV6_API_ID_ICMP_TRANSMIT, IPV6_E_NOT_INITIALIZED, E_NOT_OK);
  IpV6_CheckDetErrorReturnValue(NULL_PTR != IpTxReqDescPtr, IPV6_API_ID_ICMP_TRANSMIT, IPV6_E_INV_SOCK_IDX,    E_NOT_OK);
  /**/

  IcmpV6HdrPtr = (P2VAR(IpV6_IcmpHeaderType, AUTOMATIC, IPV6_APPL_VAR))IpV6_Icmp_EthBufPtr; /* PRQA S 0310 */ /* MD_IpV6_0310 */

  IcmpV6HdrPtr->Type = Type;
  IcmpV6HdrPtr->Code = Code;
  IcmpV6HdrPtr->ChecksumNbo = 0;

  PayloadLen += sizeof(IpV6_IcmpHeaderType);

  /* Checksum is calculated by lower layer or in hardware */

  return IpV6_Transmit(SockIdx, IpTxReqDescPtr, IPV6_HDR_ID_ICMP, PayloadLen, FALSE, 0, FALSE);

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_Transmit() */

/**********************************************************************************************************************
 *  IpV6_Icmp_ProvideTxBuffer()
 **********************************************************************************************************************/
/*! \brief      This function is called by upper layer to get a transmit buffer.
 *              the function only succeeds if the destination specified via DstAddrPtr is reachable
 *  \param[in,out] AddrIdPtr          ip address identifier
 *                                    if the identifier is an AutoSelect id, the selected source address id will be returend
 *  \param[in]     SockIdx            socket index
 *  \param[out]    TxReqDescPtr       pointer to IP tx request descriptor (initialized by this function)
 *  \param[in]     DstAddrPtr         pointer to the address of the desired destination
 *  \param[out]    BufPtr             pointer to a variable which recieves the pointer to the provided buffer
 *  \param[in,out] BufLenPtr          pointer to a variable which holds the minimum desired buffer size
 *                                    if the the function succeeds the available buffer size is stored here
 *  \return     BUFREQ_OK             buffer provided
 *  \return     BUFREQ_E_BUSY         currently no free buffer availabe, call again later
 *  \return     BUFREQ_E_NOT_OK       unknown error
 *  \context    task level
 **********************************************************************************************************************/
FUNC(BufReq_ReturnType, TCPIP_CODE) IpV6_Icmp_ProvideTxBuffer(
    IPV6_P2V(IpV6_AddrIdType)                 AddrIdPtr,
    TcpIp_SockIdxType                         SockIdx,
    IPV6_P2V(TcpIp_IpTxRequestDescriptorType) TxReqDescPtr,
    IPV6_P2C(IpV6_AddrType)                   DstAddrPtr,
    IPV6_P2V(uint8*)                          BufPtr,
    IPV6_P2V(uint16)                          BufLenPtr)
{
  BufReq_ReturnType BufReqRes;

  /* Det checks */
  /* PRQA S 3109 8 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnValue(IPV6_IS_INITIALIZED,               IPV6_API_ID_ICMP_PROVIDE_TX_BUFFER, IPV6_E_NOT_INITIALIZED, BUFREQ_E_NOT_OK);
  IpV6_CheckDetErrorReturnValue(NULL_PTR != AddrIdPtr,             IPV6_API_ID_ICMP_PROVIDE_TX_BUFFER, IPV6_E_INV_POINTER,     BUFREQ_E_NOT_OK);
  IpV6_CheckDetErrorReturnValue(IPV6_IS_VALID_ADDR_ID(*AddrIdPtr), IPV6_API_ID_ICMP_PROVIDE_TX_BUFFER, IPV6_E_INV_ADDR_ID,     BUFREQ_E_NOT_OK);
  IpV6_CheckDetErrorReturnValue(IPV6_IS_VALID_SOCK_IDX(SockIdx),   IPV6_API_ID_ICMP_PROVIDE_TX_BUFFER, IPV6_E_INV_SOCK_IDX,    BUFREQ_E_NOT_OK);
  IpV6_CheckDetErrorReturnValue(NULL_PTR != TxReqDescPtr,          IPV6_API_ID_ICMP_PROVIDE_TX_BUFFER, IPV6_E_INV_POINTER,     BUFREQ_E_NOT_OK);
  IpV6_CheckDetErrorReturnValue(NULL_PTR != DstAddrPtr,            IPV6_API_ID_ICMP_PROVIDE_TX_BUFFER, IPV6_E_INV_POINTER,     BUFREQ_E_NOT_OK);
  IpV6_CheckDetErrorReturnValue(NULL_PTR != BufPtr,                IPV6_API_ID_ICMP_PROVIDE_TX_BUFFER, IPV6_E_INV_POINTER,     BUFREQ_E_NOT_OK);
  IpV6_CheckDetErrorReturnValue(NULL_PTR != BufLenPtr,             IPV6_API_ID_ICMP_PROVIDE_TX_BUFFER, IPV6_E_INV_POINTER,     BUFREQ_E_NOT_OK);
  /**/

  *BufLenPtr += sizeof(IpV6_IcmpHeaderType);

  BufReqRes = IpV6_ProvideTxBuffer(AddrIdPtr, SockIdx, DstAddrPtr, BufPtr, BufLenPtr, TxReqDescPtr, FALSE);

  if (BUFREQ_OK != BufReqRes)
  {
    return BufReqRes;
  }

  IpV6_Icmp_EthBufPtr = *BufPtr;

  *BufPtr = &(*BufPtr)[sizeof(IpV6_IcmpHeaderType)];
  *BufLenPtr -= sizeof(IpV6_IcmpHeaderType);

  return BUFREQ_OK;
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_ProvideTxBuffer() */ /* PRQA S 6060, 6010 */ /* MD_MSR_STPAR, MD_MSR_STPTH */

/**********************************************************************************************************************
 *  IpV6_Icmp_MainFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, IPV6_CODE) IpV6_Icmp_MainFunction(uint8 IpCtrlIdx)
{
  IPV6_UNUSED_PARAMETER(IpCtrlIdx);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  /* Det checks */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  IpV6_CheckDetErrorReturnVoid(IPV6_IS_VALID_CTRL_IDX(IpCtrlIdx), IPV6_API_ID_ICMP_MAIN_FUNCTION, IPV6_E_INV_CTRL_IDX);
  /**/

  IPV6_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

#if (IPV6_ENABLE_ICMP_ECHO_REPLY == STD_ON)
  /* #10 Send pending ICMPv6 Echo response. */
  if (TRUE == IpV6_Icmp_PendingEchoReply.Pending)
  {
    if (E_OK == IpV6_Icmp_VTxPendingMessage(&IpV6_Icmp_PendingEchoReply))
    {
      /* pending echo successfully transmitted */
      IpV6_Icmp_PendingEchoReply.Pending = FALSE;
    }
  }
#endif

  /* #20 Send pending ICMPv6 Error message. */
#if (IPV6_ENABLE_ICMP_ERR_MSGS == STD_ON)
  /* send pending icmp error message if one has been scheduled */
  if (TRUE == IpV6_Icmp_PendingMsg.Pending)
  {
    if (E_OK == IpV6_Icmp_VTxPendingMessage(&IpV6_Icmp_PendingMsg))
    {
      /* pending icmp successfully transmitted */
      IpV6_Icmp_PendingMsg.Pending = FALSE;
    }
  }
#endif

  IPV6_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV6_Icmp_MainFunction() */

/***********************************************************************************************************************
 *  IpV6_Icmp_StoreChecksumInHeader
 **********************************************************************************************************************/
FUNC(void, IPV6_CODE) IpV6_Icmp_StoreChecksumInHeader(
    uint16          Checksum,
    IPV6_P2V(uint8) IcmpHdrPtr)
{
  IpV6_IcmpHeaderType *MsgPtr = (IpV6_IcmpHeaderType*)IcmpHdrPtr; /* PRQA S 0310 */ /* MD_IpV6_0310 */

  /* calculate checksum */
  MsgPtr->ChecksumNbo = Checksum;

} /* IpV6_Icmp_StoreChecksumInHeader() */

#define IPV6_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif  /* (TCPIP_SUPPORT_IPV6 == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: IpV6_Icmp.c
 *********************************************************************************************************************/
