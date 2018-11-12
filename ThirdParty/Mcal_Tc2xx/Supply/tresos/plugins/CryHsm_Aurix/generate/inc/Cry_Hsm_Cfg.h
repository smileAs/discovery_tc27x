[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Cry_Hsm_Cfg.h $                                            **
**                                                                           **
**  $CC VERSION : $                                                          **
**                                                                           **
**  $DATE       : 2015-06-10 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Cry_Hsm_Cfg.h file                      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=   
] [/cover]                                          */!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Cry_Hsm_Cfg.h                                                 **
**                                                                            **
**  $CC VERSION : \main\74 $                                                  **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains functionality of Cry module             **
**                 and can be modified via GUI                                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

#ifndef CRY_HSM_CFG_H
#define CRY_HSM_CFG_H

[!/* Include Code Generator Macros */!][!//
[!NOCODE!][!//
[!INCLUDE "..\Cry_Hsm.m"!][!//
[!//
[!ENDNOCODE!]
[!SELECT "as:modconf('CryHsm')[1]"!][!//
/*******************************************************************************
**                                                                            **
**  TRACEABILITY : [cover parentID=] [/cover]                                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
[!SELECT "CryHsmGeneral"!][!//

[!VAR "WhiteSpaceInCryHsmUserTimerFileName"="normalize-space(CryHsmUserTimerFileName)"!][!//
[!IF "(string-length($WhiteSpaceInCryHsmUserTimerFileName)>0) and (CryHsmUserTimerFileName  !='NULL_PTR') and (CryHsmUserTimerFileName  !='NULL')"!][!//
/*
Configuration: CRY_HSM_USER_TIMER_FILE_NAME
User specified user timer 
*/
#include "[!"CryHsmUserTimerFileName"!].h"

[!ENDIF!][!//
[!//
[!//
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
Configuration: CRY_HSM_TRIGGERED_INIT
- STD_ON  : The HSM init is triggered from TriCore
- STD_OFF : The HSM init is performed independently from any TriCore trigger
*/
/* Traceability    : [$Satisfies $CDS_CDRV 430]                               */
#define CRY_HSM_TRIGGERED_INIT              [!//
[!CALL "CG_ConfigSwitch","node" = "CryHsmTriggeredInit"!]

/*
Configuration: CRY_HSM_USE_SYNC_INIT
- STD_ON  : The HSM init is triggered in synchronous mode
- STD_OFF : The HSM init is triggered in asynchronous mode
*/
/* Traceability    : [$Satisfies $CDS_CDRV 592]                               */
#define CRY_HSM_USE_SYNC_INIT              [!//
[!CALL "CG_ConfigSwitch","node" = "CryHsmUseSyncInit"!]

/*
Configuration: CRY_HSM_MAC_SAFE_VERIFY
Pre-processor switch to implement all safety measures described by safety
concept
- STD_ON  : The MAC verify is performed to support safety
- STD_OFF : The MAC verify is QM
*/
/* Traceability    : [$Satisfies $CDS_CDRV 431]                               */
#define CRY_HSM_MAC_SAFE_VERIFY             [!//
[!CALL "CG_ConfigSwitch","node" = "CryHsmMacSafeVerify"!]

/*
Configuration: CRY_HSM_SECURE_BOOT
Pre-processor switch to enable and disable secure boot
- STD_ON  : The HSM Secure Boot is enabled
- STD_OFF : The HSM Secure Boot is disabled
*/
/* Traceability    : [$Satisfies $CDS_CDRV 432]                               */
#define CRY_HSM_SECURE_BOOT                [!//
[!CALL "CG_ConfigSwitch","node" = "CryHsmSecureBoot"!]

/*
Configuration: CRY_HSM_USER_TIMEOUT_API
Pre-processor switch to implement the interfaces for timeout calculation.
- STD_ON  : The user defined timeout interfaces used
- STD_OFF : The AUTOSAR Gpt timeout Interfaces used
*/
/* Traceability    : [$Satisfies $CDS_CDRV 433]  [$Satisfies $CDS_CDRV 580]   */
#define CRY_HSM_USER_TIMEOUT_API           [!//
[!CALL "CG_ConfigSwitch","node" = "CryHsmUserTimeoutApi"!]

[!VAR "WhiteSpaceInStartTimerApiName"="normalize-space(CryHsmUserStartTimerApiName)"!][!//
[!IF "(string-length($WhiteSpaceInStartTimerApiName)>0) and (CryHsmUserStartTimerApiName!='NULL_PTR') and (CryHsmUserStartTimerApiName!='NULL')"!][!//

/*
Configuration: CRY_HSM_USER_START_TIMER_API_NAME
User specified start timer API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 434]                               */
#define CRY_HSM_USER_START_TIMER_API_NAME   [!"CryHsmUserStartTimerApiName"!]

[!ENDIF!][!//
[!//
[!//
[!VAR "WhiteSpaceInCryHsmUserDeltaTimerApiName"="normalize-space(CryHsmUserStartTimerApiName)"!][!//
[!IF "(string-length($WhiteSpaceInCryHsmUserDeltaTimerApiName)>0) and (CryHsmUserDeltaTimerApiName  !='NULL_PTR') and (CryHsmUserDeltaTimerApiName  !='NULL')"!][!//

/*
Configuration: CRY_HSM_USER_DELTA_TIMER_API_NAME
User specified elapsed time API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 435]                               */
#define CRY_HSM_USER_DELTA_TIMER_API_NAME   [!"CryHsmUserDeltaTimerApiName  "!]

[!ENDIF!][!//
[!//
[!//
[!VAR "WhiteSpaceInCryHsmUserStopTimerApiName"="normalize-space(CryHsmUserStopTimerApiName)"!][!//
[!IF "(string-length($WhiteSpaceInCryHsmUserStopTimerApiName)>0) and (CryHsmUserStopTimerApiName  !='NULL_PTR') and (CryHsmUserStopTimerApiName  !='NULL')"!][!//

/*
Configuration: CRY_HSM_USER_STOP_TIMER_API_NAME
User specified stop timer API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 436]                               */
#define CRY_HSM_USER_STOP_TIMER_API_NAME    [!"CryHsmUserStopTimerApiName  "!]

[!ENDIF!][!//
[!//
[!//
                    
/*
Configuration: CRY_HSM_TICK_COUNT_VALUE
Tick count for one micro second used in CRY_CONVERT_USEC_TO_TIMER_TICK
function for converting specified value from micro second to timer ticks
*/
/* Traceability    : [$Satisfies $CDS_CDRV 437]                               */
#define CRY_HSM_TICK_COUNT_VALUE                      ([!//
[!"num:f(node:value(CryHsmTickCountValue  ))"!])

/*
Configuration: CRY_HSM_BSWM_ERROR_NOTIFICATION
Pre-processor switch to enable and disable BswM module error reporting
BswM_RequestMode interface.
- STD_ON  : SHE error reported to BswM module
- STD_OFF : SHE error not reported to BswM module
*/
/* Traceability    : [$Satisfies $CDS_CDRV 438] [$Satisfies $CDS_CDRV 576]    */
#define CRY_HSM_BSWM_ERROR_NOTIFICATION               [!//
[!CALL "CG_ConfigSwitch","node" = "CryHsmBswMErrorNotification"!]

/* Timeout value for CryHsmInit function
Timeout in micro seconds, after which the Cry_HsmInit API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 439]                               */
#define CRY_HSM_INIT_TIMEOUT                                     ([!//
[!"num:i(node:value(CryHsmInitTimeout ))"!]U)

/* Timeout value for Cry_HsmRandomSeedInit start function
Timeout in micro seconds, after which the Cry_HsmRandomSeedInitStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 440]                               */
#define CRY_HSM_RND_SEED_INIT_START_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmRndSeedInitStartTimeout ))"!]U)

/* Timeout value for Cry_HsmRandomSeedInit update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmRandomSeedInitUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 441]                               */
#define CRY_HSM_RND_SEED_INIT_UPDATE_TIMEOUT                      ([!//
[!"num:i(node:value(CryHsmRndSeedInitUpdateTimeout  ))"!]U)

/* Timeout value for Cry_HsmRandomSeedInit update function.
Timeout in micro seconds, which is variable part for 
Cry_HsmRandomSeedInitUpdate. After elapsed the time of 
((CryHsmRandomSeedInitUpdateTimeout) +(No of Bytes * 
CryHsmRndSeedInitPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmRandomSeedInitUpdate API stops and returns CSM_E_NOT_OK.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 442]                               */
#define CRY_HSM_RND_SEED_INIT_PER_BYTE_UPDATE_TIMEOUT             ([!//
[!"num:i(node:value(CryHsmRndSeedInitPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmRandomSeedInit Finish function
Timeout in micro seconds, after which the Cry_HsmRandomSeedInitFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 443]                               */
#define CRY_HSM_RND_SEED_INIT_FINISH_TIMEOUT                      ([!//
[!"num:i(node:value(CryHsmRndSeedInitFinishTimeout   ))"!]U)

/* Timeout value for Cry_HsmRandomSeedExtend start function
Timeout in micro seconds, after which the Cry_HsmRandomSeedExtendStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 444]                               */
#define CRY_HSM_RND_SEED_EXTEND_START_TIMEOUT                     ([!//
[!"num:i(node:value(CryHsmRndSeedExtendStartTimeout    ))"!]U)

/* Timeout value for Cry_HsmRandomSeedExtend update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmRndSeedExtendUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 445]                               */
#define CRY_HSM_RND_SEED_EXTEND_UPDATE_TIMEOUT                   ([!//
[!"num:i(node:value(CryHsmRndSeedExtendUpdateTimeout   ))"!]U)

/* Timeout value for Cry_HsmRandomSeedExtend update function
Timeout in micro seconds, which is variable part for
Cry_HsmRandomSeedExtendUpdate.After elapsed the time of 
((CryHsmRandomSeedExtendUpdateTimeout) +
(No of Bytes * CryHsmRndSeedExtendPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmRandomSeedExtendUpdate API stops and returns CSM_E_NOT_OK.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 446]                               */
#define CRY_HSM_RND_SEED_EXTEND_PER_BYTE_UPDATE_TIMEOUT           ([!//
[!"num:i(node:value(CryHsmRndSeedExtendPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmRandomSeedExtend finish function
Timeout in micro seconds, after which the Cry_HsmRandomSeedExtendFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 447]                               */
#define CRY_HSM_RND_SEED_EXTEND_FINISH_TIMEOUT                    ([!//
[!"num:i(node:value(CryHsmRndSeedExtendFinishTimeout ))"!]U)

/* Timeout value for Cry_HsmRandomGenerate start
   Not applicable in present software
*/
/* Traceability    : [$Satisfies $CDS_CDRV 448]                               */
#define CRY_HSM_RND_GENERATE_START_TIMEOUT                        ([!//
[!"num:i(node:value(CryHsmRndGenerateStartTimeout  ))"!]U)

/* Timeout value for Cry_HsmRandomGenerate update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmRandomGenerateUpdate timeout
*/
/* Traceability    : [$Satisfies $CDS_CDRV 449]                               */
#define CRY_HSM_RND_GENERATE_UPDATE_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmRndGenerateUpdateTimeout   ))"!]U)

/* Timeout value for Cry_HsmRandomGenerate update function
Timeout in micro seconds, which is variable part for 
Cry_HsmRandomGenerateUpdate. After elapsed the time of 
((CryHsmRndGenerateUpdateTimeout) +(No of Bytes * 
CryHsmRndGeneratePerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmRandomGenerateUpdate API stops and returns CSM_E_NOT_OK.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 450]                               */
#define CRY_HSM_RND_GENERATE_PER_BYTE_UPDATE_TIMEOUT              ([!//
[!"num:i(node:value(CryHsmRndGeneratePerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmRandomGenerate finish
   Not applicable in present software
*/
/* Traceability    : [$Satisfies $CDS_CDRV 451]                               */
#define CRY_HSM_RND_GENERATE_FINISH_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmRndGenerateFinishTimeout ))"!]U)

/* Timeout value for CryHsmDebugStart
   Not applicable in present software
*/
/* Traceability    : [$Satisfies $CDS_CDRV 632]                               */
#define CRY_HSM_DEBUG_START_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmDebugStartTimeout ))"!]U)

/* Timeout value for CryHsmDebugFinish 
   Not applicable in present software
*/
/* Traceability    : [$Satisfies $CDS_CDRV 633]                               */
#define CRY_HSM_DEBUG_FINISH_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmDebugFinishTimeout ))"!]U)

/* Timeout value for CryHsmGetUid
   Not applicable in present software
*/
/* Traceability    : [$Satisfies $CDS_CDRV 640]                               */
#define CRY_HSM_GET_UID_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmGetUidTimeout ))"!]U)

/* Timeout in micro seconds, after time elapsed of 
(CryHsmTrueRndGenerateStartTimeout * SAFETY_FACTOR) 
Cry_HsmTrueRandomGenerateStart API stops and returns CSM_E_NOT_OK.
Not applicable in present software
*/
/* Traceability    : [$Satisfies $CDS_CDRV 641]                               */
#define CRY_HSM_TRUE_RND_GENERATE_START_TIMEOUT                   ([!//
[!"num:i(node:value(CryHsmTrueRndGenerateStartTimeout  ))"!]U)

/* Timeout in micro seconds, which is the constant part for  
Cry_HsmTrueRandomGenerateUpdate API
*/
/* Traceability    : [$Satisfies $CDS_CDRV 642]                               */
#define CRY_HSM_TRUE_RND_GENERATE_UPDATE_TIMEOUT                  ([!//
[!"num:i(node:value(CryHsmTrueRndGenerateUpdateTimeout   ))"!]U)

/*Timeout in micro seconds, which is variable part for 
Cry_HsmTrueRandomGenerateUpdate API. After elapsed the time of 
((CryHsmTrueRndGenerateUpdateTimeout) +
(No of Bytes * CryHsmTrueRndGeneratePerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmRandomGenerateUpdate API stops and returns CSM_E_NOT_OK.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 643]                               */
#define CRY_HSM_TRUE_RND_GENERATE_PER_BYTE_UPDATE_TIMEOUT         ([!//
[!"num:i(node:value(CryHsmTrueRndGeneratePerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmTrueRandomGenerate finish
   Not applicable in present software
*/
/* Traceability    : [$Satisfies $CDS_CDRV 644]                               */
#define CRY_HSM_TRUE_RND_GENERATE_FINISH_TIMEOUT                  ([!//
[!"num:i(node:value(CryHsmTrueRndGenerateFinishTimeout ))"!]U)

/* Timeout value for Cry_HsmAesEcbEncrypt start function
Timeout in micro seconds, after which the Cry_HsmAesEcbEncryptStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 452]                               */
#define CRY_HSM_AES_ECB_ENCRYPT_START_TIMEOUT                        ([!//
[!"num:i(node:value(CryHsmAesEcbEncryptStartTimeout  ))"!]U)

/* Timeout value for Cry_HsmAesEcbEncrypt update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmAesEcbEncryptUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 453]                               */
#define CRY_HSM_AES_ECB_ENCRYPT_UPDATE_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmAesEcbEncryptUpdateTimeout ))"!]U)

/* Timeout value for Cry_HsmAesEcbEncrypt update function
Timeout in micro seconds, which is variable part for 
Cry_HsmAesEcbEncryptUpdate. After elapsed the time of 
((CryHsmAesEcbEncryptUpdateTimeout) +(No of Bytes * 
CryHsmAesEcbEncryptPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmAesEcbEncryptUpdate API stops and returns CSM_E_NOT_OK. 
*/
/* Traceability    : [$Satisfies $CDS_CDRV 454]                               */
#define CRY_HSM_AES_ECB_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT              ([!//
[!"num:i(node:value(CryHsmAesEcbEncryptPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesEcbEncrypt finish function
Timeout in micro seconds, after which the Cry_HsmAesEcbEncryptFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 455]                               */
#define CRY_HSM_AES_ECB_ENCRYPT_FINISH_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmAesEcbEncryptFinishTimeout))"!]U)

/* Timeout value for Cry_HsmAesEcbDecrypt start function
Timeout in micro seconds, after which the Cry_HsmAesEcbDecryptStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 456]                               */
#define CRY_HSM_AES_ECB_DECRYPT_START_TIMEOUT                        ([!//
[!"num:i(node:value(CryHsmAesEcbDecryptStartTimeout))"!]U)

/* Timeout value for Cry_HsmAesEcbDecrypt update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmAesEcbDecryptUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 457]                               */
#define CRY_HSM_AES_ECB_DECRYPT_UPDATE_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmAesEcbDecryptUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesEcbDecrypt update function
Timeout in micro seconds, which is variable part for 
Cry_HsmAesEcbDecryptUpdate.After elapsed the time of 
((CryHsmAesEcbDecryptUpdateTimeout) +
(No of Bytes * CryHsmAesEcbDecryptPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmAesEcbDecryptUpdate API stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 458]                               */
#define CRY_HSM_AES_ECB_DECRYPT_PER_BYTE_UPDATE_TIMEOUT              ([!//
[!"num:i(node:value(CryHsmAesEcbDecryptPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesEcbDecrypt finish function
Timeout in micro seconds, after which the Cry_HsmAesEcbDecryptFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 459]                               */
#define CRY_HSM_AES_ECB_DECRYPT_FINISH_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmAesEcbDecryptFinishTimeout))"!]U)

/* Timeout value for Cry_HsmAesEncrypt start function
Timeout in micro seconds, after which the Cry_HsmAesEncryptStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 460]                               */
#define CRY_HSM_AES_ENCRYPT_START_TIMEOUT                            ([!//
[!"num:i(node:value(CryHsmAesEncryptStartTimeout))"!]U)

/* Timeout value for Cry_HsmAesEncrypt update function
Timeout in micro seconds, which is the constant part for
Cry_HsmAesEncryptUpdate timeout
*/
/* Traceability    : [$Satisfies $CDS_CDRV 461]                               */
#define CRY_HSM_AES_ENCRYPT_UPDATE_TIMEOUT                           ([!//
[!"num:i(node:value(CryHsmAesEncryptUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesEncrypt update function
Timeout in micro seconds, which is variable part for Cry_HsmAesEncryptUpdate.
After elapsed the time of ((CryHsmAesEncryptUpdateTimeout) +
(No of Bytes * CryHsmAesEncryptPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmAesEncryptUpdate API stops and returns CSM_E_NOT_OK. 
*/
/* Traceability    : [$Satisfies $CDS_CDRV 462]                               */
#define CRY_HSM_AES_ENCRYPT_PER_BYTE_UPDATE_TIMEOUT                  ([!//
[!"num:i(node:value(CryHsmAesEncryptPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesEncrypt finish function
Timeout in micro seconds, after which the Cry_HsmAesEncryptFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 463]                               */
#define CRY_HSM_AES_ENCRYPT_FINISH_TIMEOUT                           ([!//
[!"num:i(node:value(CryHsmAesEncryptFinishTimeout))"!]U)

/* Timeout value for Cry_HsmAesDecrypt start function
Timeout in micro seconds, after which the Cry_HsmAesDecryptStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 464]                               */
#define CRY_HSM_AES_DECRYPT_START_TIMEOUT                            ([!//
[!"num:i(node:value(CryHsmAesDecryptStartTimeout))"!]U)

/* Timeout value for Cry_HsmAesDecrypt update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmAesDecryptUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 465]                               */
#define CRY_HSM_AES_DECRYPT_UPDATE_TIMEOUT                           ([!//
[!"num:i(node:value(CryHsmAesDecryptUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesDecrypt update function
Timeout in micro seconds, which is variable part for Cry_HsmAesDecryptUpdate.
After elapsed the time of ((CryHsmAesDecryptUpdateTimeout) +
(No of Bytes * CryHsmAesDecryptPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmAesDecryptUpdate API stops and returns CSM_E_NOT_OK. 
*/
/* Traceability    : [$Satisfies $CDS_CDRV 466]                               */
#define CRY_HSM_AES_DECRYPT_PER_BYTE_UPDATE_TIMEOUT                  ([!//
[!"num:i(node:value(CryHsmAesDecryptPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesDecrypt finish function
Timeout in micro seconds, after which the Cry_HsmAesDecryptFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 467]                               */
#define CRY_HSM_AES_DECRYPT_FINISH_TIMEOUT                           ([!//
[!"num:i(node:value(CryHsmAesDecryptFinishTimeout))"!]U)

/* Timeout value for Cry_HsmAesCmacGenerate start function
Timeout in micro seconds, after which the Cry_HsmAesCmacGenerateStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 468]                               */
#define CRY_HSM_AES_CMAC_GENERATE_START_TIMEOUT                      ([!//
[!"num:i(node:value(CryHsmAesCmacGenerateStartTimeout))"!]U)

/* Timeout value for Cry_HsmAesCmacGenerate update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmAesCMacGenerateUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 469]                               */
#define CRY_HSM_AES_CMAC_GENERATE_UPDATE_TIMEOUT                     ([!//
[!"num:i(node:value(CryHsmAesCmacGenerateUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesCmacGenerate update function
Timeout in micro seconds, which is variable part for 
Cry_HsmAesCMacGenerateUpdate. After elapsed the time of 
((CryHsmAesCmacGenerateUpdateTimeout) +(No of Bytes * 
CryHsmAesCmacGeneratePerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmAesCMacGenerateUpdate API stops and returns CSM_E_NOT_OK.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 470]                               */
#define CRY_HSM_AES_CMAC_GENERATE_PER_BYTE_UPDATE_TIMEOUT            ([!//
[!"num:i(node:value(CryHsmAesCmacGeneratePerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesCmacGenerate finish function
Timeout in micro seconds, after which the Cry_HsmAesCmacGenerateFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 471]                               */
#define CRY_HSM_AES_CMAC_GENERATE_FINISH_TIMEOUT                     ([!//
[!"num:i(node:value(CryHsmAesCmacGenerateFinishTimeout))"!]U)

/* Timeout value for Cry_HsmAesCmacVerify start function
Timeout in micro seconds, after which the Cry_HsmAesCmacVerifyStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 472]                               */
#define CRY_HSM_AES_CMAC_VERIFY_START_TIMEOUT                        ([!//
[!"num:i(node:value(CryHsmAesCmacVerifyStartTimeout))"!]U)

/* Timeout value for Cry_HsmAesCmacVerify update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmAesCMacVerifyUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 473]                               */
#define CRY_HSM_AES_CMAC_VERIFY_UPDATE_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmAesCmacVerifyUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesCmacVerify update function
which is the variable part for Cry_HsmAesCmacVerifyUpdate timeout
After the elapsed time of ((CryHsmAesCmacVerifyUpdateTimeout) +
(No of Bytes * CryHsmAesCmacVerifyPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmAesCmacVerifyUpdate API stops and returns CSM_E_NOT_OK.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 474]                               */
#define CRY_HSM_AES_CMAC_VERIFY_PER_BYTE_UPDATE_TIMEOUT              ([!//
[!"num:i(node:value(CryHsmAesCmacVerifyPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmAesCmacVerify finish function
Timeout in micro seconds, after which the Cry_HsmAesCmacVerifyFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 475]                               */
#define CRY_HSM_AES_CMAC_VERIFY_FINISH_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmAesCmacVerifyFinishTimeout))"!]U)

/* Timeout value for Cry_HsmKeyLoad start function
Timeout in micro seconds, after which the Cry_HsmKeyLoadStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 476]                               */
#define CRY_HSM_KEY_LOAD_START_TIMEOUT                               ([!//
[!"num:i(node:value(CryHsmKeyLoadStartTimeout))"!]U)

/* Timeout value for Cry_HsmKeyLoad update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmKeyLoadUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 477]                               */
#define CRY_HSM_KEY_LOAD_UPDATE_TIMEOUT                              ([!//
[!"num:i(node:value(CryHsmKeyLoadUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmKeyLoad update function
Timeout in micro seconds, which is variable part for 
Cry_HsmKeyLoadUpdate. After elapsed the time of 
((CryHsmKeyLoadUpdateTimeout) +(No of Bytes * 
CryHsmKeyLoadPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmKeyLoadUpdate API stops and returns CSM_E_NOT_OK. 
*/
/* Traceability    : [$Satisfies $CDS_CDRV 478]                               */
#define CRY_HSM_KEY_LOAD_PER_BYTE_UPDATE_TIMEOUT                     ([!//
[!"num:i(node:value(CryHsmKeyLoadPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmKeyLoad finish function
Timeout in micro seconds, after which the Cry_HsmKeyLoadFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 479]                               */
#define CRY_HSM_KEY_LOAD_FINISH_TIMEOUT                              ([!//
[!"num:i(node:value(CryHsmKeyLoadFinishTimeout))"!]U)

/* Timeout value for Cry_HsmKeyLoadPlain start function
Timeout in micro seconds, after which the Cry_HsmKeyLoadPlainStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 480]                               */
#define CRY_HSM_KEY_LOAD_PLAIN_START_TIMEOUT                         ([!//
[!"num:i(node:value(CryHsmKeyLoadPlainStartTimeout))"!]U)

/* Timeout value for Cry_HsmKeyLoadPlain update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmKeyLoadPlainUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 481]                               */
#define CRY_HSM_KEY_LOAD_PLAIN_UPDATE_TIMEOUT                        ([!//
[!"num:i(node:value(CryHsmKeyLoadPlainUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmKeyLoadPlain update function
Timeout in micro seconds, which is variable part for 
Cry_HsmKeyLoadPlainUpdate. After elapsed the time of 
((CryHsmKeyLoadPlainUpdateTimeout) +(No of Bytes * 
CryHsmKeyLoadPlainPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmKeyLoadPlainUpdate API stops and returns CSM_E_NOT_OK. 
*/
/* Traceability    : [$Satisfies $CDS_CDRV 482]                               */
#define CRY_HSM_KEY_LOAD_PLAIN_PER_BYTE_UPDATE_TIMEOUT               ([!//
[!"num:i(node:value(CryHsmKeyLoadPlainPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmKeyLoadPlain finish function
Timeout in micro seconds, after which the Cry_HsmKeyLoadPlainFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 483]                               */
#define CRY_HSM_KEY_LOAD_PLAIN_FINISH_TIMEOUT                        ([!//
[!"num:i(node:value(CryHsmKeyLoadPlainFinishTimeout))"!]U)

/* Timeout value for loading the RAM key for Cry_HsmKeyLoad Start function
Timeout in micro seconds, after which the Cry_HsmKeyLoadStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 484]                               */
#define CRY_HSM_KEY_LOAD_RAMKEY_START_TIMEOUT                        ([!//
[!"num:i(node:value(CryHsmKeyLoadRamKeyStartTimeout))"!]U)

/* Timeout value for loading the RAM key for Cry_HsmKeyLoad update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmKeyLoadUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 485]                               */
#define CRY_HSM_KEY_LOAD_RAMKEY_UPDATE_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmKeyLoadRamKeyUpdateTimeout))"!]U)

/* Timeout value for loading the RAM key for Cry_HsmKeyLoad update function
Timeout in micro seconds, which is variable part for Cry_HsmKeyLoadUpdate.
After elapsed the time of ((CryHsmKeyLoadRamKeyUpdateTimeout) +
(No of Bytes * CryHsmKeyLoadRamKeyPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmKeyLoadUpdate API stops and returns CSM_E_NOT_OK.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 486]                               */
#define CRY_HSM_KEY_LOAD_RAMKEY_PER_BYTE_UPDATE_TIMEOUT              ([!//
[!"num:i(node:value(CryHsmKeyLoadRamKeyPerByteUpdateTimeout))"!]U)

/* Timeout value for loading the RAM key for Cry_HsmKeyLoad finish function
Timeout in micro seconds, after which the Cry_HsmKeyLoadFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 487]                               */
#define CRY_HSM_KEY_LOAD_RAMKEY_FINISH_TIMEOUT                       ([!//
[!"num:i(node:value(CryHsmKeyLoadRamKeyFinishTimeout))"!]U)

/* Timeout value for Cry_HsmKeyExport start function
Timeout in micro seconds, after which the Cry_HsmKeyExportStart API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 488]                               */
#define CRY_HSM_KEY_EXPORT_START_TIMEOUT                             ([!//
[!"num:i(node:value(CryHsmKeyExportStartTimeout))"!]U)

/* Timeout value for Cry_HsmKeyExport update function
Timeout in micro seconds, which is the constant part for 
Cry_HsmKeyExportUpdate timeout.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 489]                               */
#define CRY_HSM_KEY_EXPORT_UPDATE_TIMEOUT                            ([!//
[!"num:i(node:value(CryHsmKeyExportUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmKeyExport update function
Timeout in micro seconds, which is variable part for Cry_HsmKeyExportUpdate. 
After elapsed the time of ((CryHsmKeyExportUpdateTimeout) +(No of Bytes *
CryHsmKeyExportPerByteUpdateTimeout))*SAFTEY_FACTOR 
Cry_HsmKeyExportUpdate API stops and returns CSM_E_NOT_OK.
*/
/* Traceability    : [$Satisfies $CDS_CDRV 490]                               */
#define CRY_HSM_KEY_EXPORT_PER_BYTE_UPDATE_TIMEOUT                   ([!//
[!"num:i(node:value(CryHsmKeyExportPerByteUpdateTimeout))"!]U)

/* Timeout value for Cry_HsmKeyExport finish function
Timeout in micro seconds, after which the Cry_HsmKeyExportFinish API
stops and returns CSM_E_NOT_OK
*/
/* Traceability    : [$Satisfies $CDS_CDRV 491]                               */
#define CRY_HSM_KEY_EXPORT_FINISH_TIMEOUT                            ([!//
[!"num:i(node:value(CryHsmKeyExportFinishTimeout))"!]U)

/* Service ID for Cry_HsmAesCMacGenerateStart API  */
/* Traceability    : [$Satisfies $CDS_CDRV 492]                               */
#define CRY_HSM_SID_MAC_GENERATE_START                               ([!//
[!"num:i(node:value(CryHsmSidMacGenerateStart))"!]U)

/* Service ID for Cry_HsmMacGenerateUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 493]*/
#define CRY_HSM_SID_MAC_GENERATE_UPDATE                              ([!//
[!"num:i(node:value(CryHsmSidMacGenerateUpdate))"!]U)

/* Service ID for Cry_HsmMacGenerateFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 494]*/
#define CRY_HSM_SID_MAC_GENERATE_FINISH                              ([!//
[!"num:i(node:value(CryHsmSidMacGenerateFinish))"!]U)

/* Service ID for Cry_HsmMacVerifyStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 495]*/
#define CRY_HSM_SID_MAC_VERIFY_START                                 ([!//
[!"num:i(node:value(CryHsmSidMacVerifyStart))"!]U)

/* Service ID for Cry_HsmMacVerifyUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 496]*/
#define CRY_HSM_SID_MAC_VERIFY_UPDATE                                ([!//
[!"num:i(node:value(CryHsmSidMacVerifyUpdate))"!]U)

/* Service ID for Cry_HsmMacVerifyFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 497]*/
#define CRY_HSM_SID_MAC_VERIFY_FINISH                               ([!//
[!"num:i(node:value(CryHsmSidMacVerifyFinish))"!]U)

/* Service ID for Cry_HsmRandomSeedInitStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 498]*/
#define CRY_HSM_SID_RND_SEED_INIT_START                            ([!//
[!"num:i(node:value(CryHsmSidRndSeedInitStart))"!]U)

/* Service ID for Cry_HsmRandomSeedInitUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 499]*/
#define CRY_HSM_SID_RND_SEED_INIT_UPDATE                           ([!//
[!"num:i(node:value(CryHsmSidRndSeedInitUpdate))"!]U)

/* Service ID for Cry_HsmRandomSeedInitFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 500]*/
#define CRY_HSM_SID_RND_SEED_INIT_FINISH                           ([!//
[!"num:i(node:value(CryHsmSidRndSeedInitFinish))"!]U)

/* Service ID for Cry_HsmRandomSeedExtendStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 501]*/
#define CRY_HSM_SID_RND_SEED_EXTEND_START                          ([!//
[!"num:i(node:value(CryHsmSidRndSeedExtendStart))"!]U)

/* Service ID for Cry_HsmRandomSeedExtendUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 502]*/
#define CRY_HSM_SID_RND_SEED_EXTEND_UPDATE                         ([!//
[!"num:i(node:value(CryHsmSidRndSeedExtendUpdate))"!]U)

/* Service ID for Cry_HsmRandomSeedExtendFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 503]*/
#define CRY_HSM_SID_RND_SEED_EXTEND_FINISH                         ([!//
[!"num:i(node:value(CryHsmSidRndSeedExtendFinish))"!]U)

/* Service ID for Cry_HsmRandomGenerate API */
/* Traceability    : [$Satisfies $CDS_CDRV 504]*/
#define CRY_HSM_SID_RND_GENERATE                                   ([!//
[!"num:i(node:value(CryHsmSidRndGenerate))"!]U)

/* Service ID for Cry_HsmTrueRandomGenerate API */
/* Traceability    : [$Satisfies $CDS_CDRV 505]*/
#define CRY_HSM_SID_TRUE_RND_GENERATE                              ([!//
[!"num:i(node:value(CryHsmSidTrueRndGenerate))"!]U)

/* Service ID for Cry_HsmAesEncryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 506]*/
#define CRY_HSM_SID_AES_ENCRYPT_START                                 ([!//
[!"num:i(node:value(CryHsmSidAesEncryptStart))"!]U)

/* Service ID for Cry_HsmAesEncryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 507]*/
#define CRY_HSM_SID_AES_ENCRYPT_UPDATE                                ([!//
[!"num:i(node:value(CryHsmSidAesEncryptUpdate))"!]U)

/* Service ID for Cry_HsmAesEncryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 508]*/
#define CRY_HSM_SID_AES_ENCRYPT_FINISH                                ([!//
[!"num:i(node:value(CryHsmSidAesEncryptFinish))"!]U)

/* Service ID for Cry_HsmAesDecryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 509]*/
#define CRY_HSM_SID_AES_DECRYPT_START                                 ([!//
[!"num:i(node:value(CryHsmSidAesDecryptStart))"!]U)

/* Service ID for Cry_HsmAesDecryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 510]*/
#define CRY_HSM_SID_AES_DECRYPT_UPDATE                                ([!//
[!"num:i(node:value(CryHsmSidAesDecryptUpdate))"!]U)

/* Service ID for Cry_HsmAesDecryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 511]*/
#define CRY_HSM_SID_AES_DECRYPT_FINISH                                ([!//
[!"num:i(node:value(CryHsmSidAesDecryptFinish))"!]U)

/* Service ID for Cry_HsmAesEcbEncryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 512]*/
#define CRY_HSM_SID_AES_ECB_ENCRYPT_START                              ([!//
[!"num:i(node:value(CryHsmSidAesEcbEncryptStart))"!]U)

/* Service ID for Cry_HsmAesEcbEncryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 513]*/
#define CRY_HSM_SID_AES_ECB_ENCRYPT_UPDATE                             ([!//
[!"num:i(node:value(CryHsmSidAesEcbEncryptUpdate))"!]U)

/* Service ID for Cry_HsmAesEcbEncryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 514]*/
#define CRY_HSM_SID_AES_ECB_ENCRYPT_FINISH                             ([!//
[!"num:i(node:value(CryHsmSidAesEcbEncryptFinish))"!]U)

/* Service ID for Cry_HsmAesEcbDecryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 515]*/
#define CRY_HSM_SID_AES_ECB_DECRYPT_START                               ([!//
[!"num:i(node:value(CryHsmSidAesEcbDecryptStart))"!]U)

/* Service ID for Cry_HsmAesEcbDecryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 516]*/
#define CRY_HSM_SID_AES_ECB_DECRYPT_UPDATE                              ([!//
[!"num:i(node:value(CryHsmSidAesEcbDecryptUpdate))"!]U)

/* Service ID for Cry_HsmAesEcbDecryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 517]*/
#define CRY_HSM_SID_AES_ECB_DECRYPT_FINISH                              ([!//
[!"num:i(node:value(CryHsmSidAesEcbDecryptFinish))"!]U)

/* Service ID for Cry_HsmAesGcmEncryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 518]*/
#define CRY_HSM_SID_AES_GCM_ENCRYPT_START                                ([!//
[!"num:i(node:value(CryHsmSidAesGcmEncryptStart))"!]U)

/* Service ID for Cry_HsmAesGcmEncryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 519]*/
#define CRY_HSM_SID_AES_GCM_ENCRYPT_UPDATE                               ([!//
[!"num:i(node:value(CryHsmSidAesGcmEncryptUpdate))"!]U)

/* Service ID for Cry_HsmAesGcmEncryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 520]*/
#define CRY_HSM_SID_AES_GCM_ENCRYPT_FINISH                               ([!//
[!"num:i(node:value(CryHsmSidAesGcmEncryptFinish))"!]U)

/* Service ID for Cry_HsmAesGcmDecryptStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 521]*/
#define CRY_HSM_SID_AES_GCM_DECRYPT_START                                ([!//
[!"num:i(node:value(CryHsmSidAesGcmDecryptStart))"!]U)

/* Service ID for Cry_HsmAesGcmDecryptUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 522]*/
#define CRY_HSM_SID_AES_GCM_DECRYPT_UPDATE                               ([!//
[!"num:i(node:value(CryHsmSidAesGcmDecryptUpdate))"!]U)

/* Service ID for Cry_HsmAesGcmDecryptFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 523]*/
#define CRY_HSM_SID_AES_GCM_DECRYPT_FINISH                               ([!//
[!"num:i(node:value(CryHsmSidAesGcmDecryptFinish))"!]U)

/* Service ID for Cry_HsmKeyLoadStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 524]*/
#define CRY_HSM_SID_KEY_LOAD_START                                       ([!//
[!"num:i(node:value(CryHsmSidKeyLoadStart))"!]U)

/* Service ID for Cry_HsmKeyLoadUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 525]*/
#define CRY_HSM_SID_KEY_LOAD_UPDATE                                      ([!//
[!"num:i(node:value(CryHsmSidKeyLoadUpdate))"!]U)

/* Service ID for Cry_HsmKeyLoadFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 526]*/
#define CRY_HSM_SID_KEY_LOAD_FINISH                                      ([!//
[!"num:i(node:value(CryHsmSidKeyLoadFinish))"!]U)

/* Service ID for Cry_HsmKeyLoadPlainStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 527]*/
#define CRY_HSM_SID_KEY_LOAD_PLAIN_START                                 ([!//
[!"num:i(node:value(CryHsmSidKeyLoadPlainStart))"!]U)

/* Service ID for CryHsmKeyLoadPlainUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 528]*/
#define CRY_HSM_SID_KEY_LOAD_PLAIN_UPDATE                                 ([!//
[!"num:i(node:value(CryHsmSidKeyLoadPlainUpdate))"!]U)

/* Service ID for Cry_HsmKeyLoadPlainFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 529]*/
#define CRY_HSM_SID_KEY_LOAD_PLAIN_FINISH                                 ([!//
[!"num:i(node:value(CryHsmSidKeyLoadPlainFinish))"!]U)

/* Service ID for Cry_HsmKeyExportStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 530]*/
#define CRY_HSM_SID_KEY_EXPORT_START                                     ([!//
[!"num:i(node:value(CryHsmSidKeyExportStart))"!]U)

/* Service ID for Cry_HsmKeyExportUpdate API */
/* Traceability    : [$Satisfies $CDS_CDRV 531]*/
#define CRY_HSM_SID_KEY_EXPORT_UPDATE                                    ([!//
[!"num:i(node:value(CryHsmSidKeyExportUpdate))"!]U)

/* Service ID for Cry_HsmKeyExportFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 532]*/
#define CRY_HSM_SID_KEY_EXPORT_FINISH                                    ([!//
[!"num:i(node:value(CryHsmSidKeyExportFinish))"!]U)

/* Service ID for CryHsmDebugStart API */
/* Traceability    : [$Satisfies $CDS_CDRV 634]*/
#define CRY_HSM_SID_DEBUG_START                                           ([!//
[!"num:i(node:value(CryHsmSidDebugStart))"!]U)

/* Service ID for CryHsmDebugFinish API */
/* Traceability    : [$Satisfies $CDS_CDRV 635]*/
#define CRY_HSM_SID_DEBUG_FINISH                                          ([!//
[!"num:i(node:value(CryHsmSidDebugFinish))"!]U)

/* Service ID for CryHsmGetUid API */
/* Traceability    : [$Satisfies $CDS_CDRV 639]*/
#define CRY_HSM_SID_GETUID                                                ([!//
[!"num:i(node:value(CryHsmSidGetUid))"!]U)

/* Service ID for Cry_HsmInit API */
/* Traceability    : [$Satisfies $CDS_CDRV 533]*/
#define CRY_HSM_SID_INIT                                                 ([!//
[!"num:i(node:value(CryHsmSidInit))"!]U)

/* Service ID for CryModule API */
/* Traceability    : [$Satisfies $CDS_CDRV 534][$Satisfies $CDS_CDRV 202]*/
#define CRY_MODULE_ID                                                 ([!//
[!"num:i(node:value(CryModuleId))"!]U)

[!/* End of SELECT "CryHsmGeneral" */!][!//
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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!/* End of SELECT "as:modconf('CryHsm')[1]" */!][!//
[!ENDSELECT!][!//

/* end of CRY_HSM_CFG_H */
#endif
