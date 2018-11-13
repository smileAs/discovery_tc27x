/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : I2c_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  DATE, TIME: 2018-11-06, 14:00:09                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : I2C configuration generated out of ECU configuration       **
**                 file (I2c.bmd/.xdm)                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEBILITY :                                                             **
**                                                                            **
*******************************************************************************/
#ifndef I2C_CFG_H
#define I2C_CFG_H

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define I2C_AR_RELEASE_MAJOR_VERSION  (4U)
#define I2C_AR_RELEASE_MINOR_VERSION  (0U)
#define I2C_AR_RELEASE_REVISION_VERSION  (3U)

#define I2C_SW_MAJOR_VERSION   (1U)
#define I2C_SW_MINOR_VERSION   (1U)
#define I2C_SW_PATCH_VERSION   (0U)

#define I2C_DEV_ERROR_DETECT      (STD_OFF)

#define I2C_VERSION_INFO_API      (STD_ON)

#define I2C_HW_STATUS_API      (STD_ON)

#define I2C_PB_FIXEDADDR      (STD_OFF)

#define I2C_ASYNC_NOTIFICATION       (STD_OFF)

#define I2C_RESET_SFR_INIT       (STD_OFF)


/*
Configuration: I2C_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
#define I2C_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)

/*
Configuration: I2C_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
#define  I2C_USER_MODE_INIT_API_ENABLE (STD_OFF)

/*Configuration: I2C_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
#define  I2C_USER_MODE_DEINIT_API_ENABLE (STD_OFF)

/*Configuration: I2C_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
#define  I2C_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)

#define I2C_CANCEL_API      (STD_ON)


#define I2C_MAX_PACKET  (6U)

#define I2C_MAX_HW_UNIT  (1U)

#define I2C_I2C0_EXIST  (STD_ON)

#define I2C_I2C1_EXIST  (STD_OFF)




  #define I2C_ASYNC_READ_WRITE   (STD_OFF)


#define I2C_CONFIG_COUNT  (1U)

#define I2C_MAX_QUEUE   (0U)

#define I2C_CLOCK_CTRL_1_SLEEP_DIS   (0x00000108U)

#define I2C_CLOCK_CTRL_1_SLEEP_EN    (0x00000100U)

#endif  /* I2C_CFG_H */

