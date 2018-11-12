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
 *         File:  Sd_Priv.h
 *       Module:  SysService_AsrSd
 *    Generator:  SysService_AsrSd.jar (DaVinci Configurator Pro)
 *
 *  Description:  Types definitions of Service Discovery (SD)
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (SD_PRIV_H)
#define SD_PRIV_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Sd.h"
#if (STD_ON == SD_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* SD_DEV_ERROR_DETECT */
#if (STD_ON == SD_DEM_EVENTS_CONFIGURED)
#include "Dem.h" /* \trace SPEC-60076 */
#endif /* SD_DEM_EVENTS_CONFIGURED */
#include "SchM_Sd.h"


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SD_HEADER_LENGTH_SD 0x0Cu  /* The length contains the Sd header including the additional Flags and Reserved fields without the PduHeader information */


/**********************************************************************************************************************
*  GLOBAL FUNCTION MACROS
*********************************************************************************************************************/
#define SD_BEGIN_CRITICAL_SECTION() SchM_Enter_Sd_SD_EXCLUSIVE_AREA_0()
#define SD_END_CRITICAL_SECTION() SchM_Exit_Sd_SD_EXCLUSIVE_AREA_0()

/* PRQA S 3458 BRACED_MACROS */ /* MD_MSR_19.4 */
/* PRQA S 3453 FCT_MACROS */ /* MD_MSR_19.7 */

#define Sd_TriggerStateMachineRun( INSTANCE_PTR ) \
          { \
            (INSTANCE_PTR)->DynamicDataPtr->NextStateMachineRun.Seconds = 0U; \
            (INSTANCE_PTR)->DynamicDataPtr->NextStateMachineRun.Milliseconds = 0U; \
          }

#define Sd_SetNextStateMachineRun( INSTANCE_PTR, TIMER ) \
          { \
          if(((INSTANCE_PTR)->DynamicDataPtr->NextStateMachineRun.Seconds > (TIMER).Seconds) || \
            (((INSTANCE_PTR)->DynamicDataPtr->NextStateMachineRun.Seconds == (TIMER).Seconds) && \
            ((INSTANCE_PTR)->DynamicDataPtr->NextStateMachineRun.Milliseconds > (TIMER).Milliseconds))) \
            { \
              (INSTANCE_PTR)->DynamicDataPtr->NextStateMachineRun.Seconds      = (TIMER).Seconds; \
              (INSTANCE_PTR)->DynamicDataPtr->NextStateMachineRun.Milliseconds = (TIMER).Milliseconds; \
            } \
          }

#define Sd_SetTimerOffsetNoTrigger( TIMER, OFFSET_IN_MS ) \
          { \
            SD_BEGIN_CRITICAL_SECTION(); \
            (TIMER).Seconds      = Sd_TimeMsSinceStart.Seconds      + ((OFFSET_IN_MS) / 1000); \
            (TIMER).Milliseconds = Sd_TimeMsSinceStart.Milliseconds + (uint16)((OFFSET_IN_MS) % 1000); \
            (TIMER).Seconds      = (TIMER).Seconds                  + ((TIMER).Milliseconds / 1000); \
            (TIMER).Milliseconds = (TIMER).Milliseconds             % 1000; \
            SD_END_CRITICAL_SECTION(); \
          }

#define Sd_SetTimerOffset( TIMER, OFFSET_IN_MS, INSTANCE_PTR ) \
          { \
            Sd_SetTimerOffsetNoTrigger( (TIMER), (OFFSET_IN_MS) ); \
            Sd_SetNextStateMachineRun((INSTANCE_PTR), (TIMER)); \
          }

#define Sd_ResetTimerToZero( TIMER ) \
          { \
            (TIMER).Seconds = 0U; \
            (TIMER).Milliseconds = 0U; \
          }

#define Sd_ResetTimerToZeroTrigger( TIMER, INSTANCE_PTR ) \
          { \
            Sd_ResetTimerToZero(( TIMER )); \
            Sd_TriggerStateMachineRun((INSTANCE_PTR)); \
          }

#define Sd_ResetTimerToInvalid( TIMER ) \
          { \
            (TIMER).Seconds = SD_INV_TIMER_VALUE_32BIT; \
            (TIMER).Milliseconds = SD_INV_TIMER_VALUE_16BIT; \
          }

#define Sd_SetValueAndTrigger( PARAMETER, VALUE, INSTANCE_PTR ) \
          { \
            Sd_TriggerStateMachineRun((INSTANCE_PTR)); \
            (PARAMETER) = (VALUE); \
          }

#define Sd_CheckIfTimerIsInvalid(TIMER)                 ((SD_INV_TIMER_VALUE_32BIT == (TIMER).Seconds) && (SD_INV_TIMER_VALUE_16BIT == (TIMER).Milliseconds))
#define Sd_CheckIfTimerIsZero(TIMER)                    ((0 == (TIMER).Seconds) && (0 == (TIMER).Milliseconds))

#define Sd_EventHandlerUsesUdp(EVENTHANDLER)            (NULL_PTR != (EVENTHANDLER)->UdpRefPtr)
#define Sd_EventHandlerUsesTcp(EVENTHANDLER)            (NULL_PTR != (EVENTHANDLER)->TcpRefPtr)
#define Sd_EventHandlerUsesMulticast(EVENTHANDLER)      (NULL_PTR != (EVENTHANDLER)->MulticastRefPtr)

#define Sd_ConsumedEventGroupUsesUdp(EVENTGROUP)        (SOAD_INV_ROUT_GRP_ID != (EVENTGROUP)->UdpActRef)
#define Sd_ConsumedEventGroupUsesTcp(EVENTGROUP)        (SOAD_INV_ROUT_GRP_ID != (EVENTGROUP)->TcpActRef)
#define Sd_ConsumedEventGroupUsesMulticast(EVENTGROUP)  (SOAD_INV_ROUT_GRP_ID != (EVENTGROUP)->MulticastActRef)

#define Sd_GetInstancePtrByIdx(InstanceIdx)             (Sd_ConfigPtr->InstanceListPtr[InstanceIdx])
#define Sd_GetOptionIndexListPtr()                      (Sd_ConfigPtr->OptionIndexListPtr)
#define Sd_GetNrOfOptionsInList()                       (Sd_ConfigPtr->OptionIndexListPtr->NrOfOptions)
#define Sd_GetOptionIndex(OptionIdx)                    (Sd_ConfigPtr->OptionIndexListPtr->OptionIndexPtr[OptionIdx])
#define Sd_IsTriggerTransmitUsed()                      (NULL_PTR != Sd_ConfigPtr->TriggerTransmitListPtr)
#define Sd_GetTriggerTransmitList()                     (*(Sd_ConfigPtr->TriggerTransmitListPtr))
#define Sd_GetTriggerTransmitEvent(EventIdx)            (Sd_ConfigPtr->TriggerTransmitEventArrayPtr[EventIdx])
#define Sd_GetTmpSendEntryList()                        (*(Sd_ConfigPtr->TmpSendEntryListPtr))
#define Sd_GetTmpSendEntry(EntryIdx)                    (Sd_ConfigPtr->TmpSendEntryPtr[EntryIdx])
#define Sd_GetIpAddrRequestCntMapSize()                 (Sd_ConfigPtr->IpAddrRequestCntMapSize)
#define Sd_GetIpAddrRequestCntEntry(EntryIdx)           (Sd_ConfigPtr->IpAddrRequestCntMapPtr[EntryIdx])

/* Development Error Tracer */
#if (STD_ON == SD_DEV_ERROR_DETECT)
# define Sd_CheckDetErrorReturnVoid(  CONDITION, API_ID, ERROR_CODE )          { if(!(CONDITION)) { (void)Det_ReportError( SD_MODULE_ID, SD_INSTANCE_ID, (API_ID), (ERROR_CODE)); return; } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Sd_CheckDetErrorReturnValue( CONDITION, API_ID, ERROR_CODE, RET_VAL ) { if(!(CONDITION)) { (void)Det_ReportError( SD_MODULE_ID, SD_INSTANCE_ID, (API_ID), (ERROR_CODE)); return (RET_VAL); } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Sd_CheckDetErrorContinue(    CONDITION, API_ID, ERROR_CODE )          { if(!(CONDITION)) { (void)Det_ReportError( SD_MODULE_ID, SD_INSTANCE_ID, (API_ID), (ERROR_CODE)); } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Sd_CallDetReportError( API_ID, ERROR_CODE )                           (void)Det_ReportError( SD_MODULE_ID, SD_INSTANCE_ID, (API_ID), (ERROR_CODE))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
# define Sd_CheckDetErrorReturnVoid(  CONDITION, API_ID, ERROR_CODE )          { if(!(CONDITION)) { return; } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Sd_CheckDetErrorReturnValue( CONDITION, API_ID, ERROR_CODE, RET_VAL ) { if(!(CONDITION)) { return (RET_VAL); } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Sd_CheckDetErrorContinue(    CONDITION, API_ID, ERROR_CODE )
# define Sd_CallDetReportError( API_ID, ERROR_CODE )
#endif /* SD_DEV_ERROR_DETECT */

/* Diagnostic Event Manager */
#if (STD_ON == SD_DEM_EVENTS_CONFIGURED)
# define Sd_DemMalformedMsg( DEM_ID )          { if(0 != (DEM_ID)) { Dem_ReportErrorStatus((DEM_ID), DEM_EVENT_STATUS_FAILED); } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Sd_DemOutOfRes( DEM_ID )              { if(0 != (DEM_ID)) { Dem_ReportErrorStatus((DEM_ID), DEM_EVENT_STATUS_FAILED); } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
# define Sd_DemNackReceived( DEM_ID )          { if(0 != (DEM_ID)) { Dem_ReportErrorStatus((DEM_ID), DEM_EVENT_STATUS_FAILED); } }  /* PRQA S 3458 */ /* MD_MSR_19.4 */
#else
# define Sd_DemMalformedMsg( DEM_ID )
# define Sd_DemOutOfRes( DEM_ID )
# define Sd_DemNackReceived( DEM_ID )
#endif /* SD_DEM_EVENTS_CONFIGURED */

/* PRQA L:FCT_MACROS */
/* PRQA L:BRACED_MACROS */

#endif  /* SD_PRIV_H */

/**********************************************************************************************************************
 *  END OF FILE: Sd_Priv.h
 *********************************************************************************************************************/
