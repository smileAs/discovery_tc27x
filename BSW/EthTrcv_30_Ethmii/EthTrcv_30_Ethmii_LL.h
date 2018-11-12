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
/**        \file  EthTrcv_30_Ethmii_LL.h
 *        \brief  Ethernet Transceiver Driver Lower Layer Implementation
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Mark Harsch                   vismha        Vector Informatik GmbH
 *  David Fessler                 visfer        Vector Informatik GmbH
 *  David Roeder                  visdrr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2014-12-2   visfer  -             Initial creation
 *  01.01.00  2015-02-13  vismha  ESCAN00081243 FEAT-705: Ethernet wakeup based on Activation Line [AR4-1006]
 *  01.02.00  2015-05-26  visfer  ESCAN00083155 Add support for extended register access and TracnsceiverInit-Callouts
 *                                ESCAN00082502 Compiler Error: ETHTRCV_30_MII_APPL_VAR has to be replaced ...
 *  01.02.01  2015-07-22  visfer  ESCAN00084134 Interrupts are not unlocked when transceiver access check fails
 *                                ESCAN00084186 Missing abstraction for MII / SPI  register access
 *  01.02.02  2015-11-23  visfer  ESCAN00086120 Auto-negotiation is performed although it is disabled
 *  01.03.00  2016-04-25  visfer  ESCAN00089729 Remove distinction between single and multiple transceiver generation
 *                                              to reduce component complexity / variants
 *  01.03.01  2016-06-13  visfer  ESCAN00090451 Compiler error: Eth_Types.h can not be included when API infixing is 
 *                                              used
 *  01.03.02  2016-10-25  visdrr  ESCAN00091917 Wrong register offset in Apis GetDuplexMode and GetBaudRate is used to
 *                                              get PHY status
 *  01.03.03  2016-11-02  visdrr  ESCAN00092628 MISRA deviation: MISRA-C:2004 Rules 4:3332 and 4:3306
 *  01.03.04  2016-12-01  visdrr  ESCAN00092830 1000 Mbit/s not supported
 *  02.00.00  2017-02-17  visdrr  ESCAN00094054 Ethernet transceiver driver core introduced
 *  02.01.00  2017-04-02  visdrr  FEATC-1234    FEAT-2234: Ethernet Link Quality Monitoring
 *  02.01.01  2017-04-11  visdrr  ESCAN00094732 Software reset during initialization does not work
 *                                ESCAN00094731 1000 Mbit/s speed setting cannot be disabled correctly if auto
 *                                              negotiation is disabled
 *                                ESCAN00094735 1000 Mbit/s is still advertised during auto-negotiation even if the
 *                                              link-speed is set to 100 Mbit/s in the configuration
 *                                ESCAN00094738 Transceiver mode is not set to down during transceiver initialization
 *********************************************************************************************************************/
#if !defined (ETHTRCV_30_ETHMII_LL_H)
# define ETHTRCV_30_ETHMII_LL_H
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# if !defined (STATIC)
#  define STATIC static
# endif
# if !defined(ETHTRCV_30_ETHMII_INLINE)
#  define ETHTRCV_30_ETHMII_INLINE STATIC INLINE
# endif
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
# if ( defined ( ETHTRCV_30_ETHMII_SOURCE ) || defined ( ETHTRCV_30_ETHMII_LL_SOURCE ) || defined ( ETHTRCV_30_ETHMII_LCFG_SOURCE ))
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  START SET MII INTERFACE
 *********************************************************************************************************************/
#  if( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_MII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetMiiInterfaceToMiiMode()
 *********************************************************************************************************************/
/*! \brief       Sets the controller interface to Mii Mode.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[out]  RetValPtr             Pointer to the memory address where the return value indicating the success of the
 *                                     operation is stored.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToMiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_MII_MODE */

#  if( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetMiiInterfaceToLightMiiMode()
 *********************************************************************************************************************/
/*! \brief       Sets the controller interface to Light Mii Mode.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[out]  RetValPtr             Pointer to the memory address where the return value indicating the success of the
 *                                     operation is stored.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToLightMiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE */

#  if( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRmiiMode()
 *********************************************************************************************************************/
/*! \brief       Sets the controller interface to Rmii Mode.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[out]  RetValPtr             Pointer to the memory address where the return value indicating the success of the
 *                                     operation is stored.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_MODE */

#  if( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRmiiXtalMode()
 *********************************************************************************************************************/
/*! \brief       Sets the controller interface to Rmii Xtal Mode.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[out]  RetValPtr             Pointer to the memory address where the return value indicating the success of the
 *                                     operation is stored.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRmiiXtalMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_GMII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetMiiInterfaceToGmiiMode()
 *********************************************************************************************************************/
/*! \brief       Sets the controller interface to Gmii Mode.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[out]  RetValPtr             Pointer to the memory address where the return value indicating the success of the
 *                                     operation is stored.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToGmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_GMII_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRgmiiMode()
 *********************************************************************************************************************/
/*! \brief       Sets the controller interface to Rgmii Mode.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[out]  RetValPtr             Pointer to the memory address where the return value indicating the success of the
 *                                     operation is stored.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRgmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRgmiiXtalMode()
 *********************************************************************************************************************/
/*! \brief       Sets the controller interface to Rgmii Xtal Mode.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[out]  RetValPtr             Pointer to the memory address where the return value indicating the success of the
 *                                     operation is stored.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRgmiiXtalMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE */
/**********************************************************************************************************************
 *  END SET MII INTERFACE
 *********************************************************************************************************************/
#  if ( ETHTRCV_30_ETHMII_LL_SET_BASIC_CONFIGURATION_REG_VAL == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetBasicConfigurationRegVal()
 *********************************************************************************************************************/
/*! \brief       Sets the basic configuration register value.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[out]  RegValPtr             Pointer to the memory address where the register value is stored.
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetBasicConfigurationRegVal(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_BASIC_CONFIGURATION_REG_VAL */

#  if ( ETHTRCV_30_ETHMII_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK == STD_ON)
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsTransceiverAccessOk()
 *********************************************************************************************************************/
/*! \brief       Checks if the transciever's registers are accessible.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      TRUE     - Transceiver registers can be read/written
 *  \return      FALSE    - Transceiver registers cannot be read/written
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsTransceiverAccessOk(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK */

#  if ( ETHTRCV_30_ETHMII_LL_IS_LINK_STATE_ACTIVE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsLinkStateActive()
 *********************************************************************************************************************/
/*! \brief       Checks if the transciever's link state is active
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   RegVal                Register value to compare
 *  \return      TRUE     - Transceiver link state is active
 *  \return      FALSE    - Transceiver link state is down
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsLinkStateActive(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_LINK_STATE_ACTIVE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_TRANSCEIVER_MODE_ACTIVE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsTransceiverModeActive()
 *********************************************************************************************************************/
/*! \brief       Checks if the transciever is in active mode
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   RegVal                Register value to compare
 *  \return      TRUE     - Transceivermode is active
 *  \return      FALSE    - Transceivermode is down
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsTransceiverModeActive(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_TRANSCEIVER_MODE_ACTIVE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_DUPLEX_MODE_FULL == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsDuplexModeFull()
 *********************************************************************************************************************/
/*! \brief       Checks if the duplex mode is full duplex.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   RegVal                Register value to compare
 *  \return      TRUE     - Duplex mode is full duplex
 *  \return      FALSE    - Duplex mode is half duplex
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsDuplexModeFull(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_DUPLEX_MODE_FULL */

#  if ( ETHTRCV_30_ETHMII_LL_IS_START_AUTO_NEG_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsStartAutoNegAvailable()
 *********************************************************************************************************************/
/*! \brief       Checks if the transceiver supports a restart of the auto negotiation.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      TRUE     - Transceiver supports a restart of the auto negotiation
 *  \return      FALSE    - Transceiver does not support a restart of the auto negotiation
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsStartAutoNegAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_START_AUTO_NEG_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_GET_BAUD_RATE_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsGetBaudRateAvailable()
 *********************************************************************************************************************/
/*! \brief       Checks if the transceiver supports the retrieval of the baud rate.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      TRUE     - Transceiver supports the retrieval of the baud rate
 *  \return      FALSE    - Transceiver does not support the retrieval of the baud rate
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsGetBaudRateAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_GET_BAUD_RATE_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_GET_DUPLEX_MODE_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsGetDuplexModeAvailable()
 *********************************************************************************************************************/
/*! \brief       Checks if the transceiver supports the retrieval of the duplex mode.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      TRUE     - Transceiver supports the retrieval of the duplex mode
 *  \return      FALSE    - Transceiver does not support the retrieval of the duplex mode
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsGetDuplexModeAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_GET_DUPLEX_MODE_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_SET_TEST_MODE_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsSetTestModeAvailable()
 *********************************************************************************************************************/
/*! \brief       Checks if the transceiver supports to set the test mode
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      TRUE     - Transceiver supports to set the test mode
 *  \return      FALSE    - Transceiver does not support to set the test mode
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsSetTestModeAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_SET_TEST_MODE_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_SIGNAL_QUALITY_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsSignalQualityAvailable()
 *********************************************************************************************************************/
/*! \brief       Checks if the transceiver supports the retrieval of the signal quality
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      TRUE     - Transceiver supports the retrieval of the signal quality
 *  \return      FALSE    - Transceiver does not support the retrieval
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsSignalQualityAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_SIGNAL_QUALITY_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_TEST_MODE_SUPPORTED_BY_HW == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsTestmodeSupportedByHw()
 *********************************************************************************************************************/
/*! \brief       Checks if a given test mode is supported by the hardware
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   TestMode              Test mode to check
 *  \return      TRUE     - Transceiver supports the given test mode
 *  \return      FALSE    - Transceiver does not support the given test mode
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsTestmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_TEST_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_ETHMII_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsLoopbackmodeSupportedByHw()
 *********************************************************************************************************************/
/*! \brief       Checks if a given loopback mode is supported by the hardware
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   LoopbackMode          Loopback mode to check
 *  \return      TRUE     - Transceiver supports the given loopback mode
 *  \return      FALSE    - Transceiver does not support the given loopback mode
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsLoopbackmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_ETHMII_LL_IS_TX_MODE_SUPPORTED_BY_HW == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsTxmodeSupportedByHw()
 *********************************************************************************************************************/
/*! \brief       Checks if a given transmission mode is supported by the hardware
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   TxMode                Transmission mode to check
 *  \return      TRUE     - Transceiver supports the given transmission mode
 *  \return      FALSE    - Transceiver does not support the given transmission mode
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean  EthTrcv_30_Ethmii_LL_IsTxmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_TX_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsCableDiagAvailable()
 *********************************************************************************************************************/
/*! \brief       Checks if the transceiver supports cable diagnostics
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      TRUE     - Transceiver supports cable diagnostics
 *  \return      FALSE    - Transceiver does not support cable diagnostics
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsCableDiagAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_FINISHED == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsCableDiagFinished()
 *********************************************************************************************************************/
/*! \brief       Checks if the transceiver's cable diagnostics has finished
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      TRUE     - Cable diagnostics has finished
 *  \return      FALSE    - Cable diagnostics has not yet finished
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsCableDiagFinished(
    uint8 TrcvIdx);
#endif /* ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_FINISHED */

#  if ( ETHTRCV_30_ETHMII_LL_IS_SW_RESET_FINISHED == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IsSwResetFinished()
 *********************************************************************************************************************/
/*! \brief       Checks if the software reset has finished
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   RegVal                Register value to be checked
 *  \return      TRUE     - Software reset has finished
 *  \return      FALSE    - Software reset has not yet finished
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsSwResetFinished(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_ETHMII_LL_IS_SW_RESET_FINISHED */

#  if ( ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_1_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_CompareIdentifier1Register()
 *********************************************************************************************************************/
/*! \brief       Compares the value of the first identifier register
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   RegVal                Register value to be checked
 *  \return      TRUE     - Value of the read register matches the phy's identifier
 *  \return      FALSE    - Value of the read register does not match the phy's identifier
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_CompareIdentifier1Register(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_1_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_2_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_CompareIdentifier2Register()
 *********************************************************************************************************************/
/*! \brief       Compares the value of the second identifier register
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   RegVal                Register value to be checked
 *  \return      TRUE     - Value of the read register matches the phy's identifier
 *  \return      FALSE    - Value of the read register does not match the phy's identifier
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_CompareIdentifier2Register(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_2_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_BASIC_CONTROL_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetBasicControlRegister()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the basic control register of the transceiver
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetBasicControlRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_BASIC_CONTROL_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_1_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetIdentifier1Register()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the first identifier register of the transceiver
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetIdentifier1Register(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_1_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_2_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetIdentifier2Register()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the second identifier register of the transceiver
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetIdentifier2Register(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_2_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_TRANSCEIVER_MODE_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetTransceiverModeRegister()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the register to set the transceiver mode
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetTransceiverModeRegister(
    uint8 TrcvIdx);
#  endif /* #if ( ETHTRCV_30_ETHMII_LL_GET_TRANSCEIVER_MODE_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_START_AUTO_NEG_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetStartAutoNegRegister()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the register to restart the auto negotiation.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetStartAutoNegRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_START_AUTO_NEG_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_LINK_STATE_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetLinkStateRegister()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the register to read the link state.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetLinkStateRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_LINK_STATE_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_BAUD_RATE_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetBaudRateRegister()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the register to read the baud rate.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetBaudRateRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_BAUD_RATE_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_DUPLEX_MODE_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetDuplexModeRegister()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the register to read the duplex mode.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetDuplexModeRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_DUPLEX_MODE_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetPhySignalQualityValueInPercent()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the register to retrieve the signal quality.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetPhySignalQualityValueInPercent(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_ETHMII_APPL_DATA) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT */

#  if ( ETHTRCV_30_ETHMII_LL_GET_SW_RESET_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetSwResetRegister()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the register to perform a software reset.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetSwResetRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_SW_RESET_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_LINK_SPEED_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_GetLinkSpeedRegister()
 *********************************************************************************************************************/
/*! \brief       Retrieves the address of the register to set the link speed.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      Retrieved register address
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetLinkSpeedRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_GET_LINK_SPEED_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_PREPARE_SW_RESET == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_PrepareSwReset()
 *********************************************************************************************************************/
/*! \brief       Prepares a software reset.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RegValPtr                  Pointer to the memory address of the read register value.
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_PrepareSwReset(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_PREPARE_SW_RESET */

#  if ( ETHTRCV_30_ETHMII_LL_INIT_GLOBAL_VARIABLES == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_InitGlobalVariables()
 *********************************************************************************************************************/
/*! \brief       Initializes global variables.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_InitGlobalVariables(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_INIT_LINK_STARTUP_DELAY */

#  if ( ETHTRCV_30_ETHMII_LL_ENABLE_LINK_STARTUP_DELAY == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_EnableLinkStartupDelay()
 *********************************************************************************************************************/
/*! \brief       Enables a delay before link startup.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_EnableLinkStartupDelay(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_ENABLE_LINK_STARTUP_DELAY */

#  if ( ETHTRCV_30_ETHMII_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_RunVendorSpecificInitScripts()
 *********************************************************************************************************************/
/*! \brief       Runs given vendor specific initializations scripts.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_RunVendorSpecificInitScripts(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS */

#  if ( ETHTRCV_30_ETHMII_LL_ENABLE_CONFIG_ACCESS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_EnableConfigAccess()
 *********************************************************************************************************************/
/*! \brief       Enables the configuration access of the transceiver.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_EnableConfigAccess(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_ENABLE_CONFIG_ACCESS */

#  if ( ETHTRCV_30_ETHMII_LL_DISABLE_CONFIG_ACCESS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_DisableConfigAccess()
 *********************************************************************************************************************/
/*! \brief       Disables the configuration access of the transceiver.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_DisableConfigAccess(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_DISABLE_CONFIG_ACCESS */

#  if ( ETHTRCV_30_ETHMII_LL_CLEAR_ALL_MODE_SETTINGS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_ClearAllModeSettings()
 *********************************************************************************************************************/
/*! \brief       Clears all preset mode settings.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RegValPtr                  Pointer to the memory address of the read register value.
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_ClearAllModeSettings(
    uint8  TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_CLEAR_ALL_MODE_SETTINGS */

#  if ( ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetRegValForTransceiverModeActive()
 *********************************************************************************************************************/
/*! \brief       Modifies the register value to set the transceiver mode to active.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RegValPtr                  Pointer to the memory address of the read register value.
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetRegValForTransceiverModeActive(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetRegValForTransceiverModeDown()
 *********************************************************************************************************************/
/*! \brief       Modifies the register value to set the transceiver mode to down.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RegValPtr                  Pointer to the memory address of the read register value.
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetRegValForTransceiverModeDown(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN */

#  if ( ETHTRCV_30_ETHMII_LL_ENABLE_START_AUTO_NEGOTIATION == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_EnableStartAutoNegotiation()
 *********************************************************************************************************************/
/*! \brief       Enables the auto negotiation.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RegValPtr                  Pointer to the memory address of the read register value.
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_EnableStartAutoNegotiation(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_ENABLE_START_AUTO_NEGOTIATION */

#  if ( ETHTRCV_30_ETHMII_LL_CHECK_BAUD_RATE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_CheckBaudRate()
 *********************************************************************************************************************/
/*! \brief       Retrieves the baud rate out of the read register value.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[in]   RegVal                     Register value to retrieve the baud rate from.
 *  \param[out]  BaudRatePtr                Pointer to the memory address where the retrieved baud rate is stored.
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_CheckBaudRate(
    uint8 TrcvIdx,
    uint16 RegVal,
    P2VAR(EthTrcv_BaudRateType, AUTOMATIC, ETHTRCV_30_ETHMII_APPL_DATA) BaudRatePtr);
#  endif /* ETHTRCV_30_ETHMII_LL_CHECK_BAUD_RATE */

#  if ( ETHTRCV_30_ETHMII_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_PrepareSignalQualityMeasurement()
 *********************************************************************************************************************/
/*! \brief       Retrieves the baud rate out of the read register value.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_PrepareSignalQualityMeasurement(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_ETHMII_APPL_DATA) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT */

#  if (ETHTRCV_30_ETHMII_LL_SET_PHY_TEST_MODE)
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetTestMode()
 *********************************************************************************************************************/
/*! \brief       Sets the phy into the given test mode.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[in]   TestMode                   Test mode for which the transceiver should be prepared
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetPhyTestMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_ETHMII_APPL_DATA) RetValPtr);
#endif /* ETHTRCV_30_ETHMII_LL_SET_PHY_TEST_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_PHY_LOOPBACK_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetPhyLoopbackMode()
 *********************************************************************************************************************/
/*! \brief       Sets the phy into the given loopback mode.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[in]   LoopbackMode               Loopback mode for which the transceiver should be prepared
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetPhyLoopbackMode(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_PHY_LOOPBACK_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_PHY_TX_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetPhyTxMode()
 *********************************************************************************************************************/
/*! \brief       Sets the phy into the given transmission mode.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[in]   TxMode                     Transmission mode for which the transceiver should be prepared
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetPhyTxMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_PHY_TX_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_FinalizeSignalQualityMeasurement()
 *********************************************************************************************************************/
/*! \brief       Performs configuration which is necessary after a signal quality measurement to resume normal operation
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_FinalizeSignalQualityMeasurement(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT */

#  if ( ETHTRCV_30_ETHMII_LL_PREPARE_CABLE_DIAG == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_PrepareCableDiag()
 *********************************************************************************************************************/
/*! \brief       Prepares the transceiver for the retrieval of the cable diagnostics result, for example triggering of
 *               the measurement.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_PrepareCableDiag(
    uint8 TrcvIdx,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_PREPARE_CABLE_DIAG */

#  if ( ETHTRCV_30_ETHMII_LL_CHECK_CABLE_DIAG_RESULT == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_CheckCableDiagResult()
 *********************************************************************************************************************/
/*! \brief       Retrieves the result of the cable diagnostics measurement.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_CheckCableDiagResult(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, AUTOMATIC) CableDiagResultPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_CHECK_CABLE_DIAG_RESULT */

#  if ( ETHTRCV_30_ETHMII_LL_ADDITIONAL_STEPS_AFTER_CABLE_DIAG == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_AdditionalStepsAfterCableDiag()
 *********************************************************************************************************************/
/*! \brief       Performs configuration which is necessary after a cable diagnostics measurement to resume normal
 *               operation
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_AdditionalStepsAfterCableDiag(
    uint8 TrcvIdx,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_CHECK_CABLE_DIAG_RESULT */

#  if ( ETHTRCV_30_ETHMII_LL_RESET_LINK_FAIL_COUNTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_ResetLinkFailCounter()
 *********************************************************************************************************************/
/*! \brief       Resets the link fail counter.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_ResetLinkFailCounter(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_RESET_LINK_FAIL_COUNTER */

#  if ( ETHTRCV_30_ETHMII_LL_INCREMENT_LINK_FAIL_COUNTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_IncrementLinkFailCounter()
 *********************************************************************************************************************/
/*! \brief       Increments the link fail counter.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_IncrementLinkFailCounter(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_INCREMENT_LINK_FAIL_COUNTER */

#  if ( ETHTRCV_30_ETHMII_LL_MAIN_FUNCTION_LINK_HANDLING == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_MainFunctionLinkHandling()
 *********************************************************************************************************************/
/*! \brief       Main function which is used for link handling.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_MainFunctionLinkHandling(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_ETHMII_LL_MAIN_FUNCTION_LINK_HANDLING */

/**********************************************************************************************************************
 *  END INLINE FUNCTIONS USED BY LCFG SOURCE
 **********************************************************************************************************************/
#  if ( ETHTRCV_30_ETHMII_LL_SET_LINK_SPEED == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_SetLinkSpeed()
 *********************************************************************************************************************/
/*! \brief       Sets the link speed.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetLinkSpeed(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_SET_LINK_SPEED */

#  if ( ETHTRCV_30_ETHMII_LL_PREPARE_LINK_SPEED_REG_VAL == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_PrepareLinkSpeedRegVal()
 *********************************************************************************************************************/
/*! \brief       Prepares the register value to set the link speed.
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_PrepareLinkSpeedRegVal(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_PREPARE_LINK_SPEED_REG_VAL */

#  if ( ETHTRCV_30_ETHMII_LL_EXTENDED_REGISTER_ACCESS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_LL_ExtendedRegisterAccess()
 *********************************************************************************************************************/
/*! \brief       Writes additional transceiver registers as configured
 *  \details     -
 *  \param[in]   TrcvIdx                    Index of the transceiver
 *  \param[out]  RetValPtr                  Pointer to the memory address where the return value of the executed
 *                                          hardware operations is stored
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_ExtendedRegisterAccess(
    uint8 TrcvIdx,
    Std_ReturnType *RetValPtr);
#  endif /* ETHTRCV_30_ETHMII_LL_EXTENDED_REGISTER_ACCESS */

/**********************************************************************************************************************
 *  END INLINE FUNCTIONS USED BY LCFG SOURCE
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITION
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  START SET MII INTERFACE
 *********************************************************************************************************************/
#  if( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_MII_MODE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToMiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_MII_MODE */

#  if( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToLightMiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE */

#  if( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_MODE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_MODE */

#  if( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRmiiXtalMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_GMII_MODE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToGmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_GMII_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_MODE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRgmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetMiiInterfaceToRgmiiXtalMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE */
/**********************************************************************************************************************
 *  END SET MII INTERFACE
 *********************************************************************************************************************/
#  if ( ETHTRCV_30_ETHMII_LL_SET_BASIC_CONFIGURATION_REG_VAL == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetBasicConfigurationRegVal(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  *RegValPtr &= (uint16)ETHTRCV_30_ETHMII_REG_BMCR_CLEAR_SETTINGS;
  *RegValPtr |= EthTrcv_30_Ethmii_RegValBasicControl[TrcvIdx];
  *RegValPtr |= ETHTRCV_30_ETHMII_REG_BMCR_POWER_DOWN;
}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_BASIC_CONFIGURATION_REG_VAL */

#  if ( ETHTRCV_30_ETHMII_LL_PREPARE_SW_RESET == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_PrepareSwReset(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  *RegValPtr |= (uint16)ETHTRCV_30_ETHMII_REG_BMCR_RESET;
}
#  endif /* ETHTRCV_30_ETHMII_LL_PREPARE_SW_RESET */

#  if ( ETHTRCV_30_ETHMII_LL_INIT_GLOBAL_VARIABLES == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_InitGlobalVariables(
    uint8 TrcvIdx)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_INIT_LINK_STARTUP_DELAY */

#  if ( ETHTRCV_30_ETHMII_LL_ENABLE_LINK_STARTUP_DELAY == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_EnableLinkStartupDelay(
    uint8 TrcvIdx)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_ENABLE_LINK_STARTUP_DELAY */

#  if ( ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_1_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_CompareIdentifier1Register(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  boolean RetValDecision;
  if(RegVal == EthTrcv_30_Ethmii_AccessCheckRegisterValue[TrcvIdx])
  {
    RetValDecision = TRUE;
  }
  else
  {
    RetValDecision = FALSE;
  }

  return RetValDecision;
}
#  endif /* ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_1_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_1_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetIdentifier1Register(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_PHYIDR1;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_1_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_2_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetIdentifier2Register(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_PHYIDR2;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_2_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK == STD_ON)
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsTransceiverAccessOk(
    uint8 TrcvIdx)
{
  boolean RetValDecision = TRUE;

  if(EthTrcv_30_Ethmii_AccessCheckEnable[TrcvIdx] == TRUE)
  {
    Std_ReturnType RetVal;
    /* Read a register from the transceiver */
    RetVal = EthTrcv_30_Ethmii_ReadAndCompare(
        TrcvIdx,
        EthTrcv_30_Ethmii_LL_GetIdentifier1Register(TrcvIdx),
        EthTrcv_30_Ethmii_LL_CompareIdentifier1Register,
        &RetValDecision);

    if(RetVal != E_OK)
    {
      RetValDecision = FALSE;
    }
  }

  return RetValDecision;
}
#  endif /* ETHTRCV_30_ETHMII_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK */

#  if ( ETHTRCV_30_ETHMII_LL_IS_LINK_STATE_ACTIVE == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsLinkStateActive(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  return (boolean)(!(0u == (uint16)(RegVal & ETHTRCV_30_ETHMII_REG_BMSR_LINK_STATE)));
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_LINK_STATE_ACTIVE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_TRANSCEIVER_MODE_ACTIVE == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsTransceiverModeActive(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  return (boolean)(0u == (RegVal & (uint16)ETHTRCV_30_ETHMII_REG_BMCR_POWER_DOWN));
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_TRANSCEIVER_MODE_ACTIVE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_DUPLEX_MODE_FULL == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsDuplexModeFull(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  return (boolean)(!(0u == (uint16)(RegVal & ETHTRCV_30_ETHMII_REG_PHYSTS_DUPLEX_STATE)));
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_DUPLEX_MODE_FULL */

#  if ( ETHTRCV_30_ETHMII_LL_IS_START_AUTO_NEG_AVAILABLE == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsStartAutoNegAvailable(
    uint8 TrcvIdx)
{
  return TRUE;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_START_AUTO_NEG_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_GET_BAUD_RATE_AVAILABLE == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsGetBaudRateAvailable(
    uint8 TrcvIdx)
{
  return TRUE;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_GET_BAUD_RATE_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_GET_DUPLEX_MODE_AVAILABLE == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsGetDuplexModeAvailable(
    uint8 TrcvIdx)
{
  return TRUE;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_GET_DUPLEX_MODE_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_SET_TEST_MODE_AVAILABLE == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsSetTestModeAvailable(
    uint8 TrcvIdx)
{
  return FALSE;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_SET_TEST_MODE_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_SIGNAL_QUALITY_AVAILABLE == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsSignalQualityAvailable(
    uint8 TrcvIdx)
{
  return FALSE;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_SIGNAL_QUALITY_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_TEST_MODE_SUPPORTED_BY_HW == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsTestmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode)
{
  boolean retValDecision;

  if( TestMode == ETHTRCV_PHYTESTMODE_NONE)
  {
    retValDecision = TRUE;
  }
  else
  {
    retValDecision = FALSE;
  }
  return retValDecision;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_TEST_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_ETHMII_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsLoopbackmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode)
{
  boolean retValDecision;

  if( (LoopbackMode == ETHTRCV_PHYLOOPBACK_NONE) ||
      (LoopbackMode == ETHTRCV_PHYLOOPBACK_INTERNAL))
  {
    retValDecision = TRUE;
  }
  else
  {
    retValDecision = FALSE;
  }
  return retValDecision;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_ETHMII_LL_IS_TX_MODE_SUPPORTED_BY_HW == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean  EthTrcv_30_Ethmii_LL_IsTxmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode)
{
  boolean retValDecision;

  if(TxMode == ETHTRCV_PHYTXMODE_NORMAL)
  {
    retValDecision = TRUE;
  }
  else
  {
    retValDecision = FALSE;
  }
  return retValDecision;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_TX_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_AVAILABLE == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsCableDiagAvailable(
    uint8 TrcvIdx)
{
  return FALSE;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_AVAILABLE */

#  if ( ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_FINISHED == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsCableDiagFinished(
    uint8 TrcvIdx)
{
  return TRUE;
}
#endif /* ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_FINISHED */

#  if ( ETHTRCV_30_ETHMII_LL_IS_SW_RESET_FINISHED == STD_ON )
ETHTRCV_30_ETHMII_INLINE boolean EthTrcv_30_Ethmii_LL_IsSwResetFinished(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  boolean RetValDecision;

  if((uint16)(RegVal & ETHTRCV_30_ETHMII_REG_BMCR_RESET) ==
     (uint16)ETHTRCV_30_ETHMII_REG_BMCR_RESET)
  {
    RetValDecision = FALSE;
  }
  else
  {
    RetValDecision = TRUE;
  }

  return RetValDecision;
}
#  endif /* ETHTRCV_30_ETHMII_LL_IS_SW_RESET_FINISHED */

#  if ( ETHTRCV_30_ETHMII_LL_GET_BASIC_CONTROL_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetBasicControlRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_BMCR;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_BASIC_CONTROL_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_TRANSCEIVER_MODE_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetTransceiverModeRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_BMCR;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_TRANSCEIVER_MODE_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_START_AUTO_NEG_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetStartAutoNegRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_BMCR;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_START_AUTO_NEG_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_LINK_STATE_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetLinkStateRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_BMSR;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_LINK_STATE_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_BAUD_RATE_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetBaudRateRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_PHYSTS;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_BAUD_RATE_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_DUPLEX_MODE_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetDuplexModeRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_PHYSTS;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_DUPLEX_MODE_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetPhySignalQualityValueInPercent(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_ETHMII_APPL_DATA) RetValPtr)
{
  return 0;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT */

#  if ( ETHTRCV_30_ETHMII_LL_GET_SW_RESET_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetSwResetRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_BMCR;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_SW_RESET_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_GET_LINK_SPEED_REGISTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE uint8 EthTrcv_30_Ethmii_LL_GetLinkSpeedRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_ETHMII_REG_OFFS_ANAR;
}
#  endif /* ETHTRCV_30_ETHMII_LL_GET_LINK_SPEED_REGISTER */

#  if ( ETHTRCV_30_ETHMII_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_RunVendorSpecificInitScripts(
    uint8 TrcvIdx)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS */

#  if ( ETHTRCV_30_ETHMII_LL_ENABLE_CONFIG_ACCESS == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_EnableConfigAccess(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_ENABLE_CONFIG_ACCESS */

#  if ( ETHTRCV_30_ETHMII_LL_SET_LINK_SPEED == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetLinkSpeed(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  uint16 regVal;

  if(EthTrcv_30_Ethmii_ConnNeg[TrcvIdx] != ETHTRCV_CONN_NEG_MANUAL)
  {
  /* The Speed settings in the BMCR register are ignored if auto negotiation is enabled.
   * Therefore only the maximum advertised speed can be configured. */
    *RetValPtr = EthTrcv_30_Ethmii_ReadModifyWrite(
        TrcvIdx,
        EthTrcv_30_Ethmii_LL_GetLinkSpeedRegister(TrcvIdx),
        EthTrcv_30_Ethmii_LL_PrepareLinkSpeedRegVal);
  }

  /* Read CFG1 register */
  *RetValPtr = EthTrcv_30_Ethmii_ReadTrcvRegister[TrcvIdx](
      EthTrcv_30_Ethmii_HwIndex[TrcvIdx],
      EthTrcv_30_Ethmii_HwSubIndex[TrcvIdx],
      ETHTRCV_30_ETHMII_REG_OFFS_CFG1,
      &regVal);

  /* Clear 1000BASE-T Advertisement choices in CFG1 Register */
  regVal &= (uint16)ETHTRCV_30_ETHMII_REG_CFG1_CLEAR_ADV_CHOICE_MASK;

  if(ETHTRCV_BAUD_RATE_1000MBIT == EthTrcv_30_Ethmii_Speed[TrcvIdx])
  {
    /* Advertise 1000BASE-T Full Duplex in CFG1 Register */
    regVal |= (uint16)(ETHTRCV_30_ETHMII_REG_CFG1_1000BASE_T_HALF_DUPLEX
                         | ETHTRCV_30_ETHMII_REG_CFG1_1000BASE_T_FULL_DUPLEX);

    if(EthTrcv_30_Ethmii_ConnNeg[TrcvIdx] == ETHTRCV_CONN_NEG_MASTER)
    {
      regVal &= (uint16)ETHTRCV_30_ETHMII_REG_CFG1_CLEAR_MS_CHOICE_MASK;
      regVal |= (uint16)ETHTRCV_30_ETHMII_REG_CFG1_SET_PHY_AS_MASTER;
    }
    else if(EthTrcv_30_Ethmii_ConnNeg[TrcvIdx] == ETHTRCV_CONN_NEG_SLAVE)
    {
      regVal &= (uint16)ETHTRCV_30_ETHMII_REG_CFG1_CLEAR_MS_CHOICE_MASK;
      regVal |= (uint16)ETHTRCV_30_ETHMII_REG_CFG1_SET_PHY_AS_SLAVE;
    }
    else
    {
      /* for MISRA compliance, is never reached due to generator implementation */
    }
  }
  /* Write to CFG1 register */
  *RetValPtr = EthTrcv_30_Ethmii_WriteTrcvRegister[TrcvIdx](
      EthTrcv_30_Ethmii_HwIndex[TrcvIdx],
      EthTrcv_30_Ethmii_HwSubIndex[TrcvIdx],
      ETHTRCV_30_ETHMII_REG_OFFS_CFG1,
      regVal);
}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_LINK_SPEED */

#  if ( ETHTRCV_30_ETHMII_LL_PREPARE_LINK_SPEED_REG_VAL == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_PrepareLinkSpeedRegVal(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  if (ETHTRCV_BAUD_RATE_10MBIT == EthTrcv_30_Ethmii_Speed[TrcvIdx])
  {
    /* Advertise 10BASE-T Full Duplex*/
    *RegValPtr &= (uint16)ETHTRCV_30_ETHMII_REG_ANAR_CLEAR_ADV_CHOICE_MASK;
    *RegValPtr |= (uint16)(ETHTRCV_30_ETHMII_REG_ANAR_10BASE_T_HALF_DUPLEX
                     | ETHTRCV_30_ETHMII_REG_ANAR_10BASE_T_FULL_DUPLEX);
  }
  else
  {
    /* Advertise 100BASE-TX Full Duplex*/
    *RegValPtr &= (uint16)ETHTRCV_30_ETHMII_REG_ANAR_CLEAR_ADV_CHOICE_MASK;
    *RegValPtr |= (uint16)(ETHTRCV_30_ETHMII_REG_ANAR_10BASE_T_HALF_DUPLEX
                     | ETHTRCV_30_ETHMII_REG_ANAR_10BASE_T_FULL_DUPLEX
                     | ETHTRCV_30_ETHMII_REG_ANAR_100BASE_TX_HALF_DUPLEX
                     | ETHTRCV_30_ETHMII_REG_ANAR_100BASE_TX_FULL_DUPLEX);
  }
}
#  endif /* ETHTRCV_30_ETHMII_LL_PREPARE_LINK_SPEED_REG_VAL */

#  if ( ETHTRCV_30_ETHMII_LL_DISABLE_CONFIG_ACCESS == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_DisableConfigAccess(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_DISABLE_CONFIG_ACCESS */

#  if ( ETHTRCV_30_ETHMII_LL_CLEAR_ALL_MODE_SETTINGS == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_ClearAllModeSettings(
    uint8  TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_CLEAR_ALL_MODE_SETTINGS */

#  if ( ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetRegValForTransceiverModeActive(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  *RegValPtr &= (uint16)(~(uint32)ETHTRCV_30_ETHMII_REG_BMCR_POWER_DOWN);
}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetRegValForTransceiverModeDown(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  *RegValPtr |= (uint16)ETHTRCV_30_ETHMII_REG_BMCR_POWER_DOWN;
}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN */

#  if ( ETHTRCV_30_ETHMII_LL_ENABLE_START_AUTO_NEGOTIATION == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_EnableStartAutoNegotiation(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  *RegValPtr |= ETHTRCV_30_ETHMII_REG_BMCR_RESTART_AUTO_NEG;
}
#  endif /* ETHTRCV_30_ETHMII_LL_ENABLE_START_AUTO_NEGOTIATION */

#  if ( ETHTRCV_30_ETHMII_LL_CHECK_BAUD_RATE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_CheckBaudRate(
    uint8 TrcvIdx,
    uint16 RegVal,
    P2VAR(EthTrcv_BaudRateType, AUTOMATIC, ETHTRCV_30_ETHMII_APPL_DATA) BaudRatePtr)
{
  if (0u == (uint16)(RegVal & ETHTRCV_30_ETHMII_REG_PHYSTS_SPEED_STATE))
  {
    *BaudRatePtr = ETHTRCV_BAUD_RATE_100MBIT;
  }
  else
  {
    *BaudRatePtr = ETHTRCV_BAUD_RATE_10MBIT;
  }
}
#  endif /* ETHTRCV_30_ETHMII_LL_CHECK_BAUD_RATE */

#  if ( ETHTRCV_30_ETHMII_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_PrepareSignalQualityMeasurement(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_ETHMII_APPL_DATA) RetValPtr)
{
  *RetValPtr = E_OK;
}
#  endif /* ETHTRCV_30_ETHMII_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT */

#  if (ETHTRCV_30_ETHMII_LL_SET_PHY_TEST_MODE)
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetPhyTestMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

} /*lint !e438 */
#endif /* ETHTRCV_30_ETHMII_LL_SET_PHY_TEST_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_SET_PHY_LOOPBACK_MODE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetPhyLoopbackMode(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  if(LoopbackMode == ETHTRCV_PHYLOOPBACK_INTERNAL)
  {
    /* Enable internal loopback mode */
    *RetValPtr = EthTrcv_30_Ethmii_ReadModifyWriteRegVal(
        TrcvIdx,
        ETHTRCV_30_ETHMII_REG_OFFS_BMCR,
        ETHTRCV_30_ETHMII_REG_BMCR_LOOPBACK_ENABLE,
        EthTrcv_30_Ethmii_SetBitsRegValPattern);
  }
  else
  {
    /* Disable internal loopback mode */
    *RetValPtr = EthTrcv_30_Ethmii_ReadModifyWriteRegVal(
        TrcvIdx,
        ETHTRCV_30_ETHMII_REG_OFFS_BMCR,
        ETHTRCV_30_ETHMII_REG_BMCR_LOOPBACK_ENABLE,
        EthTrcv_30_Ethmii_ClearBitsRegValPattern);
  }
}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_PHY_LOOPBACK_MODE */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

#  if ( ETHTRCV_30_ETHMII_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_FinalizeSignalQualityMeasurement(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT */

#  if ( ETHTRCV_30_ETHMII_LL_PREPARE_CABLE_DIAG == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_PrepareCableDiag(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  *RetValPtr = E_OK;
}
#  endif /* ETHTRCV_30_ETHMII_LL_PREPARE_CABLE_DIAG */

#  if ( ETHTRCV_30_ETHMII_LL_CHECK_CABLE_DIAG_RESULT == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_CheckCableDiagResult(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, AUTOMATIC) CableDiagResultPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_CHECK_CABLE_DIAG_RESULT */

#  if ( ETHTRCV_30_ETHMII_LL_ADDITIONAL_STEPS_AFTER_CABLE_DIAG == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_AdditionalStepsAfterCableDiag(
    uint8 TrcvIdx,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_CHECK_CABLE_DIAG_RESULT */

#  if ( ETHTRCV_30_ETHMII_LL_SET_PHY_TX_MODE == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_SetPhyTxMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_SET_PHY_TX_MODE */

#  if ( ETHTRCV_30_ETHMII_LL_MAIN_FUNCTION_LINK_HANDLING == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_MainFunctionLinkHandling(
    uint8 TrcvIdx)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_MAIN_FUNCTION_LINK_HANDLING */

#  if ( ETHTRCV_30_ETHMII_LL_RESET_LINK_FAIL_COUNTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_ResetLinkFailCounter(
    uint8 TrcvIdx)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_RESET_LINK_FAIL_COUNTER */

#  if ( ETHTRCV_30_ETHMII_LL_INCREMENT_LINK_FAIL_COUNTER == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_IncrementLinkFailCounter(
    uint8 TrcvIdx)
{

}
#  endif /* ETHTRCV_30_ETHMII_LL_INCREMENT_LINK_FAIL_COUNTER */

#  if ( ETHTRCV_30_ETHMII_LL_EXTENDED_REGISTER_ACCESS == STD_ON )
ETHTRCV_30_ETHMII_INLINE void EthTrcv_30_Ethmii_LL_ExtendedRegisterAccess(
    uint8 TrcvIdx,
    Std_ReturnType *RetValPtr)
{
  /* Extended register access */
  uint8 RegCnt = EthTrcv_30_Ethmii_ExtendedRegisterAccess[TrcvIdx].size;
  while(RegCnt > 0)
  {
    RegCnt--;
    *RetValPtr = EthTrcv_30_Ethmii_WriteTrcvRegister[TrcvIdx](
        EthTrcv_30_Ethmii_HwIndex[TrcvIdx],
        EthTrcv_30_Ethmii_HwSubIndex[TrcvIdx],
        EthTrcv_30_Ethmii_ExtendedRegisterAccess[TrcvIdx].EthTrcv_30_Ethmii_ExtendedRegisterAccessAddress[RegCnt],
        EthTrcv_30_Ethmii_ExtendedRegisterAccess[TrcvIdx].EthTrcv_30_Ethmii_ExtendedRegisterAccessValue[RegCnt]);
  }

}
#  endif /* ETHTRCV_30_ETHMII_LL_EXTENDED_REGISTER_ACCESS */
# endif /* ETHTRCV_30_ETHMII_SOURCE, ETHTRCV_30_ETHMII_LL_SOURCE, ETHTRCV_30_ETHMII_LCFG_SOURCE*/
#endif /* ETHTRCV_30_ETHMII_LL_H */
/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ethmii_LL.h
 *********************************************************************************************************************/
