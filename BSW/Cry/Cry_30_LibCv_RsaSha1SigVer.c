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
 *         File:  Cry_30_LibCv_RsaSha1SigVer.c
 *    Component:  SysService_AsrCry
 *       Module:  MICROSAR Cryptographic library module (CRY)
 *    Generator:  -
 *
 *  Description:  Implements the RSA-SHA-1 signature verification CRY API for the ASR CSM
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

#define CRY_RSASHA1SIGVER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Cry_30_LibCv.h"
#include "Cry_30_LibCv_Key_Types.h"
#include "Csm_Cbk.h"
#include "ESLib.h"

#if ( CRY_30_LIBCV_RSASHA1SIGVERCONFIG == STD_ON )
/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define CRY_RSASHA1SIGVER_USE_SYNC_JOB_PROCESSING     CRY_30_LIBCV_USE_SYNC_JOB_PROCESSING
#define CRY_RSASHA1SIGVER_KEYSIZE                     (128u)
#define CRY_RSASHA1SIGVER_WATCHDOG_PTR                (0u)

#if !defined (CRY_LOCAL)
# define CRY_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#if ( CRY_RSASHA1SIGVER_USE_SYNC_JOB_PROCESSING == STD_OFF )
typedef struct
{
  P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr;
  P2CONST( Csm_AsymPublicKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) keyPtr;
  P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) dataPtr;
  uint32 dataLength;
  P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) signaturePtr;
  uint32 signatureLength;
  P2VAR(Csm_VerifyResultType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) resultPtr;
} Cry_30_LibCv_RsaSha1SigVer_BufferType;
#endif /* ( CRY_RSASHA1SIGVER_USE_SYNC_JOB_PROCESSING == STD_OFF ) */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#if ( CRY_RSASHA1SIGVER_USE_SYNC_JOB_PROCESSING == STD_OFF )
# define CRY_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
CRY_LOCAL VAR(Cry_30_LibCv_RsaSha1SigVer_BufferType, CRY_30_LIBCV_VAR_NOINIT) Cry_30_LibCv_RsaSha1SigVer_Buffer; /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# define CRY_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define CRY_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
CRY_LOCAL VAR(uint8, CRY_30_LIBCV_VAR_NOINIT) Cry_30_LibCv_RsaSha1SigVer_Status; /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# define CRY_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define CRY_30_LIBCV_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaSha1SigVerStartInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                           P2CONST( Csm_AsymPublicKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) keyPtr);

CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaSha1SigVerUpdateInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                            P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) dataPtr,
                                                                                            uint32 dataLength);

CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaSha1SigVerFinishInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                            P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) signaturePtr,
                                                                                            uint32 signatureLength,
                                                                                            P2VAR( Csm_VerifyResultType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) resultPtr);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Cry_30_LibCv_RsaSha1SigVerStartInternal()
 **********************************************************************************************************************/
/*! \brief      Common service start function for synchronous and asynchronous behavior
 *  \see        Cry_30_LibCv_RsaSha1SigVerStart()
 **********************************************************************************************************************/
CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaSha1SigVerStartInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                           P2CONST( Csm_AsymPublicKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) keyPtr)
{
  Csm_ReturnType retVal = CSM_E_NOT_OK;

  P2CONST( Cry_30_LibCv_RsaSha1SigVerConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) contextPtr =
    (P2CONST( Cry_30_LibCv_RsaSha1SigVerConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))cfgPtr;

  /* PRQA S 0310 2 */ /* MD_CRY_11.4 */
  P2VAR( Cry_30_LibCv_RsaSha1SigVerWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) workSpacePtr =
    (P2VAR( Cry_30_LibCv_RsaSha1SigVerWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))Cry_30_LibCv_GetAddrRsaSha1SigVerWorkSpace(Cry_30_LibCv_GetRsaSha1SigVerWorkSpaceIdxOfRsaSha1SigVerConfig(contextPtr));

  /* Recast the key to the modulo exponent representation */
  P2CONST( Cry_30_LibCv_RsaKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) localKey =
    (P2CONST( Cry_30_LibCv_RsaKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))keyPtr; /* PRQA S 0310 */ /* MD_CRY_11.4 */

  /* Range check */
  if ( ( localKey->keyModuleLength <= CRY_RSASHA1SIGVER_KEYSIZE )
    && (localKey->keyModule != NULL_PTR ) 
    && (localKey->keyExponent != NULL_PTR ))
  {
    /* Init work space */
    if ( ESL_ERC_NO_ERROR == esl_initWorkSpaceHeader( (P2VAR( eslt_WorkSpaceHeader, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))workSpacePtr->workSpace, /* PRQA S 0310 */ /* MD_CRY_11.4 */
                                                      sizeof(eslt_WorkSpaceRSAver) - sizeof(eslt_WorkSpaceHeader),
                                                      CRY_RSASHA1SIGVER_WATCHDOG_PTR  ) )
    {
      /* Init RSA-SHA-1 signature verification */
      if ( ESL_ERC_NO_ERROR == esl_initVerifyRSASHA1_V15( (P2VAR( eslt_WorkSpaceRSAver, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))workSpacePtr->workSpace, /* PRQA S 0310 */ /* MD_CRY_11.4 */
                                                          (eslt_Length)localKey->keyModuleLength,
                                                          (P2CONST( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))localKey->keyModule,
                                                          (eslt_Length)localKey->keyExponentLength,
                                                          (P2CONST( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))localKey->keyExponent) )
      {
        retVal = CSM_E_OK;
      }
    }
  }

  return retVal;
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaSha1SigVerUpdateInternal()
 **********************************************************************************************************************/
/*! \brief      Common service update function for synchronous and asynchronous behavior
 *  \see        Cry_30_LibCv_RsaSha1SigVerUpdate()
 **********************************************************************************************************************/
CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaSha1SigVerUpdateInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                            P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) dataPtr,
                                                                                            uint32 dataLength)
{
  Csm_ReturnType retVal = CSM_E_NOT_OK;

  P2CONST( Cry_30_LibCv_RsaSha1SigVerConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) contextPtr =
    (P2CONST( Cry_30_LibCv_RsaSha1SigVerConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))cfgPtr;

  /* PRQA S 0310 2 */ /* MD_CRY_11.4 */
  P2VAR( Cry_30_LibCv_RsaSha1SigVerWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) workSpacePtr =
    (P2VAR( Cry_30_LibCv_RsaSha1SigVerWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))Cry_30_LibCv_GetAddrRsaSha1SigVerWorkSpace(Cry_30_LibCv_GetRsaSha1SigVerWorkSpaceIdxOfRsaSha1SigVerConfig(contextPtr));

  /* Range check */
  if (  dataLength <= 0xFFFFu )
  {
    /* Update RSA signature verification */
    if ( ESL_ERC_NO_ERROR == esl_updateVerifyRSASHA1_V15( (P2VAR( eslt_WorkSpaceRSAver, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))workSpacePtr->workSpace, /* PRQA S 0310 */ /* MD_CRY_11.4 */
                                                          (eslt_Length)dataLength,
                                                          (P2CONST( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))dataPtr ) )
    {
      retVal = CSM_E_OK;
    }
  }

  return retVal;
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaSha1SigVerFinishInternal()
 **********************************************************************************************************************/
/*! \brief      Common service update function for synchronous and asynchronous behavior
 *  \see        Cry_30_LibCv_RsaSha1SigVerFinish()
 **********************************************************************************************************************/
CRY_LOCAL FUNC(Csm_ReturnType, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaSha1SigVerFinishInternal( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                                            P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) signaturePtr,
                                                                                            uint32 signatureLength,
                                                                                            P2VAR( Csm_VerifyResultType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) resultPtr )
{
  Csm_ReturnType retVal = CSM_E_NOT_OK;
  Csm_VerifyResultType tempResult = CSM_E_VER_NOT_OK;

  P2CONST( Cry_30_LibCv_RsaSha1SigVerConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) contextPtr =
    (P2CONST( Cry_30_LibCv_RsaSha1SigVerConfigType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))cfgPtr;

  /* PRQA S 0310 2 */ /* MD_CRY_11.4 */
  P2VAR( Cry_30_LibCv_RsaSha1SigVerWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) workSpacePtr =
    (P2VAR( Cry_30_LibCv_RsaSha1SigVerWorkSpaceType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ))Cry_30_LibCv_GetAddrRsaSha1SigVerWorkSpace(Cry_30_LibCv_GetRsaSha1SigVerWorkSpaceIdxOfRsaSha1SigVerConfig(contextPtr));

  /* Range check */
  if ( ( signatureLength > 0u )
    && ( signatureLength <= 0xFFFFu ) )
  {

    /* Finish RSA signature verification */
    switch ( esl_finalizeVerifyRSASHA1_V15( (P2VAR( eslt_WorkSpaceRSAver, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))workSpacePtr->workSpace, /* PRQA S 0310 */ /* MD_CRY_11.4 */
                                            (eslt_Length)signatureLength,
                                            (P2CONST( eslt_Byte, AUTOMATIC, CRY_30_LIBCV_APPL_VAR))signaturePtr ) )
    {
      /* Verification succeed */
      case ESL_ERC_NO_ERROR:
      {
        tempResult = CSM_E_VER_OK;
        retVal = CSM_E_OK;
        break;
      }

      /* Verification failed */
      case ESL_ERC_RSA_SIGNATURE_INVALID:
      {
        retVal = CSM_E_OK;
        break;
      }

      /* Other (unmapped) error code */
      default:
      {
        break;
      }
    }
  }

  *resultPtr = tempResult;

  return retVal;
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaSha1SigVerDecrypt128Init()
 **********************************************************************************************************************/
/*! \brief      Initializes the RSA Signature Verification
 *  \context    System Startup
 *  \note       Called by application (BswM)
 **********************************************************************************************************************/
FUNC( void, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaSha1SigVerInit( void )
{
#if ( CRY_RSASHA1SIGVER_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Cry_30_LibCv_RsaSha1SigVer_Status = CRY_30_LIBCV_STATE_IDLE;
#endif
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaDecryptMainFunction()
 **********************************************************************************************************************/
/*! \brief      API to be called to process the requested services.
 *  \context    Function could be called from task level only
 *  \note       Scheduled by the CSM
**********************************************************************************************************************/
FUNC(void, CRY_30_LIBCV_CODE) Cry_30_LibCv_RsaSha1SigVerMainFunction( void )
{
#if ( CRY_RSASHA1SIGVER_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Csm_ReturnType retVal;

  switch(Cry_30_LibCv_RsaSha1SigVer_Status)
  {
    case CRY_30_LIBCV_STATE_START:
    {
      retVal=Cry_30_LibCv_RsaSha1SigVerStartInternal( Cry_30_LibCv_RsaSha1SigVer_Buffer.cfgPtr,
                                                      Cry_30_LibCv_RsaSha1SigVer_Buffer.keyPtr);

      Cry_30_LibCv_RsaSha1SigVer_Status = CRY_30_LIBCV_STATE_IDLE;

      Csm_SignatureVerifyCallbackNotification( retVal );
      break;
    }
    case CRY_30_LIBCV_STATE_UPDATE:
    {
      retVal=Cry_30_LibCv_RsaSha1SigVerUpdateInternal( Cry_30_LibCv_RsaSha1SigVer_Buffer.cfgPtr,
                                                       Cry_30_LibCv_RsaSha1SigVer_Buffer.dataPtr,
                                                       Cry_30_LibCv_RsaSha1SigVer_Buffer.dataLength);

      Cry_30_LibCv_RsaSha1SigVer_Status = CRY_30_LIBCV_STATE_IDLE;

      Csm_SignatureVerifyCallbackNotification( retVal );
      break;
    }
    case CRY_30_LIBCV_STATE_FINISH:
    {
      retVal=Cry_30_LibCv_RsaSha1SigVerFinishInternal( Cry_30_LibCv_RsaSha1SigVer_Buffer.cfgPtr,
                                                       Cry_30_LibCv_RsaSha1SigVer_Buffer.signaturePtr,
                                                       Cry_30_LibCv_RsaSha1SigVer_Buffer.signatureLength,
                                                       Cry_30_LibCv_RsaSha1SigVer_Buffer.resultPtr);

      Cry_30_LibCv_RsaSha1SigVer_Status = CRY_30_LIBCV_STATE_IDLE;

      Csm_SignatureVerifyCallbackNotification( retVal );
      Csm_SignatureVerifyServiceFinishNotification();
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
 * Cry_30_LibCv_RsaSha1SigVerStart()
**********************************************************************************************************************/
/*! \brief        This interface shall be used to initialize the signature verification.
 *  \param[in]    cfgPtr        Pointer to ConfigStructure
 *  \param[in]    keyPtr        Holds a pointer to the key necessary for the signature verification
 *                              operation.
 *  \return       CSM_E_OK      Request successful.
 *  \return       CSM_E_NOT_OK  Request failed.
 *  \context      Function could be called from task level only.
 *  \note         Called by application.
**********************************************************************************************************************/
FUNC( Csm_ReturnType, CRY_30_LIBCV_CODE ) Cry_30_LibCv_RsaSha1SigVerStart( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                           P2CONST( Csm_AsymPublicKeyType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) keyPtr)
{
#if ( CRY_RSASHA1SIGVER_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Cry_30_LibCv_RsaSha1SigVer_Buffer.cfgPtr = cfgPtr;
  Cry_30_LibCv_RsaSha1SigVer_Buffer.keyPtr = keyPtr;
  Cry_30_LibCv_RsaSha1SigVer_Status = CRY_30_LIBCV_STATE_START;
  return CSM_E_OK;
#else
  return Cry_30_LibCv_RsaSha1SigVerStartInternal(cfgPtr, keyPtr);
#endif
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaSha1SigVerUpdate()
**********************************************************************************************************************/
/*! \brief        This interface shall be used to feed the signature verification with the input data.
 *  \param[in]    cfgPtr        Pointer to ConfigStructure
 *  \param[in]    dataPtr       Holds a pointer to the signature which shall be verified.
 *  \param[in]    dataLength    Contains the length of the signature to verify in bytes.
 *  \return       CSM_E_OK      Request successful.
 *  \return       CSM_E_NOT_OK  Request failed.
 *  \pre          Service was started.
 *  \context      Function could be called from task level only.
 *  \note         Called by application.
**********************************************************************************************************************/
FUNC( Csm_ReturnType, CRY_30_LIBCV_CODE ) Cry_30_LibCv_RsaSha1SigVerUpdate( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                            P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) dataPtr,
                                                                            uint32 dataLength)
{
#if ( CRY_RSASHA1SIGVER_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Cry_30_LibCv_RsaSha1SigVer_Buffer.cfgPtr = cfgPtr;
  Cry_30_LibCv_RsaSha1SigVer_Buffer.dataPtr = dataPtr;
  Cry_30_LibCv_RsaSha1SigVer_Buffer.dataLength = dataLength;
  Cry_30_LibCv_RsaSha1SigVer_Status = CRY_30_LIBCV_STATE_UPDATE;
  return CSM_E_OK;
#else
  return Cry_30_LibCv_RsaSha1SigVerUpdateInternal(cfgPtr, dataPtr, dataLength);
#endif
}


/**********************************************************************************************************************
 * Cry_30_LibCv_RsaSha1SigVerFinish()
**********************************************************************************************************************/
/*! \brief        This interface shall be used to finish the signature verification.
 *  \param[in]    cfgPtr        Pointer to ConfigStructure
 *  \param[in]    signaturePtr       Holds a pointer to the memory location which holds the signature to be verified.
 *  \param[in]    signatureLength    Holds the length of the signature to be verified.
 *  \param[out]   resultPtr Holds a pointer to the memory location which will hold the result of the signature verification.
 *  \return       CSM_E_OK      Request successful.
 *  \return       CSM_E_NOT_OK  Request failed.
 *  \pre          Service was started.
 *  \context      Function could be called from task level only.
 *  \note         Called by application.
**********************************************************************************************************************/
FUNC( Csm_ReturnType, CRY_30_LIBCV_CODE ) Cry_30_LibCv_RsaSha1SigVerFinish( P2CONST( void, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) cfgPtr,
                                                                            P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) signaturePtr,
                                                                            uint32 signatureLength,
                                                                            P2VAR( Csm_VerifyResultType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR) resultPtr)
{
#if ( CRY_RSASHA1SIGVER_USE_SYNC_JOB_PROCESSING == STD_OFF )
  Cry_30_LibCv_RsaSha1SigVer_Buffer.cfgPtr = cfgPtr;
  Cry_30_LibCv_RsaSha1SigVer_Buffer.signaturePtr = signaturePtr;
  Cry_30_LibCv_RsaSha1SigVer_Buffer.signatureLength = signatureLength;
  Cry_30_LibCv_RsaSha1SigVer_Buffer.resultPtr = resultPtr;
  Cry_30_LibCv_RsaSha1SigVer_Status = CRY_30_LIBCV_STATE_FINISH;
  return CSM_E_OK;
#else
  return Cry_30_LibCv_RsaSha1SigVerFinishInternal(cfgPtr, signaturePtr, signatureLength,  resultPtr);
#endif
}

#define CRY_30_LIBCV_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* ( CRY_30_LIBCV_RSASHA1SIGVERCONFIG == STD_ON ) */
/**********************************************************************************************************************
 * Module specific MISRA deviations
 *********************************************************************************************************************/
/* module specific MISRA deviations:

   MD_CRY_11.4:
     Reason:     Cast needed to use crypto lib as a Csm service.
     Risk:       Invalid memory access.
     Prevention: Covered by code review and test.

 */

/**********************************************************************************************************************
 *  END OF FILE: CRY_RSASHA1SIGVER.C
 *********************************************************************************************************************/
