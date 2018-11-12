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
**  $FILENAME   : Dsadc_Cfg.h $                                              **
**                                                                           **
**  $CC VERSION : \main\8 $                                                  **
**                                                                           **
**  $DATE       : 2016-07-29 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Dsadc_Cfg.h file                         **
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
**  FILENAME  : Dsadc_Cfg.h                                                  **
**                                                                           **
**  $CC VERSION : \main\8 $                                                  **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                     **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                         **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : DSADC configuration generated out of ECU configuration    **
**                 file (Dsadc.bmd/.xdm)                                     **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                                                                           **
**  TRACEBILITY :                                                            **
**                                                                           **
******************************************************************************/
#ifndef DSADC_CFG_H
#define DSADC_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//


#define DSADC_MODULE_INSTANCE             ((uint8)0U)

/*SW Version Information*/
#define DSADC_SW_MAJOR_VERSION            ([!"$SwMajorVersion"!]U)
#define DSADC_SW_MINOR_VERSION            ([!"$SwMinorVersion"!]U)
#define DSADC_SW_PATCH_VERSION            ([!"$SwRevisionVersion"!]U)

/*Number of DSADC modules present in the controller*/
#define DSADC_NUM_OF_CHANNELS              ([!"ecu:get('Dsadc.NoOfChannels')"!]U)

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Dsadc')[1]"!][!//
[!//
/* Derived Configuration for DsadcDevErrorDetect */
#define DSADC_DEV_ERROR_DETECT            ([!//
[!IF "DsadcGeneral/DsadcDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration for DsadcVersionInfoApi */
#define DSADC_VERSION_INFO_API            ([!//
[!IF "DsadcGeneral/DsadcVersionInfoApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration for DsadcVersionInfoApi */
#define DSADC_RESET_SFR_INIT            ([!//
[!IF "DsadcGeneral/DsadcResetSfrAtInit = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


/* Derived Configuration for DsadcDeInitApi */
#define DSADC_DEINIT_API                  ([!//
[!IF "DsadcGeneral/DsadcDeInitApi  = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

[!NOCODE!][!//
[!//
[!VAR "TotalDsadcConfig" = "num:i(count(DsadcConfigSet/*))"!][!//
[!/* Determine only one DsadcConfigSet is configured 
                                        when DsadcPBFixedAddress = true.*/!]
[!IF "DsadcGeneral/DsadcPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalDsadcConfig != 1)"!][!//
Config Error: when DsadcGeneral/DsadcPBFixedAddress is set as true, [!//
Only one DsadcConfigSet configuration is allowed. [!//
But DsadcConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/* Derived Configuration DsadcPBFixedAddress*/
#define DSADC_PB_FIXEDADDR                ([!//
[!IF "DsadcGeneral/DsadcPBFixedAddress = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration DsadcDebugSupport*/
#define DSADC_DEBUG_SUPPORT               ([!//
[!IF "DsadcGeneral/DsadcDebugSupport = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*Configuration: DSADC_ENABLE_LIMIT_CHECK
Preprocessor switch for enabling the Limit Check feature. 
- if STD_ON, Limit checking feature of DSADC is Enabled 
- if STD_OFF,Limit checking feature of DSADC is Disabled 
*/
#define DSADC_ENABLE_LIMIT_CHECK          ([!//
[!IF "DsadcGeneral/DsadcEnableLimitCheck = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration DsadcResolverSupport*/
#define DSADC_RESOLVER_SUPPORT            ([!//
[!IF "DsadcGeneral/DsadcResolverSupport = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)




/* Derived Configuration Common mode hold voltage*/
#define DSADC_COMMON_MODE_HOLD_VOLTAGE            ([!//
[!IF "ecu:get('Dsadc.CommonModeHoldVolExits') = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


/* Derived initial configuration registers enabling.
    DSADC_INITIAL_CONFIGURATION is equal to STD_ON if TC27x DA step, 
    TC26x BB step, TC29x BB step */
#define DSADC_INITIAL_CONFIGURATION           ([!//
[!IF "DsadcGeneral/DsadcInitialConfigEnable = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

[!VAR "DsadcDriverName" = "'DsadcConfigSet'"!][!//
[!VAR "TotalConfig" = "num:i(count(node:ref($DsadcDriverName)/*))"!][!//
/* Configuration: Total number of Config Root */
#define DSADC_CONFIG_COUNT  ([!"num:i($TotalConfig)"!]U)

/* Defines number of global common mode hold voltage registers */
#define DSADC_MAX_CMHV_REG  ([!"ecu:get('Dsadc.NoOfCMHVRegisters')"!]U)

[!IF "(DsadcGeneral/DsadcRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "DsadcGeneral/DsadcUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "DsadcGeneral/DsadcUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "DsadcGeneral/DsadcUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: DsadcRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
DsadcUserModeRuntimeApiEnable, DsadcUserModeInitApiEnable or DsadcUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: DSADC_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "DsadcGeneral/DsadcRunningInUser0Mode = 'true'"!][!//
#define DSADC_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define DSADC_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: DSADC_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "DsadcGeneral/DsadcUserModeInitApiEnable = 'true'"!][!//
#define DSADC_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  DSADC_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: DSADC_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "DsadcGeneral/DsadcUserModeDeInitApiEnable = 'true'"!][!//
#define DSADC_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  DSADC_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: DSADC_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "DsadcGeneral/DsadcUserModeRuntimeApiEnable = 'true'"!][!//
#define DSADC_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  DSADC_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/* Mask value for the GLOBCFG and GLOBRC sfrs */
[!IF "ecu:get('Dsadc.NoOfChannels') = num:i(10)"!][!//
#define DSADC_GLOBCFG_SFR_MSK               (0x005FF807U)
#define DSADC_GLOBRC_SFR_MSK                (0x03FF03FFU)
[!ELSEIF "ecu:get('Dsadc.NoOfChannels') = num:i(6)"!][!//
#define DSADC_GLOBCFG_SFR_MSK               (0x005F3807U)
#define DSADC_GLOBRC_SFR_MSK                (0x003F003FU)
[!ELSE!][!//
#define DSADC_GLOBCFG_SFR_MSK               (0x005F0807U)
#define DSADC_GLOBRC_SFR_MSK                (0x000D000DU)
[!ENDIF!][!//

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

#endif  /*End of DSADC_CFG_H */

