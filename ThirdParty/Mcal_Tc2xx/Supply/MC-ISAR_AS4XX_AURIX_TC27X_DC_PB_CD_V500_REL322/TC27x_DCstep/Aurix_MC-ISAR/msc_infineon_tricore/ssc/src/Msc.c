/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Msc.c $                                                    **
**                                                                           **
**  $CC VERSION : \main\45 $                                                 **
**                                                                           **
**  $DATE       : 2016-07-13 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of MSC driver.                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                                                                           **
**  TRACEABILITY :
    [cover parentID=DS_NAS_MSC_PR69_PR469_PR122_PR123,DS_NAS_MSC_PR647,
    SAS_NAS_MSC_PR1071,DS_NAS_MSC_PR746,SAS_NAS_ALL_PR749,SAS_NAS_ALL_PR102,
    SAS_NAS_ALL_PR630_PR631,SAS_NAS_ALL_PR471,SAS_NAS_ALL_PR470,
    SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR1652]
    [/cover]                                                                  **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

  /* Inclusion of controller sfr file */
#include "IfxSrc_reg.h"

  /* Inclusion of Msc sfr file */
#include "IfxMsc_reg.h"

  /* Inclusion of Msc.h header file */
#include "Msc.h"

  /* Inclusion of Msc sfr file */
#include "IfxMsc_reg.h"
#include "IfxMsc_bf.h"
#include "IfxSrc_bf.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*************** SW Version Checks ***************/
#ifndef MSC_SW_MAJOR_VERSION
  #error "MSC_SW_MAJOR_VERSION is not defined."
#endif

#ifndef MSC_SW_MINOR_VERSION
  #error "MSC_SW_MINOR_VERSION is not defined."
#endif

#ifndef MSC_SW_PATCH_VERSION
  #error "MSC_SW_PATCH_VERSION is not defined."
#endif

/* Check for Correct inclusion of headers */
#if ( MSC_SW_MAJOR_VERSION != 1U )
  #error "MSC_SW_MAJOR_VERSION does not match."
#endif
#if ( MSC_SW_MINOR_VERSION != 3U )
  #error "MSC_SW_MINOR_VERSION does not match."
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define MSC_DRIVER_UNINIT                     ((uint8)0U)
#define MSC_DRIVER_INIT                       ((uint8)1U)
#define MSC_UPSTREAM_BAUD_MASK                ((uint32)0x0000000EU)
#define MSC_CLOCK_DISABLE_VAL                 ((uint32)0x00000001U)
#define MSC_BIT0                              ((uint32)0x00000001U)
#define MSC_BIT1                              ((uint32)0x00000002U)
#define MSC_BIT2                              ((uint32)0x00000004U)
#define MSC_BIT3                              ((uint32)0x00000008U)
#define MSC_EMRDATA_HIGH_MASK                 ((uint32)0xFFFF0000U)
#define MSC_EMRDATA_LOW_MASK                  ((uint32)0x0000FFFFU)
#define MSC_KERNEL_RESET_WAIT_COUNTS          ((uint32)0x00000100U)

#define MSC_ZERO_U                            (0U)
#define MSC_ONE_U                             (1U)

/* Macros used for protected modes */
/* Interrupt Set Clear Register */
#define MSC_ISC_RESRV_CLR_MASK                ((uint32)0x007F007FU)

/* Downstream Data Register */
#define MSC_DD_DDH_CLR_MASK                   ((uint32)0x0000FFFFU)
#define MSC_DD_DDL_CLR_MASK                   ((uint32)0xFFFF0000U)

/* Downstream Data Extension Register */
#define MSC_DDE_DDHE_CLR_MASK                 ((uint32)0x0000FFFFU)
#define MSC_DDE_DDLE_CLR_MASK                 ((uint32)0xFFFF0000U)

/* Downstream Status Register */
#define MSC_DSS_RESRV_CLR_MASK                ((uint32)0x03FF000FU)
#define MSC_DSS_NPTF_SET_MASK                 ((uint32)0x00000F00U)

/* Service Request Control Register */
#define MSC_SRC_RESRV_CLR_MASK                ((uint32)0x7F3F1CFFU)
#define MSC_SRC_SRE_RESRV_CLR_MASK            ((uint32)0x7F3F18FFU)
#define MSC_SRC_SRE_CLR_MASK                  ((uint32)0x00000000U)

/* Output Control Register */
#define MSC_OCR_RESRV_CSC_CLR_MASK            ((uint32)0x00071F0FU)
#define MSC_OCR_CSC_SET_MASK                  ((uint32)0x00006000U)
#define MSC_OCR_CSL_CLR_MASK                  ((uint32)0x0007790FU)
#define MSC_OCR_CSL_SET_MASK                  ((uint32)0x00000600U)
#define MSC_OCR_CSH_CLR_MASK                  ((uint32)0x0007670FU)
#define MSC_OCR_CSH_SET_MASK                  ((uint32)0x00001800U)
#define MSC_OCR_SDISEL_CLR_MASK               ((uint32)0x00007F0FU)
#define MSC_OCR_SDISEL_SET_MASK               ((uint32)0x00070000U)

/* Upstream Status Register */
#define MSC_USR_RESRV_URR_CLR_MASK            ((uint32)0x001F0031U)
#define MSC_USR_URR_CLR_MASK                  ((uint32)0x00000000U)

/* Upstream Data Register */
#define MSC_UD_RESRV_C_CLR_MASK                 ((uint32)0x007F00FFU)

/* Upstream Control Enhanced Register */
#define MSC_USCE_RESRV_CLR_MASK               ((uint32)0x0000EFFFU)

/* Kernel Reset Control Register */
#define MSC_KRST0_RESRV_CLR_MASK              ((uint32)0x00000003U)
#define MSC_KRST1_RESRV_CLR_MASK              ((uint32)0x00000001U)

/* Kernel Reset Status Clear Register */
#define MSC_KRSTCLR_RESRV_CLR_MASK            ((uint32)0x00000001U)

/* Start Address of MSC Register - MSC0_CLC*/
#define MSC_REGMAP                            ((Ifx_MSC *)(void *) &(MSC0_CLC))
/* Start Address of MSC Register - SRC_MSC0_SR0*/
#define MSC_SRC_REGMAP            ((Ifx_SRC_MSC *)(void *) &(SRC_MSC_MSC0_SR0))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*Memory Map of the MSC Code*/
#define MSC_START_SEC_CODE
#include "MemMap.h"

#if (MSC_DEV_ERROR_DETECT == STD_ON )

/* Fucntions to check for DET's*/
static Std_ReturnType Msc_lDetCheckUnInit(uint8 ServiceId);
static Std_ReturnType Msc_lDetCheckModule(uint8 ServiceId,uint8 Module);
static Std_ReturnType Msc_lDetCheckTxMode(uint8 ServiceId,\
                                         Msc_TxStateType TxState);
static Std_ReturnType Msc_lDetCheckTxType(uint8 ServiceId,\
                                         Msc_TxType FrmTyp);
static Std_ReturnType Msc_lDetCheckRxMode(uint8 ServiceId,\
                                         Msc_RxStateType RxState);
static Std_ReturnType Msc_lDetCheckTxDevice(uint8 ServiceId,\
                                           Msc_TxDevSelectType Device);
static Std_ReturnType Msc_lDetCheckTxState(uint8 ServiceId, uint8 ModNum);
static Std_ReturnType Msc_lDetCheckRxRegister(uint8 ServiceId,\
                                      Msc_UpstreamRegType UpReg);
static Std_ReturnType Msc_lDetCheckRxDevice(uint8 ServiceId,\
                                     Msc_RxDevSelectType Device);
#endif /* End of MSC_DEV_ERROR_DETECT */

/* Function to enable IRQ service requests */
static void Msc_lEnableHwIntrService(uint8 ModNum, uint8 SrvConfig);


#if (MSC_RESET_SFR_INIT == STD_ON)
/* Function to reset Kernels */
static void Msc_lResetKernelsInit(uint8 ModNum);
#endif

#if (MSC_DEINIT_API == STD_ON)
/* Function to reset Kernels */
static void Msc_lResetKernelsDeInit(uint8 ModNum);
#endif

#define MSC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if (MSC_PB_FIXEDADDR == STD_ON)
#define MSC_START_SEC_CONST_32BIT
/*
 * To be used for global constants (32 bits)
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* To store the Msc driver configuration pointer */
static const Msc_ConfigType * const Msc_kConfigPtr = &Msc_ConfigRoot[0];

#define MSC_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* End of MSC_PB_FIXEDADDR */

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*[cover parentID = DS_NAS_MSC_PR115] Global Variables [/cover]*/
#if (MSC_PB_FIXEDADDR == STD_OFF)
#define MSC_START_SEC_VAR_32BIT
/*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

static const Msc_ConfigType *Msc_kConfigPtr;

#define MSC_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* End of MSC_PB_FIXEDADDR */

#define MSC_START_SEC_VAR_8BIT
/*
 * To be used for 8bit global variables
 * Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#if ( MSC_DEBUG_SUPPORT == STD_ON )
  /*IFX_MISRA_RULE_08_10_STATUS="Msc_DriverState" varaible is made extern in
  Msc_Dbg.h, which will be included by applcation for debugging*/
  uint8 Msc_DriverState;
#else
  static uint8 Msc_DriverState;
#endif/* End of MSC_DEBUG_SUPPORT */

#define MSC_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#ifdef IFX_MSC_DEBUG01
  extern volatile uint32 TestMSC_DebugMask;
  extern volatile uint32 TestMSC_DebugMask01;
#endif/* IFX_MSC_DEBUG01 */

#ifdef IFX_MSC_DEBUG02
  extern volatile uint32 TestMSC_DebugMask02;
#endif/*IFX_MSC_DEBUG02 */

#ifdef IFX_MSC_DEBUG03
  extern volatile uint32 TestMSC_DebugMask03;
#endif/* IFX_MSC_DEBUG03 */

#ifdef IFX_MSC_DEBUG04
  extern volatile uint32 TestMSC_DebugMask04;
#endif/* IFX_MSC_DEBUG04 */

#ifdef IFX_MSC_DEBUG05
  extern volatile uint32 TestMSC_DebugMask05;
#endif/* IFX_MSC_DEBUG05 */

#ifdef IFX_MSC_DEBUG06
  extern volatile uint32 TestMSC_DebugMask06;
#endif/* IFX_MSC_DEBUG06 */

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the MSC Code*/
#define MSC_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_MSC_PR1072,DS_NAS_HE2_MSC_PR3018,
                      DS_NAS_MSC_PR915,DS_NAS_MSC_PR63_5]                     **
**                                                                            **
** Syntax          : void Msc_Init(const Msc_ConfigType* ConfigPtr)           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x00                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters (in) : ConfigPtr - Pointer to MSC Driver configuration set      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Driver Module Initialization                                 **
**               1.This function will initialize all relevant registers of    **
**                 with the values of structure given by ConfigPtr            **
**                                                                            **
*******************************************************************************/
void Msc_Init(const Msc_ConfigType* ConfigPtr)
{


  const Msc_ModuleConfigType *lModuleCfgPtr;
  uint8 ModNum;
  uint8 ClkDisableChk;
  uint8 ClkFailureChk;
  /* Check if DET is ON*/
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  /*Check if PB Fixed Address is OFF*/
  #if (MSC_PB_FIXEDADDR == STD_OFF)
  /*Report DET if Config Pointer is NULL*/
  if(ConfigPtr == NULL_PTR)
  #else
  /*Report DET if Config Pointer does not match*/
  if(ConfigPtr != Msc_kConfigPtr)
  #endif/* End of MSC_PB_FIXEDADDR */
  {
    /*Report DET on ConfigPtr error*/
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                    MSC_SID_INIT,MSC_E_PARAM_CONFIG);
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    if(Msc_DriverState != MSC_DRIVER_INIT)
    {
      #if (MSC_PB_FIXEDADDR == STD_OFF)
      /*Store the Config Pointer to Global variable*/
      Msc_kConfigPtr = ConfigPtr;
      #endif /* End of MSC_PB_FIXEDADDR  */

      /*Start from MSC0 module*/
      ModNum = (uint8)MSC_ZERO_U;
      ClkFailureChk = (uint8)MSC_ZERO_U;

      /*Initialize all the MSC modules.*/
      while(ModNum < MSC_NUM_OF_MODULES)
      {
        /*Check if the module configuration exists*/
        if(ConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
        {
          lModuleCfgPtr = ConfigPtr->ModCfgPtr[ModNum];
          /*Clear the ENDINIT bit in the WDT_CONSR register in order
          to disable the write-protection for registers protected
          via the EndInit feature */
          MSC_SFR_INIT_RESETENDINIT();

          /*Configure the Sleep Mode enable/diable*/
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_INIT_WRITE32(MSC_REGMAP[ModNum].CLC.U,                     \
                              lModuleCfgPtr->SleepMode);

          /* Set the ENDINIT bit in the WDT_CONSR register again
          to enable the write-protection and to prevent a time-out */
          MSC_SFR_INIT_SETENDINIT();


          /* Check the status bit DISS for Checking Mod Clk Disable Status*/
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          ClkDisableChk = (uint8)((MSC_SFR_INIT_USER_MODE_READ32               \
                          (MSC_REGMAP[ModNum].CLC.U) >> IFX_MSC_CLC_DISS_OFF)  \
                           & IFX_MSC_CLC_DISS_MSK);

          #ifdef IFX_MSC_DEBUG06
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          ClkDisableChk  |= (TestMSC_DebugMask06);
          #endif

          if(MSC_ZERO_U == ClkDisableChk)
          {
            #if (MSC_RESET_SFR_INIT == STD_ON)
            Msc_lResetKernelsInit(ModNum);
            #endif /* End of MSC_RESET_SFR_INIT  */

            /*Clear the ENDINIT bit in the WDT_CONSR register in order
            to disable the write-protection for registers protected
            via the EndInit feature */
            MSC_SFR_INIT_RESETENDINIT();

            /*Configure the clock settings for fMSC*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_WRITE32(MSC_REGMAP[ModNum].FDR.U,                    \
                                 lModuleCfgPtr->ClkConfig);

            /* Set the ENDINIT bit in the WDT_CONSR register again
            to enable the write-protection and to prevent a time-out */
            MSC_SFR_INIT_SETENDINIT();

            /* Switch OFF the transmitter before configuring registers*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].ISC.U,         \
                  MSC_ISC_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_ISC_SDDIS_OFF))
            /*Configure the downstream channel with TxConfig*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DSC.U,       \
                                           lModuleCfgPtr->TxConfig);

            /*Configure the downstream channel with TxConfigExtn*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DSTE.U,        \
                                           lModuleCfgPtr->TxConfigExtn);

            /*Configure the Source Select for lower 16 bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DSDSL.U,        \
                                           lModuleCfgPtr->DataBitSrcLowConfig);

            /*Configure the Extension Source Select for lower 16 bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DSDSLE.U,      \
                                  lModuleCfgPtr->DataBitExtensionSrcLowConfig);

            /*Configure the Source Select for Upper 16 bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DSDSH.U,     \
                                           lModuleCfgPtr->DataBitSrcHighConfig);

            /*Configure the Extension Source Select for Upper 16 bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DSDSHE.U,     \
                                  lModuleCfgPtr->DataBitExtensionSrcHighConfig);

            /*Configure the Emergency Stop Control for all bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].ESR.U,     \
                                       lModuleCfgPtr->DataEmergencyStopControl);

            /*Configure the Emergency Stop Control for all bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].ESRE.U,      \
                                   lModuleCfgPtr->DataExtnEmergencyStopControl);
            /*Configure the Emergency Value for upper 16 bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].DD.U,          \
            MSC_DD_DDH_CLR_MASK, (uint32)((lModuleCfgPtr->                    \
            DataEmergencyValueHigh & IFX_MSC_DD_DDH_MSK) << IFX_MSC_DD_DDH_OFF))
            /*Configure the Emergency Value for lower 16 bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].DD.U,          \
            MSC_DD_DDL_CLR_MASK, (uint32)(lModuleCfgPtr->DataEmergencyValueLow\
                                 & IFX_MSC_DD_DDL_MSK))

            /*Configure the Emergency Value for upper 16 bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].DDE.U,         \
                      MSC_DDE_DDHE_CLR_MASK, (uint32)((lModuleCfgPtr->        \
                      DataExtnEmergencyValueHigh & IFX_MSC_DDE_DDHE_MSK)      \
                       << IFX_MSC_DDE_DDHE_OFF))
            /*Configure the Emergency Value for lower 16 bits*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].DDE.U,         \
                      MSC_DDE_DDLE_CLR_MASK,(uint32)(lModuleCfgPtr->          \
                      DataExtnEmergencyValueLow & IFX_MSC_DDE_DDLE_MSK))

            /*Configure the Data Injection configuration from ext pin*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DSCE.U,         \
                                           lModuleCfgPtr->DataInjConfig);

            /*Configure the Upstream channel with RxConfig*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].USR.U,          \
                                           lModuleCfgPtr->RxConfig);

            /*Configure the polarities for all signals*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_WRITE32(MSC_REGMAP[ModNum].OCR.U,          \
                                           lModuleCfgPtr->SignalConfig);

            /*Configure the Time Frame count*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple MSC kernels*/
            MSC_SFR_INIT_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].DSS.U,         \
            MSC_DSS_RESRV_CLR_MASK,((uint32)lModuleCfgPtr->TimeFrmCnt     \
                               << IFX_MSC_DSS_NPTF_OFF) & MSC_DSS_NPTF_SET_MASK)

            Msc_lEnableHwIntrService(ModNum,lModuleCfgPtr->InterruptConfig.   \
                 SRConfig);
          }
          else
          {
            ClkFailureChk++;
          }
        }
        /*Increment Module Pointer to the next module*/
        ModNum++;
      }
      if(MSC_ZERO_U == ClkFailureChk)
      {
        /* Change the Msc_DriverState to initalzied*/
        Msc_DriverState = MSC_DRIVER_INIT;
      }
      else
      {
        /* Change the Msc_DriverState to uninitalzied*/
        Msc_DriverState = MSC_DRIVER_UNINIT;
      }
    }
  }
}
#if (MSC_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_MSC_PR1073,DS_NAS_MSC_PR915]      **
**                                                                            **
** Syntax          : void Msc_DeInit(void)                                    **
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
** Return value    : None                                                     **
**                                                                            **
** Description : Driver DeInitialization                                      **
**               1.This function will deinitialize the MSC peripheral         **
**                                                                            **
*******************************************************************************/
void Msc_DeInit(void)
{
  uint8 ModNum;
  uint8 MscServReq;

  /*Start from MSC0 module*/
  ModNum = (uint8)MSC_ZERO_U;

  if(Msc_DriverState == MSC_DRIVER_INIT)
  {
    while(ModNum < MSC_NUM_OF_MODULES)
    {
      if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
      {
        /* Disable Service Requests */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        MscServReq = (uint8)((MSC_SFR_DEINIT_USER_MODE_READ32                \
                     (MSC_SRC_REGMAP[ModNum].SR0.U)                          \
                      >> IFX_SRC_SRCR_SRE_OFF) & IFX_SRC_SRCR_SRE_MSK);
        if(MscServReq == MSC_ONE_U)
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR0.U,              \
                  MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_CLRR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR0.U,              \
                MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_IOVCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR0.U,              \
                MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_SWSCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR0.U,              \
                  MSC_SRC_SRE_RESRV_CLR_MASK, MSC_SRC_SRE_CLR_MASK)
        }

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        MscServReq = (uint8)((MSC_SFR_DEINIT_USER_MODE_READ32                \
                     (MSC_SRC_REGMAP[ModNum].SR1.U)                          \
                      >> IFX_SRC_SRCR_SRE_OFF) & IFX_SRC_SRCR_SRE_MSK);
        if(MscServReq == MSC_ONE_U)
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR1.U,              \
                  MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_CLRR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR1.U,              \
                MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_IOVCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR1.U,              \
                MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_SWSCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR1.U,              \
                              MSC_SRC_SRE_RESRV_CLR_MASK, MSC_SRC_SRE_CLR_MASK)
        }

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        MscServReq = (uint8)((MSC_SFR_DEINIT_USER_MODE_READ32                \
                     (MSC_SRC_REGMAP[ModNum].SR2.U)                      \
                       >> IFX_SRC_SRCR_SRE_OFF) & IFX_SRC_SRCR_SRE_MSK);
        if(MscServReq == MSC_ONE_U)
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR2.U,              \
                  MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_CLRR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR2.U,              \
                MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_IOVCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR2.U,              \
                MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_SWSCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR2.U,              \
                     MSC_SRC_SRE_RESRV_CLR_MASK, MSC_SRC_SRE_CLR_MASK)
        }

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        MscServReq = (uint8)((MSC_SFR_DEINIT_USER_MODE_READ32                \
                     (MSC_SRC_REGMAP[ModNum].SR3.U)                      \
                       >> IFX_SRC_SRCR_SRE_OFF) & IFX_SRC_SRCR_SRE_MSK);
        if(MscServReq == MSC_ONE_U)
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR3.U,              \
                 MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_CLRR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR3.U,              \
               MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_IOVCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR3.U,              \
               MSC_SRC_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_SWSCLR_OFF))
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the SFRs of multiple MSC kernels*/
          MSC_SFR_DEINIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR3.U,              \
                              MSC_SRC_SRE_RESRV_CLR_MASK, MSC_SRC_SRE_CLR_MASK)
        }

        Msc_lResetKernelsDeInit(ModNum);


        MSC_SFR_DEINIT_RESETENDINIT();
        /* Disable the Module using CLC register */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        MSC_SFR_DEINIT_WRITE32(MSC_REGMAP[ModNum].CLC.U,MSC_CLOCK_DISABLE_VAL);
        /* Set the ENDINIT bit in the WDT_CONSR register again
        to enable the write-protection and to prevent a time-out */
        MSC_SFR_DEINIT_SETENDINIT();
      }
      /* Increment to the next MSC module*/
      ModNum++;
    }
  }
  #if (MSC_PB_FIXEDADDR == STD_OFF)
  /*Store the NULL to Global Pointer variable*/
  Msc_kConfigPtr = NULL_PTR;
  #endif /* End of MSC_PB_FIXEDADDR */

  /* Set Msc_DriverState to Un-Initialized */
  Msc_DriverState = MSC_DRIVER_UNINIT;
}
#endif /* End of MSC_DEINIT_API */

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_MSC_PR1074,DS_NAS_MSC_PR915,
                      DS_NAS_MSC_PR63_6]                                      **
**                                                                            **
** Syntax          : Std_ReturnType Msc_ChangeTxState  (uint8 ModNum,         **
**                   Msc_TxStateType Mode)                                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x02                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Mode - MSC_TX_ON - Transmitter is switched ON            **
**                          MSC_TX_OFF - Transmitter is switched OFF          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/E_NOT_OK                                            **
**                                                                            **
** Description     : This function:                                           **
**   - Activates/Deactivates the transmitter (downstream channel) of the      **
**     MSC module                                                             **
*******************************************************************************/
Std_ReturnType Msc_ChangeTxState (uint8 ModNum, Msc_TxStateType Mode)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_CHANGETXSTATUS);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_CHANGETXSTATUS,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for MSC Tx state is valid */
        ErrorFlag = Msc_lDetCheckTxMode(MSC_SID_CHANGETXSTATUS,Mode);
     }
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    if(Mode == MSC_TX_ON)
    {
      /*Enable the Tx on downstream channel*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].ISC.U,          \
                  MSC_ISC_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_ISC_CDDIS_OFF))
    }
    else
    {
      /*Disbale the Tx on downstream channel*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].ISC.U,         \
                  MSC_ISC_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_ISC_SDDIS_OFF))
    }

    RetVal = E_OK;
  }
  return (RetVal);
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_MSC_PR1075,DS_NAS_MSC_PR915,
                     DS_NAS_MSC_PR63_7]                                       **
**                                                                            **
** Syntax          : Msc_TxStatusType Msc_GetTxStatus (uint8 ModNum,          **
**                   Msc_TxType FrameType)                                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x03                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   FrameType - MSC_CMD_FRAME - Check for Command frame      **
**                               MSC_DATA_FRAME - Check for Data frame        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Msc_TxStatusType                                         **
**                                                                            **
** Description     : This function:                                           **
**   - Returns the readiness of the Tx to accept new command /data frame      **
**     transmission requests                                                  **
*******************************************************************************/
Msc_TxStatusType Msc_GetTxStatus (uint8 ModNum, Msc_TxType FrameType)
{
  Msc_TxStatusType RetVal;
  uint8 FramePendingFlag;
  uint8 FrameActiveFlag;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETTXSTATUS);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETTXSTATUS,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for Tx frame type validity */
        ErrorFlag = Msc_lDetCheckTxType(MSC_SID_GETTXSTATUS,FrameType);
     }
  }
  /* If any DET is reported Return value is made MSC_TX_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
     RetVal = MSC_TX_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {

     /* Check for frame type is Command or Data*/
     if(FrameType == MSC_CMD_FRAME)
     {
        #ifdef IFX_MSC_DEBUG01
         FrameActiveFlag = TestMSC_DebugMask;
        #else
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
         efficiently access the SFRs of multiple MSC kernels*/
         FramePendingFlag = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32        \
                            (MSC_REGMAP[ModNum].DSC.U)                       \
                             >> IFX_MSC_DSC_CP_OFF) & IFX_MSC_DSC_CP_MSK);
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
         efficiently access the SFRs of multiple MSC kernels*/
         FrameActiveFlag = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32         \
                           (MSC_REGMAP[ModNum].DSS.U)                        \
                            >> IFX_MSC_DSS_CFA_OFF) & IFX_MSC_DSS_CFA_MSK);
        #endif/*#ifdef IFX_MSC_DEBUG01 */
        /* Check if Command Frame Tx, Inactive and Not Pending*/
        if((FrameActiveFlag == MSC_ZERO_U) && (FramePendingFlag == MSC_ZERO_U))
        {
           RetVal = MSC_CMDFRMTX_READY;
        }
        else
        {
           RetVal = MSC_CMDFRMTX_NOTREADY;
        }
     }
     else
     {
        #ifdef IFX_MSC_DEBUG01
         FrameActiveFlag = TestMSC_DebugMask;
         FramePendingFlag = TestMSC_DebugMask01;
        #else
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
         efficiently access the SFRs of multiple MSC kernels*/
         FramePendingFlag = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32        \
                            (MSC_REGMAP[ModNum].DSC.U)                         \
                             >> IFX_MSC_DSC_DP_OFF) & IFX_MSC_DSC_DP_MSK);
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
         efficiently access the SFRs of multiple MSC kernels*/
         FrameActiveFlag = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32         \
                           (MSC_REGMAP[ModNum].DSS.U)                        \
                            >> IFX_MSC_DSS_DFA_OFF) & IFX_MSC_DSS_DFA_MSK);
        #endif/*#ifdef IFX_MSC_DEBUG01 */
        /* Check if Data Frame Tx, Inactive and Not Pending*/
        if((FrameActiveFlag == MSC_ZERO_U) && (FramePendingFlag == MSC_ZERO_U))
        {
           RetVal = MSC_DATAFRMTX_READY;
        }
        else
        {
           RetVal = MSC_DATAFRMTX_NOTREADY;
        }
     }
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_MSC_PR1076,DS_NAS_MSC_PR915,
                     DS_NAS_MSC_PR63_8]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Msc_TxCmdFrame (uint8 ModNum,             **
**                   Msc_TxDevSelectType Device, uint32 Msc_Cmd)              **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x04                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Device - MSC_TX_DEVICE_0/MSC_TX_DEVICE_1/                **
                              MSC_TX_DEVICE_2/MSC_TX_DEVICE_3                 **
**                   Msc_Cmd - Command to be transmitted                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/E_NOT_OK                                            **
**                                                                            **
** Description     : This function:                                           **
**   - Transmits a command frame                                              **
*******************************************************************************/
Std_ReturnType Msc_TxCmdFrame (uint8 ModNum, Msc_TxDevSelectType Device,
                               uint32 Msc_Cmd)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_TXCMDFRAME);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_TXCMDFRAME,ModNum);
     if(ErrorFlag == E_OK)
     {
         /* Check for, Tx Device is valid */
        ErrorFlag = Msc_lDetCheckTxDevice(MSC_SID_TXCMDFRAME,Device);
        if(ErrorFlag == E_OK)
        {
           /* Check for, Transmitter is enabled */
           ErrorFlag = Msc_lDetCheckTxState(MSC_SID_TXCMDFRAME,ModNum);
        }
     }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
     RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
     /* Select the device to the command is to be transmitted*/
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
     efficiently access the SFRs of multiple MSC kernels*/
     MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].OCR.U,           \
             MSC_OCR_RESRV_CSC_CLR_MASK,((uint32)Device << IFX_MSC_OCR_CSC_OFF)\
                                        & MSC_OCR_CSC_SET_MASK)
     /* Load the command value to the command register*/
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
     efficiently access the SFRs of multiple MSC kernels*/
     MSC_SFR_RUNTIME_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DC.U, Msc_Cmd);

     RetVal = E_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_MSC_PR1077,DS_NAS_MSC_PR915,
                      DS_NAS_MSC_PR63_9]                                      **
**                                                                            **
** Syntax          : Std_ReturnType Msc_TxDataFrame (uint8 ModNum,            **
**                   Msc_TxDevSelectType DeviceHigh,                          **
**                   Msc_TxDevSelectType DeviceLow,const uint32 *Msc_Data)    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x05                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   DeviceHigh / DeviceLow - MSC_TX_DEVICE_0/                **
                     MSC_TX_DEVICE_1/MSC_TX_DEVICE_2/MSC_TX_DEVICE_3          **
**                   Msc_Data - Pointer to the Data to be transmitted         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/E_NOT_OK                                            **
**                                                                            **
** Description      : This function:                                          **
**   - Transmits a data frame                                                 **
*******************************************************************************/
Std_ReturnType Msc_TxDataFrame (uint8 ModNum, Msc_TxDevSelectType DeviceHigh,
                         Msc_TxDevSelectType DeviceLow, const uint32 *Msc_Data)
{
  Std_ReturnType RetVal;
  uint32 lDataRegMask;
  uint32 DataVal;
  uint32 lExtnDataRegMask;
  uint32 ExtnDataVal;
  uint32 TxMode;
  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_TXDATAFRAME);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_TXDATAFRAME,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for, MSC Tx Device is valid */
        ErrorFlag = Msc_lDetCheckTxDevice(MSC_SID_TXDATAFRAME,DeviceLow);
        if(ErrorFlag == E_OK)
        {
           /* Check for, MSC Tx Device is valid */
           ErrorFlag = Msc_lDetCheckTxDevice(MSC_SID_TXDATAFRAME,DeviceHigh);
           if(ErrorFlag == E_OK)
           {
              /* Check for MSC transmitter is in ON state */
              ErrorFlag = Msc_lDetCheckTxState(MSC_SID_TXDATAFRAME,ModNum);
           }
        }
     }
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
     RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
    {
      /* Select the device for Data Frame Transmission */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].OCR.U,          \
      MSC_OCR_CSL_CLR_MASK,((uint32)DeviceLow << IFX_MSC_OCR_CSL_OFF)        \
                           & MSC_OCR_CSL_SET_MASK)
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].OCR.U,           \
      MSC_OCR_CSH_CLR_MASK,((uint32)DeviceHigh << IFX_MSC_OCR_CSH_OFF) &     \
                            MSC_OCR_CSH_SET_MASK)
      /* Check the bits for which Data register is selected as source*/
      lDataRegMask =\
       (uint32)(Msc_kConfigPtr->ModCfgPtr[ModNum]->DataRegSourceMask);
      /* Load transmit data into the Data register
         only for bits for which emergency data is not enabled.*/
      DataVal = ((uint32)(*(Msc_Data)));
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      DataVal = (MSC_SFR_RUNTIME_USER_MODE_READ32(MSC_REGMAP[ModNum].DD.U)   \
                  & (~lDataRegMask)) | (uint32)(DataVal & lDataRegMask);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
       efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DD.U,DataVal);

      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->ExtensionValue == 0x01U)
      {
        /* Check the bits for which Data register is selected as source*/
        lExtnDataRegMask =\
         (uint32)(Msc_kConfigPtr->ModCfgPtr[ModNum]->DataRegSourceMaskExtn);
        /* Load transmit data into the Data register
           only for bits for which emergency data is not enabled.*/
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        ExtnDataVal = ((uint32)(*(Msc_Data+1U)));
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        ExtnDataVal = (MSC_SFR_RUNTIME_USER_MODE_READ32                     \
                      (MSC_REGMAP[ModNum].DDE.U) & (~lExtnDataRegMask))     \
                       | (uint32)(ExtnDataVal & lExtnDataRegMask);

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        MSC_SFR_RUNTIME_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DDE.U,ExtnDataVal);
      }
      /* If MSC is in Triggered Mode, Set the Data Frame Pending bit*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      TxMode = (uint32)((MSC_SFR_RUNTIME_USER_MODE_READ32                   \
                       (MSC_REGMAP[ModNum].DSC.U)                             \
                        >> IFX_MSC_DSC_TM_OFF) & IFX_MSC_DSC_TM_MSK);


      if(TxMode == MSC_ZERO_U)
      {
         /* Data Frame Pending request bit is set*/
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
         efficiently access the SFRs of multiple MSC kernels*/
         MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].ISC.U,      \
                 MSC_ISC_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_ISC_SDP_OFF))
      }
      RetVal = E_OK;
    }
    else
    {
      /* No Configuration present for the MSC module requested*/
      RetVal = E_NOT_OK;
    }
  }
return (RetVal);
}
#if(MSC_EMERGENCY_DATA_API == STD_ON)
/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_MSC_PR1142,DS_NAS_MSC_PR915,
                      DS_NAS_MSC_PR63_10]                                     **
**                                                                            **
** Syntax          : Std_ReturnType Msc_ReconfigureEmergencyData(uint8 ModNum,**
**                  uint32 Msc_EmergencyDataHigh, uint32 Msc_EmergencyDataLow)**
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x06                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Msc_EmergencyDataHigh - The Higher 16 bits of emergency  **
**                   data high is for DDE.DDHE and the lower 16 bits of       **
**                   emergency data high is for DD.DDH                        **
**                   Msc_EmergencyDataLow  - The Higher 16 bits of emergency  **
**                   data low is for DDE.DDLE and the lower 16 bits of        **
**                   emergency data high is for DD.DDL                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :    E_OK/E_NOT_OK                                         **
**                                                                            **
** Description     : This function:                                           **
**   - Reconfigures the emergency data in DD register                         **
**   - Reconfigures the emergency data in DDE register                        **
*******************************************************************************/
Std_ReturnType Msc_ReconfigureEmergencyData(uint8 ModNum,
               uint32 Msc_EmergencyDataHigh, uint32 Msc_EmergencyDataLow)
{

  Std_ReturnType RetVal;
  uint32 lEmergencyConfig;
  uint32 lEmergencyConfigExtn;
  uint32 lEmergencyData;
  uint32 lEmergencyDataExtn;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_RECONFIGEMERDATA);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_RECONFIGEMERDATA,ModNum);
  }
  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
     RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    lEmergencyConfig = MSC_SFR_RUNTIME_USER_MODE_READ32                     \
                     (MSC_REGMAP[ModNum].ESR.U);

    lEmergencyData = (((Msc_EmergencyDataHigh) & (MSC_EMRDATA_LOW_MASK))<<16)|\
                      (Msc_EmergencyDataLow & (MSC_EMRDATA_LOW_MASK));

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    lEmergencyData = (MSC_SFR_RUNTIME_USER_MODE_READ32(MSC_REGMAP[ModNum].DD.U)\
    & (uint32)(~lEmergencyConfig))|(uint32)(lEmergencyData & lEmergencyConfig);

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    MSC_SFR_RUNTIME_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DD.U,lEmergencyData);

    if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
    {
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->ExtensionValue == 0x01U)
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        lEmergencyConfigExtn = MSC_SFR_RUNTIME_USER_MODE_READ32              \
                          (MSC_REGMAP[ModNum].ESRE.U);

        lEmergencyDataExtn =\
         ((Msc_EmergencyDataHigh) & (MSC_EMRDATA_HIGH_MASK))|                \
         (((Msc_EmergencyDataLow) & (MSC_EMRDATA_HIGH_MASK))>>16);

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        lEmergencyDataExtn= (MSC_SFR_RUNTIME_USER_MODE_READ32                \
        (MSC_REGMAP[ModNum].DDE.U) & (uint32)(~lEmergencyConfigExtn))    \
      | (uint32)(lEmergencyDataExtn & lEmergencyConfigExtn);
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
        MSC_SFR_RUNTIME_USER_MODE_WRITE32(MSC_REGMAP[ModNum].DDE.U,           \
        lEmergencyDataExtn);
      }
    }
    RetVal = E_OK;
  }
return (RetVal);
}
#endif /* End of MSC_EMERGENCY_DATA_API */
/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_MSC_PR1672,DS_NAS_MSC_PR915,
                    DS_NAS_MSC_PR63_11]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Msc_ChangeRxState (uint8 ModNum,         **
**                   Msc_RxStateType Mode)                                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x0E                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Mode - MSC_RX_ON - Receiver is switched ON               **
**                          MSC_RX_OFF - Receiver is switched OFF             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/E_NOTOK                                             **
**                                                                            **
** Description     : This function:                                           **
**   - Activates/Deactivates the receiver (upstream channel) of the           **
**     MSC module                                                             **
*******************************************************************************/
Std_ReturnType Msc_ChangeRxState (uint8 ModNum, Msc_RxStateType Mode)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_CHANGERXSTATUS);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_CHANGERXSTATUS,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for MSC Rx state is valid */
        ErrorFlag = Msc_lDetCheckRxMode(MSC_SID_CHANGERXSTATUS,Mode);
     }
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    RetVal = E_OK;
    if(Mode == MSC_RX_ON)
    {
      /* Module Configuration available for the MSC ModNum*/
      if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
      {
        /* Load the Upstream baud rate from the configuration */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
        efficiently access the SFRs of multiple MSC kernels*/
         MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].USR.U,         \
        MSC_USR_RESRV_URR_CLR_MASK,(Msc_kConfigPtr->ModCfgPtr[ModNum]->\
        RxConfig&MSC_UPSTREAM_BAUD_MASK))
      }
      else
      {
        /*Configuration does not exist for ModNum*/
        RetVal = E_NOT_OK;
      }
    }
    else
    {
      /* Disable the Upstream channel. Set the baud rate to 0*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].USR.U,            \
                              MSC_USR_RESRV_URR_CLR_MASK, MSC_USR_URR_CLR_MASK)
    }
  }
  return (RetVal);
}
/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_MSC_PR1078,DS_NAS_MSC_PR915,
                     DS_NAS_MSC_PR63_12]                                      **
**                                                                            **
** Syntax          : Msc_RxStatusType  Msc_GetRxStatus (uint8 ModNum,         **
**                   Msc_UpstreamRegType Msc_RxRegister)                      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x07                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Msc_RxRegister - MSC_UD0/MSC_UD1/MSC_UD2/MSC_UD3         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Msc_RxStatusType                                         **
**                                                                            **
** Description     : This function :                                          **
**   - returns the status of the Rx register                                  **
*******************************************************************************/
Msc_RxStatusType  Msc_GetRxStatus(uint8 ModNum,
                                  Msc_UpstreamRegType Msc_RxRegister)
{
  Msc_RxStatusType RetVal;
  uint32 ParityErr;
  uint32 ValidBit;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETRXSTATUS);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETRXSTATUS,ModNum);
     if(ErrorFlag == E_OK)
     {
       /* Check for, MSC Rx register is valid */
       ErrorFlag = Msc_lDetCheckRxRegister(MSC_SID_GETRXSTATUS,Msc_RxRegister);
     }
  }

  /* If any DET is reported Return value is made MSC_RX_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = MSC_RX_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    /*Error detected on the Rx frame*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    ParityErr = (uint32)((MSC_SFR_RUNTIME_USER_MODE_READ32                  \
              (MSC_REGMAP[ModNum].UD[Msc_RxRegister].U)                   \
               >> IFX_MSC_UD_PERR_OFF) & IFX_MSC_UD_PERR_MSK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    ValidBit = (uint32)((MSC_SFR_RUNTIME_USER_MODE_READ32                   \
             (MSC_REGMAP[ModNum].UD[Msc_RxRegister].U)                    \
              >> IFX_MSC_UD_V_OFF) & IFX_MSC_UD_V_MSK);

    if(MSC_ONE_U == ParityErr)
    {
      RetVal = MSC_RX_ERROR;
    }
    /*Valid data frame is received*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    else if(MSC_ONE_U == ValidBit)
    {
      RetVal = MSC_DATA_RECEIVED;
    }
    /* No response, data frame not received*/
    else
    {
      RetVal = MSC_RX_NO_RESPONSE;
    }
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_MSC_PR1079,DS_NAS_MSC_PR915,
                    DS_NAS_MSC_PR63_13]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Msc_GetRxData(uint8 ModNum,               **
**                   Msc_UpstreamRegType RxRegister, uint16 *DataRecd)        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x08                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Msc_RxRegister - MSC_UD0/MSC_UD1/MSC_UD2/MSC_UD3         **
**                                                                            **
** Parameters (out): DataRecd - UDx register data is copied to this variable  **
**                                                                            **
** Return value    : E_OK / E_NOT_OK                                          **
**                                                                            **
** Description     : This function :                                          **
**   - returns the data received in the Rx register                           **
*******************************************************************************/
Std_ReturnType Msc_GetRxData(uint8 ModNum, Msc_UpstreamRegType RxRegister,
                            uint16 *DataRecd)
{
  Std_ReturnType RetVal;
  uint16 DataVal;
  uint16 DataVal1;
  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETRXDATA);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETRXDATA,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for, MSC Rx register is valid */
        ErrorFlag = Msc_lDetCheckRxRegister(MSC_SID_GETRXDATA,RxRegister);
     }
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    /* Load the 8-bit data received , and the 2 bit address information*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    DataVal = (uint16)((MSC_SFR_RUNTIME_USER_MODE_READ32                    \
                    (MSC_REGMAP[ModNum].UD[RxRegister].U)                 \
                     >> IFX_MSC_UD_LABF_OFF) & IFX_MSC_UD_LABF_MSK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    DataVal1 = (uint16)((MSC_SFR_RUNTIME_USER_MODE_READ32                   \
                     (MSC_REGMAP[ModNum].UD[RxRegister].U)                \
                        >> IFX_MSC_UD_DATA_OFF) & IFX_MSC_UD_DATA_MSK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    DataVal = ((uint16)(DataVal<<8U) | DataVal1);

    *DataRecd = DataVal;

    /* Clear the valid bit, after reading the data register */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].UD[RxRegister].U,   \
                   MSC_UD_RESRV_C_CLR_MASK, ((uint32) 1 << IFX_MSC_UD_C_OFF))

    RetVal = E_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_MSC_PR1080,DS_NAS_MSC_PR915,
                     DS_NAS_MSC_PR63_14]                                      **
**                                                                            **
** Syntax          : Std_ReturnType Msc_SelectRxDevice(uint8 ModNum,          **
**                   Msc_RxDevSelectType Msc_Device)                          **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x09                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   Msc_Device - Upstream Device to be selected              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK / E_NOT_OK                                          **
**                                                                            **
** Description     : This function :                                          **
**   - selects the upstream device                                            **
*******************************************************************************/
Std_ReturnType Msc_SelectRxDevice(uint8 ModNum, Msc_RxDevSelectType Msc_Device)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_SELRXDEVICE);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_SELRXDEVICE,ModNum);
     if(ErrorFlag == E_OK)
     {
        /* Check for, MSC Rx Device is valid */
        ErrorFlag = Msc_lDetCheckRxDevice(MSC_SID_SELRXDEVICE,Msc_Device);
     }
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
     /*Select the Rx device*/
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
     efficiently access the SFRs of multiple MSC kernels*/
     MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].OCR.U,          \
           MSC_OCR_SDISEL_CLR_MASK,((uint32)Msc_Device <<                 \
           IFX_MSC_OCR_SDISEL_OFF) & MSC_OCR_SDISEL_SET_MASK)

     RetVal = E_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_MSC_PR1081,DS_NAS_MSC_PR915,       **
**                   DS_NAS_MSC_PR63_15]                                      **
**                                                                            **
** Syntax          : Std_ReturnType Msc_StartRxTimeout(uint8 ModNum)          **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x0A                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK / E_NOT_OK                                          **
**                                                                            **
** Description     : This function :                                          **
**   - starts the upstream timeout                                            **
*******************************************************************************/
Std_ReturnType Msc_StartRxTimeout(uint8 ModNum)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_STARTRXTIMEOUT);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_STARTRXTIMEOUT,ModNum);
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
     /*Check if selected MSC module is configured */
     if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
     {
       /*Clear the current timeout flag*/
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
       efficiently access the SFRs of multiple MSC kernels*/
       MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].USCE.U,        \
                MSC_USCE_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_USCE_USTC_OFF))

       /*Reload the Timeout Prescalar and Timeout Value,
       to start the timeout detection*/
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
       efficiently access the SFRs of multiple MSC kernels*/
       MSC_SFR_RUNTIME_USER_MODE_WRITE32(MSC_REGMAP[ModNum].USCE.U,         \
           Msc_kConfigPtr->ModCfgPtr[ModNum] -> UpstreamTimeoutConfig);
       RetVal = E_OK;
     }
     else
     {
       /* Configuration doesnot exist for the ModNum */
       RetVal = E_NOT_OK;
     }

  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_MSC_PR1082,DS_NAS_MSC_PR915,
                     DS_NAS_MSC_PR63_16]                                      **
**                                                                            **
** Syntax          : Msc_RxTimeoutStatusType Msc_GetRxTimeoutStatus           **
**                  (uint8 ModNum)                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x0B                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Msc_RxTimeoutStatusType                                  **
**                                                                            **
** Description     : This function :                                          **
**   - returns the status of the  upstream timeout                            **
*******************************************************************************/
Msc_RxTimeoutStatusType Msc_GetRxTimeoutStatus(uint8 ModNum)
{
  Msc_RxTimeoutStatusType RetVal;
  uint32 TmoutFg;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETRXTIMEOUT);
  if(ErrorFlag == E_OK)
  {
     /* Check for, MSC module number is valid */
     ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETRXTIMEOUT,ModNum);
  }

  /* If any DET is reported Return value is made MSC_TIMEOUT_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = MSC_TIMEOUT_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
     /*Check if timeout has happened*/
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
     efficiently access the SFRs of multiple MSC kernels*/
     TmoutFg = (uint32)((MSC_SFR_RUNTIME_USER_MODE_READ32                   \
             (MSC_REGMAP[ModNum].USCE.U) >> IFX_MSC_USCE_USTF_OFF)        \
          & IFX_MSC_USCE_USTF_MSK);

     if(TmoutFg == MSC_ONE_U)
     {
       RetVal = MSC_UPSTREAM_TIMEOUT;
     }
     else
     {
       RetVal = MSC_UPSTREAM_NO_TIMEOUT;
     }
  }
return (RetVal);
}

#if (MSC_PASSIVE_TIME_FRAME_API == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_MSC_PR1143,DS_NAS_MSC_PR915,
                     DS_NAS_MSC_PR63_17]                                      **
**                                                                            **
** Syntax          : Std_ReturnType                                           **
**                   Msc_GetPassiveTimeFrameCounter (uint8 ModNum,            **
**                   Msc_PassiveTimeFrameCounterType *CounterValue)           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x0C                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Msc_GetPassiveTimeFrameCounter                           **
**                                                                            **
** Description     : This function :                                          **
**   - returns the status of the  upstream timeout                            **
*******************************************************************************/
Std_ReturnType Msc_GetPassiveTimeFrameCounter (uint8 ModNum,
              Msc_PassiveTimeFrameCounterType *CounterValue)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_GETTIMEFRMCOUNTER);
  if(ErrorFlag == E_OK)
  {
    /* Check for, MSC module number is valid */
    ErrorFlag = Msc_lDetCheckModule(MSC_SID_GETTIMEFRMCOUNTER,ModNum);
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    if(CounterValue != NULL_PTR)
    {
      /* Load the Passive Time frame Counter */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
       efficiently access the SFRs of multiple MSC kernels*/
      *CounterValue = (Msc_PassiveTimeFrameCounterType)                      \
           ((MSC_SFR_RUNTIME_USER_MODE_READ32(MSC_REGMAP[ModNum].DSS.U)    \
          >> IFX_MSC_DSS_PFC_OFF) & IFX_MSC_DSS_PFC_MSK);
      RetVal = E_OK;
    }
    else
    {
      RetVal = E_NOT_OK;
    }
  }
return (RetVal);
}
#endif /* End of MSC_PASSIVE_TIME_FRAME_API */

/*******************************************************************************
** Traceability    :[cover parentID=DS_NAS_MSC_PR2980]                        **
**                                                                            **
** Syntax          : Std_ReturnType Msc_EnableInterrupts(uint8 ModNum)        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x0F                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK / E_NOT_OK                                          **
**                                                                            **
** Description     : This function :                                          **
**   - enables the interrupts as per configuration                            **
*******************************************************************************/
Std_ReturnType Msc_EnableInterrupts(uint8 ModNum)
{
  Std_ReturnType RetVal;

  /* Check for DET's, only if DET is enabled */
  #if ( MSC_DEV_ERROR_DETECT == STD_ON )

  Std_ReturnType ErrorFlag;

  /* Check for MSC Driver is Initialized */
  ErrorFlag = Msc_lDetCheckUnInit(MSC_SID_ENABLEINTERRUPTS);
  if(ErrorFlag == E_OK)
  {
    /* Check for, MSC module number is valid */
    ErrorFlag = Msc_lDetCheckModule(MSC_SID_ENABLEINTERRUPTS,ModNum);
  }

  /* If any DET is reported Return value is made E_NOT_OK */
  if(ErrorFlag == E_NOT_OK)
  {
    RetVal = E_NOT_OK;
  }
  else
  #endif /* End of MSC_DEV_ERROR_DETECT */
  {
    /*Check if selected MSC module is configured */
    if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
    {
      /*Update the ICR register for Interrupts*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_WRITE32(MSC_REGMAP[ModNum].ICR.U,          \
      Msc_kConfigPtr->ModCfgPtr[ModNum]-> InterruptConfig.InterruptControl);
      RetVal = E_OK;
    }
    else
    {
      /* Configuration doesnot exist for the ModNum */
      RetVal = E_NOT_OK;
    }
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : void Msc_InterruptHandler(uint8 ModNum,                  **
**                     uint8 ServiceNum)                                      **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Asynchronous                                             **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - MSC module Number                               **
**                   ServiceNum - Service number from which API is invoked    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function :                                          **
**   - Calls the configured application functions for individual Interrupts   **
*******************************************************************************/
void Msc_InterruptHandler(uint8 ModNum, uint8 ServiceNum)
{
  uint8 RxInptFlag;
  uint8 CmdInptFlag;
  uint8 DataInptFlag;
  uint8 TimeInptFlag;
  uint8 RxConfigSrv;
  uint8 CmdConfigSrv;
  uint8 DataConfigSrv;
  uint8 TimeConfigSrv;

  /* Interrupt Handler is executed only if Module is configured */
  if(Msc_kConfigPtr->ModCfgPtr[ModNum] != NULL_PTR)
  {
    /*Capture the Interrupt Pending Flags*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    RxInptFlag = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32                   \
                 (MSC_REGMAP[ModNum].ISR.U)                                  \
                  >> IFX_MSC_ISR_URDI_OFF) & IFX_MSC_ISR_URDI_MSK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    CmdInptFlag = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32                  \
                  (MSC_REGMAP[ModNum].ISR.U)                                 \
                   >> IFX_MSC_ISR_DECI_OFF) & IFX_MSC_ISR_DECI_MSK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    TimeInptFlag = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32                 \
                   (MSC_REGMAP[ModNum].ISR.U)                                \
                    >> IFX_MSC_ISR_DTFI_OFF) & IFX_MSC_ISR_DTFI_MSK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    DataInptFlag = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32                 \
                   (MSC_REGMAP[ModNum].ISR.U)                                \
                    >> IFX_MSC_ISR_DEDI_OFF) & IFX_MSC_ISR_DEDI_MSK);
    /* Capture the Service request configured for each interrupt */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    RxConfigSrv = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32                  \
                  (MSC_REGMAP[ModNum].ICR.U)                                 \
                   >> IFX_MSC_ICR_RDIP_OFF) & IFX_MSC_ICR_RDIP_MSK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    CmdConfigSrv = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32                 \
                   (MSC_REGMAP[ModNum].ICR.U)                                \
                    >> IFX_MSC_ICR_ECIP_OFF) & IFX_MSC_ICR_ECIP_MSK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    TimeConfigSrv = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32                \
                    (MSC_REGMAP[ModNum].ICR.U)                               \
                     >> IFX_MSC_ICR_TFIP_OFF) & IFX_MSC_ICR_TFIP_MSK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    DataConfigSrv = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32                \
                    (MSC_REGMAP[ModNum].ICR.U)                               \
                     >> IFX_MSC_ICR_EDIP_OFF) & IFX_MSC_ICR_EDIP_MSK);
    #ifdef IFX_MSC_DEBUG03
    TestMSC_DebugMask03 = ServiceNum;
    CmdConfigSrv = TestMSC_DebugMask03;
    TimeConfigSrv = TestMSC_DebugMask03;
    DataConfigSrv = TestMSC_DebugMask03;
    CmdInptFlag = MSC_ZERO_U;
    TimeInptFlag = MSC_ZERO_U;
    DataInptFlag = MSC_ZERO_U;
    #endif /*#ifdef IFX_MSC_DEBUG03 */

    #ifdef IFX_MSC_DEBUG04
    DataConfigSrv = TestMSC_DebugMask04;
    #endif/* #ifdef IFX_MSC_DEBUG04 */

    /* Rx Frame Interrupt Sevice */
    /* Check if, Rx interrupt is pending and current service is configired for
       this interrupt*/
    if((RxConfigSrv == ServiceNum) && (RxInptFlag == MSC_ONE_U))
    {
      /*Clear the Interrupt Pending Flag*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].ISC.U,          \
                  MSC_ISC_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_ISC_CURDI_OFF))
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.RxFrmNotify != NULL_PTR)
      {
        /*Call the Application Notifier Function*/
        (Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.RxFrmNotify)();
      }
    }
    /* Command Frame Interrupt Sevice */
    /* Check if, Cmd interrupt is pending and current service is configired
       for this interrupt*/
    else if((CmdConfigSrv == ServiceNum) && (CmdInptFlag == MSC_ONE_U))
    {
      /*Clear the Interrupt Pending Flag*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].ISC.U,            \
                 MSC_ISC_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_ISC_CDECI_OFF))
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.CmdFrmNotify != NULL_PTR)
      {
        /*Call the Application Notifier Function*/
        (Msc_kConfigPtr->ModCfgPtr[ModNum]->InterruptConfig.CmdFrmNotify)();
      }
    }
    /* Time Frame Interrupt Sevice */
    /* Check if, Time interrupt is pending and current service is configired
    for this interrupt*/
    else if((TimeConfigSrv == ServiceNum) && (TimeInptFlag == MSC_ONE_U))
    {
      /*Clear the Interrupt Pending Flag*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].ISC.U,         \
                  MSC_ISC_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_ISC_CDTFI_OFF))
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.TimeFrmNotify != NULL_PTR)
      {
        /*Call the Application Notifier Function*/
        (Msc_kConfigPtr->ModCfgPtr[ModNum]->InterruptConfig.TimeFrmNotify)();
      }
    }
    /* Data Frame Interrupt Sevice */
    /* Check if, Data interrupt is pending and current service is configired
       for this interrupt */
    else if((DataConfigSrv == ServiceNum) && (DataInptFlag  == MSC_ONE_U))
    {
      /*Clear the Interrupt Pending Flag*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple MSC kernels*/
      MSC_SFR_RUNTIME_USER_MODE_MODIFY32(MSC_REGMAP[ModNum].ISC.U,          \
                 MSC_ISC_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_ISC_CDEDI_OFF))
      if(Msc_kConfigPtr->ModCfgPtr[ModNum]->\
         InterruptConfig.DataFrmNotify != NULL_PTR)
      {
        /*Call the Application Notifier Function*/
        (Msc_kConfigPtr->ModCfgPtr[ModNum]->InterruptConfig.DataFrmNotify)();
      }
    }
    else
    {
      /*Do Nothing*/
    }
  }

}


/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static void Msc_lEnableHwIntrService(uint8 ModNum,       **
**                   uint8 SrvConfig)                                         **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ModNum - Module Number                                   **
**                   SrvConfig - SR configuration                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function :                                          **
**   - enabled the Interrupt service requests                                 **
*******************************************************************************/
static void Msc_lEnableHwIntrService(uint8 ModNum, uint8 SrvConfig)
{
  if((SrvConfig & MSC_BIT0) == MSC_BIT0)
  {
    /* Enable SR0, if enabled in configuration*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    MSC_SFR_INIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR0.U,                   \
               MSC_SRC_SRE_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_SRE_OFF))
  }
  if((SrvConfig & MSC_BIT1) == MSC_BIT1)
  {
    /* Enable SR1, if enabled in configuration*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    MSC_SFR_INIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR1.U,             \
               MSC_SRC_SRE_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_SRE_OFF))
  }
  if((SrvConfig & MSC_BIT2) == MSC_BIT2)
  {
    /* Enable SR2, if enabled in configuration*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    MSC_SFR_INIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR2.U,             \
               MSC_SRC_SRE_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_SRE_OFF))
  }
  if((SrvConfig & MSC_BIT3) == MSC_BIT3)
  {
    /* Enable SR3, if enabled in configuration*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    MSC_SFR_INIT_MODIFY32(MSC_SRC_REGMAP[ModNum].SR3.U,              \
              MSC_SRC_SRE_RESRV_CLR_MASK, ((uint32) 1 << IFX_SRC_SRCR_SRE_OFF))
  }
}
#if (MSC_RESET_SFR_INIT == STD_ON)
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static void Msc_lResetKernelsInit(uint8 ModNum)          **
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
** Description     : This function :                                          **
**   - Execute kernel reset for all available kernels                         **
*******************************************************************************/
static void Msc_lResetKernelsInit(uint8 ModNum)
{
  volatile uint32 Readback;
  uint32 WaitCount,RstStatus;

  /*Clear the ENDINIT bit in the WDT_CONSR register in order
  to disable the write-protection for registers protected
  via the EndInit feature */
  MSC_SFR_INIT_RESETENDINIT();

  /* Set request to reset the MSC Kernel */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  MSC_SFR_INIT_MODIFY32(MSC_REGMAP[ModNum].KRST0.U,                       \
                MSC_KRST0_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_KRST0_RST_OFF))
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  Readback = MSC_SFR_INIT_USER_MODE_READ32(MSC_REGMAP[ModNum].KRST0.U);

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  MSC_SFR_INIT_MODIFY32(MSC_REGMAP[ModNum].KRST1.U,                       \
               MSC_KRST1_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_KRST1_RST_OFF))
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  Readback = MSC_SFR_INIT_USER_MODE_READ32(MSC_REGMAP[ModNum].KRST1.U);

  /* Set the ENDINIT bit in the WDT_CONSR register again
  to enable the write-protection and to prevent a time-out */
  MSC_SFR_INIT_SETENDINIT();

  WaitCount = (uint32)MSC_KERNEL_RESET_WAIT_COUNTS;
  do
  {
    WaitCount--;
    #ifdef IFX_MSC_DEBUG05
    RstStatus = (uint32)(((MSC_SFR_INIT_USER_MODE_READ32                  \
              (MSC_REGMAP[ModNum].KRST0.U) >> IFX_MSC_KRST0_RSTSTAT_OFF)   \
         & IFX_MSC_KRST0_RSTSTAT_MSK) & TestMSC_DebugMask05);
    #else
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    RstStatus = (uint32)((MSC_SFR_INIT_USER_MODE_READ32                   \
              (MSC_REGMAP[ModNum].KRST0.U) >> IFX_MSC_KRST0_RSTSTAT_OFF)   \
         & IFX_MSC_KRST0_RSTSTAT_MSK);

    #endif
  }while((RstStatus == MSC_ZERO_U)&&(WaitCount > MSC_ZERO_U));

  /*Clear the ENDINIT bit in the WDT_CONSR register in order
  to disable the write-protection for registers protected
  via the EndInit feature */
  MSC_SFR_INIT_RESETENDINIT();
  /* Clear the MSC Kernel Reset Flag */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  MSC_SFR_INIT_MODIFY32(MSC_REGMAP[ModNum].KRSTCLR.U,                     \
            MSC_KRSTCLR_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_KRSTCLR_CLR_OFF))
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  Readback = MSC_SFR_INIT_USER_MODE_READ32(MSC_REGMAP[ModNum].KRSTCLR.U);
  /* Set the ENDINIT bit in the WDT_CONSR register again
  to enable the write-protection and to prevent a time-out */
  MSC_SFR_INIT_SETENDINIT();
  UNUSED_PARAMETER(Readback)
}
#endif
#if (MSC_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static void Msc_lResetKernelsDeInit(uint8 ModNum)        **
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
** Description     : This function :                                          **
**   - Execute kernel reset for all available kernels                         **
*******************************************************************************/
static void Msc_lResetKernelsDeInit(uint8 ModNum)
{
  volatile uint32 Readback;
  uint32 WaitCount,RstStatus;

  /*Clear the ENDINIT bit in the WDT_CONSR register in order
  to disable the write-protection for registers protected
  via the EndInit feature */
  MSC_SFR_DEINIT_RESETENDINIT();

  /* Set request to reset the MSC Kernel */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  MSC_SFR_DEINIT_MODIFY32(MSC_REGMAP[ModNum].KRST0.U,                       \
               MSC_KRST0_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_KRST0_RST_OFF))
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  Readback = MSC_SFR_DEINIT_USER_MODE_READ32(MSC_REGMAP[ModNum].KRST0.U);

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  MSC_SFR_DEINIT_MODIFY32(MSC_REGMAP[ModNum].KRST1.U,                       \
               MSC_KRST1_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_KRST1_RST_OFF))
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  Readback = MSC_SFR_DEINIT_USER_MODE_READ32(MSC_REGMAP[ModNum].KRST1.U);

  /* Set the ENDINIT bit in the WDT_CONSR register again
  to enable the write-protection and to prevent a time-out */
  MSC_SFR_DEINIT_SETENDINIT();

  WaitCount = (uint32)MSC_KERNEL_RESET_WAIT_COUNTS;
  do
  {
    WaitCount--;
    #ifdef IFX_MSC_DEBUG05
    RstStatus = (uint32)(((MSC_SFR_DEINIT_USER_MODE_READ32                  \
                (MSC_REGMAP[ModNum].KRST0.U) >> IFX_MSC_KRST0_RSTSTAT_OFF)   \
                 & IFX_MSC_KRST0_RSTSTAT_MSK) & TestMSC_DebugMask05);
    #else
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    RstStatus = (uint32)((MSC_SFR_DEINIT_USER_MODE_READ32                   \
                (MSC_REGMAP[ModNum].KRST0.U) >> IFX_MSC_KRST0_RSTSTAT_OFF)   \
                 & IFX_MSC_KRST0_RSTSTAT_MSK);

    #endif
  }while((RstStatus == MSC_ZERO_U)&&(WaitCount > MSC_ZERO_U));

  /*Clear the ENDINIT bit in the WDT_CONSR register in order
  to disable the write-protection for registers protected
  via the EndInit feature */
  MSC_SFR_DEINIT_RESETENDINIT();
  /* Clear the MSC Kernel Reset Flag */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  MSC_SFR_DEINIT_MODIFY32(MSC_REGMAP[ModNum].KRSTCLR.U,                     \
          MSC_KRSTCLR_RESRV_CLR_MASK, ((uint32) 1 << IFX_MSC_KRSTCLR_CLR_OFF))
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  Readback = MSC_SFR_DEINIT_USER_MODE_READ32(MSC_REGMAP[ModNum].KRSTCLR.U);
  /* Set the ENDINIT bit in the WDT_CONSR register again
  to enable the write-protection and to prevent a time-out */
  MSC_SFR_DEINIT_SETENDINIT();
  UNUSED_PARAMETER(Readback)
}
#endif

#if (MSC_DEV_ERROR_DETECT == STD_ON )
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckUnInit                **
**                   (uint8 ServiceId)                                        **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if MSC is uninitialized                                  **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckUnInit(uint8 ServiceId)
{
  Std_ReturnType RetVal;
  if(Msc_DriverState == MSC_DRIVER_UNINIT)
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_UNINIT);
    RetVal = E_NOT_OK;
  }
  else
  {
    RetVal = E_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckModule                **
**                   (uint8 ServiceId, uint8 Module)                          **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   Module - Module ID of MSC                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if MSC module is invalid                                 **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckModule(uint8 ServiceId,uint8 Module)
{
  Std_ReturnType RetVal;
  uint8 ModuleDisabled;

  if(Module >= MSC_NUM_OF_MODULES)
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_MODULE);
    RetVal = E_NOT_OK;
  }
  else
  {
    #ifdef IFX_MSC_DEBUG02
    ModuleDisabled = TestMSC_DebugMask02;
    #else
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple MSC kernels*/
    ModuleDisabled = (uint8)((MSC_SFR_RUNTIME_USER_MODE_READ32              \
                     (MSC_REGMAP[Module].CLC.U)                             \
                      >> IFX_MSC_CLC_DISS_OFF) & IFX_MSC_CLC_DISS_MSK);
    #endif/*#ifdef IFX_MSC_DEBUG02*/

    if( (ModuleDisabled == 1U) ||\
        (Msc_kConfigPtr->ModCfgPtr[Module] == NULL_PTR) )
    {
      Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                       ServiceId,MSC_E_INVALID_MODULE);
      RetVal = E_NOT_OK;
    }
    else
    {
      RetVal = E_OK;
    }
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckTxMode(uint8          **
**                       ServiceId, Msc_TxStateType TxState)                  **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   TxState - State of the tranmsmitter                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if transmitter of MSC module is OFF                      **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckTxMode(uint8 ServiceId,
                                         Msc_TxStateType TxState)
{
  Std_ReturnType RetVal;
  if((TxState == MSC_TX_ON) || (TxState == MSC_TX_OFF))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_MODE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckRxMode(uint8          **
**                       ServiceId, Msc_RxStateType RxState)                  **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   TxState - State of the tranmsmitter                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if Rx Mode is valid                                      **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckRxMode(uint8 ServiceId,
                                         Msc_RxStateType RxState)
{
  Std_ReturnType RetVal;
  if((RxState == MSC_RX_ON) || (RxState == MSC_RX_OFF))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_MODE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckTxType(uint8          **
**                   ServiceId, Msc_TxType FrmTyp)                            **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   FrmTyp - Type of Frame (Command/Data)                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if frame type is invalid                                 **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckTxType(uint8 ServiceId,
                                         Msc_TxType FrmTyp)
{
  Std_ReturnType RetVal;
  if((FrmTyp == MSC_CMD_FRAME) || (FrmTyp == MSC_DATA_FRAME))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_TXTYPE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckTxDevice(uint8        **
**                   ServiceId, Msc_TxDevSelectType Device)                   **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   Device - Downstream device                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if downstream device is invalid                          **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckTxDevice(uint8 ServiceId,
                                           Msc_TxDevSelectType Device)
{
  Std_ReturnType RetVal;
  if((Device == MSC_TX_DEVICE_0) || (Device == MSC_TX_DEVICE_1)||\
     (Device == MSC_TX_DEVICE_2) || (Device == MSC_TX_DEVICE_3))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_DEVICE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckTxState(uint8         **
**                   ServiceId, uint8 ModNum)                                 **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   ModNum - Module number for MSC                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if transmitter is in OFF state                           **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckTxState(uint8 ServiceId, uint8 ModNum)
{
  Std_ReturnType RetVal;
  uint32 DwnStrmD;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
  efficiently access the SFRs of multiple MSC kernels*/
  DwnStrmD = (uint32)((MSC_SFR_RUNTIME_USER_MODE_READ32                      \
             (MSC_REGMAP[ModNum].DSC.U) >> IFX_MSC_DSC_DSDIS_OFF)            \
              & IFX_MSC_DSC_DSDIS_MSK);
  if(DwnStrmD == MSC_ZERO_U)
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_STATE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckRxRegister(uint8      **
**                   ServiceId, Msc_UpstreamRegType UpReg)                    **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   UpReg - Upstream Register for MSC                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if UpReg is invalid                                      **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckRxRegister(uint8 ServiceId,
                                      Msc_UpstreamRegType UpReg)
{
  Std_ReturnType RetVal;
  if((UpReg == MSC_UD0) || (UpReg == MSC_UD1) ||\
     (UpReg == MSC_UD2) || (UpReg == MSC_UD3))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_RXREGISTER);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static Std_ReturnType Msc_lDetCheckRxDevice(uint8        **
**                   ServiceId, Msc_RxDevSelectType Device)                   **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : ServiceId - Service ID of the API from which this API is **
**                   invoked                                                  **
**                   Device - Upstream Device for MSC                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK/ E_NOT_OK                                           **
**                                                                            **
** Description     : This function :                                          **
**   - reports a DET if Upstream Device is invalid                            **
*******************************************************************************/
static Std_ReturnType Msc_lDetCheckRxDevice(uint8 ServiceId,
                                     Msc_RxDevSelectType Device)
{
  Std_ReturnType RetVal;
  if((Device == MSC_RX_DEVICE_0) || (Device == MSC_RX_DEVICE_1) ||          \
     (Device == MSC_RX_DEVICE_2) || (Device == MSC_RX_DEVICE_3) ||          \
     (Device == MSC_RX_DEVICE_4) || (Device == MSC_RX_DEVICE_5) ||          \
     (Device == MSC_RX_DEVICE_6) || (Device == MSC_RX_DEVICE_7))
  {
    RetVal = E_OK;
  }
  else
  {
    Det_ReportError((uint16)MSC_MODULE_ID,MSC_MODULE_INSTANCE,
                     ServiceId,MSC_E_INVALID_RXDEVICE);
    RetVal = E_NOT_OK;
  }
return (RetVal);
}

#endif /* End of MSC_DEV_ERROR_DETECT */


#define MSC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
