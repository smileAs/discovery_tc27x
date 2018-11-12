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
/**        \file
 *        \brief  Vector AUTOSAR StbM Types header file
 *
 *      \details  This header file contains the type definitions of the Vector AUTOSAR module StbM.

 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (STBM_TYPES_H)
# define STBM_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"
# include "Rte_StbM_Type.h"
# include "Os.h"
# include "StbM_Cfg.h"
# if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
#  include "EthIf.h"
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define STBM_NO_LOCALTIME                       (0U)
# define STBM_OS_LOCALTIME                       (1U)
# define STBM_GPT_LOCALTIME                      (2U)

# define STBM_NO_LOCALTIME_ID                    (0U)
# define STBM_NO_GPT_CHANNEL_IDX                 (0U)
# define STBM_NO_LOCALTIME_NSPERTICK             (0U)
# define STBM_NO_LOCALTIME_MAXVALUE              (0U)

# define STBM_NO_TIMEDOMAINID                    (255U)
# define STBM_NO_TIMEBASEID                      (0U)

# if !defined (StbM_Timeout_BflMask)
# define StbM_Timeout_BflMask                    (0x01U)
# endif

# if !defined (StbM_Timeleap_BflMask)
#  define StbM_Timeleap_BflMask                  (0x02U)
# endif

# if !defined (StbM_Sync_To_Gateway_BflMask)
#  define StbM_Sync_To_Gateway_BflMask           (0x04U)
# endif

# if !defined (StbM_Global_Time_Base_BflMask)
#  define StbM_Global_Time_Base_BflMask          (0x08U)
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
  StbM_TimeStampType StartGlobalTime;
  StbM_TimeStampType StartLocalTime;
} StbM_RateMeasurementType;

typedef struct
{
  StbM_TimeStampType TimeStamp;
  StbM_UserDataType UserData;
  uint32 LocalTimeTickValue;
# if (STBM_ETHTSYN_LOCALTIME_USED == STD_ON)
  Eth_TimeStampType LocalTime;
# endif
  uint32 SyncLossTimeoutCount;
  uint16 CurrentRateMeasurement;
  StbM_RateMeasurementType RateMeasurement[STBM_MAX_RATE_CORRECTIONS_PER_MEASUREMENT_DURATION];
  StbM_RateDeviationType RateCorrection;
} StbM_TimeBaseType;

typedef struct
{
  uint32 Counter;
  StbM_TimeStampType LastSyncTimeStamp;
  uint32 LastSyncValue;
} StbM_CustomerType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* STBM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: StbM_Types.h
 *********************************************************************************************************************/
