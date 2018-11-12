
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
  \file  File:  BrsHw_Ports.h
      Project:  Vector Basic Runtime System
       Module:  BrsHw for Platform Infineon Aurix

  \brief Description:  This header file contains the information for the evalboard specific port settings,
                       supported by this Brs implementation.

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
  Andreas Hahn                  vishan        Vector Informatik GmbH
  Sascha Mauser                 vismaa        Vector Informatik GmbH
  Benjamin Walter               visbwa        Vector Informatik GmbH
  Sherif Elsabbahy              vissey        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2016-09-15  vishan  Initial creation to support VEBN01890
                                All portpins were observed on transceiver side and toggled
  01.00.01  2016-12-02  vismaa  Added HSR_365, outsourced BrsHwPortInitPowerOn (Pin Configuration) from BrsHw.c
            2017-01-09  visbwa  Review
  01.00.02  2017-02-28  visbwa  Replaced "error:" by "error" (proper C-syntax)
  01.01.00  2017-05-02  visbwa  Added TCM pins support, review according to Brs_Template 2.01.00
  01.01.01  2017-05-10  visbwa  Clarification of error messages
  01.01.01  2017-05-15  vissey  Added TCM support for TC26X
**********************************************************************************************************************/

#ifndef _BRSHW_PORTS_H_
#define _BRSHW_PORTS_H_

/*#define BRSHW_PORTTEST*/ /* define if needed and add at the used sections*/
/*******************************************************************************
  Generic PORT definition types
********************************************************************************/
typedef enum
{
  BRSHW_PORT_PORTGROUP_0,
  BRSHW_PORT_PORTGROUP_1,
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTGROUP_3,
  BRSHW_PORT_PORTGROUP_4,
  BRSHW_PORT_PORTGROUP_5,
  BRSHW_PORT_PORTGROUP_6,
  BRSHW_PORT_PORTGROUP_7,
  BRSHW_PORT_PORTGROUP_8,
  BRSHW_PORT_PORTGROUP_9,
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTGROUP_12,
  BRSHW_PORT_PORTGROUP_13,
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTGROUP_16,
  BRSHW_PORT_PORTGROUP_17,
  BRSHW_PORT_PORTGROUP_18,
  BRSHW_PORT_PORTGROUP_19,
  BRSHW_PORT_PORTGROUP_20,
  BRSHW_PORT_PORTGROUP_21,
  BRSHW_PORT_PORTGROUP_22,
  BRSHW_PORT_PORTGROUP_23,
  BRSHW_PORT_PORTGROUP_24,
  BRSHW_PORT_PORTGROUP_25,
  BRSHW_PORT_PORTGROUP_26,
  BRSHW_PORT_PORTGROUP_27,
  BRSHW_PORT_PORTGROUP_28,
  BRSHW_PORT_PORTGROUP_29,
  BRSHW_PORT_PORTGROUP_30,
  BRSHW_PORT_PORTGROUP_31,
  BRSHW_PORT_PORTGROUP_32,
  BRSHW_PORT_PORTGROUP_33,
  BRSHW_PORT_PORTGROUP_34,
  BRSHW_PORT_PORTGROUP_35,
  BRSHW_PORT_PORTGROUP_36,
  BRSHW_PORT_PORTGROUP_37,
  BRSHW_PORT_PORTGROUP_38,
  BRSHW_PORT_PORTGROUP_39,
  BRSHW_PORT_PORTGROUP_40
}brsHw_Port_PortGroupType;

typedef enum
{
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_PORTNUMBER_4,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_PORTNUMBER_11,
  BRSHW_PORT_PORTNUMBER_12,
  BRSHW_PORT_PORTNUMBER_13,
  BRSHW_PORT_PORTNUMBER_14,
  BRSHW_PORT_PORTNUMBER_15
}brsHw_Port_PortNumberType;

typedef enum
{
  BRSHW_PORT_ALT_0,
  BRSHW_PORT_ALT_1,
  BRSHW_PORT_ALT_2,
  BRSHW_PORT_ALT_3,
  BRSHW_PORT_ALT_4,
  BRSHW_PORT_ALT_5,
  BRSHW_PORT_ALT_6,
  BRSHW_PORT_ALT_7,
  BRSHW_PORT_ALT_8
}brsHw_Port_AlternativeType;

typedef struct
{
  brsHw_Port_PortGroupType   portGroup;
  brsHw_Port_PortNumberType  portNumber;
  brsHw_Port_AlternativeType portAlternative;
}brsHw_Port_PortType;

#define BRSHW_PORT_LOGIC_HIGH (uint8)1
#define BRSHW_PORT_LOGIC_LOW  (uint8)0

/*******************************************************************************
  PIN configuration for TCM support
********************************************************************************/
#if defined (BRS_ENABLE_TCM_SUPPORT)
# if defined (BRS_DERIVATIVE_TC29X)
const brsHw_Port_PortType BRSHW_PORT_TCM_SDA_IN = {
  BRSHW_PORT_PORTGROUP_22,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_TCM_SDA_OUT = {
  BRSHW_PORT_PORTGROUP_22,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_TCM_CLK_IN = {
  BRSHW_PORT_PORTGROUP_22,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_TCM_CLK_OUT = {
  BRSHW_PORT_PORTGROUP_22,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_0};

# elif defined (BRS_DERIVATIVE_TC26X)
const brsHw_Port_PortType BRSHW_PORT_TCM_SDA_IN = {
  BRSHW_PORT_PORTGROUP_33,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_TCM_SDA_OUT = {
  BRSHW_PORT_PORTGROUP_33,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_TCM_CLK_IN = {
  BRSHW_PORT_PORTGROUP_33,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_TCM_CLK_OUT = {
  BRSHW_PORT_PORTGROUP_33,
  BRSHW_PORT_PORTNUMBER_13,
  BRSHW_PORT_ALT_0};

# else
  #error "TCM-Ports for your environment not yet configured within BrsHw_Ports.h. Configure them or disable BRS_ENABLE_TCM_SUPPORT."
# endif /*BRS_DERIVATIVE_x*/
#endif /*BRS_ENABLE_TCM_SUPPORT*/

/*******************************************************************************
  PIN configuration for alive LED support
********************************************************************************/
#if defined (BRS_ENABLE_SUPPORT_LEDS)
# if !defined (VGEN_ENABLE_DRVPORT)
#  if defined (BRS_EVA_BOARD_VEBN01263)
const brsHw_Port_PortType BRSHW_PORT_LED = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_11,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x2)
const brsHw_Port_PortType BRSHW_PORT_LED = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x3)
const brsHw_Port_PortType BRSHW_PORT_LED = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x4) || \
        defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
        defined (BRS_EVA_BOARD_TRIBOARD_TC2x7) || \
        defined (BRS_EVA_BOARD_TRIBOARD_TC2x8) || \
        defined (BRS_EVA_BOARD_TRIBOARD_TC2x9)
const brsHw_Port_PortType BRSHW_PORT_LED = {
  BRSHW_PORT_PORTGROUP_33,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_HSR_365)
const brsHw_Port_PortType BRSHW_PORT_LED = {
  BRSHW_PORT_PORTGROUP_0,
  BRSHW_PORT_PORTNUMBER_4,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_VEBN01890)
const brsHw_Port_PortType BRSHW_PORT_LED = {
  BRSHW_PORT_PORTGROUP_23,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};

#  else
  #error "Your chosen EvaBoard ist not yet supported for LED support. Feel free to add your EvaBoard on top, or disable BRS LED support."
#  endif

# else
  #error "Configure the valid PortPin for the LED within your DrvPort config and uncomment this error. Or disable BRS_ENABLE_SUPPORT_LEDS."
# endif /*!VGEN_ENABLE_DRVPORT*/
#endif /*BRS_ENABLE_SUPPORT_LEDS*/

/*******************************************************************************
  ------------------------------------------------------------
  COMMUNICATION DRIVER SPECIFIC PORT SETTINGS
  ------------------------------------------------------------
********************************************************************************/
/*******************************************************************************
  GENERAL COMMUNICATION DRIVER SPECIFIC SETTINGS
********************************************************************************/

/*******************************************************************************
  CAN driver
********************************************************************************/
#if defined (VGEN_ENABLE_CAN_DRV) || defined (BRSHW_PORTTEST)
# if defined (kCanPhysToLogChannelIndex_0) || defined (BRSHW_PORTTEST)
#  if defined (BRS_EVA_BOARD_TRIBOARD_TC2x4) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x7) || \
      defined (BRS_EVA_BOARD_VEBN01263) 
const brsHw_Port_PortType BRSHW_PORT_CAN0_TX = {
  BRSHW_PORT_PORTGROUP_20,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_5};
const brsHw_Port_PortType BRSHW_PORT_CAN0_RX = {
  BRSHW_PORT_PORTGROUP_20,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x2) || \
        defined (BRS_EVA_BOARD_TRIBOARD_TC2x3)
const brsHw_Port_PortType BRSHW_PORT_CAN0_TX = {
  BRSHW_PORT_PORTGROUP_33,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_5};
const brsHw_Port_PortType BRSHW_PORT_CAN0_RX = {
  BRSHW_PORT_PORTGROUP_33,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x8) || \
        defined (BRS_EVA_BOARD_TRIBOARD_TC2x9)
const brsHw_Port_PortType BRSHW_PORT_CAN0_TX = {
  BRSHW_PORT_PORTGROUP_34,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_4};
const brsHw_Port_PortType BRSHW_PORT_CAN0_RX = {
  BRSHW_PORT_PORTGROUP_34,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_HSR_365)
const brsHw_Port_PortType BRSHW_PORT_CAN0_TX = {
  BRSHW_PORT_PORTGROUP_34,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_4};
const brsHw_Port_PortType BRSHW_PORT_CAN0_RX = {
  BRSHW_PORT_PORTGROUP_34,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_CAN0_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_31,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_CAN0_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_31,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_VEBN01890)
const brsHw_Port_PortType BRSHW_PORT_CAN0_TX = {
  BRSHW_PORT_PORTGROUP_34,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_4};
const brsHw_Port_PortType BRSHW_PORT_CAN0_RX = {
  BRSHW_PORT_PORTGROUP_34,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_CAN0_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_34,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_CAN0_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_34,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_0};

#  else
  #error "Your EvalBoard is not yet supported CAN channel 0"
#  endif /*BRS_EVA_BOARD_x*/
# endif /*kCanPhysToLogChannelIndex_0*/

# if defined (kCanPhysToLogChannelIndex_1) || defined (BRSHW_PORTTEST)
#  if defined (BRS_EVA_BOARD_VEBN01263)      || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x2) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x3) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x4) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x7) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x8) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x9)
const brsHw_Port_PortType BRSHW_PORT_CAN1_TX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_5};
const brsHw_Port_PortType BRSHW_PORT_CAN1_RX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};

#  else
  #error "PortPins for your EvalBoard are not yet supported with CAN channel 1"
#  endif /*BRS_EVA_BOARD_x*/
# endif /*kCanPhysToLogChannelIndex_1*/

# if defined (kCanPhysToLogChannelIndex_2)
#  if defined (BRS_EVA_BOARD_VEBN01263)      || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x2) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x3) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x4) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x7) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x8)
const brsHw_Port_PortType BRSHW_PORT_CAN2_TX = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_5};
const brsHw_Port_PortType BRSHW_PORT_CAN2_RX = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};

#  else
  #error "PortPins for your EvalBoard are not yet supported with CAN channel 2"
#  endif /*BRS_EVA_BOARD_x*/
# endif /*kCanPhysToLogChannelIndex_2*/

# if defined (kCanPhysToLogChannelIndex_3)
#  if defined (BRS_EVA_BOARD_VEBN01263)      || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x4) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x7) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x8)
const brsHw_Port_PortType BRSHW_PORT_CAN3_TX = {
  BRSHW_PORT_PORTGROUP_20,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_5};
const brsHw_Port_PortType BRSHW_PORT_CAN3_RX = {
  BRSHW_PORT_PORTGROUP_20,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_0};

#  else
  #error "PortPins for your EvalBoard are not yet supported with CAN channel 3"
#  endif /*BRS_EVA_BOARD_x*/
# endif /*kCanPhysToLogChannelIndex_3*/

# if defined (kCanPhysToLogChannelIndex_4) || \
     defined (kCanPhysToLogChannelIndex_5) || \
     defined (kCanPhysToLogChannelIndex_6) || \
     defined (kCanPhysToLogChannelIndex_7)
  #error "Port configuration is not available for all CAN channels of your configuration!"
# endif
#endif /*VGEN_ENABLE_CAN_DRV*/

/*******************************************************************************
  LIN driver
********************************************************************************/
#if defined (VGEN_ENABLE_LIN_DRV) || defined (BRSHW_PORTTEST)
# if defined (SIO_ENABLE_SIO_UART0) || defined (BRSHW_PORTTEST)
#  if defined (BRS_EVA_BOARD_VEBN01263)      || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x2) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x3) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x4) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x7)
const brsHw_Port_PortType BRSHW_PORT_LIN0_TX = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_2};
const brsHw_Port_PortType BRSHW_PORT_LIN0_RX = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x8)
const brsHw_Port_PortType BRSHW_PORT_LIN0_TX = {
  BRSHW_PORT_PORTGROUP_1,
  BRSHW_PORT_PORTNUMBER_13,
  BRSHW_PORT_ALT_4};
const brsHw_Port_PortType BRSHW_PORT_LIN0_RX = {
  BRSHW_PORT_PORTGROUP_1,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_VEBN01890)
const brsHw_Port_PortType BRSHW_PORT_LIN0_TX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_2};
const brsHw_Port_PortType BRSHW_PORT_LIN0_RX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};

#  else 
  #error "PortPins for your EvalBoard are not yet supported with LIN channel 0"
#  endif /*BRS_EVA_BOARD_x*/
# endif /*SIO_ENABLE_SIO_UART0||BRSHW_PORTTEST*/

# if defined (SIO_ENABLE_SIO_UART1) || defined(BRSHW_PORTTEST)
#  if defined (BRS_EVA_BOARD_VEBN01263)      || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x4) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x7) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x8) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x9)
const brsHw_Port_PortType BRSHW_PORT_LIN1_TX = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_4,
  BRSHW_PORT_ALT_2};
const brsHw_Port_PortType BRSHW_PORT_LIN1_RX = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x2)
const brsHw_Port_PortType BRSHW_PORT_LIN1_TX = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_2};
const brsHw_Port_PortType BRSHW_PORT_LIN1_RX = {
  BRSHW_PORT_PORTGROUP_20,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x3)
const brsHw_Port_PortType BRSHW_PORT_LIN1_TX = {
  BRSHW_PORT_PORTGROUP_20,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_2};
const brsHw_Port_PortType BRSHW_PORT_LIN1_RX = {
  BRSHW_PORT_PORTGROUP_20,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_0};

#  elif defined (BRS_EVA_BOARD_VEBN01890) 
const brsHw_Port_PortType BRSHW_PORT_LIN1_TX = {
  BRSHW_PORT_PORTGROUP_20,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_2};
const brsHw_Port_PortType BRSHW_PORT_LIN1_RX = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};

#  else 
  #error "PortPins for your EvalBoard are not yet supported with LIN channel 1"
#  endif /*BRS_EVA_BOARD_x*/
# endif /*SIO_ENABLE_SIO_UART1||BRSHW_PORTTEST*/

# if defined (SIO_ENABLE_SIO_UART2)
  #error "PortPins for your EvalBoard are not yet supported with LIN channel 2"
# endif /*SIO_ENABLE_SIO_UART2*/

# if defined (SIO_ENABLE_SIO_UART3) || defined(BRSHW_PORTTEST)
#  if defined (BRS_EVA_BOARD_HSR_365)
const brsHw_Port_PortType BRSHW_PORT_LIN3_TX = {
  BRSHW_PORT_PORTGROUP_0,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_3};
const brsHw_Port_PortType BRSHW_PORT_LIN3_RX = {
  BRSHW_PORT_PORTGROUP_0,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_LIN3_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_1,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_0};

#  else
  #error "PortPins for your EvalBoard are not yet supported with LIN channel 3"
#  endif /*BRS_EVA_BOARD_x*/
# endif /*SIO_ENABLE_SIO_UART3||BRSHW_PORTTEST*/
#endif /*VGEN_ENABLE_LIN_DRV*/

/*******************************************************************************
  FLEXRAY driver
********************************************************************************/
#if defined (VGEN_ENABLE_DRVFR__BASEASR) || defined(BRSHW_PORTTEST)
# if defined (BRS_EVA_BOARD_VEBN01263)
  /* ERAY-A */
const brsHw_Port_PortType BRSHW_PORT_FR0A_TX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_RX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TXEN = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_4,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_ERRNA = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_7};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_0};

# elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x3)
  /* ERAY-A */
const brsHw_Port_PortType BRSHW_PORT_FR0A_TX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_RX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TXEN = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_4,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_ERRNA = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_7};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_0};/* pull up */
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_0};/* pull up */

  /* ERAY-B */
const brsHw_Port_PortType BRSHW_PORT_FR0B_TX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0B_RX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0B_TXEN = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0B_ERRNB = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_7};
const brsHw_Port_PortType BRSHW_PORT_FR0B_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0B_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_0};

# elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x4)
  /* ERAY-A */
const brsHw_Port_PortType BRSHW_PORT_FR0A_TX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_RX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TXEN = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_4,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_ERRNA = {
  BRSHW_PORT_PORTGROUP_0,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_7};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};/*pull-up*/
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_0};/*pull-up*/

  /* ERAY-B */
const brsHw_Port_PortType BRSHW_PORT_FR0B_TX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0B_RX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0B_TXEN = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0B_ERRNB = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_7};
const brsHw_Port_PortType BRSHW_PORT_FR0B_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_0};/*pull-up*/
const brsHw_Port_PortType BRSHW_PORT_FR0B_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_0};/*pull-up*/

# elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
       defined (BRS_EVA_BOARD_TRIBOARD_TC2x7)
  /* ERAY-A */
const brsHw_Port_PortType BRSHW_PORT_FR0A_TX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_RX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TXEN = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_4,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_ERRNA = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_7};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};/*pull-up*/
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_0};/*pull-up*/

  /* ERAY-B */
const brsHw_Port_PortType BRSHW_PORT_FR0B_TX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0B_RX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0B_TXEN = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0B_ERRNB = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_7};
const brsHw_Port_PortType BRSHW_PORT_FR0B_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_0};/*pull-up*/
const brsHw_Port_PortType BRSHW_PORT_FR0B_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_0};/*pull-up*/

# elif defined (BRS_EVA_BOARD_TRIBOARD_TC2x8) || \
       defined (BRS_EVA_BOARD_TRIBOARD_TC2x9)
  /* ERAY-A */
const brsHw_Port_PortType BRSHW_PORT_FR0A_TX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_RX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TXEN = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_ERRNA = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_7};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};/*pull-up*/
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_0};/*pull-up*/

  /* ERAY-B */
const brsHw_Port_PortType BRSHW_PORT_FR0B_TX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0B_RX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0B_TXEN = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0B_ERRNB = {
  BRSHW_PORT_PORTGROUP_15,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_7};
const brsHw_Port_PortType BRSHW_PORT_FR0B_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_0};/*pull-up*/
const brsHw_Port_PortType BRSHW_PORT_FR0B_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_10,
  BRSHW_PORT_PORTNUMBER_5,
  BRSHW_PORT_ALT_0};/*pull-up*/

# elif defined (BRS_EVA_BOARD_HSR_365)
  /* ERAY-A */
const brsHw_Port_PortType BRSHW_PORT_FR0A_TX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_RX = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TXEN = {
  BRSHW_PORT_PORTGROUP_14,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_25,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_0}; /*pull up*/
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_25,
  BRSHW_PORT_PORTNUMBER_3,/*pull up*/
  BRSHW_PORT_ALT_0};

# elif defined (BRS_EVA_BOARD_VEBN01890)
  /* ERAY-A */
const brsHw_Port_PortType BRSHW_PORT_FR0A_TX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_FR0A_RX = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_FR0A_TXEN = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_4,
  BRSHW_PORT_ALT_6}; 
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_STB = {
  BRSHW_PORT_PORTGROUP_0,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_0}; /*pull up*/
const brsHw_Port_PortType BRSHW_PORT_FR0A_TRCV_EN = {
  BRSHW_PORT_PORTGROUP_0,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0}; /*pull up*/

# else
  #error "PortPins for your EvalBoard are not yet supported with FR"
# endif /*BRS_EVA_BOARD_x*/
#endif /*VGEN_ENABLE_DRVFR__BASEASR*/

/*******************************************************************************
  ETHERNET driver
********************************************************************************/
#if defined (VGEN_ENABLE_DRVETH__BASEASR) || defined (BRSHW_PORTTEST)
# if defined (BRS_EVA_BOARD_VEBN01263)      || \
     defined (BRS_EVA_BOARD_TRIBOARD_TC2x4) || \
     defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
     defined (BRS_EVA_BOARD_TRIBOARD_TC2x7) || \
     defined (BRS_EVA_BOARD_TRIBOARD_TC2x8) || \
     defined (BRS_EVA_BOARD_TRIBOARD_TC2x9)
  /* RMII interface!!! */
const brsHw_Port_PortType BRSHW_PORT_ETH_REFCLK = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_12,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD0 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD1 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXEN = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD0 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD1 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_CRSDV = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_11,
  BRSHW_PORT_ALT_0};

#  if defined (BRS_EVA_BOARD_VEBN01263)      || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x5) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x7)
const brsHw_Port_PortType BRSHW_PORT_ETH_MDIO = {
  BRSHW_PORT_PORTGROUP_21,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_MDC = {
  BRSHW_PORT_PORTGROUP_21,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};
#  endif /*BRS_EVA_BOARD_x*/

#  if defined (BRS_EVA_BOARD_TRIBOARD_TC2x4)
const brsHw_Port_PortType BRSHW_PORT_ETH_MDIO = { 
  BRSHW_PORT_PORTGROUP_0,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_0}; 
const brsHw_Port_PortType BRSHW_PORT_ETH_MDC = {
  BRSHW_PORT_PORTGROUP_2,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_6};
#  endif /*BRS_EVA_BOARD_TRIBOARD_TC2x4*/

#  if defined (BRS_EVA_BOARD_TRIBOARD_TC2x8) || \
      defined (BRS_EVA_BOARD_TRIBOARD_TC2x9)
const brsHw_Port_PortType BRSHW_PORT_ETH_MDIO = {
  BRSHW_PORT_PORTGROUP_12,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};s
const brsHw_Port_PortType BRSHW_PORT_ETH_MDC = {
  BRSHW_PORT_PORTGROUP_12,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};
#  endif /*BRS_EVA_BOARD_TRIBOARD_TC2x8||BRS_EVA_BOARD_TRIBOARD_TC2x9*/

# elif defined (BRS_EVA_BOARD_HSR_365)
const brsHw_Port_PortType BRSHW_PORT_ETH_REFCLK = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_4,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD0 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD1 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD2 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD3 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXEN = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_6}; 
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD0 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD1 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD2 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD3 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_CRSDV = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_11,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_MDIO = {
  BRSHW_PORT_PORTGROUP_12,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_MDC = {
  BRSHW_PORT_PORTGROUP_12,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};

# elif defined (BRS_EVA_BOARD_VEBN01890)
const brsHw_Port_PortType BRSHW_PORT_ETH_REFCLK = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_12,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD0 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_3,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD1 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_2,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD2 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXD3 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_TXEN = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_6,
  BRSHW_PORT_ALT_6};
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD0 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_10,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD1 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_9,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD2 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_8,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_RXD3 = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_7,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_CRSDV = {
  BRSHW_PORT_PORTGROUP_11,
  BRSHW_PORT_PORTNUMBER_11,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_MDIO = {
  BRSHW_PORT_PORTGROUP_12,
  BRSHW_PORT_PORTNUMBER_1,
  BRSHW_PORT_ALT_0};
const brsHw_Port_PortType BRSHW_PORT_ETH_MDC = {
  BRSHW_PORT_PORTGROUP_12,
  BRSHW_PORT_PORTNUMBER_0,
  BRSHW_PORT_ALT_6};

# else
  #error "PortPins for your EvalBoard are not yet supported with ETH"
# endif /*BRS_EVA_BOARD_x*/
#endif /*VGEN_ENABLE_DRVETH__BASEASR*/

#endif /*_BRSHW_PORTS_H_*/