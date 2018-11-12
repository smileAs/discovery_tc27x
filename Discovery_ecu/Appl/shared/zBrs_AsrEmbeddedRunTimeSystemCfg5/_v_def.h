
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2014 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  v_def.h
      Project:  Vector Basic Runtime System for MICROSAR4
       Module:  BrsAsrMain
    Generator:  -

  \brief Description:  Template for BrsAsr4 to fit with old BrsHw implementations
  
  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik´s liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

#ifndef  _V_DEF_H_
#define  _V_DEF_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "VGenEnableSwitches.h"

#include "Std_Types.h"

/***************************************************************************/
/****  Hardware independent settings  **************************************/
/***************************************************************************/
/*--- standard memory qualifier definition --------------------------------*/

/* 8-Bit qualifier */
#if !defined( vuint8 ) /* ASR compatibility */
typedef uint8 vuint8;
#endif

/* 16-Bit qualifier */
#if !defined( vuint16 ) /* ASR compatibility */
typedef uint16 vuint16;
#endif

/* 32-Bit qualifier */
#if !defined( vuint32 ) /* ASR compatibility */
typedef uint32 vuint32;
#endif

/***************************************************************************/
/* Memory qualifier                                                        */
/***************************************************************************/

#ifndef MEMORY_HUGE
#  define MEMORY_HUGE               /* no entry                         */
#endif


/* *********************** default defines - used to store permanent data **************************************** */
#ifndef V_MEMROM0
# define V_MEMROM0                  /* addition qualifier data access in ROM  */
#endif

#ifndef V_MEMROM1_NEAR
# define V_MEMROM1_NEAR             /* fast data access in ROM */
#endif

#ifndef V_MEMROM1
# define V_MEMROM1                 /* fast data access in ROM */
#endif

#ifndef V_MEMROM1_FAR
# define V_MEMROM1_FAR             /* slow addressing mode in ROM */
#endif


#ifndef MEMORY_ROM_NEAR
# ifndef V_MEMROM2_NEAR
#  define V_MEMROM2_NEAR   const    /* fast data access in ROM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_ROM_NEAR   V_MEMROM2_NEAR
#else
# define V_MEMROM2_NEAR    MEMORY_ROM_NEAR
#endif

#ifndef MEMORY_ROM
# ifndef V_MEMROM2
#  define V_MEMROM2        const    /* fast data access in ROM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_ROM        V_MEMROM2       
#else
# define V_MEMROM2         MEMORY_ROM
#endif

#ifndef MEMORY_ROM_FAR
# ifndef V_MEMROM2_FAR
#  define V_MEMROM2_FAR    const    /* slow addressing mode in ROM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_ROM_FAR    V_MEMROM2_FAR
#else
# define V_MEMROM2_FAR     MEMORY_ROM_FAR
#endif

#ifndef V_MEMROM3
# define V_MEMROM3        
#endif


/* *********************** default defines - used to store volatile data **************************************** */
#ifndef V_MEMRAM0
# define V_MEMRAM0                  /* addition qualifier data access in RAM  */
#endif

#ifndef V_MEMRAM1_NEAR
# define V_MEMRAM1_NEAR             /* fast data access in RAM */
#endif

#ifndef V_MEMRAM1
# define V_MEMRAM1                 /* fast data access in RAM */
#endif

#ifndef V_MEMRAM1_FAR
# define V_MEMRAM1_FAR             /* slow addressing mode in RAM */
#endif


#ifndef MEMORY_NEAR
# ifndef V_MEMRAM2_NEAR
#  define V_MEMRAM2_NEAR           /* fast data access in RAM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_NEAR   V_MEMRAM2_NEAR
#else
# define V_MEMRAM2_NEAR    MEMORY_NEAR
#endif

#ifndef MEMORY_NORMAL
# ifndef V_MEMRAM2
#  define V_MEMRAM2                 /* fast data access in RAM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_NORMAL   V_MEMRAM2       
#else
# define V_MEMRAM2           MEMORY_NORMAL
#endif

#ifndef MEMORY_FAR
# ifndef V_MEMRAM2_FAR
#  define V_MEMRAM2_FAR            /* slow addressing mode in RAM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_FAR    V_MEMRAM2_FAR
#else
# define V_MEMRAM2_FAR     MEMORY_FAR
#endif

#ifndef V_MEMRAM3_NEAR
# define V_MEMRAM3_NEAR             /* fast data access in RAM */
#endif

#ifndef V_MEMRAM3
# define V_MEMRAM3                 /* fast data access in RAM */
#endif

#ifndef V_MEMRAM3_FAR
# define V_MEMRAM3_FAR             /* slow addressing mode in RAM */
#endif

#endif /*_V_DEF_H_*/
