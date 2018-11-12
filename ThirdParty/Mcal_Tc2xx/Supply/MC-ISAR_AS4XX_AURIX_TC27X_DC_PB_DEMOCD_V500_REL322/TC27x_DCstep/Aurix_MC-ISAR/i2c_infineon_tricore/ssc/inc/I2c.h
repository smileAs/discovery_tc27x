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
**  $FILENAME   : I2c.h $                                                    **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  $DATE       : 2016-07-29 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                functionality of I2C driver.                                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEABILITY : [cover parentID=] [/cover]                                 **
**                                                                            **
*******************************************************************************/

#ifndef I2C_H
#define I2C_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h  */
#include "Std_Types.h"

#include "Mcal.h"
#include "Mcal_DmaLib.h"
#include "IfxI2c_bf.h"
#include "IfxSrc_bf.h"
/* Pre-compile/static configuration parameters for I2C  */
#include "I2c_Cfg.h"

/* Conditional Inclusion of Developement Error Tracer File */
#if (I2C_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

#if ((I2C_USER_MODE_INIT_API_ENABLE == STD_ON)    || \
     (I2C_USER_MODE_RUNTIME_API_ENABLE == STD_ON) || \
     (I2C_USER_MODE_DEINIT_API_ENABLE == STD_ON)  || \
     (I2C_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
#include "I2c_Protect.h"
#endif  
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define I2C_INSTANCE_ID            ((uint8)0U)

#define I2C_VENDOR_ID              (17U)
#define I2C_MODULE_ID              (255U)

#define I2C_ZERO                   ((uint8)0U)
#define I2C_ONE                    ((uint8)1U)
#define I2C_TWO                    ((uint8)2U)
#define I2C_INVALID                ((uint8)0xFFu)


#if (I2C_DEV_ERROR_DETECT == STD_ON)
/* Development errors */

/*API Service called with wrong parameter.Config is a null pointer */
#define I2C_E_PARAM_CONFIG           ((uint8)0x00)
/*API Service called with wrong parameter.*/
#define I2C_E_PARAM_PACKET           ((uint8)0x01)
/*API Service called with wrong parameter.*/
#define I2C_E_PARAM_OPERATION        ((uint8)0x02)
/*API Service called with wrong parameter.*/
#define I2C_E_PARAM_UNIT             ((uint8)0x03)
/*API Service called with NULL parameter.*/
#define I2C_E_PARAM_POINTER          ((uint8)0x04)
/*API Service used without initialization */
#define I2C_E_UNINIT                 ((uint8)0x05)
/*Synchronous transmission service called at wrong parameter.*/
#define I2C_E_PACKET_UNDER_PROCESS   ((uint8)0x06)
/* I2C driver is already initialized */
#define I2C_E_ALREADY_INITIALIZED    ((uint8)0x07)
/* I2C Packet is not initialized */
#define I2C_E_PACKET_NOT_INITIALIZED ((uint8)0x08)
/* I2C peirpheral is busy */
#define I2C_E_HW_UNIT_BUSY           ((uint8)0x09)
/* End of Development errors */

/* API Service ID's */

/* API Service ID for () */
#define I2C_SID_INIT                 ((uint8)0x00)
/* API Service ID for () */
#define I2C_SID_DEINIT               ((uint8)0x01)
/* API Service ID for () */
#define I2C_SID_SETUPPACKET          ((uint8)0x02)
/* API Service ID for () */
#define I2C_SID_SYNCOPERATION        ((uint8)0x03)
/* API Service ID for () */
#define I2C_SID_ASYNCOPERATION       ((uint8)0x04)
/* API Service ID for () */
#define I2C_SID_GETSTATUS            ((uint8)0x05)
/* API Service ID for () */
#define I2C_SID_GETPACKETRESULT      ((uint8)0x06)
/* API Service ID for () */
#define I2C_SID_GETVERSIONINFO       ((uint8)0x07)
/* API Service ID for () */
#define I2C_SID_GETHWUNIITSTATUS     ((uint8)0x08)
/* API Service ID for () */
#define I2C_SID_CANCEL               ((uint8)0x09)

/* End of API Service ID's */

#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

/* Macros to define the SFR mask values */
#define I2C_KRST0_SFR_MSK         (0x00000002U)
#define I2C_KRST1_SFR_MSK         (0x00000001U)
#define I2C_KRSTCLR_SFR_MSK       (0x00000001U)
#define I2C_IMSC_SFR_MSK          (0x0000001FU)
#define I2C_PIRQSM_SFR_MSK        (0x0000005FU)
#define I2C_SRC_SRCR_MSK          (0x7F3F18FFU)
#define I2C_CLC_SFR_MSK           (0x00000002U)

/*
  The below Macros are used when INIT API is executed in User-1 mode
*/
#if (I2C_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_RESETENDINIT()                  I2C_INIT_RESETENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_SETENDINIT()                      I2C_INIT_SETENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_WRITE32(reg,value)      I2C_INIT_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_MODIFY32(reg,clearmask,setmask)                       \
                                I2C_INIT_MODIFY32((reg),(clearmask),(setmask))
/*
  The below Macros are used when INIT API is executed in User-0 mode
*/
#if (I2C_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_INIT_USER_MODE_WRITE32(reg,value)                          \
                              I2C_INIT_USER_MODE_OS_API_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_INIT_USER_MODE_READ32(reg)                                 \
                                       I2C_INIT_USER_MODE_OS_API_READ32((reg))
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_INIT_USER_MODE_WRITE32(reg,value)                          \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_INIT_USER_MODE_READ32(reg)                             (reg)
#endif /* I2C_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */
/*
  The below Macros are used when INIT API is executed in SV mode
*/
#else
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_RESETENDINIT()                        Mcal_ResetENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_SETENDINIT()                            Mcal_SetENDINIT()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_WRITE32(reg,value)               \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_MODIFY32(reg,clearmask,setmask)                         \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_USER_MODE_WRITE32(reg,value)                 \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_INIT_USER_MODE_READ32(reg)                               (reg)
#endif /* I2C_USER_MODE_INIT_API_ENABLE == STD_ON  */

/*
  The below Macros are used when RUNTIME API is executed in User-1 mode
*/
#if (I2C_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_RUNTIME_WRITE32(reg,value)    I2C_RUNTIME_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask)                      \
                              I2C_RUNTIME_MODIFY32((reg),(clearmask),(setmask))
/*
  The below Macros are used when RUNTIME APIs is executed in User-0 mode
*/
#if (I2C_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)                       \
                           I2C_RUNTIME_USER_MODE_OS_API_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_RUNTIME_USER_MODE_READ32(reg)                              \
                                    I2C_RUNTIME_USER_MODE_OS_API_READ32((reg))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)          \
            I2C_RUNTIME_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)                       \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_RUNTIME_USER_MODE_READ32(reg)                          (reg)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)          \
  { uint32 (val) ; (val) = (reg); (val) &= (clearmask); (val) |= (setmask);    \
                                                                (reg) = (val);}
#endif /* I2C_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */

/*
  The below Macros are used when RUNTIME APIs is executed in SV mode
*/
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_RUNTIME_WRITE32(reg,value)       ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask)                        \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)                         \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_RUNTIME_USER_MODE_READ32(reg)                           (reg)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)          \
      { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask);                 \
      (val) |= (setmask);(reg) = (val);}
#endif /* I2C_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */

/*
  The below Macros are used when DEINIT API is executed in User-1 mode
*/
#if (I2C_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_DEINIT_RESETENDINIT()              I2C_DEINIT_RESETENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_DEINIT_SETENDINIT()                  I2C_DEINIT_SETENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_DEINIT_MODIFY32(reg,clearmask,setmask)                       \
                              I2C_DEINIT_MODIFY32((reg),(clearmask),(setmask))

/*
  The below Macros are used when DEINIT API is executed in User-0 mode
*/
#if (I2C_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_DEINIT_USER_MODE_WRITE32(reg,value)                          \
                              I2C_DEINIT_USER_MODE_OS_API_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_DEINIT_USER_MODE_READ32(reg)                               \
                                     I2C_DEINIT_USER_MODE_OS_API_READ32((reg))
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_DEINIT_USER_MODE_WRITE32(reg,value)                          \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define I2C_SFR_DEINIT_USER_MODE_READ32(reg)                           (reg)
#endif /* I2C_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */

/*
  The below Macros are used when DEINIT API is executed in SV mode
*/
#else
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_DEINIT_RESETENDINIT()                      Mcal_ResetENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_DEINIT_SETENDINIT()                          Mcal_SetENDINIT()
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_DEINIT_MODIFY32(reg,clearmask,setmask)                       \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_DEINIT_USER_MODE_WRITE32(reg,value)                 \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define I2C_SFR_DEINIT_USER_MODE_READ32(reg)                             (reg)
#endif /* I2C_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef uint8 I2c_DataType;

/*
Type : I2c_StatusType
This type defines a range of specific status for I2C Driver.
It informs about the I2C Driver status and can be obtained
calling the API service I2c_GetStatus.
*/
typedef enum I2c_StatusType
{
  /* The I2C Driver is not initialized. */
  I2C_UNINIT = 0,
  /* The I2C Driver is idle. */
  I2C_IDLE,
  /* The I2C Driver is performing busy. */
  I2C_BUSY
}I2c_StatusType;

/*
Type : I2c_PacketResultType
This type defines a range of packet status for I2C Driver.
It informs about a I2C Driver packet status and can be obtained calling the
API service I2c_GetSequenceResult with the packet ID.
*/
typedef enum I2c_PacketResultType
{
  /* The last jpjptbd is successful.*/
  I2C_PACKET_OK = 0,
  /* The I2c packet is in the queue */
  I2C_PACKET_QUEUED,
  /* The I2c packet is under processing */
  I2C_PACKET_PENDING,
  /*The jpjptbd has failed.*/
  I2C_PACKET_FAILED,
  /*The jpjptbd is cancelled by user */
  I2C_PACKET_CANCELLED,
  /*The jpjptbd is cancelled by user */
  I2C_PACKET_INVALID
}I2c_PacketResultType;

typedef enum I2c_OperationType
{
  I2C_WRITE = 0,
  I2C_READ,
  I2C_DUMMY_WRITE,
  I2C_NO_OPERATION
}I2c_OperationType;

#if (I2C_ASYNC_READ_WRITE == STD_ON)
typedef enum I2c_HwUnitPacketStatusType
{
  I2C_HWUNIT_PKT_OK = 0,
  I2C_HWUNIT_PKT_STARTED,
  I2C_HWUNIT_PKT_LAST_SINGLE_RCVD,
  I2C_HWUNIT_PKT_NOT_OK,
  I2C_HWUNIT_PKT_INVALID,
}I2c_HwUnitPacketStatusType;
#endif

typedef enum I2c_CommunicationType
{
  I2C_COMMN_SYNCHRONOUS = 0,
  I2C_COMMN_ASYNCHRONOUS,
  I2C_COMMN_INVALID,
}I2c_CommunicationType;

typedef struct I2c_PacketInfoType
{
  I2c_DataType *NativeDataPtr;
  I2c_OperationType Operation;
}I2c_PacketInfoType;


typedef uint8 I2c_PacketType;

typedef uint16 I2c_NumberOfDataType;

typedef uint8 I2c_HWUnitType;

typedef void(*I2c_NotifFunctionPtrType)(I2c_PacketType Packet);

typedef struct I2c_PacketConfigType
{
  const uint8 Address;

  const I2c_NumberOfDataType Length;

  const I2c_HWUnitType HwUnit;

  const uint8 DeviceAddress;
  
  const uint32 AdddressCfgValue;

  const uint32 FracDividerCfgValue;

  const uint32 TimingCfgvalue;

  const uint32 FIFOCfgValue;

  const uint8  PortPinCfgvalue;

}I2c_PacketConfigType;

typedef struct I2c_HWModuleConfigType
{
  const uint32  HWClkSetting;

}I2c_HWModuleConfigType;


typedef struct I2c_ConfigType
{
  const I2c_PacketConfigType* I2cPacketConfigPtr;

  const I2c_HWModuleConfigType* HWModuleConfigPtr;

  const I2c_HWUnitType HwUnitQueueLowestIndex[I2C_MAX_HW_UNIT];

  const I2c_HWUnitType HwUnitQueueIndex[I2C_MAX_HW_UNIT];

  I2c_PacketType NoOfPackets;

} I2c_ConfigType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define I2C_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/* Declaration of I2C Post Build Configuration */
extern const struct I2c_ConfigType I2c_ConfigRoot[I2C_CONFIG_COUNT];

#define I2C_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define I2C_START_SEC_CODE
/* IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor
   directives is allowed only for MemMap.h */
#include "MemMap.h"
extern void I2c_Init(const I2c_ConfigType* ConfigPtr);
extern Std_ReturnType I2c_DeInit(void);
extern I2c_StatusType I2c_GetHWUnitStatus(I2c_HWUnitType HwUnit);
extern I2c_StatusType I2c_GetStatus(void);
extern Std_ReturnType I2c_SetupPacket(I2c_PacketType Packet, \
                                                   I2c_DataType *NativeDataPtr);
extern I2c_PacketResultType I2c_GetPacketResult(I2c_PacketType Packet);
extern Std_ReturnType I2c_SyncOperation \
                        (I2c_PacketType Packet, I2c_OperationType Operation);
#if (I2C_ASYNC_READ_WRITE == STD_ON)
extern Std_ReturnType I2c_AsyncOperation \
                        (I2c_PacketType Packet, I2c_OperationType Operation);
#endif

#if ((I2C_ASYNC_READ_WRITE == STD_ON) && (I2C_CANCEL_API == STD_ON))
extern void I2c_Cancel(I2c_PacketType Packet);
#endif
#if (I2C_ASYNC_READ_WRITE == STD_ON)
extern void I2c_IsrI2cProtocol(I2c_HWUnitType HwUnit);
#endif

#define I2C_STOP_SEC_CODE
/* IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor
 directives is allowed only for MemMap.h */
#include "MemMap.h"
/*******************************************************************************
**                      Global Function Declarations:                         **
**             Functions to be Called From Interrupt/Scheduler Context        **
*******************************************************************************/


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#if (I2C_VERSION_INFO_API == STD_ON)
/* IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand 
 to a braced initialiser */
/* IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared 
 as function like macro as per AUTOSAR. */
#define  I2c_GetVersionInfo(VersionInfoPtr)                                 \
{                                                                           \
  if ((VersionInfoPtr) == NULL_PTR)                                           \
  {                                                                         \
    /* Report to DET */                                                     \
    Det_ReportError(                                                        \
                     (uint16)I2C_MODULE_ID,                                 \
                     I2C_INSTANCE_ID,                                       \
                     I2C_SID_GETVERSIONINFO,                                \
                     I2C_E_PARAM_POINTER                                    \
                   );                                                       \
  }                                                                         \
  else                                                                      \
  {                                                                         \
    /* Note that versioninfo pointer is not checked for NULL as the user    \
       is supposed to send the memory allocated pointer */                  \
    /* I2C Module ID */                                                     \
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = I2C_MODULE_ID;     \
    /* I2C vendor ID */                                                     \
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = I2C_VENDOR_ID;     \
    /* major version of I2C */                                              \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =            \
                                            (uint8)I2C_SW_MAJOR_VERSION;    \
    /* minor version of I2C */                                              \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =            \
                                            (uint8)I2C_SW_MINOR_VERSION;    \
    /* patch version of I2C */                                              \
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =            \
                                            (uint8)I2C_SW_PATCH_VERSION;    \
  }                                                                         \
}
#else /* (I2C_VERSION_INFO_API == STD_ON) */
#define I2c_GetVersionInfo(VersionInfoPtr)  ERROR_I2c_VersionInfo_NOT_SELECTED
#endif /* (I2C_VERSION_INFO_API == STD_ON) */

#endif /* I2C_H */

