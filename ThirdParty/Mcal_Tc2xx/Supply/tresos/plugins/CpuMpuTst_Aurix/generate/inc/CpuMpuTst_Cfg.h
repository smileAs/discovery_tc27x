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
**   $FILENAME   : CpuMpuTst_Cfg.h $                                          **
**                                                                            **
**   $CC VERSION : \main\9 $                                                  **
**                                                                            **
**   $DATE       : 2014-08-09 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuMpuTst.bmd/xdm                                 **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for CpuMpuTst_Cfg.h file                     **
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
**  FILENAME  :  CpuMpuTst_Cfg.h                                              **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuMpuTst.bmd /xdm                                **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CpuMpuTst configuration header file                        **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef CPUMPUTST_CFG_H
#define CPUMPUTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!SELECT "as:modconf('CpuMpuTst')[1]"!][!//

[!VAR "TotalConfig" = "num:i(count(CpuMpuTstConfigSet/*))"!][!//

/* Set of protection registers (DPRE_x, DPWE_x, CPXE_x) to use for testing
   Valid Range: 0..3
*/
#define CPU_MPU_TST_PROT_REGISTER_SET               ( [!"(CpuMpuTstGeneral/CpuMpuTstProtRegisterSet)"!]U )

/* Total number of data protection ranges available:                        */
#define CPU_MPU_TST_DATA_RANGE_COUNT                ( 16U )

/* Total number of code protection ranges available:                        */
#define CPU_MPU_TST_CODE_RANGE_COUNT                ( 8U )

/* Number of different test configuration sets:                             */
#define CPU_MPU_TST_CFG_PARAM_COUNT                 ( [!"num:i($TotalConfig)"!]U )
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
#endif  /* CPUMPUTST_CFG_H */
[!AUTOSPACING!]
