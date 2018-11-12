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
 *         File:  Eth_30_Tricore_Types.h
 *      Project:  TcpIp-Stack
 *       Module:  Ethernet Driver for Tricore MAC
 *    Generator:  DrvEth_TricoreEthAsr.jar
 *
 *  Description:  types header
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
#ifndef ETH_TYPES_H
#define ETH_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Eth_30_Tricore_Cfg.h"
#include "Eth_GeneralTypes.h"
#if (ETH_30_TRICORE_ENABLE_MAC_WRITE_ACCESS == STD_ON)
#include "NvM.h"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ETH Header (field) lenghts */
#define ETH_30_TRICORE_FRAME_TYPE_LEN_BYTE                     2U
#define ETH_30_TRICORE_HDR_LEN_BYTE                           14U
#define ETH_30_TRICORE_FCS_LEN_BYTE                            4U

/* ETH Min Payload */
#define ETH_30_TRICORE_MIN_PAYLOAD                            46U

/* ETH Min frame size */
#define ETH_30_TRICORE_MIN_FRAME_SIZE                         (ETH_MIN_PAYLOAD + ETH_HDR_LEN_BYTE + ETH_ALIGN_PADDING)

/* ETH Alignment Padding */
#define ETH_30_TRICORE_ALIGN_PADDING                           2U

/* ETH Transmit Status */
#define ETH_30_TRICORE_TRANSMITTED                             0U
#define ETH_30_TRICORE_NOT_TRANSMITTED                         1U
#define ETH_30_TRICORE_TRANSMITTED_MORE_SENT                   2U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Eth_30_Tricore_ConfigType;

/* ETH Transmit Status Type */
typedef uint8 Eth_TxStatusType;

/* ETH Uint64 and Sint64 types for PTP - not supported by AUTOSAR Platform_Types.h */
#if (CPU_TYPE_32 == CPU_TYPE)
typedef unsigned long long Eth_UInt64;
typedef signed   long long Eth_SInt64;
#else
# error "16 Bit platforms currently not supported!"
#endif

#endif
  /* ETH_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Tricore_Types.h
 *********************************************************************************************************************/
