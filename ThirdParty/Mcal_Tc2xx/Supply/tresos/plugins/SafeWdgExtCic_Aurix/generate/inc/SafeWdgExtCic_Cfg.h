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
**   $FILENAME   : SafeWdgExtCic_Cfg.h $                                      **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
**                                                                            **
**   $DATE       : 2015-07-30 $                                               **
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
**  DESCRIPTION  : Code template for SafeWdgExtCic_Cfg.h file                 **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
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
**  FILENAME  :  SafeWdgExtCic_Cfg.h                                          **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgExtCic.bmd /xdm                            **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgExtCic configuration header file                    **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SAFEWDGEXTCIC_CFG_H
#define SAFEWDGEXTCIC_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!SELECT "as:modconf('SafeWdgExtCic')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SafeWdgExtCicConfigSet/*))"!][!//


#define SAFEWDGEXTCIC_CFG_COUNT                 ( [!"$TotalConfig"!]U )
  
/*
--------------------------------------------------------------------------------
  Debug switch:
   TRUE: It allows user to ignore signature verification by watchdog and 
          transfers expected watchdog signatures to external CIC watchdog. 
   FALSE: Signatures are verified by external CIC watchdog. 
          This switch MUST be FALSE in production code.
--------------------------------------------------------------------------------
*/
#define SAFEWDGEXTCIC_DEBUG_EN                  (FALSE)

/* Enable for trace of communication */
#define SAFEWDGEXTCIC_TRC_EN                    (FALSE)   

/* fill only once and freeze */
#define SAFEWDGEXTCIC_TRCFREEZE                 (FALSE)  
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
#endif  /*SAFEWDGEXTCIC_CFG_H */
[!AUTOSPACING!]

