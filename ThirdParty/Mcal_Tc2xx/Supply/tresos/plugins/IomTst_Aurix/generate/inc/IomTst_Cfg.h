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
**   $FILENAME   : IomTst_Cfg.h $                                             **
**                                                                            **
**   $CC VERSION : \main\2 $                                                  **
**                                                                            **
**   $DATE       : 2015-03-31 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : IomTst.bmd/xdm                                    **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for IomTst_Cfg.h file                        **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
******************************************************************************/!]
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
**  FILENAME  :  IomTst_Cfg.h                                                 **
**                                                                            **
**  VERSION   : 0.0.1                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Iom.bmd/xdm                                       **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : IomTst configuration generated out of ECU configuration    **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef IOM_CFG_H
#define IOM_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('IomTst')[1]"!][!//
[!//
[!VAR "TotalConfig" = "num:i(count(IomTstConfigSet/*))"!][!//
[!VAR "TotalLamBlocks" = "num:i(count(IomTstConfigSet/*[num:i(1)]/IomTstLamBlock/*))"!][!//

#define IOMTST_CFG_PARAM_COUNT           [!//
((uint8)([!"num:inttohex($TotalConfig,2)"!]U))

#define IOMTST_LAM_BLOCKS_TO_TEST        [!//
((uint8)([!"num:inttohex($TotalLamBlocks,2)"!]U))

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* IOM_CFG_H */

[!ENDSELECT!][!//
[!AUTOSPACING!][!//