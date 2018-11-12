
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
  \file  File:  BrsHw.c
      Project:  Vector Basic Runtime System
       Module:  BrsHw for Platform Infineon Aurix
     Template:  This file is reviewed according to zBrs_Template@root[2.01.00]

  \brief Description:  This is the hardware specific code file for Vector Basic Runtime System (BRS).
                       This file supports: see BrsHw_DerivativeList.h

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
  Timo Müller                   vistir        Vector Informatik GmbH
  Abir Bazzi                    vadaba        Vector Informatik GmbH
  Daniel Kuhnle                 viskdl        Vector Informatik GmbH
  Jens Haerer                   visjhr        Vector Informatik GmbH
  Volker Kaiser                 viskvr        Vector Informatik GmbH
  Sascha Mauser                 vismaa        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2014-09-04  visbwa  First Version (derived from zBrs_Tricore 2.01.24)
  01.00.00  2014-10-30  vistir  Added new BrsHwPllInitPowerOn()
                                Added PortInitPowerOn() for CAN2 and CAN3
                                Introduced BRS_DERIVATIVE_TC21X and BRS_DERIVATIVE_TC22X
                                Removed PLL_ERAY support for TC21x and TC22x (no PLL_ERAY available for them)
  01.00.00  2014-11-25  visbwa  Final review for first version; adopted Eth support
  01.00.01  2014-11-25  visbwa  fixed encapsulation of BrsHwFrLine0Interrupt()
  01.00.02  2014-12-02  visbwa  fixed wrong BrsHwRestoreInterrupt() implementation
  01.00.03  2015-02-13  vadaba  Introduced BRS_OSC_CLK = 16 MHZ and separated BrsHwErayPllInitPowerOn() from 
                                BrsHwPllInitPowerOn()
  01.00.04  2015-02-23  vistir  Bugfix within BrsHwPllInitPowerOn(), rework of BrsHwErayPllInitPowerOn()
  01.00.05  2015-02-24  visbwa  Review
  01.00.06  2015-04-09  visbwa  Added support for DrvPort and DrvDio within LED-support
  01.00.07  2015-04-13  viskdl  Bugfix within BrsHwErayPllInitPowerOn() (PLLPWD)
  01.00.08  2015-04-30  visjhr  Added support for TriBoards: TC2x2, TC2x3, TC2x4, TC2x5, TC2x7
  01.00.09  2015-05-05  visbwa  Enhanced SafeCtx-support of function ApplCanWaitSetMCR()
  01.00.10  2015-05-06  visbwa  Review of TriBoard support
  01.00.11  2015-09-02  visvnn/vismin  Added support for TriBoard TC2x8
  01.00.12  2015-10-05  visvnn  Fixed PortPin settings for CAN0 and LIN0 of TriBoard TC2x8,
                                added support for Eray interrupt 1,
                                added SCR-Register settings for DrvLin (necessary for DrvLin_TricoreAsr@root>=7.00.00)
  01.00.13  2015-11-04  visbwa  Fixed SCR-Register settings for DrvLin
  01.00.14  2016-03-10  visbwa  Fixed TRIBOARD_TC2x7 Pin settings for Ethernet RMII interface
  01.00.15  2016-05-24  viskvr  Added support for TRIBOARD_TC2x9, fixed FR and ETH pins for TRIBOARD_TC2x8
  01.00.16  2016-05-24  visbwa  Introduced support for Os_CoreGen7
  01.00.17  2016-06-07  visbwa  Reworked usage of BRSHW_ENABLE_TIMER_INTERRUPT and BRS_OS_USECASE_BRS to allow
                                automatic filtering by SWCP/Organi
  01.00.18  2016-06-15  visbwa  Removed unused Timer-registers, re-organisiert LED alive-blinking functions,
                                removed static inline from FR-PllInit functions
  01.00.19  2016-06-20  visbwa  Readded _endinit() for Os_UseCase OS
  01.00.20  2016-06-23  visbwa  Changed BRS_IOS into BRSHW_IOS according to Brs_Template 2.00.01
  01.00.21  2016-09-06  visbwa  Added prototypes of several Appl functions, to prevent compiler warnings with Tasking 6
  01.00.22  2016-09-16  vishan  Added generic port access macros
                                Added port init helper functions
                                Added custom port toggle test functions
  01.00.23  2016-12-02  vismaa  Added HSR_365, outsourced BrsHwPortInitPowerOn (Pin Configuration) to BrsHw_Ports.h,
                                fixed GNU interrupt handling, added DrvEth ISR for GNU
  01.00.24  2016-12-15  visbwa  Encapsulated timer interrupt initialization for GNU compiler (not necessary with OS),
                                Review
  01.00.25  2016-12-16  vismaa  Added EthIsr for GNU
  01.00.26  2017-01-12  visbwa  Simplified ApplCanWaitSetMCR() implementation (replaced mydummy++ by nop())
  01.00.27  2017-01-12  visbwa  Added Appl_UnlockEndinit() and Appl_LockEndinit() (used by newer driver implementation)
                                and made it available also with DrvLin and DrvEth
  01.00.28  2017-02-28  visbwa  Encapsuled parts for ISR initialization with != OsGen7 (has to be done with OS-APIs),
                                replaced "error:" by "error" (proper C-syntax)
  01.00.29  2017-02-28  visbwa  Added ISR-handler for DrvLin and UseCase w/o OS
  01.01.00  2017-05-02  visbwa  Added TCM support, review according Brs_Template 2.01.00
  01.01.01  2017-05-10  visbwa  Fixed comments of some PORT registers
**********************************************************************************************************************/

/**********************************************************************************************************************
*  SAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This implementation is sample code and only intended to illustrate an example of a possible BSW implementation.
*  The implementation may not be complete and is not provided for use in production
*  without any modifications. If this sample code is used in any way, the customer shall test
*  this implementation as well as any of its modifications with diligent care.
*********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
/*
 * Description: The BrsHw header provides all the necessary interfaces to
 *              the microcontroller hardware features like ports, timers, LEDs, ...
 */
#include "BrsHw.h"
#include "Can.h"



#if defined (VGEN_ENABLE_LIN_DRV)
# if defined (VGEN_ENABLE_IF_ASRIFLIN)
  /*Autosar component*/
  #include "Lin.h"
# else
  /*CANbedded component*/
  #include "lin_api.h"
  #include "sio_par.h"
# endif
#endif

#if defined (VGEN_ENABLE_DRVFR__BASEASR)
  #include "Fr.h"
# if !defined (FR_CHANNEL_A_USED) && !defined (FR_CHANNEL_B_USED)
  #error "Could not detect DrvFr channel configuration automatically. Please define here manually, which channel is used within your configuration."
  /*#define FR_CHANNEL_A_USED STD_ON*/
  /*#define FR_CHANNEL_B_USED STD_ON*/
# endif
#endif



#include "watchdog.h"

#if !defined (VGEN_ENABLE_DRVPORT)
  #include "BrsHw_Ports.h"
#endif

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
#if (BRSHW_VERSION != 0x0101u)
  #error "Header and source file are inconsistent!"
#endif
#if (BRSHW_BUGFIX_VERSION != 0x01u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
  CONFIGURATION CHECK
**********************************************************************************************************************/
#if defined (BRS_COMP_GNU)     

#else
  #error "Unknown compiler specified!"
#endif

/**********************************************************************************************************************
  DEFINITION + MACROS
**********************************************************************************************************************/

#if defined (BRS_COMP_GNU)
# if defined(BRS_DERIVATIVE_TC21X)
  #include <TC21xa/Ifx_reg.h>
# elif defined (BRS_DERIVATIVE_TC22X)
  #include <TC22xa/Ifx_reg.h>
# elif defined (BRS_DERIVATIVE_TC23X)
  #include <TC23xa/Ifx_reg.h>
# elif defined (BRS_DERIVATIVE_TC26X)
  #include <TC26xa/Ifx_reg.h>
# elif defined (BRS_DERIVATIVE_TC27X)
  #include <TC27xc/Ifx_reg.h>  // vademi change from c to a
# elif defined (BRS_DERIVATIVE_TC29X)
  #include <TC29xa/Ifx_reg.h>
# else
  #error "No rule for the register definitions of your derivative implemented yet"
# endif
#endif /*BRS_COMP_GNU*/

#if !defined (BRS_OS_USECASE_OSGEN7)
/* Autosar - CANbedded compatibility */
#if defined (LIN_ENABLE_HARDWARE_INTERFACE_0)
  #define SIO_ENABLE_SIO_UART0
#endif
#if defined (LIN_ENABLE_HARDWARE_INTERFACE_1)
  #define SIO_ENABLE_SIO_UART1
#endif
#if defined (LIN_ENABLE_HARDWARE_INTERFACE_2)
  #define SIO_ENABLE_SIO_UART2
#endif
#if defined (LIN_ENABLE_HARDWARE_INTERFACE_3)
  #define SIO_ENABLE_SIO_UART3
#endif
#if defined (Lin_PISEL_0)
  #define kSioPISEL_0  Lin_PISEL_0
#endif
#if defined (Lin_PISEL_1)
  #define kSioPISEL_1  Lin_PISEL_1
#endif
#if defined (Lin_PISEL_2)
  #define kSioPISEL_2  Lin_PISEL_2
#endif
#if defined (Lin_PISEL_3)
  #define kSioPISEL_3  Lin_PISEL_3
#endif

#if !defined (Lin_InterruptPriority_HWI0)
  #define Lin_InterruptPriority_HWI0 BRSHW_LIN0PRIO
#endif
#if !defined (Lin_InterruptPriority_0)
  #define Lin_InterruptPriority_0 Lin_InterruptPriority_HWI0
#endif

#if !defined (Lin_InterruptPriority_HWI1)
  #define Lin_InterruptPriority_HWI1 BRSHW_LIN1PRIO
#endif
#if !defined (Lin_InterruptPriority_1)
  #define Lin_InterruptPriority_1 Lin_InterruptPriority_HWI1
#endif

#if !defined (Lin_InterruptPriority_HWI2)
  #define Lin_InterruptPriority_HWI2 BRSHW_LIN2PRIO
#endif
#if !defined (Lin_InterruptPriority_2)
  #define Lin_InterruptPriority_2 Lin_InterruptPriority_HWI2
#endif

#if !defined (Lin_InterruptPriority_HWI3)
  #define Lin_InterruptPriority_HWI3 BRSHW_LIN3PRIO
#endif
#if !defined (Lin_InterruptPriority_3)
  #define Lin_InterruptPriority_3 Lin_InterruptPriority_HWI3
#endif
#endif /*BRS_OS_USECASE_OSGEN7*/

/**********************************************************************************************************************
  GLOBAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL CONST VARIABLES
**********************************************************************************************************************/
/*
 * Description: These constants are used to propagate the Versions over
 *              module boundaries.The version numbers are BCD coded. E.g. a sub
 *              version of 23 is coded with 0x23, a bug fix version of 9 is
 *              coded 0x09.
 */
uint8 const kBrsHwMainVersion   = (uint8)(BRSHW_VERSION >> 8);
uint8 const kBrsHwSubVersion    = (uint8)(BRSHW_VERSION & 0xFF);
uint8 const kBrsHwBugfixVersion = (uint8)(BRSHW_BUGFIX_VERSION);

/**********************************************************************************************************************
  LOCAL VARIABLES AND LOCAL HW REGISTERS
**********************************************************************************************************************/
/*
 * Description: This counter is used to count the number of nested calls to
 *              disable and restore the state of the global INT enable bit.
 *              Please note: This variable is used only in this file.
 * Values     : 0 if no BrsHwDisableInterrupt is called and INT is allowed by the
 *              BRS. Value > 0 if INT is locked by the BRS interrupt control API.
 */
static uint8 bBrsHwIntDiCounter;

/*
 * Description: Store value of ICR register on DI command
 * See BrsHwDisableInterrupt() and BrsHwDisableInterrupt()
 */
uint16 bBrsHwICR;

/**********************************************************************************************************************
  CONTROLLER CONFIGURATION REGISTERS
**********************************************************************************************************************/
/*******************************************************************************
  WATCHDOG  GROUP  CONFIG
*******************************************************************************/
#define BRS_SFR_WDTCON0       BRSHW_IOS(uint32, 0xF0036100)  /*original name: SCU_WDTCPU0CON0 */
#define BRS_SFR_WDTCON1       BRSHW_IOS(uint32, 0xF0036104)  /*original name: SCU_WDTCPU0CON1 */
#define BRS_SFR_WDTSCON0      BRSHW_IOS(uint32, 0xF00360F0)  /*original name: SCU_WDTSCON0 */

/* Necessary for _endinit() */
#define BRS_GPT_CLC        BRSHW_IOS(uint32, 0xF0002E00) /* GPT_CLC */

/*******************************************************************************
  PLL  GROUP  CONFIG
*******************************************************************************/
#define BRS_PLLCLC         BRSHW_IOS(uint32, 0xF0000040) /* original name: PLL_CLC */
#define BRS_VCO_BYPASS     0x00000020
#define BRS_OSC_DISC       0x01000000
#define BRS_PLL_LOCK       0x00000001
#define BRS_PLL_LOCK_RES   0x00000002
#define BRS_CLOCK_MASK     0x007FFFC4

/*******************************************************************************
  PORT  GROUP  CONFIG
*******************************************************************************/
/*#vishan: added generic port register access */
#define PORT_BASE_ADDRESS 0xF003A000
#define BRS_OFFSET_POUT  0x00 /* Port n Output Register */
#define BRS_OFFSET_IOCR0 0x10 /* Port n Input/Output Control Register 0 */
#define BRS_OFFSET_PIN   0x24 /* Port n Input Register */
#define BRS_OFFSET_PDR0  0x40 /* Port n Pad Driver Mode 0 Register */
#define BRS_OFFSET_PCSR  0x64 /* Port n Pin Controller Select Register */
#define BRS_PORT_POUT(g)   BRSHW_IOS(uint32, PORT_BASE_ADDRESS \
                                            + 0x1000 * ((uint32)g / 10) + 0x100 * ((uint32)g % 10) \
                                            + BRS_OFFSET_POUT) /* Port Output Register (group) */
#define BRS_PORT_IOCR(g,n) BRSHW_IOS(uint32, PORT_BASE_ADDRESS \
                                            + 0x1000 * ((uint32)g / 10) + 0x100 * ((uint32)g % 10) \
                                            + BRS_OFFSET_IOCR0 + 4 * ((uint32)n / 4) ) /* Port Input/Output Control Register (group, number) */
#define BRS_PORT_PIN(g)    BRSHW_IOS(uint32, PORT_BASE_ADDRESS \
                                            + 0x1000 * ((uint32)g / 10) + 0x100 * ((uint32)g % 10) \
                                            + BRS_OFFSET_PIN) /* Port Input Register (group) */
#define BRS_PORT_PDR(g,n)  BRSHW_IOS(uint32, PORT_BASE_ADDRESS \
                                            + 0x1000 * ((uint32)g / 10) + 0x100 * ((uint32)g % 10) \
                                            + BRS_OFFSET_PDR0 + 4 * ((uint32)n / 8) ) /* Port Pad Driver Mode Register (group, number) */
#define BRS_PORT_PCSR(g)   BRSHW_IOS(uint32, PORT_BASE_ADDRESS \
                                            + 0x1000 * ((uint32)g / 10) + 0x100 * ((uint32)g % 10) \
                                            + BRS_OFFSET_PCSR)                /* Port g Pin Controller Select Register */
#define BRS_IOCR_SFT(n) (3 + 8 * ((uint32)n % 4)) /* number of bit shifts to adress Px_IOCRy_PC(n) */ 
#define BRS_PDR_SFT(n)  (4 * ((uint32)n % 8)) /* number of bit shifts to adress Px_IOCRy_PC(n) */ 
/* mask for Port Input/Output Control Register (number); 
e.g.: BRS_IOCR_MSK(15) == BRS_IOCR_MSK(11) == BRS_IOCR_MSK(7) == 0xF8000000*/
#define BRS_IOCR_MSK(n) (uint32)( 0x1F << BRS_IOCR_SFT(n) )
#define BRS_PDR_MSK(n)  (uint32)( 0x0F << BRS_PDR_SFT(n) )
#define BRS_IOCR_ALT(x) (uint32)( 0x10 + x )  /*Alt 6  = 0b10110 == 0x10 + 6*/
#define BRS_IOCR_CLR(g, n) BRS_PORT_IOCR(g,n) &= ~BRS_IOCR_MSK(n)
#define BRS_IOCR_SET_OUTPUT_ALT(g, n, x) {BRS_PORT_IOCR(g,n) &= ~BRS_IOCR_MSK(n);       \
                                       BRS_PORT_IOCR(g,n) |= BRS_IOCR_ALT(x) << BRS_IOCR_SFT(n);}
#define BRS_IOCR_SET_INPUT(g, n) {     BRS_PORT_IOCR(g,n) &= ~BRS_IOCR_MSK(n);       \
                                       BRS_PORT_IOCR(g,n) |= 0xF << BRS_IOCR_SFT(n);  }
#define BRS_PDR_SET_SPD2(g,n)  {       BRS_PORT_PDR(g,n)  &= ~BRS_PDR_MSK(n);       \
                                       BRS_PORT_PDR(g,n)  |= 0x5 << BRS_PDR_SFT(n);  }
#define BRS_PDR_SET_SPD4(g,n)  {       BRS_PORT_PDR(g,n)  &= ~BRS_PDR_MSK(n);       \
                                       BRS_PORT_PDR(g,n)  |= 0x7 << BRS_PDR_SFT(n);  }
#if 0
#define BRS_P00_OUT        BRSHW_IOS(uint32, 0xF003A000) /* Port 00 Output Register */
#define BRS_P00_IOCR0      BRSHW_IOS(uint32, 0xF003A010) /* Port 00 Input/Output Control Register 0 */
#define BRS_P00_IOCR8      BRSHW_IOS(uint32, 0xF003A018) /* Port 00 Input/Output Control Register 8 */
#define BRS_P01_IOCR8      BRSHW_IOS(uint32, 0xF003A118) /* Port 01 Input/Output Control Register 8 */
#define BRS_P01_IOCR12     BRSHW_IOS(uint32, 0xF003A11C) /* Port 01 Input/Output Control Register 12 */
#define BRS_P02_IOCR0      BRSHW_IOS(uint32, 0xF003A210) /* Port 02 Input/Output Control Register 0 */
#define BRS_P02_IOCR4      BRSHW_IOS(uint32, 0xF003A214) /* Port 02 Input/Output Control Register 4 */
#define BRS_P02_IOCR8      BRSHW_IOS(uint32, 0xF003A218) /* Port 02 Input/Output Control Register 8 */
#define BRS_P02_PDR0       BRSHW_IOS(uint32, 0xF003A240) /* Port 02 Pad Driver Mode 0 Register */
#define BRS_P10_IOCR4      BRSHW_IOS(uint32, 0xF003B014) /* Port 10 Input/Output Control Register 4 */
#define BRS_P10_IOCR8      BRSHW_IOS(uint32, 0xF003B018) /* Port 10 Input/Output Control Register 8 */
#define BRS_P11_IOCR0      BRSHW_IOS(uint32, 0xF003B110) /* Port 11 Input/Output Control Register 0 */
#define BRS_P11_IOCR4      BRSHW_IOS(uint32, 0xF003B114) /* Port 11 Input/Output Control Register 4 */
#define BRS_P11_IOCR8      BRSHW_IOS(uint32, 0xF003B118) /* Port 11 Input/Output Control Register 8 */
#define BRS_P11_IOCR12     BRSHW_IOS(uint32, 0xF003B11C) /* Port 11 Input/Output Control Register 12*/
#define BRS_P11_PCSR       BRSHW_IOS(uint32, 0xF003B164) /* Port Controller Selection Register 11 */
#define BRS_P11_PDR0       BRSHW_IOS(uint32, 0xF003B140) /* Port 11 Pad Driver Mode 0 Register */
#define BRS_P11_PDR1       BRSHW_IOS(uint32, 0xF003B144) /* Port 11 Pad Driver Mode 1 Register */
#define BRS_P12_IOCR0      BRSHW_IOS(uint32, 0xF003B210) /* Port 11 Pad Driver Mode 1 Register */
#define BRS_P14_IOCR0      BRSHW_IOS(uint32, 0xF003B410) /* Port 14 Input/Output Control Register 0 */
#define BRS_P14_IOCR4      BRSHW_IOS(uint32, 0xF003B414) /* Port 14 Input/Output Control Register 0 */
#define BRS_P14_IOCR8      BRSHW_IOS(uint32, 0xF003B418) /* Port 14 Input/Output Control Register 0 */
#define BRS_P14_PDR0       BRSHW_IOS(uint32, 0xF003B440) /* Port 14 Pad Driver Mode 0 Register */
#define BRS_P15_IOCR0      BRSHW_IOS(uint32, 0xF003B510) /* Port 15 Input/Output Control Register 4 */
#define BRS_P15_IOCR4      BRSHW_IOS(uint32, 0xF003B514) /* Port 15 Input/Output Control Register 4 */
#define BRS_P15_IOCR8      BRSHW_IOS(uint32, 0xF003B518) /* Port 15 Input/Output Control Register 8 */
#define BRS_P15_PDR0       BRSHW_IOS(uint32, 0xF003B540) /* Port 15 Pad Driver Mode 0 Register */
#define BRS_P20_IOCR4      BRSHW_IOS(uint32, 0xF003C014) /* Port 20 Input/Output Control Register 4 */
#define BRS_P20_IOCR8      BRSHW_IOS(uint32, 0xF003C018) /* Port 20 Input/Output Control Register 8 */
#define BRS_P20_PDR0       BRSHW_IOS(uint32, 0xF003C040) /* Port 20 Pad Driver Mode 0 Register */
#define BRS_P20_PDR1       BRSHW_IOS(uint32, 0xF003C044) /* Port 20 Pad Driver Mode 1 Register */
#define BRS_P21_IOCR0      BRSHW_IOS(uint32, 0xF003C110) /* Port 21 Input/Output Control Register 0 */
#define BRS_P21_IOCR4      BRSHW_IOS(uint32, 0xF003C114) /* Port 21 Input/Output Control Register 4 */
#define BRS_P33_IOCR4      BRSHW_IOS(uint32, 0xF003D314) /* Port 33 Input/Output Control Register 4 */
#define BRS_P33_IOCR8      BRSHW_IOS(uint32, 0xF003D318) /* Port 33 Input/Output Control Register 8 */
#define BRS_P33_PDR0       BRSHW_IOS(uint32, 0xF003D340) /* Port 33 Pad Driver Mode 0 Register */
#define BRS_P33_PDR1       BRSHW_IOS(uint32, 0xF003D344) /* Port 33 Pad Driver Mode 1 Register */
#define BRS_P34_IOCR0      BRSHW_IOS(uint32, 0xF003D410) /* Port 34 Pad Driver Mode 0 Register */
#define BRS_P34_PDR0       BRSHW_IOS(uint32, 0xF003D440) /* Port 34 Pad Driver Mode 0 Register */
#endif

#if !defined (BRS_OS_USECASE_OSGEN7)
/*******************************************************************************
  INTERRUPT  GROUP  CONFIG
*******************************************************************************/
/*Base Address*/
#define BRS_SRC_BASE 0xF0038000
/*Flexray / ERAY*/
#define BRS_SRC_ERAYINT0   BRSHW_IOS(uint32, BRS_SRC_BASE + 0xBE0) /* ERAYINT0 */
#define BRS_SRC_ERAYINT1   BRSHW_IOS(uint32, BRS_SRC_BASE + 0xBE4) /* ERAYINT1 */
#define BRS_SRC_ERAYTINT0  BRSHW_IOS(uint32, BRS_SRC_BASE + 0xBE8) /* ERAYINTT0 */
#define BRS_SRC_ERAYTINT1  BRSHW_IOS(uint32, BRS_SRC_BASE + 0xBEC) /* ERAYINTT1 */
/*Ethernet*/
#define BRS_SRC_ETH        BRSHW_IOS(uint32, BRS_SRC_BASE + 0x8F0) /* ETH INT */
/*LIN*/
/*RX*/
#define BRS_SRC_LIN0RX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0x84) /* LIN0RX */
#define BRS_SRC_LIN1RX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0x90) /* LIN1RX */
#define BRS_SRC_LIN2RX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0x9C) /* LIN2RX */
#define BRS_SRC_LIN3RX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0xA8) /* LIN3RX */
/*TX*/
#define BRS_SRC_LIN0TX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0x80) /* LIN0TX */
#define BRS_SRC_LIN1TX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0x8C) /* LIN1TX */
#define BRS_SRC_LIN2TX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0x98) /* LIN2TX */
#define BRS_SRC_LIN3TX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0xA4) /* LIN3TX */
/*EX*/
#define BRS_SRC_LIN0EX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0x88) /* LIN0EX */
#define BRS_SRC_LIN1EX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0x94) /* LIN1EX */
#define BRS_SRC_LIN2EX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0xA0) /* LIN2EX */
#define BRS_SRC_LIN3EX     BRSHW_IOS(uint32, BRS_SRC_BASE + 0xAC) /* LIN3EX */
#endif /*!BRS_OS_USECASE_OSGEN7*/

/*******************************************************************************
  SYSTEM  CONTROL  UNIT  SCU
*******************************************************************************/
#define BRS_SWRSTCON       BRSHW_IOS(uint32, 0xF0036060)

#define BRS_SCU_OSCCON     BRSHW_IOS(uint32, 0xF0036010) /* OSCCON  OSC Control Register */
#define BRS_SCU_CCUCON0    BRSHW_IOS(uint32, 0xF0036030) /* CCUCON0 CCU Control Register 0 */
#define BRS_SCU_CCUCON1    BRSHW_IOS(uint32, 0xF0036034) /* CCUCON1 CCU Control Register 1 */
#define BRS_SCU_CCUCON5    BRSHW_IOS(uint32, 0xF003604C) /* CCUCON5 CCU Control Register 5 */
#define BRS_SCU_CCUCON6    BRSHW_IOS(uint32, 0xF0036080) /* CCUCON6 CCU Control Register 6 */
#define BRS_SCU_CCUCON7    BRSHW_IOS(uint32, 0xF0036084) /* CCUCON7 CCU Control Register 7 */
#define BRS_SCU_CCUCON8    BRSHW_IOS(uint32, 0xF0036088) /* CCUCON8 CCU Control Register 8 */

#define BRS_SCU_PLLCON0    BRSHW_IOS(uint32, 0xF0036018) /* PLLCON0 PLL Configuration 0 Register */
#define BRS_SCU_PLLCON1    BRSHW_IOS(uint32, 0xF003601C) /* PLLCON1 PLL Configuration 1 Register */
#define BRS_SCU_PLLCON2    BRSHW_IOS(uint32, 0xF0036020) /* PLLCON2 PLL Configuration 2 Register */
#define BRS_SCU_PLLSTAT    BRSHW_IOS(uint32, 0xF0036014) /* PLLSTAT PLL Status Register */

#define BRS_SCU_PLLERAYCON0  BRSHW_IOS(uint32, 0xF0036028) /* PLL_ERAY Configuration 0 Register */
#define BRS_SCU_PLLERAYCON1  BRSHW_IOS(uint32, 0xF003602C) /* PLL_ERAY Configuration 1 Register */
#define BRS_SCU_PLLERAYSTAT  BRSHW_IOS(uint32, 0xF0036024) /* PLL_ERAY Status Register */

#define BRS_SCU_TRAPCLR    BRSHW_IOS(uint32, 0xF003612C) /* Trap Clear Register */
#define BRS_SCU_TRAPDIS    BRSHW_IOS(uint32, 0xF0036130) /* Trap Disable Register */

/*******************************************************************************
| Local defines
|******************************************************************************/

#if defined (BRS_COMP_GNU)
  #define __nop()             nop()
  #define nop()               __asm__ ("nop")     /*NOP operation*/
  #define enable_interrupt()  __asm__ ("enable")  /*Enable global interrupt operation*/
  #define disable_interrupt() __asm__ ("disable") /*Disable global interrupt operation*/
  #define isync()             __asm__ ("isync")   /*Synchronize instruction stream (pipeline?)*/
  #define __interrupt(x)      void
  /*Read from (normally protected) CPU register*/
  #define mfcr(regaddr)       ({ int res; __asm__ ("mfcr %0,"#regaddr : "=d" (res)); res; })
  /*Write to (normally protected) CPU register*/
  #define mtcr(regaddr,val)   __asm__ ("mtcr "#regaddr",%0" : : "d" (val))

  #include "cint.h"
  #include "intrinsics.h"



/*#   if defined (kCanPhysToLogChannelIndex_0)*/
   extern void CanIsr_0(void);  
/* #   endif */
#   if defined (kCanPhysToLogChannelIndex_1)
  extern void CanIsr_1(void);
#   endif
#   if defined (kCanPhysToLogChannelIndex_2)
  extern void CanIsr_2(void);
#   endif
#   if defined (kCanPhysToLogChannelIndex_3)
  extern void CanIsr_3(void);
#   endif
#   if defined (kCanPhysToLogChannelIndex_4)
  extern void CanIsr_4(void);
#   endif
#   if defined (kCanPhysToLogChannelIndex_5)
  extern void CanIsr_5(void);
#   endif
#   if defined (kCanPhysToLogChannelIndex_6)
  extern void CanIsr_6(void);
#   endif
#   if defined (kCanPhysToLogChannelIndex_7)
  extern void CanIsr_7(void);
#   endif



# if defined (VGEN_ENABLE_LIN_DRV)
#  if defined (SIO_ENABLE_SIO_UART0)
  extern void BrsHwLin0Interrupt(void);
#  endif 
#  if defined (SIO_ENABLE_SIO_UART1)
  extern void BrsHwLin1Interrupt(void);
#  endif
#  if defined (SIO_ENABLE_SIO_UART2)
  extern void BrsHwLin2Interrupt(void);
#  endif
#  if defined (SIO_ENABLE_SIO_UART3)
  extern void BrsHwLin3Interrupt(void);
#  endif
# endif /*VGEN_ENABLE_LIN_DRV*/

# if defined (VGEN_ENABLE_DRVFR__BASEASR)
  extern void BrsHwFrLine0Interrupt(void);
  extern void BrsHwFrTimer0Interrupt(void);
# endif

# if defined (VGEN_ENABLE_DRVETH__BASEASR)
  /* extern void EthIsr_0 (void); */
# endif
#endif /*BRS_COMP_GNU*/

/*******************************************************************************
* Global variables
*******************************************************************************/
#if defined (BRS_COMP_GNU)
/* provide the abs function for PLL calculation for the GNU compiler */
uint32 __abs(sint32 val)
{
  if(val < 0)
  {
    return val * -1;
  }
  else
  {
    return val;
  }
}
#endif /*BRS_COMP_x*/

/**********************************************************************************************************************
  LOCAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL CONST VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  PROTOTYPES OF LOCAL FUNCTIONS
**********************************************************************************************************************/
void BrsHwSafetyUnlockInit(void);
void BrsHwSafetyLockInit(void);
void BrsHwUnlockInit(void);
void BrsHwLockInit(void);


void Appl_UnlockInit(void);
void Appl_UnlockEndinit(void);
void Appl_LockInit(void);
void Appl_LockEndinit(void);

void ApplCanWaitSetMCR(void);


#if defined (BRSHW_PLL_ERAY_AVAILABLE)
Std_ReturnType BrsHwErayPllInitPowerOn(void);
Std_ReturnType BrsHwErayPllWaitVcoLock(void);
#endif

/**********************************************************************************************************************
  FUNCTION DEFINITIONS
**********************************************************************************************************************/

/*****************************************************************************/
/**
 * @brief      This function has to be used to initialize the Watchdog.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain or EcuM at power on initialization
 */
/*****************************************************************************/
void BrsHwWatchdogInitPowerOn(void)
{
#if !defined (VGEN_ENABLE_DRVWD)
  BrsHwUnlockInit();
  BRS_SFR_WDTCON1 |= 0x8;
  BrsHwLockInit();
#endif /*!VGEN_ENABLE_DRVWD*/
}


Std_ReturnType BrsHwErayPllWaitVcoLock(void)
{
  Std_ReturnType ErrorFlag;
  uint32 TimeOutCount;

  ErrorFlag = E_OK;
  TimeOutCount = ((uint32)0x000001FFU);
  do
  {
    TimeOutCount-- ;
  } while (((BRS_SCU_PLLERAYSTAT & 0x00000004) != 0x00000004) && (TimeOutCount > 0U)) ;

  if (TimeOutCount == 0U)
  {
    ErrorFlag = E_NOT_OK;
  }
return(ErrorFlag);
}


#if !defined (VGEN_ENABLE_DRVPORT)
/*******************************************************************************
  Port Pin initialization helper functions for usage of BrsHw_Ports.h
********************************************************************************/
/*****************************************************************************/
/**
 * @brief      This function configures a port pin as input pin.
 * @pre        Port pin configuartions available within BrsHw_Ports.h and
 *             no DrvPort used for port pin initialization.
 * @param[in]  p - brsHw_Port_PortType, to be initialized.
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn() and
 *             BrsHwEvaBoardInitPowerOn() locally.
 */
/*****************************************************************************/
void BrsHwInitPortInput(brsHw_Port_PortType p)
{
  BRS_IOCR_SET_INPUT(p.portGroup, p.portNumber);
}

/*******************************************************************************
* NAME          : BrsHwInitPortIn_CAN
* CALLED BY     : BrsHwPortInitPowerOn
* PRECONDITIONS : none
* PARAMETERS    : p from BrsHw_Ports.h
* RETURN VALUE  : none
* DESCRIPTION   : This function may be used to initialize an input port pin and
*                 set the port mode to speed level 2 (fittin for CAN).
********************************************************************************/
void BrsHwInitPortIn_CAN (brsHw_Port_PortType p)
{
  BrsHwInitPortInput(p);
  BrsHwUnlockInit();
  BRS_PDR_SET_SPD2(p.portGroup, p.portNumber);
  BrsHwLockInit();
}

/*****************************************************************************/
/**
 * @brief      This function configures a port pin as output pin.
 * @pre        Port pin configuartions available within BrsHw_Ports.h and
 *             no DrvPort used for port pin initialization.
 * @param[in]  p - brsHw_Port_PortType, to be initialized.
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn() and
 *             BrsHwEvaBoardInitPowerOn() locally.
 */
/*****************************************************************************/
void BrsHwInitPortOutput(brsHw_Port_PortType p)
{
  BRS_IOCR_SET_OUTPUT_ALT(p.portGroup, p.portNumber, p.portAlternative);
}

/*******************************************************************************
* NAME          : BrsHwInitPortOut_CAN
* CALLED BY     : BrsHwPortInitPowerOn
* PRECONDITIONS : none
* PARAMETERS    : p from BrsHw_Ports.h
* RETURN VALUE  : none
* DESCRIPTION   : This function may be used to initialize an output port pin and
*                 set the port mode to speed level 2 (fittin for CAN).
********************************************************************************/
void BrsHwInitPortOut_CAN (brsHw_Port_PortType p)
{
  BrsHwInitPortOutput(p);
  BrsHwUnlockInit();
  BRS_PDR_SET_SPD2(p.portGroup, p.portNumber);
  BrsHwLockInit();
}

/*****************************************************************************/
/**
 * @brief      This function sets the output level of a port pin.
 * @pre        Port pin configuartions available within BrsHw_Ports.h,
 *             no DrvPort used for port pin initialization and
 *             transferred port pin has to be initialized as output pin with
 *             GPIO functionality.
 * @param[in]  p     - brsHw_Port_PortType, to be set,
 *             Level - level, port pin has to be set to
 *                     (BRSHW_PORT_LOGIC_LOW or BRSHW_PORT_LOGIC_HIGH).
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwPortInitPowerOn(),
 *             BrsHwEvaBoardInitPowerOn(), BrsHw_WriteDio_TCM_SDA_OUT() and
 *             BrsHw_WriteDio_TCM_CLK_OUT() locally.
 */
/*****************************************************************************/
void BrsHwPort_SetLevel(brsHw_Port_PortType p, uint8 Level)
{
  if (Level == BRSHW_PORT_LOGIC_LOW)
  {
    BRS_PORT_POUT(p.portGroup) &= ~(0x1 << p.portNumber);
  }
  else
  {
    BRS_PORT_POUT(p.portGroup) |=  (0x1 << p.portNumber);
  }
}

/*****************************************************************************/
/**
 * @brief      This function reads the input level of a port pin.
 * @pre        Port pin configuartions available within BrsHw_Ports.h,
 *             no DrvPort used for port pin initialization and
 *             transferred port pin has to be initialized as input pin with
 *             GPIO functionality.
 * @param[in]  p - brsHw_Port_PortType, to be read.
 * @param[out] -
 * @return     Level, read from port pin
 *             (BRSHW_PORT_LOGIC_LOW or BRSHW_PORT_LOGIC_HIGH).
 * @context    Function is called from BrsHw_WriteDio_TCM_SDA_OUT() and
 *             BrsHw_WriteDio_TCM_CLK_OUT() locally.
 */
/*****************************************************************************/
uint8 BrsHwPort_GetLevel(brsHw_Port_PortType p)
{
  uint32 temp;

  temp = BRS_PORT_PIN(p.portGroup);
  temp &= (1 << p.portNumber);

  if(temp !=0x0000)
  {
    return BRSHW_PORT_LOGIC_HIGH;
  }
  else
  {
    return BRSHW_PORT_LOGIC_LOW;
  }
}

# if defined (BRSHW_PORTTEST)
/*******************************************************************************
* NAME          : BrsHwPortToggleOut
* CALLED BY     : BrsHwInitPortTest
* PRECONDITIONS : none
* PARAMETERS    : p from BrsHw_Ports.h
* RETURN VALUE  : none
* DESCRIPTION   : This function may be used to init a port as GP output and
*                 toggle its level off, on, off. Initialised ports may be reset!
********************************************************************************/
/* changes port settings! */
void BrsHwPortToggleOut (brsHw_Port_PortType p)
{
  BRS_IOCR_SET_OUTPUT_ALT(p.portGroup, p.portNumber, 0x0);
  BrsHwPort_SetLevel(p, 0);
  BrsHwPort_SetLevel(p, 1);
  BrsHwPort_SetLevel(p, 0);
}

/*******************************************************************************
* NAME          : BrsHwInitPortTest
* CALLED BY     : none
* PRECONDITIONS : none
* PARAMETERS    : none
* RETURN VALUE  : none
* DESCRIPTION   : used for HW Setup port toggle test
********************************************************************************/
/* init all ports to output and toggle for testing */
void BrsHwInitPortTest()
{
  BrsHwPortToggleOut(BRSHW_PORT_CAN0_EN);
  BrsHwPortToggleOut(BRSHW_PORT_CAN0_STBN);
  BrsHwPortToggleOut(BRSHW_PORT_CAN0_TX);
  BrsHwPortToggleOut(BRSHW_PORT_CAN0_RX);

  BrsHwPortToggleOut(BRSHW_PORT_LIN0_TX);
  BrsHwPortToggleOut(BRSHW_PORT_LIN0_RX);
  BrsHwPortToggleOut(BRSHW_PORT_LIN1_TX);
  BrsHwPortToggleOut(BRSHW_PORT_LIN1_RX);

  BrsHwPortToggleOut(BRSHW_PORT_FR0A_TX);
  BrsHwPortToggleOut(BRSHW_PORT_FR0A_RX);
  BrsHwPortToggleOut(BRSHW_PORT_FR0A_TXEN);
  BrsHwPortToggleOut(BRSHW_PORT_FR0A_TRCV_STB);
  BrsHwPortToggleOut(BRSHW_PORT_FR0A_TRCV_EN);

  BrsHwPortToggleOut(BRSHW_PORT_ETH_TXD0);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_TXD1);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_TXD2);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_TXD3);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_TXEN);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_MDC);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_MDIO);

  BrsHwPortToggleOut(BRSHW_PORT_ETH_CRSDVA);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_RX0);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_RX1);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_RX2);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_RX3);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_RXCLK);
  BrsHwPortToggleOut(BRSHW_PORT_ETH_COL);
}
# endif /*BRSHW_PORTTEST*/

# if defined (BRS_ENABLE_TCM_SUPPORT)
/*******************************************************************************
  TCM Write Functions
********************************************************************************/
void BrsHw_WriteDio_TCM_SDA_OUT(uint8 Level)
{
  BrsHwPort_SetLevel(BRSHW_PORT_TCM_SDA_OUT, Level);
}

void BrsHw_WriteDio_TCM_CLK_OUT(uint8 Level)
{
  BrsHwPort_SetLevel(BRSHW_PORT_TCM_CLK_OUT, Level);
}

/*******************************************************************************
  TCM Read Functions
********************************************************************************/
uint8 BrsHw_ReadDio_TCM_SDA_IN(void)
{
  return BrsHwPort_GetLevel(BRSHW_PORT_TCM_SDA_IN);
}

uint8 BrsHw_ReadDio_TCM_CLK_IN(void)
{
  return BrsHwPort_GetLevel(BRSHW_PORT_TCM_CLK_IN);
}
# endif /*BRS_ENABLE_TCM_SUPPORT*/
#endif /*!VGEN_ENABLE_DRVPORT*/

/*****************************************************************************/
/**
 * @brief      This function has to be used to initialize the used ports.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain or EcuM at power on initialization
 */
/*****************************************************************************/
void BrsHwPortInitPowerOn(void)
{
#if !defined (VGEN_ENABLE_DRVPORT)

# if defined (BRS_ENABLE_TCM_SUPPORT)
  BrsHwInitPortOutput(BRSHW_PORT_TCM_CLK_OUT);
  BrsHwInitPortOutput(BRSHW_PORT_TCM_SDA_OUT);
  BrsHwInitPortInput(BRSHW_PORT_TCM_SDA_IN);
  BrsHwInitPortInput(BRSHW_PORT_TCM_CLK_IN);
#  if defined (BRSHW_USE_TCM_EXT_IRQ)
  BrsHwInitPortInput(BRSHW_PORT_TCM_INTA_IN);
  BrsHwInitPortInput(BRSHW_PORT_TCM_INTB_IN);
#  endif
# endif /*BRS_ENABLE_TCM_SUPPORT*/

/*******************************************************************************
  CAN driver
********************************************************************************/
# if defined (VGEN_ENABLE_CAN_DRV)
#  if defined (kCanPhysToLogChannelIndex_0)
  BrsHwInitPortOut_CAN(BRSHW_PORT_CAN0_TX);
  BrsHwInitPortIn_CAN( BRSHW_PORT_CAN0_RX);
#   if defined(BRSHW_PORT_CAN0_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN0_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN0_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#   if defined (BRSHW_PORT_CAN0_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN0_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN0_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*kCanPhysToLogChannelIndex_0*/

#  if defined (kCanPhysToLogChannelIndex_1)
  BrsHwInitPortOut_CAN(BRSHW_PORT_CAN1_TX);
  BrsHwInitPortIn_CAN( BRSHW_PORT_CAN1_RX);
#   if defined(BRSHW_PORT_CAN1_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN1_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN1_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#   if defined (BRSHW_PORT_CAN1_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN1_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN1_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*kCanPhysToLogChannelIndex_1*/

#  if defined (kCanPhysToLogChannelIndex_2)
  BrsHwInitPortOut_CAN(BRSHW_PORT_CAN2_TX);
  BrsHwInitPortIn_CAN( BRSHW_PORT_CAN2_RX);
#   if defined(BRSHW_PORT_CAN2_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN2_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN2_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#   if defined (BRSHW_PORT_CAN2_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN2_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN2_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*kCanPhysToLogChannelIndex_2*/

#  if defined (kCanPhysToLogChannelIndex_3)
  BrsHwInitPortOut_CAN(BRSHW_PORT_CAN3_TX);
  BrsHwInitPortIn_CAN( BRSHW_PORT_CAN3_RX);
#   if defined(BRSHW_PORT_CAN3_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_CAN3_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN3_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#   if defined (BRSHW_PORT_CAN3_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_CAN3_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_CAN3_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*kCanPhysToLogChannelIndex_3*/
# endif /*VGEN_ENABLE_CAN_DRV*/

/*******************************************************************************
  LIN driver
********************************************************************************/
# if defined (VGEN_ENABLE_LIN_DRV)
#  if defined (SIO_ENABLE_SIO_UART0)
  BrsHwInitPortOutput(BRSHW_PORT_LIN0_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN0_RX);
#   if defined(BRSHW_PORT_LIN0_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_LIN0_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_LIN0_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*SIO_ENABLE_SIO_UART0*/

#  if defined (SIO_ENABLE_SIO_UART1)
  BrsHwInitPortOutput(BRSHW_PORT_LIN1_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN1_RX);
#   if defined(BRSHW_PORT_LIN1_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_LIN1_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_LIN1_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*SIO_ENABLE_SIO_UART1*/

#  if defined (SIO_ENABLE_SIO_UART2)
  BrsHwInitPortOutput(BRSHW_PORT_LIN2_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN2_RX);
#   if defined(BRSHW_PORT_LIN2_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_LIN2_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_LIN2_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*SIO_ENABLE_SIO_UART2*/

#  if defined (SIO_ENABLE_SIO_UART3)
  BrsHwInitPortOutput(BRSHW_PORT_LIN3_TX);
  BrsHwInitPortInput(BRSHW_PORT_LIN3_RX);
#   if defined(BRSHW_PORT_LIN3_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_LIN3_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_LIN3_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*SIO_ENABLE_SIO_UART3*/
# endif /*VGEN_ENABLE_LIN_DRV*/

/*******************************************************************************
  FLEXRAY driver
********************************************************************************/
# if defined (VGEN_ENABLE_DRVFR__BASEASR)
#  if (FR_CHANNEL_A_USED == STD_ON)
  BrsHwInitPortOutput(BRSHW_PORT_FR0A_TX);
  BrsHwInitPortInput(BRSHW_PORT_FR0A_RX);
  BrsHwInitPortOutput(BRSHW_PORT_FR0A_TXEN);
#   if defined(BRSHW_PORT_FR0A_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_FR0A_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_FR0A_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#   if defined (BRSHW_PORT_FR0A_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_FR0A_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_FR0A_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*FR_CHANNEL_A_USED*/

#  if (FR_CHANNEL_B_USED == STD_ON)
  BrsHwInitPortOutput(BRSHW_PORT_FR0B_TX);
  BrsHwInitPortInput(BRSHW_PORT_FR0B_RX);
  BrsHwInitPortOutput(BRSHW_PORT_FR0B_TXEN);
#   if defined(BRSHW_PORT_FR0B_TRCV_STB)
  BrsHwInitPortOutput(BRSHW_PORT_FR0B_TRCV_STB);
  BrsHwPort_SetLevel(BRSHW_PORT_FR0B_TRCV_STB, BRSHW_PORT_LOGIC_HIGH);
#   endif
#   if defined (BRSHW_PORT_FR0B_TRCV_EN)
  BrsHwInitPortOutput(BRSHW_PORT_FR0B_TRCV_EN);
  BrsHwPort_SetLevel(BRSHW_PORT_FR0B_TRCV_EN, BRSHW_PORT_LOGIC_HIGH);
#   endif
#  endif /*FR_CHANNEL_B_USED*/
# endif /*VGEN_ENABLE_DRVFR__BASEASR*/

/*******************************************************************************
  ETHERNET driver
********************************************************************************/
# if defined (VGEN_ENABLE_DRVETH__BASEASR)
  /* -- Transmitter signals -- */
  BrsHwInitPortInput(BRSHW_PORT_ETH_REFCLK);
  BrsHwInitPortOutput(BRSHW_PORT_ETH_TXD0);
  BrsHwInitPortOutput(BRSHW_PORT_ETH_TXD1);
#  if defined (BRSHW_PORT_ETH_TXD2)
  /* Transmit signal 2 is obsolete within RMII */
  BrsHwInitPortOutput(BRSHW_PORT_ETH_TXD2);
#  endif
#  if defined (BRSHW_PORT_ETH_TXD3)
  /* Transmit signal 3 is obsolete within RMII */
  BrsHwInitPortOutput(BRSHW_PORT_ETH_TXD3);
#  endif
  BrsHwInitPortOutput(BRSHW_PORT_ETH_TXEN);
#  if defined (BRSHW_PORT_ETH_TXER)
  /* Transmit Error signal is only optional within MII and obsolete within RMII */
  BrsHwInitPortOutput(BRSHW_PORT_ETH_TXER);
#  endif

  /* -- Receiver signals -- */
#  if defined (BRSHW_PORT_ETH_RXCLK)
  /* Receive clock signal is obsolete within RMII */
  BrsHwInitPortInput(BRSHW_PORT_ETH_RXCLK);
#  endif
  BrsHwInitPortInput( BRSHW_PORT_ETH_RXD0);
  BrsHwInitPortInput( BRSHW_PORT_ETH_RXD1);
#  if defined (BRSHW_PORT_ETH_RXD2)
  /* Receive signal 2 is obsolete within RMII */
  BrsHwInitPortInput(BRSHW_PORT_ETH_RXD2);
#  endif
#  if defined (BRSHW_PORT_ETH_RXD3)
  /* Receive signal 3 is obsolete within RMII */
  BrsHwInitPortInput(BRSHW_PORT_ETH_RXD3);
#  endif
  BrsHwInitPortInput( BRSHW_PORT_ETH_CRSDV);

  /* -- Management signals -- */
  BrsHwInitPortInput(BRSHW_PORT_ETH_MDIO);
#  if defined (BRSHW_PORT_ETH_MDC)
  /* Management data clock not always needed */
  BrsHwInitPortOutput(BRSHW_PORT_ETH_MDC);
#  endif

  BrsHwSafetyUnlockInit();
  /* Set TX pins for RMII mode */  
  BRS_PORT_PCSR(BRSHW_PORT_ETH_TXEN.portGroup) = (0x01 << BRSHW_PORT_ETH_TXEN.portNumber) | 
                                                 (0x01 << BRSHW_PORT_ETH_TXD0.portNumber) | 
                                                 (0x01 << BRSHW_PORT_ETH_TXD1.portNumber); /* | 
                                                 (0x01 << BRSHW_PORT_ETH_TXD2.portNumber) | 
                                                 (0x01 << BRSHW_PORT_ETH_TXD3.portNumber); */   /* not used in RMII MODE*/
  BrsHwSafetyLockInit();
  /* Clock related */
  BrsHwUnlockInit();
  BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_REFCLK.portGroup, BRSHW_PORT_ETH_REFCLK.portNumber); /* Use fast input mode for REFCLK */  
  /* use fast output mode for TX */
  /* fast mode is very important */
  BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXEN.portGroup, BRSHW_PORT_ETH_TXEN.portNumber);
  BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXD0.portGroup, BRSHW_PORT_ETH_TXD0.portNumber);
  BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXD1.portGroup, BRSHW_PORT_ETH_TXD1.portNumber);
  /*BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXD2.portGroup, BRSHW_PORT_ETH_TXD2.portNumber); */ /* not used in RMII MODE */
  /*BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXD3.portGroup, BRSHW_PORT_ETH_TXD3.portNumber); */ /* not used in RMII MODE */

  BrsHwLockInit();

  /* write into ETH_GPCTL register 0xf001d008 */
  BRSHW_IOS(uint32, 0xF001D008) &= (0xFFFFFF00);  /* ALTI0 = 00b */
  BRSHW_IOS(uint32, 0xF001D008) |= (0x02 | (0x01 << 24));  /* ALTI0 = 10b because of MDIO = P12.1, EPR=1 to set RMII */ 
  /* BRSHW_IOS(uint32, 0xF001D008) |= (0x00 | (0x01 << 24)); */ /* ALTI0 = 00b because of MDIO = P00.0, EPR=1 to set RMII */
  /* BRSHW_IOS(uint32, 0xF001D008) |= (0x01 | (0x01 << 24)); */ /* ALTI0 = 01b because of MDIO = P21.1, EPR=1 to set RMII */   
  /* BRSHW_IOS(uint32, 0xF001D008) |= (0x03 | (0x01 << 24)); */ /* ALTI0 = 10b because of MDIO = P21.3, EPR=1 to set RMII */
//#error please check ETH_GPCTL Alternate Input Select value depending on MDIO port!! */
  /* Could be implemented with a look up table... You better look up in datasheet ;) */

  /*BrsHwSafetyUnlockInit();*/
  /* Set TX pins for RMII mode */  
  /*BRS_PORT_PCSR(BRSHW_PORT_ETH_TXEN.portGroup) = (0x01 << BRSHW_PORT_ETH_TXEN.portNumber) | */
  /*                                               (0x01 << BRSHW_PORT_ETH_TXD0.portNumber) | */
  /*                                               (0x01 << BRSHW_PORT_ETH_TXD1.portNumber) | */
  /*                                               (0x01 << BRSHW_PORT_ETH_TXD2.portNumber) | */
  /*                                               (0x01 << BRSHW_PORT_ETH_TXD3.portNumber);  */
  /*BrsHwSafetyLockInit();*/
  /* Clock related */
  /*BrsHwUnlockInit();*/
  /*BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_RXCLK.portGroup, BRSHW_PORT_ETH_RXCLK.portNumber);*/ /* Use fast input mode for RXCLK */  
  /* use fast output mode for TX */
  /* fast mode is very important */
  /*BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXEN.portGroup, BRSHW_PORT_ETH_TXEN.portNumber);*/
  /*BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXD0.portGroup, BRSHW_PORT_ETH_TXD0.portNumber);*/
  /*BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXD1.portGroup, BRSHW_PORT_ETH_TXD1.portNumber);*/
  /*BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXD2.portGroup, BRSHW_PORT_ETH_TXD2.portNumber);*/
  /*BRS_PDR_SET_SPD4(BRSHW_PORT_ETH_TXD3.portGroup, BRSHW_PORT_ETH_TXD3.portNumber);*/

  /*BrsHwLockInit();*/

  /* write into ETH_GPCTL register 0xf001d008 */
  /*BRSHW_IOS(uint32, 0xF001D008) &= (0xFFFFFF00); */  /* ALTI0 = 00b */
  /*BRSHW_IOS(uint32, 0xF001D008) |= (0x02 | (0x01 << 24));  */ /* ALTI0 = 10b because of MDIO = P12.1, EPR=1 to set RMII */ 
  /* BRSHW_IOS(uint32, 0xF001D008) |= (0x00 | (0x01 << 24)); */ /* ALTI0 = 00b because of MDIO = P00.0, EPR=1 to set RMII */
  /* BRSHW_IOS(uint32, 0xF001D008) |= (0x01 | (0x01 << 24)); */ /* ALTI0 = 01b because of MDIO = P21.1, EPR=1 to set RMII */   
  /* BRSHW_IOS(uint32, 0xF001D008) |= (0x03 | (0x01 << 24)); */ /* ALTI0 = 10b because of MDIO = P21.3, EPR=1 to set RMII */
//#error please check ETH_GPCTL Alternate Input Select value depending on MDIO port!! */
  /* Could be implemented with a look up table... You better look up in datasheet ;) */

# endif /*VGEN_ENABLE_DRVETH__BASEASR*/

#endif /*!VGEN_ENABLE_DRVPORT*/
}

/*****************************************************************************/
/**
 * @brief      This function has to be used to initialize misc features not
 *             covered by the three functions above.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain or EcuM at power on initialization
 */
/*****************************************************************************/
void BrsHwEvaBoardInitPowerOn(void)
{
#if defined (BRS_ENABLE_SUPPORT_LEDS)

# if !defined (VGEN_ENABLE_DRVPORT)
  BrsHwInitPortOutput(BRSHW_PORT_LED);

# else
  #error "Configure the valid PortPin for the LED within your DrvPort config and uncomment this error. Or disable BRS_ENABLE_SUPPORT_LEDS."
# endif /*!VGEN_ENABLE_DRVPORT*/

  /* Set one LED on EVB demo board to show the system is alive */
  BrsHwSetLed(BRSHW_LED_SYSTEM_OK, BRSHW_PORT_LOGIC_HIGH);
#endif /*BRS_ENABLE_SUPPORT_LEDS*/
}

/* BrsHwTimeBaseInitPowerOn() and BrsHwTimeBaseInterrupt() removed by Organi, because of ALM attributes of project */

/*****************************************************************************/
/**
 * @brief      Disable the global system interrupt and initialize the INT
 *             lock handler variables.
 * @pre        Must be the first function call in main@BrsMain
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain at power on initialization
 */
/*****************************************************************************/
void BrsHwDisableInterruptAtPowerOn(void)
{
  bBrsHwIntDiCounter = 0;

  disable_interrupt();
}

/*****************************************************************************/
/**
 * @brief      Enable the global system interrupt the first time
 * @pre        Must be called after all initializations are done
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain at power on initialization
 */
/*****************************************************************************/
void BrsHwEnableInterruptAtPowerOn(void)
{
  /* Configure used interrupts */
#if !defined (BRS_OS_USECASE_OSGEN7)
  BrsHwConfigureInterruptsAtPowerOn();
#else
  /* With OsGen7, OS-APIs have to be used for this */
  /*BrsHwConfigureInterruptsAtPowerOn();*/
#endif

  /* unmask interrupts */
  bBrsHwIntDiCounter = 0;
  enable_interrupt();
}

#if !defined (BRS_OS_USECASE_OSGEN7)
/*****************************************************************************/
/**
 * @brief      This function has to be used to initialize the used interrupts.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsHwEnableInterruptAtPowerOn or EcuM-DriverInitThree
 */
/*****************************************************************************/
void BrsHwConfigureInterruptsAtPowerOn(void)
{
#if defined (BRS_COMP_GNU)
  _init_vectab();
  unsigned int CoreID = _mfcr(0xfe1C);

# if defined (VGEN_ENABLE_CAN_DRV)
#  if defined (kCanPhysToLogChannelIndex_0)
  _install_int_handler(kCanISRPrio_0, (void (*) (int)) CanIsr_0, 0);
#  endif
#  if defined (kCanPhysToLogChannelIndex_1)
  _install_int_handler(kCanISRPrio_1, (void (*) (int)) CanIsr_1, 0);
#  endif
#  if defined (kCanPhysToLogChannelIndex_2)
  _install_int_handler(kCanISRPrio_2, (void (*) (int)) CanIsr_2, 0);
#  endif
#  if defined (kCanPhysToLogChannelIndex_3)
  _install_int_handler(kCanISRPrio_3, (void (*) (int)) CanIsr_3, 0);
#  endif
#  if defined (kCanPhysToLogChannelIndex_4)
  _install_int_handler(kCanISRPrio_4, (void (*) (int)) CanIsr_4, 0);
#  endif
#  if defined (kCanPhysToLogChannelIndex_5)
  _install_int_handler(kCanISRPrio_5, (void (*) (int)) CanIsr_5, 0);
#  endif
#  if defined (kCanPhysToLogChannelIndex_6)
  _install_int_handler(kCanISRPrio_6, (void (*) (int)) CanIsr_6, 0);
#  endif
#  if defined (kCanPhysToLogChannelIndex_7)
  _install_int_handler(kCanISRPrio_7, (void (*) (int)) CanIsr_7, 0);
#  endif
# endif

# if defined (VGEN_ENABLE_LIN_DRV)
#  if defined (SIO_ENABLE_SIO_UART0)
  _install_int_handler(Lin_InterruptPriority_0, (void (*) (int)) BrsHwLin0Interrupt, 0);
#  endif
#  if defined (SIO_ENABLE_SIO_UART1)
  _install_int_handler(Lin_InterruptPriority_1, (void (*) (int)) BrsHwLin1Interrupt, 0);
#  endif
#  if defined (SIO_ENABLE_SIO_UART2)
  _install_int_handler(Lin_InterruptPriority_2, (void (*) (int)) BrsHwLin2Interrupt, 0);
#  endif
#  if defined (SIO_ENABLE_SIO_UART3)
  _install_int_handler(Lin_InterruptPriority_3, (void (*) (int)) BrsHwLin3Interrupt, 0);
#  endif
# endif /*VGEN_ENABLE_LIN_DRV*/

# if defined (VGEN_ENABLE_DRVFR__BASEASR)
  _install_int_handler(BRSHW_FRLINE0PRIO, (void (*) (int)) BrsHwFrLine0Interrupt , 0);
  _install_int_handler(BRSHW_FRTIME0PRIO, (void (*) (int)) BrsHwFrTimer0Interrupt, 0);
  mtcr (0xfe2c, 0x00000000);  /* 2 clocks per Arb.cycle , 4 Arb.cycles , IE off */
  isync();
# endif /*VGEN_ENABLE_DRVFR__BASEASR*/

# if defined (VGEN_ENABLE_DRVETH__BASEASR)
  _install_int_handler(BRSHW_ETHPRIO, (void (*) (int)) EthIsr_0 , 0);
# endif

#else /*BRS_COMP_GNU*/
# if defined (VGEN_ENABLE_DRVFR__BASEASR)
  mtcr (0xfe2c, 0x00000000);     /* 2 clocks per Arb.cycle , 4 Arb.cycles , IE off */
  isync();
# endif /*VGEN_ENABLE_DRVFR__BASEASR*/
#endif /*else BRS_COMP_GNU*/

#if defined (VGEN_ENABLE_LIN_DRV)
# if defined (SIO_ENABLE_SIO_UART0)
  BRS_SRC_LIN0RX = 0x00000400 | Lin_InterruptPriority_0;
  BRS_SRC_LIN0TX = 0x00000400 | Lin_InterruptPriority_0;
  BRS_SRC_LIN0EX = 0x00000400 | Lin_InterruptPriority_0;
# endif
# if defined (SIO_ENABLE_SIO_UART1)
  BRS_SRC_LIN1RX = 0x00000400 | Lin_InterruptPriority_1;
  BRS_SRC_LIN1TX = 0x00000400 | Lin_InterruptPriority_1;
  BRS_SRC_LIN1EX = 0x00000400 | Lin_InterruptPriority_1;
# endif
# if defined (SIO_ENABLE_SIO_UART2)
  BRS_SRC_LIN2RX = 0x00000400 | Lin_InterruptPriority_2;
  BRS_SRC_LIN2TX = 0x00000400 | Lin_InterruptPriority_2;
  BRS_SRC_LIN2EX = 0x00000400 | Lin_InterruptPriority_2;
# endif
# if defined (SIO_ENABLE_SIO_UART3)
  BRS_SRC_LIN3RX = 0x00000400 | Lin_InterruptPriority_3;
  BRS_SRC_LIN3TX = 0x00000400 | Lin_InterruptPriority_3;
  BRS_SRC_LIN3EX = 0x00000400 | Lin_InterruptPriority_3;
# endif
#endif /*VGEN_ENABLE_LIN_DRV*/

#if defined (VGEN_ENABLE_DRVFR__BASEASR)
  /* enable line0 and time0 interrupt,
            line1 and time1 interrupt */
  BRS_SRC_ERAYINT0  = 0x00000400 | BRSHW_FRLINE0PRIO;
  BRS_SRC_ERAYINT1  = 0x00000400 | BRSHW_FRLINE1PRIO;
  BRS_SRC_ERAYTINT0 = 0x00000400 | BRSHW_FRTIME0PRIO;
  BRS_SRC_ERAYTINT1 = 0x00000400 | BRSHW_FRTIME1PRIO;
#endif

#if defined (VGEN_ENABLE_DRVETH__BASEASR)
  BRS_SRC_ETH  = 0x00000400 | BRSHW_ETHPRIO;
#endif
}
#endif /*!BRS_OS_USECASE_OSGEN7*/

/*****************************************************************************/
/**
 * @brief      Disables the global interrupt of the micro. This is done in a
 *             "save way" to allow also nested calls of BrsHwDisableInterrupt
 *             and BrsHwRestoreInterrupt. The first call of BrsHwDisableInterrupt
 *             stores the current state of the global INT flag and the last
 *             call to BrsHwRestoreInterrupt restores the state.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from all modules to disable the global interrupt
 */
/*****************************************************************************/
void BrsHwDisableInterrupt(void)
{
  /* No check for "overrun" of nested INT lock counter is performed, due to more
  *  than 255 nested calls to BrsHwDisableInterrupt are very unlikely. */
  if (bBrsHwIntDiCounter == 0)
  {
    bBrsHwICR = mfcr(0xFE2C) & 0x08000; /* Read currend status of IE bit */
    disable_interrupt();
  }

  bBrsHwIntDiCounter++;
}

/*****************************************************************************/
/**
 * @brief      Restores the state of the global interrupt of the micro. This
 *             is done in a "save way" to allow also nested calls of
 *             BrsHwDisableInterrupt and BrsHwRestoreInterrupt. The first call
 *             of BrsHwDisableInterrupt stores the current state of the global
 *             INT flag and the last call to BrsHwRestoreInterrupt restores the
 *             state.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from all modules to enable the global interrupt
 */
/*****************************************************************************/
void BrsHwRestoreInterrupt(void)
{
  /* Check for illegal call of BrsHwRestoreInterrupt. If this function is called
   *  too often, the INT lock works incorrect. */
  if (bBrsHwIntDiCounter == 0)
  {
    /* Check is only performed, if no OS is used */
  }

  bBrsHwIntDiCounter--;
  if (bBrsHwIntDiCounter == 0)
  {
    if (bBrsHwICR)
    {
      enable_interrupt();
    }
  }
}

/*****************************************************************************/
/**
 * @brief      restart ECU (issue a software reset or jump to startup code)
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. ECU state handling
 */
/*****************************************************************************/
void BrsHwSoftwareResetECU(void)
{
  BrsHwDisableInterrupt();

  BrsHwUnlockInit();
  BRS_SWRSTCON |= 0x00000002;
  BrsHwLockInit();
}

#if defined (BRS_ENABLE_SUPPORT_LEDS)
/*****************************************************************************/
/**
 * @brief      A platform specific usage of LedNumber is used to toggle a LED.
*              Please note, that not every EVA hardware supports LEDs and due
*              to this do not use this feature for a general test case!
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from all modules to set or clear a LED
 */
/*****************************************************************************/
void BrsHwSetLed(
  /*
   *  Description        : Number of the LED to be handled
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..7
   */
  uint8 LedNumber,
  /*
   *  Description        : New state of the LED
   *  Direction          : in
   *  Modified           : no
   *  Val. range / Coding: 0..1
   */
  uint8 NewState
)
{
#if defined (VGEN_ENABLE_DRVDIO)
  #error "Configure the valid DioChannel for the LED within your DrvDio config and set it as value for BrsHw_DioLED_Channel. Or disable BRS_ENABLE_SUPPORT_LEDS."
  Dio_ChannelType BrsHw_DioLED_Channel = DioConf_DioChannel_DioChannel_LED;

  Dio_WriteChannel(BrsHw_DioLED_Channel, NewState);

#else
  BrsHwPort_SetLevel(BRSHW_PORT_LED, NewState);
#endif
}
#endif /*BRS_ENABLE_SUPPORT_LEDS*/

/*****************************************************************************/
/**
 * @brief      This API is used for the BRS time measurement support to get a
 *             default time value for all measurements with this platform to
 *             be able to compare time measurements on different dates based
 *             on this time result.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from TimeMeasurement
 */
/*****************************************************************************/
void BrsHwTime100NOP(void)
{
  BrsHwDisableInterrupt();

  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();

  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();

  BrsHwRestoreInterrupt();
}

/*****************************************************************************/
/**
 * @brief Routine to unlock registers that are normally protected
 * @pre   Interrupts must be disabled
 */
/*****************************************************************************/
void BrsHwUnlockInit(void)
{
  volatile uint32 wdtcon0;
  /*
   * 1st step: Password access (create password and send to WDT_CON0)
   */
  wdtcon0 = BRS_SFR_WDTCON0;
  wdtcon0 &= 0xFFFFFF01;     /* clear WDTLCK, WDTHPW0, WDTHPW1 */
  wdtcon0 |= 0xF0;           /* set WDTHPW1 to 0xf */
  wdtcon0 |= 0x01;           /* 1 must be written to ENDINIT for password access
                                (but this will not actually modify the bit)      */
  BRS_SFR_WDTCON0 = wdtcon0; /* modify access to WDTCON0 */
  /*
   * 2nd step: Modify access, set the bit ENDINIT to 1 or 0 to allow access to
   *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
   */
  wdtcon0 &= 0xFFFFFFF0;     /* clear WDTHPW0, WDTLCK, ENDINIT  */
  wdtcon0 |= 0x02;           /* WDTHPW0=0, WDTLCK=1, ENDINIT=0 */
  isync();
  BRS_SFR_WDTCON0 = wdtcon0;
  wdtcon0 = BRS_SFR_WDTCON0; /* read is required */
}

/*****************************************************************************/
/**
 * @brief Routine to lock registers that are normally protected
 * @pre   Interrupts must be disabled
 */
/*****************************************************************************/
void BrsHwLockInit(void)
{
 /* AURIX */
  volatile uint32 wdtcon0;
  /*
   * 1st step: Password access (create password and send to WDT_CON0)
   */
  wdtcon0 = BRS_SFR_WDTCON0;
  wdtcon0 &= 0xFFFFFF01;     /* clear WDTLCK, WDTHPW0, WDTHPW1 */
  wdtcon0 |= 0xF0;           /* set WDTHPW1 to 0xf */
  wdtcon0 |= 0x01;           /* 1 must be written to ENDINIT for password access
                                 (but this will not actually modify the bit) */
  BRS_SFR_WDTCON0 = wdtcon0; /* modify access to WDTCON0 */
  /*
   * 2nd step: Modify access, set the bit ENDINIT to 1 or 0 to allow access to
   *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
   */
  wdtcon0 &= 0xFFFFFFF0;     /* clear WDTHPW0, WDTLCK, ENDINIT  */
  wdtcon0 |= 0x03;           /* WDTHPW0=0, WDTLCK=1, ENDINIT=0 */
  isync();
  BRS_SFR_WDTCON0 = wdtcon0;
  wdtcon0 = BRS_SFR_WDTCON0; /* read is required */
}

/*****************************************************************************/
/**
 * @brief Routine to unlock registers that are safety protected
 * @pre   Interrupts must be disabled
 */
/*****************************************************************************/
void BrsHwSafetyUnlockInit(void)
{
  volatile uint32 wdtcon0;
  /*
   * 1st step: Password access (create password and send to WDT_CON0)
   */
  wdtcon0 = BRS_SFR_WDTSCON0;
  wdtcon0 &= 0xFFFFFF01;     /* clear WDTLCK, WDTHPW0, WDTHPW1 */
  wdtcon0 |= 0xF0;           /* set WDTHPW1 to 0xf */
  wdtcon0 |= 0x01;           /* 1 must be written to ENDINIT for password access
                                (but this will not actually modify the bit)      */
  BRS_SFR_WDTSCON0 = wdtcon0; /* modify access to WDTCON0 */
  /*
   * 2nd step: Modify access, set the bit ENDINIT to 1 or 0 to allow access to
   *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
   */
  wdtcon0 &= 0xFFFFFFF0;     /* clear WDTHPW0, WDTLCK, ENDINIT  */
  wdtcon0 |= 0x02;           /* WDTHPW0=0, WDTLCK=1, ENDINIT=0 */
  isync();
  BRS_SFR_WDTSCON0 = wdtcon0;
  wdtcon0 = BRS_SFR_WDTSCON0; /* read is required */
}

/*****************************************************************************/
/**
 * @brief Routine to lock registers that are normally protected
 * @pre   Interrupts must be disabled
 */
/*****************************************************************************/
void BrsHwSafetyLockInit(void)
{
  volatile uint32 wdtcon0;
  /*
   * 1st step: Password access (create password and send to WDT_CON0)
   */
  wdtcon0 = BRS_SFR_WDTSCON0;
  wdtcon0 &= 0xFFFFFF01;     /* clear WDTLCK, WDTHPW0, WDTHPW1 */
  wdtcon0 |= 0xF0;           /* set WDTHPW1 to 0xf */
  wdtcon0 |= 0x01;           /* 1 must be written to ENDINIT for password access
                                 (but this will not actually modify the bit)      */
  BRS_SFR_WDTSCON0 = wdtcon0; /* modify access to WDTCON0 */
  /*
   * 2nd step: Modify access, set the bit ENDINIT to 1 or 0 to allow access to
   *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
   */
  wdtcon0 &= 0xFFFFFFF0;     /* clear WDTHPW0, WDTLCK, ENDINIT  */
  wdtcon0 |= 0x03;           /* WDTHPW0=0, WDTLCK=1, ENDINIT=0 */
  isync();
  BRS_SFR_WDTSCON0 = wdtcon0;
  wdtcon0 = BRS_SFR_WDTSCON0; /* read is required */
}

void _endinit(void)
{
  /* enable GPT12 clock */
  BRS_GPT_CLC = 0x00000000UL;

  /* wait until the module disable flag is cleared*/
  while ((BRS_GPT_CLC & 0x00000002UL)==2){}
}

/* DrvCan/DrvLin/DrvFr/DrvEth application callback functions for access protection of critical registers */
/* As different driver versions use different callback names, they are duplicated. */

void Appl_UnlockInit(void)
{
  BrsHwUnlockInit();
}

void Appl_UnlockEndinit(void)
{
  BrsHwUnlockInit();
}

void Appl_LockInit(void)
{
  BrsHwLockInit();
}

void Appl_LockEndinit(void)
{
  BrsHwLockInit();
}
 /*VGEN_ENABLE_CAN_DRV || VGEN_ENABLE_LIN_DRV || VGEN_ENABLE_DRVFR__BASEASR || VGEN_ENABLE_DRVETH__BASEASR*/

/* DrvCan Application function for wait mechanism */

void ApplCanWaitSetMCR(void)
{
  uint32 i;
  for (i=0; i<10000; i++)
  {
    nop();
  }
}


# if defined (BRSASR_ENABLE_SAFECTXSUPPORT)
/*****************************************************************************/
/**
 * @brief      This API is used to enable hardware access in untrusted mode
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsAsrInitBsw
 */
/*****************************************************************************/
void BrsHw_EnableHwAccess(void)
{
  /* Nothing to do for Aurix yet */
}
# else
  /* BrsHw_EnableHwAccess() removed by Organi, because of ALM attributes of project */
# endif /*BRSASR_ENABLE_SAFECTXSUPPORT*/
