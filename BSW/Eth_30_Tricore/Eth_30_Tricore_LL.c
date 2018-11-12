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
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Eth_30_Tricore_LL.c
 *        \brief  Lower Layer of Ethernet Driver
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
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Eth_30_Tricore_Cfg.h"
#include "Eth_30_Tricore_Lcfg.h"
#include "Eth_30_Tricore.h"
#include "Eth_30_Tricore_Int.h"
#include "Eth_30_Tricore_Types.h"
#include "Eth_30_Tricore_Regs.h"
#include "Eth_30_Tricore_LL.h"
#include "EthIf_Cbk.h"
#include "IpBase.h"
#if (ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT */
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef STATIC
#define STATIC static
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define ETH_30_TRICORE_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#if (ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON)
VAR(uint8, ETH_30_TRICORE_VAR_NOINIT) Eth_30_Tricore_RxDescriptorAvailabilityDelayed;
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT */
#define ETH_30_TRICORE_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define ETH_30_TRICORE_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#if (ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON)
/* PRQA S 3218 1 */ /* MD_Eth_30_Tricore_3218 */
VAR(uint16, ETH_30_TRICORE_VAR_NOINIT) Eth_30_Tricore_RxFrameStartPosition;
#endif
#define ETH_30_TRICORE_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define ETH_30_TRICORE_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#if (ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON)
/* PRQA S 3218 1 */ /* MD_Eth_30_Tricore_3218 */
STATIC VAR(uint32, ETH_30_TRICORE_VAR_NOINIT) Eth_30_Tricore_RxFrameBufOffs;
#endif
#define ETH_30_TRICORE_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#if (ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON)
STATIC FUNC(void, ETH_30_TRICORE_CODE)    Eth_30_Tricore_VResetRxDescriptors(uint8 CtrlIdx, uint16 StartPosition, uint16 EndPosition);
STATIC FUNC(void, ETH_30_TRICORE_CODE)    Eth_30_Tricore_LL_VIncRxReadPosition(uint8 CtrlIdx, uint8 DescrRingIdx);
STATIC FUNC(boolean, ETH_30_TRICORE_CODE) Eth_30_Tricore_LL_VIsBroadcast(P2CONST(uint8, AUTOMATIC, ETH_30_TRICORE_APPL_DATA) PhysAddrPtr);
#endif
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
#if (ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON)
/***********************************************************************************************************************
 *  Eth_30_Tricore_VResetRxDescriptors
 **********************************************************************************************************************/
STATIC FUNC(void, ETH_30_TRICORE_CODE) Eth_30_Tricore_VResetRxDescriptors(uint8 CtrlIdx, uint16 StartPosition, uint16 EndPosition)
{
  uint16 DescrPos;
  /* Iterate over all segments for the received frame to recharge them */
  for(DescrPos = StartPosition; DescrPos <= EndPosition; DescrPos++)
  {
    /* PRQA S 0306,0310 4 */ /* MD_Eth_0306 */
    Eth_30_Tricore_RxDescriptor[DescrPos][2] = (uint32)&Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, 0).BufPtr.U8
      [
        (DescrPos * Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, 0).AlignedSegmentSize) + ETH_30_TRICORE_ALIGN_PADDING
      ];

    /* Recharge buffer */
    Eth_30_Tricore_RxDescriptor[DescrPos][0] = ETH_30_TRICORE_RX0_DESC_OWN;
  }
}

STATIC FUNC(void, ETH_30_TRICORE_CODE) Eth_30_Tricore_LL_VIncRxReadPosition(uint8 CtrlIdx, uint8 DescrRingIdx)
{
  Eth_30_Tricore_RxReadPosition[CtrlIdx][DescrRingIdx]++;
  /* Wrap around */
  if (Eth_30_Tricore_RxReadPosition[CtrlIdx][DescrRingIdx] >= Eth_30_Tricore_VCfgGetRxBufferNum(CtrlIdx, DescrRingIdx))
  {
    Eth_30_Tricore_RxReadPosition[CtrlIdx][DescrRingIdx] = 0;
  }
}

STATIC FUNC(boolean, ETH_30_TRICORE_CODE) Eth_30_Tricore_LL_VIsBroadcast(P2CONST(uint8, AUTOMATIC, ETH_30_TRICORE_APPL_DATA) PhysAddrPtr)
{
  boolean IsBroadcast = TRUE;
  uint8 AddrIdx = 0;

  while (AddrIdx < ETH_PHYS_ADDR_LEN_BYTE)
  {
    if (0xFF != PhysAddrPtr[AddrIdx])
    {
      IsBroadcast = FALSE;
      break;
    }
    AddrIdx++;
  }
  return IsBroadcast;
}

FUNC(void, ETH_30_TRICORE_CODE_ISR) Eth_30_Tricore_Receive(uint8 CtrlIdx, P2VAR(Eth_RxStatusType, AUTOMATIC, AUTOMATIC) RxStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETH_30_TRICORE_E_NO_ERROR;
  uint16 LenByte;
  boolean IsBroadcast;
  uint16 FrameType;
  uint8 ReceptionFinished = FALSE;
  uint8 CurrentDescriptorFinished;
  uint8 CleanUpNeeded = FALSE;
  uint8 NoDescriptorIncrement;
  uint16 CurDescrRingPos = Eth_30_Tricore_RxReadPosition[0][0];
  /* PRQA S 0759 1 */ /* MD_Eth_0759 */
  Eth_30_Tricore_AlignedFrameCacheType RxBufDataPtr;

  /* ----- Development Error Checks ------------------------------------- */
  CtrlIdx = Eth_30_Tricore_TransformToLocalCtrlIdx(CtrlIdx);

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
  else
#endif /* ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON */
  {
    /* ----- Implementation ----------------------------------------------- */
    *RxStatusPtr = ETH_RECEIVED;

    /* No action necessary - avoid waiting for next descriptor */
    if((ETH_30_TRICORE_RX0_DESC_OWN & Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0]) != 0)
    {
      *RxStatusPtr = ETH_NOT_RECEIVED;
      return;
    }

    ETH_30_TRICORE_BEGIN_CRITICAL_SECTION_2(); /* PRQA S 3109 1 */ /* MD_MSR_14.3 */

    Eth_30_Tricore_RxDescriptorAvailabilityDelayed = FALSE;

    do
    {
      CurrentDescriptorFinished = FALSE;
      NoDescriptorIncrement = FALSE;

      if((ETH_30_TRICORE_RX0_DESC_OWN & Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0]) != 0)
      {
        Eth_30_Tricore_RxDescriptorAvailabilityDelayed = TRUE;
        ReceptionFinished = TRUE;
        CurrentDescriptorFinished = TRUE;
        NoDescriptorIncrement = TRUE;
      }

      /* Check for error condition: Only last descriptor used and FS set but not LS set: too long segment in last descriptor, cleanup necessary */
      if ((CurrentDescriptorFinished == FALSE) &&
          (Eth_30_Tricore_RxReadPosition[0][0] == (ETH_30_TRICORE_RX_BUF_TOTAL - 1)) &&
          ((ETH_30_TRICORE_RX0_DESC_FS & Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0]) != 0) &&
          ((ETH_30_TRICORE_RX0_DESC_LS & Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0]) == 0))
      {
        *RxStatusPtr = ETH_NOT_RECEIVED;
        Eth_30_Tricore_VResetRxDescriptors(CtrlIdx, CurDescrRingPos, CurDescrRingPos);
        /* reception is not finished for that frame - there must be a LS set in one of the next descriptors */
        CleanUpNeeded = TRUE;
        CurrentDescriptorFinished = TRUE;
      }
      else if((CurrentDescriptorFinished == FALSE) &&
              (CleanUpNeeded == TRUE))
      {
        if((0 != (ETH_30_TRICORE_RX0_DESC_LS & Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0])))
        {
          CleanUpNeeded = FALSE;
          ReceptionFinished = TRUE;
        }
        CurrentDescriptorFinished = TRUE;
        Eth_30_Tricore_VResetRxDescriptors(CtrlIdx, CurDescrRingPos, CurDescrRingPos);
      }
      /* Error summary bit set - clean up and exit reception loop.
      * One possible reason for an error is, that not enough Rx segments are configured and frames are lost */
      else if ((CurrentDescriptorFinished == FALSE) && (
          0 != (ETH_30_TRICORE_RX0_DESC_ES & Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0])))
      {
          *RxStatusPtr = ETH_NOT_RECEIVED;
          Eth_30_Tricore_VResetRxDescriptors(CtrlIdx, Eth_30_Tricore_RxFrameStartPosition, CurDescrRingPos);
          ReceptionFinished = TRUE;
          CurrentDescriptorFinished = TRUE;
          CleanUpNeeded = FALSE;
      }
      /* Remember the position and buffer address of the first segment of the frame */
      else if ((CurrentDescriptorFinished == FALSE) &&
               (0 != (ETH_30_TRICORE_RX0_DESC_FS & Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0])))
      {
          Eth_30_Tricore_RxFrameStartPosition = Eth_30_Tricore_RxReadPosition[0][0];
          Eth_30_Tricore_RxFrameBufOffs = CurDescrRingPos * Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, 0).AlignedSegmentSize;

      }
      else
      {
        /* MISRA */
      }
      /* Is the frame complete? */
      if ((CurrentDescriptorFinished == FALSE) &&
          (0 != (ETH_30_TRICORE_RX0_DESC_LS & Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0])))
      {
        ReceptionFinished = TRUE;

        /* Extract frame length from FL field of RX descriptor */
        LenByte = (uint16)((Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0] & ETH_30_TRICORE_RX0_DESC_FL)
          >> ETH_30_TRICORE_RX0_DESC_FL_SHIFT);

        /* Is the size correct? */
        if (LenByte > Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, ETH_30_TRICORE_RING_IDX).MaximumFrameSize)
        {
          *RxStatusPtr = ETH_NOT_RECEIVED;
          Eth_30_Tricore_VResetRxDescriptors(CtrlIdx, Eth_30_Tricore_RxFrameStartPosition, CurDescrRingPos);
        }
        else
        {
          /* Access associated buffer */
          RxBufDataPtr.U8 = &Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, ETH_30_TRICORE_RING_IDX).BufPtr.U8[Eth_30_Tricore_RxFrameBufOffs];

          /* Is a broadcast? */
          IsBroadcast = Eth_30_Tricore_LL_VIsBroadcast(&RxBufDataPtr.U8[ETH_30_TRICORE_RX_DST_OFFSET_U8]);

          /* Extract frame type */
          FrameType = IPBASE_SWAP16(RxBufDataPtr.U16[(ETH_30_TRICORE_RX_TYPE_OFFSET_U16)]);

          ETH_30_TRICORE_END_CRITICAL_SECTION_2(); /* PRQA S 3109 1 */ /* MD_MSR_14.3 */

          /* PRQA S 3305,0310 5 */ /* MD_Eth_3305 */
          EthIf_RxIndication(
              CtrlIdx,
              FrameType,
              IsBroadcast,
              &RxBufDataPtr.U8[ETH_30_TRICORE_RX_SRC_OFFSET_U8],
              &RxBufDataPtr.Native[ETH_30_TRICORE_RX_DATA_OFFSET_U32],
              LenByte - ETH_30_TRICORE_HDR_LEN_BYTE);

          ETH_30_TRICORE_BEGIN_CRITICAL_SECTION_2(); /* PRQA S 3109 1 */ /* MD_MSR_14.3 */

          /* Reset all RxDescriptors used for that frame */
          Eth_30_Tricore_VResetRxDescriptors(CtrlIdx, Eth_30_Tricore_RxFrameStartPosition, CurDescrRingPos);

        }
      }
      else
      {
        /* Frame is not yet complete */
      }
      /* Go to next descriptor if possible */
      if(NoDescriptorIncrement == FALSE)
      {
        Eth_30_Tricore_LL_VIncRxReadPosition(CtrlIdx, ETH_30_TRICORE_RING_IDX);
        CurDescrRingPos = Eth_30_Tricore_RxReadPosition[0][0];
      }
    }
    while(ReceptionFinished == FALSE);

    if( 0 == (ETH_30_TRICORE_RX0_DESC_OWN & Eth_30_Tricore_RxDescriptor[CurDescrRingPos][0]))
    {
      /* more data available ... */
      *RxStatusPtr = ETH_RECEIVED_MORE_DATA_AVAILABLE;
    }
    ETH_30_TRICORE_END_CRITICAL_SECTION_2(); /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  }
  /* ----- Development Error Report --------------------------------------- */
 #if (ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ETH_30_TRICORE_E_NO_ERROR)
  {
    (void)Det_ReportError(ETH_MODULE_ID, CtrlIdx, ETH_30_TRICORE_SID_RECEIVE, errorId);
  }
 #else
  ETH_30_TRICORE_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
 #endif /* ETH_30_TRICORE_DEV_ERROR_REPORT == STD_ON */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */  /* PRQA S 6010 */ /* MD_MSR_STPTH */  /* PRQA S 6030 */ /* MD_MSR_STCYC */  /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON */

