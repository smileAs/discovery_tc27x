[!/*
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : CpuMpuTst.m $                                              **
**                                                                            **
**   $CC VERSION : \main\4 $                                                  **
**                                                                            **
**   $DATE       : 2014-08-09 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuMpuTst.bmd/xdm                                 **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Configuration Generator Macros                             **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** BK           Basavaraj Kotayya                                                  **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V0.0.1:  2012-11-29, BK :Initial Version of Aurix CpuMpuTst
*/
*/!]
/******************************************************************************/
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('CpuMpuTst_M'))"!][!//
[!VAR "CpuMpuTst_M"="'true'"!][!//

/*******************************************************************************
** Name             : CG_ConfigSwitch                                         **
**                                                                            **
** Description      : Macro to generate configuration switch Values ON/OFF    **
**                    based on configuration true/false                       **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_ConfigSwitch", "MacInputVal" = ""!][!//
[!IF "$MacInputVal = 'true'"!][!//
[!VAR "OutMacVal" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "OutMacVal" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//

[!ENDIF!][!// IF "not(var:defined('CpuMpuTst_M'))
