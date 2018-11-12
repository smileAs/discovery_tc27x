
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  BrsHw_DerivativeList.h
      Project:  Vector Basic Runtime System
       Module:  BrsHw for Platform Infineon Aurix

  \brief Description:  This header file contains the information for the specific groups of the different derivatives,
                       supported by this Brs implementation.

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
 ----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
  ----------------------------  ------------  -------------------------------------------------------------------------
  Benjamin Walter               visbwa        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2016-06-07  visbwa  Added revision history
  01.00.01  2017-02-28  visbwa  Encapsuled ISR prio defines for UseCases != OsGen7 only
**********************************************************************************************************************/

#ifndef _BRSHW_DERIVATIVELIST_H_
#define _BRSHW_DERIVATIVELIST_H_

#if !defined (BRS_OS_USECASE_OSGEN7)
  /* Global settings for Timer interrupt */
  #define TIMER_INTERRUPT_NR    1 /* use GPT12 T2 for BrsHwTimeBaseInterrupt */
  #define SW_TIMER_INTERRUPT_NR 2 /* GPT12 interrupt is broadcasted to a core specific software interrupt */
  #define USED_TOS_CPU          0 /* use CPU0 */

  /* ISR prio settings for communication driver interrupts */
  /* This is a fallback, if the prio was not able to be used out of driver config */
  #define BRSHW_FRLINE0PRIO 7
  #define BRSHW_FRTIME0PRIO 8
  #define BRSHW_FRLINE1PRIO 9
  #define BRSHW_FRTIME1PRIO 10

  #define BRSHW_ETHPRIO     19

  #define BRSHW_LIN0PRIO    20
  #define BRSHW_LIN1PRIO    21
  #define BRSHW_LIN2PRIO    22
  #define BRSHW_LIN3PRIO    23
#endif /*BRS_OS_USECASE_OSGEN7*/

/****************************************************
  SUPPORTED DERIVATIVES
*****************************************************/
#if defined (BRS_DERIVATIVE_TC21X)
  #define BRSHW_CPU_MAX_FREQUENCY 133
  #if(BRS_CORE1_START_IMMEDIATE || BRS_CORE2_START_IMMEDIATE)
    #error "Only 1 core available for TC21x"
  #endif /*COREx_START_IMMEDIATE*/

#elif defined (BRS_DERIVATIVE_TC22X)
  #define BRSHW_CPU_MAX_FREQUENCY 133
  #if(BRS_CORE1_START_IMMEDIATE || BRS_CORE2_START_IMMEDIATE)
    #error "Only 1 core available for TC22x"
  #endif /*COREx_START_IMMEDIATE*/

#elif defined (BRS_DERIVATIVE_TC23X)
  #define BRSHW_CPU_MAX_FREQUENCY 133 /*200MHZ possible. 133MHZ only for TC234LC-24F133F and TC233LC-24F113F*/
  #define BRSHW_PLL_ERAY_AVAILABLE
  #if(BRS_CORE1_START_IMMEDIATE || BRS_CORE2_START_IMMEDIATE)
    #error "Only 1 core available for TC23x"
  #endif /*COREx_START_IMMEDIATE*/

#elif defined (BRS_DERIVATIVE_TC26X)
  #define BRSHW_CPU_MAX_FREQUENCY 200
  #define BRSHW_PLL_ERAY_AVAILABLE
  #define BRSHW_PLL_ETH_AVAILABLE
  #if(BRS_CORE2_START_IMMEDIATE)
    #error "Only 2 cores available for TC26x"
  #endif /*CORE2_START_IMMEDIATE*/

#elif defined (BRS_DERIVATIVE_TC27X)
  #define BRSHW_CPU_MAX_FREQUENCY 200
  #define BRSHW_PLL_ERAY_AVAILABLE
  #define BRSHW_PLL_ETH_AVAILABLE

#elif defined (BRS_DERIVATIVE_TC29X)
  #define BRSHW_CPU_MAX_FREQUENCY 265 /*The sum of cpu0 + cpu1 + cpu2 have to be below 803MHZ. This is to limit the current consumption, VDD and TA*/
  #define BRSHW_PLL_ERAY_AVAILABLE
  #define BRSHW_PLL_ETH_AVAILABLE

#else
  #error "Configured derivative (Makefile.config) not yet supported"
#endif /*BRS_DERIVATIVE_x*/

#endif /*_BRSHW_DERIVATIVELIST_H_*/
