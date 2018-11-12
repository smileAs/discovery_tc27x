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
**   $FILENAME   : SafeWdgQspi_Cfg.h $                                        **
**                                                                            **
**   $CC VERSION : \main\6 $                                                  **
**                                                                            **
**   $DATE       : 2015-05-21 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgQspi.bmd/xdm                             **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SafeWdgQspi_Cfg.h file                 **
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
**  FILENAME  :  SafeWdgQspi_Cfg.h                                          **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : SafeWdgQspi.bmd /xdm                            **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/HighTec/WindRiver                                     **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SafeWdgQspi configuration header file                    **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SAFEWDGQSPI_CFG_H
#define SAFEWDGQSPI_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "IfxQspi_reg.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!SELECT "as:modconf('SafeWdgQspi')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SafeWdgQspiChannelConfigSet/*))"!][!//


#define SAFEWDGQSPI_CFG_COUNT			   	 ([!"$TotalConfig"!]U)

[!IF "SafeWdgQspiConfigSet/SafeWdgQspiDmaUsed = 'true'"!][!//    
/* DMA mode selected */        
#define SAFEWDGQSPI_DMAUSED             
[!ENDIF!][!//          

     
                    

[!IF "SafeWdgQspiConfigSet/SafeWdgQspiCustCallback = 'NULL_PTR' "!][!//
[!ELSE!][!//
extern void [!"SafeWdgQspiConfigSet/SafeWdgQspiCustCallback"!]();
[!ENDIF!]


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
#endif  /*SAFEWDGQSPI_CFG_H */
[!AUTOSPACING!]

