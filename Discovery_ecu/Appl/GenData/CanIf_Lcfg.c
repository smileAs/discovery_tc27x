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
 *            Module: CanIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2018-08-21 08:49:56
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

#define CANIF_LCFG_SOURCE

/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 0857 EOF */ /* MD_CanIf_1.1_NumberOfMacroDefinitions */
/* PRQA S 0779 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 0777 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 1330, 1334 EOF */ /* MD_CanIf_16.4, MD_CanIf_16.4 */

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  PduR Header Files  */ 
#include "PduR_Cfg.h"
#include "PduR_CanIf.h"
 /*  CanSM Header Files  */ 
#include "CanSM_Cbk.h"

#define CANIF_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/





#define CANIF_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = CanSM_ControllerBusOff;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[3] = {
    /* Index    MappedTxBuffersConfigEndIdx                                                 MappedTxBuffersConfigStartIdx                                                       Referable Keys */
  { /*     0 */                         1UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,                           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */ },  /* [/ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     1 */                         0UL  /* CanChannelWithoutTxBuffer */              ,                           0UL  /* CanChannelWithoutTxBuffer */               },  /* [/ActiveEcuC/CanIf/Can/CT_CAN01_388e5969] */
  { /*     2 */                         0UL  /* CanChannelWithoutTxBuffer */              ,                           0UL  /* CanChannelWithoutTxBuffer */               }   /* [/ActiveEcuC/CanIf/Can/CT_CAN02_388e5969] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = CanSM_ControllerModeIndication;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[6] = {
    /* Index    CtrlStatesIdx                                                 PduIdFirst                            PduIdLast                            TxBufferCfgIdx                                                                                               TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,         0U  /* Unused, TxPduId 0 */ ,        0U  /* Unused, TxPduId 8 */ ,                                    0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2 */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std] */
  { /*     1 */           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,         0U  /* RxPduId */           ,       35U  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                                 , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Rx_Std] */
  { /*     2 */           1UL  /* /ActiveEcuC/CanIf/Can/CT_CAN01_388e5969 */,         0U  /* Unused, TxPduId 9 */ ,        0U  /* Unused, TxPduId 12 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex2 */                                                 , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN01_388e5969_Tx_Std] */
  { /*     3 */           1UL  /* /ActiveEcuC/CanIf/Can/CT_CAN01_388e5969 */,        36U  /* RxPduId */           ,       55U  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex3 */                                                 , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN01_388e5969_Rx_Std] */
  { /*     4 */           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,         0U  /* Unused, TxPduId 13 */,        0U  /* Unused, TxPduId 46 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex4 */                                                 , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std] */
  { /*     5 */           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,        56U  /* RxPduId */           ,       63U  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex5 */                                                 , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Rx_Std] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {
    /* Index    MailBoxConfigIdx                                                                     Referable Keys */
  { /*     0 */              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */ }   /* [/ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[3] = {
    /* Index    RxIndicationFct                                               RxIndicationLayout                                                            Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }              , CanIf_SimpleRxIndicationLayout    /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [CanTp_RxIndication] */
  { /*     2 */  { (CanIf_SimpleRxIndicationFctType)PduR_CanIfRxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ }   /* [PduR_CanIfRxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  Dlc                       Data length code.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[64] = {
    /* Index    RxPduCanId                                                                  RxPduMask                                                  UpperPduId                                                     Dlc  RxIndicationFctListIdx                                      Comment                                                                  Referable Keys */
  { /*     0 */    0x07DFU  /* DIAG_FuncReq_HSC2_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x47FFU  /* DIAG_FuncReq_HSC2_oCAN00_Rx_3abd61be */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu                            ,  8U,                    1UL  /* CanTp_RxIndication */     },  /* [PDU: DIAG_FuncReq_HSC2_oCAN00_Rx_3abd61be, CanId: 0x7df]    */  /* [CanIfConf_CanIfRxPduCfg_DIAG_FuncReq_HSC2_oCAN00_Rx_3abd61be] */
  { /*     1 */    0x0736U  /* DIAG_PhysReq_P2P_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */     ,   0x07FFU  /* DIAG_PhysReq_P2P_oCAN00_Rx_3abd61be */     , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1                          ,  8U,                    1UL  /* CanTp_RxIndication */     },  /* [PDU: DIAG_PhysReq_P2P_oCAN00_Rx_3abd61be, CanId: 0x736]     */  /* [CanIfConf_CanIfRxPduCfg_DIAG_PhysReq_P2P_oCAN00_Rx_3abd61be] */
  { /*     2 */    0x06A3U  /* GW_HSC2_FrS00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */        ,   0x07FFU  /* GW_HSC2_FrS00_oCAN00_Rx_3abd61be */        , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrS00_0fb271d2        ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_FrS00_oCAN00_Rx_3abd61be, CanId: 0x6a3]        */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_FrS00_oCAN00_Rx_3abd61be] */
  { /*     3 */    0x0603U  /* GW_HSC2_BCM_FrS16_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_BCM_FrS16_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_BCM_FrS16_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_BCM_FrS16_oCAN00_Rx_3abd61be, CanId: 0x603]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_BCM_FrS16_oCAN00_Rx_3abd61be] */
  { /*     4 */    0x0541U  /* GW_HSC2_IPK_FrP06_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_IPK_FrP06_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_IPK_FrP06_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_IPK_FrP06_oCAN00_Rx_3abd61be, CanId: 0x541]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_IPK_FrP06_oCAN00_Rx_3abd61be] */
  { /*     5 */    0x0540U  /* GW_HSC2_FrP08_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */        ,   0x07FFU  /* GW_HSC2_FrP08_oCAN00_Rx_3abd61be */        , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP08_0fb271d2        ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_FrP08_oCAN00_Rx_3abd61be, CanId: 0x540]        */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_FrP08_oCAN00_Rx_3abd61be] */
  { /*     6 */    0x046AU  /* GW_HSC2_BCM_FrP04_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_BCM_FrP04_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_BCM_FrP04_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_BCM_FrP04_oCAN00_Rx_3abd61be, CanId: 0x46a]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_BCM_FrP04_oCAN00_Rx_3abd61be] */
  { /*     7 */    0x03F1U  /* GW_HSC2_FrP10_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */        ,   0x07FFU  /* GW_HSC2_FrP10_oCAN00_Rx_3abd61be */        , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP10_0fb271d2        ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_FrP10_oCAN00_Rx_3abd61be, CanId: 0x3f1]        */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_FrP10_oCAN00_Rx_3abd61be] */
  { /*     8 */    0x0376U  /* GW_HSC2_FICM_FrP02_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */   ,   0x07FFU  /* GW_HSC2_FICM_FrP02_oCAN00_Rx_3abd61be */   , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FICM_FrP02_0fb271d2   ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_FICM_FrP02_oCAN00_Rx_3abd61be, CanId: 0x376]   */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_FICM_FrP02_oCAN00_Rx_3abd61be] */
  { /*     9 */    0x0353U  /* SCS_HSC2_FrP15_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* SCS_HSC2_FrP15_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP15_0fb271d2       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SCS_HSC2_FrP15_oCAN00_Rx_3abd61be, CanId: 0x353]       */  /* [CanIfConf_CanIfRxPduCfg_SCS_HSC2_FrP15_oCAN00_Rx_3abd61be] */
  { /*    10 */    0x034AU  /* SCS_HSC2_FrP12_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* SCS_HSC2_FrP12_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP12_0fb271d2       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SCS_HSC2_FrP12_oCAN00_Rx_3abd61be, CanId: 0x34a]       */  /* [CanIfConf_CanIfRxPduCfg_SCS_HSC2_FrP12_oCAN00_Rx_3abd61be] */
  { /*    11 */    0x0348U  /* SCS_HSC2_FrP11_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* SCS_HSC2_FrP11_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP11_0fb271d2       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SCS_HSC2_FrP11_oCAN00_Rx_3abd61be, CanId: 0x348]       */  /* [CanIfConf_CanIfRxPduCfg_SCS_HSC2_FrP11_oCAN00_Rx_3abd61be] */
  { /*    12 */    0x02F6U  /* GW_HSC2_FICM_FrP08_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */   ,   0x07FFU  /* GW_HSC2_FICM_FrP08_oCAN00_Rx_3abd61be */   , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FICM_FrP08_0fb271d2   ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_FICM_FrP08_oCAN00_Rx_3abd61be, CanId: 0x2f6]   */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_FICM_FrP08_oCAN00_Rx_3abd61be] */
  { /*    13 */    0x0230U  /* EPB_HSC2_FrP00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* EPB_HSC2_FrP00_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_EPB_HSC2_FrP00_0fb271d2       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: EPB_HSC2_FrP00_oCAN00_Rx_3abd61be, CanId: 0x230]       */  /* [CanIfConf_CanIfRxPduCfg_EPB_HSC2_FrP00_oCAN00_Rx_3abd61be] */
  { /*    14 */    0x022AU  /* EPB_HSC2_FrP01_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* EPB_HSC2_FrP01_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_EPB_HSC2_FrP01_0fb271d2       ,  2U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: EPB_HSC2_FrP01_oCAN00_Rx_3abd61be, CanId: 0x22a]       */  /* [CanIfConf_CanIfRxPduCfg_EPB_HSC2_FrP01_oCAN00_Rx_3abd61be] */
  { /*    15 */    0x021CU  /* GW_HSC2_BCM_FrP06_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_BCM_FrP06_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_BCM_FrP06_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_BCM_FrP06_oCAN00_Rx_3abd61be, CanId: 0x21c]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_BCM_FrP06_oCAN00_Rx_3abd61be] */
  { /*    16 */    0x01F2U  /* GW_HSC2_BCM_FrP07_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_BCM_FrP07_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_BCM_FrP07_0fb271d2    ,  2U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_BCM_FrP07_oCAN00_Rx_3abd61be, CanId: 0x1f2]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_BCM_FrP07_oCAN00_Rx_3abd61be] */
  { /*    17 */    0x01F1U  /* GW_HSC2_FrP01_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */        ,   0x07FFU  /* GW_HSC2_FrP01_oCAN00_Rx_3abd61be */        , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP01_0fb271d2        ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_FrP01_oCAN00_Rx_3abd61be, CanId: 0x1f1]        */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_FrP01_oCAN00_Rx_3abd61be] */
  { /*    18 */    0x01E9U  /* SCS_HSC2_FrP05_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* SCS_HSC2_FrP05_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP05_0fb271d2       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SCS_HSC2_FrP05_oCAN00_Rx_3abd61be, CanId: 0x1e9]       */  /* [CanIfConf_CanIfRxPduCfg_SCS_HSC2_FrP05_oCAN00_Rx_3abd61be] */
  { /*    19 */    0x01E5U  /* SAS_HSC2_FrP00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* SAS_HSC2_FrP00_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_SAS_HSC2_FrP00_0fb271d2       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SAS_HSC2_FrP00_oCAN00_Rx_3abd61be, CanId: 0x1e5]       */  /* [CanIfConf_CanIfRxPduCfg_SAS_HSC2_FrP00_oCAN00_Rx_3abd61be] */
  { /*    20 */    0x01C7U  /* SCS_HSC2_FrP03_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* SCS_HSC2_FrP03_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP03_0fb271d2       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SCS_HSC2_FrP03_oCAN00_Rx_3abd61be, CanId: 0x1c7]       */  /* [CanIfConf_CanIfRxPduCfg_SCS_HSC2_FrP03_oCAN00_Rx_3abd61be] */
  { /*    21 */    0x01B6U  /* EHBS_HSC2_FrP00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* EHBS_HSC2_FrP00_oCAN00_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_EHBS_HSC2_FrP00_0fb271d2      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: EHBS_HSC2_FrP00_oCAN00_Rx_3abd61be, CanId: 0x1b6]      */  /* [CanIfConf_CanIfRxPduCfg_EHBS_HSC2_FrP00_oCAN00_Rx_3abd61be] */
  { /*    22 */    0x01B1U  /* EPS_HSC2_FrP02_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* EPS_HSC2_FrP02_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_EPS_HSC2_FrP02_0fb271d2       ,  4U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: EPS_HSC2_FrP02_oCAN00_Rx_3abd61be, CanId: 0x1b1]       */  /* [CanIfConf_CanIfRxPduCfg_EPS_HSC2_FrP02_oCAN00_Rx_3abd61be] */
  { /*    23 */    0x01ADU  /* Tester_HSC2_GW_FrP14_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */ ,   0x07FFU  /* Tester_HSC2_GW_FrP14_oCAN00_Rx_3abd61be */ , PduRConf_PduRSrcPdu_SRC_Can_PT_Tester_HSC2_GW_FrP14_0fb271d2 ,  6U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: Tester_HSC2_GW_FrP14_oCAN00_Rx_3abd61be, CanId: 0x1ad] */  /* [CanIfConf_CanIfRxPduCfg_Tester_HSC2_GW_FrP14_oCAN00_Rx_3abd61be] */
  { /*    24 */    0x01A9U  /* GW_HSC2_FrP13_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */        ,   0x07FFU  /* GW_HSC2_FrP13_oCAN00_Rx_3abd61be */        , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP13_0fb271d2        ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_FrP13_oCAN00_Rx_3abd61be, CanId: 0x1a9]        */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_FrP13_oCAN00_Rx_3abd61be] */
  { /*    25 */    0x019CU  /* GW_HSC2_HCU_FrP13_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_HCU_FrP13_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_HCU_FrP13_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_HCU_FrP13_oCAN00_Rx_3abd61be, CanId: 0x19c]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_HCU_FrP13_oCAN00_Rx_3abd61be] */
  { /*    26 */    0x0196U  /* GW_HSC2_HCU_FrP01_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_HCU_FrP01_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_HCU_FrP01_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_HCU_FrP01_oCAN00_Rx_3abd61be, CanId: 0x196]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_HCU_FrP01_oCAN00_Rx_3abd61be] */
  { /*    27 */    0x0194U  /* GW_HSC2_ECM_FrP04_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_ECM_FrP04_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_ECM_FrP04_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_ECM_FrP04_oCAN00_Rx_3abd61be, CanId: 0x194]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_ECM_FrP04_oCAN00_Rx_3abd61be] */
  { /*    28 */    0x0185U  /* SCS_HSC2_FrP02_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* SCS_HSC2_FrP02_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP02_0fb271d2       ,  4U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SCS_HSC2_FrP02_oCAN00_Rx_3abd61be, CanId: 0x185]       */  /* [CanIfConf_CanIfRxPduCfg_SCS_HSC2_FrP02_oCAN00_Rx_3abd61be] */
  { /*    29 */    0x0169U  /* GW_HSC2_FrP00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */        ,   0x07FFU  /* GW_HSC2_FrP00_oCAN00_Rx_3abd61be */        , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_FrP00_0fb271d2        ,  6U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_FrP00_oCAN00_Rx_3abd61be, CanId: 0x169]        */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_FrP00_oCAN00_Rx_3abd61be] */
  { /*    30 */    0x0163U  /* GW_HSC2_SDM_FrP00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_SDM_FrP00_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_SDM_FrP00_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_SDM_FrP00_oCAN00_Rx_3abd61be, CanId: 0x163]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_SDM_FrP00_oCAN00_Rx_3abd61be] */
  { /*    31 */    0x00C9U  /* Tester_HSC2_ECM_FrP00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */,   0x07FFU  /* Tester_HSC2_ECM_FrP00_oCAN00_Rx_3abd61be */, PduRConf_PduRSrcPdu_SRC_Can_PT_Tester_HSC2_ECM_FrP00_0fb271d2,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: Tester_HSC2_ECM_FrP00_oCAN00_Rx_3abd61be, CanId: 0xc9] */  /* [CanIfConf_CanIfRxPduCfg_Tester_HSC2_ECM_FrP00_oCAN00_Rx_3abd61be] */
  { /*    32 */    0x00C5U  /* SCS_HSC2_FrP01_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* SCS_HSC2_FrP01_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP01_0fb271d2       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SCS_HSC2_FrP01_oCAN00_Rx_3abd61be, CanId: 0xc5]        */  /* [CanIfConf_CanIfRxPduCfg_SCS_HSC2_FrP01_oCAN00_Rx_3abd61be] */
  { /*    33 */    0x00C1U  /* SCS_HSC2_FrP00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* SCS_HSC2_FrP00_oCAN00_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_SCS_HSC2_FrP00_0fb271d2       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SCS_HSC2_FrP00_oCAN00_Rx_3abd61be, CanId: 0xc1]        */  /* [CanIfConf_CanIfRxPduCfg_SCS_HSC2_FrP00_oCAN00_Rx_3abd61be] */
  { /*    34 */    0x00AFU  /* GW_HSC2_HCU_FrP00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_HCU_FrP00_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_HCU_FrP00_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_HCU_FrP00_oCAN00_Rx_3abd61be, CanId: 0xaf]     */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_HCU_FrP00_oCAN00_Rx_3abd61be] */
  { /*    35 */    0x009DU  /* GW_HSC2_SCU_FrP00_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC2_SCU_FrP00_oCAN00_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC2_SCU_FrP00_0fb271d2    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC2_SCU_FrP00_oCAN00_Rx_3abd61be, CanId: 0x9d]     */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC2_SCU_FrP00_oCAN00_Rx_3abd61be] */
  { /*    36 */    0x0611U  /* GW_HSC4_TBOX_FrS10_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */   ,   0x47FFU  /* GW_HSC4_TBOX_FrS10_oCAN01_Rx_3abd61be */   , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_TBOX_FrS10_c4eea277   ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_TBOX_FrS10_oCAN01_Rx_3abd61be, CanId: 0x611]   */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_TBOX_FrS10_oCAN01_Rx_3abd61be] */
  { /*    37 */    0x0541U  /* IPK_HSC4_FrP06_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */       ,   0x07FFU  /* IPK_HSC4_FrP06_oCAN01_Rx_3abd61be */       , PduRConf_PduRSrcPdu_SRC_Can_PT_IPK_HSC4_FrP06_c4eea277       ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: IPK_HSC4_FrP06_oCAN01_Rx_3abd61be, CanId: 0x541]       */  /* [CanIfConf_CanIfRxPduCfg_IPK_HSC4_FrP06_oCAN01_Rx_3abd61be] */
  { /*    38 */    0x047EU  /* TPMS_HSC3_FrP02_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* TPMS_HSC3_FrP02_oCAN01_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_TPMS_HSC3_FrP02_c4eea277      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: TPMS_HSC3_FrP02_oCAN01_Rx_3abd61be, CanId: 0x47e]      */  /* [CanIfConf_CanIfRxPduCfg_TPMS_HSC3_FrP02_oCAN01_Rx_3abd61be] */
  { /*    39 */    0x047DU  /* TPMS_HSC3_FrP01_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* TPMS_HSC3_FrP01_oCAN01_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_TPMS_HSC3_FrP01_c4eea277      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: TPMS_HSC3_FrP01_oCAN01_Rx_3abd61be, CanId: 0x47d]      */  /* [CanIfConf_CanIfRxPduCfg_TPMS_HSC3_FrP01_oCAN01_Rx_3abd61be] */
  { /*    40 */    0x046AU  /* GW_HSC4_BCM_FrP04_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC4_BCM_FrP04_oCAN01_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_BCM_FrP04_c4eea277    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_BCM_FrP04_oCAN01_Rx_3abd61be, CanId: 0x46a]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_BCM_FrP04_oCAN01_Rx_3abd61be] */
  { /*    41 */    0x037DU  /* FICM_HSC4_FrP18_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* FICM_HSC4_FrP18_oCAN01_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP18_c4eea277      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: FICM_HSC4_FrP18_oCAN01_Rx_3abd61be, CanId: 0x37d]      */  /* [CanIfConf_CanIfRxPduCfg_FICM_HSC4_FrP18_oCAN01_Rx_3abd61be] */
  { /*    42 */    0x0376U  /* FICM_HSC4_FrP02_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* FICM_HSC4_FrP02_oCAN01_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP02_c4eea277      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: FICM_HSC4_FrP02_oCAN01_Rx_3abd61be, CanId: 0x376]      */  /* [CanIfConf_CanIfRxPduCfg_FICM_HSC4_FrP02_oCAN01_Rx_3abd61be] */
  { /*    43 */    0x034DU  /* GW_HSC4_TBOX_FrP01_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */   ,   0x07FFU  /* GW_HSC4_TBOX_FrP01_oCAN01_Rx_3abd61be */   , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_TBOX_FrP01_c4eea277   ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_TBOX_FrP01_oCAN01_Rx_3abd61be, CanId: 0x34d]   */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_TBOX_FrP01_oCAN01_Rx_3abd61be] */
  { /*    44 */    0x0336U  /* FICM_HSC4_FrP33_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* FICM_HSC4_FrP33_oCAN01_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP33_c4eea277      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: FICM_HSC4_FrP33_oCAN01_Rx_3abd61be, CanId: 0x336]      */  /* [CanIfConf_CanIfRxPduCfg_FICM_HSC4_FrP33_oCAN01_Rx_3abd61be] */
  { /*    45 */    0x02F6U  /* FICM_HSC4_FrP08_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* FICM_HSC4_FrP08_oCAN01_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP08_c4eea277      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: FICM_HSC4_FrP08_oCAN01_Rx_3abd61be, CanId: 0x2f6]      */  /* [CanIfConf_CanIfRxPduCfg_FICM_HSC4_FrP08_oCAN01_Rx_3abd61be] */
  { /*    46 */    0x02F2U  /* FICM_HSC4_FrP13_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* FICM_HSC4_FrP13_oCAN01_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP13_c4eea277      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: FICM_HSC4_FrP13_oCAN01_Rx_3abd61be, CanId: 0x2f2]      */  /* [CanIfConf_CanIfRxPduCfg_FICM_HSC4_FrP13_oCAN01_Rx_3abd61be] */
  { /*    47 */    0x029BU  /* GW_HSC4_BMS_FrP07_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC4_BMS_FrP07_oCAN01_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_BMS_FrP07_c4eea277    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_BMS_FrP07_oCAN01_Rx_3abd61be, CanId: 0x29b]    */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_BMS_FrP07_oCAN01_Rx_3abd61be] */
  { /*    48 */    0x0239U  /* GW_HSC4_PEPS_FrP02_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */   ,   0x07FFU  /* GW_HSC4_PEPS_FrP02_oCAN01_Rx_3abd61be */   , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_PEPS_FrP02_c4eea277   ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_PEPS_FrP02_oCAN01_Rx_3abd61be, CanId: 0x239]   */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_PEPS_FrP02_oCAN01_Rx_3abd61be] */
  { /*    49 */    0x0204U  /* RDA_HSC4_P02_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */         ,   0x07FFU  /* RDA_HSC4_P02_oCAN01_Rx_3abd61be */         , PduRConf_PduRSrcPdu_SRC_Can_PT_RDA_HSC4_P02_c4eea277         ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: RDA_HSC4_P02_oCAN01_Rx_3abd61be, CanId: 0x204]         */  /* [CanIfConf_CanIfRxPduCfg_RDA_HSC4_P02_oCAN01_Rx_3abd61be] */
    /* Index    RxPduCanId                                                                  RxPduMask                                                  UpperPduId                                                     Dlc  RxIndicationFctListIdx                                      Comment                                                                  Referable Keys */
  { /*    50 */    0x01B2U  /* GW_HSC4_TBOX_FrP05_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */   ,   0x07FFU  /* GW_HSC4_TBOX_FrP05_oCAN01_Rx_3abd61be */   , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_TBOX_FrP05_c4eea277   ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_TBOX_FrP05_oCAN01_Rx_3abd61be, CanId: 0x1b2]   */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_TBOX_FrP05_oCAN01_Rx_3abd61be] */
  { /*    51 */    0x017BU  /* GW_HSC4_PEPS_FrP01_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */   ,   0x07FFU  /* GW_HSC4_PEPS_FrP01_oCAN01_Rx_3abd61be */   , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_PEPS_FrP01_c4eea277   ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_PEPS_FrP01_oCAN01_Rx_3abd61be, CanId: 0x17b]   */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_PEPS_FrP01_oCAN01_Rx_3abd61be] */
  { /*    52 */    0x0094U  /* GW_HSC4_TC_FrP01_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */     ,   0x07FFU  /* GW_HSC4_TC_FrP01_oCAN01_Rx_3abd61be */     , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_TC_FrP01_c4eea277     ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_TC_FrP01_oCAN01_Rx_3abd61be, CanId: 0x94]      */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_TC_FrP01_oCAN01_Rx_3abd61be] */
  { /*    53 */    0x0080U  /* FICM_HSC4_FrP32_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* FICM_HSC4_FrP32_oCAN01_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_FICM_HSC4_FrP32_c4eea277      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: FICM_HSC4_FrP32_oCAN01_Rx_3abd61be, CanId: 0x80]       */  /* [CanIfConf_CanIfRxPduCfg_FICM_HSC4_FrP32_oCAN01_Rx_3abd61be] */
  { /*    54 */    0x003DU  /* GW_HSC4_BCM_FrS10_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC4_BCM_FrS10_oCAN01_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_BCM_FrS10_c4eea277    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_BCM_FrS10_oCAN01_Rx_3abd61be, CanId: 0x3d]     */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_BCM_FrS10_oCAN01_Rx_3abd61be] */
  { /*    55 */    0x003CU  /* GW_HSC4_BCM_FrS09_oCAN01_Rx_3abd61be, 2.0- or FD-PDU */    ,   0x07FFU  /* GW_HSC4_BCM_FrS09_oCAN01_Rx_3abd61be */    , PduRConf_PduRSrcPdu_SRC_Can_PT_GW_HSC4_BCM_FrS09_c4eea277    ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: GW_HSC4_BCM_FrS09_oCAN01_Rx_3abd61be, CanId: 0x3c]     */  /* [CanIfConf_CanIfRxPduCfg_GW_HSC4_BCM_FrS09_oCAN01_Rx_3abd61be] */
  { /*    56 */    0x0799U  /* DIAG_DTCInfo_APA_oCAN02_Rx_3abd61be, 2.0- or FD-PDU */     ,   0x47FFU  /* DIAG_DTCInfo_APA_oCAN02_Rx_3abd61be */     , PduRConf_PduRSrcPdu_SRC_Can_PT_DIAG_DTCInfo_APA_427ad0d9     ,  7U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: DIAG_DTCInfo_APA_oCAN02_Rx_3abd61be, CanId: 0x799]     */  /* [CanIfConf_CanIfRxPduCfg_DIAG_DTCInfo_APA_oCAN02_Rx_3abd61be] */
  { /*    57 */    0x03C6U  /* APA_SecCH_FrP02_oCAN02_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* APA_SecCH_FrP02_oCAN02_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP02_427ad0d9      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: APA_SecCH_FrP02_oCAN02_Rx_3abd61be, CanId: 0x3c6]      */  /* [CanIfConf_CanIfRxPduCfg_APA_SecCH_FrP02_oCAN02_Rx_3abd61be] */
  { /*    58 */    0x028CU  /* APA_SecCH_FrP04_oCAN02_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* APA_SecCH_FrP04_oCAN02_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP04_427ad0d9      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: APA_SecCH_FrP04_oCAN02_Rx_3abd61be, CanId: 0x28c]      */  /* [CanIfConf_CanIfRxPduCfg_APA_SecCH_FrP04_oCAN02_Rx_3abd61be] */
  { /*    59 */    0x028BU  /* APA_SecCH_FrP03_oCAN02_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* APA_SecCH_FrP03_oCAN02_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP03_427ad0d9      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: APA_SecCH_FrP03_oCAN02_Rx_3abd61be, CanId: 0x28b]      */  /* [CanIfConf_CanIfRxPduCfg_APA_SecCH_FrP03_oCAN02_Rx_3abd61be] */
  { /*    60 */    0x023DU  /* PDC_SecCH_FrP00_oCAN02_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* PDC_SecCH_FrP00_oCAN02_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_PDC_SecCH_FrP00_427ad0d9      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: PDC_SecCH_FrP00_oCAN02_Rx_3abd61be, CanId: 0x23d]      */  /* [CanIfConf_CanIfRxPduCfg_PDC_SecCH_FrP00_oCAN02_Rx_3abd61be] */
  { /*    61 */    0x0237U  /* PDC_SecCH_FrP01_oCAN02_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* PDC_SecCH_FrP01_oCAN02_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_PDC_SecCH_FrP01_427ad0d9      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: PDC_SecCH_FrP01_oCAN02_Rx_3abd61be, CanId: 0x237]      */  /* [CanIfConf_CanIfRxPduCfg_PDC_SecCH_FrP01_oCAN02_Rx_3abd61be] */
  { /*    62 */    0x01B5U  /* APA_SecCH_FrP01_oCAN02_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* APA_SecCH_FrP01_oCAN02_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP01_427ad0d9      ,  8U,                    2UL  /* PduR_CanIfRxIndication */ },  /* [PDU: APA_SecCH_FrP01_oCAN02_Rx_3abd61be, CanId: 0x1b5]      */  /* [CanIfConf_CanIfRxPduCfg_APA_SecCH_FrP01_oCAN02_Rx_3abd61be] */
  { /*    63 */    0x01A8U  /* APA_SecCH_FrP00_oCAN02_Rx_3abd61be, 2.0- or FD-PDU */      ,   0x07FFU  /* APA_SecCH_FrP00_oCAN02_Rx_3abd61be */      , PduRConf_PduRSrcPdu_SRC_Can_PT_APA_SecCH_FrP00_427ad0d9      ,  6U,                    2UL  /* PduR_CanIfRxIndication */ }   /* [PDU: APA_SecCH_FrP00_oCAN02_Rx_3abd61be, CanId: 0x1a8]      */  /* [CanIfConf_CanIfRxPduCfg_APA_SecCH_FrP00_oCAN02_Rx_3abd61be] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TrcvModeIndicationFctType, CANIF_CONST) CanIf_TrcvModeIndicationFctPtr = CanSM_ControllerModeIndication;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvToCtrlMap
**********************************************************************************************************************/
/** 
  \var    CanIf_TrcvToCtrlMap
  \brief  Indirection table: logical transceiver index to CAN controller index.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TrcvToCtrlMapType, CANIF_CONST) CanIf_TrcvToCtrlMap[1] = {
  /* Index     TrcvToCtrlMap                                          */
  /*     0 */             0U  /* CAN controller handle ID (upper) */
};
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {
    /* Index    TxBufferPrioByCanIdBaseIdx                                                                       TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx                                                                       TxBufferPrioByCanIdByteQueueMappedTxPdusLength                                                                       TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx                                                                             Referable Keys */
  { /*     0 */                        0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2 */,                                            9UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2 */,                                            9UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2 */,                                              0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2 */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[9] = {
    /* Index    TxPduConfigIdx                                                                                      Referable Keys */
  { /*     0 */            0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_DTCInfo_P2P_oCAN00_Tx_3abd61be */     },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
  { /*     1 */            1UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_DIAG_DTCInfo_APA_oCAN00_Tx_3abd61be */ },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
  { /*     2 */            2UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_PhysResp_P2P_oCAN00_Tx_3abd61be */    },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
  { /*     3 */            3UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrS01_oCAN00_Tx_3abd61be */       },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
  { /*     4 */            4UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP02_oCAN00_Tx_3abd61be */       },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
  { /*     5 */            5UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP03_oCAN00_Tx_3abd61be */       },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
  { /*     6 */            6UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP04_oCAN00_Tx_3abd61be */       },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
  { /*     7 */            7UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP01_oCAN00_Tx_3abd61be */       },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
  { /*     8 */            8UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP00_oCAN00_Tx_3abd61be */       }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[2] = {
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanTp_TxConfirmation                     /* [CanTp_TxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  Dlc                         Data length code.
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[47] = {
    /* Index    CanId    UpperLayerTxPduId                                                   CtrlStatesIdx                                                 Dlc  MailBoxConfigIdx                                                               TxConfirmationFctListIdx                                    Comment                                                         Referable Keys */
  { /*     0 */ 0x079EU, PduRConf_PduRDestPdu_DST_Can_PT_DIAG_DTCInfo_P2P_0fb271d2         ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,  7U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: DIAG_DTCInfo_P2P_oCAN00_Tx_3abd61be]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_DTCInfo_P2P_oCAN00_Tx_3abd61be] */
  { /*     1 */ 0x0799U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_DIAG_DTCInfo_APA_0fb271d2     ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,  7U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_DIAG_DTCInfo_APA_oCAN00_Tx_3abd61be]      */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_DIAG_DTCInfo_APA_oCAN00_Tx_3abd61be] */
  { /*     2 */ 0x073EU, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu                             ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */,                      1UL  /* CanTp_TxConfirmation */ },  /* [PDU: DIAG_PhysResp_P2P_oCAN00_Tx_3abd61be]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_PhysResp_P2P_oCAN00_Tx_3abd61be] */
  { /*     3 */ 0x0602U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrS01_0fb271d2           ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_HSC2_FrS01_oCAN00_Tx_3abd61be]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrS01_oCAN00_Tx_3abd61be] */
  { /*     4 */ 0x03C6U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP02_0fb271d2           ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_HSC2_FrP02_oCAN00_Tx_3abd61be]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP02_oCAN00_Tx_3abd61be] */
  { /*     5 */ 0x023DU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP03_0fb271d2           ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_HSC2_FrP03_oCAN00_Tx_3abd61be]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP03_oCAN00_Tx_3abd61be] */
  { /*     6 */ 0x0237U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP04_0fb271d2           ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_HSC2_FrP04_oCAN00_Tx_3abd61be]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP04_oCAN00_Tx_3abd61be] */
  { /*     7 */ 0x01B5U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP01_0fb271d2           ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_HSC2_FrP01_oCAN00_Tx_3abd61be]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP01_oCAN00_Tx_3abd61be] */
  { /*     8 */ 0x01A8U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC2_FrP00_0fb271d2           ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969 */,  6U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_HSC2_FrP00_oCAN00_Tx_3abd61be]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP00_oCAN00_Tx_3abd61be] */
  { /*     9 */ 0x060FU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC4_FrS01_c4eea277           ,           1UL  /* /ActiveEcuC/CanIf/Can/CT_CAN01_388e5969 */,  8U,              2UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN01_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_HSC4_FrS01_oCAN01_Tx_3abd61be]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC4_FrS01_oCAN01_Tx_3abd61be] */
  { /*    10 */ 0x0390U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_IECU_HSC4_FrP02_c4eea277      ,           1UL  /* /ActiveEcuC/CanIf/Can/CT_CAN01_388e5969 */,  8U,              2UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN01_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_IECU_HSC4_FrP02_oCAN01_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_IECU_HSC4_FrP02_oCAN01_Tx_3abd61be] */
  { /*    11 */ 0x030DU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_HSC4_FrP03_c4eea277           ,           1UL  /* /ActiveEcuC/CanIf/Can/CT_CAN01_388e5969 */,  8U,              2UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN01_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_HSC4_FrP03_oCAN01_Tx_3abd61be]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC4_FrP03_oCAN01_Tx_3abd61be] */
  { /*    12 */ 0x02FCU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_IECU_HSC4_FrP01_c4eea277      ,           1UL  /* /ActiveEcuC/CanIf/Can/CT_CAN01_388e5969 */,  8U,              2UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN01_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_IECU_HSC4_FrP01_oCAN01_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_IECU_HSC4_FrP01_oCAN01_Tx_3abd61be] */
  { /*    13 */ 0x06A3U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrS00_427ad0d9       ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_GW_FrS00_oCAN02_Tx_3abd61be]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrS00_oCAN02_Tx_3abd61be] */
  { /*    14 */ 0x0541U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_IPK_FrP06_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_IPK_FrP06_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_IPK_FrP06_oCAN02_Tx_3abd61be] */
  { /*    15 */ 0x0540U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP08_427ad0d9       ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_GW_FrP08_oCAN02_Tx_3abd61be]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP08_oCAN02_Tx_3abd61be] */
  { /*    16 */ 0x047AU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_BCM_FrP03_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_BCM_FrP03_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_BCM_FrP03_oCAN02_Tx_3abd61be] */
  { /*    17 */ 0x046AU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_BCM_FrP04_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_BCM_FrP04_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_BCM_FrP04_oCAN02_Tx_3abd61be] */
  { /*    18 */ 0x03F1U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP10_427ad0d9       ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_GW_FrP10_oCAN02_Tx_3abd61be]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP10_oCAN02_Tx_3abd61be] */
  { /*    19 */ 0x037DU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_FICM_FrP18_427ad0d9     ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_FICM_FrP18_oCAN02_Tx_3abd61be]      */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_FICM_FrP18_oCAN02_Tx_3abd61be] */
  { /*    20 */ 0x0376U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_FICM_FrP02_427ad0d9     ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_FICM_FrP02_oCAN02_Tx_3abd61be]      */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_FICM_FrP02_oCAN02_Tx_3abd61be] */
  { /*    21 */ 0x0353U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP15_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SCS_FrP15_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP15_oCAN02_Tx_3abd61be] */
  { /*    22 */ 0x034AU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP12_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SCS_FrP12_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP12_oCAN02_Tx_3abd61be] */
  { /*    23 */ 0x0348U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP11_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SCS_FrP11_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP11_oCAN02_Tx_3abd61be] */
  { /*    24 */ 0x02F6U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_FICM_FrP08_427ad0d9     ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_FICM_FrP08_oCAN02_Tx_3abd61be]      */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_FICM_FrP08_oCAN02_Tx_3abd61be] */
  { /*    25 */ 0x0230U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_EPB_FrP00_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_EPB_FrP00_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_EPB_FrP00_oCAN02_Tx_3abd61be] */
  { /*    26 */ 0x022AU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_EPB_FrP01_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  2U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_EPB_FrP01_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_EPB_FrP01_oCAN02_Tx_3abd61be] */
  { /*    27 */ 0x01F2U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_BCM_FrP07_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  2U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_BCM_FrP07_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_BCM_FrP07_oCAN02_Tx_3abd61be] */
  { /*    28 */ 0x01F1U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP01_427ad0d9       ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_GW_FrP01_oCAN02_Tx_3abd61be]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP01_oCAN02_Tx_3abd61be] */
  { /*    29 */ 0x01E9U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP05_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SCS_FrP05_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP05_oCAN02_Tx_3abd61be] */
  { /*    30 */ 0x01E5U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SAS_FrP00_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SAS_FrP00_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SAS_FrP00_oCAN02_Tx_3abd61be] */
  { /*    31 */ 0x01C7U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP03_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SCS_FrP03_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP03_oCAN02_Tx_3abd61be] */
  { /*    32 */ 0x01B1U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_EPS_FrP02_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  4U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_EPS_FrP02_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_EPS_FrP02_oCAN02_Tx_3abd61be] */
  { /*    33 */ 0x01ADU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_Tester_GW_FrP14_427ad0d9,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_Tester_GW_FrP14_oCAN02_Tx_3abd61be] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_Tester_GW_FrP14_oCAN02_Tx_3abd61be] */
  { /*    34 */ 0x01A9U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP13_427ad0d9       ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_GW_FrP13_oCAN02_Tx_3abd61be]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP13_oCAN02_Tx_3abd61be] */
  { /*    35 */ 0x019CU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_HCU_FrP13_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_HCU_FrP13_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_FrP13_oCAN02_Tx_3abd61be] */
  { /*    36 */ 0x0196U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_HCU_FrP01_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_HCU_FrP01_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_FrP01_oCAN02_Tx_3abd61be] */
  { /*    37 */ 0x0194U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_HCU_ECM_FrP04_427ad0d9  ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_HCU_ECM_FrP04_oCAN02_Tx_3abd61be]   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_ECM_FrP04_oCAN02_Tx_3abd61be] */
  { /*    38 */ 0x0185U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP02_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  4U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SCS_FrP02_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP02_oCAN02_Tx_3abd61be] */
  { /*    39 */ 0x0169U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_GW_FrP00_427ad0d9       ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  6U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_GW_FrP00_oCAN02_Tx_3abd61be]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP00_oCAN02_Tx_3abd61be] */
  { /*    40 */ 0x0163U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SDM_FrP00_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SDM_FrP00_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SDM_FrP00_oCAN02_Tx_3abd61be] */
  { /*    41 */ 0x00C9U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_ECM_FrP00_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_ECM_FrP00_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_ECM_FrP00_oCAN02_Tx_3abd61be] */
  { /*    42 */ 0x00C5U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP01_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SCS_FrP01_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP01_oCAN02_Tx_3abd61be] */
  { /*    43 */ 0x00C1U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCS_FrP00_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SCS_FrP00_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP00_oCAN02_Tx_3abd61be] */
  { /*    44 */ 0x00AFU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_HCU_FrP00_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_HCU_FrP00_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_FrP00_oCAN02_Tx_3abd61be] */
  { /*    45 */ 0x009DU, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_SCU_FrP00_427ad0d9      ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             },  /* [PDU: P2P_SecCH_SCU_FrP00_oCAN02_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCU_FrP00_oCAN02_Tx_3abd61be] */
  { /*    46 */ 0x0094U, PduRConf_PduRDestPdu_DST_Can_PT_P2P_SecCH_TC_FrP07_427ad0d9       ,           2UL  /* /ActiveEcuC/CanIf/Can/CT_CAN02_388e5969 */,  8U,              4UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN02_388e5969_Tx_Std */,                      0UL  /* NULL_PTR */             }   /* [PDU: P2P_SecCH_TC_FrP07_oCAN02_Tx_3abd61be]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_TC_FrP07_oCAN02_Tx_3abd61be] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element       Description
  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[47] = {
    /* Index    TxQueueIdx                                                                                                                     Comment                                                                                 Referable Keys */
  { /*     0 */                                  0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_DTCInfo_P2P_oCAN00_Tx_3abd61be */          },  /* [DIAG_DTCInfo_P2P_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_DTCInfo_P2P_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     1 */                                  1UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_DIAG_DTCInfo_APA_oCAN00_Tx_3abd61be */      },  /* [P2P_DIAG_DTCInfo_APA_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_DIAG_DTCInfo_APA_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     2 */                                  2UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_PhysResp_P2P_oCAN00_Tx_3abd61be */         },  /* [DIAG_PhysResp_P2P_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_PhysResp_P2P_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     3 */                                  3UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrS01_oCAN00_Tx_3abd61be */            },  /* [P2P_HSC2_FrS01_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrS01_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     4 */                                  4UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP02_oCAN00_Tx_3abd61be */            },  /* [P2P_HSC2_FrP02_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP02_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     5 */                                  5UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP03_oCAN00_Tx_3abd61be */            },  /* [P2P_HSC2_FrP03_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP03_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     6 */                                  6UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP04_oCAN00_Tx_3abd61be */            },  /* [P2P_HSC2_FrP04_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP04_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     7 */                                  7UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP01_oCAN00_Tx_3abd61be */            },  /* [P2P_HSC2_FrP01_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP01_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     8 */                                  8UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP00_oCAN00_Tx_3abd61be */            },  /* [P2P_HSC2_FrP00_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP00_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  { /*     9 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC4_FrS01_oCAN01_Tx_3abd61be */            },  /* [P2P_HSC4_FrS01_oCAN01_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC4_FrS01_oCAN01_Tx_3abd61be] */
  { /*    10 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_IECU_HSC4_FrP02_oCAN01_Tx_3abd61be */       },  /* [P2P_IECU_HSC4_FrP02_oCAN01_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_IECU_HSC4_FrP02_oCAN01_Tx_3abd61be] */
  { /*    11 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC4_FrP03_oCAN01_Tx_3abd61be */            },  /* [P2P_HSC4_FrP03_oCAN01_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC4_FrP03_oCAN01_Tx_3abd61be] */
  { /*    12 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_IECU_HSC4_FrP01_oCAN01_Tx_3abd61be */       },  /* [P2P_IECU_HSC4_FrP01_oCAN01_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_IECU_HSC4_FrP01_oCAN01_Tx_3abd61be] */
  { /*    13 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrS00_oCAN02_Tx_3abd61be */        },  /* [P2P_SecCH_GW_FrS00_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrS00_oCAN02_Tx_3abd61be] */
  { /*    14 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_IPK_FrP06_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_IPK_FrP06_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_IPK_FrP06_oCAN02_Tx_3abd61be] */
  { /*    15 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP08_oCAN02_Tx_3abd61be */        },  /* [P2P_SecCH_GW_FrP08_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP08_oCAN02_Tx_3abd61be] */
  { /*    16 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_BCM_FrP03_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_BCM_FrP03_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_BCM_FrP03_oCAN02_Tx_3abd61be] */
  { /*    17 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_BCM_FrP04_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_BCM_FrP04_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_BCM_FrP04_oCAN02_Tx_3abd61be] */
  { /*    18 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP10_oCAN02_Tx_3abd61be */        },  /* [P2P_SecCH_GW_FrP10_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP10_oCAN02_Tx_3abd61be] */
  { /*    19 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_FICM_FrP18_oCAN02_Tx_3abd61be */      },  /* [P2P_SecCH_FICM_FrP18_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]      */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_FICM_FrP18_oCAN02_Tx_3abd61be] */
  { /*    20 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_FICM_FrP02_oCAN02_Tx_3abd61be */      },  /* [P2P_SecCH_FICM_FrP02_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]      */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_FICM_FrP02_oCAN02_Tx_3abd61be] */
  { /*    21 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP15_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SCS_FrP15_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP15_oCAN02_Tx_3abd61be] */
  { /*    22 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP12_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SCS_FrP12_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP12_oCAN02_Tx_3abd61be] */
  { /*    23 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP11_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SCS_FrP11_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP11_oCAN02_Tx_3abd61be] */
  { /*    24 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_FICM_FrP08_oCAN02_Tx_3abd61be */      },  /* [P2P_SecCH_FICM_FrP08_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]      */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_FICM_FrP08_oCAN02_Tx_3abd61be] */
  { /*    25 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_EPB_FrP00_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_EPB_FrP00_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_EPB_FrP00_oCAN02_Tx_3abd61be] */
  { /*    26 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_EPB_FrP01_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_EPB_FrP01_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_EPB_FrP01_oCAN02_Tx_3abd61be] */
  { /*    27 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_BCM_FrP07_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_BCM_FrP07_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_BCM_FrP07_oCAN02_Tx_3abd61be] */
  { /*    28 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP01_oCAN02_Tx_3abd61be */        },  /* [P2P_SecCH_GW_FrP01_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP01_oCAN02_Tx_3abd61be] */
  { /*    29 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP05_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SCS_FrP05_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP05_oCAN02_Tx_3abd61be] */
  { /*    30 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SAS_FrP00_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SAS_FrP00_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SAS_FrP00_oCAN02_Tx_3abd61be] */
  { /*    31 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP03_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SCS_FrP03_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP03_oCAN02_Tx_3abd61be] */
  { /*    32 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_EPS_FrP02_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_EPS_FrP02_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_EPS_FrP02_oCAN02_Tx_3abd61be] */
  { /*    33 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_Tester_GW_FrP14_oCAN02_Tx_3abd61be */ },  /* [P2P_SecCH_Tester_GW_FrP14_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_Tester_GW_FrP14_oCAN02_Tx_3abd61be] */
  { /*    34 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP13_oCAN02_Tx_3abd61be */        },  /* [P2P_SecCH_GW_FrP13_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP13_oCAN02_Tx_3abd61be] */
  { /*    35 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_FrP13_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_HCU_FrP13_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_FrP13_oCAN02_Tx_3abd61be] */
  { /*    36 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_FrP01_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_HCU_FrP01_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_FrP01_oCAN02_Tx_3abd61be] */
  { /*    37 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_ECM_FrP04_oCAN02_Tx_3abd61be */   },  /* [P2P_SecCH_HCU_ECM_FrP04_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_ECM_FrP04_oCAN02_Tx_3abd61be] */
  { /*    38 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP02_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SCS_FrP02_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP02_oCAN02_Tx_3abd61be] */
  { /*    39 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP00_oCAN02_Tx_3abd61be */        },  /* [P2P_SecCH_GW_FrP00_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_GW_FrP00_oCAN02_Tx_3abd61be] */
  { /*    40 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SDM_FrP00_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SDM_FrP00_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SDM_FrP00_oCAN02_Tx_3abd61be] */
  { /*    41 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_ECM_FrP00_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_ECM_FrP00_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_ECM_FrP00_oCAN02_Tx_3abd61be] */
  { /*    42 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP01_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SCS_FrP01_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP01_oCAN02_Tx_3abd61be] */
  { /*    43 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP00_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SCS_FrP00_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCS_FrP00_oCAN02_Tx_3abd61be] */
  { /*    44 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_FrP00_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_HCU_FrP00_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_HCU_FrP00_oCAN02_Tx_3abd61be] */
  { /*    45 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCU_FrP00_oCAN02_Tx_3abd61be */       },  /* [P2P_SecCH_SCU_FrP00_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_SCU_FrP00_oCAN02_Tx_3abd61be] */
  { /*    46 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_TC_FrP07_oCAN02_Tx_3abd61be */        }   /* [P2P_SecCH_TC_FrP07_oCAN02_Tx_3abd61be, BasicCAN TxPdu NO Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_SecCH_TC_FrP07_oCAN02_Tx_3abd61be] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/Can/CT_CAN00_388e5969] */
  /*     1 */  /* [/ActiveEcuC/CanIf/Can/CT_CAN01_388e5969] */
  /*     2 */  /* [/ActiveEcuC/CanIf/Can/CT_CAN02_388e5969] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_Tx_Std_0fb271d2] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_DTCInfo_P2P_oCAN00_Tx_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_DIAG_DTCInfo_APA_oCAN00_Tx_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_PhysResp_P2P_oCAN00_Tx_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrS01_oCAN00_Tx_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP02_oCAN00_Tx_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP03_oCAN00_Tx_3abd61be] */
  /*     6 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP04_oCAN00_Tx_3abd61be] */
  /*     7 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP01_oCAN00_Tx_3abd61be] */
  /*     8 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/P2P_HSC2_FrP00_oCAN00_Tx_3abd61be] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



