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
 *         File:  Sd_Types.h
 *       Module:  SysService_AsrSd
 *    Generator:  SysService_AsrSd.jar (DaVinci Configurator Pro)
 *
 *  Description:  Types definitions of Service Discovery (SD)
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined(SD_TYPES_H)
#define SD_TYPES_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1 */


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "SoAd.h"
#include "IpBase_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SD_HEADER_PROTOCOL_VERSION            0x01U
#define SD_HEADER_INTERFACE_VERSION           0x01U
#define SD_HEADER_MESSAGE_TYPE                0x02U
#define SD_HEADER_RETURN_CODE                 0x00U
#define SD_FLAGS_REBOOT_MASK                  0x80U
#define SD_FLAGS_UNICAST_MASK                 0x40U
#define SD_TCPIP_PORT_ANY                     0x0000U

#define SD_SERVICE_ID_OTHERSERV               0xFFFEU

/* Entry Array wildcards */
#define SD_ENTRY_WILDCARD_SERVICE_ID          0xFFFFU         /* Only allowed for type 1 entries and FindService */
#define SD_ENTRY_WILDCARD_INSTANCE_ID         0xFFFFU         /* Only allowed for type 1 entries and FindService */
#define SD_ENTRY_WILDCARD_MAJOR_VERSION       0xFFU           /* Only allowed for type 1 entries */
#define SD_ENTRY_WILDCARD_MINOR_VERSION       0xFFFFFFFFU     /* Only allowed for type 1 entries */

#define SD_SIZE_OF_ENTRY_ARRAY_LENGTH_FIELD   4U
#define SD_SIZE_OF_OPTION_ARRAY_LENGTH_FIELD  4U
#define SD_SIZE_OF_OPTION_LENGTH_FIELD        2U
#define SD_SIZE_OF_TYPE_FIELD                 1U
#define SD_SIZE_OF_RESERVED_FIELD             1U
#define SD_SIZE_OF_ENTRY                      16U
#define SD_SIZE_OF_OPTION_IPv4                12U
#define SD_SIZE_NOT_COVERED_FIELDS_OF_OPTION  3U  /* SD_SIZE_OF_OPTION_LENGTH_FIELD + SD_SIZE_OF_TYPE_FIELD */
#define SD_MIN_SIZE_CONFIGURATION_OPTION      7U  /* SD_SIZE_NOT_COVERED_FIELDS_OF_OPTION + 1 {Reserved} + 1 {len} + 1 {=} + 1 {0}) */

#define SD_COVERED_LENGTH_OF_OPTION_IPv4      0x09U
#define SD_IPV4_ENDPOINT_ADDR_OFFSET          4U
#define SD_IPV4_ENDPOINT_L4PROTO_OFFSET       9U
#define SD_IPV4_ENDPOINT_PORT_OFFSET          10U
#define SD_SIZE_OF_OPTION_IPv6                24U
#define SD_COVERED_LENGTH_OF_OPTION_IPv6      0x15U
#define SD_IPV6_ENDPOINT_ADDR_OFFSET          4U
#define SD_IPV6_ENDPOINT_L4PROTO_OFFSET       21U
#define SD_IPV6_ENDPOINT_PORT_OFFSET          22U

#define SD_INV_DEM_ID                                   0U
#define SD_INV_TIMER_VALUE_16BIT                        0xFFFFU
#define SD_INV_TIMER_VALUE_32BIT                        0xFFFFFFFFUL
#define SD_INV_CAPABILITY_RECORD_CALLOUT_FUNCTION_IDX   0xFFU
#define SD_INV_OPTION_INDEX                             0xFFU

 /* PRQA S 3453 6 */ /* MD_MSR_19.7 */  /* PRQA S 0850 6 */ /* MD_MSR_19.8 */
#define SD_P2CONSTCFGROOT(Type)               P2CONST     (Type, AUTOMATIC, SD_PBCFG)
#define SD_P2CONST(Type)                      P2CONST     (Type, AUTOMATIC, SD_APPL_DATA)
#define SD_P2VAR(Type)                        P2VAR       (Type, AUTOMATIC, SD_APPL_VAR)
#define SD_CONSTP2VAR(Type)                   CONSTP2VAR  (Type, AUTOMATIC, SD_APPL_VAR)
#define SD_CONSTP2CONST(Type)                 CONSTP2CONST(Type, AUTOMATIC, SD_CONST)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Sd_StateType;
typedef uint16 Sd_Dem_EventIdType;

typedef uint16    Sd_FamilyType;

typedef struct
{
  Sd_FamilyType     family;
  SoAd_PortType     port;
  uint32            data[4];
} Sd_SockAddrContainerType;

typedef enum
{
  SD_INITIAL_RUN                              = 0U,
  SD_RUNNING                                  = 1U,
  SD_NEW_IP_ASSIGNED                          = 2U
} Sd_InitialRunType;

typedef enum
{
  SD_MATCH_FALSE                              = 0U,
  SD_MATCH_ANY                                = 2U,
  SD_MATCH_TRUE                               = 3U
} Sd_MatchType;

typedef enum
{
  SD_SOCON_MODE_ONLINE                        = 0U,  /* SOAD_SOCON_ONLINE          0x00U */
  SD_SOCON_MODE_RECONNECT                     = 1U,  /* SOAD_SOCON_RECONNECT       0x01U */
  SD_SOCON_MODE_OFFLINE                       = 2U,  /* SOAD_SOCON_OFFLINE         0x02U */
  SD_SOCON_MODE_LOST_CONNECTION               = 3U,
  SD_SOCON_MODE_INVALID                       = 10U
} Sd_SoConModeType;

typedef enum
{
  SD_ENTRY_UNDEFINED                          = 0U,
  SD_ENTRY_SERVICE_TYPE                       = 1U,
  SD_ENTRY_EVENTGROUP_TYPE                    = 2U
} Sd_EntryFormatType;

typedef enum
{
  SD_ENTRY_NONE                               = 0xAAU,
  SD_ENTRY_FIND_SERVICE                       = 0x00U,  /* Entry format type 1 - Services */
  SD_ENTRY_OFFER_SERVICE                      = 0x01U,  /* Entry format type 1 - Services */
  SD_ENTRY_STOP_OFFER_SERVICE                 = 0x81U,  /* Entry format type 1 - Services        Additional type to differentiate SendEntries */
  SD_ENTRY_SUBSCRIBE_EVENTGROUP               = 0x06U,  /* Entry format type 2 - Eventgroups */
  SD_ENTRY_STOP_SUBSCRIBE_EVENTGROUP          = 0x86U,  /* Entry format type 2 - Eventgroups     Additional type to differentiate SendEntries */
  SD_ENTRY_SUBSCRIBE_EVENTGROUP_ACK           = 0x07U,  /* Entry format type 2 - Eventgroups */
  SD_ENTRY_SUBSCRIBE_EVENTGROUP_NACK          = 0x87U   /* Entry format type 2 - Eventgroups     Additional type to differentiate SendEntries */
} Sd_EntryType;

#define SD_OPTION_MULTICAST_MASK                0x10U

typedef enum
{
  SD_OPTION_NONE                              = 0xAAU,
  SD_OPTION_CONFIGURATION                     = 0x01U,
  SD_OPTION_IPV4_ENDPOINT                     = 0x04U,
  SD_OPTION_IPV6_ENDPOINT                     = 0x06U,
  SD_OPTION_IPV4_MULTICAST                    = 0x14U,
  SD_OPTION_IPV6_MULTICAST                    = 0x16U,
  SD_OPTION_IPV4_SD_ENDPOINT                  = 0x24U, /* \trace SPEC-60067 */
  SD_OPTION_IPV6_SD_ENDPOINT                  = 0x26U, /* \trace SPEC-2046020 */
  SD_OPTION_RESERVED                          = 0x00U
} Sd_OptionType;

typedef enum
{
  SD_L4PROTOCOL_NONE                          = 0x00U,
  SD_L4PROTOCOL_TCP                           = 0x06U,
  SD_L4PROTOCOL_UDP                           = 0x11U
} Sd_L4ProtocolType;

typedef struct
{
  P2VAR(uint16, TYPEDEF, SD_APPL_VAR)         OptionIndexPtr;
  uint8                                       NrOfOptions;
} Sd_OptionIndexType;

typedef enum
{
  SD_SERVER_EVENT_EVENTGROUP_NONE                       = 0x00U,
  SD_SERVER_EVENT_EVENTGROUP_SUBSCRIBE                  = 0x10U,
  SD_SERVER_EVENT_EVENTGROUP_SUBSCRIBE_MULTI            = 0x11U,
  SD_SERVER_EVENT_EVENTGROUP_STOP_SUBSCRIBE             = 0x20U,
  SD_SERVER_EVENT_EVENTGROUP_STOP_SUBSCRIBE_MULTI       = 0x21U
} Sd_ServerEventgroupEventType;

typedef enum
{
  SD_SERVER_STATE_NONE                        = 0U,
  SD_SERVER_STATE_NOT_READY                   = 1U,
  SD_SERVER_STATE_READY_INITIAL_WAIT          = 2U,
  SD_SERVER_STATE_READY_REPETITION            = 3U,
  SD_SERVER_STATE_READY_MAIN_PHASE            = 4U
} Sd_ServerStateMachineType;

typedef enum
{
  SD_EVENT_HANDLER_STATE_NONE                     = 0U,
  SD_EVENT_HANDLER_STATE_SERVICE_DOWN             = 1U,
  SD_EVENT_HANDLER_STATE_NOT_SUBSCRIBED           = 2U,
  SD_EVENT_HANDLER_STATE_UNICAST_SUBSCRIPTION     = 3U,
  SD_EVENT_HANDLER_STATE_MULTICAST_SUBSCRIPTION   = 4U
} Sd_EventHandlerStateMachineType;

typedef enum
{
  SD_EVENT_HANDLER_CLIENT_STATE_INVALID       = 0U,
  SD_EVENT_HANDLER_CLIENT_STATE_UNSUBSCRIBED  = 1U,
  SD_EVENT_HANDLER_CLIENT_STATE_SUBSCRIBED    = 2U
} Sd_EventHandlerClientStateType;

typedef enum
{
  SD_TRIGGER_TRANSMIT_STATE_INVALID           = 0U,
  SD_TRIGGER_TRANSMIT_STATE_NEXT_CYCLE        = 1U,
  SD_TRIGGER_TRANSMIT_STATE_NOW               = 2U
} Sd_TriggerTransmitStateType;

typedef enum
{
  SD_CLIENT_EVENT_SERVICE_NONE                    = 0x00U,
  SD_CLIENT_EVENT_SERVICE_STOP_OFFER              = 0x10U,
  SD_CLIENT_EVENT_SERVICE_STOP_OFFER_OFFER_MULTI  = 0x11U,
  SD_CLIENT_EVENT_SERVICE_STOP_OFFER_OFFER_UNI    = 0x12U,
  SD_CLIENT_EVENT_SERVICE_OFFER                   = 0x20U,
  SD_CLIENT_EVENT_SERVICE_OFFER_MULTI             = 0x21U,
  SD_CLIENT_EVENT_SERVICE_OFFER_UNI               = 0x22U
} Sd_ClientServiceEventType;

typedef enum
{
  SD_CLIENT_EVENT_EVENTGROUP_NONE             = 0U,
  SD_CLIENT_EVENT_EVENTGROUP_ACK              = 3U,
  SD_CLIENT_EVENT_EVENTGROUP_NACK             = 4U
} Sd_ClientEventgroupEventType;

typedef enum
{
  SD_CLIENT_STATE_NONE                        = 0U,
  SD_CLIENT_STATE_NOT_REQUESTED_NOT_SEEN      = 1U,
  SD_CLIENT_STATE_NOT_REQUESTED_SEEN          = 2U,
  SD_CLIENT_STATE_REQUESTED_BUT_NOT_READY     = 3U,
  SD_CLIENT_STATE_SEARCHING_INITIAL_WAIT      = 4U,
  SD_CLIENT_STATE_SEARCHING_REPETITION        = 5U,
  SD_CLIENT_STATE_SERVICE_READY               = 6U,
  SD_CLIENT_STATE_STOPPED                     = 7U
} Sd_ClientStateMachineType;

/* PRQA S 0779 7 */ /* MD_MSR_5.1_779 */
typedef enum
{
  SD_CONSUMED_EVENTGROUP_STATE_UNSUBSCRIBED                   = 1U,
  SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT              = 2U,
  SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_MULTI_OFFER  = 3U,
  SD_CONSUMED_EVENTGROUP_STATE_REGISTRATION_SENT_RETRY        = 4U,
  SD_CONSUMED_EVENTGROUP_STATE_SUBSCRIBED                     = 5U
} Sd_ConsumedEventGroupStateMachineType;

/* This type defines the Server states that are reported to the SD using the expected API Sd_ServerServiceSetState. */
typedef enum
{
  SD_SERVER_SERVICE_DOWN                      = 0U,
  SD_SERVER_SERVICE_AVAILABLE                 = 1U
} Sd_ServerServiceSetStateType;

/* This type defines the Client states that are reported to the BswM using the expected API Sd_ClientServiceSetState. */
typedef enum
{
  SD_CLIENT_SERVICE_RELEASED                  = 0U,
  SD_CLIENT_SERVICE_REQUESTED                 = 1U
} Sd_ClientServiceSetStateType;

/* This type defines the subscription policy by consumed EventGroup for the Client Service. */
typedef enum
{
  SD_CONSUMED_EVENTGROUP_RELEASED             = 0U,
  SD_CONSUMED_EVENTGROUP_REQUESTED            = 1U
} Sd_ConsumedEventGroupSetStateType;

/* This type defines the modes to indicate the current mode request of a Client Service. */
typedef enum
{
  SD_CLIENT_SERVICE_DOWN                      = 0U,
  SD_CLIENT_SERVICE_AVAILABLE                 = 1U
} Sd_ClientServiceCurrentStateType;

/* This type defines the subscription policy by consumed EventGroup for the Client Service. */
typedef enum
{
  SD_CONSUMED_EVENTGROUP_DOWN                 = 0U,
  SD_CONSUMED_EVENTGROUP_AVAILABLE            = 1U
} Sd_ConsumedEventGroupCurrentStateType;

/* This type defines the subscription policy by EventHandler for the Server Service. */
typedef enum
{
  SD_EVENT_HANDLER_RELEASED                   = 0U,
  SD_EVENT_HANDLER_REQUESTED                  = 1U
} Sd_EventHandlerCurrentStateType;

/* This structure defines the SD header */
typedef struct
{
  uint16                                      ClientID;
  uint16                                      SessionID;
  uint8                                       ProtocolVersion;
  uint8                                       InterfaceVersion;
  uint8                                       MessageType;
  uint8                                       ReturnCode;
  uint8                                       Flags;
  uint8                                       Reserved[3];
} Sd_HeaderType;

typedef struct
{
  uint32                                      Seconds;
  uint16                                      Milliseconds;
} Sd_ExtendedTimeType;

/*
 *  CLIENT
 */

typedef struct
{
  Sd_ExtendedTimeType                         TimeToTriggerSend;
  Sd_ExtendedTimeType                         TimerTTL;
  uint8                                       RepetitionRun;
} Sd_DynamicClientTimerType;

typedef struct
{
  uint32                                      AcknowledgedTTL;
  Sd_ConsumedEventGroupCurrentStateType       CurrentState;
  Sd_ConsumedEventGroupSetStateType           ServiceModeRequest;
  Sd_ClientEventgroupEventType                Event;
  Sd_ConsumedEventGroupStateMachineType       StateMachine;
  Sd_ExtendedTimeType                         TimerTTL;
  SoAd_SoConIdType                            MulticastSoConId;
  SoAd_SoConIdType                            UdpSoConId;
  SoAd_SoConIdType                            TcpSoConId;
} Sd_DynamicConsumedEventGroupType;

typedef struct
{
  P2VAR(Sd_SockAddrContainerType, TYPEDEF, SD_APPL_VAR)   ServerAddrPtr;
  Sd_ClientServiceCurrentStateType                        CurrentState;
  Sd_ClientServiceSetStateType                            StateSWC;
  Sd_ClientStateMachineType                               StateMachine;
  Sd_ClientServiceEventType                               Event;
  Sd_SockAddrContainerType                                ServerTcpEndpointAddr;
  Sd_SockAddrContainerType                                ServerUdpEndpointAddr;
  Sd_SockAddrContainerType                                ServerMulticastEndpointAddr;
  uint32                                                  OfferedTTL;
  SoAd_SoConIdType                                        MethodTcpSoConId;
  SoAd_SoConIdType                                        MethodUdpSoConId;
} Sd_DynamicClientServiceType;

/*
 *  SERVER
 */

typedef struct
{
  SoAd_SoConIdType                            SoConId;
  uint8                                       NrOfActivations;
} Sd_SoConActivationMapType;

typedef struct
{
  Sd_ExtendedTimeType                         TimeToTriggerSend;
  uint8                                       InitialOfferRepetitionRun;
} Sd_DynamicServerTimerType;

typedef struct
{
  Sd_EventHandlerCurrentStateType             RequestStateEG;
  Sd_EventHandlerStateMachineType             StateMachine;
  uint16                                      NrOfClients;
  uint16                                      NrOfClientsUdp;
} Sd_DynamicEventHandlerType;

typedef enum
{
  SD_ENDPOINT_TYPE_INVALID                    = 0x00,
  SD_ENDPOINT_TYPE_TCP                        = 0x06,
  SD_ENDPOINT_TYPE_UDP                        = 0x11
} Sd_EndpointType;

typedef struct
{
  Sd_SockAddrContainerType                    Addr;
  Sd_EndpointType                             Type;
  uint8                                       NrOfReferences;
} Sd_EndpointStorageType;

typedef struct
{
  P2VAR(Sd_EndpointStorageType, TYPEDEF, SD_APPL_VAR)     UdpEndpointPtr;
  P2VAR(Sd_EndpointStorageType, TYPEDEF, SD_APPL_VAR)     TcpEndpointPtr;
  P2VAR(Sd_SockAddrContainerType, TYPEDEF, SD_APPL_VAR)   AddrPtr;
  Sd_EventHandlerClientStateType                          ClientState;
  uint32                                                  RequestedTTL;
  Sd_ExtendedTimeType                                     SubscribedUntil;
  uint16                                                  RxReserved;
  SoAd_SoConIdType                                        AssignedUdpSoConId;
  SoAd_SoConIdType                                        AssignedTcpSoConId;
  uint8                                                   NrOfReferences;
} Sd_ClientListType;

typedef struct
{
  boolean                                     Full;
  uint8                                       StartIdx;
  uint8                                       EndIdx;
} Sd_TriggerTransmitListType;

typedef struct
{
  Sd_ServerServiceSetStateType                StateSWC;
  Sd_ServerStateMachineType                   StateMachine;
} Sd_DynamicServerServiceType;

/*
 *  COMBINED CLIENT & SERVER
 */

/* State of the service instance. The suffix indicates if the state has changed during the last main function */
typedef enum
{
  SD_INSTANCE_DOWN                            = SOAD_IPADDR_STATE_UNASSIGNED,
  SD_INSTANCE_UP_AND_CONFIGURED               = SOAD_IPADDR_STATE_ASSIGNED
} Sd_ServiceInstanceStateType;

typedef struct
{
  Sd_SockAddrContainerType                    Addr;
  uint16                                      SessionIdCounter;
  uint16                                      RxUnicastSessionId;
  uint16                                      RxMulticastSessionId;
  uint8                                       Flags;
  uint8                                       RxUnicastFlags;
  uint8                                       RxMulticastFlags;
} Sd_AddressStorageType;

typedef struct
{
  Sd_SoConModeType                            SoConMode;
  SoAd_SoConIdType                            SoConId;
} Sd_SoConModeMapType;

typedef struct
{
  Sd_SockAddrContainerType                    SdUnicastAddr;
  Sd_ExtendedTimeType                         NextStateMachineRun;
  Sd_ServiceInstanceStateType                 State;
  Sd_InitialRunType                           InitialRun;
} Sd_DynamicInstanceType;


/**********************************************************************************************************************
 *  GLOBAL CAPABILITY RECORD MACROS AND TYPES
 *********************************************************************************************************************/
typedef P2CONST(uint8, SD_APPL_DATA, AUTOMATIC) Sd_ConfigOptionStringType;

typedef P2FUNC(boolean, SD_CODE, Sd_CapabilityRecordCalloutFunctionApiType)  ( \
          PduIdType pduID, \
          uint8 type, \
          uint16 serviceID, \
          uint16 instanceID, \
          uint8 majorVersion, \
          uint32 minorVersion, \
          CONSTP2CONST(Sd_ConfigOptionStringType, AUTOMATIC, SD_APPL_DATA) receivedConfigOptionPtrArray, \
          CONSTP2CONST(Sd_ConfigOptionStringType, AUTOMATIC, SD_APPL_DATA) configuredConfigOptionPtrArray);


#endif /* SD_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Sd_Types.h
 *********************************************************************************************************************/
