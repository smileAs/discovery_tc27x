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
 *         \file  EthTSyn_SwtMgmt_Priv.h
 *        \brief  EthTSyn Switch Management private header file
 *
 *      \details  Contains private definitions and declarations used by EthTSyn (for Switch Management) only
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

#if !defined(ETHTSYN_SWT_MGMT_PRIV_H)
# define ETHTSYN_SWT_MGMT_PRIV_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "EthTSyn_Types.h"

# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ----- API service IDs ----- */
/* AR */
/*!< Service ID: EthTSyn_SwitchMgmtInfoIndication() */
#  define ETHTSYN_SWT_MGMT_SID_SWITCH_MGMT_INFO_INDICATION          (0x0Au)
/*!< Service ID: EthTSyn_SwitchIngressTimeStampIndication() */
#  define ETHTSYN_SWT_MGMT_SID_SWITCH_INGRESS_TIMESTAMP_INDICATION  (0x0Bu)
/*!< Service ID: EthTSyn_SwitchEgressTimeStampIndication() */
#  define ETHTSYN_SWT_MGMT_SID_SWITCH_EGRESS_TIMESTAMP_INDICATION   (0x0Cu)

/* Non-AR */
/*!< Service ID: EthTSyn_SwtMgmt_RxIndication() */
#  define ETHTSYN_SWT_MGMT_SID_SWITCH_MGMT_RX_INDICATION            (0x70u)
/*!< Service ID: EthTSyn_SwtMgmt_ProcessMsgBuffer() */
#  define ETHTSYN_SWT_MGMT_SID_PROCESS_MSG_BUFFER                   (0x71u)

/* ----- Error codes ----- */
/*!< Error Code: No free message buffer available */
#  define ETHTSYN_SWT_MGMT_E_MSG_BUFFER_OVERFLOW                    (0x40u)
/*!< Error Code: Payload to big for the message buffer */
#  define ETHTSYN_SWT_MGMT_E_MSG_BUFFER_PAYLOAD_OVERFLOW            (0x41u)
/*!< Error Code: EthTSyn_SwitchInfoIndication called with no buffered message available */
#  define ETHTSYN_SWT_MGMT_E_NO_MSG_AVAILABLE                       (0x42u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* State Machine access Macros */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#  define EthTSyn_SiteSyncSyncSm(TimeDomainIdx) (EthTSyn_TimeDomainState[(TimeDomainIdx)].SiteSyncSyncSm)

/* TimeDomain State access macros */
/* PRQA S 3453 2 */ /* MD_MSR_19.7 */
#  define EthTSyn_SwtMgmt_SwtRateRatioMgmt(TimeDomainIdx) (EthTSyn_SiteSyncSyncSm((TimeDomainIdx)).RateRatioMgmt)
#  define EthTSyn_SwtMgmt_GetSwtRateRatio(TimeDomainIdx)  (EthTSyn_SwtMgmt_SwtRateRatioMgmt((TimeDomainIdx)).RateRatio)

/* Config access macros */
/* PRQA S 3453 3 */ /* MD_MSR_19.7 */
#  define EthTSyn_SwtMgmt_CfgGetSwitchInfo(PortIdxParam)          (EthTSyn_PortConfig[(PortIdxParam)].SwtInfo)
#  define EthTSyn_SwtMgmt_CfgGetSwitchIdx(PortIdxParam)           (EthTSyn_PortConfig[(PortIdxParam)].SwtInfo.SwitchIdx)
#  define EthTSyn_SwtMgmt_CfgGetSwitchPortIdx(PortIdxParam)       (EthTSyn_PortConfig[(PortIdxParam)].SwtInfo.PortIdx)

/* Message buffer access macros */
/* PRQA S 3453 4 */ /* MD_MSR_19.7 */
#  define EthTSyn_SwtMgmt_GetMsgBufferIngressTimestamp(MsgBufferPtr) \
  ((MsgBufferPtr)->IngressTimestampMgmt.Timestamp)
#  define EthTSyn_SwtMgmt_GetMsgBufferIngressTimestampState(MsgBufferPtr) \
  ((MsgBufferPtr)->IngressTimestampMgmt.TimestampState)

#  if (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON)
/* PRQA S 3453 4 */ /* MD_MSR_19.7 */
#   define EthTSyn_SwtMgmt_GetMsgBufferEgressTimestampHostPort(MsgBufferPtr) \
  ((MsgBufferPtr)->EgressTimestampHostPortMgmt.Timestamp)
#   define EthTSyn_SwtMgmt_GetMsgBufferEgressTimestampStateHostPort(MsgBufferPtr) \
  ((MsgBufferPtr)->EgressTimestampHostPortMgmt.TimestampState)
#  else
/* PRQA S 3453 2 */ /* MD_MSR_19.7 */
#   define EthTSyn_SwtMgmt_GetMsgBufferIngressTimestampRaw(MsgBufferPtr) \
  ((MsgBufferPtr)->IngressTimestampRaw)
#  endif /* (ETHTSYN_SWT_MGMT_SWT_TIMESTAMP_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#  define ETHTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define ETHTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#  define ETHTSYN_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_Init
 *********************************************************************************************************************/
/*! \brief        Initialization of the EthTSyn switch management parts
 *  \param        none
 *  \return       none
 *  \note         This function must be called before using the module
 *  \pre          The function EthTSyn_InitMemory() must be called first
 *  \context      This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_Init(void);

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_ProcessSmSiteSyncSync
 *********************************************************************************************************************/
/*! \brief      Processing of the Site Sync Sync state-machine
 *  \param[in]  TimeDomainIdx    Index of the TimeDomain that should be processed
 *  \return     none
 *  \context    This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_ProcessSmSiteSyncSync(
  EthTSyn_TimeDomainIdxType TimeDomainIdx);

/**********************************************************************************************************************
 *  EthTSyn_SwtMgmt_RxIndication
 *********************************************************************************************************************/
/*! \brief        Processing of received EthTSyn frames on an EthTSyn Bridge Port.
 *  \description  By this API service the EthTSyn Switch management gets an indication and the data of a received frame.
 *                The Service is called by the main RxIndication of the EthTSyn module
 *  \param[in]    CtrlIdx            Index of the Ethernet controller
 *  \param[in]    DataPtr            Pointer to payload of the received Ethernet frame
 *                                   (i.e. Ethernet header is not provided)
 *  \param[in]    LenByte            Length of received data
 *  \return       none
 *  \pre          The function EthTSyn_Init() must be called first
 *  \note         This RxIndication function is wrapped by the main EthTSyn_RxIndication. Thats why the parameters
 *                differ from a the regular RxIndication
 *  \context      This function can be called in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_SwtMgmt_RxIndication(
                uint8   CtrlIdx,
  ETHTSYN_P2VAR(uint8)  DataPtr,
                uint16  LenByte);

#  define ETHTSYN_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# endif /* (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON) */
#endif /* ETHTSYN_SWT_MGMT_PRIV_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_SwtMgmt_Priv.h
 *********************************************************************************************************************/
