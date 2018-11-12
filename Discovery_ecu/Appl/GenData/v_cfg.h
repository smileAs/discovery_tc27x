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
 *            Module: EcuC
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: v_cfg.h
 *   Generation Time: 2018-08-01 09:30:32
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
#if !defined(__V_CFG_H__)
#define __V_CFG_H__


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef V_USE_DUMMY_FUNCTIONS
#define V_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef V_USE_DUMMY_STATEMENT
#define V_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef V_DUMMY_STATEMENT
#define V_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef V_DUMMY_STATEMENT_CONST
#define V_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef V_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define V_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef V_ATOMIC_VARIABLE_ACCESS
#define V_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef V_PROCESSOR_TC277
#define V_PROCESSOR_TC277
#endif
#ifndef V_COMP_GNU
#define V_COMP_GNU
#endif
#ifndef V_GEN_GENERATOR_MSR
#define V_GEN_GENERATOR_MSR
#endif
#ifndef V_CPUTYPE_BITORDER_LSB2MSB
#define V_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef V_CONFIGURATION_VARIANT_PRECOMPILE
#define V_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef V_CONFIGURATION_VARIANT_LINKTIME
#define V_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef V_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define V_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef V_CONFIGURATION_VARIANT
#define V_CONFIGURATION_VARIANT V_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef V_POSTBUILD_VARIANT_SUPPORT
#define V_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#ifndef C_USE_DUMMY_FUNCTIONS
#define C_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef C_USE_DUMMY_STATEMENT
#define C_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef C_DUMMY_STATEMENT
#define C_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef C_DUMMY_STATEMENT_CONST
#define C_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef C_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define C_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef C_ATOMIC_VARIABLE_ACCESS
#define C_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef C_PROCESSOR_TC277
#define C_PROCESSOR_TC277
#endif
#ifndef C_COMP_GNU
#define C_COMP_GNU
#endif
#ifndef C_GEN_GENERATOR_MSR
#define C_GEN_GENERATOR_MSR
#endif
#ifndef C_CPUTYPE_BITORDER_LSB2MSB
#define C_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef C_CONFIGURATION_VARIANT_PRECOMPILE
#define C_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef C_CONFIGURATION_VARIANT_LINKTIME
#define C_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef C_CONFIGURATION_VARIANT
#define C_CONFIGURATION_VARIANT C_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef C_POSTBUILD_VARIANT_SUPPORT
#define C_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define V_DISABLE_USE_DUMMY_FUNCTIONS
#define V_ENABLE_USE_DUMMY_STATEMENT
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* __V_CFG_H__ */
/**********************************************************************************************************************
 *  END OF FILE: v_cfg.h
 *********************************************************************************************************************/    

