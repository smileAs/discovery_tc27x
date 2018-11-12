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
 *         \file  EthTSyn.c
 *        \brief  EthTSyn implementation
 *
 *      \details  Contains the main implementation of the Time Sync over Ethernet (EthTSyn) AUTOSAR module
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

#define ETHTSYN_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 MACRO_LIMIT */ /* MD_MSR_1.1_857 */
#include "EthTSyn_Priv.h" /* PRQA S 0883, 3412, 3453 */ /* MD_EthTSyn_19.15 */ /* MD_MSR_19.4 */ /* MD_MSR_19.7 */
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
# include "EthTSyn_SwtMgmt_Priv.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (   (ETHTSYN_SW_MAJOR_VERSION != 4u) \
     || (ETHTSYN_SW_MINOR_VERSION != 0u) \
     || (ETHTSYN_SW_PATCH_VERSION != 2u) )
# error "Vendor specific version numbers of EthTSyn.c and EthTSyn.h are inconsistent"
#endif

/* Check configurator version generated to EthTSyn_Cfg.h */
#if (   (ETHTSYN_CFG_MAJOR_VERSION != (0x04)) \
     || (ETHTSYN_CFG_MINOR_VERSION != (0x00)) )
# error "Version numbers of EthTSyn.c and EthTSyn_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* Wrap StbM-APIs (Ar4.3 -> Ar4.2) due to gradually implementation of new Ar3.4 APIs */ /*lint -e652 */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define StbM_GetOffset(timeBaseId, timeStamp, userData) (StbM_GetOffset((timeBaseId), (timeStamp)))
/*lint +e652 */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (ETHTSYN_LOCAL)
# define ETHTSYN_LOCAL static
#endif

#if !defined (ETHTSYN_LOCAL_INLINE)
# define ETHTSYN_LOCAL_INLINE static INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* PRQA L: MACRO_LIMIT */
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define ETHTSYN_START_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

VAR(EthTSyn_StateType, ETHTSYN_VAR_ZERO_INIT) EthTSyn_State = ETHTSYN_STATE_UNINIT;

#define ETHTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define ETHTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

VAR(EthTSyn_SystemType, ETHTSYN_VAR_NOINIT) EthTSyn_SystemState[ETHTSYN_TIME_DOMAIN_COUNT];

#define ETHTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define ETHTSYN_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

ETHTSYN_LOCAL FUNC(void, ETHTSYN_CODE) EthTSyn_SetLocalClockIdentity(
  EthTSyn_CtrlIdxType EthTSynCtrlIdx);

ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ResetMasterPriorityVector(
  EthTSyn_TimeDomainIdxType TimeDomainIdx);

ETHTSYN_LOCAL FUNC(void, ETHTSYN_CODE) EthTSyn_HtonTimestamp(
    ETHTSYN_P2VAR(EthTSyn_TimestampType)       GlobalTimestampPtr,
  ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType) LocalTimestampPtr);

ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxPdelayRespFollowUpMsg(
  EthTSyn_PortIdxType PortIdx);

ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxSyncMsg(
  EthTSyn_PortIdxType PortIdx);

ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxFollowUpMsg(
  EthTSyn_PortIdxType PortIdx);

#if (ETHTSYN_ANNOUNCE_TX_SUPPORT == STD_ON)
ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxAnnounceMsg(
  EthTSyn_PortIdxType PortIdx);
#endif /* (ETHTSYN_ANNOUNCE_TX_SUPPORT == STD_ON) */

ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_InitPort(
  EthTSyn_TimeDomainIdxType TimeDomainIdx,
  EthTSyn_PortIdxType       PortIdx);

ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_InitTimeDomain(
  EthTSyn_TimeDomainIdxType TimeDomainIdx);

ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_InitCtrl(
  EthTSyn_CtrlIdxType EthTSynCtrlIdx);

ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_InitPdelay(
  EthTSyn_PdelayIdxType PdelayIdx);

ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ResetPortsAndPdelayOfCtrl(
    EthTSyn_CtrlIdxType EthTSynCtrlIdx);

ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_IsTxReady(
  EthTSyn_PortIdxType PortIdx);

ETHTSYN_LOCAL_INLINE FUNC(EthTSyn_CtrlIdxType, ETHTSYN_CODE) EthTSyn_GetEthTSynCtrlFromEthIfCtrl(
  uint8 EthIfCtrlIdx);

ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_HandleEgressTimestamping(
  EthTSyn_PortIdxType PortIdx,
  uint8               MsgType,
  uint8               BufIdx);

/**********************************************************************************************************************
 *  EthTSyn_IsTimestampAvailable
 *********************************************************************************************************************/
/*! \brief      Check if the Timestamp of the given Timestamp state is available.
 *  \param[in]  TimestampState:    State of the Timestamp to check
 *  \return     TRUE:   Timestamp is available
 *              FALSE:  Timestamp is not available
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_IsTimestampAvailable(
  EthTSyn_TimestampStateType TimestampState);

/**********************************************************************************************************************
 *  EthTSyn_PrepareCommonMsgHdr
 *********************************************************************************************************************/
/*! \brief      Initializes the common message header
 *  \param[in]  ComMsgHdrPtr    Pointer to the common message header to be initialized
 *  \param[in]  MsgType         The type of the message the header should be prepared for
 *  \param[in]  PortIdx         Index of the EthTSyn Port the message will be transmitted on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_PrepareCommonMsgHdr(
  ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType) ComMsgHdrPtr,
                uint8                     MsgType,
                EthTSyn_PortIdxType       PortIdx);

#if (ETHTSYN_TLV_FOLLOW_UP_TX_SUPPORT == STD_ON)
/* AR4.3 message format */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_AppendArFollowUpTlvs(
                EthTSyn_PortIdxType          PortIdx,
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType)  ComMsgPtr,
    ETHTSYN_P2VAR(EthTSyn_FollowUpMsgType)   FollowUpMsgPtr);
#endif /* (ETHTSYN_TLV_FOLLOW_UP_TX_SUPPORT == STD_ON) */

#if ( (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) )
ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_QualifyAnnounceMsg(
                  EthTSyn_PortIdxType       PortIdx,
                  uint16                    LenByte,
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr);
#endif /* ( (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) ) */

#if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_ComputePdelay(
  EthTSyn_PortIdxType PortIdx);
#endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_IsSwitchPort
 *********************************************************************************************************************/
/*! \brief      Check if the given Port is a Switch-Port
 *  \param[in]  PortIdx:  Index of the Port
 *  \return     TRUE:     Port is a Switch-Port\n
 *              FALSE:    Port is not a Switch-Port
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_IsSwitchPort(
  EthTSyn_PortIdxType PortIdx);
#else
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
# define EthTSyn_IsSwitchPort(PortIdx)   (FALSE)
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_GetUserDataFromSubTlv
 *********************************************************************************************************************/
/*! \brief      Check if a UserData Sub-Tlv is present and retrieve the UserData
 *  \param[in]  FirstSubTlvPtr  Pointer to the first Ar Sub-Tlv
 *  \param[in]  SubTlvCount     The amount of the Ar Sub-Tlvs (including unknown Tlv-Types)
 *  \param[out] UserDataPtr     Pointer to where to store the retrieved UserData
 *  \return     E_OK:      UserData Sub-Tlv found and successfully retrieved the UserData\n
 *              E_NOT_OK:  No UserData Sub-Tlv found or failed to retrieve the UserData
 *  \pre        The Pointer to the FirstSubTlv and the SubTlvCount must have been retrieved using
 *              EthTSyn_GetFirstArSubTlvPtrAndCnt
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
#if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetUserDataFromSubTlv(
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType)  FirstSubTlvPtr,
                  uint8                                SubTlvCount,
    ETHTSYN_P2VAR(StbM_UserDataType)                   UserDataPtr);
#endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

/**********************************************************************************************************************
 *  EthTSyn_GetStatusFromSubTlv
 *********************************************************************************************************************/
/*! \brief      Check if a Status Sub-Tlv is present and retrieve the Status
 *  \param[in]  FirstSubTlvPtr  Pointer to the first Ar Sub-Tlv
 *  \param[in]  SubTlvCount     The amount of the Ar Sub-Tlvs (including unknown Tlv-Types)
 *  \param[out] UserDataPtr     Pointer to where to store the retrieved Status
 *  \return     E_OK:      Status Sub-Tlv found and successfully retrieved the Status\n
 *              E_NOT_OK:  No Status Sub-Tlv found or failed to retrieve the Status
 *  \pre        The Pointer to the FirstSubTlv and the SubTlvCount must have been retrieved using
 *              EthTSyn_GetFirstArSubTlvPtrAndCnt
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
#if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetStatusFromSubTlv(
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType)  FirstSubTlvPtr,
                  uint8                                SubTlvCount,
    ETHTSYN_P2VAR(StbM_TimeBaseStatusType)             StatusPtr);
#endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

/**********************************************************************************************************************
 *  EthTSyn_HandleOfsSubTlvs
 *********************************************************************************************************************/
/*! \brief      Unpacks all Ofs-Sub-Tlvs and forwards the new Offset to the StbM
 *  \param[in]  TimeDomainIdx   Index of the TimeDomain the FollowUp was received for
 *  \param[in]  FirstSubTlvPtr  Pointer to the first Ar Sub-Tlv
 *  \param[in]  SubTlvCount     The amount of the Ar Sub-Tlvs (including unknown Tlv-Types)
 *  \return     none
 *  \pre        The Pointer to the FirstSubTlv and the SubTlvCount must have been retrieved using
 *              EthTSyn_GetFirstArSubTlvPtrAndCnt
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
#if ((ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) && (ETHTSYN_OFS_TIME_DOMAIN_SUPPORT == STD_ON))
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_HandleOfsSubTlvs(
                  EthTSyn_TimeDomainIdxType            TimeDomainIdx,
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType)  FirstSubTlvPtr,
                  uint8                                SubTlvCount);
#endif /* ((ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) && (ETHTSYN_OFS_TIME_DOMAIN_SUPPORT == STD_ON)) */

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)
/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedSyncMsg
 *********************************************************************************************************************/
/*! \brief      Processing of a received Sync message
 *  \param[in]  ComMsgPtr                  Pointer to the common message header
 *  \param[in]  PortIdx                    Index of the Port the message was received on
 *  \param[in]  TimeDomainIdx              Index of the TimeDomain the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedSyncMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr,
                       EthTSyn_PortIdxType       PortIdx,
                       EthTSyn_TimeDomainIdxType TimeDomainIdx);
# endif /* (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedFollowUpMsg
 *********************************************************************************************************************/
/*! \brief      Processing of a received FollowUp message
 *  \param[in]  ComMsgPtr                  Pointer to the common message header
 *  \param[in]  PortIdx                    Index of the Port the message was received on
 *  \param[in]  TimeDomainIdx              Index of the TimeDomain the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedFollowUpMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr,
                       EthTSyn_PortIdxType       PortIdx,
                       EthTSyn_TimeDomainIdxType TimeDomainIdx);
# endif /* (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedAnnounceMsg
 *********************************************************************************************************************/
/*! \brief      Processing of a received Announce message
 *  \param[in]  ComMsgPtr       Pointer to the common message header
 *  \param[in]  LenByte         Payload length of the message in byte (passed to EthTSyn_RxIndication)
 *  \param[in]  PortIdx         Index of the Port the message was received on
 *  \param[in]  TimeDomainIdx   Index of the TimeDomain the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedAnnounceMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr,
                       uint16                    LenByte,
                       EthTSyn_PortIdxType       PortIdx,
                       EthTSyn_TimeDomainIdxType TimeDomainIdx);
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedPdelayReqMsg
 *********************************************************************************************************************/
/*! \brief      Processing of a received Pdelay request message
 *  \param[in]  ComMsgPtr                  Pointer to the common message header
 *  \param[in]  PortIdx                    Index of the Port the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedPdelayReqMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr,
                       EthTSyn_PortIdxType       PortIdx); /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedPdelayRespMsg
 *********************************************************************************************************************/
/*! \brief      Processing of a received Pdelay response message
 *  \param[in]  ComMsgPtr                  Pointer to the common message header
 *  \param[in]  PortIdx                    Index of the Port the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedPdelayRespMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr,
                       EthTSyn_PortIdxType       PortIdx); /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedRespFollowUpMsg
 *********************************************************************************************************************/
/*! \brief      Processing of a received Pdelay response FollowUp message
 *  \param[in]  ComMsgPtr                  Pointer to the common message header
 *  \param[in]  PortIdx                    Index of the Port the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedRespFollowUpMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr,
                       EthTSyn_PortIdxType       PortIdx);
# endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  EthTSyn_SetLocalClockIdentity
 *********************************************************************************************************************/
ETHTSYN_LOCAL FUNC(void, ETHTSYN_CODE) EthTSyn_SetLocalClockIdentity(EthTSyn_CtrlIdxType EthTSynCtrlIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Eth_PhysAddrType physAddr;

  /* ----- Implementation ----------------------------------------------- */
  ETHTSYN_CHECK_CRITICAL_SECTION_0();
  EthIf_GetPhysAddr(EthTSyn_CtrlConfig[EthTSynCtrlIdx].EthIfCtrlIdx, &physAddr[0]);

  EthTSyn_CtrlState[EthTSynCtrlIdx].ClockIdentity[0] = physAddr[0];
  EthTSyn_CtrlState[EthTSynCtrlIdx].ClockIdentity[1] = physAddr[1];
  EthTSyn_CtrlState[EthTSynCtrlIdx].ClockIdentity[2] = physAddr[2];
  EthTSyn_CtrlState[EthTSynCtrlIdx].ClockIdentity[3] = 0xFF;
  EthTSyn_CtrlState[EthTSynCtrlIdx].ClockIdentity[4] = 0xFE;
  EthTSyn_CtrlState[EthTSynCtrlIdx].ClockIdentity[5] = physAddr[3];
  EthTSyn_CtrlState[EthTSynCtrlIdx].ClockIdentity[6] = physAddr[4];
  EthTSyn_CtrlState[EthTSynCtrlIdx].ClockIdentity[7] = physAddr[5];
}

/**********************************************************************************************************************
 *  EthTSyn_ResetMasterPriorityVector
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ResetMasterPriorityVector(
  EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
  IpBase_Fill( (ETHTSYN_P2VAR(IpBase_CopyDataType))
    EthTSyn_SystemState[TimeDomainIdx].GmPriority.PortIdentity.ClockIdentity, 0, sizeof(EthTSyn_ClockIdentityType));
  EthTSyn_SystemState[TimeDomainIdx].GmPresent = FALSE;
}

/***********************************************************************************************************************
 *  EthTSyn_HtonTimestamp
 **********************************************************************************************************************/
ETHTSYN_LOCAL FUNC(void, ETHTSYN_CODE) EthTSyn_HtonTimestamp(
  ETHTSYN_P2VAR(EthTSyn_TimestampType) GlobalTimestampPtr,
  ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType) LocalTimestampPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  GlobalTimestampPtr->NanoSeconds[0] = (uint8)(LocalTimestampPtr->nanoseconds >> 24U);
  GlobalTimestampPtr->NanoSeconds[1] = (uint8)(LocalTimestampPtr->nanoseconds >> 16U);
  GlobalTimestampPtr->NanoSeconds[2] = (uint8)(LocalTimestampPtr->nanoseconds >> 8U);
  GlobalTimestampPtr->NanoSeconds[3] = (uint8)(LocalTimestampPtr->nanoseconds >> 0U);

  GlobalTimestampPtr->Seconds[0] = (uint8)(LocalTimestampPtr->secondsHi >> 8U);
  GlobalTimestampPtr->Seconds[1] = (uint8)(LocalTimestampPtr->secondsHi >> 0U);

  GlobalTimestampPtr->Seconds[2] = (uint8)(LocalTimestampPtr->seconds >> 24U);
  GlobalTimestampPtr->Seconds[3] = (uint8)(LocalTimestampPtr->seconds >> 16U);
  GlobalTimestampPtr->Seconds[4] = (uint8)(LocalTimestampPtr->seconds >> 8U);
  GlobalTimestampPtr->Seconds[5] = (uint8)(LocalTimestampPtr->seconds >> 0U);

}/* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  EthTSyn_QualifyAnnounceMsg
 **********************************************************************************************************************/
/*! \brief      Validation of Announce message
 *  \param[in]  PortIdx         Index of EthTSyn port that received the Announce message
 *  \param[in]  LenByte         Byte count of the received Announce message
 *  \param[in]  ComMsgPtr       Pointer to the EthTSyn common header of the Announce message
 *  \return     E_OK            Announce message is valid\n
 *              E_NOT_OK        Announce message is not valid\n
 *  \context    This function can be called in any context. Calling function must ensure that TimeDomainId is a 
 *              Slave Port
 *********************************************************************************************************************/
#if ( (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) )
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_QualifyAnnounceMsg(EthTSyn_PortIdxType PortIdx,
  uint16 LenByte, ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType) announceMsgPtr;
  ETHTSYN_P2CONST(EthTSyn_ClockIdentityType) pathSequenceClockIdentityPtr;
  ETHTSYN_P2CONST(uint8) comMsgU8Ptr;
  uint16 pathSequenceTlvCnt;
  uint16 assumedLenByte;
  uint16 stepsRemovedCnt;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(PortIdx >= ETHTSYN_PORT_COUNT)
  {
    errorId = ETHTSYN_E_PARAM;
  }
  else if(EthTSyn_CfgGetPortRole(PortIdx) != ETHTSYN_PORT_ROLE_SLAVE)
  {
    errorId = ETHTSYN_E_PARAM;
  }
  else
# endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* set message pointers */
    /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    comMsgU8Ptr = (ETHTSYN_P2CONST(uint8)) ComMsgPtr;
    announceMsgPtr = (ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType)) &comMsgU8Ptr[ETHTSYN_HDR_COM_LENGTH];

    /* get attributes of announce message */
    stepsRemovedCnt = (uint16)((uint16)announceMsgPtr->StepsRemoved[0] << 8U) |
      ((uint16)announceMsgPtr->StepsRemoved[1]);

    if((EthTSyn_Ntohs(announceMsgPtr->LengthField) % 8U) == 0)
    {
      pathSequenceTlvCnt = (uint16)(EthTSyn_Ntohs(announceMsgPtr->LengthField) / 8U);

      /* calculate assumed length including the tlv path sequence. Subtract the
      ETHTSYN_MSG_ANNOUNCE_PATH_SEQUENCE_ELEMENT_LENGTH because the length of one element is already included in the 
      ETHTSYN_MSG_ANNOUNCE_LENGTH */
      assumedLenByte = (uint16)(ETHTSYN_MSG_ANNOUNCE_LENGTH + ( EthTSyn_Ntohs(announceMsgPtr->LengthField) -
        ETHTSYN_MSG_ANNOUNCE_PATH_SEQUENCE_ELEMENT_LENGTH ));

      /* check that received Announce message is not from own system */
      /* PRQA S 3415, 0310 6 */ /* MD_EthTSyn_12.4 */ /* MD_EthTSyn_11.4 */
      if((ETHTSYN_COMPARE_EQUAL != EthTSyn_CompareClockIdentity(ComMsgPtr->SourceClockIdentity,
        ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx))) &&
        (ETHTSYN_COMPARE_EQUAL != EthTSyn_CompareClockIdentity(announceMsgPtr->ClockIdentity,
        ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx))) &&
        (LenByte >= assumedLenByte) &&
        (stepsRemovedCnt <= EthTSyn_SlavePortConfigPtr(PortIdx)->MaxStepsRemoved))
      {
        uint16_least i;
        retVal = E_OK;

        /* set message pointer to the clock identity of the path sequence */
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        pathSequenceClockIdentityPtr = (ETHTSYN_P2CONST(EthTSyn_ClockIdentityType))announceMsgPtr->ClockIdentity;
        for(i = 0; i < pathSequenceTlvCnt; i++)
        {
          if(ETHTSYN_COMPARE_EQUAL == EthTSyn_CompareClockIdentity(pathSequenceClockIdentityPtr[i],
            ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx)))
          {
            retVal = E_NOT_OK;
            break;
          }
        }
      }
    }
  }

# if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_QUALIFY_ANNOUNCE_MSG, errorId);
  }
# else
  ETHTSYN_DUMMY_STATEMENT(errorId);
# endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
} /* EthTSyn_QualifyAnnounceMsg() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L: STMIF */
#endif /* ( (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) ) */

#if (STD_ON == ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT)
/**********************************************************************************************************************
 *  EthTSyn_ComputePdelay
 *********************************************************************************************************************/
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_ComputePdelay(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  ETHTSYN_P2VAR(EthTSyn_PdelayReqSmType) pDelayReqSmPtr;

  /* ----- Implementation ----------------------------------------------- */
  if(PortIdx >= ETHTSYN_PORT_COUNT)
  {
    /* Invalid port index */
  }
  else if (EthTSyn_CfgAccess_IsPdelayInitiator(PortIdx) == FALSE)
  {
    /* No Pdelay Initiator */
  }
  else if (ETHTSYN_CFG_GET_P_DELAY_USE_STATIC(PortIdx) == TRUE)
  {
    /* Use static Pdelay -> No calculation of Pdelay required */
  }
  else
  {
    /* computes the mean propagation delay on the link (see also IEEE802.1AS-2011 Figure 11-1) */
    /* t1: Pdelay_Req egress timestamp (initiator), t2: Pdelay_Req ingress timestamp (responder) */
    /* t3: Pdelay_Resp egress timestamp (responder), t4: Pdelay_Resp ingress timestamp (initiator) */
    /*      (t4 - t1) - (t3 - t2)                      */
    /* D = ___________________________                 */
    /*              2                                  */
    EthTSyn_TimediffType localResidenceTime;
    EthTSyn_TimediffType remoteResidenceTime = 0;
    EthTSyn_TimediffType pDelay;  /* PRQA S 0781 */ /* MD_EthTSyn_5.6 */

    pDelayReqSmPtr = ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx);

# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    /* HW-Timestamping */
    localResidenceTime = 0;
    if(EthTSyn_TimestampMinusTimestamp(&ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->PdelayResp.IngressTimestamp,
      &ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->PdelayReq.EgressTimestamp, &localResidenceTime) == E_OK)
# else
    /* SW-Timestamping: Only 'raw' Timestamps are used for PdelayReq egress and PdelayResp ingress. These are stored
     * in the 'nanoseconds' field of the Timestamp */
    localResidenceTime = (EthTSyn_TimediffType)
      ((EthTSyn_TimediffType)pDelayReqSmPtr->PdelayResp.IngressTimestamp.nanoseconds -
      (EthTSyn_TimediffType)pDelayReqSmPtr->PdelayReq.EgressTimestamp.nanoseconds);
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
    {
      /* Successfully computed local residence time */
      if(EthTSyn_TimestampMinusTimestamp(&pDelayReqSmPtr->PdelayRespFollowUp.ResponseOriginTimestamp,
        &pDelayReqSmPtr->PdelayResp.RequestReceiptTimestamp, &remoteResidenceTime) == E_OK)
      {
        /* Successfully computed remote residence time --> calculate current path delay */
        pDelay = (localResidenceTime - remoteResidenceTime) / 2u;
        /* sanity check of path delay */
        if(pDelay >= 0u)
        {
# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
          if(pDelay < (EthTSyn_TimediffType)ETHTSYN_CFG_GET_P_DELAY_NEIGHBOR_DELAY_THRESHOLD_NS(PortIdx))
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
          {
            /* valid pDelay */
# if (ETHTSYN_P_DELAY_AVERAGE_SUPPORT == STD_ON)
            /* low pass filtering with weighted previous value for averaging */
            pDelayReqSmPtr->Pdelay = (EthTSyn_PdelayType)
              (((ETHTSYN_CFG_GET_P_DELAY_AVERAGE_WEIGHT(PortIdx) - 1) *
              pDelayReqSmPtr->Pdelay) + (EthTSyn_PdelayType)pDelay) / (ETHTSYN_CFG_GET_P_DELAY_AVERAGE_WEIGHT(PortIdx));
# else
            pDelayReqSmPtr->Pdelay = (EthTSyn_PdelayType)pDelay;
# endif /* (ETHTSYN_P_DELAY_AVERAGE_SUPPORT == STD_ON) */
            retVal = E_OK;
          }
        }
      }
    }

  }

  return retVal;
}/* EthTSyn_ComputePdelay() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
#endif /* (STD_ON == ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT) */

/**********************************************************************************************************************
 *  EthTSyn_IsSwitchPort
 *********************************************************************************************************************/
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_IsSwitchPort(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isSwitchPort = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  if(EthTSyn_GetPortType(PortIdx) == ETHTSYN_PORT_TYPE_SWITCH_PORT)
  {
    isSwitchPort = TRUE;
  }

  return isSwitchPort;
}
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_GetUserDataFromSubTlv
 *********************************************************************************************************************/
#if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetUserDataFromSubTlv(
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType) FirstSubTlvPtr, uint8 SubTlvCount,
  ETHTSYN_P2VAR(StbM_UserDataType) UserDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 subTlvCounter;
  uint16 currentOffsetFromFirstSubTlv = 0u;
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType) currentSubTlvPtr;

  /* ----- Implementation ----------------------------------------------- */
  for(subTlvCounter = 0; subTlvCounter < SubTlvCount; subTlvCounter++)
  {
    /* Set current sub tlv pointer */
    /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    currentSubTlvPtr = (ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType))
      &((ETHTSYN_P2CONST(uint8))FirstSubTlvPtr)[currentOffsetFromFirstSubTlv];
    currentOffsetFromFirstSubTlv += ETHTSYN_AR_SUB_TLV_ABSTRACT_HDR_LENGTH;
    currentOffsetFromFirstSubTlv += currentSubTlvPtr->Length;

    /* Check if Sub-Tlv is UserData Tlv as required */
    if((currentSubTlvPtr->Type == ETHTSYN_AR_SUB_TLV_TYPE_USER_DATA_NOT_SECURED) ||
      (currentSubTlvPtr->Type == ETHTSYN_AR_SUB_TLV_TYPE_USER_DATA_SECURED))
    {
      /* UserData Tlv-found -> store the UserData */
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      ETHTSYN_P2CONST(EthTSyn_ArSubTlvUserDataType) userDataTlvPtr =
        (ETHTSYN_P2CONST(EthTSyn_ArSubTlvUserDataType))currentSubTlvPtr;

      UserDataPtr->userDataLength = userDataTlvPtr->UserDataLength;
      UserDataPtr->userByte0 = userDataTlvPtr->UserByte0;
      UserDataPtr->userByte1 = userDataTlvPtr->UserByte1;
      UserDataPtr->userByte2 = userDataTlvPtr->UserByte2;

      retVal = E_OK;

      break; /* UserData found and retrieved -> Stop iteration of Sub-Tlvs */
    }
  }

  return retVal;
} /* EthTSyn_GetUserDataFromSubTlv() */
#endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

/**********************************************************************************************************************
 *  EthTSyn_GetStatusFromSubTlv
 *********************************************************************************************************************/
#if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetStatusFromSubTlv(
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType) FirstSubTlvPtr, uint8 SubTlvCount,
  ETHTSYN_P2VAR(StbM_TimeBaseStatusType) StatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 subTlvCounter;
  uint16 currentOffsetFromFirstSubTlv = 0u;
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType) currentSubTlvPtr;

  /* ----- Implementation ----------------------------------------------- */
  for(subTlvCounter = 0; subTlvCounter < SubTlvCount; subTlvCounter++)
  {
    /* Set current sub tlv pointer */
    /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    currentSubTlvPtr = (ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType))
      &((ETHTSYN_P2CONST(uint8))FirstSubTlvPtr)[currentOffsetFromFirstSubTlv];
    currentOffsetFromFirstSubTlv += ETHTSYN_AR_SUB_TLV_ABSTRACT_HDR_LENGTH;
    currentOffsetFromFirstSubTlv += currentSubTlvPtr->Length;

    /* Check if Sub-Tlv is Status Tlv as required */
    if((currentSubTlvPtr->Type == ETHTSYN_AR_SUB_TLV_TYPE_STATUS_NOT_SECURED) ||
      (currentSubTlvPtr->Type == ETHTSYN_AR_SUB_TLV_TYPE_STATUS_SECURED))
    {
      /* Status Tlv-found -> store the Status */
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      ETHTSYN_P2CONST(EthTSyn_ArSubTlvStatusType) statusTlvPtr =
        (ETHTSYN_P2CONST(EthTSyn_ArSubTlvStatusType))currentSubTlvPtr;

      *StatusPtr = statusTlvPtr->Status;

      retVal = E_OK;

      break; /* Status found and retrieved -> Stop iteration of Sub-Tlvs */
    }
  }

  return retVal;
} /* EthTSyn_GetStatusFromSubTlv() */
#endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

/**********************************************************************************************************************
 *  EthTSyn_HandleOfsSubTlvs
 *********************************************************************************************************************/
#if ((ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) && (ETHTSYN_OFS_TIME_DOMAIN_SUPPORT == STD_ON))
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_HandleOfsSubTlvs(EthTSyn_TimeDomainIdxType TimeDomainIdx,
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType) FirstSubTlvPtr, uint8 SubTlvCount)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 subTlvCounter;
  uint8_least ofsTimeDomainCounter;
  ETHTSYN_P2CONST(EthTSyn_OfsTimeDomainConfigType) ofsTimeDomainPtr =
    ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_PTR(TimeDomainIdx);
  uint16 currentOffsetFromFirstSubTlv = 0u;
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType) currentSubTlvPtr;

  /* ----- Implementation ----------------------------------------------- */
  if(ofsTimeDomainPtr != NULL_PTR)
  {
    for(subTlvCounter = 0; subTlvCounter < SubTlvCount; subTlvCounter++)
    {
      /* Set current sub tlv pointer */ /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      currentSubTlvPtr = (ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType))
        &((ETHTSYN_P2CONST(uint8))FirstSubTlvPtr)[currentOffsetFromFirstSubTlv];
      currentOffsetFromFirstSubTlv += ETHTSYN_AR_SUB_TLV_ABSTRACT_HDR_LENGTH;
      currentOffsetFromFirstSubTlv += currentSubTlvPtr->Length;

      /* Check if Sub-Tlv is Ofs Tlv */
      if((currentSubTlvPtr->Type == ETHTSYN_AR_SUB_TLV_TYPE_OFS_NOT_SECURED) ||
        (currentSubTlvPtr->Type == ETHTSYN_AR_SUB_TLV_TYPE_OFS_SECURED))
      {
        /* Ofs Tlv-found */
        ETHTSYN_P2CONST(EthTSyn_ArSubTlvOfsType) ofsTlvPtr =
          (ETHTSYN_P2CONST(EthTSyn_ArSubTlvOfsType))currentSubTlvPtr; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

        /* Check if offset time domain is valid for the TimeDomain of the FollowUp */
        for(ofsTimeDomainCounter = 0; ofsTimeDomainCounter < ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_COUNT(TimeDomainIdx);
          ofsTimeDomainCounter++)
        {
          if(ofsTlvPtr->OfsTimeDomain == ofsTimeDomainPtr[ofsTimeDomainCounter].OfsTimeDomainId)
          {
            /* Matching Offset TimeDomain found -> Forward new offset to StbM */
            StbM_TimeStampType timeStamp;
            StbM_UserDataType userData;
            boolean syncToTimeBase = FALSE;

            ETHTSYN_AR_SUB_TLV_STATUS_TO_TIME_BASE_STATUS(ofsTlvPtr->Status, timeStamp.timeBaseStatus);
            
            ETHTSYN_GET_UINT16(ofsTlvPtr->OfsTimeSec, 0u, timeStamp.secondsHi);
            ETHTSYN_GET_UINT32(ofsTlvPtr->OfsTimeSec, 2u, timeStamp.seconds); /* Offset 2 due to 'secondHi' */
            ETHTSYN_GET_UINT32(ofsTlvPtr->OfsTimeNSec, 0u, timeStamp.nanoseconds);

            userData.userDataLength = ofsTlvPtr->UserDataLength;
            userData.userByte0 = ofsTlvPtr->UserByte0;
            userData.userByte1 = ofsTlvPtr->UserByte1;
            userData.userByte2 = ofsTlvPtr->UserByte2;

            if((timeStamp.timeBaseStatus & ETHTSYN_TIME_BASE_STATUS_SYNC_TO_GW_MASK) != 0)
            {
              syncToTimeBase = TRUE;
            }

            (void)StbM_BusSetGlobalTime(ofsTimeDomainPtr[ofsTimeDomainCounter].SynchronizedTimeBaseId, &timeStamp,
              &userData, syncToTimeBase);

            break;
          }
        }
      }
    }
  }

} /* EthTSyn_HandleOfsSubTlvs() */
/* PRQA L: STMIF */
#endif /* ((ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) && (ETHTSYN_OFS_TIME_DOMAIN_SUPPORT == STD_ON)) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedSyncMsg
 *********************************************************************************************************************/
#if ( (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) )
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedSyncMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr, EthTSyn_PortIdxType PortIdx,
  EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_SyncReceiveSmType) syncReceiveSmPtr;
# if ( (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) )
  uint8 errorId = ETHTSYN_E_NO_ERROR;
# endif /* ( (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) ) */

  /* ----- Implementation ----------------------------------------------- */
# if (ETHTSYN_TIME_MASTER_SUPPORT == STD_ON)
  if(EthTSyn_CfgGetPortRole(PortIdx) == ETHTSYN_PORT_ROLE_SLAVE)
# endif /* (ETHTSYN_TIME_MASTER_SUPPORT == STD_ON) */
  {
    /* Check if port is AsCapable if required */
# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
    if(ETHTSYN_GET_AS_CAPABLE(PortIdx) == TRUE)
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
    {
      /* Get Sync receive state machine Pointer */
      syncReceiveSmPtr = ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
      /* Get required Timestamps */
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
      /* HW-Timestamping */
      {
        Eth_TimestampQualityType timestampQuality;
        syncReceiveSmPtr->Sync.IngressTimestampState =
          ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_NOT_AVAILABLE;

        ETHTSYN_CHECK_CRITICAL_SECTION_0();
        /* PRQA S 0310, 0311 2 */ /* MD_EthTSyn_11.4, MD_EthTSyn_11.5 */
        if(EthIf_GetIngressTimeStamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), (ETHTSYN_P2VAR(Eth_DataType))ComMsgPtr,
          &timestampQuality, &syncReceiveSmPtr->Sync.IngressTimestamp) == E_OK)
        {
          if(timestampQuality == ETH_VALID)
          {
            syncReceiveSmPtr->Sync.IngressTimestampState =
              ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
          }
        }
      }
# else
      /* SW-Timestamping */
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      if(StbM_GetCurrentTimeRaw(&syncReceiveSmPtr->Sync.IngressTimestamp.nanoseconds) == E_OK)
      {
        syncReceiveSmPtr->Sync.IngressTimestampState =
          ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
      }
      else
      {
        syncReceiveSmPtr->Sync.IngressTimestampState =
          ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_NOT_AVAILABLE;
      }
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      /* Check sync receive state machine state */
      if((syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_DISCARD) ||
        (syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_SYNC))
      {
# if ((ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON))
        boolean receiveMsg = FALSE;
# endif /* ((ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)) */

# if (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON)
        /* Check if source port identity check is enabled */
        if(EthTSyn_CfgGetEnableSourcePortIdentityCheck(PortIdx) == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        {
          /* Verify source port identity */
          if(EthTSyn_CheckSourcePortIdentity(ComMsgPtr, PortIdx) == TRUE)
          {
            /* Source port identity valid --> receive message */
            receiveMsg = TRUE;
          }
          else
          {
            errorId = ETHTSYN_E_SRC_PORT_IDENT_CHECK_FAILED;
          }
        }
# endif /* (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) */

# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
        /* Check if Announce is enabled */
        if(EthTSyn_CfgGetEnableAnnounce(PortIdx) == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        {
          /* Validate System State */
          if(EthTSyn_CheckAnnounce(ComMsgPtr, TimeDomainIdx) == TRUE)
          {
            /* Announce check passed -> receive message */
            receiveMsg = TRUE;
          }
          else
          {
            errorId = ETHTSYN_E_ANNOUNCE_CHECK_FAILED;
          }
        }
# else
        ETHTSYN_DUMMY_STATEMENT(TimeDomainIdx); /* PRQA S 3112 */ /* MD_MSR_14.2 */
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

# if ((ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON))
        if(receiveMsg == TRUE)
# endif /* ((ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)) */
        {
          /* Set Sync message attributes */
          syncReceiveSmPtr->Sync.LogMessageInterval = ComMsgPtr->LogMessageInterval;

          EthTSyn_SetClockIdentity(syncReceiveSmPtr->Sync.SourcePortIdentity.ClockIdentity,
            ComMsgPtr->SourceClockIdentity);

          syncReceiveSmPtr->Sync.SourcePortIdentity.PortNumber = (EthTSyn_PortNumberType)
            EthTSyn_Ntohs(ComMsgPtr->SourcePortNumber);

          syncReceiveSmPtr->Sync.SequenceId = (uint16)EthTSyn_Ntohs(ComMsgPtr->SequenceId);

          /* Set FollowUp receive timeout if required */
          if(EthTSyn_SlavePortConfigPtr(PortIdx)->FollowUpAllowedRxDelay > 0u) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
          {
            syncReceiveSmPtr->FollowUp.FollowUpRxTimeoutCnt =
              EthTSyn_SlavePortConfigPtr(PortIdx)->FollowUpAllowedRxDelay; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
          }

          /* Change state to waiting for FollowUp */
          syncReceiveSmPtr->State = ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_FOLLOW_UP;
        }
      }
      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
# if ( (ETHTSYN_TIME_MASTER_SUPPORT == STD_ON) && (ETHTSYN_MASTER_SLAVE_CONFLICT_DETECTION == STD_ON) )
  else
  {
    ETHTSYN_CALL_DET_REPORT_RUNTIME_ERROR();
  }
# endif /* ( (ETHTSYN_TIME_MASTER_SUPPORT == STD_ON) && (ETHTSYN_MASTER_SLAVE_CONFLICT_DETECTION == STD_ON) ) */

# if ( (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) )
#  if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_PROCESS_RECEIVED_SYNC, errorId);
  }
#  else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#  endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */
# endif /* ( (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) ) */
} /* EthTSyn_ProcessReceivedSyncMsg() */
/* PRQA L: STMIF */
#endif /* ( (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) ) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedFollowUpMsg
 *********************************************************************************************************************/
#if ( (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) )
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedFollowUpMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr, EthTSyn_PortIdxType PortIdx,
  EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_SyncReceiveSmType) syncReceiveSmPtr;

  /* ----- Implementation ----------------------------------------------- */
# if (ETHTSYN_TIME_MASTER_SUPPORT == STD_ON)
  if(EthTSyn_CfgGetPortRole(PortIdx) == ETHTSYN_PORT_ROLE_SLAVE)
# endif /* (ETHTSYN_TIME_MASTER_SUPPORT == STD_ON) */
  {
    syncReceiveSmPtr = ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

    /* Check sync receive state machine state and matching sequence id */
    if((syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_FOLLOW_UP) &&
      (syncReceiveSmPtr->Sync.SequenceId == (uint16)EthTSyn_Ntohs(ComMsgPtr->SequenceId)))
    {
      /* Waiting for FollowUp + matching Sequence Id -> continue message processing */

      /* Check for matching source port identity */
      /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
      if(EthTSyn_PortIdentityIsEqual(
        (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))&syncReceiveSmPtr->Sync.SourcePortIdentity,
        (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))ComMsgPtr->SourceClockIdentity) == TRUE)
      {
        /* Matching source port identity -> continue message processing */
        ETHTSYN_P2CONST(EthTSyn_FollowUpMsgType) followUpMsgPtr;
        EthTSyn_GlobalTimestampType timeStamp; /* used to call StbM_BusSetGlobalTime */
        EthTSyn_TimediffType timeDiff = 0;
        EthTSyn_PdelayType pDelay = 0;
        boolean callBusSetGlobalTime = FALSE;
        ETHTSYN_P2CONST(StbM_UserDataType) userDataPtr = NULL_PTR;
        StbM_TimeBaseStatusType status = 0;
# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
        ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType) firstSubTlvPtr = NULL_PTR;
        uint8 subTlvCnt = 0;
        StbM_UserDataType userData;
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
        EthTSyn_GlobalTimestampType timeStampRef; /* used as reference Timestamp when HW-Timestamping is used */
        Eth_TimestampQualityType timeStampQual;
# else
        EthTSyn_TimestampRawType timeStampDiff; /* used to show the time passed between Sync and FollowUp reception */
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
        if(EthTSyn_GetFirstArSubTlvPtrAndCnt(PortIdx, ComMsgPtr, &firstSubTlvPtr, &subTlvCnt) == E_OK)
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */
        {
          /* Get FollowUp message pointer */
          /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          followUpMsgPtr = (ETHTSYN_P2CONST(EthTSyn_FollowUpMsgType))
            &((ETHTSYN_P2CONST(uint8))ComMsgPtr)[ETHTSYN_HDR_COM_LENGTH];

          /* Get the precise origin timestamp from followUp message */
          /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          EthTSyn_NtohTimestamp(&timeStamp,
            (ETHTSYN_P2CONST(EthTSyn_TimestampType))followUpMsgPtr->PreciseOriginTimestampSeconds);

# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
          /* Get Tlv-Information */
          if(EthTSyn_GetUserDataFromSubTlv(firstSubTlvPtr, subTlvCnt, &userData) == E_OK)
          {
            userDataPtr = &userData;
          }
          if(EthTSyn_GetStatusFromSubTlv(firstSubTlvPtr, subTlvCnt, &status) == E_NOT_OK)
          {
            status = 0;
          }
#  if (ETHTSYN_OFS_TIME_DOMAIN_SUPPORT == STD_ON)
          EthTSyn_HandleOfsSubTlvs(ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(PortIdx), firstSubTlvPtr, subTlvCnt);
#  endif /* (ETHTSYN_OFS_TIME_DOMAIN_SUPPORT == STD_ON) */
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
          /* HW-Timestamping */
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          if(EthIf_GetCurrentTime(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), &timeStampQual, &timeStampRef) == E_OK)
          {
            if(timeStampQual == ETH_VALID)
            {
              /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
              if(EthTSyn_TimestampMinusTimestamp(&timeStampRef,
                &ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx)->Sync.IngressTimestamp, &timeDiff) == E_OK)
              {
                callBusSetGlobalTime = TRUE;
              }
            }
          }
# else
          /* SW-Timestamping */
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
          if(StbM_GetCurrentTimeDiff(ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx)->Sync.IngressTimestamp.nanoseconds,
            &timeStampDiff) == E_OK)
          {
            timeDiff = (EthTSyn_TimediffType)timeStampDiff;
            callBusSetGlobalTime = TRUE;
          }
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
          if(callBusSetGlobalTime == TRUE)
          {
            /* Add pDelay and correctionField to the timeDiff */
            if(EthTSyn_GetCurrentPdelay(PortIdx, &pDelay) == E_OK)
            {
              timeDiff += (EthTSyn_TimediffType)pDelay;
            }
            timeDiff += (EthTSyn_TimediffType)
              ETHTSYN_GET_FOLLOW_UP_CORRECTION_VALUE_NS_FROM_MSG(ComMsgPtr->CorrectionField);

            if(EthTSyn_TimestampPlusTimediff(&timeStamp, (ETHTSYN_P2CONST(EthTSyn_TimediffType))&timeDiff) == E_OK)
            {
              StbM_TimeStampType timeStampStbm;
              boolean syncToTimeBase = FALSE;

              ETHTSYN_COPY_GLOBAL_TS_TO_STBM_TS_W_TBS(timeStamp, timeStampStbm, status)
# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
              if((status & ETHTSYN_TIME_BASE_STATUS_SYNC_TO_GW_MASK) != 0)
              {
                syncToTimeBase = TRUE;
              }
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

              ETHTSYN_CHECK_CRITICAL_SECTION_0();
              (void)StbM_BusSetGlobalTime(ETHTSYN_CFG_GET_SYNCHRONIZED_TIME_BASE_ID(TimeDomainIdx),
                (ETHTSYN_P2CONST(StbM_TimeStampType))&timeStampStbm, userDataPtr, syncToTimeBase);
            }
          }

          syncReceiveSmPtr->State = ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_SYNC;
        }
      }
    }

  }

} /* EthTSyn_ProcessReceivedFollowUpMsg() */
/* PRQA L: STCYC */
/* PRQA L: STCAL */
/* PRQA L: STMIF */
#endif /* ( (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) ) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedAnnounceMsg
 *********************************************************************************************************************/
#if ( (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) )
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedAnnounceMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr, uint16 LenByte, EthTSyn_PortIdxType PortIdx,
  EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType) announceMsgPtr;

  /* ----- Implementation ----------------------------------------------- */
  ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* Check if the given Port is a Slave Port */
  if(EthTSyn_CfgGetPortRole(PortIdx) == ETHTSYN_PORT_ROLE_SLAVE)
  {
    /* Check if Port is AsCapable */
    if(ETHTSYN_GET_AS_CAPABLE(PortIdx) == TRUE)
    {
      /* Check if Announce is enabled for the Port */
      if(EthTSyn_CfgGetEnableAnnounce(PortIdx) == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
      {
        /* Validated the Announce Message */
        if(EthTSyn_QualifyAnnounceMsg(PortIdx, LenByte, ComMsgPtr) == E_OK)
        {
          /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          announceMsgPtr = (ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType))&
            ((ETHTSYN_P2CONST(uint8))ComMsgPtr)[ETHTSYN_HDR_COM_LENGTH];

          /* Reset announce timeout */ /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          ETHTSYN_ANNOUNCE_RECEIVE_SM_PTR(PortIdx)->RxTimeoutCnt =
            EthTSyn_SlavePortConfigPtr(PortIdx)->AnnounceAllowedRxDelay;

          /* Check if no Grandmaster is available */
          if(EthTSyn_SystemState[TimeDomainIdx].GmPresent == FALSE)
          {
            EthTSyn_SetMasterPriorityVector(announceMsgPtr, TimeDomainIdx);
          }
        }
      }
    }
  }
  ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

} /* EthTSyn_ProcessReceivedAnnounceMsg() */
/* PRQA L: STMIF */
#endif /* ( (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) ) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedPdelayReqMsg
 *********************************************************************************************************************/
#if ( (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) )
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedPdelayReqMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr, EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_PdelayRespSmType) pDelayRespSmPtr;
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
  Eth_TimestampQualityType    timestampQual;
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
  if(PortIdx == ETHTSYN_CFG_GET_P_DELAY_CFG(PortIdx).ActivePortIdx)
  {
    /* Only process the Pdelay Request message if it was received on the EthTSyn Port which is used for Pdelay */
    if(EthTSyn_CfgAccess_IsPdelayResponder(PortIdx) == TRUE)
    {
      /* Pdelay responder is enabled -> continue message processing */
      pDelayRespSmPtr = ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx);
      
      /* Get the ingress timestamp */
      pDelayRespSmPtr->PdelayReq.IngressTimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_NOT_AVAILABLE;
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      /* PRQA S 0310, 0311 2 */ /* MD_EthTSyn_11.4, MD_EthTSyn_11.5 */
      if(EthIf_GetIngressTimeStamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), (ETHTSYN_P2VAR(Eth_DataType))ComMsgPtr,
        &timestampQual, &pDelayRespSmPtr->PdelayReq.IngressTimestamp) == E_OK)
      {
        if(timestampQual == ETH_VALID)
        {
          pDelayRespSmPtr->PdelayReq.IngressTimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
        }
      }
# else
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      if(StbM_GetCurrentTimeRaw(&pDelayRespSmPtr->PdelayReq.IngressTimestamp.nanoseconds) == E_OK)
      {
        pDelayRespSmPtr->PdelayReq.IngressTimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
      }
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      /* Only proceed if ingress timestamp is available */
      if(pDelayRespSmPtr->PdelayReq.IngressTimestampState == ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE)
      {
        /* Check Pdelay response state machine state */
        if((pDelayRespSmPtr->State == ETHTSYN_STATE_P_DELAY_RESP_INITAIL_WAITING_FOR_PDELAY_REQ) ||
          (pDelayRespSmPtr->State == ETHTSYN_STATE_P_DELAY_RESP_WAITING_FOR_PDELAY_REQ) ||
          (pDelayRespSmPtr->State == ETHTSYN_STATE_P_DELAY_RESP_SEND_P_DELAY_RESP_FOLLOW_UP))
        {
          /* Store message attributes */

          /* Store Requesting source port identity */
          EthTSyn_SetClockIdentity(pDelayRespSmPtr->PdelayReq.SourcePortIdentity.ClockIdentity,
            ComMsgPtr->SourceClockIdentity);
          pDelayRespSmPtr->PdelayReq.SourcePortIdentity.PortNumber = (EthTSyn_PortNumberType)
            EthTSyn_Ntohs(ComMsgPtr->SourcePortNumber);

          /* Store sequence id */
          pDelayRespSmPtr->PdelayReq.SequenceId = (uint16)EthTSyn_Ntohs(ComMsgPtr->SequenceId);

          /* Change Pdelay response state machine state */
          pDelayRespSmPtr->State = ETHTSYN_STATE_P_DELAY_RESP_SEND_P_DELAY_RESP;
        }
      }
      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
  
} /* EthTSyn_ProcessReceivedPdelayReqMsg() */
#endif /* ( (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) ) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedPdelayRespMsg
 *********************************************************************************************************************/
#if ( (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) )
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedPdelayRespMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr, EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_PdelayReqSmType) pDelayReqSmPtr;
  ETHTSYN_P2CONST(EthTSyn_PdelayRespMsgType) pDelayRespMsgPtr;
  boolean lostResponse = FALSE;
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
  Eth_TimestampQualityType timestampQual = ETH_INVALID;
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
  /* ----- Implementation ----------------------------------------------- */
  if(EthTSyn_CfgAccess_IsActivePdelayPort(PortIdx) == TRUE)
  {
    /* Only process the Pdelay Response message if it was received on the EthTSyn Port which is used for Pdelay */
    if(EthTSyn_CfgAccess_IsPdelayInitiator(PortIdx) == TRUE)
    {
      /* Pdelay initiator is enabled -> continue message processing */
      pDelayReqSmPtr = ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx);
      
      /* Get Ingress timestamp */
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
      /* HW-Timestamping */
      pDelayReqSmPtr->PdelayResp.IngressTimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_NOT_AVAILABLE;
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      /* PRQA S 0310, 0311 2 */ /* MD_EthTSyn_11.4, MD_EthTSyn_11.5 */
      if(EthIf_GetIngressTimeStamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), (ETHTSYN_P2VAR(Eth_DataType))ComMsgPtr,
        &timestampQual, &pDelayReqSmPtr->PdelayResp.IngressTimestamp) == E_OK)
      {
        if(timestampQual == ETH_VALID)
        {
          pDelayReqSmPtr->PdelayResp.IngressTimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
        }
      }
# else
      /* SW-Timestamping */
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      if(StbM_GetCurrentTimeRaw(&pDelayReqSmPtr->PdelayResp.IngressTimestamp.nanoseconds) == E_OK)
      {
        pDelayReqSmPtr->PdelayResp.IngressTimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
      }
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      if(pDelayReqSmPtr->PdelayResp.IngressTimestampState == ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE)
      {
        /* Check Pdelay request state machine state */
        if(pDelayReqSmPtr->State == ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP)
        {
          /* Waiting for Pdelay response -> continue message processing */
          /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          pDelayRespMsgPtr = (ETHTSYN_P2CONST(EthTSyn_PdelayRespMsgType))
            &((ETHTSYN_P2CONST(uint8))ComMsgPtr)[ETHTSYN_HDR_COM_LENGTH];
        
          /* Check for matching Sequence ID and requesting source port identity */
          /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
          if((EthTSyn_PortIdentityIsEqualLocalPort(PortIdx,
            (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))pDelayRespMsgPtr->RequestingClockIdentity) == TRUE) &&
            ((uint16)EthTSyn_Ntohs(ComMsgPtr->SequenceId) == pDelayReqSmPtr->PdelayReq.SequenceId))
          {
            /* Store message attributes */
            pDelayReqSmPtr->PdelayResp.SequenceId = (uint16)EthTSyn_Ntohs(ComMsgPtr->SequenceId);
            EthTSyn_SetClockIdentity(pDelayReqSmPtr->PdelayResp.SourcePortIdentity.ClockIdentity,
              ComMsgPtr->SourceClockIdentity);
            pDelayReqSmPtr->PdelayResp.SourcePortIdentity.PortNumber = (EthTSyn_PortNumberType)
              EthTSyn_Ntohs(ComMsgPtr->SourcePortNumber);
            /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
            EthTSyn_NtohTimestamp(&pDelayReqSmPtr->PdelayResp.RequestReceiptTimestamp,
              (ETHTSYN_P2VAR(EthTSyn_TimestampType))pDelayRespMsgPtr->RequestReceiptTimestampSeconds);

            /* Change state of the pdelay request state machine */
            pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP_FOLLOW_UP;
          }
          else
          {
            lostResponse = TRUE;
          }
        }
        /* Check for double Pdelay response */
        else if(pDelayReqSmPtr->State == ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP_FOLLOW_UP)
        {
          if(pDelayReqSmPtr->PdelayReq.SequenceId == (uint16)EthTSyn_Ntohs(ComMsgPtr->SequenceId))
          {
            /* Received Pdelay response with same sequence id twice -> lost response */
            lostResponse = TRUE;
          }
        }
        else
        {
          /* Nothing to do here (MISRA) */
        }

        if(lostResponse == TRUE)
        {
# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
          /* Invalid message attributes -> treat as lost response */
          if(pDelayReqSmPtr->LostResponses < ETHTSYN_CFG_GET_P_DELAY_ALLOWED_LOST_RESPONSES(PortIdx))
          {
            pDelayReqSmPtr->LostResponses++;
          }
          else
          {
            /* Lost response limit exceeded -> Mark as not AsCapable if port is not set to 'AlwaysAsCapable' */
            ETHTSYN_SET_AS_CAPABLE(PortIdx, ETHTSYN_CFG_GET_ALWAYS_AS_CAPABLE(PortIdx));
          }
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */

          /* Trigger re-transmission of the pdelay request */
          pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_SEND_P_DELAY_REQ;
        }
      }
      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    }
  }
} /* EthTSyn_ProcessReceivedPdelayRespMsg() */
/* PRQA L: STCYC */
/* PRQA L: STCAL */
/* PRQA L: STMIF */
#endif /* ( (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) ) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessReceivedRespFollowUpMsg
 *********************************************************************************************************************/
#if ( (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) )
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessReceivedRespFollowUpMsg(
  ETHTSYN_CONSTP2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr, EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_PdelayReqSmType) pDelayReqSmPtr;
  ETHTSYN_P2CONST(EthTSyn_PDelayResFollowUpMsgType) pDelayRespFollowUpMsgPtr;

  /* ----- Implementation ----------------------------------------------- */
  if(EthTSyn_CfgAccess_IsActivePdelayPort(PortIdx) == TRUE)
  {
    /* Only process the PdelayRespFup message if it was received on the EthTSyn Port which is used for Pdelay */
    if(EthTSyn_CfgAccess_IsPdelayInitiator(PortIdx) == TRUE)
    {
      /* Pdelay initiator is enabled -> continue message processing */
      /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
      pDelayReqSmPtr = ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx);
      pDelayRespFollowUpMsgPtr = (ETHTSYN_P2CONST(EthTSyn_PDelayResFollowUpMsgType))
        &((ETHTSYN_P2CONST(uint8))ComMsgPtr)[ETHTSYN_HDR_COM_LENGTH];

      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      /* Check State of Pdelay Request state machine */
      if(pDelayReqSmPtr->State == ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP_FOLLOW_UP)
      {
        /* Waiting for Pdelay response follow up -> continue processing */
        /* Check message attributes (Sequence Id, Matching Port Identity for PdelayResp and PdelayRespFollowUp,
         * Matching Requesting Port Identity) */
        /* Check Sequnce Id */
        if((uint16)EthTSyn_Ntohs(ComMsgPtr->SequenceId) == pDelayReqSmPtr->PdelayReq.SequenceId)
        {
          /* Check Source Port Identity */
          /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
          if(EthTSyn_PortIdentityIsEqual(
            (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))&pDelayReqSmPtr->PdelayResp.SourcePortIdentity,
            (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))ComMsgPtr->SourceClockIdentity) == TRUE)
          {
            /* Check Requesting Port Identity */
            /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
            if(EthTSyn_PortIdentityIsEqualLocalPort(PortIdx,
              (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))pDelayRespFollowUpMsgPtr->RequestingClockIdentity) ==
              TRUE)
            {
              /* store message attributes */
              /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
              EthTSyn_NtohTimestamp(&pDelayReqSmPtr->PdelayRespFollowUp.ResponseOriginTimestamp,
                (ETHTSYN_P2VAR(EthTSyn_TimestampType))pDelayRespFollowUpMsgPtr->ResponseOriginTimestampSeconds);

# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
              /* Reset lost responses */
              pDelayReqSmPtr->LostResponses = 0u;
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */

              /* valid PdelayResp and PdelayRespFollowUp were received -> path delay calculation in MainFunction
              * context is possible, after PdelayReq message was transmitted successfully (indicated by
              * TxConfirmationPending flag)*/

              pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_RECEIVED_PDELAY_RESP_AND_PDELAY_RESP_FOLLOW_UP;
            }
          }
        }
      }
      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

} /* EthTSyn_ProcessReceivedRespFollowUpMsg() */
/* PRQA L: STMIF */
#endif /* ( (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) ) */

/**********************************************************************************************************************
 *  EthTSyn_TxPdelayRespFollowUpMsg
 *********************************************************************************************************************/
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxPdelayRespFollowUpMsg(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(uint8) txBufU8Ptr;
  ETHTSYN_P2VAR(EthTSyn_PDelayResFollowUpMsgType) pDelayRespFollowUpPtr;
  ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType) comMsgPtr;
  ETHTSYN_P2VAR(EthTSyn_PdelayRespSmType) pDelayRespSmPtr = ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx);
  uint8 bufIdx;
  Std_ReturnType retVal = E_NOT_OK;
  uint16 lenByte = ETHTSYN_MSG_P_DELAY_RESP_FOLLOW_UP_LENGTH;
#if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_OFF)
  EthTSyn_GlobalTimestampType pDelayRespEgressTimestamp;
#endif
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
  EthSwt_MgmtInfoType mgmtInfo;
  ETHTSYN_P2CONST(EthSwt_MgmtInfoType) mgmtInfoPtr = NULL_PTR;
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
  if(EthTSyn_IsTxReady(PortIdx) == TRUE)
  {
    if(EthTSyn_IsTimestampReadyToProcess(pDelayRespSmPtr->PdelayResp.EgressTimestampState) == TRUE)
    {
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      if(EthIf_ProvideTxBuffer(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), ETHTSYN_FRAME_TYPE,
        ETHTSYN_CFG_GET_FRAME_PRIORITY(PortIdx), &bufIdx, (ETHTSYN_P2VAR(Eth_DataType*)) &txBufU8Ptr,
        &lenByte) == BUFREQ_OK)
      {
        ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        /* set message pointers */
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        comMsgPtr = (ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType))txBufU8Ptr;
        pDelayRespFollowUpPtr = (ETHTSYN_P2VAR(EthTSyn_PDelayResFollowUpMsgType))&txBufU8Ptr[ETHTSYN_HDR_COM_LENGTH];

        /* set common header message attributes */
        comMsgPtr->TransSpecific_MessageType =
          ETHTSYN_HDR_COM_TRANSPORT_SPECIFIC | ETHTSYN_MSG_TYPE_PDELAY_RES_FOLLOW_UP;
        comMsgPtr->Reserved_VersionGPtp = ETHTSYN_PROTOCOL_VERSION;

        comMsgPtr->MessageLength = EthTSyn_Htons(ETHTSYN_MSG_P_DELAY_RESP_FOLLOW_UP_LENGTH); /*lint !e572 */
        comMsgPtr->DomainNumber = EthTSyn_PortConfig[PortIdx].TimeDomainId;

        comMsgPtr->Reserved_0 = 0;
        comMsgPtr->Flags = EthTSyn_Htons(ETHTSYN_FLAGS_TWO_STEP); /*lint !e572 */

        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))comMsgPtr->CorrectionField, 0,
          sizeof(EthTSyn_CorrectionFieldType));

        /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
        IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))comMsgPtr->Reserved_1, 0, 4);

        EthTSyn_SetClockIdentity(comMsgPtr->SourceClockIdentity, ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx));
        comMsgPtr->SourcePortNumber = (uint16)EthTSyn_Htons(ETHTSYN_CFG_GET_PORT_NUMBER(PortIdx));

        comMsgPtr->SequenceId = (uint16)EthTSyn_Htons(pDelayRespSmPtr->PdelayReq.SequenceId);
        comMsgPtr->Control = ETHTSYN_HDR_COM_CONTROL_PDELAY_RESP_FOLLOW_UP;
        comMsgPtr->LogMessageInterval = ETHTSYN_HDR_COM_LOG_MESSAGE_INTERVAL_DEFAULT;

        /* set specific message type attributes */
        EthTSyn_SetClockIdentity(pDelayRespFollowUpPtr->RequestingClockIdentity,
          pDelayRespSmPtr->PdelayReq.SourcePortIdentity.ClockIdentity);

        pDelayRespFollowUpPtr->RequestingPortNumber = 
          (uint16)EthTSyn_Htons(pDelayRespSmPtr->PdelayReq.SourcePortIdentity.PortNumber);

        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
#if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
        /* HW-Timestamping */
        /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
        EthTSyn_HtonTimestamp((ETHTSYN_P2VAR(EthTSyn_TimestampType))
          pDelayRespFollowUpPtr->ResponseOriginTimestampSeconds,
          &pDelayRespSmPtr->PdelayResp.EgressTimestamp);
#else
        /* SW-Timestamping */
        pDelayRespEgressTimestamp.secondsHi = 0u;
        pDelayRespEgressTimestamp.seconds = 0u;
        pDelayRespEgressTimestamp.nanoseconds = pDelayRespSmPtr->PdelayResp.EgressTimestamp.nanoseconds;
        /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
        EthTSyn_HtonTimestamp((ETHTSYN_P2VAR(EthTSyn_TimestampType))
          pDelayRespFollowUpPtr->ResponseOriginTimestampSeconds,
          &pDelayRespEgressTimestamp);
#endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
        /* Get Switch management info if required */
        if(EthTSyn_IsSwitchPort(PortIdx) == TRUE)
        {
          mgmtInfo.SwitchIdx = EthTSyn_PortConfig[PortIdx].SwtInfo.SwitchIdx;
          mgmtInfo.PortIdx = EthTSyn_PortConfig[PortIdx].SwtInfo.PortIdx;
# if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
          /* Get frame id if required */
          mgmtInfo.FrameId = EthTSyn_GetFrameId(txBufU8Ptr, lenByte);
# endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */

          mgmtInfoPtr = &mgmtInfo;
        }
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
        ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        /* transmit */
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
        retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_MSG_P_DELAY_RESP_FOLLOW_UP_LENGTH, FALSE, mgmtInfoPtr);
        CANOE_WRITE_STRING_1("[EthTSyn_TxPdelayRespFollowUpMsg] RetVal of EthTSyn_Transmit: %s",
          (retVal == 0 ? "E_OK" : "E_NOT_OK"));
#else
        retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_MSG_P_DELAY_RESP_FOLLOW_UP_LENGTH, FALSE);
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
      }
    }
  }
  return retVal;
} /* EthTSyn_TxPdelayRespFollowUpMsg() */
/* PRQA L: STCAL */

/**********************************************************************************************************************
 *  EthTSyn_TxSyncMsg
 *********************************************************************************************************************/
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxSyncMsg(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(uint8) txBufU8Ptr;
  ETHTSYN_P2VAR(EthTSyn_SyncMsgType) syncPtr;
  ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType) comMsgPtr;
  ETHTSYN_P2VAR(EthTSyn_SyncSendSmType) syncSendSmPtr;
  uint8 bufIdx;
  Std_ReturnType retVal = E_NOT_OK;
  uint16 lenByte = ETHTSYN_MSG_SYNC_LENGTH;
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
  EthSwt_MgmtInfoType mgmtInfo;
  ETHTSYN_P2CONST(EthSwt_MgmtInfoType) mgmtInfoPtr = &mgmtInfo;
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
  if(EthTSyn_IsTxReady(PortIdx) == TRUE)
  {
    /* Get TxBuffer, Assemble and Send Sync message for each Master Port */
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    if(EthIf_ProvideTxBuffer(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), ETHTSYN_FRAME_TYPE,
      ETHTSYN_CFG_GET_FRAME_PRIORITY(PortIdx), &bufIdx, (ETHTSYN_P2VAR(Eth_DataType*))&txBufU8Ptr,
      &lenByte) == BUFREQ_OK)
    {
      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* Init syncSendSmPtr */
      syncSendSmPtr = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

      /* Reset Timestamp States */
      syncSendSmPtr->FollowUpPreciseOriginTimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_INVALID;
#if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
      syncSendSmPtr->SyncIngressTimestampStateHostPort = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_INVALID;
#endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

      /* Set message pointers */
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      comMsgPtr = (ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType))txBufU8Ptr;
      syncPtr = (ETHTSYN_P2VAR(EthTSyn_SyncMsgType))&txBufU8Ptr[ETHTSYN_HDR_COM_LENGTH];

      /* Set common header message attributes */
      EthTSyn_PrepareCommonMsgHdr(comMsgPtr, ETHTSYN_MSG_TYPE_SYNC, PortIdx);

      /* Set message specific attributes */
      IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))syncPtr->Reserved, 0u, sizeof(syncPtr->Reserved));

      syncSendSmPtr->SyncTxBufIdx = bufIdx;

      /* store buffer pointer for call-back in TxConfirmation */
      syncSendSmPtr->SyncTxBufPtr = txBufU8Ptr;

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
# if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
      /* Get the Frame Id */
      mgmtInfo.FrameId = EthTSyn_GetFrameId(txBufU8Ptr, lenByte);
#  if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
      syncSendSmPtr->FrameId = mgmtInfo.FrameId;
#  endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
# endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
      /* Set management Info */
      if((EthTSyn_GetPortType(PortIdx) & ETHTSYN_PORT_TYPE_SWITCH_PORT) != 0)
      {
        mgmtInfo.SwitchIdx = EthTSyn_PortConfig[PortIdx].SwtInfo.SwitchIdx;
        mgmtInfo.PortIdx = EthTSyn_PortConfig[PortIdx].SwtInfo.PortIdx;
      }
      else
      {
        mgmtInfoPtr = NULL_PTR;
      }
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

      syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_SEND_FOLLOW_UP;
      syncSendSmPtr->FollowUpPreciseOriginTimestampState =
        ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;

      /* Set Tx length */
      lenByte = ETHTSYN_MSG_SYNC_LENGTH;

      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* Call to foreign module --> leave critical section is required */
#if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      retVal = EthIf_EnableEgressTimestamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), bufIdx);
      if(retVal == E_NOT_OK)
      {
        /* Failed to enable egress timestamp -> Release TxBuffer and retry Sync transmission later */
        lenByte = 0u;
      }
      else
#endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
      {
#if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
        if(EthTSyn_GetPortType(PortIdx) == ETHTSYN_PORT_TYPE_SWITCH_PORT)
        {
          syncSendSmPtr->SyncEgressTimestampStateSwitchPort =
            ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;
          syncSendSmPtr->SyncIngressTimestampStateHostPort =
            ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          retVal = EthIf_SwitchEnableEgressTimeStamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), bufIdx, mgmtInfoPtr);
          if(retVal == E_NOT_OK)
          {
            /* Failed to enable Switch Egress Timestamp -> Release TxBuffer and retry Sync transmission later */
            lenByte = 0u;
          }
        }
#endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
      }

      /* Transmit */
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
      retVal = EthTSyn_Transmit(PortIdx, bufIdx, lenByte, TRUE, mgmtInfoPtr);
#else
      retVal = EthTSyn_Transmit(PortIdx, bufIdx, lenByte, TRUE);
#endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

#if ((ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) || (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON))
      if(lenByte == 0u)
      {
        retVal = E_NOT_OK;
      }
#endif /* ((ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) || (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)) */

    }
  }

  return retVal;
} /* EthTSyn_TxSyncMsg() */
/* PRQA L: STCAL */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_TxFollowUpMsg
 *********************************************************************************************************************/
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxFollowUpMsg(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(uint8) txBufU8Ptr;
  ETHTSYN_P2VAR(EthTSyn_FollowUpMsgType) followUpPtr;
  ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType) comMsgPtr;
  /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
  ETHTSYN_P2VAR(EthTSyn_SyncSendSmType) syncSendSmPtr = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx);
  uint8 bufIdx;
  Std_ReturnType retVal = E_NOT_OK;
  uint16 lenByte = ETHTSYN_CFG_GET_FOLLOW_UP_MSG_LENGTH_TX(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
  boolean readyToSend = FALSE;
  uint64 unsignedFollowUpCorrectionValueNs = 0;
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
  EthSwt_MgmtInfoType mgmtInfo;
  ETHTSYN_P2CONST(EthSwt_MgmtInfoType) mgmtInfoPtr = &mgmtInfo;
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
  /* Check if Port is AsCapable and Enabled */
  if(EthTSyn_IsTxReady(PortIdx) == TRUE)
  {
    ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(EthTSyn_IsTimestampReadyToProcess(syncSendSmPtr->FollowUpPreciseOriginTimestampState) == TRUE)
    {
#if ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) )
      /* Check if Switch Timestamps are available already */ /* PRQA S 3415 2 */ /* MD_EthTSyn_12.4 */
      if((EthTSyn_IsTimestampReadyToProcess(syncSendSmPtr->SyncEgressTimestampStateSwitchPort) == TRUE) &&
        (EthTSyn_IsTimestampReadyToProcess(syncSendSmPtr->SyncIngressTimestampStateHostPort) == TRUE))
      {
        EthTSyn_TimediffType switchResidenceTime;

        readyToSend = TRUE;
        unsignedFollowUpCorrectionValueNs = ETHTSYN_SWT_UPLINK_TO_TX_RESIDENCE_TIME_NS;
        /* calculate FollowUp correction value */
        if(EthTSyn_TimestampMinusTimestamp(&syncSendSmPtr->SyncEgressTimestampSwitchPort,
          &syncSendSmPtr->SyncIngressTimestampHostPort, &switchResidenceTime) == E_OK)
        {
          if(switchResidenceTime > 0)
          {
            unsignedFollowUpCorrectionValueNs = (uint64)switchResidenceTime;
          }
        }
      }
#else
      readyToSend = TRUE;
#endif /* ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) ) */
    }
    ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if(readyToSend == TRUE)
  {
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    if(EthIf_ProvideTxBuffer(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), ETHTSYN_FRAME_TYPE,
      ETHTSYN_CFG_GET_FRAME_PRIORITY(PortIdx), &bufIdx, (ETHTSYN_P2VAR(Eth_DataType*)) &txBufU8Ptr,
      &lenByte) == BUFREQ_OK)
    {
      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* set message pointers */
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      comMsgPtr = (ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType))txBufU8Ptr;
      followUpPtr = (ETHTSYN_P2VAR(EthTSyn_FollowUpMsgType))&txBufU8Ptr[ETHTSYN_HDR_COM_LENGTH];

      /* set common header message attributes */
      comMsgPtr->TransSpecific_MessageType = ETHTSYN_HDR_COM_TRANSPORT_SPECIFIC | ETHTSYN_MSG_TYPE_FOLLOW_UP;
      comMsgPtr->Reserved_VersionGPtp = ETHTSYN_PROTOCOL_VERSION;

      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      comMsgPtr->MessageLength =
        (uint16)EthTSyn_Htons((uint16)ETHTSYN_CFG_GET_FOLLOW_UP_MSG_LENGTH_TX(PortIdx)); /*lint !e572 */
      comMsgPtr->DomainNumber = EthTSyn_PortConfig[PortIdx].TimeDomainId;

      comMsgPtr->Reserved_0 = 0;
      comMsgPtr->Flags = EthTSyn_Htons(ETHTSYN_FLAGS_TWO_STEP);  /*lint !e572 */

      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))comMsgPtr->CorrectionField, 0,
        sizeof(EthTSyn_CorrectionFieldType));

      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))comMsgPtr->Reserved_1, 0, 4);

      EthTSyn_SetClockIdentity(comMsgPtr->SourceClockIdentity, ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx));
      comMsgPtr->SourcePortNumber = (uint16)EthTSyn_Htons(ETHTSYN_CFG_GET_PORT_NUMBER(PortIdx));

      comMsgPtr->SequenceId = (uint16)EthTSyn_Htons(syncSendSmPtr->SequenceId);
      comMsgPtr->Control = ETHTSYN_HDR_COM_CONTROL_FOLLOW_UP;
      comMsgPtr->LogMessageInterval = syncSendSmPtr->LogMessageInterval;

      /* set specific message type attributes to zero */
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))followUpPtr, 0, sizeof(EthTSyn_FollowUpMsgType));

      /* set Tlv values */ /*lint -e572 */
      followUpPtr->TlvType = EthTSyn_Htons(ETHTSYN_FOLLOW_UP_TLV_TYPE);
      followUpPtr->LengthField = EthTSyn_Htons(ETHTSYN_FOLLOW_UP_TLV_LENGTH_FIELD);
      followUpPtr->OrganisationId[0] = (uint8)(ETHTSYN_FOLLOW_UP_ORGANISATION_ID >> 16U);
      followUpPtr->OrganisationId[1] = (uint8)(ETHTSYN_FOLLOW_UP_ORGANISATION_ID >> 8U);
      followUpPtr->OrganisationId[2] = (uint8)((ETHTSYN_FOLLOW_UP_ORGANISATION_ID >> 0U) & 0xFF);
      followUpPtr->OrganisationSubType[0] = (uint8)(ETHTSYN_FOLLOW_UP_ORGANISATION_SUBTYPE >> 16U);
      followUpPtr->OrganisationSubType[1] = (uint8)(ETHTSYN_FOLLOW_UP_ORGANISATION_SUBTYPE >> 8U);
      followUpPtr->OrganisationSubType[2] = (uint8)(ETHTSYN_FOLLOW_UP_ORGANISATION_SUBTYPE >> 0U); /*lint +e572 */

      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      EthTSyn_HtonTimestamp((ETHTSYN_P2VAR(EthTSyn_TimestampType))followUpPtr->PreciseOriginTimestampSeconds,
        &syncSendSmPtr->FollowUpPreciseOriginTimestamp);

      /* PRQA S 3109 1 */ /* MD_MSR_14_3 */
      EthTSyn_CopyFollowUpCorrectionField(unsignedFollowUpCorrectionValueNs, comMsgPtr->CorrectionField);

      syncSendSmPtr->FollowUpTxBufIdx = bufIdx;

      /* store bufferPtr for call-back in tx-confirmation */
      syncSendSmPtr->FollowUpTxBufPtr = txBufU8Ptr;

      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

#if (ETHTSYN_TLV_FOLLOW_UP_TX_SUPPORT == STD_ON)
      /* append FollowUp Ar TLVs if applicable */
      if(EthTSyn_CfgAccess_IsArTlvTxRequired(PortIdx) == TRUE)
      {
        EthTSyn_AppendArFollowUpTlvs(PortIdx, comMsgPtr, followUpPtr);
      }
#endif /* (ETHTSYN_TLV_FOLLOW_UP_TX_SUPPORT == STD_ON) */

      /* transmit */
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
      /* Get Frame Id and Management Info if required */
      if((EthTSyn_GetPortType(PortIdx) & ETHTSYN_PORT_TYPE_SWITCH_PORT) != 0)
      {
        mgmtInfo.SwitchIdx = EthTSyn_PortConfig[PortIdx].SwtInfo.SwitchIdx;
        mgmtInfo.PortIdx = EthTSyn_PortConfig[PortIdx].SwtInfo.PortIdx;
# if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
        mgmtInfo.FrameId = EthTSyn_GetFrameId(txBufU8Ptr, lenByte);
# endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
      }
      else
      {
        mgmtInfoPtr = NULL_PTR;
      }

      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_CFG_GET_FOLLOW_UP_MSG_LENGTH_TX(PortIdx), TRUE, mgmtInfoPtr);
#else
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_CFG_GET_FOLLOW_UP_MSG_LENGTH_TX(PortIdx), TRUE);
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
    }
  }

  return retVal;
} /* EthTSyn_TxFollowUpMsg() */
/* PRQA L: STCAL */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_TxAnnounceMsg
 *********************************************************************************************************************/
#if (ETHTSYN_ANNOUNCE_TX_SUPPORT == STD_ON)
ETHTSYN_LOCAL FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxAnnounceMsg(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(uint8) txBufU8Ptr;
  ETHTSYN_P2VAR(EthTSyn_AnnounceMsgType) announcePtr;
  ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType) comMsgPtr;
  uint8 bufIdx;
  Std_ReturnType retVal = E_NOT_OK;
  uint16 lenByte = ETHTSYN_MSG_ANNOUNCE_LENGTH;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if Port is enabled */
  if(EthTSyn_IsTxReady(PortIdx) == TRUE)
  {
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    if(EthIf_ProvideTxBuffer(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), ETHTSYN_FRAME_TYPE,
      ETHTSYN_CFG_GET_FRAME_PRIORITY(PortIdx), &bufIdx, (ETHTSYN_P2VAR(Eth_DataType*)) &txBufU8Ptr,
      &lenByte) == BUFREQ_OK)
    {
      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      /* set message pointers */
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      comMsgPtr = (ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType))txBufU8Ptr;
      announcePtr = (ETHTSYN_P2VAR(EthTSyn_AnnounceMsgType))&txBufU8Ptr[ETHTSYN_HDR_COM_LENGTH];
    
      /* set common header message attributes */
      comMsgPtr->TransSpecific_MessageType = ETHTSYN_HDR_COM_TRANSPORT_SPECIFIC | ETHTSYN_MSG_TYPE_ANNOUNCE;
      comMsgPtr->Reserved_VersionGPtp = ETHTSYN_PROTOCOL_VERSION;

      comMsgPtr->MessageLength = EthTSyn_Htons((uint16)ETHTSYN_MSG_ANNOUNCE_LENGTH); /*lint !e572 */
      comMsgPtr->DomainNumber = EthTSyn_PortConfig[PortIdx].TimeDomainId;
    
      comMsgPtr->Reserved_0 = 0;
      comMsgPtr->Flags = 0;
    
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))comMsgPtr->CorrectionField, 0,
        sizeof(EthTSyn_CorrectionFieldType));
    
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))comMsgPtr->Reserved_1, 0, 4);
    
      EthTSyn_SetClockIdentity(comMsgPtr->SourceClockIdentity, ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx));
      comMsgPtr->SourcePortNumber = (uint16)EthTSyn_Htons(ETHTSYN_CFG_GET_PORT_NUMBER(PortIdx));
    
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      comMsgPtr->SequenceId = (uint16)EthTSyn_Htons(ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SequenceId);
      comMsgPtr->Control = ETHTSYN_HDR_COM_CONTROL_ANNOUNCE;
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      comMsgPtr->LogMessageInterval = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->LogMessageInterval;
    
      /* set specific message type attributes */
    
      /* set first reserved field to zero */
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))announcePtr->Reserved_0, 0, 10);
      
      announcePtr->CurrentUtcOffset = 0;
    
      /* set second reserved field to zero */
      announcePtr->Reserved_1 = 0;
    
      announcePtr->GrandmasterPriority_1 = ETHTSYN_ANNOUNCE_PRIORITY_1_NETWORK_INFRASTRUCTURE;
      announcePtr->GrandmasterClockQuality.ClockAccuracy = ETHTSYN_ANNOUNCE_CLOCK_ACCURACY_UNKNOWN;
      announcePtr->GrandmasterClockQuality.ClockClass = ETHTSYN_ANNOUNCE_CLOCK_CLASS_UNKNOWN;
      announcePtr->GrandmasterClockQuality.OffsetScaledLogVariance = 
        (uint16)EthTSyn_Htons(ETHTSYN_ANNOUNCE_OFFSET_SCALED_LOG_UNKNOWN);
      announcePtr->GrandmasterPriority_2 = ETHTSYN_ANNOUNCE_PRIORITY_2_DEFAULT;
    
      EthTSyn_SetClockIdentity(announcePtr->GrandmasterIdentity, ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx));
      
      announcePtr->StepsRemoved[0] = 0;
      announcePtr->StepsRemoved[1] = 0;
    
      announcePtr->TimeSource = ETHTSYN_ANNOUNCE_TIME_SOURCE_INTERNAL_OSCILLATOR;
      /*lint -e572 */
      announcePtr->TlvType = EthTSyn_Ntohs((uint16)ETHTSYN_ANNOUNCE_TLV_TYPE);
      announcePtr->LengthField = EthTSyn_Ntohs((uint16)ETHTSYN_ANNOUNCE_TLV_LENGTH_FIELD); /*lint +e572 */
    
      /* set Tlv Clock identity */
      EthTSyn_SetClockIdentity(announcePtr->ClockIdentity, ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx));
      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* transmit */
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
      retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_MSG_ANNOUNCE_LENGTH, FALSE, NULL_PTR);
#else
      retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_MSG_ANNOUNCE_LENGTH, FALSE);
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
    }
  } /* END: Check if Port is enabled */
  return retVal;
} /* EthTSyn_TxAnnounceMsg() */
#endif /* (ETHTSYN_ANNOUNCE_TX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_InitPort
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_InitPort(EthTSyn_TimeDomainIdxType TimeDomainIdx,
  EthTSyn_PortIdxType PortIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* set default port values */
  
  if(EthTSyn_CfgGetPortRole(PortIdx) == ETHTSYN_PORT_ROLE_MASTER)
  {
    /* Master Port --> Sync-Send state machine is necessary */
    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    ETHTSYN_P2VAR(EthTSyn_SyncSendSmType) syncSendSmPtr = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx);
    /* set SyncSendSm values */
    syncSendSmPtr->SyncTxBufIdx = ETHTSYN_INV_BUF_IDX;
    syncSendSmPtr->FollowUpTxBufIdx = ETHTSYN_INV_BUF_IDX;
    syncSendSmPtr->TxConfirmationPending = 0;

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)
    /* End-Station */
    ETHTSYN_DUMMY_STATEMENT(TimeDomainIdx); /* PRQA S 3453, 3112, 3199 */ /* MD_MSR_19.7 */ /* MD_MSR_14.2 */
    syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_INITIALIZING;
    syncSendSmPtr->SyncTxBufPtr = NULL_PTR;
    syncSendSmPtr->FollowUpTxBufPtr = NULL_PTR;
    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    syncSendSmPtr->TxIntervalCnt = ETHTSYN_CFG_GET_SYNC_TX_INTERVAL_CNT(PortIdx);
#else /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) */
    /* Bridge */
    if(EthTSyn_CfgGetSlavePortCnt(TimeDomainIdx) == 0)
    {
      if((EthTSyn_GetPortType(PortIdx) & ETHTSYN_PORT_TYPE_END_STATION_PORT) != 0)
      {
        /* End-Station Port */
        syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_DISABLED;
      }
      else
      {
        /* Switch Port */
        syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_INITIALIZING;
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        syncSendSmPtr->TxIntervalCnt = EthTSyn_MasterPortConfigPtr(PortIdx)->SyncSendInterval;
        syncSendSmPtr->LogMessageInterval = EthTSyn_MasterPortConfigPtr(PortIdx)->SyncLogMessageInterval;
      }
    }
    else
    {
      syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_PENDING;
    }
    syncSendSmPtr->SyncTxBufPtr = NULL_PTR;
    syncSendSmPtr->FollowUpTxBufPtr = NULL_PTR;
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) */
  } /* END: If Master Port */
  else /* Slave Port */
  {
    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    IpBase_Fill(ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx), 0, sizeof(EthTSyn_SyncReceiveSmType));
  }

} /* End of EthTSyn_InitPort() */

/**********************************************************************************************************************
 *  EthTSyn_InitTimeDomain
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_InitTimeDomain(EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Local Variables ------------------------------------------------ */
  /* PRQA S 0781 1 */ /* MD_EthTSyn_5.6 */
  EthTSyn_PortIdxType masterPortCnt = EthTSyn_CfgGetMasterPortCnt(TimeDomainIdx);
  EthTSyn_PortIdxType slavePortCnt = EthTSyn_CfgGetSlavePortCnt(TimeDomainIdx);

  /* ----- Implementation ------------------------------------------------- */

  while(masterPortCnt > 0)
  {
    masterPortCnt--;
    EthTSyn_InitPort(TimeDomainIdx, EthTSyn_CfgGetMasterPortIdx(TimeDomainIdx, masterPortCnt));
  }

  while(slavePortCnt > 0)
  {
    EthTSyn_PortIdxType slavePortIdx;

    slavePortCnt--;
    slavePortIdx =  EthTSyn_CfgGetSlavePortIdx(TimeDomainIdx, slavePortCnt);
    EthTSyn_InitPort(TimeDomainIdx, slavePortIdx);

    /* set SyncReceiveSm values */
    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    ETHTSYN_SYNC_RECEIVE_SM_PTR(slavePortIdx)->State = ETHTSYN_STATE_SYNC_RECEIVE_DISCARD;
  }

  EthTSyn_ResetMasterPriorityVector(TimeDomainIdx);

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
  /* Bridge */
  slavePortCnt = EthTSyn_CfgGetSlavePortCnt(TimeDomainIdx);
  if(slavePortCnt <= 0)
  {
    EthTSyn_SiteSyncSyncSm(TimeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_DISABLED;
  }
  else
  {
    EthTSyn_SiteSyncSyncSm(TimeDomainIdx).TxConfirmationPending = 0;
    EthTSyn_SiteSyncSyncSm(TimeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_PENDING;
  }

  ETHTSYN_STATE_GET_SLAVE_PORT_IDX(TimeDomainIdx) = ETHTSYN_INVALID_PORT_IDX;
  while(slavePortCnt > 0)
  {
    slavePortCnt--;
    if( (EthTSyn_GetPortType(EthTSyn_CfgGetSlavePortIdx(TimeDomainIdx, slavePortCnt)) &
        ETHTSYN_PORT_TYPE_SWITCH_PORT) != 0 )
    {
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      ETHTSYN_STATE_GET_SLAVE_PORT_IDX(TimeDomainIdx) = EthTSyn_CfgGetSlavePortIdx(TimeDomainIdx, slavePortCnt);
# if (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON)
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      ETHTSYN_SYNC_RECEIVE_SM_PTR(ETHTSYN_STATE_GET_SLAVE_PORT_IDX(TimeDomainIdx))->Sync.SyncRxTimeoutCnt =
        EthTSyn_CfgGetSyncTimeout(TimeDomainIdx);
# endif /* (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON) */
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
          /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
          ETHTSYN_SYNC_RECEIVE_SM_PTR(
            ETHTSYN_STATE_GET_SLAVE_PORT_IDX(TimeDomainIdx))->Sync.EgressTimestampHostPortState =
            ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_INVALID;
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
      break;
    }
  }
#else
  /* End-Station */
  /* Nothing to do here */
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

} /* EthTSyn_InitTimeDomain() */

ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_InitCtrl(EthTSyn_CtrlIdxType EthTSynCtrlIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  EthTSyn_CtrlState[EthTSynCtrlIdx].TransmissionMode = ETHTSYN_TX_ON;
  IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))EthTSyn_CtrlState[EthTSynCtrlIdx].ClockIdentity, 0,
    sizeof(EthTSyn_ClockIdentityType));
} /* EthTSyn_InitCtrl() */

ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_InitPdelay(EthTSyn_PdelayIdxType PdelayIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* Initialize Pdelay Request state machine if required */
#if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
  if(EthTSyn_PdelayConfig[PdelayIdx].PdelayInitiatorCfgPtr != NULL_PTR)
  {
    ETHTSYN_P2CONST(EthTSyn_PdelayInitiatorCfgType) pDelayInitiatorPtr =
      EthTSyn_PdelayConfig[PdelayIdx].PdelayInitiatorCfgPtr;

    if(pDelayInitiatorPtr->PdelayReqSmPtr != NULL_PTR)
    {
      ETHTSYN_P2VAR(EthTSyn_PdelayReqSmType) pDelayReqSmPtr = pDelayInitiatorPtr->PdelayReqSmPtr;

      pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_NOT_ENABLED;
      pDelayReqSmPtr->PdelayReq.TxIntervalCnt = pDelayInitiatorPtr->PdelaySendInterval;
      pDelayReqSmPtr->TxBufIdx = ETHTSYN_INV_BUF_IDX;
      pDelayReqSmPtr->TxConfirmationPending = 0u;
      pDelayReqSmPtr->Pdelay = EthTSyn_PdelayConfig[PdelayIdx].InitialPdelay;
# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
      pDelayReqSmPtr->LostResponses = 0u;
      pDelayReqSmPtr->AsCapable = EthTSyn_PdelayConfig[PdelayIdx].AlwaysAsCapable;
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
      pDelayReqSmPtr->TxBufPtr = NULL_PTR;
#  if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
      pDelayReqSmPtr->FrameId = ETHTSYN_INVALID_FRAME_ID;
#  endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
    }
  }
#endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

  /* Initialize Pdelay Response state machine if required */
#if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
  if(EthTSyn_PdelayConfig[PdelayIdx].PdelayResponderCfgPtr != NULL_PTR)
  {
    if(EthTSyn_PdelayConfig[PdelayIdx].PdelayResponderCfgPtr->PdelayRespSmPtr != NULL_PTR)
    {
      ETHTSYN_P2VAR(EthTSyn_PdelayRespSmType) pDelayRespSmPtr =
        EthTSyn_PdelayConfig[PdelayIdx].PdelayResponderCfgPtr->PdelayRespSmPtr;

      pDelayRespSmPtr->State = ETHTSYN_STATE_P_DELAY_RESP_NOT_ENABLED;
      pDelayRespSmPtr->TxBufIdx = ETHTSYN_INV_BUF_IDX;
      pDelayRespSmPtr->TxConfirmationPending = 0u;
      pDelayRespSmPtr->InProgress = FALSE;
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
      pDelayRespSmPtr->TxBufPtr = NULL_PTR;
#  if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
      pDelayRespSmPtr->FrameId = ETHTSYN_INVALID_FRAME_ID;
#  endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
    }
  }
#endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */
} /* EthTSyn_InitPdelay() */

/***********************************************************************************************************************
 * EthTSyn_ResetPortsAndPdelayOfCtrl
 **********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_ResetPortsAndPdelayOfCtrl(EthTSyn_CtrlIdxType EthTSynCtrlIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_PortIdxIterType portIter;
  EthTSyn_PortIdxType portIdx;

  /* ----- Implementation ----------------------------------------------- */
  for(portIter = 0; portIter < EthTSyn_CtrlConfig[EthTSynCtrlIdx].EthTSynPortCount; portIter++)
  {
    portIdx = EthTSyn_CtrlConfig[EthTSynCtrlIdx].EthTSynPortIdxPtr[portIter];

    EthTSyn_InitPort(ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(portIdx), portIdx);

    if(portIdx == ETHTSYN_CFG_GET_P_DELAY_ACTIVE_PORT_IDX(portIdx))
    {
      EthTSyn_InitPdelay(ETHTSYN_CFG_GET_PDELAY_IDX(portIdx));
    }
  }
} /* EthTSyn_ResetPortsAndPdelayOfCtrl() */

ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_IsTxReady(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean txReady = FALSE;
  EthTSyn_CtrlIdxType ethTSynCtrlIdx;

  /* ----- Implementation ----------------------------------------------- */
  ethTSynCtrlIdx = EthTSyn_PortConfig[PortIdx].EthTSynCtrlIdx;

  /* Check EthTSyn Ctrl State */
  if((EthTSyn_CtrlState[ethTSynCtrlIdx].TransmissionMode == ETHTSYN_TX_ON) &&
    (EthTSyn_CtrlState[ethTSynCtrlIdx].TrcvLinkState == ETHTRCV_LINK_STATE_ACTIVE))
  {
    txReady = TRUE;
  }

  return txReady;
} /* EthTSyn_IsTxReady() */

ETHTSYN_LOCAL_INLINE FUNC(EthTSyn_CtrlIdxType, ETHTSYN_CODE) EthTSyn_GetEthTSynCtrlFromEthIfCtrl(
  uint8 EthIfCtrlIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_CtrlIdxType ethTSynCtrlIdx = ETHTSYN_CTRL_COUNT;
  EthTSyn_CtrlIdxType ethTSynCtrlIter;

  /* ----- Implementation ----------------------------------------------- */
  for(ethTSynCtrlIter = 0; ethTSynCtrlIter < ETHTSYN_CTRL_COUNT; ethTSynCtrlIter++)
  {
    if(EthTSyn_CtrlConfig[ethTSynCtrlIter].EthIfCtrlIdx == EthIfCtrlIdx)
    {
      ethTSynCtrlIdx = ethTSynCtrlIter;
      break;
    }
  }

  return ethTSynCtrlIdx;
} /* EthTSyn_GetEthTSynCtrlFromEthIfCtrl */

/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_HandleEgressTimestamping(
  EthTSyn_PortIdxType PortIdx, uint8 MsgType, uint8 BufIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_GlobalTimestampType timeStampGlobal =
  {
    0, 0, 0
  };
  StbM_TimeStampType timeStampGlobalStbm;
  StbM_UserDataType userData;
  boolean timeStampsValid = FALSE;

#if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
  /* HW-Timestamping */
  Eth_TimestampQualityType timeStampQual = ETH_INVALID;
  EthTSyn_GlobalTimestampType timeStampRefSync =
  {
    0,
    0,
    0
  };
  EthTSyn_GlobalTimestampType timeStampEgress =
  {
    0,
    0,
    0
  };
  EthTSyn_TimediffType timeDiffEgressAndRefSync = 0;
#else
  /* SW-Timestamping */
  EthTSyn_TimestampRawType timeStampRaw = 0;
#endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
  if(MsgType == ETHTSYN_MSG_TYPE_SYNC)
  {
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    if(StbM_GetCurrentTime(ETHTSYN_CFG_GET_SYNCHRONIZTED_TIME_BASE_ID_OF_PORT(PortIdx), &timeStampGlobalStbm,
      &userData) == E_OK)
    {
      ETHTSYN_COPY_STBM_TS_TO_GLOBAL_TS(timeStampGlobalStbm, timeStampGlobal)
#if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
      /* HW-Timestamping */
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      if(EthIf_GetCurrentTime(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), &timeStampQual, &timeStampRefSync) == E_OK)
      {
        if(timeStampQual == ETH_VALID)
        {
          timeStampsValid = TRUE;
        }
      }
#else
        /* SW-Timestamping */
        timeStampsValid = TRUE;
#endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
      
    }
  }
  else
  {
    timeStampsValid = TRUE;
  }

  if(timeStampsValid == TRUE)
  {
#if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    /* HW-Timestamping */
    timeStampsValid = FALSE;
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    if(EthIf_GetEgressTimeStamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), BufIdx, &timeStampQual,
      &timeStampEgress) == E_OK)
    {
      if(timeStampQual == ETH_VALID)
      {
        timeStampsValid = TRUE;
      }
    }
#else
    /* SW-Timestamping */
    ETHTSYN_DUMMY_STATEMENT(BufIdx); /* PRQA S 3112 */ /* MD_MSR_14.2 */
    if((MsgType == ETHTSYN_MSG_TYPE_PDELAY_REQ) || (MsgType == ETHTSYN_MSG_TYPE_PDELAY_RESP))
    {
      timeStampsValid = FALSE;
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      if(StbM_GetCurrentTimeRaw(&timeStampRaw) == E_OK)
      {
        timeStampsValid = TRUE;
      }
    }
#endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
  }

  /* Assign timestamp(s) and Mark theme as (In-)Valid */
  if(timeStampsValid == TRUE)
  {
    switch(MsgType)
    {
    case ETHTSYN_MSG_TYPE_SYNC:
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->FollowUpPreciseOriginTimestampState |=
        ETHTSYN_TIMESTAMP_STATE_AVAILABLE_FLAG_VALID_MASK;
#if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
      /* HW-Timestamping */
      if(EthTSyn_TimestampMinusTimestamp(&timeStampEgress, &timeStampRefSync, &timeDiffEgressAndRefSync) == E_OK)
      {
        if(EthTSyn_TimestampPlusTimediff(&timeStampGlobal, &timeDiffEgressAndRefSync) == E_OK)
        {
          /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->FollowUpPreciseOriginTimestampState |=
            ETHTSYN_TIMESTAMP_STATE_AVAILABLE_MASK;
        }
      }
#else
      /* SW-Timestamping */
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->FollowUpPreciseOriginTimestampState |= ETHTSYN_TIMESTAMP_STATE_AVAILABLE_MASK;
#endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->FollowUpPreciseOriginTimestamp = timeStampGlobal;
      break;

    case ETHTSYN_MSG_TYPE_PDELAY_REQ:
      ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->PdelayReq.EgressTimestampState =
        ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
#if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
      /* HW-Timestamping */
      ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->PdelayReq.EgressTimestamp = timeStampEgress;
#else
      /* SW-Timestamping */
      ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->PdelayReq.EgressTimestamp.nanoseconds = timeStampRaw;
#endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
      break;

    case ETHTSYN_MSG_TYPE_PDELAY_RESP:
      ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx)->PdelayResp.EgressTimestampState =
        ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
#if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
      /* HW-Timestamping */
      ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx)->PdelayResp.EgressTimestamp = timeStampEgress;
#else
      /* SW-Timestamping */
      ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx)->PdelayResp.EgressTimestamp.nanoseconds = timeStampRaw;
#endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
      break;

    default:
      /* This should never happen. Nothing to do here (MISRA) */
      break;
    }
  }

} /* EthTSyn_HandleEgressTimestamping() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */

/**********************************************************************************************************************
 *  EthTSyn_IsTimestampAvailable
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_IsTimestampAvailable(
  EthTSyn_TimestampStateType TimestampState)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean tsAvailable = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  if((TimestampState & ETHTSYN_TIMESTAMP_STATE_AVAILABLE_FLAG_VALID_MASK) != 0)
  {
    if((TimestampState & ETHTSYN_TIMESTAMP_STATE_AVAILABLE_MASK) != 0)
    {
      tsAvailable = TRUE;
    }
  }

  return tsAvailable;
} /* EthTSyn_IsTimestampAvailable() */

/**********************************************************************************************************************
 *  EthTSyn_PrepareCommonMsgHdr
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_PrepareCommonMsgHdr(
  ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType) ComMsgHdrPtr, uint8 MsgType, EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 msgLength = 0;
  uint16 sequenceId = 0;
  uint8 comHdrControl = 0;
  sint8 logMessageInterval = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* Get message length from Message type */
  switch(MsgType)
  {
  case ETHTSYN_MSG_TYPE_SYNC:
    msgLength = ETHTSYN_MSG_SYNC_LENGTH;
    sequenceId = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SequenceId; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    comHdrControl = ETHTSYN_HDR_COM_CONTROL_SYNC;
    logMessageInterval = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->LogMessageInterval; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    break;

  case ETHTSYN_MSG_TYPE_FOLLOW_UP:
    msgLength = ETHTSYN_CFG_GET_FOLLOW_UP_MSG_LENGTH_TX(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    sequenceId = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SequenceId; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    comHdrControl = ETHTSYN_HDR_COM_CONTROL_FOLLOW_UP;
    logMessageInterval = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->LogMessageInterval; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    break;

  case ETHTSYN_MSG_TYPE_PDELAY_REQ:
    msgLength = ETHTSYN_MSG_P_DELAY_REQ_LENGTH;
    sequenceId = ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->PdelayReq.SequenceId;
    comHdrControl = ETHTSYN_HDR_COM_CONTROL_PDELAY_REQ;
    logMessageInterval = ETHTSYN_CFG_GET_P_DELAY_REQ_LOG_MESSAGE_INTERVAL(PortIdx);
    break;

  case ETHTSYN_MSG_TYPE_PDELAY_RESP:
    msgLength = ETHTSYN_MSG_P_DELAY_RESP_LENGTH;
    sequenceId = ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx)->PdelayReq.SequenceId;
    comHdrControl = ETHTSYN_HDR_COM_CONTROL_PDELAY_RESP;
    logMessageInterval = ETHTSYN_HDR_COM_LOG_MESSAGE_INTERVAL_DEFAULT;
    break;

  case ETHTSYN_MSG_TYPE_PDELAY_RES_FOLLOW_UP:
    msgLength = ETHTSYN_MSG_P_DELAY_RESP_FOLLOW_UP_LENGTH;
    sequenceId = ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx)->PdelayReq.SequenceId;
    comHdrControl = ETHTSYN_HDR_COM_CONTROL_PDELAY_RESP_FOLLOW_UP;
    logMessageInterval = ETHTSYN_HDR_COM_LOG_MESSAGE_INTERVAL_DEFAULT;
    break;

  case ETHTSYN_MSG_TYPE_ANNOUNCE:
    msgLength = ETHTSYN_MSG_ANNOUNCE_LENGTH;
    sequenceId = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SequenceId; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    comHdrControl = ETHTSYN_HDR_COM_CONTROL_ANNOUNCE;
    logMessageInterval = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->LogMessageInterval; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    break;

  default:
    /* This should never happen. Nothing to do (MISRA) */
    break;
  }

  /* Set common message header attributes */
  ComMsgHdrPtr->TransSpecific_MessageType = (uint8)(ETHTSYN_HDR_COM_TRANSPORT_SPECIFIC | MsgType);
  ComMsgHdrPtr->Reserved_VersionGPtp = ETHTSYN_PROTOCOL_VERSION;

  ComMsgHdrPtr->MessageLength = (uint16)EthTSyn_Htons(msgLength);
  ComMsgHdrPtr->DomainNumber = EthTSyn_PortConfig[PortIdx].TimeDomainId;

  ComMsgHdrPtr->Reserved_0 = 0;
  ComMsgHdrPtr->Flags = EthTSyn_Htons(ETHTSYN_FLAGS_TWO_STEP);  /*lint !e572 */

  if(MsgType != ETHTSYN_MSG_TYPE_FOLLOW_UP)
  {
    /* Correction field only used for FollowUp messages */
    IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))ComMsgHdrPtr->CorrectionField, 0,
      sizeof(EthTSyn_CorrectionFieldType));
  }

  IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))ComMsgHdrPtr->Reserved_1, 0, ETHTSYN_HDR_COM_RESERVED_1_LENGTH);
  
  EthTSyn_SetClockIdentity(ComMsgHdrPtr->SourceClockIdentity, ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx));
  ComMsgHdrPtr->SourcePortNumber = (uint16)EthTSyn_Htons(ETHTSYN_CFG_GET_PORT_NUMBER(PortIdx));

  ComMsgHdrPtr->SequenceId = (uint16)EthTSyn_Htons(sequenceId);
  ComMsgHdrPtr->Control = comHdrControl;
  ComMsgHdrPtr->LogMessageInterval = logMessageInterval;

} /* EthTSyn_PrepareCommonMsgHdr() */

/**********************************************************************************************************************
 *  EthTSyn_AppendArFollowUpTlvs
 *********************************************************************************************************************/
#if (ETHTSYN_TLV_FOLLOW_UP_TX_SUPPORT == STD_ON)
/* AR4.3 message format */
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_AppendArFollowUpTlvs(EthTSyn_PortIdxType PortIdx,
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr, ETHTSYN_P2VAR(EthTSyn_FollowUpMsgType) FollowUpMsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 offset = ETHTSYN_AR_TLV_HEADER_LENGTH;
  uint16 arTlvHdrLengthField = ETHTSYN_AR_TLV_HEADER_LENGTH_FIELD_VALUE; /* Add length sum of Sub-Tlvs later */
  /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
  ETHTSYN_P2VAR(EthTSyn_ArTlvHeaderType) arTlvHdrPtr =
    (ETHTSYN_P2VAR(EthTSyn_ArTlvHeaderType))&((ETHTSYN_P2VAR(uint8))FollowUpMsgPtr)[ETHTSYN_FOLLOW_UP_AR_TLV_OFFSET];

# if ((ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON) || \
  (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON) || \
    (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON))
  StbM_SynchronizedTimeBaseType syncTimeBaseId = ETHTSYN_CFG_GET_SYNCHRONIZTED_TIME_BASE_ID_OF_PORT(PortIdx);
#  if ((ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON) || \
  (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON))
  StbM_UserDataType userData = {0, 0, 0, 0};
  StbM_TimeStampType timeStamp;
#  endif /* UserData or Ofs SUb-Tlv Support */
# endif /* Status, UserData or Ofs Sub-Tlv Support */

# if (ETHTSYN_CRC_TX_SUPPORT == STD_ON)
  uint8 dataId = EthTSyn_CfgAccess_GetFollowUpDataIdListEntry(ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(PortIdx),
    (uint16)EthTSyn_Ntohs(ComMsgPtr->SequenceId));
# endif /* (ETHTSYN_CRC_TX_SUPPORT == STD_ON) */

# if (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON)
  ETHTSYN_P2VAR(EthTSyn_ArSubTlvTimeSecuredType) timeSecuredSubTlvPtr;
# endif /* (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON) */

# if (ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON)
  ETHTSYN_P2VAR(EthTSyn_ArSubTlvStatusType) statusSubTlvPtr;
# endif /* (ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON) */

# if (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON)
  ETHTSYN_P2VAR(EthTSyn_ArSubTlvUserDataType) userDataSubTlvPtr;
# endif /* (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON) */

# if (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON)
  ETHTSYN_P2VAR(EthTSyn_ArSubTlvOfsType) ofsSubTlvPtr;
  uint8_least offsetTimeDomainIter;
# endif /* (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
# if (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON)
  /* Append the Time Secured Sub-Tlv if applicable */
  if(ETHTSYN_CFG_GET_AR_SUB_TLV_TIME_USED(PortIdx) == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
  {
    /* Add the Sub-Tlv Time Secured length to the AR Tlv header length */
    arTlvHdrLengthField += ETHTSYN_AR_SUB_TLV_TIME_LENGTH;
    
    /* Get the Time Secured Sub-Tlv pointer */
    /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    timeSecuredSubTlvPtr = (ETHTSYN_P2VAR(EthTSyn_ArSubTlvTimeSecuredType))
      &(((ETHTSYN_P2VAR(uint8))arTlvHdrPtr)[offset]);
#  if ((ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON)    || \
      (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON) || \
      ((ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON)))
    /* Only increase offset if required for further Sub-Tlv */
    offset += ETHTSYN_AR_SUB_TLV_TIME_LENGTH;
#  endif

    /* Set Type and length */
    timeSecuredSubTlvPtr->Type = ETHTSYN_AR_SUB_TLV_TYPE_TIME_SECURED;
    timeSecuredSubTlvPtr->Length = ETHTSYN_AR_SUB_TLV_TIME_LENGTH_FIELD_VALUE;

    /* Set CRC_Time_Flags */
    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    timeSecuredSubTlvPtr->CrcTimeFlags = ETHTSYN_CFG_GET_TX_CRC_SECURED_FLAGS(PortIdx);

    /* Calculate and set CRC_Time_0/1 */
    timeSecuredSubTlvPtr->CrcTime0 = EthTSyn_Crc_ComputeTime0Crc(dataId, timeSecuredSubTlvPtr->CrcTimeFlags,
      ComMsgPtr, FollowUpMsgPtr);
    timeSecuredSubTlvPtr->CrcTime1 = EthTSyn_Crc_ComputeTime1Crc(dataId, timeSecuredSubTlvPtr->CrcTimeFlags,
      ComMsgPtr);
  }
# endif /* (ETHTSYN_TLV_FOLLOW_UP_TIME_SUB_TLV_SUPPORT == STD_ON) */

# if (ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON)
  /* Append the Status (Not) Secured Sub-Tlv if applicable */
  if(ETHTSYN_CFG_GET_AR_SUB_TLV_STATUS_USED(PortIdx) == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
  {
    StbM_TimeStampType tempStbmTimeStamp;
    StbM_UserDataType tempUserData;
    /* Add the Sub-Tlv Status (Not) Secured length to the AR Tlv header length */
    arTlvHdrLengthField += ETHTSYN_AR_SUB_TLV_STATUS_LENGTH;

    /* Get the Status (Not) Secured Sub-Tlv pointer */ /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    statusSubTlvPtr = (ETHTSYN_P2VAR(EthTSyn_ArSubTlvStatusType))&(((ETHTSYN_P2VAR(uint8))arTlvHdrPtr)[offset]);
#  if ((ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON) || \
      ((ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON)))
    /* Only increase offset if required for further Sub-Tlv */
    offset += ETHTSYN_AR_SUB_TLV_STATUS_LENGTH;
#  endif

    /* Set length */
    statusSubTlvPtr->Length = ETHTSYN_AR_SUB_TLV_STATUS_LENGTH_FIELD_VALUE;

    /* Get the synchronized time base status */
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    if(StbM_GetCurrentTime(syncTimeBaseId, &tempStbmTimeStamp, &tempUserData) == E_OK)
    {
      ETHTSYN_TIME_BASE_STATUS_TO_AR_SUB_TLV_STATUS(tempStbmTimeStamp.timeBaseStatus, statusSubTlvPtr->Status);
    }
    else
    {
      statusSubTlvPtr->Status = 0u;
    }
    
    /* Write Type Secured/NotSecured and Crc (if applicable) */
#  if (ETHTSYN_CRC_TX_SUPPORT == STD_ON)
    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    if(ETHTSYN_CFG_GET_TX_CRC_SECURED(PortIdx) == ETHTSYN_CRC_TX_SECURED_SUPPORTED)
    {
      /* Secured */
      statusSubTlvPtr->Type = ETHTSYN_AR_SUB_TLV_TYPE_STATUS_SECURED;
      statusSubTlvPtr->CrcStatus = EthTSyn_Crc_ComputeStatusCrc(dataId, statusSubTlvPtr);
    }
    else
#  endif /* (ETHTSYN_CRC_TX_SUPPORT == STD_ON) */
    {
      /* Not Secured */
      statusSubTlvPtr->Type = ETHTSYN_AR_SUB_TLV_TYPE_STATUS_NOT_SECURED;
      statusSubTlvPtr->CrcStatus = 0u;
    }
  }
# endif /* (ETHTSYN_TLV_FOLLOW_UP_STATUS_SUB_TLV_SUPPORT == STD_ON) */

# if (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON)
  /* Append the User Data (Not) Secured Sub-Tlv if applicable */
  if(ETHTSYN_CFG_GET_AR_SUB_TLV_USER_DATA_USED(PortIdx) == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
  {
    /* Add the Sub-Tlv User Data (Not) Secured length to the AR Tlv header length */
    arTlvHdrLengthField += ETHTSYN_AR_SUB_TLV_USER_DATA_LENGTH;

    /* Get the UserData (Not) Secured Sub-Tlv pointer */ /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    userDataSubTlvPtr = (ETHTSYN_P2VAR(EthTSyn_ArSubTlvUserDataType))&(((ETHTSYN_P2VAR(uint8))arTlvHdrPtr)[offset]);
#  if (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON)
    /* Only increase offset if required for further Sub-Tlv */
    offset += ETHTSYN_AR_SUB_TLV_USER_DATA_LENGTH;
#  endif

    /* Set length field */
    userDataSubTlvPtr->Length = ETHTSYN_AR_SUB_TLV_USER_DATA_LENGTH_FIELD_VALUE;

    /* Get the synchronized time base UserData */
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    if(StbM_GetCurrentTime(syncTimeBaseId, &timeStamp, &userData) == E_OK)
    {
      userDataSubTlvPtr->UserDataLength = userData.userDataLength;
      userDataSubTlvPtr->UserByte0 = userData.userByte0;
      userDataSubTlvPtr->UserByte1 = userData.userByte1;
      userDataSubTlvPtr->UserByte2 = userData.userByte2;
    }
    else
    {
      /* Failed to retrieve user data -> set to '0' */
      userDataSubTlvPtr->UserDataLength = 0u;
      userDataSubTlvPtr->UserByte0 = 0u;
      userDataSubTlvPtr->UserByte1 = 0u;
      userDataSubTlvPtr->UserByte2 = 0u;
    }

    /* Write Type Secured/NotSecured and Crc (if applicable) */
#  if (ETHTSYN_CRC_TX_SUPPORT == STD_ON)
    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    if(ETHTSYN_CFG_GET_TX_CRC_SECURED(PortIdx) == ETHTSYN_CRC_TX_SECURED_SUPPORTED)
    {
      /* Secured */
      userDataSubTlvPtr->Type = ETHTSYN_AR_SUB_TLV_TYPE_USER_DATA_SECURED;
      userDataSubTlvPtr->CrcUserData = EthTSyn_Crc_ComputeUserDataCrc(dataId, userDataSubTlvPtr);
    }
    else
#  endif /* (ETHTSYN_CRC_TX_SUPPORT == STD_ON) */
    {
      /* Not Secured */
      userDataSubTlvPtr->Type = ETHTSYN_AR_SUB_TLV_TYPE_USER_DATA_NOT_SECURED;
      userDataSubTlvPtr->CrcUserData = 0u;
    }
  }
# endif /* (ETHTSYN_TLV_FOLLOW_UP_USER_DATA_SUB_TLV_SUPPORT == STD_ON) */

# if (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON)
  /* Append the Ofs (Not) Secured Sub-Tlv if applicable */
  if(ETHTSYN_CFG_GET_AR_SUB_TLV_OFS_USED(PortIdx) == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
  {
    /* Iterate the offset TimeDomains for the given Port and append an Ofs Sub-Tlv for each of them */
    for(offsetTimeDomainIter = 0u; offsetTimeDomainIter < ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_COUNT_OF_PORT(PortIdx);
      offsetTimeDomainIter++)
    {
      uint8 ofsTimeDomainId = ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_ID_OF_PORT(PortIdx, offsetTimeDomainIter);
      StbM_SynchronizedTimeBaseType syncTimeBaseIdOfs =
        ETHTSYN_CFG_GET_OFFSET_TIME_DOMAIN_SYNCHRONIZED_TIME_BASE_ID_OF_PORT(PortIdx, offsetTimeDomainIter);

      /* Add the Sub-Tlv Ofs (Not) Secured length to the AR Tlv header length */
      arTlvHdrLengthField += ETHTSYN_AR_SUB_TLV_OFS_LENGTH;

      /* Get Ofs (Not) Secured Sub-Tlv Pointer */ /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      ofsSubTlvPtr = (ETHTSYN_P2VAR(EthTSyn_ArSubTlvOfsType))&(((ETHTSYN_P2VAR(uint8))arTlvHdrPtr)[offset]);
      offset += ETHTSYN_AR_SUB_TLV_OFS_LENGTH;

      /* Set length field */
      ofsSubTlvPtr->Length = ETHTSYN_AR_SUB_TLV_OFS_LENGTH_FIELD_VALUE;

      /* Set offset time domain */
      ofsSubTlvPtr->OfsTimeDomain = ofsTimeDomainId;

      /* Get Offset and user data */
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      if(StbM_GetOffset(syncTimeBaseIdOfs, &timeStamp, &userData) == E_OK)
      {
        /* Successfully retrieve Offset and user data -> write to Sub-Tlv */
        /* Write Offset */
        ETHTSYN_PUT_UINT16(ofsSubTlvPtr->OfsTimeSec, 0u, timeStamp.secondsHi)
        ETHTSYN_PUT_UINT32(ofsSubTlvPtr->OfsTimeSec, ETHTSYN_AR_SUB_TLV_OFS_TIME_SEC_SECONDS_OFFSET, timeStamp.seconds)
        ETHTSYN_PUT_UINT32(ofsSubTlvPtr->OfsTimeNSec, 0u, timeStamp.nanoseconds)

        /* Write Status */
        ETHTSYN_TIME_BASE_STATUS_TO_AR_SUB_TLV_STATUS(timeStamp.timeBaseStatus, ofsSubTlvPtr->Status);

        /* Write UserData */
        ofsSubTlvPtr->UserDataLength = userData.userDataLength;
        ofsSubTlvPtr->UserByte0 = userData.userByte0;
        ofsSubTlvPtr->UserByte1 = userData.userByte1;
        ofsSubTlvPtr->UserByte2 = userData.userByte2;
      }
      else
      {
        /* Failed to retrieve the Offset and user data -> set to '0' */
        ETHTSYN_PUT_UINT16(ofsSubTlvPtr->OfsTimeSec, 0u, 0u) /*lint !e572 */
        ETHTSYN_PUT_UINT32(ofsSubTlvPtr->OfsTimeSec,
        ETHTSYN_AR_SUB_TLV_OFS_TIME_SEC_SECONDS_OFFSET, 0u) /*lint !e572 */
        ETHTSYN_PUT_UINT32(ofsSubTlvPtr->OfsTimeNSec, 0u, 0u) /*lint !e572 */
        /* Write Status */
        ofsSubTlvPtr->Status = 0u;

        /* Write UserData */
        ofsSubTlvPtr->UserDataLength = 0u;
        ofsSubTlvPtr->UserByte0 = 0u;
        ofsSubTlvPtr->UserByte1 = 0u;
        ofsSubTlvPtr->UserByte2 = 0u;
      }

      /* Write Type Secured/NotSecured and Crc (if applicable) */
#  if (ETHTSYN_CRC_TX_SUPPORT == STD_ON)
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      if(ETHTSYN_CFG_GET_TX_CRC_SECURED(PortIdx) == ETHTSYN_CRC_TX_SECURED_SUPPORTED)
      {
        /* Secured */
        ofsSubTlvPtr->Type = ETHTSYN_AR_SUB_TLV_TYPE_OFS_SECURED;
        ofsSubTlvPtr->CrcOfs = EthTSyn_Crc_ComputeOfsCrc(dataId, ofsSubTlvPtr);
      }
      else
#  endif /* (ETHTSYN_CRC_TX_SUPPORT == STD_ON) */
      {
        /* Not Secured */
        ofsSubTlvPtr->Type = ETHTSYN_AR_SUB_TLV_TYPE_OFS_NOT_SECURED;
        ofsSubTlvPtr->CrcOfs = 0u;
      }
    } /* END: Iteration of all Offset TimeDomains for the given Port */
  }
# endif /* (ETHTSYN_TLV_FOLLOW_UP_OFS_SUB_TLV_SUPPORT == STD_ON) */

  /* Init ArTlvHdr */
  /* Set Tlv Type */
  ETHTSYN_PUT_UINT16(arTlvHdrPtr->TlvType, 0, ETHTSYN_AR_TLV_TYPE) /*lint !e572 */

  /* Set length field */
  ETHTSYN_PUT_UINT16(arTlvHdrPtr->LengthField, 0u, arTlvHdrLengthField)

  /* Set Organization Id and SubType */
  ETHTSYN_PUT_3_BYTE(arTlvHdrPtr->OrganisationId, 0, ETHTSYN_AR_TLV_ORGANIZATION_ID)
  ETHTSYN_PUT_3_BYTE(arTlvHdrPtr->OrganisationSubType, 0, ETHTSYN_AR_TLV_ORGANIZATION_SUB_TYPE)

} /* EthTSyn_AppendArFollowUpTlvs() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: STCAL */
#endif /* (ETHTSYN_TLV_FOLLOW_UP_TX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  EthTSyn_CheckAnnounce
 *********************************************************************************************************************/
#if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
FUNC(boolean, ETHTSYN_CODE) EthTSyn_CheckAnnounce(ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr,
  EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */

  /* Verify the System State */
  /* PRQA S 3415 2 */ /* MD_EthTSyn_12.4 */
  if( (EthTSyn_SystemState[TimeDomainIdx].GmPresent == TRUE) &&
    (EthTSyn_CompareClockIdentity(ComMsgPtr->SourceClockIdentity,
    EthTSyn_SystemState[TimeDomainIdx].GmPriority.PortIdentity.ClockIdentity) == ETHTSYN_COMPARE_EQUAL) )
  {
    retVal = TRUE;
  }

  return retVal;
} /* EthTSyn_CheckAnnounce() */
#endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_CheckSourcePortIdentity
 *********************************************************************************************************************/
#if (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON)
FUNC(boolean, ETHTSYN_CODE) EthTSyn_CheckSourcePortIdentity(
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgPtr, EthTSyn_PortIdxType SlavePortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* Verify source port identity */
  /* PRQA S 3415, 0310 3 */ /* MD_EthTSyn_12.4 */ /* MD_EthTSyn_11.4 */
  if( (EthTSyn_Ntohs(ComMsgPtr->SourcePortNumber) == EthTSyn_CfgGetMasterPortIdentity(SlavePortIdx).PortNumber) &&
      (EthTSyn_CompareClockIdentity(ComMsgPtr->SourceClockIdentity,
         EthTSyn_CfgGetMasterPortIdentity(SlavePortIdx).ClockIdentity) == ETHTSYN_COMPARE_EQUAL) )
  {
    retVal = TRUE;
  }

  return retVal;
} /* EthTSyn_CheckSourcePortIdentity() */
#endif /* (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) */

#if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  EthTSyn_TxPdelayReqMsg
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxPdelayReqMsg(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(uint8) txBufU8Ptr;
  ETHTSYN_P2VAR(EthTSyn_PDelayReqMsgType) pDelayReqPtr;
  ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType) comMsgPtr;
  ETHTSYN_P2VAR(EthTSyn_PdelayReqSmType) pDelayReqSmPtr;
  uint8 bufIdx;
  Std_ReturnType retVal = E_NOT_OK;
  uint16 lenByte = ETHTSYN_MSG_P_DELAY_REQ_LENGTH;
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
  EthSwt_MgmtInfoType mgmtInfo;
  ETHTSYN_P2CONST(EthSwt_MgmtInfoType) mgmtInfoPtr = NULL_PTR;
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
  /* Verify that Pdelay Initiator is present for the given Port */
  if(EthTSyn_IsTxReady(PortIdx) == TRUE)
  {
    if(EthTSyn_CfgAccess_IsPdelayInitiator(PortIdx) == TRUE)
    {
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      if(EthIf_ProvideTxBuffer(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), ETHTSYN_FRAME_TYPE,
        ETHTSYN_CFG_GET_FRAME_PRIORITY(PortIdx), &bufIdx, (ETHTSYN_P2VAR(Eth_DataType*)) &txBufU8Ptr,
        &lenByte) == BUFREQ_OK)
      {
        ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        /* Set Pdelay Request state machine pointer */
        pDelayReqSmPtr = ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx);

        /* reload timeout interval and increment SequenceId */
        pDelayReqSmPtr->PdelayReq.TxIntervalCnt = ETHTSYN_CFG_GET_P_DELAY_REQ_SEND_INTERVAL_MF_CYCLES(PortIdx);
        pDelayReqSmPtr->PdelayReq.SequenceId++;

        /* set message pointers */
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        comMsgPtr = (ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType))txBufU8Ptr;
        pDelayReqPtr = (ETHTSYN_P2VAR(EthTSyn_PDelayReqMsgType))&txBufU8Ptr[ETHTSYN_HDR_COM_LENGTH];

        /* set common header message attributes */
        comMsgPtr->TransSpecific_MessageType = ETHTSYN_HDR_COM_TRANSPORT_SPECIFIC | ETHTSYN_MSG_TYPE_PDELAY_REQ;
        comMsgPtr->Reserved_VersionGPtp = ETHTSYN_PROTOCOL_VERSION;

        comMsgPtr->MessageLength = EthTSyn_Htons((uint16)ETHTSYN_MSG_P_DELAY_REQ_LENGTH); /*lint !e572 */
        comMsgPtr->DomainNumber = EthTSyn_PortConfig[PortIdx].TimeDomainId;

        comMsgPtr->Reserved_0 = 0;
        comMsgPtr->Flags = 0;

        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))comMsgPtr->CorrectionField, 0,
          sizeof(EthTSyn_CorrectionFieldType));

        /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
        IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))comMsgPtr->Reserved_1, 0, ETHTSYN_HDR_COM_RESERVED_1_LENGTH);

        EthTSyn_SetClockIdentity(comMsgPtr->SourceClockIdentity, ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx));
        comMsgPtr->SourcePortNumber = (uint16)EthTSyn_Htons(ETHTSYN_CFG_GET_PORT_NUMBER(PortIdx));

        comMsgPtr->SequenceId = (uint16)EthTSyn_Htons(pDelayReqSmPtr->PdelayReq.SequenceId);
        comMsgPtr->Control = ETHTSYN_HDR_COM_CONTROL_PDELAY_RESP;
        comMsgPtr->LogMessageInterval = ETHTSYN_CFG_GET_P_DELAY_REQ_LOG_MESSAGE_INTERVAL(PortIdx);

        /* set specific message type attributes */
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))pDelayReqPtr->Reserved_0, 0,
          ETHTSYN_MSG_P_DELAY_REQ_RESERVED_0_LENGTH);
        IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))pDelayReqPtr->Reserved_1, 0,
          ETHTSYN_MSG_P_DELAY_REQ_RESERVED_1_LENGTH);

        pDelayReqSmPtr->TxBufIdx = bufIdx;

# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
#  if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
        pDelayReqSmPtr->TxBufPtr = txBufU8Ptr;
#  endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
        if(EthTSyn_IsSwitchPort(PortIdx) == TRUE)
        {
#  if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
          mgmtInfo.FrameId = EthTSyn_GetFrameId(txBufU8Ptr, lenByte);

          CANOE_WRITE_STRING_2("[FRAME_ID_DEBUG] PortIdx: %d FrameId: %d (PdelayReq)",
            PortIdx, mgmtInfo.FrameId);
#   if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
          pDelayReqSmPtr->FrameId = mgmtInfo.FrameId;
#   endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
#  endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
          mgmtInfo.SwitchIdx = EthTSyn_PortConfig[PortIdx].SwtInfo.SwitchIdx;
          mgmtInfo.PortIdx = EthTSyn_PortConfig[PortIdx].SwtInfo.PortIdx;

          mgmtInfoPtr = &mgmtInfo;
        }
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
        pDelayReqSmPtr->PdelayReq.EgressTimestampState =
          ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;

        ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        /* Call to foreign module --> leave critical section is required */
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
        if(EthTSyn_IsSwitchPort(PortIdx) == TRUE)
        {
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          (void)EthIf_SwitchEnableEgressTimeStamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), bufIdx, mgmtInfoPtr);
        }
        else
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
        {
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          (void)EthIf_EnableEgressTimestamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), bufIdx);
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
        }

        /* transmit */
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
        retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_MSG_P_DELAY_REQ_LENGTH, TRUE, mgmtInfoPtr);
# else
        retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_MSG_P_DELAY_REQ_LENGTH, TRUE);
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

        if(retVal == E_OK)
        {
          pDelayReqSmPtr->TxConfirmationPending++;
        }
      }
    }
  }
  return retVal;
} /* EthTSyn_TxPdelayReqMsg() */ /* PRQA S 6050 */ /* MD_MSR_STCAL  */
#endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_TxPdelayRespMsg
 *********************************************************************************************************************/
#if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TxPdelayRespMsg(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(uint8) txBufU8Ptr;
  ETHTSYN_P2VAR(EthTSyn_PdelayRespMsgType) pDelayRespMsgPtr;
  ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType) comMsgPtr;
  ETHTSYN_P2VAR(EthTSyn_PdelayRespSmType) pDelayRespSmPtr;
  uint8 bufIdx;
  Std_ReturnType retVal = E_NOT_OK;
  uint16 lenByte = ETHTSYN_MSG_P_DELAY_RESP_LENGTH;
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
  EthSwt_MgmtInfoType mgmtInfo;
  ETHTSYN_P2CONST(EthSwt_MgmtInfoType) mgmtInfoPtr = NULL_PTR;
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
  /* Set state machine pointer */
  pDelayRespSmPtr = ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx);

  if(EthTSyn_IsTxReady(PortIdx) == TRUE)
  {
    if(EthTSyn_IsTimestampReadyToProcess(pDelayRespSmPtr->PdelayReq.IngressTimestampState) == TRUE)
    {
      ETHTSYN_CHECK_CRITICAL_SECTION_0();
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      if(EthIf_ProvideTxBuffer(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), ETHTSYN_FRAME_TYPE,
        ETHTSYN_CFG_GET_FRAME_PRIORITY(PortIdx), &bufIdx, (ETHTSYN_P2VAR(Eth_DataType*)) &txBufU8Ptr,
        &lenByte) == BUFREQ_OK)
      {
        ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        /* Set message pointers */
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        comMsgPtr = (ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType))txBufU8Ptr;
        pDelayRespMsgPtr = (ETHTSYN_P2VAR(EthTSyn_PdelayRespMsgType))&txBufU8Ptr[ETHTSYN_HDR_COM_LENGTH];

        /* Init common message header */
        EthTSyn_PrepareCommonMsgHdr(comMsgPtr, ETHTSYN_MSG_TYPE_PDELAY_RESP, PortIdx);

        /* Set message specific attributes */
        EthTSyn_SetClockIdentity(pDelayRespMsgPtr->RequestingClockIdentity,
          pDelayRespSmPtr->PdelayReq.SourcePortIdentity.ClockIdentity);

        pDelayRespMsgPtr->RequestingPortNumber =
          (uint16)EthTSyn_Htons(pDelayRespSmPtr->PdelayReq.SourcePortIdentity.PortNumber);

        if(EthTSyn_IsTimestampAvailable(pDelayRespSmPtr->PdelayReq.IngressTimestampState) == TRUE)
        {
          /* Pdelay request ingress timestamp available -> set request received timestamp */
          /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          EthTSyn_HtonTimestamp((ETHTSYN_P2VAR(EthTSyn_TimestampType))pDelayRespMsgPtr->RequestReceiptTimestampSeconds,
            &pDelayRespSmPtr->PdelayReq.IngressTimestamp);
        }
        else
        {
          /* Pdelay request ingress timestamp not available -> set request received timestamp to '0' */
          IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))pDelayRespMsgPtr->RequestReceiptTimestampSeconds, 0u,
            ETHTSYN_TIMESTAMP_SIZE_BYTE);
        }

        /* Store buffer index for TxConfirmation */
        pDelayRespSmPtr->TxBufIdx = bufIdx;

# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
        /* Store Tx buffer pointer if applicable */
        pDelayRespSmPtr->TxBufPtr = txBufU8Ptr;
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

        /* Get switch management info if applicable */
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
        if(EthTSyn_IsSwitchPort(PortIdx) == TRUE)
        {
          mgmtInfo.SwitchIdx = ETHTSYN_CFG_GET_SWITCH_IDX(PortIdx);
          mgmtInfo.PortIdx = ETHTSYN_CFG_GET_SWITCH_PORT_IDX(PortIdx);
          mgmtInfoPtr = &mgmtInfo;
        }
#  if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
        /* Get frame id */
        mgmtInfo.FrameId = EthTSyn_GetFrameId(txBufU8Ptr, lenByte);
        pDelayRespSmPtr->FrameId = mgmtInfo.FrameId;
#  endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

        pDelayRespSmPtr->PdelayResp.EgressTimestampState =
          ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;
        pDelayRespSmPtr->State = ETHTSYN_STATE_P_DELAY_RESP_WAITING_FOR_PDELAY_RESP_EGRESS_TIMESTAMP;

        ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
        if(mgmtInfoPtr != NULL_PTR)
        {
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          retVal = EthIf_SwitchEnableEgressTimeStamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), bufIdx, mgmtInfoPtr);
        }
        else
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
        {
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
          /* Try to enable the egress timestamping */
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          retVal = EthIf_EnableEgressTimestamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), bufIdx);
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
        }
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
        /* Try to enable the egress timestamping */
        if(retVal == E_OK)
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
        {
          /* Transmit message */
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
          retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_MSG_P_DELAY_RESP_LENGTH, TRUE, mgmtInfoPtr);
          CANOE_WRITE_STRING_1("[EthTSyn_TxPdelayRespMsg] RetVal of EthTSyn_Transmit: %s",
            (retVal == 0 ? "E_OK" : "E_NOT_OK"));
# else
          retVal = EthTSyn_Transmit(PortIdx, bufIdx, ETHTSYN_MSG_P_DELAY_RESP_LENGTH, TRUE);
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
        }
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
        else
        {
          /* Failed to enable egress timestamp -> release message buffer and retry transmission */
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          (void)EthIf_Transmit(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), bufIdx, ETHTSYN_FRAME_TYPE, FALSE, 0u,
            (ETHTSYN_P2VAR(uint8))EthTSyn_DestinationMac);
        }
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

      }
    }
  }

  return retVal;
} /* EthTSyn_TxPdelayRespMsg() */
/* PRQA L: STCAL */
#endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_Transmit
 *********************************************************************************************************************/
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_Transmit(EthTSyn_PortIdxType PortIdx, uint8 BufIdx, uint16 LenByte,
  boolean TxConfirmation, ETHTSYN_P2CONST(EthSwt_MgmtInfoType) MgmtInfoPtr)
#else
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_Transmit(EthTSyn_PortIdxType PortIdx, uint8 BufIdx,
  uint16 LenByte, boolean TxConfirmation)
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 ctrlIdx = ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx); /* PRQA S 0781 */ /* MD_EthTSyn_5.6 */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
  /* Set the switch egress port for the message to be transmitted */
  if(MgmtInfoPtr != NULL_PTR)
  {
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    (void)EthIf_SetSwitchMgmtInfo(ctrlIdx, BufIdx, MgmtInfoPtr);
  }
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

  ETHTSYN_CHECK_CRITICAL_SECTION_0();
  if(EthIf_Transmit(ctrlIdx, BufIdx, ETHTSYN_FRAME_TYPE, TxConfirmation, LenByte,
    (ETHTSYN_P2VAR(uint8))EthTSyn_DestinationMac) == E_OK)
  {
    retVal = E_OK;
  }
  else
  {
    errorId = ETHTSYN_E_TX_FAILED;
    /* Release TxBuffer */
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    (void)EthIf_Transmit(ctrlIdx, BufIdx, ETHTSYN_FRAME_TYPE, TxConfirmation, 0,
      (ETHTSYN_P2VAR(uint8))EthTSyn_DestinationMac);
  }

#if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_TRANSMIT, errorId);
  }
#else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
} /* EthTSyn_Transmit() */

/**********************************************************************************************************************
 *  EthTSyn_GetCurrentPdelay
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_GetCurrentPdelay(EthTSyn_PortIdxType PortIdx,
  ETHTSYN_P2VAR(EthTSyn_PdelayType) PdelayPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if(PortIdx < ETHTSYN_PORT_COUNT)
  {
#if (ETHTSYN_P_DELAY_CONFIG_COUNT > 1u)
    if(ETHTSYN_CFG_GET_PDELAY_IDX(PortIdx) >= ETHTSYN_P_DELAY_CONFIG_COUNT)
    {
      *PdelayPtr = 0;
    }
    else
#endif /* (ETHTSYN_P_DELAY_CONFIG_COUNT > 1u) */
    {
      if(ETHTSYN_CFG_GET_P_DELAY_USE_STATIC(PortIdx) == TRUE)
      {
        *PdelayPtr = ETHTSYN_CFG_GET_P_DELAY_INITIAL_NS(PortIdx);
        retVal = E_OK;
      }
#if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
      else
      {
        if(EthTSyn_CfgAccess_IsPdelayInitiator(PortIdx) == TRUE)
        {
          *PdelayPtr = ETHTSYN_CFG_GET_P_DELAY_INITIATOR_CFG_PTR(PortIdx)->PdelayReqSmPtr->Pdelay;
          retVal = E_OK;
        }
        else
        {
          *PdelayPtr = 0;
          retVal = E_OK;
        }
      }
#endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */
    }
  }

  return retVal;
} /* EthTSyn_GetCurrentPdelay() */

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmPdelayResp
 *********************************************************************************************************************/
#if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmPdelayResp(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_PdelayRespSmType) pDelayRespSmPtr = ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx);
  EthTSyn_PortIdxType activePortIdx = ETHTSYN_CFG_GET_P_DELAY_ACTIVE_PORT_IDX(PortIdx);
# if (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u)
  ETHTSYN_DUMMY_STATEMENT(PortIdx); /* PRQA S 3112 */ /* MD_MSR_14.2 */
# endif /* (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u) */

  /* ----- Implementation ----------------------------------------------- */
  switch(pDelayRespSmPtr->State)
  {
  case ETHTSYN_STATE_P_DELAY_RESP_NOT_ENABLED:
    if(ETHTSYN_STATE_GET_LINK_STATE(activePortIdx) == ETHTRCV_LINK_STATE_ACTIVE)
    {
      pDelayRespSmPtr->State = ETHTSYN_STATE_P_DELAY_RESP_INITAIL_WAITING_FOR_PDELAY_REQ;
    }
    break;

  case ETHTSYN_STATE_P_DELAY_RESP_SEND_P_DELAY_RESP:
    if(EthTSyn_TxPdelayRespMsg(activePortIdx) == E_OK)
    {
      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      pDelayRespSmPtr->TxConfirmationPending++;
      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
    break;

  case ETHTSYN_STATE_P_DELAY_RESP_WAITING_FOR_PDELAY_RESP_EGRESS_TIMESTAMP:
    /* Check if TxConfirmation for send Pdelay response occurred */
    if(pDelayRespSmPtr->TxConfirmationPending == 0)
    {
      if(EthTSyn_TxPdelayRespFollowUpMsg(activePortIdx) == E_OK)
      {
        pDelayRespSmPtr->State = ETHTSYN_STATE_P_DELAY_RESP_WAITING_FOR_PDELAY_REQ;
      }
      else
      {
        pDelayRespSmPtr->State = ETHTSYN_STATE_P_DELAY_RESP_SEND_P_DELAY_RESP_FOLLOW_UP;
      }
    }
    break;

  case ETHTSYN_STATE_P_DELAY_RESP_SEND_P_DELAY_RESP_FOLLOW_UP:
    if(EthTSyn_TxPdelayRespFollowUpMsg(activePortIdx) == E_OK)
    {
      pDelayRespSmPtr->State = ETHTSYN_STATE_P_DELAY_RESP_WAITING_FOR_PDELAY_REQ;
    }
    break;

  default:
    /* This should never happen (MISRA) */
    break;
  }

}/* PRQA S 2006 */ /* MD_MSR_14.7 */ /* PRQA S 6010 */ /* MD_MSR_STPTH */ /* PRQA S 6030 */ /* MD_MSR_STCYC */
/* EthTSyn_ProcessSmPdelayResp() */
#endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmSyncReceive
 *********************************************************************************************************************/
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
/* PRQA S 2006 RETPA */ /* MD_MSR_14.7 */
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmSyncReceive(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_TimeDomainIdxType timeDomainIdx;
  ETHTSYN_P2VAR(EthTSyn_SyncReceiveSmType) syncReceiveSmPtr;

  /* ----- Implementation ----------------------------------------------- */
  if(PortIdx < ETHTSYN_PORT_COUNT)
  {
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    timeDomainIdx = EthTSyn_CfgAccess_GetTimeDomainIdx(EthTSyn_PortConfig[PortIdx].TimeDomainId);
  }
  else
  {
    timeDomainIdx = ETHTSYN_INVALID_TIME_DOMAIN_IDX;
  }

  if( (PortIdx < ETHTSYN_PORT_COUNT) && (timeDomainIdx < ETHTSYN_TIME_DOMAIN_COUNT))
  {
    syncReceiveSmPtr = ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

    ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    switch(syncReceiveSmPtr->State)
    {
    case ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_FOLLOW_UP:
      /* check for FollowUp received timeout */
      if(syncReceiveSmPtr->FollowUp.FollowUpRxTimeoutCnt == 0) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
      {
        /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
        syncReceiveSmPtr->State = ETHTSYN_STATE_SYNC_RECEIVE_DISCARD;
        CANOE_WRITE_STRING("EthTSyn_Mainfunction: FollowUp Timeout");
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
        /* Reset state of all SyncSend state machines (Ports) of the TimeDomain */
        if(EthTSyn_CfgGetSlavePortCnt(timeDomainIdx) > 0)
        {
          if(EthTSyn_TimeDomainConfig[timeDomainIdx].MasterPortCnt > 0)
          {
            /* PRQA S 0781 1 */ /* MD_EthTSyn_5.6 */
            EthTSyn_PortIdxType MasterPortCnt = EthTSyn_TimeDomainConfig[timeDomainIdx].MasterPortCnt;

            while(MasterPortCnt > 0)
            {
              MasterPortCnt--;
              /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
              ETHTSYN_SYNC_SEND_SM_PTR(
                EthTSyn_TimeDomainConfig[timeDomainIdx].MasterPortIdxPtr[MasterPortCnt])->State =
                  ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_PENDING;
            }
          }
        }
        /* Reset state of SiteSyncSync state machine */
        if(EthTSyn_SiteSyncSyncSm(timeDomainIdx).State == ETHTSYN_STATE_SITE_SYNC_SYNC_SEND_FOLLOW_UP)
        {
          EthTSyn_SiteSyncSyncSm(timeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_PENDING;
        }
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
      }
      break;
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
# if (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON)
    case ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_SYNC:
      if( (EthTSyn_CfgGetSlavePortCnt(timeDomainIdx) > 0) &&
          ( (EthTSyn_GetPortType(PortIdx) & ETHTSYN_PORT_TYPE_SWITCH_PORT) != 0) )
      {
        if(syncReceiveSmPtr->Sync.SyncRxTimeoutCnt == 0) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        {
          /* Take up role as master now */
          uint16 masterPortCnt = EthTSyn_CfgGetMasterPortCnt(timeDomainIdx);
          EthTSyn_PortIdxType masterPortIdx;

          EthTSyn_SiteSyncSyncSm(timeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_SYNC_TIMEOUT;
          syncReceiveSmPtr->State = ETHTSYN_STATE_SYNC_RECEIVE_SYNC_TIMEOUT;
          ETHTSYN_STATE_GET_SLAVE_PORT_IDX(timeDomainIdx) = ETHTSYN_INVALID_PORT_IDX;
          /* Initialize the SyncSendSm of each Master-Port of the TimeDomain */
          while(masterPortCnt > 0)
          {
            ETHTSYN_P2VAR(EthTSyn_SyncSendSmType) syncSendSmPtr;
            masterPortCnt--;
            masterPortIdx = EthTSyn_CfgGetMasterPortIdx(timeDomainIdx, masterPortCnt);
            syncSendSmPtr = ETHTSYN_SYNC_SEND_SM_PTR(masterPortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
            syncSendSmPtr->SyncTxBufIdx = ETHTSYN_INV_BUF_IDX;
            syncSendSmPtr->FollowUpTxBufIdx = ETHTSYN_INV_BUF_IDX;
            syncSendSmPtr->TxConfirmationPending = 0;
            syncSendSmPtr->SequenceId = 0;
            /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
            syncSendSmPtr->LogMessageInterval =
                EthTSyn_MasterPortConfigPtr(masterPortIdx)->SyncLogMessageInterval;
            syncSendSmPtr->TxIntervalCnt =
                EthTSyn_MasterPortConfigPtr(masterPortIdx)->SyncSendInterval; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

            syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_INITIALIZING;
          }
        }
      }
      break;
# endif /* (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON) */
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
    default:
      /* do nothing */
      break;
    }
    ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
} /* EthTSyn_ProcessSmSyncReceive() */
/* PRQA L: STCYC */
/* PRQA L: STMIF */
/* PRQA L: RETPA */
/* PRQA L: STPTH */

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmPdelayReq
 *********************************************************************************************************************/
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
#if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmPdelayReq(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_PdelayReqSmType) pDelayReqSmPtr = ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx);
  EthTSyn_PortIdxType activePortIdx = ETHTSYN_CFG_GET_P_DELAY_ACTIVE_PORT_IDX(PortIdx);
# if (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u)
  ETHTSYN_DUMMY_STATEMENT(PortIdx); /* PRQA S 3112 */ /* MD_MSR_14.2 */
# endif /* (ETHTSYN_P_DELAY_CONFIG_COUNT <= 1u) */

  /* ----- Implementation ----------------------------------------------- */
  switch(pDelayReqSmPtr->State)
  {
  case ETHTSYN_STATE_P_DELAY_REQ_NOT_ENABLED:
    if(ETHTSYN_STATE_GET_LINK_STATE(activePortIdx) == ETHTRCV_LINK_STATE_ACTIVE)
    {
      pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_INITIAL_SEND_P_DELAY_REQ;
    }
    break;

  case ETHTSYN_STATE_P_DELAY_REQ_INITIAL_SEND_P_DELAY_REQ:
  case ETHTSYN_STATE_P_DELAY_REQ_SEND_P_DELAY_REQ:
    if(EthTSyn_TxPdelayReqMsg(activePortIdx) == E_OK)
    {
      pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP;
      pDelayReqSmPtr->PdelayRespRespFollowUpTimeout =
        ETHTSYN_CFG_GET_P_DELAY_RESP_RESP_FOLLOW_UP_TIMEOUT(activePortIdx);
    }
    break;

  case ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP:
  case ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP_FOLLOW_UP:
    /* Check for Pdelay response timeout */
    {
      boolean txPdelayReq = FALSE;
      boolean lostResponse = FALSE;

      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      if (pDelayReqSmPtr->PdelayReq.TxIntervalCnt == 0u)
      {
        txPdelayReq = TRUE;
        lostResponse = TRUE;
      }
      else if(ETHTSYN_CFG_GET_P_DELAY_RESP_RESP_FOLLOW_UP_TIMEOUT(activePortIdx) > 0)
      {
        if(pDelayReqSmPtr->PdelayRespRespFollowUpTimeout == 0u)
        {
          lostResponse = TRUE;
        }
      }
      else
      {
        /* Nothing to do here (MISRA) */
      }
      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      if(lostResponse == TRUE)
      {
# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
        /* check for lost response limit */
        ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        if(pDelayReqSmPtr->LostResponses < ETHTSYN_CFG_GET_P_DELAY_ALLOWED_LOST_RESPONSES(activePortIdx))
        {
          pDelayReqSmPtr->LostResponses++;
        }
        else
        {
          /* lost response limit exceeded */
          pDelayReqSmPtr->AsCapable = ETHTSYN_CFG_GET_ALWAYS_AS_CAPABLE(PortIdx);
        }
        ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
        if(txPdelayReq == TRUE)
        {
          if(EthTSyn_TxPdelayReqMsg(activePortIdx) == E_OK)
          {
            pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP;
            pDelayReqSmPtr->PdelayRespRespFollowUpTimeout =
              ETHTSYN_CFG_GET_P_DELAY_RESP_RESP_FOLLOW_UP_TIMEOUT(activePortIdx);
          }
          else
          {
            pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_SEND_P_DELAY_REQ;
          }
        }
        else
        {
          pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_PDELAY_INTERVAL_COUNTER;
        }
      }
    }
    break;

  case ETHTSYN_STATE_P_DELAY_REQ_RECEIVED_PDELAY_RESP_AND_PDELAY_RESP_FOLLOW_UP:
    /* Check if TxConfirmation for sent Pdelay request occurred */
    if(pDelayReqSmPtr->TxConfirmationPending == 0)
    {
      if(EthTSyn_IsTimestampReadyToProcess(pDelayReqSmPtr->PdelayReq.EgressTimestampState) == TRUE)
      {
        /* all values of Pdelay request sequence are available --> path delay calculation is possible */
        if(ETHTSYN_CFG_GET_P_DELAY_USE_STATIC(activePortIdx) == FALSE)
        {
          /* Compute new Pdelay */
# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
          if(EthTSyn_ComputePdelay(activePortIdx) == E_OK)
          {
            pDelayReqSmPtr->AsCapable = TRUE;
          }
          else
          {
            pDelayReqSmPtr->AsCapable = ETHTSYN_CFG_GET_ALWAYS_AS_CAPABLE(activePortIdx);
          }
# else
          (void)EthTSyn_ComputePdelay(activePortIdx);
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
        }

        pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_PDELAY_INTERVAL_COUNTER;
      }
    }
    break;

  case ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_PDELAY_INTERVAL_COUNTER:
    if(pDelayReqSmPtr->PdelayReq.TxIntervalCnt == 0u)
    {
      if(EthTSyn_TxPdelayReqMsg(activePortIdx) == E_OK)
      {
        pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP;
        pDelayReqSmPtr->PdelayRespRespFollowUpTimeout =
          ETHTSYN_CFG_GET_P_DELAY_RESP_RESP_FOLLOW_UP_TIMEOUT(activePortIdx);
      }
      else
      {
        pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_SEND_P_DELAY_REQ;
      }
    }
    break;

  default:
    /* do nothing */
    break;
  } /* END: switch(pDelayReqSmPtr->State) */

} /* EthTSyn_ProcessSmPdelayReq() */
/* PRQA L: STCYC */
/* PRQA L: STMIF */
#endif /* (STD_ON == ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT) */

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmSyncSend
 *********************************************************************************************************************/
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmSyncSend(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_SyncSendSmType) syncSendSmPtr;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */

  /* check for master state -> Process SyncSend state-machine only in master state */
  if(EthTSyn_CfgGetPortRole(PortIdx) == ETHTSYN_PORT_ROLE_MASTER)
  {
    syncSendSmPtr = ETHTSYN_SYNC_SEND_SM_PTR(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    /* Port is MasterPort */
    switch(syncSendSmPtr->State)
    {
    case ETHTSYN_STATE_SYNC_SEND_INITIALIZING:
      syncSendSmPtr->SequenceId = 0;
      syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_WAITING_FOR_SYNC_SEND;
      break;

    case ETHTSYN_STATE_SYNC_SEND_WAITING_FOR_SYNC_SEND:
      /* check for sync tx timeout */
      if(syncSendSmPtr->TxIntervalCnt == 0)
      {
#if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
        /* Check if the Port is AsCapable */
        if(ETHTSYN_GET_AS_CAPABLE(PortIdx) == TRUE)
#endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
        {
          /* transmit Sync message immediately */
          if(EthTSyn_TxSyncMsg(PortIdx) == E_OK)
          {
            ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            syncSendSmPtr->TxConfirmationPending++;
            ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
            syncSendSmPtr->TxIntervalCnt = ((ETHTSYN_P2CONSTCFG(EthTSyn_MasterPortConfigType))
                EthTSyn_PortConfig[PortIdx].PortRolePtr)->SyncSendInterval;
          }
          else
          {
            syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_SEND_SYNC;
            errorId = ETHTSYN_E_TX_FAILED;
          }
        } /* END: Check if Port is AsCapable and Enabled */
      } /* END: if(EthTSyn_SyncSendSm(PortIdx).TxIntervalCnt == 0) */
      break;

    case ETHTSYN_STATE_SYNC_SEND_SEND_SYNC:
#if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
        /* Check if the Port is enabled and AsCapable */
      if(ETHTSYN_GET_AS_CAPABLE(PortIdx) == TRUE)
#endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
      {
        /* transmit Sync message */
        if(EthTSyn_TxSyncMsg(PortIdx) == E_OK)
        {
          ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          syncSendSmPtr->TxConfirmationPending++;
          ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
          syncSendSmPtr->TxIntervalCnt = ((ETHTSYN_P2CONSTCFG(EthTSyn_MasterPortConfigType))
              EthTSyn_PortConfig[PortIdx].PortRolePtr)->SyncSendInterval;
        }
        else
        {
          syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_SEND_SYNC;
        }
      }
      break;

    case ETHTSYN_STATE_SYNC_SEND_SEND_FOLLOW_UP:
      /* Check if TxConfirmation for sent Sync message occurred */
      if(syncSendSmPtr->TxConfirmationPending == 0)
      {
#if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
        /* Check if the Port is enabled and AsCapable */
        if(ETHTSYN_GET_AS_CAPABLE(PortIdx) == TRUE)
#endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
        {
          if(EthTSyn_TxFollowUpMsg(PortIdx) == E_OK)
          {
            ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

            syncSendSmPtr->SequenceId++;
            syncSendSmPtr->FollowUpPreciseOriginTimestampState =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_INVALID;
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
            syncSendSmPtr->SyncEgressTimestampStateSwitchPort =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_INVALID;
            syncSendSmPtr->SyncIngressTimestampStateHostPort =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_INVALID;
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
            syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_WAITING_FOR_SYNC_SEND;

            ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

#if (ETHTSYN_ANNOUNCE_TX_SUPPORT == STD_ON)
            if(EthTSyn_MasterPortConfigPtr(PortIdx)->TxAnnounceMsg == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
            {
              if(EthTSyn_TxAnnounceMsg(PortIdx) != E_OK)
              {
                errorId = ETHTSYN_E_TX_FAILED;
              }
            }
#endif /* (ETHTSYN_ANNOUNCE_TX_SUPPORT == STD_ON) */
          }
        }
      }
      break;
    default:
      /* do nothing */;
      break;
    } /* END: Switch(SyncSendSm State) */
  } /* END: If MasterPort */

#if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_SM_SYNC_SEND, errorId);
  }
#else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */
} /* EthTSyn_ProcessSmSyncSend() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L: STMIF */
/* PRQA L: STCYC */
/* PRQA L: STPTH */

/**********************************************************************************************************************
 *  EthTSyn_ProcessSmAnnounceReceive
 *********************************************************************************************************************/
#if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
FUNC(void, ETHTSYN_CODE) EthTSyn_ProcessSmAnnounceReceive(EthTSyn_PortIdxType PortIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  if(ETHTSYN_GET_AS_CAPABLE(PortIdx) == TRUE)
  {
    if(ETHTSYN_ANNOUNCE_RECEIVE_SM_PTR(PortIdx)->RxTimeoutCnt == 0) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    {
      EthTSyn_ResetMasterPriorityVector(ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(PortIdx));
    }
  }

} /* EthTSyn_ProcessSmAnnounceReceive() */
#endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_EndStation_ProcessReceivedSync
 *********************************************************************************************************************/
#if ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_END_STATION_SUPPORT == STD_ON) )
FUNC(void, ETHTSYN_CODE) EthTSyn_EndStation_ProcessReceivedSync(EthTSyn_PortIdxType  PortIdx,
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgHdrPtr,
  ETHTSYN_P2CONST(EthTSyn_SwtMgmt_RxFrameInfoType) RxFrameInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_SyncReceiveSmType) syncReceiveSmPtr;
  ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType) SyncIngressTimestampPtr = &RxFrameInfoPtr->IngressTimestamp;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  /* check for min/correct Sync message length */
  if(ETHTSYN_MSG_SYNC_LENGTH != EthTSyn_Ntohs(ComMsgHdrPtr->MessageLength))
  {
    errorId = ETHTSYN_E_INV_MSG_LENGTH;
  }
  else
  {
    if(EthTSyn_CfgGetPortRole(PortIdx) == ETHTSYN_PORT_ROLE_SLAVE)
    {
      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      syncReceiveSmPtr = ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

      if( (syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_DISCARD) ||
        (syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_SYNC) )
      {
        /* store the current ingress timestamp */
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
        /* HW-Timestamping */
        syncReceiveSmPtr->Sync.IngressTimestamp = *SyncIngressTimestampPtr;
# else
        /* SW-Timestamping */
        syncReceiveSmPtr->Sync.IngressTimestamp.nanoseconds = SyncIngressTimestampPtr->nanoseconds;
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
        syncReceiveSmPtr->Sync.IngressTimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;

        /* set Sync message attributes */
        syncReceiveSmPtr->Sync.LogMessageInterval = ComMsgHdrPtr->LogMessageInterval;

        EthTSyn_SetClockIdentity(syncReceiveSmPtr->Sync.SourcePortIdentity.ClockIdentity,
          ComMsgHdrPtr->SourceClockIdentity);
        syncReceiveSmPtr->Sync.SourcePortIdentity.PortNumber =
          (uint16)EthTSyn_Ntohs(ComMsgHdrPtr->SourcePortNumber);

        /* store sequence id */
        syncReceiveSmPtr->Sync.SequenceId = (uint16)EthTSyn_Ntohs(ComMsgHdrPtr->SequenceId);

        /* set FollowUp receive timeout time */
        syncReceiveSmPtr->FollowUp.FollowUpRxTimeoutCnt =
          EthTSyn_SlavePortConfigPtr(PortIdx)->FollowUpAllowedRxDelay; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

        /* change state to waiting for FollowUp */
        syncReceiveSmPtr->State = ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_FOLLOW_UP;
      }
      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

# if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_RX_INDICATION, errorId);
  }
# else
  ETHTSYN_DUMMY_STATEMENT(errorId);
# endif /*  */
} /* EthTSyn_EndStation_ProcessReceivedSync() */
#endif /* ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_END_STATION_SUPPORT == STD_ON) ) */

/**********************************************************************************************************************
 *  EthTSyn_EndStation_ProcessReceivedFollowUp
 *********************************************************************************************************************/
/*! \brief      Processing of a received FollowUp message on an End-Station port
 *  \param[in]  PortIdx          Index of the port the message was received on
 *  \param[in]  ComMsgHdrPtr     Pointer to the common PTP message header
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
#if ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_END_STATION_SUPPORT == STD_ON) )
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
FUNC(void, ETHTSYN_CODE) EthTSyn_EndStation_ProcessReceivedFollowUp(EthTSyn_PortIdxType PortIdx,
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) ComMsgHdrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean readyToProcess = FALSE;
  ETHTSYN_P2CONST(EthTSyn_FollowUpMsgType) followUpMsgPtr;
  ETHTSYN_P2VAR(EthTSyn_SyncReceiveSmType) syncReceiveSmPtr = NULL_PTR;
# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
  uint8 subTlvCnt = 0;
  ETHTSYN_P2CONST(EthTSyn_ArSubTlvAbstractHeaderType) firstSubTlvPtr = NULL_PTR;
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

  /* ----- Implementation ----------------------------------------------- */
  if(EthTSyn_CfgGetPortRole(PortIdx) == ETHTSYN_PORT_ROLE_SLAVE)
  {
    syncReceiveSmPtr = ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

    /* Check Sync Receive state machine state and matching Sequence Id */
    if((syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_FOLLOW_UP) &&
      (syncReceiveSmPtr->Sync.SequenceId == (uint16)EthTSyn_Ntohs(ComMsgHdrPtr->SequenceId)))
    {
      /* Check for matching source port identity */
      if((EthTSyn_CompareClockIdentity(ComMsgHdrPtr->SourceClockIdentity,
        syncReceiveSmPtr->Sync.SourcePortIdentity.ClockIdentity) == ETHTSYN_COMPARE_EQUAL) &&
        ((EthTSyn_PortNumberType)EthTSyn_Ntohs(ComMsgHdrPtr->SourcePortNumber) ==
        syncReceiveSmPtr->Sync.SourcePortIdentity.PortNumber))
      {
# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
        if(EthTSyn_GetFirstArSubTlvPtrAndCnt(PortIdx, ComMsgHdrPtr, &firstSubTlvPtr, &subTlvCnt) == E_OK)
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */
        /* Check Crc(s) if applicable */
        {
          readyToProcess = TRUE;
        }
      }
    }
  }

  if((readyToProcess == TRUE) && (syncReceiveSmPtr != NULL_PTR))
  {
    EthTSyn_GlobalTimestampType timeStamp; /* used to call StbM_BusSetGlobalTime */
    EthTSyn_TimediffType timeDiff = 0;
    EthTSyn_PdelayType pDelay = 0;
    boolean callBusSetGlobalTime = FALSE;
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    EthTSyn_GlobalTimestampType timeStampRef; /* used as reference Timestamp when HW-Timestamping is used */
    Eth_TimestampQualityType timeStampQual;
# else
    EthTSyn_TimestampRawType timeStampDiff; /* used to show the time passed between Sync and FollowUp reception */
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

    /* Get FollowUp message pointer */ /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    followUpMsgPtr = (ETHTSYN_P2CONST(EthTSyn_FollowUpMsgType))
      &((ETHTSYN_P2CONST(uint8))ComMsgHdrPtr)[ETHTSYN_HDR_COM_LENGTH];

    /* Get the precise origin timestamp from followUp message */ /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    EthTSyn_NtohTimestamp(&timeStamp,
      (ETHTSYN_P2CONST(EthTSyn_TimestampType))followUpMsgPtr->PreciseOriginTimestampSeconds);

# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
    /* HW-Timestamping */
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    if(EthIf_GetCurrentTime(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(PortIdx), &timeStampQual, &timeStampRef) == E_OK)
    {
      if(timeStampQual == ETH_VALID)
      {
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        if(EthTSyn_TimestampMinusTimestamp(&timeStampRef,
          &ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx)->Sync.IngressTimestamp, &timeDiff) == E_OK)
        {
          callBusSetGlobalTime = TRUE;
        }
      }
    }
# else
    /* SW-Timestamping */
    ETHTSYN_CHECK_CRITICAL_SECTION_0();
    /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
    if(StbM_GetCurrentTimeDiff(ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx)->Sync.IngressTimestamp.nanoseconds,
      &timeStampDiff) == E_OK)
    {
      timeDiff = (EthTSyn_TimediffType)timeStampDiff;
      callBusSetGlobalTime = TRUE;
    }
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
    if(callBusSetGlobalTime == TRUE)
    {
      /* Add pDelay and correctionField to the timeDiff */
      if(EthTSyn_GetCurrentPdelay(PortIdx, &pDelay) == E_OK)
      {
        timeDiff += (EthTSyn_TimediffType)pDelay;
      }
      timeDiff += (EthTSyn_TimediffType)
        ETHTSYN_GET_FOLLOW_UP_CORRECTION_VALUE_NS_FROM_MSG(ComMsgHdrPtr->CorrectionField);

      if(EthTSyn_TimestampPlusTimediff(&timeStamp, (ETHTSYN_P2CONST(EthTSyn_TimediffType))&timeDiff) == E_OK)
      {
        StbM_TimeStampType timeStampStbm;
        ETHTSYN_P2CONST(StbM_UserDataType) userDataPtr = NULL_PTR;
        StbM_TimeBaseStatusType status = 0;
        boolean syncToTimeBase = FALSE;
# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
        StbM_UserDataType userData;
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
        /* Check if UserData Sub-Tlv is present */
        if(firstSubTlvPtr != NULL_PTR)
        {
          if(EthTSyn_GetUserDataFromSubTlv(firstSubTlvPtr, subTlvCnt, &userData) == E_OK)
          {
            userDataPtr = (ETHTSYN_P2CONST(StbM_UserDataType))&userData;
          }

          if(EthTSyn_GetStatusFromSubTlv(firstSubTlvPtr, subTlvCnt, &status) == E_NOT_OK)
          {
            status = 0;
          }

#  if (ETHTSYN_OFS_TIME_DOMAIN_SUPPORT == STD_ON)
          EthTSyn_HandleOfsSubTlvs(ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(PortIdx), firstSubTlvPtr, subTlvCnt);
#  endif /* (ETHTSYN_OFS_TIME_DOMAIN_SUPPORT == STD_ON) */
        }
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

        ETHTSYN_COPY_GLOBAL_TS_TO_STBM_TS_W_TBS(timeStamp, timeStampStbm, status)
# if (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF)
        if((status & ETHTSYN_TIME_BASE_STATUS_SYNC_TO_GW_MASK) != 0)
        {
          syncToTimeBase = TRUE;
        }
# endif /* (ETHTSYN_MESSAGE_COMPLIANCE == STD_OFF) */

        (void)StbM_BusSetGlobalTime(
          ETHTSYN_CFG_GET_SYNCHRONIZED_TIME_BASE_ID(ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(PortIdx)),
          (ETHTSYN_P2CONST(StbM_TimeStampType))&timeStampStbm, userDataPtr, syncToTimeBase);
      }
    }
  }
} /* EthTSyn_EndStation_ProcessReceivedFollowUp() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: STCAL */
#endif /* ( (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) && (ETHTSYN_END_STATION_SUPPORT == STD_ON) ) */

/**********************************************************************************************************************
 *  EthTSyn_RxIndication
 *********************************************************************************************************************/
/*! \brief        Processing of received EthTSyn frames.
 *  \param[in]    CtrlIdx        Index of the controller that received the frame
 *  \param[in]    FrameType      Ethertype of the received frame
 *  \param[in]    IsBroadcast    Determines that the frame is send to a broadcast destination
 *  \param[in]    PhysAddrPtr    Pointer to the physical address of the sender
 *  \param[in]    DataPtr        Pointer to the received data
 *  \param[in]    LenByte        Byte count of the received data
 *  \return       none
 *  \pre          The function EthTSyn_Init() must be called first
 *  \context      This function can be called in any context.
 *********************************************************************************************************************/
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6060 STPAR */ /* MD_MSR_STPAR */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
#if ( defined(ETHTSYN_ETHIF_AR_VERSION_GREATER_EQUAL_4_2_2) && \
       (ETHTSYN_ETHIF_AR_VERSION_GREATER_EQUAL_4_2_2 == TRUE) )
FUNC(void, ETHTSYN_CODE) EthTSyn_RxIndication(uint8 CtrlIdx, Eth_FrameType FrameType, boolean IsBroadcast,
  ETHTSYN_P2CONST(uint8) PhysAddrPtr, ETHTSYN_P2VAR(uint8) DataPtr, uint16 LenByte)
#else
/* PRQA S 3673 2 */ /* MD_EthTSyn_16.7c */
FUNC(void, ETHTSYN_CODE) EthTSyn_RxIndication(uint8 CtrlIdx, Eth_FrameType FrameType, boolean IsBroadcast,
  ETHTSYN_P2VAR(uint8) PhysAddrPtr, ETHTSYN_P2VAR(uint8) DataPtr, uint16 LenByte)
#endif
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHTSYN_E_NO_ERROR;
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)
  EthTSyn_PortIdxType portIdx = ETHTSYN_INVALID_PORT_IDX;
  EthTSyn_TimeDomainIdxType timeDomainIdx = ETHTSYN_INVALID_TIME_DOMAIN_IDX;
  /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) comMsgPtr = (ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))DataPtr;
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) */

  /* ----- Development Error Checks ------------------------------------- */
#if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if (EthTSyn_State == ETHTSYN_STATE_UNINIT)
  {
    errorId = ETHTSYN_E_NOT_INITIALIZED;
  }
  else if (DataPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else if (PhysAddrPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else if (FrameType != ETHTSYN_FRAME_TYPE)
  {
    errorId = ETHTSYN_E_INV_FRAME_TYPE;
  }
  else if (EthTSyn_GetEthTSynCtrlFromEthIfCtrl(CtrlIdx) >= ETHTSYN_CTRL_COUNT)
  {
    errorId = ETHTSYN_E_CTRL_IDX;
  }
  else if(EthTSyn_CtrlState[EthTSyn_GetEthTSynCtrlFromEthIfCtrl(CtrlIdx)].TrcvLinkState == ETHTRCV_LINK_STATE_DOWN)
  {
    errorId = ETHTSYN_E_TRCV_DOWN;
  }
  else
#endif
  {
# if (ETHTSYN_DEV_ERROR_DETECT == STD_OFF)
    ETHTSYN_DUMMY_STATEMENT(FrameType); /* PRQA S 3112 */ /* MD_MSR_14.2 */
    ETHTSYN_DUMMY_STATEMENT(PhysAddrPtr); /* PRQA S 3112 */ /* MD_MSR_14.2 */
# endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_OFF) */
    ETHTSYN_DUMMY_STATEMENT(IsBroadcast); /* PRQA S 3112 */ /* MD_MSR_14.2 */
    /* ----- Implementation ----------------------------------------------- */
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
    /* With switch management */
    /* Pass the received Frame to the Switch management */
    EthTSyn_SwtMgmt_RxIndication(CtrlIdx, DataPtr, LenByte);
#else
    /* Without switch management */
    /* Check message */
    if(EthTSyn_CheckMessageGeneral(DataPtr, LenByte, &timeDomainIdx, &errorId) == E_OK)
    {
      /* General message attributes valid */
      /* Check message Type and length */
      if(EthTSyn_CheckMessageTypeAndLength(comMsgPtr, LenByte, &errorId) == E_OK)
      {
        EthTSyn_PortIdxType portCounter;
        /* valid message type and length -> continue processing */
        /* Get EthTSyn Port */
        for(portCounter = 0; portCounter < ETHTSYN_PORT_COUNT; portCounter++)
        {
          if((ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(portCounter) == CtrlIdx) &&
            (EthTSyn_PortConfig[portCounter].TimeDomainId == comMsgPtr->DomainNumber))
          {
            /* Port found -> store index and stop iteration */
            portIdx = portCounter;
            break;
          }
        }
      }
    }

    /* Check if port was found */
    if((portIdx < ETHTSYN_PORT_COUNT) && (timeDomainIdx < ETHTSYN_TIME_DOMAIN_COUNT))
    {
      /* Port found -> continue processing of the message */
      /* Get message type and process the message if applicable */
      switch(ETHTSYN_HDR_COM_MSG_TYPE(comMsgPtr->TransSpecific_MessageType))
      {
#if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
      case ETHTSYN_MSG_TYPE_PDELAY_REQ:
        EthTSyn_ProcessReceivedPdelayReqMsg(comMsgPtr, portIdx);
        break;
#endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */

#if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
      case ETHTSYN_MSG_TYPE_PDELAY_RESP:
        EthTSyn_ProcessReceivedPdelayRespMsg(comMsgPtr, portIdx);
        break;

      case ETHTSYN_MSG_TYPE_PDELAY_RES_FOLLOW_UP:
        EthTSyn_ProcessReceivedRespFollowUpMsg(comMsgPtr, portIdx);
        break;
#endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

#if (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON)
      case ETHTSYN_MSG_TYPE_SYNC:
        EthTSyn_ProcessReceivedSyncMsg(comMsgPtr, portIdx, timeDomainIdx);
        break;

      case ETHTSYN_MSG_TYPE_FOLLOW_UP:
        EthTSyn_ProcessReceivedFollowUpMsg(comMsgPtr, portIdx, timeDomainIdx);
        break;
#endif /* (ETHTSYN_TIME_SLAVE_SUPPORT == STD_ON) */

#if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
      case ETHTSYN_MSG_TYPE_ANNOUNCE:
        EthTSyn_ProcessReceivedAnnounceMsg(comMsgPtr, LenByte, portIdx, timeDomainIdx);
        break;
#endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

      default:
        /* Nothing to do here (MISRA) */
        break;
      }
    }
#endif /* ETHTSYN_SWT_MGMT_SUPPORT */
  }

#if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_RX_INDICATION, errorId);
  }
#else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#endif

} /* EthTSyn_RxIndication() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: STCAL */
/* PRQA L: STPAR */
/* PRQA L: STMIF */

#if (ETHTSYN_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  EthTSyn_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief         Return the BCD-coded version information of the EthTSyn module.
 *  \param[in]     VersionInfoPtr   Pointer to a memory location where the EthTSyn version information shall be stored.
 *  \return        none
 *  \context       This function can be called in any context.
 *  \availability  This function is only available if EthTSynVersionInfoApi is enabled.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_GetVersionInfo(ETHTSYN_P2VAR(Std_VersionInfoType) VersionInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(VersionInfoPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation --------------------------------------------- */
    VersionInfoPtr->vendorID = (uint16)ETHTSYN_VENDOR_ID;
    VersionInfoPtr->moduleID = (uint16)ETHTSYN_MODULE_ID;
    VersionInfoPtr->sw_major_version = (uint8)ETHTSYN_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = (uint8)ETHTSYN_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = (uint8)ETHTSYN_SW_PATCH_VERSION;
  }

# if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_GET_VERSION_INFO, errorId);
  }
# else
  ETHTSYN_DUMMY_STATEMENT(errorId);
# endif
}/* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif  /* (ETHTSYN_VERSION_INFO_API == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_MainFunction
 *********************************************************************************************************************/
/*! \brief    Processing of cyclic tasks of the EthTSyn module
 *  \param    none
 *  \return   none
 *  \pre      The function EthTSyn_Init() must be called first
 *  \context  This function can be called in task context.
 *********************************************************************************************************************/
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
FUNC(void, ETHTSYN_CODE) EthTSyn_MainFunction(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_TimeDomainIdxType timeDomainIdx = ETHTSYN_TIME_DOMAIN_COUNT;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(EthTSyn_State != ETHTSYN_STATE_INIT)
  {
    errorId = ETHTSYN_E_NOT_INITIALIZED;
  }
  else
#endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* Iterate all TimeDomains */
    while( 0u < timeDomainIdx )
    {
      timeDomainIdx--;

      /* Iterate all MasterPorts (if present) of the current TimeDomain */
      if(EthTSyn_TimeDomainConfig[timeDomainIdx].MasterPortIdxPtr != NULL_PTR)
      {
        /* PRQA S 0781 1 */ /* MD_EthTSyn_5.6 */
        EthTSyn_PortIdxType masterPortCnt = EthTSyn_TimeDomainConfig[timeDomainIdx].MasterPortCnt;
        EthTSyn_PortIdxType masterPortIdx;

        while(masterPortCnt > 0)
        {
          masterPortCnt--;
          masterPortIdx = EthTSyn_CfgGetMasterPortIdx(timeDomainIdx, masterPortCnt);

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
          if(ETHTSYN_STATE_GET_SLAVE_PORT_IDX(timeDomainIdx) == ETHTSYN_INVALID_PORT_IDX)
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
          {
            if(EthTSyn_IsTxReady(masterPortIdx) == TRUE)
            {
              ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
              if(ETHTSYN_SYNC_SEND_SM_PTR(masterPortIdx)->TxIntervalCnt > 0) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
              {
                ETHTSYN_SYNC_SEND_SM_PTR(masterPortIdx)->TxIntervalCnt--; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
              }
              ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
              /* SyncSend state-machine */
              EthTSyn_ProcessSmSyncSend(masterPortIdx);
            }
          }

        } /* END: Iteration of MasterPorts */
      } /* END: If MasterPorts are present */

      /* Process the SlavePorts (if present) */
      if(EthTSyn_CfgGetSlavePortCnt(timeDomainIdx) > 0) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
      {
        /* PRQA S 0781 1 */ /* MD_EthTSyn_5.6 */
        EthTSyn_PortIdxType slavePortCnt = EthTSyn_CfgGetSlavePortCnt(timeDomainIdx);
        EthTSyn_PortIdxType slavePortIdx;

        while(slavePortCnt > 0)
        {
          ETHTSYN_P2VAR(EthTSyn_SyncReceiveSmType) syncReceiveSmPtr;

          slavePortCnt--;
          slavePortIdx = EthTSyn_CfgGetSlavePortIdx(timeDomainIdx, slavePortCnt);
          syncReceiveSmPtr = ETHTSYN_SYNC_RECEIVE_SM_PTR(slavePortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

          ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

#if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
          /* AnnounceReceive state-machine */
          /* Timeout Handling */
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
          if((EthTSyn_GetPortType(slavePortIdx) & ETHTSYN_PORT_TYPE_SWITCH_PORT) != 0)
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
          {
            if(ETHTSYN_ANNOUNCE_RECEIVE_SM_PTR(slavePortIdx)->RxTimeoutCnt > 0) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
            {
              ETHTSYN_ANNOUNCE_RECEIVE_SM_PTR(slavePortIdx)->RxTimeoutCnt--; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
            }
            EthTSyn_ProcessSmAnnounceReceive(slavePortIdx);
          }
#endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

          if(syncReceiveSmPtr->FollowUp.FollowUpRxTimeoutCnt > 0)
          {
            syncReceiveSmPtr->FollowUp.FollowUpRxTimeoutCnt--;
          }

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
# if (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON)
          if(syncReceiveSmPtr->Sync.SyncRxTimeoutCnt > 0)
          {
            syncReceiveSmPtr->Sync.SyncRxTimeoutCnt--;
          }
# endif /* (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON) */
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

          ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

          /* SyncReceive state-machine */
          EthTSyn_ProcessSmSyncReceive(slavePortIdx);
        } /* END: Iteration Slave Ports */
      }/* END: If SlavePort is present */

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
      if(EthTSyn_CfgGetSlavePortCnt(timeDomainIdx) > 0)
      {
        /* SiteSyncSync state machine */
        EthTSyn_SwtMgmt_ProcessSmSiteSyncSync(timeDomainIdx);
      }
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

    } /* END: Iteration of TimeDomains */

#if (ETHTSYN_P_DELAY_CONFIG_COUNT > 0u)
    /* Process Pdelay if required */
    {
      EthTSyn_PdelayIdxType pdelayIdx;
      for(pdelayIdx = 0; pdelayIdx < ETHTSYN_P_DELAY_CONFIG_COUNT; pdelayIdx++)
      {
# if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
        if(EthTSyn_PdelayConfig[pdelayIdx].PdelayInitiatorCfgPtr != NULL_PTR)
        {
          ETHTSYN_P2VAR(EthTSyn_PdelayReqSmType) pdelayReqSmPtr =
            EthTSyn_PdelayConfig[pdelayIdx].PdelayInitiatorCfgPtr->PdelayReqSmPtr;
          if(EthTSyn_IsTxReady(EthTSyn_PdelayConfig[pdelayIdx].ActivePortIdx) == TRUE)
          {
            ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            if(pdelayReqSmPtr->PdelayReq.TxIntervalCnt > 0u)
            {
              pdelayReqSmPtr->PdelayReq.TxIntervalCnt--;
            }
            if(pdelayReqSmPtr->PdelayRespRespFollowUpTimeout > 0u)
            {
              pdelayReqSmPtr->PdelayRespRespFollowUpTimeout--;
            }
            ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          }
          /* Process Pdelay request state machine */
          EthTSyn_ProcessSmPdelayReq(EthTSyn_PdelayConfig[pdelayIdx].ActivePortIdx);
        }
# endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

# if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
        if(EthTSyn_PdelayConfig[pdelayIdx].PdelayResponderCfgPtr != NULL_PTR)
        {
          /* Process Pdelay response state machine */
          EthTSyn_ProcessSmPdelayResp(EthTSyn_PdelayConfig[pdelayIdx].ActivePortIdx);
        }
# endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */
      } /* END: Iteration Pdelay Config */
    }
#endif /* (ETHTSYN_P_DELAY_CONFIG_COUNT > 0u) */

  }

#if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_MAIN_FUNCTION, errorId);
  }
#else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */

} /* EthTSyn_MainFunction() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: STCAL */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_InitMemory
 *********************************************************************************************************************/
/*! \brief    Memory initialization of the EthTSyn module
 *  \param    none
 *  \return   none
 *  \note     This function must be called before using the module
 *  \context  This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE)  EthTSyn_InitMemory(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_CtrlIdxType ethTSynCtrlIdx;

  /* ----- Implementation ----------------------------------------------- */
  EthTSyn_State = ETHTSYN_STATE_UNINIT;

  for(ethTSynCtrlIdx = 0; ethTSynCtrlIdx < ETHTSYN_CTRL_COUNT; ethTSynCtrlIdx++)
  {
    EthTSyn_CtrlState[ethTSynCtrlIdx].TrcvLinkState = ETHTRCV_LINK_STATE_DOWN;
  }
}

/**********************************************************************************************************************
 *  EthTSyn_Init
 *********************************************************************************************************************/
/*! \brief        Initialization of the EthTSyn module
 *  \param[in]    CfgPtr   Pointer to post-build configuration or null pointer
 *  \return       none
 *  \note         This function must be called before using the module
 *  \pre          The function EthTSyn_InitMemory() must be called first
 *  \context      This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_Init(ETHTSYN_P2CONSTCFGROOT(EthTSyn_ConfigType) CfgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_TimeDomainIdxType timeDomainIdx;
  EthTSyn_CtrlIdxType ethTSynCtrlIdx;
  EthTSyn_PdelayIdxType pDelayIdx;

  /* ----- Implementation ----------------------------------------------- */
  /*lint -e438 */
  ETHTSYN_DUMMY_STATEMENT(CfgPtr); /* PRQA S 3453, 3112, 3199 */ /* MD_MSR_19.7 */ /* MD_MSR_14.2 */

  /* init all TimeDomains */
  for(timeDomainIdx = 0; timeDomainIdx < ETHTSYN_TIME_DOMAIN_COUNT; timeDomainIdx++)
  {
    EthTSyn_InitTimeDomain(timeDomainIdx);
  }
  /* Init EthTSyn Ctrl */
  for(ethTSynCtrlIdx = 0u; ethTSynCtrlIdx < ETHTSYN_CTRL_COUNT; ethTSynCtrlIdx++)
  {
    EthTSyn_InitCtrl(ethTSynCtrlIdx);
  }
  /* Init Pdelay */
  for(pDelayIdx = 0; pDelayIdx < ETHTSYN_P_DELAY_CONFIG_COUNT; pDelayIdx++)
  {
    EthTSyn_InitPdelay(pDelayIdx);
  }

  /* set default values as zero */
  /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
  IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))EthTSyn_SystemState, 0, sizeof(EthTSyn_SystemState));

#if(ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
  EthTSyn_SwtMgmt_Init();
#endif

  EthTSyn_State = ETHTSYN_STATE_INIT;

} /* End of EthTSyn_Init() */ /*lint +e438 */

/**********************************************************************************************************************
 *  EthTSyn_TrcvLinkStateChg
 *********************************************************************************************************************/
/*! \brief        Callback function that notifies a changed state of the transceiver link
 *  \description  Allows resetting state machine in case of unexpected Link loss to avoid inconsistent
                  Sync and Follow_Up sequences
 *  \param[in]    CtrlIdx         Index of the Ethernet controller
 *  \param[in]    TrcvLinkState   New link state of the transceiver\n
 *                                ETHTRCV_LINK_STATE_DOWN\n
 *                                ETHTRCV_LINK_STATE_ACTIVE
 *  \return       none
 *  \pre          The function EthTSyn_Init() must be called first
 *  \context      This function can be in any context.
 *********************************************************************************************************************/
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 2006 RET_PATH */ /* MD_MSR_14.7 */
FUNC(void, ETHTSYN_CODE) EthTSyn_TrcvLinkStateChg(
  uint8 CtrlIdx, EthTrcv_LinkStateType TrcvLinkState)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_CtrlIdxType ethTSynCtrlIdx = ETHTSYN_CTRL_COUNT;
  EthTSyn_CtrlIdxType ethTSynCtrlIter;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(EthTSyn_State != ETHTSYN_STATE_INIT)
  {
    errorId = ETHTSYN_E_NOT_INITIALIZED;
  }
  else
#endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation --------------------------------------------- */
    /* Get EthTSyn Controller */
    for(ethTSynCtrlIter = 0; ethTSynCtrlIter < ETHTSYN_CTRL_COUNT; ethTSynCtrlIter++)
    {
      if(EthTSyn_CtrlConfig[ethTSynCtrlIter].EthIfCtrlIdx == CtrlIdx)
      {
        /* EthTSyn Controller found */
        ethTSynCtrlIdx = ethTSynCtrlIter;
        break;
      }
    }

    if(ethTSynCtrlIdx < ETHTSYN_CTRL_COUNT)
    {
      switch(TrcvLinkState)
      {
      case ETHTRCV_LINK_STATE_DOWN:
        if(EthTSyn_CtrlState[ethTSynCtrlIdx].TrcvLinkState == ETHTRCV_LINK_STATE_ACTIVE)
        {
          /* Trcv Link state changed */
          EthTSyn_CtrlState[ethTSynCtrlIdx].TrcvLinkState = ETHTRCV_LINK_STATE_DOWN;

          /* remove multi-cast frame reception */
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          (void)EthIf_UpdatePhysAddrFilter(CtrlIdx, EthTSyn_DestinationMac, ETH_REMOVE_FROM_FILTER);
          /* set default values as zero */
          /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
          IpBase_Fill((ETHTSYN_P2VAR(IpBase_CopyDataType))EthTSyn_SystemState, 0, sizeof(EthTSyn_SystemType));
          EthTSyn_ResetPortsAndPdelayOfCtrl(ethTSynCtrlIdx);

          CANOE_WRITE_STRING_1("[Link] Link Down EthTSynCtrlIdx: %u", ethTSynCtrlIdx);
        }
        break;

      case ETHTRCV_LINK_STATE_ACTIVE:
        if(EthTSyn_CtrlState[ethTSynCtrlIdx].TrcvLinkState == ETHTRCV_LINK_STATE_DOWN)
        {
          /* Trcv Link state changed */
          EthTSyn_CtrlState[ethTSynCtrlIdx].TrcvLinkState = ETHTRCV_LINK_STATE_ACTIVE;

          /* Init default values */
          EthTSyn_InitCtrl(ethTSynCtrlIdx);
          EthTSyn_SetLocalClockIdentity(ethTSynCtrlIdx);
          /* add multicast frame reception */
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          (void)EthIf_UpdatePhysAddrFilter(CtrlIdx, EthTSyn_DestinationMac, ETH_ADD_TO_FILTER);

          CANOE_WRITE_STRING_1("[Link] Link Up EthTSynCtrlIdx: %u", ethTSynCtrlIdx);
        }
        break;

      default:
        /* Nothing to do here (MISRA) */
        break;
      }
    }
  }

#if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_TRCV_LINK_STATE_CHG, errorId);
  }
#else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */
}
/* PRQA L: STMIF */
/* PRQA L: STCYC */
/* PRQA L: RET_PATH */

/**********************************************************************************************************************
 *  EthTSyn_TxConfirmation
 *********************************************************************************************************************/
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
FUNC(void, ETHTSYN_CODE) EthTSyn_TxConfirmation(uint8 CtrlIdx, uint8 BufIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHTSYN_E_NO_ERROR;
  EthTSyn_CtrlIdxType ethtsynCtrlIdx;
  EthTSyn_PortIdxType portIdx = ETHTSYN_INVALID_PORT_IDX;
  EthTSyn_PortIdxIterType portIter;
  uint8 msgType = ETHTSYN_MSG_TYPE_INVALID;
  boolean timestampRequired = FALSE;
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
  EthTSyn_TimeDomainIdxType timeDomainIdx;
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

  /* ----- Development Error Checks ------------------------------------- */
#if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(EthTSyn_State != ETHTSYN_STATE_INIT)
  {
    errorId = ETHTSYN_E_NOT_INITIALIZED;
  }
  else if(EthTSyn_GetEthTSynCtrlFromEthIfCtrl(CtrlIdx) >= ETHTSYN_CTRL_COUNT)
  {
    errorId = ETHTSYN_E_CTRL_IDX;
  }
  else
#endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation --------------------------------------------- */
    ethtsynCtrlIdx = EthTSyn_GetEthTSynCtrlFromEthIfCtrl(CtrlIdx);

    /* Get EthTSyn Port and Message type */
    for(portIter = 0; portIter < EthTSyn_CtrlConfig[ethtsynCtrlIdx].EthTSynPortCount; portIter++)
    {
      portIdx = EthTSyn_CtrlConfig[ethtsynCtrlIdx].EthTSynPortIdxPtr[portIter];

#if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
      if(EthTSyn_CfgAccess_IsPdelayInitiator(portIdx) == TRUE)
      {
        if(ETHTSYN_P_DELAY_REQ_SM_PTR(portIdx)->TxBufIdx == BufIdx)
        {
          /* Port and message type found */
          msgType = ETHTSYN_MSG_TYPE_PDELAY_REQ;
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_OFF)
          /* Egress Timestamp for Pdelay Request is only required when Switch-Timestamping is disabled */
          timestampRequired = TRUE;
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_OFF) */
        }
      }
#endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

#if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
      if(EthTSyn_CfgAccess_IsPdelayResponder(portIdx) == TRUE)
      {
        if(ETHTSYN_P_DELAY_RESP_SM_PTR(portIdx)->TxBufIdx == BufIdx)
        {
          msgType = ETHTSYN_MSG_TYPE_PDELAY_RESP;
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_OFF)
          /* Egress Timestamp for Pdelay Response is only required when Switch-Timestamping is disabled */
          timestampRequired = TRUE;
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_OFF) */
        }
      }
#endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */

      if(EthTSyn_CfgGetPortRole(portIdx) == ETHTSYN_PORT_ROLE_MASTER)
      {
        if(ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->SyncTxBufIdx == BufIdx) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        {
          msgType = ETHTSYN_MSG_TYPE_SYNC;
          /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
          if( (ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->FollowUpPreciseOriginTimestampState &
            ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP) != 0)
          {
            timestampRequired = TRUE;
          }
        }
        if(ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->FollowUpTxBufIdx == BufIdx) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        {
          msgType = ETHTSYN_MSG_TYPE_FOLLOW_UP;
        }
      }

      if(msgType != ETHTSYN_MSG_TYPE_INVALID)
      {
        break;
      }
    } /* END: Iteration of Ports for the given Controller */

    if((portIdx < ETHTSYN_PORT_COUNT) && (msgType != ETHTSYN_MSG_TYPE_INVALID))
    {
      /* Port and message type found --> continue */
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
      /* Get TimeDomain index */
      timeDomainIdx = EthTSyn_CfgAccess_GetTimeDomainIdx(EthTSyn_PortConfig[portIdx].TimeDomainId);
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */

      /* Handle Timestamp(s) if required */
      if(timestampRequired == TRUE)
      {
        EthTSyn_HandleEgressTimestamping(portIdx, msgType, BufIdx);
      }

      /* Process TxConfirmation */
      switch(msgType)
      {
#if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
      case ETHTSYN_MSG_TYPE_PDELAY_REQ:
        ETHTSYN_P_DELAY_REQ_SM_PTR(portIdx)->TxBufIdx = ETHTSYN_INV_BUF_IDX;
        ETHTSYN_P_DELAY_REQ_SM_PTR(portIdx)->TxConfirmationPending--;
        break;
#endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

#if (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON)
      case ETHTSYN_MSG_TYPE_PDELAY_RESP:
        ETHTSYN_P_DELAY_RESP_SM_PTR(portIdx)->TxBufIdx = ETHTSYN_INV_BUF_IDX;
        ETHTSYN_P_DELAY_RESP_SM_PTR(portIdx)->TxConfirmationPending--;
        break;
#endif /* (ETHTSYN_P_DELAY_RESP_STATE_MACHINE_SUPPORT == STD_ON) */

      case ETHTSYN_MSG_TYPE_SYNC:
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
        if(ETHTSYN_STATE_GET_SLAVE_PORT_IDX(timeDomainIdx) == ETHTSYN_INVALID_PORT_IDX)
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
        {
          ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->TxConfirmationPending--; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

          /* Handle Sync Sent Callback */
#if (ETHTSYN_SYNC_SENT_CBK == STD_ON)
          if(EthTSyn_MasterPortConfigPtr(portIdx)->SyncSentCbkPtr != NULL_PTR) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
          {
            /* Sync sent cbk configured -> call */
            /* PRQA S 0310 4 */ /* MD_EthTSyn_11.4 */
            ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) comMsgPtr =
              (ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->SyncTxBufPtr;
            ETHTSYN_P2CONST(EthTSyn_SyncMsgType) syncPtr =
              (ETHTSYN_P2CONST(EthTSyn_SyncMsgType))&comMsgPtr[ETHTSYN_HDR_COM_LENGTH];

            /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
            EthTSyn_MasterPortConfigPtr(portIdx)->SyncSentCbkPtr(portIdx, comMsgPtr, syncPtr);

# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF)
            ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->SyncTxBufPtr = NULL_PTR; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_OFF) */
          }
#endif /* (ETHTSYN_SYNC_SENT_CBK == STD_ON) */
        }
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
        else
        {
          /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
          ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->State = ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_WAIT_FOLLOW_UP;
          if(EthTSyn_SiteSyncSyncSm(timeDomainIdx).TxConfirmationPending > 0)
          {
            EthTSyn_SiteSyncSyncSm(timeDomainIdx).TxConfirmationPending--;
            if(EthTSyn_SiteSyncSyncSm(timeDomainIdx).TxConfirmationPending == 0)
            {
              EthTSyn_SiteSyncSyncSm(timeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_PENDING;
            }
          }
          else
          {
            /* This should never happen */
            /* TxConfirmationPending is 0. This means the TxConfirmation has been called more often than expected */
            errorId = ETHTSYN_E_INTERNAL_ERROR;
          }
        }
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
        ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->SyncTxBufIdx = ETHTSYN_INV_BUF_IDX; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        break;

      case ETHTSYN_MSG_TYPE_FOLLOW_UP:
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
        if(ETHTSYN_STATE_GET_SLAVE_PORT_IDX(timeDomainIdx) == ETHTSYN_INVALID_PORT_IDX)
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
        {
          /* Handle FollowUp sent callback */
#if (ETHTSYN_FUP_SENT_CBK == STD_ON)
          /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
          if(EthTSyn_MasterPortConfigPtr(portIdx)->FollowUpSentCbkPtr != NULL_PTR)
          {
            /* FollowUp sent cbk configured -> call */
            /* PRQA S 0310 4 */ /* MD_EthTSyn_11.4 */
            ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) comMsgPtr =
              (ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->FollowUpTxBufPtr;
            ETHTSYN_P2CONST(EthTSyn_FollowUpMsgType) followUpPtr =
              (ETHTSYN_P2CONST(EthTSyn_FollowUpMsgType))&comMsgPtr[ETHTSYN_HDR_COM_LENGTH];
            /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
            EthTSyn_MasterPortConfigPtr(portIdx)->FollowUpSentCbkPtr(portIdx, comMsgPtr, followUpPtr);

            ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->FollowUpTxBufPtr = NULL_PTR; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
          }
#endif /* (ETHTSYN_FUP_SENT_CBK == STD_ON) */
        }
#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
        else
        {
          /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
          ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->State = ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_PENDING;
          if(EthTSyn_SiteSyncSyncSm(timeDomainIdx).TxConfirmationPending > 0)
          {
            EthTSyn_SiteSyncSyncSm(timeDomainIdx).TxConfirmationPending--;
            if(EthTSyn_SiteSyncSyncSm(timeDomainIdx).TxConfirmationPending == 0)
            {
              EthTSyn_SiteSyncSyncSm(timeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_PENDING;
            }
          }
          else
          {
            /* This should never happen */
            /* TxConfirmationPending is 0. This means the TxConfirmation has been called more often than expected */
            errorId = ETHTSYN_E_INTERNAL_ERROR;
          }
        }
#endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
        /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
        ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->FollowUpTxBufIdx = ETHTSYN_INV_BUF_IDX;
        break;

      default: /* PRQA S 2018 */ /* MD_MSR_14.1 */
        /* Nothing to do here (MISRA) */
        break;
      }
    }
  }

#if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_TX_CONFIRMATION, errorId);
  }
#else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */

} /* EthTSyn_TxConfirmation() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_TimestampPlusTimediff
 *********************************************************************************************************************/
/*! \brief         Calculates the sum of a timestamps and a time difference
 *  \param[inout]  DestTimestampPtr    Pointer to timestamp where the first summand is stored and the
 *                                     sum is written
 *  \param[in]     TimediffPtr         Pointer the value where the time difference is stored
 *  \return        E_OK                Sum of added timestamps is valid
 *                 E_NOT_OK            Sum of added timestamps is invalid
 *  \context       This function can be called in any context.
 *********************************************************************************************************************/
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TimestampPlusTimediff(
  ETHTSYN_P2VAR(EthTSyn_GlobalTimestampType) DestTimestampPtr,
  ETHTSYN_P2CONST(EthTSyn_TimediffType) TimediffPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  EthTSyn_InternalTimestampType internalTimestamp;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if((DestTimestampPtr == NULL_PTR) || (TimediffPtr == NULL_PTR))
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
    retVal = E_NOT_OK;
  }
  else
#endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* Convert Global to internal Timestamp */
    internalTimestamp.nanoseconds = DestTimestampPtr->nanoseconds;
    internalTimestamp.seconds     = DestTimestampPtr->seconds;
    internalTimestamp.seconds    |= ((uint64)DestTimestampPtr->secondsHi << 32U);

    /* check for positive value of time difference */
    if(*TimediffPtr > 0U)
    {
      EthTSyn_UTimediffType TimediffU64Ns = (EthTSyn_UTimediffType)(*TimediffPtr);
      EthTSyn_UTimediffType DiffSeconds = (EthTSyn_UTimediffType)(TimediffU64Ns / ETHTSYN_TIMESTAMP_MAX_NANOSECONDS);
      uint32 DiffNanoseconds = (uint32)(TimediffU64Ns % ETHTSYN_TIMESTAMP_MAX_NANOSECONDS);

      /* overflow check of rounded up seconds -> we don't have to check nanoseconds overflow */
      if((EthTSyn_UTimediffType)((internalTimestamp.seconds + 1) + DiffSeconds) <= 
        (EthTSyn_UTimediffType)ETHTSYN_TIMESTAMP_MAX_SECONDS)
      {
        /* add nanoseconds of both summands */
        internalTimestamp.nanoseconds += (uint32)DiffNanoseconds;

        /* add seconds of overflow nanoseconds */
        internalTimestamp.seconds += (uint64)((uint64)internalTimestamp.nanoseconds / 
          (uint64)ETHTSYN_TIMESTAMP_MAX_NANOSECONDS);

        /* truncate overflow nanoseconds */
        internalTimestamp.nanoseconds = internalTimestamp.nanoseconds % ETHTSYN_TIMESTAMP_MAX_NANOSECONDS;

        /* add seconds */
        internalTimestamp.seconds += (EthTSyn_UTimediffType)DiffSeconds;
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
    /* check for negative value of time difference */
    else if(*TimediffPtr < 0U)
    {
      EthTSyn_UTimediffType TimediffU64Ns = (EthTSyn_UTimediffType)(-(*TimediffPtr));
      EthTSyn_UTimediffType DiffSeconds = (EthTSyn_UTimediffType)(TimediffU64Ns / ETHTSYN_TIMESTAMP_MAX_NANOSECONDS);
      uint32 DiffNanoseconds = (uint32)(TimediffU64Ns % ETHTSYN_TIMESTAMP_MAX_NANOSECONDS);

      /* check that result is not negative */
      if(DiffSeconds <= internalTimestamp.seconds)
      {
        if(DiffNanoseconds <= internalTimestamp.nanoseconds)
        {
          internalTimestamp.seconds -= DiffSeconds;
          internalTimestamp.nanoseconds -= DiffNanoseconds;
        }
        /* handle nanoseconds underflow */
        else
        {
          /* destination seconds must greater than diff seconds due to underflow */
          if(internalTimestamp.seconds > DiffSeconds)
          {
            /* decrement seconds due to underflow of nanoseconds */
            internalTimestamp.seconds--;
            internalTimestamp.nanoseconds = 
              (uint32)(((ETHTSYN_TIMESTAMP_MAX_NANOSECONDS + internalTimestamp.nanoseconds) - DiffNanoseconds));
            /* subtract seconds */
            internalTimestamp.seconds -= DiffSeconds;
          }
          /* negative timestamp value */
          else
          {
            retVal = E_NOT_OK;
          }
        }
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
    /* check for negative value of time difference */
    else
    {
      /* timediff is zero -> add nothing */
    }

    /* Convert Internal to global Timestamp */
    /* The seconds field of the internal timestamp has a value range from 0 - (2^48-1) */
    if(retVal == E_OK)
    {
      DestTimestampPtr->nanoseconds = internalTimestamp.nanoseconds;
      DestTimestampPtr->seconds     = (uint32)internalTimestamp.seconds;
      DestTimestampPtr->secondsHi   = (uint16)(internalTimestamp.seconds >> 32U);
    }
  }

#if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_TIMESTAMP_PLUS_TIMEDIFF, errorId);
  }
#else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
}/* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_TimestampMinusTimestamp
 *********************************************************************************************************************/
/*! \brief       Calculates the time difference between Timestamp1 and Timestamp2 (diff = Timestamp1 - Timestamp2)
 *  \param[in]   Timestamp1Ptr    Pointer to timestamp of the first timestamp
 *  \param[in]   Timestamp2Ptr    Pointer to timestamp of the second timestamp
 *  \param[out]  TimediffPtr      Pointer to time difference between Timestamp1 and Timestamp2 in Nanoseconds
 *  \return      E_OK             Timediff is valid
 *               E_NOT_OK         Timediff is greater than ETHTSYN_TIMEDIFF_MAX_SECONDS: 9.223.372.036s
 *  \context     This function can be called in any context.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_TimestampMinusTimestamp(
  ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType) Timestamp1Ptr,
  ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType) Timestamp2Ptr,
  ETHTSYN_P2VAR(EthTSyn_TimediffType) TimediffPtr)
 {
   /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  EthTSyn_TimediffType diffSeconds;
  EthTSyn_TimediffType diffNanoseconds;
  EthTSyn_UTimediffType diffSecondsU64;
  EthTSyn_InternalTimestampType internalTimestamp1;
  EthTSyn_InternalTimestampType internalTimestamp2;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if((Timestamp1Ptr == NULL_PTR) || (Timestamp2Ptr == NULL_PTR) || (TimediffPtr == NULL_PTR))
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else
#endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */

    /* Convert Global to internal Timestamp */
    internalTimestamp1.nanoseconds = Timestamp1Ptr->nanoseconds;
    internalTimestamp1.seconds     = Timestamp1Ptr->seconds;
    internalTimestamp1.seconds    |= ((uint64)Timestamp1Ptr->secondsHi << 32U);

    internalTimestamp2.nanoseconds = Timestamp2Ptr->nanoseconds;
    internalTimestamp2.seconds     = Timestamp2Ptr->seconds;
    internalTimestamp2.seconds    |= ((uint64)Timestamp2Ptr->secondsHi << 32U);

    /* check if difference in seconds is suitable for nanoseconds difference value.
    No overflow is expected due Seconds field of EthTSyn_TimestampType should not exceed 2^48 */
    diffSeconds = (EthTSyn_TimediffType)(internalTimestamp1.seconds - internalTimestamp2.seconds);

    /* check if time difference is less zero */
    if(diffSeconds < 0)
    {
      diffSecondsU64 = (EthTSyn_UTimediffType)(-diffSeconds);
    }
    /* time difference is greater zero */
    else
    {
      diffSecondsU64 = (EthTSyn_UTimediffType)diffSeconds;
    }

    /* round up difference in seconds due to handle possible nanoseconds overflow in further calculation */
    diffSecondsU64++;
    /* check if time difference in seconds is suitable for nanoseconds difference value */
    if((EthTSyn_UTimediffType)diffSecondsU64 < (EthTSyn_UTimediffType)ETHTSYN_TIMEDIFF_MAX_SECONDS)
    {
      /* calculate correct nanoseconds time difference */
      diffNanoseconds = (EthTSyn_TimediffType)
        ((EthTSyn_TimediffType)internalTimestamp1.nanoseconds - (EthTSyn_TimediffType)internalTimestamp2.nanoseconds);

      /* set seconds value */
      *TimediffPtr = diffSeconds * ETHTSYN_TIMESTAMP_MAX_NANOSECONDS;

      /* add nanoseconds value */
      *TimediffPtr = *TimediffPtr + diffNanoseconds;

      retVal = E_OK;
    }
    /* timediff value exceeds max nanoseconds value */
    else
    {
      *TimediffPtr = 0;
    }
  }

#if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_TIMESTAMP_MINUS_TIMESTAMP, errorId);
  }
#else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  EthTSyn_SetTransmissionMode
 *********************************************************************************************************************/
/*! \brief      This API is used to turn on and off the TX capabilities of the EthTSyn. 
 *  \param[in]  CtrlIdx     Index of the Ethernet controller 
 *  \param[in]  Mode        ETHTSYN_TX_OFF 
 *                          ETHTSYN_TX_ON 
 *  \return     none
 *  \pre        The function EthTSyn_Init() must be called first
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_SetTransmissionMode(uint8 CtrlIdx, EthTSyn_TransmissionModeType Mode)
{
  /* ------ Local Variables -----------------------------------------------*/
  EthTSyn_CtrlIdxType ethtsynCtrlIdx;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(EthTSyn_State != ETHTSYN_STATE_INIT)
  {
    errorId = ETHTSYN_E_NOT_INITIALIZED;
  }
  else if((Mode != ETHTSYN_TX_ON) && (Mode != ETHTSYN_TX_OFF))
  {
    errorId = ETHTSYN_E_PARAM;
  }
  else if(EthTSyn_GetEthTSynCtrlFromEthIfCtrl(CtrlIdx) >= ETHTSYN_CTRL_COUNT)
  {
    errorId = ETHTSYN_E_CTRL_IDX;
  }
  else
#endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation --------------------------------------------- */
    ethtsynCtrlIdx = EthTSyn_GetEthTSynCtrlFromEthIfCtrl(CtrlIdx);

    if(ethtsynCtrlIdx < ETHTSYN_CTRL_COUNT)
    {
      EthTSyn_CtrlState[ethtsynCtrlIdx].TransmissionMode = Mode;
    }
  }

#if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_SET_TRANSMISSION_MODE, errorId);
  }
#else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#endif

} /* EthTSyn_SetTransmissionMode() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

#define ETHTSYN_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* module specific MISRA deviations:
  MD_EthTSyn_11.4:
      Reason:     Casting to different object pointer type
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_EthTSyn_11.5
      Reason:     Called API expects a P2VAR.
      Risk:       No risk. The object addressed by the pointer parameter is not modified within the called API.
      Prevention: Covered by code review.
  MD_EthTSyn_16.7a:
      Reason:     The parameter is not modified and so the pointer could be of type 'pointer to const'
      Risk:       No risk. The object addressed by the pointer parameter is of type 'pointer to const'
      Prevention: Covered by code review.
  MD_EthTSyn_16.7b:
      Reason:     The parameter is not modified and so the pointer could be of type 'pointer to const'
      Risk:       No risk. The modification of the parameter depends on preprocessor define
      Prevention: Covered by code review
  MD_EthTSyn_16.7c:
      Reason:     The parameter is of type P2VAR due to AUTOSAR specification
      Risk:       No risk.
      Prevention: Covered by code review
  MD_EthTSyn_5.6
      Reason:     Reuse of variable name improves readability
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_EthTSyn_12.4
      Reason:     The right hand operand of the && operator is only evaluated if the left hand operand is "true"
      Risk:       No risk. No assignments are done in conditional statements
      Prevention: Covered by code review.
  MD_EthTSyn_14.6
      Reason:     Performance enhancement
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_EthTSyn_685
      Reason:     AUTOSAR Macro is used to determine the NsPerTick value for the used OsCounter.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_EthTSyn_19.15
      Reason:     Wrong MISRA Warning. Standard Include Guard is present.
      Risk:       No risk.
      Prevention: Covered by code review.
  MD_EthTSyn_3451:
      Reason:     The declarations are generated and are always the same.
      Risk:       No functional risk.
      Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn.c
 *********************************************************************************************************************/
