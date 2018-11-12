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
**   $FILENAME   : SafeWdgQspi_PBCfg.c $                                      **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2015-06-04 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgQspi.bmd/xdm                             	**
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SafeWdgQspi_PBCfg.c file               **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgQspi.docm, Ver 0.1        **
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
**  FILENAME  :  SafeWdgQspi_PBCfg.c                                        **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgQspi.bmd/xdm                             **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/HighTec/WindRiver                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **                                                                      
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgQspi configuration generated file                 **
**                                                                            **
**  SPECIFICATION(S) :Aurix-HE_SafeTlib_DS_SafeWdgQspi.docm, Ver 0.1        **
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


[!SELECT "as:modconf('SafeWdgQspi')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SafeWdgQspiConfigSet/*))"!][!//

/* QSPI Module configuration */
const SafeWdgQspi_ModuleConfigType SafeWdgQspi_ModuleConfigRoot =
{
		&MODULE_QSPI[!"SafeWdgQspiConfigSet/SafeWdgQspiModule"!],/* QSPI module [!"SafeWdgQspiConfigSet/SafeWdgQspiModule"!]selected*/
		&SRC_QSPI[!"SafeWdgQspiConfigSet/SafeWdgQspiModule"!]TX,/*SRC register for Tx interrut*/
		&SRC_QSPI[!"SafeWdgQspiConfigSet/SafeWdgQspiModule"!]RX,/*SRC register for Rx interrut*/
		[!"SafeWdgQspiConfigSet/SafeWdgQspiDmaTxChannel"!]U,/* DMA Tx channel */ 
		[!"SafeWdgQspiConfigSet/SafeWdgQspiDmaRxChannel"!]U,/* DMA Rx channel */ 
		[!"SafeWdgQspiConfigSet/SafeWdgQspiRxInpSelection"!]U,/* Receive input selection*/
		[!"SafeWdgQspiConfigSet/SafeWdgQspiModuleTQLen"!]U, /*SafeWdgQspiModuleTQLen*/
   [!IF "SafeWdgQspiConfigSet/SafeWdgQspiCustCallback = 'NULL_PTR' "!][!//
		[!"SafeWdgQspiConfigSet/SafeWdgQspiCustCallback"!]/* No User callback fucntion for SafeWdgQspi_CustomerTxRx()*/
    [!ELSE!][!//
    &[!"SafeWdgQspiConfigSet/SafeWdgQspiCustCallback"!]/* User callback fucntion for SafeWdgQspi_CustomerTxRx()*/
    [!ENDIF!][!//
	};  

const SafeWdgQspi_ChannelConfigType SafeWdgQspi_ChannelConfigRoot[] = 
{
[!FOR "SafeWdgQspi" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SafeWdgQspiChannelConfigSet/*[num:i($SafeWdgQspi)]"!][!//   
 {
		[!"SafeWdgQspiChannel"!]U,/* Channel [!"SafeWdgQspiChannel"!]  slected */
		[!"SafeWdgQspiSlaveSlctActvLvl"!]U,/* Slave select SSOC.AOL*/
		
		[!"SafeWdgQspiChannelTQLen"!]U,/*SafeWdgQspiChannelTQLen*/
		[!"SafeWdgQspiECONzBitSeg1"!]U,/*SafeWdgQspiECONzBitSeg1*/
		[!"SafeWdgQspiECONzBitSeg2"!]U,/*SafeWdgQspiECONzBitSeg2*/
		[!"SafeWdgQspiECONzBitSeg3"!]U,/*SafeWdgQspiECONzBitSeg3*/
		[!"SafeWdgQspiClkPhase"!]U,/*Clock Phase (ECONz.CPH)*/
		[!"SafeWdgQspiClkPolarity"!]U,/*Clock Polarity (ECONz.CPOL)*/
		[!"SafeWdgQspiParityEnable"!]U,/*Parity Enable (ECONz.PAREN)*/
		[!"SafeWdgQspiParityType"!]U,/*Even parity (BACON.PARTYP)*/
		[!"SafeWdgQspiMSBFirst"!]U,/*MSB first (BACON.MSB)*/
		[!"SafeWdgQspiDataLen"!]U,/*15bits data length (BACON.DL)*/
		[!"SafeWdgQspiIdlePrescaler"!]U,/*Idle delay prescaler (BACON.IPRE)*/
		[!"SafeWdgQspiIdleTime"!]U,/*Idle delay length (BACON.IDLE)*/
		[!"SafeWdgQspiLeadPrescaler"!]U,/*Leading delay prescaler (BACON.LPRE)*/
		[!"SafeWdgQspiLeadTime"!]U,/*Leading delay length (BACON.LEAD)*/
		[!"SafeWdgQspiTrailPrescaler"!]U,/*Trailing delay prescaler (BACON.TPRE)*/
		[!"SafeWdgQspiTrailTime"!]U/* Trailing delay length (BACON.TRAIL)*/

 }[!IF "$SafeWdgQspi < $TotalConfig"!],[!ENDIF!][!//  

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
