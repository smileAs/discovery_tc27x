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
**   $FILENAME   : Cry_Hsm_Cfg.h $                                            **
**                                                                            **
**   $CC VERSION : \main\37 $                                                 **
**                                                                            **
**   $DATE       : 2014-11-06 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Cry_Hsm configuration generated out of ECU configuration   **
**                 file                                                       **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
********************************************************************************
[!/*
MACRO: CG_ConfigSwitch
Macro to generate configuration switch Values STD_ON/STD_OFF based on configuration
true/false
*/!]
[!//
[!MACRO "CG_ConfigSwitch", "node" = ""!][!//
[!//
[!IF "$node = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!][!//
[!ENDMACRO!][!//