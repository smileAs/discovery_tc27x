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
 *            Module: CanTrcv
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTrcv_30_Tja1043_Cfg.h
 *   Generation Time: 2018-08-21 08:49:55
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


#if !defined(CANTRCV_30_TJA1043_CFG_H)
#define CANTRCV_30_TJA1043_CFG_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
/* SREQ00010148 */
# include "ComStack_Types.h" 
# include "Can_GeneralTypes.h"


#include "Dio.h"
#include "CanIf.h"

#include "EcuM_Cbk.h"


/**********************************************************************************************************************
  VERSION DEFINES (Adapted with: ESCAN00086365)
**********************************************************************************************************************/
#define DRVTRANS_CAN_30_TJA1043_GENTOOL_CFG5_MAJOR_VERSION 0x03U
#define DRVTRANS_CAN_30_TJA1043_GENTOOL_CFG5_MINOR_VERSION 0x01U
#define DRVTRANS_CAN_30_TJA1043_GENTOOL_CFG5_PATCH_VERSION 0x00U

#define CANTRCV_30_TJA1043_GENTOOL_CFG5_BASE_COMP_VERSION 0x0104U
#define CANTRCV_30_TJA1043_GENTOOL_CFG5_HW_COMP_VERSION   0x0103U


/**********************************************************************************************************************
  SWITCHES (BASE)
**********************************************************************************************************************/
#define CANTRCV_30_TJA1043_MAX_CHANNEL             1U
#define CANTRCV_30_TJA1043_GENERAL_WAKE_UP_SUPPORT CANTRCV_30_TJA1043_WAKEUP_NOT_SUPPORTED
#define CANTRCV_30_TJA1043_WAKEUP_BY_BUS_USED      STD_OFF
#define CANTRCV_30_TJA1043_GET_VERSION_INFO        STD_OFF
#define CANTRCV_30_TJA1043_DEV_ERROR_DETECT        STD_OFF
#define CANTRCV_30_TJA1043_DEV_ERROR_REPORT        STD_OFF
#define CANTRCV_30_TJA1043_ECUC_SAFE_BSW_CHECKS    STD_OFF
#define CANTRCV_30_TJA1043_PROD_ERROR_DETECT       STD_OFF 
#define CANTRCV_30_TJA1043_INSTANCE_ID             0
#define CANTRCV_30_TJA1043_HW_PN_SUPPORT           STD_OFF
#define CANTRCV_30_TJA1043_BUS_ERR_FLAG            STD_OFF
#define CANTRCV_30_TJA1043_VERIFY_DATA             STD_ON  
#define CANTRCV_30_TJA1043_SPI_ACCESS_SYNCHRONOUS  STD_OFF
#define CANTRCV_30_TJA1043_USE_ICU                 STD_OFF
#define CANTRCV_30_TJA1043_USE_EXTENDED_WU_SRC     STD_OFF

#define CanTrcv_30_Tja1043_CanTrcvChannel 0U 


#ifndef CANTRCV_30_TJA1043_USE_DUMMY_FUNCTIONS
#define CANTRCV_30_TJA1043_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef CANTRCV_30_TJA1043_USE_DUMMY_STATEMENT
#define CANTRCV_30_TJA1043_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef CANTRCV_30_TJA1043_DUMMY_STATEMENT
#define CANTRCV_30_TJA1043_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CANTRCV_30_TJA1043_DUMMY_STATEMENT_CONST
#define CANTRCV_30_TJA1043_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CANTRCV_30_TJA1043_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANTRCV_30_TJA1043_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANTRCV_30_TJA1043_ATOMIC_VARIABLE_ACCESS
#define CANTRCV_30_TJA1043_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANTRCV_30_TJA1043_PROCESSOR_TC277
#define CANTRCV_30_TJA1043_PROCESSOR_TC277
#endif
#ifndef CANTRCV_30_TJA1043_COMP_GNU
#define CANTRCV_30_TJA1043_COMP_GNU
#endif
#ifndef CANTRCV_30_TJA1043_GEN_GENERATOR_MSR
#define CANTRCV_30_TJA1043_GEN_GENERATOR_MSR
#endif
#ifndef CANTRCV_30_TJA1043_CPUTYPE_BITORDER_LSB2MSB
#define CANTRCV_30_TJA1043_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef CANTRCV_30_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE
#define CANTRCV_30_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANTRCV_30_TJA1043_CONFIGURATION_VARIANT_LINKTIME
#define CANTRCV_30_TJA1043_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANTRCV_30_TJA1043_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANTRCV_30_TJA1043_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANTRCV_30_TJA1043_CONFIGURATION_VARIANT
#define CANTRCV_30_TJA1043_CONFIGURATION_VARIANT CANTRCV_30_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANTRCV_30_TJA1043_POSTBUILD_VARIANT_SUPPORT
#define CANTRCV_30_TJA1043_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
  SWITCHES (HW SPECIFIC)
**********************************************************************************************************************/
 

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanTrcv_30_Tja1043PCDataSwitches  CanTrcv_30_Tja1043 Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANTRCV_30_TJA1043_CHANNEL                                    STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_Channel' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CANTRCV_30_TJA1043_ICUCHANNELOFCHANNEL                        STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_Channel.IcuChannel' Reason: 'No "ICU" is configured.' */
#define CANTRCV_30_TJA1043_ICUCHANNELSETOFCHANNEL                     STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_Channel.IcuChannelSet' Reason: 'No "ICU" is configured.' */
#define CANTRCV_30_TJA1043_CHANNELUSED                                STD_ON
#define CANTRCV_30_TJA1043_DIOCONFIGURATION                           STD_ON
#define CANTRCV_30_TJA1043_PINENOFDIOCONFIGURATION                    STD_ON
#define CANTRCV_30_TJA1043_PINERROFDIOCONFIGURATION                   STD_ON
#define CANTRCV_30_TJA1043_PINSTBOFDIOCONFIGURATION                   STD_ON
#define CANTRCV_30_TJA1043_FINALMAGICNUMBER                           STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANTRCV_30_TJA1043_GENERATORCOMPATIBILITYVERSION              STD_ON
#define CANTRCV_30_TJA1043_INITDATAHASHCODE                           STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANTRCV_30_TJA1043_SIZEOFCHANNELUSED                          STD_ON
#define CANTRCV_30_TJA1043_SIZEOFDIOCONFIGURATION                     STD_ON
#define CANTRCV_30_TJA1043_SIZEOFWAKEUPBYBUSUSED                      STD_ON
#define CANTRCV_30_TJA1043_SIZEOFWAKEUPSOURCE                         STD_ON
#define CANTRCV_30_TJA1043_WAKEUPBYBUSUSED                            STD_ON
#define CANTRCV_30_TJA1043_WAKEUPSOURCE                               STD_ON
#define CANTRCV_30_TJA1043_WUSRCPOR                                   STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_WuSrcPor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTRCV_30_TJA1043_WUSRCSYSERR                                STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_WuSrcSyserr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTRCV_30_TJA1043_PCCONFIG                                   STD_ON
#define CANTRCV_30_TJA1043_CHANNELUSEDOFPCCONFIG                      STD_ON
#define CANTRCV_30_TJA1043_DIOCONFIGURATIONOFPCCONFIG                 STD_ON
#define CANTRCV_30_TJA1043_FINALMAGICNUMBEROFPCCONFIG                 STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANTRCV_30_TJA1043_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG    STD_ON
#define CANTRCV_30_TJA1043_INITDATAHASHCODEOFPCCONFIG                 STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANTRCV_30_TJA1043_SIZEOFCHANNELUSEDOFPCCONFIG                STD_ON
#define CANTRCV_30_TJA1043_SIZEOFDIOCONFIGURATIONOFPCCONFIG           STD_ON
#define CANTRCV_30_TJA1043_SIZEOFWAKEUPBYBUSUSEDOFPCCONFIG            STD_ON
#define CANTRCV_30_TJA1043_SIZEOFWAKEUPSOURCEOFPCCONFIG               STD_ON
#define CANTRCV_30_TJA1043_WAKEUPBYBUSUSEDOFPCCONFIG                  STD_ON
#define CANTRCV_30_TJA1043_WAKEUPSOURCEOFPCCONFIG                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCIsReducedToDefineDefines  CanTrcv_30_Tja1043 Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANTRCV_30_TJA1043_ISDEF_CHANNELUSED                          STD_OFF
#define CANTRCV_30_TJA1043_ISDEF_PINENOFDIOCONFIGURATION              STD_OFF
#define CANTRCV_30_TJA1043_ISDEF_PINERROFDIOCONFIGURATION             STD_OFF
#define CANTRCV_30_TJA1043_ISDEF_PINSTBOFDIOCONFIGURATION             STD_OFF
#define CANTRCV_30_TJA1043_ISDEF_WAKEUPBYBUSUSED                      STD_OFF
#define CANTRCV_30_TJA1043_ISDEF_WAKEUPSOURCE                         STD_OFF
#define CANTRCV_30_TJA1043_ISDEF_CHANNELUSEDOFPCCONFIG                STD_ON
#define CANTRCV_30_TJA1043_ISDEF_DIOCONFIGURATIONOFPCCONFIG           STD_ON
#define CANTRCV_30_TJA1043_ISDEF_WAKEUPBYBUSUSEDOFPCCONFIG            STD_ON
#define CANTRCV_30_TJA1043_ISDEF_WAKEUPSOURCEOFPCCONFIG               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCEqualsAlwaysToDefines  CanTrcv_30_Tja1043 Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANTRCV_30_TJA1043_EQ2_CHANNELUSED                            
#define CANTRCV_30_TJA1043_EQ2_PINENOFDIOCONFIGURATION                
#define CANTRCV_30_TJA1043_EQ2_PINERROFDIOCONFIGURATION               
#define CANTRCV_30_TJA1043_EQ2_PINSTBOFDIOCONFIGURATION               
#define CANTRCV_30_TJA1043_EQ2_WAKEUPBYBUSUSED                        
#define CANTRCV_30_TJA1043_EQ2_WAKEUPSOURCE                           
#define CANTRCV_30_TJA1043_EQ2_CHANNELUSEDOFPCCONFIG                  CanTrcv_30_Tja1043_ChannelUsed
#define CANTRCV_30_TJA1043_EQ2_DIOCONFIGURATIONOFPCCONFIG             CanTrcv_30_Tja1043_DioConfiguration
#define CANTRCV_30_TJA1043_EQ2_WAKEUPBYBUSUSEDOFPCCONFIG              CanTrcv_30_Tja1043_WakeupByBusUsed
#define CANTRCV_30_TJA1043_EQ2_WAKEUPSOURCEOFPCCONFIG                 CanTrcv_30_Tja1043_WakeupSource
/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCSymbolicInitializationPointers  CanTrcv_30_Tja1043 Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanTrcv_30_Tja1043_Config_Ptr                                 NULL_PTR  /**< symbolic identifier which shall be used to initialize 'CanTrcv_30_Tja1043' */
/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCInitializationSymbols  CanTrcv_30_Tja1043 Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanTrcv_30_Tja1043_Config                                     NULL_PTR  /**< symbolic identifier which could be used to initialize 'CanTrcv_30_Tja1043 */
/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCGeneral  CanTrcv_30_Tja1043 General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANTRCV_30_TJA1043_CHECK_INIT_POINTER                         STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANTRCV_30_TJA1043_FINAL_MAGIC_NUMBER                         0x461EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanTrcv_30_Tja1043 */
#define CANTRCV_30_TJA1043_INDIVIDUAL_POSTBUILD                       STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanTrcv_30_Tja1043' is not configured to be postbuild capable. */
#define CANTRCV_30_TJA1043_INIT_DATA                                  CANTRCV_30_TJA1043_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANTRCV_30_TJA1043_INIT_DATA_HASH_CODE                        777796122L  /**< the precompile constant to validate the initialization structure at initialization time of CanTrcv_30_Tja1043 with a hashcode. The seed value is '0x461EU' */
#define CANTRCV_30_TJA1043_USE_ECUM_BSW_ERROR_HOOK                    STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANTRCV_30_TJA1043_USE_INIT_POINTER                           STD_OFF  /**< STD_ON if the init pointer CanTrcv_30_Tja1043 shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanTrcv_30_Tja1043LTDataSwitches  CanTrcv_30_Tja1043 Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANTRCV_30_TJA1043_LTCONFIG                                   STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanTrcv_30_Tja1043PBDataSwitches  CanTrcv_30_Tja1043 Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANTRCV_30_TJA1043_PBCONFIG                                   STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANTRCV_30_TJA1043_LTCONFIGIDXOFPBCONFIG                      STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANTRCV_30_TJA1043_PCCONFIGIDXOFPBCONFIG                      STD_OFF  /**< Deactivateable: 'CanTrcv_30_Tja1043_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
  \defgroup  CanTrcv_30_Tja1043PCGetConstantDuplicatedRootDataMacros  CanTrcv_30_Tja1043 Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanTrcv_30_Tja1043_GetChannelUsedOfPCConfig()                 CanTrcv_30_Tja1043_ChannelUsed  /**< the pointer to CanTrcv_30_Tja1043_ChannelUsed */
#define CanTrcv_30_Tja1043_GetDioConfigurationOfPCConfig()            CanTrcv_30_Tja1043_DioConfiguration  /**< the pointer to CanTrcv_30_Tja1043_DioConfiguration */
#define CanTrcv_30_Tja1043_GetGeneratorCompatibilityVersionOfPCConfig() 0x01040103UL
#define CanTrcv_30_Tja1043_GetSizeOfChannelUsedOfPCConfig()           1U  /**< the number of accomplishable value elements in CanTrcv_30_Tja1043_ChannelUsed */
#define CanTrcv_30_Tja1043_GetSizeOfDioConfigurationOfPCConfig()      1U  /**< the number of accomplishable value elements in CanTrcv_30_Tja1043_DioConfiguration */
#define CanTrcv_30_Tja1043_GetSizeOfWakeupByBusUsedOfPCConfig()       1U  /**< the number of accomplishable value elements in CanTrcv_30_Tja1043_WakeupByBusUsed */
#define CanTrcv_30_Tja1043_GetSizeOfWakeupSourceOfPCConfig()          1U  /**< the number of accomplishable value elements in CanTrcv_30_Tja1043_WakeupSource */
#define CanTrcv_30_Tja1043_GetWakeupByBusUsedOfPCConfig()             CanTrcv_30_Tja1043_WakeupByBusUsed  /**< the pointer to CanTrcv_30_Tja1043_WakeupByBusUsed */
#define CanTrcv_30_Tja1043_GetWakeupSourceOfPCConfig()                CanTrcv_30_Tja1043_WakeupSource  /**< the pointer to CanTrcv_30_Tja1043_WakeupSource */
/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCGetDataMacros  CanTrcv_30_Tja1043 Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanTrcv_30_Tja1043_IsChannelUsed(Index)                       ((CanTrcv_30_Tja1043_GetChannelUsedOfPCConfig()[(Index)]) != FALSE)
#define CanTrcv_30_Tja1043_GetPinENOfDioConfiguration(Index)          (CanTrcv_30_Tja1043_GetDioConfigurationOfPCConfig()[(Index)].PinENOfDioConfiguration)
#define CanTrcv_30_Tja1043_GetPinERROfDioConfiguration(Index)         (CanTrcv_30_Tja1043_GetDioConfigurationOfPCConfig()[(Index)].PinERROfDioConfiguration)
#define CanTrcv_30_Tja1043_GetPinSTBOfDioConfiguration(Index)         (CanTrcv_30_Tja1043_GetDioConfigurationOfPCConfig()[(Index)].PinSTBOfDioConfiguration)
#define CanTrcv_30_Tja1043_IsWakeupByBusUsed(Index)                   ((CanTrcv_30_Tja1043_GetWakeupByBusUsedOfPCConfig()[(Index)]) != FALSE)
#define CanTrcv_30_Tja1043_GetWakeupSource(Index)                     (CanTrcv_30_Tja1043_GetWakeupSourceOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCGetDeduplicatedDataMacros  CanTrcv_30_Tja1043 Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanTrcv_30_Tja1043_GetGeneratorCompatibilityVersion()         CanTrcv_30_Tja1043_GetGeneratorCompatibilityVersionOfPCConfig()
#define CanTrcv_30_Tja1043_GetSizeOfChannelUsed()                     CanTrcv_30_Tja1043_GetSizeOfChannelUsedOfPCConfig()
#define CanTrcv_30_Tja1043_GetSizeOfDioConfiguration()                CanTrcv_30_Tja1043_GetSizeOfDioConfigurationOfPCConfig()
#define CanTrcv_30_Tja1043_GetSizeOfWakeupByBusUsed()                 CanTrcv_30_Tja1043_GetSizeOfWakeupByBusUsedOfPCConfig()
#define CanTrcv_30_Tja1043_GetSizeOfWakeupSource()                    CanTrcv_30_Tja1043_GetSizeOfWakeupSourceOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCHasMacros  CanTrcv_30_Tja1043 Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanTrcv_30_Tja1043_HasChannelUsed()                           (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasDioConfiguration()                      (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasPinENOfDioConfiguration()               (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasPinERROfDioConfiguration()              (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasPinSTBOfDioConfiguration()              (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasGeneratorCompatibilityVersion()         (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasSizeOfChannelUsed()                     (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasSizeOfDioConfiguration()                (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasSizeOfWakeupByBusUsed()                 (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasSizeOfWakeupSource()                    (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasWakeupByBusUsed()                       (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasWakeupSource()                          (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasPCConfig()                              (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasChannelUsedOfPCConfig()                 (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasDioConfigurationOfPCConfig()            (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasGeneratorCompatibilityVersionOfPCConfig() (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasSizeOfChannelUsedOfPCConfig()           (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasSizeOfDioConfigurationOfPCConfig()      (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasSizeOfWakeupByBusUsedOfPCConfig()       (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasSizeOfWakeupSourceOfPCConfig()          (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasWakeupByBusUsedOfPCConfig()             (TRUE != FALSE)
#define CanTrcv_30_Tja1043_HasWakeupSourceOfPCConfig()                (TRUE != FALSE)
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
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTrcv_30_Tja1043PCIterableTypes  CanTrcv_30_Tja1043 Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanTrcv_30_Tja1043_ChannelUsed */
typedef uint8_least CanTrcv_30_Tja1043_ChannelUsedIterType;

/**   \brief  type used to iterate CanTrcv_30_Tja1043_DioConfiguration */
typedef uint8_least CanTrcv_30_Tja1043_DioConfigurationIterType;

/**   \brief  type used to iterate CanTrcv_30_Tja1043_WakeupByBusUsed */
typedef uint8_least CanTrcv_30_Tja1043_WakeupByBusUsedIterType;

/**   \brief  type used to iterate CanTrcv_30_Tja1043_WakeupSource */
typedef uint8_least CanTrcv_30_Tja1043_WakeupSourceIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCValueTypes  CanTrcv_30_Tja1043 Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanTrcv_30_Tja1043_ChannelUsed */
typedef boolean CanTrcv_30_Tja1043_ChannelUsedType;

/**   \brief  value based type definition for CanTrcv_30_Tja1043_GeneratorCompatibilityVersion */
typedef uint32 CanTrcv_30_Tja1043_GeneratorCompatibilityVersionType;

/**   \brief  value based type definition for CanTrcv_30_Tja1043_SizeOfChannelUsed */
typedef uint16 CanTrcv_30_Tja1043_SizeOfChannelUsedType;

/**   \brief  value based type definition for CanTrcv_30_Tja1043_SizeOfDioConfiguration */
typedef uint16 CanTrcv_30_Tja1043_SizeOfDioConfigurationType;

/**   \brief  value based type definition for CanTrcv_30_Tja1043_SizeOfWakeupByBusUsed */
typedef uint16 CanTrcv_30_Tja1043_SizeOfWakeupByBusUsedType;

/**   \brief  value based type definition for CanTrcv_30_Tja1043_SizeOfWakeupSource */
typedef uint16 CanTrcv_30_Tja1043_SizeOfWakeupSourceType;

/**   \brief  value based type definition for CanTrcv_30_Tja1043_WakeupByBusUsed */
typedef boolean CanTrcv_30_Tja1043_WakeupByBusUsedType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTrcv_30_Tja1043PCStructTypes  CanTrcv_30_Tja1043 Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanTrcv_30_Tja1043_DioConfiguration */
typedef struct sCanTrcv_30_Tja1043_DioConfigurationType
{
  Dio_ChannelType PinENOfDioConfiguration;
  Dio_ChannelType PinERROfDioConfiguration;
  Dio_ChannelType PinSTBOfDioConfiguration;
} CanTrcv_30_Tja1043_DioConfigurationType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTrcv_30_Tja1043PCRootValueTypes  CanTrcv_30_Tja1043 Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanTrcv_30_Tja1043_PCConfig */
typedef struct sCanTrcv_30_Tja1043_PCConfigType
{
  uint8 CanTrcv_30_Tja1043_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CanTrcv_30_Tja1043_PCConfigType;

typedef CanTrcv_30_Tja1043_PCConfigType CanTrcv_30_Tja1043_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTrcv_30_Tja1043_ChannelUsed
**********************************************************************************************************************/
#define CANTRCV_30_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(CanTrcv_30_Tja1043_ChannelUsedType, CANTRCV_30_TJA1043_CONST) CanTrcv_30_Tja1043_ChannelUsed[1];
#define CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1043_DioConfiguration
**********************************************************************************************************************/
/** 
  \var    CanTrcv_30_Tja1043_DioConfiguration
  \details
  Element    Description
  PinEN  
  PinERR 
  PinSTB 
*/ 
#define CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(CanTrcv_30_Tja1043_DioConfigurationType, CANTRCV_30_TJA1043_CONST) CanTrcv_30_Tja1043_DioConfiguration[1];  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
#define CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1043_WakeupByBusUsed
**********************************************************************************************************************/
#define CANTRCV_30_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(CanTrcv_30_Tja1043_WakeupByBusUsedType, CANTRCV_30_TJA1043_CONST) CanTrcv_30_Tja1043_WakeupByBusUsed[1];  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
#define CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1043_WakeupSource
**********************************************************************************************************************/
#define CANTRCV_30_TJA1043_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(EcuM_WakeupSourceType, CANTRCV_30_TJA1043_CONST) CanTrcv_30_Tja1043_WakeupSource[1];
#define CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT
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





#endif /* CANTRCV_30_TJA1043_CFG_H */

