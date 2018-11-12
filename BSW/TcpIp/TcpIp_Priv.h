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
 *         \file  TcpIp_Priv.h
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

#if !defined TCPIP_PRIV_H  /* PRQA S 0883 */ /* MD_TCPIP_19.15_0883 */
# define TCPIP_PRIV_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "TcpIp_Priv_Types.h"

#include "TcpIp_Cfg.h"
#if (TCPIP_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
#include "TcpIp_Lcfg.h"
#include "SchM_TcpIp.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TCPIP_SOCK_CONN_NONE                0u
#define TCPIP_SOCK_CONN_ALLOCATED           1u
#define TCPIP_SOCK_CONN_LISTEN_ENABLED      2u
#if(TCPIP_SUPPORT_TCP == STD_ON)
# define TCPIP_SOCK_CONN_CONNECTED          3u
#endif

#define TCPIP_DUMMY_ASM_NOP    /* empty define */

#define TCPIP_ACTIVE_STATE_OFFLINE          0u  /* module is offline / not initialized */
#define TCPIP_ACTIVE_STATE_IN_SHUTDOWN      1u  /* module is shutting down, all sockets are about to beeing closed */
#define TCPIP_ACTIVE_STATE_ONLINE           2u  /* module is initialized and ready for communication (if an IP address is available) */

/* Ethernet frame types */
#define TCPIP_ETH_FRAME_TYPE_IPV4      0x0800U
#define TCPIP_ETH_FRAME_TYPE_ARP       0x0806U
#define TCPIP_ETH_FRAME_TYPE_IPV6      0x86DDU

#ifdef TCPIP_PROCESSOR_CANOEEMU
  #define TCPIP_VENABLE_CANOE_WRITE_STRING            STD_OFF
#else
  #define TCPIP_VENABLE_CANOE_WRITE_STRING            STD_OFF
#endif

#define TCPIP_API_ID_V_INTERNAL_FUNCTION              0xFFu

#define TCPIP_DHCPV4_MULTIPLE_CONFIG_SETS STD_ON
#define TCPIP_DHCPV4_MULTIPLE_INSTANCES STD_ON

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#ifdef TCPIP_PROCESSOR_CANOEEMU
#if (TCPIP_VENABLE_CANOE_WRITE_STRING == STD_ON)
  #include "stdio.h"
  #define CANOE_WRITE_STRING(Txt)                 CANoeAPI_WriteString((Txt));
  #define CANOE_WRITE_STRING_1(Txt, P1)           \
    _snprintf(TcpIp_CanoeWriteStr, 256, Txt, P1); CANoeAPI_WriteString((TcpIp_CanoeWriteStr));
  #define CANOE_WRITE_STRING_2(Txt, P1, P2)       \
    _snprintf(TcpIp_CanoeWriteStr, 256, Txt, P1, P2); \
    CANoeAPI_WriteString((TcpIp_CanoeWriteStr));
  #define CANOE_WRITE_STRING_3(Txt, P1, P2, P3)   \
    _snprintf(TcpIp_CanoeWriteStr, 256, Txt, P1, P2, P3); \
    CANoeAPI_WriteString((TcpIp_CanoeWriteStr));
  #define CANOE_WRITE_STRING_4(Txt, P1, P2, P3, P4)   \
    _snprintf(TcpIp_CanoeWriteStr, 256, Txt, P1, P2, P3, P4); \
    CANoeAPI_WriteString((TcpIp_CanoeWriteStr));
#else
  #define CANOE_WRITE_STRING(txt)
  #define CANOE_WRITE_STRING_1(txt, p1)
  #define CANOE_WRITE_STRING_2(txt, p1, p2)
  #define CANOE_WRITE_STRING_3(txt, p1, p2, p3)
  #define CANOE_WRITE_STRING_4(txt, p1, p2, p3, p4)
#endif
  /* X_VENABLE_CANOE_WRITE_STRING */
#else
  #define CANOE_WRITE_STRING(txt)
  #define CANOE_WRITE_STRING_1(txt, p1)
  #define CANOE_WRITE_STRING_2(txt, p1, p2)
  #define CANOE_WRITE_STRING_3(txt, p1, p2, p3)
  #define CANOE_WRITE_STRING_4(txt, p1, p2, p3, p4)
#endif

#define TCPIP_VENTER_CRITICAL_SECTION() SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_0()
#define TCPIP_VLEAVE_CRITICAL_SECTION() SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_0()

#define TCPIP_SOCKHND2SOCKIDX(SockHnd)  ((TcpIp_SockIdxType)(SockHnd))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_SOCKHND2TCPIDX(SockHnd)   ((TcpIp_TcpIdxType)((TcpIp_SockIdxType)(SockHnd) - ((TcpIp_SockIdxType)(TcpIp_VCfgGetMaxNumUdpSocks()))))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_SOCKIDX2TCPIDX(SockIdx)   ((TcpIp_TcpIdxType)((SockIdx) - (TcpIp_VCfgGetMaxNumUdpSocks())))  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* PRQA S 3382 */ /* MD_TCPIP_21.1_3382 */

#define TCPIP_SOCKIDX2SOCKHND(SockIdx)  ((TcpIp_SockHndType)(SockIdx))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_TCPIDX2SOCKHND(TcpIdx)    ((TcpIp_SockHndType)((TcpIdx) + (TcpIp_VCfgGetMaxNumUdpSocks())))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_TCPIDX2SOCKIDX(TcpIdx)    ((TcpIp_SockIdxType)((TcpIdx) + (TcpIp_VCfgGetMaxNumUdpSocks())))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(LOCAL_ADDR_ID)       (LOCAL_ADDR_ID)  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(LOCAL_ADDR_ID)      (TcpIp_LocalAddrIdType)((LOCAL_ADDR_ID) - (TcpIp_LocalAddrIdType)TCPIP_MAX_NUM_IPV4_ADDR_IDS)  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_LOCAL_ADDR_ID_2_IPVX_ID(LOCAL_ADDR_ID)      ((TcpIp_LocalAddrIdType)(TCPIP_LOCAL_ADDR_IS_AF_INET(LOCAL_ADDR_ID) ? TCPIP_LOCAL_ADDR_ID_2_IPV4_ID(LOCAL_ADDR_ID) : TCPIP_LOCAL_ADDR_ID_2_IPV6_ID(LOCAL_ADDR_ID)))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define TCPIP_LOCAL_ADDR_IS_AF_INET(LOCAL_ADDR_ID)        ((LOCAL_ADDR_ID) <  TCPIP_MAX_NUM_IPV4_ADDR_IDS)  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_LOCAL_ADDR_IS_AF_INET6(LOCAL_ADDR_ID)      (((LOCAL_ADDR_ID) >= TCPIP_MAX_NUM_IPV4_ADDR_IDS) && TCPIP_COND_VALID_LOCALADDRID(LOCAL_ADDR_ID))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define TCPIP_GET_LOCAL_ADDR_FAMILY(LOCAL_ADDR_ID)       (TCPIP_LOCAL_ADDR_IS_AF_INET(LOCAL_ADDR_ID) ? IPBASE_AF_INET : IPBASE_AF_INET6)  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define TCPIP_GET_NEXT_DYNAMIC_PORT(COUNTER_VAR)         ((uint16)((COUNTER_VAR)++ | 0xC000u))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* TcpIp TxBuf */
#define TcpIp_IncTxBufIdx(SockIdx, Idx, Num)  ((Idx) = (((Idx) +(Num)) % (TcpIp_VCfgGetTxBufSizeByte(TCPIP_SOCKIDX2TCPIDX(SockIdx)))))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define TcpIp_DecTxBufIdx(SockIdx, Idx, Num)  (Idx) = (((Idx) + (TcpIp_VCfgGetTxBufSizeByte(TCPIP_SOCKIDX2TCPIDX(SockIdx)))) - (Num)) % (TcpIp_VCfgGetTxBufSizeByte(TCPIP_SOCKIDX2TCPIDX(SockIdx)))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* ------------------------------------------------- */
/* ------------------------------------------------- */

#if !defined(TCPIP_VENABLE_INTERNAL_DET_CHECKS)
# define TCPIP_VENABLE_INTERNAL_DET_CHECKS STD_OFF
#endif

#if (TCPIP_ENABLE_DLISTS == STD_ON)

# define TCPIP_DLIST_GET_NEXT(NodeIdx, DList) ((DList).DescPtr->NodePtr[(NodeIdx)].NextIdx)  /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define TCPIP_DLIST_GET_PREV(NodeIdx, DList) ((DList).DescPtr->NodePtr[(NodeIdx)].PrevIdx)  /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define TCPIP_DLIST_SET_NEXT(NodeIdx, DList) ((NodeIdx) = TCPIP_DLIST_GET_NEXT(NodeIdx, DList))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define TCPIP_DLIST_SET_PREV(NodeIdx, DList) ((NodeIdx) = TCPIP_DLIST_GET_PREV(NodeIdx, DList))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define TCPIP_DLIST_IS_EMPTY(DList)           (TCPIP_DLIST_END_IDX == (DList).FirstIdx)  /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define TCPIP_DLIST_END_IDX 0xFF

#endif

/* ------------------------------------------------- */
/* ------------------------------------------------- */

/* TCP */

/* RAM array access macros: */

/* TxRstQueue */
#define TcpIp_Tcp_IncTxRstQueueIdx(Idx)  ((Idx) = (uint8)(((Idx) +1) % (TcpIp_Tcp_VCfgGetTxRstQueueSize())))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* RxBuffers */
#define TcpIp_Tcp_GetRxBuffersElemPtr(TcpIdx, Idx)  (&(TcpIp_Tcp_RxBuffer[TcpIp_Tcp_Socket_AssignedRxBufferIndex[TcpIdx]])[Idx])  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* RxPreBufArray */
#define TcpIp_Tcp_GetRxPreBufArrayElemPtr(TcpIdx, Idx)  (&(TcpIp_Tcp_RxPreBufArray[ ((TcpIdx) * (TcpIp_Tcp_VCfgGetMaxNumOooSegments())) + (Idx)]))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define TcpIp_GetTxBuffersElemPtr(SockIdx, Idx)    (&(TcpIp_Tcp_TxBuffer[TcpIp_Tcp_Socket_AssignedTxBufferIndex[TCPIP_SOCKIDX2TCPIDX(SockIdx)]])[Idx])  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* ------------------------------------------------- */
/* ------------------------------------------------- */

/* Development Error Tracer */
#if ( TCPIP_DEV_ERROR_REPORT == STD_ON )
# define TcpIp_CheckDetErrorReturnVoid(  CONDITION, API_ID, ERROR_CODE )           { if(!(CONDITION)) {    \
    (void)Det_ReportError( TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, (API_ID), (ERROR_CODE)); return; } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define TcpIp_CheckDetErrorReturnValue( CONDITION, API_ID, ERROR_CODE, RET_VAL )  { if(!(CONDITION)) {    \
    (void)Det_ReportError( TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, (API_ID), (ERROR_CODE)); return (RET_VAL); } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define TcpIp_CheckDetErrorContinue(    CONDITION, API_ID, ERROR_CODE )           { if(!(CONDITION)) {    \
    (void)Det_ReportError( TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, (API_ID), (ERROR_CODE)); } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define TcpIp_CallDetReportError( API_ID, ERROR_CODE )  { \
    (void)Det_ReportError( TCPIP_MODULE_ID, TCPIP_VINSTANCE_ID, (API_ID), (ERROR_CODE)); }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
#else
# define TcpIp_CheckDetErrorReturnVoid(  CONDITION, API_ID, ERROR_CODE )
# define TcpIp_CheckDetErrorReturnValue( CONDITION, API_ID, ERROR_CODE, RET_VAL )
# define TcpIp_CheckDetErrorContinue(    CONDITION, API_ID, ERROR_CODE )
# define TcpIp_CallDetReportError(                  API_ID, ERROR_CODE )
#endif  /* TCPIP_DEV_ERROR_REPORT */

/* CHECK CONDITIONS: */
#define TCPIP_COND_INIT                     ( TCPIP_STATE_INIT == TcpIp_State )  /* TCPIP_E_NOTINIT */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_VALID_SOCKHND(SockHnd)   ( ((TcpIp_SockHndType)(TcpIp_VCfgGetMaxNumSocks()) > (SockHnd)) )  /* TCPIP_E_INV_SOCK_ID */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_VALID_IPADDR(IpAddr)     ( (0 != (IpAddr)) )                      /* TCPIP_E_INV_ARG */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_VALID_SOCKET_ID(SocketId)   ((TcpIp_SocketIdType)(TcpIp_VCfgGetMaxNumSocks()) > (SocketId))  /* TCPIP_E_INV_SOCK_ID */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_VALID_SOCKIDX(SockIdx)   ( (TcpIp_VCfgGetMaxNumSocks() > (SockIdx)) )  /* TCPIP_E_INV_SOCK_ID */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_VALID_TCPSOCKIDX(SockIdx)  ( (TcpIp_VCfgGetMaxNumSocks() > (SockIdx)) && \
                                              (TcpIp_VCfgGetMaxNumUdpSocks() <= (SockIdx)) )  /* TCPIP_E_INV_SOCK_ID */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_VALID_UDPSOCKIDX(SockIdx)  (TcpIp_VCfgGetMaxNumUdpSocks() > (SockIdx))  /* TCPIP_E_INV_SOCK_ID */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_VALID_PTR(Pointer)       ( NULL_PTR != (Pointer) )                /* TCPIP_E_PARAM_POINTER */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_MIN_SIZE(Value, Ref)     ( (Value) >= (Ref) )                     /* TCPIP_E_INV_ARG */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_PBUF_LEN(PbufPtr)        ( (NULL_PTR != (PbufPtr)->payload) && \
                                              (0 != (PbufPtr)->totLen) && \
                                              ((PbufPtr)->totLen >= (PbufPtr)->len) )      /* TCPIP_E_INV_ARG */  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define TCPIP_COND_VALID_LOCALADDRID(LocalAddrId)        ( TcpIp_VCfgGetMaxLocalAddrId() >= (LocalAddrId) )  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TCPIP_COND_VALID_OR_ANY_LOCALADDRID(LocalAddrId) ( (TCPIP_LOCALADDRID_ANY == (LocalAddrId)) || TCPIP_COND_VALID_LOCALADDRID(LocalAddrId) )  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define TCPIP_IPADDR_ASSIGNMENT_MAX_VALUE  TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER

#if (TCPIP_SUPPORT_IPV4 == STD_ON)
# if (TCPIP_SUPPORT_IPV6 == STD_ON)
/* IPV4 and IPV6 are enabled */
#define TCPIP_COND_VALID_ADDR_FAM(SockAddrPtr)   ( (((IpBase_SockAddrType*)(SockAddrPtr))->sa_family == IPBASE_AF_INET6) || \
                                                   (((IpBase_SockAddrType*)(SockAddrPtr))->sa_family == IPBASE_AF_INET) )  /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
/* only IPV4 is enabled */
#define TCPIP_COND_VALID_ADDR_FAM(SockAddrPtr)   ( ((IpBase_SockAddrType*)(SockAddrPtr))->sa_family == IPBASE_AF_INET )  /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif
#else
/* only IPV6 is enabled */
#define TCPIP_COND_VALID_ADDR_FAM(SockAddrPtr)   ( ((IpBase_SockAddrType*)(SockAddrPtr))->sa_family == IPBASE_AF_INET6 )  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/* implementation limit: max message length is 64kB */
#define TCPIP_COND_LEN_MAX_UINT16(Len)      ( (uint32)(Len) <= (uint32)0xFFFF )        /* TCPIP_E_INV_ARG */  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define TCPIP_COND_VALID_DOMAIN(Domain)      ( (IPBASE_AF_INET == (Domain)) || \
                                               (IPBASE_AF_INET6 == (Domain)))          /* TCPIP_E_INV_ARG */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#if (TCPIP_SUPPORT_TCP == STD_ON)
#define TCPIP_COND_VALID_PROT(Prot)          ( (TCPIP_SOCK_PROT_UDP == (Prot)) || \
                                               (TCPIP_SOCK_PROT_TCP == (Prot)) )       /* TCPIP_E_INV_ARG */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
#define TCPIP_COND_VALID_PROT(Prot)          ( TCPIP_SOCK_PROT_UDP == (Prot) )         /* TCPIP_E_INV_ARG */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif
#define TCPIP_TCP_COND_VALID_TCPIDX(TcpIdx)   ( (TCPIP_TCP_INV_IDX != (TcpIdx)) && \
                                          (TcpIp_VCfgGetMaxNumTcpSocks() > (TcpIdx)) )  /* TCPIP_E_INV_SOCK_ID */  /* PRQA S 3453 */ /* MD_MSR_19.7 */

#if (TCPIP_USE_DUMMY_STATEMENT == STD_ON)
# define TCPIP_UNUSED_PARAMETER(Parameter) TCPIP_DUMMY_STATEMENT(Parameter)  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
# define TCPIP_UNUSED_PARAMETER(Parameter)
#endif

#define TCPIP_ASSERT(CONDITION)            TCPIP_ASSERT_MSG(CONDITION, NULL_PTR) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#if defined(TCPIP_ASSERT_HANDLER)
# define TCPIP_ASSERT_MSG(CONDITION, MSG)  (void)TCPIP_ASSERT_HANDLER(CONDITION, MSG)
#else
# define TCPIP_ASSERT_MSG(CONDITION, MSG)
#endif

#define TCPIP_CYCLES_PER_SECOND             (1000 / TCPIP_MAIN_FCT_PERIOD_MSEC)
#define TCPIP_MAX_SEC_IN_UINT32_CYCLE_VAR   (0xFFFFFFFFu / TCPIP_CYCLES_PER_SECOND)

/* ------------------------------------------------- */
/* ------------------------------------------------- */
/* Configuration access (depending on configuration variant)*/
#define TcpIp_VCfgGetMaxNumUdpSocks()       (TCPIP_MAX_NUM_UDP_SOCKETS)
#define TcpIp_VCfgGetMaxNumTcpSocks()       (TCPIP_MAX_NUM_TCP_SOCKETS)
#define TcpIp_VCfgGetMaxNumSocks()          (TCPIP_MAX_NUM_SOCKETS)
#define TcpIp_VCfgGetMainFctPeriodMsec()    (TCPIP_MAIN_FCT_PERIOD_MSEC)
#define TcpIp_VCfgGetMaxLocalAddrId()       (TCPIP_MAX_LOCAL_ADDR_ID)

#define TcpIp_VCfgGetSockMode()             (TcpIp_Cfg_SockMode)
#define TcpIp_VCfgGetUserIdx()              (TcpIp_SockUserIdx)  /* (TcpIp_CfgUserIdx) */
#define TcpIp_VCfgGetTxBufSizeByte(TcpIdx)        (TcpIp_Tcp_TxBufferSize[TcpIp_Tcp_Socket_AssignedTxBufferIndex[TcpIdx]])  /* (TcpIp_TxBufSizeByte) */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TcpIp_VCfgGetTxBufSizeOffset()      (TcpIp_TxBufSizeOffset)

#define TcpIp_VCfgGetNumSocketOwners()      (TCPIP_NUM_SOCKET_OWNERS)

#if (TCPIP_UDP_TXCONFIRMATION_ENABLED == STD_ON)
#define TcpIp_VCfgGetUdpTxReqListNum()      (TCPIP_UDP_TX_REQ_LIST_NUM)
#endif

#define TcpIp_VCfgGetLocalIpAssignmentChgFuncCount() (TCPIP_LOCAL_IP_ADDR_ASSIGNMENT_CHG_CBK_CNT)
#define TcpIp_VCfgGetPhysAddrTableChgFuncCount()     (TCPIP_PHYS_ADDR_TABLE_CHG_FUNCTION_CNT)

/* DHCP */
/* Configuration access (depending on configuration variant)*/

#define TcpIp_DhcpV4_VCfgGetSockHnd()                       (IPV4_DHCP_TX_SOCKET_IDX)

#if (TCPIP_DHCPV4_MULTIPLE_CONFIG_SETS == STD_ON)
# define TcpIp_DhcpV4_VCfgGetInitWaitMinMsec()              (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->InitWaitMin)
# define TcpIp_DhcpV4_VCfgGetInitWaitMaxMsec()              (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->InitWaitMax)
# define TcpIp_DhcpV4_VCfgGetDiscoverMaxNum()               (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->DiscoverMaxNum)
# define TcpIp_DhcpV4_VCfgGetRequestMaxNum()                (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->RequestMaxNum)
# define TcpIp_DhcpV4_VCfgGetDiscoverMinIntervalSec()       (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->DiscoverIntervalMin)
# define TcpIp_DhcpV4_VCfgGetDiscoverMaxIntervalSec()       (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->DiscoverIntervalMax)
# define TcpIp_DhcpV4_VCfgGetRequestIntervalSec()           (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->RequestInterval)
# define TcpIp_DhcpV4_VCfgGetRenewMinIntervalSec()          (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->RenewIntervalMin)
# define TcpIp_DhcpV4_VCfgGetRebindMinIntervalSec()         (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->RebindIntervalMin)
# define TcpIp_DhcpV4_VCfgGetHostNameLenMax()               (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->HostNameLenMax)
# define TcpIp_DhcpV4_VCfgGetRestartOnFail()                (TcpIp_DhcpV4_ConfigSets[IpCtrlIdx]->RestartOnFail)
#else
# define TcpIp_DhcpV4_VCfgGetInitWaitMinMsec()              (TCPIP_DHCPV4_INIT_WAIT_MIN_MSEC)
# define TcpIp_DhcpV4_VCfgGetInitWaitMaxMsec()              (TCPIP_DHCPV4_INIT_WAIT_MAX_MSEC)
# define TcpIp_DhcpV4_VCfgGetDiscoverMaxNum()               (TCPIP_DHCPV4_DISCOVER_MAX_NUM)
# define TcpIp_DhcpV4_VCfgGetRequestMaxNum()                (TCPIP_DHCPV4_REQUEST_MAX_NUM)
# define TcpIp_DhcpV4_VCfgGetDiscoverMinIntervalSec()       (TCPIP_DHCPV4_DISCOVER_MIN_INTERVAL_SEC)
# define TcpIp_DhcpV4_VCfgGetDiscoverMaxIntervalSec()       (TCPIP_DHCPV4_DISCOVER_MAX_INTERVAL_SEC)
# define TcpIp_DhcpV4_VCfgGetRequestIntervalSec()           (TCPIP_DHCPV4_REQUEST_INTERVAL_SEC)
# define TcpIp_DhcpV4_VCfgGetRenewMinIntervalSec()          (TCPIP_DHCPV4_RENEW_MIN_INTERVAL_SEC)
# define TcpIp_DhcpV4_VCfgGetRebindMinIntervalSec()         (TCPIP_DHCPV4_REBIND_MIN_INTERVAL_SEC)
# define TcpIp_DhcpV4_VCfgGetHostNameLenMax()               (TCPIP_DHCPV4_HOSTNAME_LEN_MAX)
# define TcpIp_DhcpV4_VCfgGetRestartOnFail()                (TCPIP_DHCPV4_RESTART_ON_FAIL)
#endif

/* TCP */
/* Configuration access (depending on configuration variant): */
#define TcpIp_Tcp_VCfgGetSocketIdxRstTx()               (TCPIP_TCP_SOCKET_IDX_RST_TX)
#define TcpIp_Tcp_VCfgGetTxRetrQueueSize()              (TCPIP_TCP_TX_RETR_QUEUE_SIZE)
#define TcpIp_Tcp_VCfgGetTxRstQueueSize()               (TCPIP_TCP_TX_RST_QUEUE_SIZE)
#define TcpIp_Tcp_VCfgGetMaxWindowSize(RxBufIdx)        (TcpIp_Tcp_RxBufferSize[RxBufIdx])  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define TcpIp_Tcp_VCfgGetMaxTxMsgSizeByte()             (TCPIP_TCP_MAX_TX_MSG_SIZE_BYTE)   /* EthPayload (1500) - IPv4Header (20) - TcpHeader (20) */
#define TcpIp_Tcp_VCfgGetMaxRxMsgSizeByte()             (TCPIP_TCP_MAX_RX_MSG_SIZE_BYTE)
#define TcpIp_Tcp_VCfgGetTxRetryIntMinCycles()          (TCPIP_TCP_TX_RETRY_INT_MIN_CYCLES)  /* retry interval */
#define TcpIp_Tcp_VCfgGetTxRetryIntMaxCycles()          (TCPIP_TCP_TX_RETRY_INT_MAX_CYCLES)  /* retry interval */
#define TcpIp_Tcp_VCfgGet2MslTimeoutCycles()            (TCPIP_TCP_2MSL_TIMEOUT_CYCLES)
#define TcpIp_Tcp_VCfgGetKeepAliveTimeoutDefCycles()    (TCPIP_TCP_KEEP_ALIVE_TIMEOUT_DEF_CYCLES)
#define TcpIp_Tcp_VCfgGetKeepAliveMaxProbesDef()        (TCPIP_TCP_KEEP_ALIVE_MAX_PROBE_DEF)
#define TcpIp_Tcp_VCfgGetKeepAliveIntervalDefCycles()   (TCPIP_TCP_KEEP_ALIVE_INTERVAL_DEF_CYCLES)
#define TcpIp_Tcp_VCfgGetNagleTimeoutCycles()           (TCPIP_TCP_NAGLE_TIMEOUT_CYCLES)
#define TcpIp_Tcp_VCfgGetUserTimeoutMinCycles()         (TCPIP_TCP_USER_TIMEOUT_MIN_CYCLES)
#define TcpIp_Tcp_VCfgGetUserTimeoutMaxCycles()         (TCPIP_TCP_USER_TIMEOUT_MAX_CYCLES)
#define TcpIp_Tcp_VCfgGetUserTimeoutDefCycles()         (TCPIP_TCP_USER_TIMEOUT_DEF_CYCLES)
#define TcpIp_Tcp_VCfgGetOooAvgNumSeg()                 (TCPIP_TCP_OOO_AVG_NUM_SEG_PER_SOCK)

/* UDP */
/* Configuration access (depending on configuration variant)*/

#define TcpIp_Udp_VCfgGetTxReqListSize(ListIdx)         (TcpIp_Udp_TxReqListSize[ListIdx])  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ----- */
#define TCPIP_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, TCPIP_VAR_NOINIT) TcpIp_ActiveState;

#if ( TCPIP_VENABLE_CANOE_WRITE_STRING == STD_ON )
extern VAR(sint8, TCPIP_VAR_NOINIT)                TcpIp_CanoeWriteStr[];
#endif
  /* TCPIP_VENABLE_CANOE_WRITE_STRING */

#define TCPIP_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ----- */
#define TCPIP_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if (TCPIP_SUPPORT_TCP == STD_ON)
extern VAR(uint16, TCPIP_VAR_NOINIT)               TcpIp_Tcp_DynamicPortCount;
# endif
extern VAR(uint16, TCPIP_VAR_NOINIT)               TcpIp_Udp_DynamicPortCount;

#define TCPIP_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ----- */
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#if (TCPIP_SUPPORT_IPV6 == STD_ON)
extern CONST(IpBase_AddrIn6Type, TCPIP_CONST) TcpIp_Ipv6NullAddr;  /* PRQA S 0759 */ /* MD_TCPIP_18.4_0759 */
#endif

#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define TCPIP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  TcpIp_VPreconfigSocket
 **********************************************************************************************************************/
/*! \brief      pre-configure socket
 *  \param[in]  SockIdx               socket index
 *  \context    initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE)  TcpIp_VPreconfigSocket(TcpIp_SockIdxType SockIdx);

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
    P2CONST(uint8, TCPIP_APPL_DATA, TCPIP_CONST) PhysAddrTwoPtr );

/***********************************************************************************************************************
 *  TcpIp_VRxUdpSockIdxIdent
 **********************************************************************************************************************/
/*! \brief       Identify incomming socket
 **********************************************************************************************************************/
FUNC(TcpIp_SockIdxType, TCPIP_CODE) TcpIp_VRxUdpSockIdxIdent(
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_CONST) RxSockLocAddrPtr,
    TcpIp_LocalAddrIdType                                LocalAddrId);

#if (TCPIP_SUPPORT_TCP == STD_ON)
/***********************************************************************************************************************
 *  TcpIp_VRxTcpSockIdxIdent
 **********************************************************************************************************************/
/*! \brief       Identify incomming socket
 **********************************************************************************************************************/
FUNC(TcpIp_SockIdxType, TCPIP_CODE) TcpIp_VRxTcpSockIdxIdent(
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_CONST) RxSockRemAddrPtr,
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_CONST) RxSockLocAddrPtr,
    TcpIp_LocalAddrIdType                                LocalAddrId);
#endif

/***********************************************************************************************************************
 *  TcpIp_SetLastSockError
 **********************************************************************************************************************/
/*! \brief       set last socket error
 *  \param[in]   Error                  error code
 *  \return      none
 *  \context     interrupt or task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_SetLastSockError(
  uint16 Error );

/***********************************************************************************************************************
 *  TcpIp_VInitSockets
 **********************************************************************************************************************/
/*! \brief       init of all sockets
 *  \context     initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE)TcpIp_VInitSockets(void);

/***********************************************************************************************************************
 *  TcpIp_VInitSocket
 **********************************************************************************************************************/
/*! \brief       init of one single socket
 *  \param[in]   SockIdx                socket index
 *  \context     initialization
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VInitSocket(
    TcpIp_SockIdxType SockIdx );

/***********************************************************************************************************************
 *  TcpIp_VInitTxSocket
 **********************************************************************************************************************/
/*! \brief       init some variables of a tx socket
 *  \param[in]   SockIdx                socket index
 *  \context     initialization / reset
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VInitTxSocket(TcpIp_SockIdxType SockIdx);

/***********************************************************************************************************************
 *  TcpIp_VDelSockAddrMapping
 **********************************************************************************************************************/
/*! \brief       delete socket address mapping
 *  \param[in]   SockIdx                socket index
 *  \context     task level
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VDelSockAddrMapping(TcpIp_SockIdxType SockIdx);

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
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockBPtr );

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
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockBPtr );

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
    P2CONST(IpBase_SockAddrType, AUTOMATIC, TCPIP_APPL_DATA) SockAddrPtr );

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
    CONST(uint8, AUTOMATIC) Protocol );

/**********************************************************************************************************************
 *  TcpIp_VPhysAddrTableChg()
 **********************************************************************************************************************/
/*! \brief      This API is called by the IpV4 or IpV6 in case of a change in the ARP/NDP table related to the
 *              controller specified by CtrlIdx.
 *  \param[in]  CtrlIdx     EthIf controller index of the related ARP/NDP table.
 *  \param[in]  IpAddrPtr   specifies the IP address of the changed ARP/NDP table entry
 *  \param[in]  PhysAddrPtr specifies the physical address of the changed ARP/NDP table entry
 *  \param[in]  Valid       specifies if the ARP/NDP table entry is added or changed (TRUE) or has been removed (FALSE)
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_VPhysAddrTableChg(
  uint8                         CtrlIdx,
  TCPIP_P2V(TcpIp_SockAddrType) IpAddrPtr,
  TCPIP_P2V(uint8)              PhysAddrPtr,
  boolean                       Valid);

FUNC(void, TCPIP_CODE) TcpIp_RxIndicationFunctions(
    uint8                         userIndex,
    TcpIp_SocketIdType            socketId,
    TCPIP_P2V(TcpIp_SockAddrType) remoteSockAddrPtr,
    TCPIP_P2V(uint8)              dataPtr, /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
    uint16                        dataLenByte);

FUNC(void, TCPIP_CODE) TcpIp_TxConfirmationFunctions(
    uint8                         userIndex,
    TcpIp_SocketIdType            socketId,
    uint16                        dataLenByte);

FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_TcpAcceptedFunctions(
    uint8                         userIndex,
    TcpIp_SocketIdType            socketId,
    TcpIp_SocketIdType            socketIdConnected,
    TCPIP_P2V(TcpIp_SockAddrType) remoteSockAddrPtr);

FUNC(void, TCPIP_CODE) TcpIp_TcpConnectedFunctions(
    uint8                         userIndex,
    TcpIp_SocketIdType            socketId);

FUNC(void, TCPIP_CODE) TcpIp_TcpIpEventFunctions(
    uint8                         userIndex,
    TcpIp_SocketIdType            socketId,
    IpBase_TcpIpEventType         eventType);

FUNC(BufReq_ReturnType, TCPIP_CODE) TcpIp_CopyTxDataFunctions(
    uint8                         userIndex,
    TcpIp_SocketIdType            socketId,
    TCPIP_P2V(uint8)              bufferPtr,    /* PRQA S 3673 */ /* MD_TCPIP_16.7_3673 */
    TCPIP_P2V(uint16)             bufferLenBytePtr);

FUNC(void, TCPIP_CODE) TcpIp_LocalIpAssignmentChgFunctions(
    TcpIp_LocalAddrIdType         ipAddrId,
    TcpIp_IpAddrStateType         addrState);

#if (TCPIP_ENABLE_DLISTS == STD_ON)

/* DList public functions */

/**********************************************************************************************************************
 *  TcpIp_DListInitDesc()
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListInitDesc(
  TCPIP_P2V(TcpIp_DListDescType)  DescPtr,
  TCPIP_P2V(TcpIp_DListNodeType)  NodePtr,
  uint8                         NodeCount);

/**********************************************************************************************************************
 *  TcpIp_DListInit()
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListInit(
  TCPIP_P2V(TcpIp_DListType)      ListPtr,
  TCPIP_P2V(TcpIp_DListDescType)  DescPtr);

/**********************************************************************************************************************
 *  TcpIp_DListDiff()
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DListDiff(
  TCPIP_P2V(TcpIp_DListType)      ListAPtr,
  TCPIP_P2V(TcpIp_DListType)      ListBPtr,
  TCPIP_P2V(TcpIp_DListType)      ListBothPtr);

/**********************************************************************************************************************
 *  TcpIp_DListAddElement()
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_DListAddElement(
  TCPIP_P2V(TcpIp_DListType)      DListPtr,
  TcpIp_DListIdxType             AfterIdx,
  TCPIP_P2V(TcpIp_DListIdxType)   NewIdxPtr);

/**********************************************************************************************************************
 *  TcpIp_DListRemoveElement()
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListRemoveElement(
  TCPIP_P2V(TcpIp_DListType)      DListPtr,
  TcpIp_DListIdxType             RemIdx);

/**********************************************************************************************************************
 *  TcpIp_DListRemoveElementRange()
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListRemoveElementRange(
  TCPIP_P2V(TcpIp_DListType)      DListPtr,
  TcpIp_DListIdxType             RemStartIdx,
  TcpIp_DListIdxType             RemEndIdx);

/**********************************************************************************************************************
 *  TcpIp_DListMoveElement()
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListMoveElement(
  TCPIP_P2V(TcpIp_DListType)      SrcListPtr,
  TcpIp_DListIdxType             SrcListIdx,
  TCPIP_P2V(TcpIp_DListType)      TgtListPtr,
  TcpIp_DListIdxType             TgtPrevIdx);

/**********************************************************************************************************************
 *  TcpIp_DListMoveElementRange()
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListMoveElementRange(
  TCPIP_P2V(TcpIp_DListType)      SrcListPtr,
  TcpIp_DListIdxType             SrcListStartIdx,
  TcpIp_DListIdxType             SrcListEndIdx,
  TCPIP_P2V(TcpIp_DListType)      TgtListPtr,
  TcpIp_DListIdxType             TgtPrevIdx);

/**********************************************************************************************************************
 *  TcpIp_DListClear()
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListClear(
  TCPIP_P2V(TcpIp_DListType)      DListPtr);

/**********************************************************************************************************************
 *  TcpIp_DListSwap()
 **********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_DListSwap(
  TCPIP_P2V(TcpIp_DListType)      ListAPtr,
  TCPIP_P2V(TcpIp_DListType)      ListBPtr);

#endif

#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif
  /* TCPIP_PRIV_H */
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Priv.h
 *********************************************************************************************************************/
