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
 *         File:  Eth_30_Tricore_Int.h
 *      Project:  TcpIp-Stack
 *       Module:  Ethernet Driver for SPC58xx MAC
 *    Generator:  DrvEth_Spc58xxEthAsr.jar
 *
 *  Description:  internal header
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
#ifndef ETH_30_TRICORE_INT_H
# define ETH_30_TRICORE_INT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Eth_30_Tricore_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define ETH_30_TRICORE_UNDEFINED_DESCRIPTOR_RING                                  (0xFFU)

# define ETH_30_TRICORE_UINT8_MAX                                                  (0xFFU)
# define ETH_30_TRICORE_UINT16_MAX                                                 (0xFFFFU)
# define ETH_30_TRICORE_UINT32_MAX                                                 (0xFFFFFFFFU)

#define ETH_30_TRICORE_ISR_NO_OS_SUPPORT                                           (0U)
#define ETH_30_TRICORE_ISR_CATEGORY_1                                              (1U)
#define ETH_30_TRICORE_ISR_CATEGORY_2                                              (2U)

# ifndef ETH_30_TRICORE_INLINE
#  define ETH_30_TRICORE_INLINE static INLINE
# endif
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 FUNCTION_MACROS */ /* MD_MSR_19.7 */
# define ETH_30_TRICORE_BEGIN_CRITICAL_SECTION_0() SchM_Enter_Eth_30_Tricore_ETH_30_TRICORE_EXCLUSIVE_AREA_0()
# define ETH_30_TRICORE_END_CRITICAL_SECTION_0()   SchM_Exit_Eth_30_Tricore_ETH_30_TRICORE_EXCLUSIVE_AREA_0()
# define ETH_30_TRICORE_BEGIN_CRITICAL_SECTION_1() SchM_Enter_Eth_30_Tricore_ETH_30_TRICORE_EXCLUSIVE_AREA_1()
# define ETH_30_TRICORE_END_CRITICAL_SECTION_1()   SchM_Exit_Eth_30_Tricore_ETH_30_TRICORE_EXCLUSIVE_AREA_1()

/* Configuration access macros utilized for both single and multiple controller configurations */
# define Eth_30_Tricore_VCfgGetTxBufferNum(CtrlIdx)                                (Eth_30_Tricore_TxBufferNum[CtrlIdx])
# define Eth_30_Tricore_VCfgGetTxMaxBufSize(CtrlIdx)                               (Eth_30_Tricore_TxMaxBufferSize[CtrlIdx])
# define Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, RingIdx)                            (Eth_30_Tricore_Ctrl2RxRingMap[CtrlIdx][RingIdx])
# define Eth_30_Tricore_VCfgGetRxBufferNum(CtrlIdx, RingIdx)                       (Eth_30_Tricore_Ctrl2RxRingMap[CtrlIdx][RingIdx].SegmentNumber)
# define Eth_30_Tricore_VCfgGetTxState(CtrlIdx, BufIdx)                            (Eth_30_Tricore_UlTxConfState[CtrlIdx][BufIdx])
# define Eth_30_Tricore_VCfgGetCtrlNum()                                           (ETH_30_TRICORE_MAX_CTRLS_TOTAL)
# define Eth_30_Tricore_VCfgGetRxDescrCnt(CtrlIdx, RingIdx)                        (Eth_30_Tricore_Ctrl2RxRingMap[CtrlIdx][RingIdx].SegmentNumber)
# define Eth_30_Tricore_VCfgGetRxDescrRingCnt(CtrlIdx)                             (Eth_30_Tricore_CtrlCfg[CtrlIdx].RxDescriptorRingNum)
# define Eth_30_Tricore_VCfgGetRegVal(CtrlIdx, RegIdx)                             (Eth_30_Tricore_CtrlCfg[CtrlIdx].RegVals[RegIdx].RegValue)
# define Eth_30_Tricore_VCfgGetRegAddr(CtrlIdx, RegIdx)                            (Eth_30_Tricore_CtrlCfg[CtrlIdx].RegVals[RegIdx].RegOffset)
# define Eth_30_Tricore_VCfgGetPhysSrcAddr(CtrlIdx)                                (Eth_30_Tricore_PhysSrcAddrs[CtrlIdx])
# define Eth_30_Tricore_VCfgGetPhysSrcAddrRomDefault(CtrlIdx)                      (Eth_30_Tricore_PhysSrcAddrsRom[CtrlIdx])
# define Eth_30_Tricore_VCfgGetRegBaseAddr(CtrlIdx)                                (Eth_30_Tricore_RegBaseAddr[CtrlIdx])
# define Eth_30_Tricore_VCfgGetMiiHwLoopMaxCycles(CtrlIdx)                         (Eth_30_Tricore_MiiHwLoopCycles[CtrlIdx])
# define Eth_30_Tricore_VCfgGetInitHwLoopMaxCycles(CtrlIdx)                        (Eth_30_Tricore_InitHwLoopCycles[CtrlIdx])
# define Eth_30_Tricore_VCfgGetRegData(CtrlIdx, RegIdx)                            (Eth_30_Tricore_CtrlCfg[CtrlIdx].RegVals[RegIdx])
# define Eth_30_Tricore_VCfgGetRegTotal(CtrlIdx)                                   (Eth_30_Tricore_CtrlCfg[CtrlIdx].RegNum)
# define Eth_30_Tricore_VCfgGetMiiModeMask(CtrlIdx)                                (Eth_30_Tricore_CtrlCfg[CtrlIdx].MiiModeMask)
# define Eth_30_Tricore_VCfgGetTxDescrRingCnt(CtrlIdx)                             (Eth_30_Tricore_CtrlCfg[CtrlIdx].TxDescriptorRingNum)
# define Eth_30_Tricore_VCfgGetTxDescrCnt(CtrlIdx, DescrRingIdx)                   (Eth_30_Tricore_TxBufferNum[CtrlIdx])
# define Eth_30_Tricore_VCfgGetCtrl2TxBufMap(CtrlIdx)                              (Eth_30_Tricore_Ctrl2TxBufferMap[0])
# define Eth_30_Tricore_VCfgGetUlTxConfState(CtrlIdx, BufIdx)                      (Eth_30_Tricore_UlTxConfState[CtrlIdx][BufIdx])
# define Eth_30_Tricore_VCfgGetTxBufferBusyTable(CtrlIdx, BufIdx)                  (Eth_30_Tricore_TxBufferBusyTable[CtrlIdx][BufIdx])
# define Eth_30_Tricore_VCfgTxDescriptorBufferMap(CtrlIdx, DescrRingIdx, BufIdx)   (Eth_30_Tricore_TxDescriptorBufferMap[CtrlIdx][DescrRingIdx][BufIdx])

# if (ETH_30_TRICORE_ENABLE_MAC_WRITE_ACCESS == STD_ON)
#  define Eth_VCfgGetMacAddressBlockId(CtrlIdx)                                    (Eth_CtrlMacAddrBlockIds[CtrlIdx].EthNvMBlockDesc)
#  define Eth_VCfgIsMacWriteAccess(CtrlIdx)                                        (Eth_CtrlMacAddrBlockIds[CtrlIdx].EthIsMacAddrWriteAccess)
# endif /* ETH_30_TRICORE_ENABLE_MAC_WRITE_ACCESS */
# define Eth_30_Tricore_VCfgGetDemErrorId(CtrlIdx)                                 (Eth_30_Tricore_DemEvents[CtrlIdx])

# define Eth_30_Tricore_VCfgGetTxBufferLen(CtrlIdx, BufIdx)                        (Eth_30_Tricore_CtrlCfg[CtrlIdx].TxBufferLen[BufIdx])
# define Eth_30_Tricore_VCfgGetTxBufferStart(CtrlIdx, BufIdx)                      (Eth_30_Tricore_CtrlCfg[CtrlIdx].TxBufferStart[BufIdx])
# define Eth_30_Tricore_VCfgGetPtpEgressTable(CtrlIdx, BufIdx)                     (Eth_30_Tricore_PtpEgressTable[CtrlIdx][BufIdx])

# define Eth_30_Tricore_VCfgGetPtpBuf2DescMap(CtrlIdx, BufIdx)                     (Eth_30_Tricore_PtpBuf2DescMap[CtrlIdx][BufIdx])
# define Eth_30_Tricore_VCfgGetPtpBuf2DescrRingMap(CtrlIdx, BufIdx)                (Eth_30_Tricore_PtpBuf2DescrRingMap[CtrlIdx][BufIdx])
# define Eth_30_Tricore_VCfgGetTxDescriptorTxReadyTable(CtrlIdx, RingIdx, BufIdx)  (Eth_30_Tricore_TxDescriptorTxReadyTable[CtrlIdx][RingIdx][BufIdx])
# define Eth_30_Tricore_VCfgIsQosEnabled(CtrlIdx)                              \
           (0U != (Eth_30_Tricore_CtrlCfg[CtrlIdx].Features & ETH_30_TRICORE_QOS_SUPPORT_MASK))
# define Eth_30_Tricore_VCfgIsPtpEnabled(CtrlIdx)                              \
           (0U != (Eth_30_Tricore_CtrlCfg[CtrlIdx].Features & ETH_30_TRICORE_PTP_SUPPORT_MASK))
# define Eth_30_Tricore_VCfgIsIpChecksumOffloadingEnabled(CtrlIdx)             \
           (0U != (Eth_30_Tricore_CtrlCfg[CtrlIdx].Features & ETH_30_TRICORE_IP_CHECK_OFF_MASK))
# define Eth_30_Tricore_VCfgIsProtocolChecksumOffloadingEnabled(CtrlIdx)       \
           (0U != (Eth_30_Tricore_CtrlCfg[CtrlIdx].Features & ETH_30_TRICORE_PROT_CHECK_OFF_MASK))
# define Eth_30_Tricore_VCfgIsMiiHwLoopCancelationEnabled(CtrlIdx)             \
           (0U != (Eth_30_Tricore_CtrlCfg[CtrlIdx].Features & ETH_30_TRICORE_MII_HW_LOOP_CANCELATION_MASK))
# define Eth_30_Tricore_VCfgIsInitHwLoopCancelationEnabled(CtrlIdx)            \
           (0U != (Eth_30_Tricore_CtrlCfg[CtrlIdx].Features & ETH_30_TRICORE_INIT_HW_LOOP_CANCELATION_MASK))

/* Ethernet controller register access */
# define Eth_30_Tricore_VCtrlRegReadValue(CtrlIdx, Reg)                        \
    (*((volatile P2VAR(uint32, AUTOMATIC, MSR_REGSPACE))((P2VAR(void, AUTOMATIC, MSR_REGSPACE)) \
        ((uint32)Eth_30_Tricore_VCfgGetRegBaseAddr(CtrlIdx)+(Reg)))))
# define Eth_30_Tricore_VCtrlMibReadValue(CtrlIdx, Reg)                        \
    (*((volatile P2VAR(uint32, AUTOMATIC, MSR_REGSPACE))((P2VAR(void, AUTOMATIC, MSR_REGSPACE)) \
        ((uint32)Eth_30_Tricore_VCfgGetCountersBaseAddr(CtrlIdx)+(Reg)))))
# define Eth_30_Tricore_VCtrlRegAddr(CtrlIdx, Reg)                             \
    (  (volatile P2VAR(uint32, AUTOMATIC, MSR_REGSPACE))((P2VAR(void, AUTOMATIC, MSR_REGSPACE)) \
        ((uint32)Eth_30_Tricore_VCfgGetRegBaseAddr(CtrlIdx)+(Reg))))
# define Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, Reg, Value)                \
    (Eth_30_Tricore_VCtrlRegReadValue((CtrlIdx), (Reg))  = (Value))
# define Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, Reg, Bits)                    \
    (Eth_30_Tricore_VCtrlRegReadValue((CtrlIdx), (Reg)) |= (Bits))
# define Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, Reg, Bits)                  \
    (Eth_30_Tricore_VCtrlRegReadValue((CtrlIdx), (Reg)) &= ((uint32)(((uint32)0xFFFFFFFFu) ^(Bits))))
# define Eth_30_Tricore_VCtrlRegReadBits(CtrlIdx, Reg, Mask)                   \
    (Eth_30_Tricore_VCtrlRegReadValue((CtrlIdx), (Reg)) &  (Mask))
# define Eth_30_Tricore_VCtrlRegReadBitsShift(CtrlIdx, Reg, Mask, Shift)       \
    (((Eth_30_Tricore_VCtrlRegReadValue((CtrlIdx), (Reg))) & (Mask)) >> (Shift))
# define Eth_30_Tricore_VCtrlRegReadValueShiftdMask(CtrlIdx, Reg, Shift, Mask) \
    ((Eth_30_Tricore_VCtrlRegReadValue((CtrlIdx), (Reg)) >> (Shift)) & (Mask))
# define Eth_30_Tricore_VCtrlRegIsBitSet(CtrlIdx, Reg, Bit)                    \
    (Eth_VCtrlRegReadBits((CtrlIdx), (Reg), (Bit)) == (Bit))
# define Eth_30_Tricore_VRegReadValue(CtrlIdx, Reg)                            \
    (*((volatile P2VAR(uint32, AUTOMATIC, MSR_REGSPACE))((P2VAR(void, AUTOMATIC, MSR_REGSPACE))((uint32)(Reg)))))
# define Eth_30_Tricore_VRegSetBits(CtrlIdx, Reg, Bits)                        \
    (Eth_30_Tricore_VRegReadValue((CtrlIdx), (Reg)) |= (Bits))
# define Eth_30_Tricore_VRegResetBits(CtrlIdx, Reg, Bits)                      \
    (Eth_30_Tricore_VRegReadValue((CtrlIdx), (Reg)) &= ((uint32)(((uint32)0xFFFFFFFFu) ^(Bits))))
/* PRQA L:FUNCTION_MACROS */ /* MD_MSR_19.7 */

/* Diagnostic Event Manager */
# if ( ETH_30_TRICORE_DEM_ERROR_DETECT == STD_ON )
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#  define ETH_30_TRICORE_DEM_REPORT_ERROR_STATUS_ETH_E_ACCESS(CtrlIdx) \
  (Dem_ReportErrorStatus(Eth_30_Tricore_VCfgGetDemErrorId(CtrlIdx), DEM_EVENT_STATUS_FAILED))
# else
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#  define ETH_30_TRICORE_DEM_REPORT_ERROR_STATUS_ETH_E_ACCESS(CtrlIdx)
# endif
  /* ETH_30_TRICORE_DEM_ERROR_DETECT */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define ETH_30_TRICORE_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if ( ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON )
extern VAR(Eth_StateType, ETH_30_TRICORE_VAR_ZERO_INIT) Eth_30_Tricore_State;
extern VAR(Eth_ModeType, ETH_30_TRICORE_VAR_ZERO_INIT) Eth_30_Tricore_Mode[ETH_30_TRICORE_MAX_CTRLS_TOTAL];
# endif /* ETH_30_TRICORE_DEV_ERROR_DETECT */

# define ETH_30_TRICORE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* ETH_30_TRICORE_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Tricore_Int.h
 *********************************************************************************************************************/

