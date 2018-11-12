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
 *              File: Com_Types.h
 *   Generation Time: 2018-08-03 14:23:04
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

#if !defined (COM_TYPES_H)
# define COM_TYPES_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "ComStack_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef P2FUNC(void, COM_APPL_CODE, ComCbkTxAckDefType) (void);
typedef P2FUNC(void, COM_APPL_CODE, ComCbkRxTOutType) (void);
typedef P2FUNC(void, COM_APPL_CODE, ComCbkTxAckImType) (void);
typedef P2FUNC(void, COM_APPL_CODE, ComCbkTxTOutType) (void);
typedef P2FUNC(void, COM_APPL_CODE, ComRxCbkType) (void);
typedef P2FUNC(void, COM_APPL_CODE, ComCbkTxErrType) (void);
typedef P2FUNC(boolean, COM_APPL_CODE, ComTxPduCalloutType) (PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
typedef P2FUNC(boolean, COM_APPL_CODE, ComRxPduCalloutType) (PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);


/** AUTOSAR COM signal object identifier. */
typedef uint16 Com_SignalIdType;

/** AUTOSAR COM signal group object identifier. */
typedef uint16 Com_SignalGroupIdType;

/** AUTOSAR COM PDU group object identifier. */
typedef uint16 Com_IpduGroupIdType;

typedef uint8 Com_IpduGroupVector[1];  /* COM_LMGT_MAXIPDUGROUPVECTORBYTECNT */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

#endif  /* COM_TYPES_H */
/**********************************************************************************************************************
  END OF FILE: Com_Types.h
**********************************************************************************************************************/

