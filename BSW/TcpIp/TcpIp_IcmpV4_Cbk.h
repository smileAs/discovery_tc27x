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
 *         \file  TcpIp_IcmpV4_Cbk.h
 *        \brief  Implementation of Internet Control Message Protocol for IPv4 (ICMPv4) - Callback Header
 *
 *      \details  This file is part of the TcpIp IPv4 submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp IPv4 submodule. >> TcpIp_IpV4.h
 *********************************************************************************************************************/

#if !defined (IPV4_ICMP_CBK_H)
# define IPV4_ICMP_CBK_H

#include "TcpIp_Cfg.h"
#if (TCPIP_SUPPORT_IPV4 == STD_ON)

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

#include "TcpIp_IpV4_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define IPV4_START_SEC_CODE
#include "MemMap.h"
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
extern FUNC(void, IPV4_CODE) IpV4_Icmp_RxIndication(
    IpV4_AddrIdType   AddrId,
    IpBase_AddrInType RemNetAddr,
    P2VAR(uint8, AUTOMATIC, IPV4_APPL_DATA) DataPtr,
    uint16 LenByte );

/***********************************************************************************************************************
 *  IpV4_Icmp_Cbk_VAddrResTimeout
 **********************************************************************************************************************/
/*! \brief      Address resolution timout Callback
 *  \param[in]  IpCtrlIdx               controller index
 *  \param[in]  DestAddrPtr           Pointer to destination address
 *  \context    interrupt or task level
 *  \note       The address resolution for the given address timed out on the given controller, after the address
 *              resolution request was accepted earlier.
 **********************************************************************************************************************/
extern FUNC(void, IPV4_CODE) IpV4_Icmp_Cbk_VAddrResTimeout(
  uint8 IpCtrlIdx,
  P2CONST(IpBase_SockAddrType, AUTOMATIC, IPV4_APPL_DATA) DestAddrPtr );

/***********************************************************************************************************************
 *  IpV4_Icmp_StoreChecksumInHeader
 **********************************************************************************************************************/
/*! \brief       Stores a calculated ICMP checksum value at the correct position into the ICMP header.
 *  \param[in]   Checksum              Finalized checksum value.
 *  \param[in]   IcmpHdrPtr            Pointer the location of the ICMP header.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Icmp_StoreChecksumInHeader(
    uint16          Checksum,
    IPV4_P2V(uint8) IcmpHdrPtr);

/***********************************************************************************************************************
 *  IpV4_Icmp_VLocalIpAddrAssignmentChange()
 **********************************************************************************************************************/
extern FUNC(void, IPV4_CODE) IpV4_Icmp_VLocalIpAddrAssignmentChange(
  IpV4_AddrIdType       IpAddrId,
  TcpIp_IpAddrStateType State);

#define IPV4_STOP_SEC_CODE
#include "MemMap.h"

#endif  /* (TCPIP_SUPPORT_IPV4 == STD_ON) */
#endif  /* IPV4_ICMP_CBK_H */
/**********************************************************************************************************************
 *  END OF FILE: IPV4_Icmp_Cbk.h
 *********************************************************************************************************************/
