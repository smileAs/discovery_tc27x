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
**   $FILENAME   : CpuBusMpuLfmTst_Cfg.h $                                    **
**                                                                            **
**   $CC VERSION : \main\6 $                                                  **
**                                                                            **
**   $DATE       : 2014-04-08 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuBusMpuLfmTst.bmd/xdm                           **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for CpuBusMpuLfmTst_Cfg.h file               **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
**************************************************************************/!][!//
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
**  FILENAME  :  CpuBusMpuLfmTst_Cfg.h                                        **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuBusMpuLfmTst.bmd /xdm                          **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CpuBusMpuLfmTst configuration header file                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef CPUBUSMPULFMTST_CFG_H
#define CPUBUSMPULFMTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Platform_Types.h"
#include "Compiler_Cfg.h"
#include "CpuBusMpuLfmTst.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!SELECT "as:modconf('CpuBusMpuLfmTst')[1]"!][!//

[!VAR "TotalConfig" = "num:i(count(CpuBusMpuLfmTstConfigSet/*))"!][!//

/* Number of different test configuration sets */
#define CPUBUSMPU_LFM_TST_CFG_PARAM_COUNT        ( [!"num:i($TotalConfig)"!] )


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
/* Exported Bus MPU LFM test configuration:                                 */
extern const CpuBusMpuLfmTst_ConfigType
CpuBusMpuLfmTst_ConfigRoot[CPUBUSMPU_LFM_TST_CFG_PARAM_COUNT];

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
#endif  /* CPUBUSMPULFMTST_CFG_H */
[!AUTOSPACING!]
