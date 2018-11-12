
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
 *           File:  Lin.c
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
 *    Description:  Implementation of the AUTOSAR LIN Driver
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

#define LIN_SOURCE
/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* Disable the following MISRA warnings because they would appear too often for individual suppression.
   See justification at the end of file */

/* PRQA S 0303 EOF */ /* MD_LIN_0303 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Os.h"
#include "Lin.h"
#include "EcuM_Cbk.h"
#include "LinIf_Cbk.h"

#if ( LIN_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif

#if ( LIN_E_TIMEOUT_TYPE_DET == STD_OFF ) 
# include "Dem.h"
#endif

#if ( LIN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON )
# include "Rtm.h"
#endif

#if ( LIN_USE_ECUM_BSW_ERROR_HOOK == STD_ON )
# include "EcuM_Error.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

#if ( LIN_SW_MAJOR_VERSION != 7 )
# error "Source and Header are inconsistent (LIN_SW_MAJOR_VERSION)!"
#endif
#if ( LIN_SW_MINOR_VERSION != 3 )
# error "Source and Header are inconsistent (LIN_SW_MINOR_VERSION)!"
#endif
#if ( LIN_SW_PATCH_VERSION != 0 )
# error "Source and Header are inconsistent (LIN_SW_PATCH_VERSION)!"
#endif

#if ( LIN_TPS_MAJOR_VERSION != LIN_SW_MAJOR_VERSION )
# error "Source and Types Header are inconsistent (LIN_TPS_MAJOR_VERSION)!"
#endif
#if ( LIN_TPS_MINOR_VERSION != LIN_SW_MINOR_VERSION )
# error "Source and Types Header are inconsistent (LIN_TPS_MINOR_VERSION)!"
#endif
#if ( LIN_TPS_PATCH_VERSION != LIN_SW_PATCH_VERSION )
# error "Source and Types Header are inconsistent (LIN_TPS_PATCH_VERSION)!"
#endif

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 **********************************************************************************************************************/

#if   ( LIN_CONFIGURATION_VARIANT != LIN_CONFIGURATION_VARIANT_PRECOMPILE ) && \
      ( LIN_CONFIGURATION_VARIANT != LIN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE )
# error "LIN_CONFIGURATION_VARIANT not in valid range, check settings in generation tool!"
#endif

#if ( LIN_HL_GENERATORMSR_IMPLEMENTATION != LIN_HL_GENERATORMSR_COMPATIBILITY_VERSION )
# error "Version of the Hl generator is not consistent with the implementation!"
#endif

#if ( LIN_LL_GENERATORMSR_IMPLEMENTATION != LIN_LL_GENERATORMSR_COMPATIBILITY_VERSION )
# error "Version of the LL generator is not consistent with the implementation!"
#endif

#if   ( defined LIN_COMP_TASKING )                                                                                      /* COV_LIN_COMPILER */
#elif ( defined LIN_COMP_GNU     )                                                                                      /* COV_LIN_COMPILER */
#else
# error "Selected compiler not supported / tested. Check settings in generation tool!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#if !defined osWritePeripheral32
/* PRQA S 3453 2 */ /* MD_MSR_19.6 */
# define LIN_PROTECTED_AREA_ENDINIT 0
# define osWritePeripheral32( a, b, c ) ChannelBaseAddress->CLC = 0x0008u
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/* DET Report Handling */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define Lin_Det_ReportError( Lin_ApiId, Lin_ErrorCode) (Det_ReportError(LIN_MODULE_ID, 0, (Lin_ApiId), (Lin_ErrorCode)))

/* RTM Support */
#if ( LIN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON )
  /* PRQA S 3453, 342 2 */ /* MD_MSR_19.7, MD_MSR_19.13 */
# define Lin_Rtm_Start(RtmMeasurementPoint_id)  Rtm_Start( RtmConf_RtmMeasurementPoint_##RtmMeasurementPoint_id )
# define Lin_Rtm_Stop(RtmMeasurementPoint_id)   Rtm_Stop( RtmConf_RtmMeasurementPoint_##RtmMeasurementPoint_id )
#else
# define Lin_Rtm_Start(RtmMeasurementPoint_id)
# define Lin_Rtm_Stop(RtmMeasurementPoint_id)
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* Define if not already defined */
#if !defined (LIN_LOCAL)                                                                                                /* COV_LIN_COMPATIBILITY */
# define LIN_LOCAL static
#endif

#if !defined (LIN_LOCAL_INLINE)                                                                                         /* COV_LIN_COMPATIBILITY */
# define LIN_LOCAL_INLINE LOCAL_INLINE
#endif

/* Bitmasks for register LIN_CSR */
          /* Clock Select */
#define   LIN_CSR_CLKSEL_MASK       ((uint32)0x0000000Fu)

/* Defines for register LIN_FRAMECON */
          /* ODD=0, PEN=0, CEN=1, MSB=0, MODE=3(LIN), LEAD=2, STOP=1, IDLE=1 */
#define   LIN_FRAMECON_DEFAULT      ((uint32)0x20032240u)

/* Defines for register LIN_LINCON */
          /* enable master mode, enable hardware checksum logic  0x06000000u */
#define   LIN_LINCON_DEFAULT        ((uint32)0x06000000u) 

/* Defines for register LIN_BITCON */
          /* 3 samples per bit, bits 7,8 and 9, oversampling factor 16 */
#define   LIN_BITCON_DEFAULT        ((uint32)0x890F0000u)

/* Defines for register LIN_BTIMER */
          /* 14 bit times sync break length */
#define   LIN_LINBTIMER_DEFAULT     ((uint32)0x0000000Eu)

/* Defines for register LIN_DATCON */
          /* response timeout to 256 */
#define   LIN_DATCON_MAXRESP        ((uint32)0x00FF0000u)
          /* response mode set to response part */
#define   LIN_DATCON_RM_RESP        ((uint32)0x00004000u)
          /* response mode set to whole frame */
#define   LIN_DATCON_RM_FRAME       ((uint32)0x00000000u)
          /* classic checksum mode */
#define   LIN_DATCON_CSM_CLASSIC    ((uint32)0x00000000u)
          /* classic checksum mode */
#define   LIN_DATCON_CSM_ENH        ((uint32)0x00008000u)
          /* header only mode */
#define   LIN_DATCON_HO             ((uint32)0x00002000u)

/* Defines for register LIN_RXFIFOCON */
          /* flush Rx FIFO, disable inlet */
#define   LIN_RXFIFOCON_CLEAR_STOP  ((uint32)0x00000001u)
          /* enable inlet, get 1 byte per read */
#define   LIN_RXFIFOCON_ENABLE      ((uint32)0x00000042u)
          /* FIFO filling level mask */
#define   LIN_RXFIFOCON_FILL_MASK   ((uint32)0x001F0000u)

/* Defines for register LIN_TXFIFOCON */
          /* flush Tx FIFO, disable outlet, inlet width = 1 */
#define   LIN_TXFIFOCON_CLEAR_STOP  ((uint32)0x00000041u)
          /* enable outlet, inlet width = 1 => take one byte into FIFO per write to TXDATA register */
#define   LIN_TXFIFOCON_ENABLE      ((uint32)0x00000042u)

/* Defines for register LIN_IOCR */
          /* Rx signal status mask */
#define   LIN_IOCR_RXM              ((uint32)0x40000000u)

/* Defines for register LIN_LINHTIMER */
          /* default header timeout value of 49 bits */
#define   LIN_LINHTIMER_DEFAULT     ((uint32)0x00000031u)
          /* alternate Rx input selection mask */
#define   LIN_IOCR_ALTI             ((uint32)0x00000007u)

/* Define for registers FLAGS, FLAGSENABLE, FLAGSCLEAR, FLAGSSET ( interrupt bits / flags ) */
          /* Transmit Header End */
#define   LIN_FLAGS_TH              ((uint32)0x00000001u)
          /* Transmit Response End */
#define   LIN_FLAGS_TR              ((uint32)0x00000002u)
          /* Receive Header End */
#define   LIN_FLAGS_RH              ((uint32)0x00000004u)
          /* Receive Response End */
#define   LIN_FLAGS_RR              ((uint32)0x00000008u)
          /* Falling Edge 1 -> 0 */
#define   LIN_FLAGS_FED             ((uint32)0x00000020u)
          /* Rising Edge 0 -> 1 */
#define   LIN_FLAGS_RED             ((uint32)0x00000040u)
          /* Transmit Wake Request */
#define   LIN_FLAGS_TWRQ            ((uint32)0x00002000u)
          /* Transmit Header Request */
#define   LIN_FLAGS_THRQ            ((uint32)0x00004000u)
          /* Transmit Response Request */
#define   LIN_FLAGS_TRRQ            ((uint32)0x00008000u)
          /* Parity Error */
#define   LIN_FLAGS_PE              ((uint32)0x00010000u)
          /* Transmission Completed */
#define   LIN_FLAGS_TC              ((uint32)0x00020000u)
          /* Framing Error */
#define   LIN_FLAGS_FE              ((uint32)0x00040000u)
          /* Header Timeout */
#define   LIN_FLAGS_HT              ((uint32)0x00080000u)
          /* Response Timeout */
#define   LIN_FLAGS_RT              ((uint32)0x00100000u)
          /* Break Detected */
#define   LIN_FLAGS_BD              ((uint32)0x00200000u)
          /* LIN Parity Error */
#define   LIN_FLAGS_LP              ((uint32)0x00400000u)
          /* LIN Autobaud Detection */
#define   LIN_FLAGS_LA              ((uint32)0x00800000u)
          /* LIN Checksum Error */
#define   LIN_FLAGS_LC              ((uint32)0x01000000u)
          /* Collision Detection */
#define   LIN_FLAGS_CE              ((uint32)0x02000000u)
          /* Receive FIFO Overflow */
#define   LIN_FLAGS_RFO             ((uint32)0x04000000u)
          /* Receive FIFO Underflow */
#define   LIN_FLAGS_RFU             ((uint32)0x08000000u)
          /* Receive FIFO Level */
#define   LIN_FLAGS_RFL             ((uint32)0x10000000u)
          /* Transmit FIFO Overflow */
#define   LIN_FLAGS_TFO             ((uint32)0x40000000u)
          /* Transmit FIFO Level */
#define   LIN_FLAGS_TFL             ((uint32)0x80000000u)

#define   LIN_FLAGSENABLE_OPERATIONAL   ((uint32)( 0 ))

#define   LIN_FLAGSENABLE_TRANSMISSION  ((uint32)(  LIN_FLAGS_TR | \
                                                    LIN_FLAGS_RR | \
                                                    LIN_FLAGS_FE | \
                                                    LIN_FLAGS_RT | \
                                                    LIN_FLAGS_LC | \
                                                    LIN_FLAGS_CE))

#define   LIN_FLAGSCLEAR_DEFAULT        ((uint32)0xDFFFE06Fu)

/* detecting a wakeup frame is only possible via the FED flag */
#define   LIN_FLAGSENABLE_SLEEP         ((uint32)(LIN_FLAGS_FED))

#define   LIN_FLAGS_ERROR               ((uint32)(  LIN_FLAGS_FE | \
                                                    LIN_FLAGS_RT | \
                                                    LIN_FLAGS_LC | \
                                                    LIN_FLAGS_CE ))

#define   LIN_WAKEUP_PATTERN          ((uint8)0x80u)

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#if (LIN_USE_INIT_POINTER == STD_ON)

# define LIN_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"                                                                                                    /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Pointer to Global Configuration */
LIN_LOCAL P2CONST(Lin_ConfigType, LIN_VAR_NOINIT, LIN_PBCFG) Lin_ConfigDataPtr;

# define LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"                                                                                                    /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif

#if ( LIN_DEV_ERROR_DETECT == STD_ON )
# define LIN_DEV_UNINITVALUE                              ((uint8)0x00u)
# define LIN_DEV_INITVALUE                                ((uint8)0xA5u)

# define LIN_START_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h"                                                                                                    /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Variable Lin_Dev_InitDetect must be initialized after reset for working debug check */
LIN_LOCAL VAR(uint8, LIN_VAR_ZERO_INIT) Lin_Dev_InitDetect = LIN_DEV_UNINITVALUE;
# define LIN_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h"                                                                                                    /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
/* none */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
 
#define LIN_START_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  Lin_CheckIrqWakeupEvent
 **********************************************************************************************************************/
/*! \brief      Checks an wake up event.
 *  \details    If the channel has a EcuM Wakeup Source ID the wake up event are set and EcuM_CheckWakeup() are called.
 *  \param[in]  ChannelConfigIdx Channel index of configuration.
 *  \pre        -
 *  \context    ANY
 **********************************************************************************************************************/
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_CheckIrqWakeupEvent( Lin_ChannelConfigIdxOfChannelHwType ChannelConfigIdx );

/***********************************************************************************************************************
 *  Lin_SetSleep
 **********************************************************************************************************************/
/*! \brief      Set sleep.
 *  \details    Set the hardware and software state to sleep.
 *  \param[in]  ChannelConfigIdx  Channel index of configuration.
 *  \param[in]  ApiId             Lin Service ID, needed only for some hardware.
 *  \pre        -
 *  \context    ANY
 **********************************************************************************************************************/
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetSleep( Lin_ChannelConfigIdxOfChannelHwType ChannelConfigIdx, 
                                                    uint8 ApiId );

/***********************************************************************************************************************
 *  Lin_SetHardwareWake
 **********************************************************************************************************************/
/*! \brief      Set hardware to operational.
 *  \details    Set the hardware to operational without sending a wake-up-frame. Software state does not change.
 *  \param[in]  ChannelConfigIdx  Channel index of configuration.
 *  \param[in]  ApiId             Lin Service ID, needed only for some hardware.
 *  \pre        -
 *  \context    ANY
 **********************************************************************************************************************/
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetHardwareWake( Lin_ChannelConfigIdxOfChannelHwType ChannelConfigIdx,
                                                           uint8 ApiId );

/* --- Platform specific local function prototypes() ---------------------------------------------------------------- */

/***********************************************************************************************************************
 *  Appl_UnlockEndinit
 **********************************************************************************************************************/
/*! \brief       Unlock Endinit-Protect. 
 *  \details     Unlocks registers that are normally protected through Endinit-Protect.
 *  \pre         LIN interrupts for hardware channel of Channel must be locked.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The user application has provide this function.
 **********************************************************************************************************************/
extern FUNC(void, LIN_APPL_CODE) Appl_UnlockEndinit( void );                                                            /* PRQA S 3447 */ /* MD_LIN_3447 */ 

/***********************************************************************************************************************
 *  Appl_LockEndinit
 **********************************************************************************************************************/
/*! \brief       Lock Endinit-Protect.
 *  \details     Locks registers that are normally protected through Endinit-Protect.
 *  \pre         LIN interrupts for hardware channel of Channel must be locked.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The user application has provide this function.
 **********************************************************************************************************************/
extern FUNC(void, LIN_APPL_CODE) Appl_LockEndinit( void );                                                              /* PRQA S 3447 */ /* MD_LIN_3447 */ 
/* ------------------------------------------------------------------------------------------------------------------ */

#define LIN_STOP_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_19.1 */ 

/**********************************************************************************************************************
 *  FUNCTIONS
 **********************************************************************************************************************/
 
#define LIN_START_SEC_CODE_ISR
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  Lin_Interrupt
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, LIN_CODE_ISR) Lin_Interrupt( uint8 ChannelHw )
{
  VAR(Lin_ChannelConfigIdxOfChannelIdType, AUTOMATIC) ChannelConfigIdx;
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;
  P2VAR(Lin_RegisterStruct, AUTOMATIC, LIN_VAR_REGS) ChannelBaseAddress;
  VAR(uint32, AUTOMATIC) Flags;
  VAR(uint32, AUTOMATIC) RxFifoCon;
  VAR(volatile uint8, AUTOMATIC) DummyUint8 = 0;

  /* Runtime Measurement start */
  Lin_Rtm_Start(Lin_Interrupt)

  /* #10 Check hardware channel parameter validity against configuration */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  if ( Lin_GetSizeOfChannelHw() <= ChannelHw )
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# if( LIN_POSTBUILD_VARIANT_SUPPORT == STD_ON )
  else if ( Lin_IsInvalidHndOfChannelHw( ChannelHw ) )                                                                  /* PRQA S 3325 */ /* MD_MSR_14.1 */ 
  { /* A gap in the indirection could only occur if a channel not present on selected variant */                        /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;  
  }
# endif
  else
#endif
  {
    ChannelConfigIdx = Lin_GetChannelConfigIdxOfChannelHw( ChannelHw );
    
/* --- Platform specific implementation of Lin_Interrupt() ---------------------------------------------------------- */
    /* pointer to lin module registers */
    ChannelBaseAddress = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx );
    
    /* #20 Read hardware status flags to determine hardware status and reset flags */
    /* read status flags */
    Flags     = ChannelBaseAddress->FLAGS;
    RxFifoCon = ChannelBaseAddress->RXFIFOCON;
    /* clear status flags */
    ChannelBaseAddress->FLAGSCLEAR = Flags;                                                                             /* SBSW_LIN_PTR_HW */

    /* #30 Handling current channel state according DSGN-Lin23401 */
    switch( Lin_GetInternalStateOfChannelData( ChannelConfigIdx ) )
    {
      case LIN_ONSLEEP_INTERNALSTATEOFCHANNELDATA:
        Lin_CheckIrqWakeupEvent( ChannelConfigIdx );
        break;
        
      case LIN_ONSLEEP_PENDING_INTERNALSTATEOFCHANNELDATA:
        /* stay until Lin_GetStatus() */
        break;
        
      case LIN_ONWAKEUP_PENDING_INTERNALSTATEOFCHANNELDATA:
        Lin_SetHardwareWake( ChannelConfigIdx, LIN_SID_INTERRUPT_ID );
        Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONWAKE_INTERNALSTATEOFCHANNELDATA );                   /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
        break;

      case LIN_ONTX_BUSY_INTERNALSTATEOFCHANNELDATA:
        if ( ( Flags & LIN_FLAGS_TR ) != 0 )
        { /* TX message successful transmitted */
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONTX_OK_INTERNALSTATEOFCHANNELDATA );                /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
        }
        else if( ( Flags & LIN_FLAGS_TH ) != 0 )
        { /* No successful TX message but header was successful transmitted */
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONTX_ERROR_INTERNALSTATEOFCHANNELDATA );             /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
        }
        else
        { /* No successful TX message and no header was successful transmitted */
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONTX_HEADER_ERROR_INTERNALSTATEOFCHANNELDATA );      /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */        
        }
        break;

      case LIN_ONRX_BUSY_INTERNALSTATEOFCHANNELDATA:
        if ( ( Flags & LIN_FLAGS_RR ) != 0 )
        { /* Response successfully received */
          /* dummy read to ignore received PID */
          DummyUint8 = (uint8)ChannelBaseAddress->RXDATA;

          /* store RX Data */
          Lin_GetDataBufferOfChannelData( ChannelConfigIdx )[0] = (uint8)ChannelBaseAddress->RXDATA;                    /* SBSW_LIN_BUFFER_WRITE */
          Lin_GetDataBufferOfChannelData( ChannelConfigIdx )[1] = (uint8)ChannelBaseAddress->RXDATA;                    /* SBSW_LIN_BUFFER_WRITE */
          Lin_GetDataBufferOfChannelData( ChannelConfigIdx )[2] = (uint8)ChannelBaseAddress->RXDATA;                    /* SBSW_LIN_BUFFER_WRITE */
          Lin_GetDataBufferOfChannelData( ChannelConfigIdx )[3] = (uint8)ChannelBaseAddress->RXDATA;                    /* SBSW_LIN_BUFFER_WRITE */
          Lin_GetDataBufferOfChannelData( ChannelConfigIdx )[4] = (uint8)ChannelBaseAddress->RXDATA;                    /* SBSW_LIN_BUFFER_WRITE */
          Lin_GetDataBufferOfChannelData( ChannelConfigIdx )[5] = (uint8)ChannelBaseAddress->RXDATA;                    /* SBSW_LIN_BUFFER_WRITE */
          Lin_GetDataBufferOfChannelData( ChannelConfigIdx )[6] = (uint8)ChannelBaseAddress->RXDATA;                    /* SBSW_LIN_BUFFER_WRITE */
          Lin_GetDataBufferOfChannelData( ChannelConfigIdx )[7] = (uint8)ChannelBaseAddress->RXDATA;                    /* SBSW_LIN_BUFFER_WRITE */

          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONRX_OK_INTERNALSTATEOFCHANNELDATA );                /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
        }
        else if( ( Flags & LIN_FLAGS_RH) == 0 )
        { /* no header was successful transmitted */
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONTX_HEADER_ERROR_INTERNALSTATEOFCHANNELDATA );      /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
        }
        else if ( ( (RxFifoCon & LIN_RXFIFOCON_FILL_MASK ) == (uint32)0x00010000u ) &&   /* only PID received */
                  ( (Flags & (LIN_FLAGS_FE | LIN_FLAGS_LC | LIN_FLAGS_CE)) == 0 ) )      /* no error expect timeout */
        { /* no response byte received */
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONRX_NO_RESPONSE_INTERNALSTATEOFCHANNELDATA );       /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
        }
        else
        { /* response partly received */
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONRX_ERROR_INTERNALSTATEOFCHANNELDATA );             /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
        }
        break;
        
      case LIN_ONS2S_BUSY_INTERNALSTATEOFCHANNELDATA:
        if ( ( Flags & LIN_FLAGS_ERROR) == 0 )
        { /* header was successful transmitted */
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONTX_OK_INTERNALSTATEOFCHANNELDATA );                /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
        }
        else
        { /* any error on slave to slave is an header error */
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONTX_HEADER_ERROR_INTERNALSTATEOFCHANNELDATA );      /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */      
        }
        break;
      
      default:
        /* interrupt not needed in other states than above --> ignore */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
        ErrorId = LIN_E_STATE_TRANSITION;
#endif
        break;
    }

/* ------------------------------------------------------------------------------------------------------------------ */
  }

#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_INTERRUPT_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif

  /* Runtime Measurement stop */
  Lin_Rtm_Stop(Lin_Interrupt)
  LIN_DUMMY_STATEMENT(DummyUint8);
}                                                                                                                       /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

#define LIN_STOP_SEC_CODE_ISR
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define LIN_START_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  Lin_SendFrame
 **********************************************************************************************************************/
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
FUNC(Std_ReturnType, LIN_CODE) Lin_SendFrame( uint8 Channel,
                                              P2VAR(Lin_PduType, AUTOMATIC, LIN_APPL_VAR) PduInfoPtr )                  /* PRQA S 3673 */ /* MD_LIN_HL_16.7 */
{
  VAR(Lin_ChannelConfigIdxOfChannelIdType, AUTOMATIC) ChannelConfigIdx;
  VAR(Std_ReturnType, AUTOMATIC) RetTmp = E_NOT_OK;
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;
  P2VAR(Lin_RegisterStruct, AUTOMATIC, LIN_VAR_REGS) ChannelBaseAddress;
  VAR(uint8_least, AUTOMATIC) BufferCounterTmp;
  LIN_LOCAL CONST(uint32, LIN_CONST) ResponseTimeoutDurations[8] =
  {  /* response timeout durations for different frame lengths in bit times */
    28  << 16,   /* 1 databyte  */
    42  << 16,   /* 2 databytes */
    56  << 16,   /* 3 databytes */
    70  << 16,   /* 4 databytes */
    84  << 16,   /* 5 databytes */
    98  << 16,   /* 6 databytes */
    112 << 16,   /* 7 databytes */
    126 << 16,   /* 8 databytes */
  };

  /* #10 Check if component is initialized */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  if ( Lin_Dev_InitDetect != LIN_DEV_INITVALUE )
  {
    ErrorId = LIN_E_UNINIT;
  }
  /* #20 Check PduInfoPtr parameter for NULL pointer */
  else if ( (void*)PduInfoPtr == NULL_PTR )
  {
    ErrorId = LIN_E_PARAM_POINTER;
  }
  /* #30 Check Channel parameter validity against configuration */
  else if ( Lin_GetSizeOfChannelId() <= Channel )
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# if( LIN_INVALIDHNDOFCHANNELID == STD_ON )
  else if ( Lin_IsInvalidHndOfChannelId( Channel ) )                                                                    /* PRQA S 3325 */ /* MD_MSR_14.1 */ 
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# endif
  else
#endif
  {
    /* Get channel RAM/ROM array index of Channel ID */ 
    ChannelConfigIdx = Lin_GetChannelConfigIdxOfChannelId( Channel );
    
    /* #35 Check if data length parameter is in range (1-8 data bytes) */
    if( (PduInfoPtr->Dl == 0) || (PduInfoPtr->Dl > 8)  )
    {      
      ErrorId = LIN_E_PARAM_VALUE;
    } 
    /* #40 Check if channel state not on sleep */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
    else if( (Lin_GetInternalStateOfChannelData( ChannelConfigIdx ) & 0x0F) == LIN_ONSLEEP_INTERNALSTATEOFCHANNELDATA )
    {
      ErrorId = LIN_E_STATE_TRANSITION;
    }
#endif
    else
    {
      RetTmp = E_OK;
/* --- Platform specific implementation of Lin_SendFrame() ---------------------------------------------------------- */
      /* pointer to lin module registers */
      ChannelBaseAddress = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx );

      /* #50 Stop any ongoing transmission on channel (reset hardware, clear hardware status flags) */
      /* flush Rx FIFO, disable FIFO inlet */
      ChannelBaseAddress->RXFIFOCON  = LIN_RXFIFOCON_CLEAR_STOP;                                                        /* SBSW_LIN_PTR_HW */
      /* flush Tx FIFO, disable FIFO outlet */
      ChannelBaseAddress->TXFIFOCON  = LIN_TXFIFOCON_CLEAR_STOP;                                                        /* SBSW_LIN_PTR_HW */
      /* clear all flags */
      ChannelBaseAddress->FLAGSCLEAR = ChannelBaseAddress->FLAGS;                                                       /* SBSW_LIN_PTR_HW */

      /* #60 Set hardware configuration according PDU values */
      /* configure PID to be sent */
      ChannelBaseAddress->TXDATA     = (uint32)PduInfoPtr->Pid;                                                         /* SBSW_LIN_PTR_HW */

      /* configure response length, timeout and checksum type */
      if ( PduInfoPtr->Cs == (Lin_FrameCsModelType)LIN_ENHANCED_CS )
      {
        /* set frame length, response duration and checksum type */
        ChannelBaseAddress->DATCON = (uint32)(ResponseTimeoutDurations[(PduInfoPtr->Dl-1)] |                            /* SBSW_LIN_PTR_HW */
                                             LIN_DATCON_CSM_ENH | LIN_DATCON_RM_RESP | (uint32)(PduInfoPtr->Dl-1));
      }
      else
      {
      /* set frame length, response duration and checksum type */
        ChannelBaseAddress->DATCON = (uint32)(ResponseTimeoutDurations[(PduInfoPtr->Dl-1)] |                            /* SBSW_LIN_PTR_HW */
                                             LIN_DATCON_CSM_CLASSIC | LIN_DATCON_RM_RESP | (uint32)(PduInfoPtr->Dl-1));
      }

      /* #70 Set state according DSGN-Lin23162 */
      switch( PduInfoPtr->Drc )
      {
        case (Lin_FrameResponseType)LIN_MASTER_RESPONSE:
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONTX_BUSY_INTERNALSTATEOFCHANNELDATA );              /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */

          /* write all data bytes to transmit register which are automatically shifted to Tx FIFO */
          for (BufferCounterTmp = 0; BufferCounterTmp < (PduInfoPtr->Dl); BufferCounterTmp++)
          {
            ChannelBaseAddress->TXDATA = (uint8)PduInfoPtr->SduPtr[BufferCounterTmp];                                   /* SBSW_LIN_PTR_HW */
          }

          ChannelBaseAddress->FLAGSENABLE = LIN_FLAGSENABLE_TRANSMISSION;                                               /* SBSW_LIN_PTR_HW */
          break;
        
        case (Lin_FrameResponseType)LIN_SLAVE_RESPONSE:
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONRX_BUSY_INTERNALSTATEOFCHANNELDATA );              /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */

          /* Because no interrupt is handled after header transmission, the Rx FIFO is enabled at this place, before
             header transmission. This means that there is also the PID in the rx buffer which has to be ignored. */
          ChannelBaseAddress->RXFIFOCON   = LIN_RXFIFOCON_ENABLE;                                                       /* SBSW_LIN_PTR_HW */
          ChannelBaseAddress->FLAGSENABLE = LIN_FLAGSENABLE_TRANSMISSION;                                               /* SBSW_LIN_PTR_HW */
          break;
        
        default: /* slave-to-slave frame */
          Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONS2S_BUSY_INTERNALSTATEOFCHANNELDATA );             /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */

          /* set initial timeout value to maximum according to datasheet */
          ChannelBaseAddress->DATCON      = LIN_DATCON_MAXRESP | LIN_DATCON_HO;                                         /* SBSW_LIN_PTR_HW */
          ChannelBaseAddress->FLAGSENABLE = LIN_FLAGSENABLE_TRANSMISSION | LIN_FLAGS_TH;                                /* SBSW_LIN_PTR_HW */
          break;
      }
      
      /* #80 Set hardware to start transmission of the LIN frame (including configure intern interrupt flags) */
      /* trigger header transmission and enable Tx Fifo here to allow sending the PID */
      ChannelBaseAddress->FLAGSSET  = LIN_FLAGS_THRQ;                                                                   /* SBSW_LIN_PTR_HW */
      ChannelBaseAddress->TXFIFOCON = LIN_TXFIFOCON_ENABLE;                                                             /* SBSW_LIN_PTR_HW */
      
      /* trigger response transmission (only on TX) */
      if( PduInfoPtr->Drc == (Lin_FrameResponseType)LIN_MASTER_RESPONSE )
      { /* according to Aurix User Manual (Lin Master Sequences) TRRQ flag should be set after THRQ flag */
        ChannelBaseAddress->FLAGSSET      = LIN_FLAGS_TRRQ;                                                             /* SBSW_LIN_PTR_HW */
      }
      
/* ------------------------------------------------------------------------------------------------------------------ */
    }
  }
#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_SENDFRAME_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif

  LIN_DUMMY_STATEMENT(Channel);

  return(RetTmp);
}                                                                                                                       /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  Lin_GetStatus
 **********************************************************************************************************************/
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
FUNC(Lin_StatusType, LIN_CODE) Lin_GetStatus( uint8 Channel,
                                              P2VAR(Lin_u8PtrType, AUTOMATIC, LIN_APPL_VAR) Lin_SduPtr )
{
  VAR(Lin_ChannelConfigIdxOfChannelIdType, AUTOMATIC) ChannelConfigIdx;
  VAR(Lin_StatusType, AUTOMATIC) RetTmp = LIN_NOT_OK;
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;
  /* #10 Check if component is initialized */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  if ( Lin_Dev_InitDetect != LIN_DEV_INITVALUE )
  {
    ErrorId = LIN_E_UNINIT;
  }
  /* #20 Check Lin_SduPtr parameter for NULL pointer */
  else if ( (void*)Lin_SduPtr == NULL_PTR )
  {
    ErrorId = LIN_E_PARAM_POINTER;
  }
  /* #30 Check Channel parameter validity against configuration */
  else if ( Lin_GetSizeOfChannelId() <= Channel )
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# if( LIN_INVALIDHNDOFCHANNELID == STD_ON )
  else if ( Lin_IsInvalidHndOfChannelId( Channel ) )                                                                    /* PRQA S 3325 */ /* MD_MSR_14.1 */ 
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# endif
  else
#endif
  {
    ChannelConfigIdx = Lin_GetChannelConfigIdxOfChannelId( Channel );
/* --- Platform specific implementation of Lin_GetStatus() ---------------------------------------------------------- */
    /* #40 Handle hardware specific behaviour */
    switch( Lin_GetInternalStateOfChannelData( ChannelConfigIdx ) )
    {
      case LIN_ONSLEEP_PENDING_INTERNALSTATEOFCHANNELDATA:
        Lin_SetSleep( ChannelConfigIdx, LIN_SID_INTERRUPT_ID );
        break;

      case LIN_ONWAKEUP_PENDING_INTERNALSTATEOFCHANNELDATA:
        Lin_SetHardwareWake( ChannelConfigIdx, LIN_SID_GETSTATUS_ID );
        Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONWAKE_INTERNALSTATEOFCHANNELDATA );                   /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
        break;
    
      case LIN_ONRX_OK_INTERNALSTATEOFCHANNELDATA:
        *Lin_SduPtr = Lin_GetDataBufferOfChannelData( ChannelConfigIdx );                                               /* SBSW_LIN_PTR */
        break;
        
      default:
        /* current state valid or nothing to do */
        break;
    }
    
    /* mask non ASR sub-states */
    RetTmp = (Lin_StatusType)(Lin_GetInternalStateOfChannelData( ChannelConfigIdx ) & 0x0F);
/* ------------------------------------------------------------------------------------------------------------------ */
  }

#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_GETSTATUS_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif

  LIN_DUMMY_STATEMENT(Channel);

  return(RetTmp);
}                                                                                                                       /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  Lin_CheckWakeup
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeup( uint8 Channel )
{
#if( LIN_LEAST_ONE_CHANNEL_WAKEUP_SUPPORT_ENABLED == STD_ON )

  VAR(Lin_ChannelConfigIdxOfChannelIdType, AUTOMATIC) ChannelConfigIdx;
  VAR(Std_ReturnType, AUTOMATIC) RetTmp = E_NOT_OK;
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;
  /* #10 Check if component is initialized */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  if ( Lin_Dev_InitDetect != LIN_DEV_INITVALUE )
  {
    ErrorId = LIN_E_UNINIT;
  }
  /* #20 Check Channel parameter validity against configuration */
  else if ( Lin_GetSizeOfChannelId() <= Channel )
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# if( LIN_INVALIDHNDOFCHANNELID == STD_ON )
  else if ( Lin_IsInvalidHndOfChannelId( Channel ) )                                                                    /* PRQA S 3325 */ /* MD_MSR_14.1 */ 
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# endif
  else
#endif
  {
    RetTmp = E_OK;
    ChannelConfigIdx = Lin_GetChannelConfigIdxOfChannelId( Channel );

    /* #30 Check if a wakeup event occurred */
    if ( Lin_GetInternalStateOfChannelData( ChannelConfigIdx ) == LIN_ONWAKEUP_EXTERNAL_INTERNALSTATEOFCHANNELDATA )
    {
      /* #40 Set channel state to operational (according DSGN-Lin22334) */
      Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONSLEEP_INTERNALSTATEOFCHANNELDATA );                    /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */

      /* #50 Inform EcuM and LinIf about wakeup */
      EcuM_SetWakeupEvent( Lin_GetEcuMWakeupSourceOfChannelConfig( ChannelConfigIdx ) );
      LinIf_WakeupConfirmation( Lin_GetEcuMWakeupSourceOfChannelConfig( ChannelConfigIdx ) );
    }
  }

#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_CHECKWAKEUP_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif

  LIN_DUMMY_STATEMENT(Channel);

  return(RetTmp);
#else
  return E_OK;
#endif
}

/***********************************************************************************************************************
 *  Lin_Wakeup
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Wakeup( uint8 Channel )
{
  VAR(Lin_ChannelConfigIdxOfChannelIdType, AUTOMATIC) ChannelConfigIdx;
  VAR(Std_ReturnType, AUTOMATIC) RetTmp = E_NOT_OK;
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;
  P2VAR(Lin_RegisterStruct, AUTOMATIC, LIN_VAR_REGS) ChannelBaseAddress;

  /* #10 Check if component is initialized */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  if ( Lin_Dev_InitDetect != LIN_DEV_INITVALUE )
  {
    ErrorId = LIN_E_UNINIT;
  }
  /* #20 Check Channel parameter validity against configuration */
  else if ( Lin_GetSizeOfChannelId() <= Channel )
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# if( LIN_INVALIDHNDOFCHANNELID == STD_ON )
  else if ( Lin_IsInvalidHndOfChannelId( Channel ) )                                                                    /* PRQA S 3325 */ /* MD_MSR_14.1 */ 
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# endif
  else
#endif
  {
    ChannelConfigIdx = Lin_GetChannelConfigIdxOfChannelId( Channel );

    /* #30 Check if channel state on sleep */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
    if( (Lin_GetInternalStateOfChannelData( ChannelConfigIdx ) & 0x0F) != LIN_ONSLEEP_INTERNALSTATEOFCHANNELDATA )
    {
      ErrorId = LIN_E_STATE_TRANSITION;
    }
    else
#endif
    {
      RetTmp = E_OK;

      /* #40 Set channel state to wakeup pending (according DSGN-Lin22334) */
      Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONWAKEUP_PENDING_INTERNALSTATEOFCHANNELDATA );           /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
/* --- Platform specific implementation of Lin_Wakeup() ------------------------------------------------------------- */
      /* #50 Set hardware to operational and transmit a wakeup frame (including configure intern interrupt flags) */
      /* pointer to lin module registers */
      ChannelBaseAddress = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx );

      /* set wakeup byte to transmit */
      ChannelBaseAddress->TXFIFOCON = LIN_TXFIFOCON_CLEAR_STOP;                                                         /* SBSW_LIN_PTR_HW */
      ChannelBaseAddress->TXDATA    = LIN_WAKEUP_PATTERN;                                                               /* SBSW_LIN_PTR_HW */
      ChannelBaseAddress->TXFIFOCON = LIN_TXFIFOCON_ENABLE;                                                             /* SBSW_LIN_PTR_HW */

      /* trigger wakeup frame transmission */
      ChannelBaseAddress->FLAGSSET  = LIN_FLAGS_TWRQ;                                                                   /* SBSW_LIN_PTR_HW */
/* ------------------------------------------------------------------------------------------------------------------ */
    }
  }

#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_WAKEUP_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif

  LIN_DUMMY_STATEMENT(Channel);

  return(RetTmp);
}

/***********************************************************************************************************************
 *  Lin_GoToSleep
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleep( uint8 Channel )
{
  VAR(Lin_ChannelConfigIdxOfChannelIdType, AUTOMATIC) ChannelConfigIdx;
  VAR(Std_ReturnType, AUTOMATIC) RetTmp = E_NOT_OK;
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;
  VAR(Lin_PduType, AUTOMATIC) PduTmp;
  VAR(uint8, AUTOMATIC) DataTmp[8];
  
  /* #10 Check if component is initialized */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  if ( Lin_Dev_InitDetect != LIN_DEV_INITVALUE )
  {
    ErrorId = LIN_E_UNINIT;
  }
  /* #20 Check Channel parameter validity against configuration */
  else if ( Lin_GetSizeOfChannelId() <= Channel )
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# if( LIN_INVALIDHNDOFCHANNELID == STD_ON )
  else if ( Lin_IsInvalidHndOfChannelId( Channel ) )                                                                    /* PRQA S 3325 */ /* MD_MSR_14.1 */ 
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# endif
  else
#endif
  {
    ChannelConfigIdx = Lin_GetChannelConfigIdxOfChannelId( Channel );
    
    /* #30 Set-up and transmit a go-to-sleep frame */     
    PduTmp.Cs        = LIN_CLASSIC_CS;
    PduTmp.Dl        = 8;
    PduTmp.Drc       = LIN_MASTER_RESPONSE;
    PduTmp.Pid       = 0x3Cu;
    PduTmp.SduPtr    = DataTmp;
    PduTmp.SduPtr[0] = 0x00u;                                                                                           /* SBSW_LIN_BUFFER_WRITE */
    PduTmp.SduPtr[1] = 0xFFu;                                                                                           /* SBSW_LIN_BUFFER_WRITE */
    PduTmp.SduPtr[2] = 0xFFu;                                                                                           /* SBSW_LIN_BUFFER_WRITE */
    PduTmp.SduPtr[3] = 0xFFu;                                                                                           /* SBSW_LIN_BUFFER_WRITE */
    PduTmp.SduPtr[4] = 0xFFu;                                                                                           /* SBSW_LIN_BUFFER_WRITE */
    PduTmp.SduPtr[5] = 0xFFu;                                                                                           /* SBSW_LIN_BUFFER_WRITE */
    PduTmp.SduPtr[6] = 0xFFu;                                                                                           /* SBSW_LIN_BUFFER_WRITE */
    PduTmp.SduPtr[7] = 0xFFu;                                                                                           /* SBSW_LIN_BUFFER_WRITE */

    RetTmp = Lin_SendFrame( Channel, &PduTmp );                                                                     /* SBSW_LIN_PTR_CALL */
    
    /* #40 Set channel state to sleep pending (according DSGN-Lin22334) */
    Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONSLEEP_PENDING_INTERNALSTATEOFCHANNELDATA );              /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
  }

#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_GOTOSLEEP_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif

  LIN_DUMMY_STATEMENT(Channel);

  return(RetTmp);
}

/***********************************************************************************************************************
 *  Lin_GoToSleepInternal
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternal( uint8 Channel )
{
  VAR(Lin_ChannelConfigIdxOfChannelIdType, AUTOMATIC) ChannelConfigIdx;
  VAR(Std_ReturnType, AUTOMATIC) RetTmp = E_NOT_OK;
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;

  /* #10 Check if component is initialized */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  if ( Lin_Dev_InitDetect != LIN_DEV_INITVALUE )
  {
    ErrorId = LIN_E_UNINIT;
  }
  /* #20 Check Channel parameter validity against configuration */
  else if ( Lin_GetSizeOfChannelId() <= Channel )
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# if( LIN_INVALIDHNDOFCHANNELID == STD_ON )
  else if ( Lin_IsInvalidHndOfChannelId( Channel ) )                                                                    /* PRQA S 3325 */ /* MD_MSR_14.1 */ 
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# endif
  else
#endif
  {
    RetTmp = E_OK;
    ChannelConfigIdx = Lin_GetChannelConfigIdxOfChannelId( Channel );
    /* #30 Set hardware and software state to sleep */
    Lin_SetSleep( ChannelConfigIdx, LIN_SID_GOTOSLEEPINTERNAL_ID );
  }

#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_GOTOSLEEPINTERNAL_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif

  return(RetTmp);
}

/***********************************************************************************************************************
 *  Lin_WakeupInternal
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternal( uint8 Channel )
{
  VAR(Lin_ChannelConfigIdxOfChannelIdType, AUTOMATIC) ChannelConfigIdx;
  VAR(Std_ReturnType, AUTOMATIC) RetTmp = E_NOT_OK;
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;
  /* #10 Check if component is initialized */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  if ( Lin_Dev_InitDetect != LIN_DEV_INITVALUE )
  {
    ErrorId = LIN_E_UNINIT;
  }
  /* #20 Check Channel parameter validity against configuration */
  else if ( Lin_GetSizeOfChannelId() <= Channel )
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# if( LIN_INVALIDHNDOFCHANNELID == STD_ON )
  else if ( Lin_IsInvalidHndOfChannelId( Channel ) )                                                                    /* PRQA S 3325 */ /* MD_MSR_14.1 */ 
  {                                                                                                                     /* PRQA S 3201 */ /* MD_MSR_14.1 */
    ErrorId = LIN_E_INVALID_CHANNEL;
  }
# endif
  else
#endif
  {
    ChannelConfigIdx = Lin_GetChannelConfigIdxOfChannelId( Channel );
    /* #30 Check if channel state on sleep */
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
    if( (Lin_GetInternalStateOfChannelData( ChannelConfigIdx ) & 0x0F) != LIN_ONSLEEP_INTERNALSTATEOFCHANNELDATA )
    {
      ErrorId = LIN_E_STATE_TRANSITION;
    }
    else
#endif
    {
      RetTmp = E_OK;
      /* #40 Set channel state to operational (according DSGN-Lin22334) */
      Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONWAKE_INTERNALSTATEOFCHANNELDATA );                     /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
      /* #50 Set hardware to operational mode (without transmit a wakeup frame) */
      Lin_SetHardwareWake( ChannelConfigIdx, LIN_SID_WAKEUPINTERNAL_ID );
    }
  }
#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_WAKEUPINTERNAL_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif

  LIN_DUMMY_STATEMENT(Channel);

  return(RetTmp);
}

#if ( LIN_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  Lin_GetVersionInfo
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, LIN_CODE) Lin_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, LIN_APPL_VAR) versioninfo )
{
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;
  
# if ( LIN_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check versioninfo for NULL pointer */
  if ( versioninfo == (P2VAR(Std_VersionInfoType, AUTOMATIC, LIN_APPL_VAR))NULL_PTR )
  {
    ErrorId = LIN_E_PARAM_POINTER; 
  }
  else
# endif
  {
    /* #20 Set versioninfo with corresponding macros from component header */
    versioninfo->vendorID           = LIN_VENDOR_ID;                                                                    /* SBSW_LIN_PTR */
    versioninfo->moduleID           = LIN_MODULE_ID;                                                                    /* SBSW_LIN_PTR */
    versioninfo->sw_major_version   = LIN_SW_MAJOR_VERSION;                                                             /* SBSW_LIN_PTR */
    versioninfo->sw_minor_version   = LIN_SW_MINOR_VERSION;                                                             /* SBSW_LIN_PTR */
    versioninfo->sw_patch_version   = LIN_SW_PATCH_VERSION;                                                             /* SBSW_LIN_PTR */
  }
  
#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_GETVERSIONINFO_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif
}
#endif /* LIN_VERSION_INFO_API == STD_ON */

/***********************************************************************************************************************
 *  Lin_InitMemory
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, LIN_CODE) Lin_InitMemory( void )
{
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  /* #10 Set state to uninitialized (according DSGN-Lin22334) */
  Lin_Dev_InitDetect = LIN_DEV_UNINITVALUE;
#endif
}

/***********************************************************************************************************************
 *  Lin_Init
 **********************************************************************************************************************/
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
FUNC(void, LIN_CODE) Lin_Init( P2CONST(Lin_ConfigType, AUTOMATIC, LIN_PBCFG) Config )
{
  VAR(Lin_ChannelConfigIdxOfChannelIdType, AUTOMATIC) ChannelConfigIdx;
  VAR(uint8, AUTOMATIC) ErrorId = LIN_E_NO_ERROR;
  P2VAR(Lin_RegisterStruct, AUTOMATIC, LIN_VAR_REGS) ChannelBaseAddress;

 /* Runtime Measurement start */
  Lin_Rtm_Start(Lin_Init)

#if ( LIN_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is uninitialized */
  if ( Lin_Dev_InitDetect == LIN_DEV_INITVALUE )
  {
    ErrorId = LIN_E_STATE_TRANSITION;
  }
  else
#endif
  {

#if (LIN_USE_INIT_POINTER == STD_ON)
    /* #20 Check Config parameter for NULL pointer */
    if ( Config == NULL_PTR )
    {
# if ( LIN_DEV_ERROR_DETECT == STD_ON )
      ErrorId = LIN_E_INVALID_POINTER;
# endif

# if( LIN_USE_ECUM_BSW_ERROR_HOOK == STD_ON )
      EcuM_BswErrorHook((uint16) LIN_MODULE_ID, ECUM_BSWERROR_NULLPTR);
# endif
    }
    else
#endif
    {

#if (LIN_USE_INIT_POINTER == STD_ON)      
      Lin_ConfigDataPtr = Config;
#else
      LIN_DUMMY_STATEMENT( Config );
#endif

#if( LIN_USE_ECUM_BSW_ERROR_HOOK == STD_ON )
      /* #30 Check Generator compatibility version */
      if (Lin_GetHLGeneratorCompatibilityVersion() != (uint16) LIN_HL_GENERATORMSR_COMPATIBILITY_VERSION)
      {
        EcuM_BswErrorHook((uint16) LIN_MODULE_ID, ECUM_BSWERROR_COMPATIBILITYVERSION);
      }
      else if (Lin_GetLLGeneratorCompatibilityVersion() != (uint16) LIN_LL_GENERATORMSR_COMPATIBILITY_VERSION)
      {
        EcuM_BswErrorHook((uint16) LIN_MODULE_ID, ECUM_BSWERROR_COMPATIBILITYVERSION);
      }
      /* #40 Check version and magic number */
      else if (Lin_GetFinalMagicNumber() != LIN_FINAL_MAGIC_NUMBER)
      {
        EcuM_BswErrorHook((uint16) LIN_MODULE_ID, ECUM_BSWERROR_MAGICNUMBER);
      }
      else
#endif
      {
#if ( LIN_DEV_ERROR_DETECT == STD_ON )
        /* #50 Set state to initialized (according DSGN-Lin22334) */
        Lin_Dev_InitDetect = LIN_DEV_INITVALUE;
#endif
        
/* --- Platform specific implementation of Lin_Init() --------------------------------------------------------------- */
        /* #60 Set channel independent hardware configuration (if applicable) */
/* ------------------------------------------------------------------------------------------------------------------ */
        
        /* #70 Loop over all configured hardware channels */
        for (ChannelConfigIdx = 0x00u; ChannelConfigIdx < Lin_GetSizeOfChannelConfig(); ChannelConfigIdx++)
        {
          /* #80 Set channel state to operational (according DSGN-Lin22334) */
          Lin_SetInternalStateOfChannelData(  ChannelConfigIdx, LIN_ONWAKE_INTERNALSTATEOFCHANNELDATA );                /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
/* --- Platform specific implementation of Lin_Init() - Channel loop - ---------------------------------------------- */
          /* #90 Set channel dependent hardware configuration (baud rate, break field length, ...) */
          /* pointer to lin module registers */
          ChannelBaseAddress = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx );

          /* Set ASCLIN_CLC register */
          Appl_UnlockEndinit();

          osWritePeripheral32( LIN_PROTECTED_AREA_ENDINIT, (uint32)(&(ChannelBaseAddress->CLC)), 0x0008u );             /* SBSW_LIN_PTR_HW */
 
          Appl_LockEndinit();

          /* deactivate clock source during configuration */
          ChannelBaseAddress->CSR &= (uint32)~(LIN_CSR_CLKSEL_MASK);                                                    /* SBSW_LIN_PTR_HW */

          /* select LIN operation mode, configure frame parameters */
          ChannelBaseAddress->FRAMECON = LIN_FRAMECON_DEFAULT;                                                          /* SBSW_LIN_PTR_HW */

          /* select master mode, enable hardware checksum logic */
          ChannelBaseAddress->LINCON = LIN_LINCON_DEFAULT;                                                              /* SBSW_LIN_PTR_HW */

          /* configure baudrate */
          ChannelBaseAddress->BRG = Lin_GetBRGOfChannelConfig( ChannelConfigIdx );                                      /* SBSW_LIN_PTR_HW */

          /* configure bit timing and sampling */
          ChannelBaseAddress->BITCON = LIN_BITCON_DEFAULT | Lin_GetBITCON_PRESCALEROfChannelConfig( ChannelConfigIdx ); /* SBSW_LIN_PTR_HW */
                                                
          /* configure break length */
          ChannelBaseAddress->LINBTIMER = LIN_LINBTIMER_DEFAULT;                                                        /* SBSW_LIN_PTR_HW */

          /* set header timeout, sufficient to set it once. Setting requires CSR_CLKSEL = 0 */
          ChannelBaseAddress->LINHTIMER = LIN_LINHTIMER_DEFAULT;                                                        /* SBSW_LIN_PTR_HW */

          /* set used interrupt flag sources */
          ChannelBaseAddress->FLAGSENABLE = LIN_FLAGSENABLE_OPERATIONAL;                                                /* SBSW_LIN_PTR_HW */

         /* set pin configuration */
          ChannelBaseAddress->IOCR = Lin_GetIOCR_ALTIOfChannelConfig( ChannelConfigIdx );                               /* SBSW_LIN_PTR_HW */

          /* activate clock source */
          ChannelBaseAddress->CSR = (Lin_GetCSR_CLKSELOfChannelConfig( ChannelConfigIdx ) & LIN_CSR_CLKSEL_MASK);       /* SBSW_LIN_PTR_HW */
/* ------------------------------------------------------------------------------------------------------------------ */
        }
      }
    }
  }

#if ( LIN_DEV_ERROR_REPORT == STD_ON )
  if( ErrorId != LIN_E_NO_ERROR )
  {
    Lin_Det_ReportError( LIN_SID_INIT_ID, ErrorId );
  }
#else
  LIN_DUMMY_STATEMENT(ErrorId);
#endif

  /* Runtime Measurement stop */
  Lin_Rtm_Stop(Lin_Init)
}                                                                                                                       /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  Lin_CheckIrqWakeupEvent
 **********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_CheckIrqWakeupEvent( Lin_ChannelConfigIdxOfChannelHwType ChannelConfigIdx )
{
  /* #10 If channel has a EcuM Wakeup Source ID */
#if( LIN_LEAST_ONE_CHANNEL_WAKEUP_SUPPORT_ENABLED == STD_ON )
# if( LIN_LEAST_ONE_CHANNEL_WAKEUP_SUPPORT_DISABLED == STD_ON )                                                         /* COV_LIN_DERIVATIVE */
  if ( Lin_GetEcuMWakeupSourceOfChannelConfig( ChannelConfigIdx ) != 0 )   
# endif
  {
    /* #20 Set channel state to external wakeup pending (according DSGN-Lin22334) */
    Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONWAKEUP_EXTERNAL_INTERNALSTATEOFCHANNELDATA );            /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
    /* #30 Call EcuM_CheckWakeup() to inform EcuM about wakeup event */
    EcuM_CheckWakeup( Lin_GetEcuMWakeupSourceOfChannelConfig( ChannelConfigIdx ) );
  }
#endif
}

/***********************************************************************************************************************
 *  Lin_SetSleep
 **********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetSleep ( Lin_ChannelConfigIdxOfChannelHwType ChannelConfigIdx,
                                                     uint8 ApiId /* needed only for some hardware */ )
{
/* --- Platform specific implementation of Lin_SetSleep() ----------------------------------------------------------- */
  /* #10 Set hardware to sleep and enable hardware detection of wakeup pulse (over interrupt) */
  /* enable edge interrupt to detect a wakeup frame */
  (Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ))->FLAGSCLEAR  = LIN_FLAGSCLEAR_DEFAULT;                 /* SBSW_LIN_PTR_HW */
  (Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ))->FLAGSENABLE = LIN_FLAGSENABLE_SLEEP;                  /* SBSW_LIN_PTR_HW */
  LIN_DUMMY_STATEMENT( ApiId );
/* ------------------------------------------------------------------------------------------------------------------ */

  /* #20 Set channel state to sleep (according DSGN-Lin22334) */
  Lin_SetInternalStateOfChannelData( ChannelConfigIdx, LIN_ONSLEEP_INTERNALSTATEOFCHANNELDATA );                        /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
}

/***********************************************************************************************************************
 *  Lin_SetHardwareWake
 **********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_SetHardwareWake( Lin_ChannelConfigIdxOfChannelHwType ChannelConfigIdx,
                                                           uint8 ApiId /* needed only for some hardware */ )
{
/* --- Platform specific implementation of Lin_SetHardwareWake() ---------------------------------------------------- */
  /* #10 Set hardware to operational (disable detection of wakeup pulse) */
  /* enable interrupt sources for normal communication */
  (Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ))->FLAGSENABLE = LIN_FLAGSENABLE_OPERATIONAL;            /* SBSW_LIN_PTR_HW */
  LIN_DUMMY_STATEMENT( ApiId );
/* ------------------------------------------------------------------------------------------------------------------ */
}

/* --- Platform specific implementation of internal functions ------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------ */

#define LIN_STOP_SEC_CODE
#include "MemMap.h"                                                                                                     /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* module specific MISRA deviations:

   MD_LIN_HL_16.7:
     Reason: API specification given by AUTOSAR and must be kept.
     Risk: N/A
     Prevention: N/A
     
   MD_LIN_0303:
     Reason: The size of integer required to hold the result of a pointer cast is implementation-defined. This type
             of operation is not uncommon in embedded software applications where memory mapped I/O ports must be
             addressed.
     Risk: Cast a pointer to an integer type or vice versa may be non-portable.
     Prevention: The code inspection and tests on hardware ensure that the memory location referenced contains the
                 registers with the same structure as specified.

   MD_LIN_3447:
     Reason:     Function has external linkage but this declaration is not in a header file.
     Risk:       No functional risk.
     Prevention: Not required.
                 
*/

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_LIN_PTR_HW 
  \DESCRIPTION The function accesses a hardware register using a pointer access.
  \COUNTERMEASURE \T The code inspection and tests on hardware ensure that the memory location
                     referenced contains the registers with the same structure as specified.
                  \S Verify that the values generated match the address of register of the used hardware.

  \ID SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID
  \DESCRIPTION Access to InternalState via indirection over ChannelId.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib.

  \ID SBSW_LIN_BUFFER_WRITE
  \DESCRIPTION Write to the array of constant size.
  \COUNTERMEASURE \R The index based access to the array uses constant index values. The buffer is statically allocated
                     with fixed size (e.g. 8 bytes). The size is sufficient for the largest used index value (e.g. 7).

  \ID SBSW_LIN_PTR
  \DESCRIPTION The function writes to the object referenced by parameter.
  \COUNTERMEASURE \N The caller ensures that the pointers passed to the parameter is valid.

  \ID SBSW_LIN_PTR_CALL
  \DESCRIPTION The function call uses a pointer parameter.
  \COUNTERMEASURE \N A local variable is used and Lin_SendFrame copy the data to internal buffer.

SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION

  \ID COV_LIN_COMPILER
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XX
  \REASON The source code covers different compilers. There is however only a subset of the compilers released for
          safeBSW, therefore the code of the unsupported compilers is not covered.

  \ID COV_LIN_DERIVATIVE
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XX
  \REASON The source code covers different derivatives. There is however only a subset of the derivatives released for
          safeBSW, therefore the code of the unsupported derivatives features or existing/not existing erratas is not
          covered.

  \ID COV_LIN_INTEGRATION
  \ACCEPT XF
  \REASON The include of the transceiver types header is not tested in the LIN driver test suite because it is a stub
          test without transceiver driver. 

  \ID COV_LIN_COMPATIBILITY
  \ACCEPT TX
  \ACCEPT XF
  \REASON [COV_MSR_COMPATIBILITY]

END_COVERAGE_JUSTIFICATION */ 

/**********************************************************************************************************************
 *  END OF FILE: Lin.c
 *********************************************************************************************************************/

