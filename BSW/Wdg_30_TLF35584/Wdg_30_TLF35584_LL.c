/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Wdg_30_TLF35584_LL.c
 *        \brief  Implementation of sub-module Wdg_30_TLF35584_LL
 *                This is an internal include file and shall not be included by other modules than Wdg_30_TLF35584.
 *
 *      \details  This sub-module provides low level services to other sub-modules. It manages hardware access of
 *                the module.
 *
 *********************************************************************************************************************/

#define WDG_30_TLF35584_SOURCE

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Wdg_30_TLF35584_Cfg.h"
#include "Wdg_30_TLF35584_LL.h"
#include "Wdg_30_TLF35584_TrgCnd.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (WDG_30_TLF35584_LOCAL) /* COV_WDG_30_TLF35584_COMPATIBILITY */
# define WDG_30_TLF35584_LOCAL static
#endif

#if !defined (WDG_30_TLF35584_LOCAL_INLINE) /* COV_WDG_30_TLF35584_COMPATIBILITY */
# define WDG_30_TLF35584_LOCAL_INLINE LOCAL_INLINE
#endif

typedef struct
{
  uint8 SYSPCFG0;
  uint8 SYSPCFG1;
  uint8 WDCFG0;
  uint8 WDCFG1;
  uint8 WWDCFG0;
  uint8 WWDCFG1;
} Wdg_30_TLF35584_ProtReg_Type;

/**********************************************************************************************************************
 * LOCAL VARIABLES
 *********************************************************************************************************************/
#define WDG_30_TLF35584_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if(WDG_30_TLF35584_TRIGGER_DIO == STD_ON)
WDG_30_TLF35584_LOCAL VAR(Dio_LevelType, WDG_30_TLF35584_VAR_INIT) Wdg_30_TLF35584_LL_pendingEdge = STD_LOW;
#endif

#define WDG_30_TLF35584_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define WDG_30_TLF35584_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

WDG_30_TLF35584_LOCAL VAR(Wdg_30_TLF35584_ProtReg_Type, WDG_30_TLF35584_VAR_INIT) Wdg_30_TLF35584_ProtReg;
WDG_30_TLF35584_LOCAL VAR(uint16, WDG_30_TLF35584_VAR_INIT) Wdg_30_TLF35584_Wdg_SpiOutBuffer = 0;
WDG_30_TLF35584_LOCAL VAR(uint16, WDG_30_TLF35584_VAR_INIT) Wdg_30_TLF35584_Wdg_SpiInBuffer = 0;

#define WDG_30_TLF35584_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

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

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Read/ Write masks masks */
#define WDG_30_TLF35584_LL_MASK_SPIADDR                    (0x3Fu)     /*!< Masks address from address byte (1 Byte) */
#define WDG_30_TLF35584_LL_MASK_SPIDATA_RAW                (0x01FEu)   /*!< Masks data from complete SPI sequence (2 Bytes) */
#define WDG_30_TLF35584_LL_MASK_CMD_WRITE_RAW              (0x8000u)   /*!< Masks CMD bit from complete SPI sequence (2 Bytes) */

/*! Protected registers addresses */
#define WDG_30_TLF35584_LL_REG_ADDR_SYSPCFG0               (0x04u)     /*!< Protected System configuration request 0 */
#define WDG_30_TLF35584_LL_REG_ADDR_SYSPCFG1               (0x05u)     /*!< Protected System configuration request 1 */
#define WDG_30_TLF35584_LL_REG_ADDR_WDCFG0                 (0x06u)     /*!< Protected Watchdog configuration request 0 */
#define WDG_30_TLF35584_LL_REG_ADDR_WDCFG1                 (0x07u)     /*!< Protected Watchdog configuration request 1 */
#define WDG_30_TLF35584_LL_REG_ADDR_FWDCFG                 (0x08u)     /*!< Protected Functional watchdog configuration request */
#define WDG_30_TLF35584_LL_REG_ADDR_WWDCFG0                (0x09u)     /*!< Protected Window watchdog configuration request 0*/
#define WDG_30_TLF35584_LL_REG_ADDR_WWDCFG1                (0x0Au)     /*!< Protected Window watchdog configuration request 1*/

/*! Main registers addresses */
#define WDG_30_TLF35584_LL_REG_ADDR_PROTCFG                (0x03u)     /*!< Protected register */
#define WDG_30_TLF35584_LL_REG_ADDR_RSYSPCFG0              (0x0Bu)     /*!< System configuration 0 status */
#define WDG_30_TLF35584_LL_REG_ADDR_RSYSPCFG1              (0x0Cu)     /*!< System configuration 1 status */
#define WDG_30_TLF35584_LL_REG_ADDR_RWDCFG0                (0x0Du)     /*!< Watchdog configuration 0 status */
#define WDG_30_TLF35584_LL_REG_ADDR_RWDCFG1                (0x0Eu)     /*!< Watchdog configuration 1 status */
#define WDG_30_TLF35584_LL_REG_ADDR_RFWDCFG                (0x0Fu)     /*!< Functional watchdog configuration status */
#define WDG_30_TLF35584_LL_REG_ADDR_RWWDCFG0               (0x10u)     /*!< Window watchdog configuration status 0 */
#define WDG_30_TLF35584_LL_REG_ADDR_RWWDCFG1               (0x11u)     /*!< Window watchdog configuration status 1 */

#define WDG_30_TLF35584_LL_REG_ADDR_DEVCTRL                (0x15u)     /*!< Device control request */
#define WDG_30_TLF35584_LL_REG_ADDR_DEVCTRLN               (0x16u)     /*!< Device control inverted request */

#define WDG_30_TLF35584_LL_REG_ADDR_WWDSCMD                (0x17u)     /*!< Window watchdog service command */
#define WDG_30_TLF35584_LL_REG_ADDR_WWDSTAT                (0x29u)     /*!< Window watchdog status */

/*! PROTCFG register bit masks */
#define WDG_30_TLF35584_LL_REG_MASK_PROTCFG_KEY            (0xFF)      /*!< PROTCFG:0:7 Key to lock/unlock protected registers */

/*! SYSPCFG1 register bit masks */
#define WDG_30_TLF35584_LL_REG_MASK_SYSPCFG1_ERREN         (0x08u)     /*!< SYSPCFG1:3:3 Enable ERR pin monitor*/

/*! WDCFG0 register bit masks */
#define WDG_30_TLF35584_LL_REG_MASK_WDCFG0_WDCYC           (0x01u)     /*!< WDCFG0:0:0 Watchdog cycle time */
#define WDG_30_TLF35584_LL_REG_MASK_WDCFG0_WWDTSEL         (0x02u)     /*!< WDCFG0:1:1 Window watchdog trigger selection */
#define WDG_30_TLF35584_LL_REG_MASK_WDCFG0_WWDEN           (0x08u)     /*!< WDCFG0:3:3 Window watchdog enable */
#define WDG_30_TLF35584_LL_REG_MASK_WDCFG0_ERRTRH          (0xF0u)     /*!< WDCFG0:4:7 Window watchdog error threshold */

/*! WWDSCMD register bit masks */
#define WDG_30_TLF35584_LL_REG_MASK_WWDSCMD_TRIG           (0x01u)     /*!< WWDSCMD:0:0 WWD trigger command to trigger WWD*/
#define WDG_30_TLF35584_LL_REG_MASK_WWDSCMD_TRIG_STATUS    (0x80u)     /*!< WWDSCMD:7:7 Last internal trigger value received via SPI */

/* Protection register values */
 #define WDG_30_TLF35584_LL_REG_CMD_PROTCFG_UNLOCK_SEQ1    (0xABu)     /*!< First byte of consecutive unlock sequence */
 #define WDG_30_TLF35584_LL_REG_CMD_PROTCFG_UNLOCK_SEQ2    (0xEFu)     /*!< Second byte of consecutive unlock sequence */
 #define WDG_30_TLF35584_LL_REG_CMD_PROTCFG_UNLOCK_SEQ3    (0x56u)     /*!< Third byte of consecutive unlock sequence */
 #define WDG_30_TLF35584_LL_REG_CMD_PROTCFG_UNLOCK_SEQ4    (0x12u)     /*!< Fourth byte of consecutive unlock sequence */

 #define WDG_30_TLF35584_LL_REG_CMD_PROTCFG_LOCK_SEQ1      (0xDFu)     /*!< First byte of consecutive lock sequence */
 #define WDG_30_TLF35584_LL_REG_CMD_PROTCFG_LOCK_SEQ2      (0x34u)     /*!< Second byte of consecutive lock sequence */
 #define WDG_30_TLF35584_LL_REG_CMD_PROTCFG_LOCK_SEQ3      (0xBEu)     /*!< Third byte of consecutive lock sequence */
 #define WDG_30_TLF35584_LL_REG_CMD_PROTCFG_LOCK_SEQ4      (0xCAu)     /*!< Fourth byte of consecutive lock sequence */

/* compatibility defines for SPI API mapping */
#if !defined(Wdg_30_TLF35584_LL_SpiSetupEB)
# define Wdg_30_TLF35584_LL_SpiSetupEB Spi_SetupEB
#endif

#if !defined(Wdg_30_TLF35584_LL_SpiSyncTransmit)
# define Wdg_30_TLF35584_LL_SpiSyncTransmit Spi_SyncTransmit
#endif

#if !defined(WDG_30_TLF35584_LL_SPI_TRANSFER_LENGTH)
# define WDG_30_TLF35584_LL_SPI_TRANSFER_LENGTH 1
#endif

#if !defined(Wdg_30_TLF35584_LL_SpiDataType)
# define Wdg_30_TLF35584_LL_SpiDataType Spi_DataType
#endif

/**********************************************************************************************************************
 * FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 6 */ /* MD_Wdg_30_TLF35584_3453 */
#define Wdg_30_TLF35584_LL_MkWrCommand(addr, data)       (uint16) ( ( ( ( ( (addr) & 0xFFu) << 8) | ((uint16)(data) & 0xFFu) ) << 1) | WDG_30_TLF35584_LL_MASK_CMD_WRITE_RAW)
#define Wdg_30_TLF35584_LL_MkRdCommand(addr)             (uint16)( ( (addr) & WDG_30_TLF35584_LL_MASK_SPIADDR) << 9)

#define Wdg_30_TLF35584_LL_ReadRegister(addr, target)               Wdg_30_TLF35584_LL_AccessRegister(Wdg_30_TLF35584_LL_MkRdCommand((addr)), (target))
#define Wdg_30_TLF35584_LL_WriteRegister(addr, data)                Wdg_30_TLF35584_LL_AccessRegister(Wdg_30_TLF35584_LL_MkWrCommand((addr), (data)), NULL_PTR)
#define Wdg_30_TLF35584_LL_ReadWriteRegister(addr, data, target)    Wdg_30_TLF35584_LL_AccessRegister(Wdg_30_TLF35584_LL_MkWrCommand((addr), (data)), (target))

#define Wdg_30_TLF35584_LL_updatePendingEdge()           Wdg_30_TLF35584_LL_pendingEdge = ~(Wdg_30_TLF35584_LL_pendingEdge)

/**********************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_UnlockRegisters
 *********************************************************************************************************************/
/*! \brief       Unlock and read protected registers of TLF35584.
 *  \return      E_OK on success.
 *               E_NOT_OK otherwise.
 *  \pre         - 
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function writes the UNLOCK sequence to protection register and reads the contents of the protected
 *               registers to the members of Wdg_30_TLF35584_ProtReg.
 *********************************************************************************************************************/
WDG_30_TLF35584_LOCAL_INLINE FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_UnlockRegisters(void);

/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_LockRegisters
 *********************************************************************************************************************/
/*! \brief       Lock protected registers of TLF35584.
 *  \return      E_OK on success.
 *               E_NOT_OK otherwise.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This function writes the contents of Wdg_30_TLF35584_ProtReg members to the hardware. Additionally 
 *               it writes the LOCK sequence to protection register which stores the changes in hardware registers.
 *********************************************************************************************************************/
WDG_30_TLF35584_LOCAL_INLINE FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_LockRegisters(void);

/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_CalcParity
 *********************************************************************************************************************/
/*! \brief       Calculate parity bit for SPI command.
 *  \return      Data intended to be written to TLF35584 via SPI including the parity bit.
 *  \param[in]   in   Data intended to be written to TLF35584 via SPI.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \details     This function calculates the parity bit for a passed SPI command.
 *********************************************************************************************************************/
WDG_30_TLF35584_LOCAL_INLINE FUNC(uint16, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_CalcParity(uint16 in);

/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_AccessRegister
 *********************************************************************************************************************/
/*! \brief       Function to send SPI command to SPI target
 *  \return      E_OK on success.
 *               E_NOT_OK otherwise.
 *  \param[in]   cmd     Command to write to SPI target
 *  \param[out]  target  Pointer to where to store the data written back from SPI target
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \details     This functions sends an SPI command to the target and stores the returned data to a given pointer.
 *********************************************************************************************************************/
WDG_30_TLF35584_LOCAL_INLINE FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_AccessRegister(
  CONST(uint16, AUTOMATIC) cmd,
  P2VAR(uint8, AUTOMATIC, WDG_30_TLF35584_APPL_DATA) target
);

/**********************************************************************************************************************
 * GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define WDG_30_TLF35584_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Wdg_30_TLF35584_LL_Wdg_30_TLF35584Trigger()
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
 */

FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_Init(void)
{
  Std_ReturnType result;

  /* #10 Enable Gpt notification */
  Gpt_EnableNotification(Wdg_30_TLF35584_ConfigPtr->TriggerTimer);

  /* #15 Setup SPI buffer */
  result = Wdg_30_TLF35584_LL_SpiSetupEB( /* SBSW_TLF35584_CALL_SPI_SETUPEB */
    Wdg_30_TLF35584_ConfigPtr->SpiChl, 
    (Wdg_30_TLF35584_LL_SpiDataType *) &Wdg_30_TLF35584_Wdg_SpiOutBuffer, 
    (Wdg_30_TLF35584_LL_SpiDataType *) &Wdg_30_TLF35584_Wdg_SpiInBuffer, 
    WDG_30_TLF35584_LL_SPI_TRANSFER_LENGTH
  ); 

  if(result == E_OK)
  {

    /* #20 Unlock protected registers */
    result = Wdg_30_TLF35584_LL_UnlockRegisters();

    /* #30 Set WWDETHR to configured error threshold */
    Wdg_30_TLF35584_ProtReg.WDCFG0 = ((Wdg_30_TLF35584_ProtReg.WDCFG0 & ~(WDG_30_TLF35584_LL_REG_MASK_WDCFG0_ERRTRH)) | (Wdg_30_TLF35584_ConfigPtr->WwdEthr << 4));

#if(WDG_30_TLF35584_TRIGGER_DIO == STD_ON)
    /* #32 If WWD shall be triggered via external WDI pin, select WDI as trigger */
    Wdg_30_TLF35584_ProtReg.WDCFG0 &= (uint8)~(WDG_30_TLF35584_LL_REG_MASK_WDCFG0_WWDTSEL);
#endif

    /* #34 Disable watchdog */
    Wdg_30_TLF35584_ProtReg.WDCFG0 &= (uint8)~(WDG_30_TLF35584_LL_REG_MASK_WDCFG0_WWDEN);

    /* #40 Set ERR pin monitoring */
    Wdg_30_TLF35584_ProtReg.SYSPCFG1 = ((Wdg_30_TLF35584_ProtReg.SYSPCFG1 & ~(WDG_30_TLF35584_LL_REG_MASK_SYSPCFG1_ERREN)) | (Wdg_30_TLF35584_ConfigPtr->WdErrEn));

    /* #50 Lock protected registers */
    result |= Wdg_30_TLF35584_LL_LockRegisters();

  }

  if(result == E_OK)
  {

    /* #60 Initial trigger (necessary to leave the Long Open Window) */
    Wdg_30_TLF35584_LL_TriggerHw();

#if(WDG_30_TLF35584_GOTO_NORMAL == STD_ON)
    /* #70 If configured, request state transition INIT -> NORMAL */
    result = Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_DEVCTRL, Wdg_30_TLF35584_ConfigPtr->RegValDEVCTRL); /* SBSW_TLF35584_NULLPTR_PARAM */
    result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_DEVCTRLN, ~(Wdg_30_TLF35584_ConfigPtr->RegValDEVCTRL)); /* SBSW_TLF35584_NULLPTR_PARAM */

#endif
  }

  return result;
}

/**********************************************************************************************************************
 *  Wdg_30_TLF35584_LL_TriggerHw()
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
FUNC(void, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_TriggerHw(void)
{
#if(WDG_30_TLF35584_TRIGGER_DIO == STD_ON)
  /* #10 If watchdog is triggered via external WDI pin */

  /* #12 Write pending edge to configured trigger DIO channel */
  Dio_WriteChannel(Wdg_30_TLF35584_ConfigPtr->DioPinWDI, Wdg_30_TLF35584_LL_pendingEdge);

  /* #14 Prepare pending edge for next trigger */
  Wdg_30_TLF35584_LL_updatePendingEdge();

#else
  /* #20 Otherwise */
  VAR(uint8, WDG_30_TLF35584_CODE) wwdscmdContent;

  /* #22 Read content of WWDSCMD */
  (void)Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_WWDSCMD, &wwdscmdContent); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */

  /* #24 Write answer back to WWDSCMD */
  (void)Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_WWDSCMD, (WDG_30_TLF35584_LL_REG_MASK_WWDSCMD_TRIG & (uint8)~(wwdscmdContent>>7))); /* SBSW_TLF35584_NULLPTR_PARAM */
#endif

}

/**********************************************************************************************************************
 *  Wdg_30_TLF35584_LL_SetHwMode()
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
FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_SetHwMode(WdgIf_ModeType Mode)
{
  VAR(uint8, WDG_30_TLF35584_CODE) modeIdx;
  VAR(uint8, WDG_30_TLF35584_CODE) result = E_OK;

  /* #10 Unlock protected registers */
  result |= Wdg_30_TLF35584_LL_UnlockRegisters();

  switch(Mode)
  {
    /* #20 If requested mode is WDGIF_OFF_MODE, disable watchdog */
    case WDGIF_OFF_MODE:
      Wdg_30_TLF35584_ProtReg.WDCFG0 &= (uint8)~(WDG_30_TLF35584_LL_REG_MASK_WDCFG0_WWDEN);
      break;

    /* #30 Otherwise configure watchdog according the requested mode */
    default: /* WDGIF_SLOW_MODE, WDGIF_FAST_MODE */

      /* PRQA S 3382 3 */ /* MD_Wdg_30_TLF35584_3382 */
      /* PRQA S 3689 2 */ /* MD_Wdg_30_TLF35584_3689 */
      modeIdx = WDG_30_TLF35584_MODE_INDEX(Mode);

      /* Set Wd enable */
      Wdg_30_TLF35584_ProtReg.WDCFG0 |= WDG_30_TLF35584_LL_REG_MASK_WDCFG0_WWDEN;

      /* Set Wd cycle */
      Wdg_30_TLF35584_ProtReg.WDCFG0 = ((Wdg_30_TLF35584_ProtReg.WDCFG0 & ~(WDG_30_TLF35584_LL_REG_MASK_WDCFG0_WDCYC)) | Wdg_30_TLF35584_ConfigPtr->WdCycVal[modeIdx]);

      /* Set open/closed window time */
      Wdg_30_TLF35584_ProtReg.WWDCFG0 = Wdg_30_TLF35584_ConfigPtr->CwVal[modeIdx];
      Wdg_30_TLF35584_ProtReg.WWDCFG1 = Wdg_30_TLF35584_ConfigPtr->OwVal[modeIdx];
      break;
  }

  /* #40 Lock protected registers */
  result |= Wdg_30_TLF35584_LL_LockRegisters();

  /* #50 Trigger watchdog */
  Wdg_30_TLF35584_LL_TriggerHw();

#if(WDG_30_TLF35584_TRIGGER_DIO == STD_ON)
  /* #60 If watchdog is triggered, prepare pending trigger as falling edge for trigger DIO channel */
  Dio_WriteChannel(Wdg_30_TLF35584_ConfigPtr->DioPinWDI, STD_HIGH);
  Wdg_30_TLF35584_LL_pendingEdge = STD_LOW;
#endif

  return result;
}

/**********************************************************************************************************************
 *  Wdg_30_TLF35584_LL_StartTriggerTimer()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_StartTriggerTimer(WdgIf_ModeType Mode)
{
  /* PRQA S 3382 4 */ /* MD_Wdg_30_TLF35584_3382 */
  /* PRQA S 3689 3 */ /* MD_Wdg_30_TLF35584_3689 */
  Gpt_StartTimer(
    Wdg_30_TLF35584_ConfigPtr->TriggerTimer,
    Wdg_30_TLF35584_ConfigPtr->TriggerTimerCounter[WDG_30_TLF35584_MODE_INDEX(Mode)]
  );
}

/**********************************************************************************************************************
 *  Wdg_30_TLF35584_LL_StopTriggerTimer()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_StopTriggerTimer(void)
{
  /* #10 Stop trigger timer */
  Gpt_StopTimer(Wdg_30_TLF35584_ConfigPtr->TriggerTimer);
}

/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_UnlockRegisters
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
WDG_30_TLF35584_LOCAL_INLINE FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_UnlockRegisters(void)
{

  VAR(Std_ReturnType, WDG_30_TLF35584_CODE) result;

  /*  #10 Write UNLOCK pattern to Protection register */
  result = Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_PROTCFG, WDG_30_TLF35584_LL_REG_CMD_PROTCFG_UNLOCK_SEQ1); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_PROTCFG, WDG_30_TLF35584_LL_REG_CMD_PROTCFG_UNLOCK_SEQ2); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_PROTCFG, WDG_30_TLF35584_LL_REG_CMD_PROTCFG_UNLOCK_SEQ3); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_PROTCFG, WDG_30_TLF35584_LL_REG_CMD_PROTCFG_UNLOCK_SEQ4); /* SBSW_TLF35584_NULLPTR_PARAM */

  /* #20 Read values of protected registers */
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_RSYSPCFG0, &Wdg_30_TLF35584_ProtReg.SYSPCFG0); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_RSYSPCFG1, &Wdg_30_TLF35584_ProtReg.SYSPCFG1); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_RWDCFG0, &Wdg_30_TLF35584_ProtReg.WDCFG0); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_RWDCFG1, &Wdg_30_TLF35584_ProtReg.WDCFG1); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_RWWDCFG0, &Wdg_30_TLF35584_ProtReg.WWDCFG0); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_RWWDCFG1, &Wdg_30_TLF35584_ProtReg.WWDCFG1); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */

  return result;
}

/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_LockRegisters
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
WDG_30_TLF35584_LOCAL_INLINE FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_LockRegisters(void)
{

  VAR(Std_ReturnType, WDG_30_TLF35584_CODE) result;
  VAR(uint8, WDG_30_TLF35584_CODE) tmpRegContent;
  VAR(uint8, WDG_30_TLF35584_CODE) checkSum = 0xFF;

  /* #10 Write values to protected registers */
  result = Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_SYSPCFG0, Wdg_30_TLF35584_ProtReg.SYSPCFG0); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_SYSPCFG1, Wdg_30_TLF35584_ProtReg.SYSPCFG1); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_WDCFG0, Wdg_30_TLF35584_ProtReg.WDCFG0); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_WDCFG1, Wdg_30_TLF35584_ProtReg.WDCFG1); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_WWDCFG0, Wdg_30_TLF35584_ProtReg.WWDCFG0); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_WWDCFG1, Wdg_30_TLF35584_ProtReg.WWDCFG1); /* SBSW_TLF35584_NULLPTR_PARAM */

  /* #20 Read back configuration and validate values */
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_SYSPCFG0, &tmpRegContent); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  checkSum &= Wdg_30_TLF35584_ProtReg.SYSPCFG0 ^ tmpRegContent;
  
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_SYSPCFG1, &tmpRegContent); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  checkSum &= Wdg_30_TLF35584_ProtReg.SYSPCFG1 ^ tmpRegContent;
  
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_WDCFG0, &tmpRegContent); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  checkSum &= Wdg_30_TLF35584_ProtReg.WDCFG0 ^ tmpRegContent;
  
  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_WDCFG1, &tmpRegContent); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  checkSum &= Wdg_30_TLF35584_ProtReg.WDCFG1 ^ tmpRegContent;

  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_WWDCFG0, &tmpRegContent); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  checkSum &= Wdg_30_TLF35584_ProtReg.WWDCFG0 ^ tmpRegContent;

  result |= Wdg_30_TLF35584_LL_ReadRegister(WDG_30_TLF35584_LL_REG_ADDR_WWDCFG1, &tmpRegContent); /* SBSW_WDG_30_TLF35584_LOCALPTR_PARAM */
  checkSum &= Wdg_30_TLF35584_ProtReg.WWDCFG1 ^ tmpRegContent;

  if(checkSum != 0xFF)
  {
    result |= E_NOT_OK;
  }

  /* #30 Write LOCK pattern to protection register */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_PROTCFG, WDG_30_TLF35584_LL_REG_CMD_PROTCFG_LOCK_SEQ1); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_PROTCFG, WDG_30_TLF35584_LL_REG_CMD_PROTCFG_LOCK_SEQ2); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_PROTCFG, WDG_30_TLF35584_LL_REG_CMD_PROTCFG_LOCK_SEQ3); /* SBSW_TLF35584_NULLPTR_PARAM */
  result |= Wdg_30_TLF35584_LL_WriteRegister(WDG_30_TLF35584_LL_REG_ADDR_PROTCFG, WDG_30_TLF35584_LL_REG_CMD_PROTCFG_LOCK_SEQ4); /* SBSW_TLF35584_NULLPTR_PARAM */

  return result;
}

/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_CalcParity
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
WDG_30_TLF35584_LOCAL_INLINE FUNC(uint16, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_CalcParity(uint16 in)
{
  uint8 i;
  uint16 res=0;
  for(i=0;i<16;i++)
  {
      res = res ^ ((in >> i) & 0x01);
  }
  return (((in & (~(0x1u))) | res));
}

/**********************************************************************************************************************
 * Wdg_30_TLF35584_LL_AccessRegister
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
WDG_30_TLF35584_LOCAL_INLINE FUNC(Std_ReturnType, WDG_30_TLF35584_CODE) Wdg_30_TLF35584_LL_AccessRegister(
  CONST(uint16, AUTOMATIC) cmd,
  P2VAR(uint8, AUTOMATIC, WDG_30_TLF35584_APPL_DATA) target)
{
  VAR(Std_ReturnType, WDG_30_TLF35584_CODE) result;

  /* #10 Calculate parity for command */
  Wdg_30_TLF35584_Wdg_SpiOutBuffer = Wdg_30_TLF35584_LL_CalcParity(cmd);

  /* #20 Write command via SPI */
  result = Wdg_30_TLF35584_LL_SpiSyncTransmit(Wdg_30_TLF35584_ConfigPtr->SpiSeq);

  /* #30 If parameter target is not a NULL_PTR, write read back value to pointer */
  if(target != NULL_PTR)
  {
    *target  = (uint8) ((Wdg_30_TLF35584_Wdg_SpiInBuffer  & (uint16)WDG_30_TLF35584_LL_MASK_SPIDATA_RAW) >> 1); /* SBSW_TLF35584_VALID_TARGETPTR */
  }

  return result;
}

#define WDG_30_TLF35584_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:

MD_Wdg_30_TLF35584_3453: MISRA Rule 19.7
  Reason: Complex macros used to optimize code runtime.
  Risk: Readability reduced.
  Prevention: Code inspection.

MD_Wdg_30_TLF35584_3382:
 Misra Rule 21.1
 Reason: '#define WDG_30_TLF35584_MODE_INDEX(X) (uint8)(X)-1u' is used to calculate a corresponding array index
 for a passed mode. If the macro would be used with X = WDGIF_OFF_MODE (0) a wrap-around would happen.
 As the macro only is used with X = WDGIF_SLOW_MODE (1) or WDGIF_FAST_MODE (2) this wrap-around never
 will  happen.
 Risk: No risk.
 Prevention: Code inspection.

MD_Wdg_30_TLF35584_3689:
 Misra Rule 21.1
 Reason: '#define WDG_30_TLF35584_MODE_INDEX(X) (uint8)(X)-1u' is used to calculate a corresponding array index
 for a passed mode. If the macro would be used with X = WDGIF_OFF_MODE (0) an access outside the array
 boundaries would happen. As the macro only is used with X = WDGIF_SLOW_MODE (1) or WDGIF_FAST_MODE (2)
 the access will always be inside the array boundaries.
 Risk: No risk.
 Prevention: Code inspection.

*/

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_TLF35584_CALL_SPI_SETUPEB
    \DESCRIPTION SPI API function Spi_SetupEB is called with parameter 'Channel', 'SrcDataBufferPtr',
        'DesDataBufferPtr' and 'Length'.
    \COUNTERMEASURE \N SrcDataBufferPtr is a pointer to const and its content cannot be modified by the callee.
        For DesDataBufferPtr a pointer to one element of the Wdg_30_TLF35584_Wdg_SpiOutBuffer is passed.

  \ID SBSW_WDG_30_TLF35584_LOCALPTR_PARAM
    \DESCRIPTION Static functions are called with a local pointer as a parameter.
    \COUNTERMEASURE \N The static function is only called with valid pointers to local parameters.

  \ID SBSW_TLF35584_NULLPTR_PARAM
    \DESCRIPTION Static function Wdg_30_TLF35584_LL_AccessRegister is called with a null pointer as a parameter.
    \COUNTERMEASURE \R A 'if-condition' ensures that in case of a null pointer the parameter 'target' is not used.

  \ID SBSW_TLF35584_VALID_TARGETPTR
    \DESCRIPTION Array access or function call using parameter 'target'.
    \COUNTERMEASURE \N The caller ensures that the pointer 'target' that is used as parameter is valid.

SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION

  \ID COV_WDG_30_TLF35584_COMPATIBILITY
  \ACCEPT TX
  \REASON [COV_MSR_COMPATIBILITY]

END_COVERAGE_JUSTIFICATION */

/**********************************************************************************************************************
 *  END OF FILE: Wdg_30_TLF35584_LL.c
 *********************************************************************************************************************/
