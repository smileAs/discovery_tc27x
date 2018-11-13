/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: LinIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: LinIf_Lcfg.c
 *   Generation Time: 2018-11-06 14:01:58
 *           Project: discovery_ecu - Version 1.0
 *          Delivery: CBD1800319_D00
 *      Tool Version: DaVinci Configurator (beta) 5.15.11 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* Disable the following MISRA warnings because they would appear too often for individual suppression. */

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/**********************************************************************************************************************
 *  Includes
 *********************************************************************************************************************/

#include "LinIf.h"
#include "PduR_LinIf.h"
/*
 * [LINIF556]
 */
#include "LinSM_Cbk.h"


/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  LinIf_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    LinIf_ChannelConfig
  \details
  Element                         Description
  FrameLengthDelayListEndIdx      the end index of the 0:n relation pointing to LinIf_FrameLengthDelayList
  FrameLengthDelayListStartIdx    the start index of the 0:n relation pointing to LinIf_FrameLengthDelayList
  FrameListEndIdx                 the end index of the 1:n relation pointing to LinIf_FrameList
  FrameListStartIdx               the start index of the 1:n relation pointing to LinIf_FrameList
  ScheduleTableListIndEndIdx      the end index of the 1:n relation pointing to LinIf_ScheduleTableListInd
  ScheduleTableListIndStartIdx    the start index of the 1:n relation pointing to LinIf_ScheduleTableListInd
  ScheduleChangeBeforeSlotEnd     Point of schedule table change. True = after maximum frame time, False = at end of schedule slot.
  ChannelFuncCallCycle            Channel function call cycle
  LoadBalancingOffset             Load balancing offset in ticks
  StartupState                    Startup state of channel: 0 : sleep  1 : operational state
  TimeBase                        Channel time base
  WakeupDelayExternal             External wakeup delay in ticks
  WakeupDelayInternal             Internal wakeup delay in ticks
  NumberOfSchedules               Number of schedule tables
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(LinIf_ChannelConfigType, LINIF_CONST) LinIf_ChannelConfig[1] = {
    /* Index    FrameLengthDelayListEndIdx  FrameLengthDelayListStartIdx  FrameListEndIdx  FrameListStartIdx  ScheduleTableListIndEndIdx  ScheduleTableListIndStartIdx  ScheduleChangeBeforeSlotEnd  ChannelFuncCallCycle  LoadBalancingOffset  StartupState  TimeBase  WakeupDelayExternal  WakeupDelayInternal  NumberOfSchedules */
  { /*     0 */                         8U,                           0U,              4U,                0U,                         2U,                           0U,                       FALSE,                   1U,                  1U,           1U,       5U,                 20U,                 20U,               1UL }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ChannelIndTable
**********************************************************************************************************************/
/** 
  \var    LinIf_ChannelIndTable
  \details
  Element               Description
  LinChannelIndex   
  SystemChannelIndex
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(LinIf_ChannelIndTableType, LINIF_CONST) LinIf_ChannelIndTable[1] = {
    /* Index    LinChannelIndex                            SystemChannelIndex                          */
  { /*     0 */ 0 /* LinConf_LinChannel_LIN00_f26020e5 */, 3 /* ComMConf_ComMChannel_LIN00_f26020e5 */ }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ChannelToDrvWakeupInfo
**********************************************************************************************************************/
/** 
  \var    LinIf_ChannelToDrvWakeupInfo
  \details
  Element            Description
  LinWakeupSource    Defines the ID of the wakeup source. Zero means invalid source and that external wakeup is not supported.
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(LinIf_ChannelToDrvWakeupInfoType, LINIF_CONST) LinIf_ChannelToDrvWakeupInfo[1] = {
    /* Index    LinWakeupSource */
  { /*     0 */    0x00000100UL }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_Entry
**********************************************************************************************************************/
/** 
  \var    LinIf_Entry
  \details
  Element                 Description
  FrameListIdx            the index of the 1:1 relation pointing to LinIf_FrameList
  DelayInTimebaseTicks
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(LinIf_EntryType, LINIF_CONST) LinIf_Entry[4] = {
    /* Index    FrameListIdx  DelayInTimebaseTicks        Comment                    Referable Keys */
  { /*     0 */           0U,                   1U },  /* [FT_Init_SRU3] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5/Normal_45618847] */
  { /*     1 */           1U,                  10U },  /* [FT_Init_LRU1] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5/Normal_45618847] */
  { /*     2 */           2U,                   4U },  /* [FT_Read_SRU3] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5/Normal_45618847] */
  { /*     3 */           3U,                  10U }   /* [FT_Read_LRU1] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5/Normal_45618847] */
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_FrameLengthDelayList
**********************************************************************************************************************/
/** 
  \var    LinIf_FrameLengthDelayList
  \details
  Element             Description
  FrameLengthDelay
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(LinIf_FrameLengthDelayListType, LINIF_CONST) LinIf_FrameLengthDelayList[8] = {
    /* Index    FrameLengthDelay        Comment                      Referable Keys */
  { /*     0 */               1U },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
  { /*     1 */               1U },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
  { /*     2 */               2U },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
  { /*     3 */               2U },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
  { /*     4 */               2U },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
  { /*     5 */               2U },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
  { /*     6 */               2U },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
  { /*     7 */               2U }   /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_FrameList
**********************************************************************************************************************/
/** 
  \var    LinIf_FrameList
  \details
  Element         Description
  PduId           Upper layer PduId
  ChecksumType    CLASSIC  ENHANCED  
  Direction       TX  RX  S2S  
  FrameType       UNCONDITIONAL : 0  MRF : 1  SRF : 2  EVENT_TRIGGERED : 4  SPORADIC : 5  ASSIGN : 6  UNASSIGN : 7  ASSIGN_NAD : 8  FREE : 9  CONDITIONAL : 10  ASSIGN_FRAME_ID_RANGE : 11  SAVE_CONFIGURATION : 12  
  Length          Frame length in bytes
  Pid             Protected Identifier
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(LinIf_FrameListType, LINIF_CONST) LinIf_FrameList[4] = {
    /* Index    PduId                                               ChecksumType     Direction            FrameType  Length  Pid          Referable Keys */
  { /*     0 */ PduRConf_PduRDestPdu_DST_Lin_PT_Init_SRU3_45618847, LIN_ENHANCED_CS, LIN_MASTER_RESPONSE,        0U,     2U, 0x80U },  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5, /ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5/FT_Init_SRU3] */
  { /*     1 */ PduRConf_PduRDestPdu_DST_Lin_PT_Init_LRU1_45618847, LIN_ENHANCED_CS, LIN_MASTER_RESPONSE,        0U,     1U, 0xC1U },  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5, /ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5/FT_Init_LRU1] */
  { /*     2 */ PduRConf_PduRSrcPdu_SRC_Lin_PT_Read_SRU3_45618847 , LIN_ENHANCED_CS, LIN_SLAVE_RESPONSE ,        0U,     3U, 0x0DU },  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5, /ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5/FT_Read_SRU3] */
  { /*     3 */ PduRConf_PduRSrcPdu_SRC_Lin_PT_Read_LRU1_45618847 , LIN_ENHANCED_CS, LIN_SLAVE_RESPONSE ,        0U,     8U, 0x1FU }   /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5, /ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5/FT_Read_LRU1] */
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ScheduleTableList
**********************************************************************************************************************/
/** 
  \var    LinIf_ScheduleTableList
  \details
  Element                    Description
  EntryEndIdx                the end index of the 0:n relation pointing to LinIf_Entry
  EntryStartIdx              the start index of the 0:n relation pointing to LinIf_Entry
  NumberOfScheduleEntries    number of entries
  ResumePosition             CONTINUE_AT_IT_POINT : 0  START_FROM_BEGINNING : 1  
  RunMode                    RUN_CONTINUOUS : 0  RUN_ONCE : 1  
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(LinIf_ScheduleTableListType, LINIF_CONST) LinIf_ScheduleTableList[2] = {
    /* Index    EntryEndIdx                              EntryStartIdx                              NumberOfScheduleEntries  ResumePosition  RunMode        Comment                       Referable Keys */
  { /*     0 */ LINIF_NO_ENTRYENDIDXOFSCHEDULETABLELIST, LINIF_NO_ENTRYSTARTIDXOFSCHEDULETABLELIST,                   0x00U,          0x00U,   0x00U },  /* [NULLSchedule]    */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
  { /*     1 */                                      4U,                                        0U,                   0x04U,          0x01U,   0x00U }   /* [Normal_45618847] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ScheduleTableListInd
**********************************************************************************************************************/
/** 
  \var    LinIf_ScheduleTableListInd
  \brief  the indexes of the 1:1 sorted relation pointing to LinIf_ScheduleTableList
*/ 
#define LINIF_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(LinIf_ScheduleTableListIndType, LINIF_CONST) LinIf_ScheduleTableListInd[2] = {
  /* Index     ScheduleTableListInd      Referable Keys */
  /*     0 */                    0U,  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
  /*     1 */                    1U   /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/LIN00_f26020e5] */
};
#define LINIF_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_SystemToLinIfChannel
**********************************************************************************************************************/
/** 
  \var    LinIf_SystemToLinIfChannel
  \details
  Element              Description
  LinIfChannelIndex
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(LinIf_SystemToLinIfChannelType, LINIF_CONST) LinIf_SystemToLinIfChannel[4] = {
    /* Index    LinIfChannelIndex                                                                     */
  { /*     0 */                                                     255U /* 0xFF -> No Lin channel */ },
  { /*     1 */                                                     255U /* 0xFF -> No Lin channel */ },
  { /*     2 */                                                     255U /* 0xFF -> No Lin channel */ },
  { /*     3 */ 0U /* ComMConf_ComMChannel_LIN00_f26020e5 -> LinIfConf_LinIfChannel_LIN00_f26020e5 */ }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ChannelData
**********************************************************************************************************************/
#define LINIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(LinIf_ChannelDataType, LINIF_VAR_NOINIT) LinIf_ChannelData[1];  /* Data structure per LinIf channel */
#define LINIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/






