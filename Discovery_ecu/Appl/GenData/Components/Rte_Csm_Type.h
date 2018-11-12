/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Csm_Type.h
 *        Config:  discovery_ecu.dpa
 *   ECU-Project:  P2P
 *
 *     Generator:  MICROSAR RTE Generator Version 4.14.0
 *                 RTE Core Version 1.14.0
 *       License:  Unlimited license CBD1800319 for Tong Ji University
 *
 *   Description:  Application types header file for SW-C <Csm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CSM_TYPE_H
# define _RTE_CSM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef CSM_E_OK
#   define CSM_E_OK (0U)
#  endif

#  ifndef CSM_E_NOT_OK
#   define CSM_E_NOT_OK (1U)
#  endif

#  ifndef CSM_E_BUSY
#   define CSM_E_BUSY (2U)
#  endif

#  ifndef CSM_E_SMALL_BUFFER
#   define CSM_E_SMALL_BUFFER (3U)
#  endif

#  ifndef CSM_E_ENTROPY_EXHAUSTION
#   define CSM_E_ENTROPY_EXHAUSTION (4U)
#  endif

#  ifndef CSM_E_VER_OK
#   define CSM_E_VER_OK (0U)
#  endif

#  ifndef CSM_E_VER_NOT_OK
#   define CSM_E_VER_NOT_OK (1U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CSM_TYPE_H */
