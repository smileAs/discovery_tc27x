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
 *         File:  Eth_30_Tricore_LL_Int.h
 *      Project:  TcpIp-Stack
 *       Module:  Ethernet Driver for Tricore MAC
 *    Generator:  DrvEth_30_Tricore_TricoreEthAsr.jar
 *
 *  Description:  private header
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

#ifndef ETH_30_TRICORE_LL_INT_H
#define ETH_30_TRICORE_LL_INT_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* only one instance is supported */
#define ETH_30_TRICORE_INSTANCE_ID                                0U
/* Only one descriptor ring supported */
#define ETH_30_TRICORE_RING_IDX                                   0U
#define ETH_30_TRICORE_MAX_CFGS_TOTAL                             1U
#define ETH_30_TRICORE_MAX_MII_REG_TOTAL                         32U

/* ETH Frame offsets (including offset) */
#define ETH_30_TRICORE_RX_DST_OFFSET_U8                           2U
#define ETH_30_TRICORE_RX_DST_OFFSET_U16                          1U
#define ETH_30_TRICORE_RX_SRC_OFFSET_U8                           8U
#define ETH_30_TRICORE_RX_SRC_OFFSET_U16                          4U
#define ETH_30_TRICORE_RX_SRC_OFFSET_U32                          2U
#define ETH_30_TRICORE_RX_TYPE_OFFSET_U8                         14U
#define ETH_30_TRICORE_RX_TYPE_OFFSET_U16                         7U
#define ETH_30_TRICORE_RX_DATA_OFFSET_U8                         16U
#define ETH_30_TRICORE_RX_DATA_OFFSET_U16                         8U
#define ETH_30_TRICORE_RX_DATA_OFFSET_U32                         4U
#define ETH_30_TRICORE_TX_DST_OFFSET_U8                           0U
#define ETH_30_TRICORE_TX_DST_OFFSET_U16                          0U
#define ETH_30_TRICORE_TX_SRC_OFFSET_U8                           6U
#define ETH_30_TRICORE_TX_SRC_OFFSET_U16                          3U
#define ETH_30_TRICORE_TX_TYPE_OFFSET_U8                         12U
#define ETH_30_TRICORE_TX_TYPE_OFFSET_U16                         6U
#define ETH_30_TRICORE_TX_DATA_OFFSET_U8                         14U
#define ETH_30_TRICORE_TX_DATA_OFFSET_U16                         7U

/* Tx Confirmation */
#define ETH_30_TRICORE_TX_STATE_CONFIRMATION_NOT_PENDING       0x00U
#define ETH_30_TRICORE_TX_STATE_CONFIRMATION_PENDING           0x01U

#define ETH_30_TRICORE_CONFIRMATION_NOT_CALLED                 0x00U
#define ETH_30_TRICORE_CONFIRMATION_CALLED                     0x01U

/* Buffer status */
#define ETH_30_TRICORE_BUFFER_BUSY                             0x01U
#define ETH_30_TRICORE_BUFFER_NOT_BUSY                         0x00U

/* Descriptor status */
#define ETH_30_TRICORE_DESCRIPTOR_TRANSMITTED                  0x02U
#define ETH_30_TRICORE_DESCRIPTOR_READY                        0x01U
#define ETH_30_TRICORE_DESCRIPTOR_NOT_READY                    0x00U

/* PTP status */
#define ETH_30_TRICORE_PTP_EGRESS_DESIRED                      0x01U
#define ETH_30_TRICORE_PTP_EGRESS_NOT_DESIRED                  0x00U
#define ETH_30_TRICORE_PTP_BUF2DESC_NOT_MAPPED                 0xFFU

/* Receive status */
#define ETH_30_TRICORE_FRAME_RECEIVED                          0x01U
#define ETH_30_TRICORE_FRAME_NOT_RECEIVED                      0x00U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 FUNCTION_MACROS */ /* MD_MSR_19.7 */
# define Eth_30_Tricore_VCfgGetCountersTotal(CtrlIdx)         (ETH_30_TRICORE_MMC_COUNTER_TOTAL)
# define Eth_30_Tricore_VCfgGetCountersBaseAddr(CtrlIdx)      (ETH_30_TRICORE_MMC_MEM_BASE_ADDR)
# define Eth_30_Tricore_VCfgGetCountersLastAddr(CtrlIdx)      (Eth_30_Tricore_MmcMemLastAddr[CtrlIdx])

#define ETH_30_TRICORE_BEGIN_CRITICAL_SECTION_2()             SchM_Enter_Eth_30_Tricore_ETH_30_TRICORE_EXCLUSIVE_AREA_2()
#define ETH_30_TRICORE_END_CRITICAL_SECTION_2()               SchM_Exit_Eth_30_Tricore_ETH_30_TRICORE_EXCLUSIVE_AREA_2()
/* PRQA L:FUNCTION_MACROS */ /* MD_MSR_19.7 */

#if (defined ETH_30_CORE_PROTECTED_MODE)
# if (STD_ON == ETH_30_CORE_PROTECTED_MODE)
#  define C_ENABLE_PROTECTED_MODE
#  if (!defined ETH_30_CORE_PROTECTED_AREA_ENDINIT)
#   error "ETH_30_CORE_PROTECTED_AREA_ENDINIT has to be defined when using Protected Mode"
#  endif /* C_ENABLE_PROTECTED_MODE */
# endif /* STD_ON == ETH_30_CORE_PROTECTED_MODE */
#endif /* defined ETH_30_CORE_PROTECTED_MODE */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define ETH_30_TRICORE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
ETH_30_TRICORE_INLINE FUNC(uint8, ETH_30_TRICORE_CODE) Eth_30_Tricore_Reverse(uint8 data);
FUNC(void, ETH_30_TRICORE_APPL_CODE) Appl_UnlockEndinit(void);
FUNC(void, ETH_30_TRICORE_APPL_CODE) Appl_LockEndinit(void);
# define ETH_30_TRICORE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif
  /* ETH_30_TRICORE_LL_INT_H */
/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Tricore_LL_Int.h
 *********************************************************************************************************************/
