/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Hssl.h $                                                   **
**                                                                            **
**  $CC VERSION : \main\29 $                                                 **
**                                                                            **
**  $DATE       : 2016-09-27 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file exports                                           **
**                functionality of HSSL driver.                               **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
*******************************************************************************/
#ifndef HSSL_H
#define HSSL_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
#include "Mcal.h"
#include "Mcal_DmaLib.h"
#include "Hssl_Cfg.h"

#if ( HSSL_DEV_ERROR_DETECT == STD_ON)
/* Import of DET functionality */
#include "Det.h"
#endif  /* End Of HSSL_DEV_ERROR_DETECT */

#if ((HSSL_USER_MODE_INIT_API_ENABLE == STD_ON) || \
       (HSSL_USER_MODE_RUNTIME_API_ENABLE == STD_ON))
  #include "Hssl_Protect.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
  /* Development Error values */
#if (HSSL_DEV_ERROR_DETECT == STD_ON)

/* Return value when Development Error found*/
#define HSSL_ERR_FOUND          (1U)
/* Return value when Development error is not found*/
#define HSSL_ERR_NOT_FOUND      (0U)
/* HSSL module instance ID to be used in Det_ReportError*/
#define HSSL_MODULE_INSTANCE    (0U)

/* Development error codes */
/* Service is called before Init */
#define HSSL_E_NOT_INITIALIZED  (1U)
/* Service is called with NULL pointer */
#define HSSL_E_INV_POINTER      (2U)
/* Service is called with invalid parameter */
#define HSSL_E_INV_PARAM        (3U)
/* Service is called in an Invalid driver Mode */
#define HSSL_E_INV_MODE         (4U)

/*Module Identification, Vendor Identification*/
  /* HSSL Module ID */
#define HSSL_MODULE_ID            ((uint16)255U)
  /* HSSL Vendor ID */
#define HSSL_VENDOR_ID            (17U)
  /* HSSL Instance ID */
#define HSSL_INSTANCE_ID          (0U)

/*Service ID number for all HSSL driver services */
/* Service ID for Hssl_SetMode */
#define HSSL_SID_MODE             (1U)
/* Service ID for Hssl_Reset */
#define HSSL_SID_RESET            (2U)
/* Service ID for Hssl_Init */
#define HSSL_SID_INIT             (3U)
/* Service ID for Hssl_InitChannel */
#define HSSL_SID_INIT_CH          (4U)
/* Service ID for Hssl_Write */
#define HSSL_SID_WRITE            (5U)
/* Service ID for Hssl_WriteAck */
#define HSSL_SID_WRITE_ACK        (6U)
/* Service ID for Hssl_Read */
#define HSSL_SID_READ             (7U)
/* Service ID for Hssl_ReadReply */
#define HSSL_SID_READ_REPLY       (8U)
/* Service ID for Hssl_Id */
#define HSSL_SID_READ_ID          (9U)
/* Service ID for Hssl_StartStream */
#define HSSL_SID_STREAM           (10U)
/* Service ID for Hssl_StopStream */
#define HSSL_SID_STREAM_STOP      (11U)
/* Service ID for Hssl_MultiWrite */
#define HSSL_SID_WRITE_MULTIPLE   (12U)
/* Service ID for Hssl_MultiRead */
#define HSSL_SID_READ_MULTIPLE    (13U)
/* Service ID for Hssl_GetGlobalError */
#define HSSL_SID_GET_GLOBALERROR  (14U)

#endif  /* End of (HSSL_DEV_ERROR_DETECT == STD_ON) */

#define HSSL_NO_ACCESS            ((uint32)0)
#define HSSL_READ_ACCESS          ((uint32)1)
#define HSSL_WRITE_ACCESS         ((uint32)2)
#define HSSL_READ_WRITE_ACCESS    ((uint32)3)

/* Driver States */
#define HSSL_DRIVER_UNINITIALIZED (0U)
#define HSSL_DRIVER_INITIALIZED   (1U)

/* HSSL Modes */
#define HSSL_MODE_DISABLE        ((uint8)(0U))
#define HSSL_MODE_INIT           ((uint8)(1U))
#define HSSL_MODE_RUN            ((uint8)(2U))

/* HSSL Commands */
#define HSSL_READ_FRAME          ((uint8)(1U))
#define HSSL_WRITE_FRAME         ((uint8)(2U))

#define HSSL_NUM_CHANNEL         (4U)

/* Possible data size values */
#define HSSL_DATA_SIZE_8BIT      (0U)
#define HSSL_DATA_SIZE_16BIT     (1U)
#define HSSL_DATA_SIZE_32BIT     (2U)
#define HSSL_MAX_DATA_SIZE       (3U)

/*Enable HSSL module */
#define HSSL_MOD_ENABLE            (0U)

#if (HSSL_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_RESETENDINIT()           (HSSL_INIT_RESETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_SETENDINIT()             (HSSL_INIT_SETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_WRITE32(reg,value)    (HSSL_INIT_WRITE32((reg),(value)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_READ32(reg)              (HSSL_INIT_READ32(reg))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define HSSL_SFR_INIT_MODIFY32(reg,clearmask,setmask)     \
                               HSSL_INIT_MODIFY32((reg),(clearmask),(setmask))
#if (HSSL_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define HSSL_SFR_INIT_USER_MODE_WRITE32(reg, value)        \
                           (HSSL_INIT_USER_MODE_OS_API_WRITE32((reg),(value)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define HSSL_SFR_INIT_USER_MODE_READ32(reg)                 \
                                      (HSSL_INIT_USER_MODE_OS_API_READ32(reg))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define HSSL_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
              HSSL_INIT_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))
  #else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define HSSL_SFR_INIT_USER_MODE_WRITE32(reg, value)        ((reg) = (value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define HSSL_SFR_INIT_USER_MODE_READ32(reg)                   (reg)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define HSSL_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
       { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
#endif /* HSSL_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_RESETENDINIT()                   (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_WRITE32(reg, value)               ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_READ32(reg)                      (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define HSSL_SFR_INIT_MODIFY32(reg, clearmask,setmask) \
     { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_SETENDINIT()                      (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_USER_MODE_WRITE32(reg, value)      ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_INIT_USER_MODE_READ32(reg)             (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define HSSL_SFR_INIT_USER_MODE_MODIFY32(reg, clearmask ,setmask)  \
     { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
#endif /* HSSL_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (HSSL_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_RESETENDINIT()         (HSSL_RUNTIME_RESETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_SETENDINIT()           (HSSL_RUNTIME_SETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_WRITE32(reg,value) \
                                        (HSSL_RUNTIME_WRITE32((reg),(value)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_READ32(reg)            (HSSL_RUNTIME_READ32(reg))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define HSSL_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask)   \
                           HSSL_RUNTIME_MODIFY32((reg),(clearmask),(setmask))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(val)  \
                               (HSSL_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(val)  \
                                    (HSSL_RUNTIME_MCAL_DMACHCLRINTRFLAGS(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMACFGINTCONTROL(channel,val)  \
                         (HSSL_RUNTIME_MCAL_DMACFGINTCONTROL((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMAENABLECHINTRTRIGGER(channel)  \
                           (HSSL_RUNTIME_MCAL_DMAENABLECHINTRTRIGGER(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETDESTADDR(channel,reg)  \
                           (HSSL_RUNTIME_MCAL_DMASETDESTADDR((channel),(reg)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETADICR(channel,val)\
                              (HSSL_RUNTIME_MCAL_DMASETADICR((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETTXCOUNT(channel,val)  \
                            (HSSL_RUNTIME_MCAL_DMASETTXCOUNT((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETDATAWIDTH(channel,val)  \
                          (HSSL_RUNTIME_MCAL_DMASETDATAWIDTH((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMAENABLEHWTRANSFER(channel)  \
                             (HSSL_RUNTIME_MCAL_DMAENABLEHWTRANSFER(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETSOURCEADDR(channel,val)  \
                        (HSSL_RUNTIME_MCAL_DMASETSOURCEADDR((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMACFGNOOFMOVESPERTRANSFER(channel,val)  \
               (HSSL_RUNTIME_MCAL_DMACFGNOOFMOVESPERTRANSFER((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMAENTRANSREQLOSTINTR(channel)  \
                         (HSSL_RUNTIME_MCAL_DMAENTRANSREQLOSTINTR(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASTARTTRANSACTION(channel)  \
                         (HSSL_RUNTIME_MCAL_DMASTARTTRANSACTION(channel))

#if (HSSL_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
    calls definition, it is declared as a function like macro*/
    #define HSSL_SFR_RUNTIME_USER_MODE_WRITE32(reg,value) \
                       (HSSL_RUNTIME_USER_MODE_OS_API_WRITE32((reg),(value)))
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
    calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
    modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
    #define HSSL_SFR_RUNTIME_USER_MODE_READ32(reg)        \
                                   (HSSL_RUNTIME_USER_MODE_OS_API_READ32(reg))
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
    calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
    modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
    #define HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask) \
           HSSL_RUNTIME_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))
#else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define HSSL_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)    ((reg) = (value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define HSSL_SFR_RUNTIME_USER_MODE_READ32(reg)                 (reg)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(reg, clearmask ,setmask) \
    { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
#endif /* HSSL_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_RESETENDINIT()           (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_WRITE32(reg, value)       ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_READ32(reg)              (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define HSSL_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask)\
    {uint32 val ; (val) = (reg) ; (val) &= (clearmask);\
                                           (val) |= (setmask); (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_SETENDINIT()              (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)     ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_USER_MODE_READ32(reg)      (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)  \
    { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETSOURCEADDR(channel,reg)  \
                                       (Mcal_DmaSetSourceAddr((channel),(reg)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(val)  \
                                            (Mcal_DmaChClrIntctEtrlFlags(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(val)  \
                                            (Mcal_DmaChClrIntrFlags(val))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMACFGINTCONTROL(channel,val)  \
                                      (Mcal_DmaCfgIntControl((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMAENABLECHINTRTRIGGER(channel)  \
                                        (Mcal_DmaEnableChIntrTrigger(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETDESTADDR(channel,reg)  \
                                        (Mcal_DmaSetDestAddr((channel),(reg)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETADICR(channel,val)  \
                                           (Mcal_DmaSetAdicr((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETTXCOUNT(channel,val)  \
                                         (Mcal_DmaSetTxCount((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASETDATAWIDTH(channel,val)  \
                                       (Mcal_DmaSetDataWidth((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMAENABLEHWTRANSFER(channel)  \
                                           (Mcal_DmaEnableHwTransfer(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMACFGNOOFMOVESPERTRANSFER(channel,val)  \
                             (Mcal_DmaCfgNoOfMovesPerTransfer((channel),(val)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMAENTRANSREQLOSTINTR(channel)  \
                                         (Mcal_DmaEnTransReqLostIntr(channel))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define HSSL_SFR_RUNTIME_MCAL_DMASTARTTRANSACTION(channel)  \
                                           (Mcal_DmaStartTransaction(channel))
#endif /* HSSL_USER_MODE_RUNTIME_API_ENABLE = STD_ON */

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef struct Hssl_DataTemplateType
{
  uint32 *Data;
  uint32 *Address;
}Hssl_DataTemplateType;


/* Hssl_ChannelType structure should be utilised as a 4 element array
 in the application (for HSSL Channels 1-4)*/
typedef struct Hssl_ChannelType
{
  uint8 Number;
  uint32 Timeout;
}Hssl_ChannelType;

#define HSSL_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
** Syntax : uint8 Hssl_Init(uint16 ClockPreDivider)                           **
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ClockPreDivider: Integer representation of Prescale     **
**                    for Timeout Clock.Default is 64.                        **
**                    Can be 64, 128, 256, 512 or 1024.                       **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, error code otherwise.        **
**                                                                            **
** Description : Initializes Initiator / Target side of HSSL module.          **
**               setting HSSLMCR with clk prescale, Mode etc.                 **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_Init (uint16 ClockPreDivider );

/*******************************************************************************
** Syntax : uint8 Hssl_Reset(void)                                            **
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, error code otherwise.        **
**                                                                            **
** Description : Performs Kernel reset of module,clears all status and error  **
**               registers,disables module clock and sets drive module        **
**               Any transfers in progress when reset is called               **
**               will immediately end.                                        **
**                                       **
*******************************************************************************/
extern uint8 Hssl_Reset(void) ;

/*******************************************************************************
** Syntax : uint8 Hssl_SetMode(uint8 Mode)                                    **
**                                                                            **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  Mode                                                    **
**                    0 = Disabled, 1 = Enabled/Init, 2 = Enabled/Run         **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, error code otherwise.        **
**                                                                            **
** Description : Puts the HSSL module into the required mode. Must be used    **
**               to place module into 'INIT' mode before calling the          **
**               initialization functions.                                    **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_SetMode(uint8 Mode) ;

/*******************************************************************************
** Syntax : uint8 Hssl_InitChannel(Hssl_ChannelType Channel,uint8 WriteAck,   **
**     uint8 ReadAns,  uint8 Trigger, uint8 TimeoutErr, uint8 TransID,        **
**     uint8 AckErr)                                                          **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  Channel : HSSL Channel to use.                          **
**                    WriteAck: Enable/Disable Write Acknowledge interrupt    **
**                    ReadAns: Enable/Disable Read Answer interrupt.          **
**                    Trigger: Enable/Disable Trigger Command interrupt.      **
**                    TimeoutErr: Enable/Disable Timeout Error interrupt.     **
**                    TransID: Enable/Disable Transaction ID Error interrupt. **
**                    AckErr: Enable/Disable Acknowledge Error interrupt.     **
**   (0 to disable, 1 to enable)                                              **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, error code otherwise.        **
**                                                                            **
** Description : Initializes HSSL Channel. Also sets up interrupts.           **
**               events to handle received packets appropriately.             **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_InitChannel (Hssl_ChannelType Channel, uint8 WriteAck,
   uint8 ReadAns, uint8 Trigger,uint8 TimeoutErr, uint8 TransID, uint8 AckErr);

/*******************************************************************************
** Syntax : uint8 Hssl_Write( const Hssl_DataTemplateType *WriteData,         **
**                           uint16 DataSize, Hssl_ChannelType Channel,       **
**                           uint8 InjectedError)                             **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : WriteData :: Pointer to Hssl_DataTemplateType structure  **
**                    which includes write Address and Data to be written.    **
**                    DataSize:: Size of data to be written.                  **
**                    Channel:: HSSL Channel to use.                          **
**                    InjectedError: injected error (if required)             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, error code otherwise.        **
**                                                                            **
** Description : Performs a direct write transfer.                            **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_Write (const Hssl_DataTemplateType *WriteData,
       uint16 DataSize,Hssl_ChannelType Channel,uint8 InjectedError) ;

/*******************************************************************************
** Syntax : uint8 Hssl_WriteAck(Hssl_ChannelType Channel)                     **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : Channel:: HSSL Channel to use.                           **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, Error code otherwise.        **
**                                                                            **
** Description : Write acknowledge function, should be called when a          **
**               write acknowledge is received by the module, or a timeout    **
**               occurs during a write command.                               **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_WriteAck(Hssl_ChannelType Channel);

/*******************************************************************************
** Syntax : uint8 Hssl_Read (const Hssl_DataTemplateType *DataAddress,        **
**                           uint16 DataSize, Hssl_ChannelType Channel,       **
**                           uint8 InjectedError)                             **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  DataAddr : Pointer to Hssl_DataTemplateType structure   **
**                    which includes read Address                             **
**                    DataSize:: Size of data to be read.                     **
**                    Channel:: HSSL Channel to use.                          **
**                    InjectedError: injected Error (if required)             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, Error code otherwise.        **
**                                                                            **
** Description : Performs a direct Read transfer.                             **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_Read(const Hssl_DataTemplateType *DataAddress,
          uint16 DataSize,Hssl_ChannelType Channel,uint8 InjectedError) ;

/*******************************************************************************
** Syntax : uint8 Hssl_ReadRply  (const Hssl_DataTemplateType *ReadData,      **
**                         Hssl_ChannelType Channel)                          **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : ReadData : Pointer to Data_Template structure which      **
**                   includes the data read and the address                   **
**                   Channel:: HSSL Channel to use.                           **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, Error code otherwise.        **
**                                                                            **
** Description : Reply function which is called either when a successful      **
**               read reply is received, or when a timeout is reached.        **
**               If called due to a timeout then only the Channel and         **
**               Error parameters will be written.                            **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_ReadRply (const Hssl_DataTemplateType *ReadData,
                      Hssl_ChannelType Channel);

/*******************************************************************************
** Syntax : uint32 Hssl_Id(uint32 *StoreAddress)                              **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : *StoreAddress Pointer to the Address location/variable   **
**                   to store the ID received from target                     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, Error code otherwise.        **
**                                                                            **
** Description :  Sends ID Request Frame to target. Stores received command   **
**                in the  address passed.                                     **
**                                                                            **
*******************************************************************************/
extern uint32 Hssl_Id(uint32 *StoreAddress) ;

/*******************************************************************************
** Syntax : uint8 Hssl_StartStreams( uint32 *SourceAddressStart,              **
**                           uint16 DataSize, uint8 InjectedError)            **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  SourceAddressStart : Pointer to address containing start**
**                    of data to be streamed.                                 **
**                    DataSize:: Size of data to be written.                  **
**                    InjectedError: injected Error (if required)             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, Error code otherwise.        **
**                                                                            **
** Description : Performs streaming write transfer.                           **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_StartStream (uint32 *SourceAddressStart,
                 uint16 DataSize,uint8 InjectedError) ;

/*******************************************************************************
** Syntax : void Hssl_StopStream(void)                                        **
**                                                                            **
** Service ID:  0x0B                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    : None.                                                    **
**                                                                            **
** Description :  Stops the ongoing streaming                                 **
**                                                                            **
*******************************************************************************/
extern void Hssl_StopStream(void) ;

/*******************************************************************************
** Syntax : uint8 Hssl_MultiWrite( const Hssl_DataTemplateType *WriteData,    **
**                                 uint16 DataSize, uint16 NumCmd,            **
**                            Hssl_ChannelType Channel,uint8 InjectedError)   **
**                                                                            **
** Service ID:  0x0C                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  WriteArray : Hssl_DataTemplateType structure which      **
**                    includes array containing write Address and Data to be  **
**                    written for each array record.                          **
**                    DataSize:: Size of data to be written.                  **
**                    NumCmd : Number of address command pairs                **
**                    Channel:: HSSL Channel to use.                          **
**                    InjectedError: injected Error (if required)             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, Error code otherwise.        **
**                                                                            **
** Description : Performs multiple write transfers.                           **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_MultiWrite (const Hssl_DataTemplateType *WriteArray,
                   uint16 DataSize,uint16 NumCmd ,Hssl_ChannelType Channel,
                   uint8 InjectedError) ;

/*******************************************************************************
** Syntax : uint8 Hssl_MultiRead( const Hssl_DataTemplateType *ReadArray,     **
**                           uint16 DataSize, uint16 NumCmd ,                 **
**                           Hssl_ChannelType Channel,                        **
**                           uint8 InjectedError)                             **
**                                                                            **
** Service ID:  0x0D                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ReadArray : Hssl_DataTemplateType structure which       **
**                includes array containing write Address and Data to be read **
**                    for each array record.                                  **
**                    DataSize:: Size of data to be written.                  **
**                    NumCmd : Number of address command pairs                **
**                    Channel:: HSSL Channel to use.                          **
**                    InjectedError: injected Error (if required)             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, Error code otherwise.        **
**                                                                            **
** Description : Performs multiple Register Read                              **
**                                                                            **
*******************************************************************************/
extern uint8 Hssl_MultiRead (const Hssl_DataTemplateType *ReadArray,
               uint16 DataSize,uint16 NumCmd ,Hssl_ChannelType Channel,
               uint8 InjectedError) ;

/*******************************************************************************
** Syntax : uint32 Hssl_GetGlobalError(void)                                  **
**                                                                            **
** Service ID:  0x0E                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  uint32 (Global Error Value)                             **
**                                                                            **
** Description : Reads the global error status for the HSSL                   **
**                                                                            **
*******************************************************************************/
extern uint32 Hssl_GetGlobalError(void);

#define HSSL_STOP_SEC_CODE
#include "MemMap.h"


#endif  /* HSSL_H */
