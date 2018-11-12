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
 *         \file  TcpIp.h
 *        \brief  Implementation of TcpIp Module
 *
 *      \details  This file is part of the TcpIp module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Thorsten Albers               visal         Vector Informatik GmbH
 *  Frederik Dornemann            visfdn        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  The following table lists the changes affecting the following files:
 *    TcpIp.*
 *    TcpIp_Cbk.h
 *    TcpIp_Types.h
 *    TcpIp_Priv.*
 *    TcpIp_Priv_Types.h
 *    TcpIp_Tcp.*
 *    TcpIp_Tcp_Cbk.h
 *    TcpIp_Udp.*
 *    TcpIp_Udp_Cbk.h
 *
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  This module is the successor of Tp_TcpIp[5.00.02].
 *  -
 *  01.00.00  2015-06-18  visfdn  -             TcpIp: New module Tp_AsrTpTcpIp (combination of TcpIp, IpV4 and IpV6)
 *            2015-07-09  visfdn  ESCAN00083590 TcpIp: FEAT-1248: Configuration of the TCP/IP stack according to AR 4.2.1
 *            2015-07-09  visal   ESCAN00082689 TcpIp: FEAT-1283: Use hardware-based checksum calculation (IPv4, IPv6,
 *                                                     TCP, UDP and ICMP) if it is supported by the microcontroller
 *            2015-07-09  visal   ESCAN00082684 TcpIp: FEAT-1249: Optimized UDP retry behavior e.g. in case of ARP miss
 *                                                     (TcpIp_GetRemotePhysAddr and TcpIp_GetCtrlIdx added)
 *            2015-07-09  visal   ESCAN00083909 TcpIp: Remove the APIs TcpIp_Htonl and TcpIp_Htons
 *            2015-07-09  visal   ESCAN00083911 TcpIp: Remove function TcpIp_PrepareShutdown, not needed any more
 *            2015-07-09  visal   ESCAN00083912 TcpIp: Remove TcpIp_GetLocNetAddr and TcpIp_GetLocNetMask, not needed any more
 *            2015-07-09  visal   -             TcpIp: Remove extern declaration of all declared TcpIp functions
 *            2015-07-09  visal   -             Tcp  : Remove parameter SockIdxPtr from the internal API TcpIp_Tcp_RxIndication
 *            2015-06-24  visal   ESCAN00083056 Tcp  : TCP causes DET in IP and tries to use a wrong address to answer
 *                                                     a SYN in LISTEN state
 *            2015-06-24  visal   ESCAN00083183 TcpIp: Network mask of IPv4 address has wrong byte order after
 *                                                     TcpIp_RequestIpAddrAssignment() is called
 *            2015-06-25  visal   ESCAN00083300 Tcp  : TCP Array index out of bounds
 *            2015-06-25  visal   ESCAN00082914 Udp  : UDP frame sent even if <Ul>_CopyTxData returns BUFREQ_NOT_OK
 *            2015-06-25  visal   ESCAN00082737 TcpIp: TcpIp_Bind() returns E_NOT_OK and reports Det Error if
 *                                                     LocalAddrId is TCPIP_LOCALADDRID_ANY
 *            2015-07-09  visal   ESCAN00083547 Tcp  : Buffers can be assigned to a socket several times, leading to inconsistency
 *            2015-07-20  visal   ESCAN00083690 TcpIp: TcpIp causes memory access violation or Det in IpV4/IpV6 in Dual Stack mode
 *            2015-07-20  visal   ESCAN00082912 Tcp  : <Ul>_TcpAccepted return value not handled
 *  01.00.01  2015-08-21  visfdn  ESCAN00084660 Udp  : Use of uninitialized pointer PbufPtr in TcpIp_UdpTransmit()
 *            2015-08-21  visfdn  ESCAN00084653 Tcp  : no SACK permit or TCP timestamp option at ECU passive open
 *  01.00.02  2015-09-11  visfdn  ESCAN00084728 Tcp  : TCP sends unnecessary DUP-ACKs
 *            2015-09-11  visfdn  ESCAN00084743 Tcp  : TCPIP_TCP_DEFAULT_TX_MSS for IPv6 sockets incorrect.
 *            2015-09-11  visfdn  ESCAN00084740 Tcp  : retransmission the last (n-1) bytes of n bytes-segment unnecessarily during zero window probing
 *            2015-09-11  visfdn  ESCAN00084742 Tcp  : TCP sends too big MSS for IPv6 connections
 *            2015-09-11  visfdn  ESCAN00084656 Tcp  : TCP SYN triggers infinite number of ARP/NDP requests
 *            2015-09-11  visfdn  ESCAN00084924 Tcp  : TcpIp_Bind() did not detect an already requested connection (port check fail due to wrong byte order)
 *            2015-09-11  visfdn  -             All  : Resolved PClint warnings
 *            2015-10-14  visal   ESCAN00085847 TcpIp: Adapt code to avoid MISRA and PClint deviations
 *            2015-10-14  visal   ESCAN00085566 Tcp  : MISRA deviation: MISRA-C:2004 Rule 15.2
 *            2015-10-14  visfdn  ESCAN00083547 Tcp  : Buffers can be assigned to a socket several times, leading to inconsistency (rework)
 *  02.00.00  2015-11-27  visfdn  ESCAN00086824 Udp  : Support of multiple IP buffer fragments in TcpIp_UdpTransmit()
 *            2015-11-27  visfdn  ESCAN00086825 All  : TX checksum calculation always performed by lower layer
 *            2015-11-27  visal   ESCAN00086795 TcpIp: FEAT-10: Send the FQDN option via DHCP to identify the ECU
 *            2015-11-27  visal   ESCAN00086797 TcpIp: FEAT-10: Support triggering of IP address assignment
 *            2015-11-27  visal   ESCAN00086798 TcpIp: FEAT-10: Implement API to read the local physical address
 *            2015-11-27  visal   ESCAN00086848 TcpIp: Adapt wrong define values in DHCPv4
 *            2015-12-03  visfdn  ESCAN00086099 Tcp  : TCP calculates wrong message length from MSS received in IPv6 TCP SYN
 *            2015-12-03  visfdn  ESCAN00086097 Tcp  : Socket resources not released after TCP SYN with illegal option length is received
 *            2016-01-07  visal   ESCAN00087306 Tcp  : TCP Nagle algorithm can not be enabled / disabled in state CLOSED
 *  02.00.01  2016-01-29  visal   ESCAN00087828 TcpIp: Compiler error: Missing function declaration for TcpIp_DhcpV6ReadOption and TcpIp_DhcpV6WriteOption
 *            2016-01-29  visal   ESCAN00087910 TcpIp: Missing checks for valid address IDs in DHCP option APIs may lead to NULL-Ptr exceptions
 *            2016-01-29  visal   ESCAN00087908 TcpIp: Minor code rework due to MISRA / Code Review findings
 *            2016-01-28  visfdn  ESCAN00087894 Tcp  : TCP client connection attempt (SYN) rejected with RST
 *            2016-01-28  visfdn  ESCAN00087897 Tcp  : TCP enters congestion avoidance too early/late or memory access violation (invalid read access)
 *  02.01.00  2016-01-19  visfdn  ESCAN00087557 TcpIp: Allow configuration of TcpIp lower layer other than EthIf
 *            2016-02-26  visal   ESCAN00087677 All  : FEAT-1347: TLS as TcpIp plug-in
 *            2016-02-26  visal   ESCAN00088589 All  : Remove XX defines for internal callback functions (events, and random number)
 *            2016-02-26  visal   ------------- Tcp  : Implement the same TCP interrupt locks as in version 3.10.11
 *            2016-02-26  visal   ------------- Tcp  : Code rework: replace if-else chain by switch-case construct
 *            2016-02-26  visal   ESCAN00088319 Udp  : Compiler error: TcpIp_Udp.c: TcpIp_DhcpV4_Cbk.h: No such file or directory
 *            2016-03-30  visal   ESCAN00088304 TcpIp: IpAddrAssignment is not indicated to the socket owners
 *  03.00.00  2016-05-12  visfdn  ESCAN00089974 TcpIp: TcpIp_GetIpAddr() does not provide values for IPv6 netmask and default router.
 *            2016-05-17  visfdn  ESCAN00090041 Tcp  : Improved internal TCP TX Retry Queue handling
 *            2016-05-17  visfdn  ESCAN00088736 TcpIp: TCP rejects SYN if listen socket is bound to all IP addresses of a controller
 *            2016-05-17  visfdn  ESCAN00084745 Tcp  : Usage of two different configuration parameters for Retransmission Timer
 *            2016-05-17  visfdn  ESCAN00084724 Tcp  : Nagle-Algorithm does not buffer data until outstanding data has been ACKed
 *            2016-05-17  visfdn  ESCAN00084726 Tcp  : TCP stops sending and does not ACK received data
 *            2016-05-18  visfdn  ESCAN00085683 Tcp  : Zero Window Probe is sent immediately and not after RTO seconds
 *            2016-06-13  visfdn  ESCAN00089368 TcpIp: FEAT-1516: Support IP address assignment methods according to AR 4.2.1 for IPv4
 *            2016-06-22  visfdn  ESCAN00088858 TcpIp: DHCPv4 server does not respond correctly to a client with broadcast flag set to 0
 *            2016-06-23  visal   ESCAN00089291 Tcp  : ECU ceases to transmit TCP data completely or partially
 *            2016-06-23  visal   ESCAN00089289 Tcp  : Reported TCP receive window size incorrect
 *            2016-06-23  visal   ESCAN00089388 Tcp  : ECU stops responding during TCP communication
 *            2016-07-12  visal   ESCAN00090966 TcpIp: Calling TcpIp_TcpReceived causes division by zero
 *  03.00.01  2016-08-11  visfdn  ESCAN00091009 Tcp  : MSL timer has an underflow if configured to 0s
 *  03.00.02  2016-08-29  visal   ESCAN00089031 Tcp  : [IETF] Close on listen socket did not close not established connections
 *            2016-08-29  visal   ESCAN00085278 Tcp  : ECU sends SYN/ACK with MSS = 0 if Listen socket has no assigned buffers
 *            2016-09-01  visal   ESCAN00091010 TcpIp: It is not possible to send less data than requested when using TLS
 *            2016-09-15  visal   ESCAN00084719 TcpIp: Compiler warning: Several warnings when the component is compiled with Visual Studio
 *  04.00.00  2016-10-04  visfdn  ESCAN00092165 TcpIp: FEAT-1953: Support of Dynamic Length in CopyTxData
 *            2016-10-14  visfdn  ESCAN00092054 TcpIp: Compiler warning: Inconsistent memory mapping for constant TcpIp_Ipv6NullAddr
 *            2016-10-14  visfdn  ESCAN00084737 Udp  : UDP packets not sent if socket is unbound
 *            2016-10-14  visfdn  ESCAN00092354 TcpIp: Use incrementing numbers for TCP/UDP ports in dynamic range.
 *            2016-10-14  visfdn  FEATC-258     TcpIp: FEAT-1816: Split MainFunctions to optimize gateway use-case
 *            2016-10-14  visfdn  FEATC-263     Tcp  : FEAT-1509: Support of the TCP Keep Alive Mechanism
 *            2016-10-14  visfdn  ESCAN00092353 Tcp  : TCP does not send last ACK segment during active close if MSL is 0
 *            2016-10-28  visal   FEATC-361     TcpIp: FEAT-1996: TLS Heartbeat Extension
 *  04.00.01  2017-01-02  visal   ESCAN00092609 Tcp  : TcpIp calls TxConfirmation of upper layer with locked interrupts
 *            2017-01-02  visal   ESCAN00093077 Tcp  : TCP connection initiated or accepted by SoAd is interrupted or cannot be established.
 *  04.00.02  2017-02-02  visfdn  ESCAN00093113 Tcp  : TCP closes connection via RST if reserved bits in TCP header are set 
 *            2017-02-02  visfdn  ESCAN00093812 Tcp  : TcpIp calls <Up>_RxIndication() and <Up>_TxConfirmation() for TCP data in unexpected order
 *            2017-02-03  visfdn  ESCAN00093622 Udp  : Invalid UDP packet with length bigger than IP payload length is not dropped
 *            2017-02-13  visfdn  ESCAN00093149 Tcp  : TCP sends data after FIN
 *            2017-02-14  visfdn  ESCAN00093967 TcpIp: Inconsistent variable memory mapping causes triggering of OS Protection Hook
 *  05.00.00  2017-02-22  visfdn  ESCAN00094090 TcpIp: Compiler error: Missing definition of NvM_BlockIdType
 *  05.00.01  2017-04-26  visfdn  ESCAN00094737 Tcp  : TCP does not send keep-alive messages
 *********************************************************************************************************************/
#if !defined TCPIP_H  /* PRQA S 0883 */ /* MD_TCPIP_19.15_0883 */
# define TCPIP_H

/**************************************************************************************************
**************************************************************************************************/

/*
+---+         +--------+   +--------+   +--------+
|   |         |        |   |        |   |        |
|   | ------- |  SoAd  |   |  SCC   |   |  HTTP  |  ...
|   |         |        |   |        |   |        |
|   |         +--------+   +--------+   +--------+
|   |             |            |            |
|   |      +-------------------------------------------------+
| E |      |   +---------------------------+         (TcpIp) |
| t |      |   |                           |                 |
| h |      |   |           TCPIP           |                 |
| S |      |   |                           |                 |
| m |      |   +---------------------------+                 |
|   |      |         |               |                       |   +--------+
|   |      |   +-----------+   +-----------+                 |   |        |
|   |      |   |    UDP    |   |    TCP    |---------------------|  TLS   |
|   |      |   +-----------+   +-----------+                 |   |        |
|   |      +-------------------------------------------------+   +--------+
|   |                |                            |
|   |                |                            |
|   |      +-------------------+         +-------------------+
|   |      |            (IpV4) |         |            (IpV6) |
|   |      |                   |         |                   |
|   |      |       IPv4        |         |       IPv6        |
|   |      |      ICMPv4       |         |      ICMPv6       |
|   |      |      DHCPv4       |         |      DHCPv6       |
|   |      |       ARP         |         |       NDP         |
|   |      |                   |         |                   |
|   |      +-------------------+         +-------------------+
|   |                         |           |
|   |                         |           |
|   |                      +-----------------+
|   | -------------------- |      EthIf      |
+---+                      +-----------------+
                              |            \
                    +-----------------+     \  +-------------+
                    |       Eth       |      --|   EthTrcv   |
                    +-----------------+        +-------------+
*/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

#include "TcpIp_Cfg.h"
#include "TcpIp_Cbk.h"
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# include "TcpIp_Arp_Cbk.h"
# include "TcpIp_IpV4_Cbk.h"
#endif
#if (TCPIP_SUPPORT_IPV6 == STD_ON)
# include "TcpIp_IpV6_Cbk.h"
#endif

#if (STD_ON == TCPIP_SUPPORT_SOAD)
# include "SoAd_Types.h"
#endif

#include "TcpIp_Lcfg.h"

#include "TcpIp_Types.h"

#if (TCPIP_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#if (TCPIP_SUPPORT_TLS == STD_ON)
# include "NvM.h"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* software module version */
#define TCPIP_SW_MAJOR_VERSION                     5u
#define TCPIP_SW_MINOR_VERSION                     0u
#define TCPIP_SW_PATCH_VERSION                     1u

#define TP_ASRTPTCPIP_VERSION                      (TCPIP_SW_MAJOR_VERSION << 8 | TCPIP_SW_MINOR_VERSION)

/* supported Autosar version */
#define TCPIP_AR_RELEASE_MAJOR_VERSION             4u
#define TCPIP_AR_RELEASE_MINOR_VERSION             2u
#define TCPIP_AR_RELEASE_REVISION_VERSION          1u

#define TCPIP_VENDOR_ID                           30u   /* Vector Informatik */
#define TCPIP_VINSTANCE_ID                         1u   /* 1=TcpIp, 2=IpV4, 3=IpV6, 4=DhcpV4Server */
#define TCPIP_MODULE_ID                          170u

/* TCPIP ApiIds */
/* ASR4.2 APIs */
#define TCPIP_API_ID_INIT                       0x01u  /* ASR4.2.1 value */
#define TCPIP_API_ID_GET_VERSION_INFO           0x02u  /* ASR4.2.1 value */
#define TCPIP_API_ID_GET_SOCKET                 0x03u  /* ASR4.2.1 value */
#define TCPIP_API_ID_CLOSE                      0x04u  /* ASR4.2.1 value */
#define TCPIP_API_ID_BIND                       0x05u  /* ASR4.2.1 value */
#define TCPIP_API_ID_TCP_CONNECT                0x06u  /* ASR4.2.1 value */
#define TCPIP_API_ID_TCP_LISTEN                 0x07u  /* ASR4.2.1 value */
#define TCPIP_API_ID_TCP_RECEIVED               0x08u  /* ASR4.2.1 value */
#define TCPIP_API_ID_REQ_IP_ADDR_ASSIGN         0x0Au  /* ASR4.2.1 value */
#define TCPIP_API_ID_REL_IP_ADDR_ASSIGN         0x0Bu  /* ASR4.2.1 value */
#define TCPIP_API_ID_SET_DHCP_READ_OPT          0x0Du  /* ASR4.2.1 value */
#define TCPIP_API_ID_SET_DHCP_WRITE_OPT         0x0Eu  /* ASR4.2.1 value */
#define TCPIP_API_ID_CHANGE_PARAM               0x0Fu  /* ASR4.2.1 value */
#define TCPIP_API_ID_GET_PHYS_ADDR              0x11u  /* ASR4.2.1 value */
#define TCPIP_API_ID_UDP_TRANSMIT               0x12u  /* ASR4.2.1 value */
#define TCPIP_API_ID_TCP_TRANSMIT               0x13u  /* ASR4.2.1 value */
#define TCPIP_API_ID_RXINDICATION               0x14u  /* ASR4.2.1 value */
#define TCPIP_API_ID_MAIN_FUNCTION              0x15u  /* ASR4.2.1 value */
#define TCPIP_API_ID_GET_REMOTE_PHYS_ADDR       0x16u  /* ASR4.2.1 value */
#define TCPIP_API_ID_GET_CTRL_IDX               0x17u  /* ASR4.2.1 value */
#define TCPIP_API_ID_SET_DHCP_V6_READ_OPT       0x19u  /* ASR4.2.1 value */
#define TCPIP_API_ID_SET_DHCP_V6_WRITE_OPT      0x1Au  /* ASR4.2.1 value */

/* Vector defined APIs */
#define TCPIP_API_ID_PROVIDE_TX_BUFFER_INT              0x81u
#define TCPIP_API_ID_PROVIDE_TX_BUFFER                  0x82u
#define TCPIP_API_ID_TRANSMIT_TO                        0x83u
#define TCPIP_API_ID_TRANSMIT_TO_INT                    0x84u
#define TCPIP_API_ID_GET_LOC_NET_ADDR                   0x85u
#define TCPIP_API_ID_GET_LOC_NET_MASK                   0x86u
#define TCPIP_API_ID_SET_DHCP_HOST_NAME                 0x87u
#define TCPIP_API_ID_SET_CLIENT_CERT_INFO               0x88u
#define TCPIP_API_ID_GET_NVM_BLOCK_FOR_USED_ROOT_CERT   0x89u
#define TCPIP_API_ID_ROOT_CERT_WAS_MODIFIED             0x8Au

/* stack internal APIs: */

#define TCPIP_API_ID_CBK_RX_INDICATION          0x90u
#define TCPIP_API_ID_CBK_TX_CONFIRMATION        0x91u
#define TCPIP_API_ID_CBK_TCP_ACCEPTED           0x92u
#define TCPIP_API_ID_CBK_TCP_CONNECTED          0x93u
#define TCPIP_API_ID_CBK_TCP_IP_EVENT           0x94u
#define TCPIP_API_ID_CBK_COPY_TX_DATA           0x95u

#define TCPIP_API_ID_RX_SOCK_IDENT              0x96u
#define TCPIP_API_ID_TCP_STATE_CHG              0x97u
#define TCPIP_API_ID_LOC_IP_ASS_CHG             0x98u
#define TCPIP_API_ID_PREPARE_SHUTDOWN           0x99u
#define TCPIP_API_ID_TRCV_LINK_STATE_CHG        0x9Au
#define TCPIP_API_ID_ADDR_RES_TIMEOUT           0x9Bu
#define TCPIP_API_ID_SOCK_ADDR_IS_EQ            0x9Cu
#define TCPIP_API_ID_SOCK_ADDR_IS_EQ_OR_UNSPEC  0x9Du
#define TCPIP_API_ID_PATH_MTU_CHG               0x9Eu
#define TCPIP_API_ID_GET_IP_ADDR_CFG_SRC        0x9Fu
#define TCPIP_API_ID_GET_IP_ADDR                0xA0u
#define TCPIP_API_ID_GET_REM_NET_ADDR           0xA1u

#define TCPIP_API_ID_RX_INDICATION              0xA2u
#define TCPIP_API_ID_TX_CONFIRMATION            0xA3u

#define TCPIP_API_ID_V_VRESET                   0xA4u
#define TCPIP_API_ID_V_VRESET_L4                0xA5u
#define TCPIP_API_ID_V_DEL_SOCK_ADDR_MAPPING    0xA6u
#define TCPIP_API_ID_V_COPY_PBUF_TO_PBUF        0xA7u

/* Additional functions */
#define TCPIP_API_ID_GET_DNS_SERV_ADDR          0xA8u
#define TCPIP_API_ID_GET_LOCAL_SOCK_ADDR        0xA9u
#define TCPIP_API_ID_DIAG_DATA_READ_ACCESS      0xAAu

/* ------------------------------------------------------ */

/* TCPIP DET errors */
/* NEW ASR42x DET errors */
#define TCPIP_E_NO_ERROR       0x00  /* No error occured. */
#define TCPIP_E_NOTINIT        0x01  /* API service called before initializing the module */
#define TCPIP_E_PARAM_POINTER  0x02  /* API service called with NULL pointer */
#define TCPIP_E_INV_ARG        0x03  /* API service called with invalid argument */
#define TCPIP_E_NOBUFS         0x04  /* No buffer space available */
#define TCPIP_E_MSGSIZE        0x07  /* Message too long */
#define TCPIP_E_PROTOTYPE      0x08  /* Protocol wrong type for socket */
#define TCPIP_E_ADDRINUSE      0x09  /* Address already in use */
#define TCPIP_E_ADDRNOTAVAIL   0x0A  /* Can't assign requested address */
#define TCPIP_E_ISCONN         0x0B  /* Socket is already connected */
#define TCPIP_E_NOTCONN        0x0C  /* Socket is not connected */
#define TCPIP_E_NOPROTOOPT     0x0D  /* Protocol not available */
#define TCPIP_E_AFNOSUPPORT    0x0E  /* Address family not supported by protocol family */
#define TCPIP_E_INIT_FAILED    0x0F  /* Invalid configuration set selection */

#define TCPIP_E_INV_SOCK_ID    0x20  /* Vector Extension */ /* invalid socket idx */
#define TCPIP_E_CBK_REQUIRED   0x21  /* Callback function not configured but required due to socket owner runtime behavior.. */

/* ------------------------------------------------------ */

#define TCPIP_PROTOCOL_TCP                         6u
#define TCPIP_PROTOCOL_UDP                        17u

#define TCPIP_INADDR_BROADCAST            0xFFFFFFFFu
#define TCPIP_INADDR_ANY                  0x00000000u
#define TCPIP_PORT_ANY                        0x0000u

#define TCPIP_SOCK_ADDR_LEN_BYTE                (16u)

/* SOCK protocol */
#define TCPIP_SOCK_PROT_NONE                     (0u)
#define TCPIP_SOCK_PROT_UDP                     (17u)
#define TCPIP_SOCK_PROT_TCP                      (6u)

/* SOCKET states */
/* SOCKET states / state changes */
#define TCPIP_SOCK_STATES                        0x00
#define TCPIP_SOCK_STATE_OK                      0x01  /* connection established */
/* UDP states / state changes */
#define TCPIP_UDP_STATES                         0x10
#define TCPIP_UDP_STATE_CONN_ESTAB               0x11  /* connection established */
/* TCP states / state changes */
#define TCPIP_TCP_STATES                         0x20
#define TCPIP_TCP_STATE_CONN_ESTAB               0x21  /* connection established */
#define TCPIP_TCP_STATE_CONN_REQ_REC             0x22  /* SYN received on listening socket */
#define TCPIP_TCP_STATE_FIN_REC                  0x23  /* FIN received */
#define TCPIP_TCP_STATE_RST_REC                  0x24  /* Reset received */
#define TCPIP_TCP_STATE_CONN_REFUSED             0x25  /* connection refused by peer */
#define TCPIP_TCP_STATE_CONN_CLOSING             0x26  /* connection is about to close */
#define TCPIP_TCP_STATE_CLOSED                   0x27  /* connection is closed */
#define TCPIP_TCP_STATE_CONNECTED                0x28  /* host connected to peer */
#define TCPIP_TCP_STATE_ACCEPTED                 0x29  /* peer connected to host */

/* Socket error codes (uint16 values) */
#define TCPIP_SOCK_ERR_00087     87u /* RFC: "error: xx", WinSock: WSA_INVALID_PARAMETER 87 - "One or more parameters are invalid" */
#define TCPIP_SOCK_ERR_10022  10022u /* RFC: "error: xx", WinSock: WSAEINVAL 10022 - "Invalid argument" */
#define TCPIP_SOCK_ERR_10035  10035u /* RFC: "error: xx", WinSock: WSAEWOULDBLOCK 10035 - "Resource temporarily unavailable" */
#define TCPIP_SOCK_ERR_10038  10038u /* RFC: "error: xx", WinSock: WSAENOTSOCK 10038 - "Socket operation on nonsocket" */
#define TCPIP_SOCK_ERR_10039  10039u /* RFC: "error: foreign socket unspecified", WinSock: WSAEDESTADDRREQ 10039 - "Destination address required" */
#define TCPIP_SOCK_ERR_10043  10043u /* RFC: "error: xx", WinSock: WSAEPROTONOSUPPORT 10043 - "Protocol not supported" */
#define TCPIP_SOCK_ERR_10044  10044u /* RFC: "error: xx", WinSock: WSAESOCKTNOSUPPORT 10044 - "Socket type not supported" */ /* e.g. RAW-Socket */
#define TCPIP_SOCK_ERR_10046  10046u /* RFC: "error: xx", WinSock: WSAEPFNOSUPPORT 10046 - "Protocol family not supported" */
#define TCPIP_SOCK_ERR_10047  10047u /* RFC: "error: xx", WinSock: WSAEAFNOSUPPORT 10047 - "Address family not supported by protocol family" */
#define TCPIP_SOCK_ERR_10048  10048u /* RFC: "error: xx", WinSock: WSAEADDRINUSE 10048 - "Address already in use" */
#define TCPIP_SOCK_ERR_10054  10054u /* RFC: "error: xx", WinSock: WSAECONNRESET 10054 - "Connection reset by peer" */
#define TCPIP_SOCK_ERR_10056  10056u /* RFC: "error: connection already exists", WinSock: WSAEISCONN 10056 - "Socket is already connected" */
#define TCPIP_SOCK_ERR_10057  10057u /* RFC: "error: xx", WinSock: WSAENOTCONN 10057 - "Socket is not connected" */
#define TCPIP_SOCK_ERR_10061  10061u /* RFC: "error: xx", WinSock: WSAECONNREFUSED 10061 - "Connection refused" */
#define TCPIP_SOCK_ERR_10101  10101u /* RFC: "error: connection closing", WinSock: WSAEDISCON 10101 - "Graceful shutdown in progress" */

#define TCPIP_SOCK_ERR_10013  10013u /* RFC: "error: xx", WinSock: WSAEACCES 10013 - "broadcast access not allowed" */
#define TCPIP_SOCK_ERR_10040  10040u /* RFC: "error: xx", WinSock: WSAEMSGSIZE 10040 - "Message too long" */

/* ------------------------------------------------------ */

/* TCPIP module state */
#define TCPIP_STATE_UNINIT                       0x00u
#define TCPIP_STATE_INIT                         0x01u

/* ------------------------------------------------------ */

#define TCPIP_INV_SOCK_HND                       (0xFF)

#define TCPIP_IP_PROT_VER_4                      0x04u
#define TCPIP_IP_PROT_VER_6                      0x06u

#define TCPIP_IPVX_ADDR_ID_ANY         0xFF  /* ANY IP address id, either for IPv4 or IpV6 (IP local id)*/  /* TODO ASR4: has to be the same in IpV4 and IpV6 */

/* IP address configuration sources */
#define TCPIP_IP_CFG_SRC_NONE       0
#define TCPIP_IP_CFG_SRC_FIX        1
#define TCPIP_IP_CFG_SRC_DHCP       2
#define TCPIP_IP_CFG_SRC_LL         3  /* link local */
#define TCPIP_IP_CFG_SRC_RA         4  /* router advertisement */
#define TCPIP_IP_CFG_SRC_PRIV_EXT   5  /* temporaray address configured by privacy extensions */

/* DHCP Message Type defines */
#if (TCPIP_SUPPORT_DHCPV4 == STD_ON)
# define TCPIP_DHCPV4_MSG_DISCOVER                  1U
# define TCPIP_DHCPV4_MSG_OFFER                     2U
# define TCPIP_DHCPV4_MSG_REQUEST                   3U
# define TCPIP_DHCPV4_MSG_DECLINE                   4U
# define TCPIP_DHCPV4_MSG_ACK                       5U
# define TCPIP_DHCPV4_MSG_NACK                      6U
# define TCPIP_DHCPV4_MSG_RELEASE                   7U
# define TCPIP_DHCPV4_MSG_INFORM                    8U
# if ((TCPIP_DHCPV4_SUPPORT_OPTIONS == STD_ON) && (TCPIP_DHCPV4_TX_OPTION_CNT > 0))  /* PRQA S 3332 */ /* MD_TCPIP_19.11_3332 */
#  define TCPIP_DHCPV4_MSG_FLAG_DISCOVER            (1<<(TCPIP_DHCPV4_MSG_DISCOVER -1))
#  define TCPIP_DHCPV4_MSG_FLAG_OFFER               (1<<(TCPIP_DHCPV4_MSG_OFFER -1))
#  define TCPIP_DHCPV4_MSG_FLAG_REQUEST             (1<<(TCPIP_DHCPV4_MSG_REQUEST -1))
#  define TCPIP_DHCPV4_MSG_FLAG_DECLINE             (1<<(TCPIP_DHCPV4_MSG_DECLINE -1))
#  define TCPIP_DHCPV4_MSG_FLAG_ACK                 (1<<(TCPIP_DHCPV4_MSG_ACK -1))
#  define TCPIP_DHCPV4_MSG_FLAG_NACK                (1<<(TCPIP_DHCPV4_MSG_NACK -1))
#  define TCPIP_DHCPV4_MSG_FLAG_RELEASE             (1<<(TCPIP_DHCPV4_MSG_RELEASE -1))
#  define TCPIP_DHCPV4_MSG_FLAG_INFORM              (1<<(TCPIP_DHCPV4_MSG_INFORM -1))
#  define TCPIP_DHCPV4_MSG_FLAG_ALLWAYS             (0xFFu)
# endif
#endif

#if (TCPIP_SUPPORT_DHCPV6 == STD_ON)
# define TCPIP_DHCPV6_MSG_SOLICIT                   1U
# define TCPIP_DHCPV6_MSG_ADVERTISE                 2U
# define TCPIP_DHCPV6_MSG_REQUEST                   3U
# define TCPIP_DHCPV6_MSG_CONFIRM                   4U
# define TCPIP_DHCPV6_MSG_RENEW                     5U
# define TCPIP_DHCPV6_MSG_REBIND                    6U
# define TCPIP_DHCPV6_MSG_REPLY                     7U
# define TCPIP_DHCPV6_MSG_RELEASE                   8U
# define TCPIP_DHCPV6_MSG_DECLINE                   9U
# define TCPIP_DHCPV6_MSG_RECONFIGURE              10U
# define TCPIP_DHCPV6_MSG_INFORMATION_REQUEST      11U
# define TCPIP_DHCPV6_MSG_RELAY_FORWARD            12U
# define TCPIP_DHCPV6_MSG_RELAY_REPLY              13U
# if ((TCPIP_DHCPV6_SUPPORT_OPTIONS == STD_ON) && (TCPIP_DHCPV6_TX_OPTION_CNT > 0))  /* PRQA S 3332 */ /* MD_TCPIP_19.11_3332 */
#  define TCPIP_DHCPV6_MSG_FLAG_SOLICIT             (1<<TCPIP_DHCPV6_MSG_SOLICIT)
#  define TCPIP_DHCPV6_MSG_FLAG_ADVERTISE           (1<<TCPIP_DHCPV6_MSG_ADVERTISE)
#  define TCPIP_DHCPV6_MSG_FLAG_REQUEST             (1<<TCPIP_DHCPV6_MSG_REQUEST)
#  define TCPIP_DHCPV6_MSG_FLAG_CONFIRM             (1<<TCPIP_DHCPV6_MSG_CONFIRM)
#  define TCPIP_DHCPV6_MSG_FLAG_RENEW               (1<<TCPIP_DHCPV6_MSG_RENEW)
#  define TCPIP_DHCPV6_MSG_FLAG_REBIND              (1<<TCPIP_DHCPV6_MSG_REBIND)
#  define TCPIP_DHCPV6_MSG_FLAG_REPLY               (1<<TCPIP_DHCPV6_MSG_REPLY)
#  define TCPIP_DHCPV6_MSG_FLAG_RELEASE             (1<<TCPIP_DHCPV6_MSG_RELEASE)
#  define TCPIP_DHCPV6_MSG_FLAG_DECLINE             (1<<TCPIP_DHCPV6_MSG_DECLINE)
#  define TCPIP_DHCPV6_MSG_FLAG_RECONFIGURE         (1<<TCPIP_DHCPV6_MSG_RECONFIGURE)
#  define TCPIP_DHCPV6_MSG_FLAG_INFORMATION_REQUEST (1<<TCPIP_DHCPV6_MSG_INFORMATION_REQUEST)
#  define TCPIP_DHCPV6_MSG_FLAG_RELAY_FORWARD       (1<<TCPIP_DHCPV6_MSG_RELAY_FORWARD)
#  define TCPIP_DHCPV6_MSG_FLAG_RELAY_REPLY         (1<<TCPIP_DHCPV6_MSG_RELAY_REPLY)
#  define TCPIP_DHCPV6_MSG_FLAG_ALLWAYS             (0xFFFFu)
# endif
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(TcpIp_TcpIpErrorType, TCPIP_VAR_NOINIT) TcpIp_LastSockError;

#define TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ----- */
#define TCPIP_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(TcpIp_StateType, TCPIP_VAR_ZERO_INIT) TcpIp_State;

#define TCPIP_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  TcpIp_InitMemory
 **********************************************************************************************************************/
/*! \brief         Initialize the TcpIp-internal global module state variable.
 *  \param[in]     void             none
 *  \return        void
 *  \context       initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_InitMemory(void);

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
    P2CONST(TcpIp_ConfigType, TCPIP_PBCFG, TCPIP_CONST) ConfigPtr );

/***********************************************************************************************************************
 *  TcpIp_Shutdown
 **********************************************************************************************************************/
/*! \brief         Shutdown the module TcpIp.
 *  \param[in]     void             none
 *  \return        void
 *  \context       task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Shutdown( void );

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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetSocketForUser(
    TcpIp_DomainType Domain,
    TcpIp_ProtocolType Protocol,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, TCPIP_APPL_DATA) SocketIdPtr,
    uint8 UserIndex );

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
    uint16 MaxChannels );
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
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RemoteAddrPtr );
#endif

#if (TCPIP_SUPPORT_TCP == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_TcpTransmit
 **********************************************************************************************************************/
/*! \brief      Transmit TCP message
 *  \description                   This service requests transmission of data via TCP to a remote node. The transmission of the data is decoupled.
 *  \param[in]  SocketId           socket index
 *  \param[in]  DataPtr            Pointer to a linear buffer of AvailableLength bytes containing the data to be
 *                                 transmitted. In case DataPtr is a NULL_PTR, TcpIp shall retrieve data from SoAd via
 *                                 callback SoAd_CopyTxData().
 *  \param[in]  AvailableLength    Available data for transmission in bytes
 *  \param[in]  ForceRetrieve      This parameter is only valid if DataPtr is a NULL_PTR. Indicates how the TCP/IP stack
 *                                 retrieves data from SoAd if DataPtr is a NULL_PTR.<br>
 *                                 TRUE: the whole data indicated by availableLength shall be retrieved from the upper
 *                                 layer via one or multiple SoAd_CopyTxData() calls within the context of this transmit
 *                                 function.
 *                                 FALSE: The TCP/IP stack may retrieve up to availableLength data from the upper layer.
 *                                 It is allowed to retrieve less than availableLength bytes. Note: Not retrieved data
 *                                 will be provided by SoAd with the next call to TcpIp_TcpTransmit (along with new data
 *                                 if available).
 *  \return     E_OK               The request has been accepted <br>
 *              E_NOT_OK           The request has not been accepted
 *  \note       The TCP segment(s) are sent dependent on runtime factors (e.g. receive window) and configuration
 *                                 parameter (e.g. Nagle algorithm).
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpTransmit(
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr,
    uint32 AvailableLength,
    boolean ForceRetrieve );
#endif  /* (TCPIP_SUPPORT_TCP == STD_ON) */

/***********************************************************************************************************************
 *  TcpIp_UdpTransmit
 **********************************************************************************************************************/
/*! \brief         Transmit UDP message
 *  \description   This service transmits data via UDP to a remote node. The transmission of the data is immediately
 *                 performed with this function call by forwarding it to EthIf.
 *  \param[in]     SocketId           socket index
 *  \param[in]     DataPtr            Pointer to a linear buffer of TotalLength bytes containing the data to be
 *                                    transmitted. In case DataPtr is a NULL_PTR, TcpIp shall retrieve data from SoAd via
 *                                    callback SoAd_CopyTxData().
 *  \param[in]     RemoteAddrPtr      IP address and port of the remote host to transmit to.
 *  \param[in]     TotalLength        indicates the payload size of the UDP datagram.
 *  \return        TCPIP_OK           UDP message has been forwarded to EthIf for transmission. <br>
 *                 TCPIP_E_NOT_OK     UDP message could not be sent because of a permanent error, e.g. message is too
 *                                    long.
 *  \note          This function may not be called reentrant from one socket owner.
 *  \context       task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_UdpTransmit(
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) RemoteAddrPtr,
    uint16 TotalLength );

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
    uint32 Length );

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
    uint32 Length );

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
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) DestinationPtr );

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
    P2CONST(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) DestinationPtr );

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
    uint32 Length );
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
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_Close(
    TcpIp_SocketIdType SocketId,
    boolean Abort );

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
    P2VAR(uint16, AUTOMATIC, TCPIP_APPL_VAR) PortPtr );

/***********************************************************************************************************************
 *  TcpIp_RequestIpAddrAssignment
 **********************************************************************************************************************/
/*! \brief        Initiate the local IP address assignment for the IP address specified by LocalAddrId.
 *  \param[in]    LocalAddrId         IP address index specifying the IP address for which an
 *                                    assignment shall be initiated.
 *  \param[in]    Type                type of IP address assignment which shall be initiated
 *  \param[in]    LocalIpAddrPtr      pointer to structure containing the IP address which shall be
 *                                    assigned to the EthIf controller indirectly specified via
 *                                    LocalAddrId. Note: This parameter is only used in case the
 *                                    parameters Type is set to TCPIP_IPADDR_ASSIGNMENT_STATIC.
 *  \param[in]    Netmask             Network mask of IPv4 address or address prefix of IPv6 address in CIDR Notation.
 *  \param[in]    DefaultRouterPtr    Pointer to struct where the IP address of the default router
 *                                    (gateway) is stored (struct member 'port' is not used and of
 *                                    arbitrary value) (IPv4 only)
 *  \return       E_OK                The request has been accepted <br>
 *                E_NOT_OK            The request has not been accepted
 *  \context      task level
 *  \trace        SPEC-66293, SPEC-66335
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_RequestIpAddrAssignment(
    TcpIp_LocalAddrIdType LocalAddrId,
    TcpIp_IpAddrAssignmentType Type,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_VAR) LocalIpAddrPtr,
    uint8 Netmask,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_VAR) DefaultRouterPtr );

/***********************************************************************************************************************
 *  TcpIp_ReleaseIpAddrAssignment
 **********************************************************************************************************************/
/*! \brief        Release the local IP address assignment for the IP address specified by LocalAddrId.
 *  \param[in]    LocalAddrId         IP address index specifying the IP address for which an
 *                                    assignment shall be released.
 *  \return       E_OK                The request has been accepted <br>
 *                E_NOT_OK            The request has not been accepted
 *  \context      task level
 *  \trace        SPEC-66313
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_ReleaseIpAddrAssignment(
    TcpIp_LocalAddrIdType LocalAddrId );

/***********************************************************************************************************************
 *  TcpIp_ReleaseSpecificIpAddrAssignment
 **********************************************************************************************************************/
/*! \brief        Release the local IP address assignment of a specific type for an IP address.
 *  \param[in]    localAddrId         IP address identifier of the IP address for which the assignment shall be released.
 *  \param[in]    assignmentType      Type of assignment that shall be released (e.g.: STATIC, LINKLOCAL, DHCP, ROUTER).
 *  \return       E_OK                The assignment could be released.
 *  \return       E_NOT_OK            The assignment could not be released.
 *  \note         This API is a Vector extension to the AUTOSAR API (TcpIp_ReleaseIpAddrAssignment).
 *  \context      TASK
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_ReleaseSpecificIpAddrAssignment (
    TcpIp_LocalAddrIdType      localAddrId,
    TcpIp_IpAddrAssignmentType assignmentType);

/***********************************************************************************************************************
 *  TcpIp_GetPhysAddr
 **********************************************************************************************************************/
/*! \brief        Obtains the physical source address used by the EthIf controller implicitly specified via LocalAddrId.
 *  \param[in]    LocalAddrId        Local address identifier implicitely specifing the EthIf controller for which the
 *                                   physical address shall be obtained.
 *  \param[out]   PhysAddrPtr        Pointer to the memory where the physical source address (MAC address) in network
 *                                   byte order is stored
 *  \return       E_OK               The request was successful <br>
 *                E_NOT_OK           The request was not successful, e.g. no unique Ctrl specified via IpAddrId.
 *  \context      task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetPhysAddr(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) PhysAddrPtr );

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
 **********************************************************************************************************************/
FUNC(TcpIp_ReturnType, TCPIP_CODE) TcpIp_GetRemotePhysAddr(
    uint8 CtrlIdx,
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_VAR) IpAddrPtr,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) PhysAddrPtr,
    boolean initRes);

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
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) CtrlIdxPtr );  /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */

#ifdef TCPIP_DECLARE_OWN_MAINFUNCTION
/***********************************************************************************************************************
 *  TcpIp_MainFunction
 **********************************************************************************************************************/
/*! \brief       MainFunction that calls RX, State and TX MainFunctions of the module. 
 *  \details     This function is a wrapper for the RX, TX and state specific MainFunctions of the module that may be 
 *               used instead of calling the specific MainFunctions separately.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        If this function is called, the specific RX, TX and State MainFunctions MUST NOT be called directly.
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_MainFunction(void);

/***********************************************************************************************************************
 *  TcpIp_MainFunctionRx
 **********************************************************************************************************************/
/*! \brief       MainFunction that processes all received data and forwards information to upper layers.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        If this function is called, the TX and State MainFunctions MUST be called as well and MainFunction MUST not be called.
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_MainFunctionRx(void);

/***********************************************************************************************************************
 *  TcpIp_MainFunctionTx
 **********************************************************************************************************************/
/*! \brief       MainFunction that processes all pending transmit requests from the upper layers and transmits the data.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        If this function is called, the RX and State MainFunctions MUST be called as well and MainFunction MUST not be called.
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_MainFunctionTx(void);

/***********************************************************************************************************************
 *  TcpIp_MainFunctionState
 **********************************************************************************************************************/
/*! \brief       MainFunction that performs all state and timing secific actions.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        If this function is called, the RX and TX MainFunctions MUST be called as well and MainFunction MUST not be called.
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_MainFunctionState(void);
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
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) ParameterValue );

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
    uint16 KeyLen );

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
    P2VAR(NvM_BlockIdType, AUTOMATIC, TCPIP_APPL_DATA) RootCertBlockIdPtr );

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
    NvM_BlockIdType NvmBlockId );
#endif  /* (TCPIP_SUPPORT_TLS == STD_ON) */

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_GetLocNetAddr
 **********************************************************************************************************************/
/*! \brief      This function returns the current IP address for a given controller
 *  \param[in]  LocalAddrId           local address identifier
 *  \param[out] NetAddrPtr            pointer for the local network address
 *  \return     E_OK                  local network address returned <br>
 *              E_NOT_OK              local network address access failed
 *  \note       This API is deprecated and will be removed in future revisions of this module.
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetLocNetAddr(
    TcpIp_LocalAddrIdType                                LocalAddrId,
    P2VAR(TcpIp_NetAddrType, AUTOMATIC, TCPIP_APPL_DATA) NetAddrPtr );

/***********************************************************************************************************************
 *  TcpIp_GetLocNetMask
 **********************************************************************************************************************/
/*! \brief      This function returns the current network mask for a given controller
 *  \param[in]  LocalAddrId           local address identifier
 *  \param[out] NetMaskPtr            pointer for the local network mask
 *  \return     E_OK                  local network mask returned <br>
 *              E_NOT_OK              local network mask access failed
 *  \note       This API is deprecated and will be removed in future revisions of this module.
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetLocNetMask(
    TcpIp_LocalAddrIdType                                LocalAddrId,
    P2VAR(TcpIp_NetAddrType, AUTOMATIC, TCPIP_APPL_DATA) NetMaskPtr );
#endif

/***********************************************************************************************************************
 *  TcpIp_GetIpAddr
 **********************************************************************************************************************/
/*! \brief      Obtains the local IP address actually used by LocalAddrId, the netmask and default router
 *  \param[in]  LocalAddrId           local address identifier
 *  \param[out] IpAddrPtr             Pointer to a struct where the IP address is stored.
 *                                    (only struct members family and address will be updated)
 *  \param[out] NetmaskPtr            Pointer to memory where Network mask of IPv4 address or address prefix of IPv6
 *                                    address in CIDR notation is stored.
 *  \param[out] DefaultRouterPtr      Pointer to struct where the IP address of the default router (gateway) is stored
 *                                    (only struct members family and address will be updated)
 *  \return     E_OK                  The request was successful <br>
 *              E_NOT_OK              The request was not successful.
 *  \note       The output parameters IpAddrPtr, NetmaskPtr, DefaultRouterPtr may be set to NULL_PTR if the information
 *                                    is not required.
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_GetIpAddr(
  TcpIp_LocalAddrIdType LocalAddrId,
  TCPIP_P2V(TcpIp_SockAddrType) IpAddrPtr,
  TCPIP_P2V(uint8)               NetmaskPtr,
  TCPIP_P2V(TcpIp_SockAddrType) DefaultRouterPtr);

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
  TCPIP_P2V(TcpIp_SockAddrType) *SockAddrPtr);

/***********************************************************************************************************************
 *  TcpIp_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief      Get Tcp/Ip Version
 *  \param[in]  versioninfo           pointer for version information
 *  \return     void
 *  \context    task level
 *  \note       The module version is given decimal coded.
 *  \trace      CREQ-111952
 **********************************************************************************************************************/
#if ( TCPIP_VERSION_INFO_API == STD_ON )
FUNC(void, TCPIP_CODE) TcpIp_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, TCPIP_APPL_DATA) versioninfo);
#endif
  /* TCPIP_VERSION_INFO_API == STD_ON */

#if (TCPIP_SUPPORT_DHCPV4 == STD_ON)
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
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpReadOption(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint8 Option,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataLength,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr );

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
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpWriteOption(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint8 Option,
    uint8 DataLength,
    P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr );
# endif
#endif  /* TCPIP_SUPPORT_DHCPV4 == STD_ON */

#if (TCPIP_SUPPORT_DHCPV6 == STD_ON)
# if ((TCPIP_DHCPV6_SUPPORT_OPTIONS == STD_ON) && (TCPIP_DHCPV6_TX_OPTION_CNT > 0))  /* PRQA S 3332 */ /* MD_TCPIP_19.11_3332 */
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
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6ReadOption(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint16 Option,
    P2VAR(uint16, AUTOMATIC, TCPIP_APPL_DATA) DataLength,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr );

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
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DhcpV6WriteOption(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint16 Option,
    uint16 DataLength,
    P2CONST(uint8, AUTOMATIC, TCPIP_APPL_DATA) DataPtr );
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
    uint8 CtrlIdx,
    uint8 IpVer );

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
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) CfgSrcPtr);

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
    uint8            CtrlIdx,
    TcpIp_StateType  State);

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
    P2VAR(TcpIp_SockAddrType, AUTOMATIC, TCPIP_APPL_VAR) SockPtr);

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
    P2VAR(uint16, AUTOMATIC, TCPIP_APPL_VAR) DataLenPtr );
#endif

#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif
  /* TCPIP_H */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp.h
 *********************************************************************************************************************/
