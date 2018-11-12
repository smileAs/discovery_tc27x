/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EthTSyn_CfgAccess_Int.h
 *        \brief  EthTSyn internal header file to access configuration data
 *
 *      \details  Contains all macros and function declarations used by the EthTSyn to access the configuration data
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#if !defined (ETHTSYN_CFG_ACCESS_INT_H)
# define ETHTSYN_CFG_ACCESS_INT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "EthTSyn_Types.h"
# include "EthTSyn_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (ETHTSYN_INLINE)
#  define ETHTSYN_INLINE static INLINE
# endif

# define ETHTSYN_INV_TIME_DOMAIN_ID                    ((EthTSyn_DomainNumberType)(255))
# define ETHTSYN_INV_BUF_IDX                           ((EthTSyn_BufferIdxType)(255))

/* ----- Inline function availability ----- */
/* -- EthTSyn_CfgAccess_GetFollowUpDataIdListEntry() -- */
# if (                                             \
        (ETHTSYN_FOLLOW_UP_DATA_ID_LIST_SIZE > 0u) \
     )
#  define ETHTSYN_INLINE_API_CFG_GET_FUP_DATA_ID_LIST_ENTRY  STD_ON
# else
#  define ETHTSYN_INLINE_API_CFG_GET_FUP_DATA_ID_LIST_ENTRY  STD_OFF
# endif /* EthTSyn_CfgAccess_GetFollowUpDataIdListEntry availability check */

/* -- EthTSyn_CfgAccess_IsArTlvTxRequired() -- */
# if(                                                 \
      ((ETHTSYN_TLV_FOLLOW_UP_TX_SUPPORT == STD_ON) ) \
    )
#  define ETHTSYN_INLINE_API_CFG_IS_AR_TLV_TX_REQUIRED  STD_ON
# else
#  define ETHTSYN_INLINE_API_CFG_IS_AR_TLV_TX_REQUIRED STD_OFF
# endif /* EthTSyn_CfgAccess_IsArTlvTxRequired availability check */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* TimeDomain */
# define EthTSyn_CfgGetSlavePortCnt(TimeDomainIdx)     (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].SlavePortCnt)
# define EthTSyn_CfgGetSlavePortIdxPtr(TimeDomainIdx)  (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].SlavePortIdxPtr)
# define EthTSyn_CfgGetSlavePortIdx(TimeDomainIdx, Idx) \
  (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].SlavePortIdxPtr[(Idx)])
# define EthTSyn_CfgGetMasterPortCnt(TimeDomainIdx)    (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].MasterPortCnt)
# define EthTSyn_CfgGetMasterPortIdxPtr(TimeDomainIdx) (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].MasterPortIdxPtr)
# define EthTSyn_CfgGetMasterPortIdx(TimeDomainIdx, Idx) \
  (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].MasterPortIdxPtr[(Idx)])
# define ETHTSYN_CFG_GET_SYNCHRONIZED_TIME_BASE_ID(TimeDomainIdx) \
  ((StbM_SynchronizedTimeBaseType)EthTSyn_TimeDomainConfig[(TimeDomainIdx)].SynchronizedTimeBaseId)
# define ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_COUNT(TimeDomainIdx) \
  (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].OfsTimeDomainCnt)
# define ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_PTR(TimeDomainIdx) \
  (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].OfsTimeDomainPtr)
# define ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_ID(TimeDomainIdx, OfsTimeDomainIdx) \
  (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].OfsTimeDomainPtr[(OfsTimeDomainIdx)].OfsTimeDomainId)
# define ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_SYNCHRONIZED_TIME_BASE_ID(TimeDomainIdx, OfsTimeDomainIdx) \
  (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].OfsTimeDomainPtr[(OfsTimeDomainIdx)].SynchronizedTimeBaseId)

/* Port */
# define EthTSyn_CfgGetPortRole(PortIdx)               (EthTSyn_PortConfig[(PortIdx)].PortRolePtr->PortRole)
# define EthTSyn_CfgGetTimeDomainId(PortIdx)           (EthTSyn_PortConfig[(PortIdx)].TimeDomainId)
# define ETHTSYN_CFG_GET_PORT_NUMBER(PortIdx)          (EthTSyn_PortConfig[(PortIdx)].PortNumber)
# define ETHTSYN_CFG_GET_ETHTSYN_CTRL_IDX(PortIdx) \
  (EthTSyn_PortConfig[PortIdx].EthTSynCtrlIdx)
# define ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx) \
  (EthTSyn_CtrlConfig[EthTSyn_PortConfig[PortIdx].EthTSynCtrlIdx].EthIfCtrlIdx)
# define ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(PortIdx) \
  (EthTSyn_CfgAccess_GetTimeDomainIdx(EthTSyn_CfgGetTimeDomainId((PortIdx))))
# define ETHTSYN_CFG_GET_SYNCHRONIZTED_TIME_BASE_ID_OF_PORT(PortIdx) \
  (ETHTSYN_CFG_GET_SYNCHRONIZED_TIME_BASE_ID(EthTSyn_CfgAccess_GetTimeDomainIdx(EthTSyn_CfgGetTimeDomainId((PortIdx)))))
# define ETHTSYN_CFG_GET_FRAME_PRIORITY(PortIdx)  (EthTSyn_PortConfig[(PortIdx)].FramePriority)
# define ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_COUNT_OF_PORT(PortIdx) \
  (EthTSyn_TimeDomainConfig[ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT((PortIdx))].OfsTimeDomainCnt)
# define ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_POINTER_OF_PORT(PortIdx) \
  (EthTSyn_TimeDomainConfig[ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT((PortIdx))].OfsTimeDomainPtr)
# define ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_ID_OF_PORT(PortIdx, OfsTimeDomainIdx) \
  (ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_POINTER_OF_PORT((PortIdx))[OfsTimeDomainIdx].OfsTimeDomainId)
# define ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_SYNCHRONIZED_TIME_BASE_ID_OF_PORT(PortIdx, OfsTimeDomainIdx) \
  (ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_POINTER_OF_PORT((PortIdx))[OfsTimeDomainIdx].SynchronizedTimeBaseId)

# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
#  define ETHTSYN_CFG_GET_SWITCH_IDX(EthTSynPortIdx)       (EthTSyn_PortConfig[(EthTSynPortIdx)].SwtInfo.SwitchIdx)
#  define ETHTSYN_CFG_GET_SWITCH_PORT_IDX(EthTSynPortIdx)  (EthTSyn_PortConfig[(EthTSynPortIdx)].SwtInfo.PortIdx)
# else
#  define ETHTSYN_CFG_GET_SWITCH_IDX(PortIdx)       (ETHTSYN_INVALID_ETHIF_SWITCH_IDX)
#  define ETHTSYN_CFG_GET_SWITCH_PORT_IDX(PortIdx)  (ETHTSYN_INVALID_SWITCH_PORT_IDX)
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_ON)
#  define ETHTSYN_CFG_GET_FOLLOW_UP_MSG_LENGTH_TX(MasterPortIdx)  (ETHTSYN_MSG_FOLLOW_UP_TX_LENGTH)
# else
#  define ETHTSYN_CFG_GET_FOLLOW_UP_MSG_LENGTH_TX(MasterPortIdx) \
  (EthTSyn_MasterPortConfigPtr((MasterPortIdx))->FollowUpMsgLength)
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_ON) */

/* Pdelay */
# if (ETHTSYN_P_DELAY_CONFIG_COUNT == 1u)
#  define ETHTSYN_CFG_GET_PDELAY_IDX(PortIdx)           (0u)
# else
#  define ETHTSYN_CFG_GET_PDELAY_IDX(PortIdx)           (EthTSyn_PortConfig[(PortIdx)].PdelayIdx)
# endif /* (ETHTSYN_P_DELAY_CONFIG_COUNT == 1u) */
# define ETHTSYN_CFG_GET_P_DELAY_CFG(PortIdx) \
  (EthTSyn_PdelayConfig[ETHTSYN_CFG_GET_PDELAY_IDX((PortIdx))])
# define ETHTSYN_CFG_GET_P_DELAY_ACTIVE_PORT_IDX(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_CFG((PortIdx)).ActivePortIdx)
# define ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_CFG((PortIdx)).PdelayInitiatorCfgPtr)
# define ETHTSYN_CFG_GET_P_DELAY_RESPONDER_CFG_PTR(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_CFG((PortIdx)).PdelayResponderCfgPtr)

# define ETHTSYN_CFG_GET_P_DELAY_USE_STATIC(PortIdx) (ETHTSYN_CFG_GET_P_DELAY_CFG((PortIdx)).UseStaticPdelay)
# define ETHTSYN_CFG_GET_P_DELAY_INITIAL_NS(PortIdx) (ETHTSYN_CFG_GET_P_DELAY_CFG((PortIdx)).InitialPdelay)
# define ETHTSYN_CFG_GET_P_DELAY_RESP_RESP_FOLLOW_UP_TIMEOUT(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR((PortIdx))->PdelayRespRespFollowUpTimeout)

# define ETHTSYN_CFG_GET_ALWAYS_AS_CAPABLE(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_CFG((PortIdx)).AlwaysAsCapable)

/* Pdelay Initiator */
# define ETHTSYN_CFG_GET_P_DELAY_NEIGHBOR_DELAY_THRESHOLD_NS(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR((PortIdx))->PdelayNeighborDelayThreshold)
# define ETHTSYN_CFG_GET_P_DELAY_ALLOWED_LOST_RESPONSES(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR((PortIdx))->PdelayAllowedLostResponses)
# define ETHTSYN_CFG_GET_P_DELAY_REQ_SEND_INTERVAL_MF_CYCLES(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR(PortIdx)->PdelaySendInterval)
# define ETHTSYN_CFG_GET_P_DELAY_REQ_LOG_MESSAGE_INTERVAL(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR((PortIdx))->PdelayLogMessageInterval)
# define ETHTSYN_CFG_GET_P_DELAY_AVERAGE_WEIGHT(PortIdx) \
  (ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR((PortIdx))->PdelayAverageWeight)

/* Slave-Port */
# define EthTSyn_CfgGetEnableAnnounce(SlavePortIdx)    (EthTSyn_SlavePortConfigPtr((SlavePortIdx))->EnableAnnounce)
# define EthTSyn_CfgGetEnableSourcePortIdentityCheck(SlavePortIdx) \
   (EthTSyn_SlavePortConfigPtr((SlavePortIdx))->EnableSrcPortIdentityCheck)
# define EthTSyn_CfgGetMasterPortIdentity(SlavePortIdx) \
   (EthTSyn_SlavePortConfigPtr((SlavePortIdx))->MasterPortIdentity)

/* Master-Port */
# define ETHTSYN_CFG_GET_SYNC_TX_INTERVAL_CNT(MasterPortIdx) \
  (EthTSyn_MasterPortConfigPtr((MasterPortIdx))->SyncSendInterval)

/* Configuration access Macros only available in Bridge configuration */
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
/* TimeDomain */
# define EthTSyn_CfgGetSyncTimeout(TimeDomainIdx)         (EthTSyn_TimeDomainConfig[(TimeDomainIdx)].SyncTimeout)
# define EthTSyn_CfgGetKeepSrcPortIdentity(TimeDomainIdx) (EthTSyn_TimeDomainConfig[ \
                                                            (TimeDomainIdx)].KeepSrcPortIdentity)
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

# define EthTSyn_MasterPortConfigPtr(PortIdx) \
   ((ETHTSYN_P2CONSTCFG(EthTSyn_MasterPortConfigType))&EthTSyn_PortConfig[(PortIdx)].PortRolePtr->PortRole)
# define EthTSyn_SlavePortConfigPtr(PortIdx) \
   ((ETHTSYN_P2CONSTCFG(EthTSyn_SlavePortConfigType))&EthTSyn_PortConfig[(PortIdx)].PortRolePtr->PortRole)

/* Tx FollowUp Ar Sub-Tlv Used */
# if (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON)
#  define ETHTSYN_CFG_GET_AR_SUB_TLV_TIME_USED(PortIdx)       (EthTSyn_MasterPortConfigPtr((PortIdx))->TimeSubTlv)
#else
#  define ETHTSYN_CFG_GET_AR_SUB_TLV_TIME_USED(PortIdx)       (FALSE)
#endif /* (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON) */
# if (ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON)
#  define ETHTSYN_CFG_GET_AR_SUB_TLV_STATUS_USED(PortIdx)     (EthTSyn_MasterPortConfigPtr((PortIdx))->StatusSubTlv)
# else
#  define ETHTSYN_CFG_GET_AR_SUB_TLV_STATUS_USED(PortIdx)     (FALSE)
# endif /* (ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON) */
# if (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON)
#  define ETHTSYN_CFG_GET_AR_SUB_TLV_USER_DATA_USED(PortIdx)  (EthTSyn_MasterPortConfigPtr((PortIdx))->UserDataSubTlv)
# else
#  define ETHTSYN_CFG_GET_AR_SUB_TLV_USER_DATA_USED(PortIdx)  (FALSE)
# endif /* (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON) */
# if (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON)
#  define ETHTSYN_CFG_GET_AR_SUB_TLV_OFS_USED(PortIdx)        (EthTSyn_MasterPortConfigPtr((PortIdx))->OfsSubTlv)
# else
#  define ETHTSYN_CFG_GET_AR_SUB_TLV_OFS_USED(PortIdx)        (FALSE)
# endif /* (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON) */
# if (ETHTSYN_CRC_TX_SUPPORT == STD_ON)
#  define ETHTSYN_CFG_GET_TX_CRC_SECURED(PortIdx)             (EthTSyn_MasterPortConfigPtr((PortIdx))->TxCrcSecured)
#  if (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON)
#   define ETHTSYN_CFG_GET_TX_CRC_SECURED_FLAGS(PortIdx) \
    (EthTSyn_MasterPortConfigPtr((PortIdx))->CrcTimeFlagsTxSecured)
#  else
#   define ETHTSYN_CFG_GET_TX_CRC_SECURED_FLAGS(PortIdx)       (0u)
#  endif /* (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON) */
# else
#  define ETHTSYN_CFG_GET_TX_CRC_SECURED(PortIdx)             (0u)
#  define ETHTSYN_CFG_GET_TX_CRC_SECURED_FLAGS(PortIdx)       (0u)
# endif /* (ETHTSYN_CRC_TX_SUPPORT == STD_ON) */

/* Rx FollowUp Crc */
# if (ETHTSYN_CRC_RX_SUPPORT == STD_ON)
#  define ETHTSYN_CFG_GET_RX_CRC_VALIDATED(PortIdx)       (EthTSyn_SlavePortConfigPtr((PortIdx))->RxCrcValidated)
#  define ETHTSYN_CFG_GET_RX_CRC_VALIDATED_FLAGS(PortIdx) (EthTSyn_SlavePortConfigPtr((PortIdx))->CrcFlagsRxValidated)
# else
#  define ETHTSYN_CFG_GET_RX_CRC_VALIDATED(PortIdx)       (0u)
#  define ETHTSYN_CFG_GET_RX_CRC_VALIDATED_FLAGS(PortIdx) (0u)
# endif /* (ETHTSYN_CRC_RX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define ETHTSYN_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_GetTimeDomainIdx
 *********************************************************************************************************************/
/*! \brief      Get the TimeDomain index of the given TimeDomainNumber
 *  \param[in]  TimeDomainNumber:      Number of the TimeDomain the index should be retrieved for
 *  \return     The corresponding TimeDomain index. If no corresponding TimeDomain was found, the return value will be
 *              ETHTSYN_INVALID_TIME_DOMAIN_IDX
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(EthTSyn_TimeDomainIdxType, ETHTSYN_CODE) EthTSyn_CfgAccess_GetTimeDomainIdx(
  EthTSyn_DomainNumberType TimeDomainNumber);

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_GetFollowUpDataIdListEntry
 *********************************************************************************************************************/
/*! \brief      Get the value of the FollowUp Data Id list for the given FollowUp Sequence Id
 *  \param[in]  TimeDomainIdx:   Index of the TimeDomain the DataId is requested for
 *  \param[in]  SequenceId:      The SequenceId
 *  \return     The value of the FollowUp Data Id list for the given Sequence Id
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_INLINE_API_CFG_GET_FUP_DATA_ID_LIST_ENTRY == STD_ON)
ETHTSYN_INLINE FUNC(uint8, ETHTSYN_CODE) EthTSyn_CfgAccess_GetFollowUpDataIdListEntry(
  EthTSyn_TimeDomainIdxType TimeDomainIdx,
  uint16                    SequenceId);
# endif /* (ETHTSYN_INLINE_API_CFG_GET_FUP_DATA_ID_LIST_ENTRY == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_IsArTlvTxRequired
 *********************************************************************************************************************/
/*! \brief      Check if an Ar Tlv has to be appended to the FollowUp message transmitted on the given Port
 *  \param[in]  PortIdx:   Index of the Port the FollowUp message is transmitted on
 *  \return     TRUE:   Ar Tlv required\n
 *              FALSE:  Ar Tlv not required
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_INLINE_API_CFG_IS_AR_TLV_TX_REQUIRED == STD_ON)
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_CfgAccess_IsArTlvTxRequired(
  EthTSyn_PortIdxType PortIdx);
# endif /* (ETHTSYN_INLINE_API_CFG_IS_AR_TLV_TX_REQUIRED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_IsPdelayInitiator
 *********************************************************************************************************************/
/*! \brief      Check if the given Port is a Pdelay initiator
 *  \param[in]  PortIdx:   Index of the Port
 *  \return     TRUE:   Port is Pdelay initiator\n
 *              FALSE:  Port is no Pdelay initiator
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_CfgAccess_IsPdelayInitiator(
  EthTSyn_PortIdxType PortIdx);

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_IsPdelayResponder
 *********************************************************************************************************************/
/*! \brief      Check if the given Port is a Pdelay responder
 *  \param[in]  PortIdx:   Index of the Port
 *  \return     TRUE:   Port is Pdelay responder\n
 *              FALSE:  Port is no Pdelay responder
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_CfgAccess_IsPdelayResponder(
  EthTSyn_PortIdxType PortIdx);

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_IsActivePdelayPort
 *********************************************************************************************************************/
/*! \brief      Check if the given Port is the active Pdelay Port
 *  \param[in]  PortIdx:   Index of the Port
 *  \return     TRUE:   Port is the active Pdelay Port\n
 *              FALSE:  Port is not the active Pdelay Port
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_CfgAccess_IsActivePdelayPort(
  EthTSyn_PortIdxType PortIdx);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# ifndef ETHTSYN_UNIT_TEST /* COV_ETHTSYN_TESTSUITE_INSTRUMENTATION */
/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_GetTimeDomainIdx
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(EthTSyn_TimeDomainIdxType, ETHTSYN_CODE) EthTSyn_CfgAccess_GetTimeDomainIdx(
  EthTSyn_DomainNumberType TimeDomainNumber)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_TimeDomainIdxType timeDomainIdx = ETHTSYN_INVALID_TIME_DOMAIN_IDX;
  EthTSyn_TimeDomainIdxIterType timeDomainCounter;

  /* ----- Implementation ----------------------------------------------- */
  for(timeDomainCounter = 0; timeDomainCounter < ETHTSYN_TIME_DOMAIN_COUNT; timeDomainCounter++)
  {
    if(EthTSyn_TimeDomainConfig[timeDomainCounter].TimeDomainId == TimeDomainNumber)
    {
      timeDomainIdx = (EthTSyn_TimeDomainIdxType)timeDomainCounter;
      break;
    }
  }

  return timeDomainIdx;
} /* EthTSyn_CfgAccess_GetTimeDomainIdx() */

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_GetFollowUpDataIdListEntry
 *********************************************************************************************************************/
#  if (ETHTSYN_INLINE_API_CFG_GET_FUP_DATA_ID_LIST_ENTRY == STD_ON)
ETHTSYN_INLINE FUNC(uint8, ETHTSYN_CODE) EthTSyn_CfgAccess_GetFollowUpDataIdListEntry(
  EthTSyn_TimeDomainIdxType TimeDomainIdx, uint16 SequenceId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 dataListIdx = (uint8)(SequenceId % ETHTSYN_FOLLOW_UP_DATA_ID_LIST_SIZE);
  uint8 dataListEntry = 0;

  /* ----- Implementation ----------------------------------------------- */
  if(EthTSyn_TimeDomainConfig[TimeDomainIdx].FollowUpDataIdListPtr != NULL_PTR)
  {
    dataListEntry = EthTSyn_TimeDomainConfig[TimeDomainIdx].FollowUpDataIdListPtr[dataListIdx];
  }
  return dataListEntry;
} /* EthTSyn_CfgAccess_GetFollowUpDataIdListEntry() */
#  endif /* (ETHTSYN_INLINE_API_CFG_GET_FUP_DATA_ID_LIST_ENTRY == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_IsArTlvTxRequired
 *********************************************************************************************************************/
#  if (ETHTSYN_INLINE_API_CFG_IS_AR_TLV_TX_REQUIRED == STD_ON)
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_CfgAccess_IsArTlvTxRequired(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean arTlvRequired = FALSE;
  ETHTSYN_P2CONST(EthTSyn_MasterPortConfigType) masterPortCfgPtr = EthTSyn_MasterPortConfigPtr(PortIdx);

  /* ----- Implementation ----------------------------------------------- */
#   if (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON)
  if(masterPortCfgPtr->TimeSubTlv == TRUE)
  {
    arTlvRequired = TRUE;
  }
#   endif /* (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON) */

#   if (ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON)
  if(arTlvRequired == FALSE)
  {
    arTlvRequired = masterPortCfgPtr->StatusSubTlv;
  }
#   endif /* (ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON) */

#   if (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON)
  if(arTlvRequired == FALSE)
  {
    arTlvRequired = masterPortCfgPtr->UserDataSubTlv;
  }
#   endif /* (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON) */

#   if (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON)
  if(arTlvRequired == FALSE)
  {
    arTlvRequired = masterPortCfgPtr->OfsSubTlv;
  }
#   endif /* (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON) */

  return arTlvRequired;
} /* EthTSyn_CfgAccess_IsArTlvTxRequired() */
#  endif /* (ETHTSYN_INLINE_API_CFG_IS_AR_TLV_TX_REQUIRED == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_IsPdelayInitiator
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_CfgAccess_IsPdelayInitiator(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isPdelayInitiator;

  /* ----- Implementation ----------------------------------------------- */
  /* Check for Valid Pdelay index for the given Port */
#  if (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u)
  ETHTSYN_DUMMY_STATEMENT(PortIdx);
#   if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
  isPdelayInitiator = TRUE;
#   else
  isPdelayInitiator = FALSE;
#   endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */
#  else
  isPdelayInitiator = FALSE;
  if(ETHTSYN_CFG_GET_PDELAY_IDX(PortIdx) < ETHTSYN_P_DELAY_CONFIG_COUNT)
  {
    if(ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR(PortIdx) != NULL_PTR)
    {
      isPdelayInitiator = TRUE;
    }
  }
#  endif /* (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u) */

  return isPdelayInitiator;
} /* EthTSyn_CfgAccess_IsPdelayInitiator() */

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_IsPdelayResponder
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_CfgAccess_IsPdelayResponder(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isPdelayResponder;

  /* ----- Implementation ----------------------------------------------- */
  /* Check for Valid Pdelay index for the given Port */
#  if (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u)
  ETHTSYN_DUMMY_STATEMENT(PortIdx);
#  if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
  isPdelayResponder = TRUE;
#  else
  isPdelayResponder = FALSE;
#  endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */
#  else
  isPdelayResponder = FALSE;
  if(ETHTSYN_CFG_GET_PDELAY_IDX(PortIdx) < ETHTSYN_P_DELAY_CONFIG_COUNT)
  {
    if(ETHTSYN_CFG_GET_P_DELAY_RESPONDER_CFG_PTR(PortIdx) != NULL_PTR)
    {
      isPdelayResponder = TRUE;
    }
  }
#  endif /* (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u) */

  return isPdelayResponder;
} /* EthTSyn_CfgAccess_IsPdelayResponder() */

/**********************************************************************************************************************
 *  EthTSyn_CfgAccess_IsActivePdelayPort
 *********************************************************************************************************************/
ETHTSYN_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_CfgAccess_IsActivePdelayPort(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isActivePdelayPort = FALSE;

  /* ----- Implementation ----------------------------------------------- */
#  if (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u)
  ETHTSYN_DUMMY_STATEMENT(PortIdx);
#  else
  if(ETHTSYN_CFG_GET_PDELAY_IDX(PortIdx) < ETHTSYN_P_DELAY_CONFIG_COUNT)
#  endif /* (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u) */
  {
    if(ETHTSYN_CFG_GET_P_DELAY_CFG(PortIdx).ActivePortIdx == PortIdx)
    {
      isActivePdelayPort = TRUE;
    }
  }

  return isActivePdelayPort;
} /* EthTSyn_CfgAccess_IsActivePdelayPort() */
# endif /* ETHTSYN_UNIT_TEST */

# define ETHTSYN_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* ETHTSYN_CFG_ACCESS_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_CfgAccess_Int.h
 *********************************************************************************************************************/
