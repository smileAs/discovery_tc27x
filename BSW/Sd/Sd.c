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
 *         File:  Sd.c
 *       Module:  SysService_AsrSd
 *    Generator:  SysService_AsrSd.jar (DaVinci Configurator Pro)
 *
 *  Description:  Implementation of Service Discovery (SD)
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

#define SD_SOURCE

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e438 -e550 */ /* Return values can be used to gain debug information */
/* PRQA S 0781 EOF */ /* MD_Sd_5.6_0781 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Sd.h"
#include "Sd_Priv.h"
#include "BswM_Sd.h"
#include "IpBase.h"
#if (SD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SD_CONFIGURATION_VARIANT)
# include "EcuM_Error.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of Sd header file */
#if (  (SD_SW_MAJOR_VERSION != (0x04u)) \
    || (SD_SW_MINOR_VERSION != (0x02u)) \
    || (SD_SW_PATCH_VERSION != (0x00u)) )
# error "Vendor specific version numbers of Sd.c and Sd.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if defined (STATIC)
#else
# define STATIC static
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#define SD_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC VAR(Sd_StateType, SD_VAR_ZERO_INIT) Sd_State = SD_STATE_UNINIT;

#define SD_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SD_START_SEC_VAR_ZERO_INIT_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SD_STOP_SEC_VAR_ZERO_INIT_16BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define SD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC VAR(Sd_ExtendedTimeType, SD_VAR_ZERO_INIT) Sd_TimeMsSinceStart = {0u, 0u};

#define SD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (SD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SD_CONFIGURATION_VARIANT)
# define SD_START_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
STATIC P2CONST(Sd_ConfigType, SD_VAR_INIT, SD_PBCFG) Sd_ConfigPtr = NULL_PTR;
# define SD_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#else
# define SD_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
STATIC CONSTP2CONST(Sd_ConfigType, SD_CONST, SD_CONST) Sd_ConfigPtr = &Sd_GlobalConfig;
# define SD_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SD_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  *  Sd_UpdateServerStateMachine
  ********************************************************************************************************************/
/*! \brief          This function updated the state of the server service state machine and sets a timer event for the
  *                 next main function cycle.
  *  \param[in]     ServerServicePtr        Server to set the value and timer event
  *  \param[in]     NewState                New state of the server service state machine
  *  \param[in]     ResetTimeToTriggerSend  Set TimeToTriggerSend to the invalid value
  *  \return        none
  ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SD_CODE) Sd_UpdateServerStateMachine(
  SD_P2CONST(Sd_ServerServiceType) ServerServicePtr,
  Sd_ServerStateMachineType NewState,
  boolean ResetTimeToTriggerSend);

/**********************************************************************************************************************
  *  Sd_UpdateEventHandlerStateMachine
  ********************************************************************************************************************/
/*! \brief          This function updated the state of the eventhandler state machine and sets a timer event for the
  *                 next main function cycle.
  *  \param[in]     EventHandlerPtr   Eventhandler to set the value and timer event
  *  \param[in]     NewState          New state of the eventhandler state machine
  *  \return        none
  ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SD_CODE) Sd_UpdateEventHandlerStateMachine(
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  Sd_EventHandlerStateMachineType NewState);

/**********************************************************************************************************************
  *  Sd_UpdateClientStateMachine
  ********************************************************************************************************************/
/*! \brief          This function updated the state of the client service state machine and sets a timer event for the
  *                 next main function cycle.
  *  \param[in]     ClientServicePtr        Client to set the value and timer event
  *  \param[in]     NewState                New state of the client service state machine
  *  \param[in]     ResetTimeToTriggerSend  Set TimeToTriggerSend to the invalid value
  *  \return        none
  ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SD_CODE) Sd_UpdateClientStateMachine(
  SD_P2CONST(Sd_ClientServiceType) ClientServicePtr,
  Sd_ClientStateMachineType NewState,
  boolean ResetTimeToTriggerSend);

/**********************************************************************************************************************
  *  Sd_UpdateConsumedEventGroupStateMachine
  ********************************************************************************************************************/
/*! \brief          This function updated the state of the consumed eventgroup state machine and sets a timer event
  *                 for the next main function cycle.
  *  \param[in]     ConsumedEventGroupPtr   Consumed eventgroup to set the value and timer event
  *  \param[in]     NewState                New state of the consumed eventgroup state machine
  *  \return        none
  ********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SD_CODE) Sd_UpdateConsumedEventGroupStateMachine(
  SD_P2CONST(Sd_ConsumedEventGroupType) ConsumedEventGroupPtr,
  Sd_ConsumedEventGroupStateMachineType NewState);

/**********************************************************************************************************************
 *  Sd_InitialRunInit
 *********************************************************************************************************************/
/*! \brief      This function is used to initialize the global variables of the Sd at startup if not done by
                startup code.
 *  \param[in]  InstancePtr  Instance which shall be initialized
 *  \return     none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_InitialRunInit(
  SD_P2CONST(Sd_InstanceType) InstancePtr);

/**********************************************************************************************************************
 *  Sd_ProcessHeader
 *********************************************************************************************************************/
/*! \brief          Header processing checks all header fields.
 *  \param[in]      PduInfoPtr    Contains the length (SduLength) of the received I-PDU and a pointer to a
                                  buffer (SduDataPtr) containing the I-PDU.
 *  \param[out]     SdHeaderPtr   Pointer where to store the header.
 *  \return         E_OK:       Header is valid
 *                  E_NOT_OK:   Invalid Header, this SD message is not valid.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ProcessHeader(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  SD_P2VAR(Sd_HeaderType) SdHeaderPtr);

/**********************************************************************************************************************
 *  Sd_IndexOptionArray
 *********************************************************************************************************************/
/*! \brief          This function reads all attached options and generates a index in order to ease the access
                    of individual options.
 *  \param[in]      PduInfoPtr        Contains the length (SduLength) of the received I-PDU and a pointer to a
 *                                    buffer (SduDataPtr) containing the I-PDU.
 *  \param[in]      StartIndexOption  Index of the first byte of the attached option
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_IndexOptionArray(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint16 StartIndexOption);

/**********************************************************************************************************************
 *  Sd_GetSdEndpointOption
 *********************************************************************************************************************/
/*! \brief          This function checks if a SD endpoint option was attached to the message and extracts it.
 *  \param[in]      RxSoConId             Socket connection ID to obtain the subnet.
 *  \param[in]      PduInfoPtr            Contains the length (SduLength) of the received I-PDU and a pointer to a
 *  \param[out]     SdEndpointAddressPtr  Pointer to a structure where the SD endpoint address shall be stored.
 *  \return         none
 *  \trace          SPEC-60026, SPEC-60066, SPEC-60036, SPEC-60022
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_GetSdEndpointOption(
  SoAd_SoConIdType RxSoConId,
  SD_P2CONST(PduInfoType) PduInfoPtr,
  SD_P2VAR(Sd_SockAddrContainerType) SdEndpointAddressPtr);

/**********************************************************************************************************************
 *  Sd_ReadHeader
 *********************************************************************************************************************/
/*! \brief          This function deserializes the Sd header into the appropriate struct.
 *  \param[in]      DataPtr       Pointer to the received data.
 *  \param[out]     SdHeaderPtr   Pointer where to store the header.
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_ReadHeader(
  SD_P2CONST(uint8) DataPtr,
  SD_P2VAR(Sd_HeaderType) SdHeaderPtr);

/**********************************************************************************************************************
 *  Sd_HandleRemoteReboot
 *********************************************************************************************************************/
/*! \brief          This function searches all client and server services which are affected by the reboot of the
 *                  remote service and handles the reboot.
 *  \param[in]      InstanceIdx   Index of the SdInstance which received the message.
 *  \param[in]      AddrPtr       Reference to the saved address.
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_HandleRemoteReboot(
  uint16 InstanceIdx,
  SD_P2CONST(Sd_AddressStorageType) AddrPtr);

/**********************************************************************************************************************
 *  Sd_ProcessEntryOption
 *********************************************************************************************************************/
/*! \brief          This function processes the attached Entry Option.
 *  \param[in]      InstanceIdx       Index of the SdInstance which received the message.
 *  \param[in]      PduInfoPtr        Contains the length (SduLength) of the received I-PDU and a pointer to a
 *                                    buffer (SduDataPtr) containing the I-PDU.
 *  \param[in]      IndexEntry        Index of the entry which shall be processed.
 *  \param[in]      SavedAddrPtr      Remote IP address of the sender.
 *  \param[in]      RebootDetected    Flag to indicate if the sender of the message has rebooted.
 *  \param[in]      MulticastMessage  Flag to indicate if the message was received by a multicast IP address.
 *  \return         none
 *  \trace          SPEC-60023
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_ProcessEntryOption(
  uint16 InstanceIdx,
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint16 IndexEntry,
  SD_P2VAR(Sd_SockAddrContainerType) SavedAddrPtr,
  boolean RebootDetected,
  boolean MulticastMessage);

/**********************************************************************************************************************
 *  Sd_ProcessClientEntryOption
 *********************************************************************************************************************/
/*! \brief          This function reads and processes the attached Client Entry Option.
 *  \param[in]      PduInfoPtr             Contains the length (SduLength) of the received I-PDU and a pointer to a
 *                                         buffer (SduDataPtr) containing the I-PDU.
 *  \param[in]      IndexEntry             Start index of the Entry-Option.
 *  \param[in]      EntryFormat            Defines if the Entry-Option is a Service-Type or EventGroup-Type.
 *  \param[in]      ServiceInstancePtr     Pointer to the SdServiceInstance.
 *  \param[in]      SavedAddrPtr           Remote IP address of the sender.
 *  \param[in]      RebootDetected         Flag to indicate if the sender of the message has rebooted.
 *  \param[in]      MulticastMessage       Flag to indicate if the message was received by a multicast IP address.
 *  \return         none
 *  \trace          CREQ-121011
 *  \trace          SPEC-2046424, SPEC-60048
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_ProcessClientEntryOption(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint16 IndexEntry,
  Sd_EntryFormatType EntryFormat,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr,
  SD_P2VAR(Sd_SockAddrContainerType) SavedAddrPtr,
  boolean RebootDetected,
  boolean MulticastMessage);

/**********************************************************************************************************************
 *  Sd_ProcessClientOption
 *********************************************************************************************************************/
/*! \brief          This function reads and processes the attached Client Option.
 *  \param[in]      PduInfoPtr               Contains the length (SduLength) of the received I-PDU and a pointer to a
 *                                           buffer (SduDataPtr) containing the I-PDU.
 *  \param[in]      IndexOfOption            Start index of the Option.
 *  \param[in]      NrOfOptions              Number of succeeding Options which are attached to the Entry-Option.
 *  \param[in]      EMalformedMsgId          DEM error id for malformed messages
 *  \param[in]      EventgroupPtr            Pointer to the SdConsumedEventGroup.
 *  \param[out]     EndpointAddrUdpPtr       Pointer to the attached UDP Endpoint Address.
 *  \param[out]     EndpointAddrTcpPtr       Pointer to the attached TCP Endpoint Address.
 *  \param[in/out]  ConfigOptionPtrArrayPtr  Pointer to the Configuration Option Pointer Array.
 *  \return         E_OK:       Option is valid.
 *                  E_NOT_OK:   Invalid option, this SD message is not valid.
 *  \trace          CREQ-121019
 *  \trace          SPEC-60075, SPEC-60008
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ProcessClientOption(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint8 IndexOfOption,
  uint8 NrOfOptions,
  Sd_Dem_EventIdType EMalformedMsgId,
  SD_P2CONST(Sd_ConsumedEventGroupType) EventgroupPtr,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrUdpPtr,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrTcpPtr,
  SD_P2VAR(Sd_ConfigOptionStringType) ConfigOptionPtrArrayPtr);

/**********************************************************************************************************************
 *  Sd_UpdateClientServiceSoCons
 *********************************************************************************************************************/
/*! \brief          This function updates all socket connections and routing groups for the consumed methods.
 *  \param[in]      ClientServicePtr          Pointer to the SdClientService.
 *  \param[in]      EstablishConfiguration    To differentiate if the configuration should be established or removed.
 *  \return         E_OK:       All socket connections and routing groups updated.
 *                  E_NOT_OK:   Unable to update all socket connections and routing groups.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_UpdateClientServiceSoCons(
  SD_P2CONST(Sd_ClientServiceType) ClientServicePtr,
  boolean EstablishConfiguration);

/**********************************************************************************************************************
 *  Sd_UpdateClientServiceEventGroupSoCons
 *********************************************************************************************************************/
/*! \brief          This function updates all socket connections and routing groups of the EventGroup.
 *  \param[in]      ConsumedEventGroupPtr     Pointer to the SdConsumedEventGroup.
 *  \param[in]      AcknowledgeReceived       Flag indicating if an acknowledge message was received.
 *  \return         E_OK:       All socket connections and routing groups updated.
 *                  E_NOT_OK:   Unable to update all socket connections and routing groups.
 *  \trace          SPEC-60077, SPEC-60032
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_UpdateClientServiceEventGroupSoCons(
  SD_P2CONST(Sd_ConsumedEventGroupType) ConsumedEventGroupPtr,
  boolean AcknowledgeReceived);

/**********************************************************************************************************************
 *  Sd_ProcessServerEntryOption
 *********************************************************************************************************************/
/*! \brief          This function reads and processes the attached Server Entry-Options.
 *  \param[in]      PduInfoPtr             Contains the length (SduLength) of the received I-PDU and a pointer to a
 *                                         buffer (SduDataPtr) containing the I-PDU.
 *  \param[in]      IndexEntry             Start index of the Entry-Option.
 *  \param[in]      EntryFormat            Defines if the Entry-Option is a Service-Type or EventGroup-Type
 *  \param[in]      ServiceInstancePtr     Pointer to the SdServiceInstance.
 *  \param[in]      SavedAddrPtr           Remote IP address of the sender.
 *  \param[in]      MulticastMessage       Flag to indicate if the message was received by a multicast IP address.
 *  \return         none
 *  \trace          CREQ-121011
 *  \trace          SPEC-60069, SPEC-60059
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_ProcessServerEntryOption(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint16 IndexEntry,
  Sd_EntryFormatType EntryFormat,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr,
  SD_P2VAR(Sd_SockAddrContainerType) SavedAddrPtr,
  boolean MulticastMessage);

/**********************************************************************************************************************
 *  Sd_ProcessServerOption
 *********************************************************************************************************************/
/*! \brief          This function processes the attached Server Option.
 *  \param[in]      PduInfoPtr               Contains the length (SduLength) of the received I-PDU and a pointer to a
 *                                           buffer (SduDataPtr) containing the I-PDU.
 *  \param[in]      IndexEntry               Start index of the Entry-Option.
 *  \param[in]      IndexOfOption            Start index of the Option.
 *  \param[in]      NrOfOptions              Number of successive attached Options.
 *  \param[in]      EventHandlerPtr          Pointer to the corresponding EventHandler.
 *  \param[out]     EndpointAddrUdpPtr       Pointer to the attached UDP Endpoint Address.
 *  \param[out]     EndpointAddrTcpPtr       Pointer to the attached TCP Endpoint Address.
 *  \param[in/out]  ConfigOptionPtrArrayPtr  Pointer to the Configuration Option Pointer Array.
 *  \return         E_OK:       Option is valid.
 *                  E_NOT_OK:   Invalid Option, this SD message is not valid.
 *  \trace          SPEC-60069, SPEC-60059
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ProcessServerOption(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint8 IndexOfOption,
  uint8 NrOfOptions,
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrUdpPtr,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrTcpPtr,
  SD_P2VAR(Sd_ConfigOptionStringType) ConfigOptionPtrArrayPtr);

/**********************************************************************************************************************
 *  Sd_UpdateServerServiceSoCons
 *********************************************************************************************************************/
/*! \brief          This function updates all socket connections and routing groups.
 *  \param[in]      EventPtr          Pointer to the corresponding event.
 *  \return         E_OK:       All socket connections and routing groups updated.
 *                  E_NOT_OK:   Unable to update all socket connections and routing groups.
 *  \trace          CREQ-121019
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_UpdateServerServiceSoCons(
  SD_P2CONST(Sd_RxEventType) EventPtr);

/**********************************************************************************************************************
 *  Sd_RunServerStateMachine()
 *********************************************************************************************************************/
/*! \brief      This function is called periodically by the MainFunction and processes the state of the Server Service
                Instance which is selected by the transfer parameter SdServiceInstance.
 *  \param[in]  ServiceInstancePtr  Pointer to the SdServiceInstance
 *  \return     none
 *  \trace      SPEC-60010
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_RunServerStateMachine(
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr);

/**********************************************************************************************************************
 *  Sd_RunEventHandlerStateMachine()
 *********************************************************************************************************************/
/*! \brief      This function processes all SdEventHandlers of the SdServiceInstance.
 *  \param[in]  ServiceInstancePtr  Pointer to the SdServiceInstance
 *  \return     none
 *  \trace      CREQ-121004
 *  \trace      SPEC-60046, SPEC-60034
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_RunEventHandlerStateMachine(
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr);

/**********************************************************************************************************************
 *  Sd_RunClientStateMachine()
 *********************************************************************************************************************/
/*! \brief      This function is called periodically by the MainFunction and processes the state of the Client Service
                Instance which is selected by the transfer parameter SdServiceInstance.
 *  \param[in]  ServiceInstancePtr  Pointer to the SdServiceInstance
 *  \return     none
 *  \trace      CREQ-121005, CREQ-121006
 *  \trace      SPEC-60020, SPEC-60032
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_RunClientStateMachine(
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr);

/**********************************************************************************************************************
 *  Sd_RunConsumedEventGroupStateMachine()
 *********************************************************************************************************************/
/*! \brief      This function processes all SdConsumedEventGroups of the SdServiceInstance.
 *  \param[in]  ServiceInstancePtr  Pointer to the SdServiceInstance
 *  \return     none
 *  \trace      CREQ-121006, CREQ-121019
 *  \trace      SPEC-60045, SPEC-2046448
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_RunConsumedEventGroupStateMachine(
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr);

/**********************************************************************************************************************
 *  Sd_AddClientToList
 *********************************************************************************************************************/
/*! \brief          This function adds a client to the list of subscribed clients.
 *  \param[in]      EventHandlerPtr   Pointer to the corresponding EventHandler.
 *  \param[in]      SavedAddrPtr      Remote IP address of the client.
 *  \return         Pointer to the attached client.
 *********************************************************************************************************************/
STATIC FUNC(SD_P2VAR(Sd_ClientListType), SD_CODE) Sd_AddClientToList(
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2VAR(Sd_SockAddrContainerType) SavedAddrPtr);

/**********************************************************************************************************************
 *  Sd_RemoveClientFromList
 *********************************************************************************************************************/
/*! \brief          This function removes a client from the list of subscribed clients.
 *  \param[in]      EventHandlerPtr   Pointer to the corresponding EventHandler.
 *  \param[in]      ClientPtr         Pointer to the client which should be removed.
 *  \return         none
 *  \trace          SPEC-60071
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_RemoveClientFromList(
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2VAR(Sd_ClientListType) ClientPtr);

/**********************************************************************************************************************
 *  Sd_FindClientInList
 *********************************************************************************************************************/
/*! \brief          This function searches a client in the client-list of the event handler.
 *  \param[in]      EventHandlerPtr   Pointer to the corresponding EventHandler.
 *  \param[in]      AddrPtr           Remote address of the client.
 *  \param[in]      TcpEndpointPtr    TCP endpoint address of the entry.
 *  \param[in]      UdpEndpointPtr    UDP endpoint address of the entry.
 *  \param[in]      RebootDetected    Indicate whether a reboot of the client was detected.
 *  \return         Pointer to the client.
                    NULL_PTR if the client was not part of the list.
 *********************************************************************************************************************/
STATIC FUNC(SD_P2VAR(Sd_ClientListType), SD_CODE) Sd_FindClientInList(
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2CONST(Sd_SockAddrContainerType) AddrPtr,
  SD_P2CONST(Sd_SockAddrContainerType) TcpEndpointPtr,
  SD_P2CONST(Sd_SockAddrContainerType) UdpEndpointPtr,
  boolean RebootDetected);

/**********************************************************************************************************************
 *  Sd_GetActivationCount
 *********************************************************************************************************************/
/*! \brief          This function returns the activation count for the requested SoConId.
 *  \param[in]      EventHandlerUnicastPtr  Pointer to the corresponding SdEventHandler activation reference.
 *  \param[in]      SoConId                 Requested SocketConnectionId.
 *  \return         Pointer to the NrOfActivations or NULL_PTR if SoConId not found.
 *********************************************************************************************************************/
STATIC FUNC(SD_P2VAR(uint8), SD_CODE) Sd_GetActivationCount(
  SD_P2CONST(Sd_EventHandlerUnicastType) EventHandlerUnicastPtr,
  SoAd_SoConIdType SoConId);

/**********************************************************************************************************************
 *  Sd_IncreaseActivationCount
 *********************************************************************************************************************/
/*! \brief          This function increases the activation count for the requested SoConId.
 *  \param[in]      EventHandlerUnicastPtr  Pointer to the corresponding SdEventHandler activation reference.
 *  \param[in]      SoConId                 Requested SocketConnectionId.
 *  \return         void
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_IncreaseActivationCount(
  SD_P2CONST(Sd_EventHandlerUnicastType) EventHandlerUnicastPtr,
  SoAd_SoConIdType SoConId);

/**********************************************************************************************************************
 *  Sd_ResetActivationCount
 *********************************************************************************************************************/
/*! \brief          This function resets the activation count for all SocketConnections of the EventHandler.
 *  \param[in]      EventHandlerUnicastPtr  Pointer to the corresponding SdEventHandler activation reference.
 *  \return         void
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_ResetActivationCount(
  SD_P2CONST(Sd_EventHandlerUnicastType) EventHandlerUnicastPtr);

/**********************************************************************************************************************
 *  Sd_AddEventToRingBuffer
 *********************************************************************************************************************/
/*! \brief          This function adds an received event to the ring buffer.
 *  \param[in]      EventListPtr        Pointer to the list where the event should be saved.
 *  \param[in]      EventHandlerPtr     Pointer to the corresponding SdEventHandler.
 *  \param[in]      ClientPtr           Pointer to the client which triggered the event.
 *  \param[in]      Event               The event to process.
 *  \return         Information if the event could be saved.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_AddEventToRingBuffer(
  SD_P2VAR(Sd_RxEventListType) EventListPtr,
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2VAR(Sd_ClientListType) ClientPtr,
  Sd_ServerEventgroupEventType Event);

/**********************************************************************************************************************
 *  Sd_ReadFirstEventOfRingBuffer
 *********************************************************************************************************************/
/*! \brief          This function reads the first event from the ring buffer. The event will NOT be removed.
 *  \param[in]      EventListPtr     Pointer to the list where the event should be read.
 *  \param[out]     EventPtrPtr      Pointer to the event pointer.
 *  \return         Information if an event could be read from the buffer.
 *********************************************************************************************************************/
STATIC FUNC(boolean, SD_CODE) Sd_ReadFirstEventOfRingBuffer(
  SD_P2CONST(Sd_RxEventListType) EventListPtr,
  SD_P2VAR(SD_P2VAR(Sd_RxEventType)) EventPtrPtr);

/**********************************************************************************************************************
 *  Sd_RemoveFirstEventFromRingBuffer
 *********************************************************************************************************************/
/*! \brief          This removes the first element of the ring buffer.
 *  \param[in]      InstancePtr     Pointer to the corresponding SdInstance where the event should be removed.
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_RemoveFirstEventFromRingBuffer(
  SD_P2CONST(Sd_InstanceType) InstancePtr);

/**********************************************************************************************************************
 *  Sd_AddTriggerTransmitToRingBuffer
 *********************************************************************************************************************/
/*! \brief          This function adds an received event to the ring buffer.
 *  \param[in]      RxEvent      Pointer to the event which caused the trigger transmit.
 *  \return         Information if the event could be saved.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_AddTriggerTransmitToRingBuffer(
  SD_P2CONST(Sd_RxEventType) RxEvent);

/**********************************************************************************************************************
 *  Sd_ReadFirstTriggerTransmitOfRingBuffer
 *********************************************************************************************************************/
/*! \brief          This function reads the first event from the ring buffer. The event will NOT be removed.
 *  \param[out]     TriggerTransmitPtrPtr    Pointer to the trigger transmit pointer.
 *  \return         Information if an event could be read from the buffer.
 *********************************************************************************************************************/
STATIC FUNC(boolean, SD_CODE) Sd_ReadFirstTriggerTransmitOfRingBuffer(
  SD_P2VAR(SD_P2VAR(Sd_TriggerTransmitType)) TriggerTransmitPtrPtr);

/**********************************************************************************************************************
 *  Sd_RemoveFirstTriggerTransmitFromRingBuffer
 *********************************************************************************************************************/
/*! \brief          This removes the first element of the ring buffer.
 *  \param[in]      none
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_RemoveFirstTriggerTransmitFromRingBuffer(void);

/**********************************************************************************************************************
 *  Sd_ProcessPendingMessages
 *********************************************************************************************************************/
/*! \brief          This function checks if there are messages which are ready to transmit (TimeToTriggerSend)
                    If there is a ready message, also all pending messages with the same destination address
                    will be transmitted.
 *  \param[in]      EntriesListPtr      List of messages to transmit.
 *  \param[in]      ForceTransmission   If set to TRUE, the TimeToSend is ignored in order to transmit all pending
 *                                      messages directly.
 *  \return         none
 *  \trace          CREQ-121016
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_ProcessPendingMessages(
  SD_P2VAR(Sd_SendEntriesListType) EntriesListPtr,
  boolean ForceTransmission);

/**********************************************************************************************************************
 *  Sd_SerializePendingMessages
 *********************************************************************************************************************/
/*! \brief          This function serializes all pending messages to a single message and triggers the transmission.
 *  \param[in]      EntriesListPtr  List of messages to transmit.
 *  \return         E_OK:      All pending entries fit into the payload
 *                  E_NOT_OK:  Not able to serialize all entries to the payload
 *  \trace          CREQ-121007
 *  \trace          SPEC-60023, SPEC-60057, SPEC-60040, SPEC-60016, SPEC-60043, SPEC-60072, SPEC-60051, SPEC-60039, SPEC-60065, SPEC-60049, SPEC-60017
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_SerializePendingMessages(
  SD_P2CONST(Sd_SendEntriesListType) EntriesListPtr);

/**********************************************************************************************************************
 *  Sd_FindUnusedSlotInSendEntriesList
 *********************************************************************************************************************/
/*! \brief          This function searches for an unused slot in the SendEntriesList.
 *  \param[in]      SendEntriesListPtr  Pointer to the list where the message should be added.
 *  \return         Index of the empty Slot.
 *********************************************************************************************************************/
STATIC FUNC(uint16, SD_CODE) Sd_FindUnusedSlotInSendEntriesList(
  SD_P2CONST(Sd_SendEntriesListType) SendEntriesListPtr);

/**********************************************************************************************************************
 *  Sd_AddFindEntryToList
 *********************************************************************************************************************/
/*! \brief          This function adds a Find-Message to the pointed list of send entries.
 *  \param[in/out]  SendEntriesListPtr  Pointer to the list where the Find-Message should be added.
 *  \param[in]      ServiceInstancePtr  Pointer the the SdServiceInstance.
 *  \return         none
 *  \trace          SPEC-2046291
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_AddFindEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr);

/**********************************************************************************************************************
 *  Sd_AddMulticastOfferEntryToList
 *********************************************************************************************************************/
/*! \brief          This function adds a Offer-Message via multicast to the pointed list of send entries.
 *  \param[in/out]  SendEntriesListPtr  Pointer to the list where the Offer-Message should be added.
 *  \param[in]      ServiceInstancePtr  Pointer the the SdServiceInstance.
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_AddMulticastOfferEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr,
  boolean StopOffer);

/**********************************************************************************************************************
 *  Sd_AddUnicastOfferEntryToList
 *********************************************************************************************************************/
/*! \brief          This function adds a Offer-Message via unicast to the pointed list of send entries.
 *  \param[in/out]  SendEntriesListPtr  Pointer to the list where the Offer-Message should be added.
 *  \param[in]      ServiceInstancePtr  Pointer the the SdServiceInstance.
 *  \param[in]      StopOffer           TRUE  = StopOffer Message
                                        FALSE = Offer Message
 *  \param[in]      AddrPtr             Destination address
 *  \param[in]      TransmissionOffset  Timing offset when the message shall be transmitted.
                                        (Random delay for responses to multicast messages)
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_AddUnicastOfferEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr,
  boolean StopOffer,
  SD_P2VAR(Sd_SockAddrContainerType) AddrPtr,
  uint32 TransmissionOffset);

/**********************************************************************************************************************
 *  Sd_AddSubscribeEntryToList
 *********************************************************************************************************************/
/*! \brief          This function adds a Subscribe-Message to the pointed list of send entries.
 *  \param[in/out]  SendEntriesListPtr      Pointer to the list where the Subscribe-Message should be added.
 *  \param[in]      ConsumedEventGroupPtr   Pointer to the consumed eventgroup.
 *  \param[in]      Subscribe               TRUE  = Subscribe Message
                                            FALSE = StopSubscribe Message
 *  \param[in]      TransmissionOffset      Timing offset when the message shall be transmitted.
                                            (Random delay for responses to multicast messages)
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_AddSubscribeEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ConsumedEventGroupType) ConsumedEventGroupPtr,
  boolean Subscribe,
  uint32 TransmissionOffset);

/**********************************************************************************************************************
 *  Sd_AddEventGroupAckEntryToList
 *********************************************************************************************************************/
/*! \brief          This function adds a Subscribe-Acknowledge Message to the pointed list of send entries.
 *  \param[in/out]  SendEntriesListPtr  Pointer to the list where the ACK-Message should be added.
 *  \param[in]      EventPtr            Pointer to the received event.
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_AddEventGroupAckEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_RxEventType) EventPtr);

/**********************************************************************************************************************
 *  Sd_AddEventGroupNackEntryToList
 *********************************************************************************************************************/
/*! \brief          This function adds a Subscribe Negative Acknowledge Message to the pointed list of send entries.
 *  \param[in/out]  SendEntriesListPtr  Pointer to the list where the NACK-Message should be added.
 *  \param[in]      ServiceInstancePtr  Pointer the the SdServiceInstance.
 *  \param[in]      ServiceId         ServiceId of the rejected Subscribe Message.
 *  \param[in]      InstanceId        InstanceId of the rejected Subscribe Message.
 *  \param[in]      MajorVersion      MajorVersion of the rejected Subscribe Message.
 *  \param[in]      ReservedField     ReservedField of the rejected Subscribe Message.
 *  \param[in]      EventHandlerId    EventHandlerId of the rejected Subscribe Message.
 *  \param[in]      AddrPtr           Destination address.
 *  \param[in]      AdditionalDelay   Additional delay for transmission of the message.
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_AddEventGroupNackEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  P2CONST(Sd_ServiceInstanceType, TYPEDEF, SD_CONST) ServiceInstancePtr,
  uint16 ServiceId,
  uint16 InstanceId,
  uint8 MajorVersion,
  uint16 ReservedField,
  uint16 EventHandlerId,
  SD_P2VAR(Sd_SockAddrContainerType) AddrPtr,
  uint32 AdditionalDelay);

/**********************************************************************************************************************
 *  Sd_EntryListContainsSubscribe
 *********************************************************************************************************************/
/*! \brief          This function checks if a SubscribeEventgroup-Message is still pending.
 *  \param[in/out]  SendEntriesListPtr      Pointer to the entries list of the instance.
 *  \param[in]      ConsumedEventGroupPtr   Pointer to the consumed eventgroup.
 *  \return         none
 *********************************************************************************************************************/
STATIC FUNC(boolean, SD_CODE) Sd_EntryListContainsSubscribe(
  SD_P2CONST(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ConsumedEventGroupType) ConsumedEventGroupPtr);

/**********************************************************************************************************************
 *  Sd_SetSoConMode
 *********************************************************************************************************************/
/*! \brief        This function saves the current mode of the socket connection.
 *  \param[in]    SoConId        Socket connection index specifying the socket connection with the mode change.
 *  \param[in]    Mode           New socket connection mode.
 *  \return       none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_SetSoConMode(
  SoAd_SoConIdType SoConId,
  SoAd_SoConModeType Mode);

/**********************************************************************************************************************
 *  Sd_GetSoConMode
 *********************************************************************************************************************/
/*! \brief        This function returns the current mode of the socket connection.
 *  \param[in]    SoConId        Socket connection index specifying the socket connection.
 *  \return       Mode           Mode of the socket connection.
 *********************************************************************************************************************/
STATIC FUNC(Sd_SoConModeType, SD_CODE) Sd_GetSoConMode(
  SoAd_SoConIdType SoConId);

/**********************************************************************************************************************
 *  Sd_GetSessionIdFlags
 *********************************************************************************************************************/
/*! \brief          This function searches for the destination address pointed by the SockAddrPtr and reads out
                    the actual SessionId as well as the Flags-Field.
 *  \param[in]      InstancePtr       SdInstance which tries to send the message.
 *  \param[in]      SockAddrPtr       Destination address.
 *  \param[out]     SessionIdPtrPtr   Reference to the corresponding SessionId.
 *  \param[out]     FlagsPtrPtr       Reference to the corresponding Flags-Field.
 *  \return         E_OK:      Address found and SessionId/Flags read.
 *                  E_NOT_OK:  Unable to find the address in the array of destination addresses.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_GetSessionIdFlags(
  SD_P2CONST(Sd_InstanceType) InstancePtr,
  SD_P2CONST(Sd_SockAddrContainerType) SockAddrPtr,
  SD_P2VAR(SD_P2VAR(uint16)) SessionIdPtrPtr,
  SD_P2VAR(SD_P2VAR(uint8)) FlagsPtrPtr);

/**********************************************************************************************************************
 *  Sd_SaveAddr
 *********************************************************************************************************************/
/*! \brief          This function searches for a unused slot and saves the address pointed by InAddrPtr.
 *  \param[in]      InstancePtr           SdInstance which handles this address.
 *  \param[in]      InAddrPtr             Address which shall be saved.
 *  \param[out]     OutAddrStoragePtrPtr  Reference to the saved address.
 *  \return         E_OK:      Address saved.
 *                  E_NOT_OK:  Unable to save the address.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_SaveAddr(
  SD_P2CONST(Sd_InstanceType) InstancePtr,
  SD_P2CONST(Sd_SockAddrContainerType) InAddrPtr,
  SD_P2VAR(SD_P2VAR(Sd_AddressStorageType)) OutAddrStoragePtrPtr);

/**********************************************************************************************************************
 *  Sd_SaveEndpoint
 *********************************************************************************************************************/
/*! \brief          This function searches for a unused slot and saves the address pointed by InAddrPtr.
 *  \param[in]      InstancePtr               SdInstance which handles this address.
 *  \param[in]      InAddrPtr                 Address which shall be saved.
 *  \param[in]      Type                      Specifies the type of the endpoint address.
 *  \param[out]     OutEndpointStoragePtrPtr  Reference to the saved endpoint.
 *  \return         E_OK:      Address saved.
 *                  E_NOT_OK:  Unable to save the address.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_SaveEndpoint(
  SD_P2CONST(Sd_InstanceType) InstancePtr,
  SD_P2CONST(Sd_SockAddrContainerType) InAddrPtr,
  Sd_EndpointType Type,
  SD_P2VAR(SD_P2VAR(Sd_EndpointStorageType)) OutEndpointStoragePtrPtr);

/**********************************************************************************************************************
 *  Sd_RemoveEndpoint
 *********************************************************************************************************************/
/*! \brief          This function removes the saved endpoint address.
 *  \param[in/out]  EndpointStoragePtr   Reference to the saved endpoint.
 *  \return         E_OK:      Address saved.
 *                  E_NOT_OK:  Unable to save the address.
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_RemoveEndpoint(
  SD_P2VAR(Sd_EndpointStorageType) EndpointStoragePtr);

/**********************************************************************************************************************
 *  Sd_WriteHeader
 *********************************************************************************************************************/
/*! \brief          This function writes the header information of the Sd message.
 *  \param[in]      SdHeaderPtr  Pointer to a header struct containing constant values.
 *  \param[in]      DataPtr      Pointer the the data where the header shall be serialized.
 *  \param[in]      SessionId    Session Id of the actual message.
 *  \param[in]      Flags        Flags field of the actual message
 *  \return         Length of the written header in bytes.
 *********************************************************************************************************************/
STATIC FUNC(uint8, SD_CODE) Sd_WriteHeader(
  SD_P2CONST(Sd_HeaderType) SdHeaderPtr,
  SD_P2VAR(uint8) DataPtr,
  uint16 SessionId,
  uint8 Flags);

/**********************************************************************************************************************
 *  Sd_SerializeRelatedOptions
 *********************************************************************************************************************/
/*! \brief          Serialize all options of the referenced entry to the payload. Try to deduplicate options.
 *  \param[in]      EntryPtr              Current entry
 *  \param[in]      StartOptionArrayIdx   Start index of options array
 *  \param[in/out]  PayloadOptionIdx      Index in the payload to serialize options to
 *  \param[in/out]  FreeOptionIndexPtr    First unused option index
 *  \param[out]     Index1stPtr           Index of the first option run
 *  \param[out]     Index2ndPtr           Index of the second option run
 *  \param[out]     Nr1stOptionsPtr       Number of elements in the first option run
 *  \param[out]     Nr2ndOptionsPtr       Number of elements in the second option run
 *  \return         TRUE    Buffer was too small to serialize related options
 *                  FALSE   All related options were serialized to the payload
 *********************************************************************************************************************/
STATIC FUNC(boolean, SD_CODE) Sd_SerializeRelatedOptions(
  SD_P2CONST(Sd_SendEntryType) EntryPtr,
  uint16 StartOptionArrayIdx,
  SD_P2VAR(uint16) PayloadOptionIdx,
  SD_P2VAR(uint8) FreeOptionIndexPtr,
  SD_P2VAR(uint8) Index1stPtr,
  SD_P2VAR(uint8) Index2ndPtr,
  SD_P2VAR(uint8) Nr1stOptionsPtr,
  SD_P2VAR(uint8) Nr2ndOptionsPtr);

/**********************************************************************************************************************
 *  Sd_GetRelavantOptions
 *********************************************************************************************************************/
/*! \brief          Analyze which options have to be attached to the entry
 *  \param[in]      EntryPtr                  Current entry
 *  \param[out]     SockAddrContainerUdpPtr   Reference to the relevant UDP address
 *  \param[out]     SockAddrContainerTcpPtr   Reference to the relevant TCP address
 *  \param[out]     ConfigOptionRequiredPtr   Indicates if this entry requires a config option
 *  \return         NONE
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_GetRelavantOptions(
  SD_P2CONST(Sd_SendEntryType) EntryPtr,
  SD_P2VAR(Sd_SockAddrContainerType) SockAddrContainerUdpPtr,
  SD_P2VAR(Sd_SockAddrContainerType) SockAddrContainerTcpPtr,
  SD_P2VAR(boolean) ConfigOptionRequiredPtr);

/**********************************************************************************************************************
 *  Sd_CheckForDuplicatedOption
 *********************************************************************************************************************/
/*! \brief          Read the serialized payload and check if the indexed option is already present
 *  \param[in]      StartOptionArrayIdx     Start index of options array
 *  \param[in]      OptionIdx               Index of the (in advance) serialized option
 *  \param[out]     PossibleOptionIndexPtr  Last possible option index for deduplication
 *  \return         NONE
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_CheckForDuplicatedOption(
  uint16 StartOptionArrayIdx,
  uint16 OptionIdx,
  SD_P2VAR(uint8) PossibleOptionIndexPtr);

/**********************************************************************************************************************
 *  Sd_DeduplicateOption
 *********************************************************************************************************************/
/*! \brief          Tries to deduplicate the option
 *  \param[in]      PossibleOptionIndex   Last possible option index for deduplication
 *  \param[in]      RemainingOption       Indicates if the current option is the last one which has to be processed
 *  \param[in/out]  FreeOptionIndexPtr    First unused option index
 *  \param[in/out]  Index1stPtr           Index of the first option run
 *  \param[in/out]  Index2ndPtr           Index of the second option run
 *  \param[in/out]  Nr1stOptionsPtr       Number of elements in the first option run
 *  \param[in/out]  Nr2ndOptionsPtr       Number of elements in the second option run
 *  \return         TRUE    Option was deduplicated
 *                  FALSE   Algorithm was not able to deduplicate option
 *  \trace          CREQ-121016
 *********************************************************************************************************************/
STATIC FUNC(boolean, SD_CODE) Sd_DeduplicateOption(
  uint8 PossibleOptionIndex,
  boolean RemainingOption,
  SD_P2VAR(uint8) FreeOptionIndexPtr,
  SD_P2VAR(uint8) Index1stPtr,
  SD_P2VAR(uint8) Index2ndPtr,
  SD_P2VAR(uint8) Nr1stOptionsPtr,
  SD_P2VAR(uint8) Nr2ndOptionsPtr);

/**********************************************************************************************************************
 *  Sd_SerializeEndpointOption
 *********************************************************************************************************************/
/*! \brief        This function adds a endpoint option to the referenced data array.
 *  \param[in]    LocalIpAddrPtr    Address which shall be copied to the endpoint option.
 *  \param[in]    OptionType        Which kind of option shall be added.
 *  \param[in]    L4Proto           Which L4-Protocol (UDP/TCP) has the option.
 *  \param[in]    DataPtr           Data array where the option shall be saved.
 *  \param[in]    Offset            Start offset for the option.
 *  \param[out]   BufferTooSmallPtr Boolean indicating if the function was able to copy the endpoint to the buffer
 *  \return       OptionLength      The length of the added option.
 *********************************************************************************************************************/
STATIC FUNC(uint16, SD_CODE) Sd_SerializeEndpointOption(
  SD_P2CONST(Sd_SockAddrContainerType) LocalIpAddrPtr,
  Sd_OptionType OptionType,
  Sd_L4ProtocolType L4Proto,
  SD_P2VAR(uint8) DataPtr,
  uint16 Offset,
  SD_P2VAR(boolean) BufferTooSmallPtr);

/**********************************************************************************************************************
 *  Sd_SerializeConfigurationOption
 *********************************************************************************************************************/
/*! \brief        This function adds a configuration option to the referenced data array.
 *  \param[in]    HostnamePtr       Pointer to the configured Hostname.
 *  \param[in]    SendEntryPtr      Pointer to the entry containing the configuration option.
 *  \param[in]    DataPtr           Data array where the option shall be saved.
 *  \param[in]    Offset            Start offset for the option.
 *  \param[out]   BufferTooSmallPtr Boolean indicating if the function was able to copy the endpoint to the buffer
 *  \return       OptionLength      The length of the added option.
 *********************************************************************************************************************/
STATIC FUNC(uint16, SD_CODE) Sd_SerializeConfigurationOption(
  SD_P2CONST(uint8) HostnamePtr,
  SD_P2CONST(Sd_SendEntryType) SendEntryPtr,
  SD_P2VAR(uint8) DataPtr,
  uint16 Offset,
  SD_P2VAR(boolean) BufferTooSmallPtr);

/**********************************************************************************************************************
 *  Sd_ReadEndpointOption
 *********************************************************************************************************************/
/*! \brief        This function reads the received endpoint option.
 *  \param[in]    FamilyType        Type of the option.
 *  \param[in]    DataPtr           Data array of the option.
 *  \param[in]    DataIndex         Index of the option.
 *  \param[out]   EndpointAddrPtr   Reference where the endpoint address shall be stored.
 *  \return       E_OK:             Endpoint is valid.
 *                E_NOT_OK:         Invalid Endpoint.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ReadEndpointOption(
  Sd_FamilyType FamilyType,
  SD_P2CONST(uint8) DataPtr,
  uint16 DataIndex,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrPtr);

/**********************************************************************************************************************
  *  Sd_CheckConfigOption
  *********************************************************************************************************************/
/*! \brief           This function checks the received configuration option.
  *  \param[in]      DataPtr                  Data array of the option.
 *   \param[in/out]  ConfigOptionPtrArrayPtr  Pointer to the Configuration Option Pointer Array.
  *  \return         E_OK:                    Configuration option is valid.
  *                  E_NOT_OK:                Invalid configuration option.
  *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_CheckConfigOption(
  SD_P2CONST(uint8) DataPtr,
  SD_P2VAR(Sd_ConfigOptionStringType) ConfigOptionPtrArrayPtr);

/**********************************************************************************************************************
 *  Sd_CopySockAddr
 *********************************************************************************************************************/
/*! \brief         Copy socket addr (incl. family, port, IP-addr) from Src to Tgt.
 *  \param[inout]  TgtSockPtr           Target socket address.
 *  \param[in]     SrcSockPtr           Source socket address.
 *  \return        none
 *********************************************************************************************************************/
STATIC FUNC(void, SD_CODE) Sd_CopySockAddr(
  SD_P2VAR(SoAd_SockAddrType) TgtSockPtr,
  SD_P2CONST(SoAd_SockAddrType) SrcSockPtr);

/**********************************************************************************************************************
 *  Sd_CompareSockAddrIp
 *********************************************************************************************************************/
/*! \brief         Check if IP addresses of the sockets are equal.
 *  \param[in]     SockAPtr             Target socket address.
 *  \param[in]     SockBPtr             Source socket address.
 *  \param[in]     AddrState            State of the source socket address.
 *  \return        SD_MATCH_FALSE       IP addresses are not identical.
 *                 SD_MATCH_TRUE        IP addresses are identical
 *********************************************************************************************************************/
STATIC FUNC(Sd_MatchType, SD_CODE) Sd_CompareSockAddrIp(
  SD_P2CONST(SoAd_SockAddrType) SockAPtr,
  SD_P2CONST(SoAd_SockAddrType) SockBPtr,
  uint8 AddrState);

/**********************************************************************************************************************
 *  Sd_CompareSockAddrPort
 *********************************************************************************************************************/
/*! \brief         Check if the ports of the sockets are equal.
 *  \param[in]     SockAPtr             Target socket address.
 *  \param[in]     SockBPtr             Source socket address.
 *  \param[in]     AddrState            State of the source socket address.
 *  \return        SD_MATCH_FALSE       Ports are not identical.
 *                 SD_MATCH_TRUE        Ports are identical
 *********************************************************************************************************************/
STATIC FUNC(Sd_MatchType, SD_CODE) Sd_CompareSockAddrPort(
  SD_P2CONST(SoAd_SockAddrType) SockAPtr,
  SD_P2CONST(SoAd_SockAddrType) SockBPtr,
  uint8 AddrState);

/**********************************************************************************************************************
 *  Sd_SockAddrIsEqual
 *********************************************************************************************************************/
/*! \brief         Check if IP addresses and ports of the sockets are equal.
 *  \param[in]     SockAPtr             Target socket address.
 *  \param[in]     SockBPtr             Source socket address.
 *  \return        TRUE   IP addresses and ports are equal.
 *                 FALSE  IP addresses and/or ports are not equal.
 *********************************************************************************************************************/
STATIC FUNC(boolean, SD_CODE) Sd_SockAddrIsEqual(
  SD_P2CONST(SoAd_SockAddrType) SockAPtr,
  SD_P2CONST(SoAd_SockAddrType) SockBPtr);

/**********************************************************************************************************************
 *  Sd_SockAddrWithinSubnet
 *********************************************************************************************************************/
/*! \brief         Check if both IP addresses are within the same subnet
 *  \param[in]     SockAPtr             Socket address A
 *  \param[in]     SockBPtr             Socket address B
 *  \param[in]     NetmaskCidr          Netmask in CIDR notation
 *  \return        TRUE   IP addresses are within the same subnet.
 *                 FALSE  IP addresses are not within the same subnet.
 *********************************************************************************************************************/
STATIC FUNC(boolean, SD_CODE) Sd_SockAddrWithinSubnet(
  SD_P2CONST(SoAd_SockAddrType) SockAPtr,
  SD_P2CONST(SoAd_SockAddrType) SockBPtr,
  uint8 NetmaskCidr);

/**********************************************************************************************************************
 *  Sd_FindBestMatchLocalRemoteSoCon
 *********************************************************************************************************************/
/*! \brief         Search for the socket connection with the best local and remote address match
 *  \param[in]     MulticastSoConPtr      Structure containing available multicast socket connections.
 *  \param[in]     NrMulticastSoCons      Number of available socket connections.
 *  \param[in]     ClientConfigPtr        Client configuration containing the IP addresses which shall be compared.
 *  \param[out]    ElementIdxPtr          Index of the best matching socket connection.
 *  \param[out]    LocalIpAddrExactMatch  Indicating if the IP address match was exact.
 *  \param[out]    LocalPortExactMatch    Indicating if the port match was exact.
 *  \param[out]    RemoteAddrExactMatch   Indicating if the match was exact.
 *  \return        E_OK       Matching/suitable socket connection found.
 *                 E_NOT_OK   No suitable socket connection found.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_FindBestMatchLocalRemoteSoCon(
  SD_P2CONST(SoAd_SoConIdType) MulticastSoConPtr,
  uint16 NrMulticastSoCons,
  SD_P2CONST(Sd_DynamicClientServiceType) ClientConfigPtr,
  SD_P2VAR(uint16) ElementIdxPtr,
  SD_P2VAR(boolean) LocalIpAddrExactMatch,
  SD_P2VAR(boolean) LocalPortExactMatch,
  SD_P2VAR(boolean) RemoteAddrExactMatch);

/**********************************************************************************************************************
 *  Sd_LocalIpAlreadyConfigured
 *********************************************************************************************************************/
/*! \brief         Check if the requested multicast IP address is already configured at another socket
 *  \param[in]     MulticastAddress   Requested multicast IP address
 *  \return        TRUE     Matching/suitable socket connection found.
 *                 FALSE    No suitable socket connection found.
 *********************************************************************************************************************/
STATIC FUNC(boolean, SD_CODE) Sd_LocalIpAlreadyConfigured(
  SD_P2CONST(SoAd_SockAddrType) MulticastAddress);

/**********************************************************************************************************************
 *  Sd_RequestIpAddrAssignment
 *********************************************************************************************************************/
/*! \brief         Search for the socket connection with the best local and remote address match
 *  \param[in]     SoConId            SocketConnection which shall be configured.
 *  \param[in]     MulticastAddrPtr   Multicast address which shall be configured as local address.
 *  \param[in]     PerformRequest     Indicating if the address shall be configured or the request counter incremented.
 *  \return        E_OK       Request successfully processed.
 *                 E_NOT_OK   Not able to configure the local address.
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_RequestIpAddrAssignment(
  SoAd_SoConIdType SoConId,
  SD_P2VAR(Sd_SockAddrContainerType) MulticastAddrPtr,
  boolean PerformRequest);

/**********************************************************************************************************************
 *  Sd_ReleaseIpAddrAssignment
 *********************************************************************************************************************/
/*! \brief         This API releases the local IP address, if it is not required by another client.
 *  \param[in]     SoConId    SocketConnection which is configured with the local address
 *  \return        E_OK       Valid SoConId
 *                 E_NOT_OK   SoConId was not known
 *********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ReleaseIpAddrAssignment(
  SoAd_SoConIdType SoConId);

/**********************************************************************************************************************
 *  Sd_GetRandomNrInRange
 *********************************************************************************************************************/
/*! \brief        This function return a random value in the range: MinValue <= Random <= MaxValue
 *  \param[in]    MinValue    Minimal allowed value.
 *  \param[in]    MaxValue    Maximal allowed value.
 *  \return       Random number in the range: MinValue <= Random <= MaxValue
 *  \trace        SPEC-60052
 *********************************************************************************************************************/
STATIC FUNC(uint32, SD_CODE) Sd_GetRandomNrInRange(
  uint32 MinValue,
  uint32 MaxValue);

/**********************************************************************************************************************
 *  Sd_GetRandomNrInRangeForResponse
 *********************************************************************************************************************/
/*! \brief        This function return a random value in the range: MinValue <= Random <= MaxValue
 *  \param[in]    MinValue            Minimal allowed value.
 *  \param[in]    MaxValue            Maximal allowed value.
 *  \param[in]    InterruptContext    Specifies if the function is called from context of message reception or context
 *                                    of MainFunction.
 *  \return       Random number in the range: MinValue <= Random <= MaxValue
 *  \trace        SPEC-60052
 *********************************************************************************************************************/
STATIC FUNC(uint32, SD_CODE) Sd_GetRandomNrInRangeForResponse(
  uint32 MinValue,
  uint32 MaxValue,
  boolean InterruptContext);

/**********************************************************************************************************************
 *  Sd_CheckIfTimerExceeded
 *********************************************************************************************************************/
/*! \brief        This function checks if the timer is already exceeded
 *  \param[in]    Timer            Timer to be checked.
 *  \param[in]    EqualIsExceeded  If set to TRUE, the timer is also indicated as exceeded if it is equal to the
 *                                   current time.
 *  \return       TRUE   Timer is exceeded
 *                FALSE  Timer is not exceeded
 *********************************************************************************************************************/
STATIC FUNC(boolean, SD_CODE) Sd_CheckIfTimerExceeded(
  Sd_ExtendedTimeType Timer,
  boolean EqualIsExceeded);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Sd_RxIndication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
/* PRQA S 0715 MSR_110715 */ /* MD_MSR_1.1_0715 */
FUNC(void, SD_CODE) Sd_RxIndication(
  PduIdType RxPduId,
  P2CONST(PduInfoType, AUTOMATIC, SD_APPL_DATA) PduInfoPtr)
{
#if (STD_ON == SD_DEV_ERROR_DETECT)
  boolean InvalidId = TRUE;
#endif
  uint16 IndexEntry, StartIndexOption = 0;
  uint32 LengthEntriesArray, LengthOptionsArray = 0;
  Sd_HeaderType SdHeader;
  boolean RebootDetected = FALSE, MulticastMessage = TRUE;
  Std_ReturnType RetVal;
  SoAd_SoConIdType RxSoConId = 0;
  Sd_SockAddrContainerType RemoteAddr;
  SD_P2VAR(Sd_AddressStorageType) AddressPtr;
  uint16 InstanceIdx;
  SD_P2CONST(Sd_InstanceType) TmpInstancePtr;

  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnVoid(!(SD_STATE_UNINIT == Sd_State), SD_API_ID_RX_INDICATION, SD_E_NOT_INITIALIZED);
  Sd_CheckDetErrorReturnVoid(!(NULL_PTR == PduInfoPtr), SD_API_ID_RX_INDICATION, SD_E_PARAM_POINTER);

  /* Find the corresponding Instance */
  InstanceIdx = Sd_ConfigPtr->InstanceListSize;
  while(0 < InstanceIdx)
  {
    InstanceIdx--;

    RetVal = E_NOT_OK;
    TmpInstancePtr = Sd_GetInstancePtrByIdx(InstanceIdx);

    /* Check if the message was received by the multicast or the unicast RxPdu */
    if(TmpInstancePtr->UnicastRxPduId == RxPduId)
    {
#if (STD_ON == SD_DEV_ERROR_DETECT)
      InvalidId = FALSE;
#endif

      /* Message was received by the unicast PDU */
      MulticastMessage = FALSE;

      RxSoConId = TmpInstancePtr->UnicastRxSoConId;
      RetVal = E_OK;
    }
    else if(TmpInstancePtr->MulticastRxPduId == RxPduId)
    {
#if (STD_ON == SD_DEV_ERROR_DETECT)
      InvalidId = FALSE;
#endif

      /* Message was received by the multicast PDU */
      MulticastMessage = TRUE;

      RxSoConId = TmpInstancePtr->MulticastRxSoConId;
      RetVal = E_OK;
    }
    else
    {
      /* The message was received by another SdInstance */
    }

    if(E_OK == RetVal)
    {
      /* The correct SdInstance was found */
      /* Drop all messages that do not include a complete SD header as well as the length field for entries and options */
      if(PduInfoPtr->SduLength >= (SD_HEADER_LENGTH_SD + SD_SIZE_OF_ENTRY_ARRAY_LENGTH_FIELD + SD_SIZE_OF_OPTION_ARRAY_LENGTH_FIELD))
      {
        /* Analyze the SD header */
        RetVal = Sd_ProcessHeader(PduInfoPtr, &SdHeader);

        if(E_OK != RetVal)
        {
          /* Stop processing of the message because of an invalid header. \trace CREQ-121019 */
          Sd_DemMalformedMsg(TmpInstancePtr->EMalformedMsgId); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }
        else if(0u == (SdHeader.Flags & SD_FLAGS_UNICAST_MASK))
        {
          /* Unicast flag not set. Ignore message. */
        }
        else
        {
          /* Process the received SD payload data */
          IndexEntry = SD_HEADER_LENGTH_SD;
          LengthEntriesArray = ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry]) << 24) |
            ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+1]) << 16) |
            ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+2]) << 8) |
            ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+3]));
          IndexEntry += SD_SIZE_OF_ENTRY_ARRAY_LENGTH_FIELD;

          /* Check if the entries array fits into the payload */
          if(PduInfoPtr->SduLength >=
            (SD_HEADER_LENGTH_SD + SD_SIZE_OF_ENTRY_ARRAY_LENGTH_FIELD + LengthEntriesArray +SD_SIZE_OF_OPTION_ARRAY_LENGTH_FIELD))
          {
            LengthOptionsArray = ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+LengthEntriesArray]) << 24) |
              ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+LengthEntriesArray+1]) << 16) |
              ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+LengthEntriesArray+2]) << 8) |
              ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+LengthEntriesArray+3]));
            StartIndexOption = (uint16)(SD_HEADER_LENGTH_SD + SD_SIZE_OF_ENTRY_ARRAY_LENGTH_FIELD + LengthEntriesArray);
          }
          else
          {
            /* The entries array exceeds the payload. \trace CREQ-121019 */
            Sd_DemMalformedMsg(TmpInstancePtr->EMalformedMsgId); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            RetVal = E_NOT_OK;
          }

          /* Check if the payload can contain all mentioned entry and option arrays */
          if((E_OK == RetVal) &&
            (PduInfoPtr->SduLength >= (SD_HEADER_LENGTH_SD + SD_SIZE_OF_ENTRY_ARRAY_LENGTH_FIELD + LengthEntriesArray +
            SD_SIZE_OF_OPTION_ARRAY_LENGTH_FIELD + LengthOptionsArray)))
          {
            /* Generate an index of all attached options to be able to address them directly */
            Sd_IndexOptionArray(PduInfoPtr, StartIndexOption);

            /* Check if a SD endpoint option was attached and save it */
            Sd_GetSdEndpointOption(TmpInstancePtr->UnicastRxSoConId, PduInfoPtr, &RemoteAddr);

            if(SOAD_AF_INVALID == RemoteAddr.family)
            {
              /* Use the remote address of the sender */
              RetVal |= SoAd_GetRcvRemoteAddr(RxSoConId, (SD_P2VAR(SoAd_SockAddrType))(&RemoteAddr)); /* PRQA S 0310 */ /* MD_Sd_11.4_0310 */
            }

            if(E_OK == RetVal)
            {
              /* Save the remote address */
              RetVal = Sd_SaveAddr(Sd_GetInstancePtrByIdx(InstanceIdx), &RemoteAddr, &AddressPtr);

              /* Check if the device has rebooted */
              if((TRUE == MulticastMessage) && (E_OK == RetVal))
              {
                /* \trace CREQ-121045 */
                if(((AddressPtr->RxMulticastSessionId > SdHeader.SessionID) && (0u != (SdHeader.Flags & SD_FLAGS_REBOOT_MASK))) ||
                ((0u == (AddressPtr->RxMulticastFlags & SD_FLAGS_REBOOT_MASK)) && (0u != (SdHeader.Flags & SD_FLAGS_REBOOT_MASK))))
                {
                  /* The remote device has rebooted */
                  RebootDetected = TRUE;
                  Sd_HandleRemoteReboot(InstanceIdx, AddressPtr);

                  /* Reset the unicast Session ID in order to detect the reboot only once */
                  AddressPtr->RxUnicastSessionId = 0;
                }

                /* Update the values */
                AddressPtr->RxMulticastSessionId = SdHeader.SessionID;
                AddressPtr->RxMulticastFlags = SdHeader.Flags;
              }
              else if((FALSE == MulticastMessage) && (E_OK == RetVal))
              {
                /* \trace CREQ-121045 */
                if(((AddressPtr->RxUnicastSessionId > SdHeader.SessionID) && (0u != (SdHeader.Flags & SD_FLAGS_REBOOT_MASK))) ||
                ((0u == (AddressPtr->RxUnicastFlags & SD_FLAGS_REBOOT_MASK)) && (0u != (SdHeader.Flags & SD_FLAGS_REBOOT_MASK))))
                {
                  /* The remote device has rebooted */
                  Sd_HandleRemoteReboot(InstanceIdx, AddressPtr);
                  RebootDetected = TRUE;

                  /* Reset the multicast Session ID in order to detect the reboot only once */
                  AddressPtr->RxMulticastSessionId = 0;
                }

                /* Update the values */
                AddressPtr->RxUnicastSessionId = SdHeader.SessionID;
                AddressPtr->RxUnicastFlags = SdHeader.Flags;
              }
              else
              {
                /* Not able to save the additional address */
                /* The amount of manageable destination addresses is configured in Sd/SdConfig/SdInstance/SdMaxNrDestAddr */
                RetVal = E_NOT_OK;
                /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
                Sd_CallDetReportError(SD_API_ID_INTERNAL_FUNCTION, SD_E_LIST_FULL);
              }

              if(E_OK == RetVal)
              {
                /* Iterate through all entry arrays */
                while((IndexEntry + SD_SIZE_OF_ENTRY) <= (SD_HEADER_LENGTH_SD + SD_SIZE_OF_ENTRY_ARRAY_LENGTH_FIELD + LengthEntriesArray))
                {
                  /* Process the entry array and all associated option arrays */
                  Sd_ProcessEntryOption(InstanceIdx, PduInfoPtr, IndexEntry, &AddressPtr->Addr, RebootDetected, MulticastMessage);

                  /* The length of all entry arrays (type 1 and type 2) is 16 bytes */
                  IndexEntry += SD_SIZE_OF_ENTRY;
                }
              }
            }
          }
          else
          {
            /* \trace CREQ-121019 */
            Sd_DemMalformedMsg(TmpInstancePtr->EMalformedMsgId); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          }
        }
      }
      else
      {
        /* \trace CREQ-121019 */
        Sd_DemMalformedMsg(TmpInstancePtr->EMalformedMsgId); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }

      /* Found the corresponding SdInstance */
      break;
    }
  }

#if (STD_ON == SD_DEV_ERROR_DETECT)
  /* Raise error if RxPduId has an invalid value */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnVoid(!(TRUE == InvalidId), SD_API_ID_RX_INDICATION, SD_E_INV_ID);
#endif
} /* PRQA S 2006, 6010, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
/* PRQA L:MSR_110715 */

/**********************************************************************************************************************
 *  Sd_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, SD_CODE) Sd_InitMemory(void)
{
  Sd_State = SD_STATE_UNINIT;
  Sd_ResetTimerToZero(Sd_TimeMsSinceStart); /* PRQA S 3109 */ /* MD_MSR_14.3 */

#if (SD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SD_CONFIGURATION_VARIANT)
  Sd_ConfigPtr = NULL_PTR;
#endif
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  Sd_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, SD_CODE) Sd_Init(
  SD_P2CONSTCFGROOT(Sd_ConfigType) ConfigPtr)
{
  uint16 InstanceIdx, ServiceInstanceIdx, ClientIdx, EventGroupIdx, TmpIdx;
  uint16 RxTxEntryIdxGlobal = 0, MaxSizePendingMessages = 0;
  uint16 SoConModeMapIdx;
  SD_P2CONST(Sd_InstanceType) TmpInstancePtr;
  SD_P2CONST(Sd_ServiceInstanceType) TmpServiceInstancePtr;
  SD_P2CONST(Sd_ClientServiceType) TmpClientServicePtr;
  SD_P2CONST(Sd_ConsumedEventGroupType) TmpEventGroupPtr;
  SD_P2CONST(Sd_ServerServiceType) TmpServerServicePtr;
  SD_P2CONST(Sd_EventHandlerType) TmpEventHandlerPtr;

#if (SD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE == SD_CONFIGURATION_VARIANT)
  /* Save the config pointer */
  Sd_ConfigPtr = ConfigPtr;

  /* Check validity of config pointer */
  if(Sd_ConfigPtr == NULL_PTR)
  {
    EcuM_BswErrorHook((uint16) SD_MODULE_ID, (uint8) ECUM_BSWERROR_NULLPTR);

    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Sd_CallDetReportError(SD_API_ID_INIT, SD_E_PARAM_POINTER);
    Sd_State = SD_STATE_UNINIT;
    return;
  }

  if(SD_FINAL_MAGIC_NUMBER != Sd_ConfigPtr->FinalMagicNumber)
  {
    EcuM_BswErrorHook((uint16) SD_MODULE_ID, (uint8) ECUM_BSWERROR_MAGICNUMBER);

    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Sd_CallDetReportError(SD_API_ID_INIT, SD_E_INIT_FAILED);
    Sd_State = SD_STATE_UNINIT;
    return;
  }
#else
  SD_DUMMY_STATEMENT(ConfigPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  SoConModeMapIdx = Sd_ConfigPtr->SoConModeMapSize;
  while(0 < SoConModeMapIdx)
  {
    SoConModeMapIdx--;

    Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConId = SOAD_INV_SO_CON_ID;
    Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConMode = SD_SOCON_MODE_OFFLINE;
  }

  /* Set the state of all Service Instances to DOWN/RELEASED (expect for instances which are AutoAvailable/AutoRequired) */

  /* Iterate over all Sd Instances */
  InstanceIdx = Sd_ConfigPtr->InstanceListSize;
  while(0 < InstanceIdx)
  {
    InstanceIdx--;

    TmpInstancePtr = Sd_GetInstancePtrByIdx(InstanceIdx);

    /* Trigger an initial run of the state machines */
    Sd_TriggerStateMachineRun(TmpInstancePtr); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* Iterate over all service instances to update and process the state machine */
    ServiceInstanceIdx = TmpInstancePtr->ServiceInstancePtrListSize;
    while(0 < ServiceInstanceIdx)
    {
      ServiceInstanceIdx--;
      TmpServiceInstancePtr = TmpInstancePtr->ServiceInstancePtrListPtr[ServiceInstanceIdx];

      if(NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr)
      {
        TmpServerServicePtr = TmpServiceInstancePtr->ServerInstancePtr;

        if(TRUE == TmpServiceInstancePtr->AutoAvailableAutoRequire)
        {
          TmpServerServicePtr->DynamicDataPtr->StateSWC = SD_SERVER_SERVICE_AVAILABLE;
        }
        else
        {
          TmpServerServicePtr->DynamicDataPtr->StateSWC = SD_SERVER_SERVICE_DOWN;
        }

        /* Initialize all dynamic variables */
        TmpServerServicePtr->DynamicDataPtr->StateMachine = SD_SERVER_STATE_NONE;
        TmpServerServicePtr->DynamicTimerPtr->InitialOfferRepetitionRun = 0;
        /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
        Sd_ResetTimerToInvalid(TmpServerServicePtr->DynamicTimerPtr->TimeToTriggerSend);

        EventGroupIdx = TmpServerServicePtr->NrOfEventHandlers;
        while(0 < EventGroupIdx)
        {
          EventGroupIdx--;

          TmpEventHandlerPtr = &TmpServerServicePtr->EventHandlerPtr[EventGroupIdx];

          TmpEventHandlerPtr->DynamicDataPtr->StateMachine = SD_EVENT_HANDLER_STATE_NONE;
          TmpEventHandlerPtr->DynamicDataPtr->NrOfClients = 0;
          TmpEventHandlerPtr->DynamicDataPtr->NrOfClientsUdp = 0;
          TmpEventHandlerPtr->DynamicDataPtr->RequestStateEG = SD_EVENT_HANDLER_RELEASED;
          BswM_Sd_EventHandlerCurrentState(TmpEventHandlerPtr->EventGroupHandleId, SD_EVENT_HANDLER_RELEASED); /* \trace CREQ-121004 */

          ClientIdx = TmpEventHandlerPtr->MaxNrHandledClients;
          while(0 < ClientIdx)
          {
            ClientIdx--;

            TmpEventHandlerPtr->ClientListPtr[ClientIdx].ClientState = SD_EVENT_HANDLER_CLIENT_STATE_INVALID;
            TmpEventHandlerPtr->ClientListPtr[ClientIdx].NrOfReferences = 0;
          }

          /* Initialize the map for the number of TCP activations */
          if(NULL_PTR != TmpEventHandlerPtr->TcpRefPtr)
          {
            TmpIdx = TmpEventHandlerPtr->TcpRefPtr->NrSoConActivationMaps;
            while(0 < TmpIdx)
            {
              TmpIdx--;
              TmpEventHandlerPtr->TcpRefPtr->SoConActivationMapPtr[TmpIdx].NrOfActivations = 0;
              TmpEventHandlerPtr->TcpRefPtr->SoConActivationMapPtr[TmpIdx].SoConId = SOAD_INV_SO_CON_ID;
            }
          }

          /* Initialize the map for the number of UDP activations */
          if(NULL_PTR != TmpEventHandlerPtr->UdpRefPtr)
          {
            TmpIdx = TmpEventHandlerPtr->UdpRefPtr->NrSoConActivationMaps;
            while(0 < TmpIdx)
            {
              TmpIdx--;
              TmpEventHandlerPtr->UdpRefPtr->SoConActivationMapPtr[TmpIdx].NrOfActivations = 0;
              TmpEventHandlerPtr->UdpRefPtr->SoConActivationMapPtr[TmpIdx].SoConId = SOAD_INV_SO_CON_ID;
            }
          }
        }
      }
      else /* NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr */
      {
        TmpClientServicePtr = TmpServiceInstancePtr->ClientInstancePtr;

        /* Inform the BswM if the Sd_Init() is called while being in the initial wait phase */
        if(SD_CLIENT_STATE_SEARCHING_INITIAL_WAIT == TmpClientServicePtr->DynamicDataPtr->StateMachine)
        {
          /* Inform the BswM about the state of the client service and all consumed eventgroups. \trace CREQ-121005, CREQ-121006 */
          BswM_Sd_ClientServiceCurrentState(TmpServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_DOWN);

          EventGroupIdx = TmpClientServicePtr->NrOfEventGroups;
          while(0 < EventGroupIdx)
          {
            EventGroupIdx--;
            BswM_Sd_ConsumedEventGroupCurrentState(TmpClientServicePtr->EventGroupPtrPtr[EventGroupIdx]->EventGroupHandleId,
              SD_CONSUMED_EVENTGROUP_DOWN);
          }
        }

        if(TRUE == TmpServiceInstancePtr->AutoAvailableAutoRequire)
        {
          TmpClientServicePtr->DynamicDataPtr->StateSWC = SD_CLIENT_SERVICE_REQUESTED;
        }
        else
        {
          TmpClientServicePtr->DynamicDataPtr->StateSWC = SD_CLIENT_SERVICE_RELEASED;
        }

        TmpClientServicePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_DOWN;
        TmpClientServicePtr->DynamicDataPtr->StateMachine = SD_CLIENT_STATE_NONE;
        TmpClientServicePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_NONE;
        TmpClientServicePtr->DynamicDataPtr->ServerAddrPtr = NULL_PTR;
        TmpClientServicePtr->DynamicDataPtr->ServerTcpEndpointAddr.family = SOAD_AF_INVALID;
        TmpClientServicePtr->DynamicDataPtr->ServerUdpEndpointAddr.family = SOAD_AF_INVALID;
        TmpClientServicePtr->DynamicDataPtr->ServerMulticastEndpointAddr.family = SOAD_AF_INVALID;
        TmpClientServicePtr->DynamicDataPtr->MethodUdpSoConId = SOAD_INV_SO_CON_ID;
        TmpClientServicePtr->DynamicDataPtr->MethodTcpSoConId = SOAD_INV_SO_CON_ID;
        TmpClientServicePtr->DynamicDataPtr->OfferedTTL = 0;
        /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
        Sd_ResetTimerToInvalid(TmpClientServicePtr->DynamicTimerPtr->TimeToTriggerSend);
        Sd_ResetTimerToZero(TmpClientServicePtr->DynamicTimerPtr->TimerTTL);
        TmpClientServicePtr->DynamicTimerPtr->RepetitionRun = 0;

        EventGroupIdx = TmpClientServicePtr->NrOfEventGroups;
        while(0 < EventGroupIdx)
        {
          EventGroupIdx--;

          TmpEventGroupPtr = TmpClientServicePtr->EventGroupPtrPtr[EventGroupIdx];
          TmpEventGroupPtr->DynamicDataPtr->CurrentState = SD_CONSUMED_EVENTGROUP_DOWN;

          if(TRUE == TmpEventGroupPtr->AutoRequire)
          {
            TmpEventGroupPtr->DynamicDataPtr->ServiceModeRequest = SD_CONSUMED_EVENTGROUP_REQUESTED;
          }
          else
          {
            TmpEventGroupPtr->DynamicDataPtr->ServiceModeRequest = SD_CONSUMED_EVENTGROUP_RELEASED;
          }

          TmpEventGroupPtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_EVENTGROUP_NONE;
          TmpEventGroupPtr->DynamicDataPtr->StateMachine = SD_CONSUMED_EVENTGROUP_STATE_UNSUBSCRIBED;
          Sd_ResetTimerToZero(TmpEventGroupPtr->DynamicDataPtr->TimerTTL); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          TmpEventGroupPtr->DynamicDataPtr->AcknowledgedTTL = 0;
          TmpEventGroupPtr->DynamicDataPtr->MulticastSoConId = SOAD_INV_SO_CON_ID;
          TmpEventGroupPtr->DynamicDataPtr->UdpSoConId = SOAD_INV_SO_CON_ID;
          TmpEventGroupPtr->DynamicDataPtr->TcpSoConId = SOAD_INV_SO_CON_ID;
        }
      }

      /* Add all TCP socket connections to the socket connection map in order to monitor their current mode */
      TmpIdx = TmpServiceInstancePtr->TcpSoConListSize;
      if(0 != TmpIdx)
      {
        while(0 < TmpIdx)
        {
          TmpIdx--;
          Sd_SetSoConMode(TmpServiceInstancePtr->TcpSoConListPtr[TmpIdx], SOAD_SOCON_OFFLINE);
        }
      }
    }

    /* Initialize the RxEvent list */
    TmpInstancePtr->RxEventListPtr->Full = FALSE;
    TmpInstancePtr->RxEventListPtr->StartIdx = 0;
    TmpInstancePtr->RxEventListPtr->EndIdx = 0;
    TmpInstancePtr->RxEventListPtr->RxEventPtr = &Sd_ConfigPtr->RxEventPtr[RxTxEntryIdxGlobal];
    ClientIdx = TmpInstancePtr->MaxNrRxTxEntries;
    while(0 < ClientIdx)
    {
      ClientIdx --;
      TmpInstancePtr->RxEventListPtr->RxEventPtr[ClientIdx].ClientPtr = NULL_PTR;
      TmpInstancePtr->RxEventListPtr->RxEventPtr[ClientIdx].EventHandlerPtr = NULL_PTR;
      TmpInstancePtr->RxEventListPtr->RxEventPtr[ClientIdx].Event = SD_SERVER_EVENT_EVENTGROUP_NONE;
    }

    /* Initialize the sendentry list */
    TmpInstancePtr->SendEntriesListPtr->SendEntryPtr = &Sd_ConfigPtr->SendEntryArrayPtr[RxTxEntryIdxGlobal];
    TmpIdx = TmpInstancePtr->MaxNrRxTxEntries;
    while(0 < TmpIdx)
    {
      TmpIdx--;

      TmpInstancePtr->SendEntriesListPtr->SendEntryPtr[TmpIdx].Valid = FALSE;
    }
    TmpInstancePtr->SendEntriesListPtr->NrOfSendEntries = 0;
    TmpInstancePtr->SendEntriesListPtr->RootInstancePtr = TmpInstancePtr;
    RxTxEntryIdxGlobal = (uint16)(RxTxEntryIdxGlobal + TmpInstancePtr->MaxNrRxTxEntries);
    if(TmpInstancePtr->MaxNrRxTxEntries > MaxSizePendingMessages)
    {
      MaxSizePendingMessages = TmpInstancePtr->MaxNrRxTxEntries;
    }

    /* Initialize the dynamic data structures */
    Sd_ResetTimerToZero(TmpInstancePtr->DynamicDataPtr->NextStateMachineRun); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(SD_STATE_UNINIT == Sd_State)
    {
      /* The link state is only changed at the initial run after a reboot */
      TmpInstancePtr->DynamicDataPtr->State = SD_INSTANCE_DOWN;
      TmpInstancePtr->DynamicDataPtr->SdUnicastAddr.family = SOAD_AF_UNSPEC;
      TmpInstancePtr->DynamicDataPtr->InitialRun = SD_INITIAL_RUN;
    }

    /* Initialize the option index */
    Sd_GetNrOfOptionsInList() = 0;
    Sd_GetOptionIndexListPtr()->OptionIndexPtr = Sd_ConfigPtr->OptionIndexArrayPtr;

    /* Initialize the address storage array */
    TmpIdx = TmpInstancePtr->AddressStorageListSize;
    while(0 < TmpIdx)
    {
      TmpIdx--;

      TmpInstancePtr->AddressStorageListPtr[TmpIdx].SessionIdCounter = 0;  /* Session id of 0 is not allowed -> unused/invalid address */
      TmpInstancePtr->AddressStorageListPtr[TmpIdx].Flags = SD_FLAGS_REBOOT_MASK | SD_FLAGS_UNICAST_MASK;
      TmpInstancePtr->AddressStorageListPtr[TmpIdx].RxUnicastSessionId = 0;
      TmpInstancePtr->AddressStorageListPtr[TmpIdx].RxMulticastSessionId = 0;
      TmpInstancePtr->AddressStorageListPtr[TmpIdx].RxUnicastFlags = SD_FLAGS_REBOOT_MASK | SD_FLAGS_UNICAST_MASK;
      TmpInstancePtr->AddressStorageListPtr[TmpIdx].RxMulticastFlags = SD_FLAGS_REBOOT_MASK | SD_FLAGS_UNICAST_MASK;
    }

    TmpInstancePtr->AddressStorageListPtr[TmpInstancePtr->AddressStorageListSize - 1].SessionIdCounter = 1;

    /* Initialize the endpoint storage array */
    TmpIdx = TmpInstancePtr->EndpointListSize;
    while(0 < TmpIdx)
    {
      TmpIdx--;

      TmpInstancePtr->EndpointListPtr[TmpIdx].Addr.family = SOAD_AF_INVALID;
      TmpInstancePtr->EndpointListPtr[TmpIdx].Type = SD_ENDPOINT_TYPE_INVALID;
      TmpInstancePtr->EndpointListPtr[TmpIdx].NrOfReferences = 0;
    }
  }

  if(Sd_IsTriggerTransmitUsed())
  {
    /* Initialize the trigger transmit list */
    Sd_GetTriggerTransmitList().Full = FALSE;
    Sd_GetTriggerTransmitList().StartIdx = 0;
    Sd_GetTriggerTransmitList().EndIdx = 0;
    TmpIdx = Sd_ConfigPtr->TriggerTransmitEventArraySize;
    while(0 < TmpIdx)
    {
      TmpIdx--;

      Sd_GetTriggerTransmitEvent(TmpIdx).ClientPtr = NULL_PTR;
      Sd_GetTriggerTransmitEvent(TmpIdx).EventHandlerPtr = NULL_PTR;
      Sd_GetTriggerTransmitEvent(TmpIdx).State = SD_TRIGGER_TRANSMIT_STATE_INVALID;
    }
  }

  /* Initialize the temporary sendentry list */
  TmpIdx = MaxSizePendingMessages;
  while(0 < TmpIdx)
  {
    TmpIdx--;

    Sd_GetTmpSendEntry(TmpIdx).Valid = FALSE;
  }
  Sd_GetTmpSendEntryList().SendEntryPtr = &Sd_GetTmpSendEntry(0);
  Sd_GetTmpSendEntryList().NrOfSendEntries = 0;
  Sd_GetTmpSendEntryList().RootInstancePtr = NULL_PTR;

  /* Initialize the Request Count for each dynamic multicast address */
  TmpIdx = Sd_GetIpAddrRequestCntMapSize();
  while(0 < TmpIdx)
  {
    TmpIdx--;

    *Sd_GetIpAddrRequestCntEntry(TmpIdx).RequestCntPtr = 0;
    *Sd_GetIpAddrRequestCntEntry(TmpIdx).PortSetPtr = FALSE;
  }

  /* Set the state to initialized */
  Sd_State = SD_STATE_INIT;
} /* PRQA S 2006, 6010, 6030, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_InitialRunInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_InitialRunInit(
  SD_P2CONST(Sd_InstanceType) InstancePtr)
{
  Std_ReturnType RetVal;
  uint16 ServiceInstanceIdx, EventGroupIdx, RefIdx;
  SD_P2CONST(Sd_ServiceInstanceType) TmpServiceInstancePtr;
  SD_P2CONST(Sd_ConsumedEventGroupType) TmpConsumedEventGroupPtr;
  SD_P2CONST(Sd_EventHandlerType) TmpEventHandlerPtr;
  Sd_SockAddrContainerType LocalAddr;
  Sd_SockAddrContainerType DefaultRouter;
  uint8 NetmaskCidr = 0;

  /* Clear the list of endpoint entries */
  RefIdx = InstancePtr->EndpointListSize;
  while(0 < RefIdx)
  {
    RefIdx--;
    InstancePtr->EndpointListPtr[RefIdx].NrOfReferences = 0;
    InstancePtr->EndpointListPtr[RefIdx].Type = SD_ENDPOINT_TYPE_INVALID;
    InstancePtr->EndpointListPtr[RefIdx].Addr.family = SOAD_AF_INVALID;
  }

  /* Get the Sd multicast address */
  LocalAddr.family = SOAD_AF_INVALID;
  /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
  RetVal = SoAd_GetLocalAddr(InstancePtr->MulticastRxSoConId,
    (SD_P2VAR(SoAd_SockAddrType))&LocalAddr, &NetmaskCidr, (SD_P2VAR(SoAd_SockAddrType))&DefaultRouter);

  if(E_OK == RetVal)
  {
    /* Save the address */
    /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
    Sd_CopySockAddr((SD_P2VAR(SoAd_SockAddrType))(&InstancePtr->AddressStorageListPtr[InstancePtr->AddressStorageListSize - 1].Addr),
      (SD_P2CONST(SoAd_SockAddrType))&LocalAddr);
    InstancePtr->AddressStorageListPtr[InstancePtr->AddressStorageListSize - 1].SessionIdCounter = 1;

    /* Set the SoAd remote address of the Rx and Tx SoCons to multicast in order to initialize (open) the socket */
    /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
    /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
    if(E_OK == SoAd_SetRemoteAddr(InstancePtr->UnicastRxSoConId, (SD_P2VAR(SoAd_SockAddrType))&LocalAddr))
    {
      (void)SoAd_OpenSoCon(InstancePtr->UnicastRxSoConId);
    }
    /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
    /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
    if(E_OK == SoAd_SetRemoteAddr(InstancePtr->MulticastRxSoConId, (SD_P2VAR(SoAd_SockAddrType))&LocalAddr))
    {
      (void)SoAd_OpenSoCon(InstancePtr->MulticastRxSoConId);
    }
    /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
    /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
    if(E_OK == SoAd_SetRemoteAddr(InstancePtr->TxSoConId, (SD_P2VAR(SoAd_SockAddrType))&LocalAddr))
    {
      (void)SoAd_OpenSoCon(InstancePtr->TxSoConId);
    }

    /* Initialize the socket connections */
    /* Iterate over all service instances to update and process the state machine */
    ServiceInstanceIdx = InstancePtr->ServiceInstancePtrListSize;
    while(0 < ServiceInstanceIdx)
    {
      ServiceInstanceIdx--;
      TmpServiceInstancePtr = InstancePtr->ServiceInstancePtrListPtr[ServiceInstanceIdx];

      /* Differentiate between server and client service */
      if(NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr)
      {
        /* Method SoCon */
        if( NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr->ProvidedMethodPtr)
        {
          /* Disable the referenced routing group */
          (void)SoAd_DisableRouting(TmpServiceInstancePtr->ServerInstancePtr->ProvidedMethodPtr->ActivationRef);
        }

        /* Iterate over all EventHandlers, disable the RoutingGroups and reset the SoCons */
        EventGroupIdx = TmpServiceInstancePtr->ServerInstancePtr->NrOfEventHandlers;
        while(0 < EventGroupIdx)
        {
          EventGroupIdx--;

          TmpEventHandlerPtr = &TmpServiceInstancePtr->ServerInstancePtr->EventHandlerPtr[EventGroupIdx];

          /* Multicast event handler */
          if(Sd_EventHandlerUsesMulticast(TmpEventHandlerPtr))
          {
            (void)SoAd_CloseSoCon(TmpEventHandlerPtr->MulticastRefPtr->SoConId, TRUE);
            (void)SoAd_DisableRouting(TmpEventHandlerPtr->MulticastRefPtr->ActivationRef);
          }

          /* TCP event handler */
          if(Sd_EventHandlerUsesTcp(TmpEventHandlerPtr))
          {
            (void)SoAd_DisableRouting(TmpEventHandlerPtr->TcpRefPtr->ActivationRef);
            Sd_ResetActivationCount(TmpEventHandlerPtr->TcpRefPtr);
          }

          /* UDP event handler */
          if(Sd_EventHandlerUsesUdp(TmpEventHandlerPtr))
          {
            (void)SoAd_DisableRouting(TmpEventHandlerPtr->UdpRefPtr->ActivationRef);
            Sd_ResetActivationCount(TmpEventHandlerPtr->UdpRefPtr);
          }

          /* Clear the list of subscribed clients */
          TmpEventHandlerPtr->DynamicDataPtr->NrOfClients = 0;
          TmpEventHandlerPtr->DynamicDataPtr->NrOfClientsUdp = 0;
          RefIdx = TmpEventHandlerPtr->MaxNrHandledClients;
          while(0 < RefIdx)
          {
            RefIdx--;
            TmpEventHandlerPtr->ClientListPtr[RefIdx].ClientState = SD_EVENT_HANDLER_CLIENT_STATE_INVALID;
          }
        }
      }
      else  /* NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr */
      {
        /* Iterate over all EventGroups, disable the RoutingGroups and reset the SoCons */
        EventGroupIdx = TmpServiceInstancePtr->ClientInstancePtr->NrOfEventGroups;
        while(0 < EventGroupIdx)
        {
          EventGroupIdx--;

          TmpConsumedEventGroupPtr = TmpServiceInstancePtr->ClientInstancePtr->EventGroupPtrPtr[EventGroupIdx];

          /* Multicast */
          if(Sd_ConsumedEventGroupUsesMulticast(TmpConsumedEventGroupPtr))
          {
            (void)SoAd_DisableRouting(TmpConsumedEventGroupPtr->MulticastActRef);

            RefIdx = TmpConsumedEventGroupPtr->NrMulticastSoCons;
            while(0 < RefIdx)
            {
              RefIdx--;
              (void)SoAd_CloseSoCon(TmpConsumedEventGroupPtr->MulticastSoConPtr[RefIdx], TRUE);
            }
          }

          /* TCP */
          if(Sd_ConsumedEventGroupUsesTcp(TmpConsumedEventGroupPtr))
          {
            (void)SoAd_DisableRouting(TmpConsumedEventGroupPtr->TcpActRef);
          }

          /* UDP */
          if(Sd_ConsumedEventGroupUsesUdp(TmpConsumedEventGroupPtr))
          {
            (void)SoAd_DisableRouting(TmpConsumedEventGroupPtr->UdpActRef);
          }
        }

        /* Method SoCon */
        if( NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr->MethodPtr)
        {
          (void)SoAd_DisableRouting(TmpServiceInstancePtr->ClientInstancePtr->MethodPtr->ActivationRef);
        }
      }

      /* Close all TCP socket connections */
      RefIdx = TmpServiceInstancePtr->TcpSoConListSize;
      while(0 < RefIdx)
      {
        RefIdx--;
        (void)SoAd_CloseSoCon(TmpServiceInstancePtr->TcpSoConListPtr[RefIdx], TRUE);
      }

      /* Close all UDP socket connections */
      RefIdx = TmpServiceInstancePtr->UdpSoConListSize;
      while(0 < RefIdx)
      {
        RefIdx--;
        (void)SoAd_CloseSoCon(TmpServiceInstancePtr->UdpSoConListPtr[RefIdx], TRUE);
      }
    }
  }
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

#if (SD_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Sd_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, SD_CODE) Sd_GetVersionInfo( SD_P2VAR(Std_VersionInfoType) VersionInfoPtr)
{
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnVoid(!(NULL_PTR == VersionInfoPtr), SD_API_ID_GET_VERSION_INFO, SD_E_PARAM_POINTER);

  VersionInfoPtr->vendorID = (uint16)SD_VENDOR_ID;
  VersionInfoPtr->moduleID = (uint16)SD_MODULE_ID;
  VersionInfoPtr->sw_major_version = (uint8)SD_SW_MAJOR_VERSION;
  VersionInfoPtr->sw_minor_version = (uint8)SD_SW_MINOR_VERSION;
  VersionInfoPtr->sw_patch_version = (uint8)SD_SW_PATCH_VERSION;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif  /* SD_VERSION_INFO_API */

/**********************************************************************************************************************
 *  Sd_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, SD_CODE) Sd_MainFunction(void)
{
  Std_ReturnType RetVal;
  boolean PendingStopSubscribe;
  uint16 InstanceIdx, ServiceInstanceIdx;
  SD_P2CONST(Sd_InstanceType) TmpInstancePtr;
  SD_P2CONST(Sd_ServiceInstanceType) TmpServiceInstancePtr;
  SD_P2VAR(Sd_RxEventType) EventPtr = NULL_PTR;
  SD_P2VAR(Sd_TriggerTransmitType) TmpTriggerTransmitPtr;

  /* Update the time since start of the Sd_Init() function */
  Sd_SetTimerOffsetNoTrigger(Sd_TimeMsSinceStart, SD_MAIN_FCT_CYCLE_TIME_MS); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnVoid(!(SD_STATE_UNINIT == Sd_State), SD_API_ID_MAIN_FUNCTION, SD_E_NOT_INITIALIZED);

  /* Iterate over all Sd Instances */
  InstanceIdx = Sd_ConfigPtr->InstanceListSize;
  while(0 < InstanceIdx)
  {
    InstanceIdx--;
    TmpInstancePtr = Sd_GetInstancePtrByIdx(InstanceIdx);
    PendingStopSubscribe = FALSE;

    if(SD_RUNNING != TmpInstancePtr->DynamicDataPtr->InitialRun)
    {
      Sd_InitialRunInit(TmpInstancePtr);

      TmpInstancePtr->DynamicDataPtr->InitialRun = SD_RUNNING;
    }

    /* Process all pending events for SdEventHandler */
    while(TRUE == Sd_ReadFirstEventOfRingBuffer(TmpInstancePtr->RxEventListPtr, &EventPtr))
    {
      if(SD_EVENT_HANDLER_CLIENT_STATE_INVALID != EventPtr->ClientPtr->ClientState)
      {
        if((SD_EVENT_HANDLER_STATE_NOT_SUBSCRIBED == EventPtr->EventHandlerPtr->DynamicDataPtr->StateMachine) ||
          (SD_EVENT_HANDLER_STATE_UNICAST_SUBSCRIPTION == EventPtr->EventHandlerPtr->DynamicDataPtr->StateMachine) ||
          (SD_EVENT_HANDLER_STATE_MULTICAST_SUBSCRIPTION == EventPtr->EventHandlerPtr->DynamicDataPtr->StateMachine))
        {
          if((SD_SERVER_EVENT_EVENTGROUP_SUBSCRIBE == EventPtr->Event) ||
            (SD_SERVER_EVENT_EVENTGROUP_SUBSCRIBE_MULTI == EventPtr->Event))
          {
            if(FALSE == PendingStopSubscribe)
            {
              RetVal = Sd_UpdateServerServiceSoCons(EventPtr);

              if(E_OK == RetVal)
              {
                /* Subscription was successful */

                /* Send a SubscribeEventgroupAcknowledge message and update the state */
                Sd_AddEventGroupAckEntryToList(TmpInstancePtr->SendEntriesListPtr, EventPtr);

                /* PRQA S 0715 2 */ /* MD_MSR_1.1_0715 */
                if(SD_EVENT_HANDLER_STATE_NOT_SUBSCRIBED == EventPtr->EventHandlerPtr->DynamicDataPtr->StateMachine)
                {
                  if(SD_EVENT_HANDLER_REQUESTED != EventPtr->EventHandlerPtr->DynamicDataPtr->RequestStateEG)
                  {
                    /* Set the state of the event handler to requested and inform the BswM. \trace CREQ-121004 */
                    Sd_SetValueAndTrigger(EventPtr->EventHandlerPtr->DynamicDataPtr->RequestStateEG,
                      SD_EVENT_HANDLER_REQUESTED, TmpInstancePtr);
                    BswM_Sd_EventHandlerCurrentState(EventPtr->EventHandlerPtr->EventGroupHandleId, SD_EVENT_HANDLER_REQUESTED);
                  }

                  Sd_UpdateEventHandlerStateMachine(EventPtr->EventHandlerPtr, SD_EVENT_HANDLER_STATE_UNICAST_SUBSCRIPTION);
                }
              }
              else
              {
                /* Subscription was NOT successful */
                uint32 AdditionalDelay = 0;

                /* PRQA S 0715 2 */ /* MD_MSR_1.1_0715 */
                if(SD_SERVER_EVENT_EVENTGROUP_SUBSCRIBE_MULTI == EventPtr->Event)
                {
                  /* Add a random delay to the response message */
                  AdditionalDelay = Sd_GetRandomNrInRangeForResponse(EventPtr->EventHandlerPtr->TimerRef->RequestResponseMinDelay,
                    EventPtr->EventHandlerPtr->TimerRef->RequestResponseMaxDelay, FALSE);
                }

                /* Send a SubscribeEventgroupNegativeAcknowledge message */
                Sd_AddEventGroupNackEntryToList(TmpInstancePtr->SendEntriesListPtr,
                  EventPtr->EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr,
                  EventPtr->EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->ServiceId,
                  EventPtr->EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->InstanceId,
                  EventPtr->EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->MajorVersion,
                  EventPtr->ClientPtr->RxReserved, EventPtr->EventHandlerPtr->EventGroupId, EventPtr->ClientPtr->AddrPtr,
                  AdditionalDelay);
              }
            }
            else
            {
              /* There is a pending StopSubscribe which has to be handled during the next run of the SoAd_MainFunction() */
              /* Resume processing of the subscription in the next MainFunction cycle */
              break;
            }
          }
          else if((SD_SERVER_EVENT_EVENTGROUP_STOP_SUBSCRIBE == EventPtr->Event) ||
            (SD_SERVER_EVENT_EVENTGROUP_STOP_SUBSCRIBE_MULTI == EventPtr->Event))
          {
            (void)Sd_UpdateServerServiceSoCons(EventPtr);

            PendingStopSubscribe = TRUE;
          }
          else
          {
            /* Nothing to do */
          }
        }
      }

      /* Remove the processed event from the buffer */
      Sd_RemoveFirstEventFromRingBuffer(TmpInstancePtr);
    }

    /* Check if the states machines have to be triggered because of a pending timer event */
    if(TRUE == Sd_CheckIfTimerExceeded(TmpInstancePtr->DynamicDataPtr->NextStateMachineRun, TRUE))
    {
      /* Reset the timer */
      Sd_ResetTimerToInvalid(TmpInstancePtr->DynamicDataPtr->NextStateMachineRun); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* Iterate over all service instances to update and process the state machine */
      ServiceInstanceIdx = TmpInstancePtr->ServiceInstancePtrListSize;
      while(0 < ServiceInstanceIdx)
      {
        ServiceInstanceIdx--;
        TmpServiceInstancePtr = TmpInstancePtr->ServiceInstancePtrListPtr[ServiceInstanceIdx];

        /* Differentiate between server and client service */
        if(NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr)
        {
          Sd_RunServerStateMachine(TmpServiceInstancePtr);
        }
        else  /* NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr */
        {
          Sd_RunClientStateMachine(TmpServiceInstancePtr);
        }
      }
    }

    /* Pack all pending messages together and transmit the message */
    Sd_ProcessPendingMessages(TmpInstancePtr->SendEntriesListPtr, FALSE);
  }

  /* Process all pending trigger transmit requests */
  while(TRUE == Sd_ReadFirstTriggerTransmitOfRingBuffer(&TmpTriggerTransmitPtr))
  {
    if(SD_TRIGGER_TRANSMIT_STATE_NOW == TmpTriggerTransmitPtr->State)
    {
      SD_P2VAR(Sd_ClientListType) TmpClientPtr;
      TmpClientPtr = TmpTriggerTransmitPtr->ClientPtr;

      if((SOAD_INV_SO_CON_ID != TmpClientPtr->AssignedTcpSoConId) &&
        (SOAD_INV_ROUT_GRP_ID != TmpTriggerTransmitPtr->EventHandlerPtr->TcpRefPtr->TriggerRef))
      {
        /* Trigger the initial transmission for TCP. \trace CREQ-121043 */
        (void)SoAd_IfSpecificRoutingGroupTransmit(TmpTriggerTransmitPtr->EventHandlerPtr->TcpRefPtr->TriggerRef,
          TmpClientPtr->AssignedTcpSoConId);
      }
      if((SOAD_INV_SO_CON_ID != TmpClientPtr->AssignedUdpSoConId) &&
        (SOAD_INV_ROUT_GRP_ID != TmpTriggerTransmitPtr->EventHandlerPtr->UdpRefPtr->TriggerRef))
      {
        /* Trigger the initial transmission for UDP. \trace CREQ-121043 */
        (void)SoAd_IfSpecificRoutingGroupTransmit(TmpTriggerTransmitPtr->EventHandlerPtr->UdpRefPtr->TriggerRef,
          TmpClientPtr->AssignedUdpSoConId);
      }

      /* remove the trigger transmit request */
      Sd_RemoveFirstTriggerTransmitFromRingBuffer();
    }
    else  /* SD_TRIGGER_TRANSMIT_STATE_NEXT_CYCLE == TmpTriggerTransmitPtr->State */
    {
      TmpTriggerTransmitPtr->State = SD_TRIGGER_TRANSMIT_STATE_NOW;
      break;
    }
  }
} /* PRQA S 2006, 6010, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_RunServerStateMachine()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_RunServerStateMachine(
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr)
{
  SD_P2CONST(Sd_ServerServiceType)   TmpServerInstancePtr = ServiceInstancePtr->ServerInstancePtr;
  SD_P2CONST(Sd_ServerTimerType)     TmpTimerPtr = TmpServerInstancePtr->TimerRef;
  uint32 AdditionalOffset;
  uint16 EventHandlerIdx, SoConRefIdx;

  /* Handle the state machine within the ready block */
  switch(TmpServerInstancePtr->DynamicDataPtr->StateMachine)
  {
    case SD_SERVER_STATE_NONE :
      /* First run of the state machine */
      if((SD_INSTANCE_UP_AND_CONFIGURED == ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State) &&
        (SD_SERVER_SERVICE_AVAILABLE == TmpServerInstancePtr->DynamicDataPtr->StateSWC))
      {
        Sd_UpdateServerStateMachine(TmpServerInstancePtr, SD_SERVER_STATE_READY_INITIAL_WAIT, FALSE);
      }
      else
      {
        Sd_UpdateServerStateMachine(TmpServerInstancePtr, SD_SERVER_STATE_NOT_READY, FALSE);
      }
      break;

    case SD_SERVER_STATE_NOT_READY :
      if((SD_INSTANCE_UP_AND_CONFIGURED == ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State) &&
        (SD_SERVER_SERVICE_AVAILABLE == TmpServerInstancePtr->DynamicDataPtr->StateSWC))
      {
        /* Update the state and reset the TimeToTriggerSend */
        Sd_UpdateServerStateMachine(TmpServerInstancePtr, SD_SERVER_STATE_READY_INITIAL_WAIT, TRUE);
      }
      break;

    case SD_SERVER_STATE_READY_INITIAL_WAIT :
      if(SD_INSTANCE_UP_AND_CONFIGURED != ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State)
      {
        Sd_UpdateServerStateMachine(TmpServerInstancePtr, SD_SERVER_STATE_NOT_READY, FALSE);
      }
      else if(Sd_CheckIfTimerIsInvalid(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend))
      {
        /* First run of the wait state */

        if(NULL_PTR != TmpServerInstancePtr->ProvidedMethodPtr)
        {
          /* Enable the routing groups for the provided method */
          (void)SoAd_EnableRouting(TmpServerInstancePtr->ProvidedMethodPtr->ActivationRef);
        }

        /* Open all present multicast SocketConnections */
        EventHandlerIdx = TmpServerInstancePtr->NrOfEventHandlers;
        while(0 < EventHandlerIdx)
        {
          EventHandlerIdx--;

          if(Sd_EventHandlerUsesMulticast(&TmpServerInstancePtr->EventHandlerPtr[EventHandlerIdx]))
          {
            (void)SoAd_OpenSoCon(TmpServerInstancePtr->EventHandlerPtr[EventHandlerIdx].MulticastRefPtr->SoConId);
          }
        }

        /* Open the TCP SocketConnections in order to allow incoming connections */
        if(NULL_PTR != ServiceInstancePtr->TcpSoConListPtr)
        {
          SoConRefIdx = ServiceInstancePtr->TcpSoConListSize;
          while(0 < SoConRefIdx)
          {
            SoConRefIdx--;
            (void)SoAd_OpenSoCon(ServiceInstancePtr->TcpSoConListPtr[SoConRefIdx]);
          }
        }

        /* Timer is unused and can be set */
        AdditionalOffset = Sd_GetRandomNrInRange(TmpTimerPtr->InitialOfferDelayMin, TmpTimerPtr->InitialOfferDelayMax);
        Sd_SetTimerOffset(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend,
          AdditionalOffset, ServiceInstancePtr->RootInstancePtr);
      }
      else  /* Timer is running, check if exceeded already */
      {
        if(TRUE == Sd_CheckIfTimerExceeded(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend, TRUE))
        {
          /* Update the state and reset the TimeToTriggerSend */
          Sd_UpdateServerStateMachine(TmpServerInstancePtr, SD_SERVER_STATE_READY_REPETITION, TRUE);

          /* Send a OfferService message */
          Sd_AddMulticastOfferEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, ServiceInstancePtr, FALSE);
        }
      }
      break;

    case SD_SERVER_STATE_READY_REPETITION :
      /* Initial run of the repetition phase */
      /* Go to the main state if there is no repetition phase configured */
      if(0 == TmpTimerPtr->InitialOfferRepetitionsMax)
      {
        /* Update the state and reset the TimeToTriggerSend */
        Sd_UpdateServerStateMachine(TmpServerInstancePtr, SD_SERVER_STATE_READY_MAIN_PHASE, TRUE);
      }
      else if(Sd_CheckIfTimerIsInvalid(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend))
      {
        uint32 initialRepetitionDelay = TmpTimerPtr->InitialOfferRepetitionBaseDelay;
        if(SD_MAIN_FCT_CYCLE_TIME_MS <= initialRepetitionDelay)
        {
          initialRepetitionDelay -= SD_MAIN_FCT_CYCLE_TIME_MS;
        }

        /* Reset the repetition counter and initialize the timer */
        TmpServerInstancePtr->DynamicTimerPtr->InitialOfferRepetitionRun = 0;
        Sd_SetTimerOffset(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend, initialRepetitionDelay,
          ServiceInstancePtr->RootInstancePtr);
      }
      else
      {
        /* No further state transitions available */
      }

      /* Succeeding runs of the repetition phase */
      if((TRUE == Sd_CheckIfTimerExceeded(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend, TRUE)) &&
        (TmpTimerPtr->InitialOfferRepetitionsMax > TmpServerInstancePtr->DynamicTimerPtr->InitialOfferRepetitionRun) &&
        (SD_SERVER_STATE_READY_REPETITION == TmpServerInstancePtr->DynamicDataPtr->StateMachine))
      {
        /* Send a OfferService messgage and wait for the next repetition  */
        Sd_AddMulticastOfferEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, ServiceInstancePtr, FALSE);
        TmpServerInstancePtr->DynamicTimerPtr->InitialOfferRepetitionRun++;

        if(TmpTimerPtr->InitialOfferRepetitionsMax == TmpServerInstancePtr->DynamicTimerPtr->InitialOfferRepetitionRun)
        {
          /* Update the state and reset the TimeToTriggerSend */
          Sd_UpdateServerStateMachine(TmpServerInstancePtr, SD_SERVER_STATE_READY_MAIN_PHASE, TRUE);
        }
        else
        {
          /* Wind up the timer */
          Sd_SetTimerOffset(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend,
            (uint32)((uint32)(1 << TmpServerInstancePtr->DynamicTimerPtr->InitialOfferRepetitionRun) * TmpTimerPtr->InitialOfferRepetitionBaseDelay),
            ServiceInstancePtr->RootInstancePtr);
        }
      }
      break;

    case SD_SERVER_STATE_READY_MAIN_PHASE :
      /* Check if the server shall offer the current service instance */
      if(0 != TmpTimerPtr->OfferCyclicDelay)
      {
        /* Initial run of the main phase */
        if(Sd_CheckIfTimerIsInvalid(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend))
        {
          uint32 initialMainPhaseDelay = TmpTimerPtr->OfferCyclicDelay;
          if(SD_MAIN_FCT_CYCLE_TIME_MS <= initialMainPhaseDelay)
          {
            initialMainPhaseDelay -= SD_MAIN_FCT_CYCLE_TIME_MS;
          }

          /* Send the first offer message after the configured OfferCyclicDelay */
          Sd_SetTimerOffset(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend, initialMainPhaseDelay,
            ServiceInstancePtr->RootInstancePtr);
        }

        if(TRUE == Sd_CheckIfTimerExceeded(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend, TRUE))
        {
          /* Send a OfferService message */
          Sd_AddMulticastOfferEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, ServiceInstancePtr, FALSE);

          /* Wind up the timer */
          Sd_SetTimerOffset(TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend,
            TmpTimerPtr->OfferCyclicDelay, ServiceInstancePtr->RootInstancePtr);
        }
      }
      else
      {
        /* No offer messages are transmitted for this service */
      }
      break;

    default:
      /* Undefined state */
      break;
  }

  /* Check if the state machine is within the ready block and a condition to leave the block is fullfilled */
  if(((SD_INSTANCE_UP_AND_CONFIGURED != ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State) ||
    (SD_SERVER_SERVICE_DOWN == TmpServerInstancePtr->DynamicDataPtr->StateSWC)) &&
    ((SD_SERVER_STATE_READY_INITIAL_WAIT == TmpServerInstancePtr->DynamicDataPtr->StateMachine) ||
    (SD_SERVER_STATE_READY_REPETITION == TmpServerInstancePtr->DynamicDataPtr->StateMachine) ||
    (SD_SERVER_STATE_READY_MAIN_PHASE == TmpServerInstancePtr->DynamicDataPtr->StateMachine)))
  {
    /* Send a StopOfferService message only if the SD is still running */
    if(SD_INSTANCE_UP_AND_CONFIGURED == ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State)
    {
      /* Send a StopOfferService message */
      Sd_AddMulticastOfferEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, ServiceInstancePtr, TRUE);
    }

    /* Leave the ready-state and reset the TimeToTriggerSend */
    Sd_UpdateServerStateMachine(TmpServerInstancePtr, SD_SERVER_STATE_NOT_READY, TRUE);
  }

  /* Run the state machine, handling all eventhandlers of the server instance */
  Sd_RunEventHandlerStateMachine(ServiceInstancePtr);

  /* Update the time for the next state machine run */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_SetNextStateMachineRun(ServiceInstancePtr->RootInstancePtr, TmpServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend);
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_RunEventHandlerStateMachine()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_RunEventHandlerStateMachine(
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr)
{
  uint32 EventHandlerIdx, ClientIdx;
  SD_P2CONST(Sd_ServerServiceType) TmpServerInstancePtr = ServiceInstancePtr->ServerInstancePtr;
  SD_P2CONST(Sd_EventHandlerType) TmpEventHandlerPtr;
  SD_P2VAR(Sd_ClientListType) TmpClientPtr;

  /* Handle all event handlers of the server service instance */
  EventHandlerIdx = TmpServerInstancePtr->NrOfEventHandlers;
  while(0 < EventHandlerIdx)
  {
    EventHandlerIdx--;

    TmpEventHandlerPtr = &TmpServerInstancePtr->EventHandlerPtr[EventHandlerIdx];

    switch(TmpEventHandlerPtr->DynamicDataPtr->StateMachine)
    {
      case SD_EVENT_HANDLER_STATE_NONE:
        /* First run of the state machine */
        if(SD_SERVER_SERVICE_DOWN == TmpServerInstancePtr->DynamicDataPtr->StateSWC)
        {
          Sd_UpdateEventHandlerStateMachine(TmpEventHandlerPtr, SD_EVENT_HANDLER_STATE_SERVICE_DOWN);
        }
        else
        {
          Sd_UpdateEventHandlerStateMachine(TmpEventHandlerPtr, SD_EVENT_HANDLER_STATE_NOT_SUBSCRIBED);
        }
        break;

      case SD_EVENT_HANDLER_STATE_SERVICE_DOWN :
        if(SD_SERVER_SERVICE_AVAILABLE == TmpServerInstancePtr->DynamicDataPtr->StateSWC)
        {
          Sd_UpdateEventHandlerStateMachine(TmpEventHandlerPtr, SD_EVENT_HANDLER_STATE_NOT_SUBSCRIBED);
        }
        break;

      default:
        /* All other states are handled within the context of a client */
        break;
    }

    /* Iterate over all registered clients of a eventgroup */
    ClientIdx = TmpEventHandlerPtr->MaxNrHandledClients;
    while(0 < ClientIdx)
    {
      ClientIdx--;

      TmpClientPtr = &TmpEventHandlerPtr->ClientListPtr[ClientIdx];

      if(SD_EVENT_HANDLER_CLIENT_STATE_SUBSCRIBED == TmpClientPtr->ClientState)
      {
        /* Check the SubscribedUntil for the client */
        if(TRUE == Sd_CheckIfTimerExceeded(TmpClientPtr->SubscribedUntil, FALSE))
        {
          /* The client has unsubscribed or a timeout occurred. Unconfigure and remove the client */
          Sd_RemoveClientFromList(TmpEventHandlerPtr, TmpClientPtr);

          /* Check if the client was subscribed for a pure multicast event group and was the last subscribed client */
          if((!Sd_EventHandlerUsesUdp(TmpEventHandlerPtr)) && (!Sd_EventHandlerUsesTcp(TmpEventHandlerPtr)) &&
            Sd_EventHandlerUsesMulticast(TmpEventHandlerPtr) && (0 == TmpEventHandlerPtr->DynamicDataPtr->NrOfClients))
          {
            (void)SoAd_DisableSpecificRouting(TmpEventHandlerPtr->MulticastRefPtr->ActivationRef, TmpEventHandlerPtr->MulticastRefPtr->SoConId);
          }
        }

        /* Update the timer for the next state machine run */
        /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
        Sd_SetNextStateMachineRun(ServiceInstancePtr->RootInstancePtr, TmpClientPtr->SubscribedUntil);
      }
    }

    /* Switch to multicast if this functionality is configured and the corresponding amount of subscribed clients is reached. */
    if((0 != TmpEventHandlerPtr->MulticastThreshold) &&
      (TmpEventHandlerPtr->MulticastThreshold <= TmpEventHandlerPtr->DynamicDataPtr->NrOfClientsUdp) &&
      (SD_EVENT_HANDLER_STATE_UNICAST_SUBSCRIPTION == TmpEventHandlerPtr->DynamicDataPtr->StateMachine))
    {
      /* Enable the routing for the multicast SocketConnection */
      (void)SoAd_EnableSpecificRouting(TmpEventHandlerPtr->MulticastRefPtr->ActivationRef, TmpEventHandlerPtr->MulticastRefPtr->SoConId);

      /* Iterate over all registered clients of a eventgroup in order to disable the unicast routing groups */
      ClientIdx = TmpEventHandlerPtr->MaxNrHandledClients;
      while(0 < ClientIdx)
      {
        ClientIdx--;

        TmpClientPtr = &TmpEventHandlerPtr->ClientListPtr[ClientIdx];

        if(SD_EVENT_HANDLER_CLIENT_STATE_SUBSCRIBED == TmpClientPtr->ClientState)
        {
          if(SOAD_INV_SO_CON_ID != TmpClientPtr->AssignedUdpSoConId)
          {
            SD_P2VAR(uint8) ActivationCntPtr;
            ActivationCntPtr = Sd_GetActivationCount(TmpEventHandlerPtr->UdpRefPtr, TmpClientPtr->AssignedUdpSoConId);

            if(NULL_PTR != ActivationCntPtr)
            {
              *ActivationCntPtr = 0;
            }

            /* Disable the routing for the unicast SocketConnection */
            (void)SoAd_DisableSpecificRouting(TmpEventHandlerPtr->UdpRefPtr->ActivationRef, TmpClientPtr->AssignedUdpSoConId);
          }
        }
      }

      /* Update the state */
      Sd_UpdateEventHandlerStateMachine(TmpEventHandlerPtr, SD_EVENT_HANDLER_STATE_MULTICAST_SUBSCRIPTION);
    }

    /* Switch back to unicast if this functionality is configured */
    if((SD_EVENT_HANDLER_STATE_MULTICAST_SUBSCRIPTION == TmpEventHandlerPtr->DynamicDataPtr->StateMachine) &&
      (TmpEventHandlerPtr->MulticastThreshold > TmpEventHandlerPtr->DynamicDataPtr->NrOfClientsUdp))
    {
      /* Iterate over all registered clients of a eventgroup in order to enable the unicast routing groups */
      ClientIdx = TmpEventHandlerPtr->MaxNrHandledClients;
      while(0 < ClientIdx)
      {
        ClientIdx--;

        TmpClientPtr = &TmpEventHandlerPtr->ClientListPtr[ClientIdx];

        if(SD_EVENT_HANDLER_CLIENT_STATE_SUBSCRIBED == TmpClientPtr->ClientState)
        {
          if(SOAD_INV_SO_CON_ID != TmpClientPtr->AssignedUdpSoConId)
          {
            /* Enable the unicast routing group and increase the activation counter */
            (void)SoAd_EnableSpecificRouting(TmpEventHandlerPtr->UdpRefPtr->ActivationRef, TmpClientPtr->AssignedUdpSoConId);
            Sd_IncreaseActivationCount(TmpEventHandlerPtr->UdpRefPtr, TmpClientPtr->AssignedUdpSoConId);
          }
        }
      }

      /* Disable the routing for the multicast SocketConnection */
      (void)SoAd_DisableSpecificRouting(TmpEventHandlerPtr->MulticastRefPtr->ActivationRef, TmpEventHandlerPtr->MulticastRefPtr->SoConId);

      /* Update the state */
      Sd_UpdateEventHandlerStateMachine(TmpEventHandlerPtr, SD_EVENT_HANDLER_STATE_UNICAST_SUBSCRIPTION);
    }

    /* Inform the BswM if no client is subscribed anymore */
    if((0 == TmpEventHandlerPtr->DynamicDataPtr->NrOfClients) &&
      ((SD_EVENT_HANDLER_STATE_MULTICAST_SUBSCRIPTION == TmpEventHandlerPtr->DynamicDataPtr->StateMachine) ||
      (SD_EVENT_HANDLER_STATE_UNICAST_SUBSCRIPTION == TmpEventHandlerPtr->DynamicDataPtr->StateMachine)))
    {
      /* Set the state of the event handler to released and inform the BswM. \trace CREQ-121004 */
      Sd_SetValueAndTrigger(TmpEventHandlerPtr->DynamicDataPtr->RequestStateEG, SD_EVENT_HANDLER_RELEASED,
        ServiceInstancePtr->RootInstancePtr);
      BswM_Sd_EventHandlerCurrentState(TmpEventHandlerPtr->EventGroupHandleId, SD_EVENT_HANDLER_RELEASED);

      TmpEventHandlerPtr->DynamicDataPtr->NrOfClientsUdp = 0;

      /* Disable the multicast SocketConnection routing */
      if(SD_EVENT_HANDLER_STATE_MULTICAST_SUBSCRIPTION == TmpEventHandlerPtr->DynamicDataPtr->StateMachine)
      {
        (void)SoAd_DisableRouting(TmpEventHandlerPtr->MulticastRefPtr->ActivationRef);
      }

      /* Disable the UDP unicast SocketConnection routing */
      if(Sd_EventHandlerUsesUdp(TmpEventHandlerPtr))
      {
        (void)SoAd_DisableRouting(TmpEventHandlerPtr->UdpRefPtr->ActivationRef);
        Sd_ResetActivationCount(TmpEventHandlerPtr->UdpRefPtr);
      }

      /* Disable the TCP SocketConnection routing */
      if(Sd_EventHandlerUsesTcp(TmpEventHandlerPtr))
      {
        (void)SoAd_DisableRouting(TmpEventHandlerPtr->TcpRefPtr->ActivationRef);
        Sd_ResetActivationCount(TmpEventHandlerPtr->TcpRefPtr);
      }

      Sd_UpdateEventHandlerStateMachine(TmpEventHandlerPtr, SD_EVENT_HANDLER_STATE_NOT_SUBSCRIBED);
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_RunClientStateMachine()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_RunClientStateMachine(
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr)
{
  Std_ReturnType RetVal = E_OK;
  uint32 EventGroupIdx;
  SD_P2CONST(Sd_ClientServiceType)   TmpClientInstancePtr = ServiceInstancePtr->ClientInstancePtr;
  SD_P2CONST(Sd_ClientTimerType)     TmpTimerPtr = TmpClientInstancePtr->TimerRef;

  switch(TmpClientInstancePtr->DynamicDataPtr->StateMachine)
  {
    case SD_CLIENT_STATE_NONE :
      /* Initial run of the state machine */
      if(SD_CLIENT_SERVICE_REQUESTED != TmpClientInstancePtr->DynamicDataPtr->StateSWC)
      {
        /* Update the state */
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_NOT_REQUESTED_NOT_SEEN, FALSE);
      }
      else if((SD_INSTANCE_UP_AND_CONFIGURED != ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State) /* &&
        (SD_CLIENT_SERVICE_REQUESTED == TmpClientInstancePtr->DynamicDataPtr->StateSWC) */ )
      {
        /* Update the state */
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_REQUESTED_BUT_NOT_READY, FALSE);
      }
      else  /* (SD_CLIENT_SERVICE_REQUESTED == TmpClientInstancePtr->DynamicDataPtr->StateSWC) && */
            /* (SD_INSTANCE_UP_AND_CONFIGURED == ServiceInstancePtr->DynamicDataPtr->State) */
      {
        /* Update the state and reset the TimeToTriggerSend */
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_SEARCHING_INITIAL_WAIT, TRUE);
      }
      break;

    case SD_CLIENT_STATE_NOT_REQUESTED_NOT_SEEN :
      /* If the client received an offer */
      if(SD_CLIENT_EVENT_SERVICE_OFFER == (TmpClientInstancePtr->DynamicDataPtr->Event & 0xF0))
      {
        Sd_SetTimerOffset(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL,
          TmpClientInstancePtr->DynamicDataPtr->OfferedTTL * 1000,
          ServiceInstancePtr->RootInstancePtr);
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_NOT_REQUESTED_SEEN, FALSE);

        /* Reset the event */
        TmpClientInstancePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_NONE;
      }
      break;

    case SD_CLIENT_STATE_NOT_REQUESTED_SEEN :
      /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
      if((SD_INSTANCE_DOWN == ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State) ||
        (TRUE == Sd_CheckIfTimerExceeded(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL, FALSE)) ||
        (SD_CLIENT_EVENT_SERVICE_STOP_OFFER == (TmpClientInstancePtr->DynamicDataPtr->Event & 0xF0)))
      {
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_NOT_REQUESTED_NOT_SEEN, FALSE);
        /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
        Sd_ResetTimerToZeroTrigger(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL, ServiceInstancePtr->RootInstancePtr);
        TmpClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_DOWN;

        /* Check if a StopOffer was received or a reboot detected */
        if(SD_CLIENT_EVENT_SERVICE_STOP_OFFER == TmpClientInstancePtr->DynamicDataPtr->Event)
        {
          /* StopOffer - Reset the event */
          TmpClientInstancePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_NONE;
        }
      }
      else if(SD_CLIENT_EVENT_SERVICE_OFFER == (TmpClientInstancePtr->DynamicDataPtr->Event & 0xF0))
      {
        /* Reset the timer and the event */
        Sd_SetTimerOffset(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL,
          TmpClientInstancePtr->DynamicDataPtr->OfferedTTL * 1000,
          ServiceInstancePtr->RootInstancePtr);
        TmpClientInstancePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_NONE;
      }
      else if((SD_CLIENT_SERVICE_REQUESTED == TmpClientInstancePtr->DynamicDataPtr->StateSWC) &&
        (SD_INSTANCE_UP_AND_CONFIGURED == ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State))
      {
        /* Enter the main phase and inform the BswM. \trace CREQ-121005 */
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_SERVICE_READY, FALSE);
        BswM_Sd_ClientServiceCurrentState(ServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_AVAILABLE);
        TmpClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_AVAILABLE;
      }
      else
      {
        /* No further state transitions available */
      }
      break;

    case SD_CLIENT_STATE_REQUESTED_BUT_NOT_READY :
      if(SD_INSTANCE_UP_AND_CONFIGURED == ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State)
      {
        /* Update the state and reset the TimeToTriggerSend */
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_SEARCHING_INITIAL_WAIT, TRUE);
      }
      break;

    case SD_CLIENT_STATE_SEARCHING_INITIAL_WAIT :
      /* Initial run of the wait phase */
      if(Sd_CheckIfTimerIsInvalid(TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend))
      {
        /* Wind up the timer */
        uint32 AdditionalDelay = Sd_GetRandomNrInRange(TmpTimerPtr->InitialFindDelayMin, TmpTimerPtr->InitialFindDelayMax);
        Sd_SetTimerOffset(TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend,
          AdditionalDelay, ServiceInstancePtr->RootInstancePtr);
      }
      else if(TRUE == Sd_CheckIfTimerExceeded(TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend, TRUE))
      {
        /* Update the state and reset the TimeToTriggerSend */
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_SEARCHING_REPETITION, TRUE);
        TmpClientInstancePtr->DynamicTimerPtr->RepetitionRun = 0;

        /* Send a FindService message */
        Sd_AddFindEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, ServiceInstancePtr);
      }
      else
      {
        /* Timer is not yet expired */
      }
      break;

    case SD_CLIENT_STATE_SEARCHING_REPETITION :
      if((Sd_CheckIfTimerIsInvalid(TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend)) &&
        (0 < TmpTimerPtr->InitialFindRepetitionsMax) && (0 == TmpClientInstancePtr->DynamicTimerPtr->RepetitionRun))
      {
        uint32 initialRepetitionDelay = TmpTimerPtr->InitialFindRepetitionBaseDelay;
        if(SD_MAIN_FCT_CYCLE_TIME_MS <= initialRepetitionDelay)
        {
          initialRepetitionDelay -= SD_MAIN_FCT_CYCLE_TIME_MS;
        }

        /* Wind up the timer */
        Sd_SetTimerOffset(TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend, initialRepetitionDelay,
          ServiceInstancePtr->RootInstancePtr);
      }

      if((TRUE == Sd_CheckIfTimerExceeded(TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend, TRUE)) &&
        (TmpClientInstancePtr->DynamicTimerPtr->RepetitionRun < TmpTimerPtr->InitialFindRepetitionsMax))
      {
        /* Send a FindService message */
        Sd_AddFindEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, ServiceInstancePtr);
        TmpClientInstancePtr->DynamicTimerPtr->RepetitionRun++;

        /* Wind up the timer */
        Sd_SetTimerOffset(TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend,
          (uint32)((uint32)(1 << TmpClientInstancePtr->DynamicTimerPtr->RepetitionRun) * TmpTimerPtr->InitialFindRepetitionBaseDelay),
          ServiceInstancePtr->RootInstancePtr);
      }
      else if(TmpClientInstancePtr->DynamicTimerPtr->RepetitionRun == TmpTimerPtr->InitialFindRepetitionsMax)
      {
        /* End of the searching repetition phase */
        /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
        Sd_ResetTimerToInvalid(TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend);
        TmpClientInstancePtr->DynamicTimerPtr->RepetitionRun++;
      }
      else
      {
        /* Timer is not yet expired */
      }
      break;

    case SD_CLIENT_STATE_SERVICE_READY :
      if(SD_CLIENT_EVENT_SERVICE_STOP_OFFER == (TmpClientInstancePtr->DynamicDataPtr->Event & 0xF0))
      {
        /* Cancel the timer and update state machine */
        /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
        Sd_ResetTimerToZeroTrigger(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL, ServiceInstancePtr->RootInstancePtr);
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_STOPPED, FALSE);

        /* Report the status of the client service. \trace CREQ-121005 */
        BswM_Sd_ClientServiceCurrentState(ServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_DOWN);
        TmpClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_DOWN;

        RetVal |= Sd_UpdateClientServiceSoCons(TmpClientInstancePtr, FALSE);

        /* Check if a StopOffer was received or a reboot detected */
        if(SD_CLIENT_EVENT_SERVICE_STOP_OFFER == TmpClientInstancePtr->DynamicDataPtr->Event)
        {
          /* StopOffer - Reset the event */
          TmpClientInstancePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_NONE;
        }
      }
      else if(SD_CLIENT_EVENT_SERVICE_OFFER == (TmpClientInstancePtr->DynamicDataPtr->Event & 0xF0))
      {
        RetVal |= Sd_UpdateClientServiceSoCons(TmpClientInstancePtr, TRUE);

        if(E_OK == RetVal)
        {
          /* Update the timer */
          Sd_SetTimerOffset(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL,
            TmpClientInstancePtr->DynamicDataPtr->OfferedTTL * 1000,
            ServiceInstancePtr->RootInstancePtr);

          /* The event is not reset because it is needed during processing of the eventgroups */
        }
        else
        {
          /* The server has changed the attached endpoint addresses */

          /* Send a FindService message */
          Sd_AddFindEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, ServiceInstancePtr);

          /* Cancel the timer and reset the event */
          /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
          Sd_ResetTimerToZeroTrigger(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL, ServiceInstancePtr->RootInstancePtr);
          Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_STOPPED, FALSE);
          TmpClientInstancePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_NONE;

          /* Report the status of the client service. \trace CREQ-121005 */
          BswM_Sd_ClientServiceCurrentState(ServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_DOWN);
          TmpClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_DOWN;
        }
      }
      /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
      else if((SOAD_INV_SO_CON_ID != TmpClientInstancePtr->DynamicDataPtr->MethodTcpSoConId) &&
        (SD_SOCON_MODE_LOST_CONNECTION == Sd_GetSoConMode(TmpClientInstancePtr->DynamicDataPtr->MethodTcpSoConId)))
      {
        /* No valid connection, update the configuration */
        RetVal |= Sd_UpdateClientServiceSoCons(TmpClientInstancePtr, TRUE);
      }
      else if(TRUE == Sd_CheckIfTimerExceeded(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL, FALSE))
      {
        RetVal |= Sd_UpdateClientServiceSoCons(TmpClientInstancePtr, FALSE);

        /* Update the state and reset the TimeToTriggerSend */
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_SEARCHING_INITIAL_WAIT, TRUE);
        /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
        Sd_ResetTimerToZeroTrigger(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL, ServiceInstancePtr->RootInstancePtr);

        /* Report the status of the client service. \trace CREQ-121005 */
        BswM_Sd_ClientServiceCurrentState(ServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_DOWN);
        TmpClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_DOWN;
      }
      else
      {
        /* Timer is not yet expired */
      }
      break;

    case SD_CLIENT_STATE_STOPPED :
      if(SD_CLIENT_EVENT_SERVICE_OFFER == (TmpClientInstancePtr->DynamicDataPtr->Event & 0xF0))
      {
        /* Update the timer and the event */
        Sd_SetTimerOffset(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL,
          TmpClientInstancePtr->DynamicDataPtr->OfferedTTL * 1000,
          ServiceInstancePtr->RootInstancePtr);
        TmpClientInstancePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_NONE;

        RetVal |= Sd_UpdateClientServiceSoCons(TmpClientInstancePtr, TRUE);

        if(E_OK == RetVal)
        {
          /* Enter the main phase and inform the BswM. \trace CREQ-121005 */
          Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_SERVICE_READY, FALSE);
          BswM_Sd_ClientServiceCurrentState(ServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_AVAILABLE);
          TmpClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_AVAILABLE;
        }
      }

      /* Change the state if the connection is lost */
      if(SD_INSTANCE_UP_AND_CONFIGURED != ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State)
      {
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_REQUESTED_BUT_NOT_READY, FALSE);
      }
      break;

    default:
      /* Undefined state */
      break;
  }

  /* Condition to leave the "Not Requested" block */
  if(((SD_CLIENT_STATE_NOT_REQUESTED_NOT_SEEN == TmpClientInstancePtr->DynamicDataPtr->StateMachine) ||
    (SD_CLIENT_STATE_NOT_REQUESTED_SEEN == TmpClientInstancePtr->DynamicDataPtr->StateMachine)) &&
    (SD_CLIENT_SERVICE_REQUESTED == TmpClientInstancePtr->DynamicDataPtr->StateSWC))
  {
    if(SD_INSTANCE_UP_AND_CONFIGURED != ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State)
    {
      /* Update the state */
      Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_REQUESTED_BUT_NOT_READY, FALSE);
    }
    else
    {
      /* Update the state and reset the TimeToTriggerSend */
      Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_SEARCHING_INITIAL_WAIT, TRUE);
    }
  }

  /* Condition to leave the "Search for Service" block */
  if((SD_CLIENT_STATE_SEARCHING_INITIAL_WAIT == TmpClientInstancePtr->DynamicDataPtr->StateMachine) ||
    (SD_CLIENT_STATE_SEARCHING_REPETITION == TmpClientInstancePtr->DynamicDataPtr->StateMachine))
  {
    if(!Sd_CheckIfTimerIsZero(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL))
    {
      /* Reset the TTL */
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Sd_ResetTimerToZeroTrigger(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL, ServiceInstancePtr->RootInstancePtr);
    }

    if(SD_INSTANCE_UP_AND_CONFIGURED != ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State)
    {
      /* Update the state and reset the TimeToTriggerSend */
      Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_REQUESTED_BUT_NOT_READY, TRUE);

      /* Inform the BswM about the change of the client service instance and all associated eventgroups. \trace CREQ-121005, CREQ-121006 */
      BswM_Sd_ClientServiceCurrentState(ServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_DOWN);
      TmpClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_DOWN;
      EventGroupIdx = TmpClientInstancePtr->NrOfEventGroups;
      while(0 < EventGroupIdx)
      {
        EventGroupIdx--;
        BswM_Sd_ConsumedEventGroupCurrentState(TmpClientInstancePtr->EventGroupPtrPtr[EventGroupIdx]->EventGroupHandleId,
          SD_CONSUMED_EVENTGROUP_DOWN);
      }
    }

    if(SD_CLIENT_SERVICE_RELEASED == TmpClientInstancePtr->DynamicDataPtr->StateSWC)
    {
      /* The Client Service is not requested, change the state */
      Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_NOT_REQUESTED_NOT_SEEN, FALSE);
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Sd_ResetTimerToInvalid(TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend);
    }

    if(SD_CLIENT_EVENT_SERVICE_OFFER == (TmpClientInstancePtr->DynamicDataPtr->Event & 0xF0))
    {
      if(TmpClientInstancePtr->TimerRef->TTL > TmpClientInstancePtr->DynamicDataPtr->OfferedTTL)
      {
        Sd_SetTimerOffset(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL,
          TmpClientInstancePtr->DynamicDataPtr->OfferedTTL * 1000,
          ServiceInstancePtr->RootInstancePtr);
      }
      else
      {
        Sd_SetTimerOffset(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL,
          TmpClientInstancePtr->TimerRef->TTL * 1000,
          ServiceInstancePtr->RootInstancePtr);
      }

      RetVal |= Sd_UpdateClientServiceSoCons(TmpClientInstancePtr, TRUE);

      if(E_OK == RetVal)
      {
        /* Enter the main phase and inform the BswM. \trace CREQ-121005 */
        Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_SERVICE_READY, TRUE);
        BswM_Sd_ClientServiceCurrentState(ServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_AVAILABLE);
        TmpClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_AVAILABLE;

        /* The event is not reset because it is needed during processing of the eventgroups */
      }
    }
  }

  /* Run the state machine, handling all consumed eventgroups of the client instance */
  Sd_RunConsumedEventGroupStateMachine(ServiceInstancePtr);

  /* A reboot was detected, update the event */
  if(SD_CLIENT_EVENT_SERVICE_STOP_OFFER_OFFER_MULTI == TmpClientInstancePtr->DynamicDataPtr->Event)
  {
    Sd_SetValueAndTrigger(TmpClientInstancePtr->DynamicDataPtr->Event, SD_CLIENT_EVENT_SERVICE_OFFER_MULTI,
      ServiceInstancePtr->RootInstancePtr);
  }
  else if(SD_CLIENT_EVENT_SERVICE_STOP_OFFER_OFFER_UNI == TmpClientInstancePtr->DynamicDataPtr->Event)
  {
    Sd_SetValueAndTrigger(TmpClientInstancePtr->DynamicDataPtr->Event, SD_CLIENT_EVENT_SERVICE_OFFER_UNI,
      ServiceInstancePtr->RootInstancePtr);
  }
  else
  {
    /* Reset the event */
    TmpClientInstancePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_NONE;
  }

  /* If the client service instance is not requested anymore */
  if((SD_CLIENT_SERVICE_RELEASED == TmpClientInstancePtr->DynamicDataPtr->StateSWC) &&
    ((SD_CLIENT_STATE_REQUESTED_BUT_NOT_READY == TmpClientInstancePtr->DynamicDataPtr->StateMachine) ||
    (SD_CLIENT_STATE_SERVICE_READY == TmpClientInstancePtr->DynamicDataPtr->StateMachine) ||
    (SD_CLIENT_STATE_STOPPED == TmpClientInstancePtr->DynamicDataPtr->StateMachine)))
  {
    /* Check if there are pending SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP messages */
    /* Transmit the messages before the connections are reset (the endpoints become invalid) */
    uint16 SendEntryIdx;
    SendEntryIdx = ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr->NrOfSendEntries;
    while(0 < SendEntryIdx)
    {
      SendEntryIdx--;

      if(SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP == ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr->SendEntryPtr[SendEntryIdx].EntryType)
      {
        Sd_ProcessPendingMessages(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, TRUE);
        break;
      }
    }

    /* Enter the down phase and indicate the state. \trace CREQ-121005 */
    ServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_DOWN;
    if(SD_CLIENT_STATE_SERVICE_READY == TmpClientInstancePtr->DynamicDataPtr->StateMachine)
    {
      BswM_Sd_ClientServiceCurrentState(ServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_DOWN);
    }

    /* The Client Service is not requested, change the state */
    Sd_UpdateClientStateMachine(TmpClientInstancePtr, SD_CLIENT_STATE_NOT_REQUESTED_NOT_SEEN, FALSE);
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Sd_ResetTimerToZeroTrigger(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL, ServiceInstancePtr->RootInstancePtr);

    (void)Sd_UpdateClientServiceSoCons(TmpClientInstancePtr, FALSE);
  }

  /* Update the time for the next state machine run */
  if(!Sd_CheckIfTimerIsZero(TmpClientInstancePtr->DynamicTimerPtr->TimerTTL))
  {
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Sd_SetNextStateMachineRun(ServiceInstancePtr->RootInstancePtr, TmpClientInstancePtr->DynamicTimerPtr->TimerTTL);
  }
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_SetNextStateMachineRun(ServiceInstancePtr->RootInstancePtr, TmpClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend);
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_RunConsumedEventGroupStateMachine()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_RunConsumedEventGroupStateMachine(
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr)
{
  Std_ReturnType RetVal = E_OK;
  uint32 EventGroupIdx;
  uint32 RandDelay;
  SD_P2CONST(Sd_ClientServiceType) TmpClientInstancePtr = ServiceInstancePtr->ClientInstancePtr;
  SD_P2CONST(Sd_ConsumedEventGroupType) TmpEventGroupPtr;

  /* Handle all eventgroups of the client service instance */
  EventGroupIdx = TmpClientInstancePtr->NrOfEventGroups;
  while(0 < EventGroupIdx)
  {
    EventGroupIdx--;

    TmpEventGroupPtr = TmpClientInstancePtr->EventGroupPtrPtr[EventGroupIdx];

    /* Handle the eventgroup only if the service is ready and the eventgroup is requested */
    if(SD_CLIENT_STATE_SERVICE_READY == TmpClientInstancePtr->DynamicDataPtr->StateMachine)
    {
      switch(TmpEventGroupPtr->DynamicDataPtr->StateMachine)
      {
        case SD_CONSUMED_EVENTGROUP_STATE_UNSUBSCRIBED :
          if(SD_CONSUMED_EVENTGROUP_REQUESTED == TmpEventGroupPtr->DynamicDataPtr->ServiceModeRequest)
          {
            RetVal = Sd_UpdateClientServiceEventGroupSoCons(TmpEventGroupPtr, FALSE);

            if(E_OK == RetVal)
            {
              /* Check if the OfferMessage was transmitted by multicast or unicast */
              if(SD_CLIENT_EVENT_SERVICE_OFFER_MULTI == TmpClientInstancePtr->DynamicDataPtr->Event)
              {
                /* Calculate a random delay after which the response message will be transmitted */
                RandDelay = Sd_GetRandomNrInRangeForResponse(TmpEventGroupPtr->TimerRef->RequestResponseMinDelay,
                  TmpEventGroupPtr->TimerRef->RequestResponseMaxDelay, FALSE);
                Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_MULTI_OFFER);
              }
              else
              {
                RandDelay = 0;
                Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT);
              }

              /* Send a subscribe eventgroup message */
              Sd_AddSubscribeEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, TmpEventGroupPtr,
                TRUE, RandDelay);

              /* Enable the unicast PDU routings in order to prevent the race condition discussed in RFC 68309 */
              if(SOAD_INV_SO_CON_ID != TmpEventGroupPtr->DynamicDataPtr->TcpSoConId)
              {
                RetVal |= SoAd_EnableSpecificRouting(TmpEventGroupPtr->TcpActRef, TmpEventGroupPtr->DynamicDataPtr->TcpSoConId);
              }
              if(SOAD_INV_SO_CON_ID != TmpEventGroupPtr->DynamicDataPtr->UdpSoConId)
              {
                RetVal |= SoAd_EnableSpecificRouting(TmpEventGroupPtr->UdpActRef, TmpEventGroupPtr->DynamicDataPtr->UdpSoConId);
              }

              /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
              Sd_ResetTimerToZeroTrigger(TmpEventGroupPtr->DynamicDataPtr->TimerTTL, ServiceInstancePtr->RootInstancePtr);
            }
          }
          break;

        case SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT :
        case SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_MULTI_OFFER :
        case SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_RETRY :
          if(SD_CLIENT_EVENT_EVENTGROUP_ACK == TmpEventGroupPtr->DynamicDataPtr->Event)
          {
            /* The server acknowledged the subscription, update the socket connections */
            RetVal = Sd_UpdateClientServiceEventGroupSoCons(TmpEventGroupPtr, TRUE);

            if(E_OK == RetVal)
            {
              /* If the eventgroup was subscribed the first time */
              if(Sd_CheckIfTimerIsZero(TmpEventGroupPtr->DynamicDataPtr->TimerTTL))
              {
                /* Inform the BswM. \trace CREQ-121006 */
                BswM_Sd_ConsumedEventGroupCurrentState(TmpEventGroupPtr->EventGroupHandleId, SD_CONSUMED_EVENTGROUP_AVAILABLE);
                TmpEventGroupPtr->DynamicDataPtr->CurrentState = SD_CONSUMED_EVENTGROUP_AVAILABLE;
              }

              /* Start the timers, update the state and reset the event */
              Sd_SetTimerOffset(TmpEventGroupPtr->DynamicDataPtr->TimerTTL,
                TmpEventGroupPtr->DynamicDataPtr->AcknowledgedTTL * 1000,
                ServiceInstancePtr->RootInstancePtr);
              Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_SUBSCRIBED);
              TmpEventGroupPtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_EVENTGROUP_NONE;
            }
            else
            {
              /* The multicast SocketConnection could not be configured. \trace CREQ-121006 */
              BswM_Sd_ConsumedEventGroupCurrentState(TmpEventGroupPtr->EventGroupHandleId, SD_CONSUMED_EVENTGROUP_DOWN);
              if(SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_RETRY != TmpEventGroupPtr->DynamicDataPtr->StateMachine)
              {
                /* If the multicast endpoint was changed, the Sd will try to configure it in the next cycle */
                /* The SD_CLIENT_EVENT_EVENTGROUP_ACK event is not removed */
                Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_RETRY);
              }
              else
              {
                /* Inform the BswM and update the state */
                Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_UNSUBSCRIBED);
                TmpEventGroupPtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_EVENTGROUP_NONE;
              }
            }
          }
          else if(SD_CLIENT_EVENT_SERVICE_OFFER == (TmpClientInstancePtr->DynamicDataPtr->Event & 0xF0))
          {
            /* Check if the previous subscribe message is already transmitted, or still pending because of a missing TCP connection */
            if(TRUE == Sd_EntryListContainsSubscribe(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, TmpEventGroupPtr))
            {
              /* There is already a SubscribeEventgroup message pending. */
              /* Do not trigger the StopSubscribeEventgroup - SubscribeEventgroup message */
            }
            /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
            else if((SOAD_INV_SO_CON_ID != TmpEventGroupPtr->DynamicDataPtr->TcpSoConId) &&
              (SD_SOCON_MODE_ONLINE != Sd_GetSoConMode(TmpEventGroupPtr->DynamicDataPtr->TcpSoConId)))
            {
              /* The TCP connection is not established. Do not respond to the offer message */
            }
            else
            {
              /* Check if the OfferMessage was transmitted by multicast or unicast */
              if(SD_CLIENT_EVENT_SERVICE_OFFER_MULTI == TmpClientInstancePtr->DynamicDataPtr->Event)
              {
                /* Add a random delay to the response message */
                RandDelay = Sd_GetRandomNrInRangeForResponse(TmpEventGroupPtr->TimerRef->RequestResponseMinDelay,
                  TmpEventGroupPtr->TimerRef->RequestResponseMaxDelay, FALSE);

                /* PRQA S 0715 2 */ /* MD_MSR_1.1_0715 */
                if(SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_MULTI_OFFER == TmpEventGroupPtr->DynamicDataPtr->StateMachine)
                {
                  /* Send out a StopSubscribeEventgroup followed by a SubscribeEventgroup */
                  Sd_AddSubscribeEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, TmpEventGroupPtr,
                    FALSE, RandDelay);
                }

                Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_MULTI_OFFER);
              }
              else  /* SD_CLIENT_EVENT_SERVICE_OFFER_UNI == TmpClientInstancePtr->DynamicDataPtr->Event */
              {
                /* The response can be transmitted without additional delay */
                RandDelay = 0;
                Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT);
              }

              /* Send out a SubscribeEventgroup */
              Sd_AddSubscribeEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, TmpEventGroupPtr,
                TRUE, RandDelay);
            }
          }
          else
          {
            /* Timer is not yet expired */
          }
          break;

        case SD_CONSUMED_EVENTGROUP_STATE_SUBSCRIBED :
          /* Send a subscribeEventgroup message if a offerService was received */
          if(SD_CLIENT_EVENT_SERVICE_OFFER == (TmpClientInstancePtr->DynamicDataPtr->Event & 0xF0))
          {
            /* Check if the OfferMessage was transmitted by multicast or unicast */
            if(SD_CLIENT_EVENT_SERVICE_OFFER_MULTI == TmpClientInstancePtr->DynamicDataPtr->Event)
            {
              /* Calculate a random delay after which the response message will be transmitted */
              RandDelay = Sd_GetRandomNrInRangeForResponse(TmpEventGroupPtr->TimerRef->RequestResponseMinDelay,
                TmpEventGroupPtr->TimerRef->RequestResponseMaxDelay, FALSE);
              Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_MULTI_OFFER);
            }
            else  /* SD_CLIENT_EVENT_SERVICE_OFFER_UNI == TmpClientInstancePtr->DynamicDataPtr->Event */
            {
              /* Subscribe messages based on a unicast offer are not delayed */
              RandDelay = 0;
              Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT);
            }

            /* Send a subscribe eventgroup message and init the mechanism waiting for the ACK */
            Sd_AddSubscribeEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr,
              TmpEventGroupPtr, TRUE, RandDelay);
          }
          else if(SD_CLIENT_SERVICE_RELEASED == TmpClientInstancePtr->DynamicDataPtr->StateSWC)
          {
            /* Send a StopSubscribe message and inform the BswM. \trace CREQ-121006 */
            Sd_AddSubscribeEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr,
              TmpEventGroupPtr, FALSE, 0);
            BswM_Sd_ConsumedEventGroupCurrentState(TmpEventGroupPtr->EventGroupHandleId, SD_CONSUMED_EVENTGROUP_DOWN);
            TmpEventGroupPtr->DynamicDataPtr->CurrentState = SD_CONSUMED_EVENTGROUP_DOWN;
          }
          /* PRQA S 3415 3 */ /* MD_Sd_12.4_3415 */
          else if((SOAD_INV_SO_CON_ID != TmpEventGroupPtr->DynamicDataPtr->TcpSoConId) &&
            (SD_SOCON_MODE_LOST_CONNECTION == Sd_GetSoConMode(TmpEventGroupPtr->DynamicDataPtr->TcpSoConId)))
          {
            /* No valid connection, update the configuration and inform the BswM. \trace CREQ-121006 */
            RetVal |= Sd_UpdateClientServiceEventGroupSoCons(TmpEventGroupPtr, FALSE);
            BswM_Sd_ConsumedEventGroupCurrentState(TmpEventGroupPtr->EventGroupHandleId, SD_CONSUMED_EVENTGROUP_DOWN);
            TmpEventGroupPtr->DynamicDataPtr->CurrentState = SD_CONSUMED_EVENTGROUP_DOWN;
            Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_UNSUBSCRIBED);
          }
          else
          {
            /* Timer is not yet expired */
          }
          break;

        default:
            /* Undefined state */
          break;
      }

      /* Check if the TTL expired or the eventgroup was set from requested to released */
      /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
      if(((TRUE == Sd_CheckIfTimerExceeded(TmpEventGroupPtr->DynamicDataPtr->TimerTTL, FALSE)) &&
        (!Sd_CheckIfTimerIsZero(TmpEventGroupPtr->DynamicDataPtr->TimerTTL)) &&
        (SD_CONSUMED_EVENTGROUP_STATE_UNSUBSCRIBED != TmpEventGroupPtr->DynamicDataPtr->StateMachine)) ||
        ((SD_CONSUMED_EVENTGROUP_AVAILABLE == TmpEventGroupPtr->DynamicDataPtr->CurrentState) &&
        (SD_CONSUMED_EVENTGROUP_RELEASED == TmpEventGroupPtr->DynamicDataPtr->ServiceModeRequest)) ||
        (SD_CLIENT_EVENT_EVENTGROUP_NACK == TmpEventGroupPtr->DynamicDataPtr->Event))
      {
        /* Disable the SoAd RoutingGroup(s) */
        if(SOAD_INV_SO_CON_ID != TmpEventGroupPtr->DynamicDataPtr->TcpSoConId)
        {
          RetVal |= SoAd_DisableRouting(TmpEventGroupPtr->TcpActRef);
        }
        if(SOAD_INV_SO_CON_ID != TmpEventGroupPtr->DynamicDataPtr->UdpSoConId)
        {
          RetVal |= SoAd_DisableRouting(TmpEventGroupPtr->UdpActRef);
        }
        if(SOAD_INV_SO_CON_ID != TmpEventGroupPtr->DynamicDataPtr->MulticastSoConId)
        {
          RetVal |= SoAd_DisableRouting(TmpEventGroupPtr->MulticastActRef);

          /* Release the multicast IP Address configuration */
          if(SOAD_INV_SO_CON_ID != TmpEventGroupPtr->DynamicDataPtr->MulticastSoConId)
          {
            RetVal |= Sd_ReleaseIpAddrAssignment(TmpEventGroupPtr->DynamicDataPtr->MulticastSoConId);
            RetVal |= SoAd_CloseSoCon(TmpEventGroupPtr->DynamicDataPtr->MulticastSoConId, FALSE);
            TmpEventGroupPtr->DynamicDataPtr->MulticastSoConId = SOAD_INV_SO_CON_ID;
          }
        }

        if((SD_CONSUMED_EVENTGROUP_AVAILABLE == TmpEventGroupPtr->DynamicDataPtr->CurrentState) &&
        (SD_CONSUMED_EVENTGROUP_RELEASED == TmpEventGroupPtr->DynamicDataPtr->ServiceModeRequest))
        {
          /* The eventgroup was set from requested to released, send a StopSubscribe message */
          Sd_AddSubscribeEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, TmpEventGroupPtr, FALSE, 0);
        }
        else
        {
          /* Inform the BswM. \trace CREQ-121006 */
          BswM_Sd_ConsumedEventGroupCurrentState(TmpEventGroupPtr->EventGroupHandleId, SD_CONSUMED_EVENTGROUP_DOWN);

          if(SD_CLIENT_EVENT_EVENTGROUP_NACK == TmpEventGroupPtr->DynamicDataPtr->Event)
          {
            /* Report DEM if a NACK was received. \trace CREQ-121019 */
            Sd_DemNackReceived(ServiceInstancePtr->RootInstancePtr->ENackRecvId); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            TmpEventGroupPtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_EVENTGROUP_NONE;
          }
        }

        /* Reset the state of the eventgroup */
        Sd_UpdateConsumedEventGroupStateMachine(TmpEventGroupPtr, SD_CONSUMED_EVENTGROUP_STATE_UNSUBSCRIBED);
        TmpEventGroupPtr->DynamicDataPtr->CurrentState = SD_CONSUMED_EVENTGROUP_DOWN;
      }
    }
    else
    {
      /* The service instance is not ready. Reset the state of the eventgroup. Do not trigger the state machine execution */
      TmpEventGroupPtr->DynamicDataPtr->StateMachine = SD_CONSUMED_EVENTGROUP_STATE_UNSUBSCRIBED;
      TmpEventGroupPtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_EVENTGROUP_NONE;

      /* Report the state of all consumed eventgroups if the service was changed to down. \trace CREQ-121006 */
      if(!Sd_CheckIfTimerIsZero(TmpEventGroupPtr->DynamicDataPtr->TimerTTL))
      {
        if(SD_CONSUMED_EVENTGROUP_DOWN != TmpEventGroupPtr->DynamicDataPtr->CurrentState)
        {
          BswM_Sd_ConsumedEventGroupCurrentState(TmpEventGroupPtr->EventGroupHandleId, SD_CONSUMED_EVENTGROUP_DOWN);
          TmpEventGroupPtr->DynamicDataPtr->CurrentState = SD_CONSUMED_EVENTGROUP_DOWN;
        }

        /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
        Sd_ResetTimerToZeroTrigger(TmpEventGroupPtr->DynamicDataPtr->TimerTTL, ServiceInstancePtr->RootInstancePtr);
      }
    }

    if(!Sd_CheckIfTimerIsZero(TmpEventGroupPtr->DynamicDataPtr->TimerTTL))
    {
      /* Update the time for the next state machine run */
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Sd_SetNextStateMachineRun(ServiceInstancePtr->RootInstancePtr, TmpEventGroupPtr->DynamicDataPtr->TimerTTL);
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_ServerServiceSetState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(Std_ReturnType, SD_CODE) Sd_ServerServiceSetState(
  uint16 SdServerServiceHandleId,
  Sd_ServerServiceSetStateType ServerServiceState)
{
  Std_ReturnType RetVal = E_NOT_OK;
  SD_P2CONST(Sd_ServiceInstanceType) TmpServiceInstancePtr;
  SD_P2CONST(Sd_EventHandlerType) TmpEventHandlerPtr;
  uint16 EventHandlerIdx, ReferenceIdx;

  /* Det checks */
  /* PRQA S 3109 6 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnValue(!(SD_STATE_UNINIT == Sd_State), SD_API_ID_SERVER_SERVICE_SET_STATE, SD_E_NOT_INITIALIZED, E_NOT_OK);
  /* PRQA S 3201 4 */ /* MD_MSR_14.1 */
  /* PRQA S 3355,3356,3359 3 */ /* MD_Sd_13.7 */
  Sd_CheckDetErrorReturnValue(
    !((SD_SERVER_SERVICE_DOWN != ServerServiceState) && (SD_SERVER_SERVICE_AVAILABLE != ServerServiceState)),
    SD_API_ID_SERVER_SERVICE_SET_STATE, SD_E_INV_MODE, E_NOT_OK);

  /* Check if the SdServerServiceHandleId is valid */
  if((Sd_ConfigPtr->ServerServiceHandleIdMapSize > SdServerServiceHandleId) &&
    (NULL_PTR != Sd_ConfigPtr->ServerServiceHandleIdMapPtr[SdServerServiceHandleId]))
  {
    /* Get the corresponding service instance */
    TmpServiceInstancePtr = Sd_ConfigPtr->ServerServiceHandleIdMapPtr[SdServerServiceHandleId];

    /* Check if the service instance is a server instance */
    if(NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr)
    {
      /* Check if the server is shut down while being in initial wait or repetition phase */
      if(SD_SERVER_SERVICE_AVAILABLE != ServerServiceState)
      {
        /* Set the state of all associated EventHandlers */
        EventHandlerIdx = TmpServiceInstancePtr->ServerInstancePtr->NrOfEventHandlers;
        while(0 < EventHandlerIdx)
        {
          EventHandlerIdx--;

          TmpEventHandlerPtr = &TmpServiceInstancePtr->ServerInstancePtr->EventHandlerPtr[EventHandlerIdx];

          if(SD_EVENT_HANDLER_REQUESTED == TmpEventHandlerPtr->DynamicDataPtr->RequestStateEG)
          {
            Sd_SetValueAndTrigger(TmpEventHandlerPtr->DynamicDataPtr->RequestStateEG,
              SD_EVENT_HANDLER_RELEASED, TmpServiceInstancePtr->RootInstancePtr);

            /* Inform the BswM. \trace CREQ-121004 */
            BswM_Sd_EventHandlerCurrentState(TmpEventHandlerPtr->EventGroupHandleId,
              SD_EVENT_HANDLER_RELEASED);
          }

          /* Clear the list of clients */
          ReferenceIdx = TmpEventHandlerPtr->MaxNrHandledClients;
          while(0 < ReferenceIdx)
          {
            ReferenceIdx--;

            if(SD_EVENT_HANDLER_CLIENT_STATE_INVALID !=
              TmpEventHandlerPtr->ClientListPtr[ReferenceIdx].ClientState)
            {
              Sd_RemoveClientFromList(&TmpServiceInstancePtr->ServerInstancePtr->EventHandlerPtr[EventHandlerIdx],
                &TmpEventHandlerPtr->ClientListPtr[ReferenceIdx]);
            }
          }

          /* Disable all referenced routing groups and reset the SoCons */
          if(Sd_EventHandlerUsesMulticast(TmpEventHandlerPtr))
          {
            (void)SoAd_DisableRouting(TmpEventHandlerPtr->MulticastRefPtr->ActivationRef);
            (void)SoAd_CloseSoCon(TmpEventHandlerPtr->MulticastRefPtr->SoConId, FALSE);
          }

          if(Sd_EventHandlerUsesTcp(TmpEventHandlerPtr))
          {
            (void)SoAd_DisableRouting(TmpEventHandlerPtr->TcpRefPtr->ActivationRef);
            Sd_ResetActivationCount(TmpEventHandlerPtr->TcpRefPtr);
            /* The TCP SocketConnections will be closed at once afterwards */
          }

          if(Sd_EventHandlerUsesUdp(TmpEventHandlerPtr))
          {
            (void)SoAd_DisableRouting(TmpEventHandlerPtr->UdpRefPtr->ActivationRef);
            Sd_ResetActivationCount(TmpEventHandlerPtr->UdpRefPtr);
            /* The UDP SocketConnections will be closed afterwards */
          }
        }

        /* Close all TCP SocketConnections of the ServerService */
        if(NULL_PTR != TmpServiceInstancePtr->TcpSoConListPtr)
        {
          ReferenceIdx = TmpServiceInstancePtr->TcpSoConListSize;
          while(0 < ReferenceIdx)
          {
            ReferenceIdx--;

            (void)SoAd_CloseSoCon(TmpServiceInstancePtr->TcpSoConListPtr[ReferenceIdx], FALSE);
          }
        }

        /* Disable the routing group for the server methods */
        if(NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr->ProvidedMethodPtr)
        {
          (void)SoAd_DisableRouting(TmpServiceInstancePtr->ServerInstancePtr->ProvidedMethodPtr->ActivationRef);
        }
      }

      /* Found the corresponding Server Service Instance -> Update the state */
      Sd_SetValueAndTrigger(TmpServiceInstancePtr->ServerInstancePtr->DynamicDataPtr->StateSWC, ServerServiceState,
        TmpServiceInstancePtr->RootInstancePtr);
      RetVal = E_OK;
    }
  }

  /* Raise error if SdServerServiceHandleId has an invalid (unknown) value */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnValue(!(E_NOT_OK == RetVal), SD_API_ID_SERVER_SERVICE_SET_STATE, SD_E_INV_ID, E_NOT_OK);

  return RetVal;

} /* PRQA S 2006, 6010, 6030, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_ClientServiceSetState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(Std_ReturnType, SD_CODE) Sd_ClientServiceSetState(
  uint16 ClientServiceHandleId,
  Sd_ClientServiceSetStateType ClientServiceState)
{
  Std_ReturnType RetVal = E_NOT_OK;
  SD_P2CONST(Sd_ServiceInstanceType) TmpServiceInstancePtr;
  SD_P2CONST(Sd_ClientServiceType) TmpClientServicePtr;
  uint16 EventGroupIdx;

  /* Det checks */
  /* PRQA S 3109 6 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnValue(!(SD_STATE_UNINIT == Sd_State), SD_API_ID_CLIENT_SERVICE_SET_STATE, SD_E_NOT_INITIALIZED, E_NOT_OK);
  /* PRQA S 3201 4 */ /* MD_MSR_14.1 */
  /* PRQA S 3355,3356,3359 3 */ /* MD_Sd_13.7 */
  Sd_CheckDetErrorReturnValue(
    !((SD_CLIENT_SERVICE_RELEASED != ClientServiceState) && (SD_CLIENT_SERVICE_REQUESTED != ClientServiceState)),
    SD_API_ID_SERVER_SERVICE_SET_STATE, SD_E_INV_MODE, E_NOT_OK);

  /* Check if the ClientServiceHandleId is valid */
  if((Sd_ConfigPtr->ClientServiceHandleIdMapSize > ClientServiceHandleId) &&
    (NULL_PTR != Sd_ConfigPtr->ClientServiceHandleIdMapPtr[ClientServiceHandleId]))
  {
    /* Get the corresponding service instance */
    TmpServiceInstancePtr = Sd_ConfigPtr->ClientServiceHandleIdMapPtr[ClientServiceHandleId];

    /* Check if the service instance is a client instance */
    if(NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr)
    {
      /* Found the corresponding Client Service Instance */
      TmpClientServicePtr = TmpServiceInstancePtr->ClientInstancePtr;
      RetVal = E_OK;

      if((SD_CLIENT_SERVICE_REQUESTED == ClientServiceState) && (SD_CLIENT_SERVICE_RELEASED == TmpClientServicePtr->DynamicDataPtr->StateSWC))
      {
        if(TRUE == Sd_CheckIfTimerExceeded(TmpClientServicePtr->DynamicTimerPtr->TimerTTL, FALSE))
        {
          /* Update the state and reset the TimeToTriggerSend */
          Sd_UpdateClientStateMachine(TmpClientServicePtr, SD_CLIENT_STATE_SEARCHING_INITIAL_WAIT, TRUE);
        }
        else
        {
          /* Check if the ClientService is configured for consumed methods */
          if((NULL_PTR != TmpClientServicePtr->MethodPtr) &&
            ((TRUE == TmpClientServicePtr->MethodPtr->TcpConfigured) || (TRUE == TmpClientServicePtr->MethodPtr->UdpConfigured)))
          {
            RetVal |= Sd_UpdateClientServiceSoCons(TmpClientServicePtr, TRUE);
          }

          if(E_OK == RetVal)
          {
            /* Enter the main phase and inform the BswM. \trace CREQ-121005 */
            Sd_UpdateClientStateMachine(TmpClientServicePtr, SD_CLIENT_STATE_SERVICE_READY, FALSE);
            BswM_Sd_ClientServiceCurrentState(TmpServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_AVAILABLE);
            TmpClientServicePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_AVAILABLE;
          }
        }
      }
      else if(SD_CLIENT_SERVICE_RELEASED == ClientServiceState)
      {
        /* Check if the ClientService is configured for consumed methods */
        if((NULL_PTR != TmpClientServicePtr->MethodPtr) &&
          ((TRUE == TmpClientServicePtr->MethodPtr->TcpConfigured) || (TRUE == TmpClientServicePtr->MethodPtr->UdpConfigured)))
        {
          RetVal |= SoAd_DisableRouting(TmpClientServicePtr->MethodPtr->ActivationRef);

          if(SOAD_INV_SO_CON_ID != TmpClientServicePtr->DynamicDataPtr->MethodTcpSoConId)
          {
            /* Unconfigure the ClientService for consumed methods */
            RetVal |= SoAd_CloseSoCon(TmpClientServicePtr->DynamicDataPtr->MethodTcpSoConId, FALSE);
            TmpClientServicePtr->DynamicDataPtr->MethodTcpSoConId = SOAD_INV_SO_CON_ID;
          }

          if(SOAD_INV_SO_CON_ID != TmpClientServicePtr->DynamicDataPtr->MethodUdpSoConId)
          {
            /* Unconfigure the ClientService for consumed methods */
            RetVal |= SoAd_CloseSoCon(TmpClientServicePtr->DynamicDataPtr->MethodUdpSoConId, FALSE);
            TmpClientServicePtr->DynamicDataPtr->MethodUdpSoConId = SOAD_INV_SO_CON_ID;
          }
        }

        /* Pass the RELEASED state to all eventgroups */
        EventGroupIdx = TmpClientServicePtr->NrOfEventGroups;
        while(0 < EventGroupIdx)
        {
          EventGroupIdx--;
          RetVal |= Sd_ConsumedEventGroupSetState(TmpClientServicePtr->EventGroupPtrPtr[EventGroupIdx]->EventGroupHandleId,
            SD_CONSUMED_EVENTGROUP_RELEASED);
        }
      }
      else
      {
        /* Nothing to do */
      }

      /* Update the state */
      Sd_SetValueAndTrigger(TmpClientServicePtr->DynamicDataPtr->StateSWC, ClientServiceState,
        TmpServiceInstancePtr->RootInstancePtr);
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Sd_ResetTimerToInvalid(TmpClientServicePtr->DynamicTimerPtr->TimeToTriggerSend);
      RetVal = E_OK;
    }
  }

  /* Raise error if ClientServiceInstanceID has an invalid (unknown) value */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnValue(!(E_NOT_OK == RetVal), SD_API_ID_CLIENT_SERVICE_SET_STATE, SD_E_INV_ID, E_NOT_OK);

  return RetVal;

} /* PRQA S 2006, 6010, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_ConsumedEventGroupSetState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(Std_ReturnType, SD_CODE) Sd_ConsumedEventGroupSetState(
  uint16 SdConsumedEventGroupHandleId,
  Sd_ConsumedEventGroupSetStateType ConsumedEventGroupState)
{
  Std_ReturnType RetVal = E_NOT_OK;
  SD_P2CONST(Sd_ConsumedEventGroupType) TmpConsumedEventGroupPtr;
#if (STD_ON == SD_DEV_ERROR_DETECT)
  boolean InvalidId = TRUE;
#endif

  /* Det checks */
  /* PRQA S 3109 8 */ /* MD_MSR_14.3 */
  /* Return if Service Discovery is not initialized */
  Sd_CheckDetErrorReturnValue(!(SD_STATE_UNINIT == Sd_State), SD_API_ID_CONSUMED_EVENTGROUP_SET_STATE, SD_E_NOT_INITIALIZED, E_NOT_OK);
  /* Return if the ConsumedEventGroupState has an undefined value */
  /* PRQA S 3201 4 */ /* MD_MSR_14.1 */
  /* PRQA S 3355,3356,3359 3 */ /* MD_Sd_13.7 */
  Sd_CheckDetErrorReturnValue(
    !((SD_CONSUMED_EVENTGROUP_RELEASED != ConsumedEventGroupState) && (SD_CONSUMED_EVENTGROUP_REQUESTED != ConsumedEventGroupState)),
    SD_API_ID_SERVER_SERVICE_SET_STATE, SD_E_INV_MODE, E_NOT_OK);

  /* Check if the SdConsumedEventGroupHandleId is valid */
  if((Sd_ConfigPtr->ConsumedEventGroupHandleIdMapSize > SdConsumedEventGroupHandleId) &&
    (NULL_PTR != Sd_ConfigPtr->ConsumedEventGroupHandleIdMapPtr[SdConsumedEventGroupHandleId]))
  {
#if (STD_ON == SD_DEV_ERROR_DETECT)
    InvalidId = FALSE;
#endif

    /* Get the consumed eventgroup */
    TmpConsumedEventGroupPtr = Sd_ConfigPtr->ConsumedEventGroupHandleIdMapPtr[SdConsumedEventGroupHandleId];

    /* Check if the ConsumedEventGroup is requested while the corresponding client service instance is not requested */
    if((SD_CONSUMED_EVENTGROUP_REQUESTED == ConsumedEventGroupState) &&
      (SD_CLIENT_SERVICE_REQUESTED != TmpConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->StateSWC))
    {
      RetVal = E_NOT_OK;
    }
    else
    {
      /* Update the state */
      Sd_SetValueAndTrigger(TmpConsumedEventGroupPtr->DynamicDataPtr->ServiceModeRequest, ConsumedEventGroupState,
        TmpConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->RootInstancePtr);
      RetVal = E_OK;
    }
  }

#if (STD_ON == SD_DEV_ERROR_DETECT)
  /* Raise error if SdConsumedEventGroupHandleId has an invalid (unknown) value */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnValue(!(TRUE == InvalidId), SD_API_ID_CONSUMED_EVENTGROUP_SET_STATE, SD_E_INV_ID, E_NOT_OK);
#endif

  return RetVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  Sd_ProcessHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ProcessHeader(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  SD_P2VAR(Sd_HeaderType) SdHeaderPtr)
{
  Std_ReturnType RetVal = E_OK;

  /* This function is called by Sd_RxIndication. Det-check for PduInfoPtr and initialization already done. */

  /*
  -----------------------------------------------------------------------------------------------------
  |                            Request ID (Client ID / Session ID) [32 bit]                           |
  -----------------------------------------------------------------------------------------------------
  | Protocol Version [8 bit] | Interface Version [8 bit] | Message Type [8 bit] | Return Code [8 bit] |
  -----------------------------------------------------------------------------------------------------
  |       Flags [8 bit]      |                             Reserved [24 bit]                          |
  -----------------------------------------------------------------------------------------------------
  S                                              Payload                                              S
  -----------------------------------------------------------------------------------------------------
  */

  /* Read the header */
  Sd_ReadHeader(PduInfoPtr->SduDataPtr, SdHeaderPtr);

  /* Check the predefined fields of the header */
  if((SD_HEADER_PROTOCOL_VERSION != SdHeaderPtr->ProtocolVersion) ||
    (SD_HEADER_INTERFACE_VERSION != SdHeaderPtr->InterfaceVersion) || (SD_HEADER_MESSAGE_TYPE != SdHeaderPtr->MessageType) ||
    (SD_HEADER_RETURN_CODE != SdHeaderPtr->ReturnCode))
  {
    /* The header is not compliant with the statically defined values */
    RetVal = E_NOT_OK;
  }

  return RetVal;
}

/**********************************************************************************************************************
 *  Sd_ReadHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_ReadHeader(
  SD_P2CONST(uint8) DataPtr,
  SD_P2VAR(Sd_HeaderType) SdHeaderPtr)
{
  /* Message ID and Length field of the SD header will be handled by the SoAd */
  SdHeaderPtr->ClientID = (uint16)((uint16)(DataPtr[0]) << 8) | ((uint16)(DataPtr[1]));
  SdHeaderPtr->SessionID = (uint16)((uint16)(DataPtr[2]) << 8) | ((uint16)(DataPtr[3]));
  SdHeaderPtr->ProtocolVersion = DataPtr[4];
  SdHeaderPtr->InterfaceVersion = DataPtr[5];
  SdHeaderPtr->MessageType = DataPtr[6];
  SdHeaderPtr->ReturnCode = (uint8)(DataPtr[7] & 0x3F); /* SREQ00024913: ignore two most significant bits of the return code */
  SdHeaderPtr->Flags = DataPtr[8];
  SdHeaderPtr->Reserved[0] = DataPtr[9];
  SdHeaderPtr->Reserved[1] = DataPtr[10];
  SdHeaderPtr->Reserved[2] = DataPtr[11];
}

/**********************************************************************************************************************
 *  Sd_HandleRemoteReboot()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_HandleRemoteReboot(
  uint16 InstanceIdx,
  SD_P2CONST(Sd_AddressStorageType) AddrPtr)
{
  SD_P2CONST(Sd_ServiceInstanceType) TmpServiceInstancePtr;
  Sd_SockAddrContainerType TmpAddr;
  uint16 ServiceInstanceIdx, EventHandlerIdx, SoConIdx;
  Std_ReturnType RetVal;

  /* Iterate over all service instances to find the one corresponding to the entry */
  ServiceInstanceIdx = Sd_GetInstancePtrByIdx(InstanceIdx)->ServiceInstancePtrListSize;
  while(0 < ServiceInstanceIdx)
  {
    ServiceInstanceIdx--;

    TmpServiceInstancePtr = Sd_GetInstancePtrByIdx(InstanceIdx)->ServiceInstancePtrListPtr[ServiceInstanceIdx];

    if(NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr)
    {
      if(TmpServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->ServerAddrPtr == &AddrPtr->Addr)
      {
        /* The ClientService is also affected by the reboot of the remote service */
        TmpServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_STOP_OFFER;
      }
    }
    else
    {
      /* Close all SocketConnections used on service level */
      SoConIdx = TmpServiceInstancePtr->UdpSoConListSize;
      while(0 < SoConIdx)
      {
        SoConIdx--;
        TmpAddr.family = SOAD_AF_INVALID;

        /* Get Remote Address of SocketConnection */
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetRemoteAddr(TmpServiceInstancePtr->UdpSoConListPtr[SoConIdx], (SD_P2VAR(SoAd_SockAddrType))&TmpAddr);

        /* PRQA S 3415 3 */ /* MD_Sd_12.4_3415 */
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        if((E_OK == RetVal) &&
          (SD_MATCH_TRUE == Sd_CompareSockAddrIp((SD_P2CONST(SoAd_SockAddrType))&AddrPtr->Addr, (SD_P2VAR(SoAd_SockAddrType))&TmpAddr, 0)))
        {
          /* SocketConnection was used for the rebooted remote client, close and reopen it */
          (void)SoAd_CloseSoCon(TmpServiceInstancePtr->UdpSoConListPtr[SoConIdx], TRUE);
          (void)SoAd_OpenSoCon(TmpServiceInstancePtr->UdpSoConListPtr[SoConIdx]);
        }
      }

      SoConIdx = TmpServiceInstancePtr->TcpSoConListSize;
      while(0 < SoConIdx)
      {
        SoConIdx--;
        TmpAddr.family = SOAD_AF_INVALID;

        /* Get Remote Address of SocketConnection */
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetRemoteAddr(TmpServiceInstancePtr->TcpSoConListPtr[SoConIdx], (SD_P2VAR(SoAd_SockAddrType))&TmpAddr);

        /* PRQA S 3415 3 */ /* MD_Sd_12.4_3415 */
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        if((E_OK == RetVal) &&
          (SD_MATCH_TRUE == Sd_CompareSockAddrIp((SD_P2CONST(SoAd_SockAddrType))&AddrPtr->Addr, (SD_P2VAR(SoAd_SockAddrType))&TmpAddr, 0)))
        {
          /* SocketConnection was used for the rebooted remote client, close and reopen it */
          (void)SoAd_CloseSoCon(TmpServiceInstancePtr->TcpSoConListPtr[SoConIdx], TRUE);
          (void)SoAd_OpenSoCon(TmpServiceInstancePtr->TcpSoConListPtr[SoConIdx]);
        }
      }

      /* Check if the remote service was subscribed before */
      EventHandlerIdx = TmpServiceInstancePtr->ServerInstancePtr->NrOfEventHandlers;
      while(0 < EventHandlerIdx)
      {
        EventHandlerIdx--;

        /* Set the TTL of all matching clients to 0 in order to remove the clients during the next main function */
        (void)Sd_FindClientInList(&TmpServiceInstancePtr->ServerInstancePtr->EventHandlerPtr[EventHandlerIdx],
          &AddrPtr->Addr, NULL_PTR, NULL_PTR, TRUE);
      }
    }
  }

  /* Trigger execution of the state machines in order to process the detected remote reboot */
  Sd_TriggerStateMachineRun(Sd_GetInstancePtrByIdx(InstanceIdx)); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

/**********************************************************************************************************************
 *  Sd_ProcessEntryOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_ProcessEntryOption(
  uint16 InstanceIdx,
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint16 IndexEntry,
  SD_P2VAR(Sd_SockAddrContainerType) SavedAddrPtr,
  boolean RebootDetected,
  boolean MulticastMessage)
{
  Sd_EntryFormatType EntryFormat;
  uint16 ServiceInstanceIdx;
  Sd_EntryType RxEntryType;
  uint16 RxServiceId;
  uint16 RxInstanceId;
  uint8 RxMajorVersion;
  uint16 RxReservedField;
  uint32 RxMinorVersion;
  uint16 RxEventGroupId;
  SD_P2CONST(Sd_ServiceInstanceType) TmpServiceInstancePtr;
  boolean FoundService = FALSE, ServerPresent = FALSE;

  RxEntryType = (Sd_EntryType)PduInfoPtr->SduDataPtr[IndexEntry];

  /* Check the entry format (service format or eventgroup format) */
  if((SD_ENTRY_FIND_SERVICE == RxEntryType) || (SD_ENTRY_OFFER_SERVICE == RxEntryType)) /* || (SD_ENTRY_STOP_OFFER_SERVICE == RxEntryType) */
  {
    EntryFormat = SD_ENTRY_SERVICE_TYPE;
  }
  else if((SD_ENTRY_SUBSCRIBE_EVENTGROUP == RxEntryType) || (SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK == RxEntryType)) /* || */
    /* (SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP == RxEntryType) || (SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK == RxEntryType) */
  {
    EntryFormat = SD_ENTRY_EVENTGROUP_TYPE;
  }
  else
  {
    EntryFormat = SD_ENTRY_UNDEFINED;
  }

  /* Check if the EntryType is valid */
  if(SD_ENTRY_UNDEFINED != EntryFormat)
  {
    RxServiceId = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+4]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+5]));
    RxInstanceId = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+6]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+7]));

    /* Iterate over all service instances to find the one corresponding to the entry */
    ServiceInstanceIdx = Sd_GetInstancePtrByIdx(InstanceIdx)->ServiceInstancePtrListSize;
    while(0 < ServiceInstanceIdx)
    {
      ServiceInstanceIdx--;

      TmpServiceInstancePtr = Sd_GetInstancePtrByIdx(InstanceIdx)->ServiceInstancePtrListPtr[ServiceInstanceIdx];

      /* Check if the ServiceId and InstanceId match. The wildcards are only allowed in the case of a FindService entry (type 1)  */
      if(((TmpServiceInstancePtr->ServiceId == RxServiceId) ||
             ((SD_ENTRY_WILDCARD_SERVICE_ID == RxServiceId) && (SD_ENTRY_FIND_SERVICE == RxEntryType))) &&
        ((TmpServiceInstancePtr->InstanceId == RxInstanceId) ||
            ((SD_ENTRY_WILDCARD_INSTANCE_ID == RxInstanceId) && (SD_ENTRY_FIND_SERVICE == RxEntryType))))
      {
        /* Found the corresponding service instance */
        FoundService = TRUE;

        /* Read and save the next parameters */
        RxMajorVersion = PduInfoPtr->SduDataPtr[IndexEntry+8];

        /* Differentiate between entry type 1 or 2 */
        if(SD_ENTRY_SERVICE_TYPE == EntryFormat)
        {
          /* Entry type 1 - Service */
          /* Process the entry even if the service is not available */

          RxMinorVersion = ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+12]) << 24) |
            ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+13]) << 16) |
            ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+14]) << 8) |
            ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+15]));

          /* Check the entry array fields */
          if(((TmpServiceInstancePtr->MajorVersion == RxMajorVersion) ||
                 ((SD_ENTRY_WILDCARD_MAJOR_VERSION == RxMajorVersion) && (SD_ENTRY_FIND_SERVICE == RxEntryType))) &&
            ((TmpServiceInstancePtr->MinorVersion == RxMinorVersion) ||
                ((SD_ENTRY_WILDCARD_MINOR_VERSION == RxMinorVersion) && (SD_ENTRY_FIND_SERVICE == RxEntryType)) ||
                ((SD_ENTRY_WILDCARD_MINOR_VERSION == TmpServiceInstancePtr->MinorVersion) &&
                  (SD_ENTRY_OFFER_SERVICE == RxEntryType) && (NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr))))
          {
            /* Differentiate between client and server service instance */
            if((SD_ENTRY_OFFER_SERVICE == RxEntryType) && (NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr))
            {
              /* SD_ENTRY_OFFER_SERVICE || SD_ENTRY_STOP_OFFER_SERVICE */

              Sd_ProcessClientEntryOption(PduInfoPtr, IndexEntry, EntryFormat, TmpServiceInstancePtr,
                SavedAddrPtr, RebootDetected, MulticastMessage);
            }
            else if((SD_ENTRY_FIND_SERVICE == RxEntryType) && (NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr))
            {
              /* SD_ENTRY_FIND_SERVICE */

              Sd_ProcessServerEntryOption(PduInfoPtr, IndexEntry, EntryFormat, TmpServiceInstancePtr, SavedAddrPtr,
                MulticastMessage);
            }
            else
            {
              /* Discard message because it does not match to the configuration */
            }
          }
          else
          {
            /* The predefined fields of the entry array do not match, do not process the entry */
          }
        }
        else /* SD_ENTRY_EVENTGROUP_TYPE == EntryFormat */
        {
          /* Entry type 2 - Eventgroup */

          /* Check the entry array fields, the reserved field is ignored */
          if(TmpServiceInstancePtr->MajorVersion == RxMajorVersion)
          {
            /* Differentiate between client and server service instance */
            if((SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK == RxEntryType) && (NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr))
            {
              /* SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK || SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK */

              /* Process the acknowledge only if no reboot of the remote server was detected */
              if(TRUE != RebootDetected)
              {
                Sd_ProcessClientEntryOption(PduInfoPtr, IndexEntry, EntryFormat, TmpServiceInstancePtr,
                  SavedAddrPtr, RebootDetected, MulticastMessage);
              }
            }
            else if((SD_ENTRY_SUBSCRIBE_EVENTGROUP == RxEntryType) && (NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr))
            {
              /* SD_ENTRY_SUBSCRIBE_EVENTGROUP || SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP */

              /* Process the subscription only if no reboot of the remote server was detected */
              if(TRUE == RebootDetected)
              {
                /* Triggers a NACK for the client */
                FoundService = FALSE;
              }
              else
              {
                Sd_ProcessServerEntryOption(PduInfoPtr, IndexEntry, EntryFormat, TmpServiceInstancePtr, SavedAddrPtr,
                  MulticastMessage);
              }
            }
            else
            {
              /* Discard message because it does not match to the configuration */
            }
          }
          else
          {
            if(NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr)
            {
              /* Trigger transmission of a NACK if the MajorVersion does not match */
              uint32 AdditionalDelay = 0;
              RxReservedField = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+12]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+13]));
              RxEventGroupId = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+14]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+15]));

              if(TRUE == MulticastMessage)
              {
                /* Add a random delay to the response message */
                AdditionalDelay = Sd_GetRandomNrInRangeForResponse(TmpServiceInstancePtr->ServerInstancePtr->TimerRef->RequestResponseMinDelay,
                  TmpServiceInstancePtr->ServerInstancePtr->TimerRef->RequestResponseMaxDelay, TRUE);
              }

              Sd_AddEventGroupNackEntryToList(Sd_GetInstancePtrByIdx(InstanceIdx)->SendEntriesListPtr, NULL_PTR,
                RxServiceId, RxInstanceId, RxMajorVersion, RxReservedField, RxEventGroupId, SavedAddrPtr,
                AdditionalDelay);
            }
          }
        }

        if(((SD_ENTRY_FIND_SERVICE == RxEntryType) &&
          ((SD_ENTRY_WILDCARD_SERVICE_ID == RxServiceId) || (SD_ENTRY_WILDCARD_INSTANCE_ID == RxInstanceId))) ||
          (SD_SERVICE_ID_OTHERSERV == RxServiceId))
        {
          /* The FindService entry contains wildcards or the message was for the otherserv service. */
          /* Search for additional matching services */
        }
        else
        {
          /* Found the corresponding ServiceInstance and processed the EntryOption */
          break;
        }
      }
      else
      {
        if((NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr) && (SD_ENTRY_EVENTGROUP_TYPE == EntryFormat))
        {
          /* Flag indicating if a SdServerService is present in the config */
          /* Only if a server is present, and a malformed subscribe message was received, a NACK should be send out */
          ServerPresent = TRUE;
        }
      }
    }

    /* Send a negative acknowledgement if the ServiceId or the InstanceId are unknown */
    if((FoundService == FALSE) && (TRUE == ServerPresent))
    {
      RxMajorVersion = PduInfoPtr->SduDataPtr[IndexEntry+8];
      RxReservedField = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+12]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+13]));
      RxEventGroupId = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+14]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+15]));

      Sd_AddEventGroupNackEntryToList(Sd_GetInstancePtrByIdx(InstanceIdx)->SendEntriesListPtr, NULL_PTR,
        RxServiceId, RxInstanceId, RxMajorVersion, RxReservedField, RxEventGroupId, SavedAddrPtr, 0);
    }
  }
  else
  {
    /* Undefined entry fields shall be ignored */
  }
} /* PRQA S 6010, 6030, 6060, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_IndexOptionArray()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_IndexOptionArray(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint16 StartIndexOption)
{
  Std_ReturnType RetVal = E_OK;
  uint32 LengthOfOptionsArray;
  uint16 LengthOfOption, TmpIndex, TmpLength = 0;
  Sd_OptionType OptionType;

  /* Clear the option index */
  Sd_GetOptionIndexListPtr()->NrOfOptions = 0;

  LengthOfOptionsArray = ((uint32)(PduInfoPtr->SduDataPtr[StartIndexOption]) << 24) |
    ((uint32)(PduInfoPtr->SduDataPtr[StartIndexOption+1]) << 16) |
    ((uint32)(PduInfoPtr->SduDataPtr[StartIndexOption+2]) << 8) |
    ((uint32)(PduInfoPtr->SduDataPtr[StartIndexOption+3]));
  TmpIndex = StartIndexOption + SD_SIZE_OF_OPTION_ARRAY_LENGTH_FIELD;

  /* Iterate through all Options and generate a index */
  while ((TmpLength < LengthOfOptionsArray) && (E_OK == RetVal))
  {
    /* Check if the length and the type field are part of the payload */
    if(PduInfoPtr->SduLength >= (TmpIndex + SD_SIZE_OF_OPTION_LENGTH_FIELD + SD_SIZE_OF_TYPE_FIELD))
    {
      /* Read the length and the type of the option */
      LengthOfOption = (uint16)((uint16)(PduInfoPtr->SduDataPtr[TmpIndex]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[TmpIndex+1]));
      OptionType = (Sd_OptionType)PduInfoPtr->SduDataPtr[TmpIndex+2];

      /* Check if the length of the option is feasible */
      if((uint32)(TmpLength + LengthOfOption + SD_SIZE_OF_OPTION_LENGTH_FIELD + SD_SIZE_OF_TYPE_FIELD) <= LengthOfOptionsArray)
      {
        /* Check the length of endpoint and multicast endpoint options */
        if((SD_OPTION_IPV4_ENDPOINT == OptionType) ||
          (SD_OPTION_IPV4_MULTICAST == OptionType) ||
          (SD_OPTION_IPV4_SD_ENDPOINT == OptionType))
        {
          if(SD_COVERED_LENGTH_OF_OPTION_IPv4 != LengthOfOption)
          {
            /* Invalid option */
            RetVal = E_NOT_OK;
          }
        }
        if((SD_OPTION_IPV6_ENDPOINT == OptionType) ||
          (SD_OPTION_IPV6_MULTICAST == OptionType) ||
          (SD_OPTION_IPV6_SD_ENDPOINT == OptionType))
        {
          if(SD_COVERED_LENGTH_OF_OPTION_IPv6 != LengthOfOption)
          {
            /* Invalid option */
            RetVal = E_NOT_OK;
          }
        }

        if(E_OK == RetVal)
        {
          /* The option is valid */
          if(Sd_ConfigPtr->OptionIndexArraySize > Sd_GetNrOfOptionsInList())
          {
            /* Add the option to the index */
            Sd_GetOptionIndex(Sd_GetNrOfOptionsInList()) = TmpIndex;
            Sd_GetNrOfOptionsInList()++;
            TmpIndex  +=  SD_SIZE_OF_OPTION_LENGTH_FIELD + SD_SIZE_OF_TYPE_FIELD + LengthOfOption;
            TmpLength +=  SD_SIZE_OF_OPTION_LENGTH_FIELD + SD_SIZE_OF_TYPE_FIELD + LengthOfOption;
          }
          else
          {
            /* The Sd_OptionIndex is full. Stop reading further options */
            RetVal = E_NOT_OK;
          }
        }
        else
        {
          /* The endpoint option length is not valid, stop reading further options */
        }
      }
      else
      {
        /* The option exceeds the length of the payload, stop reading the options array */
        RetVal = E_NOT_OK;
      }
    }
    else
    {
      /* The length field exceeds the payload, stop reading the options array */
      RetVal = E_NOT_OK;
    }
  }
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_GetSdEndpointOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_GetSdEndpointOption(
  SoAd_SoConIdType RxSoConId,
  SD_P2CONST(PduInfoType) PduInfoPtr,
  SD_P2VAR(Sd_SockAddrContainerType) SdEndpointAddressPtr)
{
  Std_ReturnType RetVal = E_OK;
  uint16 OptionIndex = 0;
  uint8 OptionType;

  SdEndpointAddressPtr->family = SOAD_AF_INVALID;

  while(OptionIndex < Sd_GetNrOfOptionsInList())
  {
    /* Get the option type */
    OptionType = PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(OptionIndex) + SD_SIZE_OF_OPTION_LENGTH_FIELD];

    if(SD_OPTION_IPV4_SD_ENDPOINT == OptionType)
    {
      /* Read the address transported IPv4 SD endpoint option */
      (void)Sd_ReadEndpointOption(SOAD_AF_INET, PduInfoPtr->SduDataPtr, Sd_GetOptionIndex(OptionIndex), SdEndpointAddressPtr);
    }
    else if(SD_OPTION_IPV6_SD_ENDPOINT == OptionType)
    {
      /* Read the address transported IPv6 SD endpoint option */
      (void)Sd_ReadEndpointOption(SOAD_AF_INET6, PduInfoPtr->SduDataPtr, Sd_GetOptionIndex(OptionIndex), SdEndpointAddressPtr);
    }
    else
    {
      /* No IPv4 or IPv6 SD endpoint option */
      RetVal = E_NOT_OK;
    }

    if(E_OK == RetVal)
    {
      /* Check if the SD endpoint address is part of the subnet */
      Sd_SockAddrContainerType LocalAddr;
      Sd_SockAddrContainerType DefaultRouter;
      uint8 NetmaskCidr = 0;

      /* Get the local IP address and the subnet mask */
      /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
      RetVal |= SoAd_GetLocalAddr(RxSoConId, (SD_P2VAR(SoAd_SockAddrType))&LocalAddr, &NetmaskCidr, (SD_P2VAR(SoAd_SockAddrType))&DefaultRouter);

      /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
      /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
      if((E_OK == RetVal) && (TRUE == Sd_SockAddrWithinSubnet((SD_P2VAR(SoAd_SockAddrType))&LocalAddr,
        (SD_P2VAR(SoAd_SockAddrType))SdEndpointAddressPtr, NetmaskCidr)))
      {
        /* First valid SD endpoint option successfully read */
      }
      else
      {
        /* The endpoint references an IP address outside the configured subnet, do not consider this endpoint option */
        SdEndpointAddressPtr->family = SOAD_AF_INVALID;
      }

      /* Only the first SD endpoint option shall be processed. (All further SD endpoint options shall be ignored.) */
      break;
    }

    OptionIndex++;
  }
}

/**********************************************************************************************************************
 *  Sd_ProcessClientEntryOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_ProcessClientEntryOption(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint16 IndexEntry,
  Sd_EntryFormatType EntryFormat,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr,
  SD_P2VAR(Sd_SockAddrContainerType) SavedAddrPtr,
  boolean RebootDetected,
  boolean MulticastMessage)
{
  Std_ReturnType RetVal = E_NOT_OK;
  SD_P2CONST(Sd_ClientServiceType) TmpClientServicePtr = ServiceInstancePtr->ClientInstancePtr;
  SD_P2CONST(Sd_ConsumedEventGroupType) TmpConsumedEventGroupPtr;
  Sd_SockAddrContainerType EndpointAddrUdp;
  Sd_SockAddrContainerType EndpointAddrTcp;
  uint32 RxTTL;
  uint16 RxEventGroupId;
  uint16 EventGroupIdx;
  uint8 Index1stOption, Index2ndOption;
  uint8 Nr1stOptions, Nr2ndOptions;

  EndpointAddrUdp.family = SOAD_AF_INVALID;
  EndpointAddrTcp.family = SOAD_AF_INVALID;

  Index1stOption = PduInfoPtr->SduDataPtr[IndexEntry+1];
  Index2ndOption = PduInfoPtr->SduDataPtr[IndexEntry+2];
  Nr1stOptions = (uint8)((PduInfoPtr->SduDataPtr[IndexEntry+3] & 0xF0) >> 4);
  Nr2ndOptions = (uint8)(PduInfoPtr->SduDataPtr[IndexEntry+3] & 0x0F);

  RxTTL = ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+9]) << 16) |
    ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+10]) << 8) |
    ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+11]));

  /* Differentiate between entry type 1 or 2 */
  if(SD_ENTRY_SERVICE_TYPE == EntryFormat)
  {
    /* SD_ENTRY_OFFER_SERVICE || SD_ENTRY_STOP_OFFER_SERVICE */
    Sd_ConfigOptionStringType configOptionPtrArray[3] = { NULL_PTR,  NULL_PTR,  NULL_PTR };

    /* The entry array is valid -> update the TTL */
    TmpClientServicePtr->DynamicDataPtr->OfferedTTL = RxTTL;

    /* Process the corresponding option array(s) */
    if(0 != Nr1stOptions)
    {
      RetVal = Sd_ProcessClientOption(PduInfoPtr, Index1stOption, Nr1stOptions, ServiceInstancePtr->RootInstancePtr->EMalformedMsgId,
        NULL_PTR, &EndpointAddrUdp, &EndpointAddrTcp, configOptionPtrArray);
    }
    if((0 != Nr2ndOptions) && ((0 == Nr1stOptions) || (E_OK == RetVal)))
    {
      RetVal = Sd_ProcessClientOption(PduInfoPtr, Index2ndOption, Nr2ndOptions, ServiceInstancePtr->RootInstancePtr->EMalformedMsgId,
        NULL_PTR, &EndpointAddrUdp, &EndpointAddrTcp, configOptionPtrArray);
    }
    else if((0 == Nr1stOptions) && (0 == Nr2ndOptions) && (0 == RxTTL))
    {
      /* SD_ENTRY_STOP_OFFER_SERVICE messages without any attached option are also allowed */
      RetVal = E_OK;
    }
    else
    {
      /* Error. Nothing to do */
    }

    /* Check if all attached options are valid and there exist no conflicting endpoints */
    if(E_OK == RetVal)
    {
      /* Check the attached configuration options by a user callout. \trace CREQ-121011 */
      if(SD_INV_CAPABILITY_RECORD_CALLOUT_FUNCTION_IDX != ServiceInstancePtr->CapabilityRecordCalloutFunctionIdx)
      {
        if(TRUE != Sd_CapabilityRecordFunctionCalloutPtrList[ServiceInstancePtr->CapabilityRecordCalloutFunctionIdx](
          (TRUE == MulticastMessage) ? ServiceInstancePtr->RootInstancePtr->MulticastRxPduId : ServiceInstancePtr->RootInstancePtr->UnicastRxPduId,
          SD_ENTRY_SUBSCRIBE_EVENTGROUP,
          ServiceInstancePtr->ServiceId,
          ServiceInstancePtr->InstanceId,
          ServiceInstancePtr->MajorVersion,
          ServiceInstancePtr->MinorVersion,
          configOptionPtrArray,
          &ServiceInstancePtr->CapabilityRecordPtr))
        {
          RetVal = E_NOT_OK;
        }
      }

      if(E_OK == RetVal)
      {
        /* Save the address of the server */
        TmpClientServicePtr->DynamicDataPtr->ServerAddrPtr = SavedAddrPtr;

        if(0 == RxTTL)
        {
          /* SD_ENTRY_STOP_OFFER_SERVICE */

          Sd_SetValueAndTrigger(TmpClientServicePtr->DynamicDataPtr->Event, SD_CLIENT_EVENT_SERVICE_STOP_OFFER,
            ServiceInstancePtr->RootInstancePtr);
        }
        else
        {
          /* SD_ENTRY_OFFER_SERVICE */

          /* Save the attached endpoint options */
          /* PRQA S 0310 5 */ /* MD_Sd_11.4_0310 */
          /* PRQA S 0311 4 */ /* MD_Sd_11.5_0311 */
          Sd_CopySockAddr((SD_P2VAR(SoAd_SockAddrType))(&TmpClientServicePtr->DynamicDataPtr->ServerUdpEndpointAddr),
            (SD_P2VAR(SoAd_SockAddrType))&EndpointAddrUdp);
          Sd_CopySockAddr((SD_P2VAR(SoAd_SockAddrType))(&TmpClientServicePtr->DynamicDataPtr->ServerTcpEndpointAddr),
            (SD_P2VAR(SoAd_SockAddrType))&EndpointAddrTcp);

          /* Check if a valid endpoint option was attached */
          if((SOAD_AF_INVALID != EndpointAddrUdp.family) || (SOAD_AF_INVALID != EndpointAddrTcp.family))
          {
            TmpClientServicePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_AVAILABLE;

            /* Differentiate between multicast and unicast offer messages */
            if(TRUE == MulticastMessage)
            {
              /* Check if a reboot occurred */
              if(TRUE == RebootDetected)
              {
                /* Handle reboot as StopOffer -> Offer sequence */
                TmpClientServicePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_STOP_OFFER_OFFER_MULTI;
              }
              else
              {
                TmpClientServicePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_OFFER_MULTI;
              }
            }
            else  /* FALSE == MulticastMessage */
            {
              /* Check if a reboot occurred */
              if(TRUE == RebootDetected)
              {
                /* Handle reboot as StopOffer -> Offer sequence */
                TmpClientServicePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_STOP_OFFER_OFFER_UNI;
              }
              else
              {
                TmpClientServicePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_OFFER_UNI;
              }
            }

            Sd_TriggerStateMachineRun(ServiceInstancePtr->RootInstancePtr); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          }
        }
      }
    }
  }
  else /* SD_ENTRY_EVENTGROUP_TYPE == EntryFormat */
  {
    /* SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK || SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK */

    RxEventGroupId = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+14]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+15]));

    /* Iterate trough each eventgroup to find the corresponding one */
    EventGroupIdx = TmpClientServicePtr->NrOfEventGroups;
    while(0 < EventGroupIdx)
    {
      EventGroupIdx--;

      TmpConsumedEventGroupPtr = TmpClientServicePtr->EventGroupPtrPtr[EventGroupIdx];

      if((RxEventGroupId == TmpConsumedEventGroupPtr->EventGroupId) &&
        (SD_CONSUMED_EVENTGROUP_REQUESTED == TmpConsumedEventGroupPtr->DynamicDataPtr->ServiceModeRequest))
      {
        Sd_ConfigOptionStringType configOptionPtrArray[3] = { NULL_PTR,  NULL_PTR,  NULL_PTR };

        /* The entry array is valid -> update the TTL of the eventgroup */
        TmpConsumedEventGroupPtr->DynamicDataPtr->AcknowledgedTTL = RxTTL;

        /* Process the corresponding option array(s) */
        if(0 != Nr1stOptions)
        {
          RetVal = Sd_ProcessClientOption(PduInfoPtr, Index1stOption, Nr1stOptions,  ServiceInstancePtr->RootInstancePtr->EMalformedMsgId,
            TmpConsumedEventGroupPtr, &EndpointAddrUdp, &EndpointAddrTcp, configOptionPtrArray);
        }
        if((0 != Nr2ndOptions) && ((0 == Nr1stOptions) || (E_OK == RetVal)))
        {
          RetVal = Sd_ProcessClientOption(PduInfoPtr, Index2ndOption, Nr2ndOptions,  ServiceInstancePtr->RootInstancePtr->EMalformedMsgId,
            TmpConsumedEventGroupPtr, &EndpointAddrUdp, &EndpointAddrTcp, configOptionPtrArray);
        }
        else if((0 == Nr1stOptions) && (0 == Nr2ndOptions))
        {
          /* SD_ENTRY_SUBSCRIBE_EVENTGROUP_(N)ACK messages without any attached option are also allowed */
          RetVal = E_OK;
        }
        else
        {
          /* Error. Nothing to do */
        }

        /* Check if all attached options are valid */
        if(E_OK == RetVal)
        {
          /* Check the attached configuration options by a user callout. \trace CREQ-121011 */
          if(SD_INV_CAPABILITY_RECORD_CALLOUT_FUNCTION_IDX != ServiceInstancePtr->CapabilityRecordCalloutFunctionIdx)
          {
            if(TRUE != Sd_CapabilityRecordFunctionCalloutPtrList[ServiceInstancePtr->CapabilityRecordCalloutFunctionIdx](
              (TRUE == MulticastMessage) ? ServiceInstancePtr->RootInstancePtr->MulticastRxPduId : ServiceInstancePtr->RootInstancePtr->UnicastRxPduId,
              SD_ENTRY_SUBSCRIBE_EVENTGROUP,
              ServiceInstancePtr->ServiceId,
              ServiceInstancePtr->InstanceId,
              ServiceInstancePtr->MajorVersion,
              ServiceInstancePtr->MinorVersion,
              configOptionPtrArray,
              &ServiceInstancePtr->CapabilityRecordPtr))
            {
              RetVal = E_NOT_OK;
            }
          }

          if(E_OK == RetVal)
          {
            if(0 == RxTTL)
            {
              /* SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK */
              /* Save the event */
              TmpConsumedEventGroupPtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_EVENTGROUP_NACK;
            }
            else
            {
              /* SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK */

              /* Save the attached endpoint option */
              /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
              /* PRQA S 0311 2 */ /* MD_Sd_11.5_0311 */
              Sd_CopySockAddr((SD_P2VAR(SoAd_SockAddrType))(&TmpClientServicePtr->DynamicDataPtr->ServerMulticastEndpointAddr),
                (SD_P2VAR(SoAd_SockAddrType))&EndpointAddrUdp);

              /* Save the event */
              TmpConsumedEventGroupPtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_EVENTGROUP_ACK;
            }

            /* Trigger execution of state machines */
            Sd_TriggerStateMachineRun(ServiceInstancePtr->RootInstancePtr); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          }
        }
      }
    }
  }
} /* PRQA S 6010, 6030, 6060, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_ProcessClientOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
/* PRQA S 3673 9 */ /* MD_Sd_16.7_3673 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ProcessClientOption(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint8 IndexOfOption,
  uint8 NrOfOptions,
  Sd_Dem_EventIdType EMalformedMsgId,
  SD_P2CONST(Sd_ConsumedEventGroupType) EventgroupPtr,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrUdpPtr,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrTcpPtr,
  SD_P2VAR(Sd_ConfigOptionStringType) ConfigOptionPtrArrayPtr)
{
  Std_ReturnType RetVal = E_OK;
  uint8 CurrentOption = IndexOfOption;
  Sd_OptionType OptionType;
  Sd_L4ProtocolType OptionL4Proto = SD_L4PROTOCOL_NONE;
  uint16 AddrType;

  /* Stop processing of the message if the header indexes more options than attached */
  if(Sd_GetNrOfOptionsInList() < (IndexOfOption + NrOfOptions))
  {
    RetVal = E_NOT_OK;
  }

  /* Process all consecutive options */
  while((E_OK == RetVal) && ((IndexOfOption + NrOfOptions) > CurrentOption))
  {
    AddrType = SOAD_AF_INVALID;

    /* Read the option information */
    OptionType = (Sd_OptionType)PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption) + SD_SIZE_OF_OPTION_LENGTH_FIELD];

    /* Differentiate between service- and eventgroup entry */
    if(NULL_PTR == EventgroupPtr)
    {
      /* SD_ENTRY_OFFER_SERVICE or SD_ENTRY_STOP_OFFER_SERVICE */
      switch(OptionType)
      {
        case SD_OPTION_CONFIGURATION:
          /* Check if configuration option is valid */
          RetVal = Sd_CheckConfigOption(&PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption)], ConfigOptionPtrArrayPtr);
          break;

        case SD_OPTION_IPV4_ENDPOINT:
          /* Read the L4 protocol */
          OptionL4Proto = (Sd_L4ProtocolType)PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption) + SD_IPV4_ENDPOINT_L4PROTO_OFFSET];
          AddrType = SOAD_AF_INET;
          break;

        case SD_OPTION_IPV6_ENDPOINT:
          /* Read the L4 protocol */
          OptionL4Proto = (Sd_L4ProtocolType)PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption) + SD_IPV6_ENDPOINT_L4PROTO_OFFSET];
          AddrType = SOAD_AF_INET6;
          break;

        case SD_OPTION_IPV4_MULTICAST:
        case SD_OPTION_IPV6_MULTICAST:
          /* Multicast options are not allowed for OfferService or StopOfferService entries and shall be ignored */
          break;

        default:
          /* Unknown option fields shall be ignored */
          break;
      }
    }
    else
    {
      /* SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK or SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK */
      switch(OptionType)
      {
        case SD_OPTION_CONFIGURATION:
          /* Check if configuration option is valid */
          RetVal = Sd_CheckConfigOption(&PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption)], ConfigOptionPtrArrayPtr);
          break;

        case SD_OPTION_IPV4_ENDPOINT:
        case SD_OPTION_IPV6_ENDPOINT:
          /* Unicast endpoint options are not allowed for SubscribeEventgroupAck or SubscribeEventgroupNack entries and shall be ignored */
          break;

        case SD_OPTION_IPV4_MULTICAST:
          /* Read the L4 protocol */
          OptionL4Proto = (Sd_L4ProtocolType)PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption) + SD_IPV4_ENDPOINT_L4PROTO_OFFSET];
          AddrType = SOAD_AF_INET;
          break;
        case SD_OPTION_IPV6_MULTICAST:
          /* Read the L4 protocol */
          OptionL4Proto = (Sd_L4ProtocolType)PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption) + SD_IPV6_ENDPOINT_L4PROTO_OFFSET];
          AddrType = SOAD_AF_INET6;
          break;

        default:
          /* Unknown option fields shall be ignored */
          break;
      }
    }

    if(SOAD_AF_INVALID != AddrType)
    {
      /* Differentiate between UDP and TCP endpoints */
      switch(OptionL4Proto)
      {
        case SD_L4PROTOCOL_UDP:
          /* Check if the UDP address was already configured by another endpoint */
          if(SOAD_AF_INVALID == EndpointAddrUdpPtr->family)
          {
            /* Read the address transported in the endpoint */
            RetVal = Sd_ReadEndpointOption(AddrType, PduInfoPtr->SduDataPtr, Sd_GetOptionIndex(CurrentOption), EndpointAddrUdpPtr);
          }
          else
          {
            /* This entry references multiple times the same type of endpoint option. Reject the subscription */
            RetVal = E_NOT_OK;
          }
          break;

        case SD_L4PROTOCOL_TCP:
          /* Check if the TCP address was already configured by another endpoint */
          if(SOAD_AF_INVALID == EndpointAddrTcpPtr->family)
          {
            /* Read the address transported in the endpoint */
            RetVal = Sd_ReadEndpointOption(AddrType, PduInfoPtr->SduDataPtr, Sd_GetOptionIndex(CurrentOption), EndpointAddrTcpPtr);
          }
          else
          {
            /* This entry references multiple times the same type of endpoint option. Reject the subscription */
            RetVal = E_NOT_OK;
          }
          break;

        default:
          /* Undefined protocol type. Reject the subscription */
            RetVal = E_NOT_OK;
          break;
      }
    }

    CurrentOption++;
  }

#if (STD_ON == SD_DEM_EVENTS_CONFIGURED)
  if(E_NOT_OK == RetVal)
  {
    /* Report an error if the endpoint configuration was not correct. \trace CREQ-121019 */
    Sd_DemMalformedMsg(EMalformedMsgId); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
#else
  SD_DUMMY_STATEMENT(EMalformedMsgId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  return RetVal;
} /* PRQA S 6010, 6030, 6060 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Sd_UpdateClientServiceSoCons()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_UpdateClientServiceSoCons(
  SD_P2CONST(Sd_ClientServiceType) ClientServicePtr,
  boolean EstablishConfiguration)
{
  Std_ReturnType RetVal = E_OK;
  SD_P2CONST(Sd_ConsumedEventGroupType) TmpConsumedEventGroupPtr;
  uint16 EventGroupIdx;
  Sd_SockAddrContainerType RemoteAddr;

  if(TRUE == EstablishConfiguration)
  {
    if((NULL_PTR != ClientServicePtr->MethodPtr) && (TRUE == ClientServicePtr->MethodPtr->TcpConfigured))
    {
      /* Check if the TCP connection is still established */
      /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
      if((SOAD_INV_SO_CON_ID != ClientServicePtr->DynamicDataPtr->MethodTcpSoConId) &&
        (SD_SOCON_MODE_LOST_CONNECTION == Sd_GetSoConMode(ClientServicePtr->DynamicDataPtr->MethodTcpSoConId)))
      {
        /* No valid connection, remove the configuration */
        (void)SoAd_CloseSoCon(ClientServicePtr->DynamicDataPtr->MethodTcpSoConId, TRUE);
        Sd_SetSoConMode(ClientServicePtr->DynamicDataPtr->MethodTcpSoConId, SOAD_SOCON_OFFLINE);
        ClientServicePtr->DynamicDataPtr->MethodTcpSoConId = SOAD_INV_SO_CON_ID;
      }

      if(SOAD_AF_INVALID != ClientServicePtr->DynamicDataPtr->ServerTcpEndpointAddr.family)
      {
        if(SOAD_INV_SO_CON_ID == ClientServicePtr->DynamicDataPtr->MethodTcpSoConId)
        {
          /* Configure a socket connection with the corresponding remote address */
          /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
          RetVal = SoAd_SetUniqueRemoteAddr(ClientServicePtr->RootServiceInstancePtr->TcpSoConListPtr[0],
            (SD_P2VAR(SoAd_SockAddrType))&ClientServicePtr->DynamicDataPtr->ServerTcpEndpointAddr,
            &ClientServicePtr->DynamicDataPtr->MethodTcpSoConId);

          if((E_OK == RetVal) && (SOAD_INV_SO_CON_ID != ClientServicePtr->DynamicDataPtr->MethodTcpSoConId))
          {
            /* Each entity which requires the SocketConnection opens it in order to indicate the dependency */
            RetVal |= SoAd_OpenSoCon(ClientServicePtr->DynamicDataPtr->MethodTcpSoConId);
            RetVal |= SoAd_EnableSpecificRouting(ClientServicePtr->MethodPtr->ActivationRef, ClientServicePtr->DynamicDataPtr->MethodTcpSoConId);
          }
        }
        else
        {
          /* The SoCon is already configured. Check if the server endpoint address has changed */

          /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
          RetVal = SoAd_GetRemoteAddr(ClientServicePtr->DynamicDataPtr->MethodTcpSoConId, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr);
          /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
          /* PRQA S 0311 2 */ /* MD_Sd_11.5_0311 */
          if(FALSE == Sd_SockAddrIsEqual((SD_P2VAR(SoAd_SockAddrType))&ClientServicePtr->DynamicDataPtr->ServerTcpEndpointAddr,
            (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr))
          {
            /* The attached endpoint has changed. Close the currently configured connection and mark the service as not available */
            (void)SoAd_CloseSoCon(ClientServicePtr->DynamicDataPtr->MethodTcpSoConId, FALSE);
            (void)SoAd_DisableSpecificRouting(ClientServicePtr->MethodPtr->ActivationRef, ClientServicePtr->DynamicDataPtr->MethodTcpSoConId);
            ClientServicePtr->DynamicDataPtr->MethodTcpSoConId = SOAD_INV_SO_CON_ID;
            Sd_ResetTimerToZeroTrigger(ClientServicePtr->DynamicTimerPtr->TimerTTL,
              ClientServicePtr->RootServiceInstancePtr->RootInstancePtr);
            RetVal = E_NOT_OK;
          }
        }
      }
      else
      {
        /* The server has NOT offered all required endpoints */
        RetVal = E_NOT_OK;
      }
    }

    if((NULL_PTR != ClientServicePtr->MethodPtr) && (TRUE == ClientServicePtr->MethodPtr->UdpConfigured))
    {
      if(SOAD_AF_INVALID != ClientServicePtr->DynamicDataPtr->ServerUdpEndpointAddr.family)
      {
        if(SOAD_INV_SO_CON_ID == ClientServicePtr->DynamicDataPtr->MethodUdpSoConId)
        {
          /* Configure a socket connection with the corresponding remote address */
          /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
          RetVal = SoAd_SetUniqueRemoteAddr(ClientServicePtr->RootServiceInstancePtr->UdpSoConListPtr[0],
            (SD_P2VAR(SoAd_SockAddrType))&ClientServicePtr->DynamicDataPtr->ServerUdpEndpointAddr,
            &ClientServicePtr->DynamicDataPtr->MethodUdpSoConId);

          if((E_OK == RetVal) && (SOAD_INV_SO_CON_ID != ClientServicePtr->DynamicDataPtr->MethodUdpSoConId))
          {
            /* Each entity which requires the SocketConnection opens it in order to indicate the dependency */
            RetVal |= SoAd_OpenSoCon(ClientServicePtr->DynamicDataPtr->MethodUdpSoConId);
            RetVal |= SoAd_EnableSpecificRouting(ClientServicePtr->MethodPtr->ActivationRef, ClientServicePtr->DynamicDataPtr->MethodUdpSoConId);
          }
        }
        else
        {
          /* The SoCon is already configured. Check if the server endpoint address has changed */

          /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
          RetVal = SoAd_GetRemoteAddr(ClientServicePtr->DynamicDataPtr->MethodUdpSoConId, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr);
          /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
          /* PRQA S 0311 2 */ /* MD_Sd_11.5_0311 */
          if(FALSE == Sd_SockAddrIsEqual((SD_P2VAR(SoAd_SockAddrType))&ClientServicePtr->DynamicDataPtr->ServerUdpEndpointAddr,
            (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr))
          {
            /* The attached endpoint has changed. Close the currently configured connection and mark the service as not available */
            (void)SoAd_CloseSoCon(ClientServicePtr->DynamicDataPtr->MethodUdpSoConId, FALSE);
            (void)SoAd_DisableSpecificRouting(ClientServicePtr->MethodPtr->ActivationRef, ClientServicePtr->DynamicDataPtr->MethodUdpSoConId);
            ClientServicePtr->DynamicDataPtr->MethodUdpSoConId = SOAD_INV_SO_CON_ID;
            Sd_ResetTimerToZeroTrigger(ClientServicePtr->DynamicTimerPtr->TimerTTL,
              ClientServicePtr->RootServiceInstancePtr->RootInstancePtr);
            RetVal = E_NOT_OK;
          }
        }
      }
      else
      {
        /* The server has NOT offered all required endpoints */
        RetVal = E_NOT_OK;
      }
    }
  }
  else  /* TRUE != EstablishConfiguration */
  {
    boolean abortFlag = FALSE;

    /* Check if the renewal was triggered by reboot detection */
    if((SD_CLIENT_EVENT_SERVICE_STOP_OFFER_OFFER_MULTI == ClientServicePtr->DynamicDataPtr->Event) ||
      (SD_CLIENT_EVENT_SERVICE_STOP_OFFER_OFFER_UNI == ClientServicePtr->DynamicDataPtr->Event))
    {
      /* Do not remove the server endpoint addresses. These will be used during the next cycle to reestablish connections */
      /* Abort existing TCP connections because remote server has rebooted */
      abortFlag = TRUE;
    }
    else
    {
      /* Remove the saved endpoint addresses */
      ClientServicePtr->DynamicDataPtr->ServerTcpEndpointAddr.family = SOAD_AF_INVALID;
      ClientServicePtr->DynamicDataPtr->ServerUdpEndpointAddr.family = SOAD_AF_INVALID;
      ClientServicePtr->DynamicDataPtr->ServerMulticastEndpointAddr.family = SOAD_AF_INVALID;
    }

    /* Iterate over all eventgroups, disable the routing groups and close the SoCons */
    EventGroupIdx = ClientServicePtr->NrOfEventGroups;
    while(0 < EventGroupIdx)
    {
      EventGroupIdx--;
      TmpConsumedEventGroupPtr = ClientServicePtr->EventGroupPtrPtr[EventGroupIdx];

      if(SOAD_INV_SO_CON_ID != TmpConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId)
      {
        RetVal |= SoAd_DisableRouting(TmpConsumedEventGroupPtr->TcpActRef);
        RetVal |= SoAd_CloseSoCon(TmpConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId, abortFlag);
        TmpConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId = SOAD_INV_SO_CON_ID;
      }
      if(SOAD_INV_SO_CON_ID != TmpConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId)
      {
        RetVal |= SoAd_DisableRouting(TmpConsumedEventGroupPtr->UdpActRef);
        RetVal |= SoAd_CloseSoCon(TmpConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId, abortFlag);
        TmpConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId = SOAD_INV_SO_CON_ID;
      }
      if(SOAD_INV_SO_CON_ID != TmpConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId)
      {
        RetVal |= SoAd_DisableRouting(TmpConsumedEventGroupPtr->MulticastActRef);
        RetVal |= Sd_ReleaseIpAddrAssignment(TmpConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId);
        RetVal |= SoAd_CloseSoCon(TmpConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId, abortFlag);
        TmpConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId = SOAD_INV_SO_CON_ID;
      }
    }

    /* Disable the SoAd routing groups for methods and close the SoCons */
    if((NULL_PTR != ClientServicePtr->MethodPtr) &&
      ((TRUE == ClientServicePtr->MethodPtr->TcpConfigured) || (TRUE == ClientServicePtr->MethodPtr->UdpConfigured)))
    {
      RetVal |= SoAd_DisableRouting(ClientServicePtr->MethodPtr->ActivationRef);

      if(SOAD_INV_SO_CON_ID != ClientServicePtr->DynamicDataPtr->MethodTcpSoConId)
      {
        RetVal |= SoAd_CloseSoCon(ClientServicePtr->DynamicDataPtr->MethodTcpSoConId, abortFlag);
        ClientServicePtr->DynamicDataPtr->MethodTcpSoConId = SOAD_INV_SO_CON_ID;
      }
      if(SOAD_INV_SO_CON_ID != ClientServicePtr->DynamicDataPtr->MethodUdpSoConId)
      {
        RetVal |= SoAd_CloseSoCon(ClientServicePtr->DynamicDataPtr->MethodUdpSoConId, abortFlag);
        ClientServicePtr->DynamicDataPtr->MethodUdpSoConId = SOAD_INV_SO_CON_ID;
      }
    }
  }

  return RetVal;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_UpdateClientServiceEventGroupSoCons()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_UpdateClientServiceEventGroupSoCons(
  SD_P2CONST(Sd_ConsumedEventGroupType) ConsumedEventGroupPtr,
  boolean AcknowledgeReceived)
{
  Std_ReturnType RetVal = E_OK;
  SoAd_SoConIdType AssignedSoConId = SOAD_INV_SO_CON_ID;
  uint16 SoConIdx;
  Sd_SockAddrContainerType RemoteAddr;
  boolean LocalIpAddrExactMatch = FALSE;
  boolean LocalPortExactMatch = FALSE;
  boolean RemoteAddrExactMatch = FALSE;

  if(FALSE == AcknowledgeReceived)
  {
    /* Update the TCP configuration */
    if(Sd_ConsumedEventGroupUsesTcp(ConsumedEventGroupPtr))
    {
      /* Check if the TCP connection is still established */
      if(SOAD_INV_SO_CON_ID != ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId)
      {
        if(SD_SOCON_MODE_LOST_CONNECTION == Sd_GetSoConMode(ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId))
        {
          /* No valid connection, remove the configuration */
          (void)SoAd_CloseSoCon(ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId, TRUE);
          Sd_SetSoConMode(ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId, SOAD_SOCON_OFFLINE);
          ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId = SOAD_INV_SO_CON_ID;
        }
      }

      /* Check if the endpoint address has changed */
      if(SOAD_INV_SO_CON_ID != ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId)
      {
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetRemoteAddr(ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr);
        /* PRQA S 0310 5 */ /* MD_Sd_11.4_0310 */
        /* PRQA S 0311 4 */ /* MD_Sd_11.5_0311 */
        /* PRQA S 3415 3 */ /* MD_Sd_12.4_3415 */
        if((E_OK == RetVal) && (FALSE == Sd_SockAddrIsEqual(
          (SD_P2VAR(SoAd_SockAddrType))&ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerTcpEndpointAddr,
          (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr)))
        {
          /* The attached endpoint has changed. Close the currently configured connection and mark the service as not available */
          (void)SoAd_CloseSoCon(ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId, FALSE);
          ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId = SOAD_INV_SO_CON_ID;
          Sd_ResetTimerToZeroTrigger(ConsumedEventGroupPtr->RootClientServicePtr->DynamicTimerPtr->TimerTTL,
            ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->RootInstancePtr);
          RetVal = E_NOT_OK;
        }
      }
      else
      {
        /* Try to establish a connection to the server */
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_SetUniqueRemoteAddr(ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->TcpSoConListPtr[0],
          (SD_P2VAR(SoAd_SockAddrType))&ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerTcpEndpointAddr,
          &AssignedSoConId);

        if(E_OK == RetVal)
        {
          /* The requested IP address could be set or is already set */

          /* Each EventGroup which requires the SocketConnection opens it in order to indicate the dependency */
          RetVal |= SoAd_OpenSoCon(AssignedSoConId);

          /* Save the SocketConnectionId which is used for this EventGroup */
          ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId = AssignedSoConId;
        }
      }

      /* Check if the server endpoint address could be saved */
      if(SOAD_INV_SO_CON_ID == ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId)
      {
        RetVal = E_NOT_OK;
      }
    }

    /* Update the UDP configuration */
    if(Sd_ConsumedEventGroupUsesUdp(ConsumedEventGroupPtr) && (E_OK == RetVal))
    {
      /* Check if the endpoint address has changed */
      if(SOAD_INV_SO_CON_ID != ConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId)
      {
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetRemoteAddr(ConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr);
        /* PRQA S 0310 5 */ /* MD_Sd_11.4_0310 */
        /* PRQA S 0311 4 */ /* MD_Sd_11.5_0311 */
        /* PRQA S 3415 3 */ /* MD_Sd_12.4_3415 */
        if((E_OK == RetVal) && (FALSE == Sd_SockAddrIsEqual(
          (SD_P2VAR(SoAd_SockAddrType))&ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerUdpEndpointAddr,
          (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr)))
        {
          /* The attached endpoint has changed. Close the currently configured connection and mark the service as not available */
          (void)SoAd_CloseSoCon(ConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId, FALSE);
          ConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId = SOAD_INV_SO_CON_ID;
          Sd_ResetTimerToZeroTrigger(ConsumedEventGroupPtr->RootClientServicePtr->DynamicTimerPtr->TimerTTL,
            ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->RootInstancePtr);
          RetVal = E_NOT_OK;
        }
      }
      else
      {
        /* Check if a SocketConnection is already configured with the correct server IP address or configure a new one */
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_SetUniqueRemoteAddr(ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->UdpSoConListPtr[0],
          (SD_P2VAR(SoAd_SockAddrType))&ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerUdpEndpointAddr,
          &AssignedSoConId);

        if(E_OK == RetVal)
        {
          /* The requested IP address could be set or is already set */

          /* Each EventGroup which requires the SocketConnection opens it in order to indicate the dependency */
          RetVal |= SoAd_OpenSoCon(AssignedSoConId);

          /* Save the SocketConnectionId which is used for this EventGroup */
          ConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId = AssignedSoConId;
        }
      }

      /* Check if the server endpoint address could be saved */
      if(SOAD_INV_SO_CON_ID == ConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId)
      {
        RetVal = E_NOT_OK;
      }
    }
  }
  else /* (FALSE != AcknowledgeReceived) */
  {
    /* Update the MULTICAST configuration */
    if(Sd_ConsumedEventGroupUsesMulticast(ConsumedEventGroupPtr))
    {
      if(SOAD_INV_SO_CON_ID != ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId)
      {
        /* Check if the local endpoint address has changed */
        Sd_SockAddrContainerType LocalAddr;
        Sd_SockAddrContainerType DefaultRouter;
        uint8 NetmaskCidr = 0;

        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetLocalAddr(ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId,
          (SD_P2VAR(SoAd_SockAddrType))&LocalAddr, &NetmaskCidr, (SD_P2VAR(SoAd_SockAddrType))&DefaultRouter);

        /* PRQA S 0310 5 */ /* MD_Sd_11.4_0310 */
        /* PRQA S 0311 4 */ /* MD_Sd_11.5_0311 */
        /* PRQA S 3415 3 */ /* MD_Sd_12.4_3415 */
        if((E_OK == RetVal) && (FALSE == Sd_SockAddrIsEqual(
          (SD_P2VAR(SoAd_SockAddrType))&ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerMulticastEndpointAddr,
          (SD_P2VAR(SoAd_SockAddrType))&LocalAddr)))
        {
          /* The attached endpoint has changed. Unconfigure the local address */
          (void)Sd_ReleaseIpAddrAssignment(ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId);

          (void)SoAd_DisableSpecificRouting(ConsumedEventGroupPtr->MulticastActRef, ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId);
          (void)SoAd_CloseSoCon(ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId, FALSE);
          ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId = SOAD_INV_SO_CON_ID;

          RetVal = E_NOT_OK;
        }
      }
      else
      {
        /* Check all available SocketConnections and find the one which matches best to the server */
        RetVal = Sd_FindBestMatchLocalRemoteSoCon(ConsumedEventGroupPtr->MulticastSoConPtr,
          ConsumedEventGroupPtr->NrMulticastSoCons, ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr,
          &SoConIdx, &LocalIpAddrExactMatch, &LocalPortExactMatch, &RemoteAddrExactMatch);

        if(E_OK == RetVal)
        {
          /* Configure the local Address according to the server multicast endpoint */
          if((FALSE == LocalIpAddrExactMatch) || (FALSE == LocalPortExactMatch))
          {
            /* PRQA S 3415 4 */ /* MD_Sd_12.4_3415 */
            /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
            if((FALSE == LocalIpAddrExactMatch) &&
              (TRUE == Sd_LocalIpAlreadyConfigured(
              (SD_P2VAR(SoAd_SockAddrType))&ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerMulticastEndpointAddr)))
            {
              /* The requested multicast IP address is already configured at another socket */
              RetVal = E_NOT_OK;
            }
            else
            {
              /* Request the local Address according to the endpoint */
              RetVal |= Sd_RequestIpAddrAssignment(ConsumedEventGroupPtr->MulticastSoConPtr[SoConIdx],
                &ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerMulticastEndpointAddr, TRUE);
            }
          }
          else
          {
            /* The local address is already configured. Increment the request counter */
            RetVal |= Sd_RequestIpAddrAssignment(ConsumedEventGroupPtr->MulticastSoConPtr[SoConIdx],
              &ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerMulticastEndpointAddr, FALSE);
          }

          if(E_OK == RetVal)
          {
            if(FALSE == RemoteAddrExactMatch)
            {
              /* Configure the remote Address according to the server unicast endpoint */
              /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
              RetVal |= SoAd_SetRemoteAddr(ConsumedEventGroupPtr->MulticastSoConPtr[SoConIdx],
                (SD_P2VAR(SoAd_SockAddrType))&ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerUdpEndpointAddr);
            }

            /* Open the SocketConnection. Each EventGroup which requires the SocketConnection opens it in order to indicate the dependency */
            RetVal |= SoAd_OpenSoCon(ConsumedEventGroupPtr->MulticastSoConPtr[SoConIdx]);

            /* Save the SocketConnectionId which is used for this EventGroup */
            ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId = ConsumedEventGroupPtr->MulticastSoConPtr[SoConIdx];
          }
        }

        /* Check if the server endpoint address could be saved */
        if(SOAD_INV_SO_CON_ID == ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId)
        {
          RetVal = E_NOT_OK;

          /* Check if no valid multicast SoCon was found because of a missing multicast endpoint */
          if(SOAD_AF_INVALID == ConsumedEventGroupPtr->RootClientServicePtr->DynamicDataPtr->ServerMulticastEndpointAddr.family)
          {
            /* Accept the acknowledge if the unicast configuration was successful */
            if((Sd_ConsumedEventGroupUsesUdp(ConsumedEventGroupPtr) && (SOAD_INV_SO_CON_ID != ConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId)) ||
              (Sd_ConsumedEventGroupUsesTcp(ConsumedEventGroupPtr) && (SOAD_INV_SO_CON_ID != ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId)))
            {
              /* Accept the acknowledge */
              RetVal = E_OK;
            }
          }
        }
      }
    }

    if(E_OK == RetVal)
    {
      /* Enable the multicast PDU routing */
      if(SOAD_INV_SO_CON_ID != ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId)
      {
        RetVal |= SoAd_EnableSpecificRouting(ConsumedEventGroupPtr->MulticastActRef, ConsumedEventGroupPtr->DynamicDataPtr->MulticastSoConId);
      }
    }
  }

  return RetVal;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_ProcessServerEntryOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_ProcessServerEntryOption(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint16 IndexEntry,
  Sd_EntryFormatType EntryFormat,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr,
  SD_P2VAR(Sd_SockAddrContainerType) SavedAddrPtr,
  boolean MulticastMessage)
{
  Std_ReturnType RetVal = E_NOT_OK;
  SD_P2VAR(Sd_ClientListType) TmpClientPtr;
  Sd_SockAddrContainerType EndpointAddrUdp;
  Sd_SockAddrContainerType EndpointAddrTcp;
  boolean EventGroupConfigured = FALSE;
  uint32 RxTTL;
  uint32 RandDelay = 0;
  uint16 RxServiceId, RxInstanceId;
  uint16 EventHandlerIdx;
  uint16 RxReservedField;
  uint16 RxEventGroupId;
  uint8 RxMajorVersion;
  uint8 Index1stOption, Index2ndOption;
  uint8 Nr1stOptions, Nr2ndOptions;

  EndpointAddrUdp.family = SOAD_AF_INVALID;
  EndpointAddrTcp.family = SOAD_AF_INVALID;

  Index1stOption = PduInfoPtr->SduDataPtr[IndexEntry+1];
  Index2ndOption = PduInfoPtr->SduDataPtr[IndexEntry+2];
  Nr1stOptions = (uint8)((PduInfoPtr->SduDataPtr[IndexEntry+3] & 0xF0) >> 4);
  Nr2ndOptions = (uint8)(PduInfoPtr->SduDataPtr[IndexEntry+3] & 0x0F);

  RxTTL = ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+9]) << 16) |
    ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+10]) << 8) |
    ((uint32)(PduInfoPtr->SduDataPtr[IndexEntry+11]));

  /* Differentiate between entry type 1 or 2 */
  if(SD_ENTRY_SERVICE_TYPE == EntryFormat)
  {
    /* SD_ENTRY_FIND_SERVICE */

    /* Ignore Findservice messages if the server service is not available, during the initial wait phase, or with a TTL == 0 */
    if((SD_SERVER_SERVICE_DOWN == ServiceInstancePtr->ServerInstancePtr->DynamicDataPtr->StateSWC) ||
      (SD_SERVER_STATE_READY_INITIAL_WAIT == ServiceInstancePtr->ServerInstancePtr->DynamicDataPtr->StateMachine)||
      (0 == RxTTL))
    {
      /* The FindService entry is ignored */
    }
    else
    {
      Sd_ConfigOptionStringType configOptionPtrArray[3] = { NULL_PTR,  NULL_PTR,  NULL_PTR };

      /* Process the corresponding option array(s) (only configuration options are allowed, endpoint options shall be ignored) */
      if(0 != Nr1stOptions)
      {
        RetVal = Sd_ProcessServerOption(PduInfoPtr, Index1stOption, Nr1stOptions, NULL_PTR,
          &EndpointAddrUdp, &EndpointAddrTcp, configOptionPtrArray);
      }
      if((0 != Nr2ndOptions) && ((E_OK == RetVal) || (0 == Nr1stOptions)))
      {
        RetVal = Sd_ProcessServerOption(PduInfoPtr, Index2ndOption, Nr2ndOptions, NULL_PTR,
          &EndpointAddrUdp, &EndpointAddrTcp, configOptionPtrArray);
      }
      else if((0 == Nr1stOptions) && (0 == Nr2ndOptions))
      {
        /* Find messages without any attached option are also allowed */
        RetVal = E_OK;
      }
      else
      {
        /* Error. Nothing to do */
      }

      /* Process the find entry */
      if((E_OK == RetVal) && (SD_INSTANCE_UP_AND_CONFIGURED == ServiceInstancePtr->RootInstancePtr->DynamicDataPtr->State))
      {
        /* Check the attached configuration options by a user callout. \trace CREQ-121011 */
        if(SD_INV_CAPABILITY_RECORD_CALLOUT_FUNCTION_IDX != ServiceInstancePtr->CapabilityRecordCalloutFunctionIdx)
        {
          if(TRUE != Sd_CapabilityRecordFunctionCalloutPtrList[ServiceInstancePtr->CapabilityRecordCalloutFunctionIdx](
            (TRUE == MulticastMessage) ? ServiceInstancePtr->RootInstancePtr->MulticastRxPduId : ServiceInstancePtr->RootInstancePtr->UnicastRxPduId,
            SD_ENTRY_FIND_SERVICE,
            ServiceInstancePtr->ServiceId,
            ServiceInstancePtr->InstanceId,
            ServiceInstancePtr->MajorVersion,
            ServiceInstancePtr->MinorVersion,
            configOptionPtrArray,
            &ServiceInstancePtr->CapabilityRecordPtr))
          {
            RetVal = E_NOT_OK;
          }
        }

        if(E_OK == RetVal)
        {
          /* Check if the FindMessage was transmitted by multicast or unicast */
          if(TRUE == MulticastMessage)
          {
            /* Add a random delay to the response message */
            RandDelay = Sd_GetRandomNrInRangeForResponse(ServiceInstancePtr->ServerInstancePtr->TimerRef->RequestResponseMinDelay,
              ServiceInstancePtr->ServerInstancePtr->TimerRef->RequestResponseMaxDelay, TRUE);
          }

          /* Add a unicast OfferService to the list of sendentries */
          Sd_AddUnicastOfferEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr,
            ServiceInstancePtr, FALSE, SavedAddrPtr, RandDelay);
        }
      }
    }
  }
  else /* SD_ENTRY_EVENTGROUP_TYPE == EntryFormat */
  {
    /* SD_ENTRY_SUBSCRIBE_EVENTGROUP || SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP */

    SD_P2CONST(Sd_EventHandlerType)  TmpEventHandlerPtr = NULL_PTR;
    RxEventGroupId = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+14]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+15]));

    /* Iterate trough each eventgroup to find the corresponding one */
    EventHandlerIdx = ServiceInstancePtr->ServerInstancePtr->NrOfEventHandlers;
    while((0 < EventHandlerIdx) && (FALSE == EventGroupConfigured))
    {
      EventHandlerIdx--;

      TmpEventHandlerPtr = &ServiceInstancePtr->ServerInstancePtr->EventHandlerPtr[EventHandlerIdx];

      if((RxEventGroupId == TmpEventHandlerPtr->EventGroupId) &&
        (SD_SERVER_SERVICE_AVAILABLE == ServiceInstancePtr->ServerInstancePtr->DynamicDataPtr->StateSWC))
      {
        Sd_ConfigOptionStringType configOptionPtrArray[3] = { NULL_PTR,  NULL_PTR,  NULL_PTR };

        EventGroupConfigured = TRUE;

        /* Process the corresponding option array(s) and read the data of the attached endpoints */
        if(0 != Nr1stOptions)
        {
          RetVal = Sd_ProcessServerOption(PduInfoPtr, Index1stOption, Nr1stOptions, TmpEventHandlerPtr,
            &EndpointAddrUdp, &EndpointAddrTcp, configOptionPtrArray);
        }
        if((0 != Nr2ndOptions) && ((0 == Nr1stOptions) || (E_OK == RetVal)))
        {
          RetVal = Sd_ProcessServerOption(PduInfoPtr, Index2ndOption, Nr2ndOptions, TmpEventHandlerPtr,
            &EndpointAddrUdp, &EndpointAddrTcp, configOptionPtrArray);
        }
        else if((0 == Nr1stOptions) && (0 == Nr2ndOptions))
        {
          if(Sd_EventHandlerUsesMulticast(TmpEventHandlerPtr))
          {
            /* The EventGroup is configured for multicast, allow the subscription without any attached endpoint option */
            RetVal = E_OK;
          }
        }
        else
        {
          /* Error. Nothing to do */
        }

        /* Check if all required endpoint options are present */
        if((E_OK == RetVal) &&
          (((!Sd_EventHandlerUsesUdp(TmpEventHandlerPtr)) && (!Sd_EventHandlerUsesTcp(TmpEventHandlerPtr))) ||
          (Sd_EventHandlerUsesUdp(TmpEventHandlerPtr) && (SOAD_AF_INVALID != EndpointAddrUdp.family)) ||
          (Sd_EventHandlerUsesTcp(TmpEventHandlerPtr) && (SOAD_AF_INVALID != EndpointAddrTcp.family))))
        {
          /* Check the attached configuration options by a user callout. \trace CREQ-121011 */
          if(SD_INV_CAPABILITY_RECORD_CALLOUT_FUNCTION_IDX != ServiceInstancePtr->CapabilityRecordCalloutFunctionIdx)
          {
            if(TRUE != Sd_CapabilityRecordFunctionCalloutPtrList[ServiceInstancePtr->CapabilityRecordCalloutFunctionIdx](
              (TRUE == MulticastMessage) ? ServiceInstancePtr->RootInstancePtr->MulticastRxPduId : ServiceInstancePtr->RootInstancePtr->UnicastRxPduId,
              SD_ENTRY_SUBSCRIBE_EVENTGROUP,
              ServiceInstancePtr->ServiceId,
              ServiceInstancePtr->InstanceId,
              ServiceInstancePtr->MajorVersion,
              ServiceInstancePtr->MinorVersion,
              configOptionPtrArray,
              &ServiceInstancePtr->CapabilityRecordPtr))
            {
              RetVal = E_NOT_OK;
            }
          }

          if(E_OK == RetVal)
          {
            /* Search the client in the list of subscribed clients */
            TmpClientPtr = Sd_FindClientInList(TmpEventHandlerPtr, SavedAddrPtr, &EndpointAddrTcp, &EndpointAddrUdp, FALSE);

            if(NULL_PTR == TmpClientPtr)
            {
              /* The client subscribed the first time, add the client to the list */
              TmpClientPtr = Sd_AddClientToList(TmpEventHandlerPtr, SavedAddrPtr);
            }

            if(NULL_PTR != TmpClientPtr)
            {
              /* Save all parameters and endpoints, the processing will be done in the next main function cycle */
              TmpClientPtr->RequestedTTL = RxTTL;
              TmpClientPtr->RxReserved = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+12]) << 8) |
                ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+13]));

              if(Sd_EventHandlerUsesUdp(TmpEventHandlerPtr))
              {
                RetVal |= Sd_SaveEndpoint(ServiceInstancePtr->RootInstancePtr, &EndpointAddrUdp,
                  SD_ENDPOINT_TYPE_UDP, &TmpClientPtr->UdpEndpointPtr);
              }

              if(Sd_EventHandlerUsesTcp(TmpEventHandlerPtr))
              {
                RetVal |= Sd_SaveEndpoint(ServiceInstancePtr->RootInstancePtr, &EndpointAddrTcp,
                  SD_ENDPOINT_TYPE_TCP, &TmpClientPtr->TcpEndpointPtr);
              }

              if(0 == RxTTL)
              {
                /* SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP */
                RetVal |= Sd_AddEventToRingBuffer(ServiceInstancePtr->RootInstancePtr->RxEventListPtr,
                  TmpEventHandlerPtr, TmpClientPtr,
                  (Sd_ServerEventgroupEventType)(SD_SERVER_EVENT_EVENTGROUP_STOP_SUBSCRIBE | MulticastMessage));
              }
              else
              {
                /* SD_ENTRY_SUBSCRIBE_EVENTGROUP */
                RetVal |= Sd_AddEventToRingBuffer(ServiceInstancePtr->RootInstancePtr->RxEventListPtr,
                  TmpEventHandlerPtr, TmpClientPtr,
                  (Sd_ServerEventgroupEventType)(SD_SERVER_EVENT_EVENTGROUP_SUBSCRIBE | MulticastMessage));
              }

              Sd_TriggerStateMachineRun(ServiceInstancePtr->RootInstancePtr); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            }
            else
            {
              /* Maximum amount of clients reached, not able to process this request */
              RetVal = E_NOT_OK;
            }
          }
        }
        else
        {
          /* Not all required endpoints are present */
          RetVal = E_NOT_OK;
        }
      }
      else if((RxEventGroupId == TmpEventHandlerPtr->EventGroupId) &&
        (SD_SERVER_SERVICE_DOWN == ServiceInstancePtr->ServerInstancePtr->DynamicDataPtr->StateSWC))
      {
        EventGroupConfigured = TRUE;

        /* Send a SubscribeEventgroupNack if the service instance is not ready */
        RetVal = E_NOT_OK;
      }
      else
      {
        /* Wrong EventGroup, nothing to do */
      }
    }

    /* Send a NACK if we were not able to process the SUBSCRIBE, if no endpoint option was attached or if the eventgroup was not configured */
    if((E_OK != RetVal) || (FALSE == EventGroupConfigured))
    {
      uint32 AdditionalDelay = 0;
      RxServiceId = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+4]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+5]));
      RxInstanceId = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+6]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+7]));
      RxMajorVersion = PduInfoPtr->SduDataPtr[IndexEntry+8];
      RxReservedField = (uint16)((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+12]) << 8) | ((uint16)(PduInfoPtr->SduDataPtr[IndexEntry+13]));

      if(TRUE == MulticastMessage)
      {
        /* Add additional delay to NACK message */
        if(TRUE == EventGroupConfigured)
        {
          AdditionalDelay = Sd_GetRandomNrInRangeForResponse(TmpEventHandlerPtr->TimerRef->RequestResponseMinDelay,
            TmpEventHandlerPtr->TimerRef->RequestResponseMaxDelay, TRUE);
        }
        else
        {
          AdditionalDelay = Sd_GetRandomNrInRangeForResponse(ServiceInstancePtr->ServerInstancePtr->TimerRef->RequestResponseMinDelay,
            ServiceInstancePtr->ServerInstancePtr->TimerRef->RequestResponseMaxDelay, TRUE);
        }
      }

      Sd_AddEventGroupNackEntryToList(ServiceInstancePtr->RootInstancePtr->SendEntriesListPtr, ServiceInstancePtr,
        RxServiceId, RxInstanceId, RxMajorVersion, RxReservedField, RxEventGroupId, SavedAddrPtr, AdditionalDelay);
    }
  }
} /* PRQA S 6010, 6030, 6050, 6060, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_ProcessServerOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
/* PRQA S 3673 8 */ /* MD_Sd_16.7_3673 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ProcessServerOption(
  SD_P2CONST(PduInfoType) PduInfoPtr,
  uint8 IndexOfOption,
  uint8 NrOfOptions,
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrUdpPtr,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrTcpPtr,
  SD_P2VAR(Sd_ConfigOptionStringType) ConfigOptionPtrArrayPtr)
{
  Std_ReturnType RetVal = E_OK;
  uint8 CurrentOption = IndexOfOption;
  Sd_OptionType OptionType;
  Sd_L4ProtocolType OptionL4Proto = SD_L4PROTOCOL_NONE;
  uint16 AddrType;
  Sd_SockAddrContainerType LocalAddr;
  Sd_SockAddrContainerType DefaultRouter;
  uint8 NetmaskCidr = 0;

  /* Stop processing of the message if the header indexes more options than attached */
  if(Sd_GetNrOfOptionsInList() < (IndexOfOption + NrOfOptions))
  {
    RetVal = E_NOT_OK;
  }

  /* Process all consecutive options */
  while((E_OK == RetVal) && ((IndexOfOption + NrOfOptions) > CurrentOption))
  {
    /* Read the option information */
    OptionType = (Sd_OptionType)PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption) + SD_SIZE_OF_OPTION_LENGTH_FIELD];

    /* Differentiate between service- and eventgroup entry */
    if(NULL_PTR == EventHandlerPtr)
    {
      /* SD_ENTRY_FIND_SERVICE */

      switch(OptionType)
      {
        case SD_OPTION_CONFIGURATION:
          /* Check if configuration option is valid */
          RetVal = Sd_CheckConfigOption(&PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption)], ConfigOptionPtrArrayPtr);
          break;

        case SD_OPTION_IPV4_ENDPOINT:
        case SD_OPTION_IPV6_ENDPOINT:
        case SD_OPTION_IPV4_MULTICAST:
        case SD_OPTION_IPV6_MULTICAST:
          /* Endpoint options are not allowed for Findservice entries and shall be ignored */
          break;

        default:
          /* Unknown option fields shall be ignored */
          break;
      }
    }
    else
    {
      /* SD_ENTRY_SUBSCRIBE_EVENTGROUP or SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP */
      AddrType = SOAD_AF_INVALID;

      switch(OptionType)
      {
        case SD_OPTION_CONFIGURATION:
          /* Check if configuration option is valid */
          RetVal = Sd_CheckConfigOption(&PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption)], ConfigOptionPtrArrayPtr);
          break;

        case SD_OPTION_IPV4_MULTICAST:
        case SD_OPTION_IPV6_MULTICAST:
          /* Multicast endpoint options are not allowed for SubscribeEventgroup or StopSubscribeEventgroup entries */
          /* Ignore this referenced option */
          break;

        case SD_OPTION_IPV6_ENDPOINT:
          /* Read the L4 protocol */
          OptionL4Proto = (Sd_L4ProtocolType)PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption) + SD_IPV6_ENDPOINT_L4PROTO_OFFSET];
          AddrType = SOAD_AF_INET6;
          break;

        case SD_OPTION_IPV4_ENDPOINT:
          /* Read the L4 protocol */
          OptionL4Proto = (Sd_L4ProtocolType)PduInfoPtr->SduDataPtr[Sd_GetOptionIndex(CurrentOption) + SD_IPV4_ENDPOINT_L4PROTO_OFFSET];
          AddrType = SOAD_AF_INET;
          break;

        default:
          /* Unknown option fields shall be ignored */
          break;
      }

      if(SOAD_AF_INVALID != AddrType)
      {
        /* Differentiate between UDP and TCP endpoints */
        switch(OptionL4Proto)
        {
        case SD_L4PROTOCOL_UDP:
            /* Check if the UDP address was already configured by another endpoint */
            if(SOAD_AF_INVALID == EndpointAddrUdpPtr->family)
            {
              /* Read the address transported in the endpoint */
              RetVal = Sd_ReadEndpointOption(AddrType, PduInfoPtr->SduDataPtr, Sd_GetOptionIndex(CurrentOption), EndpointAddrUdpPtr);
            }
            else
            {
              /* This entry references multiple times the same type of endpoint option. Reject the subscription */
              RetVal = E_NOT_OK;
            }
            break;

          case SD_L4PROTOCOL_TCP:
            /* Check if the TCP address was already configured by another endpoint */
            if(SOAD_AF_INVALID == EndpointAddrTcpPtr->family)
            {
              /* Read the address transported in the endpoint */
              RetVal = Sd_ReadEndpointOption(AddrType, PduInfoPtr->SduDataPtr, Sd_GetOptionIndex(CurrentOption), EndpointAddrTcpPtr);
            }
            else
            {
              /* This entry references multiple times the same type of endpoint option. Reject the subscription */
              RetVal = E_NOT_OK;
            }
            break;

          default:
            /* Undefined protocol type. Reject the subscription */
              RetVal = E_NOT_OK;
            break;
        }

        /* Check if the endpoint address is part of the subnet */
        if((SOAD_AF_INVALID != EndpointAddrUdpPtr->family) && Sd_EventHandlerUsesUdp(EventHandlerPtr))
        {
          /* Get the local IP address and the subnet mask */
          /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
          RetVal |= SoAd_GetLocalAddr(EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->UdpSoConListPtr[0],
            (SD_P2VAR(SoAd_SockAddrType))&LocalAddr, &NetmaskCidr, (SD_P2VAR(SoAd_SockAddrType))&DefaultRouter);

          /* Check if the endpoint address is part of the subnet */
          /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
          /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
          if((E_OK == RetVal) && (TRUE != Sd_SockAddrWithinSubnet((SD_P2VAR(SoAd_SockAddrType))&LocalAddr,
            (SD_P2VAR(SoAd_SockAddrType))EndpointAddrUdpPtr, NetmaskCidr)))
          {
            /* The endpoint references an IP address outside the configured subnet, do not consider this endpoint */
            EndpointAddrUdpPtr->family = SOAD_AF_INVALID;
          }
        }
        if((SOAD_AF_INVALID != EndpointAddrTcpPtr->family) && Sd_EventHandlerUsesTcp(EventHandlerPtr))
        {
          /* Get the local IP address and the subnet mask */
          /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
          RetVal |= SoAd_GetLocalAddr(EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->TcpSoConListPtr[0],
            (SD_P2VAR(SoAd_SockAddrType))&LocalAddr, &NetmaskCidr, (SD_P2VAR(SoAd_SockAddrType))&DefaultRouter);

          /* Check if the endpoint address is part of the subnet */
          /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
          /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
          if((E_OK == RetVal) && (TRUE != Sd_SockAddrWithinSubnet((SD_P2VAR(SoAd_SockAddrType))&LocalAddr,
            (SD_P2VAR(SoAd_SockAddrType))EndpointAddrTcpPtr, NetmaskCidr)))
          {
            /* The endpoint references an IP address outside the configured subnet, do not consider this endpoint */
            EndpointAddrTcpPtr->family = SOAD_AF_INVALID;
          }
        }
      }
    }

    CurrentOption++;
  }

  return RetVal;
} /* PRQA S 6010, 6030, 6060, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_UpdateServerServiceSoCons()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_UpdateServerServiceSoCons(
  SD_P2CONST(Sd_RxEventType) EventPtr)
{
  Std_ReturnType RetVal = E_OK;
  boolean useTriggerTransmit = FALSE;
  Sd_SockAddrContainerType RemoteAddr;
  SoAd_SoConIdType AssignedSoConId = SOAD_INV_SO_CON_ID;

  if((SD_SERVER_EVENT_EVENTGROUP_SUBSCRIBE == EventPtr->Event) ||
    (SD_SERVER_EVENT_EVENTGROUP_SUBSCRIBE_MULTI == EventPtr->Event))
  {
    if(SD_EVENT_HANDLER_CLIENT_STATE_UNSUBSCRIBED == EventPtr->ClientPtr->ClientState)
    {
      /* The client subscribed for the first time */
      /* Check if all required endpoints are present */
      if((Sd_EventHandlerUsesTcp(EventPtr->EventHandlerPtr) && (NULL_PTR == EventPtr->ClientPtr->TcpEndpointPtr)) ||
        (Sd_EventHandlerUsesUdp(EventPtr->EventHandlerPtr) && (NULL_PTR == EventPtr->ClientPtr->UdpEndpointPtr)))
      {
        /* The client attached not all required endpoints, reject the subscription */
        RetVal = E_NOT_OK;
      }
      else
      {
        /* All mandatory endpoints are present, check if the client is already configured */

        if((!Sd_EventHandlerUsesTcp(EventPtr->EventHandlerPtr)) && (!Sd_EventHandlerUsesUdp(EventPtr->EventHandlerPtr)))
        {
          /* The EventHandler is a pure multicast EventHandler */
          RetVal |= SoAd_EnableSpecificRouting(EventPtr->EventHandlerPtr->MulticastRefPtr->ActivationRef, EventPtr->EventHandlerPtr->MulticastRefPtr->SoConId);

          EventPtr->EventHandlerPtr->DynamicDataPtr->NrOfClients++;
          EventPtr->EventHandlerPtr->DynamicDataPtr->NrOfClientsUdp++;
        }
        else
        {
          if(Sd_EventHandlerUsesTcp(EventPtr->EventHandlerPtr))
          {
            /* Check if the client has already established a TCP connection */
            /* PRQA S 0310 4 */ /* MD_Sd_11.4_0310 */
            /* PRQA S 0311 3 */ /* MD_Sd_11.5_0311 */
            RetVal |= SoAd_SetUniqueRemoteAddr(
              EventPtr->EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->TcpSoConListPtr[0],
              (SD_P2VAR(SoAd_SockAddrType))EventPtr->ClientPtr->TcpEndpointPtr, &AssignedSoConId);

            if(E_OK == RetVal)
            {
              /* Check if the SocketConnection is online */
              if(SD_SOCON_MODE_ONLINE == Sd_GetSoConMode(AssignedSoConId))
              {
                /* The client TCP IP address is already configured, enable the TCP routing group */
                RetVal |= SoAd_EnableSpecificRouting(EventPtr->EventHandlerPtr->TcpRefPtr->ActivationRef, AssignedSoConId);
                Sd_IncreaseActivationCount(EventPtr->EventHandlerPtr->TcpRefPtr, AssignedSoConId);

                /* PRQA S 0715 2 */ /* MD_MSR_1.1_0715 */
                if(SOAD_INV_ROUT_GRP_ID != EventPtr->EventHandlerPtr->TcpRefPtr->TriggerRef)
                {
                  useTriggerTransmit = TRUE;
                }

                /* Save the state of the client */
                EventPtr->ClientPtr->AssignedTcpSoConId = AssignedSoConId;
                EventPtr->EventHandlerPtr->DynamicDataPtr->NrOfClients++;
              }
            }

            /* Check if the subscription was successful */
            if(SOAD_INV_SO_CON_ID == EventPtr->ClientPtr->AssignedTcpSoConId)
            {
              /* Reject the subscription */
              RetVal = E_NOT_OK;
            }
          }

          if(Sd_EventHandlerUsesUdp(EventPtr->EventHandlerPtr) && (E_OK == RetVal))
          {
            /* Configure a SocketConnection with the client endpoint address if it is not already configured */
            if(SOAD_INV_SO_CON_ID == EventPtr->ClientPtr->AssignedUdpSoConId)
            {
              /* PRQA S 0310 4 */ /* MD_Sd_11.4_0310 */
              /* PRQA S 0311 3 */ /* MD_Sd_11.5_0311 */
              RetVal |= SoAd_SetUniqueRemoteAddr(
                EventPtr->EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->UdpSoConListPtr[0],
                (SD_P2VAR(SoAd_SockAddrType))EventPtr->ClientPtr->UdpEndpointPtr, &AssignedSoConId);

              if(E_OK == RetVal)
              {
                /* Each EventHandler which requires the SocketConnection opens it in order to indicate the dependency */
                RetVal |= SoAd_OpenSoCon(AssignedSoConId);

                /* PRQA S 0715 2 */ /* MD_MSR_1.1_0715 */
                if(SD_EVENT_HANDLER_STATE_MULTICAST_SUBSCRIPTION != EventPtr->EventHandlerPtr->DynamicDataPtr->StateMachine)
                {
                  RetVal |= SoAd_EnableSpecificRouting(EventPtr->EventHandlerPtr->UdpRefPtr->ActivationRef, AssignedSoConId);
                  Sd_IncreaseActivationCount(EventPtr->EventHandlerPtr->UdpRefPtr, AssignedSoConId);
                }

                /* PRQA S 0715 2 */ /* MD_MSR_1.1_0715 */
                if(SOAD_INV_ROUT_GRP_ID != EventPtr->EventHandlerPtr->UdpRefPtr->TriggerRef)
                {
                  useTriggerTransmit = TRUE;
                }

                EventPtr->ClientPtr->AssignedUdpSoConId = AssignedSoConId;
                EventPtr->EventHandlerPtr->DynamicDataPtr->NrOfClients++;
                EventPtr->EventHandlerPtr->DynamicDataPtr->NrOfClientsUdp++;
              }
            }

            /* Check if we were able to add the client to the system */
            if(SOAD_INV_SO_CON_ID == EventPtr->ClientPtr->AssignedUdpSoConId)
            {
              /* The client address could not be configured, reject the subscription. \trace CREQ-121019 */
              /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
              Sd_DemOutOfRes(EventPtr->EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->RootInstancePtr->EOutOfResId);
              RetVal = E_NOT_OK;
            }
          }

          if((E_OK == RetVal) && (TRUE == useTriggerTransmit))
          {
            /* The client subscribed the first time, save the request in the trigger transmit list */
            (void)Sd_AddTriggerTransmitToRingBuffer(EventPtr);
          }
        }

        if(E_OK == RetVal)
        {
          /* The client subscribed successfully */
          EventPtr->ClientPtr->ClientState = SD_EVENT_HANDLER_CLIENT_STATE_SUBSCRIBED;
          EventPtr->ClientPtr->NrOfReferences++;
        }
      }
    }
    else  /* SD_EVENT_HANDLER_CLIENT_STATE_UNSUBSCRIBED != EventPtr->ClientPtr->ClientState */
    {
      /* The client was already subscribed, check if the configuration and the endpoints are consistent */
      if(SOAD_INV_SO_CON_ID != EventPtr->ClientPtr->AssignedTcpSoConId)
      {
        /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
        RetVal |= SoAd_GetRemoteAddr(EventPtr->ClientPtr->AssignedTcpSoConId, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr);
        /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
        if(((TRUE == Sd_SockAddrIsEqual((SD_P2VAR(SoAd_SockAddrType))EventPtr->ClientPtr->TcpEndpointPtr, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr)) &&
          (E_OK == RetVal)))
        {
          /* The client attached the correct endpoint option */
        }
        else
        {
          /* The attached endpoint does not match to the configuration */
          RetVal = E_NOT_OK;
        }
      }

      if(SOAD_INV_SO_CON_ID != EventPtr->ClientPtr->AssignedUdpSoConId)
      {
        /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
        RetVal |= SoAd_GetRemoteAddr(EventPtr->ClientPtr->AssignedUdpSoConId, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr);
        /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
        if(((TRUE == Sd_SockAddrIsEqual((SD_P2VAR(SoAd_SockAddrType))EventPtr->ClientPtr->UdpEndpointPtr, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr)) &&
          (E_OK == RetVal)))
        {
          /* The client attached the correct endpoint option */
        }
        else
        {
          /* The attached endpoint does not match to the configuration */
          RetVal = E_NOT_OK;
        }
      }
    }
  }
  else  /* ((SD_SERVER_EVENT_EVENTGROUP_STOP_SUBSCRIBE == EventPtr->Event) || (SD_SERVER_EVENT_EVENTGROUP_STOP_SUBSCRIBE_MULTI == EventPtr->Event)) */
  {
    RetVal = E_NOT_OK;
  }

  /* Check if the configuration was successful */
  if(E_OK == RetVal)
  {
    /* Update the client */
    Sd_SetTimerOffset(EventPtr->ClientPtr->SubscribedUntil,
      EventPtr->ClientPtr->RequestedTTL * 1000,
      EventPtr->EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->RootInstancePtr);
  }
  else
  {
    /* Not able to configure all mandatory endpoints, undo the changes and remove the client */
    Sd_RemoveClientFromList(EventPtr->EventHandlerPtr, EventPtr->ClientPtr);
  }

  return RetVal;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_AddClientToList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(SD_P2VAR(Sd_ClientListType), SD_CODE) Sd_AddClientToList(
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2VAR(Sd_SockAddrContainerType) SavedAddrPtr)
{
  uint16 ClientIdx;
  SD_P2VAR(Sd_ClientListType) TmpClientPtr = NULL_PTR;
  boolean FoundFreeSlot = FALSE;

  /* Search for the next free slot */
  ClientIdx = EventHandlerPtr->MaxNrHandledClients;
  while(0 < ClientIdx)
  {
    ClientIdx--;
    TmpClientPtr = &EventHandlerPtr->ClientListPtr[ClientIdx];

    if(SD_EVENT_HANDLER_CLIENT_STATE_INVALID == TmpClientPtr->ClientState)
    {
      FoundFreeSlot = TRUE;
      TmpClientPtr->AddrPtr = SavedAddrPtr;
      TmpClientPtr->AssignedTcpSoConId = SOAD_INV_SO_CON_ID;
      TmpClientPtr->AssignedUdpSoConId = SOAD_INV_SO_CON_ID;
      TmpClientPtr->ClientState = SD_EVENT_HANDLER_CLIENT_STATE_UNSUBSCRIBED;
      TmpClientPtr->NrOfReferences = 0;
      TmpClientPtr->RequestedTTL = 0;
      TmpClientPtr->RxReserved = 0;
      Sd_ResetTimerToZero(TmpClientPtr->SubscribedUntil); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      TmpClientPtr->TcpEndpointPtr = NULL_PTR;
      TmpClientPtr->UdpEndpointPtr = NULL_PTR;
      break;
    }
  }

  if((FALSE == FoundFreeSlot))
  {
    /* No free slot found. Return a NULL_PTR */
    /* The amount of manageable clients corresponds to the amount of configured SoAdSocketConnections for this EventHandler */
    TmpClientPtr = NULL_PTR;
    Sd_CallDetReportError(SD_API_ID_INTERNAL_FUNCTION, SD_E_LIST_FULL);  /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  return TmpClientPtr;
}

/**********************************************************************************************************************
 *  Sd_RemoveClientFromList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_RemoveClientFromList(
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2VAR(Sd_ClientListType) ClientPtr)
{
  SD_P2VAR(uint8) ActivationCntPtr;

  /* Undo reset the configuration */
  if((SOAD_INV_SO_CON_ID == ClientPtr->AssignedTcpSoConId) && (SOAD_INV_SO_CON_ID == ClientPtr->AssignedUdpSoConId) &&
    (SD_EVENT_HANDLER_CLIENT_STATE_SUBSCRIBED == ClientPtr->ClientState))
  {
    /* The client was subscribed for a pure multicast event group */
    EventHandlerPtr->DynamicDataPtr->NrOfClients--;
    EventHandlerPtr->DynamicDataPtr->NrOfClientsUdp--;
  }

  if(SOAD_INV_SO_CON_ID != ClientPtr->AssignedTcpSoConId)
  {
    /* Get the activation count of the corresponding SoConId */
    ActivationCntPtr = Sd_GetActivationCount(EventHandlerPtr->TcpRefPtr, ClientPtr->AssignedTcpSoConId);

    if((NULL_PTR != ActivationCntPtr) && (0 != *ActivationCntPtr))
    {
      /* Decrement the activation counter */
      (*ActivationCntPtr)--;

      /* Deactivate the routing group if no other instance of the client is active */
      if(0 == *ActivationCntPtr)
      {
        (void)SoAd_DisableSpecificRouting(EventHandlerPtr->TcpRefPtr->ActivationRef, ClientPtr->AssignedTcpSoConId);
      }
    }

    EventHandlerPtr->DynamicDataPtr->NrOfClients--;
    ClientPtr->AssignedTcpSoConId = SOAD_INV_SO_CON_ID;
  }

  if(SOAD_INV_SO_CON_ID != ClientPtr->AssignedUdpSoConId)
  {
    /* Get the activation count of the corresponding SoConId */
    ActivationCntPtr = Sd_GetActivationCount(EventHandlerPtr->UdpRefPtr, ClientPtr->AssignedUdpSoConId);

    if((NULL_PTR != ActivationCntPtr) && (0 != *ActivationCntPtr))
    {
      /* Decrement the activation counter */
      (*ActivationCntPtr)--;

      /* Deactivate the routing group if no other instance of the client is active */
      if(0 == *ActivationCntPtr)
      {
        (void)SoAd_DisableSpecificRouting(EventHandlerPtr->UdpRefPtr->ActivationRef, ClientPtr->AssignedUdpSoConId);
      }
    }

    /* Close the SocketConnection. (The OpenCount is handled by SoAd) */
    (void)SoAd_CloseSoCon(ClientPtr->AssignedUdpSoConId, FALSE);
    EventHandlerPtr->DynamicDataPtr->NrOfClients--;
    EventHandlerPtr->DynamicDataPtr->NrOfClientsUdp--;
    ClientPtr->AssignedUdpSoConId = SOAD_INV_SO_CON_ID;
  }

  if((0 != ClientPtr->NrOfReferences) && (SD_EVENT_HANDLER_CLIENT_STATE_SUBSCRIBED == ClientPtr->ClientState))
  {
    ClientPtr->NrOfReferences--;
  }
  if(0 == ClientPtr->NrOfReferences)
  {
    /* The client is not referenced by another event. Remove it from the list */
    ClientPtr->ClientState = SD_EVENT_HANDLER_CLIENT_STATE_INVALID;
  }
  else
  {
    /* The client is referenced by another event. Keep the information in the list */
    ClientPtr->ClientState = SD_EVENT_HANDLER_CLIENT_STATE_UNSUBSCRIBED;
  }
}/* PRQA S 2006, 6010 */ /* MD_MSR_14.7, MD_MSR_STPTH */

/**********************************************************************************************************************
 *  Sd_FindClientInList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(SD_P2VAR(Sd_ClientListType), SD_CODE) Sd_FindClientInList(
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2CONST(Sd_SockAddrContainerType) AddrPtr,
  SD_P2CONST(Sd_SockAddrContainerType) TcpEndpointPtr,
  SD_P2CONST(Sd_SockAddrContainerType) UdpEndpointPtr,
  boolean RebootDetected)
{
  boolean FoundClient = FALSE, TcpMatch, UdpMatch;
  Std_ReturnType RetVal;
  uint16 ClientIdx;
  Sd_SockAddrContainerType RemoteAddr;
  SD_P2VAR(Sd_ClientListType) TmpClientPtr = NULL_PTR;

  /* Check if the client is part of the list */
  ClientIdx = EventHandlerPtr->MaxNrHandledClients;
  while(0 < ClientIdx)
  {
    ClientIdx--;
    TmpClientPtr = &EventHandlerPtr->ClientListPtr[ClientIdx];

    if(SD_EVENT_HANDLER_CLIENT_STATE_INVALID != TmpClientPtr->ClientState)
    {
      /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
      /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
      if(TRUE == Sd_SockAddrIsEqual((SD_P2VAR(SoAd_SockAddrType))(TmpClientPtr->AddrPtr), (SD_P2VAR(SoAd_SockAddrType))AddrPtr))
      {
        /* Found the corresponding remote address */
        if(TRUE == RebootDetected)
        {
          /* Set the SubscribedUntil time to 0 in order to remove the client in the next main function cycle */
          Sd_ResetTimerToZeroTrigger(TmpClientPtr->SubscribedUntil,
            EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->RootInstancePtr);
        }
        else
        {
          TcpMatch = FALSE;
          UdpMatch = FALSE;

          /* Check the attached TCP endpoint addresses. Ignore if the endpoint is redundant */
          if((SOAD_AF_INVALID != TcpEndpointPtr->family) && Sd_EventHandlerUsesTcp(EventHandlerPtr))
          {
            if(SOAD_INV_SO_CON_ID != TmpClientPtr->AssignedTcpSoConId)
            {
              /* The client is already configured for TCP. Check the remote address. */
              TcpMatch = FALSE;

              /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
              RetVal = SoAd_GetRemoteAddr(TmpClientPtr->AssignedTcpSoConId, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr);

              if(E_OK == RetVal)
              {
                /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
                /* PRQA S 0311 2 */ /* MD_Sd_11.5_0311 */
                /* PRQA S 0715 2 */ /* MD_MSR_1.1_0715 */
                if(TRUE == Sd_SockAddrIsEqual((SD_P2VAR(SoAd_SockAddrType))(&RemoteAddr), (SD_P2VAR(SoAd_SockAddrType))TcpEndpointPtr))
                {
                  TcpMatch = TRUE;
                }
              }
            }
            else if(NULL_PTR != TmpClientPtr->TcpEndpointPtr)
            {
              /* The client is not (jet) configured for TCP, but has a temporary endpoint. Check it. */
              TcpMatch = FALSE;

              /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
              /* PRQA S 0311 2 */ /* MD_Sd_11.5_0311 */
              if(TRUE == Sd_SockAddrIsEqual((SD_P2VAR(SoAd_SockAddrType))(&TmpClientPtr->TcpEndpointPtr->Addr),
                (SD_P2VAR(SoAd_SockAddrType))TcpEndpointPtr))
              {
                TcpMatch = TRUE;
              }
            }
            else
            {
              /* The client contains no information */
            }
          }
          else if((!Sd_EventHandlerUsesTcp(EventHandlerPtr)) || (SD_EVENT_HANDLER_CLIENT_STATE_SUBSCRIBED == TmpClientPtr->ClientState))
          {
            TcpMatch = TRUE;
          }
          else
          {
            TcpMatch = FALSE;
          }

          /* Check the attached UDP endpoint addresses. Ignore if the endpoint is redundant */
          if((SOAD_AF_INVALID != UdpEndpointPtr->family) && Sd_EventHandlerUsesUdp(EventHandlerPtr))
          {
            if(SOAD_INV_SO_CON_ID != TmpClientPtr->AssignedUdpSoConId)
            {
              /* The client is already configured for UDP. Check the remote address. */
              UdpMatch = FALSE;

              /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
              RetVal = SoAd_GetRemoteAddr(TmpClientPtr->AssignedUdpSoConId, (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr);

              if(E_OK == RetVal)
              {
                /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
                /* PRQA S 0311 2 */ /* MD_Sd_11.5_0311 */
                /* PRQA S 0715 2 */ /* MD_MSR_1.1_0715 */
                if(TRUE == Sd_SockAddrIsEqual((SD_P2VAR(SoAd_SockAddrType))(&RemoteAddr), (SD_P2VAR(SoAd_SockAddrType))UdpEndpointPtr))
                {
                  UdpMatch = TRUE;
                }
              }
            }
            else if(NULL_PTR != TmpClientPtr->UdpEndpointPtr)
            {
              /* The client is not (jet) configured for UDP, but has a temporary endpoint. Check it. */
              UdpMatch = FALSE;

              /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
              /* PRQA S 0311 2 */ /* MD_Sd_11.5_0311 */
              if(TRUE == Sd_SockAddrIsEqual((SD_P2VAR(SoAd_SockAddrType))(&TmpClientPtr->UdpEndpointPtr->Addr),
                (SD_P2VAR(SoAd_SockAddrType))UdpEndpointPtr))
              {
                UdpMatch = TRUE;
              }
            }
            else
            {
              /* The client contains no information */
            }
          }
          else if((!Sd_EventHandlerUsesUdp(EventHandlerPtr)) || (SD_EVENT_HANDLER_CLIENT_STATE_SUBSCRIBED == TmpClientPtr->ClientState))
          {
            UdpMatch = TRUE;
          }
          else
          {
            UdpMatch = FALSE;
          }

          if((TRUE == TcpMatch) && (TRUE == UdpMatch))
          {
            FoundClient = TRUE;
            break;
          }
        }
      }
    }
  }

  if(TRUE == FoundClient)
  {
    /* Return the TmpClientPtr */
  }
  else
  {
    /* The client was not subscribed */
    TmpClientPtr = NULL_PTR;
  }

  return TmpClientPtr;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_GetActivationCount()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(SD_P2VAR(uint8), SD_CODE) Sd_GetActivationCount(
  SD_P2CONST(Sd_EventHandlerUnicastType) EventHandlerUnicastPtr,
  SoAd_SoConIdType SoConId)
{
  boolean SoConSaved = FALSE;
  uint16 ActivationIdx;
  SD_P2VAR(uint8) NrOfActivationsPtr = NULL_PTR;

  if(NULL_PTR != EventHandlerUnicastPtr)
  {
    /* Check if the SoConId is already part of the map */
    ActivationIdx = EventHandlerUnicastPtr->NrSoConActivationMaps;
    while(0 < ActivationIdx)
    {
      ActivationIdx--;

      if(SoConId == EventHandlerUnicastPtr->SoConActivationMapPtr[ActivationIdx].SoConId)
      {
        SoConSaved = TRUE;
        break;
      }
    }

    if(FALSE == SoConSaved)
    {
      /* Search for an unused slot to save the SocketConnectionId */
      ActivationIdx = EventHandlerUnicastPtr->NrSoConActivationMaps;
      while(0 < ActivationIdx)
      {
        ActivationIdx--;

        if(SOAD_INV_SO_CON_ID == EventHandlerUnicastPtr->SoConActivationMapPtr[ActivationIdx].SoConId)
        {
          EventHandlerUnicastPtr->SoConActivationMapPtr[ActivationIdx].SoConId = SoConId;
          EventHandlerUnicastPtr->SoConActivationMapPtr[ActivationIdx].NrOfActivations = 0;
          SoConSaved = TRUE;
          break;
        }
      }
    }

    if(TRUE == SoConSaved)
    {
      NrOfActivationsPtr = &EventHandlerUnicastPtr->SoConActivationMapPtr[ActivationIdx].NrOfActivations;
    }
  }

  return NrOfActivationsPtr;
}

/**********************************************************************************************************************
 *  Sd_IncreaseActivationCount()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_IncreaseActivationCount(
  SD_P2CONST(Sd_EventHandlerUnicastType) EventHandlerUnicastPtr,
  SoAd_SoConIdType SoConId)
{
  SD_P2VAR(uint8) NrOfActivationsPtr;

  NrOfActivationsPtr = Sd_GetActivationCount(EventHandlerUnicastPtr, SoConId);

  /* Increase the activation counter */
  if(NULL_PTR != NrOfActivationsPtr)
  {
    (*NrOfActivationsPtr)++;
  }
}

/**********************************************************************************************************************
 *  Sd_ResetActivationCount()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_ResetActivationCount(
  SD_P2CONST(Sd_EventHandlerUnicastType) EventHandlerUnicastPtr)
{
  uint16 ActivationIdx;

  if(NULL_PTR != EventHandlerUnicastPtr)
  {
    ActivationIdx = EventHandlerUnicastPtr->NrSoConActivationMaps;
    while(0 < ActivationIdx)
    {
      ActivationIdx--;

      /* Reset the number of activations */
      EventHandlerUnicastPtr->SoConActivationMapPtr[ActivationIdx].NrOfActivations = 0;
    }
  }
}

/**********************************************************************************************************************
 *  Sd_AddEventToRingBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_AddEventToRingBuffer(
  SD_P2VAR(Sd_RxEventListType) EventListPtr,
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  SD_P2VAR(Sd_ClientListType) ClientPtr,
  Sd_ServerEventgroupEventType Event)
{
  Std_ReturnType EventSaved = E_NOT_OK;

  /* Check if the ring buffer is full */
  if(FALSE == EventListPtr->Full)
  {
    SD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* Save the received event */
    EventListPtr->RxEventPtr[EventListPtr->EndIdx].EventHandlerPtr = EventHandlerPtr;
    EventListPtr->RxEventPtr[EventListPtr->EndIdx].ClientPtr = ClientPtr;
    EventListPtr->RxEventPtr[EventListPtr->EndIdx].Event = Event;
    EventListPtr->EndIdx++;
    ClientPtr->NrOfReferences++;
    if(NULL_PTR != ClientPtr->TcpEndpointPtr)
    {
      ClientPtr->TcpEndpointPtr->NrOfReferences++;
    }
    if(NULL_PTR != ClientPtr->UdpEndpointPtr)
    {
      ClientPtr->UdpEndpointPtr->NrOfReferences++;
    }
    EventSaved = E_OK;

    /* Handle wrap around */
    if(EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->RootInstancePtr->MaxNrRxTxEntries <= EventListPtr->EndIdx)
    {
      EventListPtr->EndIdx = 0;
    }

    /* Check if the ring buffer is full */
    if(EventListPtr->EndIdx == EventListPtr->StartIdx)
    {
      EventListPtr->Full = TRUE;
    }

    SD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  else
  {
    /* The ringbuffer is full */
  }

  return EventSaved;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Sd_ReadFirstEventOfRingBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(boolean, SD_CODE) Sd_ReadFirstEventOfRingBuffer(
  SD_P2CONST(Sd_RxEventListType) EventListPtr,
  SD_P2VAR(SD_P2VAR(Sd_RxEventType)) EventPtrPtr)
{
  boolean EventRead = FALSE;

  /* Check if the ring buffer contains an element */
  if((EventListPtr->StartIdx != EventListPtr->EndIdx) || (TRUE == EventListPtr->Full))
  {
    /* Read the first element from of the buffer */
    *EventPtrPtr = &(EventListPtr->RxEventPtr[EventListPtr->StartIdx]);
    EventRead = TRUE;
  }
  else
  {
    /* The buffer contains no elements */
  }

  return EventRead;
}

/**********************************************************************************************************************
 *  Sd_RemoveFirstEventFromRingBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_RemoveFirstEventFromRingBuffer(
  SD_P2CONST(Sd_InstanceType) InstancePtr)
{
  SD_P2VAR(Sd_RxEventListType) EventListPtr = InstancePtr->RxEventListPtr;

  /* Check if the ring buffer contains an element */
  if((EventListPtr->StartIdx != EventListPtr->EndIdx) || (TRUE == EventListPtr->Full))
  {
    /* Remove the references of the saved client and the endpoints */
    if(0 != EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->NrOfReferences)
    {
      EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->NrOfReferences--;
    }
    if(0 == EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->NrOfReferences)
    {
      /* The client is not referenced by another event. Remove it from the list */
      EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->ClientState = SD_EVENT_HANDLER_CLIENT_STATE_INVALID;
    }
    if(NULL_PTR != EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->TcpEndpointPtr)
    {
      Sd_RemoveEndpoint(EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->TcpEndpointPtr);
      if(0 == EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->TcpEndpointPtr->NrOfReferences)
      {
        EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->TcpEndpointPtr = NULL_PTR;
      }
    }
    if(NULL_PTR != EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->UdpEndpointPtr)
    {
      Sd_RemoveEndpoint(EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->UdpEndpointPtr);
      if(0 == EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->UdpEndpointPtr->NrOfReferences)
      {
        EventListPtr->RxEventPtr[EventListPtr->StartIdx].ClientPtr->UdpEndpointPtr = NULL_PTR;
      }
    }

    SD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* Remove the first element of the buffer */
    EventListPtr->StartIdx++;

    /* Handle wrap around */
    if(InstancePtr->MaxNrRxTxEntries <= EventListPtr->StartIdx)
    {
      EventListPtr->StartIdx = 0;
    }

    /* Check if the full flag has to be removed */
    if(TRUE == EventListPtr->Full)
    {
      EventListPtr->Full = FALSE;
    }

    SD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  else
  {
    /* The buffer contains no elements */
  }
}/* PRQA S 6010 */ /* MD_MSR_STPTH */

/**********************************************************************************************************************
 *  Sd_AddTriggerTransmitToRingBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_AddTriggerTransmitToRingBuffer(
  SD_P2CONST(Sd_RxEventType) RxEvent)
{
  Std_ReturnType RequestSaved = E_NOT_OK;

  /* Check if the ring buffer is full */
  if(FALSE == Sd_GetTriggerTransmitList().Full)
  {
    /* Save the requested trigger transmit */
    Sd_GetTriggerTransmitEvent(Sd_GetTriggerTransmitList().EndIdx).ClientPtr = RxEvent->ClientPtr;
    Sd_GetTriggerTransmitEvent(Sd_GetTriggerTransmitList().EndIdx).EventHandlerPtr = RxEvent->EventHandlerPtr;
    Sd_GetTriggerTransmitEvent(Sd_GetTriggerTransmitList().EndIdx).State = SD_TRIGGER_TRANSMIT_STATE_NEXT_CYCLE;

    Sd_GetTriggerTransmitList().EndIdx++;
    RequestSaved = E_OK;

    /* Handle wrap around */
    if(Sd_ConfigPtr->TriggerTransmitEventArraySize <= Sd_GetTriggerTransmitList().EndIdx)
    {
      Sd_GetTriggerTransmitList().EndIdx = 0;
    }

    /* Check if the ring buffer is full */
    if(Sd_GetTriggerTransmitList().EndIdx == Sd_GetTriggerTransmitList().StartIdx)
    {
      Sd_GetTriggerTransmitList().Full = TRUE;
    }
  }
  else
  {
    /* The ringbuffer is full */
  }

  return RequestSaved;
}

/**********************************************************************************************************************
 *  Sd_ReadFirstTriggerTransmitOfRingBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(boolean, SD_CODE) Sd_ReadFirstTriggerTransmitOfRingBuffer(
  SD_P2VAR(SD_P2VAR(Sd_TriggerTransmitType)) TriggerTransmitPtrPtr)
{
  boolean EventRead = FALSE;

  if(Sd_IsTriggerTransmitUsed())
  {
    /* Check if the ring buffer contains an element */
    if((Sd_GetTriggerTransmitList().StartIdx != Sd_GetTriggerTransmitList().EndIdx) || (TRUE == Sd_GetTriggerTransmitList().Full))
    {
      /* Read the first element from of the buffer */
      *TriggerTransmitPtrPtr = &Sd_GetTriggerTransmitEvent(Sd_GetTriggerTransmitList().StartIdx);
      EventRead = TRUE;
    }
    else
    {
      /* The buffer contains no elements */
    }
  }

  return EventRead;
}

/**********************************************************************************************************************
 *  Sd_RemoveFirstTriggerTransmitFromRingBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_RemoveFirstTriggerTransmitFromRingBuffer(void)
{
  /* The ring buffer will always contain at least one element */

  Sd_GetTriggerTransmitEvent(Sd_GetTriggerTransmitList().StartIdx).State = SD_TRIGGER_TRANSMIT_STATE_INVALID;

  /* Remove the first element of the buffer */
  Sd_GetTriggerTransmitList().StartIdx++;

  /* Handle wrap around */
  if(Sd_ConfigPtr->TriggerTransmitEventArraySize <= Sd_GetTriggerTransmitList().StartIdx)
  {
    Sd_GetTriggerTransmitList().StartIdx = 0;
  }

  /* Check if the full flag has to be removed */
  if(TRUE == Sd_GetTriggerTransmitList().Full)
  {
    Sd_GetTriggerTransmitList().Full = FALSE;
  }
}

/**********************************************************************************************************************
 *  Sd_UpdateServerStateMachine()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
LOCAL_INLINE FUNC(void, SD_CODE) Sd_UpdateServerStateMachine(
  SD_P2CONST(Sd_ServerServiceType) ServerServicePtr,
  Sd_ServerStateMachineType NewState,
  boolean ResetTimeToTriggerSend)
{
  /* Set the new state of the state machine */
  ServerServicePtr->DynamicDataPtr->StateMachine = NewState;

  /* Set a timer event */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_TriggerStateMachineRun(ServerServicePtr->RootServiceInstancePtr->RootInstancePtr);

  if(TRUE == ResetTimeToTriggerSend)
  {
    /* Reset the TimeToTriggerSend */
    Sd_ResetTimerToInvalid(ServerServicePtr->DynamicTimerPtr->TimeToTriggerSend); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}

/**********************************************************************************************************************
 *  Sd_UpdateEventHandlerStateMachine()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
LOCAL_INLINE FUNC(void, SD_CODE) Sd_UpdateEventHandlerStateMachine(
  SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr,
  Sd_EventHandlerStateMachineType NewState)
{
  /* Set the new state of the state machine */
  EventHandlerPtr->DynamicDataPtr->StateMachine = NewState;

  /* Set a timer event */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_TriggerStateMachineRun(EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->RootInstancePtr);
}

/**********************************************************************************************************************
 *  Sd_UpdateClientStateMachine()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
LOCAL_INLINE FUNC(void, SD_CODE) Sd_UpdateClientStateMachine(
  SD_P2CONST(Sd_ClientServiceType) ClientServicePtr,
  Sd_ClientStateMachineType NewState,
  boolean ResetTimeToTriggerSend)
{
  /* Set the new state of the state machine */
  ClientServicePtr->DynamicDataPtr->StateMachine = NewState;

  /* Set a timer event */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_TriggerStateMachineRun(ClientServicePtr->RootServiceInstancePtr->RootInstancePtr);

  if(TRUE == ResetTimeToTriggerSend)
  {
    /* Reset the TimeToTriggerSend */
    Sd_ResetTimerToInvalid(ClientServicePtr->DynamicTimerPtr->TimeToTriggerSend); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}

/**********************************************************************************************************************
 *  Sd_UpdateConsumedEventGroupStateMachine()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
LOCAL_INLINE FUNC(void, SD_CODE) Sd_UpdateConsumedEventGroupStateMachine(
  SD_P2CONST(Sd_ConsumedEventGroupType) ConsumedEventGroupPtr,
  Sd_ConsumedEventGroupStateMachineType NewState)
{
  /* Set the new state of the state machine */
  ConsumedEventGroupPtr->DynamicDataPtr->StateMachine = NewState;

  /* Set a timer event */
  /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
  Sd_TriggerStateMachineRun(ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->RootInstancePtr);
}

/**********************************************************************************************************************
 *  Sd_ProcessPendingMessages()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_ProcessPendingMessages(
  SD_P2VAR(Sd_SendEntriesListType) EntriesListPtr,
  boolean ForceTransmission)
{
  Std_ReturnType RetVal;
  SD_P2VAR(Sd_SendEntryType) TmpSendEntry;
  SD_P2CONST(Sd_SockAddrContainerType) ValidAddrPtr;
  uint16 SendEntryIdx, Iteration;
  uint16 FoundMsgIdx = 0;

  /* Iterate through the list till all messages are transmitted, but maximally NrOfSendEntries-times. */
  Iteration = EntriesListPtr->NrOfSendEntries;

  /* Iterate over all entries */
  while((0 != Iteration) && (0 != EntriesListPtr->NrOfSendEntries))
  {
    ValidAddrPtr = NULL_PTR;
    Iteration--;

    /* Find all messages which shall be sent to the same address and reference them in the temporary send-entries list. */

    /* Iterate over the list of send entries and search for a message which is ready to transmit */
    for(SendEntryIdx = 0; SendEntryIdx < EntriesListPtr->RootInstancePtr->MaxNrRxTxEntries; SendEntryIdx++)
    {
      RetVal = E_OK;

      TmpSendEntry = &EntriesListPtr->SendEntryPtr[SendEntryIdx];

      /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
      if((TRUE == TmpSendEntry->Valid) && (
        (TRUE == Sd_CheckIfTimerExceeded(TmpSendEntry->TimeToSend, TRUE)) ||
        (TRUE == ForceTransmission)))
      {
        /* Check if the selected entry is a (Stop)Subscribe entry */
        if(((SD_ENTRY_SUBSCRIBE_EVENTGROUP == TmpSendEntry->EntryType) ||
          (SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP == TmpSendEntry->EntryType)))
        {
          /* ... without an established TCP connection */
          /* PRQA S 3415 3 */ /* MD_Sd_12.4_3415 */
          if(Sd_ConsumedEventGroupUsesTcp(TmpSendEntry->ConsumedEventGroupPtr) &&
          (SOAD_INV_SO_CON_ID != TmpSendEntry->ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId) &&
          (SD_SOCON_MODE_ONLINE != Sd_GetSoConMode(TmpSendEntry->ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId)))
          {
            /* The TCP connection is not established. Skip the transmission of this message */
            RetVal = E_NOT_OK;
          }

          /* Check if the client service and/or event group is still requested */
          if(((SD_CLIENT_SERVICE_RELEASED == TmpSendEntry->ServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->StateSWC) ||
            (SD_CONSUMED_EVENTGROUP_RELEASED == TmpSendEntry->ConsumedEventGroupPtr->DynamicDataPtr->ServiceModeRequest) ||
            (SD_CLIENT_SERVICE_DOWN == TmpSendEntry->ServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->CurrentState)) &&
            (SD_ENTRY_SUBSCRIBE_EVENTGROUP == TmpSendEntry->EntryType))
          {
            /* The event group is not requested or not available any more. Remove the message */
            TmpSendEntry->Valid = FALSE;
            EntriesListPtr->NrOfSendEntries--;
            RetVal = E_NOT_OK;
          }
        }
        else
        {
          RetVal = E_OK;
        }

        if(E_OK == RetVal)
        {
          ValidAddrPtr = TmpSendEntry->AddrPtr;
          FoundMsgIdx = 0;

          /* Save a reference to the root instance */
          Sd_GetTmpSendEntryList().RootInstancePtr = EntriesListPtr->RootInstancePtr;
          Sd_GetTmpSendEntryList().NrOfSendEntries = 0;
          break;
        }
      }
    }

    if(NULL_PTR != ValidAddrPtr)
    {
      /* Iterate again over the list of send entries and search all messages which shall be transmitted to the same destination */
      for(SendEntryIdx = 0; SendEntryIdx < EntriesListPtr->RootInstancePtr->MaxNrRxTxEntries; SendEntryIdx++)
      {
        RetVal = E_OK;

        TmpSendEntry = &EntriesListPtr->SendEntryPtr[SendEntryIdx];

        if(TRUE == TmpSendEntry->Valid)
        {
          /* Check if the selected entry is a Subscribe entry without an established TCP connection */
          if(((SD_ENTRY_SUBSCRIBE_EVENTGROUP == TmpSendEntry->EntryType) ||
            (SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP == TmpSendEntry->EntryType)))
          {
            /* ... without an established TCP connection */
            /* PRQA S 3415 3 */ /* MD_Sd_12.4_3415 */
            if(Sd_ConsumedEventGroupUsesTcp(TmpSendEntry->ConsumedEventGroupPtr) &&
            (SOAD_INV_SO_CON_ID != TmpSendEntry->ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId) &&
            (SD_SOCON_MODE_ONLINE != Sd_GetSoConMode(TmpSendEntry->ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId)))
            {
              /* The TCP connection is not established. Skip the transmission of this message */
              RetVal = E_NOT_OK;
            }

            /* Check if the client service and/or event group is still requested */
            if(((SD_CLIENT_SERVICE_RELEASED == TmpSendEntry->ServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->StateSWC) ||
              (SD_CONSUMED_EVENTGROUP_RELEASED == TmpSendEntry->ConsumedEventGroupPtr->DynamicDataPtr->ServiceModeRequest) ||
              (SD_CLIENT_SERVICE_DOWN == TmpSendEntry->ServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->CurrentState)) &&
              (SD_ENTRY_SUBSCRIBE_EVENTGROUP == TmpSendEntry->EntryType))
            {
              /* The event group is not requested or not available any more. Remove the message */
              TmpSendEntry->Valid = FALSE;
              EntriesListPtr->NrOfSendEntries--;
              RetVal = E_NOT_OK;
            }
          }
          else
          {
            RetVal = E_OK;
          }

          if((TmpSendEntry->AddrPtr == ValidAddrPtr) && (E_OK == RetVal))
          {
            /* Save a reference to the send entry */
            Sd_GetTmpSendEntryList().SendEntryPtr[FoundMsgIdx] = EntriesListPtr->SendEntryPtr[SendEntryIdx];

            /* Remove the entry from the main list */
            TmpSendEntry->Valid = FALSE;
            Sd_GetTmpSendEntryList().NrOfSendEntries++;
            EntriesListPtr->NrOfSendEntries--;

            FoundMsgIdx++;
          }
          else
          {
            /* The entry has to be sent to another address, or the TCP connection is not established */
          }
        }
        else
        {
          /* The entry is not valid */
        }

        /* Stop the processing of the list if all entries are processed */
        if(0 == EntriesListPtr->NrOfSendEntries)
        {
          break;
        }
      }
    }
    else
    {
      /* No message ready for transmission -> stop */
      Iteration = 0;
    }

    /* Generate a message and transmit it if there are pending messages */
    if(0 < Sd_GetTmpSendEntryList().NrOfSendEntries)
    {
      /* Serialize all entries of the temporary list to the payload and transmit the message */
      RetVal = Sd_SerializePendingMessages(&Sd_GetTmpSendEntryList());

      if((E_NOT_OK == RetVal) && (1 < Sd_GetTmpSendEntryList().NrOfSendEntries))
      {
        /* Transmit buffer too small. Try to send all entries separately */
        uint8 tmpEntryIdx = 0;
        uint16 initialNrOfSendEntries = Sd_GetTmpSendEntryList().NrOfSendEntries;
        Sd_GetTmpSendEntryList().NrOfSendEntries = 1;

        while(initialNrOfSendEntries > tmpEntryIdx)
        {
          Sd_GetTmpSendEntryList().SendEntryPtr = &Sd_GetTmpSendEntry(tmpEntryIdx);
          (void)Sd_SerializePendingMessages(&Sd_GetTmpSendEntryList());
          tmpEntryIdx++;
        }

        /* Restore the structure of the TmpSendEntryList */
        Sd_GetTmpSendEntryList().SendEntryPtr = &Sd_GetTmpSendEntry(0);
      }

      /* Clear the send entries list */
      Sd_GetTmpSendEntryList().NrOfSendEntries = 0;
    }
  }
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_SerializePendingMessages()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_SerializePendingMessages(
  SD_P2CONST(Sd_SendEntriesListType) EntriesListPtr)
{
  /* Struct defining the static fields of the Sd header */
  STATIC CONST(Sd_HeaderType, SD_CONST) Sd_Header =
  {
    0x00U,    /* ClientId:          Statically set to 0 */
    0x00U,    /* SessionId          Not used            */
    0x01U,    /* Protocol Version:  Statically set to 1 */
    0x01U,    /* Interface Version: Statically set to 1 */
    0x02U,    /* Message Type:      Statically set to 2 */
    0x00U,    /* Return Code:       Statically set to 0 */
    0x00U,    /* Flags              Not used            */
    {0,0,0}   /* Reserved:          Statically set to 0 */
  };
  Std_ReturnType RetVal;
  SD_P2VAR(uint16) SessionIdPtr;
  SD_P2VAR(uint8) FlagsPtr;
  SD_P2VAR(uint8) SdPayloadPtr = Sd_ConfigPtr->PayloadPtr;
  SD_P2VAR(Sd_SendEntryType) TmpEntryPtr;
  boolean BufferTooSmall = FALSE;
  uint32 SizeEntriesArray, SizeOfOptionsArray, UsedTTL;
  uint16 PayloadEntryIdx, PayloadOptionIdx, StartOptionArrayIdx, SendEntryIdx;
  PduInfoType PduInfo;
  uint8 FreeOptionIndex = 0, Index1st = 0, Index2nd = 0, Nr1stOptions, Nr2ndOptions;

  /* Calculate the length of the Entries Array */
  SizeEntriesArray = EntriesListPtr->NrOfSendEntries * SD_SIZE_OF_ENTRY;

  /* Check if the TxBuffer can take at least SdHeader and the Entries Array */
  if(Sd_ConfigPtr->PayloadSize >=
    (SD_HEADER_LENGTH_SD + SD_SIZE_OF_ENTRY_ARRAY_LENGTH_FIELD + SizeEntriesArray + SD_SIZE_OF_OPTION_ARRAY_LENGTH_FIELD))
  {
    /* Fill the header of the SD message */
    /* The Session ID of the header is used as a counter */
    /* All unicast as well as multicast messages have their own counter */
    RetVal = Sd_GetSessionIdFlags(EntriesListPtr->RootInstancePtr, EntriesListPtr->SendEntryPtr[0].AddrPtr, &SessionIdPtr, &FlagsPtr);

    if(E_OK == RetVal)
    {
      PayloadEntryIdx = Sd_WriteHeader(&Sd_Header, &SdPayloadPtr[0], *SessionIdPtr, *FlagsPtr);
      StartOptionArrayIdx = (uint16)(PayloadEntryIdx + SD_SIZE_OF_ENTRY_ARRAY_LENGTH_FIELD + SizeEntriesArray + SD_SIZE_OF_OPTION_ARRAY_LENGTH_FIELD);
      PayloadOptionIdx = StartOptionArrayIdx;

      /* Length of the entries array field */
      SdPayloadPtr[PayloadEntryIdx]     = (uint8)(SizeEntriesArray >> 24);
      SdPayloadPtr[PayloadEntryIdx + 1] = (uint8)(SizeEntriesArray >> 16);
      SdPayloadPtr[PayloadEntryIdx + 2] = (uint8)(SizeEntriesArray >> 8);
      SdPayloadPtr[PayloadEntryIdx + 3] = (uint8)(SizeEntriesArray);

      PayloadEntryIdx += 4;

      /* Iterate over all entries and serialize entries as well as options */
      for(SendEntryIdx = 0; SendEntryIdx < EntriesListPtr->NrOfSendEntries; SendEntryIdx++)
      {
        TmpEntryPtr = &EntriesListPtr->SendEntryPtr[SendEntryIdx];

        /* Serialize related options */
        BufferTooSmall = Sd_SerializeRelatedOptions(TmpEntryPtr, StartOptionArrayIdx, &PayloadOptionIdx,
          &FreeOptionIndex, &Index1st, &Index2nd, &Nr1stOptions, &Nr2ndOptions);

        if(TRUE == BufferTooSmall)
        {
          /* Stop serializing the payload */
          break;
        }

        /* Serialize the entry */
        /* Fill the type field. The first bit of the Sd_EntryType is only used internally to differentiate STOP/NACK entries */
        SdPayloadPtr[PayloadEntryIdx] = (uint8)(TmpEntryPtr->EntryType & 0x7F);

        /* Write the option index and number of options */
        SdPayloadPtr[PayloadEntryIdx + 1] = Index1st;
        SdPayloadPtr[PayloadEntryIdx + 2] = Index2nd;
        SdPayloadPtr[PayloadEntryIdx + 3] = (uint8)((uint8)(Nr1stOptions << 4) | Nr2ndOptions);

        /* Service ID */
        SdPayloadPtr[PayloadEntryIdx + 4] = (uint8)(TmpEntryPtr->ServiceId >> 8);
        SdPayloadPtr[PayloadEntryIdx + 5] = (uint8)(TmpEntryPtr->ServiceId);

        /* Instance ID */
        SdPayloadPtr[PayloadEntryIdx + 6] = (uint8)(TmpEntryPtr->InstanceId >> 8);
        SdPayloadPtr[PayloadEntryIdx + 7] = (uint8)(TmpEntryPtr->InstanceId);

        /* Major Version */
        SdPayloadPtr[PayloadEntryIdx + 8] = TmpEntryPtr->MajorVersion;

        /* TTL */
        if(1 == (TmpEntryPtr->EntryType >> 7))  /* The eighth bit set to 1 indicates a STOP/NACK message */
        {
          /* STOP/NACK entry with TTL = 0 */
          UsedTTL = 0;
        }
        else
        {
          if(NULL_PTR != TmpEntryPtr->ServiceInstancePtr->ClientInstancePtr)
          {
            if(SD_ENTRY_FIND_SERVICE == TmpEntryPtr->EntryType)
            {
              UsedTTL = TmpEntryPtr->ServiceInstancePtr->ClientInstancePtr->TimerRef->TTL;
            }
            else
            {
              UsedTTL = TmpEntryPtr->ConsumedEventGroupPtr->TimerRef->TTL;
            }
          }
          else /* NULL_PTR != TmpEntryPtr->ServiceInstancePtr->ServerInstancePtr */
          {
            if(SD_ENTRY_OFFER_SERVICE == TmpEntryPtr->EntryType)
            {
              UsedTTL = TmpEntryPtr->ServiceInstancePtr->ServerInstancePtr->TimerRef->TTL;
            }
            else
            {
              UsedTTL = TmpEntryPtr->ClientPtr->RequestedTTL;
            }
          }
        }

        SdPayloadPtr[PayloadEntryIdx + 9]  = (uint8)(UsedTTL >> 16);
        SdPayloadPtr[PayloadEntryIdx + 10] = (uint8)(UsedTTL >> 8);
        SdPayloadPtr[PayloadEntryIdx + 11] = (uint8)(UsedTTL);

        if((SD_ENTRY_FIND_SERVICE == TmpEntryPtr->EntryType) ||
          (SD_ENTRY_OFFER_SERVICE == TmpEntryPtr->EntryType) ||
          (SD_ENTRY_STOP_OFFER_SERVICE == TmpEntryPtr->EntryType))
        {
          SdPayloadPtr[PayloadEntryIdx + 12] = (uint8)(TmpEntryPtr->ServiceInstancePtr->MinorVersion >> 24);
          SdPayloadPtr[PayloadEntryIdx + 13] = (uint8)(TmpEntryPtr->ServiceInstancePtr->MinorVersion >> 16);
          SdPayloadPtr[PayloadEntryIdx + 14] = (uint8)(TmpEntryPtr->ServiceInstancePtr->MinorVersion >> 8);
          SdPayloadPtr[PayloadEntryIdx + 15] = (uint8)(TmpEntryPtr->ServiceInstancePtr->MinorVersion);
        }
        else if((SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK == TmpEntryPtr->EntryType) || (SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK == TmpEntryPtr->EntryType))
        {
          SdPayloadPtr[PayloadEntryIdx + 12] = (uint8)(TmpEntryPtr->ReservedField >> 8);
          SdPayloadPtr[PayloadEntryIdx + 13] = (uint8)(TmpEntryPtr->ReservedField);
          SdPayloadPtr[PayloadEntryIdx + 14] = (uint8)(TmpEntryPtr->EventHandlerId >> 8);
          SdPayloadPtr[PayloadEntryIdx + 15] = (uint8)TmpEntryPtr->EventHandlerId;
        }
        else  /* ((SD_ENTRY_SUBSCRIBE_EVENTGROUP == TmpEntryPtr->EntryType) || (SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP == TmpEntryPtr->EntryType)) */
        {
          SdPayloadPtr[PayloadEntryIdx + 12] = 0;
          SdPayloadPtr[PayloadEntryIdx + 13] = 0;
          SdPayloadPtr[PayloadEntryIdx + 14] = (uint8)(TmpEntryPtr->ConsumedEventGroupPtr->EventGroupId >> 8);
          SdPayloadPtr[PayloadEntryIdx + 15] = (uint8)TmpEntryPtr->ConsumedEventGroupPtr->EventGroupId;
        }

        PayloadEntryIdx += SD_SIZE_OF_ENTRY;
      }

      /* Set the length of the options array */
      SizeOfOptionsArray = PayloadOptionIdx - StartOptionArrayIdx;
      SdPayloadPtr[StartOptionArrayIdx - 4] = (uint8)(SizeOfOptionsArray >> 24);
      SdPayloadPtr[StartOptionArrayIdx - 3] = (uint8)(SizeOfOptionsArray >> 16);
      SdPayloadPtr[StartOptionArrayIdx - 2] = (uint8)(SizeOfOptionsArray >> 8);
      SdPayloadPtr[StartOptionArrayIdx - 1] = (uint8)(SizeOfOptionsArray);

      PduInfo.SduDataPtr = &SdPayloadPtr[0];
      PduInfo.SduLength = PayloadOptionIdx;

      /* Check if all entries fit into the payload and an IP address is assigned */
      if((FALSE == BufferTooSmall) && (SD_INSTANCE_UP_AND_CONFIGURED == EntriesListPtr->RootInstancePtr->DynamicDataPtr->State))
      {
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_SetRemoteAddr(EntriesListPtr->RootInstancePtr->TxSoConId,
          (SD_P2VAR(SoAd_SockAddrType))(EntriesListPtr->SendEntryPtr[0].AddrPtr));

        /* Send the message. (Return values are only used for debug purposes. Sd does not implement retry mechanism) */
        if(E_OK == RetVal)
        {
          RetVal = SoAd_IfTransmit(EntriesListPtr->RootInstancePtr->TxPduId, &PduInfo); /* \trace SPEC-2046291 */
        }

        if(E_NOT_OK == RetVal)
        {
          /* Transmit failed. Return value is ignored. */
        }

        /* Increment SessionId for each transmitted message */
        if(0xFFFF == *SessionIdPtr)
        {
          /* The SessionId should start with the value 1 */
          *SessionIdPtr = 1;
          /* Reset the reboot flag if the SessionId wraps around */
          *FlagsPtr = (uint8)(*FlagsPtr & 0x7F);
        }
        else
        {
          (*SessionIdPtr)++;
        }
      }
    }
  }
  else
  {
    BufferTooSmall = TRUE;
  }

  if(TRUE == BufferTooSmall)
  {
    /* The configured Sd_Payload buffer is too small to contain all entries */
    /* Buffer size is configured in Sd/SdConfig/SdInstance/SdInstanceTxPdu/SdTxPduRef or Sd/SdGeneral/SdTxBufferSize */
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Sd_CallDetReportError(SD_API_ID_INTERNAL_FUNCTION, SD_E_LIST_FULL);

    RetVal = E_NOT_OK;
  }
  else
  {
    RetVal = E_OK;
  }

  return RetVal;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_WriteHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(uint8, SD_CODE) Sd_WriteHeader(
  SD_P2CONST(Sd_HeaderType) SdHeaderPtr,
  SD_P2VAR(uint8) DataPtr,
  uint16 SessionId,
  uint8 Flags)
{
  DataPtr[0] = (uint8)(SdHeaderPtr->ClientID >> 8);
  DataPtr[1] = (uint8)(SdHeaderPtr->ClientID);
  DataPtr[2] = (uint8)(SessionId >> 8);
  DataPtr[3] = (uint8)(SessionId);
  DataPtr[4] = SdHeaderPtr->ProtocolVersion;
  DataPtr[5] = SdHeaderPtr->InterfaceVersion;
  DataPtr[6] = SdHeaderPtr->MessageType;
  DataPtr[7] = SdHeaderPtr->ReturnCode;
  DataPtr[8] = Flags;
  DataPtr[9] = SdHeaderPtr->Reserved[0];
  DataPtr[10] = SdHeaderPtr->Reserved[1];
  DataPtr[11] = SdHeaderPtr->Reserved[2];

  return SD_HEADER_LENGTH_SD;
}

/**********************************************************************************************************************
 *  Sd_SerializeRelatedOptions()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(boolean, SD_CODE) Sd_SerializeRelatedOptions(
  SD_P2CONST(Sd_SendEntryType) EntryPtr,
  uint16 StartOptionArrayIdx,
  SD_P2VAR(uint16) PayloadOptionIdx,
  SD_P2VAR(uint8) FreeOptionIndexPtr,
  SD_P2VAR(uint8) Index1stPtr,
  SD_P2VAR(uint8) Index2ndPtr,
  SD_P2VAR(uint8) Nr1stOptionsPtr,
  SD_P2VAR(uint8) Nr2ndOptionsPtr)
{
  SD_P2VAR(uint8) SdPayloadPtr = Sd_ConfigPtr->PayloadPtr;
  Sd_SockAddrContainerType SockAddrContainerUdp, SockAddrContainerTcp;
  boolean BufferTooSmall = FALSE, ConfigOptionRequired = TRUE;
  uint16 AdditionalOptionSize;
  uint8 TmpOptionIndex = SD_INV_OPTION_INDEX;

  *Index1stPtr = SD_INV_OPTION_INDEX;
  *Index2ndPtr = SD_INV_OPTION_INDEX;
  *Nr1stOptionsPtr = 0;
  *Nr2ndOptionsPtr = 0;

  /* Get relevant endpoint options */
  Sd_GetRelavantOptions(EntryPtr, &SockAddrContainerUdp, &SockAddrContainerTcp, &ConfigOptionRequired);

  /* Serialize UDP endpoint option */
  if(SOAD_AF_INVALID != SockAddrContainerUdp.family)
  {
    Sd_OptionType OptionType = SD_OPTION_IPV4_ENDPOINT;

    if(SOAD_AF_INET6 == SockAddrContainerUdp.family)
    {
      OptionType = SD_OPTION_IPV6_ENDPOINT;
    }

    if(SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK == EntryPtr->EntryType)
    {
      OptionType = (Sd_OptionType)((uint8)OptionType | SD_OPTION_MULTICAST_MASK);
    }

    /* Serialize option to the end of the payload */
    AdditionalOptionSize = Sd_SerializeEndpointOption(&SockAddrContainerUdp, OptionType, SD_L4PROTOCOL_UDP, &SdPayloadPtr[0], *PayloadOptionIdx, &BufferTooSmall);

    if(FALSE == BufferTooSmall)
    {
      /* Check if option was already serialized */
      Sd_CheckForDuplicatedOption(StartOptionArrayIdx, *PayloadOptionIdx, &TmpOptionIndex);

      /* Search for possible option configuration */
      if(FALSE == Sd_DeduplicateOption(TmpOptionIndex, TRUE, FreeOptionIndexPtr, Index1stPtr, Index2ndPtr, Nr1stOptionsPtr, Nr2ndOptionsPtr))
      {
        /* Not able to deduplicate option. Use option which was serialized to the end of the payload and extend the payload */
        *PayloadOptionIdx += AdditionalOptionSize;
      }
    }
  }

  /* Serialize TCP endpoint option */
  if((SOAD_AF_INVALID != SockAddrContainerTcp.family) && (FALSE == BufferTooSmall))
  {
    Sd_OptionType OptionType = SD_OPTION_IPV4_ENDPOINT;

    if(SOAD_AF_INET6 == SockAddrContainerUdp.family)
    {
      OptionType = SD_OPTION_IPV6_ENDPOINT;
    }

    if(SOAD_AF_INET6 == SockAddrContainerTcp.family)
    {
      OptionType = SD_OPTION_IPV6_ENDPOINT;
    }

    /* Serialize option */
    AdditionalOptionSize = Sd_SerializeEndpointOption(&SockAddrContainerTcp, OptionType, SD_L4PROTOCOL_TCP, &SdPayloadPtr[0], *PayloadOptionIdx, &BufferTooSmall);

    if(FALSE == BufferTooSmall)
    {
      /* Check if option was already serialized */
      Sd_CheckForDuplicatedOption(StartOptionArrayIdx, *PayloadOptionIdx, &TmpOptionIndex);

      /* Search for possible option configuration */
      if(FALSE == Sd_DeduplicateOption(TmpOptionIndex, ConfigOptionRequired, FreeOptionIndexPtr, Index1stPtr, Index2ndPtr, Nr1stOptionsPtr, Nr2ndOptionsPtr))
      {
        /* Not able to deduplicate option. Use option which was serialized to the end of the payload and extend the payload */
        *PayloadOptionIdx += AdditionalOptionSize;
      }
    }
  }

  /* Serialize all mandatory configuration options */
  if((NULL_PTR != EntryPtr->ServiceInstancePtr) &&
    ((NULL_PTR != EntryPtr->ServiceInstancePtr->RootInstancePtr->HostnamePtr) ||
    (NULL_PTR != EntryPtr->ServiceInstancePtr->CapabilityRecordPtr)) && (FALSE == BufferTooSmall))
  {
    if((SD_ENTRY_FIND_SERVICE == EntryPtr->EntryType) ||
      (SD_ENTRY_OFFER_SERVICE == EntryPtr->EntryType) ||
      (SD_ENTRY_STOP_OFFER_SERVICE == EntryPtr->EntryType) ||
      (SD_SERVICE_ID_OTHERSERV == EntryPtr->ServiceInstancePtr->ServiceId))
    {
      /* Build and attach the configuration option */
      AdditionalOptionSize = Sd_SerializeConfigurationOption(EntryPtr->ServiceInstancePtr->RootInstancePtr->HostnamePtr,
        EntryPtr, &SdPayloadPtr[0], *PayloadOptionIdx, &BufferTooSmall);

      if(FALSE == BufferTooSmall)
      {
        /* Check if option was already serialized */
        Sd_CheckForDuplicatedOption(StartOptionArrayIdx, *PayloadOptionIdx, &TmpOptionIndex);

        /* Search for possible option configuration */
        if(FALSE == Sd_DeduplicateOption(TmpOptionIndex, FALSE, FreeOptionIndexPtr, Index1stPtr, Index2ndPtr, Nr1stOptionsPtr, Nr2ndOptionsPtr))
        {
        /* Not able to deduplicate option. Use option which was serialized to the end of the payload and extend the payload */
          *PayloadOptionIdx += AdditionalOptionSize;
        }
      }
    }
  }

  if(SD_INV_OPTION_INDEX == *Index1stPtr)
  {
    /* 1st option run not used, clear all values */
    *Index1stPtr = 0;
    *Nr1stOptionsPtr = 0;
  }

  if(SD_INV_OPTION_INDEX == *Index2ndPtr)
  {
    /* 2nd option run not used, clear all values */
    *Index2ndPtr = 0;
    *Nr2ndOptionsPtr = 0;
  }

  return BufferTooSmall;
} /* PRQA S 6010, 6030, 6060 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Sd_GetRelavantOptions()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_GetRelavantOptions(
  SD_P2CONST(Sd_SendEntryType) EntryPtr,
  SD_P2VAR(Sd_SockAddrContainerType) SockAddrContainerUdpPtr,
  SD_P2VAR(Sd_SockAddrContainerType) SockAddrContainerTcpPtr,
  SD_P2VAR(boolean) ConfigOptionRequiredPtr)
{
  Std_ReturnType RetVal;
  Sd_SockAddrContainerType DefaultRouterAddr;
  uint16 EventHandlerIdx;
  uint8 Netmask;

  SockAddrContainerUdpPtr->family = SOAD_AF_INVALID;
  SockAddrContainerTcpPtr->family = SOAD_AF_INVALID;
  *ConfigOptionRequiredPtr = FALSE;

  /* Check if the entry requires UDP or TCP endpoint options */
  switch(EntryPtr->EntryType)
  {
    case SD_ENTRY_FIND_SERVICE :
    case SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK :
      /* These entries do not allow any endpoint options. */
      break;

    case SD_ENTRY_OFFER_SERVICE :
    case SD_ENTRY_STOP_OFFER_SERVICE :
      /* Check if the service is configured for UDP and save the address */
      if(0 != EntryPtr->ServiceInstancePtr->UdpSoConListSize)
      {
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetLocalAddr(EntryPtr->ServiceInstancePtr->UdpSoConListPtr[0],
          (SD_P2VAR(SoAd_SockAddrType))SockAddrContainerUdpPtr, &Netmask, (SD_P2VAR(SoAd_SockAddrType))(&DefaultRouterAddr));

        if(E_OK != RetVal)
        {
          /* Not able to get local address */
          SockAddrContainerUdpPtr->family = SOAD_AF_INVALID;
        }
      }

      if(SOAD_AF_INVALID == SockAddrContainerUdpPtr->family)
      {
        /* Check if the service contains a EventHandler which is configured for multicast */
        EventHandlerIdx = EntryPtr->ServiceInstancePtr->ServerInstancePtr->NrOfEventHandlers;
        while(0 < EventHandlerIdx)
        {
          EventHandlerIdx--;

          if(Sd_EventHandlerUsesMulticast(&EntryPtr->ServiceInstancePtr->ServerInstancePtr->EventHandlerPtr[EventHandlerIdx]))
          {
            /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
            RetVal = SoAd_GetLocalAddr(EntryPtr->ServiceInstancePtr->ServerInstancePtr->EventHandlerPtr[EventHandlerIdx].MulticastRefPtr->SoConId,
              (SD_P2VAR(SoAd_SockAddrType))SockAddrContainerUdpPtr, &Netmask, (SD_P2VAR(SoAd_SockAddrType))(&DefaultRouterAddr));

            if(E_OK != RetVal)
            {
              /* Not able to get local address */
              SockAddrContainerUdpPtr->family = SOAD_AF_INVALID;
            }
            break;
          }
        }
      }

      /* Check if the service is configured for TCP and save the address */
      if(0 != EntryPtr->ServiceInstancePtr->TcpSoConListSize)
      {
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetLocalAddr(EntryPtr->ServiceInstancePtr->TcpSoConListPtr[0],
          (SD_P2VAR(SoAd_SockAddrType))SockAddrContainerTcpPtr, &Netmask, (SD_P2VAR(SoAd_SockAddrType))(&DefaultRouterAddr));

        if(E_OK != RetVal)
        {
          /* Not able to get local address */
          SockAddrContainerTcpPtr->family = SOAD_AF_INVALID;
        }
      }
      break;

    case SD_ENTRY_SUBSCRIBE_EVENTGROUP :
    case SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP :
      /* These entries contain unicast endpoint options */
      if(SOAD_INV_SO_CON_ID != EntryPtr->ConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId)
      {
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetLocalAddr(EntryPtr->ConsumedEventGroupPtr->DynamicDataPtr->UdpSoConId,
          (SD_P2VAR(SoAd_SockAddrType))SockAddrContainerUdpPtr, &Netmask, (SD_P2VAR(SoAd_SockAddrType))(&DefaultRouterAddr));

        if(E_OK != RetVal)
        {
          /* Not able to get local address */
          SockAddrContainerUdpPtr->family = SOAD_AF_INVALID;
        }
      }

      if(SOAD_INV_SO_CON_ID != EntryPtr->ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId)
      {
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetLocalAddr(EntryPtr->ConsumedEventGroupPtr->DynamicDataPtr->TcpSoConId,
          (SD_P2VAR(SoAd_SockAddrType))SockAddrContainerTcpPtr, &Netmask, (SD_P2VAR(SoAd_SockAddrType))(&DefaultRouterAddr));

        if(E_OK != RetVal)
        {
          /* Not able to get local address */
          SockAddrContainerTcpPtr->family = SOAD_AF_INVALID;
        }
      }
      break;

    case SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK :
      /* These entry contains multicast endpoint options */
      if(Sd_EventHandlerUsesMulticast(EntryPtr->EventHandlerPtr))
      {
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_GetRemoteAddr(EntryPtr->EventHandlerPtr->MulticastRefPtr->SoConId, (SD_P2VAR(SoAd_SockAddrType))SockAddrContainerUdpPtr);

        if(E_OK != RetVal)
        {
          /* Not able to get local address */
          SockAddrContainerUdpPtr->family = SOAD_AF_INVALID;
        }
      }
      break;

    default:
      /* Undefined EntryType */
      break;
  }

  /* Check if a configuration option is needed */
  switch(EntryPtr->EntryType)
  {
    case SD_ENTRY_FIND_SERVICE :
    case SD_ENTRY_OFFER_SERVICE :
    case SD_ENTRY_STOP_OFFER_SERVICE :
      if((NULL_PTR != EntryPtr->ServiceInstancePtr) &&
        ((NULL_PTR != EntryPtr->ServiceInstancePtr->RootInstancePtr->HostnamePtr) ||
        (NULL_PTR != EntryPtr->ServiceInstancePtr->CapabilityRecordPtr)))
      {
        *ConfigOptionRequiredPtr = TRUE;
      }
      break;

    case SD_ENTRY_SUBSCRIBE_EVENTGROUP :
    case SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP :
    case SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK :
    case SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK :
      if((NULL_PTR != EntryPtr->ServiceInstancePtr) &&
        (SD_SERVICE_ID_OTHERSERV == EntryPtr->ServiceInstancePtr->ServiceId))
      {
        *ConfigOptionRequiredPtr = TRUE;
      }
      break;

    default:
      /* Undefined EntryType */
      break;
  }
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_CheckForDuplicatedOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_CheckForDuplicatedOption(
  uint16 StartOptionArrayIdx,
  uint16 OptionIdx,
  SD_P2VAR(uint8) PossibleOptionIndexPtr)
{
  SD_P2VAR(uint8) SdPayloadPtr = Sd_ConfigPtr->PayloadPtr;
  boolean duplicatedOption = FALSE;
  uint16 payloadIdx = StartOptionArrayIdx, optionOffset, optionLength;
  uint8 TmpOptionIndex = SD_INV_OPTION_INDEX;

  *PossibleOptionIndexPtr = SD_INV_OPTION_INDEX;

  /* Check if the serialized payload already contains the new option */
  while(OptionIdx > payloadIdx)
  {
    /* Read length of next option */
    optionLength = (uint16)((uint16)(SdPayloadPtr[payloadIdx]) << 8) | ((uint16)(SdPayloadPtr[payloadIdx + 1]));

    /* Consider entire option */
    optionLength += SD_SIZE_NOT_COVERED_FIELDS_OF_OPTION;

    optionOffset = 0;
    (*PossibleOptionIndexPtr)++;
    duplicatedOption = TRUE;

    while(optionLength > optionOffset)
    {
      if(SdPayloadPtr[payloadIdx + optionOffset] != SdPayloadPtr[OptionIdx + optionOffset])
      {
        /* Option does not match. Skip option */
        duplicatedOption = FALSE;
        break;
      }

      optionOffset++;
    }

    if(TRUE == duplicatedOption)
    {
      /* Save option for possible deduplication. Repeat searching */
      TmpOptionIndex = *PossibleOptionIndexPtr;
    }

    payloadIdx += optionLength;
  }

  if(TRUE == duplicatedOption)
  {
    /* Return the last matching option */
  }
  else if(SD_INV_OPTION_INDEX != TmpOptionIndex)
  {
    /* Return the last matching option */
    *PossibleOptionIndexPtr = TmpOptionIndex;
  }
  else
  {
    /* No matching option found */
    *PossibleOptionIndexPtr = SD_INV_OPTION_INDEX;
  }
}

/**********************************************************************************************************************
 *  Sd_DeduplicateOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(boolean, SD_CODE) Sd_DeduplicateOption(
  uint8 PossibleOptionIndex,
  boolean RemainingOption,
  SD_P2VAR(uint8) FreeOptionIndexPtr,
  SD_P2VAR(uint8) Index1stPtr,
  SD_P2VAR(uint8) Index2ndPtr,
  SD_P2VAR(uint8) Nr1stOptionsPtr,
  SD_P2VAR(uint8) Nr2ndOptionsPtr)
{
  boolean AbleToDeduplicateOption = FALSE;

  if(SD_INV_OPTION_INDEX != PossibleOptionIndex)
  {
    AbleToDeduplicateOption = TRUE;

    /* Option was already serialized to the payload. Check if it can be deduplicated */
    if(0 == *Nr1stOptionsPtr)
    {
      /* Use first option run to index the option */
      *Index1stPtr = PossibleOptionIndex;
      (*Nr1stOptionsPtr)++;
    }
    else if((*Index1stPtr + *Nr1stOptionsPtr) == PossibleOptionIndex)
    {
      /* Extend first option run at the end to index new option */
      (*Nr1stOptionsPtr)++;
    }
    else if((*Index1stPtr - 1) == PossibleOptionIndex)
    {
      /* Extend first option run at the beginning to index new option */
      (*Index1stPtr)--;
      (*Nr1stOptionsPtr)++;
    }
    else if((FALSE == RemainingOption) && (0 == *Nr2ndOptionsPtr))
    {
      /* Use second option run to index the option */
      *Index2ndPtr = PossibleOptionIndex;
      (*Nr2ndOptionsPtr)++;
    }
    else if(*FreeOptionIndexPtr == (PossibleOptionIndex + 1))
    {
      /* Use second option run to index the option because the found option is the last one in the array */
      *Index2ndPtr = PossibleOptionIndex;
      (*Nr2ndOptionsPtr)++;
    }
    else if(*FreeOptionIndexPtr == (*Index1stPtr + *Nr1stOptionsPtr))
    {
      /* Use second option run to index the option because the last option of the array is indexed by the current entry */
      *Index2ndPtr = PossibleOptionIndex;
      (*Nr2ndOptionsPtr)++;
    }
    else if((0 != *Nr2ndOptionsPtr) && ((*Index2ndPtr + *Nr2ndOptionsPtr) == PossibleOptionIndex))
    {
      /* Extend second option run at the end to index new option */
      (*Nr2ndOptionsPtr)++;
    }
    else if((0 != *Nr2ndOptionsPtr) && ((*Index2ndPtr - 1) == PossibleOptionIndex))
    {
      /* Extend second option run at the beginning to index new option */
      (*Index2ndPtr)--;
      (*Nr2ndOptionsPtr)++;
    }
    else
    {
      /* Option can not be deduplicated */
      AbleToDeduplicateOption = FALSE;
      PossibleOptionIndex = SD_INV_OPTION_INDEX;
    }
  }

  if(SD_INV_OPTION_INDEX == PossibleOptionIndex)
  {
    /* Use option which was serialized to the end of the payload */
    if(0 == *Nr1stOptionsPtr)
    {
      /* Use first option run to index the option */
      *Index1stPtr = *FreeOptionIndexPtr;
      (*Nr1stOptionsPtr)++;
    }
    else if(*FreeOptionIndexPtr == (*Index1stPtr + *Nr1stOptionsPtr))
    {
      /* Extend first option run at the end to index new option */
      (*Nr1stOptionsPtr)++;
    }
    else if(0 == *Nr2ndOptionsPtr)
    {
      /* Use second option run to index the option */
      *Index2ndPtr = *FreeOptionIndexPtr;
      (*Nr2ndOptionsPtr)++;
    }
    else if(*FreeOptionIndexPtr == (*Index2ndPtr + *Nr2ndOptionsPtr))
    {
      /* Extend second option run at the end to index new option */
      (*Nr2ndOptionsPtr)++;
    }
    else
    {
      /* Not able to index new option */
    }

    (*FreeOptionIndexPtr)++;
  }

  return AbleToDeduplicateOption;
} /* PRQA S 6030, 6060, 6080 */ /* MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_SerializeEndpointOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(uint16, SD_CODE) Sd_SerializeEndpointOption(
  SD_P2CONST(Sd_SockAddrContainerType) LocalIpAddrPtr,
  Sd_OptionType OptionType,
  Sd_L4ProtocolType L4Proto,
  SD_P2VAR(uint8) DataPtr,
  uint16 Offset,
  SD_P2VAR(boolean) BufferTooSmallPtr)
{
  uint16 OptionLength = 0;

  switch(OptionType)
  {
    case SD_OPTION_IPV4_ENDPOINT :
    case SD_OPTION_IPV4_MULTICAST :
      /* Check if the endpoint can be written into the buffer */
      if(Sd_ConfigPtr->PayloadSize <= (Offset + SD_SIZE_OF_OPTION_IPv4))
      {
        /* Stop processing of the endpoint option */
        *BufferTooSmallPtr = TRUE;
      }
      else
      {
        /* Set the length field */
        DataPtr[Offset] = 0u; /* SD_COVERED_LENGTH_OF_OPTION_IPv4 >> 8 */
        DataPtr[Offset + 1] = SD_COVERED_LENGTH_OF_OPTION_IPv4;
        OptionLength = SD_SIZE_OF_OPTION_IPv4;

        /* Set the type field */
        DataPtr[Offset + 2] = (uint8)OptionType;

        /* Set the first reserved field */
        DataPtr[Offset + 3] = 0u;

        /* Set the IP address */
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        IpBase_Copy((SD_P2VAR(IpBase_CopyDataType))&DataPtr[Offset + 4], (SD_P2VAR(IpBase_CopyDataType))LocalIpAddrPtr->data, 4);

        /* Set the port number */
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
        IpBase_Copy((SD_P2VAR(IpBase_CopyDataType))&DataPtr[Offset + 10], (SD_P2VAR(IpBase_CopyDataType))&LocalIpAddrPtr->port, 2);

        /* Set the second reserved field */
        DataPtr[Offset + 8] = 0;

        /* Set the L4-Proto field */
        DataPtr[Offset + 9] = (uint8)L4Proto;
      }
      break;

    case SD_OPTION_IPV6_ENDPOINT :
    case SD_OPTION_IPV6_MULTICAST :
      /* Check if the endpoint can be written into the buffer */
      if(Sd_ConfigPtr->PayloadSize <= (Offset + SD_SIZE_OF_OPTION_IPv6))
      {
        /* Stop processing of the endpoint option */
        *BufferTooSmallPtr = TRUE;
      }
      else
      { /* \trace SPEC-2046072 */
        /* Set the length field */
        DataPtr[Offset] = 0u; /* SD_COVERED_LENGTH_OF_OPTION_IPv6 >> 8 */
        DataPtr[Offset + 1] = SD_COVERED_LENGTH_OF_OPTION_IPv6;
        OptionLength = SD_SIZE_OF_OPTION_IPv6;

        /* Set the type field */
        DataPtr[Offset + 2] = (uint8)OptionType;

        /* Set the first reserved field */
        DataPtr[Offset + 3] = 0u;

        /* Set the IP address */
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        (void)IpBase_CopyIpV6Addr((SD_P2VAR(IpBase_AddrIn6Type))&DataPtr[Offset + 4], (SD_P2VAR(IpBase_AddrIn6Type))LocalIpAddrPtr->data);

        /* Set the port number */
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
        IpBase_Copy((SD_P2VAR(IpBase_CopyDataType))&DataPtr[Offset + 22], (SD_P2VAR(IpBase_CopyDataType))&LocalIpAddrPtr->port, 2);

        /* Set the second reserved field */
        DataPtr[Offset + 20] = 0;

        /* Set the L4-Proto field */
        DataPtr[Offset + 21] = (uint8)L4Proto;
      }
      break;

    default:
      /* Undefined OptionType */
      break;
  }

  return OptionLength;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Sd_SerializeConfigurationOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(uint16, SD_CODE) Sd_SerializeConfigurationOption(
  SD_P2CONST(uint8) HostnamePtr,
  SD_P2CONST(Sd_SendEntryType) SendEntryPtr,
  SD_P2VAR(uint8) DataPtr,
  uint16 Offset,
  SD_P2VAR(boolean) BufferTooSmallPtr)
{
  uint16 index = Offset, capabilityLengthIdx, lengthCapability;

  /* Check if at least a empty configuration option fits into the buffer */
  if(Sd_ConfigPtr->PayloadSize > (Offset + SD_MIN_SIZE_CONFIGURATION_OPTION))
  {
    /* Set the type field */
    index += SD_SIZE_OF_OPTION_LENGTH_FIELD;
    DataPtr[index] = SD_OPTION_CONFIGURATION;
    index += SD_SIZE_OF_TYPE_FIELD;
    DataPtr[index] = 0;
    index += SD_SIZE_OF_RESERVED_FIELD;

    /* Add the hostname */
    if(NULL_PTR != HostnamePtr)
    {
      lengthCapability = HostnamePtr[0];

      /* Check if the hostname fits into the buffer */
      if(Sd_ConfigPtr->PayloadSize > (index + lengthCapability))
      {
        IpBase_Copy(&DataPtr[index], &HostnamePtr[0], lengthCapability + 1);

        index += (lengthCapability + 1);
      }
      else
      {
        *BufferTooSmallPtr = TRUE;
      }
    }

    if((NULL_PTR != SendEntryPtr->ServiceInstancePtr) && (FALSE == *BufferTooSmallPtr) &&
      (NULL_PTR != SendEntryPtr->ServiceInstancePtr->CapabilityRecordPtr))
    {
      /* Add all capability records of the service instance */
      capabilityLengthIdx = 0;
      lengthCapability = SendEntryPtr->ServiceInstancePtr->CapabilityRecordPtr[capabilityLengthIdx];

      while(FALSE == *BufferTooSmallPtr)
      {
        /* Check if the capability record fits into the buffer */
        if(Sd_ConfigPtr->PayloadSize > (index + lengthCapability))
        {
          IpBase_Copy(&DataPtr[index],
            &SendEntryPtr->ServiceInstancePtr->CapabilityRecordPtr[capabilityLengthIdx],
            lengthCapability + 1);

          capabilityLengthIdx += lengthCapability + 1;
          index += lengthCapability + 1;
          lengthCapability = SendEntryPtr->ServiceInstancePtr->CapabilityRecordPtr[capabilityLengthIdx];

          if(0 == lengthCapability)
          {
            break;
          }
        }
        else
        {
          *BufferTooSmallPtr = TRUE;
        }
      }
    }

    /* Terminate the configuration option */
    DataPtr[index] = 0;
    index++;

    /* Set the length of the capability record */
    lengthCapability = index - (Offset + SD_SIZE_NOT_COVERED_FIELDS_OF_OPTION);
    DataPtr[Offset] = (uint8)(lengthCapability >> 8);
    DataPtr[Offset + 1] = (uint8)lengthCapability;
  }
  else
  {
    *BufferTooSmallPtr = TRUE;
  }

  return (index - Offset);
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_FindUnusedSlotInSendEntriesList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(uint16, SD_CODE) Sd_FindUnusedSlotInSendEntriesList(
  SD_P2CONST(Sd_SendEntriesListType) SendEntriesListPtr)
{
  uint16 EmptyEntry = 0;

  while(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries > EmptyEntry)
  {
    if(FALSE == SendEntriesListPtr->SendEntryPtr[EmptyEntry].Valid)
    {
      /* Found an empty slot */
      break;
    }

    EmptyEntry++;
  }

  return EmptyEntry;
}

/**********************************************************************************************************************
 *  Sd_AddFindEntryToList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_AddFindEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr)
{
  /*  Currently this specification does not allow sending FindService entries using unicast. */

  /* Search for an empty slot in order to save the message */
  uint16 EmptySlot = Sd_FindUnusedSlotInSendEntriesList(SendEntriesListPtr);

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries > EmptySlot)
  {
    /* Update the entry list */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].Valid = TRUE;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceId = ServiceInstancePtr->ServiceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].InstanceId = ServiceInstancePtr->InstanceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].MajorVersion = ServiceInstancePtr->MajorVersion;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EntryType = SD_ENTRY_FIND_SERVICE;
    /* PRQA S 0311 3 */ /* MD_Sd_11.5_0311 */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].AddrPtr =
      (SD_P2VAR(Sd_SockAddrContainerType))
      &SendEntriesListPtr->RootInstancePtr->AddressStorageListPtr[SendEntriesListPtr->RootInstancePtr->AddressStorageListSize - 1].Addr;
    Sd_ResetTimerToZero(SendEntriesListPtr->SendEntryPtr[EmptySlot].TimeToSend); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceInstancePtr = ServiceInstancePtr;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EventHandlerPtr = NULL_PTR;                /* Parameter not used in case of a find message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ClientPtr = NULL_PTR;                      /* Parameter not used in case of a find message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ConsumedEventGroupPtr = NULL_PTR;          /* Parameter not used in case of a find message */
    SendEntriesListPtr->NrOfSendEntries++;
  }

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries == SendEntriesListPtr->NrOfSendEntries)
  {
    /* The sendentry list is full, trigger a transmission */
    Sd_ProcessPendingMessages(SendEntriesListPtr, TRUE);
  }
}

/**********************************************************************************************************************
 *  Sd_AddMulticastOfferEntryToList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_AddMulticastOfferEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr,
  boolean StopOffer)
{
  /* Search for an empty slot in order to save the message */
  uint16 EmptySlot = Sd_FindUnusedSlotInSendEntriesList(SendEntriesListPtr);

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries > EmptySlot)
  {
    /* Update the entry list */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].Valid = TRUE;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceId = ServiceInstancePtr->ServiceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].InstanceId = ServiceInstancePtr->InstanceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].MajorVersion = ServiceInstancePtr->MajorVersion;
    /* PRQA S 0311 3 */ /* MD_Sd_11.5_0311 */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].AddrPtr =
      (SD_P2VAR(Sd_SockAddrContainerType))
      &SendEntriesListPtr->RootInstancePtr->AddressStorageListPtr[SendEntriesListPtr->RootInstancePtr->AddressStorageListSize - 1].Addr;
    Sd_ResetTimerToZero(SendEntriesListPtr->SendEntryPtr[EmptySlot].TimeToSend); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceInstancePtr = ServiceInstancePtr;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EventHandlerPtr = NULL_PTR;                /* Parameter not used in case of a (stop)offer message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ClientPtr = NULL_PTR;                      /* Parameter not used in case of a (stop)offer message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ConsumedEventGroupPtr = NULL_PTR;          /* Parameter not used in case of a (stop)offer message */

    if(FALSE == StopOffer)
    {
      SendEntriesListPtr->SendEntryPtr[EmptySlot].EntryType = SD_ENTRY_OFFER_SERVICE;
    }
    else
    {
      SendEntriesListPtr->SendEntryPtr[EmptySlot].EntryType = SD_ENTRY_STOP_OFFER_SERVICE;
    }

    SendEntriesListPtr->NrOfSendEntries++;
  }

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries == SendEntriesListPtr->NrOfSendEntries)
  {
    /* The sendentry list is full, trigger a transmission */
    Sd_ProcessPendingMessages(SendEntriesListPtr, TRUE);
  }
}

/**********************************************************************************************************************
 *  Sd_AddUnicastOfferEntryToList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_AddUnicastOfferEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ServiceInstanceType) ServiceInstancePtr,
  boolean StopOffer,
  SD_P2VAR(Sd_SockAddrContainerType) AddrPtr,
  uint32 TransmissionOffset)
{
  /* Search for an empty slot in order to save the message */
  uint16 EmptySlot = Sd_FindUnusedSlotInSendEntriesList(SendEntriesListPtr);

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries > EmptySlot)
  {
    /* Update the entry list */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].Valid = TRUE;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceId = ServiceInstancePtr->ServiceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].InstanceId = ServiceInstancePtr->InstanceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].MajorVersion = ServiceInstancePtr->MajorVersion;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].AddrPtr = AddrPtr;
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Sd_SetTimerOffsetNoTrigger(SendEntriesListPtr->SendEntryPtr[EmptySlot].TimeToSend, TransmissionOffset);
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceInstancePtr = ServiceInstancePtr;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EventHandlerPtr = NULL_PTR;                /* Parameter not used in case of a (stop)offer message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ClientPtr = NULL_PTR;                      /* Parameter not used in case of a (stop)offer message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ConsumedEventGroupPtr = NULL_PTR;          /* Parameter not used in case of a (stop)offer message */

    if(FALSE == StopOffer)
    {
      SendEntriesListPtr->SendEntryPtr[EmptySlot].EntryType = SD_ENTRY_OFFER_SERVICE;
    }
    else
    {
      SendEntriesListPtr->SendEntryPtr[EmptySlot].EntryType = SD_ENTRY_STOP_OFFER_SERVICE;
    }

    SendEntriesListPtr->NrOfSendEntries++;
  }

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries == SendEntriesListPtr->NrOfSendEntries)
  {
    /* The sendentry list is full, trigger a transmission */
    Sd_ProcessPendingMessages(SendEntriesListPtr, TRUE);
  }
}

/**********************************************************************************************************************
 *  Sd_AddSubscribeEntryToList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_AddSubscribeEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ConsumedEventGroupType) ConsumedEventGroupPtr,
  boolean Subscribe,
  uint32 TransmissionOffset)
{
  /* Search for an empty slot in order to save the message */
  uint16 EmptySlot = Sd_FindUnusedSlotInSendEntriesList(SendEntriesListPtr);

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries > EmptySlot)
  {
    /* Update the entry list */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].Valid = TRUE;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceId = ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->ServiceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].InstanceId = ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->InstanceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EventHandlerId = ConsumedEventGroupPtr->EventGroupId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].MajorVersion = ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->MajorVersion;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].AddrPtr = ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->ServerAddrPtr;
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Sd_SetTimerOffsetNoTrigger(SendEntriesListPtr->SendEntryPtr[EmptySlot].TimeToSend, TransmissionOffset);
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceInstancePtr = ConsumedEventGroupPtr->RootClientServicePtr->RootServiceInstancePtr;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EventHandlerPtr = NULL_PTR;                /* Parameter not used in case of a (stop)subscribe message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ClientPtr = NULL_PTR;                      /* Parameter not used in case of a (stop)subscribe message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ConsumedEventGroupPtr = ConsumedEventGroupPtr;

    if(TRUE == Subscribe)
    {
      SendEntriesListPtr->SendEntryPtr[EmptySlot].EntryType = SD_ENTRY_SUBSCRIBE_EVENTGROUP;
    }
    else
    {
      SendEntriesListPtr->SendEntryPtr[EmptySlot].EntryType = SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP;
    }

    SendEntriesListPtr->NrOfSendEntries++;
  }

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries == SendEntriesListPtr->NrOfSendEntries)
  {
    /* The sendentry list is full, trigger a transmission */
    Sd_ProcessPendingMessages(SendEntriesListPtr, TRUE);
  }
}

/**********************************************************************************************************************
 *  Sd_AddEventGroupAckEntryToList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_AddEventGroupAckEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_RxEventType) EventPtr)
{
  /* Search for an empty slot in order to save the message */
  uint16 EmptySlot = Sd_FindUnusedSlotInSendEntriesList(SendEntriesListPtr);
  uint32 AdditionalDelay = 0;

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries > EmptySlot)
  {
    SD_P2CONST(Sd_EventHandlerType) EventHandlerPtr = EventPtr->EventHandlerPtr;
    SD_P2VAR(Sd_ClientListType) ClientPtr = EventPtr->ClientPtr;

    /* Update the entry list */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].Valid = TRUE;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceId = EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->ServiceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].InstanceId = EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->InstanceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].MajorVersion = EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr->MajorVersion;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ReservedField = ClientPtr->RxReserved;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EventHandlerId = EventHandlerPtr->EventGroupId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].AddrPtr = ClientPtr->AddrPtr;
    if(SD_SERVER_EVENT_EVENTGROUP_SUBSCRIBE_MULTI == EventPtr->Event)
    {
      AdditionalDelay = Sd_GetRandomNrInRangeForResponse(EventHandlerPtr->TimerRef->RequestResponseMinDelay,
        EventHandlerPtr->TimerRef->RequestResponseMaxDelay, FALSE);
    }
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Sd_SetTimerOffsetNoTrigger(SendEntriesListPtr->SendEntryPtr[EmptySlot].TimeToSend, AdditionalDelay);
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceInstancePtr = EventHandlerPtr->RootServerServicePtr->RootServiceInstancePtr;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EventHandlerPtr = EventHandlerPtr;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ClientPtr = ClientPtr;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ConsumedEventGroupPtr = NULL_PTR;          /* Parameter not used in case of a (no)acknowledge message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EntryType = SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK;
    SendEntriesListPtr->NrOfSendEntries++;
  }

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries == SendEntriesListPtr->NrOfSendEntries)
  {
    /* The sendentry list is full, trigger a transmission */
    Sd_ProcessPendingMessages(SendEntriesListPtr, TRUE); /* \trace SPEC-2046291 */
  }
}

/**********************************************************************************************************************
 *  Sd_AddEventGroupNackEntryToList()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_AddEventGroupNackEntryToList(
  SD_P2VAR(Sd_SendEntriesListType) SendEntriesListPtr,
  P2CONST(Sd_ServiceInstanceType, TYPEDEF, SD_CONST) ServiceInstancePtr,
  uint16 ServiceId,
  uint16 InstanceId,
  uint8 MajorVersion,
  uint16 ReservedField,
  uint16 EventHandlerId,
  SD_P2VAR(Sd_SockAddrContainerType) AddrPtr,
  uint32 AdditionalDelay)
{
  /* Search for an empty slot in order to save the message */
  uint16 EmptySlot = Sd_FindUnusedSlotInSendEntriesList(SendEntriesListPtr);

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries > EmptySlot)
  {
    /* Update the entry list */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].Valid = TRUE;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceId = ServiceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].InstanceId = InstanceId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].MajorVersion = MajorVersion;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].AddrPtr = AddrPtr;
    /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
    Sd_SetTimerOffsetNoTrigger(SendEntriesListPtr->SendEntryPtr[EmptySlot].TimeToSend, AdditionalDelay);
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ServiceInstancePtr = ServiceInstancePtr;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ReservedField = ReservedField;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EventHandlerPtr = NULL_PTR;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EventHandlerId = EventHandlerId;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ClientPtr = NULL_PTR;
    SendEntriesListPtr->SendEntryPtr[EmptySlot].ConsumedEventGroupPtr = NULL_PTR;          /* Parameter not used in case of a (no)acknowledge message */
    SendEntriesListPtr->SendEntryPtr[EmptySlot].EntryType = SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK;
    SendEntriesListPtr->NrOfSendEntries++;
  }

  if(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries == SendEntriesListPtr->NrOfSendEntries)
  {
    /* The sendentry list is full, trigger a transmission */
    Sd_ProcessPendingMessages(SendEntriesListPtr, TRUE);
  }
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Sd_EntryListContainsSubscribe()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(boolean, SD_CODE) Sd_EntryListContainsSubscribe(
  SD_P2CONST(Sd_SendEntriesListType) SendEntriesListPtr,
  SD_P2CONST(Sd_ConsumedEventGroupType) ConsumedEventGroupPtr)
{
  uint16 EntryIdx = 0;
  boolean ContainsSubscribe = FALSE;

  /* Check all possible entries */
  while(SendEntriesListPtr->RootInstancePtr->MaxNrRxTxEntries > EntryIdx)
  {
    if(TRUE == SendEntriesListPtr->SendEntryPtr[EntryIdx].Valid)
    {
      /* Found a valid entry */
      /* Check if the entry is a Subscribe-Entry for the relevant ConsumedEventGroup */
      if((SD_ENTRY_SUBSCRIBE_EVENTGROUP == SendEntriesListPtr->SendEntryPtr[EntryIdx].EntryType) &&
        (ConsumedEventGroupPtr == SendEntriesListPtr->SendEntryPtr[EntryIdx].ConsumedEventGroupPtr))
      {
        ContainsSubscribe = TRUE;
        break;
      }
    }

    EntryIdx++;
  }

  return ContainsSubscribe;
}

/**********************************************************************************************************************
 *  Sd_GetSessionIdFlags()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_GetSessionIdFlags(
  SD_P2CONST(Sd_InstanceType) InstancePtr,
  SD_P2CONST(Sd_SockAddrContainerType) SockAddrPtr,
  SD_P2VAR(SD_P2VAR(uint16)) SessionIdPtrPtr,
  SD_P2VAR(SD_P2VAR(uint8)) FlagsPtrPtr)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint16 AddrIdx = InstancePtr->AddressStorageListSize;

  *SessionIdPtrPtr = NULL_PTR;

  while(0 < AddrIdx)
  {
    AddrIdx--;

    /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
    if((Sd_SockAddrIsEqual((SD_P2CONST(SoAd_SockAddrType))(&InstancePtr->AddressStorageListPtr[AddrIdx].Addr), (SD_P2CONST(SoAd_SockAddrType))SockAddrPtr)) &&
      (0 != InstancePtr->AddressStorageListPtr[AddrIdx].SessionIdCounter))
    {
      *SessionIdPtrPtr = &(InstancePtr->AddressStorageListPtr[AddrIdx].SessionIdCounter);
      *FlagsPtrPtr = &(InstancePtr->AddressStorageListPtr[AddrIdx].Flags);
      RetVal = E_OK;
      break;
    }
  }
  return RetVal;
}

/**********************************************************************************************************************
 *  Sd_SaveAddr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_SaveAddr(
  SD_P2CONST(Sd_InstanceType) InstancePtr,
  SD_P2CONST(Sd_SockAddrContainerType) InAddrPtr,
  SD_P2VAR(SD_P2VAR(Sd_AddressStorageType)) OutAddrStoragePtrPtr)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint16 AddrIdx = InstancePtr->AddressStorageListSize;
  boolean SaveAddr = TRUE;

  /* Check if the address is already saved */
  while(0 < AddrIdx)
  {
    AddrIdx--;

    /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
    if((Sd_SockAddrIsEqual((SD_P2CONST(SoAd_SockAddrType))(&InstancePtr->AddressStorageListPtr[AddrIdx].Addr), (SD_P2CONST(SoAd_SockAddrType))InAddrPtr)) &&
      (0 != InstancePtr->AddressStorageListPtr[AddrIdx].SessionIdCounter))
    {
      /* The address is already saved. Point to the address. */
      *OutAddrStoragePtrPtr = &InstancePtr->AddressStorageListPtr[AddrIdx];
      SaveAddr = FALSE;
      RetVal = E_OK;
      break;
    }
  }

  if(TRUE == SaveAddr)
  {
    /* Search for the next free slot and save the address */
    AddrIdx = InstancePtr->AddressStorageListSize;

    while(0 < AddrIdx)
    {
      AddrIdx--;

      if(0 == InstancePtr->AddressStorageListPtr[AddrIdx].SessionIdCounter)
      {
        /* Save the address and set the session counter to 1 */
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
        Sd_CopySockAddr((SD_P2VAR(SoAd_SockAddrType))(&InstancePtr->AddressStorageListPtr[AddrIdx].Addr), (SD_P2VAR(SoAd_SockAddrType))InAddrPtr);
        InstancePtr->AddressStorageListPtr[AddrIdx].SessionIdCounter = 1;
        InstancePtr->AddressStorageListPtr[AddrIdx].RxUnicastSessionId = 0;
        InstancePtr->AddressStorageListPtr[AddrIdx].RxMulticastSessionId = 0;
        InstancePtr->AddressStorageListPtr[AddrIdx].RxUnicastFlags = SD_FLAGS_REBOOT_MASK | SD_FLAGS_UNICAST_MASK;
        InstancePtr->AddressStorageListPtr[AddrIdx].RxMulticastFlags = SD_FLAGS_REBOOT_MASK | SD_FLAGS_UNICAST_MASK;
        *OutAddrStoragePtrPtr = &InstancePtr->AddressStorageListPtr[AddrIdx];
        RetVal = E_OK;
        break;
      }
    }
  }

  return RetVal;
}

/**********************************************************************************************************************
 *  Sd_SaveEndpoint()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_SaveEndpoint(
  SD_P2CONST(Sd_InstanceType) InstancePtr,
  SD_P2CONST(Sd_SockAddrContainerType) InAddrPtr,
  Sd_EndpointType Type,
  SD_P2VAR(SD_P2VAR(Sd_EndpointStorageType)) OutEndpointStoragePtrPtr)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint16 AddrIdx = InstancePtr->EndpointListSize;
  boolean SaveAddr = TRUE;

  if(SOAD_AF_INVALID != InAddrPtr->family)
  {
    /* Check if the address is already saved */
    while(0 < AddrIdx)
    {
      AddrIdx--;

      /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
      /* PRQA S 3415 2 */ /* MD_Sd_12.4_3415 */
      if((0 != InstancePtr->EndpointListPtr[AddrIdx].NrOfReferences) && (InstancePtr->EndpointListPtr[AddrIdx].Type == Type) &&
        (Sd_SockAddrIsEqual((SD_P2CONST(SoAd_SockAddrType))(&InstancePtr->EndpointListPtr[AddrIdx].Addr), (SD_P2CONST(SoAd_SockAddrType))InAddrPtr)))
      {
        /* The address is already saved. Point to the address. */
        *OutEndpointStoragePtrPtr = &InstancePtr->EndpointListPtr[AddrIdx];
        SaveAddr = FALSE;
        RetVal = E_OK;
        break;
      }
    }

    if(TRUE == SaveAddr)
    {
      /* Search for the next free slot and save the address */
      AddrIdx = InstancePtr->EndpointListSize;

      while(0 < AddrIdx)
      {
        AddrIdx--;

        if(SD_ENDPOINT_TYPE_INVALID == InstancePtr->EndpointListPtr[AddrIdx].Type)
        {
          /* Save the address and set the session counter to 1 */
          /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
          /* PRQA S 0311 1 */ /* MD_Sd_11.5_0311 */
          Sd_CopySockAddr((SD_P2VAR(SoAd_SockAddrType))(&InstancePtr->EndpointListPtr[AddrIdx].Addr), (SD_P2VAR(SoAd_SockAddrType))InAddrPtr);
          InstancePtr->EndpointListPtr[AddrIdx].Type = Type;
          *OutEndpointStoragePtrPtr = &InstancePtr->EndpointListPtr[AddrIdx];
          RetVal = E_OK;
          break;
        }
      }
    }
  }
  else
  {
    *OutEndpointStoragePtrPtr = NULL_PTR;
  }

  return RetVal;
}

/**********************************************************************************************************************
 *  Sd_RemoveEndpoint()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_RemoveEndpoint(
  SD_P2VAR(Sd_EndpointStorageType) EndpointStoragePtr)
{
  if(0 != EndpointStoragePtr->NrOfReferences)
  {
    EndpointStoragePtr->NrOfReferences--;
  }

  if(0 == EndpointStoragePtr->NrOfReferences)
  {
    EndpointStoragePtr->Addr.family = SOAD_AF_INVALID;
    EndpointStoragePtr->Type = SD_ENDPOINT_TYPE_INVALID;
  }
}

/**********************************************************************************************************************
 *  Sd_LocalIpAddrAssignmentChg()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, SD_CODE) Sd_LocalIpAddrAssignmentChg(
  SoAd_SoConIdType SoConId,
  SoAd_IpAddrStateType State)
{
  uint16 EventGroupIdx, ClientIdx;
  uint8 Netmask;
  Sd_SockAddrContainerType OwnAddr;
  Sd_SockAddrContainerType RouterAddr;
  uint16 InstanceIdx, ServiceInstanceIdx;
  SD_P2CONST(Sd_InstanceType) TmpInstancePtr;
  SD_P2CONST(Sd_ServiceInstanceType) TmpServiceInstancePtr;
  SD_P2CONST(Sd_ConsumedEventGroupType) TmpEventGroupPtr;
  SD_P2CONST(Sd_EventHandlerType) TmpEventHandlerPtr;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnVoid(!(SD_STATE_UNINIT == Sd_State), SD_API_ID_LOCAL_IP_ADDR_ASSIGNMENT_CHG, SD_E_NOT_INITIALIZED);
  Sd_CheckDetErrorReturnVoid(
    !((SOAD_IPADDR_STATE_ASSIGNED != State) && (SOAD_IPADDR_STATE_ONHOLD != State) && (SOAD_IPADDR_STATE_UNASSIGNED != State)),
    SD_API_ID_LOCAL_IP_ADDR_ASSIGNMENT_CHG, SD_E_INV_MODE);
  Sd_CheckDetErrorReturnVoid(!(SOAD_INV_SO_CON_ID == SoConId), SD_API_ID_LOCAL_IP_ADDR_ASSIGNMENT_CHG, SD_E_INV_ID);

  /* Iterate over all SdInstances in order to find the corresponding TxPdu */
  InstanceIdx = Sd_ConfigPtr->InstanceListSize;
  while(0 < InstanceIdx)
  {
    InstanceIdx--;
    TmpInstancePtr = Sd_GetInstancePtrByIdx(InstanceIdx);

    /* Check if the change occurred at the TxSoCon */
    if(SoConId == TmpInstancePtr->TxSoConId)
    {
      /* Save the state of the IP address */
      /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
      Sd_SetValueAndTrigger(TmpInstancePtr->DynamicDataPtr->State, (Sd_ServiceInstanceStateType)State, TmpInstancePtr);

      if(SOAD_IPADDR_STATE_ASSIGNED == State)
      {
        /* Open the socket connection again if a new address was assigned */
        TmpInstancePtr->DynamicDataPtr->InitialRun = SD_NEW_IP_ASSIGNED;

        /* Get the new address */
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        (void)SoAd_GetLocalAddr(SoConId, (SD_P2VAR(SoAd_SockAddrType))(&OwnAddr), &Netmask, (SD_P2VAR(SoAd_SockAddrType))(&RouterAddr));

        /* Save the address for all instances */
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        Sd_CopySockAddr((SD_P2VAR(SoAd_SockAddrType))&TmpInstancePtr->DynamicDataPtr->SdUnicastAddr, (SD_P2VAR(SoAd_SockAddrType))(&OwnAddr));
      }
      else  /* SOAD_IPADDR_STATE_ASSIGNED != State */
      {
        /* Reset the state of all service instances */
        ServiceInstanceIdx = TmpInstancePtr->ServiceInstancePtrListSize;
        while(0 < ServiceInstanceIdx)
        {
          ServiceInstanceIdx--;
          TmpServiceInstancePtr = TmpInstancePtr->ServiceInstancePtrListPtr[ServiceInstanceIdx];

          if(NULL_PTR != TmpServiceInstancePtr->ClientInstancePtr)
          {
            /* Reset the dynamic variables */
            TmpServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_SERVICE_NONE;
            TmpServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->ServerAddrPtr = NULL_PTR;
            TmpServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->ServerTcpEndpointAddr.family = SOAD_AF_INVALID;
            TmpServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->ServerUdpEndpointAddr.family = SOAD_AF_INVALID;
            TmpServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->OfferedTTL = 0;
            /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
            Sd_ResetTimerToZero(TmpServiceInstancePtr->ClientInstancePtr->DynamicTimerPtr->TimerTTL);
            Sd_ResetTimerToInvalid(TmpServiceInstancePtr->ClientInstancePtr->DynamicTimerPtr->TimeToTriggerSend);
            TmpServiceInstancePtr->ClientInstancePtr->DynamicTimerPtr->RepetitionRun = 0;

            EventGroupIdx = TmpServiceInstancePtr->ClientInstancePtr->NrOfEventGroups;
            while(0 < EventGroupIdx)
            {
              EventGroupIdx--;
              TmpEventGroupPtr = TmpServiceInstancePtr->ClientInstancePtr->EventGroupPtrPtr[EventGroupIdx];

              /* Reset the dynamic variables */
              TmpEventGroupPtr->DynamicDataPtr->Event = SD_CLIENT_EVENT_EVENTGROUP_NONE;
              TmpEventGroupPtr->DynamicDataPtr->AcknowledgedTTL = 0;
              Sd_ResetTimerToZero(TmpEventGroupPtr->DynamicDataPtr->TimerTTL); /* PRQA S 3109 */ /* MD_MSR_14.3 */

              /* Inform the BswM about the state of the consumed eventgroups. \trace CREQ-121006 */
              BswM_Sd_ConsumedEventGroupCurrentState(TmpEventGroupPtr->EventGroupHandleId, SD_CONSUMED_EVENTGROUP_DOWN);
              TmpEventGroupPtr->DynamicDataPtr->CurrentState = SD_CONSUMED_EVENTGROUP_DOWN;
            }

            /* Inform the BswM about the state of the client service instance. \trace CREQ-121005 */
            BswM_Sd_ClientServiceCurrentState(TmpServiceInstancePtr->HandleId, SD_CLIENT_SERVICE_DOWN);
            TmpServiceInstancePtr->ClientInstancePtr->DynamicDataPtr->CurrentState = SD_CLIENT_SERVICE_DOWN;
          }
          else  /* NULL_PTR != TmpServiceInstancePtr->ServerInstancePtr */
          {
            /* Reset the dynamic variables */
            TmpServiceInstancePtr->ServerInstancePtr->DynamicTimerPtr->InitialOfferRepetitionRun = 0;
            /* PRQA S 3109 1 */ /* MD_MSR_14.3 */
            Sd_ResetTimerToInvalid(TmpServiceInstancePtr->ServerInstancePtr->DynamicTimerPtr->TimeToTriggerSend);

            EventGroupIdx = TmpServiceInstancePtr->ServerInstancePtr->NrOfEventHandlers;
            while(0 < EventGroupIdx)
            {
              EventGroupIdx--;
              TmpEventHandlerPtr = &TmpServiceInstancePtr->ServerInstancePtr->EventHandlerPtr[EventGroupIdx];

              /* Reset the dynamic variables */
              Sd_UpdateEventHandlerStateMachine(TmpEventHandlerPtr, SD_EVENT_HANDLER_STATE_NONE);
              TmpEventHandlerPtr->DynamicDataPtr->NrOfClients = 0;
              TmpEventHandlerPtr->DynamicDataPtr->NrOfClientsUdp = 0;

              /* Update all clients */
              ClientIdx = TmpEventHandlerPtr->MaxNrHandledClients;
              while(0 < ClientIdx)
              {
                ClientIdx--;

                /* Reset all clients */
                TmpEventHandlerPtr->ClientListPtr[ClientIdx].ClientState = SD_EVENT_HANDLER_CLIENT_STATE_INVALID;
              }

              /* Inform the BswM about the state of all event handlers. \trace CREQ-121004 */
              BswM_Sd_EventHandlerCurrentState(TmpEventHandlerPtr->EventGroupHandleId, SD_EVENT_HANDLER_RELEASED);
              Sd_SetValueAndTrigger(TmpEventHandlerPtr->DynamicDataPtr->RequestStateEG, SD_EVENT_HANDLER_RELEASED,
                TmpInstancePtr);
            }
          }
        }
      }
    }
  }
} /* PRQA S 2006, 6030, 6080 */ /* MD_MSR_14.7, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_SoConModeChg()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, SD_CODE) Sd_SoConModeChg(
  SoAd_SoConIdType SoConId,
  SoAd_SoConModeType Mode)
{
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnVoid(!(SD_STATE_UNINIT == Sd_State), SD_API_ID_RX_INDICATION, SD_E_NOT_INITIALIZED);
  Sd_CheckDetErrorReturnVoid(!((SOAD_SOCON_ONLINE != Mode) && (SOAD_SOCON_RECONNECT != Mode) && (SOAD_SOCON_OFFLINE != Mode)), SD_API_ID_RX_INDICATION, SD_E_INV_MODE);

  /* Save the current mode of the socket connection */
  Sd_SetSoConMode(SoConId, Mode);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  Sd_SetSoConMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_SetSoConMode(
  SoAd_SoConIdType SoConId,
  SoAd_SoConModeType Mode)
{
  boolean SoConModeSaved = FALSE;
  uint16 SoConModeMapIdx;

  /* Check if the SoConId is already part of the map */
  SoConModeMapIdx = Sd_ConfigPtr->SoConModeMapSize;
  while(0 < SoConModeMapIdx)
  {
    SoConModeMapIdx--;

    if(SoConId == Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConId)
    {
      SoConModeSaved = TRUE;
      break;
    }
  }

  if(FALSE == SoConModeSaved)
  {
    /* Search for an unused slot to save the mode */
    SoConModeMapIdx = Sd_ConfigPtr->SoConModeMapSize;
    while(0 < SoConModeMapIdx)
    {
      SoConModeMapIdx--;

      if(SOAD_INV_SO_CON_ID == Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConId)
      {
        Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConId = SoConId;
        SoConModeSaved = TRUE;
        break;
      }
    }
  }

  if(TRUE == SoConModeSaved)
  {
    /* Update the mode */
    if(((SD_SOCON_MODE_ONLINE == Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConMode) ||
      (SD_SOCON_MODE_RECONNECT == Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConMode)) &&
      (SOAD_SOCON_OFFLINE == Mode))
    {
      Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConMode = SD_SOCON_MODE_LOST_CONNECTION;
    }
    else
    {
      Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConMode = (Sd_SoConModeType)Mode;
    }
  }
}

/**********************************************************************************************************************
 *  Sd_GetSoConMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Sd_SoConModeType, SD_CODE) Sd_GetSoConMode(
  SoAd_SoConIdType SoConId)
{
  Sd_SoConModeType TmpSoConMode = SD_SOCON_MODE_INVALID;
  uint16 SoConModeMapIdx;

  /* Search for the SoConId */
  SoConModeMapIdx = Sd_ConfigPtr->SoConModeMapSize;
  while(0 < SoConModeMapIdx)
  {
    SoConModeMapIdx--;

    if(SoConId == Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConId)
    {
      /* Found the socket connection */
      TmpSoConMode = Sd_ConfigPtr->SoConModeMapPtr[SoConModeMapIdx].SoConMode;
      break;
    }
  }

  return TmpSoConMode;
}

/**********************************************************************************************************************
 *  Sd_ReadEndpointOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ReadEndpointOption(
  Sd_FamilyType FamilyType,
  SD_P2CONST(uint8) DataPtr,
  uint16 DataIndex,
  SD_P2VAR(Sd_SockAddrContainerType) EndpointAddrPtr)
{
  Std_ReturnType RetVal = E_OK;
  EndpointAddrPtr->family = FamilyType;

  if(SOAD_AF_INET == FamilyType)
  {
    EndpointAddrPtr->data[0] =
      IPBASE_SWAP32(((uint32)(DataPtr[DataIndex + SD_IPV4_ENDPOINT_ADDR_OFFSET]) << 24) |
      ((uint32)(DataPtr[DataIndex + SD_IPV4_ENDPOINT_ADDR_OFFSET + 1]) << 16) |
      ((uint32)(DataPtr[DataIndex + SD_IPV4_ENDPOINT_ADDR_OFFSET + 2]) << 8) |
      ((uint32)(DataPtr[DataIndex + SD_IPV4_ENDPOINT_ADDR_OFFSET + 3])));

    if(0 == EndpointAddrPtr->data[0])
    {
      /* Mark the endpoint address as invalid if no definite address is defined */
      EndpointAddrPtr->family = SOAD_AF_INVALID;
      RetVal = E_NOT_OK;
    }

    EndpointAddrPtr->port =
      (uint16)IPBASE_SWAP16(((uint16)(DataPtr[DataIndex + SD_IPV4_ENDPOINT_PORT_OFFSET]) << 8) |
      ((uint16)(DataPtr[DataIndex + SD_IPV4_ENDPOINT_PORT_OFFSET + 1])));
  }
  else /* SOAD_AF_INET6 == FamilyType */
  {
    /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
    /* PRQA S 0311 2 */ /* MD_Sd_11.5_0311 */
    IpBase_Copy((SD_P2VAR(IpBase_CopyDataType))(EndpointAddrPtr->data),
      (SD_P2VAR(IpBase_CopyDataType))(&DataPtr[DataIndex + SD_IPV6_ENDPOINT_ADDR_OFFSET]), 16);

    if(0 == (EndpointAddrPtr->data[0] | EndpointAddrPtr->data[1] | EndpointAddrPtr->data[2] | EndpointAddrPtr->data[3]))
    {
      /* Mark the endpoint address as invalid if no definite address is defined */
      EndpointAddrPtr->family = SOAD_AF_INVALID;
      RetVal = E_NOT_OK;
    }

    EndpointAddrPtr->port =
      (uint16)IPBASE_SWAP16(((uint16)(DataPtr[DataIndex + SD_IPV6_ENDPOINT_PORT_OFFSET]) << 8) |
      ((uint16)(DataPtr[DataIndex + SD_IPV6_ENDPOINT_PORT_OFFSET + 1])));
  }

  if(SD_TCPIP_PORT_ANY == EndpointAddrPtr->port)
  {
    /* Mark the endpoint address as invalid if no definite port is defined */
    EndpointAddrPtr->family = SOAD_AF_INVALID;
    RetVal = E_NOT_OK;
  }

  return RetVal;
}

/**********************************************************************************************************************
 *  Sd_CheckConfigOption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_CheckConfigOption(
  SD_P2CONST(uint8) DataPtr,
  SD_P2VAR(Sd_ConfigOptionStringType) ConfigOptionPtrArrayPtr)
{
  SD_P2CONST(uint8) PayloadPtr; /* Payload including Reserved Field */
  Std_ReturnType RetVal = E_OK;
  boolean correctTermination = FALSE;
  uint8 ItemLength;
  uint16 LengthOfOption, TmpIndex = 0;

  LengthOfOption = (uint16)((uint16)(DataPtr[TmpIndex]) << 8) | ((uint16)(DataPtr[TmpIndex+1]));
  TmpIndex = SD_SIZE_OF_OPTION_LENGTH_FIELD + SD_SIZE_OF_TYPE_FIELD;
  PayloadPtr = &DataPtr[TmpIndex];

  /* Skip Reserved Field */
  TmpIndex = SD_SIZE_OF_RESERVED_FIELD;

  /* Check configuration string */
  while((LengthOfOption > TmpIndex) && (E_OK == RetVal))
  {
    ItemLength = PayloadPtr[TmpIndex];
    TmpIndex++;

    if(0 == ItemLength)
    {
      /* Termination of capability string */
      correctTermination = TRUE;
      break;
    }

    if(LengthOfOption >= (ItemLength + TmpIndex))
    {
      TmpIndex += ItemLength;
    }
    else
    {
      RetVal = E_NOT_OK;
    }
  }

  if(TRUE == correctTermination)
  {
    /* Save reverence to the configuration string in the list of configuration options */
    if(NULL_PTR == ConfigOptionPtrArrayPtr[0])
    {
      ConfigOptionPtrArrayPtr[0] = &PayloadPtr[SD_SIZE_OF_RESERVED_FIELD];
    }
    else if(NULL_PTR == ConfigOptionPtrArrayPtr[1])
    {
      ConfigOptionPtrArrayPtr[1] = &PayloadPtr[SD_SIZE_OF_RESERVED_FIELD];
    }
    else
    {
      /* Only two configuration options are allowed per message */
      RetVal = E_NOT_OK;
    }
  }

  return RetVal;
}

/**********************************************************************************************************************
 *  Sd_CopySockAddr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(void, SD_CODE) Sd_CopySockAddr(
  SD_P2VAR(SoAd_SockAddrType) TgtSockPtr,
  SD_P2CONST(SoAd_SockAddrType) SrcSockPtr)
{
  uint8 CopyLen;

  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnVoid(!(NULL_PTR == TgtSockPtr), SD_API_ID_INTERNAL, SD_E_PARAM_POINTER);
  Sd_CheckDetErrorReturnVoid(!(NULL_PTR == SrcSockPtr), SD_API_ID_INTERNAL, SD_E_PARAM_POINTER);

  if(SOAD_AF_INVALID != SrcSockPtr->domain)
  {
    if(SOAD_AF_INET == SrcSockPtr->domain)
    {
      CopyLen = sizeof(SoAd_SockAddrInetType);
    }
    else if(SOAD_AF_INET6 == SrcSockPtr->domain)
    {
      CopyLen = sizeof(SoAd_SockAddrInet6Type);
    }
    else
    {
      /* Domain Type not supported */
      TgtSockPtr->domain = SOAD_AF_INVALID;
      CopyLen = 0;
    }

    /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
    IpBase_Copy((SD_P2VAR(IpBase_CopyDataType))TgtSockPtr, (SD_P2CONST(IpBase_CopyDataType))SrcSockPtr, CopyLen);
  }
  else
  {
    /* Source address is invalid, set the target address as invalid */
    TgtSockPtr->domain = SOAD_AF_INVALID;
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  Sd_CompareSockAddrIp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Sd_MatchType, SD_CODE) Sd_CompareSockAddrIp(
  SD_P2CONST(SoAd_SockAddrType) SockAPtr,
  SD_P2CONST(SoAd_SockAddrType) SockBPtr,
  uint8 AddrState)
{
  Sd_MatchType MatchType;

  if((NULL_PTR != SockAPtr) && (NULL_PTR != SockBPtr))
  {
    if(SockAPtr->domain == SockBPtr->domain)
    {
      /* Check the IP address */
      if(0 < (AddrState & SOAD_SOCON_MASK_IPADDR & SOAD_SOCON_MASK_ANY))
      {
        MatchType = SD_MATCH_ANY;
      }
      else
      {
        if(SOAD_AF_INET == SockAPtr->domain)
        {
          /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
          if(((SD_P2CONST(SoAd_SockAddrInetType))SockAPtr)->addr[0] != ((SD_P2CONST(SoAd_SockAddrInetType))SockBPtr)->addr[0])
          {
            MatchType = SD_MATCH_FALSE;
          }
          else
          {
            MatchType = SD_MATCH_TRUE;
          }
        }
        else if(SOAD_AF_INET6 == SockAPtr->domain)
        {
          uint8 uin32Blocks = 4;

          MatchType = SD_MATCH_TRUE;

          while(0 != uin32Blocks)
          {
            uin32Blocks--;

            /* Check the IP addresses */
            /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
            if(((SD_P2CONST(SoAd_SockAddrInet6Type))SockAPtr)->addr[uin32Blocks] != ((SD_P2CONST(SoAd_SockAddrInet6Type))SockBPtr)->addr[uin32Blocks])
            {
              MatchType = SD_MATCH_FALSE;
            }
          }
        }
        else
        {
          /* Undefined domain type */
          MatchType = SD_MATCH_FALSE;
        }
      }
    }
    else
    {
      MatchType = SD_MATCH_FALSE;
    }
  }
  else
  {
    MatchType = SD_MATCH_FALSE;
  }

  return MatchType;
} /* PRQA S 2006, 6030, 6080 */ /* MD_MSR_14.7, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_CompareSockAddrPort()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Sd_MatchType, SD_CODE) Sd_CompareSockAddrPort(
  SD_P2CONST(SoAd_SockAddrType) SockAPtr,
  SD_P2CONST(SoAd_SockAddrType) SockBPtr,
  uint8 AddrState)
{
  Sd_MatchType MatchType;

  if((NULL_PTR != SockAPtr) && (NULL_PTR != SockBPtr))
  {
    if(SockAPtr->domain == SockBPtr->domain)
    {
      /* Check the IP address */
      if(0 < ((AddrState & SOAD_SOCON_MASK_PORT) & SOAD_SOCON_MASK_ANY))
      {
        MatchType = SD_MATCH_ANY;
      }
      else
      {
        if(SOAD_AF_INET == SockAPtr->domain)
        {
          /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
          if(((SD_P2CONST(SoAd_SockAddrInetType))SockAPtr)->port != ((SD_P2CONST(SoAd_SockAddrInetType))SockBPtr)->port)
          {
            MatchType = SD_MATCH_FALSE;
          }
          else
          {
            MatchType = SD_MATCH_TRUE;
          }
        }
        else if(SOAD_AF_INET6 == SockAPtr->domain)
        {
          /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
          if(((SD_P2CONST(SoAd_SockAddrInet6Type))SockAPtr)->port != ((SD_P2CONST(SoAd_SockAddrInet6Type))SockBPtr)->port)
          {
            MatchType = SD_MATCH_FALSE;
          }
          else
          {
            MatchType = SD_MATCH_TRUE;
          }
        }
        else
        {
          /* Undefined domain type */
          MatchType = SD_MATCH_FALSE;
        }
      }
    }
    else
    {
      MatchType = SD_MATCH_FALSE;
    }
  }
  else
  {
    MatchType = SD_MATCH_FALSE;
  }

  return MatchType;
} /* PRQA S 2006, 6080 */ /* MD_MSR_14.7, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_SockAddrIsEqual()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(boolean, SD_CODE) Sd_SockAddrIsEqual(
  SD_P2CONST(SoAd_SockAddrType) SockAPtr,
  SD_P2CONST(SoAd_SockAddrType) SockBPtr)
{
  boolean Equal = TRUE;

  if((NULL_PTR != SockAPtr) && (NULL_PTR != SockBPtr))
  {
    if(SockAPtr->domain == SockBPtr->domain)
    {
      if(SOAD_AF_INET == SockAPtr->domain)
      {
        /* Check the IP addresses */
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        if(((SD_P2CONST(SoAd_SockAddrInetType))SockAPtr)->addr[0] != ((SD_P2CONST(SoAd_SockAddrInetType))SockBPtr)->addr[0])
        {
          Equal = FALSE;
        }
        /* Check the Ports */
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        if(((SD_P2CONST(SoAd_SockAddrInetType))SockAPtr)->port != ((SD_P2CONST(SoAd_SockAddrInetType))SockBPtr)->port)
        {
          Equal = FALSE;
        }
      }
      else if(SOAD_AF_INET6 == SockAPtr->domain)
      {
        uint8 uin32Blocks = 4;

        while(0 != uin32Blocks)
        {
          uin32Blocks--;

          /* Check the IP addresses */
          /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
          if(((SD_P2CONST(SoAd_SockAddrInet6Type))SockAPtr)->addr[uin32Blocks] != ((SD_P2CONST(SoAd_SockAddrInet6Type))SockBPtr)->addr[uin32Blocks])
          {
            Equal = FALSE;
            break;
          }
        }

        /* Check the Ports */
        /* PRQA S 0310 1 */ /* MD_Sd_11.4_0310 */
        if(((SD_P2CONST(SoAd_SockAddrInet6Type))SockAPtr)->port != ((SD_P2CONST(SoAd_SockAddrInet6Type))SockBPtr)->port)
        {
          Equal = FALSE;
        }
      }
      else
      {
        /* domain type is not specified */
        Equal = FALSE;
      }
    }
    else
    {
      Equal = FALSE;
    }
  }
  else
  {
    Equal = FALSE;
  }

  return Equal;
} /* PRQA S 2006, 6030, 6080 */ /* MD_MSR_14.7, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_SockAddrWithinSubnet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(boolean, SD_CODE) Sd_SockAddrWithinSubnet(
  SD_P2CONST(SoAd_SockAddrType) SockAPtr,
  SD_P2CONST(SoAd_SockAddrType) SockBPtr,
  uint8 NetmaskCidr)
{
  boolean SameSubnet = FALSE;

  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  Sd_CheckDetErrorReturnValue((NULL_PTR != SockAPtr), SD_API_ID_INTERNAL, SD_E_PARAM_POINTER, FALSE);
  Sd_CheckDetErrorReturnValue((NULL_PTR != SockBPtr), SD_API_ID_INTERNAL, SD_E_PARAM_POINTER, FALSE);

  if(SockAPtr->domain == SockBPtr->domain)
  {
    if(0 == NetmaskCidr)
    {
      /* This check considers the special case in which a 32 bit value would be shifted for 32 bits. */
      /* This special case would lead to an undefined result. */
      SameSubnet = TRUE;
    }
    else
    {
      /* Check IPv4 addresses. The netmask can be in the range [1 .. 32] */
      if((SOAD_AF_INET == SockAPtr->domain) && (32 >= NetmaskCidr))
      {
        uint32 AddrA, AddrB;

        /* Generate a copy of the IP addresses */
        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        AddrA = ((SD_P2CONST(SoAd_SockAddrInetType))SockAPtr)->addr[0];
        AddrB = ((SD_P2CONST(SoAd_SockAddrInetType))SockBPtr)->addr[0];

        /* Convert to network byte order */
        AddrA = IPBASE_SWAP32(AddrA);
        AddrB = IPBASE_SWAP32(AddrB);

        /* Shift to remove the variable parts of the IP address */
        AddrA >>= (32U - NetmaskCidr);
        AddrB >>= (32U - NetmaskCidr);

        /* Compare the remaining par of the addresses */
        if(AddrA == AddrB)
        {
          SameSubnet = TRUE;
        }
      }
      /* Check IPv6 addresses. The netmask can be in the range [1 .. 128] */
      else if((SOAD_AF_INET6 == SockAPtr->domain) && (128 >= NetmaskCidr))
      {
        uint32 AddrA[4], AddrB[4];

        /* Generate a copy of the IP addresses */
        /* PRQA S 0310 8 */ /* MD_Sd_11.4_0310 */
        AddrA[0] = ((SD_P2CONST(SoAd_SockAddrInet6Type))SockAPtr)->addr[0];
        AddrA[1] = ((SD_P2CONST(SoAd_SockAddrInet6Type))SockAPtr)->addr[1];
        AddrA[2] = ((SD_P2CONST(SoAd_SockAddrInet6Type))SockAPtr)->addr[2];
        AddrA[3] = ((SD_P2CONST(SoAd_SockAddrInet6Type))SockAPtr)->addr[3];
        AddrB[0] = ((SD_P2CONST(SoAd_SockAddrInet6Type))SockBPtr)->addr[0];
        AddrB[1] = ((SD_P2CONST(SoAd_SockAddrInet6Type))SockBPtr)->addr[1];
        AddrB[2] = ((SD_P2CONST(SoAd_SockAddrInet6Type))SockBPtr)->addr[2];
        AddrB[3] = ((SD_P2CONST(SoAd_SockAddrInet6Type))SockBPtr)->addr[3];

        /* Convert to network byte order */
        AddrA[0] = IPBASE_SWAP32(AddrA[0]);
        AddrA[1] = IPBASE_SWAP32(AddrA[1]);
        AddrA[2] = IPBASE_SWAP32(AddrA[2]);
        AddrA[3] = IPBASE_SWAP32(AddrA[3]);
        AddrB[0] = IPBASE_SWAP32(AddrB[0]);
        AddrB[1] = IPBASE_SWAP32(AddrB[1]);
        AddrB[2] = IPBASE_SWAP32(AddrB[2]);
        AddrB[3] = IPBASE_SWAP32(AddrB[3]);

        /* Shift to remove the variable parts of the IP address */
        if(32U > NetmaskCidr)
        {
          AddrA[3] >>= (32U - NetmaskCidr);
          AddrB[3] >>= (32U - NetmaskCidr);
        }
        else if(64U > NetmaskCidr)
        {
          if(32U != NetmaskCidr)
          {
            AddrA[2] >>= (64U - NetmaskCidr);
            AddrB[2] >>= (64U - NetmaskCidr);
          }
          AddrA[3] = 0;
          AddrB[3] = 0;
        }
        else if(96U > NetmaskCidr)
        {
          if(64U != NetmaskCidr)
          {
            AddrA[1] >>= (96U - NetmaskCidr);
            AddrB[1] >>= (96U - NetmaskCidr);
          }
          AddrA[2] = 0;
          AddrA[3] = 0;
          AddrB[2] = 0;
          AddrB[3] = 0;
        }
        else if(128U > NetmaskCidr)
        {
          if(96U != NetmaskCidr)
          {
            AddrA[0] >>= (128U - NetmaskCidr);
            AddrB[0] >>= (128U - NetmaskCidr);
          }
          AddrA[1] = 0;
          AddrA[2] = 0;
          AddrA[3] = 0;
          AddrB[1] = 0;
          AddrB[2] = 0;
          AddrB[3] = 0;
        }
        else
        {
          /* Netmask is too big, check if both addresses are identical */
        }

        /* Compare both IP addresses */
        if((AddrA[0] == AddrB[0]) &&
          (AddrA[1] == AddrB[1]) &&
          (AddrA[2] == AddrB[2]) &&
          (AddrA[3] == AddrB[3]))
        {
          SameSubnet = TRUE;
        }
      }
      else
      {
        /* The domain is undefined or the netmask is out of range */
      }
    }
  }

  return SameSubnet;
} /* PRQA S 2006, 6010, 6030, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_FindBestMatchLocalRemoteSoCon()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_FindBestMatchLocalRemoteSoCon(
  SD_P2CONST(SoAd_SoConIdType) MulticastSoConPtr,
  uint16 NrMulticastSoCons,
  SD_P2CONST(Sd_DynamicClientServiceType) ClientConfigPtr,
  SD_P2VAR(uint16) ElementIdxPtr,
  SD_P2VAR(boolean) LocalIpAddrExactMatch,
  SD_P2VAR(boolean) LocalPortExactMatch,
  SD_P2VAR(boolean) RemoteAddrExactMatch)
{
  Std_ReturnType RetVal;
  uint16 TmpElementIdx, BestElementIdx = 0, LocalMatchPrio = 0, RemoteMatchPrio = 0, TmpLocalMatchPrio;
  Sd_SockAddrContainerType LocalAddr;
  Sd_SockAddrContainerType DefaultRouter;
  uint8 NetmaskCidr = 0;
  Sd_SockAddrContainerType RemoteAddr;
  Sd_MatchType LocalIpMatchType, LocalPortMatchType, RemoteIpMatchType, RemotePortMatchType;
  uint8 LocalAddrState, RemoteAddrState;

  *LocalIpAddrExactMatch = FALSE;
  *LocalPortExactMatch = FALSE;
  *RemoteAddrExactMatch = FALSE;

  TmpElementIdx = NrMulticastSoCons;
  while(0 < TmpElementIdx)
  {
    TmpElementIdx--;

    /* Get the configured local and remote IP address */
    /* PRQA S 0310 3 */ /* MD_Sd_11.4_0310 */
    RetVal = SoAd_GetLocalAddr(MulticastSoConPtr[TmpElementIdx],
      (SD_P2VAR(SoAd_SockAddrType))&LocalAddr, &NetmaskCidr, (SD_P2VAR(SoAd_SockAddrType))&DefaultRouter);
    RetVal |= SoAd_GetRemoteAddr(MulticastSoConPtr[TmpElementIdx], (SD_P2VAR(SoAd_SockAddrType))&RemoteAddr);

    if(E_OK == RetVal)
    {
      TmpLocalMatchPrio = 0;

      /* Calculate the state of the local address */
      if(SOAD_PORT_ANY == LocalAddr.port)
      {
        LocalAddrState = SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_PORT;
      }
      else
      {
        LocalAddrState = SOAD_SOCON_IP_SET_PORT_SET & SOAD_SOCON_MASK_PORT;
      }

      if(SOAD_AF_INET == LocalAddr.family)
      {
        if(SOAD_IPADDR_ANY == LocalAddr.data[0])
        {
          LocalAddrState = (uint8)(LocalAddrState | (SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_IPADDR));
        }
        else
        {
          LocalAddrState = (uint8)(LocalAddrState | (SOAD_SOCON_IP_SET_PORT_SET & SOAD_SOCON_MASK_IPADDR));
        }
      }
      else if(SOAD_AF_INET6 == LocalAddr.family)
      {
        if((SOAD_IPADDR_ANY == LocalAddr.data[0]) && (SOAD_IPADDR_ANY == LocalAddr.data[1]) &&
          (SOAD_IPADDR_ANY == LocalAddr.data[2]) && (SOAD_IPADDR_ANY == LocalAddr.data[3]))
        {
          LocalAddrState = (uint8)(LocalAddrState | (SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_IPADDR));
        }
        else
        {
          LocalAddrState = (uint8)(LocalAddrState | (SOAD_SOCON_IP_SET_PORT_SET & SOAD_SOCON_MASK_IPADDR));
        }
      }
      else
      {
        /* Undefined domain type */
      }

      /* Calculate the state of the remote address */
      if(SOAD_PORT_ANY == RemoteAddr.port)
      {
        RemoteAddrState = SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_PORT;
      }
      else
      {
        RemoteAddrState = SOAD_SOCON_IP_SET_PORT_SET & SOAD_SOCON_MASK_PORT;
      }

      if(SOAD_AF_INET == RemoteAddr.family)
      {
        if(SOAD_IPADDR_ANY == RemoteAddr.data[0])
        {
          RemoteAddrState = (uint8)(RemoteAddrState | (SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_IPADDR));
        }
        else
        {
          RemoteAddrState = (uint8)(RemoteAddrState | (SOAD_SOCON_IP_SET_PORT_SET & SOAD_SOCON_MASK_IPADDR));
        }
      }
      else if(SOAD_AF_INET6 == RemoteAddr.family)
      {
        if((SOAD_IPADDR_ANY == RemoteAddr.data[0]) && (SOAD_IPADDR_ANY == RemoteAddr.data[1]) &&
          (SOAD_IPADDR_ANY == RemoteAddr.data[2]) && (SOAD_IPADDR_ANY == RemoteAddr.data[3]))
        {
          RemoteAddrState = (uint8)(RemoteAddrState | (SOAD_SOCON_IP_ANY_PORT_ANY & SOAD_SOCON_MASK_IPADDR));
        }
        else
        {
          RemoteAddrState = (uint8)(RemoteAddrState | (SOAD_SOCON_IP_SET_PORT_SET & SOAD_SOCON_MASK_IPADDR));
        }
      }
      else
      {
        /* Undefined domain type */
      }

      /* PRQA S 0310 8 */ /* MD_Sd_11.4_0310 */
      LocalIpMatchType = Sd_CompareSockAddrIp((SD_P2CONST(SoAd_SockAddrType))&ClientConfigPtr->ServerMulticastEndpointAddr,
        (SD_P2CONST(SoAd_SockAddrType))&LocalAddr, LocalAddrState);
      LocalPortMatchType = Sd_CompareSockAddrPort((SD_P2CONST(SoAd_SockAddrType))&ClientConfigPtr->ServerMulticastEndpointAddr,
        (SD_P2CONST(SoAd_SockAddrType))&LocalAddr, LocalAddrState);
      RemoteIpMatchType = Sd_CompareSockAddrIp((SD_P2CONST(SoAd_SockAddrType))&ClientConfigPtr->ServerUdpEndpointAddr,
        (SD_P2CONST(SoAd_SockAddrType))&RemoteAddr, RemoteAddrState);
      RemotePortMatchType = Sd_CompareSockAddrPort((SD_P2CONST(SoAd_SockAddrType))&ClientConfigPtr->ServerUdpEndpointAddr,
        (SD_P2CONST(SoAd_SockAddrType))&RemoteAddr, RemoteAddrState);

      if((SD_MATCH_FALSE == LocalIpMatchType) || (SD_MATCH_FALSE == LocalPortMatchType) ||
        (SD_MATCH_FALSE == RemoteIpMatchType) || (SD_MATCH_FALSE == RemotePortMatchType))
      {
        /* The IP address or the port do not match, stop comparison for this socket connection */
      }
      else
      {
        /* Calculate the match priority for the local IP address */
        if((SD_MATCH_TRUE == LocalIpMatchType) && (SD_MATCH_TRUE == LocalPortMatchType))
        {
          if(4 > LocalMatchPrio)
          {
            RemoteMatchPrio = 0;
            *RemoteAddrExactMatch = FALSE;
          }
          LocalMatchPrio = 4;
          TmpLocalMatchPrio = LocalMatchPrio;
          *LocalIpAddrExactMatch = TRUE;
          *LocalPortExactMatch = TRUE;
        }
        else if((SD_MATCH_TRUE == LocalIpMatchType) && (SD_MATCH_ANY == LocalPortMatchType))
        {
          if(3 > LocalMatchPrio)
          {
            RemoteMatchPrio = 0;
            *RemoteAddrExactMatch = FALSE;
          }
          if(3 >= LocalMatchPrio)
          {
            LocalMatchPrio = 3;
            TmpLocalMatchPrio = LocalMatchPrio;
            *LocalIpAddrExactMatch = TRUE;
          }
        }
        else if((SD_MATCH_ANY == LocalIpMatchType) && (SD_MATCH_TRUE == LocalPortMatchType))
        {
          if(2 > LocalMatchPrio)
          {
            RemoteMatchPrio = 0;
            *RemoteAddrExactMatch = FALSE;
          }
          if(2 >= LocalMatchPrio)
          {
            LocalMatchPrio = 2;
            TmpLocalMatchPrio = LocalMatchPrio;
          }
        }
        else if((SD_MATCH_ANY == LocalIpMatchType) && (SD_MATCH_ANY == LocalPortMatchType))
        {
          if(1 > LocalMatchPrio)
          {
            RemoteMatchPrio = 0;
            *RemoteAddrExactMatch = FALSE;
          }
          if(1 >= LocalMatchPrio)
          {
            LocalMatchPrio = 1;
            TmpLocalMatchPrio = LocalMatchPrio;
          }
        }
        else
        {
          /* The socket connections do not match */
        }

        /* Calculate the match priority for the remote IP address */
        if((SD_MATCH_TRUE == RemoteIpMatchType) && (SD_MATCH_TRUE == RemotePortMatchType) && (TmpLocalMatchPrio == LocalMatchPrio))
        {
          RemoteMatchPrio = 4;
          BestElementIdx = TmpElementIdx;
          *RemoteAddrExactMatch = TRUE;
        }
        else if((SD_MATCH_TRUE == RemoteIpMatchType) && (SD_MATCH_ANY == RemotePortMatchType) && (TmpLocalMatchPrio == LocalMatchPrio))
        {
          if(3 > RemoteMatchPrio)
          {
            RemoteMatchPrio = 3;
            BestElementIdx = TmpElementIdx;
          }
        }
        else if((SD_MATCH_ANY == RemoteIpMatchType) && (SD_MATCH_TRUE == RemotePortMatchType) && (TmpLocalMatchPrio == LocalMatchPrio))
        {
          if(2 > RemoteMatchPrio)
          {
            RemoteMatchPrio = 2;
            BestElementIdx = TmpElementIdx;
          }
        }
        else if((SD_MATCH_ANY == RemoteIpMatchType) && (SD_MATCH_ANY == RemotePortMatchType) && (TmpLocalMatchPrio == LocalMatchPrio))
        {
          if(1 > RemoteMatchPrio)
          {
            RemoteMatchPrio = 1;
            BestElementIdx = TmpElementIdx;
          }
        }
        else
        {
          /* The socket connections do not match */
        }
      }
    }
  }

  if((0 != LocalMatchPrio) && (0 != RemoteMatchPrio))
  {
    *ElementIdxPtr = BestElementIdx;
    RetVal = E_OK;
  }
  else
  {
    /* No SoCon found which matches the given IP address */
    RetVal = E_NOT_OK;
  }

  return RetVal;
} /* PRQA S 2006, 6010, 6030, 6060, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Sd_LocalIpAlreadyConfigured()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(boolean, SD_CODE) Sd_LocalIpAlreadyConfigured(
  SD_P2CONST(SoAd_SockAddrType) MulticastAddress)
{
  Std_ReturnType RetVal;
  uint16 SoConIdx;
  Sd_SockAddrContainerType LocalAddr;
  Sd_SockAddrContainerType DefaultRouter;
  uint8 NetmaskCidr = 0;
  boolean LocalIpConfigured = FALSE;

  SoConIdx = Sd_GetIpAddrRequestCntMapSize();
  while(0 < SoConIdx)
  {
    SoConIdx--;

    /* Get the configured local IP address */
    /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
    RetVal = SoAd_GetLocalAddr(Sd_GetIpAddrRequestCntEntry(SoConIdx).SoConId,
      (SD_P2VAR(SoAd_SockAddrType))&LocalAddr, &NetmaskCidr, (SD_P2VAR(SoAd_SockAddrType))&DefaultRouter);

    /* PRQA S 3415 3 */ /* MD_Sd_12.4_3415 */
    /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
    if((E_OK == RetVal) &&
      (SD_MATCH_TRUE == Sd_CompareSockAddrIp((SD_P2CONST(SoAd_SockAddrType)) &LocalAddr, MulticastAddress, SOAD_SOCON_IP_SET_PORT_SET)))
    {
      /* The multicast IP address is already configured */
      LocalIpConfigured = TRUE;
      break;
    }
  }

  return LocalIpConfigured;
}

/**********************************************************************************************************************
 *  Sd_RequestIpAddrAssignment()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_RequestIpAddrAssignment(
  SoAd_SoConIdType SoConId,
  SD_P2VAR(Sd_SockAddrContainerType) MulticastAddrPtr,
  boolean PerformRequest)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint16 TmpSoConIdx;

  /* Get the corresponding local IP address request count */
  TmpSoConIdx = Sd_GetIpAddrRequestCntMapSize();
  while(0 < TmpSoConIdx)
  {
    TmpSoConIdx--;

    if(SoConId == Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).SoConId)
    {
      RetVal = E_OK;

      if(((FALSE == *Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).PortSetPtr) || (0 == *Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).RequestCntPtr))
        && (TRUE == PerformRequest))
      {
        /* The multicast address and port have to be requested */
        Sd_SockAddrContainerType DefaultRouter;

        /* Create an unspecified address for the default router and netmask */
        uint8 NetmaskCidr = 0;
        DefaultRouter.family = MulticastAddrPtr->family;
        DefaultRouter.data[0] = 0;
        DefaultRouter.data[1] = 0;
        DefaultRouter.data[2] = 0;
        DefaultRouter.data[3] = 0;
        DefaultRouter.port = 0;

        /* PRQA S 0310 2 */ /* MD_Sd_11.4_0310 */
        RetVal = SoAd_RequestIpAddrAssignment(SoConId, SOAD_IPADDR_ASSIGNMENT_STATIC,
          (SD_P2VAR(SoAd_SockAddrType))MulticastAddrPtr, NetmaskCidr, (SD_P2VAR(SoAd_SockAddrType))&DefaultRouter);
      }

      if(E_OK == RetVal)
      {
        /* Increment the request counter */
        (*Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).RequestCntPtr)++;
        *Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).PortSetPtr = TRUE;
      }

      break;
    }
  }

  return RetVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  Sd_ReleaseIpAddrAssignment()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(Std_ReturnType, SD_CODE) Sd_ReleaseIpAddrAssignment(
  SoAd_SoConIdType SoConId)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint16 TmpSoConIdx;

  /* Get the corresponding local IP address request count */
  TmpSoConIdx = Sd_GetIpAddrRequestCntMapSize();
  while(0 < TmpSoConIdx)
  {
    TmpSoConIdx--;

    if(SoConId == Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).SoConId)
    {
      RetVal = E_OK;

      if(1 == *Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).RequestCntPtr)
      {
        if(FALSE == Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).StaticIpConfiguration)
        {
          /* The multicast address is only requested by a single client. Release the request */
          RetVal = SoAd_ReleaseIpAddrAssignment(SoConId);
        }
      }

      if(FALSE == Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).StaticPortConfiguration)
      {
        *Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).PortSetPtr = FALSE;
      }

      /* Decrement the request counter. (Even if the SoAd_ReleaseIpAddrAssignment fails) */
      (*Sd_GetIpAddrRequestCntEntry(TmpSoConIdx).RequestCntPtr)--;

      break;
    }
  }

  return RetVal;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  Sd_GetRandomNrInRange()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(uint32, SD_CODE) Sd_GetRandomNrInRange(
  uint32 MinValue,
  uint32 MaxValue)
{
  uint32 RandNo;

  if(MinValue == MaxValue)
  {
    /* No need to calculate a random number */
    RandNo = MinValue;
  }
  else
  {
    /* Calculate a random number in the range:  MinValue <= RandInRange <= MaxValue */
    RandNo = (Sd_ExternalRandomNumberFct() % ((MaxValue + 1) - MinValue)) + MinValue;
  }

  return RandNo;
}

/**********************************************************************************************************************
 *  Sd_GetRandomNrInRangeForResponse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(uint32, SD_CODE) Sd_GetRandomNrInRangeForResponse(
  uint32 MinValue,
  uint32 MaxValue,
  boolean InterruptContext)
{

  if(TRUE == InterruptContext)
  {
    /* Response is generated in context of message transmission */

    if((0 != MinValue) && (MinValue != MaxValue))
    {
      /* Increase the lower bound in order to consider the elapsed time between the last MainFunction and the RxIndication.  */
      MinValue += SD_MAIN_FCT_CYCLE_TIME_MS;
    }
  }
  else
  {
    /* Response is generated in context of MainFunction */

    if(MaxValue != 0)
    {
      /* Decrease the upper bound in order to consider the elapsed time between the last MainFunction and the RxIndication.  */
      if(MinValue == MaxValue)
      {
        MinValue -= SD_MAIN_FCT_CYCLE_TIME_MS;
      }

      MaxValue -= SD_MAIN_FCT_CYCLE_TIME_MS;
    }
  }

  return Sd_GetRandomNrInRange(MinValue, MaxValue);
}

/**********************************************************************************************************************
 *  Sd_CheckIfTimerExceeded()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
STATIC FUNC(boolean, SD_CODE) Sd_CheckIfTimerExceeded(
  Sd_ExtendedTimeType Timer,
  boolean EqualIsExceeded)
{
  boolean exceeded = FALSE;

  SD_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if(Sd_TimeMsSinceStart.Seconds > Timer.Seconds)
  {
    exceeded = TRUE;
  }
  else if(Sd_TimeMsSinceStart.Seconds == Timer.Seconds)
  {
    if(Sd_TimeMsSinceStart.Milliseconds > Timer.Milliseconds)
    {
      exceeded = TRUE;
    }
    else if((EqualIsExceeded) && (Sd_TimeMsSinceStart.Milliseconds == Timer.Milliseconds))
    {
      exceeded = TRUE;
    }
    else
    {
      /* Milliseconds are not exceeded */
    }
  }
  else
  {
    /* Seconds are not exceeded */
  }

  SD_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return exceeded;
}

#define SD_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:

   MD_Sd_5.6_0781:
     Reason:     The name is being used as a structure/union member as well as being a label, tag or
                 ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error / warning. The user has to rename the
                 objects leading to the violation.
   MD_Sd_8.8:
     Reason:     External linkage is required by forward declaration.
     Risk:       None
     Prevention: Not applicable
   MD_Sd_11.4_0310:
     Reason:     Pointer casts are standard proceeding in TcpIp address data handling. (Rule 0310, 3305)
     Risk:       None
     Prevention: Not applicable
   MD_Sd_11.5_0311:
     Reason:     Function requires variable input parameter instead of const input parameter. (Rule 0311)
     Risk:       Changes made inside the function are not realized
     Prevention: Not applicable
   MD_Sd_12.4_3415:
     Reason:     Function does not change any value and has therefore no side effects. (Rule 3415)
     Risk:       Changes made inside the function are not realized
     Prevention: Not applicable
   MD_Sd_13.7:
     Reason:     Check is required by AUTOSAR. (Rule 3355, 3356 3359)
     Risk:       None
     Prevention: Not applicable
   MD_Sd_13.7a:
     Reason:     Functionality is not implemented, but checks are already present.
     Risk:       None
     Prevention: Not applicable
   MD_Sd_16.7_3673:
     Reason:     The pointer is used to modify the addressed object within an inner function.
     Risk:       None
     Prevention: Not applicable
*/

/**********************************************************************************************************************
 *  END OF FILE: Sd.c
 *********************************************************************************************************************/
