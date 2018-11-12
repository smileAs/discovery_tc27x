/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Cry_30_LibCv_RsaDecrypt.h
 *    Component:  SysService_AsrCry
 *       Module:  MICROSAR Cryptographic library module (CRY)
 *    Generator:  -
 *
 *  Description:  This header file implements the RSADecrypt CRY API for the ASR CSM
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#if !defined (CRY_30_LIBCV_RSADECRYPT_H)
#define CRY_30_LIBCV_RSADECRYPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Csm_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define CRY_30_LIBCV_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern FUNC( void, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaDecryptInit( void );
extern FUNC( void, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaDecryptMainFunction( void );

extern FUNC( Csm_ReturnType, CRY_30_LIBCV_CODE ) Cry_30_LibCv_RsaDecryptStart( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                               P2CONST( Csm_AsymPrivateKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) keyPtr);

extern FUNC( Csm_ReturnType, CRY_30_LIBCV_CODE ) Cry_30_LibCv_RsaDecryptUpdate( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cipherTextPtr,
                                                                                uint32 cipherTextLength,
                                                                                P2VAR( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextPtr,
                                                                                P2VAR( uint32, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextLengthPtr );

extern FUNC( Csm_ReturnType, CRY_30_LIBCV_CODE ) Cry_30_LibCv_RsaDecryptFinish( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                P2VAR( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextPtr,
                                                                                P2VAR( uint32, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextLengthPtr );

#define CRY_30_LIBCV_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif  /* CRY_30_LIBCV_RSADECRYPT8_H */
/**********************************************************************************************************************
 *  END OF FILE: CRY_30_LIBCV_RSADECRYPT.H
 *********************************************************************************************************************/
