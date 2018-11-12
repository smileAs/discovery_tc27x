[!/*****************************************************************************
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
**   $FILENAME   : SafeWdgExtTlf_Cfg.h $                                      **
**                                                                            **
**   $CC VERSION : \main\10 $                                                 **
**                                                                            **
**   $DATE       : 2015-12-04 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgExtTlf.bmd/xdm                             **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SafeWdgExtTlf_Cfg.h file                 **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*************************************************************************/!][!//
[!//
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
**  FILENAME  :  SafeWdgExtTlf_Cfg.h                                          **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgExtTlf.bmd /xdm                            **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgExtTlf configuration header file                    **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SAFEWDGEXTTLF_CFG_H
#define SAFEWDGEXTTLF_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!SELECT "as:modconf('SafeWdgExtTlf')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SafeWdgExtTlfConfigSet/*))"!][!//


#define SAFEWDGEXTTLF_CFG_PARAM_COUNT       ([!"$TotalConfig"!]U )

[!IF "SafeWdgExtTlfErrPinMontr/SafeWdgExtTlfErrPinMontrEn = 'true'"!][!//
#define SAFEWDGEXTTLF_ERR_PIN_MONITOR_ENABLE
[!ENDIF!][!//
/*SYSPCFG0 register settings*/
[!IF "SafeWdgExtTlfSysPCfg0/SafeWdgExtTlfStbyEn = 'true'"!][!//
/*Standby Enabled*/
#define SAFEWDGEXTTLF_STAND_BY_ENABLE 0x01U
[!ELSE!][!//
/*Standby Disabled*/
#define SAFEWDGEXTTLF_STAND_BY_ENABLE 0x0U
[!ENDIF!][!//
/*SYSPCFG1 register settings*/
[!IF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfErrRec = 'ErrRec_1ms'"!][!//
/*ERR pin monitor recovery time is set to 1 ms*/
#define SAFEWDGEXTTLF_ERRREC_TIME 0x0U
[!ELSEIF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfErrRec = 'ErrRec_2_5ms'"!][!//
/*ERR pin monitor recovery time is set to 2.5 ms*/
#define SAFEWDGEXTTLF_ERRREC_TIME 0x1U
[!ELSEIF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfErrRec = 'ErrRec_5ms'"!][!//
/*ERR pin monitor recovery time is set to 5 ms*/
#define SAFEWDGEXTTLF_ERRREC_TIME 0x2U
[!ELSE!][!//
/*ERR pin monitor recovery time is set to 10 ms*/
#define SAFEWDGEXTTLF_ERRREC_TIME 0x3U
[!ENDIF!][!//
[!IF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfSs2Del = 'Ss2Del_0ms'"!][!//
/*Safe state 2 delay is set to 0 ms*/
#define SAFEWDGEXTTLF_SS2DEL_TIME 0x0U
[!ELSEIF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfSs2Del = 'Ss2Del_10ms'"!][!//
/*Safe state 2 delay is set to 10 ms*/
#define SAFEWDGEXTTLF_SS2DEL_TIME 0x20U
[!ELSEIF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfSs2Del = 'Ss2Del_50ms'"!][!//
/*Safe state 2 delay is set to 50 ms*/
#define SAFEWDGEXTTLF_SS2DEL_TIME 0x40U
[!ELSEIF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfSs2Del = 'Ss2Del_100ms'"!][!//
/*Safe state 2 delay is set to 100 ms*/
#define SAFEWDGEXTTLF_SS2DEL_TIME 0x60U
[!ELSEIF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfSs2Del = 'Ss2Del_250ms'"!][!//
/*Safe state 2 delay is set to 250 ms*/
#define SAFEWDGEXTTLF_SS2DEL_TIME 0x80U
[!ENDIF!][!//
[!IF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfErrRecEn = 'true'"!][!//
/*Err pin monitor recovery enabled*/
#define SAFEWDGEXTTLF_ERR_REC_EN 0x04U
[!ELSE!][!//
/*Err pin monitor recovery Disabled*/
#define SAFEWDGEXTTLF_ERR_REC_EN 0x0U
[!ENDIF!][!//
[!IF "SafeWdgExtTlfSysPCfg1/SafeWdgExtTlfErrSlpEn = 'true'"!][!//
/*ERR pin monitor functionality while the system is in
SLEEP mode is enabled*/
#define SAFEWDGEXTTLF_ERRSLP_EN 0x10U
[!ELSE!][!//
/*ERR pin monitor functionality while the system is in
SLEEP mode is disabled*/
#define SAFEWDGEXTTLF_ERRSLP_EN 0x0U
[!ENDIF!][!//
/*WDCFG1 register settings*/
[!IF "SafeWdgExtTlfWdCfg1/SafeWdgExtTlfWdSlpEn = 'true'"!][!//
/*watchdog functionality while the system is in SLEEP
mode is enabled*/
#define SAFEWDGEXTTLF_WDSLP_EN 0x10U
[!ELSE!][!//
/*watchdog functionality while the system is in SLEEP
mode is disabled*/
#define SAFEWDGEXTTLF_WDSLP_EN 0x0U
[!ENDIF!][!//
/*DEVCTRL register settings*/
[!IF "SafeWdgExtTlfDevCtrl/SafeWdgExtTlfVrefEn = 'true'"!][!//
/*reference voltage is enabled*/
#define SAFEWDGEXTTLF_VREF_EN 0x08U
[!ELSE!][!//
/*reference voltage is disabled*/
#define SAFEWDGEXTTLF_VREF_EN 0x0U
[!ENDIF!][!//
[!IF "SafeWdgExtTlfDevCtrl/SafeWdgExtTlfComEn = 'true'"!][!//
/*communication LDO is enabled*/
#define SAFEWDGEXTTLF_COM_EN 0x20U
[!ELSE!][!//
/*communication LDO is disabled*/
#define SAFEWDGEXTTLF_COM_EN 0x0U
[!ENDIF!][!//
[!IF "SafeWdgExtTlfDevCtrl/SafeWdgExtTlfTrk1En = 'true'"!][!//
/*Tracker1 LDO is enabled*/
#define SAFEWDGEXTTLF_TRK1_EN 0x40U
[!ELSE!][!//
/*Tracker1 LDO is disabled*/
#define SAFEWDGEXTTLF_TRK1_EN 0x0U
[!ENDIF!][!//
[!IF "SafeWdgExtTlfDevCtrl/SafeWdgExtTlfTrk2En = 'true'"!][!//
/*Tracker2 LDO is enabled*/
#define SAFEWDGEXTTLF_TRK2_EN 0x80U
[!ELSE!][!//
/*Tracker2 LDO is disabled*/
#define SAFEWDGEXTTLF_TRK2_EN 0x0U
[!ENDIF!][!//
/*
--------------------------------------------------------------------------------
  Debug switch:
   TRUE: It allows user to ignore signature verification by watchdog and 
          calculate expected XOR mask required to generate required signature. 
   FALSE: Signatures are verified by TLF watchdog. Default generated value.
          This switch MUST be FALSE in production code.
--------------------------------------------------------------------------------
*/
#define _SAFEWDG_TLF_DEBUG_  (FALSE)

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

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
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!][!//
#endif  /*SAFEWDGEXTTLF_CFG_H */
[!AUTOSPACING!]

