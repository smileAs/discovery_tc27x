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
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_Interrupt  HAL Interrupt
 *  \brief      Primitives for interrupt state manipulation
 *  \details
 *  This component provides the following interrupt primitives:
 *  - Enter/leave critical sections
 *  - Disable interrupt sources
 *
 *  ### Interrupt Priority Levels ###
 *  The kernel distinguishes between the following logical groups of interrupt priority levels:
 *
 *  Interrupt Priority Level    | Description
 *  :-------------------------- | :-------------------------------------------------------------------------------------
 *  Timing Protection Interrupt | The timing protection interrupt is handled on this level.
 *  Category 1 ISRs             | AUTOSAR category 1 ISRs are handled on this level.
 *  Category 2 ISRs             | AUTOSAR category 2 ISRs are handled on this level.
 *
 *  The kernel needs some primitive interrupt functions, to enter/leave critical sections on these interrupt priority
 *  levels.  Os_Hal_IntSuspend() and Os_Hal_IntResume() work either up to timing protection level or up to category 1
 *  level, depending whether timing protection is level or NMI based.
 *
 *  ![Interrupt Priorities and Relevant HAL Functions](InterruptPriorities.png)
 *
 *
 *  ### Implementation Hint ###
 *  During implementation of this module you may have to work with the following hardware properties:
 *
 *  - Core interrupt flag
 *  - Level register in interrupt controller
 *  - Timing protection interrupt flag
 *  \{
 *
 *  \file     Os_Hal_InterruptInt.h
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#if !defined (OS_HAL_INTERRUPTINT_H)
# define OS_HAL_INTERRUPTINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os kernel module dependencies */
# include "Os_Hal_Interrupt_Types.h"

/* Os module declarations */

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_DerivativeInt.h"

# if defined(OS_HAL_INTERRUPT_AURIXTC2XX_IR)                                                                                 /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
#  include "Os_Hal_InterruptController_AurixTC2xx_IRInt.h"
# elif defined(OS_HAL_INTERRUPT_AURIXTC3XX_IR)
#  include "Os_Hal_InterruptController_AurixTC3xx_IRInt.h"
# else
#  error "The selected core module is not supported!"
# endif

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! \brief         Get the current core local interrupt state.
 *  \return        Current interrupt state. 0x0 means disabled and otherwise enabled.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_GetIntState()      (Os_Hal_Mfcr(OS_HAL_ICR_OFFSET) & OS_HAL_ICR_INT_MASK)


/*! \brief         Resume the core local interrupt state.
 *  \details       This function resume the core local interrupt state with the assumption that the current
 *                 global interrupt state is disabled.
 *  \param[in]     x       Desired interrupt state.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           The current global interrupt state is disabled.
 */
# define Os_Hal_ResumeIntState(x)  Os_Hal_Mtcr(OS_HAL_ICR_OFFSET, Os_Hal_Mfcr(OS_HAL_ICR_OFFSET) | (x)); \
                                   Os_Hal_Isync()                                                                       /* PRQA S 3412 */ /* MD_MSR_19.4 */


/*! \brief         Get the current interrupt level.
 *  \return        Current interrupt level.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
/*! \brief       */
# define Os_Hal_GetIntLevel()      (Os_Hal_Mfcr(OS_HAL_ICR_OFFSET) & OS_HAL_ICR_INT_LEVEL_MASK)


/*! \brief         Set the interrupt level.
 *  \param[in]     x       Desired interrupt level.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_SetIntLevel(x) \
         Os_Hal_Mtcr(OS_HAL_ICR_OFFSET, (Os_Hal_Mfcr(OS_HAL_ICR_OFFSET) & ~OS_HAL_ICR_INT_LEVEL_MASK) | (x)); \
         Os_Hal_Isync()                                                                                                 /* PRQA S 3412 */ /* MD_MSR_19.4 */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! \brief    Interrupt source.
 *  \details  The kernel uses this data type to disable an interrupt source.
 *            This data type is needed to implement killing of applications.
 *            It is typically an interrupt index or interrupt source address. */
typedef uint32 Os_Hal_IntSourceType;


/*! \brief    Hardware specific configuration for category 2 ISRs.
 *  \details  It typically contains the interrupt priority level and the interrupt source of the ISR.
 *            The kernel uses this data type to:
 *            - Disable an interrupt source as part of killing applications.
 *            - Implement interrupt resources.
 */
struct Os_Hal_IntIsrConfigType_Tag
{
  /*! Interrupt level */
  Os_Hal_IntLevelType Level;

  /*! Interrupt source register offset */
  Os_Hal_IntSourceType Source;

  /*! The core allocation of the ISR. */
  uint8 CoreAssignment;
};


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
 *  Os_Hal_IntSuspend()
 **********************************************************************************************************************/
/*! \brief          Suspend all interrupts except NMIs.
 *  \details        Disable core local interrupt delivery and return previous interrupt state.
 *                  The kernel uses this function to enter core local critical sections inside the OS.
 *  \param[out]     State   Previous interrupt state information which allows resuming in Os_Hal_IntResume().
 *                          Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntSuspend,
(
  P2VAR(Os_Hal_IntStateType, AUTOMATIC, OS_APPL_DATA) State
));


/***********************************************************************************************************************
 *  Os_Hal_IntResume()
 **********************************************************************************************************************/
/*! \brief          Resume state returned by Os_Hal_IntSuspend().
 *  \details        Set core local interrupt delivery to a given state.
 *                  The kernel uses this function to leave core local critical sections inside the OS.
 *  \param[in]      State    Desired interrupt state. Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Os_Hal_IntSuspend() has been called and prepared State parameter.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntResume,
(
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_APPL_DATA) State
));


/***********************************************************************************************************************
 *  Os_Hal_IntSuspendLevel()
 **********************************************************************************************************************/
/*! \brief          Increase current interrupt priority level to given level and return previous one.
 *  \details        The kernel uses this function to implement AUTOSAR OS API GetResource() in case of interrupt
 *                  resources.
 *  \param[in,out]  Level   In: Desired interrupt priority level.
 *                          Out: Previous interrupt priority level which allows resuming Os_Hal_IntResumeLevel().
 *                          Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntSuspendLevel,
(
  P2VAR(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
));


/***********************************************************************************************************************
 *  Os_Hal_IntResumeLevel()
 **********************************************************************************************************************/
/*! \brief          Resume level returned by Os_Hal_IntSuspendLevel().
 *  \details        The kernel uses this function to implement AUTOSAR OS API ReleaseResource() in case of interrupt
 *                  resources.
 *  \param[in]      Level   Level returned by Os_Hal_IntSuspendLevel(). Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Os_Hal_IntSuspendLevel() has been called and prepared Level parameter.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntResumeLevel,
(
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
));


/***********************************************************************************************************************
 *  Os_Hal_IntDisableCat2()
 **********************************************************************************************************************/
/*! \brief          Disable all category 2 ISRs.
 *  \details        Disable core local interrupt delivery of category 2 ISRs.
 *                  The kernel uses this function to enter critical sections, where category 1 ISRs are allowed.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_IntDisableCat2, (void));


/***********************************************************************************************************************
 *  Os_Hal_IntEnableCat2()
 **********************************************************************************************************************/
/*! \brief          Enable category 2 ISRs but don't touch global interrupt flag.
 *  \details        Enable core local interrupt delivery of category 2 ISRs.
 *                  The kernel uses this function to leave critical sections, where category 1 ISRs are allowed.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_IntEnableCat2, (void));


/***********************************************************************************************************************
 *  Os_Hal_IntSuspendCat2()
 **********************************************************************************************************************/
/*! \brief          Suspend all category 2 ISRs.
 *  \details        Disable core local interrupt delivery of category 2 ISRs and return previous state.
 *                  The kernel uses this function to implement AUTOSAR OS API SuspendOSInterrupts().
 *  \param[out]     State   Previous interrupt state information which allows resuming in Os_Hal_IntResumeCat2().
 *                          Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntSuspendCat2,
(
  P2VAR(Os_Hal_IntCat2StateType, AUTOMATIC, OS_APPL_DATA) State
));


/***********************************************************************************************************************
 *  Os_Hal_IntResumeCat2()
 **********************************************************************************************************************/
/*! \brief          Resume state returned by Os_Hal_IntSuspendCat2().
 *  \details        Resume interrupt delivery of category 2 ISRs.
 *                  The kernel uses this function to implement AUTOSAR OS API ResumeOSInterrupts().
 *  \param[in]      State    State returned by Os_Hal_IntSuspendCat2(). Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Os_Hal_IntSuspendCat2() has been called and prepared State parameter.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntResumeCat2,
(
  P2CONST(Os_Hal_IntCat2StateType, AUTOMATIC, OS_APPL_DATA) State
));


/***********************************************************************************************************************
 *  Os_Hal_IntSuspendCat1()
 **********************************************************************************************************************/
/*! \brief          Suspend all category 1+2 ISRs.
 *  \details        Disable core local interrupt delivery of category 1+2 ISRs and return previous state.
 *                  The kernel uses this function to implement AUTOSAR OS API DisableAllInterrupts() and
 *                  SuspendAllInterrupts().
 *  \param[in,out]  State   Previous interrupt state information which allows resuming in Os_Hal_IntResumeCat1().
 *                          Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntSuspendCat1,
(
  P2VAR(Os_Hal_IntCat1StateType, AUTOMATIC, OS_APPL_DATA) State
));


/***********************************************************************************************************************
 *  Os_Hal_IntResumeCat1()
 **********************************************************************************************************************/
/*! \brief          Resume state returned by Os_Hal_IntSuspendCat1().
 *  \details        Resume interrupt delivery of category 1+2 ISRs.
 *                  The kernel uses this function to implement AUTOSAR OS API EnableAllInterrupts() and
 *                  ResumeAllInterrupts().
 *  \param[in]      State    State to resume returned by Os_Hal_IntSuspendCat1().
 *                           Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Os_Hal_IntSuspendCat1() has been called and prepared Level parameter.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntResumeCat1,
(
  P2CONST(Os_Hal_IntCat1StateType, AUTOMATIC, OS_APPL_DATA) State
));


/***********************************************************************************************************************
 *  Os_Hal_IntSuspendTp()
 **********************************************************************************************************************/
/*! \brief          Suspend all interrupts including the timing protection interrupt.
 *  \details        Disable core local interrupt delivery (inclusive timing protection interrupt) and return previous
 *                  state. The kernel uses this function to enter core local critical sections inside the OS, which
 *                  manipulates timing protection data. If timing protection is disabled, this function does not change
 *                  the current interrupt level.
 *
 *  \param[in,out]  State   Previous interrupt state information which allows resuming in Os_Hal_IntResumeTp().
 *                          Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode, if timing protection is enabled.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntSuspendTp,
(
  P2VAR(Os_Hal_IntTpStateType, AUTOMATIC, OS_APPL_DATA) State
));


/***********************************************************************************************************************
 *  Os_Hal_IntResumeTp()
 **********************************************************************************************************************/
/*! \brief          Resume state returned by Os_Hal_IntSuspendTp().
 *  \details        Set core local interrupt delivery (inclusive timing protection interrupt) to a given state.
 *                  The kernel uses this function to leave core local critical sections inside the OS, which has been
 *                  manipulated timing protection data. If timing protection is disabled, this function does not change
 *                  the current interrupt level.
 *
 *  \param[in]      State    State to resume returned by Os_Hal_IntSuspendTp().
 *                           Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode, if timing protection is enabled.
 *  \pre            Os_Hal_IntSuspendTp() has been called and prepared State parameter.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntResumeTp,
(
  P2CONST(Os_Hal_IntTpStateType, AUTOMATIC, OS_APPL_DATA) State
));


/***********************************************************************************************************************
 *  Os_Hal_IntDisableSource()
 **********************************************************************************************************************/
/*! \brief          Disable interrupt delivery for the given interrupt source.
 *  \details        -
 *
 *  \param[in]      IsrConfig   Interrupt configuration to the ISR which shall be disabled.
 *                              Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntDisableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
));


/***********************************************************************************************************************
 *  Os_Hal_IntEnableSource()
 **********************************************************************************************************************/
/*! \brief          Enable interrupt delivery for the given interrupt source.
 *  \details        -
 *
 *  \param[in]      IsrConfig   Interrupt configuration to the ISR which shall be enabled.
 *                              Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntEnableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
));


/***********************************************************************************************************************
 *  Os_Hal_IntIsClearPendingSupported()
 **********************************************************************************************************************/
/*! \brief        Returns whether the hardware supports clearing of a pending interrupt.
 *  \details      --no details--
 *
 *  \retval       !0    Pending interrupts can be cleared.
 *  \retval       0     Pending interrupts cannot be cleared.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntIsClearPendingSupported,( void ));


/***********************************************************************************************************************
 *  Os_Hal_IntClearPending()
 **********************************************************************************************************************/
/*! \brief          Clears the pending flag of the given interrupt source.
 *  \details        --no details--
 *
 *  \param[in]      IsrConfig   Interrupt configuration to the ISR which shall be cleared.
 *                              Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntClearPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
));


/***********************************************************************************************************************
 *  Os_Hal_IntIsInterruptSourceEnabled()
 **********************************************************************************************************************/
/*! \brief          Checks if the interrupt source is enabled
 *  \details        --no details--
 *
 *  \param[in]      IsrConfig   Interrupt configuration to the ISR which shall be checked.
 *                              Parameter must not be NULL.
 *  \retval         0           not enabled
 *  \retval         !0          enabled
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntIsInterruptSourceEnabled,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
));


/***********************************************************************************************************************
 *  Os_Hal_IntIsInterruptPending()
 **********************************************************************************************************************/
/*! \brief          Checks if the specified ISR has a pending request
 *  \details        --no details--
 *
 *  \param[in]      IsrConfig   Interrupt configuration to the ISR which shall be cleared.
 *                              Parameter must not be NULL.
 *  \retval         0           no pending request.
 *  \retval         !0          pending request.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntIsInterruptPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
));


/***********************************************************************************************************************
 *  Os_Hal_IntEndOfInterrupt()
 **********************************************************************************************************************/
/*! \brief          Signal hardware that interrupt processing has been completed.
 *  \details        -
 *
 *  \param[in]      IsrConfig  Interrupt configuration to the ISR which shall signal an end of interrupt.
 *                             Parameter must not be NULL.
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntEndOfInterrupt,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
));


/***********************************************************************************************************************
 *  Os_Hal_IntIsrLevelIsLe()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ISR configuration has an interrupt priority level, which is lower than
 *                  or equal to the given interrupt priority level.
 *  \details        -
 *
 *  \param[in]      IsrConfig   The ISR configuration which shall be checked. Parameter must not be NULL.
 *  \param[in]      Level       The interrupt priority level to compare with. Parameter must not be NULL.
 *
 *   \retval        !0  The configured interrupt priority level of Isr is logically lower than or equal to Level.
 *  \retval         0   The configured interrupt priority level of Isr is logically greater than Level.
 *
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \note           Candidate for compiler attributes OS_NOSIDEEFFECTS.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntIsrLevelIsLe,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig,
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) Level
));


/***********************************************************************************************************************
 *  Os_Hal_IntLevelIsGt()
 **********************************************************************************************************************/
/*! \brief          Returns whether given interrupt priority level LevelX is logically greater than LevelY.
 *  \details        -
 *
 *
 *  \param[in]      LevelX   Left interrupt priority level. Parameter must not be NULL.
 *  \param[in]      LevelY   Right interrupt priority level. Parameter must not be NULL.
 *
 *  \retval         !0  LevelX is logically greater than LevelY.
 *  \retval         0   LevelX is logically less than or equal to LevelY.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 *  \note           Candidate for compiler attributes OS_NOSIDEEFFECTS.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntLevelIsGt,
(
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) LevelX,
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) LevelY
));


/***********************************************************************************************************************
 *  Os_Hal_IntGetLevel()
 **********************************************************************************************************************/
/*! \brief          Returns the current interrupt priority level.
 *  \details        -
 *
 *
 *  \param[out]     Level   Current interrupt priority level. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntGetLevel,
(
  P2VAR(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
));


/***********************************************************************************************************************
 *  Os_Hal_IntGetCat2LockLevel()
 **********************************************************************************************************************/
/*! \brief          Returns the interrupt priority level which is used to lock all category 2 ISRs.
 *  \details        -
 *
 *  \param[out]     Level   Category 2 Lock Level. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntGetCat2LockLevel,
(
  P2VAR(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
));


/***********************************************************************************************************************
 *  Os_Hal_IntCat2LockLevel2Cat2StateType()
 **********************************************************************************************************************/
/*! \brief          Performs a type cast from Os_Hal_IntLevelType to Os_Hal_IntCat2StateType
 *  \details        -
 *
 *
 *  \param[in]      Level   Lock Level to be type casted.
 *
 *  \return         The same lock level but in the correct representation in Os_Hal_IntCat2StateType.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_IntCat2StateType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntCat2LockLevel2Cat2StateType,
(
  Os_Hal_IntLevelType Level
));


/***********************************************************************************************************************
 *  Os_Hal_IntGetCat1LockType()
 **********************************************************************************************************************/
/*! \brief          Returns the type of interrupt locking in the functions SuspendAllInterrupts and
 *                  DisableAllInterrupts.
 *  \details        This may bee platform or configuration dependent.
 *
 *
 *  \retval         OS_HAL_INT_DISABLE_ALL_BY_FLAG  Interrupts are disabled by a global flag.
 *  \retval         OS_HAL_INT_DISABLE_ALL_BY_LEVEL Interrupts are disabled by means of an interrupt level change.
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_IntDisableAllType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntGetCat1LockType,
(
  void
));


/***********************************************************************************************************************
 *  Os_Hal_IntGetCat1LockLevel()
 **********************************************************************************************************************/
/*! \brief          Returns the interrupt priority level which is used to lock all category 1 ISRs.
 *  \details        This function is called only if Os_Hal_IntGetCat1LockType() returns
 *                  OS_HAL_INT_DISABLE_ALL_BY_LEVEL.
 *
 *
 *  \param[out]     Level   Category 1 Lock Level. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *                  Function must only be called if Os_Hal_IntGetCat1LockType() returns
 *                    OS_HAL_INT_DISABLE_ALL_BY_LEVEL.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntGetCat1LockLevel,
(
  P2VAR(Os_Hal_IntLevelType, AUTOMATIC, OS_APPL_DATA) Level
));


/***********************************************************************************************************************
 *  Os_Hal_IntCat1LockLevel2Cat1StateType()
 **********************************************************************************************************************/
/*! \brief          Performs a type cast from Os_Hal_IntLevelType to Os_Hal_IntCat1StateType
 *  \details        -
 *
 *
 *  \param[in]      Level   Lock Level to be type casted. Parameter must not be NULL.
 *
 *  \return         The same lock level but in the correct representation in Os_Hal_IntCat1StateType.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *                  Function must only be called if Os_Hal_IntGetCat1LockType() returns
 *                    OS_HAL_INT_DISABLE_ALL_BY_LEVEL.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_IntCat1StateType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntCat1LockLevel2Cat1StateType,
(
  Os_Hal_IntLevelType Level
));


/***********************************************************************************************************************
 *  Os_Hal_IntTrapRestore()
 **********************************************************************************************************************/
/*! \brief          Restore interrupt state which has been saved during trap.
 *  \details        This function shall restore the interrupt state which was active before the trap handler has been
 *                  triggered. The interrupt state given as parameter has been stored in \ref Os_Exc_SysCall().
 *
 *  \param[in]      InterruptState   Previous interrupt state to restore. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode.
 *  \pre            Called after trap.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntTrapRestore,
(
  P2CONST(Os_Hal_IntTrapStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_Hal_IntTrapUpdate()
 **********************************************************************************************************************/
/*! \brief          Copies the current interrupt state to the interrupt state which has been saved during trap.
 *  \details        This function is called by the trap handler. It allows modification of the interrupt state of the
 *                  trap caller. The interrupt state given as parameter has been stored in \ref Os_Exc_SysCall().
 *
 *  \param[out]     InterruptState   User space interrupt information. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode.
 *  \pre            Called after trap.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_Hal_IntTrapUpdate,
(
  P2VAR(Os_Hal_IntTrapStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_Hal_IntGetInterruptState()
 **********************************************************************************************************************/
/*! \brief          Returns the current interrupt state.
 *  \details        This function is used to transfer the current interrupt state between different context
 *                  (e.g. non-trusted functions).
 *
 *  \param[out]     InterruptState   Location where to store the current interrupt state. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntGetInterruptState,
(
  P2VAR(Os_Hal_InterruptStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_Hal_IntInterruptSourceInit()
 **********************************************************************************************************************/
/*! \brief          Initialize given interrupt source so interrupt handling is possible.
 *  \details
 *  Initialization includes:
 *    - Binding of interrupt sources to cores.
 *    - Setting the interrupt priority of each configured ISR.
 *
 *  The enabled-state interrupt sources shall not be touched. (This might not be possible on some interrupt
 *  controllers.)
 *
 *  \param[in,out]  InterruptSource   Interrupt source which shall be initialized. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntInterruptSourceInit,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptSource
));



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* OS_HAL_INTERRUPTINT_H */

/*!
 * \}
 */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptInt.h
 *********************************************************************************************************************/

