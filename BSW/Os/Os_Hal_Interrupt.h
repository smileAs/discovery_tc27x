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
 *  \addtogroup Os_Hal_Interrupt
 *  \{
 *
 *  \file     Os_Hal_Interrupt.h
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined (OS_HAL_INTERRUPT_H)                                                                                       /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
# define OS_HAL_INTERRUPT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_InterruptInt.h"
# include "Os_Hal_Interrupt_Cfg.h"
# include "Os_Hal_Interrupt_Lcfg.h"

/* Os kernel module declarations */
# include "Os_Cfg.h"
# include "Os_Interrupt.h"
# include "Os_TimingProtection.h"

/* Os Hal dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Derivative.h"
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

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_IntSuspend()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void,                                                                      /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_CODE, OS_ALWAYS_INLINE, Os_Hal_IntSuspend,
(
  P2VAR(Os_Hal_IntStateType, AUTOMATIC, OS_APPL_DATA) State
))
{
  /* #10 Get current state. */
  (*State) = Os_Hal_GetIntState();                                                                                      /* SBSW_OS_HAL_PWA_CALLER */

  /* #20 Disable interrupt state. */
  Os_Hal_Disable();
}

# if defined (OS_CFG_COMPILER_HIGHTEC)
#  pragma GCC diagnostic ignored "-Wuninitialized" /* This suppresses the warning with regard to "possibly 
                                                      uninitialized variable" for "State". This can be suppressed
                                                      here, since pre-condition in design ensures that the caller 
                                                      always initialize the State variable. */
                                                      
# endif

/***********************************************************************************************************************
 *  Os_Hal_IntResume()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntResume,
(
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_APPL_DATA) State
))
{
  /* #10 Set the interrupt state to the desired state with the assumption that the current interrupt is disabled. */
  Os_Hal_ResumeIntState(*State);
}

# if defined (OS_CFG_COMPILER_HIGHTEC)
#  pragma GCC diagnostic warning "-Wuninitialized"
# endif

/***********************************************************************************************************************
 *  Os_Hal_IntSuspendLevel()
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
Os_Hal_IntSuspendLevel,
(
  P2VAR(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
))
{
  Os_Hal_IntLevelType CurrentLevel;

  /* #10 Store the current interrupt level. */
  CurrentLevel = Os_Hal_GetIntLevel();

  /* #20 Set the interrupt level. */
  Os_Hal_SetIntLevel((uint32)(*Level));

  /* #30 Return the stored level. */
  *Level = CurrentLevel;                                                                                                /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_IntResumeLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntResumeLevel,
(
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
))
{
  /* #10 Set the requested interrupt level. */
  Os_Hal_SetIntLevel((uint32)(*Level));
}

/***********************************************************************************************************************
 *  Os_Hal_IntDisableCat2()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntDisableCat2, (void))
{
  Os_Hal_SetIntLevel(OS_CFG_HAL_ISR2_DISABLE_LEVEL);
}

/***********************************************************************************************************************
 *  Os_Hal_IntEnableCat2()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntEnableCat2, (void))
{
  Os_Hal_SetIntLevel(0);
}

/***********************************************************************************************************************
 *  Os_Hal_IntSuspendCat2()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntSuspendCat2,
(
  P2VAR(Os_Hal_IntCat2StateType, AUTOMATIC, OS_APPL_DATA) State
))
{
  *State = Os_Hal_GetIntLevel();                                                                                        /* SBSW_OS_HAL_PWA_CALLER */
  Os_Hal_SetIntLevel(OS_CFG_HAL_ISR2_DISABLE_LEVEL);
}

/***********************************************************************************************************************
 *  Os_Hal_IntResumeCat2()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntResumeCat2,
(
  P2CONST(Os_Hal_IntCat2StateType, AUTOMATIC, OS_APPL_DATA) State
))
{
  Os_Hal_SetIntLevel((uint32)(*State));
}

/***********************************************************************************************************************
 *  Os_Hal_IntSuspendCat1()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void,                                                                      /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_CODE, OS_ALWAYS_INLINE, Os_Hal_IntSuspendCat1,
(
  P2VAR(Os_Hal_IntCat1StateType, AUTOMATIC, OS_APPL_DATA) State
))
{
  if(Os_TpIsEnabled() != 0)
  {
    *State = Os_Hal_GetIntLevel();                                                                                      /* SBSW_OS_HAL_PWA_CALLER */
    Os_Hal_SetIntLevel(OS_CFG_HAL_ISR1_DISABLE_LEVEL);
  }else
  {
    Os_Hal_IntSuspend(State);                                                                                           /* SBSW_OS_HAL_FC_CALLER */
  }
}

/***********************************************************************************************************************
 *  Os_Hal_IntResumeCat1()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void,                                                                      /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_CODE, OS_ALWAYS_INLINE, Os_Hal_IntResumeCat1,
(
  P2CONST(Os_Hal_IntCat1StateType, AUTOMATIC, OS_APPL_DATA) State
))
{
  if(Os_TpIsEnabled() != 0)
  {
    Os_Hal_IntResumeLevel(State);                                                                                       /* SBSW_OS_HAL_FC_CALLER */
  }else
  {
    Os_Hal_IntResume(State);                                                                                            /* SBSW_OS_HAL_FC_CALLER */
  }
}

/***********************************************************************************************************************
 *  Os_Hal_IntSuspendTp()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void,                                                                      /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_CODE, OS_ALWAYS_INLINE, Os_Hal_IntSuspendTp,
(
  P2VAR(Os_Hal_IntTpStateType, AUTOMATIC, OS_APPL_DATA) State
))
{
  /*! \note Timing protection uses normal timer interrupt, this function is the same as Os_Hal_IntSuspend */
  Os_Hal_IntSuspend(State);                                                                                             /* SBSW_OS_HAL_FC_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_IntResumeTp()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntResumeTp,
(
  P2CONST(Os_Hal_IntTpStateType, AUTOMATIC, OS_APPL_DATA) State
))
{
  /*! \note Timing protection uses normal timer interrupt, this function is the same as Os_Hal_IntResume */
  Os_Hal_IntResume(State);                                                                                              /* SBSW_OS_HAL_FC_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_IntDisableSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntDisableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
))
{
  /* #10 Disable the given interrupt source in its SRC register. */
  *((volatile uint32*) (OS_HAL_INT_SRC_BASE + (IsrConfig->Source))) &= ~OS_HAL_INT_SRC_SRE_MASK;                        /* PRQA S 0303 */ /* MD_Os_Hal_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG */
}

/***********************************************************************************************************************
 *  Os_Hal_IntEnableSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntEnableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
))
{
  /* #10 Enable the given interrupt source in its SRC register. */
  *((volatile uint32*) (OS_HAL_INT_SRC_BASE + (IsrConfig->Source))) |= OS_HAL_INT_SRC_SRE_MASK;                         /* PRQA S 0303 */ /* MD_Os_Hal_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG */
}

/***********************************************************************************************************************
 *  Os_Hal_IntIsClearPendingSupported()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntIsClearPendingSupported,( void ))
{
  return !0;
}

/***********************************************************************************************************************
 *  Os_Hal_IntClearPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntClearPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
))
{
  /* #10 Clear the interrupt pending flag in its SRC register. */
  *((volatile uint32*) (OS_HAL_INT_SRC_BASE + (IsrConfig->Source))) |= OS_HAL_INT_SRC_CLRR_MASK;                        /* PRQA S 0303 */ /* MD_Os_Hal_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG */
}

/***********************************************************************************************************************
 *  Os_Hal_IntIsInterruptSourceEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntIsInterruptSourceEnabled,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
))
{
  volatile uint32 intSourceValue;

  intSourceValue = *((volatile uint32*) (OS_HAL_INT_SRC_BASE + (IsrConfig->Source)));                                   /* PRQA S 0303 */ /* MD_Os_Hal_0303 */

  return (Os_StdReturnType)((intSourceValue & OS_HAL_INT_SRC_SRE_MASK) != 0x0);
}

/***********************************************************************************************************************
 *  Os_Hal_IntIsInterruptPending()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntIsInterruptPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
))
{
  volatile uint32 intSourceValue;

  intSourceValue = *((volatile uint32*) (OS_HAL_INT_SRC_BASE + (IsrConfig->Source)));                                   /* PRQA S 0303 */ /* MD_Os_Hal_0303 */

  return (Os_StdReturnType)((intSourceValue & OS_HAL_INT_SRC_SRR_MASK) != 0x0);
}

/***********************************************************************************************************************
 *  Os_Hal_IntEndOfInterrupt()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntEndOfInterrupt,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
))
{
  /*! \note There is no need to acknowledge that interrupt handling in Aurix. */
  OS_IGNORE_UNREF_PARAM(IsrConfig);                                                                                     /* PRQA S 3112 */ /* MD_Os_Hal_3112 */
}

/***********************************************************************************************************************
 *  Os_Hal_IntIsrLevelIsLe(()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType,                                                          /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_CODE, OS_ALWAYS_INLINE, Os_Hal_IntIsrLevelIsLe,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig,
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) Level
))
{
  return (Os_StdReturnType)(IsrConfig->Level <= (*Level));
}

/***********************************************************************************************************************
 *  Os_Hal_IntLevelIsGt()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_ALWAYS_INLINE, Os_Hal_IntLevelIsGt,
(
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) LevelX,
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) LevelY
))
{
  return (Os_StdReturnType)((*LevelX) > (*LevelY));
}

/***********************************************************************************************************************
 *  Os_Hal_IntGetLevel()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_ALWAYS_INLINE, Os_Hal_IntGetLevel,
(
  P2VAR(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
))
{
  *Level = (Os_Hal_IntLevelType)Os_Hal_GetIntLevel();                                                                   /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_IntTrapRestore()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_ALWAYS_INLINE, Os_Hal_IntTrapRestore,
(
  P2CONST(Os_Hal_IntTrapStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  uint32 icr;

  icr = Os_Hal_Mfcr(OS_HAL_ICR_OFFSET) & ~(OS_HAL_ICR_INT_MASK | OS_HAL_ICR_INT_LEVEL_MASK);
  icr |= *InterruptState;

  Os_Hal_Mtcr(OS_HAL_ICR_OFFSET, icr);
  Os_Hal_Isync();
}

/***********************************************************************************************************************
 *  Os_Hal_IntTrapUpdate()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_ALWAYS_INLINE, Os_Hal_IntTrapUpdate,
(
  P2VAR(Os_Hal_IntTrapStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  *InterruptState = Os_Hal_Mfcr(OS_HAL_ICR_OFFSET);                                                                     /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_IntGetInterruptState()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
OS_ALWAYS_INLINE, Os_Hal_IntGetInterruptState,
(
  P2VAR(Os_Hal_InterruptStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  *InterruptState = Os_Hal_Mfcr(OS_HAL_ICR_OFFSET);                                                                     /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_IntInterruptSourceInit()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219, 3673 */ /* MD_Os_Hal_3219, MD_Os_Hal_3673_HalTemplate */
OS_ALWAYS_INLINE, Os_Hal_IntInterruptSourceInit,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptSource
))
{
  uint32 tempSRC;

  /* #10 Get the current register content. */
  tempSRC = *(volatile uint32*)(InterruptSource->Source + OS_HAL_INT_SRC_BASE);                                         /* PRQA S 0303 */ /* MD_Os_Hal_0303 */

  /* #20 Clear the bits for priority and core assignment. */
  tempSRC &= (~OS_HAL_INT_SRC_SRPN_MASK & ~OS_HAL_INT_SRC_TOS_MASK);

  /* #30 Set the required priority and core assignment. */
  tempSRC |= (InterruptSource->Level | (((uint32)(InterruptSource->CoreAssignment)) << 11));

  /* #40 Write back to the register. */
  *(volatile uint32*)(InterruptSource->Source + OS_HAL_INT_SRC_BASE) = tempSRC;                                         /* PRQA S 0303 */ /* MD_Os_Hal_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG */
}

/***********************************************************************************************************************
 *  Os_Hal_IntGetCat2LockLevel()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntGetCat2LockLevel,
(
  P2VAR(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
))
{
  *Level = OS_CFG_HAL_ISR2_DISABLE_LEVEL;                                                                               /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_IntCat2LockLevel2Cat2StateType()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntCat2StateType, OS_CODE, OS_ALWAYS_INLINE,                        /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntCat2LockLevel2Cat2StateType,
(
  Os_Hal_IntLevelType Level
))
{
  return (Os_Hal_IntCat2StateType) Level;
}

/***********************************************************************************************************************
 *  Os_Hal_IntGetCat1LockType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntDisableAllType, OS_CODE, OS_ALWAYS_INLINE,                       /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntGetCat1LockType,
(
  void
))
{
  Os_Hal_IntDisableAllType disableType;
  /* #10 Disable all interrupts by level if timing protection is enabled. */
  if(Os_TpIsEnabled() != 0)
  {
    disableType = OS_HAL_INT_DISABLE_ALL_BY_LEVEL;
  }
  /* #20 Else disable all interrupts by global flag. */
  else
  {
    disableType = OS_HAL_INT_DISABLE_ALL_BY_FLAG;
  }
  return disableType;
}

/***********************************************************************************************************************
 *  Os_Hal_IntGetCat1LockLevel()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntGetCat1LockLevel,
(
  P2VAR(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
))
{
  *Level =  OS_CFG_HAL_ISR1_DISABLE_LEVEL;                                                                              /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_IntCat1LockLevel2Cat1StateType()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntCat1StateType, OS_CODE, OS_ALWAYS_INLINE,                        /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_IntCat1LockLevel2Cat1StateType,
(
  Os_Hal_IntLevelType Level
))
{
  return (Os_Hal_IntCat1StateType) Level;
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* OS_HAL_INTERRUPT_H */

/*!
 * \}
 */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt.h
 *********************************************************************************************************************/

