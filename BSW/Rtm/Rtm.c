/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Rtm.c
 *      Project:  -
 *       Module:  RTM
 *    Generator:  -
 *
 *  Description:  This file provides functions and data for runtime measurements in the scope of RTM
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Alexander Zeeb                visazb        Vector Informatik GmbH
 *  Oliver Reineke                visore        Vector Informatik GmbH
 *  David Zentner                 viszda        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2013-04-22  visazb  -             Initial version
 *  01.00.01  2013-08-06  visore  ESCAN00068379 Unknown runtime behavior if Rtm_InitMemory is not invoked
 *            2013-08-06  visore  ESCAN00069628 Missing DET check for invalid disableInterrupts parameter in Rtm_StartMeasurementFct 
 -                                              and Rtm_StopMeasurementFct
 *            2013-08-06  visore  ESCAN00069629 No changes here
 *            2013-09-19  visore  ESCAN00070505 AR4-220: redefine STATIC to static
 *            2013-09-19  visore  ESCAN00070506 No changes here
 *            2013-09-23  visore  ESCAN00070619 No changes here
 *            2013-09-23  visore  ESCAN00070621 No changes here
 *  01.01.00  2013-11-26  visore  ESCAN00070889 AR4-372: Support Measurement of Net Runtimes
 *  01.01.01  2014-05-21  visore  ESCAN00075552 Remove TODO Sections
 *            2014-05-21  visore  ESCAN00075805 Compiler warning: Rtm_GetFreeMeasurementObject(void) is called with parameter
 *            2014-05-21  visore  ESCAN00075806 No changes here
 *  01.01.02  2014-07-07  visore  ESCAN00076777 Compiler warning: ["../Source/../AMD/BSW/Rtm/Rtm.c" 758/40] invalid shift count
 *            2014-07-07  visore  ESCAN00076778 Measured minumum and maximum run times are incorrect for measurements with measurement count > 1
 *            2014-07-07  visore  ESCAN00076779 Remove the critical section from Rtm_EnterIsrFct() and Rtm_LeaveIsrFct()
 *  01.02.00  2014-07-08  viszda  ESCAN00076464 AR4-817: Runtime optimization of the RTM measurement functions
 *            2014-07-09  viszda  ESCAN00076861 No changes here
 *            2014-07-23  viszda  ESCAN00077300 No changes here
 *            2014-07-29  viszda  ESCAN00077455 Type cast from 'int' to 'Rtm_MeasurementTimestampType'
 *            2014-07-29  viszda  ESCAN00077449 Add initialization of Rtm_Ctrl in Rtm_InitMemory
 *            2014-07-29  viszda  ESCAN00076463 AR4-791: Serial and parallel measurement of CPU load
 *            2014-07-29  viszda  ESCAN00077119 The measured maximum run times are in correct in case net runtime support is enabled
 *            2014-10-20  viszda  ESCAN00078841 Calculated CPU Load is wrong
 *            2014-10-24  viszda  ESCAN00079113 Overall CPU load measurement results can be higher than 100%
 *            2014-11-06  viszda  ESCAN00077452 No changes here
 *  01.02.01  2014-11-27  viszda  ESCAN00079842 The CPU load is always 100% in CPU load control mode C_API
 *            2014-11-27  viszda  ESCAN00079844 The current result of CPU load measurement should be available for CPU load control mode C_API
 *  01.02.02  2015-06-25  viszda  ESCAN00080430 Inline function not encapsulated in RTM_START_SEC_CODE
 *            2015-07-01  viszda  ESCAN00083746 Implausible measurement results for min and max values
 *  02.00.00  2015-10-01  viszda  ESCAN00085574 FEAT-921: Multicore support for RTM Measurement Points [AR4-816]
 *            2015-10-01  viszda  ESCAN00083646 Support of 32bit timer
 *            2015-10-01  viszda  ESCAN00085572 Optimization of Net Runtime implementation
 *  2.00.01   2016-02-25  viszda  ESCAN00087879 DET occurs during start up of RTM
 *  2.00.02   2016-04-05  viszda  ESCAN00089228 No changes here
 *  2.01.00   2016-04-15  viszda  ESCAN00089508 FEAT-1846: RTM cleanup and improvements
 *            2016-05-17  viszda  ESCAN00089265 API based RTM control in CANoe
 *            2016-04-07  viszda  ESCAN00090816 Implausible measurement results due to not stopped measurement points
 *  2.02.00   2016-09-14  viszda  ESCAN00091859 FEAT-2055: SafeRTM (Disable RTM safely)
 *  3.00.00   2017-04-03  viszda  STORY-718     [AMD] Support net runtime measurement with RTM in Gen7 OS
 *            2017-04-03  viszda  ESCAN00087435 Rework RTM implementation structure and comments
 *            2017-04-03  viszda  ESCAN00080428 Correction of formal issues
 *            2017-04-05  viszda  ESCAN00093290 Wrong measurement results in case of execution time measurement
 *            2017-04-05  viszda  ESCAN00085578 Add DET checks to RTM's APIs
 *            2017-04-05  viszda  ESCAN00094525 Net runtime measurement deviates to a large extent from real runtime in special cases
 *            2017-04-07  viszda  ESCAN00094694 Add missing initialization of Rtm_DisableInterruptFlag in Rtm_InitMemory
 *********************************************************************************************************************/

#define RTM_SOURCE
/* PRQA S 857 EOF */ /* MD_MSR_1.1_857 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Rtm.h"

/*lint -e438 */ /* Suppress ID438 because value assigned to variable is not required */
/*lint -e550 */ /* Suppress ID550 because symbol is not required */

#if (RTM_MULTICORE_SUPPORT == STD_ON)
# include "Os.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* vendor specific version information is BCD coded */
#if (  (RTM_SW_MAJOR_VERSION != (0x03u)) \
    || (RTM_SW_MINOR_VERSION != (0x00u)) \
    || (RTM_SW_PATCH_VERSION != (0x00u)) )
# error "Vendor specific version numbers of Rtm.c and Rtm.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

#if (RTM_CTR_DIRECTION == RTM_UP)
# if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
# define Rtm_GetCounterDelta(START_VAL, END_VAL, RESULT_PTR, MEAS_ID) ((END_VAL) >= (START_VAL)) ?                                                                    \
                                                                      (*(RESULT_PTR) = (( (uint32)                                                                    \
                                                                                              ((Rtm_TimerOverrunCnt >= Rtm_PrevOverrunCounterValues[MEAS_ID]) ?       \
                                                                                               (Rtm_TimerOverrunCnt - Rtm_PrevOverrunCounterValues[MEAS_ID])  :       \
                                                                                               ((256 - Rtm_PrevOverrunCounterValues[MEAS_ID]) + Rtm_TimerOverrunCnt)  \
                                                                                              ) * RTM_MEASUREMENT_MAX_VAL) + (END_VAL)) - (START_VAL)) :              \
                                                                      (*(RESULT_PTR) = (( (uint32)                                                                    \
                                                                                              ((Rtm_TimerOverrunCnt > Rtm_PrevOverrunCounterValues[MEAS_ID]) ?        \
                                                                                               (Rtm_TimerOverrunCnt - Rtm_PrevOverrunCounterValues[MEAS_ID])  :       \
                                                                                               ((Rtm_TimerOverrunCnt == Rtm_PrevOverrunCounterValues[MEAS_ID]) ? 1 :  \
                                                                                               ((256 - Rtm_PrevOverrunCounterValues[MEAS_ID]) + Rtm_TimerOverrunCnt)) \
                                                                                              ) * RTM_MEASUREMENT_MAX_VAL) - (START_VAL)) + (END_VAL)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else /* (RTM_TIMER_OVERRUN_SUPPORT == STD_ON) */
# define Rtm_GetCounterDelta(START_VAL, END_VAL, RESULT_PTR, MEAS_ID) ((END_VAL) >= (START_VAL)) ?                                \
                                                                      (*(RESULT_PTR) = (END_VAL) - (START_VAL)) :                 \
                                                                      (*(RESULT_PTR) = ((RTM_MEASUREMENT_MAX_VAL - (START_VAL)) + (END_VAL))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* (RTM_TIMER_OVERRUN_SUPPORT == STD_ON) */

#else /* (RTM_CTR_DIRECTION == RTM_DOWN) */
# if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
# define Rtm_GetCounterDelta(START_VAL, END_VAL, RESULT_PTR, MEAS_ID) ((END_VAL) <= (START_VAL)) ?                                                                    \
                                                                      (*(RESULT_PTR) = (( (uint32)                                                                    \
                                                                                              ((Rtm_TimerOverrunCnt >= Rtm_PrevOverrunCounterValues[MEAS_ID]) ?       \
                                                                                               (Rtm_TimerOverrunCnt - Rtm_PrevOverrunCounterValues[MEAS_ID])  :       \
                                                                                               ((256 - Rtm_PrevOverrunCounterValues[MEAS_ID]) + Rtm_TimerOverrunCnt)  \
                                                                                              ) * RTM_MEASUREMENT_MAX_VAL) + (START_VAL)) - (END_VAL)) :              \
                                                                      (*(RESULT_PTR) = (( (uint32)                                                                    \
                                                                                              ((Rtm_TimerOverrunCnt > Rtm_PrevOverrunCounterValues[MEAS_ID]) ?        \
                                                                                               (Rtm_TimerOverrunCnt - Rtm_PrevOverrunCounterValues[MEAS_ID])  :       \
                                                                                               ((Rtm_TimerOverrunCnt == Rtm_PrevOverrunCounterValues[MEAS_ID]) ? 1 :  \
                                                                                               ((256 - Rtm_PrevOverrunCounterValues[MEAS_ID]) + Rtm_TimerOverrunCnt)) \
                                                                                              ) * RTM_MEASUREMENT_MAX_VAL) - (END_VAL)) + (START_VAL)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else /* (RTM_TIMER_OVERRUN_SUPPORT == STD_ON) */
# define Rtm_GetCounterDelta(START_VAL, END_VAL, RESULT_PTR, MEAS_ID) ((END_VAL) <= (START_VAL)) ?                \
                                                                      (*(RESULT_PTR) = (START_VAL) - (END_VAL)) : \
                                                                      (*(RESULT_PTR) = ((RTM_MEASUREMENT_MAX_VAL - (END_VAL)) + (START_VAL))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* (RTM_TIMER_OVERRUN_SUPPORT == STD_ON) */
#endif /* RTM_CTR_DIRECTION == RTM_UP */

#if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
# if (RTM_CTR_DIRECTION == RTM_UP)
#define RTM_GET_CURRENT_TIME(time) {                                          \
                                     Rtm_GetCurrentTimeCnt++;                 \
                                     (time) = RTM_GET_TIME_MEASUREMENT_FCT(); \
                                     if (Rtm_GetCurrentTimeCnt == 1) {        \
                                       if ((time)<Rtm_PrevTimerValue) {       \
                                          Rtm_TimerOverrunCnt++;              \
                                       }                                      \
                                       Rtm_PrevTimerValue = (time);           \
                                     }                                        \
                                     Rtm_GetCurrentTimeCnt--;                 \
                                   } /* PRQA S 3453,3458 */ /* MD_MSR_19.7,MD_MSR_19.4 */

# else /* (RTM_CTR_DIRECTION == RTM_DOWN) */

/* ESCAN00079227 */
#define RTM_GET_CURRENT_TIME(time) {                                          \
                                     Rtm_GetCurrentTimeCnt++;                 \
                                     (time) = RTM_GET_TIME_MEASUREMENT_FCT(); \
                                     if (Rtm_GetCurrentTimeCnt == 1) {        \
                                       if ((time)>Rtm_PrevTimerValue) {       \
                                          Rtm_TimerOverrunCnt++;              \
                                       }                                      \
                                       Rtm_PrevTimerValue = (time);           \
                                     }                                        \
                                     Rtm_GetCurrentTimeCnt--;                 \
                                   } /* PRQA S 3453,3458 */ /* MD_MSR_19.7,MD_MSR_19.4 */
# endif /* (RTM_CTR_DIRECTION == RTM_UP) */

#else /* (RTM_TIMER_OVERRUN_SUPPORT == STD_ON) */
#define RTM_GET_CURRENT_TIME(time) (time) = RTM_GET_TIME_MEASUREMENT_FCT() /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif /* (RTM_TIMER_OVERRUN_SUPPORT == STD_ON) */

#if (RTM_USE_32BIT_TIMER == STD_ON)
#define Rtm_FixTypeMismatch(word) (word) = ((word) >> 1) /* PRQA S 3410,3453  */  /* MD_Rtm_3410,MD_MSR_19.7 */
#else
#define Rtm_FixTypeMismatch(word)
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

# define RTM_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# if (RTM_CONTROL == STD_ON)
VAR(uint8, RTM_VAR_INIT)                          Rtm_ControlState = RTM_CONTROL_STATE_ENABLED; /* = 1 */
# endif

# if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
VAR(uint32, RTM_VAR_INIT)                         Rtm_ActiveThreadId = RTM_NUMBER_OF_THREADS;
# endif

# define RTM_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# define RTM_START_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# if (RTM_CONTROL == STD_ON)
VAR(uint8, RTM_VAR_ZERO_INIT)                     Rtm_ControlDeniedCount = 0; /*lint -e552 */ /* Suppress ID552 */
# endif

#if (RTM_TIME_MEASUREMENT == STD_ON)
VAR(uint8, RTM_VAR_ZERO_INIT)                     Rtm_InitState = RTM_UNINITIALIZED; /* = 0 */ /*lint -e552 */ /* Suppress ID552 */
#endif

# define RTM_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#if (RTM_TIME_MEASUREMENT == STD_ON)
# define RTM_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

RTM_LOCAL VAR(uint32, RTM_VAR_NOINIT)             Rtm_LastCommandToEcu; /* PRQA S 3408 */  /* MD_Rtm_3408 */
RTM_LOCAL VAR(Rtm_TimestampType, RTM_VAR_NOINIT)  Rtm_MeasurementTimer; /* PRQA S 3408 */  /* MD_Rtm_3408 */
RTM_LOCAL VAR(Rtm_TimestampType, RTM_VAR_NOINIT)  Rtm_CalculatedCtrEndVal; /* PRQA S 3408 */  /* MD_Rtm_3408 */

# if (RTM_MULTICORE_SUPPORT == STD_ON)
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_XcpState; /*lint -e552 */ /* Suppress ID552 */
# else
RTM_LOCAL VAR(uint8, RTM_VAR_NOINIT)              Rtm_XcpState; /* PRQA S 3408 */  /* MD_Rtm_3408 */
# endif

VAR(uint32, RTM_VAR_NOINIT)                       Rtm_Cmd; /*lint -e552 */ /* Suppress ID552 */
VAR(uint32, RTM_VAR_NOINIT)                       Rtm_Resp; /*lint -e552 */ /* Suppress ID552 */
VAR(sint32, RTM_VAR_NOINIT)                       Rtm_MeasTimeCorrection; /*lint -e552 */ /* Suppress ID552 */

VAR(uint32, RTM_VAR_NOINIT)                       Rtm_AverageMainFunctionCycleTime;
VAR(uint32, RTM_VAR_NOINIT)                       Rtm_MainFunctionCounter;

# if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
VAR(Rtm_MeasurementTimestampType, RTM_VAR_NOINIT) Rtm_PrevTimerValue;
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_PrevOverrunCounterValues[RTM_MEAS_SECTION_COUNT];
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_GetCurrentTimeCnt;
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_TimerOverrunCnt;
# endif

# if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
RTM_LOCAL VAR(Rtm_TaskType, RTM_VAR_NOINIT)       Rtm_TaskIndex[RTM_NUMBER_OF_TASKS]; /* PRQA S 3408 */  /* MD_Rtm_3408 */
# endif

# if (RTM_MULTICORE_SUPPORT == STD_ON)
VAR(uint32, RTM_VAR_NOINIT)                       Rtm_CpuLoadTime[RTM_NUMBER_OF_CORES]; /*lint -e552 */ /* Suppress ID552 */
VAR(uint16, RTM_VAR_NOINIT)                       Rtm_MasterCore;
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_SendNextMainFunction;

# else
RTM_LOCAL VAR(uint8, RTM_VAR_NOINIT)              Rtm_LiveMeasurement; /* PRQA S 3408 */  /* MD_Rtm_3408 */
VAR(uint32, RTM_VAR_NOINIT)                       Rtm_CpuLoadTime;
# endif

RTM_LOCAL VAR(uint8, RTM_VAR_NOINIT)              Rtm_EndlessMeasurement; /* PRQA S 3408 */  /* MD_Rtm_3408 */
RTM_LOCAL VAR(uint32, RTM_VAR_NOINIT)             Rtm_LastMainFunctionTime; /* PRQA S 3408 */  /* MD_Rtm_3408 */
RTM_LOCAL VAR(uint32, RTM_VAR_NOINIT)             Rtm_AvgMainFunctionCycleTimeCalcCounter; /* PRQA S 3408 */  /* MD_Rtm_3408 */

# if (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF)
#  if (RTM_MULTICORE_SUPPORT == STD_ON)
RTM_LOCAL VAR(Rtm_MeasurementTimestampType, RTM_VAR_NOINIT) Rtm_CpuLoadStartTimestamp[RTM_NUMBER_OF_CORES]; /* PRQA S 3408 */  /* MD_Rtm_3408 */
RTM_LOCAL VAR(uint32, RTM_VAR_NOINIT)             Rtm_CpuLoadOverhead[RTM_NUMBER_OF_CORES]; /* PRQA S 3408 */  /* MD_Rtm_3408 */

VAR(uint32, RTM_VAR_NOINIT)                       Rtm_CpuLoadCollectedTime[RTM_NUMBER_OF_CORES];
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_CpuLoadMeasurementActive[RTM_NUMBER_OF_CORES];
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_CpuLoadWasStopped[RTM_NUMBER_OF_CORES];
#   if defined (RTM_CPU_LOAD_AUTOSTART)
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_CpuLoadSendResult[RTM_NUMBER_OF_CORES];
#   endif

#  else /* (RTM_MULTICORE_SUPPORT == STD_ON) */
RTM_LOCAL VAR(Rtm_MeasurementTimestampType, RTM_VAR_NOINIT) Rtm_CpuLoadStartTimestamp; /* PRQA S 3408 */  /* MD_Rtm_3408 */
RTM_LOCAL VAR(uint32, RTM_VAR_NOINIT)             Rtm_CpuLoadOverhead; /* PRQA S 3408 */  /* MD_Rtm_3408 */

VAR(uint32, RTM_VAR_NOINIT)                       Rtm_CpuLoadCollectedTime;
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_CpuLoadMeasurementActive;
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_CpuLoadWasStopped;
#   if defined (RTM_CPU_LOAD_AUTOSTART)
VAR(uint8, RTM_VAR_NOINIT)                        Rtm_CpuLoadSendResult;
#   endif
#  endif /* (RTM_MULTICORE_SUPPORT == STD_ON) */
# endif /* RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF */

# define RTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/* ESCAN00080430 */
# define RTM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
RTM_LOCAL_INLINE FUNC(void, RTM_CODE) Rtm_Init_TaskContext(void); /* PRQA S 3408, 3447 */  /* MD_Rtm_3408 */

/**********************************************************************************************************************
 * Rtm_Net_LeaveThread()
 *********************************************************************************************************************/
/*! \brief       Stores data of a preempted net measurement point.
 *  \details     If a net measurement section is active on preempted thread, this section is also preempted.
 *  \param[in]   LeaveThread             The thread which is preempted/terminated.
 *  \param[in]   CoreId                  The core on which the scheduling is performed.
 *  \param[in]   CurrentTime             The timestamp when the thread was preempted.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_NET_RUNTIME_SUPPORT == STD_ON.
 *  \pre         Must not be called if the APIs Rtm_EnterTaskFct/Rtm_LeaveTaskFct/Rtm_EnterIsrFctRtm_LeaveIsrFct
 *               are used.
 *  \note        Should be called by Rtm_Schedule or an API with equal behavior.
 *  \ingroup     netRuntime
 *********************************************************************************************************************/
/* PRQA S 3408, 3447 3 */  /* MD_Rtm_3408 */
RTM_LOCAL_INLINE FUNC(void, RTM_CODE) Rtm_Net_LeaveThread( uint32 LeaveThread,
                                                           uint16 CoreId,
                                                           Rtm_MeasurementTimestampType CurrentTime );

/**********************************************************************************************************************
 * Rtm_Net_EnterThread()
 *********************************************************************************************************************/
/*! \brief       Preempts a thread and starts another thread.
 *  \details     If a net measurement section is active on preempted thread, this section is also preempted. If a net 
 *               measurement section was preempted on the entered thread, this section is also started.
 *  \param[in]   LeaveThread             The thread which is started (now active).
 *  \param[in]   CoreId                  The core on which the scheduling is performed.
 *  \param[in]   CurrentTime             The timestamp when the thread was preempted.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_NET_RUNTIME_SUPPORT == STD_ON.
 *  \pre         Must not be called if the APIs Rtm_EnterTaskFct/Rtm_LeaveTaskFct/Rtm_EnterIsrFctRtm_LeaveIsrFct
 *               are used.
 *  \note        Should be called by Rtm_Schedule or an API with equal behavior.
 *  \ingroup     netRuntime
 *********************************************************************************************************************/
/* PRQA S 3408, 3447 3 */  /* MD_Rtm_3408 */
RTM_LOCAL_INLINE FUNC(void, RTM_CODE) Rtm_Net_EnterThread( uint32 EnterThread,
                                                           uint16 CoreId,
                                                           Rtm_MeasurementTimestampType CurrentTime );
# endif

# if (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF)
#  if (RTM_MULTICORE_SUPPORT == STD_OFF)
RTM_LOCAL_INLINE FUNC(void, RTM_CODE) Rtm_InitCpuLoadMeasurement(void); /* PRQA S 3408, 3447 */  /* MD_Rtm_3408 */
#  endif
# endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

# if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
RTM_LOCAL_INLINE FUNC(void, RTM_CODE) Rtm_Init_TaskContext(void)
{
  uint16_least index;
  uint32 rtmInactive = RTM_INACTIVE;

  /* Initialize Rtm_TaskIndex */
  for (index = 0; index < RTM_NUMBER_OF_TASKS; index++)
  {
    Rtm_TaskIndex[index] = (Rtm_TaskType)rtmInactive;
  }

  /* Assign each Rtm_TaskIndex index to the corresponding Rtm_TaskContext:
   *  In Rtm_TaskContext the Task IDs are specified but unsorted.
   *  Rtm_TaskIndex is used to point to Rtm_TaskContext, example:
   *    Rtm_TaskIndex[0] = 3 -> Rtm_TaskContext[3].taskId = 0
   */
  for (index = 0; index < RTM_NUMBER_OF_TASKS; index++)
  {
    /* Each task ID must be unique, thus this condition should not fail. */
    if (Rtm_TaskIndex[Rtm_TaskContext[index].taskId] == (Rtm_TaskType)rtmInactive)
    {
      Rtm_TaskIndex[Rtm_TaskContext[index].taskId] = (Rtm_TaskType)index;
    }
  }

#  if (RTM_DEV_ERROR_DETECT == STD_ON)
  /* Check vality of each task index  */
  for (index = 0; index < RTM_NUMBER_OF_TASKS; index++)
  {
    if (Rtm_TaskIndex[index] == (Rtm_TaskType)rtmInactive)
    {
      Rtm_ReportDetError(RTM_API_ID_INIT, RTM_E_INVALID_CONFIGURATION); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    }
  }
#  endif
}
# endif /* (RTM_NET_RUNTIME_SUPPORT == STD_ON) */

# if (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF)
#  if (RTM_MULTICORE_SUPPORT == STD_OFF)
/***********************************************************************************************************************
 *  Rtm_InitCpuLoadMeasurement
 **********************************************************************************************************************/
/*! \brief      This function initializes RTMs overall CPU load measurement.
 *  \param[in]  -
 *  \param[out] -
 *  \pre        -
 *  \context    Function is called from task level
 *  \note       This function has to be called in Rtm_MainFunction.
 **********************************************************************************************************************/
RTM_LOCAL_INLINE FUNC(void, RTM_CODE) Rtm_InitCpuLoadMeasurement(void)
{
  Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].count = 0x0u;
  Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].time = 0x0u;
  Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].min = 0xFFFFFFFFu;
  Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].max = 0x0u;

  Rtm_CpuLoadWasStopped = RTM_FALSE;
  Rtm_CpuLoadTime = 0;
  Rtm_CpuLoadStartTimestamp = RTM_GET_TIME_MEASUREMENT_FCT();

  /* Overall CPU-load calibration */
  Rtm_CpuLoadOverhead      = (uint32) 0u;
  Rtm_CpuLoadCollectedTime = (uint32) 0u;
  Rtm_CpuLoadMeasurementFunction();
  Rtm_CpuLoadCollectedTime = (uint32) 0u;
  Rtm_CpuLoadMeasurementFunction();
  Rtm_CpuLoadOverhead      = Rtm_CpuLoadCollectedTime;
  if (Rtm_CpuLoadOverhead == 0)
  {
    Rtm_CpuLoadOverhead = 1;
  }
} /* Rtm_InitCpuLoadMeasurement */
#  endif /* (RTM_MULTICORE_SUPPORT == STD_ON) */
# endif /* (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Rtm_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief      Rtm_GetVersionInfo. Acquires Rtm's version information.
 *  \param[in]  -
 *  \param[out] *VersionInfo
 *  \pre        -
 *  \context    Function can be called from interrupt level or from task level
 *  \note       Function to get the component version information.
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, RTM_APPL_VAR) Versioninfo)
{
# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
    Rtm_CheckDetErrorReturnVoid(NULL_PTR != Versioninfo, RTM_API_ID_GETVERSIONINFO, RTM_E_WRONG_PARAMETERS); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    Versioninfo->vendorID = RTM_VENDOR_ID;
    Versioninfo->moduleID = RTM_MODULE_ID;
    Versioninfo->sw_major_version = RTM_SW_MAJOR_VERSION;
    Versioninfo->sw_minor_version = RTM_SW_MINOR_VERSION;
    Versioninfo->sw_patch_version = RTM_SW_PATCH_VERSION;
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
}

/***********************************************************************************************************************
 *  Rtm_StartMeasurementFct
 **********************************************************************************************************************/
/*! \brief      Rtm_StartMeasurementFct. This function starts time measurement for the given measurement section.
 *  \param[in]  measurementId            Rtm internal ID of the measurement section to be started
 *  \param[out] -
 *  \pre        -
 *  \context    Function can be called from interrupt level or from task level
 *  \note       This function shall only be called by the preprocessor macros provided by Rtm.
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_StartMeasurementFct(uint32 measurementId) /* ESCAN00076464 */
{
  Rtm_MeasurementTimestampType currentTime;

  Rtm_CheckDetErrorReturnVoid((RTM_MEAS_SECTION_COUNT > measurementId), RTM_API_ID_STARTMEASUREMENT, RTM_E_WRONG_PARAMETERS); /* PRQA S 3109 */  /* MD_MSR_14.3 */

  /* #-- If the MP is assigned to one specific core, the MP must be executed on this core. */
# if (RTM_MULTICORE_SUPPORT == STD_ON)
  if (Rtm_MeasurementPointInfo[measurementId].coreId < RTM_NUMBER_OF_CORES)
  {
    Rtm_CheckDetErrorReturnVoid( ((uint16)Rtm_GetCoreId() == Rtm_MeasurementPointInfo[measurementId].coreId),
                                 RTM_API_ID_STARTMEASUREMENT,
                                 RTM_E_INVALID_CONFIGURATION ); /* PRQA S 3109 */  /* MD_MSR_14.3 */
  }
# endif

# if (RTM_NESTING_COUNTER == STD_ON)
  Rtm_MeasurementNestingCtr[measurementId]++;
  if(1 == Rtm_MeasurementNestingCtr[measurementId])
# else
#  if (RTM_DEV_ERROR_DETECT == STD_ON)
  Rtm_MeasurementNestingCtr[measurementId]++;
#  endif
# endif
  {
    RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    Rtm_StartTimeStamps[measurementId] = currentTime;
# if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
    Rtm_PrevOverrunCounterValues[measurementId] = Rtm_TimerOverrunCnt;    
# endif
  }

  Rtm_CheckDetErrorContinue((0x64 > Rtm_MeasurementNestingCtr[measurementId]), RTM_API_ID_STARTMEASUREMENT, RTM_E_UNBALANCED); /* PRQA S 3109 */  /* MD_MSR_14.3 */

  /* PRQA S 6030 3 */ /* MD_MSR_STCYC */
  /* PRQA S 6010 2 */ /* MD_MSR_STPTH */
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* Rtm_StartMeasurementFct */

/***********************************************************************************************************************
 *  Rtm_StopMeasurementFct
 **********************************************************************************************************************/
/*! \brief      Rtm_StopMeasurementFct. This function calculates the runtime
 *  \param[in]  measurementId           Rtm internal ID of the measurement section to be started
 *  \param[out] -
 *  \context    Function could be called from interrupt level or from task level
 *  \note       This function is called by a Rtm preprocessor macro
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_StopMeasurementFct(uint32 measurementId) /* ESCAN00076464 */
{
  Rtm_MeasurementTimestampType currentTime;

  Rtm_CheckDetErrorReturnVoid((RTM_MEAS_SECTION_COUNT > measurementId), RTM_API_ID_STOPMEASUREMENT, RTM_E_WRONG_PARAMETERS); /* PRQA S 3109 */  /* MD_MSR_14.3 */

/* #-- If the MP is assigned to one specific core, the MP must be executed on this core. */
# if (RTM_MULTICORE_SUPPORT == STD_ON)
  if (Rtm_MeasurementPointInfo[measurementId].coreId < RTM_NUMBER_OF_CORES)
  {
    Rtm_CheckDetErrorReturnVoid( ((uint16)Rtm_GetCoreId() == Rtm_MeasurementPointInfo[measurementId].coreId),
                                 RTM_API_ID_STARTMEASUREMENT,
                                 RTM_E_INVALID_CONFIGURATION ); /* PRQA S 3109 */  /* MD_MSR_14.3 */
  }
# endif

# if (RTM_NESTING_COUNTER == STD_ON)
  Rtm_MeasurementNestingCtr[measurementId]--;
  if(0 == Rtm_MeasurementNestingCtr[measurementId]) /* ESCAN00076464 */
# else
#  if (RTM_DEV_ERROR_DETECT == STD_ON)
  Rtm_MeasurementNestingCtr[measurementId]--;
#  endif
# endif
  {
    RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    Rtm_GetCounterDelta(Rtm_StartTimeStamps[measurementId], currentTime, &currentTime, measurementId);

    if (currentTime > Rtm_Results[measurementId].max)
    {
      Rtm_Results[measurementId].max = currentTime;
    }
    if (currentTime < Rtm_Results[measurementId].min)
    {
      Rtm_Results[measurementId].min = currentTime;
    }

    Rtm_Results[measurementId].time = Rtm_Results[measurementId].time + currentTime;
    Rtm_Results[measurementId].count = Rtm_Results[measurementId].count + 1;

    if (Rtm_Results[measurementId].time < currentTime)
    {
      /* Overflow occurred, reset results to defined state */
      Rtm_Results[measurementId].time = (uint32) 0u;
      Rtm_Results[measurementId].count = (uint32) 0u;
    }

    /* Check if a threshold is configured and exceeded */
    if ((Rtm_ThresholdTimes[measurementId] < currentTime) && (0 < Rtm_ThresholdTimes[measurementId]))
    {
      /* Call threshold callback */
      (Rtm_ThresholdCbkFctArr[measurementId]) (currentTime);
    }
  }

  Rtm_CheckDetErrorContinue(((sint8) 0 <= Rtm_MeasurementNestingCtr[measurementId]), RTM_API_ID_STOPMEASUREMENT, RTM_E_UNBALANCED); /* PRQA S 3109 */  /* MD_MSR_14.3 */
  
  /* PRQA S 6080 4 */ /* MD_MSR_STMIF */  
  /* PRQA S 6030 3 */ /* MD_MSR_STCYC */    
  /* PRQA S 6010 2 */ /* MD_MSR_STPTH */
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* Rtm_StopMeasurementFct */

# if (RTM_MULTICORE_SUPPORT == STD_OFF)
#  if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
/***********************************************************************************************************************
 *  Rtm_StartNetMeasurementFct
 **********************************************************************************************************************/
/*! \brief      Rtm_StartNetMeasurementFct. This function starts time measurement for the given measurement section.
 *  \param[in]  measurementId            Rtm internal ID of the measurement section to be started
 *  \param[out] -
 *  \pre        -
 *  \context    Function can be called from interrupt level or from task level
 *  \note       This function shall only be called by the preprocessor macros provided by Rtm.
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_StartNetMeasurementFct(uint32 measurementId) /* ESCAN00076464 */
{
  Rtm_MeasurementTimestampType currentTime;

  Rtm_CheckDetErrorReturnVoid((RTM_MEAS_SECTION_COUNT > measurementId), RTM_API_ID_STARTMEASUREMENT, RTM_E_WRONG_PARAMETERS); /* PRQA S 3109 */  /* MD_MSR_14.3 */
  
#   if (RTM_NESTING_COUNTER == STD_ON)
  Rtm_MeasurementNestingCtr[measurementId]++;
  if(1 == Rtm_MeasurementNestingCtr[measurementId])
#   else
#    if (RTM_DEV_ERROR_DETECT == STD_ON)
  Rtm_MeasurementNestingCtr[measurementId]++;
#    endif
#   endif
  {
    /* #-- A MP of type execution time has to be running in context of a thread. */
    if (Rtm_ActiveThreadId < RTM_NUMBER_OF_THREADS)
    {
      Rtm_MeasurementPointInfo[measurementId].threadContext = Rtm_ActiveThreadId;
      Rtm_MeasurementPointInfo[measurementId].prevActive = Rtm_ActiveMeasurementId;
    
      Rtm_ActiveMeasurementId = measurementId;
      RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */
      Rtm_StartTimeStamps[measurementId] = currentTime;

#   if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
      Rtm_PrevOverrunCounterValues[measurementId] = Rtm_TimerOverrunCnt;    
#   endif
    }
    /* #-- Otherwise, report an DET error. */
    else
    {
      Rtm_ReportDetError(RTM_API_ID_STARTMEASUREMENT, RTM_E_INVALID_CONFIGURATION); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    }
  }

  Rtm_CheckDetErrorContinue((0x64 > Rtm_MeasurementNestingCtr[measurementId]), RTM_API_ID_STARTMEASUREMENT, RTM_E_UNBALANCED); /* PRQA S 3109 */  /* MD_MSR_14.3 */

  /* PRQA S 6030 3 */ /* MD_MSR_STCYC */
  /* PRQA S 6010 2 */ /* MD_MSR_STPTH */
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* Rtm_StartNetMeasurementFct */

/***********************************************************************************************************************
 *  Rtm_StopNetMeasurementFct
 **********************************************************************************************************************/
/*! \brief      Rtm_StopNetMeasurementFct. This function calculates the runtime
 *  \param[in]  measurementId              Rtm internal ID of the measurement section to be started
 *  \param[out] -
 *  \context    Function could be called from interrupt level or from task level
 *  \note       This function is called by a Rtm preprocessor macro
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_StopNetMeasurementFct(uint32 measurementId) /* ESCAN00076464 */
{
  Rtm_MeasurementTimestampType currentTime;
  uint32 interTime;
  uint32 interruptedMeasId;

  Rtm_CheckDetErrorReturnVoid((RTM_MEAS_SECTION_COUNT > measurementId), RTM_API_ID_STOPMEASUREMENT, RTM_E_WRONG_PARAMETERS); /* PRQA S 3109 */  /* MD_MSR_14.3 */

#   if (RTM_NESTING_COUNTER == STD_ON)
  Rtm_MeasurementNestingCtr[measurementId]--;
  if (0 == Rtm_MeasurementNestingCtr[measurementId]) /* ESCAN00076464 */
#   else
#    if (RTM_DEV_ERROR_DETECT == STD_ON)
  Rtm_MeasurementNestingCtr[measurementId]--;
#    endif
#   endif
  {
    if (Rtm_ActiveMeasurementId == measurementId)
    {
      RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */
      interTime = Rtm_MeasurementPointInfo[measurementId].intermediateTime;
      Rtm_GetCounterDelta(Rtm_StartTimeStamps[measurementId], currentTime, &currentTime, measurementId);

      interruptedMeasId = Rtm_MeasurementPointInfo[measurementId].prevActive;

      /* Add gross runtime of now stopped measurement point to intermediateTime of interrupted measurement point if the interrupted measurement point is really interruptable. */
#   if (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON)
      if ((interruptedMeasId < RTM_MEAS_SECTION_COUNT) 
#    if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON)
          && (Rtm_MeasurementPointInfo[interruptedMeasId].isInterruptable == TRUE)
#    endif /* (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON) */
          )
      {
        Rtm_MeasurementPointInfo[interruptedMeasId].intermediateTime = Rtm_MeasurementPointInfo[interruptedMeasId].intermediateTime + currentTime; /* Add brutto runtime of current measurement point */
      }
#   endif /* (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON) && (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON) */

      Rtm_MeasurementPointInfo[measurementId].threadContext = RTM_NUMBER_OF_THREADS;
      Rtm_ActiveMeasurementId = interruptedMeasId;
      Rtm_MeasurementPointInfo[measurementId].intermediateTime = 0;

      if (interTime < currentTime)
      {
        currentTime = currentTime - interTime;
      }
      else
      {
        currentTime = 0;
      }
    
      if(currentTime > Rtm_Results[measurementId].max)
      {
        Rtm_Results[measurementId].max = currentTime;
      }
      if(currentTime < Rtm_Results[measurementId].min)
      {
        Rtm_Results[measurementId].min = currentTime;
      }

      Rtm_Results[measurementId].time = Rtm_Results[measurementId].time + currentTime;
      Rtm_Results[measurementId].count = Rtm_Results[measurementId].count + 1;

      if(Rtm_Results[measurementId].time < currentTime)
      {
        /* Overflow occurred, reset results to defined state */
        Rtm_Results[measurementId].time = (uint32) 0u;
        Rtm_Results[measurementId].count = (uint32) 0u;
      }

      /* Check if a threshold is configured and exceeded */
      if((Rtm_ThresholdTimes[measurementId] < currentTime) && (0 < Rtm_ThresholdTimes[measurementId]))
      {
        /* Call threshold callback */
        (Rtm_ThresholdCbkFctArr[measurementId]) (currentTime);
      }
    }
    /* #-- Otherwise, inconsistent Start/Stop sequence detected; Only the active MP is allowed to be stopped. */
    else
    {
      Rtm_ReportDetError(RTM_API_ID_STOPMEASUREMENT, RTM_E_UNBALANCED); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    }
  }

  Rtm_CheckDetErrorContinue(((sint8) 0 <= Rtm_MeasurementNestingCtr[measurementId]), RTM_API_ID_STOPMEASUREMENT, RTM_E_UNBALANCED); /* PRQA S 3109 */  /* MD_MSR_14.3 */

  /* PRQA S 6080 4 */ /* MD_MSR_STMIF */
  /* PRQA S 6030 3 */ /* MD_MSR_STCYC */
  /* PRQA S 6010 2 */ /* MD_MSR_STPTH */
  /* PRQA S 2006 1 */ /* MD_MSR_14.7 */
} /* Rtm_StopNetMeasurementFct */

/**********************************************************************************************************************
 * Rtm_Schedule()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, RTM_CODE) Rtm_Schedule( uint32 FromThreadId,
                                   uint32 ToThreadId,
                                   uint16 CoreId )
{
  /* #10 If Rtm's functionality is enabled. */
#   if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
#   endif
  {
    Rtm_MeasurementTimestampType currentTime;
    RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    /* #20 If a Thread is suspended/preempted:
     *       Store the preempted MP and the current time. */
    Rtm_Net_LeaveThread( FromThreadId, CoreId, currentTime );

    /* #30 If a Thread is started and the Thread interrupted a net MP:
     *       Start the preempted net MP and add the preemption runtime to these MP and all interrupted nonnested MPs. */
    Rtm_Net_EnterThread( ToThreadId, CoreId, currentTime );
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif

  RTM_DUMMY_STATEMENT(CoreId); /* PRQA S 3112 */ /* MD_MSR_14.2 */
} /* Rtm_Schedule */

/**********************************************************************************************************************
 * Rtm_Net_LeaveThread()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
RTM_LOCAL_INLINE FUNC(void, RTM_CODE) Rtm_Net_LeaveThread( uint32 LeaveThread,
                                                           uint16 CoreId,
                                                           Rtm_MeasurementTimestampType CurrentTime )
{
  /* #20 If the Thread is in valid range:
   *       Remember which MP is preempted and when this happened. */
  if (LeaveThread < RTM_NUMBER_OF_THREADS)
  {
    Rtm_ThreadContext[LeaveThread].prevActiveMP = Rtm_ActiveMeasurementId;
    Rtm_ThreadContext[LeaveThread].preemptionTime = CurrentTime;
  }

  RTM_DUMMY_STATEMENT(CoreId); /* PRQA S 3112 */ /* MD_MSR_14.2 */
} /* Rtm_Net_LeaveThread */

/**********************************************************************************************************************
 * Rtm_Net_EnterThread()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
RTM_LOCAL_INLINE FUNC(void, RTM_CODE) Rtm_Net_EnterThread( uint32 EnterThread,
                                                           uint16 CoreId,
                                                           Rtm_MeasurementTimestampType CurrentTime )
{
#   if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON)
  uint32_least i;
  uint32 locPrevActive;
#   endif
  
  /* #20 If a Thread is started,
   *       and the Thread has interrupted a MP: */
  if (EnterThread < RTM_NUMBER_OF_THREADS)
  {
    Rtm_ActiveThreadId = EnterThread;
    Rtm_ActiveMeasurementId = Rtm_ThreadContext[EnterThread].prevActiveMP;

    if (Rtm_ActiveMeasurementId < RTM_MEAS_SECTION_COUNT)
    {
      /* #30 Calculate the preemption time. */
      Rtm_GetCounterDelta(Rtm_ThreadContext[EnterThread].preemptionTime, CurrentTime, &CurrentTime, Rtm_ActiveMeasurementId);

      /* #40 If there are MPs of NONNESTED and NESTED type, add preemption time to last active MP and all interrupted NONNESTED MPs. */
#   if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON) && (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON)
      Rtm_MeasurementPointInfo[Rtm_ActiveMeasurementId].intermediateTime += CurrentTime;
      locPrevActive = Rtm_MeasurementPointInfo[Rtm_ActiveMeasurementId].prevActive;

      for ( i = 1; 
            (i < RTM_MEAS_SECTION_COUNT) && 
            (locPrevActive < RTM_MEAS_SECTION_COUNT) &&
            (Rtm_MeasurementPointInfo[locPrevActive].threadContext == (uint32)EnterThread);
            i++ )
      {
        if (Rtm_MeasurementPointInfo[locPrevActive].isInterruptable == FALSE)
        {
          Rtm_MeasurementPointInfo[locPrevActive].intermediateTime += CurrentTime;
        }

        locPrevActive = Rtm_MeasurementPointInfo[locPrevActive].prevActive;
      }
#   else

      /* #50 If all MPs are of NONNESTED type, add preemption time to all interrupted MPs. */
#    if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON)
      locPrevActive = Rtm_ActiveMeasurementId;

      for ( i = 0; 
            (i < RTM_MEAS_SECTION_COUNT) && 
            (locPrevActive < RTM_MEAS_SECTION_COUNT) &&
            (Rtm_MeasurementPointInfo[locPrevActive].threadContext == (uint32)EnterThread);
            i++ )
      {
        Rtm_MeasurementPointInfo[locPrevActive].intermediateTime += CurrentTime;

        locPrevActive = Rtm_MeasurementPointInfo[locPrevActive].prevActive;
      }
#    endif

      /* #60 If all MPs are of NESTED type, add preemption time to the last active MP. */
#    if (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON)
      Rtm_MeasurementPointInfo[Rtm_ActiveMeasurementId].intermediateTime += CurrentTime;
#    endif

#   endif
    }
  }
  /* #-- Otherwise, no new context started, therefore no MP is currently active. */
  else
  {
    Rtm_ActiveMeasurementId = RTM_INACTIVE;
    Rtm_ActiveThreadId = RTM_NUMBER_OF_THREADS;
  }

  RTM_DUMMY_STATEMENT(CoreId); /* PRQA S 3112 */ /* MD_MSR_14.2 */
} /* Rtm_Net_EnterThread */

FUNC(void, RTM_CODE) Rtm_EnterTaskFct(void)
{
  /* #10 If Rtm's functionality is enabled. */
# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
    /* Only active measurements can be interrupted */
    Rtm_TaskType locTaskId;

    GetTaskID((TaskRefType)&locTaskId); /* PRQA S 3200 */ /* MD_Rtm_3200 */
  
    if (locTaskId < RTM_NUMBER_OF_TASKS)
    {
      Rtm_ThreadContext[locTaskId].prevActiveMP = Rtm_ActiveThreadId;
      Rtm_ActiveThreadId = locTaskId;

      if (Rtm_TaskContext[Rtm_TaskIndex[locTaskId]].prevActive < RTM_MEAS_SECTION_COUNT)
      {
#   if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON)
        uint16_least i;
#   endif
        uint32 locPrevActive = Rtm_TaskContext[Rtm_TaskIndex[locTaskId]].prevActive;
        Rtm_MeasurementTimestampType currentTime;
      
        RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */
        /* Get the intermediate time */
        Rtm_GetCounterDelta(Rtm_TaskContext[Rtm_TaskIndex[locTaskId]].startTime, currentTime, &currentTime, locPrevActive);

        /* There are measurement points set to execution time with nested and with non nested. */
#   if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON) && (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON)

        /* The last active measurement point gets the interrupting task runtime. */
        Rtm_MeasurementPointInfo[locPrevActive].intermediateTime = Rtm_MeasurementPointInfo[locPrevActive].intermediateTime + currentTime;
        locPrevActive = Rtm_MeasurementPointInfo[locPrevActive].prevActive;

        /* Also all non nested measurement points get the interrupting task runtime. */
        for (i = 1; (i < RTM_MEAS_SECTION_COUNT) && (locPrevActive < RTM_MEAS_SECTION_COUNT); i++)
        {
          if (Rtm_MeasurementPointInfo[locPrevActive].isInterruptable == FALSE)
          {
            Rtm_MeasurementPointInfo[locPrevActive].intermediateTime = Rtm_MeasurementPointInfo[locPrevActive].intermediateTime + currentTime;
          }

          locPrevActive = Rtm_MeasurementPointInfo[locPrevActive].prevActive;
        }
#   else

        /* All measurement points set to execution time are not nestable. */
#    if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON)
        /* Add task runtime to each measurement point's intermediate time which is set to execution time. */
        for (i = 0; (i < RTM_MEAS_SECTION_COUNT) && (locPrevActive < RTM_MEAS_SECTION_COUNT); i++)
        {
          Rtm_MeasurementPointInfo[locPrevActive].intermediateTime = Rtm_MeasurementPointInfo[locPrevActive].intermediateTime + currentTime;

          locPrevActive = Rtm_MeasurementPointInfo[locPrevActive].prevActive;
        }
#    endif /* (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON) */

        /* All measurement points set to execution time are also nestable. */
#    if (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON)
        /* Add task runtime to the single interrupted measurement point (only one can simultaneously be active). */
        /* The following line cannot be executed with previous for loops, thus a memory corruption is not possible here. */
        Rtm_MeasurementPointInfo[locPrevActive].intermediateTime = Rtm_MeasurementPointInfo[locPrevActive].intermediateTime + currentTime;
#    endif /* (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON) */

#   endif /* (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON) && (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON) */
        Rtm_ActiveMeasurementId = Rtm_TaskContext[Rtm_TaskIndex[locTaskId]].prevActive;
        Rtm_TaskContext[Rtm_TaskIndex[locTaskId]].prevActive = RTM_MEAS_SECTION_COUNT;
      }
    }
    else
    {
      Rtm_ReportDetError(RTM_API_ID_ENTERTASKFCT, RTM_E_INVALID_CONFIGURATION); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    }
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Rtm_EnterTaskFct */

FUNC(void, RTM_CODE) Rtm_LeaveTaskFct(void)
{
  /* #10 If Rtm's functionality is enabled. */
# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
    Rtm_TaskType locTaskId;
    GetTaskID((TaskRefType)&locTaskId); /* PRQA S 3200 */ /* MD_Rtm_3200 */

    if (locTaskId < RTM_NUMBER_OF_TASKS)
    {
      Rtm_ActiveThreadId = Rtm_ThreadContext[locTaskId].prevActiveMP;
    
      /* Only active measurements can be interrupted */
      if (Rtm_ActiveMeasurementId < RTM_MEAS_SECTION_COUNT)
      {
        Rtm_TimestampType currentTime;
        Rtm_TaskContext[Rtm_TaskIndex[locTaskId]].prevActive = Rtm_ActiveMeasurementId;
        Rtm_ActiveMeasurementId = RTM_INACTIVE;
        RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */

        Rtm_TaskContext[Rtm_TaskIndex[locTaskId]].startTime = currentTime;
      }
    }
    else
    {
      Rtm_ReportDetError(RTM_API_ID_LEAVETASKFCT, RTM_E_INVALID_CONFIGURATION); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    }
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Rtm_LeaveTaskFct */

FUNC(void, RTM_CODE) Rtm_EnterIsrFct(void)
{
  /* #10 If Rtm's functionality is enabled. */
# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
    uint32 locIsrId = GetISRID();

    if (locIsrId < RTM_NUMBER_OF_ISRS)
    {
      Rtm_ThreadContext[locIsrId + RTM_NUMBER_OF_TASKS].prevActiveMP = Rtm_ActiveThreadId;
      Rtm_ActiveThreadId = locIsrId + RTM_NUMBER_OF_TASKS;
    }

    /* Only active measurements can be interrupted */
    if (Rtm_ActiveMeasurementId < RTM_MEAS_SECTION_COUNT)
    {
      /* Only the outer ISR may change the runtime of measurement points */
      if (Rtm_IsrContext.isrId == RTM_NUMBER_OF_ISRS)
      {
        Rtm_TimestampType currentTime;
        Rtm_IsrContext.isrId = locIsrId;
        /* Safe measurement context */
        Rtm_IsrContext.prevActive = Rtm_ActiveMeasurementId;
        Rtm_ActiveMeasurementId = (uint32)RTM_PAUSED_BY_ISR;
        RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */
        Rtm_IsrContext.startTime = currentTime;
      }
    }
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Rtm_EnterIsrFct */

FUNC(void, RTM_CODE) Rtm_LeaveIsrFct(void)
{
  /* #10 If Rtm's functionality is enabled. */
# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
    uint32 locIsrId = GetISRID();

    if (locIsrId < RTM_NUMBER_OF_ISRS)
    {
      Rtm_ActiveThreadId = Rtm_ThreadContext[locIsrId + RTM_NUMBER_OF_TASKS].prevActiveMP;
    }

    /* Only active measurements can be interrupted */
    if (Rtm_ActiveMeasurementId == RTM_PAUSED_BY_ISR)
    {
      if (Rtm_IsrContext.isrId == locIsrId)
      {
#   if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON)
        uint16_least i;
#   endif
        uint32 currentTime;
        uint32 locPrevActive = Rtm_IsrContext.prevActive;
        /* Restore measurement context */
        RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */
        Rtm_GetCounterDelta(Rtm_IsrContext.startTime, currentTime, &currentTime, locPrevActive);

        /* There are measurement points set to execution time with nested and with non nested. */
#   if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON) && (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON)
        /* The last active measurement point and all non nested measurement points get the interrupting task runtime. */
        for (i = 0; (i < RTM_MEAS_SECTION_COUNT) && (locPrevActive < RTM_MEAS_SECTION_COUNT); i++)
        {
          if ((i == 0) || (Rtm_MeasurementPointInfo[locPrevActive].isInterruptable == FALSE))
          {
            Rtm_MeasurementPointInfo[locPrevActive].intermediateTime = Rtm_MeasurementPointInfo[locPrevActive].intermediateTime + currentTime;
          }

          locPrevActive = Rtm_MeasurementPointInfo[locPrevActive].prevActive;
        }
#   else

        /* All measurement points set to execution time are not nestable. */
#    if (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON)
        /* Add task runtime to each measurement point's intermediate time which is set to execution time. */
        for (i = 0; (i < RTM_MEAS_SECTION_COUNT) && (locPrevActive < RTM_MEAS_SECTION_COUNT); i++)
        {
          Rtm_MeasurementPointInfo[locPrevActive].intermediateTime = Rtm_MeasurementPointInfo[locPrevActive].intermediateTime + currentTime;

          locPrevActive = Rtm_MeasurementPointInfo[locPrevActive].prevActive;
        }
#    endif /* (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON) */

        /* All measurement points set to execution time are also nestable. */
#    if (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON)
        /* Add task runtime to the single interrupted measurement point (only one can simultaneously be active). */
        Rtm_MeasurementPointInfo[locPrevActive].intermediateTime = Rtm_MeasurementPointInfo[locPrevActive].intermediateTime + currentTime;
#    endif /* (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON) */

#   endif /* (RTM_EXECUTION_TIME_NONNESTED_AVAILABLE == STD_ON) && (RTM_EXECUTION_TIME_NESTED_AVAILABLE == STD_ON) */

        Rtm_ActiveMeasurementId = Rtm_IsrContext.prevActive;
        Rtm_IsrContext.prevActive = RTM_MEAS_SECTION_COUNT;
        Rtm_IsrContext.isrId = RTM_NUMBER_OF_ISRS;
      }
    }
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
} /* Rtm_LeaveIsrFct */
#  endif /* (RTM_NET_RUNTIME_SUPPORT == STD_ON) */
# endif /* (RTM_MULTICORE_SUPPORT == STD_OFF) */

/***********************************************************************************************************************
 *  Rtm_CheckTimerOverrun
 **********************************************************************************************************************/
/*! \brief      Rtm_CheckTimerOverrun. This function handles timer overruns.
 *  \param[in]  -
 *  \param[out] -
 *  \pre        -
 *  \context    Function is called from task level
 *  \note       This function has to be called by a cyclic task at least once before the timer expires.
 **********************************************************************************************************************/
 /* ESCAN00078841 */
FUNC(void, RTM_CODE) Rtm_CheckTimerOverrun(void) 
{
# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
    Rtm_MeasurementTimestampType currentTime;
    SchM_Enter_Rtm_RTM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */  /* MD_MSR_14.3 */ 
    RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    SchM_Exit_Rtm_RTM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    RTM_DUMMY_STATEMENT(currentTime); /* PRQA S 3112 */ /* MD_MSR_14.2 */
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif
} /* Rtm_CheckTimerOverrun */

# if (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF)
/***********************************************************************************************************************
 *  Rtm_CpuLoadMeasurementFunction
 **********************************************************************************************************************/
/*! \brief      Rtm_CpuLoadMeasurementFunction. This function calculates the MCUs overall CPU-Load.
 *  \param[in]  -
 *  \param[out] -
 *  \pre        -
 *  \context    Function is called from task level
 *  \note       This function has to be called in the idle-task. The idle-task should not contain any other code.
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_CpuLoadMeasurementFunction(void)
{
#  if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
#  endif
  {
    Rtm_MeasurementTimestampType cpuLoadSinceLastCall; 
    Rtm_MeasurementTimestampType currentTime;
#   if (RTM_MULTICORE_SUPPORT == STD_ON)
    uint16 locCoreId;
#   endif /* (RTM_MULTICORE_SUPPORT == STD_ON) */

    SchM_Enter_Rtm_RTM_EXCLUSIVE_AREA_2(); /* PRQA S 3109 */  /* MD_MSR_14.3 */

#   if (RTM_MULTICORE_SUPPORT == STD_ON)
    locCoreId = (uint16)Rtm_GetCoreId();
    if (Rtm_CpuLoadMeasurementActive[locCoreId] == RTM_TRUE)
#   else /* (RTM_MULTICORE_SUPPORT == STD_ON) */
    if (Rtm_CpuLoadMeasurementActive == RTM_TRUE)
#   endif /* (RTM_MULTICORE_SUPPORT == STD_ON) */
    {
      RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */

#   if (RTM_MULTICORE_SUPPORT == STD_ON)
      /* ESCAN00078841 */
      Rtm_GetCounterDelta(Rtm_CpuLoadStartTimestamp[locCoreId], currentTime, &cpuLoadSinceLastCall, RTM_CPU_LOAD_MEASUREMENT_ID);

      if(cpuLoadSinceLastCall > (Rtm_CpuLoadOverhead[locCoreId] + (Rtm_CpuLoadOverhead[locCoreId] >> 1))) /* Add 50% safety margin */
      {
        /* Only count runtimes which are not caused by this function itself */
        Rtm_CpuLoadCollectedTime[locCoreId] = (Rtm_CpuLoadCollectedTime[locCoreId] + cpuLoadSinceLastCall) - Rtm_CpuLoadOverhead[locCoreId];
      }
      Rtm_CpuLoadStartTimestamp[locCoreId] = currentTime;
#   else /* (RTM_MULTICORE_SUPPORT == STD_ON) */
      /* ESCAN00078841 */
      Rtm_GetCounterDelta(Rtm_CpuLoadStartTimestamp, currentTime, &cpuLoadSinceLastCall, RTM_CPU_LOAD_MEASUREMENT_ID);

      if(cpuLoadSinceLastCall > (Rtm_CpuLoadOverhead + (Rtm_CpuLoadOverhead >> 1))) /* Add 50% safety margin */
      {
        /* Only count runtimes which are not caused by this function itself */
        Rtm_CpuLoadCollectedTime = (Rtm_CpuLoadCollectedTime + cpuLoadSinceLastCall) - Rtm_CpuLoadOverhead;
      }
      Rtm_CpuLoadStartTimestamp = currentTime;
#   endif /* (RTM_MULTICORE_SUPPORT == STD_ON)) */
  
#   if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)  
      Rtm_PrevTimerValue = Rtm_CpuLoadStartTimestamp;
      Rtm_PrevOverrunCounterValues[RTM_CPU_LOAD_MEASUREMENT_ID] = Rtm_TimerOverrunCnt;
#   endif /* (RTM_TIMER_OVERRUN_SUPPORT == STD_ON) */
    }

    SchM_Exit_Rtm_RTM_EXCLUSIVE_AREA_2(); /* PRQA S 3109 */  /* MD_MSR_14.3 */
  }
#  if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
#  endif
} /* Rtm_CpuLoadMeasurementFunction */
# endif /* RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF */

/***********************************************************************************************************************
 *  Rtm_GetMeasurementItem
 **********************************************************************************************************************/
/*! \brief      This function returns the requested measurement result.
 *  \details    This function only returns valid results for measurement control mode Xcp or C_API.
 *  \param[in]  -
 *  \param[out] -
 *  \return     E_NOT_OK        The requested result could not be calculated.
 *  \return     E_OK            The requested result could be calculated.
 *  \pre        -
 *  \context    Task/ISR2
 **********************************************************************************************************************/
/* PRQA S 3673 3 */ /* MD_Rtm_3673 */
FUNC(Std_ReturnType, RTM_CODE) Rtm_GetMeasurementItem( CONST(uint32, AUTOMATIC) measurementId, 
                                                       CONST(Rtm_ItemType, AUTOMATIC) itemType, 
                                                       P2VAR(uint32, AUTOMATIC, RTM_APPL_VAR) itemValuePtr)
{
  Std_ReturnType retVal = E_NOT_OK;

# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
# if (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF)
    uint32 locMeasId = measurementId;
#  if (RTM_MULTICORE_SUPPORT == STD_ON)
    uint16 locCoreId = RTM_NUMBER_OF_CORES;
#  endif

    /* PRQA S 3109, 3201, 3355, 3356, 3358 1 */  /* MD_MSR_14.3, MD_Rtm_3201, MD_Rtm_3355, MD_Rtm_3356, MD_Rtm_3358 */
    Rtm_CheckDetErrorReturnValue((itemValuePtr != NULL_PTR), RTM_API_ID_GETMEASUREMENTITEM, RTM_E_WRONG_PARAMETERS, E_NOT_OK); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    /* PRQA S 3109,3201,3355,3358 15 */  /* MD_MSR_14.3,MD_Rtm_3201,MD_Rtm_3355,MD_Rtm_3358 */
#  if (RTM_MULTICORE_SUPPORT == STD_ON)
    Rtm_CheckValidMeasurementId(locMeasId, locCoreId);
#  else
    Rtm_CheckValidMeasurementId(locMeasId);
#  endif

    /*lint -e415 */ /* Suppress ID415 because array access is blocked for invalid index. */
    /* PRQA S 3201,3355,3356,3358,3359 12 */ /* MD_Rtm_3201,MD_Rtm_3355,MD_Rtm_3356,MD_Rtm_3358,MD_Rtm_3359 */
    if ((locMeasId < RTM_MEAS_SECTION_COUNT)
#  if (RTM_MULTICORE_SUPPORT == STD_ON)
         && (locCoreId < RTM_NUMBER_OF_CORES)
#  endif
#  if (RTM_DEV_ERROR_DETECT == STD_OFF)
         && (itemValuePtr != NULL_PTR)
#  endif
       )
    {
      switch(itemType)
      {
      case (RTM_ITEM_CPU_LOAD_AVERAGE):
        SchM_Enter_Rtm_RTM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */  /* MD_MSR_14.3 */
        if (Rtm_Results[locMeasId].count > 0)
        {
          *itemValuePtr = (uint32)((100 * (((Rtm_Results[locMeasId].time) / (Rtm_Results[locMeasId].count)))) / (RTM_MAINFCT_CYCLE_TIME * RTM_TICKS_PER_MILISECOND));
        }
        else
        {
          *itemValuePtr = 0;
        }
        retVal = E_OK;
        SchM_Exit_Rtm_RTM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */  /* MD_MSR_14.3 */
      break;
      case (RTM_ITEM_CPU_LOAD_CURRENT): /* ESCAN00079844 */
        SchM_Enter_Rtm_RTM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */  /* MD_MSR_14.3 */
#  if (RTM_MULTICORE_SUPPORT == STD_ON)
        *itemValuePtr = (uint32)((100 * Rtm_CpuLoadTime[locCoreId]) / (RTM_MAINFCT_CYCLE_TIME * RTM_TICKS_PER_MILISECOND));
#  else
        *itemValuePtr = (uint32)((100 * Rtm_CpuLoadTime) / (RTM_MAINFCT_CYCLE_TIME * RTM_TICKS_PER_MILISECOND));
#  endif
        retVal = E_OK;
        SchM_Exit_Rtm_RTM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */  /* MD_MSR_14.3 */
      break;
      case (RTM_ITEM_MIN):
        if (Rtm_Results[locMeasId].min < 0xFFFFFFFFu)
        {
          *itemValuePtr = (uint32)((100 * (Rtm_Results[locMeasId].min)) / (RTM_MAINFCT_CYCLE_TIME * RTM_TICKS_PER_MILISECOND));
        }
        else
        {
          *itemValuePtr = 0;
        }
        retVal = E_OK;
      break;
      case (RTM_ITEM_MAX):
        *itemValuePtr = (uint32)((100 * (Rtm_Results[locMeasId].max)) / (RTM_MAINFCT_CYCLE_TIME * RTM_TICKS_PER_MILISECOND));
        retVal = E_OK;
      break;
      default: /* PRQA S 2018 */ /* MD_Rtm_2018 */
        *itemValuePtr = 0;
      break;
      }
    }
    else /* PRQA S 3201 1 */ /* MD_Rtm_3201 */
    {
      /* Required for MISRA */
    }
# else /* (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF) */
    RTM_DUMMY_STATEMENT_CONST(measurementId); /* PRQA S 3112 */ /* MD_MSR_14.2 */
    RTM_DUMMY_STATEMENT_CONST(itemType); /* PRQA S 3112 */ /* MD_MSR_14.2 */
    RTM_DUMMY_STATEMENT(itemValuePtr); /* PRQA S 3112 */ /* MD_MSR_14.2 */
# endif /* (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF) */
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif
  return retVal;

  /* PRQA S 2006 2 */ /* MD_MSR_14.7 */
  /* PRQA S 6030 1 */ /* MD_MSR_STCYC */
} /* Rtm_GetMeasurementItem */

# if (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF)
#  if (RTM_MULTICORE_SUPPORT == STD_ON)
/***********************************************************************************************************************
 *  Rtm_InitCpuLoadMeasurement
 **********************************************************************************************************************/
/*! \brief      This function initializes RTMs overall CPU load measurement.
 *  \param[in]  -
 *  \param[out] -
 *  \pre        -
 *  \context    Function is called from task level
 *  \note       This function has to be called in Rtm_MainFunction.
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_InitCpuLoadMeasurement(uint16 coreId, uint32 cpuMeasId)
{
  Rtm_Results[cpuMeasId].count = 0x0u;
  Rtm_Results[cpuMeasId].time = 0x0u;
  Rtm_Results[cpuMeasId].min = 0xFFFFFFFFu;
  Rtm_Results[cpuMeasId].max = 0x0u;

  Rtm_CpuLoadWasStopped[coreId] = RTM_FALSE;
  Rtm_CpuLoadTime[coreId] = 0;
  Rtm_CpuLoadStartTimestamp[coreId] = RTM_GET_TIME_MEASUREMENT_FCT();

  /* Overall CPU-load calibration */
  Rtm_CpuLoadOverhead[coreId]      = (uint32) 0u;
  Rtm_CpuLoadCollectedTime[coreId] = (uint32) 0u;
  Rtm_CpuLoadMeasurementFunction();
  Rtm_CpuLoadCollectedTime[coreId] = (uint32) 0u;
  Rtm_CpuLoadMeasurementFunction();
  Rtm_CpuLoadOverhead[coreId]      = Rtm_CpuLoadCollectedTime[coreId];
  if (Rtm_CpuLoadOverhead[coreId] == 0)
  {
    Rtm_CpuLoadOverhead[coreId] = 1;
  }
}
#  endif /* (RTM_MULTICORE_SUPPORT == STD_ON) */
# endif /* (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF) */
#endif /* RTM_TIME_MEASUREMENT == STD_ON */

/***********************************************************************************************************************
 *  Rtm_InitMemory
 **********************************************************************************************************************/
/*! \brief      This function initializes RTMs internal state.
 *  \param[in]  -
 *  \param[out] -
 *  \pre        -
 *  \context    Function is called from task level
 *  \note       This function has to be called prior to the first call to Rtm_MainFunction.
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_InitMemory(void)
{
#if (RTM_TIME_MEASUREMENT == STD_ON)
  uint16_least i;

  for (i = 0; i < RTM_MEAS_SECTION_COUNT; i++)
  {
# if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
    Rtm_MeasurementPointInfo[i].intermediateTime = 0;
    Rtm_MeasurementPointInfo[i].prevActive = RTM_INACTIVE;
    Rtm_MeasurementPointInfo[i].threadContext = RTM_NUMBER_OF_THREADS;
# endif
# if ((RTM_NESTING_COUNTER == STD_ON) || (RTM_DEV_ERROR_DETECT == STD_ON))
    Rtm_MeasurementNestingCtr[i] = 0u;
# endif
    Rtm_StartTimeStamps[i] = 0u;
    Rtm_Results[i].time = 0u;
    Rtm_Results[i].count = 0u;
    Rtm_Results[i].min = (uint32) 0xFFFFFFFFu;
    Rtm_Results[i].max = 0u;
# if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
    Rtm_PrevOverrunCounterValues[i] = 0u;
# endif
  }

  for (i = 0; i < RTM_CTRL_VECTOR_LEN; i++)
  {
    Rtm_MeasurementConfig[i] = 0u;
    Rtm_Ctrl[i] = Rtm_CtrlConfig[i]; /* ESCAN00077449 */
  }

# if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
  /* Initialize task context */
  for (i = 0; i < RTM_NUMBER_OF_TASKS; i++)
  {
    Rtm_TaskContext[i].intermediateTime = Rtm_TaskContextInit[i].intermediateTime;
    Rtm_TaskContext[i].prevActive = Rtm_TaskContextInit[i].prevActive;
    Rtm_TaskContext[i].startTime = Rtm_TaskContextInit[i].startTime;
    Rtm_TaskContext[i].taskId = Rtm_TaskContextInit[i].taskId; /* ESCAN00087879 */
  }

  for (i = 0; i < RTM_NUMBER_OF_THREADS; i++)
  {
    Rtm_ThreadContext[i].preemptionTime = Rtm_ThreadContextInit[i].preemptionTime;
    Rtm_ThreadContext[i].prevActiveMP = Rtm_ThreadContextInit[i].prevActiveMP;
  }

  /* Initialize ISR context */
  Rtm_ActiveMeasurementId = RTM_INACTIVE;
  Rtm_ActiveThreadId = RTM_NUMBER_OF_THREADS;

  Rtm_IsrContext.intermediateTime = Rtm_IsrContextInit.intermediateTime;
  Rtm_IsrContext.prevActive = Rtm_IsrContextInit.prevActive;
  Rtm_IsrContext.startTime = Rtm_IsrContextInit.startTime;
  Rtm_IsrContext.isrId = Rtm_IsrContextInit.isrId;
# endif

# if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
  /* Initialize timer overrun variables */
  Rtm_TimerOverrunCnt = 0;
  Rtm_PrevTimerValue = 0;
# endif

# if (RTM_MULTICORE_SUPPORT == STD_ON)
  for (i = 0; i < RTM_NUMBER_OF_DISABLED_INT; i++)
  {
    Rtm_DisableInterruptFlag[i] = 0;
  }
# endif

  /* Set RTM state to uninitialized */
  Rtm_InitState = RTM_UNINITIALIZED;
#endif /* RTM_TIME_MEASUREMENT == STD_ON */

#if (RTM_CONTROL == STD_ON)
  Rtm_ControlState       = RTM_CONTROL_STATE_ENABLED;
  Rtm_ControlDeniedCount = 0;
#endif
} /* Rtm_InitMemory */

#if (RTM_TIME_MEASUREMENT == STD_ON)
/***********************************************************************************************************************
 *  Rtm_Init
 **********************************************************************************************************************/
/*! \brief      This function initializes Rtm.
 *  \param[in]  -
 *  \param[out] -
 *  \pre        -
 *  \context    Function is called from task level
 *  \note       This function has to be called prior to the first call to Rtm_MainFunction.
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_Init(void)
{
# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
# if (RTM_MULTICORE_SUPPORT == STD_ON)
    uint16_least i;
# endif /* (RTM_MULTICORE_SUPPORT == STD_ON) */

# if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
    Rtm_Init_TaskContext();
# endif /* (RTM_NET_RUNTIME_SUPPORT == STD_ON) */

# if (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF)
#  if (RTM_MULTICORE_SUPPORT == STD_ON)
    /* PRQA S 3109, 3201, 3355, 3358 1 */  /* MD_MSR_14.3, MD_Rtm_3201, MD_Rtm_3355, MD_Rtm_3358 */
    Rtm_ActivateCpuLoadMeasurementPoints();

    for (i = 0; i < RTM_NUMBER_OF_CORES; i++)
    {
      Rtm_CpuLoadOverhead[i] = 0x0u;
      Rtm_CpuLoadCollectedTime[i] = 0x0u;
      Rtm_CpuLoadStartTimestamp[i] = 0x0u;
      Rtm_CpuLoadWasStopped[i] = RTM_TRUE; /* ESCAN00079842 */
    }

#  else /* (RTM_MULTICORE_SUPPORT == STD_ON) */
    Rtm_CpuLoadOverhead = 0x0u;
    Rtm_CpuLoadCollectedTime = 0x0u;
    Rtm_CpuLoadStartTimestamp = 0x0u;
#   if defined (RTM_CPU_LOAD_AUTOSTART)
    Rtm_CpuLoadMeasurementActive = RTM_TRUE;
    Rtm_CpuLoadSendResult = RTM_TRUE;
#   else /*(RTM_CPU_LOAD_AUTOSTART) */
    Rtm_CpuLoadMeasurementActive = RTM_FALSE;
#   endif /* (RTM_CPU_LOAD_AUTOSTART) */
    Rtm_CpuLoadWasStopped = RTM_TRUE; /* ESCAN00079842 */

#  endif /* (RTM_MULTICORE_SUPPORT == STD_ON) */
# endif /* RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF */

# if (RTM_MULTICORE_SUPPORT == STD_ON)
    Rtm_SendNextMainFunction = RTM_FALSE;
    Rtm_MasterCore = (uint16)Rtm_GetCoreId();
    for (i = 0; i < RTM_NUMBER_OF_CORES; i++)
    {
      Rtm_CpuLoadTime[i] = 0x0u;
    }
# else /* (RTM_MULTICORE_SUPPORT == STD_ON) */
    Rtm_CpuLoadTime = 0x0u;
    Rtm_LiveMeasurement = RTM_FALSE;
# endif /* (RTM_MULTICORE_SUPPORT == STD_ON) */

    Rtm_CalculatedCtrEndVal = 0x0u;
    Rtm_MeasTimeCorrection = 0x0;
    Rtm_MeasurementTimer = 0x0u;

    Rtm_LastCommandToEcu = RTM_NULL;
    Rtm_Cmd = RTM_NULL;
    Rtm_Resp = RTM_NULL;
    Rtm_XcpState = XCP_EVENT_NOP;

    Rtm_AverageMainFunctionCycleTime = 0x0;
    Rtm_MainFunctionCounter = 0x0;
    Rtm_EndlessMeasurement = RTM_FALSE;
    Rtm_AvgMainFunctionCycleTimeCalcCounter = 0x0u;
    Rtm_LastMainFunctionTime = 0x0u;

    Rtm_InitState = RTM_INITIALIZED;
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif
} /* Rtm_Init */

#endif /* RTM_TIME_MEASUREMENT == STD_ON */

#if (RTM_MULTICORE_SUPPORT == STD_ON)
/*
 *
 */
FUNC(uint8, RTM_CODE) Rtm_MainFunction(uint16 coreId)
{
  uint8 sendEvent0 = RTM_FALSE;

# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
# if (RTM_TIME_MEASUREMENT == STD_ON)

    Rtm_CheckDetErrorReturnValue((coreId < RTM_NUMBER_OF_CORES), RTM_API_ID_MAINFUNCTION, RTM_E_WRONG_PARAMETERS, RTM_FALSE); /* PRQA S 3109 */  /* MD_MSR_14.3 */
  
    if (Rtm_MasterCore == coreId)
    {
      uint32 currentMainFuncCycleTime;
      uint32 cmd;
      uint32_least measurementIndex;
      uint16_least ctrlVecIndex;
      uint16 timeToMeasure;
      Rtm_MeasurementTimestampType currentTime;
      
      cmd = (uint8) (Rtm_Cmd >> 28);
      timeToMeasure = (uint16) Rtm_Cmd;

      /* Get current time */
      RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */

      /* If delayed sending was requested, send in this Rtm_MainFunction-Cycle */
      if (Rtm_SendNextMainFunction == RTM_TRUE)
      {
        Rtm_SendNextMainFunction = RTM_FALSE;
        sendEvent0 = RTM_TRUE;
      }

      /* ########################################################################################## */
      /* Process Serial/Parallel Measurement: */
      if (Rtm_LastCommandToEcu != RTM_NULL)
      {
        /* If endless measurement was started: */
        if (Rtm_EndlessMeasurement == RTM_TRUE)
        {
          Rtm_GetCounterDelta(Rtm_LastMainFunctionTime, currentTime, &currentMainFuncCycleTime, 0);

          if (Rtm_AvgMainFunctionCycleTimeCalcCounter < 32)
          {
            Rtm_AvgMainFunctionCycleTimeCalcCounter++;
          }
          Rtm_AverageMainFunctionCycleTime = ((Rtm_AverageMainFunctionCycleTime * (Rtm_AvgMainFunctionCycleTimeCalcCounter - 1)) + currentMainFuncCycleTime) / Rtm_AvgMainFunctionCycleTimeCalcCounter;

          Rtm_MainFunctionCounter++;
          Rtm_LastMainFunctionTime = currentTime;
        }
        /* Otherwise, time limited measurement was started: */
        else
        {
          /* If time to measure is elapsed: */
          if (Rtm_MeasurementTimer == 0u)
          {
            /* Deactivate all measurement points */
            for(ctrlVecIndex = 0; ctrlVecIndex < RTM_CTRL_VECTOR_LEN; ctrlVecIndex++)
            {
              Rtm_Ctrl[ctrlVecIndex] = (uint8) 0u;
            }

            Rtm_LastCommandToEcu = RTM_NULL;
            Rtm_Resp = ((uint32) RTM_RESP_OK << 28); /* ESCAN00076777 */
            /* Request sending in next Rtm_MainFunction-Cycle (avoid parallel writing and reading of Rtm_Results). */
            Rtm_SendNextMainFunction = RTM_TRUE;

            Rtm_FixTypeMismatch(currentTime); /* PRQA S 3109,3410 */ /* MD_MSR_14.3,MD_Rtm_3410 */
            /* Calculate measurement correction value. */
            Rtm_MeasTimeCorrection = (sint32) (Rtm_CalculatedCtrEndVal - currentTime);
          }
          /* Otherwise, decrement measurement duration timer. */
          else
          {
            Rtm_MeasurementTimer--;
          }
        }
      }

      /* ############################################################################################ */
      /* Start Serial/Parallel Measurement: */
      if ( ((cmd == RTM_CMD_START_SERIAL_MEASUREMENT) && (timeToMeasure > 0)) 
         || (cmd == RTM_CMD_START_PARALLEL_MEASUREMENT))
      {
        /* ... start all measurement points. */
        for (ctrlVecIndex = 0; ctrlVecIndex < RTM_CTRL_VECTOR_LEN; ctrlVecIndex++)
        {
          Rtm_Ctrl[ctrlVecIndex] = Rtm_MeasurementConfig[ctrlVecIndex];
        }

        Rtm_LastCommandToEcu = Rtm_Cmd;
        Rtm_Cmd = RTM_NULL;

        /* timeToMeasure == 0 --> Endless measurement */
        if (((uint16) 0u) == timeToMeasure)
        {
          Rtm_MeasurementTimer = 0u;
          Rtm_EndlessMeasurement = RTM_TRUE;
          Rtm_LastMainFunctionTime = currentTime;
          Rtm_AvgMainFunctionCycleTimeCalcCounter = 0u;
        }
        /* Measure for: Tcycle * timeToMeasure ms */
        else
        {
          /* ... set the number of Rtm_MainFunction-Cycles until measurement stops. */
          Rtm_MeasurementTimer = timeToMeasure;
          Rtm_EndlessMeasurement = RTM_FALSE;

          /* ... Calculate counter value at measurement stop */
          Rtm_CalculatedCtrEndVal = (Rtm_TimestampType)(currentTime + ((Rtm_MeasurementTimer + 1u) * RTM_TICKS_PER_MILISECOND * RTM_MAINFCT_CYCLE_TIME));
          Rtm_FixTypeMismatch(Rtm_CalculatedCtrEndVal); /* PRQA S 3109,3410 */  /* MD_MSR_14.3,MD_Rtm_3410 */
        }

        Rtm_CheckAutostartCpuLoad(sendEvent0);  /* PRQA S 3109 */  /* MD_MSR_14.3 */
      }

      /* ########################################################################################## */
      /* Stop Measurement: */
      if ((cmd == RTM_CMD_STOP_MEASUREMENT) && (Rtm_EndlessMeasurement == RTM_TRUE))
      {
        Rtm_EndlessMeasurement = RTM_FALSE;
        Rtm_MeasurementTimer = 0u;
        Rtm_LastMainFunctionTime = 0u;
        Rtm_AvgMainFunctionCycleTimeCalcCounter = 0u;

        for (ctrlVecIndex = 0; ctrlVecIndex < RTM_CTRL_VECTOR_LEN; ctrlVecIndex++)
        {
          Rtm_Ctrl[ctrlVecIndex] = (uint8) 0u;
        }

        /* Clear all measurement results */
#  if (RTM_NESTING_COUNTER == STD_ON)
        for (measurementIndex = 0; measurementIndex < RTM_MEAS_SECTION_COUNT; measurementIndex++)
        {
          Rtm_MeasurementNestingCtr[measurementIndex] = 0u;
        }
#  endif
    
        Rtm_Cmd = RTM_NULL;
        Rtm_Resp = ((uint32) RTM_RESP_OK << 28); /* ESCAN00076777 */
        Rtm_SendNextMainFunction = RTM_TRUE;
      }

      /* ########################################################################################## */
      /* Clear Results: */
      if (cmd == RTM_CMD_CLEAR_RESULTS)
      {
        /* ... clear all measurement results on all cores */
        for (measurementIndex = 0; measurementIndex < RTM_MEAS_SECTION_COUNT; measurementIndex++)
        {
          Rtm_Results[measurementIndex].time = (uint32) 0u;
          Rtm_Results[measurementIndex].count = (uint32) 0u;
          Rtm_Results[measurementIndex].min = (uint32) 0xFFFFFFFFu;
          Rtm_Results[measurementIndex].max = (uint32) 0u;

#  if (RTM_NESTING_COUNTER == STD_ON)
          Rtm_MeasurementNestingCtr[measurementIndex] = 0;
#  endif
        }

        Rtm_Cmd = RTM_NULL;

        /* Prepare response == OK */
        Rtm_Resp = ((uint32) RTM_RESP_OK << 28); /* ESCAN00076777 */
        sendEvent0 = RTM_TRUE;
      }
    }
# else /* (RTM_TIME_MEASUREMENT == STD_ON) */
    RTM_DUMMY_STATEMENT(coreId); /* PRQA S 3112 */ /* MD_MSR_14.2 */
# endif /* (RTM_TIME_MEASUREMENT == STD_ON) */
  }
# if (RTM_CONTROL == STD_ON)
  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif

  return sendEvent0;
  /* PRQA S 6080 5 */  /* MD_MSR_STMIF */
  /* PRQA S 6010 4 */  /* MD_MSR_STPTH */
  /* PRQA S 6030 3 */  /* MD_MSR_STCYC */
  /* PRQA S 6050 2 */  /* MD_MSR_STCAL */
  /* PRQA S 2006 1 */  /* MD_MSR_14.7 */
} /* Rtm_MainFunction */
#else /* (RTM_MULTICORE_SUPPORT == STD_OFF) */

/***********************************************************************************************************************
 *  Rtm_MainFunction
 **********************************************************************************************************************/
/*! \brief      This function controlls runtime and CPU-load measurements.
 *  \param[in]  -
 *  \param[out] -
 *  \pre        -
 *  \context    Function is called from task level
 *  \note       This function has to be called cyclically to control runtime- and CPU-load measurement.
 **********************************************************************************************************************/
FUNC(void, RTM_CODE) Rtm_MainFunction(void)
{
# if (RTM_CONTROL == STD_ON)
  if (Rtm_ControlState == RTM_CONTROL_STATE_ENABLED)
# endif
  {
# if (RTM_CPU_LOAD_CONTROL_MODE == RTM_CPU_LOAD_CONTROL_XCP)
    uint8 rtmCpuLoadMeasurementWasActive;
# endif

# if (RTM_TIME_MEASUREMENT == STD_ON)
    uint32 currentMainFuncCycleTime;
    Rtm_MeasurementTimestampType currentTime;
    Rtm_TimestampType timeToMeasure;
    uint16_least ctrlVecIndex;
    uint16_least measurementIndex;
    uint8 cmd;
    uint8 sendEvent0 = RTM_FALSE;

    Rtm_CheckDetErrorReturnVoid((RTM_INITIALIZED == Rtm_InitState), RTM_API_ID_MAINFUNCTION, RTM_E_UNINIT); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    SchM_Enter_Rtm_RTM_EXCLUSIVE_AREA_2(); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    /* Get current time */
    RTM_GET_CURRENT_TIME(currentTime); /* PRQA S 3109 */  /* MD_MSR_14.3 */
  
    /* Decode command from XCP-master */
    cmd = (uint8) (Rtm_Cmd >> 28);
    timeToMeasure = (uint16) Rtm_Cmd;

    /* ############################################################################################ */
    /* Process Live Measurement: */
    if ((Rtm_LastCommandToEcu != RTM_NULL) && (Rtm_LiveMeasurement == RTM_TRUE))
    {
      /* Deactivate live measurement after XCP-disconnect */
      if (XCP_EVENT_DAQ != Rtm_XcpState)
      {
        /* Measurements are going to get deactivated */
        Rtm_LiveMeasurement = RTM_FALSE;
        Rtm_MeasurementTimer = 0u;
        Rtm_EndlessMeasurement = RTM_FALSE;
      }
      else
      {
        if (Rtm_EndlessMeasurement == RTM_FALSE)
        {
          /* XCP on line, calculate correction values for live measurement */
          Rtm_MeasTimeCorrection = (sint32) (Rtm_CalculatedCtrEndVal - currentTime);
          Rtm_CalculatedCtrEndVal = (Rtm_TimestampType) (currentTime + (1u * RTM_TICKS_PER_MILISECOND * RTM_MAINFCT_CYCLE_TIME));
        
          if( 0u == Rtm_MeasurementTimer)
          {
            /* Measurement run the predefined time. Stop! */
            for(ctrlVecIndex = 0; ctrlVecIndex < RTM_CTRL_VECTOR_LEN; ctrlVecIndex++)
            {
              Rtm_Ctrl[ctrlVecIndex] = (uint8) 0u;
            }

            Rtm_LastCommandToEcu = RTM_NULL;
            Rtm_LiveMeasurement = RTM_FALSE;
          }
          else
          {
            Rtm_MeasurementTimer--;
          }
        }
        else
        {
          Rtm_GetCounterDelta(Rtm_LastMainFunctionTime, currentTime, &Rtm_AverageMainFunctionCycleTime, 0);

          Rtm_LastMainFunctionTime = currentTime;
        }

        /* Always send if Live Measurement is active. */
        Rtm_Resp = ((uint32) RTM_RESP_OK << 28); /* ESCAN00076777 */
        sendEvent0 = RTM_TRUE;
      }
    }
  
    /* ############################################################################################ */
    /* Process Serial/Parallel Measurement: */
    if ((Rtm_LastCommandToEcu != RTM_NULL) && (Rtm_LiveMeasurement == RTM_FALSE))
    {
      if (Rtm_EndlessMeasurement == RTM_TRUE)
      {
        Rtm_GetCounterDelta(Rtm_LastMainFunctionTime, currentTime, &currentMainFuncCycleTime, 0);

        if (Rtm_AvgMainFunctionCycleTimeCalcCounter < 32)
        {
          Rtm_AvgMainFunctionCycleTimeCalcCounter++;
        }
        Rtm_AverageMainFunctionCycleTime = ((Rtm_AverageMainFunctionCycleTime * (Rtm_AvgMainFunctionCycleTimeCalcCounter - 1)) + currentMainFuncCycleTime) / Rtm_AvgMainFunctionCycleTimeCalcCounter;

        Rtm_MainFunctionCounter++;
        Rtm_LastMainFunctionTime = currentTime;
      }
      else
      {
        /* Only handle timer if measurement is active and not live */
        if( 0u == Rtm_MeasurementTimer)
        {
          /* Measurement run the predefined time. Stop! */
          for(ctrlVecIndex = 0; ctrlVecIndex < RTM_CTRL_VECTOR_LEN; ctrlVecIndex++)
          {
            Rtm_Ctrl[ctrlVecIndex] = (uint8) 0u;
          }

          Rtm_LastCommandToEcu = RTM_NULL;
          Rtm_Resp = ((uint32) RTM_RESP_OK << 28); /* ESCAN00076777 */
          sendEvent0 = RTM_TRUE;

          /* Calculate measurement correction value */
          Rtm_MeasTimeCorrection = (sint32) (Rtm_CalculatedCtrEndVal - currentTime);
        }
        else
        {
          Rtm_MeasurementTimer--;
        }
      }
    }
  
    /* ############################################################################################ */
    /* Start Serial/Parallel Measurement: */
    if ( ((cmd == RTM_CMD_START_SERIAL_MEASUREMENT) && (timeToMeasure > 0)) 
       || (cmd == RTM_CMD_START_PARALLEL_MEASUREMENT))
    {
      /* Start measurement of each configured module */
      for (ctrlVecIndex = 0; ctrlVecIndex < RTM_CTRL_VECTOR_LEN; ctrlVecIndex++)
      {
        Rtm_Ctrl[ctrlVecIndex] = Rtm_MeasurementConfig[ctrlVecIndex];
      }

      /* timeToMeasure == 0 --> Endless measurement */
      if (((uint16) 0u) == timeToMeasure)
      {
        Rtm_MeasurementTimer = 0u;
        Rtm_EndlessMeasurement = RTM_TRUE;
        Rtm_LastMainFunctionTime = currentTime;
        Rtm_AvgMainFunctionCycleTimeCalcCounter = 0u;
      }
      /* Measure for: Tcycle * timeToMeasure ms */
      else
      {
        Rtm_MeasurementTimer = timeToMeasure;
        Rtm_EndlessMeasurement = RTM_FALSE;

        /* Calculate counter value at measurement stop */
        Rtm_CalculatedCtrEndVal = (Rtm_TimestampType)(currentTime + ((Rtm_MeasurementTimer + 1u) * RTM_TICKS_PER_MILISECOND * RTM_MAINFCT_CYCLE_TIME));
      }

      Rtm_LastCommandToEcu = Rtm_Cmd;
      Rtm_Cmd = RTM_NULL;

#  if defined (RTM_CPU_LOAD_AUTOSTART)
      if (Rtm_CpuLoadSendResult == RTM_TRUE)
      {
        Rtm_CpuLoadMeasurementActive = RTM_FALSE;
        Rtm_CpuLoadSendResult = RTM_FALSE;
        sendEvent0 = RTM_TRUE;
      }
#  endif
    }
  
    /* ############################################################################################ */
    /* Start Live Measurement: */
    if (cmd == RTM_CMD_START_LIVE_MEASUREMENT)
    {
      Rtm_LiveMeasurement = RTM_TRUE;

      /* Start measurement of each configured module */
      for (ctrlVecIndex = 0; ctrlVecIndex < RTM_CTRL_VECTOR_LEN; ctrlVecIndex++)
      {
        Rtm_Ctrl[ctrlVecIndex] = Rtm_MeasurementConfig[ctrlVecIndex];
      }

      /* timeToMeasure == 0 --> Endless measurement */
      if (((uint16) 0u) == timeToMeasure)
      {
        Rtm_MeasurementTimer = 0u;
        Rtm_EndlessMeasurement = RTM_TRUE;
        Rtm_MainFunctionCounter = 1;
      }
      /* Measure for: Tcycle * timeToMeasure ms */
      else
      {
        Rtm_MeasurementTimer = timeToMeasure;
        Rtm_EndlessMeasurement = RTM_FALSE;

        /* Calculate counter value at measurement stop */
        Rtm_CalculatedCtrEndVal = (Rtm_TimestampType)(currentTime + ((Rtm_MeasurementTimer + 1u) * RTM_TICKS_PER_MILISECOND * RTM_MAINFCT_CYCLE_TIME));
      }
    
      Rtm_LastCommandToEcu = Rtm_Cmd;
      Rtm_Cmd = RTM_NULL;
    }

    /* ############################################################################################ */
    /* Stop Measurement: */
    if ((RTM_CMD_STOP_MEASUREMENT == cmd) && (Rtm_EndlessMeasurement == RTM_TRUE))
    {
      Rtm_EndlessMeasurement = RTM_FALSE;
      Rtm_MeasurementTimer = 0u;
      Rtm_LastMainFunctionTime = 0u;
      Rtm_AvgMainFunctionCycleTimeCalcCounter = 0u;

      for(ctrlVecIndex = 0; ctrlVecIndex < RTM_CTRL_VECTOR_LEN; ctrlVecIndex++)
      {
        Rtm_Ctrl[ctrlVecIndex] = (uint8) 0u;
      }

      /* Clear all measurement results */
      for (measurementIndex = 0; measurementIndex < RTM_MEAS_SECTION_COUNT; measurementIndex++)
      {
#  if (RTM_NESTING_COUNTER == STD_ON)
        Rtm_MeasurementNestingCtr[measurementIndex] = 0u;
#  endif
#  if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
        Rtm_PrevOverrunCounterValues[measurementIndex] = Rtm_TimerOverrunCnt;
#  endif
#  if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
        Rtm_MeasurementPointInfo[measurementIndex].intermediateTime = 0;
        Rtm_MeasurementPointInfo[measurementIndex].prevActive = RTM_INACTIVE;
#  endif
      }

#  if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)    
      Rtm_GetCurrentTimeCnt = 0;
#  endif
#  if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
      Rtm_ActiveMeasurementId = RTM_INACTIVE;
  
      for (measurementIndex = 0; measurementIndex < RTM_NUMBER_OF_CORES; measurementIndex++)
      {
        Rtm_TaskContext[measurementIndex].intermediateTime = Rtm_TaskContextInit[measurementIndex].intermediateTime;
        Rtm_TaskContext[measurementIndex].prevActive = Rtm_TaskContextInit[measurementIndex].prevActive;
        Rtm_TaskContext[measurementIndex].startTime = Rtm_TaskContextInit[measurementIndex].startTime;
      }

      Rtm_IsrContext.intermediateTime = Rtm_IsrContextInit.intermediateTime;
      Rtm_IsrContext.prevActive = Rtm_IsrContextInit.prevActive;
      Rtm_IsrContext.startTime = Rtm_IsrContextInit.startTime;
      Rtm_IsrContext.isrId = Rtm_IsrContextInit.isrId;
#  endif /* (RTM_NET_RUNTIME_SUPPORT == STD_ON) */
    
      Rtm_Cmd = RTM_NULL;
      Rtm_Resp = ((uint32) RTM_RESP_OK << 28); /* ESCAN00076777 */
      sendEvent0 = RTM_TRUE;
    }

    /* ############################################################################################ */
    /* Clear Results: */
    if (RTM_CMD_CLEAR_RESULTS == cmd)
    {
      Rtm_AverageMainFunctionCycleTime = 0;
      Rtm_MainFunctionCounter = 0;

      /* Clear all measurement results */
      for (measurementIndex = 0; measurementIndex < RTM_MEAS_SECTION_COUNT; measurementIndex++)
      {
#  if (RTM_NESTING_COUNTER == STD_ON)
        Rtm_MeasurementNestingCtr[measurementIndex] = 0u;
#  endif
        Rtm_Results[measurementIndex].time = (uint32) 0u;
        Rtm_Results[measurementIndex].count = (uint32) 0u;
        Rtm_Results[measurementIndex].min = (uint32) 0xFFFFFFFFu;
        Rtm_Results[measurementIndex].max = (uint32) 0u;
#  if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
        Rtm_PrevOverrunCounterValues[measurementIndex] = Rtm_TimerOverrunCnt;
#  endif
#  if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
        Rtm_MeasurementPointInfo[measurementIndex].intermediateTime = 0;
        Rtm_MeasurementPointInfo[measurementIndex].prevActive = RTM_INACTIVE;
#  endif
      }

#  if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)    
      Rtm_GetCurrentTimeCnt = 0;
#  endif
#  if (RTM_NET_RUNTIME_SUPPORT == STD_ON)
      Rtm_ActiveMeasurementId = RTM_INACTIVE;
  
      for (measurementIndex = 0; measurementIndex < RTM_NUMBER_OF_CORES; measurementIndex++)
      {
        Rtm_TaskContext[measurementIndex].intermediateTime = Rtm_TaskContextInit[measurementIndex].intermediateTime;
        Rtm_TaskContext[measurementIndex].prevActive = Rtm_TaskContextInit[measurementIndex].prevActive;
        Rtm_TaskContext[measurementIndex].startTime = Rtm_TaskContextInit[measurementIndex].startTime;
      }

      Rtm_IsrContext.intermediateTime = Rtm_IsrContextInit.intermediateTime;
      Rtm_IsrContext.prevActive = Rtm_IsrContextInit.prevActive;
      Rtm_IsrContext.startTime = Rtm_IsrContextInit.startTime;
      Rtm_IsrContext.isrId = Rtm_IsrContextInit.isrId;
#  endif /* (RTM_NET_RUNTIME_SUPPORT == STD_ON) */

      Rtm_Cmd = RTM_NULL;
      Rtm_Resp = ((uint32) RTM_RESP_OK << 28); /* ESCAN00076777 */
      sendEvent0 = RTM_TRUE;
    }

    /* ############################################################################################ */
    /* CPU Load Measurement: */
#  if (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF)
    /* Overall CPU-load measurement */
    Rtm_CpuLoadMeasurementFunction(); /* ESCAN00079113 */
    Rtm_CpuLoadTime = Rtm_CpuLoadCollectedTime;
    Rtm_CpuLoadCollectedTime = (uint32) 0u;

#   if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
    Rtm_PrevOverrunCounterValues[RTM_CPU_LOAD_MEASUREMENT_ID] = Rtm_TimerOverrunCnt;
#   endif
  
    if (Rtm_CpuLoadMeasurementActive == RTM_TRUE)
    {
#   if (RTM_CPU_LOAD_CONTROL_MODE == RTM_CPU_LOAD_CONTROL_C_API)
      /* If new cpu load measurement cycle is triggered, the old results are cleaned */
      if (Rtm_CpuLoadWasStopped != RTM_FALSE)
      {
        Rtm_InitCpuLoadMeasurement();
      }
      else
      {
#   endif
        Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].count++;
        Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].time = Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].time + Rtm_CpuLoadTime;
        if (Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].min > Rtm_CpuLoadTime)
        {
          Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].min = (Rtm_MeasurementTimestampType)Rtm_CpuLoadTime;
        }
        if (Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].max < Rtm_CpuLoadTime)
        {
          Rtm_Results[RTM_CPU_LOAD_MEASUREMENT_ID].max = (Rtm_MeasurementTimestampType)Rtm_CpuLoadTime;
        }
#   if (RTM_CPU_LOAD_CONTROL_MODE == RTM_CPU_LOAD_CONTROL_C_API)
      }
#   endif
    }

#   if (RTM_CPU_LOAD_CONTROL_MODE == RTM_CPU_LOAD_CONTROL_XCP)
    rtmCpuLoadMeasurementWasActive = Rtm_CpuLoadMeasurementActive;

    Rtm_Start(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    /* If cpu load measurement is started, make reference measurement */
    if ((Rtm_CpuLoadMeasurementActive == RTM_TRUE) && 
        ((rtmCpuLoadMeasurementWasActive == RTM_FALSE) || 
         (Rtm_CpuLoadWasStopped == RTM_TRUE)
        )
       )
    {
      Rtm_InitCpuLoadMeasurement();
    }
#   endif
#  endif /* (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF) */  

    /* ############################################################################################ */
    /* Execute Overhead Measurement: */
    Rtm_Start(RtmConf_RtmMeasurementPoint_Rtm_Overhead_EnableInterrupts); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    Rtm_Stop(RtmConf_RtmMeasurementPoint_Rtm_Overhead_EnableInterrupts); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    Rtm_Start(RtmConf_RtmMeasurementPoint_Rtm_Overhead_DisableInterrupts); /* PRQA S 3109 */  /* MD_MSR_14.3 */
    Rtm_Stop(RtmConf_RtmMeasurementPoint_Rtm_Overhead_DisableInterrupts); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    SchM_Exit_Rtm_RTM_EXCLUSIVE_AREA_2(); /* PRQA S 3109 */  /* MD_MSR_14.3 */

    /* ############################################################################################ */
    /* Send XCP event: */
    if((RTM_TRUE == sendEvent0) || (RTM_TRUE == Rtm_LiveMeasurement))
    {
      Rtm_XcpState = Xcp_Event(EV_RTM);
    }
# else /* (RTM_TIME_MEASUREMENT == STD_ON) */
    return; /*lint -e522 */ /* Suppress ID522 because RTM should do nothing if no measurement point is enabled. */
# endif /* (RTM_TIME_MEASUREMENT == STD_ON) */
  }
# if (RTM_CONTROL == STD_ON)

  else
  {
    Rtm_ControlDeniedCount++;
  }
# endif
  /* PRQA S 6080 5 */  /* MD_MSR_STMIF */
  /* PRQA S 6010 4 */  /* MD_MSR_STPTH */
  /* PRQA S 6030 3 */  /* MD_MSR_STCYC */
  /* PRQA S 6050 2 */  /* MD_MSR_STCAL */
  /* PRQA S 2006 1 */  /* MD_MSR_14.7 */
} /* Rtm_MainFunction */

#endif /* (RTM_MULTICORE_SUPPORT == STD_ON) */

#define RTM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 ********************************************************************************************************************/
/* module specific MISRA deviations:

   MD_Rtm_3201:    MISRA rule: 14.1: 
     Reason:        If the function is called with invalid parameters the stament is not reachable.
     Risk:          Compiler warning.
     Prevention:    Covered by code review.

   MD_Rtm_3410:     MISRA rule: 19.10:
     Reason:        Assignment cannot be enclosed in brackets.
     Risk:          Compile error.
     Prevention:    Not required.

   MD_Rtm_0342:     MISRA rule: 19.13: K&R compilers do not support the ISO glue operator ##. AUTOSAR requires C90 and 
                                       C90 supports ## operators.
     Reason:        Identifier has to be a combination of both IDs
     Risk:          Compile error.
     Prevention:    Not required.

   MD_Rtm_3355:     MISRA Rule: 13.7:
     Reason:        Result or value is always true or false depend on configuration aspect and used platform specific implementation.
     Risk:          Incorrect platform specific return will be ignored.
     Prevention:    Code inspection and test of the different variants in the component test.

   MD_Rtm_3356:     MISRA Rule: 13.7:
     Reason:        Result or value is always true or false depend on configuration aspect and used platform specific implementation
     Risk:          Incorrect platform specific return will be ignored.
     Prevention:    Code inspection and test of the different variants in the component test.

   MD_Rtm_3358:     MISRA Rule: 13.7:
     Reason:        Result or value is always true or false depend on configuration aspect and used platform specific implementation
     Risk:          Incorrect platform specific return will be ignored.
     Prevention:    Code inspection and test of the different variants in the component test.

   MD_Rtm_3359:     MISRA Rule: 13.7:
     Reason:        Result or value is always true or false depend on configuration aspect and used platform specific implementation
     Risk:          Incorrect platform specific return will be ignored.
     Prevention:    Code inspection and test of the different variants in the component test.

   MD_Rtm_5115:     MISRA rule: 20.2: The names of standard library macros, objects and functions shall not be reused.
     Reason:        Name of Rtm_DataSet struct member is called 'time'. Automotive software does not used standard libraries.
     Risk:          No risk, because RTM 'time' is encapsulated in struct.
     Prevention:    Do not use standard libraries.

   MD_Rtm_3200:     MISRA rule: 16.10: '%s' returns a value which is not being used.
     Reason:        The API is defined by OS. To be robust against defining GetTaskID as code 
                    ("#define GetTaskID { ... }") the void cast is omitted.
     Risk:          The return value is not handled by RTM, thus the compiler has to care about it.
     Prevention:    Not required.

   MD_Rtm_3673:      MISRA rule: 16.7: The object addressed by the pointer parameter '%s' is not modified and so the
                                      pointer could be of type 'pointer to const'.
     Reason:        This violation only occurs if RTM_CPU_LOAD_CONTROL_MODE is set to RTM_CPU_LOAD_CONTROL_OFF 
                    because the function Rtm_GetMesaurementItem does not return a value in this case.
     Risk:          The return value is not handled by RTM, thus the compiler has to care about it.
     Prevention:    Not required.

   MD_Rtm_3408:     MISRA rule: 8.8: '-identifier-' has external linkage but is being defined without any previous
                                     declaration.
     Reason:        This violation only occurs if RTM_LOCAL is defined to nothing.
     Risk:          The global variables could be re-defined in another file.
     Prevention:    Define RTM_LOCAL as static.

   MD_Rtm_883:      MISRA rule: 19.15: Precautions shall be taken in order to prevent the contents of a header file
                                       being included twice.
     Reason:        QAC does not find the "#if !defined / #define / #endif" in Rtm_Cfg.h although it exists.
     Risk:          Could be removed without being detected by QAC (=> Compiel Error).
     Prevention:    Code inspection and test of the different variants in the component test.

   MD_Rtm_2018:     MISRA rule: 14.1: There shall be no unreachable code.
     Reason:        The default path cannot be reached if DET is enabled, but a default path in a switch or
                    if-/if-else-statement is always required.
     Risk:          No risk.
     Prevention:    Not required.
*/

/* COV_JUSTIFICATION_BEGIN

\ID COV_RTM_FILTER_PAUSE_SUPPORT
\ACCEPT XF xf xx
\ACCEPT XF xf ??
\REASON The feature pause support is always filtered

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: Rtm.c
 *********************************************************************************************************************/

