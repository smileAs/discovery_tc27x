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
 *            Module: BswM
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Lcfg.c
 *   Generation Time: 2018-11-06 14:02:00
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

#define BSWM_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "SchM_BswM.h"

#if !defined (BSWM_LOCAL)
# define BSWM_LOCAL static
#endif

#if !defined (BSWM_LOCAL_INLINE) /* COV_BSWM_LOCAL_INLINE */
# define BSWM_LOCAL_INLINE LOCAL_INLINE
#endif



#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ LOCAL FUNCTION DECLARATIONS
 ----------------------------------------------------------------------------- */
/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
/*!
 * \brief       Executes a rule.
 * \details     Arbitrates a rule and executes corresponding action list.
 * \param[in]   handleId  Id of the rule to execute.
 * \return      E_OK      No action list was executed or corresponding action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId);

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
/*!
 * \brief       Updates the state of a rule.
 * \details     Set rule state of passed ruleId to passed state.
 * \param[in]   ruleId    Id of the rule to update.
 * \param[in]   state     New state of the rule.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, BswM_RuleStatesType state);

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
/*!
 * \brief       Updates a timer.
 * \details     Set timer value of passed timerId to passed value and calculates the new state.
 * \param[in]   timerId   Id of the timer to update.
 * \param[in]   value     New value of the timer.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_SizeOfTimerValueType timerId, BswM_TimerValueType value);

/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_BswM_0779 */

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionListFunctions
 * \{
 */

/*!
 * \{
 * \brief       Execute actions of action list.
 * \details     Generated function which depends on the configuration. Executes the actions of the action list in the
 *              configured order.
 * \return      E_OK      Action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_RunToPostRun(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMToShutdown(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToPrep(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMWakeup(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToRun(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitPostRun(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_TX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_TX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_Disable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_Enable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_RX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_TX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_TX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_Disable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_Enable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_RX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_TX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_TX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_Disable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_Enable_DM(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_RX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Enable(void);
/*! \} */ /* End of sharing description for BswMActionListFunctions */
#define BswM_ActionList_ESH_AL_PostRunToPrepShutdown BswM_ActionList_ESH_AL_WakeupToPrep
#define BswM_ActionList_ESH_AL_InitToWakeup BswM_ActionList_ESH_AL_WaitForNvMWakeup
#define BswM_ActionList_ESH_AL_PostRunToRun BswM_ActionList_ESH_AL_WakeupToRun
/*! \} */ /* End of group BswMActionListFunctions */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMRuleFunctions
 * \{
 */

/*!
 * \{
 * \brief       Arbitrates the configured rule.
 * \details     Generated function which depends on the configuration. Arbitrates the rule and returns the action list
 *              which shall be executed.
 * \return      ID of action list to execute (BSWM_NO_ACTIONLIST if no ActionList shall be executed)
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRun(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToShutdown(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToPrep(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToWakeup(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToRun(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_InitToWakeup(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunToPrepNested(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunNested(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRun(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PrepToWait(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN00_f26020e5_TX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN00_f26020e5_RX_DM(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN00_f26020e5_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN01_f26020e5_TX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN01_f26020e5_RX_DM(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN01_f26020e5_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN02_f26020e5_TX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN02_f26020e5_RX_DM(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN02_f26020e5_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_LIN00_f26020e5_Normal_45618847(void);
/*! \} */ /* End of sharing description for BswMRuleFunctions */
/*! \} */ /* End of group BswMRuleFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */

#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ LOCAL VARIABLE DECLARATIONS
 ----------------------------------------------------------------------------- */

/* PRQA S 0779 VARIABLEDECLARATIONS */ /* MD_BswM_0779 */ 

#define BSWM_START_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


BSWM_LOCAL VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NOINIT) BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;

BSWM_LOCAL VAR(BswM_ESH_RunRequest, BSWM_VAR_NOINIT) Request_ESH_RunRequest_0_requestedMode;
BSWM_LOCAL VAR(BswM_ESH_RunRequest, BSWM_VAR_NOINIT) Request_ESH_RunRequest_1_requestedMode;
BSWM_LOCAL VAR(BswM_ESH_RunRequest, BSWM_VAR_NOINIT) Request_ESH_PostRunRequest_0_requestedMode;
BSWM_LOCAL VAR(BswM_ESH_RunRequest, BSWM_VAR_NOINIT) Request_ESH_PostRunRequest_1_requestedMode;
BSWM_LOCAL VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NOINIT) BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode;



#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* PRQA L:VARIABLEDECLARATIONS */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/* PRQA S 0310 GLOBALDATADECLARATIONS */ /* MD_BswM_0310 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionLists
**********************************************************************************************************************/
/** 
  \var    BswM_ActionLists
  \details
  Element    Description
  FctPtr     Pointer to the array list function.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionLists[32] = {
    /* Index    FctPtr                                                              Comment                   Referable Keys */
  { /*     0 */ BswM_ActionList_ESH_AL_RunToPostRun                          },  /* [Priority: 0] */  /* [AL_ESH_AL_RunToPostRun] */
  { /*     1 */ BswM_ActionList_ESH_AL_WaitForNvMToShutdown                  },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  { /*     2 */ BswM_ActionList_ESH_AL_WakeupToPrep                          },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToPrep] */
  { /*     3 */ BswM_ActionList_ESH_AL_WaitForNvMWakeup                      },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*     4 */ BswM_ActionList_ESH_AL_WakeupToRun                           },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToRun] */
  { /*     5 */ BswM_ActionList_ESH_AL_InitToWakeup                          },  /* [Priority: 0] */  /* [AL_ESH_AL_InitToWakeup] */
  { /*     6 */ BswM_ActionList_ESH_AL_PostRunToPrepShutdown                 },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*     7 */ BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck                },  /* [Priority: 0] */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  { /*     8 */ BswM_ActionList_ESH_AL_PostRunToRun                          },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToRun] */
  { /*     9 */ BswM_ActionList_ESH_AL_ExitPostRun                           },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitPostRun] */
  { /*    10 */ BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM              },  /* [Priority: 0] */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    11 */ BswM_ActionList_INIT_AL_Initialize                           },  /* [Priority: 0] */  /* [AL_INIT_AL_Initialize] */
  { /*    12 */ BswM_ActionList_CC_AL_CAN00_f26020e5_TX_Disable              },  /* [Priority: 0] */  /* [AL_CC_AL_CAN00_f26020e5_TX_Disable] */
  { /*    13 */ BswM_ActionList_CC_AL_CAN00_f26020e5_TX_EnableNoinit         },  /* [Priority: 0] */  /* [AL_CC_AL_CAN00_f26020e5_TX_EnableNoinit] */
  { /*    14 */ BswM_ActionList_CC_AL_CAN00_f26020e5_Disable_DM              },  /* [Priority: 0] */  /* [AL_CC_AL_CAN00_f26020e5_Disable_DM] */
  { /*    15 */ BswM_ActionList_CC_AL_CAN00_f26020e5_Enable_DM               },  /* [Priority: 0] */  /* [AL_CC_AL_CAN00_f26020e5_Enable_DM] */
  { /*    16 */ BswM_ActionList_CC_AL_CAN00_f26020e5_RX_Disable              },  /* [Priority: 0] */  /* [AL_CC_AL_CAN00_f26020e5_RX_Disable] */
  { /*    17 */ BswM_ActionList_CC_AL_CAN00_f26020e5_RX_EnableNoinit         },  /* [Priority: 0] */  /* [AL_CC_AL_CAN00_f26020e5_RX_EnableNoinit] */
  { /*    18 */ BswM_ActionList_CC_AL_CAN01_f26020e5_TX_Disable              },  /* [Priority: 0] */  /* [AL_CC_AL_CAN01_f26020e5_TX_Disable] */
  { /*    19 */ BswM_ActionList_CC_AL_CAN01_f26020e5_TX_EnableNoinit         },  /* [Priority: 0] */  /* [AL_CC_AL_CAN01_f26020e5_TX_EnableNoinit] */
  { /*    20 */ BswM_ActionList_CC_AL_CAN01_f26020e5_Disable_DM              },  /* [Priority: 0] */  /* [AL_CC_AL_CAN01_f26020e5_Disable_DM] */
  { /*    21 */ BswM_ActionList_CC_AL_CAN01_f26020e5_Enable_DM               },  /* [Priority: 0] */  /* [AL_CC_AL_CAN01_f26020e5_Enable_DM] */
  { /*    22 */ BswM_ActionList_CC_AL_CAN01_f26020e5_RX_Disable              },  /* [Priority: 0] */  /* [AL_CC_AL_CAN01_f26020e5_RX_Disable] */
  { /*    23 */ BswM_ActionList_CC_AL_CAN01_f26020e5_RX_EnableNoinit         },  /* [Priority: 0] */  /* [AL_CC_AL_CAN01_f26020e5_RX_EnableNoinit] */
  { /*    24 */ BswM_ActionList_CC_AL_CAN02_f26020e5_TX_Disable              },  /* [Priority: 0] */  /* [AL_CC_AL_CAN02_f26020e5_TX_Disable] */
  { /*    25 */ BswM_ActionList_CC_AL_CAN02_f26020e5_TX_EnableNoinit         },  /* [Priority: 0] */  /* [AL_CC_AL_CAN02_f26020e5_TX_EnableNoinit] */
  { /*    26 */ BswM_ActionList_CC_AL_CAN02_f26020e5_Disable_DM              },  /* [Priority: 0] */  /* [AL_CC_AL_CAN02_f26020e5_Disable_DM] */
  { /*    27 */ BswM_ActionList_CC_AL_CAN02_f26020e5_Enable_DM               },  /* [Priority: 0] */  /* [AL_CC_AL_CAN02_f26020e5_Enable_DM] */
  { /*    28 */ BswM_ActionList_CC_AL_CAN02_f26020e5_RX_Disable              },  /* [Priority: 0] */  /* [AL_CC_AL_CAN02_f26020e5_RX_Disable] */
  { /*    29 */ BswM_ActionList_CC_AL_CAN02_f26020e5_RX_EnableNoinit         },  /* [Priority: 0] */  /* [AL_CC_AL_CAN02_f26020e5_RX_EnableNoinit] */
  { /*    30 */ BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Disable },  /* [Priority: 0] */  /* [AL_CC_AL_LIN00_f26020e5_Normal_45618847_Disable] */
  { /*    31 */ BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Enable  }   /* [Priority: 0] */  /* [AL_CC_AL_LIN00_f26020e5_Normal_45618847_Enable] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelMapping
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelMapping
  \brief  Maps the external id of BswMCanSMIndication to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMCanSMIndication.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_CanSMChannelMappingType, BSWM_CONST) BswM_CanSMChannelMapping[3] = {
    /* Index    ExternalId                           ImmediateUserEndIdx  ImmediateUserStartIdx        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_CAN00_f26020e5,                  1U,                    0U },  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CAN00_f26020e5] */
  { /*     1 */ ComMConf_ComMChannel_CAN01_f26020e5,                  2U,                    1U },  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CAN01_f26020e5] */
  { /*     2 */ ComMConf_ComMChannel_CAN02_f26020e5,                  3U,                    2U }   /* [CANSM_CHANNEL_2, MRP_CC_CanSMIndication_CAN02_f26020e5] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DeferredRules
**********************************************************************************************************************/
/** 
  \var    BswM_DeferredRules
  \details
  Element     Description
  RulesIdx    the index of the 1:1 relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRules[7] = {
    /* Index    RulesIdx        Referable Keys */
  { /*     0 */       0U },  /* [R_ESH_RunToPostRun] */
  { /*     1 */       1U },  /* [R_ESH_WaitToShutdown] */
  { /*     2 */       2U },  /* [R_ESH_WakeupToPrep] */
  { /*     3 */       3U },  /* [R_ESH_WaitToWakeup] */
  { /*     4 */       4U },  /* [R_ESH_WakeupToRun] */
  { /*     5 */       8U },  /* [R_ESH_PostRun] */
  { /*     6 */       9U }   /* [R_ESH_PrepToWait] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ImmediateUser
**********************************************************************************************************************/
/** 
  \var    BswM_ImmediateUser
  \brief  Contains all immediate request ports.
  \details
  Element             Description
  MaskedBits          contains bitcoded the boolean data of BswM_OnInitOfImmediateUser, BswM_RulesIndUsedOfImmediateUser
  RulesIndEndIdx      the end index of the 0:n relation pointing to BswM_RulesInd
  RulesIndStartIdx    the start index of the 0:n relation pointing to BswM_RulesInd
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[6] = {
    /* Index    MaskedBits  RulesIndEndIdx  RulesIndStartIdx        Comment                                                                     Referable Keys */
  { /*     0 */      0x01U,             3U,               0U },  /* [Name: CC_CanSMIndication_CAN00_f26020e5]                       */  /* [MRP_CC_CanSMIndication_CAN00_f26020e5, CANSM_CHANNEL_0] */
  { /*     1 */      0x01U,             6U,               3U },  /* [Name: CC_CanSMIndication_CAN01_f26020e5]                       */  /* [MRP_CC_CanSMIndication_CAN01_f26020e5, CANSM_CHANNEL_1] */
  { /*     2 */      0x01U,             9U,               6U },  /* [Name: CC_CanSMIndication_CAN02_f26020e5]                       */  /* [MRP_CC_CanSMIndication_CAN02_f26020e5, CANSM_CHANNEL_2] */
  { /*     3 */      0x03U,            17U,               9U },  /* [Name: ESH_State]                                               */  /* [MRP_ESH_State, GENERIC_0] */
  { /*     4 */      0x01U,            18U,              17U },  /* [Name: CC_LinScheduleIndication_LIN00_f26020e5_Normal_45618847] */  /* [MRP_CC_LinScheduleIndication_LIN00_f26020e5_Normal_45618847, LIN_SCHEDULE_0] */
  { /*     5 */      0x01U,            19U,              18U }   /* [Name: CC_LinSMIndication_LIN00_f26020e5]                       */  /* [MRP_CC_LinSMIndication_LIN00_f26020e5, LINSM_CHANNEL_0] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Rules
**********************************************************************************************************************/
/** 
  \var    BswM_Rules
  \details
  Element    Description
  Id         External id of rule.
  FctPtr     Pointer to the rule function which does the arbitration.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_Rules[20] = {
    /* Index    Id   FctPtr                                             Referable Keys */
  { /*     0 */ 15U, BswM_Rule_ESH_RunToPostRun                  },  /* [R_ESH_RunToPostRun, MRP_ESH_State, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1, MRP_ESH_SelfRunRequestTimer, MRP_ESH_ModeNotification] */
  { /*     1 */ 16U, BswM_Rule_ESH_WaitToShutdown                },  /* [R_ESH_WaitToShutdown, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents] */
  { /*     2 */ 18U, BswM_Rule_ESH_WakeupToPrep                  },  /* [R_ESH_WakeupToPrep, MRP_ESH_State, MRP_ESH_EcuM_GetPendingWakeupEvents, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ModeNotification] */
  { /*     3 */ 17U, BswM_Rule_ESH_WaitToWakeup                  },  /* [R_ESH_WaitToWakeup, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents] */
  { /*     4 */ 19U, BswM_Rule_ESH_WakeupToRun                   },  /* [R_ESH_WakeupToRun, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ModeNotification] */
  { /*     5 */ 10U, BswM_Rule_ESH_InitToWakeup                  },  /* [R_ESH_InitToWakeup, MRP_ESH_State] */
  { /*     6 */ 13U, BswM_Rule_ESH_PostRunToPrepNested           },  /* [R_ESH_PostRunToPrepNested] */
  { /*     7 */ 12U, BswM_Rule_ESH_PostRunNested                 },  /* [R_ESH_PostRunNested] */
  { /*     8 */ 11U, BswM_Rule_ESH_PostRun                       },  /* [R_ESH_PostRun, MRP_ESH_State, MRP_ESH_ModeNotification] */
  { /*     9 */ 14U, BswM_Rule_ESH_PrepToWait                    },  /* [R_ESH_PrepToWait, MRP_ESH_State, MRP_ESH_ModeNotification] */
  { /*    10 */  2U, BswM_Rule_CC_CAN00_f26020e5_TX              },  /* [R_CC_CAN00_f26020e5_TX, MRP_CC_CanSMIndication_CAN00_f26020e5] */
  { /*    11 */  1U, BswM_Rule_CC_CAN00_f26020e5_RX_DM           },  /* [R_CC_CAN00_f26020e5_RX_DM, MRP_CC_CanSMIndication_CAN00_f26020e5] */
  { /*    12 */  0U, BswM_Rule_CC_CAN00_f26020e5_RX              },  /* [R_CC_CAN00_f26020e5_RX, MRP_CC_CanSMIndication_CAN00_f26020e5] */
  { /*    13 */  5U, BswM_Rule_CC_CAN01_f26020e5_TX              },  /* [R_CC_CAN01_f26020e5_TX, MRP_CC_CanSMIndication_CAN01_f26020e5] */
  { /*    14 */  4U, BswM_Rule_CC_CAN01_f26020e5_RX_DM           },  /* [R_CC_CAN01_f26020e5_RX_DM, MRP_CC_CanSMIndication_CAN01_f26020e5] */
  { /*    15 */  3U, BswM_Rule_CC_CAN01_f26020e5_RX              },  /* [R_CC_CAN01_f26020e5_RX, MRP_CC_CanSMIndication_CAN01_f26020e5] */
  { /*    16 */  8U, BswM_Rule_CC_CAN02_f26020e5_TX              },  /* [R_CC_CAN02_f26020e5_TX, MRP_CC_CanSMIndication_CAN02_f26020e5] */
  { /*    17 */  7U, BswM_Rule_CC_CAN02_f26020e5_RX_DM           },  /* [R_CC_CAN02_f26020e5_RX_DM, MRP_CC_CanSMIndication_CAN02_f26020e5] */
  { /*    18 */  6U, BswM_Rule_CC_CAN02_f26020e5_RX              },  /* [R_CC_CAN02_f26020e5_RX, MRP_CC_CanSMIndication_CAN02_f26020e5] */
  { /*    19 */  9U, BswM_Rule_CC_LIN00_f26020e5_Normal_45618847 }   /* [R_CC_LIN00_f26020e5_Normal_45618847, MRP_CC_LinSMIndication_LIN00_f26020e5, MRP_CC_LinScheduleIndication_LIN00_f26020e5_Normal_45618847] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesInd
**********************************************************************************************************************/
/** 
  \var    BswM_RulesInd
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesInd[19] = {
  /* Index    RulesInd      Referable Keys */
  /*     0 */      10U,  /* [MRP_CC_CanSMIndication_CAN00_f26020e5] */
  /*     1 */      11U,  /* [MRP_CC_CanSMIndication_CAN00_f26020e5] */
  /*     2 */      12U,  /* [MRP_CC_CanSMIndication_CAN00_f26020e5] */
  /*     3 */      13U,  /* [MRP_CC_CanSMIndication_CAN01_f26020e5] */
  /*     4 */      14U,  /* [MRP_CC_CanSMIndication_CAN01_f26020e5] */
  /*     5 */      15U,  /* [MRP_CC_CanSMIndication_CAN01_f26020e5] */
  /*     6 */      16U,  /* [MRP_CC_CanSMIndication_CAN02_f26020e5] */
  /*     7 */      17U,  /* [MRP_CC_CanSMIndication_CAN02_f26020e5] */
  /*     8 */      18U,  /* [MRP_CC_CanSMIndication_CAN02_f26020e5] */
  /*     9 */       0U,  /* [MRP_ESH_State] */
  /*    10 */       1U,  /* [MRP_ESH_State] */
  /*    11 */       2U,  /* [MRP_ESH_State] */
  /*    12 */       3U,  /* [MRP_ESH_State] */
  /*    13 */       4U,  /* [MRP_ESH_State] */
  /*    14 */       5U,  /* [MRP_ESH_State] */
  /*    15 */       8U,  /* [MRP_ESH_State] */
  /*    16 */       9U,  /* [MRP_ESH_State] */
  /*    17 */      19U,  /* [MRP_CC_LinScheduleIndication_LIN00_f26020e5_Normal_45618847] */
  /*    18 */      19U   /* [MRP_CC_LinSMIndication_LIN00_f26020e5] */
};
#define BSWM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_ActionListQueueType, BSWM_VAR_NOINIT) BswM_ActionListQueue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [AL_ESH_AL_RunToPostRun] */
  /*     1 */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  /*     2 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*     3 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*     4 */  /* [AL_ESH_AL_WakeupToRun] */
  /*     5 */  /* [AL_ESH_AL_InitToWakeup] */
  /*     6 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*     7 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*     8 */  /* [AL_ESH_AL_PostRunToRun] */
  /*     9 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    10 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    11 */  /* [AL_INIT_AL_Initialize] */
  /*    12 */  /* [AL_CC_AL_CAN00_f26020e5_TX_Disable] */
  /*    13 */  /* [AL_CC_AL_CAN00_f26020e5_TX_EnableNoinit] */
  /*    14 */  /* [AL_CC_AL_CAN00_f26020e5_Disable_DM] */
  /*    15 */  /* [AL_CC_AL_CAN00_f26020e5_Enable_DM] */
  /*    16 */  /* [AL_CC_AL_CAN00_f26020e5_RX_Disable] */
  /*    17 */  /* [AL_CC_AL_CAN00_f26020e5_RX_EnableNoinit] */
  /*    18 */  /* [AL_CC_AL_CAN01_f26020e5_TX_Disable] */
  /*    19 */  /* [AL_CC_AL_CAN01_f26020e5_TX_EnableNoinit] */
  /*    20 */  /* [AL_CC_AL_CAN01_f26020e5_Disable_DM] */
  /*    21 */  /* [AL_CC_AL_CAN01_f26020e5_Enable_DM] */
  /*    22 */  /* [AL_CC_AL_CAN01_f26020e5_RX_Disable] */
  /*    23 */  /* [AL_CC_AL_CAN01_f26020e5_RX_EnableNoinit] */
  /*    24 */  /* [AL_CC_AL_CAN02_f26020e5_TX_Disable] */
  /*    25 */  /* [AL_CC_AL_CAN02_f26020e5_TX_EnableNoinit] */
  /*    26 */  /* [AL_CC_AL_CAN02_f26020e5_Disable_DM] */
  /*    27 */  /* [AL_CC_AL_CAN02_f26020e5_Enable_DM] */
  /*    28 */  /* [AL_CC_AL_CAN02_f26020e5_RX_Disable] */
  /*    29 */  /* [AL_CC_AL_CAN02_f26020e5_RX_EnableNoinit] */
  /*    30 */  /* [AL_CC_AL_LIN00_f26020e5_Normal_45618847_Disable] */
  /*    31 */  /* [AL_CC_AL_LIN00_f26020e5_Normal_45618847_Enable] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelState
  \brief  Variable to store current mode of BswMCanSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanSM_BswMCurrentStateType, BSWM_VAR_NOINIT) BswM_CanSMChannelState[3];
  /* Index        Referable Keys  */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_CAN00_f26020e5] */
  /*     1 */  /* [CANSM_CHANNEL_1, MRP_CC_CanSMIndication_CAN01_f26020e5] */
  /*     2 */  /* [CANSM_CHANNEL_2, MRP_CC_CanSMIndication_CAN02_f26020e5] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericState
**********************************************************************************************************************/
/** 
  \var    BswM_GenericState
  \brief  Variable to store current mode of BswMGenericRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_ModeType, BSWM_VAR_NOINIT) BswM_GenericState[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [GENERIC_0, MRP_ESH_State] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_InitializedType, BSWM_VAR_ZERO_INIT) BswM_Initialized = FALSE;
#define BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_LinSMState
**********************************************************************************************************************/
/** 
  \var    BswM_LinSMState
  \brief  Variable to store current mode of BswMLinSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(LinSM_ModeType, BSWM_VAR_NOINIT) BswM_LinSMState[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [LINSM_CHANNEL_0, MRP_CC_LinSMIndication_LIN00_f26020e5] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_LinScheduleState
**********************************************************************************************************************/
/** 
  \var    BswM_LinScheduleState
  \brief  Variable to store current mode of BswMLinScheduleIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(LinIf_SchHandleType, BSWM_VAR_NOINIT) BswM_LinScheduleState[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [LIN_SCHEDULE_0, MRP_CC_LinScheduleIndication_LIN00_f26020e5_Normal_45618847] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_ModeRequestQueueType, BSWM_VAR_NOINIT) BswM_ModeRequestQueue[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_CC_CanSMIndication_CAN00_f26020e5, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_CC_CanSMIndication_CAN01_f26020e5, CANSM_CHANNEL_1] */
  /*     2 */  /* [MRP_CC_CanSMIndication_CAN02_f26020e5, CANSM_CHANNEL_2] */
  /*     3 */  /* [MRP_ESH_State, GENERIC_0] */
  /*     4 */  /* [MRP_CC_LinScheduleIndication_LIN00_f26020e5_Normal_45618847, LIN_SCHEDULE_0] */
  /*     5 */  /* [MRP_CC_LinSMIndication_LIN00_f26020e5, LINSM_CHANNEL_0] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_RuleStatesType, BSWM_VAR_NOINIT) BswM_RuleStates[20];
  /* Index        Referable Keys  */
  /*     0 */  /* [R_ESH_RunToPostRun, MRP_ESH_State, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1, MRP_ESH_SelfRunRequestTimer, MRP_ESH_ModeNotification] */
  /*     1 */  /* [R_ESH_WaitToShutdown, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents] */
  /*     2 */  /* [R_ESH_WakeupToPrep, MRP_ESH_State, MRP_ESH_EcuM_GetPendingWakeupEvents, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ModeNotification] */
  /*     3 */  /* [R_ESH_WaitToWakeup, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents] */
  /*     4 */  /* [R_ESH_WakeupToRun, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ModeNotification] */
  /*     5 */  /* [R_ESH_InitToWakeup, MRP_ESH_State] */
  /*     6 */  /* [R_ESH_PostRunToPrepNested] */
  /*     7 */  /* [R_ESH_PostRunNested] */
  /*     8 */  /* [R_ESH_PostRun, MRP_ESH_State, MRP_ESH_ModeNotification] */
  /*     9 */  /* [R_ESH_PrepToWait, MRP_ESH_State, MRP_ESH_ModeNotification] */
  /*    10 */  /* [R_CC_CAN00_f26020e5_TX, MRP_CC_CanSMIndication_CAN00_f26020e5] */
  /*    11 */  /* [R_CC_CAN00_f26020e5_RX_DM, MRP_CC_CanSMIndication_CAN00_f26020e5] */
  /*    12 */  /* [R_CC_CAN00_f26020e5_RX, MRP_CC_CanSMIndication_CAN00_f26020e5] */
  /*    13 */  /* [R_CC_CAN01_f26020e5_TX, MRP_CC_CanSMIndication_CAN01_f26020e5] */
  /*    14 */  /* [R_CC_CAN01_f26020e5_RX_DM, MRP_CC_CanSMIndication_CAN01_f26020e5] */
  /*    15 */  /* [R_CC_CAN01_f26020e5_RX, MRP_CC_CanSMIndication_CAN01_f26020e5] */
  /*    16 */  /* [R_CC_CAN02_f26020e5_TX, MRP_CC_CanSMIndication_CAN02_f26020e5] */
  /*    17 */  /* [R_CC_CAN02_f26020e5_RX_DM, MRP_CC_CanSMIndication_CAN02_f26020e5] */
  /*    18 */  /* [R_CC_CAN02_f26020e5_RX, MRP_CC_CanSMIndication_CAN02_f26020e5] */
  /*    19 */  /* [R_CC_LIN00_f26020e5_Normal_45618847, MRP_CC_LinSMIndication_LIN00_f26020e5, MRP_CC_LinScheduleIndication_LIN00_f26020e5_Normal_45618847] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerState
**********************************************************************************************************************/
/** 
  \var    BswM_TimerState
  \brief  Variable to store current state of BswMTimer (STARTED, STOPPER OR EXPIRED).
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_TimerStateType, BSWM_VAR_NOINIT) BswM_TimerState;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerValue
**********************************************************************************************************************/
/** 
  \var    BswM_TimerValue
  \brief  Variable to store current timer values.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_TimerValueType, BSWM_VAR_NOINIT) BswM_TimerValue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/* PRQA L:GLOBALDATADECLARATIONS */


#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ FUNCTIONS
 ----------------------------------------------------------------------------- */

/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId)
{
  BswM_HandleType actionListIndex;
  Std_ReturnType retVal = E_NOT_OK;
  
  if (handleId < BswM_GetSizeOfRules())
  {
    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    actionListIndex = BswM_GetFctPtrOfRules(handleId)(); /* SBSW_BSWM_RULEFCTPTR */
    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(actionListIndex < BswM_GetSizeOfActionLists())
    {
      retVal = BswM_GetFctPtrOfActionLists(actionListIndex)(); /* SBSW_BSWM_ACTIONLISTFCTPTR */
    }
    else
    {
      retVal = E_OK;
    }
  }
  return retVal;
} 

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, BswM_RuleStatesType state)
{
  if (ruleId < BswM_GetSizeOfRuleStates())
  {
    BswM_SetRuleStates(ruleId, state); /* SBSW_BSWM_SETRULESTATE */
  }
}

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_SizeOfTimerValueType timerId, BswM_TimerValueType value)
{
  if (timerId < BswM_GetSizeOfTimerValue())
  {
      SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      BswM_SetTimerValue(timerId, value); /* SBSW_BSWM_SETTIMER */
      BswM_SetTimerState(timerId, (BswM_TimerStateType)((value != 0u) ? BSWM_TIMER_STARTED : BSWM_TIMER_STOPPED)); /* SBSW_BSWM_SETTIMER */
      SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}

/**********************************************************************************************************************
 *  BswM_Init_Gen
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Init_Gen(void)
{

  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFF;
  Request_ESH_RunRequest_0_requestedMode = RELEASED;
  Request_ESH_RunRequest_1_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_0_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_1_requestedMode = RELEASED;
  BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_STARTUP;

  (void)BswM_ActionList_INIT_AL_Initialize();
}

/**********************************************************************************************************************
 *  BswM_ModeNotificationFct
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_ModeNotificationFct(void)
{
  if(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode != 0xFF)
  {
    if(Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode) == RTE_E_OK)
    {
      BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFF;
    }
  }
}

/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct(void)
{
  uint32 mode;
  mode = Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode();
  if (mode != RTE_TRANSITION_ESH_Mode)
  {
    BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = (Rte_ModeType_ESH_Mode)mode;
  }
  (void)Rte_Read_Request_ESH_RunRequest_0_requestedMode(&Request_ESH_RunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_RunRequest_1_requestedMode(&Request_ESH_RunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(&Request_ESH_PostRunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(&Request_ESH_PostRunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
}

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_RunToPostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_RunToPostRun(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  EcuM_ClearValidatedWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
  /*lint -restore */
  BswM_ESH_OnEnterPostRun();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_POSTRUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WaitForNvMToShutdown
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMToShutdown(void)
{
  BswM_ESH_OnEnterShutdown();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WakeupToPrep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToPrep(void)
{
  BswM_ESH_OnEnterPrepShutdown();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_SHUTDOWN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WaitForNvMWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WaitForNvMWakeup(void)
{
  BswM_ESH_OnEnterWakeup();
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_WAKEUP;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_WakeupToRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_WakeupToRun(void)
{
  BswM_UpdateTimer(BSWM_TMR_ESH_SelfRunRequestTimer, 10UL);
  BswM_ESH_OnEnterRun();
  ComM_CommunicationAllowed(ComMConf_ComMUser_USR_CHNL_f276589c, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMUser_USR_CHNL_8571680a, TRUE);
  ComM_CommunicationAllowed(ComMConf_ComMUser_USR_CHNL_1c7839b0, TRUE);
  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_RUN;
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_RUN);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck(void)
{
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_PostRunToPrepNested);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_ExitPostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_ExitPostRun(void)
{
  (void)BswM_Action_RuleHandler(BSWM_ID_RULE_ESH_PostRunNested);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM(void)
{
  BswM_ESH_OnEnterWaitForNvm();
  BswM_RequestMode(BSWM_GENERIC_ESH_State, BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_INIT_AL_Initialize
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(void)
{
  BswM_AL_SetProgrammableInterrupts();
    Can_Init(Can_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Lin_Init(Lin_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  CanIf_Init(CanIf_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  LinIf_Init(LinIf_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Com_Init(Com_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  PduR_Init(PduR_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  CanSM_Init(CanSM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  LinSM_Init(LinSM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  CanTp_Init(CanTp_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  ComM_Init();
  Dcm_Init(NULL_PTR);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN00_f26020e5_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_TX_Disable(void)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_P2P_oCAN00_Tx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN00_f26020e5_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_TX_EnableNoinit(void)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_P2P_oCAN00_Tx_fcef2243, FALSE);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN00_f26020e5_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_Disable_DM(void)
{
  Com_DisableReceptionDM(ComConf_ComIPduGroup_P2P_oCAN00_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN00_f26020e5_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_Enable_DM(void)
{
  Com_EnableReceptionDM(ComConf_ComIPduGroup_P2P_oCAN00_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN00_f26020e5_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_RX_Disable(void)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_P2P_oCAN00_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN00_f26020e5_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN00_f26020e5_RX_EnableNoinit(void)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_P2P_oCAN00_Rx_fcef2243, FALSE);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN01_f26020e5_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_TX_Disable(void)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_P2P_oCAN01_Tx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN01_f26020e5_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_TX_EnableNoinit(void)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_P2P_oCAN01_Tx_fcef2243, FALSE);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN01_f26020e5_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_Disable_DM(void)
{
  Com_DisableReceptionDM(ComConf_ComIPduGroup_P2P_oCAN01_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN01_f26020e5_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_Enable_DM(void)
{
  Com_EnableReceptionDM(ComConf_ComIPduGroup_P2P_oCAN01_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN01_f26020e5_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_RX_Disable(void)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_P2P_oCAN01_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN01_f26020e5_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN01_f26020e5_RX_EnableNoinit(void)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_P2P_oCAN01_Rx_fcef2243, FALSE);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN02_f26020e5_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_TX_Disable(void)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_P2P_oCAN02_Tx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN02_f26020e5_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_TX_EnableNoinit(void)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_P2P_oCAN02_Tx_fcef2243, FALSE);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN02_f26020e5_Disable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_Disable_DM(void)
{
  Com_DisableReceptionDM(ComConf_ComIPduGroup_P2P_oCAN02_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN02_f26020e5_Enable_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_Enable_DM(void)
{
  Com_EnableReceptionDM(ComConf_ComIPduGroup_P2P_oCAN02_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN02_f26020e5_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_RX_Disable(void)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_P2P_oCAN02_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_CAN02_f26020e5_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_CAN02_f26020e5_RX_EnableNoinit(void)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_P2P_oCAN02_Rx_fcef2243, FALSE);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Disable(void)
{
  Com_IpduGroupStop(ComConf_ComIPduGroup_P2P_oLIN00_Tx_fcef2243);
  Com_IpduGroupStop(ComConf_ComIPduGroup_P2P_oLIN00_Rx_fcef2243);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Enable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Enable(void)
{
  Com_IpduGroupStart(ComConf_ComIPduGroup_P2P_oLIN00_Tx_fcef2243, FALSE);
  Com_IpduGroupStart(ComConf_ComIPduGroup_P2P_oLIN00_Rx_fcef2243, FALSE);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Rule_ESH_RunToPostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_RunToPostRun(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_RunToPostRun. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_RUN) && ((Request_ESH_RunRequest_0_requestedMode == RELEASED) && (Request_ESH_RunRequest_1_requestedMode == RELEASED)) && (BswM_GetTimerState(0) == BSWM_TIMER_EXPIRED) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_RUN))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_RunToPostRun. */
    retVal = BSWM_ID_AL_ESH_AL_RunToPostRun;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WaitToShutdown
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToShutdown(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_WaitForNvMToShutdown. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (EcuM_GetValidatedWakeupEvents() == 0u))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WaitForNvMToShutdown. */
    retVal = BSWM_ID_AL_ESH_AL_WaitForNvMToShutdown;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WakeupToPrep
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToPrep(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_WakeupToPrepShutdown. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (EcuM_GetPendingWakeupEvents() == 0u) && (EcuM_GetValidatedWakeupEvents() == 0u) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WakeupToPrep. */
    retVal = BSWM_ID_AL_ESH_AL_WakeupToPrep;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WaitToWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WaitToWakeup(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_WaitForNvMToWakeup. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (EcuM_GetValidatedWakeupEvents() != 0u))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WaitForNvMWakeup. */
    retVal = BSWM_ID_AL_ESH_AL_WaitForNvMWakeup;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_WakeupToRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_WakeupToRun(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_WakeupToRun. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (EcuM_GetValidatedWakeupEvents() != 0u))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_WakeupToRun. */
    retVal = BSWM_ID_AL_ESH_AL_WakeupToRun;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_InitToWakeup
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_InitToWakeup(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_InitToWakeup. */
  if(BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_INIT)
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_InitToWakeup. */
    retVal = BSWM_ID_AL_ESH_AL_InitToWakeup;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PostRunToPrepNested
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunToPrepNested(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_PostRunToPrep. */
  if((Request_ESH_PostRunRequest_0_requestedMode == RELEASED) && (Request_ESH_PostRunRequest_1_requestedMode == RELEASED))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_PostRunToPrepShutdown. */
    retVal = BSWM_ID_AL_ESH_AL_PostRunToPrepShutdown;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PostRunNested
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRunNested(void)
{
  BswM_HandleType retVal;
  /* Evaluate logical expression ESH_LE_RunRequestsOrWakeup. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
  if(((Request_ESH_RunRequest_0_requestedMode == REQUESTED) || (Request_ESH_RunRequest_1_requestedMode == REQUESTED)) || (EcuM_GetValidatedWakeupEvents() != 0u))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_PostRunToRun. */
    retVal = BSWM_ID_AL_ESH_AL_PostRunToRun;
  }
  else
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_ESH_PostRunToPrepCheck. */
    retVal = BSWM_ID_AL_ESH_AL_ESH_PostRunToPrepCheck;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PostRun
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PostRun(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_PostRun. */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_POSTRUN))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_ExitPostRun. */
    retVal = BSWM_ID_AL_ESH_AL_ExitPostRun;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_ESH_PrepToWait
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_ESH_PrepToWait(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression ESH_LE_PrepShutdownToWaitForNvM. */
  if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_SHUTDOWN))
  {
    /* Return conditional action list BswM_ActionList_ESH_AL_PrepShutdownToWaitForNvM. */
    retVal = BSWM_ID_AL_ESH_AL_PrepShutdownToWaitForNvM;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CAN00_f26020e5_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN00_f26020e5_TX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CAN00_f26020e5_TX. */
  if(BswM_GetCanSMChannelState(0) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_TX) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_TX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN00_f26020e5_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CAN00_f26020e5_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_TX) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_TX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN00_f26020e5_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CAN00_f26020e5_TX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CAN00_f26020e5_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN00_f26020e5_RX_DM(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CAN00_f26020e5_RX_DM. */
  if(BswM_GetCanSMChannelState(0) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_RX_DM) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_RX_DM, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN00_f26020e5_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CAN00_f26020e5_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_RX_DM) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_RX_DM, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN00_f26020e5_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CAN00_f26020e5_Disable_DM;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CAN00_f26020e5_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN00_f26020e5_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CAN00_f26020e5_RX. */
  if(BswM_GetCanSMChannelState(0) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_RX) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_RX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN00_f26020e5_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CAN00_f26020e5_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_RX) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN00_f26020e5_RX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN00_f26020e5_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CAN00_f26020e5_RX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CAN01_f26020e5_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN01_f26020e5_TX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CAN01_f26020e5_TX. */
  if(BswM_GetCanSMChannelState(1) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_TX) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_TX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN01_f26020e5_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CAN01_f26020e5_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_TX) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_TX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN01_f26020e5_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CAN01_f26020e5_TX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CAN01_f26020e5_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN01_f26020e5_RX_DM(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CAN01_f26020e5_RX_DM. */
  if(BswM_GetCanSMChannelState(1) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_RX_DM) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_RX_DM, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN01_f26020e5_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CAN01_f26020e5_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_RX_DM) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_RX_DM, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN01_f26020e5_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CAN01_f26020e5_Disable_DM;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CAN01_f26020e5_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN01_f26020e5_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CAN01_f26020e5_RX. */
  if(BswM_GetCanSMChannelState(1) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_RX) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_RX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN01_f26020e5_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CAN01_f26020e5_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_RX) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN01_f26020e5_RX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN01_f26020e5_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CAN01_f26020e5_RX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CAN02_f26020e5_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN02_f26020e5_TX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CAN02_f26020e5_TX. */
  if(BswM_GetCanSMChannelState(2) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_TX) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_TX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN02_f26020e5_TX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CAN02_f26020e5_TX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_TX) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_TX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN02_f26020e5_TX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CAN02_f26020e5_TX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CAN02_f26020e5_RX_DM
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN02_f26020e5_RX_DM(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CAN02_f26020e5_RX_DM. */
  if(BswM_GetCanSMChannelState(2) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_RX_DM) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_RX_DM, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN02_f26020e5_Enable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CAN02_f26020e5_Enable_DM;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_RX_DM) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_RX_DM, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN02_f26020e5_Disable_DM. */
      retVal = BSWM_ID_AL_CC_AL_CAN02_f26020e5_Disable_DM;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_CAN02_f26020e5_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_CAN02_f26020e5_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_CAN02_f26020e5_RX. */
  if(BswM_GetCanSMChannelState(2) != CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_RX) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_RX, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN02_f26020e5_RX_EnableNoinit. */
      retVal = BSWM_ID_AL_CC_AL_CAN02_f26020e5_RX_EnableNoinit;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_RX) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_CAN02_f26020e5_RX, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_CAN02_f26020e5_RX_Disable. */
      retVal = BSWM_ID_AL_CC_AL_CAN02_f26020e5_RX_Disable;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_LIN00_f26020e5_Normal_45618847
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_LIN00_f26020e5_Normal_45618847(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CC_LE_LIN00_f26020e5_Normal_45618847. */
  if((BswM_GetLinSMState(0) == LINSM_BSWM_FULL_COM) && (BswM_GetLinScheduleState(0) == LinSMConf_LinSMSchedule_Normal_45618847))
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_LIN00_f26020e5_Normal_45618847) != BSWM_TRUE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_LIN00_f26020e5_Normal_45618847, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Enable. */
      retVal = BSWM_ID_AL_CC_AL_LIN00_f26020e5_Normal_45618847_Enable;
    }
  }
  else
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CC_LIN00_f26020e5_Normal_45618847) != BSWM_FALSE )
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CC_LIN00_f26020e5_Normal_45618847, BSWM_FALSE);
      /* Return triggered action list BswM_ActionList_CC_AL_LIN00_f26020e5_Normal_45618847_Disable. */
      retVal = BSWM_ID_AL_CC_AL_LIN00_f26020e5_Normal_45618847_Disable;
    }
  }
  return retVal;
}



#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

