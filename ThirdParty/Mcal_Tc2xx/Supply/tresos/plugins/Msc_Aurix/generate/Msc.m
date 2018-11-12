[!/*
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
**  $FILENAME   : Msc.m $                                                    **
**                                                                           **
**  $CC VERSION : \main\13 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-03 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Configuration Generator Macros                             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
*****************************************************************************/!]
[!//
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('MSC_M'))"!][!//
[!VAR "MSC_M"="'true'"!][!//

[!/*****************************************************************************
** Name             : Msc_DscConfig                                           **
**                                                                            **
** Description      : Macro to calculate Value for DSC register from          **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Msc_DscConfig", "TxMode" = "", "DataBitsLow"="", "DataBitsHigh"="", "EnsellLow"="", "EnsellHigh"="", "CmdLen"="", "CmdPassiveLen"="", "PassiveLen"="","TxConfig"="", "TxConfigExtn"=""!]
[!NOCODE!]
[!VAR "TxConfig" = "num:i(0)"!][!//
[!VAR "TxConfigExtn" = "num:i(0)"!][!//
[!IF "$TxMode= 'TX_REPEATMODE'"!][!//
[!VAR "TxConfig" = "bit:or($TxConfig,1)"!][!//
[!ENDIF!][!//

[!IF "$DataBitsLow < 17 and $DataBitsHigh < 17 "!][!//
[!VAR "TxConfig" = "bit:or($TxConfig,bit:shl($DataBitsLow,3))"!][!//
[!VAR "TxConfig" = "bit:or($TxConfig,bit:shl($DataBitsHigh,8))"!][!//
[!ELSE!][!//
[!VAR "DataBitsLow" = "$DataBitsLow - num:i(16)"!][!//
[!VAR "DataBitsHigh" = "$DataBitsHigh - num:i(16)"!][!//
[!VAR "TxConfig" = "bit:or($TxConfig,bit:shl($DataBitsLow,3))"!][!//
[!VAR "TxConfig" = "bit:or($TxConfig,bit:shl($DataBitsHigh,8))"!][!//

[!ENDIF!][!//

[!IF "$EnsellLow= 'TX_DATAFRM_SELBIT_PRESENT'"!][!//
[!VAR "TxConfig" = "bit:or($TxConfig,bit:shl(1,13))"!][!//
[!ENDIF!][!//

[!IF "$EnsellHigh= 'TX_DATAFRM_SELBIT_PRESENT'"!][!//
[!VAR "TxConfig" = "bit:or($TxConfig,bit:shl(1,14))"!][!//
[!ENDIF!][!//

[!VAR "TxConfig" = "bit:or($TxConfig,bit:shl($CmdLen,16))"!][!//
[!VAR "NewPassiveLen" = "bit:and($PassiveLen,31)"!][!//
[!VAR "TxConfig" = "bit:or($TxConfig,bit:shl($NewPassiveLen,24))"!][!//
[!IF "$PassiveLen >= 32 "!][!//
[!VAR "PassiveLenadditionalbitval" = "(bit:and(bit:shr($PassiveLen,5),3))"!][!//
[!VAR "TxConfigExtn" = "bit:or($TxConfigExtn,bit:shl($PassiveLenadditionalbitval,0))"!][!//
[!ENDIF!][!//

[!VAR "CmdPassiveLen" = "($CmdPassiveLen - num:i(2))"!][!//
[!VAR "TxConfigExtn" = "bit:or($TxConfigExtn,bit:shl($CmdPassiveLen,2))"!][!//

[!ENDNOCODE!]
[!ENDMACRO!]


[!/*****************************************************************************
** Name             : Msc_DsdsConfig                                          **
**                                                                            **
** Description      : Macro to calculate Value for DSDS register from         **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Msc_DsdsConfig", "BitNo" = "", "SourceSel"="", "EmgStopEnb"="", "EmgStopVal"="", "EmgStopConfig"="", "EmgExtnStopConfig"="", "EmgStopConfigVal"="", "EmgExtnStopConfigVal"="", "DsdsConfig"="", "DsdsMask"="", "DsdsMaskExtn"="", "DsdsConfigExtension"=""!]
[!NOCODE!]
[!IF "$BitNo <= num:i(15)"!][!//
[!IF "$SourceSel = 'SRC_DOWNSTREAMDATA'"!][!//
[!VAR "DsdsConfig" = "bit:or($DsdsConfig,bit:shl(0,($BitNo * 2)))"!][!//
[!VAR "DsdsMask" ="bit:or($DsdsMask,bit:shl(1,$BitNo ))"!][!//
[!ELSEIF "$SourceSel= 'SRC_GTMSIGNAL'"!][!//
[!VAR "DsdsConfig" = "bit:or($DsdsConfig,bit:shl(2,($BitNo * 2)))"!][!//
[!ELSE!][!//
[!VAR "DsdsConfig" = "bit:or($DsdsConfig,bit:shl(3,($BitNo * 2)))"!][!//
[!ENDIF!][!//
[!IF "$EmgStopEnb= 'EMERGENCYSTOP_ENABLE'"!][!//
[!VAR "EmgStopConfig" = "bit:or($EmgStopConfig,bit:shl(1,$BitNo))"!][!//
[!ENDIF!][!//
[!IF "$EmgStopVal= 'EMERGENCY_DATA_LOGICAL_HIGH'"!][!//
[!VAR "EmgStopConfigVal" = "bit:or($EmgStopConfigVal,bit:shl(1,$BitNo))"!][!//
[!ENDIF!][!//

[!ELSE!][!//
[!VAR "NewBitNo" = "num:i($BitNo - num:i(16))"!][!//
[!IF "$SourceSel = 'SRC_DOWNSTREAMDATA'"!][!//
[!VAR "DsdsConfigExtension" = "bit:or($DsdsConfigExtension,bit:shl(0,($NewBitNo * 2)))"!][!//
[!VAR "DsdsMaskExtn" ="bit:or($DsdsMaskExtn,bit:shl(1,$NewBitNo ))"!][!//
[!ELSEIF "$SourceSel= 'SRC_GTMSIGNAL'"!][!//
[!VAR "DsdsConfigExtension" = "bit:or($DsdsConfigExtension,bit:shl(2,($NewBitNo * 2)))"!][!//
[!ELSE!][!//
[!VAR "DsdsConfigExtension" = "bit:or($DsdsConfigExtension,bit:shl(3,($NewBitNo * 2)))"!][!//
[!ENDIF!][!//
[!IF "$EmgStopEnb= 'EMERGENCYSTOP_ENABLE'"!][!//
[!VAR "EmgExtnStopConfig" = "bit:or($EmgExtnStopConfig,bit:shl(1,$NewBitNo))"!][!//
[!ENDIF!][!//
[!IF "$EmgStopVal= 'EMERGENCY_DATA_LOGICAL_HIGH'"!][!//
[!VAR "EmgExtnStopConfigVal" = "bit:or($EmgExtnStopConfigVal,bit:shl(1,$NewBitNo))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!]
[!ENDMACRO!]

[!/*****************************************************************************
** Name             : Msc_DsceConfig                                          **
**                                                                            **
** Description      : Macro to calculate Value for DSCE register from         **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Msc_DsceConfig", "P0Enb" = "", "P1Enb"="", "P0Pos"="", "P1Pos"="", "DataIns"="", "DsceConfig"="", "ExenStatus"="","DataBitsLow"="", "DataBitsHigh"=""!]
[!NOCODE!]
[!VAR "DsceConfig" = "num:i(0)"!][!//

[!IF "$DataBitsLow > 16 and $DataBitsHigh > 16 "!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl(1,0))"!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl(1,1))"!][!//
[!ELSE!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl(0,0))"!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl(0,1))"!][!//
[!ENDIF!][!//

[!IF "$ExenStatus= 'EXTENSION_ENABLE'"!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl(1,14))"!][!//
[!ENDIF!][!//


[!IF "$P0Enb= 'PIN0_INJECTION_ENABLE'"!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl(1,16))"!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl($P0Pos,17))"!][!//
[!ENDIF!][!//

[!IF "$P1Enb= 'PIN1_INJECTION_ENABLE'"!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl(1,24))"!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl($P1Pos,25))"!][!//
[!ENDIF!][!//

[!IF "$DataIns= 'MSC_AUTO_DATA_INSERTION_ENABLE'"!][!//
[!VAR "DsceConfig" = "bit:or($DsceConfig,bit:shl(1,31))"!][!//
[!ENDIF!][!//


[!ENDNOCODE!]
[!ENDMACRO!]


[!/*****************************************************************************
** Name             : Msc_UsrConfig                                           **
**                                                                            **
** Description      : Macro to calculate Value for USR register from          **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Msc_UsrConfig", "FrameType" = "", "RxBaud"="", "ParityType"="", "ServDelay"="", "Rxconfig"=""!]
[!NOCODE!]
[!VAR "RxConfig" = "num:i(0)"!][!//

[!IF "$FrameType= 'RX_ADDR_PRESENT'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,1)"!][!//
[!ENDIF!][!//

[!IF "$RxBaud= 'MSC_CLOCK_DIV_4'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(1,1))"!][!//
[!ELSEIF "$RxBaud= 'MSC_CLOCK_DIV_8'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(2,1))"!][!//
[!ELSEIF "$RxBaud= 'MSC_CLOCK_DIV_16'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(3,1))"!][!//
[!ELSEIF "$RxBaud= 'MSC_CLOCK_DIV_32'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(4,1))"!][!//
[!ELSEIF "$RxBaud= 'MSC_CLOCK_DIV_64'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(5,1))"!][!//
[!ELSEIF "$RxBaud= 'MSC_CLOCK_DIV_128'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(6,1))"!][!//
[!ELSEIF "$RxBaud= 'MSC_CLOCK_DIV_256'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(7,1))"!][!//
[!ELSE!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(0,1))"!][!//
[!ENDIF!][!//

[!IF "$ParityType= 'RX_ODD_PARITY'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(1,4))"!][!//
[!ENDIF!][!//

[!IF "$ServDelay= 'RX_INTERRUPT_DELAY_ENABLE'"!][!//
[!VAR "RxConfig" = "bit:or($RxConfig,bit:shl(1,5))"!][!//
[!ENDIF!][!//

[!ENDNOCODE!]
[!ENDMACRO!]


[!/*****************************************************************************
** Name             : Msc_OcrConfig                                           **
**                                                                            **
** Description      : Macro to calculate Value for OCR register from          **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Msc_OcrConfig", "ClkLinePol" = "", "ClockType"="", "SoLinePol"="", "CsLinePol"="", "RxLinePol"="", "SignalConfig"=""!]
[!NOCODE!]
[!VAR "SignalConfig" = "num:i(0)"!][!//

[!IF "$ClkLinePol= 'SIGNAL_INVERT_ON'"!][!//
[!VAR "SignalConfig" = "bit:or($SignalConfig,1)"!][!//
[!ENDIF!][!//

[!IF "$SoLinePol= 'SIGNAL_INVERT_ON'"!][!//
[!VAR "SignalConfig" = "bit:or($SignalConfig,bit:shl(1,1))"!][!//
[!ENDIF!][!//

[!IF "$CsLinePol= 'SIGNAL_INVERT_ON'"!][!//
[!VAR "SignalConfig" = "bit:or($SignalConfig,bit:shl(1,2))"!][!//
[!ENDIF!][!//

[!IF "$RxLinePol= 'SIGNAL_INVERT_ON'"!][!//
[!VAR "SignalConfig" = "bit:or($SignalConfig,bit:shl(1,3))"!][!//
[!ENDIF!][!//

[!IF "$ClockType= 'CLOCK_ALWAYS'"!][!//
[!VAR "SignalConfig" = "bit:or($SignalConfig,bit:shl(1,8))"!][!//
[!ENDIF!][!//

[!ENDNOCODE!]
[!ENDMACRO!]


[!/*****************************************************************************
** Name             : Msc_IcrConfig                                           **
**                                                                            **
** Description      : Macro to calculate Value for ICR register from          **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Msc_IcrConfig", "TimeIntrPtr" = "", "CmdIntrPtr"="", "DataIntrEnb"="", "DataIntrPtr"="", "RxIntrEnb"="", "RxIntrPtr"="", "InterruptControl"="","InterruptServiceConfig"=""!]
[!NOCODE!]
[!VAR "InterruptControl" = "num:i(0)"!][!//
[!VAR "InterruptServiceConfig" = "num:i(0)"!][!//
[!VAR "DataEnb" = "num:i(0)"!][!//
[!VAR "RxEnb" = "num:i(0)"!][!//

[!IF "$DataIntrEnb= 'INTR_TRIG_LASTBIT'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,2))"!][!//
[!VAR "DataEnb" = "num:i(1)"!][!//
[!ELSEIF "$DataIntrEnb= 'INTR_TRIG_FIRSTBIT'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(2,2))"!][!//
[!VAR "DataEnb" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$DataEnb= num:i(1)"!][!//
[!IF "$DataIntrPtr= 'INTRPTR_SR1'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,1)"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,1))"!][!//
[!ELSEIF "$DataIntrPtr= 'INTRPTR_SR2'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,2)"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,2))"!][!//
[!ELSEIF "$DataIntrPtr= 'INTRPTR_SR3'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,3)"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,3))"!][!//
[!ELSE!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,0))"!][!//
[!ENDIF!][!//

[!ENDIF!][!//

[!IF "$CmdIntrPtr= 'INTRPTR_SR0'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,7))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,0))"!][!//
[!ELSEIF "$CmdIntrPtr= 'INTRPTR_SR1'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,4))"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,7))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,1))"!][!//
[!ELSEIF "$CmdIntrPtr= 'INTRPTR_SR2'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(2,4))"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,7))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,2))"!][!//
[!ELSEIF "$CmdIntrPtr= 'INTRPTR_SR3'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(3,4))"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,7))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,3))"!][!//
[!ENDIF!][!//

[!IF "$TimeIntrPtr= 'INTRPTR_SR0'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,11))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,0))"!][!//
[!ELSEIF "$TimeIntrPtr= 'INTRPTR_SR1'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,8))"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,11))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,1))"!][!//
[!ELSEIF "$TimeIntrPtr= 'INTRPTR_SR2'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(2,8))"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,11))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,2))"!][!//
[!ELSEIF "$TimeIntrPtr= 'INTRPTR_SR3'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(3,8))"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,11))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,3))"!][!//
[!ENDIF!][!//

[!IF "$RxIntrEnb= 'INTR_TRIG_RX_ALL'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,14))"!][!//
[!VAR "RxEnb" = "num:i(1)"!][!//
[!ELSEIF "$RxIntrEnb= 'INTR_TRIG_NONZERODATA'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(2,14))"!][!//
[!VAR "RxEnb" = "num:i(1)"!][!//
[!ELSEIF "$RxIntrEnb= 'INTR_TRIG_RX_UD3'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(3,14))"!][!//
[!VAR "RxEnb" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$RxEnb= num:i(1)"!][!//
[!IF "$RxIntrPtr= 'INTRPTR_SR1'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(1,12))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,1))"!][!//
[!ELSEIF "$RxIntrPtr= 'INTRPTR_SR2'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(2,12))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,2))"!][!//
[!ELSEIF "$RxIntrPtr= 'INTRPTR_SR3'"!][!//
[!VAR "InterruptControl" = "bit:or($InterruptControl,bit:shl(3,12))"!][!//
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,3))"!][!//
[!ELSE!]
[!VAR "InterruptServiceConfig" = "bit:or($InterruptServiceConfig,bit:shl(1,0))"!][!//
[!ENDIF!][!//

[!ENDIF!][!//

[!ENDNOCODE!]
[!ENDMACRO!]


[!/*****************************************************************************
** Name             : Msc_GenerateCallbackApi                                 **
**                                                                            **
** Description      : Macro for extern declaration of all callbacks           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Msc_GenerateCallbackApi"!][!//
[!VAR "SettingsIndex" = "num:i(0)"!][!//
[!VAR "NoOfSettings" = "num:i(count(MscConfigSet/*))"!][!//
[!FOR "SettingsIndex" = "0" TO "(num:i($NoOfSettings)- 1)"!][!//
[!VAR "ModuleIndex" = "num:i(0)"!][!//
[!VAR "NoOfModules" = "num:i(count(MscConfigSet/*[@index = $SettingsIndex]/MscModuleConfiguration/*))"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i($NoOfModules)- 1)"!][!//
[!SELECT "MscConfigSet/*[@index = $SettingsIndex]/MscModuleConfiguration/*[@index = $ModuleIndex]"!][!//
[!IF "MscTxConfiguration/MscCmdFrameConfiguration/MscCmdFrameNotification != 'NULL_PTR'"!][!//
/* MSC[!"$ModuleIndex"!] Command Frame Call Back function for configuration set [!"$SettingsIndex"!] */
extern void [!"MscTxConfiguration/MscCmdFrameConfiguration/MscCmdFrameNotification"!](void);

[!ENDIF!][!//
[!IF "MscTxConfiguration/MscTimeFrameConfiguration/MscTimeFrameNotification != 'NULL_PTR'"!][!//
/* MSC[!"$ModuleIndex"!] Time Frame Call Back function for configuration set [!"$SettingsIndex"!] */
extern void [!"MscTxConfiguration/MscTimeFrameConfiguration/MscTimeFrameNotification"!](void);

[!ENDIF!][!//
[!IF "MscTxConfiguration/MscDataFrameConfiguration/MscDataFrameNotification != 'NULL_PTR'"!][!//
/* MSC[!"$ModuleIndex"!] Data Frame Call Back function for configuration set [!"$SettingsIndex"!] */
extern void [!"MscTxConfiguration/MscDataFrameConfiguration/MscDataFrameNotification"!](void);

[!ENDIF!][!//
[!IF "MscRxConfiguration/MscRxFrameNotification != 'NULL_PTR'"!][!//
/* MSC[!"$ModuleIndex"!] Rx Frame Call Back function for configuration set [!"$SettingsIndex"!] */
extern void [!"MscRxConfiguration/MscRxFrameNotification"!](void);

[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDMACRO!]

[!ENDIF!][!// IF "not(var:defined('MSC_M'))


