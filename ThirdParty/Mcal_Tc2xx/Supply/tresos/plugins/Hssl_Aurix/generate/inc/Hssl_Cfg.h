[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Hssl_Cfg.h $                                               **
**                                                                           **
**  $CC VERSION : \main\10 $                                                 **
**                                                                           **
**  $DATE       : 2016-07-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Hssl_Cfg.h file                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY: [cover parentID=]
**  [/cover]                                                                  **
*/!][!//
[!//
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
**  FILENAME  : Hssl_Cfg.h                                                    **
**                                                                            **
**  $CC VERSION : \main\10 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : HSSL configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/******************************************************************************/
#ifndef HSSL_CFG_H
#define HSSL_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Hssl')[1]"!][!//
[!//
[!//
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
#define HSSL_SW_MAJOR_VERSION              ([!"$SwMajorVersion"!]U)
#define HSSL_SW_MINOR_VERSION              ([!"$SwMinorVersion"!]U)
#define HSSL_SW_PATCH_VERSION              ([!"$SwPatchVersion"!]U)

[!VAR "HsslModuleConfigPath" = "'HsslGeneral'"!][!//
[!VAR "AccessMode"       = "''"!][!//
[!//
/*
Configuration: HSSL_DEV_ERROR_DETECT
- if STD_ON, DET is Enabled
- if STD_OFF,DET is Disabled

If the switch HSSL_DEV_ERROR_DETECT is enabled API parameter checking
is also enabled.
*/
#define HSSL_DEV_ERROR_DETECT  ([!//
[!IF "HsslGeneral/HsslDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

#define HSSL_CH2_STREAMING       (1U)
#define HSSL_CH2_COMMAND         (0U)

#define HSSL_STREAMING_CH_MODE  ([!//
[!IF "HsslGeneral/HsslCh2Mode = 'true'"!][!//
HSSL_CH2_STREAMING[!//
[!ELSE!][!//
HSSL_CH2_COMMAND[!//
[!ENDIF!][!//
)

#define  HSSL_STREAMING_MODE_CONTINOUS     (0U)
#define  HSSL_STREAMING_MODE_SINGLE        (1U)

#define HSSL_STREAMING_MODE_TX  ([!//
[!IF "HsslGeneral/HsslStreamingModeTx = 'true'"!][!//
HSSL_STREAMING_MODE_SINGLE[!//
[!ELSE!][!//
HSSL_STREAMING_MODE_CONTINOUS[!//
[!ENDIF!][!//
)
[!//
#define HSSL_STREAMING_MODE_RX  ([!//
[!IF "HsslGeneral/HsslStreamingModeRx = 'true'"!][!//
HSSL_STREAMING_MODE_SINGLE[!//
[!ELSE!][!//
HSSL_STREAMING_MODE_CONTINOUS[!//
[!ENDIF!][!//
)

/* Configuration: HSSL_RESET_SFR_AT_INIT
HSSL Enable/Disable Reset of SFR's during Init
- if STD_ON, Enables Reset of SFR's during Init
- if STD_OFF, Disables Reset of SFR's during Init
*/
#define HSSL_RESET_SFR_AT_INIT  ([!//
[!IF "HsslGeneral/HsslResetSfrAtInit = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Address pointer containing the address of the memory
location containing the unique ID data */
#define HSSL_TIDADD_ADDR ([!//
[!"num:inttohex(HsslGeneral/HsslTargetIDAddr)"!]U)

[!//
[!VAR "DmaChUsed" = "(node:ref(HsslGeneral/HsslDmaChannelRef)/ChannelUsed)"!][!//
[!VAR "DmaChNum" = "(node:ref(HsslGeneral/HsslDmaChannelRef)/ChannelId)"!][!//
[!IF "$DmaChUsed != 'USE_FOR_HSSL_DRIVER'"!][!//
[!ERROR!][!//
Configure the DmaChannel_[!"$DmaChNum"!] for HSSL in Mcu Configuration [!//
 [!ENDERROR!][!//
[!ENDIF!][!//
/* DMA Channel Used for Multi Write Transfer */
#define HSSL_DMA_CHANNEL_USED          (DMA_CHANNEL[!"$DmaChNum"!])
[!//

/* User function to handle HSSL call backs */
[!NOCODE!][!//
[!// Check if user function to handle HSSL is specified
[!ASSERT "not(node:ref($HsslModuleConfigPath)/HsslUserFunction = 'NULL')"!][!//
Error: User function to handle HSSL fnctionality is not specified.[!//
[!ENDASSERT!][!//
[!ENDNOCODE!][!//
[!//
#ifdef [!"node:ref($HsslModuleConfigPath)/HsslUserFunction"!]
#error [!"node:ref($HsslModuleConfigPath)/HsslUserFunction"!] already defined
#endif
#define HSSL_HANDLE_CALLBACK           ([!"node:ref($HsslModuleConfigPath)/HsslUserFunction"!])
[!//

/* Memory Access Window and Protection Window definitions for HSSL */
#define HSSL_ACCESS_WINDOW_START_ADDR0 ([!//
[!"num:inttohex(HsslMemoryAccessConfig/HsslAcessWindowStartAddr0)"!]U)[!//

#define HSSL_ACCESS_WINDOW_START_ADDR1 ([!//
[!"num:inttohex(HsslMemoryAccessConfig/HsslAcessWindowStartAddr1)"!]U)[!//

#define HSSL_ACCESS_WINDOW_START_ADDR2 ([!//
[!"num:inttohex(HsslMemoryAccessConfig/HsslAcessWindowStartAddr2)"!]U)[!//

#define HSSL_ACCESS_WINDOW_START_ADDR3 ([!//
[!"num:inttohex(HsslMemoryAccessConfig/HsslAcessWindowStartAddr3)"!]U)[!//


#define HSSL_ACCESS_WINDOW_END_ADDR0 ([!//
[!"num:inttohex(HsslMemoryAccessConfig/HsslAcessWindowEndAddr0)"!]U)[!//

#define HSSL_ACCESS_WINDOW_END_ADDR1 ([!//
[!"num:inttohex(HsslMemoryAccessConfig/HsslAcessWindowEndAddr1)"!]U)[!//

#define HSSL_ACCESS_WINDOW_END_ADDR2 ([!//
[!"num:inttohex(HsslMemoryAccessConfig/HsslAcessWindowEndAddr2)"!]U)[!//

#define HSSL_ACCESS_WINDOW_END_ADDR3 ([!//
[!"num:inttohex(HsslMemoryAccessConfig/HsslAcessWindowEndAddr3)"!]U)[!//

  [!/* ------ Determine the Access Modes for Memory ----- */!][!//
  [!/* Determine the operating mode configured by the user */!][!//
  [!IF "HsslMemoryAccessConfig/HsslAcessRuleWindow0 = 'NO_ACCESS'"!][!//
    [!VAR "AccessMode" = "'HSSL_NO_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow0 = 'READ'"!][!//
    [!VAR "AccessMode" = "'HSSL_READ_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow0 = 'WRITE'"!][!//
    [!VAR "AccessMode" = "'HSSL_WRITE_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow0 = 'READ_WRITE'"!][!//
    [!VAR "AccessMode" = "'HSSL_READ_WRITE_ACCESS'"!][!//
  [!ENDIF!][!/* ./HsslAcessRuleWindow0 */!][!//

#define HSSL_ACCESS_MODE_0   ([!"$AccessMode"!])[!//
[!//
  [!/* ------ Determine the Access Modes for Memory ----- */!][!//
  [!/* Determine the operating mode configured by the user */!][!//
  [!IF "HsslMemoryAccessConfig/HsslAcessRuleWindow1 = 'NO_ACCESS'"!][!//
    [!VAR "AccessMode" = "'HSSL_NO_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow1 = 'READ'"!][!//
    [!VAR "AccessMode" = "'HSSL_READ_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow1 = 'WRITE'"!][!//
    [!VAR "AccessMode" = "'HSSL_WRITE_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow1 = 'READ_WRITE'"!][!//
    [!VAR "AccessMode" = "'HSSL_READ_WRITE_ACCESS'"!][!//
  [!ENDIF!][!/* ./HsslAcessRuleWindow1 */!][!//

#define HSSL_ACCESS_MODE_1   ([!"$AccessMode"!])[!//
[!//
  [!/* ------ Determine the Access Modes for Memory ----- */!][!//
  [!/* Determine the operating mode configured by the user */!][!//
  [!IF "HsslMemoryAccessConfig/HsslAcessRuleWindow2 ='NO_ACCESS'"!][!//
    [!VAR "AccessMode" = "'HSSL_NO_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow2 = 'READ'"!][!//
    [!VAR "AccessMode" = "'HSSL_READ_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow2 = 'WRITE'"!][!//
    [!VAR "AccessMode" = "'HSSL_WRITE_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow2 = 'READ_WRITE'"!][!//
    [!VAR "AccessMode" = "'HSSL_READ_WRITE_ACCESS'"!][!//
  [!ENDIF!][!/* ./HsslAcessRuleWindow2 */!][!//

#define HSSL_ACCESS_MODE_2   ([!"$AccessMode"!])[!//
[!//
  [!/* ------ Determine the Access Modes for Memory ----- */!][!//
  [!/* Determine the operating mode configured by the user */!][!//
  [!IF "HsslMemoryAccessConfig/HsslAcessRuleWindow3 = 'NO_ACCESS'"!][!//
    [!VAR "AccessMode" = "'HSSL_NO_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow3 = 'READ'"!][!//
    [!VAR "AccessMode" = "'HSSL_READ_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow3 = 'WRITE'"!][!//
    [!VAR "AccessMode" = "'HSSL_WRITE_ACCESS'"!][!//
  [!ELSEIF "HsslMemoryAccessConfig/HsslAcessRuleWindow3 = 'READ_WRITE'"!][!//
    [!VAR "AccessMode" = "'HSSL_READ_WRITE_ACCESS'"!][!//
  [!ENDIF!][!/* ./HsslAcessRuleWindow3 */!][!//

#define HSSL_ACCESS_MODE_3   ([!"$AccessMode"!])[!//

[!/*****************************************************************************
  Macro: CG_ConfigSwitch

  Macro to generate configuration switch Values STD_ON/STD_OFF based on
  configuration true/false

  Input Parameters:
  - nodeval: true/false
*****************************************************************************/!]
[!MACRO "CG_ConfigSwitch", "nodeval" = ""!][!//
[!//
[!IF "$nodeval = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!]
[!ENDMACRO!]

[!IF "(HsslGeneral/HsslRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "HsslGeneral/HsslUserModeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "HsslGeneral/HsslUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: HsslRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
HsslUserModeRuntimeApiEnable or HsslUserModeInitApiEnable
[!ENDASSERT!][!//
[!ENDIF!][!//
/*
Configuration: HSSL_RUNNING_IN_USER_0_MODE_ENABLE
- if STD_ON, enable User0 mode
- if STD_OFF, enable User1 mode
*/
#define HSSL_RUNNING_IN_USER_0_MODE_ENABLE   [!//
[!CALL "CG_ConfigSwitch","nodeval" = "HsslGeneral/HsslRunningInUser0Mode"!][!//

/*
Configuration: HSSL_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API
- if STD_OFF, Enable Supervisor mode in Init API
*/
#define HSSL_USER_MODE_INIT_API_ENABLE         [!//
[!CALL "CG_ConfigSwitch","nodeval" = "HsslGeneral/HsslUserModeInitApiEnable"!][!//

/*
Configuration: HSSL_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
#define HSSL_USER_MODE_RUNTIME_API_ENABLE           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "HsslGeneral/HsslUserModeRuntimeApiEnable"!][!//

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* HSSL_CFG_H */

[!ENDSELECT!][!//