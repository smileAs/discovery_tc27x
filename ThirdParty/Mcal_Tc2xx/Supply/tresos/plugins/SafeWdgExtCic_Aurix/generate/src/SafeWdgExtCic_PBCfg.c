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
**   $FILENAME   : SafeWdgExtCic_PBCfg.c $                                    **
**                                                                            **
**   $CC VERSION : \main\17 $                                                 **
**                                                                            **
**   $DATE       : 2015-03-24 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgExtCic.bmd/xdm                             **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SafeWdgExtCic_PBCfg.c file               **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgExtCic.docm, Ver 0.1        **
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
**  FILENAME  :  SafeWdgExtCic_PBCfg.c                                        **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgExtCic.bmd/xdm                             **
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
**  DESCRIPTION  : SafeWdgExtCic configuration generated file                 **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgExtCic.docm, Ver 0.1        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "SafeWdgIf.h"

/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/


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

[!SELECT "as:modconf('SafeWdgExtCic')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SafeWdgExtCicConfigSet/*))"!][!//

/* external CiC watchdog configuration */
const SafeWdgExtCic_ConfigType SafeWdgExtCic_ConfigRoot[] =
{
 
  [!FOR "SafeWdgExtCic" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
  [!SELECT "SafeWdgExtCicConfigSet/*[num:i($SafeWdgExtCic)]"!][!//   
    {
      /* configuration for safety path check */
    [!NOCODE!]
    [!ASSERT "node:refexists(SafeWdgExtCicAscLinCfgPtr)", "/SafeWdgExtCicConfigSet/SafeWdgExtCicAscLinCfgPtr: Reference to QSPI configuration is empty"!]    
    [!VAR "AscLinConfigRef" = "node:value(SafeWdgExtCicAscLinCfgPtr)"!]
      [!VAR "AscLinConfigRef" = "substring-after($AscLinConfigRef, "/")"!]
      [!VAR "AscLinConfigRef" = "substring-after($AscLinConfigRef, "/")"!]
      [!VAR "AscLinConfigRef" = "substring-after($AscLinConfigRef, "/")"!]
      [!VAR "AscLinConfigRef" = "substring-after($AscLinConfigRef, "_")"!]
      [!ENDNOCODE!]
       &SafeWdgAscLin_ConfigRoot[[!"$AscLinConfigRef"!]],   /* pointer to config for ASCLIN */       
       {
     
        {    [!NOCODE!]


    [!VAR "VAR01" = "num:i(SafeWdgExtCicConfigTstSig0)"!]
        [!VAR "VAR02" = "num:i(SafeWdgExtCicExptdTstSig0)"!]
        [!VAR "VAR03" = "num:i(bit:xor($VAR01,$VAR02))"!]

        [!VAR "VAR11" = "num:i(SafeWdgExtCicConfigTstSig1)"!]
        [!VAR "VAR12" = "num:i(SafeWdgExtCicExptdTstSig1)"!]
        [!VAR "VAR13" = "num:i(bit:xor($VAR11,$VAR12))"!]

        [!VAR "VAR21" = "num:i(SafeWdgExtCicConfigTstSig2)"!]
        [!VAR "VAR22" = "num:i(SafeWdgExtCicExptdTstSig2)"!]
        [!VAR "VAR23" = "num:i(bit:xor($VAR21,$VAR22))"!]

        [!VAR "VAR31" = "num:i(SafeWdgExtCicConfigTstSig3)"!]
        [!VAR "VAR32" = "num:i(SafeWdgExtCicExptdTstSig3)"!]
        [!VAR "VAR33" = "num:i(bit:xor($VAR31,$VAR32))"!]
    
    [!VAR "VAR41" = "num:i(SafeWdgExtCicConfigTstSig4)"!]
        [!VAR "VAR42" = "num:i(SafeWdgExtCicExptdTstSig4)"!]
        [!VAR "VAR43" = "num:i(bit:xor($VAR41,$VAR42))"!]
    
    [!VAR "VAR51" = "num:i(SafeWdgExtCicConfigTstSig5)"!]
        [!VAR "VAR52" = "num:i(SafeWdgExtCicExptdTstSig5)"!]
        [!VAR "VAR53" = "num:i(bit:xor($VAR51,$VAR52))"!]
    
    [!VAR "VAR61" = "num:i(SafeWdgExtCicConfigTstSig6)"!]
        [!VAR "VAR62" = "num:i(SafeWdgExtCicExptdTstSig6)"!]
        [!VAR "VAR63" = "num:i(bit:xor($VAR61,$VAR62))"!]
    
    [!VAR "VAR71" = "num:i(SafeWdgExtCicConfigTstSig7)"!]
        [!VAR "VAR72" = "num:i(SafeWdgExtCicExptdTstSig7)"!]
        [!VAR "VAR73" = "num:i(bit:xor($VAR71,$VAR72))"!]
    
    [!VAR "VAR81" = "num:i(SafeWdgExtCicConfigTstSig8)"!]
        [!VAR "VAR82" = "num:i(SafeWdgExtCicExptdTstSig8)"!]
        [!VAR "VAR83" = "num:i(bit:xor($VAR81,$VAR82))"!]
    
    [!VAR "VAR91" = "num:i(SafeWdgExtCicConfigTstSig9)"!]
        [!VAR "VAR92" = "num:i(SafeWdgExtCicExptdTstSig9)"!]
        [!VAR "VAR93" = "num:i(bit:xor($VAR91,$VAR92))"!]
    
    [!VAR "VAR101" = "num:i(SafeWdgExtCicConfigTstSig10)"!]
        [!VAR "VAR102" = "num:i(SafeWdgExtCicExptdTstSig10)"!]
        [!VAR "VAR103" = "num:i(bit:xor($VAR101,$VAR102))"!]
    
    [!VAR "VAR111" = "num:i(SafeWdgExtCicConfigTstSig11)"!]
        [!VAR "VAR112" = "num:i(SafeWdgExtCicExptdTstSig11)"!]
        [!VAR "VAR113" = "num:i(bit:xor($VAR111,$VAR112))"!]
    
    [!VAR "VAR121" = "num:i(SafeWdgExtCicConfigTstSig12)"!]
        [!VAR "VAR122" = "num:i(SafeWdgExtCicExptdTstSig12)"!]
        [!VAR "VAR123" = "num:i(bit:xor($VAR121,$VAR122))"!]
    
    [!VAR "VAR131" = "num:i(SafeWdgExtCicConfigTstSig13)"!]
        [!VAR "VAR132" = "num:i(SafeWdgExtCicExptdTstSig13)"!]
        [!VAR "VAR133" = "num:i(bit:xor($VAR131,$VAR132))"!]
    
    
    [!VAR "VAR141" = "num:i(SafeWdgExtCicConfigTstSig14)"!]
        [!VAR "VAR142" = "num:i(SafeWdgExtCicExptdTstSig14)"!]
        [!VAR "VAR143" = "num:i(bit:xor($VAR141,$VAR142))"!]
    
    [!VAR "VAR151" = "num:i(SafeWdgExtCicConfigTstSig15)"!]
        [!VAR "VAR152" = "num:i(SafeWdgExtCicExptdTstSig15)"!]
        [!VAR "VAR153" = "num:i(bit:xor($VAR151,$VAR152))"!]    
  
      [!ENDNOCODE!]  
                 
                 
           /* Cic expected values */
           {[!"num:inttohex($VAR03)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig0)"!]u},      /* F80DE974  0*/
           {[!"num:inttohex($VAR13)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig1)"!]u},      /* B742A63B  1*/
           {[!"num:inttohex($VAR23)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig2)"!]u},      /* EE1BFF62  2*/
           {[!"num:inttohex($VAR33)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig3)"!]u},      /* A154B02D  3*/
           {[!"num:inttohex($VAR43)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig4)"!]u},      /* 728763FE  4*/
           {[!"num:inttohex($VAR53)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig5)"!]u},      /* 3DC82CB1  5*/   
           {[!"num:inttohex($VAR63)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig6)"!]u},      /* 649175E8  6*/    
           {[!"num:inttohex($VAR73)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig7)"!]u},      /* 2BDE3AA7  7*/
           {[!"num:inttohex($VAR83)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig8)"!]u},      /* D520C459  8*/
           {[!"num:inttohex($VAR93)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig9)"!]u},      /* 9A6F8B16  9*/
           {[!"num:inttohex($VAR103)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig10)"!]u},    /* C336D24F  10*/
           {[!"num:inttohex($VAR113)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig11)"!]u},    /* 8C799D00  11*/
           {[!"num:inttohex($VAR123)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig12)"!]u},    /* 5FAA4ED3  12*/
           {[!"num:inttohex($VAR133)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig13)"!]u},    /* 10E5019C  13*/
           {[!"num:inttohex($VAR143)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig14)"!]u},    /* 49BC58C5  14*/
           {[!"num:inttohex($VAR153)"!]u, [!"num:inttohex(SafeWdgExtCicExptdTstSig15)"!]u}     /* 06F3178A  15*/
        
      }  
    }[!IF "$SafeWdgExtCic < $TotalConfig"!],[!ENDIF!][!//  
    
  [!ENDSELECT!][!//
  [!ENDFOR!][!//  
  }  
};

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

[!ENDSELECT!][!//
[!AUTOSPACING!] 
