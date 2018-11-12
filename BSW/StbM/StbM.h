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
 *        \brief  Vector AUTOSAR StbM header file
 *
 *      \details  This is the main header file of the Vector AUTOSAR module StbM.

 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Stephanie Schaaf              visssf        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2012-11-05  visssf  ESCAN00060987 AR4-165: Provide AR4 compliant module StbM
 *  01.01.00  2013-04-12  visssf  ESCAN00066630 Compiler error: Missing FrIf.h when the configuration contains no FlexRay
 *            2013-05-03  visssf  ESCAN00067123 Missing exclusive area protection may lead to data inconsistency
 *  02.00.00  2013-09-06  visssf  ESCAN00070221 Compiler warning: file does not end in newline
 *  03.00.00  2014-09-18  visssf  ESCAN00077484 AR4-664: Support new global time synchronization concept
 *  03.01.00  2014-12-02  visssf  ESCAN00079950 FEAT-971: Complete support of new global time synchronization concept
 *  03.01.01  2015-03-02  visssf  ESCAN00081461 Compiler error: 'Boolean' : name in formal parameter list illegal
 *            2015-03-20  visssf  ESCAN00081652 Wrong calculation of time difference for setting timeleap bit
 *  03.02.00  2015-07-14  visssf  ESCAN00083401 StbM_TimeStampRawType is not compatible to AR 4.2.1
 *  04.00.00  2015-12-22  visssf  ESCAN00085766 FEAT-1531: Support of High Resolution Time Base Reference Clock based on GPT
 *            2016-01-05  visssf  ESCAN00083451 Missing call of EthTSyn_SetGlobalTime() in StbM_SetGlobalTime() if EthTSynHardwareTimestampSupport is set to True
 *  04.01.00  2016-02-26  visssf  ESCAN00088200 FEAT-1694: Support Time Gateway
 *            2016-03-14  visssf  ESCAN00088690 TimeStamp is updated with wrong value when OsCounter is used as local time
 *            2016-03-15  visssf  ESCAN00088923 Missing interrupt locks
 *            2016-03-18  visssf  ESCAN00087326 MISRA deviation: MISRA-C:2004 Rules 12.8, 5.6, 14.3, 16.10, 13.2, 12.1, 12.5, 19.10, 19.7, 12.6 and HIS Metrics
 *            2016-03-30  visssf  ESCAN00089136 TimeBaseStatus is cleared when EthGlobalTimeDomain referenced as local time is in state ETHTSYN_UNCERTAIN
 *            2016-03-30  visssf  ESCAN00089139 SyncScheduleTable is called with <Value> out of range
 *  04.01.01  2016-04-12  visssf  ESCAN00089411 StbM_GetCurrentTimeRaw() and StbM_GetCurrentTimeDiff() return wrong time values
 *            2016-04-13  visssf  ESCAN00089428 SyncScheduleTable is called with <Value> out of range
 *  04.02.00  2017-03-07  visssf  FEATC-644     FEAT-2279: Time Synchronization acc. to AR 4.3 [Feature Pack 1]
 *            2017-03-14  visssf  ESCAN00094362 Already running GPT channel is started again
 *********************************************************************************************************************/

#if !defined (STBM_H)
# define STBM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "StbM_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define STBM_VENDOR_ID                                (30U)
# define STBM_MODULE_ID                                (0xA0U)

/* AUTOSAR Software specification version information */
# define STBM_AR_RELEASE_MAJOR_VERSION                 (0x04U)
# define STBM_AR_RELEASE_MINOR_VERSION                 (0x03U)
# define STBM_AR_RELEASE_REVISION_VERSION              (0x00U)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define STBM_SW_MAJOR_VERSION                         (4U)
# define STBM_SW_MINOR_VERSION                         (2U)
# define STBM_SW_PATCH_VERSION                         (0U)

# define STBM_INSTANCE_ID_DET                          (0x00U)

/* ----- API service IDs ----- */
# define STBM_SID_INIT                                 (0x00U) /*!< Service ID: StbM_Init() */
# define STBM_SID_MAIN_FUNCTION                        (0x04U) /*!< Service ID: StbM_MainFunction() */
# define STBM_SID_GET_VERSION_INFO                     (0x05U) /*!< Service ID: StbM_GetVersionInfo() */
# define STBM_SID_GET_CURRENT_TIME                     (0x07U) /*!< Service ID: StbM_GetCurrentTime() */
# define STBM_SID_GET_CURRENT_TIME_EXTENDED            (0x08U) /*!< Service ID: StbM_GetCurrentTimeExtended() */
# define STBM_SID_GET_CURRENT_TIME_RAW                 (0x09U) /*!< Service ID: StbM_GetCurrentTimeRaw() */
# define STBM_SID_GET_CURRENT_TIME_DIFF                (0x0AU) /*!< Service ID: StbM_GetCurrentTimeDiff() */
# define STBM_SID_SET_GLOBAL_TIME                      (0x0BU) /*!< Service ID: StbM_SetGlobalTime() */
# define STBM_SID_SET_USER_DATA                        (0x0CU) /*!< Service ID: StbM_SetUserData() */
# define STBM_SID_SET_OFFSET                           (0x0DU) /*!< Service ID: StbM_SetOffset() */
# define STBM_SID_GET_OFFSET                           (0x0EU) /*!< Service ID: StbM_GetOffset() */
# define STBM_SID_BUS_SET_GLOBAL_TIME                  (0x0FU) /*!< Service ID: StbM_BusSetGlobalTime() */
# define STBM_SID_GET_RATE_DEVIATION                   (0x11U) /*!< Service ID: StbM_GetRateDeviation() */
# define STBM_SID_SET_RATE_CORRECTION                  (0x12U) /*!< Service ID: StbM_SetRateCorrection() */

# define STBM_SID_TIMESTAMP_PLUS_TIMESTAMP             (0xA0U) /*!< Service ID: StbM_TimestampPlusTimestamp() */
# define STBM_SID_TIMESTAMP_MINUS_TIMESTAMP            (0xA1U) /*!< Service ID: StbM_TimestampMinusTimestamp() */
# define STBM_SID_TIMESTAMP_MINUS_TIMESTAMP_IN_NS      (0xA2U) /*!< Service ID: StbM_TimestampMinusTimestampInNs() */
# define STBM_SID_TIMESTAMP_PLUS_TIMEDIFF              (0xA3U) /*!< Service ID: StbM_TimestampPlusTimediff() */

/* ----- Error codes ----- */
# define STBM_E_NO_ERROR                               (0x00U) /*!< used to check if no error occurred */
# define STBM_E_PARAM                                  (0x0AU) /*!< Error code: API service called with wrong parameter */
# define STBM_E_NOT_INITIALIZED                        (0x0BU) /*!< Error code: API service used without module initialization  */
# define STBM_E_PARAM_POINTER                          (0x10U) /*!< Error code: API service called with NULL_PTR as parameter  */
# define STBM_E_SERVICE_DISABLED                       (0x12U) /*!< Error code: API service called that is disabled by configuration */

/* ----- Modes ----- */
# define STBM_UNINIT                                   (0x00U)
# define STBM_INIT                                     (0x01U)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define STBM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Service functions */

/**********************************************************************************************************************
 *  StbM_InitMemory()
 *********************************************************************************************************************/
/*! \brief      Function for *_INIT_*-variable initialization
 *  \details    Service to initialize module global variables at power up. This function can be used to initialize the
 *              variables in *_INIT_* sections in case they are not initialized by the startup code.
 *  \pre        Module is uninitialized.
 *  \context    TASK
**********************************************************************************************************************/
FUNC(void, STBM_CODE) StbM_InitMemory(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_Init()
 *********************************************************************************************************************/
/*! \brief      Initialization function
 *  \details    This function initializes the module StbM. It initializes all variables and sets the module state to
 *              initialized.
 *  \pre        Interrupts are disabled.
 *  \pre        Module is uninitialized.
 *  \pre        StbM_InitMemory has been called unless StbM_ModuleInitialized is initialized by start-up code.
 *  \note       Specification of module initialization
 *********************************************************************************************************************/
FUNC(void, STBM_CODE) StbM_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_MainFunction()
 *********************************************************************************************************************/
/*! \brief      Main function
 *  \details    This function gets time information from providers and triggers customers.
 *  \pre        Module is initialized.
 *  \context    This function is called by Autosar SchM.
 *********************************************************************************************************************/
FUNC(void, STBM_CODE) StbM_MainFunction(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief      Returns the version information
 *  \details    StbM_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out] versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(void, STBM_CODE) StbM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, STBM_APPL_VAR) versioninfo); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_GetCurrentTime()
 *********************************************************************************************************************/
/*! \brief      Returns the current time in standard format
 *  \details    This function returns the current time of the submitted time-base in standard format.
 *  \param[in]  timeBaseId              The synchronized time-base, whose time is of interest.
 *  \param[out] timeStampPtr            Current time stamp in standard format.
 *  \param[out] userDataPtr             User data of the time base.
 *  \return     E_OK - Timestamp is valid
 *  \return     E_NOT_OK - Timestamp is invalid
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTime(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr,
  P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userDataPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# if (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON)
/**********************************************************************************************************************
 *  StbM_GetCurrentTimeExtended()
 *********************************************************************************************************************/
/*! \brief      Returns the current time in extended format
 *  \details    This function returns the current time of the submitted time-base in extended format.
 *  \param[in]  timeBaseId              The synchronized time-base, whose time is of interest.
 *  \param[out] timeStampPtr            Current time stamp in extended format.
 *  \param[out] userDataPtr             User data of the time base.
 *  \return     E_OK - Timestamp is valid
 *  \return     E_NOT_OK - Timestamp is invalid
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeExtended(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2VAR(StbM_TimeStampExtendedType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr,
  P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userDataPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *  StbM_GetCurrentTimeRaw()
 *********************************************************************************************************************/
/*! \brief      Returns time value in raw format from most accurate time source
 *  \details    This function returns a time value in raw format from the most accurate time source.
 *  \param[out] timeStampPtr            Current time stamp in raw format.
 *  \return     E_OK - Timestamp is valid
 *  \return     E_NOT_OK - Timestamp is invalid
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeRaw(P2VAR(StbM_TimeStampRawType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_GetCurrentTimeDiff()
 *********************************************************************************************************************/
/*! \brief      Returns difference of current time raw minus given time raw
 *  \details    This function returns the time difference of current time raw minus given time raw by using the most accurate time source.
 *  \param[in]  givenTimeStamp          Given time stamp as as difference calculation basis.
 *  \param[out] timeStampDiffPtr        Time difference of current time stamp minus given time stamp.
 *  \return     E_OK - Time difference is valid
 *  \return     E_NOT_OK - Time difference is invalid
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeDiff(
  StbM_TimeStampRawType givenTimeStamp,
  P2VAR(StbM_TimeStampRawType, AUTOMATIC, STBM_APPL_VAR) timeStampDiffPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_SetGlobalTime()
 *********************************************************************************************************************/
/*! \brief      Sets new global time
 *  \details    This function allows the customers to set the new global time.
 *  \param[in]  timeBaseId              The synchronized time-base, whose time is set.
 *  \param[in]  timeStampPtr            New time stamp.
 *  \param[in]  userDataPtr             New user data.
 *  \return     E_OK - New global time was set
 *  \return     E_NOT_OK - New global time was not set
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_SetGlobalTime(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
  P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_SetUserData()
 *********************************************************************************************************************/
/*! \brief      Sets new user data
 *  \details    This function allows the customers to set the new user data.
 *  \param[in]  timeBaseId              The synchronized time-base, whose user data is set.
 *  \param[in]  userDataPtr             New user data.
 *  \return     E_OK - New user data was set
 *  \return     E_NOT_OK - New user data was not set
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_SetUserData(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_SetOffset()
 *********************************************************************************************************************/
/*! \brief      Sets the offset time
 *  \details    This function allows the customers and the time base provider modules to set the offset time.
 *  \param[in]  timeBaseId              The synchronized time-base, whose offset time is set.
 *  \param[in]  timeStampPtr            New offset time stamp.
 *  \return     E_OK - New offset time was set
 *  \return     E_NOT_OK - New offset time was not set
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_SetOffset(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_GetOffset()
 *********************************************************************************************************************/
/*! \brief      Returns the current offset time
 *  \details    This function allows the time base provider modules to get the current offset time.
 *  \param[in]  timeBaseId              The synchronized time-base, whose offset time is of interest.
 *  \param[out] timeStampPtr            Current offset time stamp.
 *  \return     E_OK - Timestamp is valid
 *  \return     E_NOT_OK - Timestamp is invalid
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetOffset(
  StbM_SynchronizedTimeBaseType timeBaseId,
  P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_BusSetGlobalTime()
 *********************************************************************************************************************/
/*! \brief      Sets new global time
 *  \details    This function allows the time base provider modules to set the new global time.
 *  \param[in]  timeBaseId              The synchronized time-base, whose time is set.
 *  \param[in]  timeStampPtr            New time stamp.
 *  \param[in]  userDataPtr             New user data.
 *  \param[in]  syncToTimeBase          Status of the time-base.
 *  \return     E_OK - New global time was set
 *  \return     E_NOT_OK - New global time was not set
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_BusSetGlobalTime(
StbM_SynchronizedTimeBaseType timeBaseId,
P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr,
boolean syncToTimeBase); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_GetRateDeviation()
 *********************************************************************************************************************/
/*! \brief      Returns the current rate deviation
 *  \details    This function allows the customers to get the current rate deviation.
 *  \param[in]  timeBaseId              The synchronized time-base, whose rate deviation is of interest.
 *  \param[out] rateDeviation           Current rate deviation.
 *  \return     E_OK - Rate deviation is valid
 *  \return     E_NOT_OK - Rate deviation is invalid
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_GetRateDeviation(
StbM_SynchronizedTimeBaseType timeBaseId,
P2VAR(StbM_RateDeviationType, AUTOMATIC, STBM_APPL_VAR) rateDeviation); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *  StbM_SetRateCorrection()
 *********************************************************************************************************************/
/*! \brief      Sets rate of a time base
 *  \details    This function allows the customers to set the rate of a synchronized time base.
 *  \param[in]  timeBaseId              The synchronized time-base, whose rate is set.
 *  \param[in]  rateDeviation           New rate.
 *  \return     E_OK - New rate was set
 *  \return     E_NOT_OK - New rate was not set
 *  \pre        Module is initialized.
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, STBM_CODE) StbM_SetRateCorrection(
StbM_SynchronizedTimeBaseType timeBaseId,
StbM_RateDeviationType rateDeviation); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define STBM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* STBM_H */

/**********************************************************************************************************************
 *  END OF FILE: StbM.h
 *********************************************************************************************************************/
