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
 *  \file    Os_Hal_Interrupt_Types.h
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#if !defined (OS_HAL_INTERRUPT_TYPES_H)
# define OS_HAL_INTERRUPT_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_TimingProtection_Cfg.h"

/* Os Hal dependencies */

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! \brief      Disable all interrupt lock method.
 *  \details    Specifies whether disabling all interrupts is implemented by level or global by flag.
 */
typedef enum
{
  OS_HAL_INT_DISABLE_ALL_BY_FLAG = 0, /*!< Disabling all interrupts is implemented by global disable flag. */
  OS_HAL_INT_DISABLE_ALL_BY_LEVEL = 1 /*!< Disabling all interrupts is implemented by level. */
} Os_Hal_IntDisableAllType;

/*! \brief    Interrupt state.
 *  \details  The kernel uses this data type to suspend/resume interrupts, to protect OS internal critical sections.
 *            Variables of this type store the global interrupt state and is defined as a bit mask of ICR register.
 *            ICR with the IE mask:           0b 0000 0000 0000 0000 X000 0000 0000 0000
 *            Interrupt is globally enabled:  0b 0000 0000 0000 0000 1000 0000 0000 0000
 *            Interrupt is globally disabled: 0b 0000 0000 0000 0000 0000 0000 0000 0000 */
typedef uint32 Os_Hal_IntStateType;

/*! \brief    Timing protection interrupt state.
 *  \details  The kernel uses this data type to suspend/resume the timing protection interrupt.
 *            Variables of this type store the timing protection state. Since timing protection uses normal timer
 *            interrupt and thus disabling/enabling TP state can be performed by disabling/enabling global interrupt
 *            state. Therefore this type is the same as Os_Hal_IntStateType */
typedef Os_Hal_IntStateType Os_Hal_IntTpStateType;

/*! \brief    Interrupt level.
 *  \details  The kernel uses this data type to suspend/resume category 2 ISRs up to a certain level.
 *            Variables of this type store interrupt level and is a bit mask of ICR register.
 *            ICR with the CCPN mask: 0b 0000 0000 0000 0000 0000 0000 XXXX XXXX */
typedef uint32 Os_Hal_IntLevelType;

/*! \brief    Category 1+2 ISR interrupt state.
 *  \details  The kernel uses this data type to suspend/resume category 1+2 ISRs.
 *            If timing protection is on, suspending/resuming category 1+2 ISRs has to be performed by
 *            disabling/enabling levels and thus this type is the same as Os_Hal_IntLevelType, otherwise,
 *            suspending/resuming category 1+2 ISRs can be performed by disabling/enabling global interrupt state
 *            and this type is the same as Os_Hal_IntStateType. */
# if (OS_CFG_TIMING_PROTECTION == STD_ON)
typedef Os_Hal_IntLevelType Os_Hal_IntCat1StateType;
# else
typedef Os_Hal_IntStateType Os_Hal_IntCat1StateType;
# endif

/*! \brief    Category 2 ISR interrupt state.
 *  \details  The kernel uses this data type to suspend/resume category 2 ISRs.
 *            Suspending/resuming category 2 ISRs is performed by disabling/enabling levels, thus this type is the
 *            same as Os_Hal_IntLevelType */
typedef Os_Hal_IntLevelType Os_Hal_IntCat2StateType;

/*! \brief    Data type containing the complete interrupt state including global state and level.
 *  \details  Variables of this type store interrupt level and global state, which is a bit mask of ICR register.
 *            Variables of this type is used to store and restore interrupt states during system calls.
 *            ICR with the IE mask:   0b 0000 0000 0000 0000 X000 0000 0000 0000
 *            ICR with the CCPN mask: 0b 0000 0000 0000 0000 0000 0000 XXXX XXXX */
typedef uint32 Os_Hal_IntTrapStateType;

/*! \brief    Data type containing the complete interrupt state including global state and level.
 *  \details  Variables of this type store interrupt level and global state, which is a bit mask of ICR register.
 *            Variables of this type is used to store and restore interrupt states during service function calls.
 *            ICR with the IE mask:   0b 0000 0000 0000 0000 X000 0000 0000 0000
 *            ICR with the CCPN mask: 0b 0000 0000 0000 0000 0000 0000 XXXX XXXX */
typedef uint32 Os_Hal_InterruptStateType;

/*! Forward declaration of Os_Hal_IntIsrConfigType */
struct Os_Hal_IntIsrConfigType_Tag;
typedef struct Os_Hal_IntIsrConfigType_Tag Os_Hal_IntIsrConfigType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


#endif /* OS_HAL_INTERRUPT_TYPES_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Types.h
 **********************************************************************************************************************/

