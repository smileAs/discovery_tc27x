/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Eth_30_Tricore_LL.h
 *        \brief  AURIX Ethernet Driver Lower Layer Implementation
 *
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
 *  02.05.00   2015-07-08 visfer  ESCAN00083866 FEAT-1283: Use hardware-based checksum calculation (IPv4, IPv6, TCP, UDP and ICMP)
 *                                              if it is supported by the microcontroller
 *                                ESCAN00084058 Compiler error: Wrong timestamp type used
 *                                ESCAN00084059 Compiler error: Wrong Rtm measurement point used
 *                                ESCAN00084539 Module ID not according to AUTOSAR
 *                                ESCAN00084606 Ethernet multicast packets are not received after a reset
 *  02.05.01   2015-09-24 visfer  ESCAN00085456 Controller initialization fails when Safe Context OS is used
 *  02.05.02   2015-09-29 visfer  ESCAN00085531 Compiler error: "ETH_PROTECTED_AREA_ENDINIT has to be defined when using Protected Mode
 *  02.05.03   2015-10-26 visfer  ESCAN00086029 Congestion may happen because ETH_RECEIVED_FRAMES_LOST status is returned
 *                                              as reception status in overflow situations
 *  03.00.00   2016-06-06 visfer  ESCAN00090788 No unicast frames can be received on certain ECUs / with certain compilers settings
 *                                ESCAN00090859 FEAT-1738: Ethernet Receive Buffer Segmentation
 *  03.00.01   2016-08-26 visfer  ESCAN00091539 Missing ETH_END_CRITICAL_SECTION in API Eth_UpdatePhysAddrFilter before returning
 *                                              with E_NOT_OK
 *                                ESCAN00091614 Compiler Error: Eth.c undeclared identifier "ETH_INIT_HW_LOOP_MAX_CYCLES"
 *                                ESCAN00091551 Missing check for overflow of  Eth_PromisciousModeCounter in API
 *                                              Eth_UpdatePhysAddrFilter
 *                                ESCAN00090647 Access to PHYs connected to a switch and managed over MDIO by Host-CPU fails
 *  04.00.00   2016-10-20 visfer  ESCAN00092433 Ethernet driver core introduced
 *                                ESCAN00092752 Offset correction for timesync (PTP) does incorrect adaptions in some cases
 *                                ESCAN00092124 Adapt parameter checks for Eth_SetCorrectionTime to realistic assumptions
 *  04.00.01   2016-11-28 visfer  ESCAN00093063 Transmission stops when upper layers request to free several
 *                                              provided buffers
 *  04.00.02   2016-12-05 visfer  ESCAN00093162 Compiler error due to wrong API infixing in compiler_cfg.h and memmap.h
 *                                ESCAN00093451 Ethernet Switch initialization fails, because connected transceivers
 *                                              are not accessible for certain hardware layouts
 *  05.00.00   2017-03-21 visfer  ESCAN00094356 Memory violation in case a oversized ethernet frame has been received
 *********************************************************************************************************************/
#if !defined (ETH_30_TRICORE_LL_H)
# define ETH_30_TRICORE_LL_H
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Eth_30_Tricore_Regs.h"
# include "Eth_30_Tricore_LL_Int.h"
# include "Eth_30_Tricore_LL_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# ifndef ETH_30_TRICORE_INLINE
#  define ETH_30_TRICORE_INLINE static INLINE
# endif

/* ETH software version */
# define ETH_30_TRICORE_SW_MAJOR_VERSION                      5U
# define ETH_30_TRICORE_SW_MINOR_VERSION                      0U
# define ETH_30_TRICORE_SW_PATCH_VERSION                      0U

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/* ETH Multicast Defines */
# define ETH_30_TRICORE_MULTICAST_MASK                          0x01U
# define ETH_30_TRICORE_MULTICAST_BUCKET_COUNTERS                 64U
# define ETH_30_TRICORE_MULTICAST_HASH_30_26_MASK         0x7C000000U
# define ETH_30_TRICORE_MULTICAST_HASH_30_26_SHIFT                26U
# define ETH_30_TRICORE_MULTICAST_HASH_REG_IDENT          0x80000000U
# define ETH_30_TRICORE_BUCKET_MAX_CNT                          0xFFU
# define ETH_30_TRICORE_INITIAL_REMAINDER                 0xFFFFFFFFU
# define ETH_30_TRICORE_FINAL_XOR_VALUE                   0xFFFFFFFFU
# define ETH_30_TRICORE_CRC_POLYNOMIAL                    0x04C11DB7U

/* ETH Filter modes */
# define ETH_30_TRICORE_FILTER_UNICAST_MODE                        0U
# define ETH_30_TRICORE_FILTER_MULTICAST_MODE                      1U
# define ETH_30_TRICORE_FILTER_PROMISCUOUS_MODE                    2U

/* BCD coded version number */
# define DRVETH_30_TRICORE_TRICOREETHASR_VERSION         0x0400U
/* BCD coded release version number  */
# define DRVETH_30_TRICORE_TRICOREETHASR_RELEASE_VERSION   0x00U

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define ETH_30_TRICORE_START_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# if (ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON)
extern VAR(uint8, ETH_30_TRICORE_VAR_NOINIT) Eth_30_Tricore_RxDescriptorAvailabilityDelayed;
# endif /* ETH_30_TRICORE_DEV_ERROR_DETECT */
# define ETH_30_TRICORE_STOP_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define ETH_30_TRICORE_START_SEC_VAR_NOINIT_16BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# if (ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON)
/* PRQA S 3218 1 */ /* MD_Eth_30_Tricore_3218 */
extern VAR(uint16, ETH_30_TRICORE_VAR_NOINIT) Eth_30_Tricore_RxFrameStartPosition;
# endif
# define ETH_30_TRICORE_STOP_SEC_VAR_NOINIT_16BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# if defined ETH_30_TRICORE_SOURCE

#  define ETH_30_TRICORE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_InitializeRxDescriptor()
 *********************************************************************************************************************/
/*! \brief       Function for initializing an Rx descriptor
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller to be initialized
 *  \param[in]   DescrRingIdx     Index of descriptor ring to be initialized
 *  \param[in]   DescIdx          Index of descriptor to be initialized
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_InitializeRxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_InitializeTxDescriptor()
 *********************************************************************************************************************/
/*! \brief       Function for initializing a Tx descriptor
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller to be initialized
 *  \param[in]   DescrRingIdx     Index of descriptor ring to be initialized
 *  \param[in]   DescIdx          Index of descriptor to be initialized
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_InitializeTxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_SetDescriptorBaseAddresses()
 *********************************************************************************************************************/
/*! \brief       Function for announcing the descriptor base adresses to hardware
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which descriptors shall be announced
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_SetDescriptorBaseAddresses(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_InitDescriptorStateVariables()
 *********************************************************************************************************************/
/*! \brief       Function for initializing descriptor state variables, if needed by the lower layer
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller to be initialized
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_InitDescriptorStateVariables(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_InitDescriptorStateVariables()
 *********************************************************************************************************************/
/*! \brief       Function for enabling the MII access (MDIO line)
 *  \details     -
 *  \pre         -
 *  \param[in]   CtrlIdx          Index of controller where the MII access shall be enabled
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_EnableMiiAccess(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_ResetCounters()
 *********************************************************************************************************************/
/*! \brief       Function for resetting statistic counters of the MAC
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which statistic counters should be reset
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetCounters(uint8 CtrlIdx);
#if (ETH_30_TRICORE_ENABLE_PTP == STD_ON)
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_StartTimesyncClock()
 *********************************************************************************************************************/
/*! \brief       Function for starting the timesync clock of the MAC
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the timesync clock shall be started
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_StartTimesyncClock(uint8 CtrlIdx);
#endif /* ETH_30_TRICORE_ENABLE_PTP */
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_CalcCrc()
 *********************************************************************************************************************/
/*! \brief       Function for calculating the CRC needed for the physical address filter of the MAC
 *  \details     -
 *  \param[in]   PhysAddrPtr      Pointer to Physical address to calculate a crc for
 *  \return      calculated crc
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE uint32 Eth_30_Tricore_LL_CalcCrc(const uint8* PhysAddrPtr);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_PrepareTxDescriptorForChecksumOffloading()
 *********************************************************************************************************************/
/*! \brief       Function for enabling the checksum offload option in a Tx descriptor
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which checksum offloading shall be enabled
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which checksum offloading shall be enabled
 *  \param[in]   DescIdx          Index of descriptor for which checksum offloading shall be enabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_PrepareTxDescriptorForChecksumOffloading(uint8 CtrlIdx, uint8 DescrRingIdx, uint8 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_TriggerTransmission()
 *********************************************************************************************************************/
/*! \brief       Function for starting the transmission of a already prepared buffer an descriptor
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the transmission shall be triggered
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which the transmission shall be triggered
 *  \param[in]   DescIdx          Index of descriptor for which the transmission shall be triggered
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_TriggerTransmission(uint8 CtrlIdx, uint8 DescrRingIdx, uint8 DescIdx);
#if (ETH_30_TRICORE_ENABLE_PTP == STD_ON)
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_PrepareTxDescriptorForTimestamping()
 *********************************************************************************************************************/
/*! \brief       Function for enabling the timestamping option for a Tx descriptor
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which timestamping shall be prepared
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which timestamping shall be prepared
 *  \param[in]   DescIdx          Index of descriptor for which timestamping shall be prepared
 *  \param[in]   BufIdx           Index of buffer for which timestamping shall be prepared
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_PrepareTxDescriptorForTimestamping(uint8 CtrlIdx, uint8 DescrRingIdx, uint8 DescIdx, uint8 BufIdx);
#endif /* ETH_30_TRICORE_ENABLE_PTP */
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_PrepareTxDescriptorForTransmission()
 *********************************************************************************************************************/
/*! \brief       Function for doing all necessary settings to prepare a Tx descriptor for transmission
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller to be used for transmission
 *  \param[in]   DescrRingIdx     Index of descriptor ring to be used for transmission
 *  \param[in]   DescIdx          Index of descriptor to be transmitted
 *  \param[in]   BufIdx           Index of buffer to be transmitted
 *  \param[in]   LenByte          Length of frame to be transmitted
 *  \param[in]   BufferPtr        Pointer to buffer to be transmitted
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_PrepareTxDescriptorForTransmission(uint8 CtrlIdx, uint8 DescrRingIdx, uint8 DescIdx, uint8 BufIdx, uint16 LenByte, P2CONST(uint8, ETH_30_TRICORE_APPL_DATA, ETH_30_TRICORE_CONST) BufferPtr);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_EnableMac()
 *********************************************************************************************************************/
/*! \brief       Function for enabling the MAC
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller to be enabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_EnableMac(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_DisableMac()
 *********************************************************************************************************************/
/*! \brief       Function for disabling the MAC
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller to be disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_DisableMac(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_IsMacEnabled()
 *********************************************************************************************************************/
/*! \brief       Function for checking the mode of the MAC (enabled, disabled)
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller to be checked for mode
 *  \return      TRUE - MAC is enabled
 *  \return      FALSE - MAC is disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsMacEnabled(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_WriteMacAddressToRegister()
 *********************************************************************************************************************/
/*! \brief       Function for writing the configured MAC address to the hardware register
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the MAC adress shall be set
 *  \param[in]   PhysAddrPtr      Pointer to physical address to be set
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_WriteMacAddressToRegister(uint8 CtrlIdx, P2CONST(uint8, AUTOMATIC, ETH_30_TRICORE_APPL_DATA)  PhysAddrPtr);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_PreResetMac()
 *********************************************************************************************************************/
/*! \brief       Function for hardware specific operations which need to be executed before MAC reset
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller which shall be initialized
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_PreResetMac(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_ResetMac()
 *********************************************************************************************************************/
/*! \brief       Function for resetting the MAC (if needed by hardware)
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller which shall be reset
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetMac(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_IsResetMacFinished()
 *********************************************************************************************************************/
/*! \brief       Function for checking for the completion of the reset
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller which shall be checked for completion of reset
 *  \return      TRUE - MAC reset is finished
 *  \return      FALSE - MAC reset is not finished yet
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsResetMacFinished(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_EnablePromiscuousMode()
 *********************************************************************************************************************/
/*! \brief       Function for enabling the promiscuous mode
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which promiscuous mode shall be enabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_EnablePromiscuousMode(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_DisablePromiscuousMode()
 *********************************************************************************************************************/
/*! \brief       Function for disabling the promiscuous mode
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which promiscuous mode shall be disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_DisablePromiscuousMode(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_CloseAllMulticastFilters()
 *********************************************************************************************************************/
/*! \brief       Function for closing all multicast filters
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which all multicast filters shall be closed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_CloseAllMulticastFilters(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_SetMulticastFilteringMode()
 *********************************************************************************************************************/
/*! \brief       Function for enabling a certain multicast filter mode
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the multicast filter mode shall be set
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_SetMulticastFilteringMode(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_SetUpperMulticastFilterBucketRegister()
 *********************************************************************************************************************/
/*! \brief       Function for writing the upper multicast filter bucket register
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the multicast bucket register shall be set
 *  \param[in]   BucketMask       Mask which shall be set
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_SetUpperMulticastFilterBucketRegister(uint8 CtrlIdx, uint32 BucketMask);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_SetLowerMulticastFilterBucketRegister()
 *********************************************************************************************************************/
/*! \brief       Function for writing the upper multicast filter bucket register
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the multicast bucket register shall be set
 *  \param[in]   BucketMask       Mask which shall be set
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_SetLowerMulticastFilterBucketRegister(uint8 CtrlIdx, uint32 BucketMask);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_ResetUpperMulticastFilterBucketRegister()
 *********************************************************************************************************************/
/*! \brief       Function writing resetting bits in the upper multicast filter bucket register
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the multicast bucket register shall be set
 *  \param[in]   BucketMask       Mask which shall be reset
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetUpperMulticastFilterBucketRegister(uint8 CtrlIdx, uint32 BucketMask);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_ResetLowerMulticastFilterBucketRegister()
 *********************************************************************************************************************/
/*! \brief       Function writing resetting bits in the lower multicast filter bucket register
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the multicast bucket register shall be set
 *  \param[in]   BucketMask       Mask which shall be reset
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetLowerMulticastFilterBucketRegister(uint8 CtrlIdx, uint32 BucketMask);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_CalculateMulticastFilterRegisterHash()
 *********************************************************************************************************************/
/*! \brief       Function for triggering a write operation on the MII Interface (MDIO line)
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the multicast bucket register shall be set
 *  \param[in]   PhysAddrPtr      Pointer to the physical address for which a hash shall be calculated
 *  \param[out]  hash             Pointer to the variable which contains the calculated hash
 *  \param[out]  IsUpperReg       Pointer to the variable which contains the decicision which filter register shall be used
 *  \param[out]  BucketMask       Pointer to the variable which contains the mask for the filter register
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_CalculateMulticastFilterRegisterHash(uint8 CtrlIdx,
                                                                                  const uint8 *PhysAddrPtr,
                                                                                  uint8 *hash,
                                                                                  boolean *IsUpperReg,
                                                                                  uint32 *BucketMask);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_WriteMiiTrigger()
 *********************************************************************************************************************/
/*! \brief       Function for triggering a write operation on the MII Interface (MDIO line)
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the multicast bucket register shall be set
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_WriteMiiTrigger( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 RegVal);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_ReadMiiTrigger()
 *********************************************************************************************************************/
/*! \brief       Function for triggering a read operation on the MII Interface (MDIO line)
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the MII read operation shall be triggered
 *  \param[in]   TrcvIdx          Index of transceiver for which the MII read operation shall be triggered
 *  \param[in]   RegIdx           Index of register for which the MII read operation shall be triggered
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ReadMiiTrigger( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_GetReadMiiResult()
 *********************************************************************************************************************/
/*! \brief       Function for retrieving the result of a read operation on the MII Interface (MDIO line)
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the MII read operation result shall be retrieved
 *  \param[out]  RegValPtr        Pointer to register value for the result
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_GetReadMiiResult( uint8 CtrlIdx, P2VAR(uint16, AUTOMATIC, ETH_30_TRICORE_APPL_DATA) RegValPtr);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_ReadMiiGetResult()
 *********************************************************************************************************************/
/*! \brief       Function for checking the completion of an operation on the MII Interface (MDIO line)
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the MII operation completion shall be checked
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsMiiOperationPending(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_MainFunction()
 *********************************************************************************************************************/
/*! \brief       MainFunction for hardware specific cyclic operations
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_MainFunction(void);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_GetTxDescrRingIdxFromPendingInterrupt()
 *********************************************************************************************************************/
/*! \brief       Function for getting the highest priority Tx descriptor ring with pending operation
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the highest priority Tx descriptor ring with pending
 *                                operation shall be determined
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE uint8 Eth_30_Tricore_LL_GetTxDescrRingIdxFromPendingInterrupt(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_IsRxDescriptorOwnedByDriver()
 *********************************************************************************************************************/
/*! \brief       Function for retrieving the information, if a Rx descriptor is owned by DMA or driver
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the owner of a descriptor shall be checked
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which the owner of a descriptor shall be checked
 *  \param[in]   DescIdx          Index of descriptor for which the owner shall be checked
 *  \return      TRUE - descriptor is owned by driver
 *  \return      FALSE - decriptor is owned by DMA
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsRxDescriptorOwnedByDriver(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_IsTxDescriptorOwnedByDriver()
 *********************************************************************************************************************/
/*! \brief       Function for retrieving the information, if a Tx descriptor is owned by DMA or driver
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the owner of a descriptor shall be checked
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which the owner of a descriptor shall be checked
 *  \param[in]   DescIdx          Index of descriptor for which the owner shall be checked
 *  \return      TRUE - descriptor is owned by driver
 *  \return      FALSE - decriptor is owned by DMA
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsTxDescriptorOwnedByDriver(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_IsErrorinRxDescriptor()
 *********************************************************************************************************************/
/*! \brief       Function for retrieving the information, if a error flag was set in a Rx descriptor
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the owner of a descriptor shall be checked
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which the owner of a descriptor shall be checked
 *  \param[in]   DescIdx          Index of descriptor for which the owner shall be checked
 *  \return      TRUE - error flag is set in descriptor
 *  \return      FALSE - no error flags is set in decriptor
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsErrorinRxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_GetRxDescrRingIdxFromPendingInterrupt()
 *********************************************************************************************************************/
/*! \brief       Function for getting the highest priority Rx descriptor ring with pending operation
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the highest priority Rx descriptor ring with pending
 *                                operation shall be determined
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE uint8 Eth_30_Tricore_LL_GetRxDescrRingIdxFromPendingInterrupt(uint8 CtrlIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_ResetRxIntFlag()
 *********************************************************************************************************************/
/*! \brief       Function for resetting Rx Interrupt flags
 *  \details     This function does not reset hardware registers, but a software representation of pending interrupts.
 *               Interrupt flags are only modified in the interrupt handlers.
 *  \param[in]   CtrlIdx          Index of controller for which the interrupt flags shall be reset
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which the interrupt flags shall be reset
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetRxIntFlag(uint8 CtrlIdx, uint8 DescrRingIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_RechargeRxDescriptor()
 *********************************************************************************************************************/
/*! \brief       Function for recharging a Rx descriptor, after the reception of a frame was finished
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the descriptor shall be recharged
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which the descriptor shall be recharged
 *  \param[in]   DescrRingIdx     Index of descriptor which shall be recharged
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_RechargeRxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_AdaptRxDescriptorRingAfterReception
 *********************************************************************************************************************/
/*! \brief       Function for hw specific Rx descriptor operations which are necessary after a frame has been received
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the descriptor shall be adapted
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which the descriptor shall be adapted
 *  \param[in]   DescrRingIdx     Index of descriptor which shall be adapted
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_AdaptRxDescriptorRingAfterReception(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_GetFrameLengthFromRxDescriptor
 *********************************************************************************************************************/
/*! \brief       Function for retrieving the frame length of a received frame from a Rx descriptor
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the frame length shall be retrieved
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which the frame length shall be retrieved
 *  \param[in]   DescrRingIdx     Index of descriptor for which the frame length shall be retrieved
 *  \return      length extracted from a Rx descriptor
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE uint16 Eth_30_Tricore_LL_GetFrameLengthFromRxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_LL_ResetPtpStatusAfterTransmission
 *********************************************************************************************************************/
/*! \brief       Function for resetting the PTP status of a Tx descriptor after a frame has been transmitted
 *  \details     -
 *  \param[in]   CtrlIdx          Index of controller for which the PTP status shall be reset
 *  \param[in]   DescrRingIdx     Index of descriptor ring for which the PTP status shall be reset
 *  \param[in]   DescrRingIdx     Index of descriptor for which the PTP status shall be reset
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetPtpStatusAfterTransmission(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx);
/**********************************************************************************************************************
 *  Eth_30_Tricore_Reverse
 *********************************************************************************************************************/
/*! \brief       Function for reverting a byte, needed for hash algorithm
 *  \details     -
 *  \param[in]   data             Data to be reversed
 *  \return      reversed data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETH_30_TRICORE_INLINE FUNC(uint8, ETH_30_TRICORE_CODE) Eth_30_Tricore_Reverse(uint8 data);
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_InitializeRxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx)
{
  Eth_30_Tricore_RxDescriptor[DescIdx][0] = (uint32)(ETH_30_TRICORE_RX0_DESC_OWN);
  Eth_30_Tricore_RxDescriptor[DescIdx][1] = (uint32)ETH_30_TRICORE_RX1_DESC_RCH;

  /* Ensure that buffer begins on offset 2 so that the Ethernet payload begins on a 4-byte aligned address
   * (Eth header is 14 bytes long)
   */
  /* PRQA S 0306,0310 4 */ /* MD_Eth_0306 */
  Eth_30_Tricore_RxDescriptor[DescIdx][2] = (uint32)&Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, ETH_30_TRICORE_RING_IDX).BufPtr.U8
    [
      (DescIdx * Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, ETH_30_TRICORE_RING_IDX).AlignedSegmentSize) + ETH_30_TRICORE_ALIGN_PADDING
    ];
  /* Configuration of buffer length per descriptor.
   * Although it might look as if it was possible to overwrite 2 Bytes of memory behind the RxBuffer,
   * caused by ETH_30_TRICORE_ALIGN_PADDING, this can not occur. The special behaviour of the DMA for
   * unaligned memory acesses is described in the AUTIX' user manual, chapter 'Buffer Size Calculations'.*/
  if (DescIdx < (ETH_30_TRICORE_RX_BUF_TOTAL - 1))
  {
    /* PRQA S 0306 1 */ /* MD_Eth_0306 */
    Eth_30_Tricore_RxDescriptor[DescIdx][3] = (uint32)&Eth_30_Tricore_RxDescriptor[DescIdx + 1][0];
    /* Set set segment size */
    Eth_30_Tricore_RxDescriptor[DescIdx][1] |= (Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, ETH_30_TRICORE_RING_IDX).AlignedSegmentSize) & ETH_30_TRICORE_RX1_DESC_RBS1_MASK;
  }
  else
  {
    Eth_30_Tricore_RxDescriptor[DescIdx][1] |= (uint32)ETH_30_TRICORE_RX1_DESC_RER;
    /* link to first descriptor to close the ring */
    /* PRQA S 0306 1 */ /* MD_Eth_0306 */
    Eth_30_Tricore_RxDescriptor[DescIdx][3] = (uint32)&Eth_30_Tricore_RxDescriptor[0][0];
    /* Set the full frame size for the last descriptor */
    Eth_30_Tricore_RxDescriptor[DescIdx][1] |= (Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, ETH_30_TRICORE_RING_IDX).AlignedLastSegmentSize) & ETH_30_TRICORE_RX1_DESC_RBS1_MASK;
  }
}

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_InitializeTxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx)
{
  /* PRQA S 0306 3 */ /* MD_Eth_0306 */
  Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[0] = (uint32)(ETH_30_TRICORE_TX0_DESC_IC |
      ETH_30_TRICORE_TX0_DESC_LS |
      ETH_30_TRICORE_TX0_DESC_FS |
      ETH_30_TRICORE_TX0_DESC_TCH);

  /* Length and buffer index is set in Eth_Transmit */

  /* Set buffer address - updated in Eth_Transmit */
  Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[2] = 0x00000000;

  if (DescIdx < (ETH_30_TRICORE_TX_BUF_TOTAL - 1))
  {
    /* PRQA S 0306 1 */ /* MD_Eth_0306 */
    Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[3] = (uint32)&Eth_30_Tricore_TxDescriptor[DescIdx + 1].TcDescriptor[0];
  }
  else
  {
    Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[0] |= (uint32)ETH_30_TRICORE_TX0_DESC_TER;
    /* link to first descriptor to close the ring */
    /* PRQA S 0306 1 */ /* MD_Eth_0306 */
    Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[3] = (uint32)&Eth_30_Tricore_TxDescriptor[0].TcDescriptor[0];
  }

  Eth_30_Tricore_VCfgGetTxState(CtrlIdx, DescIdx) = (uint8)ETH_30_TRICORE_TX_STATE_CONFIRMATION_NOT_PENDING;
  Eth_30_Tricore_VCfgGetTxBufferBusyTable(CtrlIdx, DescIdx) = (uint8)ETH_30_TRICORE_BUFFER_NOT_BUSY;
  Eth_30_Tricore_VCfgGetTxDescriptorTxReadyTable(CtrlIdx, 0, DescIdx) = (uint8)ETH_30_TRICORE_DESCRIPTOR_NOT_READY;

#  if (ETH_30_TRICORE_ENABLE_PTP == STD_ON)
  Eth_30_Tricore_PtpEgressTable[CtrlIdx][DescIdx] = ETH_30_TRICORE_PTP_EGRESS_NOT_DESIRED;
  Eth_30_Tricore_PtpBuf2DescMap[CtrlIdx][DescIdx] = ETH_30_TRICORE_PTP_BUF2DESC_NOT_MAPPED;
#  endif /* ETH_30_TRICORE_ENABLE_PTP */
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_SetDescriptorBaseAddresses(uint8 CtrlIdx)
{
  /* PRQA S 0306 2 */ /* MD_Eth_0306 */
  Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_RX_DESC_LIST_ADDR, (uint32)&Eth_30_Tricore_RxDescriptor[0][0]);
  Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_TX_DESC_LIST_ADDR, (uint32)&Eth_30_Tricore_TxDescriptor[0].TcDescriptor[0]);
}

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_InitDescriptorStateVariables(uint8 CtrlIdx)
{
#  if (ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON)
  Eth_30_Tricore_RxFrameStartPosition = 0;
#  endif
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_EnableMiiAccess(uint8 CtrlIdx)
{
  /* #10 Delete Disable Request Bit in ETH_CLC register - otherwise module is not active */
  /* #20 configure MII mode and pin muxing configuration */
  /* Register is writable in supervisor mode only and is ENDINIT protected */
#  if  (ETH_30_TRICORE_USE_PERIPHERAL_ACCESS_API == STD_ON)
  Appl_UnlockEndinit();
  osWritePeripheral32(Eth_30_Tricore_Ctrl2ProtectedAreaIdMap[CtrlIdx], Eth_30_Tricore_RegBaseAddr[CtrlIdx] + ETH_30_TRICORE_REG_OFFS_CLC, 0x00000000U);
  osWritePeripheral32(Eth_30_Tricore_Ctrl2ProtectedAreaIdMap[CtrlIdx], Eth_30_Tricore_RegBaseAddr[CtrlIdx] + ETH_30_TRICORE_REG_OFFS_ETH_GPCTL, Eth_30_Tricore_GPCTL);
  Appl_LockEndinit();
#  else
  Appl_UnlockEndinit();
  /* PRQA S 0306 2 */ /* MD_Eth_0306 */
  Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_CLC, 0x00000000U);
  Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_ETH_GPCTL, Eth_30_Tricore_GPCTL);
  Appl_LockEndinit();
#  endif
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetCounters(uint8 CtrlIdx)
{
  /* PRQA S 0306 1 */ /* MD_Eth_0306 */
  Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_MMC_CNTRL, ETH_30_TRICORE_REG_MMC_CNTRL_RESET);
}

#if (ETH_30_TRICORE_ENABLE_PTP == STD_ON)
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_StartTimesyncClock(uint8 CtrlIdx)
{
  /* PRQA S 0306 1 */ /* MD_Eth_0306 */
  Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_TIMESTAMP_CNTRL, ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSADDREG | ETH_30_TRICORE_REG_TIMESTAMP_CTRL_TSINIT);
}
#endif

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_PrepareTxDescriptorForChecksumOffloading(uint8 CtrlIdx, uint8 DescrRingIdx, uint8 DescIdx)
{
  /* only IPv4-Header is offloaded */
#  if (STD_ON == ETH_30_TRICORE_ENABLE_OFFLOADING_IP)
        Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[0] |= (ETH_30_TRICORE_TX0_DESC_IP_OFFLOAD << ETH_30_TRICORE_TX0_DESC_CIC_SHIFT);
#  endif
  /* all checksums are offloaded */
#  if (STD_ON == ETH_30_TRICORE_ENABLE_OFFLOADING_TRANSPORT)
        Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[0] |= (ETH_30_TRICORE_TX0_DESC_TRANSPORT_OFFLOAD << ETH_30_TRICORE_TX0_DESC_CIC_SHIFT);
#  endif
}

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_TriggerTransmission(uint8 CtrlIdx, uint8 DescrRingIdx, uint8 DescIdx)
{
  /* Mark as owned by DMA */
  Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[0] |= ETH_30_TRICORE_TX0_DESC_OWN;

  /* Transmit poll demand */
  /* PRQA S 0306 1 */ /* MD_Eth_0306 */
  Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_TX_POLL_DMND, 0xFFFFFFFFU);
}

#if (ETH_30_TRICORE_ENABLE_PTP == STD_ON)
/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_PrepareTxDescriptorForTimestamping(uint8 CtrlIdx, uint8 DescrRingIdx, uint8 DescIdx, uint8 BufIdx)
{
  Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[0] |= ETH_30_TRICORE_TX0_DESC_TTSE;
}
#endif /* ETH_30_TRICORE_ENABLE_PTP */

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_PrepareTxDescriptorForTransmission(uint8 CtrlIdx, uint8 DescrRingIdx, uint8 DescIdx, uint8 BufIdx, uint16 LenByte, P2CONST(uint8, ETH_30_TRICORE_APPL_DATA, ETH_30_TRICORE_CONST) BufferPtr)
{
  /* PRQA S 0306,0310 1 */ /* MD_Eth_0306 */
  Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[2] = (uint32)BufferPtr;
  Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[1] &= ~ETH_30_TRICORE_TX1_DESC_TBS1_MASK;
  Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[1] |= ((uint32)(LenByte + ETH_30_TRICORE_HDR_LEN_BYTE)) & ETH_30_TRICORE_TX1_DESC_TBS1_MASK;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_EnableMac(uint8 CtrlIdx)
{
  /* PRQA S 0306 1 */ /* MD_Eth_0306 */
   Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_PMT_CTRL, ETH_30_TRICORE_REG_PMT_CTRL_PWR_DOWN);
   /* enable Frame transmission and reception in GMAC and DMA module */
   /* PRQA S 0306 2 */ /* MD_Eth_0306 */
   Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_MAC_CFG, ETH_30_TRICORE_REG_CFG_RE_TE);
   Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_OP_MODE, ETH_30_TRICORE_REG_OPMODE_SR_ST);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_DisableMac(uint8 CtrlIdx)
{
  /* PRQA S 0306 3 */ /* MD_Eth_0306 */
  Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_MAC_CFG, ETH_30_TRICORE_REG_CFG_RE_TE);
  Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_OP_MODE, ETH_30_TRICORE_REG_OPMODE_SR_ST);
  Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_PMT_CTRL, ETH_30_TRICORE_REG_PMT_CTRL_PWR_DOWN);
}

ETH_30_TRICORE_INLINE boolean  Eth_30_Tricore_LL_IsMacEnabled(uint8 CtrlIdx)
{
  /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
  return (boolean)(Eth_30_Tricore_VCtrlRegReadBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_PMT_CTRL, ETH_30_TRICORE_REG_PMT_CTRL_PWR_DOWN) == 0);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_WriteMacAddressToRegister(uint8 CtrlIdx, P2CONST(uint8, AUTOMATIC, ETH_30_TRICORE_APPL_DATA)  PhysAddrPtr)
{
  /* PRQA S 0306 8 */ /* MD_Eth_0306 */
     Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx,  ETH_30_TRICORE_REG_OFFS_ADDR0_HIGH,
       (uint32)((uint32)PhysAddrPtr[5] << 8) |
       ((uint32)PhysAddrPtr[4] << 0) );
     Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx,  ETH_30_TRICORE_REG_OFFS_ADDR0_LOW,
       (uint32)((uint32)PhysAddrPtr[3] << 24) |
       ((uint32)PhysAddrPtr[2] << 16) |
       ((uint32)PhysAddrPtr[1] << 8) |
       ((uint32)PhysAddrPtr[0] << 0) );
}

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_PreResetMac(uint8 CtrlIdx)
{

}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetMac(uint8 CtrlIdx)
{
  /* PRQA S 0306 2 */ /* MD_Eth_30_Tricore_0306 */
  Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_BUS_MODE, 0x00000001);
}
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsResetMacFinished(uint8 CtrlIdx)
{
  /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
  return (boolean)(Eth_30_Tricore_VCtrlRegReadBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_BUS_MODE, 0x00000001) == 0);
}

#  if (ETH_30_TRICORE_ENABLE_UPDATE_PHYS_ADDR_FILTER == STD_ON)
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_EnablePromiscuousMode(uint8 CtrlIdx)
{
  /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
  Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_MAC_FR_FILTER, ETH_30_TRICORE_REG_FR_FILTER_PR);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_DisablePromiscuousMode(uint8 CtrlIdx)
{
  /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
  Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_MAC_FR_FILTER, ETH_30_TRICORE_REG_FR_FILTER_PR);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_CloseAllMulticastFilters(uint8 CtrlIdx)
{
  /* PRQA S 0306 2 */ /* MD_Eth_30_Tricore_0306 */
  Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_ETH_HASH_TABLE_HIGH, 0xFFFFFFFFU);
  Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_ETH_HASH_TABLE_LOW, 0xFFFFFFFFU);
}

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_SetMulticastFilteringMode(uint8 CtrlIdx)
{
/* PRQA S 0306 1 */ /* MD_Eth_30_Spc58xx_0306 */
    Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_MAC_FR_FILTER, ETH_30_TRICORE_REG_FR_FILTER_HMC | ETH_30_TRICORE_REG_FR_FILTER_HPF);
}
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_SetUpperMulticastFilterBucketRegister(uint8 CtrlIdx,uint32 BucketMask)
{
  /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
  Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_ETH_HASH_TABLE_HIGH, BucketMask);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_SetLowerMulticastFilterBucketRegister(uint8 CtrlIdx, uint32 BucketMask)
{
  /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
  Eth_30_Tricore_VCtrlRegSetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_ETH_HASH_TABLE_LOW, BucketMask);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetUpperMulticastFilterBucketRegister(uint8 CtrlIdx, uint32 BucketMask)
{
  /* PRQA S 0306 1 */ /* MD_Eth_0306 */
  Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_ETH_HASH_TABLE_HIGH, BucketMask);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetLowerMulticastFilterBucketRegister(uint8 CtrlIdx, uint32 BucketMask)
{
  /* PRQA S 0306 1 */ /* MD_Eth_0306 */
  Eth_30_Tricore_VCtrlRegResetBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_ETH_HASH_TABLE_LOW, BucketMask);
}

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_CalculateMulticastFilterRegisterHash(uint8 CtrlIdx, const uint8 *PhysAddrPtr, uint8 *hash, boolean *IsUpperReg, uint32 *BucketMask)
{
  *hash = (uint8)(Eth_30_Tricore_LL_CalcCrc(PhysAddrPtr) >> 26);
  /* Find bucket */
  *BucketMask = (uint32)((uint32)1U << (*hash & 0x1F));
  *IsUpperReg = (*hash & 0x20) >> 5;
}

ETH_30_TRICORE_INLINE uint32 Eth_30_Tricore_LL_CalcCrc(const uint8* PhysAddrPtr)
{
  uint32 remainder = ETH_30_TRICORE_INITIAL_REMAINDER;
  uint8  data;
  uint8  byte;
  uint32 division;
  uint8  bit;

  for (byte = 0; byte < 6; ++byte)
  {
    data = (uint8)((Eth_30_Tricore_Reverse(PhysAddrPtr[byte])) ^ (uint8)(remainder >> 24));
    division = (uint32)((uint32)data << 24);

    for (bit = 8; bit > 0; --bit)
    {
      if (0 != (division & (uint32)((uint32)1 << 31)))
      {
        division = (division << 1) ^ ETH_30_TRICORE_CRC_POLYNOMIAL;
      }
      else
      {
        division = (division << 1);
      }
    }
    /* PRQA S 3371 1 */ /* MD_Eth_3371 */
    remainder = division ^ (remainder << 8);
  }
  return (remainder ^ ETH_30_TRICORE_FINAL_XOR_VALUE);
}

/***********************************************************************************************************************
 *  Eth_30_Tricore_Reverse
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
ETH_30_TRICORE_INLINE FUNC(uint8, ETH_30_TRICORE_CODE) Eth_30_Tricore_Reverse(uint8 data)
{
  uint8 reversed = 0x00;
  uint8_least bit;

  /* #10 Iterate over all bits. */
  for (bit = 0; bit < 8; bit++)
  {
    if ((data & 0x01) != 0)
    {
      /* #100 Reverse the data about the center bit. */
      reversed |= (uint8)(1 << (uint8)(7 - (uint8)bit));
    }

    data = (data >> 1);
  }
  return reversed;
}

#endif /* ETH_30_TRICORE_ENABLE_UPDATE_PHYS_ADDR_FILTER */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_WriteMiiTrigger(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 RegVal)
{
  uint32 CtrlRegVal;
  CtrlRegVal = ETH_30_TRICORE_REG_GMII_ADDR_GB | ETH_30_TRICORE_REG_GMII_ADDR_GW |
   ((((uint32)RegIdx) << ETH_30_TRICORE_REG_GMII_ADDR_GR_SHIFT) & ETH_30_TRICORE_REG_GMII_ADDR_GR_MASK) |
   ((((uint32)TrcvIdx) << ETH_30_TRICORE_REG_GMII_ADDR_PA_SHIFT) & ETH_30_TRICORE_REG_GMII_ADDR_PA_MASK);
  /* PRQA S 0306 2 */ /* MD_Eth_30_Tricore_0306 */
  Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_GMII_DATA, ((uint32)RegVal) & ETH_30_TRICORE_REG_GMII_DATA_MASK);
  Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_GMII_ADDR, CtrlRegVal);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ReadMiiTrigger(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx)
{
  uint32 CtrlRegVal;
  CtrlRegVal = ((((uint32)RegIdx) << ETH_30_TRICORE_REG_GMII_ADDR_GR_SHIFT) & ETH_30_TRICORE_REG_GMII_ADDR_GR_MASK) |
  ((((uint32)TrcvIdx) << ETH_30_TRICORE_REG_GMII_ADDR_PA_SHIFT) & ETH_30_TRICORE_REG_GMII_ADDR_PA_MASK) |
  ETH_30_TRICORE_REG_GMII_ADDR_GB;
  /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
  Eth_30_Tricore_VCtrlRegWriteValue(CtrlIdx, ETH_30_TRICORE_REG_OFFS_GMII_ADDR, CtrlRegVal);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_GetReadMiiResult( uint8 CtrlIdx, P2VAR(uint16, AUTOMATIC, ETH_30_TRICORE_APPL_DATA) RegValPtr)
{
  /* PRQA S 0306 1 */ /* MD_Eth_30_Tricore_0306 */
  *RegValPtr = (uint16) Eth_30_Tricore_VCtrlRegReadBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_GMII_DATA, ETH_30_TRICORE_REG_GMII_DATA_MASK);
}

ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsMiiOperationPending(uint8 CtrlIdx)
{
  /* PRQA S 0306 1 */ /* MD_Eth_0306 */
  return (boolean)(Eth_30_Tricore_VCtrlRegReadBits(CtrlIdx, ETH_30_TRICORE_REG_OFFS_GMII_ADDR, ETH_30_TRICORE_REG_GMII_ADDR_GB) != 0);
}

ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_MainFunction(void)
{
#  if (ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON)
  ETH_30_TRICORE_BEGIN_CRITICAL_SECTION_2(); /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  if (Eth_30_Tricore_RxDescriptorAvailabilityDelayed == TRUE)
  {
    Eth_RxStatusType RxStatus;
    Eth_30_Tricore_RxDescriptorAvailabilityDelayed = FALSE;
    ETH_30_TRICORE_END_CRITICAL_SECTION_2(); /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    do
    {
      Eth_30_Tricore_Receive(0, &RxStatus);
    }
    while(RxStatus == ETH_RECEIVED_MORE_DATA_AVAILABLE);
  }
  else
  {
      ETH_30_TRICORE_END_CRITICAL_SECTION_2(); /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  }
#  endif /* ETH_30_TRICORE_RX_BUFFER_SEGMENTATION == STD_ON */

#  if (ETH_30_TRICORE_DEV_ERROR_DETECT == STD_ON)
  if(ETH_STATE_MODE_ACTIVE == Eth_30_Tricore_State)
#  endif
  {
    Eth_30_Tricore_TxConfirmation(0);
  }

}

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE uint8 Eth_30_Tricore_LL_GetTxDescrRingIdxFromPendingInterrupt(uint8 CtrlIdx)
{
  return 0;
}

#  if (ETH_30_TRICORE_IMPLEMENTATION_RECEIVE == STD_ON)
/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsRxDescriptorOwnedByDriver(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx)
{
  return (boolean)((ETH_30_TRICORE_RX0_DESC_OWN & Eth_30_Tricore_RxDescriptor[DescIdx][0]) == 0);
}
#  endif

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsTxDescriptorOwnedByDriver(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx)
{
  return (boolean)((ETH_30_TRICORE_TX0_DESC_OWN & Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[0]) == 0);
}

#  if (ETH_30_TRICORE_IMPLEMENTATION_RECEIVE == STD_ON)
/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE boolean Eth_30_Tricore_LL_IsErrorinRxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx)
{
  boolean errorInDescriptor = FALSE;
  uint16 FrameLen = Eth_30_Tricore_LL_GetFrameLengthFromRxDescriptor(CtrlIdx, DescrRingIdx, DescIdx);

  if((ETH_30_TRICORE_RX0_DESC_ES & Eth_30_Tricore_RxDescriptor[DescIdx][0]) != 0)
  {
    errorInDescriptor = TRUE;
  }

  if(((ETH_30_TRICORE_RX0_DESC_FS & Eth_30_Tricore_RxDescriptor[DescIdx][0]) == 0) ||
     ((ETH_30_TRICORE_RX0_DESC_LS & Eth_30_Tricore_RxDescriptor[DescIdx][0]) == 0))
  {
    errorInDescriptor = TRUE;
  }

  if(FrameLen > Eth_30_Tricore_VCfgGetRxRing(CtrlIdx, DescrRingIdx).MaximumFrameSize)
  {
    errorInDescriptor = TRUE;
  }

  return errorInDescriptor;
}
#  endif

#  if (ETH_30_TRICORE_IMPLEMENTATION_RECEIVE == STD_ON)
/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE uint8 Eth_30_Tricore_LL_GetRxDescrRingIdxFromPendingInterrupt(uint8 CtrlIdx)
{
  return 0;
}
#  endif

#  if (ETH_30_TRICORE_IMPLEMENTATION_RECEIVE == STD_ON)
/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetRxIntFlag(uint8 CtrlIdx, uint8 DescrRingIdx)
{

}

/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_RechargeRxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx)
{
  /* Recharge buffer */
  Eth_30_Tricore_RxDescriptor[DescIdx][0] = ETH_30_TRICORE_RX0_DESC_OWN;
}
#  endif

#  if (ETH_30_TRICORE_IMPLEMENTATION_RECEIVE == STD_ON)
/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_AdaptRxDescriptorRingAfterReception(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx)
{

}
#  endif

#  if (ETH_30_TRICORE_IMPLEMENTATION_RECEIVE == STD_ON)
/* PRQA S 3206 1 */ /* MD_Eth_30_Tricore_3206 */
ETH_30_TRICORE_INLINE uint16 Eth_30_Tricore_LL_GetFrameLengthFromRxDescriptor(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx)
{
  return (uint16)((Eth_30_Tricore_RxDescriptor[DescIdx][0] & ETH_30_TRICORE_RX0_DESC_FL) >> ETH_30_TRICORE_RX0_DESC_FL_SHIFT);
}
#  endif

#if (ETH_30_TRICORE_ENABLE_PTP == STD_ON)
ETH_30_TRICORE_INLINE void Eth_30_Tricore_LL_ResetPtpStatusAfterTransmission(uint8 CtrlIdx, uint8 DescrRingIdx, uint16 DescIdx)
{
  /* Reset PTP descriptor flag */
  Eth_30_Tricore_TxDescriptor[DescIdx].TcDescriptor[0] &= (uint32)~ETH_30_TRICORE_TX0_DESC_TTSE;
  /* Reset PTP status */
  Eth_30_Tricore_PtpEgressTable[CtrlIdx][Eth_30_Tricore_TxDescriptorBufferMap[CtrlIdx][DescrRingIdx][DescIdx]] = ETH_30_TRICORE_PTP_EGRESS_NOT_DESIRED;
  Eth_30_Tricore_PtpBuf2DescMap[CtrlIdx][Eth_30_Tricore_TxDescriptorBufferMap[CtrlIdx][DescrRingIdx][DescIdx]] = ETH_30_TRICORE_PTP_BUF2DESC_NOT_MAPPED;
}
#  endif /* ETH_30_TRICORE_ENABLE_PTP == STD_ON */

#  define ETH_30_TRICORE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* if defined ETH_30_TRICORE_SOURCE */
#endif /* ETH_30_TRICORE_LL_H */

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Tricore_LL.h
 *********************************************************************************************************************/
