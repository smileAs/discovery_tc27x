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
 *         \file  TcpIp_Arp.c
 *        \brief  Implementation of Address Resolution Protocol (ARP) for IPv4
 *
 *      \details  This file is part of the TcpIp IPv4 submodule.
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

/* The ARP module is an integral part of the IP module. For this the ARP module may diectly access
   the IP configuration. */

#define TCPIP_ARP_SOURCE

#include "TcpIp_Cfg.h"
#if (TCPIP_SUPPORT_IPV4 == STD_ON)
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "TcpIp_Arp.h"
#include "TcpIp_Arp_Cbk.h"
#include "TcpIp_IpV4_Priv.h"
#include "TcpIp_IpV4_Lcfg.h"
#include "TcpIp_Priv.h"

#include "EthIf.h"

#include "TcpIp_IpV4.h"  /* needed for dynamic IP LL config */
#include "TcpIp_IpV4_XCfg.h"

#if (IPV4_SUPPORT_ICMP == STD_ON)
#include "TcpIp_IcmpV4_Cbk.h"
#endif

#if (IPV4_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#if !defined (STATIC)
# define STATIC static
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define IPV4_ARP_TIMESTAMP_SEC_MAX  (0xFFFFFFFFu)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define IPV4_ARP_TIMESTAMP_IS_OLDER(TS_A, TS_B) IPV4_UINT32_TIMESTAMP_IS_OLDER((TS_A), (TS_B))

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
  uint16 HwAddrType;
  uint16 ProtAddrType;
  uint8 HwAddrSize;
  uint8 ProtAddrSize;
  uint16 Operation;
  IpBase_EthPhysAddrType SrcMacAddr;
  uint16 SrcIpAddrHigh;
  uint16 SrcIpAddrLow;
  IpBase_EthPhysAddrType DestMacAddr;
  uint16 DestIpAddrHigh;
  uint16 DestIpAddrLow;
} IpV4_Arp_Packet4Type;

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
typedef uint16 IpV4_Arp_TimestampMsecType;
typedef uint32 IpV4_Arp_TimestampSecType;
#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/* ----- */
#define IPV4_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
STATIC VAR(IpV4_Arp_TimestampSecType, IPV4_VAR_NOINIT)  IpV4_Arp_TimestampSec;
STATIC VAR(IpV4_Arp_TimestampMsecType, IPV4_VAR_NOINIT) IpV4_Arp_TimestampMsec;
#endif

#define IPV4_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/* ----- */
#define IPV4_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

#define IPV4_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/* ----- */
#define IPV4_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
STATIC VAR(uint8, IPV4_VAR_NOINIT)  IpV4_Arp_NumPendEle;  /* number of pending ARP requests */
#endif

#define IPV4_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/* ----- */
#define IPV4_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

STATIC CONST(IpBase_EthPhysAddrType, IPV4_CONST) IpV4_Arp_PhysBroadcastAddr =
{
  0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU
};

#define IPV4_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define IPV4_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */
IPV4_LOCAL FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_VSendMessage(
           uint8 IpCtrlIdx,
           IpV4_Arp_TxStructType TxStruct );

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_Arp_VStoreDynamicEntry(
           uint8 IpCtrlIdx,
           IpBase_AddrInType NetAddr,
           P2CONST(uint8, IPV4_APPL_DATA, IPV4_CONST) PhysAddrPtr,
           boolean addIfNotExisting);

IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_Arp_VPhysAddrTableChgNotification(
    uint8             IpCtrlIdx,
    uint8             ArpTableIdx,
    boolean           Valid);

# if (IPV4_ARP_SUPPORT_DISCARD_HANDLING == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_VPhysAddrTableChgDiscardedNotification
 **********************************************************************************************************************/
/*! \brief        Notifies ULs about a new ARP-table entry that was discarded because the ARP-table was full, already.
 *  \details      Called only in case the functionality defined by DSGN-TcpIpIpV4AddressResolutionModes is active, i.e.:
 *                IPV4_ARP_SUPPORT_DISCARD_HANDLING == STD_ON
 *                Does nothing if no callback for this event is configured.
 *  \param[in]    PhysAddrPtr specifies the physical address of the discarded ARP table entry
 *  \param[in]    IpAddrPtr   specifies the IP address of the discarded ARP table entry
 *  \param[in]    CtrlIdx     EthIf controller index of the related ARP table.
 *  \pre          PRE_TCPIP_ARP_INIT
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \trace        DSGN-TcpIpIpV4AddressResolutionModes
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_Arp_VPhysAddrTableChgDiscardedNotification(
    IpBase_AddrInType                           DiscardedNetAddr,
    uint8                                       IpCtrlIdx);
# endif
#endif

#if (IPV4_ARP_STATIC_TABLES == STD_ON)
IPV4_LOCAL_INLINE FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_VStaticTableLookup(
    uint8                                    IpCtrlIdx,
    IpBase_AddrInType                        NetAddr,
    P2VAR(uint8, IPV4_APPL_DATA, IPV4_CONST) PhysAddrPtr);
#endif

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_VDetectLinkLocalAddressConflict
 **********************************************************************************************************************/
/*! \brief        Notifies the link-local address configuration module about IP addresses used in received ARP packets.
 *  \details      The link-local address configuration module uses this information to detect if the IP address of this
 *                node conflicts with the address of other nodes.
 *  \param[in]    IpCtrlIdx        Index of the IP controller/instance.
 *  \param[in]    arpOperation     Operation of the ARP packet. (IPV4_ARP_OP_REQUEST or IPV4_ARP_OP_REPLY)
 *  \param[in]    locIpAddr        Unicast IP address used by the IP controller/instance.
 *  \param[in]    arpSrcIpAddr     Source IP address contained in the ARP packet.
 *  \param[in]    arpDstIpAddr     Target IP address contained in the ARP packet.
 *  \param[in]    arpSrcMacAddrPtr Source MAC address contained in the ARP packet.
 *  \return                        E_OK:     No conflict was detected.
 *  \return                        E_NOT_OK: Address conflict detected.
 *  \pre          PRE_TCPIP_ARP_INIT
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
IPV4_LOCAL FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_VDetectLinkLocalAddressConflict(
   uint8              IpCtrlIdx,
   uint16             arpOperation,
   IpBase_AddrInType  locIpAddr,
   IpBase_AddrInType  arpSrcIpAddr,
   IpBase_AddrInType  arpDstIpAddr,
   IPV4_P2C(uint8)    arpSrcMacAddrPtr);
#endif /* IPV4_IP_DYN_LL_ADDR_CFG_SUPP */

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_VUpdateTable
 **********************************************************************************************************************/
/*! \brief        Updates an existing or inserts a new entry into the dynamic ARP table.
 *  \details      -
 *  \param[in]    IpCtrlIdx        Index of the IP controller/instance.
 *  \param[in]    arpSrcIpAddr     Source IP address contained in the ARP packet.
 *  \param[in]    arpSrcMacAddrPtr Source MAC address contained in the ARP packet.
 *  \param[in]    addIfNotExisting TRUE:  Add a new entry if new matching entry is found.
 *                                 FALSE: Leave ARP table unchanged if no matching entry is found.
 *  \pre          PRE_TCPIP_ARP_INIT
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_Arp_VUpdateTable(
   uint8              IpCtrlIdx,
   IpBase_AddrInType  arpSrcIpAddr,
   IPV4_P2C(uint8)    arpSrcMacAddrPtr,
   boolean            addIfNotExisting);
#endif

/***********************************************************************************************************************
 *  IpV4_Arp_VHandlePacket
 **********************************************************************************************************************/
/*! \brief        Handles a received ARP packet.
 *  \details      -
 *  \param[in]    IpCtrlIdx        Index of the IP controller/instance.
 *  \param[in]    arpOperation     Operation of the ARP packet. (IPV4_ARP_OP_REQUEST or IPV4_ARP_OP_REPLY)
 *  \param[in]    arpSrcIpAddr     Source IP address contained in the ARP packet.
 *  \param[in]    arpDstIpAddr     Target IP address contained in the ARP packet.
 *  \param[in]    arpSrcMacAddrPtr Source MAC address contained in the ARP packet.
 *  \pre          PRE_TCPIP_ARP_INIT
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
IPV4_LOCAL FUNC(void, IPV4_CODE) IpV4_Arp_VHandlePacket(
   uint8              IpCtrlIdx,
   uint16             arpOperation,
   IpBase_AddrInType  arpSrcIpAddr,
   IpBase_AddrInType  arpDstIpAddr,
   IPV4_P2C(uint8)    arpSrcMacAddrPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  IpV4_Arp_Init
 **********************************************************************************************************************/
/*! \brief      This API call stores the start address of the post build time configuration of the Address Resolution
 *              Protocol and may be used to initialize the data structures.
 *  \param[in]  CfgPtr             pointer to module configuration
 *  \context    initialization
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Arp_Init(
    P2CONST(IpV4_Arp_ConfigType, IPV4_APPL_DATA, IPV4_CONST) CfgPtr )
{
  uint8_least Idx;
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif

  IPV4_UNUSED_PARAMETER(CfgPtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)

  /* Initialize dynamic ARP table entries */
# if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  IpCtrlIdx = IpV4_VCfgGetMaxNumCtrls();

  while (0 < IpCtrlIdx)
# endif
  {
# if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
    IpCtrlIdx--;
# endif

    /* mark all elements of Arp_ResTable as invalid */
    Idx = IpV4_Arp_VCfgGetMaxNumAddrRes();
    while(0 != Idx)
    {
      /* for all table elements */
      Idx--;
      IPV4_CTRL_VAR(IpV4_Arp_ResTable)[Idx].Status = IPV4_ARP_ELSTATUS_INVALID;
    }

    /* mark all elements of Arp_ResMapTable as invalid */
    Idx = IpV4_VCfgGetMaxNumSocks();
    while(0 != Idx)
    {
      /* for all table elements */
      Idx--;
# if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
      IpV4_Arp_ResMapTable[Idx].IpCtrlIdx   = IpCtrlIdx;
# endif
      IpV4_Arp_ResMapTable[Idx].ResTableIdx = IPV4_ARP_INVALID_RES_IDX;
    }
  }

  IpV4_Arp_NumPendEle    = 0;
  IpV4_Arp_TimestampSec  = 0;
  IpV4_Arp_TimestampMsec = 0;
#endif
}

/***********************************************************************************************************************
 *  IpV4_Arp_MapIpToPhysMulticastAddr
 **********************************************************************************************************************/
/*! \brief      Map ip multicast address to physical multicast address
 *  \param[in]  NetMcAddr             network layer multicast address (network byte order)
 *  \param[out] PhysMcAddr            physical layer multicast address (network byte order)
 *  \context    task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Arp_MapIpToPhysMulticastAddr(IpBase_AddrInType NetMcAddr, P2VAR(uint8, AUTOMATIC, IPV4_APPL_DATA) PhysMcAddr)
{
  IpBase_AddrInType NetMcAddrHbo;

  /* ------------------------------------------------- */
  /* DET: */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT,                    IPV4_ARP_API_ID_MAP_IP_TO_PHYS_MC_ADDR, IPV4_E_NOT_INITIALIZED )
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_VALID_PTR(PhysMcAddr),   IPV4_ARP_API_ID_MAP_IP_TO_PHYS_MC_ADDR, IPV4_E_INV_POINTER )
  IpV4_CheckDetErrorReturnVoid( IPV4_ADDR_IS_MULTICAST(NetMcAddr), IPV4_ARP_API_ID_MAP_IP_TO_PHYS_MC_ADDR, IPV4_E_INV_PARAM )
  /* ------------------------------------------------- */

  /* "An IP host group address is mapped to an Ethernet multicast address
    *  by placing the low-order 23-bits of the IP address into the low-order
    *  23 bits of the Ethernet multicast address 01-00-5E-00-00-00 (hex)."
    * [RFC1112 6.4. Extensions to an Ethernet Local Network Module]
    */
  NetMcAddrHbo = IPV4_NTOHL(NetMcAddr); /* convert ip address from network byte order into host byte order */

  /* Set first three bytes 01:00:5e:XX:XX:XX */
  PhysMcAddr[0] = 0x01U;
  PhysMcAddr[1] = 0x00U;
  PhysMcAddr[2] = 0x5EU;

  /* Set last 23 bits of ip address */
  PhysMcAddr[3] = (uint8)((NetMcAddrHbo >> 16) & 0x0000007FU); /* 7 bit */
  PhysMcAddr[4] = (uint8) (NetMcAddrHbo >> 8);                 /* 8 bit */
  PhysMcAddr[5] = (uint8) (NetMcAddrHbo);                      /* 8 bit */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Arp_GetPhysicalAddress
 **********************************************************************************************************************/
FUNC(TcpIp_ReturnType, IPV4_CODE) IpV4_Arp_GetPhysicalAddress(
    uint8 IpCtrlIdx,
    IpBase_SockIdxType SockIdx,
    boolean UseSockInfo,
    IpBase_AddrInType NetAddr,
    P2VAR(uint8, AUTOMATIC, IPV4_APPL_DATA) PhysAddrPtr,
    boolean InitRes )
{
  TcpIp_ReturnType RetValue    = TCPIP_E_PHYS_ADDR_MISS;
#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
  boolean        ElemInTable = FALSE;
  uint8_least    TableIdx;
  uint8_least    TableIdxLru = 0; /* least recently used entry index */
  boolean        TableFull = 0u; /* flag to indicate that TableIdxLru contains an entry that will be overwritten (i.e. not an entry that's still unused) */
#endif
  IpBase_AddrInType InvertedNetMask;

  /* ------------------------------------------------- */
  /* DET: */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT, IPV4_ARP_API_ID_GET_PHYS_ADDR, IPV4_E_NOT_INITIALIZED, E_NOT_OK )
  if(TRUE == UseSockInfo)
  {
    IpV4_CheckDetErrorReturnValue( IPV4_ARP_COND_VALID_SOCKIDX(SockIdx), IPV4_ARP_API_ID_GET_PHYS_ADDR, IPV4_E_INV_SOCK_IDX, E_NOT_OK )
  }

  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_CTRLIDX(IpCtrlIdx), IPV4_ARP_API_ID_GET_PHYS_ADDR, IPV4_E_INV_CTRL_IDX, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_PTR(PhysAddrPtr), IPV4_ARP_API_ID_GET_PHYS_ADDR, IPV4_E_INV_POINTER, E_NOT_OK )
  /* ------------------------------------------------- */

  if (IPV4_ADDR_IS_MULTICAST(NetAddr))
  {
    /* NetAddr is an IP multicast address */
    IpV4_Arp_MapIpToPhysMulticastAddr(NetAddr, PhysAddrPtr);
    return TCPIP_OK;
  }

  InvertedNetMask = ~(IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetMask);

  if ((NetAddr & InvertedNetMask) == InvertedNetMask)
  {
    /* NetAddr is a local or global IP broadcast address */
    IpV4_VAssignPhysAddr(PhysAddrPtr, IpV4_Arp_PhysBroadcastAddr);
    return TCPIP_OK;
  }

  if((InvertedNetMask & NetAddr) == 0)
  {
    /* invalid address */
    return TCPIP_E_NOT_OK;
  }

#if (IPV4_ARP_STATIC_TABLES == STD_ON)
  /* Lookup mapping in static ARP table */
  if (E_OK == IpV4_Arp_VStaticTableLookup(IpCtrlIdx, NetAddr, PhysAddrPtr))
  {
    /* Static configured mapping has been found */
    return TCPIP_OK;
  }
#endif

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
  if (0 == IpV4_Arp_VCfgGetMaxNumAddrRes())
  {
    /* no dynamic ARP table configured on this controller */
    return TCPIP_E_NOT_OK;
  }

  /* Do not check the whole table but only the element for this socket
    - check if IP address is still the same
    - read physical address */
  if(TRUE == UseSockInfo)
  {
# if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
    if (IpV4_Arp_ResMapTable[SockIdx].IpCtrlIdx != IpCtrlIdx)
    {
      TableIdx = IPV4_ARP_INVALID_RES_IDX;
    }
    else
# endif
    {
      TableIdx = IpV4_Arp_ResMapTable[SockIdx].ResTableIdx;
    }
  }
  else
  {
    TableIdx = IPV4_ARP_INVALID_RES_IDX;
  }

  if((IPV4_ARP_INVALID_RES_IDX != TableIdx) && (IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status != IPV4_ARP_ELSTATUS_INVALID) && (IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].NetAddr == NetAddr))
  {
    /* there is an entry for this network address ("valid" or "in progress") */
    ElemInTable = TRUE;

    /* check for "not too old" will be done in next step */
  }
  else
  {
    /* there is no valid entry in mapping table */
    /* check if ARP entry already exists (without entry in mapping table): */
    for(TableIdx = 0; (TableIdx < IpV4_Arp_VCfgGetMaxNumAddrRes()); TableIdx++)
    {
      if(IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status != IPV4_ARP_ELSTATUS_INVALID)
      {
        /* compare network addresses */
        if(IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].NetAddr == NetAddr)
        {
          /* there is an entry for this network address ("valid" or "in progress") */
          ElemInTable = TRUE;

          /* update socket mapping table, so entry is found faster next time */
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
          IpV4_Arp_ResMapTable[SockIdx].IpCtrlIdx   = IpCtrlIdx;
#endif
          IpV4_Arp_ResMapTable[SockIdx].ResTableIdx = (uint8)TableIdx;

          /* check for "not too old" will be done in next step */
          break;
        }

        if ((IPV4_ARP_ELSTATUS_INVALID != IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdxLru].Status) && IPV4_ARP_TIMESTAMP_IS_OLDER(IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].TimeStamp, IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdxLru].TimeStamp))
        {
          /* store index of least recently used entry, if we need space for a new element later */
          TableIdxLru = TableIdx;
          TableFull = IpV4_Arp_CfgIsDiscardedEntryHandlingEnabled();
        }
      }
      else
      {
        /* store invalid (unused) entry as least recently used entry */
        TableIdxLru = TableIdx;
      }
    }
  }

  if(TRUE == ElemInTable)
  {
    /* check if too old */
    IpV4_Arp_TimestampSecType TimestampSec = IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].TimeStamp;

    /* we know that IpV4_Arp_TimestampSec will always be bigger than TimestampSec, so the values can be subtracted without considering the interger overflow */
    if((IpV4_Arp_VCfgGetElementTimeoutSec() == 0) || ((IpV4_Arp_TimestampSec - TimestampSec) < IpV4_Arp_VCfgGetElementTimeoutSec()))
    {
      /* table entry is not out of date */
      if ((IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status == IPV4_ARP_ELSTATUS_VALID) || 
          (IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status == IPV4_ARP_ELSTATUS_PROBE))
      {
        /* there is a valid entry for this network address -> return physical address */
        IpV4_VAssignPhysAddr(PhysAddrPtr, (const uint8 *) &(IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].PhysAddr[0]));
        RetValue = TCPIP_OK;
      }
      /* else: ARP request already is in progress, RetValue remains TCPIP_E_PHYS_ADDR_MISS */
    }
    else
    {
      /* element is too old ! */
      /* reset entry to "in progress" and reset timestamp */
      IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status    = IPV4_ARP_ELSTATUS_PROBE;
      IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].TimeStamp = IpV4_Arp_TimestampSec;
      IpV4_Arp_NumPendEle++;
      if(IpV4_Arp_SendArpRequest(IpCtrlIdx, NetAddr) != E_OK)
      {
        RetValue = TCPIP_E_NOT_OK;
      }
      /* else RetValue remains TCPIP_E_PHYS_ADDR_MISS */
    }
  }
  else
  {
    /* no matching element in table. Create new entry and trigger ARP request in case the caller desires that. */
    if(TRUE == InitRes)
    {
      /* In case DiscardedEntryHandling is active: Only modify an entry in case the ARP-table-entry is NOT full */
      if((!IpV4_Arp_CfgIsDiscardedEntryHandlingEnabled()) || (TableFull == 0u))
      {
        if(E_OK == IpV4_Arp_SendArpRequest(IpCtrlIdx, NetAddr))
        {
          uint8_least PhysAddrByteIdx;

          IPV4_VENTER_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

          if (IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdxLru].Status != IPV4_ARP_ELSTATUS_INVALID)
          {
            IpV4_Arp_VPhysAddrTableChgNotification(IpCtrlIdx, (uint8)TableIdxLru, FALSE);
          }

          /* set entry */
          for (PhysAddrByteIdx = 0; PhysAddrByteIdx < ETH_PHYS_ADDR_LEN_BYTE; PhysAddrByteIdx++)
          {
            IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdxLru].PhysAddr[PhysAddrByteIdx] = 0x00U;
          }

          IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdxLru].NetAddr   = NetAddr;
          IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdxLru].Status    = IPV4_ARP_ELSTATUS_INPROGESS;
          IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdxLru].TimeStamp = IpV4_Arp_TimestampSec;
# if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
          IpV4_Arp_ResMapTable[SockIdx].IpCtrlIdx   = IpCtrlIdx;
# endif
          IpV4_Arp_ResMapTable[SockIdx].ResTableIdx = (uint8)TableIdxLru;
          IpV4_Arp_NumPendEle++;
      
          IPV4_VLEAVE_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        }
        else
        {
          /* currently no buffer available, try again later (main function ?)
              "E_NOT_OK" will be returned */
        }
      }
      else
      {
        /* Due to the if-statement of this if-else-block it is sure that DiscardedEntryHandling is active, when we get here. */
        /* In case the new entry would overwrite an existing entry because the table is "full":
            Conduct the optional callout to indicate, which entry was discarded.
            IpV4_Arp_VPhysAddrTableChgNotification() is NOT used to do the discard callback, because in case of a new entry being discarded the ARP table is not changed. */
#if (IPV4_ARP_SUPPORT_DISCARD_HANDLING == STD_ON)
        IpV4_Arp_VPhysAddrTableChgDiscardedNotification(/*Discarded*/NetAddr, IpCtrlIdx);
        RetValue = TCPIP_E_NOT_OK;
#endif
      }
    }
  }
#endif

  return RetValue;
} /* PRQA S 2006, 6010, 6030, 6050, 6060, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MS_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STIMF */

/***********************************************************************************************************************
 *  IpV4_Arp_RxIndication
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
FUNC(void, IPV4_CODE) IpV4_Arp_RxIndication(
   uint8                                           CtrlIdx,
   Eth_FrameType                                   FrameType,
   boolean                                         IsBroadcast,
   P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA)        PhysAddrPtr, /* PRQA S 3673 */ /* MD_IPV4_16.7_3673 */
   P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA)        DataPtr,     /* PRQA S 3673 */ /* MD_IPV4_16.7_3673 */
   uint16                                          LenByte )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = IPV4_E_NO_ERROR;

  IPV4_UNUSED_PARAMETER(FrameType);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  
  IPV4_UNUSED_PARAMETER(IsBroadcast);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  
  IPV4_UNUSED_PARAMETER(PhysAddrPtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  

  /* ----- Development Error Checks ------------------------------------- */
#if (IPV4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (IpV4_State == IPV4_STATE_UNINIT)
  {
    errorId = IPV4_E_NOT_INITIALIZED;
  }
  /* Check parameter 'LenByte' */
  else if (LenByte < IPV4_ARP_PACKET_LEN_BYTE)
  {
    errorId = IPV4_E_INV_PARAM;
  }
  /* Check parameter 'DataPtr' */
  else if (DataPtr == NULL_PTR)
  {
    errorId = IPV4_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
    uint8 IpCtrlIdx;           /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#else
    const uint8 IpCtrlIdx = 0; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif

    /* #10 Check if IP instance is configured for CtrlIdx. */
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
    if (IPV4_CTRL_IDX_ETHIF_2_IP(CtrlIdx, IpCtrlIdx))
#else
    if (CtrlIdx == IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx))
#endif
    {
      IPV4_P2C(IpV4_Arp_Packet4Type) arpRxMsgPtr = (IPV4_P2C(IpV4_Arp_Packet4Type))DataPtr; /* PRQA S 0310 */ /* MD_IpV4_11.04 */
      
      /* #20 Check ARP hardware and protocal address formats. */
      if((arpRxMsgPtr->HwAddrType   == IPV4_ARP_HW_ADDR_TYPE_ETHERNET) &&
         (arpRxMsgPtr->HwAddrSize   == IPV4_ARP_HW_ADDR_SIZE_ETHERNET) &&
         (arpRxMsgPtr->ProtAddrType == IPV4_ARP_PROT_ADDR_TYPE_IPV4  ) &&
         (arpRxMsgPtr->ProtAddrSize == IPV4_ARP_PROT_ADDR_SIZE_IPV4  ))
      {
        IpBase_AddrInType SrcIpAddr;
        IpBase_AddrInType DstIpAddr;

#if ( CPU_BYTE_ORDER == HIGH_BYTE_FIRST )
        /* store physical source address of incoming ARP message */
        SrcIpAddr = ((uint32)(arpRxMsgPtr->SrcIpAddrLow) +
                   (((uint32)(arpRxMsgPtr->SrcIpAddrHigh))<<16));
        /* store physical destination address of incoming ARP message */
        DstIpAddr = ((uint32)(arpRxMsgPtr->DestIpAddrLow) +
                   (((uint32)(arpRxMsgPtr->DestIpAddrHigh))<<16 ));
#else
        /* store physical source address of incoming ARP message */
        SrcIpAddr = ((uint32)(arpRxMsgPtr->SrcIpAddrHigh) +
                   (((uint32)(arpRxMsgPtr->SrcIpAddrLow))<<16));
        /* store physical destination address of incoming ARP message */
        DstIpAddr = ((uint32)(arpRxMsgPtr->DestIpAddrHigh) +
                   (((uint32)(arpRxMsgPtr->DestIpAddrLow))<<16 ));
#endif

        IpV4_Arp_VHandlePacket(IpCtrlIdx, arpRxMsgPtr->Operation, SrcIpAddr, DstIpAddr, &arpRxMsgPtr->SrcMacAddr[0]);
      }
    }
  }  

  /* ----- Development Error Report --------------------------------------- */
#if (IPV4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != IPV4_E_NO_ERROR)
  {
    (void)Det_ReportError(TCPIP_MODULE_ID, IPV4_VINSTANCE_ID, IPV4_ARP_API_ID_RX_INDICATION, errorId);
  }
#else
  TCPIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif
} /* PRQA S 6060, 6080 */ /* MD_MSR_STPAR, MD_MSR_STIMF */

/***********************************************************************************************************************
 *  IpV4_Arp_TxConfirmation
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
FUNC(void, IPV4_CODE) IpV4_Arp_TxConfirmation(
    uint8 CtrlIdx,
    uint8 BufIdx )
{
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif

  IPV4_UNUSED_PARAMETER(BufIdx);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  

#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  if (!IPV4_CTRL_IDX_ETHIF_2_IP(CtrlIdx, IpCtrlIdx))
#else
  if (CtrlIdx != IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx))
#endif
  {
    return;
  }

  /* nothing to do */

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* End of IpV4_Arp_TxConfirmation() */

/***********************************************************************************************************************
 *  IpV4_Arp_SendArpRequest
 **********************************************************************************************************************/
/*! \brief      Send ARP request message
 *  \param[in]  IpCtrlIdx               controller index
 *  \param[in]  NetAddr               network address
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_SendArpRequest(
    uint8 IpCtrlIdx,
    IpBase_AddrInType NetAddr )
{
  IpV4_Arp_TxStructType TxStruct;

  /* ------------------------------------------------- */
  /* DET: */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT, IPV4_ARP_API_ID_SEND_ARP_REQUEST, IPV4_E_NOT_INITIALIZED, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_CTRLIDX(IpCtrlIdx), IPV4_ARP_API_ID_SEND_ARP_REQUEST, IPV4_E_INV_CTRL_IDX, E_NOT_OK )
  /* ------------------------------------------------- */

  IpV4_VAssignPhysAddr( &(TxStruct.RemPhysAddr[0]), &IpV4_Arp_PhysBroadcastAddr[0]);
  TxStruct.LocNetAddr = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr;
  TxStruct.RemNetAddr = NetAddr;
  TxStruct.Operation  = IPV4_ARP_OP_REQUEST;
  return IpV4_Arp_VSendMessage(IpCtrlIdx, TxStruct);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_SendArpProbe
 **********************************************************************************************************************/
/*! \brief      Sends an ARP Probe packet as specified in [RFC3927 1.2. Terminology]
 *  \param[in]  IpCtrlIdx             ip controller index
 *  \param[in]  IpAddrToProbe         network address to be probed
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_SendArpProbe(
    uint8             IpCtrlIdx,
    IpBase_AddrInType IpAddrToProbe)
{
  IpV4_Arp_TxStructType TxStruct;
  uint8_least           PhysAddrByteIdx = ETH_PHYS_ADDR_LEN_BYTE;

  /* ------------------------------------------------- */
  /* DET: */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT,                     IPV4_ARP_API_ID_SEND_ARP_PROBE, IPV4_E_NOT_INITIALIZED, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_CTRLIDX(IpCtrlIdx), IPV4_ARP_API_ID_SEND_ARP_PROBE, IPV4_E_INV_CTRL_IDX,    E_NOT_OK )
  /* ------------------------------------------------- */

  /* "The 'target hardware address' field is ignored and SHOULD be set to all zeroes. */
  while (0 < PhysAddrByteIdx)
  {
    PhysAddrByteIdx--;
    TxStruct.RemPhysAddr[PhysAddrByteIdx] = 0;
  }

  TxStruct.LocNetAddr = 0;                   /* "... with an all-zero 'sender IP address'." */
  TxStruct.RemNetAddr = IpAddrToProbe;       /* "The 'target IP address' field MUST be set to the address being probed." */
  TxStruct.Operation  = IPV4_ARP_OP_REQUEST; /* "ARP Request packet, broadcast on the local link" */
  return IpV4_Arp_VSendMessage(IpCtrlIdx, TxStruct);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/***********************************************************************************************************************
 *  IpV4_Arp_SendArpAnnouncement
 **********************************************************************************************************************/
/*! \brief      Sends an ARP Announcement packet as specified in [RFC3927 1.2. Terminology]
 *  \param[in]  IpCtrlIdx             ip controller index
 *  \param[in]  IpAddrToAnnounce      network address to be announced
 *  \context    task level
 **********************************************************************************************************************/
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_SendArpAnnouncement(
    uint8             IpCtrlIdx,
    IpBase_AddrInType IpAddrToAnnounce)
{
  IpV4_Arp_TxStructType TxStruct;
  uint8_least           PhysAddrByteIdx = ETH_PHYS_ADDR_LEN_BYTE;

  /* ------------------------------------------------- */
  /* DET: */
  IpV4_CheckDetErrorReturnValue( IPV4_COND_INIT,                     IPV4_ARP_API_ID_SEND_ARP_ANNOUNCEMENT, IPV4_E_NOT_INITIALIZED, E_NOT_OK )
  IpV4_CheckDetErrorReturnValue( IPV4_COND_VALID_CTRLIDX(IpCtrlIdx), IPV4_ARP_API_ID_SEND_ARP_ANNOUNCEMENT, IPV4_E_INV_CTRL_IDX,    E_NOT_OK )
  /* ------------------------------------------------- */

  /* "'ARP Announcement' is [...] an ARP Request packet,
   *  broadcast on the local link, identical to the ARP Probe [...]
   *  except that both the sender and target IP address fields contain the IP address being announced."
   */

  /* "The 'target hardware address' field is ignored and SHOULD be set to all zeroes. */
  while (0 < PhysAddrByteIdx)
  {
    PhysAddrByteIdx--;
    TxStruct.RemPhysAddr[PhysAddrByteIdx] = 0;
  }

  TxStruct.LocNetAddr = IpAddrToAnnounce;
  TxStruct.RemNetAddr = IpAddrToAnnounce;    /* "The 'target IP address' field MUST be set to the address being probed." */
  TxStruct.Operation  = IPV4_ARP_OP_REQUEST; /* "ARP Request packet, broadcast on the local link" */
  return IpV4_Arp_VSendMessage(IpCtrlIdx, TxStruct);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif

/***********************************************************************************************************************
 *  IpV4_Arp_SendGratuitousArpReq
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_SendGratuitousArpReq(
    IpV4_AddrIdType IpAddrId )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType          retVal = E_NOT_OK;
  uint8                   errorId = TCPIP_E_NO_ERROR;
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8                   IpCtrlIdx;        /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#else
  const uint8             IpCtrlIdx = 0;    /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (IPV4_DEV_ERROR_DETECT == STD_ON)
  if(!IPV4_COND_INIT)
  {
    errorId = IPV4_E_NOT_INITIALIZED;
  }
  else if(!IPV4_COND_VALID_IPADDRID(IpAddrId))
  {
    errorId = IPV4_E_INV_PARAM;
  }
  else
#endif
  {
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
    IpCtrlIdx = IpV4_Arp_GetCtrlIdxFromAddrId(IpAddrId);
    if(!IPV4_COND_VALID_CTRLIDX(IpCtrlIdx))
    {
      errorId = IPV4_E_INV_CTRL_IDX;
    }
    else
#endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #10 Verify that IP instance is in state ONLINE. */
      if(IPV4_CTRL_VAR(IpV4_Ip_CtrlState) == IPV4_IP_ONLINE_ACTIVE)
      {
        IpV4_Arp_TxStructType     TxStruct;
        IpBase_AddrInType         LocIpAddr = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr;

        /* #20 Fill the C-struct parameter that is given to IpV4_Arp_VSendMessage() in order to send a broadcast ARP request to publish the LocIpAddr. */
        IpV4_VAssignPhysAddr(&(TxStruct.RemPhysAddr[0]), &IpV4_Arp_PhysBroadcastAddr[0]);
        TxStruct.LocNetAddr = LocIpAddr;           /* "In either case, the ARP Sender Protocol Address [...] are both set to the IP address of the cache entry to be updated" */
        TxStruct.RemNetAddr = LocIpAddr;           /* "In either case, the [...] ARP Target Protocol Address are both set to the IP address of the cache entry to be updated" */
        TxStruct.Operation  = IPV4_ARP_OP_REQUEST; /* "ARP Request packet, broadcast on the local link" */

        /* #30 Pass the request to send the ARP request to the internal helper function that transmits ARP packages. */
        retVal = IpV4_Arp_VSendMessage(IpCtrlIdx, TxStruct);
      }
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (IPV4_DEV_ERROR_REPORT == STD_ON)
  if(errorId != TCPIP_E_NO_ERROR)
  {
    (void)Det_ReportError(IPV4_MODULE_ID, IPV4_VINSTANCE_ID, IPV4_ARP_API_ID_SEND_GRATUITOUS_ARP_REQ, errorId);
  }
#else
  TCPIP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
}

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_MainFunction
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, IPV4_CODE) IpV4_Arp_MainFunction(void)
{
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
  uint8 IpCtrlIdx; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif

  /* ------------------------------------------------- */
  /* DET: */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT, IPV4_ARP_API_ID_MAIN_FUNCTION, IPV4_E_NOT_INITIALIZED )
  /* ------------------------------------------------- */

  /* #10 Update time variable for timeout handling of ARP table entries. */
  IpV4_Arp_TimestampMsec += IpV4_VCfgGetMainFctPeriodMsec();

  /* #20 Execute MainFunction every second. */
  if(1000 <= IpV4_Arp_TimestampMsec)
  {
    IpV4_Arp_TimestampSec++;
    IpV4_Arp_TimestampMsec -= 1000;

    /* #30 Iterate over all configured IPv4 controllers. */
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
    IpCtrlIdx = IpV4_VCfgGetMaxNumCtrls();

    while (0 < IpCtrlIdx)
#endif
    {
#if (IPV4_MULTI_CONTROLLER_SUPPORT == STD_ON)
      IpCtrlIdx--;
#else
      const uint8 IpCtrlIdx = 0; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
#endif

      /* #40 Check if there are pending entries in the ARP table and ARP Requests have to be sent. */
      if(0 != IpV4_Arp_NumPendEle)
      {
        uint8 TableIdx;
        for(TableIdx=0; (TableIdx < IpV4_Arp_VCfgGetMaxNumAddrRes()); TableIdx++)
        {
          if ((IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status == IPV4_ARP_ELSTATUS_INPROGESS) ||
              (IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status == IPV4_ARP_ELSTATUS_PROBE) )
          {
            /* #50 Remove entry from ARP table if retry time has eceeded. */
            if((IpV4_Arp_TimestampSec - IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].TimeStamp) >= IpV4_Arp_VCfgGetRetryTimeSec())
            {
              /* timeout expired, invalide the table entry */
              IpV4_Arp_VPhysAddrTableChgNotification(IpCtrlIdx, TableIdx, FALSE);
              IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status = IPV4_ARP_ELSTATUS_INVALID;
              IpV4_Arp_NumPendEle--;

              {
                IpBase_SockAddrInType DestSockAddrIn;
                DestSockAddrIn.sin_family = IPBASE_AF_INET;
                DestSockAddrIn.sin_addr   = IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].NetAddr;

                /* call timeout function */
                TcpIp_Cbk_VAddrResTimeout(IpCtrlIdx, ((IpBase_SockAddrType *)&DestSockAddrIn)); /* PRQA S 0310 */ /* MD_IpV4_11.04 */
#if (IPV4_SUPPORT_ICMP == STD_ON)
                IpV4_Icmp_Cbk_VAddrResTimeout(IpCtrlIdx, ((IpBase_SockAddrType *)&DestSockAddrIn)); /* PRQA S 0310 */ /* MD_IpV4_11.04 */
#endif
              }

              if(0 == IpV4_Arp_NumPendEle)
              {
                break;
              }
            }
            /* #60 Send ARP Request if time interval between ARP requests has been reached. */
            else if(((IpV4_Arp_TimestampSec - IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].TimeStamp) % IpV4_Arp_VCfgGetRetryIntervalSec()) == 0)
            {
              /* trigger retry */
              (void)IpV4_Arp_SendArpRequest(IpCtrlIdx, IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].NetAddr);
            }
            else
            {
              /* do nothing */
            }
          }
        }
      }
    }
  }
} /* PRQA S 2006, 6080 */ /* MD_MSR_14.7, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  IpV4_Arp_Reset
 **********************************************************************************************************************/
/*! \brief      Reset elements in Arp_ResTable for given controller index
 *  \param[in]  IpCtrlIdx               ip controller index
 *  \context    task level
 **********************************************************************************************************************/
FUNC(void, IPV4_CODE) IpV4_Arp_Reset(
    uint8 IpCtrlIdx )
{
  uint8 TableIdx;

  /* ------------------------------------------------- */
  /* DET: */
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_INIT, IPV4_ARP_API_ID_RESET, IPV4_E_NOT_INITIALIZED )
  IpV4_CheckDetErrorReturnVoid( IPV4_COND_VALID_CTRLIDX(IpCtrlIdx), IPV4_ARP_API_ID_RESET, IPV4_E_INV_CTRL_IDX )
  /* ------------------------------------------------- */

  TableIdx = IpV4_Arp_VCfgGetMaxNumAddrRes();
  while(0 != TableIdx)
  {
    /* for all table elements */
    TableIdx--;

    IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status  = IPV4_ARP_ELSTATUS_INVALID;
    IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].NetAddr = 0;
  }

  IpV4_Arp_NumPendEle = 0;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif

/***********************************************************************************************************************
 *  IpV4_Arp_VSendMessage
 **********************************************************************************************************************/
IPV4_LOCAL FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_VSendMessage(
    uint8 IpCtrlIdx,
    IpV4_Arp_TxStructType TxStruct )
{
  Std_ReturnType           RetValue   = E_NOT_OK;
  uint8                    BufIdx; /* PRQA S 0781 */ /* MD_IpV4_05.06 */
  uint16                   BufLenByte = IPV4_ARP_PACKET_LEN_BYTE;
  IPV4_P2V(TcpIp_DataType) EthIfBufferPtr;

  IPV4_UNUSED_IPCTRLIDX();  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */  

  /* request a buffer */
  if(BUFREQ_OK == TCPIP_LL_ProvideTxBuffer(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), IPV4_ARP_FRAME_TYPE, IpV4_Ip_VCfgGetDefaultEthIfFramePrio(), &BufIdx, &EthIfBufferPtr, &BufLenByte))
  {
    if(IPV4_ARP_PACKET_LEN_BYTE <= BufLenByte)
    {
      IPV4_P2V(IpV4_Arp_Packet4Type) ArpTxMsgPtr = (IPV4_P2V(IpV4_Arp_Packet4Type))(EthIfBufferPtr); /* PRQA S 0310 */ /* MD_IpV4_11.04 */
      IPV4_P2V(uint8)                EthDstAddrPtr;

      /* fill buffer */
      ArpTxMsgPtr->HwAddrType     = IPV4_ARP_HW_ADDR_TYPE_ETHERNET;
      ArpTxMsgPtr->ProtAddrType   = IPV4_ARP_PROT_ADDR_TYPE_IPV4;
      ArpTxMsgPtr->HwAddrSize     = IPV4_ARP_HW_ADDR_SIZE_ETHERNET;
      ArpTxMsgPtr->ProtAddrSize   = IPV4_ARP_PROT_ADDR_SIZE_IPV4;
      ArpTxMsgPtr->Operation      = TxStruct.Operation;

      /* local addresses: */
      TCPIP_LL_GetPhysAddr(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), &(ArpTxMsgPtr->SrcMacAddr[0]));
#if ( CPU_BYTE_ORDER == HIGH_BYTE_FIRST )
      ArpTxMsgPtr->SrcIpAddrLow   = (uint16)(TxStruct.LocNetAddr & 0xFFFF);
      ArpTxMsgPtr->SrcIpAddrHigh  = (uint16)(TxStruct.LocNetAddr >>16);
#else
      ArpTxMsgPtr->SrcIpAddrHigh  = (uint16)(TxStruct.LocNetAddr & 0xFFFFu);
      ArpTxMsgPtr->SrcIpAddrLow   = (uint16)(TxStruct.LocNetAddr >>16);
#endif
  /* CPU_BYTE_ORDER */
      /* remote addresses: */
      IpV4_VAssignPhysAddr( &(ArpTxMsgPtr->DestMacAddr[0]), (const uint8 *)&(TxStruct.RemPhysAddr[0]) );

#if ( CPU_BYTE_ORDER == HIGH_BYTE_FIRST )
      ArpTxMsgPtr->DestIpAddrLow  = (uint16)(TxStruct.RemNetAddr & 0xFFFF);
      ArpTxMsgPtr->DestIpAddrHigh = (uint16)(TxStruct.RemNetAddr >> 16);
#else
      ArpTxMsgPtr->DestIpAddrHigh = (uint16)(TxStruct.RemNetAddr & 0xFFFFu);
      ArpTxMsgPtr->DestIpAddrLow  = (uint16)(TxStruct.RemNetAddr >> 16);
#endif
  /* CPU_BYTE_ORDER */
      /* send message */

      if((0 == TxStruct.LocNetAddr) || ((TxStruct.LocNetAddr & IPV4_IP_LL_NET_ADDR_MASK) == IPV4_IP_LL_NET_ADDR_NET))
      {
        /* "All ARP packets (*replies* as well as requests) that contain a Link-
          * Local 'sender IP address' MUST be sent using link-layer broadcast
          * instead of link-layer unicast."
          * [RFC3927 2.5. Conflict Detection and Defense]
          */
        EthDstAddrPtr = (uint8*)&(IpV4_Arp_PhysBroadcastAddr[0]);
      }
      else
      {
        EthDstAddrPtr = &(TxStruct.RemPhysAddr[0]);
      }

      RetValue = TCPIP_LL_Transmit( IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), BufIdx, IPV4_ARP_FRAME_TYPE, FALSE, IPV4_ARP_PACKET_LEN_BYTE, EthDstAddrPtr );
    }
    else
    {
      /* Buffer provided by EthIf is too small, function will return with "E_NOT_OK". */
      (void) TCPIP_LL_Transmit(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), BufIdx, IPV4_ARP_FRAME_TYPE, FALSE, 0, &(TxStruct.RemPhysAddr[0]));
      /* do nothing */
    }
  }
  else
  {
    /* EthIf could not provide a buffer, function will return with "E_NOT_OK". */
    /* do nothing, try again later */
    IPV4_DUMMY_ASM_NOP
  }

  return RetValue;
}

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_VStoreDynamicEntry
 **********************************************************************************************************************/
/*! Internal comment removed. *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_Arp_VStoreDynamicEntry(
    uint8 IpCtrlIdx,
    IpBase_AddrInType NetAddr,
    P2CONST(uint8, IPV4_APPL_DATA, IPV4_CONST) PhysAddrPtr,
    boolean addIfNotExisting)
{
  boolean entryInTable = FALSE;
  uint8_least TableIdx;
  uint8_least OldestArpResTabEleIdx = 0;
  uint8_least FreeArpResTabEleIdx   = IPV4_ARP_INVALID_RES_IDX;

  /* Iterate of ARP table and locate position of existing entry, unused entry or least recently used entry. */
  for (TableIdx = 0; TableIdx < IpV4_Arp_VCfgGetMaxNumAddrRes(); TableIdx++)
  {
    if(IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status != IPV4_ARP_ELSTATUS_INVALID)
    {
      /* entry is "valid" or "in progress" */
      if(IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].NetAddr == NetAddr)
      {
        /* matching entry found */
        entryInTable = TRUE;
        break;
      }

      if (IPV4_ARP_TIMESTAMP_IS_OLDER(IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].TimeStamp, IPV4_CTRL_VAR(IpV4_Arp_ResTable)[OldestArpResTabEleIdx].TimeStamp))
      {
        /* remember oldest entry */
        OldestArpResTabEleIdx = TableIdx;
      }
    }
    else if (IPV4_ARP_INVALID_RES_IDX == FreeArpResTabEleIdx)
    {
      /* store free entry idx */
      FreeArpResTabEleIdx = TableIdx;
    }
    else
    {
      /* ignore further free entries */
    }
  }

  /* Check if entry was found in table or a new entry shall be created if not. */
  if ((entryInTable == TRUE) || (addIfNotExisting == TRUE))
  {
    if (entryInTable == TRUE)
    {
      /* if entry has been found NetAddr already has the correct value */
      if ((IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status == IPV4_ARP_ELSTATUS_INPROGESS) ||
          (IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status == IPV4_ARP_ELSTATUS_PROBE) )
      {
        /* this is an answer for a pending request */
        IpV4_Arp_NumPendEle--;
      }
    }
    else
    {
      /* Check if an existing entry needs to be replaced with the new entry. */
      if (IPV4_ARP_INVALID_RES_IDX != FreeArpResTabEleIdx)
      {
        /* use free entry */
        TableIdx = FreeArpResTabEleIdx;
      }
      else
      {
        /* Notify upper layer about replaced entry, if neccessary. */
        TableIdx = OldestArpResTabEleIdx;
        IpV4_Arp_VPhysAddrTableChgNotification(IpCtrlIdx, (uint8)TableIdx, FALSE);
      }

      IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].NetAddr   = NetAddr;
    }

    IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].TimeStamp = IpV4_Arp_TimestampSec;
    
    /* Notify upper layer about new or changed entry, if neccessary. */
    if ((entryInTable == FALSE) || (! IPV4_LL_ADDR_IS_EQUAL(IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].PhysAddr, PhysAddrPtr)))
    {
      /* new entry in table or existing entry is updated */
      IpV4_VAssignPhysAddr(&(IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].PhysAddr[0]), (const uint8 *) PhysAddrPtr);
      IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status    = IPV4_ARP_ELSTATUS_VALID;
      IpV4_Arp_VPhysAddrTableChgNotification(IpCtrlIdx, (uint8)TableIdx, TRUE);
    }
    else
    {
      IPV4_CTRL_VAR(IpV4_Arp_ResTable)[TableIdx].Status    = IPV4_ARP_ELSTATUS_VALID;
    }
  }

  /* PRQA S 2006, 6010, 6030 1 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC */
} /* IpV4_Arp_VStorePhysicalAddress() */

/***********************************************************************************************************************
 *  IpV4_Arp_VPhysAddrTableChgNotification
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_Arp_VPhysAddrTableChgNotification(
    uint8             IpCtrlIdx,
    uint8             ArpTableIdx,
    boolean           Valid)
{
  TcpIp_SockAddrInetType SockAddrInet;

  IpV4_CheckDetErrorReturnVoid(IPV4_COND_VALID_CTRLIDX(IpCtrlIdx),                                                IPV4_ARP_API_ID_V_INTERNAL_FUNCTION, IPV4_E_INV_CTRL_IDX)
  IpV4_CheckDetErrorReturnVoid((ArpTableIdx < IpV4_Arp_VCfgGetMaxNumAddrRes()),                                   IPV4_ARP_API_ID_V_INTERNAL_FUNCTION, IPV4_E_INV_PARAM)

  SockAddrInet.domain  = TCPIP_AF_INET;
  SockAddrInet.addr[0] = IPV4_CTRL_VAR(IpV4_Arp_ResTable)[ArpTableIdx].NetAddr;
  SockAddrInet.port    = TCPIP_PORT_ANY;

  TcpIp_VPhysAddrTableChg(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), (TCPIP_P2V(TcpIp_SockAddrType))&SockAddrInet, &IPV4_CTRL_VAR(IpV4_Arp_ResTable)[ArpTableIdx].PhysAddr[0], Valid); /* PRQA S 0310 */ /* MD_IpV4_11.04 */

  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* IpV4_Arp_VPhysAddrTableChgNotification() */

# if (IPV4_ARP_SUPPORT_DISCARD_HANDLING == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_VPhysAddrTableChgDiscardedNotification
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_Arp_VPhysAddrTableChgDiscardedNotification(
    IpBase_AddrInType                           DiscardedNetAddr,
    uint8                                       IpCtrlIdx)
{
  uint8_least cbkIdx;
  TcpIp_SockAddrInetType SockAddrInet;

  SockAddrInet.domain  = TCPIP_AF_INET;
  SockAddrInet.addr[0] = DiscardedNetAddr;
  SockAddrInet.port    = TCPIP_PORT_ANY;

  for (cbkIdx = 0; cbkIdx < IpV4_Arp_CfgDiscardedEntryHandlingCbkCount(); cbkIdx++)
  {
    IpV4_Arp_CfgDiscardedEntryHandlingCbk((uint8)cbkIdx)(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), (TCPIP_P2V(TcpIp_SockAddrType))&SockAddrInet);  /* PRQA S 0310 */ /* MD_IpV4_11.04 */
  }
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* IpV4_Arp_VPhysAddrTableChgDiscardedNotification() */
# endif
#endif

#if (IPV4_ARP_STATIC_TABLES == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_VStaticTableLookup
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_VStaticTableLookup(
    uint8                                    IpCtrlIdx,
    IpBase_AddrInType                        NetAddr,
    P2VAR(uint8, IPV4_APPL_DATA, IPV4_CONST) PhysAddrPtr)
{
  uint8 TableIdx = Ipv4_Arp_VCfgGetStaticTableSize();

  while (0 < TableIdx)
  {
    TableIdx--;

    if (NetAddr == IPV4_CTRL_VAR(IpV4_Arp_StaticTable)[TableIdx].IpAddr)
    {
      /* Static ARP entry has been found */
      if (NULL_PTR != PhysAddrPtr)
      {
        /* Return configured physical/MAC address */
        IpV4_VAssignPhysAddr(&PhysAddrPtr[0], IPV4_CTRL_VAR(IpV4_Arp_StaticTable)[TableIdx].PhysAddr);
      }
      return E_OK;
    }
  }

  /* No static ARP table entry exists for the supplied NetAddr. */
  return E_NOT_OK;
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* IpV4_Arp_VStaticTableLookup() */
#endif

#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_VDetectLinkLocalAddressConflict
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
IPV4_LOCAL FUNC(Std_ReturnType, IPV4_CODE) IpV4_Arp_VDetectLinkLocalAddressConflict(
   uint8              IpCtrlIdx,
   uint16             arpOperation,
   IpBase_AddrInType  locIpAddr,
   IpBase_AddrInType  arpSrcIpAddr,
   IpBase_AddrInType  arpDstIpAddr,
   IPV4_P2C(uint8)    arpSrcMacAddrPtr)
{
  Std_ReturnType retVal = E_OK;

  /* #10 Check if link-local address assignment is configured on controller. */
  if (IpV4_Ip_VCfgIsAddrAssignmentEnabled(IPV4_IP_ADDR_ASSIGNMENT_METHOD_LINKLOCAL))
  {
    boolean                SentByOtherHost;
    IpBase_EthPhysAddrType OwnPhysAddr;

    TCPIP_LL_GetPhysAddr(IPV4_CTRL_IDX_IP_2_ETHIF(IpCtrlIdx), &(OwnPhysAddr[0]));

    SentByOtherHost = (boolean)(!(IPV4_LL_ADDR_IS_EQUAL(OwnPhysAddr, arpSrcMacAddrPtr)));

    /* #20 Notify link-local address configuration that sender IP address is used by other node, if required. */
    if (arpSrcIpAddr != 0) 
    {
      /* "If during this period, from the beginning of the probing process
        *  until ANNOUNCE_WAIT seconds after the last probe packet is sent,
        *  the host receives any ARP packet (Request *or* Reply) where the packet's
        *  'sender IP address' is the address being probed for, then the
        *  host MUST treat this address as being in use by some other host,
        *  and MUST select a new pseudo-random address and repeat the process."
        *  [RFC3927 2.2.1. Probe details]
        */

      IpV4_Ip_LlAddrInUse(IpCtrlIdx, arpSrcIpAddr);
    }
    /* #30 Notify link-local address configuration that target IP address is used by other node, if required. */
    else if ((arpOperation == IPV4_ARP_OP_REQUEST) && (SentByOtherHost == TRUE))
    {
      /* "In addition, if during this period the host receives any ARP Probe
        *  where the packet's 'target IP address' is the address being probed for,
        *  and the packet's 'sender hardware address' is not the hardware address
        *  of the interface the host is attempting to configure, then the host MUST
        *  similarly treat this as an address conflict and select a new address as above."
        */

      IpV4_Ip_LlAddrInUse(IpCtrlIdx, arpDstIpAddr);
    }
    else
    {
      /* nothing to do */
    }

    /* #40 Notify link-local address configuration if a conflict was detected. */
    if((locIpAddr != 0) && (arpSrcIpAddr == locIpAddr) && (SentByOtherHost == TRUE))
    {
      /* "At any time, if a host receives an ARP packet (request *or* reply) on
        *  an interface where the 'sender IP address' is the IP address the host
        *  has configured for that interface, but the 'sender hardware address'
        *  does not match the hardware address of that interface, then this is a
        *  conflicting ARP packet, indicating an address conflict."
        *  [RFC3927 2.5. Conflict Detection and Defense]
        */

      /* -> defend local address or restart address configuration */
      IpV4_Ip_AddrConflictInd(IPV4_CTRL_VAR(IpV4_Ip_AddrConfig)[IPV4_CTRL_ADDR_IDX_FIRST].IpAddrId);

      retVal = E_NOT_OK;
    }
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif /* IPV4_IP_DYN_LL_ADDR_CFG_SUPP */

#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
/***********************************************************************************************************************
 *  IpV4_Arp_VUpdateTable
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
IPV4_LOCAL_INLINE FUNC(void, IPV4_CODE) IpV4_Arp_VUpdateTable(
   uint8              IpCtrlIdx,
   IpBase_AddrInType  arpSrcIpAddr,
   IPV4_P2C(uint8)    arpSrcMacAddrPtr,
   boolean            addIfNotExisting)
{
  /* #10 Check if dynamic ARP table is configured for this controller. */
  if (0 < IpV4_Arp_VCfgGetMaxNumAddrRes())
  {
# if (IPV4_ARP_STATIC_TABLES == STD_ON)     
    /* #20 Verify that entry does not exists in static ARP table, if configured. */
    if (IpV4_Arp_VStaticTableLookup(IpCtrlIdx, arpSrcIpAddr, NULL_PTR) != E_OK)
# endif
    {
      /* #30 Store entry in the dynamic ARP table. */
      IpV4_Arp_VStoreDynamicEntry(IpCtrlIdx, arpSrcIpAddr, arpSrcMacAddrPtr, addIfNotExisting);
    }
  }
}
#endif

/***********************************************************************************************************************
 *  IpV4_Arp_VHandlePacket
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
IPV4_LOCAL FUNC(void, IPV4_CODE) IpV4_Arp_VHandlePacket(
   uint8              IpCtrlIdx,
   uint16             arpOperation,
   IpBase_AddrInType  arpSrcIpAddr,
   IpBase_AddrInType  arpDstIpAddr,
   IPV4_P2C(uint8)    arpSrcMacAddrPtr)
{
  /* get ip address of the controller */
  IpBase_AddrInType locIpAddr = IPV4_CTRL_VAR(IpV4_Ip_ActiveAddr).NetAddr;

  /* #10 Forward relevant information from ARP packet to link-local address configuration, if configured. (in order to detect IP address conflict) */
#if (IPV4_IP_DYN_LL_ADDR_CFG_SUPP == STD_ON)
  if (IpV4_Arp_VDetectLinkLocalAddressConflict(IpCtrlIdx, arpOperation, locIpAddr, arpSrcIpAddr, arpDstIpAddr, arpSrcMacAddrPtr) == E_OK)
#endif
  {
    /* #20 Check if source IP address of ARP packet is valid. */
    if (IPV4_ADDR_IS_MULTICAST(arpSrcIpAddr) || IPV4_ADDR_IS_BROADCAST(arpSrcIpAddr))
    {
      /* Ignore invalid source IP address. */
    }
    /* #30 Check if source MAC address of ARP packet is valid. */
    else if (!IPV4_LL_ADDR_IS_VALID(arpSrcMacAddrPtr))
    {
      /* Ignore invalid source MAC address. */
    }
    else 
    {
      /* #40 Update dynamic ARP table, if required. */
#if (IPV4_ARP_DYNAMIC_TABLES == STD_ON)
      if (arpSrcIpAddr != 0)
      {
        IpV4_Arp_VUpdateTable(IpCtrlIdx, arpSrcIpAddr, arpSrcMacAddrPtr, (boolean)(arpDstIpAddr == locIpAddr));
      }
      else
      {
        /* this is an ARP probe (from an IP link local address configuration) or a packet with an invalid source IP address.
         -> do not store the physical address */
      }
#endif

      /* #50 Process ARP Request. */
      if (arpOperation == IPV4_ARP_OP_REQUEST)
      {
        /* #60 Check if ARP request is addressed to this node. */
        if ((locIpAddr != 0) && (arpDstIpAddr == locIpAddr))
        {
          /* #70 Send ARP Reply. */
          IpV4_Arp_TxStructType TxStruct;

          TxStruct.LocNetAddr = locIpAddr;
          TxStruct.RemNetAddr = arpSrcIpAddr;
          TxStruct.Operation  = IPV4_ARP_OP_REPLY;
          IpV4_VAssignPhysAddr(&(TxStruct.RemPhysAddr[0]), arpSrcMacAddrPtr);

          (void)IpV4_Arp_VSendMessage(IpCtrlIdx, TxStruct);
        }
        else
        {
          /* ignore message since request is not for this node. */
        }
      }
      else if (arpOperation == IPV4_ARP_OP_REPLY)
      {
        /* Relevant information of ARP reply already handled above. */
      }
      else
      {
        /* Ignore ARP packet with unsupported operation. */
      }
    }
  }
} /* PRQA S 6060, 6080 */ /* MD_MSR_STPAR, MD_MSR_STMIF */

#define IPV4_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */

#endif  /* (TCPIP_SUPPORT_IPV4 == STD_ON) */
/**********************************************************************************************************************
 *  END OF FILE: IpV4_Arp.c
 *********************************************************************************************************************/
