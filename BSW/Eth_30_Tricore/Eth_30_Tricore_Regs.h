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
 *         File:  Eth_Tricore.h
 *      Project:  TcpIp-Stack
 *       Module:  Ethernet Driver for Tricore MAC
 *    Generator:  DrvEth_TricoreEthAsr.dll (DrvEth__baseAsr.dll)
 *
 *  Description:  controller specific header
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Harald Walter                 vishaw        Vector Informatik GmbH
 *  David Fessler                 visfer        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2012-09-19  vishaw  -             Initial creation
 *  01.00.01  2012-11-15  vishaw  ESCAN00063036 Version 1.0.0 only usable for integration. Implementation of
 *                                              core functionality not finished
 *  01.00.02  2013-01-16  vishaw  ESCAN00064226 Discrepancy between TX buffer and descriptor assignment.
 *                                              Obsolete payloads may be sent
 *                                ESCAN00063351 Hardware loop cancelation is missing for BUS_MODE register access
 *                                              in Eth_ControllerInit
 *  01.00.03  2013-02-01  vishaw  ESCAN00064727 Buffer index in TX confirmation gets confused.
 *                                              Upper layers may not work correctly
 *                                ESCAN00064787 Apply MISRA, PCLINT and Vector coding rules to embedded sources
 *  01.00.04  2013-03-15  vishaw  ESCAN00065655 Driver processes RX packets in a wrong order
 *                                ESCAN00065375 Formal improvements after code review
 *  01.01.00  2013-07-24  vishaw  ESCAN00069304 ASR4 Enhancement
 *                                ESCAN00069314 Eth_TxBufferStart uint16 data type overflow
 *  01.01.01  2013-10-17  vishaw  ESCAN00071190 ProvideTxBuffer assumes that it has a fitting buffer but is wrong
 *                                              because the buffer is too small
 *  02.00.00  2014-02-17  vishaw  ESCAN00073763 Introduced PTP support
 *                                ESCAN00073990 ASR4.1.1 extensions
 *                                ESCAN00069269 AR4-450: Usage of section PBCFG in PB files
 *  02.01.00  2014-07-21  vishaw  ESCAN00076448 Eth_UpdatePhysAddrFilter causes NullPointer exception when
 *                                              Eth_Controller is not initialized
 *                                ESCAN00075397 PTP: Eth_EnableEgressTimestamp returns with E_NOT_OK by mistake
 *                                ESCAN00076453 Break condition of MII access via API Eth_ReadMii() / Eth_WriteMii()
 *                                              is same as Eth_ControllerInit()
 *                                ESCAN00077408 Eth_TxConfirmation handles only one frame per function call
 *  02.02.00  2015-01-05  visfer  ESCAN00080157 AR4-535: RTM Runtime Measurement Points
 *                                ESCAN00079261 Reception Error flags in polling mode are not reset after reception
 *                                ESCAN00077422 Frames are transmitted with a wrong source MAC address
 *                                ESCAN00080840 Eth_UpdatePhysAddressFilter() may filter wrong addresses
 *  02.03.00   2015-02-27 visfer  ESCAN00081467 Compiler error: undeclared identifier "Eth_State"
 *                                ESCAN00081455 Add support for RMII
 *  02.04.00   2015-04-07 visfer  ESCAN00082282 64 bit TimestampType vs. 48 bit TimeStampType
 *  02.04.01   2015-04-16 visfer  ESCAN00082498 Compiler Error: ETH_APPL_CODE missing in internal Eth_Compiler_Cfg.inc file
 *  02.05.00   2015-07-08 visfer  ESCAN00083866 FEAT-1283: Use hardware-based checksum calculation (IPv4, IPv6, TCP, UDP and ICMP) if it is supported by the microcontroller
 *                                ESCAN00084058 Compiler error: Wrong timestamp type used
 *                                ESCAN00084059 Compiler error: Wrong Rtm measurement point used 
 *                                ESCAN00084539 Module ID not according to AUTOSAR
 *                                ESCAN00084606 Ethernet multicast packets are not received after a reset
 *  02.05.01   2015-09-24 visfer  ESCAN00085456 Controller initialization fails when Safe Context OS is used
 *  02.05.02   2015-09-29 visfer  ESCAN00085531 Compiler error: "ETH_PROTECTED_AREA_ENDINIT has to be defined when using Protected Mode
 *  02.05.03   2015-10-26 visfer  ESCAN00086029 Congestion may happen because ETH_RECEIVED_FRAMES_LOST status is returned as reception status in overflow situations
 *********************************************************************************************************************/

#ifndef ETH_30_TRICORE_REGS_H
#define ETH_30_TRICORE_REGS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* Register offsets */
#define ETH_30_TRICORE_REG_OFFS_CLC                                  0x0000U
#define ETH_30_TRICORE_REG_OFFS_ETH_GPCTL                            0x0008U
#define ETH_30_TRICORE_REG_OFFS_MAC_CFG                              0x1000U
#define ETH_30_TRICORE_REG_OFFS_MAC_FR_FILTER                        0x1004U
#define ETH_30_TRICORE_REG_OFFS_ETH_HASH_TABLE_HIGH                  0x1008U
#define ETH_30_TRICORE_REG_OFFS_ETH_HASH_TABLE_LOW                   0x100CU
#define ETH_30_TRICORE_REG_OFFS_GMII_ADDR                            0x1010U
#define ETH_30_TRICORE_REG_OFFS_GMII_DATA                            0x1014U
#define ETH_30_TRICORE_REG_OFFS_DEBUG                                0x1024U
#define ETH_30_TRICORE_REG_OFFS_PMT_CTRL                             0x102CU
#define ETH_30_TRICORE_REG_OFFS_INTERRUPT_MASK                       0x103CU
#define ETH_30_TRICORE_REG_OFFS_ADDR0_HIGH                           0x1040U
#define ETH_30_TRICORE_REG_OFFS_ADDR0_LOW                            0x1044U
#define ETH_30_TRICORE_REG_OFFS_ADDR1_HIGH                           0x1048U
#define ETH_30_TRICORE_REG_OFFS_ADDR1_LOW                            0x104CU
#define ETH_30_TRICORE_REG_OFFS_MMC_CNTRL                            0x1100U
#define ETH_30_TRICORE_REG_OFFS_TIMESTAMP_CNTRL                      0x1700U
#define ETH_30_TRICORE_REG_OFFS_SUB_SEC_INC                          0x1704U
#define ETH_30_TRICORE_REG_OFFS_SYS_TIME_SECONDS                     0x1708U
#define ETH_30_TRICORE_REG_OFFS_SYS_TIME_NANOSEC                     0x170CU
#define ETH_30_TRICORE_REG_OFFS_SYS_TIME_SEC_UPDATE                  0x1710U
#define ETH_30_TRICORE_REG_OFFS_SYS_TIME_NSEC_UPDATE                 0x1714U
#define ETH_30_TRICORE_REG_OFFS_SYS_TIME_ADDEND                      0x1718U
#define ETH_30_TRICORE_REG_OFFS_SYS_TIME_HIGH_WORD_SEC               0x1724U
#define ETH_30_TRICORE_REG_OFFS_TIMESTAMP_STATUS                     0x1728U
#define ETH_30_TRICORE_REG_OFFS_BUS_MODE                             0x2000U
#define ETH_30_TRICORE_REG_OFFS_TX_POLL_DMND                         0x2004U
#define ETH_30_TRICORE_REG_OFFS_RX_POLL_DMND                         0x2008U
#define ETH_30_TRICORE_REG_OFFS_STATUS                               0x2014U
#define ETH_30_TRICORE_REG_OFFS_OP_MODE                              0x2018U
#define ETH_30_TRICORE_REG_OFFS_RX_DESC_LIST_ADDR                    0x200CU
#define ETH_30_TRICORE_REG_OFFS_TX_DESC_LIST_ADDR                    0x2010U
#define ETH_30_TRICORE_REG_OFFS_TX_CUR_DESC                          0x2048U
#define ETH_30_TRICORE_REG_OFFS_RX_CUR_DESC                          0x204CU
#define ETH_30_TRICORE_REG_OFFS_TX_CUR_BUF                           0x2050U
#define ETH_30_TRICORE_REG_OFFS_RX_CUR_BUF                           0x2054U
#define ETH_30_TRICORE_REG_OFFS_HW_FEATURE                           0x2058U

/* ETH_MMC_CNTRL register access (MMC Control Register) */
#define ETH_30_TRICORE_REG_MMC_CNTRL_RESET                       0x00000001U

/* ETH_MAC_CONFIGURATION register access (MAC Configuration Register) */
#define ETH_30_TRICORE_REG_CFG_RE                                0x00000004U
#define ETH_30_TRICORE_REG_CFG_TE                                0x00000008U
#define ETH_30_TRICORE_REG_CFG_RE_TE                             0x0000000CU

/* ETH_MAC_FRAME_FILTER register access (MAC Frame Register) */
#define ETH_30_TRICORE_REG_FR_FILTER_PR                          0x00000001U
#define ETH_30_TRICORE_REG_FR_FILTER_PM                          0x00000010U
#define ETH_30_TRICORE_REG_FR_FILTER_HMC                         0x00000004U
#define ETH_30_TRICORE_REG_FR_FILTER_HPF                         0x00000400U

/* ETH_MAC_ADDRESS_HIGH register access (MAC Address High Register) */
#define ETH_30_TRICORE_REG_MAC_HIGH_AE                           0x80000000U
#define ETH_30_TRICORE_REG_MAC_HIGH_SA                           0x40000000U

/* ETH_GMII_ADDRESS register access (GMII Address Register) */
#define ETH_30_TRICORE_REG_GMII_ADDR_GB                          0x00000001U
#define ETH_30_TRICORE_REG_GMII_ADDR_GW                          0x00000002U
#define ETH_30_TRICORE_REG_GMII_ADDR_GR_MASK                     0x000007C0U
#define ETH_30_TRICORE_REG_GMII_ADDR_GR_SHIFT                             6U
#define ETH_30_TRICORE_REG_GMII_ADDR_PA_MASK                     0x0000F800U
#define ETH_30_TRICORE_REG_GMII_ADDR_PA_SHIFT                            11U

/* ETH_GMII_DATA register access (GMII Data Register) */
#define ETH_30_TRICORE_REG_GMII_DATA_MASK                        0x0000FFFFU

/* ETH_STATUS register access (Status Register) */
#define ETH_30_TRICORE_REG_STATUS_TI_TPS                         0x00000003U
#define ETH_30_TRICORE_REG_STATUS_TI                             0x00000001U
#define ETH_30_TRICORE_REG_STATUS_TPS                            0x00000002U
#define ETH_30_TRICORE_REG_STATUS_TU                             0x00000004U
#define ETH_30_TRICORE_REG_STATUS_TJT                            0x00000008U
#define ETH_30_TRICORE_REG_STATUS_OVF                            0x00000010U
#define ETH_30_TRICORE_REG_STATUS_UNF                            0x00000020U
#define ETH_30_TRICORE_REG_STATUS_RI                             0x00000040U
#define ETH_30_TRICORE_REG_STATUS_RU                             0x00000080U
#define ETH_30_TRICORE_REG_STATUS_RPS                            0x00000100U
#define ETH_30_TRICORE_REG_STATUS_RWT                            0x00000200U
#define ETH_30_TRICORE_REG_STATUS_ETI                            0x00000400U
#define ETH_30_TRICORE_REG_STATUS_FBI                            0x00002000U
#define ETH_30_TRICORE_REG_STATUS_ERI                            0x00004000U
#define ETH_30_TRICORE_REG_STATUS_AIS                            0x00008000U
#define ETH_30_TRICORE_REG_STATUS_NIS                            0x00010000U
#define ETH_30_TRICORE_REG_STATUS_RI_RU                          0x000000C0U
#define ETH_30_TRICORE_REG_STATUS_RI_RU_RPS                      0x000001C0U
#define ETH_30_TRICORE_REG_STATUS_RS_MASK                        0x000E0000U
#define ETH_30_TRICORE_REG_STATUS_RS_SHIFT                               17U
#define ETH_30_TRICORE_REG_STATUS_TS_MASK                        0x00700000U
#define ETH_30_TRICORE_REG_STATUS_TS_SHIFT                               20U
#define ETH_30_TRICORE_REG_STATUS_RX_ERROR_COMPOUND              (ETH_30_TRICORE_REG_STATUS_RU | ETH_30_TRICORE_REG_STATUS_OVF)

/* ETH_STATUS TS (Transmit Process State) decodings */
#define ETH_30_TRICORE_STATUS_TS_SUSPENDED                                6U
#define ETH_30_TRICORE_STATUS_TS_STOPPED                                  0U

/* ETH_STATUS TS (Receive Process State) decodings */
#define ETH_30_TRICORE_STATUS_RS_SUSPENDED                                4U
#define ETH_30_TRICORE_STATUS_RS_STOPPED                                  0U

/* ETH_PMT_CONTROL_STATUS register access (PMT Control and Status Register) */
#define ETH_30_TRICORE_REG_PMT_CTRL_PWR_DOWN                     0x00000001U

/* ETH TIMESTAMP CONTROL register */
#define ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSINIT                 0x00000004U
#define ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSUPDT                 0x00000008U
#define ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSADDREG               0x00000020U

/* ETH SYSTEM TIME NANOSECONDS UPDATE register */
#define ETH_30_TRICORE_REG_NSEC_UPDATE_ADDSUB                    0x80000000U

/* ETH_OPERATION_MODE register access (Operation Mode Register) */
#define ETH_30_TRICORE_REG_OPMODE_SR                             0x00000002U
#define ETH_30_TRICORE_REG_OPMODE_ST                             0x00002000U
#define ETH_30_TRICORE_REG_OPMODE_SR_ST                          0x00002002U

/* RX Descriptor fields */
#define ETH_30_TRICORE_RX0_DESC_OWN                              0x80000000U
#define ETH_30_TRICORE_RX0_DESC_FL                               0x3FFF0000U
#define ETH_30_TRICORE_RX0_DESC_FL_SHIFT                                 16U
#define ETH_30_TRICORE_RX0_DESC_ES                               0x00008000U
#define ETH_30_TRICORE_RX0_DESC_LS                               0x00000100U
#define ETH_30_TRICORE_RX0_DESC_FS                               0x00000200U
#define ETH_30_TRICORE_RX1_DESC_RER                              0x00008000U
#define ETH_30_TRICORE_RX1_DESC_RCH                              0x00004000U
#define ETH_30_TRICORE_RX1_DESC_RBS1_MASK                        0x000007FFU
#define ETH_30_TRICORE_RX1_DESC_RBS2_MASK                        0x003FF800U
#define ETH_30_TRICORE_RX1_DESC_RBS2_SHIFT                               11U

/* TX Descriptor fields */
#define ETH_30_TRICORE_TX0_DESC_OWN                              0x80000000U
#define ETH_30_TRICORE_TX0_DESC_IC                               0x40000000U
#define ETH_30_TRICORE_TX0_DESC_LS                               0x20000000U
#define ETH_30_TRICORE_TX0_DESC_FS                               0x10000000U
#define ETH_30_TRICORE_TX0_DESC_TTSE                             0x02000000U
#define ETH_30_TRICORE_TX0_DESC_TER                              0x00200000U
#define ETH_30_TRICORE_TX0_DESC_TCH                              0x00100000U
#define ETH_30_TRICORE_TX0_DESC_VF                               0x00000080U
#define ETH_30_TRICORE_TX0_DESC_CIC_SHIFT                                22U
#define ETH_30_TRICORE_TX0_DESC_IP_OFFLOAD                       0x00000001U
#define ETH_30_TRICORE_TX0_DESC_TRANSPORT_OFFLOAD                0x00000002U
#define ETH_30_TRICORE_TX1_DESC_TBS1_MASK                        0x000007FFU
#define ETH_30_TRICORE_TX1_DESC_TBS2_MASK                        0x003FF800U
#define ETH_30_TRICORE_TX1_DESC_TBS2_SHIFT                               11U

#endif
  /* ETH_30_TRICORE_REGS_H */
/**********************************************************************************************************************
 *  END OF FILE: Eth_Tricore.h
 *********************************************************************************************************************/
