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
/**        \file  Etm_Types_Priv.h
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

#if !defined (ETM_TYPES_PRIV_H)
#define ETM_TYPES_PRIV_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Etm_Cfg.h"

#if (ETM_ETHIF_ENABLED == STD_ON)
# include "Eth_Types.h"
#endif /* (ETM_ETHIF_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ETM Header Format */
/* \trace SPEC-2171512 */
/* 

    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                               |E|             |    Service    |
   |           Service ID          |V|   Group ID  |  Primitive ID | --> SOME/IP: this field represent the MessageID (uint32) containing
   |             (SID)             |B|    (GID)    |     (PID)     |              the ServiceID (uint16) and the MethodID (uint16)
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                                                               |
   |                          Length (LEN)                         |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                                                               | --> SOME/IP: this field represent the RequestID (uint32) containing
   |                           DON'T CARE                          |              the ClientID (uint16) and the SessionID (uint16)
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |    Protocol   |   Interface   |               |               |
   |    Version    |    Version    |    Type ID    |   Result ID   |
   |     (0x01)    |     (0x01)    |     (TID)     |     (RID)     |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                                                               |
   |                         Payload (DAT)                         |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

 */

/* Data length */
#define ETM_DATA_LEN_ADDRESS_IPV4       4U  /*  4 bytes --  32 bit */
#define ETM_DATA_LEN_ADDRESS_IPV6       16U /* 16 bytes -- 128 bit */

#define ETM_EVENT_LENGTH_ACCEPT         24U
#define ETM_EVENT_LENGTH_FORWARD_HEADER 16U /* Etm Header Length */
#define ETM_EVENT_LENGTH_FORWARD_DATA   22U /* Etm Fix Event Data Length */
#define ETM_EVENT_LENGTH_FORWARD_FIX    (ETM_EVENT_LENGTH_FORWARD_HEADER + ETM_EVENT_LENGTH_FORWARD_DATA)
#define ETM_EVENT_LENGTH_FORWARD        (ETM_STUB_MAX_FORWARD_LENGTH + ETM_EVENT_LENGTH_FORWARD_DATA )
#define ETM_EVENT_LENGTH_MAX            ((ETM_EVENT_LENGTH_FORWARD > ETM_EVENT_LENGTH_ACCEPT) ? ETM_EVENT_LENGTH_FORWARD : ETM_EVENT_LENGTH_ACCEPT)
#define ETM_MESSAGE_LENGTH_HEADER       16U /* Etm Header Length */
#define ETM_MESSAGE_LENGTH_MAX          (ETM_MESSAGE_LENGTH_HEADER + ETM_EVENT_LENGTH_MAX) /* the maximum message length is derived from the event 'Receive And Forward' and 'Listen And Accept' */
#define ETM_MESSAGE_OFFSET_SID          0U       /* \trace SPEC-2171512 */
#define ETM_MESSAGE_OFFSET_EVB_GID      2U       /* \trace SPEC-2171512 */
#define ETM_MESSAGE_OFFSET_PID          3U       /* \trace SPEC-2171512 */
#define ETM_MESSAGE_OFFSET_LEN          4U       /* \trace SPEC-2171512 */
#define ETM_MESSAGE_OFFSET_PROTO_VER    12U      /* \trace SPEC-2171512 */
#define ETM_MESSAGE_OFFSET_IFACE_VER    13U      /* \trace SPEC-2171512 */
#define ETM_MESSAGE_OFFSET_TID          14U      /* \trace SPEC-2171512 */
#define ETM_MESSAGE_OFFSET_RID          15U      /* \trace SPEC-2171512 */
#define ETM_MESSAGE_OFFSET_DAT          16U      /* \trace SPEC-2171512 */

#define ETM_CONFIGURE_SOCKET_TTL        0x0000   /* \trace SPEC-2171534 */
#define ETM_CONFIGURE_SOCKET_PRIORITY   0x0001   /* \trace SPEC-2171534 */

#define ETM_UINT8_MASK_EVB_BIT          0x80U    /* 1-Bit-Mask 1000.0000 */
#define ETM_UINT8_MASK_GID              0x7FU    /* 7-Bit-Mask 0111.1111 */
#define ETM_FORWARD_FOREVER             0xFFFFU  /* \trace SPEC-2171531 */
#define ETM_PORT_ANY                    0xFFFFU  /* \trace SPEC-2171529 */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/****************************************************************************************************
 *  ENUMS
 ****************************************************************************************************/

/* TID */
/* \trace SPEC-2171514 */
typedef enum
{
#if (ETM_STUB_PROTOCOL_VERSION <= 0x0004U)
  ETM_TID_REQUEST   = 0x00U,
  ETM_TID_RESPONSE  = 0x08U,
  ETM_TID_EVENT     = 0x02U
#else
  ETM_TID_REQUEST   = 0x00U,
  ETM_TID_RESPONSE  = 0x80U,
  ETM_TID_EVENT     = 0x02U /* EVB set to 1 */
#endif
} Etm_TypeIdType;

/* RID */
/* \trace SPEC-2171520 */
typedef enum
{
  /* Standard Results */
  ETM_RID_E_OK   = 0x00U,  /* E_OK */
  ETM_RID_E_NOK  = 0x01U,  /* E_NOT_OK */
  /* Testability Specific Results */
  ETM_RID_E_NTF  = 0xFFU,  /* Service Primitive not found */
  ETM_RID_E_PEN  = 0xFEU,  /* Service Primitive pending */
  ETM_RID_E_ISB  = 0xFDU,  /* Insuffizient buffer size */
  /* Service Primitive Specific Results */
  ETM_RID_E_ISD  = 0xEFU,  /* Invalid SocketId */
  ETM_RID_E_UCS  = 0xEEU,  /* Unable to create socket or no free socket */
  ETM_RID_E_UBS  = 0xEDU,  /* Unable to bind socket */
  ETM_RID_E_INV  = 0xECU   /* Invalid input or parameter */
} Etm_ResultIdType;

/* GID */ /* 7 Bit */
/* User-GIDs counted backwards starting 0x7F, 0x7E, ... */
/* \trace SPEC-2171521 */
typedef enum
{
  ETM_GID_GENERAL     = 0x00U,
  ETM_GID_UDP         = 0x01U,
  ETM_GID_TCP         = 0x02U,
  ETM_GID_ICMP        = 0x03U,
  ETM_GID_ICMPv6      = 0x04U,
  ETM_GID_IP          = 0x05U,
  ETM_GID_IPv6        = 0x06U,
  ETM_GID_DHCP        = 0x07U,
  ETM_GID_DHCPv6      = 0x08U,
  ETM_GID_ARP         = 0x09U,
  ETM_GID_NDP         = 0x0AU,
  ETM_GID_USERSCRIPT  = 0x7FU   /* \trace SPEC-2171517 */
} Etm_GroupIdType;

/* PIDs with (GID == 0x00U) */
/* User-PIDs counted backwards starting 0xFF, 0xFE, ... */
/* \trace SPEC-2171522 */
typedef enum
{
#if (ETM_STUB_PROTOCOL_VERSION <= 0x0005U)
  ETM_PID_GET_VERSION = 0x00U,
  ETM_PID_START_TEST  = 0x01U,
  ETM_PID_END_TEST    = 0x02U
#else
  ETM_PID_GET_VERSION = 0x01U,
  ETM_PID_START_TEST  = 0x02U,
  ETM_PID_END_TEST    = 0x03U
#endif
} Etm_GeneralPrimitiveType;

/* PIDs with (GID == 0x01U) */
/* User-PIDs counted backwards starting 0xFF, 0xFE, ... */
/* \trace SPEC-2171523 */
typedef enum
{
#if (ETM_STUB_PROTOCOL_VERSION <= 0x0005U)
  ETM_PID_UDP_CLOSE_SOCKET        = 0x03U,  /* mandatory */
  ETM_PID_UDP_CREATE_AND_BIND     = 0x04U,  /* mandatory */
  ETM_PID_UDP_SEND_DATA           = 0x05U,  /* mandatory */
  ETM_PID_UDP_RECEIVE_AND_FORWARD = 0x06U,  /* mandatory */
  ETM_PID_UDP_CONFIGURE_SOCKET    = 0x09U,  /* mandatory */
  ETM_PID_UDP_SHUTDOWN            = 0x0AU   /* extension */
#else
  ETM_PID_UDP_CLOSE_SOCKET        = 0x00U,  /* mandatory */
  ETM_PID_UDP_CREATE_AND_BIND     = 0x01U,  /* mandatory */
  ETM_PID_UDP_SEND_DATA           = 0x02U,  /* mandatory */
  ETM_PID_UDP_RECEIVE_AND_FORWARD = 0x03U,  /* mandatory */
  ETM_PID_UDP_CONFIGURE_SOCKET    = 0x06U,  /* mandatory */
  ETM_PID_UDP_SHUTDOWN            = 0x07U   /* extension */
#endif
} Etm_UdpPrimitiveType;

/* PIDs with (GID == 0x02U) */
/* User-PIDs counted backwards starting 0xFF, 0xFE, ... */
/* \trace SPEC-2171524 */
typedef enum
{
#if (ETM_STUB_PROTOCOL_VERSION <= 0x0005U)
  ETM_PID_TCP_CLOSE_SOCKET        = 0x03U,  /* mandatory */
  ETM_PID_TCP_CREATE_AND_BIND     = 0x04U,  /* mandatory */
  ETM_PID_TCP_SEND_DATA           = 0x05U,  /* mandatory */
  ETM_PID_TCP_RECEIVE_AND_FORWARD = 0x06U,  /* mandatory */
  ETM_PID_TCP_LISTEN_AND_ACCEPT   = 0x07U,  /* mandatory */
  ETM_PID_TCP_CONNECT             = 0x08U,  /* mandatory */
  ETM_PID_TCP_CONFIGURE_SOCKET    = 0x09U,  /* mandatory */
  ETM_PID_TCP_SHUTDOWN            = 0x0AU   /* extension */
#else
  ETM_PID_TCP_CLOSE_SOCKET        = 0x00U,  /* mandatory */
  ETM_PID_TCP_CREATE_AND_BIND     = 0x01U,  /* mandatory */
  ETM_PID_TCP_SEND_DATA           = 0x02U,  /* mandatory */
  ETM_PID_TCP_RECEIVE_AND_FORWARD = 0x03U,  /* mandatory */
  ETM_PID_TCP_LISTEN_AND_ACCEPT   = 0x04U,  /* mandatory */
  ETM_PID_TCP_CONNECT             = 0x05U,  /* mandatory */
  ETM_PID_TCP_CONFIGURE_SOCKET    = 0x06U,  /* mandatory */
  ETM_PID_TCP_SHUTDOWN            = 0x07U   /* extension */
#endif
} Etm_TcpPrimitiveType;

# define ETM_PID_USERSCRIPT__UNDEFINED     0x00

/****************************************************************************************************
 *  TYPES
 ****************************************************************************************************/

/* \trace SPEC-2171512 */
typedef struct
{
  uint16 Sid;               /* SID - ServiceId */
  boolean Evb;  /* 1 Bit */ /* EVB - EventBit */
  uint8 Gid;    /* 7 Bit */ /* GID - GroupId */
  uint8 Pid;                /* PID - SerivePrimitiveId */
  uint32 Len;               /* LEN - Length */
  uint8 ProtocolVersion;
  uint8 InterfaceVersion;
  uint8 Tid;                /* TID - TypeId */
  uint8 Rid;                /* RID - ResultId */
  uint16 PayloadLength;
  uint8 *Payload;           /* DAT */
  TcpIp_SocketIdType ReceivedSocketId;
  TcpIp_SockAddrInXType ReceivedRemoteAddress;
  boolean UsePhysAddr;      /* Answer UserScripts via Ethernet Frames */
#if (ETM_ETHIF_ENABLED == STD_ON)
  uint8 ReceivedCtrlIdx;
  Eth_PhysAddrType ReceivedRemotePhysAddr;
#endif /* (ETM_ETHIF_ENABLED == STD_ON) */
} Etm_HeaderType;

#endif  /* ETM_TYPES_PRIV_H */

/**********************************************************************************************************************
 *  END OF FILE: Etm_Types_Priv.h
 *********************************************************************************************************************/
