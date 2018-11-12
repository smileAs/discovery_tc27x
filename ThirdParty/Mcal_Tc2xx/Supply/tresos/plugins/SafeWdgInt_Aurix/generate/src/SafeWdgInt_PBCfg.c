[!/*****************************************************************************
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
**   $FILENAME   : SafeWdgInt_PBCfg.c $                                       **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2014-04-08 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgInt.bmd/xdm                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SafeWdgInt_PBCfg.c file                  **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*****************************************************************************/!]
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
**  FILENAME  :  SafeWdgInt_PBCfg.c                                           **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgInt.bmd/xdm                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU / Diab                                          **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **                                                                      
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgInt configuration file                              **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SafeWdgInt.h"

/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/
[!SELECT "as:modconf('SafeWdgInt')[1]"!][!//

[!VAR "TotalConfig" = "num:i(count(SafeWdgIntConfigSet/*))"!][!//

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define IFX_SWDG_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

/* internal watchdog configuration */
const SafeWdgInt_ConfigType SafeWdgInt_ConfigRoot[] =
{
  [!FOR "SafeWdgInt" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
  [!SELECT "SafeWdgIntConfigSet/*[num:i($SafeWdgInt)]"!][!//
  {
    [!"(SafeWdgIntFreq)"!]u,  [!"(SafeWdgIntTimerReload)"!]u, /* timeout settings */

    /* Signature table */
    {
      {
        {MCAL_WDT_PW_FIXPART_READ, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig0)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0x300u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig1)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0x500u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig2)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0x700u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig3)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0x900u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig4)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0xb00u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig5)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0xd00u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig6)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0xf00u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig7)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0xe00u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig8)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0xc00u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig9)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0xa00u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig10)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0x800u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig11)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0x600u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig12)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0x400u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig13)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0x200u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig14)"!]u},
        {MCAL_WDT_PW_FIXPART_READ+0x100u, [!"num:inttohex(SafeWdgIntSigTable/SafeWdgIntExptdTstSig15)"!]u}
      }
    }
  }[!IF "$SafeWdgInt < $TotalConfig"!],[!ENDIF!][!//  
    
  [!ENDSELECT!][!//
  [!ENDFOR!][!//  
};

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
[!ENDSELECT!][!//
[!AUTOSPACING!] 