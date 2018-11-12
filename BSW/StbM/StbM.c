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
 *        \brief  Vector AUTOSAR StbM code file
 *
 *      \details  This is the main implementation file of the Vector AUTOSAR module StbM.
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

#define STBM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "StbM.h"
#include "SchM_StbM.h"  /* Include scheduler module for critical sections */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"       /* Include Development Error Tracer */
#endif
#if (STBM_GPT_LOCALTIME_USED == STD_ON)
# include "Gpt.h"       /* Include GPT Driver */
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of StbM header file */
#if (  (STBM_SW_MAJOR_VERSION != (4U)) \
    || (STBM_SW_MINOR_VERSION != (2U)) \
    || (STBM_SW_PATCH_VERSION != (0U)) )
# error "Vendor specific version numbers of StbM.c and StbM.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (STBM_CFG_MAJOR_VERSION != (4U)) \
    || (STBM_CFG_MINOR_VERSION != (2U)) )
# error "Version numbers of StbM.c and StbM_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define STBM_TIMESTAMP_MAX_NANOSECONDS                  (999999999UL) /* 10^9 nanoseconds per second */
#define STBM_TIMESTAMP_MAX_SECONDS                      (4294967295UL)
#define STBM_TIMESTAMP_MAX_SECONDSHI                    (65535U)
#define STBM_TIMESTAMPDIFF_MAX_NANOSECONDS              (4294967295UL)
#define STBM_NANOSECONDS_IN_ONE_MICROSECOND             (1000U)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#define DUMMY_STATEMENT(x)                              (x)=(x) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define StbM_IsOsLocalTimeUsed(index)                   (StbM_TimeBaseConfig[(index)].LocalTimeMethod == STBM_OS_LOCALTIME) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_IsGptLocalTimeUsed(index)                  (StbM_TimeBaseConfig[(index)].LocalTimeMethod == STBM_GPT_LOCALTIME) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_IncrementCustomerCounter(index)            ((StbM_CustomerState[(index)].Counter == StbM_CustomerConfig[(index)].TriggeredCustomerPeriod)? (StbM_CustomerState[(index)].Counter = 1U) : (StbM_CustomerState[(index)].Counter += 1U)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_GetScheduleTableTimeConvFunc(index)        (StbM_ScheduleTableTimeConvFuncs[StbM_CustomerConfig[(index)].ScheduleTableTimeConvFuncPtrIdx]) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_IsOffsetTimeBase(index)                    (StbM_TimeBaseConfig[(index)].OffsetTimeBaseId != STBM_NO_TIMEBASEID) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_GetAbsoluteValue(value)                    (((value) < 0)? ((uint32)-(value)) : ((uint32)(value))) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define StbM_SetTimeoutBit(status)                      (status) = ((status) | StbM_Timeout_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_SetTimeleapBit(status)                     (status) = ((status) | StbM_Timeleap_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_SetSyncToGatewayBit(status)                (status) = ((status) | StbM_Sync_To_Gateway_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_SetGlobalTimeBaseBit(status)               (status) = ((status) | StbM_Global_Time_Base_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define StbM_ClearTimeoutBit(status)                    (status) = ((status) & ~StbM_Timeout_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_ClearTimeleapBit(status)                   (status) = ((status) & ~StbM_Timeleap_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_ClearSyncToGatewayBit(status)              (status) = ((status) & ~StbM_Sync_To_Gateway_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_ClearGlobalTimeBaseBit(status)             (status) = ((status) & ~StbM_Global_Time_Base_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define StbM_GetTimeoutBit(status)                      ((status) & StbM_Timeout_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_GetTimeleapBit(status)                     ((status) & StbM_Timeleap_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define StbM_GetGlobalTimeBaseBit(status)               ((status) & StbM_Global_Time_Base_BflMask) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* AUTOSAR version check */
#define STBM_AR_VERSION_EQUALS(Major,Minor,Patch) \
  ((STBM_AR_MAJOR_VERSION == (Major))\
  && (STBM_AR_MINOR_VERSION == (Minor))\
  && (STBM_AR_PATCH_VERSION == (Patch))) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Macros for StbM_TimeStampRawType accesses */
#if STBM_AR_VERSION_EQUALS(4,2,1)
# define STBM_TIMESTAMP_RAW_NANOSECONDS(StbMTimestampRaw)         ((StbMTimestampRaw).nanoseconds) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(StbMTimestampRawPtr)  ((StbMTimestampRawPtr)->nanoseconds) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
# define STBM_TIMESTAMP_RAW_NANOSECONDS(StbMTimestampRaw)         (StbMTimestampRaw) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(StbMTimestampRawPtr)  (*(StbMTimestampRawPtr)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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

#define STBM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! State of time bases */
STATIC VAR(StbM_TimeBaseType, STBM_VAR_NOINIT) StbM_TimeBaseState[STBM_TIMEBASE_COUNT]; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#if (STBM_CUSTOMER_COUNT)
/*! State of customers */
STATIC VAR(StbM_CustomerType, STBM_VAR_NOINIT) StbM_CustomerState[STBM_CUSTOMER_COUNT]; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#endif

#define STBM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define STBM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Initialization state of the module */
#if (STBM_DEV_ERROR_DETECT == STD_ON || STBM_GPT_LOCALTIME_USED == STD_ON)
STATIC VAR(uint8, STBM_VAR_ZERO_INIT) StbM_ModuleInitialized = STBM_UNINIT; /* PRQA S 0850 */ /* MD_MSR_19.8 */
#endif

#define STBM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define STBM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/**********************************************************************************************************************
 *  StbM_UpdateTimestamp()
 *********************************************************************************************************************/
/*! \brief      Update a timestamp
 *  \details    This function updates the timestamp of the given time-base.
 *  \param[in]  timeBaseId              The synchronized time-base, whose time is updated.
 *  \return     E_OK - Timestamp was updated
 *  \return     E_NOT_OK - Timestamp was not updated
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_UpdateTimestamp(StbM_SynchronizedTimeBaseType timeBaseId); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_TimestampPlusTimestamp()
 *********************************************************************************************************************/
/*! \brief      Adds two timestamps
 *  \details    This function calculates the sum of two timestamps.
 *  \param[in]   timestamp1Ptr          Pointer to timestamp where the first summand is stored.
 *  \param[in]   timestamp2Ptr          Pointer to timestamp where the second summand is stored.
 *  \param[out]  timesumPtr             Pointer to timestamp where the calculated sum is stored.
 *  \return     E_OK - Timesum is valid
 *  \return     E_NOT_OK - Timesum is invalid
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_TimestampPlusTimestamp(
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp1Ptr,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp2Ptr,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timesumPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_TimestampPlusTimediff()
 *********************************************************************************************************************/
/*! \brief      Adds time difference to timestamp
 *  \details    This function adds a time difference in nanoseconds to a timestamp.
 *  \param[in]   timestampPtr           Pointer to a timestamp.
 *  \param[in]   time                   Time difference in nanoseconds that should be added to the timestamp.
 *  \param[out]  timesumPtr             Pointer to timestamp where the calculated sum is stored.
 *  \return     E_OK - Timesum is valid
 *  \return     E_NOT_OK - Timesum is invalid
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_TimestampPlusTimediff(
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestampPtr,
  sint32 timediff,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timesumPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_TimestampMinusTimestamp()
 *********************************************************************************************************************/
/*! \brief      Subtracts two timestamps
 *  \details    This function calculates the time difference between timestamp1 and timestamp2
 *              (diff = timestamp1 - timestamp2).
 *  \param[in]  timestamp1Ptr     Pointer to first timestamp.
 *  \param[in]  timestamp2Ptr     Pointer to second timestamp.
 *  \param[out] timediffPtr       Pointer to timestamp with difference between timestamp1 and timestamp2.
 *  \return     E_OK - Time difference is valid
 *  \return     E_NOT_OK - Time difference is invalid
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_TimestampMinusTimestamp(
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp1Ptr,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp2Ptr,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timediffPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_TimestampMinusTimestampInNs
 *********************************************************************************************************************/
/*! \brief      Calculates time difference in nanoseconds
 *  \details    This function calculates the time difference between timestamp1 and timestamp2 in nanoseconds
 *              (diff = timestamp1 - timestamp2).
 *  \param[in]  timestamp1Ptr     Pointer to first timestamp.
 *  \param[in]  timestamp2Ptr     Pointer to second timestamp.
 *  \param[out] timediffPtr       Pointer to timestamp with difference between timestamp1 and timestamp2 in nanoseconds.
 *  \return     E_OK - Time difference is valid
 *  \return     E_NOT_OK - Time difference is invalid
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_TimestampMinusTimestampInNs(
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp1Ptr,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp2Ptr,
  P2VAR(sint32, AUTOMATIC, STBM_APPL_VAR) timediffPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_UpdateTimestamp(StbM_SynchronizedTimeBaseType timeBaseId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint32 elapsedCounterValue;
  uint32 elapsedTime, nanosecondsSum;
  uint8 elapsedSeconds = 0U;
  TickType osTicks, elapsedOsCounterValue;
#if (STBM_GPT_LOCALTIME_USED == STD_ON)
  uint32 OldGptChannelValue;
#endif
#if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
  Eth_TimeStampQualType ethIfTimeQual;
  Eth_TimeStampType ethIfTimeStamp;
  StbM_TimeStampType newLocalTime;
  StbM_TimeStampType oldLocalTime;
  StbM_TimeStampType diffLocalTime;
  StbM_TimeStampType localTime;
#endif

  /* ----- Implementation ----------------------------------------------- */
#if (STBM_GPT_LOCALTIME_USED == STD_ON)
  if (StbM_IsOsLocalTimeUsed(timeBaseId) || StbM_IsGptLocalTimeUsed(timeBaseId))
  {
    if (StbM_IsOsLocalTimeUsed(timeBaseId))
    {
#else
  if (StbM_IsOsLocalTimeUsed(timeBaseId))
  {
#endif
      SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      osTicks = StbM_TimeBaseState[timeBaseId].LocalTimeTickValue;
      SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      (void)GetElapsedValue((CounterType)StbM_TimeBaseConfig[timeBaseId].LocalTimeID, &osTicks, &elapsedOsCounterValue);

      SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      StbM_TimeBaseState[timeBaseId].LocalTimeTickValue = (uint32)osTicks;
      elapsedCounterValue = (uint32)elapsedOsCounterValue;
#if (STBM_GPT_LOCALTIME_USED == STD_ON)
    }
    else
    {
      SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      OldGptChannelValue = StbM_TimeBaseState[timeBaseId].LocalTimeTickValue;
      StbM_TimeBaseState[timeBaseId].LocalTimeTickValue = (uint32)Gpt_GetTimeElapsed((Gpt_ChannelType)StbM_TimeBaseConfig[timeBaseId].LocalTimeID);

      /* check for overflow of tick value */
      if (OldGptChannelValue < StbM_TimeBaseState[timeBaseId].LocalTimeTickValue)
      {
        elapsedCounterValue = StbM_TimeBaseState[timeBaseId].LocalTimeTickValue - OldGptChannelValue;
      }
      else
      {
        elapsedCounterValue = (StbM_TimeBaseConfig[timeBaseId].LocalTimeMaxValue - OldGptChannelValue) + (1U + StbM_TimeBaseState[timeBaseId].LocalTimeTickValue);
      }
    }
#endif

    elapsedTime = elapsedCounterValue * StbM_TimeBaseConfig[timeBaseId].LocalTimeNsPerTick;

    nanosecondsSum = StbM_TimeBaseState[timeBaseId].TimeStamp.nanoseconds + elapsedTime;

    /* check for overflow of nanoseconds */
    if (nanosecondsSum < elapsedTime)
    {
      /* split seconds from elapsedTime */
      elapsedSeconds = (uint8)(elapsedTime / (STBM_TIMESTAMP_MAX_NANOSECONDS + 1U));
      nanosecondsSum = (elapsedTime % (STBM_TIMESTAMP_MAX_NANOSECONDS + 1U)) + StbM_TimeBaseState[timeBaseId].TimeStamp.nanoseconds;
    }

    /* check if nanoseconds are still bigger than one second */
    if (nanosecondsSum > STBM_TIMESTAMP_MAX_NANOSECONDS)
    {
      elapsedSeconds += (uint8)(nanosecondsSum / (STBM_TIMESTAMP_MAX_NANOSECONDS + 1U));
      nanosecondsSum = nanosecondsSum % (STBM_TIMESTAMP_MAX_NANOSECONDS + 1U);
    }

    StbM_TimeBaseState[timeBaseId].TimeStamp.nanoseconds = nanosecondsSum;

    if (elapsedSeconds > 0U)
    {
      if (StbM_TimeBaseState[timeBaseId].TimeStamp.seconds > (STBM_TIMESTAMP_MAX_SECONDS - elapsedSeconds))
      {
        if (StbM_TimeBaseState[timeBaseId].TimeStamp.secondsHi < STBM_TIMESTAMP_MAX_SECONDSHI)
        {
          StbM_TimeBaseState[timeBaseId].TimeStamp.secondsHi++;
          retVal = E_OK;
        }
      }
      else
      {
        retVal = E_OK;
      }
      StbM_TimeBaseState[timeBaseId].TimeStamp.seconds += elapsedSeconds;
    }
    else
    {
      retVal = E_OK;
    }

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
#if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
  else if (StbM_TimeBaseConfig[timeBaseId].UsesEthTSynLocalTime == TRUE)
  {
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    retVal = EthIf_GetCurrentTime(StbM_TimeBaseConfig[timeBaseId].EthIfCtrlIdx, &ethIfTimeQual, &ethIfTimeStamp);
    if ((retVal == E_OK) && (ethIfTimeQual == ETH_VALID))
    {
      newLocalTime.nanoseconds = ethIfTimeStamp.nanoseconds;
      newLocalTime.seconds = ethIfTimeStamp.seconds;
      newLocalTime.secondsHi = ethIfTimeStamp.secondsHi;

      oldLocalTime.nanoseconds = StbM_TimeBaseState[timeBaseId].LocalTime.nanoseconds;
      oldLocalTime.seconds = StbM_TimeBaseState[timeBaseId].LocalTime.seconds;
      oldLocalTime.secondsHi = StbM_TimeBaseState[timeBaseId].LocalTime.secondsHi;

      retVal = StbM_TimestampMinusTimestamp(&newLocalTime, &oldLocalTime, &diffLocalTime);
      if (retVal == E_OK)
      {
        StbM_TimeBaseState[timeBaseId].LocalTime = ethIfTimeStamp;
        retVal = StbM_TimestampPlusTimestamp(&StbM_TimeBaseState[timeBaseId].TimeStamp, &diffLocalTime, &localTime);
        if (retVal == E_OK)
        {
          StbM_TimeBaseState[timeBaseId].TimeStamp = localTime;
        }
      }
    }

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
#endif
  else
  {
    retVal = E_OK;
  }

  return retVal;

} /* StbM_UpdateTimestamp() */ /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_TimestampPlusTimestamp(
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp1Ptr,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp2Ptr,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timesumPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* Check parameter 'timestamp1Ptr' */
  if (timestamp1Ptr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'timestamp2Ptr' */
  else if (timestamp2Ptr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'timesumPtr' */
  else if (timesumPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    timesumPtr->nanoseconds = timestamp1Ptr->nanoseconds + timestamp2Ptr->nanoseconds;
    timesumPtr->seconds = timestamp1Ptr->seconds + timestamp2Ptr->seconds;
    timesumPtr->secondsHi = timestamp1Ptr->secondsHi + timestamp2Ptr->secondsHi;

    /* no real overflow of nanoseconds possible, since max value is 10^9 - 1 */
    if (timesumPtr->nanoseconds > STBM_TIMESTAMP_MAX_NANOSECONDS)
    {
      timesumPtr->seconds++;
      timesumPtr->nanoseconds -= STBM_TIMESTAMP_MAX_NANOSECONDS + 1U;
    }

    /* check for overflow of seconds */
    if (timesumPtr->seconds < (timestamp1Ptr->seconds | timestamp2Ptr->seconds))
    {
      timesumPtr->secondsHi++;
    }

    /* calculated sum is invalid, if overflow of secondsHi occurred */
    if ((timesumPtr->secondsHi >= timestamp1Ptr->secondsHi) && (timesumPtr->secondsHi >= timestamp2Ptr->secondsHi))
    {
      retVal = E_OK;
    }

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_TIMESTAMP_PLUS_TIMESTAMP, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_TimestampPlusTimestamp() */

STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_TimestampPlusTimediff(
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestampPtr,
  sint32 timediff,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timesumPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_TimeStampType timestampDiff = {0, 0, 0, 0};

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check parameter 'timestampPtr' */
  if (timestampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'timesumPtr' */
  else if (timesumPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    if (timediff > 0)
    {
      timestampDiff.seconds = ((uint32)timediff / (STBM_TIMESTAMP_MAX_NANOSECONDS + 1U));
      timestampDiff.nanoseconds = ((uint32)timediff % (STBM_TIMESTAMP_MAX_NANOSECONDS + 1U));
      retVal = StbM_TimestampPlusTimestamp(timestampPtr, &timestampDiff, timesumPtr);
    }
    else
    {
      timestampDiff.seconds = ((uint32)-timediff / (STBM_TIMESTAMP_MAX_NANOSECONDS + 1U));
      timestampDiff.nanoseconds = ((uint32)-timediff % (STBM_TIMESTAMP_MAX_NANOSECONDS + 1U));
      retVal = StbM_TimestampMinusTimestamp(timestampPtr, &timestampDiff, timesumPtr);
    }

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

# if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_TIMESTAMP_PLUS_TIMEDIFF, errorId);
  }
# else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

  return retVal;

} /* StbM_TimestampPlusTimediff() */

STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_TimestampMinusTimestamp(
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp1Ptr,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp2Ptr,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timediffPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* Check parameter 'timestamp1Ptr' */
  if (timestamp1Ptr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'timestamp2Ptr' */
  else if (timestamp2Ptr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'timediffPtr' */
  else if (timediffPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    if (timestamp1Ptr->secondsHi >= timestamp2Ptr->secondsHi)
    {
      timediffPtr->secondsHi = timestamp1Ptr->secondsHi - timestamp2Ptr->secondsHi;
      timediffPtr->seconds = timestamp1Ptr->seconds - timestamp2Ptr->seconds;

      /* check for overflow of seconds */
      if (timestamp1Ptr->seconds < timestamp2Ptr->seconds)
      {
        timediffPtr->secondsHi--;
      }

      /* check for overflow of nanoseconds */
      if (timestamp1Ptr->nanoseconds < timestamp2Ptr->nanoseconds)
      {
        timediffPtr->seconds--;
        timediffPtr->nanoseconds = (STBM_TIMESTAMP_MAX_NANOSECONDS - timestamp2Ptr->nanoseconds) + (1U + timestamp1Ptr->nanoseconds);
      }
      else
      {
        timediffPtr->nanoseconds = timestamp1Ptr->nanoseconds - timestamp2Ptr->nanoseconds;
      }

      retVal = E_OK;
    }

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

# if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_TIMESTAMP_MINUS_TIMESTAMP, errorId);
  }
# else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

  return retVal;

} /* StbM_TimestampMinusTimestamp() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

STATIC FUNC(Std_ReturnType, STBM_CODE) StbM_TimestampMinusTimestampInNs(
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp1Ptr,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timestamp2Ptr,
  P2VAR(sint32, AUTOMATIC, STBM_APPL_VAR) timediffPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* Check parameter 'timestamp1Ptr' */
  if (timestamp1Ptr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'timestamp2Ptr' */
  else if (timestamp2Ptr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'timediffPtr' */
  else if (timediffPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    if (timestamp1Ptr->secondsHi == timestamp2Ptr->secondsHi)
    {
      if (timestamp1Ptr->seconds >= timestamp2Ptr->seconds)
      {
        *timediffPtr = (sint32)(timestamp1Ptr->seconds - timestamp2Ptr->seconds);
      }
      else
      {
        *timediffPtr = -(sint32)(timestamp2Ptr->seconds - timestamp1Ptr->seconds);
      }

      if ((*timediffPtr > -2) && (*timediffPtr < 2))
      {
        *timediffPtr *= ((sint32)STBM_TIMESTAMP_MAX_NANOSECONDS + 1);
        if (timestamp1Ptr->nanoseconds >= timestamp2Ptr->nanoseconds)
        {
          *timediffPtr += (sint32)(timestamp1Ptr->nanoseconds - timestamp2Ptr->nanoseconds);
        }
        else
        {
          *timediffPtr += -(sint32)(timestamp2Ptr->nanoseconds - timestamp1Ptr->nanoseconds);
        }
        retVal = E_OK;
      }
    }

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

# if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_TIMESTAMP_MINUS_TIMESTAMP_IN_NS, errorId);
  }
# else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

  return retVal;

} /* StbM_TimestampMinusTimestampInNs() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, STBM_CODE) StbM_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Implementation ----------------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON || STBM_GPT_LOCALTIME_USED == STD_ON)
  StbM_ModuleInitialized = STBM_UNINIT;
#endif

} /* StbM_InitMemory() */

/***********************************************************************************************************************
 *  StbM_Init()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, STBM_CODE) StbM_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
#if (STBM_GPT_LOCALTIME_USED == STD_ON)
  uint16 gptChannelId;
  boolean gptChannelActive[STBM_GPT_CHANNEL_COUNT];
#endif
  uint16 timeBaseId;
  TickType osTicks;
#if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
  Eth_TimeStampQualType ethIfTimeQual;
  Eth_TimeStampType ethIfTimeStamp;
#endif
  uint16 rateMeasurementIdx;
#if (STBM_CUSTOMER_COUNT)
  uint16 customerId;
#endif

  /* ----- Implementation ----------------------------------------------- */
#if (STBM_GPT_LOCALTIME_USED == STD_ON)
  for (gptChannelId = 0U; gptChannelId < STBM_GPT_CHANNEL_COUNT; gptChannelId++)
  {
    gptChannelActive[gptChannelId] = FALSE;
  }
#endif

  for (timeBaseId = 0U; timeBaseId < STBM_TIMEBASE_COUNT; timeBaseId++)
  {
    StbM_TimeBaseState[timeBaseId].SyncLossTimeoutCount = 0U;
    StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus = 0x00U;

    /* TODO: only initialize timebase with zero, if value is not stored non-volatile or restore from NvM was not successful */
    StbM_TimeBaseState[timeBaseId].TimeStamp.nanoseconds = 0U;
    StbM_TimeBaseState[timeBaseId].TimeStamp.seconds = 0U;
    StbM_TimeBaseState[timeBaseId].TimeStamp.secondsHi = 0U;

    /* get counter value of last update of local time */
    if (StbM_IsOsLocalTimeUsed(timeBaseId))
    {
      (void)GetCounterValue((CounterType)StbM_TimeBaseConfig[timeBaseId].LocalTimeID, &osTicks);
      StbM_TimeBaseState[timeBaseId].LocalTimeTickValue = (uint32)osTicks;
    }

#if (STBM_GPT_LOCALTIME_USED == STD_ON)
    if (StbM_IsGptLocalTimeUsed(timeBaseId) && (StbM_ModuleInitialized == (uint8)STBM_UNINIT))
    {
      if (gptChannelActive[StbM_TimeBaseConfig[timeBaseId].GptChannelIdx] == FALSE)
      {
        Gpt_StartTimer((Gpt_ChannelType)StbM_TimeBaseConfig[timeBaseId].LocalTimeID, (Gpt_ValueType)StbM_TimeBaseConfig[timeBaseId].LocalTimeMaxValue);
        gptChannelActive[StbM_TimeBaseConfig[timeBaseId].GptChannelIdx] = TRUE;
      }

      StbM_TimeBaseState[timeBaseId].LocalTimeTickValue = 0U;
    }
#endif

#if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
    if (StbM_TimeBaseConfig[timeBaseId].UsesEthTSynLocalTime == TRUE)
    {
      if ((EthIf_GetCurrentTime(StbM_TimeBaseConfig[timeBaseId].EthIfCtrlIdx, &ethIfTimeQual, &ethIfTimeStamp) == E_OK) && (ethIfTimeQual == ETH_VALID))
      {
        StbM_TimeBaseState[timeBaseId].LocalTime = ethIfTimeStamp;
      }
    }
#endif

    StbM_TimeBaseState[timeBaseId].UserData.userDataLength = 0U;
    StbM_TimeBaseState[timeBaseId].UserData.userByte0 = 0U;
    StbM_TimeBaseState[timeBaseId].UserData.userByte1 = 0U;
    StbM_TimeBaseState[timeBaseId].UserData.userByte2 = 0U;

    StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement = StbM_TimeBaseConfig[timeBaseId].RateCorrectionsPerMeasurementDuration - 1U;
    StbM_TimeBaseState[timeBaseId].RateCorrection = 0U;
    for (rateMeasurementIdx = 0; rateMeasurementIdx < StbM_TimeBaseConfig[timeBaseId].RateCorrectionsPerMeasurementDuration; rateMeasurementIdx++)
    {
      StbM_TimeBaseState[timeBaseId].RateMeasurement[rateMeasurementIdx].StartGlobalTime.nanoseconds = 0U;
      StbM_TimeBaseState[timeBaseId].RateMeasurement[rateMeasurementIdx].StartGlobalTime.seconds = 0U;
      StbM_TimeBaseState[timeBaseId].RateMeasurement[rateMeasurementIdx].StartGlobalTime.secondsHi = 0U;
    }
  }

#if (STBM_CUSTOMER_COUNT)
  for (customerId = 0U; customerId < STBM_CUSTOMER_COUNT; customerId++)
  {
    StbM_CustomerState[customerId].Counter = 0U;
    StbM_CustomerState[customerId].LastSyncTimeStamp.nanoseconds = 0U;
    StbM_CustomerState[customerId].LastSyncTimeStamp.seconds = 0U;
    StbM_CustomerState[customerId].LastSyncTimeStamp.secondsHi = 0U;
    StbM_CustomerState[customerId].LastSyncValue = 0U;
  }
#endif

#if (STBM_DEV_ERROR_DETECT == STD_ON || STBM_GPT_LOCALTIME_USED == STD_ON)
  StbM_ModuleInitialized = (uint8)STBM_INIT;
#endif

} /* StbM_Init() */

/**********************************************************************************************************************
 *  StbM_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, STBM_CODE) StbM_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 timeBaseId;
#if (STBM_CUSTOMER_COUNT)
  uint16 customerId;
  ScheduleTableStatusType scheduleStatus;
  uint32 elapsedNanoseconds;
  TickType elapsedOsTicks, osTicks;
#endif

  /* ----- Implementation ----------------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    return;
  }
#endif

  for (timeBaseId = 0U; timeBaseId < STBM_TIMEBASE_COUNT; timeBaseId++)
  {
    /* update local time bases */
    if (!StbM_IsOffsetTimeBase(timeBaseId))
    {
      (void)StbM_UpdateTimestamp(timeBaseId);
    }

    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* timeout monitoring */
    if (StbM_TimeBaseState[timeBaseId].SyncLossTimeoutCount > 0U)
    {
      StbM_TimeBaseState[timeBaseId].SyncLossTimeoutCount--;
      if (StbM_TimeBaseState[timeBaseId].SyncLossTimeoutCount == 0U)
      {
        StbM_SetTimeoutBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus);
        if (StbM_TimeBaseConfig[timeBaseId].IsTimeGateway == TRUE)
        {
          StbM_SetSyncToGatewayBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus);
        }
      }
    }

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

#if (STBM_CUSTOMER_COUNT)
  /* trigger customers */
  for (customerId = 0U; customerId < STBM_CUSTOMER_COUNT; customerId++)
  {
    timeBaseId = StbM_CustomerConfig[customerId].TimeBaseID;

    StbM_IncrementCustomerCounter(customerId);

    if ((StbM_CustomerState[customerId].Counter == StbM_CustomerConfig[customerId].TriggeredCustomerPeriod) && (StbM_GetGlobalTimeBaseBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus) != 0U) && (StbM_GetTimeoutBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus) == 0U) && (StbM_GetTimeleapBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus) == 0U))
    {
      if ((GetScheduleTableStatus(StbM_CustomerConfig[customerId].ScheduleTableID, &scheduleStatus) == E_OK) && ((scheduleStatus == SCHEDULETABLE_WAITING) || (scheduleStatus == SCHEDULETABLE_RUNNING) || (scheduleStatus == SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)))
      {
        /* first synchronization of schedule table */
        if ((StbM_CustomerState[customerId].LastSyncTimeStamp.nanoseconds == 0U) && (StbM_CustomerState[customerId].LastSyncTimeStamp.seconds == 0U) && (StbM_CustomerState[customerId].LastSyncTimeStamp.secondsHi == 0U))
        {
          (void)SyncScheduleTable(StbM_CustomerConfig[customerId].ScheduleTableID, 0U);
        }
        else
        {
          if ((StbM_TimeBaseState[timeBaseId].TimeStamp.secondsHi > StbM_CustomerState[customerId].LastSyncTimeStamp.secondsHi) || (StbM_TimeBaseState[timeBaseId].TimeStamp.seconds > StbM_CustomerState[customerId].LastSyncTimeStamp.seconds))
          {
            elapsedNanoseconds = (STBM_TIMESTAMP_MAX_NANOSECONDS - StbM_CustomerState[customerId].LastSyncTimeStamp.nanoseconds) + (1U + StbM_TimeBaseState[timeBaseId].TimeStamp.nanoseconds);
          }
          else
          {
            elapsedNanoseconds = StbM_TimeBaseState[timeBaseId].TimeStamp.nanoseconds - StbM_CustomerState[customerId].LastSyncTimeStamp.nanoseconds;
          }
          elapsedOsTicks = StbM_GetScheduleTableTimeConvFunc(customerId)(elapsedNanoseconds / STBM_NANOSECONDS_IN_ONE_MICROSECOND);
          elapsedOsTicks %= StbM_CustomerConfig[customerId].ScheduleTableDuration;
          osTicks = StbM_CustomerState[customerId].LastSyncValue + elapsedOsTicks;

          /* overflow check */
          if ((osTicks < elapsedOsTicks) || (osTicks >= StbM_CustomerConfig[customerId].ScheduleTableDuration))
          {
            osTicks = elapsedOsTicks - (StbM_CustomerConfig[customerId].ScheduleTableDuration - StbM_CustomerState[customerId].LastSyncValue);
          }

          (void)SyncScheduleTable(StbM_CustomerConfig[customerId].ScheduleTableID, osTicks);
          StbM_CustomerState[customerId].LastSyncValue = osTicks;
        }

        StbM_CustomerState[customerId].LastSyncTimeStamp = StbM_TimeBaseState[timeBaseId].TimeStamp;
      }
    }
  }
#endif

} /* StbM_MainFunction() */ /* PRQA S 2006, 6010, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#if (STBM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  StbM_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, STBM_CODE) StbM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, STBM_APPL_VAR) versioninfo) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* Check parameter 'versioninfo' */
  if (versioninfo == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    versioninfo->vendorID = (STBM_VENDOR_ID);
    versioninfo->moduleID = (STBM_MODULE_ID);
    versioninfo->sw_major_version = (STBM_SW_MAJOR_VERSION);
    versioninfo->sw_minor_version = (STBM_SW_MINOR_VERSION);
    versioninfo->sw_patch_version = (STBM_SW_PATCH_VERSION);
  }

# if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_GET_VERSION_INFO, errorId);
  }
# else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

} /* StbM_GetVersionInfo() */
#endif /* (STBM_VERSION_INFO_API == STD_ON) */

/**********************************************************************************************************************
 *  StbM_GetCurrentTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTime(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr,
  P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userDataPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_TimeStampType synchronizedTimeStamp;
  StbM_UserDataType synchronizedUserData;
  sint32 diffLocalTime;
  sint32 correctedLocalTime;
  StbM_TimeStampType startTimeStamp;
  sint32 diffOffset;
  uint32 diffOffsetAbs;
  uint32 diffLocalTimeAbs;
  sint32 offsetCorrectionRate;

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeBaseId' */
  else if (timeBaseId >= STBM_TIMEBASE_COUNT)
  {
    errorId = STBM_E_PARAM;
  }
  /* Check parameter 'timeStampPtr' */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'userDataPtr' */
  else if (userDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    if (StbM_IsOffsetTimeBase(timeBaseId))
    {
      /* for offset time bases, calculate the time stamp by adding the offset to the current time of the referenced time domain */
      retVal = StbM_GetCurrentTime(StbM_TimeBaseConfig[timeBaseId].OffsetTimeBaseId, &synchronizedTimeStamp, &synchronizedUserData); /* PRQA S 3670 */ /* MD_StbM_3670 */

      SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      if (retVal == E_OK)
      {
        if (StbM_GetGlobalTimeBaseBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus) != 0U)
        {
          if (StbM_TimeBaseState[timeBaseId].RateCorrection != 0)
          {
            /* correct local time with last calculated rate */
            retVal = StbM_TimestampMinusTimestampInNs(&synchronizedTimeStamp, &StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartLocalTime, &diffLocalTime);
            if (retVal == E_OK)
            {
              retVal = StbM_TimestampPlusTimestamp(&StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime, &StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartLocalTime, &startTimeStamp);
              if (retVal == E_OK)
              {
                correctedLocalTime = diffLocalTime * StbM_TimeBaseState[timeBaseId].RateCorrection;
                retVal = StbM_TimestampPlusTimediff(&startTimeStamp, correctedLocalTime, timeStampPtr);
              }
            }
          }
          else
          {
            retVal = StbM_TimestampPlusTimestamp(&synchronizedTimeStamp, &StbM_TimeBaseState[timeBaseId].TimeStamp, timeStampPtr);
          }

          if (retVal == E_OK)
          {
            timeStampPtr->timeBaseStatus = synchronizedTimeStamp.timeBaseStatus;
          }
        }
        else
        {
          /* no offset value available */
          *timeStampPtr = synchronizedTimeStamp;
          timeStampPtr->timeBaseStatus = 0x00U;
        }
      }

      *userDataPtr = StbM_TimeBaseState[timeBaseId].UserData;

      SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
    else
    {
      retVal = StbM_UpdateTimestamp(timeBaseId);
      SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      if (retVal == E_OK)
      {
        if (StbM_TimeBaseState[timeBaseId].RateCorrection != 0)
        {
          /* correct local time with last calculated rate */
          retVal = StbM_TimestampMinusTimestampInNs(&StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime, &StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartLocalTime, &diffOffset);
          if (retVal == E_OK)
          {
            retVal = StbM_TimestampMinusTimestampInNs(&StbM_TimeBaseState[timeBaseId].TimeStamp, &StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime, &diffLocalTime);
            if (retVal == E_OK)
            {
              diffOffsetAbs = StbM_GetAbsoluteValue(diffOffset);
              diffLocalTimeAbs = StbM_GetAbsoluteValue(diffLocalTime);

              if ((diffOffsetAbs >= StbM_TimeBaseConfig[timeBaseId].OffsetCorrectionJumpThreshold) || (diffLocalTimeAbs > StbM_TimeBaseConfig[timeBaseId].OffsetCorrectionAdaptionInterval))
              {
                /* rate correction */
                correctedLocalTime = diffLocalTime * StbM_TimeBaseState[timeBaseId].RateCorrection;
                retVal = StbM_TimestampPlusTimediff(&StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime, correctedLocalTime, timeStampPtr);
              }
              else
              {
                /* rate and offset correction */
                if (diffOffset < 0)
                {
                  offsetCorrectionRate = -(sint32)((uint32)-diffOffset / StbM_TimeBaseConfig[timeBaseId].OffsetCorrectionAdaptionInterval);
                }
                else
                {
                  offsetCorrectionRate = (sint32)((uint32)diffOffset / StbM_TimeBaseConfig[timeBaseId].OffsetCorrectionAdaptionInterval);
                }
                offsetCorrectionRate += 1;
                correctedLocalTime = diffLocalTime * StbM_TimeBaseState[timeBaseId].RateCorrection * offsetCorrectionRate;
                retVal = StbM_TimestampPlusTimediff(&StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartLocalTime, correctedLocalTime, timeStampPtr);
              }
            }
          }
        }
        else
        {
          *timeStampPtr = StbM_TimeBaseState[timeBaseId].TimeStamp;
        }

        *userDataPtr = StbM_TimeBaseState[timeBaseId].UserData;
      }

      SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_GET_CURRENT_TIME, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_GetCurrentTime() */ /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#if (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON)
/**********************************************************************************************************************
 *  StbM_GetCurrentTimeExtended()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeExtended(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2VAR(StbM_TimeStampExtendedType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr,
  P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userDataPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_TimeStampType currentTime;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeBaseId' */
  else if (timeBaseId >= STBM_TIMEBASE_COUNT)
  {
    errorId = STBM_E_PARAM;
  }
  /* Check parameter 'timeStampPtr' */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'userDataPtr' */
  else if (userDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* get current time in standard format and user data from StbM_GetCurrentTime */
    if (StbM_GetCurrentTime(timeBaseId, &currentTime, userDataPtr) == E_OK)
    {
      /* convert current time to extended format */
      SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      timeStampPtr->seconds = (uint64)currentTime.secondsHi << 16U;
      timeStampPtr->seconds <<= 16U;
      timeStampPtr->seconds += currentTime.seconds;
      timeStampPtr->nanoseconds = currentTime.nanoseconds;
      timeStampPtr->timeBaseStatus = currentTime.timeBaseStatus;
      SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      retVal = E_OK;
    }
  }

# if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_GET_CURRENT_TIME_EXTENDED, errorId);
  }
# else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
# endif

  return retVal;

} /* StbM_GetCurrentTimeExtended() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON) */

/**********************************************************************************************************************
 *  StbM_GetCurrentTimeRaw()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeRaw(P2VAR(StbM_TimeStampRawType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  uint32 ticks;
#if (STBM_GPT_LOCALTIME_USED == STD_OFF)
  TickType osTicks;
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeStampPtr' */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (STBM_GPT_LOCALTIME_USED == STD_ON)
    ticks = (uint32)Gpt_GetTimeElapsed((Gpt_ChannelType)STBM_MOST_ACCURATE_LOCALTIME_ID);
#else
    (void)GetCounterValue(STBM_MOST_ACCURATE_LOCALTIME_ID, &osTicks);
    ticks = (uint32)osTicks;
#endif
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(timeStampPtr) = ticks * STBM_MOST_ACCURATE_LOCALTIME_NSPERTICK;
    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retVal = E_OK;
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_GET_CURRENT_TIME_RAW, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_GetCurrentTimeRaw() */

/**********************************************************************************************************************
 *  StbM_GetCurrentTimeDiff()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeDiff(
  StbM_TimeStampRawType givenTimeStamp,
  P2VAR(StbM_TimeStampRawType, AUTOMATIC, STBM_APPL_VAR) timeStampDiffPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  uint32 ticks;
  uint32 currentNanoseconds;
#if (STBM_GPT_LOCALTIME_USED == STD_OFF)
  TickType osTicks;
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeStampDiffPtr' */
  else if (timeStampDiffPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (STBM_GPT_LOCALTIME_USED == STD_ON)
    ticks = (uint32)Gpt_GetTimeElapsed((Gpt_ChannelType)STBM_MOST_ACCURATE_LOCALTIME_ID);
#else
    (void)GetCounterValue(STBM_MOST_ACCURATE_LOCALTIME_ID, &osTicks);
    ticks = (uint32)osTicks;
#endif
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    currentNanoseconds = ticks * STBM_MOST_ACCURATE_LOCALTIME_NSPERTICK;
    if (currentNanoseconds < STBM_TIMESTAMP_RAW_NANOSECONDS(givenTimeStamp))
    {
      STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(timeStampDiffPtr) = (STBM_TIMESTAMPDIFF_MAX_NANOSECONDS - STBM_TIMESTAMP_RAW_NANOSECONDS(givenTimeStamp)) + (1U + currentNanoseconds);
    }
    else
    {
      STBM_TIMESTAMP_RAW_PTR_NANOSECONDS(timeStampDiffPtr) = currentNanoseconds - STBM_TIMESTAMP_RAW_NANOSECONDS(givenTimeStamp);
    }
    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retVal = E_OK;
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_GET_CURRENT_TIME_DIFF, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_GetCurrentTimeDiff() */

/**********************************************************************************************************************
 *  StbM_SetGlobalTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_SetGlobalTime(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
  P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  TickType osTicks;
#if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
  Eth_TimeStampQualType ethIfTimeQual;
  Eth_TimeStampType ethIfTimeStamp;
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeBaseId' */
  else if (timeBaseId >= STBM_TIMEBASE_COUNT)
  {
    errorId = STBM_E_PARAM;
  }
  /* Check parameter 'timeStampPtr' */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* Check parameter 'userDataPtr' */
  else if (userDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    StbM_TimeBaseState[timeBaseId].TimeStamp = *timeStampPtr;
    StbM_TimeBaseState[timeBaseId].UserData = *userDataPtr;

    /* set the globalTimeBase bit within TimeBaseStatus, clear all other bits */
    StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus = StbM_Global_Time_Base_BflMask;

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* get counter value of last update of local time */
#if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
    if (StbM_TimeBaseConfig[timeBaseId].UsesEthTSynLocalTime == TRUE)
    {
      SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      retVal = EthIf_GetCurrentTime(StbM_TimeBaseConfig[timeBaseId].EthIfCtrlIdx, &ethIfTimeQual, &ethIfTimeStamp);
      if ((retVal == E_OK) && (ethIfTimeQual == ETH_VALID))
      {
        StbM_TimeBaseState[timeBaseId].LocalTime = ethIfTimeStamp;
      }
      SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
    else
#endif
    {
      if (StbM_IsOsLocalTimeUsed(timeBaseId))
      {
        (void)GetCounterValue((CounterType)StbM_TimeBaseConfig[timeBaseId].LocalTimeID, &osTicks);
        SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        StbM_TimeBaseState[timeBaseId].LocalTimeTickValue = (uint32)osTicks;
        SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
#if (STBM_GPT_LOCALTIME_USED == STD_ON)
      else
      {
        if (StbM_IsGptLocalTimeUsed(timeBaseId))
        {
          SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          StbM_TimeBaseState[timeBaseId].LocalTimeTickValue = (uint32)Gpt_GetTimeElapsed((Gpt_ChannelType)StbM_TimeBaseConfig[timeBaseId].LocalTimeID);
          SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }
      }
#endif
      retVal = E_OK;
    }
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_SET_GLOBAL_TIME, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_SetGlobalTime() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  StbM_SetUserData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_SetUserData(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeBaseId' */
  else if (timeBaseId >= STBM_TIMEBASE_COUNT)
  {
    errorId = STBM_E_PARAM;
  }
  /* Check parameter 'userDataPtr' */
  else if (userDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    StbM_TimeBaseState[timeBaseId].UserData = *userDataPtr;
    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retVal = E_OK;
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_SET_USER_DATA, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_SetUserData() */

/**********************************************************************************************************************
 *  StbM_SetOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_SetOffset(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeBaseId' */
  else if ((timeBaseId >= STBM_TIMEBASE_COUNT) || (!StbM_IsOffsetTimeBase(timeBaseId)))
  {
    errorId = STBM_E_PARAM;
  }
  /* Check parameter 'timeStampPtr' */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* set globalTimeBase bit */
    StbM_SetGlobalTimeBaseBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus);

    StbM_TimeBaseState[timeBaseId].TimeStamp.nanoseconds = timeStampPtr->nanoseconds;
    StbM_TimeBaseState[timeBaseId].TimeStamp.seconds = timeStampPtr->seconds;
    StbM_TimeBaseState[timeBaseId].TimeStamp.secondsHi = timeStampPtr->secondsHi;

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retVal = E_OK;
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_SET_OFFSET, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_SetOffset() */

/**********************************************************************************************************************
 *  StbM_GetOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetOffset(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeBaseId' */
  else if ((timeBaseId >= STBM_TIMEBASE_COUNT) || (!StbM_IsOffsetTimeBase(timeBaseId)))
  {
    errorId = STBM_E_PARAM;
  }
  /* Check parameter 'timeStampPtr' */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    *timeStampPtr = StbM_TimeBaseState[timeBaseId].TimeStamp;
    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retVal = E_OK;
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_GET_OFFSET, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

return retVal;

} /* StbM_GetOffset() */

/**********************************************************************************************************************
 *  StbM_BusSetGlobalTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_BusSetGlobalTime(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
  P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr,
  boolean syncToTimeBase) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_TimeStampType diffTimeStamp;
  uint16 lastRateMeasurement;
  sint32 diffGlobalTime;
  uint32 diffGlobalTimeAbs;
  StbM_TimeStampType synchronizedTimeStamp;
  StbM_UserDataType synchronizedUserData;
  sint32 diffLocalTime;
  boolean startNewRateMeasurement = FALSE;
  uint32 rateMeasurementOffset;
  TickType osTicks;
#if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
  Eth_TimeStampQualType ethIfTimeQual;
  Eth_TimeStampType ethIfTimeStamp;
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeBaseId' */
  else if (timeBaseId >= STBM_TIMEBASE_COUNT)
  {
    errorId = STBM_E_PARAM;
  }
  /* Check parameter 'timeStampPtr' */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = E_OK;

    /* update local time base */
    if (!StbM_IsOffsetTimeBase(timeBaseId))
    {
      retVal = StbM_UpdateTimestamp(timeBaseId);
    }

    if (retVal == E_OK)
    {
      SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* check if configured threshold is exceeded with update time stamp */
      if ((StbM_TimeBaseConfig[timeBaseId].SyncLossThresholdSec > 0U) || (StbM_TimeBaseConfig[timeBaseId].SyncLossThresholdNsec > 0U))
      {
        /* calculate absolute time difference */
        if ((timeStampPtr->secondsHi > StbM_TimeBaseState[timeBaseId].TimeStamp.secondsHi) ||
            ((timeStampPtr->secondsHi == StbM_TimeBaseState[timeBaseId].TimeStamp.secondsHi) && (timeStampPtr->seconds > StbM_TimeBaseState[timeBaseId].TimeStamp.seconds)) ||
            ((timeStampPtr->secondsHi == StbM_TimeBaseState[timeBaseId].TimeStamp.secondsHi) && (timeStampPtr->seconds == StbM_TimeBaseState[timeBaseId].TimeStamp.seconds) && (timeStampPtr->nanoseconds > StbM_TimeBaseState[timeBaseId].TimeStamp.nanoseconds)))
        {
          retVal = StbM_TimestampMinusTimestamp(timeStampPtr, &StbM_TimeBaseState[timeBaseId].TimeStamp, &diffTimeStamp);
        }
        else
        {
          retVal = StbM_TimestampMinusTimestamp(&StbM_TimeBaseState[timeBaseId].TimeStamp, timeStampPtr, &diffTimeStamp);
        }
        if (retVal == E_OK)
        {
          if ((diffTimeStamp.seconds > StbM_TimeBaseConfig[timeBaseId].SyncLossThresholdSec) || 
              ((diffTimeStamp.seconds == StbM_TimeBaseConfig[timeBaseId].SyncLossThresholdSec) && (diffTimeStamp.nanoseconds > StbM_TimeBaseConfig[timeBaseId].SyncLossThresholdNsec)))
          {
            /* set timeleap bit since threshold is exceeded */
            StbM_SetTimeleapBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus);
          }
          else
          {
            /* clear timeleap bit */
            StbM_ClearTimeleapBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus);
          }
        }
      }

      /* set syncToGateway bit according syncToTimeBase parameter */
      if (syncToTimeBase == TRUE)
      {
        StbM_SetSyncToGatewayBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus);
      }
      else
      {
        StbM_ClearSyncToGatewayBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus);
      }

      /* set globalTimeBase bit */
      StbM_SetGlobalTimeBaseBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus);

      if (retVal == E_OK)
      {
        /* rate correction measurement */
        if (StbM_TimeBaseConfig[timeBaseId].RateCorrectionMeasurementDuration > 0U)
        {
          /* evaluate index of current measurement */
          lastRateMeasurement = StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement;
          if (StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement == (StbM_TimeBaseConfig[timeBaseId].RateCorrectionsPerMeasurementDuration - 1U))
          {
            StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement = 0U;
          }
          else
          {
            StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement++;
          }

          /* check if the current measurement was started before */
          if ((StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime.nanoseconds > 0U) ||
              (StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime.seconds > 0U) ||
              (StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime.secondsHi > 0U))
          {
            retVal = StbM_TimestampMinusTimestampInNs(timeStampPtr, &StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime, &diffGlobalTime);
            /* check if measurement duration has passed */
            diffGlobalTimeAbs = StbM_GetAbsoluteValue(diffGlobalTime);
            if ((retVal == E_OK) && (diffGlobalTimeAbs >= StbM_TimeBaseConfig[timeBaseId].RateCorrectionMeasurementDuration))
            {
              /* calculate rate correction if state of the time base has not changed during measurement */
              if (StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus == StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime.timeBaseStatus)
              {
                if (StbM_IsOffsetTimeBase(timeBaseId))
                {
                  retVal = StbM_GetCurrentTime(StbM_TimeBaseConfig[timeBaseId].OffsetTimeBaseId, &synchronizedTimeStamp, &synchronizedUserData);
                  if (retVal == E_OK)
                  {
                    retVal = StbM_TimestampMinusTimestampInNs(&synchronizedTimeStamp, &StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartLocalTime, &diffLocalTime);
                    if (retVal == E_OK)
                    {
                      StbM_TimeBaseState[timeBaseId].RateCorrection = ((diffLocalTime + diffGlobalTime) / diffLocalTime);
                    }
                  }
                }
                else
                {
                  retVal = StbM_TimestampMinusTimestampInNs(&StbM_TimeBaseState[timeBaseId].TimeStamp, &StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime, &diffLocalTime);
                  if (retVal == E_OK)
                  {
                    StbM_TimeBaseState[timeBaseId].RateCorrection = (diffGlobalTime / diffLocalTime);
                  }
                }
              }

              startNewRateMeasurement = TRUE;
            }
          }
          else if (StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement > 0U)
          {
            /* start new measurement if offset has passed */
            rateMeasurementOffset = StbM_TimeBaseConfig[timeBaseId].RateCorrectionMeasurementDuration / StbM_TimeBaseConfig[timeBaseId].RateCorrectionsPerMeasurementDuration;
            retVal = StbM_TimestampMinusTimestampInNs(timeStampPtr, &StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement - 1U].StartGlobalTime, &diffGlobalTime);
            diffGlobalTimeAbs = StbM_GetAbsoluteValue(diffGlobalTime);
            if ((retVal == E_OK) && (diffGlobalTimeAbs >= rateMeasurementOffset))
            {
              startNewRateMeasurement = TRUE;
            }
          }
          else
          {
            /* start first measurement */
            startNewRateMeasurement = TRUE;
          }

          if (startNewRateMeasurement && (StbM_GetTimeleapBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus) == 0U))
          {
            StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime = *timeStampPtr;
            StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartGlobalTime.timeBaseStatus = StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus;

            if (StbM_IsOffsetTimeBase(timeBaseId))
            {
              retVal = StbM_GetCurrentTime(StbM_TimeBaseConfig[timeBaseId].OffsetTimeBaseId, &synchronizedTimeStamp, &synchronizedUserData);
              if (retVal == E_OK)
              {
                StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartLocalTime = synchronizedTimeStamp;
              }
            }
            else
            {
              StbM_TimeBaseState[timeBaseId].RateMeasurement[StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement].StartLocalTime = StbM_TimeBaseState[timeBaseId].TimeStamp;
            }
          }
          else
          {
            StbM_TimeBaseState[timeBaseId].CurrentRateMeasurement = lastRateMeasurement;
          }
        }
      }

      /* clear timeout bit */
      StbM_ClearTimeoutBit(StbM_TimeBaseState[timeBaseId].TimeStamp.timeBaseStatus);
      /* start new measuring of timeout */
      StbM_TimeBaseState[timeBaseId].SyncLossTimeoutCount = StbM_TimeBaseConfig[timeBaseId].SyncLossTimeout;

      StbM_TimeBaseState[timeBaseId].TimeStamp.nanoseconds = timeStampPtr->nanoseconds;
      StbM_TimeBaseState[timeBaseId].TimeStamp.seconds = timeStampPtr->seconds;
      StbM_TimeBaseState[timeBaseId].TimeStamp.secondsHi = timeStampPtr->secondsHi;

      if (userDataPtr != NULL_PTR)
      {
        StbM_TimeBaseState[timeBaseId].UserData = *userDataPtr;
      }

      SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      if (!StbM_IsOffsetTimeBase(timeBaseId))
      {
        /* get counter value of last update of local time */
        if (StbM_IsOsLocalTimeUsed(timeBaseId))
        {
          (void)GetCounterValue((CounterType)StbM_TimeBaseConfig[timeBaseId].LocalTimeID, &osTicks);
          SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          StbM_TimeBaseState[timeBaseId].LocalTimeTickValue = (uint32)osTicks;
          SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }

#if (STBM_GPT_LOCALTIME_USED == STD_ON)
        if (StbM_IsGptLocalTimeUsed(timeBaseId))
        {
          SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          StbM_TimeBaseState[timeBaseId].LocalTimeTickValue = (uint32)Gpt_GetTimeElapsed((Gpt_ChannelType)StbM_TimeBaseConfig[timeBaseId].LocalTimeID);
          SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }
#endif

#if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
        if (StbM_TimeBaseConfig[timeBaseId].UsesEthTSynLocalTime == TRUE)
        {
          SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          retVal = EthIf_GetCurrentTime(StbM_TimeBaseConfig[timeBaseId].EthIfCtrlIdx, &ethIfTimeQual, &ethIfTimeStamp);
          if ((retVal == E_OK) && (ethIfTimeQual == ETH_VALID))
          {
            StbM_TimeBaseState[timeBaseId].LocalTime = ethIfTimeStamp;
          }
          SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }
#endif
      }
    }
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_BUS_SET_GLOBAL_TIME, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_BusSetGlobalTime() */ /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  StbM_GetRateDeviation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetRateDeviation(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2VAR(StbM_RateDeviationType, AUTOMATIC, STBM_APPL_VAR) rateDeviation) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeBaseId' */
  else if ((timeBaseId >= STBM_TIMEBASE_COUNT) || StbM_IsOffsetTimeBase(timeBaseId))
  {
    errorId = STBM_E_PARAM;
  }
  /* Check parameter 'rateDeviation' */
  else if (rateDeviation == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    if (StbM_TimeBaseState[timeBaseId].RateCorrection != 0)
    {
      *rateDeviation = StbM_TimeBaseState[timeBaseId].RateCorrection - 1;
      retVal = E_OK;
    }

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_GET_RATE_DEVIATION, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_GetRateDeviation() */

/**********************************************************************************************************************
 *  StbM_SetRateCorrection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_SetRateCorrection(
  StbM_SynchronizedTimeBaseType timeBaseId,
  StbM_RateDeviationType rateDeviation) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (StbM_ModuleInitialized == (uint8)STBM_UNINIT)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* Check parameter 'timeBaseId' */
  else if (timeBaseId >= STBM_TIMEBASE_COUNT)
  {
    errorId = STBM_E_PARAM;
  }
  /* Check if service is enabled */
  else if (StbM_TimeBaseConfig[timeBaseId].IsMasterRateCorrectionAllowed == FALSE)
  {
    errorId = STBM_E_SERVICE_DISABLED;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    if (StbM_TimeBaseConfig[timeBaseId].IsMasterRateCorrectionAllowed == TRUE)
    {
      if (rateDeviation > StbM_TimeBaseConfig[timeBaseId].MasterRateDeviationMax)
      {
        StbM_TimeBaseState[timeBaseId].RateCorrection = StbM_TimeBaseConfig[timeBaseId].MasterRateDeviationMax;
      }
      else if (rateDeviation < -StbM_TimeBaseConfig[timeBaseId].MasterRateDeviationMax)
      {
        StbM_TimeBaseState[timeBaseId].RateCorrection = -StbM_TimeBaseConfig[timeBaseId].MasterRateDeviationMax;
      }
      else
      {
        StbM_TimeBaseState[timeBaseId].RateCorrection = rateDeviation + 1;
      }

      retVal = E_OK;
    }

    SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

#if (STBM_DEV_ERROR_DETECT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    (void)Det_ReportError(STBM_MODULE_ID, STBM_INSTANCE_ID_DET, STBM_SID_SET_RATE_CORRECTION, errorId);
  }
#else
  DUMMY_STATEMENT(errorId); /* PRQA S 3199, 3112 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return retVal;

} /* StbM_SetRateCorrection() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

#define STBM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
 MD_StbM_3670: rule 16.2
      Reason:     Function needs to be called recursive for the referenced synchronized time base of an offset time base, but there could be at most one recursive call.
      Risk:       Runtime failure might be introduced by later code changes.
      Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: StbM.c
 *********************************************************************************************************************/
