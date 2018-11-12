/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. This is a demo file and the contents of this file            **
** if required shall be modified by the customer.                             **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Hssl_Protect.h $                                           **
**                                                                            **
**   $CC VERSION : \main\4 $                                                  **
**                                                                            **
**   $DATE       : 2016-08-03 $                                               **
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

#ifndef  HSSL_PROTECT_CFG_H
#define  HSSL_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Hssl_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_HSSL                (130U)
#if (HSSL_USER_MODE_INIT_API_ENABLE == STD_ON)
#define HSSL_INIT_RESETENDINIT()        TRUSTED_ApplResetEndInit()
#define HSSL_INIT_SETENDINIT()          TRUSTED_ApplSetEndInit()
#define HSSL_INIT_WRITE32(reg,value)  \
                                   OS_WritePeripheral32((OS_AREA_DRV_HSSL), \
                           (volatile uint32*)(volatile void*)(&(reg)),(value))
#define HSSL_INIT_READ32(reg)       OS_ReadPeripheral32((OS_AREA_DRV_HSSL),  \
                                   (volatile uint32*)(volatile void*)(&(reg)))
#define HSSL_INIT_MODIFY32(reg,clearmask,setmask) \
                                    OS_ModifyPeripheral32((OS_AREA_DRV_HSSL),\
      (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
  #if (HSSL_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define HSSL_INIT_USER_MODE_OS_API_WRITE32(reg, value)                       \
                                       OS_WritePeripheral32((OS_AREA_DRV_HSSL),\
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  #define HSSL_INIT_USER_MODE_OS_API_READ32(reg)                               \
                                        OS_ReadPeripheral32((OS_AREA_DRV_HSSL),\
                                     (volatile uint32*)(volatile void*)(&(reg)))
  #define HSSL_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)           \
                                      OS_ModifyPeripheral32((OS_AREA_DRV_HSSL),\
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
  #endif
#endif /* HSSL_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (HSSL_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
#define HSSL_RUNTIME_RESETENDINIT()     TRUSTED_ApplResetEndInit()
#define HSSL_RUNTIME_SETENDINIT()       TRUSTED_ApplSetEndInit()
#define HSSL_RUNTIME_WRITE32(reg, value)                                       \
                                       OS_WritePeripheral32((OS_AREA_DRV_HSSL),\
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
#define HSSL_RUNTIME_READ32(reg)      OS_ReadPeripheral32((OS_AREA_DRV_HSSL),  \
                                    (volatile uint32*)(volatile void*)(&(reg)))
#define HSSL_RUNTIME_MODIFY32(reg,clearmask,setmask) \
                                  OS_ModifyPeripheral32((OS_AREA_DRV_HSSL),\
            (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMAGETTRANSREQLOSTFLAG(val)  \
                                      (TRUSTED_Mcal_DmaGetTransReqLostFlag(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMAGETTRANSFERINTSTATUS(val)\
                                     (TRUSTED_Mcal_DmaGetTransferIntStatus(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMADISABLEINTR(val) (TRUSTED_Mcal_DmaDisableIntr(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(val) \
                                      (TRUSTED_Mcal_DmaChClrIntctEtrlFlags(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMACHCLRINTRFLAGS(val) \
                                           (TRUSTED_Mcal_DmaChClrIntrFlags(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMACLRERRFLAGS(val) (TRUSTED_Mcal_DmaClrErrFlags(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_SETATOMIC(reg,val1,val2,val3) \
                                    (TRUSTED_Mcal_SetAtomic(reg,val1,val2,val3))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMACFGINTCONTROL(channel,val) \
                                    (TRUSTED_Mcal_DmaCfgIntControl(channel,val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMAENABLECHINTRTRIGGER(channel)\
                                 (TRUSTED_Mcal_DmaEnableChIntrTrigger(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMADISABLECHINTRTRIGGER(channel)\
                                (TRUSTED_Mcal_DmaDisableChIntrTrigger(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMAENABLEINTR(channel) \
                                          (TRUSTED_Mcal_DmaEnableIntr(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMASETDESTADDR(channel,reg)\
                                      (TRUSTED_Mcal_DmaSetDestAddr(channel,reg))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMASETADICR(channel,val)\
                                 (TRUSTED_Mcal_DmaSetAdicr(channel,val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMASETTXCOUNT(channel,val)\
                                  (TRUSTED_Mcal_DmaSetTxCount(channel,val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMASETDATAWIDTH(channel,val)\
                                 (TRUSTED_Mcal_DmaSetDataWidth(channel,val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMASETSOURCEADDR(channel,reg) \
                                  (TRUSTED_Mcal_DmaSetSourceAddr(channel,reg))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMAENABLEHWTRANSFER(channel)\
                                (TRUSTED_Mcal_DmaEnableHwTransfer(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMACFGNOOFMOVESPERTRANSFER(channel,val)\
                    (TRUSTED_Mcal_DmaCfgNoOfMovesPerTransfer((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMAENTRANSREQLOSTINTR(channel)\
                                (TRUSTED_Mcal_DmaEnTransReqLostIntr(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_RUNTIME_MCAL_DMASTARTTRANSACTION(channel)\
                                (TRUSTED_Mcal_DmaStartTransaction(channel))
#if (HSSL_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define HSSL_RUNTIME_USER_MODE_OS_API_WRITE32(reg,value)                    \
                                       OS_WritePeripheral32((OS_AREA_DRV_HSSL),\
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  #define HSSL_RUNTIME_USER_MODE_OS_API_READ32(reg)                            \
                                        OS_ReadPeripheral32((OS_AREA_DRV_HSSL),\
                                     (volatile uint32*)(volatile void*)(&(reg)))
  #define HSSL_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)        \
                    OS_ModifyPeripheral32((OS_AREA_DRV_HSSL),(volatile uint32*)\
                                (volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* HSSL_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */
#endif