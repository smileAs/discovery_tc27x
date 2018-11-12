/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Hssl_Demo.h $                                              **
**                                                                           **
**  $CC VERSION : \main\5 $                                                  **
**                                                                           **
**  $DATE       : 2015-04-09 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file exports the                                      **
**                Demo Application for HSSL driver                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
    TRACEABILITY : [cover parentID=] [/cover]
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "IfxPort_reg.h"
#include "hssl.h"
#include "IfxHsct_reg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

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
void Hssl_Demo(void ) ;
void Hssl_RegisterWriteDemo(void ) ;
void Hssl_RegisterReadDemo(void ) ; 
void Hssl_MultipleRegisterWriteDemo(void ) ; 
void Hssl_MultipleRegisterReadDemo(void ) ; 
void Hssl_StartStreamingDemo(void ) ; 
void Hssl_StopStreamingDemo(void ) ; 
void Hssl_IDReadDemo(void );
