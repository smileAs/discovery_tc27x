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
**  $FILENAME   : I2c.c $                                                    **
**                                                                            **
**  $CC VERSION : \main\15 $                                                 **
**                                                                            **
**  $DATE       : 2016-08-05 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains functionality of I2C driver.             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "IfxI2c_reg.h"
#include "IfxSrc_reg.h"

/* Module header file. This also includes configuration file */
#include "I2c.h"

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/
#ifndef I2C_SW_MAJOR_VERSION
  #error "I2C_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef I2C_SW_MINOR_VERSION
  #error "I2C_SW_MINOR_VERSION is not defined. "
#endif

#ifndef I2C_SW_PATCH_VERSION
  #error "I2C_SW_PATCH_VERSION is not defined. "
#endif

#if (I2C_SW_MAJOR_VERSION != 1U)
  #error "I2C_SW_MAJOR_VERSION does not match. "
#endif

#if (I2C_SW_MINOR_VERSION != 1U)
  #error "I2C_SW_MINOR_VERSION does not match. "
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define I2C_QUEUE_EMPTY                     ((boolean)0x00U)
#define I2C_QUEUE_FILLED                    ((boolean)0x01U)

#define I2C_DRIVER_DEINITIALIZED            ((boolean)0x00U)
#define I2C_DRIVER_INITIALIZED              ((boolean)0x01U)

#define I2C_DISABLE_INTERFACE               ((uint32)0x00U)
#define I2C_ENABLE_INTERFACE                ((uint32)0x01U)

#define I2C_ERROR_INTR_STATUS_VALID_MSK     ((uint32)0x0000000FU)
#define I2C_PROTO_INTR_STATUS_VALID_MSK     ((uint32)0x00000018U)

#define I2C_CLEAR_INTERRUPT                 ((uint32)0x0000000FU)
#define I2C_CLEAR_PROTOCOL_INTERRUPT        ((uint32)0x0000007FU)
#define I2C_CLEAR_ERROR_INTERRUPT           ((uint32)0x0000000FU)

#define I2C_INIT_CLOCK_CTRL_1               ((uint32)0x00005000U)

#define I2C_SYNCTRANSMIT_TIMEOUT_CTR        ((uint16)0xFFFFU)

#define I2c_KERNEL_RESET_WAIT_COUNTS             (0x100U)

#define I2C_MODULE_X        ((volatile Ifx_I2C *)(void *) &(MODULE_I2C0))

#define I2C_REG_CLR_MASK                    (0xFFFFFFFFU)



/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                     Private Function Declarations:                         **
*******************************************************************************/
/*Memory Map of the I2C Code*/
#define I2C_START_SEC_CODE
#include "MemMap.h"

static void I2c_lHwInit(const I2c_ConfigType* ConfigPtr);
static void I2c_lHwDeInit(void);
IFX_LOCAL_INLINE boolean I2c_lHwGetModuleStatus(I2c_HWUnitType HwUnit);
IFX_LOCAL_INLINE Std_ReturnType I2c_lHwGetErrorStatus(const Ifx_I2C *HwUnitPtr);
IFX_LOCAL_INLINE void I2c_lInitHwClearAllInterrupts(I2c_HWUnitType HwUnit);
IFX_LOCAL_INLINE void I2c_lDeInitHwClearAllInterrupts(I2c_HWUnitType HwUnit);
IFX_LOCAL_INLINE void I2c_lRunTimeHwClearAllInterrupts(I2c_HWUnitType HwUnit);
IFX_LOCAL_INLINE I2c_StatusType I2c_lIsSyncHwUnitsStatus(void);
static Std_ReturnType I2c_lHwExecutePacket(I2c_PacketType Packet, \
                                                I2c_OperationType Operation);
#if (I2C_DEV_ERROR_DETECT == STD_ON)
IFX_LOCAL_INLINE Std_ReturnType I2c_lGetDetInitStatus(uint8 ApiId);
IFX_LOCAL_INLINE Std_ReturnType I2c_lGetDetPacketStatus \
                                        (uint8 ApiId, I2c_PacketType Packet);
IFX_LOCAL_INLINE Std_ReturnType I2c_lGetDetPktOperationStatus \
                                    (uint8 ApiId, I2c_OperationType Operation);
IFX_LOCAL_INLINE Std_ReturnType I2c_lGetDetPktInitializedStatus \
                                        (uint8 ApiId, I2c_PacketType Packet);
#endif
#if (I2C_ASYNC_READ_WRITE == STD_ON)
IFX_LOCAL_INLINE void I2c_lHwEnableProtocolTxEndIntr(I2c_HWUnitType HwUnit);
IFX_LOCAL_INLINE void I2c_lHwDisableProtocolTxEndIntr(I2c_HWUnitType HwUnit);
IFX_LOCAL_INLINE I2c_StatusType I2c_lIsAsyncHwUnitsStatus(void);
static void I2c_lHwInitiatePacket(I2c_PacketType Packet, \
                                                I2c_OperationType Operation);
static void I2c_lPushToQueue(I2c_PacketType Packet, I2c_HWUnitType HwUnit);
static void I2c_lPopFromQueue(I2c_HWUnitType HwUnit);
static void I2c_lProcessPacketQueue(I2c_HWUnitType HwUnit);
#endif
static void I2c_lHwUpdateModuleReg(I2c_PacketType Packet, \
            I2c_OperationType Operation, I2c_CommunicationType Communication);
#if (I2C_RESET_SFR_INIT == STD_ON)
IFX_LOCAL_INLINE void I2c_lResetKernels(void) ;
#endif

#define I2C_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Hw  Apis                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define I2C_START_SEC_VAR_UNSPECIFIED
/* IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor 
 directives is allowed only for MemMap.h */
#include "MemMap.h"
#if (I2C_ASYNC_READ_WRITE == STD_ON)
I2c_HwUnitPacketStatusType I2cHwUnitPacketStatus[I2C_MAX_QUEUE];
#endif
 

 /* IFX_MISRA_RULE_08_10_STATUS=Variable 
    I2c_PacketResultType is declared as extern in I2c.h, 
    which will be included application for debugging */
I2c_PacketResultType I2c_PacketResult[I2C_MAX_PACKET];

 /* IFX_MISRA_RULE_08_10_STATUS=Variable 
    I2c_PacketInfoType is declared as extern in I2c.h, 
    which will be included application for debugging */
I2c_PacketInfoType I2c_PacketInfo[I2C_MAX_PACKET];

#define I2C_STOP_SEC_VAR_UNSPECIFIED
/* IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor
   directives is allowed only for MemMap. */
#include "MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#define I2C_START_SEC_CONST_32BIT
/*
 * To be used for global constants (32 bits)
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#if (I2C_PB_FIXEDADDR == STD_ON)
/* To store the I2c driver configuration pointer */
static const I2c_ConfigType* const I2c_kConfigPtr = &I2c_ConfigRoot[0U];
#endif

#define I2C_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define I2C_START_SEC_VAR_32BIT
/* IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor 
 directives is allowed only for MemMap.h */
#include "MemMap.h"

#if (I2C_PB_FIXEDADDR == STD_OFF)
/* To store the I2c driver configuration pointer */
static const I2c_ConfigType *I2c_kConfigPtr;

#endif



#define I2C_STOP_SEC_VAR_32BIT
/* IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor
   directives is allowed only for MemMap. */
#include "MemMap.h"


#define I2C_START_SEC_VAR_8BIT
/* IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor
   directives is allowed only for MemMap.h */
#include "MemMap.h"

#if (I2C_PB_FIXEDADDR == STD_ON)
/* Init Status Variable. It has to be initialized to "0U" after every reset as
   0 represents the deinitialized state */
static uint8 I2c_InitStatus;
#endif  /*(I2C_DEV_ERROR_DETECT == STD_ON)*/

#if (I2C_DEV_ERROR_DETECT == STD_ON)
/* This variable is used to check the double initialisation */
static uint8 I2c_DriverState;
#endif/*(I2C_DEV_ERROR_DETECT == STD_ON)*/

/* IFX_MISRA_RULE_08_10_STATUS=Variable 
    I2c_HWUnitStatus is declared as extern in I2c.h, 
    which will be included application for debugging */
uint8 I2c_HWUnitStatus;


#if (I2C_ASYNC_READ_WRITE == STD_ON)
I2c_PacketType I2c_Queue[I2C_MAX_PACKET];
I2c_PacketType I2c_QueueIndex[I2C_MAX_QUEUE];
boolean I2c_QueueStatus[I2C_MAX_QUEUE];
#endif


#define I2C_STOP_SEC_VAR_8BIT
/* IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor
 directives is allowed only for MemMap.h */
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the I2C Code*/
#define I2C_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_I2C_PR2852]                       **
**                                                                            **
** Syntax          : void I2c_Init(const I2c_ConfigType* ConfigPtr)           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x00                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : ConfigPtr - Pointer to I2c Driver configuration set      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : Driver Module Initialization                             **
**                    1.This function will initialize all relevant registers  **
**                      of I2C perpheral with the values of structure         **
**                      ConfigPtr                                             **
**                                                                            **
*******************************************************************************/
void I2c_Init(const I2c_ConfigType* ConfigPtr)
{
  uint8 ClkFailureChk = 0U;
  uint8 ClkDisableChk = 0U;

  
  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType Returnvalue;
  #endif
  #if (I2C_ASYNC_READ_WRITE == STD_ON)
  I2c_HWUnitType HwUnit;
  #endif
  I2c_PacketType Packet;
  volatile uint8 Packetmaxvalue;
  Packetmaxvalue = I2C_MAX_PACKET;

  #if (I2C_DEV_ERROR_DETECT == STD_ON) /* if DET detection is switched On */
  Returnvalue = E_OK;
  /* The ConfigPtr is expected to be a NULL_PTR in case of Pre Compile Variant
     delivery */
  #if (I2C_PB_FIXEDADDR == STD_OFF)
  if (ConfigPtr == NULL_PTR)
  #else
  if (I2c_kConfigPtr != ConfigPtr)
  #endif
  {
    /* Report to  DET */
    Det_ReportError(
                     (uint16)I2C_MODULE_ID,
                     I2C_INSTANCE_ID,
                     I2C_SID_INIT,
                     I2C_E_PARAM_CONFIG
                   );
    Returnvalue = E_NOT_OK;
  }
  else if (I2c_DriverState == I2C_DRIVER_INITIALIZED)
  {
    Det_ReportError(
                     (uint16)I2C_MODULE_ID,
                     I2C_INSTANCE_ID,
                     I2C_SID_INIT,
                     I2C_E_ALREADY_INITIALIZED
                   );

    Returnvalue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (Returnvalue == E_OK)
  #endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
  {
    /* HW initilisation */
    I2c_lHwInit(ConfigPtr);
  
  #if (I2C_I2C0_EXIST == STD_ON)
     ClkDisableChk = (uint8)(((uint32) \
                       I2C_SFR_INIT_USER_MODE_READ32(I2C0_CLC.U)) & \
                    ((uint32)IFX_I2C_CLC_DISS_MSK << IFX_I2C_CLC_DISS_OFF));
     ClkDisableChk = (uint8)((uint32)ClkDisableChk >> IFX_I2C_CLC_DISS_OFF);
  #endif
  
  #if (I2C_I2C1_EXIST == STD_ON)
     ClkDisableChk = (uint8)(((uint32) \
                       I2C_SFR_INIT_USER_MODE_READ32(I2C1_CLC.U)) & \
                    ((uint32)IFX_I2C_CLC_DISS_MSK << IFX_I2C_CLC_DISS_OFF));
     ClkDisableChk |= (uint8)((uint32)ClkDisableChk >> IFX_I2C_CLC_DISS_OFF);
  #endif
  
    if(I2C_ZERO == ClkDisableChk)
    {
      /* Global variable initialization */
      #if (I2C_ASYNC_READ_WRITE == STD_ON)
      for (HwUnit = I2C_ZERO; HwUnit < I2C_MAX_QUEUE; HwUnit++)
      {
        I2c_QueueStatus[HwUnit] = I2C_QUEUE_EMPTY;
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
        I2c_QueueIndex[HwUnit] = ConfigPtr->HwUnitQueueLowestIndex[HwUnit];
        I2cHwUnitPacketStatus[HwUnit] = I2C_HWUNIT_PKT_OK;
      }
      #endif

      I2c_HWUnitStatus = I2C_ZERO;
     
      for (Packet = I2C_ZERO; Packet < Packetmaxvalue; Packet++)
      {
        I2c_PacketResult[Packet] = I2C_PACKET_OK;
        I2c_PacketInfo[Packet].Operation = I2C_NO_OPERATION;
      }
    }
    else
    {
      ClkFailureChk++;
    }
  
    if(I2C_ZERO == ClkFailureChk)
    {
      #if (I2C_DEV_ERROR_DETECT == STD_ON)
      I2c_DriverState = I2C_DRIVER_INITIALIZED;
      #endif /*(I2C_DEV_ERROR_DETECT == STD_ON)*/

      #if (I2C_PB_FIXEDADDR == STD_OFF)
      I2c_kConfigPtr = ConfigPtr;  /* Store ConfigPtr for use by APIs*/
      #else
      I2c_InitStatus = I2C_DRIVER_INITIALIZED;
      #endif /*(I2C_PB_FIXEDADDR == STD_ON)*/
    }
    else
    {
      #if (I2C_PB_FIXEDADDR == STD_ON)
      I2c_InitStatus = I2C_DRIVER_DEINITIALIZED;
      #endif /*(I2C_PB_FIXEDADDR == STD_ON)*/

    #if (I2C_DEV_ERROR_DETECT == STD_ON)
    I2c_DriverState = I2C_DRIVER_DEINITIALIZED;
    #endif /*(I2C_DEV_ERROR_DETECT == STD_ON)*/
    }
  }
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_I2C_PR2853]                       **
**                                                                            **
** Syntax          : void I2c_DeInit(void)                                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x01                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: de-initialisation command has been accepted.       **
**                   E_NOT_OK: de-initialisation command has not been accepted**
**                                                                            **
** Description     : Driver DeInitialization                                  **
**                    1.This function will deinitialize the I2C module        **
**                                                                            **
*******************************************************************************/
Std_ReturnType I2c_DeInit(void)
{
  Std_ReturnType Returnvalue;

  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  Returnvalue = I2c_lGetDetInitStatus(I2C_SID_DEINIT);
  #else
  Returnvalue = E_OK;
  #endif /* I2C_DEV_ERROR_DETECT */

  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  if (Returnvalue == E_OK)
  #endif
  {
    /* In case of a I2C_BUSY state, command shall be rejected  */
    if (I2c_GetStatus() == I2C_IDLE)
    {
      I2c_lHwDeInit();

      #if (I2C_DEV_ERROR_DETECT == STD_ON)
      I2c_DriverState = I2C_DRIVER_DEINITIALIZED;
      #endif /*(I2C_DEV_ERROR_DETECT == STD_ON)*/

      /* The I2C Handler/Driver state is set to I2C_UNINIT */
      /* Set Status to indicate that de-initialization is done */
      #if (I2C_PB_FIXEDADDR == STD_OFF)
      I2c_kConfigPtr = NULL_PTR;
      #else
      I2c_InitStatus = I2C_DRIVER_DEINITIALIZED;
      #endif/*(I2C_PB_FIXEDADDR == STD_ON)*/

    }/* (I2c_GetStatus() != I2C_BUS_BUSY) */
    else
    {
      Returnvalue = E_NOT_OK;
    }
  }

  return Returnvalue;
} /* End of Function: I2c_DeInit */

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_I2C_PR2858]                       **
**                                                                            **
** Syntax          : I2c_StatusType I2c_GetHWUnitStatus(I2c_HWUnitType HwUnit)**
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x08                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : HWUnit- I2C Bus identifier                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : I2C_UNINIT: I2C module is uninitialized.                 **
**                   I2C_IDLE: I2C module is idle.                            **
**                   I2C_BUSY: I2C module is busy.                            **
**                                                                            **
** Description     : This service return the status of the specified I2C      **
**                   module. The service I2c_GetHWUnitStatus() is called to   **
**                   know if the specified I2C module is I2C_IDLE I2C_BUSY.   **
**                                                                            **
*******************************************************************************/
I2c_StatusType I2c_GetHWUnitStatus(I2c_HWUnitType HwUnit)
{
  I2c_StatusType ReturnStatus;

  #if (I2C_PB_FIXEDADDR == STD_OFF)
  if (I2c_kConfigPtr == NULL_PTR)
  #else
  if (I2c_InitStatus == I2C_DRIVER_DEINITIALIZED)
  #endif /*(I2C_PB_FIXEDADDR == STD_OFF)*/
  {
    #if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    Det_ReportError(
                     (uint16)I2C_MODULE_ID,
                     I2C_INSTANCE_ID,
                     I2C_SID_GETHWUNIITSTATUS,
                     I2C_E_UNINIT
                   );
    #endif
    ReturnStatus = I2C_UNINIT;
  }
  else if (HwUnit >= (uint32)I2C_MAX_HW_UNIT)
  {
    #if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    Det_ReportError(
                     (uint16)I2C_MODULE_ID,
                     I2C_INSTANCE_ID,
                     I2C_SID_GETHWUNIITSTATUS,
                     I2C_E_PARAM_UNIT
                   );
    #endif

    ReturnStatus = I2C_UNINIT;
  }
  else if (I2C_ZERO != I2c_lHwGetModuleStatus(HwUnit))
  {
    ReturnStatus = I2C_BUSY;
  }
  else
  {
    ReturnStatus = I2C_IDLE;
  }

  return ReturnStatus;

} /* End of Function: I2c_GetHWUnitStatus */

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_I2C_PR2857]                       **
**                                                                            **
** Syntax          : I2c_StatusType I2c_GetStatus(void)                       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x05                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : I2C_UNINIT: I2C driver is uninitialized.                 **
**                   I2C_IDLE: I2C driver is idle.                            **
**                   I2C_BUSY: I2C driver is busy.                            **
**                                                                            **
** Description     : This service returns the status I2C driver.              **
**                                                                            **
*******************************************************************************/
I2c_StatusType I2c_GetStatus(void)
{
  I2c_StatusType ReturnStatus = I2C_IDLE;
  I2c_StatusType SyncStatus;
  #if (I2C_ASYNC_READ_WRITE == STD_ON)
  I2c_StatusType AsyncStatus;
  #endif


  #if (I2C_PB_FIXEDADDR == STD_OFF)
  if (I2c_kConfigPtr == NULL_PTR)
  #else
  if (I2c_InitStatus == I2C_DRIVER_DEINITIALIZED)
  #endif /*(I2C_PB_FIXEDADDR == STD_OFF)*/
  {
    #if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    Det_ReportError(
                     (uint16)I2C_MODULE_ID,
                     I2C_INSTANCE_ID,
                     I2C_SID_GETSTATUS,
                     I2C_E_UNINIT
                   );
    #endif
    ReturnStatus = I2C_UNINIT;
  }
  else
  {
    SyncStatus = I2c_lIsSyncHwUnitsStatus();

    #if (I2C_ASYNC_READ_WRITE == STD_ON)
    AsyncStatus = I2c_lIsAsyncHwUnitsStatus();
    #endif

    if (SyncStatus == I2C_IDLE)
    {
      #if (I2C_ASYNC_READ_WRITE == STD_ON)
      if (AsyncStatus == I2C_IDLE)
      {
        ReturnStatus = I2C_IDLE;
      }
      else
      {
        ReturnStatus = I2C_BUSY;
      }
      #endif
    }
    else
    {
      ReturnStatus = I2C_BUSY;
    }
  }

  return ReturnStatus;
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_I2C_PR2859]                       **
**                                                                            **
** Syntax          : Std_ReturnType I2c_SetupPacket(I2c_PacketType Packet,    **
**                                        I2c_DataType *NativeDataPtr)        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x02                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                   *NativeDataPtr - Pointer to the local buffer             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Set up packet command has been accepted.           **
**                   E_NOT_OK: Set up packet command has not been accepted.   **
**                                                                            **
** Description     : Service to setup the buffer of the Packet                **
**                                                                            **
*******************************************************************************/
Std_ReturnType I2c_SetupPacket(I2c_PacketType Packet, \
                                                I2c_DataType *NativeDataPtr)
{
  Std_ReturnType Returnvalue;

  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  Returnvalue = I2c_lGetDetInitStatus(I2C_SID_DEINIT);
  if (Returnvalue == E_OK)
  {
    Returnvalue = I2c_lGetDetPacketStatus(I2C_SID_SETUPPACKET, Packet);

    if (NativeDataPtr == NULL_PTR)
    {
      /* Report to DET */
      Det_ReportError(
                       (uint16)I2C_MODULE_ID,
                       I2C_INSTANCE_ID,
                       I2C_SID_SETUPPACKET,
                       I2C_E_PARAM_POINTER
                     );
      Returnvalue = E_NOT_OK;
    }
  }

  if (Returnvalue == E_OK)
  #endif /* I2C_DEV_ERROR_DETECT */
  {
    I2c_PacketInfo[Packet].NativeDataPtr = NativeDataPtr;
    Returnvalue = E_OK;
  }

  return Returnvalue;
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : I2c_PacketResultType I2c_GetPacketResult                 **
**                                             (I2c_PacketType Packet)        **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x06                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : I2c_PacketResultType - Packet result                     **
**                                                                            **
** Description     : Returns the Packet result                                **
**                                                                            **
*******************************************************************************/
I2c_PacketResultType I2c_GetPacketResult(I2c_PacketType Packet)
{
  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType Returnvalue;
  #endif

  I2c_PacketResultType PacketResult;

  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  Returnvalue = I2c_lGetDetInitStatus(I2C_SID_DEINIT);
  if (Returnvalue == E_OK)
  {
    Returnvalue = I2c_lGetDetPacketStatus(I2C_SID_GETPACKETRESULT, Packet);
  }

  if (Returnvalue == E_OK)
  #endif /* I2C_DEV_ERROR_DETECT */
  {
    PacketResult = I2c_PacketResult[Packet];
  }
  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  else
  {
    PacketResult = I2C_PACKET_OK;
  }
  #endif

  return PacketResult;
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_I2C_PR2861_PR2862,                **
**                                    DS_NAS_I2C_PR2860]                      **
**                                                                            **
** Syntax          : Std_ReturnType I2c_SyncOperation                         **
**                      (I2c_PacketType Packet, I2c_OperationType Operation)  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x03                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                   Operation - Read / Write                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Sync read/write command has been accepted.         **
**                   E_NOT_OK: Sync read/write command has not been accepted. **
**                                                                            **
** Description     : Service to perform synchronous read/write operation.     **
**                                                                            **
*******************************************************************************/
Std_ReturnType I2c_SyncOperation \
                        (I2c_PacketType Packet, I2c_OperationType Operation)
{
  Std_ReturnType Returnvalue;
  I2c_HWUnitType HwUnit;


  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  Returnvalue = I2c_lGetDetInitStatus(I2C_SID_DEINIT);
  if (Returnvalue == E_OK)
  {
    Returnvalue = I2c_lGetDetPacketStatus(I2C_SID_SYNCOPERATION, Packet);
    if (Returnvalue == E_OK)
    {
      Returnvalue = \
            I2c_lGetDetPktOperationStatus(I2C_SID_SYNCOPERATION, Operation);
      if (Returnvalue == E_OK)
      {
        Returnvalue =  \
            I2c_lGetDetPktInitializedStatus(I2C_SID_SYNCOPERATION, Packet);
      }
    }
  }

  if (Returnvalue == E_OK)
  #endif /* I2C_DEV_ERROR_DETECT */
  {
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple I2C kernels.*/
    HwUnit = (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).HwUnit;
    if ( (I2c_HWUnitStatus & HwUnit) == I2C_ZERO)
    {
      I2c_HWUnitStatus = I2c_HWUnitStatus | HwUnit;

      Returnvalue = E_OK;
    }
    else
    {
      #if (I2C_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      Det_ReportError(
                       (uint16)I2C_MODULE_ID,
                       I2C_INSTANCE_ID,
                       I2C_SID_SYNCOPERATION,
                       I2C_E_HW_UNIT_BUSY
                     );
      #endif
      Returnvalue = E_NOT_OK;
    }

    if (Returnvalue == E_OK)
    {
      I2c_PacketResult[Packet] = I2C_PACKET_PENDING;

      Returnvalue = I2c_lHwExecutePacket(Packet, Operation);

      if (Returnvalue == E_OK)
      {
        I2c_PacketResult[Packet] = I2C_PACKET_OK;
      }
      else
      {
        I2c_PacketResult[Packet] = I2C_PACKET_FAILED;
      }

      I2c_PacketInfo[Packet].Operation = I2C_NO_OPERATION;

      HwUnit = ~HwUnit;

      I2c_HWUnitStatus = I2c_HWUnitStatus & HwUnit;
    }
  }

  return Returnvalue;
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_I2C_PR2863_PR2864,                **
**                                    DS_NAS_I2C_PR2860]                      **
**                                                                            **
** Syntax          : Std_ReturnType I2c_AsyncOperation                        **
**                      (I2c_PacketType Packet, I2c_OperationType Operation)  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x04                                                     **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                   Operation - Read / Write                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Async read/write command has been accepted.        **
**                   E_NOT_OK: Async read/write command has not been accepted.**
**                                                                            **
** Description     : Service to perform Asynchronous read/write operation.    **
**                                                                            **
*******************************************************************************/
#if (I2C_ASYNC_READ_WRITE == STD_ON)
Std_ReturnType I2c_AsyncOperation \
                        (I2c_PacketType Packet, I2c_OperationType Operation)
{
  Std_ReturnType Returnvalue;
  I2c_HWUnitType HwUnit;
  I2c_HWUnitType HwUnitQueue;

  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  Returnvalue = I2c_lGetDetInitStatus(I2C_SID_DEINIT);
  if (Returnvalue == E_OK)
  {
    Returnvalue = I2c_lGetDetPacketStatus(I2C_SID_ASYNCOPERATION, Packet);
    if (Returnvalue == E_OK)
    {
      Returnvalue = \
            I2c_lGetDetPktOperationStatus(I2C_SID_ASYNCOPERATION, Operation);
      if (Returnvalue == E_OK)
      {
        Returnvalue = \
            I2c_lGetDetPktInitializedStatus(I2C_SID_SYNCOPERATION, Packet);
      }
    }
  }

  if (Returnvalue == E_OK)
  #endif /* I2C_DEV_ERROR_DETECT */
  {
    if ((I2c_PacketResult[Packet] == I2C_PACKET_OK) || \
        (I2c_PacketResult[Packet] == I2C_PACKET_FAILED) ||
        (I2c_PacketResult[Packet] == I2C_PACKET_CANCELLED))
    {
      HwUnit = (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).HwUnit;
      HwUnitQueue = I2c_kConfigPtr->HwUnitQueueIndex[HwUnit];

      if (I2c_QueueStatus[HwUnitQueue] == I2C_QUEUE_EMPTY)
      {
        I2c_PacketResult[Packet] = I2C_PACKET_PENDING;

        I2c_lPushToQueue(Packet, HwUnit);

        I2c_lHwInitiatePacket(Packet, Operation);
      }
      else
      {
        I2c_PacketResult[Packet] = I2C_PACKET_QUEUED;

        I2c_lPushToQueue(Packet, HwUnit);
      }
      Returnvalue = E_OK;
    }
    else
    {
      #if (I2C_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      Det_ReportError(
                       (uint16)I2C_MODULE_ID,
                       I2C_INSTANCE_ID,
                       I2C_SID_ASYNCOPERATION,
                       I2C_E_PACKET_UNDER_PROCESS
                     );
      #endif
      Returnvalue = E_NOT_OK;
    }
  }
  return Returnvalue;
}
#endif

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_Cancel(I2c_PacketType Packet)                   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x09                                                     **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : Cancels the Packet which is in the Queue                 **
**                                                                            **
*******************************************************************************/
#if ((I2C_ASYNC_READ_WRITE == STD_ON) && (I2C_CANCEL_API == STD_ON))
void I2c_Cancel(I2c_PacketType Packet)
{
  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType Returnvalue;
  #endif

  #if (I2C_DEV_ERROR_DETECT == STD_ON)
  Returnvalue = I2c_lGetDetInitStatus(I2C_SID_DEINIT);
  if (Returnvalue == E_OK)
  {
    Returnvalue = I2c_lGetDetPacketStatus(I2C_SID_CANCEL, Packet);
  }

  if (Returnvalue == E_OK)
  #endif /* I2C_DEV_ERROR_DETECT */
  {
    if (I2c_PacketResult[Packet] == I2C_PACKET_PENDING)
    {
      #if (I2C_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      Det_ReportError(
                       (uint16)I2C_MODULE_ID,
                       I2C_INSTANCE_ID,
                       I2C_SID_ASYNCOPERATION,
                       I2C_E_PACKET_UNDER_PROCESS
                     );
      #endif
    }
    else
    {
      I2c_PacketResult[Packet] = I2C_PACKET_CANCELLED;
    }
  }
}
#endif  /* ((I2C_ASYNC_READ_WRITE == STD_ON) && (I2C_CANCEL_API == STD_ON)) */


/*******************************************************************************
**                            I2c Hw Apis                                     **
*******************************************************************************/
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : I2c_lHwInit(const I2c_ConfigType* ConfigPtr)             **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ConfigPtr - Pointer to I2c Driver configuration set      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function will initialize the hardware peripheral    **
**                    - All the interrupts are cleared                        **
**                                                                            **
*******************************************************************************/
static void I2c_lHwInit(const I2c_ConfigType* ConfigPtr)
{
  I2c_HWUnitType HwUnit;
  volatile uint32 ReadBack;
  volatile uint8 MaxHWunit;
  MaxHWunit = I2C_MAX_HW_UNIT;

  #if (I2C_RESET_SFR_INIT == STD_ON)
  I2c_lResetKernels();
  #endif
  I2C_SFR_INIT_RESETENDINIT();
  #if (I2C_I2C0_EXIST == STD_ON)
  I2C_SFR_INIT_WRITE32(I2C0_CLC.U, I2C_ZERO);
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to 
     efficiently access the SFRs of multiple I2C kernels. */
  I2C_SFR_INIT_USER_MODE_WRITE32(I2C0_CLC1.U, \
                           ConfigPtr->HWModuleConfigPtr[I2C_ZERO].HWClkSetting);
  #endif
  #if (I2C_I2C1_EXIST == STD_ON)
  I2C_SFR_INIT_WRITE32(I2C1_CLC.U, I2C_ZERO);
  I2C_SFR_INIT_USER_MODE_WRITE32(I2C1_CLC1.U, \
                           ConfigPtr->HWModuleConfigPtr[I2C_ONE].HWClkSetting);
  #endif
  I2C_SFR_INIT_SETENDINIT();
  #if (I2C_I2C0_EXIST == STD_ON)
  /* Read back the CLC register to flush the pipeline effects */
  ReadBack = I2C_SFR_INIT_USER_MODE_READ32(I2C0_CLC.U);
  ReadBack = I2C_SFR_INIT_USER_MODE_READ32(I2C0_CLC1.U);
  #endif
  #if (I2C_I2C1_EXIST == STD_ON)
  /* Read back the CLC register to flush the pipeline effects */
  ReadBack = I2C_SFR_INIT_USER_MODE_READ32(I2C1_CLC.U);
  ReadBack = I2C_SFR_INIT_USER_MODE_READ32(I2C1_CLC1.U);
  #endif
  UNUSED_PARAMETER(ReadBack)
  
  for (HwUnit = I2C_ZERO; HwUnit < MaxHWunit; HwUnit++)
  {
    I2c_lInitHwClearAllInterrupts(HwUnit);
  }

}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_lHwDeInit(void)                                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function will initialize the hardware peripheral    **
**                    - All the interrupts are cleared                        **
**                                                                            **
*******************************************************************************/
static void I2c_lHwDeInit(void)
{
  I2c_HWUnitType HwUnit;
  volatile uint8 MaxHWunit;
  MaxHWunit = I2C_MAX_HW_UNIT;

  /* Disable the SENT module clock */
  I2C_SFR_DEINIT_RESETENDINIT();
  #if (I2C_I2C0_EXIST == STD_ON)
  I2C_SFR_DEINIT_MODIFY32(I2C0_CLC.U, I2C_CLC_SFR_MSK,\
                                    ((uint32)I2C_ONE << IFX_I2C_CLC_DISR_OFF))
  #endif
  #if (I2C_I2C1_EXIST == STD_ON)
  I2C_SFR_DEINIT_MODIFY32(I2C1_CLC.U, I2C_CLC_SFR_MSK,\
                                    ((uint32)I2C_ONE << IFX_I2C_CLC_DISR_OFF))
  #endif
  I2C_SFR_DEINIT_SETENDINIT();

  for (HwUnit = I2C_ZERO; HwUnit < MaxHWunit; HwUnit++)
  {
    I2c_lDeInitHwClearAllInterrupts(HwUnit);
  }
}

/*******************************************************************************
**                            I2c functions                                   **
*******************************************************************************/
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType I2c_lGetDetInitStatus(uint8 ApiId)        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: I2C driver is initialized.                         **
**                   E_NOT_OK: I2C driver is not initialized.                 **
**                                                                            **
** Description     : This function returns whether                            **
**                    - I2C driver is initialized or not                      **
**                                                                            **
*******************************************************************************/
#if (I2C_DEV_ERROR_DETECT == STD_ON)
IFX_LOCAL_INLINE Std_ReturnType I2c_lGetDetInitStatus(uint8 ApiId)
{
  Std_ReturnType Returnvalue;

  Returnvalue = E_OK;

  #if (I2C_PB_FIXEDADDR == STD_OFF)
  if (I2c_kConfigPtr == NULL_PTR)
  #else
  if (I2c_InitStatus == I2C_DRIVER_DEINITIALIZED)
  #endif /* (I2C_PB_FIXEDADDR == STD_OFF) */
  {
    /* Report to DET */
    Det_ReportError(
                     (uint16)I2C_MODULE_ID,
                     I2C_INSTANCE_ID,
                     ApiId,
                     I2C_E_UNINIT
                   );
    Returnvalue = E_NOT_OK;
  }

  return Returnvalue;
}
#endif

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType I2c_lGetDetPacketStatus \                 **
**                                      (uint8 ApiId, I2c_PacketType Packet)  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                   ApiId - ApiId                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Packet ID is valid.                                **
**                   E_NOT_OK: Packet ID is not valid.                        **
**                                                                            **
** Description     : This function returns whether                            **
**                    - Packet ID is valid or not                             **
**                                                                            **
*******************************************************************************/
#if (I2C_DEV_ERROR_DETECT == STD_ON)
IFX_LOCAL_INLINE Std_ReturnType I2c_lGetDetPacketStatus \
                                        (uint8 ApiId, I2c_PacketType Packet)
{
  Std_ReturnType Returnvalue;

  Returnvalue = E_OK;

  if (Packet >= I2C_MAX_PACKET)
  {
    /* Report to DET */
    Det_ReportError(
                     (uint16)I2C_MODULE_ID,
                     I2C_INSTANCE_ID,
                     ApiId,
                     I2C_E_PARAM_PACKET
                   );
    Returnvalue = E_NOT_OK;
  }

  return Returnvalue;
}
#endif

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType I2c_lGetDetPktOperationStatus \           **
**                              (uint8 ApiId, I2c_OperationType Operation)    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ApiId - ApiId                                            **
**                   Operation - Read / Write                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Operation is valid.                                **
**                   E_NOT_OK: Operation is not valid.                        **
**                                                                            **
** Description     : This function returns whether                            **
**                    - Packet operation requested is valid or not            **
**                                                                            **
*******************************************************************************/
#if (I2C_DEV_ERROR_DETECT == STD_ON)
IFX_LOCAL_INLINE Std_ReturnType I2c_lGetDetPktOperationStatus \
                                     (uint8 ApiId, I2c_OperationType Operation)
{
  Std_ReturnType Returnvalue;

  Returnvalue = E_OK;

  if (Operation >= I2C_NO_OPERATION)
  {
    /* Report to DET */
    Det_ReportError(
                     (uint16)I2C_MODULE_ID,
                     I2C_INSTANCE_ID,
                     ApiId,
                     I2C_E_PARAM_OPERATION
                   );
    Returnvalue = E_NOT_OK;
  }

  return Returnvalue;
}
#endif

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType I2c_lGetDetPktInitializedStatus \         **
**                                   (uint8 ApiId, I2c_PacketType Packet)     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ApiId - ApiId                                            **
**                   Packet - Packet ID                                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Packet is initialized.                             **
**                   E_NOT_OK: Packet is not initialized.                     **
**                                                                            **
** Description     : This function returns whether                            **
**                    - Packet is initialized or not                          **
**                                                                            **
*******************************************************************************/
#if (I2C_DEV_ERROR_DETECT == STD_ON)
IFX_LOCAL_INLINE Std_ReturnType I2c_lGetDetPktInitializedStatus \
                                     (uint8 ApiId, I2c_PacketType Packet)
{
  Std_ReturnType Returnvalue;

  Returnvalue = E_OK;

  if (I2c_PacketInfo[Packet].NativeDataPtr == NULL_PTR)
  {
    /* Report to DET */
    Det_ReportError(
                     (uint16)I2C_MODULE_ID,
                     I2C_INSTANCE_ID,
                     ApiId,
                     I2C_E_PACKET_NOT_INITIALIZED
                   );
    Returnvalue = E_NOT_OK;
  }

  return Returnvalue;
}
#endif  /* (I2C_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : boolean I2c_lHwGetModuleStatus(I2c_HWUnitType HwUnit)    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ZERO - HW unit is IDLE                                   **
**                   ONE - HW unit is BUSY                                    **
**                                                                            **
** Description     : This function returns the HW peripheral status           **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE boolean I2c_lHwGetModuleStatus(I2c_HWUnitType HwUnit)
{
  boolean HwUnitStatus;
  uint8 BusStatus;
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to 
     efficiently access the SFRs of multiple I2C kernels. */  
  BusStatus = (uint8)(((uint32) \
            I2C_SFR_DEINIT_USER_MODE_READ32(I2C_MODULE_X[HwUnit].BUSSTAT.U)) & \
                    ((uint32)IFX_I2C_BUSSTAT_BS_MSK << IFX_I2C_BUSSTAT_BS_OFF));
  BusStatus = (uint8)((uint32)BusStatus >> IFX_I2C_BUSSTAT_BS_OFF);  
  if (BusStatus == I2C_ZERO)
  {
    HwUnitStatus = (boolean)I2C_ZERO;
  }
  else
  {
    HwUnitStatus = (boolean)I2C_ONE;
  }
  return HwUnitStatus;
}


/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : Std_ReturnType I2c_lHwExecutePacket                      **
**                      (I2c_PacketType Packet, I2c_OperationType Operation)  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                   Operation - Read / Write                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Packet read/write is successfull.                  **
**                   E_NOT_OK: Packet read/write is not successfull.          **
**                                                                            **
** Description     : This function will initiate and completes the packet     **
**                   operation requested(read/write)                          **
**                                                                            **
*******************************************************************************/
static Std_ReturnType I2c_lHwExecutePacket(I2c_PacketType Packet, \
                                                I2c_OperationType Operation)
{
  Std_ReturnType Returnvalue;
  uint8 PirqssStatus;
  uint32 LoopCounter;
  I2c_HWUnitType HwUnit;
  Ifx_I2C *HwUnitPtr;
  I2c_DataType *NativeDataPtr;
  I2c_NumberOfDataType DataLength;
  I2c_NumberOfDataType LoopCount;
  volatile uint32 Dummy_Read;

  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    access the SFRs of multiple I2C kernels. */
  HwUnit = (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).HwUnit;
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
     access the SFRs of multiple I2C kernels. */
  HwUnitPtr = &(I2C_MODULE_X[HwUnit]);

  if (Operation == I2C_WRITE)
  {
    I2c_lRunTimeHwClearAllInterrupts(HwUnit);

    I2c_PacketInfo[Packet].Operation = I2C_WRITE;
    I2c_lHwUpdateModuleReg(Packet, Operation, I2C_COMMN_SYNCHRONOUS);

    LoopCounter = I2C_SYNCTRANSMIT_TIMEOUT_CTR;

    PirqssStatus = (uint8)(((uint32) \
                      I2C_SFR_RUNTIME_USER_MODE_READ32(HwUnitPtr->PIRQSS.U)) & \
              ((uint32)IFX_I2C_PIRQSS_TX_END_MSK << IFX_I2C_PIRQSS_TX_END_OFF));
    PirqssStatus = (uint8)((uint32)PirqssStatus >> IFX_I2C_PIRQSS_TX_END_OFF);
  
    while ((PirqssStatus == I2C_ZERO) && (LoopCounter != I2C_ZERO))
    {
      LoopCounter--;
      PirqssStatus = (uint8)(((uint32) \
                      I2C_SFR_RUNTIME_USER_MODE_READ32(HwUnitPtr->PIRQSS.U)) & \
              ((uint32)IFX_I2C_PIRQSS_TX_END_MSK << IFX_I2C_PIRQSS_TX_END_OFF));
      PirqssStatus = (uint8)((uint32)PirqssStatus >> IFX_I2C_PIRQSS_TX_END_OFF);
    }

    if ((E_OK == I2c_lHwGetErrorStatus(HwUnitPtr)) && (LoopCounter != I2C_ZERO))
    {
      Returnvalue = E_OK;
    }
    else
    {
      Returnvalue = E_NOT_OK;
    }

    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].RUNCTRL.U, \
                                                        I2C_DISABLE_INTERFACE);
    I2c_lRunTimeHwClearAllInterrupts(HwUnit);
  }
  else
  {
    I2c_lRunTimeHwClearAllInterrupts(HwUnit);

    I2c_PacketInfo[Packet].Operation = I2C_DUMMY_WRITE;
    I2c_lHwUpdateModuleReg(Packet, I2C_DUMMY_WRITE, I2C_COMMN_SYNCHRONOUS);

    LoopCounter = I2C_SYNCTRANSMIT_TIMEOUT_CTR;

    PirqssStatus = (uint8)(((uint32) \
                      I2C_SFR_RUNTIME_USER_MODE_READ32(HwUnitPtr->PIRQSS.U)) & \
              ((uint32)IFX_I2C_PIRQSS_TX_END_MSK << IFX_I2C_PIRQSS_TX_END_OFF));
    PirqssStatus = (uint8)((uint32)PirqssStatus >> IFX_I2C_PIRQSS_TX_END_OFF);
    
    while ((PirqssStatus == I2C_ZERO) && (LoopCounter != I2C_ZERO))
    {
      LoopCounter--;
      PirqssStatus = (uint8)(((uint32) \
                      I2C_SFR_RUNTIME_USER_MODE_READ32(HwUnitPtr->PIRQSS.U)) & \
              ((uint32)IFX_I2C_PIRQSS_TX_END_MSK << IFX_I2C_PIRQSS_TX_END_OFF));
      PirqssStatus = (uint8)((uint32)PirqssStatus >> IFX_I2C_PIRQSS_TX_END_OFF);
    }

    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].RUNCTRL.U, \
                                                         I2C_DISABLE_INTERFACE);

    if ((E_OK == I2c_lHwGetErrorStatus(HwUnitPtr)) && (LoopCounter != I2C_ZERO))
    {
      I2c_lRunTimeHwClearAllInterrupts(HwUnit);

      I2c_PacketInfo[Packet].Operation = I2C_READ;
      I2c_lHwUpdateModuleReg(Packet, I2C_READ, I2C_COMMN_SYNCHRONOUS);

      LoopCounter = I2C_SYNCTRANSMIT_TIMEOUT_CTR;

      PirqssStatus = (uint8)(((uint32) \
                      I2C_SFR_RUNTIME_USER_MODE_READ32(HwUnitPtr->PIRQSS.U)) & \
              ((uint32)IFX_I2C_PIRQSS_TX_END_MSK << IFX_I2C_PIRQSS_TX_END_OFF));
      PirqssStatus = (uint8)((uint32)PirqssStatus >> IFX_I2C_PIRQSS_TX_END_OFF);

      while ((PirqssStatus == I2C_ZERO) && (LoopCounter != I2C_ZERO))
      {
        LoopCounter--;
        PirqssStatus = (uint8)(((uint32) \
                      I2C_SFR_RUNTIME_USER_MODE_READ32(HwUnitPtr->PIRQSS.U)) & \
              ((uint32)IFX_I2C_PIRQSS_TX_END_MSK << IFX_I2C_PIRQSS_TX_END_OFF));
        PirqssStatus=(uint8)((uint32)PirqssStatus >> IFX_I2C_PIRQSS_TX_END_OFF);
      }

      if ((E_OK == I2c_lHwGetErrorStatus(HwUnitPtr)) && \
                                                     (LoopCounter != I2C_ZERO))
      {
        Returnvalue = E_OK;

        /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
        access the SFRs of multiple I2C kernels. */
        DataLength = ((I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).Length);
        NativeDataPtr = I2c_PacketInfo[Packet].NativeDataPtr;

        for (LoopCount = I2C_ZERO; LoopCount < DataLength; LoopCount++)
        {
        /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
       /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
           access the SFRs of multiple I2C kernels. */
          *(NativeDataPtr) = (uint8)I2C_SFR_RUNTIME_USER_MODE_READ32( \
                                                    I2C_MODULE_X[HwUnit].RXD.U);
        /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
           access the SFRs of multiple I2C kernels. */
          NativeDataPtr++;
        }
        /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
       /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
           access the SFRs of multiple I2C kernels. */
        Dummy_Read = I2C_SFR_RUNTIME_USER_MODE_READ32( \
                                                I2C_MODULE_X[HwUnit].RPSSTAT.U);
        UNUSED_PARAMETER(Dummy_Read)
      }
      else
      {
        Returnvalue = E_NOT_OK;
      }

      /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
      /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
         access the SFRs of multiple I2C kernels. */
      I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].RUNCTRL.U, \
                                                         I2C_DISABLE_INTERFACE);
    }
    else
    {
      Returnvalue = E_NOT_OK;
    }
    I2c_lRunTimeHwClearAllInterrupts(HwUnit);
  }

  return Returnvalue;
}


/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_lHwInitiatePacket(I2c_PacketType Packet, \      **
**                                              I2c_OperationType Operation)  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                   Operation - Read / Write                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function will initiate the packet operation         **
**                   requested(read/write)                                    **
**                                                                            **
*******************************************************************************/
#if (I2C_ASYNC_READ_WRITE == STD_ON)
static void I2c_lHwInitiatePacket(I2c_PacketType Packet, \
                                                I2c_OperationType Operation)
{
  I2c_HWUnitType HwUnit;
  I2c_HWUnitType HwUnitQueue;

  HwUnit = (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).HwUnit;

  HwUnitQueue = I2c_kConfigPtr->HwUnitQueueIndex[HwUnit];

  I2cHwUnitPacketStatus[HwUnitQueue] = I2C_HWUNIT_PKT_STARTED;

  I2c_lRunTimeHwClearAllInterrupts(HwUnit);

  if ((Operation == I2C_READ)  && \
                       (I2c_PacketInfo[Packet].Operation == I2C_NO_OPERATION))
  {
    I2c_PacketInfo[Packet].Operation = I2C_DUMMY_WRITE;
    I2c_lHwUpdateModuleReg(Packet, I2C_DUMMY_WRITE, I2C_COMMN_ASYNCHRONOUS);
  }
  else
  {
    I2c_PacketInfo[Packet].Operation = Operation;
    I2c_lHwUpdateModuleReg(Packet, Operation, I2C_COMMN_ASYNCHRONOUS);
  }
}
#endif

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_I2C_PR2854,DS_NAS_I2C_PR2855,     **
**                                    DS_NAS_I2C_PR2856]                      **
**                                                                            **
** Syntax          : void I2c_lHwUpdateModuleReg(I2c_PacketType Packet, \     **
**          I2c_OperationType Operation, I2c_CommunicationType Communication) **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                   Operation - Read / Write                                 **
**                   Communicaiton - Sync or Async                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function will update the peripheral registers       **
**                   to facilitate packer read/write operation                **
**                                                                            **
*******************************************************************************/
static void I2c_lHwUpdateModuleReg(I2c_PacketType Packet, \
            I2c_OperationType Operation, I2c_CommunicationType Communication)
{
  I2c_NumberOfDataType LoopCount;
  I2c_HWUnitType HwUnit;
  I2c_DataType *NativeDataPtr;
  uint8 Address, DeviceAddress;
  I2c_NumberOfDataType DataLength;

  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
    access the SFRs of multiple I2C kernels. */
  HwUnit = (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).HwUnit;

  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
    access the SFRs of multiple I2C kernels. */
  Address = (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).Address;

  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
    access the SFRs of multiple I2C kernels. */
  DeviceAddress = (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).DeviceAddress;
  
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  DataLength = ((I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).Length);

  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].RUNCTRL.U, \
                                                         I2C_DISABLE_INTERFACE);

  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].FDIVCFG.U, \
              (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).FracDividerCfgValue);

  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels.*/
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ADDRCFG.U, \
                 (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).AdddressCfgValue);

  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels.*/
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels.*/
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].TIMCFG.U, \
                   (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).TimingCfgvalue);

  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].FIFOCFG.U, \
                     (I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).FIFOCfgValue);

  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].RUNCTRL.U, \
                                                          I2C_ENABLE_INTERFACE);
   /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_WRITE32(I2C_MODULE_X[HwUnit].GPCTL.U, \
        (uint32)((I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).PortPinCfgvalue));

  if (Communication == I2C_COMMN_ASYNCHRONOUS)
  {
    #if (I2C_ASYNC_READ_WRITE == STD_ON)
    I2c_lHwEnableProtocolTxEndIntr(HwUnit);
    #endif
  }

  if (Operation == I2C_WRITE)
  {
    NativeDataPtr = I2c_PacketInfo[Packet].NativeDataPtr;

    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
       access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].TPSCTRL.U, \
                                      ((uint32)DataLength + (uint32)I2C_TWO));

    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
       access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].TXD.U,  \
                                ((uint32)DeviceAddress | ((uint32)I2C_WRITE)));

    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
       access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].TXD.U, \
                                                            ((uint32)Address));

    for (LoopCount = I2C_ZERO; LoopCount < DataLength; LoopCount++)
    {
      /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
      /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
         access the SFRs of multiple I2C kernels. */
      I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].TXD.U, \
                                                    ((uint32)*(NativeDataPtr)));
      /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
         access the SFRs of multiple I2C kernels. */
      NativeDataPtr++;
    }
  }

  else if (Operation == I2C_DUMMY_WRITE)
  {
  
    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].TPSCTRL.U, I2C_TWO);

    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
       access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].TXD.U, \
                                 ((uint32)DeviceAddress | ((uint32)I2C_WRITE)));

    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
       access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].TXD.U, \
                                                               (uint32)Address);
  }
  else
  {
    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
       access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].MRPSCTRL.U, \
                                                          ((uint32)DataLength));

    /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
    /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
       access the SFRs of multiple I2C kernels. */
    I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].TXD.U, \
                                  ((uint32)DeviceAddress | ((uint32)I2C_READ)));
  }
}


/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_lPushToQueue(I2c_PacketType Packet, \           **
**                                                 I2c_HWUnitType HwUnit)     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Packet - Packet ID                                       **
**                   HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function will push the packet into the queue        **
**                                                                            **
*******************************************************************************/
#if (I2C_ASYNC_READ_WRITE == STD_ON)
static void I2c_lPushToQueue(I2c_PacketType Packet, I2c_HWUnitType HwUnit)
{
  I2c_PacketType LowestQueueIndex;
  I2c_PacketType PrevQueueIndex;
  I2c_PacketType CurrentQueueIndex;
  I2c_PacketType NoOfPacketsInQueue;
  I2c_HWUnitType HwUnitQueue;

  LowestQueueIndex = I2c_kConfigPtr->HwUnitQueueLowestIndex[HwUnit];
  HwUnitQueue = I2c_kConfigPtr->HwUnitQueueIndex[HwUnit];

  if (I2c_QueueStatus[HwUnitQueue] == I2C_QUEUE_EMPTY)
  {
    I2c_QueueIndex[HwUnitQueue] = LowestQueueIndex;

    I2c_Queue[LowestQueueIndex] = Packet;
  }
  else
  {
    PrevQueueIndex = I2c_QueueIndex[HwUnitQueue];

    NoOfPacketsInQueue = \
                    (I2c_QueueIndex[HwUnitQueue] - LowestQueueIndex) + I2C_ONE;

    do
    {
      CurrentQueueIndex = PrevQueueIndex + I2C_ONE;

      I2c_Queue[CurrentQueueIndex] = I2c_Queue[PrevQueueIndex];

      PrevQueueIndex--;

    } while (NoOfPacketsInQueue > I2C_ZERO);

    I2c_Queue[PrevQueueIndex] = Packet;
  }

  I2c_QueueStatus[HwUnitQueue] = I2C_QUEUE_FILLED;
}
#endif

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_lPopFromQueue(I2c_HWUnitType HwUnit)            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function will pop the packet from the queue and     **
**                   initiates                                                **
**                                                                            **
*******************************************************************************/
#if (I2C_ASYNC_READ_WRITE == STD_ON)
static void I2c_lPopFromQueue(I2c_HWUnitType HwUnit)
{
  I2c_PacketType LowestQueueIndex;
  I2c_OperationType Operation;
  I2c_PacketType Packet;
  I2c_HWUnitType HwUnitQueue;

  HwUnitQueue = I2c_kConfigPtr->HwUnitQueueIndex[HwUnit];
  LowestQueueIndex = I2c_kConfigPtr->HwUnitQueueLowestIndex[HwUnit];

  do
  {
    I2c_QueueIndex[HwUnitQueue]--;
    Packet = I2c_Queue[I2c_QueueIndex[HwUnitQueue]];
  } while ((I2c_PacketResult[Packet] == I2C_PACKET_CANCELLED) &&
           (I2c_QueueIndex[HwUnitQueue] > LowestQueueIndex));

  if ((I2c_PacketResult[Packet] == I2C_PACKET_CANCELLED) &&
      (I2c_QueueIndex[HwUnitQueue] <= LowestQueueIndex))
  {
    I2c_QueueStatus[HwUnitQueue] = I2C_QUEUE_EMPTY;
  }
  else
  {
    Operation = I2c_PacketInfo[Packet].Operation;
    I2c_lHwInitiatePacket(Packet, Operation);
  }
}
#endif

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_I2C_PR2865]                       **
**                                                                            **
** Syntax          : void I2c_lProcessPacketQueue(I2c_HWUnitType HwUnit)      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function will process the packet queue              **
**                                                                            **
*******************************************************************************/
#if (I2C_ASYNC_READ_WRITE == STD_ON)
static void I2c_lProcessPacketQueue(I2c_HWUnitType HwUnit)
{
  I2c_PacketType LowestQueueIndex;
  #if (I2C_ASYNC_NOTIFICATION == STD_ON)
  I2c_PacketType Packet;
  I2c_NotifFunctionPtrType TempPacketEndNotification;
  #endif
  I2c_HWUnitType HwUnitQueue;

  HwUnitQueue = I2c_kConfigPtr->HwUnitQueueIndex[HwUnit];
  LowestQueueIndex = I2c_kConfigPtr->HwUnitQueueLowestIndex[HwUnit];

  #if (I2C_ASYNC_NOTIFICATION == STD_ON)
  Packet = I2c_Queue[I2c_QueueIndex[HwUnitQueue]];

  TempPacketEndNotification = I2c_NotifFunctionPtrArray[Packet];

  if (TempPacketEndNotification != NULL_PTR)
  {
    TempPacketEndNotification(Packet);
  }
  #endif

  if ((I2c_Queue[I2c_QueueIndex[HwUnitQueue]]) == LowestQueueIndex)
  {
    I2c_QueueStatus[HwUnitQueue] = I2C_QUEUE_EMPTY;

    I2c_lHwDisableProtocolTxEndIntr(HwUnit);

    I2c_lRunTimeHwClearAllInterrupts(HwUnit);
  }
  else
  {
    I2c_lPopFromQueue(HwUnit);
  }
}
#endif

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_IsrI2cProtocol(I2c_HWUnitType HwUnit)           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : ISR fucntion to take care of protocol interrupts         **
**                                                                            **
*******************************************************************************/
#if (I2C_ASYNC_READ_WRITE == STD_ON)
void I2c_IsrI2cProtocol(I2c_HWUnitType HwUnit)
{
  volatile I2c_HWUnitType HwUnitQueue;
  volatile I2c_PacketType Packet;
  volatile Ifx_I2C *HwUnitPtr;
  volatile I2c_NumberOfDataType LoopCount;
  volatile I2c_NumberOfDataType DataLength;
  volatile I2c_DataType *NativeDataPtr;
  volatile uint32 Dummy_Read;


  HwUnitPtr = &(I2C_MODULE_X[HwUnit]);

  HwUnitQueue = I2c_kConfigPtr->HwUnitQueueIndex[HwUnit];

  Packet = I2c_Queue[I2c_QueueIndex[HwUnitQueue]];

  if (E_OK == I2c_lHwGetErrorStatus(HwUnitPtr))
  {
    if (I2c_PacketInfo[Packet].Operation == I2C_DUMMY_WRITE)
    {
      I2c_lHwInitiatePacket(Packet, I2C_READ);
    }
    else
    {
      if (I2c_PacketInfo[Packet].Operation == I2C_READ)
      {
        DataLength = ((I2c_kConfigPtr->I2cPacketConfigPtr[Packet]).Length);
        NativeDataPtr = I2c_PacketInfo[Packet].NativeDataPtr;

        for (LoopCount = I2C_ZERO; LoopCount < DataLength; LoopCount++)
        {
          *(NativeDataPtr) = (uint8)I2C_SFR_RUNTIME_USER_MODE_READ32(\
                                                    I2C_MODULE_X[HwUnit].RXD.U);
          NativeDataPtr++;
        }
        Dummy_Read = I2C_SFR_RUNTIME_USER_MODE_READ32(\
                                                I2C_MODULE_X[HwUnit].RPSSTAT.U);
        UNUSED_PARAMETER(Dummy_Read)
      }

      I2cHwUnitPacketStatus[HwUnitQueue] = I2C_HWUNIT_PKT_OK;
      I2c_PacketResult[Packet] = I2C_PACKET_OK;
      I2c_PacketInfo[Packet].Operation = I2C_NO_OPERATION;

      I2c_lProcessPacketQueue(HwUnit);
    }
  }
  else
  {
    I2c_PacketResult[Packet] = I2C_PACKET_FAILED;
    I2c_PacketInfo[Packet].Operation = I2C_NO_OPERATION;
    I2c_lProcessPacketQueue(HwUnit);
  }

}
#endif

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_lHwEnableProtocolTxEndIntr                      **
**                                       (I2c_HWUnitType HwUnit)              **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : Fucntion to enable protocol interrupt                    **
**                                                                            **
*******************************************************************************/
#if (I2C_ASYNC_READ_WRITE == STD_ON)
IFX_LOCAL_INLINE void I2c_lHwEnableProtocolTxEndIntr(I2c_HWUnitType HwUnit)
{
  I2C_SFR_RUNTIME_USER_MODE_MODIFY32(I2C_MODULE_X[HwUnit].IMSC.U, \
               I2C_IMSC_SFR_MSK,((uint32)I2C_ONE << IFX_I2C_IMSC_I2C_P_INT_OFF))
  I2C_SFR_RUNTIME_USER_MODE_MODIFY32(I2C_MODULE_X[HwUnit].PIRQSM.U, \
              I2C_PIRQSM_SFR_MSK,((uint32)I2C_ONE << IFX_I2C_PIRQSM_TX_END_OFF))

  #if (I2C_I2C0_EXIST == STD_ON)
  if (HwUnit == I2C_ZERO)
  {
    I2C_SFR_RUNTIME_MODIFY32(SRC_I2C_I2C0_P.U, I2C_SRC_SRCR_MSK, \
                                      ((uint32)I2C_ONE << IFX_SRC_SRCR_SRE_OFF))
  }
  #endif
  #if (I2C_I2C1_EXIST == STD_ON)
  if (HwUnit == I2C_ONE)
  {
    I2C_SFR_RUNTIME_MODIFY32(SRC_I2C_I2C1_P.U, I2C_SRC_SRCR_MSK, \
                                      ((uint32)I2C_ONE << IFX_SRC_SRCR_SRE_OFF))
  }
  #endif
}
#endif

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_lHwDisableProtocolTxEndIntr                     **
**                                       (I2c_HWUnitType HwUnit)              **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : Fucntion to enable protocol interrupt                    **
**                                                                            **
*******************************************************************************/
#if (I2C_ASYNC_READ_WRITE == STD_ON)
IFX_LOCAL_INLINE void I2c_lHwDisableProtocolTxEndIntr(I2c_HWUnitType HwUnit)
{
  I2C_SFR_RUNTIME_USER_MODE_MODIFY32(I2C_MODULE_X[HwUnit].IMSC.U, \
              I2C_IMSC_SFR_MSK,((uint32)I2C_ZERO << IFX_I2C_IMSC_I2C_P_INT_OFF))
  I2C_SFR_RUNTIME_USER_MODE_MODIFY32(I2C_MODULE_X[HwUnit].PIRQSM.U, \
             I2C_PIRQSM_SFR_MSK,((uint32)I2C_ZERO << IFX_I2C_PIRQSM_TX_END_OFF))
  
  #if (I2C_I2C0_EXIST == STD_ON)
  if (HwUnit == I2C_ZERO)
  {
    I2C_SFR_RUNTIME_MODIFY32(SRC_I2C_I2C0_P.U, I2C_SRC_SRCR_MSK, \
                                     ((uint32)I2C_ZERO << IFX_SRC_SRCR_SRE_OFF))
  }
  #endif
  #if (I2C_I2C1_EXIST == STD_ON)
  if (HwUnit == I2C_ONE)
  {
    I2C_SFR_RUNTIME_MODIFY32(SRC_I2C_I2C1_P.U, I2C_SRC_SRCR_MSK, \
                                     ((uint32)I2C_ZERO << IFX_SRC_SRCR_SRE_OFF))
  }
  #endif
}
#endif


/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : uint32 I2c_lHwGetErrorStatus(const Ifx_I2C *HwUnitPtr)   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : *HwUnitPtr - Pointer to the HW unit reg map              **
**                                                                            **
** Return value    : E_OK: No error has occurred.                             **
**                   E_NOT_OK: Error has occurred.                            **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : Fucntion to check whether any error has occurred         **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType I2c_lHwGetErrorStatus(const Ifx_I2C *HwUnitPtr)
{
  Std_ReturnType Returnvalue;
  uint32 ErrorStatus;
  uint32 ProtocolErrorStatus;
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  ErrorStatus = (uint32)((I2C_SFR_RUNTIME_USER_MODE_READ32( \
                   HwUnitPtr->ERRIRQSS.U)) & (I2C_ERROR_INTR_STATUS_VALID_MSK));
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  ProtocolErrorStatus = (uint32)((I2C_SFR_RUNTIME_USER_MODE_READ32( \
                     HwUnitPtr->PIRQSS.U)) & (I2C_PROTO_INTR_STATUS_VALID_MSK));

  if ((ErrorStatus == I2C_ZERO) && (ProtocolErrorStatus == I2C_ZERO))
  {
    Returnvalue = E_OK;
  }
  else
  {
    Returnvalue = E_NOT_OK;
  }
  return Returnvalue;
}


/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_lInitHwClearAllInterrupts(I2c_HWUnitType HwUnit)**
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : Fucntion to clear all the interrupts during init         **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void I2c_lInitHwClearAllInterrupts(I2c_HWUnitType HwUnit)
{
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_INIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].IMSC.U, \
                                                              (uint32)I2C_ZERO);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_INIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ICR.U, \
                                                   (uint32)I2C_CLEAR_INTERRUPT);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_INIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].PIRQSM.U, \
                                                              (uint32)I2C_ZERO);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_INIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].PIRQSC.U, \
                                          (uint32)I2C_CLEAR_PROTOCOL_INTERRUPT);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_INIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ERRIRQSM.U, \
                                                              (uint32)I2C_ZERO);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_INIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ERRIRQSC.U, \
                                             (uint32)I2C_CLEAR_ERROR_INTERRUPT);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_lDeInitHwClearAllInterrupts(                    **
**                                                  I2c_HWUnitType HwUnit)    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : Fucntion to clear all the interrupts during deinit       **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void I2c_lDeInitHwClearAllInterrupts(I2c_HWUnitType HwUnit)
{
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_DEINIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].IMSC.U, \
                                                              (uint32)I2C_ZERO);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_DEINIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ICR.U, \
                                                   (uint32)I2C_CLEAR_INTERRUPT);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_DEINIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].PIRQSM.U, \
                                                              (uint32)I2C_ZERO);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_DEINIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].PIRQSC.U, \
                                          (uint32)I2C_CLEAR_PROTOCOL_INTERRUPT);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_DEINIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ERRIRQSM.U, \
                                                              (uint32)I2C_ZERO);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_DEINIT_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ERRIRQSC.U, \
                                             (uint32)I2C_CLEAR_ERROR_INTERRUPT);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void I2c_lRunTimeHwClearAllInterrupts(                   **
**                                                  I2c_HWUnitType HwUnit)    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : HwUnit - HW unit index(ID)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : Fucntion to clear all the interrupts during Runtime      **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void I2c_lRunTimeHwClearAllInterrupts(I2c_HWUnitType HwUnit)
{
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].IMSC.U, \
                                                              (uint32)I2C_ZERO);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ICR.U, \
                                                   (uint32)I2C_CLEAR_INTERRUPT);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].PIRQSM.U, \
                                                              (uint32)I2C_ZERO);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].PIRQSC.U, \
                                          (uint32)I2C_CLEAR_PROTOCOL_INTERRUPT);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ERRIRQSM.U, \
                                                              (uint32)I2C_ZERO);
  /* IFX_MISRA_RULE_11_05_STATUS="I2C_MODULE_X" attempt to cast away
        volatile in terms of pointer access. */
  /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently 
     access the SFRs of multiple I2C kernels. */
  I2C_SFR_RUNTIME_USER_MODE_WRITE32(I2C_MODULE_X[HwUnit].ERRIRQSC.U, \
                                             (uint32)I2C_CLEAR_ERROR_INTERRUPT);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : I2c_StatusType I2c_lIsSyncHwUnitsStatus(void)            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : I2C_IDLE: I2C module is idle.                            **
**                   I2C_BUSY: I2C module is busy.                            **
**                                                                            **
** Description     : This function returns the                                **
**                    - Status of Synchronous HW units                        **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE I2c_StatusType I2c_lIsSyncHwUnitsStatus(void)
{
  I2c_StatusType Returnvalue;

  if (I2c_HWUnitStatus == I2C_ZERO)
  {
    Returnvalue = I2C_IDLE;
  }
  else
  {
    Returnvalue = I2C_BUSY;
  }
  return Returnvalue;
}


/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : I2c_StatusType I2c_lIsAsyncHwUnitsStatus(void)           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : I2C_IDLE: I2C module is idle.                            **
**                   I2C_BUSY: I2C module is busy.                            **
**                                                                            **
** Description     : This function returns the                                **
**                    - Status of Asynchronous HW units                       **
**                                                                            **
*******************************************************************************/
#if (I2C_ASYNC_READ_WRITE == STD_ON)
IFX_LOCAL_INLINE I2c_StatusType I2c_lIsAsyncHwUnitsStatus(void)
{
  I2c_StatusType Returnvalue;
  I2c_HWUnitType HwUnit;
  I2c_HWUnitType HwUnitQueue;

  Returnvalue = I2C_IDLE;

  for (HwUnit = I2C_ZERO; HwUnit < I2C_MAX_QUEUE; HwUnit++)
  {
    HwUnitQueue = I2c_kConfigPtr->HwUnitQueueIndex[HwUnit];
    if (HwUnitQueue != I2C_INVALID)
    {
      if (I2c_QueueStatus[HwUnitQueue] != I2C_QUEUE_EMPTY)
      {
        Returnvalue = I2C_BUSY;
        break;
      }
    }
  }
  return Returnvalue;
}
#endif

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : IFX_LOCAL_INLINE void I2c_lResetKernels(void)           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : N.A                                                      **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description     : This function resets SFR to default values by resetting  **
**                   kernel registers                                         **
**                                                                            **
*******************************************************************************/
#if (I2C_RESET_SFR_INIT == STD_ON)
IFX_LOCAL_INLINE void I2c_lResetKernels(void)
{
  #if ((I2C_I2C0_EXIST == STD_ON) || (I2C_I2C1_EXIST == STD_ON))
  uint32 RstStatus;
  uint32 WaitCount;
  volatile uint32 Readback;
  #endif

  /* Command to reset the Kernel */
  I2C_SFR_INIT_RESETENDINIT();
  #if (I2C_I2C0_EXIST == STD_ON)
  I2C_SFR_INIT_MODIFY32(I2C0_KRST0.U, I2C_KRST0_SFR_MSK,  \
                                     ((uint32)I2C_ONE << IFX_I2C_KRST0_RST_OFF))
  Readback = I2C_SFR_INIT_READ32(I2C0_KRST0.U);
  DSADC_SFR_DEINIT_WRITE32(I2C0_KRST1.U, I2C_KRST1_SFR_MSK);
  Readback = I2C_SFR_INIT_READ32(I2C0_KRST1.U);

  #endif
  #if (I2C_I2C1_EXIST == STD_ON)
  I2C_SFR_INIT_MODIFY32(I2C1_KRST0.U, I2C_KRST0_SFR_MSK,  \
                                     ((uint32)I2C_ONE << IFX_I2C_KRST0_RST_OFF))
  Readback = I2C_SFR_INIT_READ32(I2C1_KRST0.U);
  DSADC_SFR_DEINIT_WRITE32(I2C1_KRST1.U, I2C_KRST1_SFR_MSK);
  Readback = I2C_SFR_INIT_READ32(I2C1_KRST1.U);
  #endif
  I2C_SFR_INIT_SETENDINIT();


  #if (I2C_I2C0_EXIST == STD_ON)
    /* Wait for Timeout*/
  WaitCount = (uint32)I2c_KERNEL_RESET_WAIT_COUNTS;
  do
  {
    WaitCount--;
    RstStatus = (((uint32)I2C_SFR_INIT_READ32(I2C0_KRST0.U)) & \
          ((uint32)IFX_I2C_KRST0_RSTSTAT_MSK << IFX_I2C_KRST0_RSTSTAT_OFF));
    RstStatus = ((uint32)RstStatus >> IFX_I2C_KRST0_RSTSTAT_OFF);
  }while((RstStatus == I2C_ZERO)&&(WaitCount > I2C_ZERO));
  #endif
  
  #if (I2C_I2C1_EXIST == STD_ON)
    /* Wait for Timeout*/
  WaitCount = (uint32)I2c_KERNEL_RESET_WAIT_COUNTS;
  do
  {
    WaitCount--;
    RstStatus = (((uint32)I2C_SFR_INIT_READ32(I2C1_KRST0.U)) & \
          ((uint32)IFX_I2C_KRST0_RSTSTAT_MSK << IFX_I2C_KRST0_RSTSTAT_OFF));
    RstStatus = ((uint32)RstStatus >> IFX_I2C_KRST0_RSTSTAT_OFF);
  }while((RstStatus == I2C_ZERO)&&(WaitCount > I2C_ZERO));
  #endif
  
  /* Clear Reset Status */
  I2C_SFR_INIT_RESETENDINIT();
  #if (I2C_I2C0_EXIST == STD_ON)
  I2C_SFR_INIT_WRITE32(I2C0_KRSTCLR.U, I2C_KRSTCLR_SFR_MSK);
  Readback = I2C_SFR_INIT_READ32(I2C0_KRSTCLR.U);
  #endif
  #if (I2C_I2C1_EXIST == STD_ON)
  I2C_SFR_INIT_WRITE32(I2C1_KRSTCLR.U, I2C_KRSTCLR_SFR_MSK);
  Readback = I2C_SFR_INIT_READ32(I2C1_KRSTCLR.U);
  #endif  
  I2C_SFR_INIT_SETENDINIT();

  UNUSED_PARAMETER(Readback)
}
#endif

#define I2C_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/


/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/