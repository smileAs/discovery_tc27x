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
 *         File:  SoAd.c
 *      Project:  TcpIp-Stack
 *       Module:  Socket Adapter
 *    Generator:  If_AsrIfSoAd.dll
 *
 *  Description:  implementation
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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 MACRO_LIMIT */ /* MD_MSR_1.1_857 */

#include "SoAd.h"
#include "SoAd_Priv.h"
#include "SoAd_Cbk.h"
#include "IpBase.h"
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
# include <sys/socket.h>
# include <sys/poll.h>
# include <sys/ioctl.h>
# include <netinet/in.h>
# include <net/if.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <ifaddrs.h>
# include <netinet/tcp.h>
#else
# include "TcpIp.h"
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
#if (SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SOAD_CONFIGURATION_VARIANT)
# include "EcuM_Error.h"
#endif /* (SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SOAD_CONFIGURATION_VARIANT) */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check consistency of source and header file. */
#if ( (SOAD_SW_MAJOR_VERSION != 9u) || (SOAD_SW_MINOR_VERSION != 2u) || (SOAD_SW_PATCH_VERSION != 0u) )
# error "SoAd.c: Source and Header file are inconsistent!"
#endif

/* Check configuration variant for building the library */
#if ( (defined(V_EXTENDED_BUILD_LIB_CHECK)) && (SOAD_CONFIGURATION_VARIANT_PRECOMPILE == SOAD_CONFIGURATION_VARIANT) )
# error "SoAd.c: Switch configuration variant to link-time or post-build for library build!"
#endif /* (defined(V_EXTENDED_BUILD_LIB_CHECK)) &&
  (SOAD_CONFIGURATION_VARIANT_PRECOMPILE == SOAD_CONFIGURATION_VARIANT) */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if defined(C_COMP_ANSI_CANOE)
# define SOAD_VENABLE_CANOE_WRITE_STRING   STD_ON
#else
# define SOAD_VENABLE_CANOE_WRITE_STRING   STD_OFF
#endif /* defined(C_COMP_ANSI_CANOE) */

#if !defined (STATIC)
# define STATIC                      static
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3453,3458 FCT_LIKE_MACROS */ /* MD_MSR_19.4, MD_MSR_19.7 */

#if defined(C_COMP_ANSI_CANOE)
# if ( defined(SOAD_VENABLE_CANOE_WRITE_STRING) && (STD_ON == SOAD_VENABLE_CANOE_WRITE_STRING) )
#  include "stdio.h"
#  define CANOE_WRITE_STRING(Txt) \
            CANoeAPI_WriteString((Txt));
#  define CANOE_WRITE_STRING_1(Txt, P1) \
            _snprintf(SoAd_CanoeWriteStr, 256, Txt, P1); \
            CANoeAPI_WriteString((SoAd_CanoeWriteStr));
#  define CANOE_WRITE_STRING_2(Txt, P1, P2) \
            _snprintf(SoAd_CanoeWriteStr, 256, Txt, P1, P2); \
            CANoeAPI_WriteString((SoAd_CanoeWriteStr));
#  define CANOE_WRITE_STRING_3(Txt, P1, P2, P3) \
            _snprintf(SoAd_CanoeWriteStr, 256, Txt, P1, P2, P3); \
            CANoeAPI_WriteString((SoAd_CanoeWriteStr));
# else
#  define CANOE_WRITE_STRING(txt)
#  define CANOE_WRITE_STRING_1(txt, p1)
#  define CANOE_WRITE_STRING_2(txt, p1, p2)
#  define CANOE_WRITE_STRING_3(txt, p1, p2, p3)
# endif /* defined(SOAD_VENABLE_CANOE_WRITE_STRING) && (STD_ON == SOAD_VENABLE_CANOE_WRITE_STRING) */
#else
# define CANOE_WRITE_STRING(txt)
# define CANOE_WRITE_STRING_1(txt, p1)
# define CANOE_WRITE_STRING_2(txt, p1, p2)
# define CANOE_WRITE_STRING_3(txt, p1, p2, p3)
#endif /* defined(C_COMP_ANSI_CANOE) */

#if ( defined(SOAD_VSOCKET_BSD_REPORT_ERROR_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_REPORT_ERROR_ENABLED) )
# define SOAD_REPORT_SOCK_ERROR(API_ID, BSD_API_ID, ERRNO) \
            SoAd_VCallReportErrorFunc((API_ID), (BSD_API_ID), SOAD_SOCK_BSD_PARAM_NONE, \
              SOAD_SOCK_BSD_VALUE_NONE, SOAD_SOCK_BSD_VALUE_NONE, (ERRNO))
# define SOAD_REPORT_SOCK_ERROR_PARAM(API_ID, BSD_API_ID, PARAM, ERRNO) \
            SoAd_VCallReportErrorFunc((API_ID), (BSD_API_ID), (PARAM), SOAD_SOCK_BSD_VALUE_NONE, \
              SOAD_SOCK_BSD_VALUE_NONE, (ERRNO))
# define SOAD_REPORT_SOCK_ERROR_PARAM_1(API_ID, BSD_API_ID, PARAM, VAL1, ERRNO) \
            SoAd_VCallReportErrorFunc((API_ID), (BSD_API_ID), (PARAM), (VAL1), SOAD_SOCK_BSD_VALUE_NONE, (ERRNO))
# define SOAD_REPORT_SOCK_ERROR_PARAM_2(API_ID, BSD_API_ID, PARAM, VAL1, VAL2, ERRNO) \
            SoAd_VCallReportErrorFunc((API_ID), (BSD_API_ID), (PARAM), (VAL1), (VAL2), (ERRNO))
#else
# define SOAD_REPORT_SOCK_ERROR(API_ID, BSD_API_ID, ERRNO)
# define SOAD_REPORT_SOCK_ERROR_PARAM(API_ID, BSD_API_ID, PARAM, ERRNO)
# define SOAD_REPORT_SOCK_ERROR_PARAM_1(API_ID, BSD_API_ID, PARAM, VAL1, ERRNO)
# define SOAD_REPORT_SOCK_ERROR_PARAM_2(API_ID, BSD_API_ID, PARAM, VAL1, VAL2, ERRNO)
#endif /* defined(SOAD_VSOCKET_BSD_REPORT_ERROR_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_REPORT_ERROR_ENABLED) */

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#if (SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SOAD_CONFIGURATION_VARIANT)
# define SOAD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
P2CONST(SoAd_ConfigType, AUTOMATIC, SOAD_PBCFG) SoAd_ConfigPtr = NULL_PTR;
# define SOAD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
#else
# define SOAD_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
CONSTP2CONST(SoAd_ConfigType, AUTOMATIC, SOAD_CONST) SoAd_ConfigPtr = &SoAd_GlobalConfig;
# define SOAD_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* (SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SOAD_CONFIGURATION_VARIANT) */

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#define SOAD_START_SEC_VAR_ZERO_INIT_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
STATIC VAR(SoAd_SockIdxType, SOAD_VAR_ZERO_INIT) SoAd_OpenSocks = 0u;
STATIC VAR(uint16,           SOAD_VAR_ZERO_INIT) SoAd_ShutdownFinishedCnt = 0u;
#define SOAD_STOP_SEC_VAR_ZERO_INIT_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SOAD_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
STATIC VAR(uint8,          SOAD_VAR_NOINIT) SoAd_CriticalSectionCount;
STATIC VAR(SoAd_StateType, SOAD_VAR_NOINIT) SoAd_State;
#if ( defined(SOAD_VENABLE_CANOE_WRITE_STRING) && (STD_ON == SOAD_VENABLE_CANOE_WRITE_STRING) )
STATIC VAR(uint8,          SOAD_VAR_NOINIT) SoAd_CanoeWriteStr[256];
#endif /* defined(SOAD_VENABLE_CANOE_WRITE_STRING) && (STD_ON == SOAD_VENABLE_CANOE_WRITE_STRING) */
#define SOAD_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) || (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) )
#define SOAD_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
STATIC VAR(uint32,         SOAD_VAR_NOINIT) SoAd_GlobalCounter;
#define SOAD_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) || (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VEventQueuesClear(void);
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VEventQueueAddElement(uint8 EveQueIdx, uint16 HandleIdx);
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VEventQueueGetNextElement(uint8 EveQueIdx,
                                        P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) HandleIdxPtr);
#if ( (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) || (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) )
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VTimeoutListsClear(void);
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTimeoutListSetElement(uint8 TimeListIdx, uint16 HandleIdx,
                                        uint32 Timeout, uint32 TimerCounter);
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTimeoutListGetCurrentTimeout(uint8 TimeListIdx, uint16 HandleIdx,
                                        P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) TimeoutPtr, uint32 TimerCounter);
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTimeoutListCheckElements(uint8 TimeListIdx,
                                        P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) ElementIdxPtr,
                                        P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) HandleIdxPtr,
                                        uint32 TimerCounter);
LOCAL_INLINE FUNC(void,           SOAD_CODE) SoAd_VTimeoutListRemoveElement(uint8 TimeListIdx, uint16 HandleIdx);
#endif /* (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) || (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) */
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
LOCAL_INLINE FUNC(void,           SOAD_CODE) SoAd_VAddPendingIfTxConf(SoAd_PduIdxType TxPduIdx,
                                        SoAd_SoConIdxType SoConIdx);
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpTxQueueReserveNextElement(SoAd_SoConIdxType SoConIdx,
                                        SoAd_PduIdxType TxPduIdx);
LOCAL_INLINE FUNC(void,           SOAD_CODE) SoAd_VTcpTxQueueSetElement(SoAd_SoConIdxType SoConIdx,
                                  SoAd_PduIdxType TxPduIdx, PduLengthType Len, boolean Free);
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
# if ( (defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED)) || \
  (defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF)) )
LOCAL_INLINE FUNC(void,           SOAD_CODE) SoAd_VReconnectSockCon(SoAd_SoConIdxType SoConIdx);
# endif /* (defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED)) || \
  (defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF)) */
# if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
#  if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VUpdatePduHdrLen(SoAd_PduHdrLenType PduHeaderLen,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr);
#  endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
# endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */

STATIC FUNC(void,              SOAD_CODE) SoAd_VCloseSockCon(SoAd_SoConIdxType SoConIdx);
STATIC FUNC(void,              SOAD_CODE) SoAd_VOpenSockCon(SoAd_SoConIdxType SoConIdx);
STATIC FUNC(void,              SOAD_CODE) SoAd_VResetSockCon(SoAd_SoConIdxType SoConIdx, boolean ResetRemAddr,
                                        boolean NormalClose);
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VResetLocalIpAddr(SoAd_LocalAddrIdType LocalAddrId);
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VCheckAndOverwriteLocalAddr(SoAd_SoConIdxType SoConIdx,
                                        boolean OverwriteLocal);
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VTcpRxIndication(SoAd_SoConIdxType SoConIdx,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        uint16 Length);
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VTcpPduHdrRxIndication(SoAd_SoConIdxType SoConIdx,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        uint16 Length);
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
STATIC FUNC(void,              SOAD_CODE) SoAd_VUdpRxIndication(SoAd_SoConIdxType SoConIdx,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        uint16 Length);
# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VUdpPduHdrRxIndication(SoAd_SoConIdxType SoConIdx,
                                        P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        uint16 Length);
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES)  */
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VIfTransmit(
                                        SoAd_SoConIdxType SoConIdx,
                                        P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInforPtr,
                                        P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_VAR) PduRouteDestPtr);
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VTcpTxConfirmation(SoAd_SoConIdxType SoConIdx,
                                        SoAd_PduIdxType TxPduIdx);
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleShutdown(void);
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleShutdownFinish(void);
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleIpAddrStates(void);
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleTcpSocketStates(void);
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleSoConStates(void);
#if ( SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON )
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleUdpAliveTimeout(void);
#endif /* SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON */
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleTpReception(void);
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleTpAndTcpTransmission(void);
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleTpTransmissionInMain(SoAd_SoConIdxType SoConIdx);
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VHandleTpTransmissionOnSockCon(SoAd_SoConIdxType SoConIdx,
                                        boolean CalledByMain);
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#if ( defined(SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) && (STD_ON == SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleIfRouteGrpTransmit(void);
#endif /* defined(SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) && (STD_ON == SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) */
#if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleNPduUdpTx(void);
STATIC FUNC(void,              SOAD_CODE) SoAd_VNPduClear(uint16 NPduUdpTxIdx);
#endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */
#if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
STATIC FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_VNPduQueueAddElement(SoAd_PduIdxType TxPduIdx,
                                        P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_VAR) PduRouteDestPtr,
                                        P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInforPtr);
STATIC FUNC(void,              SOAD_CODE) SoAd_VNPduQueueSend(uint16 NPduUdpTxIdx);
#endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
# if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
STATIC FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_VNPduBufAddElement(SoAd_PduIdxType TxPduIdx,
                                        P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_VAR) PduRouteDestPtr,
                                        P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInforPtr);
STATIC FUNC(void,              SOAD_CODE) SoAd_VNPduBufSend(uint16 NPduUdpTxIdx);
#endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
#  if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleTcpTxConfirmation(SoAd_SoConIdxType SoConIdx);
#  endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleTxConfirmation(void);
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#if ( (defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED)) || \
  (defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED)) || \
  (defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED)) )
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VTcpIpChangeParameter(SoAd_SoConIdxType SoConIdx,
                                        SoAd_SocketIdType SocketId, boolean IsTcpAcceptedSocket);
#endif /* (defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED)) || \
  (defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED)) || \
  (defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED)) */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VHandleSocketReception(void);
STATIC FUNC(void,              SOAD_CODE) SoAd_VTcpIpReceived(SoAd_SocketIdType SocketId, uint32 Length);
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VTcpIpGetSocket(SoAd_SockIdxType SockIdx,
                                        SoAd_DomainType Domain,
                                        SoAd_ProtocolType Protocol,
                                        P2VAR(SoAd_SocketIdType, AUTOMATIC, SOAD_APPL_VAR) SocketIdPtr);
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VTcpIpBind(SoAd_SockIdxType SockIdx,
                                        SoAd_SocketIdType SocketId,
                                        SoAd_LocalAddrIdType LocalAddrId,
                                        P2VAR(SoAd_PortType, AUTOMATIC, SOAD_APPL_VAR) PortPtr);
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VTcpIpListen(SoAd_SocketIdType SocketId, uint16 MaxChannels);
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VTcpIpConnect(SoAd_SockIdxType SockIdx, SoAd_SocketIdType SocketId,
                                        P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemAddrPtr);
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VTcpIpClose(SoAd_SocketIdType SocketId, boolean Abort,
                                        SoAd_SockIdxType SockIdx, boolean CallEventFunction);
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VTcpIpUdpTransmit(SoAd_SockIdxType SockIdx,
                                        SoAd_SocketIdType SocketId,
                                        P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC) RemAddrPtr,
                                        uint32 AvailableLength);
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VTcpIpTransmit(SoAd_SocketIdType SocketId, uint32 AvailableLength);
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
# if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
#  define SoAd_VTriggerAddressResolution(SoConIdx)
# endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#else
# define SoAd_VTcpIpReceived(Id, Length)                    TcpIp_TcpReceived(Id, Length)
# define SoAd_VTcpIpGetSocket(Idx, Domain, Protocol, IdPtr) TcpIp_SoAdGetSocket(Domain, Protocol, IdPtr)
# define SoAd_VTcpIpBind(Idx, Id, AddrId, PortPtr)          TcpIp_Bind(Id, AddrId, PortPtr)
# define SoAd_VTcpIpListen(Id, MaxChannels)                 TcpIp_TcpListen(Id, MaxChannels)
# define SoAd_VTcpIpConnect(Idx, Id, RemAddrPtr)            TcpIp_TcpConnect(Id, RemAddrPtr)
# define SoAd_VTcpIpClose(Id, Abort, Idx, Call)             TcpIp_Close(Id, Abort)
# define SoAd_VTcpIpUdpTransmit(Idx, Id, AddrPtr, Len)      TcpIp_UdpTransmit(Id, NULL_PTR, AddrPtr, Len)
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
#  define SoAd_VTcpIpTransmit(Id, Len)                      TcpIp_TcpTransmit(Id, NULL_PTR, Len, TRUE)
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
# if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VTriggerAddressResolution(SoAd_SoConIdxType SoConIdx);
# endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
# if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
STATIC FUNC(boolean,           SOAD_CODE) SoAd_VCheckAnyRoutGrpOnSockRouteDestEnabled(uint16 SockRouteIdx);
# endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
STATIC FUNC(boolean,           SOAD_CODE) SoAd_VCheckAnyRoutGrpOnPduRouteDestEnabled(
                                        P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_DATA) PduRouteDest);
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VGetSoConIdByBestMatchAlg(
                                        P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) DynAddr,
                                        SoAd_SoConIdxType SoConIdxStart,
                                        SoAd_SoConIdxType SoConIdxMax,
                                        SoAd_SoConModeFilterType SoConModeFilter,
                                        boolean NoSockRouteFilter,
                                        P2VAR(SoAd_SoConIdxType, AUTOMATIC, SOAD_APPL_DATA) SoConIdxBestMatch);
STATIC FUNC(SoAd_SockIdxType,  SOAD_CODE) SoAd_VGetSockIdxBySocketId(SoAd_SocketIdType SocketId);
STATIC FUNC(void,              SOAD_CODE) SoAd_VResetIpAddr(SoAd_SoConIdxType SoConIdx);
STATIC FUNC(void,              SOAD_CODE) SoAd_VResetIpAddr2Unspec(
                                        P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrPtr);
STATIC FUNC(Std_ReturnType,    SOAD_CODE) SoAd_VCheckAndSetRemoteAddr(SoAd_SoConIdxType SoConIdx,
                                        P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr);
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
STATIC FUNC(void,              SOAD_CODE) SoAd_VConvertAsrSockAddr2BsdSockAddr(
                                        P2VAR(struct sockaddr, SOAD_APPL_DATA, SOAD_APPL_DATA) BsdSockAddrPtr,
                                        P2CONST(SoAd_SockAddrType, SOAD_APPL_DATA, SOAD_APPL_DATA) AsrSockAddrPtr);
STATIC FUNC(void,              SOAD_CODE) SoAd_VConvertBsdSockAddr2AsrSockAddr(
                                        P2VAR(SoAd_SockAddrType, SOAD_APPL_DATA, SOAD_APPL_DATA) AsrSockAddrPtr,
                                        P2CONST(struct sockaddr, SOAD_APPL_DATA, SOAD_APPL_DATA) BsdSockAddrPtr);
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

/* PRQA L:FCT_LIKE_MACROS */
/* PRQA L:MACRO_LIMIT */

/**********************************************************************************************************************
 *  INLINE FUNCTIONS
 *********************************************************************************************************************/
/* PRQA S 0306,0310,3305 TYPE_CAST */ /* MD_SoAd_11.4 */

/**********************************************************************************************************************
 *  SoAd_VEventQueuesClear
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VEventQueuesClear(void)
{
  uint16 idx;

  for ( idx = 0u; idx < SoAd_EventQueueTotal(); idx++ )
  {
    SoAd_EventQueues(idx).EveMgtPtr->Idx = 0u;
    SoAd_EventQueues(idx).EveMgtPtr->Lvl = 0u;
  }
  for ( idx = 0u; idx < SoAd_EventQueueFlagsArraySize(); idx++ )
  {
    SoAd_EventQueueFlags(idx) = 0u;
  }
}

/**********************************************************************************************************************
 *  SoAd_VEventQueueAddElement
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VEventQueueAddElement(uint8 EveQueIdx, uint16 HandleIdx)
{
  SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if ( (SoAd_EventQueueFlags(HandleIdx) & SoAd_EventQueues(EveQueIdx).EveQueBitPattern) == 0u )
  { /* event not yet in queue */
    uint16 writeIdx;

    /* get next queue index */
    if ( (SoAd_EventQueues(EveQueIdx).EveMgtPtr->Idx + SoAd_EventQueues(EveQueIdx).EveMgtPtr->Lvl) >=
      SoAd_EventQueues(EveQueIdx).EveQueSize )
    { /* wrap around */
      writeIdx = SoAd_EventQueues(EveQueIdx).EveMgtPtr->Lvl -
        (SoAd_EventQueues(EveQueIdx).EveQueSize - SoAd_EventQueues(EveQueIdx).EveMgtPtr->Idx);
    }
    else
    { /* no wrap around */
      writeIdx = SoAd_EventQueues(EveQueIdx).EveMgtPtr->Idx + SoAd_EventQueues(EveQueIdx).EveMgtPtr->Lvl;
    }

    /* write new queue entry */
    if ( SoAd_EventQueues(EveQueIdx).EveQueType == SOAD_QUEUE_LIST_TYPE_UINT8 )
    {
      ((SOAD_P2VAR(uint8))SoAd_EventQueues(EveQueIdx).EveQuePtr)[writeIdx] = (uint8)HandleIdx;
    }
    else
    {
      ((SOAD_P2VAR(uint16))SoAd_EventQueues(EveQueIdx).EveQuePtr)[writeIdx] = HandleIdx;
    }
    SoAd_EventQueues(EveQueIdx).EveMgtPtr->Lvl++;

    /* set flag to indicate that handle index is in queue */
    SoAd_EventQueueFlags(HandleIdx) |= SoAd_EventQueues(EveQueIdx).EveQueBitPattern;
  }

  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

/**********************************************************************************************************************
 *  SoAd_VEventQueueGetNextElement
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VEventQueueGetNextElement(uint8 EveQueIdx,
                                        P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) HandleIdxPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if ( SoAd_EventQueues(EveQueIdx).EveMgtPtr->Lvl > 0u )
  {
    /* get next element */
    if ( SoAd_EventQueues(EveQueIdx).EveQueType == SOAD_QUEUE_LIST_TYPE_UINT8 )
    {
      *HandleIdxPtr = ((SOAD_P2VAR(uint8))SoAd_EventQueues(EveQueIdx).EveQuePtr)[
        SoAd_EventQueues(EveQueIdx).EveMgtPtr->Idx];
    }
    else
    {
      *HandleIdxPtr = ((SOAD_P2VAR(uint16))SoAd_EventQueues(EveQueIdx).EveQuePtr)[
        SoAd_EventQueues(EveQueIdx).EveMgtPtr->Idx];
    }

    /* remove element from queue */
    if ( (SoAd_EventQueues(EveQueIdx).EveMgtPtr->Idx + 1u) == SoAd_EventQueues(EveQueIdx).EveQueSize)
    { /* wrap around */
      SoAd_EventQueues(EveQueIdx).EveMgtPtr->Idx = 0u;
    }
    else
    { /* no wrap around */
      SoAd_EventQueues(EveQueIdx).EveMgtPtr->Idx++;
    }
    SoAd_EventQueues(EveQueIdx).EveMgtPtr->Lvl--;

    /* reset event flag for handle index */
    SoAd_EventQueueFlags(*HandleIdxPtr) &= (SoAd_EventQueueFlagType)(~SoAd_EventQueues(EveQueIdx).EveQueBitPattern);

    retVal = E_OK;
  }

  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return retVal;
}

#if ( (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) || (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) )
/**********************************************************************************************************************
 *  SoAd_VTimeoutListsClear
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VTimeoutListsClear(void)
{
  uint8 timeListIdx;

  for ( timeListIdx = 0u; timeListIdx < SoAd_TimeoutListTotal(); timeListIdx++ )
  {
    SoAd_TimeoutLists(timeListIdx).TimeMgtPtr->Lvl = 0u;
    if ( SoAd_TimeoutLists(timeListIdx).TimeListType == SOAD_QUEUE_LIST_TYPE_UINT8 )
    {
      uint8 mapIdx;

      for ( mapIdx = 0u; mapIdx < SoAd_TimeoutLists(timeListIdx).TimeListIdxMapSize; mapIdx++ )
      {
        ((SOAD_P2VAR(uint8))SoAd_TimeoutLists(timeListIdx).TimeListIdxMapPtr)[mapIdx] = SOAD_INV_HND_8;
      }
    }
    else
    {
      uint16 mapIdx;

      for ( mapIdx = 0u; mapIdx < SoAd_TimeoutLists(timeListIdx).TimeListIdxMapSize; mapIdx++ )
      {
        ((SOAD_P2VAR(uint16))SoAd_TimeoutLists(timeListIdx).TimeListIdxMapPtr)[mapIdx] = SOAD_INV_HND_16;
      }
    }
  }
}

/**********************************************************************************************************************
 *  SoAd_VTimeoutListSetElement
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTimeoutListSetElement(uint8 TimeListIdx, uint16 HandleIdx,
                                        uint32 Timeout, uint32 TimerCounter)
{
  Std_ReturnType retVal = E_NOT_OK;

  SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if ( SoAd_TimeoutLists(TimeListIdx).TimeListType == SOAD_QUEUE_LIST_TYPE_UINT8 )
  { /* HandleIdx is of type uint8 */
    uint8 mapIdx = ((SOAD_P2VAR(uint8))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx];

    if ( mapIdx == SOAD_INV_HND_8 )
    { /* HandleIdx not in list */
      if ( SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl < SoAd_TimeoutLists(TimeListIdx).TimeListSize )
      { /* list size is sufficient for new element */
        /* add element */
        ((SOAD_P2VAR(SoAd_TimeoutListElem8Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
          SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl].HandleIdx = (uint8)HandleIdx;
        ((SOAD_P2VAR(SoAd_TimeoutListElem8Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
          SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl].Timeout = (uint32)(TimerCounter + Timeout);

        ((SOAD_P2VAR(uint8))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx] =
          (uint8)SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl;

        SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl++;

        retVal = E_OK;
      }
    }
    else
    { /* HandleIdx already in list */
      /* update timeout count in element */
      ((SOAD_P2VAR(SoAd_TimeoutListElem8Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
        mapIdx].Timeout = (uint32)(TimerCounter + Timeout);

      retVal = E_OK;
    }
  }
  else
  { /* HandleIdx is of type uint16 */
    uint16 mapIdx = ((SOAD_P2VAR(uint16))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx];

    if ( mapIdx == SOAD_INV_HND_16 )
    { /* HandleIdx not in list */
      if ( SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl < SoAd_TimeoutLists(TimeListIdx).TimeListSize )
      { /* list size is sufficient for new element */
        /* add element */
        ((SOAD_P2VAR(SoAd_TimeoutListElem16Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
          SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl].HandleIdx = HandleIdx;
        ((SOAD_P2VAR(SoAd_TimeoutListElem16Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
          SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl].Timeout = (uint32)(TimerCounter + Timeout);

        ((SOAD_P2VAR(uint16))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx] =
          SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl;

        SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl++;

        retVal = E_OK;
      }
    }
    else
    { /* HandleIdx already in list */
      /* update timeout count in element */
      ((SOAD_P2VAR(SoAd_TimeoutListElem16Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
        mapIdx].Timeout = (uint32)(TimerCounter + Timeout);

      retVal = E_OK;
    }
  }

  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return retVal;
}

/**********************************************************************************************************************
 *  SoAd_VTimeoutListGetCurrentTimeout
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTimeoutListGetCurrentTimeout(uint8 TimeListIdx, uint16 HandleIdx,
                                        P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) TimeoutPtr, uint32 TimerCounter)
{
  Std_ReturnType retVal = E_NOT_OK;

  SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if ( SoAd_TimeoutLists(TimeListIdx).TimeListType == SOAD_QUEUE_LIST_TYPE_UINT8 )
  { /* HandleIdx is of type uint8 */
    uint8 mapIdx = ((SOAD_P2VAR(uint8))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx];

    if ( mapIdx != SOAD_INV_HND_8 )
    { /* HandleIdx is in list */
      /* retrieve timeout count from element */
      uint32 currentTimeout = ((SOAD_P2VAR(SoAd_TimeoutListElem8Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
        mapIdx].Timeout;

      if ( currentTimeout >= TimerCounter )
      { /* no timer counter overflow */
        *TimeoutPtr = (uint32)(currentTimeout - TimerCounter);
      }
      else
      { /* timer counter overflow */
        *TimeoutPtr = (uint32)(currentTimeout + (SOAD_MAX_TIMEOUT_32 - TimerCounter));
      }

      retVal = E_OK;
    }
  }
  else
  { /* HandleIdx is of type uint16 */
    uint16 mapIdx = ((SOAD_P2VAR(uint16))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx];

    if ( mapIdx != SOAD_INV_HND_16 )
    { /* HandleIdx is in list */
      /* retrieve timeout count from element */
      uint32 currentTimeout = ((SOAD_P2VAR(SoAd_TimeoutListElem16Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
        mapIdx].Timeout;

      if ( currentTimeout >= TimerCounter )
      { /* no timer counter overflow */
        *TimeoutPtr = (uint32)(currentTimeout - TimerCounter);
      }
      else
      { /* timer counter overflow */
        *TimeoutPtr = (uint32)(currentTimeout + (SOAD_MAX_TIMEOUT_32 - TimerCounter));
      }

      retVal = E_OK;
    }
  }

  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return retVal;
}

/**********************************************************************************************************************
 *  SoAd_VTimeoutListCheckElements
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTimeoutListCheckElements(uint8 TimeListIdx,
                                        P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) ElementIdxPtr,
                                        P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) HandleIdxPtr,
                                        uint32 TimerCounter)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint16_least elementIdx;
  
  if ( SoAd_TimeoutLists(TimeListIdx).TimeListType == SOAD_QUEUE_LIST_TYPE_UINT8 )
  { /* HandleIdx is of type uint8 */
    /* search for timeout */
    for ( elementIdx = *ElementIdxPtr; elementIdx < SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl; elementIdx++ )
    {
      if ( ((SOAD_P2VAR(SoAd_TimeoutListElem8Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[elementIdx].Timeout ==
        TimerCounter )
      { /* timeout occured */
        *ElementIdxPtr = (uint16)elementIdx;
        *HandleIdxPtr = ((SOAD_P2VAR(SoAd_TimeoutListElem8Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
          elementIdx].HandleIdx;
        retVal = E_OK;
        break;
      }
    }
  }
  else
  { /* HandleIdx is of type uint16 */
    /* search for timeout */
    for ( elementIdx = *ElementIdxPtr; elementIdx < SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl; elementIdx++ )
    {
      if ( ((SOAD_P2VAR(SoAd_TimeoutListElem16Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[elementIdx].Timeout ==
        TimerCounter )
      { /* timeout occured */
        *ElementIdxPtr = (uint16)elementIdx;
        *HandleIdxPtr = ((SOAD_P2VAR(SoAd_TimeoutListElem16Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr)[
          elementIdx].HandleIdx;
        retVal = E_OK;
        break;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  SoAd_VTimeoutListRemoveElement
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VTimeoutListRemoveElement(uint8 TimeListIdx, uint16 HandleIdx)
{
  SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if ( SoAd_TimeoutLists(TimeListIdx).TimeListType == SOAD_QUEUE_LIST_TYPE_UINT8 )
  { /* HandleIdx is of type uint8 */
    uint8 elementIdx = ((SOAD_P2VAR(uint8))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx];

    if ( elementIdx != SOAD_INV_HND_8 )
    { /* HandleIdx is valid */
      uint16 lastIdx;

      /* remove element */
      SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl--;
      ((SOAD_P2VAR(uint8))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx] = SOAD_INV_HND_8;

      /* replace element */
      /* get index of last element in list (lvl is already decremented so lvl is last index) */
      lastIdx = SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl;
      /* replace */
      if ( (lastIdx > 0u) && (lastIdx != elementIdx) )
      {
        SOAD_P2VAR(SoAd_TimeoutListElem8Type) timeListPtr =
          ((SOAD_P2VAR(SoAd_TimeoutListElem8Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr);

        /* replace at index */
        timeListPtr[elementIdx].HandleIdx = timeListPtr[lastIdx].HandleIdx;
        timeListPtr[elementIdx].Timeout = timeListPtr[lastIdx].Timeout;

        /* update map of replacing element */
        ((SOAD_P2VAR(uint8))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[timeListPtr[lastIdx].HandleIdx] =
          elementIdx;
      }
    }
  }
  else
  { /* HandleIdx is of type uint16 */
    uint16 elementIdx = ((SOAD_P2VAR(uint16))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx];

    if ( elementIdx != SOAD_INV_HND_16 )
    { /* HandleIdx is valid */
      uint16 lastIdx;

      /* remove element */
      SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl--;
      ((SOAD_P2VAR(uint16))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[HandleIdx] = SOAD_INV_HND_16;

      /* replace element */
      /* get index of last element in list (lvl is already decremented so lvl is last index) */
      lastIdx = SoAd_TimeoutLists(TimeListIdx).TimeMgtPtr->Lvl;
      /* replace */
      if ( (lastIdx > 0u) && (lastIdx != elementIdx) )
      {
        SOAD_P2VAR(SoAd_TimeoutListElem16Type) timeListPtr =
          ((SOAD_P2VAR(SoAd_TimeoutListElem16Type))SoAd_TimeoutLists(TimeListIdx).TimeListPtr);

        /* replace at index */
        timeListPtr[elementIdx].HandleIdx = timeListPtr[lastIdx].HandleIdx;
        timeListPtr[elementIdx].Timeout = timeListPtr[lastIdx].Timeout;

        /* update map of replacing element */
        ((SOAD_P2VAR(uint16))SoAd_TimeoutLists(TimeListIdx).TimeListIdxMapPtr)[timeListPtr[lastIdx].HandleIdx] =
          elementIdx;
      }
    }
  }

  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}
#endif /* (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) || (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) */

#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
/**********************************************************************************************************************
 *  SoAd_VAddPendingIfTxConf
 *********************************************************************************************************************/
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VAddPendingIfTxConf(SoAd_PduIdxType TxPduIdx,
                                  SoAd_SoConIdxType SoConIdx)
{
  if ( TRUE == SoAd_TxPduIdx2PduRoute(TxPduIdx).TxConfEnabled )
  { /* TxConfirmation is enabled */
    if ( SoAd_TxPduIdx2PduRoute(TxPduIdx).UpperLayer == SOAD_UL_TYPE_IF )
    { /* IF-API */
      if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr != NULL_PTR )
      { /* UDP */
# if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
        if ( SoAd_IsNPduUdpTxPresent() && (SoAd_SockConIdx2NPduUdpTxIdx(SoConIdx) != SOAD_INV_BUF_IDX_16) &&
          (SoAd_TxPduIdx2PduRoute(TxPduIdx).IfTriggerTransmitEnabled == TRUE) )
        { /* nPdu queue is used */
          /* to be confirmed after corresponding trigger transmit calls */
          SoAd_TxPduIdx2PendingTxConf(TxPduIdx)++;
        }
        else
# endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
# if ( defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) )
        if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->ImmedIfTxConf == FALSE )
# endif /* defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) */
        { /* UdpImmediateIfTxConfirmation disabled (according to AUTOSAR) */
          /* to be confirmed in main function context - set main function flag (may be set multiple times if multiple
           * PduRoutesDests are configured with this confirmation strategy) */
          SoAd_TxPduIdx2PendingTxConf(TxPduIdx) |= SOAD_TX_CONF_STRAT_BIT_PAT_MAIN;
          /* set event to handle TxConfirmation in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxIfUdpPduRoute(), TxPduIdx);
        }
# if ( (SOAD_VUDP_IMMED_IF_TX_CONF == STD_ON) && (SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON) )
        else
        {
          /* nothing to do */
        }
# endif /* (SOAD_VUDP_IMMED_IF_TX_CONF == STD_ON) && (SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON) */
      }
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
      else
      { /* TCP */
        /* to be confirmed in SoAd_TxConfirmation() context - increment pending confirmation counter */
        SoAd_TxPduIdx2PendingTxConf(TxPduIdx)++;
      }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
    }
  }
}
/* PRQA L:MSR_STMIF */

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
/**********************************************************************************************************************
 *  SoAd_VTcpTxQueueReserveNextElement
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpTxQueueReserveNextElement(SoAd_SoConIdxType SoConIdx,
                                  SoAd_PduIdxType TxPduIdx)
{
  SOAD_P2CONST(SoAd_SocketConnectionType) soConPtr = &SoAd_SockCons(SoConIdx);
  Std_ReturnType retVal = E_NOT_OK;
  uint16 idx, lvl, size, writeIdx;

  if ( NULL_PTR != soConPtr->TcpTxQueuePtr )
  {
    SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    idx  = soConPtr->TcpTxQueuePtr->MgtPtr->Idx;
    lvl  = soConPtr->TcpTxQueuePtr->MgtPtr->Lvl;
    size = soConPtr->TcpTxQueuePtr->Size;

    if ( lvl < size )
    { /* free elements left */
      if ( 0u < lvl )
      { /* check whether last entry is reserved */
        uint16 lastLvl = (uint16)(lvl - 1u);

        /* find last used entry in Tx Queue */
        if ( (idx + lastLvl) >= size )
        { /* wrap around necessary */
          writeIdx = lastLvl - (size - idx);
        }
        else
        { /* no wrap around necessary */
          writeIdx = idx + lastLvl;
        }
        /* check last entry */
        if ( 0u != soConPtr->TcpTxQueuePtr->QueuePtr[writeIdx].Len )
        { /* last entry is completely written - new entry is possible */
          if ( (writeIdx + 1) == size )
          { /* wrap around necessary */
            writeIdx = 0u;
          }
          else
          { /* no wrap around necessary */
            writeIdx++;
          }
          retVal = E_OK;
        }
      }
      else
      { /* no last entry is available */
        writeIdx = idx;
        retVal = E_OK;
      }

      if ( E_OK == retVal )
      { /* new entry is possible - reserve element */
        soConPtr->TcpTxQueuePtr->MgtPtr->Lvl++;
        soConPtr->TcpTxQueuePtr->QueuePtr[writeIdx].TxPduIdx = TxPduIdx;
        soConPtr->TcpTxQueuePtr->QueuePtr[writeIdx].Len = 0u;
      }
    }
    SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VTcpTxQueueSetElement
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VTcpTxQueueSetElement(SoAd_SoConIdxType SoConIdx, SoAd_PduIdxType TxPduIdx,
                                  PduLengthType Len, boolean Free)
{
  SOAD_P2CONST(SoAd_SocketConnectionType) soConPtr = &SoAd_SockCons(SoConIdx);

  if ( NULL_PTR != soConPtr->TcpTxQueuePtr )
  {
    uint16 idx, lvl, size, writeIdx;

    SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    idx  = soConPtr->TcpTxQueuePtr->MgtPtr->Idx;
    lvl  = soConPtr->TcpTxQueuePtr->MgtPtr->Lvl;
    size = soConPtr->TcpTxQueuePtr->Size;

    if ( 0u < lvl )
    {
      /* find last used entry in Tx Queue */
      lvl--;
      if ( (idx + lvl) >= size )
      { /* wrap around necessary */
        writeIdx = lvl - (size - idx);
      }
      else
      { /* no wrap around necessary */
        writeIdx = idx + lvl;
      }

      if ( TxPduIdx == soConPtr->TcpTxQueuePtr->QueuePtr[writeIdx].TxPduIdx )
      { /* element is reserved for the requested PDU */
        if ( TRUE == Free )
        { /* free reserved element */
          /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
          soConPtr->TcpTxQueuePtr->QueuePtr[writeIdx].TxPduIdx = SOAD_INV_PDU_IDX;
          soConPtr->TcpTxQueuePtr->MgtPtr->Lvl--;
        }
        else
        { /* write reserved element */
          soConPtr->TcpTxQueuePtr->QueuePtr[writeIdx].Len = Len;
        }
      }
    }
    SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */

# if ( (defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED)) || \
  (defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF)) )
/**********************************************************************************************************************
 *  SoAd_VReconnectSockCon
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VReconnectSockCon(SoAd_SoConIdxType SoConIdx)
{
  if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SockAutoSoConSetup == TRUE )
  {
    if ( (SOAD_SOCON_IP_ANY_PORT_ANY >= SoAd_SockConIdx2RemAddrState(SoConIdx)) && 
      (0u != (SoAd_SockCons(SoConIdx).RemAddrState & SOAD_SOCON_MASK_ANY)) )
    { /* reset remote socket and reconnect socket connection */
      SoAd_VResetIpAddr(SoConIdx);
#  if ( defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) )
      if ( NULL_PTR != SoAd_SockCons(SoConIdx).RcvRemSockPtr )
      { /* get received remote address is supported */
        /* reset remote address */
        SoAd_VResetIpAddr2Unspec(SoAd_SockCons(SoConIdx).RcvRemSockPtr);
      }
#  endif /* defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) */
      SoAd_SockConIdx2State(SoConIdx) = SOAD_SOCON_RECONNECT;
      /* set event to handle socket connection state in main function */
      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
      /* inform upper layer about socket connection state change */
      SoAd_VCallChgFunc(SoConIdx, SoAd_SockCons(SoConIdx).SoConChgFuncBitPattern,
        SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(SoConIdx));
    }
  }
}
# endif /* (defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED)) || \
  (defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF)) */

# if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
#  if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
/**********************************************************************************************************************
 *  SoAd_VUpdatePduHdrLen
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_VUpdatePduHdrLen(SoAd_PduHdrLenType PduHeaderLen,
                                  P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr)
{
  BufPtr[4] = (uint8)(PduHeaderLen >> 24);
  BufPtr[5] = (uint8)(PduHeaderLen >> 16);
  BufPtr[6] = (uint8)(PduHeaderLen >> 8);
  BufPtr[7] = (uint8)(PduHeaderLen);
}
#  endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
# endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SoAd_InitMemory
 *********************************************************************************************************************/
/*! \brief      initializes global variables
 *  \pre        has to be called before any other calls to the module
 *  \context    initialization
 *  \note       AUTOSAR extension
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_InitMemory(void)
{
  SoAd_State = SOAD_STATE_UNINIT;
#if (SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SOAD_CONFIGURATION_VARIANT)
  SoAd_ConfigPtr = NULL_PTR;
#endif /* (SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SOAD_CONFIGURATION_VARIANT) */
}

/**********************************************************************************************************************
 *  SoAd_Init
 *********************************************************************************************************************/
/*! \brief      stores the start address of the post build time configuration of the module
 *              and may be used to initialize the data structures
 *  \param[in]  SoAdConfigPtr       pointer to module configuration
 *  \pre        has to be called before useage of the module
 *  \context    initialization
 *********************************************************************************************************************/
/* PRQA S 3206 1 */ /* MD_SoAd_3206 */
FUNC(void, SOAD_CODE) SoAd_Init(P2CONST(SoAd_ConfigType, AUTOMATIC, SOAD_CONST) SoAdConfigPtr)
{
  /* PRQA S 0781 1 */ /* MD_SoAd_5.6 */
  uint16 idx;

#if (SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SOAD_CONFIGURATION_VARIANT)
  /* Save the config pointer */
  SoAd_ConfigPtr = SoAdConfigPtr;

  /* Check validity of config pointer */
  if ( SoAd_ConfigPtr == NULL_PTR )
  {
    EcuM_BswErrorHook((uint16) SOAD_MODULE_ID, (uint8) ECUM_BSWERROR_NULLPTR);

    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    SOAD_CallDetReportError(SOAD_API_ID_INIT, SOAD_E_PARAM_POINTER);
    return;
  }

  if ( SOAD_FINAL_MAGIC_NUMBER != SoAd_ConfigPtr->FinalMagicNumber )
  {
    EcuM_BswErrorHook((uint16) SOAD_MODULE_ID, (uint8) ECUM_BSWERROR_MAGICNUMBER);
    return;
  }
#else
  SOAD_DUMMY_STATEMENT_VAR(SoAdConfigPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif /* (SOAD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SOAD_CONFIGURATION_VARIANT) */

#if ( (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) || (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) )
  SoAd_GlobalCounter = 0u;
#endif /* (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) || (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) */

  SoAd_CriticalSectionCount = 0u;
  SoAd_OpenSocks = 0u;
  SoAd_ShutdownFinishedCnt = 0u;

  /* initialize RAM structs */
  SoAd_VEventQueuesClear();
#if ( (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) || (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) )
  SoAd_VTimeoutListsClear();
#endif /* (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) || (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) */
  for (idx = 0u; idx < SoAd_TcpIpSocketCnt(); idx++)
  {
    SoAd_SoConIdxType soConIdx = SoAd_SockIdx2SoConIdxCol(idx).SoConIdxStart;

    SoAd_SockIdx2SockState(idx)      = SOAD_SOCK_STATE_CLOSED;
    SoAd_SockIdx2SocketId(idx)       = SOAD_INV_SOCKET_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
    if ( 0 != SoAd_PduRouteTotal() )
    {
      SoAd_SockIdx2ActiveSoConIdx(idx)  = SOAD_INV_SO_CON_IDX;
    }
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
    if ( SoAd_IsSockRoutePresent() )
    {
      SoAd_SockIdx2SkipBytes(idx)      = 0u;
    }
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
    SoAd_SockIdx2LocPortDyn(idx)     = SoAd_SockCons(soConIdx).SockConGrpPtr->LocalPort;
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
    SoAd_SockIdx2RxMgt(idx).Len      = 0u;
    SoAd_SockIdx2RxMgt(idx).Offset   = 0u;
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
  }
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  for (idx = 0u; idx < SoAd_PduRouteTotal(); idx++)
  {
    SoAd_TxPduIdx2PendingTxConf(idx) = 0u;
  }
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
  for (idx = 0u; idx < SoAd_SockConTotal(); idx++)
  {
    SoAd_SockConIdx2State(idx)                          = SOAD_SOCON_OFFLINE;
    SoAd_SockConIdx2IpAddrState(idx)                    = SOAD_IPADDR_STATE_UNASSIGNED;
    SoAd_SockConIdx2FlagAbort(idx)                      = FALSE;
    SoAd_SockConIdx2CloseMode(idx)                      = SOAD_CLOSE_NONE;
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
    if ( 0 != SoAd_PduRouteTotal() )
    {
      SoAd_SockConIdx2TxMgt(idx).TxPduIdx                 = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
      SoAd_SockConIdx2TxMgt(idx).TxBytesPending           = 0u;
      SoAd_SockConIdx2TxMgt(idx).TxBytesLen               = 0u;
      SoAd_SockConIdx2TxMgt(idx).TxBufPtr                 = NULL_PTR;
      SoAd_SockConIdx2TxMgt(idx).CancelRequested          = FALSE;
    }
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
    if ( SoAd_IsSockRoutePresent() )
    {
      SoAd_SockConIdx2RxMgt(idx).RouteIdx                 = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
      SoAd_SockConIdx2RxMgt(idx).RxBytesPending           = 0u;
      SoAd_SockConIdx2RxMgt(idx).BufSegMgt.Idx            = 0u;
      SoAd_SockConIdx2RxMgt(idx).BufSegMgt.Lvl            = 0u;
      SoAd_SockConIdx2RxMgt(idx).CancelRequested          = FALSE;
      if ( SoAd_SockConIdx2RxBuffer(idx).IfRxBufferOffsetPtr != NULL_PTR )
      {
        *SoAd_SockConIdx2RxBuffer(idx).IfRxBufferOffsetPtr = 0u;
      }
      if ( SoAd_SockConIdx2RxBuffer(idx).TpRxBufferOffsetPtr != NULL_PTR )
      {
        *SoAd_SockConIdx2RxBuffer(idx).TpRxBufferOffsetPtr = 0u;
      }
    }
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
    SoAd_SockConIdx2FlagCntOpCl(idx) = 0u;
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
# if ( defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) )
    if ( SoAd_IsSockConIdx2TxBufferPresent() && (NULL_PTR != SoAd_SockConIdx2TxBuffer(idx).TpTxBufferOffsetPtr) )
    {
      *SoAd_SockConIdx2TxBuffer(idx).TpTxBufferOffsetPtr = 0u;
    }
# endif /* defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) */
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
    if ( NULL_PTR != SoAd_SockCons(idx).TcpTxQueuePtr )
    {
      uint16 idx2 = SoAd_SockCons(idx).TcpTxQueuePtr->Size;

      SoAd_SockCons(idx).TcpTxQueuePtr->MgtPtr->Idx = 0u;
      SoAd_SockCons(idx).TcpTxQueuePtr->MgtPtr->Lvl = 0u;
      while ( 0u < idx2 )
      {
        idx2--;
        SoAd_SockCons(idx).TcpTxQueuePtr->QueuePtr[idx2].TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
        SoAd_SockCons(idx).TcpTxQueuePtr->QueuePtr[idx2].Len = 0u;
      }
    }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */

    SoAd_VResetIpAddr((SoAd_SoConIdType)idx);
#if ( defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) )
    if ( NULL_PTR != SoAd_SockCons(idx).RcvRemSockPtr )
    { /* get received remote address is supported */
      /* reset remote address */
      SoAd_VResetIpAddr2Unspec(SoAd_SockCons(idx).RcvRemSockPtr);
    }
#endif /* defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) */
  }
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_ENABLED) )
  for (idx = 0u; idx < SoAd_RouteGrpTotal(); idx++)
  {
# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
    uint16 pduDestNum = 0;
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */
# if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
    uint16 sockRouteNum = 0;
# endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */

# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
    if ( SoAd_IsRouteGrpIdx2PduRouteDestColPresent() )
    {
      pduDestNum = SoAd_RouteGrpIdx2PduRouteDestCol(idx).PduRouteDestListSize;
    }
    while ( 0u < pduDestNum )
    {
      pduDestNum--;
      if ( SoAd_RouteGrpIdx2RoutingGroup(idx).IsEnabledAtInit == TRUE )
      {
        *SoAd_RouteGrpIdx2PduRouteDestCol(idx).StateColPtr[pduDestNum] = SOAD_ROUT_GRP_BIT_PATTERN_ENABLED;
      }
      else
      {
        *SoAd_RouteGrpIdx2PduRouteDestCol(idx).StateColPtr[pduDestNum] = SOAD_ROUT_GRP_BIT_PATTERN_NONE;
      }
    }
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */

# if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
    if ( SoAd_IsRouteGrpIdx2SocketRouteColPresent() )
    {
      sockRouteNum = SoAd_RouteGrpIdx2SocketRouteCol(idx).IdNum;
    }
    while ( 0u < sockRouteNum )
    {
      sockRouteNum--;
      if ( SoAd_RouteGrpIdx2RoutingGroup(idx).IsEnabledAtInit == TRUE )
      {
        *SoAd_RouteGrpIdx2SocketRouteCol(idx).StateColPtr[sockRouteNum] = SOAD_ROUT_GRP_BIT_PATTERN_ENABLED;
      }
      else
      {
        *SoAd_RouteGrpIdx2SocketRouteCol(idx).StateColPtr[sockRouteNum] = SOAD_ROUT_GRP_BIT_PATTERN_NONE;
      }
    }
# endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
  }
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_ENABLED) */
#if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
  if ( SoAd_IsNPduUdpTxPresent() )
  {
    for ( idx = 0u; idx < SoAd_SockConIdx2NPduUdpTxIdxSize(); idx++ )
    {
      SoAd_VNPduClear(idx);
    }
  }
#endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
  for (idx = 0u; idx < SOAD_VADDR_ID_TOTAL; idx++)
  {
    if ( SoAd_LocalAddr(idx).AssignTrigger == SOAD_ASSIGN_TRIGGER_AUTOMATIC )
    {
      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), idx);
    }
    SoAd_AddrId2LocalIpAddrReqState(idx) = SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE;
    SoAd_VResetLocalIpAddr(idx);
  }
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

  /* update SoAd state */
  SoAd_State = SOAD_STATE_INIT;
} /* PRQA S 6010 */ /* MD_MSR_STPTH */ /* PRQA S 6030 */ /* MD_MSR_STCYC */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_IfTransmit
 *********************************************************************************************************************/
/*! \brief      this service initiates a request for transmission of the PDU specified by SoAdSrcPduId over IF-API
 *  \param[in]  SoAdSrcPduId          PDU identifier
 *  \param[in]  SoAdSrcPduInfoPtr     pointer struct to data length and pointer to data buffer
 *  \return     E_OK                  transmission requested
 *  \return     E_NOT_OK              transmission request failed
 *  \context    task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfTransmit(PduIdType SoAdSrcPduId,
                                  P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) SoAdSrcPduInfoPtr)
{
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  Std_ReturnType    retVal = E_OK;
  SoAd_PduIdxType   pduRouteIdx;
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 6 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_IF_TRANSMIT, SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_GetPduRouteIdxCheckDetErrorReturnValue(pduRouteIdx, SoAdSrcPduId, SOAD_API_ID_IF_TRANSMIT, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != SoAdSrcPduInfoPtr), SOAD_API_ID_IF_TRANSMIT, SOAD_E_PARAM_POINTER,
    E_NOT_OK);

  if ( SOAD_STATE_INIT != SoAd_State )
  {
    retVal = E_NOT_OK;
  }

  /* validate upper layer */
  if ( SoAd_TxPduIdx2PduRoute(pduRouteIdx).UpperLayer != SOAD_UL_TYPE_IF )
  { /* upper layer type is inconsistent for this PduId */
    SOAD_CallDetReportError(SOAD_API_ID_IF_TRANSMIT, SOAD_E_INV_ARG);
    retVal = E_NOT_OK;
  }

  /* validate buffer pointer */
# if ( SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON )
  if ( SoAd_TxPduIdx2PduRoute(pduRouteIdx).IfTriggerTransmitEnabled == FALSE )
# endif /* SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON */
  {
    SOAD_CheckDetErrorReturnValue((NULL_PTR != SoAdSrcPduInfoPtr->SduDataPtr), SOAD_API_ID_IF_TRANSMIT, SOAD_E_INV_ARG,
      E_NOT_OK);
  }

  /* validate length */
# if ( (SOAD_VPDU_HDR_ENABLED == STD_ON) || (SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON) )
  soConIdx = (*SoAd_TxPduIdx2PduRoute(pduRouteIdx).PduRouteDestListPtr)->SoConIdx;
# endif /* (SOAD_VPDU_HDR_ENABLED == STD_ON) || (SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON) */

# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == FALSE )
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
  {
    if ( 0u == SoAdSrcPduInfoPtr->SduLength )
    { /* requested length is 0, this is prohibited by AUTOSAR specification */
      retVal = E_NOT_OK;
    }
  }

# if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
  if ( (!SoAd_IsNPduUdpTxPresent()) || (SoAd_SockConIdx2NPduUdpTxIdx(soConIdx) == SOAD_INV_BUF_IDX_16) ||
    (SoAd_TxPduIdx2PduRoute(pduRouteIdx).IfTriggerTransmitEnabled == FALSE) )
# endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
  {
    /* check for pending TxConfirmation */
    if ( 0u != SoAd_TxPduIdx2PendingTxConf(pduRouteIdx) )
    { /* TxConfirmation is pending */
      retVal = E_NOT_OK;
      /* switch off IF TxConfirmation if faster transmission is required */
    }
  }

  if ( E_NOT_OK != retVal )
  { /* all checks successful */
    uint16 pduRouteDestIdx = 0u;
    uint16 pduRouteDestNum = SoAd_TxPduIdx2PduRoute(pduRouteIdx).PduRouteDestListSize;
    uint16 pduRouteDestsDisabled = 0u;

    /* send over all configured PduRouteDests of this PduRoute (PDU fan-out) */
    while ( pduRouteDestIdx < pduRouteDestNum )
    {
      P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_VAR) pduRouteDestPtr =
        SoAd_TxPduIdx2PduRoute(pduRouteIdx).PduRouteDestListPtr[pduRouteDestIdx];

      soConIdx = pduRouteDestPtr->SoConIdx;

# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
      if ( FALSE == SoAd_VCheckAnyRoutGrpOnPduRouteDestEnabled(pduRouteDestPtr) )
      { /* all routing groups for this socket route destination are disabled */
        /* discard PDU for this socket route destination but consider that transmission is successful */
        /* count all disabled PduRouteDests */
        pduRouteDestsDisabled++;
      }
      else
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */
      {
        retVal |= SoAd_VIfTransmit(soConIdx, SoAdSrcPduInfoPtr, pduRouteDestPtr);
      }

      /* switch to next PDU Route destination */
      pduRouteDestIdx++;
    }

    if ( SoAd_TxPduIdx2PduRoute(pduRouteIdx).PduRouteDestListSize == pduRouteDestsDisabled )
    { /* all PduRouteDests are disabled */
      /* return E_NOT_OK */
      retVal = E_NOT_OK;
    }
  }

  return retVal;
#else
  SOAD_DUMMY_STATEMENT_VAR(SoAdSrcPduId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(SoAdSrcPduInfoPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_IF_TRANSMIT, SOAD_E_NOTINIT, E_NOT_OK);

  /* no PDUs for transmission configured */
  SOAD_CallDetReportError(SOAD_API_ID_IF_TRANSMIT, SOAD_E_INV_ARG);
  return E_NOT_OK;
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
} /* PRQA S 6010 */ /* MD_MSR_STPTH */ /* PRQA S 6030 */ /* MD_MSR_STCYC */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_IfRoutingGroupTransmit
 *********************************************************************************************************************/
/*! \brief      triggers the transmission of all PDUs relating to a routing group id over a TriggerTransmit request
 *  \param[in]  id        Routing Group ID
 *  \return     E_OK      request successful
 *  \return     E_NOT_OK  request not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfRoutingGroupTransmit(SoAd_RoutingGroupIdType id)
{
#if ( defined(SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) && (STD_ON == SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) )
# if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  Std_ReturnType retVal = E_OK;
  uint16 pduDestNum = 0;
  SoAd_RoutingGroupIdxType routeGrpIdx;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_IF_ROUT_GROUP_TRANSMIT,
    SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_GetRouteGrpIdxCheckDetErrorReturnValue(routeGrpIdx, id, SOAD_API_ID_IF_ROUT_GROUP_TRANSMIT, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((TRUE == SoAd_RouteGrpIdx2RoutingGroup(routeGrpIdx).TxTriggerable),
    SOAD_API_ID_IF_ROUT_GROUP_TRANSMIT, SOAD_E_INV_ARG, E_NOT_OK);

  if ( SOAD_STATE_INIT != SoAd_State )
  {
    retVal = E_NOT_OK;
  }
  else
  {
    if ( SoAd_IsRouteGrpIdx2PduRouteDestColPresent() )
    {
      pduDestNum = SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).PduRouteDestListSize;
    }

    /* save trigger transmit request on all socket connections */
    while ( 0u < pduDestNum )
    {
      pduDestNum--;
      *SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).StateColPtr[pduDestNum] |= SOAD_ROUT_GRP_BIT_PATTERN_TRIGGER;
    }

    /* set event to handle routing group transmit in main function */
    SoAd_VEventQueueAddElement(SoAd_EventQueueIdxIfTxRouteGrp(), routeGrpIdx);
  }

  return retVal;
# else
  SOAD_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  /* no PDUs for transmission configured */
  SOAD_CallDetReportError(SOAD_API_ID_IF_ROUT_GROUP_TRANSMIT, SOAD_E_INV_ARG);
  return E_NOT_OK;
# endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#else
  SOAD_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_IF_ROUT_GROUP_TRANSMIT,
    SOAD_E_NOTINIT, E_NOT_OK);

  /* IfRoutingGroupTransmit is not configured */
  SOAD_CallDetReportError(SOAD_API_ID_IF_ROUT_GROUP_TRANSMIT, SOAD_E_INV_ARG);
  return E_NOT_OK;
#endif /* defined(SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) && (STD_ON == SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STCYC */

/**********************************************************************************************************************
 *  SoAd_IfSpecificRoutingGroupTransmit
 *********************************************************************************************************************/
/*! \brief      triggers the transmission on PduRouteDests with specific routing group id and socket connection over
                a TriggerTransmit request
 *  \param[in]  id        Routing Group ID
 *  \param[in]  SoConId   Socket Connection ID
 *  \return     E_OK      request successful
 *  \return     E_NOT_OK  request not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfSpecificRoutingGroupTransmit(SoAd_RoutingGroupIdType id,
                                  SoAd_SoConIdType SoConId )
{
#if ( defined(SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) && (STD_ON == SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) )
# if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  uint16 pduDestNum = 0;
  SoAd_RoutingGroupIdxType routeGrpIdx;
  SoAd_SoConIdxType soConIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* PRQA S 3109 6 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_IF_SPEC_ROUT_GROUP_TRANSMIT,
    SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_GetRouteGrpIdxCheckDetErrorReturnValue(routeGrpIdx, id, SOAD_API_ID_IF_SPEC_ROUT_GROUP_TRANSMIT, E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_IF_SPEC_ROUT_GROUP_TRANSMIT, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((TRUE == SoAd_RouteGrpIdx2RoutingGroup(routeGrpIdx).TxTriggerable),
    SOAD_API_ID_IF_SPEC_ROUT_GROUP_TRANSMIT, SOAD_E_INV_ARG, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
    if ( SoAd_IsRouteGrpIdx2PduRouteDestColPresent() )
    {
      pduDestNum = SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).PduRouteDestListSize;
    }

    /* save trigger transmit request for specific socket connection */
    while ( 0u < pduDestNum )
    {
      pduDestNum--;

      if ( soConIdx == SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).PduRouteDestListPtr[pduDestNum]->SoConIdx )
      {
        *SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).StateColPtr[pduDestNum] |= SOAD_ROUT_GRP_BIT_PATTERN_TRIGGER;
        retVal = E_OK;
        break;
      }
    }

    /* set event to handle routing group transmit in main function */
    SoAd_VEventQueueAddElement(SoAd_EventQueueIdxIfTxRouteGrp(), routeGrpIdx);
  }

  return retVal;
# else
  SOAD_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(SoConId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  /* no PDUs for transmission configured */
  SOAD_CallDetReportError(SOAD_API_ID_IF_SPEC_ROUT_GROUP_TRANSMIT, SOAD_E_INV_ARG);
  return E_NOT_OK;
# endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#else
  SOAD_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(SoConId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_IF_SPEC_ROUT_GROUP_TRANSMIT,
    SOAD_E_NOTINIT, E_NOT_OK);

  /* no PDUs for transmission configured */
  SOAD_CallDetReportError(SOAD_API_ID_IF_SPEC_ROUT_GROUP_TRANSMIT, SOAD_E_INV_ARG);
  return E_NOT_OK;
#endif /* defined(SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) && (STD_ON == SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */

/**********************************************************************************************************************
 *  SoAd_TpTransmit
 *********************************************************************************************************************/
/*! \brief      this service initiates a request for transmission of the PDU specified by SoAdSrcPduId over TP-API
 *  \param[in]  SoAdSrcPduId          PDU identifier
 *  \param[in]  SoAdSrcPduInfoPtr     pointer struct to data length and pointer to data buffer
 *  \return     E_OK                  transmission requested
 *  \return     E_NOT_OK              transmission request failed
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpTransmit(PduIdType SoAdSrcPduId,
                                  P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) SoAdSrcPduInfoPtr)
{
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_DATA) pduRouteDestPtr;
  SoAd_SoConIdxType soConIdx;
  SoAd_PduIdxType pduRouteIdx;
  Std_ReturnType retVal = E_OK;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TP_TRANSMIT, SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != SoAdSrcPduInfoPtr), SOAD_API_ID_TP_TRANSMIT, SOAD_E_PARAM_POINTER, \
    E_NOT_OK);
  SOAD_GetPduRouteIdxCheckDetErrorReturnValue(pduRouteIdx, SoAdSrcPduId, SOAD_API_ID_TP_TRANSMIT, E_NOT_OK);

  if ( SOAD_STATE_INIT != SoAd_State )
  {
    return E_NOT_OK;
  }

  /*lint -e662 -e661 */
  if ( SoAd_TxPduIdx2PduRoute(pduRouteIdx).UpperLayer != SOAD_UL_TYPE_TP ) /*lint +e662 +e661 */
  { /* requested PDU is not a TP PDU */
    SOAD_CallDetReportError(SOAD_API_ID_TP_TRANSMIT, SOAD_E_INV_PDUID);
    return E_NOT_OK;
  }

  if ( 0u == SoAdSrcPduInfoPtr->SduLength )
  { /* Pdu length of 0 is not allowed */
    return E_NOT_OK;
  }

  /* there is only one PduRouteDest in a TP PduRoute */
  /*lint -e662 -e661 */
  pduRouteDestPtr = SoAd_TxPduIdx2PduRoute(pduRouteIdx).PduRouteDestListPtr[0]; /*lint +e662 +e661 */
  soConIdx = pduRouteDestPtr->SoConIdx;

# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
  if ( TRUE != SoAd_VCheckAnyRoutGrpOnPduRouteDestEnabled(pduRouteDestPtr) )
  {
    return E_NOT_OK;
  }
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */

# if ( defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) )
  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr != NULL_PTR )
  { /* UDP socket */
    /* check TxBuffer size */
    if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SockTpTxBufMin < SoAdSrcPduInfoPtr->SduLength )
    { /* invalid PDU length */
      return E_NOT_OK;
    }
  }
# endif /* defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) */

  /* validate transmission/reception state and socket state */
  if ( (SOAD_CLOSE_NONE != SoAd_SockConIdx2CloseMode(soConIdx)) ||
    (SOAD_SOCON_ONLINE != SoAd_SockConIdx2State(soConIdx)) )
  { /* transmission/reception is disabled (by a previous socket connection close request ) */
    /* or socket connection is offline */
    retVal = E_NOT_OK;
  }
  else
  {
    SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
    if ( SOAD_INV_SO_CON_IDX != SoAd_SockIdx2ActiveSoConIdx(SoAd_SockCons(soConIdx).SockIdx) )
    { /* transmission is ongoing */
      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      retVal = E_NOT_OK;
    }
    else
    { /* no transmission is ongoing */
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
      if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr != NULL_PTR )
      { /* TCP socket */
        /* check if TxQueue can handle transmission */
        if ( E_OK == SoAd_VTcpTxQueueReserveNextElement(soConIdx, pduRouteIdx) )
        { /* TxQueue can handle transmission */
          /* set element */
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
          if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
          {
            SoAd_VTcpTxQueueSetElement(soConIdx, pduRouteIdx, (SoAdSrcPduInfoPtr->SduLength + SOAD_PDU_HDR_SIZE), 
              FALSE);
          }
          else
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
          {
            SoAd_VTcpTxQueueSetElement(soConIdx, pduRouteIdx, SoAdSrcPduInfoPtr->SduLength, FALSE);
          }
        }
        else
        { /* TxQueue cannot handle transmission */
          retVal = E_NOT_OK;
        }
      }
      if ( E_OK == retVal )
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
      {
        /* set tx management struct */
        SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx       = pduRouteIdx;
        SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen     = SoAdSrcPduInfoPtr->SduLength;
        SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending = SoAdSrcPduInfoPtr->SduLength;
        /* set socket connection active on TcpIp socket */
        SoAd_SockIdx2ActiveSoConIdx(SoAd_SockCons(soConIdx).SockIdx) = soConIdx;
        /* lock corresponding socket */
        SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
        if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
        { /* PDU header enabled */
          /* add PDU header size to transmission request */
          SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen     += SOAD_PDU_HDR_SIZE;
          SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending += SOAD_PDU_HDR_SIZE;
        }
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
# if ( defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) )
        if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr != NULL_PTR )
        {
          if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt != 0u )
          {
            uint32 currentTimeoutCnt = 0u;

            if ( SoAd_VTimeoutListGetCurrentTimeout(SoAd_TimeoutListIdxUdpAlive(), soConIdx, &currentTimeoutCnt,
                SoAd_GlobalCounter) == E_OK )
            { /* timeout running */
              /* update timeout */
              /* return value has not to be considered since timeout ist already in list */
              (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxUdpAlive(), soConIdx,
                SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt, SoAd_GlobalCounter);
            }
          }
        }
# endif /* defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) */
# if ( SOAD_VTX_TP_OPTIMIZED_ENALBED == STD_ON )
        if ( SoAd_TxPduIdx2PduRoute(pduRouteIdx).TpOptimized == TRUE )
        {
          retVal = SoAd_VHandleTpTransmissionOnSockCon(soConIdx, FALSE);
        }
        else
# endif /* SOAD_VTX_TP_OPTIMIZED_ENALBED == STD_ON */
        {
          /* set event to handle TP transmission in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTxSoCon(), soConIdx);
        }
      }
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
      else
      {
        SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
    }
  }

  return retVal;
#else
  SOAD_DUMMY_STATEMENT_VAR(SoAdSrcPduId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(SoAdSrcPduInfoPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TP_TRANSMIT, SOAD_E_NOTINIT, E_NOT_OK);

  /* no PDUs for transmission configured */
  SOAD_CallDetReportError(SOAD_API_ID_TP_TRANSMIT, SOAD_E_INV_ARG);
  return E_NOT_OK;
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_Shutdown
 *********************************************************************************************************************/
/*! \brief      close all connections
 *  \return     E_OK                  connections closed
 *  \return     SOAD_E_INPROGRESS     shutdown in progress
 *  \return     E_NOT_OK              shutdown failed
 *  \context    task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_Shutdown(void)
{
  Std_ReturnType retVal = E_NOT_OK;

  switch (SoAd_State)
  {
    case SOAD_STATE_UNINIT:
    {
      SOAD_CallDetReportError(SOAD_API_ID_SHUTDOWN, SOAD_E_NOTINIT);
      break;
    }
    case SOAD_STATE_INIT:
    {
      if ( 0u != SoAd_OpenSocks )
      { /* sockets not yet closed */
        SoAd_ShutdownFinishedCnt = SOAD_SHUTDOWN_FINISHED_WAIT;
        SoAd_State = SOAD_STATE_SHUTDOWN_IN_PROGRESSS;
        retVal = SOAD_E_INPROGRESS;
      }
      else
      { /* all sockets closed */
        SoAd_State = SOAD_STATE_SHUTDOWN;
#if ( defined(SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) )
        SoAd_VCallShutdwnFinishedFuncs();
#endif /* defined(SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) */
        retVal = E_OK;
      }
      break;
    }
    case SOAD_STATE_SHUTDOWN_IN_PROGRESSS:
    {
      retVal = SOAD_E_INPROGRESS;
      break;
    }
    case SOAD_STATE_SHUTDOWN:
    {
      retVal = E_OK;
      break;
    }
    default:
    {
      /* nothing to do */
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  SoAd_TpCancelTransmit
 *********************************************************************************************************************/
/*! \brief      requests transmission cancellation of a specific TP PDU
 *  \param[in]  PduId                 PDU identifier
 *  \return     E_OK                  cancellation request is accepted
 *  \return     E_NOT_OK              cancellation not accepted
 *  \context    task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelTransmit(PduIdType PduId)
{
# if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  SoAd_SoConIdxType soConIdx;
  SoAd_PduIdxType pduIdx;
  Std_ReturnType retVal = E_NOT_OK;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TP_CANCEL_TRANSMIT, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((SoAd_PduRouteTotal() > PduId), SOAD_API_ID_TP_CANCEL_TRANSMIT, SOAD_E_INV_PDUID,
    E_NOT_OK);
  SOAD_GetPduRouteIdxCheckDetErrorReturnValue(pduIdx, PduId, SOAD_API_ID_TP_CANCEL_TRANSMIT, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
    soConIdx = SoAd_SockConTotal();

    while ( 0u < soConIdx )
    {
      soConIdx--;

      if ( pduIdx == SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx )
      { /* transmission is active for this PduId */
        /* set flag to handle cancellation in main function */
        SoAd_SockConIdx2TxMgt(soConIdx).CancelRequested = TRUE;

        /* set event to handle TP transmission (i.e. cancellation) in main function */
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTxSoCon(), soConIdx);

        retVal = E_OK;

        /* for TP no PDU fan-out is possible - break here */
        break;
      }
    }
  }

  return retVal;
# else
  SOAD_DUMMY_STATEMENT_VAR(PduId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TP_CANCEL_TRANSMIT, SOAD_E_NOTINIT,
    E_NOT_OK);

  /* no PDUs for transmission configured */
  SOAD_CallDetReportError(SOAD_API_ID_TP_CANCEL_TRANSMIT, SOAD_E_INV_ARG);
  return E_NOT_OK;
# endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_TpCancelReceive
 *********************************************************************************************************************/
/*! \brief      requests receive cancellation of a specfic TP PDU
 *  \param[in]  PduId                 PDU identifier
 *  \return     E_OK                  cancellation request is accepted
 *  \return     E_NOT_OK              cancellation not accepted
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelReceive(PduIdType PduId)
{
# if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
  SoAd_SoConIdxType soConIdx;
  Std_ReturnType    retVal    = E_NOT_OK;
  SoAd_PduIdxType   sockRouteIdx;
  uint16            routeIdx  = 0u;
  uint16            routeNum  = 0u;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TP_CANCEL_RECEIVE,
    SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_GetSockRouteIdxCheckDetErrorReturnValue(sockRouteIdx, PduId, SOAD_API_ID_TP_CANCEL_RECEIVE, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
    soConIdx = SoAd_SockConTotal();

    if ( SOAD_UL_TYPE_TP == SoAd_SockRoutes(sockRouteIdx).SockRouteDest.UpperLayer )
    { /* socket route destination is TP */
      /* get the corresponding soConIdx */
      while ( 0u < soConIdx )
      {
        soConIdx--;
        routeIdx = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxStart;
        routeNum = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxNum;
        while ( 0u < routeNum )
        { /* iterate over all socket route destinations of this socket connection */
          if ( routeIdx == sockRouteIdx )
          { /* socket connection found */
            break;
          }
          routeNum--;
          routeIdx++;
        }

        if ( 0u < routeNum )
        { /* socket connection found */
          break;
        }
      }

      if ( 0u < routeNum )
      { /* socket connection found */
        if ( routeIdx == SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx )
        { /* reception is active for the requested PDU */
          /* set flag to handle cancellation in main function */
          SoAd_SockConIdx2RxMgt(soConIdx).CancelRequested = TRUE;

          /* set event to handle TP reception (i.e. cancellation) in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTpRxSoCon(), soConIdx);

          retVal = E_OK;
        }
      }
    }
  }
  return retVal;
# else
  SOAD_DUMMY_STATEMENT_VAR(PduId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TP_CANCEL_RECEIVE,
    SOAD_E_NOTINIT, E_NOT_OK);

  /* no PDUs for reception configured */
  SOAD_CallDetReportError(SOAD_API_ID_TP_CANCEL_RECEIVE, SOAD_E_INV_ARG);
  return E_NOT_OK;
# endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_GetSoConId
 *********************************************************************************************************************/
/*! \brief      returns the socket connection index of a PduId
 *  \param[in]  TxPduId        transmit PDU identifier
 *  \param[out] SoConIdPtr     pointer to memory where socket connection index shall be written to
 *  \return     E_OK           request was successful
 *  \return     E_NOT_OK       request was not successful
 *  \context    task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetSoConId(PduIdType TxPduId,
                      P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_VAR) SoConIdPtr)
{
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  Std_ReturnType retVal = E_NOT_OK;
  SoAd_SoConIdType tmpSoConId;
  SoAd_PduIdxType pduRouteIdx;
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */

  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_GET_SO_CON_ID, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != SoConIdPtr), SOAD_API_ID_GET_SO_CON_ID, SOAD_E_PARAM_POINTER,
    E_NOT_OK);

#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  SOAD_GetPduRouteIdxCheckDetErrorReturnValue(pduRouteIdx, TxPduId, SOAD_API_ID_GET_SO_CON_ID, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
    if ( 1u == SoAd_TxPduIdx2PduRoute(pduRouteIdx).PduRouteDestListSize )
    { /* this function is only available for PduRoutes without PDU fan-out (i.e. only one PduRouteDest is configured) */
      /* search for the corresponding SoConId */
      tmpSoConId = SoAd_SockConTotalWithInv();
      while ( 0 < tmpSoConId )
      {
        tmpSoConId--;
        if ( SoAd_SockConId2SockConIdx(tmpSoConId) ==
          SoAd_TxPduIdx2PduRoute(pduRouteIdx).PduRouteDestListPtr[0]->SoConIdx )
        {
          *SoConIdPtr = tmpSoConId;
          retVal = E_OK;
          break;
        }
      }
    }
  }

  return retVal;
#else
  SOAD_DUMMY_STATEMENT_VAR(TxPduId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(SoConIdPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  /* no PDUs for transmission configured */
  SOAD_CallDetReportError(SOAD_API_ID_GET_SO_CON_ID, SOAD_E_INV_ARG);
  return E_NOT_OK;
# endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if ( defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_GetRcvRemoteAddr
 *********************************************************************************************************************/
/*! \brief      returns the remote address of the last received message at a socket connection
 *  \param[in]  SoConId        socket connection index
 *  \param[out] IpAddrPtr      pointer to memory where the remote address shall be written to
 *  \return     E_OK           remote address available
 *  \return     E_NOT_OK       no remote address available
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetRcvRemoteAddr(SoAd_SoConIdType SoConId,
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) IpAddrPtr)
{
# if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
  SoAd_SoConIdxType soConIdx;
  Std_ReturnType retVal = E_NOT_OK;
  boolean ipAddrIsAny = TRUE;
  boolean portIsAny = TRUE;
# endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_GET_RCV_REMOTE_ADDR,
    SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_GET_RCV_REMOTE_ADDR, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != IpAddrPtr), SOAD_API_ID_GET_RCV_REMOTE_ADDR,
    SOAD_E_PARAM_POINTER, E_NOT_OK);

# if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
  if ( SOAD_STATE_INIT == SoAd_State )
  {
    if ( NULL_PTR != SoAd_SockCons(soConIdx).RcvRemSockPtr )
    { /* get received remote address is supported  */
      SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      /* check whether IP address is set */
      SoAd_VCheckForWildcards(SoAd_SockCons(soConIdx).RcvRemSockPtr, &ipAddrIsAny, &portIsAny);
      if ( (TRUE != ipAddrIsAny) && (TRUE != portIsAny) )
      { /* IP address is set */
        /* copy remote address to upper layers memory */
        SoAd_VCopyIpAddr(IpAddrPtr, SoAd_SockCons(soConIdx).RcvRemSockPtr, TRUE);
        retVal = E_OK;
      }
      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

  return retVal;
# else
  SOAD_DUMMY_STATEMENT_VAR(SoConId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(IpAddrPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  /* no PDUs for reception configured */
  SOAD_CallDetReportError(SOAD_API_ID_GET_RCV_REMOTE_ADDR, SOAD_E_INV_ARG);
  return E_NOT_OK;
# endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
#endif /* defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) */

/**********************************************************************************************************************
 *  SoAd_OpenSoCon
 *********************************************************************************************************************/
/*! \brief      open the socket connection specified by SoConId
 *  \param[in]  SoConId        socket connection index
 *  \return     E_OK           request was successful
 *  \return     E_NOT_OK       request was not successful
 *  \context    task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_OpenSoCon(SoAd_SoConIdType SoConId)
{
  Std_ReturnType retVal = E_OK;
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_OPEN_SO_CON, SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_OPEN_SO_CON, E_NOT_OK);

  if ( SOAD_STATE_INIT != SoAd_State )
  {
    retVal = E_NOT_OK;
  }
  else if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SockAutoSoConSetup == TRUE )
  {
    SOAD_CallDetReportError(SOAD_API_ID_OPEN_SO_CON, SOAD_E_INV_ARG);
    retVal = E_NOT_OK;
  }
  else
  {
    if ( SOAD_INV_BUF_IDX_8 > SoAd_SockConIdx2FlagCntOpCl(soConIdx) )
    {
      /* increment flag to open socket connection in main function */
      SoAd_SockConIdx2FlagCntOpCl(soConIdx)++;
      /* set event to handle socket connection state in main function */
      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
    }
  }

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_CloseSoCon
 *********************************************************************************************************************/
/*! \brief      close the socket connection specified by SoConId
 *  \param[in]  SoConId        socket connection index
 *  \param[in]  Abort          terminate socket connection immediately if TRUE
 *  \return     E_OK           request was successful
 *  \return     E_NOT_OK       request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_CloseSoCon(SoAd_SoConIdType SoConId, boolean Abort)
{
  Std_ReturnType retVal = E_NOT_OK;
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_CLOSE_SO_CON, SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_CLOSE_SO_CON, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
    if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SockAutoSoConSetup == TRUE )
    {
      SOAD_CallDetReportError(SOAD_API_ID_CLOSE_SO_CON, SOAD_E_INV_ARG);
    }
    else
    {
      SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      /* decrement socket connection open counter */
      if ( 0u < SoAd_SockConIdx2FlagCntOpCl(soConIdx) )
      {
        SoAd_SockConIdx2FlagCntOpCl(soConIdx)--;
        retVal = E_OK;
      }
      if ( SOAD_SOCON_OFFLINE != SoAd_SockConIdx2State(soConIdx) )
      {
        /* check whether socket connection shall be closed immediately in next MainFunction */
        if ( (0u == SoAd_SockConIdx2FlagCntOpCl(soConIdx)) || (TRUE == Abort) )
        { /* no upper layer using this socket connection anymore or abort flag is set */
          SoAd_SockConIdx2FlagAbort(soConIdx)   |= Abort;
          SoAd_SockConIdx2FlagCntOpCl(soConIdx) = 0u;
          SoAd_SockConIdx2CloseMode(soConIdx)   = SOAD_CLOSE_OFFLINE;
          /* set event to handle socket connection state in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
          retVal = E_OK;
        }
      }
      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */

/**********************************************************************************************************************
 *  SoAd_RequestIpAddrAssignment
 *********************************************************************************************************************/
/*! \brief      triggers the local IP assignment
 *  \param[in]  SoConId           socket connection index
 *  \param[in]  Type              IP address type
 *  \param[in]  LocalIpAddrPtr    pointer to IP address which shall be assigned
 *  \param[in]  Netmask           netmask in CIDR
 *  \param[in]  DefaultRouterPtr  pointer to default router (gateway) address
 *  \return     E_OK              request was successful
 *  \return     E_NOT_OK          request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
/* PRQA S 3673 3 */ /* MD_SoAd_16.7 */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_RequestIpAddrAssignment(SoAd_SoConIdType SoConId,
                      SoAd_IpAddrAssignmentType Type,
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) LocalIpAddrPtr,
                      uint8 Netmask,
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) DefaultRouterPtr)
{
  Std_ReturnType retVal = E_OK;
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_REQ_IP_ADDR_ASSIGN, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_REQ_IP_ADDR_ASSIGN, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
    SoAd_SockIdxType sockIdx = SoAd_SockCons(soConIdx).SockIdx;

# if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (SOAD_VSOCKET_BSD_API_ENABLED == STD_ON) )
    SoAd_LocalAddrIdType addrId = SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId;

    SOAD_CheckDetErrorReturnValue((Type == SoAd_LocalAddr(addrId).AssignType), SOAD_API_ID_REQ_IP_ADDR_ASSIGN,
      SOAD_E_NOTINIT, E_NOT_OK);

    retVal = E_NOT_OK;

    if ( SoAd_SockConIdx2IpAddrState(soConIdx) == SOAD_IPADDR_STATE_ASSIGNED )
    { /* IP address is already assigned */
      /* this is allowed only if local port shall be updated */
      if ( LocalIpAddrPtr != NULL_PTR )
      {
        if ( LocalIpAddrPtr->domain == SoAd_SockCons(soConIdx).SockConGrpPtr->Domain )
        {
          P2VAR(SoAd_SockAddrInetXType, AUTOMATIC, SOAD_APPL_VAR) tmpLocalIpAddrToBeSetPtr =
            (SOAD_P2VAR(SoAd_SockAddrInetXType))LocalIpAddrPtr;

#  if ( defined(SOAD_VIPV6_ENABLED) && (SOAD_VIPV6_ENABLED == STD_ON) )
          if ( LocalIpAddrPtr->domain == SOAD_AF_INET6  )
          { /* IPv6 */
            if ( (tmpLocalIpAddrToBeSetPtr->addr[0] == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0]) ||
              (tmpLocalIpAddrToBeSetPtr->addr[1] == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[1]) ||
              (tmpLocalIpAddrToBeSetPtr->addr[2] == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[2]) ||
              (tmpLocalIpAddrToBeSetPtr->addr[3] == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[3]) )
            { /* IP address is equal */
              /* assume IP address assignment successful and update local port only */
              retVal = E_OK;
            }
          }
          else
#  endif /* defined(SOAD_VIPV6_ENABLED) && (SOAD_VIPV6_ENABLED == STD_ON) */
          { /* IPv4 */
            if ( tmpLocalIpAddrToBeSetPtr->addr[0] == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0] )
            { /* IP address is equal */
              /* assume IP address assignment successful and update local port only */
              retVal = E_OK;
            }
          }
        }
      }
    }
    else
    { /* IP address not assigned */
      if ( SoAd_LocalAddr(addrId).AssignTrigger == SOAD_ASSIGN_TRIGGER_MANUAL )
      { /* manual IP address trigger */
        if ( SOAD_IPADDR_ASSIGNMENT_STATIC == Type )
        { /* static IP address */
          SOAD_CheckDetErrorReturnValue((NULL_PTR != LocalIpAddrPtr), SOAD_API_ID_REQ_IP_ADDR_ASSIGN,
            SOAD_E_PARAM_POINTER, E_NOT_OK);

#  if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
          if ( SOAD_AF_INET6 == SoAd_SockCons(soConIdx).SockConGrpPtr->Domain )
          { /* IPv6 */
            SOAD_CheckDetErrorReturnValue((SOAD_AF_INET6 == LocalIpAddrPtr->domain), SOAD_API_ID_REQ_IP_ADDR_ASSIGN,
              SOAD_E_INV_ARG, E_NOT_OK);

            if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_MULTICAST )
            { /* multicast address */
              /* check if address is a valid multicast address */
              if ( SOAD_IPV6_MULTICAST_PREFIX == ((SOAD_A_P2VAR(SoAd_SockAddrInet6Type)LocalIpAddrPtr)->addr[0] &
                  SOAD_IPV6_MULTICAST_PREFIX_MASK) )
              { /* valid multicast address */
                retVal = E_OK;
              }
            }
            else
            { /* unicast address */
              if ( SOAD_IPV6_MULTICAST_PREFIX != ((SOAD_A_P2VAR(SoAd_SockAddrInet6Type)LocalIpAddrPtr)->addr[0] &
                  SOAD_IPV6_MULTICAST_PREFIX_MASK) )
              { /* no multicast address */
                retVal = E_OK;
              }
            }

            if ( retVal == E_OK )
            { /* valid address */
              /* overwrite current local address */
              SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0] =
                (SOAD_A_P2VAR(SoAd_SockAddrInetType)LocalIpAddrPtr)->addr[0];
              SoAd_AddrId2LocalIpAddrDyn(addrId).addr[1] =
                (SOAD_A_P2VAR(SoAd_SockAddrInetType)LocalIpAddrPtr)->addr[1];
              SoAd_AddrId2LocalIpAddrDyn(addrId).addr[2] =
                (SOAD_A_P2VAR(SoAd_SockAddrInetType)LocalIpAddrPtr)->addr[2];
              SoAd_AddrId2LocalIpAddrDyn(addrId).addr[3] =
                (SOAD_A_P2VAR(SoAd_SockAddrInetType)LocalIpAddrPtr)->addr[3];

              /* set local address to "requested" */
              SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_REQUEST;

              /* set event to handle local address in main function */
              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), addrId);
            }
          }
          else
#  endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
          { /* IPv4 */
            SOAD_CheckDetErrorReturnValue((SOAD_AF_INET == LocalIpAddrPtr->domain), SOAD_API_ID_REQ_IP_ADDR_ASSIGN,
              SOAD_E_INV_ARG, E_NOT_OK);

            if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_MULTICAST )
            { /* multicast address */
              /* check if address is a valid multicast address */
              if ( SOAD_IPV4_MULTICAST_PREFIX == ((SOAD_A_P2VAR(SoAd_SockAddrInetType)LocalIpAddrPtr)->addr[0] &
                  SOAD_IPV4_MULTICAST_PREFIX_MASK) )
              { /* valid multicast address */
                retVal = E_OK;
              }
            }
            else
            { /* unicast address */
              if (DefaultRouterPtr != NULL_PTR )
              {
                SOAD_DUMMY_STATEMENT_VAR(DefaultRouterPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

                if ( Netmask <= 32u )
                { /* valid netmask */
                  if ( SOAD_IPV4_MULTICAST_PREFIX != ((SOAD_A_P2VAR(SoAd_SockAddrInetType)LocalIpAddrPtr)->addr[0] &
                      SOAD_IPV4_MULTICAST_PREFIX_MASK) )
                  { /* no multicast address */
                    retVal = E_OK;
                  }
                }
                else
                { /* invalid netmask */
                  SOAD_CallDetReportError(SOAD_API_ID_REQ_IP_ADDR_ASSIGN, SOAD_E_INV_ARG);
                }
              }
              if ( retVal == E_OK )
              {
                /* overwrite current netmask */
                SoAd_AddrId2LocalIpAddrDyn(addrId).netmask = Netmask;
              }
            }

            if ( retVal == E_OK )
            { /* valid address */
              /* overwrite current local address */
              SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0] =
                (SOAD_A_P2VAR(SoAd_SockAddrInetType)LocalIpAddrPtr)->addr[0];

              /* set local address to "requested" */
              SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_REQUEST;

              /* set event to handle local address in main function */
              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), addrId);
            }
          }
        }
        else
        { /* SOAD_IPADDR_ASSIGNMENT_STATIC != Type */
          /* it is assumed that link local address or DHCP address assignment is started automatically at startup */
          /* return always E_OK */
          retVal = E_OK;

          /* set event to handle local address in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), addrId);
        }
      }
      else
      { /* automatic IP address trigger */
        /* IP address can be requested for trigger manual only */
      }
    }
# else
    SoAd_SockAddrInetXType localIpAddr;
    SoAd_SockAddrInetXType defaultRouter;
    uint8 netMask;

    /* get local address */
    if ( E_OK == TcpIp_GetIpAddr(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId,
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&localIpAddr,
        &netMask,
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&defaultRouter) )
    {
      /* local address configured */
      /* check if new IP address is equal to current configured IP address */
      if ( NULL_PTR != LocalIpAddrPtr )
      { /* IP address is static */
        if ( E_OK != SoAd_VCompareIpAddr((SoAd_SockAddrType*)&localIpAddr, LocalIpAddrPtr, FALSE) )
        { /* IP address is different */
          /* forward request to TcpIp module */
          retVal = TcpIp_RequestIpAddrAssignment(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId, Type,
            LocalIpAddrPtr, Netmask, DefaultRouterPtr);
        }
        else
        { /* IP address is equal */
          /* assume IP address assignment successful and update local port only */
        }
      }
      else
      {
        /* forward request to TcpIp module */
        retVal = TcpIp_RequestIpAddrAssignment(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId, Type,
          LocalIpAddrPtr, Netmask, DefaultRouterPtr);
      }
    }
    else
    {
      /* forward request to TcpIp module */
      retVal = TcpIp_RequestIpAddrAssignment(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId, Type,
        LocalIpAddrPtr, Netmask, DefaultRouterPtr);
    }
# endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (SOAD_VSOCKET_BSD_API_ENABLED == STD_ON) */

    if ( E_OK == retVal )
    { /* IP address assignment successful */
      if ( SOAD_PORT_ANY == SoAd_SockIdx2LocPortDyn(sockIdx) )
      { /* port is any */
        if ( NULL_PTR != LocalIpAddrPtr )
        { /* use new port */
          SoAd_SockIdx2LocPortDyn(sockIdx) = ((SoAd_SockAddrInetXType*)LocalIpAddrPtr)->port;
        }
      }
      else
      { /* port is set */
        /* use configured port - nothing to do here */
      }
    }
  }
  else
  { /* SoAd is not in initialized state */
    retVal = E_NOT_OK;
  }

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_ReleaseIpAddrAssignment
 *********************************************************************************************************************/
/*! \brief      releases the local IP address of a socket connection (i.e. EthIf controller)
 *  \param[in]  SoConId         socket connection index
 *  \return     E_OK            request was successful
 *  \return     E_NOT_OK        request was not successful
 *  \context    task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReleaseIpAddrAssignment(SoAd_SoConIdType SoConId)
{
  Std_ReturnType retVal = E_NOT_OK;
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_RLS_IP_ADDR_ASSIGN, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_RLS_IP_ADDR_ASSIGN, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
    SoAd_LocalAddrIdType addrId = SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId;

    if ( SOAD_IPADDR_STATE_ASSIGNED == SoAd_SockConIdx2IpAddrState(soConIdx) )
    { /* IP address is assigned */
      if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_MULTICAST )
      { /* multicast address */
        SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE;

        retVal = E_OK;

        /* set event to handle local address in main function */
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), addrId);
      }
    }
    else if ( SOAD_IPADDR_STATE_UNASSIGNED == SoAd_SockConIdx2IpAddrState(soConIdx) )
    { /* IP address is unassigned */
      /* reset previous request */
      SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE;

      retVal = E_OK;
    }
    else
    { /* unexpected state */
      /* nothing to do */
    }
#else
    retVal = TcpIp_ReleaseIpAddrAssignment(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId);
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
  }

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_GetLocalAddr
 *********************************************************************************************************************/
/*! \brief      retrieves information about the local address of a specific socket connection
 *  \param[in]  SoConId           socket connection index
 *  \param[out] LocalAddrPtr      pointer to local address (IP and Port)
 *  \param[out] NetmaskPtr        pointer to network mask (CIDR Notation)
 *  \param[out] DefaultRouterPtr  pointer to default gateway
 *  \return     E_OK              request was successful
 *  \return     E_NOT_OK          request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetLocalAddr(SoAd_SoConIdType SoConId,
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) LocalAddrPtr,
                      P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) NetmaskPtr,
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) DefaultRouterPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
#else
  SoAd_SockIdxType sockIdx;
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 9 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_GET_LOCAL_ADDR, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != LocalAddrPtr), SOAD_API_ID_GET_LOCAL_ADDR, SOAD_E_PARAM_POINTER,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != NetmaskPtr), SOAD_API_ID_GET_LOCAL_ADDR, SOAD_E_PARAM_POINTER,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != DefaultRouterPtr), SOAD_API_ID_GET_LOCAL_ADDR, SOAD_E_PARAM_POINTER,
    E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_GET_LOCAL_ADDR, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
    /* copy address to provided buffer */
    SoAd_LocalAddrIdType addrId = SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId;

    *NetmaskPtr = SoAd_AddrId2LocalIpAddrDyn(addrId).netmask;
    LocalAddrPtr->domain = SoAd_SockCons(soConIdx).SockConGrpPtr->Domain;
    ((SoAd_SockAddrInetXType*)LocalAddrPtr)->port = SoAd_SockIdx2LocPortDyn(SoAd_SockCons(soConIdx).SockIdx);
    ((SoAd_SockAddrInetXType*)LocalAddrPtr)->addr[0] = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0];
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    if ( SoAd_SockCons(soConIdx).SockConGrpPtr->Domain == SOAD_AF_INET6 )
    { /* IPv6 */
      ((SoAd_SockAddrInetXType*)LocalAddrPtr)->addr[1] = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[1];
      ((SoAd_SockAddrInetXType*)LocalAddrPtr)->addr[2] = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[2];
      ((SoAd_SockAddrInetXType*)LocalAddrPtr)->addr[3] = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[3];
    }
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */

    retVal = E_OK;
#else
    /* query requested information from TcpIp module */
    if ( E_OK != TcpIp_GetIpAddr(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId,
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))LocalAddrPtr,
        NetmaskPtr,
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))DefaultRouterPtr) )
    { /* no IP address is configured */
      /* set IP address to any */
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
      ((SoAd_SockAddrInet6Type*)LocalAddrPtr)->addr[0] = SOAD_IP6ADDR_ANY;
      ((SoAd_SockAddrInet6Type*)LocalAddrPtr)->addr[1] = SOAD_IP6ADDR_ANY;
      ((SoAd_SockAddrInet6Type*)LocalAddrPtr)->addr[2] = SOAD_IP6ADDR_ANY;
      ((SoAd_SockAddrInet6Type*)LocalAddrPtr)->addr[3] = SOAD_IP6ADDR_ANY;
# else
      ((SoAd_SockAddrInetType*)LocalAddrPtr)->addr[0] = SOAD_IPADDR_ANY;
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    }

    /* get local port by SoAd internal information */
    sockIdx = SoAd_SockCons(soConIdx).SockIdx;
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    if ( SOAD_AF_INET6 == LocalAddrPtr->domain )
    { /* IPv6 */
      ((SoAd_SockAddrInet6Type*)LocalAddrPtr)->port = SoAd_SockIdx2LocPortDyn(sockIdx);
    }
    else
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    { /* IPv4 */
      ((SoAd_SockAddrInetType*)LocalAddrPtr)->port = SoAd_SockIdx2LocPortDyn(sockIdx);
    }

    retVal = E_OK;
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
  }

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L:MSR_STPTH */

/**********************************************************************************************************************
 *  SoAd_GetPhysAddr
 *********************************************************************************************************************/
/*! \brief      retrieves the phyiscal address of a specific socket connection
 *  \param[in]  SoConId           socket connection index
 *  \param[out] PhysAddrPtr       pointer to physical source address
 *  \return     E_OK              request was successful
 *  \return     E_NOT_OK          request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 3673 2 */ /* MD_SoAd_16.7 */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetPhysAddr(SoAd_SoConIdType SoConId,
                      P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) PhysAddrPtr)
{
  SoAd_SoConIdxType     soConIdx;
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
  SoAd_LocalAddrIdType  addrId;
  SoAd_SockIdxType      sockIdx;
  SoAd_SocketIdType     socketId;
  Std_ReturnType        retVal = E_NOT_OK;
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_GET_PHYS_ADDR, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != PhysAddrPtr), SOAD_API_ID_GET_PHYS_ADDR, SOAD_E_PARAM_POINTER, 
    E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_GET_PHYS_ADDR, E_NOT_OK);

  if ( SOAD_STATE_INIT != SoAd_State )
  {
    return E_NOT_OK;
  }

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
  addrId = SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId;
  sockIdx = SoAd_SockCons(soConIdx).SockConGrpPtr->GrpSockIdx;

# if ( SOAD_VTCP_USED == STD_ON )
  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr != NULL_PTR )
  {
    if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr->TcpInitiate == TRUE )
    { /* in case of TCP client valid sockIdx is located in socket connection */
      sockIdx = SoAd_SockCons(soConIdx).SockIdx;
    }
  }
# endif /* SOAD_VTCP_USED == STD_ON */

  socketId = SoAd_SockIdx2SocketId(sockIdx);

  if ( socketId != SOAD_INV_SOCKET_ID )
  { /* socket resource bound - physical address can be retrieved */
    char ifName[IF_NAMESIZE + 1] = {0}; /* PRQA S 5013 */ /* MD_SoAd_6.3 */

    if ( if_indextoname(SoAd_AddrId2LocalIpAddrDyn(addrId).ifcIdx, ifName) != 0)
    {
      struct ifreq ifr;
      uint16 ifNameLen;
      uint16 idx;

      for ( idx = 0u; idx < (uint16)(IF_NAMESIZE + 1); idx++ )
      {
        if ( ifName[idx] == 0u )
        { /* reached 0 termination of interface name */
          ifNameLen = idx;
          break;
        }
      }

      if ( ifNameLen < sizeof(ifr.ifr_name) )
      {
        /* prepare parameter for ioctl call */
        IpBase_Copy((IpBase_CopyDataType*)ifr.ifr_name,
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))ifName, ifNameLen);
          ifr.ifr_name[ifNameLen] = 0;

        if ( ioctl(socketId, SIOCGIFHWADDR, &ifr) != -1 )
        {
          PhysAddrPtr[0] = (uint8)ifr.ifr_hwaddr.sa_data[0];
          PhysAddrPtr[1] = (uint8)ifr.ifr_hwaddr.sa_data[1];
          PhysAddrPtr[2] = (uint8)ifr.ifr_hwaddr.sa_data[2];
          PhysAddrPtr[3] = (uint8)ifr.ifr_hwaddr.sa_data[3];
          PhysAddrPtr[4] = (uint8)ifr.ifr_hwaddr.sa_data[4];
          PhysAddrPtr[5] = (uint8)ifr.ifr_hwaddr.sa_data[5];

          retVal = E_OK;
        }
      }
    }
  }

  return retVal;
#else
  return TcpIp_GetPhysAddr(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId, PhysAddrPtr);
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_GetRemoteAddr
 *********************************************************************************************************************/
/*! \brief      retrieves the remote address of a specific socket connection
 *  \param[in]  SoConId           socket connection index
 *  \param[out] IpAddrPtr         pointer to remote address
 *  \return     E_OK              request was successful
 *  \return     E_NOT_OK          request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetRemoteAddr(SoAd_SoConIdType SoConId,
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) IpAddrPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_GET_REMOTE_ADDR, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != IpAddrPtr), SOAD_API_ID_GET_REMOTE_ADDR, SOAD_E_PARAM_POINTER,
    E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_GET_REMOTE_ADDR, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
    if ( (SOAD_AF_INET == SoAd_SockConIdx2RemSockDyn(soConIdx).domain )
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
      || (SOAD_AF_INET6 == SoAd_SockConIdx2RemSockDyn(soConIdx).domain)
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
      )
    { /* domain is set */
      if ( SoAd_SockConIdx2RemAddrState(soConIdx) <= SOAD_SOCON_IP_ANY_PORT_ANY )
      { /* remote address is set or contains wildcards */
        SoAd_VCopyIpAddr(IpAddrPtr,
          (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&SoAd_SockConIdx2RemSockDyn(soConIdx), TRUE);
        retVal = E_OK;
      }
    }
    else
    { /* domain is not set */
      /* nothing to do here */
    }
  }

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L:MSR_STPTH */

/**********************************************************************************************************************
 *  SoAd_GetRemoteAddrState
 *********************************************************************************************************************/
/*! \brief      retrieves the remote address of a specific socket connection and extended information about
 *              valid, any or not set values
 *  \param[in]  SoConId           socket connection index
 *  \param[out] IpAddrPtr         pointer to memory where remote address shall be stored
 *  \param[out] RemAddrState      pointer to memory where remote address state shall be stored
 *  \return     E_OK              request was successful
 *  \return     E_NOT_OK          request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_GetRemoteAddrState(SoAd_SoConIdType SoConId,
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) IpAddrPtr,
                      P2VAR(SoAd_RemAddrStateType, AUTOMATIC, SOAD_APPL_VAR) RemAddrState)
{
  Std_ReturnType retVal = E_NOT_OK;
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 7 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_GET_REMOTE_ADDR, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != IpAddrPtr), SOAD_API_ID_GET_REMOTE_ADDR, SOAD_E_PARAM_POINTER,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != RemAddrState), SOAD_API_ID_GET_REMOTE_ADDR, SOAD_E_PARAM_POINTER,
    E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_GET_REMOTE_ADDR, E_NOT_OK);
  
  if ( SOAD_STATE_INIT == SoAd_State )
  {
    *RemAddrState = SoAd_SockConIdx2RemAddrState(soConIdx);

    if ( SOAD_AF_INET == SoAd_SockConIdx2RemSockDyn(soConIdx).domain )
    { /* domain is set */
      SoAd_VCopyIpAddr(IpAddrPtr,
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&SoAd_SockConIdx2RemSockDyn(soConIdx), TRUE);
      retVal = E_OK;
    }
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    else if ( SOAD_AF_INET6 == SoAd_SockConIdx2RemSockDyn(soConIdx).domain )
    {/* domain is set */
      SoAd_VCopyIpAddr(IpAddrPtr,
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&SoAd_SockConIdx2RemSockDyn(soConIdx), TRUE);
      retVal = E_OK;
    }
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    else
    { /* domain is not set */
      /* nothing to do here */
    }
  }

  return retVal;
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */

/**********************************************************************************************************************
 *  SoAd_EnableRouting
 *********************************************************************************************************************/
/*! \brief      enables routing for PDUs referencing a specific routing group
 *  \param[in]  id             routing group identifier
 *  \return     E_OK           request was successful
 *  \return     E_NOT_OK       request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableRouting(SoAd_RoutingGroupIdType id)
{
#if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
  uint16 pduDestNum = 0;
#endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */
#if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
  uint16 socketRouteNum = 0;
#endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
  SoAd_RoutingGroupIdxType routeGrpIdx;
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_ENABLE_ROUTING, SOAD_E_NOTINIT,
    E_NOT_OK);
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
  SOAD_GetRouteGrpIdxCheckDetErrorReturnValue(routeGrpIdx, id, SOAD_API_ID_ENABLE_ROUTING, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
    if ( SoAd_IsRouteGrpIdx2PduRouteDestColPresent() )
    {
      pduDestNum = SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).PduRouteDestListSize;
    }

    /* enable routing for all socket connections */
    while ( 0u < pduDestNum )
    {
      pduDestNum--;
      *SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).StateColPtr[pduDestNum] |= SOAD_ROUT_GRP_BIT_PATTERN_ENABLED;
    }
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */

# if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
    if ( SoAd_IsRouteGrpIdx2SocketRouteColPresent() )
    {
      socketRouteNum = SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).IdNum;
    }

    /* enable routing for all socket connections */
    while ( 0u < socketRouteNum )
    {
      socketRouteNum--;
      *SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).StateColPtr[socketRouteNum] |= SOAD_ROUT_GRP_BIT_PATTERN_ENABLED;
    }
# endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */

    return E_OK;
  }
  else
  { /* SoAd is not in initialized state */
    return E_NOT_OK;
  }
#else
  SOAD_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CallDetReportError(SOAD_API_ID_ENABLE_ROUTING, SOAD_E_INV_ARG);
  return E_NOT_OK;
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L:MSR_STPTH */

/**********************************************************************************************************************
 *  SoAd_EnableSpecificRouting
 *********************************************************************************************************************/
/*! \brief      enables routing for PDUs referencing a specific routing group on a specific socket connection
 *  \param[in]  id             routing group identifier
 *  \param[in]  SoConId        socket connection identifier
 *  \return     E_OK           request was successful
 *  \return     E_NOT_OK       request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_EnableSpecificRouting(SoAd_RoutingGroupIdType id, SoAd_SoConIdType SoConId)
{
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
  SoAd_SoConIdxType soConIdx;
  SoAd_RoutingGroupIdxType routeGrpIdx;
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */
  Std_ReturnType retVal = E_NOT_OK;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_ENABLE_SPECIFIC_ROUTING, SOAD_E_NOTINIT,
    E_NOT_OK);
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
  SOAD_GetRouteGrpIdxCheckDetErrorReturnValue(routeGrpIdx, id, SOAD_API_ID_ENABLE_SPECIFIC_ROUTING, E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_ENABLE_SPECIFIC_ROUTING, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
    uint16 pduDestNum = 0;

    if ( SoAd_IsRouteGrpIdx2PduRouteDestColPresent() )
    {
      pduDestNum = SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).PduRouteDestListSize;
    }

    /* enable routing for specific socket connection */
    while ( 0u < pduDestNum )
    {
      pduDestNum--;

      if ( soConIdx == SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).PduRouteDestListPtr[pduDestNum]->SoConIdx )
      {
        *SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).StateColPtr[pduDestNum] |= SOAD_ROUT_GRP_BIT_PATTERN_ENABLED;
        retVal = E_OK;

        /* do not break here since multiple PduRouteDests are possible per socket connection */
      }
    }
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */

# if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
    if ( SoAd_IsRouteGrpIdx2SocketRouteColPresent() )
    {
      if ( SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxNum > 0u )
      { /* socket connections has SocketRoutes */
        uint16 sockRouteNum = SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).IdNum;

        /* enable routing for specific socket connection */
        while ( 0u < sockRouteNum )
        {
          uint16 sockRouteIdx;
          uint16 sockRouteIdxStart = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxStart;
          uint16 sockRouteIdxEnd = (uint16)(sockRouteIdxStart +
            SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxNum - 1u);

          sockRouteNum--;
          sockRouteIdx = SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).IdColPtr[sockRouteNum];

          if ( (sockRouteIdx >= sockRouteIdxStart) && (sockRouteIdx <= sockRouteIdxEnd) )
          {
            *SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).StateColPtr[sockRouteNum] |=
              SOAD_ROUT_GRP_BIT_PATTERN_ENABLED;
            retVal = E_OK;

            /* do not break here since multiple SocketRoutes are possible per socket connection */
          }
        }
      }
    }
# endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
  }

  return retVal;
#else
  SOAD_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(SoConId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CallDetReportError(SOAD_API_ID_ENABLE_SPECIFIC_ROUTING, SOAD_E_INV_ARG);
  return retVal;
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_DisableRouting
 *********************************************************************************************************************/
/*! \brief      disables routing for PDUs referencing a specific routing group
 *  \param[in]  id             routing group identifier
 *  \return     E_OK           request was successful
 *  \return     E_NOT_OK       request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableRouting(SoAd_RoutingGroupIdType id)
{
#if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
  uint16 pduDestNum = 0;
#endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */
#if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
  uint16 sockRouteNum = 0;
#endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
  SoAd_RoutingGroupIdxType routeGrpIdx;
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_DISABLE_ROUTING, SOAD_E_NOTINIT,
    E_NOT_OK);
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
  SOAD_GetRouteGrpIdxCheckDetErrorReturnValue(routeGrpIdx, id, SOAD_API_ID_DISABLE_ROUTING, E_NOT_OK);
  
  if ( SOAD_STATE_INIT == SoAd_State )
  {
# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
    if ( SoAd_IsRouteGrpIdx2PduRouteDestColPresent() )
    {
      pduDestNum = SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).PduRouteDestListSize;
    }

    /* disable routing for all socket connections */
    while ( 0u < pduDestNum )
    {
      pduDestNum--;
      /* PRQA S 0277 2 */ /* MD_SoAd_3.1 */
      *SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).StateColPtr[pduDestNum] &=
        (uint8)(~SOAD_ROUT_GRP_BIT_PATTERN_ENABLED);
    }
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */

# if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
    if ( SoAd_IsRouteGrpIdx2SocketRouteColPresent() )
    {
      sockRouteNum = SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).IdNum;
    }

    /* disable routing for all socket connections */
    while ( 0u < sockRouteNum )
    {
      sockRouteNum--;
      /* PRQA S 0277 2 */ /* MD_SoAd_3.1 */
      *SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).StateColPtr[sockRouteNum] &=
        (uint8)(~SOAD_ROUT_GRP_BIT_PATTERN_ENABLED);
    }
# endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */

    return E_OK;
  }
  else
  { /* SoAd is not in initialized state */
    return E_NOT_OK;
  }
#else
  SOAD_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CallDetReportError(SOAD_API_ID_DISABLE_ROUTING, SOAD_E_INV_ARG);
  return E_NOT_OK;
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L:MSR_STPTH */

/**********************************************************************************************************************
 *  SoAd_DisableSpecificRouting
 *********************************************************************************************************************/
/*! \brief      disables routing for PDUs referencing a specific routing group on a specific socket connection
 *  \param[in]  id             routing group identifier
 *  \param[in]  SoConId        socket connection identifier
 *  \return     E_OK           request was successful
 *  \return     E_NOT_OK       request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_DisableSpecificRouting(SoAd_RoutingGroupIdType id, SoAd_SoConIdType SoConId)
{
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
  SoAd_SoConIdxType soConIdx;
  SoAd_RoutingGroupIdxType routeGrpIdx;
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */
  Std_ReturnType retVal = E_NOT_OK;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_DISABLE_SPECIFIC_ROUTING,
    SOAD_E_NOTINIT, E_NOT_OK);
#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
  SOAD_GetRouteGrpIdxCheckDetErrorReturnValue(routeGrpIdx, id, SOAD_API_ID_DISABLE_SPECIFIC_ROUTING, E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_DISABLE_SPECIFIC_ROUTING, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
    uint16 pduDestNum = 0;

    if ( SoAd_IsRouteGrpIdx2PduRouteDestColPresent() )
    {
      pduDestNum = SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).PduRouteDestListSize;
    }

    /* disable routing for specific socket connection */
    while ( 0u < pduDestNum )
    {
      pduDestNum--;

      if ( soConIdx == SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).PduRouteDestListPtr[pduDestNum]->SoConIdx )
      {
        /* PRQA S 0277 2 */ /* MD_SoAd_3.1 */
        *SoAd_RouteGrpIdx2PduRouteDestCol(routeGrpIdx).StateColPtr[pduDestNum] &=
          (uint8)(~SOAD_ROUT_GRP_BIT_PATTERN_ENABLED);
        retVal = E_OK;

        /* do not break here since multiple PduRouteDests are possible per socket connection */
      }
    }
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */

# if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
    if ( SoAd_IsRouteGrpIdx2SocketRouteColPresent() )
    {
      if ( SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxNum > 0u )
      { /* socket connections has SocketRoutes */
        uint16 sockRouteNum = SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).IdNum;

        /* disable routing for specific socket connection */
        while ( 0u < sockRouteNum )
        {
          uint16 sockRouteIdx;
          uint16 sockRouteIdxStart = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxStart;
          uint16 sockRouteIdxEnd = (uint16)(sockRouteIdxStart +
            SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxNum - 1u);

          sockRouteNum--;
          sockRouteIdx = SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).IdColPtr[sockRouteNum];

          if ( (sockRouteIdx >= sockRouteIdxStart) && (sockRouteIdx <= sockRouteIdxEnd) )
          {
            /* PRQA S 0277 2 */ /* MD_SoAd_3.1 */
            *SoAd_RouteGrpIdx2SocketRouteCol(routeGrpIdx).StateColPtr[sockRouteNum] &=
              (uint8)(~SOAD_ROUT_GRP_BIT_PATTERN_ENABLED);
            retVal = E_OK;

            /* do not break here since multiple SocketRoutes are possible per socket connection */
          }
        }
      }
    }
# endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && (STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
  }

  return retVal;
#else
  SOAD_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(SoConId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CallDetReportError(SOAD_API_ID_DISABLE_SPECIFIC_ROUTING, SOAD_E_INV_ARG);
  return retVal;
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_SetRemoteAddr
 *********************************************************************************************************************/
/*! \brief      sets the remote address struct of a specified socket connection
 *  \param[in]  SoConId        socket connection index
 *  \param[in]  RemoteAddrPtr  pointer to remote IP address struct
 *  \return     E_OK           request was successful
 *  \return     E_NOT_OK       request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 3673 2 */ /* MD_SoAd_16.7 */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetRemoteAddr(SoAd_SoConIdType SoConId,
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_SET_REMOTE_ADDR, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_SET_REMOTE_ADDR, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != RemoteAddrPtr), SOAD_API_ID_SET_REMOTE_ADDR, SOAD_E_PARAM_POINTER,
    E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
    /* check whether socket connection has automatic socket connection setup configured */
    if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SockAutoSoConSetup != TRUE )
    { /* no automatic socket connection setup configured - SetRemoteAddr is allowed to be called */
      if ( SoAd_SockCons(soConIdx).SockConGrpPtr->Domain == RemoteAddrPtr->domain )
      { /* same domain type (IPv4/IPv6) */
        if ( (SOAD_SOCON_OFFLINE == SoAd_SockConIdx2State(soConIdx)) ||
          (SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_UDP) )
        { /* remote address shall only be set if socket connection is OFFLINE or
           * socket connection is UDP and no TP session is active */
          /* Check for active TP session or IF transmission */
          /* PRQA S 0277 2 */ /* MD_SoAd_3.1 */
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
          if ( (SoAd_IsSockRoutePresent() && (SOAD_INV_PDU_ID == SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx)) ||
            (!SoAd_IsSockRoutePresent()))
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
          {
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
            if ( ( SoAd_IsPduRoutePresent() && (SOAD_INV_PDU_IDX == SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx)) ||
              (!SoAd_IsPduRoutePresent()))
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
            { /* no transmissions or TP sessions (Tx or Rx) are active */
              SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
              retVal = SoAd_VCheckAndSetRemoteAddr(soConIdx, RemoteAddrPtr);
              if ( retVal == E_OK)
              {
                /* check if socket connection is online and needs to be reset to SOAD_SOCON_RECONNECT */
                if ( (SoAd_SockConIdx2State(soConIdx) == SOAD_SOCON_ONLINE) &&
                  (0u != (SoAd_SockConIdx2RemAddrState(soConIdx) & SOAD_SOCON_MASK_ANY)) )
                { /* UDP socket connection in mode SOAD_SOCON_ONLINE and remote address contains wildcards */
                  SoAd_SockConIdx2State(soConIdx) = SOAD_SOCON_RECONNECT;
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  SoAd_VCallChgFunc(soConIdx, SoAd_SockCons(soConIdx).SoConChgFuncBitPattern,
                    SOAD_CHG_FUNC_TYPE_SOCONMODE, SOAD_SOCON_RECONNECT);
                }
                else
                {
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  /* set event to handle socket connection state in main function */
                  SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
                }
              }
              else
              {
                SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
              }
            }
          }
        }
      }
      else
      { /* domain type mismatch */
        SOAD_CallDetReportError(SOAD_API_ID_SET_REMOTE_ADDR, SOAD_E_INV_ARG);
      }
    }
    else
    { /* to set the remote address of a socket connection with automatic setup is forbidden */
      SOAD_CallDetReportError(SOAD_API_ID_SET_REMOTE_ADDR, SOAD_E_INV_ARG);
    }
  }

  return retVal;
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
/* PRQA L:MSR_147 */

/**********************************************************************************************************************
 *  SoAd_SetUniqueRemoteAddr
 *********************************************************************************************************************/
/*! \brief      sets the remote address of the socket connection specified by SoConId or an unsused socket of the
 *              same socket connection group
 *  \param[in]  SoConId             socket connection index
 *  \param[in]  RemoteAddrPtr       pointer to remote IP address struct
 *  \param[out] AssignedSoConIdPtr  pointer to return socket connection
 *  \return     E_OK           request was successful
 *  \return     E_NOT_OK       request was not successful
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
/* PRQA S 3673 2 */ /* MD_SoAd_16.7 */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SetUniqueRemoteAddr(SoAd_SoConIdType SoConId,
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr,
                      P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_VAR) AssignedSoConIdPtr)
{
  SoAd_SoConIdxType soConIdx, assignedSoConIdx;
  Std_ReturnType    retVal = E_NOT_OK;
  boolean           ipAddrIsAny = FALSE;
  boolean           portIsAny = FALSE;

  /* PRQA S 3109 9 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_SET_UNI_REMOTE_ADDR, SOAD_E_NOTINIT,
    E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_SET_UNI_REMOTE_ADDR, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != RemoteAddrPtr), SOAD_API_ID_SET_UNI_REMOTE_ADDR, SOAD_E_PARAM_POINTER,
    E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != AssignedSoConIdPtr), SOAD_API_ID_SET_UNI_REMOTE_ADDR,
    SOAD_E_PARAM_POINTER, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((RemoteAddrPtr->domain == SoAd_SockCons(soConIdx).RemSockPtr->domain),
    SOAD_API_ID_SET_UNI_REMOTE_ADDR, SOAD_E_INV_ARG, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
    SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* check remote address */
    SoAd_VCheckForWildcards(RemoteAddrPtr, &ipAddrIsAny, &portIsAny);

    /* PRQA S 3355 1 */ /* MD_SoAd_13.7_SUB */
    if ( (TRUE != ipAddrIsAny) && (TRUE != portIsAny) )
    { /* remote address is valid to be set */
      /* get all socket connections of socket connection group */
      SoAd_SoConIdxType soConIdxStart;
      SoAd_SoConIdxType soConIdxMax;

#if ( defined(SOAD_VTCP_USED) && (SOAD_VTCP_USED) )
      if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr != NULL_PTR )
      { /* TCP socket */
        if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr->TcpInitiate == TRUE )
        { /* TCP client socket */
          SoAd_SoConIdxType soConIdxTmp = SoAd_SockConTotal();

          soConIdxStart = 0u;
          soConIdxMax = SOAD_INV_SO_CON_ID;
          while ( soConIdxTmp > 0 )
          {
            soConIdxTmp--;

            if ( SoAd_SockCons(soConIdxTmp).SockConGrpPtr == SoAd_SockCons(soConIdx).SockConGrpPtr )
            {
              if ( soConIdxMax == SOAD_INV_SO_CON_IDX )
              {
                soConIdxMax = soConIdxTmp;
              }
              soConIdxStart = soConIdxTmp;
            }
          }
        }
        else
        { /* TCP server socket */
          soConIdxStart = SoAd_SockIdx2SoConIdxCol(SoAd_SockCons(soConIdx).SockConGrpPtr->GrpSockIdx).SoConIdxStart;
          soConIdxMax = (SoAd_SoConIdxType)(soConIdxStart + SoAd_SockIdx2SoConIdxCol(
            SoAd_SockCons(soConIdx).SockConGrpPtr->GrpSockIdx).SoConIdxNum - 1u);
        }
      }
      else
#endif /* defined(SOAD_VTCP_USED) && (SOAD_VTCP_USED) */
      { /* UDP Socket */
        soConIdxStart = SoAd_SockIdx2SoConIdxCol(SoAd_SockCons(soConIdx).SockConGrpPtr->GrpSockIdx).SoConIdxStart;
        soConIdxMax = (SoAd_SoConIdxType)(soConIdxStart + SoAd_SockIdx2SoConIdxCol(
          SoAd_SockCons(soConIdx).SockConGrpPtr->GrpSockIdx).SoConIdxNum - 1u);
      }

      /* get socket connection by best match algorithm */
      /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
      if ( E_OK == SoAd_VGetSoConIdByBestMatchAlg(RemoteAddrPtr, soConIdxStart, soConIdxMax,
          SOAD_SOCON_FILTER_DISABLED, FALSE, &assignedSoConIdx) )
      { /* socket connection found */
        *AssignedSoConIdPtr = SoAd_SockCons(assignedSoConIdx).SoConId;

        if ( SOAD_SOCON_IP_SET_PORT_SET == SoAd_SockConIdx2RemAddrState(assignedSoConIdx) )
        { /* remote address is already set */
          retVal = E_OK;
        }
        else
        {
#if ( defined(SOAD_VTCP_USED) && (SOAD_VTCP_USED) )
          if ( SoAd_SockCons(assignedSoConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP )
          { /* TCP socket */
            if ( SOAD_SOCK_STATE_CLOSED == SoAd_SockIdx2SockState(SoAd_SockCons(assignedSoConIdx).SockIdx) )
            { /* TcpIp socket is closed */
              /* set remote address */
              if ( SoAd_VCheckAndSetRemoteAddr(assignedSoConIdx, RemoteAddrPtr) == E_OK )
              {
                /* set event to handle socket connection state in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);

                retVal = E_OK;
              }
            }
          }
          else
#endif /* defined(SOAD_VTCP_USED) && (SOAD_VTCP_USED) */
          { /* UDP socket */
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
            if ( (!SoAd_IsPduRoutePresent()) ||
              (SoAd_SockIdx2ActiveSoConIdx(SoAd_SockCons(assignedSoConIdx).SockIdx) != assignedSoConIdx) )
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
            { /* no transmission is active */
              /* set remote address */
              if ( E_OK == SoAd_VCheckAndSetRemoteAddr(assignedSoConIdx, RemoteAddrPtr) )
              { /* remote address set successfully */
#if ( defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) )
                if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt != 0u )
                { /* alive timeout is configured */
                  /* remove timeout from list */
                  SoAd_VTimeoutListRemoveElement(SoAd_TimeoutListIdxUdpAlive(), soConIdx);
                }
#endif /* defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) */

                /* set event to handle socket connection state in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);

                retVal = E_OK;
              }
            }
          }
        }
      }
    }
    SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_TpChangeParameter
 *********************************************************************************************************************/
/*! \brief      This service is used to request the change of a specific connection parameter
 *  \param[in]  id              PDU identifier
 *  \param[in]  parameter       parameter identifier
 *  \param[in]  value           new parameter value
 *  \return     E_NOT_OK        request is not accepted
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 3206 3 */ /* MD_SoAd_3206 */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpChangeParameter(PduIdType id,
                      TPParameterType parameter,
                      uint16 value )
{
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TP_CHANGE_PARAMETER, SOAD_E_NOTINIT,
        E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((SoAd_PduRouteTotal() > id), SOAD_API_ID_TP_CHANGE_PARAMETER, SOAD_E_INV_ARG,
        E_NOT_OK);

  /* function is implemented without functionality as no requriements are available */

  SOAD_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(parameter); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(value); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  return E_NOT_OK;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_ReadDhcpHostNameOption
 *********************************************************************************************************************/
/*! \brief          This service is used to get the currently configured DHCP hostname option.
 *  \param[in]      SoConId     socket connection identifier
 *  \param[in/out]  length      length of provided data buffer, will be overwritten by actual hostname data
 *  \param[out]     data        pointer to memory where the hostname data shall be written to
 *  \return         E_OK        request is accepted
 *  \return         E_NOT_OK    request is not accepted
 *  \context        task level
 *********************************************************************************************************************/
/* PRQA S 3673 3 */ /* MD_SoAd_16.7 */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_ReadDhcpHostNameOption(SoAd_SoConIdType SoConId,
                      P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) length,
                      P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) data)
{
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 7 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_READ_DHCP_HOST_NAME_OPT,
    SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != length), SOAD_API_ID_READ_DHCP_HOST_NAME_OPT,
    SOAD_E_PARAM_POINTER, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != data), SOAD_API_ID_READ_DHCP_HOST_NAME_OPT,
    SOAD_E_PARAM_POINTER, E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_READ_DHCP_HOST_NAME_OPT, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
    SOAD_DUMMY_STATEMENT_VAR(SoConId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

    if ( 0 == gethostname((char*)data, *length) ) /* PRQA S 5013 */ /* MD_SoAd_6.3 */
    { /* host name obtained */
      uint8 idx = 0u;

      /* get length */
      while ( idx < *length )
      {
        if ( 0 == data[idx] )
        { /* string termination reached */
          *length = idx;
          return E_OK;
        }
        idx++;
      }
    }
    else
    {
      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
      SOAD_REPORT_SOCK_ERROR_PARAM_1(SOAD_SOCK_API_READ_HOST_NAME, SOAD_SOCK_BSD_API_GET_HOST_NAME,
        SOAD_SOCK_BSD_PARAM_NONE, SoConId, errno);
    }
#else
# if ( defined(SOAD_VDHCPV6_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV6_CLIENT_ENABLED) )
    if ( SOAD_AF_INET6 == SoAd_SockCons(soConIdx).SockConGrpPtr->Domain )
    {
      Std_ReturnType retVal;
      uint16 tmpLength = *length;

      if ( E_OK == TcpIp_DhcpV6ReadOption(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId,
          SOAD_DHCP_OPT_V6_HOSTNAME, &tmpLength, data) )
      {
        *length = (uint8)tmpLength;
        return E_OK;
      }
      return E_NOT_OK;
    }
# endif /* defined(SOAD_VDHCPV6_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV6_CLIENT_ENABLED) */
# if ( defined(SOAD_VDHCPV4_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV4_CLIENT_ENABLED) )
    if ( SOAD_AF_INET == SoAd_SockCons(soConIdx).SockConGrpPtr->Domain )
    {
      return TcpIp_DhcpReadOption(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId, SOAD_DHCP_OPT_V4_HOSTNAME,
        length, data);
    }
# endif /* defined(SOAD_VDHCPV4_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV4_CLIENT_ENABLED) */
# if ( (defined(SOAD_VDHCPV6_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV6_CLIENT_ENABLED)) || \
  (defined(SOAD_VDHCPV4_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV4_CLIENT_ENABLED)) )
# else
    SOAD_DUMMY_STATEMENT_VAR(SoConId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
    SOAD_DUMMY_STATEMENT_VAR(length); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
    SOAD_DUMMY_STATEMENT_VAR(data); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif /* (defined(SOAD_VDHCPV6_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV6_CLIENT_ENABLED)) || \
  (defined(SOAD_VDHCPV4_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV4_CLIENT_ENABLED)) */
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
  }

  return E_NOT_OK;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_WriteDhcpHostNameOption
 *********************************************************************************************************************/
/*! \brief      This service is used to set the DHCP hostname option.
 *  \param[in]  SoConId     socket connection identifier
 *  \param[in]  length      length of provided data buffer, will be overwritten by actual hostname data
 *  \param[in]  data        pointer to memory where the hostname data shall be written to
 *  \return     E_OK        request is accepted
 *  \return     E_NOT_OK    request is not accepted
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 3206 3 */ /* MD_SoAd_3206 */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_WriteDhcpHostNameOption(SoAd_SoConIdType SoConId,
                      uint8 length,
                      P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) data)
{
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_WRITE_DHCP_HOST_NAME_OPT,
    SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != data), SOAD_API_ID_WRITE_DHCP_HOST_NAME_OPT,
    SOAD_E_PARAM_POINTER, E_NOT_OK);
  SOAD_GetSockConIdxCheckDetErrorReturnValue(soConIdx, SoConId, SOAD_API_ID_WRITE_DHCP_HOST_NAME_OPT, E_NOT_OK);

  if ( SOAD_STATE_INIT == SoAd_State )
  {
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
    if ( 0 == sethostname((const char*)data, length) ) /* PRQA S 5013 */ /* MD_SoAd_6.3 */
    { /* host name set */
      return E_OK;
    }
    else
    {
      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
      SOAD_REPORT_SOCK_ERROR_PARAM_1(SOAD_SOCK_API_WRITE_HOST_NAME, SOAD_SOCK_BSD_API_SET_HOST_NAME,
        SOAD_SOCK_BSD_PARAM_NONE, SoConId, errno);
    }
#else
# if ( defined(SOAD_VDHCPV6_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV6_CLIENT_ENABLED) )
    if ( SOAD_AF_INET6 == SoAd_SockCons(soConIdx).SockConGrpPtr->Domain )
    {
      return TcpIp_DhcpV6WriteOption(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId, SOAD_DHCP_OPT_V6_HOSTNAME,
        length, data);
    }
# endif /* defined(SOAD_VDHCPV6_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV6_CLIENT_ENABLED) */
# if ( defined(SOAD_VDHCPV4_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV4_CLIENT_ENABLED) )
    if ( SOAD_AF_INET == SoAd_SockCons(soConIdx).SockConGrpPtr->Domain )
    {
      return TcpIp_DhcpWriteOption(SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId, SOAD_DHCP_OPT_V4_HOSTNAME,
        length, data);
    }
# endif /* defined(SOAD_VDHCPV4_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV4_CLIENT_ENABLED) */
# if ( (defined(SOAD_VDHCPV6_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV6_CLIENT_ENABLED)) || \
  (defined(SOAD_VDHCPV4_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV4_CLIENT_ENABLED)) )
# else
    SOAD_DUMMY_STATEMENT_VAR(length); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
    SOAD_DUMMY_STATEMENT_VAR(data); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif /* (defined(SOAD_VDHCPV6_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV6_CLIENT_ENABLED)) || \
  (defined(SOAD_VDHCPV4_CLIENT_ENABLED) && (STD_ON == SOAD_VDHCPV4_CLIENT_ENABLED)) */
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
  }

  return E_NOT_OK;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief      get version information
 *  \param[in]  versionInfo        pointer for version information
 *  \context    initialization or task level
 *********************************************************************************************************************/
#if ( defined(SOAD_VERSION_INFO_API) && (STD_ON == SOAD_VERSION_INFO_API) )
FUNC(void, SOAD_CODE) SoAd_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SOAD_APPL_VAR) versionInfo)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnVoid((NULL_PTR != versionInfo), SOAD_API_ID_GET_VERSION_INFO, SOAD_E_PARAM_POINTER);

  versionInfo->vendorID         = SOAD_VENDOR_ID;
  versionInfo->moduleID         = SOAD_MODULE_ID;
  versionInfo->sw_major_version = SOAD_SW_MAJOR_VERSION;
  versionInfo->sw_minor_version = SOAD_SW_MINOR_VERSION;
  versionInfo->sw_patch_version = SOAD_SW_PATCH_VERSION;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* defined(SOAD_VERSION_INFO_API) && (STD_ON == SOAD_VERSION_INFO_API) */

/**********************************************************************************************************************
 *  SoAd_MainFunctionRx
 *********************************************************************************************************************/
/*! \brief      receives pending data and handles socket states in case of BSD-Socket-API
 *  \param[in]  void none
 *  \return     none
 *  \pre        module initialized
 *  \context    task level
 *  \note       do not call in case SoAdMainFunctionSplitEnabled is disabled
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 3408 MSR_88 */ /* MD_MSR_8.8 */
FUNC(void, SOAD_CODE) SoAd_MainFunctionRx(void)
{
#if ( SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_ON )
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnVoid((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_MAIN_FUNCTION_RX, SOAD_E_NOTINIT);
#endif /* SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_ON */

#if ( (SOAD_VSOCKET_BSD_API_ENABLED == STD_ON) || (SOAD_VSOCKET_ROUTES == STD_ON) )
  if ( SOAD_STATE_INIT == SoAd_State )
  {
# if ( SOAD_VSOCKET_BSD_API_ENABLED == STD_ON )
    SoAd_VHandleSocketReception();
# endif /* SOAD_VSOCKET_BSD_API_ENABLED == STD_ON */

# if ( SOAD_VSOCKET_ROUTES == STD_ON )
    if ( SoAd_IsEventQueueIdxTpRxSoConPresent() )
    { /* handle TP reception */
      SoAd_VHandleTpReception();
    }
# endif /* SOAD_VSOCKET_ROUTES == STD_ON */
  }
#endif /* (SOAD_VSOCKET_BSD_API_ENABLED == STD_ON) || (SOAD_VSOCKET_ROUTES == STD_ON) */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_88 */

/**********************************************************************************************************************
 *  SoAd_MainFunctionState
 *********************************************************************************************************************/
/*! \brief      handles socket/socket connection states, module shutdown states and timeouts
 *  \param[in]  void none
 *  \return     none
 *  \pre        module initialized
 *  \context    task level
 *  \note       do not call in case SoAdMainFunctionSplitEnabled is disabled
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 3408 MSR_88 */ /* MD_MSR_8.8 */
FUNC(void, SOAD_CODE) SoAd_MainFunctionState(void)
{
#if ( SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_ON )
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnVoid((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_MAIN_FUNCTION_STATE, SOAD_E_NOTINIT);

#else
  if ( SoAd_State != SOAD_STATE_SHUTDOWN )
#endif /* SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_ON */
  {
    if ( SoAd_State == SOAD_STATE_SHUTDOWN_IN_PROGRESSS )
    {
      SoAd_VHandleShutdown();
    }
#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
    else if ( SoAd_State == SOAD_STATE_INIT )
    {
      /* handle IP address assignment states */
      SoAd_VHandleIpAddrStates();

      /* handle TCP socket states */
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
      SoAd_VHandleTcpSocketStates();
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
    }
    else
    {
      /* nothing to do */
    }
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

#if ( SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON )
    /* handle alive supervision timeout */
    if ( SoAd_IsTimeoutListIdxUdpAlivePresent() )
    {
      SoAd_VHandleUdpAliveTimeout();
    }
#endif /* SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON */

    /* handle socket connection states */
    SoAd_VHandleSoConStates();

    if ( SoAd_State == SOAD_STATE_SHUTDOWN_IN_PROGRESSS )
    {
      SoAd_VHandleShutdownFinish();
    }
  }

#if ( (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) || (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) )
  /* handle global timer counter */
  /* has to be handled at the end of this main function since timeouts for transmission (nPdu) are set in this context
     which would be overwritten in each call to this main function and no transmission would be performed in context of
     the transmission main function */
  SoAd_GlobalCounter++;
#endif /* (SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON) || (SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON) */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_88 */

/**********************************************************************************************************************
 *  SoAd_MainFunctionTx
 *********************************************************************************************************************/
/*! \brief      transmits pending data (TP, nPdu, routing groups) and handles TxConfirmation
 *  \param[in]  void none
 *  \return     none
 *  \pre        module initialized
 *  \context    task level
 *  \note       do not call in case SoAdMainFunctionSplitEnabled is disabled
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 3408 MSR_88 */ /* MD_MSR_8.8 */
FUNC(void, SOAD_CODE) SoAd_MainFunctionTx(void)
{
#if ( SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_ON )
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnVoid((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_MAIN_FUNCTION_TX, SOAD_E_NOTINIT);
#endif /* SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_ON */

#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  if ( SoAd_IsPduRoutePresent() )
  {
# if ( SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_OFF )
    if ( SoAd_State != SOAD_STATE_SHUTDOWN )
# endif /* SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_OFF */
    {
      /* handle TP and TCP transmission */
      if ( SoAd_IsEventQueueIdxTxSoConPresent() )
      {
        SoAd_VHandleTpAndTcpTransmission();
      }

      /* handle IfRoutingGroupTransmit requests */
# if ( SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED == STD_ON )
      if ( SoAd_IsEventQueueIdxIfTxRouteGrpPresent() )
      {
        SoAd_VHandleIfRouteGrpTransmit();
      }
#  endif /* SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED == STD_ON */

      /* UdpTriggerTimeout for nPduUdpTx */
# if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
      if ( SoAd_IsNPduUdpTxPresent() )
      {
        SoAd_VHandleNPduUdpTx();
      }
# endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */

      /* handle pending TxConfirmations */
      if ( SoAd_IsEventQueueIdxIfUdpPduRoutePresent() )
      {
        SoAd_VHandleTxConfirmation();
      }
    }
  }
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_88 */

/**********************************************************************************************************************
 *  SoAd_MainFunction
 *********************************************************************************************************************/
/*! \brief      handles states, pending transmissions and pending receptions
 *  \param[in]  void none
 *  \return     none
 *  \pre        module initialized
 *  \context    task level
 *  \note       do not call in case SoAdMainFunctionSplitEnabled is enabled
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 3408 MSR_88 */ /* MD_MSR_8.8 */
FUNC(void, SOAD_CODE) SoAd_MainFunction(void)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnVoid((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_MAIN_FUNCTION, SOAD_E_NOTINIT);

#if ( SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_ON )
  if ( SoAd_State != SOAD_STATE_SHUTDOWN )
  {
    /* call main function for reception */
# if ( (SOAD_VSOCKET_BSD_API_ENABLED == STD_ON) || (SOAD_VSOCKET_ROUTES == STD_ON) )
    SoAd_MainFunctionRx();
# endif /* (SOAD_VSOCKET_BSD_API_ENABLED == STD_ON) || (SOAD_VSOCKET_ROUTES == STD_ON) */

    /* call main function for states */
    SoAd_MainFunctionState();

    /* call main function for transmission */
# if ( SOAD_VPDU_ROUTES == STD_ON )
    SoAd_MainFunctionTx();
# endif /* SOAD_VPDU_ROUTES == STD_ON */
  }
#endif /* SOAD_VSINGLE_MAIN_FUNCTION_ENABLED == STD_ON */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_88 */

/**********************************************************************************************************************
 *  SoAd_RxIndication
 *********************************************************************************************************************/
/*! \brief      receive indication
 *  \param[in]  SocketId        socket identifier
 *  \param[in]  RemoteAddrPtr   address the message is received from
 *  \param[in]  BufPtr          pointer to received data
 *  \param[in]  Length          length of received data
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(void, SOAD_CODE) SoAd_RxIndication(SoAd_SocketIdType SocketId,
                                        P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        uint16 Length)
{
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
  P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) locBufPtr = BufPtr;
  SoAd_SockIdxType  sockIdx;
  SoAd_SoConIdxType soConIdx;
  uint16            routeIdx;
  uint16            routeNum;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */ /* PRQA S 0277 2 */ /* MD_SoAd_3.1 */
  SOAD_CheckDetErrorReturnVoid((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_RX_INDICATION, SOAD_E_NOTINIT);
  SOAD_CheckDetErrorReturnVoid((SOAD_INV_SOCKET_ID != SocketId), SOAD_API_ID_RX_INDICATION, SOAD_E_INV_SOCKETID);
  SOAD_CheckDetErrorReturnVoid((NULL_PTR != RemoteAddrPtr), SOAD_API_ID_RX_INDICATION, SOAD_E_PARAM_POINTER);
  SOAD_CheckDetErrorReturnVoid((NULL_PTR != BufPtr), SOAD_API_ID_RX_INDICATION, SOAD_E_PARAM_POINTER);

  if ( SOAD_STATE_INIT != SoAd_State )
  {
    return;
  }

  /* check if socket routes are configured */
  if ( !SoAd_IsSockRoutePresent() )
  {
    return;
  }

  /* get and validate sockIdx */
  sockIdx = SoAd_VGetSockIdxBySocketId(SocketId);
  if ( SOAD_INV_SOCK_IDX == sockIdx )
  {
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    SOAD_CallDetReportError(SOAD_API_ID_RX_INDICATION, SOAD_E_INV_SOCKETID);
    return;
  }

  /* check whether any socket connection is configured for this socket */
  if ( SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum == 0u )
  {
    return;
  }
  /* get first socket connection identifier */
  soConIdx = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;

  /* verify IP Assignment state */
  if ( SOAD_IPADDR_STATE_ASSIGNED != SoAd_SockConIdx2IpAddrState(soConIdx) )
  {
    return;
  }

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  /* validate socket state */
  if ( (SOAD_SOCK_STATE_ESTABLISHED != SoAd_SockIdx2SockState(sockIdx)) &&
    (SOAD_SOCK_STATE_LISTEN != SoAd_SockIdx2SockState(sockIdx)) )
  { /* socket is not in expected mode */
    return;
  }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */

  /* validate length */
  if ( 0u == Length )
  { /* no data received */
    return;
  }

  /* validate socket address */
  if ( (RemoteAddrPtr->domain != SOAD_AF_INET)
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    && (RemoteAddrPtr->domain != SOAD_AF_INET6)
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    )
  { /* invalid remote address */
    SOAD_CallDetReportError(SOAD_API_ID_RX_INDICATION, SOAD_E_INV_ARG);
    return;
  }

  /* get corresponding socket connection index */
# if ( defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) )
  /* check whether the best match algorithm considers the PDU Header for this socket */
  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->BestMatchWithPduHeaderEnabled != TRUE)
# endif /* defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) */
  { /* use the best match algorithm according to AUTOSAR */
    if ( SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum > 1u )
    { /* more than one socket connection is configured for this socket - use the best match algorithm */
      SoAd_SoConIdxType soConIdxStart = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;
      SoAd_SoConIdxType soConIdxMax = (SoAd_SoConIdxType)(soConIdxStart +
        SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum - 1u);

      if ( E_OK != SoAd_VGetSoConIdByBestMatchAlg(RemoteAddrPtr, soConIdxStart, soConIdxMax, SOAD_SOCON_FILTER_DISABLED,
# if ( defined(SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) )
          SoAd_SockCons(soConIdx).SockConGrpPtr->BestMatchWithSockRouteEnabled,
# else
          FALSE,
# endif /* defined(SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) */
          &soConIdx) )
      { /* no suitable socket connection found */
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
        if (SoAd_SockCons(SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP)
        { /* socket is TCP */
          (void)SoAd_VTcpIpReceived(SocketId, Length);
        }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
        return;
      }
    }

    /* get all affected socket routes */
    routeIdx = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxStart;
    routeNum = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxNum;

    if ( 0u == routeNum )
    { /* no socket route configured for this socket connection */
      /* abort reception */
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
      if (SoAd_SockCons(SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP)
      { /* socket is TCP */
        (void)SoAd_VTcpIpReceived(SocketId, Length);
      }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
      return;
    }

    /* validate transmission/reception state */
    if ( SOAD_CLOSE_NONE != SoAd_SockConIdx2CloseMode(soConIdx) )
    { /* transmission/reception is disabled (by a previous socket connection close request ) */
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
      if (SoAd_SockCons(SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP)
      { /* socket is TCP */
        (void)SoAd_VTcpIpReceived(SocketId, Length);
      }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
      return;
    }

    /* use message acceptance policy if configured */
    if ( SoAd_SockCons(soConIdx).SockConGrpPtr->MsgAcceptFilterEnabled == TRUE )
    {
      if ( E_OK != SoAd_VCompareSockAddr((SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(soConIdx), RemoteAddrPtr,
        TRUE) )
      { /* message is not accepted */
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
        if (SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP)
        { /* socket is TCP */
          (void)SoAd_VTcpIpReceived(SocketId, Length);
        }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
        return;
      }
    }

    /* validate socket connection state */
    if ( SOAD_SOCON_ONLINE != SoAd_SockConIdx2State(soConIdx) )
    { /* socket connection is not online - this is only allowed in specific cases */
      Std_ReturnType retVal = E_NOT_OK;

      /* check whether specific case is applicable */
      if ( (SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_UDP) &&
        (SoAd_SockCons(soConIdx).SockConGrpPtr->MsgAcceptFilterEnabled == TRUE) )
      { /* socket connection is UDP and message acceptance filter is enabled */
        if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpListenOnly == FALSE )
        { /* UDP listen only not enabled */
          if ( (0u < (SoAd_SockConIdx2RemAddrState(soConIdx) & SOAD_SOCON_MASK_ANY)) &&
            (0u == (SoAd_SockConIdx2RemAddrState(soConIdx) & SOAD_SOCON_MASK_NOT)) )
          { /* remote address is set but contains wildcards */
            retVal = E_OK;
# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
            if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == FALSE )
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
            { /* PDU header disabled means that only one SocketRouteDest(TP) is possible for this socket connection */
              if ( SOAD_UL_TYPE_TP == SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer )
              { /* TP SocketRouteDest */
#  if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
                /* check if routing group is enabled */
                if ( TRUE != SoAd_VCheckAnyRoutGrpOnSockRouteDestEnabled(routeIdx) )
                { /* routing group is not enabled - do not open socket connection */
                  retVal = E_NOT_OK;
                }
#  endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
              }
            }
          }
          if ( E_OK == retVal )
          {
            /* open socket connection and update remote address */
            SoAd_VCopyIpAddr((SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(soConIdx), RemoteAddrPtr, FALSE);
            SoAd_SockConIdx2RemAddrState(soConIdx) = SOAD_SOCON_IP_SET_PORT_SET;
            SoAd_SockConIdx2State(soConIdx) = SOAD_SOCON_ONLINE;
# if ( defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) )
            /* check if an alive timeout is configured */
            if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt != 0u )
            {
              /* return value has not to be considered since this timeout is always sufficient */
              (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxUdpAlive(), soConIdx,
                SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt, SoAd_GlobalCounter);
            }
# endif /* defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) */
            /* inform upper layer about socket connection state change */
            SoAd_VCallChgFunc(soConIdx, SoAd_SockCons(soConIdx).SoConChgFuncBitPattern,
              SOAD_CHG_FUNC_TYPE_SOCONMODE, SOAD_SOCON_ONLINE);
# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
            if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == FALSE )
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
            { /* PDU header disabled means that only one SocketRouteDest(TP) is possible for this socket connection */
              if ( SOAD_UL_TYPE_TP == SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer )
              { /* TP without Pdu header option */
                PduLengthType dummyLen = 0u;

                /* call StartOfReception */
                if ( BUFREQ_OK != SoAd_VCallTpStartOfReception(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                    SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId,
                    0u,
                    &dummyLen) )
                {
                  retVal = E_NOT_OK;
                  SoAd_SockConIdx2CloseMode(soConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                  /* set event to handle socket connection state in main function */
                  SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
                }
                else
                {
                  SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx = routeIdx;
                }
              }
            }
          }
        }
      }
      if ( E_OK != retVal )
      { /* reception on this socket connection while socket connection is not online is not valid */
        return;
      }
    }
# if ( defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) )
    else
    {
      /* check if an alive timeout is configured */
      if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr != NULL_PTR )
      {
        if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt != 0u )
        { /* alive timeout is configured */
          uint32 currentTimeoutCnt = 0u;

          /* check whether socket connection was opened by a reception (i.e. timer is already running) */
          if ( SoAd_VTimeoutListGetCurrentTimeout(SoAd_TimeoutListIdxUdpAlive(), soConIdx, &currentTimeoutCnt,
              SoAd_GlobalCounter) == E_OK )
          { /* opened by a reception */
            /* set new timeout */
            /* return value has not to be considered since timeout ist already in list */
            (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxUdpAlive(), soConIdx,
              SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt, SoAd_GlobalCounter);
          }
        }
      }
    }
# endif /* defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) */

# if ( defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) )
    /* update received remote address */
    if ( NULL_PTR != SoAd_SockCons(soConIdx).RcvRemSockPtr )
    { /* get recevied remote address is supported */
      SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      /* copy remote address to local buffer */
      SoAd_VCopyIpAddr(SoAd_SockCons(soConIdx).RcvRemSockPtr, RemoteAddrPtr, TRUE);
      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
# endif /* defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) */

    /* skip PDU if invalid PDU was received */
    if ( 0u < SoAd_SockIdx2SkipBytes(sockIdx) )
    {
      if ( Length < SoAd_SockIdx2SkipBytes(sockIdx) )
      {
        SoAd_SockIdx2SkipBytes(sockIdx) -= Length;
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
        if (SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP)
        { /* socket is TCP */
          (void)SoAd_VTcpIpReceived(SocketId, Length);
        }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
        return;
      }
      else
      {
        Length -= (uint16)SoAd_SockIdx2SkipBytes(sockIdx);
        locBufPtr = &BufPtr[SoAd_SockIdx2SkipBytes(sockIdx)];
        SoAd_SockIdx2SkipBytes(sockIdx) = 0u;
      }
    }
  }

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP)
  { /* TCP socket */
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
    if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
    { /* PDU Header enabled */
      SoAd_VTcpPduHdrRxIndication(soConIdx, locBufPtr, Length);
    }
    else
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
    { /* PDU Header disabled */
      SoAd_VTcpRxIndication(soConIdx, locBufPtr, Length);
    }
  }
  else
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
  { /* UDP socket */
# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
    if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
    {
      SoAd_VUdpPduHdrRxIndication(soConIdx, RemoteAddrPtr, locBufPtr, Length);
    }
    else
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
    {
      SoAd_VUdpRxIndication(soConIdx, locBufPtr, Length);
    }
  }
#else
  SOAD_DUMMY_STATEMENT_VAR(SocketId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(RemoteAddrPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(BufPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(Length); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CallDetReportError(SOAD_API_ID_RX_INDICATION, SOAD_E_INV_ARG);
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_CopyTxData
 *********************************************************************************************************************/
/*! \brief          service request to copy data for transmission to the buffer provided by TcpIp
 *  \param[in]      SocketId                socket identifier of the related local socket
 *  \param[in]      BufPtr                  pointer to provided transmission buffer
 *  \param[in/out]  BufLength|BufLengthPtr  length of provided transmission buffer
 *  \context        interrupt or task level
 *  \note           with SoAdTxDynamicLengthEnabled last parameter is used as in/out parameter to return length of
 *                  copied data
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 0771 SoAd_146 */ /* MD_SoAd_14.6 */
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_CopyTxData(SoAd_SocketIdType SocketId,
                                                   uint8* BufPtr,
#if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
                                                   uint16* BufLengthPtr
#else
                                                   uint16 BufLength
#endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
                                                   )
{
#if ( SOAD_VPDU_ROUTES == STD_ON )
  SoAd_SockIdxType  sockIdx;
  SoAd_SoConIdxType soConIdx;
  SoAd_PduIdxType   txPduIdx;
  PduLengthType     bytesCopied;
  uint16            bufLength;
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

  if ( !SoAd_IsPduRoutePresent() )
  {
    return BUFREQ_E_NOT_OK;
  }

  /* PRQA S 3109 9 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_COPY_TX_DATA, SOAD_E_NOTINIT,
    BUFREQ_E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != BufPtr), SOAD_API_ID_COPY_TX_DATA, SOAD_E_PARAM_POINTER, BUFREQ_E_NOT_OK);
# if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
  SOAD_CheckDetErrorReturnValue((NULL_PTR != BufLengthPtr), SOAD_API_ID_COPY_TX_DATA, SOAD_E_PARAM_POINTER,
    BUFREQ_E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((0u != *BufLengthPtr), SOAD_API_ID_COPY_TX_DATA, SOAD_E_INV_ARG, BUFREQ_E_NOT_OK);
# else
  SOAD_CheckDetErrorReturnValue((0u != BufLength), SOAD_API_ID_COPY_TX_DATA, SOAD_E_INV_ARG, BUFREQ_E_NOT_OK);
# endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */

# if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
  bufLength = *BufLengthPtr;
# else
  bufLength = BufLength;
# endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */

  /* get SoAd local socket index */
  sockIdx = SoAd_VGetSockIdxBySocketId(SocketId);

  /* check SocketId */
  if ( SOAD_INV_SOCK_IDX == sockIdx )
  { /* invalid SocketId */
    SOAD_CallDetReportError(SOAD_API_ID_COPY_TX_DATA, SOAD_E_INV_SOCKETID);
    return BUFREQ_E_NOT_OK;
  }

  /* get socket connection */
  soConIdx = SoAd_SockIdx2ActiveSoConIdx(sockIdx);
  if ( SOAD_INV_SO_CON_ID == soConIdx )
  { /* no transmission is active (TP session may be active but no preparation for transmission are made) */
    return BUFREQ_E_NOT_OK;
  }

  /* check socket connection states */
  if ( (SOAD_SOCON_ONLINE != SoAd_SockConIdx2State(soConIdx)) ||
    ( SOAD_CLOSE_NONE != SoAd_SockConIdx2CloseMode(soConIdx)) )
  { /* socket connection is not online or requested to be closed */
    return BUFREQ_E_NOT_OK;
  }

  txPduIdx = SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx;
  bytesCopied = SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen - SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending;

  if ( bufLength <= SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending )
  { /* requested buffer length is valid */
# if ( SOAD_VTX_BUF_ENABLED == STD_ON )
    if ( SoAd_IsSockConIdx2TxBufferPresent() && (NULL_PTR != SoAd_SockConIdx2TxBuffer(soConIdx).TpTxBufferOffsetPtr) &&
      (0u != *SoAd_SockConIdx2TxBuffer(soConIdx).TpTxBufferOffsetPtr) )
    { /* transmission of UDP TpTxBuffer */
      /* copy data to provided buffer */
      IpBase_Copy((IpBase_CopyDataType*)&BufPtr[0],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))
          &SoAd_SockConIdx2TxMgt(soConIdx).TxBufPtr[bytesCopied],
        bufLength);
      SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending -= (PduLengthType)bufLength;
      retVal = BUFREQ_OK;
    }
    else
# endif /* SOAD_VTX_BUF_ENABLED == STD_ON */
# if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
    if ( SoAd_IsNPduUdpTxPresent() && (SOAD_INV_BUF_IDX_16 != SoAd_SockConIdx2NPduUdpTxIdx(soConIdx)) )
    { /* transmission of UDP nPdu */
      uint16 nPduUdpTxIdx = SoAd_SockConIdx2NPduUdpTxIdx(soConIdx);

#  if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
      if ( SoAd_NPduUdpTx(nPduUdpTxIdx).QueueMgtPtr != NULL_PTR )
      { /* nPduUdpTxQueue */
        uint8 idx;

        retVal = BUFREQ_OK;

        for ( idx = 0u; idx < SoAd_NPduUdpTx(nPduUdpTxIdx).QueueMgtPtr->Lvl; idx++ )
        {
          txPduIdx = SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].TxPduIdx;
          if ( txPduIdx != SOAD_INV_PDU_IDX )
          {
#   if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
            if ( SoAd_TxPduIdx2PduRoute(txPduIdx).IfTriggerTransmitEnabled == FALSE )
            { /* PDU is located in nPdu buffer */
              if ( bufLength >= SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Len )
              { /* provided buffer is sufficient for this PDU */
#    if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
                IpBase_Copy((IpBase_CopyDataType*)&BufPtr[*BufLengthPtr - bufLength],
                  (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))
                    &SoAd_NPduUdpTx(nPduUdpTxIdx).BufPtr[SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].BufIdx],
                  SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Len);
#    else
                IpBase_Copy((IpBase_CopyDataType*)&BufPtr[BufLength - bufLength],
                  (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))
                    &SoAd_NPduUdpTx(nPduUdpTxIdx).BufPtr[SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].BufIdx],
                  SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Len);
#    endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */

                bufLength -= (uint16)SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Len;
              }
              else
              { /* provided buffer is not sufficient for this PDU anymore */
                break;
              }
            }
            else
#   endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
            { /* data has to be retrieved via trigger transmit */
              PduInfoType info;

#   if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
              if ( (SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == FALSE) ||
                ((SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Len - SOAD_PDU_HDR_SIZE) != 0u) )
              {
                /* retrieve PDU from upper layer */
                if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
                {
                  if ( bufLength >= SOAD_PDU_HDR_SIZE )
                  {
#    if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
                    info.SduDataPtr = &BufPtr[*BufLengthPtr - bufLength + SOAD_PDU_HDR_SIZE];
#    else
                    info.SduDataPtr = &BufPtr[BufLength - bufLength + SOAD_PDU_HDR_SIZE];
#    endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
                    info.SduLength = (PduLengthType)(bufLength - SOAD_PDU_HDR_SIZE);
                  }
                  else
                  { /* provided buffer is not sufficient for this PDU anymore */
                    break;
                  }
                }
                else
#   else
              {
#   endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */
                {
#    if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
                  info.SduDataPtr = &BufPtr[*BufLengthPtr - bufLength];
#    else
                  info.SduDataPtr = &BufPtr[BufLength - bufLength];
#    endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
                  info.SduLength = (PduLengthType)bufLength;
                }

                if ( SoAd_VCallIfTriggerTransmit(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                  SoAd_TxPduIdx2TxConfPduId(txPduIdx), &info) == E_OK )
                {
#   if ( SOAD_VTX_DYN_LEN_ENABLED == STD_OFF )
                  PduLengthType expectedLen = SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Len;

#    if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
                  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
                  {
                    expectedLen -= SOAD_PDU_HDR_SIZE;
                  }
#    endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */
                  if ( info.SduLength != expectedLen )
                  { /* upper layer copied invalid length */
                    retVal = BUFREQ_E_NOT_OK;
                    break;
                  }
#   else
                  if ( info.SduLength > bufLength )
                  { /* upper layer copied invalid length */
                    retVal = BUFREQ_E_NOT_OK;
                    break;
                  }
#   endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_OFF */

#   if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
                  /* handle PDU header if configured */
                  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
                  {
                    uint16 destIdx = 0u;

                    /* find corresponding PduRouteDest */
                    while ( SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListSize > destIdx )
                    {
                      if ( SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListPtr[destIdx]->SoConIdx == soConIdx )
                      { /* PduRouteDest found */
                        /* Copy PDU Header to buffer */
#    if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
                        SoAd_VCopyPduHdr2Buf(SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListPtr[destIdx]->TxPduHdrId,
                          info.SduLength, &BufPtr[*BufLengthPtr - bufLength], 0, SOAD_PDU_HDR_SIZE);
#    else
                        SoAd_VCopyPduHdr2Buf(SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListPtr[destIdx]->TxPduHdrId,
                          info.SduLength - SOAD_PDU_HDR_SIZE, &BufPtr[BufLength - bufLength], 0, SOAD_PDU_HDR_SIZE);
#    endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
                        bufLength -= SOAD_PDU_HDR_SIZE;
                        break;
                      }
                      destIdx++;
                    }
                  }
#   endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */
                  bufLength -= (uint16)info.SduLength;
                }
                else
                { /* provided buffer is not sufficient for this PDU anymore */
#   if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
                  if ( *BufLengthPtr == bufLength )
#   else
                  if ( BufLength == bufLength )
#   endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
                  { /* no data has been copied */
                    retVal = BUFREQ_E_NOT_OK;
                  }
                  break;
                }
              }
            }

            SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Copied = TRUE;
          }
        }
#   if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
        *BufLengthPtr -= bufLength;
        SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending -= *BufLengthPtr;
#   else
        SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending -= (BufLength - bufLength);
#   endif /* SOAD_VTX_DYN_LEN_ENABLED = STD_ON */
      }
#   if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
      else
#   endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
#  endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
#  if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
      { /* nPduUdpTxBuffer */
        /* copy data to provided buffer */
        IpBase_Copy((IpBase_CopyDataType*)&BufPtr[0],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))
            &SoAd_NPduUdpTx(nPduUdpTxIdx).BufPtr[0],
          bufLength);
        SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending = 0u;
        retVal = BUFREQ_OK;
      }
#  endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
    }
    else
# endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */
    { /* transmission of single PDU */
# if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
      /* handle PDU header if configured */
      if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
      {
        uint16 destIdx = 0u;

        if ( bytesCopied < SOAD_PDU_HDR_SIZE )
        {
          /* find corresponding PduRouteDest */
          while ( SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListSize > destIdx )
          {
            if ( SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListPtr[destIdx]->SoConIdx == soConIdx )
            { /* PduRouteDest found */
              PduLengthType bytesToCopy = SOAD_PDU_HDR_SIZE - bytesCopied;

              if ( bytesToCopy > bufLength )
              {
                bytesToCopy = bufLength;
              }
              /* Copy PDU Header to buffer */
              SoAd_VCopyPduHdr2Buf(SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListPtr[destIdx]->TxPduHdrId,
                (SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen - SOAD_PDU_HDR_SIZE),
                BufPtr, bytesCopied, bytesToCopy);
              SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending -= bytesToCopy;
              bufLength -= (uint16)bytesToCopy;
              bytesCopied += bytesToCopy;
              break;
            }
            destIdx++;
          }
        }
      }
# endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */

      if ( SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayer == SOAD_UL_TYPE_IF)
      { /* IF transmission */
# if ( SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON )
        if ( (SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_UDP) &&
          (SoAd_TxPduIdx2PduRoute(txPduIdx).IfTriggerTransmitEnabled == TRUE) )
        { /* trigger transmit API is called in this context for UDP socket connections */
          PduInfoType info;

          info.SduLength = (PduLengthType)bufLength;
#  if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
          if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
          {
            info.SduDataPtr = &BufPtr[SOAD_PDU_HDR_SIZE];
          }
          else
#  endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */
          {
            info.SduDataPtr = BufPtr;
          }

          if ( SoAd_VCallIfTriggerTransmit(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
              SoAd_TxPduIdx2TxConfPduId(txPduIdx), &info) == E_OK)
          {
#  if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
            uint8 minLen = 1u;

#   if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
            if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
            {
              minLen = 0u;
            }
#   endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */

            if ( (info.SduDataPtr != NULL_PTR) && (info.SduLength >= minLen) &&
              (info.SduLength <= bufLength) )
#  else
            if ( (info.SduDataPtr != NULL_PTR) && (info.SduLength == bufLength) )
#  endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
            { /* copied valid length */
              /* update tx management struct */
              SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending = 0u;
#  if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
#   if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
              if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
              {
                if ( info.SduLength != (SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen - SOAD_PDU_HDR_SIZE) )
                { /* length has been updated on trigger transmit call */
                  SoAd_VUpdatePduHdrLen(info.SduLength, BufPtr);
                }
                SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen = info.SduLength + SOAD_PDU_HDR_SIZE;
              }
              else
#   endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */
              {
                SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen = info.SduLength;
              }
              /* return updated length */
              *BufLengthPtr = (uint16)SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen;
#  endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
              retVal = BUFREQ_OK;
            }
          }
        }
        else
# endif /* SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON */
        {
          /* copy data to provided buffer */
# if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
          if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
          {
#  if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
            /* PRQA S 3382 4 */ /* MD_SoAd_21.1 */
            IpBase_Copy((IpBase_CopyDataType*)&BufPtr[(uint16)(*BufLengthPtr - bufLength)],
              (IpBase_CopyDataType*)&SoAd_SockConIdx2TxMgt(soConIdx).TxBufPtr[
                (uint16)(bytesCopied - SOAD_PDU_HDR_SIZE)],
              bufLength);
#  else
            /* PRQA S 3382 4 */ /* MD_SoAd_21.1 */
            IpBase_Copy((IpBase_CopyDataType*)&BufPtr[(uint16)(BufLength - bufLength)],
              (IpBase_CopyDataType*)&SoAd_SockConIdx2TxMgt(soConIdx).TxBufPtr[
                (uint16)(bytesCopied - SOAD_PDU_HDR_SIZE)],
              bufLength);
#  endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
          }
          else
# endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */
          {
            IpBase_Copy((IpBase_CopyDataType*)&BufPtr[0],
              (IpBase_CopyDataType*)&SoAd_SockConIdx2TxMgt(soConIdx).TxBufPtr[bytesCopied],
              bufLength);
          }

          SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending -= (PduLengthType)bufLength;
          retVal = BUFREQ_OK;
        }
      }
      else
      { /* TP transmission */
        PduInfoType pduInfo;
        PduLengthType availableBufLength = 0u;
        
# if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
        pduInfo.SduDataPtr = &BufPtr[*BufLengthPtr - bufLength];
# else
        pduInfo.SduDataPtr = &BufPtr[BufLength - bufLength];
# endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
        pduInfo.SduLength = (PduLengthType)bufLength;

        /* forward copy request to upper layer */
        if ( BUFREQ_OK == SoAd_VCallTpCopyTxData(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
            SoAd_TxPduIdx2TxConfPduId(txPduIdx), &pduInfo, &availableBufLength) )
        { /* copy request successful */
          SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending -= (PduLengthType)bufLength;
          retVal = BUFREQ_OK;
        }
      }
    }
  }

  return retVal;
#else
  SOAD_DUMMY_STATEMENT_VAR(SocketId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(BufPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
  SOAD_DUMMY_STATEMENT_VAR(BufLengthPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# else
  SOAD_DUMMY_STATEMENT_VAR(BufLength); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */

  SOAD_CallDetReportError(SOAD_API_ID_COPY_TX_DATA, SOAD_E_INV_ARG);
  return BUFREQ_E_NOT_OK;
#endif /* SOAD_VPDU_ROUTES == STD_ON */
}
/* PRQA L:MSR_11715 */
/* PRQA L:SoAd_146 */
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_TxConfirmation
 *********************************************************************************************************************/
/*! \brief      transmission confirmation callback
 *  \param[in]  SocketId              TcpIp local socket identifier
 *  \param[in]  Length                length of confirmed data
 *  \context    interrupt or task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 0771 SoAd_146 */ /* MD_SoAd_14.6 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(void, SOAD_CODE) SoAd_TxConfirmation(SoAd_SocketIdType SocketId, uint16 Length)
{
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  SoAd_SockIdxType sockIdx;
  SoAd_SoConIdxType soConIdx;

  if ( !SoAd_IsPduRoutePresent() )
  {
    return;
  }

  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnVoid((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TX_CONFIRMATION, SOAD_E_NOTINIT);
  SOAD_CheckDetErrorReturnVoid((0u != Length), SOAD_API_ID_TX_CONFIRMATION, SOAD_E_INV_ARG);

# if ( !defined(SOAD_VTCP_USED) || (STD_OFF == SOAD_VTCP_USED) )
  /* length parameter not needed */
  SOAD_DUMMY_STATEMENT_VAR(Length); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif /* !defined(SOAD_VTCP_USED) || (STD_OFF == SOAD_VTCP_USED) */

  sockIdx = SoAd_VGetSockIdxBySocketId(SocketId);

  /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
  if ( SOAD_INV_SOCK_IDX == sockIdx )
  { /* invalid SocketId */
    SOAD_CallDetReportError(SOAD_API_ID_TX_CONFIRMATION, SOAD_E_INV_SOCKETID);
    return;
  }

  /* check socket state */
  if ( (SOAD_SOCK_STATE_ESTABLISHED != SoAd_SockIdx2SockState(sockIdx)) )
  {
    return;
  }

  /* get soConId */
  soConIdx = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;

  /* check socket connection state */
  if ( SOAD_SOCON_ONLINE != SoAd_SockConIdx2State(soConIdx) )
  {
    return;
  }

  /* check close mode */
  if ( SOAD_CLOSE_NONE != SoAd_SockConIdx2CloseMode(soConIdx) )
  {
    return;
  }

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP )
  { /* TCP socket */
    P2CONST(SoAd_TcpTxQueueConfigType, AUTOMATIC, SOAD_APPL_VAR) qPtr = SoAd_SockCons(soConIdx).TcpTxQueuePtr;

    while ( 0u < Length )
    { /* iterate over tx queue until all entries are released or length to be released is 0 */
      if ( 0u == qPtr->MgtPtr->Lvl )
      { /* no tx elements left */
        break;
      }
      if ( SOAD_INV_PDU_IDX != qPtr->QueuePtr[qPtr->MgtPtr->Idx].TxPduIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
      { /* found element */
        if ( 0u < qPtr->QueuePtr[qPtr->MgtPtr->Idx].Len )
        { /* queue entry contains data to be confirmed */
          if ( Length >= qPtr->QueuePtr[qPtr->MgtPtr->Idx].Len )
          { /* PDU is confirmed completely */
            SoAd_PduIdxType txPduIdx = qPtr->QueuePtr[qPtr->MgtPtr->Idx].TxPduIdx;

            Length -= (uint16)qPtr->QueuePtr[qPtr->MgtPtr->Idx].Len;
            qPtr->QueuePtr[qPtr->MgtPtr->Idx].Len = 0u;
            qPtr->QueuePtr[qPtr->MgtPtr->Idx].TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
            qPtr->MgtPtr->Lvl--;
            if ( (qPtr->MgtPtr->Idx + 1u) == qPtr->Size)
            { /* wrap around */
              qPtr->MgtPtr->Idx = 0u;
            }
            else
            { /* no wrap around */
              qPtr->MgtPtr->Idx++;
            }

            SoAd_VTcpTxConfirmation(soConIdx, txPduIdx);
          }
          else
          { /* PDU confirmed partly */
            qPtr->QueuePtr[qPtr->MgtPtr->Idx].Len -= (PduLengthType)Length;
            break;
          }
        }
        else
        { /* queue entry has no length (is reserved by current transmission request) */
          break;
        }
      }
    }
  }
#  if ( defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) )
  else
#  endif /* defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) */
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
# if ( defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) )
  { /* UDP socket */
    /* in case that TxConfirmation is called within this context only one PduRoute is possible per socket connection */
    /* a TxConfirmation on a socket connection with multiple PduRoutes cannot be assigned to a PduRoute safely */
    SoAd_SoConIdxType soConIdxTmp;
    SoAd_SoConIdxType soConIdxEnd = (SoAd_SoConIdxType)((SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart +
      SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum) - 1u);

    for ( soConIdxTmp = soConIdx; soConIdxTmp <= soConIdxEnd; soConIdxTmp++)
    {
      if ( SoAd_SockConIdx2PduRouteDestCol(soConIdxTmp).PduRouteDestListSize != 0u )
      {
        if ( SoAd_SockCons(soConIdxTmp).SockConGrpPtr->SocketUdpPtr->ImmedIfTxConf == TRUE )
        { /* immediate TxConfirmation is configured */
          PduIdType txPduId = SoAd_SockConIdx2PduRouteDestCol(soConIdxTmp).PduRouteDestListPtr[0]->TxPduId;
          SoAd_PduIdxType txPduIdx = SoAd_TxPduId2PduRouteIdx(txPduId);

          /* socket connecion handling if automatic setup is enabled and wildcards configured */
          SoAd_VReconnectSockCon(soConIdxTmp);

          /* call TxConfirmation */
          if ( TRUE == SoAd_TxPduIdx2PduRoute(txPduIdx).TxConfEnabled )
          { /* TxConfirmation is configured for the corresponding upper layer or PDU */
            SoAd_VCallIfTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
              SoAd_TxPduIdx2TxConfPduId(txPduIdx));
          }

          /* break since corresponding TxPdu is found */
          break;
        }
      }
    }
  }
# endif /* defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) */
#else
  SOAD_DUMMY_STATEMENT_VAR(SocketId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(Length); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  SOAD_CallDetReportError(SOAD_API_ID_TX_CONFIRMATION, SOAD_E_INV_ARG);
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
}
/* PRQA L:MSR_147 */
/* PRQA L:SoAd_146 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_LocalIpAddrAssignmentChg
 *********************************************************************************************************************/
/*! \brief      IP address assignment change callback
 *  \param[in]  IpAddrId           IP address identifier
 *  \param[in]  State              state of IP address assignment
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
FUNC(void, SOAD_CODE) SoAd_LocalIpAddrAssignmentChg(SoAd_LocalAddrIdType IpAddrId, SoAd_IpAddrStateType State)
{
  SoAd_SoConIdxType soConIdx;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  SOAD_CheckDetErrorReturnVoid((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_LOCAL_IP_ADDR_ASSIGNMENT_CHG,
    SOAD_E_NOTINIT);
  SOAD_CheckDetErrorReturnVoid((SOAD_IPADDRID_ANY != IpAddrId), SOAD_API_ID_LOCAL_IP_ADDR_ASSIGNMENT_CHG,
    SOAD_E_INV_ARG);

  if ( (SOAD_IPADDR_STATE_ASSIGNED == State) || (SOAD_IPADDR_STATE_ONHOLD == State) ||
    (SOAD_IPADDR_STATE_UNASSIGNED == State) )
  { /* valid state */
    /* PRQA S 0781 1 */ /* MD_SoAd_5.6 */
    soConIdx = SoAd_SockConTotal();

    while ( 0u < soConIdx )
    {
      soConIdx--;

      if ( SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId == IpAddrId )
      { /* IpAddrId is configured for this socket connection */
        SoAd_SockConIdx2IpAddrState(soConIdx) = State;

        /* forward to consumer */
        SoAd_VCallChgFunc(soConIdx, SoAd_SockCons(soConIdx).IpAddrChgFuncBitPattern,
          SOAD_CHG_FUNC_TYPE_IPASSIGN, State);

        /* set event to handle socket connection state in main function */
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
      }
    }
  }
  else
  {
    SOAD_CallDetReportError(SOAD_API_ID_LOCAL_IP_ADDR_ASSIGNMENT_CHG, SOAD_E_INV_ARG);
  }
}
/* PRQA L:MSR_147 */

/**********************************************************************************************************************
 *  SoAd_TcpAccepted
 *********************************************************************************************************************/
/*! \brief      TCP connection accepted callback on listen socket
 *  \param[in]  SocketId            socket identifier used at bind (listen socket)
 *  \param[in]  SocketIdConnected   socket identifier of connected remote peer (data socket)
 *  \param[in]  RemoteAddrPtr       remote address of connected remote peer
 *  \return     E_OK                established connection accepted
 *  \return     E_NOT_OK            established connection rejected
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 3673 SoAd_167 */ /* MD_SoAd_16.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpAccepted(SoAd_SocketIdType SocketId,
                                        SoAd_SocketIdType SocketIdConnected,
                                        SoAd_SockAddrType* RemoteAddrPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  SoAd_SockIdxType sockIdx;
#if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  SoAd_SockIdxType sockIdxConnected = 0u;
  SoAd_SoConIdxType soConIdx;
#endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */

  /* PRQA S 3109 8 */ /* MD_MSR_14.3 */  /* PRQA S 0277 5 */ /* MD_SoAd_3.1 */
  SOAD_CheckDetErrorReturnValue((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TCP_ACCEPTED,
    SOAD_E_NOTINIT, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((SOAD_INV_SOCKET_ID != SocketId), SOAD_API_ID_TCP_ACCEPTED,
    SOAD_E_INV_SOCKETID, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((SOAD_INV_SOCKET_ID != SocketIdConnected), SOAD_API_ID_TCP_ACCEPTED,
    SOAD_E_INV_SOCKETID, E_NOT_OK);
  SOAD_CheckDetErrorReturnValue((NULL_PTR != RemoteAddrPtr), SOAD_API_ID_TCP_ACCEPTED,
    SOAD_E_PARAM_POINTER, E_NOT_OK);

  sockIdx = SoAd_VGetSockIdxBySocketId(SocketId);

  if ( SOAD_INV_SOCK_IDX == sockIdx )
  { /* invalid SocketId */
    SOAD_CallDetReportError(SOAD_API_ID_TCP_ACCEPTED, SOAD_E_INV_SOCKETID);
    return retVal;
  }

#if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  if ( SOAD_SOCK_STATE_LISTEN != SoAd_SockIdx2SockState(sockIdx) )
  { /* listen socket is not in listen state */
    return retVal;
  }

  soConIdx = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;

  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr->TcpInitiate != FALSE )
  { /* no server socket */
    SOAD_CallDetReportError(SOAD_API_ID_TCP_ACCEPTED, SOAD_E_INV_SOCKETID);
    return retVal;
  }

  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->MsgAcceptFilterEnabled == TRUE )
  { /* message acceptance filter is enabled */
    /* use best match algorithm to get corresponding socket connection */
    SoAd_SoConIdxType soConIdxStart = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;
    SoAd_SoConIdxType soConIdxMax = (SoAd_SoConIdxType)(soConIdxStart +
      SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum - 1u);

    if ( E_OK != SoAd_VGetSoConIdByBestMatchAlg(RemoteAddrPtr, soConIdxStart, soConIdxMax, SOAD_SOCON_FILTER_ON_OFF,
      FALSE, &soConIdx) )
    { /* no socket connection found */
      soConIdx = SOAD_INV_SO_CON_IDX;
    }
    else
    { /* socket connection found */
      sockIdxConnected = SoAd_SockCons(soConIdx).SockIdx;
    }
  }
  else
  { /* message acceptance filter is disabled */
    /* one socket connection only */
    if ( SOAD_SOCON_RECONNECT == SoAd_SockConIdx2State(SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart) )
    { /* valid socket connection state */
      soConIdx = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;
      sockIdxConnected = SoAd_SockCons(soConIdx).SockIdx;
    }
    else
    { /* invalid socket connection state */
      soConIdx = SOAD_INV_SO_CON_IDX;
    }
  }

  if ( SOAD_INV_SO_CON_IDX != soConIdx )
  { /* found socket connection */
    retVal = E_OK;

    if ( SOAD_SOCK_STATE_CLOSED == SoAd_SockIdx2SockState(sockIdxConnected) )
    { /* valid TcpIp socket state */
      /* assign TcpIp socket */
      SoAd_SockIdx2SocketId(sockIdxConnected) = SocketIdConnected;

# if ( SOAD_VSOCKET_BSD_API_ENABLED == STD_ON )
      /* set event to handle socket reception in main function */
      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxSockIdx(), sockIdxConnected);
#endif /* SOAD_VSOCKET_BSD_API_ENABLED == STD_ON */

      /* update remote address */
      SoAd_VCopyIpAddr((SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(soConIdx), RemoteAddrPtr, TRUE);
      SoAd_SockConIdx2RemAddrState(soConIdx) = SOAD_SOCON_IP_SET_PORT_SET;

      /* set socket and socket connection state */
      SoAd_SockIdx2SockState(sockIdxConnected) = SOAD_SOCK_STATE_ESTABLISHED;
      SoAd_OpenSocks++;
      SoAd_SockConIdx2State(soConIdx) = SOAD_SOCON_ONLINE;

      /* inform upper layer about socket connection state change */
      SoAd_VCallChgFunc(soConIdx, SoAd_SockCons(soConIdx).SoConChgFuncBitPattern,
        SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(soConIdx));

# if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
      if ( SoAd_IsSockRoutePresent() )
      { /* call <Up>_[SoAd][Tp]StartOfReception() with TpSduLength = 0 if PduHeader is disabled and TP-API is used */
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
        if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == FALSE )
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
        {
          uint16 routeIdx;
          uint16 routeNum;

          routeIdx = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxStart;
          routeNum = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxNum;

          if ( 0u < routeNum )
          {
            if ( SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer == SOAD_UL_TYPE_TP )
            {
              PduLengthType dummyLen = 0u;
              /* call StartOfReception */
              if ( BUFREQ_OK != SoAd_VCallTpStartOfReception(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                  SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId,
                  0u,
                  &dummyLen) )
              { /* close socket connection in next main function again */
                SoAd_SockConIdx2CloseMode(soConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                /* set event to handle socket connection state in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
                retVal = E_NOT_OK;
              }
              else
              {
                SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx = routeIdx;
              }
            }
          }
        }
      }
# endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
    }
  }
#else
  SOAD_DUMMY_STATEMENT_VAR(SocketIdConnected); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  SOAD_DUMMY_STATEMENT_VAR(RemoteAddrPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED)  */

  return retVal;
}
/* PRQA L:MSR_147 */
/* PRQA L:SoAd_167 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_TcpConnected
 *********************************************************************************************************************/
/*! \brief      TCP connection connected callback
 *  \param[in]  SocketId       socket Identifier of TcpIp module
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(void, SOAD_CODE) SoAd_TcpConnected(SoAd_SocketIdType SocketId)
{
  SoAd_SockIdxType  sockIdx;
#if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  SoAd_SoConIdxType soConIdx;
#endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED)  */

  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */  /* PRQA S 0277 2 */ /* MD_SoAd_3.1 */
  SOAD_CheckDetErrorReturnVoid((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TCP_CONNECTED, SOAD_E_NOTINIT);
  SOAD_CheckDetErrorReturnVoid((SOAD_INV_SOCKET_ID != SocketId), SOAD_API_ID_TCP_CONNECTED, SOAD_E_INV_SOCKETID);

  sockIdx = SoAd_VGetSockIdxBySocketId(SocketId);

  if ( SOAD_INV_SOCK_IDX == sockIdx )
  { /* invalid SocketId */
    SOAD_CallDetReportError(SOAD_API_ID_TCP_CONNECTED, SOAD_E_INV_SOCKETID);
    return;
  }

#if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  /* there is only one TCP socket connection per TcpIp socket */
  soConIdx = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;

  /* check socket */
  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol != SOAD_IPPROTO_TCP )
  {
    SOAD_CallDetReportError(SOAD_API_ID_TCP_CONNECTED, SOAD_E_INV_SOCKETID);
    return;
  }

  /* check whether socket is initiator */
  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr->TcpInitiate != TRUE )
  { /* socket is not initiator */
    SOAD_CallDetReportError(SOAD_API_ID_TCP_CONNECTED, SOAD_E_INV_SOCKETID);
    return;
  }

  /* check socket state */
  if ( SOAD_SOCK_STATE_CONNECT != SoAd_SockIdx2SockState(sockIdx) )
  { /* socket has wrong state */
    return;
  }

  /* check whether socket connection is still requested to be opened */
  if ( (0u < SoAd_SockConIdx2FlagCntOpCl(soConIdx)) ||
    (TRUE == SoAd_SockCons(soConIdx).SockConGrpPtr->SockAutoSoConSetup) )
  { /* socket connection is still requested to be opened */
    if ( SOAD_SOCON_ONLINE != SoAd_SockConIdx2State(soConIdx) )
    { /* socket connection is not online */
      /* open socket connection */
      SoAd_SockIdx2SockState(sockIdx) = SOAD_SOCK_STATE_ESTABLISHED;

# if ( SOAD_VSOCKET_BSD_API_ENABLED == STD_ON )
      /* set event to handle socket reception in main function */
      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxSockIdx(), sockIdx);
# endif /* SOAD_VSOCKET_BSD_API_ENABLED == STD_ON */

      SoAd_SockConIdx2State(soConIdx) = SOAD_SOCON_ONLINE;
      /* inform upper layer about socket connection state change */
      SoAd_VCallChgFunc(soConIdx, SoAd_SockCons(soConIdx).SoConChgFuncBitPattern,
        SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(soConIdx));

# if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
      if ( SoAd_IsSockRoutePresent() )
      { /* call <Up>_[SoAd][Tp]StartOfReception() with TpSduLength = 0 if PduHeader is disabled and TP-API is used */
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
        if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == FALSE )
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
        {
          uint16 routeIdx;
          uint16 routeNum;

          routeIdx = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxStart;
          routeNum = SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxNum;

          while ( 0u < routeNum )
          {
            if ( SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer == SOAD_UL_TYPE_TP )
            {
              PduLengthType dummyLen = 0u;
              /* call StartOfReception */
              if ( BUFREQ_OK != SoAd_VCallTpStartOfReception(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                  SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId,
                  0u,
                  &dummyLen) )
              { /* close socket connection */
                SoAd_SockConIdx2CloseMode(soConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                /* set event to handle socket connection state in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
              }
              else
              {
                SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx = routeIdx;
              }
            }
            routeNum--;
            routeIdx++;
          }
        }
      }
# endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
    }
  }
#endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED)  */
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_TcpIpEvent
 *********************************************************************************************************************/
/*! \brief      TCP event handler (state change)
 *  \param[in]  SocketId       socket identifier of TcpIp socket
 *  \param[in]  Event          event type
 *  \context    task level
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(void, SOAD_CODE) SoAd_TcpIpEvent(SoAd_SocketIdType SocketId, SoAd_EventType Event)
{
  SoAd_SockIdxType sockIdx;

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */  /* PRQA S 0277 2 */ /* MD_SoAd_3.1 */
  SOAD_CheckDetErrorReturnVoid((SOAD_STATE_UNINIT != SoAd_State), SOAD_API_ID_TCPIP_EVENT, SOAD_E_NOTINIT);
  SOAD_CheckDetErrorReturnVoid((SOAD_INV_SOCKET_ID != SocketId), SOAD_API_ID_TCPIP_EVENT, SOAD_E_INV_SOCKETID);

  sockIdx = SoAd_VGetSockIdxBySocketId(SocketId);

  if ( SOAD_INV_SOCK_IDX != sockIdx )
  { /* valid sockIdx */
    switch ( Event )
    {
      case SOAD_UDP_CLOSED:
      {
        SoAd_SoConIdType soConIdxFirst = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;

        if ( SoAd_SockCons(soConIdxFirst).SockConGrpPtr->Protocol == SOAD_IPPROTO_UDP )
        { /* UDP socket */
          SoAd_SoConIdxType soConIdxTmp = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;
          SoAd_SoConIdxType soConIdxMax = (SoAd_SoConIdxType)(soConIdxTmp +
            SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum);
          boolean resetLocPort = TRUE;

          /* remove TcpIp socket assignment */
          if ( SoAd_SockIdx2SockState(sockIdx) != SOAD_SOCK_STATE_CLOSED )
          {
            if ( SoAd_OpenSocks > 0u )
            {
              SoAd_OpenSocks--;
            }
          }
          SoAd_SockIdx2SockState(sockIdx)      = SOAD_SOCK_STATE_CLOSED;
          SoAd_SockIdx2SocketId(sockIdx)       = SOAD_INV_SOCKET_ID;  /* PRQA S 0277 */ /* MD_SoAd_3.1 */
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
          if ( SoAd_IsPduRoutePresent() )
          {
            SoAd_SockIdx2ActiveSoConIdx(sockIdx)  = SOAD_INV_SO_CON_IDX;
          }
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
          if ( SoAd_IsSockRoutePresent() )
          {
            SoAd_SockIdx2SkipBytes(sockIdx)      = 0u;
          }
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */

          /* close all socket connections */
          while ( soConIdxTmp < soConIdxMax )
          {
            if ( SOAD_SOCON_OFFLINE != SoAd_SockConIdx2State(soConIdxTmp) )
            { /* socket connection is not offline */
              /* handle socket connection state dependent on close mode */
              switch ( SoAd_SockConIdx2CloseMode(soConIdxTmp) )
              {
                case SOAD_CLOSE_RECONNECT:
                { /* set socket connection to reconnect */
                  if ( SOAD_SOCON_RECONNECT != SoAd_SockConIdx2State(soConIdxTmp) )
                  {
                    SoAd_SockConIdx2State(soConIdxTmp) = SOAD_SOCON_RECONNECT;
                    resetLocPort = FALSE;
                    /* reset socket connection, release buffers, terminate active TP sessions */
                    SoAd_VResetSockCon(soConIdxTmp, TRUE, FALSE);
                    /* inform upper layer about socket connection state change */
                    SoAd_VCallChgFunc(soConIdxTmp, SoAd_SockCons(soConIdxTmp).SoConChgFuncBitPattern,
                      SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(soConIdxTmp));
                  }
                  break;
                }
                case SOAD_CLOSE_OFFLINE_RESET:
                { /* set socket connection to offline and reset open/close counter */
                  SoAd_SockConIdx2FlagCntOpCl(soConIdxTmp) = 0u;
                  SoAd_SockConIdx2State(soConIdxTmp) = SOAD_SOCON_OFFLINE;
                  /* reset socket connection, release buffers, terminate active TP sessions */
                  SoAd_VResetSockCon(soConIdxTmp, TRUE, FALSE);
                  /* inform upper layer about socket connection state change */
                  SoAd_VCallChgFunc(soConIdxTmp, SoAd_SockCons(soConIdxTmp).SoConChgFuncBitPattern,
                    SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(soConIdxTmp));
                  break;
                }
                case SOAD_CLOSE_OFFLINE:
                { /* set socket connection to offline */
                  SoAd_SockConIdx2State(soConIdxTmp) = SOAD_SOCON_OFFLINE;
                  /* reset socket connection, release buffers, terminate active TP sessions */
                  SoAd_VResetSockCon(soConIdxTmp, TRUE, TRUE);
                  /* inform upper layer about socket connection state change */
                  SoAd_VCallChgFunc(soConIdxTmp, SoAd_SockCons(soConIdxTmp).SoConChgFuncBitPattern,
                    SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(soConIdxTmp));
                  break;
                }
                default:
                { /* set socket connection to offline */
                  SoAd_SockConIdx2State(soConIdxTmp) = SOAD_SOCON_OFFLINE;
                  /* reset socket connection, release buffers, terminate active TP sessions */
                  SoAd_VResetSockCon(soConIdxTmp, TRUE, FALSE);
                  /* inform upper layer about socket connection state change */
                  SoAd_VCallChgFunc(soConIdxTmp, SoAd_SockCons(soConIdxTmp).SoConChgFuncBitPattern,
                    SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(soConIdxTmp));
                  break;
                }
              }
            }

            /* reset close mode */
            SoAd_SockConIdx2CloseMode(soConIdxTmp) = SOAD_CLOSE_NONE;

            /* set event to handle socket connection state in main function */
            SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdxTmp);

            soConIdxTmp++;
          }

          if ( TRUE == resetLocPort )
          { /* reset local port */
            SoAd_SockIdx2LocPortDyn(sockIdx) = SoAd_SockCons(soConIdxFirst).SockConGrpPtr->LocalPort;
          }
        }
        else
        { /* UDP Event on TCP socket */
          SOAD_CallDetReportError(SOAD_API_ID_TCPIP_EVENT, SOAD_E_INV_SOCKETID);
        }
        break;
      }
      case SOAD_TCP_RESET:
      case SOAD_TCP_CLOSED:
      {
        SoAd_SoConIdType soConIdxFirst = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;

        if ( SoAd_SockCons(soConIdxFirst).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP )
        { /* TCP socket */
          SoAd_SoConIdxType soConIdxTmp = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;
          SoAd_SoConIdxType soConIdxMax = (SoAd_SoConIdType)(soConIdxTmp +
            SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum);
          boolean resetLocPort = TRUE;

          if ( SoAd_SockCons(soConIdxFirst).SockConGrpPtr->GrpSockIdx == sockIdx )
          { /* listen socket */
            /* remove TcpIp socket assignment */
            SoAd_SockIdx2SockState(sockIdx) = SOAD_SOCK_STATE_CLOSED;
            SoAd_SockIdx2SocketId(sockIdx)  = SOAD_INV_SOCKET_ID;  /* PRQA S 0277 */ /* MD_SoAd_3.1 */
            if ( SoAd_OpenSocks > 0u )
            {
              SoAd_OpenSocks--;
            }
          }
          else
          { /* no listen socket */
            /* remove TcpIp socket assignment */
            if ( SoAd_SockIdx2SockState(sockIdx) != SOAD_SOCK_STATE_CLOSED )
            {
              if ( SoAd_OpenSocks > 0u )
              {
                SoAd_OpenSocks--;
              }
            }
            SoAd_SockIdx2SockState(sockIdx)      = SOAD_SOCK_STATE_CLOSED;
            SoAd_SockIdx2SocketId(sockIdx)       = SOAD_INV_SOCKET_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
            if ( SoAd_IsPduRoutePresent() )
            {
              SoAd_SockIdx2ActiveSoConIdx(sockIdx)  = SOAD_INV_SO_CON_IDX;
            }
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
            if ( SoAd_IsSockRoutePresent() )
            {
              SoAd_SockIdx2SkipBytes(sockIdx)      = 0u;
            }
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */

            if ( SOAD_SOCON_ONLINE == SoAd_SockConIdx2State(soConIdxFirst) )
            {
              /* handle socket connection state dependent on close mode */
              switch ( SoAd_SockConIdx2CloseMode(soConIdxFirst) )
              {
                case SOAD_CLOSE_RECONNECT:
                { /* set socket connection to reconnect and reset remote address */
                  SoAd_SockConIdx2State(soConIdxFirst) = SOAD_SOCON_RECONNECT;
                  SoAd_VResetSockCon(soConIdxFirst, TRUE, FALSE);
                  break;
                }
                case SOAD_CLOSE_NONE:
                case SOAD_CLOSE_REMOTE:
                { /* set socket connection to reconnect */
                  SoAd_SockConIdx2State(soConIdxFirst) = SOAD_SOCON_RECONNECT;
                  if ( SoAd_SockCons(soConIdxFirst).SockConGrpPtr->SocketTcpPtr->TcpInitiate == TRUE )
                  { /* client socket */
                    /* do not reset remote address to prevent that upper layer has to set remote address again */
                    SoAd_VResetSockCon(soConIdxFirst, FALSE, FALSE);
                  }
                  else
                  { /* server socket */
                    SoAd_VResetSockCon(soConIdxFirst, TRUE, FALSE);
                  }
                  break;
                }
                case SOAD_CLOSE_OFFLINE_RESET:
                { /* set socket connection to offline, reset open/close counter and reset remote address */
                  SoAd_SockConIdx2FlagCntOpCl(soConIdxFirst) = 0u;
                  SoAd_SockConIdx2State(soConIdxFirst) = SOAD_SOCON_OFFLINE;
                  SoAd_VResetSockCon(soConIdxFirst, TRUE, FALSE);
                  break;
                }
                default:
                { /* set socket connection to offline and reset remote address */
                  SoAd_SockConIdx2State(soConIdxFirst) = SOAD_SOCON_OFFLINE;
                  SoAd_VResetSockCon(soConIdxFirst, TRUE, TRUE);
                  break;
                }
              }

              /* inform upper layer about socket connection state change */
              SoAd_VCallChgFunc(soConIdxFirst, SoAd_SockCons(soConIdxFirst).SoConChgFuncBitPattern,
                SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(soConIdxFirst));
            }

            /* set event to handle socket connection state in main function */
            SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdxFirst);

            /* reset close mode */
            SoAd_SockConIdx2CloseMode(soConIdxFirst) = SOAD_CLOSE_NONE;
          }

          /* reset local port if all socket connections and listen socket are offline and closed */
          while ( soConIdxTmp < soConIdxMax )
          {
            if ( SOAD_SOCON_OFFLINE != SoAd_SockConIdx2State(soConIdxTmp) )
            {
              resetLocPort = FALSE;
              break;
            }
            soConIdxTmp++;
          }

          if ( SoAd_SockCons(soConIdxFirst).SockConGrpPtr->SocketTcpPtr->TcpInitiate == FALSE )
          { /* server socket - listen socket is available */
            if ( SOAD_SOCK_STATE_CLOSED != SoAd_SockIdx2SockState(SoAd_SockCons(soConIdxFirst).
                SockConGrpPtr->GrpSockIdx) )
            { /* listen socket is not closed */
              resetLocPort = FALSE;
            }
          }

          if ( TRUE == resetLocPort )
          { /* reset local port */
            SoAd_SockIdx2LocPortDyn(sockIdx) = SoAd_SockCons(soConIdxFirst).SockConGrpPtr->LocalPort;
          }
        }
        else
        { /* TCP Event on UDP socket */
          SOAD_CallDetReportError(SOAD_API_ID_TCPIP_EVENT, SOAD_E_INV_SOCKETID);
        }
        break;
      }
      case SOAD_TCP_FIN_RECEIVED:
      {
        SoAd_SoConIdType soConIdxFirst = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;

        if ( SoAd_SockCons(soConIdxFirst).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP )
        { /* TCP socket */
          /* set close mode to "closed by remote" */
          SoAd_SockConIdx2CloseMode(soConIdxFirst) = SOAD_CLOSE_REMOTE;

          /* set event to handle socket connection state in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdxFirst);

          /* close TcpIp socket */
          (void)SoAd_VTcpIpClose(SoAd_SockIdx2SocketId(sockIdx), FALSE, sockIdx, TRUE);
        }
        else
        { /* TCP Event on UDP socket */
          SOAD_CallDetReportError(SOAD_API_ID_TCPIP_EVENT, SOAD_E_INV_SOCKETID);
        }
        break;
      }
      default:
      {
        SOAD_CallDetReportError(SOAD_API_ID_TCPIP_EVENT, SOAD_E_INV_ARG);
        break;
      }
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  SoAd_VCloseSockCon
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VCloseSockCon(SoAd_SoConIdxType SoConIdx)
{
  boolean abortFlag = SoAd_SockConIdx2FlagAbort(SoConIdx);
  SoAd_SoConModeType oldState = SoAd_SockConIdx2State(SoConIdx);

  /* set socket connection state */
  switch ( SoAd_SockConIdx2CloseMode(SoConIdx) )
  {
    case SOAD_CLOSE_OFFLINE_RESET:
    case SOAD_CLOSE_OFFLINE:
    { /* set socket connection to offline */
      SoAd_SockConIdx2State(SoConIdx) = SOAD_SOCON_OFFLINE;
      break;
    }
    case SOAD_CLOSE_RECONNECT:
    { /* set socket connection to reconnect */
      SoAd_SockConIdx2State(SoConIdx) = SOAD_SOCON_RECONNECT;
      break;
    }
    default:
    {
      return;
    }
  }

  if ( SoAd_SockConIdx2State(SoConIdx) != oldState )
  {
    if ( SOAD_CLOSE_OFFLINE == SoAd_SockConIdx2CloseMode(SoConIdx) )
    { /* closed by normal close request */
      /* reset socket connection, release buffers, terminate active TP sessions and reset TxQueue */
      SoAd_VResetSockCon(SoConIdx, TRUE, TRUE);
    }
    else
    { /* closed by different reason (not normal close request) */
      if ( SOAD_CLOSE_OFFLINE_RESET == SoAd_SockConIdx2CloseMode(SoConIdx) )
      {
        /* reset open/close counter */
        SoAd_SockConIdx2FlagCntOpCl(SoConIdx) = 0u;
      }
      SoAd_VResetSockCon(SoConIdx, TRUE, FALSE);
    }

    /* inform upper layer about socket connection state change */
    SoAd_VCallChgFunc(SoConIdx, SoAd_SockCons(SoConIdx).SoConChgFuncBitPattern,
      SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(SoConIdx));

    /* close TcpIp socket */
#if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
    if ( SOAD_IPPROTO_TCP == SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol )
    { /* TCP socket */
      /* get socket index */
      SoAd_SockIdxType sockIdx = SoAd_SockCons(SoConIdx).SockIdx;

      if ( (SOAD_SOCK_STATE_CLOSED != SoAd_SockIdx2SockState(sockIdx)) &&
        (SOAD_SOCK_STATE_CLOSING != SoAd_SockIdx2SockState(sockIdx)) )
      { /* socket is not already closed or closing */
        SoAd_SockIdx2SockState(sockIdx) = SOAD_SOCK_STATE_CLOSING;
        /* call TcpIp close function */
        (void)SoAd_VTcpIpClose(SoAd_SockIdx2SocketId(sockIdx), abortFlag, sockIdx, TRUE);
      }
      else
      { /* socket is already closed or closing - reset close mode */
        SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_NONE;
      }

      if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpInitiate == FALSE )
      { /* server socket */
        SoAd_SockIdxType sockIdxListen = SoAd_SockCons(SoConIdx).SockConGrpPtr->GrpSockIdx;

        if ( (SOAD_SOCK_STATE_CLOSED != SoAd_SockIdx2SockState(sockIdxListen)) &&
          (SOAD_SOCK_STATE_CLOSING != SoAd_SockIdx2SockState(sockIdxListen)) )
        { /* listen socket is not already closed or closing */
          /* check if all socket connections are closed */
          SoAd_SoConIdxType soConIdxTmp = SoAd_SockIdx2SoConIdxCol(sockIdxListen).SoConIdxStart;
          SoAd_SoConIdxType soConIdxMax = (SoAd_SoConIdxType)(soConIdxTmp +
            SoAd_SockIdx2SoConIdxCol(sockIdxListen).SoConIdxNum);

          while ( soConIdxTmp < soConIdxMax )
          {
            if ( SOAD_SOCON_OFFLINE != SoAd_SockConIdx2State(soConIdxTmp) )
            { /* at least one of the socket connections is not offline - do not close corresponding TcpIp socket */
              return;
            }
            soConIdxTmp++;
          }
          /* all socket connections are offline */
          /* close listen socket */
          SoAd_SockIdx2SockState(sockIdxListen) = SOAD_SOCK_STATE_CLOSING;
          /* call TcpIp close function */
          (void)SoAd_VTcpIpClose(SoAd_SockIdx2SocketId(sockIdxListen), abortFlag, sockIdx, TRUE);
        }
      }
    }
    else
#endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
    { /* UDP socket */
      SoAd_SockIdxType sockIdx = SoAd_SockCons(SoConIdx).SockIdx;

      if ( (SOAD_SOCK_STATE_CLOSED != SoAd_SockIdx2SockState(sockIdx)) &&
        (SOAD_SOCK_STATE_CLOSING != SoAd_SockIdx2SockState(sockIdx)) )
      { /* socket is not already closed or closing */
        /* check if all socket connections are closed */
        SoAd_SoConIdxType soConIdxTmp = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;
        SoAd_SoConIdxType soConIdxMax = (SoAd_SoConIdxType)(soConIdxTmp +
          SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum);

        while ( soConIdxTmp < soConIdxMax )
        {
          if ( SOAD_SOCON_OFFLINE != SoAd_SockConIdx2State(soConIdxTmp) )
          { /* at least one of the socket connections is not offline - do not close corresponding TcpIp socket */
            SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_NONE;
            return;
          }
          soConIdxTmp++;
        }

        /* abort flag is set or all socket connections are offline */
        SoAd_SockIdx2SockState(sockIdx) = SOAD_SOCK_STATE_CLOSING;
        /* call TcpIp close function */
        (void)SoAd_VTcpIpClose(SoAd_SockIdx2SocketId(sockIdx), abortFlag, sockIdx, TRUE);
      }
      else
      { /* socket is already closed or closing - reset close mode */
        SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_NONE;
      }
    }
  }

  /* set event to handle socket connection state in main function */
  SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VOpenSockCon
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VOpenSockCon(SoAd_SoConIdxType SoConIdx)
{
  if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_UDP )
  { /* UDP socket */
    /* check if TcpIp socket is already assigned to socket connection group */
    SoAd_SockIdxType sockIdx = SoAd_SockCons(SoConIdx).SockIdx;

    if ( SOAD_SOCK_STATE_CLOSED == SoAd_SockIdx2SockState(sockIdx) )
    { /* no TcpIp socket is assigned */
      SoAd_VAssignUdpSocket(SoConIdx);
    }

    /* check if TcpIp socket is now assigned completely */
    if ( SOAD_SOCK_STATE_ESTABLISHED == SoAd_SockIdx2SockState(sockIdx) )
    { /* TcpIp socket is assigned */
      /* try to open socket connection */
      /* check remote address */
      if ( (SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->UdpListenOnly == TRUE) ||
        (SOAD_SOCON_IP_SET_PORT_SET == SoAd_SockConIdx2RemAddrState(SoConIdx)) )
      { /* remote address is set or UDP is listen only */
        /* open socket connection */
        SoAd_SockConIdx2State(SoConIdx) = SOAD_SOCON_ONLINE;

#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
        /* trigger address resolution */
        if ( SOAD_SOCON_IP_SET_PORT_SET == SoAd_SockConIdx2RemAddrState(SoConIdx) )
        { /* remote address set */
          if ( SoAd_IsPduRoutePresent() )
          {
            SoAd_VTriggerAddressResolution(SoConIdx);
          }
        }
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */

        /* inform upper layer about socket connection state change */
        SoAd_VCallChgFunc(SoConIdx, SoAd_SockCons(SoConIdx).SoConChgFuncBitPattern,
          SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(SoConIdx));

#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
        if ( SoAd_IsSockRoutePresent() )
        {/* check whether StartOfReception need to be called for upper layers */
# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
          if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->PduHdrEnabled == FALSE )
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
          {
            if ( SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxNum > 0u )
            {
              uint16 routeIdx = SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxStart;

              if ( SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer == SOAD_UL_TYPE_TP )
              {
                PduLengthType dummyLen = 0u;
                /* call StartOfReception */
                if ( BUFREQ_OK != SoAd_VCallTpStartOfReception(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                    SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId,
                    0u,
                    &dummyLen) )
                { /* close socket connection and reset open/close counter */
                  SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                  /* set event to handle socket connection state in main function */
                  SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
                }
                else
                {
                  SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = routeIdx;
                }
              }
            }
          }
        }
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
      }
      else
      { /* no remote address is set */
        if ( SOAD_SOCON_RECONNECT != SoAd_SockConIdx2State(SoConIdx) )
        {
          /* set socket connection to reconnect */
          SoAd_SockConIdx2State(SoConIdx) = SOAD_SOCON_RECONNECT;

          /* inform upper layer about socket connection state change */
          SoAd_VCallChgFunc(SoConIdx, SoAd_SockCons(SoConIdx).SoConChgFuncBitPattern,
            SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(SoConIdx));
        }
      }
    }
    else
    { /* TcpIp socket not assigned */
      /* set event to handle socket connection state in main function again */
      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
    }
  }
  else
  { /* TCP socket */
#if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
    SoAd_SockIdxType sockIdx;

    if ( TRUE == SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpInitiate )
    { /* client socket */
      sockIdx = SoAd_SockCons(SoConIdx).SockIdx;

      /* check if socket is already assigned */
      if ( SOAD_SOCK_STATE_CLOSED == SoAd_SockIdx2SockState(sockIdx) )
      { /* no socket is assigned */
        /* check remote address */
        if ( SOAD_SOCON_IP_SET_PORT_SET == SoAd_SockConIdx2RemAddrState(SoConIdx) )
        { /* remote address is set */
          SoAd_SocketIdType socketId = SOAD_INV_SOCKET_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */

          /* get TcpIp socket */
          if ( E_OK == SoAd_VTcpIpGetSocket(sockIdx, SoAd_SockCons(SoConIdx).SockConGrpPtr->Domain,
              SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol,
              &socketId) )
          { /* TcpIp socket assigned */
            /* change parameter */
            if ( E_OK == SoAd_VTcpIpChangeParameter(SoConIdx, socketId, FALSE) )
            { /* change parameter successful */
              uint16 locPort = (uint16)(IPBASE_HTON16(SoAd_SockIdx2LocPortDyn(sockIdx)));

              if ( E_OK == SoAd_VTcpIpBind(sockIdx, socketId, SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId,
                  &locPort) )
              {
                /* update local port */
                SoAd_SockIdx2LocPortDyn(sockIdx) = (uint16)(IPBASE_HTON16(locPort));
                /* connect to server socket */
                if ( E_OK == SoAd_VTcpIpConnect(sockIdx, socketId,
                    (SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(SoConIdx)) )
                { /* connect request accepted */
                  /* assign socketId to local management struct */
                  SoAd_SockIdx2SocketId(sockIdx) = socketId;
                  /* set socket state */
                  SoAd_SockIdx2SockState(sockIdx) = SOAD_SOCK_STATE_CONNECT;
# if ( SOAD_VSOCKET_BSD_API_ENABLED == STD_ON )
                  /* set event to handle socket in main function */
                  SoAd_VEventQueueAddElement(SoAd_EventQueueIdxSockIdx(), sockIdx);
# endif /* SOAD_VSOCKET_BSD_API_ENABLED == STD_ON */
                  /* increment opened sockets for shutdown mechanism */
                  SoAd_OpenSocks++;
                }
              }
            }
            if ( SOAD_SOCK_STATE_CONNECT != SoAd_SockIdx2SockState(sockIdx) )
            { /* change parameter, bind or connect failed */
              /* set event to handle socket connection state in main function again */
              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
              /* close TcpIp socket */
              (void)SoAd_VTcpIpClose(socketId, FALSE, sockIdx, FALSE);
            }
            else
            { /* socket connection establishment running */
              if ( SOAD_SOCON_RECONNECT != SoAd_SockConIdx2State(SoConIdx) )
              {
                SoAd_SockConIdx2State(SoConIdx) = SOAD_SOCON_RECONNECT;

                /* inform upper layer about socket connection state change */
                SoAd_VCallChgFunc(SoConIdx, SoAd_SockCons(SoConIdx).SoConChgFuncBitPattern,
                  SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(SoConIdx));
              }
            }
          }
          else
          { /* no TcpIp socket assigned */
            /* set event to handle socket connection state in main function again */
            SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
          }
        }
      }
    }
    else
    { /* server socket */
      sockIdx = SoAd_SockCons(SoConIdx).SockConGrpPtr->GrpSockIdx;

      if ( SOAD_SOCK_STATE_CLOSED == SoAd_SockIdx2SockState(sockIdx) )
      { /* no listen socket is assigned */
        SoAd_SocketIdType socketId = SOAD_INV_SOCKET_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */

        /* get TcpIp socket */
        if ( E_OK == SoAd_VTcpIpGetSocket(sockIdx, SoAd_SockCons(SoConIdx).SockConGrpPtr->Domain,
            SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol,
            &socketId) )
        { /* TcpIp socket assigned */
          /* change parameter */
          if ( E_OK == SoAd_VTcpIpChangeParameter(SoConIdx, socketId, FALSE) )
          { /* change parameter successful */
            uint16 locPort = (uint16)(IPBASE_HTON16(SoAd_SockIdx2LocPortDyn(sockIdx)));

            if ( E_OK == SoAd_VTcpIpBind(sockIdx, socketId, SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId,
                &locPort) )
            {
              /* update local port */
              SoAd_SockIdx2LocPortDyn(sockIdx) = (uint16)(IPBASE_HTON16(locPort));
              /* set socket to listen */
              if ( E_OK == SoAd_VTcpIpListen(socketId, (uint16)SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum) )
              { /* listen request accepted */
                /* assign socketId to local management struct */
                SoAd_SockIdx2SocketId(sockIdx) = socketId;
                /* set socket state */
                SoAd_SockIdx2SockState(sockIdx) = SOAD_SOCK_STATE_LISTEN;
# if ( SOAD_VSOCKET_BSD_API_ENABLED == STD_ON )
                /* set event to handle socket in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxSockIdx(), sockIdx);
# endif /* SOAD_VSOCKET_BSD_API_ENABLED == STD_ON */
                /* increment opened sockets for shutdown mechanism */
                SoAd_OpenSocks++;
              }
            }
          }
          if ( SOAD_SOCK_STATE_LISTEN != SoAd_SockIdx2SockState(sockIdx) )
          { /* change parameter, bind or listen failed */
            /* set event to handle socket connection state in main function again */
            SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
            /* close TcpIp socket */
            (void)SoAd_VTcpIpClose(socketId, FALSE, sockIdx, FALSE);
          }
        }
        else
        {
          /* set event to handle socket connection state in main function again */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
        }
      }
      if ( SOAD_SOCK_STATE_LISTEN == SoAd_SockIdx2SockState(sockIdx) )
      { /* listen socket is (now) assigned */
        if ( SOAD_SOCON_OFFLINE == SoAd_SockConIdx2State(SoConIdx) )
        {
          SoAd_SockConIdx2State(SoConIdx) = SOAD_SOCON_RECONNECT;

          /* inform upper layer about socket connection state change */
          SoAd_VCallChgFunc(SoConIdx, SoAd_SockCons(SoConIdx).SoConChgFuncBitPattern,
            SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(SoConIdx));
        }
      }
    }
#else
    SOAD_CallDetReportError(SOAD_API_ID_VOPEN_SOCK_CON, SOAD_E_INV_ARG);
#endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VAssignUdpSocket
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_VAssignUdpSocket(SoAd_SoConIdxType SoConIdx)
{
  SoAd_SocketIdType socketId = SOAD_INV_SOCKET_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
  SoAd_SockIdxType sockIdx = SoAd_SockCons(SoConIdx).SockIdx;

  if ( E_OK == SoAd_VTcpIpGetSocket(sockIdx, SoAd_SockCons(SoConIdx).SockConGrpPtr->Domain,
    SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol,
    &socketId) )
  { /* TcpIp socket assigned */
    Std_ReturnType retVal = E_OK;

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
    retVal |= SoAd_VTcpIpChangeParameter(SoConIdx, socketId, FALSE);
#else
# if ( defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED) )
    /* change parameter */
    if ( SOAD_INV_FRAME_PRIORITY != SoAd_SockCons(SoConIdx).SockConGrpPtr->FramePriority )
    {
      uint8 framePriority = SoAd_SockCons(SoConIdx).SockConGrpPtr->FramePriority;

      retVal |= TcpIp_ChangeParameter(socketId, SOAD_PARAMID_FRAMEPRIO, &framePriority);
    }
# endif /* defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED) */
# if ( defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) )
    if ( 0u != SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->ImmedIfTxConfListSize )
    {
      uint8 udpTxReqListSize = SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->ImmedIfTxConfListSize;

      retVal |= TcpIp_ChangeParameter(socketId, SOAD_PARAMID_UDP_TXREQLISTSIZE, &udpTxReqListSize);
    }
# endif /* defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) */
# if ( defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED) )
    if ( TRUE == SoAd_TcpIpCtrl(SoAd_AddrId2TcpIpCtrl(SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId)).RetryEnabled )
    {
      uint8 udpTxRetryListSize = SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->RetryQueueLimit;

      retVal |= TcpIp_ChangeParameter(socketId, SOAD_PARAMID_UDP_TXRETRYLISTSIZE, &udpTxRetryListSize);
    }
# endif /* defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED) */
# if ( (defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED)) || \
 (defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF)) || \
 (defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED)) )
    if ( E_OK == retVal )
# endif /* (defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED)) || \
 (defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF)) || \
 (defined(SOAD_VUDP_RETRY_ENABLED) && (STD_ON == SOAD_VUDP_RETRY_ENABLED)) */
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
    {
      uint16 locPort = (uint16)(IPBASE_HTON16(SoAd_SockIdx2LocPortDyn(sockIdx)));

      retVal |= SoAd_VTcpIpBind(sockIdx, socketId, SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId, &locPort);

      if ( E_OK == retVal )
      {
        /* update local port */
        SoAd_SockIdx2LocPortDyn(sockIdx) = (uint16)(IPBASE_HTON16(locPort));
        /* assign TcpIp socket to socket connection group */
        SoAd_SockIdx2SocketId(sockIdx) = socketId;
        /* set socket state */
        SoAd_SockIdx2SockState(sockIdx) = SOAD_SOCK_STATE_ESTABLISHED;
#if ( SOAD_VSOCKET_BSD_API_ENABLED == STD_ON )
        /* set event to handle socket in main function */
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxSockIdx(), sockIdx);
#endif /* SOAD_VSOCKET_BSD_API_ENABLED == STD_ON */
        /* increment opened sockets for shutdown mechanism */
        SoAd_OpenSocks++;
      }
    }
    if ( E_OK != retVal )
    { /* TcpIp socket could not be assigned */
      /* check if socket is assigned but further steps failed */
      if ( SOAD_INV_SOCKET_ID != socketId ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
      { /* socket is assigned */
        /* close TcpIp socket */
        (void)SoAd_VTcpIpClose(socketId, FALSE, sockIdx, FALSE);
      }
    }
  }
}

/**********************************************************************************************************************
 *  SoAd_VResetSockCon
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VResetSockCon(SoAd_SoConIdxType SoConIdx, boolean ResetRemAddr, boolean NormalClose)
{
  if ( TRUE == ResetRemAddr )
  { /* reset remote address */
    SoAd_VResetIpAddr(SoConIdx);
#if ( defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) )
    if ( NULL_PTR != SoAd_SockCons(SoConIdx).RcvRemSockPtr )
    { /* get received remote address is supported */
      /* reset remote address */
      SoAd_VResetIpAddr2Unspec(SoAd_SockCons(SoConIdx).RcvRemSockPtr);
    }
#endif /* defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) */
  }

  SoAd_SockConIdx2FlagAbort(SoConIdx) = FALSE;

#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
  if ( SoAd_IsSockRoutePresent() )
  { /* release buffer */
    if ( SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr != NULL_PTR )
    {
      *SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr = 0u;
    }
    if ( SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr != NULL_PTR )
    {
      *SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr = 0u;
    }
  }
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */

  /* terminate active TP session */
  /* TP transmit */
#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
  if ( SoAd_IsPduRoutePresent() )
  {
    if ( SOAD_INV_PDU_IDX != SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
    {
      if ( SoAd_TxPduIdx2PduRoute(SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx).UpperLayer == SOAD_UL_TYPE_TP )
      { /* TP transmission active */
        /* call TxConfirmation */
        if ( SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending == 0u )
        { /* no data pending */
          SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx).UpperLayerId,
            SoAd_TxPduIdx2TxConfPduId(SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx),
            E_OK);
        }
        else
        { /* data pending */
          /* call TxConfirmation */
          SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx).UpperLayerId,
            SoAd_TxPduIdx2TxConfPduId(SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx),
            E_NOT_OK);
        }

        SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen      = 0u;
        SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending  = 0u;
        SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx        = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
        SoAd_SockConIdx2TxMgt(SoConIdx).CancelRequested = FALSE;
      }
    }
  }
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
  /* TP reception */
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
  /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
  if ( SoAd_IsSockRoutePresent() )
  {
    if ( SOAD_INV_PDU_ID != SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx )
    { /* reception may be ongoing */
      if ( TRUE == NormalClose )
      { /* reset caused by call to SoAd_CloseSoCon */
        /* check if all received data were forwarded to upper layer */
        if ( (SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_UDP) &&
          (0u != SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending) )
        { /* received data pending on UDP socket */
          SoAd_VCallTpRxIndication(SoAd_SockRoutes(SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx).SockRouteDest.UpperLayerId,
            SoAd_SockRoutes(SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx).SockRouteDest.RxPduId,
            E_NOT_OK);
        }
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
        else if ( (SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP) &&
          (0u != SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt.Lvl) )
        { /* received data pending on TCP socket */
          SoAd_VCallTpRxIndication(SoAd_SockRoutes(SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx).SockRouteDest.UpperLayerId,
            SoAd_SockRoutes(SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx).SockRouteDest.RxPduId,
            E_NOT_OK);
        }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
        else
        { /* no received data pending on TCP socket */
          SoAd_VCallTpRxIndication(SoAd_SockRoutes(SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx).SockRouteDest.UpperLayerId,
            SoAd_SockRoutes(SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx).SockRouteDest.RxPduId,
            E_OK);
        }
      }
      else
      { /* reset caused by different reason (not by normal close request) */
        SoAd_VCallTpRxIndication(SoAd_SockRoutes(SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx).SockRouteDest.UpperLayerId,
          SoAd_SockRoutes(SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx).SockRouteDest.RxPduId,
          E_NOT_OK);
      }
    }
    if ( SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr != NULL_PTR )
    {
      *SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr = 0u;
    }
    SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt.Lvl   = 0u;
    SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending  = 0u;
    SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested = FALSE;
    SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx        = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
  }
#else
  SOAD_DUMMY_STATEMENT_VAR(NormalClose); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */

#if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  /* empty tx queue if configured */
  if ( NULL_PTR != SoAd_SockCons(SoConIdx).TcpTxQueuePtr )
  {
    uint16 idx = SoAd_SockCons(SoConIdx).TcpTxQueuePtr->Size;
    while ( 0u < idx )
    {
      idx--;
      /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
      SoAd_SockCons(SoConIdx).TcpTxQueuePtr->QueuePtr[idx].TxPduIdx = SOAD_INV_PDU_IDX;
      SoAd_SockCons(SoConIdx).TcpTxQueuePtr->QueuePtr[idx].Len = 0u;
    }
    SoAd_SockCons(SoConIdx).TcpTxQueuePtr->MgtPtr->Idx = 0u;
    SoAd_SockCons(SoConIdx).TcpTxQueuePtr->MgtPtr->Lvl = 0u;
  }
#endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */

#if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
  if ( SoAd_IsNPduUdpTxPresent() )
  {
    uint16 idx = SoAd_SockConIdx2NPduUdpTxIdx(SoConIdx);

    if ( idx != SOAD_INV_BUF_IDX_16 )
    {
      SoAd_VNPduClear(idx);
    }
  }
#endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */

#if ( SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON )
  if ( SoAd_IsTimeoutListIdxUdpAlivePresent() )
  {
    SoAd_VTimeoutListRemoveElement(SoAd_TimeoutListIdxUdpAlive(), SoConIdx);
  }
#endif /* SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON */
}
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VResetLocalIpAddr
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VResetLocalIpAddr(SoAd_LocalAddrIdType LocalAddrId)
{
  SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).ifcIdx = SoAd_LocalAddr(LocalAddrId).IfcIdx;
  if ( SoAd_AddrId2LocalIpAddr(LocalAddrId).addrPtr == NULL_PTR )
  {
    SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).netmask = 0u;
    SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[0] = SOAD_IPADDR_ANY;
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    if ( SoAd_AddrId2LocalIpAddr(LocalAddrId).domain == SOAD_AF_INET6 )
    {
      SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[1] = SOAD_IPADDR_ANY;
      SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[2] = SOAD_IPADDR_ANY;
      SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[3] = SOAD_IPADDR_ANY;
    }
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
  }
  else
  {
    SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).netmask = SoAd_AddrId2LocalIpAddr(LocalAddrId).netmask;
    SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[0] = SoAd_AddrId2LocalIpAddr(LocalAddrId).addrPtr[0];
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    if ( SoAd_AddrId2LocalIpAddr(LocalAddrId).domain == SOAD_AF_INET6 )
    {
      SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[1] = SoAd_AddrId2LocalIpAddr(LocalAddrId).addrPtr[1];
      SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[2] = SoAd_AddrId2LocalIpAddr(LocalAddrId).addrPtr[2];
      SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[3] = SoAd_AddrId2LocalIpAddr(LocalAddrId).addrPtr[3];
    }
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
  }
}

/**********************************************************************************************************************
 *  SoAd_VCheckAndOverwriteLocalAddr
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VCheckAndOverwriteLocalAddr(SoAd_SoConIdxType SoConIdx,
                      boolean OverwriteLocal)
{
  Std_ReturnType retVal = E_NOT_OK;
  SoAd_LocalAddrIdType addrId = SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId;
  struct ifaddrs * addrPtr;

  /* get all local addresses */
  if ( 0 == getifaddrs(&addrPtr) )
  { /* retrieved all addresses successfully */
    struct ifaddrs * addrPtrIdx;
    uint8 family = AF_INET;

# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Domain == SOAD_AF_INET6 )
    {
      family = AF_INET6;
    }
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */

    for (addrPtrIdx = addrPtr; addrPtrIdx != NULL; addrPtrIdx = addrPtrIdx->ifa_next)
    {
      if ( if_nametoindex(addrPtrIdx->ifa_name) == SoAd_AddrId2LocalIpAddrDyn(addrId).ifcIdx )
      { /* same interface */
        if (addrPtrIdx->ifa_addr != NULL)
        {
          if ( family == addrPtrIdx->ifa_addr->sa_family )
          { /* same address family */
            if ( TRUE == OverwriteLocal )
            { /* overwrite current local address with first suitable local address on interface */
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
              if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Domain == SOAD_AF_INET6 )
              { /* IPv6 */
                uint8 idx32 = 4;

                /* store IP address */
                SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0] =
                  *((uint32*)&((struct sockaddr_in6*)addrPtrIdx->ifa_addr)->sin6_addr.s6_addr[0]);
                SoAd_AddrId2LocalIpAddrDyn(addrId).addr[1] =
                  *((uint32*)&((struct sockaddr_in6*)addrPtrIdx->ifa_addr)->sin6_addr.s6_addr[4]);
                SoAd_AddrId2LocalIpAddrDyn(addrId).addr[2] =
                  *((uint32*)&((struct sockaddr_in6*)addrPtrIdx->ifa_addr)->sin6_addr.s6_addr[8]);
                SoAd_AddrId2LocalIpAddrDyn(addrId).addr[3] =
                  *((uint32*)&((struct sockaddr_in6*)addrPtrIdx->ifa_addr)->sin6_addr.s6_addr[12]);

                /* store netmask */
                SoAd_AddrId2LocalIpAddrDyn(addrId).netmask = 0u;
                while ( 0u < idx32 )
                {
                  uint32 addr = *(uint32*)&((struct sockaddr_in6*)
                    addrPtrIdx->ifa_netmask)->sin6_addr.s6_addr[(--idx32) * 4];

                  if ( 0 != addr )
                  {
                    uint8 idx = 32;

                    while ( 0 < idx )
                    {
                      idx--;

                      if ( 0u != (addr << idx) )
                      {
                        SoAd_AddrId2LocalIpAddrDyn(addrId).netmask = (idx32 * 32) + idx + 1;
                        break;
                      }
                    }
                    break;
                  }
                }

                retVal = E_OK;
                break;
              }
              else
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
              { /* IPv4 */
                uint32 addr = *((uint32*)&((struct sockaddr_in*)addrPtrIdx->ifa_addr)->sin_addr.s_addr);
                uint8 idx = 32;

                /* store IP address */
                SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0] = addr;

                /* store netmask */
                addr = *((uint32*)&((struct sockaddr_in*)addrPtrIdx->ifa_netmask)->sin_addr.s_addr);
                SoAd_AddrId2LocalIpAddrDyn(addrId).netmask = 0u;
                while ( 0 < idx )
                {
                  idx--;

                  if ( 0u != (addr << idx) )
                  {
                    SoAd_AddrId2LocalIpAddrDyn(addrId).netmask = idx + 1;
                    break;
                  }
                }

                retVal = E_OK;
                break;
              }
            }
            else
            { /* no overwrite - check if local address matches configured local address only */
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
              if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Domain == SOAD_AF_INET6 )
              { /* IPv6 */
                uint32 *localAddrPtr = SoAd_AddrId2LocalIpAddrDyn(addrId).addr;
                uint32 *bsdAddrPtr = (uint32*)&((struct sockaddr_in6*)addrPtrIdx->ifa_addr)->sin6_addr.s6_addr;

                if ( (localAddrPtr[0] == bsdAddrPtr[0]) && (localAddrPtr[1] == bsdAddrPtr[1]) &&
                    (localAddrPtr[2] == bsdAddrPtr[2]) && (localAddrPtr[3] == bsdAddrPtr[3]) )
                { /* IP address match */
                  retVal = E_OK;
                  break;
                }
              }
              else
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
              { /* IPv4 */
                uint32 addr = *((uint32*)&((struct sockaddr_in*)addrPtrIdx->ifa_addr)->sin_addr.s_addr);

                if ( SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0] == addr )
                { /* IP address match */
                  retVal = E_OK;
                  break;
                }
              }
            }
          }
        }
      }
    }
    freeifaddrs(addrPtr);
  }
  return retVal;
}
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VTcpPduHdrRxIndication
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 0771 SoAd_146 */ /* MD_SoAd_14.6 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VTcpPduHdrRxIndication(SoAd_SoConIdxType SoConIdx,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        uint16 Length)
{
  /* add newly received data to segmented buffer struct */
  if ( E_OK != SoAd_VWriteBufSegment(BufPtr, Length, &SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt) )
  { /* segmented buffer struct cannot handle additional segments */
    SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
    /* set event to handle socket connection state in main function */
    SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
    SOAD_CallDetReportError(SOAD_API_ID_VTCP_PDU_HDR_RX_INDICATION, SOAD_E_NOBUFS);
  }
  else
  {
    SoAd_SockIdxType sockIdx = SoAd_SockCons(SoConIdx).SockIdx;
    SoAd_SocketIdType socketId = SoAd_SockIdx2SocketId(sockIdx);

    uint32 totalLen = SoAd_VGetBufSegmentTotLen(&SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt, 0);
    uint32 releaseBufLen = 0u;

    while ( releaseBufLen < totalLen )
    {
      SoAd_PduHdrIdType  pduHdrId;
      SoAd_PduHdrLenType pduHdrLen;

      if ( SOAD_INV_PDU_ID == SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
      { /* PDU header not extracted before */
        if ( SOAD_PDU_HDR_SIZE > (totalLen - releaseBufLen) )
        { /* PDU header not received completely */
          /* wait for next TCP segment */
          break;
        }
        else
        { /* PDU header received completely */
          boolean pduIsValid = FALSE;
          uint8   pduHdrBuf[SOAD_PDU_HDR_SIZE] = { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u };

          /* extract PDU header */
          SoAd_VCopyBufSeg2Buf(&pduHdrBuf[0], &SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt,
            SOAD_PDU_HDR_SIZE, releaseBufLen);
          IPBASE_GET_UINT32(pduHdrBuf, 0u, pduHdrId);
          IPBASE_GET_UINT32(pduHdrBuf, SOAD_PDU_HDR_ID_SIZE, pduHdrLen);

          if ( (SOAD_PDU_MAX_LEN < pduHdrLen) || (0u == pduHdrLen) ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
          { /* discard PDU */
            /* PRQA S 3355 1 */ /* MD_SoAd_13.7_CFG */ /* PRQA S 3358 1 */ /* MD_SoAd_13.7_CFG */
            if ( (uint32)(totalLen - releaseBufLen) < (SOAD_PDU_HDR_SIZE + pduHdrLen) )
            { /* PDU is not received completely */
              /* PRQA S 3382 1 */ /* MD_SoAd_21.1 */
              SoAd_SockIdx2SkipBytes(sockIdx) = (uint32)((SOAD_PDU_HDR_SIZE + pduHdrLen) -
                (uint32)(totalLen - releaseBufLen));
              releaseBufLen = totalLen;
            }
            else
            { /* PDU is received completely */ /* PRQA S 3201 */ /* MD_SoAd_13.7_CFG */
              releaseBufLen += (uint32)(SOAD_PDU_HDR_SIZE + pduHdrLen);
            }
          }
          else
          { /* PDU length valid */
            /* get all affected socket routes */
            uint16 routeIdx = SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxStart;
            uint16 routeNum = SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxNum;

            /* find socket route */
            while ( 0 < routeNum )
            {
              if ( SoAd_SockRoutes(routeIdx).RxPduHdrId == pduHdrId )
              {
#  if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
                if ( FALSE == SoAd_VCheckAnyRoutGrpOnSockRouteDestEnabled(routeIdx) )
                { /* no routing group is enabled for this socket route destination */
                  /* discard PDU */
                  if ( (uint32)(totalLen - releaseBufLen) < (SOAD_PDU_HDR_SIZE + pduHdrLen) )
                  { /* PDU is not received completely */
                    /* PRQA S 3382 1 */ /* MD_SoAd_21.1 */
                    SoAd_SockIdx2SkipBytes(sockIdx) = (uint32)((SOAD_PDU_HDR_SIZE + pduHdrLen) -
                      (uint32)(totalLen - releaseBufLen));
                    releaseBufLen = totalLen;
                  }
                  else
                  { /* PDU is received completely */
                    releaseBufLen += (uint32)(SOAD_PDU_HDR_SIZE + pduHdrLen);
                  }
                  /* valid PDU found */
                  pduIsValid = TRUE;
                  break;
                }
                else
#  endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
                {
                  if ( SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer == SOAD_UL_TYPE_IF )
                  { /* IF-API */
                    /* check length (configured length does not contain PDU Header size) */
                    if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SockIfRxBufMin < pduHdrLen )
                    { /* rx buffer is not sufficient */
                      SOAD_CallDetReportError(SOAD_API_ID_VTCP_PDU_HDR_RX_INDICATION, SOAD_E_NOBUFS);
                      /* discard PDU */
                      if ( (uint32)(totalLen - releaseBufLen) < (SOAD_PDU_HDR_SIZE + pduHdrLen) )
                      { /* PDU is not received completely */
                        /* PRQA S 3382 1 */ /* MD_SoAd_21.1 */
                        SoAd_SockIdx2SkipBytes(sockIdx) = (uint32)((SOAD_PDU_HDR_SIZE + pduHdrLen) -
                          (uint32)(totalLen - releaseBufLen));
                        releaseBufLen = totalLen;
                      }
                      else
                      { /* PDU is received completely */
                        releaseBufLen += (uint32)(SOAD_PDU_HDR_SIZE + pduHdrLen);
                      }
                    }
                    else
                    {
                      SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = routeIdx;
                      /* copy header to IF buffer */
                      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_VAR))
                        &SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferPtr[0],
                        (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))&pduHdrBuf[0],
                        SOAD_PDU_HDR_SIZE);
                      *SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr = SOAD_PDU_HDR_SIZE;
                      releaseBufLen += SOAD_PDU_HDR_SIZE;
                    }
                    /* valid PDU found */
                    pduIsValid = TRUE;
                    break;
                  }
                  else
                  { /* TP-API */
                    SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = routeIdx;
                    /* copy header to TP buffer */
                    IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_VAR))
                      &SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferPtr[0],
                      (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))&pduHdrBuf[0],
                      SOAD_PDU_HDR_SIZE);
                    releaseBufLen += SOAD_PDU_HDR_SIZE;
                    /* valid PDU found */
                    pduIsValid = TRUE;
                    break;
                  }
                }
              }
              routeNum--;
              routeIdx++;
            }
            if ( TRUE != pduIsValid )
            { /* no socket route found */
              SOAD_CallDetReportError(SOAD_API_ID_RX_INDICATION, SOAD_E_INV_PDUHEADER_ID);
              /* discard PDU */
              if ( (uint32)(totalLen - releaseBufLen) < (SOAD_PDU_HDR_SIZE + pduHdrLen) )
              { /* PDU is not received completely */
                /* PRQA S 3382 1 */ /* MD_SoAd_21.1 */
                SoAd_SockIdx2SkipBytes(sockIdx) = (uint32)((SOAD_PDU_HDR_SIZE + pduHdrLen) -
                  (uint32)(totalLen - releaseBufLen));
                releaseBufLen = totalLen;
              }
              else
              { /* PDU is received completely */
                releaseBufLen += (uint32)(SOAD_PDU_HDR_SIZE + pduHdrLen);
              }
            }
          }
        }
      }

      if ( SOAD_INV_PDU_ID != SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
      { /* PDU header is (now) extracted */
        PduInfoType pduInfo;

        uint16 routeIdx = SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx;

        if ( SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer == SOAD_UL_TYPE_IF )
        { /* IF-API */
          uint32 bufSegLen = 0u;

          /* get PDU length */
          IPBASE_GET_UINT32(SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferPtr, SOAD_PDU_HDR_ID_SIZE, pduHdrLen);

          /* check whether PDU is received within one TCP segment */
          SoAd_VGetBufSegment(&SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt, releaseBufLen, &pduInfo.SduDataPtr,
            &bufSegLen);
          if ( (*SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr == SOAD_PDU_HDR_SIZE) &&
            (pduHdrLen <= bufSegLen) )
          { /* PDU is within one TCP segment */
            releaseBufLen += pduHdrLen;
            *SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr += (PduLengthType)pduHdrLen;
          }
          else
          { /* PDU is segmented */
            uint32 bytesToCopy = (pduHdrLen + SOAD_PDU_HDR_SIZE) -
              *SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr;

            if ( bytesToCopy > (totalLen - releaseBufLen) )
            {
              bytesToCopy = totalLen - releaseBufLen;
            }

            /* copy to rx buffers */
            SoAd_VCopyBufSeg2Buf(&SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferPtr[
                *SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr],
              &SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt, bytesToCopy, releaseBufLen);

            *SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr += (PduLengthType)bytesToCopy;
            releaseBufLen += bytesToCopy;

            pduInfo.SduDataPtr = &SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferPtr[SOAD_PDU_HDR_SIZE];
          }

          /* forward PDU if received completely */
          if ( *SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr == (pduHdrLen + SOAD_PDU_HDR_SIZE) )
          { /* received completely */
            pduInfo.SduLength  = (PduLengthType)pduHdrLen;

            /* forward PDU */
            SoAd_VCallIfRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
              SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, &pduInfo);
            *SoAd_SockConIdx2RxBuffer(SoConIdx).IfRxBufferOffsetPtr = 0u;
            SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
          }
        }
        else
        { /* TP-API */
          PduLengthType bufferSize = 0u;

          /* get PDU length */
          IPBASE_GET_UINT32(SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferPtr, SOAD_PDU_HDR_ID_SIZE, pduHdrLen);

          if ( 0u == pduHdrLen )
          { /* PDU header length is 0 - skip further processing */
            SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
          }
          else
          { /* valid PDU header length */
            if ( 0u == SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
            { /* begin reception */
              if ( BUFREQ_OK != SoAd_VCallTpStartOfReception(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, (PduLengthType)pduHdrLen, &bufferSize) )
              { /* start of reception failed */
                /* discard PDU */
                if ( (uint32)(totalLen - releaseBufLen) < pduHdrLen )
                { /* PDU is not received completely */
                  SoAd_SockIdx2SkipBytes(sockIdx) = (uint32)(pduHdrLen - (totalLen - releaseBufLen));
                  releaseBufLen = totalLen;
                }
                else
                { /* PDU is received completely */
                  releaseBufLen += pduHdrLen;
                }
                SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
              }
              else
              { /* start of reception successful */
                SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = (PduLengthType)pduHdrLen;
              }
            }
          }

          if ( 0u < SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
          { /* reception is ongoing */
            uint32 bufSegLen  = 0u;

            pduInfo.SduDataPtr = NULL_PTR;
            pduInfo.SduLength  = 0u;
            bufferSize         = 1u;

            /* call copy rx data until all data are received */
            while ( 0u < SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
            {
              if ( TRUE == SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested )
              { /* reception is canceled */
                if ( (uint32)(totalLen - releaseBufLen) < SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
                { /* PDU is not received completely */
                  /* PRQA S 3382 1 */ /* MD_SoAd_21.1 */
                  SoAd_SockIdx2SkipBytes(sockIdx) = (uint32)(SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending -
                    (uint32)(totalLen - releaseBufLen));
                  releaseBufLen = Length;
                }
                else
                { /* PDU is received completely */
                  releaseBufLen += SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending;
                }

                SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = 0u;
                SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested = FALSE;

                /* call upper layer RxIndication with negative result value */
                SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                  SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_NOT_OK);

                /* close socket connection */
                SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                /* set event to handle socket connection state in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
                break;
              }

              if ( NULL_PTR == pduInfo.SduDataPtr )
              { /* first call of copy rx data */
                pduInfo.SduLength  = 0u;
              }

              /* get next segment */
              SoAd_VGetBufSegment(&SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt, releaseBufLen,
                &pduInfo.SduDataPtr, &bufSegLen);

              if ( 0u == bufSegLen )
              { /* no received data pending */
                break;
              }

              if ( pduInfo.SduLength > 0u )
              { /* consecutive call of copy rx data */
                if ( pduInfo.SduLength > bufSegLen )
                {
                  pduInfo.SduLength = (PduLengthType)bufSegLen;
                }
                if ( pduInfo.SduLength > SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
                {
                  pduInfo.SduLength = SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending;
                }
              }

              if ( BUFREQ_OK == SoAd_VCallTpCopyRxData(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, &pduInfo, &bufferSize) )
              { /* copying successful */
                releaseBufLen += pduInfo.SduLength;
                bufSegLen     -= pduInfo.SduLength;
                SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending -= pduInfo.SduLength;

                if ( 0u < SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
                { /* reception is ongoing */
                  if ( 0u == bufferSize )
                  { /* no buffer is left */
                    /* set event to try again in main function */
                    SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTpRxSoCon(), SoConIdx);
                    break;
                  }
                  /* set length to current bufferSize - will be updated in next loop cycle */
                  pduInfo.SduLength = bufferSize;
                }
                else
                { /* reception of PDU finished */
                  /* call upper layer TpRxIndication */
                  SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                    SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_OK);
                  SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                  SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested = FALSE;
                }
              }
              else
              { /* reception not possible */
                /* discard PDU */
                if ( (uint32)(totalLen - releaseBufLen) < SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
                { /* PDU is not received completely */
                  /* PRQA S 3382 2 */ /* MD_SoAd_21.1 */
                  SoAd_SockIdx2SkipBytes(sockIdx) =
                    (uint32)(SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending - (uint32)(totalLen - releaseBufLen));
                  releaseBufLen = totalLen;
                }
                else
                { /* PDU is received completely */
                  releaseBufLen += SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending;
                }
                SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = 0u;

                /* call upper layer RxIndication with negative result value */
                SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                  SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_NOT_OK);
              }
            }

            if ( 0u < SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
            { /* data remaining which was not accepted by upper layer */
              break;
            }
          }
        }
      }
    }
    if ( 0u != releaseBufLen )
    { /* buffer segment processed */
      if ( 0u < SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt.Lvl )
      { /* socket connection specific buffer struct is used */
        /* release SoAd socket connection specific buffer struct */
        SoAd_VReleaseBufSegment(&SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt, releaseBufLen);
      }
      /* release TcpIp buffer */
      (void)SoAd_VTcpIpReceived(socketId, releaseBufLen);
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:SoAd_146 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */

/**********************************************************************************************************************
 *  SoAd_VTcpRxIndication
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 0771 SoAd_146 */ /* MD_SoAd_14.6 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VTcpRxIndication(SoAd_SoConIdxType SoConIdx,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        uint16 Length)
{
  PduInfoType pduInfo;
  SoAd_SockIdxType sockIdx = SoAd_SockCons(SoConIdx).SockIdx;
  SoAd_SocketIdType socketId = SoAd_SockIdx2SocketId(sockIdx);
  uint32 releaseBufLen = 0u;
  /* get all affected socket routes */
  uint16 routeIdx = SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxStart;
  uint16 routeNum = SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxNum;

  while ( 0 < routeNum )
  { /* handle reception for all configured socket routes related to this socket connection */
#  if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
    if ( TRUE == SoAd_VCheckAnyRoutGrpOnSockRouteDestEnabled(routeIdx) )
    /* at least one routing group for this socket route destination is enabled */
    /* do not discard PDU for this socket route destination */
#  endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
    {
      if ( SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer == SOAD_UL_TYPE_IF )
      { /* IF-API */
        pduInfo.SduDataPtr = BufPtr;
        pduInfo.SduLength  = (PduLengthType)Length;

        /* call upper layer IF RxIndication */
        SoAd_VCallIfRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
          SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, &pduInfo);
        releaseBufLen = Length;
      }
      else
      { /* TP-API */
        /* in this case there is only one TP session possible per socket connection */
        /* the first socket route configured for this socket connection is used */

        /* TP session must be active due socket establishment */
        if ( SOAD_INV_PDU_ID != SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
        { /* TP session is active */
          PduLengthType bufferSize;

          /* merge received Pbuf with socket connection specific PBuf */
          if ( E_OK != SoAd_VWriteBufSegment(BufPtr, Length, &SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt) )
          {
            /* segmented buffer struct cannot handle additional segments */
            SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
            /* set event to handle socket connection state in main function */
            SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
            SOAD_CallDetReportError(SOAD_API_ID_VTCP_PDU_HDR_RX_INDICATION, SOAD_E_NOBUFS);
          }
          else
          {
            /* set dummy values */
            pduInfo.SduDataPtr = NULL_PTR;
            pduInfo.SduLength  = 1u;
            bufferSize         = 1u;

            /* copy data to upper layer until no upper layer buffer or TcpIp buffer is available */
            while ( pduInfo.SduLength != 0u )
            {
              if ( TRUE == SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested )
              { /* reception is canceled for this PDU */
                /* no specific handling specified by AUTOSAR - socket will be closed */
                SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested = FALSE;
                SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                /* set event to handle socket connection state in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
                releaseBufLen = Length;
                break;
              }
              else
              {
                if ( NULL_PTR == pduInfo.SduDataPtr )
                { /* first call of CopyRxData */
                  pduInfo.SduLength = 0u;
                }

                /* call CopyRxData */
                if ( BUFREQ_OK != SoAd_VCallTpCopyRxData(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                    SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId,
                    &pduInfo,
                    &bufferSize) )
                {
                  SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                  /* set event to handle socket connection state in main function */
                  SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
                  releaseBufLen = Length;
                  break;
                }
                else
                {
                  uint32 bufSegLen = 0u;

                  releaseBufLen += pduInfo.SduLength;

                  if ( bufferSize == 0u )
                  { /* no buffer left */
                    /* set event to try again in main function */
                    SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTpRxSoCon(), SoConIdx);
                    break;
                  }

                  /* get next TcpIp buf segment */
                  SoAd_VGetBufSegment(&SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt, releaseBufLen,
                    &pduInfo.SduDataPtr, &bufSegLen);

                  pduInfo.SduLength = (PduLengthType)bufSegLen;

                  if ( pduInfo.SduLength > bufferSize )
                  {
                    pduInfo.SduLength = bufferSize;
                  }
                }
              }
            }
          }
        }
      }
    }
#  if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
    else
    {
      releaseBufLen = Length;
    }
#  endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
    routeNum--;
    routeIdx++;
  }
  if ( 0u != releaseBufLen )
  { /* buffer segment processed */
    if ( 0u < SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt.Lvl )
    { /* socket connection specific buffer struct is used */
      /* release SoAd socket connection specific TcpIp buffer struct */
      SoAd_VReleaseBufSegment(&SoAd_SockConIdx2RxMgt(SoConIdx).BufSegMgt, releaseBufLen);
    }
    /* release TcpIp buffer */
    (void)SoAd_VTcpIpReceived(socketId, releaseBufLen);
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:SoAd_146 */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */

# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */

# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VUdpPduHdrRxIndication
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 3673 SoAd_167 */ /* MD_SoAd_16.7 */
/* PRQA S 0771 SoAd_146 */ /* MD_SoAd_14.6 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VUdpPduHdrRxIndication(SoAd_SoConIdxType SoConIdx,
                                        P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        uint16 Length)
{
  SoAd_SockIdxType   sockIdx     = SoAd_SockCons(SoConIdx).SockIdx;
  uint16             readDataLen = 0u;
  SoAd_PduHdrIdType  pduHdrId;
  SoAd_PduHdrLenType pduHdrLen;
  PduInfoType        pduInfo;
  uint16             routeIdx;
  uint16             routeNum;
#  if ( defined(SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) && (STD_ON == SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) )
  uint16             offset      = Length;

  if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->UdpStrictHdrLenCheckEnabled == TRUE )
  {
    offset = 0u;

    /* check if PDU Header lengths is valid for entire frame */
    while ( offset < Length )
    {
      if ( ((uint16)(Length - offset)) >= SOAD_PDU_HDR_SIZE )
      {
        IPBASE_GET_UINT32(BufPtr, (offset + SOAD_PDU_HDR_ID_SIZE), pduHdrLen);

        offset += SOAD_PDU_HDR_SIZE;
        if ( pduHdrLen > ((SoAd_PduHdrLenType)(Length - offset)) )
        {
          break;
        }
        offset += (uint16)pduHdrLen;
      }
      else
      {
        break;
      }
    }
  }

  if ( offset == Length )
  { /* PDU Header length is valid */
#  endif /* defined(SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) && (STD_ON == SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) */

    while ( Length > readDataLen )
    {
      boolean validPduIdFound = FALSE;
#  if ( defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) )
      SoAd_SoConIdxType soConIdxEnd = (SoAd_SoConIdxType)((SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart +
        SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum) - 1u);
#  endif /* defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) */

      /* check whether complete PDU header is available */
      if ( SOAD_PDU_HDR_SIZE > (uint16)(Length - readDataLen) )
      { /* invalid length - discard entire message */
        break;
      }

      /* extract PDU information from buffer */
      IPBASE_GET_UINT32(BufPtr, readDataLen, pduHdrId);
      IPBASE_GET_UINT32(BufPtr, (readDataLen + SOAD_PDU_HDR_ID_SIZE), pduHdrLen);

      /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
      if ( (SOAD_PDU_MAX_LEN < pduHdrLen) || ((Length - readDataLen - SOAD_PDU_HDR_SIZE) < pduHdrLen) )
      { /* received PDU header length invalid - discard entire message */
        break;
      }

#  if ( defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) )
      while ( SoConIdx <= soConIdxEnd )
      {
        if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->BestMatchWithPduHeaderEnabled == TRUE )
        {
          if ( SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxNum > 1u )
          { /* more than one socket connection is configured for this socket - use the best match algorithm */
            if ( E_OK != SoAd_VGetSoConIdByBestMatchAlg(RemoteAddrPtr, SoConIdx, soConIdxEnd,
              SOAD_SOCON_FILTER_DISABLED,
#   if ( defined(SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) )
              SoAd_SockCons(SoConIdx).SockConGrpPtr->BestMatchWithSockRouteEnabled,
#   else
              FALSE,
#   endif /* defined(SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED)&& STD_ON == SOAD_VBEST_MATCH_WITH_SOCK_ROUTE_ENABLED) */
              &SoConIdx) )
            { /* no suitable socket connection found */
              readDataLen += (uint16)(pduHdrLen + SOAD_PDU_HDR_SIZE);
              break;
            }
          }
        }
#  endif /* defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) */

        routeIdx = SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxStart;
        routeNum = SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxNum;

        while ( 0 < routeNum )
        { /* try to find the corresponding socket route for the extracted PDU */
          if ( SoAd_SockRoutes(routeIdx).RxPduHdrId == pduHdrId )
          { /* PDU ID match - check length */
            if ( pduHdrLen > (SoAd_PduHdrLenType)(Length - readDataLen) )
            { /* invalid length - discard entire message */
              break;
            }
            validPduIdFound = TRUE;
            if ( (0u == pduHdrLen) && (SOAD_UL_TYPE_TP == SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer) )
            { /* PDU is valid but has length 0 - not possible for TP upper layer */
              break;
            }

            /* validate transmission/reception state */
            if ( SOAD_CLOSE_NONE != SoAd_SockConIdx2CloseMode(SoConIdx) )
            { /* transmission/reception is disabled (by a previous socket connection close request) */
              break;
            }

            /* use message acceptance policy if configured */
            if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->MsgAcceptFilterEnabled == TRUE )
            {
              if ( E_OK != SoAd_VCompareSockAddr((SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(SoConIdx),
                RemoteAddrPtr, TRUE) )
              { /* message is not accepted */
                break;
              }
            }

#  if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
            /* check routing group states */
            if ( TRUE != SoAd_VCheckAnyRoutGrpOnSockRouteDestEnabled(routeIdx) )
            { /* routing group is not enabled - do not open socket connection */
              break;
            }
#  endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */

            /* validate socket connection state */
            if ( SOAD_SOCON_ONLINE != SoAd_SockConIdx2State(SoConIdx) )
            { /* socket connection is not online - this is only allowed in specific cases */
              Std_ReturnType retVal = E_NOT_OK;

              /* check whether specific case is applicable */
              if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->MsgAcceptFilterEnabled == TRUE )
              { /* message acceptance filter is enabled */
                if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->UdpListenOnly == FALSE )
                { /* open socket connection and update remote address */
                  SoAd_VCopyIpAddr((SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(SoConIdx), RemoteAddrPtr, FALSE);
                  SoAd_SockConIdx2RemAddrState(SoConIdx) = SOAD_SOCON_IP_SET_PORT_SET;
                  if ( SOAD_SOCK_STATE_ESTABLISHED != SoAd_SockIdx2SockState(sockIdx) )
                  {
                    SoAd_SockIdx2SockState(sockIdx) = SOAD_SOCK_STATE_ESTABLISHED;
                    SoAd_OpenSocks++;
                  }
                  SoAd_SockConIdx2State(SoConIdx) = SOAD_SOCON_ONLINE;
#  if ( defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) )
                  /* check whether a alive timeout is configured */
                  if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt != 0u )
                  { /* alive timeout is configured */
                    /* set counter */
                    (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxUdpAlive(), SoConIdx,
                      SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt, SoAd_GlobalCounter);
                  }
#  endif /* defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) */
                  /* inform upper layer about socket connection state change */
                  SoAd_VCallChgFunc(SoConIdx, SoAd_SockCons(SoConIdx).SoConChgFuncBitPattern,
                    SOAD_CHG_FUNC_TYPE_SOCONMODE, SOAD_SOCON_ONLINE);
                  retVal = E_OK;
                }
              }
              if ( E_OK != retVal )
              { /* reception on this socket connection while socket connection is not online is not valid */
                break;
              }
            }
#  if ( defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) )
            else
            {
              /* check whether a alive timeout is configured */
              if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt != 0u )
              {
                uint32 currentTimeoutCnt = 0u;

                if ( SoAd_VTimeoutListGetCurrentTimeout(SoAd_TimeoutListIdxUdpAlive(), SoConIdx, &currentTimeoutCnt,
                    SoAd_GlobalCounter) == E_OK )
                { /* opened by a reception */
                  /* set new timeout */
                  /* return value has not to be considered since timeout ist already in list */
                  (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxUdpAlive(), SoConIdx,
                    SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt, SoAd_GlobalCounter);
                }
              }
            }
#  endif /* defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) */

#  if ( defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) )
            /* update received remote address */
            if ( NULL_PTR != SoAd_SockCons(SoConIdx).RcvRemSockPtr )
            { /* get recevied remote address is supported */
              SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
              /* copy remote address to local buffer */
              SoAd_VCopyIpAddr(SoAd_SockCons(SoConIdx).RcvRemSockPtr, RemoteAddrPtr, TRUE);
              SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            }
#  endif /* defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) */

            if ( SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer == SOAD_UL_TYPE_IF )
            { /* IF-API */
#  if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
              if ( TRUE == SoAd_VCheckAnyRoutGrpOnSockRouteDestEnabled(routeIdx) )
                /* at least one routing group for this socket route destination is enabled */
                /* do not discard PDU for this socket route destination */
#  endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
              {
                pduInfo.SduDataPtr = &BufPtr[readDataLen + SOAD_PDU_HDR_SIZE];
                pduInfo.SduLength  = (PduLengthType)pduHdrLen;

                /* call upper layer IF RxIndication */
                SoAd_VCallIfRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                  SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, &pduInfo);
              }
            }
            else
            { /* TP-API */
              PduLengthType bufferSize = 0u;

              if ( SOAD_INV_PDU_ID == SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
              { /* TP session is not active - otherwise PDU is discarded */
                /* call StartOfReception */
                if ( BUFREQ_OK == SoAd_VCallTpStartOfReception(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                  SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId,
                  (PduLengthType)pduHdrLen,
                  &bufferSize) )
                { /* start of reception successful - otherwise PDU is discarded */
                  SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = routeIdx;
                  SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = (PduLengthType)pduHdrLen;

                  if ( 0u == bufferSize )
                  { /* reception possible but no buffer is available */
                    /* check whether PDU fits into rx buffer */
                    if ( SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending >
                      SoAd_SockCons(SoConIdx).SockConGrpPtr->SockTpRxBufMin )
                    { /* buffer is not sufficient - invalid PDU length received */
                      SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                      SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = 0u;

                      /* call upper layer RxIndication with negative result value */
                      SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                        SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_NOT_OK);
                    }
                    else
                    {
                      /* copy PDU data (without header) to TP rx buffer */
                      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_VAR))
                        &SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferPtr[0],
                        (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))
                        &BufPtr[readDataLen + SOAD_PDU_HDR_SIZE],
                        SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending);
                      *SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr =
                        (uint16)SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending;
                    }
                  }
                }
                if ( SOAD_INV_PDU_ID != SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                { /* TP session is active */
                  pduInfo.SduDataPtr = NULL_PTR;
                  pduInfo.SduLength = 1u;

                  /* copy data to upper layer */
                  while ( 0u != SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
                  {
                    if ( TRUE == SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested )
                    { /* reception is canceled */
                      SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                      SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = 0u;
                      SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested = FALSE;

                      /* call upper layer RxIndication with negative result value */
                      SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                        SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_NOT_OK);

                      /* close socket connection in next MainFunction cycle */
                      SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                      /* set event to handle socket connection state in main function */
                      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
                      break;
                    }
                    else
                    {
                      /* copy data to upper layer  */
                      if ( NULL_PTR == pduInfo.SduDataPtr )
                      { /* first call of CopyRxData */
                        pduInfo.SduLength = 0u;
                      }

                      /* call CopyRxData */
                      if ( BUFREQ_OK != SoAd_VCallTpCopyRxData(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                        SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId,
                        &pduInfo,
                        &bufferSize) )
                      { /* reception is not possible - discard PDU */
                        SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                        SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = 0u;
                        SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested = FALSE;

                        /* call upper layer RxIndication with negative result value */
                        SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                          SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_NOT_OK);
                      }
                      else
                      { /* data segment copied successfully */
                        SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending -= pduInfo.SduLength;
                        if ( 0u == SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
                        { /* PDU received completely */
                          /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
                          SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID;

                          /* call upper layer RxIndication with negative result value */
                          SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                            SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_OK);
                        }
                        else
                        { /* pending PDU data */
                          if ( 0u < bufferSize )
                          { /* upper layer has avaiable buffer to copy data */
                            pduInfo.SduLength = SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending;
                            if ( pduInfo.SduLength > bufferSize )
                            {
                              pduInfo.SduLength = bufferSize;
                            }
                            pduInfo.SduDataPtr = &BufPtr[readDataLen + SOAD_PDU_HDR_SIZE];
                          }
                          else
                          { /* upper layer has no buffer */
                            /* check whether PDU fits into rx buffer */
                            if ( SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending >
                              SoAd_SockCons(SoConIdx).SockConGrpPtr->SockTpRxBufMin )
                            { /* buffer is not sufficient - invalid PDU length received */
                              /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
                              SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID;
                              SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = 0u;

                              /* call upper layer RxIndication with negative result value */
                              SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                                SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_NOT_OK);
                            }
                            else
                            {
                              /* copy PDU data (without header) to TP rx buffer */
                              IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_VAR))
                                &SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferPtr[0],
                                (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))
                                &BufPtr[readDataLen + SOAD_PDU_HDR_SIZE],
                                SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending);
                              *SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr =
                                (uint16)SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending;
                              /* set event to try again in main function */
                              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTpRxSoCon(), SoConIdx);
                              break;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if ( TRUE == validPduIdFound )
          { /* valid PDU found */
            break;
          }
          routeNum--;
          routeIdx++;
        }
        /* check whether a valid PDU could be extracted */
#  if ( defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) )
        if ( TRUE == validPduIdFound )
        { /* valid PDU found */
          readDataLen += (uint16)(pduHdrLen + SOAD_PDU_HDR_SIZE);
          break;
        }
        if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->BestMatchWithPduHeaderEnabled == TRUE )
        { /* no valid PDU found and best match considers the PDU */
          SoConIdx++;
          if ( SoConIdx > soConIdxEnd )
          { /* no valid PDU found */
            SOAD_CallDetReportError(SOAD_API_ID_RX_INDICATION, SOAD_E_INV_PDUHEADER_ID);
            readDataLen += (uint16)(pduHdrLen + SOAD_PDU_HDR_SIZE);
            break;
          }
        }
        else
        { /* no valid PDU found */
          SOAD_CallDetReportError(SOAD_API_ID_RX_INDICATION, SOAD_E_INV_PDUHEADER_ID);
          readDataLen += (uint16)(pduHdrLen + SOAD_PDU_HDR_SIZE);
          break;
        }
      }
#  else
        if ( FALSE == validPduIdFound )
        {
          SOAD_CallDetReportError(SOAD_API_ID_RX_INDICATION, SOAD_E_INV_PDUHEADER_ID);
        }
        readDataLen += (uint16)(pduHdrLen + SOAD_PDU_HDR_SIZE);
# endif /* defined(SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) && (STD_ON == SOAD_VBEST_MATCH_WITH_PDU_HDR_ENABLED) */
    }
#  if ( defined(SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) && (STD_ON == SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) )
  }
#  endif /* defined(SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) && (STD_ON == SOAD_VUDP_STRICT_HDR_LEN_CHECK_ENABLED) */
}
/* PRQA L:MSR_11715 */
/* PRQA L:SoAd_167 */
/* PRQA L:SoAd_146 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED */

/**********************************************************************************************************************
 *  SoAd_VUdpRxIndication
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 0771 SoAd_146 */ /* MD_SoAd_14.6 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VUdpRxIndication(SoAd_SoConIdxType SoConIdx,
                                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                        uint16 Length)
{
  PduInfoType pduInfo;
  /* get all affected socket routes */
  uint16 routeIdx = SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxStart;
  uint16 routeNum = SoAd_SockConIdx2SockRouteCol(SoConIdx).SockRouteIdxNum;

  while ( 0 < routeNum )
  { /* handle reception for all configured socket routes related to this socket connection */
# if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
    if ( FALSE == SoAd_VCheckAnyRoutGrpOnSockRouteDestEnabled(routeIdx) )
    { /* all routing groups for this socket route destination are disabled */
      /* discard PDU for this socket route destination */
    }
    else
# endif /* defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
    {
      if ( SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayer == SOAD_UL_TYPE_IF )
      { /* IF-API */
        pduInfo.SduDataPtr = &BufPtr[0];
        pduInfo.SduLength  = (PduLengthType)Length;

        /* call corresponding upper layer IF RxIndication */
        SoAd_VCallIfRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
          SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, &pduInfo);
      }
      else
      { /* TP-API */
        if ( SOAD_INV_PDU_ID != SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
        { /* TP session is active - discard message otherwise */
          /* check whether rx buffer is filled already */
          if ( 0u < *SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr )
          { /* buffer is filled already */
            /* check whether PDU fits into rx buffer */
            if ( (*SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr + Length) <=
              SoAd_SockCons(SoConIdx).SockConGrpPtr->SockTpRxBufMin )
            { /* buffer is sufficient - discard message otherwise */
              /* copy PDU data (without header) to TP rx buffer */
              IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_VAR))
                &SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferPtr[
                  *SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr],
                (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))&BufPtr[0],
                Length);
              *SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr += Length;
              SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending += (PduLengthType)Length;
            }
          }
          else
          { /* buffer is empty - try to copy data here */
            PduLengthType bufferSize = 1u;

            pduInfo.SduDataPtr = NULL_PTR;
            pduInfo.SduLength = 1u;

            SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = (PduLengthType)Length;

            /* copy data to upper layer */
            while ( (0u < bufferSize) && (0u != SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending) )
            {
              if ( TRUE == SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested )
              { /* reception is canceled */
                SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = 0u;
                SoAd_SockConIdx2RxMgt(SoConIdx).CancelRequested = FALSE;

                /* call upper layer RxIndication with negative result value */
                SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                  SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_NOT_OK);

                /* close socket connection in next MainFunction cycle */
                SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                /* set event to handle socket connection state in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
                break;
              }
              else
              {
                /* copy data to upper layer  */
                if ( NULL_PTR == pduInfo.SduDataPtr )
                { /* first call of CopyRxData */
                  pduInfo.SduLength = 0u;
                }

                /* call CopyRxData */
                if ( BUFREQ_OK != SoAd_VCallTpCopyRxData(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                  SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId,
                  &pduInfo,
                  &bufferSize) )
                { /* reception is not possible - close socket connection */
                  SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending = 0u;
                  SoAd_SockConIdx2RxMgt(SoConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                  SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                  /* set event to handle socket connection state in main function */
                  SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
                  break;
                }
                /* data segment copied successfully */
                SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending -= pduInfo.SduLength;
                if ( 0u != SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending )
                { /* pending PDU data */
                  if ( 0u < bufferSize )
                  { /* upper layer has buffer to copy data */
                    pduInfo.SduLength = SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending;
                    if ( pduInfo.SduLength > bufferSize )
                    {
                      pduInfo.SduLength = bufferSize;
                    }
                    pduInfo.SduDataPtr = &BufPtr[Length - SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending];
                  }
                  else
                  { /* upper layer has no buffer */
                    /* check whether PDU fits into rx buffer */
                    if ( SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending <=
                      SoAd_SockCons(SoConIdx).SockConGrpPtr->SockTpRxBufMin )
                    {
                      /* copy PDU data to TP rx buffer */
                      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_VAR))
                          &SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferPtr[0],
                        (P2CONST(IpBase_CopyDataType, AUTOMATIC, SOAD_APPL_DATA))
                          &BufPtr[Length - SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending],
                        SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending);
                      *SoAd_SockConIdx2RxBuffer(SoConIdx).TpRxBufferOffsetPtr =
                        (uint16)SoAd_SockConIdx2RxMgt(SoConIdx).RxBytesPending;
                      /* set event to try again in main function */
                      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTpRxSoCon(), SoConIdx);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    routeNum--;
    routeIdx++;
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:SoAd_146 */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */

#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
/**********************************************************************************************************************
 *  SoAd_VIfTransmit
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VIfTransmit(
                        SoAd_SoConIdxType SoConIdx,
                        P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInforPtr,
                        P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_VAR) PduRouteDestPtr)
{
  Std_ReturnType   retVal  = E_NOT_OK;
  SoAd_PduIdxType  txPduIdx;
  PduLengthType    dataLen = PduInforPtr->SduLength;
  SoAd_SockIdxType sockIdx = SoAd_SockCons(SoConIdx).SockIdx;

  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  SOAD_GetPduRouteIdxCheckDetError(txPduIdx, PduRouteDestPtr->TxPduId, SOAD_API_ID_IF_TRANSMIT);

  /* check socket state, socket connection state and transmission/reception state */
  if ( (SOAD_SOCK_STATE_ESTABLISHED == SoAd_SockIdx2SockState(sockIdx)) &&
    (SOAD_SOCON_ONLINE == SoAd_SockConIdx2State(SoConIdx)) &&
    (SOAD_CLOSE_NONE == SoAd_SockConIdx2CloseMode(SoConIdx)) )
  { /* states are valid */
    if ( (SOAD_TX_CONF_STRAT_BIT_PAT_CONF & SoAd_TxPduIdx2PendingTxConf(txPduIdx)) < SOAD_TX_CONF_STRAT_BIT_PAT_CONF)
    { /* TxConfirmation queue is sufficient */
      /* further handling depends on socket configuration */
# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
      if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
      { /* PDU Header ID is enabled */
        dataLen += SOAD_PDU_HDR_SIZE;
      }
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
      if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP )
      { /* TCP socket */
        /* store PDU in global PDU struct for CopyTxData */
        SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        if ( (SOAD_INV_SO_CON_IDX == SoAd_SockIdx2ActiveSoConIdx(sockIdx)) )
        {
          /* set local socket index to active socket connection mapping */
          SoAd_SockIdx2ActiveSoConIdx(sockIdx) = SoConIdx;
          SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

#  if ( SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON )
          if ( SoAd_TxPduIdx2PduRoute(txPduIdx).IfTriggerTransmitEnabled == TRUE )
          { /* trigger transmit */
            uint16 bufIdx = SoAd_SockConIdx2IfTriggerTransmitBufIdx(SoConIdx);
            PduInfoType info;

            info.SduDataPtr = SoAd_IfTriggerTransmitBuffer(bufIdx).BufPtr;
            info.SduLength = SoAd_IfTriggerTransmitBuffer(bufIdx).MaxLen;

            if ( SoAd_VCallIfTriggerTransmit(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                SoAd_TxPduIdx2TxConfPduId(txPduIdx), &info) == E_OK )
            { /* trigger transmit successful */
              uint8 minLen = 1u;

              /* check out parameter and update data length */
              dataLen = 0u;
#   if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
              if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
              {
                minLen = 0u;
                dataLen = SOAD_PDU_HDR_SIZE;
              }
#   endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */

              if ( (info.SduDataPtr != NULL_PTR) && (info.SduLength >= minLen) &&
                (info.SduLength <= SoAd_IfTriggerTransmitBuffer(bufIdx).MaxLen) )
              { /* copied valid length */
                dataLen += info.SduLength;

                /* set tx management struct for CopyTxData */
                SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = txPduIdx;
                SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = dataLen;
                SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending = dataLen;
                SoAd_SockConIdx2TxMgt(SoConIdx).TxBufPtr = SoAd_IfTriggerTransmitBuffer(bufIdx).BufPtr;
              }
            }
          }
          else
#  endif /* SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON */
          { /* direct transmit */
            /* set tx management struct for CopyTxData */
            SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = txPduIdx;
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = dataLen;
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending = dataLen;
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBufPtr = PduInforPtr->SduDataPtr;
          }

#  if ( SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON )
          if ( SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx != SOAD_INV_PDU_IDX )
#  endif /* SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON */
          {
            if ( E_OK == SoAd_VTcpTxQueueReserveNextElement(SoConIdx, txPduIdx) )
            {
              if ( E_OK == SoAd_VTcpIpTransmit(SoAd_SockIdx2SocketId(sockIdx), dataLen) )
              { /* transmission successful */
                SoAd_VTcpTxQueueSetElement(SoConIdx, txPduIdx, SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen, FALSE);

                /* handle TxConfirmation */
                SoAd_VAddPendingIfTxConf(txPduIdx, SoConIdx);

#  if ( SOAD_VSOCKET_BSD_API_ENABLED == STD_ON )
                /* set event to handle TCP confirmation in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTxSoCon(), SoConIdx);
#  endif /* SOAD_VSOCKET_BSD_API_ENABLED == STD_ON */

                retVal = E_OK;
              }
              else
              { /* transmission failed */
                SoAd_VTcpTxQueueSetElement(SoConIdx, txPduIdx, 0, TRUE);
              }
            }

            /* reset tx management struct */
            SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBufPtr = NULL_PTR;
          }
        }
        else
        {
          SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }

        /* reset local socket index to active socket connection mapping */
        SoAd_SockIdx2ActiveSoConIdx(sockIdx) = SOAD_INV_SO_CON_IDX;
      }
      else
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
      { /* UDP socket */
# if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
        uint16 nPduUdpTxIdx = SOAD_INV_BUF_IDX_16;
        if ( SoAd_IsNPduUdpTxPresent() )
        {
          nPduUdpTxIdx = SoAd_SockConIdx2NPduUdpTxIdx(SoConIdx);
        }
# endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */

        retVal = E_NOT_OK;
# if ( defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) )
        /* check if an alive timeout is configured */
        if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt != 0u )
        {
          uint32 currentTimeoutCnt = 0u;

          if ( SoAd_VTimeoutListGetCurrentTimeout(SoAd_TimeoutListIdxUdpAlive(), SoConIdx, &currentTimeoutCnt,
              SoAd_GlobalCounter) == E_OK )
          { /* opened by a reception */
            /* set new timeout */
            /* return value has not to be considered since timeout ist already in list */
            (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxUdpAlive(), SoConIdx,
              SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt, SoAd_GlobalCounter);
          }
        }
# endif /* defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) */
# if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
        if ( SOAD_INV_BUF_IDX_16 != nPduUdpTxIdx )
        { /* nPduUdpTx is configured */
          if ( dataLen <= SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->NPduUdpTxBufferMin )
          { /* PDU size is valid */
#  if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
#   if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
            if ( SoAd_NPduUdpTx(nPduUdpTxIdx).QueueMgtPtr != NULL_PTR )
#   endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
            { /* NPduUdpTxQueue is used */
              switch ( SoAd_VNPduQueueAddElement(txPduIdx, PduRouteDestPtr, PduInforPtr) )
              {
                case SOAD_NPDU_OVFL_NEW:
                { /* remaining length is not sufficient for new PDU */
                  /* send queue now */
                  SoAd_VNPduQueueSend(nPduUdpTxIdx);
                  /* add PDU */
                  if ( SoAd_VNPduQueueAddElement(txPduIdx, PduRouteDestPtr, PduInforPtr) == SOAD_NPDU_OK )
                  { /* PDU added */
                    /* check if PDU triggers transmission */
                    if ( PduRouteDestPtr->TxUdpTrigMode == SOAD_TX_UDP_TRIGGER_ALWAYS )
                    { /* PDU triggers transmission */
                      /* send queue now */
                      SoAd_VNPduQueueSend(nPduUdpTxIdx);
                    }
                    retVal = E_OK;
                  }
                  break;
                }
                case SOAD_NPDU_OVFL_UPDATE:
                { /* remaining length is not sufficient for updated PDU */
                  /* send queue now (length has been updated) */
                  SoAd_VNPduQueueSend(nPduUdpTxIdx);
                  retVal = E_OK;
                  break;
                }
                case SOAD_NPDU_OK:
                { /* remaining length is sufficient for new PDU */
                  if ( PduRouteDestPtr->TxUdpTrigMode == SOAD_TX_UDP_TRIGGER_ALWAYS )
                  { /* PDU triggers transmission */
                    /* send queue now */
                    SoAd_VNPduQueueSend(nPduUdpTxIdx);
                  }
                  retVal = E_OK;
                  break;
                }
                default: /* SOAD_NPDU_NOT_OK */
                { /* PDU cannot be sent */
                  /* nothing to do */
                }
              }
            }
#   if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
            else
#   endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
#  endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
#  if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
            { /* NPduUdpTxBuffer is used */
              SoAd_NPduReturnType nPduRetVal = SoAd_VNPduBufAddElement(txPduIdx, PduRouteDestPtr, PduInforPtr);

              if ( nPduRetVal == SOAD_NPDU_OK )
              { /* remaining length is sufficient */
                /* check if PDU triggers transmission */
                if ( PduRouteDestPtr->TxUdpTrigMode == SOAD_TX_UDP_TRIGGER_ALWAYS )
                { /* PDU triggers transmission */
                  /* send queue now */
                  SoAd_VNPduBufSend(nPduUdpTxIdx);
                }
                retVal = E_OK;
              }
              else if ( nPduRetVal == SOAD_NPDU_OVFL_NEW )
              { /* remaining length is not sufficient */
                /* send buffer now */
                SoAd_VNPduBufSend(nPduUdpTxIdx);
                /* try to add PDU again */
                if ( SoAd_VNPduBufAddElement(txPduIdx, PduRouteDestPtr, PduInforPtr) == SOAD_NPDU_OK )
                { /* added PDU */
                  /* check if PDU triggers transmission */
                  if ( PduRouteDestPtr->TxUdpTrigMode == SOAD_TX_UDP_TRIGGER_ALWAYS )
                  { /* PDU triggers transmission */
                    /* send queue now */
                    SoAd_VNPduBufSend(nPduUdpTxIdx);
                  }
                  retVal = E_OK;
                }
              }
              else
              { /* nPduRetVal == SOAD_NPDU_NOT_OK */
                /* PDU could not be added to nPduUdpTxBuffer */
                /* nothing to do */
              }
            }
#  endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
          }
          else
          { /* requested PDU is larger than the the nPduUdpTxBuffer */
            SOAD_CallDetReportError(SOAD_API_ID_VIF_TRANSMIT, SOAD_E_NOBUFS);
          }
        }
        else
# endif /* defined(SOAD_VN_PDU_UDP_TX_BUF_ENABLED) && (STD_ON == SOAD_VN_PDU_UDP_TX_BUF_ENABLED) */
        { /* nPduUdpTx is not used */
          /* try to send PDU */
          /* store PDU in global PDU struct for CopyTxData */
          SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          if ( SOAD_INV_SO_CON_IDX == SoAd_SockIdx2ActiveSoConIdx(sockIdx) )
          {
            /* set local socket index to active socket connection mapping */
            SoAd_SockIdx2ActiveSoConIdx(sockIdx) = SoConIdx;
            /* set tx management struct for CopyTxData */
            SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = txPduIdx;
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = dataLen;
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending = dataLen;
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBufPtr = PduInforPtr->SduDataPtr;
            SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

            /* try to send new PDU */
            if ( E_OK == SoAd_VTcpIpUdpTransmit(sockIdx, SoAd_SockIdx2SocketId(sockIdx),
              (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&SoAd_SockConIdx2RemSockDyn(SoConIdx),
              (uint16)dataLen) )
            { /* transmission successful */
              /* handle TxConfirmation */
# if ( defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) )
              if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->ImmedIfTxConf != TRUE )
# endif /* defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) */
              { /* No UdpImmediateIfTxConfirmation is configured */
                SoAd_VAddPendingIfTxConf(txPduIdx, SoConIdx);
              }

              retVal = E_OK;
            }

            /* reset tx management struct */
            SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBufPtr = NULL_PTR;

            /* reset local socket index to active socket connection mapping */
            SoAd_SockIdx2ActiveSoConIdx(sockIdx) = SOAD_INV_SO_CON_IDX;
          }
          else
          {
            SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          }
        }
      }
    }
    else
    {
      SOAD_CallDetReportError(SOAD_API_ID_VIF_TRANSMIT, SOAD_E_NOBUFS);
    }
  }
  return retVal;
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
/**********************************************************************************************************************
 *  SoAd_VTcpTxConfirmation
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VTcpTxConfirmation(SoAd_SoConIdxType SoConIdx, SoAd_PduIdxType TxPduIdx)
{
  if ( (SoAd_TxPduIdx2PduRoute(TxPduIdx).UpperLayer == SOAD_UL_TYPE_TP) )
  { /* TP-API */
    if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->ImmedTpTxConf == FALSE )
    {
      if ( TRUE != SoAd_SockConIdx2TxMgt(SoConIdx).CancelRequested )
      {
        /* socket connecion handling if automatic setup is enabled and wildcards configured */
        if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SockAutoSoConSetup == TRUE )
        {
          if ( (SOAD_SOCON_IP_ANY_PORT_ANY >= SoAd_SockConIdx2RemAddrState(SoConIdx)) &&
            (0u != (SoAd_SockCons(SoConIdx).RemAddrState & SOAD_SOCON_MASK_ANY)) )
          {
            SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_RECONNECT;
            /* set event to handle socket connection state in main function */
            SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
          }
        }

        /* reset TxMgt struct */
        SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
        SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = 0u;

        /* reset local socket index to active socket connection mapping */
        SoAd_SockIdx2ActiveSoConIdx(SoAd_SockCons(SoConIdx).SockIdx) = SOAD_INV_SO_CON_IDX;

        SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(TxPduIdx).UpperLayerId,
          SoAd_TxPduIdx2TxConfPduId(TxPduIdx), E_OK);
      }
    }
  }
  else
  { /* IF-API */
    if ( SoAd_TxPduIdx2PduRoute(TxPduIdx).TxConfEnabled == TRUE )
    { /* TxConfirmation is configured for the corresponding upper layer and PDU */
      SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      if ( 0u < (SoAd_TxPduIdx2PendingTxConf(TxPduIdx) & SOAD_TX_CONF_STRAT_BIT_PAT_CONF) )
      {
        /* there is a pending TxConfirmation for one of the PduRouteDests */
        SoAd_TxPduIdx2PendingTxConf(TxPduIdx)--;
        if ( 0u == SoAd_TxPduIdx2PendingTxConf(TxPduIdx) )
        { /* call TxConfirmation of upper layer only if all PduRouteDests are confirmed (PDU fan-out) */
          SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          /* socket connecion handling if automatic setup is enabled and wildcards configured */
          if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SockAutoSoConSetup == TRUE )
          {
            if ( (SOAD_SOCON_IP_ANY_PORT_ANY >= SoAd_SockConIdx2RemAddrState(SoConIdx)) &&
              (0u != (SoAd_SockCons(SoConIdx).RemAddrState & SOAD_SOCON_MASK_ANY)) )
            {
              SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_RECONNECT;
              /* set event to handle socket connection state in main function */
              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
            }
          }
          /* call TxConfirmation of upper layer */
          SoAd_VCallIfTxConfirmation(SoAd_TxPduIdx2PduRoute(TxPduIdx).UpperLayerId,
            SoAd_TxPduIdx2TxConfPduId(TxPduIdx));
        }
        else
        {
          SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }
      }
      else
      {
        SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */

/**********************************************************************************************************************
 *  SoAd_VHandleShutdown
 *********************************************************************************************************************/
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleShutdown(void)
{
  if ( 0 != SoAd_OpenSocks )
  { /* sockets still opened */
    if ( 0u < SoAd_ShutdownFinishedCnt )
    {
      SoAd_ShutdownFinishedCnt--;
      if ( 0u == SoAd_ShutdownFinishedCnt )
      {
        SoAd_SockIdxType sockIdx = SoAd_TcpIpSocketCnt();

        /* close all sockets (will implicitly close all socket connections) */
        while ( 0u < sockIdx )
        {
          SoAd_SocketIdType socketId;

          sockIdx--;

          socketId = SoAd_SockIdx2SocketId(sockIdx);
          if ( SOAD_INV_SOCKET_ID != socketId ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
          { /* socket still bound */
            (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
          }
        }
      }
    }
  }
  else
  { /* all sockets closed */
    SoAd_ShutdownFinishedCnt = 0u;
  }
}
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VHandleShutdownFinish
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleShutdownFinish(void)
{
  if ( (0u == SoAd_ShutdownFinishedCnt) || (0u == SoAd_OpenSocks) )
  { /* shutdown finished */
    SoAd_State = SOAD_STATE_SHUTDOWN;
#if ( defined(SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) )
    SoAd_VCallShutdwnFinishedFuncs();
#endif /* defined(SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) */
  }
  else
  {
    boolean soConsClosed = TRUE;
    SoAd_SoConIdxType soConIdx = SoAd_SockConTotal();

    while ( 0u < soConIdx )
    {
      soConIdx--;

      if ( SOAD_SOCON_OFFLINE != SoAd_SockConIdx2State(soConIdx) )
      { /* socket connection not offline */
        soConsClosed = FALSE;
        if ( SOAD_CLOSE_NONE == SoAd_SockConIdx2CloseMode(soConIdx) )
        { /* socket connection not closing */
          /* check for pending transmissions */
          if ( SOAD_INV_PDU_IDX == SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
          { /* transmission is not active (e.g. TP session) */
#if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
            boolean nPduPending = FALSE;

            /* check if nPduUdpTx is filled */
            if ( SoAd_IsNPduUdpTxPresent() )
            {
              if ( SoAd_SockConIdx2NPduUdpTxIdx(soConIdx) != SOAD_INV_BUF_IDX_16 )
              {
                if ( SoAd_NPduUdpTx(SoAd_SockConIdx2NPduUdpTxIdx(soConIdx)).MgtPtr->TotalLen != 0u )
                { /* nPdu is pending */
                  /* update timeout to send nPdu immediately in next main function */
                  (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(),
                      SoAd_SockConIdx2NPduUdpTxIdx(soConIdx), 1u, SoAd_GlobalCounter);
                  nPduPending = TRUE;
                }
              }
            }
            if ( nPduPending == FALSE )
              /* nPduUdpTx is empty */
#endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */
            {
#if ( SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED == STD_ON )
              /* check if routing group transmit is pending */
              uint16 pduRouteDestIdx;
              uint16 pduRouteDestNum = SoAd_SockConIdx2PduRouteDestCol(soConIdx).PduRouteDestListSize;
              boolean routGrpTransmitPending = FALSE;

              for ( pduRouteDestIdx = 0u; pduRouteDestIdx < pduRouteDestNum; pduRouteDestIdx++ )
              {
                SoAd_RoutingGroupIdType grpIdx;
                SoAd_RoutingGroupIdType grpNum = SoAd_SockConIdx2PduRouteDestCol(soConIdx).
                  PduRouteDestListPtr[pduRouteDestIdx]->RoutGrpNum;

                for ( grpIdx = 0u; grpIdx < grpNum; grpIdx++ )
                {
                  if ( (*SoAd_SockConIdx2PduRouteDestCol(soConIdx).PduRouteDestListPtr[
                      pduRouteDestIdx]->RoutGrpStateColPtr[grpIdx] & SOAD_ROUT_GRP_BIT_PATTERN_TRIGGER) != 0u )
                  { /* if routing group transmit */
                    routGrpTransmitPending = TRUE;
                    break;
                  }
                }
                if ( routGrpTransmitPending == TRUE )
                {
                  break;
                }
              }
              if ( routGrpTransmitPending == FALSE )
#endif /* SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED == STD_ON */
              {
                SoAd_SockConIdx2CloseMode(soConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                /* set event to handle socket connection state in main function */
                SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
              }
            }
          }
        }
      }
    }
    if ( TRUE == soConsClosed )
    { /* all socket connections are offline */
      SoAd_SockIdxType sockIdx = SoAd_TcpIpSocketCnt();

      /* release UDP sockets for socket connection which can be opened on reception */
      while ( 0u < sockIdx )
      {
        SoAd_SocketIdType socketId;

        sockIdx--;

        socketId = SoAd_SockIdx2SocketId(sockIdx);
        if ( SOAD_INV_SOCKET_ID != socketId ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
        { /* socket still bound */
          if ( NULL_PTR != SoAd_SockCons(SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart).SockConGrpPtr->SocketUdpPtr )
          { /* UDP socket */
            (void)SoAd_VTcpIpClose(socketId, FALSE, sockIdx, TRUE);
          }
        }
      }

      /* check if all sockets are released now */
      if ( 0u == SoAd_OpenSocks )
      {
        SoAd_State = SOAD_STATE_SHUTDOWN;
#if ( defined(SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) )
        SoAd_VCallShutdwnFinishedFuncs();
#endif /* defined(SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == SOAD_VSHUTDOWN_FINISHED_CBK_SUPPORT) */
      }
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VHandleIpAddrStates
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleIpAddrStates(void)
{
  uint16 handleIdx = SOAD_INV_PDU_IDX;
  SoAd_LocalAddrIdType lvl = (SoAd_SockIdxType)SoAd_EventQueues(SoAd_EventQueueIdxLocalAddr()).EveMgtPtr->Lvl;
  SoAd_LocalAddrIdType_least idx;

# if ( SOAD_VEVE_QUE_LIMIT_LOCALADDR_ENALBED == STD_ON )
  if ( lvl > SoAd_EventQueues(SoAd_EventQueueIdxLocalAddr()).EveQueLimit )
  {
    lvl = (SoAd_LocalAddrIdType)SoAd_EventQueues(SoAd_EventQueueIdxLocalAddr()).EveQueLimit;
  }
# endif /* SOAD_VEVE_QUE_LIMIT_LOCALADDR_ENALBED == STD_ON */

  for ( idx = 0u; idx < lvl; idx++ )
  {
    if ( SoAd_VEventQueueGetNextElement(SoAd_EventQueueIdxLocalAddr(), &handleIdx) == E_OK )
    {
      boolean addEventAgain = FALSE;
      SoAd_LocalAddrIdType addrId = (SoAd_LocalAddrIdType)handleIdx;
      SoAd_SoConIdxType firstSoConIdx;

      firstSoConIdx = SoAd_SockIdx2SoConIdxCol(SoAd_AddrId2SockIdxCol(addrId).SockIdxColPtr[0]).SoConIdxStart;

      SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* check IP address state */
      if ( SOAD_IPADDR_STATE_ASSIGNED != SoAd_SockConIdx2IpAddrState(firstSoConIdx) )
      { /* IP address not yet assigned */
        if ( (SOAD_ASSIGN_TRIGGER_AUTOMATIC == SoAd_LocalAddr(addrId).AssignTrigger) ||
          (SOAD_LOCAL_IP_ADDR_REQ_STATE_REQUEST == SoAd_AddrId2LocalIpAddrReqState(addrId)) )
        { /* IP address trigger is automatic or address is requested */
          /* check for wildcard */
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
          if ( SoAd_SockCons(firstSoConIdx).SockConGrpPtr->Domain == SOAD_AF_INET6 )
          { /* IPv6 */
            if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_UNICAST )
            {
              if ( (SOAD_IP6ADDR_ANY == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0]) &&
                (SOAD_IP6ADDR_ANY == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[1]) &&
                (SOAD_IP6ADDR_ANY == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[2]) &&
                (SOAD_IP6ADDR_ANY == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[3]) )
              { /* local address is wildcard (i.e. unassigned DHCP) */
                /* overwrite local address with first suitable address on interface */
                if ( E_OK == SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, TRUE) )
                { /* SoAd local address overwritten successfully */
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  /* IP address assigned */
                  SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE;
                  SoAd_LocalIpAddrAssignmentChg(addrId, SOAD_IPADDR_STATE_ASSIGNED);
                }
                else
                {
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  addEventAgain = TRUE;
                }
              }
              else
              { /* static IP address */
                /* check if IP address is available */
                if ( E_OK == SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, FALSE) )
                { /* IP address available */
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  /* IP address assigned */
                  SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE;
                  SoAd_LocalIpAddrAssignmentChg(addrId, SOAD_IPADDR_STATE_ASSIGNED);
                }
                else
                {
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  addEventAgain = TRUE;
                }
              }
            }
            else
            { /* multicast address */
              SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

              SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE;
              SoAd_LocalIpAddrAssignmentChg(addrId, SOAD_IPADDR_STATE_ASSIGNED);
            }
          }
          else
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
          { /* IPv4 */
            if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_UNICAST )
            { /* unicast address */
              if ( SOAD_IPADDR_ANY == SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0] )
              { /* local address is wildcard (i.e. unassigned DHCP) */
                /* overwrite local address with first suitable address on interface */
                if ( E_OK == SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, TRUE) )
                { /* SoAd local address overwritten successfully */
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  /* IP address assigned */
                  SoAd_LocalIpAddrAssignmentChg(addrId, SOAD_IPADDR_STATE_ASSIGNED);
                  SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE;
                }
                else
                {
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  addEventAgain = TRUE;
                }
              }
              else
              { /* static IP address */
                /* check if IP address is available */
                if ( E_OK == SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, FALSE) )
                { /* IP address available */
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  /* IP address assigned */
                  SoAd_LocalIpAddrAssignmentChg(addrId, SOAD_IPADDR_STATE_ASSIGNED);
                  SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE;
                }
                else
                {
                  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                  addEventAgain = TRUE;
                }
              }
            }
            else
            { /* multicast address */
              SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

              SoAd_LocalIpAddrAssignmentChg(addrId, SOAD_IPADDR_STATE_ASSIGNED);
              SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE;
            }
          }
        }
        else
        {
          SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }
      }
      else
      { /* IP address assigned */
        SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        if ( SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE == SoAd_AddrId2LocalIpAddrReqState(addrId) )
        { /* IP address shall be released */
          /* close all corresponding sockets */
          SoAd_SockIdxType sockIdxNum = SoAd_AddrId2SockIdxCol(addrId).SockIdxNum;

          while ( 0u < sockIdxNum )
          {
            SoAd_SockIdxType sockIdx;
            SoAd_SocketIdType socketId;

            sockIdxNum--;
            sockIdx = SoAd_AddrId2SockIdxCol(addrId).SockIdxColPtr[sockIdxNum];
            socketId = SoAd_SockIdx2SocketId(sockIdx);

            if ( SOAD_INV_SOCKET_ID != socketId )
            { /* socket is assigned */
              /* close TcpIp socket */
              (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
            }
          }

          SoAd_VResetLocalIpAddr(addrId);
          SoAd_AddrId2LocalIpAddrReqState(addrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE;
          SoAd_LocalIpAddrAssignmentChg(addrId, SOAD_IPADDR_STATE_UNASSIGNED);

          if (SoAd_LocalAddr(addrId).AssignTrigger == SOAD_ASSIGN_TRIGGER_AUTOMATIC)
          {
            /* try to reassign local address in main function */
            addEventAgain = TRUE;
          }
        }
      }

      if ( addEventAgain == TRUE )
      { /* add event again to queue */
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), addrId);
      }
    }
    else
    { /* no element left */
      break;
    }
  }
}

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
/**********************************************************************************************************************
 *  SoAd_VHandleTcpSocketStates
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleTcpSocketStates(void)
{
  uint16 handleIdx = SOAD_INV_PDU_IDX;
  SoAd_SockIdxType lvl = (SoAd_SockIdxType)SoAd_EventQueues(SoAd_EventQueueIdxSockIdx()).EveMgtPtr->Lvl;
  SoAd_SockIdxType_least idx;

#  if ( SOAD_VEVE_QUE_LIMIT_SOCKIDX_ENALBED == STD_ON )
  if ( lvl > SoAd_EventQueues(SoAd_EventQueueIdxSockIdx()).EveQueLimit )
  {
    lvl = (SoAd_PduIdxType)SoAd_EventQueues(SoAd_EventQueueIdxSockIdx()).EveQueLimit;
  }
#  endif /* SOAD_VEVE_QUE_LIMIT_SOCKIDX_ENALBED == STD_ON */

  for ( idx = 0u; idx < lvl; idx++ )
  {
    if ( SoAd_VEventQueueGetNextElement(SoAd_EventQueueIdxSockIdx(), &handleIdx) == E_OK )
    {
      boolean addEventAgain = FALSE;
      SoAd_SockIdxType sockIdx = (SoAd_SockIdxType)handleIdx;

      if ( SOAD_SOCK_STATE_CLOSED != SoAd_SockIdx2SockState(sockIdx) )
      {
        SoAd_SocketIdType socketId = SoAd_SockIdx2SocketId(sockIdx);
        SoAd_SoConIdxType soConIdx = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;

        if ( NULL_PTR != SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr )
        { /* TCP socket */
          if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr->TcpInitiate == TRUE )
          { /* client socket */
            if ( SOAD_SOCK_STATE_CONNECT == SoAd_SockIdx2SockState(sockIdx) )
            { /* client socket not connected yet */
              if ( SOAD_AF_INET == SoAd_SockConIdx2RemSockDyn(soConIdx).domain )
              {
                struct sockaddr_in sockAddr;

                sockAddr.sin_family = AF_INET;
                SoAd_VConvertAsrSockAddr2BsdSockAddr(SOAD_A_P2VAR(struct sockaddr)&sockAddr,
                  SOAD_A_P2CONST(SoAd_SockAddrType)&SoAd_SockConIdx2RemSockDyn(soConIdx));

                if ( 0 > connect(socketId, SOAD_A_P2CONST(struct sockaddr)&sockAddr, sizeof(sockAddr)))
                { /* failed - maybe connection establishment still active */
                  if ( EALREADY != errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
                  { /* failed */
                    /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
                    SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VHANDLE_SOCKET_STATES, SOAD_SOCK_BSD_API_CONNECT,
                      SOAD_SOCK_BSD_PARAM_NONE, SoAd_SockCons(soConIdx).SoConId, socketId, errno);
                    /* close socket */
                    (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
                  }
                  else
                  {
                    addEventAgain = TRUE;
                  }
                }
                else
                { /* connection established successfully */
                  SoAd_TcpConnected(socketId);
                }
              }
  #  if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
              else
              {
                struct sockaddr_in6 sockAddr;

                sockAddr.sin6_family = AF_INET6;
                sockAddr.sin6_scope_id = SoAd_AddrId2LocalIpAddrDyn(
                  SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId).ifcIdx;
                SoAd_VConvertAsrSockAddr2BsdSockAddr(SOAD_A_P2VAR(struct sockaddr)&sockAddr,
                  SOAD_A_P2CONST(SoAd_SockAddrType)&SoAd_SockConIdx2RemSockDyn(soConIdx));

                if ( 0 > connect(socketId, SOAD_A_P2VAR(struct sockaddr)&sockAddr, sizeof(sockAddr)))
                { /* failed - maybe connection establishment still active */
                  if ( EALREADY != errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
                  { /* failed */
                    /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
                    SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VHANDLE_SOCKET_STATES, SOAD_SOCK_BSD_API_CONNECT,
                      SOAD_SOCK_BSD_PARAM_NONE, SoAd_SockCons(soConIdx).SoConId, socketId, errno);
                    /* close socket */
                    (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
                  }
                  else
                  {
                    addEventAgain = TRUE;
                  }
                }
                else
                { /* connection established successfully */
                  SoAd_TcpConnected(socketId);
                }
              }
  #  endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
            }
            else
            {
              /* add event again to handle socket reception in rx main function */
              addEventAgain = TRUE;
            }
          }
          else
          { /* server socket */
            if ( sockIdx == SoAd_SockCons(soConIdx).SockConGrpPtr->GrpSockIdx )
            { /* listen socket */
              if ( SOAD_SOCK_STATE_LISTEN == SoAd_SockIdx2SockState(sockIdx) )
              { /* listen */
                if ( SOAD_AF_INET == SoAd_SockCons(soConIdx).SockConGrpPtr->Domain )
                { /* IPv4 */
                  SoAd_SocketIdType socketIdConnected;
                  struct sockaddr_in sockAddr;
                  socklen_t sockAddrLen = sizeof(sockAddr);

                  sockAddr.sin_family = AF_INET;
                  socketIdConnected = accept(socketId, SOAD_A_P2VAR(struct sockaddr)&sockAddr, &sockAddrLen);
                  if ( -1 != socketIdConnected )
                  { /* new socket available */
                    if ( sizeof(sockAddr) != sockAddrLen )
                    { /* returned invalid address length */
                      /* close socket */
                      (void)SoAd_VTcpIpClose(socketIdConnected, TRUE, sockIdx, TRUE);
                    }
                    else
                    {
                      SoAd_SockAddrInetXType RemSockAddr;

                      RemSockAddr.domain = SOAD_AF_INET;
                      SoAd_VConvertBsdSockAddr2AsrSockAddr(SOAD_A_P2VAR(SoAd_SockAddrType)&RemSockAddr,
                        SOAD_A_P2CONST(struct sockaddr)&sockAddr);

                      if ( E_OK == SoAd_VTcpIpChangeParameter(soConIdx, socketIdConnected, TRUE) )
                      {
                        if ( E_OK != SoAd_TcpAccepted(socketId, socketIdConnected,
                            SOAD_A_P2VAR(SoAd_SockAddrType)&RemSockAddr))
                        { /* remote entity not accepted */
                          /* close socket */
                          (void)SoAd_VTcpIpClose(socketIdConnected, TRUE, sockIdx, TRUE);
                        }
                      }
                      else
                      { /* ChangeParamter failed */
                        /* close socket */
                        (void)SoAd_VTcpIpClose(socketIdConnected, TRUE, sockIdx, TRUE);
                      }
                    }
                    addEventAgain = TRUE;
                  }
                  else
                  { /* error */
                    if ( (EAGAIN == errno) || (EWOULDBLOCK == errno) ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
                    { /* no new socket available in accepted queue */
                      addEventAgain = TRUE;
                    }
                    else
                    { /* unexpected error */
                      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
                      SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VHANDLE_SOCKET_STATES, SOAD_SOCK_BSD_API_ACCEPT,
                        SOAD_SOCK_BSD_PARAM_NONE, SoAd_SockCons(soConIdx).SoConId, socketId, errno);
                      /* close socket */
                      (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
                    }
                  }
                }
  #  if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
                else
                { /* IPv6 */
                  SoAd_SocketIdType socketIdConnected;
                  struct sockaddr_in6 sockAddr;
                  socklen_t sockAddrLen = sizeof(sockAddr);

                  sockAddr.sin6_family = AF_INET6;
                  socketIdConnected = accept(socketId, SOAD_A_P2VAR(struct sockaddr)&sockAddr, &sockAddrLen);
                  if ( -1 != socketIdConnected )
                  { /* new socket available */
                    if ( sizeof(sockAddr) != sockAddrLen )
                    { /* returned invalid address length */
                      /* close socket */
                      (void)SoAd_VTcpIpClose(socketIdConnected, TRUE, sockIdx, TRUE);
                    }
                    else
                    {
                      SoAd_SockAddrInetXType RemSockAddr;

                      RemSockAddr.domain = SOAD_AF_INET6;
                      SoAd_VConvertBsdSockAddr2AsrSockAddr(SOAD_A_P2VAR(SoAd_SockAddrType)&RemSockAddr,
                        SOAD_A_P2CONST(struct sockaddr)&sockAddr);

                      if ( E_OK == SoAd_VTcpIpChangeParameter(soConIdx, socketIdConnected, TRUE) )
                      {
                        if ( E_OK != SoAd_TcpAccepted(socketId, socketIdConnected,
                            SOAD_A_P2VAR(SoAd_SockAddrType)&RemSockAddr))
                        { /* remote entity not accepted */
                          /* close socket */
                          (void)SoAd_VTcpIpClose(socketIdConnected, TRUE, sockIdx, TRUE);
                        }
                      }
                      else
                      { /* ChangeParamter failed */
                        /* close socket */
                        (void)SoAd_VTcpIpClose(socketIdConnected, TRUE, sockIdx, TRUE);
                      }
                    }
                    addEventAgain = TRUE;
                  }
                  else
                  { /* error */
                    if ( (EAGAIN == errno) || (EWOULDBLOCK == errno) ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
                    { /* no new socket available in accepted queue */
                      addEventAgain = TRUE;
                    }
                    else
                    { /* unexpected error */
                      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
                      SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VHANDLE_SOCKET_STATES, SOAD_SOCK_BSD_API_ACCEPT,
                        SOAD_SOCK_BSD_PARAM_NONE, SoAd_SockCons(soConIdx).SoConId, socketId, errno);
                      /* close socket */
                      (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
                    }
                  }
                }
  #  endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
              }
              else
              { /* closing */
                SoAd_TcpIpEvent(socketId, SOAD_TCP_CLOSED);
              }
            }
            else
            { /* data socket */
              /* add event again to handle socket reception in rx main function */
              addEventAgain = TRUE;
            }
          }
        }
        else
        { /* UDP socket */
          /* add event again to handle socket reception in rx main function */
          addEventAgain = TRUE;
        }
      }
      if ( addEventAgain == TRUE )
      { /* add event again to queue */
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxSockIdx(), sockIdx);
      }
    }
    else
    { /* no element left */
      break;
    }
  }
}
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

/**********************************************************************************************************************
 *  SoAd_VHandleSoConStates
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleSoConStates(void)
{
  uint16 handleIdx = SOAD_INV_SO_CON_IDX;
  SoAd_SoConIdxType lvl = (SoAd_SoConIdxType)SoAd_EventQueues(SoAd_EventQueueIdxStateSoCon()).EveMgtPtr->Lvl;
  SoAd_SoConIdxType_least idx;

#if ( SOAD_VEVE_QUE_LIMIT_STATESOCON_ENALBED == STD_ON )
  if ( lvl > SoAd_EventQueues(SoAd_EventQueueIdxStateSoCon()).EveQueLimit )
  {
    lvl = (SoAd_SoConIdxType)SoAd_EventQueues(SoAd_EventQueueIdxStateSoCon()).EveQueLimit;
  }
#endif /* SOAD_VEVE_QUE_LIMIT_STATESOCON_ENALBED == STD_ON */

  for ( idx = 0u; idx < lvl; idx++ )
  {
    if ( SoAd_VEventQueueGetNextElement(SoAd_EventQueueIdxStateSoCon(), &handleIdx) == E_OK )
    {
      SoAd_SoConIdxType soConIdx = (SoAd_SoConIdxType)handleIdx;

      if ( SOAD_CLOSE_NONE != SoAd_SockConIdx2CloseMode(soConIdx) )
      {
        /* close socket connection */
        SoAd_VCloseSockCon(soConIdx);
      }
      else
      {
        if ( SOAD_STATE_INIT == SoAd_State )
        { /* perform open actions not in case of shutdown */
          if ( (SoAd_SockCons(soConIdx).SockConGrpPtr->SockAutoSoConSetup == TRUE) ||
            (SOAD_SOCON_RECONNECT == SoAd_SockConIdx2State(soConIdx)) ||
            (0u < SoAd_SockConIdx2FlagCntOpCl(soConIdx)) )
          { /* open socket connection automatically or if requested */
            if ( (SOAD_SOCON_ONLINE != SoAd_SockConIdx2State(soConIdx)) &&
              (SOAD_IPADDR_STATE_ASSIGNED == SoAd_SockConIdx2IpAddrState(soConIdx)) )
            { /* socket connection is not online and IP is assigned */
              SoAd_VOpenSockCon(soConIdx);
            }
          }
          else
          { /* do not open socket connection but check if TcpIp socket shall be assigned */
            if ( SOAD_IPADDR_STATE_ASSIGNED == SoAd_SockConIdx2IpAddrState(soConIdx) )
            { /* IP is assigned */
              if ( SOAD_SOCK_STATE_CLOSED == SoAd_SockIdx2SockState(SoAd_SockCons(soConIdx).SockIdx) )
              { /* no TcpIp socket is assigned */
                if ( SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_UDP )
                { /* UDP socket connection */
                  if ( (SoAd_SockCons(soConIdx).SockConGrpPtr->MsgAcceptFilterEnabled == TRUE) &&
                    (SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpListenOnly == FALSE) )
                  { /* message acceptance filter is enabled and UDP listen only dsisabled */
                    boolean ipAddrIsAny = FALSE;
                    boolean portIsAny = FALSE;

                    SoAd_VCheckForWildcards(SoAd_SockCons(soConIdx).RemSockPtr, &ipAddrIsAny, &portIsAny);
                    if ( (TRUE == ipAddrIsAny) || (TRUE == portIsAny) )
                    { /* wildcards are configured */
                      /* all condtions are fufilled to open socket connection on reception - assign socket */
                      SoAd_VAssignUdpSocket(soConIdx);
                      if ( SoAd_SockIdx2SockState(SoAd_SockCons(soConIdx).SockIdx) != SOAD_SOCK_STATE_ESTABLISHED )
                      { /* TcpIp socket not assigned */
                        /* set event to handle socket connection state in main function again */
                        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    { /* no element left */
      break;
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

#if ( SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON )
/**********************************************************************************************************************
 *  SoAd_VHandleUdpAliveTimeout
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleUdpAliveTimeout(void)
{
  uint16 elementIdx = 0u;
  uint16 handleIdx = SOAD_INV_HND_16;

  while ( SoAd_VTimeoutListCheckElements(SoAd_TimeoutListIdxUdpAlive(), &elementIdx, &handleIdx, SoAd_GlobalCounter) ==
    E_OK )
  { /* timout occured */
    SoAd_SoConIdxType soConIdx = (SoAd_SoConIdxType)handleIdx;

    SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* handle timeout */
    if ( (SOAD_SOCON_ONLINE == SoAd_SockConIdx2State(soConIdx)) &&
      (SOAD_CLOSE_NONE == SoAd_SockConIdx2CloseMode(soConIdx)) )
    { /* socket connection is still online and not requested to be closed */
      /* close socket connection later in MainFunction */
      SoAd_SockConIdx2CloseMode(soConIdx) = SOAD_CLOSE_RECONNECT;

      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* set event to handle socket connection state in main function */
      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
    }
    else
    {
      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }

    /* remove element from list */
    SoAd_VTimeoutListRemoveElement(SoAd_TimeoutListIdxUdpAlive(), handleIdx);
  }
}
#endif /* SOAD_VUDP_ALIVE_TIMEOUT_ENALBED == STD_ON */

#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
/**********************************************************************************************************************
 *  SoAd_VHandleTpReception
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleTpReception(void)
{
  uint16 handleIdx = SOAD_INV_SO_CON_IDX;
  SoAd_SoConIdxType lvl = (SoAd_SoConIdxType)SoAd_EventQueues(SoAd_EventQueueIdxTpRxSoCon()).EveMgtPtr->Lvl;
  SoAd_SoConIdxType_least idx;

# if ( SOAD_VEVE_QUE_LIMIT_TPRXSOCON_ENALBED == STD_ON )
  if ( lvl > SoAd_EventQueues(SoAd_EventQueueIdxTpRxSoCon()).EveQueLimit )
  {
    lvl = (SoAd_SoConIdxType)SoAd_EventQueues(SoAd_EventQueueIdxTpRxSoCon()).EveQueLimit;
  }
# endif /* SOAD_VEVE_QUE_LIMIT_TPRXSOCON_ENALBED == STD_ON */

  for ( idx = 0u; idx < lvl; idx++ )
  {
    if ( SoAd_VEventQueueGetNextElement(SoAd_EventQueueIdxTpRxSoCon(), &handleIdx) == E_OK )
    {
      boolean addEventAgain = FALSE;
      SoAd_SoConIdxType soConIdx = (SoAd_SoConIdxType)handleIdx;

      /* check socket connection state */
      if ( (SOAD_SOCON_ONLINE == SoAd_SockConIdx2State(soConIdx)) &&
        (SOAD_CLOSE_NONE == SoAd_SockConIdx2CloseMode(soConIdx)) )
      { /* socket connection is online and not requested to be closed */
        SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        if ( TRUE == SoAd_SockConIdx2RxMgt(soConIdx).CancelRequested )
        { /* reception is canceled */
          uint16 routeIdx = SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx;

          if ( SOAD_INV_PDU_ID != routeIdx )
          {
            if ( SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_UDP )
            {
              *SoAd_SockConIdx2RxBuffer(soConIdx).TpRxBufferOffsetPtr = 0u;
            }
            SoAd_SockConIdx2RxMgt(soConIdx).RxBytesPending = 0u;
            SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
            SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

            /* call TpRxIndication */
            SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
              SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_NOT_OK);
          }
          else
          {
            SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          }

          /* close socket connection in next MainFunction cycle */
          SoAd_SockConIdx2CloseMode(soConIdx) = SOAD_CLOSE_OFFLINE_RESET;
          /* set event to handle socket connection state in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);

          SoAd_SockConIdx2RxMgt(soConIdx).CancelRequested = FALSE;
        }
        else
        {
          SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  # if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
          if ( SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP)
          { /* TCP socket */
            /* check whether TcpIp buffer is available */
            if ( 0u < SoAd_SockConIdx2RxMgt(soConIdx).BufSegMgt.Lvl )
            {
              uint16 curLvl = (uint16)(SoAd_SockConIdx2RxMgt(soConIdx).BufSegMgt.Lvl - 1u);
              uint16 lastIdx;

              /* get current index */
              if ( (SoAd_SockConIdx2RxMgt(soConIdx).BufSegMgt.Idx + curLvl) >= SOAD_VBUF_SEG_SIZE_TOTAL )
              { /* wrap around necessary */
                lastIdx = (uint16)(curLvl - (SOAD_VBUF_SEG_SIZE_TOTAL -
                  SoAd_SockConIdx2RxMgt(soConIdx).BufSegMgt.Idx));
              }
              else
              { /* no wrap around necessary */
                lastIdx = SoAd_SockConIdx2RxMgt(soConIdx).BufSegMgt.Idx + curLvl;
              }

              /* call RxIndication again */
              /* PRQA S 3689 4 */ /* MD_SoAd_21.1 */
              SoAd_RxIndication(SoAd_SockIdx2SocketId(SoAd_SockCons(soConIdx).SockIdx),
                (SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(soConIdx),
                SoAd_SockConIdx2RxMgt(soConIdx).BufSegMgt.BufSegs[lastIdx].DataPtr,
                SoAd_SockConIdx2RxMgt(soConIdx).BufSegMgt.BufSegs[lastIdx].Len);

              if ( SoAd_SockConIdx2RxMgt(soConIdx).BufSegMgt.Lvl > 0u )
              { /* buffer still contains data so retry in next main function is required */
                addEventAgain = TRUE;
              }
            }
          }
          else
  # endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
          { /* UDP socket */
            PduLengthType bufferSize = 1u;

            /* UDP over TP has always a TP rx buffer - if no buffer is configured socket connection has no TP */
            if ( NULL_PTR != SoAd_SockConIdx2RxBuffer(soConIdx).TpRxBufferOffsetPtr )
            {
              if ( (0u < *SoAd_SockConIdx2RxBuffer(soConIdx).TpRxBufferOffsetPtr)
                && (SOAD_INV_PDU_ID != SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx) ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
              { /* active TP session and rx data are available */
                PduInfoType  pduInfo;
                uint16       routeIdx = SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx;

                pduInfo.SduDataPtr = NULL_PTR;
                pduInfo.SduLength  = 1u;

                /* copy data to upper layer */
                while ( (0u < bufferSize) && (0u < SoAd_SockConIdx2RxMgt(soConIdx).RxBytesPending) )
                {
                  if ( TRUE == SoAd_SockConIdx2RxMgt(soConIdx).CancelRequested )
                  { /* reception is canceled */
                    SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                    *SoAd_SockConIdx2RxBuffer(soConIdx).TpRxBufferOffsetPtr = 0u;
                    SoAd_SockConIdx2RxMgt(soConIdx).RxBytesPending = 0u;
                    SoAd_SockConIdx2RxMgt(soConIdx).CancelRequested = FALSE;
                    SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                    SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                    /* call TpRxIndication */
                    SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                      SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_NOT_OK);

                    /* close socket connection */
                    SoAd_SockConIdx2CloseMode(soConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                    /* set event to handle socket connection state in main function */
                    SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
                    break;
                  }
                  else
                  {
                    /* copy data to upper layer  */
                    if ( NULL_PTR == pduInfo.SduDataPtr )
                    { /* first call of CopyRxData */
                      pduInfo.SduLength = 0u;
                    }

                    /* call CopyRxData */
                    if ( BUFREQ_OK != SoAd_VCallTpCopyRxData(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                        SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId,
                        &pduInfo,
                        &bufferSize) )
                    { /* reception is not possible - close socket connection */
                      SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                      *SoAd_SockConIdx2RxBuffer(soConIdx).TpRxBufferOffsetPtr = 0u;
                      SoAd_SockConIdx2RxMgt(soConIdx).RxBytesPending = 0u;
                      SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx = SOAD_INV_PDU_ID; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
                      SoAd_SockConIdx2CloseMode(soConIdx) = SOAD_CLOSE_OFFLINE_RESET;
                      /* set event to handle socket connection state in main function */
                      SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
                      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                    }
                    else
                    { /* data segment copied successfully */
                      SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                      SoAd_SockConIdx2RxMgt(soConIdx).RxBytesPending -= pduInfo.SduLength;
                      if ( 0u == SoAd_SockConIdx2RxMgt(soConIdx).RxBytesPending )
                      { /* all data copied completely to upper layer - release rx buffer */
                        *SoAd_SockConIdx2RxBuffer(soConIdx).TpRxBufferOffsetPtr = 0u;
  # if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
                        if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
                        { /* PDU Header option is enabled */
                          /* if disabled TP session is finished on socket connection state change */
                          /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
                          SoAd_SockConIdx2RxMgt(soConIdx).RouteIdx = SOAD_INV_PDU_ID;
                          /* call TpRxIndication */
                          SoAd_VCallTpRxIndication(SoAd_SockRoutes(routeIdx).SockRouteDest.UpperLayerId,
                            SoAd_SockRoutes(routeIdx).SockRouteDest.RxPduId, E_OK);
                        }
  # endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
                      }
                      else
                      { /* pending PDU data */
                        if ( 0u < bufferSize )
                        { /* upper layer has buffer to copy data */
                          pduInfo.SduLength = SoAd_SockConIdx2RxMgt(soConIdx).RxBytesPending;
                          if ( pduInfo.SduLength > bufferSize )
                          {
                            pduInfo.SduLength = bufferSize;
                          }
                          pduInfo.SduDataPtr = &SoAd_SockConIdx2RxBuffer(soConIdx).TpRxBufferPtr[
                            *SoAd_SockConIdx2RxBuffer(soConIdx).TpRxBufferOffsetPtr -
                            SoAd_SockConIdx2RxMgt(soConIdx).RxBytesPending];
                        }
                        else
                        {
                          addEventAgain = TRUE;
                        }
                      }
                      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                    }
                  }
                }
              }
            }
          }
        }
      }

      if ( addEventAgain == TRUE )
      {
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTpRxSoCon(), handleIdx);
      }
    }
    else
    { /* no element left */
      break;
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */

#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
/**********************************************************************************************************************
 *  SoAd_VHandleTpAndTcpTransmission
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleTpAndTcpTransmission(void)
{
  uint16 handleIdx = SOAD_INV_SO_CON_IDX;
  SoAd_SoConIdxType lvl = (SoAd_SoConIdxType)SoAd_EventQueues(SoAd_EventQueueIdxTxSoCon()).EveMgtPtr->Lvl;
  SoAd_SoConIdxType_least idx;

# if ( SOAD_VEVE_QUE_LIMIT_TXSOCON_ENALBED == STD_ON )
  if ( lvl > SoAd_EventQueues(SoAd_EventQueueIdxTxSoCon()).EveQueLimit )
  {
    lvl = (SoAd_SoConIdxType)SoAd_EventQueues(SoAd_EventQueueIdxTxSoCon()).EveQueLimit;
  }
# endif /* SOAD_VEVE_QUE_LIMIT_TXSOCON_ENALBED == STD_ON */

  for ( idx = 0u; idx < lvl; idx++ )
  {
    if ( SoAd_VEventQueueGetNextElement(SoAd_EventQueueIdxTxSoCon(), &handleIdx) == E_OK )
    {
      SoAd_SoConIdxType soConIdx = (SoAd_SoConIdxType)handleIdx;

      SoAd_VHandleTpTransmissionInMain(soConIdx);

# if ( SOAD_VTCP_USED == STD_ON )
#  if ( SOAD_VSOCKET_BSD_API_ENABLED == STD_ON )
      /* handle pending TCP TxConfirmations for BSD Socket API (have to be simulated since BSD is polling based) */
      SoAd_VHandleTcpTxConfirmation(soConIdx);
#  endif /* SOAD_VSOCKET_BSD_API_ENABLED == STD_ON) */
# endif /* SOAD_VTCP_USED == STD_ON */
    }
    else
    { /* no element left */
      break;
    }
  }
}

/**********************************************************************************************************************
 *  SoAd_VHandleTpTransmissionInMain
 *********************************************************************************************************************/
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleTpTransmissionInMain(SoAd_SoConIdxType SoConIdx)
{
  SoAd_PduIdxType txPduIdx = SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx;

  if ( SOAD_INV_PDU_IDX != txPduIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
  { /* pending PDU transmission */
    if ( SOAD_UL_TYPE_TP == SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayer )
    { /* pending TP PDU transmission */
      /* check socket connection state */
      if ( (SOAD_SOCON_ONLINE == SoAd_SockConIdx2State(SoConIdx)) &&
        (SOAD_CLOSE_NONE == SoAd_SockConIdx2CloseMode(SoConIdx)) )
      { /* socket connection is online and not requested to be closed */
        /* handle TP cancellation */
        if ( TRUE == SoAd_SockConIdx2TxMgt(SoConIdx).CancelRequested )
        {
          /* reset TxMgt struct */
          SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
          SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = 0u;
          SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending = 0u;

#  if ( defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) )
          /* release SoAd local buffer */
          if ( SoAd_IsSockConIdx2TxBufferPresent() &&
            (NULL_PTR != SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr) )
          { /* buffer is available */
            *SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr = 0u;
          }
#  endif /* defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) */

#  if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
          /* free tx queue element if available */
          SoAd_VTcpTxQueueSetElement(SoConIdx, txPduIdx, 0u, TRUE);
#  endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */

          /* call TxConfirmation */
          SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
            SoAd_TxPduIdx2TxConfPduId(txPduIdx),
            E_NOT_OK);

          SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
          /* set event to handle socket connection state in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);

          SoAd_SockConIdx2TxMgt(SoConIdx).CancelRequested = FALSE;
        }
        else
        {
# if ( defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) )
          /* check whether a alive timeout is configured */
          if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr != NULL_PTR )
          {
            if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt != 0u )
            {
              uint32 currentTimeoutCnt = 0u;

              if ( SoAd_VTimeoutListGetCurrentTimeout(SoAd_TimeoutListIdxUdpAlive(), SoConIdx, &currentTimeoutCnt,
                  SoAd_GlobalCounter) == E_OK )
              { /* opened by a reception */
                /* set new timeout */
                /* return value has not to be considered since timeout ist already in list */
                (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxUdpAlive(), SoConIdx,
                  SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketUdpPtr->AliveTimeoutMaxCnt, SoAd_GlobalCounter);
              }
            }
          }
# endif /* defined(SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) && (STD_ON == SOAD_VUDP_ALIVE_TIMEOUT_ENALBED) */
          (void)SoAd_VHandleTpTransmissionOnSockCon(SoConIdx, TRUE);
        }
      }
    }
  }
}
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VHandleTpTransmissionOnSockCon
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 0771 SoAd_146 */ /* MD_SoAd_14.6 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VHandleTpTransmissionOnSockCon(SoAd_SoConIdxType SoConIdx,
                      boolean CalledByMain)
{
  Std_ReturnType  retVal = E_OK;
  PduLengthType   availableBufLen = 1u;
  SoAd_PduIdxType txPduIdx = SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx;

  while ( (0u < availableBufLen) && (0u != SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending) )
  {
    PduInfoType pduInfo;

    /* query available data from upper layer */
    pduInfo.SduDataPtr = NULL_PTR;
    pduInfo.SduLength = 0u;

    /* call TpCopyTxData */
    if ( BUFREQ_OK == SoAd_VCallTpCopyTxData(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
        SoAd_TxPduIdx2TxConfPduId(txPduIdx), &pduInfo, &availableBufLen) )
    {
      if ( 0u < availableBufLen )
      { /* data are available */
        PduLengthType maxExpectedBufLen = SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending;
# if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
        PduLengthType pduHdrRestLen = 0u;

        if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
        { /* PDU header enabled */
          /* calculate remaining PDU header length */
          pduHdrRestLen = SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen -
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending;

          if ( SOAD_PDU_HDR_SIZE < pduHdrRestLen )
          {
            pduHdrRestLen = 0u;
          }
          else
          {
            pduHdrRestLen = SOAD_PDU_HDR_SIZE - pduHdrRestLen;
          }

          /* maximum expected available buffer length does not contain PDU header */
          maxExpectedBufLen -= pduHdrRestLen;
        }
# endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */

        if ( maxExpectedBufLen < availableBufLen )
        { /* available buffer length is greater than expected */
          availableBufLen = maxExpectedBufLen;
        }

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
        if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP )
        { /* TCP socket */
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
          if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
          { /* PDU header enabled */
            /* add PDU header to availableBufLen if not sent yet */
            pduHdrRestLen = SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen -
              SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending;

            if ( SOAD_PDU_HDR_SIZE < pduHdrRestLen )
            {
              pduHdrRestLen = 0u;
            }
            else
            {
              pduHdrRestLen = SOAD_PDU_HDR_SIZE - pduHdrRestLen;
            }
          }

          /* transmit data over TCP */
          if ( E_OK != SoAd_VTcpIpTransmit(SoAd_SockIdx2SocketId(SoAd_SockCons(SoConIdx).SockIdx),
              (availableBufLen + pduHdrRestLen)) )
#  else
          if ( E_OK != SoAd_VTcpIpTransmit(SoAd_SockIdx2SocketId(SoAd_SockCons(SoConIdx).SockIdx),
              availableBufLen) )
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
          { /* transmission failed */
#  if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
            /* retry until data could be sent or socket is closed */
            /* set event to handle TP transmission in main function */
            SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTxSoCon(), SoConIdx);
            break;
#  else
            /* reset TxMgt struct */
            SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = 0u;
            SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending = 0u;

            /* reset local socket index to active socket connection mapping */
            SoAd_SockIdx2ActiveSoConIdx(SoAd_SockCons(SoConIdx).SockIdx) = SOAD_INV_SO_CON_IDX;

            if ( SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen !=
              SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending )
            { /* transmission is already active */
              /* close socket connection in next MainFunction */
              SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
              /* set event to handle socket connection state in main function */
              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
            }
            else
            { /* failed at beginning and no data has been sent before */
              /* free tx queue element */
              SoAd_VTcpTxQueueSetElement(SoConIdx, txPduIdx, 0u, TRUE);
            }

            retVal = E_NOT_OK;

            if ( CalledByMain == TRUE )
            {
              /* call upper layer TxConfirmation */
              SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                SoAd_TxPduIdx2TxConfPduId(txPduIdx), E_NOT_OK);
            }
#  endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
          }
          else
          { /* call to TcpIp successful */
#  if ( SOAD_VSOCKET_BSD_API_ENABLED == STD_ON )
            /* set event to handle socket in main function */
            SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTxSoCon(), SoConIdx);
#  endif /* SOAD_VSOCKET_BSD_API_ENABLED == STD_ON */

            if ( 0u == SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending )
            { /* transmission finished */
              if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->ImmedTpTxConf == TRUE )
              {
                /* reset TxMgt struct */
                /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
                SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = SOAD_INV_PDU_IDX;
                SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = 0u;

                /* reset local socket index to active socket connection mapping */
                SoAd_SockIdx2ActiveSoConIdx(SoAd_SockCons(SoConIdx).SockIdx) = SOAD_INV_SO_CON_IDX;

                /* socket connecion handling if automatic setup is enabled and wildcards configured */
                if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SockAutoSoConSetup == TRUE )
                {
                  if ( (SOAD_SOCON_IP_ANY_PORT_ANY >= SoAd_SockConIdx2RemAddrState(SoConIdx)) &&
                    (0u != (SoAd_SockCons(SoConIdx).RemAddrState & SOAD_SOCON_MASK_ANY)) )
                  {
                    SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_RECONNECT;
                  }
                }

                /* call upper layer TxConfirmation (this is MainFunction context - no need to wait) */
                SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                  SoAd_TxPduIdx2TxConfPduId(txPduIdx), E_OK);
              }
            }
          }
        }
        else
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
        { /* UDP socket */
# if ( defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) )
          if ( SoAd_IsSockConIdx2TxBufferPresent() )
          {
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
            if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
            { /* PDU header enabled */
              if ( 0u == *SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr )
              { /* PDU header not yet copied to SoAd local buffer */
                /* copy PDU header first */
                SoAd_VCopyPduHdr2Buf(SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListPtr[0]->TxPduHdrId,
                  (SoAd_PduHdrLenType)(SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen - SOAD_PDU_HDR_SIZE),
                  &SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferPtr[0],
                  0u, SOAD_PDU_HDR_SIZE);
                *SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr = SOAD_PDU_HDR_SIZE;
              }
            }
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
            while ( 0u < availableBufLen )
            { /* copy upper layer data to local buffer until no buffer is available or PDU is copied */
              /* set pduInfo */
              pduInfo.SduDataPtr = &SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferPtr[
                *SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr];
              pduInfo.SduLength = availableBufLen;

              if ( BUFREQ_OK == SoAd_VCallTpCopyTxData(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                  SoAd_TxPduIdx2TxConfPduId(txPduIdx), &pduInfo, &availableBufLen) )
              {
                *SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr += (uint16)pduInfo.SduLength;

                if ( *SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr ==
                  SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen )
                { /* PDU copied completely to local buffer */
                  SoAd_SockConIdx2TxMgt(SoConIdx).TxBufPtr =
                    &SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferPtr[0];
                    /* transmit PDU over UDP */
                  if ( E_OK != SoAd_VTcpIpUdpTransmit(SoAd_SockCons(SoConIdx).SockIdx,
                      SoAd_SockIdx2SocketId(SoAd_SockCons(SoConIdx).SockIdx),
                      (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&SoAd_SockConIdx2RemSockDyn(SoConIdx),
                      (uint16)SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen) )
                  {
                    retVal = E_NOT_OK;
                  }

                  /* release local Tx buffer */
                  *SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr = 0u;

                  /* reset TxMgt struct */
                  /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
                  SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = SOAD_INV_PDU_IDX;
                  SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = 0u;
                  SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending = 0u;

                  /* reset local socket index to active socket connection mapping */
                  SoAd_SockIdx2ActiveSoConIdx(SoAd_SockCons(SoConIdx).SockIdx) = SOAD_INV_SO_CON_IDX;

                  if ( E_OK != retVal )
                  {
                    if ( CalledByMain == TRUE )
                    {
                      /* call negative TxConfirmation */
                      SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                        SoAd_TxPduIdx2TxConfPduId(txPduIdx), E_NOT_OK);
                    }
                  }
                  else
                  {
                    /* socket connecion handling if automatic setup is enabled and wildcards configured */
                    SoAd_VReconnectSockCon(SoConIdx);
                    /* call positive TxConfirmation */
                    SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                      SoAd_TxPduIdx2TxConfPduId(txPduIdx), E_OK);
                  }
                  break;
                }
                else
                { /* PDU not copied completely to local buffer */
                  if ( availableBufLen == 0u )
                  { /* no buffer available anymore */
                    /* set event to handle TP transmission in main function */
                    SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTxSoCon(), SoConIdx);
                  }
                }
              }
              else
              { /* call to upper layer failed */
                /* release local Tx buffer */
                *SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr = 0u;

                /* reset TxMgt struct */
                /* PRQA S 0277 1 */ /* MD_SoAd_3.1 */
                SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = SOAD_INV_PDU_IDX;
                SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = 0u;
                SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending = 0u;

                /* reset local socket index to active socket connection mapping */
                SoAd_SockIdx2ActiveSoConIdx(SoAd_SockCons(SoConIdx).SockIdx) = SOAD_INV_SO_CON_IDX;

                retVal = E_NOT_OK;

                if ( CalledByMain == TRUE )
                {
                  /* call negative TxConfirmation */
                  SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                    SoAd_TxPduIdx2TxConfPduId(txPduIdx), E_NOT_OK);
                }

                break;
              }
            }
          }
# endif /* defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) */
        }
      }
      else
      {
        /* set event to handle TP transmission in main function */
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxTxSoCon(), SoConIdx);
      }
    }
    else
    { /* call to upper layer failed */
      retVal = E_NOT_OK;
# if ( SOAD_VTCP_USED == STD_ON )
      if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP )
      { /* TCP */
        /* close socket in next MainFunction in case of TCP */
        SoAd_SockConIdx2CloseMode(SoConIdx) = SOAD_CLOSE_OFFLINE_RESET;
        /* set event to handle socket connection state in main function */
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), SoConIdx);
      }
# endif /* SOAD_VTCP_USED == STD_ON */
# if ( defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) )
#  if ( SOAD_VTCP_USED == STD_ON )
      else
#  endif /* SOAD_VTCP_USED == STD_ON */
      { /* UDP */
        if ( SoAd_IsSockConIdx2TxBufferPresent() )
        {
          /* release local Tx buffer */
          *SoAd_SockConIdx2TxBuffer(SoConIdx).TpTxBufferOffsetPtr = 0u;

          /* reset TxMgt struct */
          SoAd_SockConIdx2TxMgt(SoConIdx).TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
          SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesLen = 0u;
          SoAd_SockConIdx2TxMgt(SoConIdx).TxBytesPending = 0u;

          /* reset local socket index to active socket connection mapping */
          SoAd_SockIdx2ActiveSoConIdx(SoAd_SockCons(SoConIdx).SockIdx) = SOAD_INV_SO_CON_IDX;

          if ( CalledByMain == TRUE )
          {
            /* call negative TxConfirmation */
            SoAd_VCallTpTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
              SoAd_TxPduIdx2TxConfPduId(txPduIdx), E_NOT_OK);
          }
        }
      }
# endif /* defined(SOAD_VTX_BUF_ENABLED) && (STD_ON == SOAD_VTX_BUF_ENABLED) */
      break;
    }
  }

# if ( (SOAD_VTCP_USED == STD_OFF) && (SOAD_VTX_BUF_ENABLED == STD_OFF) )
  SOAD_DUMMY_STATEMENT_VAR(CalledByMain); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif /* (SOAD_VTCP_USED == STD_OFF) && (SOAD_VTX_BUF_ENABLED == STD_OFF) */

  return retVal;
}
/* PRQA L:MSR_11715 */
/* PRQA L:SoAd_146 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */

#if ( defined(SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) && (STD_ON == SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VHandleIfRouteGrpTransmit
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleIfRouteGrpTransmit(void)
{
  uint16 handleIdx = SOAD_INV_ROUT_GRP_IDX;
  SoAd_RoutingGroupIdxType lvl = (SoAd_RoutingGroupIdxType)
    SoAd_EventQueues(SoAd_EventQueueIdxIfTxRouteGrp()).EveMgtPtr->Lvl;
  SoAd_RoutingGroupIdxType_least idx;

# if ( SOAD_VEVE_QUE_LIMIT_IFTXROUTGRP_ENALBED == STD_ON )
  if ( lvl > SoAd_EventQueues(SoAd_EventQueueIdxIfTxRouteGrp()).EveQueLimit )
  {
    lvl = (SoAd_RoutingGroupIdxType)SoAd_EventQueues(SoAd_EventQueueIdxIfTxRouteGrp()).EveQueLimit;
  }
# endif /* SOAD_VEVE_QUE_LIMIT_IFTXROUTGRP_ENALBED == STD_ON */

  for ( idx = 0u; idx < lvl; idx++ )
  {
    if ( SoAd_VEventQueueGetNextElement(SoAd_EventQueueIdxIfTxRouteGrp(), &handleIdx) == E_OK )
    {
      SoAd_RoutingGroupIdxType  routGrpIdx = (SoAd_RoutingGroupIdxType)handleIdx;
      PduInfoType               info;
      uint16                    pduRouteDestNum = 0u;
      PduIdType                 txPduId = SOAD_INV_PDU_ID;
      Std_ReturnType            retVal = E_OK;

      /* initialize struct here to prevent compiler warnings */
      info.SduDataPtr = SoAd_IfRouteGrpTransmitBufPtr();
      info.SduLength  = SoAd_IfRouteGrpTransmitBufSize();

      /* iterate over all referenced PduRouteDests */
      while ( SoAd_RouteGrpIdx2PduRouteDestCol(routGrpIdx).PduRouteDestListSize > pduRouteDestNum )
      {
        SOAD_P2CONST(SoAd_PduRouteDestType) pduRouteDestPtr =
          SoAd_RouteGrpIdx2PduRouteDestCol(routGrpIdx).PduRouteDestListPtr[pduRouteDestNum];

        if ( 0u != (*SoAd_RouteGrpIdx2PduRouteDestCol(routGrpIdx).StateColPtr[pduRouteDestNum] &
          SOAD_ROUT_GRP_BIT_PATTERN_TRIGGER) )
        { /* trigger transmit is enabled for this PduRouteDest */
          SoAd_PduIdxType txPduIdx = SoAd_TxPduId2PduRouteIdx(pduRouteDestPtr->TxPduId);

# if ( (SOAD_VTX_DYN_LEN_ENABLED == STD_ON) && (SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON) )
          if ( SoAd_TxPduIdx2PduRoute(txPduIdx).IfTriggerTransmitEnabled == TRUE )
          { /* normal PDU transmission request as trigger transmit */
            /* transmission in context of CopyTxData */
            info.SduDataPtr = NULL_PTR;
            info.SduLength = SoAd_MaxIfRouteGrpTransmitPduSize();

            (void)SoAd_VIfTransmit(pduRouteDestPtr->SoConIdx, &info, pduRouteDestPtr);
          }
          else
# endif /* (SOAD_VTX_DYN_LEN_ENABLED == STD_ON) && (SOAD_VIF_TRIGGER_TRANSMIT_ENABLED == STD_ON) */
          { /* normal PDU transmission request as direct transmit */
            /* use buffer and call trigger transmit now */
            if ( pduRouteDestPtr->TxPduId == txPduId )
            { /* trigger transmit is already called for the corresponding PduRoute */
              if ( E_NOT_OK != retVal )
              { /* call to upper layer was successful */
                /* send data info parameter pointing to */
                (void)SoAd_VIfTransmit(pduRouteDestPtr->SoConIdx, &info, pduRouteDestPtr);
              }
            }
            else
            { /* retrieve data from upper layer */
              info.SduDataPtr = SoAd_IfRouteGrpTransmitBufPtr();
              info.SduLength  = SoAd_IfRouteGrpTransmitBufSize();
              retVal = E_NOT_OK;
              txPduId = pduRouteDestPtr->TxPduId;

              if ( E_OK == SoAd_VCallIfTriggerTransmit(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                SoAd_TxPduIdx2TxConfPduId(txPduIdx), &info) )
              { /* trigger transmit function call to upper layer successful */
                /* check info parameter */
                if ( (info.SduDataPtr != NULL_PTR) && (info.SduLength != 0) &&
                  (info.SduLength <= SoAd_IfRouteGrpTransmitBufSize()) )
                { /* send data info parameter pointing to */
                  (void)SoAd_VIfTransmit(pduRouteDestPtr->SoConIdx, &info, pduRouteDestPtr);
                  retVal = E_OK;
                }
              }
            }
          }
          /* reset trigger transmit flag later since multiple PduRouteDests of this RoutingGroup may reference the
            * same socket connection */
        }
        pduRouteDestNum++;
      }

      /* reset trigger transmit flags */
      pduRouteDestNum = 0u;
      while ( SoAd_RouteGrpIdx2PduRouteDestCol(routGrpIdx).PduRouteDestListSize > pduRouteDestNum )
      {
        /* PRQA S 0277 2 */ /* MD_SoAd_3.1 */
        *SoAd_RouteGrpIdx2PduRouteDestCol(routGrpIdx).StateColPtr[pduRouteDestNum] &=
          (uint8)(~SOAD_ROUT_GRP_BIT_PATTERN_TRIGGER);
        pduRouteDestNum++;
      }
    }
    else
    { /* no element left */
      break;
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
#endif /* defined(SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) && (STD_ON == SOAD_VIF_ROUT_GROUP_TRANSMIT_ENABLED) */

#if ( SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON )
/**********************************************************************************************************************
 *  SoAd_VHandleNPduUdpTx
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleNPduUdpTx(void)
{
  uint16 elementIdx = 0u;
  uint16 handleIdx = SOAD_INV_HND_16;

  while ( SoAd_VTimeoutListCheckElements(SoAd_TimeoutListIdxNPduUdpTx(),
      &elementIdx, &handleIdx, SoAd_GlobalCounter) == E_OK )
  { /* timout occured */
    uint16 nPduUdpTxIdx = handleIdx;

    /* handle timeout */

    /* start transmission if not already active */
    if ( SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TransmissionActive == FALSE )
    {
      SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TransmissionActive = TRUE;
# if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
      if ( SoAd_NPduUdpTx(nPduUdpTxIdx).QueueMgtPtr != NULL_PTR )
      {
        SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->RetryCnt = SOAD_VN_PDU_UDP_TX_QUEUE_RETRY_CNT_MAIN;
      }
# endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
    }

    /* handle transmission */
# if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
    if ( SoAd_NPduUdpTx(nPduUdpTxIdx).QueueMgtPtr != NULL_PTR )
    {
      SoAd_VNPduQueueSend(nPduUdpTxIdx);
    }
#  if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
    else
#  endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
# endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
# if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
    {
      SoAd_VNPduBufSend(nPduUdpTxIdx);
    }
# endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */

    /* handling dependent of transmission state */
    if ( SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TransmissionActive == FALSE )
    { /* transmission finished or aborted */
      /* remove element from list */
      SoAd_VTimeoutListRemoveElement(SoAd_TimeoutListIdxNPduUdpTx(), handleIdx);
    }
    else
    { /* transmission pending */
      /* update element to retry in next main function */
      (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), handleIdx, 1u, SoAd_GlobalCounter);
    }
  }
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VNPduClear
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VNPduClear(uint16 NPduUdpTxIdx)
{
  SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen = 0u;
  SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TransmissionActive = FALSE;

  SoAd_VTimeoutListRemoveElement(SoAd_TimeoutListIdxNPduUdpTx(), NPduUdpTxIdx);

# if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
  if ( SoAd_NPduUdpTx(NPduUdpTxIdx).QueueMgtPtr != NULL_PTR )
  {
    uint8 idx;
    uint8 queueSize = SoAd_SockCons(
      SoAd_NPduUdpTx(NPduUdpTxIdx).SoConIdx).SockConGrpPtr->SocketUdpPtr->NPduUdpTxQueueSize;

    SoAd_NPduUdpTx(NPduUdpTxIdx).QueueMgtPtr->Lvl = 0u;
    for ( idx = 0u; idx < queueSize; idx++ )
    {
      SoAd_PduIdxType txPduIdx = SoAd_NPduUdpTx(NPduUdpTxIdx).QueuePtr[idx].TxPduIdx;

      if ( txPduIdx != SOAD_INV_PDU_IDX )
      {
        /* handle TxConfirmation */
        if ( SoAd_TxPduIdx2PduRoute(txPduIdx).TxConfEnabled == TRUE )
        { /* TxConfirmation is configured for the corresponding upper layer and PDU */
          SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          if ( 0u < (SoAd_TxPduIdx2PendingTxConf(txPduIdx) & SOAD_TX_CONF_STRAT_BIT_PAT_CONF) )
          {
            /* there is a pending TxConfirmation for one of the PduRouteDests */
            SoAd_TxPduIdx2PendingTxConf(txPduIdx)--;
            if ( 0u == SoAd_TxPduIdx2PendingTxConf(txPduIdx) )
            { /* call TxConfirmation of upper layer only if all PduRouteDests are confirmed (PDU fan-out) */
              SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
              /* call TxConfirmation of upper layer */
              SoAd_VCallIfTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                SoAd_TxPduIdx2TxConfPduId(txPduIdx));
            }
            else
            {
              SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            }
          }
          else
          {
            SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          }
        }
      }

#  if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
      SoAd_NPduUdpTx(NPduUdpTxIdx).QueuePtr[idx].BufIdx = 0u;
#  endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
      SoAd_NPduUdpTx(NPduUdpTxIdx).QueuePtr[idx].Copied = FALSE;
      SoAd_NPduUdpTx(NPduUdpTxIdx).QueuePtr[idx].Len = 0u;
      SoAd_NPduUdpTx(NPduUdpTxIdx).QueuePtr[idx].TxPduIdx = SOAD_INV_PDU_IDX;
    }
  }
# endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */
# if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
  if ( SoAd_NPduUdpTx(NPduUdpTxIdx).BufMgtPtr != NULL_PTR )
  {
    SoAd_NPduUdpTx(NPduUdpTxIdx).BufMgtPtr->Len = 0u;
  }
# endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
#endif /* SOAD_VN_PDU_UDP_TX_ENABLED == STD_ON */

#if ( SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON )
/**********************************************************************************************************************
 *  SoAd_VNPduQueueAddElement
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_VNPduQueueAddElement(SoAd_PduIdxType TxPduIdx,
                      P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_VAR) PduRouteDestPtr,
                      P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInforPtr)
{
  SoAd_NPduReturnType nPduRetVal = SOAD_NPDU_OK;
  SoAd_SoConIdxType soConIdx = PduRouteDestPtr->SoConIdx;
  PduLengthType dataLen = PduInforPtr->SduLength;
  uint16 nPduUdpTxIdx = SoAd_SockConIdx2NPduUdpTxIdx(soConIdx);
  boolean elementUpdated = FALSE;

  SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

# if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
  if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
  {
    dataLen += SOAD_PDU_HDR_SIZE;
  }
# endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */

  /* check if PDU is already in queue */
# if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
  if ( SoAd_TxPduIdx2PduRoute(TxPduIdx).IfTriggerTransmitEnabled == TRUE )
# endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
  { /* data will be retrieved via trigger transmit */
    uint8 idx;

    for ( idx = 0u; idx < SoAd_NPduUdpTx(nPduUdpTxIdx).QueueMgtPtr->Lvl; idx++ )
    {
      if ( SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].TxPduIdx == TxPduIdx )
      { /* PDU is already in queue */
        if ( dataLen != SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Len )
        { /* different length */
          /* update */
          SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TotalLen -= SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Len;
          SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[idx].Len = dataLen;
          SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TotalLen += dataLen;

          /* check size after update */
          if ( SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TotalLen >
            SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->NPduUdpTxBufferMin )
          { /* maximum NPdu size exceeded */
            nPduRetVal = SOAD_NPDU_OVFL_UPDATE;
          }
          elementUpdated = TRUE;
        }
        break;
      }
    }
  }

  if ( elementUpdated == FALSE )
  { /* new PDU */
    if ( SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TransmissionActive == FALSE )
    { /* nPdu transmission is not ongoing */
      /* check queue size */
      if ( SoAd_NPduUdpTx(nPduUdpTxIdx).QueueMgtPtr->Lvl <
        SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->NPduUdpTxQueueSize )
      {
        /* check size */
        if ( (SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TotalLen + dataLen) <=
          SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->NPduUdpTxBufferMin )
        { /* NPdu size is sufficient for new request */
          Std_ReturnType retVal = E_OK;

          /* check and restart UDP trigger timer if necessary */
          if ( PduRouteDestPtr->UdpTriggerTimeout > 0u  )
          { /* PduRouteDest specific timeout is configured */
            uint32 currentTimeoutCnt = 0u;

            if ( SoAd_VTimeoutListGetCurrentTimeout(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx, &currentTimeoutCnt,
              SoAd_GlobalCounter) == E_OK )
            { /* timer is already in list */
              /* check timer value */
              if ( PduRouteDestPtr->UdpTriggerTimeout < currentTimeoutCnt )
              { /* current timer value is bigger than configured value */
                /* update timeout */
                (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx,
                  PduRouteDestPtr->UdpTriggerTimeout, SoAd_GlobalCounter);
              }
            }
            else
            { /* timer is not set */
              retVal = SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx,
                PduRouteDestPtr->UdpTriggerTimeout, SoAd_GlobalCounter);
            }
          }
          else if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpTriggerTimeout > 0u )
          { /* socket connection specific timeout is configured */
            uint32 currentTimeoutCnt = 0u;

            if ( SoAd_VTimeoutListGetCurrentTimeout(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx, &currentTimeoutCnt,
              SoAd_GlobalCounter) == E_OK )
            { /* timer is already in list */
              /* check timer value */
              if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpTriggerTimeout < currentTimeoutCnt )
              { /* current timer value is bigger than configured value */
                /* update timeout */
                (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx,
                  SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpTriggerTimeout, SoAd_GlobalCounter);
              }
            }
            else
            { /* timer is not set */
              retVal = SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx,
                SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpTriggerTimeout, SoAd_GlobalCounter);
            }
          }
          else
          { /* no timeout is configured */
            /* nothing to do */
          }

          if ( retVal == E_OK )
          {
            uint8 lvl = SoAd_NPduUdpTx(nPduUdpTxIdx).QueueMgtPtr->Lvl;

            /* store request */
            SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[lvl].Copied = FALSE;
            SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[lvl].Len = dataLen;
            SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[lvl].TxPduIdx = TxPduIdx;
            SoAd_NPduUdpTx(nPduUdpTxIdx).QueueMgtPtr->Lvl++;

# if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
            /* store data in buffer if TriggerTransmit is not enabled */
            if ( SoAd_TxPduIdx2PduRoute(TxPduIdx).IfTriggerTransmitEnabled == FALSE )
            { /* store in buffer */
              SoAd_NPduUdpTx(nPduUdpTxIdx).QueuePtr[lvl].BufIdx = SoAd_NPduUdpTx(nPduUdpTxIdx).BufMgtPtr->Len;

              (void)SoAd_VNPduBufAddElement(TxPduIdx, PduRouteDestPtr, PduInforPtr);
            }
            else
# endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
            {
              /* handle TxConfirmation */
              SoAd_VAddPendingIfTxConf(TxPduIdx, soConIdx);

              /* increment entire length */
              SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TotalLen += dataLen;
            }
          }
          else
          {
            nPduRetVal = SOAD_NPDU_NOT_OK;
          }
        }
        else
        {
          nPduRetVal = SOAD_NPDU_OVFL_NEW;
        }
      }
      else
      {
        nPduRetVal = SOAD_NPDU_OVFL_NEW;
      }
    }
    else
    {
      nPduRetVal = SOAD_NPDU_OVFL_NEW;
    }
  }

  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return nPduRetVal;
}
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VNPduQueueSend
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 0771 SoAd_146 */ /* MD_SoAd_14.6 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VNPduQueueSend(uint16 NPduUdpTxIdx)
{
  SoAd_SoConIdxType soConIdx = SoAd_NPduUdpTx(NPduUdpTxIdx).SoConIdx;
  SoAd_SockIdxType sockIdx = SoAd_SockCons(soConIdx).SockIdx;
  uint8 retryCnt;

  for ( retryCnt = 0u; retryCnt < SOAD_VN_PDU_UDP_TX_QUEUE_RETRY_CNT_DIRECT; retryCnt++ )
  { /* loop since PDUs may be larger than mentioned in transmission request and need to be splitted */
    SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if ( SOAD_INV_SO_CON_IDX == SoAd_SockIdx2ActiveSoConIdx(sockIdx) )
    {
      /* set nPdu to transmission state and handle retry counter */
      if ( SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TransmissionActive == TRUE )
      { /* transmission already active */
        if ( SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->RetryCnt > 0u )
        {
          SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->RetryCnt--;
        }
        if ( SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->RetryCnt == 0u )
        { /* retry limit reached */
          SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          /* clear queue to allow new transmissions */
          SoAd_VNPduClear(NPduUdpTxIdx);
          break;
        }
      }
      else
      { /* transmission not yet active */
        SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TransmissionActive = TRUE;
        SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->RetryCnt = SOAD_VN_PDU_UDP_TX_QUEUE_RETRY_CNT_MAIN;
      }

      /* set local socket index to active socket connection mapping */
      SoAd_SockIdx2ActiveSoConIdx(sockIdx) = soConIdx;
      /* set tx management struct for CopyTxData */
      SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx = 0u; /* set dummy PduId */
      if ( SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen >
        SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->NPduUdpTxBufferMin )
      {
        SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending =
          (PduLengthType)SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->NPduUdpTxBufferMin;
        SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen =
          (PduLengthType)SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->NPduUdpTxBufferMin;
      }
      else
      {
        SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending = (PduLengthType)SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen;
        SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen = (PduLengthType)SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen;
      }
      SoAd_SockConIdx2TxMgt(soConIdx).TxBufPtr = NULL_PTR;
      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* try to send nPdu */
      if ( SoAd_VTcpIpUdpTransmit(sockIdx, SoAd_SockIdx2SocketId(sockIdx),
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&SoAd_SockConIdx2RemSockDyn(soConIdx),
        (uint16)SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending) == E_OK )
      { /* transmission successful */
        uint8 idx;

        /* release sent queue element */
        for ( idx = 0u; idx < SoAd_NPduUdpTx(NPduUdpTxIdx).QueueMgtPtr->Lvl; idx++ )
        {
          SoAd_PduIdxType txPduIdx = SoAd_NPduUdpTx(NPduUdpTxIdx).QueuePtr[idx].TxPduIdx;

          if ( txPduIdx != SOAD_INV_PDU_IDX )
          {
            if ( SoAd_NPduUdpTx(NPduUdpTxIdx).QueuePtr[idx].Copied == TRUE )
            {
# if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
              if ( SoAd_TxPduIdx2PduRoute(txPduIdx).IfTriggerTransmitEnabled == TRUE )
# endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */
              {
                /* handle TxConfirmation */
                if ( SoAd_TxPduIdx2PduRoute(txPduIdx).TxConfEnabled == TRUE )
                { /* TxConfirmation is configured for the corresponding upper layer and PDU */
                  SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                  if ( 0u < (SoAd_TxPduIdx2PendingTxConf(txPduIdx) & SOAD_TX_CONF_STRAT_BIT_PAT_CONF) )
                  {
                    /* there is a pending TxConfirmation for one of the PduRouteDests */
                    SoAd_TxPduIdx2PendingTxConf(txPduIdx)--;
                    if ( 0u == SoAd_TxPduIdx2PendingTxConf(txPduIdx) )
                    { /* call TxConfirmation of upper layer only if all PduRouteDests are confirmed (PDU fan-out) */
                      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                      /* socket connecion handling if automatic setup is enabled and wildcards configured */
                      if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SockAutoSoConSetup == TRUE )
                      {
                        if ( (SOAD_SOCON_IP_ANY_PORT_ANY >= SoAd_SockConIdx2RemAddrState(soConIdx)) &&
                          (0u != (SoAd_SockCons(soConIdx).RemAddrState & SOAD_SOCON_MASK_ANY)) )
                        {
                          SoAd_SockConIdx2CloseMode(soConIdx) = SOAD_CLOSE_RECONNECT;
                          /* set event to handle socket connection state in main function */
                          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxStateSoCon(), soConIdx);
                        }
                      }
                      /* call TxConfirmation of upper layer */
                      SoAd_VCallIfTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                        SoAd_TxPduIdx2TxConfPduId(txPduIdx));
                    }
                    else
                    {
                      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                    }
                  }
                  else
                  {
                    SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                  }
                }
              }

              /* release queue element */
              SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen -= SoAd_NPduUdpTx(NPduUdpTxIdx).QueuePtr[idx].Len;
              SoAd_NPduUdpTx(NPduUdpTxIdx).QueuePtr[idx].TxPduIdx = SOAD_INV_PDU_IDX;
            }
            else
            { /* first PDU which could not be copied anymore */
              break;
            }
          }
        }

        /* reset tx management struct */
        SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */

        /* reset local socket index to active socket connection mapping */
        SoAd_SockIdx2ActiveSoConIdx(sockIdx) = SOAD_INV_SO_CON_IDX;

        if ( SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen == 0u )
        { /* nPduQueue sent completely */
          SoAd_NPduUdpTx(NPduUdpTxIdx).QueueMgtPtr->Lvl = 0u;
          /* remove timeout from list */
          SoAd_VTimeoutListRemoveElement(SoAd_TimeoutListIdxNPduUdpTx(), NPduUdpTxIdx);
          /* transmission of nPdu finished */
          SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TransmissionActive = FALSE;
          break;
        }
      }
      else
      { /* transmission failed */
        /* reset tx management struct */
        SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */

        /* reset local socket index to active socket connection mapping */
        SoAd_SockIdx2ActiveSoConIdx(sockIdx) = SOAD_INV_SO_CON_IDX;

        /* set timeout to retry in next main function */
        (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), NPduUdpTxIdx, 1u, SoAd_GlobalCounter);

        /* break here since retry in this context shall only be done if nPdu is larger than provided TcpIp buffer */
        break;
      }
    }
    else
    {
      SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      break;
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:SoAd_146 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */
#endif /* SOAD_VN_PDU_UDP_TX_QUEUE_ENABLED == STD_ON */

# if ( SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON )
/**********************************************************************************************************************
 *  SoAd_VNPduBufAddElement
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_VNPduBufAddElement(SoAd_PduIdxType TxPduIdx,
                      P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_VAR) PduRouteDestPtr,
                      P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInforPtr)
{
  SoAd_NPduReturnType nPduRetVal = SOAD_NPDU_NOT_OK;
  SoAd_SoConIdxType soConIdx = PduRouteDestPtr->SoConIdx;
  PduLengthType dataLen = PduInforPtr->SduLength;
  uint16 nPduUdpTxIdx = SoAd_SockConIdx2NPduUdpTxIdx(soConIdx);

  SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if ( SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TransmissionActive == FALSE )
  { /* nPdu transmission is not ongoing */
# if ( SOAD_VPDU_HDR_ENABLED == STD_ON )
    if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
    {
      dataLen += SOAD_PDU_HDR_SIZE;
    }
# endif /* SOAD_VPDU_HDR_ENABLED == STD_ON */

    if ( (SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TotalLen + dataLen) <=
      SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->NPduUdpTxBufferMin )
    { /* nPdu size is sufficient for new request */
      Std_ReturnType retVal = E_OK;

      /* check and restart UDP trigger timer if necessary */
      if ( PduRouteDestPtr->UdpTriggerTimeout > 0u  )
      { /* PduRouteDest specific timeout is configured */
        uint32 currentTimeoutCnt = 0u;

        if ( SoAd_VTimeoutListGetCurrentTimeout(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx, &currentTimeoutCnt,
          SoAd_GlobalCounter) == E_OK )
        { /* timer is already in list */
          /* check timer value */
          if ( PduRouteDestPtr->UdpTriggerTimeout < currentTimeoutCnt )
          { /* current timer value is bigger than configured value */
            /* update timeout */
            (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx,
              PduRouteDestPtr->UdpTriggerTimeout, SoAd_GlobalCounter);
          }
        }
        else
        { /* timer is not set */
          retVal = SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx,
            PduRouteDestPtr->UdpTriggerTimeout, SoAd_GlobalCounter);
        }
      }
      else if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpTriggerTimeout > 0u )
      { /* socket connection specific timeout is configured */
        uint32 currentTimeoutCnt = 0u;

        if ( SoAd_VTimeoutListGetCurrentTimeout(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx, &currentTimeoutCnt,
          SoAd_GlobalCounter) == E_OK )
        { /* timer is already in list */
          /* check timer value */
          if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpTriggerTimeout < currentTimeoutCnt )
          { /* current timer value is bigger than configured value */
            /* update timeout */
            (void)SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx,
              SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpTriggerTimeout, SoAd_GlobalCounter);
          }
        }
        else
        { /* timer is not set */
          retVal = SoAd_VTimeoutListSetElement(SoAd_TimeoutListIdxNPduUdpTx(), nPduUdpTxIdx,
            SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->UdpTriggerTimeout, SoAd_GlobalCounter);
        }
      }
      else
      { /* no timeout is configured */
        /* nothing to do */
      }

      if ( retVal == E_OK )
      {
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
        if ( SoAd_SockCons(soConIdx).SockConGrpPtr->PduHdrEnabled == TRUE )
        { /* PDU Header enabled - copy first */
          SoAd_VCopyPduHdr2Buf(PduRouteDestPtr->TxPduHdrId, PduInforPtr->SduLength,
            &SoAd_NPduUdpTx(nPduUdpTxIdx).BufPtr[SoAd_NPduUdpTx(nPduUdpTxIdx).BufMgtPtr->Len], 0u, SOAD_PDU_HDR_SIZE);
          SoAd_NPduUdpTx(nPduUdpTxIdx).BufMgtPtr->Len += SOAD_PDU_HDR_SIZE;
        }
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
        /* copy PDU */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))
            &SoAd_NPduUdpTx(nPduUdpTxIdx).BufPtr[SoAd_NPduUdpTx(nPduUdpTxIdx).BufMgtPtr->Len],
          (P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&PduInforPtr->SduDataPtr[0],
          PduInforPtr->SduLength);
        SoAd_NPduUdpTx(nPduUdpTxIdx).BufMgtPtr->Len += (uint16)PduInforPtr->SduLength;

        /* handle TxConfirmation */
        SoAd_VAddPendingIfTxConf(TxPduIdx, soConIdx);

        /* increment entire length */
        SoAd_NPduUdpTx(nPduUdpTxIdx).MgtPtr->TotalLen += dataLen;

        nPduRetVal = SOAD_NPDU_OK;
      }
    }
    else
    {
      nPduRetVal = SOAD_NPDU_OVFL_NEW;
    }
  }

  SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return nPduRetVal;
}
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VNPduBufSend
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VNPduBufSend(uint16 NPduUdpTxIdx)
{
  SoAd_SoConIdxType soConIdx = SoAd_NPduUdpTx(NPduUdpTxIdx).SoConIdx;
  SoAd_SockIdxType sockIdx = SoAd_SockCons(soConIdx).SockIdx;

  SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  if ( SOAD_INV_SO_CON_IDX == SoAd_SockIdx2ActiveSoConIdx(sockIdx) )
  {
    /* set nPdu to transmission state (may be already active) */
    SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TransmissionActive = TRUE;

    /* set local socket index to active socket connection mapping */
    SoAd_SockIdx2ActiveSoConIdx(sockIdx) = soConIdx;
    /* set tx management struct for CopyTxData */
    SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx = 0u; /* set dummy PduId */
    SoAd_SockConIdx2TxMgt(soConIdx).TxBytesPending = (PduLengthType)SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen;
    SoAd_SockConIdx2TxMgt(soConIdx).TxBytesLen = (PduLengthType)SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen;
    SoAd_SockConIdx2TxMgt(soConIdx).TxBufPtr = NULL_PTR;
    SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* try to send nPdu */
    if ( E_OK == SoAd_VTcpIpUdpTransmit(sockIdx, SoAd_SockIdx2SocketId(sockIdx),
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&SoAd_SockConIdx2RemSockDyn(soConIdx),
        (uint16)SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen) )
    { /* transmission successful */
      SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TotalLen = 0u;
      SoAd_NPduUdpTx(NPduUdpTxIdx).BufMgtPtr->Len = 0u;
      /* remove timeout from list */
      SoAd_VTimeoutListRemoveElement(SoAd_TimeoutListIdxNPduUdpTx(), NPduUdpTxIdx);
      /* transmission of nPdu finished */
      SoAd_NPduUdpTx(NPduUdpTxIdx).MgtPtr->TransmissionActive = FALSE;
    }

    /* reset tx management struct */
    SoAd_SockConIdx2TxMgt(soConIdx).TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */

    /* reset local socket index to active socket connection mapping */
    SoAd_SockIdx2ActiveSoConIdx(sockIdx) = SOAD_INV_SO_CON_IDX;
  }
  else
  {
    SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}
#endif /* SOAD_VN_PDU_UDP_TX_BUF_ENABLED == STD_ON */

#if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
#  if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VHandleTcpTxConfirmation
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleTcpTxConfirmation(SoAd_SoConIdxType SoConIdx)
{
  if ( SoAd_SockCons(SoConIdx).TcpTxQueuePtr != NULL_PTR )
  {
    P2CONST(SoAd_TcpTxQueueConfigType, AUTOMATIC, SOAD_APPL_VAR) qPtr = SoAd_SockCons(SoConIdx).TcpTxQueuePtr;

    while ( 0u < qPtr->MgtPtr->Lvl )
    {
      if ( SOAD_INV_PDU_IDX != qPtr->QueuePtr[qPtr->MgtPtr->Idx].TxPduIdx ) /* PRQA S 0277 */ /* MD_SoAd_3.1 */
      { /* found element */
        if ( 0u < qPtr->QueuePtr[qPtr->MgtPtr->Idx].Len )
        { /* queue entry contains data to be confirmed */
          SoAd_PduIdxType txPduIdx = qPtr->QueuePtr[qPtr->MgtPtr->Idx].TxPduIdx;

          qPtr->QueuePtr[qPtr->MgtPtr->Idx].Len = 0u;
          qPtr->QueuePtr[qPtr->MgtPtr->Idx].TxPduIdx = SOAD_INV_PDU_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
          qPtr->MgtPtr->Lvl--;
          if ( (qPtr->MgtPtr->Idx + 1u) == qPtr->Size)
          { /* wrap around */
            qPtr->MgtPtr->Idx = 0u;
          }
          else
          { /* no wrap around */
            qPtr->MgtPtr->Idx++;
          }

          SoAd_VTcpTxConfirmation(SoConIdx, txPduIdx);
        }
        else
        { /* queue entry has no length (is reserved by current transmission request) */
          break;
        }
      }
    }
  }
}
#  endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */

/**********************************************************************************************************************
 *  SoAd_VHandleTxConfirmation
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleTxConfirmation(void)
{
  uint16 handleIdx = SOAD_INV_PDU_IDX;
  SoAd_PduIdxType lvl = (SoAd_PduIdxType)SoAd_EventQueues(SoAd_EventQueueIdxIfUdpPduRoute()).EveMgtPtr->Lvl;
  SoAd_PduIdxType idx;

# if ( SOAD_VEVE_QUE_LIMIT_UDPPDUROUTE_ENALBED == STD_ON )
  if ( lvl > SoAd_EventQueues(SoAd_EventQueueIdxIfUdpPduRoute()).EveQueLimit )
  {
    lvl = (SoAd_PduIdxType)SoAd_EventQueues(SoAd_EventQueueIdxIfUdpPduRoute()).EveQueLimit;
  }
# endif /* SOAD_VEVE_QUE_LIMIT_UDPPDUROUTE_ENALBED == STD_ON */

  for ( idx = 0u; idx < lvl; idx++ )
  {
    if ( SoAd_VEventQueueGetNextElement(SoAd_EventQueueIdxIfUdpPduRoute(), &handleIdx) == E_OK )
    {
      SoAd_PduIdxType txPduIdx = (SoAd_PduIdxType)handleIdx;

      if ( 0u != (SoAd_TxPduIdx2PendingTxConf(txPduIdx) & SOAD_TX_CONF_STRAT_BIT_PAT_MAIN) )
      { /* TxConfirmation pending */
        /* IF-API only (TP TxConfirmation is handled directly after transmission or in SoAd_TxConfirmation context) */
        P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_VAR) pduRouteDestPtr =
          SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListPtr[0];
        uint16 pduRouteDestNum = SoAd_TxPduIdx2PduRoute(txPduIdx).PduRouteDestListSize;

        /* handle multiple PduRouteDests (PDU fan-out) */
        while ( 0u < pduRouteDestNum )
        {
          SoAd_SoConIdxType soConIdx = pduRouteDestPtr->SoConIdx;

          if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr != NULL_PTR )
          { /* UDP socket */
# if ( defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) )
            if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SocketUdpPtr->ImmedIfTxConf == FALSE )
# endif /* defined(SOAD_VUDP_IMMED_IF_TX_CONF) && (STD_ON == SOAD_VUDP_IMMED_IF_TX_CONF) */
            { /* TxConfirmation is handled in MainFunction context */
              SOAD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

              /* reset MainFunction bit */
              SoAd_TxPduIdx2PendingTxConf(txPduIdx) &= SOAD_TX_CONF_STRAT_BIT_PAT_CONF;
              if ( 0u == SoAd_TxPduIdx2PendingTxConf(txPduIdx) )
              { /* no TxConfirmation in SoAd_TxConfirmation context pending */
                SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

                /* socket connecion handling if automatic setup is enabled and wildcards configured */
                if ( SoAd_SockCons(soConIdx).SockConGrpPtr->SockAutoSoConSetup == TRUE )
                {
                  if ( (SOAD_SOCON_IP_ANY_PORT_ANY >= SoAd_SockConIdx2RemAddrState(soConIdx)) &&
                    (0u != (SoAd_SockCons(soConIdx).RemAddrState & SOAD_SOCON_MASK_ANY)) )
                  {
                    /* reset remote socket and reconnect socket connection */
                    SoAd_VResetIpAddr(soConIdx);
# if ( defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) )
                    if ( NULL_PTR != SoAd_SockCons(soConIdx).RcvRemSockPtr )
                    { /* get received remote address is supported */
                      /* reset remote address */
                      SoAd_VResetIpAddr2Unspec(SoAd_SockCons(soConIdx).RcvRemSockPtr);
                    }
# endif /* defined(SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) && (STD_ON == SOAD_VGET_RCV_REMOTE_ADDR_ENABLED) */
                    SoAd_SockConIdx2State(soConIdx) = SOAD_SOCON_RECONNECT;
                    /* inform upper layer about socket connection state change */
                    SoAd_VCallChgFunc(soConIdx, SoAd_SockCons(soConIdx).SoConChgFuncBitPattern,
                      SOAD_CHG_FUNC_TYPE_SOCONMODE, SoAd_SockConIdx2State(soConIdx));
                  }
                }

                /* call TxConfirmation */
                if ( TRUE == SoAd_TxPduIdx2PduRoute(txPduIdx).TxConfEnabled )
                { /* TxConfirmation is configured for the corresponding upper layer or PDU */
                  SoAd_VCallIfTxConfirmation(SoAd_TxPduIdx2PduRoute(txPduIdx).UpperLayerId,
                    SoAd_TxPduIdx2TxConfPduId(txPduIdx));
                }

                /* no pending TxConfirmation anymore - skip this PduRouteDest collection */
                break;
              }
              else
              { /* TxConfirmation in SoAd_TxConfirmation context pending */
                SOAD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                /* nothing to do */
              }
            }
          }
          else
          { /* TCP socket */
            /* TxConfirmation is always handled in SoAd_TxConfirmation context for IF-TCP connections */
          }
          pduRouteDestNum--;
          pduRouteDestPtr++; /* PRQA S 0489 */ /* MD_SoAd_17.4 */
        }
      }
    }
    else
    { /* no element left */
      break;
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
#endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VHandleSocketReception
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VHandleSocketReception(void)
{
  uint16 handleIdx = SOAD_INV_PDU_IDX;
  SoAd_SockIdxType lvl = (SoAd_SockIdxType)SoAd_EventQueues(SoAd_EventQueueIdxSockIdx()).EveMgtPtr->Lvl;
  SoAd_SockIdxType_least idx;

# if ( SOAD_VEVE_QUE_LIMIT_SOCKIDX_ENALBED == STD_ON )
  if ( lvl > SoAd_EventQueues(SoAd_EventQueueIdxSockIdx()).EveQueLimit )
  {
    lvl = (SoAd_PduIdxType)SoAd_EventQueues(SoAd_EventQueueIdxSockIdx()).EveQueLimit;
  }
# endif /* SOAD_VEVE_QUE_LIMIT_SOCKIDX_ENALBED == STD_ON */

  for ( idx = 0u; idx < lvl; idx++ )
  {
    if ( SoAd_VEventQueueGetNextElement(SoAd_EventQueueIdxSockIdx(), &handleIdx) == E_OK )
    {
      boolean addEventAgain = FALSE;
      SoAd_SockIdxType sockIdx = (SoAd_SockIdxType)handleIdx;

      if ( SOAD_SOCK_STATE_ESTABLISHED == SoAd_SockIdx2SockState(sockIdx) )
      { /* socket is ready to receive data */
        SoAd_SoConIdxType soConIdx = SoAd_SockIdx2SoConIdxCol(sockIdx).SoConIdxStart;
        SoAd_SocketIdType socketId = SoAd_SockIdx2SocketId(sockIdx);

        if ( SOAD_IPPROTO_UDP == SoAd_SockCons(soConIdx).SockConGrpPtr->Protocol )
        { /* UDP socket */
          SoAd_LocalAddrIdType addrId = SoAd_SockCons(soConIdx).SockConGrpPtr->LocIpAddrId;
          struct sockaddr_inX sockAddr;
          socklen_t addrLen = sizeof(sockAddr);
          ssize_t dataLen;

          /* receive from unicast address */
          dataLen = recvfrom(socketId, SoAd_SocketRxBuffer(), SoAd_SocketRxBufferSize(), 0,
            SOAD_A_P2VAR(struct sockaddr)&sockAddr, &addrLen);

          if ( 0 >= dataLen )
          { /* error */
            if ( ((EAGAIN == errno) || (EWOULDBLOCK == errno)) && (0 != dataLen) ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
            { /* no date received */
              addEventAgain = TRUE;
            }
            else
            {
              (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
            }
          }
          else
          { /* received data */
            SoAd_SockAddrInetXType remSockAddr;

            SoAd_VConvertBsdSockAddr2AsrSockAddr(SOAD_A_P2VAR(SoAd_SockAddrType)&remSockAddr,
              SOAD_A_P2CONST(struct sockaddr)&sockAddr);

            SoAd_RxIndication(socketId, SOAD_A_P2VAR(SoAd_SockAddrType)&remSockAddr, SoAd_SocketRxBuffer(), dataLen);

            addEventAgain = TRUE;
          }

          if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_UNICAST )
          { /* unicast local address needs additional UDP sockets to receive from broadcasts/multicasts */
            /* receive from directed broadcast/link-local address */
            if ( -1 != SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId )
            {
              dataLen = recvfrom(SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId, SoAd_SocketRxBuffer(),
                SoAd_SocketRxBufferSize(), 0, SOAD_A_P2VAR(struct sockaddr)&sockAddr, &addrLen);

              if ( 0 >= dataLen )
              { /* error */
                /* PRQA S 5119 1 */ /* MD_SoAd_20.5 */
                if ( ((EAGAIN == errno) || (EWOULDBLOCK == errno)) && (0 != dataLen) )
                { /* no date received */
                  addEventAgain = TRUE;
                }
                else
                {
                  (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
                }
              }
              else
              { /* received data */
                SoAd_SockAddrInetXType remSockAddr;

                SoAd_VConvertBsdSockAddr2AsrSockAddr(SOAD_A_P2VAR(SoAd_SockAddrType)&remSockAddr,
                  SOAD_A_P2CONST(struct sockaddr)&sockAddr);

                if ( E_NOT_OK == SoAd_VCompareIpAddr(SoAd_SockCons(soConIdx).SockConGrpPtr->Domain,
                    SOAD_A_P2CONST(SoAd_IpAddrType)remSockAddr.addr,
                    SOAD_A_P2CONST(SoAd_IpAddrType)SoAd_AddrId2LocalIpAddrDyn(addrId).addr) )
                { /* received from different address, not local address */
                  SoAd_RxIndication(socketId, SOAD_A_P2VAR(SoAd_SockAddrType)&remSockAddr, SoAd_SocketRxBuffer(),
                    dataLen);
                }

                addEventAgain = TRUE;
              }
            }

            /* receive from limited broadcast/node-local address */
            if ( -1 != SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId )
            {
              dataLen = recvfrom(SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, SoAd_SocketRxBuffer(),
                SoAd_SocketRxBufferSize(), 0, SOAD_A_P2VAR(struct sockaddr)&sockAddr, &addrLen);

              if ( 0 >= dataLen )
              { /* error */
                /* PRQA S 5119 1 */ /* MD_SoAd_20.5 */
                if ( ((EAGAIN == errno) || (EWOULDBLOCK == errno)) && (0 != dataLen) )
                { /* no date received */
                  addEventAgain = TRUE;
                }
                else
                {
                  (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
                }
              }
              else
              { /* received data */
                SoAd_SockAddrInetXType remSockAddr;

                SoAd_VConvertBsdSockAddr2AsrSockAddr(SOAD_A_P2VAR(SoAd_SockAddrType)&remSockAddr,
                  SOAD_A_P2CONST(struct sockaddr)&sockAddr);

                if ( E_NOT_OK == SoAd_VCompareIpAddr(SoAd_SockCons(soConIdx).SockConGrpPtr->Domain,
                    SOAD_A_P2CONST(SoAd_IpAddrType)remSockAddr.addr,
                    SOAD_A_P2CONST(SoAd_IpAddrType)SoAd_AddrId2LocalIpAddrDyn(addrId).addr) )
                { /* received from different address, not local address */
                  SoAd_RxIndication(socketId, SOAD_A_P2VAR(SoAd_SockAddrType)&remSockAddr, SoAd_SocketRxBuffer(),
                    dataLen);
                }

                addEventAgain = TRUE;
              }
            }
          }
        }
        else
        { /* TCP socket */
          if ( (SoAd_SockCons(soConIdx).SockConGrpPtr->SocketTcpPtr->TcpInitiate == TRUE) ||
            (SoAd_SockCons(soConIdx).SockConGrpPtr->GrpSockIdx != sockIdx) )
          { /* client or server data socket */
            if ( SoAd_SockIdx2RxMgt(sockIdx).Len != SoAd_SockIdx2RxBuf(sockIdx).MaxLen )
            { /* unused buffer available */
              ssize_t dataLen;
              ssize_t bufLen;
              ssize_t bufIdx;

              /* get unused buffer segment */
              if ( SoAd_SockIdx2RxBuf(sockIdx).MaxLen <= (SoAd_SockIdx2RxMgt(sockIdx).Offset +
                SoAd_SockIdx2RxMgt(sockIdx).Len) )
              { /* ring buffer wrap around */
                bufLen = SoAd_SockIdx2RxBuf(sockIdx).MaxLen - SoAd_SockIdx2RxMgt(sockIdx).Len;
                bufIdx = SoAd_SockIdx2RxMgt(sockIdx).Offset - bufLen;
              }
              else
              { /* no wrap around */
                bufLen = SoAd_SockIdx2RxBuf(sockIdx).MaxLen - (SoAd_SockIdx2RxMgt(sockIdx).Offset +
                  SoAd_SockIdx2RxMgt(sockIdx).Len);
                bufIdx = SoAd_SockIdx2RxMgt(sockIdx).Offset + SoAd_SockIdx2RxMgt(sockIdx).Len;
              }

              dataLen = recv(socketId, &SoAd_SockIdx2RxBuf(sockIdx).BufPtr[bufIdx], bufLen, 0);

              if ( 0 >= dataLen )
              { /* error */
                 /* PRQA S 5119 1 */ /* MD_SoAd_20.5 */
                if ( ((EAGAIN == errno) || (EWOULDBLOCK == errno)) && (0 != dataLen) )
                { /* no data received */
                  addEventAgain = TRUE;
                }
                else
                {
                  (void)SoAd_VTcpIpClose(socketId, TRUE, sockIdx, TRUE);
                }
              }
              else
              { /* received data */
                SoAd_SockIdx2RxMgt(sockIdx).Len += dataLen;

                SoAd_RxIndication(socketId, SOAD_A_P2VAR(SoAd_SockAddrType)&SoAd_SockConIdx2RemSockDyn(soConIdx),
                  &SoAd_SockIdx2RxBuf(sockIdx).BufPtr[bufIdx], dataLen);

                addEventAgain = TRUE;
              }
            }
          }
          else
          { /* server listen socket */
            /* add event to queue again to handle socket state in state main function */
            addEventAgain = TRUE;
          }
        }
      }
      else
      { /* socket is not established */
        /* add event to queue again to handle socket state in state main function */
        addEventAgain = TRUE;
      }
      if ( addEventAgain == TRUE )
      { /* add event again to queue */
        SoAd_VEventQueueAddElement(SoAd_EventQueueIdxSockIdx(), sockIdx);
      }
    }
    else
    { /* no element left */
      break;
    }
  }
}

/**********************************************************************************************************************
 *  SoAd_VTcpIpReceived
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VTcpIpReceived(SoAd_SocketIdType SocketId, uint32 Length)
{
  SoAd_SockIdxType sockIdx = SoAd_VGetSockIdxBySocketId(SocketId);

  if ( SoAd_SockIdx2RxMgt(sockIdx).Len < Length )
  { /* unxpected length */
    Length = SoAd_SockIdx2RxMgt(sockIdx).Len;
  }

  if ( (SoAd_SockIdx2RxMgt(sockIdx).Offset + Length) > SoAd_SockIdx2RxBuf(sockIdx).MaxLen )
  { /* ring buffer wrap around */
    SoAd_SockIdx2RxMgt(sockIdx).Offset -= SoAd_SockIdx2RxBuf(sockIdx).MaxLen - Length;
  }
  else
  { /* no wrap around */
    SoAd_SockIdx2RxMgt(sockIdx).Offset += Length;
  }

  SoAd_SockIdx2RxMgt(sockIdx).Len -= Length;
}

/**********************************************************************************************************************
 *  SoAd_VTcpIpGetSocket
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpIpGetSocket(SoAd_SockIdxType SockIdx,
                        SoAd_DomainType Domain,
                        SoAd_ProtocolType Protocol,
                        P2VAR(SoAd_SocketIdType, AUTOMATIC, SOAD_APPL_VAR) SocketIdPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  sint32 domain = AF_INET;
  sint32 type = SOCK_DGRAM;
  sint32 protocol = 0;
  sint32 retValSocket;

  if ( SOAD_AF_INET6 == Domain )
  {
    domain = AF_INET6;
  }

  if ( SOAD_IPPROTO_TCP == Protocol )
  { /* TCP */
    type = SOCK_STREAM;

    retValSocket = socket(domain, type, protocol);

    if ( -1 != retValSocket )
    {
      *SocketIdPtr = retValSocket;
      retVal = E_OK;
    }
    else
    {
      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
      SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_GET_SOCKET, SOAD_SOCK_BSD_API_SOCKET,
        SOAD_SOCK_BSD_PARAM_NONE, domain, type, errno);
    }
  }
  else
  { /* UDP */
    SoAd_SoConIdxType firstSoConIdx = SoAd_SockIdx2SoConIdxCol(SockIdx).SoConIdxStart;
    SoAd_LocalAddrIdType addrId = SoAd_SockCons(firstSoConIdx).SockConGrpPtr->LocIpAddrId;
    SoAd_SocketIdType dirLinkSocketId = -1;
    SoAd_SocketIdType limNodeSocketId = -1;
    *SocketIdPtr = -1;

    retVal = E_OK;

    /* get socket for unicast */
    *SocketIdPtr = socket(domain, type, protocol);
    if ( -1 == *SocketIdPtr )
    {
      retVal = E_NOT_OK;
      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
      SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_GET_SOCKET, SOAD_SOCK_BSD_API_SOCKET,
        SOAD_SOCK_BSD_PARAM_NONE, domain, type, errno);
    }

    if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_UNICAST )
    { /* unicast local address needs additional UDP sockets to receive from broadcasts/multicasts */
      /* get socket for directed broadcast/link-local multicast */
      if ( E_OK == retVal )
      {
        dirLinkSocketId = socket(domain, type, protocol);
        if ( -1 == dirLinkSocketId )
        {
          retVal = E_NOT_OK;
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_GET_SOCKET, SOAD_SOCK_BSD_API_SOCKET,
            SOAD_SOCK_BSD_PARAM_NONE, domain, type, errno);
        }
      }

      /* get socket for limited broadcast/node-local */
      if ( E_OK == retVal )
      {
        limNodeSocketId = socket(domain, type, protocol);
        if ( -1 == limNodeSocketId )
        {
          retVal = E_NOT_OK;
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_GET_SOCKET, SOAD_SOCK_BSD_API_SOCKET,
            SOAD_SOCK_BSD_PARAM_NONE, domain, type, errno);
        }
      }
    }
    else
    { /* multicast local address */
      if ( E_OK == retVal )
      { /* set multicast SocketIds to unicast SocketId */
        dirLinkSocketId = *SocketIdPtr;
        limNodeSocketId = *SocketIdPtr;
      }
    }

    /* handle socket errors */
    if ( E_OK != retVal )
    {
      /* release all resources */
      if ( -1 != *SocketIdPtr )
      {
        (void)close(*SocketIdPtr);
        if ( -1 != dirLinkSocketId )
        {
          (void)close(dirLinkSocketId);
        }
      }
    }
    else
    {
      SoAd_SockIdx2MulticastAddr(SockIdx).DirLinkSocketId = dirLinkSocketId;
      SoAd_SockIdx2MulticastAddr(SockIdx).LimNodeSocketId = limNodeSocketId;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  SoAd_VTcpIpBind
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpIpBind(SoAd_SockIdxType SockIdx,
                        SoAd_SocketIdType SocketId,
                        SoAd_LocalAddrIdType LocalAddrId,
                        P2VAR(SoAd_PortType, AUTOMATIC, SOAD_APPL_VAR) PortPtr)
{
  Std_ReturnType retVal = E_OK;
  SoAd_SoConIdxType firstSoConIdx = SoAd_SockIdx2SoConIdxCol(SockIdx).SoConIdxStart;

  if ( SOAD_AF_INET == SoAd_SockCons(firstSoConIdx).SockConGrpPtr->Domain )
  {
    struct sockaddr_in localAddr;

    localAddr.sin_family = AF_INET;
    localAddr.sin_port = IPBASE_HTON16(*PortPtr);

    /* bind socket */
    localAddr.sin_addr.s_addr = SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[0];

    if ( -1 == bind(SocketId, SOAD_A_P2CONST(struct sockaddr)&localAddr, sizeof(localAddr)) )
    {
      retVal = E_NOT_OK;
      if ( EADDRNOTAVAIL == errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
      { /* IP address seems not to be available anymore */
        if ( E_OK != SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, FALSE) )
        { /* IP address is not available anymore */
          SoAd_AddrId2LocalIpAddrReqState(LocalAddrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE;
          /* set event to handle local address in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), LocalAddrId);
        }
      }
      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
      SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_BIND, SOAD_SOCK_BSD_API_BIND, SOAD_SOCK_BSD_PARAM_NONE,
        SoAd_SockCons(firstSoConIdx).SoConId, SocketId, errno);
    }
    else
    {
      if ( 0u == *PortPtr )
      { /* a random port has been chosen */
        struct sockaddr_in sockAddr;
        socklen_t sockAddrLen = sizeof(sockAddr);

        /* retrieve port */
        if ( -1 == getsockname(SocketId, SOAD_A_P2VAR(struct sockaddr)&sockAddr, &sockAddrLen) )
        {
          retVal = E_NOT_OK;
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_BIND, SOAD_SOCK_BSD_API_GET_SOCK_NAME,
            SOAD_SOCK_BSD_PARAM_NONE, SoAd_SockCons(firstSoConIdx).SoConId, SocketId, errno);
        }
        else
        {
          *PortPtr = IPBASE_SWAP16(sockAddr.sin_port);
          localAddr.sin_port = sockAddr.sin_port;
        }
      }
    }

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
    if ( NULL_PTR != SoAd_SockCons(firstSoConIdx).SockConGrpPtr->SocketUdpPtr )
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
    { /* UDP */
      if ( SoAd_LocalAddr(LocalAddrId).AddressType != SOAD_ADDRESS_TYPE_MULTICAST )
      { /* unicast local address needs additional UDP sockets to receive from broadcasts */
        /* bind for directed broadcast socket */
        localAddr.sin_addr.s_addr = SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[0] |
          IPBASE_HTON32((INADDR_BROADCAST >> SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).netmask));

        if ( -1 == bind(SoAd_SockIdx2MulticastAddr(SockIdx).DirLinkSocketId, SOAD_A_P2CONST(struct sockaddr)&localAddr,
            sizeof(localAddr)) )
        {
          retVal = E_NOT_OK;
          if ( EADDRNOTAVAIL == errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
          { /* IP address seems not to be available anymore */
            if ( E_OK != SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, FALSE) )
            { /* IP address is not available anymore */
              SoAd_AddrId2LocalIpAddrReqState(LocalAddrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE;
              /* set event to handle local address in main function */
              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), LocalAddrId);
            }
          }
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_BIND, SOAD_SOCK_BSD_API_BIND, SOAD_SOCK_BSD_PARAM_NONE,
            SoAd_SockCons(firstSoConIdx).SoConId,
            SoAd_SockIdx2MulticastAddr(SockIdx).DirLinkSocketId, errno);
        }

        /* bind for limited broadcast socket */
        localAddr.sin_addr.s_addr = INADDR_BROADCAST;

        if ( -1 == bind(SoAd_SockIdx2MulticastAddr(SockIdx).LimNodeSocketId, SOAD_A_P2CONST(struct sockaddr)&localAddr,
            sizeof(localAddr)) )
        {
          retVal = E_NOT_OK;
          if ( EADDRNOTAVAIL == errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
          { /* IP address seems not to be available anymore */
            if ( E_OK != SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, FALSE) )
            { /* IP address is not available anymore */
              SoAd_AddrId2LocalIpAddrReqState(LocalAddrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE;
              /* set event to handle local address in main function */
              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), LocalAddrId);
            }
          }
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_BIND, SOAD_SOCK_BSD_API_BIND, SOAD_SOCK_BSD_PARAM_NONE,
            SoAd_SockCons(firstSoConIdx).SoConId,
            SoAd_SockIdx2MulticastAddr(SockIdx).LimNodeSocketId, errno);
        }
      }
    }
  }
  else
  {
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    struct sockaddr_in6 localAddr;

    localAddr.sin6_family = AF_INET6;
    localAddr.sin6_port = IPBASE_HTON16(*PortPtr);
    localAddr.sin6_flowinfo = 0u;
    localAddr.sin6_scope_id = SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).ifcIdx;

    *((uint32*)&localAddr.sin6_addr.s6_addr[0]) = SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[0];
    *((uint32*)&localAddr.sin6_addr.s6_addr[4]) = SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[1];
    *((uint32*)&localAddr.sin6_addr.s6_addr[8]) = SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[2];
    *((uint32*)&localAddr.sin6_addr.s6_addr[12]) = SoAd_AddrId2LocalIpAddrDyn(LocalAddrId).addr[3];

    if ( -1 == bind(SocketId, SOAD_A_P2CONST(struct sockaddr)&localAddr, sizeof(localAddr)) )
    {
      retVal = E_NOT_OK;
      if ( EADDRNOTAVAIL == errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
      { /* IP address seems not to be available anymore */
        if ( E_OK != SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, FALSE) )
        { /* IP address is not available anymore */
          SoAd_AddrId2LocalIpAddrReqState(LocalAddrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE;
          /* set event to handle local address in main function */
          SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), LocalAddrId);
        }
      }
      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
      SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_BIND, SOAD_SOCK_BSD_API_BIND, SOAD_SOCK_BSD_PARAM_NONE,
        SoAd_SockCons(firstSoConIdx).SoConId, SocketId, errno);
    }
    else
    {
      if ( 0u == *PortPtr )
      { /* a random port has been chosen */
        struct sockaddr_in6 sockAddr;
        socklen_t sockAddrLen = sizeof(sockAddr);

        /* retrieve port */
        if ( -1 == getsockname(SocketId, SOAD_A_P2VAR(struct sockaddr)&sockAddr, &sockAddrLen) )
        {
          retVal = E_NOT_OK;
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_BIND, SOAD_SOCK_BSD_API_GET_SOCK_NAME,
            SOAD_SOCK_BSD_PARAM_NONE, SoAd_SockCons(firstSoConIdx).SoConId, SocketId, errno);
        }
        else
        {
          *PortPtr = IPBASE_SWAP16(sockAddr.sin6_port);
        }
      }
    }

#  if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
    if ( NULL_PTR != SoAd_SockCons(firstSoConIdx).SockConGrpPtr->SocketUdpPtr )
#  endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
    { /* UDP */
      if ( SoAd_LocalAddr(LocalAddrId).AddressType != SOAD_ADDRESS_TYPE_MULTICAST )
      { /* unicast local address needs additional UDP sockets to receive from multicasts */
        /* bind for link-local multicast socket */
        *((uint32*)&localAddr.sin6_addr.s6_addr[0])  = IPBASE_HTON32(0xFF010000ul);
        *((uint32*)&localAddr.sin6_addr.s6_addr[4])  = IPBASE_HTON32(0x00000000ul);
        *((uint32*)&localAddr.sin6_addr.s6_addr[8])  = IPBASE_HTON32(0x00000000ul);
        *((uint32*)&localAddr.sin6_addr.s6_addr[12]) = IPBASE_HTON32(0x00000001ul);

        if ( -1 == bind(SoAd_SockIdx2MulticastAddr(SockIdx).DirLinkSocketId, SOAD_A_P2CONST(struct sockaddr)&localAddr,
            sizeof(localAddr)) )
        {
          retVal = E_NOT_OK;
          if ( EADDRNOTAVAIL == errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
          { /* IP address seems not to be available anymore */
            if ( E_OK != SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, FALSE) )
            { /* IP address is not available anymore */
              SoAd_AddrId2LocalIpAddrReqState(LocalAddrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE;
              /* set event to handle local address in main function */
              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), LocalAddrId);
            }
          }
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_BIND, SOAD_SOCK_BSD_API_BIND, SOAD_SOCK_BSD_PARAM_NONE,
            SoAd_SockCons(firstSoConIdx).SoConId,
            SoAd_SockIdx2MulticastAddr(SockIdx).DirLinkSocketId, errno);
        }

        /* bind for node-local multicast socket */
        *((uint32*)&localAddr.sin6_addr.s6_addr[0])  = IPBASE_HTON32(0xFF020000ul);
        *((uint32*)&localAddr.sin6_addr.s6_addr[4])  = IPBASE_HTON32(0x00000000ul);
        *((uint32*)&localAddr.sin6_addr.s6_addr[8])  = IPBASE_HTON32(0x00000000ul);
        *((uint32*)&localAddr.sin6_addr.s6_addr[12]) = IPBASE_HTON32(0x00000001ul);

        if ( -1 == bind(SoAd_SockIdx2MulticastAddr(SockIdx).LimNodeSocketId, SOAD_A_P2CONST(struct sockaddr)&localAddr,
            sizeof(localAddr)) )
        {
          retVal = E_NOT_OK;
          if ( EADDRNOTAVAIL == errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
          { /* IP address seems not to be available anymore */
            if ( E_OK != SoAd_VCheckAndOverwriteLocalAddr(firstSoConIdx, FALSE) )
            { /* IP address is not available anymore */
              SoAd_AddrId2LocalIpAddrReqState(LocalAddrId) = SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE;
              /* set event to handle local address in main function */
              SoAd_VEventQueueAddElement(SoAd_EventQueueIdxLocalAddr(), LocalAddrId);
            }
          }
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_BIND, SOAD_SOCK_BSD_API_BIND, SOAD_SOCK_BSD_PARAM_NONE,
            SoAd_SockCons(firstSoConIdx).SoConId,
            SoAd_SockIdx2MulticastAddr(SockIdx).LimNodeSocketId, errno);
        }
      }
    }
# else
    retVal = E_NOT_OK;
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  SoAd_VTcpIpListen
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpIpListen(SoAd_SocketIdType SocketId, uint16 MaxChannels)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ( -1 != listen(SocketId, MaxChannels) )
  {
    retVal = E_OK;
  }
  else
  {
    /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
    SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_LISTEN, SOAD_SOCK_BSD_API_LISTEN, SOAD_SOCK_BSD_PARAM_NONE,
      SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  SoAd_VTcpIpConnect
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpIpConnect(SoAd_SockIdxType SockIdx, SoAd_SocketIdType SocketId,
                        P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemAddrPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ( SOAD_AF_INET == RemAddrPtr->domain )
  {
    struct sockaddr_in sockAddr;

    sockAddr.sin_family = AF_INET;
    SoAd_VConvertAsrSockAddr2BsdSockAddr(SOAD_A_P2VAR(struct sockaddr)&sockAddr, RemAddrPtr);

    /* will return always -1 (non-blocking mode) */
    (void)connect(SocketId, SOAD_A_P2VAR(struct sockaddr)&sockAddr, sizeof(sockAddr));

    if ( EINPROGRESS == errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
    {
      retVal = E_OK;
    }
    else
    {
      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
      SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CONNECT, SOAD_SOCK_BSD_API_CONNECT, SOAD_SOCK_BSD_PARAM_NONE,
        SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
    }
  }
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
  else
  {
    SoAd_LocalAddrIdType addrId = SoAd_SockCons(
      SoAd_SockIdx2SoConIdxCol(SockIdx).SoConIdxStart).SockConGrpPtr->LocIpAddrId;
    struct sockaddr_in6 sockAddr;

    sockAddr.sin6_family = AF_INET6;
    sockAddr.sin6_scope_id = SoAd_AddrId2LocalIpAddrDyn(addrId).ifcIdx;
    SoAd_VConvertAsrSockAddr2BsdSockAddr(SOAD_A_P2VAR(struct sockaddr)&sockAddr, RemAddrPtr);

    /* will return always -1 (non-blocking mode) */
    (void)connect(SocketId, SOAD_A_P2VAR(struct sockaddr)&sockAddr, sizeof(sockAddr));

    if ( EINPROGRESS == errno ) /* PRQA S 5119 */ /* MD_SoAd_20.5 */
    {
      retVal = E_OK;
    }
    else
    {
      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
      SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CONNECT, SOAD_SOCK_BSD_API_CONNECT, SOAD_SOCK_BSD_PARAM_NONE,
        SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
    }
  }
# else
  SOAD_DUMMY_STATEMENT_VAR(SockIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */

  return retVal;
}

/**********************************************************************************************************************
 *  SoAd_VTcpIpClose
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpIpClose(SoAd_SocketIdType SocketId, boolean Abort,
                        SoAd_SockIdxType SockIdx, boolean CallEventFunction)
{
  Std_ReturnType retVal = E_OK;
  SoAd_SoConIdxType firstSoConIdx = SoAd_SockIdx2SoConIdxCol(SockIdx).SoConIdxStart;

  SOAD_DUMMY_STATEMENT_VAR(Abort); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  if ( NULL_PTR != SoAd_SockCons(firstSoConIdx).SockConGrpPtr->SocketUdpPtr )
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
  {
    SoAd_LocalAddrIdType addrId = SoAd_SockCons(firstSoConIdx).SockConGrpPtr->LocIpAddrId;

    if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_UNICAST )
    { /* unicast local address needs additional UDP sockets to receive from broadcasts/multicasts */
      /* directed broadcast/link-local multicast address */
      if ( -1 == close(SoAd_SockIdx2MulticastAddr(SockIdx).DirLinkSocketId) )
      {
        retVal = E_NOT_OK;
        /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
        SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CLOSE, SOAD_SOCK_BSD_API_CLOSE, SOAD_SOCK_BSD_PARAM_NONE,
          SoAd_SockCons(firstSoConIdx).SoConId, SoAd_SockIdx2MulticastAddr(SockIdx).DirLinkSocketId, errno);
      }
      SoAd_SockIdx2MulticastAddr(SockIdx).DirLinkSocketId = -1;
      /* limited broadcast/node-local multicast address */
      if ( -1 == close(SoAd_SockIdx2MulticastAddr(SockIdx).LimNodeSocketId) )
      {
        retVal = E_NOT_OK;
        /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
        SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CLOSE, SOAD_SOCK_BSD_API_CLOSE, SOAD_SOCK_BSD_PARAM_NONE,
          SoAd_SockCons(firstSoConIdx).SoConId, SoAd_SockIdx2MulticastAddr(SockIdx).LimNodeSocketId, errno);
      }
      SoAd_SockIdx2MulticastAddr(SockIdx).LimNodeSocketId = -1;
    }
  }

  if ( -1 == close(SocketId) )
  {
    retVal = E_NOT_OK;
    /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
    SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CLOSE, SOAD_SOCK_BSD_API_CLOSE, SOAD_SOCK_BSD_PARAM_NONE,
      SoAd_SockCons(firstSoConIdx).SoConId, SocketId, errno);
  }

  if ( TRUE == CallEventFunction )
  { /* SocketId in use - event function must be called to reset socket */
    if ( NULL_PTR != SoAd_SockCons(firstSoConIdx).SockConGrpPtr->SocketUdpPtr )
    {
      SoAd_TcpIpEvent(SocketId, SOAD_UDP_CLOSED);
    }
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
    else
    {
      SoAd_SockIdx2RxMgt(SockIdx).Len = 0;
      SoAd_SockIdx2RxMgt(SockIdx).Offset = 0;
      SoAd_TcpIpEvent(SocketId, SOAD_TCP_CLOSED);
    }
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  SoAd_VTcpIpUdpTransmit
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpIpUdpTransmit(SoAd_SockIdxType SockIdx,
                        SoAd_SocketIdType SocketId,
                        P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC) RemAddrPtr,
                        uint32 AvailableLength)
{
  Std_ReturnType retVal = E_NOT_OK;

# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
  struct sockaddr_in6 remAddr;
# else
  struct sockaddr_in remAddr;
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */

  SoAd_VConvertAsrSockAddr2BsdSockAddr(SOAD_A_P2VAR(struct sockaddr)&remAddr, RemAddrPtr);

  if ( SOAD_VSOCKET_TX_BUFFER_SIZE >= AvailableLength )
  { /* Tx buffer size sufficient */
# if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
    if ( BUFREQ_OK == SoAd_CopyTxData(SocketId, &SoAd_SocketTxBuffer()[0], SOAD_A_P2VAR(uint16)&AvailableLength) )
# else
    if ( BUFREQ_OK == SoAd_CopyTxData(SocketId, &SoAd_SocketTxBuffer()[0], AvailableLength) )
# endif
    { /* data copied completely to Tx buffer */
      if ( AF_INET == (SOAD_A_P2VAR(struct sockaddr)&remAddr)->sa_family )
      {
        if ( -1 != sendto(SocketId, SOAD_A_P2CONST(void)&SoAd_SocketTxBuffer()[0], AvailableLength, SOAD_ZERO_FLAGS,
            SOAD_A_P2VAR(struct sockaddr)&remAddr, sizeof(struct sockaddr_in)) )
        { /* transmission successful */
          retVal = E_OK;
        }
        else
        {
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_UDP_TRANSMIT, SOAD_SOCK_BSD_API_SEND_TO,
            SOAD_SOCK_BSD_PARAM_NONE, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
        }
      }
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
      else
      {
        SoAd_LocalAddrIdType addrId = SoAd_SockCons(
            SoAd_SockIdx2SoConIdxCol(SockIdx).SoConIdxStart).SockConGrpPtr->LocIpAddrId;
        remAddr.sin6_scope_id = SoAd_AddrId2LocalIpAddrDyn(addrId).ifcIdx;

        if ( -1 != sendto(SocketId, SOAD_A_P2CONST(void)&SoAd_SocketTxBuffer()[0], AvailableLength, SOAD_ZERO_FLAGS,
            SOAD_A_P2VAR(struct sockaddr)&remAddr, sizeof(struct sockaddr_in6)) )
        { /* transmission successful */
          retVal = E_OK;
        }
        else
        {
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_UDP_TRANSMIT, SOAD_SOCK_BSD_API_SEND_TO,
            SOAD_SOCK_BSD_PARAM_NONE, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
        }
      }
# else
      SOAD_DUMMY_STATEMENT_VAR(SockIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    }
  }

  return retVal;
}

# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
/**********************************************************************************************************************
 *  SoAd_VTcpIpTransmit
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpIpTransmit(SoAd_SocketIdType SocketId, uint32 AvailableLength)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ( SOAD_VSOCKET_TX_BUFFER_SIZE >= AvailableLength )
  { /* Tx buffer size sufficient */
    /* check if transmission is possible */
    struct pollfd sockDesc;

    sockDesc.fd = SocketId;
    sockDesc.events = POLLOUT;
    sockDesc.revents = 0;

    if ( 1 == poll(&sockDesc, 1, 0) )
    { /* transmission possible */
#  if ( SOAD_VTX_DYN_LEN_ENABLED == STD_ON )
      if ( BUFREQ_OK == SoAd_CopyTxData(SocketId, &SoAd_SocketTxBuffer()[0], SOAD_A_P2VAR(uint16)&AvailableLength) )
#  else
      if ( BUFREQ_OK == SoAd_CopyTxData(SocketId, &SoAd_SocketTxBuffer()[0], AvailableLength) )
#  endif /* SOAD_VTX_DYN_LEN_ENABLED == STD_ON */
      { /* data copied completely to Tx buffer */
        if ( -1 != send(SocketId, SOAD_A_P2CONST(void)&SoAd_SocketTxBuffer()[0], AvailableLength, SOAD_ZERO_FLAGS) )
        { /* transmission successful */
          retVal = E_OK;
        }
      }
    }
  }

  return retVal;
}
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

#if ( (defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED)) || \
  (defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED)) || \
  (defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED)) )
/**********************************************************************************************************************
 *  SoAd_VTcpIpChangeParameter
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 3206 2 */ /* MD_SoAd_3206 */
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VTcpIpChangeParameter(SoAd_SoConIdxType SoConIdx,
                                  SoAd_SocketIdType SocketId, boolean IsTcpAcceptedSocket)
{
# if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
  sint32 var;

  /* set socket in non-blocking mode */
  /* get flags */
  var = fcntl(SocketId, F_GETFL, 0);
  if ( -1 == var )
  {
    /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
    SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
      SOAD_SOCK_BSD_PARAM_F_GETFL, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
    return E_NOT_OK;
  }

  if ( -1 == fcntl(SocketId, F_SETFL, var|O_NONBLOCK) )
  {
    /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
    SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
      SOAD_SOCK_BSD_PARAM_F_SETFL, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
    return E_NOT_OK;
  }

  /* set reuse option for IP address to have possibility to bind same address to another local address */
  var = (sint32)TRUE;
  if ( -1 == setsockopt(SocketId, SOL_SOCKET, SO_REUSEADDR, &var, sizeof(var)) )
  {
    /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
    SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
      SOAD_SOCK_BSD_PARAM_REUSEADDR, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
    return E_NOT_OK;
  }

  /* set bind to device option to bind socket on one device */
  /* not yet supported */

  if ( -1 == setsockopt(SocketId, SOL_SOCKET, SO_BROADCAST, &var, sizeof(var)) )
  {
    /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
    SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
      SOAD_SOCK_BSD_PARAM_BROADCAST, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
    return E_NOT_OK;
  }

#  if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
  /* restrict socket to one address */
  if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Domain == SOAD_AF_INET6 )
  {
    if ( FALSE == IsTcpAcceptedSocket )
    {
      if ( -1 == setsockopt(SocketId, IPPROTO_IPV6, IPV6_V6ONLY, &var, sizeof(var)) )
      {
        /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
        SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
          SOAD_SOCK_BSD_PARAM_IP6ONLY, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
        return E_NOT_OK;
      }
    }
  }
#  else
  SOAD_DUMMY_STATEMENT_VAR(IsTcpAcceptedSocket); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#  endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */

#  if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
  if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr != NULL_PTR )
  { /* TCP socket */
    /* set linger time */
    if ( SoAd_LingerTimeoutEnabled() == TRUE )
    { /* linger time enabled */
      struct linger lingerConfig;
      lingerConfig.l_onoff = 1;
      lingerConfig.l_linger = 0;
      if ( -1 == setsockopt(SocketId, SOL_SOCKET, SO_LINGER, &lingerConfig, sizeof(lingerConfig)) )
      {
        /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
        SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
          SOAD_SOCK_BSD_PARAM_LINGER, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
        return E_NOT_OK;
      }
    }

    /* Rx Buffer */
    if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SockTpRxBufMin > 0u )
    { /* Rx buffer size is configured */
      size_t sockTpRxBufMin = SoAd_SockCons(SoConIdx).SockConGrpPtr->SockTpRxBufMin;

      if ( -1 == setsockopt(SocketId, SOL_SOCKET, SO_RCVBUF, &sockTpRxBufMin, sizeof(sockTpRxBufMin)) )
      {
        /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
        SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
          SOAD_SOCK_BSD_PARAM_RCVBUF, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
        return E_NOT_OK;
      }
    }

#   if ( defined(SOAD_VTCP_TX_BUF_MIN_ENABLED) && (STD_ON == SOAD_VTCP_TX_BUF_MIN_ENABLED) )
    /* Tx Buffer */
    if ( 0u < SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpTxBufMin )
    { /* Tx buffer size is configured */
      sint32 sockTcpTxBufMin = SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpTxBufMin;

      if ( -1 == setsockopt(SocketId, SOL_SOCKET, SO_SNDBUF, &sockTcpTxBufMin, sizeof(sockTcpTxBufMin)) )
      {
        /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
        SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
          SOAD_SOCK_BSD_PARAM_SNDBUF, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
        return E_NOT_OK;
      }
    }
#   endif/* defined(SOAD_VTCP_TX_BUF_MIN_ENABLED) && (STD_ON == SOAD_VTCP_TX_BUF_MIN_ENABLED) */

    /* TCP no delay (Nagle) */
    switch ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpNoDelay )
    {
      case SOAD_TCP_NO_DELAY_ENABLED:
      {
        if ( -1 == setsockopt(SocketId, IPPROTO_TCP, TCP_NODELAY, &var, sizeof(var)) )
        {
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
              SOAD_SOCK_BSD_PARAM_NODELAY, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
          return E_NOT_OK;
        }
        break;
      }
      case SOAD_TCP_NO_DELAY_DISABLED:
      {
        var = (sint32)FALSE;
        if ( -1 == setsockopt(SocketId, IPPROTO_TCP, TCP_NODELAY, &var, sizeof(var)) )
        {
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
              SOAD_SOCK_BSD_PARAM_NODELAY, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
          return E_NOT_OK;
        }
        break;
      }
      default:
      { /* SOAD_TCP_NO_DELAY_NOT_SPECIFIED */
        /* nothing to do */
      }
    }

#   if ( defined(SOAD_VTCP_KEEP_ALIVE_ENABLED) && (STD_ON == SOAD_VTCP_KEEP_ALIVE_ENABLED) )
    /* Keep Alive */
    var = (sint32)SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAlive;
    if ( -1 == setsockopt(SocketId, SOL_SOCKET, SO_KEEPALIVE, &var, sizeof(var)) )
    {
      /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
      SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
          SOAD_SOCK_BSD_PARAM_SO_KEEPALIVE, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
      return E_NOT_OK;
    }
    if ( TRUE == SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAlive )
    { /* Keep Alive is enabled */
      /* set sub parameter */
      /* Keep Alive Time */
      if ( SOAD_INV_KEEP_ALIVE_VALUE != SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveTime )
      { /* Keep Alive Time is enabled */
        var = (sint32)SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveTime;
        if ( -1 == setsockopt(SocketId, IP_PROTOTCP, TCP_KEEPALIVE, &var, sizeof(var)) )
        {
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
            SOAD_SOCK_BSD_PARAM_TCP_KEEPALIVE, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
          return E_NOT_OK;
        }
      }
      /* Keep Alive Probes Max */
      if ( SOAD_INV_KEEP_ALIVE_VALUE != SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveProbesMax )
      { /* Keep Alive Probes Max is enabled */
        var = (sint32)SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveProbesMax;
        if ( -1 == setsockopt(SocketId, IP_PROTOTCP, TM_TCP_KEEPALIVE_CNT, &var, sizeof(var)) )
        {
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
            SOAD_SOCK_BSD_PARAM_TCP_KEEPALIVE_CNT, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
          return E_NOT_OK;
        }
      }
      /* Keep Alive Internal */
      if ( SOAD_INV_KEEP_ALIVE_VALUE != SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveInterval )
      { /* Keep Alive Internal is enabled */
        var = (sint32)SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveInterval;
        if ( -1 == setsockopt(SocketId, IP_PROTOTCP, TM_TCP_KEEPALIVE_INTV, &var, sizeof(var)) )
        {
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
            SOAD_SOCK_BSD_PARAM_TCP_KEEPALIVE_INTV, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
          return E_NOT_OK;
        }
      }
    }
#   endif /* defined(SOAD_VTCP_KEEP_ALIVE_ENABLED) && (STD_ON == SOAD_VTCP_KEEP_ALIVE_ENABLED) */
  }
  else
#  endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
  { /* UDP socket */
#  if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Domain == SOAD_AF_INET6 )
    { /* IPv6 */
      SoAd_LocalAddrIdType addrId = SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId;

      if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_MULTICAST )
      { /* multicast address type */
        /* join specific multicast address */
        struct ipv6_mreq mreq;

        mreq.ipv6mr_interface = SoAd_LocalAddr(addrId).IfcIdx;
        *((uint32*)&mreq.ipv6mr_multiaddr.s6_addr[0]) = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0];
        *((uint32*)&mreq.ipv6mr_multiaddr.s6_addr[4]) = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[1];
        *((uint32*)&mreq.ipv6mr_multiaddr.s6_addr[8]) = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[2];
        *((uint32*)&mreq.ipv6mr_multiaddr.s6_addr[12]) = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[3];

        if ( -1 == setsockopt(SocketId, IPPROTO_IPV6, IPV6_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) )
        {
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
            SOAD_SOCK_BSD_PARAM_IP_ADD_MEMBERSHIP, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
          return E_NOT_OK;
        }
      }
      else
      { /* unicast address type */
        SoAd_SockIdxType sockIdx = SoAd_SockCons(SoConIdx).SockIdx;

        /* unicast local address needs additional UDP sockets to receive from multicasts */

        /* link-local multicast socket */

        /* set socket in non-blocking mode */
        /* get flags */
        var = fcntl(SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId, F_GETFL, 0);
        if ( -1 == var )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
            SOAD_SOCK_BSD_PARAM_F_GETFL, SOAD_SOCK_BSD_VALUE_NONE, SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId,
            errno);
          return E_NOT_OK;
        }
        if ( -1 == fcntl(SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId, F_SETFL, var|O_NONBLOCK) )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
            SOAD_SOCK_BSD_PARAM_F_SETFL, SOAD_SOCK_BSD_VALUE_NONE, SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId,
            errno);
          return E_NOT_OK;
        }

        /* set reuse option for IP address to have possibility to bind same address to another local address */
        var = (sint32)TRUE;
        if ( -1 == setsockopt(SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId, SOL_SOCKET, SO_REUSEADDR, &var,
            sizeof(var)) )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
            SOAD_SOCK_BSD_PARAM_REUSEADDR, SOAD_SOCK_BSD_VALUE_NONE,
            SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId, errno);
          return E_NOT_OK;
        }

        /* node-local multicast socket */

        /* set socket in non-blocking mode */
        /* get flags */
        var = fcntl(SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, F_GETFL, 0);
        if ( -1 == var )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
            SOAD_SOCK_BSD_PARAM_F_GETFL, SOAD_SOCK_BSD_VALUE_NONE,
            SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, errno);
          return E_NOT_OK;
        }
        if ( -1 == fcntl(SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, F_SETFL, var|O_NONBLOCK) )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
            SOAD_SOCK_BSD_PARAM_F_SETFL, SOAD_SOCK_BSD_VALUE_NONE,
            SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, errno);
          return E_NOT_OK;
        }

        /* set reuse option for IP address to have possibility to bind same address to another local address */
        var = (sint32)TRUE;
        if ( -1 == setsockopt(SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, SOL_SOCKET, SO_REUSEADDR, &var,
            sizeof(var)) )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
            SOAD_SOCK_BSD_PARAM_REUSEADDR, SOAD_SOCK_BSD_VALUE_NONE,
            SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, errno);
          return E_NOT_OK;
        }
      }
    }
    else
#  endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    { /* IPv4 UDP sockets have to listen additionally to broadcast sockets */
      SoAd_LocalAddrIdType addrId = SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId;

      if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_MULTICAST )
      { /* multicast address type */
        /* join specific multicast address */
        struct ip_mreqn mreq;

        mreq.imr_ifindex = SoAd_LocalAddr(addrId).IfcIdx;
        mreq.imr_address.s_addr = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0];
        mreq.imr_multiaddr.s_addr = SoAd_AddrId2LocalIpAddrDyn(addrId).addr[0];

        if ( -1 == setsockopt(SocketId, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) )
        {
          /* PRQA S 5119 2 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
            SOAD_SOCK_BSD_PARAM_IP_ADD_MEMBERSHIP, SOAD_SOCK_BSD_VALUE_NONE, SocketId, errno);
          return E_NOT_OK;
        }
      }
      else
      { /* unicast address type */
        SoAd_SockIdxType sockIdx = SoAd_SockCons(SoConIdx).SockIdx;

        /* unicast local address needs additional UDP sockets to receive from broadcasts */

        /* broadcast socket */

        /* set socket in non-blocking mode */
        /* get flags */
        var = fcntl(SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId, F_GETFL, 0);
        if ( -1 == var )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
            SOAD_SOCK_BSD_PARAM_F_GETFL, SOAD_SOCK_BSD_VALUE_NONE, SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId,
            errno);
          return E_NOT_OK;
        }
        if ( -1 == fcntl(SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId, F_SETFL, var|O_NONBLOCK) )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
            SOAD_SOCK_BSD_PARAM_F_SETFL, SOAD_SOCK_BSD_VALUE_NONE, SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId,
            errno);
          return E_NOT_OK;
        }

        /* set reuse option for IP address to have possibility to bind same address to another local address */
        var = (sint32)TRUE;
        if ( -1 == setsockopt(SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId, SOL_SOCKET, SO_REUSEADDR, &var,
            sizeof(var)) )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
            SOAD_SOCK_BSD_PARAM_REUSEADDR, SOAD_SOCK_BSD_VALUE_NONE,
            SoAd_SockIdx2MulticastAddr(sockIdx).DirLinkSocketId, errno);
          return E_NOT_OK;
        }

        /* limited broadcast socket */

        /* set socket in non-blocking mode */
        /* get flags */
        var = fcntl(SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, F_GETFL, 0);
        if ( -1 == var )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
            SOAD_SOCK_BSD_PARAM_F_GETFL, SOAD_SOCK_BSD_VALUE_NONE,
            SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, errno);
          return E_NOT_OK;
        }
        if ( -1 == fcntl(SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, F_SETFL, var|O_NONBLOCK) )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_FCNTL,
            SOAD_SOCK_BSD_PARAM_F_SETFL, SOAD_SOCK_BSD_VALUE_NONE,
            SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, errno);
          return E_NOT_OK;
        }

        /* set reuse option for IP address to have possibility to bind same address to another local address */
        var = (sint32)TRUE;
        if ( -1 == setsockopt(SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, SOL_SOCKET, SO_REUSEADDR, &var,
            sizeof(var)) )
        {
          /* PRQA S 5119 3 */ /* MD_SoAd_20.5 */
          SOAD_REPORT_SOCK_ERROR_PARAM_2(SOAD_SOCK_API_VTCPIP_CHG_PARAMETER, SOAD_SOCK_BSD_API_SET_SOCK_OPT,
            SOAD_SOCK_BSD_PARAM_REUSEADDR, SOAD_SOCK_BSD_VALUE_NONE,
            SoAd_SockIdx2MulticastAddr(sockIdx).LimNodeSocketId, errno);
          return E_NOT_OK;
        }
      }
    }
  }
# else
#  if ( defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED) )
  /* frame priority */
  if ( SOAD_INV_FRAME_PRIORITY != SoAd_SockCons(SoConIdx).SockConGrpPtr->FramePriority )
  { /* frame priority is configured */
    uint8 framePriority = SoAd_SockCons(SoConIdx).SockConGrpPtr->FramePriority;
    if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_FRAMEPRIO, &framePriority) )
    { /* parameter change failed */
      return E_NOT_OK;
    }
  }
#  endif /* defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED) */

  if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->Protocol == SOAD_IPPROTO_TCP )
  { /* TCP socket */
    /* Rx window size */
    if ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SockTpRxBufMin > 0u )
    { /* Rx window size is configured */
      uint32 sockTpRxBufMin = SoAd_SockCons(SoConIdx).SockConGrpPtr->SockTpRxBufMin;

      if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TCP_RXWND_MAX, (uint8*)&sockTpRxBufMin) )
      { /* parameter change failed */
        return E_NOT_OK;
      }
    }

#  if ( defined(SOAD_VTCP_TX_BUF_MIN_ENABLED) && (STD_ON == SOAD_VTCP_TX_BUF_MIN_ENABLED) )
    /* Tx window size */
    if ( 0u < SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpTxBufMin )
    { /* Tx window size is configured */
      uint32 sockTcpTxBufMin = SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpTxBufMin;

      if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TCP_TXWND_MAX, (uint8*)&sockTcpTxBufMin) )
      { /* parameter change failed */
        return E_NOT_OK;
      }
    }
#  endif/* defined(SOAD_VTCP_TX_BUF_MIN_ENABLED) && (STD_ON == SOAD_VTCP_TX_BUF_MIN_ENABLED) */

    /* TCP no delay (Nagle) */
    switch ( SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpNoDelay )
    {
      case SOAD_TCP_NO_DELAY_ENABLED:
      {
        uint8 value = 0x00u;

        if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TCP_NAGLE, &value) )
        { /* parameter change failed */
          return E_NOT_OK;
        }
        break;
      }
      case SOAD_TCP_NO_DELAY_DISABLED:
      {
        uint8 value = 0x01u;

        if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TCP_NAGLE, &value) )
        { /* parameter change failed */
          return E_NOT_OK;
        }
        break;
      }
      default:
      { /* SOAD_TCP_NO_DELAY_NOT_SPECIFIED */
        /* nothing to do */
      }
    }

#  if ( defined(SOAD_VTCP_KEEP_ALIVE_ENABLED) && (STD_ON == SOAD_VTCP_KEEP_ALIVE_ENABLED) )
    /* Keep Alive */
    if ( (E_OK == TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TCP_KEEPALIVE,
          (uint8*)&SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAlive)) &&
        (TRUE == SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAlive))
    { /* Keep Alive is enabled */
      /* set sub parameter */
      /* Keep Alive Time */
      if ( SOAD_INV_KEEP_ALIVE_VALUE != SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveTime )
      { /* Keep Alive Time is enabled */
        if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TCP_KEEPALIVE_TIME,
            (uint8*)&SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveTime) )
        { /* parameter change failed */
          return E_NOT_OK;
        }
      }
      /* Keep Alive Probes Max */
      if ( SOAD_INV_KEEP_ALIVE_VALUE != SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveProbesMax )
      { /* Keep Alive Probes Max is enabled */
        if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TCP_KEEPALIVE_PROBES_MAX,
            (uint8*)&SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveProbesMax) )
        { /* parameter change failed */
          return E_NOT_OK;
        }
      }
      /* Keep Alive Internal */
      if ( SOAD_INV_KEEP_ALIVE_VALUE != SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveInterval )
      { /* Keep Alive Internal is enabled */
        if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TCP_KEEPALIVE_INTERVAL,
            (uint8*)&SoAd_SockCons(SoConIdx).SockConGrpPtr->SocketTcpPtr->TcpKeepAliveInterval) )
        { /* parameter change failed */
          return E_NOT_OK;
        }
      }
    }
#  endif /* defined(SOAD_VTCP_KEEP_ALIVE_ENABLED) && (STD_ON == SOAD_VTCP_KEEP_ALIVE_ENABLED) */

#  if ( defined(SOAD_VTCP_TLS_ENABLED) && (STD_ON == SOAD_VTCP_TLS_ENABLED) )
    /* TLS */
    if ( NULL_PTR != SoAd_SockCons(SoConIdx).TcpTlsConfigPtr )
    { /* TLS enabled */
      uint8 tlsEnabled = TRUE;

      /* Enable TLS */
      if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_USE_TLS, &tlsEnabled) )
      { /* parameter change failed */
        return E_NOT_OK;
      }
      else
      { /* TLS enabled */
        uint32 bufSize;

        /* TLS Rx buffer size */
        bufSize = SoAd_SockCons(SoConIdx).TcpTlsConfigPtr->RxBufSize;
        if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TLS_RXBUFSIZE, SOAD_A_P2VAR(uint8)&bufSize) )
        { /* parameter change failed */
          return E_NOT_OK;
        }
        /* TLS Tx buffer size */
        bufSize = SoAd_SockCons(SoConIdx).TcpTlsConfigPtr->TxBufSize;
        if ( E_OK != TcpIp_ChangeParameter(SocketId, SOAD_PARAMID_TLS_TXBUFSIZE, SOAD_A_P2VAR(uint8)&bufSize) )
        { /* parameter change failed */
          return E_NOT_OK;
        }

        /* notify user about socket creation */
        if (SOAD_FCT_ID_TLS_NOTIF_INV != SoAd_SockCons(SoConIdx).TcpTlsConfigPtr->FctIdTlsNotif)
        { /* notification configured */
          /* call notification function */
          SoAd_VCallTlsSockCreatedNotifFunc(SoAd_SockCons(SoConIdx).TcpTlsConfigPtr->FctIdTlsNotif,
            SoConIdx, SocketId);
        }
      }
    }
#  endif /* defined(SOAD_VTCP_TLS_ENABLED) && (STD_ON == SOAD_VTCP_TLS_ENABLED) */
  }
  SOAD_DUMMY_STATEMENT_VAR(IsTcpAcceptedSocket); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
# endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

  return E_OK;
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
#endif /* (defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED)) || \
  (defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED)) || \
  (defined(SOAD_VFRAME_PRIORITY_ENABLED) && (STD_ON == SOAD_VFRAME_PRIORITY_ENABLED)) */

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
#else
# if ( defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) )
/**********************************************************************************************************************
 *  SoAd_VTriggerAddressResolution
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VTriggerAddressResolution(SoAd_SoConIdxType SoConIdx)
{
  /* check if any PduRouteDest is configured for this socket connection */
  if ( SoAd_SockConIdx2PduRouteDestCol(SoConIdx).PduRouteDestListSize != 0u )
  {
    /* trigger address resolution */
    uint8 ctrlIdx = 0u;
    uint8 physAddr[6] = { 0u, 0u, 0u, 0u, 0u, 0u };

    if ( E_NOT_OK != TcpIp_GetCtrlIdx(SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId, &ctrlIdx) )
    {
      (void)TcpIp_GetRemotePhysAddr(ctrlIdx, SOAD_A_P2VAR(SoAd_SockAddrType)&SoAd_SockConIdx2RemSockDyn(SoConIdx),
        &physAddr[0], TRUE);
    }
  }
}
# endif /* defined(SOAD_VPDU_ROUTES) && (STD_ON == SOAD_VPDU_ROUTES) */
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )

/**********************************************************************************************************************
 *  SoAd_VWriteBufSegment
 *********************************************************************************************************************/
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
/* PRQA S 3689 SoAd_21_1 */ /* MD_SoAd_21.1 */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VWriteBufSegment(
                        P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) SrcBufPtr,
                        uint16 SrcBufLen,
                        P2VAR(SoAd_BufSegMgtType, AUTOMATIC, SOAD_APPL_DATA) TgtBufSegPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ( 0u != SrcBufLen )
  { /* new data received */
    /* check if buffer struct is alredy used */
    if ( 0u == TgtBufSegPtr->Lvl )
    { /* buffer struct unused */
      TgtBufSegPtr->BufSegs[TgtBufSegPtr->Idx].Len = SrcBufLen;
      TgtBufSegPtr->BufSegs[TgtBufSegPtr->Idx].DataPtr = SrcBufPtr;
      TgtBufSegPtr->Lvl++;
      retVal = E_OK;
    }
    else
    { /* buffer struct contains elements (at least one segment received before) */
      uint16 lastIdx;
      uint16 writeIdx;
      uint16 curLvl = (uint16)(TgtBufSegPtr->Lvl - 1u);

      /* get current index */
      if ( (TgtBufSegPtr->Idx + curLvl) >= SOAD_VBUF_SEG_SIZE_TOTAL )
      { /* wrap around necessary */
        lastIdx = curLvl - (SOAD_VBUF_SEG_SIZE_TOTAL - TgtBufSegPtr->Idx);
      }
      else
      { /* no wrap around necessary */
        lastIdx = TgtBufSegPtr->Idx + curLvl;
      }

      /* check if new data are available */
      if ( &TgtBufSegPtr->BufSegs[lastIdx].DataPtr[0] != &SrcBufPtr[0] )
      { /* new data shall be added */
        /* check if new segment is in same memory segment like last segment */
        if ( &TgtBufSegPtr->BufSegs[lastIdx].DataPtr[TgtBufSegPtr->BufSegs[lastIdx].Len] == &SrcBufPtr[0] )
        { /* new segment is in same memory segment */
          /* increment length only */
          TgtBufSegPtr->BufSegs[lastIdx].Len += SrcBufLen;

          retVal = E_OK;
        }
        else
        { /* new segment available */
          if ( SOAD_VBUF_SEG_SIZE_TOTAL > TgtBufSegPtr->Lvl )
          { /* segmented buffer struct size sufficient */
            /* find next free segment */
            if ( (TgtBufSegPtr->Idx + TgtBufSegPtr->Lvl) >= SOAD_VBUF_SEG_SIZE_TOTAL )
            { /* wrap around necessary */
              writeIdx = TgtBufSegPtr->Lvl - (SOAD_VBUF_SEG_SIZE_TOTAL - TgtBufSegPtr->Idx);
            }
            else
            { /* no wrap around necessary */
              writeIdx = TgtBufSegPtr->Idx + TgtBufSegPtr->Lvl;
            }

            TgtBufSegPtr->BufSegs[writeIdx].Len = SrcBufLen;
            TgtBufSegPtr->BufSegs[writeIdx].DataPtr = SrcBufPtr;
            TgtBufSegPtr->Lvl++;

            retVal = E_OK;
          }
        }
      }
      else
      {
        retVal = E_OK;
      }
    }
  }
  else
  { /* no new data received */
    retVal = E_OK;
  }

  return retVal;
}
/* PRQA L:MSR_STMIF */
/* PRQA L:SoAd_21_1 */

/**********************************************************************************************************************
 *  SoAd_VGetBufSegment
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_VGetBufSegment(
                        P2CONST(SoAd_BufSegMgtType, AUTOMATIC, SOAD_APPL_DATA) BufSegPtr,
                        uint32 StartPos,
                        P2VAR(uint8*, AUTOMATIC, SOAD_APPL_VAR) SegPtr,
                        P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) SegLen)
{
  uint16 bufSegIdx = BufSegPtr->Idx;
  uint16 bufSegLvl = BufSegPtr->Lvl;
  
  *SegLen = 0u;
  *SegPtr = &BufSegPtr->BufSegs[BufSegPtr->Idx].DataPtr[0];

  while ( 0u < bufSegLvl )
  {
    if ( BufSegPtr->BufSegs[bufSegIdx].Len <= StartPos )
    { /* start position in next buffer segment */
      StartPos -= BufSegPtr->BufSegs[bufSegIdx].Len;
      if ( (bufSegIdx + 1u) == SOAD_VBUF_SEG_SIZE_TOTAL )
      { /* wrap around */
        bufSegIdx = 0u;
      }
      else
      { /* no wrap around */
        bufSegIdx++;
      }
    }
    else
    { /* start position in current segment */
      /* set length */
      *SegLen = (uint32)(BufSegPtr->BufSegs[bufSegIdx].Len - StartPos);
      /* set data pointer */
      *SegPtr = &BufSegPtr->BufSegs[bufSegIdx].DataPtr[StartPos];
      break;
    }
    bufSegLvl--;
  }
}

#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VGetBufSegmentTotLen
 *********************************************************************************************************************/
FUNC(uint32, SOAD_CODE) SoAd_VGetBufSegmentTotLen(
                        P2CONST(SoAd_BufSegMgtType, AUTOMATIC, SOAD_APPL_DATA) BufSegPtr,
                        uint32 StartPos)
{
  uint32 totSegLen = 0u;
  uint16 bufSegIdx = BufSegPtr->Idx;
  uint16 bufSegLvl = BufSegPtr->Lvl;

  while ( 0u < bufSegLvl )
  {
    if ( BufSegPtr->BufSegs[bufSegIdx].Len <= StartPos )
    { /* start position in next buffer segment */
      StartPos -= BufSegPtr->BufSegs[bufSegIdx].Len;
    }
    else
    { /* start position in current segment */
      /* set length */
      totSegLen += (uint32)(BufSegPtr->BufSegs[bufSegIdx].Len - StartPos);
    }
    if ( (bufSegIdx + 1u) == SOAD_VBUF_SEG_SIZE_TOTAL )
    { /* wrap around */
      bufSegIdx = 0u;
    }
    else
    { /* no wrap around */
      bufSegIdx++;
    }
    bufSegLvl--;
  }

  return totSegLen;
}
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */

/**********************************************************************************************************************
 *  SoAd_VReleaseBufSegment
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_VReleaseBufSegment(
                        P2VAR(SoAd_BufSegMgtType, AUTOMATIC, AUTOMATIC) BufSegPtr,
                        uint32 Len)
{
  while ( (0u < Len) && (0u < BufSegPtr->Lvl) )
  {
    if ( Len < BufSegPtr->BufSegs[BufSegPtr->Idx].Len )
    { /* release buffer in current element only */
      BufSegPtr->BufSegs[BufSegPtr->Idx].Len -= (uint16)Len;
      BufSegPtr->BufSegs[BufSegPtr->Idx].DataPtr = &BufSegPtr->BufSegs[BufSegPtr->Idx].DataPtr[Len];
      Len = 0u;
    }
    else
    { /* release complete element */
      Len -= BufSegPtr->BufSegs[BufSegPtr->Idx].Len;
      BufSegPtr->BufSegs[BufSegPtr->Idx].Len = 0u;

      if ( (BufSegPtr->Idx + 1u) == SOAD_VBUF_SEG_SIZE_TOTAL )
      { /* wrap around necessary */
        BufSegPtr->Idx = 0u;
      }
      else
      { /* no wrap around necessary */
        BufSegPtr->Idx++;
      }
      BufSegPtr->Lvl--;
    }
  }
}

# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */

/**********************************************************************************************************************
 *  SoAd_VCompareSockAddr
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VCompareSockAddr(
                      P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) AddrA,
                      P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) AddrB,
                      boolean AllowWildcards)
{
  Std_ReturnType  retVal = E_NOT_OK;

  /* check input values */
  if ( (NULL_PTR != AddrA) && (NULL_PTR != AddrB) )
  {
    SoAd_DomainType tmpDomainA = AddrA->domain;

    if ( 0u == tmpDomainA )
    { /* domain of IpAddrA is not configured - assume domain is equal to IpAddrB */
      tmpDomainA = AddrB->domain;
    }
    /* check domain */
    if ( AddrB->domain == tmpDomainA )
    {
      if ( SOAD_AF_INET == tmpDomainA )
      { /* IPv4 */
        uint32 addrA = ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))AddrA)->addr[0];
        uint32 addrB = ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))AddrB)->addr[0];
        uint16 portA = ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))AddrA)->port;
        uint16 portB = ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))AddrB)->port;

        /* compare address */
        if ( (addrA == addrB) || ((SOAD_IPADDR_ANY == addrA) && (TRUE == AllowWildcards)) )
        { /* compare ports */
          if ( (portA == portB) || ((SOAD_PORT_ANY == portA) && (TRUE == AllowWildcards)) )
          {
            retVal = E_OK;
          }
        }
      }
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
      else if ( SOAD_AF_INET6 == tmpDomainA )
      { /* IPv6 */
        uint8 addrIdx;
        boolean ipIsWildcard = TRUE;
        boolean ipIsEqual = TRUE;
        uint16 portA = ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrA)->port;
        uint16 portB = ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrB)->port;

        /* check whether IP address is equal */
        for (addrIdx = 0; addrIdx < 4; addrIdx++)
        {
          if ( ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrA)->addr[addrIdx] !=
            ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrB)->addr[addrIdx] )
          { /* not equal */
            ipIsEqual = FALSE;
            break;
          }
        }

        /* check whether IP address is wildcard */
        for (addrIdx = 0; addrIdx < 4; addrIdx++)
        {
          if ( SOAD_IP6ADDR_ANY != ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrA)->addr[addrIdx] )
          { /* no wildcard */
            ipIsWildcard = FALSE;
            break;
          }
        }

        /* compare address */
        if ( TRUE == ipIsEqual )
        { /* compare ports */
          if ( (portA == portB) || ((SOAD_PORT_ANY == portA) && (TRUE == AllowWildcards)) )
          {
            retVal = E_OK;
          }
        }
        else if ( (TRUE == AllowWildcards) && (TRUE == ipIsWildcard) )
        { /* compare ports */
          if ( (portA == portB) || (SOAD_PORT_ANY == portA) )
          {
            retVal = E_OK;
          }
        }
        else
        { /* no address match */
          /* nothing to do here */
        }
      }
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
      else
      { /* unknown IP version */
        /* nothing to do here */
      }
    }
  }
  return retVal;
}
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VCompareIpAddr
 *********************************************************************************************************************/
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VCompareIpAddr(
                      SoAd_DomainType Domain,
                      P2CONST(SoAd_IpAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrA,
                      P2CONST(SoAd_IpAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrB)
{
  Std_ReturnType  retVal = E_NOT_OK;

  /* check input values */
  if ( (NULL_PTR != IpAddrA) && ((NULL_PTR != IpAddrB)) )
  {
    if ( SOAD_AF_INET == Domain )
    { /* IPv4 */
      uint32 addrA = ((P2CONST(SoAd_IpAddrInetType, AUTOMATIC, AUTOMATIC))IpAddrA)->addr[0];
      uint32 addrB = ((P2CONST(SoAd_IpAddrInetType, AUTOMATIC, AUTOMATIC))IpAddrB)->addr[0];

      /* compare address */
      if ( addrA == addrB )
      {
        retVal = E_OK;
      }
    }
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    else if ( SOAD_AF_INET6 == Domain )
    { /* IPv6 */
      uint8 addrIdx;

      retVal = E_OK;

      /* check whether IP address is equal */
      for (addrIdx = 0; addrIdx < 4; addrIdx++)
      {
        if ( ((P2CONST(SoAd_IpAddrInet6Type, AUTOMATIC, AUTOMATIC))IpAddrA)->addr[addrIdx] !=
          ((P2CONST(SoAd_IpAddrInet6Type, AUTOMATIC, AUTOMATIC))IpAddrB)->addr[addrIdx] )
        { /* not equal */
          retVal = E_NOT_OK;
          break;
        }
      }
    }
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    else
    { /* unknown IP version */
      /* nothing to do here */
    }
  }
  return retVal;
}
#else
/**********************************************************************************************************************
 *  SoAd_VCompareIpAddr
 *********************************************************************************************************************/
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SOAD_CODE) SoAd_VCompareIpAddr(
                      P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrA,
                      P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrB,
                      boolean AllowWildcards)
{
  Std_ReturnType  retVal = E_NOT_OK;

  /* check input values */
  if ( (NULL_PTR != IpAddrA) && ((NULL_PTR != IpAddrB)) )
  {
    SoAd_DomainType tmpDomainA = IpAddrA->domain;

    if ( 0u == tmpDomainA )
    { /* domain of IpAddrA is not configured - assume domain is equal to IpAddrB */
      tmpDomainA = IpAddrB->domain;
    }
    /* check domain */
    if ( IpAddrB->domain == tmpDomainA )
    {
      if ( SOAD_AF_INET == tmpDomainA )
      { /* IPv4 */
        uint32 addrA = ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))IpAddrA)->addr[0];
        uint32 addrB = ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))IpAddrB)->addr[0];

        /* compare address */
        if ( (addrA == addrB) || ((SOAD_IPADDR_ANY == addrA) && (TRUE == AllowWildcards)) )
        {
          retVal = E_OK;
        }
      }
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
      else if ( SOAD_AF_INET6 == tmpDomainA )
      { /* IPv6 */
        uint8 addrIdx;

        retVal = E_OK;

        /* check wether IP address is equal */
        for (addrIdx = 0; addrIdx < 4; addrIdx++)
        {
          if ( ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))IpAddrA)->addr[addrIdx] !=
            ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))IpAddrB)->addr[addrIdx] )
          { /* not equal */
            retVal = E_NOT_OK;
            break;
          }
        }

        if ( (E_OK != retVal) && (TRUE == AllowWildcards) )
        {
          retVal = E_OK;

          /* check wether IP address is wildcarad */
          for (addrIdx = 0; addrIdx < 4; addrIdx++)
          {
            if ( SOAD_IP6ADDR_ANY != ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))IpAddrA)->addr[addrIdx] )
            { /* no wildcard */
              retVal = E_NOT_OK;
              break;
            }
          }
        }
      }
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
      else
      { /* unknown IP version */
        /* nothing to do here */
      }
    }
  }
  return retVal;
}
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

#if ( defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) )
# if ( defined(SOAD_VROUT_GROUP_TX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VCheckAnyRoutGrpOnPduRouteDestEnabled
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_147 */ /* MD_MSR_14.7 */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(boolean, SOAD_CODE) SoAd_VCheckAnyRoutGrpOnPduRouteDestEnabled(
                      P2CONST(SoAd_PduRouteDestType, AUTOMATIC, SOAD_APPL_DATA) PduRouteDest)
{
  SoAd_RoutingGroupIdType grpIdx;
  boolean retVal = FALSE;

  if ( PduRouteDest->RoutGrpNum > 0u )
  { /* at least one routing group is configured */
    for ( grpIdx = 0u; grpIdx < PduRouteDest->RoutGrpNum; grpIdx++ )
    {
      if ( 0u != (*PduRouteDest->RoutGrpStateColPtr[grpIdx] & SOAD_ROUT_GRP_BIT_PATTERN_ENABLED) )
      { /* at least one routing group is enabled - forward PDU */
        retVal = TRUE;
        break;
      }
    }
  }
  else
  { /* no routing group configured - forward PDU */
    retVal = TRUE;
  }
  return retVal;
}
/* PRQA L:MSR_147 */
/* PRQA L:MSR_STMIF */
# endif /* defined(SOAD_VROUT_GROUP_TX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_TX_ENABLED) */

# if ( defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VCheckAnyRoutGrpOnSockRouteDestEnabled
 *********************************************************************************************************************/
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(boolean, SOAD_CODE) SoAd_VCheckAnyRoutGrpOnSockRouteDestEnabled(uint16 SockRouteIdx)
{
  boolean retVal = FALSE;
  SoAd_RoutingGroupIdType grpIdNum = SoAd_SockRoutes(SockRouteIdx).SockRouteDest.RoutGrpIdNum;

  if ( 0u < grpIdNum )
  { /* at least one routing group is configured */
    while ( 0u < grpIdNum )
    {
      SoAd_RoutingGroupIdType grpId;
      SoAd_RoutingGroupIdxType grpIdx;
      uint16 sockRouteNum = 0;

      grpIdNum--;
      grpId = SoAd_SockRoutes(SockRouteIdx).SockRouteDest.RoutGrpIdColPtr[grpIdNum];
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      SOAD_GetRouteGrpIdxCheckDetError(grpIdx, grpId, SOAD_API_ID_VCHECK_ROUT_GRP_ON_SOCK_ROUTE_ENABLED);

      if ( SOAD_INV_ROUT_GRP_IDX != grpIdx )
      {
        sockRouteNum = SoAd_RouteGrpIdx2SocketRouteCol(grpIdx).IdNum;
      }

      /* find routing group state for socket route */
      while ( 0u < sockRouteNum )
      {
        uint16 sockRouteIdx;

        sockRouteNum--;
        sockRouteIdx = SoAd_RouteGrpIdx2SocketRouteCol(grpIdx).IdColPtr[sockRouteNum];

        if ( sockRouteIdx == SockRouteIdx )
        { /* socket route found */
          if ( 0u != (*SoAd_RouteGrpIdx2SocketRouteCol(grpIdx).StateColPtr[sockRouteNum] &
            SOAD_ROUT_GRP_BIT_PATTERN_ENABLED) )
          { /* at least one routing group is enabled - forward PDU */
            retVal = TRUE;
            break;
          }
        }
      }
    }
  }
  else
  { /* no routing group configured - forward PDU */
    retVal = TRUE;
  }
  return retVal;
}
/* PRQA L:MSR_STMIF */
# endif /*  defined(SOAD_VROUT_GROUP_RX_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_RX_ENABLED) */
#endif /* defined(SOAD_VROUT_GROUP_ENABLED) && ( STD_ON == SOAD_VROUT_GROUP_ENABLED) */

/**********************************************************************************************************************
 *  SoAd_VCheckForWildcards
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_VCheckForWildcards(
                          P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) AddrCheck,
                          P2VAR(boolean, AUTOMATIC, SOAD_APPL_DATA) IpAddrIsAny,
                          P2VAR(boolean, AUTOMATIC, SOAD_APPL_DATA) PortIsAny)
{
  SoAd_DomainType tmpDomain;

  /* check AddrCheck */
  if ( NULL_PTR != AddrCheck )
  {
    tmpDomain = AddrCheck->domain;

    if ( SOAD_AF_UNSPEC == tmpDomain )
    { /* domain is not set */
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
      /* assume IPv6 */
      tmpDomain = SOAD_AF_INET6;
#else
      /* assume IPv4 */
      tmpDomain = SOAD_AF_INET;
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    }

    if ( SOAD_AF_INET == tmpDomain )
    { /* IPv4 */
      if ( SOAD_IPADDR_ANY == ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))AddrCheck)->addr[0] )
      {
        *IpAddrIsAny = TRUE;
      }
      else
      {
        *IpAddrIsAny = FALSE;
      }

      if ( SOAD_PORT_ANY == ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))AddrCheck)->port )
      {
        *PortIsAny = TRUE;
      }
      else
      {
        *PortIsAny = FALSE;
      }
    }
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    else if ( SOAD_AF_INET6 == tmpDomain )
    { /* IPv6 */
      if ( (SOAD_IP6ADDR_ANY == ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrCheck)->addr[0]) &&
        (SOAD_IP6ADDR_ANY == ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrCheck)->addr[1]) &&
        (SOAD_IP6ADDR_ANY == ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrCheck)->addr[2]) &&
        (SOAD_IP6ADDR_ANY == ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrCheck)->addr[3]) )
      {
        *IpAddrIsAny = TRUE;
      }
      else
      {
        *IpAddrIsAny = FALSE;
      }

      if ( SOAD_PORT_ANY == ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))AddrCheck)->port )
      {
        *PortIsAny = TRUE;
      }
      else
      {
        *PortIsAny = FALSE;
      }
    }
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    else
    { /* unknown IP version */
      /* ignore */
    }
  }
  else
  { /* no remote address is configured */
    *IpAddrIsAny = TRUE;
    *PortIsAny   = TRUE;
  }
}

/**********************************************************************************************************************
 *  SoAd_VGetSoConIdByBestMatchAlg
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6060 MSR_STPAR */ /* MD_MSR_STPAR */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VGetSoConIdByBestMatchAlg(
                          P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) DynAddr,
                          SoAd_SoConIdxType SoConIdxStart,
                          SoAd_SoConIdxType SoConIdxMax,
                          SoAd_SoConModeFilterType SoConModeFilter,
                          boolean NoSockRouteFilter,
                          P2VAR(SoAd_SoConIdxType, AUTOMATIC, SOAD_APPL_DATA) SoConIdxBestMatch)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 bestMatchPrio = 0u;
  SoAd_SoConIdxType soConIdx = SoConIdxStart;

  while ( soConIdx <= SoConIdxMax )
  {
    SoAd_DomainType tmpDomain;
    uint8 bestMatchPrioTmp = 0u;

    if ( SOAD_SOCON_FILTER_ON_OFF == SoConModeFilter )
    { /* filter socket connection if state is SOAD_SOCON_ONLINE or SOAD_SOCON_OFFLINE */
      if ( SOAD_SOCON_RECONNECT != SoAd_SockConIdx2State(soConIdx) )
      { /* socket connection state is not SOAD_SOCON_RECONNECT */
        /* skip socket connection */
        soConIdx++;
        continue; /* PRQA S 0770 */ /* MD_SoAd_14.5 */
      }
    }

    if ( TRUE == NoSockRouteFilter )
    { /* filter socket connection if no socket route is configured */
#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
      if ( (SoAd_IsSockRoutePresent()) && (SoAd_SockConIdx2SockRouteCol(soConIdx).SockRouteIdxNum == 0) )
      { /* no socket route is configured */
        /* skip socket connection */
        soConIdx++;
        continue; /* PRQA S 0770 */ /* MD_SoAd_14.5 */
      }
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */
    }

    if ( 0u < (SoAd_SockConIdx2RemAddrState(soConIdx) & SOAD_SOCON_MASK_NOT) )
    { /* remote address is NOT_SET */
      /* skip socket connection */
      soConIdx++;
      continue; /* PRQA S 0770 */ /* MD_SoAd_14.5 */
    }

    tmpDomain = SoAd_SockConIdx2RemSockDyn(soConIdx).domain;

    if ( 0u == tmpDomain )
    { /* domain is not set - assume domain is equal to DynAddr */
      tmpDomain = DynAddr->domain;
    }

    if ( tmpDomain == DynAddr->domain )
    {
      if ( DynAddr->domain == SOAD_AF_INET )
      { /* IPv4 */
        uint32 dynAddr = ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))DynAddr)->addr[0];
        uint16 dynPort = ((P2CONST(SoAd_SockAddrInetType, AUTOMATIC, AUTOMATIC))DynAddr)->port;

        if ( (dynAddr == SoAd_SockConIdx2RemSockDyn(soConIdx).addr[0]) &&
          (dynPort == SoAd_SockConIdx2RemSockDyn(soConIdx).port) )
        { /* IP and port match */
          bestMatchPrioTmp = 4u;
        }
        else if ( (dynAddr == SoAd_SockConIdx2RemSockDyn(soConIdx).addr[0]) &&
          (SOAD_PORT_ANY == SoAd_SockConIdx2RemSockDyn(soConIdx).port) )
        { /* IP match and port is wildcard */
          bestMatchPrioTmp = 3u;
        }
        else if ( (SOAD_IPADDR_ANY == SoAd_SockConIdx2RemSockDyn(soConIdx).addr[0]) &&
          (dynPort == SoAd_SockConIdx2RemSockDyn(soConIdx).port) )
        { /* IP is wildcard and port match */
          bestMatchPrioTmp = 2u;
        }
        else if ( (SOAD_IPADDR_ANY == SoAd_SockConIdx2RemSockDyn(soConIdx).addr[0]) &&
          (SOAD_PORT_ANY == SoAd_SockConIdx2RemSockDyn(soConIdx).port))
        { /* IP and port are wildcards */
          bestMatchPrioTmp = 1u;
        }
        else
        { /* no match */
          /* nothing to do */
        }
      }
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
      else
      { /* IPv6 */
        uint8 addrIdx;
        boolean ipIsWildcard = TRUE;
        boolean ipIsEqual = TRUE;
        uint16 dynPort = ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))DynAddr)->port;

        /* check wether IP address is equal */
        for (addrIdx = 0; addrIdx < 4; addrIdx++)
        {
          if ( ((P2CONST(SoAd_SockAddrInet6Type, AUTOMATIC, AUTOMATIC))DynAddr)->addr[addrIdx] !=
             SoAd_SockConIdx2RemSockDyn(soConIdx).addr[addrIdx] )
          { /* not equal */
            ipIsEqual = FALSE;
            break;
          }
        }

        /* check wether IP address is wildcarad */
        for (addrIdx = 0; addrIdx < 4; addrIdx++)
        {
          if ( SOAD_IP6ADDR_ANY != SoAd_SockConIdx2RemSockDyn(soConIdx).addr[addrIdx] )
          { /* no wildcard */
            ipIsWildcard = FALSE;
            break;
          }
        }

        if ( (TRUE == ipIsEqual) && (dynPort == SoAd_SockConIdx2RemSockDyn(soConIdx).port) )
        { /* IP and port match */
          bestMatchPrioTmp = 4u;
        }
        else if ( (TRUE == ipIsEqual) && (SOAD_PORT_ANY == SoAd_SockConIdx2RemSockDyn(soConIdx).port) )
        { /* IP match and port is wildcard */
          bestMatchPrioTmp = 3u;
        }
        else if ( (TRUE == ipIsWildcard) && (dynPort == SoAd_SockConIdx2RemSockDyn(soConIdx).port) )
        { /* IP is wildcard and port match */
          bestMatchPrioTmp = 2u;
        }
        else if ( (TRUE == ipIsWildcard) && (SOAD_PORT_ANY == SoAd_SockConIdx2RemSockDyn(soConIdx).port) )
        { /* IP and port are wildcards */
          bestMatchPrioTmp = 1u;
        }
        else
        { /* no match */
          /* nothing to do */
        }
      }
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    }
    if ( bestMatchPrioTmp > bestMatchPrio )
    {
      bestMatchPrio = bestMatchPrioTmp;
      *SoConIdxBestMatch = soConIdx;
      if ( 4u == bestMatchPrio )
      { /* best match found */
        break;
      }
    }
    soConIdx++;
  }

  if ( 0u < bestMatchPrio )
  {
    retVal = E_OK;
  }

  return retVal;
}
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STPAR */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VGetSockIdxBySocketId
 *********************************************************************************************************************/
STATIC FUNC(SoAd_SockIdxType, SOAD_CODE) SoAd_VGetSockIdxBySocketId(SoAd_SocketIdType SocketId)
{
  /* PRQA S 0781 1 */ /* MD_SoAd_5.6 */
  SoAd_SockIdxType sockIdx = SoAd_TcpIpSocketCnt();

  while ( 0u < sockIdx )
  {
    sockIdx--;
    if ( SoAd_SockIdx2SocketId(sockIdx) == SocketId )
    {
      return sockIdx;
    }
  }
  return SOAD_INV_SOCK_IDX; /* PRQA S 0277 */ /* MD_SoAd_3.1 */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  SoAd_VResetIpAddr
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VResetIpAddr(SoAd_SoConIdxType SoConIdx)
{
  if ( NULL_PTR != SoAd_SockCons(SoConIdx).RemSockPtr )
  { /* reset to configured remote socket */
    SoAd_VCopyIpAddr((SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(SoConIdx),
      SoAd_SockCons(SoConIdx).RemSockPtr, TRUE);
  }
  else
  { /* no remote socket is configured */
    SoAd_VResetIpAddr2Unspec((SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(SoConIdx));
  }
  SoAd_SockConIdx2RemAddrState(SoConIdx) = SoAd_SockCons(SoConIdx).RemAddrState;
}

/**********************************************************************************************************************
 *  SoAd_VResetIpAddr2Unspec
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VResetIpAddr2Unspec(P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) IpAddrPtr)
{
  if ( NULL_PTR != IpAddrPtr )
  { /* pointer is valid */
    IpAddrPtr->domain = SOAD_AF_UNSPEC;
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON != SOAD_VIPV6_ENABLED) )
    ((SoAd_SockAddrInetType*)IpAddrPtr)->port    = SOAD_PORT_ANY;
    ((SoAd_SockAddrInetType*)IpAddrPtr)->addr[0] = SOAD_IPADDR_ANY;
#else
    ((SoAd_SockAddrInet6Type*)IpAddrPtr)->port    = SOAD_PORT_ANY;
    ((SoAd_SockAddrInet6Type*)IpAddrPtr)->addr[0] = SOAD_IP6ADDR_ANY;
    ((SoAd_SockAddrInet6Type*)IpAddrPtr)->addr[1] = SOAD_IP6ADDR_ANY;
    ((SoAd_SockAddrInet6Type*)IpAddrPtr)->addr[2] = SOAD_IP6ADDR_ANY;
    ((SoAd_SockAddrInet6Type*)IpAddrPtr)->addr[3] = SOAD_IP6ADDR_ANY;
#endif
  }
}

/**********************************************************************************************************************
 *  SoAd_VCopyIpAddr
 *********************************************************************************************************************/
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(void, SOAD_CODE) SoAd_VCopyIpAddr(
                      P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) TgtIpAddr,
                      P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) SrcIpAddr,
                      boolean OverwriteAll)
{
  /* This function assumes that there is enough memory reserved to overwrite an IPv4 address with an IPv6 address */
  if ( (NULL_PTR != SrcIpAddr) && (NULL_PTR != TgtIpAddr) )
  { /* valid pointer */
    if ( SOAD_AF_UNSPEC == SrcIpAddr->domain )
    { /* unspecific domain */
      ((SoAd_SockAddrInetXType*)TgtIpAddr)->domain = SOAD_AF_UNSPEC;
      if ( (TRUE == OverwriteAll) || ( SOAD_PORT_ANY == ((SoAd_SockAddrInetXType*)TgtIpAddr)->port ) )
      {
        ((SoAd_SockAddrInetXType*)TgtIpAddr)->port = (SOAD_A_P2CONST(SoAd_SockAddrInetXType)SrcIpAddr)->port;
      }
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
      if ( (TRUE == OverwriteAll) ||
        ((SOAD_IP6ADDR_ANY == ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[0]) &&
          (SOAD_IP6ADDR_ANY == ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[1]) &&
          (SOAD_IP6ADDR_ANY == ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[2]) &&
          (SOAD_IP6ADDR_ANY == ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[3])) )
      {
        ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[0] = SOAD_IP6ADDR_ANY;
        ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[1] = SOAD_IP6ADDR_ANY;
        ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[2] = SOAD_IP6ADDR_ANY;
        ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[3] = SOAD_IP6ADDR_ANY;
      }
#else
      if ( (TRUE == OverwriteAll) || (SOAD_IPADDR_ANY == ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[0]) )
      {
        ((SoAd_SockAddrInetXType*)TgtIpAddr)->addr[0] = SOAD_IPADDR_ANY;
      }
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    }
    else if ( SOAD_AF_INET == SrcIpAddr->domain )
    { /* IPv4 */
      ((SoAd_SockAddrInetType*)TgtIpAddr)->domain = (SOAD_A_P2CONST(SoAd_SockAddrInetType)SrcIpAddr)->domain;
      if ( (TRUE == OverwriteAll) || ( SOAD_PORT_ANY == ((SoAd_SockAddrInetType*)TgtIpAddr)->port ) )
      {
        ((SoAd_SockAddrInetType*)TgtIpAddr)->port = (SOAD_A_P2CONST(SoAd_SockAddrInetType)SrcIpAddr)->port;
      }
      if ( (TRUE == OverwriteAll) || (SOAD_IPADDR_ANY == ((SoAd_SockAddrInetType*)TgtIpAddr)->addr[0]) )
      {
        ((SoAd_SockAddrInetType*)TgtIpAddr)->addr[0] = (SOAD_A_P2CONST(SoAd_SockAddrInetType)SrcIpAddr)->addr[0];
      }
    }
#if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
    else if ( SOAD_AF_INET6 == SrcIpAddr->domain )
    { /* IPv6 */
      ((SoAd_SockAddrInet6Type*)TgtIpAddr)->domain  = (SOAD_A_P2CONST(SoAd_SockAddrInet6Type)SrcIpAddr)->domain;
      if ( (TRUE == OverwriteAll) || ( SOAD_PORT_ANY == ((SoAd_SockAddrInet6Type*)TgtIpAddr)->port ) )
      {
        ((SoAd_SockAddrInet6Type*)TgtIpAddr)->port    = (SOAD_A_P2CONST(SoAd_SockAddrInet6Type)SrcIpAddr)->port;
      }
      if ( (TRUE == OverwriteAll) ||
        ((SOAD_IP6ADDR_ANY == ((SoAd_SockAddrInet6Type*)TgtIpAddr)->addr[0]) &&
          (SOAD_IP6ADDR_ANY == ((SoAd_SockAddrInet6Type*)TgtIpAddr)->addr[1]) &&
          (SOAD_IP6ADDR_ANY == ((SoAd_SockAddrInet6Type*)TgtIpAddr)->addr[2]) &&
          (SOAD_IP6ADDR_ANY == ((SoAd_SockAddrInet6Type*)TgtIpAddr)->addr[3])) )
      {
        ((SoAd_SockAddrInet6Type*)TgtIpAddr)->addr[0] = (SOAD_A_P2CONST(SoAd_SockAddrInet6Type)SrcIpAddr)->addr[0];
        ((SoAd_SockAddrInet6Type*)TgtIpAddr)->addr[1] = (SOAD_A_P2CONST(SoAd_SockAddrInet6Type)SrcIpAddr)->addr[1];
        ((SoAd_SockAddrInet6Type*)TgtIpAddr)->addr[2] = (SOAD_A_P2CONST(SoAd_SockAddrInet6Type)SrcIpAddr)->addr[2];
        ((SoAd_SockAddrInet6Type*)TgtIpAddr)->addr[3] = (SOAD_A_P2CONST(SoAd_SockAddrInet6Type)SrcIpAddr)->addr[3];
      }
    }
#endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
    else
    { /* unknown IP version */
      /* ignore */
    }
  }
}
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  SoAd_VCheckAndSetRemoteAddr
 *********************************************************************************************************************/
/* PRQA S 0771 SoAd_146 */ /* MD_SoAd_14.6 */
STATIC FUNC(Std_ReturnType, SOAD_CODE) SoAd_VCheckAndSetRemoteAddr(SoAd_SoConIdxType SoConIdx,
                      P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_DATA) RemoteAddrPtr)
{
  Std_ReturnType retVal = E_OK;

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
  SoAd_LocalAddrIdType addrId = SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId;

  if ( SoAd_LocalAddr(addrId).AddressType == SOAD_ADDRESS_TYPE_UNICAST )
  { /* unicast addresses can be used for transmission */
    /* check remote address to prevent transmissions to local address */
    if ( E_OK == SoAd_VCompareIpAddr(RemoteAddrPtr->domain,
        (SOAD_A_P2CONST(SoAd_SockAddrInetXType)RemoteAddrPtr)->addr,
        SOAD_A_P2CONST(SoAd_IpAddrType)SoAd_AddrId2LocalIpAddrDyn(addrId).addr) )
    { /* remote address is equal to local address */
      retVal = E_NOT_OK;
    }
  }
  else
  { /* multicast address cannot be used for transmission */
    /* allow setting remote address since some upper layer may use it to open a socket connection */
  }
#else
  uint8 tcpIpCtrl = SoAd_AddrId2TcpIpCtrl(SoAd_SockCons(SoConIdx).SockConGrpPtr->LocIpAddrId);
  uint8 tcpIpCtrlIdx = SoAd_TcpIpCtrl(tcpIpCtrl).AddrIdListNum;

  /* compare with all affected local unicast addresses */
  while ( 0u < tcpIpCtrlIdx )
  {
    SoAd_SockAddrInetXType localIpAddr;
    SoAd_SockAddrInetXType defaultRouter;
    uint8 netMask;

    tcpIpCtrlIdx--;
    /* get local IP address */
    if ( E_OK == TcpIp_GetIpAddr(SoAd_TcpIpCtrl(tcpIpCtrl).AddrIdListPtr[tcpIpCtrlIdx],
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&localIpAddr,
        &netMask,
        (P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC))&defaultRouter) )
    { /* local IP address retrieved */
      /* compare remote address to be set to local IP address */
      if ( E_OK == SoAd_VCompareIpAddr((SoAd_SockAddrType*)&localIpAddr, RemoteAddrPtr, FALSE) )
      { /* equal to local address */
        retVal = E_NOT_OK;
        break;
      }
    }
    else
    { /* local IP address not retrieved */
      retVal = E_NOT_OK;
      break;
    }
  }
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

  if ( E_OK == retVal )
  {
    boolean addrIsAny = FALSE;
    boolean portIsAny = FALSE;

    /* set remote address */
    SoAd_VCopyIpAddr((SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(SoConIdx), RemoteAddrPtr, TRUE);
    SoAd_VCheckForWildcards((SoAd_SockAddrType*)&SoAd_SockConIdx2RemSockDyn(SoConIdx), &addrIsAny,
      &portIsAny);
    if ( TRUE == addrIsAny )
    {
      SoAd_SockConIdx2RemAddrState(SoConIdx) =
        (uint8)(SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_IPADDR);
    }
    else
    {
      SoAd_SockConIdx2RemAddrState(SoConIdx) =
        (uint8)(SOAD_SOCON_IP_SET_PORT_ANY & SOAD_SOCON_MASK_IPADDR);
    }
    if ( TRUE == portIsAny )
    {
      SoAd_SockConIdx2RemAddrState(SoConIdx) |=
        (uint8)(SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_PORT);
    }
    else
    {
      SoAd_SockConIdx2RemAddrState(SoConIdx) |=
        (uint8)(SOAD_SOCON_IP_SET_PORT_SET & SOAD_SOCON_MASK_PORT);
    }
  }

  return retVal;
}
/* PRQA L:SoAd_146 */

#if ( defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VConvertAsrSockAddr2BsdSockAddr
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VConvertAsrSockAddr2BsdSockAddr(
                        P2VAR(struct sockaddr, SOAD_APPL_DATA, SOAD_APPL_DATA) BsdSockAddrPtr,
                        P2CONST(SoAd_SockAddrType, SOAD_APPL_DATA, SOAD_APPL_DATA) AsrSockAddrPtr)
{
  if ( SOAD_AF_INET == AsrSockAddrPtr->domain )
  {
    ((struct sockaddr_in*)BsdSockAddrPtr)->sin_family = AF_INET;
    ((struct sockaddr_in*)BsdSockAddrPtr)->sin_port = ((SoAd_SockAddrInetType*)AsrSockAddrPtr)->port;
    ((struct sockaddr_in*)BsdSockAddrPtr)->sin_addr.s_addr = *((SoAd_SockAddrInetType*)AsrSockAddrPtr)->addr;
  }
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
  else
  {
    ((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_family = AF_INET6;
    ((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_port = ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->port;
    ((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_flowinfo = 0u;

    *((uint32*)&((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_addr.s6_addr[0]) =
      ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->addr[0];
    *((uint32*)&((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_addr.s6_addr[4]) =
      ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->addr[1];
    *((uint32*)&((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_addr.s6_addr[8]) =
      ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->addr[2];
    *((uint32*)&((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_addr.s6_addr[12]) =
      ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->addr[3];
  }
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
}

/**********************************************************************************************************************
 *  SoAd_VConvertBsdSockAddr2AsrSockAddr
 *********************************************************************************************************************/
STATIC FUNC(void, SOAD_CODE) SoAd_VConvertBsdSockAddr2AsrSockAddr(
                        P2VAR(SoAd_SockAddrType, SOAD_APPL_DATA, SOAD_APPL_DATA) AsrSockAddrPtr,
                        P2CONST(struct sockaddr, SOAD_APPL_DATA, SOAD_APPL_DATA) BsdSockAddrPtr)
{
  if ( AF_INET == BsdSockAddrPtr->sa_family )
  {
    ((SoAd_SockAddrInetType*)AsrSockAddrPtr)->domain = SOAD_AF_INET;
    ((SoAd_SockAddrInetType*)AsrSockAddrPtr)->port = ((struct sockaddr_in*)BsdSockAddrPtr)->sin_port;
    ((SoAd_SockAddrInetType*)AsrSockAddrPtr)->addr[0] = ((struct sockaddr_in*)BsdSockAddrPtr)->sin_addr.s_addr;
  }
# if ( defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) )
  else
  {
    ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->domain = SOAD_AF_INET6;
    ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->port = ((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_port;
    ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->addr[0] =
      *((uint32*)&((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_addr.s6_addr[0]);
    ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->addr[1] =
      *((uint32*)&((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_addr.s6_addr[4]);
    ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->addr[2] =
      *((uint32*)&((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_addr.s6_addr[8]);
    ((SoAd_SockAddrInet6Type*)AsrSockAddrPtr)->addr[3] =
      *((uint32*)&((struct sockaddr_in6*)BsdSockAddrPtr)->sin6_addr.s6_addr[12]);
  }
# endif /* defined(SOAD_VIPV6_ENABLED) && (STD_ON == SOAD_VIPV6_ENABLED) */
}
#endif /* defined(SOAD_VSOCKET_BSD_API_ENABLED) && (STD_ON == SOAD_VSOCKET_BSD_API_ENABLED) */

#if ( defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) )
# if ( defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) )
#  if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VCopyBufSeg2Buf
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_VCopyBufSeg2Buf(P2VAR(uint8, SOAD_APPL_DATA, SOAD_APPL_DATA) BufPtr,
                                        P2CONST(SoAd_BufSegMgtType, SOAD_APPL_DATA, SOAD_APPL_DATA) BufSegPtr,
                                        uint32 BufLen, uint32 StartPos)
{
  uint32 bytesToCopy;
  uint32 bytesCopied = 0u;
  uint16 bufSegIdx = BufSegPtr->Idx;

  /* get start position */
  while ( 0u < StartPos )
  {
    if ( BufSegPtr->BufSegs[bufSegIdx].Len < StartPos )
    { /* start position in next buffer segment */
      StartPos -= BufSegPtr->BufSegs[bufSegIdx].Len;
      if ( (bufSegIdx + 1u) == SOAD_VBUF_SEG_SIZE_TOTAL )
      { /* wrap around */
        bufSegIdx = 0u;
      }
      else
      { /* no wrap around */
        bufSegIdx++;
      }
    }
    else
    { /* start position in current segment */
      break;
    }
  }

  /* copy to target buffer */
  bytesToCopy = (uint32)(BufSegPtr->BufSegs[bufSegIdx].Len - StartPos);
  if ( bytesToCopy < BufLen )
  { /* more data shall be copied than available in current segment */
    /* copy first segment */
    IpBase_Copy((IpBase_CopyDataType*)&BufPtr[0],
      (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&BufSegPtr->BufSegs[bufSegIdx].DataPtr[StartPos],
      bytesToCopy);
    BufLen -= bytesToCopy;
    bytesCopied += bytesToCopy;

    /* copy remaining segments */
    while ( 0u < BufLen )
    {
      /* get index of segment */
      if ( (bufSegIdx + 1u) == SOAD_VBUF_SEG_SIZE_TOTAL )
      { /* wrap around */
        bufSegIdx = 0u;
      }
      else
      { /* no wrap around */
        bufSegIdx++;
      }

      /* get remaining data size */
      if ( BufSegPtr->BufSegs[bufSegIdx].Len < BufLen )
      {
        bytesToCopy = BufSegPtr->BufSegs[bufSegIdx].Len;
      }
      else
      {
        bytesToCopy = BufLen;
      }

      IpBase_Copy((IpBase_CopyDataType*)&BufPtr[bytesCopied],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&BufSegPtr->BufSegs[bufSegIdx].DataPtr[0],
        bytesToCopy);
      BufLen -= bytesToCopy;
      bytesCopied += bytesToCopy;
    }
  }
  else
  { /* segment is bigger than data to be copied */
    IpBase_Copy((IpBase_CopyDataType*)&BufPtr[0],
      (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&BufSegPtr->BufSegs[bufSegIdx].DataPtr[StartPos], BufLen);
  }
}
#  endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */
# endif /* defined(SOAD_VTCP_USED) && (STD_ON == SOAD_VTCP_USED) */
#endif /* defined(SOAD_VSOCKET_ROUTES) && (STD_ON == SOAD_VSOCKET_ROUTES) */

#if ( defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) )
/**********************************************************************************************************************
 *  SoAd_VCopyPduHdr2Buf
 *********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_VCopyPduHdr2Buf(SoAd_PduHdrIdType PduHeaderId,
                                  SoAd_PduHdrLenType PduHeaderLen,
                                  P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
                                  PduLengthType Offset,
                                  PduLengthType Length)
{
  PduLengthType pduHdrIdx = Offset;
  PduLengthType pduHdrEndIdx = Offset + Length;

  if ( (SOAD_PDU_HDR_SIZE <= Length) && ( 0u == Offset) )
  { /* copy entire PDU Header */
    BufPtr[0] = (uint8)(PduHeaderId >> 24);
    BufPtr[1] = (uint8)(PduHeaderId >> 16);
    BufPtr[2] = (uint8)(PduHeaderId >> 8);
    BufPtr[3] = (uint8)(PduHeaderId);
    BufPtr[4] = (uint8)(PduHeaderLen >> 24);
    BufPtr[5] = (uint8)(PduHeaderLen >> 16);
    BufPtr[6] = (uint8)(PduHeaderLen >> 8);
    BufPtr[7] = (uint8)(PduHeaderLen);
  }
  else
  { /* copy PDU Header segment */
    uint8 pduHdrBuf[SOAD_PDU_HDR_SIZE];

    /* create local PDU Header buffer */
    pduHdrBuf[0] = (uint8)(PduHeaderId >> 24);
    pduHdrBuf[1] = (uint8)(PduHeaderId >> 16);
    pduHdrBuf[2] = (uint8)(PduHeaderId >> 8);
    pduHdrBuf[3] = (uint8)(PduHeaderId);
    pduHdrBuf[4] = (uint8)(PduHeaderLen >> 24);
    pduHdrBuf[5] = (uint8)(PduHeaderLen >> 16);
    pduHdrBuf[6] = (uint8)(PduHeaderLen >> 8);
    pduHdrBuf[7] = (uint8)(PduHeaderLen);

    /* copy segment */
    while ( pduHdrIdx < pduHdrEndIdx )
    {
      BufPtr[pduHdrIdx - Offset] = pduHdrBuf[pduHdrIdx];
      pduHdrIdx++;
    }
  }
}
#endif /* defined(SOAD_VPDU_HDR_ENABLED) && (STD_ON == SOAD_VPDU_HDR_ENABLED) */

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA L:TYPE_CAST */

/* module specific MISRA deviations:
  MD_SoAd_3.1:
      Reason:     Signed unsigned mismatch for data type independence
      Risk:       Misinterpretation of data.
      Prevention: Covered by code review.
  MD_SoAd_5.6:
      Reason:     Same name used to improve readability.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_SoAd_6.3:
      Reason:     Platform specific type.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_SoAd_8.8:
     Reason:      Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:        No risk.
     Prevention:  Not required.
  MD_SoAd_11.4:
      Reason:     Type cast due to hardware oriented programming
      Risk:       Misinterpretation of data.
      Prevention: Covered by code review.
  MD_SoAd_13.7_CFG:
      Reason:     Condition depends on configuration.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_SoAd_13.7_SUB:
      Reason:     Value is changed in sub routine.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_SoAd_14.5:
      Reason:     Continue statement used for readability and performance reasons.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_SoAd_14.6:
      Reason:     Multiple break statements due to runtime optimization.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_SoAd_16.7:
      Reason:     No pointer to const due to modification in a called function or required by specification.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_SoAd_17.4:
      Reason:     Code optimization, array indexing more complex in this case.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_SoAd_20.5:
      Reason:     errno is a facility of C, but which in practice is poorly defined by the standard.
      Risk:       No risk.
      Prevention: Used with BSD Socket API only.
  MD_SoAd_21.1:
      Reason:     Wraparound past zero or index out of bounds prevented by complex mechanism.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_SoAd_3206:
      Reason:     API parameter is only used in some configurations or is required by specification but currently not
                  supported.
      Risk:       There is no risk.
      Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: SoAd.c
 *********************************************************************************************************************/
