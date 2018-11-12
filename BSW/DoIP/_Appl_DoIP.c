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
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Appl_DoIP.c
 *      Project:  TcpIp-Stack
 *       Module:  Diagnostic over IP (DoIP)
 *    Generator:  -
 *
 *  Description:  demo application for component
 *  
 *********************************************************************************************************************/
#define APPLDOIP_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Appl_DoIP.h"

/**********************************************************************************************************************
 *  DATA
 *********************************************************************************************************************/
/* EXAMPLE
 *  uint8 Appl_DoIP_Vin[17]            = { 0x57, 0x30, 0x4C, 0x30, 0x30, 0x30, 0x30, 0x34, 0x33, 0x4D, 0x42, 0x35, \
 *                                         0x34, 0x31, 0x33, 0x32, 0x36 };
 *  uint8 Appl_DoIP_Gid[6]             = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
 *  uint8 Appl_DoIP_DiagPowerMode      = 0x01;
 *  uint8 Appl_DoIP_RoutActState       = DOIP_ACTIVATION_LINE_ACTIVE; // DOIP_ACTIVATION_LINE_ACTIVE/DOIP_ACTIVATION_LINE_INACTIVE
 *  uint8 Appl_DoIP_RoutActAuthReq[]   = { 0x00, 0x01 };
 *  uint8 Appl_DoIP_RoutActAuthReqLen  = 2;
 *  uint8 Appl_DoIP_RoutActConfReq[]   = { 0x02, 0x03 };
 *  uint8 Appl_DoIP_RoutActConfReqLen  = 2;
 *  uint8 Appl_DoIP_RoutActAuthRes[]   = { 0x04, 0x05 };
 *  uint8 Appl_DoIP_RoutActAuthResLen  = 2;
 *  uint8 Appl_DoIP_RoutActConfRes[]   = { 0x06, 0x07 };
 *  uint8 Appl_DoIP_RoutActConfResLen  = 2;
 *  uint8 Appl_DoIP_OemPayloadTypeSend = 0x01;
 */

/**********************************************************************************************************************
 *  ApplDoIP_GetVin
 *********************************************************************************************************************/
/*! \brief      Retrieves VIN from application
 *  \param[in]  Vin       Pointer to buffer where the VIN shall be stored
 *  \return     E_OK      Request is accepted
 *  \return     E_NOT_OK  Request is not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_GetVin(uint8 * Vin)
{
  #error "Appl_DoIP: ApplDoIP_GetVin() needs to be implemented! An example is given in template."

  /* EXAMPLE
   *  uint8 idx;
   *
   *  for ( idx = 0u; idx < 17; idx++)
   *  {
   *    Vin[idx] = Appl_DoIP_Vin[idx];
   *  }
   *
   *  return E_OK;
   */
}

/**********************************************************************************************************************
 *  ApplDoIP_GetGid
 *********************************************************************************************************************/
/*! \brief      Retrieves GID from application
 *  \param[in]  GroupId   Pointer to buffer where the GID shall be stored
 *  \return     E_OK      Request is accepted
 *  \return     E_NOT_OK  Request is not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_GetGid(uint8 * GroupId)
{
  #error "Appl_DoIP: ApplDoIP_GetGid() is an optional callback. Implement or remove the function depending on your configuration! An example is given in template."

  /* EXAMPLE
   *  uint8 idx;
   *
   *  for ( idx = 0u; idx < 6; idx++)
   *  {
   *    GroupId[idx] = Appl_DoIP_Gid[idx];
   *  }
   *
   *  return E_OK;
   */
}

/**********************************************************************************************************************
 *  ApplDoIP_TriggerGidSync
 *********************************************************************************************************************/
/*! \brief      Triggers GID synchronization at application
 *  \param[in]  void none
 *  \return     E_OK      GroupIdentifier Synchronization was triggered
 *  \return     E_NOT_OK  GroupIdentifier Synchronization could not be triggered so try again next MainFunction
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_TriggerGidSync(void)
{
  #error "Appl_DoIP: ApplDoIP_TriggerGidSync() is an optional callback. Implement or remove the function depending on your configuration! An example is given in template."

  /* EXAMPLE
   *  return E_OK;
   */
}

/**********************************************************************************************************************
 *  ApplDoIP_GetDiagPowerMode
 *********************************************************************************************************************/
/*! \brief      Retrieves power mode from application
 *  \param[in]  PowerStateReady   Pointer to buffer where the power mode shall be stored
 *  \return     E_OK              Request is accepted
 *  \return     E_NOT_OK          Request is not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_GetDiagPowerMode(DoIP_PowerStateType * PowerStateReady)
{
  #error "Appl_DoIP: ApplDoIP_GetDiagPowerMode() needs to be implemented! An example is given in template."

  /* EXAMPLE
   *  *PowerStateReady = Appl_DoIP_DiagPowerMode;
   *
   *  return E_OK;
   */
}

/**********************************************************************************************************************
 *  ApplDoIP_ShutdownFinished
 *********************************************************************************************************************/
/*! \brief      Informs upper layer about finished shutdown
 *  \param[in]  void      none
 *  \return     E_OK      Request is accepted
 *  \return     E_NOT_OK  Request is not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_ShutdownFinished(void)
{
  #error "Appl_DoIP: ApplDoIP_ShutdownFinished() is an optional callback. Implement or remove the function depending on your configuration!"
}

/**********************************************************************************************************************
 *  ApplDoIP_GetActivationLineState
 *********************************************************************************************************************/
/*! \brief      Retrieves activation line state from application
 *  \param[in]  state     Pointer to buffer where activation line state shall be stored
 *  \return     E_OK      Request is accepted
 *  \return     E_NOT_OK  Request is not accepted
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_GetActivationLineState(DoIP_ActivationLineType * const state)
{
  #error "Appl_DoIP: ApplDoIP_GetActivationLineState() is an optional callback. Implement or remove the function depending on your configuration! An example is given in template."

  /* EXAMPLE
   *  *state = Appl_DoIP_RoutActState;
   *
   *  return E_OK;
   */
}

/**********************************************************************************************************************
 *  ApplDoIP_RoutingActivationAuthentication
 *********************************************************************************************************************/
/*! \brief      Forwards OEM specific part for authentication of received routing activation request to application and
                retrieves OEM specific part for authentication for routing activation response
 *  \param[in]  Authentified            Indicates if authentication was successful
 *  \param[in]  AuthenticationReqData   Pointer to OEM specific part for authentication of routing activation request
 *  \param[in]  AuthenticationResData   Pointer to OEM specific part for authentication of routing activation response
 *  \return     E_OK                    Authentified and AuthenticationResData contain valid Data
 *  \return     E_NOT_OK                Authentified and/or AuthenticationResData do not contain valid information
 *  \return     DOIP_E_PENDING          Authentication still running. Call next DoIP_MainFunction cycle again
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_RoutingActivationAuthentication(boolean * Authentified, uint8 * AuthenticationReqData, uint8 * AuthenticationResData)
{
  #error "Appl_DoIP: ApplDoIP_RoutingActivationAuthentication() is an optional callback. Implement or remove the function depending on your configuration! An example is given in template."

  /* EXAMPLE
   *  uint8 idx;
   *  
   *  // check OEM specific data
   *  for ( idx = 0u; idx < Appl_DoIP_RoutActAuthReqLen; idx++ )
   *  {
   *    if ( AuthenticationReqData[idx] != Appl_DoIP_RoutActAuthReq[idx] )
   *    {
   *      return E_NOT_OK;
   *    }
   *  }
   *  
   *  // fill OEM spcific data/
   *  for ( idx = 0u; idx < Appl_DoIP_RoutActAuthResLen; idx++ )
   *  {
   *    AuthenticationResData[idx] = Appl_DoIP_RoutActAuthRes[idx];
   *  }
   *  
   *  *Authentified = TRUE;
   *  
   *  return E_OK;
   */
}

/**********************************************************************************************************************
 *  ApplDoIP_RoutingActivationConfirmation
 *********************************************************************************************************************/
/*! \brief      Forwards OEM specific part for confirmation of received routing activation request to application and
                retrieves OEM specific part for confirmation for routing activation response
 *  \param[in]  Confirmed             Indicates if confirmation was successful
 *  \param[in]  ConfirmationReqData   Pointer to OEM specific part for confirmation of routing activation request
 *  \param[in]  ConfirmationResData   Pointer to OEM specific part for authentication of routing activation response
 *  \return     E_OK                  Confirmed and ConfirmationResData contain valid Data
 *  \return     E_NOT_OK              Confirmed and/or ConfirmationResData do not contain valid information
 *  \return     DOIP_E_PENDING        Confirmation still running. Call next DoIP_MainFunction cycle again
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt 
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_RoutingActivationConfirmation(boolean * Confirmed, uint8 * ConfirmationReqData, uint8 * ConfirmationResData)
{
  #error "Appl_DoIP: ApplDoIP_RoutingActivationConfirmation() is an optional callback. Implement or remove the function depending on your configuration! An example is given in template."

  /* EXAMPLE
   *  uint8 idx;
   *  
   *  // check OEM specific data
   *  for ( idx = 0u; idx < Appl_DoIP_RoutActConfReqLen; idx++ )
   *  {
   *    if ( ConfirmationReqData[idx] != Appl_DoIP_RoutActConfReq[idx] )
   *    {
   *      return E_NOT_OK;
   *    }
   *  }
   *  
   *  // fill OEM spcific data/
   *  for ( idx = 0u; idx < Appl_DoIP_RoutActConfResLen; idx++ )
   *  {
   *    ConfirmationResData[idx] = Appl_DoIP_RoutActConfRes[idx];
   *  }
   *  
   *  *Confirmed = TRUE;
   *  
   *  return E_OK;
   */
}

/**********************************************************************************************************************
 *  ApplDoIP_OemPayloadType
 *********************************************************************************************************************/
/*! \brief      Forwards user data of manufacturer-specific payload types to user and initiate transmission of a
 *              response
 *  \param[in]  RxPayloadType         Received payload type
 *  \param[in]  RxUserData            Pointer to received user data
 *  \param[in]  Flags                 Flags indicates protocol (TCP/UDP) and routing activation state
 *  \param[out] TxPayloadType         Payload type for response which must not to be set if no response shall be sent
 *  \param[out] TxUserData            Pointer to buffer where user can store user data for response. As “in” parameter
 *                                    it indicates the buffer size provided by DoIP and must be set to length of copied
 *                                    response data.
 *  \return     E_OK                  Known payload type
 *  \return     E_NOT_OK              Unknown payload type
 *  \pre        Module initialized
 *  \context    Task level
 *  \context    Interrupt 
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_OemPayloadType(uint16 RxPayloadType, const PduInfoType* RxUserData, DoIP_OemPayloadTypeFlagType Flags, uint16* TxPayloadType, PduInfoType* TxUserData)
{
  #error "Appl_DoIP: ApplDoIP_OemPayloadType() is an optional callback. Implement or remove the function depending on your configuration! An example is given in template."
  
  /* EXAMPLE
   *  uint8 idx;
   *  
   *  // check payload type
   *  if ( RxPayloadType != 0xF000 )
   *  {
   *    return E_NOT_OK;
   *  }
   *  
   *  // check flags
   *  if ( (Flags & DOIP_OEM_PAYLOAD_TYPE_FLAG_PROT_TCP) == 0 )
   *  { // not received on TCP
   *    return E_NOT_OK;
   *  }
   *  if ( (Flags & DOIP_OEM_PAYLOAD_TYPE_FLAG_ROUT_ACTIV) == 0 )
   *  { // routing activation not active
   *    return E_NOT_OK;
   *  }
   *  
   *  // check user data
   *  for ( idx = 0u; idx < RxUserData->SduLength; idx++ )
   *  {
   *    if ( RxUserData->SduDataPtr[idx] != idx )
   *    {
   *      return E_NOT_OK;
   *    }
   *  }
   *  
   *  // prepare response if required
   *  if ( Appl_DoIP_OemPayloadTypeSend == 0x01 )
   *  {
   *    *TxPayloadType = 0xF001;
   *  
   *    if ( RxUserData->SduLength == 0u )
   *    {
   *      // if request has no user data send response without user data, too
   *      TxUserData->SduLength = 0;
   *    }
   *    else
   *    {
   *      // copy have of request data
   *      for ( idx = 0u; idx < (RxUserData->SduLength / 2); idx++ )
   *      {
   *        TxUserData->SduDataPtr[idx] = idx + 1;
   *      }
   *      TxUserData->SduLength = RxUserData->SduLength / 2;
   *    }
   *  }
   *  
   *  return E_OK;
   */
}

/**********************************************************************************************************************
 *  ApplDoIP_VerifyTargetAddr
 *********************************************************************************************************************/
/*! \brief      Forwards logical target address received within diagnostic message to user
 *  \param[in]  TargetAddr            Target address received within diagnostic message
 *  \return     E_OK                  Target address accepted
 *  \return     E_NOT_OK              Target address declined
 *  \pre        Module initialized
 *  \context    Task level
 *********************************************************************************************************************/
Std_ReturnType ApplDoIP_VerifyTargetAddr(uint16 TargetAddr)
{
  #error "Appl_DoIP: ApplDoIP_VerifyTargetAddr() is an optional callback. Implement or remove the function depending on your configuration! An example is given in template."
  
  /* EXAMPLE
   *  Std_ReturnType retVal = E_NOT_OK;
   *
   *  // check target address
   *  if ( TargetAddr == 0x0200 )
   *  {
   *    retVal = E_OK;
   *  }
   *  
   *  return retVal;
   */
}

/**********************************************************************************************************************
 *  END OF FILE: Appl_DoIP.c
 *********************************************************************************************************************/
