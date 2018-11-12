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
/**        \file  EthTrcv_30_Ethmii_LL.c
 *        \brief  Lower Layer of Ethernet Transceiver Driver
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
#define ETHTRCV_30_ETHMII_LL_SOURCE
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EthTrcv_30_Ethmii.h"
#include "EthTrcv_30_Ethmii_Lcfg.h"
#include "EthTrcv_30_Ethmii_Int.h"
#include "EthTrcv_30_Ethmii_Regs.h"
#include "EthTrcv_30_Ethmii_LL_Cfg.h"
#include "EthTrcv_30_Ethmii_LL.h"
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_ETHMII_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_ETHMII_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_ETHMII_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_ETHMII_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Ethmii_LL.c
 *********************************************************************************************************************/
