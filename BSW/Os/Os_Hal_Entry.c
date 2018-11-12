/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup Os_Hal_Entry
 *  \{
 *
 *  \file       Os_Hal_Entry.c
 *  \brief      This component handles hardware exceptions and interrupts.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HAL_ENTRY_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Entry.h"

/* Os module dependencies */
#include "Os_Cfg.h"

/* Os Hal dependencies */
#include "Os_Hal_Compiler.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  Os_Hal_MemFault()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_MemFault,
(
  uint32 CoreId
))
{
  uint32 stackEnd = OsCfg_Stack_KernelStacks[CoreId]->StackRegionEnd;
  Os_Hal_Mta10(stackEnd);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(0), stackEnd);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(0), OsCfg_Stack_KernelStacks[CoreId]->StackRegionStart);
  Os_Hal_Isync();
  Os_MemFault();
}

/***********************************************************************************************************************
 *  Os_Hal_SysCall()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(uint32, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_SysCall,
(
  uint32 Tin,
  uint32 Pcxi,
  P2VAR(Os_TrapPacketType, AUTOMATIC, OS_VAR_NOINIT) Packet
))
{
  /* #10 Check that the system call identification number is valid */
  if(Tin == OS_HAL_SYSCALL_TRAP_ID)
  {
    Os_Hal_IntTrapStateType callerState;

    /* #20 Prepare the interrupt state for Os_TrapHandler */
    callerState = (Pcxi & OS_HAL_PCXI_PCPN_MASK) >> OS_HAL_PCXI_CCPN_TO_PCPN;
    callerState |= (Pcxi & OS_HAL_PCXI_PIE_MASK) >> OS_HAL_PCXI_IE_TO_PIE;

    /* #30 Call Os_TrapHandler */
    Os_TrapHandler(Packet, &callerState);                                                                               /* SBSW_OS_HAL_FC_MIXED_VAR */

    /* #40 Prepare the PCXI content for return from system call */
    Pcxi &= ~(OS_HAL_PCXI_PCPN_MASK | OS_HAL_PCXI_PIE_MASK);
    Pcxi |= (callerState & OS_HAL_ICR_INT_MASK) << OS_HAL_PCXI_IE_TO_PIE;
    Pcxi |= (callerState & OS_HAL_ICR_INT_LEVEL_MASK) << OS_HAL_PCXI_CCPN_TO_PCPN;
  }else
  {
    /* #50 If the identification number is invalid */
    Os_UnhandledSysCall();
  }

  /* #60 Return Pcxi */
  return Pcxi;
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry.c
 **********************************************************************************************************************/

