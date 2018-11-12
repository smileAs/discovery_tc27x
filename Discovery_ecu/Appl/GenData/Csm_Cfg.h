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
 *            Module: Csm
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.h
 *   Generation Time: 2018-07-31 15:38:39
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



#if !defined (CSM_CFG_H)
#define CSM_CFG_H

#include "Std_Types.h"
#include "Rte_Csm_Type.h"

/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
#ifndef CSM_USE_DUMMY_FUNCTIONS
#define CSM_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef CSM_USE_DUMMY_STATEMENT
#define CSM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef CSM_DUMMY_STATEMENT
#define CSM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CSM_DUMMY_STATEMENT_CONST
#define CSM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CSM_ATOMIC_VARIABLE_ACCESS
#define CSM_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CSM_PROCESSOR_TC277
#define CSM_PROCESSOR_TC277
#endif
#ifndef CSM_COMP_GNU
#define CSM_COMP_GNU
#endif
#ifndef CSM_GEN_GENERATOR_MSR
#define CSM_GEN_GENERATOR_MSR
#endif
#ifndef CSM_CPUTYPE_BITORDER_LSB2MSB
#define CSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef CSM_CONFIGURATION_VARIANT_PRECOMPILE
#define CSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CSM_CONFIGURATION_VARIANT_LINKTIME
#define CSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CSM_CONFIGURATION_VARIANT
#define CSM_CONFIGURATION_VARIANT CSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CSM_POSTBUILD_VARIANT_SUPPORT
#define CSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



/**********************************************************************************************************************
 *  GENERAL PROPERTIES
 *********************************************************************************************************************/
 
 /* Enables or disables error checking */ 
#define CSM_DEV_ERROR_DETECT                                STD_ON

/* Enables or disables error reporting */ 
#define CSM_DEV_ERROR_REPORT                                STD_ON

/* Enables or disables Csm_GetVersionInfo API*/ 
#define CSM_VERSION_INFO_API                                STD_OFF

/* If enabled services operate synchronously, else asynchronously */
#define CSM_USE_SYNC_JOB_PROCESSING                         STD_ON

/* Enables or disables the Interruption of the MainFunction after a given time */ 
#define CSM_USE_INTERRUPTION                                STD_OFF

/* If enabled, APIs of not configured services are not available */
#define CSM_DISABLE_NOT_USED_APIS                           STD_ON

/* The scalar type which has the maximum alignment restrictions on the given platform
 * Valid values are 8, 16 or 32 */
#define CSM_MAX_ALIGN_SCALAR_TYPE                           32U

/* CSM_ASYM_PUB_KEY_MAX_SIZE shall be chosen such that 
 * "CSM_ASYM_PUB_KEY_MAX_SIZE * sizeof(Csm_AlignType)" is greater or equal to the 
 * maximum of the configured values CsmAsymEncryptMaxKeySize,
 * CsmSignatureVerifyMaxKeySize, CsmAsymPublicKeyExtractMaxKeySize, 
 * CsmSymKeyWrapAsymMaxPubKeySize and CsmAsymPrivateKeyWrapAsymMaxPubKeySize. */
#define CSM_ASYM_PUB_KEY_MAX_SIZE                           1U

/* CSM_ASYM_PRIV_KEY_MAX_SIZE shall be chosen such that 
 * "CSM_ASYM_PRIV_KEY_MAX_SIZE * sizeof(Csm_AlignType)" is greater or equal to the 
 * maximum of the configured values CsmAsymDecryptMaxKeySize,
 * CsmSignatureGenerateMaxKeySize, CsmAsymPrivateKeyExtractMaxKeySize, 
 * CsmAsymPrivateKeyWrapSymMaxPrivKeySize and CsmAsymPrivateKeyWrapAsymMaxPrivKeySize. */
#define CSM_ASYM_PRIV_KEY_MAX_SIZE                          1U

/* CSM_SYM_KEY_MAX_SIZE shall be chosen such that 
 * "CSM_SYM_KEY_MAX_SIZE * sizeof(Csm_AlignType)" * is greater or equal to the maximum of the configured values 
 * CsmSymBlockEncryptMaxKeySize, CsmSymBlockDecryptMaxKeySize, 
 * CsmSymEncryptMaxKeySize, CsmSymDecryptMaxKeySize, CsmKeyDeriveMaxKeySize,
 * CsmSymKeyExtractMaxKeySize, CsmMacGenerateMaxKeySize, 
 * CsmMacVerifyMaxKeySize, CsmSymKeyWrapSymMaxSymKeySize,
 * CsmSymKeyWrapAsymMaxSymKeySize, CsmAsymPrivateKeyWrapSymMaxSymKeySize,
 * CsmKeyExchangeCalcSymKeyMaxSymKeySize and CsmKeyDeriveSymKeyMaxSymKeySize. */
#define CSM_SYM_KEY_MAX_SIZE                                1U

/* CSM_KEY_EX_BASE_MAX_SIZE shall be chosen such that 
 * "CSM_KEY_EX_BASE_MAX_SIZE * sizeof(Csm_AlignType)" is greater or equal to the maximum of the configured values 
 * CsmKeyExchangeCalcPubValMaxBaseTypeSize, CsmKeyExchangeCalcSecretMaxBaseTypeSize,
 * and CsmKeyExchangeCalcSymKeyMaxBaseTypeSize. */
#define CSM_KEY_EX_BASE_MAX_SIZE                            1U

/* CSM_KEY_EX_PRIV_MAX_SIZE shall be chosen such that 
* "CSM_KEY_EX_PRIV_MAX_SIZE * sizeof(Csm_AlignType)" is greater or equal to the maximum of the configured values 
* CsmKeyExchangeCalcPubValMaxPrivateTypeSize, CsmKeyExchangeCalcSecretMaxPrivateTypeSize,
* and CsmKeyExchangeCalcSymKeyMaxPrivateTypeSize. */
#define CSM_KEY_EX_PRIV_MAX_SIZE                            1U


/**********************************************************************************************************************
 *  SERVICE CONFIGURATIONS
 *********************************************************************************************************************/

/* CSM_NUMBER_OF_X_CONFIGS determines the amount of configured services of this type */
#define CSM_NUMBER_OF_ASYM_DECRYPT_CONFIGS               0U 
#define CSM_NUMBER_OF_ASYM_ENCRYPT_CONFIGS               0U 
#define CSM_NUMBER_OF_ASYM_PRIVATE_KEY_EXTRACT_CONFIGS   0U 
#define CSM_NUMBER_OF_ASYM_PRIVATE_KEY_WRAP_ASYM_CONFIGS 0U 
#define CSM_NUMBER_OF_ASYM_PRIVATE_KEY_WRAP_SYM_CONFIGS  0U 
#define CSM_NUMBER_OF_ASYM_PUBLIC_KEY_EXTRACT_CONFIGS    0U 
#define CSM_NUMBER_OF_CHECKSUM_CONFIGS                   0U 
#define CSM_NUMBER_OF_HASH_CONFIGS                       0U 
#define CSM_NUMBER_OF_KEY_DERIVE_CONFIGS                 0U 
#define CSM_NUMBER_OF_KEY_DERIVE_SYM_KEY_CONFIGS         0U 
#define CSM_NUMBER_OF_KEY_EXCHANGE_CALC_PUB_VAL_CONFIGS  0U 
#define CSM_NUMBER_OF_KEY_EXCHANGE_CALC_SECRET_CONFIGS   0U 
#define CSM_NUMBER_OF_KEY_EXCHANGE_CALC_SYM_KEY_CONFIGS  0U 
#define CSM_NUMBER_OF_MAC_GENERATE_CONFIGS               0U 
#define CSM_NUMBER_OF_MAC_VERIFY_CONFIGS                 0U 
#define CSM_NUMBER_OF_RANDOM_GENERATE_CONFIGS            0U 
#define CSM_NUMBER_OF_RANDOM_SEED_CONFIGS                0U 
#define CSM_NUMBER_OF_SIGNATURE_GENERATE_CONFIGS         0U 
#define CSM_NUMBER_OF_SIGNATURE_VERIFY_CONFIGS           0U 
#define CSM_NUMBER_OF_SYM_BLOCK_DECRYPT_CONFIGS          0U 
#define CSM_NUMBER_OF_SYM_BLOCK_ENCRYPT_CONFIGS          0U 
#define CSM_NUMBER_OF_SYM_DECRYPT_CONFIGS                0U 
#define CSM_NUMBER_OF_SYM_ENCRYPT_CONFIGS                0U 
#define CSM_NUMBER_OF_SYM_KEY_EXTRACT_CONFIGS            0U 
#define CSM_NUMBER_OF_SYM_KEY_WRAP_ASYM_CONFIGS          0U 
#define CSM_NUMBER_OF_SYM_KEY_WRAP_SYM_CONFIGS           0U 
#define CSM_NUMBER_OF_SERVICES                           0U 




/* Offset of Configuration Ids */
/* CSM_OFFSET_X determines the first ID of the service type. */
#define CSM_OFFSET_ASYM_DECRYPT               0U 
#define CSM_OFFSET_ASYM_ENCRYPT               0U 
#define CSM_OFFSET_ASYM_PRIVATE_KEY_EXTRACT   0U 
#define CSM_OFFSET_ASYM_PRIVATE_KEY_WRAP_ASYM 0U 
#define CSM_OFFSET_ASYM_PRIVATE_KEY_WRAP_SYM  0U 
#define CSM_OFFSET_ASYM_PUBLIC_KEY_EXTRACT    0U 
#define CSM_OFFSET_CHECKSUM                   0U 
#define CSM_OFFSET_HASH                       0U 
#define CSM_OFFSET_KEY_DERIVE                 0U 
#define CSM_OFFSET_KEY_DERIVE_SYM_KEY         0U 
#define CSM_OFFSET_KEY_EXCHANGE_CALC_PUB_VAL  0U 
#define CSM_OFFSET_KEY_EXCHANGE_CALC_SECRET   0U 
#define CSM_OFFSET_KEY_EXCHANGE_CALC_SYM_KEY  0U 
#define CSM_OFFSET_MAC_GENERATE               0U 
#define CSM_OFFSET_MAC_VERIFY                 0U 
#define CSM_OFFSET_RANDOM_GENERATE            0U 
#define CSM_OFFSET_RANDOM_SEED                0U 
#define CSM_OFFSET_SIGNATURE_GENERATE         0U 
#define CSM_OFFSET_SIGNATURE_VERIFY           0U 
#define CSM_OFFSET_SYM_BLOCK_DECRYPT          0U 
#define CSM_OFFSET_SYM_BLOCK_ENCRYPT          0U 
#define CSM_OFFSET_SYM_DECRYPT                0U 
#define CSM_OFFSET_SYM_ENCRYPT                0U 
#define CSM_OFFSET_SYM_KEY_EXTRACT            0U 
#define CSM_OFFSET_SYM_KEY_WRAP_ASYM          0U 
#define CSM_OFFSET_SYM_KEY_WRAP_SYM           0U 



/* Configuration IDs */


#ifndef Rte_TypeDef_Csm_ReturnType
typedef uint8 Csm_ReturnType;
#endif



#endif /* CSM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Csm_Cfg.h
 *********************************************************************************************************************/

