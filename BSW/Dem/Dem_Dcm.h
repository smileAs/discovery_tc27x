
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
 *         File:  Dem_Dcm.h
 *      Project:  MICROSAR Diagnostic Event Manager (Dem)
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Static public API declarations of Dem.
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

#if !defined (DEM_DCM_H)
#define DEM_DCM_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
                                                               /* Dem itself */
/* ------------------------------------------------------------------------- */
#include "Dem.h"
/* ------------------------------------------------------------------------- */

#if (DEM_CFG_SUPPORT_DCM != STD_ON)
# error "Dcm API is not supported"
#endif

/* ********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

                                                       /* Generic properties */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmGetTranslationType
 *****************************************************************************/
/*!
 * \brief         Get the UDS DTC format.
 *
 * \details       Returns the UDS DTC format.
 *
 * \return        The configured DTC format.
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_DTCTranslationFormatType, DEM_CODE)
Dem_DcmGetTranslationType(
  void
  );

/* ****************************************************************************
 * Dem_DcmGetDTCStatusAvailabilityMask
 *****************************************************************************/
/*!
 * \brief         Get the supported UDS DTC status availability mask.
 *
 * \details       Returns the supported UDS DTC status availability mask.
 *
 * \param[out]    DTCStatusMask
 *                Pointer to receive the status availability mask
 *
 * \return        E_OK
 *                The DTCStatusMask was returned
 * \return        E_NOT_OK
 *                The DTCStatusMask was not returned
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmGetDTCStatusAvailabilityMask(
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatusMask
  );

                                                           /* DTC properties */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmGetStatusOfDTC
 *****************************************************************************/
/*!
 * \brief         Get the current Uds status of a DTC
 *
 * \details       Returns the current Uds status of a DTC
 *
 * \param[in]     DTC
 *                The UDS DTC number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[out]    DTCStatus
 *                Pointer to receive the Uds status
 *
 * \return        DEM_STATUS_OK
 *                The requested status was returned
 * \return        DEM_STATUS_WRONG_DTC
 *                DTC does not exist in DTCOrigin
 * \return        DEM_STATUS_WRONG_DTCORIGIN
 *                DTCOrigin does not exist
 * \return        DEM_STATUS_FAILED
 *                A generic error occurred.
 * \return        DEM_STATUS_PENDING
 *                Never returned by this implementation
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE)
Dem_DcmGetStatusOfDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus
  );

/* ****************************************************************************
 * Dem_DcmGetSeverityOfDTC
 *****************************************************************************/
/*!
 * \brief         Get the severity of a DTC
 *
 * \details       Returns the severity of a DTC
 *
 * \param[in]     DTC
 *                The UDS DTC number
 * \param[out]    DTCSeverity
 *                Pointer to receive the DTC severity
 *
 * \return        DEM_GET_SEVERITYOFDTC_OK
 *                The requested severity was returned
 * \return        DEM_GET_SEVERITYOFDTC_WRONG_DTC
 *                The DTC does not exist in origin PRIMARY
 * \return        DEM_GET_SEVERITYOFDTC_NOSEVERITY
 *                Severities do not exist
 * \return        DEM_GET_SEVERITYOFDTC_PENDING
 *                Never returned by this implementation
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE)
Dem_DcmGetSeverityOfDTC(
  uint32  DTC,
  P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_DCM_DATA)  DTCSeverity
  );

/* ****************************************************************************
 * Dem_DcmGetFunctionalUnitOfDTC
 *****************************************************************************/
/*!
 * \brief         Get the functional unit of a DTC.
 *
 * \details       Returns the functional unit of a DTC.
 *
 * \param[in]     DTC
 *                The DTC number
 * \param[out]    DTCFunctionalUnit
 *                Pointer to receive the DTC functional unit
 *
 * \return        DEM_GET_FUNCTIONALUNITOFDTC_OK
 *                The requested functional unit was returned
 * \return        DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC
 *                The DTC does not exist in origin PRIMARY
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE)
Dem_DcmGetFunctionalUnitOfDTC(
  uint32  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCFunctionalUnit
  );

                                                               /* DTC filter */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmSetDTCFilter
 *****************************************************************************/
/*!
 * \brief         Initialize the Dcm DTC filter with the given criteria.
 *
 * \details       Initializes the Dcm DTC filter with the given criteria.
 *
 * \param[in]     DTCStatusMask
 *                Requested status bits according to ISO14229-1
 *                0x04, 0x08 and 0x0C filter in chronologic order
 *                0x00 reports all DTCs, 0x01..0xFF apply the mask
 * \param[in]     DTCKind
 *                The DTC kind to filter
 * \param[in]     DTCFormat
 *                The DTC format
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     FilterWithSeverity
 *                Select severity as filter criterion
 * \param[in]     DTCSeverityMask
 *                Severity filter (conditional)
 * \param[in]     FilterForFaultDetectionCounter
 *                Select fault detection counter as filter criterion
 *
 * \return        DEM_FILTER_ACCEPTED
 *                The filter parameters were accepted
 * \return        DEM_WRONG_FILTER
 *                Wrong filter selected
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnSetFilterType, DEM_CODE)
Dem_DcmSetDTCFilter(
  uint8  DTCStatusMask,
  Dem_DTCKindType  DTCKind,
  Dem_DTCFormatType  DTCFormat,
  Dem_DTCOriginType  DTCOrigin,
  Dem_FilterWithSeverityType  FilterWithSeverity,
  Dem_DTCSeverityType  DTCSeverityMask,
  Dem_FilterForFDCType  FilterForFaultDetectionCounter
  );

/* ****************************************************************************
 * Dem_DcmSetFreezeFrameRecordFilter
 *****************************************************************************/
/*!
 * \brief         Initialize the DTC record filter with the given criteria.
 *
 * \details       Initializes the DTC record filter with the given criteria.
 *
 * \param[in]     DTCFormat
 *                The DTC format
 * \param[out]    NumberOfFilteredRecords
 *                Pointer to receive the number of stored snapshot records
 *
 * \return        DEM_FILTER_ACCEPTED
 *                The filter parameters were accepted
 * \return        DEM_WRONG_FILTER
 *                Wrong filter selected
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnSetFilterType, DEM_CODE)
Dem_DcmSetFreezeFrameRecordFilter(
  Dem_DTCFormatType  DTCFormat,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  NumberOfFilteredRecords
  );

/* ****************************************************************************
 * Dem_DcmGetNumberOfFilteredDTC
 *****************************************************************************/
/*!
 * \brief         Calculate the number of DTCs matching the filter criteria.
 *
 * \details       Calculates the number of DTCs matching the filter criteria.
 *
 * \param[out]    NumberOfFilteredDTC
 *                Pointer to receive the DTC count
 *
 * \return        DEM_NUMBER_OK
 *                The number of matching DTCs was returned
 * \return        DEM_NUMBER_FAILED
 *                The number of matching DTCs could not be calculated
 * \return        DEM_NUMBER_PENDING
 *                Counting is currently in progress - not used
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           The Dcm filter has to be initialized by Dem_DcmSetDTCFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE)
Dem_DcmGetNumberOfFilteredDTC(
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  NumberOfFilteredDTC
  );

/* ****************************************************************************
 * Dem_DcmGetNextFilteredDTC
 *****************************************************************************/
/*!
 * \brief         Iterate the next matching DTC.
 *
 * \details       Iterates the next matching DTC.
 *
 * \param[out]    DTC
 *                Pointer to receive the UDS/OBD DTC number
 * \param[out]    DTCStatus
 *                Pointer to receive the DTC status
 *
 * \return        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           The Dcm filter has to be initialized by Dem_DcmSetDTCFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredDTC(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus
  );

/* ****************************************************************************
 * Dem_DcmGetDTCByOccurrenceTime
 *****************************************************************************/
/*!
 * \brief         Get a DTC based on occurrence time.
 *
 * \details       Returns a DTC based on occurrence time.
 *
 * \param[in]     DTCRequest
 *                The occurrence time
 * \param[out]    DTC
 *                Pointer to receive the UDS DTC number
 *
 * \return        DEM_OCCURR_OK
 *                The requested DTC was returned
 * \return        DEM_OCCURR_NOT_AVAILABLE
 *                No DTC is available for the given occurrence time
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE)
Dem_DcmGetDTCByOccurrenceTime(
  Dem_DTCRequestType  DTCRequest,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC
  );

/* ****************************************************************************
 * Dem_DcmGetNextFilteredRecord
 *****************************************************************************/
/*!
 * \brief         Iterate the next snapshot record number matching the filter.
 *
 * \details       Iterates the next snapshot record number matching the filter.
 *
 * \param[out]    DTC
 *                Pointer to receive the UDS DTC number
 * \param[out]    RecordNumber
 *                Pointer to receive the snapshot record number
 *
 * \return        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           The record filter has been initialized by
 *                Dem_DcmSetFreezeFrameRecordFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredRecord(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  RecordNumber
  );

/* ****************************************************************************
 * Dem_DcmGetNextFilteredDTCAndFDC
 *****************************************************************************/
/*!
 * \brief         Iterate the next DTC matching the filter criteria.
 *
 * \details       Iterates the next DTC matching the filter criteria. This
 *                function also retrieves the DTC's fault detection counter.
 *
 * \param[out]    DTC
 *                Pointer to receive the UDS/OBD DTC number
 * \param[out]    DTCFaultDetectionCounter
 *                Pointer to receive the fault detection counter
 *
 * \return        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           The Dcm filter has to be initialized by Dem_DcmSetDTCFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredDTCAndFDC(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(sint8, AUTOMATIC, DEM_DCM_DATA)  DTCFaultDetectionCounter
  );

/* ****************************************************************************
 * Dem_DcmGetNextFilteredDTCAndSeverity
 *****************************************************************************/
/*!
 * \brief         Iterate the next DTC matching the filter criteria.
 *
 * \details       Iterates the next DTC matching the filter criteria. This
 *                function also retrieves the DTC's Status, Severity and
 *                Functional Unit.
 *
 * \param[out]    DTC
 *                Pointer to receive the UDS/OBD DTC number
 * \param[out]    DTCStatus
 *                Pointer to receive the DTC status
 * \param[out]    DTCSeverity
 *                Pointer to receive the DTC severity
 * \param[out]    DTCFunctionalUnit
 *                Pointer to receive the DTC functional unit
 *
 * \return        DEM_FILTERED_OK
 *                The next filtered element was returned
 * \return        DEM_FILTERED_NO_MATCHING_ELEMENT
 *                No further element was found, iteration is complete
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           The Dcm filter has to be initialized by Dem_DcmSetDTCFilter
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
Dem_DcmGetNextFilteredDTCAndSeverity(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus,
  P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_DCM_DATA)  DTCSeverity,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCFunctionalUnit
  );

                                                          /* Data Protection */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmDisableDTCRecordUpdate
 *****************************************************************************/
/*!
 * \brief         Prepare a memory entry for readout by the Dcm.
 *
 * \details       Prepares a memory entry for readout by the Dcm.
 *
 * \param[in]     DTC
 *                The UDS DTC number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 *
 * \return        DEM_DISABLE_DTCRECUP_OK
 *                The memory entry is ready for readout
 * \return        DEM_DISABLE_DTCRECUP_WRONG_DTC
 *                The DTC value does not exist in this evcent memory
 * \return        DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN
 *                Wrong DTC origin
 * \return        DEM_DISABLE_DTCRECUP_PENDING
 *                The operation was started and is currently processed
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE)
Dem_DcmDisableDTCRecordUpdate(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin
  );

/* ****************************************************************************
 * Dem_DcmEnableDTCRecordUpdate
 *****************************************************************************/
/*!
 * \brief         Release a previously prepared memory entry.
 *
 * \brief         Releases the memory entry previously locked by
 *                Dem_DcmDisableDTCRecordUpdate
 *
 * \return        E_OK
 *                The memory entry has been released
 * \return        E_NOT_OK
 *                There was no memory entry to release
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmEnableDTCRecordUpdate(
  void
  );

                                                                 /* DTC Data */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmGetOBDFreezeFrameData
 *****************************************************************************/
/*!
 * \brief         Read the OBD freeze frame via UDS protocol (19 05).
 *
 * \details       Reads the OBD freeze frame via UDS protocol (19 05).
 *
 * \param[out]    DTC
 *                Pointer to receive the DTC number
 * \param[out]    DestBuffer
 *                Pointer to receive the snapshot data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data.
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                DTC and OBD freeze frame have been returned
 * \return        E_NOT_OK
 *                No DTC and OBD freeze frame data available
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmGetOBDFreezeFrameData(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  BufSize
  );

/* ****************************************************************************
 * Dem_DcmGetFreezeFrameDataByDTC
 *****************************************************************************/
/*!
 * \brief         Read a snapshot record stored for a DTC (19 04).
 *
 * \details       Reads a snapshot record stored for a DTC (19 04). If the
 *                snapshot is currently not stored, the function returns
 *                BufSize 0.
 *
 * \param[in]     DTC
 *                The DTC number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[out]    DestBuffer
 *                Pointer to receive the snapshot data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data.
 *                Out: Number of written bytes.
 *
 * \return        DEM_GET_FFDATABYDTC_OK
 *                The requested data was returned
 * \return        DEM_GET_FFDATABYDTC_WRONG_DTC
 *                The requested DTC is not available in that event memory
 * \return        DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN
 *                The requested event memory is not available
 * \return        DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER
 *                The requested record is not available
 * \return        DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE
 *                The destination buffer is too small
 * \return        DEM_GET_FFDATABYDTC_PENDING
 *                Not used by this implementation
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           The data of the requested DTC has to be initialized by
 *                Dem_DcmDisableDTCRecordUpdate
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)
Dem_DcmGetFreezeFrameDataByDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  uint8  RecordNumber,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  BufSize
  );

/* ****************************************************************************
 * Dem_DcmGetSizeOfFreezeFrameByDTC
 *****************************************************************************/
/*!
 * \brief         Get the size of a formatted snapshot record stored for a DTC
 *                (19 04).
 *
 * \details       Gets the size of a formatted snapshot record stored for a DTC
 *                (19 04).
 *
 * \param[in]     DTC
 *                The Dtc number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[out]    SizeOfFreezeFrame
 *                Pointer to receive the size in bytes
 *
 * \return        DEM_GETSIZEBYDTC_OK
 *                The requested data was returned
 * \return        DEM_GETSIZEBYDTC_WRONG_DTC
 *                The requested DTC is not available in that event memory
 * \return        DEM_GETSIZEBYDTC_WRONG_DTCORIGIN
 *                The requested event memory is not available
 * \return        DEM_GETSIZEBYDTC_WRONG_RECNUM
 *                The requested record is not available
 * \return        DEM_GETSIZEBYDTC_PENDING
 *                Not used by this implementation
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           The data of the requested DTC has to be initialized by
 *                Dem_DcmDisableDTCRecordUpdate
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)
Dem_DcmGetSizeOfFreezeFrameByDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  uint8  RecordNumber,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame
  );

/* ****************************************************************************
 * Dem_DcmGetExtendedDataRecordByDTC
 *****************************************************************************/
/*!
 * \brief         Read an extended data record stored for a DTC.
 *
 * \details       Reads an extended data record stored for a DTC. If the record
 *                is currently not stored, the function returns BufSize 0.
 *
 * \param[in]     DTC
 *                The Dtc number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     ExtendedDataNumber
 *                The extended record number
 * \param[out]    DestBuffer
 *                Pointer to receive the extended record data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data
 *                Out: Number of written bytes
 *
 * \return        DEM_RECORD_OK
 *                The requested data was returned
 * \return        DEM_RECORD_WRONG_DTC
 *                The requested DTC is not available in that event memory
 * \return        DEM_RECORD_WRONG_DTCORIGIN
 *                The requested event memory is not available
 * \return        DEM_RECORD_WRONG_NUMBER
 *                The requested record is not available
 * \return        DEM_RECORD_WRONG_BUFFERSIZE
 *                The destination buffer is too small
 * \return        DEM_RECORD_PENDING
 *                Not used by this implementation
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           The data of the requested DTC has to be initialized by
 *                Dem_DcmDisableDTCRecordUpdate
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)
Dem_DcmGetExtendedDataRecordByDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  uint8  ExtendedDataNumber,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  BufSize
  );

/* ****************************************************************************
 * Dem_DcmGetSizeOfExtendedDataRecordByDTC
 *****************************************************************************/
/*!
 * \brief         Gets the size of a formatted extended data record stored for
 *                a DTC.
 *
 * \details       This function returns the size of the formatted extended data
 *                record, including the record number.
 *
 * \param[in]     DTC
 *                The Dtc number
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 * \param[in]     ExtendedDataNumber
 *                The extended data record
 * \param[out]    SizeOfExtendedDataRecord
 *                Pointer to receive the size in bytes
 *
 * \return        DEM_GETSIZEBYDTC_OK
 *                The requested data was returned
 * \return        DEM_GETSIZEBYDTC_WRONG_DTC
 *                The requested DTC is not available in that event memory
 * \return        DEM_GETSIZEBYDTC_WRONG_DTCORIGIN
 *                The requested event memory is not available
 * \return        DEM_GETSIZEBYDTC_WRONG_RECNUM
 *                The requested record is not available
 * \return        DEM_GETSIZEBYDTC_PENDING
 *                Not used by this implementation
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           The data of the requested DTC has to be initialized by
 *                Dem_DcmDisableDTCRecordUpdate
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)
Dem_DcmGetSizeOfExtendedDataRecordByDTC(
  uint32  DTC,
  Dem_DTCOriginType  DTCOrigin,
  uint8  ExtendedDataNumber,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfExtendedDataRecord
  );

                                                                /* Clear DTC */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmClearDTC
 *****************************************************************************/
/*!
 * \brief         Clear DTCs from a memory.
 *
 * \details       Clears the requested DTC(s) from the passed memory. This
 *                function blocks all other clear requests until the asynchonous
 *                clear has completed and the final result was returned. The caller
 *                must continue to poll this function while the result is PENDING,
 *                otherwise clearing can be blocked indefinitely.
 *
 * \param[in]     DTC
 *                DTC number of a single DTC to clear this DTC
 *                DTC number of a DTC group to clear all DTCs in the group
 *                DTC number '0xFFFFFF' to clear all DTCs
 * \param[in]     DTCFormat
 *                The DTC format
 * \param[in]     DTCOrigin
 *                The external identifier of the event memory
 *
 * \return        DEM_CLEAR_OK
 *                Clearing is completed, the requested DTC(s) are reset.
 * \return        DEM_CLEAR_WRONG_DTC
 *                The requested DTC is not valid in the context of DTCFormat
 *                and DTCOrigin
 * \return        DEM_CLEAR_WRONG_DTCORIGIN
 *                The requested DTC origin is not available in the context of
 *                DTCFormat
 * \return        DEM_CLEAR_FAILED
 *                The clear operation could not be started
 * \return        DEM_CLEAR_MEMORY_ERROR
 *                The clear operation has completed, but the NV synchronization
 *                has failed
 * \return        DEM_CLEAR_PENDING
 *                The clear operation was started and is currently processed
 * \return        DEM_CLEAR_BUSY
 *                Another clear operation is currently processing
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(Dem_ReturnClearDTCType, DEM_CODE)
Dem_DcmClearDTC(
  uint32  DTC,
  Dem_DTCFormatType  DTCFormat,
  Dem_DTCOriginType  DTCOrigin
  );

                                                     /* Control DTC Settings */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmDisableDTCSetting
 *****************************************************************************/
/*!
 * \brief         Disable DTC setting (UDS 0x85)
 *
 * \details       Completely disables the processing of DTCs (UDS 0x85).
 *
 * \param[in]     DTCGroup
 *                Only all DTCs is supported
 * \param[in]     DTCKind
 *                Only all kind of DTCs is supported
 *
 * \return        DEM_CONTROL_DTC_SETTING_OK
 *                DTCs setting was disabled
 * \return        DEM_CONTROL_DTC_SETTING_N_OK
 *                DTCs setting was not disabled
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)
Dem_DcmDisableDTCSetting(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType  DTCKind
  );

/* ****************************************************************************
 * Dem_DcmEnableDTCSetting
 *****************************************************************************/
/*!
 * \brief         Enable the DTC setting (UDS 0x85)
 *
 * \details       Re-Enables the processing of DTCs (UDS 0x85) after
 *                Dem_DcmDisableDTCSetting was called.
 *
 * \param[in]     DTCGroup
 *                Only all DTCs is supported
 * \param[in]     DTCKind
 *                Only all kind of DTCs is supported
 *
 * \return        DEM_CONTROL_DTC_SETTING_OK
 *                DTCs setting was disabled
 * \return        DEM_CONTROL_DTC_SETTING_N_OK
 *                DTCs setting was not disabled
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)
Dem_DcmEnableDTCSetting(
  Dem_DTCGroupType  DTCGroup,
  Dem_DTCKindType  DTCKind
  );

                                                 /* Control DTC Notification */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmControlDTCStatusChangedNotification
 *****************************************************************************/
/*!
 * \brief         Toggle DTC status change notification
 *
 * \details       Enables or Disables DTC status change notifications to
 *                Dcm_DemTriggerOnDTCStatusChange. Clear DTC will not trigger
 *                these notifications.
 *                Notifications are disabled after Dem initialization.
 *
 * \param[in]     TriggerNotification
 *                New notification setting
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(void, DEM_CODE)
Dem_DcmControlDTCStatusChangedNotification(
  boolean TriggerNotification
  );

                                                  /* Dcm <-> Dem : OBD DTR */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_SUPPORT_DTR == STD_ON)
/* ****************************************************************************
 * Dem_DcmGetDTRData
 *****************************************************************************/
/*!
 * \brief         Gets the DTR data for a OBDMID / TID combination
 *
 * \param[in]     Obdmid
 *                OBDMID
 * \param[in]     TIDindex
 *                TID index
 * \param[out]    TIDvalue
 *                TID value
 * \param[out]    UaSID
 *                Unit and Scaling ID
 * \param[out]    Testvalue
 *                Test Value
 * \param[out]    Lowlimvalue
 *                Lower Limit
 * \param[out]    Upplimvalue
 *                Upper Limit
 *
 * \return        E_OK
 *                The data was successfully copied
 * \return        E_NOT_OK
 *                The requested data was not copied
 *
 * \config           DEM_CFG_SUPPORT_DTR == STD_ON
 *                && DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmGetDTRData(
  uint8 Obdmid,
  uint8 TIDindex,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA) TIDvalue,                                                                                /* PRQA S 3673 */ /* MD_DEM_16.7 */
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA) UaSID,                                                                                   /* PRQA S 3673 */ /* MD_DEM_16.7 */
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) Testvalue,                                                                              /* PRQA S 3673 */ /* MD_DEM_16.7 */
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) Lowlimvalue,                                                                            /* PRQA S 3673 */ /* MD_DEM_16.7 */
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) Upplimvalue                                                                             /* PRQA S 3673 */ /* MD_DEM_16.7 */
  );
#endif

                                                   /* Dcm <-> Dem : OBD MIDs */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_SUPPORT_DTR == STD_ON)
/* ****************************************************************************
 * Dem_DcmGetAvailableOBDMIDs
 *****************************************************************************/
/*!
 * \brief         Gets the supported Mid Mask for an availability OBDMID
 *
 * \param[in]     Obdmid
 *                Availability OBDMID
 * \param[out]    Obdmidvalue
 *                Supported Mid Mask
 *
 * \return        E_OK
 *                The data was successfully copied
 * \return        E_NOT_OK
 *                The requested data was not copied
 *
 * \config           DEM_CFG_SUPPORT_DTR == STD_ON
 *                && DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmGetAvailableOBDMIDs(
  uint8 Obdmid,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  Obdmidvalue                                                                            /* PRQA S 3673 */ /* MD_DEM_16.7 */
  );
#endif

#if (DEM_CFG_SUPPORT_DTR == STD_ON)
/* ****************************************************************************
 * Dem_DcmGetNumTIDsOfOBDMID
 *****************************************************************************/
/*!
 * \brief         Gets the number of TIDs for a MID
 *
 * \param[in]     Obdmid
 *                OBDMID
 * \param[out]    numberOfTIDs
 *                Number of TIDs for OBDMID
 *
 * \retval        E_OK
 *                DTR data was successfully copied
 * \retval        E_NOT_OK
 *                DTR data was not copied
 *
 * \config           DEM_CFG_SUPPORT_DTR == STD_ON
 *                && DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmGetNumTIDsOfOBDMID(
  uint8 Obdmid,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA) numberOfTIDs
  );
#endif

                                                         /* Cancel Operation */
/* ------------------------------------------------------------------------- */

/* ****************************************************************************
 * Dem_DcmCancelOperation
 *****************************************************************************/
/*!
 * \brief         Cancel an active asynchronous operation started by Dcm
 *
 * \details       The active operation will continue until it finishes, but the
 *                Dem will no longer require the Dcm to poll the API to finalization.
 *                This is most relevant for ClearDTC.
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
FUNC(void, DEM_CODE)
Dem_DcmCancelOperation(
  void
  );

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif
