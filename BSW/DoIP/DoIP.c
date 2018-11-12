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
 *         File:  DoIP.c
 *      Project:  TcpIp-Stack
 *       Module:  Diagnostic over Internet Protocol
 *    Generator:  -
 *
 *  Description:  Implementation Diagnostic over IP
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

#include "DoIP.h" /* includes SoAd.h and ComStack_Types.h */
#include "DoIP_Priv.h"
#include "DoIP_Cbk.h"
#include "IpBase.h"
#include "PduR_DoIP.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check consistency of source and header file. */
#if ( (DOIP_SW_MAJOR_VERSION != 3u) || (DOIP_SW_MINOR_VERSION != 1u) || (DOIP_SW_PATCH_VERSION != 0u) )
# error "DoIP.c: Source and Header file are inconsistent!"
#endif

/* Check configuration variant for building the library */
#if ( (defined(V_EXTENDED_BUILD_LIB_CHECK)) && (DOIP_CONFIGURATION_VARIANT_PRECOMPILE == DOIP_CONFIGURATION_VARIANT) )
# error "DoIP.c: Switch configuration variant to link-time or post-build for library build!"
#endif /* (defined(V_EXTENDED_BUILD_LIB_CHECK)) && (DOIP_CONFIG_VARIANT_PRECOMPILE == DOIP_CONFIGURATION_VARIANT) */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC                              static
#endif

#define DOIP_GEN_HDR_LEN_BYTE                8u

#if ( defined(DOIP_VIN_GID_SYNC) && (STD_ON == DOIP_VIN_GID_SYNC) )
# define DOIP_ACK_VEHICLE_IDENT_LEN_BYTE     33u
#else
# define DOIP_ACK_VEHICLE_IDENT_LEN_BYTE     32u
#endif /* defined(DOIP_VIN_GID_SYNC) && (STD_ON == DOIP_VIN_GID_SYNC) */

#if ( defined(DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) && (STD_ON == DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) )
# define DOIP_ACK_ENTITY_STATE_LEN_BYTE      7u
#else
# define DOIP_ACK_ENTITY_STATE_LEN_BYTE      3u
#endif /* defined(DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) && (STD_ON == DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) */

#define DOIP_DIAG_HDR_LEN_BYTE               4u

#if ( defined(DOIP_VERSION) && (DOIP_ISO_DIS_13400_2_2010 == DOIP_VERSION) )
#define DOIP_PROTOCOL_VERSION                DOIP_PROTOCOL_VERSION_2010
#endif /* defined(DOIP_VERSION) && (DOIP_ISO_DIS_13400_2_2010 == DOIP_VERSION) */
#if ( defined(DOIP_VERSION) && (DOIP_ISO_FDIS_13400_2_2011 == DOIP_VERSION) )
#define DOIP_PROTOCOL_VERSION                DOIP_PROTOCOL_VERSION_2011
#endif /* defined(DOIP_VERSION) && (DOIP_ISO_FDIS_13400_2_2011 == DOIP_VERSION) */
#if ( defined(DOIP_VERSION) && (DOIP_ISO_13400_2_2012 == DOIP_VERSION) )
#define DOIP_PROTOCOL_VERSION                DOIP_PROTOCOL_VERSION_2012
#endif /* defined(DOIP_VERSION) && (DOIP_ISO_13400_2_2012 == DOIP_VERSION) */

#define DOIP_VIN_PREFIX_LEN_BYTE              3u
#define DOIP_VIN_LEN_BYTE                     17u
#define DOIP_GID_LEN_BYTE                     6u
#define DOIP_EID_LEN_BYTE                     6u
#define DOIP_ADDR_LEN_BYTE                    2u
#define DOIP_ADDR_ANY                         ((uint16)0xFFFFu)
#define DOIP_INV_QUE_IDX                      ((uint16)0xFFFFu)
#define DOIP_INV_TESTER_IDX                   ((uint8)   0xFFu)
#define DOIP_INV_ROUT_ACT_IDX                 ((uint8)   0xFFu)
#define DOIP_INV_ADDR_IDX                     ((uint8)   0xFFu)
#define DOIP_GEN_HDR_TYPE_IDX                 2u
#define DOIP_GEN_HDR_NACK_CODE_LEN_BYTE       1u
#define DOIP_ACT_TYPE_CENT_SEC                0xE0u
#if ( defined(DOIP_VERSION) && ( DOIP_VERSION == DOIP_ISO_13400_2_2012 ) )
# define DOIP_ROUT_ACTIV_REQ_MIN_LEN_BYTE     7u
# define DOIP_ROUT_ACTIV_REQ_MAX_LEN_BYTE     11u
# define DOIP_ROUT_ACTIV_REQ_TYPE_LEN_BYTE    1u
#else
# define DOIP_ROUT_ACTIV_REQ_MIN_LEN_BYTE     8u
# define DOIP_ROUT_ACTIV_REQ_MAX_LEN_BYTE     12u
# define DOIP_ROUT_ACTIV_REQ_TYPE_LEN_BYTE    2u
#endif /* defined(DOIP_VERSION) && ( DOIP_VERSION == DOIP_ISO_13400_2_2012 ) */
#define DOIP_ROUT_ACTIV_REQ_RSVD_LEN_BYTE     4u
#define DOIP_ROUT_ACTIV_REQ_OEM_LEN_BYTE      4u
#define DOIP_ROUT_ACTIV_ACK_MIN_LEN_BYTE      9u
#define DOIP_ROUT_ACTIV_ACK_MAX_LEN_BYTE      13u
#define DOIP_ROUT_ACTIV_ACK_RSVD_LEN_BYTE     4u
#define DOIP_ROUT_ACTIV_ACK_OEM_LEN_BYTE      4u
#define DOIP_DIAG_MSG_REQ_MIN_LEN_BYTE        4u
#define DOIP_DIAG_MSG_ACK_LEN_BYTE            5u

#define DOIP_VMIN_HOST_NAME_SIZE              5u

#if !defined(DOIP_UDP_MAX_RETRY_CNT)
/* depending on MainFunction cycle: 5ms -> 60s */
# define DOIP_UDP_MAX_RETRY_CNT               12000u
#endif /* !defined(DOIP_UDP_MAX_RETRY_CNT) */

/* PRQA S 3453 1 */ /* MD_MSR_19.1 */
#define DoIP_VTcpTxQueueGetLevel(Connection)  DoIP_VTcpCon2TxMgtQueLvl[(Connection)]

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
  uint8   Ver;        /* Version */
  uint8   InvVer;     /* Bit-Inverted version */
  uint8   Type[2];    /* Payload type */
  uint8   LenByte[4]; /* Payload length */
} DoIP_HdrType;

typedef struct
{
  DoIP_HdrType GenHdr;
  uint8        NackCode;
} DoIP_HdrNackType;

typedef struct
{
  uint8   TestAddr[DOIP_ADDR_LEN_BYTE];                 /* Logical address of Diagnostic Tester */
  uint8   ActivType[DOIP_ROUT_ACTIV_REQ_TYPE_LEN_BYTE]; /* Routing Activation Type */
  uint8   Reserved[DOIP_ROUT_ACTIV_REQ_RSVD_LEN_BYTE];  /* Reserved by DoIP specification */
  uint8   Oem[DOIP_ROUT_ACTIV_REQ_OEM_LEN_BYTE];        /* OEM specific extension */
} DoIP_RoutActiveReqType;

typedef struct
{
  uint8   SrcAddr[DOIP_ADDR_LEN_BYTE]; /* Logical address of Gateway */
  uint8   TgtAddr[DOIP_ADDR_LEN_BYTE]; /* Logical address of Diagnostic Tester */
} DoIP_DiagReqType;

typedef struct
{
  DoIP_HdrType GenHdr;
  uint8        DiagPowerMode;
} DoIP_PowerModeAckType;

typedef struct
{
  DoIP_HdrType GenHdr;
  uint8        NodeType;       /* DOIP_GATEWAY / DOIP_NODE */
  uint8        MaxTcpSockCnt;  /* Max number of concurrent TCP sockets */
  uint8        TcpSockCnt;     /* Current number of open TCP sockets */
#if ( defined(DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) && (STD_ON == DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) )
  uint8        MaxDataSize[4]; /* Maximum size of one logical request that this DoIP entity can process */
#endif /* defined(DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) && (STD_ON == DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) */
} DoIP_EntityStateAckType;

/* PRQA L:MACRO_LIMIT */

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#define DOIP_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
STATIC VAR(DoIP_StateType, DOIP_VAR_ZERO_INIT) DoIP_State = DOIP_STATE_UNINIT;
#define DOIP_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DOIP_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
STATIC VAR(DoIP_ActivationLineLocalType,   DOIP_VAR_NOINIT) DoIP_ActivationLineLocalState;
STATIC VAR(DoIP_ActivationLineType,        DOIP_VAR_NOINIT) DoIP_ActivationLineState;
#if ( defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) )
STATIC VAR(boolean,                        DOIP_VAR_NOINIT) DoIP_IsPduSizeRoutingEnabled;
#endif /* defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) */
#if ( defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) )
STATIC VAR(boolean,                        DOIP_VAR_NOINIT) DoIP_GidInSync;
#endif /* defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) */
#define DOIP_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VUdpSingleTransmit(PduIdType Connection, uint16 HdrType, uint16 Param);
STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VUdpTransmit(PduIdType Connection, uint16 HdrType, uint16 Param,
                               boolean CloseSocket);
STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VTcpTransmit(PduIdType Connection, uint16 HdrType, uint16 Param1,
                               uint16 Param2, uint8 Param3, SduDataPtrType DataPtr, boolean CloseSocket);
STATIC FUNC(void,           DOIP_CODE) DoIP_VTcpPrepareTransmit(PduIdType Connection, uint16 HdrType, uint16 Param1,
                               uint16 Param2, uint8 Param3, boolean CloseSocket);
STATIC FUNC(void,           DOIP_CODE) DoIP_VTcpFinishTransmit(PduIdType Connection);
STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VTcpTxQueueAddElement(PduIdType Connection, uint16 HdrType, uint16 Param1,
                               uint16 Param2, uint8 Param3, SduDataPtrType DataPtr);
STATIC FUNC(void,           DOIP_CODE) DoIP_VTcpTxQueueSend(PduIdType Connection);
STATIC FUNC(void,           DOIP_CODE) DoIP_VTcpTxQueueRemoveElement(PduIdType Connection, Std_ReturnType Result);
STATIC FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_VTcpTxQueueCopyElement(PduIdType Connection,
                                P2VAR(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
                                P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr);
STATIC FUNC(void,           DOIP_CODE) DoIP_VFillGenHdr(uint16 HdrType,
                               uint32 HdrLen,
                               P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) TgtBufferPtr);
STATIC FUNC(void,           DOIP_CODE) DoIP_VGetConnectionOfTesterAddr(uint16 TesterAddr,
                               P2VAR(PduIdType, AUTOMATIC, DOIP_APPL_VAR) Connection);
#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
STATIC FUNC(PduIdType,      DOIP_CODE) DoIP_VGetChannelByEcuAddr (uint16 EcuAddr);
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */
STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VGetConnectionBySoConId(SoAd_SoConIdType SoConId,
                               P2VAR(PduIdType, AUTOMATIC, DOIP_APPL_VAR) Connection);
STATIC FUNC(void,           DOIP_CODE) DoIP_VActivateConnectionAtChannel(uint8 RoutActIdx, PduIdType Connection);
STATIC FUNC(void,           DOIP_CODE) DoIP_VCloseSoCon(PduIdType Connection);
STATIC FUNC(uint8,          DOIP_CODE) DoIP_VGetAvailableSockNum(uint8 LocalAddrIdx);
STATIC FUNC(void,           DOIP_CODE) DoIP_VRemoveAliveCheckFromRoutActHandler(PduIdType Connection);
#if ( (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) )
STATIC FUNC(void,           DOIP_CODE) DoIP_VRequestIpAddrAssignment(uint8 LocalAddrIdx);
#endif /* (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) */
/* PRQA S 0779 1 */ /* MD_DoIP_5.1 */
STATIC FUNC(void,           DOIP_CODE) DoIP_VActivationLineStateTransitionToActive(void);
#if ( defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) )
/* PRQA S 0779 1 */ /* MD_DoIP_5.1 */
STATIC FUNC(void,           DOIP_CODE) DoIP_VActivationLineStateTransitionToInactive(void);
#endif /* defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) */
STATIC FUNC(void,           DOIP_CODE) DoIP_VPerformAuthConfAndActivateRouting(void);
STATIC FUNC(void,           DOIP_CODE) DoIP_VOpenSockConInitially(PduIdType Connection);
#if ( (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) )
STATIC FUNC(void,           DOIP_CODE) DoIP_VHandleIpAddrReassignment(void);
#endif /* (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) */
STATIC FUNC(void,           DOIP_CODE) DoIP_VHandleSockConStates(void);
#if ( defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) )
STATIC FUNC(void,           DOIP_CODE) DoIP_VHandleGidSync(void);
#endif /* defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) */
STATIC FUNC(void,           DOIP_CODE) DoIP_VHandleAuthConf(void);
STATIC FUNC(void,           DOIP_CODE) DoIP_VHandleUdpTxList(void);
STATIC FUNC(void,           DOIP_CODE) DoIP_VHandleTcpTxQueue(void);
STATIC FUNC(void,           DOIP_CODE) DoIP_VHandleTimeouts(void);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DoIP_InitMemory
 *********************************************************************************************************************/
/*! \brief      Initializes global variables
 *  \param[in]  void none
 *  \return     none
 *  \pre        Has to be called before any other calls to the module
 *  \context    Task level
 *  \context    Initialization
 *  \note       AUTOSAR extension
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_InitMemory(void)
{
  DoIP_State = DOIP_STATE_UNINIT;
}

/**********************************************************************************************************************
 *  DoIP_Init
 *********************************************************************************************************************/
/*! \brief      Initialize the data structures
 *  \param[in]  DoIPConfigPtr      Pointer to module configuration
 *  \return     none
 *  \pre        Has to be called before usage of the module
 *  \context    Task level
 *  \context    Initialization
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_Init(P2CONST(DoIP_ConfigType, AUTOMATIC, DOIP_CONST) DoIPConfigPtr)
{
  uint8 idx;

  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((NULL_PTR == DoIPConfigPtr), DOIP_API_ID_INIT, DOIP_E_PARAM_POINTER);

  /* dummy statement to avoid compiler warnings */
  DOIP_DUMMY_STATEMENT_VAR(DoIPConfigPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  /* initialize TCP socket info */
  idx = DOIP_VCONNECTION_TOTAL;
  while ( 0u < idx )
  {
    idx--;
    DoIP_VCon2IpAddrState[idx]  = SOAD_IPADDR_STATE_UNASSIGNED;
    DoIP_VCon2SoConId[idx]      = SOAD_INV_SO_CON_ID;
    DoIP_VCon2SoConState[idx]   = SOAD_SOCON_OFFLINE;
    DoIP_VCon2SoConClosing[idx] = FALSE;
  }

  idx = DOIP_VCONNECTION_TCP_TOTAL;
  while ( 0u < idx )
  {
    uint16 idx2 = DOIP_VTCP_TX_MGT_QUEUE_SIZE;
    
    idx--;
    DoIP_VTcpCon2ActivMgt[idx].TesterAddr    = DOIP_ADDR_ANY;
    DoIP_VTcpCon2ActivMgt[idx].TesterIdx     = DOIP_INV_TESTER_IDX;
    DoIP_VTcpCon2ActivMgt[idx].RoutActIdx    = DOIP_INV_ROUT_ACT_IDX;
    DoIP_VTcpCon2ActivMgt[idx].ActivState    = DOIP_ROUT_ACTIV_STATE_NONE;
    DoIP_VTcpCon2InactivCnt[idx]             = 0u;
    DoIP_VTcpCon2SkipRxMsg[idx]              = FALSE;
    DoIP_VTcpCon2RxMsgOffset[idx]            = 0u;
    DoIP_VTcpCon2TxBytesCopied[idx]          = 0u;
    DoIP_VTcpCon2LastRxBufSize[idx]          = 0u;
    DoIP_VTcpCon2LastTxBufSize[idx]          = 0u;
    DoIP_VTcpCon2RxChannelActive[idx]        = DOIP_INV_PDU_ID;
#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
    DoIP_VTcpCon2DoIPGwRxChannelActive[idx]  = DOIP_INV_PDU_ID;
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */
    DoIP_VTcpCon2TxMgtQueLvl[idx]            = 0u;
    DoIP_VTcpCon2TxMgtQueIdx[idx]            = 0u;
    DoIP_VTcpCon2TxTpSessionActive[idx]      = FALSE;
    DoIP_VTcpCon2RxTpSessionActive[idx]      = FALSE;
    DoIP_VTcpCon2TpPreTransMgt[idx].HdrType  = DOIP_HDR_TYPE_INVALID;
#if ( defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) )
    DoIP_VTcpCon2TxTpCancelRequested[idx]    = FALSE;
#endif /* defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) */
#if ( defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) )
    DoIP_VTcpCon2RxTpCancelRequested[idx]    = FALSE;
#endif /* defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) */
    while ( 0u < idx2 )
    {
      idx2--;
      DoIP_VTcpCon2TcpTxMgt[idx][idx2].Channel     = DOIP_INV_PDU_ID;
      DoIP_VTcpCon2TcpTxMgt[idx][idx2].TxHdrBufLen = 0u;
    }
  }

  idx = DOIP_VUDP_TX_MGT_LIST_SIZE;
  while ( 0u < idx )
  {
    idx--;
    DoIP_VUdpTxMgtList[idx].UdpCon = DOIP_INV_PDU_ID;
  }

  idx = DOIP_VCHANNELS_TOTAL;
  while ( 0u < idx )
  {
    idx--;
    DoIP_VChannel2TcpCon[idx]   = DOIP_INV_PDU_ID;
    DoIP_VChannel2TxMsgLen[idx] = 0u;
  }

#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
  idx = DOIP_VTESTER_TOTAL;
  while ( 0u < idx )
  {
    idx--;
    DoIP_VTester2DiagNAckOffset[idx] = 0u;
  }
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) */

  idx = DOIP_VLOCAL_ADDR_TOTAL;
  while ( 0u < idx )
  {
    idx--;
    DoIP_VLocalAddrIdx2IpAddrReqState[idx] = DOIP_IP_ADDR_REQ_STATE_NONE;
  }

  idx = DOIP_VMAX_CONS_PER_LOC_ADDR;
  while ( 0u < idx )
  {
    idx--;
    DoIP_VRoutActivHandler.AliveCheckList[idx] = DOIP_INV_PDU_ID;
  }
  DoIP_VRoutActivHandler.OemSpecReq[0]     = 0u;
  DoIP_VRoutActivHandler.OemSpecReq[1]     = 0u;
  DoIP_VRoutActivHandler.OemSpecReq[2]     = 0u;
  DoIP_VRoutActivHandler.OemSpecReq[3]     = 0u;
  DoIP_VRoutActivHandler.OemSpecRes[0]     = 0u;
  DoIP_VRoutActivHandler.OemSpecRes[1]     = 0u;
  DoIP_VRoutActivHandler.OemSpecRes[2]     = 0u;
  DoIP_VRoutActivHandler.OemSpecRes[3]     = 0u;
  DoIP_VRoutActivHandler.OemSpecUsed       = FALSE;
  DoIP_VRoutActivHandler.RoutActIdx        = DOIP_INV_ROUT_ACT_IDX;
  DoIP_VRoutActivHandler.TesterAddr        = DOIP_ADDR_ANY;
  DoIP_VRoutActivHandler.TesterIdx         = DOIP_INV_ADDR_IDX;
  DoIP_VRoutActivHandler.AliveCheckCnt     = 0u;
  DoIP_VRoutActivHandler.AliveCheckElemNum = 0u;
  DoIP_VRoutActivHandler.TcpCon            = DOIP_INV_PDU_ID;

  DoIP_ActivationLineLocalState = DOIP_ACTIVATION_LINE_LOCAL_INACTIVE;
#if ( defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) )
# if ( defined(DOIP_VACTIV_LINE_DEFAULT_ACTIVE) && (STD_ON == DOIP_VACTIV_LINE_DEFAULT_ACTIVE) )
  DoIP_ActivationLineState = DOIP_ACTIVATION_LINE_ACTIVE;
# else
  DoIP_ActivationLineState = DOIP_ACTIVATION_LINE_INACTIVE;
# endif /* defined(DOIP_VACTIV_LINE_DEFAULT_ACTIVE) && (STD_ON == DOIP_VACTIV_LINE_DEFAULT_ACTIVE) */
#else
  DoIP_ActivationLineState = DOIP_ACTIVATION_LINE_ACTIVE;
#endif /* defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) */

#if ( defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) )
  DoIP_IsPduSizeRoutingEnabled = FALSE;
#endif /* defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) */

#if ( defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) )
  DoIP_GidInSync = FALSE;
#endif /* defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) */

#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
# if ( DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u )
  DoIP_VOemPayloadTypeTcpBufLen  = 0u;
  DoIP_VOemPayloadTypeTcpBufIsTx = FALSE;
  DoIP_VOemPayloadTypeTcpBuf2Con = DOIP_INV_PDU_ID;
# endif /* DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u */
  DoIP_VOemPayloadTypeUdpBufLen = 0u;
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */

  DoIP_State = DOIP_STATE_INIT;
} /* PRQA S 6010 */ /* MD_MSR_STPTH */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if ( defined(DOIP_VERSION_INFO_API) && (STD_ON == DOIP_VERSION_INFO_API) )
/**********************************************************************************************************************
 *  DoIP_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief      Get version information
 *  \param[out] versionInfo        Pointer for version information
 *  \return     none
 *  \context    Task level
 *  \context    Initialization
 *  \note       none
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, DOIP_APPL_VAR) versionInfo)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((NULL_PTR != versionInfo), DOIP_API_ID_GET_VERSION_INFO, DOIP_E_PARAM_POINTER);

  versionInfo->vendorID         = DOIP_VENDOR_ID;
  versionInfo->moduleID         = DOIP_MODULE_ID;
  versionInfo->sw_major_version = DOIP_SW_MAJOR_VERSION;
  versionInfo->sw_minor_version = DOIP_SW_MINOR_VERSION;
  versionInfo->sw_patch_version = DOIP_SW_PATCH_VERSION;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* defined(DOIP_VERSION_INFO_API) && (STD_ON == DOIP_VERSION_INFO_API) */

/**********************************************************************************************************************
 *  DoIP_TpTransmit
 *********************************************************************************************************************/
/*! \brief      Transmission request
 *  \param[in]  DoIPPduRTxId       PDU identifier
 *  \param[in]  DoIPPduRTxInfoPtr  Pointer to message structure
 *  \return     E_OK               Transmission requested
 *  \return     E_NOT_OK           Transmission request failed
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpTransmit(PduIdType DoIPPduRTxId,
                                  P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) DoIPPduRTxInfoPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  PduIdType connection;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnValue((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_TP_TRANSMIT, DOIP_E_UNINIT, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_VCHANNELS_TOTAL > DoIPPduRTxId), DOIP_API_ID_TP_TRANSMIT,
    DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_API_TYPE_TP == DoIP_VChannel2ApiType[DoIPPduRTxId]), DOIP_API_ID_TP_TRANSMIT,
    DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_INV_PDU_ID != DoIP_VChannel2PduRTxConfPduId[DoIPPduRTxId]),
    DOIP_API_ID_TP_TRANSMIT, DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((NULL_PTR != DoIPPduRTxInfoPtr), DOIP_API_ID_TP_TRANSMIT, DOIP_E_PARAM_POINTER,
    E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((0u != DoIPPduRTxInfoPtr->SduLength), DOIP_API_ID_TP_TRANSMIT,
    DOIP_E_INVALID_PARAMETER, E_NOT_OK);

  /* get tester socket connection */
  connection = DoIP_VChannel2TcpCon[DoIPPduRTxId];

  /* check whether TP session is active or requested for this channel */
  if ( 0u == DoIP_VChannel2TxMsgLen[DoIPPduRTxId] )
  {
    /* check whether tester is connected to channel */
    if ( DOIP_INV_PDU_ID != connection )
    { /* tester is connected */
      DoIP_VChannel2TxMsgLen[DoIPPduRTxId] = DoIPPduRTxInfoPtr->SduLength;

      if ( E_OK == DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_DIAG_REQ, (uint16)DoIPPduRTxId,
        (uint16)DoIPPduRTxInfoPtr->SduLength, 0u, NULL_PTR, FALSE) )
      { /* transmit request successful */
        retVal = E_OK;
      }
    }
    if ( E_OK != retVal )
    { /* reset channel information */
      DoIP_VChannel2TxMsgLen[DoIPPduRTxId] = 0u;
    }
  }

  return retVal;
}
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_TpCancelTransmit
 *********************************************************************************************************************/
/*! \brief      Requests transmission cancellation of a specific TP PDU
 *  \param[in]  DoIPPduRTxId          PDU identifier
 *  \return     E_OK                  Cancellation request is accepted 
 *  \return     E_NOT_OK              Cancellation not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpCancelTransmit(PduIdType DoIPPduRTxId)
{
  Std_ReturnType retVal = E_NOT_OK;
#if ( defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) )
  PduIdType connection;
#endif /* defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) */

  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnValue((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_TP_CANCEL_TRANSMIT, DOIP_E_UNINIT,
    E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_VCHANNELS_TOTAL > DoIPPduRTxId), DOIP_API_ID_TP_CANCEL_TRANSMIT,
    DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_API_TYPE_TP == DoIP_VChannel2ApiType[DoIPPduRTxId]),
    DOIP_API_ID_TP_CANCEL_TRANSMIT, DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);

#if ( defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) )
  connection = DoIP_VChannel2TcpCon[DoIPPduRTxId];

  if ( DOIP_INV_PDU_ID != connection )
  { /* channel to connection mapping is available */
    if ( TRUE == DoIP_VTcpCon2TxTpSessionActive[connection] )
    { /* TP session of the corresponding socket connection is active */
      if ( 0u != DoIP_VChannel2TxMsgLen[DoIPPduRTxId] )
      { /* transmission of PDU is active */
        if ( E_OK == SoAd_TpCancelTransmit(DoIP_VCon2SoAdTxPduId[connection]) )
        { /* cancellation request successful */
          DoIP_VTcpCon2TxTpCancelRequested[connection] = TRUE;
          retVal = E_OK;
        }
      }
    }
  }
#else
  DOIP_DUMMY_STATEMENT_VAR(DoIPPduRTxId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif /* defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) */

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  DoIP_TpCancelReceive
 *********************************************************************************************************************/
/*! \brief      Requests reception cancellation of a specific TP PDU
 *  \param[in]  DoIPPduRRxId          PDU identifier
 *  \return     E_OK                  Cancellation request is accepted 
 *  \return     E_NOT_OK              Cancellation not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpCancelReceive(PduIdType DoIPPduRRxId)
{
  Std_ReturnType retVal = E_NOT_OK;
#if ( defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) )
  PduIdType      channel = DOIP_VCHANNELS_TOTAL;
#endif /* defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) */

  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnValue((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_TP_CANCEL_RECEIVE, DOIP_E_UNINIT,
    E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_VCHANNELS_TOTAL > DoIPPduRRxId), DOIP_API_ID_TP_CANCEL_RECEIVE,
    DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_API_TYPE_TP == DoIP_VChannel2ApiType[DoIPPduRRxId]),
    DOIP_API_ID_TP_CANCEL_RECEIVE, DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);

#if ( defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) )
  /* search for affected channel */
  while ( 0u < channel )
  {
    channel--;

    if ( DoIP_VChannel2PduRRxCancelPduId[channel] == DoIPPduRRxId )
    { /* found affected channel */
      PduIdType connection = DoIP_VChannel2TcpCon[channel];

      if ( DOIP_INV_PDU_ID != connection )
      { /* channel to connection mapping is available */
        if ( DOIP_INV_PDU_ID != DoIP_VTcpCon2RxChannelActive[connection] )
        { /* TP session of the corresponding socket connection is active */
          if ( E_OK == SoAd_TpCancelReceive(DoIP_VCon2SoAdRxCancelPduId[connection]) )
          { /* cancellation request successful */
            DoIP_VTcpCon2RxTpCancelRequested[connection] = TRUE;
            retVal = E_OK;
          }
        }
      }
      break;
    }
  }
#else
  DOIP_DUMMY_STATEMENT_VAR(DoIPPduRRxId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif /* defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) */

  return retVal;
}
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_IfTransmit
 *********************************************************************************************************************/
/*! \brief      Transmission request
 *  \param[in]  id          PDU identifier
 *  \param[in]  info        Pointer to message structure
 *  \return     E_OK        Transmission requested
 *  \return     E_NOT_OK    Transmission request failed
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 3206 1 */ /* MD_DoIP_3206 */
FUNC(Std_ReturnType, DOIP_CODE) DoIP_IfTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) info)
{
  Std_ReturnType retVal = E_NOT_OK;
  PduIdType connection;

  /* PRQA S 3109 9 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnValue((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_IF_TRANSMIT, DOIP_E_UNINIT, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_VCHANNELS_TOTAL > id), DOIP_API_ID_IF_TRANSMIT,
    DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_API_TYPE_IF == DoIP_VChannel2ApiType[id]), DOIP_API_ID_IF_TRANSMIT,
    DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((NULL_PTR != info), DOIP_API_ID_IF_TRANSMIT, DOIP_E_PARAM_POINTER,
    E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((NULL_PTR != info->SduDataPtr), DOIP_API_ID_IF_TRANSMIT, DOIP_E_PARAM_POINTER,
    E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((0u != info->SduLength), DOIP_API_ID_IF_TRANSMIT, DOIP_E_PARAM_POINTER,
    E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DoIP_VChannel2IfTxBuf[id].MaxBufLen >= info->SduLength), DOIP_API_ID_IF_TRANSMIT,
    DOIP_E_PARAM_POINTER, E_NOT_OK);

  /* get tester socket connection */
  connection = DoIP_VChannel2TcpCon[id];

  /* check if previous transmission is pending */
  if ( 0u == DoIP_VChannel2TxMsgLen[id] )
  { /* no transmission pending */
    if ( DOIP_INV_PDU_ID != connection )
    { /* tester is connected */
      DoIP_VChannel2TxMsgLen[id] = info->SduLength;

      retVal = DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_DIAG_REQ, (uint16)id, (uint16)info->SduLength, 0u,
        info->SduDataPtr, FALSE);
    }
  }

  return retVal;
}
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STPTH */

/**********************************************************************************************************************
 *  DoIP_IfCancelTransmit
 *********************************************************************************************************************/
/*! \brief      Transmission cancellation of a specific IF PDU
 *  \param[in]  id          PDU identifier
 *  \return     E_OK        Cancellation was executed successfully
 *  \return     E_NOT_OK    Cancellation was rejected
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 3206 1 */ /* MD_DoIP_3206 */
FUNC(Std_ReturnType, DOIP_CODE) DoIP_IfCancelTransmit(PduIdType id)
{
  Std_ReturnType retVal = E_NOT_OK;
#if ( defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) )
  PduIdType connection;
#endif /* defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) */

  DOIP_CheckDetErrorReturnValue((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_IF_CANCEL_TRANSMIT, DOIP_E_UNINIT,
    E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_VCHANNELS_TOTAL > id), DOIP_API_ID_IF_CANCEL_TRANSMIT,
    DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_API_TYPE_IF == DoIP_VChannel2ApiType[id]), DOIP_API_ID_IF_CANCEL_TRANSMIT,
    DOIP_E_INVALID_PDU_SDU_ID, E_NOT_OK);

#if ( defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) )
  connection = DoIP_VChannel2TcpCon[id];

  if ( DOIP_INV_PDU_ID != connection )
  { /* channel to connection mapping is available */
    if ( TRUE == DoIP_VTcpCon2TxTpSessionActive[connection] )
    { /* TP session of the corresponding socket connection is active */
      if ( 0u != DoIP_VChannel2TxMsgLen[id] )
      { /* transmission of PDU is active */
        if ( E_OK == SoAd_TpCancelTransmit(DoIP_VCon2SoAdTxPduId[connection]) )
        { /* cancellation request successful */
          DoIP_VTcpCon2TxTpCancelRequested[connection] = TRUE;
          retVal = E_OK;
        }
      }
    }
  }
#else
  DOIP_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif /* defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) */

  return retVal;
}
/* PRQA L:MSR_14_7 */

/**********************************************************************************************************************
 *  DoIP_TpChangeParameter
 *********************************************************************************************************************/
/*! \brief      Implemented to support generic PduR modules - no functionality
 *  \param[in]  id              PDU identifier
 *  \param[in]  parameter       Parameter identifier
 *  \param[in]  value           New parameter value
 *  \return     E_OK            Request is accepted
 *  \return     E_NOT_OK        Request is not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *  \note       No functionality - always returns E_NOT_OK
 *********************************************************************************************************************/
/* PRQA S 3206 1 */ /* MD_DoIP_3206 */
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
  /* prevent compiler warnings for unused parameter */
  DOIP_DUMMY_STATEMENT_VAR(id); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  DOIP_DUMMY_STATEMENT_VAR(parameter); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  DOIP_DUMMY_STATEMENT_VAR(value); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  return E_NOT_OK;
}

/**********************************************************************************************************************
 *  DoIP_MainFunction
 *********************************************************************************************************************/
/*! \brief      Issue vehicle announcement, alive check and inactivity timeout handling
 *  \param[in]  void none
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(void, DOIP_CODE) DoIP_MainFunction(void)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_UNINIT != DoIP_State), DOIP_API_ID_MAIN_FUNCTION, DOIP_E_UNINIT);

  if ( DOIP_STATE_INIT == DoIP_State )
  { /* DoIP is initialized */
    /* handling depends on activation line state */
    switch (DoIP_ActivationLineLocalState)
    {
      case DOIP_ACTIVATION_LINE_LOCAL_INACTIVE:
      { /* local activation line state inactive */
        if ( DOIP_ACTIVATION_LINE_ACTIVE == DoIP_ActivationLineState )
        { /* requested to be active */
          DoIP_ActivationLineLocalState = DOIP_ACTIVATION_LINE_LOCAL_INACTIVE_TO_ACTIVE;
          /* copy case DOIP_ACTIVATION_LINE_LOCAL_INACTIVE_TO_ACTIVE to handle state in this main function cycle */
          DoIP_VActivationLineStateTransitionToActive();
        }
        break;
      }
      case DOIP_ACTIVATION_LINE_LOCAL_INACTIVE_TO_ACTIVE:
      { /* local activation line state in transition from inactive to active */
        DoIP_VActivationLineStateTransitionToActive();
        break;
      }
      case DOIP_ACTIVATION_LINE_LOCAL_ACTIVE:
      { /* local activation line state active */
#if ( DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON )
        if ( DOIP_ACTIVATION_LINE_INACTIVE == DoIP_ActivationLineState )
        { /* requested to be inactive */
          DoIP_ActivationLineLocalState = DOIP_ACTIVATION_LINE_LOCAL_ACTIVE_TO_INACTIVE;
          /* copy case DOIP_ACTIVATION_LINE_LOCAL_ACTIVE_TO_INACTIVE to handle state in this main function cycle */
          DoIP_VActivationLineStateTransitionToInactive();
        }
        else
#endif /* DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON */
        {
#if ( (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) )
          DoIP_VHandleIpAddrReassignment();
#endif /* (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) */

          DoIP_VHandleSockConStates();

#if ( defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) )
          DoIP_VHandleGidSync();
#endif /* defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) */

          DoIP_VHandleAuthConf();

          DoIP_VHandleUdpTxList();

          DoIP_VHandleTcpTxQueue();

          DoIP_VHandleTimeouts();
        }
        break;
      }
#if ( defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) )
      case DOIP_ACTIVATION_LINE_LOCAL_ACTIVE_TO_INACTIVE:
      { /* local activation line state in transition from active to inactive */
        DoIP_VActivationLineStateTransitionToInactive();
        break;
      }
#endif /* defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) */
      default:
      { /* invalid state */
        /* nothing to do */
      }
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_SoAdIfRxIndication
 *********************************************************************************************************************/
/*! \brief      Receive indication callback for IF
 *  \param[in]  RxPduId        RX indication PDU ID
 *  \param[in]  PduInfoPtr     Pointer to received data and length
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 3333 DoIP_14_6 */ /* MD_DoIP_14.6 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(void, DOIP_CODE) DoIP_SoAdIfRxIndication(PduIdType RxPduId,
                                              P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr )
{
  boolean closeSocket = FALSE;
  uint8 srcHdrVer;
  uint8 srcHdrInvVer;
  uint32 srcHdrLen;
  uint16 srcHdrType;
  uint32 dataOffset = 0u;
  uint8 reqCnt = 0u;

  /* PRQA S 3109 8 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_IF_RX_INDICATION, DOIP_E_UNINIT);
  DOIP_CheckDetErrorReturnVoid(((DOIP_VCONNECTION_TCP_TOTAL <= RxPduId) &&
    (DOIP_VCONNECTION_TCP_UDP_TOTAL > RxPduId)), DOIP_API_ID_IF_RX_INDICATION, DOIP_E_INVALID_PDU_SDU_ID);
  DOIP_CheckDetErrorReturnVoid((NULL_PTR != PduInfoPtr), DOIP_API_ID_IF_RX_INDICATION,  DOIP_E_PARAM_POINTER);
  DOIP_CheckDetErrorReturnVoid((NULL_PTR != PduInfoPtr->SduDataPtr), DOIP_API_ID_IF_RX_INDICATION,
    DOIP_E_PARAM_POINTER);

  if ( SOAD_IPADDR_STATE_ASSIGNED != DoIP_VCon2IpAddrState[RxPduId] )
  { /* no IP is assigned */
    return;
  }

  if ( (SOAD_SOCON_ONLINE != DoIP_VCon2SoConState[RxPduId]) || (TRUE == DoIP_VCon2SoConClosing[RxPduId]) )
  { /* socket connection is not online or requested to be closed */
    return;
  }

  while ( PduInfoPtr->SduLength > dataOffset )
  {
    if ( (PduInfoPtr->SduLength - dataOffset) < DOIP_GEN_HDR_LEN_BYTE )
    { /* message too short */
      DoIP_VCloseSoCon(RxPduId);
      break;
    }

    /* extract generic header */
    DOIP_GET_UINT8(PduInfoPtr->SduDataPtr, dataOffset, srcHdrVer);
    DOIP_GET_UINT8(PduInfoPtr->SduDataPtr, (dataOffset + 1), srcHdrInvVer);
    DOIP_GET_UINT16(PduInfoPtr->SduDataPtr, (dataOffset + 2), srcHdrType);
    DOIP_GET_UINT32(PduInfoPtr->SduDataPtr, (dataOffset + 4), srcHdrLen);

    if ( (DOIP_PROTOCOL_VERSION != (uint8)srcHdrVer) || (DOIP_PROTOCOL_VERSION != (uint8)(~srcHdrInvVer)) )
    { /* header pattern does not match configured DoIP version */
      /* check whether default protocol version is used and valid here */
      if ( (DOIP_PROTOCOL_VERSION_DEFAULT != (uint8)srcHdrVer) || 
        (DOIP_PROTOCOL_VERSION_DEFAULT != (uint8)(~srcHdrInvVer)) ||
        (DOIP_HDR_TYPE_VEHICLE_IDENT_REQ > srcHdrType) || 
        (DOIP_HDR_TYPE_VEHICLE_IDENT_REQ_VIN < srcHdrType) )
      { /* invalid header pattern */
        (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_FORMAT, TRUE);
        return;
      }
    }
    if ( (DOIP_GEN_HDR_LEN_BYTE + srcHdrLen) > (PduInfoPtr->SduLength - dataOffset) )
    { /* invalid header length relative to received data length */
      (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, TRUE);
      return;
    }

    reqCnt++;
    if ( DOIP_VMAX_UDP_REQ_PER_MSG < reqCnt )
    { /* maximum requests per message exceeded */
      if ( (DOIP_GEN_HDR_LEN_BYTE + srcHdrLen) == (PduInfoPtr->SduLength - dataOffset) )
      { /* last message in frame */
        if ( FALSE == DoIP_VLocalAddrIdx2HasUdpAliveTimeout[DoIP_VCon2LocalAddrIdx[RxPduId]] )
        { /* socket connection has to be closed manually since no UDP alive timeout is configured */
          /* close socket connection after sending */
          (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_OUT_OF_MEM, TRUE);
        }
        else
        {
          (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_OUT_OF_MEM, FALSE);
        }
      }
      else
      {
        (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_OUT_OF_MEM, FALSE);
      }
    }
    else
    {
      if ( (DOIP_GEN_HDR_LEN_BYTE + srcHdrLen) == (PduInfoPtr->SduLength - dataOffset) )
      { /* last message in frame */
        if ( FALSE == DoIP_VLocalAddrIdx2HasUdpAliveTimeout[DoIP_VCon2LocalAddrIdx[RxPduId]] )
        { /* socket connection has to be closed manually since no UDP alive timeout is configured */
          /* close socket connection after sending */
          closeSocket = TRUE;
        }
      }

      /* further handling depends on message type */
      switch(srcHdrType)
      {
        case DOIP_HDR_TYPE_VEHICLE_IDENT_REQ:
        { /* vehicle identification request */
          if ( DOIP_MAX_REQUEST_BYTES < srcHdrLen )
          { /* max length exceeded */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, closeSocket);
            break;
          }
          if ( 0u != srcHdrLen )
          { /* length check failed */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, closeSocket);
          }
          else
          {
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT, DOIP_IDENT_RES_NUM, closeSocket);
          }
          break;
        }
        case DOIP_HDR_TYPE_VEHICLE_IDENT_REQ_VIN:
        { /* vehicle identification with VIN (check for our VIN) */
          if ( DOIP_MAX_REQUEST_BYTES < srcHdrLen )
          { /* max length exceeded */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, closeSocket);
            break;
          }
          if ( DOIP_VIN_LEN_BYTE != srcHdrLen )
          { /* length check failed */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, closeSocket);
          }
          else
          { /* length check ok */
            boolean IdentOk = TRUE;
            uint8 IdentIdx = DOIP_VIN_LEN_BYTE;
            uint8 vin[DOIP_VIN_LEN_BYTE] = {0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};

            if ( E_OK == DoIP_VCallGetVinDirect(vin) )
            { /* VIN successfully retrieved */
              /* compare to retrieved VIN */
              while ( 0u < IdentIdx )
              {
                IdentIdx--;
                if ( PduInfoPtr->SduDataPtr[dataOffset + DOIP_GEN_HDR_LEN_BYTE + IdentIdx] != vin[IdentIdx] )
                {
                  IdentOk = FALSE;
                  break;
                }
              }
            }
            else
            { /* VIN request failed */
              /* compare to invaliditiy pattern */
              while ( 0u < IdentIdx )
              {
                IdentIdx--;
                if ( PduInfoPtr->SduDataPtr[dataOffset + DOIP_GEN_HDR_LEN_BYTE + IdentIdx] != DOIP_VVIN_INV_PATTERN )
                {
                  IdentOk = FALSE;
                  break;
                }
              }
            }

            if ( TRUE == IdentOk )
            {
              (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT, DOIP_IDENT_RES_NUM, closeSocket);
            }
          }
          break;
        }
#if ( defined(DOIP_VVEHICLE_IDENT_EID_SUPPORT) && (STD_ON == DOIP_VVEHICLE_IDENT_EID_SUPPORT) )
        case DOIP_HDR_TYPE_VEHICLE_IDENT_REQ_EID:
        { /* vehicle identification with entity id (check for our physical address (MAC address)) */
          if ( DOIP_MAX_REQUEST_BYTES < srcHdrLen )
          { /* max length exceeded */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, closeSocket);
            break;
          }
          if ( DOIP_UHWID_LEN_BYTE != srcHdrLen )
          { /* length check failed */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, closeSocket);
          }
          else
          { /* length check ok */
            boolean identOk  = TRUE;
            uint8   identIdx = DOIP_UHWID_LEN_BYTE;

# if ( defined(DOIP_VUSE_MAC_ADDR_FOR_IDENT) && (STD_ON == DOIP_VUSE_MAC_ADDR_FOR_IDENT) )
            uint8   physAddrBuf[DOIP_UHWID_LEN_BYTE];

            if ( E_OK == SoAd_GetPhysAddr(DoIP_VCon2SoConId[RxPduId], &physAddrBuf[0]) )
            {
              while ( 0u < identIdx )
              {
                identIdx--;
                if ( PduInfoPtr->SduDataPtr[dataOffset + DOIP_GEN_HDR_LEN_BYTE + identIdx] != physAddrBuf[identIdx] )
                {
                  identOk = FALSE;
                  break;
                }
              }
            }
            else
            {
              identOk = FALSE;
            }
# else
            while ( 0u < identIdx )
            {
              identIdx--;
              if ( PduInfoPtr->SduDataPtr[dataOffset + DOIP_GEN_HDR_LEN_BYTE + identIdx] != 
                (uint8)(DoIP_VEid[identIdx]) )
              {
                identOk = FALSE;
                break;
              }
            }
# endif /* defined(DOIP_VUSE_MAC_ADDR_FOR_IDENT) && (STD_ON == DOIP_VUSE_MAC_ADDR_FOR_IDENT) */

            if ( TRUE == identOk )
            {
              (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT, DOIP_IDENT_RES_NUM, closeSocket);
            }
          }
          break;
        }
#endif /* defined(DOIP_VVEHICLE_IDENT_EID_SUPPORT) && (STD_ON == DOIP_VVEHICLE_IDENT_EID_SUPPORT) */
        case DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_REQ:
        { /* diagnostic power mode request */
          if ( DOIP_MAX_REQUEST_BYTES < srcHdrLen )
          { /* max length exceeded */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, closeSocket);
            break;
          }
          if ( 0u != srcHdrLen )
          { /* length check failed */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, closeSocket);
          }
          else
          { /* length check ok */
            DoIP_PowerModeType diagPowerMode = DOIP_POWER_MODE_NOT_SUPPORTED;

            if( E_NOT_OK == DoIP_VCallPowerModeDirect(&diagPowerMode) )
            {
              diagPowerMode = DOIP_POWER_MODE_NOT_READY;
            }
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_ACK, diagPowerMode, closeSocket);
          }
          break;
        }
#if ( defined(DOIP_ENTITY_STATE_SUPPORT) && (STD_ON == DOIP_ENTITY_STATE_SUPPORT) )
        case DOIP_HDR_TYPE_ENTITY_STATE_REQ:
        { /* entity status request */
          if ( DOIP_MAX_REQUEST_BYTES < srcHdrLen )
          { /* max length exceeded */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, closeSocket);
            break;
          }
          if (0u != srcHdrLen)
          { /* length check failed */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, closeSocket);
          }
          else
          { /* length check ok */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_ENTITY_STATE_ACK, DOIP_UNUSED_PARAM, closeSocket);
          }
          break;
        }
#endif /* defined(DOIP_ENTITY_STATE_SUPPORT) && (STD_ON == DOIP_ENTITY_STATE_SUPPORT) */
        case DOIP_HDR_TYPE_GEN_NACK:
        case DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT:
        case DOIP_HDR_TYPE_ROUT_ACTIV_REQ:
        case DOIP_HDR_TYPE_ROUT_ACTIV_ACK:
        case DOIP_HDR_TYPE_ALIVE_CHECK_REQ:
        case DOIP_HDR_TYPE_ALIVE_CHECK_ACK:
        case DOIP_HDR_TYPE_ENTITY_STATE_ACK:
        case DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_ACK:
        case DOIP_HDR_TYPE_DIAG_REQ:
        case DOIP_HDR_TYPE_DIAG_ACK:
        case DOIP_HDR_TYPE_DIAG_NACK:
        { /* ignore not relevant header type */
          break;
        }
        default:
        { /* TxNack: unknown header type */
#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
          PduInfoType rxUserData;

          rxUserData.SduLength = (PduLengthType)srcHdrLen;
          if ( srcHdrLen == 0u)
          {
            rxUserData.SduDataPtr = NULL_PTR;
          }
          else
          {
            rxUserData.SduDataPtr = &PduInfoPtr->SduDataPtr[dataOffset + DOIP_GEN_HDR_LEN_BYTE];
          }

          /* check if tx buffer is available */
          if ( DoIP_VOemPayloadTypeUdpBufLen == 0u )
          { /* tx buffer is available */
            uint16 txHdrType = DOIP_HDR_TYPE_INVALID;
            PduInfoType txUserData;

            txUserData.SduDataPtr = &DoIP_VOemPayloadTypeUdpBuf[DOIP_GEN_HDR_LEN_BYTE];
            txUserData.SduLength = DOIP_VOEM_PAYLOAD_TYPE_UDP_BUF_SIZE;

            /* call user callback to forward message to upper layer */
            if ( DoIP_VCallOemPayloadTypeDirect(srcHdrType, &rxUserData, DOIP_OEM_PAYLOAD_TYPE_FLAG_PROT_UDP,
                &txHdrType, &txUserData) == E_NOT_OK )
            {
              (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE, closeSocket);
            }
            else
            {
              if ( txHdrType != DOIP_HDR_TYPE_INVALID )
              {
                if ( txUserData.SduLength <= DOIP_VOEM_PAYLOAD_TYPE_UDP_BUF_SIZE )
                {
                  DoIP_VOemPayloadTypeUdpBufLen = (uint16)(txUserData.SduLength + DOIP_GEN_HDR_LEN_BYTE);
                  (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_OEM_SPECIFIC, txHdrType, closeSocket);
                }
              }
            }
          }
          else
          { /* no tx buffer is available */
            /* send out of memory */
            (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_OUT_OF_MEM, closeSocket);
          }
#else
          (void)DoIP_VUdpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE, closeSocket);
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */
        }
      }
    }

    dataOffset += DOIP_GEN_HDR_LEN_BYTE + srcHdrLen;
  }
}
/* PRQA L:MSR_14_7 */
/* PRQA L:DoIP_14_6 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_SoAdTpStartOfReception
 *********************************************************************************************************************/
/*! \brief      Receive indication callback for TP
 *  \param[in]  RxPduId           Rx PDU ID 
 *  \param[in]  info              Pointer to data to support first or single frames (not used by SoAd)
 *  \param[in]  TpSduLength       Total length of the received PDU
 *  \param[out] bufferSizePtr     Available receive buffer
 *  \return     BUFREQ_OK         Connection has been accepted
 *  \return     BUFREQ_E_NOT_OK   Connection has not been accepted
 *  \return     BUFREQ_E_OVFL     No buffer of the required length can be provided
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 3673 DoIP_16_7 */ /* MD_DoIP_16.7 */
/* PRQA S 3206 4 */ /* MD_DoIP_3206 */
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpStartOfReception(PduIdType RxPduId,
                        P2VAR(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) info,
                        PduLengthType TpSduLength,
                        P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) bufferSizePtr)
{
  DOIP_CheckDetErrorReturnValue((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_TP_START_OF_RECEPTION,
    DOIP_E_UNINIT, BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_VCONNECTION_TCP_TOTAL > RxPduId), DOIP_API_ID_TP_START_OF_RECEPTION,
    DOIP_E_INVALID_PDU_SDU_ID, BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((NULL_PTR != bufferSizePtr), DOIP_API_ID_TP_START_OF_RECEPTION,
    DOIP_E_PARAM_POINTER, BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((0u == TpSduLength), DOIP_API_ID_TP_START_OF_RECEPTION,
    DOIP_E_INVALID_PARAMETER, BUFREQ_E_NOT_OK);
  
  /* prevent compiler warnings for unused parameter */
  DOIP_DUMMY_STATEMENT_VAR(info); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  DOIP_DUMMY_STATEMENT_VAR(bufferSizePtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  /*lint -e662 -e661 */

  /* check socket connection state */
  if ( SOAD_SOCON_ONLINE != DoIP_VCon2SoConState[RxPduId] )
  { /* socket connection is not online */
    return BUFREQ_E_NOT_OK;
  }

  if ( TRUE == DoIP_VTcpCon2RxTpSessionActive[RxPduId] )
  { /* TP Routing is already active */
    return BUFREQ_E_NOT_OK;
  }
  else
  { /* TP Routing is not active */
    /* activate TP session */
    DoIP_VTcpCon2RxTpSessionActive[RxPduId] = TRUE;
  }

  /*lint +e662 +e661 */

  return BUFREQ_OK;
}
/* PRQA L: DoIP_16_7 */
/* PRQA L: MSR_14_7 */

/**********************************************************************************************************************
 *  DoIP_SoAdTpCopyRxData
 *********************************************************************************************************************/
/*! \brief      Called when SoAd has data to copy
 *  \param[in]  RxPduId           Rx PDU ID
 *  \param[in]  PduInfoPtr        Pointer to received data and length
 *  \param[out] bufferSizePtr     Available buffer after data has been copy
 *  \return     BUFREQ_OK         Buffer request successful
 *  \return     BUFREQ_E_NOT_OK   Buffer request not successful
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
/* PRQA S 3333 DoIP_14_6 */ /* MD_DoIP_14.6 */
/* PRQA S 3673 DoIP_16_7 */ /* MD_DoIP_16.7 */
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 MSR_STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyRxData(PduIdType RxPduId,
                        P2VAR(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
                        P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) bufferSizePtr)
{
  PduLengthType readDataLen = 0u;

  DOIP_CheckDetErrorReturnValue((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_TP_COPY_RX_DATA, DOIP_E_UNINIT,
    BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_VCONNECTION_TCP_TOTAL > RxPduId), DOIP_API_ID_TP_COPY_RX_DATA,
    DOIP_E_INVALID_PDU_SDU_ID, BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((NULL_PTR != PduInfoPtr), DOIP_API_ID_TP_COPY_RX_DATA, DOIP_E_PARAM_POINTER,
    BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((NULL_PTR != bufferSizePtr), DOIP_API_ID_TP_COPY_RX_DATA, DOIP_E_PARAM_POINTER,
    BUFREQ_E_NOT_OK);

  /* check socket connection state */
  if ( SOAD_SOCON_ONLINE != DoIP_VCon2SoConState[RxPduId] )
  { /* socket connection is not online */
    return BUFREQ_E_NOT_OK;
  }

  /* check TP session state */
  if ( TRUE != DoIP_VTcpCon2RxTpSessionActive[RxPduId] )
  { /* TP session is not active */
    return BUFREQ_E_NOT_OK;
  }

  /* check whether socket connection is requested to be closed */
  if ( TRUE == DoIP_VCon2SoConClosing[RxPduId] )
  { /* socket connection closing is requested - do not handle more than pending rx data of message */
    *bufferSizePtr = 0u;
    DoIP_VTcpCon2LastRxBufSize[RxPduId] = 0u;
    return BUFREQ_OK;
  }

#if ( defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) )
  /* Check TP cancellation */
  if ( TRUE == DoIP_VTcpCon2RxTpCancelRequested[RxPduId] )
  { /* TP cancellation is ongoing */
    return BUFREQ_E_NOT_OK;
  }
#endif /* defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) */

#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
  if ( DOIP_INV_TESTER_IDX != DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx )
  { /* the feature to send previously received user data cannot be used if tester could not be determined */
    if ( 0u == DoIP_VTcpCon2RxMsgOffset[RxPduId] )
    {
      if ( 0u < DoIP_VTester2DiagNAckOffset[DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx] )
      { /* diagnostic message acknowledge is pending - do not accept new data until acknowledge is sent */
        *bufferSizePtr = 0u;
        DoIP_VTcpCon2LastRxBufSize[RxPduId] = 0u;
        return BUFREQ_OK;
      }
    }
  }
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) */

  if ( 0u == PduInfoPtr->SduLength )
  { /* SoAd queries Rx buffer size */
    if ( DOIP_GEN_HDR_LEN_BYTE > DoIP_VTcpCon2RxMsgOffset[RxPduId] )
    { /* generic header not received completely */
      /* do only provide buffer for generic header */
      *bufferSizePtr = DOIP_GEN_HDR_LEN_BYTE - DoIP_VTcpCon2RxMsgOffset[RxPduId];
      DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
      return BUFREQ_OK;
    }
  }
  else
  { /* SoAd has Rx data */
    DOIP_CheckDetErrorReturnValue((NULL_PTR != PduInfoPtr->SduDataPtr), DOIP_API_ID_TP_COPY_RX_DATA,
      DOIP_E_PARAM_POINTER, BUFREQ_E_NOT_OK);

    /* check length */
    if ( DoIP_VTcpCon2LastRxBufSize[RxPduId] < PduInfoPtr->SduLength )
    { /* unexpected length */
      return BUFREQ_E_NOT_OK;
    }
  }

  if ( DOIP_ROUT_ACTIV_STATE_ACTIVATED == DoIP_VTcpCon2ActivMgt[RxPduId].ActivState )
  { /* routing activation active */
    /* reset inactivity timer */
    DoIP_VTcpCon2InactivCnt[RxPduId] = 0;
  }

  do
  {
    if ( DOIP_GEN_HDR_LEN_BYTE > DoIP_VTcpCon2RxMsgOffset[RxPduId] )
    { /* generic header was not received completely */
      PduLengthType bytesToCopy = PduInfoPtr->SduLength;

      /* PduInfoPtr->SduLength has been checkd before against bufferSizePtr of last call to this function */

      /* PRQA S 0310,3305 4 */ /* MD_DoIP_11.4 */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VTcpCon2RxHdrBuf[RxPduId][
          DoIP_VTcpCon2RxMsgOffset[RxPduId]],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&PduInfoPtr->SduDataPtr[readDataLen],
        (uint32)bytesToCopy);
      readDataLen                       += bytesToCopy;
      DoIP_VTcpCon2RxMsgOffset[RxPduId] += bytesToCopy;
    }

    if ( DOIP_GEN_HDR_LEN_BYTE <= DoIP_VTcpCon2RxMsgOffset[RxPduId] )
    { /* generic header was received completely */
      P2VAR(DoIP_HdrType, AUTOMATIC, DOIP_APPL_DATA) hdrPtr;
      uint32 hdrLen;
      uint16 hdrType;

      /* PRQA S 0310 1 */ /* MD_DoIP_11.4 */
      hdrPtr = ((P2VAR(DoIP_HdrType, AUTOMATIC, DOIP_VAR_NOINIT))&DoIP_VTcpCon2RxHdrBuf[RxPduId][0]);

      if ( (DOIP_PROTOCOL_VERSION != (uint8)hdrPtr->Ver) || (DOIP_PROTOCOL_VERSION != (uint8)(~hdrPtr->InvVer)) )
      { /* invalid header pattern */
        (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_FORMAT, 0u, 0u, NULL_PTR, TRUE);
        return BUFREQ_OK;
      }

      /* PRQA S 0310 2 */ /* MD_DoIP_11.4 */
      DOIP_GET_UINT16(hdrPtr->Type, 0, hdrType);
      DOIP_GET_UINT32(hdrPtr->LenByte, 0, hdrLen);

      if ( (DOIP_HDR_TYPE_ROUT_ACTIV_REQ == hdrType) && (DOIP_INV_PDU_ID != DoIP_VRoutActivHandler.TcpCon) )
      { /* routing activation handler is busy */
        /* handle routing activation later */
        *bufferSizePtr = 0u;
        DoIP_VTcpCon2LastRxBufSize[RxPduId] = 0u;
        break;
      }

      /* check whether message shall be skipped */
      if ( TRUE == DoIP_VTcpCon2SkipRxMsg[RxPduId] )
      { /* message shall be skipped */
#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
        if ( DOIP_HDR_TYPE_DIAG_REQ == hdrType )
        { /* diagnostic message */
          if ( DOIP_HDR_TYPE_DIAG_NACK == DoIP_VTcpCon2TpPreTransMgt[RxPduId].HdrType )
          { /* diagnostic message negative acknowledge shall be sent */
            uint8 testerIdx = DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx;

            if ( DOIP_INV_TESTER_IDX != testerIdx )
            { /* the feature to send previously received user data cannot be used if tester could not be determined */
              if ( DoIP_VTester[testerIdx].DiagAckNackNumByte > 0u )
              { /* diagnostic message acknowledge shall contain user data */
                PduLengthType bytesToCopy = PduInfoPtr->SduLength - readDataLen;

                /* PduInfoPtr->SduLength has been checked before against bufferSizePtr of last call to this function */

                if ( (DoIP_VTester[testerIdx].DiagAckNackNumByte - DoIP_VTester2DiagNAckOffset[testerIdx]) < 
                  bytesToCopy )
                { /* DiagAckNack buffer is smaller than the received diagnostic message user data */
                  bytesToCopy = (PduLengthType)(DoIP_VTester[testerIdx].DiagAckNackNumByte - 
                    DoIP_VTester2DiagNAckOffset[testerIdx]);
                }
                if ( 0u < bytesToCopy )
                { /* copy data to DiagNAck buffer */
                  /* PRQA S 0310,3305 4 */ /* MD_DoIP_11.4 */
                  IpBase_Copy(
                    (P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VTester[testerIdx].DiagAckNackBufPtr[
                      DoIP_VTester2DiagNAckOffset[testerIdx]], 
                        (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&PduInfoPtr->SduDataPtr[readDataLen],
                        (uint32)bytesToCopy);
                  DoIP_VTester2DiagNAckOffset[testerIdx] += bytesToCopy;
                }
              }
            }
          }
        }
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) */
        if ( (PduLengthType)((DOIP_GEN_HDR_LEN_BYTE + hdrLen) - DoIP_VTcpCon2RxMsgOffset[RxPduId]) > 
          ((PduLengthType)(PduInfoPtr->SduLength - readDataLen)) )
        { /* message to be skipped is not received completely */
          DoIP_VTcpCon2RxMsgOffset[RxPduId] += PduInfoPtr->SduLength - readDataLen;
          *bufferSizePtr = (PduLengthType)((DOIP_GEN_HDR_LEN_BYTE + hdrLen) - DoIP_VTcpCon2RxMsgOffset[RxPduId]);
          DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
        }
        else
        { /* message to be skipped is received completely */
          /* finish message */
          DoIP_VTcpFinishTransmit(RxPduId);

          *bufferSizePtr                      = 0u;
          DoIP_VTcpCon2LastRxBufSize[RxPduId] = 0u;
          DoIP_VTcpCon2RxMsgOffset[RxPduId]   = 0u;
          DoIP_VTcpCon2SkipRxMsg[RxPduId]     = FALSE;
        }
        return BUFREQ_OK;
      }

      /* further handling depends on message type */
      switch(hdrType)
      {
        case DOIP_HDR_TYPE_ROUT_ACTIV_REQ:
        { /* routing activation request */
          PduLengthType bytesToCopy;

          /* check message length */
          if ( DOIP_MAX_REQUEST_BYTES < hdrLen )
          { /* max length exceeded */
            DoIP_VTcpCon2SkipRxMsg[RxPduId] = TRUE;
            (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, 0u, 0u, NULL_PTR, FALSE);
            break;
          }
          if ( (DOIP_ROUT_ACTIV_REQ_MIN_LEN_BYTE != hdrLen) &&
            ((DOIP_ROUT_ACTIV_REQ_MIN_LEN_BYTE + DOIP_ROUT_ACTIV_REQ_OEM_LEN_BYTE) != hdrLen) )
          { /* length check failed */
            (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, 0u, 0u, NULL_PTR, TRUE);
            break;
          }

          bytesToCopy = (PduLengthType)((hdrLen + DOIP_GEN_HDR_LEN_BYTE) - DoIP_VTcpCon2RxMsgOffset[RxPduId]);
          if ( bytesToCopy > (PduLengthType)(PduInfoPtr->SduLength - readDataLen) )
          {
            bytesToCopy = (PduLengthType)(PduInfoPtr->SduLength - readDataLen);
          }

          if ( bytesToCopy > 0u )
          {
            /* copy data to header buffer */
            /* PRQA S 0310,3305 3 */ /* MD_DoIP_11.4 */
            IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VTcpCon2RxHdrBuf[RxPduId][
                DoIP_VTcpCon2RxMsgOffset[RxPduId]],
              (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&PduInfoPtr->SduDataPtr[readDataLen],
              (uint32)bytesToCopy);
            readDataLen                       += bytesToCopy;
            DoIP_VTcpCon2RxMsgOffset[RxPduId] += bytesToCopy;
          }

          /* check whether message is now copied completely */
          if ( (hdrLen + DOIP_GEN_HDR_LEN_BYTE) == DoIP_VTcpCon2RxMsgOffset[RxPduId] )
          { /* message copied completely */
            /* PRQA S 0310 2 */ /* MD_DoIP_11.4 */
            P2VAR(DoIP_RoutActiveReqType, AUTOMATIC, DOIP_APPL_VAR) reqPtr =
              (P2VAR(DoIP_RoutActiveReqType, AUTOMATIC, DOIP_VAR_NOINIT))&DoIP_VTcpCon2RxHdrBuf[RxPduId][
                DOIP_GEN_HDR_LEN_BYTE];
            uint16 testerAddr;
            uint8  locAddrIdx = DoIP_VCon2LocalAddrIdx[RxPduId];
            uint8  testerIdx = DOIP_VTESTER_TOTAL;
            uint8  routActColIdx = 0u;
            uint8  routActIdx = 0u;
#if ( defined(DOIP_VERSION) && (DOIP_VERSION == DOIP_ISO_13400_2_2012) )
            uint8  activType;
#else
            uint16 activType;
#endif /* defined(DOIP_VERSION) && (DOIP_VERSION == DOIP_ISO_13400_2_2012) */

            /* finish message */
            DoIP_VTcpCon2RxMsgOffset[RxPduId] = 0u;

            /* lock routing activation handler */
            DoIP_VRoutActivHandler.TcpCon = RxPduId;

            /* reset inactivity timer */
            DoIP_VTcpCon2InactivCnt[RxPduId] = 0;

            DOIP_GET_UINT16(reqPtr->TestAddr, 0, testerAddr);
            /* check if any tester with received tester address is configured */
            if ( E_OK != DoIP_VGetTesterIdxByTesterAddr(testerAddr, &testerIdx) )
            { /* tester address is not configured */
              (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
                DOIP_ROUT_ACTIV_RES_CODE_UNKNOWN_TESTER, testerIdx, NULL_PTR, TRUE);
              break;
            }
            DoIP_VRoutActivHandler.TesterIdx = testerIdx;
            DoIP_VRoutActivHandler.TesterAddr = testerAddr;

            /* check if any routing activation is configured for this activation number/type */
#if ( defined(DOIP_VERSION) && (DOIP_VERSION == DOIP_ISO_13400_2_2012) )
            activType = reqPtr->ActivType[0];
#else
            DOIP_GET_UINT16(reqPtr->ActivType, 0, activType);
#endif /* defined(DOIP_VERSION) && (DOIP_VERSION == DOIP_ISO_13400_2_2012) */
            while ( DoIP_VTester[testerIdx].RoutActNum > routActColIdx )
            {
              routActIdx = DoIP_VTester[testerIdx].RoutActColPtr[routActColIdx];
              if ( DoIP_VRoutingActivations[routActIdx].RoutingActivationNum == activType )
              { /* routing activation with corresponding activation number/type found */
                break;
              }
              routActColIdx++;
            }
            if ( DoIP_VTester[testerIdx].RoutActNum == routActColIdx )
            { /* activation type check failed */
              (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
                DOIP_ROUT_ACTIV_RES_CODE_INV_ACTIV_TYPE, testerIdx, NULL_PTR, TRUE);
              break;
            }
            DoIP_VRoutActivHandler.RoutActIdx = routActIdx;

            /* get OEM specific part */
            if ( DOIP_ROUT_ACTIV_REQ_MAX_LEN_BYTE == hdrLen )
            { /* OEM specific part available */
              /* initalize OEM specific part for response */
              DoIP_VRoutActivHandler.OemSpecRes[0] = 0u;
              DoIP_VRoutActivHandler.OemSpecRes[1] = 0u;
              DoIP_VRoutActivHandler.OemSpecRes[2] = 0u;
              DoIP_VRoutActivHandler.OemSpecRes[3] = 0u;

              /* store OEM specific part for request */
              DoIP_VRoutActivHandler.OemSpecReq[0] = reqPtr->Oem[0];
              DoIP_VRoutActivHandler.OemSpecReq[1] = reqPtr->Oem[1];
              DoIP_VRoutActivHandler.OemSpecReq[2] = reqPtr->Oem[2];
              DoIP_VRoutActivHandler.OemSpecReq[3] = reqPtr->Oem[3];

              DoIP_VRoutActivHandler.OemSpecUsed = TRUE;
            }
            else
            {
              DoIP_VRoutActivHandler.OemSpecUsed = FALSE;
            }

            if ( DOIP_INV_TESTER_IDX != DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx )
            { /* a tester is already assigned to this socket connection */
              if ( testerIdx != DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx )
              { /* other TesterAddr is already active on this socket connection -> tx nack and close socket */
                (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
                  DOIP_ROUT_ACTIV_RES_CODE_DIFFERENT_TESTER, testerIdx, NULL_PTR, TRUE);
                break;
              }
              else
              { /* tester address is already active on this socket */
                /* nothing to do here */
              }
            }
            else
            { /* current socket connection has no registered tester */
              PduIdType connection;

              DoIP_VGetConnectionOfTesterAddr(testerAddr, &connection);
              if ( DOIP_INV_PDU_ID != connection )
              { /* TesterAddr is already assigned to another socket -> issue single alive check on this socket */
                if ( E_OK == DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ALIVE_CHECK_REQ, 0u, 0u, 0u,
                    NULL_PTR, FALSE) )
                {
                  DoIP_VRoutActivHandler.AliveCheckList[0] = connection;
                  DoIP_VRoutActivHandler.AliveCheckElemNum = 1u;
                  /* load alive check timer */
                  DoIP_VRoutActivHandler.AliveCheckCnt = DOIP_VALIVE_CHECK_WAIT;
                }
                else
                {
                  DOIP_CallDetReportError(DOIP_API_ID_TP_COPY_RX_DATA, DOIP_E_NOBUFS);
                }
                break;
              }
              else if ( 0u == DoIP_VGetAvailableSockNum(locAddrIdx) )
              { /* all sockets but max one are in use -> issue alive check on all active sockets */
                connection = DOIP_VCONNECTION_TCP_TOTAL;
                while ( 0u < connection )
                {
                  connection--;
                  /* filter local address */
                  if ( DoIP_VCon2LocalAddrIdx[connection] == DoIP_VCon2LocalAddrIdx[RxPduId] )
                  {
                    if ( DOIP_INV_TESTER_IDX != DoIP_VTcpCon2ActivMgt[connection].TesterIdx )
                    { /* valid socket found -> issue alive check */
                      if ( E_OK == DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ALIVE_CHECK_REQ, 0u, 0u, 0u,
                          NULL_PTR, FALSE) )
                      {
                        DoIP_VRoutActivHandler.AliveCheckList[DoIP_VRoutActivHandler.AliveCheckElemNum] = connection;
                        DoIP_VRoutActivHandler.AliveCheckElemNum++;
                      }
                      else
                      {
                        DOIP_CallDetReportError(DOIP_API_ID_TP_COPY_RX_DATA, DOIP_E_NOBUFS);
                      }
                    }
                  }
                }
                /* load alive check timer */
                DoIP_VRoutActivHandler.AliveCheckCnt = DOIP_VALIVE_CHECK_WAIT;
                break;
              }
              else
              { /* tester is not active on a different socket and a TCP_DATA socket is available */
              }
            }

            /* tester already or not yet activated */
            DoIP_VPerformAuthConfAndActivateRouting();
          }
          else
          { /* set bufferSize to length of pending message part */
            *bufferSizePtr = (PduLengthType)((hdrLen + DOIP_GEN_HDR_LEN_BYTE) - DoIP_VTcpCon2RxMsgOffset[RxPduId]);
            DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
          }
          break;
        }
        case DOIP_HDR_TYPE_ALIVE_CHECK_ACK:
        { /* alive check response */
          PduLengthType bytesToCopy;
          
          /* check message length */
          if ( DOIP_MAX_REQUEST_BYTES < hdrLen )
          { /* max length exceeded */
            DoIP_VTcpCon2SkipRxMsg[RxPduId] = TRUE;
            (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, 0u, 0u, NULL_PTR, FALSE);
            break;
          }
          if ( DOIP_ADDR_LEN_BYTE != hdrLen )
          { /* length check failed */
            (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, 0u, 0u, NULL_PTR, TRUE);
            break;
          }

          bytesToCopy = (PduLengthType)((hdrLen + DOIP_GEN_HDR_LEN_BYTE) - DoIP_VTcpCon2RxMsgOffset[RxPduId]);
          if ( bytesToCopy > ((PduLengthType)(PduInfoPtr->SduLength - readDataLen)) )
          {
            bytesToCopy = (PduLengthType)(PduInfoPtr->SduLength - readDataLen);
          }

          if ( bytesToCopy > 0u )
          {
            /* copy data to header buffer */
            /* PRQA S 0310,3305 3 */ /* MD_DoIP_11.4 */
            IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VTcpCon2RxHdrBuf[RxPduId][
                DoIP_VTcpCon2RxMsgOffset[RxPduId]],
              (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&PduInfoPtr->SduDataPtr[readDataLen],
              (uint32)bytesToCopy);
            readDataLen                       += bytesToCopy;
            DoIP_VTcpCon2RxMsgOffset[RxPduId] += bytesToCopy;
          }

          /* check whether message is now copied completely */
          if ( (hdrLen + DOIP_GEN_HDR_LEN_BYTE) == DoIP_VTcpCon2RxMsgOffset[RxPduId] )
          {
            if ( DOIP_INV_TESTER_IDX != DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx )
            {
#if ( defined (DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) )
              if ( DoIP_VTester[DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx].TesterAddr == DOIP_ADDR_ANY )
              { /* default tester */
                uint16 testerAddr;

                DOIP_GET_UINT16(DoIP_VTcpCon2RxHdrBuf[RxPduId], DOIP_GEN_HDR_LEN_BYTE, testerAddr);
                if ( testerAddr == DoIP_VTcpCon2ActivMgt[RxPduId].TesterAddr )
                { /* alive check response with expected tester address */
                  DoIP_VRemoveAliveCheckFromRoutActHandler(RxPduId);
                }
                else
                { /* alive check response with unexpected tester address */
                  /* close socket */
                  DoIP_VCon2SoConClosing[RxPduId] = TRUE;
                  DoIP_VCloseSoCon(RxPduId);
                }
              }
              else
#endif /* defined (DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) */
              { /* no default tester */
                uint16 testerAddr;

                DOIP_GET_UINT16(DoIP_VTcpCon2RxHdrBuf[RxPduId], DOIP_GEN_HDR_LEN_BYTE, testerAddr);
                /* PRQA S 0310 1 */ /* MD_DoIP_11.4 */
                if ( testerAddr == DoIP_VTester[DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx].TesterAddr)
                { /* alive check response with expected tester address */
                  DoIP_VRemoveAliveCheckFromRoutActHandler(RxPduId);
                }
                else
                { /* alive check response with unexpected tester address */
                  /* close socket */
                  DoIP_VCon2SoConClosing[RxPduId] = TRUE;
                  DoIP_VCloseSoCon(RxPduId);
                }
              }
            }

            /* finish message */
            DoIP_VTcpCon2RxMsgOffset[RxPduId] = 0u;
          }
          else
          { /* set bufferSize to length of pending message part */
            *bufferSizePtr = (PduLengthType)((hdrLen + DOIP_GEN_HDR_LEN_BYTE) - DoIP_VTcpCon2RxMsgOffset[RxPduId]);
            DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
          }
          break;
        }
        case DOIP_HDR_TYPE_DIAG_REQ:
        { /* diagnostic message */
          uint8 routActIdx;
          uint8 channelNum;
          PduLengthType bytesToCopy;
          PduInfoType localPduInfoPtr;
          boolean queryBufSize = FALSE;

          /* check message length */
          if ( DOIP_MAX_REQUEST_BYTES < hdrLen )
          { /* max length exceeded */
            DoIP_VTcpCon2SkipRxMsg[RxPduId] = TRUE;
            (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, 0u, 0u, NULL_PTR, FALSE);
            break;
          }
          if ( DOIP_DIAG_MSG_REQ_MIN_LEN_BYTE >= hdrLen )
          { /* length check failed */
            (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, 0u, 0u, NULL_PTR, TRUE);
            break;
          }

#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
          /* PRQA S 0277 2 */ /* MD_DoIP_3.1 */
          if ( (DOIP_INV_PDU_ID != DoIP_VTcpCon2DoIPGwRxChannelActive[RxPduId]) &&
            (DOIP_INV_PDU_ID == DoIP_VTcpCon2RxChannelActive[RxPduId]) )
          { /* channel to PduR is not active anymore but DoIPGw has not yet received message completely */
            /* wait for DoIPGw */
            *bufferSizePtr = 0u;
            DoIP_VTcpCon2LastRxBufSize[RxPduId] = 0u;
            break;
          }
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */

          /* check whether diagnostic message header was copied completely to header buffer */
          if ( (DOIP_GEN_HDR_LEN_BYTE + DOIP_DIAG_MSG_REQ_MIN_LEN_BYTE) > DoIP_VTcpCon2RxMsgOffset[RxPduId] )
          { /* diagnostic message header was not copied completely to header buffer */
            bytesToCopy = (PduLengthType)((DOIP_GEN_HDR_LEN_BYTE + DOIP_DIAG_MSG_REQ_MIN_LEN_BYTE) -
              DoIP_VTcpCon2RxMsgOffset[RxPduId]);

            if ( bytesToCopy > ((PduLengthType)(PduInfoPtr->SduLength - readDataLen)) )
            {
              bytesToCopy = (PduLengthType)(PduInfoPtr->SduLength - readDataLen);
            }

            if ( bytesToCopy > 0u )
            { /* message not copied completely */
              /* copy data to header buffer */
              /* PRQA S 0310,3305 3 */ /* MD_DoIP_11.4 */
              IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VTcpCon2RxHdrBuf[RxPduId][
                DoIP_VTcpCon2RxMsgOffset[RxPduId]],
                (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&PduInfoPtr->SduDataPtr[readDataLen],
                (uint32)bytesToCopy);
              readDataLen                       += bytesToCopy;
              DoIP_VTcpCon2RxMsgOffset[RxPduId] += bytesToCopy;
            }

            /* check whether message header was copied completely */
            if ( (DOIP_GEN_HDR_LEN_BYTE + DOIP_DIAG_MSG_REQ_MIN_LEN_BYTE) == DoIP_VTcpCon2RxMsgOffset[RxPduId] )
            { /* message header copied completely */
              /* PRQA S 0310 5 */ /* MD_DoIP_11.4 */
              P2VAR(DoIP_DiagReqType, AUTOMATIC, DOIP_APPL_VAR) diagReqPtr =
                (P2VAR(DoIP_DiagReqType, AUTOMATIC, DOIP_VAR_NOINIT))&DoIP_VTcpCon2RxHdrBuf[RxPduId][
                DOIP_GEN_HDR_LEN_BYTE];
              uint32    diagMsgLength  = (uint32)(hdrLen - DOIP_DIAG_MSG_REQ_MIN_LEN_BYTE);
#if ( defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) )
              uint32    bestMaxPduSize = 0u;
#endif /* defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) */
              uint16    srcAddr;
              uint16    tgtAddr;
              PduIdType channel = DOIP_INV_PDU_ID;

              DOIP_GET_UINT16(diagReqPtr->SrcAddr, 0, srcAddr);
              DOIP_GET_UINT16(diagReqPtr->TgtAddr, 0, tgtAddr);

              /* set skip message flag - will be reset if PduR buffer could be obtained */
              DoIP_VTcpCon2SkipRxMsg[RxPduId] = TRUE;

              /* check whether routing is active */
              if ( DOIP_ROUT_ACTIV_STATE_ACTIVATED != DoIP_VTcpCon2ActivMgt[RxPduId].ActivState )
              { /* missing routing activation */
                DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                  DOIP_DIAG_MSG_RES_CODE_INVALID_SRC_ADDR, TRUE);
                break;
              }
#if ( defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) )
              if ( DOIP_ADDR_ANY == DoIP_VTester[DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx].TesterAddr )
              { /* default tester */
                if ( srcAddr != DoIP_VTcpCon2ActivMgt[RxPduId].TesterAddr )
                { /* invalid tester address */
                  DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                    DOIP_DIAG_MSG_RES_CODE_INVALID_SRC_ADDR, TRUE);
                  break;
                }
              }
              else
#endif /* defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) */
              { /* no default tester */
                if ( srcAddr != DoIP_VTester[DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx].TesterAddr )
                { /* invalid tester address */
                  DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                    DOIP_DIAG_MSG_RES_CODE_INVALID_SRC_ADDR, TRUE);
                  break;
                }
              }

              routActIdx = DoIP_VTcpCon2ActivMgt[RxPduId].RoutActIdx;
              channelNum = DoIP_VRoutingActivations[routActIdx].ChannelNum;

              while ( 0u < channelNum )
              {
                PduIdType tmpChannel;

                channelNum--;

                tmpChannel = DoIP_VRoutingActivations[routActIdx].ChannelColPtr[channelNum];
#if ( DOIP_VTARGET_ADDR_BIT_MASK_ENABLED == STD_ON )
                if ( ((DoIP_VChannel2EcuAddr[tmpChannel] & DoIP_VChannel2BitMask[tmpChannel]) ==
                    (tgtAddr & DoIP_VChannel2BitMask[tmpChannel])) &&
                  (DoIP_VChannel2TpMaxLen[tmpChannel] != 0u) )
#else
                if ( (DoIP_VChannel2EcuAddr[tmpChannel] == tgtAddr) && (DoIP_VChannel2TpMaxLen[tmpChannel] != 0u) )
#endif /* DOIP_VTARGET_ADDR_BIT_MASK_ENABLED == STD_ON */
                { /* target address is configured for reception for this routing activation */
#if ( defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) )
                  if ( TRUE == DoIP_IsPduSizeRoutingEnabled )
                  {
                    if ( (DoIP_VChannel2MaxPduSize[tmpChannel] >= diagMsgLength) &&
                      ((0u == bestMaxPduSize) || (DoIP_VChannel2MaxPduSize[tmpChannel] < bestMaxPduSize)) )
                    { /* Best fitting target found (up to now) */
                      channel        = tmpChannel;
                      bestMaxPduSize = DoIP_VChannel2MaxPduSize[tmpChannel];
                      if ( DoIP_VChannel2MaxPduSize[tmpChannel] == diagMsgLength )
                      { /* exact match */
                        break;
                      }
                    }
                    else
                    { /* TP max buffer size too small or better match already found */
                      if ( DOIP_INV_PDU_ID == channel )
                      {
                        channel = tmpChannel;
                      }
                    }
                  }
                  else
#endif /* defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) */
                  {
                    if ( TRUE == DoIP_VChannel2IsDefaultChannel[tmpChannel] )
                    {
                      channel = tmpChannel;
                      break; /* PRQA S 0771 */ /* MD_DoIP_14.6 */
                    }
                  }
                }
              }
              if ( DOIP_INV_PDU_ID == channel )
              { /* target address not configured for routing activation */
                /* check if target address is configured at all */
                PduIdType tmpChannel = DOIP_VCHANNELS_TOTAL;

                while (0u < tmpChannel)
                {
                  tmpChannel--;

#if ( DOIP_VTARGET_ADDR_BIT_MASK_ENABLED == STD_ON )
                  if ( ((DoIP_VChannel2EcuAddr[tmpChannel] & DoIP_VChannel2BitMask[tmpChannel]) ==
                      (tgtAddr & DoIP_VChannel2BitMask[tmpChannel])) &&
                    (DoIP_VChannel2TpMaxLen[tmpChannel] != 0u) )
#else
                  if ( (DoIP_VChannel2EcuAddr[tmpChannel] == tgtAddr) && (DoIP_VChannel2TpMaxLen[tmpChannel] != 0u) )
#endif /* DOIP_VTARGET_ADDR_BIT_MASK_ENABLED == STD_ON */
                  { /* target address is configured for reception but not for active routing activation */
                    DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                      DOIP_DIAG_MSG_RES_CODE_TGT_UNREACHABLE, FALSE);
                    break;
                  }
                }

                /* target address is not configured */
                DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                  DOIP_DIAG_MSG_RES_CODE_UNKNOWN_TGT_ADDR, FALSE);
                break;
              }
              else if ( DoIP_VChannel2TpMaxLen[channel] < diagMsgLength )
              { /* max length of target Transport Protocol exceeded */
                DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                  DOIP_DIAG_MSG_RES_CODE_MSG_TOO_LARGE, FALSE);
                break;
              }
#if ( defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) )
              else if ( (TRUE == DoIP_IsPduSizeRoutingEnabled) &&
                (DoIP_VChannel2MaxPduSize[channel] < diagMsgLength) )
              { /* max length of PDU exceeded */
                DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                  DOIP_DIAG_MSG_RES_CODE_MSG_TOO_LARGE, FALSE);
                break;
              }
#endif /* defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) */
#if ( DOIP_VVERIFY_TARGET_ADDR_ENABLED == STD_ON )
              else if ( DoIP_VCallVerifyTargetAddrDirect(tgtAddr) != E_OK )
              { /* target address not accepted */
                DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                  DOIP_DIAG_MSG_RES_CODE_UNKNOWN_TGT_ADDR, FALSE);
                break;
              }
#endif /* DOIP_VVERIFY_TARGET_ADDR_ENABLED == STD_ON */
              else
              { /* valid target address and within max length of the target Transport Protocol */
#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
                /* inform DoIPGw about new reception if target is DoIPGw */
                if ( TRUE == DoIP_VChannel2TargetIsDoIPGw[channel] )
                { /* channel target is DoIPGw */
                  PduInfoType pduInfo;
                  
                  pduInfo.SduDataPtr = &DoIP_VTcpCon2RxHdrBuf[RxPduId][0];
                  pduInfo.SduLength = (PduLengthType)(DOIP_DIAG_HDR_LEN_BYTE + DOIP_GEN_HDR_LEN_BYTE);
                  /* call DoIPGw module */
                  if ( E_OK != DoIPGw_DoIPRxIndication(&pduInfo, E_OK) )
                  { /* call to DoIPGw not successful */
                    DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                      DOIP_DIAG_MSG_RES_CODE_OUT_OF_MEMORY, FALSE);
                    break;
                  }
                  /* set active channel */
                  DoIP_VTcpCon2DoIPGwRxChannelActive[RxPduId] = channel;
                }
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */
                /* call start of reception at PduR */
                if ( BUFREQ_OK != PduR_DoIPTpStartOfReception(DoIP_VChannel2PduRRxPduId[channel], NULL_PTR, 
                  (PduLengthType)(hdrLen - DOIP_DIAG_HDR_LEN_BYTE), bufferSizePtr) )
                { /* no buffer obtained */
#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
                  /* reset active channel and inform DoIPGw about reception abort */
                  if ( TRUE == DoIP_VChannel2TargetIsDoIPGw[channel] )
                  { /* channel target is DoIPGw */
                    PduInfoType pduInfo;

                    pduInfo.SduDataPtr = &DoIP_VTcpCon2RxHdrBuf[RxPduId][0];
                    pduInfo.SduLength = (PduLengthType)(DOIP_DIAG_HDR_LEN_BYTE + DOIP_GEN_HDR_LEN_BYTE);
                    /* reset active channel */
                    /* PRQA S 0277 1 */ /* MD_DoIP_3.1 */
                    DoIP_VTcpCon2DoIPGwRxChannelActive[RxPduId] = DOIP_INV_PDU_ID;
                    /* call DoIPGw module */
                    (void)DoIPGw_DoIPRxIndication(&pduInfo, E_NOT_OK);
                  }
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */
                  DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, tgtAddr, srcAddr,
                    DOIP_DIAG_MSG_RES_CODE_OUT_OF_MEMORY, FALSE);
                  break;
                }
                else
                { /* start of reception successful */
                  DoIP_VTcpCon2SkipRxMsg[RxPduId] = FALSE;
                  DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
                  /* set active channel for this socket connection */
                  DoIP_VTcpCon2RxChannelActive[RxPduId] = channel;
                  DoIP_VTcpCon2LastRxTgtAddr[RxPduId] = tgtAddr;
                  /* set flag to query PduR buffer in next step */
                  queryBufSize = TRUE;
                }
              }
            }
            else
            { /* set bufferSize to length of pending message part */
              *bufferSizePtr = (PduLengthType)((DOIP_DIAG_HDR_LEN_BYTE + DOIP_GEN_HDR_LEN_BYTE) -
                DoIP_VTcpCon2RxMsgOffset[RxPduId]);
              DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
              break;
            }
          }

          /* reception to PduR is active */
          if ( TRUE == queryBufSize )
          { /* query available data length */
            localPduInfoPtr.SduLength  = 0u;
            /* set pointer to dummy data */
            localPduInfoPtr.SduDataPtr = &DoIP_VTcpCon2RxHdrBuf[RxPduId][0];
          }
          else
          { /* set PDU info struct */
            localPduInfoPtr.SduLength  = (PduLengthType)(PduInfoPtr->SduLength - readDataLen);
            localPduInfoPtr.SduDataPtr = &PduInfoPtr->SduDataPtr[readDataLen];
          }

#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
          /* check whether acknowledge message shall contain user data */
          if ( localPduInfoPtr.SduLength > 0u )
          {
            uint8 testerIdx = DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx;

            if ( DoIP_VTester[testerIdx].DiagAckNackNumByte > 0u )
            { /* diagnostic message acknowledge shall contain user data */
              bytesToCopy = (PduLengthType)(DoIP_VTester[testerIdx].DiagAckNackNumByte - 
                DoIP_VTester2DiagNAckOffset[testerIdx]);
              if ( bytesToCopy > localPduInfoPtr.SduLength )
              {
                bytesToCopy = localPduInfoPtr.SduLength;
              }
              if ( 0u < bytesToCopy )
              { /* copy data to DiagNAck buffer */
                /* PRQA S 0310,3305 4 */ /* MD_DoIP_11.4 */
                IpBase_Copy(
                  (P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VTester[testerIdx].DiagAckNackBufPtr[
                    DoIP_VTester2DiagNAckOffset[testerIdx]], 
                  (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&PduInfoPtr->SduDataPtr[readDataLen],
                  (uint32)bytesToCopy);
                DoIP_VTester2DiagNAckOffset[testerIdx] += bytesToCopy;
              }
            }
          }
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) */

          /* call CopyRxData of PduR */
          if ( BUFREQ_OK != PduR_DoIPTpCopyRxData(DoIP_VChannel2PduRRxPduId[DoIP_VTcpCon2RxChannelActive[
              RxPduId]], &localPduInfoPtr, bufferSizePtr) )
          { /* CopyRxData call was not successful */
            uint16 testerAddr;
            uint16 entityAddr = DoIP_VTcpCon2LastRxTgtAddr[RxPduId];

            /* send diagnostic message negative acknowledge */
#if ( defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) )
            if ( DoIP_VTester[DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx].TesterAddr == DOIP_ADDR_ANY )
            { /* default tester */
              testerAddr = DoIP_VTcpCon2ActivMgt[RxPduId].TesterAddr;
            }
            else
#endif /* defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) */
            { /* no default tester */
              testerAddr = DoIP_VTester[DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx].TesterAddr;
            }
            DoIP_VTcpPrepareTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_NACK, entityAddr, testerAddr,
              DOIP_DIAG_MSG_RES_CODE_NETWORK_TRANSPROT, FALSE);
            /* call PduR */
            PduR_DoIPTpRxIndication(DoIP_VChannel2PduRRxPduId[DoIP_VTcpCon2RxChannelActive[RxPduId]], E_NOT_OK);
#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
            /* reset active channel if target is DoIPGw */
            if ( TRUE == DoIP_VChannel2TargetIsDoIPGw[DoIP_VTcpCon2RxChannelActive[RxPduId]] )
            { /* channel target is DoIPGw */
              DoIP_VTcpCon2DoIPGwRxChannelActive[RxPduId] = DOIP_INV_PDU_ID;
            }
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */
            /* reset active channel */
            DoIP_VTcpCon2RxChannelActive[RxPduId] = DOIP_INV_PDU_ID;
            /* skip message */
            DoIP_VTcpCon2SkipRxMsg[RxPduId] = TRUE;
          }
          else
          { /* CopyRxData call was successful */
            PduLengthType bytesLeft = (PduLengthType)((DOIP_GEN_HDR_LEN_BYTE + hdrLen) -
              (DoIP_VTcpCon2RxMsgOffset[RxPduId] + localPduInfoPtr.SduLength));

            if (bytesLeft < *bufferSizePtr)
            { /* upper layer has more buffer than expected */
              *bufferSizePtr = bytesLeft;
            }
            DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;

            /* PRQA S 3356,3359,3201 11 */ /* MD_DoIP_13.7_TOOL */
            if ( 0u == bytesLeft )
            { /* entire message is processed */
              /* send diagnostic message positive acknowledge */
              (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_DIAG_ACK, DoIP_VTcpCon2LastRxTgtAddr[RxPduId],
                0u, 0u, NULL_PTR, FALSE);
              /* call PduR */
              PduR_DoIPTpRxIndication(DoIP_VChannel2PduRRxPduId[DoIP_VTcpCon2RxChannelActive[RxPduId]], E_OK);
              /* finish message */
              DoIP_VTcpCon2RxMsgOffset[RxPduId] = 0u;
              /* reset active channel */
              DoIP_VTcpCon2RxChannelActive[RxPduId] = DOIP_INV_PDU_ID;
            }
            else
            { /* another part of the message is received */
              /* increment offset */
              DoIP_VTcpCon2RxMsgOffset[RxPduId] += localPduInfoPtr.SduLength;
            }
          }

          readDataLen += localPduInfoPtr.SduLength;
          break;
        }
        case DOIP_HDR_TYPE_GEN_NACK:
        case DOIP_HDR_TYPE_VEHICLE_IDENT_REQ:
#if ( defined(DOIP_VVEHICLE_IDENT_EID_SUPPORT) && (STD_ON == DOIP_VVEHICLE_IDENT_EID_SUPPORT) )
        case DOIP_HDR_TYPE_VEHICLE_IDENT_REQ_EID:
#endif /* defined(DOIP_VVEHICLE_IDENT_EID_SUPPORT) && (STD_ON == DOIP_VVEHICLE_IDENT_EID_SUPPORT) */
        case DOIP_HDR_TYPE_VEHICLE_IDENT_REQ_VIN:
        case DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT:
        case DOIP_HDR_TYPE_ROUT_ACTIV_ACK:
        case DOIP_HDR_TYPE_ALIVE_CHECK_REQ:
        case DOIP_HDR_TYPE_ENTITY_STATE_REQ:
        case DOIP_HDR_TYPE_ENTITY_STATE_ACK:
        case DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_REQ:
        case DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_ACK:
        case DOIP_HDR_TYPE_DIAG_ACK:
        case DOIP_HDR_TYPE_DIAG_NACK:
        { /* not relevant payload type */
          DoIP_VTcpCon2SkipRxMsg[RxPduId] = TRUE;
          break;
        }
        default:
        { /* unknown payload type */
#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
# if ( DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u )
          PduLengthType bytesToCopy;
# endif /* DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u */
          PduInfoType rxUserData;
          PduInfoType txUserData;
          uint16 txHdrType = DOIP_HDR_TYPE_INVALID;
          uint8 flags;

          /* check length */
          if ( hdrLen > DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE )
          { /* unsupported header length */
            DoIP_VTcpCon2SkipRxMsg[RxPduId] = TRUE;
            (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, 0u, 0u, NULL_PTR, FALSE);
            break;
          }

          /* set flags for callback */
          flags = DOIP_OEM_PAYLOAD_TYPE_FLAG_PROT_TCP;
          if ( DoIP_VTcpCon2ActivMgt[RxPduId].ActivState == DOIP_ROUT_ACTIV_STATE_ACTIVATED )
          {
            flags |= DOIP_OEM_PAYLOAD_TYPE_FLAG_ROUT_ACTIV;
          }

# if ( DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u )
          /* check buffer availability */
          if ( DoIP_VOemPayloadTypeTcpBuf2Con != DOIP_INV_PDU_ID )
          { /* buffer is already used */
            if ( (DoIP_VOemPayloadTypeTcpBuf2Con != RxPduId) || (DoIP_VOemPayloadTypeTcpBufIsTx == TRUE) )
            { /* buffer is used by another connection or buffer is used for transmission */
              /* wait until buffer is free again */
              *bufferSizePtr = 0u;
              DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
              break;
            }
          }
          else
          { /* buffer is not used */
            /* occupy buffer */
            DoIP_VOemPayloadTypeTcpBuf2Con = RxPduId;
          }

          /* copy to OEM specific payload type user data buffer */
          bytesToCopy = (PduLengthType)((hdrLen + DOIP_GEN_HDR_LEN_BYTE) - DoIP_VTcpCon2RxMsgOffset[RxPduId]);
          if ( bytesToCopy > ((PduLengthType)(PduInfoPtr->SduLength - readDataLen)) )
          {
            bytesToCopy = (PduLengthType)(PduInfoPtr->SduLength - readDataLen);
          }

          if ( bytesToCopy > 0u )
          {
            /* copy data */
            /* PRQA S 0310,3305 3 */ /* MD_DoIP_11.4 */
            IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VOemPayloadTypeTcpBuf[
              DoIP_VTcpCon2RxMsgOffset[RxPduId] - DOIP_GEN_HDR_LEN_BYTE],
              (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&PduInfoPtr->SduDataPtr[readDataLen],
              (uint32)bytesToCopy);
            readDataLen                       += bytesToCopy;
            DoIP_VTcpCon2RxMsgOffset[RxPduId] += bytesToCopy;
          }

          /* check whether message is now copied completely */
          if ( (hdrLen + DOIP_GEN_HDR_LEN_BYTE) == DoIP_VTcpCon2RxMsgOffset[RxPduId] )
          {
            rxUserData.SduDataPtr = DoIP_VOemPayloadTypeTcpBuf;
            rxUserData.SduLength  = (PduLengthType)(DoIP_VTcpCon2RxMsgOffset[RxPduId] - DOIP_GEN_HDR_LEN_BYTE);

            /* use rx buffer as tx buffer to save RAM */
            txUserData.SduDataPtr = DoIP_VOemPayloadTypeTcpBuf;
            txUserData.SduLength  = DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE;

            /* call user callback to forward message to upper layer */
            if ( DoIP_VCallOemPayloadTypeDirect(hdrType, &rxUserData, flags, &txHdrType, &txUserData) == E_NOT_OK )
            { /* unknown payload type */
              (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE, 0u, 0u, NULL_PTR, FALSE);

              DoIP_VOemPayloadTypeTcpBuf2Con = DOIP_INV_PDU_ID;
            }
            else
            { /* payload type known by user */
              if ( txHdrType != DOIP_HDR_TYPE_INVALID )
              { /* send response */
                if ( txUserData.SduLength <= DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE )
                { /* response has valid length */
                  DoIP_VOemPayloadTypeTcpBufLen = (uint16)txUserData.SduLength;
                  if ( txUserData.SduLength > 0u )
                  {
                    DoIP_VOemPayloadTypeTcpBufIsTx = TRUE;
                  }
                  /* send response */
                  if ( DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_OEM_SPECIFIC, txHdrType, 0u, 0u, NULL_PTR, FALSE) ==
                      E_NOT_OK)
                  { /* response could not be sent */
                    DoIP_VOemPayloadTypeTcpBuf2Con = DOIP_INV_PDU_ID;
                  }
                }
                else
                { /* response has invalid length - ignore response */
                  DoIP_VOemPayloadTypeTcpBuf2Con = DOIP_INV_PDU_ID;
                }
              }
              else
              { /* no response */
                DoIP_VOemPayloadTypeTcpBuf2Con = DOIP_INV_PDU_ID;
              }
            }

            /* finish message */
            DoIP_VTcpCon2RxMsgOffset[RxPduId] = 0u;
          }
          else
          {
            *bufferSizePtr = (PduLengthType)(hdrLen - (DOIP_GEN_HDR_LEN_BYTE - DoIP_VTcpCon2RxMsgOffset[RxPduId]));
             DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
          }
# else
          rxUserData.SduDataPtr = NULL_PTR;
          rxUserData.SduLength  = 0u;

          txUserData.SduDataPtr = NULL_PTR;
          txUserData.SduLength  = 0u;

          /* call user callback to forward message to upper layer */
          if ( DoIP_VCallOemPayloadTypeDirect(hdrType, &rxUserData, flags, &txHdrType, &txUserData) == E_NOT_OK )
          { /* unknown payload type */
            (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE, 0u, 0u, NULL_PTR, FALSE);
          }
          else
          { /* payload type known by user */
            if ( txHdrType != DOIP_HDR_TYPE_INVALID )
            { /* send response */
              (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_OEM_SPECIFIC, txHdrType, 0u, 0u, NULL_PTR, FALSE);
            }
          }

          /* finish message */
          DoIP_VTcpCon2RxMsgOffset[RxPduId] = 0u;
# endif /* DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u */
#else
          DoIP_VTcpCon2SkipRxMsg[RxPduId] = TRUE;
          (void)DoIP_VTcpTransmit(RxPduId, DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE, 0u, 0u, NULL_PTR, FALSE);
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */
        }
      }
      
      if ( TRUE == DoIP_VTcpCon2SkipRxMsg[RxPduId] )
      { /* message shall be skipped */
        /* set buffer size to receive entire message in next function call */
        *bufferSizePtr = (PduLengthType)((DOIP_GEN_HDR_LEN_BYTE + hdrLen) - DoIP_VTcpCon2RxMsgOffset[RxPduId]);
        DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
      }
    }
    else
    {
      *bufferSizePtr = DOIP_GEN_HDR_LEN_BYTE - DoIP_VTcpCon2RxMsgOffset[RxPduId];
      DoIP_VTcpCon2LastRxBufSize[RxPduId] = *bufferSizePtr;
    }
  } while ( PduInfoPtr->SduLength > readDataLen );

  if ( 0u == DoIP_VTcpCon2RxMsgOffset[RxPduId] )
  { /* message processed completely */
#if ( DOIP_VTCP_RX_MULTI_MSG == STD_ON )
# if ( DOIP_NACK_APPEND_REQ == STD_ON )
    if ( DOIP_INV_TESTER_IDX != DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx )
    { /* the feature to send previously received user data cannot be used if tester could not be determined */
      if ( 0u < DoIP_VTester2DiagNAckOffset[DoIP_VTcpCon2ActivMgt[RxPduId].TesterIdx] )
      { /* diagnostic message acknowledge is pending - do not accept new data until acknowledge is sent */
        *bufferSizePtr = 0u;
        DoIP_VTcpCon2LastRxBufSize[RxPduId] = 0u;
      }
    }
    else
# endif /* DOIP_NACK_APPEND_REQ == STD_ON */
    {
      *bufferSizePtr = DOIP_GEN_HDR_LEN_BYTE;
      DoIP_VTcpCon2LastRxBufSize[RxPduId] = DOIP_GEN_HDR_LEN_BYTE;
    }
#else
    *bufferSizePtr = 0u;
    DoIP_VTcpCon2LastRxBufSize[RxPduId] = 0u;
#endif /* DOIP_VTCP_RX_MULTI_MSG == STD_ON */
  }
  else if ( DoIP_VTcpTxQueueGetLevel(RxPduId) >= (DOIP_VTCP_TX_MGT_QUEUE_SIZE - 1u) )
  { /* high tx queue fill level - slow down rx path */
    *bufferSizePtr = 0u;
    DoIP_VTcpCon2LastRxBufSize[RxPduId] = 0u;
  }
  else if ( (DOIP_ROUT_ACTIV_STATE_AUTH_PENDING == DoIP_VTcpCon2ActivMgt[RxPduId].ActivState) ||
    (DOIP_ROUT_ACTIV_STATE_CONF_PENDING == DoIP_VTcpCon2ActivMgt[RxPduId].ActivState) )
  { /* activation state is pending */
    /* stop reception until state changes */
    *bufferSizePtr = 0u;
    DoIP_VTcpCon2LastRxBufSize[RxPduId] = 0u;
  }
  else
  {
    /* nothing to do here */
  }

  return BUFREQ_OK;
}
/* PRQA L:DoIP_14_6 */
/* PRQA L:DoIP_16_7 */
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STCAL */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_SoAdTpRxIndication
 *********************************************************************************************************************/
/*! \brief      Receive indication callback for TP
 *  \param[in]  RxPduId        RX indication PDU ID
 *  \param[in]  result         Result of reception
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdTpRxIndication(PduIdType RxPduId, Std_ReturnType result)
{ /* will be called when socket connection shall be closed  */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_UNINIT != DoIP_State), DOIP_API_ID_TP_RX_INDICATION, DOIP_E_UNINIT);
  DOIP_CheckDetErrorReturnVoid((DOIP_VCONNECTION_TCP_TOTAL > RxPduId), DOIP_API_ID_TP_RX_INDICATION,
    DOIP_E_INVALID_PDU_SDU_ID);
  DOIP_CheckDetErrorReturnVoid(((NTFRSLT_OK == result) || (NTFRSLT_E_NOT_OK == result)),
    DOIP_API_ID_TP_RX_INDICATION, DOIP_E_INVALID_PARAMETER);

  /* TP session is now offline */
  DoIP_VTcpCon2RxTpSessionActive[RxPduId] = FALSE;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  DoIP_SoAdIfTxConfirmation
 *********************************************************************************************************************/
/*! \brief      Transmission confirmation callback for IF
 *  \param[in]  TxPduId        TX confirmation PDU ID
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoAdIfTxConfirmation(PduIdType TxPduId)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_IF_TX_CONFIRMATION, DOIP_E_UNINIT);
  DOIP_CheckDetErrorReturnVoid(((DOIP_VCONNECTION_TOTAL > TxPduId) && (DOIP_VCONNECTION_TCP_TOTAL <= TxPduId)),
    DOIP_API_ID_IF_TX_CONFIRMATION, DOIP_E_INVALID_PDU_SDU_ID);

  /* prevent compiler warnings for unused parameter */
  DOIP_DUMMY_STATEMENT_VAR(TxPduId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  DoIP_SoAdTpCopyTxData
 *********************************************************************************************************************/
/*! \brief      queries transmit data of a PDU
 *  \param[in]  TxPduId             TX confirmation PDU ID
 *  \param[in]  PduInfoPtr          pointer to destination buffer and length
 *  \param[in]  retry               retry is not by SoAd supported ( NULL_PTR )
 *  \param[out] availableDataPtr    remaining buffer length in DoIP Tx Buffer
 *  \return     BUFREQ_OK           data has been copied sucessful
 *  \return     BUFREQ_E_BUSY       data could temporarily not be copied
 *  \return     BUFREQ_E_NOT_OK     data has not been copied
 *  \context    interrupt or task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 3673 DoIP_16_7 */ /* MD_DoIP_16.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_SoAdTpCopyTxData(PduIdType TxPduId,
                        P2VAR(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
                        P2VAR(RetryInfoType, AUTOMATIC, DOIP_APPL_VAR) retry,
                        P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) availableDataPtr)
{
  BufReq_ReturnType bufReqRetVal;

  DOIP_CheckDetErrorReturnValue((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_TP_COPY_TX_DATA, DOIP_E_UNINIT,
    BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((DOIP_VCONNECTION_TCP_TOTAL > TxPduId), DOIP_API_ID_TP_COPY_TX_DATA,
    DOIP_E_INVALID_PDU_SDU_ID, BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((NULL_PTR != PduInfoPtr), DOIP_API_ID_TP_COPY_TX_DATA, DOIP_E_PARAM_POINTER,
    BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((NULL_PTR != availableDataPtr), DOIP_API_ID_TP_COPY_TX_DATA, DOIP_E_PARAM_POINTER,
    BUFREQ_E_NOT_OK);
  DOIP_CheckDetErrorReturnValue((NULL_PTR == retry), DOIP_API_ID_TP_COPY_TX_DATA, DOIP_E_INVALID_PARAMETER,
    BUFREQ_E_NOT_OK);

  if ( PduInfoPtr->SduLength != 0 )
  {
    DOIP_CheckDetErrorReturnValue((NULL_PTR != PduInfoPtr->SduDataPtr), DOIP_API_ID_TP_COPY_TX_DATA,
      DOIP_E_PARAM_POINTER, BUFREQ_E_NOT_OK);
  }

  /* check socket connection state */
  if ( SOAD_SOCON_ONLINE != DoIP_VCon2SoConState[TxPduId] )
  { /* socket connection is not online */
    bufReqRetVal = BUFREQ_E_NOT_OK;
  }
  else
  {
    /* TxPduId is equal to index for Connection */
    bufReqRetVal = DoIP_VTcpTxQueueCopyElement(TxPduId, PduInfoPtr, availableDataPtr);
  }

  DOIP_DUMMY_STATEMENT_VAR(retry); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  return bufReqRetVal;
}
/* PRQA L:MSR_14_7 */
/* PRQA L: DoIP_16_7 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_SoAdTpTxConfirmation
 *********************************************************************************************************************/
/*! \brief      transmission confirmation callback for TP
 *  \param[in]  TxPduId        TX confirmation PDU ID
 *  \param[in]  result         result of TP session
 *  \context    interrupt or task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
FUNC(void, DOIP_CODE) DoIP_SoAdTpTxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_UNINIT != DoIP_State), DOIP_API_ID_TP_TX_CONFIRMATION, DOIP_E_UNINIT);
  DOIP_CheckDetErrorReturnVoid((DOIP_VCONNECTION_TCP_TOTAL > TxPduId), DOIP_API_ID_TP_TX_CONFIRMATION,
    DOIP_E_INVALID_PDU_SDU_ID);
  DOIP_CheckDetErrorReturnVoid(((NTFRSLT_OK == result) || (NTFRSLT_E_NOT_OK == result)),
    DOIP_API_ID_TP_TX_CONFIRMATION, DOIP_E_INVALID_PARAMETER);

  /*lint -e662 -e661 */

#if ( defined(DOIP_VSUPPORT_SHUTDOWN) && (STD_ON == DOIP_VSUPPORT_SHUTDOWN) )
  if ( DOIP_STATE_INIT == DoIP_State )
#endif /* defined(DOIP_VSUPPORT_SHUTDOWN) && (STD_ON == DOIP_VSUPPORT_SHUTDOWN) */
  {
    DoIP_VTcpTxQueueRemoveElement(TxPduId, result);

#if ( defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) )
    /* reset cancellation */
    if ( TRUE == DoIP_VTcpCon2TxTpCancelRequested[TxPduId] )
    {
      DoIP_VTcpCon2TxTpCancelRequested[TxPduId] = FALSE;
    }
#endif /* defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) */

    if ( (TRUE == DoIP_VCon2SoConClosing[TxPduId]) && (0u == DoIP_VTcpTxQueueGetLevel(TxPduId)) )
    { /* socket shall be closed */
      DoIP_VCloseSoCon(TxPduId);
    }
    else
    { /* check if Tx Queue contains elements */
#if ( DOIP_VTP_OPTIMZED_ENABLED == STD_OFF )
      if ( 0u < DoIP_VTcpTxQueueGetLevel(TxPduId) )
      { /* Tx Queue not empty, start transmission */
        DoIP_VTcpTxQueueSend(TxPduId);
      }
#endif /* DOIP_VTP_OPTIMZED_ENABLED == STD_OFF */
    }
  }

  /*lint +e662 +e661 */
}
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STPTH */

/**********************************************************************************************************************
 *  DoIP_SoConModeChg
 *********************************************************************************************************************/
/*! \brief      socket state change callback
 *  \param[in]  SoConId            socket connection identifier
 *  \param[in]  Mode               new mode
 *  \context    interrupt or task level
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(void, DOIP_CODE) DoIP_SoConModeChg(SoAd_SoConIdType SoConId, SoAd_SoConModeType Mode)
{
  PduIdType connection;

  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_UNINIT != DoIP_State), DOIP_API_ID_SO_CON_MODE_CHG, DOIP_E_UNINIT);

#if ( defined(DOIP_VSUPPORT_SHUTDOWN) && (STD_ON == DOIP_VSUPPORT_SHUTDOWN) )
  if ( DOIP_STATE_INIT == DoIP_State )
#endif /* defined(DOIP_VSUPPORT_SHUTDOWN) && (STD_ON == DOIP_VSUPPORT_SHUTDOWN) */
  {
    if ( E_OK == DoIP_VGetConnectionBySoConId(SoConId, &connection) )
    {
      if ( (SOAD_SOCON_OFFLINE == Mode) || (SOAD_SOCON_ONLINE == Mode) || (SOAD_SOCON_RECONNECT == Mode) )
      {
        if ( SOAD_SOCON_ONLINE != Mode )
        { /* terminate all transmission requests */
          DoIP_VCon2SoConState[connection] = Mode;
          DoIP_VCon2SoConClosing[connection] = FALSE;

          if ( DOIP_VCONNECTION_TCP_TOTAL > connection )
          { /* TCP connection */
            PduIdType idx;

            /* reset socket connection specific structs */
#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
            if ( DOIP_INV_TESTER_IDX != DoIP_VTcpCon2ActivMgt[connection].TesterIdx )
            {
              DoIP_VTester2DiagNAckOffset[DoIP_VTcpCon2ActivMgt[connection].TesterIdx] = 0u;
            }
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) */
            DoIP_VTcpCon2ActivMgt[connection].TesterIdx    = DOIP_INV_TESTER_IDX;
            DoIP_VTcpCon2ActivMgt[connection].TesterAddr   = DOIP_ADDR_ANY;
            DoIP_VTcpCon2ActivMgt[connection].RoutActIdx   = DOIP_INV_ROUT_ACT_IDX;
            DoIP_VTcpCon2ActivMgt[connection].ActivState   = DOIP_ROUT_ACTIV_STATE_NONE;
            DoIP_VTcpCon2InactivCnt[connection]            = 0u;
            DoIP_VTcpCon2RxMsgOffset[connection]           = 0u;
            DoIP_VTcpCon2TxBytesCopied[connection]         = 0u;
            DoIP_VTcpCon2TxTpSessionActive[connection]     = FALSE;
            DoIP_VTcpCon2RxTpSessionActive[connection]     = FALSE;
            DoIP_VTcpCon2SkipRxMsg[connection]             = FALSE;
            DoIP_VTcpCon2TpPreTransMgt[connection].HdrType = DOIP_HDR_TYPE_INVALID;
#if ( defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) )
            DoIP_VTcpCon2TxTpCancelRequested[connection]   = FALSE;
#endif /* defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) */
#if ( defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) )
            DoIP_VTcpCon2RxTpCancelRequested[connection]   = FALSE;
#endif /* defined(DOIP_VPROVIDE_CANCEL_RECEIVE_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_RECEIVE_API) */
#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
            DoIP_VTcpCon2DoIPGwRxChannelActive[connection] = DOIP_INV_PDU_ID;
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */

            /* alive check ongoing */
            if ( DOIP_INV_PDU_ID != DoIP_VRoutActivHandler.TcpCon )
            { /* Routing Activation active */
              if ( 0u < DoIP_VRoutActivHandler.AliveCheckElemNum )
              {
                uint8 listIdx = DOIP_VMAX_CONS_PER_LOC_ADDR;

                while ( 0u < listIdx )
                {
                  listIdx--;
                  if ( connection == DoIP_VRoutActivHandler.AliveCheckList[listIdx] )
                  { /* alive check pending */
                    DoIP_VRoutActivHandler.AliveCheckList[listIdx] = DOIP_INV_PDU_ID;
                    DoIP_VRoutActivHandler.AliveCheckElemNum--;
                  }
                }
              }
              if ( (0u == DoIP_VRoutActivHandler.AliveCheckElemNum) &&
                (SOAD_SOCON_ONLINE != DoIP_VCon2SoConState[DoIP_VRoutActivHandler.TcpCon]) )
              { /* all routing activation relevant socket connections closed or alive check received */
                /* release handler */
                DoIP_VRoutActivHandler.TcpCon = DOIP_INV_PDU_ID;
              }
            }

            /* PRQA S 0277 1 */ /* MD_DoIP_3.1 */
            if ( DOIP_INV_PDU_ID != DoIP_VTcpCon2RxChannelActive[connection] )
            { /* reception is ongoing */
              PduR_DoIPTpRxIndication(DoIP_VChannel2PduRRxPduId[DoIP_VTcpCon2RxChannelActive[connection]],
                E_NOT_OK);
              DoIP_VTcpCon2RxChannelActive[connection] = DOIP_INV_PDU_ID;
            }

            /* reset Tx Queue */
            while ( 0u < DoIP_VTcpTxQueueGetLevel(connection) )
            {
              DoIP_VTcpTxQueueRemoveElement(connection, E_NOT_OK);
            }

            /* reset channel specific structs */
            idx = DOIP_VCHANNELS_TOTAL;
            while ( 0u < idx )
            {
              idx--;

              if ( connection == DoIP_VChannel2TcpCon[idx] )
              {
                DoIP_VChannel2TcpCon[idx]   = DOIP_INV_PDU_ID;
                DoIP_VChannel2TxMsgLen[idx] = 0u;
              }
            }
          }
          else
          { /* UDP connection */
            uint16 idx = DOIP_VUDP_TX_MGT_LIST_SIZE;

            /* reset Tx list */
            while ( 0u < idx )
            {
              idx--;
              if ( DoIP_VUdpTxMgtList[idx].UdpCon == connection )
              {
#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
                if ( DoIP_VUdpTxMgtList[idx].HdrType == DOIP_HDR_TYPE_OEM_SPECIFIC )
                {
                  DoIP_VOemPayloadTypeUdpBufLen = 0u;
                }
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */

                DoIP_VUdpTxMgtList[idx].UdpCon = DOIP_INV_PDU_ID;
              }
            }
          }
        }
        else
        { /* socket connection is online */
          if ( SOAD_IPADDR_STATE_ASSIGNED == DoIP_VCon2IpAddrState[connection] )
          { /* IP address assigned */
            DoIP_VCon2SoConState[connection] = Mode;
            DoIP_VCon2SoConClosing[connection] = FALSE;

            if ( connection >= DOIP_VCONNECTION_TCP_UDP_TOTAL )
            { /* UDP Vehicle Announcement connection */
              /* trigger Vehicle Announcements */
              /* list Vehicle Announcement in Tx list */
              if ( E_OK != DoIP_VUdpTransmit(connection, DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT, DOIP_VANNOUNCE_NUM,
                  FALSE) )
              { /* buffer overflow after socket connection setup should not happen */
                DOIP_CallDetReportError(DOIP_API_ID_SO_CON_MODE_CHG, DOIP_E_NOBUFS);
              }
            }
          }
          else
          {
            DOIP_CallDetReportError(DOIP_API_ID_SO_CON_MODE_CHG, DOIP_E_UNEXPECTED_ASSIGNMENT);
          }
        }
      }
      else
      { /* invalid Mode */
        DOIP_CallDetReportError(DOIP_API_ID_SO_CON_MODE_CHG, DOIP_E_INVALID_PARAMETER);
      }
    }
    else
    { /* invalid SoConId */
      DOIP_CallDetReportError(DOIP_API_ID_SO_CON_MODE_CHG, DOIP_E_INVALID_PARAMETER);
    }
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_LocalIpAddrAssignmentChg
 *********************************************************************************************************************/
/*! \brief      IP address assignment change callback
 *  \param[in]  SoConId            socket connection identifier
 *  \param[in]  State              state
 *  \context    interrupt or task level
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(void, DOIP_CODE) DoIP_LocalIpAddrAssignmentChg(SoAd_SoConIdType SoConId, SoAd_IpAddrStateType State)
{
  PduIdType connection;

  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_UNINIT != DoIP_State), DOIP_API_ID_LOC_IP_ADDR_ASSIGN_CHG,
    DOIP_E_UNINIT);

  if ( E_OK == DoIP_VGetConnectionBySoConId(SoConId, &connection) )
  {
    if ( (SOAD_IPADDR_STATE_ASSIGNED == State) ||
         (SOAD_IPADDR_STATE_UNASSIGNED == State) ||
         (SOAD_IPADDR_STATE_ONHOLD == State) )
    {
      uint8 addrIdx = DoIP_VCon2LocalAddrIdx[connection];

      switch(DoIP_ActivationLineLocalState)
      {
        case DOIP_ACTIVATION_LINE_LOCAL_ACTIVE:
        {
          DoIP_VCon2IpAddrState[connection] = State;
          if ( SOAD_IPADDR_STATE_UNASSIGNED == State )
          {
            DoIP_VLocalAddrIdx2IpAddrReqState[addrIdx] = DOIP_IP_ADDR_REQ_STATE_NONE;
            /* request socket connection close to reset open/close sequence in SoAd */
            DoIP_VCloseSoCon(connection);
          }
          else if ( SOAD_IPADDR_STATE_ASSIGNED == State )
          {
            DoIP_VLocalAddrIdx2IpAddrReqState[addrIdx] = DOIP_IP_ADDR_REQ_STATE_ASSIGNED;
            /* open socket connections initially after IP address reassignment */
            DoIP_VOpenSockConInitially(connection);
          }
          else
          {
            /* nothing to do */
          }
          break;
        }
#if ( defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) )
        case DOIP_ACTIVATION_LINE_LOCAL_ACTIVE_TO_INACTIVE:
        {
          DoIP_VCon2IpAddrState[connection] = State;
          if ( SOAD_IPADDR_STATE_UNASSIGNED == State )
          { /* IP address not assigned */
            /* IpAddrReqState is set multiple times (for each SoConId) */
            DoIP_VLocalAddrIdx2IpAddrReqState[addrIdx] = DOIP_IP_ADDR_REQ_STATE_NONE;
          }
          break;
        }
#endif /* defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) */
        default:
        { /* invalid state */
          DOIP_CallDetReportError(DOIP_API_ID_LOC_IP_ADDR_ASSIGN_CHG, DOIP_E_UNEXPECTED_ASSIGNMENT);
        }
      }
    }
    else
    { /* unknown state */
      DOIP_CallDetReportError(DOIP_API_ID_LOC_IP_ADDR_ASSIGN_CHG, DOIP_E_INVALID_PARAMETER);
    }
  }
  else
  { /* unknown SoConId */
    DOIP_CallDetReportError(DOIP_API_ID_LOC_IP_ADDR_ASSIGN_CHG, DOIP_E_INVALID_PARAMETER);
  }
}
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_ActivationLineSwitch
 *********************************************************************************************************************/
/*! \brief      Notifies DoIP on a switch of the DoIPActivationLine. Must not be called if configuration container
 *              DoIPActivationLineStateCallback does not exist.
 *  \param[in]  void none
 *  \return     none
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
FUNC(void, DOIP_CODE) DoIP_ActivationLineSwitch(void)
{
#if ( defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) )
  DoIP_ActivationLineType state;

  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_ACTIVATION_LINE_SWITCH, DOIP_E_UNINIT);

  DoIP_VCallActivationLineStateDirect(&state);
  if ( DOIP_ACTIVATION_LINE_INACTIVE == state )
  { /* switch to inactive */
    DoIP_ActivationLineState = DOIP_ACTIVATION_LINE_INACTIVE;
  }
  else
  { /* switch to active */
    DoIP_ActivationLineState = DOIP_ACTIVATION_LINE_ACTIVE;
  }
#else
  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_ACTIVATION_LINE_SWITCH, DOIP_E_UNINIT);
  /* activation line switch not supported since callback is not configured */
  DOIP_CallDetReportError(DOIP_API_ID_ACTIVATION_LINE_SWITCH, DOIP_E_ACTIVATION_LINE);
#endif /* defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) */
}
/* PRQA L:MSR_14_7 */

#if ( defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) )
/**********************************************************************************************************************
 *  DoIP_EnablePduSizeRouting
 *********************************************************************************************************************/
/*! \brief      Activates the DoIP packet size dependent routing
 *  \param[in]  void none
 *  \return     none
 *  \pre        Module initialized and DoIP PduSizeRouting must be enabled
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_EnablePduSizeRouting(void)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_ENABLE_PDU_SIZE_ROUTING, DOIP_E_UNINIT);

  DoIP_IsPduSizeRoutingEnabled = TRUE;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  DoIP_DisablePduSizeRouting
 *********************************************************************************************************************/
/*! \brief      Deactivates the DoIP packet size dependent routing
 *  \param[in]  void none
 *  \return     none
 *  \pre        Module initialized and DoIP PduSizeRouting must be enabled
 *  \context    Task level
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_DisablePduSizeRouting(void)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  DOIP_CheckDetErrorReturnVoid((DOIP_STATE_INIT == DoIP_State), DOIP_API_ID_DISABLE_PDU_SIZE_ROUTING, DOIP_E_UNINIT);

  DoIP_IsPduSizeRoutingEnabled = FALSE;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#endif /* defined(DOIP_VSUPPORT_PDU_SIZE_ROUTING) && (STD_ON == DOIP_VSUPPORT_PDU_SIZE_ROUTING) */

#if ( defined(DOIP_VSUPPORT_SHUTDOWN) && (STD_ON == DOIP_VSUPPORT_SHUTDOWN) )
/**********************************************************************************************************************
 *  DoIP_Shutdown
 *********************************************************************************************************************/
/*! \brief      Shutdown TcpIp stack (i.e. all sockets will be closed and modules change to special shutdown state)
 *  \param[in]  void none
 *  \return     E_OK                Successful
 *  \return     E_NOT_OK            Not successful
 *  \return     SOAD_E_INPROGRESS   Shutdown in progress
 *  \pre        Module initialized and DoIP Shutdown must be enabled
 *  \context    Task level
 *  \note       Vector specific API
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_Shutdown(void)
{
#if ( defined(DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) )
  return SoAd_Shutdown();
#else
  DoIP_State = DOIP_STATE_SHUTDOWN;
  
  return SoAd_Shutdown();
#endif /* defined(DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) */
}
#endif /* defined(DOIP_VSUPPORT_SHUTDOWN) && (STD_ON == DOIP_VSUPPORT_SHUTDOWN) */

#if ( defined(DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) )
/**********************************************************************************************************************
 *  DoIP_ShutdownFinished
 *********************************************************************************************************************/
/*! \brief      indicates shutdown of SoAd
 *  \context    task level
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_ShutdownFinished(void)
{
  DoIP_State = DOIP_STATE_SHUTDOWN;
  DoIP_VCallShutdownFinished();
}
#endif /* defined(DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) && (STD_ON == DOIP_VSHUTDOWN_FINISHED_CBK_SUPPORT) */

#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
/**********************************************************************************************************************
 *  DoIP_DoIPGwReceived
 *********************************************************************************************************************/
/*! \brief      Informs DoIP about a processed diagnostic message within DoIPGw module
 *  \param[in]  EntityAddr    DoIP entity address (target address in diagnostic message sent by tester)
 *  \return     none
 *  \pre        Module initialized and DoIP Gateway must be enabled
 *  \context    Task level
 *  \note       Vector specific API
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_DoIPGwReceived(uint16 EntityAddr)
{
  PduIdType channel = DoIP_VGetChannelByEcuAddr(EntityAddr);

  if ( DOIP_INV_PDU_ID != channel )
  {
    if ( TRUE == DoIP_VChannel2TargetIsDoIPGw[channel] )
    { /* DoIPGw is channel target */
      uint16 idx = DOIP_VCONNECTION_TCP_TOTAL;

      /* find affected TCP connection */
      while ( 0u < idx )
      {
        idx--;
        if ( channel == DoIP_VTcpCon2DoIPGwRxChannelActive[idx] )
        { /* TCP connection found */
          /* reset flag */
          DoIP_VTcpCon2DoIPGwRxChannelActive[idx] = DOIP_INV_PDU_ID;
        }
      }
    }
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  DoIP_VUdpSingleTransmit
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 3199 MSR_3199 */ /* MD_DoIP_3199 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VUdpSingleTransmit(PduIdType Connection, uint16 HdrType, uint16 Param)
{
  Std_ReturnType retVal = E_NOT_OK;

  switch(HdrType)
  {
    case DOIP_HDR_TYPE_GEN_NACK:
    { /* generic header negative acknowledge */
      DoIP_HdrNackType msg;
      PduInfoType msgStruct;

      /* build Nack message */
      msg.GenHdr.Ver    = DOIP_PROTOCOL_VERSION;
      msg.GenHdr.InvVer = (uint8)(~msg.GenHdr.Ver); /* PRQA S 0290 */ /* MD_DoIP_21.1_INV */

      msg.GenHdr.Type[0] = (uint8)(HdrType >> 8);
      msg.GenHdr.Type[1] = (uint8)(HdrType);

      msg.GenHdr.LenByte[0] = 0u;
      msg.GenHdr.LenByte[1] = 0u;
      msg.GenHdr.LenByte[2] = 0u;
      msg.GenHdr.LenByte[3] = 1u;

      msg.NackCode = (uint8)Param;

      /* build message struct for request */
      msgStruct.SduDataPtr = &msg.GenHdr.Ver;
      msgStruct.SduLength = DOIP_GEN_HDR_LEN_BYTE + 1u;

      /* send message */
      retVal = SoAd_IfTransmit(DoIP_VCon2SoAdTxPduId[Connection], &msgStruct);
      break;
    }
    case DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT:
    { /* vehicle announcement/identification request */
      PduInfoType msgStruct;
      uint16 logAddr;
      uint16 ackIdx = DOIP_GEN_HDR_LEN_BYTE;
      uint8 data[DOIP_GEN_HDR_LEN_BYTE + DOIP_ACK_VEHICLE_IDENT_LEN_BYTE];
      uint8 vinGidBuf[DOIP_VIN_LEN_BYTE] = {0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u};
#if ( defined(DOIP_VUSE_MAC_ADDR_FOR_IDENT) && (STD_ON == DOIP_VUSE_MAC_ADDR_FOR_IDENT) )
      uint8 physAddrBuf[DOIP_UHWID_LEN_BYTE];
#endif /* defined(DOIP_VUSE_MAC_ADDR_FOR_IDENT) && (STD_ON == DOIP_VUSE_MAC_ADDR_FOR_IDENT) */
      Std_ReturnType vinRetVal;

      /* fill VIN */
      vinRetVal = DoIP_VCallGetVinDirect(vinGidBuf);
      if ( E_OK == vinRetVal )
      { /* VIN successfully retrieved */
        /* PRQA S 0310,3305 2 */ /* MD_DoIP_11.4 */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&data[ackIdx],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))vinGidBuf, DOIP_VIN_LEN_BYTE);
      }
      else
      { /* VIN request failed */
        uint8 vinIdx = DOIP_VIN_LEN_BYTE;

        while ( 0u < vinIdx )
        {
          vinIdx--;
          data[ackIdx + vinIdx] = DOIP_VVIN_INV_PATTERN;
        }
      }
      ackIdx += DOIP_VIN_LEN_BYTE;

      /* fill Addr */
      logAddr = DOIP_VADDR;
      data[ackIdx] = (uint8)(logAddr >> 8u);
      ackIdx++;
      data[ackIdx] = (uint8)(logAddr);
      ackIdx++;

      /* fill EId */
#if ( defined(DOIP_VUSE_MAC_ADDR_FOR_IDENT) && (STD_ON == DOIP_VUSE_MAC_ADDR_FOR_IDENT) )
      if ( E_OK == SoAd_GetPhysAddr(DoIP_VCon2SoConId[Connection], &physAddrBuf[0]) )
      {
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&data[ackIdx],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, DOIP_CONST))&physAddrBuf[0],
          DOIP_UHWID_LEN_BYTE);
      }
      else
      {
        break;
      }
#else
      /* PRQA S 0310,3305 2 */ /* MD_DoIP_11.4 */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&data[ackIdx],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, DOIP_CONST))(&DoIP_VEid[0]),
        DOIP_UHWID_LEN_BYTE);
#endif /* defined(DOIP_VUSE_MAC_ADDR_FOR_IDENT) && (STD_ON == DOIP_VUSE_MAC_ADDR_FOR_IDENT) */
      ackIdx += DOIP_EID_LEN_BYTE;

      /* fill GId */
#if ( defined(DOIP_VVIN_GID_MASTER) && (STD_ON == DOIP_VVIN_GID_MASTER) )
# if ( defined(DOIP_VUSE_EID_AS_GID) && (STD_ON == DOIP_VUSE_EID_AS_GID) )
#  if ( defined(DOIP_VUSE_MAC_ADDR_FOR_IDENT) && (STD_ON == DOIP_VUSE_MAC_ADDR_FOR_IDENT) )
      if ( E_OK == SoAd_GetPhysAddr(DoIP_VCon2SoConId[Connection], &physAddrBuf[0]) )
      {
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&data[ackIdx],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, DOIP_CONST))&physAddrBuf[0],
          DOIP_UHWID_LEN_BYTE);
      }
      else
      {
        break;
      }
#  else
      /* PRQA S 0310 2 */ /* MD_DoIP_11.4 */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&data[ackIdx],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, DOIP_CONST))(&DoIP_VEid[0]),
        DOIP_UHWID_LEN_BYTE);
#  endif /* defined(DOIP_VUSE_MAC_ADDR_FOR_IDENT) && (STD_ON == DOIP_VUSE_MAC_ADDR_FOR_IDENT) */
# else
#  if ( defined(DOIP_VGID_AVAILABLE) && (STD_ON == DOIP_VGID_AVAILABLE) )
      /* use DoIP GID */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&data[ackIdx],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))DoIP_VGid, DOIP_GID_LEN_BYTE);
#  else
      /* use DoIP_VCallGetGidDirect or invalidity value */
      if ( E_OK == DoIP_VCallGetGidDirect(vinGidBuf) )
      { /* GID successfully retrieved */
        /* PRQA S 0310,3305 2 */ /* MD_DoIP_11.4 */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&data[ackIdx],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))vinGidBuf, DOIP_GID_LEN_BYTE);
      }
      else
      { /* GID request failed */
        uint8 gidIdx = DOIP_GID_LEN_BYTE;

        while ( 0u < gidIdx )
        {
          gidIdx--;
          data[ackIdx + gidIdx] = DOIP_VGID_INV_PATTERN;
        }
      }
#  endif /* defined(DOIP_VGID_ENABLED) && (STD_ON == DOIP_VGID_ENABLED) */
# endif /* defined(DOIP_VUSE_EID_AS_GID) && (STD_ON == DOIP_VUSE_EID_AS_GID) */
#else
# if ( defined(DOIP_VGID_AVAILABLE) && (STD_ON == DOIP_VGID_AVAILABLE) )
      /* use DoIP GID */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&data[ackIdx],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))DoIP_VGid, DOIP_GID_LEN_BYTE);
# else
      /* use DoIP_VCallGetGidDirect or invalidity value */
      if ( E_OK == DoIP_VCallGetGidDirect(vinGidBuf) )
      { /* GID successfully retrieved */
        /* PRQA S 0310,3305 2 */ /* MD_DoIP_11.4 */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&data[ackIdx],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))vinGidBuf, DOIP_GID_LEN_BYTE);
      }
      else
      { /* GID request failed */
        uint8 gidIdx = DOIP_GID_LEN_BYTE;

        while ( 0u < gidIdx )
        {
          gidIdx--;
          data[ackIdx + gidIdx] = DOIP_VGID_INV_PATTERN;
        }
      }
# endif /* defined(DOIP_VGID_ENABLED) && (STD_ON == DOIP_VGID_ENABLED) */
#endif /* defined(DOIP_VVIN_GID_MASTER) && (STD_ON == DOIP_VVIN_GID_MASTER) */
      ackIdx += DOIP_GID_LEN_BYTE;

      /* fill FurtherAction */
      data[ackIdx] = 0x00u;
#if ( defined(DOIP_VTESTER_WITH_CEN_SEC_AVAILABLE) && (STD_ON == DOIP_VTESTER_WITH_CEN_SEC_AVAILABLE) )
      {
        PduIdType tmpSoAdRxPduId = DOIP_VCONNECTION_TCP_TOTAL;

        while ( 0u < tmpSoAdRxPduId )
        {
          tmpSoAdRxPduId--;
          if ( (DOIP_ROUT_ACTIV_STATE_ACTIVATED != DoIP_VTcpCon2ActivMgt[tmpSoAdRxPduId].ActivState) ||
            (DoIP_VRoutingActivations[DoIP_VTcpCon2ActivMgt[
              tmpSoAdRxPduId].RoutActIdx].RoutingActivationNum != 0xE0u) )
          {
            if ( DoIP_VTester[DoIP_VTcpCon2ActivMgt[tmpSoAdRxPduId].TesterIdx].CentralSecurity == TRUE )
            { /* central security enabled */
              data[ackIdx] = 0x10u;
              break;
            }
          }
        }
      }
#endif /* defined(DOIP_VTESTER_WITH_CEN_SEC_AVAILABLE) && (STD_ON == DOIP_VTESTER_WITH_CEN_SEC_AVAILABLE) */

#if ( defined(DOIP_VIN_GID_SYNC) && (STD_ON == DOIP_VIN_GID_SYNC) )
      ackIdx++;

      /* fill VinGidSync */
      data[ackIdx] = 0x00u;
# if ( defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) )
      if ( (E_OK != vinRetVal) && (TRUE != DoIP_GidInSync) )
      { /* VIN/GID sync not succcessful */
        data[ackIdx] = 0x10u;
      }
# endif /* defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) */
#endif /* defined(DOIP_VIN_GID_SYNC) && (STD_ON == DOIP_VIN_GID_SYNC) */

      /* fill generic header */
      DoIP_VFillGenHdr(DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT, DOIP_ACK_VEHICLE_IDENT_LEN_BYTE, &data[0]);

      /* prepare msg struct for sending */
      msgStruct.SduDataPtr = &data[0];
      msgStruct.SduLength  = DOIP_GEN_HDR_LEN_BYTE + DOIP_ACK_VEHICLE_IDENT_LEN_BYTE;

      /* send message */
      retVal = SoAd_IfTransmit(DoIP_VCon2SoAdTxPduId[Connection], &msgStruct);
      break;
    }
    case DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_ACK:
    { /* diagnostic power mode information acknowledge */
      DoIP_PowerModeAckType msg;
      PduInfoType msgStruct;

      /* build power mode information message */
      msg.GenHdr.Ver        = DOIP_PROTOCOL_VERSION;
      msg.GenHdr.InvVer     = (uint8)(~msg.GenHdr.Ver); /* PRQA S 0290 */ /* MD_DoIP_21.1_INV */
      msg.GenHdr.Type[0]    = (uint8)(DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_ACK >> 8);
      msg.GenHdr.Type[1]    = (uint8)(DOIP_HDR_TYPE_DIAG_POWER_MODE_INFO_ACK & 0xFFu);
      msg.GenHdr.LenByte[0] = 0x00u;
      msg.GenHdr.LenByte[1] = 0x00u;
      msg.GenHdr.LenByte[2] = 0x00u;
      msg.GenHdr.LenByte[3] = 0x01u;
    
      msg.DiagPowerMode = (uint8)Param;

      /* build message struct for request */
      msgStruct.SduDataPtr = &msg.GenHdr.Ver;
      msgStruct.SduLength  = DOIP_GEN_HDR_LEN_BYTE + 1u;

      /* send message */
      retVal = SoAd_IfTransmit(DoIP_VCon2SoAdTxPduId[Connection], &msgStruct);
      break;
    }
#if ( defined(DOIP_ENTITY_STATE_SUPPORT) && (STD_ON == DOIP_ENTITY_STATE_SUPPORT) )
    case DOIP_HDR_TYPE_ENTITY_STATE_ACK:
    { /* DoIP entity status response */
      DoIP_EntityStateAckType msg;
      PduInfoType msgStruct;
      PduIdType tmpSoAdRxPduId = DOIP_VCONNECTION_TCP_TOTAL;
# if ( defined(DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) && (STD_ON == DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) )
      uint32 maxDataSize = DOIP_MAX_REQUEST_BYTES;
# endif /* defined(DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) && (STD_ON == DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) */

      /* build entity status response */
      msg.GenHdr.Ver        = DOIP_PROTOCOL_VERSION;
      msg.GenHdr.InvVer     = (uint8)(~msg.GenHdr.Ver); /* PRQA S 0290 */ /* MD_DoIP_21.1_INV */
      msg.GenHdr.Type[0]    = (uint8)(DOIP_HDR_TYPE_ENTITY_STATE_ACK >> 8);
      msg.GenHdr.Type[1]    = (uint8)(DOIP_HDR_TYPE_ENTITY_STATE_ACK & 0xFFu);
      msg.GenHdr.LenByte[0] = 0x00u;
      msg.GenHdr.LenByte[1] = 0x00u;
      msg.GenHdr.LenByte[2] = 0x00u;
      msg.GenHdr.LenByte[3] = DOIP_ACK_ENTITY_STATE_LEN_BYTE;
      msg.NodeType          = DOIP_NODE_TYPE;
      msg.MaxTcpSockCnt     = DOIP_VCONNECTION_TCP_TOTAL - DOIP_VLOCAL_ADDR_TOTAL; /* remove n+1 socket of each addr */
      msg.TcpSockCnt        = 0u;
      /* count open TCP_DATA socket (of all addr) */
      while ( 0u < tmpSoAdRxPduId )
      {
        tmpSoAdRxPduId--;

        if ( SOAD_SOCON_ONLINE == DoIP_VCon2SoConState[tmpSoAdRxPduId] )
        {
          msg.TcpSockCnt++;
        }
      }

# if ( defined(DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) && (STD_ON == DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) )
      msg.MaxDataSize[0]    = (uint8)(maxDataSize >> 24);
      msg.MaxDataSize[1]    = (uint8)(maxDataSize >> 16);
      msg.MaxDataSize[2]    = (uint8)(maxDataSize >> 8);
      msg.MaxDataSize[3]    = (uint8)(maxDataSize);
# endif /* defined(DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) && (STD_ON == DOIP_VENTITY_STATUS_MAX_BYTE_FIELD_USE) */

      /* build message struct for request */
      msgStruct.SduDataPtr = &msg.GenHdr.Ver;
      msgStruct.SduLength  = DOIP_GEN_HDR_LEN_BYTE + DOIP_ACK_ENTITY_STATE_LEN_BYTE;

      /* send message */
      retVal = SoAd_IfTransmit(DoIP_VCon2SoAdTxPduId[Connection], &msgStruct);
      break;
    }
#endif /* defined(DOIP_ENTITY_STATE_SUPPORT) && (STD_ON == DOIP_ENTITY_STATE_SUPPORT) */
#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
    case DOIP_HDR_TYPE_OEM_SPECIFIC:
    { /* OEM specific payload type */
      PduInfoType msgStruct;

      /* add the generic header in front of the user data */
      DoIP_VFillGenHdr(Param, (uint32)(DoIP_VOemPayloadTypeUdpBufLen - DOIP_GEN_HDR_LEN_BYTE),
        &DoIP_VOemPayloadTypeUdpBuf[0]);

      /* build message struct */
      msgStruct.SduDataPtr = &DoIP_VOemPayloadTypeUdpBuf[0];
      msgStruct.SduLength = DoIP_VOemPayloadTypeUdpBufLen;

      /* send message */
      retVal = SoAd_IfTransmit(DoIP_VCon2SoAdTxPduId[Connection], &msgStruct);

      break;
    }
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */
    default:
    { /* function does not support this header type */
      DOIP_CallDetReportError(DOIP_API_ID_VUDP_SINGLE_TRANSMIT, DOIP_E_INVALID_PARAMETER);
      break;
    }
  }

  return retVal;
}
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_3199 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_VUdpTransmit
 *********************************************************************************************************************/
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VUdpTransmit(PduIdType Connection, uint16 HdrType, uint16 Param,
                        boolean CloseSocket)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ( HdrType != DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT )
  { /* no Vehicle Announcement */
    /* try to send message immediately */
    retVal = DoIP_VUdpSingleTransmit(Connection, HdrType, Param);
  }

  if ( E_OK == retVal )
  { /* message has been sent immediately */
    boolean otherEntryFound = FALSE;

    /* check if response is pending for this socket connection */
    uint16 idx = DOIP_VUDP_TX_MGT_LIST_SIZE;
    while ( 0u < idx )
    {
      idx--;
      if ( Connection == DoIP_VUdpTxMgtList[idx].UdpCon )
      { /* response pending */
        otherEntryFound = TRUE;
        break;
      }
    }

#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
    /* check if OEM specific payload type buffer has to be released */
    if ( HdrType == DOIP_HDR_TYPE_OEM_SPECIFIC )
    {
      DoIP_VOemPayloadTypeUdpBufLen = 0u;
    }
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */

    if ( otherEntryFound == FALSE )
    { /* close socket connection directly (abort flag set to FALSE) */
      if ( CloseSocket == TRUE )
      {
        DoIP_VCloseSoCon(Connection);
      }
    }
    else
    { /* close socket connection after list does not contain elements for this connection anymore */
      DoIP_VCon2SoConClosing[Connection] |= CloseSocket;
    }
  }
  else
  { /* message has not been sent immediately */
    /* try to find an empty list element */
    uint16 idx = DOIP_VUDP_TX_MGT_LIST_SIZE;
    while ( 0u < idx )
    {
      idx--;
      if ( DOIP_INV_PDU_ID == DoIP_VUdpTxMgtList[idx].UdpCon )
      { /* element is not used */
        /* write element */
        DoIP_VUdpTxMgtList[idx].UdpCon = Connection;
        DoIP_VUdpTxMgtList[idx].HdrType = HdrType;
        DoIP_VUdpTxMgtList[idx].RetryAttempt = DOIP_UDP_MAX_RETRY_CNT;
        /* write message specific parameter */
        if ( HdrType == DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT )
        { /* Vehicle Announcement/Vehicle Identification Response */
          /* timer */
          DoIP_VUdpTxMgtList[idx].Param1 = DOIP_VANNOUNCE_WAIT;
        }
        /* number of announcements, nack code, power mode, OEM specific header type... */
        DoIP_VUdpTxMgtList[idx].Param2 = Param;

        DoIP_VCon2SoConClosing[Connection] |= CloseSocket;

        retVal = E_OK;
        break;
      }
    }
  }
  return retVal;
}
/* PRQA L:MSR_STCYC */

/**********************************************************************************************************************
 *  DoIP_VTcpTransmit
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 3689 DoIP_21_1_IDX */ /* MD_DoIP_21.1_IDX */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6060 MSR_STPAR */ /* MD_MSR_STPAR */
STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VTcpTransmit(PduIdType Connection, uint16 HdrType, uint16 Param1,
                        uint16 Param2, uint8 Param3, SduDataPtrType DataPtr, boolean CloseSocket)
{
  Std_ReturnType retVal = E_NOT_OK;

  DOIP_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* check socket connection state */
  if ( SOAD_SOCON_ONLINE == DoIP_VCon2SoConState[Connection] )
  { /* socket connection online */
    if ( TRUE != DoIP_VCon2SoConClosing[Connection] )
    { /* socket is not requested to be closed by a prevoius transmission request */
      /* add element to Tx Queue */
      retVal = DoIP_VTcpTxQueueAddElement(Connection, HdrType, Param1, Param2, Param3, DataPtr);

      if ( E_OK == retVal )
      {
        if ( TRUE == CloseSocket )
        { /* socket shall be closed after sending this message */
          DoIP_VCon2SoConClosing[Connection] = TRUE;
        }

        DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        /* start transmission of Tx Queue */
        DoIP_VTcpTxQueueSend(Connection);
      }
      else
      {
        DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        /* no memory in TxQueue available */
        DOIP_CallDetReportError(DOIP_API_ID_VTCP_TRANSMIT, DOIP_E_NOBUFS);
      }
    }
    else
    {
      DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
  else
  {
    DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  return retVal;
}
/* PRQA L:MSR_14_7 */
/* PRQA L:DoIP_21_1_IDX */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STPAR */

/**********************************************************************************************************************
 *  DoIP_VTcpPrepareTransmit
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6060 MSR_STPAR */ /* MD_MSR_STPAR */
STATIC FUNC(void, DOIP_CODE) DoIP_VTcpPrepareTransmit(PduIdType Connection, uint16 HdrType, uint16 Param1,
                        uint16 Param2, uint8 Param3, boolean CloseSocket)
{
  if ( DOIP_HDR_TYPE_INVALID == DoIP_VTcpCon2TpPreTransMgt[Connection].HdrType )
  { /* no pending prepare transmit request */
    /* store transmission parameter */
    DoIP_VTcpCon2TpPreTransMgt[Connection].HdrType     = HdrType;
    DoIP_VTcpCon2TpPreTransMgt[Connection].Param1      = Param1;
    DoIP_VTcpCon2TpPreTransMgt[Connection].Param2      = Param2;
    DoIP_VTcpCon2TpPreTransMgt[Connection].Param3      = Param3;
    DoIP_VTcpCon2TpPreTransMgt[Connection].CloseSocket = CloseSocket;
  }
}
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STPAR */

/**********************************************************************************************************************
 *  DoIP_VTcpFinishTransmit
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VTcpFinishTransmit(PduIdType Connection)
{
  if ( DOIP_HDR_TYPE_INVALID != DoIP_VTcpCon2TpPreTransMgt[Connection].HdrType )
  { /* PrepareTransmit function called before */
    /* call transmit function to send message */
    (void)DoIP_VTcpTransmit(Connection,
      DoIP_VTcpCon2TpPreTransMgt[Connection].HdrType,
      DoIP_VTcpCon2TpPreTransMgt[Connection].Param1,
      DoIP_VTcpCon2TpPreTransMgt[Connection].Param2,
      DoIP_VTcpCon2TpPreTransMgt[Connection].Param3,
      NULL_PTR,
      DoIP_VTcpCon2TpPreTransMgt[Connection].CloseSocket);
    DoIP_VTcpCon2TpPreTransMgt[Connection].HdrType = DOIP_HDR_TYPE_INVALID;
  }
}

/**********************************************************************************************************************
 *  DoIP_VTcpTxQueueAddElement
 *********************************************************************************************************************/
/* PRQA S 3689 DoIP_21_1_IDX */ /* MD_DoIP_21.1_IDX */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6060 MSR_STPAR */ /* MD_MSR_STPAR */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VTcpTxQueueAddElement(PduIdType Connection, uint16 HdrType, uint16 Param1,
                        uint16 Param2, uint8 Param3, SduDataPtrType DataPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* check if Tx Queue can handle this request */
  if ( DoIP_VTcpCon2TxMgtQueLvl[Connection] < DOIP_VTCP_TX_MGT_QUEUE_SIZE )
  {
    uint8 idx;

    /* find next free entry in Tx Queue */
    if ( (DoIP_VTcpCon2TxMgtQueIdx[Connection] + DoIP_VTcpCon2TxMgtQueLvl[Connection]) >=
      DOIP_VTCP_TX_MGT_QUEUE_SIZE )
    { /* wrap around necessary */
      idx = (uint8)(DoIP_VTcpCon2TxMgtQueLvl[Connection] -
        (DOIP_VTCP_TX_MGT_QUEUE_SIZE - DoIP_VTcpCon2TxMgtQueIdx[Connection]));
    }
    else
    { /* no wrap around necessary */
      idx = (uint8)(DoIP_VTcpCon2TxMgtQueIdx[Connection] + DoIP_VTcpCon2TxMgtQueLvl[Connection]);
    }

    switch(HdrType)
    {
      case DOIP_HDR_TYPE_GEN_NACK:
      {
        uint8 nackCode = (uint8)Param1;

        /* fill DoIP header in Tx buffer */
        /* generic header */
        DoIP_VFillGenHdr(DOIP_HDR_TYPE_GEN_NACK, DOIP_GEN_HDR_NACK_CODE_LEN_BYTE,
          &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);

        /* NACK Code */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[DOIP_GEN_HDR_LEN_BYTE] = nackCode;

        /* set txMgt struct */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBufLen = DOIP_GEN_HDR_LEN_BYTE + DOIP_GEN_HDR_NACK_CODE_LEN_BYTE;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength = DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBufLen;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduDataPtr = &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0];

        break;
      }
      case DOIP_HDR_TYPE_ROUT_ACTIV_ACK:
      {
        PduLengthType bufIdx     = DOIP_GEN_HDR_LEN_BYTE;
        uint16        testAddr   = Param1;
        uint16        entityAddr = DOIP_VADDR;
        uint8         ackCode    = (uint8)Param2;
        uint8         testerIdx  = Param3;

        /* fill DoIP header in Tx buffer */
        /* routing activation response */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = (uint8)(testAddr >> 8u);
        bufIdx++;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = (uint8)(testAddr);
        bufIdx++;

        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = (uint8)(entityAddr >> 8u);
        bufIdx++;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = (uint8)(entityAddr);
        bufIdx++;

        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = ackCode;
        bufIdx++;

        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = 0u;
        bufIdx++;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = 0u;
        bufIdx++;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = 0u;
        bufIdx++;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = 0u;
        bufIdx++;

        /* identify tester */
        if ( DOIP_INV_ADDR_IDX == testerIdx )
        { /* unknown tester */
          /* generic header */
          DoIP_VFillGenHdr(DOIP_HDR_TYPE_ROUT_ACTIV_ACK, DOIP_ROUT_ACTIV_ACK_MIN_LEN_BYTE,
            &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);
        }
        else
        {
          /* check if OEM specific data shall be added */
          if ( DOIP_INV_ROUT_ACT_IDX != DoIP_VTcpCon2ActivMgt[Connection].RoutActIdx )
          { /* routing activation determined */
            if ( ((0u == DoIP_VRoutingActivations[DoIP_VTcpCon2ActivMgt[Connection].RoutActIdx].AuthResLength) &&
                (0u == DoIP_VRoutingActivations[DoIP_VTcpCon2ActivMgt[Connection].RoutActIdx].ConfResLength)) ||
              (DOIP_ROUT_ACTIV_STATE_ACTIVATED != DoIP_VTcpCon2ActivMgt[Connection].ActivState) )
            { /* no OEM specific data */
              DoIP_VFillGenHdr(DOIP_HDR_TYPE_ROUT_ACTIV_ACK, DOIP_ROUT_ACTIV_ACK_MIN_LEN_BYTE,
                &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);
            }
            else
            { /* add OEM specific data */
              P2VAR(uint8, AUTOMATIC, AUTOMATIC) oemSpecPtr = DoIP_VRoutActivHandler.OemSpecRes;

              /* generic header */
              DoIP_VFillGenHdr(DOIP_HDR_TYPE_ROUT_ACTIV_ACK, DOIP_ROUT_ACTIV_ACK_MAX_LEN_BYTE,
                &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);

              DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = oemSpecPtr[0];
              bufIdx++;
              DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = oemSpecPtr[1];
              bufIdx++;
              DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = oemSpecPtr[2];
              bufIdx++;
              DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = oemSpecPtr[3];
              bufIdx++;
            }
          }
          else
          { /* not routing activation determined */
            /* no OEM specific data */
            DoIP_VFillGenHdr(DOIP_HDR_TYPE_ROUT_ACTIV_ACK, DOIP_ROUT_ACTIV_ACK_MIN_LEN_BYTE,
              &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);
          }
        }

        /* set txMgt struct */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBufLen    = bufIdx;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength  = bufIdx;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduDataPtr = &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0];

        break;
      }
      case DOIP_HDR_TYPE_ALIVE_CHECK_REQ:
      {
        /* fill DoIP header in Tx buffer */
        /* generic header */
        DoIP_VFillGenHdr(DOIP_HDR_TYPE_ALIVE_CHECK_REQ, 0u, &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);

        /* set txMgt struct */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBufLen    = DOIP_GEN_HDR_LEN_BYTE;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength  = DOIP_GEN_HDR_LEN_BYTE;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduDataPtr = &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0];

        break;
      }
      case DOIP_HDR_TYPE_DIAG_REQ:
      {
        PduIdType     channel   = (PduIdType)Param1;
        PduLengthType length    = (PduLengthType)Param2;
        PduLengthType bufIdx    = DOIP_GEN_HDR_LEN_BYTE;

        if ( DOIP_API_TYPE_TP != DoIP_VChannel2ApiType[channel] )
        {
          /* PRQA S 0310,3305 3 */ /* MD_DoIP_11.4 */
          IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))DoIP_VChannel2IfTxBuf[channel].BufPtr,
            (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))DataPtr,
            length);
        }

        /* fill DoIP header in Tx buffer */
        /* generic header */
        DoIP_VFillGenHdr(DOIP_HDR_TYPE_DIAG_REQ, (DOIP_DIAG_HDR_LEN_BYTE + length),
          &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);

        /* diagnostic message */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+0] = (uint8)(DoIP_VChannel2EcuAddr[channel] >> 8);
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+1] = (uint8)DoIP_VChannel2EcuAddr[channel];
        bufIdx += DOIP_ADDR_LEN_BYTE;
#if ( defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) )
        if ( DoIP_VTester[DoIP_VTcpCon2ActivMgt[Connection].TesterIdx].TesterAddr == DOIP_ADDR_ANY )
        { /* default tester */
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+0] =
            (uint8)(DoIP_VTcpCon2ActivMgt[Connection].TesterAddr >> 8u);
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+1] =
            (uint8)DoIP_VTcpCon2ActivMgt[Connection].TesterAddr;
        }
        else
#endif /* defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) */
        { /* no default tester */
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+0] =
            (uint8)(DoIP_VTester[DoIP_VTcpCon2ActivMgt[Connection].TesterIdx].TesterAddr >> 8u);
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+1] =
            (uint8)DoIP_VTester[DoIP_VTcpCon2ActivMgt[Connection].TesterIdx].TesterAddr;
        }
        bufIdx += DOIP_ADDR_LEN_BYTE;

        /* set txMgt struct */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Channel        = channel;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBufLen    = bufIdx;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength  = bufIdx + length;
        if ( DOIP_API_TYPE_TP == DoIP_VChannel2ApiType[channel] )
        { /* standard diagnostic message */
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduDataPtr = &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0];
        }
        else
        { /* UUDT */
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduDataPtr = DataPtr;
        }

        break;
      }
      case DOIP_HDR_TYPE_DIAG_ACK:
      {
        PduLengthType bufIdx  = DOIP_GEN_HDR_LEN_BYTE;
        uint16        ecuAddr = Param1;
        uint8         testerIdx = DoIP_VTcpCon2ActivMgt[Connection].TesterIdx;

        /* fill DoIP header in Tx buffer */
        /* generic header */
#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
        DoIP_VFillGenHdr(DOIP_HDR_TYPE_DIAG_ACK, DOIP_DIAG_MSG_ACK_LEN_BYTE + DoIP_VTester2DiagNAckOffset[testerIdx],
          &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);
#else
        DoIP_VFillGenHdr(DOIP_HDR_TYPE_DIAG_ACK, DOIP_DIAG_MSG_ACK_LEN_BYTE,
          &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) */

        /* diagnostic message positive ack */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+0] = (uint8)(ecuAddr >> 8);
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+1] = (uint8)ecuAddr;
        bufIdx += DOIP_ADDR_LEN_BYTE;
#if ( defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) )
        if ( DoIP_VTester[testerIdx].TesterAddr == DOIP_ADDR_ANY )
        { /* default tester */
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+0] =
            (uint8)(DoIP_VTcpCon2ActivMgt[Connection].TesterAddr >> 8u);
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+1] =
            (uint8)DoIP_VTcpCon2ActivMgt[Connection].TesterAddr;
        }
        else
#endif /* defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) */
        { /* no default tester */
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+0] =
            (uint8)(DoIP_VTester[testerIdx].TesterAddr >> 8u);
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+1] =
            (uint8)DoIP_VTester[testerIdx].TesterAddr;
        }
        bufIdx += DOIP_ADDR_LEN_BYTE;
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = DOIP_DIAG_MSG_RES_CODE_ACK;
        bufIdx++;

        /* set txMgt struct */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBufLen    = bufIdx;
#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength  = (PduLengthType)(bufIdx + 
          DoIP_VTester2DiagNAckOffset[testerIdx]);
#else
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength  = bufIdx;
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ)  */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduDataPtr = &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0];

        break;
      }
      case DOIP_HDR_TYPE_DIAG_NACK:
      {
        uint16        ecuAddr   = Param1;
        uint16        testAddr  = Param2;
        PduLengthType bufIdx    = DOIP_GEN_HDR_LEN_BYTE;
        uint8         testerIdx = DoIP_VTcpCon2ActivMgt[Connection].TesterIdx;
        uint8         ackCode   = Param3;

        /* fill DoIP header in Tx buffer */
        /* generic header */
#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
        if ( DOIP_INV_TESTER_IDX != testerIdx )
        { /* tester known */
          /* send diagnostic message negative ack with configured amount of user data */
          DoIP_VFillGenHdr(DOIP_HDR_TYPE_DIAG_NACK, DOIP_DIAG_MSG_ACK_LEN_BYTE +
            DoIP_VTester2DiagNAckOffset[testerIdx], &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);
        }
        else
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) */
        { /* unknown tester */
          /* send diagnostic message negative ack without user data */
          DoIP_VFillGenHdr(DOIP_HDR_TYPE_DIAG_NACK, DOIP_DIAG_MSG_ACK_LEN_BYTE,
            &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);
        }

        /* diagnostic message negative ack */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+0] = (uint8)(ecuAddr >> 8u);
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+1] = (uint8)ecuAddr;
        bufIdx += DOIP_ADDR_LEN_BYTE;

        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+0] = (uint8)(testAddr >> 8u);
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx+1] = (uint8)testAddr;
        bufIdx += DOIP_ADDR_LEN_BYTE;

        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[bufIdx] = ackCode;
        bufIdx += 1u;

        /* set txMgt struct */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBufLen    = bufIdx;
#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
        if ( DOIP_INV_TESTER_IDX != testerIdx )
        { /* send diagnostic message negative ack with configured ammount of user data */
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength  = (PduLengthType)(bufIdx + 
            DoIP_VTester2DiagNAckOffset[testerIdx]);
        }
        else
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) */
        { /* send diagnostic message negative ack without user data */
          DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength  = bufIdx;
        }
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduDataPtr = &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0];

        break;
      }
#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
      case DOIP_HDR_TYPE_OEM_SPECIFIC:
      {
        uint16 hdrType = Param1;

        /* fill DoIP header in Tx buffer */
        /* generic header */
# if ( DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0 )
        DoIP_VFillGenHdr(hdrType, DoIP_VOemPayloadTypeTcpBufLen, &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);
# else
        DoIP_VFillGenHdr(hdrType, 0u, &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0]);
# endif /* DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0 */

        /* set txMgt struct */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBufLen    = DOIP_GEN_HDR_LEN_BYTE;
# if ( DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0 )
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength  = (PduLengthType)(DOIP_GEN_HDR_LEN_BYTE +
            DoIP_VOemPayloadTypeTcpBufLen);
# else
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduLength  = DOIP_GEN_HDR_LEN_BYTE;
# endif /* DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0 */
        DoIP_VTcpCon2TcpTxMgt[Connection][idx].Msg.SduDataPtr = &DoIP_VTcpCon2TcpTxMgt[Connection][idx].TxHdrBuf[0];
        break;
      }
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */
      default:
      {
        break;
      }
    }

    /* update Tx Queue */
    DoIP_VTcpCon2TxMgtQueLvl[Connection]++;

    retVal = E_OK;
  }

  return retVal;
}
/* PRQA L:DoIP_21_1_IDX */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STPAR */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_VTcpTxQueueSend
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, DOIP_CODE) DoIP_VTcpTxQueueSend(PduIdType Connection)
{
  DOIP_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if ( FALSE == DoIP_VTcpCon2TxTpSessionActive[Connection] )
  { /* no transmission is requested for this socket connection */
    /* lock since this function can be called reentrant */
    DoIP_VTcpCon2TxTpSessionActive[Connection] = TRUE;

    if ( 0u < DoIP_VTcpCon2TxMgtQueLvl[Connection] )
    { /* pending msg */
      PduInfoType txMgtMsg;
      uint16 txMgtQueIdx;

      txMgtQueIdx = DoIP_VTcpCon2TxMgtQueIdx[Connection];
      txMgtMsg.SduDataPtr = DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].Msg.SduDataPtr;
      txMgtMsg.SduLength = DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].Msg.SduLength;

      DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* request transmission at SoAd */
      if ( E_OK == SoAd_TpTransmit(DoIP_VCon2SoAdTxPduId[Connection], &txMgtMsg) )
      { /* transmission request succeeded */
        /* nothing to do */
      }
      else
      { /* transmission request failed */
        DoIP_VTcpCon2TxTpSessionActive[Connection] = FALSE;
      }
    }
    else
    { /* queue is empty */
      DoIP_VTcpCon2TxTpSessionActive[Connection] = FALSE;

      DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
  else
  { /* transmission is already active */
    DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}
/* PRQA L:MSR_11715 */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_VTcpTxQueueCopyElement
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_VTcpTxQueueCopyElement(PduIdType Connection,
                        P2VAR(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
                        P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr)
{
  uint16  txMgtQueIdx;
  uint16  hdrType;
  boolean hdrCopied = FALSE;

  /*lint -e662 -e661 */

  DOIP_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* check whether TP session is online */
  if ( TRUE != DoIP_VTcpCon2TxTpSessionActive[Connection] )
  { /* TP session is not online */
    DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    return BUFREQ_E_NOT_OK;
  }

#if ( defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) )
  /* Check TP cancellation */
  if ( TRUE == DoIP_VTcpCon2TxTpCancelRequested[Connection] )
  { /* TP cancellation is ongoing */
    DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    return BUFREQ_E_NOT_OK;
  }
#endif /* defined(DOIP_VPROVIDE_CANCEL_TRANSMIT_API) && (STD_ON == DOIP_VPROVIDE_CANCEL_TRANSMIT_API) */

  if ( DOIP_ROUT_ACTIV_STATE_ACTIVATED == DoIP_VTcpCon2ActivMgt[Connection].ActivState )
  { /* routing activation active */
    /* reset inactivity timer */
    DoIP_VTcpCon2InactivCnt[Connection] = 0;
  }

  txMgtQueIdx = DoIP_VTcpCon2TxMgtQueIdx[Connection];

  /* extract message type */
  DOIP_GET_UINT16(&DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBuf[DOIP_GEN_HDR_TYPE_IDX], 0, hdrType);

  /* check whether this is a first call of CopyTxData */
  if ( 0u != PduInfoPtr->SduLength )
  { /* subsequent call - copy request */
    /* check length */
    if ( DoIP_VTcpCon2LastTxBufSize[Connection] < PduInfoPtr->SduLength )
    { /* unexpected length */
      DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      return BUFREQ_E_NOT_OK;
    }
  }

  if ( DoIP_VTcpCon2TxBytesCopied[Connection] < DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBufLen )
  { /* header is not yet copied */
    if ( 0u != PduInfoPtr->SduLength )
    { /* subsequent call - copy request */
      /* check requested length */
      if ( PduInfoPtr->SduLength <= ((PduLengthType)(DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBufLen -
          DoIP_VTcpCon2TxBytesCopied[Connection])) )
      { /* length is in valid range - copy requested number of bytes to target buffer */
        /* PRQA S 0310,3305 2 */ /* MD_DoIP_11.4 */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))PduInfoPtr->SduDataPtr,
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VTcpCon2TcpTxMgt[Connection][
            txMgtQueIdx].TxHdrBuf[DoIP_VTcpCon2TxBytesCopied[Connection]],
          PduInfoPtr->SduLength);
        DoIP_VTcpCon2TxBytesCopied[Connection] += PduInfoPtr->SduLength;
        if ( DoIP_VTcpCon2TxBytesCopied[Connection] == DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBufLen )
        { /* header copied completely */
          if (DOIP_HDR_TYPE_ROUT_ACTIV_ACK == hdrType)
          { /* Routing Activation Response */
            if ( DOIP_INV_PDU_ID != DoIP_VRoutActivHandler.TcpCon )
            {
              if ( DOIP_ROUT_ACTIV_STATE_CONF_PENDING !=
                DoIP_VTcpCon2ActivMgt[DoIP_VRoutActivHandler.TcpCon].ActivState )
              { /* In case of confirmation a Routing Activation Response might be sent even if Routing Activation
                 * is not finished. Release Routing Activation Handler in all other cases. */
                DoIP_VRoutActivHandler.TcpCon = DOIP_INV_PDU_ID;
              }
            }
          }
          hdrCopied = TRUE;
        }
      }
      else
      { /* invalid length */
        DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        return BUFREQ_E_NOT_OK;
      }
    }
    /* set available data length */
    *AvailableDataPtr = (PduLengthType)(DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBufLen -
      DoIP_VTcpCon2TxBytesCopied[Connection]);
    DoIP_VTcpCon2LastTxBufSize[Connection] = *AvailableDataPtr;
  }

  if ( (DoIP_VTcpCon2TxBytesCopied[Connection] >= DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBufLen) &&
    (DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBufLen <
      DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].Msg.SduLength) )
  { /* header copied completely and more data are available */
    if ( hdrType == DOIP_HDR_TYPE_DIAG_REQ )
    { /* diagnostic message */
      PduIdType channel = DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].Channel;
      P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) locPduInfoPtr = PduInfoPtr;
      PduInfoType locPduInfoStruct;
      BufReq_ReturnType bufReqRetVal;

      if ( DOIP_API_TYPE_TP == DoIP_VChannel2ApiType[channel] )
      { /* TP-API */
        /* query available upper layer buffer if header was copied successful */
        if ( TRUE == hdrCopied )
        {
          /* query Tx buffer size of upper layer */
          locPduInfoStruct.SduLength = 0u;
          locPduInfoPtr = &locPduInfoStruct;
        }

        DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        /* call upper layer CopyTxData function to query available buffer or copying */
        bufReqRetVal = PduR_DoIPTpCopyTxData(DoIP_VChannel2PduRTxConfPduId[channel], locPduInfoPtr, NULL_PTR,
          AvailableDataPtr);

        DOIP_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        /* check if Tx Queue has been modifed (e.g. connection closed) */
        if ( 0u == DoIP_VTcpCon2TxMgtQueLvl[Connection] )
        {
          DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

          return BUFREQ_E_NOT_OK;
        }

        if ( BUFREQ_OK == bufReqRetVal )
        { /* buffer request was sucessful */
          DoIP_VTcpCon2LastTxBufSize[Connection] = *AvailableDataPtr;
          if ( (0u == locPduInfoPtr->SduLength) && (0u != PduInfoPtr->SduLength) )
          { /* available buffer of upper layer was requested by DoIP - do not forward return value of upper layer */
            DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

            return BUFREQ_OK;
          }
          /* copying successful - update TxMgt struct */ 
          DoIP_VTcpCon2TxBytesCopied[Connection] += locPduInfoPtr->SduLength;
        }
        else
        { /* buffer request failed */
          /* close connection since generic header has already been sent */
          DoIP_VCon2SoConClosing[Connection] = TRUE;

          DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

          DoIP_VCloseSoCon(Connection);

          return BUFREQ_E_NOT_OK;
        }
      }
      else
      { /* IF-API (UUDT) */
        if ( (0u < locPduInfoPtr->SduLength) && (FALSE == hdrCopied) )
        {
          PduLengthType bufIdx = (PduLengthType)(DoIP_VTcpCon2TxBytesCopied[Connection] -
            DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBufLen);

          /* copy UUDT data from internal buffer to target buffer */
          /* PRQA S 0310,3305 3 */ /* MD_DoIP_11.4 */
          IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))PduInfoPtr->SduDataPtr,
            (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VChannel2IfTxBuf[channel].BufPtr[bufIdx],
            (uint32)PduInfoPtr->SduLength);

          /* update TxMgt struct */ 
          DoIP_VTcpCon2TxBytesCopied[Connection] += PduInfoPtr->SduLength;
        }
        /* set available data length */
        *AvailableDataPtr = (PduLengthType)(DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].Msg.SduLength -
          DoIP_VTcpCon2TxBytesCopied[Connection]);
        DoIP_VTcpCon2LastTxBufSize[Connection] = *AvailableDataPtr;

        bufReqRetVal = BUFREQ_OK;
      }

      DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      return bufReqRetVal;
    }
    else if ( (hdrType == DOIP_HDR_TYPE_DIAG_ACK) || (hdrType == DOIP_HDR_TYPE_DIAG_NACK) )
    { /* diagnostic message positive/negative acknowledge */
#if ( defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) )
      if ( (0u != PduInfoPtr->SduLength) && (FALSE == hdrCopied) )
      { /* copy data to target buffer */
        /* PRQA S 0310,3305 2 */ /* MD_DoIP_11.4 */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))PduInfoPtr->SduDataPtr,
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VTester[
            DoIP_VTcpCon2ActivMgt[Connection].TesterIdx].DiagAckNackBufPtr[
              DoIP_VTcpCon2TxBytesCopied[Connection] - DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBufLen],
          PduInfoPtr->SduLength);
        DoIP_VTcpCon2TxBytesCopied[Connection] += PduInfoPtr->SduLength;

        if ( DoIP_VTcpCon2TxBytesCopied[Connection] == DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].Msg.SduLength )
        { /* all data are copied to lower layer buffer */
          /* reset DiagNAck buffer offset to indicate that new data can be received (do not wait for TxConfirmation) */
          DoIP_VTester2DiagNAckOffset[DoIP_VTcpCon2ActivMgt[Connection].TesterIdx] = 0u;
        }
      }
      /* set available data length */
      *AvailableDataPtr = (PduLengthType)(DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].Msg.SduLength -
        DoIP_VTcpCon2TxBytesCopied[Connection]);
      DoIP_VTcpCon2LastTxBufSize[Connection] = *AvailableDataPtr;
#else
      /* nothing to do */
#endif /* defined(DOIP_NACK_APPEND_REQ) && (STD_ON == DOIP_NACK_APPEND_REQ) */
    }
    else
    { /* OEM specific payload type */
#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
# if ( DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u )
      if ( (0u != PduInfoPtr->SduLength) && (FALSE == hdrCopied) )
      { /* copy data to target buffer */
        /* PRQA S 0310,3305 2 */ /* MD_DoIP_11.4 */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))PduInfoPtr->SduDataPtr,
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, AUTOMATIC))&DoIP_VOemPayloadTypeTcpBuf[
            DoIP_VTcpCon2TxBytesCopied[Connection] - DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].TxHdrBufLen],
          PduInfoPtr->SduLength);
        DoIP_VTcpCon2TxBytesCopied[Connection] += PduInfoPtr->SduLength;

        if ( DoIP_VTcpCon2TxBytesCopied[Connection] == DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].Msg.SduLength )
        { /* all data are copied to lower layer buffer */
          DoIP_VOemPayloadTypeTcpBufLen  = 0u;
          DoIP_VOemPayloadTypeTcpBufIsTx = FALSE;
          DoIP_VOemPayloadTypeTcpBuf2Con = DOIP_INV_PDU_ID;
        }
      }
      /* set available data length */
      *AvailableDataPtr = (PduLengthType)(DoIP_VTcpCon2TcpTxMgt[Connection][txMgtQueIdx].Msg.SduLength -
        DoIP_VTcpCon2TxBytesCopied[Connection]);
      DoIP_VTcpCon2LastTxBufSize[Connection] = *AvailableDataPtr;
# else
      /* nothing to do */
# endif /* DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u */
#else
      /* nothing to do */
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */
    }

    /*lint +e662 +e661 */
  }

  DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return BUFREQ_OK;
}
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_VTcpTxQueueRemoveElement
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VTcpTxQueueRemoveElement(PduIdType Connection, Std_ReturnType Result)
{
  DOIP_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if ( 0u < DoIP_VTcpCon2TxMgtQueLvl[Connection] )
  {
    PduIdType channel = DoIP_VTcpCon2TcpTxMgt[Connection][DoIP_VTcpCon2TxMgtQueIdx[Connection]].Channel;
    uint8 queIdx = DoIP_VTcpCon2TxMgtQueIdx[Connection];

    /* reset TxMgt structs */
    DoIP_VTcpCon2TcpTxMgt[Connection][queIdx].TxHdrBufLen = 0u;

    /* Update Tx Queue */
    DoIP_VTcpCon2TxMgtQueLvl[Connection]--;
    DoIP_VTcpCon2TxMgtQueIdx[Connection]++;
    if ( DoIP_VTcpCon2TxMgtQueIdx[Connection] == DOIP_VTCP_TX_MGT_QUEUE_SIZE )
    { /* wrap around */
      DoIP_VTcpCon2TxMgtQueIdx[Connection] = 0u;
    }

#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
# if ( DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u )
    /* release OEM specific payload type buffer */
    if ( DoIP_VOemPayloadTypeTcpBuf2Con == Connection )
    {
      DoIP_VOemPayloadTypeTcpBufLen  = 0u;
      DoIP_VOemPayloadTypeTcpBufIsTx = FALSE;
      DoIP_VOemPayloadTypeTcpBuf2Con = DOIP_INV_PDU_ID;
    }
# endif /* DOIP_VOEM_PAYLOAD_TYPE_TCP_BUF_SIZE > 0u */
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */

    /* finish TP session */
    DoIP_VTcpCon2TxTpSessionActive[Connection] = FALSE;

    DoIP_VTcpCon2TxBytesCopied[Connection] = 0u;

    if ( DOIP_INV_PDU_ID != channel )
    {
      DoIP_VChannel2TxMsgLen[channel] = 0u;
      /* PRQA S 0277 1 */ /* MD_DoIP_3.1 */
      DoIP_VTcpCon2TcpTxMgt[Connection][queIdx].Channel = DOIP_INV_PDU_ID;

      DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* forward TxConfirmation to upper layer */
#if ( defined(DOIP_VPDUR_IF_TXCONF_ENABLED) && (STD_ON == DOIP_VPDUR_IF_TXCONF_ENABLED) )
      if ( DOIP_API_TYPE_IF == DoIP_VChannel2ApiType[channel] )
      { /* IF-API */
        if ( DOIP_INV_PDU_ID != DoIP_VChannel2PduRTxConfPduId[channel] )
        { /* TxConfirmation enabled */
          PduR_DoIPIfTxConfirmation(DoIP_VChannel2PduRTxConfPduId[channel]);
        }
      }
      else
#endif /* defined(DOIP_VPDUR_IF_TXCONF_ENABLED) && (STD_ON == DOIP_VPDUR_IF_TXCONF_ENABLED) */
      { /* TP-API */
        PduR_DoIPTpTxConfirmation(DoIP_VChannel2PduRTxConfPduId[channel], Result);
      }
    }
    else
    {
      DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
  else
  {
    DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}

/**********************************************************************************************************************
 *  DoIP_VFillGenHdr
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VFillGenHdr(uint16 HdrType,
                                  uint32 HdrLen,
                                  P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) TgtBufferPtr)
{
  /* header version */
  TgtBufferPtr[0] = DOIP_PROTOCOL_VERSION;
  /* inverse header version */
  TgtBufferPtr[1] = (uint8)(~TgtBufferPtr[0]);
  /* header type */
  TgtBufferPtr[2] = (uint8)(HdrType >> 8);
  TgtBufferPtr[3] = (uint8)(HdrType);
  /* header length */
  TgtBufferPtr[4] = (uint8)(HdrLen >> 24);
  TgtBufferPtr[5] = (uint8)(HdrLen >> 16);
  TgtBufferPtr[6] = (uint8)(HdrLen >> 8);
  TgtBufferPtr[7] = (uint8)(HdrLen);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  DoIP_VGetConnectionOfTesterAddr
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VGetConnectionOfTesterAddr(uint16 TesterAddr,
                               P2VAR(PduIdType, AUTOMATIC, DOIP_APPL_VAR) Connection)
{
  PduIdType pduId = DOIP_VCONNECTION_TCP_TOTAL;

  while ( 0u < pduId )
  {
    pduId--;

    if ( DoIP_VTcpCon2ActivMgt[pduId].TesterAddr == TesterAddr )
    {
      *Connection = pduId;
      return;
    }
  }
  *Connection = DOIP_INV_PDU_ID;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  DoIP_VGetTesterIdxByTesterAddr
 *********************************************************************************************************************/
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, DOIP_CODE) DoIP_VGetTesterIdxByTesterAddr(uint16 TesterAddr,
                               P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) TesterIdx)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 testerIdx = DOIP_VTESTER_TOTAL;

  *TesterIdx = DOIP_INV_TESTER_IDX;
  while ( 0u < testerIdx )
  {
    testerIdx--;
    if ( DoIP_VTester[testerIdx].TesterAddr == TesterAddr )
    {
      *TesterIdx = testerIdx;
      retVal = E_OK;
      break;
    }
#if ( defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) )
    if ( DoIP_VTester[testerIdx].TesterAddr == DOIP_ADDR_ANY )
    { /* default tester */
      /* check if tester is used on another connection with same address */
      PduIdType connection = DOIP_VCONNECTION_TCP_TOTAL;

      *TesterIdx = testerIdx;
      retVal = E_OK;

      while ( 0u < connection )
      {
        connection--;

        if ( testerIdx == DoIP_VTcpCon2ActivMgt[connection].TesterIdx )
        { /* default tester is already in use */
          if ( TesterAddr != DoIP_VTcpCon2ActivMgt[connection].TesterAddr )
          { /* default tester is already in use with different logical address */
            /* default tester is not available */
            *TesterIdx = DOIP_INV_TESTER_IDX;
            retVal = E_NOT_OK;
            break;
          }
        }
      }
    }
#endif /* defined(DOIP_VDEFAULT_TESTER_ENABLED) && (STD_ON == DOIP_VDEFAULT_TESTER_ENABLED) */
  }
  return retVal;
}
/* PRQA L:MSR_STMIF */

#if ( defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) )
/**********************************************************************************************************************
 *  DoIP_VGetChannelByEcuAddr
 *********************************************************************************************************************/
STATIC FUNC(PduIdType, DOIP_CODE) DoIP_VGetChannelByEcuAddr(uint16 EcuAddr)
{
  PduIdType pduId = DOIP_INV_PDU_ID;
  PduIdType idx   = DOIP_VCHANNELS_TOTAL;

  /* try to find corresponding channel */
  while ( 0u < idx )
  {
    idx--;
    if ( EcuAddr == DoIP_VChannel2EcuAddr[idx] )
    {
      pduId = idx;
      break;
    }
  }

  return pduId;
}
#endif /* defined(DOIP_VSUPPORT_DOIP_GW) && (STD_ON == DOIP_VSUPPORT_DOIP_GW) */

/**********************************************************************************************************************
 *  DoIP_VActivateConnectionAtChannel
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VActivateConnectionAtChannel(uint8 RoutActIdx, PduIdType Connection)
{
  uint8 channelNum = DoIP_VRoutingActivations[RoutActIdx].ChannelNum;

  /* set connection active on all corresponding channels */
  while ( 0u < channelNum )
  {
    PduIdType channel;

    channelNum--;

    channel = DoIP_VRoutingActivations[RoutActIdx].ChannelColPtr[channelNum];
    DoIP_VChannel2TcpCon[channel] = Connection;
  }
}

/**********************************************************************************************************************
 *  DoIP_VGetConnectionBySoConId
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, DOIP_CODE) DoIP_VGetConnectionBySoConId(SoAd_SoConIdType SoConId,
                               P2VAR(PduIdType, AUTOMATIC, DOIP_APPL_VAR) Connection)
{
  Std_ReturnType retVal = E_NOT_OK;
  PduIdType pduId = DOIP_VCONNECTION_TOTAL;

  while ( 0u < pduId )
  {
    pduId--;
    if ( (DoIP_VCon2SoConId[pduId] == SoConId) && (SOAD_INV_SO_CON_ID != SoConId) )
    {
      *Connection = pduId;
      retVal = E_OK;
      break;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  DoIP_VCloseSoCon
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VCloseSoCon(PduIdType Connection)
{
  (void)SoAd_CloseSoCon(DoIP_VCon2SoConId[Connection], TRUE);
}

/**********************************************************************************************************************
 *  DoIP_VGetAvailableSockNum
 *********************************************************************************************************************/
STATIC FUNC(uint8, DOIP_CODE) DoIP_VGetAvailableSockNum(uint8 LocalAddrIdx)
{
  PduIdType localSoAdRxPduId = DOIP_VCONNECTION_TCP_TOTAL;
  PduIdType routActivNum = 0u;
  PduIdType connectionNum = 0u;

  while ( 0u < localSoAdRxPduId )
  {
    localSoAdRxPduId--;
    if ( DoIP_VCon2LocalAddrIdx[localSoAdRxPduId] == LocalAddrIdx )
    { /* local address index match */
      connectionNum++;
      if ( DOIP_INV_TESTER_IDX != DoIP_VTcpCon2ActivMgt[localSoAdRxPduId].TesterIdx )
      { /* tester connected */
        routActivNum++;
      }
    }
  }

  return (uint8)((connectionNum - routActivNum) - 1u); /* PRQA S 3382 */ /* MD_DoIP_21.1_CFG */
}

/**********************************************************************************************************************
 *  DoIP_VRemoveAliveCheckFromRoutActHandler
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VRemoveAliveCheckFromRoutActHandler(PduIdType Connection)
{
  uint8 tmpListIdx = DOIP_VMAX_CONS_PER_LOC_ADDR;

  while ( 0u < tmpListIdx )
  {
    tmpListIdx--;

    if ( Connection == DoIP_VRoutActivHandler.AliveCheckList[tmpListIdx] )
    { /* entry found */
      /* remove it */
      DoIP_VRoutActivHandler.AliveCheckList[tmpListIdx] = DOIP_INV_PDU_ID;
      /* decrement size */
      DoIP_VRoutActivHandler.AliveCheckElemNum--;
      break;
    }
  }
}

#if ( (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) )
/**********************************************************************************************************************
 *  DoIP_VRequestIpAddrAssignment
 *********************************************************************************************************************/
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, DOIP_CODE) DoIP_VRequestIpAddrAssignment(uint8 LocalAddrIdx)
{
  PduIdType connection = DOIP_VCONNECTION_TOTAL;

  while ( DOIP_VCONNECTION_TCP_TOTAL < connection )
  {
    connection--;

    if ( DoIP_VCon2LocalAddrIdx[connection] == LocalAddrIdx )
    { /* UdpConnection for current local address found */
      DoIP_VLocalAddrIdx2IpAddrReqState[LocalAddrIdx] = DOIP_IP_ADDR_REQ_STATE_REQUESTED;

# if ( DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON )
#  if ( (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_STATIC) != 0u )
      if ( (DoIP_VLocalAddrIdx2AssignmentType[LocalAddrIdx] & DOIP_IPADDR_ASSIGN_PATTERN_STATIC) != 0u )
      { /* static IP address */
        SoAd_SockAddrInet6Type localIpAddr = { SOAD_AF_INET6, SOAD_PORT_ANY,
          {SOAD_IPADDR_ANY, SOAD_IPADDR_ANY, SOAD_IPADDR_ANY, SOAD_IPADDR_ANY} };
        SoAd_SockAddrInet6Type defaultRouter = { SOAD_AF_INET6, SOAD_PORT_ANY,
          {SOAD_IPADDR_ANY, SOAD_IPADDR_ANY, SOAD_IPADDR_ANY, SOAD_IPADDR_ANY} };

        localIpAddr.domain = DoIP_VLocalAddrIdx2DomainType[LocalAddrIdx];
        defaultRouter.domain = DoIP_VLocalAddrIdx2DomainType[LocalAddrIdx];

        /* request IP address assignment */
        if ( E_OK != SoAd_RequestIpAddrAssignment(DoIP_VCon2SoConId[connection], SOAD_IPADDR_ASSIGNMENT_STATIC,
          DOIP_A_P2VAR(SoAd_SockAddrType)&localIpAddr, 0u, DOIP_A_P2VAR(SoAd_SockAddrType)&defaultRouter) )
        { /* request failed */
          /* no requirement specified */
          /* reset DOIP_IP_ADDR_REQ_STATE_REQUESTED to support assignment callback in this context */
          DoIP_VLocalAddrIdx2IpAddrReqState[LocalAddrIdx] &= DOIP_IP_ADDR_REQ_STATE_REQUESTED_INV;
          break; /* PRQA S 0771 */ /* MD_DoIP_14.6 */
        }
      }
#  endif /* (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_STATIC) != 0u */
#  if ( (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_LINKLOCAL_DOIP) != 0u )
      if ( (DoIP_VLocalAddrIdx2AssignmentType[LocalAddrIdx] & DOIP_IPADDR_ASSIGN_PATTERN_LINKLOCAL_DOIP) != 0u )
      { /* link local DoIP IP address */
        /* request IP address assignment */
        if ( E_OK != SoAd_RequestIpAddrAssignment(DoIP_VCon2SoConId[connection], SOAD_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP,
          NULL_PTR, 0u, NULL_PTR) )
        { /* request failed */
          /* no requirement specified */
          /* reset DOIP_IP_ADDR_REQ_STATE_REQUESTED to support assignment callback in this context */
          DoIP_VLocalAddrIdx2IpAddrReqState[LocalAddrIdx] &= DOIP_IP_ADDR_REQ_STATE_REQUESTED_INV;
          break; /* PRQA S 0771 */ /* MD_DoIP_14.6 */
        }
      }
#  endif /* (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_LINKLOCAL_DOIP) != 0u */
#  if ( (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_LINKLOCAL) != 0u )
      if ( (DoIP_VLocalAddrIdx2AssignmentType[LocalAddrIdx] & DOIP_IPADDR_ASSIGN_PATTERN_LINKLOCAL) != 0u )
      { /* link local IP address */
        /* request IP address assignment */
        if ( E_OK != SoAd_RequestIpAddrAssignment(DoIP_VCon2SoConId[connection], SOAD_IPADDR_ASSIGNMENT_LINKLOCAL,
          NULL_PTR, 0u, NULL_PTR) )
        { /* request failed */
          /* no requirement specified */
          /* reset DOIP_IP_ADDR_REQ_STATE_REQUESTED to support assignment callback in this context */
          DoIP_VLocalAddrIdx2IpAddrReqState[LocalAddrIdx] &= DOIP_IP_ADDR_REQ_STATE_REQUESTED_INV;
          break; /* PRQA S 0771 */ /* MD_DoIP_14.6 */
        }
      }
#  endif /* (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_LINKLOCAL) != 0u */
#  if ( (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_IPV6_ROUTER) != 0u )
      if ( (DoIP_VLocalAddrIdx2AssignmentType[LocalAddrIdx] & DOIP_IPADDR_ASSIGN_PATTERN_IPV6_ROUTER) != 0u )
      { /* Router Advertisement IP address */
        /* request IP address assignment */
        if ( E_OK != SoAd_RequestIpAddrAssignment(DoIP_VCon2SoConId[connection], SOAD_IPADDR_ASSIGNMENT_IPV6_ROUTER,
          NULL_PTR, 0u, NULL_PTR) )
        { /* request failed */
          /* no requirement specified */
          /* reset DOIP_IP_ADDR_REQ_STATE_REQUESTED to support assignment callback in this context */
          DoIP_VLocalAddrIdx2IpAddrReqState[LocalAddrIdx] &= DOIP_IP_ADDR_REQ_STATE_REQUESTED_INV;
          break; /* PRQA S 0771 */ /* MD_DoIP_14.6 */
        }
      }
#  endif /* (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_IPV6_ROUTER) != 0u */
# endif /* DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON */
# if ( (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u )
      if ( (DoIP_VLocalAddrIdx2AssignmentType[LocalAddrIdx] & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u )
      { /* DHCP IP address */
        /* overwrite hostname option */
#  if ( defined(DOIP_VDHCP_OPTION_VIN_USE_ENABLED) && (STD_ON == DOIP_VDHCP_OPTION_VIN_USE_ENABLED) )
        /* PRQA S 0686 2 */ /* MD_DoIP_0686 */
        uint8 hostName[DOIP_VMIN_HOST_NAME_SIZE + DOIP_VIN_PREFIX_LEN_BYTE + DOIP_VIN_LEN_BYTE] =
          { 'D', 'o', 'I', 'P', '-', 'V', 'I', 'N'};

        if ( E_OK != DoIP_VCallGetVinDirect(&hostName[DOIP_VMIN_HOST_NAME_SIZE + DOIP_VIN_PREFIX_LEN_BYTE]) )
        { /* VIN request failed */
          /* use invaliditiy pattern */
          uint8 idx = (uint8)(DOIP_VMIN_HOST_NAME_SIZE + DOIP_VIN_PREFIX_LEN_BYTE + DOIP_VIN_LEN_BYTE);

          while ( (DOIP_VMIN_HOST_NAME_SIZE + DOIP_VIN_PREFIX_LEN_BYTE) < idx )
          {
            idx--;
            hostName[idx] = DOIP_VVIN_INV_PATTERN;
          }
        }

        if ( E_OK != SoAd_WriteDhcpHostNameOption(DoIP_VCon2SoConId[connection],
            (DOIP_VMIN_HOST_NAME_SIZE + DOIP_VIN_PREFIX_LEN_BYTE + DOIP_VIN_LEN_BYTE), hostName) )
        {
          /* no requirement specified */
          /* reset DOIP_IP_ADDR_REQ_STATE_REQUESTED to support assignment callback in this context */
          DoIP_VLocalAddrIdx2IpAddrReqState[LocalAddrIdx] &= DOIP_IP_ADDR_REQ_STATE_REQUESTED_INV;
          break; /* PRQA S 0771 */ /* MD_DoIP_14.6 */
        }
#  else
        uint8 hostName[DOIP_VMIN_HOST_NAME_SIZE] = { 'D', 'o', 'I', 'P', '-' };

        if ( E_OK != SoAd_WriteDhcpHostNameOption(DoIP_VCon2SoConId[connection],
            DOIP_VMIN_HOST_NAME_SIZE, hostName) )
        {
          /* no requirement specified */
          /* reset DOIP_IP_ADDR_REQ_STATE_REQUESTED to support assignment callback in this context */
          DoIP_VLocalAddrIdx2IpAddrReqState[LocalAddrIdx] &= DOIP_IP_ADDR_REQ_STATE_REQUESTED_INV;
          break; /* PRQA S 0771 */ /* MD_DoIP_14.6 */
        }
#  endif /* defined(DOIP_VDHCP_OPTION_VIN_USE_ENABLED) && (STD_ON == DOIP_VDHCP_OPTION_VIN_USE_ENABLED) */

#  if ( DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON )
        /* request IP address assignment */
        if ( E_OK != SoAd_RequestIpAddrAssignment(DoIP_VCon2SoConId[connection], SOAD_IPADDR_ASSIGNMENT_DHCP,
          NULL_PTR, 0u, NULL_PTR) )
        { /* request failed */
          /* no requirement specified */
          /* reset DOIP_IP_ADDR_REQ_STATE_REQUESTED to support assignment callback in this context */
          DoIP_VLocalAddrIdx2IpAddrReqState[LocalAddrIdx] &= DOIP_IP_ADDR_REQ_STATE_REQUESTED_INV;
          break; /* PRQA S 0771 */ /* MD_DoIP_14.6 */
        }
#  endif /* DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON */
      }
# endif /* (DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u */
      break; /* PRQA S 0771 */ /* MD_DoIP_14.6 */
    }
  }
}
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
#endif /* (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) */

/**********************************************************************************************************************
 *  DoIP_VActivationLineStateTransitionToActive
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VActivationLineStateTransitionToActive(void)
{
  Std_ReturnType retVal = E_OK;

  /* initiate socket connection structs if not done before */
  if ( SOAD_INV_SO_CON_ID == DoIP_VCon2SoConId[0] )
  {
    PduIdType connection;
    SoAd_SoConIdType soConId = 0u;

    /* get socket connection identifier from SoAd */
    for ( connection = 0u; connection < DOIP_VCONNECTION_TOTAL; connection++ )
    {
      retVal |= SoAd_GetSoConId(DoIP_VCon2SoAdTxPduId[connection], &soConId);

      if ( E_OK == retVal )
      {
        DoIP_VCon2SoConId[connection] = soConId;
      }
      else
      {
        DOIP_CallDetReportError(DOIP_API_ID_VACT_LINE_STATE_TRANS_TO_ACT, DOIP_E_SOAD_CALL_FAILED);
        break;
      }
    }
  }

  if ( E_OK == retVal )
  {
    /* switch to active */
    DoIP_ActivationLineLocalState = DOIP_ACTIVATION_LINE_LOCAL_ACTIVE;

#if ( (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) )
    {
      /* read and write DHCP hostname option and request IP address assignment */
      uint8 localAddrIdx = DOIP_VLOCAL_ADDR_TOTAL;

      while ( 0u < localAddrIdx )
      { /* iterate over all UdpConnections and read/write DHCP option and request IP address assignment on one 
         * UdpConnection of each local address */
        localAddrIdx--;

        if ( DOIP_IP_ADDR_REQ_STATE_NONE == DoIP_VLocalAddrIdx2IpAddrReqState[localAddrIdx] )
        {
          DoIP_VRequestIpAddrAssignment(localAddrIdx);
        }
      }
    }
#endif /* (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) */
  }
} /* PRQA S 0779 */ /* MD_DoIP_5.1 */

#if ( defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) )
/**********************************************************************************************************************
 *  DoIP_VActivationLineStateTransitionToInactive
 *********************************************************************************************************************/
/* PRQA S 0779 DoIP_51*/ /* MD_DoIP_5.1 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, DOIP_CODE) DoIP_VActivationLineStateTransitionToInactive(void)
{
  boolean   soConsClosed = TRUE;
  PduIdType connection   = DOIP_VCONNECTION_TOTAL;

  while ( 0u < connection )
  {
    connection--;
    if ( SOAD_SOCON_OFFLINE != DoIP_VCon2SoConState[connection] )
    { /* socket connection not closed yet */
      soConsClosed = FALSE;

      if ( TRUE != DoIP_VCon2SoConClosing[connection] )
      { /* socket connection not requested to be closed */
        DoIP_VCon2SoConClosing[connection] = TRUE;
        DoIP_VCloseSoCon(connection);
      }
    }
  }

  if ( FALSE != soConsClosed )
  { /* all socket connections closed */
    /* release IP address assignment on all local addresses */
    uint8 localAddrIdx = DOIP_VLOCAL_ADDR_TOTAL;
    uint8 localAddrUnassigned = 0u;
    while ( 0u < localAddrIdx )
    { /* iterate over all UdpConnections and release IP address assignment on one UdpConnection of each local address */
      localAddrIdx--;

      if ( (DOIP_IP_ADDR_REQ_STATE_NONE != DoIP_VLocalAddrIdx2IpAddrReqState[localAddrIdx]) && 
        (DOIP_IP_ADDR_REQ_STATE_RELEASE != DoIP_VLocalAddrIdx2IpAddrReqState[localAddrIdx]) )
      { /* local address not yet released on this local address */
        connection = DOIP_VCONNECTION_TOTAL;
        while ( DOIP_VCONNECTION_TCP_TOTAL < connection )
        {
          connection--;
          if ( DoIP_VCon2LocalAddrIdx[connection] == localAddrIdx )
          { /* UdpConnection for current local address found */
            DoIP_VLocalAddrIdx2IpAddrReqState[localAddrIdx] = DOIP_IP_ADDR_REQ_STATE_RELEASE;
            /* release IP address assignment */
            if ( E_OK != SoAd_ReleaseIpAddrAssignment(DoIP_VCon2SoConId[connection]) )
            { /* release failed */
              /* no requirement specified */
              /* perform retry in next MainFunction cycle */
              DoIP_VLocalAddrIdx2IpAddrReqState[localAddrIdx] = DOIP_IP_ADDR_REQ_STATE_ASSIGNED;
            }
            break;
          }
        }
      }
      else if ( DOIP_IP_ADDR_REQ_STATE_NONE == DoIP_VLocalAddrIdx2IpAddrReqState[localAddrIdx] )
      {
        localAddrUnassigned++;
      }
      else
      {
        /* nothing to do */
      }
    }

    /* check if all local addresses are unassigned */
    if ( DOIP_VLOCAL_ADDR_TOTAL == localAddrUnassigned )
    { /* all local addresses unassigned */
#if ( defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) )
      /* reset GID sync */
      DoIP_GidInSync = FALSE;
#endif /* defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) */

      /* switch to inactive */
      DoIP_ActivationLineLocalState = DOIP_ACTIVATION_LINE_LOCAL_INACTIVE;
    }
  }
}
/* PRQA L:DoIP_51*/
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */
#endif /* defined(DOIP_VACTIV_LINE_CALLBACK_ENABLED) && (STD_ON == DOIP_VACTIV_LINE_CALLBACK_ENABLED) */

/**********************************************************************************************************************
 *  DoIP_VPerformAuthConfAndActivateRouting
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
STATIC FUNC(void, DOIP_CODE) DoIP_VPerformAuthConfAndActivateRouting(void)
{
  PduIdType connection = DoIP_VRoutActivHandler.TcpCon;
  uint16    testerAddr = DoIP_VRoutActivHandler.TesterAddr;
  uint8     testerIdx  = DoIP_VRoutActivHandler.TesterIdx;
  uint8     routActIdx = DoIP_VRoutActivHandler.RoutActIdx;

  /* check OEM part */
  if ( (FALSE == DoIP_VRoutActivHandler.OemSpecUsed) &&
    ((0u != DoIP_VRoutingActivations[routActIdx].AuthReqLength) ||
      (0u != DoIP_VRoutingActivations[routActIdx].ConfReqLength)) )
  { /* routing activation requires OEM specific part */
    DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

    (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
      DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT, testerIdx, NULL_PTR, FALSE);

    return;
  }

  /* call authentication callback */
  if ( DoIP_VRoutingActivations[routActIdx].AuthFuncPtr != NULL_PTR )
  {
    Std_ReturnType retVal;
    boolean authentified = FALSE;

#if ( DOIP_VROUT_ACT_AUTH_REM_ADDR_ENABLED == STD_ON )
    if ( DoIP_VRoutingActivations[routActIdx].AuthFuncWithRemAddr == TRUE )
    {
      SoAd_SockAddrInet6Type remAddr;

      remAddr.domain = SOAD_AF_UNSPEC;

      /* PRQA S 0310 6 */ /* MD_DoIP_11.4 */
      if ( SoAd_GetRemoteAddr(DoIP_VCon2SoConId[connection], DOIP_A_P2VAR(SoAd_SockAddrType)&remAddr) == E_OK )
      {
        /* PRQA S 0313 1 */ /* MD_DoIP_11.1 */
        retVal = ((DoIP_AuthWithRemAddrFctPtrType)DoIP_VRoutingActivations[routActIdx].AuthFuncPtr)
          (&authentified, DoIP_VRoutActivHandler.OemSpecReq,DoIP_VRoutActivHandler.OemSpecRes,
          DOIP_A_P2CONST(SoAd_SockAddrType)&remAddr);
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
    else
#endif /* DOIP_VROUT_ACT_AUTH_REM_ADDR_ENABLED == STD_ON */
    {
      retVal = DoIP_VRoutingActivations[routActIdx].AuthFuncPtr
        (&authentified, DoIP_VRoutActivHandler.OemSpecReq,DoIP_VRoutActivHandler.OemSpecRes);
    }

    if ( E_NOT_OK == retVal )
    { /* authentication failed */
      /* register tester */
      DoIP_VTcpCon2ActivMgt[connection].TesterIdx = testerIdx;
      DoIP_VTcpCon2ActivMgt[connection].TesterAddr = testerAddr;
      DoIP_VTcpCon2ActivMgt[connection].RoutActIdx = routActIdx;
      DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

      (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
        DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT, testerIdx, NULL_PTR, FALSE);

      return;
    }
    else if ( DOIP_E_PENDING == retVal )
    { /* authentication pending */
      /* register tester */
      DoIP_VTcpCon2ActivMgt[connection].TesterIdx = testerIdx;
      DoIP_VTcpCon2ActivMgt[connection].TesterAddr = testerAddr;
      DoIP_VTcpCon2ActivMgt[connection].RoutActIdx = routActIdx;
      DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_AUTH_PENDING;

      return;
    }
    else
    { /* authentication successful (callback return value) */
      if ( TRUE != authentified )
      { /* authentication failed */
        /* register tester */
        DoIP_VTcpCon2ActivMgt[connection].TesterIdx = testerIdx;
        DoIP_VTcpCon2ActivMgt[connection].TesterAddr = testerAddr;
        DoIP_VTcpCon2ActivMgt[connection].RoutActIdx = routActIdx;
        DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

        (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
          DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT, testerIdx, NULL_PTR, FALSE);

        return;
      }
      else
      { /* authentication successful */
        /* nothing to do here */
      }
    }
  }

  /* call confirmation callback */
  if ( DoIP_VRoutingActivations[routActIdx].ConfFuncPtr != NULL_PTR )
  {
    Std_ReturnType retVal;
    boolean confirmed = FALSE;
    uint8 offsetReq = 0u;
    uint8 offsetRes = 0u;

    if ( 0u < DoIP_VRoutingActivations[routActIdx].ConfReqLength )
    {
      offsetReq = (uint8)(DOIP_ROUT_ACTIV_ACK_OEM_LEN_BYTE -
        DoIP_VRoutingActivations[routActIdx].ConfReqLength);
    }
    if ( 0u < DoIP_VRoutingActivations[routActIdx].ConfResLength )
    {
      offsetRes = (uint8)(DOIP_ROUT_ACTIV_ACK_OEM_LEN_BYTE -
        DoIP_VRoutingActivations[routActIdx].ConfResLength);
    }

#if ( DOIP_VROUT_ACT_CONF_REM_ADDR_ENABLED == STD_ON )
    if ( DoIP_VRoutingActivations[routActIdx].ConfFuncWithRemAddr == TRUE )
    {
      SoAd_SockAddrInet6Type remAddr;

      remAddr.domain = SOAD_AF_UNSPEC;

      /* PRQA S 0310 7 */ /* MD_DoIP_11.4 */
      if ( SoAd_GetRemoteAddr(DoIP_VCon2SoConId[connection], DOIP_A_P2VAR(SoAd_SockAddrType)&remAddr) == E_OK )
      {
        /* PRQA S 0313 2 */ /* MD_DoIP_11.1 */
        /* PRQA S 3689 2 */ /* MD_DoIP_21.1_IDX */
        retVal = ((DoIP_ConfWithRemAddrFctPtrType)DoIP_VRoutingActivations[routActIdx].ConfFuncPtr)
          (&confirmed, &DoIP_VRoutActivHandler.OemSpecReq[offsetReq], &DoIP_VRoutActivHandler.OemSpecRes[offsetRes],
          DOIP_A_P2CONST(SoAd_SockAddrType)&remAddr);
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
    else
#endif /* DOIP_VROUT_ACT_CONF_REM_ADDR_ENABLED */
    {
      /* PRQA S 3689 2 */ /* MD_DoIP_21.1_IDX */
      retVal = DoIP_VRoutingActivations[routActIdx].ConfFuncPtr
        (&confirmed, &DoIP_VRoutActivHandler.OemSpecReq[offsetReq], &DoIP_VRoutActivHandler.OemSpecRes[offsetRes]);
    }

    if ( E_NOT_OK == retVal )
    { /* confirmation failed */
      /* register tester */
      DoIP_VTcpCon2ActivMgt[connection].TesterIdx = testerIdx;
      DoIP_VTcpCon2ActivMgt[connection].TesterAddr = testerAddr;
      DoIP_VTcpCon2ActivMgt[connection].RoutActIdx = routActIdx;
      DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

      (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
        DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REJECTED, testerIdx, NULL_PTR, TRUE);

      return;
    }
    else if ( DOIP_E_PENDING == retVal )
    { /* confirmation pending */
      /* register tester */
      DoIP_VTcpCon2ActivMgt[connection].TesterIdx = testerIdx;
      DoIP_VTcpCon2ActivMgt[connection].TesterAddr = testerAddr;
      DoIP_VTcpCon2ActivMgt[connection].RoutActIdx = routActIdx;
      DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_CONF_PENDING;

      (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
        DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REQUIRED, testerIdx, NULL_PTR, FALSE);

      return;
    }
    else
    { /* confirmation successful (callback return value) */
      if ( TRUE != confirmed )
      { /* confirmation failed */
        /* register tester */
        DoIP_VTcpCon2ActivMgt[connection].TesterIdx = testerIdx;
        DoIP_VTcpCon2ActivMgt[connection].TesterAddr = testerAddr;
        DoIP_VTcpCon2ActivMgt[connection].RoutActIdx = routActIdx;
        DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

        (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
          DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REJECTED, testerIdx, NULL_PTR, TRUE);

        return;
      }
      else
      { /* confirmation successful */
        /* nothing to do here */
      }
    }
  }

  /* register tester */
  DoIP_VTcpCon2ActivMgt[connection].TesterIdx = testerIdx;
  DoIP_VTcpCon2ActivMgt[connection].TesterAddr = testerAddr;
  DoIP_VTcpCon2ActivMgt[connection].RoutActIdx = routActIdx;

  /* set mapping for connection and channels */
  DoIP_VActivateConnectionAtChannel(routActIdx, connection);

  /* routing activated */
  DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_ACTIVATED;

  /* reset inactivity counter */
  DoIP_VTcpCon2InactivCnt[connection] = 0u;

  (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
    DOIP_ROUT_ACTIV_RES_CODE_SUCCESS, testerIdx, NULL_PTR, FALSE);
}
/* PRQA L:MSR_14_7 */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STPTH */

/**********************************************************************************************************************
 *  DoIP_VOpenSockConInitially
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VOpenSockConInitially(PduIdType Connection)
{
  DOIP_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if ( SOAD_SOCON_OFFLINE == DoIP_VCon2SoConState[Connection] )
  { /* call SoAd to reopen socket connection */
    /* set state to reconnect to avoid multiple open requests */
    DoIP_VCon2SoConState[Connection] = SOAD_SOCON_RECONNECT;

    DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    (void)SoAd_OpenSoCon(DoIP_VCon2SoConId[Connection]);
  }
  else
  {
    DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}

/**********************************************************************************************************************
 *  DoIP_VHandleCloseSocketInUdpTxList
 *********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_VHandleCloseSocketInUdpTxList(uint16 udpTxListIdx)
{
  PduIdType connection = DoIP_VUdpTxMgtList[udpTxListIdx].UdpCon;

  /* check if socket connection shall be closed */
  if ( (DOIP_INV_PDU_ID != connection) && (TRUE == DoIP_VCon2SoConClosing[connection]) )
  { /* socket connection shall be closed */
    /* check if other entries for socket connection exists */
    PduIdType tmpListIdx = DOIP_VUDP_TX_MGT_LIST_SIZE;
    boolean otherEntryFound = FALSE;

    while ( 0u < tmpListIdx )
    {
      tmpListIdx--;
      if ( (udpTxListIdx != tmpListIdx) &&
        (DoIP_VUdpTxMgtList[udpTxListIdx].UdpCon == DoIP_VUdpTxMgtList[tmpListIdx].UdpCon) )
      { /* found other entry */
        /* do not close socket connection */
        otherEntryFound = TRUE;
        break;
      }
    }

    if ( FALSE == otherEntryFound )
    { /* no other entry found */
      /* close socket connection */
      DoIP_VCloseSoCon(connection);
    }
  }
}

#if ( (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) )
/**********************************************************************************************************************
 *  DoIP_VHandleIpAddrReassignment
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VHandleIpAddrReassignment(void)
{
  uint8 localAddrIdx = DOIP_VLOCAL_ADDR_TOTAL;

  while ( 0u < localAddrIdx )
  {
    localAddrIdx--;

    if ( DOIP_IP_ADDR_REQ_STATE_NONE == DoIP_VLocalAddrIdx2IpAddrReqState[localAddrIdx] )
    {
      DoIP_VRequestIpAddrAssignment(localAddrIdx);
    }
  }
}
#endif /* (DOIP_VACTIV_LINE_CALLBACK_ENABLED == STD_ON) || \
  ((DOIP_VIPADDR_ASSIGN_GLOBAL_PATTERN & DOIP_IPADDR_ASSIGN_PATTERN_DHCP) != 0u) */

/**********************************************************************************************************************
 *  DoIP_VHandleSockConStates
 *********************************************************************************************************************/
STATIC FUNC(void, DOIP_CODE) DoIP_VHandleSockConStates(void)
{
  PduIdType connection = DOIP_VCONNECTION_TOTAL;

  while ( DOIP_VCONNECTION_TCP_TOTAL < connection )
  {
    connection--;

    if ( DOIP_VCONNECTION_TCP_UDP_TOTAL <= connection )
    { /* UDP connection for vehicle announcements */
      /* do not reopen socket connection */
    }
    else
    { /* UDP connection for requests */
      DOIP_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      if ( (SOAD_SOCON_OFFLINE == DoIP_VCon2SoConState[connection]) && 
        (SOAD_IPADDR_STATE_ASSIGNED == DoIP_VCon2IpAddrState[connection]) )
      { /* call SoAd to reopen socket connection */
        /* set state to reconnect to avoid multiple open requests */
        DoIP_VCon2SoConState[connection] = SOAD_SOCON_RECONNECT;

        DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        (void)SoAd_OpenSoCon(DoIP_VCon2SoConId[connection]);
      }
      else
      {
        DOIP_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
    }
  }

  while ( 0u < connection )
  {
    connection--;

    if ( (SOAD_SOCON_OFFLINE == DoIP_VCon2SoConState[connection]) && 
      (SOAD_IPADDR_STATE_ASSIGNED == DoIP_VCon2IpAddrState[connection]) )
    { /* call SoAd to reopen socket connection */
      (void)SoAd_OpenSoCon(DoIP_VCon2SoConId[connection]);
      /* set state to reconnect to avoid multiple open requests */
      DoIP_VCon2SoConState[connection] = SOAD_SOCON_RECONNECT;
    }
  }
}

#if ( defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) )
/**********************************************************************************************************************
 *  DoIP_VHandleGidSync
 *********************************************************************************************************************/
/* PRQA S 2006 MSR_14_7 */ /* MD_MSR_14.7 */
STATIC FUNC(void, DOIP_CODE) DoIP_VHandleGidSync(void)
{
  if ( TRUE != DoIP_GidInSync )
  {
    uint8_least localAddrIdx;

    for ( localAddrIdx = 0u; localAddrIdx < DOIP_VLOCAL_ADDR_TOTAL; localAddrIdx++ )
    {
      if ( DoIP_VLocalAddrIdx2IpAddrReqState[localAddrIdx] == DOIP_IP_ADDR_REQ_STATE_ASSIGNED )
      {
        if ( DoIP_VCallTriggerGidSync() == E_OK )
        {
          DoIP_GidInSync = TRUE;
        }
        break;
      }
    }
  }
}
/* PRQA L:MSR_14_7 */
#endif /* defined(DOIP_VGID_SYNC_ENABLED) && (STD_ON == DOIP_VGID_SYNC_ENABLED) */

/**********************************************************************************************************************
 *  DoIP_VHandleAuthConf
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, DOIP_CODE) DoIP_VHandleAuthConf(void)
{
  PduIdType connection = DoIP_VRoutActivHandler.TcpCon;

  if ( (DOIP_INV_PDU_ID != connection) && (0u == DoIP_VRoutActivHandler.AliveCheckCnt) )
  { /* routing activation but no alive check is pending */
    uint16 testerAddr = DoIP_VRoutActivHandler.TesterAddr;
    uint8 routActIdx = DoIP_VRoutActivHandler.RoutActIdx;
    uint8 testerIdx = DoIP_VRoutActivHandler.RoutActIdx;
    DoIP_RoutActivStateType nextState = DOIP_ROUT_ACTIV_STATE_NONE;
    DoIP_RoutActivStateType lastState = DoIP_VTcpCon2ActivMgt[connection].ActivState;

    /* call authentication callback */
    if ( DOIP_ROUT_ACTIV_STATE_AUTH_PENDING == lastState )
    {
      boolean authentified = FALSE;
      Std_ReturnType retVal;

#if ( DOIP_VROUT_ACT_AUTH_REM_ADDR_ENABLED == STD_ON )
      if ( DoIP_VRoutingActivations[routActIdx].AuthFuncWithRemAddr == TRUE )
      {
        SoAd_SockAddrInet6Type remAddr;

        remAddr.domain = SOAD_AF_UNSPEC;

        /* PRQA S 0310 6 */ /* MD_DoIP_11.4 */
        if ( SoAd_GetRemoteAddr(DoIP_VCon2SoConId[connection], DOIP_A_P2VAR(SoAd_SockAddrType)&remAddr) == E_OK )
        {
          /* PRQA S 0313 1 */ /* MD_DoIP_11.1 */
          retVal = ((DoIP_AuthWithRemAddrFctPtrType)DoIP_VRoutingActivations[routActIdx].AuthFuncPtr)
            (&authentified, DoIP_VRoutActivHandler.OemSpecReq,DoIP_VRoutActivHandler.OemSpecRes,
            DOIP_A_P2CONST(SoAd_SockAddrType)&remAddr);
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
      else
#endif /* DOIP_VROUT_ACT_AUTH_REM_ADDR_ENABLED == STD_ON */
      {
        retVal = DoIP_VRoutingActivations[routActIdx].AuthFuncPtr
          (&authentified, DoIP_VRoutActivHandler.OemSpecReq,DoIP_VRoutActivHandler.OemSpecRes);
      }

      if ( E_NOT_OK == retVal )
      { /* authentication failed */
        DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

        (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
          DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT, testerIdx, NULL_PTR, FALSE);
      }
      else if ( DOIP_E_PENDING == retVal )
      { /* authentication pending */
        /* nothing to do here (rety in next MainFunction) */
      }
      else
      { /* authentication successful (callback return value) */
        if ( TRUE != authentified )
        { /* authentication failed */
          DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

          (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
            DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT, testerIdx, NULL_PTR, FALSE);
        }
        else
        { /* authentication successful */
          nextState = DOIP_ROUT_ACTIV_STATE_ACTIVATED;
        }
      }
    }

    /* call confirmation callback */
    if ( (DOIP_ROUT_ACTIV_STATE_CONF_PENDING == lastState) || ((DOIP_ROUT_ACTIV_STATE_ACTIVATED == nextState) &&
      (DoIP_VRoutingActivations[routActIdx].ConfFuncPtr != NULL_PTR)) )
    {
      Std_ReturnType retVal;
      boolean confirmed = FALSE;
      uint8 offsetReq = 0u;
      uint8 offsetRes = 0u;

      if ( 0u < DoIP_VRoutingActivations[routActIdx].ConfReqLength )
      {
        offsetReq = (uint8)(DOIP_ROUT_ACTIV_ACK_OEM_LEN_BYTE -
          DoIP_VRoutingActivations[routActIdx].ConfReqLength);
      }
      if ( 0u < DoIP_VRoutingActivations[routActIdx].ConfResLength )
      {
        offsetRes = (uint8)(DOIP_ROUT_ACTIV_ACK_OEM_LEN_BYTE -
          DoIP_VRoutingActivations[routActIdx].ConfResLength);
      }

#if ( DOIP_VROUT_ACT_CONF_REM_ADDR_ENABLED == STD_ON )
      if ( DoIP_VRoutingActivations[routActIdx].ConfFuncWithRemAddr == TRUE )
      {
        SoAd_SockAddrInet6Type remAddr;

        remAddr.domain = SOAD_AF_UNSPEC;

        /* PRQA S 0310 7 */ /* MD_DoIP_11.4 */
        if ( SoAd_GetRemoteAddr(DoIP_VCon2SoConId[connection], DOIP_A_P2VAR(SoAd_SockAddrType)&remAddr) == E_OK )
        {
          /* PRQA S 0313 2 */ /* MD_DoIP_11.1 */
          /* PRQA S 3689 2 */ /* MD_DoIP_21.1_IDX */
          retVal = ((DoIP_ConfWithRemAddrFctPtrType)DoIP_VRoutingActivations[routActIdx].ConfFuncPtr)
            (&confirmed, &DoIP_VRoutActivHandler.OemSpecReq[offsetReq], &DoIP_VRoutActivHandler.OemSpecRes[offsetRes],
            DOIP_A_P2CONST(SoAd_SockAddrType)&remAddr);
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
      else
#endif /* DOIP_VROUT_ACT_CONF_REM_ADDR_ENABLED == STD_ON */
      {
        /* PRQA S 3689 2 */ /* MD_DoIP_21.1_IDX */
        retVal = DoIP_VRoutingActivations[routActIdx].ConfFuncPtr
          (&confirmed, &DoIP_VRoutActivHandler.OemSpecReq[offsetReq], &DoIP_VRoutActivHandler.OemSpecRes[offsetRes]);
      }

      if ( E_NOT_OK == retVal )
      { /* confirmation failed */
        DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

        (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
          DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REJECTED, testerIdx, NULL_PTR, TRUE);
      }
      else if ( DOIP_E_PENDING == retVal )
      { /* confirmation pending */
        if ( DOIP_ROUT_ACTIV_STATE_ACTIVATED == nextState )
        { /* authentication performed in same context - first pending returned for confirmation */
          DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_CONF_PENDING;
          
          /* routing activation response has to be sent */
          (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
            DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REQUIRED, testerIdx, NULL_PTR, FALSE);
        }
        /* rety in next MainFunction */
      }
      else
      { /* confirmation successful (callback return value) */
        if ( TRUE != confirmed )
        { /* confirmation failed */
          DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

          (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
            DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REJECTED, testerIdx, NULL_PTR, TRUE);
        }
        else
        { /* confirmation successful */
          nextState = DOIP_ROUT_ACTIV_STATE_ACTIVATED;
        }
      }
    }

    /* routing activated */
    if ( DOIP_ROUT_ACTIV_STATE_ACTIVATED == nextState )
    { /* routing activation successful */
      /* set mapping for connection and channels */
      DoIP_VActivateConnectionAtChannel(routActIdx, connection);

      DoIP_VTcpCon2ActivMgt[connection].ActivState = DOIP_ROUT_ACTIV_STATE_ACTIVATED;

      if ( DOIP_ROUT_ACTIV_STATE_CONF_PENDING != lastState )
      { /* not activated after confirmation was pending (i.e. response was already sent) */
        /* reset inactivity counter */
        DoIP_VTcpCon2InactivCnt[connection] = 0u;

        /* send routing activation response */
        (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, testerAddr,
          DOIP_ROUT_ACTIV_RES_CODE_SUCCESS, testerIdx, NULL_PTR, FALSE);
      }
      else
      { /* activated after confirmation was pending (i.e. response was already sent) */
        /* release routing activation handler */
        DoIP_VRoutActivHandler.TcpCon = DOIP_INV_PDU_ID;
      }
    }
  }
}
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_VHandleUdpTxList
 *********************************************************************************************************************/
/* PRQA S 0715 MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, DOIP_CODE) DoIP_VHandleUdpTxList(void)
{
  PduIdType listIdx = DOIP_VUDP_TX_MGT_LIST_SIZE;
  while ( 0u < listIdx )
  {
    PduIdType connection;

    listIdx--;

    connection = DoIP_VUdpTxMgtList[listIdx].UdpCon;
    if ( DOIP_INV_PDU_ID != connection )
    { /* pending UDP message */
      boolean releaseListEntry = FALSE;

      if ( SOAD_SOCON_ONLINE == DoIP_VCon2SoConState[connection] )
      { /* socket connection is online */
        if ( DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT == DoIP_VUdpTxMgtList[listIdx].HdrType )
        { /* Vehicle Announcement/Vehicle Identification Response */
          DoIP_VUdpTxMgtList[listIdx].Param1--;
          if ( 0u == DoIP_VUdpTxMgtList[listIdx].Param1 )
          { /* try to send message */
            if ( E_OK != DoIP_VUdpSingleTransmit(connection, DOIP_HDR_TYPE_VEHICLE_ANNOUNCEMENT, DOIP_UNUSED_PARAM) )
            { /* transmission not successful */
              /* increment counter again to rety in next MainFunction */
              DoIP_VUdpTxMgtList[listIdx].Param1++;
              /* decrement retry attempt counter */
              DoIP_VUdpTxMgtList[listIdx].RetryAttempt--;
              if ( 0u == DoIP_VUdpTxMgtList[listIdx].RetryAttempt )
              { /* too many retries */
                /* release list entry to avoid that ECU does not answer other requests anymore */
                DoIP_VUdpTxMgtList[listIdx].UdpCon = DOIP_INV_PDU_ID;
              }
            }
            else
            { /* transmission successful */
              DoIP_VUdpTxMgtList[listIdx].Param2--;
              if ( DoIP_VUdpTxMgtList[listIdx].Param2 > 0u )
              { /* further Vehicle Announcement messages are pending */
                /* reload timer */
                DoIP_VUdpTxMgtList[listIdx].Param1 = DOIP_VANNOUNCE_WAIT;
              }
              else
              { /* all pending messages for this entry are sent */
                if ( DOIP_VCONNECTION_TCP_UDP_TOTAL > connection )
                {
                  DoIP_VHandleCloseSocketInUdpTxList(listIdx);
                }
                /* release list entry */
                DoIP_VUdpTxMgtList[listIdx].UdpCon = DOIP_INV_PDU_ID;
              }
            }
          }
        }
        else
        { /* Entity State Status Response, Diagnostic Power Mode Response or Generic Negative Acknowledgement */
          /* try to send message */
          if ( E_OK != DoIP_VUdpSingleTransmit(connection, DoIP_VUdpTxMgtList[listIdx].HdrType,
              DoIP_VUdpTxMgtList[listIdx].Param2) )
          { /* message not sent */
            /* decrement retry attempt counter */
            DoIP_VUdpTxMgtList[listIdx].RetryAttempt--;
            if ( 0u == DoIP_VUdpTxMgtList[listIdx].RetryAttempt )
            { /* too many retries */
              releaseListEntry = TRUE;
            }
          }
          else
          { /* message sent */
            releaseListEntry = TRUE;
          }
        }
      }
      else
      { /* socket connection is not online anymore */
        releaseListEntry = TRUE;
      }
      if ( releaseListEntry == TRUE )
      {
#if ( DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON )
        /* check if OEM specific payload type buffer has to be released */
        if ( DoIP_VUdpTxMgtList[listIdx].HdrType == DOIP_HDR_TYPE_OEM_SPECIFIC )
        {
          DoIP_VOemPayloadTypeUdpBufLen = 0u;
        }
#endif /* DOIP_VOEM_PAYLOAD_TYPE_ENABLED == STD_ON */
        DoIP_VHandleCloseSocketInUdpTxList(listIdx);
        /* release list entry */
        DoIP_VUdpTxMgtList[listIdx].UdpCon = DOIP_INV_PDU_ID;
      }
    }
  }
}
/* PRQA L:MSR_11715 */ /* MD_MSR_1.1_715 */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_VHandleTcpTxQueue
 *********************************************************************************************************************/
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, DOIP_CODE) DoIP_VHandleTcpTxQueue(void)
{
  PduIdType connection = DOIP_VCONNECTION_TCP_TOTAL;
  
  while ( 0u < connection )
  {
    connection--;

    if ( SOAD_SOCON_ONLINE == DoIP_VCon2SoConState[connection] )
    { /* socket connection is online */
#if ( DOIP_VTP_OPTIMZED_ENABLED == STD_ON )
      uint8_least txReqIdx;

      /* handle configured number of transmissmission requests within on main function cycle */
      for ( txReqIdx = 0u; txReqIdx < DOIP_VTCP_TX_QUEUE_REQ_CNT; txReqIdx++ )
#endif /* DOIP_VTP_OPTIMZED_ENABLED == STD_ON */
      {
        uint8 queLvl = DoIP_VTcpTxQueueGetLevel(connection);

        if ( queLvl > 0 )
        {
          DoIP_VTcpTxQueueSend(connection);
        }

#if ( DOIP_VTP_OPTIMZED_ENABLED == STD_ON )
        if ( (DoIP_VTcpTxQueueGetLevel(connection) == 0u) || (queLvl == DoIP_VTcpTxQueueGetLevel(connection)) )
        { /* queue is empty or queue level has not been changed (e.g. transmission still active) */
          break;
        }
#endif /* DOIP_VTP_OPTIMZED_ENABLED == STD_ON */
      }
    }
  }
}
/* PRQA L:MSR_STMIF */

/**********************************************************************************************************************
 *  DoIP_VHandleTimeouts
 *********************************************************************************************************************/
/* PRQA S 6010 MSR_STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 MSR_STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 MSR_STMIF */ /* MD_MSR_STMIF */
STATIC FUNC(void, DOIP_CODE) DoIP_VHandleTimeouts(void)
{
  PduIdType connection = DoIP_VRoutActivHandler.TcpCon;

  if ( DOIP_INV_PDU_ID != connection )
  {
    /* alive check */
    if ( 0u < DoIP_VRoutActivHandler.AliveCheckCnt )
    { /* handle alive check */
      DoIP_VRoutActivHandler.AliveCheckCnt--;
      if ( 0u == DoIP_VRoutActivHandler.AliveCheckCnt )
      { /* clean up all timed-out socket connections */
        PduIdType listIdx = DOIP_VMAX_CONS_PER_LOC_ADDR;

        while ( 0u < listIdx )
        {
          listIdx--;

          if ( 0u == DoIP_VRoutActivHandler.AliveCheckElemNum )
          { /* all sockets closed or Alive Check Response received */
            break;
          }
          if ( DOIP_INV_PDU_ID != DoIP_VRoutActivHandler.AliveCheckList[listIdx] )
          { /* alive check timeout -> close socket connection */
            PduIdType tmpSoAdRxPduId = DoIP_VRoutActivHandler.AliveCheckList[listIdx];

            DoIP_VCloseSoCon(tmpSoAdRxPduId);
            DoIP_VTcpCon2ActivMgt[tmpSoAdRxPduId].TesterIdx = DOIP_INV_TESTER_IDX;
            DoIP_VTcpCon2ActivMgt[tmpSoAdRxPduId].TesterAddr = DOIP_ADDR_ANY;
            DoIP_VTcpCon2ActivMgt[tmpSoAdRxPduId].RoutActIdx = DOIP_INV_ROUT_ACT_IDX;
            DoIP_VTcpCon2ActivMgt[tmpSoAdRxPduId].ActivState = DOIP_ROUT_ACTIV_STATE_NONE;

            DoIP_VRoutActivHandler.AliveCheckList[listIdx] = DOIP_INV_PDU_ID;
            DoIP_VRoutActivHandler.AliveCheckElemNum--;
          }
        }

        if ( SOAD_SOCON_ONLINE == DoIP_VCon2SoConState[connection] )
        { /* socket connection with routing activation request is still online */
          PduIdType tmpSoAdRxPduId = DOIP_INV_PDU_ID;

          /* check if routing is (still) active on other socket */
          DoIP_VGetConnectionOfTesterAddr(DoIP_VRoutActivHandler.TesterAddr, &tmpSoAdRxPduId);

            /* PRQA S 0277 1 */ /* MD_DoIP_3.1 */
          if ( DOIP_INV_PDU_ID != tmpSoAdRxPduId )
          { /* deny routing activation for active address on new socket connection */
            (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, DoIP_VRoutActivHandler.TesterAddr,
              DOIP_ROUT_ACTIV_RES_CODE_ALREADY_ACTIV, 0u, NULL_PTR, TRUE);
          }
          else
          { /* routing activation of new address */
            if ( 0u == DoIP_VGetAvailableSockNum(DoIP_VCon2LocalAddrIdx[connection]) )
            { /* all sockets but max one are in use - deny RoutingActivation request */
              (void)DoIP_VTcpTransmit(connection, DOIP_HDR_TYPE_ROUT_ACTIV_ACK, DoIP_VRoutActivHandler.TesterAddr,
                DOIP_ROUT_ACTIV_RES_CODE_SOCKETS_IN_USE, 0u, NULL_PTR, TRUE);
            }
            else
            { /* continue with received routing activation request */
              DoIP_VPerformAuthConfAndActivateRouting();
            }
          }
        }
      }
    }
  }

  connection = DOIP_VCONNECTION_TCP_TOTAL;
  while ( 0u < connection )
  {
    connection--;

    if ( SOAD_SOCON_ONLINE == DoIP_VCon2SoConState[connection] )
    {
      if ( DOIP_ROUT_ACTIV_STATE_ACTIVATED != DoIP_VTcpCon2ActivMgt[connection].ActivState )
      { /* no routing active */
        if ( DOIP_VINIT_INACTIV_WAIT == DoIP_VTcpCon2InactivCnt[connection] )
        { /* initial inactivity timeout */
          /* close socket */
          DoIP_VCloseSoCon(connection);
        }
      }
      else
      { /* routing activated */
        if ( DOIP_VGEN_INACTIV_WAIT == DoIP_VTcpCon2InactivCnt[connection] )
        { /* general inactivity timeout */
          /* close socket */
          DoIP_VCloseSoCon(connection);
        }
      }
      DoIP_VTcpCon2InactivCnt[connection]++;
    }
  }
}
/* PRQA L:MSR_STPTH */
/* PRQA L:MSR_STCYC */
/* PRQA L:MSR_STMIF */

#define DOIP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* module specific MISRA deviations:
  MD_DoIP_3.1:
      Reason:     Signed unsigned mismatch for data type independence
      Risk:       Misinterpretation of data.
      Prevention: Covered by code review.
  MD_DoIP_5.1:
      Reason:     Identifier does not differ from other identifiers within 31 significant characters.
      Risk:       There is no risk as such statements have no effect on the code.
      Prevention: Covered by code review.
  MD_DoIP_11.1:
      Reason:     Casting to different function pointer type
      Risk:       Misinterpretation of data.
      Prevention: Covered by code review.
  MD_DoIP_11.4:
      Reason:     Casting to different object pointer type
      Risk:       Misinterpretation of data.
      Prevention: Covered by code review.
  MD_DoIP_13.7_TOOL:
      Reason:     Expression is always 'true' or 'false' misinterpreted by test tool
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_DoIP_14.6:
      Reason:     Multiple break statements due to runtime optimization.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_DoIP_16.7:
      Reason:     No pointer to const due to modification in a called function or required by specification.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_DoIP_21.1_INV:
      Reason:     Used to get an invalid value depending on data type or to get the inverse value.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_DoIP_21.1_CFG:
      Reason:     Error does not apply since prevention is given in configuration.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_DoIP_21.1_IDX:
      Reason:     Indexing out of bounds prevented by complex mechanism (misinterpreted by test tool).
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_DoIP_0686:
      Reason:     All not initialized elements are overwritten later.
      Risk:       Uninitialized elements may remain.
      Prevention: Covered by code review.
  MD_DoIP_3199:
      Reason:     Symbol is part of struct overlaying a byte array (misinterpreted by test tool).
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_DoIP_3206:
      Reason:     API parameter is only used in some configurations or is required by specification but currently not
                  supported.
      Risk:       No risk.
      Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: DoIP.c
 *********************************************************************************************************************/
