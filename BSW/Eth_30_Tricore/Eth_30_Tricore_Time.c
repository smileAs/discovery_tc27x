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
 *         File:  Eth_30_Tricore_Time.c
 *      Project:  TcpIp-Stack
 *       Module:  Ethernet Driver for Tricore MAC
 *    Generator:  DrvEth_30_Tricore_TricoreEthAsr.dll (DrvEth_30_Tricore__baseAsr.dll)
 *
 *  Description:  Timesync hardware support implementation for Tricore MAC
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
#define ETH_30_TRICORE_SOURCE


/*lint -e438 */ /* Suppress ID438 because Config pointer only used in Post-Build Variant */
/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */
/*lint -e537 */ /* Suppress ID537 due to MD_MSR_19.1 */
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e652 */ /* Used for Vector API optimization */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Eth_30_Tricore_Time.h"
#include "Eth_30_Tricore.h"
#include "Eth_30_Tricore_Int.h"
#include "Eth_30_Tricore_LL_Int.h"
#include "Eth_30_Tricore_Regs.h"
#if (ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT */
/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if defined (STATIC)
/* nothing to do */
#else
#define STATIC static
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define ETH_30_TRICORE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS PROTOTYPES
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_VDoRateCorrection(uint8 CtrlIdx,
                                   P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_30_TRICORE_APPL_CONST)  RateRatioPtr);
STATIC FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_VDoOffsetCorrection(uint8 CtrlIdx,
                                   P2CONST(Eth_TimediffType,  AUTOMATIC, ETH_30_TRICORE_APPL_CONST)  OffsetTimePtr);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
#if (ETH_30_TRICORE_ENABLE_PTP == STD_ON)

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Eth_30_Tricore_GetGlobalTime
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_GetGlobalTime(
  uint8 CtrlIdx,
  P2VAR(Eth_TimeStampType,        AUTOMATIC, ETH_30_TRICORE_APPL_VAR) TimestampPtr,
  P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETH_30_TRICORE_APPL_VAR) TimestampQualityPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETH_30_TRICORE_E_NO_ERROR;
  Eth_ReturnType RetVal = E_NOT_OK;

   /* ----- Development Error Checks ------------------------------------- */
#if ( ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON )
  if(CtrlIdx >= ETH_30_TRICORE_MAX_CTRLS_TOTAL)
  {
   errorId = ETH_30_TRICORE_E_INV_CTRL_IDX;
  }
  else if(Eth_30_Tricore_State == ETH_STATE_UNINIT)
  {
   errorId = ETH_30_TRICORE_E_NOT_INITIALIZED;
  }
  else if(TimestampPtr == NULL_PTR)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else if(TimestampQualityPtr == NULL_PTR)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON */
  {
    /* Read lower 32 bits of seconds */
    /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
    TimestampPtr->seconds = Eth_30_Tricore_VCtrlRegReadValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_SECONDS);

    /* Read upper 16 bits of seconds */
    /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
    TimestampPtr->secondsHi = (uint16)(Eth_30_Tricore_VCtrlRegReadValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_HIGH_WORD_SEC) & 0x0000FFFF);

    /* Read nanoseconds */
    /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
    TimestampPtr->nanoseconds = Eth_30_Tricore_VCtrlRegReadValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_NANOSEC);

    /* Write timestamp quality and set always to valid because there is no possibility here to obtain
     * the hardware status (different to ingress or egress timestamps that could be invalid) */
    *TimestampQualityPtr = ETH_TIMESTAMP_VALID;
    RetVal = E_OK;
  }
  /* ----- Development Error Report --------------------------------------- */
  #if (ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ETH_30_TRICORE_E_NO_ERROR)
  {
  (void)Det_ReportError(ETH_MODULE_ID, CtrlIdx, ETH_30_TRICORE_PTP_API_ID_GET_GLOBAL_TIME, errorId);
  }
  #else
  ETH_30_TRICORE_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  #endif /* ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON */
  return RetVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */

/***********************************************************************************************************************
 *  Eth_30_Tricore_SetGlobalTime
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_SetGlobalTime(
  uint8 CtrlIdx,
  P2CONST(Eth_TimeStampType, AUTOMATIC, ETH_30_TRICORE_APPL_CONST) TimestampPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETH_30_TRICORE_E_NO_ERROR;
  Eth_ReturnType RetVal = E_NOT_OK;
  uint32 UpperSeconds;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON )
  if(CtrlIdx >= ETH_30_TRICORE_MAX_CTRLS_TOTAL)
  {
    errorId = ETH_30_TRICORE_E_INV_CTRL_IDX;
  }
  else if(Eth_30_Tricore_State == ETH_STATE_UNINIT)
  {
    errorId = ETH_30_TRICORE_E_NOT_INITIALIZED;
  }
  else if(Eth_30_Tricore_Mode[CtrlIdx] == ETH_MODE_DOWN)
  {
    errorId = ETH_30_TRICORE_E_INV_MODE;
  }
  else if(TimestampPtr == NULL_PTR)
  {
    errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON */
  {
    /* Write lower 32 bits of seconds */
    /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
    Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_SEC_UPDATE, TimestampPtr->seconds);

    /* Write upper 16 bits of seconds */
    UpperSeconds = TimestampPtr->secondsHi & 0x0000FFFFUL;
    /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
    Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_HIGH_WORD_SEC, UpperSeconds);

    /* Write nanoseconds */
    /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
    Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_NSEC_UPDATE, TimestampPtr->nanoseconds);

    /* Write TSINIT bit to set the new timestamp */
    /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
    if (Eth_30_Tricore_VCtrlRegReadBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_TIMESTAMP_CNTRL, ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSINIT) == 0)
    {
      /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
      Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_TIMESTAMP_CNTRL, ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSINIT);
      RetVal = E_OK;
    }
    else
    {
      RetVal = E_NOT_OK;
    }
  }
 /* ----- Development Error Report --------------------------------------- */
 #if (ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON)
 if (errorId != ETH_30_TRICORE_E_NO_ERROR)
 {
 (void)Det_ReportError(ETH_MODULE_ID, CtrlIdx, ETH_30_TRICORE_PTP_API_ID_SET_GLOBAL_TIME, errorId);
 }
 #else
 ETH_30_TRICORE_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
 #endif /* ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON */
 return RetVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

STATIC FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_VDoOffsetCorrection(uint8 CtrlIdx,
                                   P2CONST(Eth_TimediffType,  AUTOMATIC, ETH_30_TRICORE_APPL_CONST)  OffsetTimePtr)
{
  Std_ReturnType RetVal = E_OK;
  uint32 OffsetTime;
  uint32 OffsetLeadingSignMask;

  /* set offset in PTP update registers */
    if (*OffsetTimePtr >= 0)
    {
      OffsetTime = (uint32)*OffsetTimePtr;
      /* leading sign is plus */
      OffsetLeadingSignMask = 0x00000000;
    }
    else
    {
      OffsetTime = (uint32)(*OffsetTimePtr * (-1));
      /* leading sign is minus */
      OffsetLeadingSignMask = ETH_30_TRICORE_REG_NSEC_UPDATE_ADDSUB;
    }

    /* PRQA S 0306 1 */ /* MD_Eth_0306 */
    Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_SEC_UPDATE, OffsetTime / ETH_30_TRICORE_TIMESTAMP_MAX_NANOSECONDS);

    /* Update nano seconds and leading sign bit in register */
    /* PRQA S 0306 1 */ /* MD_Eth_0306 */
    Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_NSEC_UPDATE, (OffsetTime % ETH_30_TRICORE_TIMESTAMP_MAX_NANOSECONDS) | OffsetLeadingSignMask);
   /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
   if (0 == Eth_30_Tricore_VCtrlRegReadBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_TIMESTAMP_CNTRL, ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSUPDT))
   {
     /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
     Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_TIMESTAMP_CNTRL, ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSUPDT);
   }
   else
   {
     RetVal = E_NOT_OK;
   }
  return RetVal;
}

STATIC FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_VDoRateCorrection(uint8 CtrlIdx,
                                 P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_30_TRICORE_APPL_CONST)  RateRatioPtr)
{
  Std_ReturnType RetVal = E_OK;
  uint32 AddendReg;

  /* PRQA S 0306 1 */ /* MD_Eth_0306 */
  AddendReg = Eth_30_Tricore_VCtrlRegReadValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_ADDEND);

  /* check that addend register does not overflow or underflow after frequency multiplication */
  if ((0xFFFFFFFFUL < (*RateRatioPtr * (Eth_RateRatioType)AddendReg)) ||
      (0 > (*RateRatioPtr * (Eth_RateRatioType)AddendReg)))
  {
    /* Don't do any modifications */
    RetVal = E_NOT_OK;
  }
  else
  {
    /* no overflow or underflow */
    AddendReg = (uint32)(*RateRatioPtr * (Eth_RateRatioType)AddendReg);

    /* PRQA S 0306 2 */ /* MD_Eth_0306 */
    Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_ADDEND, AddendReg);

    /* PRQA S 0306 2 */ /* MD_Eth_0306 */
    if (Eth_30_Tricore_VCtrlRegReadBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_TIMESTAMP_CNTRL, ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSADDREG) == 0)
    {
      /* PRQA S 0306 1 */ /* MD_Eth_0306 */
      Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_TIMESTAMP_CNTRL, ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSADDREG);
    }
  }
  return RetVal;
}

/***********************************************************************************************************************
 *  Eth_30_Tricore_SetCorrectionTime
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_SetCorrectionTime(
  uint8 CtrlIdx,
  P2CONST(Eth_TimediffType,            AUTOMATIC, ETH_30_TRICORE_APPL_CONST) OffsetTimePtr,
  P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_30_TRICORE_APPL_CONST) RateRatioPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETH_30_TRICORE_E_NO_ERROR;
  Eth_ReturnType RetVal = E_OK;
  Eth_TimeStampType CurrentTime;
  Eth_TimestampQualityType TimeStampQuality;
  Eth_UInt64 CurrentTimeNs;

  CtrlIdx = Eth_30_Tricore_TransformToLocalCtrlIdx(CtrlIdx);

   /* ----- Development Error Checks ------------------------------------- */
#if ( ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON )
  if(CtrlIdx >= ETH_30_TRICORE_MAX_CTRLS_TOTAL)
  {
   errorId = ETH_30_TRICORE_E_INV_CTRL_IDX;
  }
  else if(Eth_30_Tricore_State == ETH_STATE_UNINIT)
  {
   errorId = ETH_30_TRICORE_E_NOT_INITIALIZED;
  }
  else if(OffsetTimePtr == NULL_PTR)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else if(RateRatioPtr == NULL_PTR)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON */
  {
    RetVal = Eth_30_Tricore_GetGlobalTime(CtrlIdx, &CurrentTime, &TimeStampQuality);

    if(RetVal == E_OK)
    {
      if((*RateRatioPtr <= 0) || (*RateRatioPtr > 2))
      {
        /* RateRatio is not acceptable */
        RetVal = E_NOT_OK;
      }
      else if((CurrentTime.secondsHi == 0) && (*OffsetTimePtr < 0))
      {
        CurrentTimeNs = CurrentTime.nanoseconds + (Eth_UInt64)((Eth_UInt64)CurrentTime.seconds * ETH_30_TRICORE_TIMESTAMP_MAX_NANOSECONDS);
        if((Eth_UInt64)(-1 * ((Eth_SInt64)(*OffsetTimePtr))) > CurrentTimeNs)
        {
          RetVal = E_NOT_OK;
        }
        else
        {
          RetVal = E_OK;
        }
      }
      else
      {
        RetVal = E_OK;
      }
    }

    if(RetVal == E_OK)
    {
      RetVal |= Eth_30_Tricore_VDoOffsetCorrection(CtrlIdx, OffsetTimePtr);
      RetVal |= Eth_30_Tricore_VDoRateCorrection(CtrlIdx, RateRatioPtr);
    }
  }
  /* ----- Development Error Report --------------------------------------- */
  #if (ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ETH_30_TRICORE_E_NO_ERROR)
  {
  (void)Det_ReportError(ETH_MODULE_ID, CtrlIdx, ETH_30_TRICORE_PTP_API_ID_SET_CORRECTION_TIME, errorId);
  }
  #else
  ETH_30_TRICORE_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  #endif /* ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON */
  return RetVal;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  Eth_30_Tricore_EnableEgressTimestamp
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_EnableEgressTimestamp(
  uint8 CtrlIdx,
  uint8 BufIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETH_30_TRICORE_E_NO_ERROR;
  Eth_ReturnType RetVal = E_NOT_OK;

   /* ----- Development Error Checks ------------------------------------- */
#if ( ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON )
  if(CtrlIdx >= ETH_30_TRICORE_MAX_CTRLS_TOTAL)
  {
   errorId = ETH_30_TRICORE_E_INV_CTRL_IDX;
  }
  else if(Eth_30_Tricore_State == ETH_STATE_UNINIT)
  {
   errorId = ETH_30_TRICORE_E_NOT_INITIALIZED;
  }
  else if(BufIdx >= ETH_30_TRICORE_TX_BUF_TOTAL)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON */
  {
    if (ETH_30_TRICORE_BUFFER_BUSY == Eth_30_Tricore_TxBufferBusyTable[CtrlIdx][BufIdx])
    {
      Eth_30_Tricore_PtpEgressTable[CtrlIdx][BufIdx] = ETH_30_TRICORE_PTP_EGRESS_DESIRED;
      RetVal = E_OK;
    }
    else
    {
      /* Either buffer not locked or descriptor already handed over to controller */
      RetVal = E_NOT_OK;
    }
  }
  /* ----- Development Error Report --------------------------------------- */
  #if (ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ETH_30_TRICORE_E_NO_ERROR)
  {
  (void)Det_ReportError(ETH_MODULE_ID, CtrlIdx, ETH_30_TRICORE_PTP_API_ID_ENABLE_EGRESS_TIMESTAMP, errorId);
  }
  #else
  ETH_30_TRICORE_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  #endif /* ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON */
  return RetVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  Eth_30_Tricore_GetEgressTimestamp
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_GetEgressTimestamp(
  uint8 CtrlIdx,
  uint8                                                    BufIdx,
  P2VAR(Eth_TimeStampType,        AUTOMATIC, ETH_30_TRICORE_APPL_VAR) TimestampPtr,
  P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETH_30_TRICORE_APPL_VAR) TimestampQualityPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETH_30_TRICORE_E_NO_ERROR;
  Eth_ReturnType RetVal = E_NOT_OK;
  uint8 DescIdx;

   /* ----- Development Error Checks ------------------------------------- */
#if ( ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON )
  if(CtrlIdx >= ETH_30_TRICORE_MAX_CTRLS_TOTAL)
  {
   errorId = ETH_30_TRICORE_E_INV_CTRL_IDX;
  }
  else if(Eth_30_Tricore_State == ETH_STATE_UNINIT)
  {
   errorId = ETH_30_TRICORE_E_NOT_INITIALIZED;
  }
  else if(BufIdx >= ETH_30_TRICORE_TX_BUF_TOTAL)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else if(TimestampQualityPtr == NULL_PTR)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON */
  {
    DescIdx = Eth_30_Tricore_PtpBuf2DescMap[CtrlIdx][BufIdx];

    if ((ETH_30_TRICORE_BUFFER_BUSY == Eth_30_Tricore_TxBufferBusyTable[CtrlIdx][BufIdx]) &&                /* Buffer is locked */
        (ETH_30_TRICORE_PTP_EGRESS_DESIRED == Eth_30_Tricore_PtpEgressTable[CtrlIdx][BufIdx]) &&            /* PTP egress time stamping is enabled */
        (ETH_30_TRICORE_DESCRIPTOR_TRANSMITTED == Eth_30_Tricore_TxDescriptorTxReadyTable[CtrlIdx][0][DescIdx]) /* Transmission finished */
       )
    {
      TimestampPtr->nanoseconds = Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[6];
      TimestampPtr->seconds = (uint32)Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[7];

      /* The seconds portion, stored in the descriptor only contains the lower 32 bits. The upper bits must be read
       * from Higher Word Seconds Register.
       * There is a potential risk that the Higher Word Seconds Register was increased between the actual reception of
       * the frame and the time the descriptor is processed here. However this risk is extremely unlikely and cannot be
       * avoided
       */
      /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
      TimestampPtr->secondsHi = (uint16)(Eth_30_Tricore_VCtrlRegReadValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_HIGH_WORD_SEC) & 0x0000FFFF);

      /* If an all ones pattern is set, the timestamp is not valid */
      if ((0xFFFFFFFFUL == TimestampPtr->seconds) && (0xFFFFFFFFUL == TimestampPtr->nanoseconds))
      {
        *TimestampQualityPtr = ETH_TIMESTAMP_INVALID;
      }
      else
      {
        *TimestampQualityPtr = ETH_TIMESTAMP_VALID;
      }

      RetVal = E_OK;
    }
    else
    {
      RetVal = E_NOT_OK;
    }
  }
  /* ----- Development Error Report --------------------------------------- */
  #if (ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ETH_30_TRICORE_E_NO_ERROR)
  {
  (void)Det_ReportError(ETH_MODULE_ID, CtrlIdx, ETH_30_TRICORE_PTP_API_ID_GET_EGRESS_TIMESTAMP, errorId);
  }
  #else
  ETH_30_TRICORE_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  #endif /* ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON */
  return RetVal;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  Eth_30_Tricore_GetIngressTimestamp
 **********************************************************************************************************************/
/* PRQA S 3673 5 */ /* MD_Eth_30_Tricore_3673 */
FUNC(Std_ReturnType, ETH_30_TRICORE_CODE) Eth_30_Tricore_GetIngressTimestamp(
  uint8 CtrlIdx,
  P2VAR(Eth_DataType,             AUTOMATIC, ETH_30_TRICORE_APPL_DATA) DataPtr,
  P2VAR(Eth_TimeStampType,        AUTOMATIC, ETH_30_TRICORE_APPL_VAR)  TimestampPtr,
  P2VAR(Eth_TimestampQualityType, AUTOMATIC, ETH_30_TRICORE_APPL_VAR)  TimestampQualityPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETH_30_TRICORE_E_NO_ERROR;
  Eth_ReturnType RetVal = E_NOT_OK;
  uint16 DescIdx;

   /* ----- Development Error Checks ------------------------------------- */
#if ( ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON )
  if(CtrlIdx >= ETH_30_TRICORE_MAX_CTRLS_TOTAL)
  {
   errorId = ETH_30_TRICORE_E_INV_CTRL_IDX;
  }
  else if(Eth_30_Tricore_State == ETH_STATE_UNINIT)
  {
   errorId = ETH_30_TRICORE_E_NOT_INITIALIZED;
  }
  else if(DataPtr == NULL_PTR)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else if(TimestampPtr == NULL_PTR)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else if(TimestampQualityPtr == NULL_PTR)
  {
   errorId = ETH_30_TRICORE_E_INV_POINTER;
  }
  else
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON */
  {
    /* buffer pointer is expected to point to the payload portion. Decrement pointer in order to point to the buffer
     * base address
     */
    DescIdx = Eth_30_Tricore_RxReadPosition[CtrlIdx][0];

    /* validate buffer index to be sure that nobody manipulated it by mistake */
    /* Check that receive status is correct */
    if (ETH_30_TRICORE_RX_BUF_TOTAL > DescIdx)
    {
      TimestampPtr->nanoseconds = Eth_30_Tricore_RxDescriptor[DescIdx][6];
      TimestampPtr->seconds = (uint32)Eth_30_Tricore_RxDescriptor[DescIdx][7];

      /* The seconds portion, stored in the descriptor only contains the lower 32 bits. The upper bits must be read
       * from Higher Word Seconds Register.
       * There is a potential risk that the Higher Word Seconds Register was increased between the actual reception of
       * the frame and the time the descriptor is processed here. However this risk is extremely unlikely and cannot be
       * avoided
       */
      /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
      TimestampPtr->secondsHi = (uint16)(Eth_30_Tricore_VCtrlRegReadValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_SYS_TIME_HIGH_WORD_SEC) & (0x0000FFFF));

      /* If an all ones pattern is set, the timestamp is not valid */
      if ((0xFFFFFFFFUL == TimestampPtr->seconds)  && (0xFFFFFFFFUL == TimestampPtr->nanoseconds))
      {
        *TimestampQualityPtr = ETH_TIMESTAMP_INVALID;
      }
      else
      {
        *TimestampQualityPtr = ETH_TIMESTAMP_VALID;
      }

      RetVal = E_OK;
    }
    else
    {
      /* Buffer index manipulated! Critical error. Somebody overwrote the index by mistake */
      RetVal = E_NOT_OK;
    }
  }
  /* ----- Development Error Report --------------------------------------- */
  #if (ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ETH_30_TRICORE_E_NO_ERROR)
  {
  (void)Det_ReportError(ETH_MODULE_ID, CtrlIdx, ETH_30_TRICORE_PTP_API_ID_GET_INGRESS_TIMESTAMP, errorId);
  }
  #else
  ETH_30_TRICORE_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  #endif /* ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON */
  return RetVal;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
#endif  /* (STD_ON == ETH_30_TRICORE_ENABLE_PTP) */

#define ETH_30_TRICORE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* module specific MISRA deviations:
 * see file Eth.c
*/

/**********************************************************************************************************************
 *  END OF FILE: Eth.c
 *********************************************************************************************************************/
