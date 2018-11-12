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
/**        \file  EthTrcv_30_Ethmii.h
 *        \brief  Ethernet transceiver driver header file
 *
 *      \details  Module header providing access to AUTOSAR APIs of the Ethernet transceiver driver
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  David Roeder                  visdrr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2017-02-28  visdrr  -             Initial creation
 *            2017-03-02  visdrr  FEATC-944     FEAT-1824: Support a component-specific SafeBSW configuration switch
 *  01.01.00  2017-03-14  visdrr  FEATC-676     FEAT-2234: Ethernet Link Quality Monitoring
 *********************************************************************************************************************/
#if !defined (ETHTRCV_30_ETHMII_H)
# define ETHTRCV_30_ETHMII_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "EthTrcv_30_Ethmii_Types.h"
# include "EthTrcv_30_Ethmii_Cfg.h"
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857  */
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* supported version */
# define ETHTRCV_30_ETHMII_SW_MAJOR_VERSION                           1U
# define ETHTRCV_30_ETHMII_SW_MINOR_VERSION                           1U
# define ETHTRCV_30_ETHMII_SW_PATCH_VERSION                           0U

/* AUTOSAR 4.x Software Specification Version Information */
# define ETHTRCV_30_ETHMII_AR_RELEASE_MAJOR_VERSION                0x04U
# define ETHTRCV_30_ETHMII_AR_RELEASE_MINOR_VERSION                0x01U
# define ETHTRCV_30_ETHMII_AR_RELEASE_REVISION_VERSION             0x01U

/* Vector ID */
# define ETHTRCV_30_ETHMII_VENDOR_ID                                 30U

/* ETHTRCV ModuleId */
# define ETHTRCV_30_ETHMII_MODULE_ID                                 73U

/* ----- API service IDs ----- */
# define ETHTRCV_30_ETHMII_SID_INIT                                (0x01U) /*!< Service ID: EthTrcv_30_Ethmii_Init() */
# define ETHTRCV_30_ETHMII_SID_TRANSCEIVER_INIT                    (0x02U) /*!< Service ID: EthTrcv_30_Ethmii_TransceiverInit() */
# define ETHTRCV_30_ETHMII_SID_SET_TRANSCEIVER_MODE                (0x03U) /*!< Service ID: EthTrcv_30_Ethmii_SetTransceiverMode() */
# define ETHTRCV_30_ETHMII_SID_GET_TRANSCEIVER_MODE                (0x04U) /*!< Service ID: EthTrcv_30_Ethmii_GetTransceiverMode() */
# define ETHTRCV_30_ETHMII_SID_START_AUTO_NEG                      (0x05U) /*!< Service ID: EthTrcv_30_Ethmii_StartAutoNegotiation() */
# define ETHTRCV_30_ETHMII_SID_GET_LINK_STATE                      (0x06U) /*!< Service ID: EthTrcv_30_Ethmii_GetLinkState() */
# define ETHTRCV_30_ETHMII_SID_GET_BAUD_RATE                       (0x07U) /*!< Service ID: EthTrcv_30_Ethmii_GetBaudRate() */
# define ETHTRCV_30_ETHMII_SID_GET_DUPLEX_MODE                     (0x08U) /*!< Service ID: EthTrcv_30_Ethmii_GetDuplexMode() */
# define ETHTRCV_30_ETHMII_SID_GET_VERSION_INFO                    (0x09U) /*!< Service ID: EthTrcv_30_Ethmii_GetVersionInfo() */
# define ETHTRCV_30_ETHMII_SID_MAIN_FUNCTION                       (0x0CU) /*!< Service ID: EthTrcv_30_Ethmii_MainFunction() */
# define ETHTRCV_30_ETHMII_SID_SET_TRANSCEIVER_WAKEUP_MODE         (0x0DU) /*!< Service ID: EthTrcv_30_Ethmii_SetTransceiverWakeupMode() */
# define ETHTRCV_30_ETHMII_SID_GET_TRANSCEIVER_WAKEUP_MODE         (0x0EU) /*!< Service ID: EthTrcv_30_Ethmii_GetTransceiverWakeupMode() */
# define ETHTRCV_30_ETHMII_SID_CHECK_WAKEUP                        (0x0FU) /*!< Service ID: EthTrcv_30_Ethmii_CheckWakeup() */
# define ETHTRCV_30_ETHMII_SID_SET_PHY_TEST_MODE                   (0x10U) /*!< Service ID: EthTrcv_30_Ethmii_SetPhyTestMode() */
# define ETHTRCV_30_ETHMII_SID_SET_PHY_LOOPBACK_MODE               (0x11U) /*!< Service ID: EthTrcv_30_Ethmii_SetPhyLoopbackMode() */
# define ETHTRCV_30_ETHMII_SID_GET_PHY_SIGNAL_QUALITY              (0x12U) /*!< Service ID: EthTrcv_30_Ethmii_GetPhySignalQuality() */
# define ETHTRCV_30_ETHMII_SID_SET_PHY_TX_MODE                     (0x13U) /*!< Service ID: EthTrcv_30_Ethmii_SetPhyTxMode() */
# define ETHTRCV_30_ETHMII_SID_GET_CABLE_DIAGNOSTICS_RESULT        (0x14U) /*!< Service ID: EthTrcv_30_Ethmii_GetCableDiagnosticsResult() */
# define ETHTRCV_30_ETHMII_SID_GET_PHY_IDENTIFIER                  (0x15U) /*!< Service ID: EthTrcv_30_Ethmii_GetPhyIdentifier() */

/* ETHTRCV DET errors */
# define ETHTRCV_30_ETHMII_E_NO_ERROR                              (0x00U) /*!< No Error occurred */
# define ETHTRCV_30_ETHMII_E_INV_TRCV_IDX                          (0x01U) /*!< Error code: API service has been called with invalid transceiver index */
# define ETHTRCV_30_ETHMII_E_NOT_INITIALIZED                       (0x02U) /*!< Error code: API service used without module initialization */
# define ETHTRCV_30_ETHMII_E_INV_POINTER                           (0x03U) /*!< Error code: API service used with invalid pointer parameter */
# define ETHTRCV_30_ETHMII_E_INV_PARAM                             (0x04U) /*!< Error code: API service used with invalid value for parameter */
# define ETHTRCV_30_ETHMII_E_NOT_SUPPORTED                         (0x05U) /*!< Error code: API service not supported by the hardware */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define ETHTRCV_30_ETHMII_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  EthTrcv_30_Ethmii_InitMemory()
 **********************************************************************************************************************/
/*! \brief       Function for *_INIT_*-variable initialization
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_InitMemory(
    void);

/**********************************************************************************************************************
 * EthTrcv_30_Ethmii_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     This function initializes the module EthTrcv_30_Ethmii. It initializes all variables and sets the
 *               module state to initialized.
 *  \param[in]   ConfigPtr               Configuration structure for initializing the module
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \pre         EthTrcv_30_Ethmii_InitMemory has been called unless EthTrcv_30_Ethmii_ModuleInitialized is
 *               initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *********************************************************************************************************************/
FUNC(void, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_Init(
    P2CONST(EthTrcv_30_Ethmii_ConfigType, AUTOMATIC, AUTOMATIC) CfgPtr);


/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_TransceiverInit()
 ************** *******************************************************************************************************/
/*! \brief       Initializes an Ethernet transceiver (register configuration)
 *  \details     This function initializes the transceiver's registers to realize its functionality according to the
 *               configuration.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[in]   CfgIdx                Configuration index
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameters or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_Init() has been called .
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_TransceiverInit(
    uint8 TrcvIdx,
    uint8 CfgIdx);

# if ( ETHTRCV_30_ETHMII_ENABLE_SET_TRCV_MODE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_SetTransceiverMode()
 *********************************************************************************************************************/
/*! \brief       Sets the transceiver's mode
 *  \details     This function sets the transceiver to active or down.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[in]   TrcvMode              Transceiver mode to set:
 *                                     ETHTRCV_MODE_DOWN - shut down the Ethernet transceiver
 *                                     ETHTRCV_MODE_ACTIVE - activate the Ethernet transceiver
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameters or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_SetTransceiverMode(
    uint8 TrcvIdx,
    EthTrcv_ModeType TrcvMode);
# endif /* ETHTRCV_30_ETHMII_ENABLE_SET_TRCV_MODE */

# if ( ETHTRCV_30_ETHMII_ENABLE_GET_TRCV_MODE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_GetTransceiverMode()
 *********************************************************************************************************************/
/*! \brief       Gets the transceiver's mode
 *  \details     This function returns the transceiver's current mode.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver.
 *  \param[in]   TrcvModePtr           Pointer for retrieved transceiver mode:
 *                                     ETHTRCV_MODE_DOWN - transceiver is turned off
 *                                     ETHTRCV_MODE_ACTIVE - transceiver is active
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameters or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_GetTransceiverMode(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_ModeType, AUTOMATIC, AUTOMATIC) TrcvModePtr);
# endif /* ETHTRCV_30_ETHMII_ENABLE_GET_TRCV_MODE */

# if ( ETHTRCV_30_ETHMII_ENABLE_START_AUTO_NEG == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_StartAutoNegotiation()
 *********************************************************************************************************************/
/*! \brief       Starts automatic negotiation
 *  \details     This function starts the process to automatically negotiate the transceivers master-slave role,
 *               duplex mode and link speed, if available.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver.
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_StartAutoNegotiation(
    uint8 TrcvIdx);
# endif /* ETHTRCV_30_ETHMII_ENABLE_START_AUTO_NEG */

# if ( ETHTRCV_30_ETHMII_ENABLE_GET_LINK_STATE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_GetLinkState()
 *********************************************************************************************************************/
/*! \brief       Gets the transceiver's link state
 *  \details     This function returns the transceiver's current link state
 *  \param[in]   TrcvIdx               Zero based index of the transceiver.
 *  \param[out]  LinkStatePtr          Pointer for the retrieved link state value:
 *                                     ETHTRCV_LINK_STATE_DOWN - link is down
 *                                     ETHTRCV_LINK_STATE_ACTIVE - link is up
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_GetLinkState(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, AUTOMATIC) LinkStatePtr);
# endif /* ETHTRCV_30_ETHMII_ENABLE_GET_LINK_STATE */

# if ( ETHTRCV_30_ETHMII_ENABLE_GET_BAUD_RATE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_GetBaudRate()
 *********************************************************************************************************************/
/*! \brief       Gets the transceiver's baud rate
 *  \details     This function returns the transceiver's current baud rate.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver.
 *  \param[out]  BaudRatePtr           pointer for the retrieved baud rate value:
 *                                     ETHTRCV_BAUD_RATE_10MBIT - Link speed is 10 Mbit/s
 *                                     ETHTRCV_BAUD_RATE_100MBIT - Link speed is 100 Mbit/s
 *                                     ETHTRCV_BAUD_RATE_1000MBIT - Link speed is 1000 Mbit/s
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_GetBaudRate(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_BaudRateType, AUTOMATIC, AUTOMATIC) BaudRatePtr);
# endif /* ETHTRCV_30_ETHMII_ENABLE_GET_BAUD_RATE */

# if ( ETHTRCV_30_ETHMII_ENABLE_GET_DUPLEX_MODE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_GetDuplexMode()
 *********************************************************************************************************************/
/*! \brief       Gets the transceiver's duplex mode
 *  \details     This function returns the transceiver's current duplex mode.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[out]  DuplexModePtr         Pointer for the retrieved duplex mode value:
 *                                     ETHTRCV_DUPLEX_MODE_HALF - transceiver operates in half duplex mode
 *                                     ETHTRCV_DUPLEX_MODE_FULL - transceiver operates in full duplex mode
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_GetDuplexMode(
  uint8 TrcvIdx,
  P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, AUTOMATIC) DuplexModePtr);
# endif /* ETHTRCV_30_ETHMII_ENABLE_GET_DUPLEX_MODE */

/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_SetPhyTestMode()
 *********************************************************************************************************************/
/*! \brief       Sets the phy test mode
 *  \details     This function activates the given phy test mode
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *               TestMode              Test mode to be activated
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_SetPhyTestMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode);

/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_SetPhyLoopbackMode()
 *********************************************************************************************************************/
/*! \brief       Sets the phy loopback mode
 *  \details     This function activates the given phy loopback mode
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *               LoopbackMode          Loopback mode to be activated
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_SetPhyLoopbackMode(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode);

/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_GetPhySignalQuality()
 *********************************************************************************************************************/
/*! \brief       Gets the signal quality
 *  \details     This function obtains the current signal quality of the link of the indexed transceiver
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[out]  SignalQualityPtr      Pointer to the memory where the signal quality in percent shall be stored
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_GetPhySignalQuality(
    uint8 TrcvIdx,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) SignalQualityPtr);

/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_SetPhyTxMode()
 *********************************************************************************************************************/
/*! \brief       Activates a given Tx Mode
 *  \details     This function activates the given transmission mode
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[in]   TxMode                Transmission mode to be activated
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \pre         The transmission mode to be activated is supported by the hardware
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_SetPhyTxMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode);

/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_GetCableDiagnosticsResult()
 *********************************************************************************************************************/
/*! \brief       Retrieves cable diagnostics result
 *  \details     This function retrieves the cable diagnostics result of a given transceiver
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[out]  CableDiagResultPtr      Pointer to the memory where the signal quality in percent shall be stored
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_GetCableDiagnosticsResult(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, AUTOMATIC) CableDiagResultPtr);

/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_GetPhyIdentifier()
 *********************************************************************************************************************/
/*! \brief       Obtains PHY identifier
 *  \details     This function obtains the PHY identifier of the Ethernet Transceiver according to IEEE 802.3-2015 chapter
 *               22.2.4.3.1 PHY Identifier.
 *  \param[in]   TrcvIdx             Zero based index of the transceiver
 *  \param[out]  OrgUniqueIdPtr      Pointer to the memory where the Organizational Unique Identifier shall be stored
 *  \param[out]  ModelNrPtr          Pointer to the memory where the Manufacturer's Model Number shall be stored
 *  \param[out]  RevisionNrPtr       Pointer to the memory where the Revision Number shall be stored
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - Function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_GetPhyIdentifier(
    uint8 TrcvIdx,
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) OrgUniqueIdPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) ModelNrPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) RevisionNrPtr);


# if ( ETHTRCV_WAKEUP_NOT_SUPPORTED != ETHTRCV_30_ETHMII_WAKEUP_TYPE )
/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_SetTransceiverWakeupMode
 *********************************************************************************************************************/
/*! \brief       Enable/disable transceiver wakeup or clear wakeup reason
 *  \details     This function allows to enable or disable the transceiver's wakeup feature or to clear any occurred
 *               wakeup reason.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[in]   TrcvWakeupMode        Operation that shall be performed:
 *                                     ETHTRCV_WUM_DISABLE - disable the transceiver wakeup
 *                                     ETHTRCV_WUM_ENABLE - enable the transceiver wakeup
 *                                     ETHTRCV_WUM_CLEAR - clear wakeup reason
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \pre         EthTrcv_30_Ethmii_TransceiverInit() has been called for the transceiver with index TrcvIdx
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_SetTransceiverWakeupMode(
    uint8 TrcvIdx,
    EthTrcv_WakeupModeType TrcvWakeupMode);

/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_GetTransceiverWakeupMode
 *********************************************************************************************************************/
/*! \brief       Gets the current wakeup mode
 *  \details     This function allows to retrieve if the transceiver wakeup is enabled or disabled.
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \param[out]  TrcvWakeupMode        Wakeup mode the transceiver is currently set to:
 *                                     ETHTRCV_WUM_DISABLE - Transceiver wakeup disabled
 *                                     ETHTRCV_WUM_ENABLE - Transceiver wakeup enabled
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_GetTransceiverWakeupMode(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_WakeupModeType, AUTOMATIC, ETHTRCV_30_ETHMII_APPL_DATA) TrcvWakeupModePtr);

/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_CheckWakeup
 *********************************************************************************************************************/
/*! \brief       Performs a wakeup check.
 *  \details     This function performs a check of the transceiver's wakeup function..
 *  \param[in]   TrcvIdx               Zero based index of the transceiver
 *  \return      E_OK     - success
 *  \return      E_NOT_OK - function has been called with invalid parameter or at least one of the hardware operations
 *                          (read/write) has failed.
 *  \pre         Module is initialized.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_CheckWakeup(
          uint8  TrcvIdx);
# endif /* ETHTRCV_WAKEUP_NOT_SUPPORTED != ETHTRCV_30_ETHMII_WAKEUP_TYPE */

/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_MainFunction
 *********************************************************************************************************************/
/*! \brief       Handles the cyclic processes of the transceiver driver.
 *  \details     This function handles cyclyc processes of the Ethernet transceiver driver.
 *  \return      void
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_MainFunction(
    void );

# if ( ETHTRCV_30_ETHMII_VERSION_INFO_API == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Ethmii_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     EthTrcv_30_Ethmii() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  VersionInfoPtr        Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         none
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, ETHTRCV_30_ETHMII_CODE) EthTrcv_30_Ethmii_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETHTRCV_30_ETHMII_APPL_DATA) VersionInfoPtr);
# endif /* ETHTRCV_30_ETHMII_VERSION_INFO_API == STD_ON */

# define ETHTRCV_30_ETHMII_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#endif /* ETHTRCV_30_ETHMII_H */
/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ethmii.h
 *********************************************************************************************************************/
