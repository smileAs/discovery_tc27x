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
/**        \file  EthTrcv_30_Tja1100_LL.h
 *        \brief  Ethernet Transceiver Driver Lower Layer Implementation
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  David Fessler                 visfer        Vector Informatik GmbH
 *  David Roeder                  visdrr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2015-01-29  visfer  -             Initial creation
 *  01.01.00  2015-03-30  visfer  ESCAN00082159 FEAT-705: Ethernet wakeup based on Activation Line [AR4-1006]
 *  01.01.01  2015-04-29  visfer  ESCAN00082746 Compiler error when wakeup is enabled
 *  01.01.02  2015-06-02  visfer  ESCAN00083237 Compiler error when more than one Tja1100 Transceiver is used
 *  01.01.03  2015-08-10  visfer  ESCAN00084434 Compiler error when DET is disabled
 *  01.01.04  2015-12-08  visfer  ESCAN00085848 Link is reported as active although cable is not connected
 *                                ESCAN00086588 Compiler error: declaration may not appear after executable statement in block
 *  01.01.05  2015-02-26  visfer  ESCAN00088599 Duplicate configuration structure for Mii mode is generated
 *  01.02.00  2016-04-26  visfer  ESCAN00089734 Remove distinction between single and multiple transceiver generation
 *                                              to reduce component complexity / variants
 *  01.03.00  2016-06-23  visfer  ESCAN00090726 Link is not reestablished after a loss of link
 *  01.04.00  2016-08-04  visfer  ESCAN00091330 Add support for Tja1102
 *                                ESCAN00091389 Wrong api switch in EthTrcv_30_Tja1100.c
 *                                              (used ENABLE_GET_BAUD_RATE instead of ENABLE_GET_DUPLEX_MODE)
 *  01.04.01  2016-09-01  visfer  ESCAN00091704 Compiler error:"ETHTRCV_30_TJA1100_DERIVATIVE_TJA1100" is undefined
 *  01.04.02  2016-11-07  visdrr  ESCAN00092046 Variable in ZERO_INIT section has no value assignment
 *  01.04.03  2016-12-14  visfer  ESCAN00092405 Link startup behaviour is not implemented according to NXP
 *                                              ApplicationHints_v12. Link startup and ethernet communication may fail
 *  02.00.00  2017-02-16  visdrr  ESCAN00094037 Ethernet transceiver driver core introduced
 *  02.01.00  2017-03-14  visdrr  FEATC-676     FEAT-2234: Ethernet Link Quality Monitoring
 *  02.01.01  2017-04-27  visdrr  ESCAN00092405 Link startup behaviour is not implemented according to NXP
 *                                              ApplicationHints_v12. Link startup and ethernet communication may fail.
 *                                ESCAN00094672 Support TxMode Off and Scrambler Off
 *********************************************************************************************************************/
#if !defined (ETHTRCV_30_TJA1100_LL_H)
# define ETHTRCV_30_TJA1100_LL_H
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
# if !defined(ETHTRCV_30_TJA1100_INLINE)
#  define ETHTRCV_30_TJA1100_INLINE STATIC INLINE
# endif

# define ETHTRCV_30_TJA1100_NO_LINK_STARTUP                    (0xFFU) /* The link startup delay counter is disabled */
# define ETHTRCV_30_TJA1100_LINK_STATE_DELAY_MS                (100U)  /* Timer value in ms after which the link state is
                                                                          checked if extended link state checking is enabled */
# define ETHTRCV_30_TJA1100_LINK_STATE_DELAY_TIMEOUT_MS        (200U)  /* Timeout value for the extended link state check */
# define ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_0               (0x00U) /* No link startup required */
# define ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_1               (0x01U) /* Link startup required, enable link startup delay */
# define ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_2               (0x02U) /* Link startup delay passed, enable LINK_CONTROL */
# define ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_3               (0x03U) /* Wait for the timeout of the 100 ms counter */
# define ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_4               (0x04U) /* Check link state and if stable --> State 5 */
# define ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_5               (0x05U) /* Link up and stable, normal operation */
# define ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_6               (0x06U) /* Link fail counter overeflow or timout --> SW Reset */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
# if defined(ETHTRCV_30_TJA1100_SOURCE)
#  define ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_8BIT
#  include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

STATIC VAR(uint8, ETHTRCV_30_TJA1100_VAR_NOINIT) EthTrcv_30_Tja1100_LinkStartupState[ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL];

#  define ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_8BIT
#  include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

#  define ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_32BIT
#  include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

STATIC VAR(uint32, ETHTRCV_30_TJA1100_VAR_NOINIT) EthTrcv_30_Tja1100_LinkStartupDelayCounter[ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL];
STATIC VAR(uint32, ETHTRCV_30_TJA1100_VAR_NOINIT) EthTrcv_30_Tja1100_LinkStateDelayCounter[ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL];
STATIC VAR(uint32, ETHTRCV_30_TJA1100_VAR_NOINIT) EthTrcv_30_Tja1100_LinkStateTimeoutCounter[ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL];

#  define ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_32BIT
#  include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# endif /* ETHTRCV_30_TJA1100_SOURCE */
# if ( defined ( ETHTRCV_30_TJA1100_SOURCE ) || defined ( ETHTRCV_30_TJA1100_LL_SOURCE ) || defined ( ETHTRCV_30_TJA1100_LCFG_SOURCE ))
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  START SET MII INTERFACE
 *********************************************************************************************************************/
#  if( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_MII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetMiiInterfaceToMiiMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToMiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_MII_MODE */

#  if( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetMiiInterfaceToLightMiiMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToLightMiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE */

#  if( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RMII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRmiiMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RMII_MODE */

#  if( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRmiiXtalMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRmiiXtalMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_GMII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetMiiInterfaceToGmiiMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToGmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_GMII_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RGMII_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRgmiiMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRgmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RGMII_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRgmiiXtalMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRgmiiXtalMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE */
/**********************************************************************************************************************
 *  END SET MII INTERFACE
 *********************************************************************************************************************/
#  if ( ETHTRCV_30_TJA1100_LL_SET_BASIC_CONFIGURATION_REG_VAL == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetBasicConfigurationRegVal()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetBasicConfigurationRegVal(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_BASIC_CONFIGURATION_REG_VAL */

#  if ( ETHTRCV_30_TJA1100_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK == STD_ON)
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsTransceiverAccessOk()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsTransceiverAccessOk(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK */

#  if ( ETHTRCV_30_TJA1100_LL_IS_LINK_STATE_ACTIVE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsLinkStateActive()
 *********************************************************************************************************************/
/*! \brief       Checks if the transciever's link state is active
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   RegVal                Register value to compare
 *  \return      TRUE     - Transceiver link state is active
 *  \return      FALSE    - Transceiver link state is down
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Tja1100_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsLinkStateActive(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_LINK_STATE_ACTIVE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_TRANSCEIVER_MODE_ACTIVE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsTransceiverModeActive()
 *********************************************************************************************************************/
/*! \brief       Checks if the transciever is in active mode
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   RegVal                Register value to compare
 *  \return      TRUE     - Transceivermode is active
 *  \return      FALSE    - Transceivermode is down
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Tja1100_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsTransceiverModeActive(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_TRANSCEIVER_MODE_ACTIVE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_DUPLEX_MODE_FULL == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsDuplexModeFull()
 *********************************************************************************************************************/
/*! \brief       Checks if the duplex mode is full duplex.
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   RegVal                Register value to compare
 *  \return      TRUE     - Duplex mode is full duplex
 *  \return      FALSE    - Duplex mode is half duplex
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Tja1100_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsDuplexModeFull(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_DUPLEX_MODE_FULL */

#  if ( ETHTRCV_30_TJA1100_LL_IS_START_AUTO_NEG_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsStartAutoNegAvailable()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsStartAutoNegAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_START_AUTO_NEG_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_GET_BAUD_RATE_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsGetBaudRateAvailable()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsGetBaudRateAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_GET_BAUD_RATE_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_GET_DUPLEX_MODE_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsGetDuplexModeAvailable()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsGetDuplexModeAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_GET_DUPLEX_MODE_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_SET_TEST_MODE_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsSetTestModeAvailable()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsSetTestModeAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_SET_TEST_MODE_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_SIGNAL_QUALITY_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsSignalQualityAvailable()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsSignalQualityAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_SIGNAL_QUALITY_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_TEST_MODE_SUPPORTED_BY_HW == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsTestmodeSupportedByHw()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsTestmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_TEST_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_TJA1100_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsLoopbackmodeSupportedByHw()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsLoopbackmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_TJA1100_LL_IS_TX_MODE_SUPPORTED_BY_HW == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsTxmodeSupportedByHw()
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
ETHTRCV_30_TJA1100_INLINE boolean  EthTrcv_30_Tja1100_LL_IsTxmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_TX_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_TJA1100_LL_IS_CABLE_DIAG_AVAILABLE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsCableDiagAvailable()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsCableDiagAvailable(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_CABLE_DIAG_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_CABLE_DIAG_FINISHED == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsCableDiagFinished()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsCableDiagFinished(
    uint8 TrcvIdx);
#endif /* ETHTRCV_30_TJA1100_LL_IS_CABLE_DIAG_FINISHED */

#  if ( ETHTRCV_30_TJA1100_LL_IS_SW_RESET_FINISHED == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IsSwResetFinished()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsSwResetFinished(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_TJA1100_LL_IS_SW_RESET_FINISHED */

#  if ( ETHTRCV_30_TJA1100_LL_COMPARE_IDENTIFIER_1_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_CompareIdentifier1Register()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_CompareIdentifier1Register(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_TJA1100_LL_COMPARE_IDENTIFIER_1_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_COMPARE_IDENTIFIER_2_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_CompareIdentifier2Register()
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
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_CompareIdentifier2Register(
    uint8 TrcvIdx,
    uint16 RegVal);
#  endif /* ETHTRCV_30_TJA1100_LL_COMPARE_IDENTIFIER_2_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_BASIC_CONTROL_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetBasicControlRegister()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetBasicControlRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_BASIC_CONTROL_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_IDENTIFIER_1_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetIdentifier1Register()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetIdentifier1Register(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_IDENTIFIER_1_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_IDENTIFIER_2_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetIdentifier2Register()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetIdentifier2Register(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_IDENTIFIER_2_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_TRANSCEIVER_MODE_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetTransceiverModeRegister()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetTransceiverModeRegister(
    uint8 TrcvIdx);
#  endif /* #if ( ETHTRCV_30_TJA1100_LL_GET_TRANSCEIVER_MODE_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_START_AUTO_NEG_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetStartAutoNegRegister()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetStartAutoNegRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_START_AUTO_NEG_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_LINK_STATE_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetLinkStateRegister()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetLinkStateRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_LINK_STATE_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_BAUD_RATE_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetBaudRateRegister()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetBaudRateRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_BAUD_RATE_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_DUPLEX_MODE_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetDuplexModeRegister()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetDuplexModeRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_DUPLEX_MODE_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetPhySignalQualityValueInPercent()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetPhySignalQualityValueInPercent(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT */

#  if ( ETHTRCV_30_TJA1100_LL_GET_SW_RESET_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetSwResetRegister()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetSwResetRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_SW_RESET_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_LINK_SPEED_REGISTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_GetLinkSpeedRegister()
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
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetLinkSpeedRegister(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_GET_LINK_SPEED_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_PREPARE_SW_RESET == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_PrepareSwReset()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_PrepareSwReset(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_PREPARE_SW_RESET */

#  if ( ETHTRCV_30_TJA1100_LL_INIT_GLOBAL_VARIABLES == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_InitGlobalVariables()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_InitGlobalVariables(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_INIT_LINK_STARTUP_DELAY */

#  if ( ETHTRCV_30_TJA1100_LL_ENABLE_LINK_STARTUP_DELAY == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_EnableLinkStartupDelay()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_EnableLinkStartupDelay(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_ENABLE_LINK_STARTUP_DELAY */

#  if ( ETHTRCV_30_TJA1100_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_RunVendorSpecificInitScripts()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_RunVendorSpecificInitScripts(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS */

#  if ( ETHTRCV_30_TJA1100_LL_ENABLE_CONFIG_ACCESS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_EnableConfigAccess()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_EnableConfigAccess(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_ENABLE_CONFIG_ACCESS */

#  if ( ETHTRCV_30_TJA1100_LL_DISABLE_CONFIG_ACCESS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_DisableConfigAccess()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_DisableConfigAccess(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_DISABLE_CONFIG_ACCESS */

#  if ( ETHTRCV_30_TJA1100_LL_CLEAR_ALL_MODE_SETTINGS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_ClearAllModeSettings()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_ClearAllModeSettings(
    uint8  TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_CLEAR_ALL_MODE_SETTINGS */

#  if ( ETHTRCV_30_TJA1100_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetRegValForTransceiverModeActive()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetRegValForTransceiverModeActive(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetRegValForTransceiverModeDown()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetRegValForTransceiverModeDown(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN */

#  if ( ETHTRCV_30_TJA1100_LL_ENABLE_START_AUTO_NEGOTIATION == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_EnableStartAutoNegotiation()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_EnableStartAutoNegotiation(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_ENABLE_START_AUTO_NEGOTIATION */

#  if ( ETHTRCV_30_TJA1100_LL_CHECK_BAUD_RATE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_CheckBaudRate()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_CheckBaudRate(
    uint8 TrcvIdx,
    uint16 RegVal,
    P2VAR(EthTrcv_BaudRateType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) BaudRatePtr);
#  endif /* ETHTRCV_30_TJA1100_LL_CHECK_BAUD_RATE */

#  if ( ETHTRCV_30_TJA1100_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_PrepareSignalQualityMeasurement()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_PrepareSignalQualityMeasurement(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT */

#  if (ETHTRCV_30_TJA1100_LL_SET_PHY_TEST_MODE)
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetTestMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetPhyTestMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) RetValPtr);
#endif /* ETHTRCV_30_TJA1100_LL_SET_PHY_TEST_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_PHY_LOOPBACK_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetPhyLoopbackMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetPhyLoopbackMode(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_PHY_LOOPBACK_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_PHY_TX_MODE == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetPhyTxMode()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetPhyTxMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_PHY_TX_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_FinalizeSignalQualityMeasurement()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_FinalizeSignalQualityMeasurement(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT */

#  if ( ETHTRCV_30_TJA1100_LL_PREPARE_CABLE_DIAG == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_PrepareCableDiag()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_PrepareCableDiag(
    uint8 TrcvIdx,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_PREPARE_CABLE_DIAG */

#  if ( ETHTRCV_30_TJA1100_LL_CHECK_CABLE_DIAG_RESULT == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_CheckCableDiagResult()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_CheckCableDiagResult(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, AUTOMATIC) CableDiagResultPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_CHECK_CABLE_DIAG_RESULT */

#  if ( ETHTRCV_30_TJA1100_LL_ADDITIONAL_STEPS_AFTER_CABLE_DIAG == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_AdditionalStepsAfterCableDiag()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_AdditionalStepsAfterCableDiag(
    uint8 TrcvIdx,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_CHECK_CABLE_DIAG_RESULT */

#  if ( ETHTRCV_30_TJA1100_LL_RESET_LINK_FAIL_COUNTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_ResetLinkFailCounter()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_ResetLinkFailCounter(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_RESET_LINK_FAIL_COUNTER */

#  if ( ETHTRCV_30_TJA1100_LL_INCREMENT_LINK_FAIL_COUNTER == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_IncrementLinkFailCounter()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_IncrementLinkFailCounter(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_INCREMENT_LINK_FAIL_COUNTER */

#  if ( ETHTRCV_30_TJA1100_LL_MAIN_FUNCTION_LINK_HANDLING == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_MainFunctionLinkHandling()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_MainFunctionLinkHandling(
    uint8 TrcvIdx);
#  endif /* ETHTRCV_30_TJA1100_LL_MAIN_FUNCTION_LINK_HANDLING */

/**********************************************************************************************************************
 *  END INLINE FUNCTIONS USED BY LCFG SOURCE
 **********************************************************************************************************************/
#  if ( ETHTRCV_30_TJA1100_LL_SET_LINK_SPEED == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_SetLinkSpeed()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetLinkSpeed(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_SET_LINK_SPEED */

#  if ( ETHTRCV_30_TJA1100_LL_PREPARE_LINK_SPEED_REG_VAL == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_PrepareLinkSpeedRegVal()
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_PrepareLinkSpeedRegVal(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_PREPARE_LINK_SPEED_REG_VAL */

#  if ( ETHTRCV_30_TJA1100_LL_APPLY_ADDITIONAL_CONFIG_STEPS == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_LL_ApplyAdditionalConfigSteps()
 *********************************************************************************************************************/
/*! \brief       Applies additional configuration steps if necessary
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
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_ApplyAdditionalConfigSteps(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr);
#  endif /* ETHTRCV_30_TJA1100_LL_APPLY_ADDITIONAL_CONFIG_STEPS */

/**********************************************************************************************************************
 *  END INLINE FUNCTIONS USED BY LCFG SOURCE
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITION
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  START SET MII INTERFACE
 *********************************************************************************************************************/
#  if( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_MII_MODE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToMiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  /* Clear current mii mode settings (is equal to mii mode) */
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_CFG1,
      ETHTRCV_30_TJA1100_REG_CFG1_MII_MODE_MASK,
      EthTrcv_30_Tja1100_ClearBitsRegValPattern);
}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_MII_MODE */

#  if( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToLightMiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE */

#  if( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RMII_MODE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  /* Clear current mii mode settings */
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_CFG1,
      ETHTRCV_30_TJA1100_REG_CFG1_MII_MODE_MASK,
      EthTrcv_30_Tja1100_ClearBitsRegValPattern);

  /* Set mii mode to rmii */
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_CFG1,
      ETHTRCV_30_TJA1100_REG_CFG1_RMII_MODE,
      EthTrcv_30_Tja1100_SetBitsRegValPattern);
}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RMII_MODE */

#  if( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRmiiXtalMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  /* Clear current mii mode settings */
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_CFG1,
      ETHTRCV_30_TJA1100_REG_CFG1_MII_MODE_MASK,
      EthTrcv_30_Tja1100_ClearBitsRegValPattern);

  /* Set mii mode to rmii xtal*/
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_CFG1,
      ETHTRCV_30_TJA1100_REG_CFG1_RMII_MODE_XTAL,
      EthTrcv_30_Tja1100_SetBitsRegValPattern);
}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_GMII_MODE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToGmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_GMII_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RGMII_MODE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRgmiiMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RGMII_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRgmiiXtalMode(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE */
/**********************************************************************************************************************
 *  END SET MII INTERFACE
 *********************************************************************************************************************/
#  if ( ETHTRCV_30_TJA1100_LL_SET_BASIC_CONFIGURATION_REG_VAL == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetBasicConfigurationRegVal(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  *RegValPtr &= (uint16)ETHTRCV_30_TJA1100_REG_CFG1_CLEAR_SETTINGS;
  *RegValPtr |= EthTrcv_30_Tja1100_RegValBasicControl[TrcvIdx];
}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_BASIC_CONFIGURATION_REG_VAL */

#  if ( ETHTRCV_30_TJA1100_LL_PREPARE_SW_RESET == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_PrepareSwReset(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_PREPARE_SW_RESET */

#  if ( ETHTRCV_30_TJA1100_LL_INIT_GLOBAL_VARIABLES == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_InitGlobalVariables(
    uint8 TrcvIdx)
{
  EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_0;
  EthTrcv_30_Tja1100_LinkStartupDelayCounter[TrcvIdx] = ETHTRCV_30_TJA1100_NO_LINK_STARTUP;
  EthTrcv_30_Tja1100_LinkStateDelayCounter[TrcvIdx] = 0;
  EthTrcv_30_Tja1100_LinkFailCounter[TrcvIdx] = 0;
  EthTrcv_30_Tja1100_LinkStateTimeoutCounter[TrcvIdx] = 0;
}
#  endif /* ETHTRCV_30_TJA1100_LL_INIT_LINK_STARTUP_DELAY */

#  if ( ETHTRCV_30_TJA1100_LL_ENABLE_LINK_STARTUP_DELAY == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_EnableLinkStartupDelay(
    uint8 TrcvIdx)
{
  EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_1;
  /* At least 2 ms */
  EthTrcv_30_Tja1100_LinkStartupDelayCounter[TrcvIdx] =  (EthTrcv_30_Tja1100_LinkStartupDelay[TrcvIdx] / ETHTRCV_30_TJA1100_MAINFUNCTION_LINKHANDLING_MS);
  /* 100 ms */
  EthTrcv_30_Tja1100_LinkStateDelayCounter[TrcvIdx] = (uint32)(ETHTRCV_30_TJA1100_LINK_STATE_DELAY_MS / ETHTRCV_30_TJA1100_MAINFUNCTION_LINKHANDLING_MS);
  /* 200 ms */
  EthTrcv_30_Tja1100_LinkStateTimeoutCounter[TrcvIdx] = (uint32)(ETHTRCV_30_TJA1100_LINK_STATE_DELAY_TIMEOUT_MS / ETHTRCV_30_TJA1100_MAINFUNCTION_LINKHANDLING_MS);

  EthTrcv_30_Tja1100_LinkFailCounter[TrcvIdx] = 0;
}
#  endif /* ETHTRCV_30_TJA1100_LL_ENABLE_LINK_STARTUP_DELAY */

#  if ( ETHTRCV_30_TJA1100_LL_COMPARE_IDENTIFIER_1_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_CompareIdentifier1Register(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  boolean retValDecision;
  if(RegVal == ETHTRCV_30_TJA1100_REG_PHYIDR1_NXP_OUI_MSB)
  {
    retValDecision = TRUE;
  }
  else
  {
    retValDecision = FALSE;
  }
  return retValDecision;
}
#  endif /* ETHTRCV_30_TJA1100_LL_COMPARE_IDENTIFIER_1_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_IDENTIFIER_1_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetIdentifier1Register(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_TJA1100_REG_OFFS_PHYIDR1;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_IDENTIFIER_1_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_IDENTIFIER_2_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetIdentifier2Register(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_TJA1100_REG_OFFS_PHYIDR2;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_IDENTIFIER_2_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK == STD_ON)
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsTransceiverAccessOk(
    uint8 TrcvIdx)
{
  uint16         regVal         = 0;
  Std_ReturnType retVal         = E_NOT_OK;
  boolean        retValDecision = FALSE;

  /* check transceiver access */
  if(EthTrcv_30_Tja1100_Derivative[TrcvIdx] == ETHTRCV_30_TJA1100_DERIVATIVE_TJA1100)
  {
    retVal = EthTrcv_30_Tja1100_ReadAndCompare(
        TrcvIdx,
        EthTrcv_30_Tja1100_LL_GetIdentifier1Register(TrcvIdx),
        EthTrcv_30_Tja1100_LL_CompareIdentifier1Register,
        &retValDecision);
  }
  else if(EthTrcv_30_Tja1100_Derivative[TrcvIdx] == ETHTRCV_30_TJA1100_DERIVATIVE_TJA1102)
  {
    /* PHY is connected via MII interface */
    if(EthTrcv_30_Tja1100_P0MiiAddress[TrcvIdx] != ETHTRCV_DONT_CARE)
    {
      retVal = EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
          EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
          EthTrcv_30_Tja1100_P0MiiAddress[TrcvIdx],
          ETHTRCV_30_TJA1100_REG_OFFS_PHYIDR1,
          &regVal);
    }
    else /* PHY is managed by switch */
    {
      retVal = EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
        EthTrcv_30_Tja1100_P0SwitchIdx[TrcvIdx],
        EthTrcv_30_Tja1100_P0SwitchPortIdx[TrcvIdx],
        ETHTRCV_30_TJA1100_REG_OFFS_PHYIDR1,
        &regVal);
    }
    retValDecision = EthTrcv_30_Tja1100_LL_CompareIdentifier1Register(TrcvIdx, regVal);
  }
  else
  {
    /* There is no other derivative supported */
    retVal = E_NOT_OK;
  }

  if( (retVal != E_OK) )
  {
    retValDecision = FALSE;
  }

  return retValDecision;
}
#  endif /* ETHTRCV_30_TJA1100_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK */

#  if ( ETHTRCV_30_TJA1100_LL_IS_LINK_STATE_ACTIVE == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsLinkStateActive(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  boolean retValDecision;

  if((uint16)(RegVal & ETHTRCV_30_TJA1100_REG_COM_STAT_LINK_STATE) ==  ETHTRCV_30_TJA1100_REG_COM_STAT_LINK_STATE)
  {
    EthTrcv_30_Tja1100_LL_ResetLinkFailCounter(TrcvIdx);

    /* No extended link state check is performed or it has already completed sucessfully */
    if(EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] == ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_5)
    {
      retValDecision = TRUE;
    }
    else
    {
      retValDecision = FALSE;
    }
  }
  else
  {
    /* Link state is down and the link fail counter increases */
    retValDecision = FALSE;
  }
  return retValDecision;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_LINK_STATE_ACTIVE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_TRANSCEIVER_MODE_ACTIVE == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsTransceiverModeActive(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  boolean retValDecision;

  if((RegVal & (uint16)ETHTRCV_30_TJA1100_REG_EXTCTRL_MODE_MASK) == (uint16)ETHTRCV_30_TJA1100_REG_EXTCTRL_NORMAL_MODE)
  {
    retValDecision = TRUE;
  }
  else
  {
    retValDecision = FALSE;
  }
  return retValDecision;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_TRANSCEIVER_MODE_ACTIVE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_DUPLEX_MODE_FULL == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsDuplexModeFull(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  boolean retValDecision;

  if((RegVal & ETHTRCV_30_TJA1100_REG_BMCR_DUPLEX_MODE_FULL) == 0)
  {
    retValDecision = FALSE;
  }
  else
  {
    retValDecision = TRUE;
  }
  return retValDecision;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_DUPLEX_MODE_FULL */

#  if ( ETHTRCV_30_TJA1100_LL_IS_START_AUTO_NEG_AVAILABLE == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsStartAutoNegAvailable(
    uint8 TrcvIdx)
{
  return FALSE;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_START_AUTO_NEG_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_GET_BAUD_RATE_AVAILABLE == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsGetBaudRateAvailable(
    uint8 TrcvIdx)
{
  return TRUE;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_GET_BAUD_RATE_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_GET_DUPLEX_MODE_AVAILABLE == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsGetDuplexModeAvailable(
    uint8 TrcvIdx)
{
  return TRUE;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_GET_DUPLEX_MODE_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_SET_TEST_MODE_AVAILABLE == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsSetTestModeAvailable(
    uint8 TrcvIdx)
{
  return TRUE;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_SET_TEST_MODE_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_SIGNAL_QUALITY_AVAILABLE == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsSignalQualityAvailable(
    uint8 TrcvIdx)
{
  return TRUE;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_SIGNAL_QUALITY_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_TEST_MODE_SUPPORTED_BY_HW == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsTestmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode)
{
  boolean retValDecision;

  if((TestMode == ETHTRCV_PHYTESTMODE_NONE)||
     (TestMode == ETHTRCV_PHYTESTMODE_1)   ||
     (TestMode == ETHTRCV_PHYTESTMODE_2)   ||
     (TestMode == ETHTRCV_PHYTESTMODE_3)   ||
     (TestMode == ETHTRCV_PHYTESTMODE_4)   ||
     (TestMode == ETHTRCV_PHYTESTMODE_5)   ||
     (TestMode == ETHTRCV_30_TJA1100_PHY_TEST_MODE_6))
  {
    retValDecision = TRUE;
  }
  else
  {
    retValDecision = FALSE;
  }
  return retValDecision;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_TEST_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_TJA1100_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsLoopbackmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode)
{
  boolean retValDecision;

  if((LoopbackMode == ETHTRCV_PHYLOOPBACK_NONE)     ||
     (LoopbackMode == ETHTRCV_PHYLOOPBACK_INTERNAL) ||
     (LoopbackMode == ETHTRCV_PHYLOOPBACK_EXTERNAL) ||
     (LoopbackMode == ETHTRCV_PHYLOOPBACK_REMOTE))
  {
    retValDecision = TRUE;
  }
  else
  {
    retValDecision = FALSE;
  }

  return retValDecision;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_TJA1100_LL_IS_TX_MODE_SUPPORTED_BY_HW == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean  EthTrcv_30_Tja1100_LL_IsTxmodeSupportedByHw(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode)
{
  boolean retValDecision;

  if((TxMode == ETHTRCV_PHYTXMODE_NORMAL) ||
     (TxMode == ETHTRCV_PHYTXMODE_TX_OFF) ||
     (TxMode == ETHTRCV_PHYTXMODE_SCRAMBLER_OFF))
  {
    retValDecision = TRUE;
  }
  else
  {
    retValDecision = FALSE;
  }
  return retValDecision;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_TX_MODE_SUPPORTED_BY_HW */

#  if ( ETHTRCV_30_TJA1100_LL_IS_CABLE_DIAG_AVAILABLE == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsCableDiagAvailable(
    uint8 TrcvIdx)
{
  return TRUE;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_CABLE_DIAG_AVAILABLE */

#  if ( ETHTRCV_30_TJA1100_LL_IS_CABLE_DIAG_FINISHED == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsCableDiagFinished(
    uint8 TrcvIdx)
{
  uint16 regVal;
  Std_ReturnType retVal;
  boolean retValDecision = FALSE;

  retVal = EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
    EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
    EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
    ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
    &regVal);

  if(retVal == E_OK)
  {
    if((regVal & (uint16)ETHTRCV_30_TJA1100_REG_EXTCTRL_CABLE_TEST_ENABLE)
              == (uint16)ETHTRCV_30_TJA1100_REG_EXTCTRL_CABLE_TEST_ENABLE)
    {
      retValDecision = FALSE;
    }
    else
    {
      retValDecision = TRUE;
    }
  }

  return retValDecision;
}
#endif /* ETHTRCV_30_TJA1100_LL_IS_CABLE_DIAG_FINISHED */

#  if ( ETHTRCV_30_TJA1100_LL_IS_SW_RESET_FINISHED == STD_ON )
ETHTRCV_30_TJA1100_INLINE boolean EthTrcv_30_Tja1100_LL_IsSwResetFinished(
    uint8 TrcvIdx,
    uint16 RegVal)
{
  boolean RetValDecision;

  if((RegVal & ETHTRCV_30_TJA1100_REG_BMCR_RESET) == 0)
  {
    RetValDecision = TRUE;
  }
  else
  {
    RetValDecision = FALSE;
  }

  return RetValDecision;
}
#  endif /* ETHTRCV_30_TJA1100_LL_IS_SW_RESET_FINISHED */

#  if ( ETHTRCV_30_TJA1100_LL_GET_BASIC_CONTROL_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetBasicControlRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_TJA1100_REG_OFFS_CFG1;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_BASIC_CONTROL_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_TRANSCEIVER_MODE_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetTransceiverModeRegister(
    uint8 TrcvIdx)
{
  return ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_TRANSCEIVER_MODE_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_START_AUTO_NEG_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetStartAutoNegRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_TJA1100_REG_OFFS_BMCR;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_START_AUTO_NEG_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_LINK_STATE_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetLinkStateRegister(
    uint8 TrcvIdx)
{
  return ETHTRCV_30_TJA1100_REG_OFFS_COM_STAT;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_LINK_STATE_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_BAUD_RATE_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetBaudRateRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_TJA1100_REG_OFFS_BMSR;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_BAUD_RATE_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_DUPLEX_MODE_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetDuplexModeRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_TJA1100_REG_OFFS_BMCR;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_DUPLEX_MODE_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetPhySignalQualityValueInPercent(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) RetValPtr)
{
  uint16 regVal;
  uint8 signalQualityValue;

  *RetValPtr = EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
      EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
      EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
      ETHTRCV_30_TJA1100_REG_OFFS_COM_STAT,
      &regVal);

  if(*RetValPtr == E_OK)
  {
    signalQualityValue = (uint8)((regVal & ETHTRCV_30_TJA1100_REG_COM_STAT_SIGNAL_QUALITY_MASK)
                                       >> ETHTRCV_30_TJA1100_REG_COM_STAT_SIGNAL_QUALITY_SHIFT);

    signalQualityValue = (uint8)(((uint16)signalQualityValue * 100) / 7);
  }
  else
  {
    signalQualityValue = 0;
  }

  return signalQualityValue;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT */

#  if ( ETHTRCV_30_TJA1100_LL_GET_SW_RESET_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetSwResetRegister(
    uint8 TrcvIdx)
{
  return (uint8)ETHTRCV_30_TJA1100_REG_OFFS_BMCR;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_SW_RESET_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_GET_LINK_SPEED_REGISTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_LL_GetLinkSpeedRegister(
    uint8 TrcvIdx)
{
  return 0;
}
#  endif /* ETHTRCV_30_TJA1100_LL_GET_LINK_SPEED_REGISTER */

#  if ( ETHTRCV_30_TJA1100_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_RunVendorSpecificInitScripts(
    uint8 TrcvIdx)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS */

#  if ( ETHTRCV_30_TJA1100_LL_ENABLE_CONFIG_ACCESS == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_EnableConfigAccess(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_CONFIG_EN,
      EthTrcv_30_Tja1100_SetBitsRegValPattern);
}
#  endif /* ETHTRCV_30_TJA1100_LL_ENABLE_CONFIG_ACCESS */

#  if ( ETHTRCV_30_TJA1100_LL_SET_LINK_SPEED == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetLinkSpeed(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_LINK_SPEED */

#  if ( ETHTRCV_30_TJA1100_LL_PREPARE_LINK_SPEED_REG_VAL == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_PrepareLinkSpeedRegVal(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_PREPARE_LINK_SPEED_REG_VAL */

#  if ( ETHTRCV_30_TJA1100_LL_APPLY_ADDITIONAL_CONFIG_STEPS == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_ApplyAdditionalConfigSteps(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

  if(EthTrcv_30_Tja1100_Derivative[TrcvIdx] == ETHTRCV_30_TJA1100_DERIVATIVE_TJA1102)
  {
    /* Disable AUTO-OP */
    *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
        TrcvIdx,
        ETHTRCV_30_TJA1100_REG_OFFS_COMMON_CFG,
        ETHTRCV_30_TJA1100_REG_CFG1_AUTO_OP_TJA1102,
        EthTrcv_30_Tja1100_ClearBitsRegValPattern);
  }
  else
  {
    /* For MISRA */
  }
  /* Set the transceiver mode to down */
  *RetValPtr |= EthTrcv_30_Tja1100_WriteTrcvRegister[TrcvIdx](
      EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
      EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_STANDBY_MODE);
}
#  endif /* ETHTRCV_30_TJA1100_LL_APPLY_ADDITIONAL_CONFIG_STEPS */

#  if ( ETHTRCV_30_TJA1100_LL_DISABLE_CONFIG_ACCESS == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_DisableConfigAccess(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  /* disable config access */
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_CONFIG_EN,
      EthTrcv_30_Tja1100_ClearBitsRegValPattern);
}
#  endif /* ETHTRCV_30_TJA1100_LL_DISABLE_CONFIG_ACCESS */

#  if ( ETHTRCV_30_TJA1100_LL_CLEAR_ALL_MODE_SETTINGS == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_ClearAllModeSettings(
    uint8  TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  *RegValPtr &= (uint16)(~(ETHTRCV_30_TJA1100_REG_EXTCTRL_MODE_MASK | ETHTRCV_30_TJA1100_REG_EXTCTRL_LINK_CONTROL));
}
#  endif /* ETHTRCV_30_TJA1100_LL_CLEAR_ALL_MODE_SETTINGS */

#  if ( ETHTRCV_30_TJA1100_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetRegValForTransceiverModeActive(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  *RegValPtr |= (uint16)(ETHTRCV_30_TJA1100_REG_EXTCTRL_NORMAL_MODE);
}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetRegValForTransceiverModeDown(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  *RegValPtr |= (uint16)ETHTRCV_30_TJA1100_REG_EXTCTRL_STANDBY_MODE;
}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN */

#  if ( ETHTRCV_30_TJA1100_LL_ENABLE_START_AUTO_NEGOTIATION == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_EnableStartAutoNegotiation(
    uint8 TrcvIdx,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_ENABLE_START_AUTO_NEGOTIATION */

#  if ( ETHTRCV_30_TJA1100_LL_CHECK_BAUD_RATE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_CheckBaudRate(
    uint8 TrcvIdx,
    uint16 RegVal,
    P2VAR(EthTrcv_BaudRateType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) BaudRatePtr)
{
  *BaudRatePtr = ETHTRCV_BAUD_RATE_100MBIT;
}
#  endif /* ETHTRCV_30_TJA1100_LL_CHECK_BAUD_RATE */

#  if ( ETHTRCV_30_TJA1100_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_PrepareSignalQualityMeasurement(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) RetValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT */

#  if (ETHTRCV_30_TJA1100_LL_SET_PHY_TEST_MODE)
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetPhyTestMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  uint16 regVal = 0;

  EthTrcv_30_Tja1100_LL_EnableConfigAccess(TrcvIdx, RetValPtr);

  /* Clear current test mode setting */
  *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_TEST_MODE_MASK,
      EthTrcv_30_Tja1100_ClearBitsRegValPattern);

  if((TestMode == ETHTRCV_PHYTESTMODE_1) ||
     (TestMode == ETHTRCV_PHYTESTMODE_2) ||
     (TestMode == ETHTRCV_PHYTESTMODE_3) ||
     (TestMode == ETHTRCV_PHYTESTMODE_4) ||
     (TestMode == ETHTRCV_PHYTESTMODE_5))
  {
    /* Setup chosen test mode */
    regVal = ((uint16)TestMode << ETHTRCV_30_TJA1100_REG_EXTCTRL_TEST_MODE_SHIFT);

    /* Write test mode setting */
    *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
        TrcvIdx,
        ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
        regVal,
        EthTrcv_30_Tja1100_SetBitsRegValPattern);

    /* Disable link control */
    *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
        TrcvIdx,
        ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
        ETHTRCV_30_TJA1100_REG_EXTCTRL_LINK_CONTROL,
        EthTrcv_30_Tja1100_ClearBitsRegValPattern);
  }
  else
  {
    /* Enable link control */
    *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
        TrcvIdx,
        ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
        ETHTRCV_30_TJA1100_REG_EXTCTRL_LINK_CONTROL,
        EthTrcv_30_Tja1100_SetBitsRegValPattern);
  }

  EthTrcv_30_Tja1100_LL_DisableConfigAccess(TrcvIdx, RetValPtr);
} /*lint !e438 */
#endif /* ETHTRCV_30_TJA1100_LL_SET_PHY_TEST_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_SET_PHY_LOOPBACK_MODE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetPhyLoopbackMode(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  uint16 regVal;

  /* Read the loopback mode configuration register */
  *RetValPtr = EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
      EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
      EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      &regVal);

  /* Clear the loopback mode settings */
  regVal &= (uint16)ETHTRCV_30_TJA1100_REG_EXTCTRL_LOOPBACK_MODE_CLEAR;

  if(LoopbackMode == ETHTRCV_PHYLOOPBACK_EXTERNAL)
  {
    /* Enable external loopback */
    regVal |= (uint16)ETHTRCV_30_TJA1100_REG_EXTCTRL_LOOPBACK_MODE_EXT;
  }
  else if(LoopbackMode == ETHTRCV_PHYLOOPBACK_REMOTE)
  {
    /* Enable remote loopback */
    regVal |= (uint16)ETHTRCV_30_TJA1100_REG_EXTCTRL_LOOPBACK_MODE_REM;
  }
  else
  {
    /* Bits already cleared */
  }

  /* #Write the loopback mode configuration register */
  *RetValPtr |= EthTrcv_30_Tja1100_WriteTrcvRegister[TrcvIdx](
      EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
      EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      regVal);

  /* Enable config access*/
  EthTrcv_30_Tja1100_LL_EnableConfigAccess(TrcvIdx, RetValPtr);
  /* Enable or disable loopback mode in basic control register */
  if(LoopbackMode == ETHTRCV_PHYLOOPBACK_NONE)
  {
    /* Disable link control */
    *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
        TrcvIdx,
        ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
        ETHTRCV_30_TJA1100_REG_EXTCTRL_LINK_CONTROL,
        EthTrcv_30_Tja1100_ClearBitsRegValPattern);

    /* Disable loopback operation in basic control register*/
    *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
        TrcvIdx,
        ETHTRCV_30_TJA1100_REG_OFFS_BMCR,
        ETHTRCV_30_TJA1100_REG_BMCR_LOOPBACK,
        EthTrcv_30_Tja1100_ClearBitsRegValPattern);
  }
  else
  {
    /* Enable loopback operation in Basic Control Register */
    *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
        TrcvIdx,
        ETHTRCV_30_TJA1100_REG_OFFS_BMCR,
        ETHTRCV_30_TJA1100_REG_BMCR_LOOPBACK,
        EthTrcv_30_Tja1100_SetBitsRegValPattern);
  }


  EthTrcv_30_Tja1100_LL_DisableConfigAccess(TrcvIdx, RetValPtr);

  /* Enable link control */
  *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_LINK_CONTROL,
      EthTrcv_30_Tja1100_SetBitsRegValPattern);
}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_PHY_LOOPBACK_MODE */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

#  if ( ETHTRCV_30_TJA1100_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_FinalizeSignalQualityMeasurement(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

}
#  endif /* ETHTRCV_30_TJA1100_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT */

#  if ( ETHTRCV_30_TJA1100_LL_PREPARE_CABLE_DIAG == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_PrepareCableDiag(
    uint8 TrcvIdx,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{

  /* Disable link control */
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_LINK_CONTROL,
      EthTrcv_30_Tja1100_ClearBitsRegValPattern);

  /* Enable the cable diagnostics test sequence */
  *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_CABLE_TEST_ENABLE,
      EthTrcv_30_Tja1100_SetBitsRegValPattern);
}
#  endif /* ETHTRCV_30_TJA1100_LL_PREPARE_CABLE_DIAG */

#  if ( ETHTRCV_30_TJA1100_LL_CHECK_CABLE_DIAG_RESULT == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_CheckCableDiagResult(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, AUTOMATIC) CableDiagResultPtr)
{
  uint16 regVal;
  Std_ReturnType retVal;

  /* Read cable diag status register */
  retVal = EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
      EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
      EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
      ETHTRCV_30_TJA1100_REG_OFFS_EXT_STAT,
      &regVal);

  if(retVal == E_OK)
  {
    uint16 cableDiagResult = (regVal & ETHTRCV_30_TJA1100_REG_EXT_STAT_CABLE_DIAG_RESULT_MASK);

    switch(cableDiagResult)
    {
    case ETHTRCV_30_TJA1100_REG_EXT_STAT_OK:
      *CableDiagResultPtr = ETHTRCV_CABLEDIAG_OK;
      break;

    case ETHTRCV_30_TJA1100_REG_EXT_STAT_CABLE_DIAG_RESULT_MASK:
      *CableDiagResultPtr = ETHTRCV_CABLEDIAG_ERROR;
      break;

    case ETHTRCV_30_TJA1100_REG_EXT_STAT_SHORT_DETECT:
      *CableDiagResultPtr = ETHTRCV_CABLEDIAG_SHORT;
      break;

    case ETHTRCV_30_TJA1100_REG_EXT_STAT_OPEN_DETECT:
      *CableDiagResultPtr = ETHTRCV_CABLEDIAG_OPEN;
      break;
    default: break;
    }
  }
  else
  {
    *CableDiagResultPtr = ETHTRCV_CABLEDIAG_ERROR;
  }
}
#  endif /* ETHTRCV_30_TJA1100_LL_CHECK_CABLE_DIAG_RESULT */

#  if ( ETHTRCV_30_TJA1100_LL_ADDITIONAL_STEPS_AFTER_CABLE_DIAG == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_AdditionalStepsAfterCableDiag(
    uint8 TrcvIdx,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  /* Enable link control to resume normal operation */
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_LINK_CONTROL,
      EthTrcv_30_Tja1100_SetBitsRegValPattern);
}
#  endif /* ETHTRCV_30_TJA1100_LL_CHECK_CABLE_DIAG_RESULT */

#  if ( ETHTRCV_30_TJA1100_LL_SET_PHY_TX_MODE == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_SetPhyTxMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetValPtr)
{
  uint16 regVal;

  /* Enable config access */
  *RetValPtr = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_CONFIG_EN,
      EthTrcv_30_Tja1100_SetBitsRegValPattern);

  switch(TxMode)
  {
    case ETHTRCV_PHYTXMODE_NORMAL:
      /* #30 Read the tx mode status register */
      *RetValPtr |= EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
          EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
          EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
          ETHTRCV_30_TJA1100_REG_OFFS_COM_STAT,
          &regVal);

      if(*RetValPtr == E_OK)
      {
        /* Check if transmission mode is not normal */
        if((regVal & ETHTRCV_30_TJA1100_REG_COM_STAT_TX_MODE_MASK) != ETHTRCV_30_TJA1100_REG_COM_STAT_TX_MODE_SEND_N)
        {
          /* Perform software reset in next main function */
          EthTrcv_30_Tja1100_LinkFailCounter[TrcvIdx] = EthTrcv_30_Tja1100_LinkFailCounterValueForReset[TrcvIdx];
        }
      }

      /* Resume master/slave setting */
      *RetValPtr = EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
          EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
          EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
          ETHTRCV_30_TJA1100_REG_OFFS_CFG1,
          &regVal);

      if(EthTrcv_30_Tja1100_ConnNeg[TrcvIdx] == ETHTRCV_CONN_NEG_MASTER)
      {
        regVal |= ETHTRCV_30_TJA1100_REG_CFG1_MASTER_SLAVE;
      }
      else if(EthTrcv_30_Tja1100_ConnNeg[TrcvIdx] == ETHTRCV_CONN_NEG_SLAVE)
      {
        regVal &= (uint16)(~(uint32)ETHTRCV_30_TJA1100_REG_CFG1_MASTER_SLAVE);
      }
      else
      {
        /* Not possible due to generator impl. */
      }

      *RetValPtr |= EthTrcv_30_Tja1100_WriteTrcvRegister[TrcvIdx](
          EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
          EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
          ETHTRCV_30_TJA1100_REG_OFFS_CFG1,
          regVal);

      break;

    case ETHTRCV_PHYTXMODE_TX_OFF:
      /* Disable Link Control */
      *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
          TrcvIdx,
          ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
          ETHTRCV_30_TJA1100_REG_EXTCTRL_LINK_CONTROL,
          EthTrcv_30_Tja1100_ClearBitsRegValPattern);
      break;

    case ETHTRCV_PHYTXMODE_SCRAMBLER_OFF:
      /* Set the transceiver to slave and enable link control */
      *RetValPtr |= EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
          EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
          EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
          ETHTRCV_30_TJA1100_REG_OFFS_CFG1,
          &regVal);

      if((regVal & ETHTRCV_30_TJA1100_REG_CFG1_MASTER_SLAVE) != 0)
      {
        regVal |= ETHTRCV_30_TJA1100_REG_CFG1_MASTER_SLAVE;
      }

      *RetValPtr |= EthTrcv_30_Tja1100_WriteTrcvRegister[TrcvIdx](
          EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
          EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
          ETHTRCV_30_TJA1100_REG_OFFS_CFG1,
          regVal);

      break;

    default:
      break;
  }
  /* Disable config access */
  *RetValPtr |= EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
      TrcvIdx,
      ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
      ETHTRCV_30_TJA1100_REG_EXTCTRL_CONFIG_EN,
      EthTrcv_30_Tja1100_ClearBitsRegValPattern);
}
#  endif /* ETHTRCV_30_TJA1100_LL_SET_PHY_TX_MODE */

#  if ( ETHTRCV_30_TJA1100_LL_MAIN_FUNCTION_LINK_HANDLING == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_MainFunctionLinkHandling(
    uint8 TrcvIdx)
{
  Std_ReturnType retVal = E_NOT_OK;

  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_INIT)
  {
    /* STATE 1: Link down, transceiver mode active */
    if(EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] == ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_1)
    {
      /* Startup required, decrement startup delay counter (> 2ms) */
      EthTrcv_30_Tja1100_LinkStartupDelayCounter[TrcvIdx]--;

      /* Check if startup delay has passed */
      if(EthTrcv_30_Tja1100_LinkStartupDelayCounter[TrcvIdx] == 0)
      {
        /* Proceed to state 2 */
        EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_2;
      }
    }
    /* STATE 2: Enable LINK_CONTROL */
    if(EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] == ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_2)
    {
      retVal = EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
          TrcvIdx,
          ETHTRCV_30_TJA1100_REG_OFFS_EXCTRL,
          ETHTRCV_30_TJA1100_REG_EXTCTRL_LINK_CONTROL,
          EthTrcv_30_Tja1100_SetBitsRegValPattern);

      if(retVal == E_OK)
      {
        /* Disable startup delay counter until next startup is required */
        EthTrcv_30_Tja1100_LinkStartupDelayCounter[TrcvIdx] = ETHTRCV_30_TJA1100_NO_LINK_STARTUP;

        /* An extended link state check is necessary */
        if(EthTrcv_30_Tja1100_ExtendedLinkStateCheck[TrcvIdx] == STD_ON)
        {
          /* Proceed to state 3 and perform an extended link state check */
          EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_3;
        }
        else
        {
          /* Proceed to state 5 and skip the link state check */
          EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_5;
        }
      }
      else
      {
        /* Repeat operation */
        EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_2;
      }
    }
    /* Decrement counters to realize the software timer */
    if((EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] == ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_3) ||
       (EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] == ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_4))
    {
      if(EthTrcv_30_Tja1100_LinkStateDelayCounter[TrcvIdx] > 0)
      {
        EthTrcv_30_Tja1100_LinkStateDelayCounter[TrcvIdx]--; /* Timeout: 100 ms */
      }
      if(EthTrcv_30_Tja1100_LinkStateTimeoutCounter[TrcvIdx] > 0)
      {
        EthTrcv_30_Tja1100_LinkStateTimeoutCounter[TrcvIdx]--; /* Timeout: 200 ms */
      }
    }
    /* STATE 3: Software timer enabled and < 100 ms */
    if(EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] == ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_3)
    {
      if(EthTrcv_30_Tja1100_LinkStateDelayCounter[TrcvIdx] == 0)
      {
        /* 100 ms have passed, perform link state checks in next state */
        EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_4;
      }
      else
      {
        EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_3;
      }
    }
    /* STATE 4: Software timer > 100 ms */
    if(EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] == ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_4)
    {
      uint16 regVal;

      /* Read link state status register */
      retVal = EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx](
          EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
          EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
          ETHTRCV_30_TJA1100_REG_OFFS_COM_STAT,
          &regVal);

      if(retVal == E_OK)
      {
        if((uint16)(regVal & ETHTRCV_30_TJA1100_REG_COM_STAT_LINK_STATE) ==  ETHTRCV_30_TJA1100_REG_COM_STAT_LINK_STATE)
        {
          /* The link is stable now and the get link state result can be retrieved */
          EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_5;
        }
        else if(EthTrcv_30_Tja1100_LinkStateTimeoutCounter[TrcvIdx] == 0)
        {
          /* The 200 ms timeous has occured --> perform software reset */
          EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_6;
        }
        else
        {
          /* Repeat operation */
          EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_4;
        }
      }
      else
      {
        /* Repeat operation */
        EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_4;
      }
    }

    /* STATE 6: Software timer > 200 ms or link fail counter has overflown */
    if(EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] == ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_6)
    {
     /* soft reset */
      retVal = EthTrcv_30_Tja1100_WriteTrcvRegister[TrcvIdx](
          EthTrcv_30_Tja1100_HwIndex[TrcvIdx],
          EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx],
          ETHTRCV_30_TJA1100_REG_OFFS_BMCR,
          ETHTRCV_30_TJA1100_REG_BMCR_RESET);

      if(retVal == E_OK)
      {
        /* Repeat link startup procedure */
        EthTrcv_30_Tja1100_LL_EnableLinkStartupDelay(TrcvIdx);
      }
      else
      {
        /* Repeat SW Reset */
        EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_6;
      }
    }
    /* Check the link fail counter if an overflow occurred and set the state to perform a SW Reset in this case */
    if(EthTrcv_30_Tja1100_LinkFailCounter[TrcvIdx] >= EthTrcv_30_Tja1100_LinkFailCounterValueForReset[TrcvIdx])
    {
      EthTrcv_30_Tja1100_LinkStartupState[TrcvIdx] = ETHTRCV_30_TJA1100_LINK_STARTUP_STATE_6;
    }
  }
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#  endif /* ETHTRCV_30_TJA1100_LL_MAIN_FUNCTION_LINK_HANDLING */

#  if ( ETHTRCV_30_TJA1100_LL_RESET_LINK_FAIL_COUNTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_ResetLinkFailCounter(
    uint8 TrcvIdx)
{
  EthTrcv_30_Tja1100_LinkFailCounter[TrcvIdx] = 0;
}
#  endif /* ETHTRCV_30_TJA1100_LL_RESET_LINK_FAIL_COUNTER */

#  if ( ETHTRCV_30_TJA1100_LL_INCREMENT_LINK_FAIL_COUNTER == STD_ON )
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_LL_IncrementLinkFailCounter(
    uint8 TrcvIdx)
{
  EthTrcv_30_Tja1100_LinkFailCounter[TrcvIdx]++;
}
#  endif /* ETHTRCV_30_TJA1100_LL_INCREMENT_LINK_FAIL_COUNTER */
# endif /* ETHTRCV_30_TJA1100_SOURCE, ETHTRCV_30_TJA1100_LL_SOURCE, ETHTRCV_30_TJA1100_LCFG_SOURCE*/
#endif /* ETHTRCV_30_TJA1100_LL_H */
/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Tja1100_LL.h
 *********************************************************************************************************************/
