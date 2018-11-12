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
 *         File:  Cry_Key_Types.h
 *    Component:  SysService_AsrCry
 *       Module:  MICROSAR Cryptographic library module (Cry)
 *    Generator:  -
 *
 *  Description:  This header file provides custom key types for the application
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

#if !defined (CRY_KEY_TYPES_H)
#define CRY_KEY_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/** RSA key type */
typedef struct
{
  uint16 keyModuleLength;                                         /*< Length of the modulo in byte */
  P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) keyModule;   /*< Pointer to the modulo */
  uint16 keyExponentLength;                                       /*< Length of the exponent in byte */
  P2CONST( uint8, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) keyExponent; /*< Pointer to the exponent */
} Cry_RsaKeyType;

#endif  /* CRY_KEY_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: CRY_KEY_TYPES.H
 *********************************************************************************************************************/

