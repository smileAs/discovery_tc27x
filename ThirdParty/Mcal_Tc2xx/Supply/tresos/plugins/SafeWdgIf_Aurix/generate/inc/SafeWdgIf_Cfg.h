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
**   $FILENAME   : SafeWdgIf_Cfg.h $                                          **
**                                                                            **
**   $CC VERSION : \main\23 $                                                 **
**                                                                            **
**   $DATE       : 2015-09-30 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION :SafeWdgIf.bmd/xdm                                  **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SafeWdgIf_Cfg.h file                     **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgIf.docm, Ver 1.1            **
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
**  FILENAME  : SafeWdgIf_Cfg.h                                               **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION :SafeWdgIf.bmd /xdm                                 **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU /Diab                                           **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  :SafeWdgIf configuration header file                         **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SAFEWDGIF_CFG_H
#define SAFEWDGIF_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!SELECT "as:modconf('SafeWdgIf')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SafeWdgIfConfigSet/*))"!][!//
[!IF "SafeWdgIfGeneral/SafeWdgIfWdgCombination = 'SWDG_INT_WDG_ONLY'"!][!//
/*Only internal watchdog is used*/
#define SWDG_INT_WDG_ONLY
#include "SafeWdgIf_Types.h"
#include "SafeWdgInt.h"
#define SAFEWDGIF_CFG_COUNT              ( [!"$TotalConfig"!]u )

#define SafeWdgIf_CfgIntServiceFn(a)     SafeWdgInt_Service((a))
#define SafeWdgIf_CfgIntInitFn(a)        SafeWdgInt_Init((a))
#define SafeWdgIf_CfgIntDeInitFn()       SafeWdgInt_DeInit()
#define SafeWdgIf_CfgIntActivateFn()     SafeWdgInt_Activate()
#define SafeWdgIf_CfgIntGetSeedFn(a)     SafeWdgInt_GetSeed((a))
#define SafeWdgIf_CfgIntGetStateFn()     SafeWdgInt_GetState()
#define SafeWdgIf_CfgIntInfo()           (E_NOT_OK)
#define SafeWdgIf_CfgIntGetErrCntr(a)    (E_NOT_OK)
#define SafeWdgIf_CfgIntUserReqFn(a,b)   (E_NOT_OK)
#define SafeWdgIf_CfgIntJobResult()      (E_NOT_OK)

#define SafeWdgIf_CfgExtServiceFn(a)     (E_NOT_OK)
#define SafeWdgIf_CfgExtInitFn(a)        (E_NOT_OK)
#define SafeWdgIf_CfgExtDeInitFn()       (E_NOT_OK)
#define SafeWdgIf_CfgExtActivateFn()     (E_NOT_OK)
#define SafeWdgIf_CfgExtGetSeedFn(a)     (E_NOT_OK)
#define SafeWdgIf_CfgExtGetStateFn()     (E_NOT_OK)
#define SafeWdgIf_CfgExtUserReqFn(a,b)   (E_NOT_OK)
#define SafeWdgIf_CfgExtJobResult()      (E_NOT_OK)
#define SafeWdgIf_CfgExtGetErrCntr(a)    (E_NOT_OK)
#define SafeWdgIf_CfgExtTxDoneCallback(a)(E_NOT_OK)
#define SafeWdgIf_CfgExtInfo()           (E_NOT_OK)
[!ENDIF!][!//  
[!IF "SafeWdgIfGeneral/SafeWdgIfWdgCombination = 'SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG'"!][!//
/* Internal watchdog + External TLF watchdog (used in window mode) */
#define SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG
/* Number of available configurations for the SafeWdgIf test */
#define SAFEWDGIF_CFG_COUNT              ( [!"$TotalConfig"!]u )
#include "SafeWdgIf_Types.h"
#include "SafeWdgInt.h"
#include "SafeWdgQspi.h"
#include "SafeWdgExtTlf.h"


#define SafeWdgIf_CfgExtServiceFn(a)        SafeWdgExtTlf_Service((a))
#define SafeWdgIf_CfgExtInitFn(a)           SafeWdgExtTlf_Init((a))
#define SafeWdgIf_CfgExtDeInitFn()          SafeWdgExtTlf_DeInit()
#define SafeWdgIf_CfgExtActivateFn()        SafeWdgExtTlf_Activate()
#define SafeWdgIf_CfgExtGetSeedFn(a)        SafeWdgExtTlf_GetSeed((a))
#define SafeWdgIf_CfgExtGetStateFn()        SafeWdgExtTlf_GetState()
#define SafeWdgIf_CfgExtUserReqFn(a,b)      SafeWdgExtTlf_UserRequest((a),(b))
#define SafeWdgIf_CfgExtJobResult()         SafeWdgExtTlf_GetJobResult()
#define SafeWdgIf_CfgExtGetErrCntr(a)       SafeWdgExtTlf_GetErrCntr((a))
#define SafeWdgIf_CfgExtInfo()              SafeWdgExtTlf_GetWdgInfo()

#define SafeWdgIf_CfgIntServiceFn(a)     SafeWdgInt_Service((a))
#define SafeWdgIf_CfgIntInitFn(a)        SafeWdgInt_Init((a))
#define SafeWdgIf_CfgIntDeInitFn()       SafeWdgInt_DeInit()
#define SafeWdgIf_CfgIntActivateFn()     SafeWdgInt_Activate()
#define SafeWdgIf_CfgIntGetSeedFn(a)     SafeWdgInt_GetSeed((a))
#define SafeWdgIf_CfgIntGetStateFn()     SafeWdgInt_GetState()
#define SafeWdgIf_CfgIntInfo()           (E_NOT_OK)
#define SafeWdgIf_CfgIntGetErrCntr(a)    (E_NOT_OK)
#define SafeWdgIf_CfgIntUserReqFn(a,b)   (E_NOT_OK)
#define SafeWdgIf_CfgIntJobResult()      (E_NOT_OK)

#define SafeWdgIf_CfgExtTxDoneCallback(a)(E_NOT_OK)

[!ENDIF!][!//  
[!IF "SafeWdgIfGeneral/SafeWdgIfWdgCombination = 'SWDG_EXT_CIC_WDG_ONLY'"!][!//
/* Only External CIC watchdog is used - Challenge and response watchdog */
#define SWDG_EXT_CIC_WDG_ONLY
#include "SafeWdgIf_Types.h"
#include "SafeWdgAscLin.h"
#include "SafeWdgExtCic.h"
#include "SafeWdgExtCic_MF.h"
/* Number of available configurations for the SafeWdgIf test */
#define SAFEWDGIF_CFG_COUNT              ( [!"$TotalConfig"!]u )


#define SafeWdgIf_CfgExtServiceFn(a)        SafeWdgExtCic_Service((a))
#define SafeWdgIf_CfgExtInitFn(a)           SafeWdgExtCic_Init((a))
#define SafeWdgIf_CfgExtDeInitFn()          SafeWdgExtCic_DeInit()
#define SafeWdgIf_CfgExtActivateFn()        SafeWdgExtCic_Activate()
#define SafeWdgIf_CfgExtGetSeedFn(a)        SafeWdgExtCic_GetSeed((a))
#define SafeWdgIf_CfgExtGetStateFn()        SafeWdgExtCic_GetState()
#define SafeWdgIf_CfgExtUserReqFn(a,b)      SafeWdgExtCic_UserRequest((a),(b))
#define SafeWdgIf_CfgExtJobResult()         SafeWdgExtCic_GetJobResult()
#define SafeWdgIf_CfgExtGetErrCntr(a)       SafeWdgExtCic_GetErrCntr((a))
#define SafeWdgIf_CfgExtInfo()              SafeWdgExtCic_GetWdgInfo()

#define SafeWdgIf_CfgIntServiceFn(a)     (E_NOT_OK)
#define SafeWdgIf_CfgIntInitFn(a)        (E_NOT_OK)
#define SafeWdgIf_CfgIntDeInitFn()       
#define SafeWdgIf_CfgIntActivateFn()     (E_NOT_OK)
#define SafeWdgIf_CfgIntGetSeedFn(a)     (E_NOT_OK)
#define SafeWdgIf_CfgIntGetStateFn()     (E_NOT_OK)
#define SafeWdgIf_CfgIntInfo()           (E_NOT_OK)
#define SafeWdgIf_CfgIntGetErrCntr(a)    (E_NOT_OK)
#define SafeWdgIf_CfgIntUserReqFn(a,b)   (E_NOT_OK)
#define SafeWdgIf_CfgIntJobResult()      (E_NOT_OK)
[!ENDIF!][!//  
[!IF "SafeWdgIfGeneral/SafeWdgIfWdgCombination = 'SWDG_EXT_TLF_WDG_ONLY'"!][!//
/* Only External TLF watchdog is used - Challenge and response watchdog */
#define SWDG_EXT_TLF_WDG_ONLY
/* Number of available configurations for the SafeWdgIf test */
#define SAFEWDGIF_CFG_COUNT               ( [!"$TotalConfig"!]u )
#include "SafeWdgIf_Types.h"
#include "SafeWdgQspi.h"
#include "SafeWdgExtTlf.h"


#define SafeWdgIf_CfgExtServiceFn(a)        SafeWdgExtTlf_Service((a))
#define SafeWdgIf_CfgExtInitFn(a)           SafeWdgExtTlf_Init((a))
#define SafeWdgIf_CfgExtDeInitFn()          SafeWdgExtTlf_DeInit()
#define SafeWdgIf_CfgExtActivateFn()        SafeWdgExtTlf_Activate()
#define SafeWdgIf_CfgExtGetSeedFn(a)        SafeWdgExtTlf_GetSeed((a))
#define SafeWdgIf_CfgExtGetStateFn()        SafeWdgExtTlf_GetState()
#define SafeWdgIf_CfgExtUserReqFn(a,b)      SafeWdgExtTlf_UserRequest((a),(b))
#define SafeWdgIf_CfgExtJobResult()         SafeWdgExtTlf_GetJobResult()
#define SafeWdgIf_CfgExtGetErrCntr(a)       SafeWdgExtTlf_GetErrCntr((a))
#define SafeWdgIf_CfgExtInfo()              SafeWdgExtTlf_GetWdgInfo()

#define SafeWdgIf_CfgIntServiceFn(a)     (E_NOT_OK)
#define SafeWdgIf_CfgIntInitFn(a)        (E_NOT_OK)
#define SafeWdgIf_CfgIntDeInitFn()       
#define SafeWdgIf_CfgIntActivateFn()     (E_NOT_OK)
#define SafeWdgIf_CfgIntGetSeedFn(a)     (E_NOT_OK)
#define SafeWdgIf_CfgIntGetStateFn()     (E_NOT_OK)
#define SafeWdgIf_CfgIntInfo()           (E_NOT_OK)
#define SafeWdgIf_CfgIntGetErrCntr(a)    (E_NOT_OK)
#define SafeWdgIf_CfgIntUserReqFn(a,b)   (E_NOT_OK)
#define SafeWdgIf_CfgIntJobResult()      (E_NOT_OK)

#define SafeWdgIf_CfgExtTxDoneCallback(a)(E_NOT_OK)
[!ENDIF!][!//  

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
#endif  /*SAFEWDGIF_CFG_H */
[!AUTOSPACING!]
