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
 *        \file  TcpIp_IpV4.c
 *        \brief  Implementation of Internet Protocol version 4 (IPv4)
 *
 *        \details  This file is part of the TcpIp IPv4 submodule.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the TcpIp IPv4 submodule. >> TcpIp_IpV4.h
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

#define TCPIP_IPV4_SOURCE

#include "TcpIp_Cfg.h"
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_IpV4.h"
#include "TcpIp_IpV4_Cbk.h"
#include "TcpIp_IpV4_Priv.h"
#include "TcpIp_IpV4_Lcfg.h"
#if (IPV4_SUPPORT_ICMP == STD_ON)
# include "TcpIp_IcmpV4.h"
# include "TcpIp_IcmpV4_Cbk.h"
#endif
#include "TcpIp_Arp.h"
#include "TcpIp_Priv.h"

#include "IpBase.h"

#include "TcpIp_Cbk.h"  /* for IP link status change */

#if (IPV4_IP_DHCP_ADDR_CFG_SUPP == STD_ON)
# include "TcpIp_DhcpV4.h"
# include "TcpIp_DhcpV4_Cbk.h"
#endif

#if (IPV4_SUPPORT_TCP == STD_ON)
# include "TcpIp_Tcp_Cbk.h"
#endif /* IPV4_SUPPORT_TCP */

#include "TcpIp_Udp_Cbk.h"
#include "TcpIp_Lcfg.h"

#include "EthIf.h"

#if (IPV4_SUPPORT_ETHSM == STD_ON)
# include "EthSM.h"
#endif

#if (IPV4_IP_ENABLE_ADDR_NVM_STORAGE == STD_ON)
# include "NvM.h"
#endif

#if defined(TCPIP_INV_DEM_EVENT_ID)
# include "Dem.h"
#endif

#if !defined (STATIC)
# define STATIC static
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of TcpIp_IpV4.h file */
#if (  (IPV4_SW_MAJOR_VERSION != 5u) \
    || (IPV4_SW_MINOR_VERSION != 0u) \
    || (IPV4_SW_PATCH_VERSION != 1u) )
  #error "TcpIp_IpV4.c: Source and Header file are inconsistent!"
#endif

/*
Design:
- The function Ip_AddrConflictInd only indicates address conflicts for usage with IP-LL config.
  Since DHCP won't probe its addresses (design decision) no further differentiation is necessary.
*/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define IPV4_IP_TXPROGR_FREE       0
#define IPV4_IP_TXPROGR_REQU       1
#define IPV4_IP_TXPROGR_PART_SENT  2

#define IPV4_IP_TB_STATUS_READY    0
#define IPV4_IP_TB_STATUS_NOT_OK   1

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
/* PRQA S 3453 FunctionLikeMacros */ /* MD_MSR_19.7 */

/* PRQA L:FunctionLikeMacros */ /* MD_MSR_19.7 */
/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
#define IPV4_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

#define IPV4_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/* -------------------------------------------------------------------------- */

#define IPV4_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

#if (IPV4_IP_ENABLE_REASSEMBLY == STD_ON)
STATIC VAR(uint32, IPV4_VAR_NOINIT) IpV4_Ip_TimeMs;
#endif

#define IPV4_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/* -------------------------------------------------------------------------- */

#define IPV4_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

STATIC VAR(uint16, IPV4_VAR_NOINIT) IpV4_Ip_Identification;

#define IPV4_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/* -------------------------------------------------------------------------- */

#define IPV4_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

#if IPV4_DEV_ERROR_DETECT == STD_ON
VAR(IpV4_StateType, IPV4_VAR_ZERO_INIT) IpV4_State = IPV4_STATE_UNINIT;
#endif

#define IPV4_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define IPV4_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/***********************************************************************************************************************
 *  IpV4_Ip_Init
 **********************************************************************************************************************/
/*! \brief        Init the IP submodule.
 *  \description  <br>This API call stores the start address of the post build time configuration  of the IP module
 *                and may be used to initialize the data structures.
 *  \param[in]    Ip_ConfigType  *CfgPtr: pointer to post-build configuration
 *  \return       void
 *  \note
 *  \context      system startup
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_Init(
    P2CONST(IpV4_Ip_ConfigType, IPV4_CONST, IPV4_CONST) CfgPtr );

/***********************************************************************************************************************
 *  IpV4_Ip_MainFunction
 **********************************************************************************************************************/
/*! \brief      This function handles the IP global status
 *  \context    task level
 *  \note       This function is called every IPV4_MAIN_FCT_PERIOD_MSEC ms
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_MainFunction(void);

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)

/***********************************************************************************************************************
 *  IpV4_Ip_VLl_GenerateIpAddr
 **********************************************************************************************************************/
/*! \brief      Generates a random link-local IP address according to IETF RFC3927.
 *  \param[in]  IpCtrlIdx     Index of the IP controller
 *  \param[in]  conflictCount Number of link-local address configuration conflicts that occured on this controller 
 *                            since last restart of the address assignment method.
 *  \return     Generated IP address is in range 169.254.1.0 to 169.254.254.255 (inclusive).
 *  \context    TASK
 *  \reentrant  FALSE
 **********************************************************************************************************************/
STATIC FUNC(IpBase_AddrInType, TCPIP_CODE) IpV4_Ip_VLl_GenerateIpAddr(uint8 IpCtrlIdx, uint8 conflictCount);

STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VLl_Reset(uint8 IpCtrlIdx);
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VLl_Start(uint8 IpCtrlIdx);
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VLl_Main(uint8 IpCtrlIdx);
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VLl_FindAddr(uint8 IpCtrlIdx);
#endif /* IPV4_IP_DYN_LL_ADDR_CFG_SUPP */

/***********************************************************************************************************************
 *  IpV4_Ip_VForwardPacketToUpperLayer()
 **********************************************************************************************************************/
/*! \brief       Forwards IP packet payload to the corresponding upper layer (TCP, UDP, ICMP) for the protocol.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VForwardPacketToUpperLayer(
  uint8             IpCtrlIdx,
  IpV4_AddrIdType   IpAddrId,
  IpBase_AddrInType IpSrcAddr,
  IpBase_AddrInType IpDstAddr,
  uint8             IpProtocol,
  IPV4_P2V(uint8)   IpPayloadPtr,
  uint16            IpPayloadLen);

#if (IPV4_IP_ENABLE_REASSEMBLY == STD_ON)
/************************************************************************************************************
 *  IpV4_Ip_VInitReassemblyBuffers()
 ***********************************************************************************************************/
/*! \brief       Initializes reassembly buffers and descriptors.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
***********************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VInitReassemblyBuffers(void);

/************************************************************************************************************
 *  IpV4_Ip_VGetReassemblyBufferDesc()
 ***********************************************************************************************************/
/*! \brief       Locates a new or existing reassembly buffer descriptor.
 *  \details     Locates a new or existing reassembly buffer descriptor according to SrcIpAddr, DstIpAddr,
 *               Protocol and Identification values
 *  \param[in]   IpCtrlIdx      IP controller index
 *  \param[in]   IpSrcAddr      IP source address of fragment
 *  \param[in]   IpDstAddr      IP destination address of fragment
 *  \param[in]   IpProtocol     IP upper layer protocol value of fragment
 *  \param[in]   Identification IP identification value of fragment
 *  \return      Index of current or newly initialized reassembly buffer
 *  \context     IpV4_Ip_VReceiveFragment
 *  \reentrant   FALSE
 *  \synchronous TRUE
***********************************************************************************************************/
STATIC FUNC(uint8, IPV4_CODE) IpV4_Ip_VGetReassemblyBufferDesc(
  uint8                     IpCtrlIdx,
  IpBase_AddrInType         IpSrcAddr,
  IpBase_AddrInType         IpDstAddr,
  uint8                     IpProtocol,
  uint16                    Identification);

/************************************************************************************************************
 *  IpV4_Ip_VReceiveFragment()
 ***********************************************************************************************************/
/*! \brief       Processes a received IP fragment.
 *  \details     Copies fragment payload into corresponding reassembly buffer and checks is reassembly is complete.
 *  \param[in]        IpCtrlIdx           IP controller index.
 *  \param[in]        IpHdrPtr            Pointer to IP header of received fragment.
 *  \param[in,out]    FragPayloadPtrPtr   In:  Pointer to payload of received fragment.
 *                                        Out: Pointer to reassembled IP packet.
 *  \param[in,out]    FragPayloadLenPtr   In:  Pointer to length of fragment in bytes
 *                                        Out: Length of reassembled packet in bytes.
 *  \return           TRUE                All fragments received and reassembly is complete.
 *  \return           FALSE               Fragment was stored or ignored.
 *  \pre         IP packet has been checked for validity and is acceptable
 *  \context     TASK|ISR1
 *  \reentrant   FALSE
 *  \synchronous TRUE
***********************************************************************************************************/
STATIC FUNC(boolean, IPV4_CODE) IpV4_Ip_VReceiveFragment(
  uint8                     IpCtrlIdx,
  IPV4_P2C(IpV4_Ip_HdrType) IpHdrPtr,
  IPV4_P2V(uint8*)          FragPayloadPtrPtr,
  IPV4_P2V(uint16)          FragPayloadLenPtr);
#endif

#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
# if (IPV4_ENABLE_ETHIF_ADDR_FILTER_API == STD_ON)
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VJoinMulticastGroup(uint8 IpCtrlIdx, IpBase_AddrInType MulticastAddr, boolean Join);
# endif
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VUpdateMulticastMemberships(uint8 IpCtrlIdx, boolean Join);
#endif

/* PRQA S 3453 5 */ /* MD_MSR_19.7 */
#if (IPV4_SUPPORT_ETHSM == STD_ON)
# define ETHSM_TCPIP_MODE_INDICATION(CtrlIdx, IsIpAddrAssigned) (void)EthSM_VTcpIpModeIndication((CtrlIdx), (IsIpAddrAssigned))
#else
# define ETHSM_TCPIP_MODE_INDICATION(CtrlIdx, IsIpAddrAssigned)
#endif

/***********************************************************************************************************************
 *  IpV4_Ip_VGetBestAvailableAddrAssignment()
 **********************************************************************************************************************/
/*! \brief      Find available IP address assignment method that has highest priority (STATIC, DHCP, LINKLOCAL).
 *  \param[in]  IpCtrlIdx                 Index of the IP controller.
 *  \param[out] addrAssignmentPriorityPtr Priority of the returned assignment method (Range 1..3 based on configuration).
 *  \param[out] addrInfoPtr               IP address information (IP address, Netmask, Default Router) tuple.
 *  \return     IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE      No IP address assignment ready.
 *  \return     IPV4_IP_ADDR_ASSIGNMENT_METHOD_DHCP
 *  \return     IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL
 *  \return     IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC
 *  \context    TASK
 *  \reentrant  TRUE for different controllers.
 **********************************************************************************************************************/
STATIC FUNC(uint8, IPV4_CODE) IpV4_Ip_VGetBestAvailableAddrAssignment(
  uint8                         IpCtrlIdx, 
  IPV4_P2V(uint8)               addrAssignmentPriorityPtr,
  IPV4_P2V(IpV4_IpAddrSetType)  addrInfoPtr);

/***********************************************************************************************************************
 *  IpV4_Ip_VGetActiveAddressOfAssignmentMethod()
 **********************************************************************************************************************/
/*! \brief      Checks whether an address assignment method is ready and returns the address parameters.
 *  \param[in]  IpCtrlIdx             Index of the IP controller.
 *  \param[in]  addrAssignmentMethod  Address assignment method (DHCP, LINKLOCAL, STATIC).
 *  \param[out] addrInfoPtr           IP address information (IP address, Netmask, Default Router) tuple.
 *  \return     TRUE                  Address assignment method is ready.
 *  \return     FALSE                 Address assignment method is not ready. (No address available)
 *  \context    TASK
 *  \reentrant  TRUE for different controllers.
 **********************************************************************************************************************/
STATIC FUNC(boolean, IPV4_CODE) IpV4_Ip_VGetActiveAddressOfAssignmentMethod(
  uint8                        IpCtrlIdx, 
  uint8                        addrAssignmentMethod,
  IPV4_P2V(IpV4_IpAddrSetType) addrInfoPtr);

/***********************************************************************************************************************
 *  IpV4_Ip_VTriggerAddrAssignment()
 **********************************************************************************************************************/
/*! \brief Set/Unset address assignment trigger flag and start/stop dynamic (DHCP, LINKLOCAL) assignment if necessary.
 *  \param[in]  IpCtrlIdx                 Index of the IP controller.
 *  \param[in]  addrAssignmentCfg         IP address assignment configuration set.
 *  \param[in]  triggerValue              Specifies whether the flag shall be set (TRUE) or unset (FALSE).
 *  \return     E_OK     Flag was changed.
 *  \return     E_NOT_OK Flag was already set/unset.
 *  \context    TASK
 *  \reentrant  TRUE for different controllers.
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) IpV4_Ip_VTriggerAddrAssignment(
    uint8   IpCtrlIdx,
    uint8   addrAssignmentCfg,
    boolean triggerValue);

/***********************************************************************************************************************
 *  IpV4_Ip_VTriggerAutomaticAddrAssignments()
 **********************************************************************************************************************/
/*! \brief      Sets trigger flags for all configured unicast address assignments with trigger AUTOMATIC.
 *  \param[in]  IpCtrlIdx  Index of IP controller.
 *  \context    TASK
 *  \reentrant  TRUE for different controllers.
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VTriggerAutomaticAddrAssignments(uint8 IpCtrlIdx);

/***********************************************************************************************************************
 *  IpV4_Ip_VSetCtrlStateOffline()
 **********************************************************************************************************************/
/*! \brief Sets IP controller into state OFFLINE and perform required operations based on current state.
 *  \details    In state OFFLINE the IP controller does not send any messages.
 *              This state is entered based on the current state of the ethernet transceiver.
 *  \param[in]  IpCtrlIdx  Index of IP controller.
 *  \context    TASK
 *  \reentrant  TRUE for different controllers.
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VSetCtrlStateOffline(uint8 IpCtrlIdx);

/***********************************************************************************************************************
 *  IpV4_Ip_VSetCtrlStateOnlinePassive()
 **********************************************************************************************************************/
/*! \brief Sets IP controller into state ONLINE_PASSIVE and perform required operations based on current state.
 *  \details    In state ONLINE_PASSIVE the IP controller is online but has not completed unicast address assignment.
 *  \param[in]  IpCtrlIdx  Index of IP controller.
 *  \context    TASK
 *  \reentrant  TRUE for different controllers.
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VSetCtrlStateOnlinePassive(uint8 IpCtrlIdx);

/***********************************************************************************************************************
 *  IpV4_Ip_VSetCtrlStateOnlineActive()
 **********************************************************************************************************************/
/*! \brief      Sets IP controller into state ONLINE_ACTIVE and perform required operations based on current state.
 *  \details    In state ONLINE_ACTIVE the IP controller is online and has completed unicast address assignment.
 *  \param[in]  IpCtrlIdx  Index of IP controller.
 *  \context    TASK
 *  \reentrant  TRUE for different controllers.
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VSetCtrlStateOnlineActive(uint8 IpCtrlIdx);

/***********************************************************************************************************************
 *  IpV4_VLocalIpAddrAssignmentChange()
 **********************************************************************************************************************/
/*! \brief      Notifies upper layers about an IP address assignment change of a unicast or multicast address.
 *  \param[in]  IpCtrlIdx    Index of IP controller.
 *  \param[in]  ctrlAddrIdx  Index of the IP address of the controller.
 *  \context    TASK
 *  \reentrant  TRUE for different controllers.
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_VLocalIpAddrAssignmentChange(
    uint8                 IpCtrlIdx,
    uint8                 CtrlAddrIdx,
    TcpIp_IpAddrStateType State);

#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Ip_VChangeMulticastAddrAssignment
 **********************************************************************************************************************/
/*! \brief      Changes value of a multicast address.
 *  \param[in]  IpCtrlIdx       Index of the IP controller.
 *  \param[in]  mcAddrIdx       Index of the multicast address.
 *  \param[in]  addrValue       Value that shall be assigned to the specified multicast address index.
 *  \return     E_OK            Address was changed.
 *  \return     E_NOT_OK        Address could not be changed.
 *  \context    TASK
 *  \reentrant  TRUE for different controllers.
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) IpV4_Ip_VChangeMulticastAddrAssignment(
    uint8             IpCtrlIdx,
    uint8             mcAddrIdx,
    IpBase_AddrInType addrValue);
#endif

#if defined TCPIP_INV_DEM_EVENT_ID
/***********************************************************************************************************************
 *  IpV4_ResetDemEventAllIpCtrl
 **********************************************************************************************************************/
/*! \brief      Sets the status of a DEM event to 'passed' for all IpCtrlIdx that the event is configured for.
 *  \param[in]  CONSTP2CONST(PduIdType, IPV4_CONST) DemEventSnvsByIpV4Ctrl: Array of the SNVs of the DEM event.
 *  \param[in]  uint8 NumIpV4CtrlsOfDemEvent: Max. number of ip controllers that have the DEM event configured.
 *  \context    TASK
 *  \reentrant  FALSE
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_ResetDemEventAllIpCtrl(
  CONSTP2CONST(PduIdType, AUTOMATIC, IPV4_CONST) DemEventSnvsByIpV4Ctrl,
  uint8 NumIpV4CtrlsOfDemEvent
);

/***********************************************************************************************************************
 *  IpV4_ResetDemEventIpCtrl
 **********************************************************************************************************************/
/*! \brief      Sets the status of a DEM event to 'passed' for given IpCtrlIdx that the event is configured for.
 *  \param[in]  CONSTP2CONST(PduIdType, IPV4_CONST) DemEventSnvsByIpV4Ctrl: Array of the SNVs of the DEM event.
 *  \param[in]  uint8 NumIpV4CtrlsOfDemEvent: Max. number of ip controllers that have the DEM event configured.
 *  \param[in]  uint8 IpCtrlIdx: Ip controller that the DEM event shall be reset for.
 *  \context    TASK
 *  \reentrant  FALSE
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_ResetDemEventIpCtrl(
  CONSTP2CONST(PduIdType, AUTOMATIC, IPV4_CONST) DemEventSnvsByIpV4Ctrl,
  uint8 NumIpV4CtrlsOfDemEvent,
  uint8 IpCtrlIdx
);

#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  IpV4_InitMemory
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_InitMemory(void)
{
#if (IPV4_DEV_ERROR_DETECT == STD_ON)
  IpV4_State = IPV4_STATE_UNINIT;
#endif
  /* IPV4_DEV_ERROR_DETECT == STD_ON */
}

/***********************************************************************************************************************
 *  IpV4_Init
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Init(
    P2CONST(IpV4_ConfigType, IPV4_CONST, IPV4_CONST) CfgPtr )
{
  IPV4_UNUSED_PARAMETER(CfgPtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  /* #10 Initialize sub components (ARP, ICMP and IP). */
  IpV4_Arp_Init( NULL_PTR );
# if (IPV4_SUPPORT_ICMP == STD_ON)
  IpV4_Icmp_Init( NULL_PTR );
# endif
  /* IPV4_SUPPORT_ICMP == STD_ON */
  IpV4_Ip_Init( NULL_PTR );

#if (IPV4_DEV_ERROR_DETECT == STD_ON)
  IpV4_State = IPV4_STATE_INIT;
#endif

#if (IPV4_IP_ENABLE_REASSEMBLY == STD_ON)
  IpV4_Ip_TimeMs = 0;
#endif

#if defined TCPIP_INV_DEM_EVENT_ID
# if (TcpIp_NumIpV4CtrlsOfDemEventTCPIP_E_DUPLICATE_DHCP_ADDR > 0)
  IpV4_ResetDemEventAllIpCtrl(TcpIp_DemEventTCPIP_E_DUPLICATE_DHCP_ADDRSnvsByIpV4Ctrl, TcpIp_NumIpV4CtrlsOfDemEventTCPIP_E_DUPLICATE_DHCP_ADDR);
  /* Initialize array of last duplicated DHCP DID data */
  {
    uint8 IpCtrlIdx;  /* PRQA S 0781 */ /* MD_IpV4_5.6 */
    uint8 initPhysAddr[IPBASE_ETH_PHYS_ADDR_LEN_BYTE] = {0,0,0,0,0,0};
    for(IpCtrlIdx = 0; IpCtrlIdx < TcpIp_NumIpV4CtrlsOfDemEventTCPIP_E_DUPLICATE_DHCP_ADDR; IpCtrlIdx++)
    {
      IpV4_VAssignPhysAddr(TcpIp_LastDuplicateDhcpNetAddr[IpCtrlIdx].PhysAddr, initPhysAddr);
      TcpIp_LastDuplicateDhcpNetAddr[IpCtrlIdx].NetAddr = 0u;
    }
  }
# endif
#endif
} /* IpV4_Init */

/***********************************************************************************************************************
 *  IpV4_MainFunction
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, IPV4_CODE) IpV4_MainFunction(void)
{
  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT, IPV4_API_ID_MAIN_FUNCTION, IPV4_E_NOT_INITIALIZED )
  /* ------------------------------------------------- */

#if (IPV4_IP_ENABLE_REASSEMBLY == STD_ON)
  /* #10 Update time variable used for timeout handling. */
  IpV4_Ip_TimeMs += IPV4_MAIN_FCT_PERIOD_MSEC;
#endif

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
  /* #20 Call ARP MainFunction. */
  /* ARP MainFunction is only necessary if ECU needs to perform active address resolution */
  IpV4_Arp_MainFunction();
#endif

  /* #30 Call IP MainFunction. */
  IpV4_Ip_MainFunction();

#if (IPV4_SUPPORT_ICMP == STD_ON)
  /* #40 Call ICMP MainFunction. */
  IpV4_Icmp_MainFunction();
#endif

#if (IPV4_IP_DHCP_ADDR_CFG_SUPP == STD_ON)
  /* #50 Call DHCP MainFunction. */
  TcpIp_DhcpV4_MainFunction();
#endif
  /* TCPIP_SUPPORT_DHCPV4 == STD_ON */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief        Get IpV4 software version.
 *  \description  Returns version information, vendor ID and AUTOSAR module ID of the component.
 *                The versions are BCD-coded.
 *  \param[in]    VersionInfoPtr        pointer for version information
 *  \return       void
 *  \note
 *  \context      task level
 **********************************************************************************************************************/
#if ( (defined IPV4_VERSION_INFO_API) && (IPV4_VERSION_INFO_API == STD_ON) )
FUNC(void, IPV4_CODE) IpV4_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, IPV4_APPL_DATA) VersionInfoPtr )
{
  /* ------------------------------------------------- */
  /* DET: */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_VALID_PTR(VersionInfoPtr), IPV4_API_ID_GET_VERSION_INFO, IPV4_E_INV_POINTER )
  /* ------------------------------------------------- */

  VersionInfoPtr->vendorID         = IPV4_VENDOR_ID;
  VersionInfoPtr->moduleID         = IPV4_MODULE_ID;
  VersionInfoPtr->sw_major_version = IPV4_SW_MAJOR_VERSION;
  VersionInfoPtr->sw_minor_version = IPV4_SW_MINOR_VERSION;
  VersionInfoPtr->sw_patch_version = IPV4_SW_PATCH_VERSION;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif
  /* IPV4_VERSION_INFO_API */

/***********************************************************************************************************************
 *  IpV4_Ip_Init
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_Init(
    P2CONST(IpV4_Ip_ConfigType, IPV4_CONST, IPV4_CONST) CfgPtr )
{
#if(IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif

  TcpIp_SockIdxType TcpIpSockIdx;   /* IpV4_Ip_TransferBlock / socket index */

  IPV4_UNUSED_PARAMETER(CfgPtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  IpV4_Ip_Identification = 0;

  /* #10 Iterate over all IP controller instances. */
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  for (IpCtrlIdx = 0; IpCtrlIdx < IpV4_VCfgGetMaxNumCtrls(); IpCtrlIdx++) /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif
  {
    /* #20 Set IP controller instance to state OFFLINE. */
    IPV4_CTRL_VAR(IpV4_Ip_CtrlState)                    = IPV4_IP_OFFLINE;
    IPV4_CTRL_VAR(IpV4_Ip_PhysLinkActive)               = FALSE;
    IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentReadyChanged)   = FALSE;
    IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod)   = IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE;
    IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentTriggeredFlags) = 0;
#if (IPV4_IP_ENABLE_ADDR_NVM_STORAGE == STD_ON)
    IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentMethodPersist)  = IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE;
#endif

    /* #30 Reset Mulicast address assignment. */
#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
    {
      uint8_least mcAddrIdx;
      for (mcAddrIdx = 0; mcAddrIdx < IpV4_Ip_VCfgGetMulticastAddrCount(); mcAddrIdx++)
      {
        IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[mcAddrIdx] = IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs_Default)[mcAddrIdx];
      }
    }
#endif

    /* #40 Reset LinkLocal address assignment. */
#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
    if (IpV4_Ip_VCfgIsAddrAssignmentEnabled(IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL))
    {
      IpV4_Ip_VLl_Reset(IPV4_IPCTRLIDX);
    }
#endif
  } /* for each controller */

  /* #50 Reset socket specific information. */

  TcpIpSockIdx = IPV4_IP_MAX_NUM_SOCKETS;

  /* for each socket */
  while (0 < TcpIpSockIdx)
  {
    TcpIpSockIdx--;
    IpV4_Ip_ResetSocket(TcpIpSockIdx);
  }

  /* #60 Initialize packet reassembly buffers. */

#if (IPV4_IP_ENABLE_REASSEMBLY == STD_ON)
  IpV4_Ip_VInitReassemblyBuffers();
#endif
}

/***********************************************************************************************************************
 *  IpV4_Ip_MainFunction
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_MainFunction(void)
{
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT, IPV4_IP_API_ID_MAIN_FUNCTION, IPV4_E_NOT_INITIALIZED )
  /* ------------------------------------------------- */

  /* #10 Iterate over all IP controller instances. */
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  for (IpCtrlIdx = 0; IpCtrlIdx < IpV4_VCfgGetMaxNumCtrls(); IpCtrlIdx++)
#endif
  {
#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
    /* #20 Call link local address assignment MainFunction if configured. */
    if (IpV4_Ip_VCfgIsAddrAssignmentEnabled(IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL))
    {
      IpV4_Ip_VLl_Main(IPV4_IPCTRLIDX);
    }
#endif

    /* #30 Perform IP instance state and address assignment handling. */
    if (IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_OFFLINE)
    {
      if (IPV4_CTRL_VAR(IpV4_Ip_PhysLinkActive) == TRUE)
      {
        /* IP instance is OFFLINE and physical link has become active. */
        IpV4_Ip_VSetCtrlStateOnlinePassive(IPV4_IPCTRLIDX);
      }
    }
    else
    {
      if (IPV4_CTRL_VAR(IpV4_Ip_PhysLinkActive) == TRUE)
      {
#if (IPV4_IP_ENABLE_ADDR_NVM_STORAGE == STD_ON)
        /* #40 Store IP address into NvM if triggered. */
        if (IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentMethodPersist) != IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE)
        {
          uint8 NvMStatus = NVM_REQ_PENDING;
          
          IPV4_ASSERT(IpV4_Ip_VCfgGetNvmAddrVar() != NULL_PTR);

          (void)NvM_GetErrorStatus(TCPIP_NVM_BLOCK_ID, &NvMStatus);

          if(NVM_REQ_PENDING != NvMStatus)
          {
            if (IpV4_Ip_VGetActiveAddressOfAssignmentMethod(IpCtrlIdx, IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentMethodPersist), IpV4_Ip_VCfgGetNvmAddrVar()) == TRUE)
            {
              /* set block Status to true */
              (void)NvM_SetRamBlockStatus(TCPIP_NVM_BLOCK_ID, TRUE);
              IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentMethodPersist) = IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE;
            }

          }
        }
        else
#endif
        {
          uint8              bestAvailableAddrAssignmentMethod;
          uint8              bestAvailableAddrAssignmentPriority;
          IpV4_IpAddrSetType bestAvailableAddr;

          bestAvailableAddrAssignmentMethod = IpV4_Ip_VGetBestAvailableAddrAssignment(IPV4_IPCTRLIDX, &bestAvailableAddrAssignmentPriority, &bestAvailableAddr);

          if (IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) == IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE)
          {
            if (bestAvailableAddrAssignmentMethod == IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE)
            {
              /* Still no IP address of any configured assignment method available. */
            }
            else
            {
              /* IP address ready. */
              IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr)                 = bestAvailableAddr;
              IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) = bestAvailableAddrAssignmentMethod;

              IpV4_Ip_VSetCtrlStateOnlineActive(IPV4_IPCTRLIDX);
            }
          }
          else
          {
            if (bestAvailableAddrAssignmentMethod != IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE)
            {
              /* IP address available still available. */
              if (IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr != bestAvailableAddr.NetAddr)
              {
                /* IP address value has changed. Inform upper-layer. */
                IpV4_VLocalIpAddrAssignmentChange(IPV4_IPCTRLIDX, IPV4_CTRL_ADDR_IDX_FIRST, TCPIP_IPADDR_STATE_UNASSIGNED);

                IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr)                 = bestAvailableAddr;
                IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) = bestAvailableAddrAssignmentMethod;

                IpV4_VLocalIpAddrAssignmentChange(IPV4_IPCTRLIDX, IPV4_CTRL_ADDR_IDX_FIRST, TCPIP_IPADDR_STATE_ASSIGNED);
              }
              else if (IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) != bestAvailableAddrAssignmentMethod)
              {
                /* IP address assignment method has changed but IP address is the same. No need to inform upper-layer. */
                IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) = bestAvailableAddrAssignmentMethod;
              }
              else
              {
                /* IP address and assignment method did not change. */
              }
            }
            else
            {
              /* IP address lost. */
              IpV4_Ip_VSetCtrlStateOnlinePassive(IPV4_IPCTRLIDX);
            }
          }
        }
      }
      else
      {
        /* Physical link lost. */
        IpV4_Ip_VSetCtrlStateOffline(IPV4_IPCTRLIDX);
      }
    }
  } /* for each controller */
} /* PRQA S 2006, 6010, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  IpV4_Ip_RxIndication
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_RxIndication(
  uint8                                    CtrlIdx,
  Eth_FrameType                            FrameType,
  boolean                                  IsBroadcast,
  P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr, /* PRQA S 3673 */ /* MD_IPV4_16.7_3673 */
  P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) DataPtr,
  uint16                                   LenByte)
{
  IPV4_P2V(IpV4_Ip_HdrType) IpHeaderPtr = (IPV4_P2V(IpV4_Ip_HdrType))DataPtr; /* PRQA S 0310 */ /* MD_IpV4_11.04 */
  IPV4_P2V(uint8)           IpPayloadPtr; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
  uint8                     IpHdrLenByte;
  uint16                    IpTotalLenByte;
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx;           /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif

  IPV4_UNUSED_PARAMETER(FrameType);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  IPV4_UNUSED_PARAMETER(IsBroadcast);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

#if defined TCPIP_INV_DEM_EVENT_ID
# if (TcpIp_NumIpV4CtrlsOfDemEventTCPIP_E_DUPLICATE_DHCP_ADDR > 0)
  /* PhysAddrPtr is used in case DEM event is triggered */
# endif
#else
  IPV4_UNUSED_PARAMETER(PhysAddrPtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT, IPV4_IP_API_ID_RX_INDICATION, IPV4_E_NOT_INITIALIZED )
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_VALID_PTR(DataPtr), IPV4_IP_API_ID_RX_INDICATION, IPV4_E_INV_POINTER )

  /* ------------------------------------------------- */

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  if (!IPV4_CTRL_IDX_ETHIF_2_IP(CtrlIdx, IPV4_IPCTRLIDX))
#else
  if (CtrlIdx != IPV4_CTRL_IDX_IP_2_ETHIF(IPV4_IPCTRLIDX))
#endif
  {
    return;
  }

  /* #10 Check, that the IP controller is not offline and the given packet length is valid. */
  if(IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_OFFLINE)
  {
    /* IpV4 is shut down, so do not process any incoming message -> drop message */
    return;
  }

  if(IPV4_IP_DEF_HEADER_LENGTH_BYTE > LenByte)
  {
    /* invalid message length, message is smaller than minimum IP header length -> drop message */
    return;
  }

  /* #20 Extract the header and total packet length. */
  IpHdrLenByte = (uint8)((IpHeaderPtr->Ver_Ihl & 0x0FU) << 2);
  IpTotalLenByte = IPV4_NTOHS(IpHeaderPtr->TotLen);

  /* #30 Check IP header length, IP version number and consistency of length values of the IP packet. */
  /* check IP header length: */
  if(IpHdrLenByte >= IPV4_IP_DEF_HEADER_LENGTH_BYTE)
  {
    /* check IP version number: */
    if((IpHeaderPtr->Ver_Ihl & 0xF0u) == ((uint8)(IPV4_IP_HEADER_VERSION_V4)) <<4)
    {
      /* Check if indicated length equals length provided in IP header.
         -> if not, IP fragmentation is used (not supported) or wrong length is indicated */
      if(LenByte < IpTotalLenByte)
      {
        /* message seams to be fragmented -> drop message */
        return;
      }

      if (IpHdrLenByte > IpTotalLenByte)
      {
        /* total length (including IP header) is smaller than IP header length. -> drop message */
        return;
      }
      /* #40 Check the header checksum, if not already done in hardware. */
#if (IPV4_IP_CHECK_RX_CHECKSUM == STD_ON)
#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_OFF)  /* If the hardware supports ckecking the checksum, the check if the checksum is ok will be done later. */
      /* check header checksum */
      if(0 == IpBase_TcpIpChecksumAdd((IPV4_P2C(uint8))IpHeaderPtr, IpHdrLenByte, 0, TRUE)) /* PRQA S 0310 */ /* MD_IpV4_11.04 */
#endif /* TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED */
#endif /* IP_CHECK_RX_CHECKSUM */
      {
        IpV4_AddrIdType       AddrId;      /* PRQA S 0781 */ /* MD_IpV4_5.6 */

        /* #50 Discard the packet in case the source address is not broadcast or multicast. */
        /* check source address */
        if(TCPIP_INADDR_BROADCAST == IpHeaderPtr->SrcAddr)
        {
          /* According to RFC 791, section 3.3 ("The internet module must check to see that the
             source address is one of the legal address for this host."), and RFC 1122, section
             3.2.1.3, case c ("It MUST NOT be used as a source address."), the broadcast address
             may not be used as a source address. Therefore an incoming message with broadcast addr
             as the source addr must be discarded. */
          /* discard message immediately */
          return;
        }

        if ((IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_ONLINE_ACTIVE) &&
            (IpHeaderPtr->SrcAddr == (IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr | ~(IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetMask))))
        {
          /* This message uses the local broadcast address as source address */
          /* discard message immediately */
          return;
        }

        if(IPV4_ADDR_IS_MULTICAST(IpHeaderPtr->SrcAddr))
        {
          /* This message uses a multicast address as source address */
          /* discard message immediately */
          return;
        }

        /* #60 In case the IP controller is online and it is a DHCP IP address, check for a duplicate DHCP address. */
        if ((IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_ONLINE_ACTIVE) &&
            (IpHeaderPtr->SrcAddr == IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr))
        {
          /* This message uses the node's local IP address as source address */
#if defined TCPIP_INV_DEM_EVENT_ID
#  if (TcpIp_NumIpV4CtrlsOfDemEventTCPIP_E_DUPLICATE_DHCP_ADDR > 0)
          /* Issue the related DEM event in case it's a DHCP address */
          if(    ( IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) == IPV4_IP_ADDR_ASSIGNMENT_METHOD_DHCP )
              && ( TcpIp_DemEventTCPIP_E_DUPLICATE_DHCP_ADDRSnvsByIpV4Ctrl[IpCtrlIdx] != TCPIP_INV_DEM_EVENT_ID )
            )
          {
            IpV4_VAssignPhysAddr(TcpIp_LastDuplicateDhcpNetAddr[IpCtrlIdx].PhysAddr, PhysAddrPtr);
            TcpIp_LastDuplicateDhcpNetAddr[IpCtrlIdx].NetAddr = IpHeaderPtr->SrcAddr;
            Dem_ReportErrorStatus(TcpIp_DemEventTCPIP_E_DUPLICATE_DHCP_ADDRSnvsByIpV4Ctrl[IpCtrlIdx], DEM_EVENT_STATUS_PREFAILED);
          }
#  endif
#endif
          /* discard message immediately */
          return;
        }

        if((0 == IpHeaderPtr->SrcAddr) && (IpHeaderPtr->Prot == IPV4_IP_PROTOCOL_TCP))
        {
          /* This message uses the invalid address as source address */
          /* UDP messages with source address 0.0.0.0 are accepted since a DHCPv4 server
           * and link-local address configuration must be able to receive UDP packets sent from 0.0.0.0.
           */
          /* discard message immediately */
          return;
        }

        if(IPV4_ADDR_IN_SUBNET(IpHeaderPtr->SrcAddr,    IPV4_LOCALNET_PREFIX, IPV4_LOCALNET_PREFIX_MASK))
        {
          /* This message uses a localnet address as source address */
          /* discard message immediately */
          return;
        }

        /* check destination IP address of the message */
        /* if node:
             check if IP packet is intended for this node (unicast, multicast, broadcast)
             if unicast: check if IP addres matches node address (depenent on CtrlIdx)
           if router:
             not implemented */

        if (IpHeaderPtr->DestAddr == IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr) /* local IP-addr */
        {
          AddrId      = IPV4_CTRL_VAR(IpV4_Ip_AddrConfig)[IPV4_CTRL_ADDR_IDX_FIRST].IpAddrId;
        }
        else if (IPV4_ADDR_IS_BROADCAST(IpHeaderPtr->DestAddr)) /* local or directed broadcast */
        {
          AddrId      = IPV4_CTRL_VAR(IpV4_Ip_BcAddrId);
          IPV4_CTRL_VAR(IpV4_Ip_LastBcAddr) = IpHeaderPtr->DestAddr;
        }
#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
        else if (IPV4_ADDR_IS_MULTICAST(IpHeaderPtr->DestAddr)) /* multicast */
        {
          boolean McCtrlAddrIdxFound = FALSE;
          uint8   McCtrlAddrIdx      = IpV4_Ip_VCfgGetMulticastAddrCount();

          while (0 < McCtrlAddrIdx)
          {
            McCtrlAddrIdx--;

            if (IpHeaderPtr->DestAddr == IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[McCtrlAddrIdx])
            {
              McCtrlAddrIdxFound = TRUE;
              break;
            }
          }

          if (TRUE == McCtrlAddrIdxFound)
          {
            /* accept packet and map to specific multicast address id */
            AddrId      = IPV4_CTRL_VAR(IpV4_Ip_AddrConfig)[IPV4_CTRL_MULTICAST_ADDR_IDX_2_ADDR_IDX(McCtrlAddrIdx)].IpAddrId;
          }
          else if (IpV4_Ip_VCfgIsReceiveAllMulticastsEnabled())
          {
            /* accept packet and map to AutoSelectBroadcast address id */
            AddrId      = IPV4_CTRL_VAR(IpV4_Ip_BcAddrId);
            IPV4_CTRL_VAR(IpV4_Ip_LastBcAddr) = IpHeaderPtr->DestAddr;
          }
          else
          {
            /* drop packet */
            AddrId      = IPV4_ADDR_ID_INV;
          }
        }
#endif
        else
        {
          /* Destination of the packet is not this node.
           * Packet will be dropped.
           */
          AddrId      = IPV4_ADDR_ID_INV;
        }

        if(IPV4_ADDR_ID_INV != AddrId)
        {
          uint16 FlagsOffsetHbo = IPV4_NTOHS(IpHeaderPtr->Flags_Offset);
          uint16 FragmentOffset = (uint16)(FlagsOffsetHbo & IPV4_IP_FRAGMENT_OFFSET_MASK);
          /* defragment message if necessary and forward to next layer or protocol */

          LenByte = IpTotalLenByte - IpHdrLenByte;

          if (0 == LenByte)
          {
            /* ip datagram does not contain any payload. -> drop message */
            return;
          }

          /* ignore IP header options if available: */
          IpPayloadPtr = &DataPtr[IpHdrLenByte]; /* PRQA S 0310 */ /* MD_IpV4_11.04 */

#if (IPV4_IP_CHECK_RX_CHECKSUM == STD_ON)
# if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
          /* check header checksum */
          if(IPV4_CTRL_VAR(TcpIp_IpV4_ChecksumOffloadingSupport).Ip == FALSE)
          {
            if(0 == IpBase_TcpIpChecksumAdd((IPV4_P2C(uint8))IpHeaderPtr, IpHdrLenByte, 0, TRUE)) /* PRQA S 0310 */ /* MD_IpV4_11.04 */
            {
              /* checksum is ok */
            }
            else
            {
              /* checksum is invalid, so drop the message */
              return;
            }
          }
          else
          {
            /* IP checksum was already checked by HW */
          }
# endif /* TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED */
#endif /* IP_CHECK_RX_CHECKSUM */

          if ((0 != FragmentOffset) || (0 != (FlagsOffsetHbo & IPV4_IP_FLAGS_MORE_FRAGMENTS)))
          {
            /* this packet is a fragment */

#if (IPV4_IP_ENABLE_REASSEMBLY == STD_ON)
            if (IpV4_Ip_VCfgHasFragmentationConfig())
            {
              if (FALSE == IpV4_Ip_VReceiveFragment(IPV4_IPCTRLIDX, IpHeaderPtr, &IpPayloadPtr, &LenByte))
              {
                IpPayloadPtr = NULL_PTR;
              }
            }
            else
#endif
            {
              IpPayloadPtr = NULL_PTR;
            }
          }

          if (NULL_PTR != IpPayloadPtr)
          {
            IpV4_Ip_VForwardPacketToUpperLayer(IPV4_IPCTRLIDX, AddrId, IpHeaderPtr->SrcAddr, IpHeaderPtr->DestAddr, IpHeaderPtr->Prot, IpPayloadPtr, LenByte);
          }
        }
        else
        {
          /* incoming message not for this node */
          /* if(routing is activated) ? proceed : discard */
        }
      }
#if (IPV4_IP_CHECK_RX_CHECKSUM == STD_ON)
#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_OFF)
      else
      {
        /* header checksum error */
        /* discard message */
      }
#endif /* TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED */
#endif /* IPV4_IP_CHECK_RX_CHECKSUM */
    }
    else
    {
      /* IP version number error */
      /* discard message */
    }
  }
  else
  {
    /* IP header length error */
    /* discard message */
  }
} /* PRQA S 2006, 6010, 6030, 6060, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  IpV4_Ip_ProvideTxBuffer
 **********************************************************************************************************************/
/*! \brief        Request a buffer for transmission.
 *  \description  <br>This function is called by upper layer to get a transmit buffer and eventually to trigger an
 *                ARP request.
 *  \param[inout] AddrIdPtr             pointer to the IP address id that shall be used.
 *                                      If address ID is broadcast or multicast the auto-selected unicast address is returned.
 *  \param[in]    SockIdx               socket index of TcpIp
 *  \param[out]   BufIdx                pointer for buffer index
 *  \param[in]    DestAddrPtr           destination network address
 *  \param[out]   IpBufferPtr           pointer for provided buffer (pointer to the IP payload)
 *  \param[inout] LenBytePtr            pointer for provided buffer length in bytes (lenth of the IP payload)
 *  \param[out]   TxReqDescrPtr         pointer to the used transmit request descriptor
 *  \param[in]    ForceProvideBuffer    Provide a buffer even if no ARP resolution is available
 *  \return       BUFREQ_OK             buffer provided
 *  \return       BUFREQ_E_BUSY         address resolution pending or currently no buffer available. -> try again later
 *  \return       BUFREQ_E_NOT_OK       provide buffer failed
 *  \note
 *  \context      task level
 **********************************************************************************************************************/
FUNC(BufReq_ReturnType, IPV4_CODE) IpV4_Ip_ProvideTxBuffer(
    IPV4_P2V(IpV4_AddrIdType)                  AddrIdPtr,
    TcpIp_SockIdxType                          SockIdx,
    IPV4_P2C(IpBase_SockAddrInType)            DestAddrPtr,
    IPV4_P2V(uint8)                           *IpBufferPtr,
    IPV4_P2V(uint16)                           LenBytePtr,
    IPV4_P2V(TcpIp_IpTxRequestDescriptorType)  TxReqDescrPtr,
    boolean                                    ForceProvideBuffer
    )
{
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx;           /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif
  IpBase_AddrInType        DestAddr     = DestAddrPtr->sin_addr; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
  IpBase_EthPhysAddrType   DestMacAddr;
  TcpIp_ReturnType         ArpRetValue;
  BufReq_ReturnType        RetValue     = BUFREQ_E_NOT_OK;
  uint8                    CtrlAddrIdx;

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT,                              IPV4_IP_API_ID_PROVIDE_TX_BUFFER, IPV4_E_NOT_INITIALIZED, BUFREQ_E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_IP_COND_VALID_SOCKIDX(SockIdx),         IPV4_IP_API_ID_PROVIDE_TX_BUFFER, IPV4_E_INV_SOCK_IDX,    BUFREQ_E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(AddrIdPtr),              IPV4_IP_API_ID_PROVIDE_TX_BUFFER, IPV4_E_INV_POINTER,     BUFREQ_E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_OR_ANY_IPADDRID(*AddrIdPtr), IPV4_IP_API_ID_PROVIDE_TX_BUFFER, IPV4_E_INV_PARAM,       BUFREQ_E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(DestAddrPtr),            IPV4_IP_API_ID_PROVIDE_TX_BUFFER, IPV4_E_INV_POINTER,     BUFREQ_E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(IpBufferPtr),            IPV4_IP_API_ID_PROVIDE_TX_BUFFER, IPV4_E_INV_POINTER,     BUFREQ_E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(LenBytePtr),             IPV4_IP_API_ID_PROVIDE_TX_BUFFER, IPV4_E_INV_POINTER,     BUFREQ_E_NOT_OK )
  /* ------------------------------------------------- */

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  if (IPV4_ADDR_ID_ANY == (*AddrIdPtr))
  {
    /* auto select controller for outgoing message */
    uint8 IpCtrlIdxCandidate = 0;

    while(IpCtrlIdxCandidate < IpV4_VCfgGetMaxNumCtrls())
    {
      if ((IPV4_CTRL_VAR_X(IpV4_Ip_PhysLinkActive,             IpCtrlIdxCandidate) == TRUE) &&
          (IPV4_CTRL_VAR_X(IpV4_Ip_CtrlState,                  IpCtrlIdxCandidate) == IPV4_IP_ONLINE_ACTIVE) &&
          (IPV4_CTRL_VAR_X(IpV4_Ip_ActiveAddrAssignmentMethod, IpCtrlIdxCandidate) != IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE))
      {
        if((DestAddr & IPV4_CTRL_VAR_X(IpV4_Ip_ActiveAddr, IpCtrlIdxCandidate).NetMask) == (IPV4_CTRL_VAR_X(IpV4_Ip_ActiveAddr, IpCtrlIdxCandidate).NetAddr & IPV4_CTRL_VAR_X(IpV4_Ip_ActiveAddr, IpCtrlIdxCandidate).NetMask))
        {
          /* address is part of this subnet */
          break;
        }
      }

      IpCtrlIdxCandidate++;
    }

    if(IpCtrlIdxCandidate < IpV4_VCfgGetMaxNumCtrls())
    {
      /* use selected controller */
      IpCtrlIdx = IpCtrlIdxCandidate;
    }
#if (IpV4_Ip_VCfgGetDefaultCtrlIdx() < IpV4_VCfgGetMaxNumCtrls())
    else if ((IPV4_CTRL_VAR_X(IpV4_Ip_PhysLinkActive,             IpV4_Ip_VCfgGetDefaultCtrlIdx()) == TRUE) &&
             (IPV4_CTRL_VAR_X(IpV4_Ip_CtrlState,                  IpV4_Ip_VCfgGetDefaultCtrlIdx()) == IPV4_IP_ONLINE_ACTIVE) &&
             (IPV4_CTRL_VAR_X(IpV4_Ip_ActiveAddrAssignmentMethod, IpV4_Ip_VCfgGetDefaultCtrlIdx()) != IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE))
    {
      /* use default controller for all messages not directed to nodes in own subnet(s) */
      IpCtrlIdx = IpV4_Ip_VCfgGetDefaultCtrlIdx();
    }
#endif
    else
    {
      /* no suitable controller in active state found */
      return BUFREQ_E_NOT_OK;
    }

    /* set AddrId to AutoSelect_Broadcast address of the selected controller */
    (*AddrIdPtr) = IPV4_CTRL_VAR(IpV4_Ip_BcAddrId);
  }
  else
  {
    IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IPV4_IPCTRLIDX, *AddrIdPtr);
  }
#else
  if (IPV4_ADDR_ID_ANY == (*AddrIdPtr))
  {
    *AddrIdPtr = IPV4_CTRL_VAR(IpV4_Ip_AddrConfig)[IPV4_CTRL_ADDR_IDX_FIRST].IpAddrId;
  }
#endif

  IPV4_GET_ADDR_IDX_FROM_ADDR_ID(CtrlAddrIdx, *AddrIdPtr);

  TxReqDescrPtr->IpAddrId      = (*AddrIdPtr);
  TxReqDescrPtr->CtrlIdx       = IPV4_CTRL_IDX_IP_2_ETHIF(IPV4_IPCTRLIDX);

  if ((*LenBytePtr) > (IpV4_Ip_VCfgGetMaxTxMsgSize() - IPV4_IP_DEF_HEADER_LENGTH_BYTE))
  {
    /* requested length exceeds configured maximum. */
    return BUFREQ_E_NOT_OK;
  }

  if ((IPV4_CTRL_ADDR_IDX_ANY == CtrlAddrIdx)
#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
      || IPV4_CTRL_ADDR_IDX_IS_MULTICAST(CtrlAddrIdx)
#endif
     )
  {
    /* automatically select source address for transmission */
    /* Only one address supported for IPv4 */
    (*AddrIdPtr) = IPV4_CTRL_VAR(IpV4_Ip_AddrConfig)[IPV4_CTRL_ADDR_IDX_FIRST].IpAddrId;
  }

  if ((IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_OFFLINE) || (
      (IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_ONLINE_PASSIVE) &&
      (IpV4_Ip_VCfgIsAddrAssignmentEnabled(IPV4_IP_ADDR_ASSIGNMENT_METHOD_DHCP)      == FALSE) && 
      (IpV4_Ip_VCfgIsAddrAssignmentEnabled(IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL) == FALSE) ))
  {
    /* ERROR: Packets may not be sent in state OFFLINE or ONLINE_PASSIVE (if DHCP or LINKLOCAL address assignment is not enabled). ! */
    return BUFREQ_E_NOT_OK;
  }

  if (DestAddr == IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr)
  {
    /* it is not allowed to send packets to ourself. */
    return BUFREQ_E_NOT_OK;
  }

  /* check if physical address for network address is available: */
  if (IPV4_CHK_FLAG_U8(IpV4_Ip_TransferBlock[SockIdx].Flags, IPV4_IP_TRANSFER_BLOCK_FLAG_PHYS_DEST_ADDR))
  {
    /* Physical destination address for the socket has been set manually. Use this address and skip ARP. */
    DestMacAddr[0] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[0];
    DestMacAddr[1] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[1];
    DestMacAddr[2] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[2];
    DestMacAddr[3] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[3];
    DestMacAddr[4] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[4];
    DestMacAddr[5] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[5];

    ArpRetValue = TCPIP_OK;
  }
  else
  {
    IpBase_AddrInType NextHopIpAddr;

    if ((IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetMask & IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr) == (IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetMask & DestAddr))
    {
      /* address is inside the local subnet */
      NextHopIpAddr = DestAddr;
    }
    else if (DestAddr == TCPIP_INADDR_BROADCAST)
    {
      /* address is a global broadcast */
      NextHopIpAddr = DestAddr;
    }
    else if (IPV4_ADDR_IS_MULTICAST(DestAddr))
    {
      /* address is a multicast */
      NextHopIpAddr = DestAddr;
    }
    else
    {
      NextHopIpAddr = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).DefGwAddr;
    }

    if (IPV4_ADDR_ANY == NextHopIpAddr)
    {
      /* Destination is not on this link and no default router known
       * -> Cannot send packet.
       */
      return BUFREQ_E_NOT_OK;
    }

    ArpRetValue = IpV4_Arp_GetPhysicalAddress(IPV4_IPCTRLIDX, SockIdx, TRUE, NextHopIpAddr, &DestMacAddr[0], TRUE);
  }

  if((TCPIP_OK == ArpRetValue) || (TRUE == ForceProvideBuffer))
  {
    uint16  IpPayloadLenRemain = *LenBytePtr;
    uint8   PrevEthBufIdx      = IPV4_IP_TX_BUF_IDX_INV;

    /* Provide one or more (in case of fragmentation) tx buffers. */
    while (0 < IpPayloadLenRemain)
    {
      IPV4_P2V(Eth_DataType) EthBufPtr; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
      uint8                  EthBufIdx;
      uint16                 EthBufLen; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
      uint16                 FragPayloadLen = (uint16)(IpV4_Ip_VCfgGetMtuTx() - IPV4_IP_DEF_HEADER_LENGTH_BYTE);

      if (FragPayloadLen < IpPayloadLenRemain)
      {
        /* IP payload does not fit into one IP packet.
         * -> IP packet has to be sent in multiple fragments.
         */

        /* Trim length of fragment payload to be multiple of 8 octets */
        FragPayloadLen       -= (FragPayloadLen % 8);
        IpPayloadLenRemain   -= FragPayloadLen;
      }
      else
      {
        /* Complete IP payload fits into this fragment. */
        IpPayloadLenRemain  = 0;
      }

      EthBufLen = (FragPayloadLen + IPV4_IP_DEF_HEADER_LENGTH_BYTE);

      RetValue = TCPIP_LL_ProvideTxBuffer(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), IPV4_IP_FRAME_TYPE, IPV4_GET_SOCKET_ETHIF_FRAME_PRIO(SockIdx), &EthBufIdx, &EthBufPtr, &EthBufLen);

      if (BUFREQ_OK == RetValue)
      {
        if (PrevEthBufIdx == IPV4_IP_TX_BUF_IDX_INV)
        {
          /* This is an ethernet buffer for the first (and maybe the only) fragment. */
          TxReqDescrPtr->BufIdx    = EthBufIdx;
          TxReqDescrPtr->CurBufIdx = EthBufIdx;
        }
        else
        {
          /* This is an ethernet buffer for an additional IP fragment.
           * Link buffer of previous fragment with this fragment.
           */
          IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[PrevEthBufIdx].EthBufIdxNext = EthBufIdx;
        }

        /* Store information for this ethernet buffer index */
        IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[EthBufIdx].EthBufPtr     = (IPV4_P2V(uint8))EthBufPtr; /* PRQA S 0310 */ /* MD_IpV4_11.04 */
        IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[EthBufIdx].EthBufLen     = (FragPayloadLen + IPV4_IP_DEF_HEADER_LENGTH_BYTE);
        IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[EthBufIdx].EthBufIdxNext = IPV4_IP_TX_BUF_IDX_INV;

        PrevEthBufIdx = EthBufIdx;
      }
      else
      {
        /* Ethernet buffer could not be provided successfully. */

        /* Release already provided buffers for all previous fragments (if any) */
        if (IPV4_IP_TX_BUF_IDX_INV != PrevEthBufIdx)
        {
          (void)IpV4_Ip_Transmit(SockIdx, TxReqDescrPtr, 0, 0, DestAddrPtr->sin_addr, FALSE, 0, FALSE);
        }

        RetValue = BUFREQ_E_NOT_OK;
        break;
      }
    } /* while (0 < IpPayloadLenRemain) */

    if (BUFREQ_OK == RetValue)
    {
      /* Store information in IP tx descriptor */
      TxReqDescrPtr->IsEthBuf      = TRUE;

      /* IpPayloadPtr points to payload of the first (and maybe the only) fragment of this IP packet */
      TxReqDescrPtr->EthPayloadPtr = IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[TxReqDescrPtr->BufIdx].EthBufPtr;
      TxReqDescrPtr->EthPayloadLen = IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[TxReqDescrPtr->BufIdx].EthBufLen;
      TxReqDescrPtr->IpPayloadOfs  = IPV4_IP_DEF_HEADER_LENGTH_BYTE;

      (*IpBufferPtr) = &TxReqDescrPtr->EthPayloadPtr[IPV4_IP_DEF_HEADER_LENGTH_BYTE];
      (*LenBytePtr)  = (uint16)(TxReqDescrPtr->EthPayloadLen - IPV4_IP_DEF_HEADER_LENGTH_BYTE);
    }
  }
  else
  {
    /* Evaluate the ARP's return code in case it is not TCPIP_OK */
    if( ArpRetValue == TCPIP_E_PHYS_ADDR_MISS )
    {
      /* Physical address could not be received from ARP module. Either address is not yet stored in
         ARP table (then an ARP request was triggered), or ARP is not able to allocate a Tx buffer.
         -> Try again later */
      RetValue = BUFREQ_E_BUSY;
    }
    else
    {
      /* ARP's return code is not TCPIP_OK and not TCPIP_E, i.e. it is TCPIP_E_NOT_OK or invalid:
         Address resolution could not be started or the resolution is not desired ("ARP table full" mode is active) */
      RetValue = BUFREQ_E_NOT_OK;
    }
  }

  return RetValue;
} /* PRQA S 2006, 6010, 6030, 6060 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR */

/***********************************************************************************************************************
 *  IpV4_Ip_ProvideNextTxBuffer
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Ip_ProvideNextTxBuffer(
  IPV4_P2V(TcpIp_IpTxRequestDescriptorType)  TxReqDescrPtr,
  IPV4_P2V(uint8)                           *BufPtrPtr,
  IPV4_P2V(uint16)                           BufLenPtr)
{
  Std_ReturnType Result    = E_OK;
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8          IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT,                     IPV4_IP_API_ID_PROVIDE_NEXT_TX_BUFFER, IPV4_E_NOT_INITIALIZED, BUFREQ_E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(TxReqDescrPtr), IPV4_IP_API_ID_PROVIDE_NEXT_TX_BUFFER, IPV4_E_INV_POINTER,     BUFREQ_E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(BufPtrPtr),     IPV4_IP_API_ID_PROVIDE_NEXT_TX_BUFFER, IPV4_E_INV_POINTER,     BUFREQ_E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(BufLenPtr),     IPV4_IP_API_ID_PROVIDE_NEXT_TX_BUFFER, IPV4_E_INV_POINTER,     BUFREQ_E_NOT_OK )
  /* ------------------------------------------------- */

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx, TxReqDescrPtr->IpAddrId);
#endif

  if (IPV4_IP_TX_BUF_IDX_INV != TxReqDescrPtr->CurBufIdx)
  {
    uint8 NextBufIdx = IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[TxReqDescrPtr->CurBufIdx].EthBufIdxNext;

    if (IPV4_IP_TX_BUF_IDX_INV != NextBufIdx)
    {
      (*BufPtrPtr) =         &IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[NextBufIdx].EthBufPtr[IPV4_IP_DEF_HEADER_LENGTH_BYTE];
      (*BufLenPtr) = (uint16)(IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[NextBufIdx].EthBufLen - IPV4_IP_DEF_HEADER_LENGTH_BYTE);
    }
    else
    {
      Result = E_NOT_OK;
    }

    TxReqDescrPtr->CurBufIdx = NextBufIdx;
  }
  else
  {
    Result = E_NOT_OK;
  }

  return Result;
} /* IpV4_Ip_ProvideNextTxBuffer */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Ip_Transmit
 **********************************************************************************************************************/
FUNC(TcpIp_ReturnType, IPV4_CODE) IpV4_Ip_Transmit(
    TcpIp_SockIdxType                         SockIdx,
    IPV4_P2V(TcpIp_IpTxRequestDescriptorType) TxReqDescrPtr, /* PRQA S 3673 */ /* MD_IPV4_16.7_3673 */
    uint16                                    LenByte,
    uint8                                     Protocol,
    IpBase_AddrInType                         DestAddr,
    boolean                                   TxConf,
    uint8                                     UlTxReqTabIdx,
    boolean                                   RetryOnPhysAddrMiss)
{
  /* local variables --------------------------------- */
  TcpIp_ReturnType       Result;
  uint16                 RemainLenByte = LenByte;
  IpBase_EthPhysAddrType DestMacAddr =
  {
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U
  }; /* dummy value for call of TCPIP_LL_Transmit in case of 'cancel transmit' */
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8              IpCtrlIdx;     /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif
  /* IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON */

  /* ------------------------------------------------- */

  /* DET */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT,                      IPV4_IP_API_ID_TRANSMIT, IPV4_E_NOT_INITIALIZED,  E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_IP_COND_VALID_SOCKIDX(SockIdx), IPV4_IP_API_ID_TRANSMIT, IPV4_E_INV_SOCK_IDX,     E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(TxReqDescrPtr),  IPV4_IP_API_ID_TRANSMIT, IPV4_E_INV_POINTER,      E_NOT_OK )
  /* ------------------------------------------------- */

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  /* use controller that was chosen during "Ip_ProvideTxBuffer": */
  IpCtrlIdx = IPV4_ADDR_ID_2_CTRL_IDX(TxReqDescrPtr->IpAddrId);
#endif

  /* get the physical (MAC) address for the given network (IP) address */
  if (RemainLenByte == 0)
  {
    /* Transmit will be aborted. Next Hop determination not required. */
    Result = E_OK;
  }
  else if (IPV4_CHK_FLAG_U8(IpV4_Ip_TransferBlock[SockIdx].Flags, IPV4_IP_TRANSFER_BLOCK_FLAG_PHYS_DEST_ADDR))
  {
    /* Physical destination address for the socket has been set manually. Use this address and skip ARP. */
    DestMacAddr[0] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[0];
    DestMacAddr[1] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[1];
    DestMacAddr[2] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[2];
    DestMacAddr[3] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[3];
    DestMacAddr[4] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[4];
    DestMacAddr[5] = IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[5];

    Result = TCPIP_OK;
  }
  else
  {
    IpBase_AddrInType ReqIpAddr;

    if( ((IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetMask & IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr) == (IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetMask & DestAddr)) ||
        (TCPIP_INADDR_BROADCAST == DestAddr) || IPV4_ADDR_IS_MULTICAST(DestAddr) )
    {
      ReqIpAddr = DestAddr;
    }
    else
    {
      ReqIpAddr = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).DefGwAddr;
    }

    Result = IpV4_Arp_GetPhysicalAddress(IPV4_IPCTRLIDX, SockIdx, TRUE, ReqIpAddr, &DestMacAddr[0], TRUE);
    if(Result == TCPIP_E_PHYS_ADDR_MISS)
    {
      /* Setting length 0 here causes release of all ethernet buffers for this packet below. */
      RemainLenByte = 0;
    }
  }

  if ((TCPIP_OK == Result) || (FALSE == RetryOnPhysAddrMiss))
  {
    uint8           BufIdx                     = TxReqDescrPtr->BufIdx; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
    uint16          NextFragBlockOfs           = 0;
    boolean         CalculateProtocolChecksum;
    uint32          ProtocolChecksum           = 0;
    IPV4_P2V(uint8) ProtocolHdrPtr             = &IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[BufIdx].EthBufPtr[IPV4_IP_DEF_HEADER_LENGTH_BYTE];

    IpV4_Ip_Identification++;  /* increment IP identification number */

#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
    if (RemainLenByte > (IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[BufIdx].EthBufLen - IPV4_IP_DEF_HEADER_LENGTH_BYTE))
    {
      /* this packet needs fragmentation.
       * Checksum calculation of IP protocols by hardware not supported for fragmented packets.
       */
      CalculateProtocolChecksum = TRUE;
    }
    else
    {
      /* Check if the checksum of the upper layer (TCP, UDP or ICMPv4) can be calculated by the lower layer (HW) or has to be calculated by the upper layer itself. */
      switch(Protocol)
      {
# if (IPV4_SUPPORT_TCP == STD_ON)
        case TCPIP_PROTOCOL_TCP:
          CalculateProtocolChecksum = (boolean)(IPV4_CTRL_VAR(TcpIp_IpV4_ChecksumOffloadingSupport).Tcp == FALSE);
          break;
# endif
        case TCPIP_PROTOCOL_UDP:
          CalculateProtocolChecksum = (boolean)(IPV4_CTRL_VAR(TcpIp_IpV4_ChecksumOffloadingSupport).Udp == FALSE);
          break;

        case IPV4_IP_PROTOCOL_ICMP:
          CalculateProtocolChecksum = (boolean)(IPV4_CTRL_VAR(TcpIp_IpV4_ChecksumOffloadingSupport).Icmp == FALSE);
          break;

        default:
          CalculateProtocolChecksum = TRUE;
          break;

      }  /* switch(Protocol) */
    }
#else
    CalculateProtocolChecksum = TRUE;
#endif

    /* If the protocol checksum has to be calculated in software the following loop will iterate in two passes over all IP fragments.
     * Pass 1: Calculates upper layer protocol checksum for all fragments. The result will be stored in the upper layer protocol header located in the first fragment.
     * Pass 2: Triggers transmission of all fragments.
     * In case there is only one IP fragment and HW checksum calculation for the upper layer protocol is supported, pass 1 will be skipped and the loop will only do one interation.
     */

    /* for each provided ethernet buffer */
    while (IPV4_IP_TX_BUF_IDX_INV != BufIdx)
    {
      /* Store next ethernet buffer index before releasing current buffer because next pointer may be overwritten directly after releasing the buffer. */
      uint8 NextBufIdx = IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[BufIdx].EthBufIdxNext;

      if(RemainLenByte > 0)
      {
        IPV4_P2V(uint8)           EthPayloadPtr  = IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[BufIdx].EthBufPtr; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
        uint16                    EthPayloadLen  = IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[BufIdx].EthBufLen; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
        uint16                    FragBlockOfs   = NextFragBlockOfs;
        uint16                    FragPayloadLen = (uint16)(EthPayloadLen - IPV4_IP_DEF_HEADER_LENGTH_BYTE);
        boolean                   FragIsLast;

        if (RemainLenByte > FragPayloadLen)
        {
          /* remaining data does not fit into one IP packet */
          FragIsLast = FALSE;

          IPV4_ASSERT(0 == (FragPayloadLen % 8)); /* All fragment bufferes except for the last should have a length that is a multiple of 8 octets. */

          NextFragBlockOfs += (FragPayloadLen / 8);
          RemainLenByte    -=  FragPayloadLen;
        }
        else
        {
          /* this is the last fragment */
          FragIsLast = TRUE;

          FragPayloadLen = RemainLenByte;
          RemainLenByte  = 0;
        }

        if (TRUE == CalculateProtocolChecksum)
        {
          /* Calculate checksum of fragment */
          uint8 *FragPayloadPtr = &EthPayloadPtr[IPV4_IP_DEF_HEADER_LENGTH_BYTE];

          /* call the upper layer checksum calculation function */
          if ((0 == FragBlockOfs) && ((TCPIP_PROTOCOL_TCP == Protocol) || (TCPIP_PROTOCOL_UDP == Protocol)))
          {
            TcpIp_SockAddrInetType  LocSockAddr;
            TcpIp_SockAddrInetType  RemSockAddr;

            LocSockAddr.domain  = IPBASE_AF_INET;
            LocSockAddr.addr[0] = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr;
            RemSockAddr.domain  = IPBASE_AF_INET;
            RemSockAddr.addr[0] = DestAddr;

            /* Calculate pseudo header checksum */
            ProtocolChecksum = TcpIp_VCalcPseudoHdrAndChecksum((const IpBase_SockAddrType*)&RemSockAddr, (const IpBase_SockAddrType*)&LocSockAddr, NULL_PTR, LenByte, Protocol);  /* PRQA S 0310 */ /* MD_TCPIP_11.4_0310_sock */
          }

          if (FALSE == FragIsLast)
          {
            /* Calculate payload checksum of first or intermediate fragment */
            ProtocolChecksum = IpBase_TcpIpChecksumAdd(FragPayloadPtr, FragPayloadLen, ProtocolChecksum, FALSE);
          }
          else
          {
            /* Calculate payload checksum of last fragment and store finalized value in upper layer header */
            ProtocolChecksum = IpBase_TcpIpChecksumAdd(FragPayloadPtr, FragPayloadLen, ProtocolChecksum, TRUE);

            switch(Protocol)
            {
#if (IPV4_SUPPORT_TCP == STD_ON)
            case TCPIP_PROTOCOL_TCP:
              TcpIp_Tcp_StoreChecksumInHeader((uint16)ProtocolChecksum, ProtocolHdrPtr);
              break;
#endif
            case TCPIP_PROTOCOL_UDP:
              TcpIp_Udp_StoreChecksumInHeader((uint16)ProtocolChecksum, ProtocolHdrPtr);
              break;

#if (IPV4_SUPPORT_ICMP == STD_ON)
            case IPV4_IP_PROTOCOL_ICMP:
              IpV4_Icmp_StoreChecksumInHeader((uint16)ProtocolChecksum, ProtocolHdrPtr);
              break;
#endif

            default:
              {
                /* unsupported protocol.
                 * -> do nothing
                 */
              }
            }  /* switch(Protocol) */
          }
        }
        else
        {
          /* Trigger transmission fragment */

          uint16                    FlagsOffsetHbo;
          uint16                    FragTotalLen   = FragPayloadLen + IPV4_IP_DEF_HEADER_LENGTH_BYTE;
          IPV4_P2V(IpV4_Ip_HdrType) IpHdrPtr       = (IPV4_P2V(IpV4_Ip_HdrType))EthPayloadPtr; /* PRQA S 0310 */ /* MD_IpV4_11.04 */
          /* fill IP header ---------------------------------- */
          IpHdrPtr->Ver_Ihl                        = (((uint8)IPV4_IP_HEADER_VERSION_V4) << 4) | (IPV4_IP_DEF_HEADER_LENGTH_BYTE >> 2);
          IpHdrPtr->Tos                            = IPV4_GET_SOCKET_TYPE_OF_SERVICE(SockIdx);
          IpHdrPtr->TotLen                         = IPV4_HTONS(FragTotalLen);
          IpHdrPtr->Ident                          = IPV4_HTONS(IpV4_Ip_Identification);

          FlagsOffsetHbo = (uint16)(IPV4_IP_FLAGS_DONT_FRAGMENT | FragBlockOfs);

          if (FALSE == FragIsLast)
          {
            FlagsOffsetHbo |= IPV4_IP_FLAGS_MORE_FRAGMENTS;
          }

          IpHdrPtr->Flags_Offset = IPV4_HTONS(FlagsOffsetHbo);
          IpHdrPtr->Ttl          = IPV4_GET_SOCKET_TIME_TO_LIVE(SockIdx);
          IpHdrPtr->Prot         = Protocol;
          IpHdrPtr->SrcAddr      = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr;
          IpHdrPtr->DestAddr     = DestAddr;
          IpHdrPtr->Checksum     = 0; /* Zero used for calculation. Correct checksum will be set later. */

          /* calc IP header checksum and insert into header: */
#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
          if (TRUE == IPV4_CTRL_VAR(TcpIp_IpV4_ChecksumOffloadingSupport).Ip)
          {
            /* Checksum already set to zero. Checksum will be calculated by lower layer. */
          }
          else
#endif  /* TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED */
          {
            IpHdrPtr->Checksum = (uint16)IpBase_TcpIpChecksumAdd(EthPayloadPtr, IPV4_IP_DEF_HEADER_LENGTH_BYTE, 0, TRUE); /* PRQA S 0310 */ /* MD_IpV4_11.04 */
          }

          /* Store information that may be required for TxConfirmation */
          IpV4_Ip_SocketDesc[SockIdx].Prot = Protocol;
          IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[BufIdx].TxSockIdx  = SockIdx;
          IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[BufIdx].UlTxReqIdx = UlTxReqTabIdx;

          /* call TCPIP_LL_Transmit to transmit frame ----------- */
          if(E_OK == TCPIP_LL_Transmit(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), BufIdx, IPV4_IP_FRAME_TYPE, TxConf, FragTotalLen, &DestMacAddr[0]))
          {
            Result = TCPIP_OK;
          }
          else
          {
            /* Transmission of packet failed. */
            Result = TCPIP_E_NOT_OK;
          }
        }
      }
      else if ((CalculateProtocolChecksum == FALSE) || (LenByte == 0))
      {
        /* No more data to send. */
        /* Cancel transmission of this fragment */
        /* DestMacAddr will be ignored in the called function if the length to be transmitted is 0. */
        (void)TCPIP_LL_Transmit(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), BufIdx, IPV4_IP_FRAME_TYPE, FALSE, 0, &DestMacAddr[0]);
      }
      else
      {
        /* This is pass 1/2 (checksum calculation) and transmit shall not be aborted (LenByte > 0).
         * Transmit will be done in pass 2/2 (transmit). 
         */
      }

      if (IPV4_IP_TX_BUF_IDX_INV != NextBufIdx)
      {
        /* Continue with next fragment. */
        BufIdx = NextBufIdx;
      }
      else if ((TCPIP_OK == Result) && (TRUE == CalculateProtocolChecksum) && (LenByte > 0))
      {
        /* Checksum calculation for all fragments complete.
         * ->Restart loop send packets.
         */
        BufIdx                    = TxReqDescrPtr->BufIdx;
        CalculateProtocolChecksum = FALSE;
        RemainLenByte             = LenByte;
        NextFragBlockOfs          = 0;
      }
      else
      {
        /* All done.
         * -> End the loop
         */
        BufIdx = IPV4_IP_TX_BUF_IDX_INV;
      }
    } /* while */
  }
  else
  {
    /* Skip sending the packet. */
  }

  return Result;
} /* PRQA S 2006, 6060, 6010, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPAR, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  IpV4_Ip_GetPhysAddr
 **********************************************************************************************************************/
/*! \brief        Obtains the physical source address used by the EthIf controller implicitly specified via IpAddrId.
 *  \param[in]    IpAddrId           Local address identifier implicitely specifing the EthIf controller for which the
 *                                   physical address shall be obtained.
 *  \param[out]   PhysAddrPtr        Pointer to the memory where the physical source address (MAC address) in network
 *                                   byte order is stored
 *  \return       E_OK               The request was successful <br>
 *                E_NOT_OK           The request was not successful, e.g. no unique Ctrl specified via IpAddrId.
 *  \context      task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) IpV4_Ip_GetPhysAddr(
    IpV4_AddrIdType IpAddrId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) PhysAddrPtr )
{
  uint8 IpCtrlIdx;    /* PRQA S 0781 */ /* MD_IpV4_5.6 */
  uint8 EthIfCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
  Std_ReturnType RetValue;

  if(FALSE == IPV4_COND_VALID_IPADDRID(IpAddrId))
  {
    RetValue = E_NOT_OK;
  }
  else
  {
    /* Get the IpControllerIndex */
    IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx, IpAddrId);

    /* Get the EthIf controller index */
    EthIfCtrlIdx = IpV4_CtrlIdxIp2EthIf[IpCtrlIdx];

    /* Get the phys addr */
    TCPIP_LL_GetPhysAddr(EthIfCtrlIdx, PhysAddrPtr);
    RetValue = E_OK;
  }

  return RetValue;
}

/***********************************************************************************************************************
 *  IpV4_Ip_GetRemotePhysAddr
 **********************************************************************************************************************/
/*! \brief        Lookup the physical address for a remote network address. <br>
 *  \description  TcpIp_GetRemotePhysAddr queries the IP/physical address translation table specified by CtrlIdx and
 *                returns the physical address related to the IP address specified by IpAddrPtr. In case no physical
 *                address can be retrieved and parameter initRes is TRUE, address resolution for the specified IP
 *                address is initiated on the local network.
 *  \param[in]    CtrlIdx             EthIf controller index to identify the related ARP/NDP table.
 *  \param[in]    IpAddrPtr           specifies the IP address for which the physical address shall be retrieved
 *  \param[in]    InitRes             specifies if the address resolution shall be initiated (TRUE) or not (FALSE) in
 *                                    case the physical address related to the specified IP address is currently
 *                                    unknown.
 *  \param[out]   PhysAddrPtr         Pointer to the memory where the physical address (MAC address) related to the
 *                                    specified IP address is stored in network byte order.
 *  \return       TCPIP_E_OK               specified IP address resolved, physical address provided via PhysAddrPtr <br>
 *                TCPIP_E_NOT_OK           physical address currently unknown, not even resolution could be started!
 *                TCPIP_E_PHYS_ADDR_MISS   physical address currently unknown (address resolution initiated if initRes set to TRUE)
 *  \context      task level
 **********************************************************************************************************************/
FUNC(TcpIp_ReturnType, TCPIP_CODE) IpV4_Ip_GetRemotePhysAddr(
    uint8                                                       CtrlIdx,
    P2CONST(TcpIp_SockAddrInetType, AUTOMATIC, TCPIP_APPL_DATA) IpAddrPtr,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR)                     PhysAddrPtr,
    boolean                                                     InitRes )
{
  TcpIp_ReturnType  RetVal;
  IpBase_AddrInType RemoteIpAddr = IpAddrPtr->addr[0];
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_05.06 */

  /* get IpCtrlIdx */
  if(E_OK == IpV4_CtrlIdxEthIf2Ip(CtrlIdx, &IpCtrlIdx))
  {
    /* get phys addr */
    RetVal = IpV4_Arp_GetPhysicalAddress(IpCtrlIdx, 0, FALSE, RemoteIpAddr, PhysAddrPtr, InitRes);
  }
  else
  {
    RetVal = TCPIP_E_NOT_OK;
  }

  return RetVal;
}

/***********************************************************************************************************************
 *  IpV4_GetCtrlIdx
 **********************************************************************************************************************/
/*! \brief        IpV4_GetCtrlIdx returns the index of the EthIf controller related to LocalAddrId.
 *  \param[in]    AddrId              Local IP address identifier implicitely specifing the EthIf controller that shall
 *                                    be returned
 *  \param[out]   CtrlIdxPtr          Pointer to the memory where the index of the EthIf controller related to
 *                                    LocalAddrId is stored
 *  \return       E_OK                The request was successful <br>
 *                E_NOT_OK            The request was not successful
 *  \context      task level
 *  \note
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) IpV4_GetCtrlIdx(
    IpV4_AddrIdType AddrId,
    P2VAR(uint8, AUTOMATIC, TCPIP_APPL_VAR) CtrlIdxPtr )
{

  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */

  /* Get the IpControllerIndex */
  IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx, AddrId);

  /* Get the EthIf controller index */
  *CtrlIdxPtr = IpV4_CtrlIdxIp2EthIf[IpCtrlIdx];

  return E_OK;
}

/***********************************************************************************************************************
 *  IpV4_Ip_TxConfirmation
 **********************************************************************************************************************/
/*! \brief        Confirmation of a message transmission.
 *  \description  <br>This callback function is called by lower layer (EthIf) if a message has been transmitted by the
 *                hardware.
 *  \param[in]    CtrlIdx               controller index
 *  \param[in]    BufIdx                buffer index
 *  \return       void
 *  \note
 *  \context      interrupt or task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_TxConfirmation(
    uint8 CtrlIdx,
    uint8 BufIdx )
{
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx;           /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif
  TcpIp_SockIdxType SockIdx; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
  uint8 UlTxReqTabIdx;
  uint8 IpProtocol;

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT, IPV4_IP_API_ID_TX_CONFIRMATION, IPV4_E_NOT_INITIALIZED )
  /* ------------------------------------------------- */

  /* Map EthIfCtrlIdx to IpCtrlIdx or return if IP is not active on this EthIfCtrl. */
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  if (!IPV4_CTRL_IDX_ETHIF_2_IP(CtrlIdx, IpCtrlIdx))
#else
  if (CtrlIdx != IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx))
#endif
  {
    /* IP not active on this EthIf controller */
    return;
  }

  SockIdx       = IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[BufIdx].TxSockIdx;  /* PRQA S 0781 */ /* MD_IpV4_05.06 */
  UlTxReqTabIdx = IPV4_CTRL_VAR(IpV4_Ip_Buf2TxReqMap)[BufIdx].UlTxReqIdx;
  IpProtocol    = IpV4_Ip_SocketDesc[SockIdx].Prot;

  if(IPV4_IP_PROTOCOL_UDP == IpProtocol)
  {
    TcpIp_Udp_TxConfirmation(SockIdx, UlTxReqTabIdx);
  }
#if (IPV4_SUPPORT_TCP == STD_ON)
  else if(IPV4_IP_PROTOCOL_TCP == IpProtocol)
  {
    /* do not forward TxConfirmation to TCP, TCP is not interested in this information
       -> do nothing */
  }
#endif /* IPV4_SUPPORT_TCP */
  else
  {
    /* invalid protocol:
       this should never happen -> ignore tx confirmation */
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Ip_Cbk_TrcvLinkStateChg
 **********************************************************************************************************************/
/*! \brief      This callback function is called by lower layer on physical link status change
 *  \param[in]  CtrlIdx               controller index
 *  \param[in]  TrcvLinkState         transceiver link state
 *  \context    interrupt or task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_Cbk_TrcvLinkStateChg(
    uint8 CtrlIdx,
    EthTrcv_LinkStateType TrcvLinkState )
{
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx;           /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT, IPV4_IP_API_ID_TRCV_LNK_ST_CH, IPV4_E_NOT_INITIALIZED )
  /* ------------------------------------------------- */

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  if (!IPV4_CTRL_IDX_ETHIF_2_IP(CtrlIdx, IpCtrlIdx))
#else
  if (CtrlIdx != IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx))
#endif
  {
    return;
  }

  if(ETHTRCV_LINK_STATE_DOWN == TrcvLinkState)
  {
    TcpIp_Cbk_VTrcvLinkStateChg(IPV4_IPCTRLIDX, IPBASE_AF_INET, FALSE); /* notify TcpIp/Dhcp */

    /* Set physical link indication to FALSE. (State of IP instance will be changed in MainFunction) */
    IPV4_CTRL_VAR(IpV4_Ip_PhysLinkActive) = FALSE;
  }
  else
  {
    TcpIp_Cbk_VTrcvLinkStateChg(IPV4_IPCTRLIDX, IPBASE_AF_INET, TRUE); /* notify TcpIp/Dhcp */

    /* Set physical link indication to TRUE. (State of IP instance will be changed in MainFunction) */
    IPV4_CTRL_VAR(IpV4_Ip_PhysLinkActive) = TRUE;

#if defined TCPIP_INV_DEM_EVENT_ID
# if (TcpIp_NumIpV4CtrlsOfDemEventTCPIP_E_DUPLICATE_DHCP_ADDR > 0)
    /* In case the link has been down, before, the address-assignment was renewed and thus related DEM event is now being reset */
    IpV4_ResetDemEventIpCtrl(TcpIp_DemEventTCPIP_E_DUPLICATE_DHCP_ADDRSnvsByIpV4Ctrl, TcpIp_NumIpV4CtrlsOfDemEventTCPIP_E_DUPLICATE_DHCP_ADDR, IpCtrlIdx);
# endif
#endif
  }
} /* IpV4_Ip_Cbk_TrcvLinkStateChg */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Ip_GetLocNetAddr
 **********************************************************************************************************************/
/*! \brief        Request the current IP address for a given IP address id
 *  \description  <br>Reading the local IP address is mostly used for diagnostic purposes.
 *  \param[in]    AddrId                id of the IPv4 address
 *  \param[out]   NetAddrPtr            pointer for the local network address
 *  \return       E_OK                  local network address returned
 *  \return       E_NOT_OK              local network address access failed
 *  \note
 *  \context      task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Ip_GetLocNetAddr(
  IpV4_AddrIdType AddrId,
  P2VAR(IpBase_AddrInType, AUTOMATIC, IPV4_APPL_DATA) NetAddrPtr )
{
  Std_ReturnType RetValue = E_NOT_OK;
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif
  uint8 CtrlAddrIdx;

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT,                   IPV4_IP_API_ID_GET_LOC_NET_ADDR, IPV4_E_NOT_INITIALIZED, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_IPADDRID(AddrId), IPV4_IP_API_ID_GET_LOC_NET_ADDR, IPV4_E_INV_PARAM,       E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(NetAddrPtr),  IPV4_IP_API_ID_GET_LOC_NET_ADDR, IPV4_E_INV_POINTER,     E_NOT_OK )
  /* ------------------------------------------------- */

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx,   AddrId);
#endif
  IPV4_GET_ADDR_IDX_FROM_ADDR_ID(CtrlAddrIdx, AddrId);

  if (IPV4_CTRL_ADDR_IDX_ANY != CtrlAddrIdx)
  {
#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
    if (IPV4_CTRL_ADDR_IDX_IS_MULTICAST(CtrlAddrIdx))
    {
      /* return multicast address */
      uint8 McCtrlAddrIdx = IPV4_CTRL_ADDR_IDX_2_MULTICAST_ADDR_IDX(CtrlAddrIdx);

      if (IPV4_ADDR_ANY != IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[McCtrlAddrIdx])
      {
        (*NetAddrPtr) = IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[McCtrlAddrIdx];
        RetValue = E_OK;
      }
    }
    else
#endif
    {
      /* return unicast address */
      (*NetAddrPtr) = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr;

      if(IPV4_ADDR_ANY != IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr)
      {
        RetValue = E_OK;
      }
    }
  }
  else
  {
    /* return destination address of last received broadcast packet */
    *NetAddrPtr = IPV4_CTRL_VAR(IpV4_Ip_LastBcAddr);
    RetValue = E_OK;
  }

  return RetValue;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Ip_GetDefaultRouterNetAddr
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Ip_GetDefaultRouterNetAddr(
  IpV4_AddrIdType                                     ipAddrId,
  P2VAR(IpBase_AddrInType, AUTOMATIC, IPV4_APPL_DATA) defRouterNetAddrPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (IPV4_COND_VALID_IPADDRID(ipAddrId))
  {
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
    uint8 IpCtrlIdx = IPV4_ADDR_ID_2_CTRL_IDX(ipAddrId); /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif

    if (defRouterNetAddrPtr != NULL_PTR)
    {
      *defRouterNetAddrPtr = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).DefGwAddr;
      retVal = E_OK;
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}

/***********************************************************************************************************************
 *  IpV4_Ip_GetLocNetMask
 **********************************************************************************************************************/
/*! \brief        Request the current net mask for a given IP address id
 *  \description  <br>Reading the local network mask is mostly used for diagnostic purposes.
 *  \param[in]    AddrId                id of the IPv4 address
 *  \param[out]   NetMaskPtr            pointer for the local network mask
 *  \return       E_OK                  local network mask returned
 *  \return       E_NOT_OK              local network mask access failed
 *  \note
 *  \context      task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Ip_GetLocNetMask(
    IpV4_AddrIdType AddrId,
    P2VAR(IpBase_AddrInType, AUTOMATIC, IPV4_APPL_DATA) NetMaskPtr )
{
  Std_ReturnType RetValue;
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT,                   IPV4_IP_API_ID_GET_LOC_NET_MASK, IPV4_E_NOT_INITIALIZED, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_IPADDRID(AddrId), IPV4_IP_API_ID_GET_LOC_NET_ADDR, IPV4_E_INV_PARAM, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(NetMaskPtr),  IPV4_IP_API_ID_GET_LOC_NET_MASK, IPV4_E_INV_POINTER, E_NOT_OK )
  /* ------------------------------------------------- */

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx, AddrId);
#endif

  if(0 != IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetMask)
  {
    *NetMaskPtr = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetMask;
    RetValue = E_OK;
  }
  else
  {
    /* no valid address available */
    *NetMaskPtr = 0;
    RetValue = E_NOT_OK;
  }

  return RetValue;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Ip_GetActiveAddrAssignmentMethod
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 **********************************************************************************************************************/
FUNC(uint8, IPV4_CODE) IpV4_Ip_GetActiveAddrAssignmentMethod(
  IpV4_AddrIdType ipAddrId)
{
  uint8 retVal;
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif
  uint8 ctrlAddrIdx;

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx,   ipAddrId);
#endif
  IPV4_GET_ADDR_IDX_FROM_ADDR_ID(ctrlAddrIdx, ipAddrId);

  /* #10 Determine address type (ANY, UNICAST, MULTICAST) specified by ipAddrId and return assignment method. */

  if (ctrlAddrIdx == IPV4_CTRL_ADDR_IDX_ANY)
  {
    /* Broadcast address is assigned statically. */
    retVal = IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC;
  }
  else if (IPV4_CTRL_ADDR_IDX_IS_UNICAST(ctrlAddrIdx))
  {
    /* Unicast address assignment method is configuration and runtime dependent. */
    retVal = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod);
  }
  else
  {
#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
    uint8 mcAddrIdx = IPV4_CTRL_ADDR_IDX_2_MULTICAST_ADDR_IDX(ctrlAddrIdx);

    IPV4_ASSERT(mcAddrIdx < IpV4_Ip_VCfgGetMulticastAddrCount());

    if (IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[mcAddrIdx] != IPV4_ADDR_ANY)
    {
      /* MULTICAST addresses are assigned statically. */
      retVal = IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC;
    }
    else
    {
      retVal = IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE;
    }
#else
    IPV4_ASSERT_UNREACHABLE();
    retVal = IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE;
#endif
  }

  return retVal;
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV4_Ip_GetActiveAddrAssignmentMethod() */

/**********************************************************************************************************************
 *  IpV4_Ip_IsAddrIdAcceptable()
 **********************************************************************************************************************/
/*! \brief        This function checks whether the address identifier of a received packet is acceptable for a socket
 *                bound to a specific address identifier.
 *                The check is performed according to the acceptance filter given in [SWS_TCPIP_00106].
 *  \param[in]    BindIpAddrId           ip address identifier to which the socket has been bound
 *  \param[in]    RecvIpAddrId           ip address identifier of the received packet
 *  \param[out]   MatchType              specifies the type of the match (e.g. TCPIP_IF_MATCH, TCPIP_EXACT_MATCH)
 *  \return       TRUE                   packet is acceptable
 *  \return       FALSE                  packet is not acceptable
 *  \context      interrupt or task level
 **********************************************************************************************************************/
FUNC(boolean, IPV4_CODE) IpV4_Ip_IsAddrIdAcceptable(IpV4_AddrIdType BindIpAddrId, IpV4_AddrIdType RecvIpAddrId, IPV4_P2V(uint8) MatchType)
{
  /* Det checks */
  /* PRQA S 3109 2 */ /* MD_MSR_14.3 */
  IpV4_CheckDetErrorReturnValue(IPV4_COND_VALID_OR_ANY_IPADDRID(BindIpAddrId), IPV4_API_ID_IS_ADDR_ID_ACCEPTABLE, IPV4_E_INV_PARAM, FALSE);
  IpV4_CheckDetErrorReturnValue(IPV4_COND_VALID_IPADDRID(RecvIpAddrId),        IPV4_API_ID_IS_ADDR_ID_ACCEPTABLE, IPV4_E_INV_PARAM, FALSE);
  /**/

  if (IPV4_ADDR_ID_ANY == BindIpAddrId)
  {
    (*MatchType) = IPV4_ADDR_MATCH_EVER;
    return TRUE;
  }

  if (RecvIpAddrId == BindIpAddrId)
  {
    /* address matches filter address (exact match) */
    (*MatchType) = IPV4_ADDR_MATCH_EXACT;
    return TRUE;
  }

  if ((IPV4_ADDR_ID_2_ADDR_IDX(BindIpAddrId) == IPV4_CTRL_ADDR_IDX_ANY) || (IPV4_ADDR_ID_2_ADDR_IDX(RecvIpAddrId) == IPV4_CTRL_ADDR_IDX_ANY))
  {
    /* bind or received address is an AutoSelect_Multicast address */
    if (IPV4_ADDR_ID_2_CTRL_IDX(BindIpAddrId) == IPV4_ADDR_ID_2_CTRL_IDX(RecvIpAddrId))
    {
      /* both addresses are on same controller If-match */
      (*MatchType) = IPV4_ADDR_MATCH_IF;
      return TRUE;
    }
  }

  return FALSE;
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV4_Ip_IsAddrIdAcceptable() */

/***********************************************************************************************************************
 *  IpV4_Ip_RequestIpAddrAssignment
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) IpV4_Ip_RequestIpAddrAssignment(
    uint8                       ipAddrId,
    TcpIp_IpAddrAssignmentType  addrAssgnmentType,
    IpBase_AddrInType           localIpAddr,
    uint8                       netmaskCidr,
    IpBase_AddrInType           defaultRouter)
{
  Std_ReturnType          retVal = E_NOT_OK;
  uint8                   IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
  uint8                   ctrlAddrIdx;

  /* #05 Map TcpIp address assignment type to IPv4 address assignment method. */
  uint8 addrAssignmentMethod = IPV4_CONVERT_TCPIP_ADDR_ASSIGNMENT_TYPE(addrAssgnmentType);

  /* #10 Check input parameters. */

  /* DET checks */
  IpV4_CheckDetErrorReturnValue(IPV4_COND_INIT, IPV4_IP_API_ID_REQ_IP_ADDR_ASSIGN, IPV4_E_NOT_INITIALIZED, E_NOT_OK)

  if(FALSE == IPV4_COND_VALID_IPADDRID(ipAddrId))
  {
    return E_NOT_OK;
  }

  IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx,   ipAddrId);
  IPV4_GET_ADDR_IDX_FROM_ADDR_ID(ctrlAddrIdx, ipAddrId);

  /* #20 Verify that IP instance is not in state OFFLINE. */
  if(IPV4_CTRL_VAR(IpV4_Ip_CtrlState) != IPV4_IP_OFFLINE)
  {
    /* #30 Check if address type is UNICAST or MULTICAST. */
    if (IPV4_CTRL_ADDR_IDX_IS_UNICAST(ctrlAddrIdx))
    {
      uint8 addrAssignmentPrio = IpV4_Ip_VCfgGetAddrAssignmentPrio(addrAssignmentMethod);

      if (addrAssignmentPrio != IPV4_IP_ADDR_ASSIGNMENT_PRIO_NONE)
      {
        uint8 addrAssignmentCfg  = IpV4_Ip_VCfgGetAddrAssignmentCfgByPrio(addrAssignmentPrio);

        /* #40 Do not allow address assignment if trigger is configured to AUTOMATIC. */
        if (IPV4_CHK_FLAG_U8(addrAssignmentCfg, IPV4_IP_ADDR_ASSIGNMENT_FLAG_AUTO_TRIGGER) == FALSE)
        {
          /* #50 Trigger address assignment method. */
          retVal = IpV4_Ip_VTriggerAddrAssignment(IpCtrlIdx, addrAssignmentCfg, TRUE);
          /* #60 Store requested address value if assignment method is STATIC. */
          if (addrAssignmentMethod == IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC)
          {
            if (localIpAddr != IPV4_ADDR_ANY)
            {
              IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Requested)->NetAddr   = localIpAddr;
              IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Requested)->NetMask   = IPBASE_HTON32(0xFFFFFFFFu << (32 - netmaskCidr));
              IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Requested)->DefGwAddr = defaultRouter;

              IpV4_Ip_VIpAddrAssignmentReadyNotification(IpCtrlIdx, IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC, TRUE);
              retVal = E_OK;
            }
            else if (IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Default) != NULL_PTR)
            {
              /* Assign configured default address. */
              *IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Requested) = *IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Default);

              IpV4_Ip_VIpAddrAssignmentReadyNotification(IpCtrlIdx, IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC, TRUE);
              retVal = E_OK;
            }
            else
            {
              /* ERROR: No default address configured. */
              IPV4_ASSERT_UNREACHABLE();
            }
          }
        }
      }
    }
    else
    {
      /* #70 Update MULTICAST address value. */
#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
      uint8 mcAddrIdx = IPV4_CTRL_ADDR_IDX_2_MULTICAST_ADDR_IDX(ctrlAddrIdx);
      retVal = IpV4_Ip_VChangeMulticastAddrAssignment(IpCtrlIdx, mcAddrIdx, localIpAddr);
#else
      IPV4_ASSERT_UNREACHABLE();
#endif
    }
  }

  return retVal;
} /* IpV4_Ip_RequestIpAddrAssignment() */ /* PRQA S 2006, 6010, 6030, 6060, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  IpV4_Ip_ReleaseIpAddrAssignment
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, TCPIP_CODE) IpV4_Ip_ReleaseIpAddrAssignment(
    uint8                      ipAddrId,
    TcpIp_IpAddrAssignmentType addrAssignmentType)
{
  Std_ReturnType          retVal = E_NOT_OK;
  uint8                   IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
  uint8                   ctrlAddrIdx;
  uint8                   addrAssignmentPrio;

  uint8 addrAssignmentMethodToRelease;

  IPV4_ASSERT(IPV4_COND_INIT);

  /* #10 Check input parameters. */

  /* #15 Map TcpIp address assignment type to IPv4 address assignment method. */
  if(IPV4_COND_VALID_IPADDRID(ipAddrId))
  {
    if (addrAssignmentType < 0xFFu)
    {
      addrAssignmentMethodToRelease = IPV4_CONVERT_TCPIP_ADDR_ASSIGNMENT_TYPE(addrAssignmentType);
    }
    else
    {
      addrAssignmentMethodToRelease = 0xFFu;
    }
 
    IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx, ipAddrId);
    IPV4_GET_ADDR_IDX_FROM_ADDR_ID(ctrlAddrIdx, ipAddrId);

    /* #20 Handle addresses of type UNICAST. */
    if (IPV4_CTRL_ADDR_IDX_IS_UNICAST(ctrlAddrIdx))
    {
      /* #30 Iterate over all configured address assignment methods (priority is not important here). */
      for (addrAssignmentPrio = IPV4_IP_ADDR_ASSIGNMENT_PRIO_HIGHEST; addrAssignmentPrio <= IPV4_IP_ADDR_ASSIGNMENT_PRIO_LOWEST; addrAssignmentPrio++)
      {
        uint8 addrAssignmentCfg    = IpV4_Ip_VCfgGetAddrAssignmentCfgByPrio(addrAssignmentPrio);
        uint8 addrAssignmentMethod = IpV4_Ip_VCfgGetAddrAssignmentMethodByCfg(addrAssignmentCfg);

        /* #40 Only release address assignment if trigger is not configured to AUTOMATIC. */
        if ((addrAssignmentMethod != IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE) && (IPV4_CHK_FLAG_U8(addrAssignmentCfg, IPV4_IP_ADDR_ASSIGNMENT_FLAG_AUTO_TRIGGER) == FALSE))
        {
          /* #50 Release address assignment if method was explicitly specified or all assignments shall be released. */
          if ((addrAssignmentMethodToRelease == TCPIP_IPADDR_ASSIGNMENT_ANY) || (addrAssignmentMethodToRelease == addrAssignmentMethod))
          {
            (void)IpV4_Ip_VTriggerAddrAssignment(IpCtrlIdx, addrAssignmentCfg, FALSE);
            retVal = E_OK;
          }
        }
      }
    }
    else 
    {
#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
      if ((addrAssignmentMethodToRelease == TCPIP_IPADDR_ASSIGNMENT_ANY) || (addrAssignmentMethodToRelease == IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC))
      {
        /* #60 Handle addresses of type MULTICAST. */
        uint8 mcAddrIdx = IPV4_CTRL_ADDR_IDX_2_MULTICAST_ADDR_IDX(ctrlAddrIdx);
        retVal = IpV4_Ip_VChangeMulticastAddrAssignment(IpCtrlIdx, mcAddrIdx, IPV4_ADDR_ANY);
      }
#else
      IPV4_ASSERT_UNREACHABLE();
#endif
    }
  }

  return retVal;
} /* IpV4_Ip_ReleaseIpAddrAssignment() */ /* PRQA S 6080 */ /* MD_MSR_MD_MSR_STMIF */

/***********************************************************************************************************************
 *  IpV4_Ip_ResetSocket
 **********************************************************************************************************************/
/*! \brief      Reset parameters (e.g.: TTL, ToS, Frame Priority) for a specific socket to default values
 *  \param[in]  SockIdx             socket index
 *  \context    task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_ResetSocket(TcpIp_SockIdxType SockIdx)
{
  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_IP_COND_VALID_SOCKIDX(SockIdx), IPV4_IP_API_ID_RESET_SOCKET, IPV4_E_INV_SOCK_IDX )
  /* ------------------------------------------------- */

  IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[0] = 0;
  IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[1] = 0;
  IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[2] = 0;
  IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[3] = 0;
  IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[4] = 0;
  IpV4_Ip_TransferBlock[SockIdx].PhysDestAddr[5] = 0;
  IpV4_Ip_TransferBlock[SockIdx].EthIfFramePrio  = 0;
  IpV4_Ip_TransferBlock[SockIdx].TimeToLive      = 0;
  IpV4_Ip_TransferBlock[SockIdx].TypeOfService   = 0;
  IpV4_Ip_TransferBlock[SockIdx].Flags           = 0;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Ip_SetTimeToLive
 **********************************************************************************************************************/
/*! \brief      Set socket specific value of the 'Time To Live' IPv4 header field used in outgoing packets
 *  \param[in]  SockIdx             socket index
 *  \param[in]  Value               value of the 'Time to Live' field
 *  \context    task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_SetTimeToLive(TcpIp_SockIdxType SockIdx, uint8 Value)
{
  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT,                      IPV4_IP_API_ID_SET_TIME_TO_LIVE, IPV4_E_NOT_INITIALIZED )
  IpV4_CheckDetErrorReturnVoid( IPV4_IP_COND_VALID_SOCKIDX(SockIdx), IPV4_IP_API_ID_SET_TIME_TO_LIVE, IPV4_E_INV_SOCK_IDX    )
  /* ------------------------------------------------- */

  IpV4_Ip_TransferBlock[SockIdx].TimeToLive = Value;
  IpV4_Ip_TransferBlock[SockIdx].Flags |= IPV4_IP_TRANSFER_BLOCK_FLAG_TIME_TO_LIVE;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Ip_SetTypeOfService
 **********************************************************************************************************************/
/*! \brief      Set socket specific value of the 'Type of Service' IPv4 header field used in outgoing packets
 *  \param[in]  SockIdx             socket index
 *  \param[in]  Value               value of the 'Type of Service' field
 *  \context    task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_SetTypeOfService(TcpIp_SockIdxType SockIdx, uint8 Value)
{
  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT,                      IPV4_IP_API_ID_SET_TYPE_OF_SERVICE, IPV4_E_NOT_INITIALIZED )
  IpV4_CheckDetErrorReturnVoid( IPV4_IP_COND_VALID_SOCKIDX(SockIdx), IPV4_IP_API_ID_SET_TYPE_OF_SERVICE, IPV4_E_INV_SOCK_IDX    )
  /* ------------------------------------------------- */

  IpV4_Ip_TransferBlock[SockIdx].TypeOfService = Value;
  IpV4_Ip_TransferBlock[SockIdx].Flags |= IPV4_IP_TRANSFER_BLOCK_FLAG_TYPE_OF_SERVICE;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Ip_SetPhysDestAddr
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_SetPhysDestAddr(TcpIp_SockIdxType sockIdx, IPV4_P2C(uint8) physDestAddrPtr)
{
  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT,                      IPV4_IP_API_ID_SET_TYPE_OF_SERVICE, IPV4_E_NOT_INITIALIZED )
  IpV4_CheckDetErrorReturnVoid( IPV4_IP_COND_VALID_SOCKIDX(sockIdx), IPV4_IP_API_ID_SET_TYPE_OF_SERVICE, IPV4_E_INV_SOCK_IDX    )
  /* ------------------------------------------------- */

  /* #10 Check if physDestAddrPtr is not a NULL_PTR. */
  if (physDestAddrPtr != NULL_PTR)
  {
    /* #20 Store provided physical address in the socket data structure and set valid flag. */
    uint8_least physAddrByteIdx;
    
    for (physAddrByteIdx = 0; physAddrByteIdx < ETH_PHYS_ADDR_LEN_BYTE; physAddrByteIdx++)
    {
      IpV4_Ip_TransferBlock[sockIdx].PhysDestAddr[physAddrByteIdx] = physDestAddrPtr[physAddrByteIdx];
    }

    IPV4_SET_FLAG_U8(IpV4_Ip_TransferBlock[sockIdx].Flags, IPV4_IP_TRANSFER_BLOCK_FLAG_PHYS_DEST_ADDR);
  }
  else
  {
    /* #30 Otherwise clear flag. */
    IPV4_CLR_FLAG_U8(IpV4_Ip_TransferBlock[sockIdx].Flags, IPV4_IP_TRANSFER_BLOCK_FLAG_PHYS_DEST_ADDR);
  }  
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Ip_SetEthIfFramePrio
 **********************************************************************************************************************/
/*! \brief      Set socket specific Frame Priority value that is passed to the lower layer (EthIf)
 *  \param[in]  SockIdx             socket index
 *  \param[in]  Value               Frame priority value (0-7)
 *  \return     E_OK                Frame priority updated
 *  \return     E_NOT_OK            Value out of range
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Ip_SetEthIfFramePrio(TcpIp_SockIdxType SockIdx, uint8 Value)
{
  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT,                      IPV4_IP_API_ID_SET_ETHIF_FRAME_PRIO, IPV4_E_NOT_INITIALIZED, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_IP_COND_VALID_SOCKIDX(SockIdx), IPV4_IP_API_ID_SET_ETHIF_FRAME_PRIO, IPV4_E_INV_SOCK_IDX,    E_NOT_OK )
  /* ------------------------------------------------- */

  if (Value > IPV4_IP_MAX_ETHIF_FRAME_PRIO)
  {
    return E_NOT_OK;
  }

  IpV4_Ip_TransferBlock[SockIdx].EthIfFramePrio = Value;
  IpV4_Ip_TransferBlock[SockIdx].Flags |= IPV4_IP_TRANSFER_BLOCK_FLAG_ETHIF_FRAME_PRIO;
  return E_OK;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Ip_AddrConflictInd
 **********************************************************************************************************************/
/*! \brief        Indicate an address conflict in the ARP.
 *  \description  <br>This function is used for IP LL address configuration.
 *  \param[in]    AddrId             ip address identifier
 *  \return       void
 *  \note
 *  \context      task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_AddrConflictInd(
    IpV4_AddrIdType AddrId )
{
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
#endif

  /* ------------------------------------------------- */
  /* DET */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT, IPV4_IP_API_ID_ADDR_CONFL_IND, IPV4_E_NOT_INITIALIZED )
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_VALID_IPADDRID(AddrId), IPV4_IP_API_ID_ADDR_CONFL_IND, IPV4_E_INV_CTRL_IDX )
  /* ------------------------------------------------- */

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  IPV4_GET_CTRL_IDX_FROM_ADDR_ID(IpCtrlIdx,   AddrId);
#endif

  IPV4_ASSERT(IPV4_CTRL_ADDR_IDX_IS_UNICAST(IPV4_ADDR_ID_2_ADDR_IDX(AddrId)));

  if (IpV4_Ip_VCfgIsAddrAssignmentEnabled(IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL))
  {
    /* check address conflict timeout */
    if(0 != IPV4_CTRL_LL_VAR(AddrConflictTimeout))
    {
      /* This is not the first conflict, so release current local IP address assignment. */

      IPV4_CTRL_LL_VAR(State) = IPV4_IP_LL_STATE_CONFLICT;
      IpV4_Ip_VIpAddrAssignmentReadyNotification(IPV4_IPCTRLIDX, IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL, FALSE);
    }
    else
    {
      IPV4_CTRL_LL_VAR(AddrConflictTimeout) = IpV4_Ip_VCfgGetDefendIntervalMsec() / IpV4_VCfgGetMainFctPeriodMsec();

      /* send ARP announcement */
      (void)IpV4_Arp_SendArpAnnouncement(IPV4_IPCTRLIDX, IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr);
    }
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif  /* IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON */

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Ip_LlAddrInUse
 **********************************************************************************************************************/
/*! \brief      This function handles address conflicts
 *  \param[in]  IpCtrlIdx             ip controller index
 *  \param[in]  IpAddr                ip address that seems to be in use by other host
 *  \context    task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_LlAddrInUse(
    uint8 IpCtrlIdx,
    IpBase_AddrInType IpAddr)
{
  if (IpV4_Ip_VCfgIsAddrAssignmentEnabled(IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL))
  {
    if(IPV4_IP_LL_STATE_PROBE == IPV4_CTRL_LL_VAR(State))
    {
      if ((0 != IpAddr) && (IPV4_CTRL_LL_VAR(NetAddrCand) == IpAddr))
      {
        IPV4_CTRL_LL_VAR(AddrConflict) = 1;
      }
    }
  }
}
#endif  /* IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON */

#if defined(TCPIP_INV_DEM_EVENT_ID)
# if (TcpIp_NumIpV4CtrlsOfDemEventTCPIP_E_DUPLICATE_DHCP_ADDR > 0)
/***********************************************************************************************************************
 *  IpV4_GetLastDuplicateDhcpAddrDid
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, IPV4_CODE) IpV4_GetLastDuplicateDhcpAddrDid(
    uint8                                                         IpCtrlIdx,
    CONSTP2VAR(IpBase_AddrInType, AUTOMATIC, IPV4_APPL_DATA)      IpAddrPtr,
    CONSTP2VAR(IpBase_EthPhysAddrType, AUTOMATIC, IPV4_APPL_DATA) PhysAddrPtr
    )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = TCPIP_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (IPV4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if(!IPV4_COND_INIT)
  {
    errorId = IPV4_E_NOT_INITIALIZED;
  }
  /* Check parameter 'IpAddrPtr' */
  else if(IpAddrPtr == NULL_PTR)
  {
    errorId = IPV4_E_INV_POINTER;
  }
  /* Check parameter 'PhysAddrPtr' */
  else if(PhysAddrPtr == NULL_PTR)
  {
    errorId = IPV4_E_INV_POINTER;
  }
  /* Check parameter 'IpCtrlIdx' */
  else if(IpCtrlIdx >= TcpIp_NumIpV4CtrlsOfDemEventTCPIP_E_DUPLICATE_DHCP_ADDR)
  {
    errorId = IPV4_E_INV_PARAM;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 In case all parameters are valid assign the last duplicate DHCP address DID to the C-structs given as out-parameters */
    IpV4_VAssignPhysAddr((uint8 *)(PhysAddrPtr), TcpIp_LastDuplicateDhcpNetAddr[IpCtrlIdx].PhysAddr);  /* PRQA S 0310 */ /* MD_IpV4_11.04 */
    *IpAddrPtr = TcpIp_LastDuplicateDhcpNetAddr[IpCtrlIdx].NetAddr;
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (IPV4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != TCPIP_E_NO_ERROR)
  {
    (void)Det_ReportError(IPV4_MODULE_ID, IPV4_VINSTANCE_ID, IPV4_IP_API_ID_GET_LAST_DUPLICATE_DHCP_ADDR_DID, errorId);
  }
#else
  TCPIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */ /* SBSW_IpV4_56 */
#endif

  return retVal;
}
# endif
#endif

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
# if (IPV4_ENABLE_ETHIF_ADDR_FILTER_API == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Ip_VJoinMulticastGroup
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VJoinMulticastGroup(uint8 IpCtrlIdx, IpBase_AddrInType MulticastAddr, boolean Join)
{
  Eth_PhysAddrType     PhysMulticastAddr;
  Eth_FilterActionType EthFilterAction = (Eth_FilterActionType)((TRUE == Join) ? ETH_ADD_TO_FILTER : ETH_REMOVE_FROM_FILTER);

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  IPV4_UNUSED_PARAMETER(IpCtrlIdx);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  
#endif

  if (IPV4_ADDR_IS_MULTICAST(MulticastAddr))
  {
    /* configure physical address filter */
    IpV4_Arp_MapIpToPhysMulticastAddr(MulticastAddr, &PhysMulticastAddr[0]);

    if (E_OK != TCPIP_LL_UpdatePhysAddrFilter(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), &PhysMulticastAddr[0], EthFilterAction))
    {
      IpV4_ReportDetError(IPV4_IP_API_ID_V_INTERNAL_FUNCTION, IPV4_E_INV_PARAM);
    }
  }
} /* End of IpV4_Ip_VJoinMulticastGroup() */
# endif

/***********************************************************************************************************************
 *  IpV4_Ip_VUpdateMulticastMemberships
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VUpdateMulticastMemberships(uint8 IpCtrlIdx, boolean Join)
{
  /* initialize configured multicast address assignments */
  uint8 MulticastAddrIdx = IpV4_Ip_VCfgGetMulticastAddrCount();

  while (0 < MulticastAddrIdx)
  {
    MulticastAddrIdx--;

    if (IPV4_ADDR_ANY != IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[MulticastAddrIdx])
    {
      TcpIp_IpAddrStateType AddrState = (TcpIp_IpAddrStateType)((TRUE == Join) ? TCPIP_IPADDR_STATE_ASSIGNED : TCPIP_IPADDR_STATE_UNASSIGNED);

# if (IPV4_ENABLE_ETHIF_ADDR_FILTER_API == STD_ON)
      if (!IpV4_Ip_VCfgIsReceiveAllMulticastsEnabled())
      {
        /* configure individual physical address filter */
        IpV4_Ip_VJoinMulticastGroup(IpCtrlIdx, IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[MulticastAddrIdx], Join);
      }
# endif

      IpV4_VLocalIpAddrAssignmentChange(IpCtrlIdx, IPV4_CTRL_MULTICAST_ADDR_IDX_2_ADDR_IDX(MulticastAddrIdx), AddrState);
    }
  }

# if (IPV4_ENABLE_ETHIF_ADDR_FILTER_API == STD_ON)
  if (IpV4_Ip_VCfgIsReceiveAllMulticastsEnabled())
  {
    const Eth_PhysAddrType PhysBroadcastAddr  = { 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU };
    Eth_FilterActionType EthFilterAction = (Eth_FilterActionType)((TRUE == Join) ? ETH_ADD_TO_FILTER : ETH_REMOVE_FROM_FILTER);

    /* Enable the promiscous mode to receive multicast messages */
    if (E_OK != TCPIP_LL_UpdatePhysAddrFilter(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), &PhysBroadcastAddr[0], EthFilterAction))
    {
      IpV4_ReportDetError(IPV4_IP_API_ID_V_INTERNAL_FUNCTION, IPV4_E_INV_PARAM);
    }
  }
# endif
} /* End of IpV4_Ip_VUpdateMulticastMemberships() */
#endif

/***********************************************************************************************************************
 *  IpV4_Ip_VIpAddrAssignmentReadyNotification()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Ip_VIpAddrAssignmentReadyNotification(
  uint8   IpCtrlIdx, 
  uint8   addrAssignmentMethod,
  boolean addrAssigned)
{
#if (IPV4_IP_ENABLE_ADDR_NVM_STORAGE == STD_ON)
  uint8 addrAssignmentPrio = IpV4_Ip_VCfgGetAddrAssignmentPrio(addrAssignmentMethod);
  uint8 addrAssignmentCfg  = IpV4_Ip_VCfgGetAddrAssignmentCfgByPrio(addrAssignmentPrio);

  /* #10 Check if address of specified assignment method shall be stored into NvM. */

  IPV4_ASSERT(addrAssignmentMethod != IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE);
  IPV4_ASSERT(IPV4_CHK_BIT_U8(IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentTriggeredFlags), addrAssignmentMethod) == TRUE);

  if ((addrAssigned == TRUE) && (IPV4_CHK_FLAG_U8(addrAssignmentCfg, IPV4_IP_ADDR_ASSIGNMENT_FLAG_LIFETIME_STORE) == TRUE))
  {
    IPV4_ASSERT(IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentMethodPersist) == IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE);

    /* #20 Set 'persist' flag, so address will be written into NvM in MainFunction. */
    IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentMethodPersist) = addrAssignmentMethod;
  }
#else
  IPV4_UNUSED_PARAMETER(IpCtrlIdx);            /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  IPV4_UNUSED_PARAMETER(addrAssignmentMethod); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  IPV4_UNUSED_PARAMETER(addrAssigned);         /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentReadyChanged) = TRUE;
} /* IpV4_Ip_VIpAddrAssignmentReadyNotification() */

/***********************************************************************************************************************
 *  IpV4_Ip_VGetBestAvailableAddrAssignment
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(uint8, IPV4_CODE) IpV4_Ip_VGetBestAvailableAddrAssignment(
  uint8                         IpCtrlIdx, 
  IPV4_P2V(uint8)               addrAssignmentPriorityPtr,
  IPV4_P2V(IpV4_IpAddrSetType)  addrInfoPtr)
{
  uint8_least addrAssignmentPrio;
  boolean     addrAssignmentReady  = FALSE;
  uint8       addrAssignmentMethod = IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE;

  if (IPV4_COND_VALID_CTRLIDX(IpCtrlIdx))
  {
    /* #10 Iterate over configured address assignments for current controller (ordered by high to low priority). */
    for (addrAssignmentPrio = IPV4_IP_ADDR_ASSIGNMENT_PRIO_HIGHEST; addrAssignmentPrio <= IPV4_IP_ADDR_ASSIGNMENT_PRIO_LOWEST; addrAssignmentPrio++)
    {
      uint8 addrAssignmentCfg = IpV4_Ip_VCfgGetAddrAssignmentCfgByPrio(addrAssignmentPrio);
      addrAssignmentMethod    = IpV4_Ip_VCfgGetAddrAssignmentMethodByCfg(addrAssignmentCfg);

      if (addrAssignmentMethod == IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE)
      {
        /* No more address assignments configured. */
        break;
      }

      /* #20 Check if address assignment is active. */
      if (IPV4_CHK_BIT_U8(IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentTriggeredFlags), addrAssignmentMethod) == TRUE)
      {
#if (IPV4_IP_ENABLE_ADDR_NVM_STORAGE == STD_ON)
        /* #30 Check if an address is stored into NvM for this assignment method. Is so, use it. */
        if (IPV4_CHK_FLAG_U8(addrAssignmentCfg, IPV4_IP_ADDR_ASSIGNMENT_FLAG_LIFETIME_STORE) == TRUE)
        {
          IPV4_ASSERT(IpV4_Ip_VCfgGetNvmAddrVar() != NULL_PTR);
       
          if ((IpV4_Ip_VCfgGetNvmAddrVar()->NetAddr != IPV4_ADDR_ANY) && 
              (IpV4_Ip_VCfgGetNvmAddrVar()->NetMask  > 0))
          {
            /* Use address stored in NvM. */
            addrAssignmentReady = TRUE;
            *addrInfoPtr = *IpV4_Ip_VCfgGetNvmAddrVar();
          }
        }

        if (addrAssignmentReady == FALSE)
#endif
        {
          addrAssignmentReady = IpV4_Ip_VGetActiveAddressOfAssignmentMethod(IpCtrlIdx, addrAssignmentMethod, addrInfoPtr);
        }

        if (addrAssignmentReady == TRUE)
        {
          break; /* PRQA S 0771 */ /* MD_IPV4_0771 */
        }
      }
    }

    /* #40 Store priority of best available address assignment method at addrAssignmentPriorityPtr (if there is one). */
    if (addrAssignmentReady == TRUE) 
    {
      *addrAssignmentPriorityPtr = (uint8)addrAssignmentPrio;
    }
    else
    {
      addrAssignmentMethod = IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE;
    }
  }
  else
  {
    IPV4_ASSERT_UNREACHABLE();
  }

  return addrAssignmentMethod;
} /* IpV4_Ip_VGetBestAvailableAddrAssignment() */ /* PRQA S 6010, 6030, 6080  */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  IpV4_Ip_VGetActiveAddressOfAssignmentMethod()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(boolean, IPV4_CODE) IpV4_Ip_VGetActiveAddressOfAssignmentMethod(
  uint8                        IpCtrlIdx, 
  uint8                        addrAssignmentMethod,
  IPV4_P2V(IpV4_IpAddrSetType) addrInfoPtr)
{
  boolean retVal = FALSE;

  IPV4_UNUSED_IPCTRLIDX();  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  /* #10 Check if specified address assignment method has a valid address and store value in addrInfoPtr. */
  switch (addrAssignmentMethod)
  {
#if (IPV4_IP_DHCP_ADDR_CFG_SUPP == STD_ON)
  case IPV4_IP_ADDR_ASSIGNMENT_METHOD_DHCP:
    retVal = TcpIp_DhcpV4_GetActiveAddress(IpCtrlIdx, addrInfoPtr);
    break;
#endif

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
  case IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL:
    if ((IPV4_CTRL_LL_VAR(State) == IPV4_IP_LL_STATE_ANNOUNCE) ||
        (IPV4_CTRL_LL_VAR(State) == IPV4_IP_LL_STATE_READY))
    {
      addrInfoPtr->NetAddr   = IPV4_CTRL_LL_VAR(AddrFound);
      addrInfoPtr->NetMask   = IPV4_IP_LL_NET_ADDR_MASK;
      addrInfoPtr->DefGwAddr = TCPIP_INADDR_BROADCAST;
      retVal = TRUE;
    }
    break;
#endif

  case IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC:
    if (IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Requested)->NetAddr != IPV4_ADDR_ANY)
    {
      (*addrInfoPtr) = *IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Requested);
      retVal = TRUE;
    }
    break;

  default:
    IPV4_ASSERT_UNREACHABLE();
    break;
  }

  return retVal;
} /* IpV4_Ip_VGetActiveAddressOfAssignmentMethod() */

/***********************************************************************************************************************
 *  IpV4_Ip_VTriggerAddrAssignment
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) IpV4_Ip_VTriggerAddrAssignment(
    uint8   IpCtrlIdx,
    uint8   addrAssignmentCfg,
    boolean triggerValue)
{
  boolean retVal = E_NOT_OK;
  uint8 addrAssignmentMethod = IpV4_Ip_VCfgGetAddrAssignmentMethodByCfg(addrAssignmentCfg);

  IPV4_UNUSED_IPCTRLIDX();  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  

  IPV4_ASSERT((addrAssignmentMethod == IPV4_IP_ADDR_ASSIGNMENT_METHOD_DHCP) ||
              (addrAssignmentMethod == IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL) ||
              (addrAssignmentMethod == IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC));

  /* #10 Check if trigger value differs from current value. */
  if (triggerValue == TRUE)
  {
    if (IPV4_CHK_BIT_U8(IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentTriggeredFlags), addrAssignmentMethod))
    {
      /* Trigger already set. */
    }
    else
    {
      IPV4_SET_BIT_U8(IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentTriggeredFlags), addrAssignmentMethod);

      {
        /* #20 Do not trigger dynamic address assignment (DHCP, LINKLOCAL) if an address of this method was stored in the NvM before. */
#if (IPV4_IP_ENABLE_ADDR_NVM_STORAGE == STD_ON)
        boolean triggerAssignment = TRUE;

        if (IPV4_CHK_FLAG_U8(addrAssignmentCfg, IPV4_IP_ADDR_ASSIGNMENT_FLAG_LIFETIME_STORE) == TRUE)
        {
          IPV4_ASSERT(IpV4_Ip_VCfgGetNvmAddrVar() != NULL_PTR);

          if (IpV4_Ip_VCfgGetNvmAddrVar()->NetAddr != IPV4_ADDR_ANY)
          {
            /* There is an address stored in the NvM. Avoid that dynamic address assignment is started below. */ 
            triggerAssignment = FALSE;
          }
        }

        /* #30 Otherwise start dynamic address assignment method (in case of DHCP or LINKLOCAL). */
        if (triggerAssignment == TRUE)
#endif
        {
          switch (addrAssignmentMethod)
          {
#if (IPV4_IP_DHCP_ADDR_CFG_SUPP == STD_ON)
          case IPV4_IP_ADDR_ASSIGNMENT_METHOD_DHCP:
            TcpIp_DhcpV4_TriggerAddrRequest(IpCtrlIdx, 0);
            retVal = E_OK;
            break;
#endif

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
          case IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL:
            IpV4_Ip_VLl_Start(IpCtrlIdx);
            retVal = E_OK;
            break;
#endif

          case IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC:
            retVal = E_OK;
            break;

          default:
            /* No action required. */
            IPV4_ASSERT_UNREACHABLE();
            break;
          }
        }
      }
    }
  }
  else
  {
    if (IPV4_CHK_BIT_U8(IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentTriggeredFlags), addrAssignmentMethod))
    {
      IPV4_CLR_BIT_U8(IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentTriggeredFlags), addrAssignmentMethod);

      /* #40 Stop dynamic address assignment method (in case of DHCP or LINKLOCAL). */
      switch (addrAssignmentMethod)
      {
#if (IPV4_IP_DHCP_ADDR_CFG_SUPP == STD_ON)
      case IPV4_IP_ADDR_ASSIGNMENT_METHOD_DHCP:
        TcpIp_DhcpV4_StopAddrRequest(IpCtrlIdx);
        retVal = E_OK;
        break;
#endif

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
      case IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL:
        IpV4_Ip_VLl_Reset(IpCtrlIdx);
        retVal = E_OK;
        break;
#endif

      case IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC:
        retVal = E_OK;
        break;

      default:
        /* No action required. */
        IPV4_ASSERT_UNREACHABLE();
          break;
      }
    }
    else
    {
      /* Trigger already unset. */
    }
  }

  return retVal;
} /* IpV4_Ip_VTriggerAddrAssignment() */ /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  IpV4_Ip_VTriggerAutomaticAddrAssignments()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VTriggerAutomaticAddrAssignments(uint8 IpCtrlIdx)
{
  uint8_least addrAssignmentPrio;

  /* #10 Iterate over all configured address assignment methods for the IP instance. */
  for (addrAssignmentPrio = IPV4_IP_ADDR_ASSIGNMENT_PRIO_HIGHEST; addrAssignmentPrio <= IPV4_IP_ADDR_ASSIGNMENT_PRIO_LOWEST; addrAssignmentPrio++)
  {
    uint8 addrAssignmentCfg     = IpV4_Ip_VCfgGetAddrAssignmentCfgByPrio(addrAssignmentPrio);
    uint8 addrAssignmentMethod  = IpV4_Ip_VCfgGetAddrAssignmentMethodByCfg(addrAssignmentCfg);

    /* #20 If assignment method trigger is configured to AUTOMATIC set trigger flag. */
    if ((addrAssignmentMethod != IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE) && ((addrAssignmentCfg & IPV4_IP_ADDR_ASSIGNMENT_FLAG_AUTO_TRIGGER) != 0))
    {
      if (IpV4_Ip_VTriggerAddrAssignment(IpCtrlIdx, addrAssignmentCfg, TRUE) == E_NOT_OK)
      {
        IPV4_ASSERT_UNREACHABLE_MSG("Address assignment method should always be triggerable here.");
      }

      /* #30 If assignment method is STATIC set active address of assignment to configured default address (if there is one). */
      if (addrAssignmentMethod == IPV4_IP_ADDR_ASSIGNMENT_METHOD_STATIC)
      {
        IPV4_ASSERT(IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Default) != NULL_PTR);

        *IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Requested) = *IPV4_CTRL_VAR(IpV4_Ip_StaticAddr_Default);
      }
    }
  }
}

/**********************************************************************************************************************
 *  IpV4_Ip_VSetCtrlStateOffline()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VSetCtrlStateOffline(uint8 IpCtrlIdx)
{
  /* #10 If IP instance is in state ONLINE_ACTIVE move to ONLINE_PASSIVE first. */
  if (IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_ONLINE_ACTIVE)
  {
    IpV4_Ip_VSetCtrlStateOnlinePassive(IpCtrlIdx);
  }

  if (IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_ONLINE_PASSIVE)
  {

    /* #20 If IP instance is in state ONLINE_PASSIVE stop all dynamic address assignments. */
    (void)IpV4_Ip_VTriggerAddrAssignment(IpCtrlIdx, IPV4_IP_ADDR_ASSIGNMENT_METHOD_DHCP, FALSE);
    (void)IpV4_Ip_VTriggerAddrAssignment(IpCtrlIdx, IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL, FALSE);   

    /* #30 Clear address assignment trigger flags for all address assignment methods of the IP instance. */
    IPV4_CTRL_VAR(IpV4_Ip_AddrAssignmentTriggeredFlags) = 0;

    /* #40 Reset ARP submodule. */
#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
    IpV4_Arp_Reset(IPV4_IPCTRLIDX);
#endif

    /* #50 Reset all multicast addresses to default values. */
#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
    {
      uint8_least mcAddrIdx;
      
      for (mcAddrIdx = 0; mcAddrIdx < IpV4_Ip_VCfgGetMulticastAddrCount(); mcAddrIdx++)
      {
        IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[mcAddrIdx] = IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs_Default)[mcAddrIdx];
      }
    }
#endif

    /* #60 Set state to OFFLINE. */
    IPV4_CTRL_VAR(IpV4_Ip_CtrlState) = IPV4_IP_OFFLINE;
  }
  else
  {
    /* Invalid state transition. */
    IPV4_ASSERT_UNREACHABLE();
  }
}

/**********************************************************************************************************************
 *  IpV4_Ip_VSetCtrlStateOnlinePassive()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VSetCtrlStateOnlinePassive(uint8 IpCtrlIdx)
{
  /* #10 If IP instance is in state ONLINE_ACTIVE: */
  if (IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_ONLINE_ACTIVE)
  {

#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
    /* #20 Leave all multicast groups (if reception of multicast packets is configured.) */
    if ((0 < IpV4_Ip_VCfgGetMulticastAddrCount()) || (IpV4_Ip_VCfgIsReceiveAllMulticastsEnabled()))
    {
      /* update physical address filters */
      IpV4_Ip_VUpdateMulticastMemberships(IpCtrlIdx, FALSE);
    }
#endif

    /* #30 Unassign broadcast address. */
    if (IPV4_ADDR_ID_INV != IPV4_CTRL_VAR(IpV4_Ip_BcAddrId))
    {
      IpV4_VLocalIpAddrAssignmentChange(IpCtrlIdx, IPV4_CTRL_ADDR_IDX_ANY, TCPIP_IPADDR_STATE_UNASSIGNED);
    }

    IPV4_ASSERT(IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) != IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE);

    /* #40 Unassign unicast address. */
    IpV4_VLocalIpAddrAssignmentChange(IpCtrlIdx, IPV4_CTRL_ADDR_IDX_FIRST, TCPIP_IPADDR_STATE_UNASSIGNED);

    /* #50 Set IP instance state to PASSIVE and active assignment method to NONE. */
    IPV4_CTRL_VAR(IpV4_Ip_CtrlState)                  = IPV4_IP_ONLINE_PASSIVE;
    IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr         = IPV4_ADDR_ANY;
    IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetMask         = 0;
    IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).DefGwAddr       = IPV4_ADDR_ANY;
    IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) = IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE;

    /* #60 Notify TcpIp/EthSM. */
    ETHSM_TCPIP_MODE_INDICATION(IpV4_CtrlIdxIp2EthIf[IpCtrlIdx], FALSE);
  }
  /* #70 If IP instance is in state OFFLINE: */
  else if (IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_OFFLINE)
  {

    IPV4_ASSERT(IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) == IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE);

    /* #80 Trigger all configured address assignments with trigger AUTOMATIC. */
    IpV4_Ip_VTriggerAutomaticAddrAssignments(IpCtrlIdx);

    /* #90 Set IP instance state to ONLINE_PASSIVE. */
    IPV4_CTRL_VAR(IpV4_Ip_CtrlState) = IPV4_IP_ONLINE_PASSIVE;
  }
  else
  {
    /* ERROR: Invalid state transition. */
    IPV4_ASSERT_UNREACHABLE();
  }
} /* End of IpV4_Ip_VChangeCtrlState() */

/**********************************************************************************************************************
 *  IpV4_Ip_VSetCtrlStateOnlineActive()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VSetCtrlStateOnlineActive(uint8 IpCtrlIdx)
{
  /* #10 If IP instance is in state ONLINE_PASSIVE. */
  if (IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_ONLINE_PASSIVE)
  {

    /* #20 Set IP instance state to ONLINE_ACTIVE. */
    IPV4_CTRL_VAR(IpV4_Ip_CtrlState) = IPV4_IP_ONLINE_ACTIVE;

    IPV4_ASSERT(IPV4_CTRL_VAR(IpV4_Ip_ActiveAddrAssignmentMethod) != IPV4_IP_ADDR_ASSIGNMENT_METHOD_NONE);

    /* #30 Notify upper layer about available unicast address. */
    IpV4_VLocalIpAddrAssignmentChange(IpCtrlIdx, IPV4_CTRL_ADDR_IDX_FIRST, TCPIP_IPADDR_STATE_ASSIGNED);

    /* #40 Notify upper layer about available broadcast address. */
    if (IPV4_ADDR_ID_INV != IPV4_CTRL_VAR(IpV4_Ip_BcAddrId))
    {
      IpV4_VLocalIpAddrAssignmentChange(IpCtrlIdx, IPV4_CTRL_ADDR_IDX_ANY, TCPIP_IPADDR_STATE_ASSIGNED);
    }

#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
    /* #50 Join multicast groups. (if reception of multicast packets is configured.) */
    if ((0 < IpV4_Ip_VCfgGetMulticastAddrCount()) || (IpV4_Ip_VCfgIsReceiveAllMulticastsEnabled()))
    {
      /* update physical address filters */
      IpV4_Ip_VUpdateMulticastMemberships(IpCtrlIdx, TRUE);
    }
#endif

    /* #60 Notify TcpIp/EthSM. */
    ETHSM_TCPIP_MODE_INDICATION(IpV4_CtrlIdxIp2EthIf[IpCtrlIdx], TRUE);
  }
  else
  {
    /* ERROR: Invalid state transition. */
    IPV4_ASSERT_UNREACHABLE();
  }
}

/***********************************************************************************************************************
 *  IpV4_VLocalIpAddrAssignmentChange()
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_VLocalIpAddrAssignmentChange(
    uint8                 IpCtrlIdx,
    uint8                 CtrlAddrIdx,
    TcpIp_IpAddrStateType State)
{
  IpV4_AddrIdType       TmpIpAddrId;

  IPV4_UNUSED_IPCTRLIDX();  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */

  if (IPV4_CTRL_ADDR_IDX_ANY != CtrlAddrIdx)
  {
    TmpIpAddrId    = IPV4_CTRL_VAR(IpV4_Ip_AddrConfig)[CtrlAddrIdx].IpAddrId;
  }
  else
  {
    TmpIpAddrId    = IPV4_CTRL_VAR(IpV4_Ip_BcAddrId);
  }

#if (IPV4_SUPPORT_ICMP  == STD_ON)
  IpV4_Icmp_VLocalIpAddrAssignmentChange(TmpIpAddrId, State);
#endif
  TcpIp_Cbk_VLocalIpAssignmentChg(IPV4_ADDR_ID_2_TCPIP_LOCAL_ADDR_ID(TmpIpAddrId), State);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if (IPV4_IP_ENABLE_MULTICAST_RX == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Ip_VChangeMulticastAddrAssignment
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, TCPIP_CODE) IpV4_Ip_VChangeMulticastAddrAssignment(
    uint8             IpCtrlIdx,
    uint8             mcAddrIdx,
    IpBase_AddrInType addrValue)
{
  Std_ReturnType  retVal = E_NOT_OK;

  IPV4_ASSERT(mcAddrIdx < IpV4_Ip_VCfgGetMulticastAddrCount());

  /* #10 Check if address value differs from current value. */
  if (IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[mcAddrIdx] != addrValue)
  {
    /* #20 Check if address value is a valid multicast address or ANY (in order remove address assignment). */
    if (IPV4_ADDR_IS_MULTICAST(addrValue) || IPV4_ADDR_IS_BROADCAST(addrValue) || (addrValue == IPV4_ADDR_ANY))
    {
      /* #30 Leave multicast group if an address is currently assigned. */
      if (IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[mcAddrIdx] != IPV4_ADDR_ANY)
      {
# if (IPV4_ENABLE_ETHIF_ADDR_FILTER_API == STD_ON)
        /* leave current multicast group */
        IpV4_Ip_VJoinMulticastGroup(IpCtrlIdx, IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[mcAddrIdx], FALSE);
# endif

        IpV4_VLocalIpAddrAssignmentChange(IpCtrlIdx, IPV4_CTRL_MULTICAST_ADDR_IDX_2_ADDR_IDX(mcAddrIdx), TCPIP_IPADDR_STATE_UNASSIGNED);
      }

      /* #40 Update address value. */
      if (addrValue != IPV4_ADDR_ANY)
      {
        /* update multicast address assignment */
        IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[mcAddrIdx] = addrValue;
      }
      else
      {
        /* set configured default address value. */
        IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[mcAddrIdx] = IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs_Default)[mcAddrIdx];
      }

      /* #50 Join multicast group if a new address was assigned. */
      if (IPV4_ADDR_ANY != IPV4_CTRL_VAR(IpV4_Ip_MulticastAddrs)[mcAddrIdx])
      {
# if (IPV4_ENABLE_ETHIF_ADDR_FILTER_API == STD_ON)
        /* join new multicast group */
        IpV4_Ip_VJoinMulticastGroup(IpCtrlIdx, addrValue, TRUE);
# endif

        IpV4_VLocalIpAddrAssignmentChange(IpCtrlIdx, IPV4_CTRL_MULTICAST_ADDR_IDX_2_ADDR_IDX(mcAddrIdx), TCPIP_IPADDR_STATE_ASSIGNED);
      }

      retVal = E_OK;
    }
    else
    {
      /* address is not a valid multicast or broadcast */
    }
  }

  return retVal;
} /* IpV4_Ip_VChangeMulticastAddrAssignment() */
#endif

#if defined TCPIP_INV_DEM_EVENT_ID
/***********************************************************************************************************************
 *  IpV4_ResetDemEventAllIpCtrl
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_ResetDemEventAllIpCtrl(
  CONSTP2CONST(PduIdType, AUTOMATIC, IPV4_CONST) DemEventSnvsByIpV4Ctrl,
  uint8 NumIpV4CtrlsOfDemEvent
)
{
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
  for(IpCtrlIdx = 0; IpCtrlIdx < NumIpV4CtrlsOfDemEvent; IpCtrlIdx++)
  {
    if(DemEventSnvsByIpV4Ctrl[IpCtrlIdx] != TCPIP_INV_DEM_EVENT_ID)
    {
      Dem_ReportErrorStatus(DemEventSnvsByIpV4Ctrl[IpCtrlIdx], DEM_EVENT_STATUS_PREPASSED);
    }
  }
}

/***********************************************************************************************************************
 *  IpV4_ResetDemEventIpCtrl
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_ResetDemEventIpCtrl(
  CONSTP2CONST(PduIdType, AUTOMATIC, IPV4_CONST) DemEventSnvsByIpV4Ctrl,
  uint8 NumIpV4CtrlsOfDemEvent,
  uint8 IpCtrlIdx
)
{
  if(    (IpCtrlIdx < NumIpV4CtrlsOfDemEvent)
      && (DemEventSnvsByIpV4Ctrl[IpCtrlIdx] != TCPIP_INV_DEM_EVENT_ID)
    )
  {
    Dem_ReportErrorStatus(DemEventSnvsByIpV4Ctrl[IpCtrlIdx], DEM_EVENT_STATUS_PREPASSED);
  }
}
#endif

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Ip_VLl_GenerateIpAddr
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(IpBase_AddrInType, TCPIP_CODE) IpV4_Ip_VLl_GenerateIpAddr(uint8 IpCtrlIdx, uint8 conflictCount)
{
  IpV4_AddrIdType ipAddrId = IPV4_CTRL_VAR(IpV4_Ip_AddrConfig)[IPV4_CTRL_ADDR_IDX_FIRST].IpAddrId;
  IpV4_LinkLocalAddrCalloutFuncType addrCalloutFunc = IpV4_Ip_VCfgGetLinkLocalAddrCalloutFunc();

  /* #10 Initialize IP address value to 0.0.0.0 */
  IpBase_AddrInType ipAddr = IPV4_ADDR_ANY;

  /* #20 If configured, call user callout function for IP address generation. */
  if (addrCalloutFunc != NULL_PTR)
  {
    addrCalloutFunc(IPV4_ADDR_ID_2_TCPIP_LOCAL_ADDR_ID(ipAddrId), conflictCount, &ipAddr);
  }

  /* #30 If callout does not specify IP address, generate random address in link-local subnet (169.254.1.0). */
  if (ipAddr == IPV4_ADDR_ANY)
  {
    ipAddr = IPV4_IP_LL_NET_ADDR_START_NBO + (TcpIp_GetRandNoFct() % IPV4_IP_LL_NET_ADDR_COUNT);
  }

  return IPV4_NTOHL(ipAddr);
} /* IpV4_Ip_VLl_GenerateIpAddr */

/***********************************************************************************************************************
 *  IpV4_Ip_VLl_Reset
 **********************************************************************************************************************/
/*! \brief      This function resets variables for the dynamic IP address asignment
 *  \param[in]  IpCtrlIdx             controller index
 *  \context    task level
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VLl_Reset(
    uint8 IpCtrlIdx )
{
  IPV4_CTRL_LL_VAR(AddrConflictTimeout) = 0;
  IPV4_CTRL_LL_VAR(AddrFound)           = 0;
  IPV4_CTRL_LL_VAR(NetAddrCand)         = 0;
  IPV4_CTRL_LL_VAR(MsecCnt)             = 0;
  IPV4_CTRL_LL_VAR(ProbeNumSinceConf)   = 0;
  IPV4_CTRL_LL_VAR(AnnounceNum)         = 0;
  IPV4_CTRL_LL_VAR(ConflictsNum)        = 0;
  IPV4_CTRL_LL_VAR(State)               = IPV4_IP_LL_STATE_INACTIVE;
  IPV4_CTRL_LL_VAR(ProbeState)          = IPV4_IP_LL_PROBE_STATE_CHOOSE;
  IPV4_CTRL_LL_VAR(AnnState)            = IPV4_IP_LL_ANN_STATE_PROBE;

  IPV4_CTRL_LL_VAR(WaitUntilTime)       = 0;
  IPV4_CTRL_LL_VAR(AddrConflict)        = 0;
}

/***********************************************************************************************************************
 *  IpV4_Ip_VLl_Start
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VLl_Start(
    uint8 IpCtrlIdx )
{
  /* #10 Start LINKLOCAL address assignment if not alerady started. */
  if (IPV4_CTRL_LL_VAR(State) == IPV4_IP_LL_STATE_INACTIVE)
  {
    IPV4_CTRL_LL_VAR(State) = IPV4_IP_LL_STATE_INIT;
  }
  else
  {
    IPV4_ASSERT_UNREACHABLE();
  }
}

/***********************************************************************************************************************
 *  IpV4_Ip_VLl_Main
 **********************************************************************************************************************/
/*! \brief      This function processes handling of LinkLocal address
 *  \param[in]  IpCtrlIdx             controller index
 *  \context    task level
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VLl_Main(
    uint8 IpCtrlIdx )
{
  if (IPV4_CTRL_LL_VAR(State) != IPV4_IP_LL_STATE_INACTIVE)
  {
    if(0 != IPV4_CTRL_LL_VAR(AddrConflictTimeout))
    {
      /* decrease address conflict timeout */
      IPV4_CTRL_LL_VAR(AddrConflictTimeout)--;
    }

    /* No address has been configured or there are pending announcements for a link-local address */
    IpV4_Ip_VLl_FindAddr(IpCtrlIdx);
  }
  else
  {
  }

}

/***********************************************************************************************************************
 *  IpV4_Ip_VLl_FindAddr
 **********************************************************************************************************************/
/*! \brief      This function tries to get a LinkLocal address
 *  \param[in]  IpCtrlIdx             controller index
 *  \context    task level
 **********************************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VLl_FindAddr(
    uint8 IpCtrlIdx )
{

  /*
     This function is only called under the following conditions:
     - assert( Ip_GlobalState == IP_INIT )
     - assert( Ip_RAM_ActiveStatus(CtrlIdx).CtrlState == IP_ONLINE_ADDR_REQUESTED )

     while(no addr found)
       choose random IP addr
       send ARP request to check if Addr is already in use
       poll ARP for a while (x seconds)
         if(not in use) -> take this addr -> break
         else -> increment counter
     if(no valid (free) add after y seconds) -> timeout -> error?
  */
  switch (IPV4_CTRL_LL_VAR(State))
  {
  case IPV4_IP_LL_STATE_INIT:
    {
      uint16 RandNo = TcpIp_VIpGetRandNoFct();

      IPV4_CTRL_LL_VAR(WaitUntilTime) = IPV4_CTRL_LL_VAR(MsecCnt) + IpV4_Ip_VCfgGetProbeWaitMinMsec();
      /* choose random time between "IPV4_IP_PROBE_WAIT_MIN_MS" and "IPV4_IP_PROBE_WAIT_MAX_MS" */
      if (IpV4_Ip_VCfgGetProbeWaitMaxMsec() > IpV4_Ip_VCfgGetProbeWaitMinMsec())
      {
        IPV4_CTRL_LL_VAR(WaitUntilTime) += (RandNo % ( IpV4_Ip_VCfgGetProbeWaitMaxMsec() - IpV4_Ip_VCfgGetProbeWaitMinMsec()));
      }

      IPV4_CTRL_LL_VAR(State) = IPV4_IP_LL_STATE_WAIT;
    }
    break;

  case IPV4_IP_LL_STATE_WAIT:
    {
      /* wait some time before issue the next probe cycle */
      if(IPV4_CTRL_LL_VAR(WaitUntilTime) <= IPV4_CTRL_LL_VAR(MsecCnt))
      {
        IPV4_CTRL_LL_VAR(State)      = IPV4_IP_LL_STATE_PROBE;
        IPV4_CTRL_LL_VAR(ProbeState) = IPV4_IP_LL_PROBE_STATE_CHOOSE;
      }
      else
      {
        /* wait a little longer */
        /* do nothing */
      }
    }
    break;

  case IPV4_IP_LL_STATE_PROBE:
    {
      if(IPV4_CTRL_LL_VAR(AddrConflict) != 0)
      {
        /* goto conflict */
        IPV4_CTRL_LL_VAR(State) = IPV4_IP_LL_STATE_CONFLICT;
      }
      else
      {

        if(IPV4_CTRL_LL_VAR(ProbeState) == IPV4_IP_LL_PROBE_STATE_CHOOSE)
        {
          IPV4_CTRL_LL_VAR(NetAddrCand) = IpV4_Ip_VLl_GenerateIpAddr(IpCtrlIdx, IPV4_CTRL_LL_VAR(ConflictsNum));
          IPV4_CTRL_LL_VAR(ProbeState)  = IPV4_IP_LL_PROBE_STATE_PROBE;
        }

        if(IPV4_CTRL_LL_VAR(ProbeState) == IPV4_IP_LL_PROBE_STATE_PROBE)
        {
          Std_ReturnType     RetArp;

          RetArp = IpV4_Arp_SendArpProbe(IpCtrlIdx, IPV4_CTRL_LL_VAR(NetAddrCand));
          if(E_OK == RetArp)
          {
            IPV4_CTRL_LL_VAR(ProbeNumSinceConf)++;
            IPV4_CTRL_LL_VAR(ProbeState) = IPV4_IP_LL_PROBE_STATE_WAIT;

            if(IPV4_CTRL_LL_VAR(ProbeNumSinceConf) == IpV4_Ip_VCfgGetProbeNum())
            {
              /* wait IPV4_IP_ANNOUNCE_WAIT_MS ms */
              IPV4_CTRL_LL_VAR(WaitUntilTime) = IPV4_CTRL_LL_VAR(MsecCnt) + IpV4_Ip_VCfgGetAnnounceWaitMsec();
            }
            else
            {
              /* wait random time (IPV4_IP_PROBE_MIN_MS .. IPV4_IP_PROBE_MAX_MS) ms */
              IPV4_CTRL_LL_VAR(WaitUntilTime) = IPV4_CTRL_LL_VAR(MsecCnt) +
                                            ((uint32)(IpV4_Ip_VCfgGetProbeMinMsec() + IpV4_Ip_VCfgGetProbeMaxMsec())/2);
            }
          }
          else
          {
            /* ARP request could not be sent, so try again later */
          }
        }
        else if(IPV4_CTRL_LL_VAR(ProbeState) == IPV4_IP_LL_PROBE_STATE_WAIT)
        {
          if(IPV4_CTRL_LL_VAR(WaitUntilTime) < IPV4_CTRL_LL_VAR(MsecCnt))
          {
            if(IPV4_CTRL_LL_VAR(ProbeNumSinceConf) == IpV4_Ip_VCfgGetProbeNum())
            {
              /* goto announce */
              IPV4_CTRL_LL_VAR(State)    = IPV4_IP_LL_STATE_ANNOUNCE;
              IPV4_CTRL_LL_VAR(AnnState) = IPV4_IP_LL_ANN_STATE_PROBE;

              /* "If, by ANNOUNCE_WAIT seconds after the transmission of the last ARP
               *  Probe no conflicting ARP Reply or ARP Probe has been received, then
               *  the host has successfully claimed the desired IPv4 Link-Local address."
               *                                           [RFC3927 2.2.1. Probe details]
               */

              /* valid addr found, so indicate it! */
              IPV4_CTRL_LL_VAR(AddrFound) = IPV4_CTRL_LL_VAR(NetAddrCand);
              IpV4_Ip_VIpAddrAssignmentReadyNotification(IpCtrlIdx, IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL, TRUE);
            }
            else
            {
              /* next probe */
              IPV4_CTRL_LL_VAR(ProbeState) = IPV4_IP_LL_PROBE_STATE_PROBE;
            }
          }
          else
          {
            /* wait a little longer */
            /* do nothing */
          }
        }
        else
        {
          /* ERROR: invalid state */
        }
      }
    }
    break;

  case IPV4_IP_LL_STATE_CONFLICT:
    {
      IPV4_CTRL_LL_VAR(AnnounceNum)  = 0;       /* reset announcement number */
      IPV4_CTRL_LL_VAR(AddrConflict) = 0;       /* reset confict marker */
      IPV4_CTRL_LL_VAR(ProbeNumSinceConf) = 0;  /* reset probe counter */
      IPV4_CTRL_LL_VAR(ConflictsNum)++;
      if(IpV4_Ip_VCfgGetMaxConflicts() > IPV4_CTRL_LL_VAR(ConflictsNum))
      {
        /* no delay, try next random network address */
        IPV4_CTRL_LL_VAR(WaitUntilTime) = IPV4_CTRL_LL_VAR(MsecCnt);  /* now (or in the next call cycle)! */
      }
      else
      {
        /* (too) many conflicts occured, so delay further address tests */
        IPV4_CTRL_LL_VAR(WaitUntilTime) = IPV4_CTRL_LL_VAR(MsecCnt) + IpV4_Ip_VCfgGetRateLimitIntervalMsec();
      }
      IPV4_CTRL_LL_VAR(State) = IPV4_IP_LL_STATE_WAIT;

    }
    break;

  case IPV4_IP_LL_STATE_ANNOUNCE:
    {
      if(IPV4_CTRL_LL_VAR(AnnState) == IPV4_IP_LL_ANN_STATE_PROBE)
      {
        Std_ReturnType RetArp;

        /* send ARP announcement */
        /* copy old addr, send with new candidate addr, restore old addr */
        RetArp = IpV4_Arp_SendArpAnnouncement(IpCtrlIdx, IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr);

        if(E_OK == RetArp)
        {
          IPV4_CTRL_LL_VAR(AnnounceNum)++;
          IPV4_CTRL_LL_VAR(AnnState) = IPV4_IP_LL_ANN_STATE_WAIT;

          /* wait IPV4_IP_ANNOUNCE_INTERVAL_MS ms */
          IPV4_CTRL_LL_VAR(WaitUntilTime) = IPV4_CTRL_LL_VAR(MsecCnt) + IpV4_Ip_VCfgGetAnnounceIntervalMsec();
        }
      }
      else if(IPV4_CTRL_LL_VAR(AnnState) == IPV4_IP_LL_ANN_STATE_WAIT)
      {
        if(IPV4_CTRL_LL_VAR(WaitUntilTime) < IPV4_CTRL_LL_VAR(MsecCnt))
        {
          if(IPV4_CTRL_LL_VAR(AnnounceNum) >= IpV4_Ip_VCfgGetAnnounceNum())
          {
            /* goto ready */
            IPV4_CTRL_LL_VAR(State) = IPV4_IP_LL_STATE_READY;
          }
          else
          {
            /* next announcement */
            IPV4_CTRL_LL_VAR(AnnState) = IPV4_IP_LL_ANN_STATE_PROBE;
          }
        }
        else
        {
          /* wait a little longer */
          /* do nothing */
        }
      }
      else
      {
        /* Error: invalid state */
      }
    }
    break;

  case IPV4_IP_LL_STATE_READY:
    /* nothing to do. */
    break;
    
  default:
    /* Error: This state should not be reached. */
    IPV4_ASSERT_UNREACHABLE();
    break;
  }

  IPV4_CTRL_LL_VAR(MsecCnt) += IpV4_VCfgGetMainFctPeriodMsec();
  return;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

#endif /* IPV4_IP_DYN_LL_ADDR_CFG_SUPP */

/************************************************************************************************************
 *  IpV4_Ip_VForwardPacketToUpperLayer()
 ***********************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VForwardPacketToUpperLayer(
  uint8             IpCtrlIdx,
  IpV4_AddrIdType   IpAddrId,
  IpBase_AddrInType IpSrcAddr,
  IpBase_AddrInType IpDstAddr,
  uint8             IpProtocol,
  IPV4_P2V(uint8)   IpPayloadPtr,
  uint16            IpPayloadLen)
{
  IpBase_SockAddrInType IpRxSockAddrRem;

  IpRxSockAddrRem.sin_family   = IPBASE_AF_INET;
  IpRxSockAddrRem.sin_addr     = IpSrcAddr;
  IpRxSockAddrRem.sin_port     = 0;  /* undefined */

#if (TCPIP_SUPPORT_DHCPV4 == STD_OFF)
  IPV4_UNUSED_IPCTRLIDX();           /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
  IPV4_UNUSED_PARAMETER(IpDstAddr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */
#endif

  switch (IpProtocol)
  {
    case IPV4_IP_PROTOCOL_UDP:
    {
#if (TCPIP_SUPPORT_DHCPV4 == STD_ON)
      {
        IpBase_SockAddrInType IpRxSockAddrLoc;

        IpRxSockAddrLoc.sin_family   = IPBASE_AF_INET;
        IpRxSockAddrLoc.sin_addr     = IpDstAddr;
        IpRxSockAddrLoc.sin_port     = 0;  /* undefined */

        /* forward message to upper layer DHCP (in addition to forwarding it to UDP) */
        TcpIp_DhcpV4_RxIndication(IpCtrlIdx, IpPayloadPtr, IpPayloadLen, (IpBase_SockAddrType *)&IpRxSockAddrRem, (IpBase_SockAddrType *)&IpRxSockAddrLoc /* PRQA S 0310 */ /* MD_IpV4_11.04 */
# if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
          , IPV4_CTRL_VAR(TcpIp_IpV4_ChecksumOffloadingSupport).Udp /* boolean ChecksumCalculated */
# endif
        );
      }
#endif
      /* forward message to upper layer (UDP) */
      TcpIp_Udp_RxIndication(IPV4_ADDR_ID_2_TCPIP_LOCAL_ADDR_ID(IpAddrId), (IpBase_SockAddrType *)&IpRxSockAddrRem, IpPayloadPtr, IpPayloadLen /* PRQA S 0310 */ /* MD_IpV4_11.04 */
#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
        , IPV4_CTRL_VAR(TcpIp_IpV4_ChecksumOffloadingSupport).Udp /* boolean ChecksumCalculated */
#endif
      );
    }
    break;

#if (IPV4_SUPPORT_TCP == STD_ON)
    case IPV4_IP_PROTOCOL_TCP:
    {
      /* forward message only if IP address of the ECU is already configured */
      if(IPV4_IP_ONLINE_ACTIVE == IPV4_CTRL_VAR(IpV4_Ip_CtrlState))
      {
        /* forward message to upper layer (TCP) */
        TcpIp_Tcp_RxIndication(IPV4_ADDR_ID_2_TCPIP_LOCAL_ADDR_ID(IpAddrId), (IpBase_SockAddrType *)&IpRxSockAddrRem, IpPayloadPtr, IpPayloadLen /* PRQA S 0310 */ /* MD_IpV4_11.04 */
#if (TCPIP_TCPIP_HW_BASED_CHECKSUM_ENABLED == STD_ON)
          , IPV4_CTRL_VAR(TcpIp_IpV4_ChecksumOffloadingSupport).Tcp /* boolean ChecksumCalculated */
#endif
          );
      }
    }
    break;
#endif
  /* IPV4_SUPPORT_TCP */

#if (IPV4_SUPPORT_ICMP == STD_ON)
    case IPV4_IP_PROTOCOL_ICMP:
    {
      /* forward message to upper layer (ICMP) */
      IpV4_Icmp_RxIndication(IpAddrId, IpSrcAddr, IpPayloadPtr, IpPayloadLen );
    }
    break;
#endif
  /* IPV4_SUPPORT_ICMP == STD_ON */

    default:
    /* unsupported protocol -> discard message */
    break;
  }
} /* IpV4_Ip_VForwardPacketToUpperLayer() */ /* PRQA S 6010, 6030, 6060, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

#if (IPV4_IP_ENABLE_REASSEMBLY == STD_ON)
/************************************************************************************************************
 *  IpV4_Ip_VInitReassemblyBuffers()
 ***********************************************************************************************************/
STATIC FUNC(void, IPV4_CODE) IpV4_Ip_VInitReassemblyBuffers(void)
{
  uint8_least IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_5.6 */
  uint8_least ReassemblyBufDescIdx;

  /* Mark all reassembly buffer descriptors as unused */
  for (IpCtrlIdx = 0; IpCtrlIdx < IpV4_VCfgGetMaxNumCtrls(); IpCtrlIdx++)
  {
    if (IpV4_Ip_VCfgHasFragmentationConfig())
    {
      for (ReassemblyBufDescIdx = 0; ReassemblyBufDescIdx < IpV4_Ip_VCfgGetReassemblyBufDescCnt(); ReassemblyBufDescIdx++)
      {
        IPV4_P2V(IpV4_Ip_ReassemblyBufferDescType) ReassemblyBufDescPtr = &IPV4_CTRL_VAR(IpV4_Ip_ReassemblyBufferDesc)[ReassemblyBufDescIdx];

        ReassemblyBufDescPtr->Status = IPV4_IP_REASSEMBLY_BUF_STATUS_UNUSED;

        if (ReassemblyBufDescIdx < IpV4_Ip_VCfgGetReassemblyBufCnt())
        {
          ReassemblyBufDescPtr->ReassemblyBufIdx = (uint8)ReassemblyBufDescIdx;
        }
        else
        {
          ReassemblyBufDescPtr->ReassemblyBufIdx = IPV4_IP_REASSEMBLY_BUF_IDX_INV;
        }
      }
    }
  }
} /* IpV4_Ip_VInitReassemblyBuffers() */

/************************************************************************************************************
 *  IpV4_Ip_VGetReassemblyBufferDesc()
 ***********************************************************************************************************/
STATIC FUNC(uint8, IPV4_CODE) IpV4_Ip_VGetReassemblyBufferDesc(
  uint8                     IpCtrlIdx,
  IpBase_AddrInType         IpSrcAddr,
  IpBase_AddrInType         IpDstAddr,
  uint8                     IpProtocol,
  uint16                    Identification)
{
  uint8_least DescIdx;

  uint8_least UnusedDescIdx        = IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV; /* will be used if no matching descriptor is found */
  uint8_least OldestDescIdx        = IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV; /* will be used if no matching descripor and no free descriptor is found */

  for (DescIdx = 0; DescIdx < IpV4_Ip_VCfgGetReassemblyBufDescCnt(); DescIdx++)
  {
    IPV4_P2V(IpV4_Ip_ReassemblyBufferDescType) ReassemblyBufDescPtr = &IPV4_CTRL_VAR(IpV4_Ip_ReassemblyBufferDesc)[DescIdx];

    if (IPV4_IP_REASSEMBLY_BUF_STATUS_COMPLETE == ReassemblyBufDescPtr->Status)
    {
      /* Release reassembly buffer. */
      ReassemblyBufDescPtr->Status = IPV4_IP_REASSEMBLY_BUF_STATUS_UNUSED;
    }

    if (IPV4_IP_REASSEMBLY_BUF_STATUS_UNUSED != ReassemblyBufDescPtr->Status)
    {
      /* Buffers are exculsive for ip controller, so matching IpCtrlIdx is not necessary. */
      if ((ReassemblyBufDescPtr->MatchIpSrcAddr      == IpSrcAddr) &&
          (ReassemblyBufDescPtr->MatchIpDstAddr      == IpDstAddr) &&
          (ReassemblyBufDescPtr->MatchIpProtocol     == IpProtocol) &&
          (ReassemblyBufDescPtr->MatchIdentification == Identification))
      {
        /* matching reassembly buffer found */
        break;
      }

      /* Record index of the oldest descriptor that has a buffer if no unused descritor has been found yet. */
      if (IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV == UnusedDescIdx)
      {
        if (IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV == OldestDescIdx)
        {
          OldestDescIdx = DescIdx;
        }
        else
        {
          /* update oldest descriptor index if this descriptor is older than the previous stored */
          if (IPV4_UINT32_TIMESTAMP_IS_OLDER(ReassemblyBufDescPtr->TimeMs, IPV4_CTRL_VAR(IpV4_Ip_ReassemblyBufferDesc)[OldestDescIdx].TimeMs))
          {
            OldestDescIdx = DescIdx;
          }
        }
      }
    }
    else
    {
      if (IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV == UnusedDescIdx)
      {
        UnusedDescIdx = DescIdx;
      }
    }
  }

  /* Prepare unused assembly buffer descriptor if no matching reassembly buffer was found. */
  if (DescIdx >= IpV4_Ip_VCfgGetReassemblyBufDescCnt())
  {
    /* no matching reassembly buffer descriptor was found. */

    if (IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV != UnusedDescIdx)
    {
      DescIdx = UnusedDescIdx;
    }
    else
    {
      uint32 AgeMs;

      IPV4_ASSERT(IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV != OldestDescIdx); /* There must always be an oldest descriptor index. */

      AgeMs = IpV4_Ip_TimeMs - IPV4_CTRL_VAR(IpV4_Ip_ReassemblyBufferDesc)[OldestDescIdx].TimeMs;

      if (AgeMs >= IpV4_Ip_VCfgGetReassemblyTimeoutMs())
      {
        DescIdx = OldestDescIdx;
      }
      else
      {
        DescIdx = IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV;
      }
    }

    if (IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV != DescIdx)
    {
      IPV4_P2V(IpV4_Ip_ReassemblyBufferDescType) ReassemblyBufDescPtr = &IPV4_CTRL_VAR(IpV4_Ip_ReassemblyBufferDesc)[DescIdx];

      uint8_least  ReassemblyBufIdx = ReassemblyBufDescPtr->ReassemblyBufIdx;  /* PRQA S 0781 */ /* MD_IpV4_5.6 */
      uint16_least FirstGapOfs      = IPV4_IP_REASSEMBLY_BUF_NO_NEXT_GAP_OFS;
      uint16_least FirstGapSize     = IpV4_Ip_VCfgGetReassemblyBufSize() - IPV4_IP_REASSEMBLY_MAX_HEADER_LEN_BYTE;

      ReassemblyBufDescPtr->MatchIpSrcAddr       = IpSrcAddr;
      ReassemblyBufDescPtr->MatchIpDstAddr       = IpDstAddr;
      ReassemblyBufDescPtr->MatchIpProtocol      = IpProtocol;
      ReassemblyBufDescPtr->MatchIdentification  = Identification;
      ReassemblyBufDescPtr->NextFragOfs          = IPV4_IP_REASSEMBLY_MAX_HEADER_LEN_BYTE;

      IPBASE_PUT_UINT16(&IPV4_CTRL_VAR(IpV4_Ip_ReassemblyBuffers)[ReassemblyBufIdx * IpV4_Ip_VCfgGetReassemblyBufSize()], IPV4_IP_REASSEMBLY_MAX_HEADER_LEN_BYTE,                                       FirstGapOfs);
      IPBASE_PUT_UINT16(&IPV4_CTRL_VAR(IpV4_Ip_ReassemblyBuffers)[ReassemblyBufIdx * IpV4_Ip_VCfgGetReassemblyBufSize()], IPV4_IP_REASSEMBLY_MAX_HEADER_LEN_BYTE + IPV4_IP_REASSEMBLY_BUF_GAP_SIZE_OFS, FirstGapSize);

      ReassemblyBufDescPtr->TimeMs               = IpV4_Ip_TimeMs;
      ReassemblyBufDescPtr->Status               = IPV4_IP_REASSEMBLY_BUF_STATUS_IN_PROGRESS;
      ReassemblyBufDescPtr->Flags                = 0;
      ReassemblyBufDescPtr->FragmentLen          = 0;
      ReassemblyBufDescPtr->FragmentsDropped     = 0;
      ReassemblyBufDescPtr->FragmentsReceived    = 0;
    }
    else
    {
      /* RESOURCE LIMIT: no free descriptor available */
    }
  }

  return (uint8)DescIdx;
} /* IpV4_Ip_VGetReassemblyBufferDesc() */ /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/************************************************************************************************************
 *  IpV4_Ip_VReceiveFragment()
 ***********************************************************************************************************/
STATIC FUNC(boolean, IPV4_CODE) IpV4_Ip_VReceiveFragment(
  uint8                     IpCtrlIdx,
  IPV4_P2C(IpV4_Ip_HdrType) IpHdrPtr,
  IPV4_P2V(uint8*)          FragPayloadPtrPtr,
  IPV4_P2V(uint16)          FragPayloadLenPtr)
{
  boolean     ReassemblyComplete = FALSE;
  uint16      Identification;
  uint8_least RaBufDescIdx;

  IpV4_CheckDetErrorReturnValue(IPV4_COND_VALID_CTRLIDX(IpCtrlIdx), IPV4_IP_API_ID_V_INTERNAL_FUNCTION, IPV4_E_INV_POINTER, FALSE)
  IpV4_CheckDetErrorReturnValue(NULL_PTR != IpHdrPtr,               IPV4_IP_API_ID_V_INTERNAL_FUNCTION, IPV4_E_INV_POINTER, FALSE)
  IpV4_CheckDetErrorReturnValue(NULL_PTR != FragPayloadPtrPtr,      IPV4_IP_API_ID_V_INTERNAL_FUNCTION, IPV4_E_INV_POINTER, FALSE)
  IpV4_CheckDetErrorReturnValue(NULL_PTR != FragPayloadLenPtr,      IPV4_IP_API_ID_V_INTERNAL_FUNCTION, IPV4_E_INV_POINTER, FALSE)

  IPV4_ASSERT(0        != FragPayloadLenPtr[0]);
  IPV4_ASSERT(NULL_PTR != FragPayloadPtrPtr[0]);

  Identification = IPV4_NTOHS(IpHdrPtr->Ident);

  RaBufDescIdx = IpV4_Ip_VGetReassemblyBufferDesc(IpCtrlIdx, IpHdrPtr->SrcAddr, IpHdrPtr->DestAddr, IpHdrPtr->Prot, Identification);

  if (RaBufDescIdx == IPV4_IP_REASSEMBLY_BUF_DESC_IDX_INV)
  {
    /* RESOURCE LIMIT: No free reassembly buffer and descriptor
      * -> Do not start reassembly.
      */
  }
  else
  {
    IpV4_Ip_ReassemblyBufferDescType *ReassemblyBufDescPtr = &IPV4_CTRL_VAR(IpV4_Ip_ReassemblyBufferDesc)[RaBufDescIdx];
    uint16                            FlagsOffsetHbo       = IPV4_NTOHS(IpHdrPtr->Flags_Offset);
    uint16                            FragBlockOfs         = (uint16)(FlagsOffsetHbo & IPV4_IP_FRAGMENT_OFFSET_MASK);
    boolean                           FragIsLast           = (boolean)(0 == (FlagsOffsetHbo & IPV4_IP_FLAGS_MORE_FRAGMENTS));
    boolean                           AcceptFragment       = TRUE;

    ReassemblyBufDescPtr->FragmentsReceived++;

    IPV4_ASSERT(IPV4_IP_REASSEMBLY_BUF_STATUS_UNUSED != ReassemblyBufDescPtr->Status);

    if (ReassemblyBufDescPtr->Status != IPV4_IP_REASSEMBLY_BUF_STATUS_IN_PROGRESS)
    {
      /* Reassembly of this packet has already failed or is complete.
       * -> Ignore this fragment
       */
      AcceptFragment = FALSE;
    }

    if ((TRUE == AcceptFragment) && (0 == FragBlockOfs))
    {
      /* this is the first fragment. Note: it may arrive after other fragments. */

      if (0 == (ReassemblyBufDescPtr->Flags & IPV4_IP_REASSEMBLY_FLAG_FIRST_FRAG_RECEIVED))
      {
        ReassemblyBufDescPtr->Flags |= IPV4_IP_REASSEMBLY_FLAG_FIRST_FRAG_RECEIVED;
      }
      else
      {
        /* INVALID FRAGMENT: recieved first fragment twice!
         * -> Ignore this fragment
         */
        AcceptFragment = FALSE;
      }
    }

    if (TRUE == AcceptFragment)
    {
      if (TRUE == FragIsLast)
      {
        if (0 == (ReassemblyBufDescPtr->Flags & IPV4_IP_REASSEMBLY_FLAG_LAST_FRAG_RECEIVED))
        {
          ReassemblyBufDescPtr->Flags |= IPV4_IP_REASSEMBLY_FLAG_LAST_FRAG_RECEIVED;
        }
        else
        {
          /* INVALID FRAGMENT: received last fragmant twice!
           * -> Ignore this fragment
           */
          AcceptFragment = FALSE;
        }
      }
      else
      {
        if (0 != ((*FragPayloadLenPtr) % IPV4_IP_FRAGMENT_BLOCK_SIZE))
        {
          /* INVALID FRAGMENT: Only the last fragment may have a length that is not a multiple of 8 bytes.
           * -> Abort Reassemby of this packet.
           */

          AcceptFragment = FALSE;
          ReassemblyBufDescPtr->Status = IPV4_IP_REASSEMBLY_BUF_STATUS_FAILED;
        }
      }
    }

    if (TRUE == AcceptFragment)
    {
      uint8  *ReassemblyBufPtr;
      uint16  FragAbsByteOfs = (FragBlockOfs * IPV4_IP_FRAGMENT_BLOCK_SIZE)  + IPV4_IP_REASSEMBLY_MAX_HEADER_LEN_BYTE;

      IPV4_ASSERT(ReassemblyBufDescPtr->ReassemblyBufIdx < IpV4_Ip_VCfgGetReassemblyBufCnt());

      ReassemblyBufPtr = &IPV4_CTRL_VAR(IpV4_Ip_ReassemblyBuffers)[ReassemblyBufDescPtr->ReassemblyBufIdx * IpV4_Ip_VCfgGetReassemblyBufSize()];

# if (IPV4_IP_ENABLE_REASSEMBLY_OOO == STD_ON)
      if (FALSE == IpV4_Ip_VCfgIsReassemblyInOrderEnabled())
      {
        uint16  GapOfs            = ReassemblyBufDescPtr->NextFragOfs;
        uint16  PrevGapOfs        = IPV4_IP_REASSEMBLY_BUF_NO_NEXT_GAP_OFS;
        boolean SearchMatchingGap = TRUE;
        uint16  FragEndOfs        = (FragAbsByteOfs + *FragPayloadLenPtr);
        /* iterate over linked list of payload gaps.
         * payload gaps are non overlapping and stored in ascending order.
         * all gaps but the last gap will always have a size of at least 8 bytes,
         * because all fragments exept for the last fragment must be a multiple of 8 bytes long.
         */
        while ((TRUE == SearchMatchingGap) && (GapOfs != IPV4_IP_REASSEMBLY_BUF_NO_NEXT_GAP_OFS))
        {
          uint16 NextGapOfs;
          uint16 GapSize;
          uint16 GapEndOfs;

          IPV4_ASSERT(0 == (GapOfs % IPV4_IP_FRAGMENT_BLOCK_SIZE));

          IPBASE_GET_UINT16(ReassemblyBufPtr, GapOfs, NextGapOfs);
          IPV4_ASSERT((IPV4_IP_REASSEMBLY_BUF_NO_NEXT_GAP_OFS == NextGapOfs) || (0 == (NextGapOfs % IPV4_IP_FRAGMENT_BLOCK_SIZE)));

          IPBASE_GET_UINT16(ReassemblyBufPtr, GapOfs + IPV4_IP_REASSEMBLY_BUF_GAP_SIZE_OFS, GapSize);
          IPV4_ASSERT(0 < GapSize);

          GapEndOfs = (GapOfs + GapSize);

          if (FragAbsByteOfs < GapOfs)
          {
            /* INVALID FRAGMENT: Fragment starts before this gap.
             * Since all following gaps will have bigger GapOfs, they do not need to be checked.
             * This is an invalid, overlapping or already received fragment.
             * -> Ignore this fragment.
             */
            SearchMatchingGap = FALSE;
          }
          else if (FragEndOfs > GapEndOfs)
          {
            /* Fragments ends after end of this gap.
              * Check if fragement fits into next gap.
              */
          }
          else
          { /* PRQA S 0715 ControlStructNesting */ /* MD_MSR_1.1_715 */
            /* OK: Fragment fits (partially or fully) into this gap */

            if (TRUE == FragIsLast)
            {
              IPV4_ASSERT(IPV4_IP_REASSEMBLY_BUF_NO_NEXT_GAP_OFS == NextGapOfs);

              if (FragEndOfs < GapEndOfs)
              {
                /* shrink gap to it ends after last fragment */
                GapSize   = (*FragPayloadLenPtr);
                GapEndOfs = FragEndOfs;
                IPBASE_PUT_UINT16(ReassemblyBufPtr, GapOfs + IPV4_IP_REASSEMBLY_BUF_GAP_SIZE_OFS, GapSize);
              }

              ReassemblyBufDescPtr->FragmentLen = GapEndOfs;
            }

            /* There are 4 cases how a fragment may fit into a gap in the reassembly buffer.
             *  |######| Case 1: fragment complete fits into gap
             *  |####__| Case 2: fragment starts at beginning of gap but does not completely fill the gap
             *  |__####| Case 3: fragment ends at end of gap but does not start at beginning of gap
             *  |__##__| Case 4: fragment fills some part in the middle of the gap but there will remain a gap before and after the fragment
             */

            if (FragAbsByteOfs == GapOfs)
            {
              if (FragEndOfs == GapEndOfs)
              {
                /* |######| Case 1: fragment complete fits into gap */

                /* If there is a previous gap, set next pointer to following gap (or INV) */
                if (IPV4_IP_REASSEMBLY_BUF_NO_NEXT_GAP_OFS != PrevGapOfs)
                {
                  IPBASE_PUT_UINT16(ReassemblyBufPtr, PrevGapOfs, NextGapOfs);
                }
                else
                {
                  /* set first gap pointer to next gap */
                  ReassemblyBufDescPtr->NextFragOfs = NextGapOfs;
                }
              }
              else
              {
                /* |####__| Case 2: fragment starts at beginning of gap but does not completely fill the gap */

                /* Create new gap (old one will be overwirtten) */
                uint16 NewGapOfs  = FragEndOfs;
                IPBASE_PUT_UINT16(ReassemblyBufPtr, NewGapOfs + IPV4_IP_REASSEMBLY_BUF_GAP_SIZE_OFS, (GapEndOfs - FragEndOfs));

                /* If there is a previous gap, set next pointer to new gap */
                if (IPV4_IP_REASSEMBLY_BUF_NO_NEXT_GAP_OFS != PrevGapOfs)
                {
                  IPBASE_PUT_UINT16(ReassemblyBufPtr, PrevGapOfs, NewGapOfs);
                }
                else
                {
                  ReassemblyBufDescPtr->NextFragOfs = NewGapOfs;
                }

                /* Set next pointer of new gap to next gap (or INV) */
                IPBASE_PUT_UINT16(ReassemblyBufPtr, NewGapOfs, NextGapOfs);
              }
            }
            else
            {
              if (FragEndOfs == GapEndOfs)
              {
                /* |__####| Case 3: fragment ends at end of gap but does not start at beginning of gap */

                /* Decrease size of this gap */
                IPBASE_PUT_UINT16(ReassemblyBufPtr, GapOfs + IPV4_IP_REASSEMBLY_BUF_GAP_SIZE_OFS, (FragAbsByteOfs - GapOfs));
              }
              else
              {
                /* |__##__| Case 4: fragment fills some part in the middle of the gap but there will remain a gap before and after the fragment */
                uint16 NewGapOfs;

                /* Decrease size of this gap */
                IPBASE_PUT_UINT16(ReassemblyBufPtr, GapOfs + IPV4_IP_REASSEMBLY_BUF_GAP_SIZE_OFS, (FragAbsByteOfs - GapOfs));

                /* Create new gap */
                NewGapOfs  = FragEndOfs;
                IPBASE_PUT_UINT16(ReassemblyBufPtr, NewGapOfs + IPV4_IP_REASSEMBLY_BUF_GAP_SIZE_OFS, (GapEndOfs - FragEndOfs));

                /* Set next pointer of this gap to new gap */
                IPBASE_PUT_UINT16(ReassemblyBufPtr, GapOfs, NewGapOfs);

                /* Set next pointer of new gap to next gap (or INV) */
                IPBASE_PUT_UINT16(ReassemblyBufPtr, NewGapOfs, NextGapOfs);
              }
            }

            /* copy fragment payload */
            IpBase_Copy((IpBase_CopyDataType*)&ReassemblyBufPtr[FragAbsByteOfs], (const IpBase_CopyDataType*)&(*FragPayloadPtrPtr)[0], *FragPayloadLenPtr);  /* PRQA S 0310 */ /* MD_IpV4_11.04 */
            break;
          } /* PRQA L:ControlStructNesting */ /* MD_MSR_1.1_715 */

          PrevGapOfs = GapOfs;

          /* move to next gap */
          GapOfs = NextGapOfs;
        } /* while(more gaps) */

        if (IPV4_IP_REASSEMBLY_BUF_NO_NEXT_GAP_OFS == ReassemblyBufDescPtr->NextFragOfs)
        {
          if (0 != (ReassemblyBufDescPtr->Flags & IPV4_IP_REASSEMBLY_FLAG_LAST_FRAG_RECEIVED))
          {
            /* no more gaps... all fragments received
             *  - Set reassembly status of this buffer descriptor to complete.
             */
            ReassemblyComplete = TRUE;
            ReassemblyBufDescPtr->Status = IPV4_IP_REASSEMBLY_BUF_STATUS_COMPLETE;

            (*FragPayloadPtrPtr) = &ReassemblyBufPtr[IPV4_IP_REASSEMBLY_MAX_HEADER_LEN_BYTE];
            (*FragPayloadLenPtr) = ReassemblyBufDescPtr->FragmentLen - IPV4_IP_REASSEMBLY_MAX_HEADER_LEN_BYTE;
          }
          else
          {
            /* RESOURCE LIMIT: Reassembly buffer is full before last fragment has been received.
             * -> Abort reassembly
             */

            AcceptFragment = FALSE;
            ReassemblyBufDescPtr->Status = IPV4_IP_REASSEMBLY_BUF_STATUS_FAILED;
          }
        }
        else if (IPV4_IP_REASSEMBLY_BUF_NO_NEXT_GAP_OFS == GapOfs)
        {
          /* RESOURCE LIMIT: fragment does not fit into any gap. Assembly buffer too small.
           * -> Abort reassembly
           */

          AcceptFragment = FALSE;
          ReassemblyBufDescPtr->Status = IPV4_IP_REASSEMBLY_BUF_STATUS_FAILED;
          /* Descriptor will be released after the reassembly timeout has expired */
        }
        else
        {
          /* there are still gaps in the buffer. Wait for further fragments... */
        }
      }
      else
# endif
      {
        if (FragAbsByteOfs == ReassemblyBufDescPtr->NextFragOfs)
        {
          /* fragment fits exactly after the previous fragment */
          uint16 RemainingBufLen = (IpV4_Ip_VCfgGetReassemblyBufSize() - FragAbsByteOfs);

          if ((*FragPayloadLenPtr) > RemainingBufLen)
          {
            /* RESOURCE LIMIT: Assembly buffer too small.
             * -> Abort reassembly
             */

            AcceptFragment = FALSE;
            ReassemblyBufDescPtr->Status = IPV4_IP_REASSEMBLY_BUF_STATUS_UNUSED;
            /* We do not expcet segments out-of-order. So free reassembl buffer immediately. */
          }
          else
          {
            /* copy fragment payload */
            IpBase_Copy((IpBase_CopyDataType*)&ReassemblyBufPtr[FragAbsByteOfs], (const IpBase_CopyDataType*)&(*FragPayloadPtrPtr)[0], *FragPayloadLenPtr);  /* PRQA S 0310 */ /* MD_IpV4_11.04 */

            ReassemblyBufDescPtr->NextFragOfs = FragAbsByteOfs + (*FragPayloadLenPtr);

            if (TRUE == FragIsLast)
            {
              ReassemblyComplete = TRUE;
              ReassemblyBufDescPtr->Status = IPV4_IP_REASSEMBLY_BUF_STATUS_COMPLETE;
              ReassemblyBufDescPtr->FragmentLen = ReassemblyBufDescPtr->NextFragOfs;

              (*FragPayloadPtrPtr) = &ReassemblyBufPtr[IPV4_IP_REASSEMBLY_MAX_HEADER_LEN_BYTE];
              (*FragPayloadLenPtr) = ReassemblyBufDescPtr->FragmentLen - IPV4_IP_REASSEMBLY_MAX_HEADER_LEN_BYTE;
            }
          }
        }
        else
        {
          /* Unexpected fragment offset. Out of order reassembly not supported.
           * -> Abort fragment reassembly
           */
          AcceptFragment = FALSE;
          ReassemblyBufDescPtr->Status = IPV4_IP_REASSEMBLY_BUF_STATUS_UNUSED;
          /* We do not expcet segments out-of-order. So free reassembl buffer immediately. */
        }
      }
    }

    if (FALSE == AcceptFragment)
    {
      ReassemblyBufDescPtr->FragmentsDropped++;
    }
  }

  return ReassemblyComplete;
} /* IpV4_Ip_VReceiveFragment() */ /* PRQA S 6010, 6030, 6080, 2006 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF, MD_MSR_14.7 */
#endif

#define IPV4_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/* module specific MISRA deviations:
   MD_IPV4_1.1_0857:
     Reason:     Number of macro definitions is huge but improves readablitiy. (rule 0857)
     Risk:       Some compilers might have a problem with too many macro definitions.
     Prevention: Use only compilers supporting more than 1024 macro definitions.
   MD_IPV4_5.6_0781:
     Reason:     Readablitiy is increased by using well known names. (rule 0781)
     Risk:       none
     Prevention: not applicable
   MD_IPV4_6.3_5013:
     Reason:     Usage of basic types is defined in SWS_SoAd
     Risk:       problem with different platforms
     Prevention: not possible
   MD_IPV4_11.4_0310:
     Reason:     Pointer casts are standard proceeding in TcpIp data handling. (rule 0310)
     Risk:       none
     Prevention: not applicable
   MD_IPV4_16.7_3673:
     Reason:     Reworking the code to use 'const' pointers more often would cause much effort.
     Risk:       none
     Prevention: not applicable
   MD_IPV4_0771:
     Reason:     Restructuring the code so that only one break statement is used would create complex conditions that
                 are hard to understand and reduce runtime performance.
     Risk:       Code may become unstructured.
     Prevention: Covered by code review.
*/

#endif  /* (TCPIP_SUPPORT_IPV4 == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: Ip.c
 *********************************************************************************************************************/
