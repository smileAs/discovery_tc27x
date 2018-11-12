/**********************************************************************************************************************
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
 *         File:  Eth_30_Tricore_Ptp.h
 *      Project:  TcpIp-Stack
 *       Module:  Ethernet Driver for Tricore MAC
 *    Generator:  DrvEth_30_Tricore_TricoreEthAsr.dll (DrvEth_30_Tricore__baseAsr.dll)
 *
 *  Description:  Precision Time Protocol (PTP) Header for Tricore MAC
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
 
#ifndef ETH_30_TRICORE_PTP_H
#define ETH_30_TRICORE_PTP_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Eth_30_Tricore_Lcfg.h"

#if (ETH_30_TRICORE_ENABLE_PTP == STD_ON)
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ETH Min/Max values for Eth_TimeStampType and Eth_30_Tricore_TimediffType */
/* 48 bit seconds */
#define ETH_30_TRICORE_TIMESTAMP_MAX_SECONDS                                               (0xFFFFFFFFFFFFLL)
/* 10^9 nanoseconds per second */
#define ETH_30_TRICORE_TIMESTAMP_MAX_NANOSECONDS                                               (1000000000UL)
/* 63 bit max timediff in nanoseconds */
#define ETH_30_TRICORE_TIMEDIFF_MAX_NANOSECONDS                                        (0x7FFFFFFFFFFFFFFFLL)
/* Seconds portion of a timediff */
#define ETH_30_TRICORE_TIMEDIFF_MAX_SECONDS    (ETH_30_TRICORE_TIMEDIFF_MAX_NANOSECONDS / ETH_30_TRICORE_TIMESTAMP_MAX_NANOSECONDS)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* ETH ApiIds */
#define ETH_30_TRICORE_PTP_API_ID_GET_GLOBAL_TIME                                                     0x30U
#define ETH_30_TRICORE_PTP_API_ID_SET_GLOBAL_TIME                                                     0x31U
#define ETH_30_TRICORE_PTP_API_ID_SET_CORRECTION_TIME                                                 0x32U
#define ETH_30_TRICORE_PTP_API_ID_ENABLE_EGRESS_TIMESTAMP                                             0x33U
#define ETH_30_TRICORE_PTP_API_ID_GET_EGRESS_TIMESTAMP                                                0x34U
#define ETH_30_TRICORE_PTP_API_ID_GET_INGRESS_TIMESTAMP                                               0x35U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define ETH_30_TRICORE_START_SEC_CODE
#include "MemMap.h"

/***********************************************************************************************************************
 *  Eth_30_Tricore_GetGlobalTime
 **********************************************************************************************************************/
/*! \brief      Returns the global time of the controllers PTP submodule.
 *  \param[in]  CtrlIdx                  Controller index
 *  \param[out] TimestampPtr             Pointer to a timestamp of type Eth_TimeStampType
 *  \param[out] TimestampQualityPtr      Pointer to the timestamp quality of type Eth_TimestampQualityType
 *  \return     E_OK                     : Call successful. Timestamp and TimestampQuality are valid\n
 *              E_NOT_OK                 : Obtaining global time failed
 *  \context    Interrupt or task level
 *  \note       - Re-entrant, synchronous\n
 *              - If API optimization is enabled, parameter CtrlIdx is void
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_GetGlobalTime(
  uint8 CtrlIdx,
  P2VAR(Eth_TimeStampType,        AUTOMATIC, ETH_30_TRICORE_APPL_VAR) TimestampPtr,
  P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETH_30_TRICORE_APPL_VAR) TimestampQualityPtr);

/***********************************************************************************************************************
 *  Eth_30_Tricore_SetGlobalTime
 **********************************************************************************************************************/
/*! \brief      Resets the global time of the controllers PTP submodule to a specified value.
 *  \param[in]  CtrlIdx                  Controller index
 *  \param[out] TimestampPtr             Pointer to a timestamp of type Eth_TimeStampType
 *  \return     E_OK                     : Time successfully set\n
 *              E_NOT_OK                 : Failed to set time
 *  \context    Interrupt or task level
 *  \note       - Re-entrant, synchronous\n
 *              - If API optimization is enabled, parameter CtrlIdx is void
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_SetGlobalTime(
  uint8 CtrlIdx,
  P2CONST(Eth_TimeStampType, AUTOMATIC, ETH_30_TRICORE_APPL_CONST) TimestampPtr);

/***********************************************************************************************************************
 *  Eth_30_Tricore_SetCorrectionTime
 **********************************************************************************************************************/
/*! \brief      Corrects the global time by an offset and a rate ratio.
 *  \param[in]  CtrlIdx                  Controller index
 *  \param[in]  OffsetTimePtr            Pointer to a time difference object of type Eth_30_Tricore_TimediffType
 *  \param[in]  RateRatioPtr             Pointer to a rate ratio object of type Eth_RateRatioType
 *  \return     E_OK                     : Time successfully corrected\n
 *              E_NOT_OK                 : Call failed. Try again
 *  \context    Interrupt or task level
 *  \note       - Re-entrant, synchronous\n
 *              - If API optimization is enabled, parameter CtrlIdx is void
 *
 *              The time correction consists of three steps: First offset correction, optional second offset correction
 *              and the rate correction. If one step fails the function continues to the next step,
 *              trying to serve the request at least partly.
 *              Also, assuming that step 2 or step 3 fails, there wouldn't be a possibility to reverse the changes of
 *              the preceding steps.
 *              The optional second offset correction is necessary because the Ethernet controller only supports a
 *              maximum offset correct of 2^31 at once. Offsets between 2^31 and 2^32 must be set in two steps. This
 *              is done by the function internally.
 *
 *              Be aware that calling the function a second time should not be done in a row. The user does not know if
 *              time correction during the first function call took place partly or not at all. Just continue and try
 *              to do the rate correction later on (on future PTP frames) and based on a new parameter calculation.
 *
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_SetCorrectionTime(
  uint8 CtrlIdx,
  P2CONST(Eth_TimediffType,            AUTOMATIC, ETH_30_TRICORE_APPL_CONST) OffsetTimePtr,
  P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_30_TRICORE_APPL_CONST) RateRatioPtr);

/***********************************************************************************************************************
 *  Eth_30_Tricore_EnableEgressTimestamp
 **********************************************************************************************************************/
/*! \brief      Enables timestamping for a frame that is going to be transmitted.
 *  \param[in]  CtrlIdx                  Controller index
 *  \param[in]  BufIdx                   Index associated with the buffer containing the frame to be timestamped.
 *  \return     E_OK                     : Egress timestamping successfully enabled\n
 *              E_NOT_OK                 : DET check failed or buffer identified with BufIdx not locked.
 *  \context    Interrupt or task level
 *  \note       - Re-entrant, synchronous\n
 *              - If API optimization is enabled, parameter CtrlIdx is void
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_EnableEgressTimestamp(
  uint8 CtrlIdx,
  uint8 BufIdx);

/***********************************************************************************************************************
 *  Eth_30_Tricore_GetEgressTimestamp
 **********************************************************************************************************************/
/*! \brief      Returns the egress timestamp of the frame identified by BufIdx.
 *  \param[in]  CtrlIdx                  Controller index
 *  \param[in]  BufIdx                   Index associated with the buffer containing the frame that was timestamped
 *  \param[out] TimestampPtr             Pointer to a timestamp of type Eth_TimeStampType
 *  \param[out] TimestampQualityPtr      Pointer to the timestamp quality of type Eth_TimestampQualityType
 *  \return     E_OK                     : Egress timestamp successfully obtained\n
 *              E_NOT_OK                 : DET check failed or wrong call context
 *  \context    Context of Eth_30_Tricore_TxConfirmation. All other call contexts are invalid.
 *  \note       - NOT Re-entrant, synchronous\n
 *              - If API optimization is enabled, parameter CtrlIdx is void
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_GetEgressTimestamp(
  uint8 CtrlIdx,
  uint8                                                    BufIdx,
  P2VAR(Eth_TimeStampType,        AUTOMATIC, ETH_30_TRICORE_APPL_VAR) TimestampPtr,
  P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETH_30_TRICORE_APPL_VAR) TimestampQualityPtr);

/***********************************************************************************************************************
 *  Eth_30_Tricore_GeIngressTimestamp
 **********************************************************************************************************************/
/*! \brief      Returns the ingress timestamp of the frame identified by BufIdx.
 *  \param[in]  CtrlIdx                  Controller index
 *  \param[in]  DataPtr                  Data portion of the frame that was timestamped
 *  \param[out] TimestampPtr             Pointer to a timestamp of type Eth_TimeStampType
 *  \param[out] TimestampQualityPtr      Pointer to the timestamp quality of type Eth_TimestampQualityType
 *  \return     E_OK                     : Ingress timestamp successfully obtained\n
 *              E_NOT_OK                 : DET check failed or wrong call context
 *  \context    Context of Eth_30_Tricore_RxIndication. All other call contexts are invalid.
 *  \note       - NOT Re-entrant, synchronous\n
 *              - If API optimization is enabled, parameter CtrlIdx is void
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_GetIngressTimestamp(
  uint8 CtrlIdx,
  P2VAR(Eth_DataType,             AUTOMATIC, ETH_30_TRICORE_APPL_DATA) DataPtr,
  P2VAR(Eth_TimeStampType,        AUTOMATIC, ETH_30_TRICORE_APPL_VAR)  TimestampPtr,
  P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETH_30_TRICORE_APPL_VAR)  TimestampQualityPtr);

/***********************************************************************************************************************
 *  Global Function Macros
 **********************************************************************************************************************/
#define ETH_30_TRICORE_STOP_SEC_CODE
#include "MemMap.h"

#endif
  /* (defined ETH_30_TRICORE_ENABLE_PTP) && (STD_ON == ETH_30_TRICORE_ENABLE_PTP) */

#endif
  /* ETH_30_TRICORE_PTP_H */
/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Tricore_Ptp.h
 *********************************************************************************************************************/
