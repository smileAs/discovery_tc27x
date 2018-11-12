/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Msc_Protect.h $                                            **
**                                                                            **
**   $CC VERSION : \main\4 $                                                  **
**                                                                            **
**   $DATE       : 2016-07-03 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file file define all the first level                  **
**                 indirection macros for Protected mode support              **
**                                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** Traceabilty      :                                                         **
**                                                                            **
*******************************************************************************/

#ifndef  MSC_PROTECT_CFG_H
#define  MSC_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Msc_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_MSC (0x01U)

#if (MSC_USER_MODE_INIT_API_ENABLE == STD_ON) 
#define MSC_INIT_WRITE32(reg, value)                                 OS_WritePeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(value))
#define MSC_INIT_MODIFY32(reg,clearmask,setmask)                     OS_ModifyPeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#define MSC_INIT_RESETENDINIT()                                 TRUSTED_ApplResetEndInit()
#define MSC_INIT_SETENDINIT()                                       TRUSTED_ApplSetEndInit()
#if (MSC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define MSC_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)   OS_ModifyPeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask))
  #define MSC_INIT_USER_MODE_OS_API_WRITE32(reg,value)                OS_WritePeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(value))
  #define MSC_INIT_USER_MODE_OS_API_READ32(reg)                           OS_ReadPeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)))
#endif                                                                       
#endif /* MSC_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (MSC_USER_MODE_DEINIT_API_ENABLE == STD_ON) 
#define MSC_DEINIT_WRITE32(reg, value)                                 OS_WritePeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(value))
#define MSC_DEINIT_MODIFY32(reg,clearmask,setmask)                     OS_ModifyPeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#define MSC_DEINIT_RESETENDINIT()                                 TRUSTED_ApplResetEndInit()
#define MSC_DEINIT_SETENDINIT()                                       TRUSTED_ApplSetEndInit()
#if (MSC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define MSC_DEINIT_USER_MODE_OS_API_READ32(reg)                           OS_ReadPeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)))
  #define MSC_DEINIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)     OS_ModifyPeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask))
#endif
#endif /* MSC_USER_MODE_DEINIT_API_ENABLE == STD_ON  */ 

#if (MSC_USER_MODE_RUNTIME_API_ENABLE == STD_ON) 
#define MSC_RUNTIME_WRITE32(reg, value)                                 OS_WritePeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(value))
#define MSC_RUNTIME_MODIFY32(reg,clearmask,setmask)                     OS_ModifyPeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#define MSC_RUNTIME_RESETENDINIT()                                 TRUSTED_ApplResetEndInit()
#define MSC_RUNTIME_SETENDINIT()                                       TRUSTED_ApplSetEndInit()
#if (MSC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define MSC_RUNTIME_USER_MODE_OS_API_WRITE32(reg,value)            OS_WritePeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(value))
  #define MSC_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)   OS_ModifyPeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask))
  #define MSC_RUNTIME_USER_MODE_OS_API_READ32(reg)                           OS_ReadPeripheral32(OS_AREA_DRV_MSC,(volatile uint32*)(volatile void*)(&(reg)))
#endif                                                                       
#endif /* MSC_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */
 #endif 