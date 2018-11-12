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
**   $FILENAME   : PmuEccEdcTst_Cfg.h $                                       **
**                                                                            **
**   $CC VERSION : \main\14 $                                                 **
**                                                                            **
**   $DATE       : 2015-08-11 $                                               **
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
**  DESCRIPTION  : Code template for PmuEccEdcTst_Cfg.h file                  **
**                                                                            **
**  [/cover]                                                                  **
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
**  FILENAME  :  PmuEccEdcTst_Cfg.h                                           **
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
**  DESCRIPTION  : PmuEccEdcTst configuration header file                     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef PMUECCEDCTST_CFG_H
#define PMUECCEDCTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('PmuEccEdcTst')[1]"!][!//. 
[!//

#define PMU_ECC_EDC_TST_PF0_SELECT                  ([!//
[!IF "PmuEccEdcTstGeneral/PmuEccEdcTstPF0Select = 'true'"!][!//
1U[!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
)

#define PMU_ECC_EDC_TST_PF1_SELECT                  ([!//
[!IF "node:exists(PmuEccEdcTstGeneral/PmuEccEdcTstPF1Select) = 'true'"!][!//      
[!IF "PmuEccEdcTstGeneral/PmuEccEdcTstPF1Select = 'true'"!][!//
1U[!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!// 
)

#define PMU_ECC_EDC_TST_PF2_SELECT                  ([!//
[!IF "node:exists(PmuEccEdcTstGeneral/PmuEccEdcTstPF2Select) = 'true'"!][!//      
[!IF "PmuEccEdcTstGeneral/PmuEccEdcTstPF2Select = 'true'"!][!//
1U[!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
) 

#define PMU_ECC_EDC_TST_PF3_SELECT                  ([!//
[!IF "node:exists(PmuEccEdcTstGeneral/PmuEccEdcTstPF3Select) = 'true'"!][!//      
[!IF "PmuEccEdcTstGeneral/PmuEccEdcTstPF3Select = 'true'"!][!//
1U[!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
)

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
/* max number of flash banks supported */
#define PMU_ECC_EDC_TST_MAX_FLASHBANKS  ( [!"num:i($PmuCount)"!]U )

[!IF "PmuEccEdcTstGeneral/PmuEccEdcTstSecurityDisableCustCallback = 'NULL_PTR' "!][!//
[!ELSE!][!//
/*Callback functions are defined for disabling/enabling security*/
#define VALID_FUNCTION_CALLBACK
/*Callback function for disabling security*/
extern void [!"PmuEccEdcTstGeneral/PmuEccEdcTstSecurityDisableCustCallback"!](void);
#define SECURITYDISABLE [!"PmuEccEdcTstGeneral/PmuEccEdcTstSecurityDisableCustCallback"!]
[!ENDIF!]

[!IF "PmuEccEdcTstGeneral/PmuEccEdcTstSecurityEnableCustCallback = 'NULL_PTR' "!][!//
[!ELSE!][!//
/*Callback function for enabling security*/
extern void [!"PmuEccEdcTstGeneral/PmuEccEdcTstSecurityEnableCustCallback"!](void);
#define SECURITYENABLE  [!"PmuEccEdcTstGeneral/PmuEccEdcTstSecurityEnableCustCallback"!]
[!ENDIF!]
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
#endif  /* PMUECCEDCTST_CFG_H */
[!AUTOSPACING!]
