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
/**
 * \ingroup     Os_Hal
 * \addtogroup  Os_Hal_Core
 * \brief   Primitives definition for TriCore Processor Core TC1.6P and TC1.6E
 *
 * \{
 *
 * \file       Os_Hal_Core_161_EPInt.h
 * \brief		This file contains hardware specific addresses for TriCore Processor Core TC1.6P and TC1.6E
 *
 * Internal comment removed.
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
 *
 *
 *
 *
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_CORE_161_EPINT_H)
# define OS_HAL_CORE_161_EPINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! Address of core id register. Read only register */
# define OS_HAL_CORE_ID_REGISTER          0xFE1CUL

/*! Address of the ICR register. */
# define OS_HAL_ICR_OFFSET                0xFE2CU
/*! Bit mask (bit 15) for global interrupt flag */
# define OS_HAL_ICR_INT_MASK              0x00008000UL
/*! Bit mask (bits 7..0) for interrupt level */
# define OS_HAL_ICR_INT_LEVEL_MASK        0x000000FFUL

/*! Address of the SYSCON register. */
# define OS_HAL_SYSCON_OFFSET             0xFE14U
/*! Bit mask (bit 2) for timing protection exception flag */
# define OS_HAL_SYSCON_TP_MASK            0x00000004UL
/*! Bit mask (bit 1) for memory protection exception flag */
# define OS_HAL_SYSCON_MP_MASK            0x00000002UL
/*! Bit mask (bit 3) for initial state for PSW.S bit in trap handler */
# define OS_HAL_SYSCON_IS_MASK            0x00000008UL
/*! Bit mask (bit 4) for initial state of PSW.S bit in interrupt handler */
# define OS_HAL_SYSCON_TS_MASK            0x00000010UL

/*! Address of the PCXI register. */
# define OS_HAL_PCXI_OFFSET               0xFE00
/*! Bit mask (bits 29..22) for previous CPU priority number */
# define OS_HAL_PCXI_PCPN_MASK            0x3FC00000UL
/*! Start bit position of PCPN for shift operation */
# define OS_HAL_PCXI_PCPN_BIT_POSITION    (22U)
/*! Bit mask (bit 21) for previous interrupt state */
# define OS_HAL_PCXI_PIE_MASK             0x00200000UL
/*! Bit value (bit 21) for previous interrupt state as disabled */
# define OS_HAL_PCXI_PIE_DISABLED         0x00000000UL
/*! Bit value (bit 21) for previous interrupt state as enabled */
# define OS_HAL_PCXI_PIE_ENABLED          0x00200000UL
/*! Bit mask (bit 20) for previous context type (lower or upper) */
# define OS_HAL_PCXI_UL_MASK              0x00100000UL
/*! Bit mask (bits 19..0) for linked address */
# define OS_HAL_PCXI_PCX_MASK             0x000FFFFFUL
/*! Bit mask (bits 19..16) for linked address */
# define OS_HAL_PCXI_PCXS_MASK            0x000F0000UL
/*! Bit mask (bits 15..0) for linked address */
# define OS_HAL_PCXI_PCXO_MASK            0x0000FFFFUL
/*! The difference in bit position between ICR.IE and PCXI.PIE. ICR.IE should be shifted leftwards */
# define OS_HAL_PCXI_IE_TO_PIE            (6U)
/*! The difference in bit position between ICR.CCPN and PCXI.PCPN. ICR.CCPN should be shifted leftwards */
# define OS_HAL_PCXI_CCPN_TO_PCPN         (22U)

/*! Address of the FCX register. */
# define OS_HAL_FCX_OFFSET               0xFE38U

/*! Address of the LCX register. */
# define OS_HAL_LCX_OFFSET               0xFE3CU

/*! Address of the PSW register. */
# define OS_HAL_PSW_OFFSET               0xFE04U
/*! Bit mask (bit 7) for CDE (Call Depth Enable) */
# define OS_HAL_PSW_CDE_MASK             0x00000080UL
/*! Bit value (bits 6..0) when CDC (Call Depth Counter) is 1 */
# define OS_HAL_PSW_CDC_1                0x00000001UL
/*! Bit mask (bit 8) for GW (Global Address Register Write Permission) */
# define OS_HAL_PSW_GW_MASK              0x00000100UL
/*! Bit mask (bit 14) for safety task identifier */
# define OS_HAL_PSW_S_MASK               0x00004000UL
/*! Bit mask (bit 9) for IS (Interrupt Stack Control) */
# define OS_HAL_PSW_IS_MASK              0x00000200UL
/*! Bit mask (bits 11,10) for IO (Access Privilege Level Control) */
# define OS_HAL_PSW_IO_MASK              0x00000C00UL
/*! Bit value (bits 11,10) for supervisor mode */
# define OS_HAL_PSW_IO_SUPERVISOR        0x00000800UL
/*! Bit value (bits 11,10) for user mode */
# define OS_HAL_PSW_IO_USER              0x00000400UL
/*! Bit mask (bit 13,12) for PRS (Protection Register Set) */
# define OS_HAL_PSW_PRS_MASK             0x00003000UL
/*! Bit value (bits 13,12) for PRS0 (Protection Register Set 0) */
# define OS_HAL_PSW_PRS_PS0              0x00000000UL
/*! Bit value (bits 13,12) for PRS1 (Protection Register Set 1) */
# define OS_HAL_PSW_PRS_PS1              0x00001000UL
/*! Bit value (bits 13,12) for PRS2 (Protection Register Set 2) */
# define OS_HAL_PSW_PRS_PS2              0x00002000UL
/*! Bit value (bits 13,12) for PRS3 (Protection Register Set 3) */
# define OS_HAL_PSW_PRS_PS3              0x00003000UL

/*! Offset of PSW in CSA upper context. */
# define OS_HAL_CSA_PSW_OFFSET           (4U)
/*! Offset of stack pointer A10 (SP) in CSA upper context. */
# define OS_HAL_CSA_SP_OFFSET            (8U)
/*! Offset of return address A11 (RA) in CSA upper context. */
# define OS_HAL_CSA_RA_OFFSET            (12U)

/*! Core special function register for multicore start */
# define OS_HAL_CORE_161_EP_CORE0_CSFR_BASE       0xF8810000UL
# define OS_HAL_CORE_161_EP_CORE0_SFR_BASE        0xF8800000UL
# define OS_HAL_CORE_161_EP_CORE1_CSFR_BASE       0xF8830000UL
# define OS_HAL_CORE_161_EP_CORE1_SFR_BASE        0xF8820000UL
# define OS_HAL_CORE_161_EP_CORE2_CSFR_BASE       0xF8850000UL
# define OS_HAL_CORE_161_EP_CORE2_SFR_BASE        0xF8840000UL
# define OS_HAL_CORE0_PC                          (OS_HAL_CORE_161_EP_CORE0_CSFR_BASE + 0xFE08UL)
# define OS_HAL_CORE0_DBGSR                       (OS_HAL_CORE_161_EP_CORE0_CSFR_BASE + 0xFD00UL)
# define OS_HAL_CORE0_SYSCON                      (OS_HAL_CORE_161_EP_CORE0_CSFR_BASE + 0xFE14UL)
# define OS_HAL_CORE1_PC                          (OS_HAL_CORE_161_EP_CORE1_CSFR_BASE + 0xFE08UL)
# define OS_HAL_CORE1_DBGSR                       (OS_HAL_CORE_161_EP_CORE1_CSFR_BASE + 0xFD00UL)
# define OS_HAL_CORE1_SYSCON                      (OS_HAL_CORE_161_EP_CORE1_CSFR_BASE + 0xFE14UL)
# define OS_HAL_CORE2_PC                          (OS_HAL_CORE_161_EP_CORE2_CSFR_BASE + 0xFE08UL)
# define OS_HAL_CORE2_DBGSR                       (OS_HAL_CORE_161_EP_CORE2_CSFR_BASE + 0xFD00UL)
# define OS_HAL_CORE2_SYSCON                      (OS_HAL_CORE_161_EP_CORE2_CSFR_BASE + 0xFE14UL)
# define OS_HAL_DBGSR_START_CORE                  (0x00000004UL)

/*! Define the number of protection sets */
# define OS_HAL_COREMPU_NUM_OF_PS        4

/*! Core MPU registers to specify regions for data protection */
# define OS_HAL_COREMPU_DPR_BASE         0xC000U
/*! Register for lower boundary */
# define OS_HAL_COREMPU_DPR_LOW(x)       (OS_HAL_COREMPU_DPR_BASE + ((x)*8U))                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Register for upper boundary */
# define OS_HAL_COREMPU_DPR_UPPER(x)     (OS_HAL_COREMPU_DPR_BASE + 4U +((x)*8U))                                       /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Core MPU registers to specify regions for data protection */
# define OS_HAL_COREMPU_CPR_BASE         0xD000U
/*! Register for lower boundary */
# define OS_HAL_COREMPU_CPR_LOW(x)       (OS_HAL_COREMPU_CPR_BASE + ((x)*8U))                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Register for upper boundary */
# define OS_HAL_COREMPU_CPR_UPPER(x)     (OS_HAL_COREMPU_CPR_BASE + 4U +((x)*8U))                                       /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Core MPU registers to specify access rights */
/*! Read access rights */
# define OS_HAL_COREMPU_DPRE(x)          (0xE010U + ((x)*4U))                                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Write access rights */
# define OS_HAL_COREMPU_DPWE(x)          (0xE020U + ((x)*4U))                                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Execution access rights */
# define OS_HAL_COREMPU_CPXE(x)          (0xE000U + ((x)*4U))                                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Predefined value to enable individual MPU region */
# define OS_HAL_COREMPU_ENABLE_REGION0   (0x00000001UL)
# define OS_HAL_COREMPU_ENABLE_REGION1   (0x00000002UL)
# define OS_HAL_COREMPU_ENABLE_REGION2   (0x00000004UL)
# define OS_HAL_COREMPU_ENABLE_REGION3   (0x00000008UL)
# define OS_HAL_COREMPU_ENABLE_REGION4   (0x00000010UL)
# define OS_HAL_COREMPU_ENABLE_REGION5   (0x00000020UL)
# define OS_HAL_COREMPU_ENABLE_REGION6   (0x00000040UL)
# define OS_HAL_COREMPU_ENABLE_REGION7   (0x00000080UL)
# define OS_HAL_COREMPU_ENABLE_REGION8   (0x00000100UL)
# define OS_HAL_COREMPU_ENABLE_REGION9   (0x00000200UL)
# define OS_HAL_COREMPU_ENABLE_REGION10  (0x00000400UL)
# define OS_HAL_COREMPU_ENABLE_REGION11  (0x00000800UL)
# define OS_HAL_COREMPU_ENABLE_REGION12  (0x00001000UL)
# define OS_HAL_COREMPU_ENABLE_REGION13  (0x00002000UL)
# define OS_HAL_COREMPU_ENABLE_REGION14  (0x00004000UL)
# define OS_HAL_COREMPU_ENABLE_REGION15  (0x00008000UL)

/*! Predefined value to disable individual MPU region */
# define OS_HAL_COREMPU_DISABLE_REGION0  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION1  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION2  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION3  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION4  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION5  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION6  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION7  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION8  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION9  (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION10 (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION11 (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION12 (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION13 (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION14 (0x00000000UL)
# define OS_HAL_COREMPU_DISABLE_REGION15 (0x00000000UL)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_GetCsaAddress()
 **********************************************************************************************************************/
/*! \brief          This function decodes the physical address of the CSA frame from the encoded pointer x.
 *
 *  \param[in]      x        Encoded pointer to the CSA frame, e.g.: raw value read from PCXI.
 *
 *  \return         The physical memory address of the CSA frame pointed by x.
 *
 *  \context        ANY
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
# define Os_Hal_GetCsaAddress(x)            (                                           \
                                              (((x) & OS_HAL_PCXI_PCXS_MASK) << 12) |   \
                                              (((x) & OS_HAL_PCXI_PCXO_MASK) << 6)      \
                                            )                                                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */

/***********************************************************************************************************************
 *  Os_Hal_SetDataRegion()
 **********************************************************************************************************************/
/*! \brief          Set a data MPU region
 *  \param[in]      Slot           Region slot. It must be in range [0, 15].
 *  \param[in]      LowerValue     Lower boundary of the region
 *  \param[in]      UpperValue     Upper boundary of the region
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
# define Os_Hal_SetDataRegion(Slot, LowerValue, UpperValue)                                                 \
         switch(Slot)                                                                                       \
         {                                                                                                  \
           case 0:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(0), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(0), (UpperValue));                                        \
             break;                                                                                         \
           case 1:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(1), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(1), (UpperValue));                                        \
             break;                                                                                         \
           case 2:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(2), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(2), (UpperValue));                                        \
             break;                                                                                         \
           case 3:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(3), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(3), (UpperValue));                                        \
             break;                                                                                         \
           case 4:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(4), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(4), (UpperValue));                                        \
             break;                                                                                         \
           case 5:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(5), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(5), (UpperValue));                                        \
             break;                                                                                         \
           case 6:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(6), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(6), (UpperValue));                                        \
             break;                                                                                         \
           case 7:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(7), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(7), (UpperValue));                                        \
             break;                                                                                         \
           case 8:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(8), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(8), (UpperValue));                                        \
             break;                                                                                         \
           case 9:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(9), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(9), (UpperValue));                                        \
             break;                                                                                         \
           case 10:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(10), (LowerValue));                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(10), (UpperValue));                                       \
             break;                                                                                         \
           case 11:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(11), (LowerValue));                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(11), (UpperValue));                                       \
             break;                                                                                         \
           case 12:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(12), (LowerValue));                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(12), (UpperValue));                                       \
             break;                                                                                         \
           case 13:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(13), (LowerValue));                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(13), (UpperValue));                                       \
             break;                                                                                         \
           case 14:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(14), (LowerValue));                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(14), (UpperValue));                                       \
             break;                                                                                         \
           case 15:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(15), (LowerValue));                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(15), (UpperValue));                                       \
             break;                                                                                         \
           default:                                                                                         \
             break;                                                                                         \
         }                                                                                                              /* PRQA S 3412 */ /* MD_MSR_19.4 */

/***********************************************************************************************************************
 *  Os_Hal_SetCodeRegion()
 **********************************************************************************************************************/
/*! \brief          Set a code MPU region
 *  \param[in]      Slot           Region slot. It must be in range [0, 7].
 *  \param[in]      LowerValue     Lower boundary of the region
 *  \param[in]      UpperValue     Upper boundary of the region
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
# define Os_Hal_SetCodeRegion(Slot, LowerValue, UpperValue)                                                 \
         switch(Slot)                                                                                       \
         {                                                                                                  \
           case 0:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW(0), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER(0), (UpperValue));                                        \
             break;                                                                                         \
           case 1:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW(1), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER(1), (UpperValue));                                        \
             break;                                                                                         \
           case 2:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW(2), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER(2), (UpperValue));                                        \
             break;                                                                                         \
           case 3:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW(3), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER(3), (UpperValue));                                        \
             break;                                                                                         \
           case 4:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW(4), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER(4), (UpperValue));                                        \
             break;                                                                                         \
           case 5:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW(5), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER(5), (UpperValue));                                        \
             break;                                                                                         \
           case 6:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW(6), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER(6), (UpperValue));                                        \
             break;                                                                                         \
           case 7:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW(7), (LowerValue));                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER(7), (UpperValue));                                        \
             break;                                                                                         \
           default:                                                                                         \
             break;                                                                                         \
         }                                                                                                              /* PRQA S 3412 */ /* MD_MSR_19.4 */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessDPRE()
 **********************************************************************************************************************/
/*! \brief        Initial read access rights for all protection sets.
 *  \details      This function initializes the DPRE register for all protection sets.
 *  \param[in]    Value[OS_HAL_COREMPU_NUM_OF_PS]        The access right values for all protection sets.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_InitializeAccessDPRE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
));

/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessDPWE()
 **********************************************************************************************************************/
/*! \brief        Initial write access rights for all protection sets.
 *  \details      This function initializes the DPWE register for all protection sets.
 *  \param[in]    Value[OS_HAL_COREMPU_NUM_OF_PS]        The access right values for all protection sets.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_InitializeAccessDPWE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
));

/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessCPXE()
 **********************************************************************************************************************/
/*! \brief        Initial execution rights for all protection sets.
 *  \details      This function initializes the CPXE register for all protection sets.
 *  \param[in]    Value[OS_HAL_COREMPU_NUM_OF_PS]        The access right values for all protection sets.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_InitializeAccessCPXE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
));

/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessDPRE()
 **********************************************************************************************************************/
/*! \brief          Modify the read access rights for a particular protection set.
 *  \details        This function modifies the DPRE register for all protection sets.
 *  \param[in]      ProtectionSet  Target protection set. It must be in range [0, 3].
 *  \param[in]      Mask           Mask of the involved regions
 *  \param[in]      Value          Access rights of the involved regions.
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ReadModifyAccessDPRE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
));

/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessDPWE()
 **********************************************************************************************************************/
/*! \brief          Modify the write access rights for a particular protection set.
 *  \details        This function modifies the DPWE register for all protection sets.
 *  \param[in]      ProtectionSet  Target protection set. It must be in range [0, 3].
 *  \param[in]      Mask           Mask of the involved regions
 *  \param[in]      Value          Access rights of the involved regions.
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ReadModifyAccessDPWE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
));

/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessCPXE()
 **********************************************************************************************************************/
/*! \brief          Modify execution access rights for a particular protection set.
 *  \details        This function modifies the CPXE register for all protection sets.
 *  \param[in]      ProtectionSet  Target protection set. It must be in range [0, 3].
 *  \param[in]      Mask           Mask of the involved regions
 *  \param[in]      Value          Access rights of the involved regions.
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ReadModifyAccessCPXE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
));

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* OS_HAL_CORE_161_EPINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_161_EPInt.h
 *********************************************************************************************************************/
