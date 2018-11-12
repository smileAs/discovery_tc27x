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
 *  \addtogroup Os_Hal_Os
 *  \{
 *
 *  \file       Os_Hal_Os.h
 *  \brief      HAL interfaces which are visible to the user.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Benjamin Seifert              virbse        Vector Informatik GmbH
 *  Da He                         visdhe        Vector Informatik GmbH
 *  David Feuerstein              visdfe        Vector Informatik GmbH
 *  Rainer Kuennemeyer            visrk         Vector Informatik GmbH
 *  Torsten Schmidt               visto         Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2015-01-26  visdhe  -             Initial version
 *  01.01.00  2015-04-29  visdhe  -             Developer version
 *  01.01.01  2015-05-10  visrk   -             Add coverage justifications
 *  01.01.02  2016-05-23  visto   ESCAN00088874 Adaption to HAL interface changes
 *  01.01.03  2016-06-03  visdfe  ESCAN00088874 Rework from previous adaption
 *                                              Add preconditions to service function interface (from FMEA).
 *  01.01.04  2016-06-23  visdhe                Adaption to HAL interface changes
 *  01.01.05  2016-07-05  visdhe                Adaption to HAL interface changes
 *  01.01.06  2016-07-19  visdfe                Adaption to HAL interface changes
 *  01.02.00  2016-08-31  visdhe                Added support for TriCore Aurix TC3xx
 *  01.02.01  2016-09-08  visdhe  FEAT-1931     Provide access to interrupt control register (Step2)
 *  01.02.02  2016-09-28  visdhe                Updated version for Sprint 10 (no functionality changes)
 *  01.03.00  2016-10-12  visdhe                Updated version for Sprint 11 (no hal functionality changes)
 *  01.03.01  2016-10-28  visdhe                Updated version for Sprint 12 (fixed ESCANs)
                                  ESCAN00092399 OS stays in a loop due to incorrectly initialized PCXI
                                  ESCAN00092193 Idle task terminates due to compiler options
 *  01.04.00  2016-11-14  virbse                Updated Generator to latest BSWMD version
 *                        visto                 Re-Create the derivative headers with hardware documentation references
 *  01.05.00  2016-11-28  visdhe  WORKITEM10645 Code Coverage Analysis
 *  01.06.00  2016-12-05  virbse  WORKITEM11413 Reworked Os_Hal_DerivativeInt.h to use OS_CFG_DERIVATIVEGROUP_x defines
 *  01.07.00  2016-12-15  -       -             Internal improvements
 *  01.08.00  2017-01-12  -       -             Internal improvements
 *  02.00.00  2017-02-01  -       -             Internal improvements
 *  02.01.00  2017-03-17  visdhe  ESCAN00094000 Wrong core assignment of interrupts on systems with mixed core IDs
 *            2017-03-17  visdhe  ESCAN00093917 Timing protection ISR always lowers its interrupt level to the OS 
 *                                              system level during interrupt prologue
 *  02.02.00  2017-03-28  visto   WORKITEM14883 Keep compatibility to core generator
 *  02.03.00  2017-05-04  virbse  WORKITEM6746  The core generator shall provide a common core entry symbol for each 
 *                                              core.
 ***********************************************************************************************************************/


#if !defined (OS_HAL_OS_H)
# define OS_HAL_OS_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_OsInt.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* ----- Component version information ----- */
# define OS_HAL_SW_MAJOR_VERSION                     (2u)
# define OS_HAL_SW_MINOR_VERSION                     (3u)
# define OS_HAL_SW_PATCH_VERSION                     (0u)

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

#endif /* OS_HAL_OS_H */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Os.h
 **********************************************************************************************************************/

