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
 *         \file  EthTSyn_Priv.h
 *        \brief  EthTSyn private header file
 *
 *      \details  Contains private definitions and declarations used by EthTSyn only
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

#if !defined(ETHTSYN_PRIV_H)
# define ETHTSYN_PRIV_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "EthTSyn.h"
# include "EthTSyn_CfgAccess_Int.h"
# include "EthTSyn_Crc_Int.h"
# include "SchM_EthTSyn.h"
# include "StbM.h"

# if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif  /* ETHTSYN_DEV_ERROR_REPORT */

# include "IpBase.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (ETHTSYN_INLINE)
#  define ETHTSYN_INLINE static INLINE
# endif

/* PRQA L: FCT_MACRO */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ETHTSYN General */
# define ETHTSYN_PROTOCOL_VERSION                             (0x02U)

/* ETHTSYN Header Length */
# define ETHTSYN_HDR_COM_LENGTH                               (34U)
# define ETHTSYN_HDR_COM_RESERVED_1_LENGTH                    (4U)
# define ETHTSYN_HDR_COM_CORRECTION_FIELD_LENGTH              (8U)
# define ETHTSYN_HDR_COM_TRANSPORT_SPECIFIC                   (0x10U)
# define ETHTSYN_HDR_COM_CONTROL_SYNC                         (0x00U)
# define ETHTSYN_HDR_COM_CONTROL_FOLLOW_UP                    (0x02U)
# define ETHTSYN_HDR_COM_CONTROL_ANNOUNCE                     (0x05U)
# define ETHTSYN_HDR_COM_CONTROL_PDELAY_REQ                   (0x05U)
# define ETHTSYN_HDR_COM_CONTROL_PDELAY_RESP                  (0x05U)
# define ETHTSYN_HDR_COM_CONTROL_PDELAY_RESP_FOLLOW_UP        (0x05U)

# define ETHTSYN_HDR_COM_LOG_MESSAGE_INTERVAL_DEFAULT         (0x7FU)

/* ETHTSYN Header Flags */ 
# define ETHTSYN_FLAGS_TWO_STEP                               (0x0002U)
# define ETHTSYN_FLAGS_LEAP61                                 (0x0100U)
# define ETHTSYN_FLAGS_LEAP59                                 (0x0200U)
# define ETHTSYN_FLAGS_UTC_OFFSET_VALID                       (0x0400U)
# define ETHTSYN_FLAGS_ETHTSYN_TIMESCALE                      (0x0800U)
# define ETHTSYN_FLAGS_TIME_TRACEABLE                         (0x1000U)
# define ETHTSYN_FLAGS_FREQUENCY_TRACEABLE                    (0x2000U)

/* PRQA S 3453 8 */ /* MD_MSR_19.7 */
# define ETHTSYN_HDR_FLAGS_TWO_STEP(param)                    ((uint16)(param) & ETHTSYN_FLAGS_TWO_STEP)
# define ETHTSYN_HDR_FLAGS_LEAP61(param)                      ((uint16)(param) & ETHTSYN_FLAGS_LEAP61)
# define ETHTSYN_HDR_FLAGS_LEAP59(param)                      ((uint16)(param) & ETHTSYN_FLAGS_LEAP59)
# define ETHTSYN_HDR_FLAGS_ETHTSYN_TIMESCALE(param)           ((uint16)(param) & ETHTSYN_FLAGS_ETHTSYN_TIMESCALE)
# define ETHTSYN_HDR_FLAGS_UTC_OFFSET_VALID(param)            ((uint16)(param) & ETHTSYN_FLAGS_UTC_OFFSET_VALID)
# define ETHTSYN_HDR_FLAGS_TIME_TRACEABLE(param)              ((uint16)(param) & ETHTSYN_FLAGS_TIME_TRACEABLE)
# define ETHTSYN_HDR_FLAGS_FREQUENCY_TRACEABLE(param)         ((uint16)(param) & ETHTSYN_FLAGS_FREQUENCY_TRACEABLE)

/* PRQA S 3453 4 */ /* MD_MSR_19.7 */
# define ETHTSYN_HDR_COM_MSG_TYPE(param)                      ((uint8)(param) & 0x0F)
# define ETHTSYN_HDR_COM_VERSION(param)                       ((uint8)(param) & 0x0F)

/* Message Pdelay values */
# define ETHTSYN_MSG_P_DELAY_PAYLOAD_LENGTH                   (20U)

/* Message PdelayReq values */
# define ETHTSYN_MSG_P_DELAY_REQ_LENGTH                       (ETHTSYN_MSG_P_DELAY_PAYLOAD_LENGTH \
                                                              + ETHTSYN_HDR_COM_LENGTH)
# define ETHTSYN_MSG_P_DELAY_REQ_RESERVED_0_LENGTH            (10U)
# define ETHTSYN_MSG_P_DELAY_REQ_RESERVED_1_LENGTH            (10U)

/* Message PdelayResp values */
# define ETHTSYN_MSG_P_DELAY_RESP_LENGTH                      (ETHTSYN_MSG_P_DELAY_PAYLOAD_LENGTH \
                                                              + ETHTSYN_HDR_COM_LENGTH)

/* Message PdelayRespFollowUp values */
# define ETHTSYN_MSG_P_DELAY_RESP_FOLLOW_UP_LENGTH            (ETHTSYN_MSG_P_DELAY_PAYLOAD_LENGTH \
                                                              + ETHTSYN_HDR_COM_LENGTH)

/* Message FollowUp values */
/* FollowUp message lengths -> EthTSyn_Cfg.h */
/* Precise Origin Timestamp length (10) + complete FollowUp IEEE Tlv length (32) */
# define ETHTSYN_FOLLOW_UP_AR_TLV_OFFSET                             (42u)
# define ETHTSYN_FOLLOW_UP_TLV_TYPE                                  (0x03U)
# define ETHTSYN_FOLLOW_UP_TLV_LENGTH_FIELD                          (28U)
# define ETHTSYN_FOLLOW_UP_ORGANISATION_ID                           (0x000080C2UL)
# define ETHTSYN_FOLLOW_UP_ORGANISATION_SUBTYPE                      (0x00000001UL)
# define ETHTSYN_MSG_FOLLOW_UP_PRECISE_ORIGIN_TS_SECONDS_LENGTH      (6U)
# define ETHTSYN_MSG_FOLLOW_UP_PRECISE_ORIGIN_TS_NANOSECONDS_LENGTH  (4U)
# define ETHTSYN_MSG_FOLLOW_UP_ORGANISATION_ID_LENGTH                (3U)
# define ETHTSYN_MSG_FOLLOW_UP_ORGANISATION_SUB_TYPE_LENGTH          (3U)
# define ETHTSYN_MSG_FOLLOW_UP_LAST_GM_PHASE_CHANGE_LENGTH           (12U)
# define ETHTSYN_MSG_FOLLOW_UP_SCALED_LAST_GM_FREQ_CHANGE_LENGTH     (4U)
# define ETHTSYN_MSG_FOLLOW_UP_CORRECTION_FIELD_MULTIPLIER           (65536U)
# define ETHTSYN_MSG_FOLLOW_UP_CORRECTION_FIELD_SHIFT                (16U)
# define ETHTSYN_MSG_FOLLOW_UP_CORRECTION_FIELD_LENGTH               (8U)

/* PRQA S 3453 2 */ /* MD_MSR_19.7 */
# define ETHTSYN_MSG_FOLLOW_UP_CORRECTION_FIELD_TO_NS(CorrectionField)  ((uint64)((CorrectionField) >> 16U))
# define ETHTSYN_MSG_FOLLOW_UP_NS_TO_CORRECTION_FIELD(Nanoseconds)      ((uint64)((Nanoseconds) << 16U))

/* Message Sync values */
# define ETHTSYN_MSG_SYNC_PAYLOAD_LENGTH                      (10U)
# define ETHTSYN_MSG_SYNC_LENGTH                              (ETHTSYN_MSG_SYNC_PAYLOAD_LENGTH \
                                                              + ETHTSYN_HDR_COM_LENGTH)
# define ETHTSYN_MSG_SYNC_RESERVED_LENGTH                     (10U)

/* ETHTSYN Announce values */
# define ETHTSYN_MSG_ANNOUNCE_PAYLOAD_LENGTH                  (42U)
# define ETHTSYN_MSG_ANNOUNCE_LENGTH                          (ETHTSYN_MSG_ANNOUNCE_PAYLOAD_LENGTH \
                                                              + ETHTSYN_HDR_COM_LENGTH)
# define ETHTSYN_MSG_ANNOUNCE_PATH_SEQUENCE_ELEMENT_LENGTH    (8U)
# define ETHTSYN_ANNOUNCE_PRIORITY_1_NETWORK_INFRASTRUCTURE   (246U)
# define ETHTSYN_ANNOUNCE_PRIORITY_1_OTHER_SYSTEM             (248U)
# define ETHTSYN_ANNOUNCE_PRIORITY_1_NOT_GM_CAPABLE           (255U)

# define ETHTSYN_ANNOUNCE_PRIORITY_2_DEFAULT                  (248U)
# define ETHTSYN_ANNOUNCE_CLOCK_CLASS_UNKNOWN                 (248U)
# define ETHTSYN_ANNOUNCE_CLOCK_CLASS_NOT_GM_CAPABLE          (255U)
# define ETHTSYN_ANNOUNCE_CLOCK_ACCURACY_UNKNOWN              (254U)
# define ETHTSYN_ANNOUNCE_OFFSET_SCALED_LOG_UNKNOWN           (0x4100U)
# define ETHTSYN_ANNOUNCE_TIME_SOURCE_INTERNAL_OSCILLATOR     (0xA0U)
# define ETHTSYN_ANNOUNCE_TLV_TYPE                            (0x08U)
# define ETHTSYN_ANNOUNCE_TLV_LENGTH_FIELD                    (0x08U)

/* ETHTSYN Message Types */
# define ETHTSYN_MSG_TYPE_ANNOUNCE                            (0x0BU)
# define ETHTSYN_MSG_TYPE_SIGNALING                           (0x0CU)
# define ETHTSYN_MSG_TYPE_SYNC                                (0x00U)
# define ETHTSYN_MSG_TYPE_PDELAY_REQ                          (0x02U)
# define ETHTSYN_MSG_TYPE_PDELAY_RESP                         (0x03U)
# define ETHTSYN_MSG_TYPE_FOLLOW_UP                           (0x08U)
# define ETHTSYN_MSG_TYPE_PDELAY_RES_FOLLOW_UP                (0x0AU)
# define ETHTSYN_MSG_TYPE_INVALID                             (0xFFU)

/* TimeBaseStatus Masks */
# define ETHTSYN_TIME_BASE_STATUS_TIMEOUT_MASK                (0x01u)
# define ETHTSYN_TIME_BASE_STATUS_SYNC_TO_GW_MASK             (0x04u)
# define ETHTSYN_TIME_BASE_STATUS_SYNC_TO_GW_SHIFT            (2u)
# define ETHTSYN_TIME_BASE_STATUS_GLOBAL_TIME_BASE_MASK       (0x08u)
# define ETHTSYN_TIME_BASE_STATUS_TIMELEAP_FUTURE_MASK        (0x10u)
# define ETHTSYN_TIME_BASE_STATUS_TIMELEAP_PAST_MASK          (0x20u)

/* ETHTSYN Ar (Sub)-Tlv values */
# define ETHTSYN_AR_SUB_TLV_OFS_TIME_SEC_SECONDS_OFFSET       (2u)

# define ETHTSYN_UINT16_MAX_VALUE                             (65535U)

/* ----- Inline function availability ----- */

/* -- EthTSyn_CheckMessageGeneral() -- */
# if (                                                                               \
       (defined(ETHTSYN_SWTMGMT_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) ) || \
       (defined(ETHTSYN_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)        )    \
     )
#  define ETHTSYN_INLINE_API_CHECK_MESSAGE_GENERAL_ENABLED  STD_ON
# else
#  define ETHTSYN_INLINE_API_CHECK_MESSAGE_GENERAL_ENABLED  STD_OFF
# endif /* EthTSyn_CheckMessageGeneral() availability check */

/* -- EthTSyn_CheckMessageTypeAndLength() -- */
# if (                                                                               \
       (defined(ETHTSYN_SWTMGMT_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) ) || \
       (defined(ETHTSYN_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)        )    \
     )
#  define ETHTSYN_INLINE_API_CHECK_MESSAGE_TYPE_AND_LENGTH_ENABLED  STD_ON
# else
#  define ETHTSYN_INLINE_API_CHECK_MESSAGE_TYPE_AND_LENGTH_ENABLED  STD_OFF
# endif /* EthTSyn_CheckMessageTypeAndLength() availability check */

/* -- EthTSyn_PortIdentityIsEqual() -- */
# if (                                                                               \
       (defined(ETHTSYN_SWTMGMT_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) ) || \
       (defined(ETHTSYN_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)        )    \
     )
#  define ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_ENABLED  STD_ON
# else
#  define ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_ENABLED  STD_OFF
# endif /* EthTSyn_PortIdentityIsEqual() availability check */

/* -- EthTSyn_PortIdentityIsEqualLocalPort() -- */
# if (                                                                               \
       (defined(ETHTSYN_SWTMGMT_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) ) || \
       (defined(ETHTSYN_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)        )    \
     )
#  define ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_LOCAL_PORT_ENABLED  STD_ON
# else
#  define ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_LOCAL_PORT_ENABLED  STD_OFF
# endif /* EthTSyn_PortIdentityIsEqualLocalPort() availability check */

/* -- EthTSyn_SetAsCapable() -- */
# if (                                                                                 \
       (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)                                       && \
       (                                                                               \
         (defined(ETHTSYN_SWTMGMT_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) ) || \
         (defined(ETHTSYN_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)        )    \
       )                                                                               \
     )
#  define ETHTSYN_INLINE_API_SET_AS_CAPABLE_ENABLED  STD_ON
# else
#  define ETHTSYN_INLINE_API_SET_AS_CAPABLE_ENABLED  STD_OFF
# endif /* EthTSyn_SetAsCapable() availability check */

/* -- EthTSyn_GetFrameId() -- */
# if (                                                                                 \
       ((ETHTSYN_FRAME_ID_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) ) \
     )
#  define ETHTSYN_INLINE_API_GET_FRAME_ID_ENABLED  STD_ON
# else
#  define ETHTSYN_INLINE_API_GET_FRAME_ID_ENABLED  STD_OFF
# endif /* EthTSyn_GetFrameId() availability check */

/* -- EthTSyn_SetMasterPriorityVector() -- */
# if (                                                                                  \
        (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)                                      && \
        (                                                                               \
          (defined(ETHTSYN_SWTMGMT_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) ) || \
          (defined(ETHTSYN_SOURCE) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)        )    \
        )                                                                               \
     )
#  define ETHTSYN_INLINE_API_SET_MASTER_PRIO_VECTOR_ENABLED STD_ON
# else
#  define ETHTSYN_INLINE_API_SET_MASTER_PRIO_VECTOR_ENABLED STD_OFF
# endif /* EthTSyn_SetMasterPriorityVector() availability check */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#if ( (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) && (ETHTSYN_WRAP_ETH_IF_TIME_APIS == STD_ON) )
/* PRQA S 3453 5 */ /* MD_MSR_19.7 */
/* Macros required to adopt AR4.3 EthIf APIs to the EthIf APIs of the Vector EthIf */
# define EthIf_GetEgressTimeStamp(CtrlIdx, BufIdx, TimeQualPtr, TimeStampPtr) \
  (EthIf_GetEgressTimestamp((CtrlIdx), (BufIdx), (TimeStampPtr), (TimeQualPtr)))
# define EthIf_GetIngressTimeStamp(CtrlIdx, DataPtr, TimeQualPtr, TimeStampPtr) \
  (EthIf_GetIngressTimestamp((CtrlIdx), (DataPtr), (TimeStampPtr), (TimeQualPtr)))
#endif /* ( (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) && (ETHTSYN_WRAP_ETH_IF_TIME_APIS == STD_ON) ) */

# ifndef CANOE_WRITE_STRING
#  define CANOE_WRITE_STRING(Txt)
# endif
# ifndef CANOE_WRITE_STRING_1
#  define CANOE_WRITE_STRING_1(Txt, P1)
# endif
# ifndef CANOE_WRITE_STRING_2
#  define CANOE_WRITE_STRING_2(Txt, P1, P2)
# endif
# ifndef CANOE_WRITE_STRING_3
#  define CANOE_WRITE_STRING_3(Txt, P1, P2, P3)
# endif
# ifndef CANOE_WRITE_STRING_4
#  define CANOE_WRITE_STRING_4(Txt, P1, P2, P3, P4)
# endif

/* PRQA S 3412 MACRO_CODE */ /* MD_MSR_19.4 */
/* PRQA S 3453 FCT_MACRO */ /* MD_MSR_19.7 */
# define EthTSyn_Htons(HostShort16)                       IPBASE_HTON16(HostShort16)
# define EthTSyn_Htonl(HostLong32)                        IPBASE_HTON32(HostLong32)
# define EthTSyn_Ntohs(NetworkShort16)                    IPBASE_HTON16(NetworkShort16)
# define EthTSyn_Ntohl(NetworkLong32)                     IPBASE_HTON32(NetworkLong32)

# define ETHTSYN_PUT_UINT8(Buffer, Offset, Value)        ( (Buffer)[(Offset)] = (uint8)(Value))

# define ETHTSYN_PUT_UINT16(Buffer, Offset, Value)    (Buffer)[(Offset)+0] = (uint8)(((uint16_least)(Value)) >> 8); \
                                                      (Buffer)[(Offset)+1] = (uint8)((uint16_least)(Value));

# define ETHTSYN_PUT_UINT32(Buffer, Offset, Value)    (Buffer)[(Offset)+0] = (uint8)(((uint32_least)(Value)) >> 24); \
                                                      (Buffer)[(Offset)+1] = (uint8)(((uint32_least)(Value)) >> 16); \
                                                      (Buffer)[(Offset)+2] = (uint8)(((uint32_least)(Value)) >>  8); \
                                                      (Buffer)[(Offset)+3] = (uint8)((uint32_least)(Value));

# define ETHTSYN_PUT_3_BYTE(Buffer, Offset, Value)  (Buffer)[(Offset)+0u] = (uint8)(((uint32_least)(Value)) >> 16u); \
                                                    (Buffer)[(Offset)+1u] = (uint8)(((uint32_least)(Value)) >> 8u); \
                                                    (Buffer)[(Offset)+2u] = (uint8)((uint32_least)(Value));

# define ETHTSYN_GET_UINT8(Buffer, Offset, Variable)      IPBASE_GET_UINT8((Buffer), (Offset), (Variable))
# define ETHTSYN_GET_UINT16(Buffer, Offset, Variable)     IPBASE_GET_UINT16((Buffer), (Offset), (Variable))
# define ETHTSYN_GET_UINT32(Buffer, Offset, Variable)     IPBASE_GET_UINT32((Buffer), (Offset), (Variable))
# define ETHTSYN_GET_3_BYTE(Buffer, Offset, Variable)  ( (Variable) = (uint32)(((uint32)(0x00u) << 24u) | \
                                                                           ((uint32)((Buffer)[(Offset)+0u]) << 16u) | \
                                                                           ((uint32)((Buffer)[(Offset)+1u]) <<  8u) | \
                                                                           ((uint32)((Buffer)[(Offset)+2u]))) )

# define ETHTSYN_GET_FOLLOW_UP_CORRECTION_VALUE_NS_FROM_MSG(CorrectionFieldNbo)  ( (uint64)( \
  ((uint64)(CorrectionFieldNbo)[0] << 40U) | \
  ((uint64)(CorrectionFieldNbo)[1] << 32U) | \
  ((uint64)(CorrectionFieldNbo)[2] << 24U) | \
  ((uint64)(CorrectionFieldNbo)[3] << 16U) | \
  ((uint64)(CorrectionFieldNbo)[4] <<  8U) | \
  ((uint64)(CorrectionFieldNbo)[5] <<  0U)) )

# define EthTSyn_CopyFollowUpCorrectionField(FollowUpCorrectionValueNs, FollowUpCorrectionField)  \
  (FollowUpCorrectionField)[0] = (uint8)((FollowUpCorrectionValueNs) >> 40U); \
  (FollowUpCorrectionField)[1] = (uint8)((FollowUpCorrectionValueNs) >> 32U); \
  (FollowUpCorrectionField)[2] = (uint8)((FollowUpCorrectionValueNs) >> 24U); \
  (FollowUpCorrectionField)[3] = (uint8)((FollowUpCorrectionValueNs) >> 16U); \
  (FollowUpCorrectionField)[4] = (uint8)((FollowUpCorrectionValueNs) >>  8U); \
  (FollowUpCorrectionField)[5] = (uint8)((FollowUpCorrectionValueNs) >>  0U); \
  (FollowUpCorrectionField)[6] = 0; \
  (FollowUpCorrectionField)[7] = 0;

# define ETHTSYN_COPY_STBM_TS_TO_GLOBAL_TS(StbmTimestamp, GlobalTimestamp) \
  (GlobalTimestamp).secondsHi   = (StbmTimestamp).secondsHi; \
  (GlobalTimestamp).seconds     = (StbmTimestamp).seconds;   \
  (GlobalTimestamp).nanoseconds = (StbmTimestamp).nanoseconds;

# define ETHTSYN_COPY_GLOBAL_TS_TO_STBM_TS_WO_TBS(GlobalTimestamp, StbmTimestamp) \
  (StbmTimestamp).timeBaseStatus = (0u); \
  (StbmTimestamp).secondsHi      = (GlobalTimestamp).secondsHi; \
  (StbmTimestamp).seconds        = (GlobalTimestamp).seconds;   \
  (StbmTimestamp).nanoseconds    = (GlobalTimestamp).nanoseconds;

# define ETHTSYN_COPY_GLOBAL_TS_TO_STBM_TS_W_TBS(GlobalTimestamp, StbmTimestamp, TimeBaseStatus) \
  (StbmTimestamp).timeBaseStatus = (TimeBaseStatus); \
  (StbmTimestamp).secondsHi      = (GlobalTimestamp).secondsHi; \
  (StbmTimestamp).seconds        = (GlobalTimestamp).seconds;   \
  (StbmTimestamp).nanoseconds    = (GlobalTimestamp).nanoseconds;

# define ETHTSYN_TIME_BASE_STATUS_TO_AR_SUB_TLV_STATUS(StbmTimeBaseStatus, ArSubTlvStatus) \
  ((ArSubTlvStatus) = (uint8) \
  (((StbmTimeBaseStatus) & ETHTSYN_TIME_BASE_STATUS_SYNC_TO_GW_MASK) >> ETHTSYN_TIME_BASE_STATUS_SYNC_TO_GW_SHIFT))

# define ETHTSYN_AR_SUB_TLV_STATUS_TO_TIME_BASE_STATUS(ArSubTlvStatus, StbmTimeBaseStatus) \
  ((StbmTimeBaseStatus) = (uint8) \
  (((ArSubTlvStatus) << ETHTSYN_TIME_BASE_STATUS_SYNC_TO_GW_SHIFT) & ETHTSYN_TIME_BASE_STATUS_SYNC_TO_GW_MASK))

# ifndef ETHTSYN_ENTER_CRITICAL_SECTION_0
#  define ETHTSYN_ENTER_CRITICAL_SECTION_0()   SchM_Enter_EthTSyn_ETHTSYN_EXCLUSIVE_AREA_0()
# endif /* ETHTSYN_ENTER_CRITICAL_SECTION_0 */
# ifndef ETHTSYN_LEAVE_CRITICAL_SECTION_0
#  define ETHTSYN_LEAVE_CRITICAL_SECTION_0()   SchM_Exit_EthTSyn_ETHTSYN_EXCLUSIVE_AREA_0()
# endif /* ETHTSYN_LEAVE_CRITICAL_SECTION_0 */
# ifndef ETHTSYN_CHECK_CRITICAL_SECTION_0
/* Macro provided by TestApp used to check if a Critical section is opened (e.g. when calling a foreign module) */
#  define ETHTSYN_CHECK_CRITICAL_SECTION_0()
# endif /* ETHTSYN_CHECK_CRITICAL_SECTION_0 */

# ifndef ETHTSYN_CALL_DET_REPORT_RUNTIME_ERROR
#  define ETHTSYN_CALL_DET_REPORT_RUNTIME_ERROR()
# endif /* ETHTSYN_CALL_DET_REPORT_RUNTIME_ERROR */

/* State Machine access Macros */
# define ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)    (ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR((PortIdx))->PdelayReqSmPtr)
# define ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx)   (ETHTSYN_CFG_GET_P_DELAY_RESPONDER_CFG_PTR((PortIdx))->PdelayRespSmPtr)

# define ETHTSYN_SYNC_RECEIVE_SM_PTR(SlavePortIdx) ((((ETHTSYN_P2CONSTCFG(EthTSyn_SlavePortConfigType)) \
    EthTSyn_PortConfig[(SlavePortIdx)].PortRolePtr)->SyncReceiveSmPtr))
# define ETHTSYN_ANNOUNCE_RECEIVE_SM_PTR(PortIdx)     (EthTSyn_SlavePortConfigPtr((PortIdx))->AnnounceReceiveSmPtr)
# define ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)            (EthTSyn_MasterPortConfigPtr((PortIdx))->SyncSendSmPtr)

/* ----- "State" access Macros ----- */
/* TimeDomain */
# define ETHTSYN_STATE_GET_SLAVE_PORT_IDX(TimeDomainIdx) (EthTSyn_TimeDomainState[(TimeDomainIdx)].SlavePortIdx)

/* Port */
# define ETHTSYN_STATE_GET_LINK_STATE(PortIdx) \
  (EthTSyn_CtrlState[ETHTSYN_CFG_GET_ETHTSYN_CTRL_IDX((PortIdx))].TrcvLinkState)
# define ETHTSYN_STATE_GET_TX_MODE(PortIdx) \
  (EthTSyn_CtrlState[ETHTSYN_CFG_GET_ETHTSYN_CTRL_IDX((PortIdx))].TransmissionMode)

/* Controller */
# define ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx) \
  (EthTSyn_CtrlState[ETHTSYN_CFG_GET_ETHTSYN_CTRL_IDX((PortIdx))].ClockIdentity)

/* Pdelay */
# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
#  define ETHTSYN_GET_AS_CAPABLE(PortIdx)              (EthTSyn_GetAsCapable((PortIdx)))
#  define ETHTSYN_SET_AS_CAPABLE(PortIdx, AsCapable)   (EthTSyn_SetAsCapable((PortIdx), (AsCapable)))
# else
#  define ETHTSYN_GET_AS_CAPABLE(PortIdx)              (TRUE)
#  define ETHTSYN_SET_AS_CAPABLE(PortIdx, AsCapable)
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */

/* PRQA L: MACRO_CODE */
/* PRQA L: FCT_MACRO */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define ETHTSYN_START_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

extern VAR(EthTSyn_StateType, ETHTSYN_VAR_ZERO_INIT) EthTSyn_State;

# define ETHTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

# define ETHTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

extern VAR(EthTSyn_SystemType, ETHTSYN_VAR_NOINIT) EthTSyn_SystemState[ETHTSYN_TIME_DOMAIN_COUNT];

# define ETHTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define ETHTSYN_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  EthTSyn_CheckAnnounce
 *********************************************************************************************************************/
/*! \brief      Checks if the Source-Port-Identity of the given Sync/FollowUp message (ComMsgPtr) is equal to the one
 *              received with a former announce message (stored in SystemState)
 *  \param[in]  ComMsgPtr      Pointer to the Common Message Header of the message the check should be performed for
 *  \param[in]  TimeDomainIdx  Index of the TimeDomain
 *  \return     TRUE:  Receive message
 *              FALSE: Discard message
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
FUNC(boolean, ETHTSYN_CODE) EthTSyn_CheckAnnounce(
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr,
                  EthTSyn_TimeDomainIdxType TimeDomainIdx);
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CheckSourcePortIdentity
 *********************************************************************************************************************/
/*! \brief      Checks if the  Source-Port-Identity of the given Sync/FollowUp message (ComMsgPtr) is equal to the one
 *              configured for the given port
 *  \param[in]  ComMsgPtr    Pointer to the Common Message Header of the message the check should be performed for
 *  \param[in]  SlavePortIdx Index of the Slave-Port the message was received on
 *  \return     TRUE:  Receive message
 *              FALSE: Discard message
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON)
FUNC(boolean, ETHTSYN_CODE) EthTSyn_CheckSourcePortIdentity(
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr,
                  EthTSyn_PortIdxType       SlavePortIdx);
# endif /* (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_TxPdelayReqMsg
 *********************************************************************************************************************/
/*! \brief      Transmits a Pdelay Request message
 *  \param[in]  PortIdx         Index of the port that should transmit the message
 *  \return     E_OK            Message transmission was successful\n
 *              E_NOT_OK        Message transmission was not successful\n
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxPdelayReqMsg(
  EthTSyn_PortIdxType PortIdx);
# endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_TxPdelayRespMsg
 *********************************************************************************************************************/
/*! \brief      Transmits a PdelayResp message
 *  \param[in]  PortIdx         Index of the port that should transmit the message
 *  \return     E_OK            Message transmission was successful
 *              E_NOT_OK        Message transmission was not successful
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxPdelayRespMsg(
  EthTSyn_PortIdxType PortIdx);
# endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_Transmit
 *********************************************************************************************************************/
/*! \brief      Transmits a EthTSyn frame on the given Port
 *  \param[in]  PortIdx           Index of the port that is used for transmission
 *  \param[in]  BufIdx            Index of the transmit buffer that holds the data
 *  \param[in]  LenByte           Byte count of the data that should be transmitted
 *  \param[in]  TxConfirmation    Determines if Tx confirmation is needed
 *  \param[in]  MgmtInfoPointer   Pointer to the Switch management info. NULL_PTR for non Switch-Ports
 *  \return     E_OK              Message transmission was successful
 *              E_NOT_OK          Message transmission was not successful
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_Transmit(
                  EthTSyn_PortIdxType  PortIdx,
                  uint8                BufIdx,
                  uint16               LenByte,
                  boolean              TxConfirmation,
  ETHTSYN_P2CONST(EthSwt_MgmtInfoType) MgmtInfoPtr);
# else
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_Transmit(
  EthTSyn_PortIdxType PortIdx,
  uint8               BufIdx,
  uint16              LenByte,
  boolean             TxConfirmation);
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_GetCurrentPdelay
 *********************************************************************************************************************/
/*! \brief      Checks if Pdelay is used for the given port and returns its current value
 *  \param[in]  PortIdx    Index of the port the Pdelay is requested for
 *  \param[out] PdelayPtr  Pointer to where to store the current Pdelay
 *  \return     E_OK:     Successfully retrieved the current Pdelay
 *              E_NOT_OK: Failed to retrieve the current Pdelay (e.g. invalid PortIdx)
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetCurrentPdelay(
                EthTSyn_PortIdxType PortIdx,
  ETHTSYN_P2VAR(EthTSyn_PdelayType) PdelayPtr);

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmPdelayResp
 *********************************************************************************************************************/
/*! \brief      Handles the processing of the given Path Delay Response state-machine
 *  \param[in]  PortIdx    Index of the Port the state machine should be processed for
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmPdelayResp(
  EthTSyn_PortIdxType PortIdx);
# endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmSyncReceive
 *********************************************************************************************************************/
/*! \brief      Handles the processing of the Sync Receive state-machine for the given TimeDomain
 *  \param[in]  PortIdx    Index of the Port which state-machine should be processed
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmSyncReceive(
  EthTSyn_PortIdxType PortIdx);

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmPdelayReq
 *********************************************************************************************************************/
/*! \brief      Handles the processing of the Path Delay Request state-machine for the given Port
 *  \param[in]  PortIdx     Index of the Port which state-machine should be processed
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmPdelayReq(
  EthTSyn_PortIdxType PortIdx);

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmSyncSend
 *********************************************************************************************************************/
/*! \brief      Handles the processing of the Sync Send state-machine for the given Port
 *  \param[in]  PortIdx    Index of the Port that state-machine should be processed
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmSyncSend(
  EthTSyn_PortIdxType PortIdx);

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmAnnounceReceive
 *********************************************************************************************************************/
/*! \brief      Processing of the Announce receive state-machine for the given Port
 *  \param[in]  PortIdx    Index of the port that should be processed
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmAnnounceReceive(
  EthTSyn_PortIdxType PortIdx);
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_EndStation_ProcessReceivedSync
 *********************************************************************************************************************/
/*! \brief      Processing of a received Sync message on an End-Station port
 *  \param[in]  PortIdx          Index of the port the message was received on
 *  \param[in]  ComMsgHdrPtr     Pointer to the common PTP message header
 *  \param[in]  RxFrameInfoPtr   Pointer to the Rx info of the received message
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_END_STATION_SUPPORT == STD_ON) )
FUNC(void, ETHTSYN_CODE) EthTSyn_EndStation_ProcessReceivedSync(
                  EthTSyn_PortIdxType              PortIdx,
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType)        ComMsgHdrPtr,
  ETHTSYN_P2CONST(EthTSyn_SwtMgmt_RxFrameInfoType) RxFrameInfoPtr);
# endif /* ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_END_STATION_SUPPORT == STD_ON) ) */

/**********************************************************************************************************************
 *  EthTSyn_EndStation_ProcessReceivedFollowUp
 *********************************************************************************************************************/
/*! \brief      Processing of a received FollowUp message on an End-Station port
 *  \param[in]  PortIdx          Index of the port the message was received on
 *  \param[in]  ComMsgHdrPtr     Pointer to the common PTP message header
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_END_STATION_SUPPORT == STD_ON) )
FUNC(void, ETHTSYN_CODE) EthTSyn_EndStation_ProcessReceivedFollowUp(
                  EthTSyn_PortIdxType              PortIdx,
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType)        ComMsgHdrPtr); /* PRQA S 0777 */ /* MD_MSR_5.1_777 */
# endif /* ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_END_STATION_SUPPORT == STD_ON) ) */

/**********************************************************************************************************************
 *  GLOBAL INLINE FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EthTSyn_SetClockIdentity
 *********************************************************************************************************************/
/*! \brief       Sets a clock identity to the given value
 *  \param[out]  TargetPtr    Pointer to the clock identity that should be set
 *  \param[in]   SourcePtr    Pointer to the clock identity that should be used as source value
 *  \return      none
 *  \context     This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SetClockIdentity(
        EthTSyn_ClockIdentityType                 TargetPtr,
  CONST(EthTSyn_ClockIdentityType, ETHTSYN_CONST) SourcePtr );

/**********************************************************************************************************************
 *  EthTSyn_SetMasterPriorityVector
 *********************************************************************************************************************/
/*! \brief      Sets the EthTSyn system state of the master priority vector for the given TimeDomain
 *  \param[in]  AnnounceMsgPtr    Pointer to the Announce message where the master priority vector is stored
 *  \param[in]  TimeDomainIdx     Index of the TimeDomain the master priority should be set for
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_INLINE_API_SET_MASTER_PRIO_VECTOR_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SetMasterPriorityVector(
  ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType)  AnnounceMsgPtr,
                  EthTSyn_TimeDomainIdxType TimeDomainIdx);
# endif /* (ETHTSYN_INLINE_API_SET_MASTER_PRIO_VECTOR_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CompareClockIdentity
 *********************************************************************************************************************/
/*! \brief      Compares the value of the given clock identities.
 *  \param[in]  Value                      Clock identity that should be compared.
 *  \param[in]  Reference                  Reference Clock identity that is used for comparison.
 *  \return     ETHTSYN_COMPARE_LESS       Value clock identity is less than Reference clock identity\n
 *              ETHTSYN_COMPARE_EQUAL      Clock identities are equal\n
 *              ETHTSYN_COMPARE_GREATER    Value clock identity is greater that Reference clock identity\n
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(EthTSyn_CompareType, ETHTSYN_CODE) EthTSyn_CompareClockIdentity(
  ETHTSYN_P2CONST(EthTSyn_ClockIdentityPtrType) Value,
  ETHTSYN_P2CONST(EthTSyn_ClockIdentityPtrType) Reference);

/**********************************************************************************************************************
 *  EthTSyn_NtohTimestamp
 *********************************************************************************************************************/
/*! \brief       Converts an received Timestamp from Network-Byte-Order to Host-Byte-Order and into the locally used \
                 TimestampType
 *  \param[out]  LocalTimestampPtr     Pointer to the local timestamp value in Host-Byte-Order (destination)
 *  \param[in]   GlobalTimestampPtr    Pointer to the EthTSyn timestamp value in Network-Byte-Order (source)
 *  \return      none
 *  \context     This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_NtohTimestamp(
    ETHTSYN_P2VAR(EthTSyn_GlobalTimestampType) LocalTimestampPtr,
  ETHTSYN_P2CONST(EthTSyn_TimestampType)       GlobalTimestampPtr );

/**********************************************************************************************************************
 *  EthTSyn_GetPortType
 *********************************************************************************************************************/
/*! \brief      Get the Port type of the given Port
 *  \param[in]  PortIdx:      Index of the Port
 *  \return     ETHTSYN_PORT_TYPE_END_STATION_PORT:     End-Station Port
 *              ETHTSYN_PORT_TYPE_SWITCH_PORT:          Switch-Port
 *              ETHTSYN_PORT_TYPE_SWITCH_HOST_PORT:     Host-Port of the Switch
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
ETHTSYN_INLINE FUNC(EthTSyn_PortTypeType, ETHTSYN_CODE) EthTSyn_GetPortType(
  EthTSyn_PortIdxType PortIdx);
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CheckMessageGeneral
 *********************************************************************************************************************/
/*! \brief      Perform general message checks
 *  \param[in]  MsgPtr           Pointer to the message to be checked
 *  \param[in]  LenByte          Length of the message in Byte
 *  \param[out] TimeDomainIdxPtr The TimeDomainIdx matching the Domain Number of the message will be stored here
 *  \param[out] ErrorIdPtr       If the a general message check fails, the corresponding errorId will be stored here
 *  \return     E_OK:     Passed message check
 *              E_NOT_OK: Message check failed
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_INLINE_API_CHECK_MESSAGE_GENERAL_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_CheckMessageGeneral(
    ETHTSYN_P2CONST(uint8)                     MsgPtr,
                    uint16                     LenByte,
      ETHTSYN_P2VAR(EthTSyn_TimeDomainIdxType) TimeDomainIdxPtr,
      ETHTSYN_P2VAR(uint8)                     ErrorIdPtr);
# endif /* (ETHTSYN_INLINE_API_CHECK_MESSAGE_GENERAL_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CheckMessageLength
 *********************************************************************************************************************/
/*! \brief      Checks if the frame length and the message length of the common message header matches the message type
 *              Checks if the message type is valid and if the frame length and message length of the common header
 *              matches the message type
 *  \param[in]  ComMsgHdrPtr    Pointer to the common message header to be checked
 *  \param[in]  LenByte         Length of the message in Byte
 *  \param[out] ErrorIdPtr      If the a message check fails, the corresponding errorId will be stored here
 *  \return     E_OK:     Passed message check
 *              E_NOT_OK: Message check failed
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_INLINE_API_CHECK_MESSAGE_TYPE_AND_LENGTH_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_CheckMessageTypeAndLength(
    ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgHdrPtr,
                    uint16                    LenByte,
      ETHTSYN_P2VAR(uint8) ErrorIdPtr);
# endif /* (ETHTSYN_INLINE_API_CHECK_MESSAGE_TYPE_AND_LENGTH_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_GetFirstArSubTlvPtrAndCnt
 *********************************************************************************************************************/
/*! \brief      Gets the amount of Ar Sub-Tlvs and the Pointer to the first Sub-Tlv. Furthermore some general checks
 *              regarding the Ar (Sub-) Tlvs are performed (if applicable: check Crc as well)
 *  \param[in]  PortIdx            Index of the Port the message was received on
 *  \param[in]  ComMsgHdrPtr       Pointer to the common message header of the received FollowUp message
 *  \param[out] FirstSubTlvPtrPtr  Pointer to the first Ar Sub-Tlv of the message (NULL_PTR) if no Sub-Tlvs is found
 *  \param[out] SubTlvCnt          The number of found Ar Sub-Tlvs (will also be increased for unknown TLV Types)
 *  \return     E_OK:      Successfully retrieved the SubTlv Ptr and count. General checks passed\n
 *              E_NOT_OK:  Failed to retrieve the SubTlvPtr/count or general checks failed.
 *  \pre        This function is only available when EthTSynMessageCompliance is set to FALSE
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
ETHTSYN_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetFirstArSubTlvPtrAndCnt(
                                EthTSyn_PortIdxType                   PortIdx,
                ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType)             ComMsgHdrPtr,
  ETHTSYN_P2VAR(ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType))  FirstSubTlvPtrPtr,
                  ETHTSYN_P2VAR(uint8)                                SubTlvCnt);
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

/**********************************************************************************************************************
 *  EthTSyn_IsTimestampReadyToProcess
 *********************************************************************************************************************/
/*! \brief      Check if the Timestamp of the given Timestamp state is ready to be processed.
 *              Note: If Timestamp is actually available has to be checked separately (EthTSyn_IsTimestampAvailable)
 *  \param[in]  TimestampState:    State of the Timestamp to check
 *  \return     TRUE:   Timestamp is ready to be processed
 *              FALSE:  Timestamp is not ready to be processed
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_IsTimestampReadyToProcess(
  EthTSyn_TimestampStateType TimestampState);

/**********************************************************************************************************************
 *  EthTSyn_PortIdentityIsEqual
 *********************************************************************************************************************/
/*! \brief      Checks if the two given Port Identities are equal or not.
 *  \param[in]  PortIdentity1     Port Identity 1
 *  \param[in]  PortIdentity2Nbo  Port Identity 2 in Network byte order
 *  \return     TRUE              The Port Identities are equal\n
 *              FALSE             The Port Identities are not equal\n
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_PortIdentityIsEqual(
  ETHTSYN_CONSTP2CONST(EthTSyn_PortIdentityType) PortIdentity1,
  ETHTSYN_CONSTP2CONST(EthTSyn_PortIdentityType) PortIdentity2Nbo);
# endif /* (ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_PortIdentityIsEqualLocalPort
 *********************************************************************************************************************/
/*! \brief      Checks if the given port identity equals the port identity of the given port
 *  \param[in]  PortIdx           Port index
 *  \param[in]  PortIdentityNbo   Port Identity in Network byte order
 *  \return     TRUE              The Port Identities are equal\n
 *              FALSE             The Port Identities are not equal\n
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_LOCAL_PORT_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_PortIdentityIsEqualLocalPort(
                       EthTSyn_PortIdxType       PortIdx,
  ETHTSYN_CONSTP2CONST(EthTSyn_PortIdentityType) PortIdentityNbo);
# endif /* (ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_LOCAL_PORT_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_GetAsCapable
 *********************************************************************************************************************/
/*! \brief      Check if the given Port is AsCapable
 *  \param[in]  PortIdx  Index of the Port
 *  \return     TRUE     Port is AsCapable\n
 *              FALSE    Port is not AsCapable\n
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_GetAsCapable(
  EthTSyn_PortIdxType PortIdx);
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SetAsCapable
 *********************************************************************************************************************/
/*! \brief      Set AsCapable of the given Port
 *  \param[in]  PortIdx    Index of the Port
 *  \param[in]  AsCapable  The new value for AsCapable of the given Port
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_INLINE_API_SET_AS_CAPABLE_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SetAsCapable(
  EthTSyn_PortIdxType PortIdx,
  boolean             AsCapable);
# endif /* # (ETHTSYN_INLINE_API_SET_AS_CAPABLE_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_GetFrameId
 *********************************************************************************************************************/
/*! \brief      Retrieves the frame identifier contained in the Ethernet frame buffer
 *  \param[in]  DataPtr     Pointer to the Ethernet frame buffer
 *  \param[in]  PayloadLen  Length of the Ethernet frame payload
 *  \return     Frame identifier contained in the Ethernet frame buffer
 *********************************************************************************************************************/
# if (ETHTSYN_INLINE_API_GET_FRAME_ID_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(Eth_FrameIdType, ETHIF_CODE) EthTSyn_GetFrameId(
  ETHTSYN_P2CONST(uint8)  DataPtr,
                  uint16  PayloadLen);
# endif /* (ETHTSYN_INLINE_API_GET_FRAME_ID_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# ifndef ETHTSYN_UNIT_TEST /* COV_ETHTSYN_TESTSUITE_INSTRUMENTATION */
/**********************************************************************************************************************
 *  EthTSyn_SetClockIdentity
 *********************************************************************************************************************/
 /* PRQA S 3673 3 */ /* MD_EthTSyn_16.7a */
ETHTSYN_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SetClockIdentity(EthTSyn_ClockIdentityType TargetPtr,
    CONST(EthTSyn_ClockIdentityType, ETHTSYN_CONST) SourcePtr )
{
  /* ----- Implementation ----------------------------------------------- */
  /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
  IpBase_Copy( (ETHTSYN_P2VAR(IpBase_CopyDataType)) TargetPtr,
    (ETHTSYN_P2VAR(IpBase_CopyDataType)) SourcePtr, sizeof(EthTSyn_ClockIdentityType));
}

/**********************************************************************************************************************
 *  EthTSyn_SetMasterPriorityVector
 *********************************************************************************************************************/
#  if (ETHTSYN_INLINE_API_SET_MASTER_PRIO_VECTOR_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SetMasterPriorityVector(
  ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType) AnnounceMsgPtr, EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  CANOE_WRITE_STRING("EthTSyn_SetMasterPriorityVector: Set new Grandmaster");
  EthTSyn_SetClockIdentity( EthTSyn_SystemState[TimeDomainIdx].GmPriority.PortIdentity.ClockIdentity,
    AnnounceMsgPtr->ClockIdentity);
  EthTSyn_SystemState[TimeDomainIdx].GmPresent = TRUE;
}
#  endif /* (ETHTSYN_INLINE_API_SET_MASTER_PRIO_VECTOR_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CompareClockIdentity
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(EthTSyn_CompareType, ETHTSYN_CODE) EthTSyn_CompareClockIdentity(
  ETHTSYN_P2CONST(EthTSyn_ClockIdentityPtrType) Value, ETHTSYN_P2CONST(EthTSyn_ClockIdentityPtrType) Reference)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least Idx; /* PRQA S 0781 */ /* MD_EthTSyn_5.6 */
  EthTSyn_CompareType retVal = ETHTSYN_COMPARE_EQUAL;

  /* ----- Implementation ----------------------------------------------- */
  for(Idx = 0; Idx < 8; Idx++)
  {
    if(Value[Idx] > Reference[Idx])
    {
      retVal = ETHTSYN_COMPARE_GREATER;
      break;
    }
    else if(Value[Idx] < Reference[Idx])
    {
      retVal = ETHTSYN_COMPARE_LESS;
      break; /* PRQA S 0771 */ /* MD_EthTSyn_14.6 */
    }
    else
    {
      /* values are equal -> do nothing */
    }
  }
  return retVal;
} /* EthTSyn_CompareClockIdentity() */

/**********************************************************************************************************************
 *  EthTSyn_NtohTimestamp
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_NtohTimestamp(
  ETHTSYN_P2VAR(EthTSyn_GlobalTimestampType) LocalTimestampPtr,
  ETHTSYN_P2CONST(EthTSyn_TimestampType) GlobalTimestampPtr )
{
  /* ----- Implementation ----------------------------------------------- */
  LocalTimestampPtr->nanoseconds = (uint32)(((uint32) GlobalTimestampPtr->NanoSeconds[0] << 24u) |
                                            ((uint32) GlobalTimestampPtr->NanoSeconds[1] << 16u) |
                                            ((uint32) GlobalTimestampPtr->NanoSeconds[2] <<  8u) |
                                            ((uint32) GlobalTimestampPtr->NanoSeconds[3] <<  0u));

  LocalTimestampPtr->secondsHi =   (uint16)(((uint16) GlobalTimestampPtr->Seconds[0] << 8u) |
                                            ((uint16) GlobalTimestampPtr->Seconds[1] << 0u));

  LocalTimestampPtr->seconds =     (uint32)(((uint32) GlobalTimestampPtr->Seconds[2] << 24u) |
                                            ((uint32) GlobalTimestampPtr->Seconds[3] << 16u) |
                                            ((uint32) GlobalTimestampPtr->Seconds[4] <<  8u) |
                                            ((uint32) GlobalTimestampPtr->Seconds[5] <<  0u));

} /* EthTSyn_NtohTimestamp() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  EthTSyn_GetPortType
 *********************************************************************************************************************/
#  if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
ETHTSYN_INLINE FUNC(EthTSyn_PortTypeType, ETHTSYN_CODE) EthTSyn_GetPortType(
    EthTSyn_PortIdxType PortIdx)
{

  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_PortTypeType portType = ETHTSYN_PORT_TYPE_END_STATION_PORT;

  /* ----- Implementation ----------------------------------------------- */
  
  if ( (EthTSyn_PortConfig[PortIdx].SwtInfo.SwitchIdx != ETHTSYN_INVALID_ETHIF_SWITCH_IDX) &&
       (EthTSyn_PortConfig[PortIdx].SwtInfo.PortIdx != ETHTSYN_INVALID_SWITCH_PORT_IDX) )
  {
    portType = ETHTSYN_PORT_TYPE_SWITCH_PORT;
  }

  return portType;
} /* EthTSyn_GetPortType() */
#  endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CheckMessageGeneral
 *********************************************************************************************************************/
#  if (ETHTSYN_INLINE_API_CHECK_MESSAGE_GENERAL_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_CheckMessageGeneral(ETHTSYN_P2CONST(uint8) MsgPtr,
    uint16 LenByte, ETHTSYN_P2VAR(EthTSyn_TimeDomainIdxType) TimeDomainIdxPtr, ETHTSYN_P2VAR(uint8) ErrorIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) comMsgHdrPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* Message length sanity check */
  if(LenByte < ETHTSYN_HDR_COM_LENGTH)
  {
    /* Invalid message length, message is smaller than common header --> drop message */
    /* Note: This should never happen since the common header length is 34 while the min Eth Frame Payload size is 46 */
    *ErrorIdPtr = ETHTSYN_E_INV_MSG_LENGTH;
  }
  else
  {
    /* Get the common message hdr */
    comMsgHdrPtr = (ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))&MsgPtr[0]; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

    /* Check header message length vs. LenByte */
    if((uint16)EthTSyn_Ntohs(comMsgHdrPtr->MessageLength) > LenByte)
    {
      *ErrorIdPtr = ETHTSYN_E_INV_MSG_LENGTH;
    }
    /* Check EthTSyn Protocol version */
    else if(ETHTSYN_HDR_COM_VERSION(comMsgHdrPtr->Reserved_VersionGPtp) != ETHTSYN_PROTOCOL_VERSION)
    {
      /* Invalid EthTSyn protocol version --> drop message */
      *ErrorIdPtr = ETHTSYN_E_INV_PROTOCOL_VERSION;
    }
    else
    {
      *TimeDomainIdxPtr = EthTSyn_CfgAccess_GetTimeDomainIdx(comMsgHdrPtr->DomainNumber);
      if(*TimeDomainIdxPtr < ETHTSYN_TIME_DOMAIN_COUNT)
      {
        retVal = E_OK;
      }
      else
      {
        *ErrorIdPtr = ETHTSYN_E_INV_DOMAIN_NUMBER;
      }
    }
  }

  return retVal;
} /* EthTSyn_CheckMessageGeneral() */
#  endif /* (ETHTSYN_INLINE_API_CHECK_MESSAGE_GENERAL_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CheckMessageTypeAndLength
 *********************************************************************************************************************/
#  if (ETHTSYN_INLINE_API_CHECK_MESSAGE_TYPE_AND_LENGTH_ENABLED == STD_ON)
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
ETHTSYN_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_CheckMessageTypeAndLength(
    ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgHdrPtr, uint16 LenByte, ETHTSYN_P2VAR(uint8) ErrorIdPtr)
{ /* No 'SwtMgmt' in-fixing because the function will be used globally in future */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  uint16 msgLengthHeader;

  /* ----- Implementation ----------------------------------------------- */
  msgLengthHeader = (uint16)EthTSyn_Ntohs(ComMsgHdrPtr->MessageLength);

  switch(ETHTSYN_HDR_COM_MSG_TYPE(ComMsgHdrPtr->TransSpecific_MessageType))
  {
    case ETHTSYN_MSG_TYPE_SYNC:
#   if (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON)
      if( (LenByte < ETHTSYN_MSG_SYNC_LENGTH) || (msgLengthHeader != ETHTSYN_MSG_SYNC_LENGTH) )
      {
        *ErrorIdPtr = ETHTSYN_E_INV_MSG_LENGTH;
        retVal = E_NOT_OK;
      }
#   else
      /* Nothing to do here */
#   endif /* (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON) */
      break;

    case ETHTSYN_MSG_TYPE_FOLLOW_UP:
#   if (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON)
      if( (LenByte < ETHTSYN_MSG_FOLLOW_UP_RX_MIN_LENGTH) || (msgLengthHeader < ETHTSYN_MSG_FOLLOW_UP_RX_MIN_LENGTH) )
      {
        *ErrorIdPtr = ETHTSYN_E_INV_MSG_LENGTH;
        retVal = E_NOT_OK;
      }
#   else
      /* Nothing to do here */
#   endif /* (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON) */
      break;

#   if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
    case ETHTSYN_MSG_TYPE_PDELAY_REQ:
      if( (LenByte < ETHTSYN_MSG_P_DELAY_REQ_LENGTH) || (msgLengthHeader != ETHTSYN_MSG_P_DELAY_REQ_LENGTH) )
      {
        *ErrorIdPtr = ETHTSYN_E_INV_MSG_LENGTH;
        retVal = E_NOT_OK;
      }
#   else
      /* Nothing to do here */
#   endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */
      break;

    case ETHTSYN_MSG_TYPE_PDELAY_RESP:
#   if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
      if( (LenByte < ETHTSYN_MSG_P_DELAY_RESP_LENGTH) || (msgLengthHeader != ETHTSYN_MSG_P_DELAY_RESP_LENGTH) )
      {
        *ErrorIdPtr = ETHTSYN_E_INV_MSG_LENGTH;
        retVal = E_NOT_OK;
      }
#   else
      /* Nothing to do here */
#   endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */
      break;

    case ETHTSYN_MSG_TYPE_PDELAY_RES_FOLLOW_UP:
#   if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
      if( (LenByte < ETHTSYN_MSG_P_DELAY_RESP_FOLLOW_UP_LENGTH) ||
          (msgLengthHeader != ETHTSYN_MSG_P_DELAY_RESP_FOLLOW_UP_LENGTH) )
      {
        *ErrorIdPtr = ETHTSYN_E_INV_MSG_LENGTH;
        retVal = E_NOT_OK;
      }
#   else
      /* Nothing to do here */
#   endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */
      break;

    case ETHTSYN_MSG_TYPE_ANNOUNCE:
#   if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
      if( (LenByte < ETHTSYN_MSG_ANNOUNCE_LENGTH) ||
          (msgLengthHeader != ETHTSYN_MSG_ANNOUNCE_LENGTH) )
      {
        *ErrorIdPtr = ETHTSYN_E_INV_MSG_LENGTH;
        retVal = E_NOT_OK;
      }
#   else
      /* nothing to do here */
#   endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */
      break;

    default:
      *ErrorIdPtr = ETHTSYN_E_INV_MSG_TYPE;
      retVal = E_NOT_OK;
      break;
  }

  return retVal;
} /* EthTSyn_CheckMessageTypeAndLength() */
/* PRQA L: STCYC */
#  endif /* (ETHTSYN_INLINE_API_CHECK_MESSAGE_TYPE_AND_LENGTH_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_GetFirstArSubTlvPtrAndCnt
 *********************************************************************************************************************/
#  if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetFirstArSubTlvPtrAndCnt(EthTSyn_PortIdxType PortIdx,
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgHdrPtr,
  ETHTSYN_P2VAR(ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType)) FirstSubTlvPtrPtr, ETHTSYN_P2VAR(uint8) SubTlvCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  ETHTSYN_P2CONST(EthTSyn_ArTlvHeaderType) arTlvHdrPtr;
  uint32 arTlvOrgaId;
  uint32 arTlvOrgaSubType;
  uint16 arTlvLengthField;
  uint16 arTlvTypeField;
  uint16 offsetToArTlvHdr;
  sint32 remainingLength = 0;
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType) subTlvPtr;
#   if (ETHTSYN_CRC_RX_SUPPORT == STD_ON)
  uint8 rxCrcValidated = ETHTSYN_CFG_GET_RX_CRC_VALIDATED(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
  uint8 dataId;
#   endif /* (ETHTSYN_CRC_RX_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
  /* Init out parameters */
  *FirstSubTlvPtrPtr = NULL_PTR;
  *SubTlvCnt = 0;

#   if (ETHTSYN_CRC_RX_SUPPORT == STD_ON)
  /* Get the dataId if Crc support is enabled */
  dataId = EthTSyn_CfgAccess_GetFollowUpDataIdListEntry(ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(PortIdx),
    (uint16)EthTSyn_Ntohs(ComMsgHdrPtr->SequenceId));
#   else
  ETHTSYN_DUMMY_STATEMENT(PortIdx); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#   endif /* (ETHTSYN_CRC_RX_SUPPORT == STD_ON) */

  /* Check if the message length indicates at least one Ar-Tlv */
  if((uint16)EthTSyn_Ntohs(ComMsgHdrPtr->MessageLength) >=
    (ETHTSYN_MSG_FOLLOW_UP_RX_MIN_LENGTH + ETHTSYN_AR_TLV_HEADER_LENGTH))
  {
    /* There might be a Ar Tlv. Check it */
    /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    arTlvHdrPtr = (ETHTSYN_P2CONST(EthTSyn_ArTlvHeaderType))
      &((ETHTSYN_P2CONST(uint8))ComMsgHdrPtr)[ETHTSYN_MSG_FOLLOW_UP_RX_MIN_LENGTH];

    /* perform general checks on the Ar Tlv Header */
    ETHTSYN_GET_UINT16(arTlvHdrPtr->TlvType, 0u, arTlvTypeField);
    if(arTlvTypeField == ETHTSYN_AR_TLV_TYPE)
    {
      /* Get LenghtField, OrganizationId and OrganizationSubType */
      ETHTSYN_GET_UINT16(arTlvHdrPtr->LengthField, 0u, arTlvLengthField);
      ETHTSYN_GET_3_BYTE(arTlvHdrPtr->OrganisationId, 0u, arTlvOrgaId);
      ETHTSYN_GET_3_BYTE(arTlvHdrPtr->OrganisationSubType, 0u, arTlvOrgaSubType);
      if(arTlvLengthField > (ETHTSYN_AR_TLV_HEADER_LENGTH_FIELD_VALUE + ETHTSYN_AR_SUB_TLV_ABSTRACT_HDR_LENGTH))
      {
        if((arTlvOrgaId == ETHTSYN_AR_TLV_ORGANIZATION_ID) &&
          (arTlvOrgaSubType == ETHTSYN_AR_TLV_ORGANIZATION_SUB_TYPE))
        {
          /* Ready to unpack and check the Sub-Tlvs */
          retVal = E_OK;
          remainingLength = (sint32)(arTlvLengthField - ETHTSYN_AR_TLV_HEADER_LENGTH_FIELD_VALUE);
        }
      }
    }

    if(retVal == E_OK)
    {
      /* Unpack and check Sub-Tlvs */
      offsetToArTlvHdr = ETHTSYN_AR_TLV_HEADER_LENGTH;

      do
      {
        uint8 tlvLength;

        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        subTlvPtr = (ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType))
          &((ETHTSYN_P2CONST(uint8))arTlvHdrPtr)[offsetToArTlvHdr];
        tlvLength = ETHTSYN_AR_SUB_TLV_ABSTRACT_HDR_LENGTH;
        tlvLength += subTlvPtr->Length;

        remainingLength -= (sint32)tlvLength;

        if(remainingLength >= 0)
        {
          offsetToArTlvHdr += tlvLength;
          (*SubTlvCnt)++;
          if(*FirstSubTlvPtrPtr == NULL_PTR)
          {
            *FirstSubTlvPtrPtr = subTlvPtr;
          }

          /* Process Sub-Tlv */
#   if (ETHTSYN_CRC_RX_SUPPORT == STD_ON)
          /* Check if Crc is included and valid */
          switch(subTlvPtr->Type)
          {
          case ETHTSYN_AR_SUB_TLV_TYPE_TIME_SECURED:
          case ETHTSYN_AR_SUB_TLV_TYPE_OFS_SECURED:
          case ETHTSYN_AR_SUB_TLV_TYPE_STATUS_SECURED:
          case ETHTSYN_AR_SUB_TLV_TYPE_USER_DATA_SECURED:
            /* Secured Sub-Tlv -> Check if this is valid */
            if(rxCrcValidated == ETHTSYN_CRC_RX_CRC_NOT_VALIDATED)
            {
              /* Crc not allowed -> drop message */
              retVal = E_NOT_OK;
            }
            else if(rxCrcValidated == ETHTSYN_CRC_RX_CRC_IGNORED)
            {
              /* Not required to validate Crc -> continue with next Sub-Tlv */
            }
            else
            {
              /* Validate Crc */
              switch(subTlvPtr->Type)
              {
              case ETHTSYN_AR_SUB_TLV_TYPE_TIME_SECURED:
                /* PRQA S 0310, 0715 3 */ /* MD_EthTSyn_11.4, MD_MSR_1.1_715 */
                if(EthTSyn_Crc_ValidateTimeCrc(dataId, ComMsgHdrPtr, (ETHTSYN_P2CONST(EthTSyn_FollowUpMsgType))
                  &((ETHTSYN_P2CONST(uint8))ComMsgHdrPtr)[ETHTSYN_HDR_COM_LENGTH],
                  (ETHTSYN_P2CONST(EthTSyn_ArSubTlvTimeSecuredType))subTlvPtr) == FALSE)
                {
                  /* Crc invalid -> drop message */
                  retVal = E_NOT_OK;
                }
                break;
              case ETHTSYN_AR_SUB_TLV_TYPE_OFS_SECURED:
                /* PRQA S 0310, 0715 1 */ /* MD_EthTSyn_11.4, MD_MSR_1.1_715 */
                if(EthTSyn_Crc_ValidateOfsCrc(dataId, (ETHTSYN_P2CONST(EthTSyn_ArSubTlvOfsType))subTlvPtr) == FALSE)
                {
                  /* Crc invalid -> drop message */
                  retVal = E_NOT_OK;
                }
                break;
              case ETHTSYN_AR_SUB_TLV_TYPE_STATUS_SECURED:
                /* PRQA S 0310, 0715 1 */ /* MD_EthTSyn_11.4, MD_MSR_1.1_715 */
                if(EthTSyn_Crc_ValidateStatusCrc(dataId, (ETHTSYN_P2CONST(EthTSyn_ArSubTlvStatusType))subTlvPtr) ==
                  FALSE)
                {
                  /* Crc invalid -> drop message */
                  retVal = E_NOT_OK;
                }
                break;
              case ETHTSYN_AR_SUB_TLV_TYPE_USER_DATA_SECURED:
                /* PRQA S 0310, 0715 1 */ /* MD_EthTSyn_11.4, MD_MSR_1.1_715 */
                if(EthTSyn_Crc_ValidateUserDataCrc(dataId, (ETHTSYN_P2CONST(EthTSyn_ArSubTlvUserDataType))subTlvPtr) ==
                  FALSE)
                {
                  /* Crc invalid -> drop message */
                  retVal = E_NOT_OK;
                }
                break;

              default:
                /* This sould never happen (MISRA) */
                break;
              }
            }
            break;

          case ETHTSYN_AR_SUB_TLV_TYPE_OFS_NOT_SECURED:
          case ETHTSYN_AR_SUB_TLV_TYPE_STATUS_NOT_SECURED:
          case ETHTSYN_AR_SUB_TLV_TYPE_USER_DATA_NOT_SECURED:
            /* Not Secured Sub-Tlv --> Check if this is valid */
            if(rxCrcValidated == ETHTSYN_CRC_RX_CRC_VALIDATED)
            {
              /* Crc required -> drop message */
              retVal = E_NOT_OK;
            }
            break;

          default:
            /* Unknown Tlv-Type --> skip */
            break;
          }
#   endif /* (ETHTSYN_CRC_RX_SUPPORT == STD_ON) */
        }
        else
        {
          retVal = E_NOT_OK;
        }
      } while((remainingLength > (sint32)ETHTSYN_AR_SUB_TLV_ABSTRACT_HDR_LENGTH) && (retVal == E_OK));
    }
  }
  else
  {
    /* According to message length, no Ar Tlv can be included in the message. This is valid. */
    retVal = E_OK;
  }

  return retVal;
} /* EthTSyn_GetFirstArSubTlvPtrAndCnt() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: STMIF */
#  endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

/**********************************************************************************************************************
 *  EthTSyn_IsTimestampReadyToProcess
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_IsTimestampReadyToProcess(
  EthTSyn_TimestampStateType TimestampState)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean timestampReadyToProcess = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  if((TimestampState & ETHTSYN_TIMESTAMP_STATE_REQUIRED_FLAG_VALID_MASK) != 0)
  {
    if((TimestampState & ETHTSYN_TIMESTAMP_STATE_REQUIRED_MASK) == 0)
    {
      /* Timestamp not required --> processing possible regardless of the availability */
      timestampReadyToProcess = TRUE;
    }
    else
    {
      /* Timestamp required. Check availability */
      if((TimestampState & ETHTSYN_TIMESTAMP_STATE_AVAILABLE_FLAG_VALID_MASK) != 0)
      {
        timestampReadyToProcess = TRUE;
      }
    }
  }

  return timestampReadyToProcess;
} /* EthTSyn_IsTimestampReadyToProcess() */

/**********************************************************************************************************************
 *  EthTSyn_PortIdentityIsEqual
 *********************************************************************************************************************/
#  if (ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_PortIdentityIsEqual(
  ETHTSYN_CONSTP2CONST(EthTSyn_PortIdentityType) PortIdentity1,
  ETHTSYN_CONSTP2CONST(EthTSyn_PortIdentityType) PortIdentity2Nbo)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isEqual = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  if(PortIdentity1->PortNumber == (EthTSyn_PortNumberType)EthTSyn_Ntohs(PortIdentity2Nbo->PortNumber))
  {
    if(EthTSyn_CompareClockIdentity(PortIdentity1->ClockIdentity, PortIdentity2Nbo->ClockIdentity) ==
      ETHTSYN_COMPARE_EQUAL)
    {
      isEqual = TRUE;
    }
  }

  return isEqual;
} /* EthTSyn_PortIdentityIsEqual() */
#  endif /* (ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_PortIdentityIsEqualLocalPort
 *********************************************************************************************************************/
#  if (ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_LOCAL_PORT_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_PortIdentityIsEqualLocalPort(EthTSyn_PortIdxType PortIdx,
  ETHTSYN_CONSTP2CONST(EthTSyn_PortIdentityType) PortIdentityNbo)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isEqual = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  if(ETHTSYN_CFG_GET_PORT_NUMBER(PortIdx) == (EthTSyn_PortNumberType)EthTSyn_Ntohs(PortIdentityNbo->PortNumber))
  {
    if(EthTSyn_CompareClockIdentity(ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx),
      PortIdentityNbo->ClockIdentity) == ETHTSYN_COMPARE_EQUAL)
    {
      isEqual = TRUE;
    }
  }

  return isEqual;
} /* EthTSyn_PortIdentityIsEqualLocalPort() */
#  endif /* (ETHTSYN_INLINE_API_PORT_IDENTITY_IS_EQUAL_LOCAL_PORT_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_GetAsCapable
 *********************************************************************************************************************/
#  if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_GetAsCapable(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean asCapable = TRUE; /* Init as TRUE for better readability */

  /* ----- Implementation ----------------------------------------------- */
  /* Check if Port is pdelay initiator because AsCapble can only be FALSE when Port is pdelay initiator */
  if(EthTSyn_CfgAccess_IsPdelayInitiator(PortIdx) == TRUE)
  {
    /* Port is Pdelay initiator -> Check AsCapable status */
    asCapable = ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->AsCapable;
  }

  return asCapable;
} /* EthTSyn_GetAsCapable() */
#  endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SetAsCapable
 *********************************************************************************************************************/
#  if (ETHTSYN_INLINE_API_SET_AS_CAPABLE_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SetAsCapable(EthTSyn_PortIdxType PortIdx, boolean AsCapable)
{
  /* ----- Implementation ----------------------------------------------- */
  /* Check if Port is pdelay initiator because AsCapble can only change for Pdelay initiators */
  if(EthTSyn_CfgAccess_IsPdelayInitiator(PortIdx) == TRUE)
  {
    /* Check if Port is not always AsCapable */
    if(ETHTSYN_CFG_GET_ALWAYS_AS_CAPABLE(PortIdx) == FALSE)
    {
      /* Only set AsCapble for Ports which are not always AsCapable */
      ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->AsCapable = AsCapable;
    }
  }
} /* EthTSyn_SetAsCapable() */
#  endif /* # (ETHTSYN_INLINE_API_SET_AS_CAPABLE_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_GetFrameId
 *********************************************************************************************************************/
#  if (ETHTSYN_INLINE_API_GET_FRAME_ID_ENABLED == STD_ON)
ETHTSYN_INLINE FUNC(Eth_FrameIdType, ETHIF_CODE) EthTSyn_GetFrameId(ETHTSYN_P2CONST(uint8) DataPtr, uint16 PayloadLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(uint8) frameIdPtr;
  Eth_FrameIdType frameId;
  uint8_least frameIdByteIdx;
  
  /* ----- Implementation ----------------------------------------------- */
  /* PRQA S 0310 1 */ /* Byte access needed to avoid mis-aligned access on specific platforms. */
  frameIdPtr = (ETHTSYN_P2VAR(uint8))&frameId;
  for( frameIdByteIdx = 0; frameIdByteIdx < sizeof(Eth_FrameIdType); frameIdByteIdx++ )
  {
    frameIdPtr[frameIdByteIdx] = DataPtr[PayloadLen + frameIdByteIdx];
  }
  
  return frameId;
} /* EthTSyn_GetFrameId() */
#  endif /* (ETHTSYN_INLINE_API_GET_FRAME_ID_ENABLED == STD_ON) */
# endif /* ETHTSYN_UNIT_TEST */

# define ETHTSYN_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif
  /* ETHTSYN_PRIV_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_Priv.h
 *********************************************************************************************************************/
