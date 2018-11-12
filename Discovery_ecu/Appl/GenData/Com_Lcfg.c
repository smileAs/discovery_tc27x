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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Lcfg.c
 *   Generation Time: 2018-09-27 17:21:16
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
 * [Warning] COM02205 - Inconsistent signal layout. 
 * - [Reduced Severity due to User-Defined Parameter] /ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_FuncReq_HSC2_PP_DIAG_FuncReq_HSC2_Rx_0fb271d2_c07658fd[0:PduLength](value=7) of /ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be cannot hold contained ComSignals / ComGroupSignals.
 * 
 * Exceeding signals:
 * /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3
 * Erroneous configuration elements:
 * /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3[0:ComBitPosition](value=0) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComBitPosition)
 * /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3[0:ComSignalLength](value=8) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComSignalLength)
 * /ActiveEcuC/EcuC/EcucPduCollection/PT_DIAG_FuncReq_HSC2_PP_DIAG_FuncReq_HSC2_Rx_0fb271d2_c07658fd[0:PduLength](value=7) (DefRef: /MICROSAR/EcuC/EcucPduCollection/Pdu/PduLength)
 * /ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be[0:ComIPduSignalRef](value=/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3) (DefRef: /MICROSAR/Com/ComConfig/ComIPdu/ComIPduSignalRef)
 * /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3[0:ComSignalEndianness](value=OPAQUE) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComSignalEndianness)
 * /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3[0:ComSignalType](value=UINT8_N) (DefRef: /MICROSAR/Com/ComConfig/ComSignal/ComSignalType)
 *********************************************************************************************************************/

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA S 0342 EOF */ /* MD_Com_0342 */
/* PRQA S 0612 EOF */ /* MD_Com_0612 */
/* PRQA S 0639 EOF */ /* MD_MSR_1.1_639 */
/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 2006 EOF */ /* MD_MSR_14.7 */
/* PRQA S 3109 EOF */ /* MD_MSR_14.3 */
/* PRQA S 3453 EOF */ /* MD_CSL_3453 */
/* PRQA S 3458 EOF */ /* MD_MSR_19.4 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"

#include "Com_Lcfg.h"


#include "SchM_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
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
  Com_ConstValueArrayBased
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueArrayBased
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueArrayBasedType, COM_CONST) Com_ConstValueArrayBased[8] = {
  /* Index     ConstValueArrayBased      Referable Keys */
  /*     0 */                 0x00U,  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5InitValue, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510addInitValue, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449dInitValue, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cdInitValue, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014InitValue, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85InitValue] */
  /*     1 */                 0x00U,  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5InitValue, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510addInitValue, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449dInitValue, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cdInitValue, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014InitValue, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85InitValue] */
  /*     2 */                 0x00U,  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5InitValue, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510addInitValue, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449dInitValue, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cdInitValue, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014InitValue, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85InitValue] */
  /*     3 */                 0x00U,  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5InitValue, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510addInitValue, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449dInitValue, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cdInitValue, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014InitValue, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85InitValue] */
  /*     4 */                 0x00U,  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5InitValue, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510addInitValue, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449dInitValue, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cdInitValue, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014InitValue, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85InitValue] */
  /*     5 */                 0x00U,  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5InitValue, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510addInitValue, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449dInitValue, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cdInitValue, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014InitValue, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85InitValue] */
  /*     6 */                 0x00U,  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5InitValue, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510addInitValue, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449dInitValue, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cdInitValue, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014InitValue, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85InitValue] */
  /*     7 */                 0x00U   /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5InitValue, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510addInitValue, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3InitValue, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449dInitValue, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cdInitValue, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014InitValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueSInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueSInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (SINT16)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueSInt16Type, COM_CONST) Com_ConstValueSInt16[1] = {
  /* Index     ConstValueSInt16      Referable Keys */
  /*     0 */                 0   /* [/ActiveEcuC/Com/ComConfig/TBOXAccelZHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/TBOXAccelZHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VSELatAccHSC2_542766fdInitValue, /ActiveEcuC/Com/ComConfig/VSELatAccHSC2_542766fdRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VSELongtAccHSC2_542766fdInitValue, /ActiveEcuC/Com/ComConfig/VSELongtAccHSC2_542766fdRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehDynYawRateHSC2_5ee26fe4InitValue, /ActiveEcuC/Com/ComConfig/VehDynYawRateHSC2_5ee26fe4RxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[2] = {
  /* Index     ConstValueUInt16      Referable Keys */
  /*     0 */           0x8000U,  /* [/ActiveEcuC/Com/ComConfig/TMSpd_h1HSC4_d68cf0b9InitValue, /ActiveEcuC/Com/ComConfig/TMSpd_h1HSC4_d68cf0b9RxDataTimeoutSubstitutionValue] */
  /*     1 */           0x0000U   /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqValPV_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APASCSAcclReqValPV_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APASlotLngth_sech2_SecCAN2_48fe6e71InitValue, /ActiveEcuC/Com/ComConfig/APASlotLngth_sech2_SecCAN2_48fe6e71RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAToqReqVal_sech2_SecCAN2_0adb690cInitValue, /ActiveEcuC/Com/ComConfig/APAToqReqVal_sech2_SecCAN2_0adb690cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APATrgtEPSStrgWhlAng_sech2_SecCAN2_0adb690cInitValue, /ActiveEcuC/Com/ComConfig/APATrgtEPSStrgWhlAng_sech2_SecCAN2_0adb690cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAVehCrdnatAzmth_sech2_SecCAN2_48fe6e71InitValue, /ActiveEcuC/Com/ComConfig/APAVehCrdnatAzmth_sech2_SecCAN2_48fe6e71RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosX_sech2_SecCAN2_48fe6e71InitValue, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosX_sech2_SecCAN2_48fe6e71RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosY_sech2_SecCAN2_48fe6e71InitValue, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosY_sech2_SecCAN2_48fe6e71RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnHSC2_49997ba7InitValue, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnHSC2_49997ba7RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FLObsDist_sech2_SecCAN2_84546eefInitValue, /ActiveEcuC/Com/ComConfig/FLObsDist_sech2_SecCAN2_84546eefRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FLSideObsDist_sech2_SecCAN2_eb7d27c8InitValue, /ActiveEcuC/Com/ComConfig/FLSideObsDist_sech2_SecCAN2_eb7d27c8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FRObsDist_sech2_SecCAN2_84546eefInitValue, /ActiveEcuC/Com/ComConfig/FRObsDist_sech2_SecCAN2_84546eefRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FRSideObsDist_sech2_SecCAN2_eb7d27c8InitValue, /ActiveEcuC/Com/ComConfig/FRSideObsDist_sech2_SecCAN2_eb7d27c8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FrtMidLObsDist_sech2_SecCAN2_8e9167f6InitValue, /ActiveEcuC/Com/ComConfig/FrtMidLObsDist_sech2_SecCAN2_8e9167f6RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FrtMidRObsDist_sech2_SecCAN2_8e9167f6InitValue, /ActiveEcuC/Com/ComConfig/FrtMidRObsDist_sech2_SecCAN2_8e9167f6RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistPlsCtrHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistPlsCtrHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTmspHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTmspHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistPCHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistPCHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistPlsCtrHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistPlsCtrHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTmspHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTmspHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RLObsDist_sech2_SecCAN2_84546eefInitValue, /ActiveEcuC/Com/ComConfig/RLObsDist_sech2_SecCAN2_84546eefRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RLSideObsDist_sech2_SecCAN2_eb7d27c8InitValue, /ActiveEcuC/Com/ComConfig/RLSideObsDist_sech2_SecCAN2_eb7d27c8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistPCHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistPCHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RRObsDist_sech2_SecCAN2_84546eefInitValue, /ActiveEcuC/Com/ComConfig/RRObsDist_sech2_SecCAN2_84546eefRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RRSideObsDist_sech2_SecCAN2_eb7d27c8InitValue, /ActiveEcuC/Com/ComConfig/RRSideObsDist_sech2_SecCAN2_eb7d27c8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RrMidLObsDist_sech2_SecCAN2_8e9167f6InitValue, /ActiveEcuC/Com/ComConfig/RrMidLObsDist_sech2_SecCAN2_8e9167f6RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RrMidRObsDist_sech2_SecCAN2_8e9167f6InitValue, /ActiveEcuC/Com/ComConfig/RrMidRObsDist_sech2_SecCAN2_8e9167f6RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_AXHSC4_c0316154InitValue, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_AXHSC4_c0316154RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_AYHSC4_c0316154InitValue, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_AYHSC4_c0316154RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_BXHSC4_c0316154InitValue, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_BXHSC4_c0316154RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_BYHSC4_c0316154InitValue, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_BYHSC4_c0316154RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/StrgWhlAngHSC2_dccc170cInitValue, /ActiveEcuC/Com/ComConfig/StrgWhlAngHSC2_dccc170cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TOF_LRU1_18ef6e8dInitValue, /ActiveEcuC/Com/ComConfig/TOF_LRU1_18ef6e8dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TOF_SRU3_67c459fdInitValue, /ActiveEcuC/Com/ComConfig/TOF_SRU3_67c459fdRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnHSC2_49997ba7InitValue, /ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnHSC2_49997ba7RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnHSC2_49997ba7InitValue, /ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnHSC2_49997ba7RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnHSC2_cdd3755dInitValue, /ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnHSC2_cdd3755dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnHSC2_435c72beInitValue, /ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnHSC2_435c72beRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnHSC2_cdd3755dInitValue, /ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnHSC2_cdd3755dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnHSC2_435c72beInitValue, /ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnHSC2_435c72beRxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt32
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt32Type, COM_CONST) Com_ConstValueUInt32[1] = {
  /* Index     ConstValueUInt32      Referable Keys */
  /*     0 */      0x00000000UL   /* [/ActiveEcuC/Com/ComConfig/VehOdo_h2HSC2_78aeb97bInitValue, /ActiveEcuC/Com/ComConfig/VehOdo_h2HSC2_78aeb97bRxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[6] = {
  /* Index     ConstValueUInt8      Referable Keys */
  /*     0 */            0x0FU,  /* [/ActiveEcuC/Com/ComConfig/SCUShifterPosInvsnHSC2_efc2a4dbInitValue, /ActiveEcuC/Com/ComConfig/SCUShifterPosInvsnHSC2_efc2a4dbRxDataTimeoutSubstitutionValue] */
  /*     1 */            0x03U,  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDircnHSC2_988d6663InitValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDircnHSC2_988d6663RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDircnHSC2_988d6663InitValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDircnHSC2_988d6663RxDataTimeoutSubstitutionValue] */
  /*     2 */            0x37U,  /* [/ActiveEcuC/Com/ComConfig/FLTirePrsHSC4_fa528d8cInitValue, /ActiveEcuC/Com/ComConfig/FLTirePrsHSC4_fa528d8cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FRTirePrsHSC4_fa528d8cInitValue, /ActiveEcuC/Com/ComConfig/FRTirePrsHSC4_fa528d8cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RLTirePrsHSC4_fa528d8cInitValue, /ActiveEcuC/Com/ComConfig/RLTirePrsHSC4_fa528d8cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RRTirePrsHSC4_fa528d8cInitValue, /ActiveEcuC/Com/ComConfig/RRTirePrsHSC4_fa528d8cRxDataTimeoutSubstitutionValue] */
  /*     3 */            0x07U,  /* [/ActiveEcuC/Com/ComConfig/EPSAPAStsHSC2_a6919738InitValue, /ActiveEcuC/Com/ComConfig/EPSAPAStsHSC2_a6919738RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehLckngStaHSC4_0f57ab67InitValue, /ActiveEcuC/Com/ComConfig/VehLckngStaHSC4_0f57ab67RxDataTimeoutSubstitutionValue] */
  /*     4 */            0x01U,  /* [/ActiveEcuC/Com/ComConfig/AirbagDplInvsnHSC2_2128899bInitValue, /ActiveEcuC/Com/ComConfig/AirbagDplInvsnHSC2_2128899bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsVHSC2_533eb1f8InitValue, /ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsVHSC2_533eb1f8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PDCCofignSts_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/PDCCofignSts_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TMSpdV_h1HSC4_d68cf0b9InitValue, /ActiveEcuC/Com/ComConfig/TMSpdV_h1HSC4_d68cf0b9RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnVHSC2_cdd3755dInitValue, /ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnVHSC2_cdd3755dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnVHSC2_435c72beInitValue, /ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnVHSC2_435c72beRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnVHSC2_cdd3755dInitValue, /ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnVHSC2_cdd3755dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnVHSC2_435c72beInitValue, /ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnVHSC2_435c72beRxDataTimeoutSubstitutionValue] */
  /*     5 */            0x00U   /* [/ActiveEcuC/Com/ComConfig/ABSAHSC2_5ee26fe4InitValue, /ActiveEcuC/Com/ComConfig/ABSAHSC2_5ee26fe4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAAlvRC_sech2_SecCAN2_0adb690cInitValue, /ActiveEcuC/Com/ComConfig/APAAlvRC_sech2_SecCAN2_0adb690cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAChksm_sech2_SecCAN2_0adb690cInitValue, /ActiveEcuC/Com/ComConfig/APAChksm_sech2_SecCAN2_0adb690cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APACmdEPSSts_sech2_SecCAN2_0adb690cInitValue, /ActiveEcuC/Com/ComConfig/APACmdEPSSts_sech2_SecCAN2_0adb690cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APACrpSpdReqSts_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APACrpSpdReqSts_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APACrpSpdReqVal_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APACrpSpdReqVal_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APACtrlAbotdRsnHSC2_32bfb16eInitValue, /ActiveEcuC/Com/ComConfig/APACtrlAbotdRsnHSC2_32bfb16eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAEPBOPReq_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APAEPBOPReq_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAEPBOpReqValPV_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APAEPBOpReqValPV_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAEPBReqAlvRC_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APAEPBReqAlvRC_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAF_sech2_SecCAN2_0adb690cInitValue, /ActiveEcuC/Com/ComConfig/APAF_sech2_SecCAN2_0adb690cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAInfoDispReq_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APAInfoDispReq_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAMd_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APAMd_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APANRCDAvlbl_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APANRCDAvlbl_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAParkngSchedV_sech2_SecCAN2_48fe6e71InitValue, /ActiveEcuC/Com/ComConfig/APAParkngSchedV_sech2_SecCAN2_48fe6e71RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAParkngSched_sech2_SecCAN2_48fe6e71InitValue, /ActiveEcuC/Com/ComConfig/APAParkngSched_sech2_SecCAN2_48fe6e71RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAReq_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APAReq_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APASCSAcclReqSts_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APASCSAcclReqSts_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APASCSAcclReqVal_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APASCSAcclReqVal_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APASCSAlvRC_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APASCSAlvRC_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAShifterPosReqd_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APAShifterPosReqd_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APASlotBearng_sech2_SecCAN2_48fe6e71InitValue, /ActiveEcuC/Com/ComConfig/APASlotBearng_sech2_SecCAN2_48fe6e71RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APASts_sech2_SecCAN2_c6716992InitValue, /ActiveEcuC/Com/ComConfig/APASts_sech2_SecCAN2_c6716992RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APASwReqHSC2_46783686InitValue, /ActiveEcuC/Com/ComConfig/APASwReqHSC2_46783686RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APASwReqHSC4_687c4159InitValue, /ActiveEcuC/Com/ComConfig/APASwReqHSC4_687c4159RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/APAToqReqSts_sech2_SecCAN2_0adb690cInitValue, /ActiveEcuC/Com/ComConfig/APAToqReqSts_sech2_SecCAN2_0adb690cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/AVMAutoViewChgHSC4_0c9b61caInitValue, /ActiveEcuC/Com/ComConfig/AVMAutoViewChgHSC4_0c9b61caRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/AirbagDplHSC2_2128899bInitValue, /ActiveEcuC/Com/ComConfig/AirbagDplHSC2_2128899bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/AlisysrdyHSC4_226d494cInitValue, /ActiveEcuC/Com/ComConfig/AlisysrdyHSC4_226d494cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/BCMAvlbly_h2HSC2_ab4ba2ceInitValue, /ActiveEcuC/Com/ComConfig/BCMAvlbly_h2HSC2_ab4ba2ceRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/BCMSSBAHSC2_f8a32097InitValue, /ActiveEcuC/Com/ComConfig/BCMSSBAHSC2_f8a32097RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/BCMSSBAVHSC2_f8a32097InitValue, /ActiveEcuC/Com/ComConfig/BCMSSBAVHSC2_f8a32097RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/BCMSSBFltStsHSC2_34092009InitValue, /ActiveEcuC/Com/ComConfig/BCMSSBFltStsHSC2_34092009RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/BMSBscSta_h1HSC4_c182dd1dInitValue, /ActiveEcuC/Com/ComConfig/BMSBscSta_h1HSC4_c182dd1dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/BPMMstrAvlbly_h2HSC2_67e1a250InitValue, /ActiveEcuC/Com/ComConfig/BPMMstrAvlbly_h2HSC2_67e1a250RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/BntOpenStsHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/BntOpenStsHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/BrkPdlAppdHSC2_70a619c8InitValue, /ActiveEcuC/Com/ComConfig/BrkPdlAppdHSC2_70a619c8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CalendarDayHSC2_c30fb534InitValue, /ActiveEcuC/Com/ComConfig/CalendarDayHSC2_c30fb534RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CalendarDayHSC4_80f6c9a0InitValue, /ActiveEcuC/Com/ComConfig/CalendarDayHSC4_80f6c9a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CalendarMonthHSC2_c30fb534InitValue, /ActiveEcuC/Com/ComConfig/CalendarMonthHSC2_c30fb534RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CalendarMonthHSC4_80f6c9a0InitValue, /ActiveEcuC/Com/ComConfig/CalendarMonthHSC4_80f6c9a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CalendarYearHSC2_c30fb534InitValue, /ActiveEcuC/Com/ComConfig/CalendarYearHSC2_c30fb534RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CalendarYearHSC4_80f6c9a0InitValue, /ActiveEcuC/Com/ComConfig/CalendarYearHSC4_80f6c9a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DayTimeRunningLampOnHSC2_34092009InitValue, /ActiveEcuC/Com/ComConfig/DayTimeRunningLampOnHSC2_34092009RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DipdBeamLghtOnHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/DipdBeamLghtOnHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DircnIndLampSwStsHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/DircnIndLampSwStsHSC2_762c2774RxDataTimeoutSubstitutionValue, 
              /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnRstOcdHSC2_49997ba7InitValue, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnRstOcdHSC2_49997ba7RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnSrcHSC2_49997ba7InitValue, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnSrcHSC2_49997ba7RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnVHSC2_49997ba7InitValue, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnVHSC2_49997ba7RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DrvrDoorOpenStsHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/DrvrDoorOpenStsHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DrvrSbltAtcHSC2_2128899bInitValue, /ActiveEcuC/Com/ComConfig/DrvrSbltAtcHSC2_2128899bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DrvrSbltAtcVHSC2_2128899bInitValue, /ActiveEcuC/Com/ComConfig/DrvrSbltAtcVHSC2_2128899bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC2_d7b82a4eInitValue, /ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC2_d7b82a4eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC4_7f07551aInitValue, /ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC4_7f07551aRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC2_d7b82a4eInitValue, /ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC2_d7b82a4eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC4_7f07551aInitValue, /ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC4_7f07551aRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ECMAvlbly_h2HSC2_ab4ba2ceInitValue, /ActiveEcuC/Com/ComConfig/ECMAvlbly_h2HSC2_ab4ba2ceRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPBAppcnStsHSC2_ecbe2b89InitValue, /ActiveEcuC/Com/ComConfig/EPBAppcnStsHSC2_ecbe2b89RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPBAppcnStsPVHSC2_ecbe2b89InitValue, /ActiveEcuC/Com/ComConfig/EPBAppcnStsPVHSC2_ecbe2b89RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPBAvlblyStsHSC2_ecbe2b89InitValue, /ActiveEcuC/Com/ComConfig/EPBAvlblyStsHSC2_ecbe2b89RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPBAvlblyStsPVHSC2_ecbe2b89InitValue, /ActiveEcuC/Com/ComConfig/EPBAvlblyStsPVHSC2_ecbe2b89RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPBSwStsHSC2_20142b17InitValue, /ActiveEcuC/Com/ComConfig/EPBSwStsHSC2_20142b17RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPBSwStsVHSC2_20142b17InitValue, /ActiveEcuC/Com/ComConfig/EPBSwStsVHSC2_20142b17RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPSAPAAlvRCHSC2_a6919738InitValue, /ActiveEcuC/Com/ComConfig/EPSAPAAlvRCHSC2_a6919738RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPSAPAChksmHSC2_a6919738InitValue, /ActiveEcuC/Com/ComConfig/EPSAPAChksmHSC2_a6919738RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPSAPAInhHSC2_a6919738InitValue, /ActiveEcuC/Com/ComConfig/EPSAPAInhHSC2_a6919738RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPTAccelActuPosHSC2_533eb1f8InitValue, /ActiveEcuC/Com/ComConfig/EPTAccelActuPosHSC2_533eb1f8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPTAccelActuPosVHSC2_533eb1f8InitValue, /ActiveEcuC/Com/ComConfig/EPTAccelActuPosVHSC2_533eb1f8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsHSC2_533eb1f8InitValue, /ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsHSC2_533eb1f8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPTRdy_h1HSC2_9f94b166InitValue, /ActiveEcuC/Com/ComConfig/EPTRdy_h1HSC2_9f94b166RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EPTStCmdOn_h1HSC2_533eb1f8InitValue, /ActiveEcuC/Com/ComConfig/EPTStCmdOn_h1HSC2_533eb1f8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EnRunAHSC2_235f8f9bInitValue, /ActiveEcuC/Com/ComConfig/EnRunAHSC2_235f8f9bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FICMAvlbly_h2HSC2_ab4ba2ceInitValue, /ActiveEcuC/Com/ComConfig/FICMAvlbly_h2HSC2_ab4ba2ceRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FICMP2PQuitReqHSC4_0c9b61caInitValue, /ActiveEcuC/Com/ComConfig/FICMP2PQuitReqHSC4_0c9b61caRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FICMPLCRtCoverSwReqHSC4_0c9b61caInitValue, /ActiveEcuC/Com/ComConfig/FICMPLCRtCoverSwReqHSC4_0c9b61caRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FICMPLCRtEndSwReqHSC4_0c9b61caInitValue, /ActiveEcuC/Com/ComConfig/FICMPLCRtEndSwReqHSC4_0c9b61caRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FICMPLCSwReqHSC4_0c9b61caInitValue, /ActiveEcuC/Com/ComConfig/FICMPLCSwReqHSC4_0c9b61caRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FICMRouteChangeCheckHSC4_0c9b61caInitValue, /ActiveEcuC/Com/ComConfig/FICMRouteChangeCheckHSC4_0c9b61caRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FICMRouteReqHSC4_0c9b61caInitValue, /ActiveEcuC/Com/ComConfig/FICMRouteReqHSC4_0c9b61caRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FICMSilentSearchCheckHSC4_0c9b61caInitValue, /ActiveEcuC/Com/ComConfig/FICMSilentSearchCheckHSC4_0c9b61caRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FICMSilentSearchReqHSC4_0c9b61caInitValue, /ActiveEcuC/Com/ComConfig/FICMSilentSearchReqHSC4_0c9b61caRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FLDoorHadlSwAHSC4_5c9d774fInitValue, /ActiveEcuC/Com/ComConfig/FLDoorHadlSwAHSC4_5c9d774fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FLObsRng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/FLObsRng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FLTirePrsVHSC4_fa528d8cInitValue, /ActiveEcuC/Com/ComConfig/FLTirePrsVHSC4_fa528d8cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FRDoorHadlSwAHSC4_5c9d774fInitValue, /ActiveEcuC/Com/ComConfig/FRDoorHadlSwAHSC4_5c9d774fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FRObsRng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/FRObsRng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FRTirePrsVHSC4_fa528d8cInitValue, /ActiveEcuC/Com/ComConfig/FRTirePrsVHSC4_fa528d8cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FrtFogLghtOnHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/FrtFogLghtOnHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FrtMidLObsRng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/FrtMidLObsRng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FrtMidRObsRng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/FrtMidRObsRng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FrtObsDist_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/FrtObsDist_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FrtPDCAudWrnng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/FrtPDCAudWrnng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FrtPsngDoorOpenStsHSC2_762c2774InitValue, 
              /ActiveEcuC/Com/ComConfig/FrtPsngDoorOpenStsHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/HCUAvlbly_h2HSC2_ab4ba2ceInitValue, /ActiveEcuC/Com/ComConfig/HCUAvlbly_h2HSC2_ab4ba2ceRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/HourOfDayHSC2_c30fb534InitValue, /ActiveEcuC/Com/ComConfig/HourOfDayHSC2_c30fb534RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/HourOfDayHSC4_80f6c9a0InitValue, /ActiveEcuC/Com/ComConfig/HourOfDayHSC4_80f6c9a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/HydBstrCmpstnReqHSC2_70a619c8InitValue, /ActiveEcuC/Com/ComConfig/HydBstrCmpstnReqHSC2_70a619c8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/IPCAvlbly_h2HSC2_ab4ba2ceInitValue, /ActiveEcuC/Com/ComConfig/IPCAvlbly_h2HSC2_ab4ba2ceRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LDircnIOHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/LDircnIOHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTRCHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTRCHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistVHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistVHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlRstOcdHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlRstOcdHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlSeqNumHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlSeqNumHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTRCHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTRCHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistVHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistVHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlRstOcdHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlRstOcdHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlSeqNumHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlSeqNumHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LRCTAWrnngHSC4_693ba2afInitValue, /ActiveEcuC/Com/ComConfig/LRCTAWrnngHSC4_693ba2afRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/LdspcOpenStsHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/LdspcOpenStsHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/MainBeamLghtOnHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/MainBeamLghtOnHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/MinuteOfHourHSC2_c30fb534InitValue, /ActiveEcuC/Com/ComConfig/MinuteOfHourHSC2_c30fb534RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/MinuteOfHourHSC4_80f6c9a0InitValue, /ActiveEcuC/Com/ComConfig/MinuteOfHourHSC4_80f6c9a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NRCDAlvRCHSC2_6ae5c0ffInitValue, /ActiveEcuC/Com/ComConfig/NRCDAlvRCHSC2_6ae5c0ffRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NRCDFHSC2_6ae5c0ffInitValue, /ActiveEcuC/Com/ComConfig/NRCDFHSC2_6ae5c0ffRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NRCDSts_h2HSC2_32bfb16eInitValue, /ActiveEcuC/Com/ComConfig/NRCDSts_h2HSC2_32bfb16eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrValMsk_h2HSC2_bc30b68dInitValue, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrValMsk_h2HSC2_bc30b68dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrValV_h2HSC2_bc30b68dInitValue, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrValV_h2HSC2_bc30b68dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrVal_h2HSC2_bc30b68dInitValue, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrVal_h2HSC2_bc30b68dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/P2PExeAvlblHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/P2PExeAvlblHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/P2PExeAvlblVHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/P2PExeAvlblVHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/P2PSwReqHSC4_8dbecfcaInitValue, /ActiveEcuC/Com/ComConfig/P2PSwReqHSC4_8dbecfcaRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PDCSwReqHSC2_46783686InitValue, /ActiveEcuC/Com/ComConfig/PDCSwReqHSC2_46783686RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PDCSwReqHSC4_687c4159InitValue, /ActiveEcuC/Com/ComConfig/PDCSwReqHSC4_687c4159RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PDCSysSts_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/PDCSysSts_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PEPSSSBAHSC4_5c9d774fInitValue, /ActiveEcuC/Com/ComConfig/PEPSSSBAHSC4_5c9d774fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PEPSSSBAVHSC4_5c9d774fInitValue, /ActiveEcuC/Com/ComConfig/PEPSSSBAVHSC4_5c9d774fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PEPSSSBFltStsHSC4_d21270acInitValue, /ActiveEcuC/Com/ComConfig/PEPSSSBFltStsHSC4_d21270acRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/Peak_LRU1_18ef6e8dInitValue, /ActiveEcuC/Com/ComConfig/Peak_LRU1_18ef6e8dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PwrMdAutoCtrlAvlblHSC2_f8a32097InitValue, /ActiveEcuC/Com/ComConfig/PwrMdAutoCtrlAvlblHSC2_f8a32097RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PwrMdMstrAccryA_h2HSC2_67e1a250InitValue, /ActiveEcuC/Com/ComConfig/PwrMdMstrAccryA_h2HSC2_67e1a250RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/PwrMdMstrRunCrkA_h2HSC2_67e1a250InitValue, /ActiveEcuC/Com/ComConfig/PwrMdMstrRunCrkA_h2HSC2_67e1a250RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RDircnIOHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/RDircnIOHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTRCHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTRCHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistVHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistVHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlRstOcdHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlRstOcdHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlSeqNumHSC2_16026180InitValue, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlSeqNumHSC2_16026180RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RLDoorOpenStsHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/RLDoorOpenStsHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RLObsRng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/RLObsRng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RLTirePrsVHSC4_fa528d8cInitValue, /ActiveEcuC/Com/ComConfig/RLTirePrsVHSC4_fa528d8cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTRCHSC2_daa8611eInitValue, 
              /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTRCHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistVHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistVHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlRstOcdHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlRstOcdHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlSeqNumHSC2_daa8611eInitValue, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlSeqNumHSC2_daa8611eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RRCTAWrnngHSC4_693ba2afInitValue, /ActiveEcuC/Com/ComConfig/RRCTAWrnngHSC4_693ba2afRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RRDoorOpenStsHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/RRDoorOpenStsHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RRObsRng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/RRObsRng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RRTirePrsVHSC4_fa528d8cInitValue, /ActiveEcuC/Com/ComConfig/RRTirePrsVHSC4_fa528d8cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RrFogLghtOnHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/RrFogLghtOnHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RrMidLObsRng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/RrMidLObsRng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RrMidRObsRng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/RrMidRObsRng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RrObsDist_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/RrObsDist_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RrPDCAudWrnng_sech2_SecCAN2_27d72756InitValue, /ActiveEcuC/Com/ComConfig/RrPDCAudWrnng_sech2_SecCAN2_27d72756RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC2_d7b82a4eInitValue, /ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC2_d7b82a4eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC4_f9bc5d91InitValue, /ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC4_f9bc5d91RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCSAPAAcclAHSC2_988d6663InitValue, /ActiveEcuC/Com/ComConfig/SCSAPAAcclAHSC2_988d6663RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCSAPAAlvRCHSC2_988d6663InitValue, /ActiveEcuC/Com/ComConfig/SCSAPAAlvRCHSC2_988d6663RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCSAPAAvlblHSC2_988d6663InitValue, /ActiveEcuC/Com/ComConfig/SCSAPAAvlblHSC2_988d6663RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCSNRCDAvlblHSC2_988d6663InitValue, /ActiveEcuC/Com/ComConfig/SCSNRCDAvlblHSC2_988d6663RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCUAvlbly_h2HSC2_ab4ba2ceInitValue, /ActiveEcuC/Com/ComConfig/SCUAvlbly_h2HSC2_ab4ba2ceRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCUDrvrIntrvnAHSC2_efc2a4dbInitValue, /ActiveEcuC/Com/ComConfig/SCUDrvrIntrvnAHSC2_efc2a4dbRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCUNRCDAvlblHSC2_efc2a4dbInitValue, /ActiveEcuC/Com/ComConfig/SCUNRCDAvlblHSC2_efc2a4dbRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCUShifterLvrPosHSC2_efc2a4dbInitValue, /ActiveEcuC/Com/ComConfig/SCUShifterLvrPosHSC2_efc2a4dbRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SCUShifterPosRCHSC2_efc2a4dbInitValue, /ActiveEcuC/Com/ComConfig/SCUShifterPosRCHSC2_efc2a4dbRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SDMAvlbly_h2HSC2_ab4ba2ceInitValue, /ActiveEcuC/Com/ComConfig/SDMAvlbly_h2HSC2_ab4ba2ceRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC2_c30fb534InitValue, /ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC2_c30fb534RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC4_80f6c9a0InitValue, /ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC4_80f6c9a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/Status_LRU1_18ef6e8dInitValue, /ActiveEcuC/Com/ComConfig/Status_LRU1_18ef6e8dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/Status_SRU3_67c459fdInitValue, /ActiveEcuC/Com/ComConfig/Status_SRU3_67c459fdRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/StrgWhlAngVHSC2_dccc170cInitValue, /ActiveEcuC/Com/ComConfig/StrgWhlAngVHSC2_dccc170cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SurndViewSelnHSC4_c0316154InitValue, /ActiveEcuC/Com/ComConfig/SurndViewSelnHSC4_c0316154RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SysBPMEnbdHSC2_f8a32097InitValue, /ActiveEcuC/Com/ComConfig/SysBPMEnbdHSC2_f8a32097RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SysBPMHSC2_f8a32097InitValue, /ActiveEcuC/Com/ComConfig/SysBPMHSC2_f8a32097RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SysOpnlMd_h2HSC2_67e1a250InitValue, /ActiveEcuC/Com/ComConfig/SysOpnlMd_h2HSC2_67e1a250RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SysPwrMd_h2HSC2_67e1a250InitValue, /ActiveEcuC/Com/ComConfig/SysPwrMd_h2HSC2_67e1a250RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SysVolMdV_h2HSC2_67e1a250InitValue, /ActiveEcuC/Com/ComConfig/SysVolMdV_h2HSC2_67e1a250RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SysVolMd_h2HSC2_67e1a250InitValue, /ActiveEcuC/Com/ComConfig/SysVolMd_h2HSC2_67e1a250RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SysVolV_h2HSC2_67e1a250InitValue, /ActiveEcuC/Com/ComConfig/SysVolV_h2HSC2_67e1a250RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SysVol_h2HSC2_67e1a250InitValue, /ActiveEcuC/Com/ComConfig/SysVol_h2HSC2_67e1a250RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TBOXAccelZVHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/TBOXAccelZVHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TCAvlbly_h2HSC2_ab4ba2ceInitValue, /ActiveEcuC/Com/ComConfig/TCAvlbly_h2HSC2_ab4ba2ceRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TCSAHSC2_5ee26fe4InitValue, /ActiveEcuC/Com/ComConfig/TCSAHSC2_5ee26fe4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_ACMDHSC4_c0316154InitValue, /ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_ACMDHSC4_c0316154RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_BCMDHSC4_c0316154InitValue, /ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_BCMDHSC4_c0316154RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_STATUS_h4HSC4_c0316154InitValue, /ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_STATUS_h4HSC4_c0316154RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TPMSFHSC4_74dd8a6fInitValue, /ActiveEcuC/Com/ComConfig/TPMSFHSC4_74dd8a6fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TboxP2PRCHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/TboxP2PRCHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TimeDspFmtHSC2_c30fb534InitValue, /ActiveEcuC/Com/ComConfig/TimeDspFmtHSC2_c30fb534RxDataTimeoutSubstitutionValue, 
              /ActiveEcuC/Com/ComConfig/TimeDspFmtHSC4_80f6c9a0InitValue, /ActiveEcuC/Com/ComConfig/TimeDspFmtHSC4_80f6c9a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TrShftLvrPosV_h1HSC2_8bd5df01InitValue, /ActiveEcuC/Com/ComConfig/TrShftLvrPosV_h1HSC2_8bd5df01RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TrShftLvrPos_h1HSC2_8bd5df01InitValue, /ActiveEcuC/Com/ComConfig/TrShftLvrPos_h1HSC2_8bd5df01RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TrlrHitchSwAHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/TrlrHitchSwAHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VCUAccReqStsHSC2_cacaa258InitValue, /ActiveEcuC/Com/ComConfig/VCUAccReqStsHSC2_cacaa258RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VCUAccReqValHSC2_cacaa258InitValue, /ActiveEcuC/Com/ComConfig/VCUAccReqValHSC2_cacaa258RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VCUNRCDAvlblHSC2_cacaa258InitValue, /ActiveEcuC/Com/ComConfig/VCUNRCDAvlblHSC2_cacaa258RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VSELatAccVHSC2_542766fdInitValue, /ActiveEcuC/Com/ComConfig/VSELatAccVHSC2_542766fdRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VSELongtAccVHSC2_542766fdInitValue, /ActiveEcuC/Com/ComConfig/VSELongtAccVHSC2_542766fdRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VSESysAHSC2_5ee26fe4InitValue, /ActiveEcuC/Com/ComConfig/VSESysAHSC2_5ee26fe4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehBkwdSwReqHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/VehBkwdSwReqHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehBkwdSwReqVHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/VehBkwdSwReqVHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehDynYawRateVHSC2_5ee26fe4InitValue, /ActiveEcuC/Com/ComConfig/VehDynYawRateVHSC2_5ee26fe4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehFwdSwReqHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/VehFwdSwReqHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehFwdSwReqVHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/VehFwdSwReqVHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehOdoV_h2HSC2_78aeb97bInitValue, /ActiveEcuC/Com/ComConfig/VehOdoV_h2HSC2_78aeb97bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehRoadWhlLReqHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/VehRoadWhlLReqHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehRoadWhlLReqVHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/VehRoadWhlLReqVHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehRoadWhlRReqHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/VehRoadWhlRReqHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehRoadWhlRReqVHSC4_09f4c130InitValue, /ActiveEcuC/Com/ComConfig/VehRoadWhlRReqVHSC4_09f4c130RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehSideLghtStsHSC2_762c2774InitValue, /ActiveEcuC/Com/ComConfig/VehSideLghtStsHSC2_762c2774RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnVHSC2_49997ba7InitValue, /ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnVHSC2_49997ba7RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnVHSC2_49997ba7InitValue, /ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnVHSC2_49997ba7RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/Width_LRU1_18ef6e8dInitValue, /ActiveEcuC/Com/ComConfig/Width_LRU1_18ef6e8dRxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfo
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfo
  \brief  Contains all I-Pdu Group relevant information
  \details
  Element                 Description
  TxPduInfoIndUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInfoInd
  RxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxPduInfoInd
  RxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxPduInfoInd
  TxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_TxPduInfoInd
  TxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_TxPduInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_IPduGroupInfoType, COM_CONST) Com_IPduGroupInfo[8] = {
    /* Index    TxPduInfoIndUsed  RxPduInfoIndEndIdx                        RxPduInfoIndStartIdx                        TxPduInfoIndEndIdx                        TxPduInfoIndStartIdx                              Referable Keys */
  { /*     0 */            FALSE,                                      36U,                                         0U, COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243, /ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  { /*     1 */             TRUE, COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO,                                       8U,                                         0U },  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  { /*     2 */            FALSE,                                      56U,                                        36U, COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  { /*     3 */             TRUE, COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO,                                      12U,                                         8U },  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  { /*     4 */            FALSE,                                      64U,                                        56U, COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  { /*     5 */             TRUE, COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO,                                      46U,                                        12U },  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  { /*     6 */            FALSE,                                      66U,                                        64U, COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_oLIN00_Rx_fcef2243, /ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  { /*     7 */             TRUE, COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO, COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO,                                      48U,                                        46U }   /* [/ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243, /ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfoOfRxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfoOfRxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_IPduGroupInfoOfRxPduInfoIndType, COM_CONST) Com_IPduGroupInfoOfRxPduInfoInd[66] = {
  /* Index     IPduGroupInfoOfRxPduInfoInd      Referable Keys */
  /*     0 */                           4U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     1 */                           4U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*     2 */                           4U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*     3 */                           4U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*     4 */                           4U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*     5 */                           4U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*     6 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /*     7 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*     8 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*     9 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    10 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  /*    11 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    12 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    13 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    14 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*    15 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*    16 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    17 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    18 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    19 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*    20 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  /*    21 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*    22 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*    23 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*    24 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*    25 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*    26 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*    27 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*    28 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*    29 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*    30 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*    31 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*    32 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*    33 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*    34 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*    35 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*    36 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*    37 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*    38 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*    39 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*    40 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*    41 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*    42 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*    43 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*    44 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*    45 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*    46 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*    47 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*    48 */                           4U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*    49 */                           4U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /* Index     IPduGroupInfoOfRxPduInfoInd      Referable Keys */
  /*    50 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*    51 */                           6U,  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*    52 */                           6U,  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  /*    53 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    54 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    55 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*    56 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    57 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*    58 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*    59 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*    60 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*    61 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*    62 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*    63 */                           2U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*    64 */                           0U,  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*    65 */                           0U   /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfoOfTxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfoOfTxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_IPduGroupInfoOfTxPduInfoIndType, COM_CONST) Com_IPduGroupInfoOfTxPduInfoInd[48] = {
  /* Index     IPduGroupInfoOfTxPduInfoInd      Referable Keys */
  /*     0 */                           1U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  /*     1 */                           7U,  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be] */
  /*     2 */                           7U,  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be] */
  /*     3 */                           1U,  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  /*     4 */                           1U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  /*     5 */                           1U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  /*     6 */                           1U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*     7 */                           1U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  /*     8 */                           1U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  /*     9 */                           1U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  /*    10 */                           3U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    11 */                           3U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*    12 */                           3U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    13 */                           3U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    14 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*    15 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*    16 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be] */
  /*    17 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*    18 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*    19 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be] */
  /*    20 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  /*    21 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*    22 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*    23 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*    24 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*    25 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*    26 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*    27 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*    28 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*    29 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  /*    30 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*    31 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*    32 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*    33 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*    34 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*    35 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*    36 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  /*    37 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  /*    38 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  /*    39 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*    40 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*    41 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*    42 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*    43 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*    44 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*    45 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*    46 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*    47 */                           5U   /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                                       Description
  InitValueUsed                                 TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxSigBufferArrayBasedBufferUsed               TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigBufferArrayBased
  ApplType                                      Application data type.
  BitLength                                     Bit length of the signal or group signal.
  BitPosition                                   Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                                        BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                                    Byte length of the signal or group signal.
  BytePosition                                  Little endian byte position of the signal or group signal within the I-PDU.
  ConstValueArrayBasedInitValueEndIdx           the end index of the 0:n relation pointing to Com_ConstValueArrayBased
  ConstValueArrayBasedInitValueStartIdx         the start index of the 0:n relation pointing to Com_ConstValueArrayBased
  RoutingBufferIdx                              the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64
  RxDataTimeoutSubstitutionValueIdx             the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxPduInfoIdx                                  the index of the 1:1 relation pointing to Com_RxPduInfo
  RxSigBufferArrayBasedBufferLength             the number of relations pointing to Com_RxSigBufferArrayBased
  RxSigBufferArrayBasedRoutingBufferEndIdx      the end index of the 0:n relation pointing to Com_RxSigBufferArrayBased
  RxSigBufferArrayBasedRoutingBufferStartIdx    the start index of the 0:n relation pointing to Com_RxSigBufferArrayBased
  StartByteInPduPosition                        Start Byte position of the signal or group signal within the I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[283] = {
    /* Index    InitValueUsed  RxSigBufferArrayBasedBufferUsed  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  ConstValueArrayBasedInitValueEndIdx                       ConstValueArrayBasedInitValueStartIdx                       RoutingBufferIdx                       RxDataTimeoutSubstitutionValueIdx                       RxPduInfoIdx  RxSigBufferArrayBasedBufferLength  RxSigBufferArrayBasedRoutingBufferEndIdx                       RxSigBufferArrayBasedRoutingBufferStartIdx                       StartByteInPduPosition        Referable Keys */
  { /*     0 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         30U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    0U,                                                     5U,          58U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/ABSAHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*     1 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         32U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    1U,                                                     5U,           0U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/APAAlvRC_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     2 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         40U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    2U,                                                     5U,           0U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/APAChksm_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     3 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          6U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    3U,                                                     5U,           0U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/APACmdEPSSts_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     4 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         39U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    4U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/APACrpSpdReqSts_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*     5 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,         24U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    5U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/APACrpSpdReqVal_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*     6 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         44U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    6U,                                                     5U,          29U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/APACtrlAbotdRsnHSC2_32bfb16e, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  { /*     7 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         30U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    7U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/APAEPBOPReq_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*     8 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         56U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    8U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/APAEPBOpReqValPV_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*     9 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         48U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    9U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/APAEPBReqAlvRC_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    10 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          5U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   10U,                                                     5U,           0U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/APAF_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*    11 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,         32U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   11U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/APAInfoDispReq_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    12 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   12U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/APAMd_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    13 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         38U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   13U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/APANRCDAvlbl_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    14 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         25U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   14U,                                                     5U,           2U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/APAParkngSchedV_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    15 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        7U,         16U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   15U,                                                     5U,           2U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/APAParkngSched_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    16 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,          5U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   16U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/APAReq_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    17 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         55U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   17U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqSts_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    18 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       10U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    0U,                                                     1U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqValPV_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    19 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         16U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   18U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqVal_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    20 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         44U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   19U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/APASCSAlvRC_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    21 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         40U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   20U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/APAShifterPosReqd_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    22 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         46U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   21U,                                                     5U,           2U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/APASlotBearng_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    23 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       11U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    1U,                                                     1U,           2U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/APASlotLngth_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    24 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,         52U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   22U,                                                     5U,           1U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/APASts_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    25 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         58U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   23U,                                                     5U,          24U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/APASwReqHSC2_46783686, /ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  { /*    26 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         58U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   24U,                                                     5U,          13U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/APASwReqHSC4_687c4159, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  { /*    27 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          4U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   25U,                                                     5U,           0U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/APAToqReqSts_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*    28 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    2U,                                                     1U,           0U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/APAToqReqVal_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*    29 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         24U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    3U,                                                     1U,           0U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/APATrgtEPSStrgWhlAng_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*    30 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         32U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    4U,                                                     1U,           2U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/APAVehCrdnatAzmth_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    31 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         50U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    5U,                                                     1U,           2U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/APAVehCrdnatPosX_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    32 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       10U,         56U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    6U,                                                     1U,           2U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/APAVehCrdnatPosY_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    33 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         22U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   26U,                                                     5U,          17U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/AVMAutoViewChgHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    34 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         11U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   27U,                                                     5U,          36U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/AirbagDplHSC2_2128899b, /ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  { /*    35 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         10U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   28U,                                                     4U,          36U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/AirbagDplInvsnHSC2_2128899b, /ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  { /*    36 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         50U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   29U,                                                     5U,          14U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/AlisysrdyHSC4_226d494c, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  { /*    37 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         31U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   30U,                                                     5U,          25U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/BCMAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    38 */         FALSE,                            TRUE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         8U,           0U,                                                       8U,                                                         0U, COM_NO_ROUTINGBUFFERIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          38U,                                8U,                                                            8U,                                                              0U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5, /ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  { /*    39 */         FALSE,                            TRUE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         8U,           0U,                                                       8U,                                                         0U, COM_NO_ROUTINGBUFFERIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          39U,                                8U,                                                           16U,                                                              8U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add, /ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  { /*    40 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          0U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   31U,                                                     5U,          20U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/BCMSSBAHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*    41 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          1U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   32U,                                                     5U,          20U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/BCMSSBAVHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*    42 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,          5U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   33U,                                                     5U,          19U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/BCMSSBFltStsHSC2_34092009, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  { /*    43 */         FALSE,                            TRUE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         8U,           0U,                                                       8U,                                                         0U, COM_NO_ROUTINGBUFFERIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          21U,                                8U,                                                           24U,                                                             16U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  { /*    44 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        5U,          1U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   34U,                                                     5U,          40U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/BMSBscSta_h1HSC4_c182dd1d, /ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  { /*    45 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         35U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   35U,                                                     5U,          26U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/BPMMstrAvlbly_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    46 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         46U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   36U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/BntOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    47 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         10U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   37U,                                                     5U,           8U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/BrkPdlAppdHSC2_70a619c8, /ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    48 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        5U,         16U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   38U,                                                     5U,          34U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/CalendarDayHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*    49 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        5U,         16U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   39U,                                                     5U,          47U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/CalendarDayHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
    /* Index    InitValueUsed  RxSigBufferArrayBasedBufferUsed  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  ConstValueArrayBasedInitValueEndIdx                       ConstValueArrayBasedInitValueStartIdx                       RoutingBufferIdx                       RxDataTimeoutSubstitutionValueIdx                       RxPduInfoIdx  RxSigBufferArrayBasedBufferLength  RxSigBufferArrayBasedRoutingBufferEndIdx                       RxSigBufferArrayBasedRoutingBufferStartIdx                       StartByteInPduPosition        Referable Keys */
  { /*    50 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   40U,                                                     5U,          34U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/CalendarMonthHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*    51 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   41U,                                                     5U,          47U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/CalendarMonthHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*    52 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   42U,                                                     5U,          34U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/CalendarYearHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*    53 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   43U,                                                     5U,          47U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/CalendarYearHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*    54 */         FALSE,                            TRUE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,       56U,          0U,  COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         7U,           0U,                                                       7U,                                                         0U, COM_NO_ROUTINGBUFFERIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,           5U,                                7U,                                                           31U,                                                             24U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85, /ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  { /*    55 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         29U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   44U,                                                     5U,          19U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/DayTimeRunningLampOnHSC2_34092009, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  { /*    56 */         FALSE,                            TRUE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         8U,           0U,                                                       8U,                                                         0U, COM_NO_ROUTINGBUFFERIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,           6U,                                8U,                                                           39U,                                                             31U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3, /ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  { /*    57 */         FALSE,                            TRUE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         8U,           0U,                                                       8U,                                                         0U, COM_NO_ROUTINGBUFFERIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,           7U,                                8U,                                                           47U,                                                             39U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d, /ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  { /*    58 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         13U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   45U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/DipdBeamLghtOnHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    59 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   46U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/DircnIndLampSwStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    60 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       13U,         24U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    7U,                                                     1U,          61U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*    61 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         21U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   47U,                                                     5U,          61U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnRstOcdHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*    62 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         55U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   48U,                                                     5U,          61U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnSrcHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*    63 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         22U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   49U,                                                     5U,          61U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnVHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*    64 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          0U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   50U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/DrvrDoorOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    65 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         12U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   51U,                                                     5U,          36U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSbltAtcHSC2_2128899b, /ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  { /*    66 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         13U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   52U,                                                     5U,          36U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSbltAtcVHSC2_2128899b, /ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  { /*    67 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,          8U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   53U,                                                     5U,          23U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC2_d7b82a4e, /ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  { /*    68 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,         14U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   54U,                                                     5U,          15U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC4_7f07551a, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  { /*    69 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         11U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   55U,                                                     5U,          23U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC2_d7b82a4e, /ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  { /*    70 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          5U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   56U,                                                     5U,          15U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC4_7f07551a, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  { /*    71 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          7U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   57U,                                                     5U,          25U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/ECMAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    72 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         14U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   58U,                                                     5U,          10U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/EPBAppcnStsHSC2_ecbe2b89, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    73 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         12U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   59U,                                                     5U,          10U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/EPBAppcnStsPVHSC2_ecbe2b89, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    74 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,          3U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   60U,                                                     5U,          10U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/EPBAvlblyStsHSC2_ecbe2b89, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    75 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,          0U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   61U,                                                     5U,          10U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/EPBAvlblyStsPVHSC2_ecbe2b89, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    76 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          6U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   62U,                                                     5U,           9U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/EPBSwStsHSC2_20142b17, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    77 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          5U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   63U,                                                     5U,           9U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/EPBSwStsVHSC2_20142b17, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    78 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         16U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   64U,                                                     5U,          11U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/EPSAPAAlvRCHSC2_a6919738, /ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    79 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         24U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   65U,                                                     5U,          11U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/EPSAPAChksmHSC2_a6919738, /ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    80 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          8U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   66U,                                                     5U,          11U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/EPSAPAInhHSC2_a6919738, /ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    81 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          1U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   67U,                                                     3U,          11U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/EPSAPAStsHSC2_a6919738, /ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    82 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   68U,                                                     5U,          31U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/EPTAccelActuPosHSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*    83 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         43U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   69U,                                                     5U,          31U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/EPTAccelActuPosVHSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*    84 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         31U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   70U,                                                     5U,          31U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsHSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*    85 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         16U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   71U,                                                     4U,          31U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsVHSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*    86 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         38U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   72U,                                                     5U,          32U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/EPTRdy_h1HSC2_9f94b166, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  { /*    87 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         17U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   73U,                                                     5U,          31U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/EPTStCmdOn_h1HSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*    88 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          7U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   74U,                                                     5U,          64U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/EnRunAHSC2_235f8f9b, /ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  { /*    89 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         25U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   75U,                                                     5U,          25U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/FICMAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    90 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         23U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   76U,                                                     5U,          17U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/FICMP2PQuitReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    91 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   77U,                                                     5U,          17U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/FICMPLCRtCoverSwReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    92 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          0U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   78U,                                                     5U,          17U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/FICMPLCRtEndSwReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    93 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          4U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   79U,                                                     5U,          17U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/FICMPLCSwReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    94 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         14U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   80U,                                                     5U,          17U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/FICMRouteChangeCheckHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    95 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         12U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   81U,                                                     5U,          17U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/FICMRouteReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    96 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         10U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   82U,                                                     5U,          17U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/FICMSilentSearchCheckHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    97 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          8U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   83U,                                                     5U,          17U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/FICMSilentSearchReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    98 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         59U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   84U,                                                     5U,          41U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/FLDoorHadlSwAHSC4_5c9d774f, /ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  { /*    99 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         32U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    8U,                                                     1U,           3U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/FLObsDist_sech2_SecCAN2_84546eef, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
    /* Index    InitValueUsed  RxSigBufferArrayBasedBufferUsed  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  ConstValueArrayBasedInitValueEndIdx                       ConstValueArrayBasedInitValueStartIdx                       RoutingBufferIdx                       RxDataTimeoutSubstitutionValueIdx                       RxPduInfoIdx  RxSigBufferArrayBasedBufferLength  RxSigBufferArrayBasedRoutingBufferEndIdx                       RxSigBufferArrayBasedRoutingBufferStartIdx                       StartByteInPduPosition        Referable Keys */
  { /*   100 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         44U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   85U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/FLObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   101 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         56U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    9U,                                                     1U,          49U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/FLSideObsDist_sech2_SecCAN2_eb7d27c8, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  { /*   102 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        7U,         56U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   86U,                                                     2U,          62U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/FLTirePrsHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   103 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         63U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   87U,                                                     5U,          62U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/FLTirePrsVHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   104 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         58U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   88U,                                                     5U,          41U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/FRDoorHadlSwAHSC4_5c9d774f, /ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  { /*   105 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         29U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   10U,                                                     1U,           3U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/FRObsDist_sech2_SecCAN2_84546eef, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  { /*   106 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         32U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   89U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/FRObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   107 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         40U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   11U,                                                     1U,          49U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/FRSideObsDist_sech2_SecCAN2_eb7d27c8, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  { /*   108 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        7U,         40U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   90U,                                                     2U,          62U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/FRTirePrsHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   109 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         47U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   91U,                                                     5U,          62U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/FRTirePrsVHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   110 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         14U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   92U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/FrtFogLghtOnHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   111 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         32U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   12U,                                                     1U,           4U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/FrtMidLObsDist_sech2_SecCAN2_8e9167f6, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  { /*   112 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         28U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   93U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/FrtMidLObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   113 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         29U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   13U,                                                     1U,           4U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/FrtMidRObsDist_sech2_SecCAN2_8e9167f6, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  { /*   114 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         16U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   94U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/FrtMidRObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   115 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         48U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   95U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/FrtObsDist_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   116 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   96U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/FrtPDCAudWrnng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   117 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         42U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   97U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/FrtPsngDoorOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   118 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         12U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   98U,                                                     5U,          25U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/HCUAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   119 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        5U,         24U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   99U,                                                     5U,          34U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/HourOfDayHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   120 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        5U,         24U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  100U,                                                     5U,          47U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/HourOfDayHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   121 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         54U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  101U,                                                     5U,           8U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/HydBstrCmpstnReqHSC2_70a619c8, /ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   122 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         30U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  102U,                                                     5U,          25U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/IPCAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   123 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         11U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  103U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/LDircnIOHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   124 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       10U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   14U,                                                     1U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistPlsCtrHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   125 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          6U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  104U,                                                     5U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTRCHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   126 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         24U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   15U,                                                     1U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTmspHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   127 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  105U,                                                     5U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistVHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   128 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          3U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  106U,                                                     5U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlRstOcdHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   129 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          4U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  107U,                                                     5U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlSeqNumHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   130 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         32U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  108U,                                                     1U,          57U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDircnHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   131 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       10U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   16U,                                                     1U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistPCHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   132 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         24U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   17U,                                                     1U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   133 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          6U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  109U,                                                     5U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTRCHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   134 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  110U,                                                     5U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistVHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   135 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          3U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  111U,                                                     5U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlRstOcdHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   136 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          4U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  112U,                                                     5U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlSeqNumHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   137 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  113U,                                                     5U,          50U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LRCTAWrnngHSC4_693ba2af, /ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  { /*   138 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          6U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  114U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/LdspcOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   139 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         15U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  115U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/MainBeamLghtOnHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   140 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,         32U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  116U,                                                     5U,          34U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/MinuteOfHourHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   141 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,         32U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  117U,                                                     5U,          47U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/MinuteOfHourHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   142 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         32U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  118U,                                                     5U,          65U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/NRCDAlvRCHSC2_6ae5c0ff, /ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
  { /*   143 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          5U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  119U,                                                     5U,          65U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/NRCDFHSC2_6ae5c0ff, /ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
  { /*   144 */         FALSE,                            TRUE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         8U,           0U,                                                       8U,                                                         0U, COM_NO_ROUTINGBUFFERIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          30U,                                8U,                                                           55U,                                                             47U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  { /*   145 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         38U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  120U,                                                     5U,          29U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/NRCDSts_h2HSC2_32bfb16e, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  { /*   146 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         51U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  121U,                                                     5U,          28U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/OtsdAirTemCrValMsk_h2HSC2_bc30b68d, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  { /*   147 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         48U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  122U,                                                     5U,          28U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/OtsdAirTemCrValV_h2HSC2_bc30b68d, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  { /*   148 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         56U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  123U,                                                     5U,          28U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/OtsdAirTemCrVal_h2HSC2_bc30b68d, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  { /*   149 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         28U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  124U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/P2PExeAvlblHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
    /* Index    InitValueUsed  RxSigBufferArrayBasedBufferUsed  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  ConstValueArrayBasedInitValueEndIdx                       ConstValueArrayBasedInitValueStartIdx                       RoutingBufferIdx                       RxDataTimeoutSubstitutionValueIdx                       RxPduInfoIdx  RxSigBufferArrayBasedBufferLength  RxSigBufferArrayBasedRoutingBufferEndIdx                       RxSigBufferArrayBasedRoutingBufferStartIdx                       StartByteInPduPosition        Referable Keys */
  { /*   150 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         29U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  125U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/P2PExeAvlblVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   151 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         15U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  126U,                                                     5U,          43U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/P2PSwReqHSC4_8dbecfca, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  { /*   152 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,         40U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  127U,                                                     4U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/PDCCofignSts_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   153 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         60U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  128U,                                                     5U,          24U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/PDCSwReqHSC2_46783686, /ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  { /*   154 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         60U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  129U,                                                     5U,          13U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/PDCSwReqHSC4_687c4159, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  { /*   155 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          4U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  130U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/PDCSysSts_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   156 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         56U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  131U,                                                     5U,          41U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/PEPSSSBAHSC4_5c9d774f, /ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  { /*   157 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         61U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  132U,                                                     5U,          41U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/PEPSSSBAVHSC4_5c9d774f, /ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  { /*   158 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,         52U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  133U,                                                     5U,          42U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/PEPSSSBFltStsHSC4_d21270ac, /ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  { /*   159 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         16U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  134U,                                                     5U,          51U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/Peak_LRU1_18ef6e8d, /ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  { /*   160 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  135U,                                                     5U,          20U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/PwrMdAutoCtrlAvlblHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*   161 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  136U,                                                     5U,          26U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/PwrMdMstrAccryA_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   162 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          3U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  137U,                                                     5U,          26U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/PwrMdMstrRunCrkA_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   163 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          9U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  138U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/RDircnIOHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   164 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       10U,         40U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   18U,                                                     1U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistPlsCtrHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   165 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         38U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  139U,                                                     5U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTRCHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   166 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         56U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   19U,                                                     1U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTmspHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   167 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         34U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  140U,                                                     5U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistVHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   168 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         35U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  141U,                                                     5U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlRstOcdHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   169 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         36U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  142U,                                                     5U,          54U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlSeqNumHSC2_16026180, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   170 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         40U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  143U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/RLDoorOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   171 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         22U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   20U,                                                     1U,           3U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/RLObsDist_sech2_SecCAN2_84546eef, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  { /*   172 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         36U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  144U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RLObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   173 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         24U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   21U,                                                     1U,          49U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/RLSideObsDist_sech2_SecCAN2_eb7d27c8, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  { /*   174 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        7U,         24U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  145U,                                                     2U,          62U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/RLTirePrsHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   175 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         31U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  146U,                                                     5U,          62U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/RLTirePrsVHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   176 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         34U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  147U,                                                     1U,          57U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDircnHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   177 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       10U,         40U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   22U,                                                     1U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistPCHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   178 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         56U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   23U,                                                     1U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   179 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         38U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  148U,                                                     5U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTRCHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   180 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         34U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  149U,                                                     5U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistVHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   181 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         35U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  150U,                                                     5U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlRstOcdHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   182 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         36U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  151U,                                                     5U,          55U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlSeqNumHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   183 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          0U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  152U,                                                     5U,          50U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/RRCTAWrnngHSC4_693ba2af, /ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  { /*   184 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          4U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  153U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/RRDoorOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   185 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         15U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   24U,                                                     1U,           3U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/RRObsDist_sech2_SecCAN2_84546eef, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  { /*   186 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         24U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  154U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/RRObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   187 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   25U,                                                     1U,          49U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/RRSideObsDist_sech2_SecCAN2_eb7d27c8, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  { /*   188 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        7U,          8U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  155U,                                                     2U,          62U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/RRTirePrsHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   189 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         15U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  156U,                                                     5U,          62U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/RRTirePrsVHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   190 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          8U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  157U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/RrFogLghtOnHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   191 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         22U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   26U,                                                     1U,           4U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/RrMidLObsDist_sech2_SecCAN2_8e9167f6, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  { /*   192 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         20U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  158U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/RrMidLObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   193 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         15U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   27U,                                                     1U,           4U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/RrMidRObsDist_sech2_SecCAN2_8e9167f6, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  { /*   194 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  159U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/RrMidRObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   195 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         56U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  160U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/RrObsDist_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   196 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          0U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  161U,                                                     5U,          48U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/RrPDCAudWrnng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   197 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         56U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  162U,                                                     5U,          23U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC2_d7b82a4e, /ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  { /*   198 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         56U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  163U,                                                     5U,          12U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC4_f9bc5d91, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  { /*   199 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   28U,                                                     1U,          16U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SCREEN_COORD_AXHSC4_c0316154, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
    /* Index    InitValueUsed  RxSigBufferArrayBasedBufferUsed  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  ConstValueArrayBasedInitValueEndIdx                       ConstValueArrayBasedInitValueStartIdx                       RoutingBufferIdx                       RxDataTimeoutSubstitutionValueIdx                       RxPduInfoIdx  RxSigBufferArrayBasedBufferLength  RxSigBufferArrayBasedRoutingBufferEndIdx                       RxSigBufferArrayBasedRoutingBufferStartIdx                       StartByteInPduPosition        Referable Keys */
  { /*   200 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         24U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   29U,                                                     1U,          16U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/SCREEN_COORD_AYHSC4_c0316154, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*   201 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         40U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   30U,                                                     1U,          16U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/SCREEN_COORD_BXHSC4_c0316154, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*   202 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         56U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   31U,                                                     1U,          16U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/SCREEN_COORD_BYHSC4_c0316154, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*   203 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         46U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  164U,                                                     5U,          57U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/SCSAPAAcclAHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   204 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         36U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  165U,                                                     5U,          57U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/SCSAPAAlvRCHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   205 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         47U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  166U,                                                     5U,          57U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/SCSAPAAvlblHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   206 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         45U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  167U,                                                     5U,          57U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/SCSNRCDAvlblHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   207 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          3U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  168U,                                                     5U,          25U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SCUAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   208 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  169U,                                                     5U,          35U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SCUDrvrIntrvnAHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  { /*   209 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          3U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  170U,                                                     5U,          35U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SCUNRCDAvlblHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  { /*   210 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         20U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  171U,                                                     5U,          35U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/SCUShifterLvrPosHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  { /*   211 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         28U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  172U,                                                     0U,          35U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/SCUShifterPosInvsnHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  { /*   212 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  173U,                                                     5U,          35U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/SCUShifterPosRCHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  { /*   213 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          5U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  174U,                                                     5U,          25U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SDMAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   214 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,         40U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  175U,                                                     5U,          34U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   215 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,         40U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  176U,                                                     5U,          47U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   216 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         48U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  177U,                                                     5U,          51U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/Status_LRU1_18ef6e8d, /ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  { /*   217 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         16U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  178U,                                                     5U,          52U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/Status_SRU3_67c459fd, /ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  { /*   218 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         16U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   32U,                                                     1U,          53U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/StrgWhlAngHSC2_dccc170c, /ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   219 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          7U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  179U,                                                     5U,          53U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/StrgWhlAngVHSC2_dccc170c, /ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   220 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          4U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  180U,                                                     5U,          16U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SurndViewSelnHSC4_c0316154, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*   221 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          6U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  181U,                                                     5U,          20U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SysBPMEnbdHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*   222 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          4U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  182U,                                                     5U,          20U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SysBPMHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*   223 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,          4U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  183U,                                                     5U,          26U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SysOpnlMd_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   224 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          0U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  184U,                                                     5U,          26U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SysPwrMd_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   225 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          7U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  185U,                                                     5U,          26U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/SysVolMdV_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   226 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         57U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  186U,                                                     5U,          26U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/SysVolMd_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   227 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         32U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  187U,                                                     5U,          26U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/SysVolV_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   228 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         40U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  188U,                                                     5U,          26U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/SysVol_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   229 */          TRUE,                           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       12U,         40U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    0U,                                                     0U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/TBOXAccelZHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   230 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         36U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  189U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/TBOXAccelZVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   231 */         FALSE,                            TRUE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         8U,           0U,                                                       8U,                                                         0U, COM_NO_ROUTINGBUFFERIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          45U,                                8U,                                                           63U,                                                             55U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  { /*   232 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          8U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  190U,                                                     5U,          25U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     1U },  /* [/ActiveEcuC/Com/ComConfig/TCAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   233 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         28U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  191U,                                                     5U,          58U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/TCSAHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*   234 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         23U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  192U,                                                     4U,          46U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/TMSpdV_h1HSC4_d68cf0b9, /ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  { /*   235 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,          8U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   33U,                                                     0U,          46U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/TMSpd_h1HSC4_d68cf0b9, /ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  { /*   236 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,          0U,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   34U,                                                     1U,          51U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/TOF_LRU1_18ef6e8d, /ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  { /*   237 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,          0U,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   35U,                                                     1U,          52U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/TOF_SRU3_67c459fd, /ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  { /*   238 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         20U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  193U,                                                     5U,          16U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_ACMDHSC4_c0316154, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*   239 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         52U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  194U,                                                     5U,          16U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_BCMDHSC4_c0316154, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*   240 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         36U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  195U,                                                     5U,          16U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_STATUS_h4HSC4_c0316154, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*   241 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          0U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  196U,                                                     5U,          63U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/TPMSFHSC4_74dd8a6f, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  { /*   242 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         24U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  197U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/TboxP2PRCHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   243 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         46U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  198U,                                                     5U,          34U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/TimeDspFmtHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   244 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         46U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  199U,                                                     5U,          47U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     5U },  /* [/ActiveEcuC/Com/ComConfig/TimeDspFmtHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   245 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         28U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  200U,                                                     5U,          22U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/TrShftLvrPosV_h1HSC2_8bd5df01, /ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  { /*   246 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         24U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  201U,                                                     5U,          22U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/TrShftLvrPos_h1HSC2_8bd5df01, /ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  { /*   247 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         54U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  202U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/TrlrHitchSwAHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   248 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         53U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  203U,                                                     5U,          33U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/VCUAccReqStsHSC2_cacaa258, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  { /*   249 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         56U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  204U,                                                     5U,          33U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/VCUAccReqValHSC2_cacaa258, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
    /* Index    InitValueUsed  RxSigBufferArrayBasedBufferUsed  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  ConstValueArrayBasedInitValueEndIdx                       ConstValueArrayBasedInitValueStartIdx                       RoutingBufferIdx                       RxDataTimeoutSubstitutionValueIdx                       RxPduInfoIdx  RxSigBufferArrayBasedBufferLength  RxSigBufferArrayBasedRoutingBufferEndIdx                       RxSigBufferArrayBasedRoutingBufferStartIdx                       StartByteInPduPosition        Referable Keys */
  { /*   250 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         52U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  205U,                                                     5U,          33U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/VCUNRCDAvlblHSC2_cacaa258, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  { /*   251 */          TRUE,                           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       12U,         24U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    1U,                                                     0U,          56U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/VSELatAccHSC2_542766fd, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*   252 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          3U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  206U,                                                     5U,          56U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/VSELatAccVHSC2_542766fd, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*   253 */          TRUE,                           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       10U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    2U,                                                     0U,          56U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/VSELongtAccHSC2_542766fd, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*   254 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  207U,                                                     5U,          56U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/VSELongtAccVHSC2_542766fd, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*   255 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         24U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  208U,                                                     5U,          58U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/VSESysAHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*   256 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         21U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  209U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/VehBkwdSwReqHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   257 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         20U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  210U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/VehBkwdSwReqVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   258 */          TRUE,                           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       12U,         40U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    3U,                                                     0U,          58U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/VehDynYawRateHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*   259 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         36U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  211U,                                                     5U,          58U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/VehDynYawRateVHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*   260 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         23U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  212U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/VehFwdSwReqHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   261 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         22U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  213U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/VehFwdSwReqVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   262 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,         53U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  214U,                                                     3U,          37U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     6U },  /* [/ActiveEcuC/Com/ComConfig/VehLckngStaHSC4_0f57ab67, /ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  { /*   263 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         31U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  215U,                                                     5U,          27U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U },  /* [/ActiveEcuC/Com/ComConfig/VehOdoV_h2HSC2_78aeb97b, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  { /*   264 */          TRUE,                           FALSE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       24U,         16U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         3U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                    0U,                                                     0U,          27U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/VehOdo_h2HSC2_78aeb97b, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  { /*   265 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         19U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  216U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/VehRoadWhlLReqHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   266 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         18U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  217U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/VehRoadWhlLReqVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   267 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         17U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  218U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/VehRoadWhlRReqHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   268 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         16U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  219U,                                                     5U,          44U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/VehRoadWhlRReqVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   269 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         56U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  220U,                                                     5U,          18U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     7U },  /* [/ActiveEcuC/Com/ComConfig/VehSideLghtStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*   270 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       15U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   36U,                                                     1U,          61U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   271 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          7U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  221U,                                                     5U,          61U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnVHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   272 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       15U,         40U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           5U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   37U,                                                     1U,          61U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   273 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         39U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  222U,                                                     5U,          61U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     4U },  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnVHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   274 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       14U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   38U,                                                     1U,          59U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnHSC2_cdd3755d, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  { /*   275 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          6U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  223U,                                                     4U,          59U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnVHSC2_cdd3755d, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  { /*   276 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       14U,          8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   39U,                                                     1U,          60U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnHSC2_435c72be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  { /*   277 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,          6U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  224U,                                                     4U,          60U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     0U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnVHSC2_435c72be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  { /*   278 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       14U,         24U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   40U,                                                     1U,          59U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnHSC2_cdd3755d, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  { /*   279 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         22U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  225U,                                                     4U,          59U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnVHSC2_cdd3755d, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  { /*   280 */          TRUE,                           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       14U,         24U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                   41U,                                                     1U,          60U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnHSC2_435c72be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  { /*   281 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         22U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  226U,                                                     4U,          60U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     2U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnVHSC2_435c72be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  { /*   282 */          TRUE,                           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         24U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                                  227U,                                                     5U,          51U,                                0U, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO,                     3U }   /* [/ActiveEcuC/Com/ComConfig/Width_LRU1_18ef6e8d, /ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[283] = {
  /* Index     RxAccessInfoInd      Referable Keys */
  /*     0 */               1U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     1 */               2U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     2 */               3U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     3 */              10U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     4 */              27U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     5 */              28U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     6 */              29U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     7 */               4U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*     8 */               5U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*     9 */               7U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    10 */               8U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    11 */               9U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    12 */              11U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    13 */              12U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    14 */              13U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    15 */              16U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    16 */              17U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    17 */              18U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    18 */              19U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    19 */              20U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    20 */              21U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    21 */              24U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    22 */              14U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    23 */              15U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    24 */              22U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    25 */              23U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    26 */              30U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    27 */              31U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    28 */              32U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    29 */              99U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    30 */             105U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    31 */             171U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    32 */             185U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    33 */             111U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    34 */             113U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    35 */             191U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    36 */             193U,  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    37 */              54U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*    38 */              56U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /*    39 */              57U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*    40 */              47U,  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    41 */             121U,  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    42 */              76U,  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    43 */              77U,  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    44 */              72U,  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  /*    45 */              73U,  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  /*    46 */              74U,  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  /*    47 */              75U,  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  /*    48 */              78U,  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    49 */              79U,  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*    50 */              80U,  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    51 */              81U,  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    52 */             198U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    53 */              26U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    54 */             154U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    55 */              36U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*    56 */              68U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*    57 */              70U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*    58 */             199U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    59 */             200U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    60 */             201U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    61 */             202U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    62 */             220U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    63 */             238U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    64 */             239U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    65 */             240U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    66 */              33U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    67 */              90U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    68 */              91U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    69 */              92U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    70 */              93U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    71 */              94U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    72 */              95U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    73 */              96U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    74 */              97U,  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    75 */              46U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    76 */              58U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    77 */              59U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    78 */              64U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    79 */             110U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    80 */             117U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    81 */             123U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    82 */             138U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    83 */             139U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    84 */             163U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    85 */             170U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    86 */             184U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    87 */             190U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    88 */             247U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    89 */             269U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    90 */              42U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*    91 */              55U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*    92 */              40U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  /*    93 */              41U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  /*    94 */             160U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  /*    95 */             221U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  /*    96 */             222U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  /*    97 */              43U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*    98 */             245U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*    99 */             246U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   100 */              67U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   101 */              69U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   102 */             197U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   103 */              25U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   104 */             153U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   105 */              37U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   106 */              71U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   107 */              89U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   108 */             118U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   109 */             122U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   110 */             207U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   111 */             213U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   112 */             232U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   113 */              45U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   114 */             161U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   115 */             162U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   116 */             223U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   117 */             224U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   118 */             225U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   119 */             226U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   120 */             227U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   121 */             228U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   122 */             263U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*   123 */             264U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*   124 */             146U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   125 */             147U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   126 */             148U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   127 */               6U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   128 */             145U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   129 */             144U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*   130 */              82U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   131 */              83U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   132 */              84U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   133 */              85U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   134 */              87U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   135 */              86U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*   136 */             248U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   137 */             249U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   138 */             250U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   139 */              48U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   140 */              50U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   141 */              52U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   142 */             119U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   143 */             140U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   144 */             214U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   145 */             243U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   146 */             208U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   147 */             209U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   148 */             210U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   149 */             211U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   150 */             212U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   151 */              34U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   152 */              35U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   153 */              65U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   154 */              66U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   155 */             262U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*   156 */              38U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*   157 */              39U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*   158 */              44U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*   159 */              98U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   160 */             104U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   161 */             156U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   162 */             157U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   163 */             158U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*   164 */             151U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*   165 */             149U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   166 */             150U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   167 */             229U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   168 */             230U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   169 */             242U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   170 */             256U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   171 */             257U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   172 */             260U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   173 */             261U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   174 */             265U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   175 */             266U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   176 */             267U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   177 */             268U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   178 */             231U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*   179 */             234U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*   180 */             235U,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*   181 */              49U,  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   182 */              51U,  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   183 */              53U,  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   184 */             120U,  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   185 */             141U,  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   186 */             215U,  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   187 */             244U,  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   188 */             100U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   189 */             106U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   190 */             112U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   191 */             114U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   192 */             115U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   193 */             116U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   194 */             152U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   195 */             155U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   196 */             172U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   197 */             186U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   198 */             192U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   199 */             194U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   200 */             195U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   201 */             196U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   202 */             101U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   203 */             107U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   204 */             173U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   205 */             187U,  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   206 */             137U,  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   207 */             183U,  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   208 */             159U,  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   209 */             216U,  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   210 */             236U,  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   211 */             282U,  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   212 */             217U,  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  /*   213 */             237U,  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  /*   214 */             218U,  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   215 */             219U,  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   216 */             124U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   217 */             125U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   218 */             126U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   219 */             127U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   220 */             128U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   221 */             129U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   222 */             164U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   223 */             165U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   224 */             166U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   225 */             167U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   226 */             168U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   227 */             169U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   228 */             131U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   229 */             132U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   230 */             133U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   231 */             134U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   232 */             135U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   233 */             136U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   234 */             177U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   235 */             178U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   236 */             179U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   237 */             180U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   238 */             181U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   239 */             182U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   240 */             251U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*   241 */             252U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*   242 */             253U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*   243 */             254U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*   244 */             130U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   245 */             176U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   246 */             203U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   247 */             204U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   248 */             205U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   249 */             206U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   250 */               0U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   251 */             233U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   252 */             255U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   253 */             258U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   254 */             259U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   255 */             274U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   256 */             275U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   257 */             278U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   258 */             279U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   259 */             276U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   260 */             277U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   261 */             280U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   262 */             281U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   263 */              60U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   264 */              61U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   265 */              62U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   266 */              63U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   267 */             270U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   268 */             271U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   269 */             272U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   270 */             273U,  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   271 */             102U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   272 */             103U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   273 */             108U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   274 */             109U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   275 */             174U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   276 */             175U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   277 */             188U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   278 */             189U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   279 */             241U,  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*   280 */              88U,  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*   281 */             142U,  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
  /*   282 */             143U   /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduCalloutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_RxPduCalloutFuncPtr
  \brief  Rx I-PDU callout function pointer table.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(ComRxPduCalloutType, COM_CONST) Com_RxPduCalloutFuncPtr[5] = {
  /* Index     RxPduCalloutFuncPtr                           Referable Keys */
  /*     0 */ ComIPduCallout_Read_LRU1_oLIN00_3abd61be ,  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*     1 */ ComIPduCallout_Read_SRU3_oLIN00_3abd61be ,  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  /*     2 */ MessageRX_GW_HSC2_FrP13                  ,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*     3 */ MessageRX_GW_HSC2_HCU_FrP13              ,  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*     4 */ MessageRX_SCS_HSC2_FrP05                    /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                            Description
  RxDefPduBufferEndIdx               the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx             the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigInfoEndIdx                    the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx                  the start index of the 0:n relation pointing to Com_RxSigInfo
  IPduGroupInfoOfRxPduInfoIndUsed    TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfRxPduInfoInd
  RxPduCalloutFuncPtrIdx             the index of the 0:1 relation pointing to Com_RxPduCalloutFuncPtr
  Type                               Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[66] = {
    /* Index    RxDefPduBufferEndIdx  RxDefPduBufferStartIdx  RxSigInfoEndIdx  RxSigInfoStartIdx  IPduGroupInfoOfRxPduInfoIndUsed  RxPduCalloutFuncPtrIdx                    Type                              Referable Keys */
  { /*     0 */                   6U,                     0U,              7U,                0U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  { /*     1 */                  14U,                     6U,             22U,                7U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  { /*     2 */                  22U,                    14U,             29U,               22U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  { /*     3 */                  30U,                    22U,             33U,               29U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  { /*     4 */                  38U,                    30U,             37U,               33U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  { /*     5 */                  45U,                    38U,             38U,               37U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  { /*     6 */                  52U,                    45U,             39U,               38U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*     7 */                  60U,                    52U,             40U,               39U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*     8 */                  68U,                    60U,             42U,               40U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*     9 */                  76U,                    68U,             44U,               42U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    10 */                  78U,                    76U,             48U,               44U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    11 */                  82U,                    78U,             52U,               48U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    12 */                  90U,                    82U,             53U,               52U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    13 */                  98U,                    90U,             55U,               53U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    14 */                 106U,                    98U,             56U,               55U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    15 */                 114U,                   106U,             58U,               56U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    16 */                 122U,                   114U,             66U,               58U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    17 */                 130U,                   122U,             75U,               66U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    18 */                 138U,                   130U,             90U,               75U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    19 */                 146U,                   138U,             92U,               90U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    20 */                 148U,                   146U,             97U,               92U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    21 */                 156U,                   148U,             98U,               97U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    22 */                 164U,                   156U,            100U,               98U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    23 */                 172U,                   164U,            103U,              100U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    24 */                 180U,                   172U,            105U,              103U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    25 */                 186U,                   180U,            113U,              105U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    26 */                 194U,                   186U,            122U,              113U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    27 */                 202U,                   194U,            124U,              122U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    28 */                 210U,                   202U,            127U,              124U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    29 */                 218U,                   210U,            129U,              127U,                            TRUE,                                       2U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    30 */                 226U,                   218U,            130U,              129U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    31 */                 234U,                   226U,            135U,              130U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    32 */                 242U,                   234U,            136U,              135U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    33 */                 250U,                   242U,            139U,              136U,                            TRUE,                                       3U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    34 */                 258U,                   250U,            146U,              139U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    35 */                 266U,                   258U,            151U,              146U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    36 */                 274U,                   266U,            155U,              151U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    37 */                 282U,                   274U,            156U,              155U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    38 */                 290U,                   282U,            157U,              156U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    39 */                 298U,                   290U,            158U,              157U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    40 */                 306U,                   298U,            159U,              158U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    41 */                 314U,                   306U,            163U,              159U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    42 */                 322U,                   314U,            164U,              163U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    43 */                 330U,                   322U,            165U,              164U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    44 */                 338U,                   330U,            178U,              165U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    45 */                 346U,                   338U,            179U,              178U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    46 */                 354U,                   346U,            181U,              179U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    47 */                 362U,                   354U,            188U,              181U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    48 */                 370U,                   362U,            202U,              188U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  { /*    49 */                 378U,                   370U,            206U,              202U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
    /* Index    RxDefPduBufferEndIdx  RxDefPduBufferStartIdx  RxSigInfoEndIdx  RxSigInfoStartIdx  IPduGroupInfoOfRxPduInfoIndUsed  RxPduCalloutFuncPtrIdx                    Type                              Referable Keys */
  { /*    50 */                 386U,                   378U,            208U,              206U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    51 */                 394U,                   386U,            212U,              208U,                            TRUE,                                       0U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Rx_fcef2243] */
  { /*    52 */                 397U,                   394U,            214U,              212U,                            TRUE,                                       1U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Rx_fcef2243] */
  { /*    53 */                 405U,                   397U,            216U,              214U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    54 */                 413U,                   405U,            228U,              216U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    55 */                 421U,                   413U,            240U,              228U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    56 */                 425U,                   421U,            244U,              240U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    57 */                 433U,                   425U,            250U,              244U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    58 */                 441U,                   433U,            255U,              250U,                            TRUE,                                       4U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    59 */                 449U,                   441U,            259U,              255U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    60 */                 457U,                   449U,            263U,              259U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    61 */                 465U,                   457U,            271U,              263U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    62 */                 473U,                   465U,            279U,              271U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    63 */                 481U,                   473U,            280U,              279U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  { /*    64 */                 489U,                   481U,            281U,              280U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  { /*    65 */                 495U,                   489U,            283U,              281U,                            TRUE, COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxPduInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxPduInfoIndType, COM_CONST) Com_RxPduInfoInd[66] = {
  /* Index     RxPduInfoInd      Referable Keys */
  /*     0 */            6U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     1 */            7U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     2 */            8U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     3 */            9U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     4 */           10U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     5 */           11U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     6 */           18U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     7 */           19U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     8 */           20U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     9 */           21U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    10 */           22U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    11 */           23U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    12 */           24U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    13 */           25U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    14 */           26U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    15 */           27U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    16 */           28U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    17 */           29U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    18 */           30U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    19 */           31U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    20 */           32U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    21 */           33U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    22 */           34U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    23 */           35U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    24 */           36U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    25 */           53U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    26 */           54U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    27 */           55U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    28 */           56U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    29 */           57U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    30 */           58U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    31 */           59U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    32 */           60U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    33 */           61U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    34 */           64U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    35 */           65U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    36 */           12U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    37 */           13U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    38 */           14U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    39 */           15U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    40 */           16U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    41 */           17U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    42 */           37U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    43 */           38U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    44 */           39U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    45 */           40U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    46 */           41U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    47 */           42U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    48 */           43U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    49 */           44U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /* Index     RxPduInfoInd      Referable Keys */
  /*    50 */           45U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    51 */           46U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    52 */           47U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    53 */           50U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    54 */           62U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    55 */           63U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    56 */            0U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*    57 */            1U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*    58 */            2U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*    59 */            3U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*    60 */            4U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*    61 */            5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*    62 */           48U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*    63 */           49U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*    64 */           51U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oLIN00_Rx_fcef2243] */
  /*    65 */           52U   /* [/ActiveEcuC/Com/ComConfig/P2P_oLIN00_Rx_fcef2243] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element             Description
  RxAccessInfoIdx     the index of the 1:1 relation pointing to Com_RxAccessInfo
  SignalProcessing
  ValidDlc            Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[283] = {
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*     0 */              1U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     1 */              2U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     2 */              3U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     3 */             10U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     4 */             27U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     5 */             28U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     6 */             29U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  { /*     7 */              4U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*     8 */              5U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*     9 */              7U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    10 */              8U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    11 */              9U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    12 */             11U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    13 */             12U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    14 */             13U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    15 */             16U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    16 */             17U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    17 */             18U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    18 */             19U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    19 */             20U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    20 */             21U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    21 */             24U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  { /*    22 */             14U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    23 */             15U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    24 */             22U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    25 */             23U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    26 */             30U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    27 */             31U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    28 */             32U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  { /*    29 */             99U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  { /*    30 */            105U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  { /*    31 */            171U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  { /*    32 */            185U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  { /*    33 */            111U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  { /*    34 */            113U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  { /*    35 */            191U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  { /*    36 */            193U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  { /*    37 */             54U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  { /*    38 */             56U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  { /*    39 */             57U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  { /*    40 */             47U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    41 */            121U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    42 */             76U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    43 */             77U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    44 */             72U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    45 */             73U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    46 */             74U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    47 */             75U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    48 */             78U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    49 */             79U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*    50 */             80U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    51 */             81U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    52 */            198U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  { /*    53 */             26U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  { /*    54 */            154U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  { /*    55 */             36U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  { /*    56 */             68U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  { /*    57 */             70U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  { /*    58 */            199U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*    59 */            200U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*    60 */            201U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*    61 */            202U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*    62 */            220U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*    63 */            238U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*    64 */            239U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*    65 */            240U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  { /*    66 */             33U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    67 */             90U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    68 */             91U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    69 */             92U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    70 */             93U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    71 */             94U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    72 */             95U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    73 */             96U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    74 */             97U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  { /*    75 */             46U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    76 */             58U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    77 */             59U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    78 */             64U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    79 */            110U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    80 */            117U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    81 */            123U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    82 */            138U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    83 */            139U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    84 */            163U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    85 */            170U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    86 */            184U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    87 */            190U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    88 */            247U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    89 */            269U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  { /*    90 */             42U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  { /*    91 */             55U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  { /*    92 */             40U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*    93 */             41U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*    94 */            160U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*    95 */            221U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*    96 */            222U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  { /*    97 */             43U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  { /*    98 */            245U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  { /*    99 */            246U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   100 */             67U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  { /*   101 */             69U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  { /*   102 */            197U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  { /*   103 */             25U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  { /*   104 */            153U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  { /*   105 */             37U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   106 */             71U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   107 */             89U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   108 */            118U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   109 */            122U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   110 */            207U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   111 */            213U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   112 */            232U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   113 */             45U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   114 */            161U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   115 */            162U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   116 */            223U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   117 */            224U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   118 */            225U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   119 */            226U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   120 */            227U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   121 */            228U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   122 */            263U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  { /*   123 */            264U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  { /*   124 */            146U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  { /*   125 */            147U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  { /*   126 */            148U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  { /*   127 */              6U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  { /*   128 */            145U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  { /*   129 */            144U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  { /*   130 */             82U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*   131 */             83U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*   132 */             84U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*   133 */             85U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*   134 */             87U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  { /*   135 */             86U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  { /*   136 */            248U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  { /*   137 */            249U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  { /*   138 */            250U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  { /*   139 */             48U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   140 */             50U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   141 */             52U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   142 */            119U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   143 */            140U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   144 */            214U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   145 */            243U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  { /*   146 */            208U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  { /*   147 */            209U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  { /*   148 */            210U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  { /*   149 */            211U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   150 */            212U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  { /*   151 */             34U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  { /*   152 */             35U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  { /*   153 */             65U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  { /*   154 */             66U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  { /*   155 */            262U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  { /*   156 */             38U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  { /*   157 */             39U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  { /*   158 */             44U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  { /*   159 */             98U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  { /*   160 */            104U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  { /*   161 */            156U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  { /*   162 */            157U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  { /*   163 */            158U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  { /*   164 */            151U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  { /*   165 */            149U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   166 */            150U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   167 */            229U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   168 */            230U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   169 */            242U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   170 */            256U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   171 */            257U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   172 */            260U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   173 */            261U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   174 */            265U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   175 */            266U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   176 */            267U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   177 */            268U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  { /*   178 */            231U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  { /*   179 */            234U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  { /*   180 */            235U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  { /*   181 */             49U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   182 */             51U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   183 */             53U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   184 */            120U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   185 */            141U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   186 */            215U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   187 */            244U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  { /*   188 */            100U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   189 */            106U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   190 */            112U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   191 */            114U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   192 */            115U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   193 */            116U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   194 */            152U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   195 */            155U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   196 */            172U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   197 */            186U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   198 */            192U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   199 */            194U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   200 */            195U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   201 */            196U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  { /*   202 */            101U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  { /*   203 */            107U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  { /*   204 */            173U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  { /*   205 */            187U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  { /*   206 */            137U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  { /*   207 */            183U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  { /*   208 */            159U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  { /*   209 */            216U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  { /*   210 */            236U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  { /*   211 */            282U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  { /*   212 */            217U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  { /*   213 */            237U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  { /*   214 */            218U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   215 */            219U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   216 */            124U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   217 */            125U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   218 */            126U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   219 */            127U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   220 */            128U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   221 */            129U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   222 */            164U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   223 */            165U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   224 */            166U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   225 */            167U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   226 */            168U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   227 */            169U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  { /*   228 */            131U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   229 */            132U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   230 */            133U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   231 */            134U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   232 */            135U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   233 */            136U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   234 */            177U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   235 */            178U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   236 */            179U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   237 */            180U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   238 */            181U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   239 */            182U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  { /*   240 */            251U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*   241 */            252U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*   242 */            253U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*   243 */            254U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  { /*   244 */            130U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   245 */            176U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   246 */            203U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   247 */            204U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   248 */            205U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   249 */            206U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   250 */              0U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*   251 */            233U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*   252 */            255U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*   253 */            258U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*   254 */            259U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  { /*   255 */            274U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  { /*   256 */            275U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  { /*   257 */            278U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  { /*   258 */            279U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  { /*   259 */            276U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  { /*   260 */            277U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  { /*   261 */            280U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  { /*   262 */            281U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  { /*   263 */             60U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   264 */             61U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   265 */             62U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   266 */             63U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   267 */            270U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   268 */            271U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   269 */            272U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   270 */            273U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  { /*   271 */            102U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   272 */            103U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   273 */            108U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   274 */            109U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   275 */            174U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   276 */            175U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   277 */            188U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   278 */            189U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  { /*   279 */            241U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  { /*   280 */             88U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  { /*   281 */            142U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
  { /*   282 */            143U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U }   /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element       Description
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[8] = {
    /* Index    TimePeriod        Referable Keys */
  { /*     0 */        25U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  { /*     1 */       100U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  { /*     2 */         1U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  { /*     3 */        20U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*     4 */         5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  { /*     5 */        10U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*     6 */         2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  { /*     7 */         0U }   /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element            Description
  TxModeFalseUsed    TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxModeFalse
  TxModeTrueIdx      the index of the 0:1 relation pointing to Com_TxModeTrue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[48] = {
    /* Index    TxModeFalseUsed  TxModeTrueIdx        Referable Keys */
  { /*     0 */            TRUE,            7U },  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  { /*     1 */            TRUE,            7U },  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be] */
  { /*     2 */            TRUE,            7U },  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be] */
  { /*     3 */            TRUE,            7U },  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  { /*     4 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  { /*     5 */            TRUE,            5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*     6 */            TRUE,            5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  { /*     7 */            TRUE,            5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*     8 */            TRUE,            5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  { /*     9 */            TRUE,            7U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  { /*    10 */            TRUE,            5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  { /*    11 */            TRUE,            7U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  { /*    12 */            TRUE,            4U },  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  { /*    13 */            TRUE,            5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  { /*    14 */            TRUE,            3U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  { /*    15 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  { /*    16 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be] */
  { /*    17 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  { /*    18 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  { /*    19 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be] */
  { /*    20 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  { /*    21 */            TRUE,            5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  { /*    22 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  { /*    23 */            TRUE,            5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  { /*    24 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  { /*    25 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*    26 */            TRUE,            1U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  { /*    27 */            TRUE,            0U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  { /*    28 */            TRUE,            4U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  { /*    29 */            TRUE,            7U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  { /*    30 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  { /*    31 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  { /*    32 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  { /*    33 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  { /*    34 */            TRUE,            3U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*    35 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  { /*    36 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*    37 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*    38 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  { /*    39 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  { /*    40 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  { /*    41 */            TRUE,            4U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  { /*    42 */            TRUE,            4U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  { /*    43 */            TRUE,            5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*    44 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  { /*    45 */            TRUE,            6U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  { /*    46 */            TRUE,            2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  { /*    47 */            TRUE,            6U }   /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[8] = {
    /* Index    TimePeriod        Referable Keys */
  { /*     0 */        25U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  { /*     1 */       100U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  { /*     2 */         1U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  { /*     3 */        20U },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*     4 */         5U },  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  { /*     5 */        10U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*     6 */         2U },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  { /*     7 */         0U }   /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduCalloutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_TxPduCalloutFuncPtr
  \brief  Tx I-PDU callout function pointer table.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(ComTxPduCalloutType, COM_CONST) Com_TxPduCalloutFuncPtr[1] = {
  /* Index     TxPduCalloutFuncPtr           Referable Keys */
  /*     0 */ MessageTX_P2P_HSC2_FrP00    /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                     Description
  TxPduInitValueEndIdx        the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx      the start index of the 0:n relation pointing to Com_TxPduInitValue
  TxBufferUsed                TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer
  ExternalId                  External ID used to call PduR_ComTransmit().
  MetaDataLength              Length of MetaData.
  TxBufferLength              the number of relations pointing to Com_TxBuffer
  TxPduCalloutFuncPtrIdx      the index of the 0:1 relation pointing to Com_TxPduCalloutFuncPtr
  TxPduTTCalloutFuncPtrIdx    the index of the 0:1 relation pointing to Com_TxPduTTCalloutFuncPtr
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[48] = {
    /* Index    TxPduInitValueEndIdx  TxPduInitValueStartIdx  TxBufferUsed  ExternalId                                                         MetaDataLength  TxBufferLength  TxPduCalloutFuncPtrIdx                    TxPduTTCalloutFuncPtrIdx                          Referable Keys */
  { /*     0 */                   7U,                     0U,         TRUE,          PduRConf_PduRSrcPdu_SRC_Can_PT_DIAG_DTCInfo_P2P_0fb271d2,             0U,             7U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  { /*     1 */                   8U,                     7U,         TRUE,                 PduRConf_PduRSrcPdu_SRC_Lin_PT_Init_LRU1_45618847,             0U,             1U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO,                                         0U },  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  { /*     2 */                  10U,                     8U,         TRUE,                 PduRConf_PduRSrcPdu_SRC_Lin_PT_Init_SRU3_45618847,             0U,             2U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO,                                         1U },  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  { /*     3 */                  17U,                    10U,         TRUE,      PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_DIAG_DTCInfo_APA_0fb271d2,             0U,             7U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  { /*     4 */                  23U,                    17U,         TRUE,            PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP00_0fb271d2,             0U,             6U,                                       0U, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  { /*     5 */                  31U,                    23U,         TRUE,            PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP01_0fb271d2,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  { /*     6 */                  39U,                    31U,         TRUE,            PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP02_0fb271d2,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  { /*     7 */                  47U,                    39U,         TRUE,            PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP03_0fb271d2,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  { /*     8 */                  55U,                    47U,         TRUE,            PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrP04_0fb271d2,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  { /*     9 */                  63U,                    55U,         TRUE,            PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC2_FrS01_0fb271d2,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  { /*    10 */                  71U,                    63U,         TRUE,            PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC4_FrP03_c4eea277,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  { /*    11 */                  79U,                    71U,         TRUE,            PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_HSC4_FrS01_c4eea277,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  { /*    12 */                  87U,                    79U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_IECU_HSC4_FrP01_c4eea277,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  { /*    13 */                  95U,                    87U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_IECU_HSC4_FrP02_c4eea277,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  { /*    14 */                 103U,                    95U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_BCM_FrP03_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    15 */                 111U,                   103U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_BCM_FrP04_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    16 */                 113U,                   111U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_BCM_FrP07_427ad0d9,             0U,             2U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    17 */                 121U,                   113U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_ECM_FrP00_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    18 */                 129U,                   121U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_EPB_FrP00_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    19 */                 131U,                   129U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_EPB_FrP01_427ad0d9,             0U,             2U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    20 */                 135U,                   131U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_EPS_FrP02_427ad0d9,             0U,             4U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    21 */                 143U,                   135U,         TRUE,      PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_FICM_FrP02_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    22 */                 151U,                   143U,         TRUE,      PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_FICM_FrP08_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    23 */                 159U,                   151U,         TRUE,      PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_FICM_FrP18_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    24 */                 165U,                   159U,         TRUE,        PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP00_427ad0d9,             0U,             6U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    25 */                 173U,                   165U,         TRUE,        PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP01_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    26 */                 181U,                   173U,         TRUE,        PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP08_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    27 */                 189U,                   181U,         TRUE,        PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP10_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    28 */                 197U,                   189U,         TRUE,        PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrP13_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    29 */                 205U,                   197U,         TRUE,        PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_GW_FrS00_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    30 */                 213U,                   205U,         TRUE,   PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_HCU_ECM_FrP04_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    31 */                 221U,                   213U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_HCU_FrP00_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    32 */                 229U,                   221U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_HCU_FrP01_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    33 */                 237U,                   229U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_HCU_FrP13_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    34 */                 245U,                   237U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_IPK_FrP06_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    35 */                 253U,                   245U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SAS_FrP00_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    36 */                 261U,                   253U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP00_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    37 */                 269U,                   261U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP01_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    38 */                 273U,                   269U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP02_427ad0d9,             0U,             4U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    39 */                 281U,                   273U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP03_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    40 */                 289U,                   281U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP05_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    41 */                 297U,                   289U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP11_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    42 */                 305U,                   297U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP12_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    43 */                 313U,                   305U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCS_FrP15_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    44 */                 321U,                   313U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SCU_FrP00_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    45 */                 329U,                   321U,         TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_SDM_FrP00_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    46 */                 337U,                   329U,         TRUE,        PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_TC_FrP07_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  { /*    47 */                 345U,                   337U,         TRUE, PduRConf_PduRSrcPdu_SRC_Can_PT_P2P_SecCH_Tester_GW_FrP14_427ad0d9,             0U,             8U, COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO, COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduInfoIndType, COM_CONST) Com_TxPduInfoInd[48] = {
  /* Index     TxPduInfoInd      Referable Keys */
  /*     0 */            0U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */            3U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     2 */            4U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     3 */            5U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */            6U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */            7U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */            8U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */            9U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */           10U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*     9 */           11U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    10 */           12U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */           13U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */           14U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    13 */           15U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    14 */           16U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */           17U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */           18U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */           19U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */           20U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */           21U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */           22U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */           23U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */           24U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */           25U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */           26U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */           27U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */           28U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */           29U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */           30U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */           31U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */           32U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */           33U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */           34U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */           35U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */           36U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */           37U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */           38U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */           39U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */           40U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */           41U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */           42U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */           43U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */           44U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */           45U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */           46U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */           47U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */            1U,  /* [/ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*    47 */            2U   /* [/ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[345] = {
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  /*     1 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  /*     2 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  /*     3 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  /*     4 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  /*     5 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  /*     6 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  /*     7 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be] */
  /*     8 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be] */
  /*     9 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be] */
  /*    10 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  /*    11 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  /*    12 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  /*    13 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  /*    14 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  /*    15 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  /*    16 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  /*    17 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  /*    18 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  /*    19 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  /*    20 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  /*    21 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  /*    22 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  /*    23 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  /*    24 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  /*    25 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  /*    26 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  /*    27 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  /*    28 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  /*    29 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  /*    30 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  /*    31 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*    32 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*    33 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*    34 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*    35 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*    36 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*    37 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*    38 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*    39 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  /*    40 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  /*    41 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  /*    42 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  /*    43 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  /*    44 */           0x01U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  /*    45 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  /*    46 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  /*    47 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  /*    48 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  /*    49 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  /* Index     TxPduInitValue      Referable Keys */
  /*    50 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  /*    51 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  /*    52 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  /*    53 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  /*    54 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  /*    55 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  /*    56 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  /*    57 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  /*    58 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  /*    59 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  /*    60 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  /*    61 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  /*    62 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  /*    63 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    64 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    65 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    66 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    67 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    68 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    69 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    70 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    71 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*    72 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*    73 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*    74 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*    75 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*    76 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*    77 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*    78 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*    79 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    80 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    81 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    82 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    83 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    84 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    85 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    86 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    87 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    88 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    89 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    90 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    91 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    92 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    93 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    94 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    95 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*    96 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*    97 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*    98 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*    99 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   100 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*   101 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*   102 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*   103 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   104 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   105 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   106 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   107 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   108 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   109 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   110 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   111 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be] */
  /*   112 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be] */
  /*   113 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   114 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   115 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   116 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   117 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   118 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   119 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   120 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   121 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   122 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   123 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   124 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   125 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   126 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   127 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   128 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   129 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be] */
  /*   130 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be] */
  /*   131 */           0x0EU,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  /*   132 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  /*   133 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  /*   134 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  /*   135 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   136 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   137 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   138 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   139 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   140 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   141 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   142 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   143 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   144 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   145 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   146 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   147 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   148 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   149 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   150 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   151 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   152 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   153 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   154 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   155 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   156 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   157 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   158 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   159 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*   160 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*   161 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*   162 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*   163 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*   164 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*   165 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   166 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   167 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   168 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   169 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   170 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   171 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   172 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   173 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   174 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   175 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   176 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   177 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   178 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   179 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   180 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   181 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   182 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   183 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   184 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   185 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   186 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   187 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   188 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   189 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   190 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   191 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   192 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   193 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   194 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   195 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   196 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   197 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  /*   198 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  /*   199 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   200 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  /*   201 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  /*   202 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  /*   203 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  /*   204 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  /*   205 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   206 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   207 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   208 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   209 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   210 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   211 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   212 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   213 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   214 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   215 */           0x01U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   216 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   217 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   218 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   219 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   220 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   221 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   222 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   223 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   224 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   225 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   226 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   227 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   228 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   229 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   230 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   231 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   232 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   233 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   234 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   235 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   236 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   237 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   238 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   239 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   240 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   241 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   242 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   243 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   244 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   245 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   246 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   247 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   248 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   249 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   250 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   251 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   252 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   253 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  /*   254 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  /*   255 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  /*   256 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  /*   257 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  /*   258 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  /*   259 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  /*   260 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  /*   261 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  /*   262 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  /*   263 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  /*   264 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  /*   265 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  /*   266 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  /*   267 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  /*   268 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  /*   269 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  /*   270 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  /*   271 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  /*   272 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  /*   273 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   274 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   275 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   276 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   277 */           0x0FU,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   278 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   279 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   280 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   281 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   282 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   283 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   284 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   285 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   286 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   287 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   288 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   289 */           0x40U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   290 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   291 */           0x40U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   292 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   293 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   294 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   295 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   296 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   297 */           0x40U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   298 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   299 */           0x40U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   300 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   301 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   302 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   303 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   304 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   305 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*   306 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*   307 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*   308 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*   309 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*   310 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*   311 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*   312 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*   313 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   314 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   315 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   316 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   317 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   318 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   319 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   320 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   321 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   322 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   323 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   324 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   325 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   326 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   327 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   328 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   329 */           0x80U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   330 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   331 */           0x80U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   332 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   333 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   334 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   335 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   336 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   337 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   338 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   339 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   340 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   341 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   342 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   343 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   344 */           0x00U   /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduTTCalloutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_TxPduTTCalloutFuncPtr
  \brief  Tx I-PDU trigger transmit callout function pointer table.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(ComTxPduCalloutType, COM_CONST) Com_TxPduTTCalloutFuncPtr[2] = {
  /* Index     TxPduTTCalloutFuncPtr                                        Referable Keys */
  /*     0 */ ComIPduTriggerTransmitCallout_Init_LRU1_oLIN00_3abd61be ,  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be] */
  /*     1 */ ComIPduTriggerTransmitCallout_Init_SRU3_oLIN00_3abd61be    /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[200] = {
    /* Index    TxBufferEndIdx  TxBufferStartIdx  ApplType                         BitLength  BitPosition  BusAcc                              ByteLength  BytePosition  StartByteInPduPosition  TxPduInfoIdx        Referable Keys */
  { /*     0 */           285U,             284U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         30U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          40U },  /* [/ActiveEcuC/Com/ComConfig/ABSA_SecCAN2_72648180, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  { /*     1 */            22U,              21U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         32U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           4U,                     4U,           4U },  /* [/ActiveEcuC/Com/ComConfig/APAAlvRCHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  { /*     2 */            23U,              22U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         40U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           5U,                     5U,           4U },  /* [/ActiveEcuC/Com/ComConfig/APAChksmHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  { /*     3 */            18U,              17U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,          6U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,           4U },  /* [/ActiveEcuC/Com/ComConfig/APACmdEPSStsHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  { /*     4 */            28U,              27U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         39U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APACrpSpdReqStsHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*     5 */            27U,              26U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         24U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APACrpSpdReqValHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*     6 */           195U,             194U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         44U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          28U },  /* [/ActiveEcuC/Com/ComConfig/APACtrlAbotdRsn_SecCAN2_11614789, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  { /*     7 */            27U,              26U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         30U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APAEPBOPReqHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*     8 */            31U,              30U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         56U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           7U,                     7U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APAEPBOpReqValPVHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*     9 */            30U,              29U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         48U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APAEPBReqAlvRCHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    10 */            18U,              17U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          5U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,           4U },  /* [/ActiveEcuC/Com/ComConfig/APAFHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    11 */            28U,              27U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         32U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APAInfoDispReqHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    12 */            24U,              23U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,          2U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APAMdHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    13 */            28U,              27U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         38U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APANRCDAvlblHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    14 */            34U,              33U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        7U,         16U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,           6U },  /* [/ActiveEcuC/Com/ComConfig/APAParkngSchedHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    15 */            35U,              34U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         25U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,           6U },  /* [/ActiveEcuC/Com/ComConfig/APAParkngSchedVHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    16 */            24U,              23U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,          5U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APAReqHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    17 */            30U,              29U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         55U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqStsHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    18 */            26U,              25U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         16U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           2U,                     2U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqValHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    19 */            25U,              23U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqValPVHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    20 */            29U,              28U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         44U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APASCSAlvRCHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    21 */            29U,              28U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         40U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APAShifterPosReqdHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    22 */            37U,              36U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         46U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,           6U },  /* [/ActiveEcuC/Com/ComConfig/APASlotBearngHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    23 */            33U,              31U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       11U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,           6U },  /* [/ActiveEcuC/Com/ComConfig/APASlotLngthHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    24 */            30U,              29U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,         52U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,           5U },  /* [/ActiveEcuC/Com/ComConfig/APAStsHSC2_a845052a, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be] */
  { /*    25 */           151U,             150U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         58U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,          22U },  /* [/ActiveEcuC/Com/ComConfig/APASwReq_SecCAN2_0e098acc, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  { /*    26 */            18U,              17U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          4U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,           4U },  /* [/ActiveEcuC/Com/ComConfig/APAToqReqStsHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    27 */            19U,              17U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,           4U },  /* [/ActiveEcuC/Com/ComConfig/APAToqReqValHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    28 */            21U,              19U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         24U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2U,           3U,                     2U,           4U },  /* [/ActiveEcuC/Com/ComConfig/APATrgtEPSStrgWhlAngHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be] */
  { /*    29 */            36U,              34U,  COM_UINT16_APPLTYPEOFTXSIGINFO,        9U,         32U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           4U,                     3U,           6U },  /* [/ActiveEcuC/Com/ComConfig/APAVehCrdnatAzmthHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    30 */            38U,              36U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12U,         50U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           6U,                     5U,           6U },  /* [/ActiveEcuC/Com/ComConfig/APAVehCrdnatPosXHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    31 */            39U,              37U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,         56U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           7U,                     6U,           6U },  /* [/ActiveEcuC/Com/ComConfig/APAVehCrdnatPosYHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  { /*    32 */            90U,              89U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         16U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           2U,                     2U,          13U },  /* [/ActiveEcuC/Com/ComConfig/AutoDrvngSysStsHSC4_cdb8af8b, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  { /*    33 */           163U,             162U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         31U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          24U },  /* [/ActiveEcuC/Com/ComConfig/BCMAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  { /*    34 */           170U,             169U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         35U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          25U },  /* [/ActiveEcuC/Com/ComConfig/BPMMstrAvlbly_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*    35 */           109U,             108U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         44U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          15U },  /* [/ActiveEcuC/Com/ComConfig/BntOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  { /*    36 */           240U,             239U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        5U,         16U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          34U },  /* [/ActiveEcuC/Com/ComConfig/CalendarDay_SecCAN2_ee8bd5bd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*    37 */           239U,             238U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          8U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,          34U },  /* [/ActiveEcuC/Com/ComConfig/CalendarMonth_SecCAN2_ee8bd5bd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*    38 */           238U,             237U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           0U,                     0U,          34U },  /* [/ActiveEcuC/Com/ComConfig/CalendarYear_SecCAN2_ee8bd5bd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*    39 */            17U,              10U, COM_UINT8_N_APPLTYPEOFTXSIGINFO,       56U,          0U,  COM_ARRAY_BASED_BUSACCOFTXSIGINFO,         7U,           0U,                     0U,           3U },  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationAPAHSC2_c3e0343e, /ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be] */
  { /*    40 */             7U,               0U, COM_UINT8_N_APPLTYPEOFTXSIGINFO,       56U,          0U,  COM_ARRAY_BASED_BUSACCOFTXSIGINFO,         7U,           0U,                     0U,           0U },  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationP2PHSC2_daa1a8e8, /ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be] */
  { /*    41 */           308U,             307U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         21U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          43U },  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnRstOcd_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*    42 */           312U,             311U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         55U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,          43U },  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnSrc_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*    43 */           308U,             307U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         22U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          43U },  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnV_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*    44 */           309U,             307U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       13U,         24U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           3U,                     2U,          43U },  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvn_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*    45 */           109U,             108U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         46U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          15U },  /* [/ActiveEcuC/Com/ComConfig/DrvrDoorOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  { /*    46 */           323U,             322U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         13U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,          45U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSbltAtcV_SecCAN2_0cace912, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  { /*    47 */           323U,             322U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         12U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,          45U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSbltAtc_SecCAN2_0cace912, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  { /*    48 */           153U,             151U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,         14U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         0U,           1U,                     0U,          23U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMd_SecCAN2_19729e8f, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  { /*    49 */           152U,             151U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,          5U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          23U },  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearng_SecCAN2_19729e8f, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
    /* Index    TxBufferEndIdx  TxBufferStartIdx  ApplType                         BitLength  BitPosition  BusAcc                              ByteLength  BytePosition  StartByteInPduPosition  TxPduInfoIdx        Referable Keys */
  { /*    50 */           160U,             159U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          7U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          24U },  /* [/ActiveEcuC/Com/ComConfig/ECMAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  { /*    51 */           131U,             130U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         14U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,          19U },  /* [/ActiveEcuC/Com/ComConfig/EPBAppcnSts_SecCAN2_ed3af02c, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be] */
  { /*    52 */           130U,             129U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,          0U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          19U },  /* [/ActiveEcuC/Com/ComConfig/EPBAvlblyStsPV_SecCAN2_ed3af02c, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be] */
  { /*    53 */           130U,             129U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,          3U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          19U },  /* [/ActiveEcuC/Com/ComConfig/EPBAvlblySts_SecCAN2_ed3af02c, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be] */
  { /*    54 */           122U,             121U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          5U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          18U },  /* [/ActiveEcuC/Com/ComConfig/EPBSwStsV_SecCAN2_2190f0b2, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  { /*    55 */           122U,             121U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,          6U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          18U },  /* [/ActiveEcuC/Com/ComConfig/EPBSwSts_SecCAN2_2190f0b2, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  { /*    56 */           134U,             133U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         16U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           2U,                     2U,          20U },  /* [/ActiveEcuC/Com/ComConfig/EPSAPAAlvRC_SecCAN2_98082ad5, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  { /*    57 */           135U,             134U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         24U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           3U,                     3U,          20U },  /* [/ActiveEcuC/Com/ComConfig/EPSAPAChksm_SecCAN2_98082ad5, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  { /*    58 */           133U,             132U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          8U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           1U,                     1U,          20U },  /* [/ActiveEcuC/Com/ComConfig/EPSAPAInh_SecCAN2_98082ad5, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  { /*    59 */           132U,             131U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          1U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          20U },  /* [/ActiveEcuC/Com/ComConfig/EPSAPASts_SecCAN2_98082ad5, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be] */
  { /*    60 */           219U,             218U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         43U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          31U },  /* [/ActiveEcuC/Com/ComConfig/EPTAccelActuPosV_SecCAN2_7ebad171, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  { /*    61 */           214U,             213U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           0U,                     0U,          31U },  /* [/ActiveEcuC/Com/ComConfig/EPTAccelActuPos_SecCAN2_7ebad171, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  { /*    62 */           216U,             215U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         16U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          31U },  /* [/ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsV_SecCAN2_7ebad171, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  { /*    63 */           217U,             216U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         31U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          31U },  /* [/ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptSts_SecCAN2_7ebad171, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  { /*    64 */           226U,             225U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         38U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          32U },  /* [/ActiveEcuC/Com/ComConfig/EPTRdy_h1_SecCAN2_b210d1ef, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  { /*    65 */           216U,             215U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         17U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          31U },  /* [/ActiveEcuC/Com/ComConfig/EPTStCmdOn_h1_SecCAN2_7ebad171, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  { /*    66 */           114U,             113U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          7U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          17U },  /* [/ActiveEcuC/Com/ComConfig/EnRunA_SecCAN2_221bb172, /ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  { /*    67 */           163U,             162U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         25U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          24U },  /* [/ActiveEcuC/Com/ComConfig/FICMAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  { /*    68 */            45U,              44U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         44U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,           7U },  /* [/ActiveEcuC/Com/ComConfig/FLObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*    69 */            55U,              53U,  COM_UINT16_APPLTYPEOFTXSIGINFO,        9U,         56U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           7U,                     6U,           8U },  /* [/ActiveEcuC/Com/ComConfig/FLSideObsDistHSC2_e0a50b4e, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  { /*    70 */            44U,              43U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         32U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,           7U },  /* [/ActiveEcuC/Com/ComConfig/FRObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*    71 */            53U,              51U,  COM_UINT16_APPLTYPEOFTXSIGINFO,        9U,         40U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           5U,                     4U,           8U },  /* [/ActiveEcuC/Com/ComConfig/FRSideObsDistHSC2_e0a50b4e, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  { /*    72 */            43U,              42U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         28U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,           7U },  /* [/ActiveEcuC/Com/ComConfig/FrtMidLObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*    73 */            42U,              41U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         16U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,           7U },  /* [/ActiveEcuC/Com/ComConfig/FrtMidRObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*    74 */            46U,              45U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         48U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           6U,                     6U,           7U },  /* [/ActiveEcuC/Com/ComConfig/FrtObsDistHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*    75 */            41U,              40U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         12U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,           7U },  /* [/ActiveEcuC/Com/ComConfig/FrtPDCAudWrnngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*    76 */           109U,             108U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         42U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          15U },  /* [/ActiveEcuC/Com/ComConfig/FrtPsngDoorOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  { /*    77 */           161U,             160U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         12U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,          24U },  /* [/ActiveEcuC/Com/ComConfig/HCUAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  { /*    78 */            86U,              85U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         48U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,          12U },  /* [/ActiveEcuC/Com/ComConfig/HD_AVMCurViewHSC4_4337a868, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  { /*    79 */            87U,              86U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         56U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,          12U },  /* [/ActiveEcuC/Com/ComConfig/HD_AVMErrorDisplay_h4HSC4_4337a868, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  { /*    80 */            87U,              86U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         60U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,          12U },  /* [/ActiveEcuC/Com/ComConfig/HD_AVMInfoDisplayHSC4_4337a868, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  { /*    81 */            86U,              85U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         52U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,          12U },  /* [/ActiveEcuC/Com/ComConfig/HD_AVMVideoFmtStaHSC4_4337a868, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  { /*    82 */            85U,              84U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         40U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          12U },  /* [/ActiveEcuC/Com/ComConfig/HD_AVMsysrdyHSC4_4337a868, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  { /*    83 */           241U,             240U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        5U,         24U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          34U },  /* [/ActiveEcuC/Com/ComConfig/HourOfDay_SecCAN2_ee8bd5bd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*    84 */            63U,              55U, COM_UINT8_N_APPLTYPEOFTXSIGINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFTXSIGINFO,         8U,           0U,                     0U,           9U },  /* [/ActiveEcuC/Com/ComConfig/IECUToBCMRmtCtrlPotclHSC2_4372be29, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be] */
  { /*    85 */            79U,              71U, COM_UINT8_N_APPLTYPEOFTXSIGINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFTXSIGINFO,         8U,           0U,                     0U,          11U },  /* [/ActiveEcuC/Com/ComConfig/IECUToTBOXCtrlPotclHSC4_ccb7c509, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  { /*    86 */           163U,             162U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         30U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          24U },  /* [/ActiveEcuC/Com/ComConfig/IPCAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  { /*    87 */           108U,             107U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         37U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          15U },  /* [/ActiveEcuC/Com/ComConfig/LDircnIO_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  { /*    88 */           255U,             253U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,          36U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistPlsCtr_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*    89 */           254U,             253U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,          6U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          36U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTRC_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*    90 */           257U,             255U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         24U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2U,           3U,                     2U,          36U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTmsp_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*    91 */           254U,             253U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          2U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          36U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistV_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*    92 */           254U,             253U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          3U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          36U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlRstOcd_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*    93 */           254U,             253U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,          4U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          36U },  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlSeqNum_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*    94 */           278U,             277U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         32U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          39U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDircn_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  { /*    95 */           263U,             261U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,          37U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistPC_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*    96 */           262U,             261U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,          6U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          37U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTRC_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*    97 */           265U,             263U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         24U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2U,           3U,                     2U,          37U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistT_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*    98 */           262U,             261U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          2U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          37U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistV_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*    99 */           262U,             261U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          3U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          37U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlRstOcd_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
    /* Index    TxBufferEndIdx  TxBufferStartIdx  ApplType                         BitLength  BitPosition  BusAcc                              ByteLength  BytePosition  StartByteInPduPosition  TxPduInfoIdx        Referable Keys */
  { /*   100 */           262U,             261U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,          4U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          37U },  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlSeqNum_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*   101 */           111U,             109U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         63U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         0U,           7U,                     6U,          15U },  /* [/ActiveEcuC/Com/ComConfig/LdspcOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  { /*   102 */           242U,             241U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         32U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          34U },  /* [/ActiveEcuC/Com/ComConfig/MinuteOfHour_SecCAN2_ee8bd5bd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*   103 */           344U,             343U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         48U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           6U,                     6U,          47U },  /* [/ActiveEcuC/Com/ComConfig/NRCDAlvRC_SecCAN2_d64f184b, /ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  { /*   104 */           340U,             339U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         21U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          47U },  /* [/ActiveEcuC/Com/ComConfig/NRCDF_SecCAN2_d64f184b, /ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  { /*   105 */           205U,             197U, COM_UINT8_N_APPLTYPEOFTXSIGINFO,       64U,          0U,  COM_ARRAY_BASED_BUSACCOFTXSIGINFO,         8U,           0U,                     0U,          29U },  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2_SecCAN2_63a2ef2a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be] */
  { /*   106 */           193U,             192U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         24U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          28U },  /* [/ActiveEcuC/Com/ComConfig/NRCDSts_h2_SecCAN2_11614789, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  { /*   107 */           188U,             187U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         51U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,          27U },  /* [/ActiveEcuC/Com/ComConfig/OtsdAirTemCrValMsk_h2_SecCAN2_9fee406a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  { /*   108 */           188U,             187U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         48U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,          27U },  /* [/ActiveEcuC/Com/ComConfig/OtsdAirTemCrValV_h2_SecCAN2_9fee406a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  { /*   109 */           189U,             188U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         56U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           7U,                     7U,          27U },  /* [/ActiveEcuC/Com/ComConfig/OtsdAirTemCrVal_h2_SecCAN2_9fee406a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  { /*   110 */            64U,              63U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           0U,                     0U,          10U },  /* [/ActiveEcuC/Com/ComConfig/P2PACTMdChngTmotHSC4_65a57977, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  { /*   111 */            65U,              64U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          8U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           1U,                     1U,          10U },  /* [/ActiveEcuC/Com/ComConfig/P2PDisplayHSC4_65a57977, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  { /*   112 */            66U,              65U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         20U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          10U },  /* [/ActiveEcuC/Com/ComConfig/P2PProgressHSC4_65a57977, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  { /*   113 */            45U,              44U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,         40U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,           7U },  /* [/ActiveEcuC/Com/ComConfig/PDCCofignStsHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   114 */           151U,             150U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         60U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,          22U },  /* [/ActiveEcuC/Com/ComConfig/PDCSwReq_SecCAN2_0e098acc, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  { /*   115 */            40U,              39U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          4U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,           7U },  /* [/ActiveEcuC/Com/ComConfig/PDCSysStsHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   116 */           166U,             165U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          2U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          25U },  /* [/ActiveEcuC/Com/ComConfig/PwrMdMstrAccryA_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*   117 */           166U,             165U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          3U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          25U },  /* [/ActiveEcuC/Com/ComConfig/PwrMdMstrRunCrkA_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*   118 */           108U,             107U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         38U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          15U },  /* [/ActiveEcuC/Com/ComConfig/RDircnIO_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  { /*   119 */           259U,             257U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,         40U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           5U,                     4U,          36U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistPlsCtr_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*   120 */           258U,             257U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         38U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          36U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTRC_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*   121 */           261U,             259U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         56U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2U,           7U,                     6U,          36U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTmsp_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*   122 */           258U,             257U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         34U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          36U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistV_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*   123 */           258U,             257U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         35U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          36U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlRstOcd_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*   124 */           258U,             257U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         36U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          36U },  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlSeqNum_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be] */
  { /*   125 */           110U,             109U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         49U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,          15U },  /* [/ActiveEcuC/Com/ComConfig/RLDoorOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  { /*   126 */            44U,              43U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         36U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,           7U },  /* [/ActiveEcuC/Com/ComConfig/RLObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   127 */            51U,              49U,  COM_UINT16_APPLTYPEOFTXSIGINFO,        9U,         24U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           3U,                     2U,           8U },  /* [/ActiveEcuC/Com/ComConfig/RLSideObsDistHSC2_e0a50b4e, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  { /*   128 */           278U,             277U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         34U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          39U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDircn_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  { /*   129 */           267U,             265U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,         40U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           5U,                     4U,          37U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistPC_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*   130 */           266U,             265U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         38U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          37U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTRC_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*   131 */           269U,             267U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         56U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2U,           7U,                     6U,          37U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistT_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*   132 */           266U,             265U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         34U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          37U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistV_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*   133 */           266U,             265U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         35U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          37U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlRstOcd_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*   134 */           266U,             265U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         36U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          37U },  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlSeqNum_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be] */
  { /*   135 */           109U,             108U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         40U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          15U },  /* [/ActiveEcuC/Com/ComConfig/RRDoorOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  { /*   136 */            43U,              42U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         24U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,           7U },  /* [/ActiveEcuC/Com/ComConfig/RRObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   137 */            49U,              47U,  COM_UINT16_APPLTYPEOFTXSIGINFO,        9U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,           8U },  /* [/ActiveEcuC/Com/ComConfig/RRSideObsDistHSC2_e0a50b4e, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be] */
  { /*   138 */            67U,              66U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        7U,         24U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          10U },  /* [/ActiveEcuC/Com/ComConfig/Route1SavePercentageHSC4_65a57977, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  { /*   139 */            66U,              65U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         18U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          10U },  /* [/ActiveEcuC/Com/ComConfig/Route1StateHSC4_65a57977, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  { /*   140 */            68U,              67U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        7U,         32U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          10U },  /* [/ActiveEcuC/Com/ComConfig/Route2SavePercentageHSC4_65a57977, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  { /*   141 */            66U,              65U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         16U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          10U },  /* [/ActiveEcuC/Com/ComConfig/Route2StateHSC4_65a57977, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  { /*   142 */            42U,              41U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         20U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,           7U },  /* [/ActiveEcuC/Com/ComConfig/RrMidLObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   143 */            41U,              40U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          8U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,           7U },  /* [/ActiveEcuC/Com/ComConfig/RrMidRObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   144 */            47U,              46U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         56U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           7U,                     7U,           7U },  /* [/ActiveEcuC/Com/ComConfig/RrObsDistHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   145 */            40U,              39U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          0U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,           7U },  /* [/ActiveEcuC/Com/ComConfig/RrPDCAudWrnngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be] */
  { /*   146 */           143U,             142U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         56U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,          21U },  /* [/ActiveEcuC/Com/ComConfig/RstrFctryDeftsReq_SecCAN2_9fc99604, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  { /*   147 */           279U,             278U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         46U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          39U },  /* [/ActiveEcuC/Com/ComConfig/SCSAPAAcclA_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  { /*   148 */           278U,             277U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         36U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          39U },  /* [/ActiveEcuC/Com/ComConfig/SCSAPAAlvRC_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  { /*   149 */           279U,             278U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         47U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          39U },  /* [/ActiveEcuC/Com/ComConfig/SCSAPAAvlbl_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
    /* Index    TxBufferEndIdx  TxBufferStartIdx  ApplType                         BitLength  BitPosition  BusAcc                              ByteLength  BytePosition  StartByteInPduPosition  TxPduInfoIdx        Referable Keys */
  { /*   150 */           279U,             278U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         45U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          39U },  /* [/ActiveEcuC/Com/ComConfig/SCSNRCDAvlbl_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  { /*   151 */           160U,             159U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          3U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          24U },  /* [/ActiveEcuC/Com/ComConfig/SCUAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  { /*   152 */           314U,             313U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          2U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          44U },  /* [/ActiveEcuC/Com/ComConfig/SCUDrvrIntrvnA_SecCAN2_c246c452, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  { /*   153 */           314U,             313U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          3U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          44U },  /* [/ActiveEcuC/Com/ComConfig/SCUNRCDAvlbl_SecCAN2_c246c452, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  { /*   154 */           160U,             159U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          5U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          24U },  /* [/ActiveEcuC/Com/ComConfig/SDMAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  { /*   155 */           243U,             242U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         40U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          34U },  /* [/ActiveEcuC/Com/ComConfig/SecsOfMinute_SecCAN2_ee8bd5bd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*   156 */            10U,               8U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,          0U,        COM_NBYTE_BUSACCOFTXSIGINFO,         2U,           0U,                     0U,           2U },  /* [/ActiveEcuC/Com/ComConfig/Sig_Init_SRU3_829252cc, /ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be] */
  { /*   157 */             8U,               7U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           0U,                     0U,           1U },  /* [/ActiveEcuC/Com/ComConfig/Sin_Init_LRU1_fdb965bc, /ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be] */
  { /*   158 */           246U,             245U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          7U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          35U },  /* [/ActiveEcuC/Com/ComConfig/StrgWhlAngV_SecCAN2_92023e75, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  { /*   159 */           248U,             246U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         16U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2U,           2U,                     1U,          35U },  /* [/ActiveEcuC/Com/ComConfig/StrgWhlAng_SecCAN2_92023e75, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  { /*   160 */           112U,             111U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          6U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          16U },  /* [/ActiveEcuC/Com/ComConfig/SysBPMEnbd_SecCAN2_d527401e, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be] */
  { /*   161 */           112U,             111U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,          4U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          16U },  /* [/ActiveEcuC/Com/ComConfig/SysBPM_SecCAN2_d527401e, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be] */
  { /*   162 */           166U,             165U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,          4U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          25U },  /* [/ActiveEcuC/Com/ComConfig/SysOpnlMd_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*   163 */           166U,             165U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,          0U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          25U },  /* [/ActiveEcuC/Com/ComConfig/SysPwrMd_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*   164 */           166U,             165U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          7U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          25U },  /* [/ActiveEcuC/Com/ComConfig/SysVolMdV_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*   165 */           173U,             172U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         57U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,          25U },  /* [/ActiveEcuC/Com/ComConfig/SysVolMd_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*   166 */           170U,             169U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         32U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          25U },  /* [/ActiveEcuC/Com/ComConfig/SysVolV_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*   167 */           171U,             170U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         40U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           5U,                     5U,          25U },  /* [/ActiveEcuC/Com/ComConfig/SysVol_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  { /*   168 */           161U,             160U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          8U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,          24U },  /* [/ActiveEcuC/Com/ComConfig/TCAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  { /*   169 */           285U,             284U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         28U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          40U },  /* [/ActiveEcuC/Com/ComConfig/TCSA_SecCAN2_72648180, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  { /*   170 */           332U,             331U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         23U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          46U },  /* [/ActiveEcuC/Com/ComConfig/TMSpdV_h1_SecCAN2_a8511b71, /ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  { /*   171 */           331U,             329U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,          8U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         2U,           1U,                     0U,          46U },  /* [/ActiveEcuC/Com/ComConfig/TMSpd_h1_SecCAN2_a8511b71, /ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  { /*   172 */           243U,             242U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         46U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,          34U },  /* [/ActiveEcuC/Com/ComConfig/TimeDspFmt_SecCAN2_ee8bd5bd, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  { /*   173 */           209U,             208U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         28U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          30U },  /* [/ActiveEcuC/Com/ComConfig/TrShftLvrPosV_h1_SecCAN2_f7a3932f, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  { /*   174 */           209U,             208U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         24U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          30U },  /* [/ActiveEcuC/Com/ComConfig/TrShftLvrPos_h1_SecCAN2_f7a3932f, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  { /*   175 */            97U,              96U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         15U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,          14U },  /* [/ActiveEcuC/Com/ComConfig/TrlrHitchSwA_SecCAN2_516d4ee4, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  { /*   176 */           236U,             235U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         53U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,          33U },  /* [/ActiveEcuC/Com/ComConfig/VCUAccReqSts_SecCAN2_e74ec2d1, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  { /*   177 */           237U,             236U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         56U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           7U,                     7U,          33U },  /* [/ActiveEcuC/Com/ComConfig/VCUAccReqVal_SecCAN2_e74ec2d1, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  { /*   178 */           236U,             235U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         52U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,          33U },  /* [/ActiveEcuC/Com/ComConfig/VCUNRCDAvlbl_SecCAN2_e74ec2d1, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  { /*   179 */           270U,             269U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          3U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          38U },  /* [/ActiveEcuC/Com/ComConfig/VSELatAccV_SecCAN2_78a18899, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  { /*   180 */           273U,             271U,  COM_SINT16_APPLTYPEOFTXSIGINFO,       12U,         24U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           3U,                     2U,          38U },  /* [/ActiveEcuC/Com/ComConfig/VSELatAcc_SecCAN2_78a18899, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  { /*   181 */           270U,             269U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          2U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          38U },  /* [/ActiveEcuC/Com/ComConfig/VSELongtAccV_SecCAN2_78a18899, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  { /*   182 */           271U,             269U,  COM_SINT16_APPLTYPEOFTXSIGINFO,       10U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,          38U },  /* [/ActiveEcuC/Com/ComConfig/VSELongtAcc_SecCAN2_78a18899, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be] */
  { /*   183 */           285U,             284U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         24U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          40U },  /* [/ActiveEcuC/Com/ComConfig/VSESysA_SecCAN2_72648180, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  { /*   184 */           286U,             285U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         36U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          40U },  /* [/ActiveEcuC/Com/ComConfig/VehDynYawRateV_SecCAN2_72648180, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  { /*   185 */           287U,             285U,  COM_SINT16_APPLTYPEOFTXSIGINFO,       12U,         40U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           5U,                     4U,          40U },  /* [/ActiveEcuC/Com/ComConfig/VehDynYawRate_SecCAN2_72648180, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  { /*   186 */           177U,             176U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         31U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,          26U },  /* [/ActiveEcuC/Com/ComConfig/VehOdoV_h2_SecCAN2_5b704f9c, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  { /*   187 */           176U,             173U,  COM_UINT32_APPLTYPEOFTXSIGINFO,       24U,         16U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         3U,           2U,                     0U,          26U },  /* [/ActiveEcuC/Com/ComConfig/VehOdo_h2_SecCAN2_5b704f9c, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  { /*   188 */           306U,             305U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          7U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          43U },  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnV_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*   189 */           307U,             305U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       15U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,          43U },  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgDrvn_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*   190 */           310U,             309U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         39U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,          43U },  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnV_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*   191 */           311U,             309U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       15U,         40U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           5U,                     4U,          43U },  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvn_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  { /*   192 */           290U,             289U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          6U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          41U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnV_SecCAN2_e1559b39, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  { /*   193 */           291U,             289U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       14U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,          41U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLDrvn_SecCAN2_e1559b39, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  { /*   194 */           298U,             297U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          6U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,          42U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnV_SecCAN2_6fda9cda, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  { /*   195 */           299U,             297U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       14U,          8U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,          42U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvn_SecCAN2_6fda9cda, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  { /*   196 */           292U,             291U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         22U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          41U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnV_SecCAN2_e1559b39, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  { /*   197 */           293U,             291U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       14U,         24U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           3U,                     2U,          41U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRDrvn_SecCAN2_e1559b39, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  { /*   198 */           300U,             299U,   COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         22U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,          42U },  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnV_SecCAN2_6fda9cda, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  { /*   199 */           301U,             299U,  COM_UINT16_APPLTYPEOFTXSIGINFO,       14U,         24U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           3U,                     2U,          42U }   /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvn_SecCAN2_6fda9cda, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayDescriptionProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_GatewayDescriptionProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayDescriptionProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_GatewayProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_GwEventCacheIndex
**********************************************************************************************************************/
/** 
  \var    Com_GwEventCacheIndex
  \brief  Index for deferred gw description event cache
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_GwEventCacheIndexType, COM_VAR_NOINIT) Com_GwEventCacheIndex;
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleTxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleTxPduDeferred
  \brief  Flag array used for deferred Tx confirmation handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_HandleTxPduDeferredType, COM_VAR_NOINIT) Com_HandleTxPduDeferred[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupState
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_IPduGroupStateType, COM_VAR_NOINIT) Com_IPduGroupState[8];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243, /ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_oLIN00_Rx_fcef2243, /ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243, /ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized = FALSE;
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests plus one initial transmit.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RepCntType, COM_VAR_NOINIT) Com_RepCnt[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    92 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    93 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    94 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    97 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be] */
  /*    98 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*    99 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /* Index        Referable Keys  */
  /*   100 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*   101 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*   102 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*   103 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*   104 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*   105 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be] */
  /*   106 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*   107 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*   108 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*   109 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*   110 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*   111 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*   112 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*   113 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be] */
  /*   114 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*   115 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*   116 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*   117 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*   118 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*   119 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*   120 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*   121 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be] */
  /*   122 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*   123 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*   124 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*   125 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*   126 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*   129 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be] */
  /*   130 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*   131 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*   132 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*   133 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*   134 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*   135 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*   136 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*   137 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be] */
  /*   138 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*   139 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*   140 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*   141 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*   142 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*   143 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*   144 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*   145 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be] */
  /*   146 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  /*   147 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be] */
  /*   148 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*   149 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /* Index        Referable Keys  */
  /*   150 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*   151 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*   152 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*   153 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*   154 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*   155 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be] */
  /*   156 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*   157 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*   158 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*   159 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*   160 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*   161 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*   162 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*   163 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be] */
  /*   164 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   165 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   166 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   167 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   168 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   169 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   170 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   171 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be] */
  /*   172 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   173 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   174 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   175 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   176 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   177 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   178 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   179 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be] */
  /*   180 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   181 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   182 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   183 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   184 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   185 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be] */
  /*   186 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   187 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   188 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   189 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   190 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   191 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   192 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   193 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be] */
  /*   194 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*   195 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*   196 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*   197 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*   198 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*   199 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /* Index        Referable Keys  */
  /*   200 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*   201 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be] */
  /*   202 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   203 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   204 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   205 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   206 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   207 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   208 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   209 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be] */
  /*   210 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   211 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   212 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   213 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   214 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   215 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   216 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   217 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be] */
  /*   218 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*   219 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*   220 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*   221 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*   222 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*   223 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*   224 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*   225 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be] */
  /*   226 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   227 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   228 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   229 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   230 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   231 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   232 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   233 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be] */
  /*   234 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*   235 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*   236 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*   237 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*   238 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*   239 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*   240 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*   241 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be] */
  /*   242 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   243 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   244 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   245 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   246 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   247 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   248 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /*   249 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be] */
  /* Index        Referable Keys  */
  /*   250 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   251 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   252 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   253 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   254 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   255 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   256 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   257 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be] */
  /*   258 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   259 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   260 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   261 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   262 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   263 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   264 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   265 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be] */
  /*   266 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   267 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   268 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   269 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   270 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   271 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   272 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   273 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be] */
  /*   274 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*   275 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*   276 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*   277 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*   278 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*   279 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*   280 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*   281 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be] */
  /*   282 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*   283 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*   284 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*   285 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*   286 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*   287 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*   288 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*   289 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be] */
  /*   290 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*   291 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*   292 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*   293 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*   294 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*   295 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*   296 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*   297 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be] */
  /*   298 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*   299 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /* Index        Referable Keys  */
  /*   300 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*   301 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*   302 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*   303 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*   304 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*   305 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be] */
  /*   306 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   307 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   308 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   309 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   310 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   311 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   312 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   313 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be] */
  /*   314 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*   315 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*   316 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*   317 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*   318 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*   319 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*   320 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*   321 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be] */
  /*   322 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*   323 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*   324 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*   325 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*   326 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*   327 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*   328 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*   329 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be] */
  /*   330 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   331 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   332 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   333 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   334 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   335 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   336 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   337 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be] */
  /*   338 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*   339 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*   340 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*   341 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*   342 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*   343 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*   344 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*   345 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be] */
  /*   346 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*   347 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*   348 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*   349 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /* Index        Referable Keys  */
  /*   350 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*   351 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*   352 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*   353 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be] */
  /*   354 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   355 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   356 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   357 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   358 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   359 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   360 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   361 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be] */
  /*   362 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   363 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   364 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   365 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   366 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   367 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   368 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   369 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be] */
  /*   370 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   371 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   372 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   373 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   374 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   375 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   376 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   377 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be] */
  /*   378 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   379 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   380 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   381 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   382 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   383 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   384 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   385 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be] */
  /*   386 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   387 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   388 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   389 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   390 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   391 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   392 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   393 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be] */
  /*   394 */  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  /*   395 */  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  /*   396 */  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be] */
  /*   397 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   398 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   399 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /* Index        Referable Keys  */
  /*   400 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   401 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   402 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   403 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   404 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   405 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   406 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   407 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   408 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   409 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   410 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   411 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   412 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be] */
  /*   413 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   414 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   415 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   416 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   417 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   418 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   419 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   420 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be] */
  /*   421 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*   422 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*   423 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*   424 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be] */
  /*   425 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   426 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   427 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   428 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   429 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   430 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   431 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   432 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be] */
  /*   433 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   434 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   435 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   436 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   437 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   438 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   439 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   440 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be] */
  /*   441 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   442 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   443 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   444 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   445 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   446 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   447 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   448 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be] */
  /*   449 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /* Index        Referable Keys  */
  /*   450 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   451 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   452 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   453 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   454 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   455 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   456 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be] */
  /*   457 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   458 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   459 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   460 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   461 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   462 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   463 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   464 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be] */
  /*   465 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   466 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   467 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   468 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   469 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   470 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   471 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   472 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be] */
  /*   473 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*   474 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*   475 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*   476 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*   477 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*   478 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*   479 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*   480 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be] */
  /*   481 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*   482 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*   483 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*   484 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*   485 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*   486 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*   487 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*   488 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be] */
  /*   489 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
  /*   490 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
  /*   491 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
  /*   492 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
  /*   493 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */
  /*   494 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupStopISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxIPduGroupStopISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupStopISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[66];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/APA_SecCH_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_APA_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_FuncReq_HSC2_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_PhysReq_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/EHBS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/EPB_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/EPS_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP08_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP13_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP18_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP32_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/FICM_HSC4_FrP33_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP06_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrP07_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_BCM_FrS16_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_ECM_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FICM_FrP08_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP08_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP10_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrP13_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_FrS00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_HCU_FrP13_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_IPK_FrP06_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SCU_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC2_SDM_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrP04_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS09_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BCM_FrS10_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_BMS_FrP07_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_PEPS_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrP05_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TBOX_FrS10_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/GW_HSC4_TC_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/IPK_HSC4_FrP06_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/PDC_SecCH_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Rx_fcef2243] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/RDA_HSC4_P02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/Read_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Rx_fcef2243] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/Read_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Rx_fcef2243] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/SAS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP05_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP11_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP12_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/SCS_HSC2_FrP15_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/TPMS_HSC3_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Rx_fcef2243] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_ECM_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/Tester_HSC2_GW_FrP14_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Rx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferArrayBased
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferArrayBased
  \brief  Rx Signal and Group Signal Buffer. (UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferArrayBasedType, COM_VAR_NOINIT) Com_RxSigBufferArrayBased[63];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5, /ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5, /ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5, /ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5, /ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5, /ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5, /ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5, /ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5, /ActiveEcuC/Com/ComConfig/BCMImmoData4HSC4_7f6505b5_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add_RxSignalBufferRouting] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add_RxSignalBufferRouting] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add, /ActiveEcuC/Com/ComConfig/BCMImmoData5HSC4_77510add_RxSignalBufferRouting] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49_RxSignalBufferRouting] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49_RxSignalBufferRouting] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49_RxSignalBufferRouting] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49_RxSignalBufferRouting] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49_RxSignalBufferRouting] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49_RxSignalBufferRouting] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49_RxSignalBufferRouting] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49, /ActiveEcuC/Com/ComConfig/BCMToIECURmtCtrlPotclHSC2_c8458f49_RxSignalBufferRouting] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85_RxSignalBufferRouting] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85_RxSignalBufferRouting] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85_RxSignalBufferRouting] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85_RxSignalBufferRouting] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85_RxSignalBufferRouting] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85_RxSignalBufferRouting] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85, /ActiveEcuC/Com/ComConfig/DTCInfomationAPA_SecCAN2_3e47bb85_RxSignalBufferRouting] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3_RxSignalBufferRouting] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3_RxSignalBufferRouting] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3_RxSignalBufferRouting] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3_RxSignalBufferRouting] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3_RxSignalBufferRouting] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3_RxSignalBufferRouting] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3_RxSignalBufferRouting] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3, /ActiveEcuC/Com/ComConfig/DiagnosticFuncAddrReq_h2_a8412cb3_RxSignalBufferRouting] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d_RxSignalBufferRouting] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d_RxSignalBufferRouting] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d_RxSignalBufferRouting] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d_RxSignalBufferRouting] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d_RxSignalBufferRouting] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d_RxSignalBufferRouting] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d_RxSignalBufferRouting] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d, /ActiveEcuC/Com/ComConfig/DiagnosticReqP2P_h2_2483449d_RxSignalBufferRouting] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd_RxSignalBufferRouting] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd_RxSignalBufferRouting] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd_RxSignalBufferRouting] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd_RxSignalBufferRouting] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd_RxSignalBufferRouting] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd_RxSignalBufferRouting] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd_RxSignalBufferRouting] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2HSC2_407c19cd_RxSignalBufferRouting] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014_RxSignalBufferRouting] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014_RxSignalBufferRouting] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014_RxSignalBufferRouting] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014_RxSignalBufferRouting] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014_RxSignalBufferRouting] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014_RxSignalBufferRouting] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014_RxSignalBufferRouting] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014, /ActiveEcuC/Com/ComConfig/TBOXToIECUCtrlPotclHSC4_bd586014_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferSInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferSInt16
  \brief  Rx Signal and Group Signal Buffer. (SINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferSInt16Type, COM_VAR_NOINIT) Com_RxSigBufferSInt16[4];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/TBOXAccelZHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/TBOXAccelZHSC4_09f4c130_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/VSELatAccHSC2_542766fd, /ActiveEcuC/Com/ComConfig/VSELatAccHSC2_542766fd_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/VSELongtAccHSC2_542766fd, /ActiveEcuC/Com/ComConfig/VSELongtAccHSC2_542766fd_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/VehDynYawRateHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/VehDynYawRateHSC2_5ee26fe4_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[42];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqValPV_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APASCSAcclReqValPV_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/APASlotLngth_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APASlotLngth_sech2_SecCAN2_48fe6e71_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/APAToqReqVal_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APAToqReqVal_sech2_SecCAN2_0adb690c_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/APATrgtEPSStrgWhlAng_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APATrgtEPSStrgWhlAng_sech2_SecCAN2_0adb690c_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/APAVehCrdnatAzmth_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APAVehCrdnatAzmth_sech2_SecCAN2_48fe6e71_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/APAVehCrdnatPosX_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosX_sech2_SecCAN2_48fe6e71_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/APAVehCrdnatPosY_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosY_sech2_SecCAN2_48fe6e71_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnHSC2_49997ba7_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/FLObsDist_sech2_SecCAN2_84546eef, /ActiveEcuC/Com/ComConfig/FLObsDist_sech2_SecCAN2_84546eef_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/FLSideObsDist_sech2_SecCAN2_eb7d27c8, /ActiveEcuC/Com/ComConfig/FLSideObsDist_sech2_SecCAN2_eb7d27c8_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/FRObsDist_sech2_SecCAN2_84546eef, /ActiveEcuC/Com/ComConfig/FRObsDist_sech2_SecCAN2_84546eef_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/FRSideObsDist_sech2_SecCAN2_eb7d27c8, /ActiveEcuC/Com/ComConfig/FRSideObsDist_sech2_SecCAN2_eb7d27c8_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/FrtMidLObsDist_sech2_SecCAN2_8e9167f6, /ActiveEcuC/Com/ComConfig/FrtMidLObsDist_sech2_SecCAN2_8e9167f6_RxSignalBufferRouting] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/FrtMidRObsDist_sech2_SecCAN2_8e9167f6, /ActiveEcuC/Com/ComConfig/FrtMidRObsDist_sech2_SecCAN2_8e9167f6_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistPlsCtrHSC2_16026180, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistPlsCtrHSC2_16026180_RxSignalBufferRouting] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTmspHSC2_16026180, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTmspHSC2_16026180_RxSignalBufferRouting] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistPCHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistPCHSC2_daa8611e_RxSignalBufferRouting] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTHSC2_daa8611e_RxSignalBufferRouting] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistPlsCtrHSC2_16026180, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistPlsCtrHSC2_16026180_RxSignalBufferRouting] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTmspHSC2_16026180, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTmspHSC2_16026180_RxSignalBufferRouting] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/RLObsDist_sech2_SecCAN2_84546eef, /ActiveEcuC/Com/ComConfig/RLObsDist_sech2_SecCAN2_84546eef_RxSignalBufferRouting] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/RLSideObsDist_sech2_SecCAN2_eb7d27c8, /ActiveEcuC/Com/ComConfig/RLSideObsDist_sech2_SecCAN2_eb7d27c8_RxSignalBufferRouting] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistPCHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistPCHSC2_daa8611e_RxSignalBufferRouting] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTHSC2_daa8611e_RxSignalBufferRouting] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/RRObsDist_sech2_SecCAN2_84546eef, /ActiveEcuC/Com/ComConfig/RRObsDist_sech2_SecCAN2_84546eef_RxSignalBufferRouting] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/RRSideObsDist_sech2_SecCAN2_eb7d27c8, /ActiveEcuC/Com/ComConfig/RRSideObsDist_sech2_SecCAN2_eb7d27c8_RxSignalBufferRouting] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/RrMidLObsDist_sech2_SecCAN2_8e9167f6, /ActiveEcuC/Com/ComConfig/RrMidLObsDist_sech2_SecCAN2_8e9167f6_RxSignalBufferRouting] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/RrMidRObsDist_sech2_SecCAN2_8e9167f6, /ActiveEcuC/Com/ComConfig/RrMidRObsDist_sech2_SecCAN2_8e9167f6_RxSignalBufferRouting] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/SCREEN_COORD_AXHSC4_c0316154, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_AXHSC4_c0316154_RxSignalBufferRouting] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/SCREEN_COORD_AYHSC4_c0316154, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_AYHSC4_c0316154_RxSignalBufferRouting] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/SCREEN_COORD_BXHSC4_c0316154, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_BXHSC4_c0316154_RxSignalBufferRouting] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/SCREEN_COORD_BYHSC4_c0316154, /ActiveEcuC/Com/ComConfig/SCREEN_COORD_BYHSC4_c0316154_RxSignalBufferRouting] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/StrgWhlAngHSC2_dccc170c, /ActiveEcuC/Com/ComConfig/StrgWhlAngHSC2_dccc170c_RxSignalBufferRouting] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/TMSpd_h1HSC4_d68cf0b9, /ActiveEcuC/Com/ComConfig/TMSpd_h1HSC4_d68cf0b9_RxSignalBufferRouting] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/TOF_LRU1_18ef6e8d, /ActiveEcuC/Com/ComConfig/TOF_LRU1_18ef6e8d_RxSignalBufferRouting] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/TOF_SRU3_67c459fd, /ActiveEcuC/Com/ComConfig/TOF_SRU3_67c459fd_RxSignalBufferRouting] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnHSC2_49997ba7_RxSignalBufferRouting] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnHSC2_49997ba7_RxSignalBufferRouting] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnHSC2_cdd3755d, /ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnHSC2_cdd3755d_RxSignalBufferRouting] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnHSC2_435c72be, /ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnHSC2_435c72be_RxSignalBufferRouting] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnHSC2_cdd3755d, /ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnHSC2_cdd3755d_RxSignalBufferRouting] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnHSC2_435c72be, /ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnHSC2_435c72be_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt32
  \brief  Rx Signal and Group Signal Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt32Type, COM_VAR_NOINIT) Com_RxSigBufferUInt32[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/VehOdo_h2HSC2_78aeb97b, /ActiveEcuC/Com/ComConfig/VehOdo_h2HSC2_78aeb97b_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[228];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ABSAHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/ABSAHSC2_5ee26fe4_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/APAAlvRC_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APAAlvRC_sech2_SecCAN2_0adb690c_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/APAChksm_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APAChksm_sech2_SecCAN2_0adb690c_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/APACmdEPSSts_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APACmdEPSSts_sech2_SecCAN2_0adb690c_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/APACrpSpdReqSts_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APACrpSpdReqSts_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/APACrpSpdReqVal_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APACrpSpdReqVal_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/APACtrlAbotdRsnHSC2_32bfb16e, /ActiveEcuC/Com/ComConfig/APACtrlAbotdRsnHSC2_32bfb16e_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/APAEPBOPReq_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APAEPBOPReq_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/APAEPBOpReqValPV_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APAEPBOpReqValPV_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/APAEPBReqAlvRC_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APAEPBReqAlvRC_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/APAF_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APAF_sech2_SecCAN2_0adb690c_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/APAInfoDispReq_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APAInfoDispReq_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/APAMd_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APAMd_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/APANRCDAvlbl_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APANRCDAvlbl_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/APAParkngSchedV_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APAParkngSchedV_sech2_SecCAN2_48fe6e71_RxSignalBufferRouting] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/APAParkngSched_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APAParkngSched_sech2_SecCAN2_48fe6e71_RxSignalBufferRouting] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/APAReq_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APAReq_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqSts_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APASCSAcclReqSts_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/APASCSAcclReqVal_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APASCSAcclReqVal_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/APASCSAlvRC_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APASCSAlvRC_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/APAShifterPosReqd_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APAShifterPosReqd_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/APASlotBearng_sech2_SecCAN2_48fe6e71, /ActiveEcuC/Com/ComConfig/APASlotBearng_sech2_SecCAN2_48fe6e71_RxSignalBufferRouting] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/APASts_sech2_SecCAN2_c6716992, /ActiveEcuC/Com/ComConfig/APASts_sech2_SecCAN2_c6716992_RxSignalBufferRouting] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/APASwReqHSC2_46783686, /ActiveEcuC/Com/ComConfig/APASwReqHSC2_46783686_RxSignalBufferRouting] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/APASwReqHSC4_687c4159, /ActiveEcuC/Com/ComConfig/APASwReqHSC4_687c4159_RxSignalBufferRouting] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/APAToqReqSts_sech2_SecCAN2_0adb690c, /ActiveEcuC/Com/ComConfig/APAToqReqSts_sech2_SecCAN2_0adb690c_RxSignalBufferRouting] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/AVMAutoViewChgHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/AVMAutoViewChgHSC4_0c9b61ca_RxSignalBufferRouting] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/AirbagDplHSC2_2128899b, /ActiveEcuC/Com/ComConfig/AirbagDplHSC2_2128899b_RxSignalBufferRouting] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/AirbagDplInvsnHSC2_2128899b, /ActiveEcuC/Com/ComConfig/AirbagDplInvsnHSC2_2128899b_RxSignalBufferRouting] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/AlisysrdyHSC4_226d494c, /ActiveEcuC/Com/ComConfig/AlisysrdyHSC4_226d494c_RxSignalBufferRouting] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/BCMAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/BCMAvlbly_h2HSC2_ab4ba2ce_RxSignalBufferRouting] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/BCMSSBAHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/BCMSSBAHSC2_f8a32097_RxSignalBufferRouting] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/BCMSSBAVHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/BCMSSBAVHSC2_f8a32097_RxSignalBufferRouting] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/BCMSSBFltStsHSC2_34092009, /ActiveEcuC/Com/ComConfig/BCMSSBFltStsHSC2_34092009_RxSignalBufferRouting] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/BMSBscSta_h1HSC4_c182dd1d, /ActiveEcuC/Com/ComConfig/BMSBscSta_h1HSC4_c182dd1d_RxSignalBufferRouting] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/BPMMstrAvlbly_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/BPMMstrAvlbly_h2HSC2_67e1a250_RxSignalBufferRouting] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/BntOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/BntOpenStsHSC2_762c2774_RxSignalBufferRouting] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/BrkPdlAppdHSC2_70a619c8, /ActiveEcuC/Com/ComConfig/BrkPdlAppdHSC2_70a619c8_RxSignalBufferRouting] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/CalendarDayHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/CalendarDayHSC2_c30fb534_RxSignalBufferRouting] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/CalendarDayHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/CalendarDayHSC4_80f6c9a0_RxSignalBufferRouting] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/CalendarMonthHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/CalendarMonthHSC2_c30fb534_RxSignalBufferRouting] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/CalendarMonthHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/CalendarMonthHSC4_80f6c9a0_RxSignalBufferRouting] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/CalendarYearHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/CalendarYearHSC2_c30fb534_RxSignalBufferRouting] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/CalendarYearHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/CalendarYearHSC4_80f6c9a0_RxSignalBufferRouting] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/DayTimeRunningLampOnHSC2_34092009, /ActiveEcuC/Com/ComConfig/DayTimeRunningLampOnHSC2_34092009_RxSignalBufferRouting] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/DipdBeamLghtOnHSC2_762c2774, /ActiveEcuC/Com/ComConfig/DipdBeamLghtOnHSC2_762c2774_RxSignalBufferRouting] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/DircnIndLampSwStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/DircnIndLampSwStsHSC2_762c2774_RxSignalBufferRouting] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnRstOcdHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnRstOcdHSC2_49997ba7_RxSignalBufferRouting] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnSrcHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnSrcHSC2_49997ba7_RxSignalBufferRouting] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/DistRCAvgDrvnVHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnVHSC2_49997ba7_RxSignalBufferRouting] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/DrvrDoorOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/DrvrDoorOpenStsHSC2_762c2774_RxSignalBufferRouting] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/DrvrSbltAtcHSC2_2128899b, /ActiveEcuC/Com/ComConfig/DrvrSbltAtcHSC2_2128899b_RxSignalBufferRouting] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/DrvrSbltAtcVHSC2_2128899b, /ActiveEcuC/Com/ComConfig/DrvrSbltAtcVHSC2_2128899b_RxSignalBufferRouting] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC2_d7b82a4e, /ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC2_d7b82a4e_RxSignalBufferRouting] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC4_7f07551a, /ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMdHSC4_7f07551a_RxSignalBufferRouting] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC2_d7b82a4e, /ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC2_d7b82a4e_RxSignalBufferRouting] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC4_7f07551a, /ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearngHSC4_7f07551a_RxSignalBufferRouting] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/ECMAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/ECMAvlbly_h2HSC2_ab4ba2ce_RxSignalBufferRouting] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/EPBAppcnStsHSC2_ecbe2b89, /ActiveEcuC/Com/ComConfig/EPBAppcnStsHSC2_ecbe2b89_RxSignalBufferRouting] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/EPBAppcnStsPVHSC2_ecbe2b89, /ActiveEcuC/Com/ComConfig/EPBAppcnStsPVHSC2_ecbe2b89_RxSignalBufferRouting] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/EPBAvlblyStsHSC2_ecbe2b89, /ActiveEcuC/Com/ComConfig/EPBAvlblyStsHSC2_ecbe2b89_RxSignalBufferRouting] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/EPBAvlblyStsPVHSC2_ecbe2b89, /ActiveEcuC/Com/ComConfig/EPBAvlblyStsPVHSC2_ecbe2b89_RxSignalBufferRouting] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/EPBSwStsHSC2_20142b17, /ActiveEcuC/Com/ComConfig/EPBSwStsHSC2_20142b17_RxSignalBufferRouting] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/EPBSwStsVHSC2_20142b17, /ActiveEcuC/Com/ComConfig/EPBSwStsVHSC2_20142b17_RxSignalBufferRouting] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/EPSAPAAlvRCHSC2_a6919738, /ActiveEcuC/Com/ComConfig/EPSAPAAlvRCHSC2_a6919738_RxSignalBufferRouting] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/EPSAPAChksmHSC2_a6919738, /ActiveEcuC/Com/ComConfig/EPSAPAChksmHSC2_a6919738_RxSignalBufferRouting] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/EPSAPAInhHSC2_a6919738, /ActiveEcuC/Com/ComConfig/EPSAPAInhHSC2_a6919738_RxSignalBufferRouting] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/EPSAPAStsHSC2_a6919738, /ActiveEcuC/Com/ComConfig/EPSAPAStsHSC2_a6919738_RxSignalBufferRouting] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/EPTAccelActuPosHSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/EPTAccelActuPosHSC2_533eb1f8_RxSignalBufferRouting] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/EPTAccelActuPosVHSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/EPTAccelActuPosVHSC2_533eb1f8_RxSignalBufferRouting] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsHSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsHSC2_533eb1f8_RxSignalBufferRouting] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsVHSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsVHSC2_533eb1f8_RxSignalBufferRouting] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/EPTRdy_h1HSC2_9f94b166, /ActiveEcuC/Com/ComConfig/EPTRdy_h1HSC2_9f94b166_RxSignalBufferRouting] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/EPTStCmdOn_h1HSC2_533eb1f8, /ActiveEcuC/Com/ComConfig/EPTStCmdOn_h1HSC2_533eb1f8_RxSignalBufferRouting] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/EnRunAHSC2_235f8f9b, /ActiveEcuC/Com/ComConfig/EnRunAHSC2_235f8f9b_RxSignalBufferRouting] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/FICMAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/FICMAvlbly_h2HSC2_ab4ba2ce_RxSignalBufferRouting] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/FICMP2PQuitReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICMP2PQuitReqHSC4_0c9b61ca_RxSignalBufferRouting] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/FICMPLCRtCoverSwReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICMPLCRtCoverSwReqHSC4_0c9b61ca_RxSignalBufferRouting] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/FICMPLCRtEndSwReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICMPLCRtEndSwReqHSC4_0c9b61ca_RxSignalBufferRouting] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/FICMPLCSwReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICMPLCSwReqHSC4_0c9b61ca_RxSignalBufferRouting] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/FICMRouteChangeCheckHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICMRouteChangeCheckHSC4_0c9b61ca_RxSignalBufferRouting] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/FICMRouteReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICMRouteReqHSC4_0c9b61ca_RxSignalBufferRouting] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/FICMSilentSearchCheckHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICMSilentSearchCheckHSC4_0c9b61ca_RxSignalBufferRouting] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/FICMSilentSearchReqHSC4_0c9b61ca, /ActiveEcuC/Com/ComConfig/FICMSilentSearchReqHSC4_0c9b61ca_RxSignalBufferRouting] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/FLDoorHadlSwAHSC4_5c9d774f, /ActiveEcuC/Com/ComConfig/FLDoorHadlSwAHSC4_5c9d774f_RxSignalBufferRouting] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/FLObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/FLObsRng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/FLTirePrsHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/FLTirePrsHSC4_fa528d8c_RxSignalBufferRouting] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/FLTirePrsVHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/FLTirePrsVHSC4_fa528d8c_RxSignalBufferRouting] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/FRDoorHadlSwAHSC4_5c9d774f, /ActiveEcuC/Com/ComConfig/FRDoorHadlSwAHSC4_5c9d774f_RxSignalBufferRouting] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/FRObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/FRObsRng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/FRTirePrsHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/FRTirePrsHSC4_fa528d8c_RxSignalBufferRouting] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/FRTirePrsVHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/FRTirePrsVHSC4_fa528d8c_RxSignalBufferRouting] */
  /*    92 */  /* [/ActiveEcuC/Com/ComConfig/FrtFogLghtOnHSC2_762c2774, /ActiveEcuC/Com/ComConfig/FrtFogLghtOnHSC2_762c2774_RxSignalBufferRouting] */
  /*    93 */  /* [/ActiveEcuC/Com/ComConfig/FrtMidLObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/FrtMidLObsRng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*    94 */  /* [/ActiveEcuC/Com/ComConfig/FrtMidRObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/FrtMidRObsRng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/FrtObsDist_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/FrtObsDist_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/FrtPDCAudWrnng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/FrtPDCAudWrnng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*    97 */  /* [/ActiveEcuC/Com/ComConfig/FrtPsngDoorOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/FrtPsngDoorOpenStsHSC2_762c2774_RxSignalBufferRouting] */
  /*    98 */  /* [/ActiveEcuC/Com/ComConfig/HCUAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/HCUAvlbly_h2HSC2_ab4ba2ce_RxSignalBufferRouting] */
  /*    99 */  /* [/ActiveEcuC/Com/ComConfig/HourOfDayHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/HourOfDayHSC2_c30fb534_RxSignalBufferRouting] */
  /* Index        Referable Keys  */
  /*   100 */  /* [/ActiveEcuC/Com/ComConfig/HourOfDayHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/HourOfDayHSC4_80f6c9a0_RxSignalBufferRouting] */
  /*   101 */  /* [/ActiveEcuC/Com/ComConfig/HydBstrCmpstnReqHSC2_70a619c8, /ActiveEcuC/Com/ComConfig/HydBstrCmpstnReqHSC2_70a619c8_RxSignalBufferRouting] */
  /*   102 */  /* [/ActiveEcuC/Com/ComConfig/IPCAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/IPCAvlbly_h2HSC2_ab4ba2ce_RxSignalBufferRouting] */
  /*   103 */  /* [/ActiveEcuC/Com/ComConfig/LDircnIOHSC2_762c2774, /ActiveEcuC/Com/ComConfig/LDircnIOHSC2_762c2774_RxSignalBufferRouting] */
  /*   104 */  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTRCHSC2_16026180, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTRCHSC2_16026180_RxSignalBufferRouting] */
  /*   105 */  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistVHSC2_16026180, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistVHSC2_16026180_RxSignalBufferRouting] */
  /*   106 */  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlRstOcdHSC2_16026180, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlRstOcdHSC2_16026180_RxSignalBufferRouting] */
  /*   107 */  /* [/ActiveEcuC/Com/ComConfig/LDrvnWhlRotlSeqNumHSC2_16026180, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlSeqNumHSC2_16026180_RxSignalBufferRouting] */
  /*   108 */  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDircnHSC2_988d6663, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDircnHSC2_988d6663_RxSignalBufferRouting] */
  /*   109 */  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTRCHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTRCHSC2_daa8611e_RxSignalBufferRouting] */
  /*   110 */  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistVHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistVHSC2_daa8611e_RxSignalBufferRouting] */
  /*   111 */  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlRstOcdHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlRstOcdHSC2_daa8611e_RxSignalBufferRouting] */
  /*   112 */  /* [/ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlSeqNumHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlSeqNumHSC2_daa8611e_RxSignalBufferRouting] */
  /*   113 */  /* [/ActiveEcuC/Com/ComConfig/LRCTAWrnngHSC4_693ba2af, /ActiveEcuC/Com/ComConfig/LRCTAWrnngHSC4_693ba2af_RxSignalBufferRouting] */
  /*   114 */  /* [/ActiveEcuC/Com/ComConfig/LdspcOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/LdspcOpenStsHSC2_762c2774_RxSignalBufferRouting] */
  /*   115 */  /* [/ActiveEcuC/Com/ComConfig/MainBeamLghtOnHSC2_762c2774, /ActiveEcuC/Com/ComConfig/MainBeamLghtOnHSC2_762c2774_RxSignalBufferRouting] */
  /*   116 */  /* [/ActiveEcuC/Com/ComConfig/MinuteOfHourHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/MinuteOfHourHSC2_c30fb534_RxSignalBufferRouting] */
  /*   117 */  /* [/ActiveEcuC/Com/ComConfig/MinuteOfHourHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/MinuteOfHourHSC4_80f6c9a0_RxSignalBufferRouting] */
  /*   118 */  /* [/ActiveEcuC/Com/ComConfig/NRCDAlvRCHSC2_6ae5c0ff, /ActiveEcuC/Com/ComConfig/NRCDAlvRCHSC2_6ae5c0ff_RxSignalBufferRouting] */
  /*   119 */  /* [/ActiveEcuC/Com/ComConfig/NRCDFHSC2_6ae5c0ff, /ActiveEcuC/Com/ComConfig/NRCDFHSC2_6ae5c0ff_RxSignalBufferRouting] */
  /*   120 */  /* [/ActiveEcuC/Com/ComConfig/NRCDSts_h2HSC2_32bfb16e, /ActiveEcuC/Com/ComConfig/NRCDSts_h2HSC2_32bfb16e_RxSignalBufferRouting] */
  /*   121 */  /* [/ActiveEcuC/Com/ComConfig/OtsdAirTemCrValMsk_h2HSC2_bc30b68d, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrValMsk_h2HSC2_bc30b68d_RxSignalBufferRouting] */
  /*   122 */  /* [/ActiveEcuC/Com/ComConfig/OtsdAirTemCrValV_h2HSC2_bc30b68d, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrValV_h2HSC2_bc30b68d_RxSignalBufferRouting] */
  /*   123 */  /* [/ActiveEcuC/Com/ComConfig/OtsdAirTemCrVal_h2HSC2_bc30b68d, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrVal_h2HSC2_bc30b68d_RxSignalBufferRouting] */
  /*   124 */  /* [/ActiveEcuC/Com/ComConfig/P2PExeAvlblHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/P2PExeAvlblHSC4_09f4c130_RxSignalBufferRouting] */
  /*   125 */  /* [/ActiveEcuC/Com/ComConfig/P2PExeAvlblVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/P2PExeAvlblVHSC4_09f4c130_RxSignalBufferRouting] */
  /*   126 */  /* [/ActiveEcuC/Com/ComConfig/P2PSwReqHSC4_8dbecfca, /ActiveEcuC/Com/ComConfig/P2PSwReqHSC4_8dbecfca_RxSignalBufferRouting] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/PDCCofignSts_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDCCofignSts_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/PDCSwReqHSC2_46783686, /ActiveEcuC/Com/ComConfig/PDCSwReqHSC2_46783686_RxSignalBufferRouting] */
  /*   129 */  /* [/ActiveEcuC/Com/ComConfig/PDCSwReqHSC4_687c4159, /ActiveEcuC/Com/ComConfig/PDCSwReqHSC4_687c4159_RxSignalBufferRouting] */
  /*   130 */  /* [/ActiveEcuC/Com/ComConfig/PDCSysSts_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/PDCSysSts_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*   131 */  /* [/ActiveEcuC/Com/ComConfig/PEPSSSBAHSC4_5c9d774f, /ActiveEcuC/Com/ComConfig/PEPSSSBAHSC4_5c9d774f_RxSignalBufferRouting] */
  /*   132 */  /* [/ActiveEcuC/Com/ComConfig/PEPSSSBAVHSC4_5c9d774f, /ActiveEcuC/Com/ComConfig/PEPSSSBAVHSC4_5c9d774f_RxSignalBufferRouting] */
  /*   133 */  /* [/ActiveEcuC/Com/ComConfig/PEPSSSBFltStsHSC4_d21270ac, /ActiveEcuC/Com/ComConfig/PEPSSSBFltStsHSC4_d21270ac_RxSignalBufferRouting] */
  /*   134 */  /* [/ActiveEcuC/Com/ComConfig/Peak_LRU1_18ef6e8d, /ActiveEcuC/Com/ComConfig/Peak_LRU1_18ef6e8d_RxSignalBufferRouting] */
  /*   135 */  /* [/ActiveEcuC/Com/ComConfig/PwrMdAutoCtrlAvlblHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/PwrMdAutoCtrlAvlblHSC2_f8a32097_RxSignalBufferRouting] */
  /*   136 */  /* [/ActiveEcuC/Com/ComConfig/PwrMdMstrAccryA_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/PwrMdMstrAccryA_h2HSC2_67e1a250_RxSignalBufferRouting] */
  /*   137 */  /* [/ActiveEcuC/Com/ComConfig/PwrMdMstrRunCrkA_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/PwrMdMstrRunCrkA_h2HSC2_67e1a250_RxSignalBufferRouting] */
  /*   138 */  /* [/ActiveEcuC/Com/ComConfig/RDircnIOHSC2_762c2774, /ActiveEcuC/Com/ComConfig/RDircnIOHSC2_762c2774_RxSignalBufferRouting] */
  /*   139 */  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTRCHSC2_16026180, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTRCHSC2_16026180_RxSignalBufferRouting] */
  /*   140 */  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistVHSC2_16026180, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistVHSC2_16026180_RxSignalBufferRouting] */
  /*   141 */  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlRstOcdHSC2_16026180, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlRstOcdHSC2_16026180_RxSignalBufferRouting] */
  /*   142 */  /* [/ActiveEcuC/Com/ComConfig/RDrvnWhlRotlSeqNumHSC2_16026180, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlSeqNumHSC2_16026180_RxSignalBufferRouting] */
  /*   143 */  /* [/ActiveEcuC/Com/ComConfig/RLDoorOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/RLDoorOpenStsHSC2_762c2774_RxSignalBufferRouting] */
  /*   144 */  /* [/ActiveEcuC/Com/ComConfig/RLObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/RLObsRng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*   145 */  /* [/ActiveEcuC/Com/ComConfig/RLTirePrsHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/RLTirePrsHSC4_fa528d8c_RxSignalBufferRouting] */
  /*   146 */  /* [/ActiveEcuC/Com/ComConfig/RLTirePrsVHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/RLTirePrsVHSC4_fa528d8c_RxSignalBufferRouting] */
  /*   147 */  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDircnHSC2_988d6663, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDircnHSC2_988d6663_RxSignalBufferRouting] */
  /*   148 */  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTRCHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTRCHSC2_daa8611e_RxSignalBufferRouting] */
  /*   149 */  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistVHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistVHSC2_daa8611e_RxSignalBufferRouting] */
  /* Index        Referable Keys  */
  /*   150 */  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlRstOcdHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlRstOcdHSC2_daa8611e_RxSignalBufferRouting] */
  /*   151 */  /* [/ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlSeqNumHSC2_daa8611e, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlSeqNumHSC2_daa8611e_RxSignalBufferRouting] */
  /*   152 */  /* [/ActiveEcuC/Com/ComConfig/RRCTAWrnngHSC4_693ba2af, /ActiveEcuC/Com/ComConfig/RRCTAWrnngHSC4_693ba2af_RxSignalBufferRouting] */
  /*   153 */  /* [/ActiveEcuC/Com/ComConfig/RRDoorOpenStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/RRDoorOpenStsHSC2_762c2774_RxSignalBufferRouting] */
  /*   154 */  /* [/ActiveEcuC/Com/ComConfig/RRObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/RRObsRng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*   155 */  /* [/ActiveEcuC/Com/ComConfig/RRTirePrsHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/RRTirePrsHSC4_fa528d8c_RxSignalBufferRouting] */
  /*   156 */  /* [/ActiveEcuC/Com/ComConfig/RRTirePrsVHSC4_fa528d8c, /ActiveEcuC/Com/ComConfig/RRTirePrsVHSC4_fa528d8c_RxSignalBufferRouting] */
  /*   157 */  /* [/ActiveEcuC/Com/ComConfig/RrFogLghtOnHSC2_762c2774, /ActiveEcuC/Com/ComConfig/RrFogLghtOnHSC2_762c2774_RxSignalBufferRouting] */
  /*   158 */  /* [/ActiveEcuC/Com/ComConfig/RrMidLObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/RrMidLObsRng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*   159 */  /* [/ActiveEcuC/Com/ComConfig/RrMidRObsRng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/RrMidRObsRng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*   160 */  /* [/ActiveEcuC/Com/ComConfig/RrObsDist_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/RrObsDist_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*   161 */  /* [/ActiveEcuC/Com/ComConfig/RrPDCAudWrnng_sech2_SecCAN2_27d72756, /ActiveEcuC/Com/ComConfig/RrPDCAudWrnng_sech2_SecCAN2_27d72756_RxSignalBufferRouting] */
  /*   162 */  /* [/ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC2_d7b82a4e, /ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC2_d7b82a4e_RxSignalBufferRouting] */
  /*   163 */  /* [/ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC4_f9bc5d91, /ActiveEcuC/Com/ComConfig/RstrFctryDeftsReqHSC4_f9bc5d91_RxSignalBufferRouting] */
  /*   164 */  /* [/ActiveEcuC/Com/ComConfig/SCSAPAAcclAHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCSAPAAcclAHSC2_988d6663_RxSignalBufferRouting] */
  /*   165 */  /* [/ActiveEcuC/Com/ComConfig/SCSAPAAlvRCHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCSAPAAlvRCHSC2_988d6663_RxSignalBufferRouting] */
  /*   166 */  /* [/ActiveEcuC/Com/ComConfig/SCSAPAAvlblHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCSAPAAvlblHSC2_988d6663_RxSignalBufferRouting] */
  /*   167 */  /* [/ActiveEcuC/Com/ComConfig/SCSNRCDAvlblHSC2_988d6663, /ActiveEcuC/Com/ComConfig/SCSNRCDAvlblHSC2_988d6663_RxSignalBufferRouting] */
  /*   168 */  /* [/ActiveEcuC/Com/ComConfig/SCUAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/SCUAvlbly_h2HSC2_ab4ba2ce_RxSignalBufferRouting] */
  /*   169 */  /* [/ActiveEcuC/Com/ComConfig/SCUDrvrIntrvnAHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/SCUDrvrIntrvnAHSC2_efc2a4db_RxSignalBufferRouting] */
  /*   170 */  /* [/ActiveEcuC/Com/ComConfig/SCUNRCDAvlblHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/SCUNRCDAvlblHSC2_efc2a4db_RxSignalBufferRouting] */
  /*   171 */  /* [/ActiveEcuC/Com/ComConfig/SCUShifterLvrPosHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/SCUShifterLvrPosHSC2_efc2a4db_RxSignalBufferRouting] */
  /*   172 */  /* [/ActiveEcuC/Com/ComConfig/SCUShifterPosInvsnHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/SCUShifterPosInvsnHSC2_efc2a4db_RxSignalBufferRouting] */
  /*   173 */  /* [/ActiveEcuC/Com/ComConfig/SCUShifterPosRCHSC2_efc2a4db, /ActiveEcuC/Com/ComConfig/SCUShifterPosRCHSC2_efc2a4db_RxSignalBufferRouting] */
  /*   174 */  /* [/ActiveEcuC/Com/ComConfig/SDMAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/SDMAvlbly_h2HSC2_ab4ba2ce_RxSignalBufferRouting] */
  /*   175 */  /* [/ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC2_c30fb534_RxSignalBufferRouting] */
  /*   176 */  /* [/ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/SecsOfMinuteHSC4_80f6c9a0_RxSignalBufferRouting] */
  /*   177 */  /* [/ActiveEcuC/Com/ComConfig/Status_LRU1_18ef6e8d, /ActiveEcuC/Com/ComConfig/Status_LRU1_18ef6e8d_RxSignalBufferRouting] */
  /*   178 */  /* [/ActiveEcuC/Com/ComConfig/Status_SRU3_67c459fd, /ActiveEcuC/Com/ComConfig/Status_SRU3_67c459fd_RxSignalBufferRouting] */
  /*   179 */  /* [/ActiveEcuC/Com/ComConfig/StrgWhlAngVHSC2_dccc170c, /ActiveEcuC/Com/ComConfig/StrgWhlAngVHSC2_dccc170c_RxSignalBufferRouting] */
  /*   180 */  /* [/ActiveEcuC/Com/ComConfig/SurndViewSelnHSC4_c0316154, /ActiveEcuC/Com/ComConfig/SurndViewSelnHSC4_c0316154_RxSignalBufferRouting] */
  /*   181 */  /* [/ActiveEcuC/Com/ComConfig/SysBPMEnbdHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/SysBPMEnbdHSC2_f8a32097_RxSignalBufferRouting] */
  /*   182 */  /* [/ActiveEcuC/Com/ComConfig/SysBPMHSC2_f8a32097, /ActiveEcuC/Com/ComConfig/SysBPMHSC2_f8a32097_RxSignalBufferRouting] */
  /*   183 */  /* [/ActiveEcuC/Com/ComConfig/SysOpnlMd_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/SysOpnlMd_h2HSC2_67e1a250_RxSignalBufferRouting] */
  /*   184 */  /* [/ActiveEcuC/Com/ComConfig/SysPwrMd_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/SysPwrMd_h2HSC2_67e1a250_RxSignalBufferRouting] */
  /*   185 */  /* [/ActiveEcuC/Com/ComConfig/SysVolMdV_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/SysVolMdV_h2HSC2_67e1a250_RxSignalBufferRouting] */
  /*   186 */  /* [/ActiveEcuC/Com/ComConfig/SysVolMd_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/SysVolMd_h2HSC2_67e1a250_RxSignalBufferRouting] */
  /*   187 */  /* [/ActiveEcuC/Com/ComConfig/SysVolV_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/SysVolV_h2HSC2_67e1a250_RxSignalBufferRouting] */
  /*   188 */  /* [/ActiveEcuC/Com/ComConfig/SysVol_h2HSC2_67e1a250, /ActiveEcuC/Com/ComConfig/SysVol_h2HSC2_67e1a250_RxSignalBufferRouting] */
  /*   189 */  /* [/ActiveEcuC/Com/ComConfig/TBOXAccelZVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/TBOXAccelZVHSC4_09f4c130_RxSignalBufferRouting] */
  /*   190 */  /* [/ActiveEcuC/Com/ComConfig/TCAvlbly_h2HSC2_ab4ba2ce, /ActiveEcuC/Com/ComConfig/TCAvlbly_h2HSC2_ab4ba2ce_RxSignalBufferRouting] */
  /*   191 */  /* [/ActiveEcuC/Com/ComConfig/TCSAHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/TCSAHSC2_5ee26fe4_RxSignalBufferRouting] */
  /*   192 */  /* [/ActiveEcuC/Com/ComConfig/TMSpdV_h1HSC4_d68cf0b9, /ActiveEcuC/Com/ComConfig/TMSpdV_h1HSC4_d68cf0b9_RxSignalBufferRouting] */
  /*   193 */  /* [/ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_ACMDHSC4_c0316154, /ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_ACMDHSC4_c0316154_RxSignalBufferRouting] */
  /*   194 */  /* [/ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_BCMDHSC4_c0316154, /ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_BCMDHSC4_c0316154_RxSignalBufferRouting] */
  /*   195 */  /* [/ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_STATUS_h4HSC4_c0316154, /ActiveEcuC/Com/ComConfig/TOUCH_SCREEN_STATUS_h4HSC4_c0316154_RxSignalBufferRouting] */
  /*   196 */  /* [/ActiveEcuC/Com/ComConfig/TPMSFHSC4_74dd8a6f, /ActiveEcuC/Com/ComConfig/TPMSFHSC4_74dd8a6f_RxSignalBufferRouting] */
  /*   197 */  /* [/ActiveEcuC/Com/ComConfig/TboxP2PRCHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/TboxP2PRCHSC4_09f4c130_RxSignalBufferRouting] */
  /*   198 */  /* [/ActiveEcuC/Com/ComConfig/TimeDspFmtHSC2_c30fb534, /ActiveEcuC/Com/ComConfig/TimeDspFmtHSC2_c30fb534_RxSignalBufferRouting] */
  /*   199 */  /* [/ActiveEcuC/Com/ComConfig/TimeDspFmtHSC4_80f6c9a0, /ActiveEcuC/Com/ComConfig/TimeDspFmtHSC4_80f6c9a0_RxSignalBufferRouting] */
  /* Index        Referable Keys  */
  /*   200 */  /* [/ActiveEcuC/Com/ComConfig/TrShftLvrPosV_h1HSC2_8bd5df01, /ActiveEcuC/Com/ComConfig/TrShftLvrPosV_h1HSC2_8bd5df01_RxSignalBufferRouting] */
  /*   201 */  /* [/ActiveEcuC/Com/ComConfig/TrShftLvrPos_h1HSC2_8bd5df01, /ActiveEcuC/Com/ComConfig/TrShftLvrPos_h1HSC2_8bd5df01_RxSignalBufferRouting] */
  /*   202 */  /* [/ActiveEcuC/Com/ComConfig/TrlrHitchSwAHSC2_762c2774, /ActiveEcuC/Com/ComConfig/TrlrHitchSwAHSC2_762c2774_RxSignalBufferRouting] */
  /*   203 */  /* [/ActiveEcuC/Com/ComConfig/VCUAccReqStsHSC2_cacaa258, /ActiveEcuC/Com/ComConfig/VCUAccReqStsHSC2_cacaa258_RxSignalBufferRouting] */
  /*   204 */  /* [/ActiveEcuC/Com/ComConfig/VCUAccReqValHSC2_cacaa258, /ActiveEcuC/Com/ComConfig/VCUAccReqValHSC2_cacaa258_RxSignalBufferRouting] */
  /*   205 */  /* [/ActiveEcuC/Com/ComConfig/VCUNRCDAvlblHSC2_cacaa258, /ActiveEcuC/Com/ComConfig/VCUNRCDAvlblHSC2_cacaa258_RxSignalBufferRouting] */
  /*   206 */  /* [/ActiveEcuC/Com/ComConfig/VSELatAccVHSC2_542766fd, /ActiveEcuC/Com/ComConfig/VSELatAccVHSC2_542766fd_RxSignalBufferRouting] */
  /*   207 */  /* [/ActiveEcuC/Com/ComConfig/VSELongtAccVHSC2_542766fd, /ActiveEcuC/Com/ComConfig/VSELongtAccVHSC2_542766fd_RxSignalBufferRouting] */
  /*   208 */  /* [/ActiveEcuC/Com/ComConfig/VSESysAHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/VSESysAHSC2_5ee26fe4_RxSignalBufferRouting] */
  /*   209 */  /* [/ActiveEcuC/Com/ComConfig/VehBkwdSwReqHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/VehBkwdSwReqHSC4_09f4c130_RxSignalBufferRouting] */
  /*   210 */  /* [/ActiveEcuC/Com/ComConfig/VehBkwdSwReqVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/VehBkwdSwReqVHSC4_09f4c130_RxSignalBufferRouting] */
  /*   211 */  /* [/ActiveEcuC/Com/ComConfig/VehDynYawRateVHSC2_5ee26fe4, /ActiveEcuC/Com/ComConfig/VehDynYawRateVHSC2_5ee26fe4_RxSignalBufferRouting] */
  /*   212 */  /* [/ActiveEcuC/Com/ComConfig/VehFwdSwReqHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/VehFwdSwReqHSC4_09f4c130_RxSignalBufferRouting] */
  /*   213 */  /* [/ActiveEcuC/Com/ComConfig/VehFwdSwReqVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/VehFwdSwReqVHSC4_09f4c130_RxSignalBufferRouting] */
  /*   214 */  /* [/ActiveEcuC/Com/ComConfig/VehLckngStaHSC4_0f57ab67, /ActiveEcuC/Com/ComConfig/VehLckngStaHSC4_0f57ab67_RxSignalBufferRouting] */
  /*   215 */  /* [/ActiveEcuC/Com/ComConfig/VehOdoV_h2HSC2_78aeb97b, /ActiveEcuC/Com/ComConfig/VehOdoV_h2HSC2_78aeb97b_RxSignalBufferRouting] */
  /*   216 */  /* [/ActiveEcuC/Com/ComConfig/VehRoadWhlLReqHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/VehRoadWhlLReqHSC4_09f4c130_RxSignalBufferRouting] */
  /*   217 */  /* [/ActiveEcuC/Com/ComConfig/VehRoadWhlLReqVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/VehRoadWhlLReqVHSC4_09f4c130_RxSignalBufferRouting] */
  /*   218 */  /* [/ActiveEcuC/Com/ComConfig/VehRoadWhlRReqHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/VehRoadWhlRReqHSC4_09f4c130_RxSignalBufferRouting] */
  /*   219 */  /* [/ActiveEcuC/Com/ComConfig/VehRoadWhlRReqVHSC4_09f4c130, /ActiveEcuC/Com/ComConfig/VehRoadWhlRReqVHSC4_09f4c130_RxSignalBufferRouting] */
  /*   220 */  /* [/ActiveEcuC/Com/ComConfig/VehSideLghtStsHSC2_762c2774, /ActiveEcuC/Com/ComConfig/VehSideLghtStsHSC2_762c2774_RxSignalBufferRouting] */
  /*   221 */  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnVHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnVHSC2_49997ba7_RxSignalBufferRouting] */
  /*   222 */  /* [/ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnVHSC2_49997ba7, /ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnVHSC2_49997ba7_RxSignalBufferRouting] */
  /*   223 */  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnVHSC2_cdd3755d, /ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnVHSC2_cdd3755d_RxSignalBufferRouting] */
  /*   224 */  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnVHSC2_435c72be, /ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnVHSC2_435c72be_RxSignalBufferRouting] */
  /*   225 */  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnVHSC2_cdd3755d, /ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnVHSC2_cdd3755d_RxSignalBufferRouting] */
  /*   226 */  /* [/ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnVHSC2_435c72be, /ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnVHSC2_435c72be_RxSignalBufferRouting] */
  /*   227 */  /* [/ActiveEcuC/Com/ComConfig/Width_LRU1_18ef6e8d, /ActiveEcuC/Com/ComConfig/Width_LRU1_18ef6e8d_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxBuffer
  \brief  Temporary buffer for Rx UINT8_N and UINT8_DYN signals.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TmpRxBufferType, COM_VAR_NOINIT) Com_TmpRxBuffer[8];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[345];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationP2PHSC2_daa1a8e8] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationP2PHSC2_daa1a8e8] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationP2PHSC2_daa1a8e8] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationP2PHSC2_daa1a8e8] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationP2PHSC2_daa1a8e8] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationP2PHSC2_daa1a8e8] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationP2PHSC2_daa1a8e8] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/Sin_Init_LRU1_fdb965bc] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/Sig_Init_SRU3_829252cc] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/Sig_Init_SRU3_829252cc] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationAPAHSC2_c3e0343e] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationAPAHSC2_c3e0343e] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationAPAHSC2_c3e0343e] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationAPAHSC2_c3e0343e] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationAPAHSC2_c3e0343e] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationAPAHSC2_c3e0343e] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/DTCInfomationAPAHSC2_c3e0343e] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APACmdEPSStsHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/APAFHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/APAToqReqStsHSC2_64ef05b4, /ActiveEcuC/Com/ComConfig/APAToqReqValHSC2_64ef05b4] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAToqReqValHSC2_64ef05b4] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APATrgtEPSStrgWhlAngHSC2_64ef05b4] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APATrgtEPSStrgWhlAngHSC2_64ef05b4] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAAlvRCHSC2_64ef05b4] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAChksmHSC2_64ef05b4] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAMdHSC2_a845052a, /ActiveEcuC/Com/ComConfig/APAReqHSC2_a845052a, /ActiveEcuC/Com/ComConfig/APASCSAcclReqValPVHSC2_a845052a] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APASCSAcclReqValPVHSC2_a845052a] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APASCSAcclReqValHSC2_a845052a] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APACrpSpdReqValHSC2_a845052a, /ActiveEcuC/Com/ComConfig/APAEPBOPReqHSC2_a845052a] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APACrpSpdReqStsHSC2_a845052a, /ActiveEcuC/Com/ComConfig/APAInfoDispReqHSC2_a845052a, /ActiveEcuC/Com/ComConfig/APANRCDAvlblHSC2_a845052a] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APASCSAlvRCHSC2_a845052a, /ActiveEcuC/Com/ComConfig/APAShifterPosReqdHSC2_a845052a] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAEPBReqAlvRCHSC2_a845052a, /ActiveEcuC/Com/ComConfig/APASCSAcclReqStsHSC2_a845052a, /ActiveEcuC/Com/ComConfig/APAStsHSC2_a845052a] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAEPBOpReqValPVHSC2_a845052a] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APASlotLngthHSC2_26ca02c9] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APASlotLngthHSC2_26ca02c9] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAParkngSchedHSC2_26ca02c9] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAParkngSchedVHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/APAVehCrdnatAzmthHSC2_26ca02c9] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAVehCrdnatAzmthHSC2_26ca02c9] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APASlotBearngHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosXHSC2_26ca02c9] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosXHSC2_26ca02c9, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosYHSC2_26ca02c9] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/APAVehCrdnatPosYHSC2_26ca02c9] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/PDCSysStsHSC2_ea600257, /ActiveEcuC/Com/ComConfig/RrPDCAudWrnngHSC2_ea600257] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FrtPDCAudWrnngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/RrMidRObsRngHSC2_ea600257] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FrtMidRObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/RrMidLObsRngHSC2_ea600257] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FrtMidLObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/RRObsRngHSC2_ea600257] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FRObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/RLObsRngHSC2_ea600257] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FLObsRngHSC2_ea600257, /ActiveEcuC/Com/ComConfig/PDCCofignStsHSC2_ea600257] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FrtObsDistHSC2_ea600257] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/RrObsDistHSC2_ea600257] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/RRSideObsDistHSC2_e0a50b4e] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/RRSideObsDistHSC2_e0a50b4e] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/RLSideObsDistHSC2_e0a50b4e] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/RLSideObsDistHSC2_e0a50b4e] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FRSideObsDistHSC2_e0a50b4e] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FRSideObsDistHSC2_e0a50b4e] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FLSideObsDistHSC2_e0a50b4e] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/FLSideObsDistHSC2_e0a50b4e] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToBCMRmtCtrlPotclHSC2_4372be29] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToBCMRmtCtrlPotclHSC2_4372be29] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToBCMRmtCtrlPotclHSC2_4372be29] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToBCMRmtCtrlPotclHSC2_4372be29] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToBCMRmtCtrlPotclHSC2_4372be29] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToBCMRmtCtrlPotclHSC2_4372be29] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToBCMRmtCtrlPotclHSC2_4372be29] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToBCMRmtCtrlPotclHSC2_4372be29] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2PACTMdChngTmotHSC4_65a57977] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2PDisplayHSC4_65a57977] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2PProgressHSC4_65a57977, /ActiveEcuC/Com/ComConfig/Route1StateHSC4_65a57977, /ActiveEcuC/Com/ComConfig/Route2StateHSC4_65a57977] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/Route1SavePercentageHSC4_65a57977] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/Route2SavePercentageHSC4_65a57977] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToTBOXCtrlPotclHSC4_ccb7c509] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToTBOXCtrlPotclHSC4_ccb7c509] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToTBOXCtrlPotclHSC4_ccb7c509] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToTBOXCtrlPotclHSC4_ccb7c509] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToTBOXCtrlPotclHSC4_ccb7c509] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToTBOXCtrlPotclHSC4_ccb7c509] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToTBOXCtrlPotclHSC4_ccb7c509] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/IECUToTBOXCtrlPotclHSC4_ccb7c509] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/HD_AVMsysrdyHSC4_4337a868] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/HD_AVMCurViewHSC4_4337a868, /ActiveEcuC/Com/ComConfig/HD_AVMVideoFmtStaHSC4_4337a868] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/HD_AVMErrorDisplay_h4HSC4_4337a868, /ActiveEcuC/Com/ComConfig/HD_AVMInfoDisplayHSC4_4337a868] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/AutoDrvngSysStsHSC4_cdb8af8b] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    92 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    93 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    94 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/TrlrHitchSwA_SecCAN2_516d4ee4] */
  /*    97 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*    98 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*    99 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /* Index        Referable Keys  */
  /*   100 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*   101 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*   102 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be] */
  /*   103 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   104 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   105 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   106 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be] */
  /*   107 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LDircnIO_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/RDircnIO_SecCAN2_5ba847fd] */
  /*   108 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/BntOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/DrvrDoorOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/FrtPsngDoorOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/RRDoorOpenSts_SecCAN2_5ba847fd] */
  /*   109 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LdspcOpenSts_SecCAN2_5ba847fd, /ActiveEcuC/Com/ComConfig/RLDoorOpenSts_SecCAN2_5ba847fd] */
  /*   110 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LdspcOpenSts_SecCAN2_5ba847fd] */
  /*   111 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/SysBPMEnbd_SecCAN2_d527401e, /ActiveEcuC/Com/ComConfig/SysBPM_SecCAN2_d527401e] */
  /*   112 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be] */
  /*   113 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EnRunA_SecCAN2_221bb172] */
  /*   114 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   115 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   116 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   117 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   118 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   119 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   120 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be] */
  /*   121 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPBSwStsV_SecCAN2_2190f0b2, /ActiveEcuC/Com/ComConfig/EPBSwSts_SecCAN2_2190f0b2] */
  /*   122 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   123 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   124 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   125 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   126 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be] */
  /*   129 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPBAvlblyStsPV_SecCAN2_ed3af02c, /ActiveEcuC/Com/ComConfig/EPBAvlblySts_SecCAN2_ed3af02c] */
  /*   130 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPBAppcnSts_SecCAN2_ed3af02c] */
  /*   131 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPSAPASts_SecCAN2_98082ad5] */
  /*   132 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPSAPAInh_SecCAN2_98082ad5] */
  /*   133 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPSAPAAlvRC_SecCAN2_98082ad5] */
  /*   134 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPSAPAChksm_SecCAN2_98082ad5] */
  /*   135 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   136 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   137 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   138 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   139 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   140 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   141 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be] */
  /*   142 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/RstrFctryDeftsReq_SecCAN2_9fc99604] */
  /*   143 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   144 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   145 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   146 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   147 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   148 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /*   149 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be] */
  /* Index        Referable Keys  */
  /*   150 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APASwReq_SecCAN2_0e098acc, /ActiveEcuC/Com/ComConfig/PDCSwReq_SecCAN2_0e098acc] */
  /*   151 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMd_SecCAN2_19729e8f, /ActiveEcuC/Com/ComConfig/DrvrSelAPASlotBearng_SecCAN2_19729e8f] */
  /*   152 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/DrvrSelAPAParkngMd_SecCAN2_19729e8f] */
  /*   153 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   154 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   155 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   156 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   157 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   158 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be] */
  /*   159 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/ECMAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/SCUAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/SDMAvlbly_h2_SecCAN2_88955429] */
  /*   160 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/HCUAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/TCAvlbly_h2_SecCAN2_88955429] */
  /*   161 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*   162 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/BCMAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/FICMAvlbly_h2_SecCAN2_88955429, /ActiveEcuC/Com/ComConfig/IPCAvlbly_h2_SecCAN2_88955429] */
  /*   163 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*   164 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be] */
  /*   165 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/PwrMdMstrAccryA_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/PwrMdMstrRunCrkA_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/SysOpnlMd_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/SysPwrMd_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/SysVolMdV_h2_SecCAN2_443f54b7] */
  /*   166 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   167 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   168 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   169 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/BPMMstrAvlbly_h2_SecCAN2_443f54b7, /ActiveEcuC/Com/ComConfig/SysVolV_h2_SecCAN2_443f54b7] */
  /*   170 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/SysVol_h2_SecCAN2_443f54b7] */
  /*   171 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be] */
  /*   172 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/SysVolMd_h2_SecCAN2_443f54b7] */
  /*   173 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehOdo_h2_SecCAN2_5b704f9c] */
  /*   174 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehOdo_h2_SecCAN2_5b704f9c] */
  /*   175 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehOdo_h2_SecCAN2_5b704f9c] */
  /*   176 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehOdoV_h2_SecCAN2_5b704f9c] */
  /*   177 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   178 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   179 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   180 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be] */
  /*   181 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   182 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   183 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   184 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   185 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   186 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be] */
  /*   187 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrValMsk_h2_SecCAN2_9fee406a, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrValV_h2_SecCAN2_9fee406a] */
  /*   188 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/OtsdAirTemCrVal_h2_SecCAN2_9fee406a] */
  /*   189 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   190 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   191 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   192 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDSts_h2_SecCAN2_11614789] */
  /*   193 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   194 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/APACtrlAbotdRsn_SecCAN2_11614789] */
  /*   195 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   196 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be] */
  /*   197 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2_SecCAN2_63a2ef2a] */
  /*   198 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2_SecCAN2_63a2ef2a] */
  /*   199 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2_SecCAN2_63a2ef2a] */
  /* Index        Referable Keys  */
  /*   200 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2_SecCAN2_63a2ef2a] */
  /*   201 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2_SecCAN2_63a2ef2a] */
  /*   202 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2_SecCAN2_63a2ef2a] */
  /*   203 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2_SecCAN2_63a2ef2a] */
  /*   204 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDMstrChlg_h2_SecCAN2_63a2ef2a] */
  /*   205 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   206 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   207 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   208 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/TrShftLvrPosV_h1_SecCAN2_f7a3932f, /ActiveEcuC/Com/ComConfig/TrShftLvrPos_h1_SecCAN2_f7a3932f] */
  /*   209 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   210 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   211 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   212 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be] */
  /*   213 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPTAccelActuPos_SecCAN2_7ebad171] */
  /*   214 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   215 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptStsV_SecCAN2_7ebad171, /ActiveEcuC/Com/ComConfig/EPTStCmdOn_h1_SecCAN2_7ebad171] */
  /*   216 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPTBrkPdlDscrtInptSts_SecCAN2_7ebad171] */
  /*   217 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   218 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPTAccelActuPosV_SecCAN2_7ebad171] */
  /*   219 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   220 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be] */
  /*   221 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   222 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   223 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   224 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   225 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/EPTRdy_h1_SecCAN2_b210d1ef] */
  /*   226 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   227 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   228 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be] */
  /*   229 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   230 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   231 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   232 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   233 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   234 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be] */
  /*   235 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VCUAccReqSts_SecCAN2_e74ec2d1, /ActiveEcuC/Com/ComConfig/VCUNRCDAvlbl_SecCAN2_e74ec2d1] */
  /*   236 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VCUAccReqVal_SecCAN2_e74ec2d1] */
  /*   237 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/CalendarYear_SecCAN2_ee8bd5bd] */
  /*   238 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/CalendarMonth_SecCAN2_ee8bd5bd] */
  /*   239 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/CalendarDay_SecCAN2_ee8bd5bd] */
  /*   240 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/HourOfDay_SecCAN2_ee8bd5bd] */
  /*   241 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/MinuteOfHour_SecCAN2_ee8bd5bd] */
  /*   242 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/SecsOfMinute_SecCAN2_ee8bd5bd, /ActiveEcuC/Com/ComConfig/TimeDspFmt_SecCAN2_ee8bd5bd] */
  /*   243 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   244 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be] */
  /*   245 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/StrgWhlAngV_SecCAN2_92023e75] */
  /*   246 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/StrgWhlAng_SecCAN2_92023e75] */
  /*   247 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/StrgWhlAng_SecCAN2_92023e75] */
  /*   248 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   249 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /* Index        Referable Keys  */
  /*   250 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   251 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   252 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be] */
  /*   253 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistPlsCtr_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTRC_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistV_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlRstOcd_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlSeqNum_SecCAN2_3a848fe4] */
  /*   254 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistPlsCtr_SecCAN2_3a848fe4] */
  /*   255 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTmsp_SecCAN2_3a848fe4] */
  /*   256 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LDrvnWhlRotlDistTmsp_SecCAN2_3a848fe4] */
  /*   257 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistPlsCtr_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTRC_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistV_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlRstOcd_SecCAN2_3a848fe4, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlSeqNum_SecCAN2_3a848fe4] */
  /*   258 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistPlsCtr_SecCAN2_3a848fe4] */
  /*   259 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTmsp_SecCAN2_3a848fe4] */
  /*   260 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/RDrvnWhlRotlDistTmsp_SecCAN2_3a848fe4] */
  /*   261 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistPC_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistTRC_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistV_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlRstOcd_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlSeqNum_SecCAN2_f62e8f7a] */
  /*   262 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistPC_SecCAN2_f62e8f7a] */
  /*   263 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistT_SecCAN2_f62e8f7a] */
  /*   264 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDistT_SecCAN2_f62e8f7a] */
  /*   265 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistPC_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistTRC_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistV_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlRstOcd_SecCAN2_f62e8f7a, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlSeqNum_SecCAN2_f62e8f7a] */
  /*   266 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistPC_SecCAN2_f62e8f7a] */
  /*   267 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistT_SecCAN2_f62e8f7a] */
  /*   268 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDistT_SecCAN2_f62e8f7a] */
  /*   269 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VSELatAccV_SecCAN2_78a18899, /ActiveEcuC/Com/ComConfig/VSELongtAccV_SecCAN2_78a18899, /ActiveEcuC/Com/ComConfig/VSELongtAcc_SecCAN2_78a18899] */
  /*   270 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VSELongtAcc_SecCAN2_78a18899] */
  /*   271 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VSELatAcc_SecCAN2_78a18899] */
  /*   272 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VSELatAcc_SecCAN2_78a18899] */
  /*   273 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   274 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   275 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   276 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   277 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/LNonDrvnWhlRotlDircn_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/RNonDrvnWhlRotlDircn_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/SCSAPAAlvRC_SecCAN2_b40b8807] */
  /*   278 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/SCSAPAAcclA_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/SCSAPAAvlbl_SecCAN2_b40b8807, /ActiveEcuC/Com/ComConfig/SCSNRCDAvlbl_SecCAN2_b40b8807] */
  /*   279 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   280 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be] */
  /*   281 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   282 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   283 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   284 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/ABSA_SecCAN2_72648180, /ActiveEcuC/Com/ComConfig/TCSA_SecCAN2_72648180, /ActiveEcuC/Com/ComConfig/VSESysA_SecCAN2_72648180] */
  /*   285 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehDynYawRateV_SecCAN2_72648180, /ActiveEcuC/Com/ComConfig/VehDynYawRate_SecCAN2_72648180] */
  /*   286 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehDynYawRate_SecCAN2_72648180] */
  /*   287 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   288 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be] */
  /*   289 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/WhlGndVelLDrvnV_SecCAN2_e1559b39, /ActiveEcuC/Com/ComConfig/WhlGndVelLDrvn_SecCAN2_e1559b39] */
  /*   290 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/WhlGndVelLDrvn_SecCAN2_e1559b39] */
  /*   291 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/WhlGndVelRDrvnV_SecCAN2_e1559b39, /ActiveEcuC/Com/ComConfig/WhlGndVelRDrvn_SecCAN2_e1559b39] */
  /*   292 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/WhlGndVelRDrvn_SecCAN2_e1559b39] */
  /*   293 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   294 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   295 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   296 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be] */
  /*   297 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvnV_SecCAN2_6fda9cda, /ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvn_SecCAN2_6fda9cda] */
  /*   298 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/WhlGndVelLNonDrvn_SecCAN2_6fda9cda] */
  /*   299 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvnV_SecCAN2_6fda9cda, /ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvn_SecCAN2_6fda9cda] */
  /* Index        Referable Keys  */
  /*   300 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/WhlGndVelRNonDrvn_SecCAN2_6fda9cda] */
  /*   301 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   302 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   303 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   304 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be] */
  /*   305 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehSpdAvgDrvnV_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/VehSpdAvgDrvn_SecCAN2_651f95c3] */
  /*   306 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehSpdAvgDrvn_SecCAN2_651f95c3] */
  /*   307 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnRstOcd_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnV_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvn_SecCAN2_651f95c3] */
  /*   308 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvn_SecCAN2_651f95c3] */
  /*   309 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvnV_SecCAN2_651f95c3, /ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvn_SecCAN2_651f95c3] */
  /*   310 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/VehSpdAvgNonDrvn_SecCAN2_651f95c3] */
  /*   311 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/DistRCAvgDrvnSrc_SecCAN2_651f95c3] */
  /*   312 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be] */
  /*   313 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/SCUDrvrIntrvnA_SecCAN2_c246c452, /ActiveEcuC/Com/ComConfig/SCUNRCDAvlbl_SecCAN2_c246c452] */
  /*   314 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   315 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   316 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   317 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   318 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   319 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   320 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be] */
  /*   321 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   322 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/DrvrSbltAtcV_SecCAN2_0cace912, /ActiveEcuC/Com/ComConfig/DrvrSbltAtc_SecCAN2_0cace912] */
  /*   323 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   324 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   325 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   326 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   327 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   328 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be] */
  /*   329 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/TMSpd_h1_SecCAN2_a8511b71] */
  /*   330 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/TMSpd_h1_SecCAN2_a8511b71] */
  /*   331 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/TMSpdV_h1_SecCAN2_a8511b71] */
  /*   332 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   333 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   334 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   335 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   336 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be] */
  /*   337 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   338 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   339 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDF_SecCAN2_d64f184b] */
  /*   340 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   341 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   342 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */
  /*   343 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/NRCDAlvRC_SecCAN2_d64f184b] */
  /*   344 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupStopISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxIPduGroupStopISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupStopISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_WaitingForConfirmation
**********************************************************************************************************************/
/** 
  \var    Com_WaitingForConfirmation
  \brief  Flag array used for Tx error notification handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_WaitingForConfirmationType, COM_VAR_NOINIT) Com_WaitingForConfirmation[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_DTCInfo_P2P_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Init_LRU1_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Init_SRU3_oLIN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oLIN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP00_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP02_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP03_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrP04_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC2_FrS01_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN00_Tx_fcef2243] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrP03_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/P2P_HSC4_FrS01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP01_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/P2P_IECU_HSC4_FrP02_oCAN01_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN01_Tx_fcef2243] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_BCM_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_ECM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPB_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_EPS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_FICM_FrP18_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP08_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP10_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_GW_FrS00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_HCU_FrP13_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_IPK_FrP06_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SAS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP01_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP02_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP03_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP05_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP11_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP12_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCS_FrP15_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SCU_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_SDM_FrP00_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_TC_FrP07_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be, /ActiveEcuC/Com/ComConfig/P2P_oCAN02_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/






/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

