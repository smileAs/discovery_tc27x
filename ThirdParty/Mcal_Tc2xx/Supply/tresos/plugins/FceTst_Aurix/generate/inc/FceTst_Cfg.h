[!/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : FceTst_Cfg.h $                                             **
**                                                                            **
**   $CC VERSION : \main\7 $                                                  **
**                                                                            **
**   $DATE       : 2015-04-13 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : FceTst.bmd/xdm                                    **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for FceTst_Cfg.h file                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*************************************************************************/!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  FceTst_Cfg.h                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : FceTst.bmd /xdm                                   **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : FceTst configuration header file                           **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef FCETST_CFG_H
#define FCETST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define FCETST_8BIT_KERNEL_TEST    (0x00U)
#define FCETST_16BIT_KERNEL_TEST   (0x01U)
#define FCETST_32BIT_KERNEL_TEST   (0x02U)
 

[!SELECT "as:modconf('FceTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(FceTstConfigSet/*))"!][!//
 /* number of available configurations for the SFR test              */
#define FCE_TST_CFG_PARAM_COUNT ( [!"$TotalConfig"!]U ) 

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

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!][!//
#endif  /* FCETST_CFG_H */
[!AUTOSPACING!]
