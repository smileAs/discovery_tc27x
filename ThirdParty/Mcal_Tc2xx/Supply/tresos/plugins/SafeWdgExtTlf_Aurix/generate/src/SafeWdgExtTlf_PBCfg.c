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
**   $FILENAME   : SafeWdgExtTlf_PBCfg.c $                                    **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2016-02-11 $                                               **
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
**  DESCRIPTION  : Code template for SafeWdgExtTlf_PBCfg.c file               **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgExtTlf.docm, Ver 0.1        **
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
**  FILENAME  :  SafeWdgExtTlf_PBCfg.c                                        **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgExtTlf.bmd/xdm                             **
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
**  DESCRIPTION  : SafeWdgExtTlf configuration generated file                 **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgExtTlf.docm, Ver 0.1        **
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

[!SELECT "as:modconf('SafeWdgExtTlf')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SafeWdgExtTlfConfigSet/*))"!][!//

/* external TLF watchdog configuration */
const SafeWdgExtTlf_ConfigType SafeWdgExtTlf_ConfigRoot[] =
{
[!FOR "SafeWdgExtTlf" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SafeWdgExtTlfConfigSet/*[num:i($SafeWdgExtTlf)]"!][!//
	{
[!NOCODE!][!//
[!ASSERT "node:refexists(SafeWdgExtTlfQspiCfgRef)", "/SafeWdgExtTlfConfigSet/SafeWdgExtTlfQspiCfgRef: Reference to QSPI configuration is empty"!][!//
[!VAR "QspiConfigRef" = "node:value(SafeWdgExtTlfQspiCfgRef)"!][!//
[!VAR "QspiConfigRef" = "substring-after($QspiConfigRef, "/")"!][!//
[!VAR "QspiConfigRef" = "substring-after($QspiConfigRef, "/")"!][!//
[!VAR "QspiConfigRef" = "substring-after($QspiConfigRef, "/")"!][!//
[!VAR "QspiConfigRef" = "substring-after($QspiConfigRef, "_")"!][!//
[!ENDNOCODE!][!//
		&SafeWdgQspi_ChannelConfigRoot[[!"$QspiConfigRef"!]],
    [!"(SafeWdgExtTlfMode)"!],/*Type of Watchdog */
 [!IF "node:exists(SafeWdgExtTlfOpenWinTime)"!][!//
 [!VAR "OwTime1" = "SafeWdgExtTlfOpenWinTime"!][!//
[!VAR "OwTime1" = "substring-after($OwTime1, "_")"!][!//
[!VAR "OwTime1" = "num:i(substring-before($OwTime1, "m"))"!][!//
[!ENDIF!][!//
 [!IF "node:exists(SafeWdgExtTlfCloseWinTime)"!][!//
 [!VAR "CwTime1" = "SafeWdgExtTlfCloseWinTime"!][!//
 [!VAR "CwTime1" = "substring-after($CwTime1, "_")"!][!//
[!VAR "CwTime1" = "num:i(substring-before($CwTime1, "m"))"!][!//
[!ENDIF!][!//
 [!IF "node:exists(SafeWdgExtTlfFuncWdgTime  )"!][!//
 [!VAR "FwTime1" = "SafeWdgExtTlfFuncWdgTime"!][!//
 [!VAR "FwTime1" = "substring-after($FwTime1, "_")"!][!//
[!VAR "FwTime1" = "num:i(substring-before($FwTime1, "m"))"!][!//
[!ENDIF!][!//
[!IF "SafeWdgExtTlfMode = 'TLF_WM_FWD_WWD_SPI' "!][!//
[!IF "$OwTime1 > num:i(160) and $CwTime1 > num:i(160)"!][!//
    [!VAR "WatchdogCycleTime" = "num:i(1)"!][!//
[!ELSEIF "$OwTime1 < num:i(200) and $CwTime1 < num:i(200)"!][!//
   [!VAR "WatchdogCycleTime" = "num:i(0)"!][!//
   [!ELSE!][!//
   [!ERROR!][!//
Watchdog cycle time setting is not possible with open ,close watchdog time selected.
Select open ,close watchdog time lesser than 200 or greater than 160. Other combinations
            not allowed.[!//
    [!ENDERROR!][!//
     [!ENDIF!][!//
 [!ELSEIF "SafeWdgExtTlfMode = 'TLF_WM_FWD' "!][!//
   [!IF "$FwTime1 > num:i(160)"!][!//
    [!VAR "WatchdogCycleTime" = "num:i(1)"!][!//
   [!ELSE!][!//
   [!VAR "WatchdogCycleTime" = "num:i(0)"!][!//
   [!ENDIF!][!//
 [!ELSEIF "SafeWdgExtTlfMode = 'TLF_WM_WWD_WDI' or SafeWdgExtTlfMode = 'TLF_WM_WWD_SPI' "!][!//
    [!IF "$OwTime1 > num:i(160) and $CwTime1 > num:i(160)"!][!//
     [!VAR "WatchdogCycleTime" = "num:i(1)"!][!//
   [!ELSEIF "$OwTime1 < num:i(200) and $CwTime1 < num:i(200)"!][!//
     [!VAR "WatchdogCycleTime" = "num:i(0)"!][!//
   [!ELSE!][!//
    [!ERROR!][!//
Watchdog cycle time setting is not possible with open ,close watchdog time selected.
Select open ,close watchdog time lesser than 200 or greater than 160. Other combinations
            not allowed.[!//
    [!ENDERROR!][!//
[!ENDIF!][!//
[!ELSE!] [!//
[!ENDIF!][!//
    [!"$WatchdogCycleTime"!]U, /*Watchdog cycle time.This value will set "WDCYC" bit in WDCFG0*/
[!IF "SafeWdgExtTlfMode = 'TLF_WM_FWD_WWD_SPI' "!][!//
[!IF "$OwTime1 > num:i(160) and $CwTime1 > num:i(160) "!][!//
[!VAR "OwTime" = "num:i( ($OwTime1 div 50)- 1)"!][!//
[!VAR "CwTime" = "num:i( ($CwTime1 div 50)- 1)"!][!//
[!VAR "FnTime" = "num:i( ($FwTime1 div 50)- 1)"!][!//
[!ELSEIF "$OwTime1 < num:i(200) and $CwTime1 < num:i(200) "!][!//
[!VAR "OwTime" = "num:i( ($OwTime1 div 5) - 1 )"!][!//
[!VAR "CwTime" = "num:i( ($CwTime1 div 5) - 1 )"!][!//
[!VAR "FnTime" = "num:i( ($FwTime1 div 5) - 1 )"!][!//
   [!ELSE!][!//
[!ERROR!][!//
Watchdog cycle time setting is not possible with open ,close watchdog time selected.
            Select open ,close and functional watchdog time lesser than 200 or greater than 160. Other combinations
not allowed.[!//
    [!ENDERROR!][!//
   [!ENDIF!][!//
[!IF "$FnTime > 31"!][!//
[!ERROR!][!//
Functional watchdog time can't be set with the given close and open window settings.[!//
[!ENDERROR!][!//
[!ENDIF!][!//
 [!ELSEIF "SafeWdgExtTlfMode = 'TLF_WM_FWD' "!][!//
   [!IF "$FwTime1 > num:i(160)"!][!//
[!VAR "FnTime" = "num:i(($FwTime1   div 50) - 1)"!][!//
[!VAR "OwTime" = "num:i(0)"!][!//
[!VAR "CwTime" = "num:i(0)"!][!//
   [!ELSE!][!//
[!VAR "FnTime" = "num:i( ($FwTime1   div 5) - 1 )"!][!//
[!VAR "OwTime" = "num:i(0)"!][!//
[!VAR "CwTime" = "num:i(0)"!][!//
[!ENDIF!][!//
 
 [!ELSEIF "SafeWdgExtTlfMode = 'TLF_WM_WWD_WDI' or SafeWdgExtTlfMode = 'TLF_WM_WWD_SPI' "!][!//
   [!IF "$OwTime1 > num:i(160) and $CwTime1 > num:i(160)"!][!//
[!VAR "OwTime" = "num:i(($OwTime1 div 50) - 1)"!][!//
[!VAR "CwTime" = "num:i(($CwTime1 div 50) - 1 )"!][!//
[!VAR "FnTime" = "num:i(0)"!][!//
   [!ELSEIF "$OwTime1 < num:i(200) and $CwTime1 < num:i(200)"!][!//
[!VAR "OwTime" = "num:i(($OwTime1 div 5) - 1)"!][!//
[!VAR "CwTime" = "num:i(($CwTime1 div 5) - 1)"!][!//
[!VAR "FnTime" = "num:i(0)"!][!//
[!ELSE!][!//
    [!ERROR!][!//
Watchdog cycle time setting is not possible with open ,close watchdog time selected.
            Select open ,close and functional watchdog time lesser than 200 or greater than 160. Other combinations
not allowed."!][!//
    [!ENDERROR!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!ENDIF!][!//
[!IF "SafeWdgExtTlfMode = 'TLF_WM_FWD_WWD_SPI' "!][!//
    [!"$OwTime"!]U, /*open window time*/
    [!"$CwTime"!]U, /*Close window time*/
    [!"$FnTime"!]U, /*Functional watchdog time*/
 [!ELSEIF "SafeWdgExtTlfMode = 'TLF_WM_FWD' "!][!//
    [!"$OwTime"!]U, /*open window time - will not be considered since functional wdg only is selected*/
    [!"$CwTime"!]U, /*Close window time- will not be considered since functional wdg only is selected*/
    [!"$FnTime"!]U, /*Functional watchdog time*/
  [!ELSEIF "SafeWdgExtTlfMode = 'TLF_WM_WWD_WDI' or SafeWdgExtTlfMode = 'TLF_WM_WWD_SPI' "!][!//
    [!"$OwTime"!]U, /*open window time*/
    [!"$CwTime"!]U, /*Close window time*/
    [!"$FnTime"!]U, /*Functional watchdog time - will not be considered since window wdg only is selected*/
[!ENDIF!]
[!IF "SafeWdgExtTlfMode = 'TLF_WM_FWD_WWD_SPI' "!][!//
		[!"(SafeWdgExtTlfWWDErrThreshold)"!]U,				/*Window Watchdog error threshold*/
		[!"(SafeWdgExtTlfFWDErrThreshold)"!]U,				/*Functional Watchdog error threshold*/
 [!ELSEIF "SafeWdgExtTlfMode = 'TLF_WM_FWD' "!][!//
		2U,				 /*Window Watchdog error threshold - will not be considered since functional wdg only is selected. So selected the minimum value as dummy param*/
		[!"(SafeWdgExtTlfFWDErrThreshold)"!]U,				/*Functional Watchdog error threshold*/
 [!ELSEIF "SafeWdgExtTlfMode = 'TLF_WM_WWD_WDI' or SafeWdgExtTlfMode = 'TLF_WM_WWD_SPI' "!][!//
		[!"(SafeWdgExtTlfWWDErrThreshold)"!]U,				/*Window Watchdog error threshold*/
		2U,				/*Functional Watchdog error threshold will not be considered since window wdg only is selected. So selected minimum value as dummy param */
[!ENDIF!]

[!IF "SafeWdgExtTlfMode = 'TLF_WM_WWD_WDI'"!][!//
		&MODULE_P[!"(SafeWdgExtTlfWDIPortNum)"!],		/* pointer to port configuration of WDI pin */
		[!"(SafeWdgExtTlfWDIPinOffset)"!]U,				/* Pin number of WDI pin */
[!ELSE!][!//
		&MODULE_P20,		/*DUMMY PORT ,Will not be used since TLF_WM_WWD_WDI ia not selected.*/
		9U,				/*DUMMY PIN ,Will not be used since TLF_WM_WWD_WDI ia not selected.*/
[!ENDIF!]
		/* Signature XOR table: */
		{
[!IF "SafeWdgExtTlfMode = 'TLF_WM_FWD' or SafeWdgExtTlfMode = 'TLF_WM_FWD_WWD_SPI'"!][!//
      /*XOR Mask for sig;     Actual TLF Sig*/
			[!"(SafeWdgExtTlfXorMask0x0)"!]U,						  /* FF0FF000*/
			[!"(SafeWdgExtTlfXorMask0x01)"!]U,						/* B040BF4F*/
			[!"(SafeWdgExtTlfXorMask0x02)"!]U,						/* E919E616*/
			[!"(SafeWdgExtTlfXorMask0x03)"!]U,						/* A656A959*/
			[!"(SafeWdgExtTlfXorMask0x04)"!]U,						/* 75857A8A*/
			[!"(SafeWdgExtTlfXorMask0x05)"!]U,						/* 3ACA35C5*/
			[!"(SafeWdgExtTlfXorMask0x06)"!]U,						/* 63936C9C*/
			[!"(SafeWdgExtTlfXorMask0x07)"!]U,						/* 2CDC23D3*/
			[!"(SafeWdgExtTlfXorMask0x08)"!]U,						/* D222DD2D*/
			[!"(SafeWdgExtTlfXorMask0x09)"!]U,						/* 9D6D9262*/
			[!"(SafeWdgExtTlfXorMask0x0A)"!]U,						/* C434CB3B*/
			[!"(SafeWdgExtTlfXorMask0x0B)"!]U,						/* 8B7B8474*/
			[!"(SafeWdgExtTlfXorMask0x0C)"!]U,						/* 58A857A7*/
			[!"(SafeWdgExtTlfXorMask0x0D)"!]U,						/* 17E718E8*/
			[!"(SafeWdgExtTlfXorMask0x0E)"!]U,						/* 4EBE41B1*/
			[!"(SafeWdgExtTlfXorMask0x0F)"!]U							/* 01F10EFE*/
[!ELSE!][!//
			/*TLF_WM_FWD or TLF_WM_FWD_WWD_SPI, NOT selected.These dummy xor masks will
      not be used by the driver*/
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U,
			0x0U
[!ENDIF!]
		}
  }[!IF "$SafeWdgExtTlf < $TotalConfig"!],[!ENDIF!][!//

[!ENDSELECT!][!//
[!ENDFOR!][!//
};

#define IFX_SWDG_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
[!ENDSELECT!][!//
[!AUTOSPACING!][!// 
