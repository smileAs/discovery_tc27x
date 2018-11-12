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
**   $FILENAME   : PflashMonTst_Cfg.h $                                       **
**                                                                            **
**   $CC VERSION : \main\2 $                                                  **
**                                                                            **
**   $DATE       : 2016-05-16 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : PmuEccEdcTst.bmd/xdm                              **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for PflashMonTst_Cfg.h file                  **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
**************************************************************************/!][!//
[!//
/*******************************************************************************
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
**  FILENAME  :  PflashMonTst_Cfg.h                                           **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : PmuEccEdcTst.bmd /xdm                             **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU /Diab                                           **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : PflashMonTst configuration header file                     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef PFLASHMONTST_CFG_H
#define PFLASHMONTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('PmuEccEdcTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(PmuEccEdcTstConfigSet/*))"!][!//
[!//
/* Number of available configurations for the PFLASH monitor test: */
#define PFLASH_MON_TST_CFG_PARAM_COUNT          ( [!"$TotalConfig"!]U ) 

[!VAR "PmuCount" = "num:i(0)"!][!//
[!IF "node:exists(PmuEccEdcTstGeneral/PmuEccEdcTstPF0Select) = 'true'"!][!//     
[!VAR "PmuCount" = "$PmuCount + num:i(1)"!][!//
[!ENDIF!][!//
[!IF "node:exists(PmuEccEdcTstGeneral/PmuEccEdcTstPF1Select) = 'true'"!][!//     
[!VAR "PmuCount" = "$PmuCount + num:i(1)"!][!//
[!ENDIF!][!//
[!IF "node:exists(PmuEccEdcTstGeneral/PmuEccEdcTstPF2Select) = 'true'"!][!//     
[!VAR "PmuCount" = "$PmuCount + num:i(1)"!][!//
[!ENDIF!][!//
[!IF "node:exists(PmuEccEdcTstGeneral/PmuEccEdcTstPF3Select) = 'true'"!][!//     
[!VAR "PmuCount" = "$PmuCount + num:i(1)"!][!//
[!ENDIF!][!//

/* Max number of flash banks supported: */
#define PFLASH_MON_TST_MAX_FLASHBANKS  ( [!"num:i($PmuCount)"!]U )

[!IF "PmuEccEdcTstGeneral/PmuEccEdcTstEnableFifoBufferFullTest = 'true'"!][!//     
/* FifoBufferFullTest Enabled: */
#define PFLASH_FIFO_BUFFERFULL_TEST_ENABLE
[!ENDIF!][!//

[!ENDSELECT!][!//
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
#endif  /* PFLASHMONTST_CFG_H */
