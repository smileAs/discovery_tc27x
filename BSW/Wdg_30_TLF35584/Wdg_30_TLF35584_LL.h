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
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Wdg_30_TLF35584_LL.h
 *        \brief  Header file of Wdg_30_TLF35584_Timer
 *
 *      \details  This sub-component provides low level services to other sub-components. It manages hardware access of
 *                the module.
 *                This is an internal include file and shall not be included by other modules than Wdg_30_TLF35584.
 *
 *********************************************************************************************************************/

#if !(defined WDG_30_TLF35584_LL_H)
#define WDG_30_TLF35584_LL_H

#include "Wdg_30_TLF35584_Cfg.h"

#define WDG_30_TLF35584_MODES_ALL       (0x7u)

/*! /brief Bit-field that stores the supported modes */
#define WDG_30_TLF35584_SUPPORTED_MODES WDG_30_TLF35584_MODES_ALL

#define WDG_30_TLF35584_MODE_FAST       (0x4)
#define WDG_30_TLF35584_MODE_SLOW       (0x2)
#define WDG_30_TLF35584_MODE_OFF        (0x1)

/* PRQA S 3453 1 */ /* MD_MSR_19.6  */
#define WDG_30_TLF35584_IS_MODE_SUPPORTED(X) ((WDG_30_TLF35584_SUPPORTED_MODES & (X)) == (X))



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define WDG_30_TLF35584_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_Init()
 *********************************************************************************************************************/
/*! \brief       Function to initialize hardware-dependent functions of TLF35584.
 *  \return      E_OK on success.
 *               E_NOT_OK otherwise.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function prepares Gpt channel and SPI channel. Then it prepares the watchdog hardware and disables 
 *               the window watchdog (WDGIF_OFF_MODE) to synchronize with overlying sub-modules.
 *  \trace       CREQ-105559, DSGN-Wdg22909
 *********************************************************************************************************************/
FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_Init(void);


/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_TriggerHw()
 *********************************************************************************************************************/
/*! \brief       Function to trigger the window watchdog of TLF35584.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     According to the configuration this function triggers the window watchdog of TLF35584 via SPI or DIO.
 *               In case DIO is used for triggering it also is used to recover the DIO channel to DioLevel STD_HIGH 
 *               after the trigger. This is necessary due to the fact that only a falling edge on external PIN WDI is 
 *               recognized as a valid trigger signal. 
 *  \trace       CREQ-105563, DSGN-Wdg22903
 *********************************************************************************************************************/
FUNC(void, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_TriggerHw(void);


/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_SetHwMode()
 *********************************************************************************************************************/
/*! \brief       Function to set watchdog mode of TLF35584.
 *  \param[in]   Mode   Mode to which the watchdog hardware should be set
 *  \return      E_OK in case the mode change request was executed successfully.
 *  \pre         E_NOT_OK in case the mode change request was not successful.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function sets the timing of the window watchdog of TLF35584 according to the requested mode.
 *  \trace       CREQ-105560, DSGN-Wdg22902
 *********************************************************************************************************************/
FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_SetHwMode(WdgIf_ModeType Mode);


/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_StartTriggerTimer()
 *********************************************************************************************************************/
/*! \brief       Function to start trigger timer.
 *  \param[in]   Mode   Determines for which mode timing the trigger timer should be started.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function starts the Gpt channel referenced in Wdg_ConfigPtr. The callback function of this Gpt 
 *               channel is used to call the trigger function cyclically.
 *  \trace       DSGN-Wdg23011
 *********************************************************************************************************************/
FUNC(void, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_StartTriggerTimer(WdgIf_ModeType Mode);


/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_StopTriggerTimer()
 *********************************************************************************************************************/
/*! \brief       Function to stop trigger timer.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function stops the Gpt channel referenced in Wdg_ConfigPtr. The callback function of this Gpt 
 *               channel is used to call the trigger function cyclically.
 *  \trace       DSGN-Wdg23011
 *********************************************************************************************************************/
FUNC(void, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_StopTriggerTimer(void);

#define WDG_30_TLF35584_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* WDG_30_TLF35584_LL_H */

/**********************************************************************************************************************
 *  END OF FILE: Wdg_30_TLF35584_LL.h
 *********************************************************************************************************************/
