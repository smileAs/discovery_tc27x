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
 *            Module: Can
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Cfg.h
 *   Generation Time: 2018-08-04 13:37:35
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

/* -----------------------------------------------------------------------------
    Generator Info
 ----------------------------------------------------------------------------- 
  Name:     MICROSAR Can TRICORE MultiCAN driver Generator
  Version:  4.03.02
  MSN:      Can
  Origin:   CAN
  Descrip:  MICROSAR Can driver generator
  JavaPack: com.vector.cfg.gen.DrvCan_TricoreMulticanAsr
 ----------------------------------------------------------------------------- */

#if !defined(CAN_CFG_H)
#define CAN_CFG_H

/* CAN222, CAN389, CAN365, CAN366, CAN367 */
/* CAN022, CAN047, CAN388, CAN397, CAN390, CAN392  */

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "ComStack_Types.h"

#include "Can_GeneralTypes.h" /* CAN435 */

#if defined (CAN_LCFG_SOURCE) || defined (C_DRV_INTERNAL) /* ESCAN00070085 */
# include "Os.h"
#endif

/* -----------------------------------------------------------------------------
    General Switches for CAN module
 ----------------------------------------------------------------------------- */

#ifndef CAN_USE_DUMMY_FUNCTIONS
#define CAN_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef CAN_USE_DUMMY_STATEMENT
#define CAN_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef CAN_DUMMY_STATEMENT
#define CAN_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CAN_DUMMY_STATEMENT_CONST
#define CAN_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CAN_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CAN_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CAN_ATOMIC_VARIABLE_ACCESS
#define CAN_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CAN_PROCESSOR_TC277
#define CAN_PROCESSOR_TC277
#endif
#ifndef CAN_COMP_GNU
#define CAN_COMP_GNU
#endif
#ifndef CAN_GEN_GENERATOR_MSR
#define CAN_GEN_GENERATOR_MSR
#endif
#ifndef CAN_CPUTYPE_BITORDER_LSB2MSB
#define CAN_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef CAN_CONFIGURATION_VARIANT_PRECOMPILE
#define CAN_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CAN_CONFIGURATION_VARIANT_LINKTIME
#define CAN_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CAN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CAN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CAN_CONFIGURATION_VARIANT
#define CAN_CONFIGURATION_VARIANT CAN_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CAN_POSTBUILD_VARIANT_SUPPORT
#define CAN_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* -----------------------------------------------------------------------------
    General Switches from old v_cfg.h
 ----------------------------------------------------------------------------- */
#if !defined(V_GEN_GENERATOR5)
# define V_GEN_GENERATOR5 /* need by LL */
#endif
#if !defined(V_ENABLE_CAN_ASR_ABSTRACTION)
# define V_ENABLE_CAN_ASR_ABSTRACTION /* ATK */
#endif
#define CAN_GEN_COM_STACK_LIB

#if !defined( V_OSTYPE_AUTOSAR )
# define V_OSTYPE_AUTOSAR
#endif

#if (CPU_TYPE == CPU_TYPE_32)
# if !defined( C_CPUTYPE_32BIT )
#  define C_CPUTYPE_32BIT
# endif
#endif
#if (CPU_TYPE == CPU_TYPE_16)
# if !defined( C_CPUTYPE_16BIT )
#  define C_CPUTYPE_16BIT
# endif
#endif
#if (CPU_TYPE == CPU_TYPE_8)
# if !defined( C_CPUTYPE_8BIT )
#  define C_CPUTYPE_8BIT
# endif
#endif
#if (CPU_BIT_ORDER == LSB_FIRST)
# if !defined( C_CPUTYPE_BITORDER_LSB2MSB )
#  define C_CPUTYPE_BITORDER_LSB2MSB
# endif
#endif
#if (CPU_BIT_ORDER == MSB_FIRST)
# if !defined( C_CPUTYPE_BITORDER_MSB2LSB )
#  define C_CPUTYPE_BITORDER_MSB2LSB
# endif
#endif
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
# if !defined( C_CPUTYPE_LITTLEENDIAN )
#  define C_CPUTYPE_LITTLEENDIAN
# endif
#endif
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
# if !defined( C_CPUTYPE_BIGENDIAN )
#  define C_CPUTYPE_BIGENDIAN
# endif
#endif

#if !defined( V_DISABLE_USE_DUMMY_FUNCTIONS )
# define V_DISABLE_USE_DUMMY_FUNCTIONS
#endif
#if !defined( V_ENABLE_USE_DUMMY_STATEMENT )
# define V_ENABLE_USE_DUMMY_STATEMENT
#endif

#if !defined( V_CPU_TRICORE )
# define V_CPU_TRICORE
#endif

#if !defined( C_PROCESSOR_INFINEON_TC277 )
# define C_PROCESSOR_INFINEON_TC277
#endif
#if !defined( V_PROCESSOR_INFINEON_TC277 )
# define V_PROCESSOR_INFINEON_TC277
#endif

#if !defined( C_COMP_GNU_TRICORE_MULTICAN )
#define C_COMP_GNU_TRICORE_MULTICAN
#endif
#if !defined( V_COMP_GNU )
# define V_COMP_GNU
#endif
#if !defined( V_COMP_GNU_TRICORE )
# define V_COMP_GNU_TRICORE
#endif

#if !defined( V_SUPPRESS_EXTENDED_VERSION_CHECK )
# define V_SUPPRESS_EXTENDED_VERSION_CHECK
#endif

/* -----------------------------------------------------------------------------
    Version defines
 ----------------------------------------------------------------------------- */

/* CAN024, CAN023 */
#define CAN_ASR_VERSION              0x0400U
#define CAN_GEN_BASE_CFG5_VERSION    0x0103U
#define CAN_GEN_BASESASR_VERSION     0x0407U
#define CAN_GEN_TricoreMulticanAsr_VERSION              0x0101U
#define CAN_MICROSAR_VERSION         CAN_MSR403

/* -----------------------------------------------------------------------------
    Hardcoded defines
 ----------------------------------------------------------------------------- */

#define CAN_INSTANCE_ID           0

#if !defined(CAN_RX_BASICCAN_TYPE)
# define CAN_RX_BASICCAN_TYPE                 0U
# define CAN_RX_FULLCAN_TYPE                  1U
# define CAN_TX_BASICCAN_TYPE                 2U
# define CAN_TX_FULLCAN_TYPE                  3U
# define CAN_UNUSED_CAN_TYPE                  4U
#endif

#define CAN_INTERRUPT                        0U
#define CAN_POLLING                          1U

#define kCanChannelNotUsed                     CAN_NO_CANIFCHANNELID 

#define CAN_NONE                             0U
/* RAM check (also  none) */
#define CAN_NOTIFY_ISSUE                     1U
#define CAN_NOTIFY_MAILBOX                   2U
#define CAN_EXTENDED                         3U
/* Interrupt lock (also  none) */
#define CAN_DRIVER                           1U
#define CAN_APPL                             2U
#define CAN_BOTH                             3U
/* MicroSar Version */
#define CAN_MSR30                            30U
#define CAN_MSR40                            40U
#define CAN_MSR403                           403U
/* Overrun Notification (als none,appl) */
#define CAN_DET                              1U
/* CAN FD Support */
#define CAN_BRS                              1U
#define CAN_FULL                             2U
/* CAN FD Configuration */
#define CAN_FD_RXONLY                        2U /* FD Baudrate exist (RX) */
#define CAN_FD_RXTX                          1U /* FD Baudrate also used for TX */
/* Generic Confirmation */
#define CAN_API1                             1U
#define CAN_API2                             2U

#define CAN_OS_TICK2MS(tick)     OS_TICKS2MS_SystemTimer_Core0((tick))     /* PRQA S 3453 */ /* MD_Can_3453 */
#define CAN_OS_COUNTER_ID        SystemTimer_Core0

/* -----------------------------------------------------------------------------
    Defines / Switches
 ----------------------------------------------------------------------------- */

/* Version and Issue detection */
#define CAN_VERSION_INFO_API                 STD_OFF   /* CAN106_Conf */
#define CAN_DEV_ERROR_DETECT                 STD_OFF   /* CAN064_Conf */
#define CAN_DEV_ERROR_REPORT                 STD_OFF
#define CAN_PROD_ERROR_DETECT                STD_OFF
#define CAN_DEV_TIMEOUT_DETECT               STD_OFF
#define CAN_SAFE_BSW                         STD_OFF

/* Interrupt / Polling */
#define CAN_TX_PROCESSING                    CAN_INTERRUPT   /* CAN318_Conf */
#define CAN_RX_PROCESSING                    CAN_INTERRUPT   /* CAN317_Conf */
#define CAN_BUSOFF_PROCESSING                CAN_INTERRUPT   /* CAN314_Conf */
#define CAN_WAKEUP_PROCESSING                CAN_INTERRUPT   /* CAN319_Conf */
#define CAN_INDIVIDUAL_PROCESSING            STD_OFF
#define CAN_INTERRUPT_USED                   STD_ON
#define CAN_NESTED_INTERRUPTS                STD_OFF
#define C_ENABLE_OSEK_OS_INTCAT2
#define C_DISABLE_ISRVOID
#define CAN_INTLOCK                          CAN_DRIVER

/* Tx Handling */
#define CAN_MULTIPLEXED_TX_MAX               1U
#define CAN_CANCEL_SUPPORT_API               STD_OFF
#define CAN_TRANSMIT_BUFFER                  STD_ON
#define CAN_MULTIPLEXED_TRANSMISSION         STD_OFF   /* CAN095_Conf */
#define CAN_HW_TRANSMIT_CANCELLATION         STD_OFF   /* CAN069_Conf */
#define CAN_IDENTICAL_ID_CANCELLATION        STD_OFF   /* CAN378_Conf */
#define CAN_MULTIPLE_BASICCAN_TX             STD_OFF

/* Rx Handling */
#define CAN_MULTIPLE_BASICCAN                STD_OFF
#define CAN_RX_QUEUE                         STD_OFF
#define CAN_OVERRUN_NOTIFICATION             CAN_NONE

/* Sleep Wakeup */
#define CAN_SLEEP_SUPPORT                    STD_OFF
#define CAN_WAKEUP_SUPPORT                   STD_OFF   /* CAN330_Conf */

/* Hardware loop check */
#define CAN_HARDWARE_CANCELLATION            STD_ON
#define CAN_TIMEOUT_DURATION                 10UL   /* CAN113_Conf */
#define CAN_LOOP_MAX                         3U

/* Appl calls */
#define CAN_EXTENDED_STATE_MACHINE           STD_OFF
#define CAN_BUSOFF_SUPPORT_API               STD_OFF
#define CAN_HW_LOOP_SUPPORT_API              STD_OFF
#define CAN_GENERIC_PRECOPY                  STD_OFF
#define CAN_GENERIC_CONFIRMATION             STD_OFF
#define CAN_GENERIC_PRETRANSMIT              STD_OFF
#define CAN_USE_OS_INTERRUPT_CONTROL         STD_ON

/* Optimization */
#define CAN_RX_FULLCAN_OBJECTS               STD_OFF
#define CAN_TX_FULLCAN_OBJECTS               STD_OFF
#define CAN_RX_BASICCAN_OBJECTS              STD_ON
#define CAN_EXTENDED_ID                      STD_OFF
#define CAN_MIXED_ID                         STD_OFF
#define CAN_ONE_CONTROLLER_OPTIMIZATION      STD_OFF
#define CAN_DYNAMIC_FULLCAN_ID               STD_ON
#define CAN_SECURE_TEMP_BUFFER               STD_OFF
#define C_ENABLE_GEN_HW_START_STOP_IDX
#define CAN_CHANGE_BAUDRATE_API              STD_OFF   /* CAN460_Conf */

/* CAN FD */
#define CAN_SET_BAUDRATE_API                 STD_OFF   /* CAN482_Conf */
#define CAN_FD_SUPPORT                       CAN_NONE

/* Other */
#define CAN_MULTI_ECU_CONFIG                 STD_OFF
#define CAN_COMMON_CAN                       STD_OFF
#define CAN_PARTIAL_NETWORK                  STD_OFF
#define CAN_RAM_CHECK                        CAN_NONE
#define CAN_REINIT_START                     STD_OFF
#define CAN_GET_STATUS                       STD_OFF
#define CAN_RUNTIME_MEASUREMENT_SUPPORT      STD_OFF
#define CAN_PROTECTED_MODE                   STD_OFF
#define CAN_MIRROR_MODE                      STD_OFF
/* -----------------------------------------------------------------------------
    Channel And Maibox
 ----------------------------------------------------------------------------- */
#ifndef C_DRV_INTERNAL
# ifndef kCanNumberOfChannels
#  define kCanNumberOfChannels               3U
# endif
# ifndef kCanNumberOfHwChannels
#  define kCanNumberOfHwChannels             3U
# endif
#endif
#ifndef kCanNumberOfUsedChannels /* ATK only */
# define kCanNumberOfUsedChannels            3U
#endif

#define kCanPhysToLogChannelIndex_0 0u
#define kCanPhysToLogChannelIndex_1 1u
#define kCanPhysToLogChannelIndex_2 2u

#define kCanNumberOfPhysChannels             3U

/* -----------------------------------------------------------------------------
    Symbolic Name Values for Controller, HardwareObject and Baudrates
 ----------------------------------------------------------------------------- */
/* These definitions can change at Link-time and Post-build configuration time. Use them wisely. */



/**
 * \defgroup CanHandleIdsactivated Handle IDs of handle space activated.
 * \brief controllers by CanControllerActivation
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CanConf_CanController_CT_CAN00_388e5969                       0
#define CanConf_CanController_CT_CAN01_388e5969                       1
#define CanConf_CanController_CT_CAN02_388e5969                       2
/**\} */
#define CanConf_CN_CAN00_388e5969_Rx_Std 1U
#define CanConf_CN_CAN00_388e5969_Tx_Std 0U
#define CanConf_CN_CAN01_388e5969_Rx_Std 3U
#define CanConf_CN_CAN01_388e5969_Tx_Std 2U
#define CanConf_CN_CAN02_388e5969_Rx_Std 5U
#define CanConf_CN_CAN02_388e5969_Tx_Std 4U

#define CanConf_ControllerBaudrateConfig_CT_CAN00_388e5969_CanControllerBaudrateConfig 0u
#define CanConf_ControllerBaudrateConfig_CT_CAN01_388e5969_CanControllerBaudrateConfig 0u
#define CanConf_ControllerBaudrateConfig_CT_CAN02_388e5969_CanControllerBaudrateConfig 0u



/* -----------------------------------------------------------------------------
    Types
 ----------------------------------------------------------------------------- */
/* HW specific BEGIN */

/* -----------------------------------------------------------------------------
    &&&~ Defines / Switches (Hw specific ) 
 ----------------------------------------------------------------------------- */
#define CAN_RX_HW_FIFO_FULL_NOTIFICATION     STD_OFF
#define C_DISABLE_MULTIPLE_DRIVERS
#define C_DISABLE_MULTIPLE_CELLS
#define C_ENABLE_CONFIGURE_SRC_ADDRESS

#define kCanBaseAdr                          0xF0018000UL
#define kCanSRCAdr                           0xF0038900UL
#define kCanMCRValue                         1U
#define CanClockDividor                      0x000043FFUL
#define CAN_MAX_HW_NODE_AMOUNT               8U
#define CAN_MAX_MAILBOX_AMOUNT               256U

#define kCanISRPrio_0                        10U
#define kCanUsedCore_0                       0U
#define kCanISRPrio_1                        10U
#define kCanUsedCore_1                       0U
#define kCanISRPrio_2                        10U
#define kCanUsedCore_2                       0U
#define kCanISRPrio_3                        0U
#define kCanUsedCore_3                       0U
#define kCanISRPrio_4                        0U
#define kCanUsedCore_4                       0U
#define kCanISRPrio_5                        0U
#define kCanUsedCore_5                       0U
#define kCanISRPrio_6                        0U
#define kCanUsedCore_6                       0U
#define kCanISRPrio_7                        0U
#define kCanUsedCore_7                       0U

#define CAN_FD_NISO                          STD_OFF
#define CAN_FD_PED                           STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Types (Hw specific ) 
 ----------------------------------------------------------------------------- */
typedef VAR(uint32, CAN_VAR_NOINIT) tCanLLCanIntOld;  /* PRQA S 0850 */ /* MD_MSR_19.8 */

typedef struct tCanTmpMsgObjStructTag
{
  uint8 MoFCR_Mode;
  uint8 MoFCR_Gate;
  uint8 MoFCR_IE;
  uint8 MoFCR_DLC;
  uint16 MoARLo;
  uint16 MoARHi;
  uint32 MoDR[2];
} tCanTmpMsgObjStruct;
 
/* HW specific END */ 

typedef VAR(uint8, TYPEDEF) CanChannelHandle;

#if defined (CAN_LCFG_SOURCE) || defined (C_DRV_INTERNAL)
typedef TickType Can_ExternalTickType;
#else
typedef uint32 Can_ExternalTickType;
#endif

typedef VAR(Can_ExternalTickType, TYPEDEF) Can_LoopTimeout_dim_type[CAN_LOOP_MAX+1];         /* (ASR3: without +1) PRQA S 0850 */ /* MD_MSR_19.8 */




/* -----------------------------------------------------------------------------
    CONST Declarations
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    VAR Declarations
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */
/* HW specific BEGIN */

/* HW specific END */


/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/* Can_GlobalConfig: CAN354_Conf */
/* Can_ConfigType: CAN413 */

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanPCDataSwitches  Can Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CAN_ACTIVESENDPDU                                             STD_ON
#define CAN_ACTIVESENDSTATE                                           STD_ON
#define CAN_BASEDLL_GENERATORVERSION                                  STD_ON
#define CAN_BUSOFFNOTIFIED                                            STD_ON
#define CAN_CANIFCHANNELID                                            STD_ON
#define CAN_CANINTERRUPTCOUNTER                                       STD_ON
#define CAN_CANINTERRUPTOLDSTATUS                                     STD_ON
#define CAN_CONTROLLERCONFIG                                          STD_ON
#define CAN_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG         STD_OFF  /**< Deactivateable: 'Can_ControllerConfig.CanControllerDefaultBaudrateIdx' Reason: '/ActiveEcuC/Can/CanGeneral[0:CanSetBaudrateApi] is configured to 'false'' */
#define CAN_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG            STD_ON
#define CAN_RXBASICHANDLEMAXOFCONTROLLERCONFIG                        STD_ON
#define CAN_RXBASICHANDLESTARTOFCONTROLLERCONFIG                      STD_ON
#define CAN_RXBASICHANDLESTOPOFCONTROLLERCONFIG                       STD_ON
#define CAN_RXBASICHWSTARTOFCONTROLLERCONFIG                          STD_ON
#define CAN_RXBASICHWSTOPOFCONTROLLERCONFIG                           STD_ON
#define CAN_RXFULLHANDLEMAXOFCONTROLLERCONFIG                         STD_ON
#define CAN_RXFULLHANDLESTARTOFCONTROLLERCONFIG                       STD_ON
#define CAN_RXFULLHANDLESTOPOFCONTROLLERCONFIG                        STD_ON
#define CAN_RXFULLHWSTARTOFCONTROLLERCONFIG                           STD_ON
#define CAN_RXFULLHWSTOPOFCONTROLLERCONFIG                            STD_ON
#define CAN_TXBASICHANDLEMAXOFCONTROLLERCONFIG                        STD_ON
#define CAN_TXBASICHANDLESTARTOFCONTROLLERCONFIG                      STD_ON
#define CAN_TXBASICHANDLESTOPOFCONTROLLERCONFIG                       STD_ON
#define CAN_TXBASICHWSTARTOFCONTROLLERCONFIG                          STD_ON
#define CAN_TXBASICHWSTOPOFCONTROLLERCONFIG                           STD_ON
#define CAN_TXFULLHANDLEMAXOFCONTROLLERCONFIG                         STD_ON
#define CAN_TXFULLHANDLESTARTOFCONTROLLERCONFIG                       STD_ON
#define CAN_TXFULLHANDLESTOPOFCONTROLLERCONFIG                        STD_ON
#define CAN_TXFULLHWSTARTOFCONTROLLERCONFIG                           STD_ON
#define CAN_TXFULLHWSTOPOFCONTROLLERCONFIG                            STD_ON
#define CAN_UNUSEDHANDLEMAXOFCONTROLLERCONFIG                         STD_ON
#define CAN_UNUSEDHANDLESTARTOFCONTROLLERCONFIG                       STD_ON
#define CAN_UNUSEDHANDLESTOPOFCONTROLLERCONFIG                        STD_ON
#define CAN_UNUSEDHWSTARTOFCONTROLLERCONFIG                           STD_ON
#define CAN_UNUSEDHWSTOPOFCONTROLLERCONFIG                            STD_ON
#define CAN_FINALMAGICNUMBER                                          STD_OFF  /**< Deactivateable: 'Can_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_GLOBALINTERRUPTPENDINGMASK                                STD_ON
#define CAN_HALT                                                      STD_ON
#define CAN_INITBT                                                    STD_ON
#define CAN_INITCODEH                                                 STD_ON
#define CAN_INITCODEL                                                 STD_ON
#define CAN_INITDATAHASHCODE                                          STD_OFF  /**< Deactivateable: 'Can_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_INITMASKH                                                 STD_ON
#define CAN_INITMASKL                                                 STD_ON
#define CAN_INITOBJECTBAUDRATE                                        STD_ON
#define CAN_INITOBJECTSTARTINDEX                                      STD_ON
#define CAN_INITPORTSEL                                               STD_ON
#define CAN_ISBUSOFF                                                  STD_ON
#define CAN_ISHARDWARECANCELED                                        STD_ON
#define CAN_ISROSID                                                   STD_ON
#define CAN_LASTINITOBJECT                                            STD_ON
#define CAN_LOGSTATUS                                                 STD_ON
#define CAN_LOOPTIMEOUT                                               STD_ON
#define CAN_MAILBOX                                                   STD_ON
#define CAN_DLC_FIFOOFMAILBOX                                         STD_ON
#define CAN_HWHANDLEOFMAILBOX                                         STD_ON
#define CAN_IDVALUEOFMAILBOX                                          STD_ON
#define CAN_MAILBOXTYPEOFMAILBOX                                      STD_ON
#define CAN_MAXDATALENOFMAILBOX                                       STD_ON
#define CAN_MSGCONTROLLEROFMAILBOX                                    STD_ON
#define CAN_NODEADR                                                   STD_ON
#define CAN_NODENUM                                                   STD_ON
#define CAN_PHYSPRIO                                                  STD_ON
#define CAN_PLATFORMDLL_GENERATORVERSION                              STD_ON
#define CAN_RXBASICINTERRUPTPENDINGMASK                               STD_ON
#define CAN_RXFULLINTERRUPTPENDINGMASK                                STD_ON
#define CAN_SIZEOFACTIVESENDPDU                                       STD_ON
#define CAN_SIZEOFACTIVESENDSTATE                                     STD_ON
#define CAN_SIZEOFBUSOFFNOTIFIED                                      STD_ON
#define CAN_SIZEOFCANIFCHANNELID                                      STD_ON
#define CAN_SIZEOFCANINTERRUPTCOUNTER                                 STD_ON
#define CAN_SIZEOFCANINTERRUPTOLDSTATUS                               STD_ON
#define CAN_SIZEOFCONTROLLERCONFIG                                    STD_ON
#define CAN_SIZEOFGLOBALINTERRUPTPENDINGMASK                          STD_ON
#define CAN_SIZEOFHALT                                                STD_ON
#define CAN_SIZEOFINITBT                                              STD_ON
#define CAN_SIZEOFINITCODEH                                           STD_ON
#define CAN_SIZEOFINITCODEL                                           STD_ON
#define CAN_SIZEOFINITMASKH                                           STD_ON
#define CAN_SIZEOFINITMASKL                                           STD_ON
#define CAN_SIZEOFINITOBJECTBAUDRATE                                  STD_ON
#define CAN_SIZEOFINITOBJECTSTARTINDEX                                STD_ON
#define CAN_SIZEOFINITPORTSEL                                         STD_ON
#define CAN_SIZEOFISBUSOFF                                            STD_ON
#define CAN_SIZEOFISHARDWARECANCELED                                  STD_ON
#define CAN_SIZEOFISROSID                                             STD_ON
#define CAN_SIZEOFLASTINITOBJECT                                      STD_ON
#define CAN_SIZEOFLOGSTATUS                                           STD_ON
#define CAN_SIZEOFLOOPTIMEOUT                                         STD_ON
#define CAN_SIZEOFMAILBOX                                             STD_ON
#define CAN_SIZEOFNODEADR                                             STD_ON
#define CAN_SIZEOFNODENUM                                             STD_ON
#define CAN_SIZEOFPHYSPRIO                                            STD_ON
#define CAN_SIZEOFRXBASICINTERRUPTPENDINGMASK                         STD_ON
#define CAN_SIZEOFRXFULLINTERRUPTPENDINGMASK                          STD_ON
#define CAN_SIZEOFSRCNUM                                              STD_ON
#define CAN_SIZEOFSTATUSREQ                                           STD_ON
#define CAN_SIZEOFTMPRXMSGMAILBOX                                     STD_ON
#define CAN_SIZEOFTXINTERRUPTPENDINGMASK                              STD_ON
#define CAN_SIZEOFTXOFFSETHWTOLOG                                     STD_ON
#define CAN_SRCNUM                                                    STD_ON
#define CAN_STATUSREQ                                                 STD_ON
#define CAN_TMPRXMSGMAILBOX                                           STD_ON
#define CAN_TXINTERRUPTPENDINGMASK                                    STD_ON
#define CAN_TXOFFSETHWTOLOG                                           STD_ON
#define CAN_PCCONFIG                                                  STD_ON
#define CAN_ACTIVESENDPDUOFPCCONFIG                                   STD_ON
#define CAN_ACTIVESENDSTATEOFPCCONFIG                                 STD_ON
#define CAN_BASEDLL_GENERATORVERSIONOFPCCONFIG                        STD_ON
#define CAN_BUSOFFNOTIFIEDOFPCCONFIG                                  STD_ON
#define CAN_CANIFCHANNELIDOFPCCONFIG                                  STD_ON
#define CAN_CANINTERRUPTCOUNTEROFPCCONFIG                             STD_ON
#define CAN_CANINTERRUPTOLDSTATUSOFPCCONFIG                           STD_ON
#define CAN_CONTROLLERCONFIGOFPCCONFIG                                STD_ON
#define CAN_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Can_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_GLOBALINTERRUPTPENDINGMASKOFPCCONFIG                      STD_ON
#define CAN_HALTOFPCCONFIG                                            STD_ON
#define CAN_INITBTOFPCCONFIG                                          STD_ON
#define CAN_INITCODEHOFPCCONFIG                                       STD_ON
#define CAN_INITCODELOFPCCONFIG                                       STD_ON
#define CAN_INITDATAHASHCODEOFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Can_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_INITMASKHOFPCCONFIG                                       STD_ON
#define CAN_INITMASKLOFPCCONFIG                                       STD_ON
#define CAN_INITOBJECTBAUDRATEOFPCCONFIG                              STD_ON
#define CAN_INITOBJECTSTARTINDEXOFPCCONFIG                            STD_ON
#define CAN_INITPORTSELOFPCCONFIG                                     STD_ON
#define CAN_ISBUSOFFOFPCCONFIG                                        STD_ON
#define CAN_ISHARDWARECANCELEDOFPCCONFIG                              STD_ON
#define CAN_ISROSIDOFPCCONFIG                                         STD_ON
#define CAN_LASTINITOBJECTOFPCCONFIG                                  STD_ON
#define CAN_LOGSTATUSOFPCCONFIG                                       STD_ON
#define CAN_LOOPTIMEOUTOFPCCONFIG                                     STD_ON
#define CAN_MAILBOXOFPCCONFIG                                         STD_ON
#define CAN_NODEADROFPCCONFIG                                         STD_ON
#define CAN_NODENUMOFPCCONFIG                                         STD_ON
#define CAN_PHYSPRIOOFPCCONFIG                                        STD_ON
#define CAN_PLATFORMDLL_GENERATORVERSIONOFPCCONFIG                    STD_ON
#define CAN_RXBASICINTERRUPTPENDINGMASKOFPCCONFIG                     STD_ON
#define CAN_RXFULLINTERRUPTPENDINGMASKOFPCCONFIG                      STD_ON
#define CAN_SIZEOFACTIVESENDPDUOFPCCONFIG                             STD_ON
#define CAN_SIZEOFACTIVESENDSTATEOFPCCONFIG                           STD_ON
#define CAN_SIZEOFBUSOFFNOTIFIEDOFPCCONFIG                            STD_ON
#define CAN_SIZEOFCANIFCHANNELIDOFPCCONFIG                            STD_ON
#define CAN_SIZEOFCANINTERRUPTCOUNTEROFPCCONFIG                       STD_ON
#define CAN_SIZEOFCANINTERRUPTOLDSTATUSOFPCCONFIG                     STD_ON
#define CAN_SIZEOFCONTROLLERCONFIGOFPCCONFIG                          STD_ON
#define CAN_SIZEOFGLOBALINTERRUPTPENDINGMASKOFPCCONFIG                STD_ON
#define CAN_SIZEOFHALTOFPCCONFIG                                      STD_ON
#define CAN_SIZEOFINITBTOFPCCONFIG                                    STD_ON
#define CAN_SIZEOFINITCODEHOFPCCONFIG                                 STD_ON
#define CAN_SIZEOFINITCODELOFPCCONFIG                                 STD_ON
#define CAN_SIZEOFINITMASKHOFPCCONFIG                                 STD_ON
#define CAN_SIZEOFINITMASKLOFPCCONFIG                                 STD_ON
#define CAN_SIZEOFINITOBJECTBAUDRATEOFPCCONFIG                        STD_ON
#define CAN_SIZEOFINITOBJECTSTARTINDEXOFPCCONFIG                      STD_ON
#define CAN_SIZEOFINITPORTSELOFPCCONFIG                               STD_ON
#define CAN_SIZEOFISBUSOFFOFPCCONFIG                                  STD_ON
#define CAN_SIZEOFISHARDWARECANCELEDOFPCCONFIG                        STD_ON
#define CAN_SIZEOFISROSIDOFPCCONFIG                                   STD_ON
#define CAN_SIZEOFLASTINITOBJECTOFPCCONFIG                            STD_ON
#define CAN_SIZEOFLOGSTATUSOFPCCONFIG                                 STD_ON
#define CAN_SIZEOFLOOPTIMEOUTOFPCCONFIG                               STD_ON
#define CAN_SIZEOFMAILBOXOFPCCONFIG                                   STD_ON
#define CAN_SIZEOFNODEADROFPCCONFIG                                   STD_ON
#define CAN_SIZEOFNODENUMOFPCCONFIG                                   STD_ON
#define CAN_SIZEOFPHYSPRIOOFPCCONFIG                                  STD_ON
#define CAN_SIZEOFRXBASICINTERRUPTPENDINGMASKOFPCCONFIG               STD_ON
#define CAN_SIZEOFRXFULLINTERRUPTPENDINGMASKOFPCCONFIG                STD_ON
#define CAN_SIZEOFSRCNUMOFPCCONFIG                                    STD_ON
#define CAN_SIZEOFSTATUSREQOFPCCONFIG                                 STD_ON
#define CAN_SIZEOFTMPRXMSGMAILBOXOFPCCONFIG                           STD_ON
#define CAN_SIZEOFTXINTERRUPTPENDINGMASKOFPCCONFIG                    STD_ON
#define CAN_SIZEOFTXOFFSETHWTOLOGOFPCCONFIG                           STD_ON
#define CAN_SRCNUMOFPCCONFIG                                          STD_ON
#define CAN_STATUSREQOFPCCONFIG                                       STD_ON
#define CAN_TMPRXMSGMAILBOXOFPCCONFIG                                 STD_ON
#define CAN_TXINTERRUPTPENDINGMASKOFPCCONFIG                          STD_ON
#define CAN_TXOFFSETHWTOLOGOFPCCONFIG                                 STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanPCMinNumericValueDefines  Can Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CAN_MIN_ACTIVESENDPDU                                         0U
#define CAN_MIN_ACTIVESENDSTATE                                       0U
#define CAN_MIN_BUSOFFNOTIFIED                                        0U
#define CAN_MIN_CANINTERRUPTCOUNTER                                   0U
#define CAN_MIN_HALT                                                  0U
#define CAN_MIN_LASTINITOBJECT                                        0U
#define CAN_MIN_LOGSTATUS                                             0U
#define CAN_MIN_STATUSREQ                                             0U
/** 
  \}
*/ 

/** 
  \defgroup  CanPCMaxNumericValueDefines  Can Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CAN_MAX_ACTIVESENDPDU                                         255U
#define CAN_MAX_ACTIVESENDSTATE                                       255U
#define CAN_MAX_BUSOFFNOTIFIED                                        255U
#define CAN_MAX_CANINTERRUPTCOUNTER                                   255U
#define CAN_MAX_HALT                                                  255U
#define CAN_MAX_LASTINITOBJECT                                        255U
#define CAN_MAX_LOGSTATUS                                             255U
#define CAN_MAX_STATUSREQ                                             255U
/** 
  \}
*/ 

/** 
  \defgroup  CanPCNoReferenceDefines  Can No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CAN_NO_CANIFCHANNELID                                         255U
#define CAN_NO_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG         65535U
#define CAN_NO_RXBASICHANDLEMAXOFCONTROLLERCONFIG                     255U
#define CAN_NO_RXBASICHANDLESTARTOFCONTROLLERCONFIG                   255U
#define CAN_NO_RXBASICHANDLESTOPOFCONTROLLERCONFIG                    255U
#define CAN_NO_RXBASICHWSTARTOFCONTROLLERCONFIG                       255U
#define CAN_NO_RXBASICHWSTOPOFCONTROLLERCONFIG                        255U
#define CAN_NO_RXFULLHANDLEMAXOFCONTROLLERCONFIG                      255U
#define CAN_NO_RXFULLHANDLESTARTOFCONTROLLERCONFIG                    255U
#define CAN_NO_RXFULLHANDLESTOPOFCONTROLLERCONFIG                     255U
#define CAN_NO_RXFULLHWSTARTOFCONTROLLERCONFIG                        255U
#define CAN_NO_RXFULLHWSTOPOFCONTROLLERCONFIG                         255U
#define CAN_NO_TXBASICHANDLEMAXOFCONTROLLERCONFIG                     255U
#define CAN_NO_TXBASICHANDLESTARTOFCONTROLLERCONFIG                   255U
#define CAN_NO_TXBASICHANDLESTOPOFCONTROLLERCONFIG                    255U
#define CAN_NO_TXBASICHWSTARTOFCONTROLLERCONFIG                       255U
#define CAN_NO_TXBASICHWSTOPOFCONTROLLERCONFIG                        255U
#define CAN_NO_TXFULLHANDLEMAXOFCONTROLLERCONFIG                      255U
#define CAN_NO_TXFULLHANDLESTARTOFCONTROLLERCONFIG                    255U
#define CAN_NO_TXFULLHANDLESTOPOFCONTROLLERCONFIG                     255U
#define CAN_NO_TXFULLHWSTARTOFCONTROLLERCONFIG                        255U
#define CAN_NO_TXFULLHWSTOPOFCONTROLLERCONFIG                         255U
#define CAN_NO_UNUSEDHANDLEMAXOFCONTROLLERCONFIG                      255U
#define CAN_NO_UNUSEDHANDLESTARTOFCONTROLLERCONFIG                    255U
#define CAN_NO_UNUSEDHANDLESTOPOFCONTROLLERCONFIG                     255U
#define CAN_NO_UNUSEDHWSTARTOFCONTROLLERCONFIG                        255U
#define CAN_NO_UNUSEDHWSTOPOFCONTROLLERCONFIG                         255U
#define CAN_NO_GLOBALINTERRUPTPENDINGMASK                             4294967295UL
#define CAN_NO_INITBT                                                 65535U
#define CAN_NO_INITCODEH                                              65535U
#define CAN_NO_INITCODEL                                              65535U
#define CAN_NO_INITMASKH                                              65535U
#define CAN_NO_INITMASKL                                              65535U
#define CAN_NO_INITPORTSEL                                            255U
#define CAN_NO_NODEADR                                                4294967295UL
#define CAN_NO_NODENUM                                                255U
#define CAN_NO_PHYSPRIO                                               65535U
#define CAN_NO_RXBASICINTERRUPTPENDINGMASK                            4294967295UL
#define CAN_NO_RXFULLINTERRUPTPENDINGMASK                             4294967295UL
#define CAN_NO_SRCNUM                                                 255U
#define CAN_NO_TXINTERRUPTPENDINGMASK                                 4294967295UL
#define CAN_NO_TXOFFSETHWTOLOG                                        32767
/** 
  \}
*/ 

/** 
  \defgroup  CanPCEnumExistsDefines  Can Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define CAN_EXISTS_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX              STD_ON
#define CAN_EXISTS_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX               STD_OFF
#define CAN_EXISTS_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX              STD_ON
#define CAN_EXISTS_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX               STD_OFF
#define CAN_EXISTS_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanPCEnumDefines  Can Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                     0x00U
#define CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                     0x02U
#define CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX                      0x04U
/** 
  \}
*/ 

/** 
  \defgroup  CanPCIsReducedToDefineDefines  Can Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CAN_ISDEF_CANIFCHANNELID                                      STD_OFF
#define CAN_ISDEF_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG      STD_OFF
#define CAN_ISDEF_RXBASICHANDLEMAXOFCONTROLLERCONFIG                  STD_OFF
#define CAN_ISDEF_RXBASICHANDLESTARTOFCONTROLLERCONFIG                STD_OFF
#define CAN_ISDEF_RXBASICHANDLESTOPOFCONTROLLERCONFIG                 STD_OFF
#define CAN_ISDEF_RXBASICHWSTARTOFCONTROLLERCONFIG                    STD_OFF
#define CAN_ISDEF_RXBASICHWSTOPOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_RXFULLHANDLEMAXOFCONTROLLERCONFIG                   STD_OFF
#define CAN_ISDEF_RXFULLHANDLESTARTOFCONTROLLERCONFIG                 STD_OFF
#define CAN_ISDEF_RXFULLHANDLESTOPOFCONTROLLERCONFIG                  STD_OFF
#define CAN_ISDEF_RXFULLHWSTARTOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_RXFULLHWSTOPOFCONTROLLERCONFIG                      STD_OFF
#define CAN_ISDEF_TXBASICHANDLEMAXOFCONTROLLERCONFIG                  STD_OFF
#define CAN_ISDEF_TXBASICHANDLESTARTOFCONTROLLERCONFIG                STD_OFF
#define CAN_ISDEF_TXBASICHANDLESTOPOFCONTROLLERCONFIG                 STD_OFF
#define CAN_ISDEF_TXBASICHWSTARTOFCONTROLLERCONFIG                    STD_OFF
#define CAN_ISDEF_TXBASICHWSTOPOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_TXFULLHANDLEMAXOFCONTROLLERCONFIG                   STD_OFF
#define CAN_ISDEF_TXFULLHANDLESTARTOFCONTROLLERCONFIG                 STD_OFF
#define CAN_ISDEF_TXFULLHANDLESTOPOFCONTROLLERCONFIG                  STD_OFF
#define CAN_ISDEF_TXFULLHWSTARTOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_TXFULLHWSTOPOFCONTROLLERCONFIG                      STD_OFF
#define CAN_ISDEF_UNUSEDHANDLEMAXOFCONTROLLERCONFIG                   STD_OFF
#define CAN_ISDEF_UNUSEDHANDLESTARTOFCONTROLLERCONFIG                 STD_OFF
#define CAN_ISDEF_UNUSEDHANDLESTOPOFCONTROLLERCONFIG                  STD_OFF
#define CAN_ISDEF_UNUSEDHWSTARTOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_UNUSEDHWSTOPOFCONTROLLERCONFIG                      STD_OFF
#define CAN_ISDEF_GLOBALINTERRUPTPENDINGMASK                          STD_OFF
#define CAN_ISDEF_INITBT                                              STD_OFF
#define CAN_ISDEF_INITCODEH                                           STD_OFF
#define CAN_ISDEF_INITCODEL                                           STD_OFF
#define CAN_ISDEF_INITMASKH                                           STD_OFF
#define CAN_ISDEF_INITMASKL                                           STD_OFF
#define CAN_ISDEF_INITOBJECTBAUDRATE                                  STD_OFF
#define CAN_ISDEF_INITOBJECTSTARTINDEX                                STD_OFF
#define CAN_ISDEF_INITPORTSEL                                         STD_OFF
#define CAN_ISDEF_ISROSID                                             STD_OFF
#define CAN_ISDEF_DLC_FIFOOFMAILBOX                                   STD_OFF
#define CAN_ISDEF_HWHANDLEOFMAILBOX                                   STD_OFF
#define CAN_ISDEF_IDVALUEOFMAILBOX                                    STD_OFF
#define CAN_ISDEF_MAILBOXTYPEOFMAILBOX                                STD_OFF
#define CAN_ISDEF_MAXDATALENOFMAILBOX                                 STD_OFF
#define CAN_ISDEF_MSGCONTROLLEROFMAILBOX                              STD_OFF
#define CAN_ISDEF_NODEADR                                             STD_OFF
#define CAN_ISDEF_NODENUM                                             STD_OFF
#define CAN_ISDEF_PHYSPRIO                                            STD_OFF
#define CAN_ISDEF_RXBASICINTERRUPTPENDINGMASK                         STD_OFF
#define CAN_ISDEF_RXFULLINTERRUPTPENDINGMASK                          STD_OFF
#define CAN_ISDEF_SRCNUM                                              STD_OFF
#define CAN_ISDEF_TXINTERRUPTPENDINGMASK                              STD_OFF
#define CAN_ISDEF_TXOFFSETHWTOLOG                                     STD_OFF
#define CAN_ISDEF_ACTIVESENDPDUOFPCCONFIG                             STD_ON
#define CAN_ISDEF_ACTIVESENDSTATEOFPCCONFIG                           STD_ON
#define CAN_ISDEF_BUSOFFNOTIFIEDOFPCCONFIG                            STD_ON
#define CAN_ISDEF_CANIFCHANNELIDOFPCCONFIG                            STD_ON
#define CAN_ISDEF_CANINTERRUPTCOUNTEROFPCCONFIG                       STD_ON
#define CAN_ISDEF_CANINTERRUPTOLDSTATUSOFPCCONFIG                     STD_ON
#define CAN_ISDEF_CONTROLLERCONFIGOFPCCONFIG                          STD_ON
#define CAN_ISDEF_GLOBALINTERRUPTPENDINGMASKOFPCCONFIG                STD_ON
#define CAN_ISDEF_HALTOFPCCONFIG                                      STD_ON
#define CAN_ISDEF_INITBTOFPCCONFIG                                    STD_ON
#define CAN_ISDEF_INITCODEHOFPCCONFIG                                 STD_ON
#define CAN_ISDEF_INITCODELOFPCCONFIG                                 STD_ON
#define CAN_ISDEF_INITMASKHOFPCCONFIG                                 STD_ON
#define CAN_ISDEF_INITMASKLOFPCCONFIG                                 STD_ON
#define CAN_ISDEF_INITOBJECTBAUDRATEOFPCCONFIG                        STD_ON
#define CAN_ISDEF_INITOBJECTSTARTINDEXOFPCCONFIG                      STD_ON
#define CAN_ISDEF_INITPORTSELOFPCCONFIG                               STD_ON
#define CAN_ISDEF_ISBUSOFFOFPCCONFIG                                  STD_ON
#define CAN_ISDEF_ISHARDWARECANCELEDOFPCCONFIG                        STD_ON
#define CAN_ISDEF_ISROSIDOFPCCONFIG                                   STD_ON
#define CAN_ISDEF_LASTINITOBJECTOFPCCONFIG                            STD_ON
#define CAN_ISDEF_LOGSTATUSOFPCCONFIG                                 STD_ON
#define CAN_ISDEF_LOOPTIMEOUTOFPCCONFIG                               STD_ON
#define CAN_ISDEF_MAILBOXOFPCCONFIG                                   STD_ON
#define CAN_ISDEF_NODEADROFPCCONFIG                                   STD_ON
#define CAN_ISDEF_NODENUMOFPCCONFIG                                   STD_ON
#define CAN_ISDEF_PHYSPRIOOFPCCONFIG                                  STD_ON
#define CAN_ISDEF_RXBASICINTERRUPTPENDINGMASKOFPCCONFIG               STD_ON
#define CAN_ISDEF_RXFULLINTERRUPTPENDINGMASKOFPCCONFIG                STD_ON
#define CAN_ISDEF_SRCNUMOFPCCONFIG                                    STD_ON
#define CAN_ISDEF_STATUSREQOFPCCONFIG                                 STD_ON
#define CAN_ISDEF_TMPRXMSGMAILBOXOFPCCONFIG                           STD_ON
#define CAN_ISDEF_TXINTERRUPTPENDINGMASKOFPCCONFIG                    STD_ON
#define CAN_ISDEF_TXOFFSETHWTOLOGOFPCCONFIG                           STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanPCEqualsAlwaysToDefines  Can Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CAN_EQ2_CANIFCHANNELID                                        
#define CAN_EQ2_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG        
#define CAN_EQ2_RXBASICHANDLEMAXOFCONTROLLERCONFIG                    
#define CAN_EQ2_RXBASICHANDLESTARTOFCONTROLLERCONFIG                  
#define CAN_EQ2_RXBASICHANDLESTOPOFCONTROLLERCONFIG                   
#define CAN_EQ2_RXBASICHWSTARTOFCONTROLLERCONFIG                      
#define CAN_EQ2_RXBASICHWSTOPOFCONTROLLERCONFIG                       
#define CAN_EQ2_RXFULLHANDLEMAXOFCONTROLLERCONFIG                     
#define CAN_EQ2_RXFULLHANDLESTARTOFCONTROLLERCONFIG                   
#define CAN_EQ2_RXFULLHANDLESTOPOFCONTROLLERCONFIG                    
#define CAN_EQ2_RXFULLHWSTARTOFCONTROLLERCONFIG                       
#define CAN_EQ2_RXFULLHWSTOPOFCONTROLLERCONFIG                        
#define CAN_EQ2_TXBASICHANDLEMAXOFCONTROLLERCONFIG                    
#define CAN_EQ2_TXBASICHANDLESTARTOFCONTROLLERCONFIG                  
#define CAN_EQ2_TXBASICHANDLESTOPOFCONTROLLERCONFIG                   
#define CAN_EQ2_TXBASICHWSTARTOFCONTROLLERCONFIG                      
#define CAN_EQ2_TXBASICHWSTOPOFCONTROLLERCONFIG                       
#define CAN_EQ2_TXFULLHANDLEMAXOFCONTROLLERCONFIG                     
#define CAN_EQ2_TXFULLHANDLESTARTOFCONTROLLERCONFIG                   
#define CAN_EQ2_TXFULLHANDLESTOPOFCONTROLLERCONFIG                    
#define CAN_EQ2_TXFULLHWSTARTOFCONTROLLERCONFIG                       
#define CAN_EQ2_TXFULLHWSTOPOFCONTROLLERCONFIG                        
#define CAN_EQ2_UNUSEDHANDLEMAXOFCONTROLLERCONFIG                     
#define CAN_EQ2_UNUSEDHANDLESTARTOFCONTROLLERCONFIG                   
#define CAN_EQ2_UNUSEDHANDLESTOPOFCONTROLLERCONFIG                    
#define CAN_EQ2_UNUSEDHWSTARTOFCONTROLLERCONFIG                       
#define CAN_EQ2_UNUSEDHWSTOPOFCONTROLLERCONFIG                        
#define CAN_EQ2_GLOBALINTERRUPTPENDINGMASK                            
#define CAN_EQ2_INITBT                                                
#define CAN_EQ2_INITCODEH                                             
#define CAN_EQ2_INITCODEL                                             
#define CAN_EQ2_INITMASKH                                             
#define CAN_EQ2_INITMASKL                                             
#define CAN_EQ2_INITOBJECTBAUDRATE                                    
#define CAN_EQ2_INITOBJECTSTARTINDEX                                  
#define CAN_EQ2_INITPORTSEL                                           
#define CAN_EQ2_ISROSID                                               
#define CAN_EQ2_DLC_FIFOOFMAILBOX                                     
#define CAN_EQ2_HWHANDLEOFMAILBOX                                     
#define CAN_EQ2_IDVALUEOFMAILBOX                                      
#define CAN_EQ2_MAILBOXTYPEOFMAILBOX                                  
#define CAN_EQ2_MAXDATALENOFMAILBOX                                   
#define CAN_EQ2_MSGCONTROLLEROFMAILBOX                                
#define CAN_EQ2_NODEADR                                               
#define CAN_EQ2_NODENUM                                               
#define CAN_EQ2_PHYSPRIO                                              
#define CAN_EQ2_RXBASICINTERRUPTPENDINGMASK                           
#define CAN_EQ2_RXFULLINTERRUPTPENDINGMASK                            
#define CAN_EQ2_SRCNUM                                                
#define CAN_EQ2_TXINTERRUPTPENDINGMASK                                
#define CAN_EQ2_TXOFFSETHWTOLOG                                       
#define CAN_EQ2_ACTIVESENDPDUOFPCCONFIG                               Can_ActiveSendPdu
#define CAN_EQ2_ACTIVESENDSTATEOFPCCONFIG                             Can_ActiveSendState
#define CAN_EQ2_BUSOFFNOTIFIEDOFPCCONFIG                              Can_BusOffNotified
#define CAN_EQ2_CANIFCHANNELIDOFPCCONFIG                              Can_CanIfChannelId
#define CAN_EQ2_CANINTERRUPTCOUNTEROFPCCONFIG                         Can_CanInterruptCounter
#define CAN_EQ2_CANINTERRUPTOLDSTATUSOFPCCONFIG                       Can_CanInterruptOldStatus
#define CAN_EQ2_CONTROLLERCONFIGOFPCCONFIG                            Can_ControllerConfig
#define CAN_EQ2_GLOBALINTERRUPTPENDINGMASKOFPCCONFIG                  Can_GlobalInterruptPendingMask
#define CAN_EQ2_HALTOFPCCONFIG                                        Can_Halt
#define CAN_EQ2_INITBTOFPCCONFIG                                      Can_InitBT
#define CAN_EQ2_INITCODEHOFPCCONFIG                                   Can_InitCodeH
#define CAN_EQ2_INITCODELOFPCCONFIG                                   Can_InitCodeL
#define CAN_EQ2_INITMASKHOFPCCONFIG                                   Can_InitMaskH
#define CAN_EQ2_INITMASKLOFPCCONFIG                                   Can_InitMaskL
#define CAN_EQ2_INITOBJECTBAUDRATEOFPCCONFIG                          Can_InitObjectBaudrate
#define CAN_EQ2_INITOBJECTSTARTINDEXOFPCCONFIG                        Can_InitObjectStartIndex
#define CAN_EQ2_INITPORTSELOFPCCONFIG                                 Can_InitPortSel
#define CAN_EQ2_ISBUSOFFOFPCCONFIG                                    Can_IsBusOff
#define CAN_EQ2_ISHARDWARECANCELEDOFPCCONFIG                          Can_IsHardwareCanceled
#define CAN_EQ2_ISROSIDOFPCCONFIG                                     Can_IsrOsId
#define CAN_EQ2_LASTINITOBJECTOFPCCONFIG                              Can_LastInitObject
#define CAN_EQ2_LOGSTATUSOFPCCONFIG                                   Can_LogStatus
#define CAN_EQ2_LOOPTIMEOUTOFPCCONFIG                                 Can_LoopTimeout
#define CAN_EQ2_MAILBOXOFPCCONFIG                                     Can_Mailbox
#define CAN_EQ2_NODEADROFPCCONFIG                                     Can_NodeAdr
#define CAN_EQ2_NODENUMOFPCCONFIG                                     Can_NodeNum
#define CAN_EQ2_PHYSPRIOOFPCCONFIG                                    Can_PhysPrio
#define CAN_EQ2_RXBASICINTERRUPTPENDINGMASKOFPCCONFIG                 Can_RxBasicInterruptPendingMask
#define CAN_EQ2_RXFULLINTERRUPTPENDINGMASKOFPCCONFIG                  Can_RxFullInterruptPendingMask
#define CAN_EQ2_SRCNUMOFPCCONFIG                                      Can_SrcNum
#define CAN_EQ2_STATUSREQOFPCCONFIG                                   Can_StatusReq
#define CAN_EQ2_TMPRXMSGMAILBOXOFPCCONFIG                             Can_TmpRxMsgMailbox
#define CAN_EQ2_TXINTERRUPTPENDINGMASKOFPCCONFIG                      Can_TxInterruptPendingMask
#define CAN_EQ2_TXOFFSETHWTOLOGOFPCCONFIG                             Can_TxOffsetHwToLog
/** 
  \}
*/ 

/** 
  \defgroup  CanPCSymbolicInitializationPointers  Can Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Can_Config_Ptr                                                NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Can' */
/** 
  \}
*/ 

/** 
  \defgroup  CanPCInitializationSymbols  Can Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Can_Config                                                    NULL_PTR  /**< symbolic identifier which could be used to initialize 'Can */
/** 
  \}
*/ 

/** 
  \defgroup  CanPCGeneral  Can General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CAN_CHECK_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CAN_FINAL_MAGIC_NUMBER                                        0x501EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of Can */
#define CAN_INDIVIDUAL_POSTBUILD                                      STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Can' is not configured to be postbuild capable. */
#define CAN_INIT_DATA                                                 CAN_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CAN_INIT_DATA_HASH_CODE                                       -1002145066L  /**< the precompile constant to validate the initialization structure at initialization time of Can with a hashcode. The seed value is '0x501EU' */
#define CAN_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CAN_USE_INIT_POINTER                                          STD_OFF  /**< STD_ON if the init pointer Can shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanLTDataSwitches  Can Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CAN_LTCONFIG                                                  STD_OFF  /**< Deactivateable: 'Can_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanPBDataSwitches  Can Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CAN_PBCONFIG                                                  STD_OFF  /**< Deactivateable: 'Can_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CAN_LTCONFIGIDXOFPBCONFIG                                     STD_OFF  /**< Deactivateable: 'Can_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CAN_PCCONFIGIDXOFPBCONFIG                                     STD_OFF  /**< Deactivateable: 'Can_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanPCGetConstantDuplicatedRootDataMacros  Can Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Can_GetActiveSendPduOfPCConfig()                              Can_ActiveSendPdu  /**< the pointer to Can_ActiveSendPdu */
#define Can_GetActiveSendStateOfPCConfig()                            Can_ActiveSendState  /**< the pointer to Can_ActiveSendState */
#define Can_GetBaseDll_GeneratorVersionOfPCConfig()                   0x0103U
#define Can_GetBusOffNotifiedOfPCConfig()                             Can_BusOffNotified  /**< the pointer to Can_BusOffNotified */
#define Can_GetCanIfChannelIdOfPCConfig()                             Can_CanIfChannelId  /**< the pointer to Can_CanIfChannelId */
#define Can_GetCanInterruptCounterOfPCConfig()                        Can_CanInterruptCounter  /**< the pointer to Can_CanInterruptCounter */
#define Can_GetCanInterruptOldStatusOfPCConfig()                      Can_CanInterruptOldStatus  /**< the pointer to Can_CanInterruptOldStatus */
#define Can_GetControllerConfigOfPCConfig()                           Can_ControllerConfig  /**< the pointer to Can_ControllerConfig */
#define Can_GetGlobalInterruptPendingMaskOfPCConfig()                 Can_GlobalInterruptPendingMask  /**< the pointer to Can_GlobalInterruptPendingMask */
#define Can_GetHaltOfPCConfig()                                       Can_Halt  /**< the pointer to Can_Halt */
#define Can_GetInitBTOfPCConfig()                                     Can_InitBT  /**< the pointer to Can_InitBT */
#define Can_GetInitCodeHOfPCConfig()                                  Can_InitCodeH  /**< the pointer to Can_InitCodeH */
#define Can_GetInitCodeLOfPCConfig()                                  Can_InitCodeL  /**< the pointer to Can_InitCodeL */
#define Can_GetInitMaskHOfPCConfig()                                  Can_InitMaskH  /**< the pointer to Can_InitMaskH */
#define Can_GetInitMaskLOfPCConfig()                                  Can_InitMaskL  /**< the pointer to Can_InitMaskL */
#define Can_GetInitObjectBaudrateOfPCConfig()                         Can_InitObjectBaudrate  /**< the pointer to Can_InitObjectBaudrate */
#define Can_GetInitObjectStartIndexOfPCConfig()                       Can_InitObjectStartIndex  /**< the pointer to Can_InitObjectStartIndex */
#define Can_GetInitPortSelOfPCConfig()                                Can_InitPortSel  /**< the pointer to Can_InitPortSel */
#define Can_GetIsBusOffOfPCConfig()                                   Can_IsBusOff  /**< the pointer to Can_IsBusOff */
#define Can_GetIsHardwareCanceledOfPCConfig()                         Can_IsHardwareCanceled  /**< the pointer to Can_IsHardwareCanceled */
#define Can_GetIsrOsIdOfPCConfig()                                    Can_IsrOsId  /**< the pointer to Can_IsrOsId */
#define Can_GetLastInitObjectOfPCConfig()                             Can_LastInitObject  /**< the pointer to Can_LastInitObject */
#define Can_GetLogStatusOfPCConfig()                                  Can_LogStatus  /**< the pointer to Can_LogStatus */
#define Can_GetLoopTimeoutOfPCConfig()                                Can_LoopTimeout  /**< the pointer to Can_LoopTimeout */
#define Can_GetMailboxOfPCConfig()                                    Can_Mailbox  /**< the pointer to Can_Mailbox */
#define Can_GetNodeAdrOfPCConfig()                                    Can_NodeAdr  /**< the pointer to Can_NodeAdr */
#define Can_GetNodeNumOfPCConfig()                                    Can_NodeNum  /**< the pointer to Can_NodeNum */
#define Can_GetPhysPrioOfPCConfig()                                   Can_PhysPrio  /**< the pointer to Can_PhysPrio */
#define Can_GetPlatformDll_GeneratorVersionOfPCConfig()               0x0101U
#define Can_GetRxBasicInterruptPendingMaskOfPCConfig()                Can_RxBasicInterruptPendingMask  /**< the pointer to Can_RxBasicInterruptPendingMask */
#define Can_GetRxFullInterruptPendingMaskOfPCConfig()                 Can_RxFullInterruptPendingMask  /**< the pointer to Can_RxFullInterruptPendingMask */
#define Can_GetSizeOfActiveSendPduOfPCConfig()                        3U  /**< the number of accomplishable value elements in Can_ActiveSendPdu */
#define Can_GetSizeOfActiveSendStateOfPCConfig()                      3U  /**< the number of accomplishable value elements in Can_ActiveSendState */
#define Can_GetSizeOfBusOffNotifiedOfPCConfig()                       3U  /**< the number of accomplishable value elements in Can_BusOffNotified */
#define Can_GetSizeOfCanIfChannelIdOfPCConfig()                       3U  /**< the number of accomplishable value elements in Can_CanIfChannelId */
#define Can_GetSizeOfCanInterruptCounterOfPCConfig()                  3U  /**< the number of accomplishable value elements in Can_CanInterruptCounter */
#define Can_GetSizeOfCanInterruptOldStatusOfPCConfig()                3U  /**< the number of accomplishable value elements in Can_CanInterruptOldStatus */
#define Can_GetSizeOfControllerConfigOfPCConfig()                     3U  /**< the number of accomplishable value elements in Can_ControllerConfig */
#define Can_GetSizeOfGlobalInterruptPendingMaskOfPCConfig()           24U  /**< the number of accomplishable value elements in Can_GlobalInterruptPendingMask */
#define Can_GetSizeOfHaltOfPCConfig()                                 3U  /**< the number of accomplishable value elements in Can_Halt */
#define Can_GetSizeOfInitBTOfPCConfig()                               3U  /**< the number of accomplishable value elements in Can_InitBT */
#define Can_GetSizeOfInitCodeHOfPCConfig()                            3U  /**< the number of accomplishable value elements in Can_InitCodeH */
#define Can_GetSizeOfInitCodeLOfPCConfig()                            3U  /**< the number of accomplishable value elements in Can_InitCodeL */
#define Can_GetSizeOfInitMaskHOfPCConfig()                            3U  /**< the number of accomplishable value elements in Can_InitMaskH */
#define Can_GetSizeOfInitMaskLOfPCConfig()                            3U  /**< the number of accomplishable value elements in Can_InitMaskL */
#define Can_GetSizeOfInitObjectBaudrateOfPCConfig()                   3U  /**< the number of accomplishable value elements in Can_InitObjectBaudrate */
#define Can_GetSizeOfInitObjectStartIndexOfPCConfig()                 4U  /**< the number of accomplishable value elements in Can_InitObjectStartIndex */
#define Can_GetSizeOfInitPortSelOfPCConfig()                          3U  /**< the number of accomplishable value elements in Can_InitPortSel */
#define Can_GetSizeOfIsBusOffOfPCConfig()                             3U  /**< the number of accomplishable value elements in Can_IsBusOff */
#define Can_GetSizeOfIsHardwareCanceledOfPCConfig()                   3U  /**< the number of accomplishable value elements in Can_IsHardwareCanceled */
#define Can_GetSizeOfIsrOsIdOfPCConfig()                              3U  /**< the number of accomplishable value elements in Can_IsrOsId */
#define Can_GetSizeOfLastInitObjectOfPCConfig()                       3U  /**< the number of accomplishable value elements in Can_LastInitObject */
#define Can_GetSizeOfLogStatusOfPCConfig()                            3U  /**< the number of accomplishable value elements in Can_LogStatus */
#define Can_GetSizeOfLoopTimeoutOfPCConfig()                          3U  /**< the number of accomplishable value elements in Can_LoopTimeout */
#define Can_GetSizeOfMailboxOfPCConfig()                              9U  /**< the number of accomplishable value elements in Can_Mailbox */
#define Can_GetSizeOfNodeAdrOfPCConfig()                              3U  /**< the number of accomplishable value elements in Can_NodeAdr */
#define Can_GetSizeOfNodeNumOfPCConfig()                              3U  /**< the number of accomplishable value elements in Can_NodeNum */
#define Can_GetSizeOfPhysPrioOfPCConfig()                             8U  /**< the number of accomplishable value elements in Can_PhysPrio */
#define Can_GetSizeOfRxBasicInterruptPendingMaskOfPCConfig()          24U  /**< the number of accomplishable value elements in Can_RxBasicInterruptPendingMask */
#define Can_GetSizeOfRxFullInterruptPendingMaskOfPCConfig()           24U  /**< the number of accomplishable value elements in Can_RxFullInterruptPendingMask */
#define Can_GetSizeOfSrcNumOfPCConfig()                               3U  /**< the number of accomplishable value elements in Can_SrcNum */
#define Can_GetSizeOfStatusReqOfPCConfig()                            3U  /**< the number of accomplishable value elements in Can_StatusReq */
#define Can_GetSizeOfTmpRxMsgMailboxOfPCConfig()                      3U  /**< the number of accomplishable value elements in Can_TmpRxMsgMailbox */
#define Can_GetSizeOfTxInterruptPendingMaskOfPCConfig()               24U  /**< the number of accomplishable value elements in Can_TxInterruptPendingMask */
#define Can_GetSizeOfTxOffsetHwToLogOfPCConfig()                      3U  /**< the number of accomplishable value elements in Can_TxOffsetHwToLog */
#define Can_GetSrcNumOfPCConfig()                                     Can_SrcNum  /**< the pointer to Can_SrcNum */
#define Can_GetStatusReqOfPCConfig()                                  Can_StatusReq  /**< the pointer to Can_StatusReq */
#define Can_GetTmpRxMsgMailboxOfPCConfig()                            Can_TmpRxMsgMailbox  /**< the pointer to Can_TmpRxMsgMailbox */
#define Can_GetTxInterruptPendingMaskOfPCConfig()                     Can_TxInterruptPendingMask  /**< the pointer to Can_TxInterruptPendingMask */
#define Can_GetTxOffsetHwToLogOfPCConfig()                            Can_TxOffsetHwToLog  /**< the pointer to Can_TxOffsetHwToLog */
/** 
  \}
*/ 

/** 
  \defgroup  CanPCGetDataMacros  Can Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Can_GetActiveSendPdu(Index)                                   (Can_GetActiveSendPduOfPCConfig()[(Index)])
#define Can_GetActiveSendState(Index)                                 (Can_GetActiveSendStateOfPCConfig()[(Index)])
#define Can_GetBusOffNotified(Index)                                  (Can_GetBusOffNotifiedOfPCConfig()[(Index)])
#define Can_GetCanIfChannelId(Index)                                  (Can_GetCanIfChannelIdOfPCConfig()[(Index)])
#define Can_GetCanInterruptCounter(Index)                             (Can_GetCanInterruptCounterOfPCConfig()[(Index)])
#define Can_GetCanInterruptOldStatus(Index)                           (Can_GetCanInterruptOldStatusOfPCConfig()[(Index)])
#define Can_GetCanControllerDefaultBaudrateOfControllerConfig(Index)  (Can_GetControllerConfigOfPCConfig()[(Index)].CanControllerDefaultBaudrateOfControllerConfig)
#define Can_GetRxBasicHandleMaxOfControllerConfig(Index)              (Can_GetControllerConfigOfPCConfig()[(Index)].RxBasicHandleMaxOfControllerConfig)
#define Can_GetRxBasicHandleStartOfControllerConfig(Index)            (Can_GetControllerConfigOfPCConfig()[(Index)].RxBasicHandleStartOfControllerConfig)
#define Can_GetRxBasicHandleStopOfControllerConfig(Index)             (Can_GetControllerConfigOfPCConfig()[(Index)].RxBasicHandleStopOfControllerConfig)
#define Can_GetRxBasicHwStartOfControllerConfig(Index)                (Can_GetControllerConfigOfPCConfig()[(Index)].RxBasicHwStartOfControllerConfig)
#define Can_GetRxBasicHwStopOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].RxBasicHwStopOfControllerConfig)
#define Can_GetRxFullHandleMaxOfControllerConfig(Index)               (Can_GetControllerConfigOfPCConfig()[(Index)].RxFullHandleMaxOfControllerConfig)
#define Can_GetRxFullHandleStartOfControllerConfig(Index)             (Can_GetControllerConfigOfPCConfig()[(Index)].RxFullHandleStartOfControllerConfig)
#define Can_GetRxFullHandleStopOfControllerConfig(Index)              (Can_GetControllerConfigOfPCConfig()[(Index)].RxFullHandleStopOfControllerConfig)
#define Can_GetRxFullHwStartOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].RxFullHwStartOfControllerConfig)
#define Can_GetRxFullHwStopOfControllerConfig(Index)                  (Can_GetControllerConfigOfPCConfig()[(Index)].RxFullHwStopOfControllerConfig)
#define Can_GetTxBasicHandleMaxOfControllerConfig(Index)              (Can_GetControllerConfigOfPCConfig()[(Index)].TxBasicHandleMaxOfControllerConfig)
#define Can_GetTxBasicHandleStartOfControllerConfig(Index)            (Can_GetControllerConfigOfPCConfig()[(Index)].TxBasicHandleStartOfControllerConfig)
#define Can_GetTxBasicHandleStopOfControllerConfig(Index)             (Can_GetControllerConfigOfPCConfig()[(Index)].TxBasicHandleStopOfControllerConfig)
#define Can_GetTxBasicHwStartOfControllerConfig(Index)                (Can_GetControllerConfigOfPCConfig()[(Index)].TxBasicHwStartOfControllerConfig)
#define Can_GetTxBasicHwStopOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].TxBasicHwStopOfControllerConfig)
#define Can_GetTxFullHandleMaxOfControllerConfig(Index)               (Can_GetControllerConfigOfPCConfig()[(Index)].TxFullHandleMaxOfControllerConfig)
#define Can_GetTxFullHandleStartOfControllerConfig(Index)             (Can_GetControllerConfigOfPCConfig()[(Index)].TxFullHandleStartOfControllerConfig)
#define Can_GetTxFullHandleStopOfControllerConfig(Index)              (Can_GetControllerConfigOfPCConfig()[(Index)].TxFullHandleStopOfControllerConfig)
#define Can_GetTxFullHwStartOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].TxFullHwStartOfControllerConfig)
#define Can_GetTxFullHwStopOfControllerConfig(Index)                  (Can_GetControllerConfigOfPCConfig()[(Index)].TxFullHwStopOfControllerConfig)
#define Can_GetUnusedHandleMaxOfControllerConfig(Index)               (Can_GetControllerConfigOfPCConfig()[(Index)].UnusedHandleMaxOfControllerConfig)
#define Can_GetUnusedHandleStartOfControllerConfig(Index)             (Can_GetControllerConfigOfPCConfig()[(Index)].UnusedHandleStartOfControllerConfig)
#define Can_GetUnusedHandleStopOfControllerConfig(Index)              (Can_GetControllerConfigOfPCConfig()[(Index)].UnusedHandleStopOfControllerConfig)
#define Can_GetUnusedHwStartOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].UnusedHwStartOfControllerConfig)
#define Can_GetUnusedHwStopOfControllerConfig(Index)                  (Can_GetControllerConfigOfPCConfig()[(Index)].UnusedHwStopOfControllerConfig)
#define Can_GetGlobalInterruptPendingMask(Index)                      (Can_GetGlobalInterruptPendingMaskOfPCConfig()[(Index)])
#define Can_GetHalt(Index)                                            (Can_GetHaltOfPCConfig()[(Index)])
#define Can_GetInitBT(Index)                                          (Can_GetInitBTOfPCConfig()[(Index)])
#define Can_GetInitCodeH(Index)                                       (Can_GetInitCodeHOfPCConfig()[(Index)])
#define Can_GetInitCodeL(Index)                                       (Can_GetInitCodeLOfPCConfig()[(Index)])
#define Can_GetInitMaskH(Index)                                       (Can_GetInitMaskHOfPCConfig()[(Index)])
#define Can_GetInitMaskL(Index)                                       (Can_GetInitMaskLOfPCConfig()[(Index)])
#define Can_GetInitObjectBaudrate(Index)                              (Can_GetInitObjectBaudrateOfPCConfig()[(Index)])
#define Can_GetInitObjectStartIndex(Index)                            (Can_GetInitObjectStartIndexOfPCConfig()[(Index)])
#define Can_GetInitPortSel(Index)                                     (Can_GetInitPortSelOfPCConfig()[(Index)])
#define Can_IsIsBusOff(Index)                                         ((Can_GetIsBusOffOfPCConfig()[(Index)]) != FALSE)
#define Can_IsIsHardwareCanceled(Index)                               ((Can_GetIsHardwareCanceledOfPCConfig()[(Index)]) != FALSE)
#define Can_GetIsrOsId(Index)                                         (Can_GetIsrOsIdOfPCConfig()[(Index)])
#define Can_GetLastInitObject(Index)                                  (Can_GetLastInitObjectOfPCConfig()[(Index)])
#define Can_GetLogStatus(Index)                                       (Can_GetLogStatusOfPCConfig()[(Index)])
#define Can_GetLoopTimeout(Index)                                     (Can_GetLoopTimeoutOfPCConfig()[(Index)])
#define Can_GetDLC_FIFOOfMailbox(Index)                               (Can_GetMailboxOfPCConfig()[(Index)].DLC_FIFOOfMailbox)
#define Can_GetHwHandleOfMailbox(Index)                               (Can_GetMailboxOfPCConfig()[(Index)].HwHandleOfMailbox)
#define Can_GetIDValueOfMailbox(Index)                                (Can_GetMailboxOfPCConfig()[(Index)].IDValueOfMailbox)
#define Can_GetMailboxTypeOfMailbox(Index)                            (Can_GetMailboxOfPCConfig()[(Index)].MailboxTypeOfMailbox)
#define Can_GetMaxDataLenOfMailbox(Index)                             (Can_GetMailboxOfPCConfig()[(Index)].MaxDataLenOfMailbox)
#define Can_GetMsgControllerOfMailbox(Index)                          (Can_GetMailboxOfPCConfig()[(Index)].MsgControllerOfMailbox)
#define Can_GetNodeAdr(Index)                                         (Can_GetNodeAdrOfPCConfig()[(Index)])
#define Can_GetNodeNum(Index)                                         (Can_GetNodeNumOfPCConfig()[(Index)])
#define Can_GetPhysPrio(Index)                                        (Can_GetPhysPrioOfPCConfig()[(Index)])
#define Can_GetRxBasicInterruptPendingMask(Index)                     (Can_GetRxBasicInterruptPendingMaskOfPCConfig()[(Index)])
#define Can_GetRxFullInterruptPendingMask(Index)                      (Can_GetRxFullInterruptPendingMaskOfPCConfig()[(Index)])
#define Can_GetSrcNum(Index)                                          (Can_GetSrcNumOfPCConfig()[(Index)])
#define Can_GetStatusReq(Index)                                       (Can_GetStatusReqOfPCConfig()[(Index)])
#define Can_GetTmpRxMsgMailbox(Index)                                 (Can_GetTmpRxMsgMailboxOfPCConfig()[(Index)])
#define Can_GetTxInterruptPendingMask(Index)                          (Can_GetTxInterruptPendingMaskOfPCConfig()[(Index)])
#define Can_GetTxOffsetHwToLog(Index)                                 (Can_GetTxOffsetHwToLogOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CanPCGetDeduplicatedDataMacros  Can Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Can_GetBaseDll_GeneratorVersion()                             Can_GetBaseDll_GeneratorVersionOfPCConfig()
#define Can_GetPlatformDll_GeneratorVersion()                         Can_GetPlatformDll_GeneratorVersionOfPCConfig()
#define Can_GetSizeOfActiveSendPdu()                                  Can_GetSizeOfActiveSendPduOfPCConfig()
#define Can_GetSizeOfActiveSendState()                                Can_GetSizeOfActiveSendStateOfPCConfig()
#define Can_GetSizeOfBusOffNotified()                                 Can_GetSizeOfBusOffNotifiedOfPCConfig()
#define Can_GetSizeOfCanIfChannelId()                                 Can_GetSizeOfCanIfChannelIdOfPCConfig()
#define Can_GetSizeOfCanInterruptCounter()                            Can_GetSizeOfCanInterruptCounterOfPCConfig()
#define Can_GetSizeOfCanInterruptOldStatus()                          Can_GetSizeOfCanInterruptOldStatusOfPCConfig()
#define Can_GetSizeOfControllerConfig()                               Can_GetSizeOfControllerConfigOfPCConfig()
#define Can_GetSizeOfGlobalInterruptPendingMask()                     Can_GetSizeOfGlobalInterruptPendingMaskOfPCConfig()
#define Can_GetSizeOfHalt()                                           Can_GetSizeOfHaltOfPCConfig()
#define Can_GetSizeOfInitBT()                                         Can_GetSizeOfInitBTOfPCConfig()
#define Can_GetSizeOfInitCodeH()                                      Can_GetSizeOfInitCodeHOfPCConfig()
#define Can_GetSizeOfInitCodeL()                                      Can_GetSizeOfInitCodeLOfPCConfig()
#define Can_GetSizeOfInitMaskH()                                      Can_GetSizeOfInitMaskHOfPCConfig()
#define Can_GetSizeOfInitMaskL()                                      Can_GetSizeOfInitMaskLOfPCConfig()
#define Can_GetSizeOfInitObjectBaudrate()                             Can_GetSizeOfInitObjectBaudrateOfPCConfig()
#define Can_GetSizeOfInitObjectStartIndex()                           Can_GetSizeOfInitObjectStartIndexOfPCConfig()
#define Can_GetSizeOfInitPortSel()                                    Can_GetSizeOfInitPortSelOfPCConfig()
#define Can_GetSizeOfIsBusOff()                                       Can_GetSizeOfIsBusOffOfPCConfig()
#define Can_GetSizeOfIsHardwareCanceled()                             Can_GetSizeOfIsHardwareCanceledOfPCConfig()
#define Can_GetSizeOfIsrOsId()                                        Can_GetSizeOfIsrOsIdOfPCConfig()
#define Can_GetSizeOfLastInitObject()                                 Can_GetSizeOfLastInitObjectOfPCConfig()
#define Can_GetSizeOfLogStatus()                                      Can_GetSizeOfLogStatusOfPCConfig()
#define Can_GetSizeOfLoopTimeout()                                    Can_GetSizeOfLoopTimeoutOfPCConfig()
#define Can_GetSizeOfMailbox()                                        Can_GetSizeOfMailboxOfPCConfig()
#define Can_GetSizeOfNodeAdr()                                        Can_GetSizeOfNodeAdrOfPCConfig()
#define Can_GetSizeOfNodeNum()                                        Can_GetSizeOfNodeNumOfPCConfig()
#define Can_GetSizeOfPhysPrio()                                       Can_GetSizeOfPhysPrioOfPCConfig()
#define Can_GetSizeOfRxBasicInterruptPendingMask()                    Can_GetSizeOfRxBasicInterruptPendingMaskOfPCConfig()
#define Can_GetSizeOfRxFullInterruptPendingMask()                     Can_GetSizeOfRxFullInterruptPendingMaskOfPCConfig()
#define Can_GetSizeOfSrcNum()                                         Can_GetSizeOfSrcNumOfPCConfig()
#define Can_GetSizeOfStatusReq()                                      Can_GetSizeOfStatusReqOfPCConfig()
#define Can_GetSizeOfTmpRxMsgMailbox()                                Can_GetSizeOfTmpRxMsgMailboxOfPCConfig()
#define Can_GetSizeOfTxInterruptPendingMask()                         Can_GetSizeOfTxInterruptPendingMaskOfPCConfig()
#define Can_GetSizeOfTxOffsetHwToLog()                                Can_GetSizeOfTxOffsetHwToLogOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  CanPCSetDataMacros  Can Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Can_SetActiveSendPdu(Index, Value)                            Can_GetActiveSendPduOfPCConfig()[(Index)] = (Value)
#define Can_SetActiveSendState(Index, Value)                          Can_GetActiveSendStateOfPCConfig()[(Index)] = (Value)
#define Can_SetBusOffNotified(Index, Value)                           Can_GetBusOffNotifiedOfPCConfig()[(Index)] = (Value)
#define Can_SetCanInterruptCounter(Index, Value)                      Can_GetCanInterruptCounterOfPCConfig()[(Index)] = (Value)
#define Can_SetCanInterruptOldStatus(Index, Value)                    Can_GetCanInterruptOldStatusOfPCConfig()[(Index)] = (Value)
#define Can_SetHalt(Index, Value)                                     Can_GetHaltOfPCConfig()[(Index)] = (Value)
#define Can_SetIsBusOff(Index, Value)                                 Can_GetIsBusOffOfPCConfig()[(Index)] = (Value)
#define Can_SetIsHardwareCanceled(Index, Value)                       Can_GetIsHardwareCanceledOfPCConfig()[(Index)] = (Value)
#define Can_SetLastInitObject(Index, Value)                           Can_GetLastInitObjectOfPCConfig()[(Index)] = (Value)
#define Can_SetLogStatus(Index, Value)                                Can_GetLogStatusOfPCConfig()[(Index)] = (Value)
#define Can_SetLoopTimeout(Index, Value)                              Can_GetLoopTimeoutOfPCConfig()[(Index)] = (Value)
#define Can_SetStatusReq(Index, Value)                                Can_GetStatusReqOfPCConfig()[(Index)] = (Value)
#define Can_SetTmpRxMsgMailbox(Index, Value)                          Can_GetTmpRxMsgMailboxOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanPCHasMacros  Can Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Can_HasActiveSendPdu()                                        (TRUE != FALSE)
#define Can_HasActiveSendState()                                      (TRUE != FALSE)
#define Can_HasBaseDll_GeneratorVersion()                             (TRUE != FALSE)
#define Can_HasBusOffNotified()                                       (TRUE != FALSE)
#define Can_HasCanIfChannelId()                                       (TRUE != FALSE)
#define Can_HasCanInterruptCounter()                                  (TRUE != FALSE)
#define Can_HasCanInterruptOldStatus()                                (TRUE != FALSE)
#define Can_HasControllerConfig()                                     (TRUE != FALSE)
#define Can_HasCanControllerDefaultBaudrateOfControllerConfig()       (TRUE != FALSE)
#define Can_HasRxBasicHandleMaxOfControllerConfig()                   (TRUE != FALSE)
#define Can_HasRxBasicHandleStartOfControllerConfig()                 (TRUE != FALSE)
#define Can_HasRxBasicHandleStopOfControllerConfig()                  (TRUE != FALSE)
#define Can_HasRxBasicHwStartOfControllerConfig()                     (TRUE != FALSE)
#define Can_HasRxBasicHwStopOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasRxFullHandleMaxOfControllerConfig()                    (TRUE != FALSE)
#define Can_HasRxFullHandleStartOfControllerConfig()                  (TRUE != FALSE)
#define Can_HasRxFullHandleStopOfControllerConfig()                   (TRUE != FALSE)
#define Can_HasRxFullHwStartOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasRxFullHwStopOfControllerConfig()                       (TRUE != FALSE)
#define Can_HasTxBasicHandleMaxOfControllerConfig()                   (TRUE != FALSE)
#define Can_HasTxBasicHandleStartOfControllerConfig()                 (TRUE != FALSE)
#define Can_HasTxBasicHandleStopOfControllerConfig()                  (TRUE != FALSE)
#define Can_HasTxBasicHwStartOfControllerConfig()                     (TRUE != FALSE)
#define Can_HasTxBasicHwStopOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasTxFullHandleMaxOfControllerConfig()                    (TRUE != FALSE)
#define Can_HasTxFullHandleStartOfControllerConfig()                  (TRUE != FALSE)
#define Can_HasTxFullHandleStopOfControllerConfig()                   (TRUE != FALSE)
#define Can_HasTxFullHwStartOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasTxFullHwStopOfControllerConfig()                       (TRUE != FALSE)
#define Can_HasUnusedHandleMaxOfControllerConfig()                    (TRUE != FALSE)
#define Can_HasUnusedHandleStartOfControllerConfig()                  (TRUE != FALSE)
#define Can_HasUnusedHandleStopOfControllerConfig()                   (TRUE != FALSE)
#define Can_HasUnusedHwStartOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasUnusedHwStopOfControllerConfig()                       (TRUE != FALSE)
#define Can_HasGlobalInterruptPendingMask()                           (TRUE != FALSE)
#define Can_HasHalt()                                                 (TRUE != FALSE)
#define Can_HasInitBT()                                               (TRUE != FALSE)
#define Can_HasInitCodeH()                                            (TRUE != FALSE)
#define Can_HasInitCodeL()                                            (TRUE != FALSE)
#define Can_HasInitMaskH()                                            (TRUE != FALSE)
#define Can_HasInitMaskL()                                            (TRUE != FALSE)
#define Can_HasInitObjectBaudrate()                                   (TRUE != FALSE)
#define Can_HasInitObjectStartIndex()                                 (TRUE != FALSE)
#define Can_HasInitPortSel()                                          (TRUE != FALSE)
#define Can_HasIsBusOff()                                             (TRUE != FALSE)
#define Can_HasIsHardwareCanceled()                                   (TRUE != FALSE)
#define Can_HasIsrOsId()                                              (TRUE != FALSE)
#define Can_HasLastInitObject()                                       (TRUE != FALSE)
#define Can_HasLogStatus()                                            (TRUE != FALSE)
#define Can_HasLoopTimeout()                                          (TRUE != FALSE)
#define Can_HasMailbox()                                              (TRUE != FALSE)
#define Can_HasDLC_FIFOOfMailbox()                                    (TRUE != FALSE)
#define Can_HasHwHandleOfMailbox()                                    (TRUE != FALSE)
#define Can_HasIDValueOfMailbox()                                     (TRUE != FALSE)
#define Can_HasMailboxTypeOfMailbox()                                 (TRUE != FALSE)
#define Can_HasMaxDataLenOfMailbox()                                  (TRUE != FALSE)
#define Can_HasMsgControllerOfMailbox()                               (TRUE != FALSE)
#define Can_HasNodeAdr()                                              (TRUE != FALSE)
#define Can_HasNodeNum()                                              (TRUE != FALSE)
#define Can_HasPhysPrio()                                             (TRUE != FALSE)
#define Can_HasPlatformDll_GeneratorVersion()                         (TRUE != FALSE)
#define Can_HasRxBasicInterruptPendingMask()                          (TRUE != FALSE)
#define Can_HasRxFullInterruptPendingMask()                           (TRUE != FALSE)
#define Can_HasSizeOfActiveSendPdu()                                  (TRUE != FALSE)
#define Can_HasSizeOfActiveSendState()                                (TRUE != FALSE)
#define Can_HasSizeOfBusOffNotified()                                 (TRUE != FALSE)
#define Can_HasSizeOfCanIfChannelId()                                 (TRUE != FALSE)
#define Can_HasSizeOfCanInterruptCounter()                            (TRUE != FALSE)
#define Can_HasSizeOfCanInterruptOldStatus()                          (TRUE != FALSE)
#define Can_HasSizeOfControllerConfig()                               (TRUE != FALSE)
#define Can_HasSizeOfGlobalInterruptPendingMask()                     (TRUE != FALSE)
#define Can_HasSizeOfHalt()                                           (TRUE != FALSE)
#define Can_HasSizeOfInitBT()                                         (TRUE != FALSE)
#define Can_HasSizeOfInitCodeH()                                      (TRUE != FALSE)
#define Can_HasSizeOfInitCodeL()                                      (TRUE != FALSE)
#define Can_HasSizeOfInitMaskH()                                      (TRUE != FALSE)
#define Can_HasSizeOfInitMaskL()                                      (TRUE != FALSE)
#define Can_HasSizeOfInitObjectBaudrate()                             (TRUE != FALSE)
#define Can_HasSizeOfInitObjectStartIndex()                           (TRUE != FALSE)
#define Can_HasSizeOfInitPortSel()                                    (TRUE != FALSE)
#define Can_HasSizeOfIsBusOff()                                       (TRUE != FALSE)
#define Can_HasSizeOfIsHardwareCanceled()                             (TRUE != FALSE)
#define Can_HasSizeOfIsrOsId()                                        (TRUE != FALSE)
#define Can_HasSizeOfLastInitObject()                                 (TRUE != FALSE)
#define Can_HasSizeOfLogStatus()                                      (TRUE != FALSE)
#define Can_HasSizeOfLoopTimeout()                                    (TRUE != FALSE)
#define Can_HasSizeOfMailbox()                                        (TRUE != FALSE)
#define Can_HasSizeOfNodeAdr()                                        (TRUE != FALSE)
#define Can_HasSizeOfNodeNum()                                        (TRUE != FALSE)
#define Can_HasSizeOfPhysPrio()                                       (TRUE != FALSE)
#define Can_HasSizeOfRxBasicInterruptPendingMask()                    (TRUE != FALSE)
#define Can_HasSizeOfRxFullInterruptPendingMask()                     (TRUE != FALSE)
#define Can_HasSizeOfSrcNum()                                         (TRUE != FALSE)
#define Can_HasSizeOfStatusReq()                                      (TRUE != FALSE)
#define Can_HasSizeOfTmpRxMsgMailbox()                                (TRUE != FALSE)
#define Can_HasSizeOfTxInterruptPendingMask()                         (TRUE != FALSE)
#define Can_HasSizeOfTxOffsetHwToLog()                                (TRUE != FALSE)
#define Can_HasSrcNum()                                               (TRUE != FALSE)
#define Can_HasStatusReq()                                            (TRUE != FALSE)
#define Can_HasTmpRxMsgMailbox()                                      (TRUE != FALSE)
#define Can_HasTxInterruptPendingMask()                               (TRUE != FALSE)
#define Can_HasTxOffsetHwToLog()                                      (TRUE != FALSE)
#define Can_HasPCConfig()                                             (TRUE != FALSE)
#define Can_HasActiveSendPduOfPCConfig()                              (TRUE != FALSE)
#define Can_HasActiveSendStateOfPCConfig()                            (TRUE != FALSE)
#define Can_HasBaseDll_GeneratorVersionOfPCConfig()                   (TRUE != FALSE)
#define Can_HasBusOffNotifiedOfPCConfig()                             (TRUE != FALSE)
#define Can_HasCanIfChannelIdOfPCConfig()                             (TRUE != FALSE)
#define Can_HasCanInterruptCounterOfPCConfig()                        (TRUE != FALSE)
#define Can_HasCanInterruptOldStatusOfPCConfig()                      (TRUE != FALSE)
#define Can_HasControllerConfigOfPCConfig()                           (TRUE != FALSE)
#define Can_HasGlobalInterruptPendingMaskOfPCConfig()                 (TRUE != FALSE)
#define Can_HasHaltOfPCConfig()                                       (TRUE != FALSE)
#define Can_HasInitBTOfPCConfig()                                     (TRUE != FALSE)
#define Can_HasInitCodeHOfPCConfig()                                  (TRUE != FALSE)
#define Can_HasInitCodeLOfPCConfig()                                  (TRUE != FALSE)
#define Can_HasInitMaskHOfPCConfig()                                  (TRUE != FALSE)
#define Can_HasInitMaskLOfPCConfig()                                  (TRUE != FALSE)
#define Can_HasInitObjectBaudrateOfPCConfig()                         (TRUE != FALSE)
#define Can_HasInitObjectStartIndexOfPCConfig()                       (TRUE != FALSE)
#define Can_HasInitPortSelOfPCConfig()                                (TRUE != FALSE)
#define Can_HasIsBusOffOfPCConfig()                                   (TRUE != FALSE)
#define Can_HasIsHardwareCanceledOfPCConfig()                         (TRUE != FALSE)
#define Can_HasIsrOsIdOfPCConfig()                                    (TRUE != FALSE)
#define Can_HasLastInitObjectOfPCConfig()                             (TRUE != FALSE)
#define Can_HasLogStatusOfPCConfig()                                  (TRUE != FALSE)
#define Can_HasLoopTimeoutOfPCConfig()                                (TRUE != FALSE)
#define Can_HasMailboxOfPCConfig()                                    (TRUE != FALSE)
#define Can_HasNodeAdrOfPCConfig()                                    (TRUE != FALSE)
#define Can_HasNodeNumOfPCConfig()                                    (TRUE != FALSE)
#define Can_HasPhysPrioOfPCConfig()                                   (TRUE != FALSE)
#define Can_HasPlatformDll_GeneratorVersionOfPCConfig()               (TRUE != FALSE)
#define Can_HasRxBasicInterruptPendingMaskOfPCConfig()                (TRUE != FALSE)
#define Can_HasRxFullInterruptPendingMaskOfPCConfig()                 (TRUE != FALSE)
#define Can_HasSizeOfActiveSendPduOfPCConfig()                        (TRUE != FALSE)
#define Can_HasSizeOfActiveSendStateOfPCConfig()                      (TRUE != FALSE)
#define Can_HasSizeOfBusOffNotifiedOfPCConfig()                       (TRUE != FALSE)
#define Can_HasSizeOfCanIfChannelIdOfPCConfig()                       (TRUE != FALSE)
#define Can_HasSizeOfCanInterruptCounterOfPCConfig()                  (TRUE != FALSE)
#define Can_HasSizeOfCanInterruptOldStatusOfPCConfig()                (TRUE != FALSE)
#define Can_HasSizeOfControllerConfigOfPCConfig()                     (TRUE != FALSE)
#define Can_HasSizeOfGlobalInterruptPendingMaskOfPCConfig()           (TRUE != FALSE)
#define Can_HasSizeOfHaltOfPCConfig()                                 (TRUE != FALSE)
#define Can_HasSizeOfInitBTOfPCConfig()                               (TRUE != FALSE)
#define Can_HasSizeOfInitCodeHOfPCConfig()                            (TRUE != FALSE)
#define Can_HasSizeOfInitCodeLOfPCConfig()                            (TRUE != FALSE)
#define Can_HasSizeOfInitMaskHOfPCConfig()                            (TRUE != FALSE)
#define Can_HasSizeOfInitMaskLOfPCConfig()                            (TRUE != FALSE)
#define Can_HasSizeOfInitObjectBaudrateOfPCConfig()                   (TRUE != FALSE)
#define Can_HasSizeOfInitObjectStartIndexOfPCConfig()                 (TRUE != FALSE)
#define Can_HasSizeOfInitPortSelOfPCConfig()                          (TRUE != FALSE)
#define Can_HasSizeOfIsBusOffOfPCConfig()                             (TRUE != FALSE)
#define Can_HasSizeOfIsHardwareCanceledOfPCConfig()                   (TRUE != FALSE)
#define Can_HasSizeOfIsrOsIdOfPCConfig()                              (TRUE != FALSE)
#define Can_HasSizeOfLastInitObjectOfPCConfig()                       (TRUE != FALSE)
#define Can_HasSizeOfLogStatusOfPCConfig()                            (TRUE != FALSE)
#define Can_HasSizeOfLoopTimeoutOfPCConfig()                          (TRUE != FALSE)
#define Can_HasSizeOfMailboxOfPCConfig()                              (TRUE != FALSE)
#define Can_HasSizeOfNodeAdrOfPCConfig()                              (TRUE != FALSE)
#define Can_HasSizeOfNodeNumOfPCConfig()                              (TRUE != FALSE)
#define Can_HasSizeOfPhysPrioOfPCConfig()                             (TRUE != FALSE)
#define Can_HasSizeOfRxBasicInterruptPendingMaskOfPCConfig()          (TRUE != FALSE)
#define Can_HasSizeOfRxFullInterruptPendingMaskOfPCConfig()           (TRUE != FALSE)
#define Can_HasSizeOfSrcNumOfPCConfig()                               (TRUE != FALSE)
#define Can_HasSizeOfStatusReqOfPCConfig()                            (TRUE != FALSE)
#define Can_HasSizeOfTmpRxMsgMailboxOfPCConfig()                      (TRUE != FALSE)
#define Can_HasSizeOfTxInterruptPendingMaskOfPCConfig()               (TRUE != FALSE)
#define Can_HasSizeOfTxOffsetHwToLogOfPCConfig()                      (TRUE != FALSE)
#define Can_HasSrcNumOfPCConfig()                                     (TRUE != FALSE)
#define Can_HasStatusReqOfPCConfig()                                  (TRUE != FALSE)
#define Can_HasTmpRxMsgMailboxOfPCConfig()                            (TRUE != FALSE)
#define Can_HasTxInterruptPendingMaskOfPCConfig()                     (TRUE != FALSE)
#define Can_HasTxOffsetHwToLogOfPCConfig()                            (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanPCIncrementDataMacros  Can Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Can_IncActiveSendPdu(Index)                                   Can_GetActiveSendPdu(Index)++
#define Can_IncActiveSendState(Index)                                 Can_GetActiveSendState(Index)++
#define Can_IncBusOffNotified(Index)                                  Can_GetBusOffNotified(Index)++
#define Can_IncCanInterruptCounter(Index)                             Can_GetCanInterruptCounter(Index)++
#define Can_IncCanInterruptOldStatus(Index)                           Can_GetCanInterruptOldStatus(Index)++
#define Can_IncHalt(Index)                                            Can_GetHalt(Index)++
#define Can_IncLastInitObject(Index)                                  Can_GetLastInitObject(Index)++
#define Can_IncLogStatus(Index)                                       Can_GetLogStatus(Index)++
#define Can_IncLoopTimeout(Index)                                     Can_GetLoopTimeout(Index)++
#define Can_IncStatusReq(Index)                                       Can_GetStatusReq(Index)++
#define Can_IncTmpRxMsgMailbox(Index)                                 Can_GetTmpRxMsgMailbox(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanPCDecrementDataMacros  Can Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Can_DecActiveSendPdu(Index)                                   Can_GetActiveSendPdu(Index)--
#define Can_DecActiveSendState(Index)                                 Can_GetActiveSendState(Index)--
#define Can_DecBusOffNotified(Index)                                  Can_GetBusOffNotified(Index)--
#define Can_DecCanInterruptCounter(Index)                             Can_GetCanInterruptCounter(Index)--
#define Can_DecCanInterruptOldStatus(Index)                           Can_GetCanInterruptOldStatus(Index)--
#define Can_DecHalt(Index)                                            Can_GetHalt(Index)--
#define Can_DecLastInitObject(Index)                                  Can_GetLastInitObject(Index)--
#define Can_DecLogStatus(Index)                                       Can_GetLogStatus(Index)--
#define Can_DecLoopTimeout(Index)                                     Can_GetLoopTimeout(Index)--
#define Can_DecStatusReq(Index)                                       Can_GetStatusReq(Index)--
#define Can_DecTmpRxMsgMailbox(Index)                                 Can_GetTmpRxMsgMailbox(Index)--
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanPCIterableTypes  Can Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Can_ActiveSendPdu */
typedef uint8_least Can_ActiveSendPduIterType;

/**   \brief  type used to iterate Can_ActiveSendState */
typedef uint8_least Can_ActiveSendStateIterType;

/**   \brief  type used to iterate Can_BusOffNotified */
typedef uint8_least Can_BusOffNotifiedIterType;

/**   \brief  type used to iterate Can_CanIfChannelId */
typedef uint8_least Can_CanIfChannelIdIterType;

/**   \brief  type used to iterate Can_CanInterruptCounter */
typedef uint8_least Can_CanInterruptCounterIterType;

/**   \brief  type used to iterate Can_CanInterruptOldStatus */
typedef uint8_least Can_CanInterruptOldStatusIterType;

/**   \brief  type used to iterate Can_ControllerConfig */
typedef uint8_least Can_ControllerConfigIterType;

/**   \brief  type used to iterate Can_GlobalInterruptPendingMask */
typedef uint8_least Can_GlobalInterruptPendingMaskIterType;

/**   \brief  type used to iterate Can_Halt */
typedef uint8_least Can_HaltIterType;

/**   \brief  type used to iterate Can_InitBT */
typedef uint8_least Can_InitBTIterType;

/**   \brief  type used to iterate Can_InitCodeH */
typedef uint8_least Can_InitCodeHIterType;

/**   \brief  type used to iterate Can_InitCodeL */
typedef uint8_least Can_InitCodeLIterType;

/**   \brief  type used to iterate Can_InitMaskH */
typedef uint8_least Can_InitMaskHIterType;

/**   \brief  type used to iterate Can_InitMaskL */
typedef uint8_least Can_InitMaskLIterType;

/**   \brief  type used to iterate Can_InitObjectBaudrate */
typedef uint8_least Can_InitObjectBaudrateIterType;

/**   \brief  type used to iterate Can_InitObjectStartIndex */
typedef uint8_least Can_InitObjectStartIndexIterType;

/**   \brief  type used to iterate Can_InitPortSel */
typedef uint8_least Can_InitPortSelIterType;

/**   \brief  type used to iterate Can_IsBusOff */
typedef uint8_least Can_IsBusOffIterType;

/**   \brief  type used to iterate Can_IsHardwareCanceled */
typedef uint8_least Can_IsHardwareCanceledIterType;

/**   \brief  type used to iterate Can_IsrOsId */
typedef uint8_least Can_IsrOsIdIterType;

/**   \brief  type used to iterate Can_LastInitObject */
typedef uint8_least Can_LastInitObjectIterType;

/**   \brief  type used to iterate Can_LogStatus */
typedef uint8_least Can_LogStatusIterType;

/**   \brief  type used to iterate Can_LoopTimeout */
typedef uint8_least Can_LoopTimeoutIterType;

/**   \brief  type used to iterate Can_Mailbox */
typedef uint8_least Can_MailboxIterType;

/**   \brief  type used to iterate Can_NodeAdr */
typedef uint8_least Can_NodeAdrIterType;

/**   \brief  type used to iterate Can_NodeNum */
typedef uint8_least Can_NodeNumIterType;

/**   \brief  type used to iterate Can_PhysPrio */
typedef uint8_least Can_PhysPrioIterType;

/**   \brief  type used to iterate Can_RxBasicInterruptPendingMask */
typedef uint8_least Can_RxBasicInterruptPendingMaskIterType;

/**   \brief  type used to iterate Can_RxFullInterruptPendingMask */
typedef uint8_least Can_RxFullInterruptPendingMaskIterType;

/**   \brief  type used to iterate Can_SrcNum */
typedef uint8_least Can_SrcNumIterType;

/**   \brief  type used to iterate Can_StatusReq */
typedef uint8_least Can_StatusReqIterType;

/**   \brief  type used to iterate Can_TmpRxMsgMailbox */
typedef uint8_least Can_TmpRxMsgMailboxIterType;

/**   \brief  type used to iterate Can_TxInterruptPendingMask */
typedef uint8_least Can_TxInterruptPendingMaskIterType;

/**   \brief  type used to iterate Can_TxOffsetHwToLog */
typedef uint8_least Can_TxOffsetHwToLogIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanPCValueTypes  Can Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Can_ActiveSendPdu */
typedef PduIdType Can_ActiveSendPduType;

/**   \brief  value based type definition for Can_ActiveSendState */
typedef uint8 Can_ActiveSendStateType;

/**   \brief  value based type definition for Can_BaseDll_GeneratorVersion */
typedef uint16 Can_BaseDll_GeneratorVersionType;

/**   \brief  value based type definition for Can_BusOffNotified */
typedef uint8 Can_BusOffNotifiedType;

/**   \brief  value based type definition for Can_CanIfChannelId */
typedef uint8 Can_CanIfChannelIdType;

/**   \brief  value based type definition for Can_CanInterruptCounter */
typedef uint8 Can_CanInterruptCounterType;

/**   \brief  value based type definition for Can_CanControllerDefaultBaudrateOfControllerConfig */
typedef uint16 Can_CanControllerDefaultBaudrateOfControllerConfigType;

/**   \brief  value based type definition for Can_RxBasicHandleMaxOfControllerConfig */
typedef uint8 Can_RxBasicHandleMaxOfControllerConfigType;

/**   \brief  value based type definition for Can_RxBasicHandleStartOfControllerConfig */
typedef uint8 Can_RxBasicHandleStartOfControllerConfigType;

/**   \brief  value based type definition for Can_RxBasicHandleStopOfControllerConfig */
typedef uint8 Can_RxBasicHandleStopOfControllerConfigType;

/**   \brief  value based type definition for Can_RxBasicHwStartOfControllerConfig */
typedef uint8 Can_RxBasicHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_RxBasicHwStopOfControllerConfig */
typedef uint8 Can_RxBasicHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_RxFullHandleMaxOfControllerConfig */
typedef uint8 Can_RxFullHandleMaxOfControllerConfigType;

/**   \brief  value based type definition for Can_RxFullHandleStartOfControllerConfig */
typedef uint8 Can_RxFullHandleStartOfControllerConfigType;

/**   \brief  value based type definition for Can_RxFullHandleStopOfControllerConfig */
typedef uint8 Can_RxFullHandleStopOfControllerConfigType;

/**   \brief  value based type definition for Can_RxFullHwStartOfControllerConfig */
typedef uint8 Can_RxFullHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_RxFullHwStopOfControllerConfig */
typedef uint8 Can_RxFullHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_TxBasicHandleMaxOfControllerConfig */
typedef uint8 Can_TxBasicHandleMaxOfControllerConfigType;

/**   \brief  value based type definition for Can_TxBasicHandleStartOfControllerConfig */
typedef uint8 Can_TxBasicHandleStartOfControllerConfigType;

/**   \brief  value based type definition for Can_TxBasicHandleStopOfControllerConfig */
typedef uint8 Can_TxBasicHandleStopOfControllerConfigType;

/**   \brief  value based type definition for Can_TxBasicHwStartOfControllerConfig */
typedef uint8 Can_TxBasicHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_TxBasicHwStopOfControllerConfig */
typedef uint8 Can_TxBasicHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_TxFullHandleMaxOfControllerConfig */
typedef uint8 Can_TxFullHandleMaxOfControllerConfigType;

/**   \brief  value based type definition for Can_TxFullHandleStartOfControllerConfig */
typedef uint8 Can_TxFullHandleStartOfControllerConfigType;

/**   \brief  value based type definition for Can_TxFullHandleStopOfControllerConfig */
typedef uint8 Can_TxFullHandleStopOfControllerConfigType;

/**   \brief  value based type definition for Can_TxFullHwStartOfControllerConfig */
typedef uint8 Can_TxFullHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_TxFullHwStopOfControllerConfig */
typedef uint8 Can_TxFullHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_UnusedHandleMaxOfControllerConfig */
typedef uint8 Can_UnusedHandleMaxOfControllerConfigType;

/**   \brief  value based type definition for Can_UnusedHandleStartOfControllerConfig */
typedef uint8 Can_UnusedHandleStartOfControllerConfigType;

/**   \brief  value based type definition for Can_UnusedHandleStopOfControllerConfig */
typedef uint8 Can_UnusedHandleStopOfControllerConfigType;

/**   \brief  value based type definition for Can_UnusedHwStartOfControllerConfig */
typedef uint8 Can_UnusedHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_UnusedHwStopOfControllerConfig */
typedef uint8 Can_UnusedHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_GlobalInterruptPendingMask */
typedef uint32 Can_GlobalInterruptPendingMaskType;

/**   \brief  value based type definition for Can_Halt */
typedef uint8 Can_HaltType;

/**   \brief  value based type definition for Can_InitBT */
typedef uint16 Can_InitBTType;

/**   \brief  value based type definition for Can_InitCodeH */
typedef uint16 Can_InitCodeHType;

/**   \brief  value based type definition for Can_InitCodeL */
typedef uint16 Can_InitCodeLType;

/**   \brief  value based type definition for Can_InitMaskH */
typedef uint16 Can_InitMaskHType;

/**   \brief  value based type definition for Can_InitMaskL */
typedef uint16 Can_InitMaskLType;

/**   \brief  value based type definition for Can_InitObjectBaudrate */
typedef uint16 Can_InitObjectBaudrateType;

/**   \brief  value based type definition for Can_InitObjectStartIndex */
typedef uint8 Can_InitObjectStartIndexType;

/**   \brief  value based type definition for Can_InitPortSel */
typedef uint8 Can_InitPortSelType;

/**   \brief  value based type definition for Can_IsBusOff */
typedef boolean Can_IsBusOffType;

/**   \brief  value based type definition for Can_IsHardwareCanceled */
typedef boolean Can_IsHardwareCanceledType;

/**   \brief  value based type definition for Can_IsrOsId */
typedef uint32 Can_IsrOsIdType;

/**   \brief  value based type definition for Can_LastInitObject */
typedef uint8 Can_LastInitObjectType;

/**   \brief  value based type definition for Can_LogStatus */
typedef uint8 Can_LogStatusType;

/**   \brief  value based type definition for Can_DLC_FIFOOfMailbox */
typedef uint8 Can_DLC_FIFOOfMailboxType;

/**   \brief  value based type definition for Can_HwHandleOfMailbox */
typedef uint8 Can_HwHandleOfMailboxType;

/**   \brief  value based type definition for Can_IDValueOfMailbox */
typedef uint16 Can_IDValueOfMailboxType;

/**   \brief  value based type definition for Can_MailboxTypeOfMailbox */
typedef uint8 Can_MailboxTypeOfMailboxType;

/**   \brief  value based type definition for Can_MaxDataLenOfMailbox */
typedef uint8 Can_MaxDataLenOfMailboxType;

/**   \brief  value based type definition for Can_MsgControllerOfMailbox */
typedef uint8 Can_MsgControllerOfMailboxType;

/**   \brief  value based type definition for Can_NodeAdr */
typedef uint32 Can_NodeAdrType;

/**   \brief  value based type definition for Can_NodeNum */
typedef uint8 Can_NodeNumType;

/**   \brief  value based type definition for Can_PhysPrio */
typedef uint16 Can_PhysPrioType;

/**   \brief  value based type definition for Can_PlatformDll_GeneratorVersion */
typedef uint16 Can_PlatformDll_GeneratorVersionType;

/**   \brief  value based type definition for Can_RxBasicInterruptPendingMask */
typedef uint32 Can_RxBasicInterruptPendingMaskType;

/**   \brief  value based type definition for Can_RxFullInterruptPendingMask */
typedef uint32 Can_RxFullInterruptPendingMaskType;

/**   \brief  value based type definition for Can_SizeOfActiveSendPdu */
typedef uint16 Can_SizeOfActiveSendPduType;

/**   \brief  value based type definition for Can_SizeOfActiveSendState */
typedef uint16 Can_SizeOfActiveSendStateType;

/**   \brief  value based type definition for Can_SizeOfBusOffNotified */
typedef uint16 Can_SizeOfBusOffNotifiedType;

/**   \brief  value based type definition for Can_SizeOfCanIfChannelId */
typedef uint16 Can_SizeOfCanIfChannelIdType;

/**   \brief  value based type definition for Can_SizeOfCanInterruptCounter */
typedef uint16 Can_SizeOfCanInterruptCounterType;

/**   \brief  value based type definition for Can_SizeOfCanInterruptOldStatus */
typedef uint16 Can_SizeOfCanInterruptOldStatusType;

/**   \brief  value based type definition for Can_SizeOfControllerConfig */
typedef uint16 Can_SizeOfControllerConfigType;

/**   \brief  value based type definition for Can_SizeOfGlobalInterruptPendingMask */
typedef uint16 Can_SizeOfGlobalInterruptPendingMaskType;

/**   \brief  value based type definition for Can_SizeOfHalt */
typedef uint16 Can_SizeOfHaltType;

/**   \brief  value based type definition for Can_SizeOfInitBT */
typedef uint16 Can_SizeOfInitBTType;

/**   \brief  value based type definition for Can_SizeOfInitCodeH */
typedef uint16 Can_SizeOfInitCodeHType;

/**   \brief  value based type definition for Can_SizeOfInitCodeL */
typedef uint16 Can_SizeOfInitCodeLType;

/**   \brief  value based type definition for Can_SizeOfInitMaskH */
typedef uint16 Can_SizeOfInitMaskHType;

/**   \brief  value based type definition for Can_SizeOfInitMaskL */
typedef uint16 Can_SizeOfInitMaskLType;

/**   \brief  value based type definition for Can_SizeOfInitObjectBaudrate */
typedef uint16 Can_SizeOfInitObjectBaudrateType;

/**   \brief  value based type definition for Can_SizeOfInitObjectStartIndex */
typedef uint16 Can_SizeOfInitObjectStartIndexType;

/**   \brief  value based type definition for Can_SizeOfInitPortSel */
typedef uint16 Can_SizeOfInitPortSelType;

/**   \brief  value based type definition for Can_SizeOfIsBusOff */
typedef uint16 Can_SizeOfIsBusOffType;

/**   \brief  value based type definition for Can_SizeOfIsHardwareCanceled */
typedef uint16 Can_SizeOfIsHardwareCanceledType;

/**   \brief  value based type definition for Can_SizeOfIsrOsId */
typedef uint16 Can_SizeOfIsrOsIdType;

/**   \brief  value based type definition for Can_SizeOfLastInitObject */
typedef uint16 Can_SizeOfLastInitObjectType;

/**   \brief  value based type definition for Can_SizeOfLogStatus */
typedef uint16 Can_SizeOfLogStatusType;

/**   \brief  value based type definition for Can_SizeOfLoopTimeout */
typedef uint16 Can_SizeOfLoopTimeoutType;

/**   \brief  value based type definition for Can_SizeOfMailbox */
typedef uint16 Can_SizeOfMailboxType;

/**   \brief  value based type definition for Can_SizeOfNodeAdr */
typedef uint16 Can_SizeOfNodeAdrType;

/**   \brief  value based type definition for Can_SizeOfNodeNum */
typedef uint16 Can_SizeOfNodeNumType;

/**   \brief  value based type definition for Can_SizeOfPhysPrio */
typedef uint16 Can_SizeOfPhysPrioType;

/**   \brief  value based type definition for Can_SizeOfRxBasicInterruptPendingMask */
typedef uint16 Can_SizeOfRxBasicInterruptPendingMaskType;

/**   \brief  value based type definition for Can_SizeOfRxFullInterruptPendingMask */
typedef uint16 Can_SizeOfRxFullInterruptPendingMaskType;

/**   \brief  value based type definition for Can_SizeOfSrcNum */
typedef uint16 Can_SizeOfSrcNumType;

/**   \brief  value based type definition for Can_SizeOfStatusReq */
typedef uint16 Can_SizeOfStatusReqType;

/**   \brief  value based type definition for Can_SizeOfTmpRxMsgMailbox */
typedef uint16 Can_SizeOfTmpRxMsgMailboxType;

/**   \brief  value based type definition for Can_SizeOfTxInterruptPendingMask */
typedef uint16 Can_SizeOfTxInterruptPendingMaskType;

/**   \brief  value based type definition for Can_SizeOfTxOffsetHwToLog */
typedef uint16 Can_SizeOfTxOffsetHwToLogType;

/**   \brief  value based type definition for Can_SrcNum */
typedef uint8 Can_SrcNumType;

/**   \brief  value based type definition for Can_StatusReq */
typedef uint8 Can_StatusReqType;

/**   \brief  value based type definition for Can_TxInterruptPendingMask */
typedef uint32 Can_TxInterruptPendingMaskType;

/**   \brief  value based type definition for Can_TxOffsetHwToLog */
typedef sint16 Can_TxOffsetHwToLogType;

/** 
  \}
*/ 

/** 
  \defgroup  CanPCStructTypes  Can Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Can_ControllerConfig */
typedef struct sCan_ControllerConfigType
{
  Can_CanControllerDefaultBaudrateOfControllerConfigType CanControllerDefaultBaudrateOfControllerConfig;
  Can_RxBasicHandleMaxOfControllerConfigType RxBasicHandleMaxOfControllerConfig;
  Can_RxBasicHandleStartOfControllerConfigType RxBasicHandleStartOfControllerConfig;
  Can_RxBasicHandleStopOfControllerConfigType RxBasicHandleStopOfControllerConfig;
  Can_RxBasicHwStartOfControllerConfigType RxBasicHwStartOfControllerConfig;
  Can_RxBasicHwStopOfControllerConfigType RxBasicHwStopOfControllerConfig;
  Can_RxFullHandleMaxOfControllerConfigType RxFullHandleMaxOfControllerConfig;
  Can_RxFullHandleStartOfControllerConfigType RxFullHandleStartOfControllerConfig;
  Can_RxFullHandleStopOfControllerConfigType RxFullHandleStopOfControllerConfig;
  Can_RxFullHwStartOfControllerConfigType RxFullHwStartOfControllerConfig;
  Can_RxFullHwStopOfControllerConfigType RxFullHwStopOfControllerConfig;
  Can_TxBasicHandleMaxOfControllerConfigType TxBasicHandleMaxOfControllerConfig;
  Can_TxBasicHandleStartOfControllerConfigType TxBasicHandleStartOfControllerConfig;
  Can_TxBasicHandleStopOfControllerConfigType TxBasicHandleStopOfControllerConfig;
  Can_TxBasicHwStartOfControllerConfigType TxBasicHwStartOfControllerConfig;
  Can_TxBasicHwStopOfControllerConfigType TxBasicHwStopOfControllerConfig;
  Can_TxFullHandleMaxOfControllerConfigType TxFullHandleMaxOfControllerConfig;
  Can_TxFullHandleStartOfControllerConfigType TxFullHandleStartOfControllerConfig;
  Can_TxFullHandleStopOfControllerConfigType TxFullHandleStopOfControllerConfig;
  Can_TxFullHwStartOfControllerConfigType TxFullHwStartOfControllerConfig;
  Can_TxFullHwStopOfControllerConfigType TxFullHwStopOfControllerConfig;
  Can_UnusedHandleMaxOfControllerConfigType UnusedHandleMaxOfControllerConfig;
  Can_UnusedHandleStartOfControllerConfigType UnusedHandleStartOfControllerConfig;
  Can_UnusedHandleStopOfControllerConfigType UnusedHandleStopOfControllerConfig;
  Can_UnusedHwStartOfControllerConfigType UnusedHwStartOfControllerConfig;
  Can_UnusedHwStopOfControllerConfigType UnusedHwStopOfControllerConfig;
} Can_ControllerConfigType;

/**   \brief  type used in Can_Mailbox */
typedef struct sCan_MailboxType
{
  Can_IDValueOfMailboxType IDValueOfMailbox;
  Can_DLC_FIFOOfMailboxType DLC_FIFOOfMailbox;
  Can_HwHandleOfMailboxType HwHandleOfMailbox;
  Can_MailboxTypeOfMailboxType MailboxTypeOfMailbox;
  Can_MaxDataLenOfMailboxType MaxDataLenOfMailbox;
  Can_MsgControllerOfMailboxType MsgControllerOfMailbox;
} Can_MailboxType;

/** 
  \}
*/ 

/** 
  \defgroup  CanPCRootValueTypes  Can Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Can_PCConfig */
typedef struct sCan_PCConfigType
{
  uint8 Can_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Can_PCConfigType;

typedef Can_PCConfigType Can_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Can_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[3];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                         Description
  CanControllerDefaultBaudrate
  RxBasicHandleMax            
  RxBasicHandleStart          
  RxBasicHandleStop           
  RxBasicHwStart              
  RxBasicHwStop               
  RxFullHandleMax             
  RxFullHandleStart           
  RxFullHandleStop            
  RxFullHwStart               
  RxFullHwStop                
  TxBasicHandleMax            
  TxBasicHandleStart          
  TxBasicHandleStop           
  TxBasicHwStart              
  TxBasicHwStop               
  TxFullHandleMax             
  TxFullHandleStart           
  TxFullHandleStop            
  TxFullHwStart               
  TxFullHwStop                
  UnusedHandleMax             
  UnusedHandleStart           
  UnusedHandleStop            
  UnusedHwStart               
  UnusedHwStop                
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[3];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_GlobalInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_GlobalInterruptPendingMask
  \brief  Mask of all interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_GlobalInterruptPendingMaskType, CAN_CONST) Can_GlobalInterruptPendingMask[24];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitBT
**********************************************************************************************************************/
/** 
  \var    Can_InitBT
  \brief  Bit timing.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_InitBTType, CAN_CONST) Can_InitBT[3];
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitCodeH
**********************************************************************************************************************/
/** 
  \var    Can_InitCodeH
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_InitCodeHType, CAN_CONST) Can_InitCodeH[3];
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitCodeL
**********************************************************************************************************************/
/** 
  \var    Can_InitCodeL
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_InitCodeLType, CAN_CONST) Can_InitCodeL[3];
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitMaskH
**********************************************************************************************************************/
/** 
  \var    Can_InitMaskH
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_InitMaskHType, CAN_CONST) Can_InitMaskH[3];
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitMaskL
**********************************************************************************************************************/
/** 
  \var    Can_InitMaskL
  \brief  BasicCAN acceptance filter.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_InitMaskLType, CAN_CONST) Can_InitMaskL[3];
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[3];
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectStartIndex
  \brief  Start index of 'InitStruct'  / baudratesets (controllers as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[4];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitPortSel
**********************************************************************************************************************/
/** 
  \var    Can_InitPortSel
  \brief  Receive input selection.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_InitPortSelType, CAN_CONST) Can_InitPortSel[3];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsrOsId
**********************************************************************************************************************/
/** 
  \var    Can_IsrOsId
  \brief  OS Symbolic Name Value for all controller interrupts.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_IsrOsIdType, CAN_CONST) Can_IsrOsId[3];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element          Description
  IDValue      
  DLC_FIFO     
  HwHandle     
  MailboxType  
  MaxDataLen   
  MsgController
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[9];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_NodeAdr
**********************************************************************************************************************/
/** 
  \var    Can_NodeAdr
  \brief  Physical node address.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_NodeAdrType, CAN_CONST) Can_NodeAdr[3];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_NodeNum
**********************************************************************************************************************/
/** 
  \var    Can_NodeNum
  \brief  Physical node.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_NodeNumType, CAN_CONST) Can_NodeNum[3];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_PhysPrio
**********************************************************************************************************************/
/** 
  \var    Can_PhysPrio
  \brief  Interrupt priority.
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_PhysPrioType, CAN_CONST) Can_PhysPrio[8];
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_RxBasicInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_RxBasicInterruptPendingMask
  \brief  Mask of Rx BasicCAN interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_RxBasicInterruptPendingMaskType, CAN_CONST) Can_RxBasicInterruptPendingMask[24];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_RxFullInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_RxFullInterruptPendingMask
  \brief  Mask of Rx FullCAN interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_RxFullInterruptPendingMaskType, CAN_CONST) Can_RxFullInterruptPendingMask[24];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_SrcNum
**********************************************************************************************************************/
/** 
  \var    Can_SrcNum
  \brief  Interrupt source register.
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_SrcNumType, CAN_CONST) Can_SrcNum[3];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_TxInterruptPendingMask
**********************************************************************************************************************/
/** 
  \var    Can_TxInterruptPendingMask
  \brief  Mask of Tx interrupt objects.
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_TxInterruptPendingMaskType, CAN_CONST) Can_TxInterruptPendingMask[24];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_TxOffsetHwToLog
**********************************************************************************************************************/
/** 
  \var    Can_TxOffsetHwToLog
  \brief  tx hardware to logical handle indirection table
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Can_TxOffsetHwToLogType, CAN_CONST) Can_TxOffsetHwToLog[3];
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendPdu
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendPdu
  \brief  temporary pduId buffer for send mailbox
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Can_ActiveSendPduType, CAN_VAR_NOINIT) Can_ActiveSendPdu[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendState
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendState
  \brief  temporary send state buffer for send mailbox
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Can_ActiveSendStateType, CAN_VAR_NOINIT) Can_ActiveSendState[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_BusOffNotified
**********************************************************************************************************************/
/** 
  \var    Can_BusOffNotified
  \brief  Controls BusOff notifications.
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Can_BusOffNotifiedType, CAN_VAR_NOINIT) Can_BusOffNotified[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_CanInterruptCounter
**********************************************************************************************************************/
/** 
  \var    Can_CanInterruptCounter
  \brief  CAN interrupt disable counter for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern volatile VAR(Can_CanInterruptCounterType, CAN_VAR_NOINIT) Can_CanInterruptCounter[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_CanInterruptOldStatus
**********************************************************************************************************************/
/** 
  \var    Can_CanInterruptOldStatus
  \brief  last CAN interrupt status for restore interrupt for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(tCanLLCanIntOld, CAN_VAR_NOINIT) Can_CanInterruptOldStatus[3];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_Halt
**********************************************************************************************************************/
/** 
  \var    Can_Halt
  \brief  Reflects halt status of the controller.
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Can_HaltType, CAN_VAR_NOINIT) Can_Halt[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsBusOff
**********************************************************************************************************************/
/** 
  \var    Can_IsBusOff
  \brief  CAN state for each controller: busoff occur
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern volatile VAR(Can_IsBusOffType, CAN_VAR_NOINIT) Can_IsBusOff[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsHardwareCanceled
**********************************************************************************************************************/
/** 
  \var    Can_IsHardwareCanceled
  \brief  hw loop timeout occur for controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Can_IsHardwareCanceledType, CAN_VAR_NOINIT) Can_IsHardwareCanceled[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_LastInitObject
**********************************************************************************************************************/
/** 
  \var    Can_LastInitObject
  \brief  last set baudrate for reinit
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Can_LastInitObjectType, CAN_VAR_NOINIT) Can_LastInitObject[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_LogStatus
**********************************************************************************************************************/
/** 
  \var    Can_LogStatus
  \brief  CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern volatile VAR(Can_LogStatusType, CAN_VAR_NOINIT) Can_LogStatus[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_LoopTimeout
**********************************************************************************************************************/
/** 
  \var    Can_LoopTimeout
  \brief  hw loop timeout for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(Can_LoopTimeout_dim_type, CAN_VAR_NOINIT) Can_LoopTimeout[3];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_StatusReq
**********************************************************************************************************************/
/** 
  \var    Can_StatusReq
  \brief  CAN state request for each controller: START=0x01, STOP=0x02, WAKEUP=0x08, SLEEP=0x80
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern volatile VAR(Can_StatusReqType, CAN_VAR_NOINIT) Can_StatusReq[3];
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_TmpRxMsgMailbox
**********************************************************************************************************************/
/** 
  \var    Can_TmpRxMsgMailbox
  \brief  Temporary buffer for received messages.
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(tCanTmpMsgObjStruct, CAN_VAR_NOINIT) Can_TmpRxMsgMailbox[3];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* -----------------------------------------------------------------------------
    UserConfigFile
 ----------------------------------------------------------------------------- */
/* User Config File Start */

/* User Config File End */



#endif  /* CAN_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Can_Cfg.h
**********************************************************************************************************************/
 

