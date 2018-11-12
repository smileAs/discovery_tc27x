/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Csm.c
 *        Config:  discovery_ecu.dpa
 *     SW-C Type:  Csm
 *
 *     Generator:  MICROSAR RTE Generator Version 4.14.0
 *                 RTE Core Version 1.14.0
 *       License:  Unlimited license CBD1800319 for Tong Ji University
 *
 *   Description:  C-Code implementation template for SW-C <Csm>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * AsymPrivateKeyType
 *   
 *
 * AsymPublicKeyType
 *   
 *
 * Csm_ConfigIdType
 *   
 *
 * Csm_ReturnType
 *   
 *
 * Csm_VerifyResultType
 *   
 *
 * KeyExchangeBaseType
 *   
 *
 * KeyExchangePrivateType
 *   
 *
 * SymKeyType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_Csm.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Csm.h"
#include "SchM_Csm.h"
#include "TSC_SchM_Csm.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Csm_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Csm_ConfigIdType: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Csm_ReturnType: Enumeration of integer in interval [0...255] with enumerators
 *   CSM_E_OK (0U)
 *   CSM_E_NOT_OK (1U)
 *   CSM_E_BUSY (2U)
 *   CSM_E_SMALL_BUFFER (3U)
 *   CSM_E_ENTROPY_EXHAUSTION (4U)
 * Csm_VerifyResultType: Enumeration of integer in interval [0...255] with enumerators
 *   CSM_E_VER_OK (0U)
 *   CSM_E_VER_NOT_OK (1U)
 *
 * Array Types:
 * ============
 * Rte_DT_AsymPrivateKeyType_1: Array with 1 element(s) of type uint32
 * Rte_DT_AsymPublicKeyType_1: Array with 1 element(s) of type uint32
 * Rte_DT_KeyExchangeBaseType_1: Array with 1 element(s) of type uint32
 * Rte_DT_KeyExchangePrivateType_1: Array with 1 element(s) of type uint32
 * Rte_DT_SymKeyType_1: Array with 1 element(s) of type uint32
 *
 * Record Types:
 * =============
 * AsymPrivateKeyType: Record with elements
 *   length of type uint32
 *   data of type Rte_DT_AsymPrivateKeyType_1
 * AsymPublicKeyType: Record with elements
 *   length of type uint32
 *   data of type Rte_DT_AsymPublicKeyType_1
 * KeyExchangeBaseType: Record with elements
 *   length of type uint32
 *   data of type Rte_DT_KeyExchangeBaseType_1
 * KeyExchangePrivateType: Record with elements
 *   length of type uint32
 *   data of type Rte_DT_KeyExchangePrivateType_1
 * SymKeyType: Record with elements
 *   length of type uint32
 *   data of type Rte_DT_SymKeyType_1
 *
 *********************************************************************************************************************/


#define Csm_START_SEC_CODE
#include "Csm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Csm_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Csm_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Csm_CODE) Csm_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Csm_MainFunction
 *********************************************************************************************************************/


  Csm_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Csm_STOP_SEC_CODE
#include "Csm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Csm_TestDefines(void)
{
  /* Enumeration Data Types */

  Csm_ReturnType Test_Csm_ReturnType_V_1 = CSM_E_OK;
  Csm_ReturnType Test_Csm_ReturnType_V_2 = CSM_E_NOT_OK;
  Csm_ReturnType Test_Csm_ReturnType_V_3 = CSM_E_BUSY;
  Csm_ReturnType Test_Csm_ReturnType_V_4 = CSM_E_SMALL_BUFFER;
  Csm_ReturnType Test_Csm_ReturnType_V_5 = CSM_E_ENTROPY_EXHAUSTION;

  Csm_VerifyResultType Test_Csm_VerifyResultType_V_1 = CSM_E_VER_OK;
  Csm_VerifyResultType Test_Csm_VerifyResultType_V_2 = CSM_E_VER_NOT_OK;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
