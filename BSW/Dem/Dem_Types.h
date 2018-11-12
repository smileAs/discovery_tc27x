
/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dem_Types.h
 *      Project:  MICROSAR Diagnostic Event Manager (Dem)
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Static public API declarations of the MICROSAR Dem.
 *                Dynamically available APIs are declared in the generated file Rte_Dem.h
 *
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Stefan Huebner                vishrs        Vector Informatik GmbH
 *  Alexander Ditte               visade        Vector Informatik GmbH
 *  Matthias Heil                 vismhe        Vector Informatik GmbH
 *  Thomas Dedler                 visdth        Vector Informatik GmbH
 *  Anna Bosch                    visanh        Vector Informatik GmbH
 *  Savas Ates                    vissat        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_TYPES_H)
#define DEM_TYPES_H

/* ********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

                                                   /* AUTOSAR standard types */
/* ------------------------------------------------------------------------- */
#include "Std_Types.h"
/* ------------------------------------------------------------------------- */

                                             /* Global configuration options */
/* ------------------------------------------------------------------------- */
#include "Dem_Cfg.h"
/* ------------------------------------------------------------------------- */

                                                  /* RTE generated Dem types */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_USE_RTE == STD_ON)
# include "Rte_Dem_Type.h"
#else
# include "Dem_Cdd_Types.h"
#endif
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (DEM_LOCAL)                                                                                                         /* COV_MSR_COMPATIBILITY XF */
/*! Dem private function linkage */
# define DEM_LOCAL                               static
#endif

#if !defined (DEM_LOCAL_INLINE)                                                                                                  /* COV_MSR_COMPATIBILITY XF */
/*! Dem private inline function linkage */
# define DEM_LOCAL_INLINE                        LOCAL_INLINE
#endif

#if (DEM_CFG_SUPPORT_SPLIT_TASKS == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED XF */
/*! Dem task function linkage */
# define DEM_MAINFUNC_LINKAGE
#else
/*! Dem task function linkage */
# define DEM_MAINFUNC_LINKAGE                    DEM_LOCAL_INLINE
#endif

/* ********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*!
 * \defgroup  Dem_DTCRequestType
 * \{
 */
/*! This type is used to request a DTC with specific attributes. */
typedef uint8                                    Dem_DTCRequestType;
#define DEM_FIRST_FAILED_DTC                     ((Dem_DTCRequestType)(0x01U))  /*!< first failed DTC requested */
#define DEM_MOST_RECENT_FAILED_DTC               ((Dem_DTCRequestType)(0x02U))  /*!< most recent failed DTC requested */
#define DEM_FIRST_DET_CONFIRMED_DTC              ((Dem_DTCRequestType)(0x03U))  /*!< first detected confirmed DTC requested */
#define DEM_MOST_REC_DET_CONFIRMED_DTC           ((Dem_DTCRequestType)(0x04U))  /*!< most recently detected confirmed DTC requested */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_DTCTranslationFormatType
 * \{
 */
/*! DTC translation format as defined in ISO14229-1 Service 0x19 returned by Dem_DcmGetTranslationType(). */
typedef uint8                                    Dem_DTCTranslationFormatType;
#define DEM_DTC_TRANSLATION_ISO15031_6           ((Dem_DTCTranslationFormatType)(0x00U))  /*!< DTC format ISO 15031-6 / SAE J2012-DA_DTCFormat_00 */
#define DEM_DTC_TRANSLATION_ISO14229_1           ((Dem_DTCTranslationFormatType)(0x01U))  /*!< DTC format ISO 14229-1 */
#define DEM_DTC_TRANSLATION_SAEJ1939_73          ((Dem_DTCTranslationFormatType)(0x02U))  /*!< DTC format SAE J1939-73 */
#define DEM_DTC_TRANSLATION_ISO11992_4           ((Dem_DTCTranslationFormatType)(0x03U))  /*!< DTC format ISO 11992-4 */
#define DEM_DTC_TRANSLATION_J2012DA_FORMAT_04    ((Dem_DTCTranslationFormatType)(0x04U))  /*!< DTC format SAE_J2012-DA_DTCFormat_04 */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_FilterForFDCType
 * \{
 */
/*! DTC filter selector for fault detection counter */
typedef uint8                                    Dem_FilterForFDCType;
#define DEM_FILTER_FOR_FDC_YES                   ((Dem_FilterForFDCType)(0x00U))  /*!< Fault Detection Counter information used */
#define DEM_FILTER_FOR_FDC_NO                    ((Dem_FilterForFDCType)(0x01U))  /*!< Fault Detection Counter information not used */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_FilterWithSeverityType
 * \{
 */
/*! DTC filter selector for DTC severity */
typedef uint8                                    Dem_FilterWithSeverityType;
#define DEM_FILTER_WITH_SEVERITY_YES             ((Dem_FilterWithSeverityType)(0x00U))  /*!< Severity information used */
#define DEM_FILTER_WITH_SEVERITY_NO              ((Dem_FilterWithSeverityType)(0x01U))  /*!< Severity information not used */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnSetFilterType
 * \{
 */
/*! Used to return the status of (re-)setting a specific filter. */
typedef uint8                                    Dem_ReturnSetFilterType;
#define DEM_FILTER_ACCEPTED                      ((Dem_ReturnSetFilterType)(0x00U))  /*!< Filter was accepted */
#define DEM_WRONG_FILTER                         ((Dem_ReturnSetFilterType)(0x01U))  /*!< Wrong filter selected */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnGetStatusOfDTCType
 * \{
 */
/*! Used to return the status of Dem_DcmGetStatusOfDTC. */
typedef uint8                                    Dem_ReturnGetStatusOfDTCType;
#define DEM_STATUS_OK                            ((Dem_ReturnGetStatusOfDTCType)(0x00U))  /*!< Status of DTC is OK */
#define DEM_STATUS_WRONG_DTC                     ((Dem_ReturnGetStatusOfDTCType)(0x01U))  /*!< DTC value not existing (in this format) */
#define DEM_STATUS_WRONG_DTCORIGIN               ((Dem_ReturnGetStatusOfDTCType)(0x02U))  /*!< Wrong DTC origin */
#define DEM_STATUS_FAILED                        ((Dem_ReturnGetStatusOfDTCType)(0x03U))  /*!< DTC failed */
#define DEM_STATUS_PENDING                       ((Dem_ReturnGetStatusOfDTCType)(0x04U))  /*!< The requested value is calculated asynchronously and currently not available. The caller can retry later.  */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnGetNextFilteredElementType
 * \{
 */
/*! Used to return the status of Dem_DcmGetNextFiltered<X> and Dem_J1939DcmGetNextFiltered<X>. */
typedef uint8                                    Dem_ReturnGetNextFilteredElementType;
#define DEM_FILTERED_OK                          ((Dem_ReturnGetNextFilteredElementType)(0x00U))  /*!< Returned next filtered element */
#define DEM_FILTERED_NO_MATCHING_ELEMENT         ((Dem_ReturnGetNextFilteredElementType)(0x01U))  /*!< No further element (matching the filter criteria) found */
#define DEM_FILTERED_PENDING                     ((Dem_ReturnGetNextFilteredElementType)(0x02U))  /*!< The requested value is calculated asynchronously and currently not available. The caller can retry later. */
#define DEM_FILTERED_BUFFER_TOO_SMALL            ((Dem_ReturnGetNextFilteredElementType)(0x03U))  /*!< Buffer in the BufSize parameter is not large enough  */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnGetNumberOfFilteredDTCType
 * \{
 */
/*! Used to return the status of Dem_DcmGetNumberOfFilteredDTC. */
typedef uint8                                    Dem_ReturnGetNumberOfFilteredDTCType;
#define DEM_NUMBER_OK                            ((Dem_ReturnGetNumberOfFilteredDTCType)(0x00U))  /*!< Getting number of filtered DTCs was successful. */
#define DEM_NUMBER_FAILED                        ((Dem_ReturnGetNumberOfFilteredDTCType)(0x01U))  /*!< Getting number of filtered DTCs failed. */
#define DEM_NUMBER_PENDING                       ((Dem_ReturnGetNumberOfFilteredDTCType)(0x02U))  /*!< The requested value is calculated asynchronously and currently not available. The caller can retry later. */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnClearDTCType
 * \{
 */
/*! Used to return the status of Dem_<*>ClearDTC. */
typedef uint8                                    Dem_ReturnClearDTCType;
#define DEM_CLEAR_OK                             ((Dem_ReturnClearDTCType)(0x00U))  /*!< DTC successfully cleared. */
#define DEM_CLEAR_WRONG_DTC                      ((Dem_ReturnClearDTCType)(0x01U))  /*!< DTC value not existing (in this format) */
#define DEM_CLEAR_WRONG_DTCORIGIN                ((Dem_ReturnClearDTCType)(0x02U))  /*!< Wrong DTC origin. */
#define DEM_CLEAR_FAILED                         ((Dem_ReturnClearDTCType)(0x03U))  /*!< DTC clearing failed. */
#define DEM_CLEAR_PENDING                        ((Dem_ReturnClearDTCType)(0x04U))  /*!< The DTC clearing is performed asynchronously and still pending. The caller can retry later */
#define DEM_CLEAR_BUSY                           ((Dem_ReturnClearDTCType)(0x05U))  /*!< DTC not cleared, as another clearing process is in progress. The caller can retry later. */
#define DEM_CLEAR_MEMORY_ERROR                   ((Dem_ReturnClearDTCType)(0x06U))  /*!< An error occurred during erasing a non-volatile memory location. */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnControlDTCSettingType
 * \{
 */
/*! Used to return the status of Dem_DcmDisableDTCSetting and Dem_DcmEnableDTCSetting. */
typedef uint8                                    Dem_ReturnControlDTCSettingType;
#define DEM_CONTROL_DTC_SETTING_OK               ((Dem_ReturnControlDTCSettingType)(0x00U))  /*!< DTC setting control successful. */
#define DEM_CONTROL_DTC_SETTING_N_OK             ((Dem_ReturnControlDTCSettingType)(0x01U))  /*!< DTC setting control not successful. */
#define DEM_CONTROL_DTC_WRONG_DTCGROUP           ((Dem_ReturnControlDTCSettingType)(0x02U))  /*!< DTC setting control not successful because group of DTC was wrong */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnDisableDTCRecordUpdateType
 * \{
 */
/*! Used to return the status of Dem_DcmDisableDTCRecordUpdate. */
typedef uint8                                    Dem_ReturnDisableDTCRecordUpdateType;
#define DEM_DISABLE_DTCRECUP_OK                  ((Dem_ReturnDisableDTCRecordUpdateType)(0x00U))  /*!< Event memory update of DTC successfully disabled */
#define DEM_DISABLE_DTCRECUP_WRONG_DTC           ((Dem_ReturnDisableDTCRecordUpdateType)(0x01U))  /*!< DTC value not existing (in UDS format) */
#define DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN     ((Dem_ReturnDisableDTCRecordUpdateType)(0x02U))  /*!< Wrong DTC origin */
#define DEM_DISABLE_DTCRECUP_PENDING             ((Dem_ReturnDisableDTCRecordUpdateType)(0x03U))  /*!< Disabling is performed asynchronously and still pending. The caller can retry later */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnGetExtendedDataRecordByDTCType
 * \{
 */
/*! Used to return the status of Dem_DcmGetExtendedDataRecordByDTC. */
typedef uint8                                    Dem_ReturnGetExtendedDataRecordByDTCType;
#define DEM_RECORD_OK                            ((Dem_ReturnGetExtendedDataRecordByDTCType)(0x00U))  /*!< Extended data record successfully returned */
#define DEM_RECORD_WRONG_DTC                     ((Dem_ReturnGetExtendedDataRecordByDTCType)(0x01U))  /*!< DTC value not existing (in UDS format) */
#define DEM_RECORD_WRONG_DTCORIGIN               ((Dem_ReturnGetExtendedDataRecordByDTCType)(0x02U))  /*!< Origin wrong */
#define DEM_RECORD_WRONG_NUMBER                  ((Dem_ReturnGetExtendedDataRecordByDTCType)(0x03U))  /*!< Record number is not supported by configuration and therefore invalid */
#define DEM_RECORD_WRONG_BUFFERSIZE              ((Dem_ReturnGetExtendedDataRecordByDTCType)(0x04U))  /*!< Provided buffer to small */
#define DEM_RECORD_PENDING                       ((Dem_ReturnGetExtendedDataRecordByDTCType)(0x05U))  /*!< The requested value is calculated asynchronously and currently not available. The caller can retry later. */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnGetDTCByOccurrenceTimeType
 * \{
 */
/*! Used to return the status of Dem_DtcGetDTCByOccurrenceTime. */
typedef uint8                                    Dem_ReturnGetDTCByOccurrenceTimeType;
#define DEM_OCCURR_OK                            ((Dem_ReturnGetDTCByOccurrenceTimeType)(0x00U))  /*!< matching DTC available */
#define DEM_OCCURR_NOT_AVAILABLE                 ((Dem_ReturnGetDTCByOccurrenceTimeType)(0x01U))  /*!< no DTC is matching the requested occurrence time */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnGetFreezeFrameDataByDTCType
 * \{
 */
/*! Used to return the status of Dem_DcmGetFreezeFrameDataByDTC. */
typedef uint8                                    Dem_ReturnGetFreezeFrameDataByDTCType;
#define DEM_GET_FFDATABYDTC_OK                   ((Dem_ReturnGetFreezeFrameDataByDTCType)(0x00U))  /*!< Freeze frame data successfully returned. */
#define DEM_GET_FFDATABYDTC_WRONG_DTC            ((Dem_ReturnGetFreezeFrameDataByDTCType)(0x01U))  /*!< DTC value not existing (in UDS format) */
#define DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN      ((Dem_ReturnGetFreezeFrameDataByDTCType)(0x02U))  /*!< Wrong DTC origin */
#define DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER   ((Dem_ReturnGetFreezeFrameDataByDTCType)(0x03U))  /*!< Record number is not supported by configuration and therefore invalid */
#define DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE     ((Dem_ReturnGetFreezeFrameDataByDTCType)(0x04U))  /*!< provided buffer size to small */
#define DEM_GET_FFDATABYDTC_PENDING              ((Dem_ReturnGetFreezeFrameDataByDTCType)(0x05U))  /*!< The requested value is calculated asynchronously and currently not available. The caller can retry later. */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnGetSizeOfDataByDTCType
 * \{
 */
/*! Used to return the status of Dem_DcmGetSizeOfFreezeFrameByDTC and Dem_DcmGetSizeOfExtendedDataRecordByDTC. */
typedef uint8                                    Dem_ReturnGetSizeOfDataByDTCType;
#define DEM_GETSIZEBYDTC_OK                      ((Dem_ReturnGetSizeOfDataByDTCType)(0x00U))  /*!< Size successfully returned */
#define DEM_GETSIZEBYDTC_WRONG_DTC               ((Dem_ReturnGetSizeOfDataByDTCType)(0x01U))  /*!< DTC value not existing (in UDS format) */
#define DEM_GETSIZEBYDTC_WRONG_DTCORIGIN         ((Dem_ReturnGetSizeOfDataByDTCType)(0x02U))  /*!< Wrong DTC origin */
#define DEM_GETSIZEBYDTC_WRONG_RECNUM            ((Dem_ReturnGetSizeOfDataByDTCType)(0x03U))  /*!< Record number is not supported by configuration and therefore invalid */
#define DEM_GETSIZEBYDTC_PENDING                 ((Dem_ReturnGetSizeOfDataByDTCType)(0x04U))  /*!< The requested value is calculated asynchronously and currently not available. The caller can retry later. */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnGetSeverityOfDTCType
 * \{
 */
/*! Used to return the status of Dem_DcmGetSeverityOfDTC. */
typedef uint8                                    Dem_ReturnGetSeverityOfDTCType;
#define DEM_GET_SEVERITYOFDTC_OK                 ((Dem_ReturnGetSeverityOfDTCType)(0x00U))  /*!< Severity successfully returned. */
#define DEM_GET_SEVERITYOFDTC_WRONG_DTC          ((Dem_ReturnGetSeverityOfDTCType)(0x01U))  /*!< DTC value not existing (in UDS format) */
#define DEM_GET_SEVERITYOFDTC_NOSEVERITY         ((Dem_ReturnGetSeverityOfDTCType)(0x02U))  /*!< Severity information is not available */
#define DEM_GET_SEVERITYOFDTC_PENDING            ((Dem_ReturnGetSeverityOfDTCType)(0x03U))  /*!< The requested value is calculated asynchronously and currently not available. The caller can retry later. */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_ReturnGetFunctionalUnitOfDTCType
 * \{
 */
/*! Used to return the status of Dem_DcmGetFunctionalUnitOfDTC. */
typedef uint8                                    Dem_ReturnGetFunctionalUnitOfDTCType;
#define DEM_GET_FUNCTIONALUNITOFDTC_OK           ((Dem_ReturnGetFunctionalUnitOfDTCType)(0x00U))  /*!< Functional unit successfully returned. */
#define DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC    ((Dem_ReturnGetFunctionalUnitOfDTCType)(0x01U))  /*!< DTC value not existing (in UDS format) */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_J1939DcmSetClearFilterType
 * \{
 */
/*! The type to distinguish which DTCs gets cleared. */
typedef uint8                                    Dem_J1939DcmSetClearFilterType;
#define DEM_J1939DTC_CLEAR_ALL                   ((Dem_J1939DcmSetClearFilterType)(0x00U))  /*!< Clear active DTCs */
#define DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE     ((Dem_J1939DcmSetClearFilterType)(0x01U))  /*!< Clear previously active DTCs */
#define DEM_J1939DTC_CLEAR_ALL_AND_PREVIOUSLY_ACTIVE  ((Dem_J1939DcmSetClearFilterType)(0x02U))  /*!< Clear active and previously active DTCs */
/*!
 * \}
 */

/*! J1939 indicator lamp status
 *  bits 14-15 : Malfunction Indicator Lamp Status
 *  bits 12-13 : Red Stop Lamp Status
 *  bits 10-11 : Amber Warning Lamp Status
 *  bits  8- 9 : Protect Lamp Status
 *  bits  6- 7 : Malfunction Indicator Lamp Flash Status
 *  bits  4- 5 : Red Stop Lamp Flash Status
 *  bits  2- 3 : Amber Warning Lamp Flash Status
 *  bits  0- 1 : Protect Lamp Flash Status
 */
typedef uint16                                   Dem_J1939DcmLampStatusType;

/*!
 * \defgroup  Dem_J1939DcmSetFreezeFrameFilterType
 * \{
 */
/*! The type to select the freeze frame filter. */
typedef uint8                                    Dem_J1939DcmSetFreezeFrameFilterType;
#define DEM_J1939DCM_FREEZEFRAME                  ((Dem_J1939DcmSetFreezeFrameFilterType)(0x00U))  /*!< Freeze Frame (DM04) */
#define DEM_J1939DCM_EXPANDED_FREEZEFRAME         ((Dem_J1939DcmSetFreezeFrameFilterType)(0x01U))  /*!< Expanded Freeze Frame (DM25) */
#define DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME ((Dem_J1939DcmSetFreezeFrameFilterType)(0x02U))  /*!< SPNs in Expanded Freeze Frame (DM24) */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_J1939DcmDTCStatusFilterType
 * \{
 */
/*! The type to distinguish which DTCs should be filtered. */
typedef uint8                                    Dem_J1939DcmDTCStatusFilterType;
#define DEM_J1939DTC_ACTIVE                      ((Dem_J1939DcmDTCStatusFilterType)(0x00U))  /*!< active DTCs */
#define DEM_J1939DTC_PREVIOUSLY_ACTIVE           ((Dem_J1939DcmDTCStatusFilterType)(0x01U))  /*!< previously active DTCs */
#define DEM_J1939DTC_PENDING                     ((Dem_J1939DcmDTCStatusFilterType)(0x02U))  /*!< pending DTCs */
#define DEM_J1939DTC_PERMANENT                   ((Dem_J1939DcmDTCStatusFilterType)(0x03U))  /*!< permanent DTCs */
#define DEM_J1939DTC_CURRENTLY_ACTIVE            ((Dem_J1939DcmDTCStatusFilterType)(0x04U))  /*!< currently failed DTCs */
/*!
 * \}
 */

/*! This structure represents all data elements of the DM05 message. The encoding is according to SAE J1939-73 */
typedef struct Dem_J1939DcmDiagnosticReadiness1Type_tag
{
  uint8 ActiveTroubleCodes;                          /*!< Number of active DTCs */
  uint8 PreviouslyActiveDiagnosticTroubleCodes;      /*!< Number of previously active DTCs */
  uint8 OBDCompliance;                               /*!< OBD Compliance */
  uint8 ContinuouslyMonitoredSystemsSupport_Status;  /*!< Identifies the continuously monitored system support and status */
  uint16 NonContinuouslyMonitoredSystemsSupport;     /*!< Identifies the non-continuously monitored systems support */
  uint16 NonContinuouslyMonitoredSystemsStatus;      /*!< Identifies the non-continuously monitored systems status */
} Dem_J1939DcmDiagnosticReadiness1Type;                                                                                          /* PRQA S 0779 */ /* MD_DEM_5.1_API */

/*! This structure represents all data elements of the DM21 message. The encoding is according to SAE J1939-73 */
typedef struct Dem_J1939DcmDiagnosticReadiness2Type_tag
{
  uint16 DistanceTraveledWhileMILisActivated;        /*!< The kilometers accumulated while the MIL is activated */
  uint16 DistanceSinceDTCsCleared;                   /*!< Distance accumulated since emission related DTCs were cleared */
  uint16 MinutesRunbyEngineWhileMILisActivated;      /*!< Accumulated count (in minutes) while the MIL is activated (not off) */
  uint16 TimeSinceDiagnosticTroubleCodesCleared;     /*!< Engine run-time accumulated since emission related DTCs were cleared */
} Dem_J1939DcmDiagnosticReadiness2Type;                                                                                          /* PRQA S 0779 */ /* MD_DEM_5.1_API */

/*! This structure represents all data elements of the DM26 message. The encoding is according to SAE J1939-73 */
typedef struct Dem_J1939DcmDiagnosticReadiness3Type_tag
{
  uint16 TimeSinceEngineStart;                       /*!< Time since key-on that the engine has been running. */
  uint8 NumberofWarmupsSinceDTCsCleared;             /*!< Number of OBD warm-up cycles since all DTCs were cleared */
  uint8 ContinuouslyMonitoredSystemsEnableCompletedStatus; /*!<  Identifies the continuously monitored system enable/completed support and status. */
  uint16 NonContinuouslyMonitoredSystemsEnableStatus;  /*!< Enable status of non-continuous monitors this monitoring cycle */
  uint16 NonContinuouslyMonitoredSystems;            /*!< Completion status of non-continuous monitors this monitoring cycle */
} Dem_J1939DcmDiagnosticReadiness3Type;                                                                                          /* PRQA S 0779 */ /* MD_DEM_5.1_API */

/*! Function pointer type for clear event allowed callbacks */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_ClearEventAllowedFPtrType)(
                                                   P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) /* [out] isAllowed */
                                                 );

/*! Function pointer type for get fault detection counter callbacks */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_GetFDCFPtrType)(
                                                   P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) /* [out] FDC */
                                                 );

/*! Function pointer type for event status changed notifications */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_EventStatusChangedFPtrType)(
                                                   Dem_EventStatusExtendedType /* [in] oldStatus */,
                                                   Dem_EventStatusExtendedType /* [in] newStatus */
                                                 );

/*! Function pointer type for DTC status changed notifications */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_DtcStatusChangedFPtrType)(
                                                   uint32 /* [in] DTC */,
                                                   Dem_DTCStatusMaskType /* [in] oldStatus */,
                                                   Dem_DTCStatusMaskType /* [in] newStatus */
                                                 );

/*! Function pointer type for event data changed notifications */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_EventDataChangedFPtrType)(
                                                   void
                                                 );

/*! Function pointer type for global event status changed notifications */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_GlobalStatusChangedFPtrType)(
                                                   Dem_EventIdType /* [in] EventId*/,
                                                   Dem_EventStatusExtendedType /* [in] oldStatus */,
                                                   Dem_EventStatusExtendedType /* [in] newStatus */
                                                 );

/*! Function pointer type for global event data changed notifications */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_GlobalDataChangedFPtrType)(
                                                   Dem_EventIdType /* [in] EventId*/
                                                 );

/*! Function pointer type for init monitor for event notifications */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_InitMonitorForEventFPtrType)(
                                                   Dem_InitMonitorReasonType /* [in] initReason */
                                                 );

/*! Function pointer type for init monitor for function notifications */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_InitMonitorForFuncFPtrType)(
                                                   void
                                                 );

/*! Function pointer type for control DTC setting changed notifications */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_ControlDtcSettingChangedFPtrType)(
                                                   boolean
                                                 );

/*! Function pointer type for C/S read data callbacks */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_ReadDataStandardFPtrType)(
                                                   P2VAR(uint8, DEM_NVM_DATA, AUTOMATIC) /* [out] data */
                                                 );

/*! Function pointer type for C/S read data callbacks with additional event argument */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_ReadDataExtendedFPtrType)(
                                                   Dem_EventIdType /* [in] EventId*/,
                                                   P2VAR(uint8, DEM_NVM_DATA, AUTOMATIC) /* [out] data */
                                                 );

/*! Function pointer type for S/R read data callbacks for data type boolean */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_ReadDataSRBooleanFPtrType)(
                                                P2VAR(boolean, DEM_NVM_DATA, AUTOMATIC) /* [out] data */
                                               );

/*! Function pointer type for S/R read data callbacks for data type sint8 */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_ReadDataSRSint8FPtrType)(
                                                P2VAR(sint8, DEM_NVM_DATA, AUTOMATIC) /* [out] data */
                                              );

/*! Function pointer type for S/R read data callbacks for data type sint16 */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_ReadDataSRSint16FPtrType)(
                                                P2VAR(sint16, DEM_NVM_DATA, AUTOMATIC) /* [out] data */
                                              );

/*! Function pointer type for S/R read data callbacks for data type uint16 */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_ReadDataSRUint16FPtrType)(
                                                P2VAR(uint16, DEM_NVM_DATA, AUTOMATIC) /* [out] data */
                                              );

/*! Function pointer type for S/R read data callbacks for data type sint32 */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_ReadDataSRSint32FPtrType)(
                                                P2VAR(sint32, DEM_NVM_DATA, AUTOMATIC) /* [out] data */
                                              );

/*! Function pointer type for S/R read data callbacks for data type uint32 */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_ReadDataSRUint32FPtrType)(
                                                P2VAR(uint32, DEM_NVM_DATA, AUTOMATIC) /* [out] data */
                                              );

/*! Common function pointer type for read data callbacks. Must be casted to the correct type before it can be called */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE,    Dem_ReadDataFPtrType)(void);

/*! Data pointer into Dem defined RAM */
typedef P2VAR(uint8, TYPEDEF, DEM_VAR_NOINIT)    Dem_DataPtrType;
/*! Data pointer into Nv backed RAM */
typedef P2VAR(uint8, TYPEDEF, DEM_NVM_DATA)      Dem_NvDataPtrType;
/*! Data pointer into Nv backed RAM */
typedef P2VAR(sint8, TYPEDEF, DEM_NVM_DATA)      Dem_SignedNvDataPtrType;
/*! Data pointer into RAM provided by Dcm */
typedef P2VAR(uint8, TYPEDEF, DEM_DCM_DATA)      Dem_DcmDataPtrType;
/*! Common data pointer into RAM - must be able to point to all used RAM locations */
typedef P2VAR(uint8, TYPEDEF, DEM_SHARED_DATA)   Dem_SharedDataPtrType;

/*! Common read-only data pointer Dem defined RAM */
typedef P2CONST(uint8, TYPEDEF, DEM_CONST)       Dem_ConstDataPtrType;
/*! Common read-only data pointer into RAM - must be able to point to all used RAM locations */
typedef P2CONST(uint8, TYPEDEF, DEM_SHARED_DATA) Dem_ConstSharedDataPtrType;

/* ********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* DEM_TYPES_H */

/* ********************************************************************************************************************
 *  END OF FILE: Dem_Types.h
 *********************************************************************************************************************/
