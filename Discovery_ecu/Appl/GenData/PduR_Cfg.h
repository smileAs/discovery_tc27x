/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: PduR
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Cfg.h
 *   Generation Time: 2018-09-27 17:21:15
 *           Project: discovery_ecu - Version 1.0
 *          Delivery: CBD1800319_D00
 *      Tool Version: DaVinci Configurator (beta) 5.15.11 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] Communication type of PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request cannot be determined. The communication types of the PduRSrcPdu and PduRDestPdu must be unique. Routing paths between different communication types are not possible.
 * 
 * Multiple communication types found:
 * TRANSPORT_PROTOCOL, COMMUNICATION_INTERFACE
 * 
 * Parameters influencing the communication type:
 * /ActiveEcuC/CanTp/CanTpConfig/CanTpChannel_Func/CanTpRxNSdu[0:CanTpRxNSduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_FuncReq_HSC2_PP_DIAG_FuncReq_HSC2_Rx_0fb271d2_c07658fd), /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx_Functional_Address[0:DcmDslProtocolRxPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/diag_PUDR_Functional_request), /ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be[0:ComIPduType](value=NORMAL)
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request/PduRDestPdu[0:PduRDestPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/diag_PUDR_Functional_request) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRDestPdu/PduRDestPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request/PduRSrcPdu[0:PduRSrcPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_FuncReq_HSC2_PP_DIAG_FuncReq_HSC2_Rx_0fb271d2_c07658fd) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSrcPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request[0:PduRRoutingPathCommunicationType](value=TRANSPORT_PROTOCOL) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] Communication type of PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request cannot be determined. The communication types of the PduRSrcPdu and PduRDestPdu must be unique. Routing paths between different communication types are not possible.
 * 
 * Multiple communication types found:
 * TRANSPORT_PROTOCOL, COMMUNICATION_INTERFACE
 * 
 * Parameters influencing the communication type:
 * /ActiveEcuC/CanTp/CanTpConfig/CanTpChannel_physical/CanTpRxNSdu_002[0:CanTpRxNSduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_PhysReq_P2P_PP_DIAG_PhysReq_P2P_Rx_0fb271d2_c07658fd), /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx_Physical_Address[0:DcmDslProtocolRxPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/diag_PUDR_Physical_request), /ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be[0:ComIPduType](value=NORMAL)
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request/PduRDestPdu_1[0:PduRDestPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/diag_PUDR_Physical_request) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRDestPdu/PduRDestPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request/PduRSrcPdu_1[0:PduRSrcPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_PhysReq_P2P_PP_DIAG_PhysReq_P2P_Rx_0fb271d2_c07658fd) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSrcPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request[0:PduRRoutingPathCommunicationType](value=TRANSPORT_PROTOCOL) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type TRANSPORT_PROTOCOL of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request[0:PduRRoutingPathCommunicationType](value=TRANSPORT_PROTOCOL) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type TRANSPORT_PROTOCOL of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request[0:PduRRoutingPathCommunicationType](value=TRANSPORT_PROTOCOL) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 *********************************************************************************************************************/
#if !defined (PDUR_CFG_H)
# define PDUR_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PDUR_USE_DUMMY_FUNCTIONS
#define PDUR_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT_CONST
#define PDUR_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef PDUR_PROCESSOR_TC277
#define PDUR_PROCESSOR_TC277
#endif
#ifndef PDUR_COMP_GNU
#define PDUR_COMP_GNU
#endif
#ifndef PDUR_GEN_GENERATOR_MSR
#define PDUR_GEN_GENERATOR_MSR
#endif
#ifndef PDUR_CPUTYPE_BITORDER_LSB2MSB
#define PDUR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#define PDUR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_LINKTIME
#define PDUR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef PDUR_CONFIGURATION_VARIANT
#define PDUR_CONFIGURATION_VARIANT PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef PDUR_POSTBUILD_VARIANT_SUPPORT
#define PDUR_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define PDUR_DEV_ERROR_DETECT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSafeBswChecks] || /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */
#define PDUR_DEV_ERROR_REPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_METADATA_SUPPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRMetaDataSupport] */
#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

 #define PDUR_ERROR_NOTIFICATION STD_OFF


#define PduR_PBConfigIdType uint32

#define PDUR_INVALID_VARARRAYIDX                                      ((uint16)0xFFFF) /**< Invalid VarArray element */

 /*  DET Error define list  */ 
#define PDUR_FCT_CANIFRXIND 0x01U 
#define PDUR_FCT_CANIFTX 0x09U 
#define PDUR_FCT_CANIFTXCFM 0x02U 
#define PDUR_FCT_COMTX 0x89U 
#define PDUR_FCT_CANTPRXIND 0x05U 
#define PDUR_FCT_CANTPTX 0x09U 
#define PDUR_FCT_CANTPTXCFM 0x08U 
#define PDUR_FCT_CANTPSOR 0x06U 
#define PDUR_FCT_CANTPCPYRX 0x04U 
#define PDUR_FCT_CANTPCPYTX 0x07U 
#define PDUR_FCT_DCMTX 0x99U 
#define PDUR_FCT_LINIFRXIND 0x51U 
#define PDUR_FCT_LINIFTX 0x59U 
#define PDUR_FCT_LINIFTXCFM 0x52U 
#define PDUR_FCT_LINIFTT 0x53U 
 /*   PduR_CanIfIfRxIndication  PduR_CanIfTransmit  PduR_CanIfTxConfirmation  PduR_ComTransmit  PduR_CanTpTpRxIndication  PduR_CanTpTransmit  PduR_CanTpTxConfirmation  PduR_CanTpStartOfReception  PduR_CanTpCopyRxData  PduR_CanTpCopyTxData  PduR_DcmTransmit  PduR_LinIfIfRxIndication  PduR_LinIfTransmit  PduR_LinIfTxConfirmation  PduR_LinIfTriggerTransmit  */ 



/**
 * \defgroup PduRHandleIdsIfRxDest Handle IDs of handle space IfRxDest.
 * \brief Communication interface Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_Can_PT_APA_SecCH_FrP00_427ad0d9      0
#define PduRConf_PduRDestPdu_DST_Can_PT_APA_SecCH_FrP01_427ad0d9      1
#define PduRConf_PduRDestPdu_DST_Can_PT_APA_SecCH_FrP02_427ad0d9      2
#define PduRConf_PduRDestPdu_DST_Can_PT_APA_SecCH_FrP03_427ad0d9      3
#define PduRConf_PduRDestPdu_DST_Can_PT_APA_SecCH_FrP04_427ad0d9      4
#define PduRConf_PduRDestPdu_DST_Can_PT_DIAG_DTCInfo_APA_427ad0d9     5
#define PduRConf_PduRDestPdu_DST_Can_PT_EHBS_HSC2_FrP00_0fb271d2      6
#define PduRConf_PduRDestPdu_DST_Can_PT_EPB_HSC2_FrP00_0fb271d2       7
#define PduRConf_PduRDestPdu_DST_Can_PT_EPB_HSC2_FrP01_0fb271d2       8
#define PduRConf_PduRDestPdu_DST_Can_PT_EPS_HSC2_FrP02_0fb271d2       9
#define PduRConf_PduRDestPdu_DST_Can_PT_FICM_HSC4_FrP02_c4eea277      10
#define PduRConf_PduRDestPdu_DST_Can_PT_FICM_HSC4_FrP08_c4eea277      11
#define PduRConf_PduRDestPdu_DST_Can_PT_FICM_HSC4_FrP13_c4eea277      12
#define PduRConf_PduRDestPdu_DST_Can_PT_FICM_HSC4_FrP18_c4eea277      13
#define PduRConf_PduRDestPdu_DST_Can_PT_FICM_HSC4_FrP32_c4eea277      14
#define PduRConf_PduRDestPdu_DST_Can_PT_FICM_HSC4_FrP33_c4eea277      15
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_BCM_FrP04_0fb271d2    16
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_BCM_FrP06_0fb271d2    17
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_BCM_FrP07_0fb271d2    18
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_BCM_FrS16_0fb271d2    19
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_ECM_FrP04_0fb271d2    20
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_FICM_FrP02_0fb271d2   21
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_FICM_FrP08_0fb271d2   22
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_FrP00_0fb271d2        23
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_FrP01_0fb271d2        24
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_FrP08_0fb271d2        25
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_FrP10_0fb271d2        26
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_FrP13_0fb271d2        27
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_FrS00_0fb271d2        28
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_HCU_FrP00_0fb271d2    29
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_HCU_FrP01_0fb271d2    30
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_HCU_FrP13_0fb271d2    31
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_IPK_FrP06_0fb271d2    32
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_SCU_FrP00_0fb271d2    33
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC2_SDM_FrP00_0fb271d2    34
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_BCM_FrP04_c4eea277    35
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_BCM_FrS09_c4eea277    36
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_BCM_FrS10_c4eea277    37
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_BMS_FrP07_c4eea277    38
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_PEPS_FrP01_c4eea277   39
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_PEPS_FrP02_c4eea277   40
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_TBOX_FrP01_c4eea277   41
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_TBOX_FrP05_c4eea277   42
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_TBOX_FrS10_c4eea277   43
#define PduRConf_PduRDestPdu_DST_Can_PT_GW_HSC4_TC_FrP01_c4eea277     44
#define PduRConf_PduRDestPdu_DST_Can_PT_IPK_HSC4_FrP06_c4eea277       45
#define PduRConf_PduRDestPdu_DST_Can_PT_PDC_SecCH_FrP00_427ad0d9      46
#define PduRConf_PduRDestPdu_DST_Can_PT_PDC_SecCH_FrP01_427ad0d9      47
#define PduRConf_PduRDestPdu_DST_Can_PT_RDA_HSC4_P02_c4eea277         48
#define PduRConf_PduRDestPdu_DST_Can_PT_SAS_HSC2_FrP00_0fb271d2       51
#define PduRConf_PduRDestPdu_DST_Can_PT_SCS_HSC2_FrP00_0fb271d2       52
#define PduRConf_PduRDestPdu_DST_Can_PT_SCS_HSC2_FrP01_0fb271d2       53
#define PduRConf_PduRDestPdu_DST_Can_PT_SCS_HSC2_FrP02_0fb271d2       54
#define PduRConf_PduRDestPdu_DST_Can_PT_SCS_HSC2_FrP03_0fb271d2       55
#define PduRConf_PduRDestPdu_DST_Can_PT_SCS_HSC2_FrP05_0fb271d2       56
#define PduRConf_PduRDestPdu_DST_Can_PT_SCS_HSC2_FrP11_0fb271d2       57
#define PduRConf_PduRDestPdu_DST_Can_PT_SCS_HSC2_FrP12_0fb271d2       58
#define PduRConf_PduRDestPdu_DST_Can_PT_SCS_HSC2_FrP15_0fb271d2       59
#define PduRConf_PduRDestPdu_DST_Can_PT_TPMS_HSC3_FrP01_c4eea277      60
#define PduRConf_PduRDestPdu_DST_Can_PT_TPMS_HSC3_FrP02_c4eea277      61
#define PduRConf_PduRDestPdu_DST_Can_PT_Tester_HSC2_ECM_FrP00_0fb271d2 62
#define PduRConf_PduRDestPdu_DST_Can_PT_Tester_HSC2_GW_FrP14_0fb271d2 63
#define PduRConf_PduRDestPdu_DST_Lin_PT_Read_LRU1_45618847            49
#define PduRConf_PduRDestPdu_DST_Lin_PT_Read_SRU3_45618847            50
/**\} */

/**
 * \defgroup PduRHandleIdsIfRxSrc Handle IDs of handle space IfRxSrc.
 * \brief Communication interface Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP00_427ad0d9       0
#define PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP01_427ad0d9       1
#define PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP02_427ad0d9       2
#define PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP03_427ad0d9       3
#define PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP04_427ad0d9       4
#define PduRConf_PduRSrcPdu_SRC_Can_PT_DIAG_DTCInfo_APA_427ad0d9      5
#define PduRConf_PduRSrcPdu_SRC_Can_PT_EHBS_HSC2_FrP00_0fb271d2       6
#define PduRConf_PduRSrcPdu_SRC_Can_PT_EPB_HSC2_FrP00_0fb271d2        7
#define PduRConf_PduRSrcPdu_SRC_Can_PT_EPB_HSC2_FrP01_0fb271d2        8
#define PduRConf_PduRSrcPdu_SRC_Can_PT_EPS_HSC2_FrP02_0fb271d2        9
#define PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP02_c4eea277       10
#define PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP08_c4eea277       11
#define PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP13_c4eea277       12
#define PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP18_c4eea277       13
#define PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP32_c4eea277       14
#define PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP33_c4eea277       15
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_BCM_FrP04_0fb271d2     16
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_BCM_FrP06_0fb271d2     17
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_BCM_FrP07_0fb271d2     18
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_BCM_FrS16_0fb271d2     19
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_ECM_FrP04_0fb271d2     20
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FICM_FrP02_0fb271d2    21
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FICM_FrP08_0fb271d2    22
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP00_0fb271d2         23
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP01_0fb271d2         24
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP08_0fb271d2         25
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP10_0fb271d2         26
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP13_0fb271d2         27
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrS00_0fb271d2         28
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_HCU_FrP00_0fb271d2     29
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_HCU_FrP01_0fb271d2     30
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_HCU_FrP13_0fb271d2     31
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_IPK_FrP06_0fb271d2     32
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_SCU_FrP00_0fb271d2     33
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_SDM_FrP00_0fb271d2     34
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_BCM_FrP04_c4eea277     35
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_BCM_FrS09_c4eea277     36
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_BCM_FrS10_c4eea277     37
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_BMS_FrP07_c4eea277     38
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_PEPS_FrP01_c4eea277    39
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_PEPS_FrP02_c4eea277    40
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_TBOX_FrP01_c4eea277    41
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_TBOX_FrP05_c4eea277    42
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_TBOX_FrS10_c4eea277    43
#define PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_TC_FrP01_c4eea277      44
#define PduRConf_PduRSrcPdu_SRC_Can_PT_IPK_HSC4_FrP06_c4eea277        45
#define PduRConf_PduRSrcPdu_SRC_Can_PT_PDC_SecCH_FrP00_427ad0d9       46
#define PduRConf_PduRSrcPdu_SRC_Can_PT_PDC_SecCH_FrP01_427ad0d9       47
#define PduRConf_PduRSrcPdu_SRC_Can_PT_RDA_HSC4_P02_c4eea277          48
#define PduRConf_PduRSrcPdu_SRC_Can_PT_SAS_HSC2_FrP00_0fb271d2        49
#define PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP00_0fb271d2        50
#define PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP01_0fb271d2        51
#define PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP02_0fb271d2        52
#define PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP03_0fb271d2        53
#define PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP05_0fb271d2        54
#define PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP11_0fb271d2        55
#define PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP12_0fb271d2        56
#define PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP15_0fb271d2        57
#define PduRConf_PduRSrcPdu_SRC_Can_PT_TPMS_HSC3_FrP01_c4eea277       58
#define PduRConf_PduRSrcPdu_SRC_Can_PT_TPMS_HSC3_FrP02_c4eea277       59
#define PduRConf_PduRSrcPdu_SRC_Can_PT_Tester_HSC2_ECM_FrP00_0fb271d2 60
#define PduRConf_PduRSrcPdu_SRC_Can_PT_Tester_HSC2_GW_FrP14_0fb271d2  61
#define PduRConf_PduRSrcPdu_SRC_Lin_PT_Read_LRU1_45618847             62
#define PduRConf_PduRSrcPdu_SRC_Lin_PT_Read_SRU3_45618847             63
/**\} */

/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2                              46
#define PduRConf_PduRSrcPdu_SRC_Can_PT_DIAG_DTCInfo_P2P_0fb271d2      0
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_DIAG_DTCInfo_APA_0fb271d2  1
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP00_0fb271d2        2
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP01_0fb271d2        3
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP02_0fb271d2        4
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP03_0fb271d2        5
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP04_0fb271d2        6
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrS01_0fb271d2        7
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC4_FrP03_c4eea277        8
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC4_FrS01_c4eea277        9
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_IECU_HSC4_FrP01_c4eea277   10
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_IECU_HSC4_FrP02_c4eea277   11
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_BCM_FrP03_427ad0d9   12
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_BCM_FrP04_427ad0d9   13
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_BCM_FrP07_427ad0d9   14
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_ECM_FrP00_427ad0d9   15
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_EPB_FrP00_427ad0d9   16
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_EPB_FrP01_427ad0d9   17
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_EPS_FrP02_427ad0d9   18
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_FICM_FrP02_427ad0d9  19
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_FICM_FrP08_427ad0d9  20
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_FICM_FrP18_427ad0d9  21
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP00_427ad0d9    22
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP01_427ad0d9    23
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP08_427ad0d9    24
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP10_427ad0d9    25
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP13_427ad0d9    26
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrS00_427ad0d9    27
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_HCU_ECM_FrP04_427ad0d9 28
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_HCU_FrP00_427ad0d9   29
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_HCU_FrP01_427ad0d9   30
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_HCU_FrP13_427ad0d9   31
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_IPK_FrP06_427ad0d9   32
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SAS_FrP00_427ad0d9   33
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP00_427ad0d9   34
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP01_427ad0d9   35
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP02_427ad0d9   36
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP03_427ad0d9   37
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP05_427ad0d9   38
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP11_427ad0d9   39
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP12_427ad0d9   40
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP15_427ad0d9   41
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCU_FrP00_427ad0d9   42
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SDM_FrP00_427ad0d9   43
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_TC_FrP07_427ad0d9    44
#define PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_Tester_GW_FrP14_427ad0d9 45
#define PduRConf_PduRSrcPdu_SRC_Lin_PT_Init_LRU1_45618847             47
#define PduRConf_PduRSrcPdu_SRC_Lin_PT_Init_SRU3_45618847             48
/**\} */

/**
 * \defgroup PduRHandleIdsIfTxDest Handle IDs of handle space IfTxDest.
 * \brief Communication interface Tx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_Can_PT_DIAG_DTCInfo_P2P_0fb271d2     0
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_DIAG_DTCInfo_APA_0fb271d2 3
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP00_0fb271d2       4
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP01_0fb271d2       5
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP02_0fb271d2       6
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP03_0fb271d2       7
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP04_0fb271d2       8
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrS01_0fb271d2       9
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC4_FrP03_c4eea277       10
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC4_FrS01_c4eea277       11
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_IECU_HSC4_FrP01_c4eea277  12
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_IECU_HSC4_FrP02_c4eea277  13
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_BCM_FrP03_427ad0d9  14
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_BCM_FrP04_427ad0d9  15
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_BCM_FrP07_427ad0d9  16
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_ECM_FrP00_427ad0d9  17
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_EPB_FrP00_427ad0d9  18
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_EPB_FrP01_427ad0d9  19
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_EPS_FrP02_427ad0d9  20
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_FICM_FrP02_427ad0d9 21
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_FICM_FrP08_427ad0d9 22
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_FICM_FrP18_427ad0d9 23
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP00_427ad0d9   24
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP01_427ad0d9   25
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP08_427ad0d9   26
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP10_427ad0d9   27
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP13_427ad0d9   28
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrS00_427ad0d9   29
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_HCU_ECM_FrP04_427ad0d9 30
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_HCU_FrP00_427ad0d9  31
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_HCU_FrP01_427ad0d9  32
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_HCU_FrP13_427ad0d9  33
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_IPK_FrP06_427ad0d9  34
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SAS_FrP00_427ad0d9  35
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP00_427ad0d9  36
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP01_427ad0d9  37
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP02_427ad0d9  38
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP03_427ad0d9  39
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP05_427ad0d9  40
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP11_427ad0d9  41
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP12_427ad0d9  42
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP15_427ad0d9  43
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCU_FrP00_427ad0d9  44
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SDM_FrP00_427ad0d9  45
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_TC_FrP07_427ad0d9   46
#define PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_Tester_GW_FrP14_427ad0d9 47
#define PduRConf_PduRDestPdu_DST_Lin_PT_Init_LRU1_45618847            1
#define PduRConf_PduRDestPdu_DST_Lin_PT_Init_SRU3_45618847            2
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxDest Handle IDs of handle space TpRxDest.
 * \brief Transport protocol Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_PduRDestPdu                              0
#define PduRConf_PduRDestPdu_PduRDestPdu_1                            1
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxSrc Handle IDs of handle space TpRxSrc.
 * \brief Transport protocol Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu                                0
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1                              1
/**\} */

/**
 * \defgroup PduRHandleIdsTpTxDest Handle IDs of handle space TpTxDest.
 * \brief Transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_PduRDestPdu_2                            0
/**\} */


/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_CFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Cfg.h
 *********************************************************************************************************************/

