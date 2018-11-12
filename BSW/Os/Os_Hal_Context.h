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
 *  \addtogroup Os_Hal_Context
 *  \trace      CREQ-1201
 *
 *  \{
 *  \file       Os_Hal_Context.h
 *  \brief      Context switching primitives.
 *  \details    Hardware information can be found in:
 *              "TriCore TC1.6P & TC1.6E - Core Architecture (Volume 1, V1.0 D10 2012-12)".
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined (OS_HAL_CONTEXT_H)                                                                                         /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
# define OS_HAL_CONTEXT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_Hal_ContextInt.h"
# include "Os_Hal_Context_Lcfg.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Core.h"

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
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_ContextInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextInit,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 SavedPCXIRaw;

  /* #10 Save the current PCXI, since this function is called inside another context */
  SavedPCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);

  /* #20 Create the reserved CSA */
  Os_Hal_ContextIntInitilizeReserved(Config, Context);                                                                  /* SBSW_OS_HAL_FC_CALLER */

  /* #30 Create the actual CSA */
  Os_Hal_ContextIntInitilize(Config, Context);                                                                          /* SBSW_OS_HAL_FC_CALLER */

  /* #40 Restore the old PCXI */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, SavedPCXIRaw);
  Os_Hal_Isync();
}

/***********************************************************************************************************************
 *  Os_Hal_ContextReset()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextReset,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 SavedPCXIRaw;

  /* #10 Save the current PCXI, since this function is called inside another context */
  SavedPCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);

  /* #20 Cleanup the CSAs and re-initialize the context */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, Context->PCXI);
  Os_Hal_Isync();
  Os_Hal_ContextIntCleanupCSAs(Context);                                                                                /* SBSW_OS_HAL_FC_CALLER */
  Os_Hal_ContextIntInitilizeReserved(Config, Context);                                                                  /* SBSW_OS_HAL_FC_CALLER */
  Os_Hal_ContextIntInitilize(Config, Context);                                                                          /* SBSW_OS_HAL_FC_CALLER */

  /* #30 Restore the old PCXI */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, SavedPCXIRaw);
  Os_Hal_Isync();
}

/***********************************************************************************************************************
 *  Os_Hal_ContextSetParameter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextSetParameter,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(void, AUTOMATIC, OS_VAR_NOINIT) Parameter
))
{
  Context->A4 = (uint32)Parameter;                                                                                      /* SBSW_OS_HAL_PWA_CALLER */ /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
}

/***********************************************************************************************************************
 *  Os_Hal_ContextSetStack()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextSetStack,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) Stack
))
{
  uint32 PCXIAddr;
  
  if(Os_MpIsEnabled() != 0)
  {
    Context->MpuRegionForStackLow = Stack->StackRegionStart;                                                            /* SBSW_OS_HAL_PWA_CALLER */
    Context->MpuRegionForStackUpper = Stack->StackRegionEnd;                                                            /* SBSW_OS_HAL_PWA_CALLER */
  }
  
  PCXIAddr = Os_Hal_GetCsaAddress(Context->PCXI);
  *(uint32*)(PCXIAddr + OS_HAL_CSA_SP_OFFSET) = Stack->StackRegionEnd;                                                  /* SBSW_OS_HAL_PWA_PCXI_SERVICEFUNCTION */ /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
}

/***********************************************************************************************************************
 *  Os_Hal_ContextSetInterruptState()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextSetInterruptState,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_InterruptStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  Context->PCXI &= (~OS_HAL_PCXI_PCPN_MASK) & (~OS_HAL_PCXI_PIE_MASK);                                                  /* SBSW_OS_HAL_PWA_CALLER */
  Context->PCXI |= (*InterruptState & OS_HAL_ICR_INT_MASK) << OS_HAL_PCXI_IE_TO_PIE;                                    /* SBSW_OS_HAL_PWA_CALLER */
  Context->PCXI |= (*InterruptState & OS_HAL_ICR_INT_LEVEL_MASK) << OS_HAL_PCXI_CCPN_TO_PCPN;                           /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_ContextFirstResume()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextFirstResume,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  uint32 PCXIRaw;

  /* #10 Clean up the CSAs used by the startup code */
  for(
       PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET); 
       (PCXIRaw & OS_HAL_PCXI_PCX_MASK) != 0x0UL; 
       PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET)
     )
  {
    Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, PCXIRaw & ~OS_HAL_PCXI_UL_MASK);
    Os_Hal_Isync();
    Os_Hal_Rslcx();
  }

  /* #20 Restore the next thread context */
  Os_Hal_ContextIntRestore(Next);                                                                                       /* SBSW_OS_HAL_FC_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_ContextResetAndResume()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextResetAndResume,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  /* #10 Cleanup the CSAs and re-initialize the context */
  Os_Hal_ContextIntCleanupCSAs(Current);                                                                                /* SBSW_OS_HAL_FC_CALLER */
  Os_Hal_ContextIntInitilizeReserved(CurrentConfig, Current);                                                           /* SBSW_OS_HAL_FC_CALLER */
  Os_Hal_ContextIntInitilize(CurrentConfig, Current);                                                                   /* SBSW_OS_HAL_FC_CALLER */

  /* #20 Restore the next PCXI and the link register */
  Os_Hal_ContextIntRestore(Next);                                                                                       /* SBSW_OS_HAL_FC_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_ContextAbort()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextAbort,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 SavedPCXIRaw;

  /* #10 Save the current PCXI, since this function is called inside another context */
  SavedPCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);

  /* #20 Cleanup the CSAs and re-initialize the context only with the reserved CSA */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, Context->PCXI);
  Os_Hal_Isync();
  Os_Hal_ContextIntCleanupCSAs(Context);                                                                                /* SBSW_OS_HAL_FC_CALLER */
  Os_Hal_ContextIntInitilizeReserved(Config, Context);                                                                  /* SBSW_OS_HAL_FC_CALLER */

  /* #30 Overwrite the context pointer */
  Context->PCXI = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);                                                                      /* SBSW_OS_HAL_PWA_CALLER */

  /* #40 Overwrite the link register to the address of Os_IsrEpilogue */
  Context->Lr = Config->ReturnAddress;                                                                                  /* SBSW_OS_HAL_PWA_CALLER */

  /* #50 Restore the old PCXI */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, SavedPCXIRaw);
  Os_Hal_Isync();
}

/***********************************************************************************************************************
 *  Os_Hal_ContextReturn()
 **********************************************************************************************************************/
 /*!
  *
  * Internal comment removed.
 *
 *
 *
  */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_ContextReturn,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  /* #10 Clean up the used CSAs. */
  Os_Hal_ContextIntCleanupCSAs(Current);                                                                                /* SBSW_OS_HAL_FC_CALLER */

  /* #20 Restore the saved context. The interrupt state is assumed to be adjusted in core code */
  Os_Hal_ContextIntRestore(Next);                                                                                       /* SBSW_OS_HAL_FC_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_ContextIsExceptionContextSupported()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
    Os_Hal_ContextIsExceptionContextSupported,( void ))
{
  return 0;
}

/***********************************************************************************************************************
*  Os_Hal_ContextIntCleanupCSAs()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntCleanupCSAs,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 PCXIRaw;
  uint32 FirstPCXIAddr;

  /* #10 Create a dummy CSA just for the case that the context list is empty */
  Os_Hal_Svlcx();
  Os_Hal_Dsync();

  /* #20 Cleanup the CSAs based on the stored InitPCXI */
  PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);
  FirstPCXIAddr = Os_Hal_GetCsaAddress(Context->InitPCXI);
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, *(uint32*)FirstPCXIAddr);                                                             /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  Os_Hal_Isync();
  *(uint32*)FirstPCXIAddr = Os_Hal_Mfcr(OS_HAL_FCX_OFFSET);                                                             /* PRQA S 0306 */ /* MD_Os_Hal_0306 */ /* SBSW_OS_HAL_PWA_FIRST_PCXI */
  Os_Hal_Mtcr(OS_HAL_FCX_OFFSET, PCXIRaw);
  Os_Hal_Isync();
}

/***********************************************************************************************************************
*  Os_Hal_ContextIntInitilize()
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
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntInitilize,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 PCXIRaw;
  uint32 PCXIAddr;

  /* #10 Create a new CSA entry (lower context), which is actually used as part of the initial context */
  Os_Hal_Svlcx();
  Os_Hal_Dsync();

  /* #20 Adapt the created CSA entry based on the thread configuration */
  PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);
  PCXIAddr = Os_Hal_GetCsaAddress(PCXIRaw);

  /* #30 Initialize the program status word with call depth 1 due to the reserved CSA frame */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_PSW_OFFSET) = CurrentConfig->ProgramStatus | OS_HAL_PSW_CDC_1;                       /* PRQA S 0306 */ /* MD_Os_Hal_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #40 Initialize the stack pointer */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_SP_OFFSET) = CurrentConfig->StackEndAddr;                                            /* PRQA S 0306 */ /* MD_Os_Hal_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #50 Initialize the return address */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_RA_OFFSET) = CurrentConfig->ReturnAddress;                                           /* PRQA S 0306 */ /* MD_Os_Hal_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #60 Initialize the interrupt status */
  PCXIRaw &= (~OS_HAL_PCXI_PCPN_MASK) & (~OS_HAL_PCXI_PIE_MASK);
  PCXIRaw |= OS_HAL_PCXI_UL_MASK | CurrentConfig->IntStatus;
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, PCXIRaw);
  Os_Hal_Isync();

  /* #70 Initialize the MPU stack settings */
  if(Os_MpIsEnabled() != 0)
  {
    Context->MpuRegionForStackLow = CurrentConfig->StackStartAddr;                                                      /* SBSW_OS_HAL_PWA_CALLER */
    Context->MpuRegionForStackUpper = CurrentConfig->StackEndAddr;                                                      /* SBSW_OS_HAL_PWA_CALLER */
  }

  /* #80 Initialize the runtime context variable */
  Context->PCXI = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);                                                                      /* SBSW_OS_HAL_PWA_CALLER */
  Context->Lr = CurrentConfig->Entry;                                                                                   /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
*  Os_Hal_ContextIntInitilizeReserved()
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
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntInitilizeReserved,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 PCXIRaw;
  uint32 PCXIAddr;

  /* #10 Create a new CSA entry (lower context), which is a reserved context and is only used when ISRs
   *     terminate or tasks terminate without calling TerminateTask */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, 0x00000000UL);
  Os_Hal_Isync();
  Os_Hal_Svlcx();
  Os_Hal_Dsync();

  /* #20 Adapt the created CSA entry based on the thread configuration */
  PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);
  PCXIAddr = Os_Hal_GetCsaAddress(PCXIRaw);

  /* #30 Initialize the program status word */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_PSW_OFFSET) = CurrentConfig->ProgramStatus;                                          /* PRQA S 0306 */ /* MD_Os_Hal_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #40 Initialize the stack pointer */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_SP_OFFSET) = CurrentConfig->StackEndAddr;                                            /* PRQA S 0306 */ /* MD_Os_Hal_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #50 Initialize the return address. When this CSA is restored, the program should never return */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_RA_OFFSET) = 0x00000000UL;                                                           /* PRQA S 0306 */ /* MD_Os_Hal_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #60 Initialize the interrupt status */
  PCXIRaw &= (~OS_HAL_PCXI_PCPN_MASK) & (~OS_HAL_PCXI_PIE_MASK);
  PCXIRaw |= OS_HAL_PCXI_UL_MASK | CurrentConfig->IntStatus;
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, PCXIRaw);
  Os_Hal_Isync();

  /* #70 Initialize the runtime context variable */
  Context->InitPCXI = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);                                                                  /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
*  Os_Hal_ContextIntSave()
**********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_ContextIntSave,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  Context->PCXI = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);                                                                      /* SBSW_OS_HAL_PWA_CALLER */
  Context->Lr = Os_Hal_Mfa11();                                                                                         /* SBSW_OS_HAL_PWA_CALLER */

  if(Os_MpIsEnabled() != 0)
  {
    Context->MpuRegionForStackLow = Os_Hal_Mfcr(OS_HAL_COREMPU_DPR_LOW(0));                                             /* SBSW_OS_HAL_PWA_CALLER */
    Context->MpuRegionForStackUpper = Os_Hal_Mfcr(OS_HAL_COREMPU_DPR_UPPER(0));                                         /* SBSW_OS_HAL_PWA_CALLER */
  }
}

/***********************************************************************************************************************
*  Os_Hal_ContextIntRestore()
**********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_ContextIntRestore,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  if(Os_MpIsEnabled() != 0)
  {
    Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER(0), Context->MpuRegionForStackUpper);
    Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW(0), Context->MpuRegionForStackLow);
  }

  Os_Hal_Mta11(Context->Lr);
  Os_Hal_Mta4(Context->A4);
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, Context->PCXI);
  Os_Hal_Isync();

  Os_Hal_ContextIntGo();
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* OS_HAL_CONTEXT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context.h
 **********************************************************************************************************************/

