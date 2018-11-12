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
**   $FILENAME   : CpuSbstTst_Cfg.h $                                         **
**                                                                            **
**   $CC VERSION : \main\8 $                                                  **
**                                                                            **
**   $DATE       : 2016-07-26 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuSbstTst.bmd/xdm                                   **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for CpuSbstTst_Cfg.h file                       **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/!][!//
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
**  FILENAME  :  CpuSbstTst_Cfg.h                                             **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuSbstTst.bmd /xdm                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CpuSbstTst configuration header file                       **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef CPUSBSTTST_CFG_H
#define CPUSBSTTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!SELECT "as:modconf('CpuSbstTst')[1]"!][!//

[!VAR "SymbolicName1" = "CpuSbstTstGeneral/CpuSbstTstEnterSafeTcore"!]
[!VAR "SymbolicName2" = "CpuSbstTstGeneral/CpuSbstTstExitSafeTcore"!]
[!IF "(($SymbolicName1 = 'NULL_PTR')and($SymbolicName2 = 'NULL_PTR'))"!][!//
/* Notification Function is a NULL */
[!ELSE!][!//
#define CPUSBSTTST_NOTIFICATION
[!ENDIF!][!//

/* Sbst Enter SafeTcore	*/ 
#define CPUSBSTTST_ENTER_NOTIF ( [!"$SymbolicName1"!] ) 

/* Sbst Exit SafeTcore	*/
#define CPUSBSTTST_EXIT_NOTIF  ( [!"$SymbolicName2"!] ) 
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Expected SBST CRC Value*/
/*SBST Expected CRC value is based on the DSPR and PSPR memory location, the 
default Expected CRC value used in safetlib is based on the SBST DSPR 0xd0000000 
to 0xd0000100 and SBST PSPR 0xc0000000 to 0xc0000040, if user changes the DSPR 
and PSPR memory location then the expected CRC value to be updated accordingly*/
[!VAR "CpuSbstTstExpCrcValue" = "num:inttohex(CpuSbstTstGeneral/CpuSbstTstExpectedCrcValue)"!]
#define SBST_EXPECTED_CRC_VALUE ([!"$CpuSbstTstExpCrcValue"!]U)
[!IF "node:exists(CpuSbstTstGeneral/CpuSbstPTstExpectedCrcValue) = 'true'"!]
[!VAR "CpuSbstPTstExpCrcValue" = "num:inttohex(CpuSbstTstGeneral/CpuSbstPTstExpectedCrcValue)"!]
#define SBST_PTST_EXPECTED_CRC_VALUE ([!"$CpuSbstPTstExpCrcValue"!]U)
[!ENDIF!]
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

/* Notification Function for CpuSbstTstEnterSafeTcore notification */
[!VAR "SymbolicName1" = "CpuSbstTstGeneral/CpuSbstTstEnterSafeTcore"!][!//
[!IF "$SymbolicName1 != 'NULL_PTR'"!][!//
extern void [!"$SymbolicName1"!](void);
[!ELSE!][!//
/* Notification Function is a NULL */
[!ENDIF!][!//


/* Notification Function for CpuSbstTstExitSafeTcore notification */
[!VAR "SymbolicName2" = "CpuSbstTstGeneral/CpuSbstTstExitSafeTcore"!][!//
[!IF "$SymbolicName2 != 'NULL_PTR'"!][!//
extern void [!"$SymbolicName2"!](void);
[!ELSE!][!//
/* Notification Function is a NULL */
[!ENDIF!][!//
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!][!//
#endif  /* CPUSBSTTST_CFG_H */
[!AUTOSPACING!]
