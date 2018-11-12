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
 *  \defgroup   Os_Hal_Os  HAL OS
 *  \brief      HAL interfaces which are visible to the user.
 *  \details
 *  This file is included by Os.h. Therefore all symbols defined here are visible to the user.
 *  \{
 *
 *  \file       Os_Hal_OsInt.h
 *  \brief      HAL interfaces which are visible to the user.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#if !defined (OS_HAL_OSINT_H)
# define OS_HAL_OSINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Os_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! \brief         Abstraction of CAT 1ISR definition.
 *  \details       This macro is provided for user to define a Cat1 interrupt service routine.
 */
# if defined (OS_CFG_COMPILER_HIGHTEC) || defined (OS_CFG_COMPILER_GNU)                                                 /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
#  define OS_HAL_ISR1_DEFINE(IsrName) \
   __attribute__((interrupt_handler)) void IsrName(void)
# elif defined (OS_CFG_COMPILER_TASKING)   
#  define OS_HAL_ISR1_DEFINE(IsrName) \
   void __interrupt(OS_ISR_##IsrName##_LEVEL) __vector_table(OS_ISR_##IsrName##_CORE) IsrName(void)
# elif defined (OS_STATIC_CODE_ANALYSIS)
#  define OS_HAL_ISR1_DEFINE(IsrName) \
   void IsrName(void)                                                                                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/*! Platform specific address type.
 *  \details This data type has the same bit width as a pointer. Therefore a conversion from this type into a
 *  pointer and vice versa is always valid. */
typedef uint32 Os_Hal_AddressType;

/*! Set of hardware registers to be able to resume from an exception. */
struct Os_ExceptionContextType_Tag
{
  /*! Dummy attribute */
  uint32 Dummy;
};

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* OS_HAL_OS_H */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_OsInt.h
 **********************************************************************************************************************/

