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
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EthTrcv_30_Tja1100.c
 *        \brief  Source file containing the core implementation of the Ethernet transceiver driver
 *
 *      \details  The file EthTrcv_30_Tja1100.c is the source file which contains the hardware independent parts of
 *                the implementation of the Ethernet transceiver driver.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#define ETHTRCV_30_TJA1100_SOURCE
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EthTrcv_30_Tja1100.h"
#include "EthTrcv_30_Tja1100_Lcfg.h"
#include "EthTrcv_30_Tja1100_Int.h"
#include "EthTrcv_30_Tja1100_Regs.h"
#include "EthTrcv_30_Tja1100_LL_Cfg.h"
#include "EthTrcv_30_Tja1100_LL.h"
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857  */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777  */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779  */
/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of the EthTrcv_30_Tja1100 header file */
#if ( (ETHTRCV_30_TJA1100_SW_MAJOR_VERSION != 1U) \
    ||(ETHTRCV_30_TJA1100_SW_MINOR_VERSION != 1U) \
    ||(ETHTRCV_30_TJA1100_SW_PATCH_VERSION != 0U) )
# error "Vendor specific version numbers of EthTrcv_30_Tja1100.c and EthTrcv_30_Tja1100.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

VAR(EthTrcv_StateType, ETHTRCV_30_TJA1100_VAR_ZERO_INIT) EthTrcv_30_Tja1100_ModuleState = ETHTRCV_STATE_UNINIT;

#define ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#define ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
STATIC VAR(EthTrcv_StateType, ETHTRCV_30_TJA1100_VAR_NOINIT) EthTrcv_30_Tja1100_TrcvState[ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL];
#endif /* ETHTRCV_30_TJA1100_DEV_ERROR_DETECT */

STATIC VAR(EthTrcv_ModeType, ETHTRCV_30_TJA1100_VAR_NOINIT) EthTrcv_30_Tja1100_TrcvMode[ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL];

STATIC VAR(EthTrcv_LinkStateType, ETHTRCV_30_TJA1100_VAR_NOINIT) EthTrcv_30_Tja1100_LinkState[ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL];

#define ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

#define ETHTRCV_30_TJA1100_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  LOCAL INLINE FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetTrcvState()
 *********************************************************************************************************************/
/*! \brief       Retrieves the global transceiver state variable
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Transceiver state
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_StateType EthTrcv_30_Tja1100_GetTrcvState(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_SetTrcvState()
 *********************************************************************************************************************/
/*! \brief       Sets the global transceiver state variable
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   TrcvState             Transceiver state to set
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_SetTrcvState(
    uint8 TrcvIdx,
    EthTrcv_StateType TrcvState);
#endif /* ETHTRCV_30_TJA1100_DEV_ERROR_DETECT */

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetTrcvModeVar()
 *********************************************************************************************************************/
/*! \brief       Retrieves the global transceiver mode variable
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Transceiver mode
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_ModeType EthTrcv_30_Tja1100_GetTrcvModeVar(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetTrcvLinkState()
 *********************************************************************************************************************/
/*! \brief       Retrieves the global transceiver link state variable
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Link state
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_LinkStateType EthTrcv_30_Tja1100_GetTrcvLinkState(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetPhySignalQualityMeanValueLength()
 *********************************************************************************************************************/
/*! \brief       Retrieves the phy signal quality mean value length
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Phy signal quality mean value length
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE uint16 EthTrcv_30_Tja1100_GetPhySignalQualityMeanValueLength(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_SetTrcvModeVar()
 *********************************************************************************************************************/
/*! \brief       Sets the global transceiver mode variable
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   TrcvMode              Transceiver mode to set
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_SetTrcvModeVar(
    uint8 TrcvIdx,
    EthTrcv_ModeType TrcvMode);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_SetTrcvLinkState()
 *********************************************************************************************************************/
/*! \brief       Sets the global transceiver link state variable
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \param[in]   TrcvLinkState              Transceiver link state to set
 *  \return      -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_SetTrcvLinkState(
    uint8 TrcvIdx,
    EthTrcv_LinkStateType TrcvLinkState);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetHwIndex()
 *********************************************************************************************************************/
/*! \brief       Retrieves the hardware index of the transceiver
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Hardware index
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetHwIndex(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetHwSubIndex()
 *********************************************************************************************************************/
/*! \brief       Retrieves the hardware sub-index of the transceiver
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Hardware sub-index
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetHwSubIndex(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetMiiMode()
 *********************************************************************************************************************/
/*! \brief       Retrieves the mii mode of the transceiver
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Mii mode
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetMiiMode(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetWriteTrcvRegisterFunc()
 *********************************************************************************************************************/
/*! \brief       Retrieves a pointer to the register write function of the transceiver with index TrcvIdx
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Pointer to write register function
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_WriteTrcvRegisterType EthTrcv_30_Tja1100_GetWriteTrcvRegisterFunc(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc()
 *********************************************************************************************************************/
/*! \brief       Retrieves a pointer to the register read function of the transceiver with index TrcvIdx
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Pointer to read register function
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_ReadTrcvRegisterType EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(
    uint8 TrcvIdx);
#if( ETHTRCV_30_TJA1100_MAX_INIT_FUNCS_NUM != 0 )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetInitFunction()
 *********************************************************************************************************************/
/*! \brief       Retrieves a pointer to a lower layer function used in EthTrcv_30_Tja1100_TransceiverInit()
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Pointer to a lower layer init function
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_LL_InitFunction EthTrcv_30_Tja1100_GetInitFunction(
    uint8 TrcvIdx);
#endif /* ETHTRCV_30_TJA1100_MAX_INIT_FUNCS_NUM */

#if(ETHTRCV_30_TJA1100_ENABLE_PRE_TRCVINIT_CALLOUT == STD_ON)
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetPreTransceiverInitCalloutEnabled()
 *********************************************************************************************************************/
/*! \brief       Retrieves a boolean indicating of the pre transceiver init callout is enabled for the transceiver with
 *               index TrcvIdx
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      STD_ON - Pre transceiver init callout enabled
 *  \return      STD_OFF - Pre transceiver init callout disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetPreTransceiverInitCalloutEnabled(
    uint8 TrcvIdx);
#endif /* ETHTRCV_30_TJA1100_ENABLE_PRE_TRCVINIT_CALLOUT */

#if(ETHTRCV_30_TJA1100_ENABLE_POST_TRCVINIT_CALLOUT == STD_ON)
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetPostTransceiverInitCalloutEnabled()
 *********************************************************************************************************************/
/*! \brief       Retrieves a boolean indicating of the post transceiver init callout is enabled for the transceiver with
 *               index TrcvIdx
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      STD_ON - Post transceiver init callout enabled
 *  \return      STD_OFF - Post transceiver init callout disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetPostTransceiverInitCalloutEnabled(
    uint8 TrcvIdx);
#endif /* ETHTRCV_30_TJA1100_ENABLE_POST_TRCVINIT_CALLOUT */

#if ( ETHTRCV_30_TJA1100_WAKEUP_TYPE != ETHTRCV_WAKEUP_NOT_SUPPORTED )
/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetIcuChannel()
 *********************************************************************************************************************/
/*! \brief       Retrieves the icu channel of the transceiver with index TrcvIdx
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Icu channel
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE Icu_ChannelType EthTrcv_30_Tja1100_GetIcuChannel(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetWakeupMap()
 *********************************************************************************************************************/
/*! \brief       Retrieves the wakeup map of the transceiver with index TrcvIdx
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Wakeup map
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_WakeupMapType EthTrcv_30_Tja1100_GetWakeupMap(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetWakeupCalloutFct()
 *********************************************************************************************************************/
/*! \brief       Retrieves a pointer to the wakeup callout function of the transceiver with index TrcvIdx
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Wakeup callout function pointer
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_WakeupCalloutFctType EthTrcv_30_Tja1100_GetWakeupCalloutFct(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetWakeupMode()
 *********************************************************************************************************************/
/*! \brief       Retrieves the wakeup mode of the transceiver with index TrcvIdx
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Wakeup mode
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_WakeupModeType EthTrcv_30_Tja1100_GetWakeupMode(
    uint8 TrcvIdx);

/**********************************************************************************************************************
 * EthTrcv_30_Tja1100_GetWakeupReasonFlags()
 *********************************************************************************************************************/
/*! \brief       Retrieves the wakeup reason flags of the transceiver with index TrcvIdx
 *  \details     -
 *  \param[in]   TrcvIdx               Index of the transceiver
 *  \return      Wakeup reason flags
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
ETHTRCV_30_TJA1100_INLINE EthTrcv_WakeupReasonFlagsType EthTrcv_30_Tja1100_GetWakeupReasonFlags(
    uint8 TrcvIdx);
#endif /* ETHTRCV_30_TJA1100_WAKEUP_TYPE */
/**********************************************************************************************************************
 *  LOCAL INLINE FUNCTION DEFINITION
 *********************************************************************************************************************/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
ETHTRCV_30_TJA1100_INLINE EthTrcv_StateType EthTrcv_30_Tja1100_GetTrcvState(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_TrcvState[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_SetTrcvState(
    uint8 TrcvIdx,
    EthTrcv_StateType TrcvState)
{
  EthTrcv_30_Tja1100_TrcvState[TrcvIdx] = TrcvState;
}
#endif /* ETHTRCV_30_TJA1100_DEV_ERROR_DETECT */

ETHTRCV_30_TJA1100_INLINE EthTrcv_ModeType EthTrcv_30_Tja1100_GetTrcvModeVar(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_TrcvMode[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_SetTrcvModeVar(
    uint8 TrcvIdx,
    EthTrcv_ModeType TrcvMode)
{
  EthTrcv_30_Tja1100_TrcvMode[TrcvIdx] = TrcvMode;
}

ETHTRCV_30_TJA1100_INLINE uint16 EthTrcv_30_Tja1100_GetPhySignalQualityMeanValueLength(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_PhySignalQualityMeanValueLength[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE EthTrcv_LinkStateType EthTrcv_30_Tja1100_GetTrcvLinkState(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_LinkState[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE void EthTrcv_30_Tja1100_SetTrcvLinkState(
    uint8 TrcvIdx,
    EthTrcv_LinkStateType TrcvLinkState)
{
  EthTrcv_30_Tja1100_LinkState[TrcvIdx] = TrcvLinkState;
}

ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetHwIndex(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_HwIndex[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetHwSubIndex(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_HwSubIndex[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetMiiMode(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_MiiMode[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_WriteTrcvRegisterType EthTrcv_30_Tja1100_GetWriteTrcvRegisterFunc(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_WriteTrcvRegister[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_ReadTrcvRegisterType EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_ReadTrcvRegister[TrcvIdx];
}

#if( ETHTRCV_30_TJA1100_MAX_INIT_FUNCS_NUM != 0 )
ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_LL_InitFunction EthTrcv_30_Tja1100_GetInitFunction(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_InitFunctions[TrcvIdx];
}
#endif /* ETHTRCV_30_TJA1100_MAX_INIT_FUNCS_NUM */

#if(ETHTRCV_30_TJA1100_ENABLE_PRE_TRCVINIT_CALLOUT == STD_ON)
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetPreTransceiverInitCalloutEnabled(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_PreTransceiverInitCalloutEnabled[TrcvIdx];
}
#endif /* ETHTRCV_30_TJA1100_ENABLE_PRE_TRCVINIT_CALLOUT */

#if(ETHTRCV_30_TJA1100_ENABLE_POST_TRCVINIT_CALLOUT == STD_ON)
ETHTRCV_30_TJA1100_INLINE uint8 EthTrcv_30_Tja1100_GetPostTransceiverInitCalloutEnabled(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_PostTransceiverInitCalloutEnabled[TrcvIdx];
}
#endif /* ETHTRCV_30_TJA1100_ENABLE_POST_TRCVINIT_CALLOUT */

#if ( ETHTRCV_30_TJA1100_WAKEUP_TYPE != ETHTRCV_WAKEUP_NOT_SUPPORTED )
ETHTRCV_30_TJA1100_INLINE Icu_ChannelType EthTrcv_30_Tja1100_GetIcuChannel(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_IcuChannel[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_WakeupMapType EthTrcv_30_Tja1100_GetWakeupMap(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_WakeupMap[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE EthTrcv_30_Tja1100_WakeupCalloutFctType EthTrcv_30_Tja1100_GetWakeupCalloutFct(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_WakeupCalloutFct[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE EthTrcv_WakeupModeType EthTrcv_30_Tja1100_GetWakeupMode(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_WakeupMode[TrcvIdx];
}

ETHTRCV_30_TJA1100_INLINE EthTrcv_WakeupReasonFlagsType EthTrcv_30_Tja1100_GetWakeupReasonFlags(
    uint8 TrcvIdx)
{
  return EthTrcv_30_Tja1100_WakeupReasonFlags[TrcvIdx];
}
#endif /* ETHTRCV_30_TJA1100_WAKEUP_TYPE */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *  EthTrcv_30_Tja1100_SetBitsRegValPattern
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_SetBitsRegValPattern(
    uint16 RegValPattern,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  /* #10 Set bits according to the given pattern */
  *RegValPtr |= (uint16)RegValPattern;
}

/*********************************************************************************************************************
 *  EthTrcv_30_Tja1100_ClearBitsRegValPattern
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_ClearBitsRegValPattern(
    uint16 RegValPattern,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) RegValPtr)
{
  /* #10 Clear bits according to the given pattern */
  *RegValPtr &= (uint16)((uint32)~RegValPattern);
}

/*********************************************************************************************************************
 *  EthTrcv_30_Tja1100_ReadModifyWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_ReadModifyWrite(
    uint8 TrcvIdx,
    uint8 RegAddr,
    EthTrcv_30_Tja1100_LL_ModifyRegValFunction ModifyFunc)
{
  /* ----- Local Variables ---------------------------------------------- */

  uint16         regVal;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameter */
  if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else
#endif
  {
    /* #20 Read the specified transceiver register */
    retVal = EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(TrcvIdx)(
        EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
        EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
        RegAddr,
        &regVal);

    /* #30 Modify the register with the specified modification function */
    ModifyFunc(TrcvIdx, &regVal);

    /* #40 Write the register value back */
    retVal |= EthTrcv_30_Tja1100_GetWriteTrcvRegisterFunc(TrcvIdx)(
        EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
        EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
        RegAddr,
        regVal);
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, 0, ETHTRCV_30_TJA1100_SID_READ_MODIFY_WRITE_REG_VAL, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_ReadModifyWrite() */

/*********************************************************************************************************************
 *  EthTrcv_30_Tja1100_ReadModifyWriteRegVal
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_ReadModifyWriteRegVal(
    uint8 TrcvIdx,
    uint8 RegAddr,
    uint16 RegVal,
    EthTrcv_30_Tja1100_ModifyRegWithRegValFunction ModifyFunc)
{
  /* ----- Local Variables ---------------------------------------------- */

  uint16         regValRead;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;
  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameter */
  if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else
#endif
  {
    /* #20 Read the specified transceiver register */
    retVal = EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(TrcvIdx)(
        EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
        EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
        RegAddr,
        &regValRead);

    /* #30 Modify the register's value with the specified modification function and the given register value */
    ModifyFunc(RegVal, &regValRead);

    /* #40 Write the register value back */
    retVal |= EthTrcv_30_Tja1100_GetWriteTrcvRegisterFunc(TrcvIdx)(
        EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
        EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
        RegAddr,
        regValRead);
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, 0, ETHTRCV_30_TJA1100_SID_READ_MODIFY_WRITE_REG_VAL, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_ReadModifyWrite() */

/*********************************************************************************************************************
 *  EthTrcv_30_Tja1100_ReadAndCompare
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_ReadAndCompare(
    uint8 TrcvIdx,
    uint8 RegAddr,
    EthTrcv_30_Tja1100_LL_CompareRegValFunction CompareFunc,
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) ResultPtr)
{
  /* ----- Local Variables ---------------------------------------------- */

  uint16         regVal;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  Std_ReturnType retVal  = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameter */
  if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else
#endif
  {
    /* #20 Read the specified transceiver register */
    retVal = EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(TrcvIdx)(
        EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
        EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
        RegAddr,
        &regVal);

    if(retVal == E_OK)
    {
      /* #30 Compare the register's value with the specified compare function */
      *ResultPtr = CompareFunc(TrcvIdx, regVal);
    }
    else
    {
      *ResultPtr = FALSE;
    }
  }

  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, 0, ETHTRCV_30_TJA1100_SID_READ_AND_COMPARE, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif
  /* #40 Return the result */
  return retVal;
} /* EthTrcv_30_Tja1100_ReadAndCompare() */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_InitMemory
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_InitMemory(
    void)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */

  EthTrcv_30_Tja1100_ModuleState = ETHTRCV_STATE_UNINIT;
} /* EthTrcv_30_Tja1100_InitMemory() */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_Init(
  P2CONST(EthTrcv_30_Tja1100_ConfigType, ETHTRCV_30_TJA1100_CONST, ETHTRCV_30_TJA1100_CONST) CfgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameter */
  if(CfgPtr != NULL_PTR)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    uint8 trcvIdx;

    ETHTRCV_30_TJA1100_DUMMY_STATEMENT(CfgPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */

    /* #20 Loop over all available transceivers */
    for( trcvIdx = 0; trcvIdx < ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL; trcvIdx++ )
    {
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
      /* #210 Set the transceiver's init state to uninit */
      EthTrcv_30_Tja1100_SetTrcvState(trcvIdx, ETHTRCV_STATE_UNINIT);
#endif /* ETHTRCV_30_TJA1100_DEV_ERROR_DETECT */

      /* #220 Set the transceiver mode to down */
      EthTrcv_30_Tja1100_SetTrcvModeVar(trcvIdx, ETHTRCV_MODE_DOWN);

      /* #230 Initialize additional global variables */ /*lint -e{522} */
      EthTrcv_30_Tja1100_LL_InitGlobalVariables(trcvIdx);

#if ( ETHTRCV_30_TJA1100_WAKEUP_TYPE != ETHTRCV_WAKEUP_NOT_SUPPORTED )
      /* #240 Initialize wakeup related state variables */
      EthTrcv_30_Tja1100_GetWakeupMode(trcvIdx) = ETHTRCV_WUM_ENABLE;
      EthTrcv_30_Tja1100_ClearWakeupReasons(trcvIdx);

      /* #250 Check for wakeup events */
      (void)EthTrcv_30_Tja1100_InspectWakeupReasons(trcvIdx);

      /* #260 Check if any wakeup reason was set */
      if( !EthTrcv_30_Tja1100_IsWakeupReasonPending(trcvIdx) )
      {
        /* #2610 No wakeup reason set -> default during initialization is RESET */
        EthTrcv_30_Tja1100_SetWakeupReason_Reset(trcvIdx);
      }
      /* #270 report wakeup events */
      EthTrcv_30_Tja1100_ReportWakeup(trcvIdx);
#endif

    }
    /* #30 Initialize state variable */
    if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
    {
      EthTrcv_30_Tja1100_ModuleState = ETHTRCV_STATE_INIT;
    }
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, 0, ETHTRCV_30_TJA1100_SID_TRANSCEIVER_INIT, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif
} /* EthTrcv_30_Tja1100_Init() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */ /*lint !e438 */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_TransceiverInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_TransceiverInit(
    uint8 TrcvIdx,
    uint8 CfgIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal    = E_NOT_OK;
  uint8          errorId   = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(CfgIdx >= ETHTRCV_30_TJA1100_MAX_CFGS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation --------------------------------------------- */
    /* #20 Trigger start of runtime measurement */
    EthTrcv_30_Tja1100_Rtm_Start(TransceiverInit);

    /* #30 Perform user callouts before transceiver init */
#if(ETHTRCV_30_TJA1100_ENABLE_PRE_TRCVINIT_CALLOUT == STD_ON)
    if(EthTrcv_30_Tja1100_GetPreTransceiverInitCalloutEnabled(TrcvIdx) == STD_ON)
    {
      EthTrcv_30_Tja1100_PreTransceiverInitCallout(TrcvIdx);
    }
#endif /* ETHTRCV_30_TJA1100_ENABLE_PRE_TRCVINIT_CALLOUT */

    /* #40 Perform wait until hardware reset is finished */ /*lint -e{522} */
#if ( ETHTRCV_30_TJA1100_HW_ACCESS_LOOP_COUNT != 0 )
    {
      uint32 loopCount;

      for(loopCount = 0; loopCount < (uint32)ETHTRCV_30_TJA1100_HW_ACCESS_LOOP_COUNT; loopCount++)
      {
        if(EthTrcv_30_Tja1100_LL_IsTransceiverAccessOk(TrcvIdx) == TRUE)
        {
          break;
        }
      }
    }
#endif /* ETHTRCV_30_TJA1100_MII_ACCESS_LOOP_COUNT != 0 */

    /* #50 The register value of the identifier register was plausible */ /*lint -e{522} */
    if ( (EthTrcv_30_Tja1100_LL_IsTransceiverAccessOk(TrcvIdx) == TRUE) )
    {
    /* #510 If necessary, soft-reset Transceiver and wait until the reset bit is cleared by the transceiver */ /*lint -e{522} */
#if(ETHTRCV_30_TJA1100_SOFT_RESET_ON_INIT == STD_ON)
      uint16  regVal;
      uint16  swResetCt;
      boolean isSwResetFinished;

      retVal = EthTrcv_30_Tja1100_ReadModifyWrite(
          TrcvIdx,
          EthTrcv_30_Tja1100_LL_GetSwResetRegister(TrcvIdx),
          EthTrcv_30_Tja1100_LL_PrepareSwReset);

        swResetCt = 0;
        do
        {
          retVal |= EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(TrcvIdx)(
              EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
              EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
              EthTrcv_30_Tja1100_LL_GetSwResetRegister(TrcvIdx),
              &regVal);

          swResetCt++;
          isSwResetFinished = EthTrcv_30_Tja1100_LL_IsSwResetFinished(TrcvIdx, regVal);
        }
        while ( (isSwResetFinished == FALSE) && (swResetCt < ETHTRCV_30_TJA1100_SOFT_RESET_WAIT_CYCLES) && (retVal == E_OK) );

        if ( isSwResetFinished == FALSE )
        {
          /* The software reset could not be finished */
          retVal = E_NOT_OK;
        }
#else
      retVal = E_OK;
#endif /* ETHTRCV_30_TJA1100_SOFT_RESET_ON_INIT */
      ETHTRCV_30_TJA1100_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #520 Run vendor specific initialization script if available */ /*lint -e{522} */
      EthTrcv_30_Tja1100_LL_RunVendorSpecificInitScripts(TrcvIdx);

      /* #530 Enable the access to Transceiver Registers in order to perform the configuration of the device */ /*lint -e{522} */
      EthTrcv_30_Tja1100_LL_EnableConfigAccess(TrcvIdx, &retVal);

      /* #540 Write the generated basic control register value to the transceiver */
      retVal = EthTrcv_30_Tja1100_ReadModifyWrite(
          TrcvIdx,
          EthTrcv_30_Tja1100_LL_GetBasicControlRegister(TrcvIdx),
          EthTrcv_30_Tja1100_LL_SetBasicConfigurationRegVal);

      /* #550 Set the interface options between the Ethernet controller and transceiver */
      switch( EthTrcv_30_Tja1100_GetMiiMode(TrcvIdx) )
      {
        case ETHTRCV_MII_MODE:
          /*lint -e{522} */
          EthTrcv_30_Tja1100_LL_SetMiiInterfaceToMiiMode(TrcvIdx, &retVal);
          break;
        case ETHTRCV_LIGHT_MII_MODE:
          /*lint -e{522} */
          EthTrcv_30_Tja1100_LL_SetMiiInterfaceToLightMiiMode(TrcvIdx, &retVal);
          break;
        case ETHTRCV_RMII_MODE:
          /*lint -e{522} */
          EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRmiiMode(TrcvIdx, &retVal);
          break;
        case ETHTRCV_RMII_XTAL_MODE:
          /*lint -e{522} */
          EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRmiiXtalMode(TrcvIdx, &retVal);
          break;
        case ETHTRCV_GMII_MODE:
          /*lint -e{522} */
          EthTrcv_30_Tja1100_LL_SetMiiInterfaceToGmiiMode(TrcvIdx, &retVal);
          break;
        case ETHTRCV_RGMII_MODE:
          /*lint -e{522} */
          EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRgmiiMode(TrcvIdx, &retVal);
          break;
        case ETHTRCV_RGMII_XTAL_MODE:
          /*lint -e{522} */
          EthTrcv_30_Tja1100_LL_SetMiiInterfaceToRgmiiXtalMode(TrcvIdx, &retVal);
          break;
        default:
          break;
      }
      /* #560 Perform additional hardware dependent configuration steps */
#if( ETHTRCV_30_TJA1100_MAX_INIT_FUNCS_NUM != 0 )
      {
        uint8 funcIdx;

        for(funcIdx = 0; funcIdx < ETHTRCV_30_TJA1100_MAX_INIT_FUNCS_NUM; funcIdx++)
        {
          EthTrcv_30_Tja1100_GetInitFunction(funcIdx)(TrcvIdx, &retVal);
        }
      }
#endif /* ETHTRCV_30_TJA1100_MAX_INIT_FUNCS_NUM */

      /* #570 Perform user callouts after transceiver init */
#if( ETHTRCV_30_TJA1100_ENABLE_POST_TRCVINIT_CALLOUT == STD_ON )
    if(EthTrcv_30_Tja1100_GetPostTransceiverInitCalloutEnabled(TrcvIdx) == STD_ON)
    {
      EthTrcv_30_Tja1100_PostTransceiverInitCallout(TrcvIdx);
    }
#endif /* ETHTRCV_30_TJA1100_ENABLE_POST_TRCVINIT_CALLOUT */

      /* #580 Disable the configuration access */ /*lint -e{522} */
      EthTrcv_30_Tja1100_LL_DisableConfigAccess(TrcvIdx, &retVal);

      ETHTRCV_30_TJA1100_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
    /* #60 The register value of the identifier register was not plausible */
    else
    {
      /* #610 DEM error because no access to transceiver */
      ETHTRCV_30_TJA1100_DEM_REPORT_ERROR_STATUS_ETHTRCV_E_ACCESS(TrcvIdx);

      retVal = E_NOT_OK;
    }

#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
    /* #70 Set transceiver state variable */
    EthTrcv_30_Tja1100_SetTrcvState(TrcvIdx, ETHTRCV_STATE_INIT);
#endif
    /* #80 Set transceiver mode to down */
    EthTrcv_30_Tja1100_SetTrcvModeVar(TrcvIdx, ETHTRCV_MODE_DOWN);

    /* #90 Set the link state to down */
    EthTrcv_30_Tja1100_SetTrcvLinkState(TrcvIdx, ETHTRCV_LINK_STATE_DOWN);

    /* #100 Trigger stop of runtime measurement */
    EthTrcv_30_Tja1100_Rtm_Stop(TransceiverInit);
  }

  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_TRANSCEIVER_INIT, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_TransceiverInit() */ /* PRQA S 2006, 6010, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_SetTransceiverMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#if ( ETHTRCV_30_TJA1100_ENABLE_SET_TRCV_MODE == STD_ON )
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_SetTransceiverMode(
    uint8 TrcvIdx,
    EthTrcv_ModeType TrcvMode)
{
  /* ----- Local Variables ----------------------------------------- */
  uint16         regVal;
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks -------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(EthTrcv_30_Tja1100_GetTrcvState(TrcvIdx) == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if((TrcvMode != ETHTRCV_MODE_DOWN) && (TrcvMode != ETHTRCV_MODE_ACTIVE))
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_PARAM;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    ETHTRCV_30_TJA1100_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* #20 Read transceiver mode register */
    retVal = EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(TrcvIdx)(
        EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
        EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
        EthTrcv_30_Tja1100_LL_GetTransceiverModeRegister(TrcvIdx),
        &regVal);

    if ( retVal == E_OK )
    {
      /* #30 Clear all mode settings - will be set later */ /*lint -e{522} */
      EthTrcv_30_Tja1100_LL_ClearAllModeSettings(TrcvIdx, &regVal);

      /* #40 The transceiver mode should be set to ACTIVE */
      if ( TrcvMode == ETHTRCV_MODE_ACTIVE )
      {
        /* #410 Prepare RegVal to set the transceiver mode to ACTIVE */
        EthTrcv_30_Tja1100_LL_SetRegValForTransceiverModeActive(TrcvIdx, &regVal);

        /* #420 If necessary Wait before the LINK_CONTROL bit is enabled */ /*lint -e{522} */
        EthTrcv_30_Tja1100_LL_EnableLinkStartupDelay(TrcvIdx);

        /* #430 If wakeup mode is configured and enabled, disable ICU notification */
#if ( ETHTRCV_30_TJA1100_WAKEUP_TYPE != ETHTRCV_WAKEUP_NOT_SUPPORTED )
        if( EthTrcv_30_Tja1100_GetWakeupMode(TrcvIdx) == ETHTRCV_WUM_ENABLE )
        {
          Icu_DisableNotification(EthTrcv_30_Tja1100_GetIcuChannel(TrcvIdx));
        }
#endif /* ETHTRCV_WAKEUP_NOT_SUPPORTED != ETHTRCV_30_TJA1100_WAKEUP_TYPE */

        EthTrcv_30_Tja1100_SetTrcvModeVar(TrcvIdx, ETHTRCV_MODE_ACTIVE);
      }
      /* #50 The transceiver mode should be set to DOWN */
      else
      {
        /* #510 Prepare RegVal to set the transceiver mode to DOWN */
        EthTrcv_30_Tja1100_LL_SetRegValForTransceiverModeDown(TrcvIdx, &regVal);

        /* #520 If wakeup mode is configured and enabled, enable ICU notification */
#if ( ETHTRCV_30_TJA1100_WAKEUP_TYPE != ETHTRCV_WAKEUP_NOT_SUPPORTED )
        if( EthTrcv_30_Tja1100_GetWakeupMode(TrcvIdx) == ETHTRCV_WUM_ENABLE )
        {
          Icu_EnableNotification(EthTrcv_30_Tja1100_GetIcuChannel(TrcvIdx));
        }
#endif /* ETHTRCV_WAKEUP_NOT_SUPPORTED != ETHTRCV_30_TJA1100_WAKEUP_TYPE */

        EthTrcv_30_Tja1100_SetTrcvModeVar(TrcvIdx, ETHTRCV_MODE_DOWN);
      }
      /* #60 Write the register value back to the transceiver mode register */
      retVal = EthTrcv_30_Tja1100_GetWriteTrcvRegisterFunc(TrcvIdx)(
          EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
          EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
          EthTrcv_30_Tja1100_LL_GetTransceiverModeRegister(TrcvIdx),
          regVal);

      /* #70 Call wakeup callout user code if wakup is supported and callout functions are configured */
#if ( ETHTRCV_30_TJA1100_WAKEUP_TYPE != ETHTRCV_WAKEUP_NOT_SUPPORTED )
      if( ( retVal == E_OK ) && ( TrcvMode == ETHTRCV_MODE_ACTIVE ) )
      {
        /* call user code */
        if( EthTrcv_30_Tja1100_GetWakeupCalloutFct(TrcvIdx) != NULL_PTR )
        {
          EthTrcv_30_Tja1100_GetWakeupCalloutFct(TrcvIdx)(TrcvIdx);
        }
      }
#endif /* ETHTRCV_WAKEUP_NOT_SUPPORTED != ETHTRCV_30_TJA1100_WAKEUP_TYPE */
    }
    ETHTRCV_30_TJA1100_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_SET_TRANSCEIVER_MODE, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_SetTransceiverMode() */ /* PRQA S 2006, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* ETHTRCV_30_TJA1100_ENABLE_SET_TRCV_MODE */

#if ( ETHTRCV_30_TJA1100_ENABLE_GET_TRCV_MODE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_GetTransceiverMode
 *********************************************************************************************************************/
/*!
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
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_GetTransceiverMode(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_ModeType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) TrcvModePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  boolean        result;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(EthTrcv_30_Tja1100_GetTrcvState(TrcvIdx) == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvModePtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #20 Read transceiver mode register */
    retVal = EthTrcv_30_Tja1100_ReadAndCompare(
        TrcvIdx,
        EthTrcv_30_Tja1100_LL_GetTransceiverModeRegister(TrcvIdx),
        EthTrcv_30_Tja1100_LL_IsTransceiverModeActive,
        &result);

    if(retVal == E_OK)
    {
      if(result == TRUE)
      /* #30 The register value of the transceiver mode register returns mode ACTIVE */
      {
        /* #310 Report transceiver mode ACTIVE */
        *TrcvModePtr = ETHTRCV_MODE_ACTIVE;
      }
      /* #40 The register value of the transceiver mode register returns mode DOWN */
      else
      {
        /* #410 Report transceiver mode DOWN */
        *TrcvModePtr = ETHTRCV_MODE_DOWN;
      }
      /* #50 Save the retrieved transceiver mode in local variable */
      EthTrcv_30_Tja1100_SetTrcvModeVar(TrcvIdx, *TrcvModePtr);
    }
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_GET_TRANSCEIVER_MODE, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_GetTransceiverMode() */ /* PRQA S 2006, 6010, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* ETHTRCV_30_TJA1100_ENABLE_GET_TRCV_MODE */

/* PRQA S 3007 2 */ /* MD_EthTrcv_30_Tja1100_3007 */
#if ( ETHTRCV_30_TJA1100_ENABLE_START_AUTO_NEG == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_StartAutoNegotiation
 *********************************************************************************************************************/
/*!
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
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_StartAutoNegotiation(
    uint8 TrcvIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  boolean        isTrcvModeActive;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(EthTrcv_30_Tja1100_GetTrcvState(TrcvIdx) == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Auto negotiation is available and the transceiver mode is active */
    isTrcvModeActive = (boolean)(EthTrcv_30_Tja1100_GetTrcvModeVar(TrcvIdx) == ETHTRCV_MODE_ACTIVE);
    if((EthTrcv_30_Tja1100_LL_IsStartAutoNegAvailable(TrcvIdx) == TRUE) && (isTrcvModeActive == TRUE))
    {
      ETHTRCV_30_TJA1100_BEGIN_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #210 Read register that enables auto negotiation
       * #220 Prepare the read register value to enable auto negotiation
       * #230 Write the prepared register value back into the register to start auto negotiation*/
      retVal = EthTrcv_30_Tja1100_ReadModifyWrite(
          TrcvIdx,
          EthTrcv_30_Tja1100_LL_GetStartAutoNegRegister(TrcvIdx),
          EthTrcv_30_Tja1100_LL_EnableStartAutoNegotiation);

      ETHTRCV_30_TJA1100_END_CRITICAL_SECTION(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
    /* #30 Auto negotiation is not available */
    else
    {
      /* #310 Leave the API with E_NOT_OK */
      retVal = E_NOT_OK;
    }
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_START_AUTO_NEG, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_StartAutoNegotiation() */ /* PRQA S 2006, 6080 */ /* MD_MSR_14.7, MD_MSR_STMIF */
#endif /* ETHTRCV_30_TJA1100_ENABLE_START_AUTO_NEG */

#if ( ETHTRCV_30_TJA1100_ENABLE_GET_LINK_STATE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_GetLinkState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_GetLinkState(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) LinkStatePtr)
{
  /* ----- Local variables ---------------------------------------------- */

  uint16         regVal;
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  boolean        result;

  /* ----- Development Error Checks ------------------------------------- */

#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(EthTrcv_30_Tja1100_GetTrcvState(TrcvIdx) == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(LinkStatePtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #20 The transceiver mode is active */
    if(EthTrcv_30_Tja1100_GetTrcvModeVar(TrcvIdx) == ETHTRCV_MODE_ACTIVE)
    {
      /* #210 Read the link state register twice because some bits are latched low in some transceivers */
      retVal  = EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(TrcvIdx)(
          EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
          EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
          EthTrcv_30_Tja1100_LL_GetLinkStateRegister(TrcvIdx),
          &regVal);

      retVal |= EthTrcv_30_Tja1100_ReadAndCompare(
              TrcvIdx,
              EthTrcv_30_Tja1100_LL_GetLinkStateRegister(TrcvIdx),
              EthTrcv_30_Tja1100_LL_IsLinkStateActive,
              &result);

      if(retVal == E_OK)
      {
        if(result == TRUE)
        /* #220 The link state register returns link state ACTIVE */
        {
          /* #2210 Report the link state is ACTIVE */
          *LinkStatePtr = ETHTRCV_LINK_STATE_ACTIVE;
          /* #2220  Reset the link fail counter */ /*lint -e{522} */
          EthTrcv_30_Tja1100_LL_ResetLinkFailCounter(TrcvIdx);
        }
        /* #230 The link state register returns link state DOWN */
        else
        {
          /* #2310 Report the link state is DOWN */
          *LinkStatePtr = ETHTRCV_LINK_STATE_DOWN;
          /* #2320 Increment the link fail counter */ /*lint -e{522} */
          EthTrcv_30_Tja1100_LL_IncrementLinkFailCounter(TrcvIdx);
        }
      }
      /* #240 Save the link state in local state variable */
      EthTrcv_30_Tja1100_SetTrcvLinkState(TrcvIdx, *LinkStatePtr);
    }
    /* #30 The transceiver mode is down */
    else
    {
      /* #310 Report the link state is DOWN */
      *LinkStatePtr = ETHTRCV_LINK_STATE_DOWN;

      /* #320 Save the link state in local state variable */
      EthTrcv_30_Tja1100_SetTrcvLinkState(TrcvIdx, *LinkStatePtr);

      retVal = E_OK;
    }
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_GET_LINK_STATE, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* ETHTRCV_30_TJA1100_ENABLE_GET_LINK_STATE */ /* PRQA S 2006, 6010, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* ETHTRCV_30_TJA1100_ENABLE_GET_LINK_STATE */

#if ( ETHTRCV_30_TJA1100_ENABLE_GET_BAUD_RATE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_GetBaudRate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_GetBaudRate(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_BaudRateType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) BaudRatePtr)
{
  /* ----- Local variables ---------------------------------------------- */
  uint16         regVal;
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  boolean        isLinkStateActive;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(BaudRatePtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 The baud rate can be read and the link state is active */
    isLinkStateActive = (boolean)(EthTrcv_30_Tja1100_GetTrcvLinkState(TrcvIdx) == ETHTRCV_LINK_STATE_ACTIVE);
    if((EthTrcv_30_Tja1100_LL_IsGetBaudRateAvailable(TrcvIdx) == TRUE) && (isLinkStateActive == TRUE))
    {
      /* #210 Read the baud rate register */
      retVal  = EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(TrcvIdx)(
          EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
          EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
          EthTrcv_30_Tja1100_LL_GetBaudRateRegister(TrcvIdx), /*lint -e{522} */
          &regVal);

      if(retVal == E_OK)
      {
        /* #220 Report the returned baud rate */ /*lint -e{522} */
        EthTrcv_30_Tja1100_LL_CheckBaudRate(TrcvIdx, regVal, BaudRatePtr);
      }
    }
    /* #30 The baud rate cannot be read or the link state is down*/
    else
    {
      /* #310 Return E_NOT_OK */
      retVal = E_NOT_OK;
    }
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_GET_BAUD_RATE, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_GetBaudRate() */ /* PRQA S 2006, 6010, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* ETHTRCV_30_TJA1100_ENABLE_GET_BAUD_RATE */

#if ( ETHTRCV_30_TJA1100_ENABLE_GET_DUPLEX_MODE == STD_ON )
/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_GetDuplexMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_GetDuplexMode(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) DuplexModePtr)
{
  /* ----- Local variables ---------------------------------------------- */

  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  boolean        result;
  boolean        isLinkStateActive;
  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(DuplexModePtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 The duplex mode can be read and the link state is active */
    isLinkStateActive = (boolean)(EthTrcv_30_Tja1100_GetTrcvLinkState(TrcvIdx) == ETHTRCV_LINK_STATE_ACTIVE);
    if((EthTrcv_30_Tja1100_LL_IsGetDuplexModeAvailable(TrcvIdx) == TRUE) && (isLinkStateActive == TRUE))
    {
      /* #210 Read the duplex mode register */
      retVal = EthTrcv_30_Tja1100_ReadAndCompare(
              TrcvIdx,
              EthTrcv_30_Tja1100_LL_GetDuplexModeRegister(TrcvIdx),
              EthTrcv_30_Tja1100_LL_IsDuplexModeFull,
              &result);

      if (retVal == E_OK)
      {
        /* #220 The duplex mode register returns that the duplex mode is full duplex */ /*lint -e{522} */
        if (result == TRUE)
        {
          /* #2210 Report that the duplex mode is full duplex */
          *DuplexModePtr = ETHTRCV_DUPLEX_MODE_FULL;
        }
        /* #230 The duplex mode register returns that the duplex mode is half duplex */
        else
        {
          /* #2310 Report that the duplex mode is half duplex */
          *DuplexModePtr = ETHTRCV_DUPLEX_MODE_HALF;
        }
      }
    }
    /* #30 The duplex mode cannot be read or the link state is down */
    else
    {
      /* #310 Return E_NOT_OK */
      retVal = E_NOT_OK;
    }
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_GET_DUPLEX_MODE, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_GetDuplexMode() */ /* PRQA S 2006, 6010, 6080 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STMIF */
#endif /* ETHTRCV_30_TJA1100_ENABLE_GET_DUPLEX_MODE */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_SetPhyTestMode
 *********************************************************************************************************************/
/*!
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
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_SetPhyTestMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTestModeType TestMode)
{
  /* ----- Local variables ---------------------------------------------- */

  Std_ReturnType retVal         = E_NOT_OK;
  uint8          errorId        = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(EthTrcv_30_Tja1100_LL_IsTestmodeSupportedByHw(TrcvIdx, TestMode) == FALSE)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_SUPPORTED;
  }
  else
#endif
  {
    if(EthTrcv_30_Tja1100_LL_IsSetTestModeAvailable(TrcvIdx) == TRUE)
    {
      if(EthTrcv_30_Tja1100_GetTrcvModeVar(TrcvIdx) == ETHTRCV_MODE_ACTIVE)
      {
        /* #20 Prepare the transceiver to set the test mode */ /*lint -e{522} */
        EthTrcv_30_Tja1100_LL_SetPhyTestMode(TrcvIdx, TestMode, &retVal);
      }
    }
  }
    /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_SET_PHY_TEST_MODE, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_SetPhyTestMode() */ /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STCYC, MD_MSR_STCAL,  MD_MSR_STMIF */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_SetPhyLoopbackMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_SetPhyLoopbackMode(
    uint8 TrcvIdx,
    EthTrcv_PhyLoopbackModeType LoopbackMode)
{
  /* ----- Local variables ---------------------------------------------- */

  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(EthTrcv_30_Tja1100_LL_IsLoopbackmodeSupportedByHw(TrcvIdx, LoopbackMode) == FALSE)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_SUPPORTED;
  }
  else
#endif
  {
    /* #20 Set the given loopback mode */
    EthTrcv_30_Tja1100_LL_SetPhyLoopbackMode(TrcvIdx, LoopbackMode, &retVal);
  }
    /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_SET_PHY_LOOPBACK_MODE, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_SetPhyLoopbackMode() */ /* PRQA S 6050 */ /* MD_MSR_14.7, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_GetPhySignalQuality
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_GetPhySignalQuality(
    uint8 TrcvIdx,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) SignalQualityPtr)
{
  /* ----- Local variables ---------------------------------------------- */

  uint32         signalQualityValueSum;
  uint16         signalQualityValueIndex;
  uint16         meanLength;
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(SignalQualityPtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* #20 The transceiver mode is active */
    if(EthTrcv_30_Tja1100_GetTrcvModeVar(TrcvIdx) == ETHTRCV_MODE_ACTIVE)
    {
      /* #30 The signal quality of the transceiver can be obtained */
      if(EthTrcv_30_Tja1100_LL_IsSignalQualityAvailable(TrcvIdx) == TRUE)
      {
        if(EthTrcv_30_Tja1100_GetTrcvLinkState(TrcvIdx) == ETHTRCV_LINK_STATE_ACTIVE)
        {
          /* #310 Prepare the signal quality measurement */
          EthTrcv_30_Tja1100_LL_PrepareSignalQualityMeasurement(TrcvIdx, &retVal);

          /* #320 Retrieve the mean length to be used to calculate the average signal quality value */
          meanLength = EthTrcv_30_Tja1100_GetPhySignalQualityMeanValueLength(TrcvIdx);

          signalQualityValueSum = 0;

          /* #330 Summarize the data points for the signal quality until the mean length is reached */
          for(signalQualityValueIndex = 0; signalQualityValueIndex < meanLength; signalQualityValueIndex++)
          {
            signalQualityValueSum = signalQualityValueSum + EthTrcv_30_Tja1100_LL_GetPhySignalQualityValueInPercent(TrcvIdx, &retVal);
          }

          /* #340 Finalize the signal quality measurement */
          EthTrcv_30_Tja1100_LL_FinalizeSignalQualityMeasurement(TrcvIdx, &retVal);

          /* #350 Return the average of the obtained data points for the signal quality in percent */
          if(retVal == E_OK)
          {
            *SignalQualityPtr = (uint8)(signalQualityValueSum / meanLength);
          }
        }
        else
        {
          *SignalQualityPtr = 0;
        }
      }
    }
  }
    /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_GET_PHY_SIGNAL_QUALITY, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_GetPhySignalQuality() */ /* PRQA S 2006, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_SetPhyTxMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_SetPhyTxMode(
    uint8 TrcvIdx,
    EthTrcv_PhyTxModeType TxMode)
{
  /* ----- Local variables ---------------------------------------------- */

  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(EthTrcv_30_Tja1100_LL_IsTxmodeSupportedByHw(TrcvIdx, TxMode) == FALSE)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_SUPPORTED;
  }
  else
#endif
  {
    /* #20 Set the given tx mode */
    EthTrcv_30_Tja1100_LL_SetPhyTxMode(TrcvIdx, TxMode, &retVal);
  }
    /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_SET_PHY_TX_MODE, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_SetPhyTxMode() */ /* PRQA S 2006, 6050 */ /* MD_MSR_14.7, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_GetCableDiagnosticsResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_GetCableDiagnosticsResult(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, AUTOMATIC) CableDiagResultPtr)
{
  /* ----- Local variables ---------------------------------------------- */

  uint32         timeoutCounter;
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(CableDiagResultPtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    if(EthTrcv_30_Tja1100_GetTrcvModeVar(TrcvIdx) == ETHTRCV_MODE_ACTIVE)
    {
      /* #20 The transceiver supports cable diagnostics */
      if(EthTrcv_30_Tja1100_LL_IsCableDiagAvailable(TrcvIdx) == TRUE)
      {
        /* #210 Prepare the cable diagnostic */ /*lint -e{522} */
        EthTrcv_30_Tja1100_LL_PrepareCableDiag(TrcvIdx, &retVal);

        if(retVal == E_OK)
        {
          /* #220 Wait until the cable diagnostics result is available */
          retVal = E_NOT_OK;
          for(timeoutCounter = 0; timeoutCounter < ETHTRCV_30_TJA1100_CABLE_DIAG_LOOP_CYCLES; timeoutCounter++)
          {
            if(EthTrcv_30_Tja1100_LL_IsCableDiagFinished(TrcvIdx) == TRUE)
            {
              retVal = E_OK;
              break;
            }
          }
          if(retVal == E_OK)
          {
            /* #230 Report the returned cable diagnostic result */ /*lint -e{522} */
            EthTrcv_30_Tja1100_LL_CheckCableDiagResult(TrcvIdx, CableDiagResultPtr);
          }
        }
        /* #240 Perform additional steps after the cable diagnostics */ /*lint -e{522} */
        EthTrcv_30_Tja1100_LL_AdditionalStepsAfterCableDiag(TrcvIdx, &retVal);
      }
    }
  }
    /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_GET_CABLE_DIAGNOSTICS_RESULT, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_GetCableDiagnosticsResult() */ /* PRQA S 2006, 6030, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF*/

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_GetPhyIdentifier
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_GetPhyIdentifier(
    uint8 TrcvIdx,
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) OrgUniqueIdPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) ModelNrPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) RevisionNrPtr)
{
  /* ----- Local variables ---------------------------------------------- */
  uint16         idRegVal1;
  uint16         idRegVal2;
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;
  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if((OrgUniqueIdPtr == NULL_PTR) ||
          (ModelNrPtr     == NULL_PTR) ||
          (RevisionNrPtr  == NULL_PTR))
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* #20 Read the transceiver's registers */
    retVal = EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(TrcvIdx)(
        EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
        EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
        EthTrcv_30_Tja1100_LL_GetIdentifier1Register(TrcvIdx),
        &idRegVal1);

    retVal |= EthTrcv_30_Tja1100_GetReadTrcvRegisterFunc(TrcvIdx)(
        EthTrcv_30_Tja1100_GetHwIndex(TrcvIdx),
        EthTrcv_30_Tja1100_GetHwSubIndex(TrcvIdx),
        EthTrcv_30_Tja1100_LL_GetIdentifier2Register(TrcvIdx),
        &idRegVal2);

    if(retVal == E_OK)
    {
      /* #30 Retrieve the organizational unique identifier */
      *OrgUniqueIdPtr = (((uint32)(idRegVal1 & ETHTRCV_30_TJA1100_REG_PHYIDR1_OUI_LSB_MASK)) << ETHTRCV_30_TJA1100_REG_PHYIDR1_SHIFT_LSB) |
                         ((uint32)(idRegVal2 & ETHTRCV_30_TJA1100_REG_PHYIDR2_OUI_MSB_MASK)  >> ETHTRCV_30_TJA1100_REG_PHYIDR2_SHIFT_MSB);

      /* #40 Retrieve the model number */
      *ModelNrPtr = (uint8)((idRegVal2 & ETHTRCV_30_TJA1100_REG_PHYIDR2_TYPE_NO_MASK) >> ETHTRCV_30_TJA1100_REG_PHYIDR2_MODEL_NO_SHIFT);

      /* #50 Retrieve the revision number */
      *RevisionNrPtr = (uint8)(idRegVal2 & ETHTRCV_30_TJA1100_REG_PHYIDR2_REV_NO_MASK);
    }
  }
    /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_GET_PHY_IDENTIFIER, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_GetPhyIdentifier() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if ( ETHTRCV_30_TJA1100_WAKEUP_TYPE != ETHTRCV_WAKEUP_NOT_SUPPORTED )
/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_SetTransceiverWakeupMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_SetTransceiverWakeupMode(
    uint8 TrcvIdx,
    EthTrcv_WakeupModeType TrcvWakeupMode)
{
  /* ----- Local variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if((TrcvWakeupMode != ETHTRCV_WUM_DISABLE) &&
          (TrcvWakeupMode != ETHTRCV_WUM_ENABLE) &&
          (TrcvWakeupMode != ETHTRCV_WUM_CLEAR))
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_PARAM;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Check the parameter TrcvWakeupMode */
    switch( TrcvWakeupMode )
    {
      /* #30 In case TrcvWakeupMode is ETHTRCV_WUM_DISABLE */
      case ETHTRCV_WUM_DISABLE: /* #310 Do nothing */
      /* #40 In case TrcvWakeupMode is ETHTRCV_WUM_ENABLE */
      case ETHTRCV_WUM_ENABLE:
        /* #410 Set the global wakeup mode variable to ETHTRCV_WUM_ENABLE */
        EthTrcv_30_Tja1100_GetWakeupMode(TrcvIdx) = TrcvWakeupMode;
        retVal = E_OK;
        /* #420 Leave the function */
        break;
      /* #50 In case TrcvWakeupMode is ETHTRCV_WUM_CLEAR */
      case ETHTRCV_WUM_CLEAR:
        /* #510 Clear all wakeup reasons */
        EthTrcv_30_Tja1100_ClearWakeupReasons(TrcvIdx);
        RetVal = E_OK;
        /* #520 Leave the function */
        break;
      /* #60 In the default case */
      default:  /* PRQA S 2018 */ /* MS_MSR_14.1 */
        /* #610 Leave the function */
        break;
    }
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(
        ETHTRCV_30_TJA1100_MODULE_ID,
        TrcvIdx,
        ETHTRCV_30_TJA1100_SID_SET_TRANSCEIVER_WAKEUP_MODE,
        errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_SetTransceiverWakeupMode() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_GetTransceiverWakeupMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_GetTransceiverWakeupMode(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_WakeupModeType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) TrcvWakeupModePtr)
{
  /* ----- Local variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else if(TrcvWakeupModePtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Report the content of the global wakeup mode variable */
    *TrcvWakeupModePtr = EthTrcv_30_Tja1100_GetWakeupMode(TrcvIdx);
    retVal = E_OK;
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(
        ETHTRCV_30_TJA1100_MODULE_ID,
        TrcvIdx,
        ETHTRCV_30_TJA1100_SID_GET_TRANSCEIVER_WAKEUP_MODE,
        errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_GetTransceiverWakeupMode() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_CheckWakeup
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_CheckWakeup(
  uint8  TrcvIdx)
{
  /* ----- Local variables ---------------------------------------------- */
  Std_ReturnType retVal  = E_NOT_OK;
  uint8          errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else if(TrcvIdx >= ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_TRCV_IDX;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 The global wakup mode variable is ETHTRCV_WUM_ENABLE */
    if( EthTrcv_30_Tja1100_GetWakeupMode(TrcvIdx) == ETHTRCV_WUM_ENABLE )
    {
      /* #310 check for wakeup events and handle them */
      retVal = EthTrcv_30_Tja1100_InspectWakeupReasons(TrcvIdx);
      if( retVal == E_OK )
      {
        EthTrcv_30_Tja1100_ReportWakeup(TrcvIdx);
      }
    }
    else
    {
      retVal = E_OK;
    }
  }

#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, TrcvIdx, ETHTRCV_30_TJA1100_SID_CHECK_WAKEUP, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif

  return retVal;
} /* EthTrcv_30_Tja1100_CheckWakeup() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

#endif /* ETHTRCV_WAKEUP_NOT_SUPPORTED != ETHTRCV_30_TJA1100_WAKEUP_TYPE */
/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_MainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_MainFunction( void )
{
  /* ----- Local variables ---------------------------------------------- */
  uint8 trcvIdx;
  uint8 errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */

#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameters */
  if(EthTrcv_30_Tja1100_ModuleState == ETHTRCV_STATE_UNINIT)
  {
    errorId = ETHTRCV_30_TJA1100_E_NOT_INITIALIZED;
  }
  else
#endif /* ETHTRCV_30_TJA1100_DEV_ERROR_DETECT */
  {
    /* #20 Iterate over all configured transceivers */
    for(trcvIdx = 0; trcvIdx < ETHTRCV_30_TJA1100_MAX_TRCVS_TOTAL; trcvIdx++)
    {
      /* #220 Wakeup by polling is enabled */
#if ( ETHTRCV_WAKEUP_BY_POLLING == ETHTRCV_30_TJA1100_WAKEUP_TYPE)
      /* #2210 check for wakeup events and handle them */
      if( EthTrcv_30_Tja1100_InspectWakeupReasons(trcvIdx) == E_OK )
      {
        EthTrcv_30_Tja1100_ReportWakeup(trcvIdx);
      }
#endif /* ETHTRCV_WAKEUP_BY_POLLING == ETHTRCV_30_TJA1100_WAKEUP_TYPE */
      /* #40 Perform additional link handling actions */ /*lint -e{522} */
      EthTrcv_30_Tja1100_LL_MainFunctionLinkHandling(trcvIdx);
    }
  }

#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, 0, ETHTRCV_30_TJA1100_SID_MAIN_FUNCTION, errorId);
  }
#else
      ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif /* ETHTRCV_30_TJA1100_DEV_ERROR_REPORT */
} /* EthTrcv_30_Tja1100_MainFunction() */ /* PRQA S 2006, 6050, 6080 */ /* MD_MSR_14.7, MD_MSR_STCAL, MD_MSR_STMIF */

#if (ETHTRCV_30_TJA1100_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  EthTrcv_30_Tja1100_GetVersionInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

FUNC(void, ETHTRCV_30_TJA1100_CODE) EthTrcv_30_Tja1100_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, ETHTRCV_30_TJA1100_APPL_DATA) VersionInfoPtr)
{
  /* ----- Local variables ---------------------------------------------- */
  uint8 errorId = ETHTRCV_30_TJA1100_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check plausibility of input parameter */
  if(VersionInfoPtr == NULL_PTR)
  {
    errorId = ETHTRCV_30_TJA1100_E_INV_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #20 Report the module's version info */
    VersionInfoPtr->vendorID = ETHTRCV_30_TJA1100_VENDOR_ID;
    VersionInfoPtr->moduleID = ETHTRCV_30_TJA1100_MODULE_ID;
    VersionInfoPtr->sw_major_version = ETHTRCV_30_TJA1100_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = ETHTRCV_30_TJA1100_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = ETHTRCV_30_TJA1100_SW_PATCH_VERSION;
  }
  /* ----- Development Error Report --------------------------------------*/
#if ( ETHTRCV_30_TJA1100_DEV_ERROR_REPORT == STD_ON )
  if (errorId != ETHTRCV_30_TJA1100_E_NO_ERROR)
  {
    (void)Det_ReportError(ETHTRCV_30_TJA1100_MODULE_ID, 0, ETHTRCV_30_TJA1100_SID_GET_VERSION_INFO, errorId);
  }
#else
  ETHTRCV_30_TJA1100_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint !e438 */
#endif
} /* EthTrcv_30_Tja1100_GetVersionInfo */ /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* ETHTRCV_30_TJA1100_VERSION_INFO_API */

#define ETHTRCV_30_TJA1100_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_30_Tja1100.c
 *********************************************************************************************************************/
