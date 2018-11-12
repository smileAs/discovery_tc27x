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
**  $FILENAME   : Hssl.c $                                                   **
**                                                                            **
**  $CC VERSION : \main\42 $                                                 **
**                                                                            **
**  $DATE       : 2016-09-27 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                functionality of HSSL driver.                               **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
    TRACEABILITY : [cover parentID=] [/cover]
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "IfxSrc_reg.h"
#include "IfxHssl_reg.h"
#include "hssl.h"

/*******************************************************************************
**                      File Inclusion Check                                  **
*******************************************************************************/
/*    VERSION CHECK FOR HSSL MODULE INCLUSION */

#ifndef HSSL_SW_MAJOR_VERSION
  #error "HSSL_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef HSSL_SW_MINOR_VERSION
  #error "HSSL_SW_MINOR_VERSION is not defined. "
#endif

#ifndef HSSL_SW_PATCH_VERSION
  #error "HSSL_SW_PATCH_VERSION is not defined. "
#endif

#if ( HSSL_SW_MAJOR_VERSION != 1U )
  #error "HSSL_SW_MAJOR_VERSION does not match. "
#endif
#if ( HSSL_SW_MINOR_VERSION != 3U )
  #error "HSSL_SW_MINOR_VERSION does not match. "
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define HSSL_WRITE_PENDING        (1U)
#define HSSL_READ_PENDING         (2U)

#define HSSL_SET_FLAG             (0xffffffffU)
#define HSSL_TIMEOUT              (0xffU)
#define HSSL_WAIT_COUNT           (0x1000U)
#define HSSL_CHANNEL_CFG          (2U)

#define HSSL_FLAG_CFG             (0xFU)

#define HSSL_CLK_PREDIV_VAL       (0xFU)

#define HSSL_DATA_ADDR            (0xF00800B4U)
#define HSSL_DATA_ADDR1           (0xF0080094U)

#define HSSL_KERNEL_RESET_WAIT_COUNT  (0x00000100U)

/* Set and clear masks for Register's */
#define HSSL_CLR_MASK             (0xFFFFFFFFU)
#define HSSL_SET_MASK             (0x00000001U)

#define HSSL_CLC_DISR_CLEARMASK        (0x0000000AU)
#define HSSL_CLC_DISR_SETMASK          (0x00000001U)
#define HSSL_CLC_DISS_SETMASK          (0x00000002U)
#define HSSL_MFLAGSCL_INIC_CLEARMASK   (0x53FCFFFFU)
#define HSSL_MFLAGSCL_INIC_SETMASK     (0x80000000U)
#define HSSL_MFLAGS_INI_SETMASK        (0x80000000U)
#define HSSL_MFLAGSCL_ALL_SET_FLAG     (0xD3FCFFFFU)
#define HSSL_AWSTARTX_AWS_SETMASK      (0xFFFFFF00U)
#define HSSL_AWSTARTX_AWE_SETMASK      (0xFFFFFF00U)
#define HSSL_CFG_PREDIV_CLEARMASK      (0x000F0000U)
#define HSSL_CFG_PREDIV_SETMASK        (0x00003FFFU)
#define HSSL_AR_ARWX_SETMASK           (0x000000FFU)
#define HSSL_CFG_SMT_CLEARMASK         (0x000E3FFFU)
#define HSSL_CFG_SMT_SETMASK           (0x00010000U)
#define HSSL_CFG_SMR_CLEARMASK         (0x000D3FFFU)
#define HSSL_CFG_SMR_SETMASK           (0x00020000U)
#define HSSL_CFG_SCM_CLEARMASK         (0x000B3FFFU)
#define HSSL_CFG_SCM_SETMASK           (0x00040000U)
#define HSSL_SRE_CLEARMASK             (0x7F3F18FFU)
#define HSSL_SRE_SETMASK               (0x00000400U)
#define HSSL_MFLAGSEN_SETMASK          (0x23E0FFFFU)
#define HSSL_SRC_HSSLCOK_SRE_CLEARMASK (0xFF3F18FFU)
#define HSSL_SRC_HSSLCOK_SRE_SETMASK   (0x00000400U)
#define HSSL_ICONX_BSY_SETMASK         (0x00100000U)
#define HSSL_CRC_SETMASK               (0x0001FFFFU)
#define HSSL_ICONX_DATLEN_CLEARMASK    (0xFFFCFFFFU)
#define HSSL_ICONX_DATLEN_SETMASK      (0x00030000U)
#define HSSL_ICONX_TOREL_CLEARMASK     (0x00FFFFFFU)
#define HSSL_ICONX_TOREL_SETMASK       (0xFF000000U)
#define HSSL_ICONX_RWT_CLEARMASK       (0xFFF3FFFFU)
#define HSSL_ICONX_RWT_SETMASK         (0x000C0000U)
#define HSSL_ICONX_IDQ_CLEARMASK       (0xFFFFFFFEU)
#define HSSL_ICONX_IDQ_SETMASK         (0x00000001U)
#define HSSL_MFLAGS_SETMASK            (0xF3FCFFFFU)
#define HSSL_ISFC_RELCOUNT_CLEARMASK   (0xFFFF0000U)
#define HSSL_ISFC_RELCOUNT_SETMASK     (0x0000FFFFU)
#define HSSL_MFLAGSSET_TSES_CLEARMASK  (0xC3FCFFFFU)
#define HSSL_MFLAGSSET_TSES_SETMASK    (0x10000000U)
#define HSSL_MFLAGSSET_ISBS_CLEARMASK  (0xD3ECFFFFU)
#define HSSL_MFLAGSSET_ISBS_SETMASK    (0x00100000U)
#define HSSL_MFLAGSCL_TSEC_CLEARMASK   (0xC3FCFFFFU)
#define HSSL_MFLAGSCL_TSEC_SETMASK     (0x10000000U)
#define HSSL_MFLAGSCL_ISBC_CLEARMASK   (0xD3ECFFFFU)
#define HSSL_MFLAGSCL_ISBC_SETMASK     (0x00100000U)
#define HSSL_KRST0_RST_CLEARMASK       (0x00000002U)
#define HSSL_KRST0_RST_SETMASK         (0x00000001U)
#define HSSL_KRST0_RSTSTAT_SETMASK     (0x00000002U)
#define HSSL_AWENDX_AWE_SETMASK        (0xFFFFFF00U)

/*----------------------------------------------------------------------------*/
/* Magic numbers used for bit shift */
#define HSSL_SHIFT_BIT_1                     ((uint32)0x01U)
#define HSSL_SHIFT_BIT_2                     ((uint32)0x02U)
#define HSSL_SHIFT_BIT_3                     ((uint32)0x03U)
#define HSSL_SHIFT_BIT_4                     ((uint32)0x04U)
#define HSSL_SHIFT_BIT_5                     ((uint32)0x05U)
#define HSSL_SHIFT_BIT_6                     ((uint32)0x06U)
#define HSSL_SHIFT_BIT_7                     ((uint32)0x07U)
#define HSSL_SHIFT_BIT_8                     ((uint32)0x08U)
#define HSSL_SHIFT_BIT_9                     ((uint32)0x09U)
#define HSSL_SHIFT_BIT_10                    ((uint32)0x0AU)
#define HSSL_SHIFT_BIT_11                    ((uint32)0x0BU)
#define HSSL_SHIFT_BIT_12                    ((uint32)0x0CU)
#define HSSL_SHIFT_BIT_13                    ((uint32)0x0DU)
#define HSSL_SHIFT_BIT_14                    ((uint32)0x0EU)
#define HSSL_SHIFT_BIT_15                    ((uint32)0x0FU)
#define HSSL_SHIFT_BIT_16                    ((uint32)0x10U)
#define HSSL_SHIFT_BIT_17                    ((uint32)0x11U)
#define HSSL_SHIFT_BIT_18                    ((uint32)0x12U)
#define HSSL_SHIFT_BIT_20                    ((uint32)0x14U)
#define HSSL_SHIFT_BIT_21                    ((uint32)0x15U)
#define HSSL_SHIFT_BIT_22                    ((uint32)0x16U)
#define HSSL_SHIFT_BIT_24                    ((uint32)0x18U)
#define HSSL_SHIFT_BIT_31                    ((uint32)0x1FU)

#define HSSL_INIT_API_ACCESS                   ((uint8)72U)
#define HSSL_RUNTIME_API_ACCESS                ((uint8)73U)
/*----------------------------------------------------------------------------*/

#define HSSL_MASK_NOCLR           (0x00000000U)

#define HSSL_ADICR_REG_VAL        (0x00004F98U)

/* SRC register for HSSL are offset by 4 */
#define HSSL_SRC_ADDROFFSET       (0x04U)

/* SRC register addresses */
#define SRC_HSSLCOK0ADDR          (&(SRC_HSSLCOK0))
#define SRC_HSSLRDI0ADDR          (&(SRC_HSSLRDI0))
#define SRC_HSSLTRG0ADDR          (&(SRC_HSSLTRG0))
#define SRC_HSSLERR0ADDR          (&(SRC_HSSLERR0))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
extern uint16 HSSL_HANDLE_CALLBACK (uint8 HsslCode, uint32 HsslData);
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define HSSL_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

static uint8 Hssl_lSetTargetID(void) ;
static uint8 Hssl_lSetTargetAddress(const uint32 *StartAddress);
static uint8 Hssl_lWriteAck(Hssl_ChannelType Channel);
static uint8 Hssl_lSingleFrameWrite(const Hssl_DataTemplateType *WriteData,
       uint16 DataSize,Hssl_ChannelType Channel,uint8 InjectedError);
static void Hssl_lResetKernels(uint8 ApiAccessId);

#define HSSL_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/
 #define HSSL_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
  #include "MemMap.h"

  static uint32 Hssl_DataBuffer ;
  static uint32 Hssl_DataAddr ;
/*IFX_MISRA_RULE_08_07_STATUS=WriteData1 of the driver cannot be declared as a
 local variable,because address of this variable is passed to another API*/
  static Hssl_DataTemplateType WriteData1;
 /*IFX_MISRA_RULE_08_07_STATUS=WriteData2 of the driver cannot be declared as a
 local variable,because address of this variable is passed to another API*/
  static Hssl_DataTemplateType WriteData2;
  #define HSSL_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
  #include "MemMap.h"
/******************************************************************************
**                      Global Constant Definitions                           *
******************************************************************************/
#define HSSL_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

static volatile uint8 Hssl_DriverState;
static volatile uint8 Hssl_InterfaceMode;

#define HSSL_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#define HSSL_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#if (HSSL_DEV_ERROR_DETECT == STD_ON)
/*******************************************************************************
** Syntax :  IFX_LOCAL_INLINE uint32 Hssl_lInitCallVerify (uint8 ServiceId)   **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   ServiceId - API Service Id number                       **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:      Error - Informs whether error has found or not          **
**                                                                            **
** Description :      Local function :Service to verify whether Init has been **
**                                    called or report DET error              **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Hssl_lInitCallVerify(uint8 ServiceId)
{
  uint32 ErrorFlag;
  ErrorFlag = HSSL_ERR_NOT_FOUND;

  /* Verify whether Init had been called */
  if (Hssl_DriverState !=  HSSL_DRIVER_INITIALIZED)
  {
    Det_ReportError(
                     HSSL_MODULE_ID,
                     HSSL_MODULE_INSTANCE,
                     ServiceId,
                     HSSL_E_NOT_INITIALIZED
                   );/* End of report to  DET */
    ErrorFlag = HSSL_ERR_FOUND;
  }
  return (ErrorFlag);
}/* End of Hssl_lInitCallVerify() function */

/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint32 Hssl_lChannelVerify            **
**                    (uint8 ChannelNumber,uint8 ServiceId)                  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceId - API Service Id number                      **
**                    ChannelNumber - Channel number                         **
**                                                                           **
** Parameters (out):   None                                                  **
**                                                                           **
** Return value:      Error - Informs whether error has found or not         **
**                                                                           **
** Description :      Local function :Service to verify whether Channel is   **
**                                    correct or report DET error            **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint32 Hssl_lChannelVerify(uint8 ChannelNumber,\
                                                      uint8 ServiceId)
{
  uint32 ErrorFlag;
  ErrorFlag = HSSL_ERR_NOT_FOUND;

  /* Verify Channel Number */
  if(ChannelNumber >= HSSL_NUM_CHANNEL)
  {
    Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                    ServiceId,HSSL_E_INV_PARAM);

    ErrorFlag = HSSL_ERR_FOUND;
  }
  return (ErrorFlag);
}/* End of Hssl_lChannelVerify() function */

/*******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint32 Hssl_ldataSizeVerify            **
                      (uint16 DataSize,uint8 ServiceId)                       **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   ServiceId - API Service Id number                       **
**                    DataSize - size of the data                             **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:      Error - Informs whether error has found or not          **
**                                                                            **
** Description :      Local function :Service to verify whether data size is  **
**                                    correct or report DET error             **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Hssl_ldataSizeVerify(uint16 DataSize, uint8 ServiceId)
{
  uint32 ErrorFlag;
  ErrorFlag = HSSL_ERR_NOT_FOUND;
  /* Verify whether Init had been called */

  /* Data size can be 8 , 16 or  32 bit only */
  if(DataSize >= HSSL_MAX_DATA_SIZE)
  {
    Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                    ServiceId,HSSL_E_INV_PARAM);

    ErrorFlag = HSSL_ERR_FOUND;
  }
  return (ErrorFlag);
}/* End of Hssl_ldataSizeVerify() function */

/*******************************************************************************
** Syntax :    IFX_LOCAL_INLINE uint32 Hssl_lRunModeVerify(uint8 ServiceId)   **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   ServiceId - API Service Id number                       **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:      Error - Informs whether error has found or not          **
**                                                                            **
** Description :      Local function :Service to verify whether Init has been **
**                                    called or report DET error              **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Hssl_lRunModeVerify(uint8 ServiceId)
{
  uint32 ErrorFlag;
  ErrorFlag = HSSL_ERR_NOT_FOUND;

  /* Verify if driver in RUN Mode*/
  if (Hssl_InterfaceMode !=  HSSL_MODE_RUN)
  {
    Det_ReportError(
                     HSSL_MODULE_ID,
                     HSSL_MODULE_INSTANCE,
                     ServiceId,
                     HSSL_E_INV_MODE
                   );
    ErrorFlag = HSSL_ERR_FOUND;
  }
  return (ErrorFlag);
}/* End of Hssl_lRunModeVerify() function */
#endif
   /*End Of HSSL_DEV_ERROR_DETECT*/

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
uint8 Hssl_SetMode(uint8 Mode)
{
  uint8 RetVal ;

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorFlag;

    RetVal = 1U;
    ErrorFlag =  HSSL_ERR_NOT_FOUND;

    /* Check If the Mode passed is a Valid one */
    if((HSSL_MODE_RUN == Mode) || (HSSL_MODE_DISABLE == Mode) || \
       (HSSL_MODE_INIT == Mode))
    {
      /* Check the mode transition */
      if((HSSL_MODE_DISABLE == Hssl_InterfaceMode)&&(HSSL_MODE_RUN == Mode))
      {
          Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                          HSSL_SID_MODE,HSSL_E_INV_MODE);
          /*Error flag is set*/
          ErrorFlag = HSSL_ERR_FOUND;
      }
    }
    else /* Mode parameter is wrong */
    {
      Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                        HSSL_SID_MODE,HSSL_E_INV_PARAM);

      ErrorFlag = HSSL_ERR_FOUND;
    }
    /*If no error present*/
    if (HSSL_ERR_FOUND != ErrorFlag)
  #endif
    /*End Of HSSL_DEV_ERROR_DETECT*/
    {
      RetVal = 0U ;
      /* check the mode and set the sfr accordingly */
      switch(Mode)
      {
        case HSSL_MODE_DISABLE:
        {
          HSSL_SFR_RUNTIME_RESETENDINIT();

          /* Disable HSSL module */
          HSSL_SFR_RUNTIME_MODIFY32(HSSL_CLC.U,HSSL_CLC_DISR_CLEARMASK, \
                                                    HSSL_CLC_DISR_SETMASK)

          /* Check the status bit DISS to be Set */
          if ((HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_CLC.U) & \
                               HSSL_CLC_DISS_SETMASK) >> HSSL_SHIFT_BIT_1)
          {
            Hssl_InterfaceMode = HSSL_MODE_DISABLE ;
          }
          else
          {
            RetVal = 1U ;
          }
          HSSL_SFR_RUNTIME_SETENDINIT();
        }
        break;

        case HSSL_MODE_INIT:
        {
          Hssl_InterfaceMode = HSSL_MODE_INIT ;
        }
        break;

        case HSSL_MODE_RUN:
        {
          /* Set the Module to RUN mode */
          HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(HSSL_MFLAGSCL.U,   \
                      HSSL_MFLAGSCL_INIC_CLEARMASK,HSSL_MFLAGSCL_INIC_SETMASK)

          while((HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_MFLAGS.U) \
                              & HSSL_MFLAGS_INI_SETMASK) >> HSSL_SHIFT_BIT_31)
          {
            /* Dummy */
          }
          Hssl_InterfaceMode = HSSL_MODE_RUN;
        }
        break;

        default:
          RetVal = 1U ;
        break;
      }
    }/* if (HSSL_ERR_FOUND != ErrorFlag)   */
  return(RetVal);
}
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
**                                                                            **
*******************************************************************************/
uint8 Hssl_Reset(void)
{
  uint8 RetVal ;

  /* Clear All Status and Error registers */
  HSSL_SFR_RUNTIME_USER_MODE_WRITE32(HSSL_MFLAGSCL.U,   \
                                           HSSL_MFLAGSCL_ALL_SET_FLAG);

  /* Reset HSSL module */
  Hssl_lResetKernels (HSSL_RUNTIME_API_ACCESS);

  /* Disable HSSL module */
  RetVal = Hssl_SetMode(HSSL_MODE_DISABLE);

  /* Reset Driver State */
  Hssl_DriverState = HSSL_DRIVER_UNINITIALIZED ;

  return(RetVal);
}
/*******************************************************************************
** Syntax : Hssl_Init(uint16 ClockPreDivider)                                 **
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
uint8  Hssl_Init(uint16 ClockPreDivider)
{
  uint8 RetVal,ClkDisableChk ;
  RetVal = 0U ;

  /* Enable HSSL module */
  HSSL_SFR_INIT_RESETENDINIT();

  HSSL_SFR_INIT_WRITE32(HSSL_CLC.U, HSSL_MOD_ENABLE);

  HSSL_SFR_INIT_SETENDINIT();

  ClkDisableChk = (uint8)((HSSL_SFR_INIT_USER_MODE_READ32(HSSL_CLC.U) & \
                               HSSL_CLC_DISS_SETMASK) >> HSSL_SHIFT_BIT_1);

  /* Check the status bit DISS is Zero*/
  if (0U == ClkDisableChk)
  {
#if (HSSL_RESET_SFR_AT_INIT == STD_ON)
    Hssl_lResetKernels(HSSL_INIT_API_ACCESS);
#endif

      /* Set the Global Pre-divider */
    HSSL_SFR_INIT_USER_MODE_MODIFY32(HSSL_CFG.U, HSSL_CFG_PREDIV_CLEARMASK,  \
                            (uint32)ClockPreDivider & HSSL_CFG_PREDIV_SETMASK)

    /* Set the start and End address of access windows
       where HSSL access are allowed */
    HSSL_SFR_INIT_WRITE32(HSSL_AWSTART0.U, \
               (HSSL_ACCESS_WINDOW_START_ADDR0 & HSSL_AWSTARTX_AWS_SETMASK));

    HSSL_SFR_INIT_WRITE32(HSSL_AWEND0.U, \
                   (HSSL_ACCESS_WINDOW_END_ADDR0 & HSSL_AWENDX_AWE_SETMASK));

    HSSL_SFR_INIT_WRITE32(HSSL_AWSTART1.U, \
               (HSSL_ACCESS_WINDOW_START_ADDR1 & HSSL_AWSTARTX_AWS_SETMASK));

    HSSL_SFR_INIT_WRITE32(HSSL_AWEND1.U, \
                   (HSSL_ACCESS_WINDOW_END_ADDR1 & HSSL_AWENDX_AWE_SETMASK));

    HSSL_SFR_INIT_WRITE32(HSSL_AWSTART2.U, \
               (HSSL_ACCESS_WINDOW_START_ADDR2 & HSSL_AWSTARTX_AWS_SETMASK));

    HSSL_SFR_INIT_WRITE32(HSSL_AWEND2.U, \
                   (HSSL_ACCESS_WINDOW_END_ADDR3 & HSSL_AWENDX_AWE_SETMASK));

    HSSL_SFR_INIT_WRITE32(HSSL_AWSTART3.U, \
               (HSSL_ACCESS_WINDOW_START_ADDR3 & HSSL_AWSTARTX_AWS_SETMASK));

    HSSL_SFR_INIT_WRITE32(HSSL_AWEND3.U, \
                   (HSSL_ACCESS_WINDOW_END_ADDR3 & HSSL_AWENDX_AWE_SETMASK));

    /* Configure read/write access for different windows  */
    HSSL_SFR_INIT_WRITE32(HSSL_AR.U,((HSSL_ACCESS_MODE_0 | \
                           (HSSL_ACCESS_MODE_1 << HSSL_SHIFT_BIT_2) |  \
                                 (HSSL_ACCESS_MODE_2 << HSSL_SHIFT_BIT_4) |  \
          (HSSL_ACCESS_MODE_3 << HSSL_SHIFT_BIT_6)) & HSSL_AR_ARWX_SETMASK));

    /* Switch to run mode */
    HSSL_SFR_INIT_USER_MODE_MODIFY32(HSSL_MFLAGSCL.U,   \
                      HSSL_MFLAGSCL_INIC_CLEARMASK,HSSL_MFLAGSCL_INIC_SETMASK)

    /* Wait until the mode changes */
    while((HSSL_SFR_INIT_USER_MODE_READ32(HSSL_MFLAGS.U) \
                              & HSSL_MFLAGS_INI_SETMASK) >> HSSL_SHIFT_BIT_31)
    {}

    /* Set Streaming Mode to Continuous / Single for Tx and Rx */
    HSSL_SFR_INIT_USER_MODE_MODIFY32(HSSL_CFG.U, HSSL_CFG_SMT_CLEARMASK, \
          (uint32)(((uint32)HSSL_STREAMING_MODE_TX << HSSL_SHIFT_BIT_16) \
                                                  & HSSL_CFG_SMT_SETMASK))

    HSSL_SFR_INIT_USER_MODE_MODIFY32(HSSL_CFG.U, HSSL_CFG_SMR_CLEARMASK, \
          (uint32)(((uint32)HSSL_STREAMING_MODE_RX << HSSL_SHIFT_BIT_17) \
                                                  & HSSL_CFG_SMR_SETMASK))

    /* Set Channel 2 Mode to Streaming / Command */
    HSSL_SFR_INIT_USER_MODE_MODIFY32(HSSL_CFG.U, HSSL_CFG_SCM_CLEARMASK, \
          (uint32)(((uint32)HSSL_STREAMING_CH_MODE << HSSL_SHIFT_BIT_18) \
                                                  & HSSL_CFG_SCM_SETMASK))

    /* Enable EXI interrupt */
    HSSL_SFR_INIT_MODIFY32(SRC_HSSLEXI.U, HSSL_SRE_CLEARMASK, \
                                                    HSSL_SRE_SETMASK)

    /* Set Target ID Address */
    HSSL_SFR_INIT_WRITE32(HSSL_TIDADD.U, HSSL_TIDADD_ADDR);

    /* Set Driver State to Initialised */
    Hssl_DriverState = HSSL_DRIVER_INITIALIZED ;
  }
  else
  {
    RetVal =  1U ;

    /* Reset Driver State */
    Hssl_DriverState = HSSL_DRIVER_UNINITIALIZED ;
  }
  return (RetVal);
}

/*******************************************************************************
** Syntax : uint8 Hssl_InitChannel( Hssl_ChannelType Channel ,                **
**     uint8 WriteAck, uint8 ReadAns,  uint8 Trigger, uint8 TimeoutErr,       **
**     uint8 TransID, uint8 AckErr)                                           **
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
uint8 Hssl_InitChannel(Hssl_ChannelType Channel, uint8 WriteAck, uint8 ReadAns,
                  uint8 Trigger, uint8 TimeoutErr, uint8 TransID, uint8 AckErr)
{
  volatile uint32 * Address;
  uint32 Offset,RegVal;
  uint8 RetVal ;

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
  uint32 ErrorFlag;

  RetVal = 1U;
  ErrorFlag = Hssl_lInitCallVerify(HSSL_SID_INIT_CH);
  /*If Error Flag is not set*/
  if (HSSL_ERR_FOUND != ErrorFlag)
  {
    /* Verify Channel Number parameter */
    ErrorFlag = Hssl_lChannelVerify(Channel.Number , HSSL_SID_INIT_CH);
  }

  /*If no error present*/
  if (HSSL_ERR_FOUND != ErrorFlag)
  #endif   /*End Of HSSL_DEV_ERROR_DETECT*/
  {
    RetVal = 0U;

    /* Enable/Disable Error(NACK,TTAG,Timeout) Interrupt */
    RegVal = (uint32)(HSSL_SFR_INIT_USER_MODE_READ32(HSSL_MFLAGSEN.U) | \
                ((uint32)AckErr | ((uint32)TransID << HSSL_SHIFT_BIT_4) | \
                                  ((uint32)TimeoutErr << HSSL_SHIFT_BIT_8)));

    HSSL_SFR_INIT_USER_MODE_WRITE32(HSSL_MFLAGSEN.U,(unsigned_int)(RegVal & \
                                                    HSSL_MFLAGSEN_SETMASK));

    Offset = (uint32)(Channel.Number) * HSSL_SRC_ADDROFFSET ;

    /* Check if Command OK interrupt needs to be enabled */
    if(WriteAck)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
       efficiently access the SFRs of multiple HSSL Channels.*/
      Address = ((volatile uint32 *)(void *)SRC_HSSLCOK0ADDR + Offset);

      HSSL_SFR_INIT_MODIFY32(*Address, HSSL_SRE_CLEARMASK, HSSL_SRE_SETMASK)

    }

    /* If Read response frame interrupt is needed, enable RDI interrupt */
    if(ReadAns)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
       efficiently access the SFRs of multiple HSSL Channels.*/
      Address = ((volatile uint32 *)(void *)SRC_HSSLRDI0ADDR + Offset);

      HSSL_SFR_INIT_MODIFY32(*Address, HSSL_SRE_CLEARMASK, HSSL_SRE_SETMASK)

    }

    /* Check if trigger interrupt is needed */
    if(Trigger)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
       efficiently access the SFRs of multiple HSSL Channels.*/
      Address = ((volatile uint32 *)(void *)SRC_HSSLTRG0ADDR + Offset);

      HSSL_SFR_INIT_MODIFY32(*Address, HSSL_SRE_CLEARMASK, HSSL_SRE_SETMASK)

    }

    /* Any of the error conditions generate a ERR interrupt */
    if((TimeoutErr != 0U) || (TransID !=0U) || (AckErr != 0U))
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
       efficiently access the SFRs of multiple HSSL Channels.*/
      Address = ((volatile uint32 *)(void *)SRC_HSSLERR0ADDR + Offset);

      HSSL_SFR_INIT_MODIFY32(*Address, HSSL_SRE_CLEARMASK, HSSL_SRE_SETMASK)

    }

  }/* if (HSSL_ERR_FOUND != ErrorFlag)    */

  return(RetVal);
}
/*******************************************************************************
** Syntax : uint8 Hssl_Write( const Hssl_DataTemplateType *WriteData,         **
**                         uint16 DataSize, Hssl_ChannelType Channel,         **
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
**                    Channel:: HSSL Channel to used.                         **
**                    InjectedError: injected error (if required)             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, error code otherwise.        **
**                                                                            **
** Description : Performs a direct write transfer.                            **
**                                                                            **
*******************************************************************************/
uint8 Hssl_Write(const Hssl_DataTemplateType *WriteData,uint16 DataSize,
                   Hssl_ChannelType Channel,uint8 InjectedError)
{
  uint8 RetVal ;

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
  uint32 ErrorFlag;

  RetVal = 1U ;
  /* Check if Init is called or not */
  ErrorFlag = Hssl_lInitCallVerify(HSSL_SID_WRITE);

  /*If Error Flag is not set*/
  if (HSSL_ERR_FOUND != ErrorFlag)
  {
    /* Verify Channel Number parameter */
    ErrorFlag = Hssl_lChannelVerify(Channel.Number , HSSL_SID_WRITE);

    if (HSSL_ERR_FOUND != ErrorFlag)
    {
     /* verify the data size */
     ErrorFlag = Hssl_ldataSizeVerify(DataSize , HSSL_SID_WRITE);

      if (HSSL_ERR_FOUND != ErrorFlag)
      {
      /* Verify the mode to be run */
        ErrorFlag = Hssl_lRunModeVerify(HSSL_SID_WRITE);

        if (HSSL_ERR_FOUND != ErrorFlag)
        {
        /* verify the data pointer */
          if(NULL_PTR == WriteData->Data)
          {
            Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                            HSSL_SID_WRITE,HSSL_E_INV_POINTER);
            ErrorFlag = HSSL_ERR_FOUND ;
          }
        }
      }
    }
  }
  /*If no error present*/
  if (HSSL_ERR_FOUND != ErrorFlag)
  #endif
  {
   RetVal= Hssl_lSingleFrameWrite(WriteData,DataSize,Channel,InjectedError);
  }

  return(RetVal) ;
}
/*******************************************************************************
** Syntax : uint8 Hssl_WriteAck( Hssl_ChannelType Channel)                    **
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
uint8 Hssl_WriteAck(Hssl_ChannelType Channel)
{
  uint8 RetVal ;

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
  uint32 ErrorFlag;
  RetVal = 1U ;

  /* check if Init is called or not */
  ErrorFlag = Hssl_lInitCallVerify(HSSL_SID_WRITE_ACK);

  /*If Error Flag is not set*/
  if (HSSL_ERR_FOUND != ErrorFlag)
  {
    /* Verify Channel Number parameter */
    ErrorFlag = Hssl_lChannelVerify(Channel.Number , HSSL_SID_WRITE_ACK);
    if (HSSL_ERR_FOUND != ErrorFlag)
    {
    /* Verify the mode to be run */
      ErrorFlag = Hssl_lRunModeVerify(HSSL_SID_WRITE_ACK);
    }
  }
  /*If no Error present*/
  if (HSSL_ERR_FOUND != ErrorFlag)
  #endif
  /* #if ( HSSL_DEV_ERROR_DETECT == STD_ON ) */
  {
    RetVal = Hssl_lWriteAck(Channel) ;
  }  /* if (HSSL_ERR_FOUND != ErrorFlag) */
  return RetVal;
}
/*******************************************************************************
** Syntax : uint8 Hssl_Read(const Hssl_DataTemplateType *DataAddress,         **
**            uint16 DataSize,Hssl_ChannelType Channel,uint8 InjectedError)   **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  DataAddress :Pointer to Hssl_DataTemplateType structure **
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
uint8 Hssl_Read(const Hssl_DataTemplateType *DataAddress,uint16 DataSize,
                  Hssl_ChannelType Channel,uint8 InjectedError)
{
  volatile Ifx_HSSL_I_ICON *CtrlRegPtr;
  uint32 CRCRegVal ;
  uint8 RetVal ;

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorFlag;

    RetVal = 1U ;
    /* check if Init is called or not */
    ErrorFlag = Hssl_lInitCallVerify(HSSL_SID_READ);

    /*If Error Flag is not set*/
    if (HSSL_ERR_FOUND != ErrorFlag)
    {
      /* Verify Channel Number parameter */
      ErrorFlag = Hssl_lChannelVerify(Channel.Number , HSSL_SID_READ);

      /* verify the data size */
      if (HSSL_ERR_FOUND != ErrorFlag)
      {
        ErrorFlag = Hssl_ldataSizeVerify(DataSize , HSSL_SID_READ);

        /* Verify the mode to be run */
        if (HSSL_ERR_FOUND != ErrorFlag)
        {
          ErrorFlag = Hssl_lRunModeVerify(HSSL_SID_READ);
          /* verify the data pointer */
          if (HSSL_ERR_FOUND != ErrorFlag)
          {
            if(NULL_PTR == DataAddress->Address)
            {
              Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                              HSSL_SID_READ,HSSL_E_INV_POINTER);
              ErrorFlag = HSSL_ERR_FOUND ;
            }
          }
        }
      }
    }

    /*If no Error present*/
    if (HSSL_ERR_FOUND != ErrorFlag)
  #endif
    {
      RetVal = 1U ;

      CtrlRegPtr = (volatile Ifx_HSSL_I_ICON *)(void *)\
                                     (&MODULE_HSSL.I[Channel.Number].ICON);
      /*  Read ICONx.BSY bit to check if Channel is Busy or Available */
      if(((HSSL_SFR_RUNTIME_USER_MODE_READ32(CtrlRegPtr->U) \
                  & HSSL_ICONX_BSY_SETMASK) >> HSSL_SHIFT_BIT_20) == 0U)
      {
        /* If Error Injection is needed, set it in CRC register */
        if(InjectedError)
        {
          CRCRegVal = (((uint32)InjectedError) | ((uint32)1 << \
                                                        HSSL_SHIFT_BIT_16));

          HSSL_SFR_RUNTIME_WRITE32(HSSL_CRC.U,(unsigned_int)\
                                             (CRCRegVal & HSSL_CRC_SETMASK));

        }

        /* Write data size in ICONx */
        HSSL_SFR_RUNTIME_USER_MODE_MODIFY32( \
                                    MODULE_HSSL.I[Channel.Number].ICON.U, \
                                            HSSL_ICONX_DATLEN_CLEARMASK, \
          (((uint32)DataSize << HSSL_SHIFT_BIT_16) & HSSL_ICONX_DATLEN_SETMASK))

        /* Write Time Out Value in ICONx */
        HSSL_SFR_RUNTIME_USER_MODE_MODIFY32( \
                                 MODULE_HSSL.I[Channel.Number].ICON.U, \
                      HSSL_ICONX_TOREL_CLEARMASK, (((uint32)Channel.Timeout \
                             << HSSL_SHIFT_BIT_24) & HSSL_ICONX_TOREL_SETMASK))

        /* Write ICONx.RWT with 0x1 Read Frame */
        HSSL_SFR_RUNTIME_USER_MODE_MODIFY32( \
                                  MODULE_HSSL.I[Channel.Number].ICON.U, \
               HSSL_ICONX_RWT_CLEARMASK, (((uint32)1 << HSSL_SHIFT_BIT_18) \
                                                & HSSL_ICONX_RWT_SETMASK))

        /* Write IRWAx register with Address */
        HSSL_SFR_RUNTIME_USER_MODE_WRITE32( \
                 MODULE_HSSL.I[Channel.Number].IRWA.U,*DataAddress->Address);

        RetVal = 0U;

      }/* Channel is Busy */
    } /* if (HSSL_ERR_FOUND != ErrorFlag)   */
  return(RetVal);
}

/*******************************************************************************
** Syntax : uint32 Hssl_Id(uint32 *StoreAddress)                              **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : StoreAddress : Pointer to the Address location/variable  **
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
uint32 Hssl_Id(uint32 *StoreAddress)
{
  uint32 RetVal,ExpectMask ;
  volatile Ifx_HSSL_I_ICON *CtrlRegPtr;
  volatile uint32 Qflags;

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorFlag;

    RetVal = 1U ;
    /* check if Init is called or not */
    ErrorFlag = Hssl_lInitCallVerify(HSSL_SID_READ_ID);

    /* verify the driver Mode */
    if (HSSL_ERR_FOUND != ErrorFlag)
    {
      ErrorFlag = Hssl_lRunModeVerify(HSSL_SID_READ_ID);

      /* verify the data pointer */
      if (HSSL_ERR_FOUND != ErrorFlag)
      {
        if(NULL_PTR == StoreAddress)
        {
          Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                          HSSL_SID_READ_ID,HSSL_E_INV_POINTER);
          ErrorFlag = HSSL_ERR_FOUND ;
        }
      }
    }
    /*If no Error present*/
    if (HSSL_ERR_FOUND != ErrorFlag)
  #endif
    {
      /* Set the Target ID Address in slave device */
      RetVal = Hssl_lSetTargetID( ) ;

      if(0U == RetVal)
      {
        RetVal  = 1U;

        /* Read ID is sent on Channel 0 always */
        CtrlRegPtr = \
        (volatile Ifx_HSSL_I_ICON *)(void *)(&MODULE_HSSL.I[0U].ICON);
        /*  Read ICONx.BSY bit to check if Channel is Busy or Available */
        if(((HSSL_SFR_RUNTIME_USER_MODE_READ32(CtrlRegPtr->U) \
                  & HSSL_ICONX_BSY_SETMASK) >> HSSL_SHIFT_BIT_20) == 0U)
        {
          /* LOad Write Time Out Reload Value in ICONx */
          HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_HSSL.I[0U].ICON.U, \
            HSSL_ICONX_TOREL_CLEARMASK, (uint32)(((uint32)HSSL_TIMEOUT \
                           << HSSL_SHIFT_BIT_24) & HSSL_ICONX_TOREL_SETMASK))

          /* Set Address from which the target ID is fetched */
          HSSL_SFR_RUNTIME_WRITE32(HSSL_TIDADD.U,*StoreAddress);

          /* Request a Read ID Frame */
          HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_HSSL.I[0U].ICON.U, \
                           HSSL_ICONX_IDQ_CLEARMASK, HSSL_ICONX_IDQ_SETMASK)

          /* Check Ix and Ex signals to check if any request is pending */
          do
          {
            Qflags = HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_QFLAGS.U);
          }
          while(Qflags &  \
          (((uint32)HSSL_READ_PENDING << HSSL_SHIFT_BIT_16)|1U));

          /*****************************************************
           check RetVal and return
          *****************************************************/
          /* NACK */
          ExpectMask = 1U;
          /* TTE */
          ExpectMask = (ExpectMask | ((uint32)1U << HSSL_SHIFT_BIT_4));
          /* TIMEOUT */
          ExpectMask = (ExpectMask | ((uint32)1U << HSSL_SHIFT_BIT_8));
          /* UNEXPECTED */
          ExpectMask = (ExpectMask | ((uint32)1U << HSSL_SHIFT_BIT_12));
          /* SRIE,PIE1,PIE2,CRCE */
          ExpectMask = (ExpectMask | \
                           ((uint32)HSSL_FLAG_CFG << HSSL_SHIFT_BIT_22));

          if(HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_MFLAGS.U) & ExpectMask)
          {
            RetVal = (uint32)((HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_MFLAGS.U)\
                                                   & HSSL_MFLAGS_SETMASK));
          }
          else
          {
            RetVal  = 0U;
            *StoreAddress = \
             (uint32)HSSL_SFR_RUNTIME_USER_MODE_READ32(MODULE_HSSL.I[0U].IRD.U);
          }
        }  /* Channel is Busy */
      }
    }/* if (HSSL_ERR_FOUND != ErrorFlag)    */
  return(RetVal);
}

/*******************************************************************************
** Syntax : uint8 Hssl_ReadRply (struct Hssl_DataTemplateType *ReadData,      **
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
uint8 Hssl_ReadRply (const Hssl_DataTemplateType *ReadData,
                      Hssl_ChannelType Channel)
{
  uint32 Qflags,ExpectMask;
  uint32 *DataPtr ;
  uint8 RetVal ;

  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorFlag;
  #endif

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
    RetVal = 1U ;
    /* check if Init is called or not */
    ErrorFlag = Hssl_lInitCallVerify(HSSL_SID_READ_REPLY);

    /*If Error Flag is not set*/
    if (HSSL_ERR_FOUND != ErrorFlag)
    {
      /* Verify Channel Number parameter */
      ErrorFlag = Hssl_lChannelVerify(Channel.Number , HSSL_SID_READ_REPLY);

      /* verify the driver Mode */
      if (HSSL_ERR_FOUND != ErrorFlag)
      {
        ErrorFlag = Hssl_lRunModeVerify(HSSL_SID_READ_REPLY);

        /* verify the data pointer */
        if (HSSL_ERR_FOUND != ErrorFlag)
        {
          if(NULL_PTR == ReadData->Data)
          {
            Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                            HSSL_SID_READ_REPLY,HSSL_E_INV_POINTER);
            ErrorFlag = HSSL_ERR_FOUND ;
          }
        }
      }
    }
    /*If no Error present*/
    if (HSSL_ERR_FOUND != ErrorFlag)
  #endif
    {
      RetVal = 0U ;

      Qflags = HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_QFLAGS.U);

      /* Check Ix and Ex signals to check if any request is pending */
      while(Qflags & (((uint32)HSSL_READ_PENDING << (HSSL_SHIFT_BIT_16 + \
      (Channel.Number*(uint32)HSSL_CHANNEL_CFG)))
       |((uint32)1U << Channel.Number)))
      {
        Qflags = HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_QFLAGS.U);
      }

      /*****************************************************
      check RetVal and return
      *****************************************************/
      ExpectMask = ((uint32)1U << (uint32)Channel.Number);        /* NACK */
      /* TTE */
      ExpectMask = ExpectMask |
      ((uint32)1U << (Channel.Number + HSSL_SHIFT_BIT_4));
      /*TIMEOUT*/
      ExpectMask = ExpectMask |
      ((uint32)1U << (Channel.Number + HSSL_SHIFT_BIT_8));
      ExpectMask = ExpectMask |
      ((uint32)1U << (Channel.Number + HSSL_SHIFT_BIT_12));
      /* SRIE,PIE1,PIE2,CRCE */
      ExpectMask = ExpectMask | (uint32)((uint32)HSSL_FLAG_CFG \
                                                 << HSSL_SHIFT_BIT_22);

      if(HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_MFLAGS.U) & ExpectMask)
      {
        RetVal = 1U;
      }
      else
      {
        DataPtr = ReadData->Data ;
        *DataPtr = (uint32)HSSL_SFR_RUNTIME_USER_MODE_READ32( \
                                         MODULE_HSSL.I[Channel.Number].IRD.U);
      }
    }/* if (HSSL_ERR_FOUND != ErrorFlag) */
  return RetVal;
}
/*******************************************************************************
** Syntax : uint8 Hssl_StartStream( uint32 *SourceAddressStart,               **
**                           uint16 DataSize, uint8 InjectedError)            **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : SourceAddressStart : Pointer to address containing start **
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
uint8 Hssl_StartStream (uint32 *SourceAddressStart,uint16 DataSize,
                             uint8 InjectedError)
{
  uint32 CRCRegVal ;
  uint8 RetVal ;

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorFlag;

    RetVal = 1U ;
    /* check if Init is called or not */
    ErrorFlag = Hssl_lInitCallVerify(HSSL_SID_STREAM);

    /*If Error Flag is not set*/
    if (HSSL_ERR_FOUND != ErrorFlag)
    {
      /* Verify the mode to be run */
      ErrorFlag = Hssl_lRunModeVerify(HSSL_SID_STREAM);
      /* verify the data pointer */
      if (HSSL_ERR_FOUND != ErrorFlag)
      {
        if(NULL_PTR == SourceAddressStart)
        {
          Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                          HSSL_SID_STREAM,HSSL_E_INV_POINTER);
          ErrorFlag = HSSL_ERR_FOUND ;
        }
      }
    }
    /*If no Error present*/
    if (HSSL_ERR_FOUND != ErrorFlag)
  #endif
    {
      RetVal = Hssl_lSetTargetAddress (SourceAddressStart);

      if(0U == RetVal)
      {
        /*  Read ICONx.BSY bit to check if Channel is Busy or Available */
        if(((HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_I2_ICON.U) \
                  & HSSL_ICONX_BSY_SETMASK) >> HSSL_SHIFT_BIT_20) == 0U)
        {
          if(InjectedError)
          {
            CRCRegVal = (((uint32)InjectedError) | \
                                            ((uint32)1 << HSSL_SHIFT_BIT_16));

            HSSL_SFR_RUNTIME_WRITE32(HSSL_CRC.U,(unsigned_int)\
                                         (CRCRegVal & HSSL_CRC_SETMASK));
          }

          /* Initiator Address */
          HSSL_SFR_RUNTIME_USER_MODE_WRITE32(HSSL_IS_SA0.U, \
                                                 (uint32)SourceAddressStart);

          HSSL_SFR_RUNTIME_USER_MODE_WRITE32(HSSL_IS_SA1.U, \
                                                 (uint32)SourceAddressStart);

          /* Initiator reload counter (burst numbers, one burst is 8 words)*/
          HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(HSSL_ISFC.U, \
                  HSSL_ISFC_RELCOUNT_CLEARMASK, (((uint32)DataSize - 0x1U) \
                                                & HSSL_ISFC_RELCOUNT_SETMASK))

          /* SRI clk pre divider for timer */
          HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(HSSL_CFG.U, \
                         HSSL_CFG_PREDIV_CLEARMASK, HSSL_CLK_PREDIV_VAL \
                                                   & HSSL_CFG_PREDIV_SETMASK)

          /* Timeout Reload Value */
          HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(HSSL_I2_ICON.U, \
                      HSSL_ICONX_TOREL_CLEARMASK, HSSL_ICONX_TOREL_SETMASK)

          /* Start streaming */
          HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(HSSL_MFLAGSSET.U, \
                HSSL_MFLAGSSET_TSES_CLEARMASK, HSSL_MFLAGSSET_TSES_SETMASK)

          HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(HSSL_MFLAGSSET.U, \
                HSSL_MFLAGSSET_ISBS_CLEARMASK, HSSL_MFLAGSSET_ISBS_SETMASK)
        }
      }
    }/* if (HSSL_ERR_FOUND != ErrorFlag)  */
  return(RetVal);
}
/******************************************************************************
** Syntax : void Hssl_StopStream(void)                                       **
**                                                                           **
** Service ID:  0x0B                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  Non reentrant                                                **
**                                                                           **
** Parameters (in) : None                                                    **
**                                                                           **
** Parameters (out):  None                                                   **
**                                                                           **
** Return value    : None.                                                   **
**                                                                           **
** Description :  Stops the ongoing data streaming                           **
**                                                                           **
******************************************************************************/
void Hssl_StopStream(void)
{
  /*Disable the Target Data Streaming*/
  HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(HSSL_MFLAGSCL.U, \
        HSSL_MFLAGSCL_TSEC_CLEARMASK, HSSL_MFLAGSCL_TSEC_SETMASK)

  /*Clear Initiator Stream Block Request to Stop Data Streaming*/
  HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(HSSL_MFLAGSCL.U, \
        HSSL_MFLAGSCL_ISBC_CLEARMASK, HSSL_MFLAGSCL_ISBC_SETMASK)

}

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
**            includes array containing write Address and Data to be written  **
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
** Description : Performs multiple write transfers.                           **
**                                                                            **
*******************************************************************************/
uint8 Hssl_MultiWrite(const Hssl_DataTemplateType *WriteArray,uint16 DataSize,
                   uint16 NumCmd,Hssl_ChannelType Channel,uint8 InjectedError)
{
  uint32 CRCRegVal ;
  volatile uint32 Index  ;
  uint8 RetVal ;

  volatile Ifx_HSSL_I_ICON *CtrlRegPtr;
  volatile Ifx_HSSL_I_IWD *WriteDataRegPtr;

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorFlag;

    RetVal = 1U ;
    /* check if Init is called or not */
    ErrorFlag = Hssl_lInitCallVerify(HSSL_SID_WRITE_MULTIPLE);

    /*If Error Flag is not set*/
    if (HSSL_ERR_FOUND != ErrorFlag)
    {
      /* Verify Channel Number parameter */
      ErrorFlag = Hssl_lChannelVerify(Channel.Number,HSSL_SID_WRITE_MULTIPLE);

      /* verify the data size */
      if (HSSL_ERR_FOUND != ErrorFlag)
      {
        ErrorFlag = Hssl_ldataSizeVerify(DataSize , HSSL_SID_WRITE_MULTIPLE);

        /* Verify the mode to be run */
        if (HSSL_ERR_FOUND != ErrorFlag)
        {
          ErrorFlag = Hssl_lRunModeVerify(HSSL_SID_WRITE_MULTIPLE);
          /* verify the data pointer */
          if (HSSL_ERR_FOUND != ErrorFlag)
          {
            if(NULL_PTR == WriteArray)
            {
              Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                              HSSL_SID_WRITE_MULTIPLE,HSSL_E_INV_POINTER);
              ErrorFlag = HSSL_ERR_FOUND ;
            }
          }
        }
      }
    }
    /*If no Error present*/
    if (HSSL_ERR_FOUND != ErrorFlag)
  #endif
    {
      RetVal = 1U ;

      CtrlRegPtr = (volatile Ifx_HSSL_I_ICON *)\
      (void *)(&MODULE_HSSL.I[Channel.Number].ICON);
      WriteDataRegPtr  = (volatile Ifx_HSSL_I_IWD *)\
      (void *) (&MODULE_HSSL.I[Channel.Number].IWD);

      /*  Read ICONx.BSY bit to check if Channel is Busy or Available */
      if(((HSSL_SFR_RUNTIME_USER_MODE_READ32(CtrlRegPtr->U) \
                  & HSSL_ICONX_BSY_SETMASK) >> HSSL_SHIFT_BIT_20) == 0U)
      {
        /* If injected Error is needed set it in CRC register */
        if(InjectedError)
        {
          CRCRegVal =
                 (((uint32)InjectedError) | ((uint32)1 << HSSL_SHIFT_BIT_16));

          HSSL_SFR_RUNTIME_WRITE32(HSSL_CRC.U,(unsigned_int)\
                                         (CRCRegVal & HSSL_CRC_SETMASK));
        }

        /* Write data size in ICONx */
        HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(  \
                                    MODULE_HSSL.I[Channel.Number].ICON.U, \
                                            HSSL_ICONX_DATLEN_CLEARMASK, \
          (((uint32)DataSize << HSSL_SHIFT_BIT_16) & HSSL_ICONX_DATLEN_SETMASK))

        /* Write Time Out Value in ICONx */
        HSSL_SFR_RUNTIME_USER_MODE_MODIFY32( \
                                     MODULE_HSSL.I[Channel.Number].ICON.U, \
                      HSSL_ICONX_TOREL_CLEARMASK, (((uint32)Channel.Timeout \
                             << HSSL_SHIFT_BIT_24) & HSSL_ICONX_TOREL_SETMASK))

        /* Write ICONx.RWT with 0x2 Write Frame */
        HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(
                                    MODULE_HSSL.I[Channel.Number].ICON.U, \
               HSSL_ICONX_RWT_CLEARMASK, (((uint32)2 << HSSL_SHIFT_BIT_18) \
                                                & HSSL_ICONX_RWT_SETMASK))

        /* Set up the DMA ,data should be ordered pair of address and data */

        /* Set Source Address */
        /*IFX_MISRA_RULE_11_01_STATUS=WriteArray is typecast to unit32
          to pass it as a variable to the DMA Api */
        /*IFX_MISRA_RULE_11_03_STATUS=WriteArray is typecast to unit32
           to pass it as a variable to the DMA Api */
        HSSL_SFR_RUNTIME_MCAL_DMASETSOURCEADDR(HSSL_DMA_CHANNEL_USED, \
                                                (uint32)(WriteArray->Data));

        /* Set Destination Address */
        /*IFX_MISRA_RULE_11_01_STATUS=WriteDataRegPtr is typecast to unit32
          to pass it as a variable to the DMA Api */
         /*IFX_MISRA_RULE_11_03_STATUS=WriteDataRegPtr is typecast to unit32
            to pass it as a variable to the DMA Api */
        HSSL_SFR_RUNTIME_MCAL_DMASETDESTADDR( \
            (Dma_ChannelType)HSSL_DMA_CHANNEL_USED, (uint32)WriteDataRegPtr);

        /* Init Channel control register */
        HSSL_SFR_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(HSSL_DMA_CHANNEL_USED);

        /* DMA will have 2 moves per transaction :
           Data register and Address register.
        */
        HSSL_SFR_RUNTIME_MCAL_DMACFGNOOFMOVESPERTRANSFER( \
                                 HSSL_DMA_CHANNEL_USED, HSSL_CHANNEL_CFG);

        HSSL_SFR_RUNTIME_MCAL_DMASETDATAWIDTH(HSSL_DMA_CHANNEL_USED, \
                                                       HSSL_CHANNEL_CFG);
        /* Set the transfer count */
        HSSL_SFR_RUNTIME_MCAL_DMASETTXCOUNT(HSSL_DMA_CHANNEL_USED , \
                                                            (uint32)NumCmd);

        HSSL_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(HSSL_DMA_CHANNEL_USED) ;

        HSSL_SFR_RUNTIME_MCAL_DMAENTRANSREQLOSTINTR(HSSL_DMA_CHANNEL_USED);

        HSSL_SFR_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(HSSL_DMA_CHANNEL_USED);

        HSSL_SFR_RUNTIME_MCAL_DMACFGINTCONTROL(HSSL_DMA_CHANNEL_USED, \
                                                          HSSL_CHANNEL_CFG);

        /* SMF = 0 and INCS = 1 for incrementing source address by 4 */
        /* DMF = 1 and INCD = 1 for incrementing source address by 8 */
        /* CBLS --> F and 31-15 is not updated , source destination
            update by 4 no source wrap around*/
        /* CBLD -> HSSL_SHIFT_BIT_4 bit 31-4 are not updated Destination wrap
           around by 16 */

        /* Set Address Ctr Reg RX*/
        HSSL_SFR_RUNTIME_MCAL_DMASETADICR(HSSL_DMA_CHANNEL_USED, \
                                                        HSSL_ADICR_REG_VAL);

        /* Channel Interrupt trigger activated */
        HSSL_SFR_RUNTIME_MCAL_DMAENABLECHINTRTRIGGER(HSSL_DMA_CHANNEL_USED);

        HSSL_SFR_RUNTIME_MCAL_DMASTARTTRANSACTION(HSSL_DMA_CHANNEL_USED);

        /* Provide some delay for transcation to complete */
        for(Index = 0U ; Index < HSSL_WAIT_COUNT ; Index ++ )
        {
        }

        HSSL_SFR_RUNTIME_MCAL_DMAENABLEHWTRANSFER(HSSL_DMA_CHANNEL_USED);
        RetVal = 0U;
      }
    } /* if (HSSL_ERR_FOUND != ErrorFlag) */
  return(RetVal );
}

/*******************************************************************************
** Syntax : uint8 Hssl_MultiRead( const Hssl_DataTemplateType *ReadArray ,    **
**                            uint16 DataSize, uint16 NumCmd ,                **
**                      Hssl_ChannelType Channel,  uint8 InjectedError )      **
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
** Description : Performs multiple read transfers.                            **
**                                                                            **
*******************************************************************************/
uint8 Hssl_MultiRead (const Hssl_DataTemplateType *ReadArray,uint16 DataSize,
                  uint16 NumCmd ,Hssl_ChannelType Channel,uint8 InjectedError)
{
  uint8 RetVal,Index ;

  /* Parameter check for the API if DET is STD_ON*/
  #if ( HSSL_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorFlag;

    RetVal = 1U ;
    /* check if Init is called or not */
    ErrorFlag = Hssl_lInitCallVerify(HSSL_SID_READ_MULTIPLE);

    /*If Error Flag is not set*/
    if (HSSL_ERR_FOUND != ErrorFlag)
    {
      /* Verify Channel Number parameter */
      ErrorFlag = Hssl_lChannelVerify(Channel.Number , HSSL_SID_READ_MULTIPLE);

      /* verify the data size */
      if (HSSL_ERR_FOUND != ErrorFlag)
      {
        ErrorFlag = Hssl_ldataSizeVerify(DataSize , HSSL_SID_READ_MULTIPLE);

        /* Verify the mode to be run */
        if (HSSL_ERR_FOUND != ErrorFlag)
        {
          ErrorFlag = Hssl_lRunModeVerify(HSSL_SID_READ_MULTIPLE);
          /* verify the data pointer */
          if (HSSL_ERR_FOUND != ErrorFlag)
          {
            if(NULL_PTR == ReadArray)
            {
              Det_ReportError(HSSL_MODULE_ID,HSSL_MODULE_INSTANCE,
                              HSSL_SID_READ_MULTIPLE,HSSL_E_INV_POINTER);
              ErrorFlag = HSSL_ERR_FOUND ;
            }
          }
        }
      }
    }
    /*If no Error present*/
    if (HSSL_ERR_FOUND != ErrorFlag)
  #endif
    {
      RetVal = 1U ;
      /* call read and read reply API until until all records exhausted. */
      for(Index = 0U ; Index <  NumCmd; Index ++)
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithemtic is done on ReadArray
         to read the next corresponding data*/
        RetVal = Hssl_Read((ReadArray + (Index )),
                         DataSize, Channel, InjectedError);

        if(RetVal == 0U)
        {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithemtic is done on ReadArray
         to read the next corresponding data*/
          RetVal = Hssl_ReadRply((ReadArray + (Index )),
                 Channel) ;

        }
      }
    } /* if (HSSL_ERR_FOUND != ErrorFlag) */
  return(RetVal );
}
/*******************************************************************************
** Syntax : uint8 Hssl_lSetTargetID (void)                                    **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
** Description : Performs a direct write transfer.                            **
**                                                                            **
*******************************************************************************/
static uint8 Hssl_lSetTargetID (void)
{
  Hssl_ChannelType Channel ;
  uint8 Error ;

  Channel.Number = 0U;
  Channel.Timeout = HSSL_TIMEOUT;

  Hssl_DataBuffer = HSSL_TIDADD_ADDR ;
  WriteData1.Data = &Hssl_DataBuffer;

  Hssl_DataAddr =  HSSL_DATA_ADDR1;
  WriteData1.Address = &Hssl_DataAddr;

  Error = Hssl_lSingleFrameWrite(&WriteData1,HSSL_DATA_SIZE_32BIT,Channel,0U);

  if(0U == Error)
  {
    Error = Hssl_lWriteAck(Channel) ;
  }
  return(Error) ;
}

/*******************************************************************************
** Syntax : uint8 Hssl_lSetTargetAddress (const uint32 *StartAddress)         **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : StartAddress                                             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, Error code otherwise.        **
**                                                                            **
** Description : Local function to do direct write transfer.                  **
**                                                                            **
*******************************************************************************/
static uint8 Hssl_lSetTargetAddress(const uint32 *StartAddress)
{
  Hssl_ChannelType Channel ;
  uint8 Error ;

  Channel.Number = 0U;
  Channel.Timeout = HSSL_TIMEOUT;

  Hssl_DataBuffer = *StartAddress;
  WriteData2.Data = &Hssl_DataBuffer ;

  Hssl_DataAddr =  HSSL_DATA_ADDR;
  WriteData2.Address = &Hssl_DataAddr;

  Error = Hssl_lSingleFrameWrite(&WriteData2,HSSL_DATA_SIZE_32BIT,Channel,0U);

  if(0U == Error)
  {
    Error = Hssl_lWriteAck(Channel) ;

    if(0U == Error)
    {
      Hssl_DataAddr = (HSSL_DATA_ADDR + HSSL_SHIFT_BIT_4);
      WriteData2.Address = &Hssl_DataAddr;

      Error =
      Hssl_lSingleFrameWrite(&WriteData2, HSSL_DATA_SIZE_32BIT, Channel,0U);

      if(0U == Error)
      {
        Error = Hssl_lWriteAck(Channel) ;
      }
    }
  }
  return(Error) ;
}

/*******************************************************************************
** Syntax : uint8 Hssl_lSingleFrameWrite(                                     **
**                  const Hssl_DataTemplateType *WriteData,uint16 DataSize,   **
**                  Hssl_ChannelType Channel,uint8 InjectedError)             **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  WriteData : Pointer to Hssl_DataTemplateType structure  **
**                    which includes write Address and Data to be written.    **
**                    DataSize:: Size of data to be written.                  **
**                    Channel:: HSSL Channel to use.                          **
**                    InjectedError: injected error (if required)             **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns '0' if successful, error code otherwise.        **
**                                                                            **
** Description : Local function to do a direct write transfer.                **
**                                                                            **
*******************************************************************************/
uint8 Hssl_lSingleFrameWrite (const Hssl_DataTemplateType *WriteData,
                 uint16 DataSize,Hssl_ChannelType Channel,uint8 InjectedError)
{
  uint32 CRCRegVal ;
  uint8 RetVal ;

  volatile Ifx_HSSL_I_ICON *CtrlRegPtr;

  CtrlRegPtr = (volatile Ifx_HSSL_I_ICON *)\
  (void *)(&MODULE_HSSL.I[Channel.Number].ICON);

  /*  Read ICONx.BSY bit to check if Channel is Busy or Available */
  if(((HSSL_SFR_RUNTIME_USER_MODE_READ32(CtrlRegPtr->U) \
              & HSSL_ICONX_BSY_SETMASK) >> HSSL_SHIFT_BIT_20) == 0U)
  {
    /* If injected error is needed set it in CRC register */
    if(InjectedError)
    {
      CRCRegVal = (((uint32)InjectedError) | ((uint32)1 << HSSL_SHIFT_BIT_16));

      HSSL_SFR_RUNTIME_WRITE32(HSSL_CRC.U,(unsigned_int)\
                                              (CRCRegVal & HSSL_CRC_SETMASK));
    }

    /* Write data size in ICONx */
    HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_HSSL.I[Channel.Number].ICON.U, \
                                        HSSL_ICONX_DATLEN_CLEARMASK, \
         (((uint32)DataSize << HSSL_SHIFT_BIT_16) & HSSL_ICONX_DATLEN_SETMASK))

    /* Write Time Out Value in ICONx */
    HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_HSSL.I[Channel.Number].ICON.U, \
             HSSL_ICONX_TOREL_CLEARMASK, (uint32)(((uint32)HSSL_TIMEOUT << \
                             HSSL_SHIFT_BIT_24) & HSSL_ICONX_TOREL_SETMASK))

    /* Write ICONx.RWT with 0x10 Write Frame */
    HSSL_SFR_RUNTIME_USER_MODE_MODIFY32(MODULE_HSSL.I[Channel.Number].ICON.U, \
               HSSL_ICONX_RWT_CLEARMASK, (((uint32)2 << HSSL_SHIFT_BIT_18) \
                                                & HSSL_ICONX_RWT_SETMASK))

    /* Write IWDx register with the data */
    HSSL_SFR_RUNTIME_USER_MODE_WRITE32(MODULE_HSSL.I[Channel.Number].IWD.U, \
                                                            *WriteData->Data);

    /* Write IRWAx register with Address */
    HSSL_SFR_RUNTIME_USER_MODE_WRITE32(MODULE_HSSL.I[Channel.Number].IRWA.U, \
                                                         *WriteData->Address);

    RetVal = 0U;
  }
  else
  {
    RetVal =1U;
  }  /* Channel is Busy */

  return(RetVal) ;
}
/*******************************************************************************
** Syntax : uint8 Hssl_lWriteAck(Hssl_ChannelType Channel)                    **
**                                                                            **
** Service ID:  NA                                                            **
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
uint8 Hssl_lWriteAck(Hssl_ChannelType Channel)
{
  volatile uint32 Qflags;
  uint32 ExpectMask ;
  uint8 RetVal ;
  RetVal = 0U;

  /*Read the Request Flag register*/
  Qflags = HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_QFLAGS.U);

  /* Check Ix and Ex signals to check if any request is pending */
  while(Qflags & (((uint32)HSSL_WRITE_PENDING
        << (HSSL_SHIFT_BIT_16 +(Channel.Number * (uint32)HSSL_CHANNEL_CFG)))
        |((uint32)1U << Channel.Number)))
  {
    Qflags = HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_QFLAGS.U);
  }

  ExpectMask = ((uint32)1U << Channel.Number);        /* Not ACK Error */
  /* Transcation Tag Error */
  ExpectMask = ExpectMask |
                        ((uint32)1U << (Channel.Number + HSSL_SHIFT_BIT_4));
  /*TIMEOUT Error*/
  ExpectMask = ExpectMask |
                        ((uint32)1U << (Channel.Number + HSSL_SHIFT_BIT_8));
  ExpectMask = ExpectMask |
                        ((uint32)1U << (Channel.Number + HSSL_SHIFT_BIT_12));
   /* SRIE,PIE1,PIE2,CRCE */
  ExpectMask = ExpectMask | ((uint32)HSSL_FLAG_CFG << HSSL_SHIFT_BIT_22);

  if(HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_MFLAGS.U) & ExpectMask)
  {
    RetVal = 1U ;
  }
  return RetVal;
}

/*******************************************************************************
** Syntax : uint32 Hssl_GetGlobalError(void)                                  **
**                                                                            **
** Service ID:  0x0E                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Returns 32 bit Global Error Flags Value                 **
**                                                                            **
** Description : Reads the global error flags for the HSSL                    **
**                                                                            **
*******************************************************************************/
uint32 Hssl_GetGlobalError(void)
{
  uint32 GlobalErrorFlags ;

  /* Read the Global Error Flags*/
  GlobalErrorFlags = (uint32)((HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_MFLAGS.U)\
                                                   & HSSL_MFLAGS_SETMASK));

  return(GlobalErrorFlags);
}

/*******************************************************************************
** Syntax          : static void Hssl_lResetKernels(void)                     **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : NA                                                       **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : local function to reset all available kernels            **
*******************************************************************************/
static void Hssl_lResetKernels(uint8 ApiAccessId)
{
  volatile uint32 Readback;
  uint32 WaitCount;

  if(ApiAccessId == HSSL_INIT_API_ACCESS)
  {
    /*Clear the ENDINIT bit in the WDT_CONSR register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    HSSL_SFR_INIT_RESETENDINIT();

    /* Set request to reset the HSSL Kernel */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    HSSL_SFR_INIT_MODIFY32(HSSL_KRST0.U,HSSL_KRST0_RST_CLEARMASK, \
                                                      HSSL_KRST0_RST_SETMASK)

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    Readback = HSSL_SFR_INIT_USER_MODE_READ32(HSSL_KRST0.U);

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    HSSL_SFR_INIT_WRITE32(HSSL_KRST1.U, 1U);

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    Readback = HSSL_SFR_INIT_USER_MODE_READ32(HSSL_KRST1.U);

    /* Set the ENDINIT bit in the WDT_CONSR register again
    to enable the write-protection and to prevent a time-out */
    HSSL_SFR_INIT_SETENDINIT();

    WaitCount = (uint32)HSSL_KERNEL_RESET_WAIT_COUNT;
    do
    {
      WaitCount--;
    }
    while(((HSSL_SFR_INIT_USER_MODE_READ32(HSSL_KRST0.U) & \
                       HSSL_KRST0_RSTSTAT_SETMASK) != 1U) && (WaitCount > 0U));

    /*Clear the ENDINIT bit in the WDT_CONSR register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    HSSL_SFR_INIT_RESETENDINIT();
    /* Clear the HSSL Kernel Reset Flag */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    HSSL_SFR_INIT_WRITE32(HSSL_KRSTCLR.U, 1U);

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    Readback = HSSL_SFR_INIT_USER_MODE_READ32(HSSL_KRSTCLR.U);

    /* Set the ENDINIT bit in the WDT_CONSR register again
    to enable the write-protection and to prevent a time-out */
    HSSL_SFR_INIT_SETENDINIT();
  }
  else
  {
    /*Clear the ENDINIT bit in the WDT_CONSR register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    HSSL_SFR_RUNTIME_RESETENDINIT();

    /* Set request to reset the HSSL Kernel */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    HSSL_SFR_RUNTIME_MODIFY32(HSSL_KRST0.U,HSSL_KRST0_RST_CLEARMASK, \
                                                      HSSL_KRST0_RST_SETMASK)

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    Readback = HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_KRST0.U);

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    HSSL_SFR_RUNTIME_WRITE32(HSSL_KRST1.U, 1U);

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    Readback = HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_KRST1.U);

    /* Set the ENDINIT bit in the WDT_CONSR register again
    to enable the write-protection and to prevent a time-out */
    HSSL_SFR_RUNTIME_SETENDINIT();

    WaitCount = (uint32)HSSL_KERNEL_RESET_WAIT_COUNT;
    do
    {
      WaitCount--;
    }
    while(((HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_KRST0.U) & \
                       HSSL_KRST0_RSTSTAT_SETMASK) != 1U) && (WaitCount > 0U));

    /*Clear the ENDINIT bit in the WDT_CONSR register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    HSSL_SFR_RUNTIME_RESETENDINIT();
    /* Clear the HSSL Kernel Reset Flag */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    HSSL_SFR_RUNTIME_WRITE32(HSSL_KRSTCLR.U, 1U);

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple HSSL kernels*/
    Readback = HSSL_SFR_RUNTIME_USER_MODE_READ32(HSSL_KRSTCLR.U);

    /* Set the ENDINIT bit in the WDT_CONSR register again
    to enable the write-protection and to prevent a time-out */
    HSSL_SFR_RUNTIME_SETENDINIT();
  }
  UNUSED_PARAMETER(Readback)
}

#define HSSL_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
