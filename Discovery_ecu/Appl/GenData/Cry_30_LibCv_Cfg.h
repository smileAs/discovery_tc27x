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
 *            Module: Cry_30_LibCv
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Cry_30_LibCv_Cfg.h
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


#if !defined (CRY_30_LIBCV_CFG_H)
#define CRY_30_LIBCV_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */
#include "ESLib.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef CRY_30_LIBCV_USE_DUMMY_FUNCTIONS
#define CRY_30_LIBCV_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef CRY_30_LIBCV_USE_DUMMY_STATEMENT
#define CRY_30_LIBCV_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef CRY_30_LIBCV_DUMMY_STATEMENT
#define CRY_30_LIBCV_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CRY_30_LIBCV_DUMMY_STATEMENT_CONST
#define CRY_30_LIBCV_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CRY_30_LIBCV_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CRY_30_LIBCV_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CRY_30_LIBCV_ATOMIC_VARIABLE_ACCESS
#define CRY_30_LIBCV_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CRY_30_LIBCV_PROCESSOR_TC277
#define CRY_30_LIBCV_PROCESSOR_TC277
#endif
#ifndef CRY_30_LIBCV_COMP_GNU
#define CRY_30_LIBCV_COMP_GNU
#endif
#ifndef CRY_30_LIBCV_GEN_GENERATOR_MSR
#define CRY_30_LIBCV_GEN_GENERATOR_MSR
#endif
#ifndef CRY_30_LIBCV_CPUTYPE_BITORDER_LSB2MSB
#define CRY_30_LIBCV_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef CRY_30_LIBCV_CONFIGURATION_VARIANT_PRECOMPILE
#define CRY_30_LIBCV_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CRY_30_LIBCV_CONFIGURATION_VARIANT_LINKTIME
#define CRY_30_LIBCV_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CRY_30_LIBCV_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CRY_30_LIBCV_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CRY_30_LIBCV_CONFIGURATION_VARIANT
#define CRY_30_LIBCV_CONFIGURATION_VARIANT CRY_30_LIBCV_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CRY_30_LIBCV_POSTBUILD_VARIANT_SUPPORT
#define CRY_30_LIBCV_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Microsar Define Block for Boolean and Integers */
#define CRY_30_LIBCV_USE_SYNC_JOB_PROCESSING                          STD_ON 
#define CRY_30_LIBCV_VERSION_INFO_API                                 STD_OFF 

#define CRY_30_LIBCV_AESBLOCKMODE_CBC                                 0x00000000UL 
#define CRY_30_LIBCV_AESBLOCKMODE_ECB                                 0x00000001UL 
#define CRY_30_LIBCV_AESPADDINGMODE_PKCS5                             0x00000000UL 

/* Configuration Structure Defines */

#ifndef CRY_30_LIBCV_DEV_ERROR_DETECT
#define CRY_30_LIBCV_DEV_ERROR_DETECT STD_OFF
#endif
#ifndef CRY_30_LIBCV_DEV_ERROR_REPORT
#define CRY_30_LIBCV_DEV_ERROR_REPORT STD_OFF
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Cry_30_LibCvPCDataSwitches  Cry_30_LibCv Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRY_30_LIBCV_AESDECRYPT128CONFIG                              STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesDecrypt128Config' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_AESDECRYPT128WORKSPACEIDXOFAESDECRYPT128CONFIG   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesDecrypt128Config.AesDecrypt128WorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_BLOCKMODEOFAESDECRYPT128CONFIG                   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesDecrypt128Config.BlockMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_DUMMYOFAESDECRYPT128CONFIG                       STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesDecrypt128Config.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_PADDINGMODEOFAESDECRYPT128CONFIG                 STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesDecrypt128Config.PaddingMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_AESDECRYPT128WORKSPACE                           STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesDecrypt128WorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_AESENCRYPT128CONFIG                              STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesEncrypt128Config' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_AESENCRYPT128WORKSPACEIDXOFAESENCRYPT128CONFIG   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesEncrypt128Config.AesEncrypt128WorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_BLOCKMODEOFAESENCRYPT128CONFIG                   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesEncrypt128Config.BlockMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_DUMMYOFAESENCRYPT128CONFIG                       STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesEncrypt128Config.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_PADDINGMODEOFAESENCRYPT128CONFIG                 STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesEncrypt128Config.PaddingMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_AESENCRYPT128WORKSPACE                           STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_AesEncrypt128WorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_CMACAES128GENCONFIG                              STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_CmacAes128GenConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_CMACAES128GENWORKSPACEIDXOFCMACAES128GENCONFIG   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_CmacAes128GenConfig.CmacAes128GenWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_CMACAES128GENWORKSPACE                           STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_CmacAes128GenWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_CMACAES128VERCONFIG                              STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_CmacAes128VerConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_CMACAES128VERWORKSPACEIDXOFCMACAES128VERCONFIG   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_CmacAes128VerConfig.CmacAes128VerWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_DUMMYOFCMACAES128VERCONFIG                       STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_CmacAes128VerConfig.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_LENGTHINBYTESOFCMACAES128VERCONFIG               STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_CmacAes128VerConfig.LengthInBytes' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_CMACAES128VERWORKSPACE                           STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_CmacAes128VerWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_ECDHCONFIG                                       STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdhConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_DUMMYOFECDHCONFIG                                STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdhConfig.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_ECDHWORKSPACEIDXOFECDHCONFIG                     STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdhConfig.EcdhWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_PBKDF2ITERATIONCOUNTOFECDHCONFIG                 STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdhConfig.PBKDF2IterationCount' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_ECDHWORKSPACE                                    STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdhWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_ECDSASIGGENCONFIG                                STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigGenConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_BERENCODINGOFECDSASIGGENCONFIG                   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigGenConfig.BerEncoding' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_DUMMYOFECDSASIGGENCONFIG                         STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigGenConfig.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_ECDSASIGGENWORKSPACEIDXOFECDSASIGGENCONFIG       STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigGenConfig.EcdsaSigGenWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_ECDSASIGGENWORKSPACE                             STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigGenWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_ECDSASIGVERCONFIG                                STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigVerConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_BERENCODINGOFECDSASIGVERCONFIG                   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigVerConfig.BerEncoding' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_DUMMYOFECDSASIGVERCONFIG                         STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigVerConfig.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_ECDSASIGVERWORKSPACEIDXOFECDSASIGVERCONFIG       STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigVerConfig.EcdsaSigVerWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_ECDSASIGVERWORKSPACE                             STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_EcdsaSigVerWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_EXPECTEDCOMPATIBILITYVERSION                     STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRY_30_LIBCV_FINALMAGICNUMBER                                 STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRY_30_LIBCV_FIPS186CONFIG                                    STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_Fips186Config' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_DUMMYOFFIPS186CONFIG                             STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_Fips186Config.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_FIPS186WORKSPACEIDXOFFIPS186CONFIG               STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_Fips186Config.Fips186WorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_SAVESTATEOFFIPS186CONFIG                         STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_Fips186Config.SaveState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_FIPS186WORKSPACE                                 STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_Fips186WorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_GENERATORCOMPATIBILITYVERSION                    STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRY_30_LIBCV_HASHRIPEMD160CONFIG                              STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HashRipemd160Config' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_HASHRIPEMD160WORKSPACEIDXOFHASHRIPEMD160CONFIG   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HashRipemd160Config.HashRipemd160WorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HASHRIPEMD160WORKSPACE                           STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HashRipemd160WorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HASHSHA1CONFIG                                   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HashSha1Config' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_HASHSHA1WORKSPACEIDXOFHASHSHA1CONFIG             STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HashSha1Config.HashSha1WorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HASHSHA1WORKSPACE                                STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HashSha1WorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HASHSHA256CONFIG                                 STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HashSha256Config' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_HASHSHA256WORKSPACEIDXOFHASHSHA256CONFIG         STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HashSha256Config.HashSha256WorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HASHSHA256WORKSPACE                              STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HashSha256WorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HMACSHA1VERIFYCONFIG                             STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha1VerifyConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_DUMMYOFHMACSHA1VERIFYCONFIG                      STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha1VerifyConfig.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_HMACSHA1VERIFYWORKSPACEIDXOFHMACSHA1VERIFYCONFIG STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha1VerifyConfig.HmacSha1VerifyWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_LENGTHINBYTESOFHMACSHA1VERIFYCONFIG              STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha1VerifyConfig.LengthInBytes' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HMACSHA1VERIFYWORKSPACE                          STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha1VerifyWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HMACSHA256GENERATECONFIG                         STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha256GenerateConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_HMACSHA256GENERATEWORKSPACEIDXOFHMACSHA256GENERATECONFIG STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha256GenerateConfig.HmacSha256GenerateWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HMACSHA256GENERATEWORKSPACE                      STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha256GenerateWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HMACSHA256VERIFYCONFIG                           STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha256VerifyConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_DUMMYOFHMACSHA256VERIFYCONFIG                    STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha256VerifyConfig.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_HMACSHA256VERIFYWORKSPACEIDXOFHMACSHA256VERIFYCONFIG STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha256VerifyConfig.HmacSha256VerifyWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_LENGTHINBYTESOFHMACSHA256VERIFYCONFIG            STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha256VerifyConfig.LengthInBytes' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_HMACSHA256VERIFYWORKSPACE                        STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_HmacSha256VerifyWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_INITDATAHASHCODE                                 STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRY_30_LIBCV_KDF2HMACSHA1CONFIG                               STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_Kdf2HmacSha1Config' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_KDF2HMACSHA1WORKSPACEIDXOFKDF2HMACSHA1CONFIG     STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_Kdf2HmacSha1Config.Kdf2HmacSha1WorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_KDF2HMACSHA1WORKSPACE                            STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_Kdf2HmacSha1WorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_RSADECRYPTCONFIG                                 STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_RsaDecryptConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_DUMMYOFRSADECRYPTCONFIG                          STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_RsaDecryptConfig.Dummy' Reason: 'Dummy field generation is disabled!' */
#define CRY_30_LIBCV_RSADECRYPTWORKSPACEIDXOFRSADECRYPTCONFIG         STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_RsaDecryptConfig.RsaDecryptWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_USEPRIVATEKEYOFRSADECRYPTCONFIG                  STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_RsaDecryptConfig.UsePrivateKey' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_RSADECRYPTWORKSPACE                              STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_RsaDecryptWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_RSASHA1SIGVERCONFIG                              STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_RsaSha1SigVerConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRY_30_LIBCV_RSASHA1SIGVERWORKSPACEIDXOFRSASHA1SIGVERCONFIG   STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_RsaSha1SigVerConfig.RsaSha1SigVerWorkSpaceIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_RSASHA1SIGVERWORKSPACE                           STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_RsaSha1SigVerWorkSpace' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRY_30_LIBCV_USESYNCJOBPROCESSINGOFGENERAL                    STD_ON
#define CRY_30_LIBCV_VERSIONINFOAPIOFGENERAL                          STD_ON
#define CRY_30_LIBCV_PCCONFIG                                         STD_ON
#define CRY_30_LIBCV_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG           STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRY_30_LIBCV_FINALMAGICNUMBEROFPCCONFIG                       STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRY_30_LIBCV_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG          STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRY_30_LIBCV_INITDATAHASHCODEOFPCCONFIG                       STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRY_30_LIBCV_USESYNCJOBPROCESSINGOFGENERALOFPCCONFIG          STD_ON
#define CRY_30_LIBCV_VERSIONINFOAPIOFGENERALOFPCCONFIG                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCNoReferenceDefines  Cry_30_LibCv No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CRY_30_LIBCV_NO_EXPECTEDCOMPATIBILITYVERSION                  65535U
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCIsReducedToDefineDefines  Cry_30_LibCv Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRY_30_LIBCV_ISDEF_AESDECRYPT128WORKSPACEIDXOFAESDECRYPT128CONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_BLOCKMODEOFAESDECRYPT128CONFIG             STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFAESDECRYPT128CONFIG                 STD_OFF
#define CRY_30_LIBCV_ISDEF_PADDINGMODEOFAESDECRYPT128CONFIG           STD_OFF
#define CRY_30_LIBCV_ISDEF_AESENCRYPT128WORKSPACEIDXOFAESENCRYPT128CONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_BLOCKMODEOFAESENCRYPT128CONFIG             STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFAESENCRYPT128CONFIG                 STD_OFF
#define CRY_30_LIBCV_ISDEF_PADDINGMODEOFAESENCRYPT128CONFIG           STD_OFF
#define CRY_30_LIBCV_ISDEF_CMACAES128GENWORKSPACEIDXOFCMACAES128GENCONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_CMACAES128VERWORKSPACEIDXOFCMACAES128VERCONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFCMACAES128VERCONFIG                 STD_OFF
#define CRY_30_LIBCV_ISDEF_LENGTHINBYTESOFCMACAES128VERCONFIG         STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFECDHCONFIG                          STD_OFF
#define CRY_30_LIBCV_ISDEF_ECDHWORKSPACEIDXOFECDHCONFIG               STD_OFF
#define CRY_30_LIBCV_ISDEF_PBKDF2ITERATIONCOUNTOFECDHCONFIG           STD_OFF
#define CRY_30_LIBCV_ISDEF_BERENCODINGOFECDSASIGGENCONFIG             STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFECDSASIGGENCONFIG                   STD_OFF
#define CRY_30_LIBCV_ISDEF_ECDSASIGGENWORKSPACEIDXOFECDSASIGGENCONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_BERENCODINGOFECDSASIGVERCONFIG             STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFECDSASIGVERCONFIG                   STD_OFF
#define CRY_30_LIBCV_ISDEF_ECDSASIGVERWORKSPACEIDXOFECDSASIGVERCONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFFIPS186CONFIG                       STD_OFF
#define CRY_30_LIBCV_ISDEF_FIPS186WORKSPACEIDXOFFIPS186CONFIG         STD_OFF
#define CRY_30_LIBCV_ISDEF_SAVESTATEOFFIPS186CONFIG                   STD_OFF
#define CRY_30_LIBCV_ISDEF_HASHRIPEMD160WORKSPACEIDXOFHASHRIPEMD160CONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_HASHSHA1WORKSPACEIDXOFHASHSHA1CONFIG       STD_OFF
#define CRY_30_LIBCV_ISDEF_HASHSHA256WORKSPACEIDXOFHASHSHA256CONFIG   STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFHMACSHA1VERIFYCONFIG                STD_OFF
#define CRY_30_LIBCV_ISDEF_HMACSHA1VERIFYWORKSPACEIDXOFHMACSHA1VERIFYCONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_LENGTHINBYTESOFHMACSHA1VERIFYCONFIG        STD_OFF
#define CRY_30_LIBCV_ISDEF_HMACSHA256GENERATEWORKSPACEIDXOFHMACSHA256GENERATECONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFHMACSHA256VERIFYCONFIG              STD_OFF
#define CRY_30_LIBCV_ISDEF_HMACSHA256VERIFYWORKSPACEIDXOFHMACSHA256VERIFYCONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_LENGTHINBYTESOFHMACSHA256VERIFYCONFIG      STD_OFF
#define CRY_30_LIBCV_ISDEF_KDF2HMACSHA1WORKSPACEIDXOFKDF2HMACSHA1CONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_DUMMYOFRSADECRYPTCONFIG                    STD_OFF
#define CRY_30_LIBCV_ISDEF_RSADECRYPTWORKSPACEIDXOFRSADECRYPTCONFIG   STD_OFF
#define CRY_30_LIBCV_ISDEF_USEPRIVATEKEYOFRSADECRYPTCONFIG            STD_OFF
#define CRY_30_LIBCV_ISDEF_RSASHA1SIGVERWORKSPACEIDXOFRSASHA1SIGVERCONFIG STD_OFF
#define CRY_30_LIBCV_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG     STD_OFF
#define CRY_30_LIBCV_ISDEF_FINALMAGICNUMBEROFPCCONFIG                 STD_OFF
#define CRY_30_LIBCV_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG    STD_OFF
#define CRY_30_LIBCV_ISDEF_INITDATAHASHCODEOFPCCONFIG                 STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCEqualsAlwaysToDefines  Cry_30_LibCv Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRY_30_LIBCV_EQ2_AESDECRYPT128WORKSPACEIDXOFAESDECRYPT128CONFIG 
#define CRY_30_LIBCV_EQ2_BLOCKMODEOFAESDECRYPT128CONFIG               
#define CRY_30_LIBCV_EQ2_DUMMYOFAESDECRYPT128CONFIG                   
#define CRY_30_LIBCV_EQ2_PADDINGMODEOFAESDECRYPT128CONFIG             
#define CRY_30_LIBCV_EQ2_AESENCRYPT128WORKSPACEIDXOFAESENCRYPT128CONFIG 
#define CRY_30_LIBCV_EQ2_BLOCKMODEOFAESENCRYPT128CONFIG               
#define CRY_30_LIBCV_EQ2_DUMMYOFAESENCRYPT128CONFIG                   
#define CRY_30_LIBCV_EQ2_PADDINGMODEOFAESENCRYPT128CONFIG             
#define CRY_30_LIBCV_EQ2_CMACAES128GENWORKSPACEIDXOFCMACAES128GENCONFIG 
#define CRY_30_LIBCV_EQ2_CMACAES128VERWORKSPACEIDXOFCMACAES128VERCONFIG 
#define CRY_30_LIBCV_EQ2_DUMMYOFCMACAES128VERCONFIG                   
#define CRY_30_LIBCV_EQ2_LENGTHINBYTESOFCMACAES128VERCONFIG           
#define CRY_30_LIBCV_EQ2_DUMMYOFECDHCONFIG                            
#define CRY_30_LIBCV_EQ2_ECDHWORKSPACEIDXOFECDHCONFIG                 
#define CRY_30_LIBCV_EQ2_PBKDF2ITERATIONCOUNTOFECDHCONFIG             
#define CRY_30_LIBCV_EQ2_BERENCODINGOFECDSASIGGENCONFIG               
#define CRY_30_LIBCV_EQ2_DUMMYOFECDSASIGGENCONFIG                     
#define CRY_30_LIBCV_EQ2_ECDSASIGGENWORKSPACEIDXOFECDSASIGGENCONFIG   
#define CRY_30_LIBCV_EQ2_BERENCODINGOFECDSASIGVERCONFIG               
#define CRY_30_LIBCV_EQ2_DUMMYOFECDSASIGVERCONFIG                     
#define CRY_30_LIBCV_EQ2_ECDSASIGVERWORKSPACEIDXOFECDSASIGVERCONFIG   
#define CRY_30_LIBCV_EQ2_DUMMYOFFIPS186CONFIG                         
#define CRY_30_LIBCV_EQ2_FIPS186WORKSPACEIDXOFFIPS186CONFIG           
#define CRY_30_LIBCV_EQ2_SAVESTATEOFFIPS186CONFIG                     
#define CRY_30_LIBCV_EQ2_HASHRIPEMD160WORKSPACEIDXOFHASHRIPEMD160CONFIG 
#define CRY_30_LIBCV_EQ2_HASHSHA1WORKSPACEIDXOFHASHSHA1CONFIG         
#define CRY_30_LIBCV_EQ2_HASHSHA256WORKSPACEIDXOFHASHSHA256CONFIG     
#define CRY_30_LIBCV_EQ2_DUMMYOFHMACSHA1VERIFYCONFIG                  
#define CRY_30_LIBCV_EQ2_HMACSHA1VERIFYWORKSPACEIDXOFHMACSHA1VERIFYCONFIG 
#define CRY_30_LIBCV_EQ2_LENGTHINBYTESOFHMACSHA1VERIFYCONFIG          
#define CRY_30_LIBCV_EQ2_HMACSHA256GENERATEWORKSPACEIDXOFHMACSHA256GENERATECONFIG 
#define CRY_30_LIBCV_EQ2_DUMMYOFHMACSHA256VERIFYCONFIG                
#define CRY_30_LIBCV_EQ2_HMACSHA256VERIFYWORKSPACEIDXOFHMACSHA256VERIFYCONFIG 
#define CRY_30_LIBCV_EQ2_LENGTHINBYTESOFHMACSHA256VERIFYCONFIG        
#define CRY_30_LIBCV_EQ2_KDF2HMACSHA1WORKSPACEIDXOFKDF2HMACSHA1CONFIG 
#define CRY_30_LIBCV_EQ2_DUMMYOFRSADECRYPTCONFIG                      
#define CRY_30_LIBCV_EQ2_RSADECRYPTWORKSPACEIDXOFRSADECRYPTCONFIG     
#define CRY_30_LIBCV_EQ2_USEPRIVATEKEYOFRSADECRYPTCONFIG              
#define CRY_30_LIBCV_EQ2_RSASHA1SIGVERWORKSPACEIDXOFRSASHA1SIGVERCONFIG 
#define CRY_30_LIBCV_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG       
#define CRY_30_LIBCV_EQ2_FINALMAGICNUMBEROFPCCONFIG                   
#define CRY_30_LIBCV_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG      
#define CRY_30_LIBCV_EQ2_INITDATAHASHCODEOFPCCONFIG                   
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCSymbolicInitializationPointers  Cry_30_LibCv Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Cry_30_LibCv_Config_Ptr                                       NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Cry_30_LibCv' */
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCInitializationSymbols  Cry_30_LibCv Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Cry_30_LibCv_Config                                           NULL_PTR  /**< symbolic identifier which could be used to initialize 'Cry_30_LibCv */
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCGeneral  Cry_30_LibCv General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CRY_30_LIBCV_CHECK_INIT_POINTER                               STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CRY_30_LIBCV_FINAL_MAGIC_NUMBER                               0xFF1EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of Cry_30_LibCv */
#define CRY_30_LIBCV_INDIVIDUAL_POSTBUILD                             STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Cry_30_LibCv' is not configured to be postbuild capable. */
#define CRY_30_LIBCV_INIT_DATA                                        CRY_30_LIBCV_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CRY_30_LIBCV_INIT_DATA_HASH_CODE                              -492792326L  /**< the precompile constant to validate the initialization structure at initialization time of Cry_30_LibCv with a hashcode. The seed value is '0xFF1EU' */
#define CRY_30_LIBCV_USE_ECUM_BSW_ERROR_HOOK                          STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CRY_30_LIBCV_USE_INIT_POINTER                                 STD_OFF  /**< STD_ON if the init pointer Cry_30_LibCv shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Cry_30_LibCvPBDataSwitches  Cry_30_LibCv Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRY_30_LIBCV_PBCONFIG                                         STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRY_30_LIBCV_LTCONFIGIDXOFPBCONFIG                            STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRY_30_LIBCV_PCCONFIGIDXOFPBCONFIG                            STD_OFF  /**< Deactivateable: 'Cry_30_LibCv_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPBIsReducedToDefineDefines  Cry_30_LibCv Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRY_30_LIBCV_ISDEF_LTCONFIGIDXOFPBCONFIG                      STD_OFF
#define CRY_30_LIBCV_ISDEF_PCCONFIGIDXOFPBCONFIG                      STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPBEqualsAlwaysToDefines  Cry_30_LibCv Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRY_30_LIBCV_EQ2_LTCONFIGIDXOFPBCONFIG                        
#define CRY_30_LIBCV_EQ2_PCCONFIGIDXOFPBCONFIG                        
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Cry_30_LibCvPCGetRootDataMacros  Cry_30_LibCv Get Root Data Macros (PRE_COMPILE)
  \brief  These are used to get data pointers of root data.
  \{
*/ 
#define Cry_30_LibCv_GetExpectedCompatibilityVersionOfPCConfig()      
#define Cry_30_LibCv_GetFinalMagicNumberOfPCConfig()                  
#define Cry_30_LibCv_GetGeneratorCompatibilityVersionOfPCConfig()     
#define Cry_30_LibCv_GetInitDataHashCodeOfPCConfig()                  
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCGetConstantDuplicatedRootDataMacros  Cry_30_LibCv Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Cry_30_LibCv_IsUseSyncJobProcessingOfGeneralOfPCConfig()      (((TRUE)) != FALSE)
#define Cry_30_LibCv_IsVersionInfoApiOfGeneralOfPCConfig()            (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCGetDataMacros  Cry_30_LibCv Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Cry_30_LibCv_GetAesDecrypt128Config(Index)                    
#define Cry_30_LibCv_GetAesDecrypt128WorkSpaceIdxOfAesDecrypt128Config(Symbol) 
#define Cry_30_LibCv_GetBlockModeOfAesDecrypt128Config(Symbol)        
#define Cry_30_LibCv_IsDummyOfAesDecrypt128Config(Symbol)             
#define Cry_30_LibCv_GetPaddingModeOfAesDecrypt128Config(Symbol)      
#define Cry_30_LibCv_GetAesDecrypt128WorkSpace(Index)                 
#define Cry_30_LibCv_GetAesEncrypt128Config(Index)                    
#define Cry_30_LibCv_GetAesEncrypt128WorkSpaceIdxOfAesEncrypt128Config(Symbol) 
#define Cry_30_LibCv_GetBlockModeOfAesEncrypt128Config(Symbol)        
#define Cry_30_LibCv_IsDummyOfAesEncrypt128Config(Symbol)             
#define Cry_30_LibCv_GetPaddingModeOfAesEncrypt128Config(Symbol)      
#define Cry_30_LibCv_GetAesEncrypt128WorkSpace(Index)                 
#define Cry_30_LibCv_GetCmacAes128GenConfig(Index)                    
#define Cry_30_LibCv_GetCmacAes128GenWorkSpaceIdxOfCmacAes128GenConfig(Symbol) 
#define Cry_30_LibCv_GetCmacAes128GenWorkSpace(Index)                 
#define Cry_30_LibCv_GetCmacAes128VerConfig(Index)                    
#define Cry_30_LibCv_GetCmacAes128VerWorkSpaceIdxOfCmacAes128VerConfig(Symbol) 
#define Cry_30_LibCv_IsDummyOfCmacAes128VerConfig(Symbol)             
#define Cry_30_LibCv_IsLengthInBytesOfCmacAes128VerConfig(Symbol)     
#define Cry_30_LibCv_GetCmacAes128VerWorkSpace(Index)                 
#define Cry_30_LibCv_GetEcdhConfig(Index)                             
#define Cry_30_LibCv_IsDummyOfEcdhConfig(Symbol)                      
#define Cry_30_LibCv_GetEcdhWorkSpaceIdxOfEcdhConfig(Symbol)          
#define Cry_30_LibCv_GetPBKDF2IterationCountOfEcdhConfig(Symbol)      
#define Cry_30_LibCv_GetEcdhWorkSpace(Index)                          
#define Cry_30_LibCv_GetEcdsaSigGenConfig(Index)                      
#define Cry_30_LibCv_IsBerEncodingOfEcdsaSigGenConfig(Symbol)         
#define Cry_30_LibCv_IsDummyOfEcdsaSigGenConfig(Symbol)               
#define Cry_30_LibCv_GetEcdsaSigGenWorkSpaceIdxOfEcdsaSigGenConfig(Symbol) 
#define Cry_30_LibCv_GetEcdsaSigGenWorkSpace(Index)                   
#define Cry_30_LibCv_GetEcdsaSigVerConfig(Index)                      
#define Cry_30_LibCv_IsBerEncodingOfEcdsaSigVerConfig(Symbol)         
#define Cry_30_LibCv_IsDummyOfEcdsaSigVerConfig(Symbol)               
#define Cry_30_LibCv_GetEcdsaSigVerWorkSpaceIdxOfEcdsaSigVerConfig(Symbol) 
#define Cry_30_LibCv_GetEcdsaSigVerWorkSpace(Index)                   
#define Cry_30_LibCv_GetFips186Config(Index)                          
#define Cry_30_LibCv_IsDummyOfFips186Config(Symbol)                   
#define Cry_30_LibCv_GetFips186WorkSpaceIdxOfFips186Config(Symbol)    
#define Cry_30_LibCv_IsSaveStateOfFips186Config(Symbol)               
#define Cry_30_LibCv_GetFips186WorkSpace(Index)                       
#define Cry_30_LibCv_GetHashRipemd160Config(Index)                    
#define Cry_30_LibCv_GetHashRipemd160WorkSpaceIdxOfHashRipemd160Config(Symbol) 
#define Cry_30_LibCv_GetHashRipemd160WorkSpace(Index)                 
#define Cry_30_LibCv_GetHashSha1Config(Index)                         
#define Cry_30_LibCv_GetHashSha1WorkSpaceIdxOfHashSha1Config(Symbol)  
#define Cry_30_LibCv_GetHashSha1WorkSpace(Index)                      
#define Cry_30_LibCv_GetHashSha256Config(Index)                       
#define Cry_30_LibCv_GetHashSha256WorkSpaceIdxOfHashSha256Config(Symbol) 
#define Cry_30_LibCv_GetHashSha256WorkSpace(Index)                    
#define Cry_30_LibCv_GetHmacSha1VerifyConfig(Index)                   
#define Cry_30_LibCv_IsDummyOfHmacSha1VerifyConfig(Symbol)            
#define Cry_30_LibCv_GetHmacSha1VerifyWorkSpaceIdxOfHmacSha1VerifyConfig(Symbol) 
#define Cry_30_LibCv_IsLengthInBytesOfHmacSha1VerifyConfig(Symbol)    
#define Cry_30_LibCv_GetHmacSha1VerifyWorkSpace(Index)                
#define Cry_30_LibCv_GetHmacSha256GenerateConfig(Index)               
#define Cry_30_LibCv_GetHmacSha256GenerateWorkSpaceIdxOfHmacSha256GenerateConfig(Symbol) 
#define Cry_30_LibCv_GetHmacSha256GenerateWorkSpace(Index)            
#define Cry_30_LibCv_GetHmacSha256VerifyConfig(Index)                 
#define Cry_30_LibCv_IsDummyOfHmacSha256VerifyConfig(Symbol)          
#define Cry_30_LibCv_GetHmacSha256VerifyWorkSpaceIdxOfHmacSha256VerifyConfig(Symbol) 
#define Cry_30_LibCv_IsLengthInBytesOfHmacSha256VerifyConfig(Symbol)  
#define Cry_30_LibCv_GetHmacSha256VerifyWorkSpace(Index)              
#define Cry_30_LibCv_GetKdf2HmacSha1Config(Index)                     
#define Cry_30_LibCv_GetKdf2HmacSha1WorkSpaceIdxOfKdf2HmacSha1Config(Symbol) 
#define Cry_30_LibCv_GetKdf2HmacSha1WorkSpace(Index)                  
#define Cry_30_LibCv_GetRsaDecryptConfig(Index)                       
#define Cry_30_LibCv_IsDummyOfRsaDecryptConfig(Symbol)                
#define Cry_30_LibCv_GetRsaDecryptWorkSpaceIdxOfRsaDecryptConfig(Symbol) 
#define Cry_30_LibCv_IsUsePrivateKeyOfRsaDecryptConfig(Symbol)        
#define Cry_30_LibCv_GetRsaDecryptWorkSpace(Index)                    
#define Cry_30_LibCv_GetRsaSha1SigVerConfig(Index)                    
#define Cry_30_LibCv_GetRsaSha1SigVerWorkSpaceIdxOfRsaSha1SigVerConfig(Symbol) 
#define Cry_30_LibCv_GetRsaSha1SigVerWorkSpace(Index)                 
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCGetDeduplicatedDataMacros  Cry_30_LibCv Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Cry_30_LibCv_GetExpectedCompatibilityVersion()                
#define Cry_30_LibCv_GetFinalMagicNumber()                            
#define Cry_30_LibCv_GetGeneratorCompatibilityVersion()               
#define Cry_30_LibCv_GetInitDataHashCode()                            
#define Cry_30_LibCv_IsUseSyncJobProcessingOfGeneral()                Cry_30_LibCv_IsUseSyncJobProcessingOfGeneralOfPCConfig()
#define Cry_30_LibCv_IsVersionInfoApiOfGeneral()                      Cry_30_LibCv_IsVersionInfoApiOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCSetDataMacros  Cry_30_LibCv Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Cry_30_LibCv_SetAesDecrypt128WorkSpace(Index, Value)          
#define Cry_30_LibCv_SetAesEncrypt128WorkSpace(Index, Value)          
#define Cry_30_LibCv_SetCmacAes128GenWorkSpace(Index, Value)          
#define Cry_30_LibCv_SetCmacAes128VerWorkSpace(Index, Value)          
#define Cry_30_LibCv_SetEcdhWorkSpace(Index, Value)                   
#define Cry_30_LibCv_SetEcdsaSigGenWorkSpace(Index, Value)            
#define Cry_30_LibCv_SetEcdsaSigVerWorkSpace(Index, Value)            
#define Cry_30_LibCv_SetFips186WorkSpace(Index, Value)                
#define Cry_30_LibCv_SetHashRipemd160WorkSpace(Index, Value)          
#define Cry_30_LibCv_SetHashSha1WorkSpace(Index, Value)               
#define Cry_30_LibCv_SetHashSha256WorkSpace(Index, Value)             
#define Cry_30_LibCv_SetHmacSha1VerifyWorkSpace(Index, Value)         
#define Cry_30_LibCv_SetHmacSha256GenerateWorkSpace(Index, Value)     
#define Cry_30_LibCv_SetHmacSha256VerifyWorkSpace(Index, Value)       
#define Cry_30_LibCv_SetKdf2HmacSha1WorkSpace(Index, Value)           
#define Cry_30_LibCv_SetRsaDecryptWorkSpace(Index, Value)             
#define Cry_30_LibCv_SetRsaSha1SigVerWorkSpace(Index, Value)          
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCGetAddressOfDataMacros  Cry_30_LibCv Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Cry_30_LibCv_GetAddrAesDecrypt128WorkSpace(Index)             
#define Cry_30_LibCv_GetAddrAesEncrypt128WorkSpace(Index)             
#define Cry_30_LibCv_GetAddrCmacAes128GenWorkSpace(Index)             
#define Cry_30_LibCv_GetAddrCmacAes128VerWorkSpace(Index)             
#define Cry_30_LibCv_GetAddrEcdhWorkSpace(Index)                      
#define Cry_30_LibCv_GetAddrEcdsaSigGenWorkSpace(Index)               
#define Cry_30_LibCv_GetAddrEcdsaSigVerWorkSpace(Index)               
#define Cry_30_LibCv_GetAddrFips186WorkSpace(Index)                   
#define Cry_30_LibCv_GetAddrHashRipemd160WorkSpace(Index)             
#define Cry_30_LibCv_GetAddrHashSha1WorkSpace(Index)                  
#define Cry_30_LibCv_GetAddrHashSha256WorkSpace(Index)                
#define Cry_30_LibCv_GetAddrHmacSha1VerifyWorkSpace(Index)            
#define Cry_30_LibCv_GetAddrHmacSha256GenerateWorkSpace(Index)        
#define Cry_30_LibCv_GetAddrHmacSha256VerifyWorkSpace(Index)          
#define Cry_30_LibCv_GetAddrKdf2HmacSha1WorkSpace(Index)              
#define Cry_30_LibCv_GetAddrRsaDecryptWorkSpace(Index)                
#define Cry_30_LibCv_GetAddrRsaSha1SigVerWorkSpace(Index)             
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCDeclareStructPointerDataMacros  Cry_30_LibCv Declare Struct Pointer Data Macros (PRE_COMPILE)
  \brief  These macros can be used to declare a pointer to a structure.
  \{
*/ 
#define Cry_30_LibCv_DeclPtr2AesDecrypt128Config(Symbol)              
#define Cry_30_LibCv_DeclPtr2AesEncrypt128Config(Symbol)              
#define Cry_30_LibCv_DeclPtr2CmacAes128GenConfig(Symbol)              
#define Cry_30_LibCv_DeclPtr2CmacAes128VerConfig(Symbol)              
#define Cry_30_LibCv_DeclPtr2EcdhConfig(Symbol)                       
#define Cry_30_LibCv_DeclPtr2EcdsaSigGenConfig(Symbol)                
#define Cry_30_LibCv_DeclPtr2EcdsaSigVerConfig(Symbol)                
#define Cry_30_LibCv_DeclPtr2Fips186Config(Symbol)                    
#define Cry_30_LibCv_DeclPtr2HashRipemd160Config(Symbol)              
#define Cry_30_LibCv_DeclPtr2HashSha1Config(Symbol)                   
#define Cry_30_LibCv_DeclPtr2HashSha256Config(Symbol)                 
#define Cry_30_LibCv_DeclPtr2HmacSha1VerifyConfig(Symbol)             
#define Cry_30_LibCv_DeclPtr2HmacSha256GenerateConfig(Symbol)         
#define Cry_30_LibCv_DeclPtr2HmacSha256VerifyConfig(Symbol)           
#define Cry_30_LibCv_DeclPtr2Kdf2HmacSha1Config(Symbol)               
#define Cry_30_LibCv_DeclPtr2RsaDecryptConfig(Symbol)                 
#define Cry_30_LibCv_DeclPtr2RsaSha1SigVerConfig(Symbol)              
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCInstanciateStructPointerDataMacros  Cry_30_LibCv Instanciate Struct Pointer Data Macros (PRE_COMPILE)
  \brief  These macros can be used to declare and set a CONST pointer to a structure.
  \{
*/ 
#define Cry_30_LibCv_InstPtr2AesDecrypt128Config(Symbol, Index)       
#define Cry_30_LibCv_InstPtr2AesEncrypt128Config(Symbol, Index)       
#define Cry_30_LibCv_InstPtr2CmacAes128GenConfig(Symbol, Index)       
#define Cry_30_LibCv_InstPtr2CmacAes128VerConfig(Symbol, Index)       
#define Cry_30_LibCv_InstPtr2EcdhConfig(Symbol, Index)                
#define Cry_30_LibCv_InstPtr2EcdsaSigGenConfig(Symbol, Index)         
#define Cry_30_LibCv_InstPtr2EcdsaSigVerConfig(Symbol, Index)         
#define Cry_30_LibCv_InstPtr2Fips186Config(Symbol, Index)             
#define Cry_30_LibCv_InstPtr2HashRipemd160Config(Symbol, Index)       
#define Cry_30_LibCv_InstPtr2HashSha1Config(Symbol, Index)            
#define Cry_30_LibCv_InstPtr2HashSha256Config(Symbol, Index)          
#define Cry_30_LibCv_InstPtr2HmacSha1VerifyConfig(Symbol, Index)      
#define Cry_30_LibCv_InstPtr2HmacSha256GenerateConfig(Symbol, Index)  
#define Cry_30_LibCv_InstPtr2HmacSha256VerifyConfig(Symbol, Index)    
#define Cry_30_LibCv_InstPtr2Kdf2HmacSha1Config(Symbol, Index)        
#define Cry_30_LibCv_InstPtr2RsaDecryptConfig(Symbol, Index)          
#define Cry_30_LibCv_InstPtr2RsaSha1SigVerConfig(Symbol, Index)       
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCSetStructPointerDataMacros  Cry_30_LibCv Set Struct Pointer Data Macros (PRE_COMPILE)
  \brief  These macros can be used to set a pointer to a structure in an array.
  \{
*/ 
#define Cry_30_LibCv_SetPtr2AesDecrypt128Config(Symbol, Index)        
#define Cry_30_LibCv_SetPtr2AesEncrypt128Config(Symbol, Index)        
#define Cry_30_LibCv_SetPtr2CmacAes128GenConfig(Symbol, Index)        
#define Cry_30_LibCv_SetPtr2CmacAes128VerConfig(Symbol, Index)        
#define Cry_30_LibCv_SetPtr2EcdhConfig(Symbol, Index)                 
#define Cry_30_LibCv_SetPtr2EcdsaSigGenConfig(Symbol, Index)          
#define Cry_30_LibCv_SetPtr2EcdsaSigVerConfig(Symbol, Index)          
#define Cry_30_LibCv_SetPtr2Fips186Config(Symbol, Index)              
#define Cry_30_LibCv_SetPtr2HashRipemd160Config(Symbol, Index)        
#define Cry_30_LibCv_SetPtr2HashSha1Config(Symbol, Index)             
#define Cry_30_LibCv_SetPtr2HashSha256Config(Symbol, Index)           
#define Cry_30_LibCv_SetPtr2HmacSha1VerifyConfig(Symbol, Index)       
#define Cry_30_LibCv_SetPtr2HmacSha256GenerateConfig(Symbol, Index)   
#define Cry_30_LibCv_SetPtr2HmacSha256VerifyConfig(Symbol, Index)     
#define Cry_30_LibCv_SetPtr2Kdf2HmacSha1Config(Symbol, Index)         
#define Cry_30_LibCv_SetPtr2RsaDecryptConfig(Symbol, Index)           
#define Cry_30_LibCv_SetPtr2RsaSha1SigVerConfig(Symbol, Index)        
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCHasMacros  Cry_30_LibCv Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Cry_30_LibCv_HasAesDecrypt128Config()                         
#define Cry_30_LibCv_HasAesDecrypt128WorkSpaceIdxOfAesDecrypt128Config() 
#define Cry_30_LibCv_HasBlockModeOfAesDecrypt128Config()              
#define Cry_30_LibCv_HasDummyOfAesDecrypt128Config()                  
#define Cry_30_LibCv_HasPaddingModeOfAesDecrypt128Config()            
#define Cry_30_LibCv_HasAesDecrypt128WorkSpace()                      
#define Cry_30_LibCv_HasAesEncrypt128Config()                         
#define Cry_30_LibCv_HasAesEncrypt128WorkSpaceIdxOfAesEncrypt128Config() 
#define Cry_30_LibCv_HasBlockModeOfAesEncrypt128Config()              
#define Cry_30_LibCv_HasDummyOfAesEncrypt128Config()                  
#define Cry_30_LibCv_HasPaddingModeOfAesEncrypt128Config()            
#define Cry_30_LibCv_HasAesEncrypt128WorkSpace()                      
#define Cry_30_LibCv_HasCmacAes128GenConfig()                         
#define Cry_30_LibCv_HasCmacAes128GenWorkSpaceIdxOfCmacAes128GenConfig() 
#define Cry_30_LibCv_HasCmacAes128GenWorkSpace()                      
#define Cry_30_LibCv_HasCmacAes128VerConfig()                         
#define Cry_30_LibCv_HasCmacAes128VerWorkSpaceIdxOfCmacAes128VerConfig() 
#define Cry_30_LibCv_HasDummyOfCmacAes128VerConfig()                  
#define Cry_30_LibCv_HasLengthInBytesOfCmacAes128VerConfig()          
#define Cry_30_LibCv_HasCmacAes128VerWorkSpace()                      
#define Cry_30_LibCv_HasEcdhConfig()                                  
#define Cry_30_LibCv_HasDummyOfEcdhConfig()                           
#define Cry_30_LibCv_HasEcdhWorkSpaceIdxOfEcdhConfig()                
#define Cry_30_LibCv_HasPBKDF2IterationCountOfEcdhConfig()            
#define Cry_30_LibCv_HasEcdhWorkSpace()                               
#define Cry_30_LibCv_HasEcdsaSigGenConfig()                           
#define Cry_30_LibCv_HasBerEncodingOfEcdsaSigGenConfig()              
#define Cry_30_LibCv_HasDummyOfEcdsaSigGenConfig()                    
#define Cry_30_LibCv_HasEcdsaSigGenWorkSpaceIdxOfEcdsaSigGenConfig()  
#define Cry_30_LibCv_HasEcdsaSigGenWorkSpace()                        
#define Cry_30_LibCv_HasEcdsaSigVerConfig()                           
#define Cry_30_LibCv_HasBerEncodingOfEcdsaSigVerConfig()              
#define Cry_30_LibCv_HasDummyOfEcdsaSigVerConfig()                    
#define Cry_30_LibCv_HasEcdsaSigVerWorkSpaceIdxOfEcdsaSigVerConfig()  
#define Cry_30_LibCv_HasEcdsaSigVerWorkSpace()                        
#define Cry_30_LibCv_HasExpectedCompatibilityVersion()                
#define Cry_30_LibCv_HasFinalMagicNumber()                            
#define Cry_30_LibCv_HasFips186Config()                               
#define Cry_30_LibCv_HasDummyOfFips186Config()                        
#define Cry_30_LibCv_HasFips186WorkSpaceIdxOfFips186Config()          
#define Cry_30_LibCv_HasSaveStateOfFips186Config()                    
#define Cry_30_LibCv_HasFips186WorkSpace()                            
#define Cry_30_LibCv_HasGeneratorCompatibilityVersion()               
#define Cry_30_LibCv_HasHashRipemd160Config()                         
#define Cry_30_LibCv_HasHashRipemd160WorkSpaceIdxOfHashRipemd160Config() 
#define Cry_30_LibCv_HasHashRipemd160WorkSpace()                      
#define Cry_30_LibCv_HasHashSha1Config()                              
#define Cry_30_LibCv_HasHashSha1WorkSpaceIdxOfHashSha1Config()        
#define Cry_30_LibCv_HasHashSha1WorkSpace()                           
#define Cry_30_LibCv_HasHashSha256Config()                            
#define Cry_30_LibCv_HasHashSha256WorkSpaceIdxOfHashSha256Config()    
#define Cry_30_LibCv_HasHashSha256WorkSpace()                         
#define Cry_30_LibCv_HasHmacSha1VerifyConfig()                        
#define Cry_30_LibCv_HasDummyOfHmacSha1VerifyConfig()                 
#define Cry_30_LibCv_HasHmacSha1VerifyWorkSpaceIdxOfHmacSha1VerifyConfig() 
#define Cry_30_LibCv_HasLengthInBytesOfHmacSha1VerifyConfig()         
#define Cry_30_LibCv_HasHmacSha1VerifyWorkSpace()                     
#define Cry_30_LibCv_HasHmacSha256GenerateConfig()                    
#define Cry_30_LibCv_HasHmacSha256GenerateWorkSpaceIdxOfHmacSha256GenerateConfig() 
#define Cry_30_LibCv_HasHmacSha256GenerateWorkSpace()                 
#define Cry_30_LibCv_HasHmacSha256VerifyConfig()                      
#define Cry_30_LibCv_HasDummyOfHmacSha256VerifyConfig()               
#define Cry_30_LibCv_HasHmacSha256VerifyWorkSpaceIdxOfHmacSha256VerifyConfig() 
#define Cry_30_LibCv_HasLengthInBytesOfHmacSha256VerifyConfig()       
#define Cry_30_LibCv_HasHmacSha256VerifyWorkSpace()                   
#define Cry_30_LibCv_HasInitDataHashCode()                            
#define Cry_30_LibCv_HasKdf2HmacSha1Config()                          
#define Cry_30_LibCv_HasKdf2HmacSha1WorkSpaceIdxOfKdf2HmacSha1Config() 
#define Cry_30_LibCv_HasKdf2HmacSha1WorkSpace()                       
#define Cry_30_LibCv_HasRsaDecryptConfig()                            
#define Cry_30_LibCv_HasDummyOfRsaDecryptConfig()                     
#define Cry_30_LibCv_HasRsaDecryptWorkSpaceIdxOfRsaDecryptConfig()    
#define Cry_30_LibCv_HasUsePrivateKeyOfRsaDecryptConfig()             
#define Cry_30_LibCv_HasRsaDecryptWorkSpace()                         
#define Cry_30_LibCv_HasRsaSha1SigVerConfig()                         
#define Cry_30_LibCv_HasRsaSha1SigVerWorkSpaceIdxOfRsaSha1SigVerConfig() 
#define Cry_30_LibCv_HasRsaSha1SigVerWorkSpace()                      
#define Cry_30_LibCv_HasUseSyncJobProcessingOfGeneral()               (TRUE != FALSE)
#define Cry_30_LibCv_HasVersionInfoApiOfGeneral()                     (TRUE != FALSE)
#define Cry_30_LibCv_HasPCConfig()                                    (TRUE != FALSE)
#define Cry_30_LibCv_HasExpectedCompatibilityVersionOfPCConfig()      
#define Cry_30_LibCv_HasFinalMagicNumberOfPCConfig()                  
#define Cry_30_LibCv_HasGeneratorCompatibilityVersionOfPCConfig()     
#define Cry_30_LibCv_HasInitDataHashCodeOfPCConfig()                  
#define Cry_30_LibCv_HasUseSyncJobProcessingOfGeneralOfPCConfig()     (TRUE != FALSE)
#define Cry_30_LibCv_HasVersionInfoApiOfGeneralOfPCConfig()           (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCIncrementDataMacros  Cry_30_LibCv Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Cry_30_LibCv_IncAesDecrypt128WorkSpace(Index)                 
#define Cry_30_LibCv_IncAesEncrypt128WorkSpace(Index)                 
#define Cry_30_LibCv_IncCmacAes128GenWorkSpace(Index)                 
#define Cry_30_LibCv_IncCmacAes128VerWorkSpace(Index)                 
#define Cry_30_LibCv_IncEcdhWorkSpace(Index)                          
#define Cry_30_LibCv_IncEcdsaSigGenWorkSpace(Index)                   
#define Cry_30_LibCv_IncEcdsaSigVerWorkSpace(Index)                   
#define Cry_30_LibCv_IncFips186WorkSpace(Index)                       
#define Cry_30_LibCv_IncHashRipemd160WorkSpace(Index)                 
#define Cry_30_LibCv_IncHashSha1WorkSpace(Index)                      
#define Cry_30_LibCv_IncHashSha256WorkSpace(Index)                    
#define Cry_30_LibCv_IncHmacSha1VerifyWorkSpace(Index)                
#define Cry_30_LibCv_IncHmacSha256GenerateWorkSpace(Index)            
#define Cry_30_LibCv_IncHmacSha256VerifyWorkSpace(Index)              
#define Cry_30_LibCv_IncKdf2HmacSha1WorkSpace(Index)                  
#define Cry_30_LibCv_IncRsaDecryptWorkSpace(Index)                    
#define Cry_30_LibCv_IncRsaSha1SigVerWorkSpace(Index)                 
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCDecrementDataMacros  Cry_30_LibCv Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Cry_30_LibCv_DecAesDecrypt128WorkSpace(Index)                 
#define Cry_30_LibCv_DecAesEncrypt128WorkSpace(Index)                 
#define Cry_30_LibCv_DecCmacAes128GenWorkSpace(Index)                 
#define Cry_30_LibCv_DecCmacAes128VerWorkSpace(Index)                 
#define Cry_30_LibCv_DecEcdhWorkSpace(Index)                          
#define Cry_30_LibCv_DecEcdsaSigGenWorkSpace(Index)                   
#define Cry_30_LibCv_DecEcdsaSigVerWorkSpace(Index)                   
#define Cry_30_LibCv_DecFips186WorkSpace(Index)                       
#define Cry_30_LibCv_DecHashRipemd160WorkSpace(Index)                 
#define Cry_30_LibCv_DecHashSha1WorkSpace(Index)                      
#define Cry_30_LibCv_DecHashSha256WorkSpace(Index)                    
#define Cry_30_LibCv_DecHmacSha1VerifyWorkSpace(Index)                
#define Cry_30_LibCv_DecHmacSha256GenerateWorkSpace(Index)            
#define Cry_30_LibCv_DecHmacSha256VerifyWorkSpace(Index)              
#define Cry_30_LibCv_DecKdf2HmacSha1WorkSpace(Index)                  
#define Cry_30_LibCv_DecRsaDecryptWorkSpace(Index)                    
#define Cry_30_LibCv_DecRsaSha1SigVerWorkSpace(Index)                 
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Cry_30_LibCvPBGetRootDataMacros  Cry_30_LibCv Get Root Data Macros (POST_BUILD)
  \brief  These are used to get data pointers of root data.
  \{
*/ 
#define Cry_30_LibCv_GetLTConfigIdxOfPBConfig()                       
#define Cry_30_LibCv_GetPCConfigIdxOfPBConfig()                       
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPBHasMacros  Cry_30_LibCv Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Cry_30_LibCv_HasPBConfig()                                    
#define Cry_30_LibCv_HasLTConfigIdxOfPBConfig()                       
#define Cry_30_LibCv_HasPCConfigIdxOfPBConfig()                       
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

#if defined (CRY_30_LIBCV_FIPS186CONFIG)
# if ( CRY_30_LIBCV_FIPS186CONFIG == STD_ON )
/** FIPS-186 workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  /** Internal buffers */
  boolean seedInitialized;
  uint8 savedState[ESL_SIZEOF_RNGFIPS186_STATE];
  uint8 workSpace[sizeof(eslt_WorkSpaceFIPS186)];
} Cry_30_LibCv_Fips186WorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_HMACSHA1VERIFYCONFIG)
# if ( CRY_30_LIBCV_HMACSHA1VERIFYCONFIG == STD_ON )
/** HMAC SHA-1 workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceHMACSHA1)]; /*< Internal buffer */
} Cry_30_LibCv_HmacSha1VerifyWorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_AESDECRYPT128CONFIG)
# if ( CRY_30_LIBCV_AESDECRYPT128CONFIG == STD_ON )
/** AES-128 workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceAES128)]; /*< Internal buffer */
} Cry_30_LibCv_AesDecrypt128WorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_AESENCRYPT128CONFIG)
# if ( CRY_30_LIBCV_AESENCRYPT128CONFIG == STD_ON )
/** AES-128 workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceAES128)]; /*< Internal buffer */
} Cry_30_LibCv_AesEncrypt128WorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_RSADECRYPTCONFIG)
# if ( CRY_30_LIBCV_RSADECRYPTCONFIG == STD_ON )
/** RSA decrypt workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceRSAdec)]; /*< Internal buffer */
} Cry_30_LibCv_RsaDecryptWorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_RSASHA1SIGVERCONFIG)
# if ( CRY_30_LIBCV_RSASHA1SIGVERCONFIG == STD_ON )
/** RSA-SHA-1 workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceRSAver)]; /*< Internal buffer */
} Cry_30_LibCv_RsaSha1SigVerWorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_CMACAES128GENCONFIG)
# if ( CRY_30_LIBCV_CMACAES128GENCONFIG == STD_ON )
/** CMAC-AES-128 Generation workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceCMACAES)]; /*< Internal buffer */
} Cry_30_LibCv_CmacAes128GenWorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_CMACAES128VERCONFIG)
# if ( CRY_30_LIBCV_CMACAES128VERCONFIG == STD_ON )
/** CMAC-AES-128 Verification workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceCMACAES)]; /*< Internal buffer */
} Cry_30_LibCv_CmacAes128VerWorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_KDF2HMACSHA1CONFIG)
# if ( CRY_30_LIBCV_KDF2HMACSHA1CONFIG == STD_ON )
/** KDF2-HMAC-SHA-1 workspace buffer type */
typedef struct {
  uint32 alignmentDummy;
  /** Internal buffers */
  uint16 keyLength;
  uint8 key[ESL_SIZEOF_SHA1_DIGEST];
  uint8 workSpace[sizeof(eslt_WorkSpaceKDF2HMACSHA1)];
} Cry_30_LibCv_Kdf2HmacSha1WorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_HASHRIPEMD160CONFIG)
# if ( CRY_30_LIBCV_HASHRIPEMD160CONFIG == STD_ON )
/** HASH SHA-1 workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceRIPEMD160)]; /*< Internal buffer */
} Cry_30_LibCv_HashRipemd160WorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_HASHSHA1CONFIG)
# if ( CRY_30_LIBCV_HASHSHA1CONFIG == STD_ON )
/** HASH SHA-1 workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceSHA1)]; /*< Internal buffer */
} Cry_30_LibCv_HashSha1WorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_HASHSHA256CONFIG)
# if ( CRY_30_LIBCV_HASHSHA256CONFIG == STD_ON )
/** HASH SHA-256 workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceSHA256)]; /*< Internal buffer */
} Cry_30_LibCv_HashSha256WorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_HASHSHA512CONFIG)
# if ( CRY_30_LIBCV_HASHSHA512CONFIG == STD_ON )
/** HASH SHA-512 workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceSHA512)]; /*< Internal buffer */
} Cry_30_LibCv_HashSha512WorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_HMACSHA256GENERATECONFIG)
# if ( CRY_30_LIBCV_HMACSHA256GENERATECONFIG == STD_ON )
/** HMACSHA-256 Generate workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceSHA256)]; /*< Internal buffer */
} Cry_30_LibCv_HmacSha256GenerateWorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_HMACSHA256VERIFYCONFIG)
# if ( CRY_30_LIBCV_HMACSHA256VERIFYCONFIG == STD_ON )
/** HMACSHA-256 Verify workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint8 workSpace[sizeof(eslt_WorkSpaceSHA256)]; /*< Internal buffer */
} Cry_30_LibCv_HmacSha256VerifyWorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_ECDSASIGGENCONFIG)
# if ( CRY_30_LIBCV_ECDSASIGGENCONFIG == STD_ON )
/** ED25519-SIG-GEN workspace buffer type */
typedef struct{
  uint32 alignmentDummy;
  /** Internal buffers */
  uint32 dataLength;
  uint8 secretKey[32];
  const uint8* dataPtr;
  uint8 workSpace[sizeof(eslt_WorkSpaceEcP)];
} Cry_30_LibCv_EcdsaSigGenWorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_ECDSASIGVERCONFIG)
# if ( CRY_30_LIBCV_ECDSASIGVERCONFIG == STD_ON )
/** ED25519-SIG-VER workspace buffer type */
typedef struct{
  uint32 alignmentDummy;
  /** Internal buffers */
  uint32 dataLength;
  const uint8* pubKeyXPtr;
  const uint8* pubKeyYPtr;
  const uint8* dataPtr;
  uint8 workSpace[sizeof(eslt_WorkSpaceEcP)];
} Cry_30_LibCv_EcdsaSigVerWorkSpaceType;
# endif
#endif

#if defined (CRY_30_LIBCV_ECDHCONFIG)
# if ( CRY_30_LIBCV_ECDHCONFIG == STD_ON )
/** ECDH workspace buffer type */
typedef struct
{
  uint32 alignmentDummy;
  uint32 partnerPublicValueLength;
  uint32 privateValueLength;
  P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) partnerPublicValuePtr;
  uint8 privateValue[64];
  uint8 workSpace[sizeof(eslt_WorkSpaceEcP)]; /*< Internal buffer */
} Cry_30_LibCv_EcdhWorkSpaceType;
# endif
#endif




/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Cry_30_LibCvPCIterableTypes  Cry_30_LibCv Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCValueTypes  Cry_30_LibCv Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Cry_30_LibCv_UseSyncJobProcessingOfGeneral */
typedef boolean Cry_30_LibCv_UseSyncJobProcessingOfGeneralType;

/**   \brief  value based type definition for Cry_30_LibCv_VersionInfoApiOfGeneral */
typedef boolean Cry_30_LibCv_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Cry_30_LibCvPCStructTypes  Cry_30_LibCv Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCRootPointerTypes  Cry_30_LibCv Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point to arrays.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  Cry_30_LibCvPCRootValueTypes  Cry_30_LibCv Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Cry_30_LibCv_PCConfig */
typedef struct sCry_30_LibCv_PCConfigType
{
  uint8 Cry_30_LibCv_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Cry_30_LibCv_PCConfigType;

typedef Cry_30_LibCv_PCConfigType Cry_30_LibCv_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/* PRQA S 0779 POSTBUILDGLOBALDATATYPES */ /* MD_CSL_0779 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Cry_30_LibCvPBValueTypes  Cry_30_LibCv Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Cry_30_LibCvPBRootValueTypes  Cry_30_LibCv Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 


/* PRQA L:POSTBUILDGLOBALDATATYPES */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/




/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/








#endif /* CRY_30_LIBCV_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Cry_30_LibCv_Cfg.h
 *********************************************************************************************************************/

