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
 *         File:  SoAd_Priv.h
 *      Project:  TcpIp-Stack
 *       Module:  Socket Adapter
 *    Generator:  If_AsrIfSoAd.dll
 *
 *  Description:  private header
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/


#if !defined(SOAD_PRIV_H)
#define SOAD_PRIV_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SoAd_Types.h"
#include "SoAd_Cfg.h"
#include "SoAd_Lcfg.h"
#include "SchM_SoAd.h"
#if ( defined(SOAD_DEV_ERROR_REPORT) && (STD_ON == SOAD_DEV_ERROR_REPORT) )
# include "Det.h"
#endif /* defined(SOAD_DEV_ERROR_REPORT) && (STD_ON == SOAD_DEV_ERROR_REPORT) */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SOAD_INSTANCE_ID                  0u

/**********************************************************************************************************************
 * DATA TYPE MACROS
 *********************************************************************************************************************/
/* PRQA S 3453,3458 FCT_LIKE_MACROS */ /* MD_MSR_19.4, MD_MSR_19.7 */
#define SOAD_A_P2VAR(Type)                (P2VAR(Type, AUTOMATIC, AUTOMATIC))
#define SOAD_A_P2CONST(Type)              (P2CONST(Type, AUTOMATIC, AUTOMATIC))

#define SOAD_D_P2VAR(Type)                (P2VAR(Type, AUTOMATIC, SOAD_APPL_DATA))
#define SOAD_D_P2CONST(Type)              (P2CONST(Type, AUTOMATIC, SOAD_APPL_DATA))

#define SOAD_V_P2VAR(Type)                (P2VAR(Type, AUTOMATIC, SOAD_APPL_VAR))
#define SOAD_V_P2CONST(Type)              (P2CONST(Type, AUTOMATIC, SOAD_APPL_VAR))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# define SOAD_BEGIN_CRITICAL_SECTION() \
  { \
    if ( 0xFFu > SoAd_CriticalSectionCount) \
    { \
      if ( 0u == SoAd_CriticalSectionCount ) \
      { \
        SchM_Enter_SoAd_SOAD_EXCLUSIVE_AREA_0(); \
      } \
      SoAd_CriticalSectionCount++; \
    } \
    else \
    { \
      SOAD_CallDetReportError(SOAD_API_ID_BEGIN_CRITICAL_SECTION, SOAD_E_OVERFLOW); \
    } \
  }
# define SOAD_END_CRITICAL_SECTION() \
  { \
    if ( 0x00u < SoAd_CriticalSectionCount) \
    { \
      if ( 1u == SoAd_CriticalSectionCount ) \
      { \
        SchM_Exit_SoAd_SOAD_EXCLUSIVE_AREA_0(); \
      } \
      SoAd_CriticalSectionCount--; \
    } \
    else \
    { \
      SOAD_CallDetReportError(SOAD_API_ID_END_CRITICAL_SECTION, SOAD_E_OVERFLOW); \
    } \
  }

#define SOAD_DUMMY_STATEMENT_TYPE_VOID  0u
#define SOAD_DUMMY_STATEMENT_TYPE_VAR   1u

#if ( !defined(SOAD_DUMMY_STATEMENT_TYPE) )
# define SOAD_DUMMY_STATEMENT_VAR(v)    SOAD_DUMMY_STATEMENT(v)
#else
# if ( SOAD_DUMMY_STATEMENT_TYPE_VOID == SOAD_DUMMY_STATEMENT_TYPE )
#  define SOAD_DUMMY_STATEMENT_VAR(v)   (void)(v);
# else
#  define SOAD_DUMMY_STATEMENT_VAR(v)   (v)=(v);
# endif /* SOAD_DUMMY_STATEMENT_TYPE_VOID == SOAD_DUMMY_STATEMENT_TYPE */
#endif /* !defined(SOAD_DUMMY_STATEMENT_VAR) */

/* Development Error Tracer */
#if ( defined(SOAD_DEV_ERROR_REPORT) && (STD_ON == SOAD_DEV_ERROR_REPORT) )
# define SOAD_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE) \
         { \
           if (!(CONDITION)) \
           { \
             (void)Det_ReportError(SOAD_MODULE_ID, SOAD_INSTANCE_ID, (API_ID), (ERROR_CODE)); \
             return; \
           } \
         }
# define SOAD_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL) \
         { \
           if (!(CONDITION)) \
           { \
             (void)Det_ReportError(SOAD_MODULE_ID, SOAD_INSTANCE_ID, (API_ID), (ERROR_CODE)); \
             return (RET_VAL); \
           } \
         }
# define SOAD_CheckDetErrorContinue(CONDITION, API_ID, ERROR_CODE) \
         { \
           if (!(CONDITION)) \
           { \
             (void)Det_ReportError(SOAD_MODULE_ID, SOAD_INSTANCE_ID, (API_ID), (ERROR_CODE)); \
           } \
         }
# define SOAD_CallDetReportError(API_ID, ERROR_CODE) \
          (void)Det_ReportError(SOAD_MODULE_ID, SOAD_INSTANCE_ID, (API_ID), (ERROR_CODE))
#else
# define SOAD_CheckDetErrorReturnVoid(CONDITION, API_ID, ERROR_CODE) \
          { \
            if (!(CONDITION)) \
            { \
              return; \
            } \
          }
# define SOAD_CheckDetErrorReturnValue(CONDITION, API_ID, ERROR_CODE, RET_VAL) \
          { \
            if (!(CONDITION)) \
            { \
              return (RET_VAL); \
            } \
          }
# define SOAD_CheckDetErrorContinue(CONDITION, API_ID, ERROR_CODE)
# define SOAD_CallDetReportError(API_ID, ERROR_CODE)
#endif /* defined(SOAD_DEV_ERROR_REPORT) && (STD_ON == SOAD_DEV_ERROR_REPORT) */

/* --- Pointers always present ------------------------------------------------------------------------------------- */
#define SoAd_EventQueueFlags(HandleIdx)               (SoAd_ConfigPtr->EventQueueFlagsListPtr[(HandleIdx)])
                                                      /* SoAd_VEventQueueFlags[] */
#define SoAd_EventQueues(EveQueIdx)                   (SoAd_ConfigPtr->EventQueuesListPtr[(EveQueIdx)])
                                                      /* SoAd_VEventQueues[] */
#define SoAd_SockConIdx2RemSockDyn(SoConIdx)          (SoAd_ConfigPtr->SockConIdx2RemSockDynListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2RemSockDyn[] */
#define SoAd_SockConIdx2State(SoConIdx)               (SoAd_ConfigPtr->SockConIdx2StateListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2State[] */
#define SoAd_SockConIdx2IpAddrState(SoConIdx)         (SoAd_ConfigPtr->SockConIdx2IpAddrStateListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2IpAddrState[] */
#define SoAd_SockIdx2LocPortDyn(SockIdx)              (SoAd_ConfigPtr->SockIdx2LocPortDynListPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2LocPortDyn[] */
#define SoAd_SockIdx2SocketId(SockIdx)                (SoAd_ConfigPtr->SockIdx2SocketIdListPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2SocketId[] */
#define SoAd_SockConIdx2FlagAbort(SoConIdx)           (SoAd_ConfigPtr->SockConIdx2FlagAbortListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2FlagAbort[] */
#define SoAd_SockConIdx2CloseMode(SoConIdx)           (SoAd_ConfigPtr->SockConIdx2CloseModeListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2CloseMode[] */
#define SoAd_SockIdx2SockState(SockIdx)               (SoAd_ConfigPtr->SockIdx2SockStateListPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2SockState[] */
#define SoAd_SockConIdx2FlagCntOpCl(SoConIdx)         (SoAd_ConfigPtr->SockConIdx2FlagCntOpClListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2FlagCntOpCl[] */
#define SoAd_SockConIdx2RemAddrState(SoConIdx)        (SoAd_ConfigPtr->SockConIdx2RemAddrStateListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2RemAddrState[] */
#define SoAd_SockCons(SoConIdx)                       (SoAd_ConfigPtr->SockConsListPtr[(SoConIdx)])
                                                      /* SoAd_VSockCons[] */
#define SoAd_SockIdx2SoConIdxCol(SockIdx)             (SoAd_ConfigPtr->SockIdx2SoConIdxColListPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2SoConIdxCol[] */
#define SoAd_SockConId2SockConIdx(SoConId)            (SoAd_ConfigPtr->SockConId2SockConIdxMapPtr[(SoConId)])
                                                      /* SoAd_VSockConId2SockConIdx[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointers present if SoAdPduRoutes configured ---------------------------------------------------------------- */
/* Check by SoAd_PduRouteTotal() and SoAd_PduRouteTotalWithInv() or SoAd_IsPduRoutePresent() */
#define SoAd_IsPduRoutePresent()                      (0 != SoAd_PduRouteTotal())
#define SoAd_SockConIdx2TxMgt(SoConIdx)               (SoAd_ConfigPtr->SockConIdx2TxMgtListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2TxMgt[] */
#define SoAd_SockIdx2ActiveSoConIdx(SockIdx)          (SoAd_ConfigPtr->SockIdx2ActiveSoConIdxListPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2ActiveSoConIdx[] */
#define SoAd_TxPduIdx2PendingTxConf(TxPduIdx)         (SoAd_ConfigPtr->TxPduIdx2PendingTxConfListPtr[(TxPduIdx)])
                                                      /* SoAd_VTxPduIdx2PendingTxConf[] */
#define SoAd_SockConIdx2PduRouteDestCol(SoConIdx)     (SoAd_ConfigPtr->SockConIdx2PduRouteDestColListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2PduRouteDestCol[] */
#define SoAd_TxPduIdx2PduRoute(TxPduIdx)              (SoAd_ConfigPtr->TxPduIdx2PduRouteListPtr[(TxPduIdx)])
                                                      /* SoAd_VTxPduIdx2PduRoute[] */
#define SoAd_TxPduIdx2TxConfPduId(TxPduIdx)           (SoAd_ConfigPtr->TxPduIdx2TxConfPduIdListPtr[(TxPduIdx)])
                                                      /* SoAd_VTxPduIdx2TxConfPduId[] */
#define SoAd_SockIdx2TxPduIdCol(SockIdx)              (SoAd_ConfigPtr->SockIdx2TxPduIdColListPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2TxPduIdCol[] */
#define SoAd_TxPduId2PduRouteIdx(TxPduId)             (SoAd_ConfigPtr->TxPduId2PduRouteIdxMapPtr[(TxPduId)])
                                                      /* SoAd_VTxPduId2PduRouteIdx[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointers present if SoAdSocketRoutes configured ------------------------------------------------------------- */
/* Check by SoAd_SockRouteTotal(), SoAd_SockRouteTotalWithInv() or SoAd_IsSockRoutePresent() */
#define SoAd_IsSockRoutePresent()                     (0 != SoAd_SockRouteTotal())
#define SoAd_SockConIdx2RxMgt(SoConIdx)               (SoAd_ConfigPtr->SockConIdx2RxMgtListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2RxMgt[] */
#define SoAd_SockIdx2SkipBytes(SockIdx)               (SoAd_ConfigPtr->SockIdx2SkipBytesListPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2SkipBytes[] */
#define SoAd_SockConIdx2RxBuffer(SoConIdx)            (SoAd_ConfigPtr->SockConIdx2RxBufferListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2RxBuffer[] */
#define SoAd_SockRoutes(RouteIdx)                     (SoAd_ConfigPtr->SockRoutesListPtr[(RouteIdx)])
                                                      /* SoAd_VSockRoutes[] */
#define SoAd_SockConIdx2SockRouteCol(SoConIdx)        (SoAd_ConfigPtr->SockConIdx2SockRouteColListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2SockRouteCol[] */
#define SoAd_RxPduId2SockRouteIdx(RxPduId)            (SoAd_ConfigPtr->RxPduId2SockRouteIdxMapPtr[(RxPduId)])
                                                      /* SoAd_VRxPduId2SockRouteIdx[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointers present if NPDU UDP Tx SoCons configured ----------------------------------------------------------- */
/* Check by SoAd_SockConIdx2NPduUdpTxIdxSize() or SoAd_IsNPduUdpTxPresent() */
#define SoAd_IsNPduUdpTxPresent()                     (0 != SoAd_ConfigPtr->SockConIdx2NPduUdpTxIdxSize)
#define SoAd_SockConIdx2NPduUdpTxIdx(SoConIdx)        (SoAd_ConfigPtr->SockConIdx2NPduUdpTxIdxListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2NPduUdpTxIdx[] */
#define SoAd_NPduUdpTx(NPduUdpTxIdx)                  (SoAd_ConfigPtr->NPduUdpTxListPtr[(NPduUdpTxIdx)])
                                                      /* SoAd_VNPduUdpTx[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointers present if TCP IF Trigger Transmit SoCons configured ----------------------------------------------- */
#define SoAd_SockConIdx2IfTriggerTransmitBufIdx(SoConIdx) \
                                                (SoAd_ConfigPtr->SockConIdx2IfTriggerTransmitBufIdxListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2IfTriggerTransmitBufIdx[] */
#define SoAd_IfTriggerTransmitBuffer(BufIdx)          (SoAd_ConfigPtr->IfTriggerTransmitBufferListPtr[(BufIdx)])
                                                      /* SoAd_VTriggerTransmitBuffer[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointer present if Tp UDP SockCons configured --------------------------------------------------------------- */
#define SoAd_IsSockConIdx2TxBufferPresent()           (NULL_PTR != SoAd_ConfigPtr->SockConIdx2TxBufferListPtr)
#define SoAd_SockConIdx2TxBuffer(SoConIdx)            (SoAd_ConfigPtr->SockConIdx2TxBufferListPtr[(SoConIdx)])
                                                      /* SoAd_VSockConIdx2TxBuffer[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointer present if SoAdRoutingGroups configured ------------------------------------------------------------- */
/* Check by SoAd_RouteGrpTotal() and SoAd_RouteGrpTotalWithInv() */
#define SoAd_RouteGrpIdx2RoutingGroup(RoutGrpIdx)     (SoAd_ConfigPtr->RouteGrpIdx2RoutingGroupListPtr[(RoutGrpIdx)])
                                                      /* SoAd_VRouteGrpIdx2RoutingGroup[] */
#define SoAd_RouteGrpId2RouteGrpIdx(RouteGrpId)       (SoAd_ConfigPtr->RouteGrpId2RouteGrpIdxMapPtr[(RouteGrpId)])
                                                      /* SoAd_VRouteGrpId2RouteGrpIdx[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointer present if SoAdPduRoutes with configured SoAdRoutingGroups exists ----------------------------------- */
#define SoAd_IsRouteGrpIdx2PduRouteDestColPresent()   (NULL_PTR != SoAd_ConfigPtr->RouteGrpIdx2PduRouteDestColListPtr)
#define SoAd_RouteGrpIdx2PduRouteDestCol(RoutGrpIdx)  (SoAd_ConfigPtr->RouteGrpIdx2PduRouteDestColListPtr[\
                                                      (RoutGrpIdx)])
                                                      /* SoAd_VRouteGrpIdx2PduRouteDestCol[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointer present if SoAdSocketRoutes with configured SoAdRoutingGroups exists -------------------------------- */
#define SoAd_IsRouteGrpIdx2SocketRouteColPresent()    (NULL_PTR != SoAd_ConfigPtr->RouteGrpIdx2SocketRouteColListPtr)
#define SoAd_RouteGrpIdx2SocketRouteCol(RoutGrpIdx)   (SoAd_ConfigPtr->RouteGrpIdx2SocketRouteColListPtr[(RoutGrpIdx)])
                                                      /* SoAd_VRouteGrpIdx2SocketRouteCol[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointer present if TriggerTransmit configured --------------------------------------------------------------- */
#define SoAd_IsIfRouteGrpTransmitBufPtrPresent()      (NULL_PTR != SoAd_ConfigPtr->IfRouteGrpTransmitBufPtr)
#define SoAd_IfRouteGrpTransmitBufPtr()               (&(SoAd_ConfigPtr->IfRouteGrpTransmitBufPtr[0]))
                                                      /* SoAd_VIfRouteGrpTransmitBuf[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointer present if any TimeoutList is configured -------------------------------------------------------------*/
#define SoAd_IsTimeoutListsPtrPresent()               (0u != SoAd_ConfigPtr->TimeoutListTotal)
#define SoAd_TimeoutLists(TimeListIdx)                (SoAd_ConfigPtr->TimeoutListsListPtr[(TimeListIdx)])
                                                      /* SoAd_VTimeoutLists[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointers present if BSD Socket API is disabled -------------------------------------------------------------- */
#define SoAd_AddrId2TcpIpCtrl(AddrId)                 (SoAd_ConfigPtr->AddrId2TcpIpCtrlPtr[(AddrId)])
                                                      /* SoAd_VAddrId2TcpIpCtrl[] */
#define SoAd_TcpIpCtrl(TcpIpCtrl)                     (SoAd_ConfigPtr->TcpIpCtrlPtr[(TcpIpCtrl)])
                                                      /* SoAd_VTcpIpCtrl[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Pointers present if BSD Socket API is enabled (pre-compile) ------------------------------------------------- */
#define SoAd_LocalAddr(AddrId)                        (SoAd_ConfigPtr->LocalAddrPtr[(AddrId)])
                                                      /* SoAd_VLocalAddr[][] */
#define SoAd_AddrId2LocalIpAddr(AddrId)               (SoAd_ConfigPtr->AddrId2LocalIpAddrPtr[(AddrId)])
                                                      /* SoAd_VAddrId2LocalIpAddr[] */
#define SoAd_AddrId2LocalIpAddrDyn(AddrId)            (SoAd_ConfigPtr->AddrId2LocalIpAddrDynPtr[(AddrId)])
                                                      /* SoAd_VAddrId2LocalIpAddrDyn[] */
#define SoAd_AddrId2LocalIpAddrReqState(AddrId)       (SoAd_ConfigPtr->AddrId2LocalIpAddrReqStatePtr[(AddrId)])
                                                      /* SoAd_VAddrId2LocalIpAddrReqState[] */
#define SoAd_AddrId2SockIdxCol(AddrId)                (SoAd_ConfigPtr->AddrId2SockIdxColPtr[(AddrId)])
                                                      /* SoAd_VAddrId2SockIdxCol[] */
#define SoAd_SockIdx2MulticastAddr(SockIdx)           (SoAd_ConfigPtr->SockIdx2MulticastAddrPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2MulticastAddr[] */
#define SoAd_SockIdx2RxMgt(SockIdx)                   (SoAd_ConfigPtr->SockIdx2RxMgtPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2RxMgt[] */
#define SoAd_SockIdx2RxBuf(SockIdx)                   (SoAd_ConfigPtr->SockIdx2RxBufPtr[(SockIdx)])
                                                      /* SoAd_VSockIdx2RxBuf[] */
#define SoAd_SocketTxBuffer()                         (SoAd_ConfigPtr->SocketTxBufferPtr)
                                                      /* SoAd_VSocketTxBuffer[] */
#define SoAd_SocketRxBuffer()                         (SoAd_ConfigPtr->SocketRxBufferPtr)
                                                      /* SoAd_VSocketRxBuffer[] */
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Sizes ------------------------------------------------------------------------------------------------------- */
#define SoAd_EventQueueFlagsArraySize()               (SoAd_ConfigPtr->EventQueueFlagsArraySize)
#define SoAd_EventQueueTotal()                        (SoAd_ConfigPtr->EventQueueTotal)
#define SoAd_TimeoutListTotal()                       (SoAd_ConfigPtr->TimeoutListTotal)
#define SoAd_SockConTotal()                           (SoAd_ConfigPtr->SockConTotal)
#define SoAd_SockConTotalWithInv()                    (SoAd_ConfigPtr->SockConTotalWithInv)
#define SoAd_RouteGrpTotal()                          (SoAd_ConfigPtr->RouteGrpTotal)
#define SoAd_RouteGrpTotalWithInv()                   (SoAd_ConfigPtr->RouteGrpTotalWithInv)
#define SoAd_SockRouteTotal()                         (SoAd_ConfigPtr->SockRouteTotal)
#define SoAd_SockRouteTotalWithInv()                  (SoAd_ConfigPtr->SockRouteTotalWithInv)
#define SoAd_PduRouteTotal()                          (SoAd_ConfigPtr->PduRouteTotal)
#define SoAd_PduRouteTotalWithInv()                   (SoAd_ConfigPtr->PduRouteTotalWithInv)
#define SoAd_TcpIpSocketCnt()                         (SoAd_ConfigPtr->TcpIpSocketCnt)
#define SoAd_IfRouteGrpTransmitBufSize()              (SoAd_ConfigPtr->IfRouteGrpTransmitBufSize)
#define SoAd_MaxIfRouteGrpTransmitPduSize()           (SoAd_ConfigPtr->MaxIfRouteGrpTransmitPduSize)
#define SoAd_SockConIdx2NPduUdpTxIdxSize()            (SoAd_ConfigPtr->SockConIdx2NPduUdpTxIdxSize)
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Indexs ------------------------------------------------------------------------------------------------------ */
/* check presence by following defines */
#define SoAd_IsEventQueueIdxSockIdxPresent()          (SoAd_ConfigPtr->EventQueueIdxSockIdx != 0xFFu)
#define SoAd_IsEventQueueIdxTpRxSoConPresent()        (SoAd_ConfigPtr->EventQueueIdxTpRxSoCon != 0xFFu)
#define SoAd_IsEventQueueIdxLocalAddrPresent()        (SoAd_ConfigPtr->EventQueueIdxLocalAddr != 0xFFu)
#define SoAd_IsEventQueueIdxStateSoConPresent()       (SoAd_ConfigPtr->EventQueueIdxStateSoCon != 0xFFu)
#define SoAd_IsEventQueueIdxTxSoConPresent()          (SoAd_ConfigPtr->EventQueueIdxTxSoCon != 0xFFu)
#define SoAd_IsEventQueueIdxIfUdpPduRoutePresent()    (SoAd_ConfigPtr->EventQueueIdxIfUdpPduRoute != 0xFFu)
#define SoAd_IsEventQueueIdxIfTxRouteGrpPresent()     (SoAd_ConfigPtr->EventQueueIdxIfTxRouteGrp != 0xFFu)
#define SoAd_IsTimeoutListIdxUdpAlivePresent()        (SoAd_ConfigPtr->TimeoutListIdxUdpAlive != 0xFFu)
#define SoAd_IsTimeoutListIdxNPduUdpTxPresent()       (SoAd_ConfigPtr->TimeoutListIdxNPduUdpTx != 0xFFu)

#define SoAd_EventQueueIdxSockIdx()                   (SoAd_ConfigPtr->EventQueueIdxSockIdx)
#define SoAd_EventQueueIdxTpRxSoCon()                 (SoAd_ConfigPtr->EventQueueIdxTpRxSoCon)
#define SoAd_EventQueueIdxLocalAddr()                 (SoAd_ConfigPtr->EventQueueIdxLocalAddr)
#define SoAd_EventQueueIdxStateSoCon()                (SoAd_ConfigPtr->EventQueueIdxStateSoCon)
#define SoAd_EventQueueIdxTxSoCon()                   (SoAd_ConfigPtr->EventQueueIdxTxSoCon)
#define SoAd_EventQueueIdxIfUdpPduRoute()             (SoAd_ConfigPtr->EventQueueIdxIfUdpPduRoute)
#define SoAd_EventQueueIdxIfTxRouteGrp()              (SoAd_ConfigPtr->EventQueueIdxIfTxRouteGrp)
#define SoAd_TimeoutListIdxUdpAlive()                 (SoAd_ConfigPtr->TimeoutListIdxUdpAlive)
#define SoAd_TimeoutListIdxNPduUdpTx()                (SoAd_ConfigPtr->TimeoutListIdxNPduUdpTx)
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Sizes if BSD Socket API is enabled (pre-Compile) ------------------------------------------------------------ */
#define SoAd_AddrIdTotal()                            (SoAd_ConfigPtr->AddrIdTotal)
#define SoAd_SocketTxBufferSize()                     (SoAd_ConfigPtr->SocketTxBufferSize)
#define SoAd_SocketRxBufferSize()                     (SoAd_ConfigPtr->SocketRxBufferSize)
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- Parameters if BSD Socket API is enabled (pre-Compile) ------------------------------------------------------- */
#define SoAd_LingerTimeoutEnabled()                   (SoAd_ConfigPtr->LingerTimeoutEnabled)
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- SoConId -> SoConIdx ----------------------------------------------------------------------------------------- */
#define SOAD_GetSockConIdxCheckDetErrorReturnValue(PARAMETER, SOCONID, API_ID, RET_VAL) \
        { \
          SOAD_CheckDetErrorReturnValue((SoAd_SockConTotalWithInv() > (SOCONID)), (API_ID), SOAD_E_INV_ARG, \
            (RET_VAL)); \
          (PARAMETER) = SoAd_SockConId2SockConIdx((SOCONID)); \
          SOAD_CheckDetErrorReturnValue((SOAD_INV_SO_CON_IDX != (PARAMETER)), (API_ID), SOAD_E_INV_ARG, (RET_VAL)); \
        }
#define SOAD_GetSockConIdxCheckDetErrorReturnVoid(PARAMETER, SOCONID, API_ID) \
        { \
          SOAD_CheckDetErrorReturnVoid((SoAd_SockConTotalWithInv() > (SOCONID)), (API_ID), SOAD_E_INV_ARG); \
          (PARAMETER) = SoAd_SockConId2SockConIdx((SOCONID)); \
          SOAD_CheckDetErrorReturnVoid((SOAD_INV_SO_CON_IDX != (PARAMETER)), (API_ID), SOAD_E_INV_ARG); \
        }
#define SOAD_CheckSockConIdDetErrorReturnValue(SOCONID, API_ID, RET_VAL) \
        { \
          SOAD_CheckDetErrorReturnValue((SoAd_SockConTotalWithInv() > (SOCONID)), (API_ID), SOAD_E_INV_ARG, \
            (RET_VAL)); \
          SOAD_CheckDetErrorReturnValue((SOAD_INV_SO_CON_IDX != SoAd_SockConId2SockConIdx((SOCONID))), \
            (API_ID), SOAD_E_INV_ARG, (RET_VAL)); \
        }
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- RouteGrpId -> RouteGrpIdx ----------------------------------------------------------------------------------- */
#define SOAD_GetRouteGrpIdxCheckDetErrorReturnValue(PARAMETER, ROUTEGRPID, API_ID, RET_VAL) \
        { \
          SOAD_CheckDetErrorReturnValue((SoAd_RouteGrpTotalWithInv() > (ROUTEGRPID)), (API_ID), SOAD_E_INV_ARG, \
            (RET_VAL)); \
          (PARAMETER) = SoAd_RouteGrpId2RouteGrpIdx((ROUTEGRPID)); \
          SOAD_CheckDetErrorReturnValue((SOAD_INV_ROUT_GRP_IDX != (PARAMETER)), (API_ID), SOAD_E_INV_ARG, (RET_VAL)); \
        }
#define SOAD_GetRouteGrpIdxCheckDetError(PARAMETER, ROUTEGRPID, API_ID) \
        { \
          SOAD_CheckDetErrorContinue((SoAd_RouteGrpTotalWithInv() > (ROUTEGRPID)), (API_ID), SOAD_E_INV_ARG); \
          (PARAMETER) = SoAd_RouteGrpId2RouteGrpIdx((ROUTEGRPID)); \
          SOAD_CheckDetErrorContinue((SOAD_INV_ROUT_GRP_IDX != (PARAMETER)), (API_ID), SOAD_E_INV_ARG); \
        }
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- SockRouteId -> SockRouteIdx --------------------------------------------------------------------------------- */
#define SOAD_GetSockRouteIdxCheckDetErrorReturnValue(PARAMETER, RXPDUID, API_ID, RET_VAL) \
        { \
          SOAD_CheckDetErrorReturnValue((SoAd_SockRouteTotalWithInv() > (RXPDUID)), (API_ID), SOAD_E_INV_PDUID, \
            (RET_VAL)); \
          (PARAMETER) = SoAd_RxPduId2SockRouteIdx((RXPDUID)); \
          SOAD_CheckDetErrorReturnValue((SOAD_INV_SOCKROUTE_IDX != (PARAMETER)), (API_ID), SOAD_E_INV_PDUID, \
            (RET_VAL)); \
        }
/* ----------------------------------------------------------------------------------------------------------------- */

/* --- PduRouteId -> PduRouteIdx ----------------------------------------------------------------------------------- */
#define SOAD_GetPduRouteIdxCheckDetErrorReturnValue(PARAMETER, TXPDUID, API_ID, RET_VAL) \
        { \
          SOAD_CheckDetErrorReturnValue((SoAd_PduRouteTotalWithInv() > (TXPDUID)), (API_ID), SOAD_E_INV_PDUID, \
            (RET_VAL)); \
          (PARAMETER) = SoAd_TxPduId2PduRouteIdx((TXPDUID)); \
          SOAD_CheckDetErrorReturnValue((SOAD_INV_PDUROUTE_IDX != (PARAMETER)), (API_ID), SOAD_E_INV_PDUID, \
            (RET_VAL)); \
        }
#define SOAD_GetPduRouteIdxCheckDetErrorReturnVoid(PARAMETER, TXPDUID, API_ID) \
        { \
          SOAD_CheckDetErrorReturnVoid((SoAd_PduRouteTotalWithInv() > (TXPDUID)), (API_ID), SOAD_E_INV_PDUID); \
          (PARAMETER) = SoAd_TxPduId2PduRouteIdx((TXPDUID)); \
          SOAD_CheckDetErrorReturnVoid((SOAD_INV_PDUROUTE_IDX != (PARAMETER)), (API_ID), SOAD_E_INV_PDUID); \
        }
#define SOAD_GetPduRouteIdxCheckDetError(PARAMETER, TXPDUID, API_ID) \
        { \
          SOAD_CheckDetErrorContinue((SoAd_PduRouteTotalWithInv() > (TXPDUID)), (API_ID), SOAD_E_INV_PDUID); \
          (PARAMETER) = SoAd_TxPduId2PduRouteIdx((TXPDUID)); \
          SOAD_CheckDetErrorContinue((SOAD_INV_PDUROUTE_IDX != (PARAMETER)), (API_ID), SOAD_E_INV_PDUID); \
        }
/* ----------------------------------------------------------------------------------------------------------------- */

#if !defined(SOAD_CONFIGURATION_VARIANT)
# error "SoAd_Priv.h: Missing SOAD_CONFIGURATION_VARIANT"
#endif /* defined(SOAD_CONFIGURATION_VARIANT) */

/* PRQA L:FCT_LIKE_MACROS */

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
FUNC(void,           SOAD_CODE) SoAd_VAssignUdpSocket(SoAd_SoConIdxType SoConIdx);
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VWriteBufSegment(
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) SrcBufPtr,
                                        uint16 SrcBufLen,
                                        P2VAR(SoAd_BufSegMgtType, AUTOMATIC, SOAD_APPL_DATA) TgtBufSegPtr);
FUNC(void,           SOAD_CODE) SoAd_VGetBufSegment(
                                        P2CONST(SoAd_BufSegMgtType, AUTOMATIC, SOAD_APPL_DATA) BufSegPtr,
                                        uint32 StartPos,
                                        P2VAR(uint8*, AUTOMATIC, SOAD_APPL_VAR) SegPtr,
                                        P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) SegLen);
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
FUNC(uint32,         SOAD_CODE) SoAd_VGetBufSegmentTotLen(
                                        P2CONST(SoAd_BufSegMgtType, AUTOMATIC, SOAD_APPL_DATA) BufSegPtr,
                                        uint32 StartPos);
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
FUNC(void,           SOAD_CODE) SoAd_VReleaseBufSegment(
                                        P2VAR(SoAd_BufSegMgtType, AUTOMATIC, AUTOMATIC) BufSegPtr,
                                        uint32 Len);
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VCompareSockAddr(P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) AddrA,
                                        P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) AddrB,
                                        boolean AllowWildcards);
FUNC(void,           SOAD_CODE) SoAd_VCheckForWildcards(
                                        P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) AddrCheck,
                                        P2VAR(boolean, AUTOMATIC, SOAD_APPL_DATA) IpAddrIsAny,
                                        P2VAR(boolean, AUTOMATIC, SOAD_APPL_DATA) PortIsAny);
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VCompareIpAddr(
                                        SoAd_DomainType Domain,
                                        P2CONST(SoAd_IpAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrA,
                                        P2CONST(SoAd_IpAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrB);
#else
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VCompareIpAddr(
                                        P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrA,
                                        P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrB,
                                        boolean AllowWildcards);
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
FUNC(void,           SOAD_CODE) SoAd_VCopyIpAddr(P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) TgtIpAddr,
                                        P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) SrcIpAddr,
                                        boolean OverwriteAll);
#if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
FUNC(void,           SOAD_CODE) SoAd_VCopyPduHdr2Buf(SoAd_PduHdrIdType PduHeaderId,
                                        SoAd_PduHdrLenType PduHeaderLen,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        PduLengthType Offset,
                                        PduLengthType Length);
# if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
#  if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
FUNC(void,           SOAD_CODE) SoAd_VCopyBufSeg2Buf(P2VAR(uint8, SOAD_APPL_DATA, SOAD_APPL_DATA) BufPtr,
                                        P2CONST(SoAd_BufSegMgtType, SOAD_APPL_DATA, SOAD_APPL_DATA) BufSegPtr,
                                        uint32 BufLen, uint32 StartPos);
#  endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
# endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
#endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */

#endif /* !defined(SOAD_PRIV_H) */

/**********************************************************************************************************************
 *  END OF FILE: SoAd_Priv.h
 *********************************************************************************************************************/
