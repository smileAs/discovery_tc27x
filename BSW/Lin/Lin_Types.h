
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
 *  -------------------------------------------------------------------------------------------------------------------
 *           File:  Lin_Types.h
 *      Component:  AUTOSAR LIN Driver
 *         Module:  DrvLin_TricoreAsr
 *      Generator:  DrvLin_TricoreAsr
 *
 *  Target system:  Tricore
 *       Compiler:  Tasking
 *                  GNU
 *
 *    Derivatives:  TC2XX
 *  
 *    Description:  Type definitions of the AUTOSAR LIN Driver
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Lutz Pflueger                 vislpr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  04.00.00  2013-08-14  vislpr  ESCAN00069798 Implement new AUTOSAR 4, R7 LIN driver for Tricore Aurix
 *  05.00.00  2013-11-04  vislpr  ESCAN00071569 Implement AUTOSAR 4, R8  LIN driver for Tricore Aurix
 *                                ESCAN00070430 Enabling of the LIN Interface does not work
 *                                ESCAN00069442 Improve handling of BSW DBG Data
 *                                -             Improve frame handling at timing violation (frame delay)
 *            2013-11-12  vislpr  -             Justify Lin_Interrupt() due RTM complexity 
 *  06.00.00  2014-11-26  vislpr  -             R11, HL Part was updated
 *  07.00.00  2015-02-17  vislpr  ESCAN00081297 FEAT-427: SafeBSW Step I
 *  07.00.01  2015-03-16  vislpr  ESCAN00081849 Compiler error: Incompatible types at osWritePeripheral32() in Lin_Init()
 *  07.00.02  2015-06-23  vislpr  -             Update HL Part
 *  07.01.00  2015-07-08  vislpr  ESCAN00083857 Remove LinEnSettingOfISRConfiguration and LinEnSettingOfInputPinConfig switch
 *            2015-08-10  vislpr  ESCAN00081553 Value of BITCON.SM not clearly set
 *  07.01.01  2015-09-18  vislpr  -             Update HL Part
 *  07.01.02  2015-09-22  vislpr  ESCAN00085383 Compiler error:  #error "Source and Types Header are inconsistent (LIN_TPS_PATCH_VERSION)!"
 *  07.02.00  2016-01-19  vislpr  -             Update HL Part
 *  07.03.00  2016-04-13  vislpr  ESCAN00089454 Compiler error: Identifier "ApiId" is undefined
 *                                -             Update HL Part
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Friedrich Kiesel              visfki        Vector Informatik GmbH
 *  Lutz Pflueger                 vislpr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY - CORE -
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  04.00.00  2012-07-20  visfki  ESCAN00059300 Implementation of High Level AUTOSAR 4 LIN Driver
 *  04.01.00  2012-11-20  visfki  ESCAN00061782 AR4-220: Remove STATIC
 *                                ESCAN00063147 Rename Lin_WakeUp to Lin_Wakeup
 *  04.02.00  2013-02-08  visfki  ESCAN00064956 AR4-325: Implement Post-Build Loadable
 *                                ESCAN00065149 Compiler error: LIN_CH_OPERATIONAL changed in ASR4 to LIN_OPERATIONAL
 *  05.00.00  2013-09-19  vislpr  ESCAN00066851 Improve include structure for EcuM headers
 *                                ESCAN00079533 AR4-260: Remove ProdErrorDetection configuration switch
 *                                ESCAN00069952 Justify MISRA Warnings on functions
 *                                ESCAN00067708 AR4-328: Predefined Runtime Measurement Points
 *  05.00.01  2013-11-19  vislpr  ESCAN00071647 Remove MISRA warning 0850/3453
 *                                ESCAN00072030 Change RTM macros
 *  05.00.02  2013-11-21  vislpr  ESCAN00072030 Fix MISRA Warnings and GNU Compiler error on RTM
 *  06.00.00  2014-10-01  vislpr  ESCAN00076482 AR4-832: External wake up via LIN transceiver
 *                                ESCAN00078696 AR4-698: Post-Build Selectable (Identity Manager)
 *  06.00.01  2014-11-14  vislpr  ESCAN00079471 Compiler error: lin.c: 'Lin_Dev_InitDetect'/'LIN_DEV_INITVALUE'
 *  06.00.02  2014-11-14  vislpr  ESCAN00079588 Compiler error: Identifier Channel not declared
 *  06.00.03  2014-12-02  vislpr  -             Change wakeup handling
 *  07.00.00  2014-12-12  vislpr  ESCAN00080307 FEAT-427: SafeBSW Step I
 *  07.00.01  2015-01-27  vislpr  ESCAN00080823 Add channel DET check for out of bounds of channel id and channel idx
 *                        vislpr  ESCAN00080824 Use LOCAL_INLINE macro of Compiler.h instead "static inline"
 *  07.00.02  2015-03-26  vislpr  ESCAN00082080 Remove redundant code in Lin_GoToSleep
 *  07.00.03  2015-05-26  vislpr  ESCAN00083154 Dem.h not included if Dem repoting enabled
 *                        vislpr  ESCAN00083156 EcuM_BswErrorHook() are used on precompile with Selectable enabled
 *  07.01.00  2015-07-13  vislpr  ESCAN00081794 FEAT-1275: SafeBSW Step 2
 *  07.01.01  2015-09-15  vislpr  ESCAN00085267 Unkown return value 0x01u of Lin_GetStatus() in case of LIN_TX_BUSY error
 *  07.01.02  2015-10-23  vislpr  ESCAN00086056 Check data length parameter of Lin_SendFrame()
 *  07.02.00  2015-11-04  vislpr  ESCAN00086254 Unification the register base address struct and typedef for each driver
 *            2015-11-04  vislpr  ESCAN00086267 Code refactoring
 *            2015-11-16  vislpr  ESCAN00086493 Remove Lin_GetRxPin() Macro.
 *            2015-11-16  vislpr  ESCAN00086494 Do not set the state to wake after calling Lin_CheckWakeup()
 *            2015-11-17  vislpr  ESCAN00086546 Inconsistency of wakeup support between Lin, LinIf and EcuM in variant Post Build
 *  07.03.00  2016-01-27  vislpr  ESCAN00087812 FEAT-1688: SafeBSW Step 4
 *  07.03.01  2016-03-16  vislpr  -             SafeBSW review rework
 *  07.04.00  2016-04-13  vislpr  -             SafeBSW review rework (ISR)
 *  07.04.01  2016-05-23  vislpr  -             SafeBSW review rework
 *********************************************************************************************************************/

#if !defined (LIN_TYPES_H)
#define LIN_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/* include ComStack_Types.h so all needed types are known */
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "EcuM_Generated_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define LIN_TPS_MAJOR_VERSION 7
#define LIN_TPS_MINOR_VERSION 3
#define LIN_TPS_PATCH_VERSION 0

/* Compatibility defines */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
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
typedef volatile struct Lin_RegisterStructTag /*!< Hardware register layout */
{
  VAR(uint32, TYPEDEF) CLC;         /*!< Offset Address 0x0000: Clock Control Register */
  VAR(uint32, TYPEDEF) IOCR;        /*!< Offset Address 0x0004: Input Output Control Register */
  VAR(uint32, TYPEDEF) ID;          /*!< Offset Address 0x0008: Module Identification Register */
  VAR(uint32, TYPEDEF) TXFIFOCON;   /*!< Offset Address 0x000C: TX FIFO Configuration Register */
  VAR(uint32, TYPEDEF) RXFIFOCON;   /*!< Offset Address 0x0010: RX FIFO Configuration Register */
  VAR(uint32, TYPEDEF) BITCON;      /*!< Offset Address 0x0014: Bit Timing Configuration Register */
  VAR(uint32, TYPEDEF) FRAMECON;    /*!< Offset Address 0x0018: Frame Configuration Register */
  VAR(uint32, TYPEDEF) DATCON;      /*!< Offset Address 0x001C: Data Configuration Register */
  VAR(uint32, TYPEDEF) BRG;         /*!< Offset Address 0x0020: Baud Rate Generation Register */
  VAR(uint32, TYPEDEF) BRD;         /*!< Offset Address 0x0024: Baud Rate Detection Register */
  VAR(uint32, TYPEDEF) LINCON;      /*!< Offset Address 0x0028: LIN Configuration Register */
  VAR(uint32, TYPEDEF) LINBTIMER;   /*!< Offset Address 0x002C: LIN Break Timer Register */
  VAR(uint32, TYPEDEF) LINHTIMER;   /*!< Offset Address 0x0030: LIN Header Timer Register */
  VAR(uint32, TYPEDEF) FLAGS;       /*!< Offset Address 0x0034: Flags Register */
  VAR(uint32, TYPEDEF) FLAGSSET;    /*!< Offset Address 0x0038: Flags Set Register */
  VAR(uint32, TYPEDEF) FLAGSCLEAR;  /*!< Offset Address 0x003C: Flags Clear Register */
  VAR(uint32, TYPEDEF) FLAGSENABLE; /*!< Offset Address 0x0040: Flags Enable Register */
  VAR(uint32, TYPEDEF) TXDATA;      /*!< Offset Address 0x0044: Transmit Data Register */
  VAR(uint32, TYPEDEF) RXDATA;      /*!< Offset Address 0x0048: Receive Data Register */
  VAR(uint32, TYPEDEF) CSR;         /*!< Offset Address 0x004C: Clock Selection Register */
} Lin_RegisterStruct;
 
/**********************************************************************************************************************
 *  TYPE AND DEFINE DEFINITIONS FOR INTERNAL USE IN LIN DRIVER
 *********************************************************************************************************************/
/*! Pointer to hardware register base address of channel. */
typedef Lin_RegisterStruct* Lin_RegisterStructPtr;
 
/*! Buffer size for frame data */
#define Lin_ChannelDataBufferSize 0x08u

/*! Buffer type for frame data (for using in ComStackLib) */
typedef uint8 Lin_DataBufferType[Lin_ChannelDataBufferSize];

#endif /* LIN_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Lin_Types.h
 *********************************************************************************************************************/

