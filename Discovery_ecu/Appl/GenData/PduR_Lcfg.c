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
 *              File: PduR_Lcfg.c
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
#define PDUR_LCFG_SOURCE

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0612 EOF */ /* MD_MSR_1.1 */


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"

#if(PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/* Include headers with callbacks */
#include "PduR_CanIf.h"
#include "PduR_Com.h"
#include "PduR_CanTp.h"
#include "PduR_Dcm.h"
#include "PduR_LinIf.h"


/**********************************************************************************************************************
 * LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA
 *********************************************************************************************************************/
/* \trace SPEC-663, SPEC-661 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_CopyRxDataFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_CopyRxDataFctPtr
  \brief  Transport protocol CopyRxData function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_CopyRxDataFctPtrType, PDUR_CONST) PduR_CopyRxDataFctPtr[1] = {
  /* Index     CopyRxDataFctPtr      Referable Keys */
  /*     0 */ Dcm_CopyRxData      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_CopyTxDataFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_CopyTxDataFctPtr
  \brief  Transport protocol CopyTxData function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_CopyTxDataFctPtrType, PDUR_CONST) PduR_CopyTxDataFctPtr[1] = {
  /* Index     CopyTxDataFctPtr      Referable Keys */
  /*     0 */ Dcm_CopyTxData      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfRoutingStateTable
**********************************************************************************************************************/
/** 
  \var    PduR_IfRoutingStateTable
  \brief  Contains state transition for Communication Interface routings
  \details
  Element                                   Description
  NextState_For_Init_If_Routing_State   
  NextState_For_Wait_For_RxIndication   
  NextState_For_Wait_For_TriggerTransmit
  NextState_For_Wait_For_TxConfirmation 
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_IfRoutingStateTableType, PDUR_CONST) PduR_IfRoutingStateTable[4] = {
    /* Index    NextState_For_Init_If_Routing_State                                                     NextState_For_Wait_For_RxIndication                                                     NextState_For_Wait_For_TriggerTransmit                                                     NextState_For_Wait_For_TxConfirmation                                                    */
  { /*     0 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE,    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,                                                                                       0UL,                                                                                      0UL },
  { /*     1 */ PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE,                                                                                      0UL },
  { /*     2 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE },
  { /*     3 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,                                                                                       0UL,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfRxIndicationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_IfRxIndicationFctPtr
  \brief  Upper layer communication interface Rx indication function pointers.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_IfRxIndicationType, PDUR_CONST) PduR_IfRxIndicationFctPtr[1] = {
  /* Index     IfRxIndicationFctPtr      Referable Keys */
  /*     0 */ Com_RxIndication        /* [/ActiveEcuC/PduR/Com] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfTriggerTransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_IfTriggerTransmitFctPtr
  \brief  Upper layer trigger transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TriggerTransmitFctPtrType, PDUR_CONST) PduR_IfTriggerTransmitFctPtr[1] = {
  /* Index     IfTriggerTransmitFctPtr      Referable Keys */
  /*     0 */ Com_TriggerTransmit        /* [/ActiveEcuC/PduR/Com] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxIf2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxIf2Dest
  \brief  This table contains all routing information to perform the Rx handling of an interface routing. Used in the &lt;LLIf&gt;_RxIndication
  \details
  Element                    Description
  DestHnd                    Handle to be used as parameter for the RxIndication function call.
  IfRxIndicationFctPtrIdx    the index of the 1:1 relation pointing to PduR_IfRxIndicationFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_RxIf2DestType, PDUR_CONST) PduR_RxIf2Dest[64] = {
    /* Index    DestHnd                                                IfRxIndicationFctPtrIdx        Referable Keys */
  { /*     0 */       ComConf_ComIPdu_APA_SecCH_FrP00_oCAN02_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_APA_SecCH_FrP00_427ad0d9/SRC_Can_PT_APA_SecCH_FrP00_427ad0d9] */
  { /*     1 */       ComConf_ComIPdu_APA_SecCH_FrP01_oCAN02_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_APA_SecCH_FrP01_427ad0d9/SRC_Can_PT_APA_SecCH_FrP01_427ad0d9] */
  { /*     2 */       ComConf_ComIPdu_APA_SecCH_FrP02_oCAN02_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_APA_SecCH_FrP02_427ad0d9/SRC_Can_PT_APA_SecCH_FrP02_427ad0d9] */
  { /*     3 */       ComConf_ComIPdu_APA_SecCH_FrP03_oCAN02_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_APA_SecCH_FrP03_427ad0d9/SRC_Can_PT_APA_SecCH_FrP03_427ad0d9] */
  { /*     4 */       ComConf_ComIPdu_APA_SecCH_FrP04_oCAN02_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_APA_SecCH_FrP04_427ad0d9/SRC_Can_PT_APA_SecCH_FrP04_427ad0d9] */
  { /*     5 */      ComConf_ComIPdu_DIAG_DTCInfo_APA_oCAN02_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_DIAG_DTCInfo_APA_427ad0d9/SRC_Can_PT_DIAG_DTCInfo_APA_427ad0d9] */
  { /*     6 */       ComConf_ComIPdu_EHBS_HSC2_FrP00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_EHBS_HSC2_FrP00_0fb271d2/SRC_Can_PT_EHBS_HSC2_FrP00_0fb271d2] */
  { /*     7 */        ComConf_ComIPdu_EPB_HSC2_FrP00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_EPB_HSC2_FrP00_0fb271d2/SRC_Can_PT_EPB_HSC2_FrP00_0fb271d2] */
  { /*     8 */        ComConf_ComIPdu_EPB_HSC2_FrP01_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_EPB_HSC2_FrP01_0fb271d2/SRC_Can_PT_EPB_HSC2_FrP01_0fb271d2] */
  { /*     9 */        ComConf_ComIPdu_EPS_HSC2_FrP02_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_EPS_HSC2_FrP02_0fb271d2/SRC_Can_PT_EPS_HSC2_FrP02_0fb271d2] */
  { /*    10 */       ComConf_ComIPdu_FICM_HSC4_FrP02_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_FICM_HSC4_FrP02_c4eea277/SRC_Can_PT_FICM_HSC4_FrP02_c4eea277] */
  { /*    11 */       ComConf_ComIPdu_FICM_HSC4_FrP08_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_FICM_HSC4_FrP08_c4eea277/SRC_Can_PT_FICM_HSC4_FrP08_c4eea277] */
  { /*    12 */       ComConf_ComIPdu_FICM_HSC4_FrP13_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_FICM_HSC4_FrP13_c4eea277/SRC_Can_PT_FICM_HSC4_FrP13_c4eea277] */
  { /*    13 */       ComConf_ComIPdu_FICM_HSC4_FrP18_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_FICM_HSC4_FrP18_c4eea277/SRC_Can_PT_FICM_HSC4_FrP18_c4eea277] */
  { /*    14 */       ComConf_ComIPdu_FICM_HSC4_FrP32_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_FICM_HSC4_FrP32_c4eea277/SRC_Can_PT_FICM_HSC4_FrP32_c4eea277] */
  { /*    15 */       ComConf_ComIPdu_FICM_HSC4_FrP33_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_FICM_HSC4_FrP33_c4eea277/SRC_Can_PT_FICM_HSC4_FrP33_c4eea277] */
  { /*    16 */     ComConf_ComIPdu_GW_HSC2_BCM_FrP04_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_BCM_FrP04_0fb271d2/SRC_Can_PT_GW_HSC2_BCM_FrP04_0fb271d2] */
  { /*    17 */     ComConf_ComIPdu_GW_HSC2_BCM_FrP06_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_BCM_FrP06_0fb271d2/SRC_Can_PT_GW_HSC2_BCM_FrP06_0fb271d2] */
  { /*    18 */     ComConf_ComIPdu_GW_HSC2_BCM_FrP07_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_BCM_FrP07_0fb271d2/SRC_Can_PT_GW_HSC2_BCM_FrP07_0fb271d2] */
  { /*    19 */     ComConf_ComIPdu_GW_HSC2_BCM_FrS16_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_BCM_FrS16_0fb271d2/SRC_Can_PT_GW_HSC2_BCM_FrS16_0fb271d2] */
  { /*    20 */     ComConf_ComIPdu_GW_HSC2_ECM_FrP04_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_ECM_FrP04_0fb271d2/SRC_Can_PT_GW_HSC2_ECM_FrP04_0fb271d2] */
  { /*    21 */    ComConf_ComIPdu_GW_HSC2_FICM_FrP02_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_FICM_FrP02_0fb271d2/SRC_Can_PT_GW_HSC2_FICM_FrP02_0fb271d2] */
  { /*    22 */    ComConf_ComIPdu_GW_HSC2_FICM_FrP08_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_FICM_FrP08_0fb271d2/SRC_Can_PT_GW_HSC2_FICM_FrP08_0fb271d2] */
  { /*    23 */         ComConf_ComIPdu_GW_HSC2_FrP00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_FrP00_0fb271d2/SRC_Can_PT_GW_HSC2_FrP00_0fb271d2] */
  { /*    24 */         ComConf_ComIPdu_GW_HSC2_FrP01_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_FrP01_0fb271d2/SRC_Can_PT_GW_HSC2_FrP01_0fb271d2] */
  { /*    25 */         ComConf_ComIPdu_GW_HSC2_FrP08_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_FrP08_0fb271d2/SRC_Can_PT_GW_HSC2_FrP08_0fb271d2] */
  { /*    26 */         ComConf_ComIPdu_GW_HSC2_FrP10_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_FrP10_0fb271d2/SRC_Can_PT_GW_HSC2_FrP10_0fb271d2] */
  { /*    27 */         ComConf_ComIPdu_GW_HSC2_FrP13_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_FrP13_0fb271d2/SRC_Can_PT_GW_HSC2_FrP13_0fb271d2] */
  { /*    28 */         ComConf_ComIPdu_GW_HSC2_FrS00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_FrS00_0fb271d2/SRC_Can_PT_GW_HSC2_FrS00_0fb271d2] */
  { /*    29 */     ComConf_ComIPdu_GW_HSC2_HCU_FrP00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_HCU_FrP00_0fb271d2/SRC_Can_PT_GW_HSC2_HCU_FrP00_0fb271d2] */
  { /*    30 */     ComConf_ComIPdu_GW_HSC2_HCU_FrP01_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_HCU_FrP01_0fb271d2/SRC_Can_PT_GW_HSC2_HCU_FrP01_0fb271d2] */
  { /*    31 */     ComConf_ComIPdu_GW_HSC2_HCU_FrP13_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_HCU_FrP13_0fb271d2/SRC_Can_PT_GW_HSC2_HCU_FrP13_0fb271d2] */
  { /*    32 */     ComConf_ComIPdu_GW_HSC2_IPK_FrP06_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_IPK_FrP06_0fb271d2/SRC_Can_PT_GW_HSC2_IPK_FrP06_0fb271d2] */
  { /*    33 */     ComConf_ComIPdu_GW_HSC2_SCU_FrP00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_SCU_FrP00_0fb271d2/SRC_Can_PT_GW_HSC2_SCU_FrP00_0fb271d2] */
  { /*    34 */     ComConf_ComIPdu_GW_HSC2_SDM_FrP00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC2_SDM_FrP00_0fb271d2/SRC_Can_PT_GW_HSC2_SDM_FrP00_0fb271d2] */
  { /*    35 */     ComConf_ComIPdu_GW_HSC4_BCM_FrP04_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_BCM_FrP04_c4eea277/SRC_Can_PT_GW_HSC4_BCM_FrP04_c4eea277] */
  { /*    36 */     ComConf_ComIPdu_GW_HSC4_BCM_FrS09_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_BCM_FrS09_c4eea277/SRC_Can_PT_GW_HSC4_BCM_FrS09_c4eea277] */
  { /*    37 */     ComConf_ComIPdu_GW_HSC4_BCM_FrS10_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_BCM_FrS10_c4eea277/SRC_Can_PT_GW_HSC4_BCM_FrS10_c4eea277] */
  { /*    38 */     ComConf_ComIPdu_GW_HSC4_BMS_FrP07_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_BMS_FrP07_c4eea277/SRC_Can_PT_GW_HSC4_BMS_FrP07_c4eea277] */
  { /*    39 */    ComConf_ComIPdu_GW_HSC4_PEPS_FrP01_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_PEPS_FrP01_c4eea277/SRC_Can_PT_GW_HSC4_PEPS_FrP01_c4eea277] */
  { /*    40 */    ComConf_ComIPdu_GW_HSC4_PEPS_FrP02_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_PEPS_FrP02_c4eea277/SRC_Can_PT_GW_HSC4_PEPS_FrP02_c4eea277] */
  { /*    41 */    ComConf_ComIPdu_GW_HSC4_TBOX_FrP01_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_TBOX_FrP01_c4eea277/SRC_Can_PT_GW_HSC4_TBOX_FrP01_c4eea277] */
  { /*    42 */    ComConf_ComIPdu_GW_HSC4_TBOX_FrP05_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_TBOX_FrP05_c4eea277/SRC_Can_PT_GW_HSC4_TBOX_FrP05_c4eea277] */
  { /*    43 */    ComConf_ComIPdu_GW_HSC4_TBOX_FrS10_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_TBOX_FrS10_c4eea277/SRC_Can_PT_GW_HSC4_TBOX_FrS10_c4eea277] */
  { /*    44 */      ComConf_ComIPdu_GW_HSC4_TC_FrP01_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_GW_HSC4_TC_FrP01_c4eea277/SRC_Can_PT_GW_HSC4_TC_FrP01_c4eea277] */
  { /*    45 */        ComConf_ComIPdu_IPK_HSC4_FrP06_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_IPK_HSC4_FrP06_c4eea277/SRC_Can_PT_IPK_HSC4_FrP06_c4eea277] */
  { /*    46 */       ComConf_ComIPdu_PDC_SecCH_FrP00_oCAN02_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_PDC_SecCH_FrP00_427ad0d9/SRC_Can_PT_PDC_SecCH_FrP00_427ad0d9] */
  { /*    47 */       ComConf_ComIPdu_PDC_SecCH_FrP01_oCAN02_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_PDC_SecCH_FrP01_427ad0d9/SRC_Can_PT_PDC_SecCH_FrP01_427ad0d9] */
  { /*    48 */          ComConf_ComIPdu_RDA_HSC4_P02_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_RDA_HSC4_P02_c4eea277/SRC_Can_PT_RDA_HSC4_P02_c4eea277] */
  { /*    49 */        ComConf_ComIPdu_SAS_HSC2_FrP00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_SAS_HSC2_FrP00_0fb271d2/SRC_Can_PT_SAS_HSC2_FrP00_0fb271d2] */
    /* Index    DestHnd                                                IfRxIndicationFctPtrIdx        Referable Keys */
  { /*    50 */        ComConf_ComIPdu_SCS_HSC2_FrP00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_SCS_HSC2_FrP00_0fb271d2/SRC_Can_PT_SCS_HSC2_FrP00_0fb271d2] */
  { /*    51 */        ComConf_ComIPdu_SCS_HSC2_FrP01_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_SCS_HSC2_FrP01_0fb271d2/SRC_Can_PT_SCS_HSC2_FrP01_0fb271d2] */
  { /*    52 */        ComConf_ComIPdu_SCS_HSC2_FrP02_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_SCS_HSC2_FrP02_0fb271d2/SRC_Can_PT_SCS_HSC2_FrP02_0fb271d2] */
  { /*    53 */        ComConf_ComIPdu_SCS_HSC2_FrP03_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_SCS_HSC2_FrP03_0fb271d2/SRC_Can_PT_SCS_HSC2_FrP03_0fb271d2] */
  { /*    54 */        ComConf_ComIPdu_SCS_HSC2_FrP05_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_SCS_HSC2_FrP05_0fb271d2/SRC_Can_PT_SCS_HSC2_FrP05_0fb271d2] */
  { /*    55 */        ComConf_ComIPdu_SCS_HSC2_FrP11_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_SCS_HSC2_FrP11_0fb271d2/SRC_Can_PT_SCS_HSC2_FrP11_0fb271d2] */
  { /*    56 */        ComConf_ComIPdu_SCS_HSC2_FrP12_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_SCS_HSC2_FrP12_0fb271d2/SRC_Can_PT_SCS_HSC2_FrP12_0fb271d2] */
  { /*    57 */        ComConf_ComIPdu_SCS_HSC2_FrP15_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_SCS_HSC2_FrP15_0fb271d2/SRC_Can_PT_SCS_HSC2_FrP15_0fb271d2] */
  { /*    58 */       ComConf_ComIPdu_TPMS_HSC3_FrP01_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_TPMS_HSC3_FrP01_c4eea277/SRC_Can_PT_TPMS_HSC3_FrP01_c4eea277] */
  { /*    59 */       ComConf_ComIPdu_TPMS_HSC3_FrP02_oCAN01_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_TPMS_HSC3_FrP02_c4eea277/SRC_Can_PT_TPMS_HSC3_FrP02_c4eea277] */
  { /*    60 */ ComConf_ComIPdu_Tester_HSC2_ECM_FrP00_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Tester_HSC2_ECM_FrP00_0fb271d2/SRC_Can_PT_Tester_HSC2_ECM_FrP00_0fb271d2] */
  { /*    61 */  ComConf_ComIPdu_Tester_HSC2_GW_FrP14_oCAN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Tester_HSC2_GW_FrP14_0fb271d2/SRC_Can_PT_Tester_HSC2_GW_FrP14_0fb271d2] */
  { /*    62 */             ComConf_ComIPdu_Read_LRU1_oLIN00_3abd61be,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Lin_PT_Read_LRU1_45618847/SRC_Lin_PT_Read_LRU1_45618847] */
  { /*    63 */             ComConf_ComIPdu_Read_SRU3_oLIN00_3abd61be,                     0UL }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Lin_PT_Read_SRU3_45618847/SRC_Lin_PT_Read_SRU3_45618847] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2Dest
  \brief  This table contains all routing information to perform the Rx handling of a Tp Routing. Used in the PduR_&lt;LLTp&gt;_StartOfReception, PduR_&lt;LLTp&gt;_CopyRxData and PduR_&lt;LLTp&gt;_RxIndication.
  \details
  Element                      Description
  DestHnd                      handle to be used as parameter for the StartOfReception, CopyRxData or RxIndication function call.
  StartOfReceptionFctPtrIdx    the index of the 1:1 relation pointing to PduR_StartOfReceptionFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_RxTp2DestType, PDUR_CONST) PduR_RxTp2Dest[2] = {
    /* Index    DestHnd                                                       StartOfReceptionFctPtrIdx        Referable Keys */
  { /*     0 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_Functional_Address,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_Functional_request/PduRSrcPdu] */
  { /*     1 */   DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_Physical_Address,                       0UL }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_physical_request/PduRSrcPdu_1] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_StartOfReceptionFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_StartOfReceptionFctPtr
  \brief  Transport protocol StartOfReception function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_StartOfReceptionFctPtrType, PDUR_CONST) PduR_StartOfReceptionFctPtr[1] = {
  /* Index     StartOfReceptionFctPtr      Referable Keys */
  /*     0 */ Dcm_StartOfReception      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TpRxIndicationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_TpRxIndicationFctPtr
  \brief  Transport protocol TpRxIndication function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TpRxIndicationFctPtrType, PDUR_CONST) PduR_TpRxIndicationFctPtr[1] = {
  /* Index     TpRxIndicationFctPtr      Referable Keys */
  /*     0 */ Dcm_TpRxIndication      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TpTxConfirmationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_TpTxConfirmationFctPtr
  \brief  Transport protocol TpTxConfimation function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TpTxConfirmationFctPtrType, PDUR_CONST) PduR_TpTxConfirmationFctPtr[1] = {
  /* Index     TpTxConfirmationFctPtr      Referable Keys */
  /*     0 */ Dcm_TpTxConfirmation      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_TransmitFctPtr
  \brief  Lower layer transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TransmitFctPtrType, PDUR_CONST) PduR_TransmitFctPtr[3] = {
  /* Index     TransmitFctPtr      Referable Keys */
  /*     0 */ CanIf_Transmit ,  /* [/ActiveEcuC/PduR/CanIf] */
  /*     1 */ CanTp_Transmit ,  /* [/ActiveEcuC/PduR/CanTp] */
  /*     2 */ LinIf_Transmit    /* [/ActiveEcuC/PduR/LinIf] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all informations to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element              Description
  DestHnd              Handle to be used as parameter for the Transmit function call.
  TransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_TransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[49] = {
    /* Index    DestHnd                                                               TransmitFctPtrIdx        Referable Keys */
  { /*     0 */          CanIfConf_CanIfTxPduCfg_DIAG_DTCInfo_P2P_oCAN00_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_DIAG_DTCInfo_P2P_0fb271d2/SRC_Can_PT_DIAG_DTCInfo_P2P_0fb271d2] */
  { /*     1 */      CanIfConf_CanIfTxPduCfg_P2P_DIAG_DTCInfo_APA_oCAN00_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_DIAG_DTCInfo_APA_0fb271d2/SRC_Can_PT_P2P_DIAG_DTCInfo_APA_0fb271d2] */
  { /*     2 */            CanIfConf_CanIfTxPduCfg_P2P_HSC2_FrP00_oCAN00_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_HSC2_FrP00_0fb271d2/SRC_Can_PT_P2P_HSC2_FrP00_0fb271d2] */
  { /*     3 */            CanIfConf_CanIfTxPduCfg_P2P_HSC2_FrP01_oCAN00_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_HSC2_FrP01_0fb271d2/SRC_Can_PT_P2P_HSC2_FrP01_0fb271d2] */
  { /*     4 */            CanIfConf_CanIfTxPduCfg_P2P_HSC2_FrP02_oCAN00_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_HSC2_FrP02_0fb271d2/SRC_Can_PT_P2P_HSC2_FrP02_0fb271d2] */
  { /*     5 */            CanIfConf_CanIfTxPduCfg_P2P_HSC2_FrP03_oCAN00_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_HSC2_FrP03_0fb271d2/SRC_Can_PT_P2P_HSC2_FrP03_0fb271d2] */
  { /*     6 */            CanIfConf_CanIfTxPduCfg_P2P_HSC2_FrP04_oCAN00_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_HSC2_FrP04_0fb271d2/SRC_Can_PT_P2P_HSC2_FrP04_0fb271d2] */
  { /*     7 */            CanIfConf_CanIfTxPduCfg_P2P_HSC2_FrS01_oCAN00_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_HSC2_FrS01_0fb271d2/SRC_Can_PT_P2P_HSC2_FrS01_0fb271d2] */
  { /*     8 */            CanIfConf_CanIfTxPduCfg_P2P_HSC4_FrP03_oCAN01_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_HSC4_FrP03_c4eea277/SRC_Can_PT_P2P_HSC4_FrP03_c4eea277] */
  { /*     9 */            CanIfConf_CanIfTxPduCfg_P2P_HSC4_FrS01_oCAN01_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_HSC4_FrS01_c4eea277/SRC_Can_PT_P2P_HSC4_FrS01_c4eea277] */
  { /*    10 */       CanIfConf_CanIfTxPduCfg_P2P_IECU_HSC4_FrP01_oCAN01_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_IECU_HSC4_FrP01_c4eea277/SRC_Can_PT_P2P_IECU_HSC4_FrP01_c4eea277] */
  { /*    11 */       CanIfConf_CanIfTxPduCfg_P2P_IECU_HSC4_FrP02_oCAN01_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_IECU_HSC4_FrP02_c4eea277/SRC_Can_PT_P2P_IECU_HSC4_FrP02_c4eea277] */
  { /*    12 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_BCM_FrP03_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_BCM_FrP03_427ad0d9/SRC_Can_PT_P2P_SecCH_BCM_FrP03_427ad0d9] */
  { /*    13 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_BCM_FrP04_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_BCM_FrP04_427ad0d9/SRC_Can_PT_P2P_SecCH_BCM_FrP04_427ad0d9] */
  { /*    14 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_BCM_FrP07_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_BCM_FrP07_427ad0d9/SRC_Can_PT_P2P_SecCH_BCM_FrP07_427ad0d9] */
  { /*    15 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_ECM_FrP00_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_ECM_FrP00_427ad0d9/SRC_Can_PT_P2P_SecCH_ECM_FrP00_427ad0d9] */
  { /*    16 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_EPB_FrP00_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_EPB_FrP00_427ad0d9/SRC_Can_PT_P2P_SecCH_EPB_FrP00_427ad0d9] */
  { /*    17 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_EPB_FrP01_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_EPB_FrP01_427ad0d9/SRC_Can_PT_P2P_SecCH_EPB_FrP01_427ad0d9] */
  { /*    18 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_EPS_FrP02_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_EPS_FrP02_427ad0d9/SRC_Can_PT_P2P_SecCH_EPS_FrP02_427ad0d9] */
  { /*    19 */      CanIfConf_CanIfTxPduCfg_P2P_SecCH_FICM_FrP02_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_FICM_FrP02_427ad0d9/SRC_Can_PT_P2P_SecCH_FICM_FrP02_427ad0d9] */
  { /*    20 */      CanIfConf_CanIfTxPduCfg_P2P_SecCH_FICM_FrP08_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_FICM_FrP08_427ad0d9/SRC_Can_PT_P2P_SecCH_FICM_FrP08_427ad0d9] */
  { /*    21 */      CanIfConf_CanIfTxPduCfg_P2P_SecCH_FICM_FrP18_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_FICM_FrP18_427ad0d9/SRC_Can_PT_P2P_SecCH_FICM_FrP18_427ad0d9] */
  { /*    22 */        CanIfConf_CanIfTxPduCfg_P2P_SecCH_GW_FrP00_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_GW_FrP00_427ad0d9/SRC_Can_PT_P2P_SecCH_GW_FrP00_427ad0d9] */
  { /*    23 */        CanIfConf_CanIfTxPduCfg_P2P_SecCH_GW_FrP01_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_GW_FrP01_427ad0d9/SRC_Can_PT_P2P_SecCH_GW_FrP01_427ad0d9] */
  { /*    24 */        CanIfConf_CanIfTxPduCfg_P2P_SecCH_GW_FrP08_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_GW_FrP08_427ad0d9/SRC_Can_PT_P2P_SecCH_GW_FrP08_427ad0d9] */
  { /*    25 */        CanIfConf_CanIfTxPduCfg_P2P_SecCH_GW_FrP10_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_GW_FrP10_427ad0d9/SRC_Can_PT_P2P_SecCH_GW_FrP10_427ad0d9] */
  { /*    26 */        CanIfConf_CanIfTxPduCfg_P2P_SecCH_GW_FrP13_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_GW_FrP13_427ad0d9/SRC_Can_PT_P2P_SecCH_GW_FrP13_427ad0d9] */
  { /*    27 */        CanIfConf_CanIfTxPduCfg_P2P_SecCH_GW_FrS00_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_GW_FrS00_427ad0d9/SRC_Can_PT_P2P_SecCH_GW_FrS00_427ad0d9] */
  { /*    28 */   CanIfConf_CanIfTxPduCfg_P2P_SecCH_HCU_ECM_FrP04_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_HCU_ECM_FrP04_427ad0d9/SRC_Can_PT_P2P_SecCH_HCU_ECM_FrP04_427ad0d9] */
  { /*    29 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_HCU_FrP00_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_HCU_FrP00_427ad0d9/SRC_Can_PT_P2P_SecCH_HCU_FrP00_427ad0d9] */
  { /*    30 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_HCU_FrP01_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_HCU_FrP01_427ad0d9/SRC_Can_PT_P2P_SecCH_HCU_FrP01_427ad0d9] */
  { /*    31 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_HCU_FrP13_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_HCU_FrP13_427ad0d9/SRC_Can_PT_P2P_SecCH_HCU_FrP13_427ad0d9] */
  { /*    32 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_IPK_FrP06_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_IPK_FrP06_427ad0d9/SRC_Can_PT_P2P_SecCH_IPK_FrP06_427ad0d9] */
  { /*    33 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SAS_FrP00_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SAS_FrP00_427ad0d9/SRC_Can_PT_P2P_SecCH_SAS_FrP00_427ad0d9] */
  { /*    34 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SCS_FrP00_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SCS_FrP00_427ad0d9/SRC_Can_PT_P2P_SecCH_SCS_FrP00_427ad0d9] */
  { /*    35 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SCS_FrP01_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SCS_FrP01_427ad0d9/SRC_Can_PT_P2P_SecCH_SCS_FrP01_427ad0d9] */
  { /*    36 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SCS_FrP02_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SCS_FrP02_427ad0d9/SRC_Can_PT_P2P_SecCH_SCS_FrP02_427ad0d9] */
  { /*    37 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SCS_FrP03_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SCS_FrP03_427ad0d9/SRC_Can_PT_P2P_SecCH_SCS_FrP03_427ad0d9] */
  { /*    38 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SCS_FrP05_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SCS_FrP05_427ad0d9/SRC_Can_PT_P2P_SecCH_SCS_FrP05_427ad0d9] */
  { /*    39 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SCS_FrP11_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SCS_FrP11_427ad0d9/SRC_Can_PT_P2P_SecCH_SCS_FrP11_427ad0d9] */
  { /*    40 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SCS_FrP12_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SCS_FrP12_427ad0d9/SRC_Can_PT_P2P_SecCH_SCS_FrP12_427ad0d9] */
  { /*    41 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SCS_FrP15_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SCS_FrP15_427ad0d9/SRC_Can_PT_P2P_SecCH_SCS_FrP15_427ad0d9] */
  { /*    42 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SCU_FrP00_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SCU_FrP00_427ad0d9/SRC_Can_PT_P2P_SecCH_SCU_FrP00_427ad0d9] */
  { /*    43 */       CanIfConf_CanIfTxPduCfg_P2P_SecCH_SDM_FrP00_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_SDM_FrP00_427ad0d9/SRC_Can_PT_P2P_SecCH_SDM_FrP00_427ad0d9] */
  { /*    44 */        CanIfConf_CanIfTxPduCfg_P2P_SecCH_TC_FrP07_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_TC_FrP07_427ad0d9/SRC_Can_PT_P2P_SecCH_TC_FrP07_427ad0d9] */
  { /*    45 */ CanIfConf_CanIfTxPduCfg_P2P_SecCH_Tester_GW_FrP14_oCAN02_Tx_3abd61be,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_P2P_SecCH_Tester_GW_FrP14_427ad0d9/SRC_Can_PT_P2P_SecCH_Tester_GW_FrP14_427ad0d9] */
  { /*    46 */                                    CanTpConf_CanTpTxNSdu_CanTpTxNSdu,               1UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_diag_response/PduRSrcPdu_2] */
  { /*    47 */                           LinIfConf_LinIfTxPdu_FT_Init_LRU1_c348e776,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Lin_PT_Init_LRU1_45618847/SRC_Lin_PT_Init_LRU1_45618847] */
  { /*    48 */                           LinIfConf_LinIfTxPdu_FT_Init_SRU3_c348e776,               2UL }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Lin_PT_Init_SRU3_45618847/SRC_Lin_PT_Init_SRU3_45618847] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2Up
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2Up
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element                       Description
  DestHnd                       handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
  IfTriggerTransmitFctPtrIdx    the index of the 0:1 relation pointing to PduR_IfTriggerTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2Up[48] = {
    /* Index    DestHnd                                    IfTriggerTransmitFctPtrIdx                         Referable Keys */
  { /*     0 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_DTCInfo_P2P_PP_DIAG_DTCInfo_P2P_Tx_0fb271d2_c07658fd] */
  { /*     1 */ ComConf_ComIPdu_Init_LRU1_oLIN00_3abd61be,                                         0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Init_LRU1_PP_Init_LRU1_Tx_45618847_8792e7c3] */
  { /*     2 */ ComConf_ComIPdu_Init_SRU3_oLIN00_3abd61be,                                         0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Init_SRU3_PP_Init_SRU3_Tx_45618847_8792e7c3] */
  { /*     3 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_DIAG_DTCInfo_APA_PP_P2P_DIAG_DTCInfo_APA_Tx_0fb271d2_c07658fd] */
  { /*     4 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_HSC2_FrP00_PP_P2P_HSC2_FrP00_Tx_0fb271d2_c07658fd] */
  { /*     5 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_HSC2_FrP01_PP_P2P_HSC2_FrP01_Tx_0fb271d2_c07658fd] */
  { /*     6 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_HSC2_FrP02_PP_P2P_HSC2_FrP02_Tx_0fb271d2_c07658fd] */
  { /*     7 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_HSC2_FrP03_PP_P2P_HSC2_FrP03_Tx_0fb271d2_c07658fd] */
  { /*     8 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_HSC2_FrP04_PP_P2P_HSC2_FrP04_Tx_0fb271d2_c07658fd] */
  { /*     9 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_HSC2_FrS01_PP_P2P_HSC2_FrS01_Tx_0fb271d2_c07658fd] */
  { /*    10 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_HSC4_FrP03_PP_P2P_HSC4_FrP03_Tx_c4eea277_b771686b] */
  { /*    11 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_HSC4_FrS01_PP_P2P_HSC4_FrS01_Tx_c4eea277_b771686b] */
  { /*    12 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_IECU_HSC4_FrP01_PP_P2P_IECU_HSC4_FrP01_Tx_c4eea277_b771686b] */
  { /*    13 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_IECU_HSC4_FrP02_PP_P2P_IECU_HSC4_FrP02_Tx_c4eea277_b771686b] */
  { /*    14 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_BCM_FrP03_PP_P2P_SecCH_BCM_FrP03_Tx_427ad0d9_2e7839d1] */
  { /*    15 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_BCM_FrP04_PP_P2P_SecCH_BCM_FrP04_Tx_427ad0d9_2e7839d1] */
  { /*    16 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_BCM_FrP07_PP_P2P_SecCH_BCM_FrP07_Tx_427ad0d9_2e7839d1] */
  { /*    17 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_ECM_FrP00_PP_P2P_SecCH_ECM_FrP00_Tx_427ad0d9_2e7839d1] */
  { /*    18 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_EPB_FrP00_PP_P2P_SecCH_EPB_FrP00_Tx_427ad0d9_2e7839d1] */
  { /*    19 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_EPB_FrP01_PP_P2P_SecCH_EPB_FrP01_Tx_427ad0d9_2e7839d1] */
  { /*    20 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_EPS_FrP02_PP_P2P_SecCH_EPS_FrP02_Tx_427ad0d9_2e7839d1] */
  { /*    21 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_FICM_FrP02_PP_P2P_SecCH_FICM_FrP02_Tx_427ad0d9_2e7839d1] */
  { /*    22 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_FICM_FrP08_PP_P2P_SecCH_FICM_FrP08_Tx_427ad0d9_2e7839d1] */
  { /*    23 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_FICM_FrP18_PP_P2P_SecCH_FICM_FrP18_Tx_427ad0d9_2e7839d1] */
  { /*    24 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_GW_FrP00_PP_P2P_SecCH_GW_FrP00_Tx_427ad0d9_2e7839d1] */
  { /*    25 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_GW_FrP01_PP_P2P_SecCH_GW_FrP01_Tx_427ad0d9_2e7839d1] */
  { /*    26 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_GW_FrP08_PP_P2P_SecCH_GW_FrP08_Tx_427ad0d9_2e7839d1] */
  { /*    27 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_GW_FrP10_PP_P2P_SecCH_GW_FrP10_Tx_427ad0d9_2e7839d1] */
  { /*    28 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_GW_FrP13_PP_P2P_SecCH_GW_FrP13_Tx_427ad0d9_2e7839d1] */
  { /*    29 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_GW_FrS00_PP_P2P_SecCH_GW_FrS00_Tx_427ad0d9_2e7839d1] */
  { /*    30 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_HCU_ECM_FrP04_PP_P2P_SecCH_HCU_ECM_FrP04_Tx_427ad0d9_2e7839d1] */
  { /*    31 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_HCU_FrP00_PP_P2P_SecCH_HCU_FrP00_Tx_427ad0d9_2e7839d1] */
  { /*    32 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_HCU_FrP01_PP_P2P_SecCH_HCU_FrP01_Tx_427ad0d9_2e7839d1] */
  { /*    33 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_HCU_FrP13_PP_P2P_SecCH_HCU_FrP13_Tx_427ad0d9_2e7839d1] */
  { /*    34 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_IPK_FrP06_PP_P2P_SecCH_IPK_FrP06_Tx_427ad0d9_2e7839d1] */
  { /*    35 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SAS_FrP00_PP_P2P_SecCH_SAS_FrP00_Tx_427ad0d9_2e7839d1] */
  { /*    36 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SCS_FrP00_PP_P2P_SecCH_SCS_FrP00_Tx_427ad0d9_2e7839d1] */
  { /*    37 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SCS_FrP01_PP_P2P_SecCH_SCS_FrP01_Tx_427ad0d9_2e7839d1] */
  { /*    38 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SCS_FrP02_PP_P2P_SecCH_SCS_FrP02_Tx_427ad0d9_2e7839d1] */
  { /*    39 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SCS_FrP03_PP_P2P_SecCH_SCS_FrP03_Tx_427ad0d9_2e7839d1] */
  { /*    40 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SCS_FrP05_PP_P2P_SecCH_SCS_FrP05_Tx_427ad0d9_2e7839d1] */
  { /*    41 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SCS_FrP11_PP_P2P_SecCH_SCS_FrP11_Tx_427ad0d9_2e7839d1] */
  { /*    42 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SCS_FrP12_PP_P2P_SecCH_SCS_FrP12_Tx_427ad0d9_2e7839d1] */
  { /*    43 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SCS_FrP15_PP_P2P_SecCH_SCS_FrP15_Tx_427ad0d9_2e7839d1] */
  { /*    44 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SCU_FrP00_PP_P2P_SecCH_SCU_FrP00_Tx_427ad0d9_2e7839d1] */
  { /*    45 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_SDM_FrP00_PP_P2P_SecCH_SDM_FrP00_Tx_427ad0d9_2e7839d1] */
  { /*    46 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_TC_FrP07_PP_P2P_SecCH_TC_FrP07_Tx_427ad0d9_2e7839d1] */
  { /*    47 */                  PDUR_NO_DESTHNDOFTXIF2UP, PDUR_NO_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP }   /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_P2P_SecCH_Tester_GW_FrP14_PP_P2P_SecCH_Tester_GW_FrP14_Tx_427ad0d9_2e7839d1] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Initialized
**********************************************************************************************************************/
/** 
  \var    PduR_Initialized
  \brief  Initialization state of PduR. TRUE, if PduR_Init() has been called, else FALSE
*/ 
#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized = FALSE;
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define PDUR_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* Upper Layer Interface APIs */

/**********************************************************************************************************************
 * PduR_ComTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if  transmit function used for this routing
 *       - #40 if routing path group is enabled
 *         - #41 get destination handle
 *         - #42 call gateway or lower layer tranmsit function
 *   - #40 else arguments check fails
 *     - #41 call DET
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_TX2LO == STD_ON)
  else if((id >= PduR_GetSizeOfTx2Lo())
#  if (PDUR_INVALIDHNDOFTX2LO == STD_ON)
          || (PduR_IsInvalidHndOfTx2Lo(id))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_TX2LO == STD_ON) */
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if (PDUR_TX2LO == STD_ON)
# if (PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO == STD_ON)
    if(PduR_IsBswMPduRTransmitCallbackOfTx2Lo(id))
    {
      BswM_PduR_Transmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
# endif /* (PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO == STD_ON) */
# if (PDUR_RMDESTRPGROMIDXOFTX2LO == STD_ON)
    if((!PduR_IsRmDestRpgRomUsedOfTx2Lo(id)) || (0 != PduR_GetEnabledCntOfRpgDestState(PduR_GetRmDestRpgRomIdxOfTx2Lo(id)))) /* PRQA S 3355, 3356 */ /* MD_CSL_3355_3356 */ /* COV_PDUR_RPG_FEATURE_CHECK */
# endif
    {
      PduR_DestHndOfTx2LoType destHnd = PduR_GetDestHndOfTx2Lo(id);
      retVal = PduR_GetTransmitFctPtr(PduR_GetTransmitFctPtrIdxOfTx2Lo(id))(destHnd, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
#else
# if (PDUR_USE_DUMMY_STATEMENT == STD_ON)
    id = id;
    info = info;
# endif
#endif /* (PDUR_TX2LO == STD_ON) */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_COMTX, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(id);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(info); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_DcmTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if  transmit function used for this routing
 *       - #40 if routing path group is enabled
 *         - #41 get destination handle
 *         - #42 call gateway or lower layer tranmsit function
 *   - #40 else arguments check fails
 *     - #41 call DET
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_TX2LO == STD_ON)
  else if((id >= PduR_GetSizeOfTx2Lo())
#  if (PDUR_INVALIDHNDOFTX2LO == STD_ON)
          || (PduR_IsInvalidHndOfTx2Lo(id))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_TX2LO == STD_ON) */
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if (PDUR_TX2LO == STD_ON)
# if (PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO == STD_ON)
    if(PduR_IsBswMPduRTransmitCallbackOfTx2Lo(id))
    {
      BswM_PduR_Transmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
# endif /* (PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO == STD_ON) */
# if (PDUR_RMDESTRPGROMIDXOFTX2LO == STD_ON)
    if((!PduR_IsRmDestRpgRomUsedOfTx2Lo(id)) || (0 != PduR_GetEnabledCntOfRpgDestState(PduR_GetRmDestRpgRomIdxOfTx2Lo(id)))) /* PRQA S 3355, 3356 */ /* MD_CSL_3355_3356 */ /* COV_PDUR_RPG_FEATURE_CHECK */
# endif
    {
      PduR_DestHndOfTx2LoType destHnd = PduR_GetDestHndOfTx2Lo(id);
      retVal = PduR_GetTransmitFctPtr(PduR_GetTransmitFctPtrIdxOfTx2Lo(id))(destHnd, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
#else
# if (PDUR_USE_DUMMY_STATEMENT == STD_ON)
    id = id;
    info = info;
# endif
#endif /* (PDUR_TX2LO == STD_ON) */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_DCMTX, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(id);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(info); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
}


/* Communication Interface APIs */

/**********************************************************************************************************************
 * PduR_CanIfRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if BSWM callback is active
 *       - #31 call BSWM callback function
 *     - #40 if routing path group is enabled
 *       - #41 get destination handle
 *       - #42 call the gateway communication interface Rx Indication function
 *   - #50 else arguments check fails
 *     - #51 call DET
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_RXIF2DEST == STD_ON)
  else if((RxPduId >= PduR_GetSizeOfRxIf2Dest())
#  if (PDUR_INVALIDHNDOFRXIF2DEST == STD_ON)
    || (PduR_IsInvalidHndOfRxIf2Dest(RxPduId))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_RXIF2DEST == STD_ON) */
#endif
  else
  {
    /* #20 ----- Implementation ----------------------------------------------- */
#if (PDUR_RXIF2DEST == STD_ON)
    /* #30 BSWM callback */
# if (PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST == STD_ON)
    if(PduR_IsBswMPduRRxIndicationCallbackOfRxIf2Dest(RxPduId))
    {
      /* #31 */
      BswM_PduR_RxIndication(RxPduId, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
# endif /* (PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST == STD_ON) */
# if (PDUR_RMDESTRPGROMIDXOFRXIF2DEST == STD_ON)
    /* #40 */
    if((!PduR_IsRmDestRpgRomUsedOfRxIf2Dest(RxPduId)) || (0 != PduR_GetEnabledCntOfRpgDestState(PduR_GetRmDestRpgRomIdxOfRxIf2Dest(RxPduId)))) /* PRQA S 3355, 3356 */ /* MD_CSL_3355_3356 */ /* COV_PDUR_RPG_FEATURE_CHECK */
# endif
    {
      PduR_DestHndOfRxIf2DestType destHnd = PduR_GetDestHndOfRxIf2Dest(RxPduId);
      PduR_GetIfRxIndicationFctPtr(PduR_GetIfRxIndicationFctPtrIdxOfRxIf2Dest(RxPduId))(destHnd, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
#endif /* (PDUR_RXIF2DEST == STD_ON) */
  }

  /* #50 ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    /* #51 */
    PduR_Det_ReportError(PDUR_FCT_CANIFRXIND, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(RxPduId);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(info); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_LinIfRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if BSWM callback is active
 *       - #31 call BSWM callback function
 *     - #40 if routing path group is enabled
 *       - #41 get destination handle
 *       - #42 call the gateway communication interface Rx Indication function
 *   - #50 else arguments check fails
 *     - #51 call DET
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_LinIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_RXIF2DEST == STD_ON)
  else if((RxPduId >= PduR_GetSizeOfRxIf2Dest())
#  if (PDUR_INVALIDHNDOFRXIF2DEST == STD_ON)
    || (PduR_IsInvalidHndOfRxIf2Dest(RxPduId))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_RXIF2DEST == STD_ON) */
#endif
  else
  {
    /* #20 ----- Implementation ----------------------------------------------- */
#if (PDUR_RXIF2DEST == STD_ON)
    /* #30 BSWM callback */
# if (PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST == STD_ON)
    if(PduR_IsBswMPduRRxIndicationCallbackOfRxIf2Dest(RxPduId))
    {
      /* #31 */
      BswM_PduR_RxIndication(RxPduId, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
# endif /* (PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST == STD_ON) */
# if (PDUR_RMDESTRPGROMIDXOFRXIF2DEST == STD_ON)
    /* #40 */
    if((!PduR_IsRmDestRpgRomUsedOfRxIf2Dest(RxPduId)) || (0 != PduR_GetEnabledCntOfRpgDestState(PduR_GetRmDestRpgRomIdxOfRxIf2Dest(RxPduId)))) /* PRQA S 3355, 3356 */ /* MD_CSL_3355_3356 */ /* COV_PDUR_RPG_FEATURE_CHECK */
# endif
    {
      PduR_DestHndOfRxIf2DestType destHnd = PduR_GetDestHndOfRxIf2Dest(RxPduId);
      PduR_GetIfRxIndicationFctPtr(PduR_GetIfRxIndicationFctPtrIdxOfRxIf2Dest(RxPduId))(destHnd, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
#endif /* (PDUR_RXIF2DEST == STD_ON) */
  }

  /* #50 ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    /* #51 */
    PduR_Det_ReportError(PDUR_FCT_LINIFRXIND, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(RxPduId);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(info); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_LinIfTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if BSWM callback is active
 *       - #31 call BSWM callback function
 *     - #40 if confirmation function used for this routing
 *       - #41 get destination handle
 *       - #42 call the gateway or communication interface confirmation function
 *   - #50 else arguments check fails
 *     - #51 call DET
 * \endinternal
 *********************************************************************************************************************/
/* PRQA S 6080 PDUR_LLIF_TXCONFIRMATION */ /* MD_MSR_STMIF */
FUNC(void, PDUR_CODE) PduR_LinIfTxConfirmation(PduIdType TxPduId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;

  /*  #10 ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_TXIF2UP == STD_ON)
  else if((TxPduId >= PduR_GetSizeOfTxIf2Up())
#  if (PDUR_INVALIDHNDOFTXIF2UP == STD_ON)
    || (PduR_IsInvalidHndOfTxIf2Up(TxPduId))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_TXIF2UP == STD_ON) */
#endif
  else
  {
    /* #20 ----- Implementation ----------------------------------------------- */
#if (PDUR_TXIF2UP == STD_ON)
    /* #30 BSWM callback */
# if (PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP == STD_ON)
    if(PduR_IsBswMPduRTxConfirmationCallbackOfTxIf2Up(TxPduId))
    {
      /* #31 */
      BswM_PduR_TxConfirmation(TxPduId);
    }
# endif /* (PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP == STD_ON) */
# if ( PDUR_IFTXCONFIRMATIONFCTPTRUSEDOFTXIF2UP == STD_ON )
    /* #40 */
    if(PduR_IsIfTxConfirmationFctPtrUsedOfTxIf2Up(TxPduId)) /* PRQA S 3355 */ /* MD_CSL_3355_3356 */ /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
      PduR_DestHndOfTxIf2UpType destHnd = PduR_GetDestHndOfTxIf2Up(TxPduId);
      PduR_GetIfTxConfirmationFctPtr(PduR_GetIfTxConfirmationFctPtrIdxOfTxIf2Up(TxPduId))(destHnd); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY */
    }
# endif
#endif /* (PDUR_TXIF2UP == STD_ON) */
  }

  /* #50 ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_LINIFTXCFM, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(TxPduId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
}
/* PRQA L:PDUR_LLIF_TXCONFIRMATION */



/**********************************************************************************************************************
 * PduR_LinIfTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if trigger transmit function used for this routing
 *       - #31 get destination handle
 *       - #32 call the gateway or communication interface trigger transmit function
 *   - #33 else call DET
 *   - #50 else arguments check fails
 *     - #51 call DET
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_LinIfTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_TXIF2UP == STD_ON)
  else if((TxPduId >= PduR_GetSizeOfTxIf2Up())
#  if (PDUR_INVALIDHNDOFTXIF2UP == STD_ON)
    || (PduR_IsInvalidHndOfTxIf2Up(TxPduId))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_TXIF2UP == STD_ON) */
#endif
  else
  {
    /* #20 ----- Implementation ----------------------------------------------- */
#if (PDUR_TXIF2UP == STD_ON)
# if (PDUR_DESTHNDOFTXIF2UP == STD_ON) && (PDUR_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP == STD_ON)
    /* #30 */
    if(PduR_IsIfTriggerTransmitFctPtrUsedOfTxIf2Up(TxPduId)) /* PRQA S 3355 */ /* MD_CSL_3355_3356 */ /* COV_PDUR_FEATURE_ALWAYS_TRUE */
    {
      PduR_DestHndOfTxIf2UpType destHnd = PduR_GetDestHndOfTxIf2Up(TxPduId);
      retVal = PduR_GetIfTriggerTransmitFctPtr(PduR_GetIfTriggerTransmitFctPtrIdxOfTxIf2Up(TxPduId))(destHnd, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
#  if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
    else
    {
      errorId = PDUR_E_PDU_ID_INVALID;
    }
#  endif
# endif
#endif /* (PDUR_TXIF2UP == STD_ON) */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_LINIFTT, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(TxPduId);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(info); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
}


/* Transport Protocol APIs */

/**********************************************************************************************************************
 * PduR_CanTpStartOfReception
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if routing path group is enabled
 *      - #31 get destination handle
 *      - #32 call the gateway or Tp module start of reception function
 *   - #40 else arguments check fails
 *     - #41 call DET
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_RXTP2DEST == STD_ON)
  else if((id >= PduR_GetSizeOfRxTp2Dest())
#  if (PDUR_INVALIDHNDOFRXTP2DEST == STD_ON)
    || (PduR_IsInvalidHndOfRxTp2Dest(id))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_RXTP2DEST == STD_ON) */
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if (PDUR_RXTP2DEST == STD_ON)
# if (PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST == STD_ON)
    if(PduR_IsBswMPduRTpStartOfReceptionCallbackOfRxTp2Dest(id))
    {
      BswM_PduR_TpStartOfReception(id, info, TpSduLength, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
# endif /* (PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST == STD_ON) */
# if (PDUR_RMDESTRPGROMIDXOFRXTP2DEST == STD_ON)
    if((!PduR_IsRmDestRpgRomUsedOfRxTp2Dest(id)) || (0 != PduR_GetEnabledCntOfRpgDestState(PduR_GetRmDestRpgRomIdxOfRxTp2Dest(id)))) /* PRQA S 3355, 3356 */ /* MD_CSL_3355_3356 */ /* COV_PDUR_RPG_FEATURE_CHECK */
# endif
    {
      PduR_DestHndOfRxTp2DestType destHnd = PduR_GetDestHndOfRxTp2Dest(id);
      retVal = PduR_GetStartOfReceptionFctPtr(PduR_GetStartOfReceptionFctPtrIdxOfRxTp2Dest(id))(destHnd, info, TpSduLength, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
#endif /* (PDUR_RXTP2DEST == STD_ON) */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CANTPSOR, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(id);            /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);          /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(TpSduLength);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyRxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if routing path group is enabled
 *      - #31 get destination handle
 *      - #32 call the gateway or Tp module CopyRxData function
 *   - #40 else arguments check fails
 *     - #41 call DET
 * \endinternal
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_PduR_3673_AsrProto */
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

  /* #10 ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_RXTP2DEST == STD_ON)
  else if((id >= PduR_GetSizeOfRxTp2Dest())
#  if (PDUR_INVALIDHNDOFRXTP2DEST == STD_ON)
    || (PduR_IsInvalidHndOfRxTp2Dest(id))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_RXTP2DEST == STD_ON) */
#endif
  else
  {
    /* #20 ----- Implementation ----------------------------------------------- */
#if (PDUR_RXTP2DEST == STD_ON)
# if (PDUR_RMDESTRPGROMIDXOFRXTP2DEST == STD_ON)
    /* #30 */
    if((!PduR_IsRmDestRpgRomUsedOfRxTp2Dest(id)) || (0 != PduR_GetEnabledCntOfRpgDestState(PduR_GetRmDestRpgRomIdxOfRxTp2Dest(id)))) /* PRQA S 3355, 3356 */ /* MD_CSL_3355_3356 */ /* COV_PDUR_RPG_FEATURE_CHECK */
# endif
    {
      PduR_DestHndOfRxTp2DestType destHnd = PduR_GetDestHndOfRxTp2Dest(id);
      retVal = PduR_GetCopyRxDataFctPtr(PduR_GetCopyRxDataFctPtrIdxOfRxTp2Dest(id))(destHnd, info, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
#else
#  if (PDUR_USE_DUMMY_STATEMENT == STD_ON)
    id = id;
    info = info;
    bufferSizePtr = bufferSizePtr;
#  endif
#endif /* (PDUR_RXTP2DEST == STD_ON) */
  }

  /* #40 ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CANTPCPYRX, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(id);            /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);          /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyTxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if routing path group is enabled
 *      - #31 get destination handle
 *      - #32 call the gateway or Tp module copy tx data function 
 *   - #40 else arguments check fails
 *     - #41 call DET
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_TXTP2SRC == STD_ON)
  else if((id >= PduR_GetSizeOfTxTp2Src())
#  if (PDUR_INVALIDHNDOFTXTP2SRC == STD_ON)
    || (PduR_IsInvalidHndOfTxTp2Src(id))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_RXTP2UP == STD_ON) */
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if (PDUR_TXTP2SRC == STD_ON)
# if (PDUR_RMDESTRPGROMIDXOFTXTP2SRC == STD_ON)
    if((!PduR_IsRmDestRpgRomUsedOfTxTp2Src(id)) || (0 != PduR_GetEnabledCntOfRpgDestState(PduR_GetRmDestRpgRomIdxOfTxTp2Src(id)))) /* PRQA S 3355, 3356 */ /* MD_CSL_3355_3356 */ /* COV_PDUR_RPG_FEATURE_CHECK */
# endif
    {
      PduR_SrcHndOfTxTp2SrcType srcHnd = PduR_GetSrcHndOfTxTp2Src(id);
      retVal = PduR_GetCopyTxDataFctPtr(PduR_GetCopyTxDataFctPtrIdxOfTxTp2Src(id))(srcHnd, info, retry, availableDataPtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR */
    }
#endif /* (PDUR_RXTP2UP == STD_ON) */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CANTPCPYTX, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(id);               /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);             /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(retry);            /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(availableDataPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #21 get destination handle
 *     - #30 if BSWM callback is active
 *       - #31 call BSWM callback function
 *     - #22 call the gateway or tansport protocol indication function 
 *   - #50 else arguments check fails
 *     - #51 call DET
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;

  /* #10 ----- Development Error Checks ------------------------------------- */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_RXTP2DEST == STD_ON)
  else if((id >= PduR_GetSizeOfRxTp2Dest())
#  if (PDUR_INVALIDHNDOFRXTP2DEST == STD_ON)
    || (PduR_IsInvalidHndOfRxTp2Dest(id))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_RXTP2DEST == STD_ON) */
#endif
  else
  {
    /*  #20 ----- Implementation ----------------------------------------------- */
#if (PDUR_RXTP2DEST == STD_ON)
# if (PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST == STD_ON)
    /* #30 BSWM callback */
    if(PduR_IsBswMPduRTpRxIndicationCallbackOfRxTp2Dest(id))
    {
      /* #31 */
      BswM_PduR_TpRxIndication(id, result);
    }
# endif /* (PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST == STD_ON) */
    PduR_GetTpRxIndicationFctPtr(PduR_GetTpRxIndicationFctPtrIdxOfRxTp2Dest(id))(PduR_GetDestHndOfRxTp2Dest(id), result); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY */
#endif
  }

  /* #50 ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CANTPRXIND, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanTpTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Check arguments
 *   - #20 if arguments check was successfully
 *     - #30 if BSWM callback is active
 *       - #31 call BSWM callback function
 *     - #22 call the gateway or the tp module tx confirmaation function
 *   - #50 else arguments check fails
 *     - #51 call DET
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = PDUR_E_NO_ERROR;

  /* #10 ----- Development Error Checks ------------------------------------- */
  /* Check initialization state of the component */
  if(PduR_IsInitialized() == FALSE)
  {
    errorId = PDUR_E_INVALID_REQUEST;
  }
#if (PDUR_DEV_ERROR_DETECT == STD_ON) /* COV_PDUR_VAR_DEV_ERROR_DETECT */
# if (PDUR_TXTP2SRC == STD_ON)
  else if((id >= PduR_GetSizeOfTxTp2Src())
#  if (PDUR_INVALIDHNDOFTXTP2SRC == STD_ON)
    || (PduR_IsInvalidHndOfTxTp2Src(id))
#  endif
  )
  {
    errorId = PDUR_E_PDU_ID_INVALID;
  }
# endif /* (PDUR_TXTP2SRC == STD_ON) */
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if (PDUR_TXTP2SRC == STD_ON)
# if (PDUR_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC == STD_ON)
    /* #30 BSWM callback */
    if(PduR_IsBswMPduRTpTxConfirmationCallbackOfTxTp2Src(id))
    {
      /* #31 */
      BswM_PduR_TpTxConfirmation(id, result);
    }
# endif /* (PDUR_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC == STD_ON) */
    PduR_GetTpTxConfirmationFctPtr(PduR_GetTpTxConfirmationFctPtrIdxOfTxTp2Src(id))(PduR_GetSrcHndOfTxTp2Src(id), result); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY */
#endif /* (PDUR_TXTP2SRC == STD_ON) */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (PDUR_DEV_ERROR_REPORT == STD_ON)
  if(errorId != PDUR_E_NO_ERROR)
  {
    PduR_Det_ReportError(PDUR_FCT_CANTPTXCFM, errorId);
  }
#else
  PDUR_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
}


/* CancelReceive global without UseTag API */

/* ChangeParameter global without UseTag  API */

/* Communication Interface / Transport Protocol APIs */

/* Communication Interface / Transport Protocol APIs */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


#define PDUR_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR
    \DESCRIPTION    The API is called with an Id and a pointer.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \N The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       The pointer is provided by the lower layer and is assumed to be valid. It is passed as is to the corresponding function. 

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY
    \DESCRIPTION    The API is called with an Id.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \R The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.

 SBSW_JUSTIFICATION_END */

/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.c
 *********************************************************************************************************************/

