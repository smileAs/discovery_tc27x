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
 *         File:  Cry_30_LibCv.c
 *    Component:  SysService_AsrCry
 *       Module:  MICROSAR Cryptographic library module (Cry)
 *    Generator:  -
 *
 *  Description:  Implements the Cry API for the ASR CSM
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

#define CRY_30_LIBCV_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Cry_30_LibCv.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (  (CRY_30_LIBCV_SW_MAJOR_VERSION != (0x03)) \
    || (CRY_30_LIBCV_SW_MINOR_VERSION != (0x00)) \
    || (CRY_30_LIBCV_SW_PATCH_VERSION != (0x00)) )
  #error "Vendor specific version numbers of Cry_30_LibCv.c and Cry_30_LibCv.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if !defined (CRY_30_LIBCV_LOCAL)
# define CRY_30_LIBCV_LOCAL static
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Cry_30_LibCv_Init
**********************************************************************************************************************/
/*! \brief      Initialization function
 *  \context    Function could be called from task level only
 *  \note       Called by application
**********************************************************************************************************************/
FUNC (void, CRY_30_LIBCV_CODE) Cry_30_LibCv_Init( void )
{

  /* Initialize FIPS-186 */
# if ( CRY_30_LIBCV_FIPS186CONFIG == STD_ON )
  Cry_30_LibCv_Fips186Init();
# endif

  /* Initialize RSA decrypt */
# if ( CRY_30_LIBCV_RSADECRYPTCONFIG == STD_ON )
  Cry_30_LibCv_RsaDecryptInit();
# endif

  /* Initialize RsaSha1SigVer */
# if ( CRY_30_LIBCV_RSASHA1SIGVERCONFIG == STD_ON )
  Cry_30_LibCv_RsaSha1SigVerInit();
# endif

}  /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 * Cry_30_LibCv_InitMemory
**********************************************************************************************************************/
/*! \brief      Memory initialization function
 *  \context    Function could be called from task level only
 *  \note       Called by application
**********************************************************************************************************************/
FUNC (void, CRY_30_LIBCV_CODE) Cry_30_LibCv_InitMemory( void )
{

}

#if ( CRY_30_LIBCV_VERSION_INFO_API == STD_ON )
/**********************************************************************************************************************
 * Cry_30_LibCv_GetVersionInfo
**********************************************************************************************************************/
/*! \brief      This service returns the version information of this module.
 *  \param[out] cryVerInfoPtr          Pointer where to store the version information of this module.
 *  \context    Function could be called from task level only
 *  \note       Called by application
**********************************************************************************************************************/
FUNC( void, CRY_30_LIBCV_CODE ) Cry_30_LibCv_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, CRY_30_LIBCV_APPL_VAR ) cryVerInfoPtr )
{
  if( cryVerInfoPtr != NULL_PTR )
  {
    cryVerInfoPtr->vendorID = (uint16)CRY_30_LIBCV_VENDOR_ID;
    cryVerInfoPtr->moduleID = (uint8)CRY_30_LIBCV_MODULE_ID;
    cryVerInfoPtr->sw_major_version = (uint8)CRY_30_LIBCV_SW_MAJOR_VERSION;
    cryVerInfoPtr->sw_minor_version = (uint8)CRY_30_LIBCV_SW_MINOR_VERSION;
    cryVerInfoPtr->sw_patch_version = (uint8)CRY_30_LIBCV_SW_PATCH_VERSION;
  }
}
#endif /* ( CRY_30_LIBCV_VERSION_INFO_API == STD_ON ) */

/**********************************************************************************************************************
 *  END OF FILE: CRY_30_LIBCV.C
 *********************************************************************************************************************/
