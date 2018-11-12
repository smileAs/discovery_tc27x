[!/****************************************************************************
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
**  $FILENAME   : Msc_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\21 $                                                 **
**                                                                           **
**  $DATE       : 2016-06-17 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Msc_Cfg.h file                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
[!//
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
**  FILENAME  : Msc_Cfg.h                                                    **
**                                                                           **
**  $CC VERSION : \main\21 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : MSC configuration generated out of ECU configuration      **
**                 file (Msc.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                                                                           **
    TRACEBILITY :[cover parentID = DS_NAS_MSC_PR446,SAS_NAS_MSC_PR1071,
    SAS_NAS_MSC_PR914,SAS_NAS_MSC_PR915,SAS_NAS_MSC_PR916,SAS_NAS_MSC_PR60,
    SAS_NAS_MSC_PR64,SAS_NAS_MSC_PR82,DS_NAS_HE2_MSC_PR3054_1,
    DS_NAS_HE2_MSC_PR3054_2,DS_NAS_HE2_MSC_PR3054_3,DS_NAS_HE2_MSC_PR3054_4]
    [/cover]                               **
**                                                                           **
******************************************************************************/
#ifndef MSC_CFG_H 
#define MSC_CFG_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//

/* Module ID and Vendor ID moved to Msc.h.*/
#define MSC_MODULE_INSTANCE             ((uint8)0U)

/*SW Version Information*/
#define MSC_SW_MAJOR_VERSION            ([!"$SwMajorVersion"!]U)
#define MSC_SW_MINOR_VERSION            ([!"$SwMinorVersion"!]U)
#define MSC_SW_PATCH_VERSION            ([!"$SwRevisionVersion"!]U)

/*Number of MSC modules present in the controller*/
#define MSC_NUM_OF_MODULES              ([!"ecu:get('Msc.NoOfModules')"!]U)

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Msc')[1]"!][!//
[!//
/* Total No of Config Sets */
#define MSC_CONFIG_COUNT                ([!"num:i(count(MscConfigSet/*))"!]U)

/* Derived Configuration for MscDevErrorDetect */
#define MSC_DEV_ERROR_DETECT            ([!//
[!IF "MscGeneral/MscDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: Msc_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "node:exists(./MscGeneral/MscRunningInUser0Mode)"!][!//
  [!IF "MscGeneral/MscRunningInUser0Mode = 'true'"!][!//
  [!ASSERT "not((./MscGeneral/MscUserModeInitApiEnable != 'true') and (./MscGeneral/MscUserModeDeInitApiEnable != 'true') and (./MscGeneral/MscUserModeRuntimeApiEnable != 'true'))"!][!//
Config Error: when MscGeneral/MscRunningInUser0Mode is set as true, [!//
Then atleast any one of the switches: MscUserModeInitApiEnable or [!//
MscUserModeDeInitApiEnable or MscUserModeRuntimeApiEnable should be selected.[!//
But in configuration none are selected.[!//
  [!ENDASSERT!][!//
#define MSC_RUNNING_IN_USER_0_MODE_ENABLE    (STD_ON)
  [!ELSE!][!//
#define MSC_RUNNING_IN_USER_0_MODE_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define MSC_RUNNING_IN_USER_0_MODE_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: Msc_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "node:exists(./MscGeneral/MscUserModeInitApiEnable)"!][!//
  [!IF "MscGeneral/MscUserModeInitApiEnable = 'true'"!][!// 
#define MSC_USER_MODE_INIT_API_ENABLE    (STD_ON)
  [!ELSE!][!//
#define MSC_USER_MODE_INIT_API_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define MSC_USER_MODE_INIT_API_ENABLE    (STD_OFF)
[!ENDIF!][!//
/*
Configuration: Msc_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in DeInit API 
- if STD_OFF, Enable Supervisor mode in DeInit API 
*/
[!IF "node:exists(./MscGeneral/MscUserModeDeInitApiEnable)"!][!//
  [!IF "MscGeneral/MscUserModeDeInitApiEnable = 'true'"!][!// 
#define MSC_USER_MODE_DEINIT_API_ENABLE    (STD_ON)
  [!ELSE!][!//
#define MSC_USER_MODE_DEINIT_API_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define MSC_USER_MODE_DEINIT_API_ENABLE    (STD_OFF)
[!ENDIF!][!//
/*
Configuration: Msc_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
[!IF "node:exists(./MscGeneral/MscUserModeRuntimeApiEnable)"!][!//
  [!IF "MscGeneral/MscUserModeRuntimeApiEnable = 'true'"!][!//    
#define MSC_USER_MODE_RUNTIME_API_ENABLE    (STD_ON)
  [!ELSE!][!//
#define MSC_USER_MODE_RUNTIME_API_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define MSC_USER_MODE_RUNTIME_API_ENABLE    (STD_OFF)
[!ENDIF!][!//

/* Derived Configuration for MscVersionInfoApi */
#define MSC_VERSION_INFO_API            ([!//
[!IF "MscGeneral/MscVersionInfoApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration for MscPassiveFrameCounterApi */
#define MSC_PASSIVE_TIME_FRAME_API      ([!//
[!IF "MscGeneral/MscPassiveFrameCounterApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration for MscDeInitApi */
#define MSC_DEINIT_API                  ([!//
[!IF "MscGeneral/MscDeInitApi  = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration MscEmergencyDataApi*/
#define MSC_EMERGENCY_DATA_API          ([!//
[!IF "MscGeneral/MscEmergencyDataApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration MscDebugSupport*/
#define MSC_DEBUG_SUPPORT               ([!//
[!IF "MscGeneral/MscDebugSupport = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!NOCODE!][!//
[!//
[!VAR "TotalMscConfig" = "num:i(count(MscConfigSet/*))"!][!//
[!/* Determine only one MscConfigSet is configured 
                                        when MscPBFixedAddress = true.*/!]

[!IF "MscGeneral/MscPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalMscConfig != 1)"!][!//
Config Error: when MscGeneral/MscPBFixedAddress is set as true, [!//
Only one MscConfigSet configuration is allowed. [!//
But MscConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/* Derived Configuration MscPBFixedAddress*/
#define MSC_PB_FIXEDADDR                ([!//
[!IF "MscGeneral/MscPBFixedAddress = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration MscResetSfrAtInit*/
#define MSC_RESET_SFR_INIT              ([!//
[!IF "MscGeneral/MscResetSfrAtInit = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

[!ENDSELECT!][!//

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif  /*End of MSC_CFG_H */


