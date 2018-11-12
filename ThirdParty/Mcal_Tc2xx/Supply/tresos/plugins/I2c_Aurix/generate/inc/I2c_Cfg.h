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
**  $FILENAME   : I2c_Cfg.h $                                                **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  $DATE       : 2016-07-22 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                Code template for I2c_Cfg.h file                            **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/!][!//
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
**  FILENAME  : I2c_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : I2C configuration generated out of ECU configuration       **
**                 file (I2c.bmd/.xdm)                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEBILITY :                                                             **
**                                                                            **
*******************************************************************************/
[!AUTOSPACING!]
#ifndef I2C_CFG_H
#define I2C_CFG_H

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!//
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!]
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!]
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!]
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!]
[!//
[!IF "$MajorVersion = num:i(4)"!]
#define I2C_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define I2C_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define I2C_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)
[!ENDIF!]

[!//
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!]
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!]
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!]
#define I2C_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define I2C_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define I2C_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)

[!//
[!/* Find the Autosar version number */!][!//
[!IF "$NewString = num:i(402)"!]
  [!VAR "AS_Version" = "num:i(402)"!]
[!ELSEIF "$NewString = num:i(321)"!]
  [!VAR "AS_Version" = "num:i(321)"!]
[!ELSE!][!//
  [!VAR "AS_Version" = "num:i(0)"!]
[!ENDIF!]
[!//
[!/*
MACRO: CG_ConfigSwitch
Macro to generate configuration switch values STD_ON/STD_OFF based on configuration
true/false
*/!][!//
[!MACRO "CG_ConfigSwitch", "node" = ""!]
  [!IF "$node = 'true'"!]
    (STD_ON)
  [!ELSE!]
    (STD_OFF)
  [!ENDIF!]
[!ENDMACRO!]
[!MACRO "CG_ConfigSwitch_Number", "node" = ""!]
  [!IF "$node = '1'"!]
    (STD_ON)
  [!ELSE!]
    (STD_OFF)
  [!ENDIF!]
[!ENDMACRO!]
[!//
#define I2C_DEV_ERROR_DETECT  [!//
[!CALL "CG_ConfigSwitch","node" = "I2cGeneral/I2cDevErrorDetect"!]

#define I2C_VERSION_INFO_API  [!//
[!CALL "CG_ConfigSwitch","node" = "I2cGeneral/I2cVersionInfoApi"!]

#define I2C_HW_STATUS_API  [!//
[!CALL "CG_ConfigSwitch","node" = "I2cGeneral/I2cHwStatusApi"!]

[!IF "node:exists(./I2cGeneral/I2cPBFixedAddress)"!]
#define I2C_PB_FIXEDADDR  [!//
[!CALL "CG_ConfigSwitch","node" = "I2cGeneral/I2cPBFixedAddress"!]
[!ENDIF!]

#define I2C_ASYNC_NOTIFICATION   [!//
[!CALL "CG_ConfigSwitch","node" = "I2cGeneral/I2cAsyncNotification"!]

#define I2C_RESET_SFR_INIT   [!//
[!CALL "CG_ConfigSwitch","node" = "I2cGeneral/I2cResetSfrAtInit"!]

[!IF "(I2cGeneral/I2cRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "I2cGeneral/I2cUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "I2cGeneral/I2cUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "I2cGeneral/I2cUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: I2cRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
I2cUserModeRuntimeApiEnable, I2cUserModeInitApiEnable or I2cUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: I2C_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "I2cGeneral/I2cRunningInUser0Mode = 'true'"!][!//
#define I2C_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define I2C_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: I2C_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "I2cGeneral/I2cUserModeInitApiEnable = 'true'"!][!//
#define I2C_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  I2C_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: I2C_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "I2cGeneral/I2cUserModeDeInitApiEnable = 'true'"!][!//
#define I2C_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  I2C_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: I2C_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "I2cGeneral/I2cUserModeRuntimeApiEnable = 'true'"!][!//
#define I2C_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  I2C_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//

#define I2C_CANCEL_API  [!//
[!CALL "CG_ConfigSwitch","node" = "I2cGeneral/I2cCancelApi"!]


[!VAR "I2cDriverName" = "'I2cDriver'"!]
[!VAR "I2cPacketName" = "'I2cPacket'"!]
[!VAR "I2cDeviceAssignmentName" = "'I2cDeviceAssignment'"!]
[!VAR "I2cExternalDeviceName" = "'I2cExternalDevice'"!]
[!//
[!SELECT "as:modconf('I2c')[1]"!]
  [!VAR "TotalConfig" = "num:i(count(node:ref($I2cDriverName)/*))"!]
[!ENDSELECT!]
[!//
[!/*
Get No of Packets Configured
*/!][!//
[!SELECT "as:modconf('I2c')[1]"!]
  [!VAR "MaxTotalPackets" = "num:i(0)"!]
  [!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!]
    [!SELECT "node:ref($I2cDriverName)/*[@index = num:i($ModuleId - 1)]"!]
      [!VAR "TotalPackets" = "num:i(count(node:ref($I2cPacketName)/*))"!]
      [!IF "$TotalPackets > $MaxTotalPackets"!]
        [!VAR "MaxTotalPackets" = "$TotalPackets"!]
      [!ENDIF!]
    [!ENDSELECT!]
  [!ENDFOR!]
[!ENDSELECT!]
[!//
#define I2C_MAX_PACKET  ([!"num:i($MaxTotalPackets)"!]U)

[!VAR "MaxHwUnits" = "num:i(count(I2cHwConfiguration/*))"!]
[!//
#define I2C_MAX_HW_UNIT  ([!"num:i($MaxHwUnits)"!]U)

[!IF "$MaxHwUnits = num:i(1)"!][!//
#define I2C_I2C0_EXIST  (STD_ON)

#define I2C_I2C1_EXIST  (STD_OFF)
[!ELSE!]
[!IF "$MaxHwUnits = num:i(2)"!][!//
#define I2C_I2C0_EXIST  (STD_ON)

#define I2C_I2C1_EXIST  (STD_ON)
[!ELSE!]
#define I2C_I2C0_EXIST  (STD_OFF)

#define I2C_I2C1_EXIST  (STD_OFF)
[!ENDIF!]
[!ENDIF!]


[!VAR "AsyncUnits" = "num:i(count(I2cHwConfiguration/*[I2cCommunicationType = 'ASYNCHRONOUS']))"!][!//


[!IF "$AsyncUnits = num:i(0)"!][!//
  #define I2C_ASYNC_READ_WRITE   (STD_OFF)
[!ELSE!][!//
  #define I2C_ASYNC_READ_WRITE   (STD_ON)
[!ENDIF!]
[!//


#define I2C_CONFIG_COUNT  ([!"num:i($TotalConfig)"!]U)

#define I2C_MAX_QUEUE   ([!"num:i($AsyncUnits)"!]U)

#define I2C_CLOCK_CTRL_1_SLEEP_DIS   (0x00000108U)

#define I2C_CLOCK_CTRL_1_SLEEP_EN    (0x00000100U)

#endif  /* I2C_CFG_H */

