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
/**        \file
 *        \brief  Vector AUTOSAR CanTSyn code file
 *
 *      \details  This is the main implementation file of the Vector AUTOSAR module CanTSyn.
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

#define CANTSYN_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "CanTSyn.h"
#include "CanTSyn_Cbk.h"
#include "SchM_CanTSyn.h"
#include "StbM.h"
#if (CANTSYN_MASTER_COUNT)
# include "CanIf.h"
#endif
#if (CANTSYN_CRC_USED)
# include "Crc.h"
#endif
#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of CanTSyn header file */
#if (  (CANTSYN_SW_MAJOR_VERSION != (2U)) \
    || (CANTSYN_SW_MINOR_VERSION != (1U)) \
    || (CANTSYN_SW_PATCH_VERSION != (1U)) )
# error "Vendor specific version numbers of CanTSyn.c and CanTSyn.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (CANTSYN_CFG_MAJOR_VERSION != (2U)) \
    || (CANTSYN_CFG_MINOR_VERSION != (1U)) )
# error "Version numbers of CanTSyn.c and CanTSyn_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CANTSYN_INV_DOMAIN_IDX                             (255U)
#define CANTSYN_MAX_SEQUENCE_COUNTER                       (15U)
#define CANTSYN_START_OFFSET_TIME_DOMAIN_ID                (16U)

#define CANTSYN_TIME_SYNC_MESSAGE_DLC                      (8U)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_NOT_CRC        (0x10U)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC            (0x20U)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_NOT_CRC         (0x18U)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC             (0x28U)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_NOT_CRC         (0x30U)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC             (0x40U)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_NOT_CRC        (0x38U)
#define CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC            (0x48U)

#define CANTSYN_CRC_START_VALUE                            (0xFFU)

#define CANTSYN_TIMESTAMP_MAX_NANOSECONDS                  (999999999UL) /* 10^9 nanoseconds per second */
#define CANTSYN_TIMESTAMP_MAX_SECONDS                      (4294967295UL)
#define CANTSYN_TIMESTAMP_MAX_SECONDSHI                    (65535U)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#define DUMMY_STATEMENT(x)                                 (x)=(x) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define CanTSyn_DomainHasSlave(index)                      (CanTSyn_DomainConfig[(index)].SlaveIdx != CANTSYN_NO_SLAVE_IDX) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_DomainHasMaster(index)                     (CanTSyn_DomainConfig[(index)].MasterCount != 0) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define CanTSyn_GetGlobalTimeBaseBit(status)               ((status) & StbM_Global_Time_Base_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_GetSyncToGatewayBit(status)                ((status) & StbM_Sync_To_Gateway_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define CanTSyn_IsSyncMsg(type)                            (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_NOT_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_IsFupMsg(type)                             (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_NOT_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_IsOfsMsg(type)                             (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_NOT_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_IsOfnsMsg(type)                            (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_NOT_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define CanTSyn_IsSyncCrcSecured(type)                     (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_IsFupCrcSecured(type)                      (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get Message type (Multiplexer value) */
#define CanTSyn_CanSignal_GetType(msg)                     ((msg)[0U]) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get CRC */
#define CanTSyn_CanSignal_GetCRC(crcMsg)                   ((crcMsg)[1U]) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get Sequence counter */
#define CanTSyn_CanSignal_GetSC(msg)                       ((msg)[2U] & 0x0FU) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get Time Domain */
#define CanTSyn_CanSignal_GetD(msg)                        ((msg)[2U] >> 4U) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get the time value (seconds from SYNC/OFS message or nanoseconds from FUP/OFNS message) */
#define CanTSyn_CanSignal_GetTime(msg)                     (((uint32) (msg)[7U])         | \
                                                            ((uint32) (msg)[6U] <<  8U)  | \
                                                            ((uint32) (msg)[5U] <<  16U) | \
                                                            ((uint32) (msg)[4U] <<  24U)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get OVS from FUP message */
#define CanTSyn_CanSignal_GetOVS(fupMsg)                   ((fupMsg)[3U] & 0x03U) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get SGW from FUP message */
#define CanTSyn_CanSignal_GetSGW(fupMsg)                   ((uint8)(((fupMsg)[3U] & 0x04U) >> 2U)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get User bytes (SYNC: Byte 0 and 1; FUP: Byte 2; Byte 1 and 2 only valid for not CRC secured messages) */
#define CanTSyn_CanSignal_GetUserByte0(syncMsg)            ((syncMsg)[3U]) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_CanSignal_GetUserByte1(syncMsg)            ((syncMsg)[1U]) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_CanSignal_GetUserByte2(fupMsg)             ((fupMsg)[1U]) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get secondsHi from OFS/OFNS message */
#define CanTSyn_CanSignal_GetSecHi(ofsMsg)                 ((ofsMsg)[3U]) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Set Message type (Multiplexer value) */
#define CanTSyn_CanSignal_SetType(msg, value)              (msg)[0U] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Set CRC */
#define CanTSyn_CanSignal_SetCRC(crcMsg, value)            (crcMsg)[1U] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Set Sequence counter */
#define CanTSyn_CanSignal_SetSC(msg, value)                (msg)[2U] = (uint8) (((msg)[2U] & 0xF0U) | ((value) & 0x0FU)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Set Time Domain */
#define CanTSyn_CanSignal_SetD(msg, value)                 (msg)[2U] = (uint8) (((msg)[2U] & 0x0FU) | ((value) << 4U)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Get the time value (seconds from SYNC/OFS message or nanoseconds from FUP/OFNS message) */
#define CanTSyn_CanSignal_SetTime(msg, value)              {(msg)[7U] = (uint8) (value);          \
                                                            (msg)[6U] = (uint8) ((value) >>  8U); \
                                                            (msg)[5U] = (uint8) ((value) >> 16U); \
                                                            (msg)[4U] = (uint8) ((value) >> 24U);} /* PRQA S 3458 */ /* MD_MSR_19.4 */

/* Set OVS from FUP message */
#define CanTSyn_CanSignal_SetOVS(fupMsg, value)            (fupMsg)[3U] = (uint8) (((fupMsg)[3U] & 0xFCU) | ((value) & 0x03U)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Set SGW from FUP message */
#define CanTSyn_CanSignal_SetSGW(fupMsg, value)            (fupMsg)[3U] = (uint8) (((fupMsg)[3U] & 0xFBU) | (((value) & 0x01U) << 2U)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Set reserved bits from FUP message */
#define CanTSyn_CanSignal_SetReservedFup(fupMsg, value)    (fupMsg)[3U] = (uint8) (((fupMsg)[3U] & 0x07U) | ((value) << 3U)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Set User bytes (SYNC: Byte 0 and 1; FUP: Byte 2; Byte 1 and 2 only valid for not CRC secured messages) */
#define CanTSyn_CanSignal_SetUserByte0(syncMsg, value)     (syncMsg)[3U] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_CanSignal_SetUserByte1(syncMsg, value)     (syncMsg)[1U] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define CanTSyn_CanSignal_SetUserByte2(fupMsg, value)      (fupMsg)[1U] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Set secondsHi from OFS/OFNS message */
#define CanTSyn_CanSignal_SetSecHi(ofsMsg, value)          (ofsMsg)[3U] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Set reserved byte from OFS/OFNS message */
#define CanTSyn_CanSignal_SetReservedOfs(ofsMsg, value)    (ofsMsg)[1U] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* StbM AUTOSAR version check */
#define CANTSYN_STBM_AR_VERSION_EQUALS(Major,Minor,Patch) \
  ((CANTSYN_STBM_AR_MAJOR_VERSION == (Major))\
  && (CANTSYN_STBM_AR_MINOR_VERSION == (Minor))\
  && (CANTSYN_STBM_AR_PATCH_VERSION == (Patch))) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Macros for StbM_TimeStampRawType accesses */
#if CANTSYN_STBM_AR_VERSION_EQUALS(4,2,1)
# define CANTSYN_STBM_TIMESTAMP_RAW_NANOSECONDS(StbMTimestampRaw)         ((StbMTimestampRaw).nanoseconds) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define CANTSYN_STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(StbMTimestampRawPtr)  ((StbMTimestampRawPtr)->nanoseconds) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
# define CANTSYN_STBM_TIMESTAMP_RAW_NANOSECONDS(StbMTimestampRaw)         (StbMTimestampRaw) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define CANTSYN_STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(StbMTimestampRawPtr)  (*(StbMTimestampRawPtr)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Preprocessor define STATIC is no longer available in Compiler.h in MSR4 - provide local define */
#if !defined (STATIC)
# define STATIC static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define CANTSYN_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Initialization state of the module */
#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
STATIC VAR(uint8, CANTSYN_VAR_ZERO_INIT) CanTSyn_ModuleInitialized = CANTSYN_UNINIT; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#endif

#define CANTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define CANTSYN_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (CANTSYN_MASTER_COUNT)
/*! Transmit state of the module */
STATIC VAR(CanTSyn_StateMachineStateType, CANTSYN_VAR_NOINIT) CanTSyn_TransmitState; /* PRQA S 0850 */ /* MD_MSR_19.8 */

/*! Transmission state of CanControllers */
STATIC VAR(CanTSyn_TransmissionModeType, CANTSYN_VAR_NOINIT) CanTSyn_CanControllerTransmissionState[CANTSYN_CANCONTROLLER_COUNT]; /* PRQA S 0850 */ /* MD_MSR_19.8 */

/*! Sequence counter for Tx messages */
STATIC VAR(uint8, CANTSYN_VAR_NOINIT) CanTSyn_TxSequenceCounter[CANTSYN_MASTER_COUNT]; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#endif

#if (CANTSYN_SLAVE_COUNT)
/*! Received sequence counter for Rx messages */
STATIC VAR(uint8, CANTSYN_VAR_NOINIT) CanTSyn_RxSequenceCounter[CANTSYN_SLAVE_COUNT]; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#endif

#define CANTSYN_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define CANTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (CANTSYN_SLAVE_COUNT)
/*! State of slaves */
STATIC VAR(CanTSyn_SlaveType, CANTSYN_VAR_NOINIT) CanTSyn_SlaveState[CANTSYN_SLAVE_COUNT]; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#endif

#if (CANTSYN_MASTER_COUNT)
/*! State of masters */
STATIC VAR(CanTSyn_MasterType, CANTSYN_VAR_NOINIT) CanTSyn_MasterState[CANTSYN_MASTER_COUNT]; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#endif

#define CANTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CANTSYN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  CanTSyn_ProcessReceive()
 *********************************************************************************************************************/
/*! \brief      Receive processing
 *  \details    This function handles the processing of receive.
 *  \param[in]  slaveIdx          Index of the Slave that receive handling should be processed.
 *********************************************************************************************************************/
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_ProcessReceive(uint8 slaveIdx); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_HandleSync()
 *********************************************************************************************************************/
/*! \brief      Processing of received sync messages
 *  \details    This function handles the processing of received sync messages.
 *  \param[in]  domainIdx         Index of the Domain that received sync message should be handled.
 *  \param[in]  pduInfoPtr        Pointer to the PDU that contains the received sync message.
 *********************************************************************************************************************/
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_HandleSync(
  uint8 domainIdx,
  P2CONST(PduInfoType, AUTOMATIC, CANTSYN_APPL_DATA) pduInfoPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_HandleFup()
 *********************************************************************************************************************/
/*! \brief      Processing of received fup messages
 *  \details    This function handles the processing of received fup messages.
 *  \param[in]  domainIdx         Index of the Domain that received fup message should be handled.
 *  \param[in]  pduInfoPtr        Pointer to the PDU that contains the received fup message.
 *********************************************************************************************************************/
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_HandleFup(
  uint8 domainIdx,
  P2CONST(PduInfoType, AUTOMATIC, CANTSYN_APPL_DATA) pduInfoPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_CheckRxSequenceCounter()
 *********************************************************************************************************************/
/*! \brief      Check received sequence counter
 *  \details    This function checks if the received sequence counter is valid.
 *  \param[in]  domainIdx         Index of the domain of the received message.
 *  \param[in]  counter           Received counter value.
 *  \return     E_OK - Received sequence counter is valid
 *  \return     E_NOT_OK - Received sequence counter is invalid
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_CheckRxSequenceCounter(
  uint8 domainIdx,
  uint8 counter); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_MemCpy()
 *********************************************************************************************************************/
/*! \brief      Copy data from one buffer to another
 *  \details    This function copies data from the source data buffer to the destination data buffer.
 *  \param[in]  destination       Pointer to the destination data buffer.
 *  \param[in]  source            Pointer to the source data buffer.
 *  \param[in]  count             Number of elements to copy.
 *********************************************************************************************************************/
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_MemCpy(
  P2VAR(uint8, AUTOMATIC, CANTSYN_APPL_VAR) destination,
  P2CONST(uint8, AUTOMATIC, CANTSYN_APPL_DATA) source,
  uint8 count); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_ProcessSend()
 *********************************************************************************************************************/
/*! \brief      Send processing
 *  \details    This function handles the processing of send.
 *  \param[in]  masterIdx         Index of the master that send state-machine should be processed.
 *********************************************************************************************************************/
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_ProcessSend(uint8 masterIdx); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_TransmitSync()
 *********************************************************************************************************************/
/*! \brief      Transmit sync messages
 *  \details    This function handles the transmitting of sync messages.
 *  \param[in]  masterIdx         Index of the master that sync message should be transmitted.
 *  \return     E_OK - Message transmission was successful
 *  \return     E_NOT_OK - Message transmission was not successful
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_TransmitSync(uint8 masterIdx); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_TransmitFup()
 *********************************************************************************************************************/
/*! \brief      Transmit fup messages
 *  \details    This function handles the transmitting of fup messages.
 *  \param[in]  masterIdx         Index of the master that fup message should be transmitted.
 *  \return     E_OK - Message transmission was successful
 *  \return     E_NOT_OK - Message transmission was not successful
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_TransmitFup(uint8 masterIdx); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_IncrementSequenceCounter()
 *********************************************************************************************************************/
/*! \brief      Increment sequence counter
 *  \details    This function increments the sequence counter.
 *  \param[in]  masterIdx         Index of the master of the transmitted message.
 *********************************************************************************************************************/
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_IncrementSequenceCounter(uint8 masterIdx); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_InitDomain()
 *********************************************************************************************************************/
/*! \brief      Initialization of CanTSyn Domain
 *  \details    This function initializes a CanTSyn Domain.
 *  \param[in]  domainIdx         Index of Domain that should be initialized.
 *********************************************************************************************************************/
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_InitDomain(uint8 domainIdx); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  CanTSyn_TimestampPlusTimestampRaw()
 *********************************************************************************************************************/
/*! \brief      Add timestamp and timestamp in raw format
 *  \details    This function calculates the sum of one timestamp and one timestamp in raw format.
 *  \param[in]  timestampPtr      Pointer to timestamp.
 *  \param[in]  timestampRawPtr   Pointer to timestamp in raw format.
 *  \param[out] timesumPtr        Pointer to timestamp with sum of timestamp and timestampRaw.
 *  \return     E_OK - Timesum is valid
 *  \return     E_NOT_OK - Timesum is invalid
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_TimestampPlusTimestampRaw(
  P2CONST(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_DATA) timestampPtr,
  P2CONST(StbM_TimeStampRawType, AUTOMATIC, CANTSYN_APPL_DATA) timestampRawPtr,
  P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timesumPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (CANTSYN_SLAVE_COUNT)
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_ProcessReceive(uint8 slaveIdx) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Implementation ----------------------------------------------- */
  switch (CanTSyn_SlaveState[slaveIdx].State)
  {
    case CANTSYN_STATE_RECEIVE_WAITING_FOR_FOLLOW_UP:
      /* check for FollowUp received timeout */
      SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      if (CanTSyn_SlaveState[slaveIdx].RxFollowUpTimeoutCount == 0U)
      {
        CanTSyn_SlaveState[slaveIdx].State = CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC;
      }
      SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      break;
    default:
      ;
  }

} /* CanTSyn_ProcessReceive() */

STATIC FUNC(void, CANTSYN_CODE) CanTSyn_HandleSync(
  uint8 domainIdx,
  P2CONST(PduInfoType, AUTOMATIC, CANTSYN_APPL_DATA) pduInfoPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 slaveIdx;
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  slaveIdx = CanTSyn_DomainConfig[domainIdx].SlaveIdx;

  if (CanTSyn_DomainConfig[domainIdx].DomainId < CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
  {
    /* on SYNC message Rx indication retrieve Local Time Stamp as T2raw */
    retVal = StbM_GetCurrentTimeRaw(&CanTSyn_SlaveState[slaveIdx].SyncTimestampRaw);
  }

  if (retVal == E_OK)
  {
    SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* get Synchronized Time Base part T0 delivered with SYNC message */
    CanTSyn_MemCpy(CanTSyn_SlaveState[slaveIdx].SyncMsg, pduInfoPtr->SduDataPtr, CANTSYN_TIME_SYNC_MESSAGE_DLC);

    CanTSyn_SlaveState[slaveIdx].State = CANTSYN_STATE_RECEIVE_WAITING_FOR_FOLLOW_UP;

    /* set FollowUp receive timeout time */
    CanTSyn_SlaveState[slaveIdx].RxFollowUpTimeoutCount = CanTSyn_DomainConfig[domainIdx].FollowUpTimeout; /* PRQA S 3689 */ /* MD_CanTSyn_3689 */

    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

} /* CanTSyn_HandleSync() */

STATIC FUNC(void, CANTSYN_CODE) CanTSyn_HandleFup(
  uint8 domainIdx,
  P2CONST(PduInfoType, AUTOMATIC, CANTSYN_APPL_DATA) pduInfoPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 slaveIdx, messageType;
  uint32 syncSeconds;
  StbM_TimeStampType syncTime, actualTime;
  StbM_TimeStampRawType fupTimestampRaw;
  StbM_UserDataType userData;

  /* ----- Implementation ----------------------------------------------- */
  slaveIdx = CanTSyn_DomainConfig[domainIdx].SlaveIdx;

  SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  messageType = CanTSyn_CanSignal_GetType(pduInfoPtr->SduDataPtr);

  if (CanTSyn_DomainConfig[domainIdx].DomainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
  {
    /* assemble second portion of the offset time base */
    actualTime.secondsHi = CanTSyn_CanSignal_GetSecHi(CanTSyn_SlaveState[slaveIdx].SyncMsg) + ((uint16)CanTSyn_CanSignal_GetSecHi(pduInfoPtr->SduDataPtr) << 8U);
    actualTime.seconds = CanTSyn_CanSignal_GetTime(CanTSyn_SlaveState[slaveIdx].SyncMsg);
    /* get nanosecond portion of the offset time */
    actualTime.nanoseconds = CanTSyn_CanSignal_GetTime(pduInfoPtr->SduDataPtr);
    (void)StbM_SetOffset(CanTSyn_DomainConfig[domainIdx].TimeBaseId, &actualTime); /* PRQA S 3685 */ /* MD_CanTSyn_3685 */
    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  else
  {
    userData.userByte0 = CanTSyn_CanSignal_GetUserByte0(CanTSyn_SlaveState[slaveIdx].SyncMsg);

    if (CanTSyn_IsFupCrcSecured(messageType))
    {
      userData.userDataLength = 1U;
    }
    else
    {
      /* user bytes 1 and 2 are only used if the message is not crc secured */
      userData.userByte1 = CanTSyn_CanSignal_GetUserByte1(CanTSyn_SlaveState[slaveIdx].SyncMsg);
      userData.userByte2 = CanTSyn_CanSignal_GetUserByte2(pduInfoPtr->SduDataPtr);
      userData.userDataLength = 3U;
    }

    /* calculate T0 + T4 */
    syncSeconds = CanTSyn_CanSignal_GetTime(CanTSyn_SlaveState[slaveIdx].SyncMsg);
    syncTime.seconds = syncSeconds + CanTSyn_CanSignal_GetOVS(pduInfoPtr->SduDataPtr);
    if (syncTime.seconds < syncSeconds)
    {
      syncTime.secondsHi = 1U;
    }
    else
    {
      syncTime.secondsHi = 0U;
    }

    /* get Synchronized Time Base part T4 delivered with FUP message */
    syncTime.nanoseconds = CanTSyn_CanSignal_GetTime(pduInfoPtr->SduDataPtr);

    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* retrieve time difference between T3raw and T2raw */
    if (StbM_GetCurrentTimeDiff(CanTSyn_SlaveState[slaveIdx].SyncTimestampRaw, &fupTimestampRaw) == E_OK)
    {
      /* calculate GlobalTimeBase as GlobalTimeBase = (T3raw - T2raw) + (T0 + T4) */
      if (CanTSyn_TimestampPlusTimestampRaw(&syncTime, &fupTimestampRaw, &actualTime) == E_OK)
      {
        (void)StbM_BusSetGlobalTime(CanTSyn_DomainConfig[domainIdx].TimeBaseId, &actualTime, &userData, CanTSyn_CanSignal_GetSGW(pduInfoPtr->SduDataPtr));
      }
    }
  }

  CanTSyn_SlaveState[slaveIdx].State = CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC;

} /* CanTSyn_HandleFup() */

STATIC FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_CheckRxSequenceCounter(
  uint8 domainIdx,
  uint8 counter) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 slaveIdx, counterJumpWidth;

  /* ----- Implementation ----------------------------------------------- */
  slaveIdx = CanTSyn_DomainConfig[domainIdx].SlaveIdx;

  /* sequence counter of first received message is not checked */
  if (CanTSyn_RxSequenceCounter[slaveIdx] <= CANTSYN_MAX_SEQUENCE_COUNTER)
  {
    /* calculate JumpWidth from last received SC */
    if (counter < CanTSyn_RxSequenceCounter[slaveIdx])
    {
      counterJumpWidth = (CANTSYN_MAX_SEQUENCE_COUNTER - CanTSyn_RxSequenceCounter[slaveIdx]) + counter;
    }
    else
    {
      counterJumpWidth = counter - CanTSyn_RxSequenceCounter[slaveIdx];
    }

    if ((counterJumpWidth > 0U) && (counterJumpWidth <= CanTSyn_DomainConfig[domainIdx].SequenceCounterJumpWidth)) /* PRQA S 3689 */ /* MD_CanTSyn_3689 */
    {
      retVal = E_OK;
    }
  }
  else
  {
    retVal = E_OK;
  }

  /* update last received sequence counter */
  CanTSyn_RxSequenceCounter[slaveIdx] = counter;

  return retVal;

} /* CanTSyn_CheckRxSequenceCounter() */

STATIC FUNC(void, CANTSYN_CODE) CanTSyn_MemCpy(
  P2VAR(uint8, AUTOMATIC, CANTSYN_APPL_VAR) destination,
  P2CONST(uint8, AUTOMATIC, CANTSYN_APPL_DATA) source,
  uint8 count) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Implementation ----------------------------------------------- */
  for ( ;count > 0U; count-- )
  {
    destination[count - 1U] = source[count - 1U];
  }

} /* CanTSyn_MemCpy() */
#endif

#if (CANTSYN_MASTER_COUNT)
STATIC FUNC(void, CANTSYN_CODE) CanTSyn_ProcessSend(uint8 masterIdx) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 domainIdx;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  domainIdx = CanTSyn_MasterConfig[masterIdx].DomainIdx;

  switch (CanTSyn_MasterState[masterIdx].State)
  {
    case CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND:
      if ((CanTSyn_TransmitState == CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND) && (CanTSyn_MasterState[masterIdx].TxIntervalCount == 0U) && (CanTSyn_CanControllerTransmissionState[CanTSyn_PduIdToCanControllerIdxMapping[CanTSyn_MasterConfig[masterIdx].MasterConfHandleId]] == CANTSYN_TX_ON))
      {
        if (CanTSyn_DomainConfig[domainIdx].DomainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
        {
          /* get Offset Time Base */
          retVal = StbM_GetOffset(CanTSyn_DomainConfig[domainIdx].TimeBaseId, &CanTSyn_MasterState[masterIdx].SyncTimestamp); /* PRQA S 3685 */ /* MD_CanTSyn_3685 */
        }
        else
        {
          /* get Synchronized Time Base T0 */
          retVal = StbM_GetCurrentTime(CanTSyn_DomainConfig[domainIdx].TimeBaseId, &CanTSyn_MasterState[masterIdx].SyncTimestamp, &CanTSyn_MasterState[masterIdx].UserData);
        }

        if ((retVal == E_OK) && (CanTSyn_GetGlobalTimeBaseBit(CanTSyn_MasterState[masterIdx].SyncTimestamp.timeBaseStatus) != 0U))
        {
          if (CanTSyn_TransmitSync(masterIdx) == E_OK)
          {
            SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            CanTSyn_TransmitState = CANTSYN_STATE_SEND_WAITING_FOR_TX_CONFIRMATION;
            CanTSyn_MasterState[masterIdx].State = CANTSYN_STATE_SEND_WAITING_FOR_TX_CONFIRMATION;
            CanTSyn_MasterState[masterIdx].TxIntervalCount = CanTSyn_MasterConfig[masterIdx].TxPeriod;
            CanTSyn_MasterState[masterIdx].TxFollowUpOffsetCount = CanTSyn_MasterConfig[masterIdx].TxFollowUpOffset;
            CanTSyn_MasterState[masterIdx].MasterConfTimeoutCount = CanTSyn_MasterConfig[masterIdx].MasterConfTimeout;
            SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          }
        }
      }
      break;

    case CANTSYN_STATE_SEND_WAITING_FOR_TX_CONFIRMATION:
      if (CanTSyn_MasterState[masterIdx].MasterConfTimeoutCount == 0U)
      {
        SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        CanTSyn_TransmitState = CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND;
        CanTSyn_MasterState[masterIdx].State = CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND;
        SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      break;

    case CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_SEND:
      if (CanTSyn_MasterState[masterIdx].TxFollowUpOffsetCount == 0U)
      {
        if (CanTSyn_TransmitFup(masterIdx) == E_OK)
        {
          SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          CanTSyn_TransmitState = CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND;
          CanTSyn_MasterState[masterIdx].State = CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND;
          SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }
      }
      break;
    default:
        ;
  }

} /* CanTSyn_ProcessSend() */ /* PRQA S 6030 */ /* MD_MSR_STCYC */

STATIC FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_TransmitSync(uint8 masterIdx) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  PduInfoType pduInfo;
  CanTSyn_CanMsgType syncMsg;
  uint8 domainIdx, counter;
# if (CANTSYN_CRC_USED)
  uint8 crcResult, dataId;
# endif

  /* ----- Implementation ----------------------------------------------- */
  domainIdx = CanTSyn_MasterConfig[masterIdx].DomainIdx;

  SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  pduInfo.SduLength  = CANTSYN_TIME_SYNC_MESSAGE_DLC;
  pduInfo.SduDataPtr = (SduDataPtrType) syncMsg;

  /* increment sequence counter on every transmission request of a SYNC message */
  CanTSyn_IncrementSequenceCounter(masterIdx);
  counter = CanTSyn_TxSequenceCounter[masterIdx];

  if (CanTSyn_DomainConfig[domainIdx].DomainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
  {
    /* Domain numbers of offset time bases (16-31) are carried in TimeSync messages as Domain number - 16 */
    CanTSyn_CanSignal_SetD(syncMsg, CanTSyn_DomainConfig[domainIdx].DomainId - CANTSYN_START_OFFSET_TIME_DOMAIN_ID);
    /* write secondsHi portion of Offset Time Base to OfsTimeSecLsbHi */
    CanTSyn_CanSignal_SetSecHi(syncMsg, CanTSyn_MasterState[masterIdx].SyncTimestamp.secondsHi);
  }
  else
  {
    CanTSyn_CanSignal_SetD(syncMsg, CanTSyn_DomainConfig[domainIdx].DomainId);
    CanTSyn_CanSignal_SetUserByte0(syncMsg, CanTSyn_MasterState[masterIdx].UserData.userByte0);
  }

  /* for SYNC message write second portion of T0 to SyncTimeSec,
     for OFS message write second portion of Offset Time Base to OfsTimeSecLsbLo */
  CanTSyn_CanSignal_SetTime(syncMsg, CanTSyn_MasterState[masterIdx].SyncTimestamp.seconds)

  CanTSyn_CanSignal_SetSC(syncMsg, counter);

  if (CanTSyn_MasterConfig[masterIdx].TxCrcSecured == CANTSYN_CRC_NOT_SUPPORTED)
  {
    if (CanTSyn_DomainConfig[domainIdx].DomainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
    {
      CanTSyn_CanSignal_SetType(syncMsg, CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_NOT_CRC);
      /* set reserved byte to default value 0 */
      CanTSyn_CanSignal_SetReservedOfs(syncMsg, 0U);
    }
    else
    {
      CanTSyn_CanSignal_SetType(syncMsg, CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_NOT_CRC);
      CanTSyn_CanSignal_SetUserByte1(syncMsg, CanTSyn_MasterState[masterIdx].UserData.userByte1);
    }
  }
# if (CANTSYN_CRC_USED)
  else
  {
    /* calculate DataID as DataIDList[SC] */
    if (CanTSyn_DomainConfig[domainIdx].DomainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
    {
      CanTSyn_CanSignal_SetType(syncMsg, CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC);
      dataId = CanTSyn_OfsDataIDList[counter];
    }
    else
    {
      CanTSyn_CanSignal_SetType(syncMsg, CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC);
      dataId = CanTSyn_SyncDataIDList[counter];
    }

    crcResult = Crc_CalculateCRC8H2F(&(syncMsg[2U]), 6U, CANTSYN_CRC_START_VALUE, TRUE);
    crcResult = Crc_CalculateCRC8H2F(&dataId, 1U, crcResult, FALSE);
    CanTSyn_CanSignal_SetCRC(syncMsg, crcResult);
  }
# endif

  if (CanTSyn_DomainConfig[domainIdx].DomainId < CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
  {
    /* get raw time T0raw for time measurement of transmission delay */
    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retVal = StbM_GetCurrentTimeRaw(&CanTSyn_MasterState[masterIdx].SyncTimestampRaw);
    SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  else
  {
    retVal = E_OK;
  }

  if (retVal == E_OK)
  {
    retVal = CanIf_Transmit(CanTSyn_MasterConfig[masterIdx].TxPduId, &pduInfo);
  }

  SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return retVal;

} /* CanTSyn_TransmitSync() */

STATIC FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_TransmitFup(uint8 masterIdx) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  PduInfoType pduInfo;
  CanTSyn_CanMsgType fupMsg;
  uint8 domainIdx, counter;
# if (CANTSYN_CRC_USED)
  uint8 crcResult, dataId;
# endif

  /* ----- Implementation ----------------------------------------------- */
  domainIdx = CanTSyn_MasterConfig[masterIdx].DomainIdx;

  SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  pduInfo.SduLength  = CANTSYN_TIME_SYNC_MESSAGE_DLC;
  pduInfo.SduDataPtr = (SduDataPtrType) fupMsg;

  if (CanTSyn_DomainConfig[domainIdx].DomainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
  {
    /* Domain numbers of offset time bases (16-31) are carried in TimeSync messages as Domain number - 16 */
    CanTSyn_CanSignal_SetD(fupMsg, CanTSyn_DomainConfig[domainIdx].DomainId - CANTSYN_START_OFFSET_TIME_DOMAIN_ID);
    /* write high bytes of secondsHi of Offset Time Base to OfsTimeSecMsbHi */
    CanTSyn_CanSignal_SetSecHi(fupMsg, (uint8)(CanTSyn_MasterState[masterIdx].SyncTimestamp.secondsHi >> 8U));
    /* write nanosecond portion of Offset Time Base to OfsTimeNSec */
    CanTSyn_CanSignal_SetTime(fupMsg, CanTSyn_MasterState[masterIdx].SyncTimestamp.nanoseconds)
  }
  else
  {
    CanTSyn_CanSignal_SetD(fupMsg, CanTSyn_DomainConfig[domainIdx].DomainId);
    /* set reserved bits to default value 0 */
    CanTSyn_CanSignal_SetReservedFup(fupMsg, 0U);
    CanTSyn_CanSignal_SetSGW(fupMsg, CanTSyn_GetSyncToGatewayBit(CanTSyn_MasterState[masterIdx].SyncTimestamp.timeBaseStatus));
    /* write second portion of T4 to OVS */
    CanTSyn_CanSignal_SetOVS(fupMsg, CanTSyn_MasterState[masterIdx].FupTimestamp.seconds);
    /* write nanosecond portion of T4 to SyncTimeNSec */
    CanTSyn_CanSignal_SetTime(fupMsg, CanTSyn_MasterState[masterIdx].FupTimestamp.nanoseconds)
  }

  counter = CanTSyn_TxSequenceCounter[masterIdx];
  CanTSyn_CanSignal_SetSC(fupMsg, counter);

  if (CanTSyn_MasterConfig[masterIdx].TxCrcSecured == CANTSYN_CRC_NOT_SUPPORTED)
  {
    if (CanTSyn_DomainConfig[domainIdx].DomainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
    {
      CanTSyn_CanSignal_SetType(fupMsg, CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_NOT_CRC);
      /* set reserved byte to default value 0 */
      CanTSyn_CanSignal_SetReservedOfs(fupMsg, 0U);
    }
    else
    {
      CanTSyn_CanSignal_SetType(fupMsg, CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_NOT_CRC);
      CanTSyn_CanSignal_SetUserByte2(fupMsg, CanTSyn_MasterState[masterIdx].UserData.userByte2);
    }
  }
# if (CANTSYN_CRC_USED)
  else
  {
    /* calculate DataID as DataIDList[SC] */
    if (CanTSyn_DomainConfig[domainIdx].DomainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
    {
      CanTSyn_CanSignal_SetType(fupMsg, CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC);
      dataId = CanTSyn_OfnsDataIDList[counter];
    }
    else
    {
      CanTSyn_CanSignal_SetType(fupMsg, CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC);
      dataId = CanTSyn_FupDataIDList[counter];
    }

    crcResult = Crc_CalculateCRC8H2F(&(fupMsg[2U]), 6U, CANTSYN_CRC_START_VALUE, TRUE);
    crcResult = Crc_CalculateCRC8H2F(&dataId, 1U, crcResult, FALSE);
    CanTSyn_CanSignal_SetCRC(fupMsg, crcResult);
  }
# endif

  if (CanIf_Transmit(CanTSyn_MasterConfig[masterIdx].TxPduId, &pduInfo) == E_OK)
  {
    retVal = E_OK;
  }

  SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return retVal;

} /* CanTSyn_TransmitFup() */

STATIC FUNC(void, CANTSYN_CODE) CanTSyn_IncrementSequenceCounter(uint8 masterIdx) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Implementation ----------------------------------------------- */
  if (CanTSyn_TxSequenceCounter[masterIdx] == CANTSYN_MAX_SEQUENCE_COUNTER)
  {
    CanTSyn_TxSequenceCounter[masterIdx] = 0U;
  }
  else
  {
    CanTSyn_TxSequenceCounter[masterIdx]++;
  }

} /* CanTSyn_IncrementSequenceCounter() */
#endif

STATIC FUNC(void, CANTSYN_CODE) CanTSyn_InitDomain(uint8 domainIdx) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
#if (CANTSYN_SLAVE_COUNT)
  uint8 slaveIdx;
#endif
#if (CANTSYN_MASTER_COUNT)
  uint8 masterCount, masterIdx;
#endif

  /* ----- Implementation ----------------------------------------------- */
#if (CANTSYN_SLAVE_COUNT)
  /* init slave state */
  if (CanTSyn_DomainHasSlave(domainIdx))
  {
    slaveIdx = CanTSyn_DomainConfig[domainIdx].SlaveIdx;
    CanTSyn_SlaveState[slaveIdx].State = CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC;
    /* initialize Rx sequence counter with invalid value to enable detection of no received message */
    CanTSyn_RxSequenceCounter[slaveIdx] = CANTSYN_MAX_SEQUENCE_COUNTER + 1U;
  }
#endif

#if (CANTSYN_MASTER_COUNT)
  /* init master state */
  if (CanTSyn_DomainHasMaster(domainIdx))
  {
    for (masterCount = 0U; masterCount < CanTSyn_DomainConfig[domainIdx].MasterCount; masterCount++)
    {
      masterIdx = CanTSyn_DomainConfig[domainIdx].MasterStartIdx + masterCount;
      CanTSyn_MasterState[masterIdx].State = CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND;
      CanTSyn_MasterState[masterIdx].TxIntervalCount = CanTSyn_MasterConfig[masterIdx].TxPeriod;
      CanTSyn_TxSequenceCounter[masterIdx] = CANTSYN_MAX_SEQUENCE_COUNTER;
    }
  }
#endif

} /* CanTSyn_InitDomain() */

STATIC FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_TimestampPlusTimestampRaw(
  P2CONST(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_DATA) timestampPtr,
  P2CONST(StbM_TimeStampRawType, AUTOMATIC, CANTSYN_APPL_DATA) timestampRawPtr,
  P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timesumPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CANTSYN_E_NO_ERROR;
  uint8 overflowSeconds = 0U;

  /* ----- Development Error Checks ------------------------------------- */
#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  /* Check parameter 'timestampPtr' */
  if (timestampPtr == NULL_PTR)
  {
    errorId = CANTSYN_E_NULL_POINTER;
  }
  /* Check parameter 'timestampRawPtr' */
  else if (timestampRawPtr == NULL_PTR)
  {
    errorId = CANTSYN_E_NULL_POINTER;
  }
  /* Check parameter 'timesumPtr' */
  else if (timesumPtr == NULL_PTR)
  {
    errorId = CANTSYN_E_NULL_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    timesumPtr->nanoseconds = timestampPtr->nanoseconds + CANTSYN_STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(timestampRawPtr);

    /* check for overflow of nanoseconds */
    if (timesumPtr->nanoseconds < CANTSYN_STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(timestampRawPtr))
    {
      /* split seconds from timestampRawPtr */
      overflowSeconds = (uint8)(CANTSYN_STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(timestampRawPtr) / (CANTSYN_TIMESTAMP_MAX_NANOSECONDS + 1U));
      timesumPtr->nanoseconds = (CANTSYN_STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(timestampRawPtr) % (CANTSYN_TIMESTAMP_MAX_NANOSECONDS + 1U)) + timestampPtr->nanoseconds;
    }

    /* check if nanoseconds are still bigger than one second */
    if (timesumPtr->nanoseconds > CANTSYN_TIMESTAMP_MAX_NANOSECONDS)
    {
      overflowSeconds += (uint8)(timesumPtr->nanoseconds / (CANTSYN_TIMESTAMP_MAX_NANOSECONDS + 1U));
      timesumPtr->nanoseconds = timesumPtr->nanoseconds % (CANTSYN_TIMESTAMP_MAX_NANOSECONDS + 1U);
    }

    timesumPtr->seconds = timestampPtr->seconds;
    timesumPtr->secondsHi = timestampPtr->secondsHi;

    if (overflowSeconds > 0U)
    {
      if (timestampPtr->seconds > (CANTSYN_TIMESTAMP_MAX_SECONDS - overflowSeconds))
      {
        if (timestampPtr->secondsHi < CANTSYN_TIMESTAMP_MAX_SECONDSHI)
        {
          timesumPtr->secondsHi++;
          retVal = E_OK;
        }
      }
      else
      {
        retVal = E_OK;
      }
      timesumPtr->seconds += overflowSeconds;
    }
    else
    {
      retVal = E_OK;
    }

    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_TIMESTAMP_PLUS_TIMESTAMPRAW, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* CanTSyn_TimestampPlusTimestampRaw() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#if (CANTSYN_SLAVE_COUNT)
/**********************************************************************************************************************
 *  CanTSyn_RxIndication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, CANTSYN_CODE) CanTSyn_RxIndication(
  PduIdType RxPduId, 
  P2CONST(PduInfoType, AUTOMATIC, CANTSYN_APPL_DATA) PduInfoPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;
  uint8 domainId, domainIdx, slaveIdx, messageType, counter;
# if (CANTSYN_CRC_USED)
  uint8 crcResult, dataId;
# endif

  /* ----- Development Error Checks ------------------------------------- */
# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CanTSyn_ModuleInitialized == (uint8)CANTSYN_UNINIT)
  {
    errorId = CANTSYN_E_NOT_INITIALIZED;
  }
  /* Check parameter 'PduInfoPtr' */
  else if (PduInfoPtr == NULL_PTR)
  {
    errorId = CANTSYN_E_NULL_POINTER;
  }
  /* Check parameter 'PduInfoPtr->SduDataPtr' */
  else if (PduInfoPtr->SduDataPtr == NULL_PTR)
  {
    errorId = CANTSYN_E_NULL_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* check DLC of received message */
    if (PduInfoPtr->SduLength == CANTSYN_TIME_SYNC_MESSAGE_DLC)
    {
      domainId = CanTSyn_CanSignal_GetD(PduInfoPtr->SduDataPtr);
      messageType = CanTSyn_CanSignal_GetType(PduInfoPtr->SduDataPtr);

      if (CanTSyn_IsOfsMsg(messageType) || CanTSyn_IsOfnsMsg(messageType))
      { /* TimeSync messages of Offset Time Bases carry the Domain number - 16 */
        domainId += CANTSYN_START_OFFSET_TIME_DOMAIN_ID;
      }

      /* check if the domain matches to one of the configured Time Domains */
      for (domainIdx = 0U; domainIdx < CANTSYN_DOMAIN_COUNT; domainIdx++)
      {
        if (CanTSyn_DomainConfig[domainIdx].DomainId == domainId)
        {
          if (CanTSyn_DomainHasSlave(domainIdx))
          {
            slaveIdx = CanTSyn_DomainConfig[domainIdx].SlaveIdx;

            /* check if the received PduId matches to the configured PduId */
            if (CanTSyn_SlaveConfig[slaveIdx].SlaveHandleId == RxPduId)
            {
              /* check if SYNC message was received and expected */
              if ((CanTSyn_SlaveState[slaveIdx].State == CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC) && (CanTSyn_IsSyncMsg(messageType) || CanTSyn_IsOfsMsg(messageType)))
              { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                counter = CanTSyn_CanSignal_GetSC(PduInfoPtr->SduDataPtr);

                /* check if SC matches to the expected value */
                if (CanTSyn_CheckRxSequenceCounter(domainIdx, counter) == E_OK)
                {
                  switch (CanTSyn_SlaveConfig[slaveIdx].RxCrcValidated) /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  {
                    case CANTSYN_CRC_IGNORED:
                      CanTSyn_HandleSync(domainIdx, PduInfoPtr);
                      break;

                    case CANTSYN_CRC_NOT_VALIDATED:
                      /* check if Type matches depending on the CanTSynRxCrcValidated parameter */
                      if (!CanTSyn_IsSyncCrcSecured(messageType))
                      {
                        CanTSyn_HandleSync(domainIdx, PduInfoPtr);
                      }
                      break;

# if (CANTSYN_CRC_USED)
                    case CANTSYN_CRC_VALIDATED:
                      /* check if Type matches depending on the CanTSynRxCrcValidated parameter */
                      if (CanTSyn_IsSyncCrcSecured(messageType))
                      {
                        /* calculate CRC over received PDU */
                        crcResult = Crc_CalculateCRC8H2F(&(PduInfoPtr->SduDataPtr[2U]), 6U, CANTSYN_CRC_START_VALUE, TRUE);
                        if (domainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
                        {
                          dataId = CanTSyn_OfsDataIDList[counter];
                        }
                        else
                        {
                          dataId = CanTSyn_SyncDataIDList[counter];
                        }
                        crcResult = Crc_CalculateCRC8H2F(&dataId, 1U, crcResult, FALSE);

                        /* check CRC */
                        if (crcResult == CanTSyn_CanSignal_GetCRC(PduInfoPtr->SduDataPtr))
                        {
                          CanTSyn_HandleSync(domainIdx, PduInfoPtr);
                        }
                      }
                      break;
# endif

                    default:
                      ;
                  }
                }
              }
              /* check if FUP message was received and expected */
              else if ((CanTSyn_SlaveState[slaveIdx].State == CANTSYN_STATE_RECEIVE_WAITING_FOR_FOLLOW_UP) && (CanTSyn_IsFupMsg(messageType) || CanTSyn_IsOfnsMsg(messageType))) /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
              {
                counter = CanTSyn_CanSignal_GetSC(PduInfoPtr->SduDataPtr);

                /* check if SC matches to the expected value and SyncTimeNSec matches the defined range of StbM_TimeStampType.nanoseconds */
                if ((counter != CanTSyn_CanSignal_GetSC(CanTSyn_SlaveState[slaveIdx].SyncMsg)) || (CanTSyn_CanSignal_GetTime(PduInfoPtr->SduDataPtr) > CANTSYN_TIMESTAMP_MAX_NANOSECONDS))
                { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  CanTSyn_SlaveState[slaveIdx].State = CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC;
                }
                else
                { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  switch (CanTSyn_SlaveConfig[slaveIdx].RxCrcValidated)
                  {
                    case CANTSYN_CRC_IGNORED:
                      CanTSyn_HandleFup(domainIdx, PduInfoPtr);
                      break;

                    case CANTSYN_CRC_NOT_VALIDATED:
                      /* check if Type matches depending on the CanTSynRxCrcValidated parameter */
                      if (!CanTSyn_IsFupCrcSecured(messageType))
                      {
                        CanTSyn_HandleFup(domainIdx, PduInfoPtr);
                      }
                      break;

# if (CANTSYN_CRC_USED)
                    case CANTSYN_CRC_VALIDATED:
                      /* check if Type matches depending on the CanTSynRxCrcValidated parameter */
                      if (CanTSyn_IsFupCrcSecured(messageType))
                      {
                        /* calculate CRC over received PDU */
                        crcResult = Crc_CalculateCRC8H2F(&(PduInfoPtr->SduDataPtr[2U]), 6U, CANTSYN_CRC_START_VALUE, TRUE);
                        if (domainId >= CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
                        {
                          dataId = CanTSyn_OfnsDataIDList[counter];
                        }
                        else
                        {
                          dataId = CanTSyn_FupDataIDList[counter];
                        }
                        crcResult = Crc_CalculateCRC8H2F(&dataId, 1U, crcResult, FALSE);

                        /* check CRC */
                        if (crcResult == CanTSyn_CanSignal_GetCRC(PduInfoPtr->SduDataPtr))
                        {
                          CanTSyn_HandleFup(domainIdx, PduInfoPtr);
                        }
                      }
                      break;
# endif

                    default:
                      ;
                  }
                }
              }
              else
              {
                /* not expected message */
              }
            }
# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
            else
            {
              /* Domain has configured different RxPduId */
              errorId = CANTSYN_E_INVALID_PDUID;
            }
# endif
          }
          break;
        }
      }
    }
  }

# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_RX_INDICATION, errorId);
  }
# else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

} /* CanTSyn_RxIndication() */ /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (CANTSYN_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CANTSYN_CODE) CanTSyn_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CANTSYN_APPL_VAR) versioninfo) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  /* Check parameter 'versioninfo' */
  if (versioninfo == NULL_PTR)
  {
    errorId = CANTSYN_E_NULL_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    versioninfo->vendorID = (CANTSYN_VENDOR_ID);
    versioninfo->moduleID = (CANTSYN_MODULE_ID);
    versioninfo->sw_major_version = (CANTSYN_SW_MAJOR_VERSION);
    versioninfo->sw_minor_version = (CANTSYN_SW_MINOR_VERSION);
    versioninfo->sw_patch_version = (CANTSYN_SW_PATCH_VERSION);
  }

# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_GET_VERSION_INFO, errorId);
  }
# else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

} /* CanTSyn_GetVersionInfo() */
#endif /* (CANTSYN_VERSION_INFO_API == STD_ON) */

/**********************************************************************************************************************
 *  CanTSyn_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CANTSYN_CODE) CanTSyn_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;
  uint8 domainIdx;
#if (CANTSYN_SLAVE_COUNT)
  uint8 slaveIdx;
#endif
#if (CANTSYN_MASTER_COUNT)
  uint8 masterCount, masterIdx;
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CanTSyn_ModuleInitialized == (uint8)CANTSYN_UNINIT)
  {
    errorId = CANTSYN_E_NOT_INITIALIZED;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    for (domainIdx = 0U; domainIdx < CANTSYN_DOMAIN_COUNT; domainIdx++)
    {
#if (CANTSYN_SLAVE_COUNT)
      if (CanTSyn_DomainHasSlave(domainIdx))
      {
        slaveIdx = CanTSyn_DomainConfig[domainIdx].SlaveIdx;

        /* Rx Timeout Handling */
        SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        if (CanTSyn_SlaveState[slaveIdx].RxFollowUpTimeoutCount > 0U)
        {
          CanTSyn_SlaveState[slaveIdx].RxFollowUpTimeoutCount--;
        }
        SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

        CanTSyn_ProcessReceive(slaveIdx);
      }
#endif

#if (CANTSYN_MASTER_COUNT)
      if (CanTSyn_DomainHasMaster(domainIdx))
      {
        for (masterCount = 0U; masterCount < CanTSyn_DomainConfig[domainIdx].MasterCount; masterCount++)
        {
          masterIdx = CanTSyn_DomainConfig[domainIdx].MasterStartIdx + masterCount;

          /* TxPeriod Handling */
          if (CanTSyn_MasterState[masterIdx].TxIntervalCount > 0U)
          {
            CanTSyn_MasterState[masterIdx].TxIntervalCount--;
          }

          /* TxFollowUpOffset Handling */
          if (CanTSyn_MasterState[masterIdx].TxFollowUpOffsetCount > 0U)
          {
            CanTSyn_MasterState[masterIdx].TxFollowUpOffsetCount--;
          }

          /* MasterConfTimeout Handling */
          if (CanTSyn_MasterState[masterIdx].MasterConfTimeoutCount > 0U)
          {
            CanTSyn_MasterState[masterIdx].MasterConfTimeoutCount--;
          }

          CanTSyn_ProcessSend(masterIdx);
        }
      }
#endif
    }
  }

#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_MAIN_FUNCTION, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

} /* CanTSyn_MainFunction() */ /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CanTSyn_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CANTSYN_CODE)  CanTSyn_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Implementation ----------------------------------------------- */
#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  CanTSyn_ModuleInitialized = CANTSYN_UNINIT;
#endif

} /* CanTSyn_InitMemory() */

/**********************************************************************************************************************
 *  CanTSyn_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CANTSYN_CODE) CanTSyn_Init(P2CONST(CanTSyn_ConfigType, AUTOMATIC, CANTSYN_APPL_DATA) configPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 domainIdx;
#if (CANTSYN_MASTER_COUNT)
  uint8 canControllerIdx;
#endif

  /* ----- Implementation ----------------------------------------------- */
  configPtr = configPtr; /* PRQA S 3199 */ /* MD_CanTSyn_3199 */

  /* init all domains */
  for (domainIdx = 0u; domainIdx < CANTSYN_DOMAIN_COUNT; domainIdx++)
  {
    CanTSyn_InitDomain(domainIdx);
  }

#if (CANTSYN_MASTER_COUNT)
  CanTSyn_TransmitState = CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND;
  for (canControllerIdx = 0U; canControllerIdx < CANTSYN_CANCONTROLLER_COUNT; canControllerIdx++)
  {
    CanTSyn_CanControllerTransmissionState[canControllerIdx] = CANTSYN_TX_ON;
  }
#endif

#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  CanTSyn_ModuleInitialized = (uint8)CANTSYN_INIT;
#endif

} /* CanTSyn_Init() */

#if (CANTSYN_MASTER_COUNT)
/**********************************************************************************************************************
 *  CanTSyn_TxConfirmation()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CANTSYN_CODE) CanTSyn_TxConfirmation(PduIdType TxPduId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;
  uint8 domainIdx;
  uint8 domainCount, masterCount, masterIdx;
  StbM_TimeStampType syncTime;
  StbM_TimeStampRawType syncTimestampRaw, fupTimestampRaw;
  boolean foundMaster = FALSE;

  /* ----- Development Error Checks ------------------------------------- */
# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  domainIdx = CANTSYN_INV_DOMAIN_IDX;
  /* Check initialization state of the component */
  if (CanTSyn_ModuleInitialized == (uint8)CANTSYN_UNINIT)
  {
    errorId = CANTSYN_E_NOT_INITIALIZED;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* search for domain index */
    for (domainCount = 0U; domainCount < CANTSYN_DOMAIN_COUNT; domainCount++)
    {
      if (CanTSyn_DomainHasMaster(domainCount))
      {
        for (masterCount = 0U; masterCount < CanTSyn_DomainConfig[domainCount].MasterCount; masterCount++)
        {
          masterIdx = CanTSyn_DomainConfig[domainCount].MasterStartIdx + masterCount;
          if (CanTSyn_MasterConfig[masterIdx].MasterConfHandleId == TxPduId)
          {
            domainIdx = domainCount;
            if (CanTSyn_MasterState[masterIdx].State == CANTSYN_STATE_SEND_WAITING_FOR_TX_CONFIRMATION)
            {
              if (CanTSyn_DomainConfig[domainIdx].DomainId < CANTSYN_START_OFFSET_TIME_DOMAIN_ID)
              {
                /* retrieve time difference T0diff of the transmission delay */
                SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                syncTimestampRaw = CanTSyn_MasterState[masterIdx].SyncTimestampRaw;
                SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
                if (StbM_GetCurrentTimeDiff(syncTimestampRaw, &fupTimestampRaw) == E_OK)
                { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 0715, 3109 */ /* MD_MSR_1.1_715, MD_MSR_14.3 */

                  /* calculate T4 for FUP message as T4 = (T0ns + T0diff) with T0ns as nanosecond portion of T0 */
                  syncTime.secondsHi = 0U;
                  syncTime.seconds = 0U;
                  syncTime.nanoseconds = CanTSyn_MasterState[masterIdx].SyncTimestamp.nanoseconds;

                  if (CanTSyn_TimestampPlusTimestampRaw(&syncTime, &fupTimestampRaw, &CanTSyn_MasterState[masterIdx].FupTimestamp) == E_OK) /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                    CanTSyn_MasterState[masterIdx].State = CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_SEND;
                  }
                  else
                  { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                    CanTSyn_MasterState[masterIdx].State = CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND;
                  }

                  SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0(); /* PRQA S 0715, 3109 */ /* MD_MSR_1.1_715, MD_MSR_14.3 */
                }
                else
                { /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
                  CanTSyn_MasterState[masterIdx].State = CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND;
                }
              }
              else
              {
                CanTSyn_MasterState[masterIdx].State = CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_SEND;
              }
            }
            foundMaster = TRUE;
            break;
          }
        }
        if (foundMaster == TRUE)
        {
          break;
        }
      }
    }

# if (CANTSYN_DEV_ERROR_DETECT)
    if (domainIdx == CANTSYN_INV_DOMAIN_IDX)
    {
      /* found no corresponding domain index -> drop message */
      errorId = CANTSYN_E_INVALID_PDUID;
    }
# endif
  }

# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_TX_CONFIRMATION, errorId);
  }
# else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

} /* CanTSyn_TxConfirmation() */ /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CanTSyn_SetTransmissionMode()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_SetTransmissionMode(
  uint8 CtrlIdx,
  CanTSyn_TransmissionModeType Mode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = CANTSYN_E_NO_ERROR;
  uint8 canControllerIdx;

  /* ----- Development Error Checks ------------------------------------- */
# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check initialization state of the component */
  if (CanTSyn_ModuleInitialized == (uint8)CANTSYN_UNINIT)
  {
    errorId = CANTSYN_E_NOT_INITIALIZED;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    for (canControllerIdx = 0U; canControllerIdx < CANTSYN_CANCONTROLLER_COUNT; canControllerIdx++)
    {
      if (CanTSyn_CanControllerIdList[canControllerIdx] == CtrlIdx)
      {
        CanTSyn_CanControllerTransmissionState[canControllerIdx] = Mode;
        break;
      }
    }

    retVal = E_OK;
  }

# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_SET_TRANSMISSION_MODE, errorId);
  }
# else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

  return retVal;

} /* CanTSyn_SetTransmissionMode() */
#endif

#define CANTSYN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
 MD_CanTSyn_3199:
      Reason:     Dummy statement required to avoid compiler warnings.
      Risk:       No functional risk.
      Prevention: Not required.
 MD_CanTSyn_3685: rule 21.1
      Reason:     A function parameter is used to access an array element. The parameter is always passed by an internal function that ensures that the parameter is in a valid range.
      Risk:       Runtime failure might be introduced by later code changes.
      Prevention: Covered by code review.
 MD_CanTSyn_3689: rule 21.1
      Reason:     A function parameter is used to access an array element. The parameter is always passed by an internal function that ensures that the parameter is in a valid range.
      Risk:       Runtime failure might be introduced by later code changes.
      Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: CanTSyn.c
 *********************************************************************************************************************/
