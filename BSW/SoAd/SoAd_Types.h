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
 *         File:  SoAd_Types.h
 *      Project:  TcpIp-Stack
 *       Module:  Socket Adapter
 *    Generator:  If_AsrIfSoAd.dll
 *
 *  Description:  types header
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/


#if !defined(SOAD_TYPES_H)
#define SOAD_TYPES_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SoAd_Cfg.h"
#include "ComStack_Types.h"
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
#else
#include "TcpIp_Types.h"
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES DEFINES
 *********************************************************************************************************************/
#define SOAD_UHWID_LEN_BYTE             TCPIP_PHYS_ADDR_LEN_BYTE

#define SOAD_IPV4_ADDR_LEN_BYTE         4u
#define SOAD_IPV6_ADDR_LEN_BYTE         16u

#define SOAD_INV_BUF_IDX_8              0xFFu
#define SOAD_INV_BUF_IDX_16             0xFFFFu

#define SOAD_INV_HND_8                  0xFFu
#define SOAD_INV_HND_16                 0xFFFFu

#define SOAD_INV_FRAME_PRIORITY         0xFFu
#define SOAD_INV_KEEP_ALIVE_VALUE       0xFFFFFFFFu

#define SOAD_MAX_TIMEOUT_32             0xFFFFFFFFu

#define SOAD_CLOSE_NONE                 0x00u
#define SOAD_CLOSE_RECONNECT            0x01u
#define SOAD_CLOSE_OFFLINE              0x02u
#define SOAD_CLOSE_OFFLINE_RESET        0x03u
#define SOAD_CLOSE_REMOTE               0x04u

#define SOAD_CHG_FUNC_TYPE_IPASSIGN     0x00u
#define SOAD_CHG_FUNC_TYPE_SOCONMODE    0x01u

#define SOAD_TX_CONF_STRAT_BIT_PAT_CONF 0x7FFFu /* b 0111 1111 1111 1111 */
#define SOAD_TX_CONF_STRAT_BIT_PAT_MAIN 0x8000u /* b 1000 0000 0000 0000 */

/* PRQA S 3453 4 */ /* MD_MSR_19.7 */  /* PRQA S 0850 4 */ /* MD_MSR_19.8 */
#define SOAD_P2CONST(Type)              P2CONST     (Type, AUTOMATIC, SOAD_APPL_DATA)
#define SOAD_P2VAR(Type)                P2VAR       (Type, AUTOMATIC, SOAD_APPL_VAR)
#define SOAD_CONSTP2VAR(Type)           CONSTP2VAR  (Type, AUTOMATIC, SOAD_APPL_VAR)
#define SOAD_CONSTP2CONST(Type)         CONSTP2CONST(Type, AUTOMATIC, SOAD_CONST)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* segmented buffer */
typedef struct
{
  uint8* DataPtr;
  uint16 Len;
} SoAd_BufSegType;

typedef struct
{
  SoAd_BufSegType BufSegs[SOAD_VBUF_SEG_SIZE_TOTAL];
  uint16          Idx;
  uint16          Lvl;
} SoAd_BufSegMgtType;

/* socket address */
#define SOAD_AF_UNSPEC              0x0000u
#define SOAD_AF_INVALID             0xFFFFu
#define SOAD_IPADDR_ANY             0x00000000u
#define SOAD_IP6ADDR_ANY            0x00000000u
/* ----------------- */

/* port */
typedef uint16                      SoAd_PortType;
#define SOAD_PORT_ANY               0x0000u
#define SOAD_INV_PORT               0xFFFFu
/* ---- */

/* TcpIp socket ID */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef sint32                       SoAd_SocketIdType;
#define SOAD_INV_SOCKET_ID          -1
#else
typedef TcpIp_SocketIdType          SoAd_SocketIdType;
#define SOAD_INV_SOCKET_ID          ((TcpIp_SocketIdType)(-1))
#endif /* defined(SOAD_VSOCKET_API) && (STD_ON == SOAD_VSOCKET_API) */
/* ------------------- */

/* BSD socket Flags */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
#define SOAD_ZERO_FLAGS             0x00
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
/* -------------- - */

/* TcpIp event */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef uint8                       SoAd_EventType;
#define SOAD_TCP_RESET              0x01u
#define SOAD_TCP_CLOSED             0x02u
#define SOAD_TCP_FIN_RECEIVED       0x03u
#define SOAD_UDP_CLOSED             0x04u
#else
typedef TcpIp_EventType             SoAd_EventType;
#define SOAD_TCP_RESET              TCPIP_TCP_RESET
#define SOAD_TCP_CLOSED             TCPIP_TCP_CLOSED
#define SOAD_TCP_FIN_RECEIVED       TCPIP_TCP_FIN_RECEIVED
#define SOAD_UDP_CLOSED             TCPIP_UDP_CLOSED
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
/* ----------- */

/* TcpIp domain */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef uint16                      SoAd_DomainType;
#define SOAD_AF_INET                0x02u
#define SOAD_AF_INET6               0x1Cu
#else
typedef TcpIp_DomainType            SoAd_DomainType;
#define SOAD_AF_INET                TCPIP_AF_INET
#define SOAD_AF_INET6               TCPIP_AF_INET6
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
/* ------------ */

/* TcpIp protocol */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef uint8                       SoAd_ProtocolType;
#define SOAD_IPPROTO_TCP            0x06u
#define SOAD_IPPROTO_UDP            0x11u
#else
typedef TcpIp_ProtocolType          SoAd_ProtocolType;
#define SOAD_IPPROTO_TCP            TCPIP_IPPROTO_TCP
#define SOAD_IPPROTO_UDP            TCPIP_IPPROTO_UDP
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
/* -------------- */

/* TcpIp port wildcard */
typedef uint16                        SoAd_PortWildcardType; /* TcpIpPortWildcardType */

/* TcpIp IP address state */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef uint8                         SoAd_IpAddrStateType;
#define SOAD_IPADDR_STATE_ASSIGNED    0x00u
#define SOAD_IPADDR_STATE_ONHOLD      0x01u
#define SOAD_IPADDR_STATE_UNASSIGNED  0x02u
#else
typedef TcpIp_IpAddrStateType         SoAd_IpAddrStateType;
#define SOAD_IPADDR_STATE_ASSIGNED    TCPIP_IPADDR_STATE_ASSIGNED
#define SOAD_IPADDR_STATE_ONHOLD      TCPIP_IPADDR_STATE_ONHOLD
#define SOAD_IPADDR_STATE_UNASSIGNED  TCPIP_IPADDR_STATE_UNASSIGNED
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
/* ---------------------- */

/* TcpIp local address ID */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef uint8                         SoAd_LocalAddrIdType;
typedef uint8_least                   SoAd_LocalAddrIdType_least;
#define SOAD_IPADDRID_ANY             0xFEU
#else
typedef TcpIp_LocalAddrIdType         SoAd_LocalAddrIdType;
#define SOAD_IPADDRID_ANY             TCPIP_LOCALADDRID_ANY
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
/* ---------------------- */

/* TcpIp parameter ID */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
#define SOAD_PARAMID_TCP_RXWND_MAX              SO_RCVBUF
#define SOAD_PARAMID_TCP_TXWND_MAX              SO_SNDBUF
#define SOAD_PARAMID_TCP_KEEPALIVE              SO_KEEPALIVE
#define SOAD_PARAMID_TCP_KEEPALIVE_TIME         TCP_KEEPIDLE
#define SOAD_PARAMID_TCP_KEEPALIVE_PROBES_MAX   TCP_KEEPCNT
#define SOAD_PARAMID_TCP_KEEPALIVE_INTERVAL     TCP_KEEPINTVL
#define SOAD_PARAMID_TCP_NAGLE                  TCP_NODELAY
#else
#define SOAD_PARAMID_TCP_RXWND_MAX              TCPIP_PARAMID_TCP_RXWND_MAX
#define SOAD_PARAMID_FRAMEPRIO                  TCPIP_PARAMID_FRAMEPRIO
#define SOAD_PARAMID_TCP_NAGLE                  TCPIP_PARAMID_TCP_NAGLE
#define SOAD_PARAMID_TCP_KEEPALIVE              TCPIP_PARAMID_TCP_KEEPALIVE
#define SOAD_PARAMID_TTL                        TCPIP_PARAMID_TTL
#define SOAD_PARAMID_TCP_KEEPALIVE_TIME         TCPIP_PARAMID_TCP_KEEPALIVE_TIME
#define SOAD_PARAMID_TCP_KEEPALIVE_PROBES_MAX   TCPIP_PARAMID_TCP_KEEPALIVE_PROBES_MAX
#define SOAD_PARAMID_TCP_KEEPALIVE_INTERVAL     TCPIP_PARAMID_TCP_KEEPALIVE_INTERVAL
#if ( defined(SOAD_VTCP_TX_BUF_MIN_ENABLED) && (STD_ON == SOAD_VTCP_TX_BUF_MIN_ENABLED) )
# define SOAD_PARAMID_TCP_TXWND_MAX             TCPIP_PARAMID_V_TCP_TXBUFSIZE
#endif /* defined(SOAD_VTCP_TX_BUF_MIN_ENABLED) && (STD_ON == SOAD_VTCP_TX_BUF_MIN_ENABLED) */
#if ( defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) )
# define SOAD_PARAMID_UDP_TXREQLISTSIZE         TCPIP_PARAMID_V_UDP_TXREQLISTSIZE
#endif /* defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) */
#if ( defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED) )
# define SOAD_PARAMID_UDP_TXRETRYLISTSIZE       TCPIP_PARAMID_V_UDP_TXRETRYLISTSIZE
#endif /* defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED) */
#define SOAD_PARAMID_USE_TLS                    TCPIP_PARAMID_V_USE_TLS
#define SOAD_PARAMID_TLS_TXBUFSIZE              TCPIP_PARAMID_V_TLS_TXBUFSIZE
#define SOAD_PARAMID_TLS_RXBUFSIZE              TCPIP_PARAMID_V_TLS_RXBUFSIZE
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

/* TcpIp IP address assignment */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef uint8                                   SoAd_IpAddrAssignmentType;
#define SOAD_IPADDR_ASSIGNMENT_STATIC           0x01u
#define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP   0x02u
#define SOAD_IPADDR_ASSIGNMENT_DHCP             0x03u
#define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL        0x04u
#define SOAD_IPADDR_ASSIGNMENT_IPV6_ROUTER      0x05u
#else
typedef TcpIp_IpAddrAssignmentType              SoAd_IpAddrAssignmentType;
#define SOAD_IPADDR_ASSIGNMENT_STATIC           TCPIP_IPADDR_ASSIGNMENT_STATIC
#define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP   TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP
#define SOAD_IPADDR_ASSIGNMENT_DHCP             TCPIP_IPADDR_ASSIGNMENT_DHCP
#define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL        TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL
#define SOAD_IPADDR_ASSIGNMENT_IPV6_ROUTER      TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
/* --------------------------- */

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef struct
{
  SoAd_DomainType    domain;
} SoAd_SockAddrType;
typedef struct
{
  SoAd_DomainType    domain;
  uint16             port;
  uint32             addr[1];
} SoAd_SockAddrInetType;
typedef struct
{
  SoAd_DomainType    domain;
  uint16             port;
  uint32             addr[4];
} SoAd_SockAddrInet6Type;
typedef struct
{
  uint32             addr[1];
} SoAd_IpAddrInetType;
typedef struct
{
  uint32             addr[4];
} SoAd_IpAddrInet6Type;
typedef uint32 SoAd_IpAddrType;
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
#  define SoAd_IpAddrInetXType      SoAd_IpAddrInet6Type
#  define sockaddr_inX              sockaddr_in6
# else
#  define SoAd_IpAddrInetXType      SoAd_IpAddrInetType
#  define sockaddr_inX              sockaddr_in
# endif
#else
typedef TcpIp_SockAddrType          SoAd_SockAddrType;
typedef TcpIp_SockAddrInetType      SoAd_SockAddrInetType;
typedef TcpIp_SockAddrInet6Type     SoAd_SockAddrInet6Type;
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef struct
{
  P2CONST(SoAd_IpAddrType, AUTOMATIC, SOAD_CONST) addrPtr;
  SoAd_DomainType domain;
  uint8 netmask;
} SoAd_LocalIpAddrType;

typedef struct
{
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
  uint32 addr[4];
#else
  uint32 addr[1];
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
  uint8 netmask;
  uint8 ifcIdx;

} SoAd_LocalIpAddrDynType;

typedef uint8                                 SoAd_LocalIpAddrReqStateType;
#define SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE     0x00u
#define SOAD_LOCAL_IP_ADDR_REQ_STATE_REQUEST  0x01u
#define SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE  0x02u

typedef uint8                           SoAd_AddressTypeType;
#define SOAD_ADDRESS_TYPE_UNICAST       0x00u
#define SOAD_ADDRESS_TYPE_MULTICAST     0x01u

typedef uint8                           SoAd_AssignTriggerType;
#define SOAD_ASSIGN_TRIGGER_AUTOMATIC   0x00u
#define SOAD_ASSIGN_TRIGGER_MANUAL      0x01u

typedef struct
{
  SoAd_AddressTypeType AddressType;
  SoAd_IpAddrAssignmentType AssignType;
  SoAd_AssignTriggerType AssignTrigger;
  uint8 IfcIdx;
} SoAd_LocalAddressType;

typedef struct
{
  SoAd_SocketIdType LimNodeSocketId;
  SoAd_SocketIdType DirLinkSocketId;
} SoAd_MulticastAddrType;
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

typedef struct
{
  SoAd_DomainType domain;
  uint16          port;
} SoAd_SockAddrUnspecType;

#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
  typedef SoAd_SockAddrInet6Type       SoAd_SockAddrInetXType;
#else
  typedef SoAd_SockAddrInetType        SoAd_SockAddrInetXType;
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
/* ------------------ */

/* internal TcpIp socket index */
typedef uint16                      SoAd_SockIdxType;
typedef uint16_least                SoAd_SockIdxType_least;
#define SOAD_INV_SOCK_IDX           0xFFFFu
/* --------------------------- */

/* socket connection mode */
typedef uint8                       SoAd_SoConModeType;
#define SOAD_SOCON_ONLINE           0x00u
#define SOAD_SOCON_RECONNECT        0x01u
#define SOAD_SOCON_OFFLINE          0x02u
/* ---------------------- */

/* socket connection mode filter */
typedef uint8                       SoAd_SoConModeFilterType;
#define SOAD_SOCON_FILTER_DISABLED  0x00u
#define SOAD_SOCON_FILTER_ON_OFF    0x01u
/* ---------------------- */

/* socket connection ID */
#if ( defined(SOAD_CONFIGURED_MAX_SOCK_CON) && (SOAD_CONFIGURED_MAX_SOCK_CON <= 255u) )
  typedef uint8                     SoAd_SoConIdType;
  typedef uint8_least               SoAd_SoConIdType_least;
# define SOAD_INV_SO_CON_ID         0xFFu
#else
  typedef uint16                    SoAd_SoConIdType;
  typedef uint16_least              SoAd_SoConIdType_least;
# define SOAD_INV_SO_CON_ID         0xFFFFu
#endif /* defined(SOAD_CONFIGURED_MAX_SOCK_CON) && (SOAD_CONFIGURED_MAX_SOCK_CON <= 255u) */

typedef SoAd_SoConIdType            SoAd_SoConIdxType;
typedef SoAd_SoConIdType_least      SoAd_SoConIdxType_least;
#define SOAD_INV_SO_CON_IDX         SOAD_INV_SO_CON_ID
/* ------------------- */

/* remote address state */
typedef uint8                           SoAd_RemAddrStateType;
                                              /*     NOT ANY SET */
#define SOAD_SOCON_IP_SET_PORT_SET      0x03u /* 00  00  00  11  */
#define SOAD_SOCON_IP_SET_PORT_ANY      0x06u /* 00  00  01  10  */
#define SOAD_SOCON_IP_SET_PORT_NOT      0x12u /* 00  01  00  10  */
#define SOAD_SOCON_IP_ANY_PORT_SET      0x09u /* 00  00  10  01  */
#define SOAD_SOCON_IP_ANY_PORT_ANY      0x0Cu /* 00  00  11  00  */
#define SOAD_SOCON_IP_ANY_PORT_NOT      0x18u /* 00  01  10  00  */
#define SOAD_SOCON_IP_NOT_PORT_SET      0x21u /* 00  10  00  01  */
#define SOAD_SOCON_IP_NOT_PORT_ANY      0x24u /* 00  10  01  00  */
#define SOAD_SOCON_IP_NOT_PORT_NOT      0x30u /* 00  11  00  00  */
#define SOAD_SOCON_MASK_IPADDR          0x2Au /* 00  10  10  10  */
#define SOAD_SOCON_MASK_PORT            0x15u /* 00  01  01  01  */
#define SOAD_SOCON_MASK_SET             0x03u /* 00  00  00  11  */
#define SOAD_SOCON_MASK_ANY             0x0Cu /* 00  00  11  00  */
#define SOAD_SOCON_MASK_NOT             0x30u /* 00  11  00  00  */
/* ------------------- */

/* PDU IDx */
typedef PduIdType                   SoAd_PduIdxType;
#define SOAD_INV_PDU_IDX            SOAD_INV_PDU_ID
#define SOAD_INV_SOCKROUTE_IDX      SOAD_INV_PDU_ID
#define SOAD_INV_PDUROUTE_IDX       SOAD_INV_PDU_ID
/* ------------------- */

/* PDU header option */
#if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
typedef uint32                      SoAd_PduHdrIdType;
typedef uint32                      SoAd_PduHdrLenType;
#define SOAD_INV_PDU_HDR_ID         0xFFFFFFFFu
#endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
/* ----------------- */

/* module initialization state */
typedef uint8                       SoAd_StateType;        /* SoAd needs state also without DET */

/* upper layer */
typedef uint8                       SoAd_UpperLayerType;
#define SOAD_UL_TYPE_TP             0x01u
#define SOAD_UL_TYPE_IF             0x00u
/* ----------- */

/* trigger mode */
typedef uint8                           SoAd_TxUdpTriggerModeType;
#define SOAD_TX_UDP_TRIGGER_ALWAYS      0x00u
#define SOAD_TX_UDP_TRIGGER_NEVER       0x01u
#define SOAD_TX_UDP_TRIGGER_NONE        0x02u
/* ------------ */

/* routing group ID */
#if ( defined(SOAD_CONFIGURED_MAX_ROUT_GROUP) && (SOAD_CONFIGURED_MAX_ROUT_GROUP <= 255u) )
  typedef uint8                    SoAd_RoutingGroupIdType;
  typedef uint8_least              SoAd_RoutingGroupIdType_least;
# define  SOAD_INV_ROUT_GRP_ID     0xFF
#else
  typedef uint16                   SoAd_RoutingGroupIdType;
  typedef uint16_least             SoAd_RoutingGroupIdType_least;
# define  SOAD_INV_ROUT_GRP_ID     0xFFFF
#endif /* defined(SOAD_CONFIGURED_MAX_ROUT_GROUP) && (SOAD_CONFIGURED_MAX_ROUT_GROUP <= 255u) */

typedef SoAd_RoutingGroupIdType       SoAd_RoutingGroupIdxType;
typedef SoAd_RoutingGroupIdType_least SoAd_RoutingGroupIdxType_least;
#define SOAD_INV_ROUT_GRP_IDX         SOAD_INV_ROUT_GRP_ID
/* ---------------- */

typedef P2FUNC(void,              SOAD_CODE, SoAd_ShutdownFinishedFctPtrType) (void);

typedef struct
{
  SoAd_PduIdxType   TxPduIdx;
  PduLengthType     Len;
} SoAd_TcpTxQueueType;

typedef struct
{
  uint16 Idx;
  uint16 Lvl;
} SoAd_TcpTxQueueMgtType;

typedef struct
{
  P2VAR(SoAd_TcpTxQueueType,      AUTOMATIC, SOAD_VAR_NOINIT) QueuePtr;
  P2VAR(SoAd_TcpTxQueueMgtType,   AUTOMATIC, SOAD_VAR_NOINIT) MgtPtr;
  uint16                                                      Size;
} SoAd_TcpTxQueueConfigType;

typedef struct
{
  uint32  TxBufSize;
  uint32  RxBufSize;
  uint8   FctIdTlsNotif;
} SoAd_TcpTlsConfigType;

typedef struct
{
  SoAd_PduIdxType                                 TxPduIdx;
  PduLengthType                                   TxBytesLen;
  PduLengthType                                   TxBytesPending;
  SduDataPtrType                                  TxBufPtr;
  boolean                                         CancelRequested;
} SoAd_TxMgtType;

typedef struct
{
  SoAd_BufSegMgtType BufSegMgt;
  uint16             RouteIdx;
  PduLengthType      RxBytesPending;
  boolean            CancelRequested;
} SoAd_RxMgtType;

typedef uint8 SoAd_QueueListTypeType;
#define SOAD_QUEUE_LIST_TYPE_UINT8   0x00u
#define SOAD_QUEUE_LIST_TYPE_UINT16  0x01u

typedef uint8 SoAd_EventQueueBitPatternType;
#define SOAD_EVENT_QUEUE_BIT_PATTERN_TCPIP_SOCKETS    0x01u
#define SOAD_EVENT_QUEUE_BIT_PATTERN_TP_RX_SO_CON     0x02u
#define SOAD_EVENT_QUEUE_BIT_PATTERN_LOCAL_ADDR       0x04u
#define SOAD_EVENT_QUEUE_BIT_PATTERN_STATE_SO_CON     0x08u
#define SOAD_EVENT_QUEUE_BIT_PATTERN_TX_SO_CON        0x10u
#define SOAD_EVENT_QUEUE_BIT_PATTERN_IF_UDP_PDU_ROUTE 0x20u
#define SOAD_EVENT_QUEUE_BIT_PATTERN_IF_TX_ROUTE_GRP  0x40u

typedef struct
{
  uint16 Idx;
  uint16 Lvl;
} SoAd_EventQueueMgtType;

typedef struct
{
  uint16 Lvl;
} SoAd_TimeoutListMgtType;

typedef struct
{
  P2VAR(SoAd_EventQueueMgtType, AUTOMATIC, SOAD_VAR_NOINIT) EveMgtPtr;
  P2VAR(void,                   AUTOMATIC, SOAD_VAR_NOINIT) EveQuePtr;
  uint16                                                    EveQueSize;
  uint16                                                    EveQueLimit;
  SoAd_QueueListTypeType                                    EveQueType;
  SoAd_EventQueueBitPatternType                             EveQueBitPattern;
} SoAd_EventQueueType;

typedef uint8 SoAd_EventQueueFlagType;

typedef struct
{
  uint32  Timeout;
} SoAd_TimeoutListElemType;

typedef struct
{
  uint32  Timeout;
  uint8   HandleIdx;
} SoAd_TimeoutListElem8Type;

typedef struct
{
  uint32  Timeout;
  uint16  HandleIdx;
} SoAd_TimeoutListElem16Type;

typedef struct
{
  P2VAR(SoAd_TimeoutListMgtType,  AUTOMATIC, SOAD_VAR_NOINIT) TimeMgtPtr;
  P2VAR(SoAd_TimeoutListElemType, AUTOMATIC, SOAD_VAR_NOINIT) TimeListPtr;
  P2VAR(void,                     AUTOMATIC, SOAD_VAR_NOINIT) TimeListIdxMapPtr;
  uint16                                                      TimeListSize;
  uint16                                                      TimeListIdxMapSize;
  SoAd_QueueListTypeType                                      TimeListType;
} SoAd_TimeoutListType;

typedef SoAd_ShutdownFinishedFctPtrType SoAd_FunctionPointerShutdownFinishedType;

typedef struct
{
  P2VAR(PduLengthType,                    AUTOMATIC, SOAD_VAR_NOINIT) IfRxBufferOffsetPtr;
  P2VAR(uint16,                           AUTOMATIC, SOAD_VAR_NOINIT) TpRxBufferOffsetPtr;
  P2VAR(uint8,                            AUTOMATIC, SOAD_VAR_NOINIT) IfRxBufferPtr;
  P2VAR(uint8,                            AUTOMATIC, SOAD_VAR_NOINIT) TpRxBufferPtr;
} SoAd_RxBufferType;

typedef struct
{
  P2VAR(uint16,                           AUTOMATIC, SOAD_VAR_NOINIT) TpTxBufferOffsetPtr;
  P2VAR(uint8,                            AUTOMATIC, SOAD_VAR_NOINIT) TpTxBufferPtr;
} SoAd_TxBufferType;

typedef struct
{
#if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
  P2CONST(SoAd_RoutingGroupIdType,    AUTOMATIC, SOAD_CONST) RoutGrpIdColPtr;
#endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
  PduIdType                RxPduId;
#if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
  SoAd_RoutingGroupIdType RoutGrpIdNum;
#endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
  SoAd_UpperLayerType      UpperLayer;
  uint8                    UpperLayerId;
} SoAd_SocketRouteDestType;

typedef struct
{
#if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
  SoAd_PduHdrIdType        RxPduHdrId;
#endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
  SoAd_SocketRouteDestType SockRouteDest;
} SoAd_SocketRouteType;

typedef struct
{
  uint16    SockRouteIdxStart;
  uint16    SockRouteIdxNum;
} SoAd_SocketRouteCollectionType;

typedef uint8                           SoAd_TcpNoDelayType;
#define SOAD_TCP_NO_DELAY_ENABLED       0x00u
#define SOAD_TCP_NO_DELAY_DISABLED      0x01u
#define SOAD_TCP_NO_DELAY_NOT_SPECIFIED 0x02u

typedef struct
{
#if ( defined(SOAD_VTCP_KEEP_ALIVE_ENABLED) && (STD_ON == SOAD_VTCP_KEEP_ALIVE_ENABLED) )
  uint32              TcpKeepAliveTime;
  uint32              TcpKeepAliveProbesMax;
  uint32              TcpKeepAliveInterval;
  boolean             TcpKeepAlive;
#endif /* defined(SOAD_VTCP_KEEP_ALIVE_ENABLED) && (STD_ON == SOAD_VTCP_KEEP_ALIVE_ENABLED) */
#if ( defined(SOAD_VTCP_TX_BUF_MIN_ENABLED) && (STD_ON == SOAD_VTCP_TX_BUF_MIN_ENABLED) )
  uint16              TcpTxBufMin;
#endif /* defined(SOAD_VTCP_TX_BUF_MIN_ENABLED) && (STD_ON == SOAD_VTCP_TX_BUF_MIN_ENABLED) */
  SoAd_TcpNoDelayType TcpNoDelay;
  boolean             ImmedTpTxConf;
  boolean             TcpInitiate;
} SoAd_TcpSocketConfigType;

typedef struct
{
#if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
  uint16          UdpTriggerTimeout;
  uint16          NPduUdpTxBufferMin;
#endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */
#if ( defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) )
  uint16          AliveTimeoutMaxCnt;
#endif /* defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) */
#if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
  uint8           NPduUdpTxQueueSize;
#endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON) */
#if ( defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED) )
  uint8           RetryQueueLimit;
#endif /* defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED) */
#if ( defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) )
  uint8           ImmedIfTxConfListSize;
  boolean         ImmedIfTxConf;
#endif /* defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) */
#if ( defined(SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) && (STD_ON == SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) )
  boolean         UdpStrictHdrLenCheckEnabled;
#endif /* defined(SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) && (STD_ON == SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) */
  boolean         UdpListenOnly;
} SoAd_UdpSocketConfigType;

typedef struct
{
  P2CONST(SoAd_TcpSocketConfigType, AUTOMATIC, SOAD_CONST) SocketTcpPtr;
  P2CONST(SoAd_UdpSocketConfigType, AUTOMATIC, SOAD_CONST) SocketUdpPtr;
  SoAd_LocalAddrIdType    LocIpAddrId;
  SoAd_PortType           LocalPort;
  SoAd_SockIdxType        GrpSockIdx;
  uint32                  SockIfRxBufMin;
  uint16                  SockTpRxBufMin;
#if ( defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) )
  uint16                  SockTpTxBufMin;
#endif /* defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) */
  SoAd_ProtocolType       Protocol;
  SoAd_DomainType         Domain;
#if ( defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED) )
  uint8                   FramePriority;
#endif /* defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED) */
#if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
  boolean                 PduHdrEnabled;
#endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
#if ( defined(SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) )
  boolean                 BestMatchWithSockRouteEnabled;
#endif /* defined(SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) */
#if ( defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) )
  boolean                 BestMatchWithPduHeaderEnabled;
#endif /* defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) */
  boolean                 SockAutoSoConSetup;
  boolean                 MsgAcceptFilterEnabled;
} SoAd_SocketConnectionGroupType;

typedef struct
{
#if ( defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) )
  P2VAR(SoAd_SockAddrType,                         AUTOMATIC, SOAD_VAR_NOINIT) RcvRemSockPtr;
#endif /* defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) */
  P2CONST(SoAd_SockAddrType,                       AUTOMATIC, SOAD_CONST) RemSockPtr;
  P2CONST(SoAd_SocketConnectionGroupType,          AUTOMATIC, SOAD_CONST) SockConGrpPtr;
#if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  P2CONST(SoAd_TcpTxQueueConfigType,               AUTOMATIC, SOAD_CONST) TcpTxQueuePtr;
# if ( defined(SOAD_VTCP_TLS_ENABLED) && (STD_ON == SOAD_VTCP_TLS_ENABLED) )
  P2CONST(SoAd_TcpTlsConfigType,                   AUTOMATIC, SOAD_CONST) TcpTlsConfigPtr;
# endif /* defined(SOAD_VTCP_TLS_ENABLED) && (STD_ON == SOAD_VTCP_TLS_ENABLED) */
#endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
  SoAd_SockIdxType  SockIdx;
  uint16            SoConChgFuncBitPattern;
  uint16            IpAddrChgFuncBitPattern;
  SoAd_SoConIdType  SoConId;
  uint8             RemAddrState;
} SoAd_SocketConnectionType;

typedef struct
{
  SoAd_SoConIdType  SoConIdxStart;
  SoAd_SoConIdType  SoConIdxNum;
} SoAd_SocketConnectionIdCollectionType;

typedef P2VAR(uint8, AUTOMATIC, SOAD_CONST) SoAd_RoutingGroupBitPatternPtrType;
#define SOAD_ROUT_GRP_BIT_PATTERN_NONE      0x00  /* 00000000 */
#define SOAD_ROUT_GRP_BIT_PATTERN_ENABLED   0x01  /* 00000001 */
#define SOAD_ROUT_GRP_BIT_PATTERN_TRIGGER   0x02  /* 00000010 */

typedef struct
{
#if ( SOAD_VROUT_GROUP_TX_ENABLED == STD_ON )
  P2CONST(SoAd_RoutingGroupBitPatternPtrType, AUTOMATIC, SOAD_CONST)  RoutGrpStateColPtr;
#endif /* SOAD_VROUT_GROUP_TX_ENABLED == STD_ON */
  SoAd_SoConIdxType                                                   SoConIdx;
  PduIdType                                                           TxPduId;
#if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
  SoAd_PduHdrIdType                                                   TxPduHdrId;
#endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
#if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
  uint16                                                              UdpTriggerTimeout;
#endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */
#if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
  SoAd_RoutingGroupIdType                                             RoutGrpNum;
#endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */
#if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
  SoAd_TxUdpTriggerModeType                                           TxUdpTrigMode;
#endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */
} SoAd_PduRouteDestType;

typedef struct
{
  const SoAd_PduRouteDestType*const*                                 PduRouteDestListPtr;
  uint16                                                             PduRouteDestListSize;
} SoAd_SockConIdxPduRouteDestCollectionType;

typedef struct
{
  boolean         IsEnabledAtInit;
  boolean         TxTriggerable;
} SoAd_RoutingGroupType;

typedef struct
{
  P2CONST(uint16,                             AUTOMATIC, SOAD_CONST) IdColPtr;
  P2CONST(SoAd_RoutingGroupBitPatternPtrType, AUTOMATIC, SOAD_CONST) StateColPtr;
  uint16                                                             IdNum;
} SoAd_RoutingGroupIdSocketRouteCollectionType;

typedef struct
{
  const SoAd_PduRouteDestType*const*                                 PduRouteDestListPtr;
  P2CONST(SoAd_RoutingGroupBitPatternPtrType, AUTOMATIC, SOAD_CONST) StateColPtr;
  uint16                                                             PduRouteDestListSize;
} SoAd_RoutingGroupIdPduRouteCollectionType;

typedef struct
{
  const SoAd_PduRouteDestType*const*                       PduRouteDestListPtr;
  uint16                                                   PduRouteDestListSize;
  SoAd_UpperLayerType                                      UpperLayer;
  uint8                                                    UpperLayerId;
  boolean                                                  TxConfEnabled;
#if ( SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON )
  boolean                                                  IfTriggerTransmitEnabled;
#endif /* SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON */
#if ( SOAD_VTX_TP_OPTIMIZED_ENALBED == STD_ON )
  boolean                                                  TpOptimized;
#endif /* SOAD_VTX_TP_OPTIMIZED_ENALBED == STD_ON */
} SoAd_PduRouteType;

typedef struct
{
  uint32 TotalLen;
#if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
  uint16 RetryCnt;
#endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
  boolean TransmissionActive;
} SoAd_NPduUdpTxMgtType;

typedef struct
{
  uint16 Len;
} SoAd_NPduUdpTxBufMgtType;

typedef struct
{
  uint8 Lvl;
} SoAd_NPduUdpTxQueueMgtType;

typedef struct
{
#if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
  uint16            BufIdx;
#endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
  SoAd_PduIdxType   TxPduIdx;
  PduLengthType     Len;
  boolean           Copied;
} SoAd_NPduUdpTxQueueType;

typedef struct
{
  P2VAR(SoAd_NPduUdpTxMgtType, AUTOMATIC, SOAD_VAR_NOINIT)      MgtPtr;
#if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
  P2VAR(uint8, AUTOMATIC, SOAD_VAR_NOINIT)                      BufPtr;
  P2VAR(SoAd_NPduUdpTxBufMgtType, AUTOMATIC, SOAD_VAR_NOINIT)   BufMgtPtr;
#endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
#if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
  P2VAR(SoAd_NPduUdpTxQueueType, AUTOMATIC, SOAD_VAR_NOINIT)    QueuePtr;
  P2VAR(SoAd_NPduUdpTxQueueMgtType, AUTOMATIC, SOAD_VAR_NOINIT) QueueMgtPtr;
#endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
  SoAd_SoConIdType                                              SoConIdx;
} SoAd_NPduUdpTxType;

typedef uint8                                 SoAd_NPduReturnType;
#define SOAD_NPDU_OK                          0x00u
#define SOAD_NPDU_OVFL_NEW                    0x01u
#define SOAD_NPDU_OVFL_UPDATE                 0x02u
#define SOAD_NPDU_NOT_OK                      0x03u

typedef struct
{
  P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr;
  PduLengthType                          MaxLen;
} SoAd_IfTriggerTransmitBufferType;

typedef struct
{
  P2CONST(SoAd_LocalAddrIdType, AUTOMATIC, SOAD_CONST)  AddrIdListPtr;
  uint8                                                 AddrIdListNum;
#if ( defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED) )
  boolean                                               RetryEnabled;
#endif /* defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED) */
} SoAd_TcpIpCtrlType;

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
typedef struct
{
  P2CONST(SoAd_SockIdxType, AUTOMATIC, SOAD_CONST)  SockIdxColPtr;
  SoAd_SockIdxType                                  SockIdxNum;
} SoAd_LocalIpAddrSockIdxCollectionType;

typedef struct
{
  uint8*  BufPtr;
  uint16  MaxLen;
} SoAd_SocketRxBufferType;

typedef struct
{
  uint16  Offset;
  uint16  Len;
} SoAd_SocketRxBufferMgtType;
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

/**********************************************************************************************************************
  POST BUILD CONFIGURATION
**********************************************************************************************************************/
typedef struct
{
  SOAD_CONSTP2VAR(SoAd_EventQueueFlagType)                          EventQueueFlagsListPtr;
  SOAD_CONSTP2CONST(SoAd_EventQueueType)                            EventQueuesListPtr;
  SOAD_CONSTP2CONST(SoAd_TimeoutListType)                           TimeoutListsListPtr;
  SOAD_CONSTP2VAR(SoAd_SockAddrInetXType)                           SockConIdx2RemSockDynListPtr;
  SOAD_CONSTP2VAR(SoAd_SoConModeType)                               SockConIdx2StateListPtr;
  SOAD_CONSTP2VAR(SoAd_IpAddrStateType)                             SockConIdx2IpAddrStateListPtr;
  SOAD_CONSTP2VAR(SoAd_PortType)                                    SockIdx2LocPortDynListPtr;
  SOAD_CONSTP2VAR(SoAd_SocketIdType)                                SockIdx2SocketIdListPtr;
  SOAD_CONSTP2VAR(boolean)                                          SockConIdx2FlagAbortListPtr;
  SOAD_CONSTP2VAR(uint8)                                            SockConIdx2CloseModeListPtr;
  SOAD_CONSTP2VAR(uint8)                                            SockIdx2SockStateListPtr;
  SOAD_CONSTP2VAR(uint8)                                            SockConIdx2FlagCntOpClListPtr;
  SOAD_CONSTP2VAR(uint8)                                            SockConIdx2RemAddrStateListPtr;
  SOAD_CONSTP2CONST(SoAd_SocketConnectionType)                      SockConsListPtr;
  SOAD_CONSTP2CONST(SoAd_SocketConnectionIdCollectionType)          SockIdx2SoConIdxColListPtr;
  SOAD_CONSTP2CONST(SoAd_SoConIdxType)                              SockConId2SockConIdxMapPtr;
  SOAD_CONSTP2VAR(SoAd_TxMgtType)                                   SockConIdx2TxMgtListPtr;
  SOAD_CONSTP2VAR(SoAd_SoConIdType)                                 SockIdx2ActiveSoConIdxListPtr;
  SOAD_CONSTP2VAR(uint16)                                           TxPduIdx2PendingTxConfListPtr;
  SOAD_CONSTP2CONST(SoAd_SockConIdxPduRouteDestCollectionType)      SockConIdx2PduRouteDestColListPtr;
  SOAD_CONSTP2CONST(SoAd_PduRouteType)                              TxPduIdx2PduRouteListPtr;
  SOAD_CONSTP2CONST(PduIdType)                                      TxPduIdx2TxConfPduIdListPtr;
  SOAD_CONSTP2CONST(SoAd_PduIdxType)                                TxPduId2PduRouteIdxMapPtr;
  SOAD_CONSTP2VAR(SoAd_RxMgtType)                                   SockConIdx2RxMgtListPtr;
  SOAD_CONSTP2VAR(uint32)                                           SockIdx2SkipBytesListPtr;
  SOAD_CONSTP2CONST(SoAd_RxBufferType)                              SockConIdx2RxBufferListPtr;
  SOAD_CONSTP2CONST(SoAd_SocketRouteType)                           SockRoutesListPtr;
  SOAD_CONSTP2CONST(SoAd_SocketRouteCollectionType)                 SockConIdx2SockRouteColListPtr;
  SOAD_CONSTP2CONST(SoAd_PduIdxType)                                RxPduId2SockRouteIdxMapPtr;
  SOAD_CONSTP2CONST(uint16)                                         SockConIdx2NPduUdpTxIdxListPtr;
  SOAD_CONSTP2CONST(SoAd_NPduUdpTxType)                             NPduUdpTxListPtr;
  SOAD_CONSTP2CONST(uint16)                                         SockConIdx2IfTriggerTransmitBufIdxListPtr;
  SOAD_CONSTP2CONST(SoAd_IfTriggerTransmitBufferType)               IfTriggerTransmitBufferListPtr;
  SOAD_CONSTP2CONST(SoAd_TxBufferType)                              SockConIdx2TxBufferListPtr;
  SOAD_CONSTP2CONST(SoAd_RoutingGroupType)                          RouteGrpIdx2RoutingGroupListPtr;
  SOAD_CONSTP2CONST(SoAd_RoutingGroupIdxType)                       RouteGrpId2RouteGrpIdxMapPtr;
  SOAD_CONSTP2CONST(SoAd_RoutingGroupIdPduRouteCollectionType)      RouteGrpIdx2PduRouteDestColListPtr;
  SOAD_CONSTP2CONST(SoAd_RoutingGroupIdSocketRouteCollectionType)   RouteGrpIdx2SocketRouteColListPtr;
  SOAD_CONSTP2VAR(uint8)                                            IfRouteGrpTransmitBufPtr;
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
  SOAD_CONSTP2CONST(SoAd_LocalAddressType)                          LocalAddrPtr;
  SOAD_CONSTP2CONST(SoAd_LocalIpAddrType)                           AddrId2LocalIpAddrPtr;
  SOAD_CONSTP2VAR(SoAd_LocalIpAddrDynType)                          AddrId2LocalIpAddrDynPtr;
  SOAD_CONSTP2VAR(SoAd_LocalIpAddrReqStateType)                     AddrId2LocalIpAddrReqStatePtr;
  SOAD_CONSTP2CONST(SoAd_LocalIpAddrSockIdxCollectionType)          AddrId2SockIdxColPtr;
  SOAD_CONSTP2VAR(SoAd_MulticastAddrType)                           SockIdx2MulticastAddrPtr;
  SOAD_CONSTP2VAR(SoAd_SocketRxBufferMgtType)                       SockIdx2RxMgtPtr;
  SOAD_CONSTP2CONST(SoAd_SocketRxBufferType)                        SockIdx2RxBufPtr;
  SOAD_CONSTP2VAR(uint8)                                            SocketTxBufferPtr;
  SOAD_CONSTP2VAR(uint8)                                            SocketRxBufferPtr;
#else
  SOAD_CONSTP2CONST(uint8)                                          AddrId2TcpIpCtrlPtr;
  SOAD_CONSTP2CONST(SoAd_TcpIpCtrlType)                             TcpIpCtrlPtr;
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
  uint16                                                            EventQueueFlagsArraySize;
  uint8                                                             EventQueueTotal;
  uint8                                                             TimeoutListTotal;
  uint8                                                             EventQueueIdxSockIdx;
  uint8                                                             EventQueueIdxTpRxSoCon;
  uint8                                                             EventQueueIdxLocalAddr;
  uint8                                                             EventQueueIdxStateSoCon;
  uint8                                                             EventQueueIdxTxSoCon;
  uint8                                                             EventQueueIdxIfUdpPduRoute;
  uint8                                                             EventQueueIdxIfTxRouteGrp;
  uint8                                                             TimeoutListIdxUdpAlive;
  uint8                                                             TimeoutListIdxNPduUdpTx;
  SoAd_SoConIdType                                                  SockConTotal;
  SoAd_SoConIdxType                                                 SockConTotalWithInv;
  SoAd_RoutingGroupIdType                                           RouteGrpTotal;
  SoAd_RoutingGroupIdxType                                          RouteGrpTotalWithInv;
  PduIdType                                                         SockRouteTotal;
  SoAd_PduIdxType                                                   SockRouteTotalWithInv;
  PduIdType                                                         PduRouteTotal;
  SoAd_PduIdxType                                                   PduRouteTotalWithInv;
  SoAd_SockIdxType                                                  TcpIpSocketCnt;
  PduLengthType                                                     IfRouteGrpTransmitBufSize;
  PduLengthType                                                     MaxIfRouteGrpTransmitPduSize;
  uint16                                                            SockConIdx2NPduUdpTxIdxSize;
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
  uint16                                                            AddrIdTotal;
  uint16                                                            SocketTxBufferSize;
  uint16                                                            SocketRxBufferSize;
  boolean                                                           LingerTimeoutEnabled;
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
  uint16                                                            FinalMagicNumber;
} SoAd_ConfigType;

#endif /* !defined(SOAD_TYPES_H) */

/**********************************************************************************************************************
 *  END OF FILE: SoAd_Types.h
 *********************************************************************************************************************/
