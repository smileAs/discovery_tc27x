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
 *  \defgroup   Os_Hal HAL
 *  \brief      The HAL provides the platform specific low level part of the OS. It has to be implemented by the
 *              platform.
 *  \details    All files given here define the HAL and can be seen as a template to implement a new platform.
 */
/**
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_Entry  HAL Entry
 *  \brief      This component handles hardware exceptions and interrupts.
 *  \details
 *  Most of the HAL consists of macros and functions that are called by the kernel via the
 *  HAL interface. These perform the required low level operations by accessing the hardware and then return.
 *  The entry component is an exception to this. It handles exceptions: either synchronous hardware traps or
 *  asynchronous device interrupts. So we have some kind of control inversion here.
 *
 *  First the control is passed to the HAL, which then passes it to the kernel or the application.
 *  After the kernel has finished, control is passed back to the HAL for in order to restore the CPU
 *  state and resume processing from the point at which the exception occurred.
 *
 *  The exact implementation of this code is under the control of the HAL implementer. As long as it interacts
 *  correctly with the functions defined in Kernel Interface it may take any form. However there is typically
 *  the entry type pattern which is listed in this component description.
 *
 *  If there are any statements within a HAL function, which have influence to the control flow, the platform
 *  developer has to ensure that all paths are covered by tests (MC/DC). If this it not possible, the
 *  functionality has to be ensured by review.
 *
 *  Timing Protection Interrupt
 *  ---------------------------
 *  The kernel handles timing protection interrupts in an ISR. The ISR has to be executed with highest priority
 *  (or NMI).
 *
 *  Inter Processor Interrupt
 *  -------------------------
 *  The kernel handles inter processor interrupts in an ISR.
 *
 *   \{
 *  \file       Os_Hal_EntryInt.h
 *  \brief      This component handles hardware exceptions and interrupts.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#if !defined(OS_HAL_ENTRYINT_H)
# define OS_HAL_ENTRYINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_KernelInt.h"
# include "Os_TrapInt.h"

/* Os hal dependencies */
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_InterruptInt.h"
# include "Os_Hal_TrapInt.h"


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
/*! \brief        Performs the HAL specific prologue before the core function Os_MemFault is called.
 *  \details      This function shall switch the stack to the kernel stack of the core with CoreId
 *  \param[in]    CoreId    The ID of the core, on which the memory exception occurs. It must be in range [0, 6].
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_MemFault,
(
  uint32 CoreId
));


/***********************************************************************************************************************
 *  Os_Hal_SysCall()
 **********************************************************************************************************************/
/*! \brief        Performs the HAL specific prologue before the core function Os_TrapHandler is called.
 *  \details      This function shall check the trap identification number and calculate the caller interrupt state.
 *  \param[in]    Tin    The trap identification number. It must be in range [0, 7].
 *  \param[in]    Pcxi   The previous interrupt state.
 *  \param[in]    Packet The parameter pointer. Parameter must not be NULL.
 *  \retval       The possibly modified PCXI, which is to be restored when system call returns.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(uint32, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_SysCall,
(
  uint32 Tin,
  uint32 Pcxi,
  P2VAR(Os_TrapPacketType, AUTOMATIC, OS_VAR_NOINIT) Packet
));

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif /* OS_HAL_ENTRYINT_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_EntryInt.h
 **********************************************************************************************************************/
