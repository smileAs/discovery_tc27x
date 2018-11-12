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
 *              File: Com_Cbk.h
 *   Generation Time: 2018-09-27 17:21:14
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

#if !defined (COM_CBK_H)
# define COM_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_Com_0777_IPduCallouts */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Cot.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/



/**
 * \defgroup ComHandleIdsComRxPdu Handle IDs of handle space ComRxPdu.
 * \brief Rx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_APA_SecCH_FrP00_oCAN02_3abd61be               0
#define ComConf_ComIPdu_APA_SecCH_FrP01_oCAN02_3abd61be               1
#define ComConf_ComIPdu_APA_SecCH_FrP02_oCAN02_3abd61be               2
#define ComConf_ComIPdu_APA_SecCH_FrP03_oCAN02_3abd61be               3
#define ComConf_ComIPdu_APA_SecCH_FrP04_oCAN02_3abd61be               4
#define ComConf_ComIPdu_DIAG_DTCInfo_APA_oCAN02_3abd61be              5
#define ComConf_ComIPdu_DIAG_FuncReq_HSC2_oCAN00_3abd61be             6
#define ComConf_ComIPdu_DIAG_PhysReq_P2P_oCAN00_3abd61be              7
#define ComConf_ComIPdu_EHBS_HSC2_FrP00_oCAN00_3abd61be               8
#define ComConf_ComIPdu_EPB_HSC2_FrP00_oCAN00_3abd61be                9
#define ComConf_ComIPdu_EPB_HSC2_FrP01_oCAN00_3abd61be                10
#define ComConf_ComIPdu_EPS_HSC2_FrP02_oCAN00_3abd61be                11
#define ComConf_ComIPdu_FICM_HSC4_FrP02_oCAN01_3abd61be               12
#define ComConf_ComIPdu_FICM_HSC4_FrP08_oCAN01_3abd61be               13
#define ComConf_ComIPdu_FICM_HSC4_FrP13_oCAN01_3abd61be               14
#define ComConf_ComIPdu_FICM_HSC4_FrP18_oCAN01_3abd61be               15
#define ComConf_ComIPdu_FICM_HSC4_FrP32_oCAN01_3abd61be               16
#define ComConf_ComIPdu_FICM_HSC4_FrP33_oCAN01_3abd61be               17
#define ComConf_ComIPdu_GW_HSC2_BCM_FrP04_oCAN00_3abd61be             18
#define ComConf_ComIPdu_GW_HSC2_BCM_FrP06_oCAN00_3abd61be             19
#define ComConf_ComIPdu_GW_HSC2_BCM_FrP07_oCAN00_3abd61be             20
#define ComConf_ComIPdu_GW_HSC2_BCM_FrS16_oCAN00_3abd61be             21
#define ComConf_ComIPdu_GW_HSC2_ECM_FrP04_oCAN00_3abd61be             22
#define ComConf_ComIPdu_GW_HSC2_FICM_FrP02_oCAN00_3abd61be            23
#define ComConf_ComIPdu_GW_HSC2_FICM_FrP08_oCAN00_3abd61be            24
#define ComConf_ComIPdu_GW_HSC2_FrP00_oCAN00_3abd61be                 25
#define ComConf_ComIPdu_GW_HSC2_FrP01_oCAN00_3abd61be                 26
#define ComConf_ComIPdu_GW_HSC2_FrP08_oCAN00_3abd61be                 27
#define ComConf_ComIPdu_GW_HSC2_FrP10_oCAN00_3abd61be                 28
#define ComConf_ComIPdu_GW_HSC2_FrP13_oCAN00_3abd61be                 29
#define ComConf_ComIPdu_GW_HSC2_FrS00_oCAN00_3abd61be                 30
#define ComConf_ComIPdu_GW_HSC2_HCU_FrP00_oCAN00_3abd61be             31
#define ComConf_ComIPdu_GW_HSC2_HCU_FrP01_oCAN00_3abd61be             32
#define ComConf_ComIPdu_GW_HSC2_HCU_FrP13_oCAN00_3abd61be             33
#define ComConf_ComIPdu_GW_HSC2_IPK_FrP06_oCAN00_3abd61be             34
#define ComConf_ComIPdu_GW_HSC2_SCU_FrP00_oCAN00_3abd61be             35
#define ComConf_ComIPdu_GW_HSC2_SDM_FrP00_oCAN00_3abd61be             36
#define ComConf_ComIPdu_GW_HSC4_BCM_FrP04_oCAN01_3abd61be             37
#define ComConf_ComIPdu_GW_HSC4_BCM_FrS09_oCAN01_3abd61be             38
#define ComConf_ComIPdu_GW_HSC4_BCM_FrS10_oCAN01_3abd61be             39
#define ComConf_ComIPdu_GW_HSC4_BMS_FrP07_oCAN01_3abd61be             40
#define ComConf_ComIPdu_GW_HSC4_PEPS_FrP01_oCAN01_3abd61be            41
#define ComConf_ComIPdu_GW_HSC4_PEPS_FrP02_oCAN01_3abd61be            42
#define ComConf_ComIPdu_GW_HSC4_TBOX_FrP01_oCAN01_3abd61be            43
#define ComConf_ComIPdu_GW_HSC4_TBOX_FrP05_oCAN01_3abd61be            44
#define ComConf_ComIPdu_GW_HSC4_TBOX_FrS10_oCAN01_3abd61be            45
#define ComConf_ComIPdu_GW_HSC4_TC_FrP01_oCAN01_3abd61be              46
#define ComConf_ComIPdu_IPK_HSC4_FrP06_oCAN01_3abd61be                47
#define ComConf_ComIPdu_PDC_SecCH_FrP00_oCAN02_3abd61be               48
#define ComConf_ComIPdu_PDC_SecCH_FrP01_oCAN02_3abd61be               49
#define ComConf_ComIPdu_RDA_HSC4_P02_oCAN01_3abd61be                  50
#define ComConf_ComIPdu_Read_LRU1_oLIN00_3abd61be                     51
#define ComConf_ComIPdu_Read_SRU3_oLIN00_3abd61be                     52
#define ComConf_ComIPdu_SAS_HSC2_FrP00_oCAN00_3abd61be                53
#define ComConf_ComIPdu_SCS_HSC2_FrP00_oCAN00_3abd61be                54
#define ComConf_ComIPdu_SCS_HSC2_FrP01_oCAN00_3abd61be                55
#define ComConf_ComIPdu_SCS_HSC2_FrP02_oCAN00_3abd61be                56
#define ComConf_ComIPdu_SCS_HSC2_FrP03_oCAN00_3abd61be                57
#define ComConf_ComIPdu_SCS_HSC2_FrP05_oCAN00_3abd61be                58
#define ComConf_ComIPdu_SCS_HSC2_FrP11_oCAN00_3abd61be                59
#define ComConf_ComIPdu_SCS_HSC2_FrP12_oCAN00_3abd61be                60
#define ComConf_ComIPdu_SCS_HSC2_FrP15_oCAN00_3abd61be                61
#define ComConf_ComIPdu_TPMS_HSC3_FrP01_oCAN01_3abd61be               62
#define ComConf_ComIPdu_TPMS_HSC3_FrP02_oCAN01_3abd61be               63
#define ComConf_ComIPdu_Tester_HSC2_ECM_FrP00_oCAN00_3abd61be         64
#define ComConf_ComIPdu_Tester_HSC2_GW_FrP14_oCAN00_3abd61be          65
/**\} */

/**
 * \defgroup ComHandleIdsComTxPdu Handle IDs of handle space ComTxPdu.
 * \brief Tx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_DIAG_DTCInfo_P2P_oCAN00_3abd61be              0
#define ComConf_ComIPdu_Init_LRU1_oLIN00_3abd61be                     1
#define ComConf_ComIPdu_Init_SRU3_oLIN00_3abd61be                     2
#define ComConf_ComIPdu_P2P_DIAG_DTCInfo_APA_oCAN00_3abd61be          3
#define ComConf_ComIPdu_P2P_HSC2_FrP00_oCAN00_3abd61be                4
#define ComConf_ComIPdu_P2P_HSC2_FrP01_oCAN00_3abd61be                5
#define ComConf_ComIPdu_P2P_HSC2_FrP02_oCAN00_3abd61be                6
#define ComConf_ComIPdu_P2P_HSC2_FrP03_oCAN00_3abd61be                7
#define ComConf_ComIPdu_P2P_HSC2_FrP04_oCAN00_3abd61be                8
#define ComConf_ComIPdu_P2P_HSC2_FrS01_oCAN00_3abd61be                9
#define ComConf_ComIPdu_P2P_HSC4_FrP03_oCAN01_3abd61be                10
#define ComConf_ComIPdu_P2P_HSC4_FrS01_oCAN01_3abd61be                11
#define ComConf_ComIPdu_P2P_IECU_HSC4_FrP01_oCAN01_3abd61be           12
#define ComConf_ComIPdu_P2P_IECU_HSC4_FrP02_oCAN01_3abd61be           13
#define ComConf_ComIPdu_P2P_SecCH_BCM_FrP03_oCAN02_3abd61be           14
#define ComConf_ComIPdu_P2P_SecCH_BCM_FrP04_oCAN02_3abd61be           15
#define ComConf_ComIPdu_P2P_SecCH_BCM_FrP07_oCAN02_3abd61be           16
#define ComConf_ComIPdu_P2P_SecCH_ECM_FrP00_oCAN02_3abd61be           17
#define ComConf_ComIPdu_P2P_SecCH_EPB_FrP00_oCAN02_3abd61be           18
#define ComConf_ComIPdu_P2P_SecCH_EPB_FrP01_oCAN02_3abd61be           19
#define ComConf_ComIPdu_P2P_SecCH_EPS_FrP02_oCAN02_3abd61be           20
#define ComConf_ComIPdu_P2P_SecCH_FICM_FrP02_oCAN02_3abd61be          21
#define ComConf_ComIPdu_P2P_SecCH_FICM_FrP08_oCAN02_3abd61be          22
#define ComConf_ComIPdu_P2P_SecCH_FICM_FrP18_oCAN02_3abd61be          23
#define ComConf_ComIPdu_P2P_SecCH_GW_FrP00_oCAN02_3abd61be            24
#define ComConf_ComIPdu_P2P_SecCH_GW_FrP01_oCAN02_3abd61be            25
#define ComConf_ComIPdu_P2P_SecCH_GW_FrP08_oCAN02_3abd61be            26
#define ComConf_ComIPdu_P2P_SecCH_GW_FrP10_oCAN02_3abd61be            27
#define ComConf_ComIPdu_P2P_SecCH_GW_FrP13_oCAN02_3abd61be            28
#define ComConf_ComIPdu_P2P_SecCH_GW_FrS00_oCAN02_3abd61be            29
#define ComConf_ComIPdu_P2P_SecCH_HCU_ECM_FrP04_oCAN02_3abd61be       30
#define ComConf_ComIPdu_P2P_SecCH_HCU_FrP00_oCAN02_3abd61be           31
#define ComConf_ComIPdu_P2P_SecCH_HCU_FrP01_oCAN02_3abd61be           32
#define ComConf_ComIPdu_P2P_SecCH_HCU_FrP13_oCAN02_3abd61be           33
#define ComConf_ComIPdu_P2P_SecCH_IPK_FrP06_oCAN02_3abd61be           34
#define ComConf_ComIPdu_P2P_SecCH_SAS_FrP00_oCAN02_3abd61be           35
#define ComConf_ComIPdu_P2P_SecCH_SCS_FrP00_oCAN02_3abd61be           36
#define ComConf_ComIPdu_P2P_SecCH_SCS_FrP01_oCAN02_3abd61be           37
#define ComConf_ComIPdu_P2P_SecCH_SCS_FrP02_oCAN02_3abd61be           38
#define ComConf_ComIPdu_P2P_SecCH_SCS_FrP03_oCAN02_3abd61be           39
#define ComConf_ComIPdu_P2P_SecCH_SCS_FrP05_oCAN02_3abd61be           40
#define ComConf_ComIPdu_P2P_SecCH_SCS_FrP11_oCAN02_3abd61be           41
#define ComConf_ComIPdu_P2P_SecCH_SCS_FrP12_oCAN02_3abd61be           42
#define ComConf_ComIPdu_P2P_SecCH_SCS_FrP15_oCAN02_3abd61be           43
#define ComConf_ComIPdu_P2P_SecCH_SCU_FrP00_oCAN02_3abd61be           44
#define ComConf_ComIPdu_P2P_SecCH_SDM_FrP00_oCAN02_3abd61be           45
#define ComConf_ComIPdu_P2P_SecCH_TC_FrP07_oCAN02_3abd61be            46
#define ComConf_ComIPdu_P2P_SecCH_Tester_GW_FrP14_oCAN02_3abd61be     47
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
  Com_RxIndication
**********************************************************************************************************************/
/** \brief    This function is called by the lower layer after an I-PDU has been received.
    \param    RxPduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                              Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param    PduInfoPtr      Payload information of the received I-PDU (pointer to data and data length).
    \return   none
    \context  The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used. 
    \synchronous TRUE
    \reentrant   TRUE, for different Handles
    \trace    SPEC-2737026
    \note     The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);


/**********************************************************************************************************************
  Com_TriggerTransmit
**********************************************************************************************************************/
/** \brief    This function is called by the lower layer when an AUTOSAR COM I-PDU shall be transmitted.
              Within this function, AUTOSAR COM shall copy the contents of its I-PDU transmit buffer
              to the L-PDU buffer given by SduPtr.
              Use case:
              This function is used e.g. by the LIN Master for sending out a LIN frame. In this case, the trigger transmit
              can be initiated by the Master schedule table itself or a received LIN header.
              This function is also used by the FlexRay Interface for requesting PDUs to be sent in static part
              (synchronous to the FlexRay global time). Once the I-PDU has been successfully sent by the lower layer
              (PDU-Router), the lower layer must call Com_TxConfirmation().
    \param          TxPduId       ID of AUTOSAR COM I-PDU that is requested to be transmitted by AUTOSAR COM.
    \param[in,out]  PduInfoPtr    Contains a pointer to a buffer (SduDataPtr) where the SDU
                                  data shall be copied to, and the available buffer size in SduLengh.
                                  On return, the service will indicate the length of the copied SDU
                                  data in SduLength.
    \return         E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
    \return         E_NOT_OK      No data has been copied, because
                                  Com is not initialized
                                  or TxPduId is not valid
                                  or PduInfoPtr is NULL_PTR
                                  or SduDataPtr is NULL_PTR
                                  or SduLength is too small.
    \context  TASK|ISR2
    \synchronous TRUE
    \reentrant   TRUE, for different Handles
    \trace    SPEC-2737022, SPEC-2737023, SPEC-2737024
    \note     The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(Std_ReturnType, COM_CODE) Com_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_VAR) PduInfoPtr);


#define COM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

#endif  /* COM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cbk.h
**********************************************************************************************************************/

