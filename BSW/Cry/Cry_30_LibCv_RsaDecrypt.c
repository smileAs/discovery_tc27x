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
 *         File:  Cry_30_LibCv_RsaDecrypt.c
 *    Component:  SysService_AsrCry
 *       Module:  MICROSAR Cryptographic library module (CRY)
 *    Generator:  -
 *
 *  Description:  Implements the RSA decrypt CRY API for the ASR CSM
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

#define CRY_30_LIBCV_RSADECRYPT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Cry_30_LibCv.h"
#include "Cry_30_LibCv_Key_Types.h"
#include "Csm_Cbk.h"
#include "ESLib.h"


#if ( CRY_30_LIBCV_RSADECRYPTCONFIG == STD_ON )
/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define CRY_RSADECRYPT_USE_SYNC_JOB_PROCESSING     CRY_30_LIBCV_USE_SYNC_JOB_PROCESSING
#define CRY_RSADECRYPT_WATCHDOG_PTR                (0u)

#if !defined (CRY_LOCAL)
# define CRY_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#if ( CRY_RSADECRYPT_USE_SYNC_JOB_PROCESSING == STD_OFF )
typedef struct
{
  P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr;
  P2CONST( Csm_AsymPrivateKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) keyPtr;
  P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cipherTextPtr;
  uint32 cipherTextLength;
  P2VAR( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextPtr;
  P2VAR( uint32, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextLengthPtr;
} Cry_30_LibCv_RsaDecrypt_BufferType;
#endif /* ( CRY_RSADECRYPT_USE_SYNC_JOB_PROCESSING == STD_OFF ) */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#if ( CRY_RSADECRYPT_USE_SYNC_JOB_PROCESSING == STD_OFF )
# define CRY_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
CRY_LOCAL VAR(Cry_30_LibCv_RsaDecrypt_BufferType, CRY_30_LIBCV_VAR_NOINIT) Cry_30_LibCv_RsaDecrypt_Buffer; /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# define CRY_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define CRY_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
CRY_LOCAL VAR(uint8, CRY_30_LIBCV_VAR_NOINIT) Cry_30_LibCv_RsaDecrypt_Status; /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# define CRY_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define CRY_30_LIBCV_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaDecryptStartInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                        P2CONST( Csm_AsymPrivateKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) keyPtr);

CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaDecryptUpdateInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                         P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cipherTextPtr,
                                                                                         uint32 cipherTextLength,
                                                                                         P2VAR( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextPtr,
                                                                                         P2VAR( uint32, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextLengthPtr);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaDecryptStartInternal()
 **********************************************************************************************************************/
/*! \brief      Common service start function for synchronous and asynchronous behavior
 *  \see        Cry_30_LibCv_RsaDecryptStart()
 **********************************************************************************************************************/
CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaDecryptStartInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                        P2CONST( Csm_AsymPrivateKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) keyPtr)
{
  Csm_ReturnType retVal = CSM_E_NOT_OK;

  P2CONST( Cry_30_LibCv_RsaDecryptConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) contextPtr =
    (P2CONST( Cry_30_LibCv_RsaDecryptConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))cfgPtr;

  /* PRQA S 0310 2 */ /* MD_CRY_11.4 */
  P2VAR( Cry_30_LibCv_RsaDecryptWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) workSpacePtr =
    (P2VAR( Cry_30_LibCv_RsaDecryptWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))Cry_30_LibCv_GetAddrRsaDecryptWorkSpace(Cry_30_LibCv_GetRsaDecryptWorkSpaceIdxOfRsaDecryptConfig(contextPtr));

  /* Recast the key to the modulo exponent representation */
  P2CONST( Cry_30_LibCv_RsaKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) localKey =
    (P2CONST( Cry_30_LibCv_RsaKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))keyPtr; /* PRQA S 0310 */ /* MD_CRY_11.4 */

  /* Check key size and check for NULL_PTR */
  if ( (localKey->keyModuleLength <= ESL_RSA_KEYSIZE)
    && (localKey->keyModule != NULL_PTR )
    && (localKey->keyExponent != NULL_PTR ) )
  {
    /* Init work space */
    if ( ESL_ERC_NO_ERROR == esl_initWorkSpaceHeader( (P2VAR( eslt_WorkSpaceHeader, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))workSpacePtr->workSpace, /* PRQA S 0310 */ /* MD_CRY_11.4 */
                                                      sizeof(eslt_WorkSpaceRSAdec) - sizeof(eslt_WorkSpaceHeader),
                                                      CRY_RSADECRYPT_WATCHDOG_PTR ) )
    {

      /* Init RSA Decrypt */
      if ( ESL_ERC_NO_ERROR == esl_initDecryptRSA_V15( (P2VAR( eslt_WorkSpaceRSAdec, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))workSpacePtr->workSpace, /* PRQA S 0310 */ /* MD_CRY_11.4 */
                                                       (eslt_Length)localKey->keyModuleLength,
                                                       (P2CONST( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))localKey->keyModule,
                                                       (eslt_Length)localKey->keyExponentLength,
                                                       (P2CONST( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))localKey->keyExponent ) )
      {
        retVal = CSM_E_OK;
      }
    }
  }

  return retVal;
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaDecryptUpdateInternal()
 **********************************************************************************************************************/
/*! \brief      Common service update function for synchronous and asynchronous behavior
 *  \see        Cry_30_LibCv_RsaDecryptUpdate()
 **********************************************************************************************************************/
CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaDecryptUpdateInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                         P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cipherTextPtr,
                                                                                         uint32 cipherTextLength,
                                                                                         P2VAR( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextPtr,
                                                                                         P2VAR( uint32, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextLengthPtr )
{
  Csm_ReturnType retVal = CSM_E_NOT_OK;
  eslt_Length plainTextLength;

  P2CONST( Cry_30_LibCv_RsaDecryptConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) contextPtr =
    (P2CONST( Cry_30_LibCv_RsaDecryptConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))cfgPtr;

  /* PRQA S 0310 2 */ /* MD_CRY_11.4 */
  P2VAR( Cry_30_LibCv_RsaDecryptWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) workSpacePtr =
    (P2VAR( Cry_30_LibCv_RsaDecryptWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))Cry_30_LibCv_GetAddrRsaDecryptWorkSpace(Cry_30_LibCv_GetRsaDecryptWorkSpaceIdxOfRsaDecryptConfig(contextPtr));

  /* Range check */
  if ( ( *plainTextLengthPtr <= 0xFFFFu )
    && ( cipherTextLength <= 0xFFFFu ) )
  {
    plainTextLength = (eslt_Length)(*plainTextLengthPtr & 0xFFFFu);

    /* Update RSA calculation */
    if (Cry_30_LibCv_IsUsePrivateKeyOfRsaDecryptConfig(contextPtr) )
    {
      if ( ESL_ERC_NO_ERROR == esl_decryptPrivRSA_V15( (P2VAR( eslt_WorkSpaceRSAdec, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))workSpacePtr->workSpace, /* PRQA S 0310 */ /* MD_CRY_11.4 */
                                                       (eslt_Length)cipherTextLength,
                                                       (P2CONST( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))cipherTextPtr,
                                                       &plainTextLength,
                                                       (P2VAR( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))plainTextPtr ) )
      {
        *plainTextLengthPtr = plainTextLength;
        retVal = CSM_E_OK;
      }
    }
    else
    {
      if ( ESL_ERC_NO_ERROR == esl_decryptPubRSA_V15( (P2VAR( eslt_WorkSpaceRSAdec, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))workSpacePtr->workSpace, /* PRQA S 0310 */ /* MD_CRY_11.4 */
                                                      (eslt_Length)cipherTextLength,
                                                      (P2CONST( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))cipherTextPtr,
                                                      &plainTextLength,
                                                      (P2VAR( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))plainTextPtr ) )
      {
        *plainTextLengthPtr = plainTextLength;
        retVal = CSM_E_OK;
      }
    }
  }

  return retVal;
}




/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Cry_30_LibCv_RsaDecryptDecrypt128Init()
 **********************************************************************************************************************/
/*! \brief      Initializes the RSA  decryption
 *  \context    System Startup
 *  \note       Called by application (BswM)
 **********************************************************************************************************************/
FUNC( void, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaDecryptInit( void )
{
#if ( CRY_RSADECRYPT_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Cry_30_LibCv_RsaDecrypt_Status = CRY_30_LIBCV_STATE_IDLE;
#endif
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaDecryptMainFunction()
 **********************************************************************************************************************/
/*! \brief      API to be called to process the requested services.
 *  \context    Function could be called from task level only
 *  \note       Scheduled by the CSM
**********************************************************************************************************************/
FUNC(void, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaDecryptMainFunction( void )
{
#if ( CRY_RSADECRYPT_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Csm_ReturnType retVal;

  switch(Cry_30_LibCv_RsaDecrypt_Status)
  {
    case CRY_30_LIBCV_STATE_START:
    {
      retVal = Cry_30_LibCv_RsaDecryptStartInternal( Cry_30_LibCv_RsaDecrypt_Buffer.cfgPtr,
                                                     Cry_30_LibCv_RsaDecrypt_Buffer.keyPtr);

      Cry_30_LibCv_RsaDecrypt_Status = CRY_30_LIBCV_STATE_IDLE;

      Csm_AsymDecryptCallbackNotification( retVal );
      break;
    }
    case CRY_30_LIBCV_STATE_UPDATE:
    {
      retVal = Cry_30_LibCv_RsaDecryptUpdateInternal( Cry_30_LibCv_RsaDecrypt_Buffer.cfgPtr,
                                                      Cry_30_LibCv_RsaDecrypt_Buffer.cipherTextPtr,
                                                      Cry_30_LibCv_RsaDecrypt_Buffer.cipherTextLength,
                                                      Cry_30_LibCv_RsaDecrypt_Buffer.plainTextPtr,
                                                      Cry_30_LibCv_RsaDecrypt_Buffer.plainTextLengthPtr);

      Cry_30_LibCv_RsaDecrypt_Status = CRY_30_LIBCV_STATE_IDLE;

      Csm_AsymDecryptCallbackNotification( retVal );
      break;
    }
    case CRY_30_LIBCV_STATE_FINISH:
    {
      retVal = CSM_E_OK;

      Cry_30_LibCv_RsaDecrypt_Status = CRY_30_LIBCV_STATE_IDLE;

      Csm_AsymDecryptCallbackNotification( retVal );
      Csm_AsymDecryptServiceFinishNotification();
      break;
    }
    default:
    {
      /* Nothing to do */
      break;
    }
  }
#endif
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaDecryptStart()
**********************************************************************************************************************/
/*! \brief        This interface shall be used to initialize the asymmetrical decryption.
 *  \param[in]    cfgPtr        Pointer to ConfigStructure
 *  \param[in]    keyPtr        Holds a pointer to the key which has to be used during the asymmetrical decryption
 *                              operation.
 *  \return       CSM_E_OK      Request successful.
 *  \return       CSM_E_NOT_OK  Request failed.
 *  \context      Function could be called from task level only.
 *  \note         Called by application.
**********************************************************************************************************************/
FUNC( Csm_ReturnType, CRY_30_LIBCV_CODE ) Cry_30_LibCv_RsaDecryptStart( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                        P2CONST( Csm_AsymPrivateKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) keyPtr )
{
#if ( CRY_RSADECRYPT_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Cry_30_LibCv_RsaDecrypt_Buffer.cfgPtr = cfgPtr;
  Cry_30_LibCv_RsaDecrypt_Buffer.keyPtr = keyPtr;
  Cry_30_LibCv_RsaDecrypt_Status = CRY_30_LIBCV_STATE_START;
  return CSM_E_OK;
#else
  return Cry_30_LibCv_RsaDecryptStartInternal(cfgPtr, keyPtr);
#endif
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaDecryptUpdate()
**********************************************************************************************************************/
/*! \brief        This interface shall be used to feed the asymmetrical decryption with the input data.
 *  \param[in]    cfgPtr        Pointer to ConfigStructure
 *  \param[in]    cipherTextPtr Holds a pointer to the encrypted data.
 *  \param[in]    cipherTextLength Contains the length of the encrypted data in bytes.
 *  \param[out]   plainTextPtr  Holds a pointer to the memory location which will hold the decrypted text.
 *  \param[in,out] plainTextLengthPtr Holds a pointer to a memory location in which the length information is stored. 
                                On calling this function this parameter shall contain the size of the buffer provided by plainTextPtr. 
                                When the request has finished, the amount of data that has been decrypted shall be stored.
 *  \return       CSM_E_OK      Request successful.
 *  \return       CSM_E_NOT_OK  Request failed.
 *  \pre          Service was started.
 *  \context      Function could be called from task level only.
 *  \note         Called by application.
**********************************************************************************************************************/
FUNC( Csm_ReturnType, CRY_30_LIBCV_CODE ) Cry_30_LibCv_RsaDecryptUpdate( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                         P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cipherTextPtr,
                                                                         uint32 cipherTextLength,
                                                                         P2VAR( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextPtr,
                                                                         P2VAR( uint32, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextLengthPtr )
{
#if ( CRY_RSADECRYPT_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Cry_30_LibCv_RsaDecrypt_Buffer.cfgPtr = cfgPtr;
  Cry_30_LibCv_RsaDecrypt_Buffer.cipherTextPtr = cipherTextPtr;
  Cry_30_LibCv_RsaDecrypt_Buffer.cipherTextLength = cipherTextLength;
  Cry_30_LibCv_RsaDecrypt_Buffer.plainTextPtr = plainTextPtr;
  Cry_30_LibCv_RsaDecrypt_Buffer.plainTextLengthPtr = plainTextLengthPtr;
  Cry_30_LibCv_RsaDecrypt_Status = CRY_30_LIBCV_STATE_UPDATE;
  return CSM_E_OK;
#else
  return Cry_30_LibCv_RsaDecryptUpdateInternal(cfgPtr, cipherTextPtr, cipherTextLength, plainTextPtr, plainTextLengthPtr);
#endif
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaDecryptFinish()
**********************************************************************************************************************/
/*! \brief        This interface shall be used to finish the asymmetrical decryption.
 *  \param[in]    cfgPtr        Pointer to ConfigStructure
 *  \param[out]   plainTextPtr  Holds a pointer to the memory location which will hold the decrypted text.
 *  \param[in,out] plainTextLengthPtr Holds a pointer to a memory location in which the length information is stored. 
 *                              On calling this function this parameter shall contain the size of the buffer 
 *                              provided by plainTextPtr. When the request has finished, 
 *                              the amount of data that has been decrypted shall be stored.
 *  \return       CSM_E_OK      Request successful.
 *  \pre          Service was started.
 *  \context      Function could be called from task level only.
 *  \note         Called by application.
**********************************************************************************************************************/
FUNC( Csm_ReturnType, CRY_30_LIBCV_CODE ) Cry_30_LibCv_RsaDecryptFinish( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                         P2VAR( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextPtr,         /* PRQA S 3673 */ /* MD_MSR_16.7 */
                                                                         P2VAR( uint32, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) plainTextLengthPtr ) /* PRQA S 3673 */ /* MD_MSR_16.7 */
{
  CRY_30_LIBCV_DUMMY_STATEMENT(cfgPtr);             /* PRQA S 3112 */ /* MD_CRY_14.2 */
  CRY_30_LIBCV_DUMMY_STATEMENT(plainTextPtr);       /* PRQA S 3112 */ /* MD_CRY_14.2 */
  CRY_30_LIBCV_DUMMY_STATEMENT(plainTextLengthPtr); /* PRQA S 3112 */ /* MD_CRY_14.2 */

#if ( CRY_RSADECRYPT_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Cry_30_LibCv_RsaDecrypt_Status = CRY_30_LIBCV_STATE_FINISH;
  return CSM_E_OK;
#else
  return CSM_E_OK;
#endif
}


#define CRY_30_LIBCV_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* ( CRY_30_LIBCV_RSADECRYPTCONFIG == STD_ON ) */
/**********************************************************************************************************************
 * Module specific MISRA deviations
 *********************************************************************************************************************/
/* module specific MISRA deviations:

   MD_CRY_11.4:
     Reason:     Cast needed to use crypto lib as a Csm service.
     Risk:       Invalid memory access.
     Prevention: Covered by code review and test.

   MD_CRY_16.7:
     Reason:     Pointer in the finish-method is unused.
     Risk:       none.
     Prevention: Covered by code review and test.

 */

/**********************************************************************************************************************
 *  END OF FILE: CRY_30_LIBCV_RSADECRYPT.C
 *********************************************************************************************************************/
