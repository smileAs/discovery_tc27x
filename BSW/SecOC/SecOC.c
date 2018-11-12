/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SecOC.c
 *        \brief  MICROSAR  Secure Onboard Communication source file
 *
 *      \details  This is the implementation of the MICROSAR Secure Onboard Communication module.
 *                The basic software module is based on the AUTOSAR Communication specification.
 *
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

#define SECOC_SOURCE
/**********************************************************************************************************************
 *  LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* PRQA S 3453 EOF */ /* MD_MSR_19.7 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */
/* PRQA S 0857, 0639 EOF */ /* MD_MSR_1.1_857, MD_MSR_1.1_639 */
/* PRQA S 3355, 3356, 3358, 3359 EOF */ /* MD_CSL_3355_3356_3358_3359  */
/* *INDENT-ON* */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SecOC_Cbk.h"
#include "SecOC.h"
#include "SchM_SecOC.h"
#include "vstdlib.h"
#if ((SECOC_EXISTS_CAL_CRYPTOSERVICEOFRXPDUINFO == STD_ON ) || (SECOC_EXISTS_CAL_CRYPTOSERVICEOFTXPDUINFO == STD_ON))
# include "Cal.h"
#endif
#if ((SECOC_EXISTS_CSM_CRYPTOSERVICEOFRXPDUINFO == STD_ON ) || (SECOC_EXISTS_CSM_CRYPTOSERVICEOFTXPDUINFO == STD_ON))
# include "Csm.h"
#endif
#include "Rte_SecOC.h"
#if (SECOC_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
#include "PduR_SecOC.h"
#if(SECOC_USE_INIT_POINTER == STD_ON)
# include "EcuM_Error.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
#if (SECOC_DEV_ERROR_DETECT == STD_ON)
# define SecOC_ReportDetError(API_ID, ERROR_CODE) ((void) Det_ReportError(SECOC_MODULE_ID, SECOC_INSTANCE_ID_DET, (API_ID), (ERROR_CODE)))
#endif
#if (SECOC_RXPDUINFO == STD_ON)
# define SecOC_IsRxPduStateUnverified(rxPduId) ((SecOC_GetRxPduState(rxPduId) & SECOC_UNVERIFIED_RXPDUSTATE) == SECOC_UNVERIFIED_RXPDUSTATE)
#endif
#if (SECOC_TXPDUINFO == STD_ON)
# define SecOC_IsTxPduStateUnauthenticated(txPduId) ((SecOC_GetTxPduState(txPduId) & SECOC_UNAUTHENTICATED_TXPDUSTATE) == SECOC_UNAUTHENTICATED_TXPDUSTATE)
#endif
/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef enum
{
  SECOC_E_VER_OK = 0,           /* !< Verified */
  SECOC_E_VER_NOT_OK = 1,       /* !< not Verified */
  SECOC_E_VER_BUSY = 2  /* !< CSM or CAL is busy */
} SecOC_VerifyResultType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
#if(SECOC_USE_INIT_POINTER == STD_ON)
# define SECOC_START_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*! \brief Pointer to the current configuration */
P2CONST(SecOC_ConfigType, SECOC_VAR_ZERO_INIT, SECOC_PBCFG) SecOC_ConfigDataPtr = NULL_PTR;
# define SECOC_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define SECOC_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_19.1 */

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetVerifyValue
**********************************************************************************************************************/
/*! \brief      Calculates the expected Freshness Value.
    \details    -
    \param[in]  rxPduId  rx PduId
    \param[in]  parsedFreshnessValue parsed Freshness Value of the received Pdu.
    \return     calculated FreshnessVerifyValue
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetVerifyValue(SecOC_RxPduInfoIterType rxPduId, SecOC_FreshnessValueType parsedFreshnessValue);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetVerifyValueFromCallout
**********************************************************************************************************************/
/*! \brief      Gets the freshness verify value form the configured callout.
    \details    -
    \param[in]  rxPduId  rx PduId
    \param[out] freshnessValue       freshness verify value
    \return     E_OK request successful
                E_NOT_OK request failed
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValue_GetVerifyValueFromCallout(SecOC_RxPduInfoIterType rxPduId, uint8 * freshnessValue);
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_RxIf_InitPdus
**********************************************************************************************************************/
/*! \brief      Init IF rx PDUs.
    \details    -
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_RxIf_InitPdus(void);
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_TxIf_InitPdus
**********************************************************************************************************************/
/*! \brief      Init IF tx PDUs.
    \details    -
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_TxIf_InitPdus(void);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetMostSignificantBitsOfRxFreshnessValue
**********************************************************************************************************************/
/*! \brief      Returns the most significant bits of a Rx Freshness Value.
    \details  -
    \param[in]  rxPduId  rx PduId
    \return     the most significant bits of a Rx Freshness Value.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetMostSignificantBitsOfRxFreshnessValue(SecOC_RxPduInfoIterType rxPduId);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetLeastSignificantBitsOfRxFreshnessValue
**********************************************************************************************************************/
/*! \brief      Returns the least significant bits of a Rx Freshness Value.
    \details  -
    \param[in]  rxPduId  rx PduId
    \return     the least significant bits of a Rx Freshness Value.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetLeastSignificantBitsOfRxFreshnessValue(SecOC_RxPduInfoIterType rxPduId);
#endif

#if (SECOC_EXISTS_CAL_CRYPTOSERVICEOFRXPDUINFO == STD_ON )
/**********************************************************************************************************************
  SecOC_Verify_MACUsingCAL
**********************************************************************************************************************/
/*! \brief      Verifies the MAC of a Secured I-Pdu using the CAL.
    \details  -
    \param[in]  rxPduId  rx PduId
    \return     verification result.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_VerifyResultType, SECOC_CODE) SecOC_Verify_MACUsingCAL(SecOC_RxPduInfoIterType rxPduId);
#endif

#if (SECOC_EXISTS_CSM_CRYPTOSERVICEOFRXPDUINFO == STD_ON )
/**********************************************************************************************************************
  SecOC_Verify_MACUsingCSM
**********************************************************************************************************************/
/*! \brief      Verifies the MAC of a Secured I-Pdu using the CSM.
    \details  -
    \param[in]  rxPduId  rx PduId
    \return     verification result.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_VerifyResultType, SECOC_CODE) SecOC_Verify_MACUsingCSM(SecOC_RxPduInfoIterType rxPduId);
#endif

#if (SECOC_EXISTS_CSM_43_CRYPTOSERVICEOFRXPDUINFO == STD_ON )
/**********************************************************************************************************************
  SecOC_Verify_MACUsingCSM43
**********************************************************************************************************************/
/*! \brief      Verifies the MAC of a Secured I-Pdu using the CSM.
    \details  -
    \param[in]  rxPduId  rx PduId
    \return     verification result.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_VerifyResultType, SECOC_CODE) SecOC_Verify_MACUsingCSM43(SecOC_RxPduInfoIterType rxPduId);
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_GetByteAlignedTruncatedAuthenticator
**********************************************************************************************************************/
/*! \brief      Reads the Authenticator for the Secured PDU byte aligned.
    \details  -
    \param[in]  rxPduId  rx PduId
    \param[out]  byteAlignedAuthenticator  byte aligned authenticator
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Verify_GetByteAlignedTruncatedAuthenticator(SecOC_RxPduInfoIterType rxPduId, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) byteAlignedAuthenticator);
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_GetVerificationResultOfOverrideStatus
**********************************************************************************************************************/
/*! \brief      Translates the verify override status in a verification result.
    \details  -
    \param[in]  rxPduId  rx PduId
    \return     verification result.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_VerifyResultType, SECOC_CODE) SecOC_Verify_GetVerificationResultOfOverrideStatus(SecOC_RxPduInfoIterType rxPduId);
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_ProcessVerificationResult
**********************************************************************************************************************/
/*! \brief      Processes the passed verification result.
    \details  -
    \param[in]  verificationResult verification result.
    \param[in]  rxPduId  rx PduId
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Verify_ProcessVerificationResult(SecOC_VerifyResultType verificationResult, SecOC_RxPduInfoIterType rxPduId);
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_MAC
**********************************************************************************************************************/
/*! \brief      Verifies the MAC of a Secured I-Pdu.
    \details  -
    \param[in]  rxPduId  rx PduId
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Verify_MAC(SecOC_RxPduInfoIterType rxPduId);
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_RxIf_HandlePdus
**********************************************************************************************************************/
/*! \brief      Handle IF rx PDUs.
    \details    -
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_RxIf_HandlePdus(void);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_CopyVerifyValueToBuffer_DEPRECATED
**********************************************************************************************************************/
/*! \brief      Copys the FreshnessVerifyValue to the Data To Authenticate Buffer.
    \details  -
    \param[in]  rxPduId  rx PduId
    \param[in]  freshnessVerifyValue  the freshness value to verify
    \return     parsed freshness value
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_CopyVerifyValueToBuffer_DEPRECATED(SecOC_RxPduInfoIterType rxPduId, SecOC_FreshnessValueType freshnessVerifyValue);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_CopyVerifyValueToBuffer
******************************************************************************************** **************************/
/*! \brief      Copys the FreshnessVerifyValue to the Data To Authenticate Buffer.
    \details  -
    \param[in]  rxPduId  rx PduId
    \param[in]  freshnessVerifyValue  the freshness value to verify
    \return     parsed freshness value
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_CopyVerifyValueToBuffer(SecOC_RxPduInfoIterType rxPduId, P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) freshnessVerifyValue);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetParsedFreshnessValue
**********************************************************************************************************************/
/*! \brief      Returns the parsed freshness value.
    \details  -
    \param[in]  rxPduId  rx PduId
    \param[out] parsedFreshnessValue parsed freshness value.
    \return     parsed freshness value
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_GetParsedFreshnessValue(SecOC_RxPduInfoIterType rxPduId, uint8 * parsedFreshnessValue);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetParsedFreshnessValue
**********************************************************************************************************************/
/*! \brief      Returns the parsed freshness value.
    \details  -
    \param[in]  rxPduId  rx PduId
    \return     parsed freshness value
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetParsedFreshnessValue_DEPRECATED(SecOC_RxPduInfoIterType rxPduId);
#endif

#if (SECOC_EXISTS_CSM_43_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_GenerateAuthenticatorUsingCSM43
**********************************************************************************************************************/
/*! \brief      generates the MAC using the CSM
    \details  -
    \param[in]  txPduId  tx PduId
    \return     Std_ReturnType
                E_OK:      generation of the MAC using CSM was successful
                E_NOT_OK:  generation of the MAC using CSM was not successful
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_Authenticate_GenerateAuthenticatorUsingCSM43(SecOC_TxPduInfoIterType txPduId);
#endif

#if (SECOC_EXISTS_CSM_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_GenerateAuthenticatorUsingCSM
**********************************************************************************************************************/
/*! \brief      generates the MAC using the CSM
    \details  -
    \param[in]  txPduId  tx PduId
    \return     Std_ReturnType
                E_OK:      generation of the MAC using CSM was successful
                E_NOT_OK:  generation of the MAC using CSM was not successful
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_Authenticate_GenerateAuthenticatorUsingCSM(SecOC_TxPduInfoIterType txPduId);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))

/**********************************************************************************************************************
  SecOC_FreshnessValue_CalculateVerifyValue
**********************************************************************************************************************/
/*! \brief      Calculates the freshness verify value.
    \details  -
    \param[in]  rxPduId  rx PduId
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_CalculateVerifyValue(SecOC_RxPduInfoIterType rxPduId);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_UpdateVerifyValueInBuffer
**********************************************************************************************************************/
/*! \brief      Updates the Freshness Verify Value.
    \details  -
    \param[in]  rxPduId  rx PduId
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_UpdateVerifyValueInBuffer(SecOC_RxPduInfoIterType rxPduId);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_CalculateVerifyValueFromCallout
**********************************************************************************************************************/
/*! \brief      Gets the freshness verify value for a Rx Pdu form a configured callout
    \details  -
    \param[in]  rxPduId  Rx Pdu Id
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_CalculateVerifyValueFromCallout(SecOC_RxPduInfoIterType rxPduId);
#endif

#if ((SECOC_TXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetValueForTxPduOfCallout
**********************************************************************************************************************/
/*! \brief      Gets the freshness verify value for a Tx Pdu form a configured callout
    \details  -
    \param[in]  txPduId  tx PduId
    \param[out] freshnessValue freshness verify value
    \param[out] truncatedFreshnessValue truncated transmit value
    \return     STD_ON  if successful
                STD_OFF if failed
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValue_GetValueForTxPduOfCallout(SecOC_TxPduInfoIterType txPduId, uint8 * freshnessValue, uint8 * truncatedFreshnessValue);
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetVerifyValueFromBuffer
**********************************************************************************************************************/
/*! \brief      Reads the freshness verify value from the Authentic Pdu Buffer.
    \details  -
    \param[in]  rxPduId              rx PduId
    \return     freshness verify value.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetVerifyValueFromBuffer(SecOC_RxPduInfoIterType rxPduId);
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_FreshnessValue_WriteTrucFreshnessValue
**********************************************************************************************************************/
/*! \brief      Copys the truncated freshness value to the SecuredPdu buffer.
    \details  -
    \param[in]  txPduId              tx PduId
    \param[in]  trucFreshnessValue   truncated freshness value
    \return     none
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_WriteTruncFreshnessValue(SecOC_TxPduInfoIterType txPduId, P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) trucFreshnessValue);
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_FreshnessValue_CopyTxFreshnessValues
**********************************************************************************************************************/
/*! \brief      Copys the freshness value to the Data To Authenticate Buffer.
    \details  -
    \param[in]  txPduId              tx PduId
    \return     none
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValue_CopyTxFreshnessValues(SecOC_TxPduInfoIterType txPduId);
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_PropagateVerificationStatus
**********************************************************************************************************************/
/*! \brief      Calls all verification status Callouts.
    \details  -
    \param[in]  rxPduId              rx PduId
    \param[in]  verificationStatus   verification status
    \return     none
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Verify_PropagateVerificationStatus(SecOC_RxPduInfoIterType rxPduId, SecOC_VerificationResultType verificationStatus);
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_GenerateAuthenticator
**********************************************************************************************************************/
/*! \brief      Generates the authenticator of the secured PDU.
    \details  -
    \param[in]  txPduId              tx PduId
    \return     none
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Authenticate_GenerateAuthenticator(SecOC_TxPduInfoIterType txPduId);
#endif

#if (SECOC_EXISTS_CAL_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_GenerateAuthenticatorUsingCAL
**********************************************************************************************************************/
/*! \brief      Generates the authenticator of the secured PDU using the CAL.
    \details  -
    \param[in]  txPduId              tx PduId
    \return     none
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_Authenticate_GenerateAuthenticatorUsingCAL(SecOC_TxPduInfoIterType txPduId);
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_TxIf_HandlePdu_ReauthenticationNeeded
**********************************************************************************************************************/
/*! \brief      Processes the REAUTHENTICATION_NEEDED state of the passed Tx Pdu.
 *  \details  -
    \param[in]  txPduId  Pdu Id
    \return     none
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_TxIf_HandlePdu_ReauthenticationNeeded(SecOC_TxPduInfoIterType txPduId);
#endif

#if (SECOC_TXSPLITPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_TxIf_HandlePdu_SplitPdu
**********************************************************************************************************************/
/*! \brief      Handle the transmission of the related split Pdu.
    \details  -
    \param[in]  txPduId  Pdu Id
    \return     E_OK if successful
                E_NOT_OK if not successful
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_TxIf_HandlePdu_SplitPdu(SecOC_TxPduInfoIterType txPduId);
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_TxIf_HandlePdus
**********************************************************************************************************************/
/*! \brief      Handles Tx Pdus.
    \details  -
    \return     none
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_TxIf_HandlePdus(void);
#endif

#if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
/**********************************************************************************************************************
  SecOC_FreshnessValue_SetValue
**********************************************************************************************************************/
/*! \brief      set the freshness value.
    \details  -
    \param[in]  freshnessId  freshness Id
    \param[in]  freshnessValue  freshness value
    \return     none
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_SetValue(uint16 freshnessId, SecOC_FreshnessValueType freshnessValue);
#endif

#if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetValue
**********************************************************************************************************************/
/*! \brief      get the freshness value.
    \details  -
    \param[in]  freshnessId  freshness Id
    \return     the freshness value
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetValue(uint16 freshnessId);
#endif

#if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
/**********************************************************************************************************************
  SecOC_FreshnessValue_IncValue
**********************************************************************************************************************/
/*! \brief      increments the freshness value.
    \details  -
    \param[in]  freshnessId  freshness Id
    \return     none
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_IncValue(uint16 freshnessId);
#endif

#if (SECOC_CURRENTMESSAGELINKER == STD_ON)
/**********************************************************************************************************************
  SecOC_Split_CheckMessageLinker
**********************************************************************************************************************/
/*! \brief          Compares the passed message linker values.
 *                  If the new value is different, the old value is replaced with the new.
 *  \details  -
    \param[in]      msgLinkNew    new message linker value.
 *  \param[in,out]  msgLinkOld    old message linker value.
 *  \param[in]      msgLinkLenInBytes   message linker length in bytes.
 *  \return         TRUE          if the new message linker is different.
 *                  FALSE         if the message linker are equal.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, SECOC_CODE) SecOC_Split_CheckMessageLinker(P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) msgLinkNew, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) msgLinkOld, SecOC_MessageLinkLenOfRxSecuredPduInfoType msgLinkLenInBytes);
#endif

#if (SECOC_CURRENTMESSAGELINKER == STD_ON)
/**********************************************************************************************************************
  SecOC_Split_ExtractMessageLinker
**********************************************************************************************************************/
/*! \brief          Extracts the message linker form the source buffer and copies it to the dest buffer.
 *  \details  -
    \param[in]      msgLinkSrc    source buffer
 *  \param[out]     msgLinkDest   destination buffer
 *  \param[in]      msgLinkLen    message linker length in bits.
 *  \param[in]      msgLinkBitInByteOffset  bit in byte offset.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Split_ExtractMessageLinker(P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) msgLinkSrc, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) msgLinkDest, uint16 msgLinkLen, uint16 msgLinkBitInByteOffset);
#endif

#if ((SECOC_ENABLE_KEY_INTERFACE == STD_ON) && (SECOC_CRYPTOSERVICEOFTXPDUINFO == STD_ON))
/**********************************************************************************************************************
  SecOC_KeyMgt_isKeyAssigned
**********************************************************************************************************************/
/*! \brief          Evaluates whether a key is assigned to the related Tx Pdu.
 *  \details  -
    \param[in]      txPduId       Tx Pdu index.
 *  \return         TRUE          if key is assigned.
 *                  FALSE         if key is not assigned.
**********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, SECOC_CODE) SecOC_KeyMgt_isKeyAssigned(SecOC_TxPduInfoIterType txPduId);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#if ((SECOC_ENABLE_KEY_INTERFACE == STD_ON) && (SECOC_CRYPTOSERVICEOFTXPDUINFO == STD_ON))
/**********************************************************************************************************************
  SecOC_KeyMgt_isKeyAssigned
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, SECOC_CODE) SecOC_KeyMgt_isKeyAssigned(SecOC_TxPduInfoIterType txPduId)
{
  boolean ret = TRUE;
  switch (SecOC_GetCryptoServiceOfTxPduInfo(txPduId))
  {
#  if (SECOC_EXISTS_CAL_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
    case SECOC_CAL_CRYPTOSERVICEOFTXPDUINFO:
#  endif
#  if (SECOC_EXISTS_CSM_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
    case SECOC_CSM_CRYPTOSERVICEOFTXPDUINFO:
#  endif
#  if ((SECOC_EXISTS_CAL_CRYPTOSERVICEOFTXPDUINFO == STD_ON) || (SECOC_EXISTS_CSM_CRYPTOSERVICEOFTXPDUINFO == STD_ON))
    {
      if(SecOC_GetKeyState(SecOC_GetexternalKeyIdOfTxPduInfo(txPduId)) == SECOC_UNASSIGNED_KEYSTATE)
      {
        ret = FALSE;
      }
      break;
    }
#  endif
    default:   /* COV_SECOC_MISRA */
      break;
  }
  return ret;
}
#endif

#if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
/**********************************************************************************************************************
  SecOC_FreshnessValue_SetValue
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_SetValue(uint16 freshnessId, SecOC_FreshnessValueType freshnessValue)
{
  SecOC_NvRamInfo.secOC_FrValues[freshnessId] = freshnessValue;
}
#endif

#if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetValue
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetValue(uint16 freshnessId)
{
  return SecOC_NvRamInfo.secOC_FrValues[freshnessId];
}
#endif

#if ((SECOC_TXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetValueForTxPduOfCallout
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValue_GetValueForTxPduOfCallout(SecOC_TxPduInfoIterType txPduId, uint8 * freshnessValue, uint8 * truncatedFreshnessValue)
{
  Std_ReturnType ret = E_NOT_OK;
  uint32 freshnessValueLength;
  freshnessValueLength = (uint32) (SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo(txPduId) << 3U);

# if ((SECOC_EXISTS_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO == STD_ON) && (SECOC_EXISTS_DONT_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO == STD_ON))
  if(SecOC_GetProvideTruncTxFreshnessOfTxPduInfo(txPduId) == SECOC_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO)
# endif
# if (SECOC_EXISTS_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO == STD_ON)
  {
    uint32 truncatedFreshnessValueLength;
    truncatedFreshnessValueLength = (uint32) SecOC_GettruncatedFreshnessValueLengthOfTxPduInfo(txPduId);
    /* *INDENT-OFF* */
    ret = GetTxFreshnessTruncData_FuncName(
      SecOC_GetexternalFreshnessIdOfTxPduInfo(txPduId),
      freshnessValue,
      &freshnessValueLength,
      truncatedFreshnessValue,
      &truncatedFreshnessValueLength
    );
    /* *INDENT-ON* */
  }
# endif
# if ((SECOC_EXISTS_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO == STD_ON) && (SECOC_EXISTS_DONT_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO == STD_ON))
  else
# endif
# if (SECOC_EXISTS_DONT_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO == STD_ON)
  {
    /* *INDENT-OFF* */
    ret = GetTxFreshness_FuncName(
        SecOC_GetexternalFreshnessIdOfTxPduInfo(txPduId),
        freshnessValue,
        &freshnessValueLength
      );
    /* *INDENT-ON* */
    VStdMemCpyRamToRam(truncatedFreshnessValue, &(freshnessValue[SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo(txPduId) - SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo(txPduId)]), SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo(txPduId));
  }
# endif

  return ret;
}
#endif

#if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
/**********************************************************************************************************************
  SecOC_FreshnessValue_IncValue
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_IncValue(uint16 freshnessId)
{
  SecOC_FreshnessValue_SetValue(freshnessId, SecOC_FreshnessValue_GetValue(freshnessId) + 1);
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_CalculateVerifyValueFromCallout
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_CalculateVerifyValueFromCallout(SecOC_RxPduInfoIterType rxPduId)
{
  Std_ReturnType result = E_OK;
  uint8 freshnessVerifyValue[SECOC_FRESHNESS_SIZE_RXPDUS] = { 0 };

  result = SecOC_FreshnessValue_GetVerifyValueFromCallout(rxPduId, freshnessVerifyValue);
  if(result == E_OK)
  {
    SecOC_FreshnessValue_CopyVerifyValueToBuffer(rxPduId, freshnessVerifyValue);
    SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_RXPDUSTATE);
  }
  else if(result == SECOC_E_BUSY)
  {
    /* Increment Build attempts and check state */
    SecOC_Verify_IncrementBuildAttempts(rxPduId);
  }
  else
  {
    SecOC_Verify_PropagateVerificationStatus(rxPduId, SECOC_FRESHNESSFAILURE);
    SecOC_SetRxPduState(rxPduId, SECOC_IDLE_RXPDUSTATE);
  }
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_CalculateVerifyValue
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_CalculateVerifyValue(SecOC_RxPduInfoIterType rxPduId)
{
  SecOC_FreshnessValueType freshnessVerifyValue = 0;
  SecOC_FreshnessValueType parsedFreshnessValue = 0;

  parsedFreshnessValue = SecOC_FreshnessValue_GetParsedFreshnessValue_DEPRECATED(rxPduId);
  freshnessVerifyValue = SecOC_FreshnessValue_GetVerifyValue(rxPduId, parsedFreshnessValue);

  SecOC_FreshnessValue_CopyVerifyValueToBuffer_DEPRECATED(rxPduId, freshnessVerifyValue);
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_UpdateVerifyValueInBuffer
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_UpdateVerifyValueInBuffer(SecOC_RxPduInfoIterType rxPduId)
{
  SecOC_FreshnessValueType freshnessVerifyValue = 0;
  if(SecOC_FreshnessValue_GetValue(SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId)) < SecOC_GetfreshnessMaxValueOfRxPduInfo(rxPduId))
  {
    freshnessVerifyValue = SecOC_FreshnessValue_GetVerifyValueFromBuffer(rxPduId);
    freshnessVerifyValue += SecOC_GetFreshnessMostSignificantIncValueOfRxPduInfo(rxPduId);

    SecOC_FreshnessValue_CopyVerifyValueToBuffer_DEPRECATED(rxPduId, freshnessVerifyValue);
  }
  else
  {
    SecOC_Verify_PropagateVerificationStatus(rxPduId, SECOC_FRESHNESSFAILURE);
# if(SECOC_DEV_ERROR_REPORT == STD_ON)
    SecOC_ReportDetError(SECOC_SID_MAIN_FUNCTION_RX, SECOC_E_FRESHNESS_VALUE_AT_LIMIT);
# endif
  }
}
#endif

#if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetVerifyValueFromBuffer
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetVerifyValueFromBuffer(SecOC_RxPduInfoIterType rxPduId)
{
  SecOC_FreshnessValueType freshnessVerifyValue = 0;

  SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfoType valueidx = SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo(rxPduId);
  for(; valueidx < SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo(rxPduId); valueidx++)
  {
    freshnessVerifyValue = (SecOC_FreshnessValueType) (freshnessVerifyValue << 8U);
    /* add octet of freshness value in buffer */
    freshnessVerifyValue += SecOC_GetAuthenticPduDataContainer(valueidx);
  }
  return freshnessVerifyValue;
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_CopyVerifyValueToBuffer_DEPRECATED
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_CopyVerifyValueToBuffer_DEPRECATED(SecOC_RxPduInfoIterType rxPduId, SecOC_FreshnessValueType freshnessVerifyValue)
{
  /* get the index of the last octet of the freshness value in buffer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfoType valueidx = SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo(rxPduId) - 1;
  /* iterate from the LSB to the MSB. The address of the MSB will then be smaller then the address of the LSB */
  for(; valueidx >= SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo(rxPduId); valueidx--)
  {
    SecOC_SetAuthenticPduDataContainer(valueidx, (uint8) (freshnessVerifyValue & 255U));
    freshnessVerifyValue = (SecOC_FreshnessValueType) (freshnessVerifyValue >> 8U);
  }
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_CopyVerifyValueToBuffer
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_CopyVerifyValueToBuffer(SecOC_RxPduInfoIterType rxPduId, P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) freshnessVerifyValue)
{
  /* get the index of the last octet of the freshness value in buffer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfoType destValueidx = SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo(rxPduId);
  uint8 srcIdx = 0;
  /* iterate from the LSB to the MSB. The address of the MSB will then be smaller then the address of the LSB */
  for(; destValueidx < SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo(rxPduId); destValueidx++)
  {
    SecOC_SetAuthenticPduDataContainer(destValueidx, freshnessVerifyValue[srcIdx]);
    srcIdx++;
  }
}
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_FreshnessValue_WriteTrucFreshnessValue
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_WriteTruncFreshnessValue(SecOC_TxPduInfoIterType txPduId, P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) trucFreshnessValue)
{
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfoType iterValue = SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfo(txPduId);
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfoType srcValueIdx = SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo(txPduId) - 1;
  SecOC_truncatedFreshnessValueLengthOfTxPduInfoType bitsToCopy = SecOC_GettruncatedFreshnessValueLengthOfTxPduInfo(txPduId);

  uint8 firstByteShift = SecOC_GetTruncFreshnessValueFirstByteShiftOfTxPduInfo(txPduId);
  uint8 secondByteShift = SecOC_GetTruncFreshnessValueSecondByteShiftOfTxPduInfo(txPduId);

  for(; iterValue > SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueStartIdxOfTxPduInfo(txPduId); iterValue--)
  {
    SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfoType destValueIdx = iterValue - 1;
    if((bitsToCopy & 7U) != 0)
    {
      uint8 bitOffset = (uint8) (bitsToCopy & 7U);
      uint8 byteToCopy = (uint8) (trucFreshnessValue[srcValueIdx] << firstByteShift);
      uint8 copyMask = (uint8) (255U >> secondByteShift);

      byteToCopy = (SecOC_GetSecuredPduDataContainer(destValueIdx) & copyMask) | byteToCopy;
      SecOC_SetSecuredPduDataContainer(destValueIdx, byteToCopy);

      bitsToCopy = bitsToCopy - bitOffset;
    }
    else
    {
      uint8 byteToCopy = (uint8) (trucFreshnessValue[srcValueIdx] << firstByteShift);

      if(secondByteShift != 0)
      {
        byteToCopy = byteToCopy | ((uint8) (trucFreshnessValue[srcValueIdx + 1] >> secondByteShift));
      }

      SecOC_SetSecuredPduDataContainer(destValueIdx, byteToCopy);
      bitsToCopy = bitsToCopy - 8;
    }
    srcValueIdx--;
  }
}
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_FreshnessValue_CopyTxFreshnessValues
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValue_CopyTxFreshnessValues(SecOC_TxPduInfoIterType txPduId)
{
  uint8 freshnessValue[SECOC_FRESHNESS_SIZE_TXPDUS] = { 0 };    /* PRQA S 0759 */ /* MD_MSR_18.4 */
  uint8 truncatedFreshnessValue[SECOC_TRUNC_FRESHNESS_SIZE_TXPDUS] = { 0 };     /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Std_ReturnType ret = E_OK;

# if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
  {
    SecOC_FreshnessValueType internalValue;
    uint16 freshnessValueIdx = SECOC_FRESHNESS_SIZE_TXPDUS;
    uint16 truncFreshnessValueIdx = SECOC_TRUNC_FRESHNESS_SIZE_TXPDUS;

    internalValue = SecOC_FreshnessValue_GetValue(SecOC_GetexternalFreshnessIdOfTxPduInfo(txPduId));

    for(; freshnessValueIdx > 0; freshnessValueIdx--)
    {
      uint8 byteToCopy = (uint8) (internalValue & 255U);

      freshnessValue[freshnessValueIdx - 1] = byteToCopy;

      if(truncFreshnessValueIdx > 0)
      {
        truncatedFreshnessValue[truncFreshnessValueIdx - 1] = byteToCopy;
        truncFreshnessValueIdx--;
      }
      internalValue = (SecOC_FreshnessValueType) (internalValue >> 8U);
    }
  }
# else
  ret = SecOC_FreshnessValue_GetValueForTxPduOfCallout(txPduId, freshnessValue, truncatedFreshnessValue);
# endif
  if(ret == E_OK)
  {
    {
      /* get the index of the last octet of the freshness value in buffer */
      SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfoType valueidx = SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfo(txPduId);

      /* iterate from the LSB to the MSB. The address of the MSB will then be smaller then the address of the LSB. */
      for(; valueidx < SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfo(txPduId); valueidx++)
      {
        SecOC_SetAuthenticPduDataContainer(valueidx, freshnessValue[valueidx - SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfo(txPduId)]);
      }
    }
    SecOC_FreshnessValue_WriteTruncFreshnessValue(txPduId, truncatedFreshnessValue);
  }
  return ret;
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetParsedFreshnessValue
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_FreshnessValue_GetParsedFreshnessValue(SecOC_RxPduInfoIterType rxPduId, uint8 * parsedFreshnessValue)
{
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfoType iterValueidx = SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo(rxPduId);
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfoType destValueIdx = SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo(rxPduId) - 1;
  SecOC_truncatedFreshnessValueLengthOfRxPduInfoType truncatedFreshnessValueBitsToCopy = SecOC_GettruncatedFreshnessValueLengthOfRxPduInfo(rxPduId);

  uint8 firstByteShift = SecOC_GetTruncFreshnessValueFirstByteShiftOfRxPduInfo(rxPduId);
  uint8 secondByteShift = SecOC_GetTruncFreshnessValueSecondByteShiftOfRxPduInfo(rxPduId);

  for(; iterValueidx > SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo(rxPduId); iterValueidx--)
  {
    SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfoType srcValueidx = iterValueidx - 1;
    if(truncatedFreshnessValueBitsToCopy >= 8)
    {
      uint8 byteToCopy = 0;
      byteToCopy = (uint8) (SecOC_GetSecuredPduDataContainer(srcValueidx) >> firstByteShift);

      if(secondByteShift != 0)
      {
        byteToCopy = byteToCopy | ((uint8) (SecOC_GetSecuredPduDataContainer(srcValueidx - 1) << secondByteShift));
      }

      parsedFreshnessValue[destValueIdx] = byteToCopy;
      truncatedFreshnessValueBitsToCopy = truncatedFreshnessValueBitsToCopy - 8;
    }
    else if(truncatedFreshnessValueBitsToCopy > 0)
    {
      parsedFreshnessValue[destValueIdx] = (uint8) (SecOC_GetSecuredPduDataContainer(srcValueidx) >> firstByteShift);
      truncatedFreshnessValueBitsToCopy = 0;
    }
    else
    {
    }
    destValueIdx--;
  }
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetParsedFreshnessValue_DEPRECATED
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetParsedFreshnessValue_DEPRECATED(SecOC_RxPduInfoIterType rxPduId)
{
  SecOC_FreshnessValueType parsedFreshnessValue = 0;
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfoType valueidx = SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo(rxPduId);
  SecOC_truncatedFreshnessValueLengthOfRxPduInfoType truncatedFreshnessValueBitsToCopy = SecOC_GettruncatedFreshnessValueLengthOfRxPduInfo(rxPduId);
  for(; valueidx < SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo(rxPduId); valueidx++)
  {
    if(truncatedFreshnessValueBitsToCopy >= 8)
    {
      parsedFreshnessValue = (SecOC_FreshnessValueType) (parsedFreshnessValue << 8U);
      parsedFreshnessValue = parsedFreshnessValue | ((SecOC_FreshnessValueType) SecOC_GetSecuredPduDataContainer(valueidx));
      truncatedFreshnessValueBitsToCopy = truncatedFreshnessValueBitsToCopy - 8;
    }
    else if(truncatedFreshnessValueBitsToCopy > 0)
    {
      uint8 copyMask = (uint8) (255U >> (8 - truncatedFreshnessValueBitsToCopy));
      parsedFreshnessValue = (SecOC_FreshnessValueType) (parsedFreshnessValue << truncatedFreshnessValueBitsToCopy);
      parsedFreshnessValue = parsedFreshnessValue | ((SecOC_FreshnessValueType) (SecOC_GetSecuredPduDataContainer(valueidx) & copyMask));
      truncatedFreshnessValueBitsToCopy = 0;
    }
    else
    {
    }

  }
  return parsedFreshnessValue;
}
#endif

#if (SECOC_EXISTS_CSM_43_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_GenerateAuthenticatorUsingCSM43
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_Authenticate_GenerateAuthenticatorUsingCSM43(SecOC_TxPduInfoIterType txPduId)
{
  Std_ReturnType ret = E_NOT_OK;
  uint32 resultLength = SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo(txPduId);
  /* *INDENT-OFF* */
  ret = Csm_MacGenerate(
      SecOC_GetAuthenticationLayerIdOfTxPduInfo(txPduId),
    CRYPTO_OPERATIONMODE_SINGLECALL,
    SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo(txPduId)),
    SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfo(txPduId),
    SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduId)),
    &resultLength);
  /* *INDENT-ON* */
  if(ret == E_OK)
  {
# if (SECOC_WAITFORCALLBACKOFTXPDUINFO == STD_ON)
    if(SecOC_IsWaitForCallbackOfTxPduInfo(txPduId))
    {
      SecOC_SetTxPduState(txPduId, SECOC_UNAUTHENTICATED_FINISHED_WAIT_FOR_CALLBACK_TXPDUSTATE);
    }
    else
# endif
    {
      SecOC_Authenticate_CopyAuthenticatorToSecuredPdu(txPduId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduId)));
      SecOC_SetTxPduState(txPduId, SECOC_UNAUTHENTICATED_FINISHED_TXPDUSTATE);
    }
  }

  return ret;
}
#endif

#if (SECOC_EXISTS_CSM_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_GenerateAuthenticatorUsingCSM
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_Authenticate_GenerateAuthenticatorUsingCSM(SecOC_TxPduInfoIterType txPduId)
{
  SecOC_AuthenticationLayerIdOfTxPduInfoType cfgId = SecOC_GetAuthenticationLayerIdOfTxPduInfo(txPduId);
  Std_ReturnType ret = E_NOT_OK;
# if (SECOC_CSM_USE_SYNC_JOB_PROCESSING == STD_ON)
  if(SecOC_GetKeyState(SecOC_GetexternalKeyIdOfTxPduInfo(txPduId)) == SECOC_ASSIGNED_KEYSTATE)
  {
    ret = Csm_MacGenerateStart((Csm_ConfigIdType) cfgId, (P2CONST(Csm_SymKeyType, AUTOMATIC, AUTOMATIC)) SecOC_GetAddrKeyArray(SecOC_GetexternalKeyIdOfTxPduInfo(txPduId)));    /* PRQA S 0310 */ /* Casting of a pointer to another pointer with the same or less strict alignment and back again is safe */
  }
  if(ret == E_OK)
  {
    ret = Csm_MacGenerateUpdate((Csm_ConfigIdType) cfgId, SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo(txPduId)), SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfo(txPduId));
    if(ret == E_OK)
    {
      uint32 resultLength = SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo(txPduId);

      ret = Csm_MacGenerateFinish((Csm_ConfigIdType) cfgId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduId)), &resultLength, TRUE);
      if((resultLength == SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo(txPduId)) && (ret == CSM_E_OK))
      {
        SecOC_Authenticate_CopyAuthenticatorToSecuredPdu(txPduId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduId)));
        SecOC_SetTxPduState(txPduId, SECOC_UNAUTHENTICATED_FINISHED_TXPDUSTATE);
        ret = E_OK;
      }
    }
  }
# else
  switch (SecOC_GetTxPduState(txPduId))
  {
    case SECOC_UNAUTHENTICATED_TO_BE_STARTED_TXPDUSTATE:
    {
      if(SecOC_GetKeyState(SecOC_GetexternalKeyIdOfTxPduInfo(txPduId)) == SECOC_ASSIGNED_KEYSTATE)
      {
        ret = Csm_MacGenerateStart((Csm_ConfigIdType) cfgId, (P2CONST(Csm_SymKeyType, AUTOMATIC, AUTOMATIC)) SecOC_GetAddrKeyArray(SecOC_GetexternalKeyIdOfTxPduInfo(txPduId)));        /* PRQA S 0310 */ /* Casting of a pointer to another pointer with the same or less strict alignment and back again is safe */
      }
      if(ret == E_OK)
      {
        SecOC_SetTxPduState(txPduId, SECOC_UNAUTHENTICATED_STARTED_WAIT_FOR_CALLBACK_TXPDUSTATE);
      }
    }
      break;
    case SECOC_UNAUTHENTICATED_TO_BE_UPDATED_TXPDUSTATE:
    {
      ret = Csm_MacGenerateUpdate((Csm_ConfigIdType) cfgId, SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo(txPduId)), SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfo(txPduId));
      if(ret == E_OK)
      {
        SecOC_SetTxPduState(txPduId, SECOC_UNAUTHENTICATED_UPDATED_WAIT_FOR_CALLBACK_TXPDUSTATE);
      }
    }
      break;
    case SECOC_UNAUTHENTICATED_TO_BE_FINISHED_TXPDUSTATE:
    {
      uint32 resultLength = SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo(txPduId);

      ret = Csm_MacGenerateFinish((Csm_ConfigIdType) cfgId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduId)), &resultLength, TRUE);
      if(ret == E_OK)
      {
        SecOC_SetTxPduState(txPduId, SECOC_UNAUTHENTICATED_FINISHED_WAIT_FOR_CALLBACK_TXPDUSTATE);
      }
    }
      break;
    default:
      ret = E_OK;
      break;
  }

# endif /* (SECOC_CSM_USE_SYNC_JOB_PROCESSING == STD_ON) */
  return ret;
}
#endif

#if (SECOC_EXISTS_CAL_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_GenerateAuthenticatorUsingCAL
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_Authenticate_GenerateAuthenticatorUsingCAL(SecOC_TxPduInfoIterType txPduId)
{
  Cal_MacGenerateCtxBufType contextBuffer;
  SecOC_AuthenticationLayerIdOfTxPduInfoType cfgId = SecOC_GetAuthenticationLayerIdOfTxPduInfo(txPduId);
  Cal_ReturnType result = CAL_E_NOT_OK;
  Std_ReturnType ret = E_NOT_OK;
  if(SecOC_GetKeyState(SecOC_GetexternalKeyIdOfTxPduInfo(txPduId)) == SECOC_ASSIGNED_KEYSTATE)
  {
    result = Cal_MacGenerateStart((Cal_ConfigIdType) cfgId, contextBuffer, (P2CONST(Cal_SymKeyType, AUTOMATIC, AUTOMATIC)) SecOC_GetAddrKeyArray(SecOC_GetexternalKeyIdOfTxPduInfo(txPduId)));  /* PRQA S 0310 */ /* Casting of a pointer to another pointer with the same or less strict alignment and back again is safe */
  }
  if(result == CAL_E_OK)
  {
    result = Cal_MacGenerateUpdate((Cal_ConfigIdType) cfgId, contextBuffer, SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo(txPduId)), SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfo(txPduId));
    if(result == CAL_E_OK)
    {
      uint32 resultLength = SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo(txPduId);

      result = Cal_MacGenerateFinish((Cal_ConfigIdType) cfgId, contextBuffer, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduId)), &resultLength, TRUE);

      if((resultLength == SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo(txPduId)) && (result == CAL_E_OK))
      {
        SecOC_Authenticate_CopyAuthenticatorToSecuredPdu(txPduId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduId)));
        SecOC_SetTxPduState(txPduId, SECOC_UNAUTHENTICATED_FINISHED_TXPDUSTATE);
        ret = E_OK;
      }
    }
  }
  return ret;
}
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_GenerateAuthenticator
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Authenticate_GenerateAuthenticator(SecOC_TxPduInfoIterType txPduId)
{
  Std_ReturnType ret = E_NOT_OK;
  SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();
# if (SECOC_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
  switch (SecOC_GetCryptoServiceOfTxPduInfo(txPduId))
  {
#  if (SECOC_EXISTS_CAL_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
    case SECOC_CAL_CRYPTOSERVICEOFTXPDUINFO:
    {
      ret = SecOC_Authenticate_GenerateAuthenticatorUsingCAL(txPduId);
    }
      break;
#  endif
#  if (SECOC_EXISTS_CSM_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
    case SECOC_CSM_CRYPTOSERVICEOFTXPDUINFO:
    {
      ret = SecOC_Authenticate_GenerateAuthenticatorUsingCSM(txPduId);
    }
      break;
#  endif
#  if (SECOC_EXISTS_CSM_43_CRYPTOSERVICEOFTXPDUINFO == STD_ON)
    case SECOC_CSM_43_CRYPTOSERVICEOFTXPDUINFO:
    {
      ret = SecOC_Authenticate_GenerateAuthenticatorUsingCSM43(txPduId);
    }
      break;
#  endif
    default:   /* COV_SECOC_MISRA */
      break;
  }
# endif
  if(ret == SECOC_E_BUSY)
  {
    SecOC_Authenticate_IncrementAndCheckBuildAttempts(txPduId);
  }
  else if(ret == E_NOT_OK)
  {
    SecOC_SetTxPduState(txPduId, SECOC_INVALID_SECURED_PDU_TXPDUSTATE);
    SecOC_SetTransmitRequest(txPduId, SECOC_IDLE_TRANSMITREQUEST);
# if (SECOC_TXSPLITPDUINFO == STD_ON)
    if(SecOC_IsTxSplitPduInfoUsedOfTxPduInfo(txPduId))
    {
      SecOC_SizeOfTxSplitPduInfoType splitTxPduId = SecOC_GetTxSplitPduInfoIdxOfTxPduInfo(txPduId);
      SecOC_SetAuthenticSplitPduTransmit(splitTxPduId, SECOC_TRANSMIT_AUTHENTICSPLITPDUTRANSMIT);
      SecOC_SetCryptographicPduTransmit(splitTxPduId, SECOC_TRANSMIT_AUTHENTICSPLITPDUTRANSMIT);
    }
# endif
  }
  else
  {
    /* COV_SECOC_MISRA */
  }
  SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();
}
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_TxIf_HandlePdu_ReauthenticationNeeded
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_TxIf_HandlePdu_ReauthenticationNeeded(SecOC_TxPduInfoIterType txPduId)
{
  if(SecOC_GetTxPduState(txPduId) == SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE)
  {
    Std_ReturnType ret = SecOC_FreshnessValue_CopyTxFreshnessValues(txPduId);
    if(ret == E_OK)
    {
      SecOC_SetTxPduState(txPduId, SECOC_UNAUTHENTICATED_TO_BE_STARTED_TXPDUSTATE);
    }
    else if(ret == E_NOT_OK)
    {
      SecOC_SetTxPduState(txPduId, SECOC_INVALID_SECURED_PDU_TXPDUSTATE);
      SecOC_SetTransmitRequest(txPduId, SECOC_IDLE_TRANSMITREQUEST);
# if (SECOC_TXSPLITPDUINFO == STD_ON)
      if(SecOC_IsTxSplitPduInfoUsedOfTxPduInfo(txPduId))
      {
        SecOC_SizeOfTxSplitPduInfoType splitTxPduId = SecOC_GetTxSplitPduInfoIdxOfTxPduInfo(txPduId);
        SecOC_SetAuthenticSplitPduTransmit(splitTxPduId, SECOC_TRANSMIT_AUTHENTICSPLITPDUTRANSMIT);
        SecOC_SetCryptographicPduTransmit(splitTxPduId, SECOC_TRANSMIT_AUTHENTICSPLITPDUTRANSMIT);
      }
# endif
    }
    else
    {
      SecOC_Authenticate_IncrementAndCheckBuildAttempts(txPduId);
    }
  }
}
#endif

#if (SECOC_TXSPLITPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_TxIf_HandlePdu_SplitPdu
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_TxIf_HandlePdu_SplitPdu(SecOC_TxPduInfoIterType txPduId)
{
  SecOC_SizeOfTxSplitPduInfoType splitTxPduId = SecOC_GetTxSplitPduInfoIdxOfTxPduInfo(txPduId);
  Std_ReturnType retVal;
  Std_ReturnType retValAuthPdu;
  Std_ReturnType retValCryptoPdu;
  if(SecOC_GetAuthenticSplitPduTransmit(splitTxPduId) == SECOC_TRANSMIT_AUTHENTICSPLITPDUTRANSMIT)
  {
    PduInfoType pduInfo;
    pduInfo.SduDataPtr = SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerAuthenticSplitPduStartIdxOfTxSplitPduInfo(splitTxPduId));
    pduInfo.SduLength = (PduLengthType) SecOC_GetSecuredPduDataContainerAuthenticSplitPduLengthOfTxSplitPduInfo(splitTxPduId);
    SecOC_SetTxPduState(txPduId, SECOC_TRANSMISSION_INITIATED_TXPDUSTATE);
    retValAuthPdu = PduR_SecOCTransmit(SecOC_GetAuthSplitPduExternalIdOfTxSplitPduInfo(splitTxPduId), &pduInfo);
    if(retValAuthPdu == E_OK)
    {
      SecOC_SetAuthenticSplitPduTransmit(splitTxPduId, SECOC_IDLE_AUTHENTICSPLITPDUTRANSMIT);
    }
  }
  else
  {
    retValAuthPdu = E_OK;
  }

  if(SecOC_GetCryptographicPduTransmit(splitTxPduId) == SECOC_TRANSMIT_CRYPTOGRAPHICPDUTRANSMIT)
  {
    PduInfoType pduInfo;
    pduInfo.SduDataPtr = SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerCryptographicPduStartIdxOfTxSplitPduInfo(splitTxPduId));
    pduInfo.SduLength = (PduLengthType) SecOC_GetSecuredPduDataContainerCryptographicPduLengthOfTxSplitPduInfo(splitTxPduId);

# if(SECOC_CURRENTMESSAGELINKER == STD_ON)
    if(SecOC_IsSecuredPduDataContainerMessageLinkerCryptoPduUsedOfTxSplitPduInfo(splitTxPduId))
    {
      /* *INDENT-OFF* */
      SecOC_Split_ExtractMessageLinker(SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerMessageLinkerAuthSplitPduStartIdxOfTxSplitPduInfo(splitTxPduId)),
                                       SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerMessageLinkerCryptoPduStartIdxOfTxSplitPduInfo(splitTxPduId)),
                                       SecOC_GetMessageLinkLenOfTxSplitPduInfo(splitTxPduId),
                                       (SecOC_GetMessageLinkPosOfTxSplitPduInfo(splitTxPduId) & 7U));
      /* *INDENT-ON* */
    }
# endif
    SecOC_SetTxPduState(txPduId, SECOC_TRANSMISSION_INITIATED_TXPDUSTATE);
    retValCryptoPdu = PduR_SecOCTransmit(SecOC_GetCyptographicPduExternalIdOfTxSplitPduInfo(splitTxPduId), &pduInfo);
    if(retValCryptoPdu == E_OK)
    {
      SecOC_SetCryptographicPduTransmit(splitTxPduId, SECOC_IDLE_CRYPTOGRAPHICPDUTRANSMIT);
    }
  }
  else
  {
    retValCryptoPdu = E_OK;
  }

  if((retValAuthPdu == E_OK) && (retValCryptoPdu == E_OK))
  {
    retVal = E_OK;
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_TxIf_HandlePdus
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_TxIf_HandlePdus(void)
{
  SecOC_TxPduInfoIterType txPduId = 0;
  for(; txPduId < SecOC_GetSizeOfTxPduInfo(); txPduId++)
  {
    SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();

    SecOC_TxIf_HandlePdu_ReauthenticationNeeded(txPduId);

    if(SecOC_IsTxPduStateUnauthenticated(txPduId))
    {
      /* Generates MAC and copies the truncated MAC to the Secured Pdu Buffer */
      if(SecOC_GetTxPduState(txPduId) != SECOC_UNAUTHENTICATED_FINISHED_TXPDUSTATE)
      {
        SecOC_Authenticate_GenerateAuthenticator(txPduId);
      }
      if(SecOC_GetTxPduState(txPduId) == SECOC_UNAUTHENTICATED_FINISHED_TXPDUSTATE)
      {
        VStdMemCpyRamToRam(SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerAuthenticPduStartIdxOfTxPduInfo(txPduId)), SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfo(txPduId)), SecOC_GetSecuredPduDataContainerAuthenticPduLengthOfTxPduInfo(txPduId));
        SecOC_SetTxPduState(txPduId, SECOC_AUTHENTICATED_TXPDUSTATE);
      }
    }

    if((SecOC_GetTxPduState(txPduId) == SECOC_AUTHENTICATED_TXPDUSTATE) && (SecOC_GetTransmitRequest(txPduId) == SECOC_TRANSMIT_TRANSMITREQUEST))
    {
      Std_ReturnType retVal;

# if (SECOC_TXSPLITPDUINFO == STD_ON)
      if(SecOC_IsTxSplitPduInfoUsedOfTxPduInfo(txPduId))
      {
        retVal = SecOC_TxIf_HandlePdu_SplitPdu(txPduId);
      }
      else
# endif
      {
        PduInfoType pduInfo;
        pduInfo.SduDataPtr = SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo(txPduId));
        pduInfo.SduLength = (PduLengthType) SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(txPduId);
        SecOC_SetTxPduState(txPduId, SECOC_TRANSMISSION_INITIATED_TXPDUSTATE);
        retVal = PduR_SecOCTransmit(SecOC_GetSecuredExternalIdOfTxPduInfo(txPduId), &pduInfo);
      }

      if(retVal == E_OK)
      {
# if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
        SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_FRESHNESS_VALUE();
        SecOC_FreshnessValue_IncValue(SecOC_GetexternalFreshnessIdOfTxPduInfo(txPduId));
        SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_FRESHNESS_VALUE();
# endif
# if (SECOC_SPDUTXCONFIRMATIONNEEDEDOFTXPDUINFO == STD_ON)
        if(SecOC_IsSPduTxConfirmationNeededOfTxPduInfo(txPduId))
        {
          SPduTxConfirmation_FuncName(SecOC_GetexternalFreshnessIdOfTxPduInfo(txPduId));
        }
# endif
        SecOC_SetTransmitRequest(txPduId, SECOC_IDLE_TRANSMITREQUEST);
      }
      else
      {
        SecOC_SetTxPduState(txPduId, SECOC_AUTHENTICATED_TXPDUSTATE);
      }
    }
    SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
  }
}  /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_PropagateVerificationStatus
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Verify_PropagateVerificationStatus(SecOC_RxPduInfoIterType rxPduId, SecOC_VerificationResultType verificationStatus)
{
  SecOC_VerificationStatusType verificationStatusStruct;
  verificationStatusStruct.verificationStatus = verificationStatus;
  verificationStatusStruct.freshnessValueID = SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId);
  verificationStatusStruct.secOCDataId = SecOC_GetDataIdOfRxPduInfo(rxPduId);
  {
# if (SECOC_VERIFICATIONSTATUSCALLOUT == STD_ON)
    SecOC_VerificationStatusCalloutIterType idx = 0;
    for(; idx < SecOC_GetSizeOfVerificationStatusCallout(); idx++)
    {
      SecOC_GetVerificationStatusCallout(idx) (verificationStatusStruct);
    }
# endif /* (SECOC_VERIFICATIONSTATUSCALLOUT == STD_ON) */
    (void) Rte_Write_VerificationStatus_verificationStatus(&verificationStatusStruct);
  }
}
#endif

#if (SECOC_EXISTS_CAL_CRYPTOSERVICEOFRXPDUINFO == STD_ON )
/**********************************************************************************************************************
  SecOC_Verify_MACUsingCAL
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_VerifyResultType, SECOC_CODE) SecOC_Verify_MACUsingCAL(SecOC_RxPduInfoIterType rxPduId)
{
  Cal_MacVerifyCtxBufType contextBuffer;
  Cal_ReturnType result;
  SecOC_VerifyResultType secOCVerifyResult = SECOC_E_VER_NOT_OK;

  SecOC_AuthenticationLayerIdOfRxPduInfoType cfgId = SecOC_GetAuthenticationLayerIdOfRxPduInfo(rxPduId);
  if(SecOC_GetKeyState(SecOC_GetexternalKeyIdOfRxPduInfo(rxPduId)) == SECOC_ASSIGNED_KEYSTATE)
  {
    result = Cal_MacVerifyStart(cfgId, contextBuffer, (P2CONST(Cal_SymKeyType, AUTOMATIC, AUTOMATIC)) SecOC_GetAddrKeyArray(SecOC_GetexternalKeyIdOfRxPduInfo(rxPduId)));       /* PRQA S 0310 */ /* Casting of a pointer to another pointer with the same or less strict alignment and back again is safe */
  }
  else
  {
    result = CAL_E_NOT_OK;
  }
  if(result == CAL_E_OK)
  {
    result = Cal_MacVerifyUpdate(cfgId, contextBuffer, SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo(rxPduId)), SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo(rxPduId));
    if(result == CAL_E_OK)
    {
      Cal_VerifyResultType calVerifyResult = CAL_E_VER_NOT_OK;
      SecOC_Verify_GetByteAlignedTruncatedAuthenticator(rxPduId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(rxPduId)));

      result = Cal_MacVerifyFinish(cfgId, contextBuffer, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(rxPduId)), SecOC_GettruncatedAuthenticationLengthOfRxPduInfo(rxPduId), &calVerifyResult);
      if(calVerifyResult == CAL_E_VER_OK)
      {
        secOCVerifyResult = SECOC_E_VER_OK;
      }
    }
  }

  SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE);

# if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(result != CAL_E_OK)
  {
    SecOC_ReportDetError(SECOC_SID_MAIN_FUNCTION_RX, SECOC_E_CRYPTO_FAILURE);
  }
# endif

  return secOCVerifyResult;
}
#endif

#if (SECOC_EXISTS_CSM_CRYPTOSERVICEOFRXPDUINFO == STD_ON )
/**********************************************************************************************************************
  SecOC_Verify_MACUsingCSM
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_VerifyResultType, SECOC_CODE) SecOC_Verify_MACUsingCSM(SecOC_RxPduInfoIterType rxPduId)
{
  Csm_ReturnType result = E_NOT_OK;
  Csm_VerifyResultType csmVerifyResult = CSM_E_VER_NOT_OK;
  SecOC_VerifyResultType secOCVerifyResult = SECOC_E_VER_NOT_OK;
  SecOC_AuthenticationLayerIdOfRxPduInfoType cfgId = SecOC_GetAuthenticationLayerIdOfRxPduInfo(rxPduId);

# if (SECOC_CSM_USE_SYNC_JOB_PROCESSING == STD_ON)
  if(SecOC_GetKeyState(SecOC_GetexternalKeyIdOfRxPduInfo(rxPduId)) == SECOC_ASSIGNED_KEYSTATE)
  {
    result = Csm_MacVerifyStart(cfgId, (P2CONST(Csm_SymKeyType, AUTOMATIC, AUTOMATIC)) SecOC_GetAddrKeyArray(SecOC_GetexternalKeyIdOfRxPduInfo(rxPduId)));      /* PRQA S 0310 */ /* Casting of a pointer to another pointer with the same or less strict alignment and back again is safe */
  }
  if(result == E_OK)
  {
    result = Csm_MacVerifyUpdate(cfgId, SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo(rxPduId)), SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo(rxPduId));
    if(result == E_OK)
    {
      SecOC_Verify_GetByteAlignedTruncatedAuthenticator(rxPduId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(rxPduId)));

      result = Csm_MacVerifyFinish(cfgId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(rxPduId)), SecOC_GettruncatedAuthenticationLengthOfRxPduInfo(rxPduId), &csmVerifyResult);
      if(result == E_OK)
      {
        SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE);
      }
    }
  }
# else
  switch (SecOC_GetRxPduState(rxPduId))
  {
    case SECOC_UNVERIFIED_VERIFICATION_TO_BE_STARTED_RXPDUSTATE:
    {
      if(SecOC_GetKeyState(SecOC_GetexternalKeyIdOfRxPduInfo(rxPduId)) == SECOC_ASSIGNED_KEYSTATE)
      {
        result = Csm_MacVerifyStart(cfgId, (P2CONST(Csm_SymKeyType, AUTOMATIC, AUTOMATIC)) SecOC_GetAddrKeyArray(SecOC_GetexternalKeyIdOfRxPduInfo(rxPduId)));  /* PRQA S 0310 */ /* Casting of a pointer to another pointer with the same or less strict alignment and back again is safe */
      }
      if(result == E_OK)
      {
        SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_STARTED_WAIT_FOR_CALLBACK_RXPDUSTATE);
      }
    }
      break;
    case SECOC_UNVERIFIED_VERIFICATION_TO_BE_UPDATED_RXPDUSTATE:
    {
      result = Csm_MacVerifyUpdate(cfgId, SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo(rxPduId)), SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo(rxPduId));
      if(result == E_OK)
      {
        SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_UPDATED_WAIT_FOR_CALLBACK_RXPDUSTATE);
      }
    }
      break;
    case SECOC_UNVERIFIED_VERIFICATION_TO_BE_FINISHED_RXPDUSTATE:
    {
      SecOC_Verify_GetByteAlignedTruncatedAuthenticator(rxPduId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(rxPduId)));

      result = Csm_MacVerifyFinish(cfgId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(rxPduId)), SecOC_GettruncatedAuthenticationLengthOfRxPduInfo(rxPduId), SecOC_GetAddrVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduId)));
      if(result == E_OK)
      {
        SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE);
      }
    }
      break;
    case SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE:
    {
      csmVerifyResult = SecOC_GetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduId));
      SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE);
      result = E_OK;
    }
      break;
    default:
      result = E_OK;
      break;
  }
# endif
  if(result == E_NOT_OK)
  {
    /* CSM returned none recoverable return value */
    SecOC_SetRxPduState(rxPduId, SECOC_IDLE_RXPDUSTATE);
  }
  else if(result != E_OK)
  {
    /* CSM returned recoverable return value */
    SecOC_SetRxPduState(rxPduId, SECOC_FRESHNESS_VALUE_NEEDED_RXPDUSTATE);
    SecOC_Verify_IncrementBuildAttempts(rxPduId);
  }
  else
  {
    /* CSM API call was successful */
  }

  if(csmVerifyResult == CSM_E_VER_OK)
  {
    secOCVerifyResult = SECOC_E_VER_OK;
  }

  return secOCVerifyResult;
}  /* PRQA S 6030 */ /* MD_MSR_STCYC */
#endif

#if (SECOC_EXISTS_CSM_43_CRYPTOSERVICEOFRXPDUINFO == STD_ON )
/**********************************************************************************************************************
  SecOC_Verify_MACUsingCSM43
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_VerifyResultType, SECOC_CODE) SecOC_Verify_MACUsingCSM43(SecOC_RxPduInfoIterType rxPduId)
{
  Std_ReturnType retValue = E_NOT_OK;
  Crypto_VerifyResultType csmVerifyResult = CSM_E_VER_NOT_OK;
  SecOC_VerifyResultType secOCVerifyResult = SECOC_E_VER_NOT_OK;

  if(SecOC_GetRxPduState(rxPduId) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE)
  {
    retValue = E_OK;
    csmVerifyResult = SecOC_GetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduId));
    SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE);
  }
  else
  {
    SecOC_Verify_GetByteAlignedTruncatedAuthenticator(rxPduId, SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(rxPduId)));
    /* *INDENT-OFF* */
    retValue = Csm_MacVerify(
        SecOC_GetAuthenticationLayerIdOfRxPduInfo(rxPduId),
        CRYPTO_OPERATIONMODE_SINGLECALL,
        SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo(rxPduId)),
        SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo(rxPduId),
        SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(rxPduId)),
        SecOC_GettruncatedAuthenticationLengthOfRxPduInfo(rxPduId),
        SecOC_GetAddrVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduId)));
    /* *INDENT-ON* */
    if(retValue == E_OK)
    {
# if(SECOC_WAITFORCALLBACKOFRXPDUINFO == STD_ON)
      if(SecOC_IsWaitForCallbackOfRxPduInfo(rxPduId))
      {
        SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE);
      }
      else
# endif
      {
        csmVerifyResult = SecOC_GetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduId));
        SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE);
      }
    }
  }

  if(retValue == E_NOT_OK)
  {
    /* CSM returned none recoverable return value */
    SecOC_SetRxPduState(rxPduId, SECOC_IDLE_RXPDUSTATE);
  }
  else if(retValue != E_OK)
  {
    /* CSM returned recoverable return value */
    SecOC_SetRxPduState(rxPduId, SECOC_FRESHNESS_VALUE_NEEDED_RXPDUSTATE);
    SecOC_Verify_IncrementBuildAttempts(rxPduId);
  }
  else
  {
    /* CSM API call was successful */
  }

  if(csmVerifyResult == CRYPTO_E_VER_OK)
  {
    secOCVerifyResult = SECOC_E_VER_OK;
  }

  return secOCVerifyResult;
}
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_GetByteAlignedTruncatedAuthenticator
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Verify_GetByteAlignedTruncatedAuthenticator(SecOC_RxPduInfoIterType rxPduId, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) byteAlignedAuthenticator)
{
  SecOC_truncatedAuthenticationLengthOfRxPduInfoType bitsToCopy = SecOC_GettruncatedAuthenticationLengthOfRxPduInfo(rxPduId);
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfoType sourceIdx = SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo(rxPduId);
  uint8 msbBitOffset = SecOC_GetTruncatedAuthenticatorShiftOffestForMsbOfRxPduInfo(rxPduId);
  uint8 lsbBitOffset = SecOC_GetTruncatedAuthenticatorShiftOffestForLsbOfRxPduInfo(rxPduId);
  uint8 destIdx = 0;

  for(; sourceIdx < SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo(rxPduId); sourceIdx++)
  {
    if(bitsToCopy >= 8)
    {
      uint8 byteToWrite = 0;
      uint8 secondByte = 0;
      byteToWrite = SecOC_GetSecuredPduDataContainer(sourceIdx);
      secondByte = SecOC_GetSecuredPduDataContainer(sourceIdx + 1);

      if(msbBitOffset != 0)
      {
        byteToWrite = (uint8) (byteToWrite << msbBitOffset);
        secondByte = (uint8) (secondByte >> lsbBitOffset);

        byteToWrite = byteToWrite | secondByte;
      }
      byteAlignedAuthenticator[destIdx] = byteToWrite;

      bitsToCopy = bitsToCopy - 8;
    }
    else if(bitsToCopy != 0)
    {
      uint8 byteToWrite = 0;
      byteToWrite = SecOC_GetSecuredPduDataContainer(sourceIdx);
      byteToWrite = (uint8) (byteToWrite << msbBitOffset);
      byteAlignedAuthenticator[destIdx] = byteToWrite;
      bitsToCopy = 0;
    }
    else
    {
    }
    destIdx++;
  }

}

#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_GetVerificationResultOfOverrideStatus
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_VerifyResultType, SECOC_CODE) SecOC_Verify_GetVerificationResultOfOverrideStatus(SecOC_RxPduInfoIterType rxPduId)
{
  uint16 freshnessId = SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId);
  SecOC_VerifyResultType verificationResult = SECOC_E_VER_NOT_OK;
  SecOC_VerifyOverrideStatusType verifyOverrideStatus = SecOC_GetVerifyOverrideStatus(freshnessId);

  switch (verifyOverrideStatus)
  {
# if (SECOC_ENABLE_FORCED_PASS_OVERRIDESTATUS == STD_ON)
    case SECOC_PASS_VERIFYOVERRIDESTATUS:
      verificationResult = SECOC_E_VER_OK;
      SecOC_DecNumberOfMessagesToOverride(freshnessId);
      if(SecOC_GetNumberOfMessagesToOverride(freshnessId) == 0)
      {
        SecOC_SetVerifyOverrideStatus(freshnessId, SECOC_CANCEL_VERIFYOVERRIDESTATUS);
      }
      break;
# endif
    case SECOC_FAIL_N_TIMES_VERIFYOVERRIDESTATUS:
      SecOC_DecNumberOfMessagesToOverride(freshnessId);
      if(SecOC_GetNumberOfMessagesToOverride(freshnessId) == 0)
      {
        SecOC_SetVerifyOverrideStatus(freshnessId, SECOC_CANCEL_VERIFYOVERRIDESTATUS);
      }
      break;
    default:   /* COV_SECOC_MISRA */
      break;
  }

  SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE);
  return verificationResult;
}
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_ProcessVerificationResult
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Verify_ProcessVerificationResult(SecOC_VerifyResultType verificationResult, SecOC_RxPduInfoIterType rxPduId)
{
  if(verificationResult == SECOC_E_VER_OK)
  {
    /* --- Hand the Authentic Pdu to the Upper Layer --- */
    PduInfoType pduInfo;
    pduInfo.SduDataPtr = SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo(rxPduId));
    pduInfo.SduLength = (PduLengthType) SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo(rxPduId);
    SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();
# if (SECOC_EXISTS_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO == STD_ON)
    if(SecOC_GetVerificationStatusPropagationModeOfRxPduInfo(rxPduId) == SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO)
    {
      SecOC_Verify_PropagateVerificationStatus(rxPduId, SECOC_VERIFICATIONSUCCESS);
    }
# endif
    PduR_SecOCRxIndication(SecOC_GetAuthenticExternalIdOfRxPduInfo(rxPduId), &pduInfo);
    SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();
# if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
    SecOC_FreshnessValue_SetValue(SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId), SecOC_FreshnessValue_GetVerifyValueFromBuffer(rxPduId));
# endif
    SecOC_SetRxPduState(rxPduId, SECOC_VERIFIED_RXPDUSTATE);
  }
  else
  {
# if ((SECOC_EXISTS_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO == STD_ON) || (SECOC_EXISTS_FAILURE_ONLY_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO == STD_ON))
#  if(SECOC_EXISTS_NONE_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO == STD_ON)
    if(SecOC_GetVerificationStatusPropagationModeOfRxPduInfo(rxPduId) != SECOC_NONE_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO)
#  endif
    {
      SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();
      SecOC_Verify_PropagateVerificationStatus(rxPduId, SECOC_VERIFICATIONFAILURE);
      SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();
    }
# endif
    SecOC_IncVerifyAttemptsCounter(rxPduId);

# if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
    SecOC_FreshnessValue_UpdateVerifyValueInBuffer(rxPduId);
# else
    SecOC_FreshnessValue_CalculateVerifyValueFromCallout(rxPduId);
# endif
    if(SecOC_GetVerifyAttemptsCounter(rxPduId) < SecOC_GetVerifyAttemptsOfRxPduInfo(rxPduId))
    {
      SecOC_SetRxBuildAttemptsCounter(rxPduId, 0);
      SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_VERIFICATION_TO_BE_STARTED_RXPDUSTATE);
    }
    else
    {
      SecOC_SetRxPduState(rxPduId, SECOC_IDLE_RXPDUSTATE);
    }
  }
}
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_MAC
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Verify_MAC(SecOC_RxPduInfoIterType rxPduId)
{
  if(SecOC_GetRxPduState(rxPduId) == SECOC_COPY_AUTHENTIC_PDU_TO_DATA_TO_AUTHENTICATE_RXPDUSTATE)
  {
    SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_RXSTATE();
    VStdMemCpyRamToRam(SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo(rxPduId)), SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo(rxPduId)), SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo(rxPduId));
    SecOC_SetRxPduState(rxPduId, SECOC_FRESHNESS_VALUE_NEEDED_RXPDUSTATE);
    SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_RXSTATE();
  }

  if(SecOC_GetRxPduState(rxPduId) == SECOC_FRESHNESS_VALUE_NEEDED_RXPDUSTATE)
  {
    /* --- calculate FreshnessVerifyValue --- */
# if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
    SecOC_FreshnessValue_CalculateVerifyValue(rxPduId);
    SecOC_SetRxPduState(rxPduId, SECOC_UNVERIFIED_RXPDUSTATE);
# else
    SecOC_FreshnessValue_CalculateVerifyValueFromCallout(rxPduId);
# endif
  }

  /* --- calculate MAC and verify the Secured Pdu --- */

  /* calculate the MAC with the referenced key and Crypto Library and compare the calculated MAC with the received MAC of the Secured PDU. */
  if(SecOC_IsRxPduStateUnverified(rxPduId))
  {
    SecOC_VerifyResultType verificationResult = SECOC_E_VER_NOT_OK;
    SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();

# if (SECOC_CRYPTOSERVICEOFRXPDUINFO == STD_ON)
    if(SecOC_GetVerifyOverrideStatus(SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId)) == SECOC_CANCEL_VERIFYOVERRIDESTATUS)
    {
      switch (SecOC_GetCryptoServiceOfRxPduInfo(rxPduId))
      {
#  if (SECOC_EXISTS_CAL_CRYPTOSERVICEOFRXPDUINFO == STD_ON)
        case SECOC_CAL_CRYPTOSERVICEOFRXPDUINFO:
        {
          verificationResult = SecOC_Verify_MACUsingCAL(rxPduId);
        }
          break;
#  endif
#  if (SECOC_EXISTS_CSM_CRYPTOSERVICEOFRXPDUINFO == STD_ON)
        case SECOC_CSM_CRYPTOSERVICEOFRXPDUINFO:
        {
          verificationResult = SecOC_Verify_MACUsingCSM(rxPduId);
        }
          break;
#  endif
#  if (SECOC_EXISTS_CSM_43_CRYPTOSERVICEOFRXPDUINFO == STD_ON)
        case SECOC_CSM_43_CRYPTOSERVICEOFRXPDUINFO:
        {
          verificationResult = SecOC_Verify_MACUsingCSM43(rxPduId);
        }
          break;
#  endif
        default:       /* COV_SECOC_MISRA */
          break;
      }
    }
    else
    {
      verificationResult = SecOC_Verify_GetVerificationResultOfOverrideStatus(rxPduId);
    }
# endif

    if(SecOC_GetRxPduState(rxPduId) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE)
    {
# if(SECOC_IGNORE_VERIFICATION_RESULT == STD_ON)
      verificationResult = SECOC_E_VER_OK;
# endif
      SecOC_Verify_ProcessVerificationResult(verificationResult, rxPduId);
    }

    if((SecOC_GetRxPduState(rxPduId) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE) || (SecOC_GetRxPduState(rxPduId) == SECOC_VERIFIED_RXPDUSTATE))
    {
      SecOC_SetRxPduState(rxPduId, SECOC_IDLE_RXPDUSTATE);
    }

    SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();
  }
}  /* PRQA S 6050, 6010 */ /* MD_MSR_STCAL, MD_MSR_STPTH */
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_RxIf_HandlePdus
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_RxIf_HandlePdus(void)
{
  /* Verify the received Secured I-Pdus and hand the Authentic I-Pdus to the UpperLayer. */
  SecOC_RxPduInfoIterType rxPduId = 0;
  for(; rxPduId < SecOC_GetSizeOfRxPduInfo(); rxPduId++)
  {
    if(SecOC_GetRxPduState(rxPduId) != SECOC_IDLE_RXPDUSTATE)
    {
      SecOC_Verify_MAC(rxPduId);
    }
  }
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetMostSignificantBitsOfRxFreshnessValue
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetMostSignificantBitsOfRxFreshnessValue(SecOC_RxPduInfoIterType rxPduId)
{
  return (SecOC_FreshnessValue_GetValue(SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId)) & SecOC_GetFreshnessValueInvertedMaskOfRxPduInfo(rxPduId));
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetLeastSignificantBitsOfRxFreshnessValue
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetLeastSignificantBitsOfRxFreshnessValue(SecOC_RxPduInfoIterType rxPduId)
{
  return (SecOC_FreshnessValue_GetValue(SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId)) & SecOC_GetFreshnessValueMaskOfRxPduInfo(rxPduId));
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && ((SECOC_QUERY_FRESHNESS_VALUE == SECOC_CFUNC) || (SECOC_QUERY_FRESHNESS_VALUE == SECOC_RTE)))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetVerifyValueFromCallout
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValue_GetVerifyValueFromCallout(SecOC_RxPduInfoIterType rxPduId, uint8 * freshnessValue)
{
  Std_ReturnType ret;
# if ((SECOC_EXISTS_USE_AUTHDATAFRESHNESSOFRXPDUINFO == STD_ON) && (SECOC_EXISTS_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO == STD_ON))
  if(SecOC_GetAuthDataFreshnessOfRxPduInfo(rxPduId) == SECOC_USE_AUTHDATAFRESHNESSOFRXPDUINFO)
# endif
# if (SECOC_EXISTS_USE_AUTHDATAFRESHNESSOFRXPDUINFO == STD_ON)
  {
    uint8 truncatedFreshnessValue[SECOC_TRUNC_FRESHNESS_SIZE_RXPDUS] = { 0 };
    uint32 freshnessValueLength = (uint32) (SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo(rxPduId) << 3U);

    SecOC_FreshnessValue_GetParsedFreshnessValue(rxPduId, truncatedFreshnessValue);
    /* *INDENT-OFF* */
    ret = GetRxFreshnessAuthData_FuncName(
      SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId),
      truncatedFreshnessValue,
      SecOC_GettruncatedFreshnessValueLengthOfRxPduInfo(rxPduId),
      SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo(rxPduId) + SecOC_GetAuthDataFreshnessStartBytePositionOfRxPduInfo(rxPduId)),
      SecOC_GetAuthDataFreshnessLenOfRxPduInfo(rxPduId),
      (uint16) SecOC_GetVerifyAttemptsCounter(rxPduId),
      freshnessValue,
      &freshnessValueLength
    );
    /* *INDENT-ON* */
  }
# endif
# if ((SECOC_EXISTS_USE_AUTHDATAFRESHNESSOFRXPDUINFO == STD_ON) && (SECOC_EXISTS_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO == STD_ON))
  else
# endif
# if (SECOC_EXISTS_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO == STD_ON)
  {
    uint8 truncatedFreshnessValue[SECOC_TRUNC_FRESHNESS_SIZE_RXPDUS] = { 0 };
    uint32 freshnessValueLength = (uint32) (SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo(rxPduId) << 3U);

    SecOC_FreshnessValue_GetParsedFreshnessValue(rxPduId, truncatedFreshnessValue);
    /* *INDENT-OFF* */
    ret = GetRxFreshness_FuncName(
      SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId),
      truncatedFreshnessValue,
      SecOC_GettruncatedFreshnessValueLengthOfRxPduInfo(rxPduId),
      (uint16) SecOC_GetVerifyAttemptsCounter(rxPduId),
      freshnessValue,
      &freshnessValueLength
   );
    /* *INDENT-ON* */
  }
# endif
  return ret;
}
#endif

#if ((SECOC_RXPDUINFO == STD_ON) && (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE))
/**********************************************************************************************************************
  SecOC_FreshnessValue_GetVerifyValue
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(SecOC_FreshnessValueType, SECOC_CODE) SecOC_FreshnessValue_GetVerifyValue(SecOC_RxPduInfoIterType rxPduId, SecOC_FreshnessValueType parsedFreshnessValue)
{
  SecOC_FreshnessValueType ret;
# if (SECOC_ISFRESHNESSVALUETRUNCATEDOFRXPDUINFO == STD_ON)
  if(SecOC_IsIsFreshnessValueTruncatedOfRxPduInfo(rxPduId))
  {
    if(parsedFreshnessValue > SecOC_FreshnessValue_GetLeastSignificantBitsOfRxFreshnessValue(rxPduId))
    {
      ret = SecOC_FreshnessValue_GetMostSignificantBitsOfRxFreshnessValue(rxPduId) | parsedFreshnessValue;
    }
    else
    {
      ret = (SecOC_FreshnessValue_GetMostSignificantBitsOfRxFreshnessValue(rxPduId) + SecOC_GetFreshnessMostSignificantIncValueOfRxPduInfo(rxPduId)) | parsedFreshnessValue;
    }
  }
  else
# endif /* (SECOC_ISFRESHNESSVALUETRUNCATEDOFRXPDUINFO == STD_ON) */
  {
    ret = parsedFreshnessValue;
  }
  return ret;
}
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_RxIf_InitPdus
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_RxIf_InitPdus(void)
{
  SecOC_RxPduInfoIterType rxPduId = 0;
  for(; rxPduId < SecOC_GetSizeOfRxPduInfo(); rxPduId++)
  {
    SecOC_SetAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataIdFirstByteIdxOfRxPduInfo(rxPduId), SecOC_GetDataIdFirstByteOfRxPduInfo(rxPduId));
    SecOC_SetAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataIdSecondByteIdxOfRxPduInfo(rxPduId), SecOC_GetDataIdSecondByteOfRxPduInfo(rxPduId));
    SecOC_SetVerifyAttemptsCounter(rxPduId, 0);
    SecOC_SetRxBuildAttemptsCounter(rxPduId, 0);
    SecOC_SetRxTpWrittenBytesCounter(rxPduId, 0);
    SecOC_SetVerifyOverrideStatus(SecOC_GetexternalFreshnessIdOfRxPduInfo(rxPduId), SECOC_CANCEL_VERIFYOVERRIDESTATUS);
  }
}
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_TxIf_InitPdus
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_TxIf_InitPdus(void)
{
  SecOC_TxPduInfoIterType txPduId = 0;
  for(; txPduId < SecOC_GetSizeOfTxPduInfo(); txPduId++)
  {
    SecOC_SetAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataIdFirstByteIdxOfTxPduInfo(txPduId), SecOC_GetDataIdFirstByteOfTxPduInfo(txPduId));
    SecOC_SetAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerDataIdSecondByteIdxOfTxPduInfo(txPduId), SecOC_GetDataIdSecondByteOfTxPduInfo(txPduId));
    SecOC_SetTxBuildAttemptsCounter(txPduId, 0);
    SecOC_SetTxTpWrittenBytesCounter(txPduId, 0);
    SecOC_SetVerifyOverrideStatus(SecOC_GetexternalFreshnessIdOfTxPduInfo(txPduId), SECOC_CANCEL_VERIFYOVERRIDESTATUS);
  }
}
#endif

#if (SECOC_CURRENTMESSAGELINKER == STD_ON)
/**********************************************************************************************************************
  SecOC_Split_ExtractMessageLinker
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(void, SECOC_CODE) SecOC_Split_ExtractMessageLinker(P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) msgLinkSrc, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) msgLinkDest, uint16 msgLinkLen, uint16 msgLinkBitInByteOffset)
{
  uint16 NumberOfBytesToCopy = (uint16) (msgLinkLen >> 3U);
  uint16_least i = 0;
  if((msgLinkLen & 7U) != 0)
  {
    NumberOfBytesToCopy++;
  }

  for(; i < NumberOfBytesToCopy; i++)
  {
    uint8 byteToCopy = 0;
    if(msgLinkBitInByteOffset != 0)
    {
      uint8 numLeftShift = 8 - msgLinkBitInByteOffset;
      uint8 numRightShift = msgLinkBitInByteOffset;
      byteToCopy = (uint8) (msgLinkSrc[i] << numLeftShift);
      byteToCopy = byteToCopy | ((uint8) (msgLinkSrc[i + 1] >> numRightShift));
    }
    else
    {
      byteToCopy = msgLinkSrc[i];
    }

    msgLinkDest[i] = byteToCopy;
  }
}
#endif

#if (SECOC_CURRENTMESSAGELINKER == STD_ON)
/**********************************************************************************************************************
  SecOC_Split_CheckMessageLinker
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, SECOC_CODE) SecOC_Split_CheckMessageLinker(P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) msgLinkNew, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) msgLinkOld, SecOC_MessageLinkLenOfRxSecuredPduInfoType msgLinkLenInBytes)
{

  boolean ret = TRUE;
  uint16_least i = 0;

  for(; i < msgLinkLenInBytes; i++)
  {
    if(msgLinkNew[i] != msgLinkOld[i])
    {
      ret = FALSE;
      break;
    }
  }

  if(ret == FALSE)
  {
    VStdMemCpyRamToRam(msgLinkOld, msgLinkNew, msgLinkLenInBytes);
  }

  return ret;
}
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_IncrementAndCheckBuildAttempts
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_Authenticate_IncrementAndCheckBuildAttempts(SecOC_TxPduInfoIterType txPduId)
{
  SecOC_IncTxBuildAttemptsCounter(txPduId);
  if(SecOC_GetTxBuildAttemptsCounter(txPduId) >= SecOC_GetBuildAttemptsOfTxPduInfo(txPduId))
  {
    SecOC_SetTxPduState(txPduId, SECOC_INVALID_SECURED_PDU_TXPDUSTATE);
    SecOC_SetTransmitRequest(txPduId, SECOC_IDLE_TRANSMITREQUEST);
# if (SECOC_TXSPLITPDUINFO == STD_ON)
    if(SecOC_IsTxSplitPduInfoUsedOfTxPduInfo(txPduId))
    {
      SecOC_SizeOfTxSplitPduInfoType splitTxPduId = SecOC_GetTxSplitPduInfoIdxOfTxPduInfo(txPduId);
      SecOC_SetAuthenticSplitPduTransmit(splitTxPduId, SECOC_TRANSMIT_AUTHENTICSPLITPDUTRANSMIT);
      SecOC_SetCryptographicPduTransmit(splitTxPduId, SECOC_TRANSMIT_AUTHENTICSPLITPDUTRANSMIT);
    }
# endif
  }
}
#endif

#if (SECOC_RXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Verify_IncrementBuildAttempts
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_Verify_IncrementBuildAttempts(SecOC_RxPduInfoIterType rxPduId)
{
  SecOC_IncRxBuildAttemptsCounter(rxPduId);
  if(SecOC_GetRxBuildAttemptsCounter(rxPduId) >= SecOC_GetBuildAttemptsOfRxPduInfo(rxPduId))
  {
    SecOC_SetRxPduState(rxPduId, SECOC_IDLE_RXPDUSTATE);
  }
}
#endif

#if (SECOC_TXPDUINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_Authenticate_CopyAuthenticatorToSecuredPdu
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_Authenticate_CopyAuthenticatorToSecuredPdu(SecOC_TxPduInfoIterType txPduId, P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) authenticatorArray)
{
  SecOC_truncatedAuthenticationLengthOfTxPduInfoType bitsToCopy = SecOC_GettruncatedAuthenticationLengthOfTxPduInfo(txPduId);
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfoType destIdx = SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo(txPduId);
  uint8 msbBitOffset = SecOC_GetTruncatedAuthenticatorShiftOffestForMsbOfTxPduInfo(txPduId);
  uint8 lsbBitOffset = SecOC_GetTruncatedAuthenticatorShiftOffestForLsbOfTxPduInfo(txPduId);
  uint8 srcIdx = 0;

  for(; destIdx < SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfo(txPduId); destIdx++)
  {
    if((bitsToCopy & 7U) != 0)
    {
      uint8 byteToWrite = 0;
      uint8 copyMask = (uint8) (255U << lsbBitOffset);
      byteToWrite = (uint8) (authenticatorArray[srcIdx] >> msbBitOffset);
      byteToWrite = (SecOC_GetSecuredPduDataContainer(destIdx) & copyMask) | byteToWrite;
      SecOC_SetSecuredPduDataContainer(destIdx, byteToWrite);

      bitsToCopy = bitsToCopy - (bitsToCopy & 7U);
    }
    else
    {
      if(msbBitOffset != 0)
      {
        uint8 byteToWrite = 0;
        byteToWrite = (uint8) (authenticatorArray[srcIdx] >> msbBitOffset);
        byteToWrite = byteToWrite | ((uint8) (authenticatorArray[srcIdx - 1] << lsbBitOffset));
        SecOC_SetSecuredPduDataContainer(destIdx, byteToWrite);
      }
      else
      {
        SecOC_SetSecuredPduDataContainer(destIdx, authenticatorArray[srcIdx]);
      }
      bitsToCopy = bitsToCopy - 8;
    }
    srcIdx++;
  }
}
#endif

/**********************************************************************************************************************
  SecOC_InitMemory
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  SecOC_SetInitialized(FALSE);
#if(SECOC_USE_INIT_POINTER == STD_ON)
  SecOC_ConfigDataPtr = NULL_PTR;
#endif
}

/**********************************************************************************************************************
  SecOC_DeInit
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_DeInit(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    SecOC_SetInitialized(FALSE);
#if(SECOC_USE_INIT_POINTER == STD_ON)
    SecOC_ConfigDataPtr = NULL_PTR;
#endif
  }

#if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_DE_INIT, errorId);
  }
#endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}

/**********************************************************************************************************************
  SecOC_Init
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_Init(P2CONST(SecOC_ConfigType, AUTOMATIC, SECOC_PBCFG) config)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  if(SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
  else
  {
    /* --- parameter check --- */
#if(SECOC_USE_INIT_POINTER == STD_ON)
    SecOC_ConfigDataPtr = config;
    /* Check validtity of Config pointer */
    if(SecOC_ConfigDataPtr == NULL_PTR)
    {
      EcuM_BswErrorHook(SECOC_MODULE_ID, ECUM_BSWERROR_NULLPTR);
      errorId = SECOC_E_PARAM_POINTER;
    }
# if (SECOC_FINALMAGICNUMBER == STD_ON)
    else if(SecOC_GetFinalMagicNumber() != SECOC_FINAL_MAGIC_NUMBER)
    {
      EcuM_BswErrorHook(SECOC_MODULE_ID, ECUM_BSWERROR_MAGICNUMBER);
      errorId = SECOC_E_PARAM_POINTER;
      SecOC_ConfigDataPtr = NULL_PTR;
    }
# endif
#else
    if(NULL_PTR != config)
    {
      errorId = SECOC_E_PARAM_POINTER;
    }
#endif
    else
    {
      /* ----- Implementation ----------------------------------------------- */
      /* The Freshness Values and Key values are read during NVRAM ReadAll() */
#if (SECOC_RXPDUINFO == STD_ON)
      SecOC_RxIf_InitPdus();
#endif
#if(SECOC_TXPDUINFO == STD_ON)
      SecOC_TxIf_InitPdus();
#endif
#if (SECOC_RXPDUSTATE == STD_ON)
      {
        SecOC_RxPduStateIterType pduStateIdx = 0;
        for(; pduStateIdx < SecOC_GetSizeOfRxPduState(); pduStateIdx++)
        {
          SecOC_SetRxPduState(pduStateIdx, SECOC_IDLE_RXPDUSTATE);
        }
      }
#endif
#if (SECOC_TXPDUSTATE == STD_ON)
      {
        SecOC_TxPduStateIterType pduStateIdx = 0;
        for(; pduStateIdx < SecOC_GetSizeOfTxPduState(); pduStateIdx++)
        {
          SecOC_SetTxPduState(pduStateIdx, SECOC_INVALID_SECURED_PDU_TXPDUSTATE);
        }
      }
#endif
#if (SECOC_VERIFYRESULT == STD_ON)
      {
        SecOC_VerifyResultIterType verifyResultIdx = 0;
        for(; verifyResultIdx < SecOC_GetSizeOfVerifyResult(); verifyResultIdx++)
        {
          SecOC_SetVerifyResult(verifyResultIdx, CSM_E_VER_NOT_OK);
        }
      }
#endif
#if(SECOC_KEYSTATE == STD_ON)
      {
        SecOC_KeyStateIterType keyIdx = 0;
        for(; keyIdx < SecOC_GetSizeOfKeyState(); keyIdx++)
        {
          SecOC_SetKeyState(keyIdx, SECOC_UNASSIGNED_KEYSTATE);
        }
      }
#endif
      SecOC_SetInitialized(TRUE);
    }
  }

#if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_INIT, errorId);
  }
#endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if (SECOC_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  SecOC_GetVersionInfo
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SECOC_APPL_DATA) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if(SECOC_DEV_ERROR_DETECT == STD_ON)
  if(versioninfo == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    versioninfo->vendorID = (SECOC_VENDOR_ID);
    versioninfo->moduleID = (SECOC_MODULE_ID);
    versioninfo->sw_major_version = (SECOC_SW_MAJOR_VERSION);
    versioninfo->sw_minor_version = (SECOC_SW_MINOR_VERSION);
    versioninfo->sw_patch_version = (SECOC_SW_PATCH_VERSION);
  }

  /* ----- Development Error Report --------------------------------------- */
# if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_GET_VERSION_INFO, errorId);
  }
# endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif

/**********************************************************************************************************************
  SecOC_Transmit
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_Transmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;
  Std_ReturnType ret = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
#if(SECOC_DEV_ERROR_DETECT == STD_ON)
# if(SECOC_TXAUTHENTICPDUINFO == STD_ON)
  else if(id >= SecOC_GetSizeOfTxAuthenticPduInfo())
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#  if(SECOC_INVALIDHNDOFTXAUTHENTICPDUINFO == STD_ON)
  else if(SecOC_IsInvalidHndOfTxAuthenticPduInfo(id))
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#  endif
# endif
  else if(info == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
  else if(info->SduDataPtr == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
# if(SECOC_TXAUTHENTICPDUINFO == STD_ON)
  else if(info->SduLength != SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo(SecOC_GetTxPduInfoIdxOfTxAuthenticPduInfo(id)))
  {
    errorId = SECOC_E_PARAM;
  }
# endif
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if(SECOC_TXAUTHENTICPDUINFO == STD_ON)
    SecOC_TxPduInfoIterType txPduInfoIdx = SecOC_GetTxPduInfoIdxOfTxAuthenticPduInfo(id);
# if(SECOC_ENABLE_KEY_INTERFACE == STD_ON)
    if(SecOC_KeyMgt_isKeyAssigned(txPduInfoIdx) == TRUE)
# endif
    {
      if(SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo(txPduInfoIdx) == info->SduLength)
      {
        SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
        /* --- Reevaluate the Pdu state --- */
        if((SecOC_GetTxPduState(txPduInfoIdx) == SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE) || (SecOC_GetTxPduState(txPduInfoIdx) == SECOC_TRANSMISSION_INITIATED_TXPDUSTATE) || (SecOC_GetTxPduState(txPduInfoIdx) == SECOC_TRIGGER_TRANSMIT_TXPDUSTATE) || (SecOC_GetTxPduState(txPduInfoIdx) == SECOC_AUTHENTICATED_TXPDUSTATE))
        {
          SecOC_SetTxPduState(txPduInfoIdx, SECOC_INVALID_SECURED_PDU_TXPDUSTATE);
        }
        if(SecOC_GetTxPduState(txPduInfoIdx) == SECOC_INVALID_SECURED_PDU_TXPDUSTATE)
        {
          /* --- Copy the Authentic Pdu into an internal Buffer --- */
          VStdMemCpyRamToRam(SecOC_GetAddrAuthenticPduDataContainer(SecOC_GetAuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfo(txPduInfoIdx)), info->SduDataPtr, SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo(txPduInfoIdx));
          /* Reset Tx Sync Attempts Counter */
          SecOC_SetTxBuildAttemptsCounter(txPduInfoIdx, 0);
          /* --- Set the Tx Pdu State to "Reauthentication needed" --- */
          SecOC_SetTxPduState(txPduInfoIdx, SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE);
          /* Set the Transmit Request state of the corresponding Pdu to Transmit */
          /* --- Set the Transmit request --- */
          SecOC_SetTransmitRequest(txPduInfoIdx, SECOC_TRANSMIT_TRANSMITREQUEST);
# if (SECOC_TXSPLITPDUINFO == STD_ON)
          if(SecOC_IsTxSplitPduInfoUsedOfTxPduInfo(txPduInfoIdx))
          {
            SecOC_SizeOfTxSplitPduInfoType splitTxPduId = SecOC_GetTxSplitPduInfoIdxOfTxPduInfo(txPduInfoIdx);
            SecOC_SetAuthenticSplitPduTransmit(splitTxPduId, SECOC_TRANSMIT_AUTHENTICSPLITPDUTRANSMIT);
            SecOC_SetCryptographicPduTransmit(splitTxPduId, SECOC_TRANSMIT_AUTHENTICSPLITPDUTRANSMIT);
          }
# endif
          /* --- return E_OK --- */
          ret = E_OK;
        }
        SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
      }
    }
#else
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_TRANSMIT, errorId);
  }
#endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return ret;
}  /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

#if (SECOC_COMMUNICATION_INTERFACE == STD_ON)
/**********************************************************************************************************************
  SecOC_RxIndication
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_RxIndication(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
# if(SECOC_DEV_ERROR_DETECT == STD_ON)
#  if(SECOC_RXSECUREDPDUINFO == STD_ON)
  else if(id >= SecOC_GetSizeOfRxSecuredPduInfo())
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   if(SECOC_INVALIDHNDOFRXSECUREDPDUINFO == STD_ON)
  else if(SecOC_IsInvalidHndOfRxSecuredPduInfo(id))
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   endif
#  endif
  else if(info == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
  else if(info->SduDataPtr == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
#  if((SECOC_RXSECUREDPDUINFO == STD_ON) && (SECOC_EXISTS_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO == STD_ON))
  else if((SecOC_GetMessageTypeOfRxSecuredPduInfo(id) == SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO) && (info->SduLength != SecOC_GetSecuredPduDataContainerLengthOfRxSecuredPduInfo(id)))
  {
    errorId = SECOC_E_PARAM;
  }
#  endif
#  if((SECOC_RXSECUREDPDUINFO == STD_ON) && (SECOC_EXISTS_AUTHENTIC_SPLIT_MESSAGETYPEOFRXSECUREDPDUINFO == STD_ON))
  else if((SecOC_GetMessageTypeOfRxSecuredPduInfo(id) == SECOC_AUTHENTIC_SPLIT_MESSAGETYPEOFRXSECUREDPDUINFO) && (info->SduLength != SecOC_GetSecuredPduDataContainerLengthOfRxSecuredPduInfo(id)))
  {
    errorId = SECOC_E_PARAM;
  }
#  endif
#  if((SECOC_RXSECUREDPDUINFO == STD_ON) && (SECOC_EXISTS_CRYPTOGRAPHIC_MESSAGETYPEOFRXSECUREDPDUINFO == STD_ON))
  else if((SecOC_GetMessageTypeOfRxSecuredPduInfo(id) == SECOC_CRYPTOGRAPHIC_MESSAGETYPEOFRXSECUREDPDUINFO) && (info->SduLength != SecOC_GetSecuredPduDataContainerLengthOfRxSecuredPduInfo(id)))
  {
    errorId = SECOC_E_PARAM;
  }
#  endif
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if(SECOC_RXSECUREDPDUINFO == STD_ON)
    boolean isNewCompletMsg = TRUE;
    SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_RXSTATE();
    switch (SecOC_GetMessageTypeOfRxSecuredPduInfo(id))
    {
#  if(SECOC_EXISTS_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO == STD_ON)
      case SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO:
      {
        VStdMemCpyRamToRam(SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerStartIdxOfRxSecuredPduInfo(id)), info->SduDataPtr, SecOC_GetSecuredPduDataContainerLengthOfRxSecuredPduInfo(id));
        break;
      }
#  endif
#  if (SECOC_EXISTS_AUTHENTIC_SPLIT_MESSAGETYPEOFRXSECUREDPDUINFO == STD_ON)
      case SECOC_AUTHENTIC_SPLIT_MESSAGETYPEOFRXSECUREDPDUINFO:
      {
#   if (SECOC_CURRENTMESSAGELINKER == STD_ON)
        uint8 messageLinker[SECOC_MESSAGE_LINKER_SIZE_RXPDUS];
        SecOC_Split_ExtractMessageLinker(&(info->SduDataPtr[((PduLengthType) (SecOC_GetMessageLinkPosOfRxSecuredPduInfo(id) >> 3U))]), messageLinker, SecOC_GetMessageLinkLenOfRxSecuredPduInfo(id), (SecOC_GetMessageLinkPosOfRxSecuredPduInfo(id) & 7U));
        isNewCompletMsg = SecOC_Split_CheckMessageLinker(messageLinker, SecOC_GetAddrCurrentMessageLinker(SecOC_GetCurrentMessageLinkerStartIdxOfRxSecuredPduInfo(id)), SecOC_GetCurrentMessageLinkerLengthOfRxSecuredPduInfo(id));
#   endif
        VStdMemCpyRamToRam(SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerStartIdxOfRxSecuredPduInfo(id)), info->SduDataPtr, SecOC_GetSecuredPduDataContainerLengthOfRxSecuredPduInfo(id));
        break;
      }
#  endif
#  if (SECOC_EXISTS_CRYPTOGRAPHIC_MESSAGETYPEOFRXSECUREDPDUINFO == STD_ON)
      case SECOC_CRYPTOGRAPHIC_MESSAGETYPEOFRXSECUREDPDUINFO:
      {
#   if (SECOC_CURRENTMESSAGELINKER == STD_ON)
        isNewCompletMsg = SecOC_Split_CheckMessageLinker(&(info->SduDataPtr[(info->SduLength - SecOC_GetCurrentMessageLinkerLengthOfRxSecuredPduInfo(id))]), SecOC_GetAddrCurrentMessageLinker(SecOC_GetCurrentMessageLinkerStartIdxOfRxSecuredPduInfo(id)), SecOC_GetCurrentMessageLinkerLengthOfRxSecuredPduInfo(id));
#   endif
        VStdMemCpyRamToRam(SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerStartIdxOfRxSecuredPduInfo(id)), info->SduDataPtr, SecOC_GetSecuredPduDataContainerLengthOfRxSecuredPduInfo(id));
        break;
      }
#  endif
      default: /* COV_SECOC_MISRA */
        break;
    }

    if(isNewCompletMsg == TRUE)
    {
      SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(id);
      /* --- Set the state of the corresponding PDU to Unverified --- */
      SecOC_SetRxPduState(rxPduInfoIdx, SECOC_COPY_AUTHENTIC_PDU_TO_DATA_TO_AUTHENTICATE_RXPDUSTATE);
      SecOC_SetVerifyAttemptsCounter(rxPduInfoIdx, 0);
      SecOC_SetRxBuildAttemptsCounter(rxPduInfoIdx, 0);
    }
    SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_RXSTATE();
# else
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_RX_INDICATION, errorId);
  }
# endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}  /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */

# if (SECOC_TX_CONFIRMATION_API == STD_ON)
/**********************************************************************************************************************
  SecOC_TxConfirmation
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_TxConfirmation(PduIdType id)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
#  if(SECOC_DEV_ERROR_DETECT == STD_ON)
#   if(SECOC_TXSECUREDPDUINFO == STD_ON)
  else if(id >= SecOC_GetSizeOfTxSecuredPduInfo())
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#    if(SECOC_INVALIDHNDOFTXSECUREDPDUINFO == STD_ON)
  else if(SecOC_IsInvalidHndOfTxSecuredPduInfo(id))
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#    endif
#   endif
#  endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#  if(SECOC_TXSECUREDPDUINFO == STD_ON)
    SecOC_TxPduInfoIterType txPduInfoIdx = SecOC_GetTxPduInfoIdxOfTxSecuredPduInfo(id);
    /* --- Action: SecOC_TxConfirmation --- */
    /* --- Call PduR_SecOCTxConfirmation --- */
#   if( SECOC_CONFIRMATIONNEEDEDOFTXPDUINFO == STD_ON)
    if(SecOC_IsConfirmationNeededOfTxPduInfo(txPduInfoIdx))
    {
      PduR_SecOCTxConfirmation(SecOC_GetAuthenticExternalIdOfTxPduInfo(txPduInfoIdx));
    }
#   endif
    SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
    switch (SecOC_GetTxPduState(txPduInfoIdx))
    {
      case SECOC_TRANSMISSION_INITIATED_TXPDUSTATE:
        SecOC_SetTxPduState(txPduInfoIdx, SECOC_INVALID_SECURED_PDU_TXPDUSTATE);
        break;
      case SECOC_TRIGGER_TRANSMIT_TXPDUSTATE:
        /* Reset Tx Sync Attempts Counter */
        SecOC_SetTxBuildAttemptsCounter(txPduInfoIdx, 0);
        SecOC_SetTxPduState(txPduInfoIdx, SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE);
        break;
      default: /* COV_SECOC_MISRA */
        break;
    }
    SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
#  else
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
#  endif
  }

  /* ----- Development Error Report --------------------------------------- */
#  if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_TX_CONFIRMATION, errorId);
  }
#  endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}
# endif

# if (SECOC_TRIGGER_TRANSMIT_API == STD_ON)
/**********************************************************************************************************************
  SecOC_TriggerTransmit
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *

 *
**********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_TriggerTransmit(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, SECOC_APPL_VAR) info)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;
  Std_ReturnType ret = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
#  if(SECOC_DEV_ERROR_DETECT == STD_ON)
#   if(SECOC_TXSECUREDPDUINFO == STD_ON)
  else if(id >= SecOC_GetSizeOfTxSecuredPduInfo())
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#    if(SECOC_INVALIDHNDOFTXSECUREDPDUINFO == STD_ON)
  else if(SecOC_IsInvalidHndOfTxSecuredPduInfo(id))
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#    endif
#   endif
  else if(info == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
  else if(info->SduDataPtr == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
#  endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#  if(SECOC_TXSECUREDPDUINFO == STD_ON)
    SecOC_TxPduInfoIterType txPduInfoIdx = SecOC_GetTxPduInfoIdxOfTxSecuredPduInfo(id);
    /* --- Action: SecOC_TriggerTransmit --- */
    /* --- Check state --- */
    /* return E_NOT_OK if the Pdu has not the state "Authenticated" or "transmission initiated" */
    if(info->SduLength >= SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(SecOC_GetTxPduInfoIdxOfTxSecuredPduInfo(id)))
    {
      SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
      if((SecOC_GetTxPduState(txPduInfoIdx) == SECOC_AUTHENTICATED_TXPDUSTATE) || (SecOC_GetTxPduState(txPduInfoIdx) == SECOC_TRANSMISSION_INITIATED_TXPDUSTATE))
      {
        /* --- copy data --- */
        /* --- update state and Freshness Value if required --- */
        switch (SecOC_GetTxPduState(txPduInfoIdx))
        {
          case SECOC_AUTHENTICATED_TXPDUSTATE:
#   if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
            SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_FRESHNESS_VALUE();
            SecOC_FreshnessValue_IncValue(SecOC_GetexternalFreshnessIdOfTxPduInfo(txPduInfoIdx));
            SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_FRESHNESS_VALUE();
#   endif
            VStdMemCpyRamToRam(info->SduDataPtr, SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo(txPduInfoIdx)), SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(txPduInfoIdx));
            info->SduLength = (PduLengthType) SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(txPduInfoIdx);
            SecOC_SetTxPduState(txPduInfoIdx, SECOC_TRIGGER_TRANSMIT_TXPDUSTATE);
            break;
          case SECOC_TRANSMISSION_INITIATED_TXPDUSTATE:
            VStdMemCpyRamToRam(info->SduDataPtr, SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo(txPduInfoIdx)), SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(txPduInfoIdx));
            info->SduLength = (PduLengthType) SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(txPduInfoIdx);
            SecOC_SetTxPduState(txPduInfoIdx, SECOC_TRIGGER_TRANSMIT_TXPDUSTATE);
            break;
          default:     /* COV_SECOC_MISRA */
            break;
        }
        ret = E_OK;
      }
      SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
    }
#  else
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
#  endif
  }

  /* ----- Development Error Report --------------------------------------- */
#  if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_TRIGGER_TRANSMIT, errorId);
  }
#  endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return ret;
}  /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
# endif
#endif

/**********************************************************************************************************************
  SecOC_FreshnessValueRead
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *

 *
**********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValueRead(uint16 freshnessValueID, P2VAR(uint64, AUTOMATIC, SECOC_APPL_VAR) counterValue)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;
  Std_ReturnType ret = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
#if(SECOC_DEV_ERROR_DETECT == STD_ON)
  else if(counterValue == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
# if (SECOC_FRESHNESSVALUE == STD_ON)
  else if(freshnessValueID >= SECOC_FRESHNESSVALUE_SIZE)
  {
    errorId = SECOC_E_PARAM;
  }
# endif
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
    /* --- Action: SecOC_FreshnessValueRead --- */
    /* write the corresponding FreshnessValue to the conterValue parameter. */
    SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_FRESHNESS_VALUE();
    *counterValue = SecOC_FreshnessValue_GetValue(freshnessValueID);
    SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_FRESHNESS_VALUE();
    ret = E_OK;
#else
    errorId = SECOC_E_PARAM;
#endif
  }
  /* ----- Development Error Report --------------------------------------- */
#if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_FRESHNESS_VALUE_READ, errorId);
  }
#endif
  SECOC_DUMMY_STATEMENT(counterValue);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return ret;
}

/**********************************************************************************************************************
  SecOC_FreshnessValueWrite
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessValueWrite(uint16 freshnessValueID, uint64 counterValue)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;
  Std_ReturnType ret = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
#if(SECOC_DEV_ERROR_DETECT == STD_ON)
# if (SECOC_FRESHNESSVALUE == STD_ON)
  else if(freshnessValueID >= SECOC_FRESHNESSVALUE_SIZE)
  {
    errorId = SECOC_E_PARAM;
  }
# endif
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if (SECOC_QUERY_FRESHNESS_VALUE == SECOC_NONE)
    /* --- Action: SecOC_FreshnessValueWrite --- */
    /* set the corresponding Freshness Value to the parameter counterValue */
    SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_FRESHNESS_VALUE();
    SecOC_FreshnessValue_SetValue(freshnessValueID, counterValue);
    SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_FRESHNESS_VALUE();
    ret = E_OK;
#else
    errorId = SECOC_E_PARAM;
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_FRESHNESS_VALUE_WRITE, errorId);
  }
#endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return ret;
}

#if (SECOC_ENABLE_KEY_INTERFACE == STD_ON)
/**********************************************************************************************************************
  SecOC_AssociateKey
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_AssociateKey(uint8 keyID, P2CONST(SecOC_KeyType, AUTOMATIC, SECOC_APPL_DATA) keyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;
  Std_ReturnType ret = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
# if(SECOC_DEV_ERROR_DETECT == STD_ON)
#  if (SECOC_KEYVALUE == STD_ON)
  else if(keyID >= SecOC_GetSizeOfKeyArray())
  {
    errorId = SECOC_E_PARAM;
  }
#  endif
  else if(keyPtr == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (SECOC_KEYVALUE == STD_ON)
    /* --- Action: SecOC_AssociateKey --- */
    /* copy the keyPtr content to the KeyValue at corresponding keyID. */
    SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();
    {
      uint16_least keyValueIdx = 0;
      for(; keyValueIdx < SECOC_KEY_MAX_SIZE; keyValueIdx++)
      {
        SecOC_GetKeyArray(keyID).data[keyValueIdx] = keyPtr->data[keyValueIdx];
      }
    }
    SecOC_GetKeyArray(keyID).length = keyPtr->length;
    SecOC_SetKeyState(keyID, SECOC_ASSIGNED_KEYSTATE);
    SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_KEY_VALUE();
    ret = E_OK;
# else
    errorId = SECOC_E_PARAM;
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_ASSOCIATE_KEY, errorId);
  }
# endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return ret;
}
#endif

#if (SECOC_TRANSPORT_PROTOCOL == STD_ON)
/**********************************************************************************************************************
  SecOC_TpRxIndication
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_TpRxIndication(PduIdType id, Std_ReturnType result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
# if(SECOC_DEV_ERROR_DETECT == STD_ON)
#  if(SECOC_RXSECUREDPDUINFO == STD_ON)
  else if(id >= SecOC_GetSizeOfRxSecuredPduInfo())
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   if(SECOC_INVALIDHNDOFRXSECUREDPDUINFO == STD_ON)
  else if(SecOC_IsInvalidHndOfRxSecuredPduInfo(id))
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   endif
#  endif
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (SECOC_RXSECUREDPDUINFO == STD_ON)
    SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(id);
    if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_COPYING_RXPDUSTATE)
    {
      if(result == E_OK)
      {
        SecOC_SetRxPduState(rxPduInfoIdx, SECOC_COPY_AUTHENTIC_PDU_TO_DATA_TO_AUTHENTICATE_RXPDUSTATE);
      }
      else
      {
        SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE);
      }
    }
    {
      SecOC_SetRxTpWrittenBytesCounter(rxPduInfoIdx, 0);
    }
# else
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_TP_RX_INDICATION, errorId);
  }
# endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
  SecOC_TpTxConfirmation
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_TpTxConfirmation(PduIdType id, Std_ReturnType result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
# if(SECOC_DEV_ERROR_DETECT == STD_ON)
#  if(SECOC_TXSECUREDPDUINFO == STD_ON)
  else if(id >= SecOC_GetSizeOfTxSecuredPduInfo())
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   if(SECOC_INVALIDHNDOFTXSECUREDPDUINFO == STD_ON)
  else if(SecOC_IsInvalidHndOfTxSecuredPduInfo(id))
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   endif
#  endif
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if(SECOC_TXSECUREDPDUINFO == STD_ON)
    SecOC_TxPduInfoIterType txPduInfoIdx = SecOC_GetTxPduInfoIdxOfTxSecuredPduInfo(id);
    if((SecOC_GetTxPduState(txPduInfoIdx) == SECOC_TRANSMISSION_INITIATED_TXPDUSTATE) || (SecOC_GetTxPduState(txPduInfoIdx) == SECOC_COPYING_TXPDUSTATE))
    {
      SecOC_SetTxPduState(txPduInfoIdx, SECOC_INVALID_SECURED_PDU_TXPDUSTATE);
    }
    SecOC_SetTxTpWrittenBytesCounter(txPduInfoIdx, 0);
# else
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_TP_TX_CONFIRMATION, errorId);
  }
# endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}

/**********************************************************************************************************************
  SecOC_CopyRxData
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_CopyRxData(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr)       /* PRQA S 3673 */ /* MD_SecOC_3673_AsrProto */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
# if(SECOC_DEV_ERROR_DETECT == STD_ON)
#  if(SECOC_RXSECUREDPDUINFO == STD_ON)
  else if(id >= SecOC_GetSizeOfRxSecuredPduInfo())
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   if(SECOC_INVALIDHNDOFRXSECUREDPDUINFO == STD_ON)
  else if(SecOC_IsInvalidHndOfRxSecuredPduInfo(id))
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   endif
#  endif
  else if(info == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
  else if(info->SduDataPtr == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
  else if(bufferSizePtr == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
#  if (SECOC_RXSECUREDPDUINFO == STD_ON)
  else if(SecOC_GetRxPduState(SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(id)) != SECOC_COPYING_RXPDUSTATE)
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
#  endif
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (SECOC_RXSECUREDPDUINFO == STD_ON)
    SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(id);
    if(info->SduLength <= (SecOC_GetSecuredPduDataContainerSecuredPduLengthOfRxPduInfo(rxPduInfoIdx) - SecOC_GetRxTpWrittenBytesCounter(rxPduInfoIdx)))
    {
      VStdMemCpyRamToRam(SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo(rxPduInfoIdx) + SecOC_GetRxTpWrittenBytesCounter(rxPduInfoIdx)), info->SduDataPtr, info->SduLength);
      SecOC_SetRxTpWrittenBytesCounter(rxPduInfoIdx, (SecOC_GetRxTpWrittenBytesCounter(rxPduInfoIdx) + info->SduLength));
      *bufferSizePtr = (PduLengthType) (SecOC_GetSecuredPduDataContainerSecuredPduLengthOfRxPduInfo(rxPduInfoIdx) - SecOC_GetRxTpWrittenBytesCounter(rxPduInfoIdx));
      retVal = BUFREQ_OK;
    }
# else
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_COPY_RX_DATA, errorId);
  }
# endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return retVal;
}  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
  SecOC_CopyTxData
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_CopyTxData(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, SECOC_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) availableDataPtr)    /* PRQA S 3673 */ /* MD_SecOC_3673_AsrProto */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
# if(SECOC_DEV_ERROR_DETECT == STD_ON)
#  if(SECOC_TXSECUREDPDUINFO == STD_ON)
  else if(id >= SecOC_GetSizeOfTxSecuredPduInfo())
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   if(SECOC_INVALIDHNDOFTXSECUREDPDUINFO == STD_ON)
  else if(SecOC_IsInvalidHndOfTxSecuredPduInfo(id))
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   endif
#  endif
  else if(info == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
  else if(info->SduDataPtr == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
  else if(availableDataPtr == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if(SECOC_TXSECUREDPDUINFO == STD_ON)
    SecOC_TxPduInfoIterType txPduInfoIdx = SecOC_GetTxPduInfoIdxOfTxSecuredPduInfo(id);
    if(SecOC_GetTxPduState(txPduInfoIdx) == SECOC_TRANSMISSION_INITIATED_TXPDUSTATE)
    {
      SecOC_SetTxPduState(txPduInfoIdx, SECOC_COPYING_TXPDUSTATE);
    }
    if(SecOC_GetTxPduState(txPduInfoIdx) == SECOC_COPYING_TXPDUSTATE)
    {
      if(info->SduLength <= (SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(txPduInfoIdx) - SecOC_GetTxTpWrittenBytesCounter(txPduInfoIdx)))
      {
        VStdMemCpyRamToRam(info->SduDataPtr, SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo(txPduInfoIdx) + SecOC_GetTxTpWrittenBytesCounter(txPduInfoIdx)), info->SduLength);
        SecOC_SetTxTpWrittenBytesCounter(txPduInfoIdx, (SecOC_GetTxTpWrittenBytesCounter(txPduInfoIdx) + info->SduLength));
        *availableDataPtr = (PduLengthType) (SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(txPduInfoIdx) - SecOC_GetTxTpWrittenBytesCounter(txPduInfoIdx));
        retVal = BUFREQ_OK;
      }
    }
# else
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_COPY_TX_DATA, errorId);
  }
# endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  SECOC_DUMMY_STATEMENT(retry); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return retVal;
}  /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
  SecOC_StartOfReception
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_StartOfReception(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr)      /* PRQA S 3673 */ /* MD_SecOC_3673_AsrProto */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
# if(SECOC_DEV_ERROR_DETECT == STD_ON)
#  if(SECOC_RXSECUREDPDUINFO == STD_ON)
  else if(id >= SecOC_GetSizeOfRxSecuredPduInfo())
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   if(SECOC_INVALIDHNDOFRXSECUREDPDUINFO == STD_ON)
  else if(SecOC_IsInvalidHndOfRxSecuredPduInfo(id))
  {
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
  }
#   endif
#  endif
  else if(bufferSizePtr == NULL_PTR)
  {
    errorId = SECOC_E_PARAM_POINTER;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if (SECOC_RXSECUREDPDUINFO == STD_ON)
    if(SecOC_GetSecuredPduDataContainerSecuredPduLengthOfRxPduInfo(SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(id)) == TpSduLength)
    {
      SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(id);
      if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE)
      {
        SecOC_SetRxPduState(rxPduInfoIdx, SECOC_COPYING_RXPDUSTATE);
        *bufferSizePtr = (PduLengthType) SecOC_GetSecuredPduDataContainerSecuredPduLengthOfRxPduInfo(rxPduInfoIdx) - SecOC_GetRxTpWrittenBytesCounter(rxPduInfoIdx);
        retVal = BUFREQ_OK;
      }
    }
    else
    {
      retVal = BUFREQ_E_OVFL;
    }
# else
    errorId = SECOC_E_INVALID_PDU_SDU_ID;
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_START_OF_RECEPTION, errorId);
  }
# endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  SECOC_DUMMY_STATEMENT(info);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return retVal;
}  /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

/**********************************************************************************************************************
  SecOC_VerifyStatusOverride
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
 *
 *
**********************************************************************************************************************/
FUNC(Std_ReturnType, SECOC_CODE) SecOC_VerifyStatusOverride(uint16 freshnessValueID, uint8 overrideStatus, uint8 numberOfMessagesToOverride)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SECOC_E_NO_ERROR;
  Std_ReturnType ret = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check if component is initialized */
  if(!SecOC_IsInitialized())
  {
    errorId = SECOC_E_INVALID_REQUEST;
  }
#if(SECOC_DEV_ERROR_DETECT == STD_ON)
# if (SECOC_FRESHNESSVALUE == STD_ON)
  else if(freshnessValueID >= SecOC_GetSizeOfVerifyOverrideStatus())
  {
    errorId = SECOC_E_PARAM;
  }
# endif
  else if(!((overrideStatus == SECOC_CANCEL_VERIFYOVERRIDESTATUS) || (overrideStatus == SECOC_FAIL_N_TIMES_VERIFYOVERRIDESTATUS) || (overrideStatus == SECOC_FAIL_INFINETE_VERIFYOVERRIDESTATUS)
# if (SECOC_ENABLE_FORCED_PASS_OVERRIDESTATUS == STD_ON)
            || (overrideStatus == SECOC_PASS_VERIFYOVERRIDESTATUS)
# endif
          ))
  {
    errorId = SECOC_E_PARAM;
  }
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if (SECOC_FRESHNESSVALUE == STD_ON)
    if((overrideStatus == SECOC_FAIL_N_TIMES_VERIFYOVERRIDESTATUS)
# if (SECOC_ENABLE_FORCED_PASS_OVERRIDESTATUS == STD_ON)
       || (overrideStatus == SECOC_PASS_VERIFYOVERRIDESTATUS)
# endif
      )
    {
      SecOC_SetNumberOfMessagesToOverride(freshnessValueID, numberOfMessagesToOverride);
    }
    SecOC_SetVerifyOverrideStatus(freshnessValueID, overrideStatus);
    ret = E_OK;
#else
    errorId = SECOC_E_PARAM;
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if(SECOC_DEV_ERROR_REPORT == STD_ON)
  if(errorId != SECOC_E_NO_ERROR)
  {
    SecOC_ReportDetError(SECOC_SID_VERIFY_STATUS_OVERRIDE, errorId);
  }
#endif

  SECOC_DUMMY_STATEMENT(errorId);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return ret;
}

/**********************************************************************************************************************
  SecOC_MainFunctionRx
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_MainFunctionRx(void)
{
#if (SECOC_RXPDUINFO == STD_ON)
  /* #10 Check if COM is initialized */
  if(SecOC_IsInitialized())
  {
    /* ----- Implementation ----------------------------------------------- */
    SecOC_RxIf_HandlePdus();
  }
#endif
}

/**********************************************************************************************************************
  SecOC_MainFunctionTx
**********************************************************************************************************************/
/** Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) SecOC_MainFunctionTx(void)
{
#if (SECOC_TXPDUINFO == STD_ON)
  /* #10 Check if COM is initialized */
  if(SecOC_IsInitialized())
  {
    /* ----- Implementation ----------------------------------------------- */
    SecOC_TxIf_HandlePdus();
  }
#endif
}

#define SECOC_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_19.1 */

/* *INDENT-OFF* */
/* module specific MISRA deviations:
   MD_SecOC_3673_AsrProto:
     Reason:     Function prototype is based on AUTOSAR specification. No optimization possible.
     Risk:       Unexpected value modification.
     Prevention: Covered by code review.
*/
/* *INDENT-ON* */

/* *INDENT-OFF* */
/* COV_JUSTIFICATION_BEGIN

  \ID COV_SECOC_MISRA
    \ACCEPT X
    \ACCEPT TX
    \REASON [MSR_COV_MISRA]

COV_JUSTIFICATION_END */
/* *INDENT-ON* */

/**********************************************************************************************************************
 *  END OF FILE: SecOC.c
 *********************************************************************************************************************/
