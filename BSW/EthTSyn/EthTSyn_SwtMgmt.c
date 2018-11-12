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
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EthTSyn_SwtMgmt.c
 *        \brief  EthTSyn Switch Management source file
 *
 *      \details  EthTSyn Switch Management source file containing the EthTSyn Switch Management implementation of the
 *                EthTSyn module.
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

#define ETHTSYN_SWTMGMT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EthTSyn_SwtMgmt_Priv.h"
#include "EthTSyn_SwtMgmt_Cbk.h"

#if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
# include "EthTSyn_Priv.h" /* PRQA S 0883 */ /* MD_EthTSyn_19.15 */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of EthTSyn header file */
# if (  (ETHTSYN_SW_MAJOR_VERSION != (4u)) \
     || (ETHTSYN_SW_MINOR_VERSION != (0u)) \
     || (ETHTSYN_SW_PATCH_VERSION != (2u)) )
#  error "Vendor specific version numbers of EthTSyn_SwtMgmt.c and EthTSyn.h are inconsistent"
# endif

/* Check the version of the configuration header file */
# if (  (ETHTSYN_CFG_MAJOR_VERSION != (4u)) \
     || (ETHTSYN_CFG_MINOR_VERSION != (0u)) )
#  error "Version numbers of EthTSyn_SwtMgmt.c and EthTSyn_Cfg.h are inconsistent!"
# endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
# if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
/* PRQA S 3453 3 */ /* MD_MSR_19.7 */
#  define ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MSG_BUFFER(MsgBufferPtr)  ((MsgBufferPtr)->SwtMgmtInfo.FrameId)
#  define ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MGMT_INFO(MgmtInfoPtr)    ((MgmtInfoPtr)->FrameId)
# else
#  define ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MSG_BUFFER(MsgBufferPtr)  ETHTSYN_INVALID_FRAME_ID
#  define ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MGMT_INFO(MgmtInfoPtr)    ETHTSYN_INVALID_FRAME_ID
# endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
# if ( (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) && (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) )
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#  define ETHTSYN_SWT_MGMT_FRAME_ID_FROM_SM(SmPtr)                 ((SmPtr)->FrameId)
# else
#  define ETHTSYN_SWT_MGMT_FRAME_ID_FROM_SM(SmPtr)                 ETHTSYN_INVALID_FRAME_ID
#endif /* ( (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) && (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) ) */

/* PRQA S 3453 8 */ /* MD_MSR_19.7 */
# define ETHTSYN_SWT_MGMT_COND_TIMESTAMP_STATE_TS_REQUIRED_VALID(TimestampState) \
  (((TimestampState) & ETHTSYN_TIMESTAMP_STATE_REQUIRED_FLAG_VALID_MASK) != 0)
# define ETHTSYN_SWT_MGMT_COND_TIMESTAMP_STATE_TS_REQUIRED(TimestampState) \
  (((TimestampState) & ETHTSYN_TIMESTAMP_STATE_REQUIRED_MASK) != 0)
# define ETHTSYN_SWT_MGMT_COND_TIMESTAMP_STATE_TS_AVAILABLE_VALID(TimestampState) \
  (((TimestampState) & ETHTSYN_TIMESTAMP_STATE_AVAILABLE_FLAG_VALID_MASK) != 0)
# define ETHTSYN_SWT_MGMT_COND_TIMESTAMP_STATE_TS_AVAILABLE(TimestampState) \
  (((TimestampState) & ETHTSYN_TIMESTAMP_STATE_AVAILABLE_MASK) != 0)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

# if !defined (ETHTSYN_LOCAL)
#  define ETHTSYN_LOCAL static
# endif

# if !defined (ETHTSYN_LOCAL_INLINE)
#  define ETHTSYN_LOCAL_INLINE LOCAL_INLINE
# endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define ETHTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

ETHTSYN_LOCAL VAR(EthTSyn_SwtMgmt_MsgBufferType, ETHTSYN_VAR_NOINIT) EthTSyn_SwtMgmt_MsgBuffer[
                                                                          ETHTSYN_SWT_MGMT_MSG_BUFFER_COUNT];

# define ETHTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
# define ETHTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define ETHTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define ETHTSYN_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_QualifyAnnounceMsg
 *********************************************************************************************************************/
/*! \brief      Validation of Announce message
 *  \param[in]  PortIdx         Index of EthTSyn port that received the Announce message
 *  \param[in]  MsgBufferPtr:   Pointer to the message buffer where the announce message is stored
 *  \return     E_OK            Announce message is valid\n
 *              E_NOT_OK        Announce message is not valid\n
 *  \context    This function can be called in any context. Calling function must ensure that TimeDomainId is a
 *              Slave Port
 *********************************************************************************************************************/
# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_QualifyAnnounceMsg(
                         EthTSyn_PortIdxType            PortIdx,
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr);
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessMsgBuffer
 *********************************************************************************************************************/
/*! \brief      Processing of a received message where all required information are present
 *  \param[in]  MsgBufferPtr   Pointer to the message buffer to be processed
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessMsgBuffer(
    ETHTSYN_CONSTP2VAR(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr);

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_TriggerStateMachine
 *********************************************************************************************************************/
/*! \brief      Trigger the processing of a specified state machine
 *  \param[in]  StateMachine    Identification of the state machine to be processed
 *  \param[in]  PortIdx         Index of the EthTSyn port the state machine should be processed for.
 *  \return                     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_TriggerStateMachine(
    EthTSyn_SwtMgmt_StateMachineIndentificationType StateMachine,
    EthTSyn_PortIdxType                             PortIdx);
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedPdelayReq
 *********************************************************************************************************************/
/*! \brief      Processing of a received Pdelay_Req message
 *  \param[in]  MsgBufferPtr:  Pointer to the message buffer to be processed
 *  \param[in]  PortIdx:       Index of the EthTSyn Port the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedPdelayReq(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr,
                         EthTSyn_PortIdxType            PortIdx); /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedPdelayResp
 *********************************************************************************************************************/
/*! \brief      Processing of a received Pdelay_Resp message
 *  \param[in]  MsgBufferPtr:  Pointer to the message buffer to be processed
 *  \param[in]  PortIdx:       Index of the EthTSyn Port the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedPdelayResp(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr,
                         EthTSyn_PortIdxType            PortIdx); /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedPdelayRespFollowUp
 *********************************************************************************************************************/
/*! \brief      Processing of a received Pdelay_Resp_FollowUp message
 *  \param[in]  MsgBufferPtr:  Pointer to the message buffer to be processed
 *  \param[in]  PortIdx:       Index of the EthTSyn Port the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedPdelayRespFollowUp(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr,
                         EthTSyn_PortIdxType            PortIdx); /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedSync
 **********************************************************************************************************************/
/*! \brief      Processing of a received Sync message
 *  \param[in]  MsgBufferPtr:  Pointer to the message buffer to be processed
 *  \param[in]  PortIdx:       Index of the EthTSyn Port the message was received on
 *  \param[in]  TimeDomainIdx: Index of the TimeDomain the message was received on
 *  \return     TRUE:  Message received
 *              FALSE: Message discarded
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedSync(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr,
                         EthTSyn_PortIdxType            PortIdx,
                         EthTSyn_TimeDomainIdxType      TimeDomainIdx); /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedFollowUp
 *********************************************************************************************************************/
/*! \brief      Processing of a received FollowUp message
 *  \param[in]  MsgBufferPtr:  Pointer to the message buffer to be processed
 *  \param[in]  PortIdx:       Index of the EthTSyn Port the message was received on
 *  \param[in]  TimeDomainIdx: Index of the TimeDomain the message was received on
 *  \return     TRUE:  Message received
 *              FALSE: Message discarded
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedFollowUp(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr,
                         EthTSyn_PortIdxType            PortIdx,
                         EthTSyn_TimeDomainIdxType      TimeDomainIdx); /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedAnnounce
 *********************************************************************************************************************/
/*! \brief      Processing of a received Announce message
 *  \param[in]  MsgBufferPtr:  Pointer to the message buffer to be processed
 *  \param[in]  PortIdx:       Index of the EthTSyn Port the message was received on
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedAnnounce(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr,
                         EthTSyn_PortIdxType            PortIdx); /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ReleaseMsgBuffer
 *********************************************************************************************************************/
/*! \brief      Release the specified message buffer
 *  \details    This functions releases the specified message buffer
 *  \param[in]  MsgBufferPtr:    Pointer to the message buffer element to be released
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ReleaseMsgBuffer(
    ETHTSYN_CONSTP2VAR(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr);

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProvideMsgBuffer
 *********************************************************************************************************************/
/*! \brief       Get a free message buffer, prepare and lock it
 *  \param[out]  MsgBufferPtrPtr:    Pointer to the free message buffer element
 *  \return      E_OK:     Free message buffer available
 *               E_NOT_OK: No message buffer available
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProvideMsgBuffer(
    ETHTSYN_P2VAR(EthTSyn_SwtMgmt_MsgBufferType) *MsgBufferPtrPtr);

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetMappedMsgBuffer
 *********************************************************************************************************************/
/*! \brief       Get the message buffer mapped to the given FrameId and Rx-Buffer Address
 *  \param[in]   CtrlIdx:            Index of the EthIf controller the frame was received on
 *  \param[in]   RxBufAddr:          Address of the corresponding Rx-Buffer
 *  \param[in]   FrameId:            The Frame ID of the frame the message buffer is requested for
 *  \param[out]  MsgBufferPtrPtr:    Pointer to the mapped message buffer element
 *  \return      E_OK:     Message buffer available
 *               E_NOT_OK: No message buffer mapped
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetMappedMsgBuffer(
                    uint8                           CtrlIdx,
    ETHTSYN_P2CONST(uint8)                          RxBufAddr,
                    EthTSyn_FrameIdType             FrameId,
      ETHTSYN_P2VAR(EthTSyn_SwtMgmt_MsgBufferType) *MsgBufferPtrPtr);

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetEndStationSlavePortIdx
 *********************************************************************************************************************/
/*! \brief      Get the End-Station Slave Port Index of the given TimeDomain
 *  \param[in]  TimeDomainIdx:      Index of the TimeDomain the slave port should be retrieved for
 *  \return     The corresponding slave port index. If no corresponding slave port was found, the return value will be
 *              ETHTSYN_INVALID_PORT_IDX
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(EthTSyn_PortIdxType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetEndStationSlavePortIdx(
  EthTSyn_TimeDomainIdxType TimeDomainIdx);

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetSwitchSlavePortIdx
 *********************************************************************************************************************/
/*! \brief      Get the Switch Slave Port Index of the given TimeDomain
 *  \param[in]  TimeDomainIdx:      Index of the TimeDomain the slave port should be retrieved for
 *  \return     The corresponding slave port index. If no corresponding slave port was found, the return value will be
 *              ETHTSYN_INVALID_PORT_IDX
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(EthTSyn_PortIdxType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetSwitchSlavePortIdx(
  EthTSyn_TimeDomainIdxType TimeDomainIdx);

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetIngressTimestamp
 *********************************************************************************************************************/
/*! \brief      Handles the ingress timestamping
 *  \param[in]  EthIfCtrlIdx         Ethernet interface controller index
 *  \param[in]  DataPtr              Pointer to the Rx-Buffer
 *  \param[out] IngressTimestampPtr  The Ingress timestamp
 *  \return     E_OK      Succeeded\n
 *              E_NOT_OK  Failed\n
 *  \context    This function has to be called in the context of the EthTSyn_RxIndication().
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetIngressTimestamp(
                uint8                         EthIfCtrlIdx,
  ETHTSYN_P2VAR(uint8)                        DataPtr,
  ETHTSYN_P2VAR(EthTSyn_GlobalTimestampType)  IngressTimestampPtr);

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetMappedStateMachine
 *********************************************************************************************************************/
/*! \brief       Get the message buffer mapped to the given FrameId and Rx-Buffer Address
 *  \param[in]   CtrlIdx:          Index of the corresponding EthIf controller
 *  \param[in]   TxBufPtr:        Address of the corresponding Tx-Buffer
 *  \param[in]   FrameId:          The Frame ID of the frame the state machine is requested for
 *  \param[out]  PortIdxPtr:       Pointer to the mapped message buffer element
 *  \return      The mapped state machine indication value
 *********************************************************************************************************************/
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(EthTSyn_SwtMgmt_StateMachineIndentificationType, ETHTSYN_CODE)
  EthTSyn_SwtMgmt_GetMappedStateMachine(
                           uint8                      CtrlIdx,
      ETHTSYN_CONSTP2CONST(uint8)                     TxBufPtr,
                           EthTSyn_FrameIdType        FrameId,
             ETHTSYN_P2VAR(EthTSyn_PortIdxType)       PortIdxPtr);
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetStateMachineTxTimestampInfo
 *********************************************************************************************************************/
/*! \brief       Get the message buffer mapped to the given FrameId and Rx-Buffer Address
 *  \param[in]   StateMachine:         The State machine 'type' for which the timestamp info is required
 *  \param[in]   PortIdx:              The Port index of the state machine
 *  \param[in]   TimestampDir:         Direction of the Timestamp (ingress/egress)
 *  \param[out]  TimestampPtrPtr:      Pointer to the corresponding Timestamp
 *  \param[out]  TimestampStatePtrPtr: Pointer to the corresponding Timestamp state
 *  \return      E_OK:     Successfully retrieved the Timestamp info
 *               E_NOT_OK: Failed to retrieve the Timestamp info
 *********************************************************************************************************************/
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetStateMachineTxTimestampInfo(
                  EthTSyn_SwtMgmt_StateMachineIndentificationType  StateMachine,
                  EthTSyn_PortIdxType                              PortIdx,
                  EthTSyn_SwtMgmt_TimestampDirectionType           TimestampDir,
    ETHTSYN_P2VAR(EthTSyn_GlobalTimestampType)                    *TimestampPtrPtr,
    ETHTSYN_P2VAR(EthTSyn_TimestampStateType)                     *TimestampStatePtrPtr);
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_QualifyAnnounceMsg
 *********************************************************************************************************************/
# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_QualifyAnnounceMsg(EthTSyn_PortIdxType PortIdx,
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = ETHTSYN_E_NO_ERROR;
  ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType) announceMsgPtr;
  ETHTSYN_P2CONST(EthTSyn_ClockIdentityType) pathSequenceClockIdentityPtr;
  uint16 pathSequenceTlvCnt;
  uint16 assumedLenByte;
  uint16 stepsRemovedCnt;
  uint16 lenByte = (uint16)EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.MessageLength);

  /* ----- Development Error Checks ------------------------------------- */
#  if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(PortIdx >= ETHTSYN_PORT_COUNT)
  {
    errorId = ETHTSYN_E_PARAM;
  }
  else if (EthTSyn_CfgGetPortRole(PortIdx) != ETHTSYN_PORT_ROLE_SLAVE)
  {
    errorId = ETHTSYN_E_PARAM;
  }
  else
#  endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* set message pointers */
    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    announceMsgPtr = (ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType))&MsgBufferPtr->Msg.Payload[0];

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
      /* PRQA S 3415 6 */ /* MD_EthTSyn_12.4 */
      if( (EthTSyn_CompareClockIdentity(MsgBufferPtr->Msg.MsgHdr.SourceClockIdentity,
        ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx)) != ETHTSYN_COMPARE_EQUAL) &&
        (EthTSyn_CompareClockIdentity(announceMsgPtr->ClockIdentity,
        ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx)) != ETHTSYN_COMPARE_EQUAL) &&
        (assumedLenByte == lenByte) &&
        /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
        (stepsRemovedCnt <= EthTSyn_SlavePortConfigPtr(PortIdx)->MaxStepsRemoved))
      {
        uint16_least i;
        retVal = E_OK;

        /* set message pointer to the clock identity of the path sequence */
        /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
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

#  if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_QUALIFY_ANNOUNCE_MSG, errorId);
  }
#  else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#  endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
} /* EthTSyn_SwtMgmt_QualifyAnnounceMsg() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* PRQA L: STMIF */
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessMsgBuffer
 *********************************************************************************************************************/
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessMsgBuffer(
    ETHTSYN_CONSTP2VAR(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr)
{
  /*
  * TimeDomainId is known from message
  * TimeDomainIdx can be retrieved using the TimeDomainId
  * The EthTSyn-Port can be found by iterating all Ports of the TimeDomain(Idx)
  * The EthTSyn-Port has to match the CtrlIdx and the SwtPortIdx
  * Within a TimeDomain only one Port for the pair of EthIf-Ctrl and Swt-Port can exist
  */

  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHTSYN_E_NO_ERROR;
  EthTSyn_PortIdxType portIdx = ETHTSYN_INVALID_PORT_IDX; /* PRQA S 0781 */ /* MD_EthTSyn_5.6 */
  EthTSyn_TimeDomainIdxType timeDomainIdx;
# if (ETHTSYN_END_STATION_SUPPORT == STD_ON)
  EthTSyn_SwtMgmt_RxFrameInfoType rxFrameInfo;
# endif /* (ETHTSYN_END_STATION_SUPPORT == STD_ON) */

  /* ----- Implementation --------------------------------------------- */
  /* Check if timestamp indications were already called */
  /* PRQA S 3415 3 */ /* MD_EthTSyn_12.4 */
  if( (EthTSyn_IsTimestampReadyToProcess(MsgBufferPtr->IngressTimestampMgmt.TimestampState) == TRUE)
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
    && (EthTSyn_IsTimestampReadyToProcess(MsgBufferPtr->EgressTimestampHostPortMgmt.TimestampState) == TRUE)
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
    )
  {
    if(MsgBufferPtr->MsgBufferState == ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_PORT_INFO_AVAILABLE)
    {
      /* Ready to process message */
      MsgBufferPtr->MsgBufferState = ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_MSG_PROCESSING;
    }
  }

  /* Check if message is ready for processing */
  if(MsgBufferPtr->MsgBufferState == ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_MSG_PROCESSING)
  {
    /* Message is ready for processing */
    /* Get corresponding EthTSyn Port */
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    timeDomainIdx = EthTSyn_CfgAccess_GetTimeDomainIdx(MsgBufferPtr->Msg.MsgHdr.DomainNumber);
    if(timeDomainIdx != ETHTSYN_INVALID_TIME_DOMAIN_IDX)
    {
      EthTSyn_PortIdxType slavePortIdx = EthTSyn_SwtMgmt_GetSwitchSlavePortIdx(timeDomainIdx);
      if( (slavePortIdx != ETHTSYN_INVALID_PORT_IDX) &&
        (ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(slavePortIdx) == MsgBufferPtr->CtrlIdx) &&
        (EthTSyn_PortConfig[slavePortIdx].SwtInfo.SwitchIdx ==
        MsgBufferPtr->SwtMgmtInfo.SwitchIdx) &&
        (EthTSyn_PortConfig[slavePortIdx].SwtInfo.PortIdx ==
        MsgBufferPtr->SwtMgmtInfo.PortIdx) )
      {
        portIdx = slavePortIdx;
      }
      else
      {
        EthTSyn_PortIdxType masterPortCnt;
        for(masterPortCnt = 0; masterPortCnt < EthTSyn_CfgGetMasterPortCnt(timeDomainIdx); masterPortCnt++)
        {
          if( (ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(EthTSyn_CfgGetMasterPortIdx(timeDomainIdx, masterPortCnt)) ==
            MsgBufferPtr->CtrlIdx) &&
            (EthTSyn_PortConfig[EthTSyn_CfgGetMasterPortIdx(timeDomainIdx, masterPortCnt)].SwtInfo.SwitchIdx ==
            MsgBufferPtr->SwtMgmtInfo.SwitchIdx) &&
            (EthTSyn_PortConfig[EthTSyn_CfgGetMasterPortIdx(timeDomainIdx, masterPortCnt)].SwtInfo.PortIdx ==
            MsgBufferPtr->SwtMgmtInfo.PortIdx) )
          {
            /* port found */
            portIdx = EthTSyn_CfgGetMasterPortIdx(timeDomainIdx, masterPortCnt);
            break;
          }
        }
      }
    }

    if(portIdx != ETHTSYN_INVALID_PORT_IDX)
    {
      /* Valid port found --> process message */
      switch(ETHTSYN_HDR_COM_MSG_TYPE(MsgBufferPtr->Msg.MsgHdr.TransSpecific_MessageType))
      {
        /* Received Pdelay request message */
      case ETHTSYN_MSG_TYPE_PDELAY_REQ:
        /* Check if Pdelay_Responder is active for the port */
        if(EthTSyn_CfgAccess_IsPdelayResponder(portIdx) == FALSE)
        {
          /* Received Pdelay_Req on a port with disabled Pdelay responder --> Drop message */
          errorId = ETHTSYN_E_PDELAY_REQ_MSG_DROPPED;
        }
        else
        {
          EthTSyn_SwtMgmt_ProcessReceivedPdelayReq(MsgBufferPtr, portIdx);
        }
        break;
# if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
      case ETHTSYN_MSG_TYPE_PDELAY_RESP:
        if(EthTSyn_CfgAccess_IsPdelayInitiator(portIdx) == FALSE)
        {
          /* Received PDelay_Resp on Port with disabled Pdelay initiator --> Drop message */
          errorId = ETHTSYN_E_PDELAY_RESP_MSG_DROPPED;
        }
        else
        {
          EthTSyn_SwtMgmt_ProcessReceivedPdelayResp(MsgBufferPtr, portIdx);
        }
        break;

      case ETHTSYN_MSG_TYPE_PDELAY_RES_FOLLOW_UP:
        if(EthTSyn_CfgAccess_IsPdelayInitiator(portIdx) == FALSE)
        {
          /* Received PDelay_Resp on Port with disabled Pdelay initiator --> Drop message */
          errorId = ETHTSYN_E_PDELAY_RESP_FUP_MSG_DROPPED;
        }
        else
        {
          EthTSyn_SwtMgmt_ProcessReceivedPdelayRespFollowUp(MsgBufferPtr, portIdx);
        }
        break;
# endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

      case ETHTSYN_MSG_TYPE_SYNC:
        if(EthTSyn_CfgGetPortRole(portIdx) == ETHTSYN_PORT_ROLE_SLAVE)
        {
# if (ETHTSYN_END_STATION_SUPPORT == STD_ON)
          if(EthTSyn_SwtMgmt_ProcessReceivedSync(MsgBufferPtr, portIdx, timeDomainIdx) == TRUE)
          {
            EthTSyn_PortIdxType endStationSlavePortIdx = EthTSyn_SwtMgmt_GetEndStationSlavePortIdx(timeDomainIdx);
            /* Check if the message has to be forwarded to the EthTSyn End-Station as well */
            if(endStationSlavePortIdx != ETHTSYN_INVALID_PORT_IDX)
            {
              ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType) ingressTimestampPtr = NULL_PTR;
#  if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
              if(MsgBufferPtr->IngressTimestampHostCtrlMgmt.TimestampState ==
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE)
              {
                ingressTimestampPtr = (ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType))
                  &MsgBufferPtr->IngressTimestampHostCtrlMgmt.Timestamp;
              }
#  else
              if(MsgBufferPtr->IngressTimestampMgmt.TimestampState ==
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE)
              {
                ingressTimestampPtr = (ETHTSYN_P2CONST(EthTSyn_GlobalTimestampType))
                  &MsgBufferPtr->IngressTimestampMgmt.Timestamp;
              }
#  endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
              if(ingressTimestampPtr != NULL_PTR)
              {
                /* Pass the message to the End-Station */
                rxFrameInfo.IngressTimestamp = *ingressTimestampPtr;
                EthTSyn_EndStation_ProcessReceivedSync(endStationSlavePortIdx, &MsgBufferPtr->Msg.MsgHdr,
                  &rxFrameInfo);
              }
            }
          }
# else
          (void)EthTSyn_SwtMgmt_ProcessReceivedSync(MsgBufferPtr, portIdx, timeDomainIdx);
# endif /* (ETHTSYN_END_STATION_SUPPORT == STD_ON) */
        }
        else
        {
          errorId = ETHTSYN_E_SYNC_MSG_DROPPED;
        }
        break;

      case ETHTSYN_MSG_TYPE_FOLLOW_UP:
        if(EthTSyn_CfgGetPortRole(portIdx) == ETHTSYN_PORT_ROLE_SLAVE)
        {
          if(EthTSyn_SwtMgmt_ProcessReceivedFollowUp(MsgBufferPtr, portIdx, timeDomainIdx) == TRUE)
          {
            /* Check if the message has to be forwarded to the EthTSyn End-Station as well */
            if(EthTSyn_SwtMgmt_GetEndStationSlavePortIdx(timeDomainIdx) != ETHTSYN_INVALID_PORT_IDX)
            {
              /* Pass the message to the End-Station */
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
              /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
              EthTSyn_TimediffType followUpCorrectionFieldNs = (EthTSyn_TimediffType)
                ETHTSYN_GET_FOLLOW_UP_CORRECTION_VALUE_NS_FROM_MSG(MsgBufferPtr->Msg.MsgHdr.CorrectionField);

              /* PRQA S 3415, 0310 4 */ /* MD_EthTSyn_12.4, MD_EthTSyn_11.4 */
              if((EthTSyn_IsTimestampReadyToProcess(
                ETHTSYN_SYNC_RECEIVE_SM_PTR(portIdx)->Sync.IngressTimestampState) == TRUE) &&
                (EthTSyn_IsTimestampReadyToProcess(
                ETHTSYN_SYNC_RECEIVE_SM_PTR(portIdx)->Sync.EgressTimestampHostPortState)))
              {
                EthTSyn_TimediffType residenceTime;
                /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
                if(EthTSyn_TimestampMinusTimestamp(&ETHTSYN_SYNC_RECEIVE_SM_PTR(portIdx)->Sync.EgressTimestampHostPort,
                  &ETHTSYN_SYNC_RECEIVE_SM_PTR(portIdx)->Sync.IngressTimestamp, &residenceTime) == E_OK)
                { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  followUpCorrectionFieldNs += residenceTime;
                }
              }
              else
              {
                /* Use default residence Time */
                followUpCorrectionFieldNs += (EthTSyn_TimediffType)ETHTSYN_SWT_RX_TO_UPLINK_RESIDENCE_TIME_NS;
              }
              /* PRQA S 0310, 3109 2 */ /* MD_EthTSyn_11.4 */ /* MD_MSR_14_3 */
              EthTSyn_CopyFollowUpCorrectionField((uint64)followUpCorrectionFieldNs,
                MsgBufferPtr->Msg.MsgHdr.CorrectionField);
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
              /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
              EthTSyn_EndStation_ProcessReceivedFollowUp(EthTSyn_SwtMgmt_GetEndStationSlavePortIdx(timeDomainIdx),
                (ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))&MsgBufferPtr->Msg);
            }
          }
        }
        else
        {
          errorId = ETHTSYN_E_FOLLOW_UP_MSG_DROPPED;
        }
        break;

# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
      case ETHTSYN_MSG_TYPE_ANNOUNCE:
        if(EthTSyn_CfgGetPortRole(portIdx) == ETHTSYN_PORT_ROLE_SLAVE)
        {
          EthTSyn_SwtMgmt_ProcessReceivedAnnounce(MsgBufferPtr, portIdx);
        }
        else
        {
          errorId = ETHTSYN_E_ANNOUNCE_MSG_DROPPED;
        }
        break;
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

      default:
        /* This should never happen (MISRA) */
        break;
      }
    }
    EthTSyn_SwtMgmt_ReleaseMsgBuffer(MsgBufferPtr);
  }

  /* ----- Development Error Report ------------------------------------- */
# if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SWT_MGMT_SID_PROCESS_MSG_BUFFER, errorId);
  }
# else
  ETHTSYN_DUMMY_STATEMENT(errorId);
# endif /* ETHTSYN_DEV_ERROR_REPORT */
} /* EthTSyn_SwtMgmt_ProcessMsgBuffer() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: STCAL */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_TriggerStateMachine
 *********************************************************************************************************************/
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_TriggerStateMachine(
    EthTSyn_SwtMgmt_StateMachineIndentificationType StateMachine, EthTSyn_PortIdxType PortIdx)
{
  switch(StateMachine)
  {
    case ETHTSYN_STATE_MACHINE_IDENTIFICATION_P_DELAY_RESP_SM:
      EthTSyn_ProcessSmPdelayResp(PortIdx);
      break;

    case ETHTSYN_STATE_MACHINE_IDENTIFICATION_SYNC_SEND_SM:
      EthTSyn_ProcessSmSyncSend(PortIdx);
      break;

    default:
      /* Nothing to do here */
      break;
  }
} /* EthTSyn_SwtMgmt_TriggerStateMachine() */
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedPdelayReq
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedPdelayReq(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr, EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_PdelayRespSmType) pDelayRespSmPtr = ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx);

  /* Check if Pdelay_Req is expected */
  if( (pDelayRespSmPtr->State == ETHTSYN_STATE_P_DELAY_RESP_WAITING_FOR_PDELAY_REQ) ||
      (pDelayRespSmPtr->State == ETHTSYN_STATE_P_DELAY_RESP_INITAIL_WAITING_FOR_PDELAY_REQ) )
  {
    /* Check if ingress timestamp is available */
    if(ETHTSYN_SWT_MGMT_COND_TIMESTAMP_STATE_TS_AVAILABLE(
        MsgBufferPtr->IngressTimestampMgmt.TimestampState))
    {
      ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* set PdelayResp procedure as in progress to avoid clock change settings in this phase */
      pDelayRespSmPtr->InProgress = TRUE;

      /* store message attributes */
      EthTSyn_SetClockIdentity(pDelayRespSmPtr->PdelayReq.SourcePortIdentity.ClockIdentity,
          MsgBufferPtr->Msg.MsgHdr.SourceClockIdentity);

      pDelayRespSmPtr->PdelayReq.SourcePortIdentity.PortNumber =
          (uint16)EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SourcePortNumber);

      pDelayRespSmPtr->PdelayReq.SequenceId =
          (uint16)EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SequenceId);

      pDelayRespSmPtr->PdelayReq.IngressTimestamp =
          MsgBufferPtr->IngressTimestampMgmt.Timestamp;

      pDelayRespSmPtr->PdelayReq.IngressTimestampState =
          ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;

      /* trigger transmission of PdelayResp message */
      pDelayRespSmPtr->State = ETHTSYN_STATE_P_DELAY_RESP_SEND_P_DELAY_RESP;

      ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      EthTSyn_ProcessSmPdelayResp(PortIdx);
    }
  }
} /* EthTSyn_SwtMgmt_ProcessReceivedPdelayReq() */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedPdelayResp
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedPdelayResp(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr, EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2CONST(EthTSyn_PdelayRespMsgType) pDelayRespMsgPtr;
  ETHTSYN_P2VAR(EthTSyn_PdelayReqSmType) pDelayReqSmPtr = ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx);
  boolean abortProcessing = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
  pDelayRespMsgPtr = (ETHTSYN_P2CONST(EthTSyn_PdelayRespMsgType))
      &MsgBufferPtr->Msg.Payload[0];

  if(pDelayReqSmPtr->State == ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP)
  {
    /* PRQA S 0310 4 */ /* MD_EthTSyn_11.4 */
    if((EthTSyn_PortIdentityIsEqualLocalPort(PortIdx,
      (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))pDelayRespMsgPtr->RequestingClockIdentity) == TRUE) &&
      (EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SequenceId) == pDelayReqSmPtr->PdelayReq.SequenceId))
    {
      if(ETHTSYN_SWT_MGMT_COND_TIMESTAMP_STATE_TS_AVAILABLE(MsgBufferPtr->IngressTimestampMgmt.TimestampState))
      {
        pDelayReqSmPtr->PdelayResp.IngressTimestamp = MsgBufferPtr->IngressTimestampMgmt.Timestamp;
        pDelayReqSmPtr->PdelayResp.IngressTimestampState =
            ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
      }
      else
      {
        abortProcessing = TRUE;
      }

      if(abortProcessing == FALSE)
      {
        pDelayReqSmPtr->PdelayResp.SequenceId = (uint16)EthTSyn_Ntohs(
          MsgBufferPtr->Msg.MsgHdr.SequenceId);
        EthTSyn_SetClockIdentity(pDelayReqSmPtr->PdelayResp.SourcePortIdentity.ClockIdentity,
            MsgBufferPtr->Msg.MsgHdr.SourceClockIdentity);
        pDelayReqSmPtr->PdelayResp.SourcePortIdentity.PortNumber =
            (uint16)EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SourcePortNumber);
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        EthTSyn_NtohTimestamp(&pDelayReqSmPtr->PdelayResp.RequestReceiptTimestamp,
            (ETHTSYN_P2VAR(EthTSyn_TimestampType))pDelayRespMsgPtr->RequestReceiptTimestampSeconds);

        pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP_FOLLOW_UP;
      }
    }
    else /* PdelayResp message has incorrect attributes -> Reset */
    {
#  if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
      /* check for lost responses limit */
      if(pDelayReqSmPtr->LostResponses <
          ETHTSYN_CFG_GET_P_DELAY_ALLOWED_LOST_RESPONSES(PortIdx))
      {
        pDelayReqSmPtr->LostResponses++;
      }
      else /* lost responses limit is exceeded */
      {
        ETHTSYN_SET_AS_CAPABLE(PortIdx, ETHTSYN_CFG_GET_ALWAYS_AS_CAPABLE(PortIdx));
      }
#  endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */

      pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_SEND_P_DELAY_REQ;
    }
  }
  /* check for double PdelayResp message */
  else if(pDelayReqSmPtr->State == ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP_FOLLOW_UP)
  {
    if(pDelayReqSmPtr->PdelayReq.SequenceId == EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SequenceId))
    {
      /* received PdelayResp message with same SequenceId twice -> Reset */
#  if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
      /* check for lost responses limit */
      if(pDelayReqSmPtr->LostResponses < ETHTSYN_CFG_GET_P_DELAY_ALLOWED_LOST_RESPONSES(PortIdx))
      {
        pDelayReqSmPtr->LostResponses++;
      }
      else /* lost responses limit is exceeded */
      {
        ETHTSYN_SET_AS_CAPABLE(PortIdx, ETHTSYN_CFG_GET_ALWAYS_AS_CAPABLE(PortIdx));
      }
#  endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */

      pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_SEND_P_DELAY_REQ;
    }
  }
  else
  {
    /* do nothing */;
  }

  ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
} /* EthTSyn_SwtMgmt_ProcessReceivedPdelayResp() */
/* PRQA L: STCYC */
/* PRQA L: STMIF */
# endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedPdelayRespFollowUp
 *********************************************************************************************************************/
# if (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedPdelayRespFollowUp(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr, EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2CONST(EthTSyn_PDelayResFollowUpMsgType) pDelayRespFollowUpMsgPtr;
  ETHTSYN_P2VAR(EthTSyn_PdelayReqSmType) pDelayReqSmPtr = ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx);

  /* ----- Implementation ----------------------------------------------- */
  ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
  pDelayRespFollowUpMsgPtr = (ETHTSYN_P2CONST(EthTSyn_PDelayResFollowUpMsgType))
      &MsgBufferPtr->Msg.Payload[0];

  if(pDelayReqSmPtr->State == ETHTSYN_STATE_P_DELAY_REQ_WAITING_FOR_P_DELAY_RESP_FOLLOW_UP)
  {
    /* PRQA S 3415, 0310 6 */ /* MD_EthTSyn_12.4, MD_EthTSyn_11.4 */
    if((EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SequenceId) == pDelayReqSmPtr->PdelayReq.SequenceId ) &&
      (EthTSyn_PortIdentityIsEqual(
      (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))&pDelayReqSmPtr->PdelayResp.SourcePortIdentity,
      (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))MsgBufferPtr->Msg.MsgHdr.SourceClockIdentity) == TRUE) &&
      (EthTSyn_PortIdentityIsEqualLocalPort(PortIdx,
      (ETHTSYN_P2CONST(EthTSyn_PortIdentityType))pDelayRespFollowUpMsgPtr->RequestingClockIdentity) == TRUE))
    {

      /* store massage attributes */
      /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
      EthTSyn_NtohTimestamp(&pDelayReqSmPtr->PdelayRespFollowUp.ResponseOriginTimestamp,
        (ETHTSYN_P2VAR(EthTSyn_TimestampType))pDelayRespFollowUpMsgPtr->ResponseOriginTimestampSeconds);

#  if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
      /* reset LostResponses counter */
      pDelayReqSmPtr->LostResponses = 0;
#  endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */

      /* check if the PdelayResp was not from own system */
      /* PRQA S 3415 3 */ /* MD_EthTSyn_12.4 */
      if(EthTSyn_CompareClockIdentity(MsgBufferPtr->Msg.MsgHdr.SourceClockIdentity,
          ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(PortIdx)) != ETHTSYN_COMPARE_EQUAL)
      {
        /* valid PdelayResp and PdelayRespFollowUp were received -> path delay calculation in MainFunction context
        is possible, after PdelayReq message was transmitted successfully (indicated by TxConfirmationPending
        flag)*/
        pDelayReqSmPtr->State = ETHTSYN_STATE_P_DELAY_REQ_RECEIVED_PDELAY_RESP_AND_PDELAY_RESP_FOLLOW_UP;
      }
    }
  }

  ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
} /* EthTSyn_SwtMgmt_ProcessReceivedPdelayResp() */
# endif /* (ETHTSYN_P_DELAY_REQ_STATE_MACHINE_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedSync
 *********************************************************************************************************************/
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedSync(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr, EthTSyn_PortIdxType PortIdx,
    EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean processMessage = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  if((PortIdx < ETHTSYN_PORT_COUNT) && (TimeDomainIdx < ETHTSYN_TIME_DOMAIN_COUNT))
  {
    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    ETHTSYN_P2VAR(EthTSyn_SyncReceiveSmType) syncReceiveSmPtr = ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx);
# if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
    if(ETHTSYN_GET_AS_CAPABLE(PortIdx) == TRUE)
# endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
    {
      if((syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_DISCARD ) ||
        (syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_SYNC ) ||
        (syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_SYNC_TIMEOUT))
      {
# if (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON)
        /* Check if source port identity check is enabled */
        if(EthTSyn_CfgGetEnableSourcePortIdentityCheck(PortIdx) == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        {
          /* Verify source port identity */
          if( EthTSyn_CheckSourcePortIdentity((ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))
            &MsgBufferPtr->Msg.MsgHdr, PortIdx) != TRUE )
          {
            /* source port identity is invalid --> discard message */
            processMessage = FALSE;
          }
        }
# endif /* (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) */
# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
        /* Check if Announce is enabled */
        if(EthTSyn_SlavePortConfigPtr(PortIdx)->EnableAnnounce == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        {
          /* Validate System State */
          if( EthTSyn_CheckAnnounce((ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))
            &MsgBufferPtr->Msg.MsgHdr, TimeDomainIdx) != TRUE )
          {
            /* Check failed --> Stop processing of Sync-Message */
            processMessage = FALSE;
          }
        }
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

# if ( (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) )
        if(processMessage == TRUE)
# endif /* ( (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) || (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) ) */
        {
          /* Check if ingress timestamp is available */
          if(ETHTSYN_SWT_MGMT_COND_TIMESTAMP_STATE_TS_AVAILABLE(MsgBufferPtr->IngressTimestampMgmt.TimestampState))
          {
            /* Store the timestamp */
            syncReceiveSmPtr->Sync.IngressTimestamp = MsgBufferPtr->IngressTimestampMgmt.Timestamp;
            syncReceiveSmPtr->Sync.IngressTimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;

# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
            if(ETHTSYN_SWT_MGMT_COND_TIMESTAMP_STATE_TS_AVAILABLE(
              MsgBufferPtr->EgressTimestampHostPortMgmt.TimestampState))
            {
              syncReceiveSmPtr->Sync.EgressTimestampHostPort = MsgBufferPtr->EgressTimestampHostPortMgmt.Timestamp;
              syncReceiveSmPtr->Sync.EgressTimestampHostPortState =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
            }
            else
            {
              syncReceiveSmPtr->Sync.EgressTimestampHostPortState =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_NOT_AVAILABLE;
            }
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
          }

          /* Store Sync message attributes */
          syncReceiveSmPtr->Sync.LogMessageInterval = MsgBufferPtr->Msg.MsgHdr.LogMessageInterval;

          EthTSyn_SetClockIdentity(syncReceiveSmPtr->Sync.SourcePortIdentity.ClockIdentity,
            MsgBufferPtr->Msg.MsgHdr.SourceClockIdentity);

          syncReceiveSmPtr->Sync.SourcePortIdentity.PortNumber =
            (uint16)EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SourcePortNumber);

          syncReceiveSmPtr->Sync.SequenceId =
            (uint16)EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SequenceId);

          /* change state to waiting for FollowUp */
          syncReceiveSmPtr->State = ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_FOLLOW_UP;
          /* set FollowUp receive timeout time */ /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          syncReceiveSmPtr->FollowUp.FollowUpRxTimeoutCnt =
            EthTSyn_SlavePortConfigPtr(PortIdx)->FollowUpAllowedRxDelay;

# if (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON)
          /* rest sync rx timeout cnt */
          syncReceiveSmPtr->Sync.SyncRxTimeoutCnt = EthTSyn_CfgGetSyncTimeout(TimeDomainIdx);
# endif /* (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON) */

          /* Handle SiteSyncSync state machine */
          switch(EthTSyn_SiteSyncSyncSm(TimeDomainIdx).State)
          {
          case ETHTSYN_STATE_SITE_SYNC_SYNC_RECEIVED_FUP_AFTER_TIMEOUT:
          case ETHTSYN_STATE_SITE_SYNC_SYNC_PENDING:
          case ETHTSYN_STATE_SITE_SYNC_SYNC_SEND_FOLLOW_UP:
            /* Copy Message to SiteSyncSync Sync Message Buffer */
            /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
            IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))&EthTSyn_SiteSyncSyncSm(TimeDomainIdx).Msg.MsgHdr,
              (ETHTSYN_P2CONST(IpBase_CopyDataType))
              &MsgBufferPtr->Msg.MsgHdr, ETHTSYN_HDR_COM_LENGTH);

            /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
            IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))EthTSyn_SiteSyncSyncSm(TimeDomainIdx).Msg.Payload,
              (ETHTSYN_P2CONST(IpBase_CopyDataType))MsgBufferPtr->Msg.Payload,
              ETHTSYN_SWT_MGMT_MSG_BUFFER_PAYLOAD_SIZE);

            /* Reset TxConfirmationPending of the SiteSyncSync state machine */
            EthTSyn_SiteSyncSyncSm(TimeDomainIdx).TxConfirmationPending =
              EthTSyn_TimeDomainConfig[TimeDomainIdx].MasterPortCnt;

            /* Change SiteSyncSyncSm state to 'SendSync' */
            EthTSyn_SiteSyncSyncSm(TimeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_SEND_SYNC;

            /* Process Sm SiteSyncSync */
            EthTSyn_SwtMgmt_ProcessSmSiteSyncSync(TimeDomainIdx);

            break;

          case ETHTSYN_STATE_SITE_SYNC_SYNC_SYNC_TIMEOUT:
            EthTSyn_SiteSyncSyncSm(TimeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_RECEIVED_SYNC_AFTER_TIMEOUT;
            break;

          default:
            /* nothing to do */
            break;
          }
        }
      }
    }
  }

  return processMessage;
} /* EthTSyn_SwtMgmt_ProcessReceivedSync() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: SMIF */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedFollowUp
 *********************************************************************************************************************/
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(boolean, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedFollowUp(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr, EthTSyn_PortIdxType PortIdx,
    EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2VAR(EthTSyn_SyncReceiveSmType) syncReceiveSmPtr;
  boolean processMessage = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  if((PortIdx < ETHTSYN_PORT_COUNT) && (TimeDomainIdx < ETHTSYN_TIME_DOMAIN_COUNT))
  {
    syncReceiveSmPtr = ETHTSYN_SYNC_RECEIVE_SM_PTR(PortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

    if((syncReceiveSmPtr->State == ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_FOLLOW_UP) &&
      (EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SequenceId) == syncReceiveSmPtr->Sync.SequenceId) )
    {
# if (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON)
      /* Check if source port identity check is enabled */
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      if(EthTSyn_SlavePortConfigPtr(PortIdx)->EnableSrcPortIdentityCheck == TRUE)
      {
        /* Verify source port identity */
        if( EthTSyn_CheckSourcePortIdentity((ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))
          &MsgBufferPtr->Msg.MsgHdr, PortIdx) != TRUE )
        {

          /* source port identity is invalid --> discard message */
          processMessage = FALSE;
        }
      }
# endif /* (ETHTSYN_SRC_PORT_IDENTITY_CHECK_SUPPORT == STD_ON) */
# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
      /* Check if Announce is enabled */
      if(EthTSyn_SlavePortConfigPtr(PortIdx)->EnableAnnounce == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
      {
        /* Validate System State */
        if( EthTSyn_CheckAnnounce((ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))
          &MsgBufferPtr->Msg.MsgHdr, TimeDomainIdx) != TRUE )
        {
          /* Check failed --> Stop processing of Sync-Message */
          processMessage = FALSE;
        }
      }
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON) */

      {
        /* Check for matching source port identity of Sync and FollowUp */
        /* PRQA S 0310 4 */ /* MD_EthTSyn_11.4 */
        if( (EthTSyn_CompareClockIdentity(MsgBufferPtr->Msg.MsgHdr.SourceClockIdentity,
          syncReceiveSmPtr->Sync.SourcePortIdentity.ClockIdentity) != ETHTSYN_COMPARE_EQUAL) ||
          (EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SourcePortNumber) !=
          syncReceiveSmPtr->Sync.SourcePortIdentity.PortNumber) )
        {
          /* Received FollowUp from different node than the former Sync --> discard message */
          processMessage = FALSE;
        }
      }

      if(processMessage == TRUE)
      {
        /* store message attributes */
        syncReceiveSmPtr->FollowUp.SequenceId = /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
          (uint16)EthTSyn_Ntohs(MsgBufferPtr->Msg.MsgHdr.SequenceId);

        /* Handle SiteSyncSycnSm */
        switch(EthTSyn_SiteSyncSyncSm(TimeDomainIdx).State)
        {
        case ETHTSYN_STATE_SITE_SYNC_SYNC_PENDING:
        case ETHTSYN_STATE_SITE_SYNC_SYNC_SEND_SYNC:
          /* Copy FollowUp message to SiteSyncSync state machine */
          /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))&EthTSyn_SiteSyncSyncSm(TimeDomainIdx).Msg.MsgHdr,
            (ETHTSYN_P2CONST(IpBase_CopyDataType))
            &MsgBufferPtr->Msg.MsgHdr, ETHTSYN_HDR_COM_LENGTH);

          /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
          IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))EthTSyn_SiteSyncSyncSm(TimeDomainIdx).Msg.Payload,
            (ETHTSYN_P2CONST(IpBase_CopyDataType))MsgBufferPtr->Msg.Payload,
            ETHTSYN_SWT_MGMT_MSG_BUFFER_PAYLOAD_SIZE);

          /* Reset TxConfirmationPending of SiteSyncSync state machine. */
          EthTSyn_SiteSyncSyncSm(TimeDomainIdx).TxConfirmationPending =
            EthTSyn_TimeDomainConfig[TimeDomainIdx].MasterPortCnt;

          /* Change state of SiteSyncSyncSm and Process the SM */
          EthTSyn_SiteSyncSyncSm(TimeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_SEND_FOLLOW_UP;

          EthTSyn_SwtMgmt_ProcessSmSiteSyncSync(TimeDomainIdx);
          break;

        case ETHTSYN_STATE_SITE_SYNC_SYNC_RECEIVED_SYNC_AFTER_TIMEOUT:
          EthTSyn_SiteSyncSyncSm(TimeDomainIdx).State = ETHTSYN_STATE_SITE_SYNC_SYNC_RECEIVED_FUP_AFTER_TIMEOUT;

          EthTSyn_SwtMgmt_ProcessSmSiteSyncSync(TimeDomainIdx);
          break;

        default:
          /* nothing to do */
          break;
        }

        syncReceiveSmPtr->State = ETHTSYN_STATE_SYNC_RECEIVE_WAITING_FOR_SYNC;
      }
    }
  }

  return processMessage;
} /* EthTSyn_SwtMgmt_ProcessReceivedFollowUp() */
/* PRQA L: STCYC */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessReceivedAnnounce
 *********************************************************************************************************************/
# if (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessReceivedAnnounce(
    ETHTSYN_CONSTP2CONST(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr, EthTSyn_PortIdxType PortIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType) announceMsgPtr;

  /* ----- Implementation ----------------------------------------------- */
#  if (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON)
  if(ETHTSYN_GET_AS_CAPABLE(PortIdx) == TRUE)
#  endif /* (ETHTSYN_AS_CAPABLE_SUPPORT == STD_ON) */
  {
    /* Check if announce is enabled for the slave port */
    if(EthTSyn_CfgGetEnableAnnounce(PortIdx) == TRUE) /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
    {
      /* check for valid Announce message */
      if(EthTSyn_SwtMgmt_QualifyAnnounceMsg(PortIdx, MsgBufferPtr) == E_OK)
      {
        /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
        announceMsgPtr = (ETHTSYN_P2CONST(EthTSyn_AnnounceMsgType))&MsgBufferPtr->Msg.Payload[0];
        CANOE_WRITE_STRING("EthTSyn_RxIndication: Received Announce");
        /* reset announce timeout counter */ /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        ETHTSYN_ANNOUNCE_RECEIVE_SM_PTR(PortIdx)->RxTimeoutCnt =
          EthTSyn_SlavePortConfigPtr(PortIdx)->AnnounceAllowedRxDelay;
        /* check if no Grandmaster is available */
        if(EthTSyn_SystemState[ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(PortIdx)].GmPresent == FALSE)
        {
          EthTSyn_SetMasterPriorityVector(announceMsgPtr, ETHTSYN_CFG_GET_TIME_DOMAIN_IDEX_OF_PORT(PortIdx));
        }
      }
    }
  }
} /* EthTSyn_SwtMgmt_ProcessReceivedAnnounce() */
# endif /* (ETHTSYN_ANNOUNCE_RX_SUPPORT == STD_ON ) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ReleaseMsgBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ETHTSYN_LOCAL_INLINE FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ReleaseMsgBuffer(
    ETHTSYN_CONSTP2VAR(EthTSyn_SwtMgmt_MsgBufferType) MsgBufferPtr)
{
  ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* #10 Release the message buffer */
  MsgBufferPtr->MsgBufferState = ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_UNUSED;
  /* #20 Reset the timestamp states */
  MsgBufferPtr->IngressTimestampMgmt.TimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_INVALID;
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
  MsgBufferPtr->EgressTimestampHostPortMgmt.TimestampState = ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_INVALID;
# endif
  /* #30 Reset the EthIf Ctrl and MgmtInfo */
  MsgBufferPtr->CtrlIdx = ETHTSYN_INVALID_ETHIF_CTRL_IDX;
  MsgBufferPtr->SwtMgmtInfo.SwitchIdx = ETHTSYN_INVALID_ETHIF_SWITCH_IDX;
  MsgBufferPtr->SwtMgmtInfo.PortIdx = ETHTSYN_INVALID_SWITCH_PORT_IDX;

  /* #40 Reset Rx buffer pointer */
  MsgBufferPtr->RxBufAddr = NULL_PTR;

  ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

} /* EthTSyn_SwtMgmt_ReleaseMsgBuffer() */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProvideMsgBuffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProvideMsgBuffer(
    ETHTSYN_P2VAR(EthTSyn_SwtMgmt_MsgBufferType) *MsgBufferPtrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8_least index;

  /* ----- Implementation ----------------------------------------------- */
  *MsgBufferPtrPtr = NULL_PTR;

  ETHTSYN_ENTER_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* #10 Iterate through all message buffers */
  for(index = 0; index < ETHTSYN_SWT_MGMT_MSG_BUFFER_COUNT; index++)
  {
    /* #1000 If message buffer is free */
    if(EthTSyn_SwtMgmt_MsgBuffer[index].MsgBufferState == ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_UNUSED)
    {
      /* #100000 Lock the message buffer */
      EthTSyn_SwtMgmt_MsgBuffer[index].MsgBufferState = ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_MSG_INVALID;

      /* 100010 Provide the MsgBuffer Pointer */
      *MsgBufferPtrPtr = &EthTSyn_SwtMgmt_MsgBuffer[index];
      retVal = E_OK;
      break;
    }
  }
  ETHTSYN_LEAVE_CRITICAL_SECTION_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return retVal;
} /* EthTSyn_SwtMgmt_ProvideMsgBuffer() */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetMappedMsgBuffer
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetMappedMsgBuffer(uint8 CtrlIdx,
    ETHTSYN_P2CONST(uint8) RxBufAddr, EthTSyn_FrameIdType FrameId,
    ETHTSYN_P2VAR(EthTSyn_SwtMgmt_MsgBufferType) *MsgBufferPtrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8_least index;

  /* ----- Implementation ----------------------------------------------- */
  for(index = 0; index < ETHTSYN_SWT_MGMT_MSG_BUFFER_COUNT; index++)
  {
    if( (EthTSyn_SwtMgmt_MsgBuffer[index].MsgBufferState == ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_MSG_VALID) ||
        (EthTSyn_SwtMgmt_MsgBuffer[index].MsgBufferState == ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_PORT_INFO_AVAILABLE) )
    {
      if( (EthTSyn_SwtMgmt_MsgBuffer[index].CtrlIdx == CtrlIdx) &&
          (EthTSyn_SwtMgmt_MsgBuffer[index].RxBufAddr == RxBufAddr) &&
          (ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MSG_BUFFER(&EthTSyn_SwtMgmt_MsgBuffer[index]) == FrameId) )
      {
        retVal = E_OK;
        *MsgBufferPtrPtr = &EthTSyn_SwtMgmt_MsgBuffer[index];
        break;
      }
    }
  }

  return retVal;
} /* EthTSyn_SwtMgmt_GetMappedMsgBuffer() */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetEndStationSlavePortIdx
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(EthTSyn_PortIdxType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetEndStationSlavePortIdx(
  EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
/* ----- Local Variables ---------------------------------------------- */
  EthTSyn_PortIdxType slavePortIdx = ETHTSYN_INVALID_PORT_IDX;
  EthTSyn_PortIdxType slavePortCnt;

  /* ----- Implementation ----------------------------------------------- */
  if(TimeDomainIdx < ETHTSYN_TIME_DOMAIN_COUNT)
  {
    slavePortCnt = EthTSyn_CfgGetSlavePortCnt(TimeDomainIdx);

    if(slavePortCnt > 0)
    {
      while(slavePortCnt > 0)
      {
        slavePortCnt--;
        if((EthTSyn_GetPortType(EthTSyn_CfgGetSlavePortIdx(TimeDomainIdx, slavePortCnt)) &
          ETHTSYN_PORT_TYPE_END_STATION_PORT) != 0)
        {
          slavePortIdx = EthTSyn_CfgGetSlavePortIdx(TimeDomainIdx, slavePortCnt);
          break;
        }
      }
    }
  }
  return slavePortIdx;
} /* EthTSyn_SwtMgmt_GetEndStationSlavePortIdx() */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetSwitchSlavePortIdx
 *********************************************************************************************************************/
ETHTSYN_LOCAL_INLINE FUNC(EthTSyn_PortIdxType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetSwitchSlavePortIdx(
  EthTSyn_TimeDomainIdxType TimeDomainIdx)
{ /* No 'SwtMgmt' in-fixing because the function will be used globally in future */
/* ----- Local Variables ---------------------------------------------- */
  EthTSyn_PortIdxType slavePortIdx = ETHTSYN_INVALID_PORT_IDX;
  EthTSyn_PortIdxType slavePortCnt = EthTSyn_CfgGetSlavePortCnt(TimeDomainIdx);

  /* ----- Implementation ----------------------------------------------- */
  while(slavePortCnt > 0)
  {
    slavePortCnt--;
    if((EthTSyn_GetPortType(EthTSyn_CfgGetSlavePortIdx(TimeDomainIdx, slavePortCnt)) &
      ETHTSYN_PORT_TYPE_SWITCH_PORT) != 0)
    {
      slavePortIdx = EthTSyn_CfgGetSlavePortIdx(TimeDomainIdx, slavePortCnt);
      break;
    }
  }

  return slavePortIdx;
} /* EthTSyn_SwtMgmt_GetSwitchSlavePortIdx() */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetIngressTimestamp
 *********************************************************************************************************************/
/* PRQA S 3673 2 */ /* MD_EthTSyn_16.7c */
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetIngressTimestamp(uint8 EthIfCtrlIdx,
  ETHTSYN_P2VAR(uint8) DataPtr, ETHTSYN_P2VAR(EthTSyn_GlobalTimestampType) IngressTimestampPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  EthTSyn_GlobalTimestampType ingressTimestamp;
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
  Eth_TimestampQualityType timestampQual = ETH_INVALID;
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

  /* ----- Implementation ----------------------------------------------- */
# if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
  ETHTSYN_CHECK_CRITICAL_SECTION_0();
  /* HW-Timestamping */ /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
  if(EthIf_GetIngressTimeStamp(EthIfCtrlIdx, (ETHTSYN_P2VAR(Eth_DataType))DataPtr, &timestampQual,
    &ingressTimestamp) == E_OK)
  {
    if(timestampQual == ETH_VALID)
    {
      *IngressTimestampPtr = ingressTimestamp;
      retVal = E_OK;
    }
  }
# else
  /* SW-Timestamping */
  ETHTSYN_DUMMY_STATEMENT(EthIfCtrlIdx); /* PRQA S 3112 */ /* MD_MSR_14.2 */
  ETHTSYN_DUMMY_STATEMENT(DataPtr); /* PRQA S 3112 */ /* MD_MSR_14.2 */
  ETHTSYN_CHECK_CRITICAL_SECTION_0();
  if(StbM_GetCurrentTimeRaw(&ingressTimestamp.nanoseconds) == E_OK)
  {
    IngressTimestampPtr->secondsHi = 0;
    IngressTimestampPtr->seconds = 0;
    IngressTimestampPtr->nanoseconds = ingressTimestamp.nanoseconds;
    retVal = E_OK;
  }
# endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */

  return retVal;
} /* EthTSyn_SwtMgmt_GetIngressTimestamping() */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetMappedStateMachine
 *********************************************************************************************************************/
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
ETHTSYN_LOCAL_INLINE FUNC(EthTSyn_SwtMgmt_StateMachineIndentificationType, ETHTSYN_CODE)
  EthTSyn_SwtMgmt_GetMappedStateMachine(uint8 CtrlIdx, ETHTSYN_CONSTP2CONST(uint8) TxBufPtr,
  EthTSyn_FrameIdType FrameId, ETHTSYN_P2VAR(EthTSyn_PortIdxType) PortIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  EthTSyn_SwtMgmt_StateMachineIndentificationType stateMachine = ETHTSYN_STATE_MACHINE_IDENTIFICATION_INVLID_SM;
  EthTSyn_PortIdxType portIdx;

  /* ----- Implementation ----------------------------------------------- */

  /* Iterate through all relevant state machines (i.e. SyncSend, Pdelay_Req, Pdelay_Resp */
  for(portIdx = 0; portIdx < ETHTSYN_PORT_COUNT; portIdx++)
  {
    if(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(portIdx) == CtrlIdx)
    {
      /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
      if((EthTSyn_CfgGetPortRole(portIdx) == ETHTSYN_PORT_ROLE_MASTER) &&
        (ETHTSYN_SYNC_SEND_SM_PTR(portIdx)->SyncTxBufPtr == TxBufPtr) &&
          (ETHTSYN_SWT_MGMT_FRAME_ID_FROM_SM(ETHTSYN_SYNC_SEND_SM_PTR(portIdx)) == FrameId))
      {
        /* SyncSend state machine */
        stateMachine = ETHTSYN_STATE_MACHINE_IDENTIFICATION_SYNC_SEND_SM;
      }
      else if((EthTSyn_CfgAccess_IsPdelayInitiator(portIdx) == TRUE) &&
        (ETHTSYN_P_DELAY_REQ_SM_PTR(portIdx)->TxBufPtr == TxBufPtr) &&
        (ETHTSYN_SWT_MGMT_FRAME_ID_FROM_SM(ETHTSYN_P_DELAY_REQ_SM_PTR(portIdx)) == FrameId))
      {
        /* Pdelay request state machine */
        stateMachine = ETHTSYN_STATE_MACHINE_IDENTIFICATION_P_DELAY_REQ_SM;
      }
      else if((EthTSyn_CfgAccess_IsPdelayResponder(portIdx) == TRUE) &&
        (ETHTSYN_P_DELAY_RESP_SM_PTR(portIdx)->TxBufPtr == TxBufPtr) &&
        (ETHTSYN_SWT_MGMT_FRAME_ID_FROM_SM(ETHTSYN_P_DELAY_RESP_SM_PTR(portIdx)) == FrameId))
      {
        /* Pdelay response state machine */
        stateMachine = ETHTSYN_STATE_MACHINE_IDENTIFICATION_P_DELAY_RESP_SM;
      }
      else
      {
        /* No matching state machine found --> continue with next port */
      }

      if(stateMachine != ETHTSYN_STATE_MACHINE_IDENTIFICATION_INVLID_SM)
      {
        /* State Machine found --> stop iteration and get PortIdx + TimeDomainIdx */
        *PortIdxPtr = portIdx;
        break;
      }
    }
  }

  return stateMachine;
} /* EthTSyn_SwtMgmt_GetMappedStateMachine */
/* PRQA L: STMIF */
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_GetStateMachineTxTimestampInfo
 *********************************************************************************************************************/
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
ETHTSYN_LOCAL_INLINE FUNC(Std_ReturnType, ETHTSYN_CODE) EthTSyn_SwtMgmt_GetStateMachineTxTimestampInfo(
    EthTSyn_SwtMgmt_StateMachineIndentificationType StateMachine,
    EthTSyn_PortIdxType PortIdx, EthTSyn_SwtMgmt_TimestampDirectionType TimestampDir,
    ETHTSYN_P2VAR(EthTSyn_GlobalTimestampType) *TimestampPtrPtr,
    ETHTSYN_P2VAR(EthTSyn_TimestampStateType) *TimestampStatePtrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  switch(StateMachine)
  {
    case ETHTSYN_STATE_MACHINE_IDENTIFICATION_SYNC_SEND_SM:
      if(TimestampDir == ETHTSYN_SWT_MGMT_TIMESTAMP_DIRECTION_INGRESS)
      {
        /* PRQA S 0310 4 */ /* MD_EthTSyn_11.4 */
        *TimestampPtrPtr = &ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SyncIngressTimestampHostPort;
        *TimestampStatePtrPtr = &ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SyncIngressTimestampStateHostPort;
        if(EthTSyn_IsTimestampReadyToProcess(
            ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SyncEgressTimestampStateSwitchPort) == TRUE)
        {
          ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SyncTxBufPtr = NULL_PTR; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        }
        retVal = E_OK;
      }
      if(TimestampDir == ETHTSYN_SWT_MGMT_TIMESTAMP_DIRECTION_EGRESS)
      {
        /* PRQA S 0310 4 */ /* MD_EthTSyn_11.4 */
        *TimestampPtrPtr = &ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SyncEgressTimestampSwitchPort;
        *TimestampStatePtrPtr = &ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SyncEgressTimestampStateSwitchPort;
        if(EthTSyn_IsTimestampReadyToProcess(
          ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SyncIngressTimestampStateHostPort) == TRUE)
        {
          ETHTSYN_SYNC_SEND_SM_PTR(PortIdx)->SyncTxBufPtr = NULL_PTR; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
        }
        retVal = E_OK;
      }
      break;

    case ETHTSYN_STATE_MACHINE_IDENTIFICATION_P_DELAY_REQ_SM:
      if(TimestampDir == ETHTSYN_SWT_MGMT_TIMESTAMP_DIRECTION_EGRESS)
      {
        *TimestampPtrPtr = &ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->PdelayReq.EgressTimestamp;
        *TimestampStatePtrPtr = &ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->PdelayReq.EgressTimestampState;
        ETHTSYN_P_DELAY_REQ_SM_PTR(PortIdx)->TxBufPtr = NULL_PTR;
        retVal = E_OK;
      }
      break;

    case ETHTSYN_STATE_MACHINE_IDENTIFICATION_P_DELAY_RESP_SM:
      if(TimestampDir == ETHTSYN_SWT_MGMT_TIMESTAMP_DIRECTION_EGRESS)
      {
        *TimestampPtrPtr = &ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx)->PdelayResp.EgressTimestamp;
        *TimestampStatePtrPtr = &ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx)->PdelayResp.EgressTimestampState;
        ETHTSYN_P_DELAY_RESP_SM_PTR(PortIdx)->TxBufPtr = NULL_PTR;
        retVal = E_OK;
      }
      break;

    default:
      /* nothing to do here */
      break;
  }

  return retVal;
} /* EthTSyn_SwtMgmt_GetStateMachineTimestampInfo() */
# endif /* ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least u8Index;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Initialize message buffers */
  for(u8Index = 0; u8Index < ETHTSYN_SWT_MGMT_MSG_BUFFER_COUNT; u8Index++)
  {
    IpBase_Fill(&EthTSyn_SwtMgmt_MsgBuffer[u8Index], 0, sizeof(EthTSyn_SwtMgmt_MsgBufferType));
  }

  /* #20 Initialize site sync sync state machine */
  for(u8Index = 0; u8Index < ETHTSYN_TIME_DOMAIN_COUNT; u8Index++)
  {
    /* #2000 Initialize site sync sync state machine state */
    if(EthTSyn_CfgGetSlavePortCnt(u8Index) <= 0)
    {
      EthTSyn_SiteSyncSyncSm(u8Index).State = ETHTSYN_STATE_SITE_SYNC_SYNC_DISABLED;
      ETHTSYN_STATE_GET_SLAVE_PORT_IDX(u8Index) = ETHTSYN_INVALID_PORT_IDX;
    }
    else
    {
      ETHTSYN_STATE_GET_SLAVE_PORT_IDX(u8Index) =
        EthTSyn_SwtMgmt_GetSwitchSlavePortIdx((EthTSyn_TimeDomainIdxType)u8Index);
      EthTSyn_SiteSyncSyncSm(u8Index).TxConfirmationPending = 0;
      EthTSyn_SiteSyncSyncSm(u8Index).State = ETHTSYN_STATE_SITE_SYNC_SYNC_PENDING;
# if (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON)
      /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
      ETHTSYN_SYNC_RECEIVE_SM_PTR(ETHTSYN_STATE_GET_SLAVE_PORT_IDX(u8Index))->Sync.SyncRxTimeoutCnt =
        EthTSyn_CfgGetSyncTimeout(u8Index);
# endif /* (ETHTSYN_SWT_MGMT_IS_GM_CAPABLE == STD_ON) */
    }
  }

} /* EthTSyn_SwtMgmt_Init() */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessSmSiteSyncSync
 *********************************************************************************************************************/
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessSmSiteSyncSync(EthTSyn_TimeDomainIdxType TimeDomainIdx)
{
  /* ----- Local Variables -------------------------------------------- */
  /* PRQA S 0781 1 */ /* MD_EthTSyn_5.6 */
  uint16 masterPortCnt = EthTSyn_CfgGetMasterPortCnt(TimeDomainIdx);
  EthTSyn_PortIdxType masterPortIdx;
  EthTSyn_PortIdxType slavePortIdx;
  uint8 bufIdx = ETHTSYN_INV_BUF_IDX;
  ETHTSYN_P2VAR(EthTSyn_SyncSendSmType) syncSendSmPtr;
  ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType) comHdrPtr;
  ETHTSYN_P2VAR(uint8) u8BufPtr;
  uint16 lenByte;
  EthSwt_MgmtInfoType mgmtInfo;
  uint8 errorId = ETHTSYN_E_NO_ERROR;

  /* ----- Implementation --------------------------------------------- */
  switch(EthTSyn_SiteSyncSyncSm(TimeDomainIdx).State)
  {
  case ETHTSYN_STATE_SITE_SYNC_SYNC_SEND_SYNC:
    while(masterPortCnt > 0)
    {
      masterPortCnt--;
      masterPortIdx = EthTSyn_CfgGetMasterPortIdx(TimeDomainIdx, masterPortCnt);
      lenByte = ETHTSYN_MSG_SYNC_LENGTH;
      syncSendSmPtr = ETHTSYN_SYNC_SEND_SM_PTR(masterPortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
      if( (syncSendSmPtr->State == ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_PENDING) ||
          (syncSendSmPtr->State == ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_SEND_FOLLOW_UP) )
      {
        syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_SEND_SYNC;
      }

      if(syncSendSmPtr->State == ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_SEND_SYNC)
      {
        ETHTSYN_CHECK_CRITICAL_SECTION_0();
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        if(EthIf_ProvideTxBuffer(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(masterPortIdx), ETHTSYN_FRAME_TYPE,
          ETHTSYN_CFG_GET_FRAME_PRIORITY(masterPortIdx), &bufIdx, (ETHTSYN_P2VAR(Eth_DataType*))&u8BufPtr,
          &lenByte) == BUFREQ_OK)
        {
          /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
          ETHTSYN_P2VAR(EthTSyn_SyncMsgType) SyncMsgPtr =
            (ETHTSYN_P2VAR(EthTSyn_SyncMsgType))&u8BufPtr[ETHTSYN_HDR_COM_LENGTH];
          comHdrPtr = (ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType))u8BufPtr;

          /* Copy common Hdr to TxBuffer */
          /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
          IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))comHdrPtr,
            (ETHTSYN_P2CONST(IpBase_CopyDataType))&EthTSyn_SiteSyncSyncSm(TimeDomainIdx).Msg.MsgHdr,
            ETHTSYN_HDR_COM_LENGTH);

          /* Manipulate SourcePortIdentity fields within the common Hdr if required */
          if(EthTSyn_CfgGetKeepSrcPortIdentity(TimeDomainIdx) != TRUE)
          {
            /* Use 'Own' source port identity */
            EthTSyn_SetClockIdentity(comHdrPtr->SourceClockIdentity,
              ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(masterPortIdx));

            comHdrPtr->SourcePortNumber = (uint16)EthTSyn_Htons(ETHTSYN_CFG_GET_PORT_NUMBER(masterPortIdx));
          }

          /* Copy Sync message values to TxBuffer */
          /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
          IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))SyncMsgPtr,
            (ETHTSYN_P2CONST(IpBase_CopyDataType))EthTSyn_SiteSyncSyncSm(TimeDomainIdx).Msg.Payload,
            ETHTSYN_MSG_SYNC_PAYLOAD_LENGTH);

          syncSendSmPtr->SyncTxBufIdx = bufIdx;
          syncSendSmPtr->SyncTxBufPtr = u8BufPtr;
# if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
          /* Save Frame Id */
          mgmtInfo.FrameId = EthTSyn_GetFrameId(u8BufPtr, lenByte);
          syncSendSmPtr->FrameId = mgmtInfo.FrameId;

          CANOE_WRITE_STRING_2("[FRAME_ID_DEBUG] PortIdx: %d FrameId: %d (Sync_Forwarded)",
            masterPortIdx, mgmtInfo.FrameId);
# endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)*/
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
          syncSendSmPtr->SyncEgressTimestampStateSwitchPort =
            ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;
          syncSendSmPtr->SyncIngressTimestampStateHostPort =
            ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;
# else
           syncSendSmPtr->FollowUpPreciseOriginTimestampState =
             ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

           /* Get Switch management Info */
           mgmtInfo.SwitchIdx = EthTSyn_PortConfig[masterPortIdx].SwtInfo.SwitchIdx;
           mgmtInfo.PortIdx = EthTSyn_PortConfig[masterPortIdx].SwtInfo.PortIdx;

# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
           ETHTSYN_CHECK_CRITICAL_SECTION_0();
           (void)EthIf_SwitchEnableEgressTimeStamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(masterPortIdx), bufIdx, &mgmtInfo);
# else
#  if (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON)
           ETHTSYN_CHECK_CRITICAL_SECTION_0();
           (void)EthIf_EnableEgressTimestamp(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(masterPortIdx), bufIdx);
#  endif /* (ETHTSYN_HW_TIMESTAMP_SUPPORT == STD_ON) */
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

          if(EthTSyn_Transmit(masterPortIdx, bufIdx, ETHTSYN_MSG_SYNC_LENGTH, TRUE, &mgmtInfo) != E_OK)
          {
            /* EthTSyn_SiteSyncSyncSm(TimeDomainIdx).TxConfirmationPending is set to the amount of configured
             * MasterPorts for the TimeDomain at the reception of a Sync message. Since this code part can only
             * be reached after the reception of a Sync message no underflow is possible */
            EthTSyn_SiteSyncSyncSm(TimeDomainIdx).TxConfirmationPending--;
            /* Transmission failed */
            syncSendSmPtr->SyncTxBufIdx = ETHTSYN_INV_BUF_IDX;
            syncSendSmPtr->SyncTxBufPtr = NULL_PTR;
# if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
            syncSendSmPtr->FrameId = ETHTSYN_INVALID_FRAME_ID;
# endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
            errorId = ETHTSYN_E_TX_FAILED;
          }
        }
      }
    }/* END: Iteration MasterPorts */
    break; /* END: ETHTSYN_STATE_SITE_SYNC_SYNC_SEND_SYNC */

  case ETHTSYN_STATE_SITE_SYNC_SYNC_SEND_FOLLOW_UP:
    slavePortIdx = EthTSyn_SwtMgmt_GetSwitchSlavePortIdx(TimeDomainIdx);

    /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
    if(EthTSyn_IsTimestampReadyToProcess(ETHTSYN_SYNC_RECEIVE_SM_PTR(slavePortIdx)->Sync.IngressTimestampState) ==
      TRUE)
    {
      while(masterPortCnt > 0)
      {
        boolean readyToTransmit = FALSE;
        ETHTSYN_P2CONST(EthTSyn_TimestampStateType) syncEgressTimestampStatePtr;
        ETHTSYN_P2VAR(EthTSyn_GlobalTimestampType)  syncEgressTimestampPtr;

        masterPortCnt--;
        masterPortIdx = EthTSyn_TimeDomainConfig[TimeDomainIdx].MasterPortIdxPtr[masterPortCnt];
        lenByte = ETHTSYN_MSG_FOLLOW_UP_TX_LENGTH;
        syncSendSmPtr = ETHTSYN_SYNC_SEND_SM_PTR(masterPortIdx); /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
        syncEgressTimestampStatePtr = &syncSendSmPtr->SyncEgressTimestampStateSwitchPort;
        syncEgressTimestampPtr      = &syncSendSmPtr->SyncEgressTimestampSwitchPort;
# else
        syncEgressTimestampStatePtr = &syncSendSmPtr->FollowUpPreciseOriginTimestampState;
        syncEgressTimestampPtr      = &syncSendSmPtr->FollowUpPreciseOriginTimestamp;
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

        if(syncSendSmPtr->State == ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_WAIT_FOLLOW_UP)
        {
          syncSendSmPtr->State = ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_SEND_FOLLOW_UP;
        }
        
        if(syncSendSmPtr->State == ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_SEND_FOLLOW_UP)
        {
          if(EthTSyn_IsTimestampReadyToProcess(*syncEgressTimestampStatePtr) == TRUE)
          {
            readyToTransmit = TRUE;
          }
        }

        if(readyToTransmit == TRUE)
        {
          ETHTSYN_CHECK_CRITICAL_SECTION_0();
          /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          if(EthIf_ProvideTxBuffer(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(masterPortIdx), ETHTSYN_FRAME_TYPE,
            ETHTSYN_CFG_GET_FRAME_PRIORITY(masterPortIdx), &bufIdx, (ETHTSYN_P2VAR(Eth_DataType*))&u8BufPtr,
            &lenByte) == BUFREQ_OK)
          {
            /* ----- Variables ----------------------------------- */
            EthTSyn_TimediffType followUpCorrectionFieldNs = 0;
            /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
            ETHTSYN_P2VAR(EthTSyn_FollowUpMsgType) followUpMsgPtr =
              (ETHTSYN_P2VAR(EthTSyn_FollowUpMsgType))&u8BufPtr[ETHTSYN_HDR_COM_LENGTH];
            comHdrPtr = (ETHTSYN_P2VAR(EthTSyn_CommonMsgHdrType))u8BufPtr;
    
            /* Copy Common Hdr to TxBuffer */
            /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
            IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))comHdrPtr,
              (ETHTSYN_P2CONST(IpBase_CopyDataType))&EthTSyn_SiteSyncSyncSm(TimeDomainIdx).Msg.MsgHdr,
              ETHTSYN_HDR_COM_LENGTH);
    
            /* Copy FollwUp to TxBuffer */
            /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
            IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))followUpMsgPtr,
              (ETHTSYN_P2CONST(IpBase_CopyDataType))EthTSyn_SiteSyncSyncSm(TimeDomainIdx).Msg.Payload,
              (ETHTSYN_MSG_FOLLOW_UP_TX_LENGTH - ETHTSYN_HDR_COM_LENGTH));
    
            /* Manipulate the SourcePortIdentity if required */
            if(EthTSyn_CfgGetKeepSrcPortIdentity(TimeDomainIdx) != TRUE)
            {
              /* Use 'Own' source port identity */
              EthTSyn_SetClockIdentity(comHdrPtr->SourceClockIdentity,
                ETHTSYN_STATE_GET_LOCAL_CLOCK_IDENTITY(masterPortIdx));
    
              comHdrPtr->SourcePortNumber =
                (uint16)EthTSyn_Htons(EthTSyn_PortConfig[masterPortIdx].PortNumber);
            }
            /* Calculate the 'Residence Time' of the Sync-Message */
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
            if(ETHTSYN_SWT_MGMT_COND_TIMESTAMP_STATE_TS_AVAILABLE(*syncEgressTimestampStatePtr))
            {
              /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
              if(EthTSyn_TimestampMinusTimestamp(syncEgressTimestampPtr,
                &ETHTSYN_SYNC_RECEIVE_SM_PTR(slavePortIdx)->Sync.IngressTimestamp, &followUpCorrectionFieldNs) != E_OK)
              {
                followUpCorrectionFieldNs = (EthTSyn_TimediffType)
                  (ETHTSYN_SWT_RX_TO_UPLINK_RESIDENCE_TIME_NS + ETHTSYN_SWT_UPLINK_TO_TX_RESIDENCE_TIME_NS);
              }
            }
            else
            {
              followUpCorrectionFieldNs = (EthTSyn_TimediffType)
                (ETHTSYN_SWT_RX_TO_UPLINK_RESIDENCE_TIME_NS + ETHTSYN_SWT_UPLINK_TO_TX_RESIDENCE_TIME_NS);
            }
# else
            /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
            if(EthTSyn_TimestampMinusTimestamp(syncEgressTimestampPtr,
              &ETHTSYN_SYNC_RECEIVE_SM_PTR(slavePortIdx)->Sync.IngressTimestamp, &followUpCorrectionFieldNs) == E_OK)
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
            {
              if(followUpCorrectionFieldNs >= 0)
              {
                uint64 unsignedFupCorrectionField = (uint64)followUpCorrectionFieldNs;
                EthTSyn_PdelayType pDelay = 0;
                /* Add the Path Delay 'of the Slave Port' to the Residence Time */
                /*
                    +----------+      Sync         +--------------------+ Sync
                    |  Master  +------------------>+S||    Bridge    ||M+--------->
                    +----------+t1               t2+--------------------+t3
      
                               +  Pdelay (t2-t1)   + Residence (t3-t2)  +
                               +<----------------->-<------------------>+
                               +                   +                    +
                */
                if(EthTSyn_GetCurrentPdelay(slavePortIdx, &pDelay) == E_OK)
                { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  unsignedFupCorrectionField += pDelay;
                }
                /* Add the former FollowUpCorrectionValue */
                /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
                unsignedFupCorrectionField +=
                    ETHTSYN_GET_FOLLOW_UP_CORRECTION_VALUE_NS_FROM_MSG(comHdrPtr->CorrectionField);
      
                /* Multiply FollwUpCorrectionField by 2^16 (as specified by IEEE802.1AS and copy it to the TxBuffer */
                EthTSyn_CopyFollowUpCorrectionField(unsignedFupCorrectionField, comHdrPtr->CorrectionField)
      
              }
            }
      
            syncSendSmPtr->FollowUpTxBufIdx = bufIdx;
            syncSendSmPtr->FollowUpTxBufPtr = u8BufPtr;
# if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
            mgmtInfo.FrameId = EthTSyn_GetFrameId(u8BufPtr, lenByte);
            syncSendSmPtr->FrameId = mgmtInfo.FrameId;

            CANOE_WRITE_STRING_2("[FRAME_ID_DEBUG] PortIdx: %d FrameId: %d (FollowUp_Forwarded)",
            masterPortIdx, mgmtInfo.FrameId);
# endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
            /* Set Switch management Info */
            mgmtInfo.SwitchIdx = EthTSyn_PortConfig[masterPortIdx].SwtInfo.SwitchIdx;
            mgmtInfo.PortIdx = EthTSyn_PortConfig[masterPortIdx].SwtInfo.PortIdx;
            /* Transmit */
            if(EthTSyn_Transmit(masterPortIdx, bufIdx, ETHTSYN_MSG_FOLLOW_UP_TX_LENGTH, TRUE, &mgmtInfo) != E_OK)
            {
            /* EthTSyn_SiteSyncSyncSm(TimeDomainIdx).TxConfirmationPending is set to the amount of configured
             * MasterPorts for the TimeDomain at the reception of a FollowUp message. Since this code part can only
             * be reached after the reception of a FollowUp message no underflow is possible */
              EthTSyn_SiteSyncSyncSm(TimeDomainIdx).TxConfirmationPending--;
              syncSendSmPtr->FollowUpTxBufIdx = ETHTSYN_INV_BUF_IDX;
              syncSendSmPtr->FollowUpTxBufPtr = NULL_PTR;
# if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
            syncSendSmPtr->FrameId = ETHTSYN_INVALID_FRAME_ID;
# endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
              /* Transmission failed */
              errorId = ETHTSYN_E_TX_FAILED;
            }
          }
        }
      }/* END: Iteration of MasterPorts */
    }
    break; /* END: ETHTSYN_STATE_SITE_SYNC_SYNC_SEND_FOLLOW_UP */

    case ETHTSYN_STATE_SITE_SYNC_SYNC_RECEIVED_FUP_AFTER_TIMEOUT:
      slavePortIdx = EthTSyn_SwtMgmt_GetSwitchSlavePortIdx(TimeDomainIdx);
      if(ETHTSYN_STATE_GET_SLAVE_PORT_IDX(TimeDomainIdx) != slavePortIdx)
      {
        /* Bridge acted as grand master after sync-timeout --> "enable" the slave port again and start 'normal'
         * bridge operation again */
        ETHTSYN_STATE_GET_SLAVE_PORT_IDX(TimeDomainIdx) = slavePortIdx; /* PRQA S 0310 */ /* MD_EthTSyn_11.4 */

        while(masterPortCnt > 0)
        {
          masterPortCnt--;
          /* ensure that no Sync/FollowUp cycle is ongoing */ /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
          if(ETHTSYN_SYNC_SEND_SM_PTR(EthTSyn_CfgGetMasterPortIdx(TimeDomainIdx, masterPortCnt))->State !=
            ETHTSYN_STATE_SYNC_SEND_SEND_FOLLOW_UP)
          {
            /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
            ETHTSYN_SYNC_SEND_SM_PTR(EthTSyn_CfgGetMasterPortIdx(TimeDomainIdx, masterPortCnt))->State =
              ETHTSYN_STATE_SYNC_SEND_SITE_SYNC_SYNC_PENDING;
          }
        }
      }
      break; /* END: ETHTSYN_STATE_SITE_SYNC_SYNC_RECEIVED_FUP_AFTER_TIMEOUT */

  default:
    /* nothing to do */
    break;
  }

# if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SID_SM_SITE_SYNC_SYNC, errorId);
  }
# else
  ETHTSYN_DUMMY_STATEMENT(errorId);
# endif /* (ETHTSYN_DEV_ERROR_REPORT == STD_ON) */
} /* EthTSyn_ProcessSmSitySyncSync() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: STCAL */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_RxIndication
 *********************************************************************************************************************/
/* PRQA S 6010 STPTH */ /* MD_MSR_STPTH */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6050 STCAL */ /* MD_MSR_STCAL */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_RxIndication(uint8 CtrlIdx, ETHTSYN_P2VAR(uint8) DataPtr, uint16 LenByte)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHTSYN_E_NO_ERROR;
  ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType) comMsgHdrPtr = NULL_PTR;
  ETHTSYN_P2VAR(EthTSyn_SwtMgmt_MsgBufferType) msgBufferPtr;
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_OFF)
  EthTSyn_GlobalTimestampType ingressTimestamp;
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_OFF) */

  EthTSyn_PortIdxType portCnt = ETHTSYN_PORT_COUNT;
  boolean foundPortForEthIfCtrl = FALSE;
  boolean readyToReceiveMsg = FALSE;
  EthTSyn_TimeDomainIdxType timeDomainIdx;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(EthTSyn_State == ETHTSYN_STATE_UNINIT)
  {
    errorId = ETHTSYN_E_NOT_INITIALIZED;
  }
  else if(DataPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else
# endif /* (ETHTSYN_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* check if at least one (Switch-)Port is assigned to the Ctrl */
    while(0u < portCnt)
    {
      portCnt--;
      if( (EthTSyn_GetPortType(portCnt) & ETHTSYN_PORT_TYPE_SWITCH_PORT) != 0 )
      {
        if(ETHTSYN_CFG_GET_ETH_IF_CTRL_IDX(portCnt) == CtrlIdx)
        {
          foundPortForEthIfCtrl = TRUE;
          break;
        }
      }
    }

    if(foundPortForEthIfCtrl == TRUE)
    {
      timeDomainIdx = ETHTSYN_INVALID_TIME_DOMAIN_IDX;
      /* At least one port is configured for the EthIf controller --> receive the message */

      /* Try to get a free message buffer */
      if(EthTSyn_SwtMgmt_ProvideMsgBuffer(&msgBufferPtr) == E_OK)
      {
        /* Message buffer available and locked */
        if(EthTSyn_CheckMessageGeneral((ETHTSYN_P2CONST(uint8))DataPtr, LenByte, &timeDomainIdx, &errorId) == E_OK)
        {
          /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
          comMsgHdrPtr = (ETHTSYN_P2CONST(EthTSyn_CommonMsgHdrType))&DataPtr[0];
          if(EthTSyn_CheckMessageTypeAndLength(comMsgHdrPtr, LenByte, &errorId) == E_OK)
          {
            /* Check TimeDomain */
            if(timeDomainIdx != ETHTSYN_INVALID_TIME_DOMAIN_IDX)
            {
              /* Ensure that message buffer is sufficient for the message */
              if(ETHTSYN_SWT_MGMT_MSG_BUFFER_PAYLOAD_SIZE >= (LenByte - ETHTSYN_HDR_COM_LENGTH))
              {
                readyToReceiveMsg = TRUE;
              }
              else
              {
                /* insufficient buffer --> drop message */
                errorId = ETHTSYN_SWT_MGMT_E_MSG_BUFFER_PAYLOAD_OVERFLOW;
              }
            }
          }
        }
      }
      else
      {
        /* No message buffer available --> drop message */
        errorId = ETHTSYN_SWT_MGMT_E_MSG_BUFFER_OVERFLOW;
      }

      if( (readyToReceiveMsg == TRUE) && (comMsgHdrPtr != NULL_PTR) )
      {
        /* Map message buffer to the EthIf Ctrl and Frame */
# if (ETHTSYN_FRAME_ID_SUPPORT == STD_ON)
        /* PRQA S 0310 1 */ /* MD_EthTSyn_11.4 */
        msgBufferPtr->SwtMgmtInfo.FrameId = EthTSyn_GetFrameId(DataPtr, LenByte);
# endif /* (ETHTSYN_FRAME_ID_SUPPORT == STD_ON) */
        msgBufferPtr->CtrlIdx = CtrlIdx;
        msgBufferPtr->RxBufAddr = DataPtr;

        /* Handle Timestamping */
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
        switch(ETHTSYN_HDR_COM_MSG_TYPE(comMsgHdrPtr->TransSpecific_MessageType))
        {
          case ETHTSYN_MSG_TYPE_SYNC:
            msgBufferPtr->IngressTimestampMgmt.TimestampState =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;
            msgBufferPtr->EgressTimestampHostPortMgmt.TimestampState =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;
            /* Get timestamp of Host Controlle if required */
#  if (ETHTSYN_END_STATION_SUPPORT == STD_ON)
            if(EthTSyn_SwtMgmt_GetEndStationSlavePortIdx(timeDomainIdx) != ETHTSYN_INVALID_PORT_IDX)
            {
              if(EthTSyn_SwtMgmt_GetIngressTimestamp(CtrlIdx, DataPtr,
                &msgBufferPtr->IngressTimestampHostCtrlMgmt.Timestamp) == E_OK)
              {
                msgBufferPtr->IngressTimestampHostCtrlMgmt.TimestampState =
                  ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
              }
              else
              {
                msgBufferPtr->IngressTimestampHostCtrlMgmt.TimestampState =
                  ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_NOT_AVAILABLE;
              }
            }
#  endif /* (ETHTSYN_END_STATION_SUPPORT == STD_ON) */
            break;
          case ETHTSYN_MSG_TYPE_PDELAY_RESP:
          case ETHTSYN_MSG_TYPE_PDELAY_REQ:
            msgBufferPtr->IngressTimestampMgmt.TimestampState =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_WAITING_FOR_TIMESTAMP;
            msgBufferPtr->EgressTimestampHostPortMgmt.TimestampState =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_NOT_REQUIRED;
            break;
          default:
            msgBufferPtr->IngressTimestampMgmt.TimestampState =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_NOT_REQUIRED;
            msgBufferPtr->EgressTimestampHostPortMgmt.TimestampState =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_NOT_REQUIRED;
            break;
        }
# else
        /* No Switch Timestamping */
        /* Get the Ingress Timestamp if necessary */
        switch(ETHTSYN_HDR_COM_MSG_TYPE(comMsgHdrPtr->TransSpecific_MessageType))
        {
          case ETHTSYN_MSG_TYPE_PDELAY_RESP:
          case ETHTSYN_MSG_TYPE_SYNC:
          case ETHTSYN_MSG_TYPE_PDELAY_REQ:
            if(EthTSyn_SwtMgmt_GetIngressTimestamp(CtrlIdx, DataPtr, &ingressTimestamp) == E_OK)
            {
              /* Successfully retrieved the IngressTimestamp --> Store it */
              EthTSyn_SwtMgmt_GetMsgBufferIngressTimestamp(msgBufferPtr) = ingressTimestamp;
              EthTSyn_SwtMgmt_GetMsgBufferIngressTimestampState(msgBufferPtr) =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_AVAILABLE;
            }
            else
            {
              /* Failed to retrieve the IngressTimestamp */
              errorId = ETHTSYN_E_GET_INGRESS_TIMESTAMP_FAILED;
              EthTSyn_SwtMgmt_GetMsgBufferIngressTimestampState(msgBufferPtr) =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_REQUIRED_NOT_AVAILABLE;
            }
            break;
          default:
            /* No Ingress Timestamp needed */
            EthTSyn_SwtMgmt_GetMsgBufferIngressTimestampState(msgBufferPtr) =
                ETHTSYN_TIMESTAMP_STATE_TIMESTAMP_NOT_REQUIRED_NOT_AVAILABLE;
            break;
        }
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

        /* Copy the received message to the message buffer for later processing */
        /* Copy the Message Header */
        /* PRQA S 0310 2 */ /* MD_EthTSyn_11.4 */
        IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))
            &msgBufferPtr->Msg.MsgHdr,
            (ETHTSYN_P2CONST(IpBase_CopyDataType))DataPtr, ETHTSYN_HDR_COM_LENGTH);

        /* Copy the Message (Payload) */
        /* PRQA S 0310 3 */ /* MD_EthTSyn_11.4 */
        IpBase_Copy((ETHTSYN_P2VAR(IpBase_CopyDataType))
            msgBufferPtr->Msg.Payload,
            (ETHTSYN_P2CONST(IpBase_CopyDataType))&DataPtr[ETHTSYN_HDR_COM_LENGTH],
            (EthTSyn_Ntohs(msgBufferPtr->Msg.MsgHdr.MessageLength) - ETHTSYN_HDR_COM_LENGTH));

        msgBufferPtr->MsgBufferState =
            ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_MSG_VALID;
      }
      else
      {
        /* Release the message buffer */
        if(msgBufferPtr != NULL_PTR)
        {
          EthTSyn_SwtMgmt_ReleaseMsgBuffer(msgBufferPtr);
        }
      }
    }
  }

  /* ----- Development Error Report ------------------------------------- */
# if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SWT_MGMT_SID_SWITCH_MGMT_RX_INDICATION,
      errorId);
  }
# else
  ETHTSYN_DUMMY_STATEMENT(errorId);
# endif /* ETHTSYN_DEV_ERROR_REPORT */
} /* EthTSyn_SwtMgmt_RxIndication() */
/* PRQA L: STPTH */
/* PRQA L: STCYC */
/* PRQA L: STCAL */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_SwitchMgmtInfoIndication
 *********************************************************************************************************************/
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
FUNC(void, ETHTSYN_CODE) EthTSyn_SwitchMgmtInfoIndication(uint8 CtrlIdx, ETHTSYN_P2CONST(uint8) DataPtr,
    ETHTSYN_P2CONST(EthSwt_MgmtInfoType) MgmtInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHTSYN_E_NO_ERROR;
  ETHTSYN_P2VAR(EthTSyn_SwtMgmt_MsgBufferType) msgBufferPtr = NULL_PTR;

  /* ----- Development Error Checks ------------------------------------- */
# if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(EthTSyn_State == ETHTSYN_STATE_UNINIT)
  {
    errorId = ETHTSYN_E_NOT_INITIALIZED;
  }
  else if(DataPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else if(MgmtInfoPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else
# endif /* ETHTSYN_DEV_ERROR_DETECT */
  {
    /* ----- Implementation --------------------------------------------- */
    if(EthTSyn_SwtMgmt_GetMappedMsgBuffer(
        CtrlIdx, DataPtr, ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MGMT_INFO(MgmtInfoPtr), &msgBufferPtr) == E_OK)
    {
      if(msgBufferPtr != NULL_PTR)
      {
        if( (MgmtInfoPtr->SwitchIdx == ETHTSYN_INVALID_ETHIF_SWITCH_IDX) ||
          (MgmtInfoPtr->PortIdx == ETHTSYN_INVALID_SWITCH_PORT_IDX) )
        {
          /* Release message buffer and drop message */
          EthTSyn_SwtMgmt_ReleaseMsgBuffer(msgBufferPtr);
        }
        else
        {
          /* Store switch management information in the message buffer */
          msgBufferPtr->SwtMgmtInfo.SwitchIdx = MgmtInfoPtr->SwitchIdx;
          msgBufferPtr->SwtMgmtInfo.PortIdx   = MgmtInfoPtr->PortIdx;

          /* Set message buffer state to processing */
          msgBufferPtr->MsgBufferState = ETHTSYN_SWT_MGMT_MSG_BUFFER_STATE_PORT_INFO_AVAILABLE;

          EthTSyn_SwtMgmt_ProcessMsgBuffer(msgBufferPtr);
        }
      }
    }
  }

  /* ----- Development Error Report ------------------------------------- */
# if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID, ETHTSYN_SWT_MGMT_SID_SWITCH_MGMT_INFO_INDICATION,
      errorId);
  }
# else
  ETHTSYN_DUMMY_STATEMENT(errorId);
# endif /* ETHTSYN_DEV_ERROR_REPORT */
} /* EthTSyn_SwitchMgmtInfoIndication() */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_SwitchEgressTimeStampIndication
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
FUNC(void, ETHTSYN_CODE) EthTSyn_SwitchEgressTimeStampIndication(uint8 CtrlIdx, ETHTSYN_P2CONST(uint8) DataPtr,
    ETHTSYN_P2CONST(EthSwt_MgmtInfoType) MgmtInfoPtr, ETHTSYN_P2CONST(Eth_TimeStampType) timeStampPtr)
{
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHTSYN_E_NO_ERROR;
  ETHTSYN_P2VAR(EthTSyn_SwtMgmt_MsgBufferType) msgBufferPtr = NULL_PTR;
  ETHTSYN_P2VAR(Eth_TimeStampType) egressTsPtr = NULL_PTR;
  ETHTSYN_P2VAR(EthTSyn_TimestampStateType) egressTsStatePtr = NULL_PTR;
  EthTSyn_SwtMgmt_StateMachineIndentificationType stateMachine = ETHTSYN_STATE_MACHINE_IDENTIFICATION_INVLID_SM;
  EthTSyn_PortIdxType portIdx = ETHTSYN_INVALID_PORT_IDX;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check input parameters */
#  if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(EthTSyn_State == ETHTSYN_STATE_UNINIT)
  {
    errorId = ETHTSYN_E_NOT_INITIALIZED;
  }
  else if(DataPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else if(MgmtInfoPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else
#  endif /* ETHTSYN_DEV_ERROR_DETECT */
  {
    /* ----- Implementation --------------------------------------------- */
    /* Check if the timestamp is given for Rx or Tx */
    if(EthTSyn_SwtMgmt_GetMappedMsgBuffer(
        CtrlIdx, DataPtr, ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MGMT_INFO(MgmtInfoPtr), &msgBufferPtr) == E_OK)
    {
      if(msgBufferPtr != NULL_PTR)
      {
        egressTsPtr = &msgBufferPtr->EgressTimestampHostPortMgmt.Timestamp;
        egressTsStatePtr = &msgBufferPtr->EgressTimestampHostPortMgmt.TimestampState;
      }
    }
    else
    {
      /* Try to get mapped state machine (Tx) */
      stateMachine = EthTSyn_SwtMgmt_GetMappedStateMachine(
          CtrlIdx, DataPtr, ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MGMT_INFO(MgmtInfoPtr), &portIdx);
      if(stateMachine != ETHTSYN_STATE_MACHINE_IDENTIFICATION_INVLID_SM)
      {
        (void)EthTSyn_SwtMgmt_GetStateMachineTxTimestampInfo(stateMachine, portIdx,
            ETHTSYN_SWT_MGMT_TIMESTAMP_DIRECTION_EGRESS, &egressTsPtr, &egressTsStatePtr);
      }
    }

    /* Check if either Rx or Tx message/state machine is available */
    if( (egressTsPtr != NULL_PTR) && (egressTsStatePtr != NULL_PTR) )
    {
      /* Check if egress timestamp is available */
      if(timeStampPtr == NULL_PTR)
      {
        /* If Timestamp is not available, mark TimeStamp as not available */
        *egressTsStatePtr |= ETHTSYN_TIMESTAMP_STATE_AVAILABLE_FLAG_VALID_MASK;
        *egressTsStatePtr &= (EthTSyn_TimestampStateType)~(ETHTSYN_TIMESTAMP_STATE_AVAILABLE_MASK);
      }
      else
      {
        /* Copy timestamp and mark it as available */
        *egressTsStatePtr |= (ETHTSYN_TIMESTAMP_STATE_AVAILABLE_FLAG_VALID_MASK |
                              ETHTSYN_TIMESTAMP_STATE_AVAILABLE_MASK);
        *egressTsPtr = *timeStampPtr;
      }
    }

    if(msgBufferPtr != NULL_PTR)
    {
      EthTSyn_SwtMgmt_ProcessMsgBuffer(msgBufferPtr);
    }
    else if( (stateMachine  != ETHTSYN_STATE_MACHINE_IDENTIFICATION_INVLID_SM) &&
             (portIdx       != ETHTSYN_INVALID_PORT_IDX)  )
    {
      /* For Tx only port specific state machines are relevant. Therefore the parameter 'TimeDomainIdx' is not required
       * and can be set to it's invalid value */
      EthTSyn_SwtMgmt_TriggerStateMachine(stateMachine, portIdx);
    }
    else
    {
      /* Nothing to do here (MISRA) */
    }
  }

  /* ----- Development Error Report ------------------------------------- */
#  if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID,
        ETHTSYN_SWT_MGMT_SID_SWITCH_EGRESS_TIMESTAMP_INDICATION, errorId);
  }
#  else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#  endif /* ETHTSYN_DEV_ERROR_REPORT */
# else
/*(ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_OFF) */
  /* PRQA S 3112 4 */ /* MD_MSR_14.2 */
  ETHTSYN_DUMMY_STATEMENT(CtrlIdx);
  ETHTSYN_DUMMY_STATEMENT(DataPtr);
  ETHTSYN_DUMMY_STATEMENT(MgmtInfoPtr);
  ETHTSYN_DUMMY_STATEMENT(timeStampPtr);
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
} /* EthTSyn_SwitchEgressTimeStampIndication() */
/* PRQA L: STCYC */
/* PRQA L: STMIF */

/**********************************************************************************************************************
 *  EthTSyn_SwitchIngressTimeStampIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 STCYC */ /* MD_MSR_STCYC */
/* PRQA S 6080 STMIF */ /* MD_MSR_STMIF */
FUNC(void, ETHTSYN_CODE) EthTSyn_SwitchIngressTimeStampIndication(uint8 CtrlIdx, ETHTSYN_P2CONST(uint8) DataPtr,
    ETHTSYN_P2CONST(EthSwt_MgmtInfoType) MgmtInfoPtr, ETHTSYN_P2CONST(Eth_TimeStampType) timeStampPtr)
{
# if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHTSYN_E_NO_ERROR;
  ETHTSYN_P2VAR(EthTSyn_SwtMgmt_MsgBufferType) msgBufferPtr = NULL_PTR;
  ETHTSYN_P2VAR(Eth_TimeStampType) ingressTsPtr = NULL_PTR;
  ETHTSYN_P2VAR(EthTSyn_TimestampStateType) ingressTsStatePtr = NULL_PTR;
  EthTSyn_SwtMgmt_StateMachineIndentificationType stateMachine = ETHTSYN_STATE_MACHINE_IDENTIFICATION_INVLID_SM;
  EthTSyn_PortIdxType portIdx = ETHTSYN_INVALID_PORT_IDX;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check input parameters */
#  if (ETHTSYN_DEV_ERROR_DETECT == STD_ON)
  if(EthTSyn_State == ETHTSYN_STATE_UNINIT)
  {
    errorId = ETHTSYN_E_NOT_INITIALIZED;
  }
  else if(DataPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else if(MgmtInfoPtr == NULL_PTR)
  {
    errorId = ETHTSYN_E_PARAM_POINTER;
  }
  else
#  endif /* ETHTSYN_DEV_ERROR_DETECT */
  {
    /* ----- Implementation --------------------------------------------- */
    /* Check if the timestamp is given for Rx or Tx */
    if(EthTSyn_SwtMgmt_GetMappedMsgBuffer(
        CtrlIdx, DataPtr, ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MGMT_INFO(MgmtInfoPtr), &msgBufferPtr) == E_OK)
    {
      if(msgBufferPtr != NULL_PTR)
      {
        ingressTsPtr = &msgBufferPtr->IngressTimestampMgmt.Timestamp;
        ingressTsStatePtr = &msgBufferPtr->IngressTimestampMgmt.TimestampState;
      }
    }
    else
    {
      /* Initialize message buffer ptr */
      msgBufferPtr = NULL_PTR;
      /* Try to get mapped state machine (Tx) */
      stateMachine = EthTSyn_SwtMgmt_GetMappedStateMachine(
          CtrlIdx, DataPtr, ETHTSYN_SWT_MGMT_FRAME_ID_FROM_MGMT_INFO(MgmtInfoPtr), &portIdx);
      if(stateMachine != ETHTSYN_STATE_MACHINE_IDENTIFICATION_INVLID_SM)
      {
        (void)EthTSyn_SwtMgmt_GetStateMachineTxTimestampInfo(stateMachine, portIdx,
            ETHTSYN_SWT_MGMT_TIMESTAMP_DIRECTION_INGRESS, &ingressTsPtr, &ingressTsStatePtr);
      }
    }

    /* Check if either Rx or Tx message/state machine is available */
    if( (ingressTsPtr != NULL_PTR) && (ingressTsStatePtr != NULL_PTR) )
    {
      /* Check if egress timestamp is available */
      if(timeStampPtr == NULL_PTR)
      {
        /* If Timestamp is not available, mark TimeStamp as not available */
        *ingressTsStatePtr |= ETHTSYN_TIMESTAMP_STATE_AVAILABLE_FLAG_VALID_MASK;
        *ingressTsStatePtr &= (EthTSyn_TimestampStateType)~(ETHTSYN_TIMESTAMP_STATE_AVAILABLE_MASK);
      }
      else
      {
        /* Copy timestamp and mark it as available */
        *ingressTsStatePtr |= (ETHTSYN_TIMESTAMP_STATE_AVAILABLE_FLAG_VALID_MASK |
                               ETHTSYN_TIMESTAMP_STATE_AVAILABLE_MASK);
        *ingressTsPtr = *timeStampPtr;
      }
    }

    if(msgBufferPtr != NULL_PTR)
    {
      EthTSyn_SwtMgmt_ProcessMsgBuffer(msgBufferPtr);
    }
    else if( (stateMachine  != ETHTSYN_STATE_MACHINE_IDENTIFICATION_INVLID_SM) &&
             (portIdx       != ETHTSYN_INVALID_PORT_IDX)  )
    {
      /* For Tx only port specific state machines are relevant. Therefore the parameter 'TimeDomainIdx' is not required
       * and can be set to it's invalid value */
      EthTSyn_SwtMgmt_TriggerStateMachine(stateMachine, portIdx);
    }
    else
    {
      /* Nothing to do here (MISRA) */
    }
  }

  /* ----- Development Error Report ------------------------------------- */
#  if (ETHTSYN_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ETHTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTSYN_MODULE_ID, ETHTSYN_INSTANCE_ID,
      ETHTSYN_SWT_MGMT_SID_SWITCH_INGRESS_TIMESTAMP_INDICATION, errorId);
  }
#  else
  ETHTSYN_DUMMY_STATEMENT(errorId);
#  endif /* ETHTSYN_DEV_ERROR_REPORT */
# else
  /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_OFF) */
  /* PRQA S 3112 4 */ /* MD_MSR_14.2 */
  ETHTSYN_DUMMY_STATEMENT(CtrlIdx);
  ETHTSYN_DUMMY_STATEMENT(DataPtr);
  ETHTSYN_DUMMY_STATEMENT(MgmtInfoPtr);
  ETHTSYN_DUMMY_STATEMENT(timeStampPtr);
# endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */
} /* EthTSyn_SwitchIngressTimeStampIndication() */
/* PRQA L: STCYC */
/* PRQA L: STMIF */
#define ETHTSYN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* ETHTSYN_SWT_MGMT_SUPPORT */

/* Justification for module-specific MISRA deviations:
 * see file EthTSyn.c
*/

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_SwtMgmt.c
 *********************************************************************************************************************/
