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
/**        \file  EthTrcv_30_Ethmii_Regs.h
 *        \brief  Transceiver specific header containing register addresses and access masks
 *
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

#if !defined (ETHTRCV_30_ETHMII_TRCV_H)
# define ETHTRCV_30_ETHMII_TRCV_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "EthTrcv_30_Ethmii_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* register adress offsets */
# define ETHTRCV_30_ETHMII_REG_OFFS_BMCR                     (0x0000U)
# define ETHTRCV_30_ETHMII_REG_OFFS_BMSR                     (0x0001U)
# define ETHTRCV_30_ETHMII_REG_OFFS_PHYIDR1                  (0x0002U)
# define ETHTRCV_30_ETHMII_REG_OFFS_PHYIDR2                  (0x0003U)
# define ETHTRCV_30_ETHMII_REG_OFFS_ANAR                     (0x0004U)
# define ETHTRCV_30_ETHMII_REG_OFFS_CFG1                     (0x0009U)
# define ETHTRCV_30_ETHMII_REG_OFFS_PHYSTS                   (0x0010U)
# define ETHTRCV_30_ETHMII_REG_OFFS_LEDCR                    (0x0018U)

/* BMCR register access (Basic Mode Control Register) */
# define ETHTRCV_30_ETHMII_REG_BMCR_RESET                    (0x8000U)
# define ETHTRCV_30_ETHMII_REG_BMCR_LOOPBACK_ENABLE          (0x4000U)
# define ETHTRCV_30_ETHMII_REG_BMCR_SPEED_SELECTION_LSB      (0x2000U)
# define ETHTRCV_30_ETHMII_REG_BMCR_SPEED_SELECTION_MSB      (0x0040U)
# define ETHTRCV_30_ETHMII_REG_BMCR_ENABLE_AUTO_NEG          (0x1000U)
# define ETHTRCV_30_ETHMII_REG_BMCR_POWER_DOWN               (0x0800U)
# define ETHTRCV_30_ETHMII_REG_BMCR_RESTART_AUTO_NEG         (0x0200U)
# define ETHTRCV_30_ETHMII_REG_BMCR_CLEAR_SETTINGS           (0xC73FU)

/* BMSR register access (Basic Mode Status Register) */
# define ETHTRCV_30_ETHMII_REG_BMSR_LINK_STATE               (0x0004U)

/* PHYSTS register access (PHY Status Register) */
# define ETHTRCV_30_ETHMII_REG_PHYSTS_DUPLEX_STATE           (0x0004U)
# define ETHTRCV_30_ETHMII_REG_PHYSTS_SPEED_STATE            (0x0002U)

/* LEDCR register access (LED Direct Control Register) */
# define ETHTRCV_30_ETHMII_REG_LEDCR_DRV_SPDLED              (0x0020U)
# define ETHTRCV_30_ETHMII_REG_LEDCR_SPDLED                  (0x0004U)

/* PHYIDR1 register access (PHY Identifier Register #1) */
# define ETHTRCV_30_ETHMII_REG_PHYIDR1_OUI_MSB_MASK          (0xFFFFU)
# define ETHTRCV_30_ETHMII_REG_PHYIDR1_TI_OUI_MSB            (0x2000U)

/* PHYIDR2 register access (PHY Identifier Register #2) */
# define ETHTRCV_30_ETHMII_REG_PHYIDR2_OUI_LSB_MASK          (0xFC00U)
# define ETHTRCV_30_ETHMII_REG_PHYIDR1_TI_OUI_LSB            (0x5C00U)

/* ANAR register access (Auto Negotiation Advertisement Register */
# define ETHTRCV_30_ETHMII_REG_ANAR_100BASE_TX_FULL_DUPLEX   (0x0100U)
# define ETHTRCV_30_ETHMII_REG_ANAR_100BASE_TX_HALF_DUPLEX   (0x0080U)
# define ETHTRCV_30_ETHMII_REG_ANAR_10BASE_T_FULL_DUPLEX     (0x0040U)
# define ETHTRCV_30_ETHMII_REG_ANAR_10BASE_T_HALF_DUPLEX     (0x0020U)
# define ETHTRCV_30_ETHMII_REG_ANAR_CLEAR_ADV_CHOICE_MASK    (0xFE1FU)

/* CFG1 register access (1000BASE-T Configuration Register) */
# define ETHTRCV_30_ETHMII_REG_CFG1_MANUAL_MASTER_SLAVE_CFG  (0x1000U)
# define ETHTRCV_30_ETHMII_REG_CFG1_SET_PHY_AS_MASTER        (0x1800U)
# define ETHTRCV_30_ETHMII_REG_CFG1_SET_PHY_AS_SLAVE         (0x1000U)
# define ETHTRCV_30_ETHMII_REG_CFG1_PORT_TYPE_MULTI          (0x0400U)
# define ETHTRCV_30_ETHMII_REG_CFG1_1000BASE_T_FULL_DUPLEX   (0x0200U)
# define ETHTRCV_30_ETHMII_REG_CFG1_1000BASE_T_HALF_DUPLEX   (0x0100U)
# define ETHTRCV_30_ETHMII_REG_CFG1_ENABLE_AUTO_TDR          (0x0080U)
# define ETHTRCV_30_ETHMII_REG_CFG1_CLEAR_ADV_CHOICE_MASK    (0xFCFFU)
# define ETHTRCV_30_ETHMII_REG_CFG1_CLEAR_MS_CHOICE_MASK     (0xE7FFU)
#endif /* ETHTRCV_30_ETHMII_TRCV_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTrcv_ETHMII_Trcv.h
 *********************************************************************************************************************/
