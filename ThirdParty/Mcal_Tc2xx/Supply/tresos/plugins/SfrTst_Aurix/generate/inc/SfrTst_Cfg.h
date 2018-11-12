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
**   $FILENAME   : SfrTst_Cfg.h $                                             **
**                                                                            **
**   $CC VERSION : \main\14 $                                                 **
**                                                                            **
**   $DATE       : 2016-05-04 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SfrTst.bmd/xdm                                    **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SfrTst_Cfg.h file                        **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*************************************************************************/!][!//
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
**  FILENAME  :  SfrTst_Cfg.h                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SfrTst.bmd /xdm                                   **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SfrTst configuration header file                           **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SFRTST_CFG_H
#define SFRTST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Platform_Types.h"
#include "Compiler_Cfg.h"
#include "Mcal.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* number of available configurations for the SFR test                        */
[!SELECT "as:modconf('SfrTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SfrTstConfigSet/*))"!][!//
#define SFR_TST_CFG_PARAM_COUNT     ( [!"$TotalConfig"!]U ) 
#define REGCOUNT_MAX                (112U)
#define CMP_PASS                    ((uint32)0x5U)
#define CMP_FAIL                    ((uint32)0x2U)
#define CMP_NOTRUN                  ((uint32)0U )
#define STL_BIT_32                  ((uint32)0U )
#define STL_BIT_16                  ((uint32)1U )

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef struct SfrTst_Config
{
  /* contains the address of the register to test                             */
  volatile void*    RegisterAddress;
  /* contains the expected register value                                     */
  uint32              RegisterValue;
  /* contains the mask used for the test.This mask allows to omit bits within */
  /* the register                                                             */
  uint32              RegisterMask;
  
  /* Used to select register type */
  
  uint32 			RegisterBitWidth;
}SfrTst_ConfigType;

typedef struct SfrTst_ParamSet
{
  /* gives the number of registers within this set*/
  uint32              NumberOfRegisters2Test;
  /* holds the expected CRC checksum for test 2                               */
  uint32              ExpectedCRCResult;
  /* the actual register configurtion*/
  const SfrTst_ConfigType*  RegisterSet2Test;
}SfrTst_ParamSetType;
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
/* Exported SFR test configuration                                            */
extern const SfrTst_ParamSetType AllAvailableSets[SFR_TST_CFG_PARAM_COUNT];

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
#endif  /* SFRTST_CFG_H */
[!AUTOSPACING!]
