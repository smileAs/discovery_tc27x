/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EthTrcv_30_Tja1100_Int.h
 *        \brief  Ethernet transceiver driver internal header
 *
 *      \details  Header file containing the private type and data declarations of the Ethernet Transceiver driver
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK in the module's header file
 *********************************************************************************************************************/
#if !defined (ETHTRCV_30_TJA1100_INT_H)
# define ETHTRCV_30_TJA1100_INT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# if (ETHTRCV_30_TJA1100_DEM_ERROR_DETECT == STD_ON)
#  include "Dem.h"
# endif /* ETHTRCV_30_TJA1100_DEM_ERROR_DETECT */
# if (ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif /* ETHTRCV_30_TJA1100_DEV_ERROR_DETECT */
# include "SchM_EthTrcv_30_Tja1100.h"
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777  */
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (STATIC)
#  define STATIC static
# endif
# if !defined(ETHTRCV_30_TJA1100_INLINE)
#  define ETHTRCV_30_TJA1100_INLINE STATIC INLINE
# endif

# define ETHTRCV_30_TJA1100_MAX_CFGS_TOTAL                     (1U)

/* value for pre-compile time config variant */
# define ETHTRCV_30_TJA1100_CONFIG_VARIANT_PRECOMPILE          (1U)

/* ----- Private API service IDs ----- */
# define ETHTRCV_30_TJA1100_SID_READ_MODIFY_WRITE              (0x16U) /*!< Service ID: EthTrcv_30_Tja1100_ReadModifyWrite() */
# define ETHTRCV_30_TJA1100_SID_READ_MODIFY_WRITE_REG_VAL      (0x17U) /*!< Service ID: EthTrcv_30_Tja1100_ReadModifyWriteRegVal() */
# define ETHTRCV_30_TJA1100_SID_READ_AND_COMPARE               (0x18U) /*!< Service ID: EthTrcv_30_Tja1100_ReadAndCompare() */
# define ETHTRCV_30_TJA1100_SID_CLEAR_BITS_REG_VAL_PATTERN     (0x19U) /*!< Service ID: EthTrcv_30_Tja1100_ClearBitsRegValPattern() */
# define ETHTRCV_30_TJA1100_SID_SET_BITS_REG_VAL_PATTERN       (0x1AU) /*!< Service ID: EthTrcv_30_Tja1100_SetBitsRegValPattern() */
/**************************************************************************************************
* GLOBAL CONSTANT MACROS
**************************************************************************************************/
# define ETHTRCV_30_TJA1100_BEGIN_CRITICAL_SECTION()           SchM_Enter_EthTrcv_30_Tja1100_ETHTRCV_30_TJA1100_EXCLUSIVE_AREA_0()
# define ETHTRCV_30_TJA1100_END_CRITICAL_SECTION()             SchM_Exit_EthTrcv_30_Tja1100_ETHTRCV_30_TJA1100_EXCLUSIVE_AREA_0()

/* Common register masks */
# define ETHTRCV_30_TJA1100_REG_PHYIDR1_OUI_LSB_MASK           (0xFFFFU)
# define ETHTRCV_30_TJA1100_REG_PHYIDR2_OUI_MSB_MASK           (0xFC00U)
# define ETHTRCV_30_TJA1100_REG_PHYIDR2_TYPE_NO_MASK           (0x03F0U)
# define ETHTRCV_30_TJA1100_REG_PHYIDR2_REV_NO_MASK            (0x000FU)
# define ETHTRCV_30_TJA1100_REG_PHYIDR1_SHIFT_LSB              (0x0006U)
# define ETHTRCV_30_TJA1100_REG_PHYIDR2_SHIFT_MSB              (0x000AU)
# define ETHTRCV_30_TJA1100_REG_PHYIDR2_MODEL_NO_SHIFT         (0x0004U)

/* Phy Test Modes */
# define ETHTRCV_30_TJA1100_PHY_TEST_MODE_NORMAL               (0x0U)
# define ETHTRCV_30_TJA1100_PHY_TEST_MODE_1                    (0x1U)
# define ETHTRCV_30_TJA1100_PHY_TEST_MODE_2                    (0x2U)
# define ETHTRCV_30_TJA1100_PHY_TEST_MODE_3                    (0x3U)
# define ETHTRCV_30_TJA1100_PHY_TEST_MODE_4                    (0x4U)
# define ETHTRCV_30_TJA1100_PHY_TEST_MODE_5                    (0x5U)
# define ETHTRCV_30_TJA1100_PHY_TEST_MODE_6                    (0x6U)
# define ETHTRCV_30_TJA1100_PHY_TEST_MODE_7                    (0x7U)

/* Transceiver Register Access Methods */
# define ETHTRCV_30_TJA1100_MII_ACCESS                         (0x0U)
# define ETHTRCV_30_TJA1100_RDB_ACCESS                         (0x1U)
# define ETHTRCV_30_TJA1100_SHADOW_ACCESS                      (0x2U)
# define ETHTRCV_30_TJA1100_INTEGRATED_PHY_ACCESS              (0x3U)

/* Diagnostic Event Manager */
# if ( ETHTRCV_30_TJA1100_DEM_ERROR_DETECT == STD_ON )
#  define ETHTRCV_30_TJA1100_DEM_REPORT_ERROR_STATUS_ETHTRCV_E_ACCESS(TrcvIdx) \
  (Dem_ReportErrorStatus(EthTrcv_30_Tja1100_DemEvents[TrcvIdx], DEM_EVENT_STATUS_FAILED))
# else
#  define ETHTRCV_30_TJA1100_DEM_REPORT_ERROR_STATUS_ETHTRCV_E_ACCESS(TrcvIdx)
# endif
  /* ETHTRCV_30_TJA1100_DEM_ERROR_DETECT */

/* PRQA L:FCT_LIKE_MACROS */

/**********************************************************************************************************************
 *  PRIVATE DATA
 *********************************************************************************************************************/
# define ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

extern VAR(EthTrcv_StateType, ETHTRCV_30_TJA1100_VAR_ZERO_INIT) EthTrcv_30_Tja1100_ModuleState;

# define ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

/* Function pointer types */
typedef P2FUNC(void,    AUTOMATIC, EthTrcv_30_Tja1100_LL_ModifyRegValFunction)       (uint8, uint16 *);
typedef P2FUNC(void,    AUTOMATIC, EthTrcv_30_Tja1100_ModifyRegWithRegValFunction)   (uint16, uint16 * );
typedef P2FUNC(boolean, AUTOMATIC, EthTrcv_30_Tja1100_LL_CompareRegValFunction)      (uint8, uint16);


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define ETHTRCV_30_TJA1100_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  EthTrcv_30_Tja1100_ReadModifyWrite()
 **********************************************************************************************************************/
/*! \brief       Function to set transceiver registers
 *  \details     This function is used to change the register value of a transceiver register.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_ReadModifyWrite(
    uint8 TrcvIdx,
    uint8 RegAddr,
    EthTrcv_30_Tja1100_LL_ModifyRegValFunction ModifyFunc);

/***********************************************************************************************************************
 *  EthTrcv_30_Tja1100_ReadModifyWriteRegVal()
 **********************************************************************************************************************/
/*! \brief       Function to set transceiver registers according to a given register value and a modification function
 *  \details     This function is used to change the register value of a transceiver register.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
    uint8 TrcvIdx,
    uint8 RegAddr,
    uint16 RegVal,
    EthTrcv_30_Tja1100_ModifyRegWithRegValFunction ModifyFunc);

/***********************************************************************************************************************
 *  EthTrcv_30_Tja1100_ReadAndCompare()
 **********************************************************************************************************************/
/*! \brief       Function to compare transceiver registers
 *  \details     This function is used to read a transceiver register and compare it with a comparing function.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_ReadAndCompare(
    uint8 TrcvIdx,
    uint8 RegAddr,
    EthTrcv_30_Tja1100_LL_CompareRegValFunction CompareFunc,
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) ResultPtr);

/***********************************************************************************************************************
 *  EthTrcv_30_Tja1100_SetBitsRegValPattern()
 **********************************************************************************************************************/
/*! \brief       Function to set bits in a register according to a given pattern
 *  \details     This function is used to modify transceiver register values according to a given pattern
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_SetBitsRegValPattern(
    uint16 RegValPattern,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);

/***********************************************************************************************************************
 *  EthTrcv_30_Tja1100_ClearBitsRegValPattern()
 **********************************************************************************************************************/
/*! \brief       Function to clear bits in a register according to a given pattern
 *  \details     This function is used to clear transceiver register values according to a given pattern
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_ClearBitsRegValPattern(
    uint16 RegValPattern,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr);

# define ETHTRCV_30_TJA1100_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#endif  /* ETHTRCV_30_TJA1100_INT_H */
/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Tja1100_Int.h
 *********************************************************************************************************************/
