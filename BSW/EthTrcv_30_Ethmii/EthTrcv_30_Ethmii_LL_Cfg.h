/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EthTrcv_30_Ethmii_LL_Cfg.h
 *        \brief  Core Ethernet Transceiver Driver Lower Layer Configuration Header
 *
 *        Description: The inline functions defined in the LL header are mapped to their respective source files by
 *        enabling the corresponding preprocessor define.
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  David Roeder                  visdrr        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2017-02-24  visdrr  -             Initial creation
 *********************************************************************************************************************/

#if !defined (ETHTRCV_30_ETHMII_LL_CFG_H)
# define ETHTRCV_30_ETHMII_LL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Compiler.h"
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* In core used inline functions */
# if (defined(ETHTRCV_30_ETHMII_SOURCE))
#  define ETHTRCV_30_ETHMII_LL_SET_BASIC_CONFIGURATION_REG_VAL               STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_MII_MODE                 STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE           STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_MODE                STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE           STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_GMII_MODE                STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_MODE               STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE          STD_ON
#  define ETHTRCV_30_ETHMII_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK             STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_LINK_STATE_ACTIVE                          STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_TRANSCEIVER_MODE_ACTIVE                    STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_DUPLEX_MODE_FULL                           STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_START_AUTO_NEG_AVAILABLE                   STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_GET_BAUD_RATE_AVAILABLE                    STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_GET_DUPLEX_MODE_AVAILABLE                  STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_SET_TEST_MODE_AVAILABLE                    STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_SIGNAL_QUALITY_AVAILABLE                   STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_TEST_MODE_SUPPORTED_BY_HW                  STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW              STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_TX_MODE_SUPPORTED_BY_HW                    STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_PHY_LOOPBACK_MODE                         STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_PHY_TX_MODE                               STD_ON
#  define ETHTRCV_30_ETHMII_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT           STD_ON
#  if(ETHTRCV_30_ETHMII_SOFT_RESET_ON_INIT == STD_ON)
#   define ETHTRCV_30_ETHMII_LL_IS_SW_RESET_FINISHED                         STD_ON
#   define ETHTRCV_30_ETHMII_LL_PREPARE_SW_RESET                             STD_ON
#   define ETHTRCV_30_ETHMII_LL_GET_SW_RESET_REGISTER                        STD_ON
#  else
#   define ETHTRCV_30_ETHMII_LL_IS_SW_RESET_FINISHED                         STD_OFF
#   define ETHTRCV_30_ETHMII_LL_PREPARE_SW_RESET                             STD_OFF
#   define ETHTRCV_30_ETHMII_LL_GET_SW_RESET_REGISTER                        STD_OFF
#  endif /* ETHTRCV_30_ETHMII_SOFT_RESET_ON_INIT */
#  define ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_1_REGISTER                 STD_ON
#  define ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_2_REGISTER                 STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_BASIC_CONTROL_REGISTER                    STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_1_REGISTER                     STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_2_REGISTER                     STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_TRANSCEIVER_MODE_REGISTER                 STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_START_AUTO_NEG_REGISTER                   STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_LINK_STATE_REGISTER                       STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_BAUD_RATE_REGISTER                        STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_DUPLEX_MODE_REGISTER                      STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT       STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_NUM_OF_INIT_FUNCS                         STD_ON
#  define ETHTRCV_30_ETHMII_LL_INIT_GLOBAL_VARIABLES                         STD_ON
#  define ETHTRCV_30_ETHMII_LL_ENABLE_LINK_STARTUP_DELAY                     STD_ON
#  define ETHTRCV_30_ETHMII_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS              STD_ON
#  define ETHTRCV_30_ETHMII_LL_ENABLE_CONFIG_ACCESS                          STD_ON
#  define ETHTRCV_30_ETHMII_LL_DISABLE_CONFIG_ACCESS                         STD_ON
#  define ETHTRCV_30_ETHMII_LL_CLEAR_ALL_MODE_SETTINGS                       STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE       STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN         STD_ON
#  define ETHTRCV_30_ETHMII_LL_ENABLE_START_AUTO_NEGOTIATION                 STD_ON
#  define ETHTRCV_30_ETHMII_LL_CHECK_BAUD_RATE                               STD_ON
#  define ETHTRCV_30_ETHMII_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT            STD_ON
#  define ETHTRCV_30_ETHMII_LL_SET_PHY_TEST_MODE                             STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_AVAILABLE                       STD_ON
#  define ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_FINISHED                        STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_CABLE_DIAG_RESULT_REGISTER                STD_ON
#  define ETHTRCV_30_ETHMII_LL_PREPARE_CABLE_DIAG                            STD_ON
#  define ETHTRCV_30_ETHMII_LL_CHECK_CABLE_DIAG_RESULT                       STD_ON
#  define ETHTRCV_30_ETHMII_LL_ADDITIONAL_STEPS_AFTER_CABLE_DIAG             STD_ON
#  define ETHTRCV_30_ETHMII_LL_RESET_LINK_FAIL_COUNTER                       STD_ON
#  define ETHTRCV_30_ETHMII_LL_INCREMENT_LINK_FAIL_COUNTER                   STD_ON
#  define ETHTRCV_30_ETHMII_LL_MAIN_FUNCTION_LINK_HANDLING                   STD_ON
# else
#  define ETHTRCV_30_ETHMII_V_READ_RDB_REGISTER                              STD_OFF
#  define ETHTRCV_30_ETHMII_V_WRITE_RDB_REGISTER                             STD_OFF
#  define ETHTRCV_30_ETHMII_V_SHADOW_READ                                    STD_OFF
#  define ETHTRCV_30_ETHMII_V_SHADOW_WRITE                                   STD_OFF
#  define ETHTRCV_30_ETHMII_V_EXPANSION_ACCESS                               STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_BASIC_CONFIGURATION_REG_VAL               STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_MII_MODE                 STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_LIGHT_MII_MODE           STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_MODE                STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RMII_XTAL_MODE           STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_GMII_MODE                STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_MODE               STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_MII_INTERFACE_TO_RGMII_XTAL_MODE          STD_OFF
#  define ETHTRCV_30_ETHMII_LL_CHECK_IF_TRANSCEIVER_ACCESS_IS_OK             STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_LINK_STATE_ACTIVE                          STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_TRANSCEIVER_MODE_ACTIVE                    STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_DUPLEX_MODE_FULL                           STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_START_AUTO_NEG_AVAILABLE                   STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_GET_BAUD_RATE_AVAILABLE                    STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_GET_DUPLEX_MODE_AVAILABLE                  STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_SET_TEST_MODE_AVAILABLE                    STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_SIGNAL_QUALITY_AVAILABLE                   STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_TEST_MODE_SUPPORTED_BY_HW                  STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_LOOPBACK_MODE_SUPPORTED_BY_HW              STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_TX_MODE_SUPPORTED_BY_HW                    STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_PHY_LOOPBACK_MODE                         STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_PHY_TX_MODE                               STD_OFF
#  define ETHTRCV_30_ETHMII_LL_FINALIZE_SIGNAL_QUALITY_MEASUREMENT           STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_SW_RESET_FINISHED                          STD_OFF
#  define ETHTRCV_30_ETHMII_LL_PREPARE_SW_RESET                              STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_SW_RESET_REGISTER                         STD_OFF
#  define ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_1_REGISTER                 STD_OFF
#  define ETHTRCV_30_ETHMII_LL_COMPARE_IDENTIFIER_2_REGISTER                 STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_BASIC_CONTROL_REGISTER                    STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_1_REGISTER                     STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_IDENTIFIER_2_REGISTER                     STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_TRANSCEIVER_MODE_REGISTER                 STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_START_AUTO_NEG_REGISTER                   STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_LINK_STATE_REGISTER                       STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_BAUD_RATE_REGISTER                        STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_DUPLEX_MODE_REGISTER                      STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_PHY_SIGNAL_QUALITY_VALUE_IN_PERCENT       STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_NUM_OF_INIT_FUNCS                         STD_OFF
#  define ETHTRCV_30_ETHMII_LL_INIT_GLOBAL_VARIABLES                         STD_OFF
#  define ETHTRCV_30_ETHMII_LL_ENABLE_LINK_STARTUP_DELAY                     STD_OFF
#  define ETHTRCV_30_ETHMII_LL_RUN_VENDOR_SPECIFIC_INIT_SCRIPTS              STD_OFF
#  define ETHTRCV_30_ETHMII_LL_ENABLE_CONFIG_ACCESS                          STD_OFF
#  define ETHTRCV_30_ETHMII_LL_DISABLE_CONFIG_ACCESS                         STD_OFF
#  define ETHTRCV_30_ETHMII_LL_CLEAR_ALL_MODE_SETTINGS                       STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_ACTIVE       STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_REG_VAL_FOR_TRANSCEIVER_MODE_DOWN         STD_OFF
#  define ETHTRCV_30_ETHMII_LL_ENABLE_START_AUTO_NEGOTIATION                 STD_OFF
#  define ETHTRCV_30_ETHMII_LL_CHECK_BAUD_RATE                               STD_OFF
#  define ETHTRCV_30_ETHMII_LL_PREPARE_SIGNAL_QUALITY_MEASUREMENT            STD_OFF
#  define ETHTRCV_30_ETHMII_LL_SET_PHY_TEST_MODE                             STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_AVAILABLE                       STD_OFF
#  define ETHTRCV_30_ETHMII_LL_IS_CABLE_DIAG_FINISHED                        STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_CABLE_DIAG_RESULT_REGISTER                STD_OFF
#  define ETHTRCV_30_ETHMII_LL_PREPARE_CABLE_DIAG                            STD_OFF
#  define ETHTRCV_30_ETHMII_LL_CHECK_CABLE_DIAG_RESULT                       STD_OFF
#  define ETHTRCV_30_ETHMII_LL_ADDITIONAL_STEPS_AFTER_CABLE_DIAG             STD_OFF
#  define ETHTRCV_30_ETHMII_LL_RESET_LINK_FAIL_COUNTER                       STD_OFF
#  define ETHTRCV_30_ETHMII_LL_INCREMENT_LINK_FAIL_COUNTER                   STD_OFF
#  define ETHTRCV_30_ETHMII_LL_MAIN_FUNCTION_LINK_HANDLING                   STD_OFF
# endif

/* In lower layer used inline functions */
# if (defined(ETHTRCV_30_ETHMII_LL_SOURCE))
# else
# endif /* ETHTRCV_30_ETHMII_LL_SOURCE */
# if (defined(ETHTRCV_30_ETHMII_LCFG_SOURCE))
#  define ETHTRCV_30_ETHMII_LL_SET_LINK_SPEED                                STD_ON
#  define ETHTRCV_30_ETHMII_LL_PREPARE_LINK_SPEED_REG_VAL                    STD_ON
#  define ETHTRCV_30_ETHMII_LL_GET_LINK_SPEED_REGISTER                       STD_ON
#  define ETHTRCV_30_ETHMII_LL_EXTENDED_REGISTER_ACCESS                      STD_ON
# else
#  define ETHTRCV_30_ETHMII_LL_SET_LINK_SPEED                                STD_OFF
#  define ETHTRCV_30_ETHMII_LL_PREPARE_LINK_SPEED_REG_VAL                    STD_OFF
#  define ETHTRCV_30_ETHMII_LL_GET_LINK_SPEED_REGISTER                       STD_OFF
#  define ETHTRCV_30_ETHMII_LL_EXTENDED_REGISTER_ACCESS                      STD_OFF
# endif /* ETHTRCV_30_ETHMII_LL_SOURCE */
#endif /* ETHTRCV_30_ETHMII_LL_CFG_H */
