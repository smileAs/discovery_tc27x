/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Compiler.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This file provides the AUTOSAR compiler abstraction for the TriCore GNU compiler
 *                   Supported compiler:           GNU
 *                   Supported compiler version:   3.4.5
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *      
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik
 *  Oliver Meili                  Om            Vector Informatik
 *  Holger Birke                  Bir           Vector Informatik
 *  Ruediger Naas                 Rna           Vector Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-11-06  Om                    Adaptation for Tasking compiler for Infineon Tricore
 *  01.01.01  2007-11-27  Jk                    Version defines for CFG management added
 *  02.00.00  2008-04-11  Jk                    Addapted to AUTOSAR 3.0
 *  02.00.01  2008-12-09  Bir                   Correct order of pointerclass and memclass
 *  02.00.02  2009-04-24  Bir                   Correct version define naming
 *  02.00.03  2009-09-29  Bir                   Name of version define
 *  02.01.00  2011-09-20  Bir                   Update to new template include AUTOSAR VERSION 4 and 3.2
 *  02.01.01  2014-03-20  Bir                   ESCAN00074430: rename compiler define
 *  02.01.02  2016-08-23  Rna                   ESCAN00091589: Change of #define _GNU_C_TRICORE_
 *********************************************************************************************************************/

#ifndef COMPILER_H
# define COMPILER_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Compiler_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr_Tricore CQComponent : Impl_CompAbstract_Gnu */
# define COMMONASR_TRICORE_IMPL_COMPABSTRACT_VERSION 0x0201
# define COMMONASR_TRICORE_IMPL_COMPABSTRACT_RELEASE_VERSION 0x02

# define COMPILER_VENDOR_ID    30u
 
/* AUTOSAR Software Specification Release Version Information */
/*            AUTOSAR Release 4.0 R1                          */
#   define COMPILER_AR_RELEASE_MAJOR_VERSION       (4u)
#   define COMPILER_AR_RELEASE_MINOR_VERSION       (0u)
#   define COMPILER_AR_RELEASE_PATCH_VERSION       (1u)

/* Component Version Information */
# define COMPILER_SW_MAJOR_VERSION       (2u)
# define COMPILER_SW_MINOR_VERSION       (1u)
# define COMPILER_SW_PATCH_VERSION       (2u) 

#define _GNU_C_TRICORE_ 1

/* AUTOMATIC used for the declaration of local pointers */
# define AUTOMATIC

/* TYPEDEF shall be used within type definitions, where no memory qualifier can be specified.*/
# define TYPEDEF

/* NULL_PTR define with a void pointer to zero definition*/
# ifndef NULL_PTR
#  define NULL_PTR  ((void *)0)
# endif

/*_INLINE_ define for abstraction of the keyword inline*/
#define INLINE    __inline__ 

/* LOCAL_INLINE define for abstraction of the keyword inline in functions with "static" scope.
   Different compilers may require a different sequence of the keywords "static" and "inline" 
   if this is supported at all. */
# define LOCAL_INLINE    static __inline__

/* FUNC macro for the declaration and definition of functions, that ensures correct syntax of function declarations
   rettype     return type of the function
   memclass    classification of the function itself*/
# define FUNC(rettype, memclass) rettype memclass

/* FUNC_P2CONST macro for declaration and definition of functions returning a pointer to a constant, that ensures 
     correct syntax of function declarations.
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance 
   memclass    classification of the function itself*/
# define FUNC_P2CONST(rettype, ptrclass, memclass) const memclass rettype ptrclass * 

/* FUNC_P2VAR macro for the declaration and definition of functions returning a pointer to a variable, that ensures
     correct syntax of function declarations
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance 
   memclass    classification of the function itself*/
# define FUNC_P2VAR(rettype, ptrclass, memclass) memclass rettype ptrclass * 

/* P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables
   ptrtype     type of the referenced variable memclass
   memclass    classification of the pointer’s variable itself
   ptrclass    defines the classification of the pointer’s distance
 */
# define P2VAR(ptrtype, memclass, ptrclass) ptrtype ptrclass * memclass

/* P2CONST macro for the declaration and definition of pointers in RAM pointing to constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define P2CONST(ptrtype, memclass, ptrclass) const ptrtype ptrclass * memclass

/* CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype ptrclass * const memclass

/* CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype ptrclass * const memclass

/* P2FUNC macro for the type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
   fctname     function name respectivly name of the defined type
 */
# define P2FUNC(rettype, ptrclass, fctname) rettype (ptrclass * fctname)

/* CONST macro for the declaration and definition of constants
   type        type of the constant
   memclass    classification of the constant itself
 */
# define CONST(type, memclass) const type memclass

/* VAR macro for the declaration and definition of variables
   vartype        type of the variable
   memclass    classification of the variable itself
 */
# define VAR(vartype, memclass) vartype memclass

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* COMPILER_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler.h
 *********************************************************************************************************************/
