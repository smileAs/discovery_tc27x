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
 *         \file  EthTSyn_Cbk.h
 *        \brief  EthTSyn Callback header file
 *
 *      \details  Contains all callback function declarations with respect to the EthTSyn module
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


#if !defined(ETHTSYN_CBK_H)
# define ETHTSYN_CBK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "EthTSyn_Types.h"
# if (ETHTSYN_SWT_MGMT_SUPPORT == STD_ON)
#  include "EthTSyn_SwtMgmt_Cbk.h"
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define ETHTSYN_START_SEC_CODE
/* PRQA S 5087 */ /*  MD_MSR_19.1 */
# include "MemMap.h"

/**********************************************************************************************************************
 *  EthTSyn_RxIndication
 *********************************************************************************************************************/
/*! \brief        Processing of received EthTSyn frames.
 *  \description  By this API service the EthTSyn gets an indication and the data of a received frame.
 *  \param[in]    CtrlIdx     Index of the Ethernet controller
 *  \param[in]    FrameType   Frame type of received Ethernet frame
 *  \param[in]    IsBroadcast Parameter to indicate a broadcast frame
 *  \param[in]    PhysAddrPtr Pointer to the Physical source address (MAC address in network byte order) of received
 *                            Ethernet frame
 *  \param[in]    DataPtr     Pointer to payload of the received Ethernet frame (i.e. Ethernet header is not provided)
 *  \param[in]    LenByte     Length of received data
 *  \return       none
 *  \pre          The function EthTSyn_Init() must be called first
 *  \context      This function can be called in any context.
 *********************************************************************************************************************/
# if ( defined(ETHTSYN_ETHIF_AR_VERSION_GREATER_EQUAL_4_2_2) && \
      (ETHTSYN_ETHIF_AR_VERSION_GREATER_EQUAL_4_2_2 == TRUE) )
FUNC(void, ETHTSYN_CODE) EthTSyn_RxIndication(
                  uint8         CtrlIdx,
                  Eth_FrameType FrameType,
                  boolean       IsBroadcast,
  ETHTSYN_P2CONST(uint8)        PhysAddrPtr,
    ETHTSYN_P2VAR(uint8)        DataPtr,
                  uint16        LenByte);
# else
FUNC(void, ETHTSYN_CODE) EthTSyn_RxIndication(
                uint8         CtrlIdx,
                Eth_FrameType FrameType,
                boolean       IsBroadcast,
  ETHTSYN_P2VAR(uint8)        PhysAddrPtr,
  ETHTSYN_P2VAR(uint8)        DataPtr,
                uint16        LenByte);
# endif

/**********************************************************************************************************************
 *  EthTSyn_TxConfirmation
 *********************************************************************************************************************/
/*! \brief        Confirms the transmission of an Ethernet frame
 *  \description  This callback function is called by lower layer (EthIf) if a message has been transmitted by the
 *                hardware.
 *  \param[in]    CtrlIdx    Index of the Ethernet controller within the context of the Ethernet Interface
 *  \param[in]    BufIdx     Index of the buffer resource
 *  \return       none
 *  \pre          The function EthTSyn_Init() must be called first
 *  \context      This function can be called in interrupt or task context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_TxConfirmation(
  uint8 CtrlIdx,
  uint8 BufIdx);

/**********************************************************************************************************************
 *  EthTSyn_TrcvLinkStateChg
 *********************************************************************************************************************/
/*! \brief        Callback function that notifies a changed state of the transceiver link
 *  \description  Allows resetting state machine in case of unexpected Link loss to avoid inconsistent
                  Sync and Follow_Up sequences
 *  \param[in]    CtrlIdx         Index of the Ethernet controller
 *  \param[in]    TrcvLinkState   New link state of the transceiver
 *  \return       none
 *  \pre          The function EthTSyn_Init() must be called first
 *  \context      This function can be in any context.
 *********************************************************************************************************************/
FUNC(void, ETHTSYN_CODE) EthTSyn_TrcvLinkStateChg(
  uint8                 CtrlIdx,
  EthTrcv_LinkStateType TrcvLinkState);

# define ETHTSYN_STOP_SEC_CODE
/* PRQA S 5087 */ /*  MD_MSR_19.1 */
# include "MemMap.h"

# endif
 /* ETHTSYN_CBK_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_Cbk.h
 *********************************************************************************************************************/
