[!/*****************************************************************************
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
**   $FILENAME   : CpuBusMpuLfmTst_LCfg.c $                                   **
**                                                                            **
**   $CC VERSION : \main\17 $                                                 **
**                                                                            **
**   $DATE       : 2014-11-12 $                                               **
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
**  DESCRIPTION  : Code template for CpuBusMpuLfmTst_LCfg.c file              **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*****************************************************************************/!]
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
**  FILENAME  :  CpuBusMpuLfmTst_LCfg.c                                       **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : CpuBusMpuLfmTst.bmd/xdm                           **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CpuBusMpuLfmTst configuration                              **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "CpuBusMpuLfmTst_Cfg.h"

/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

#define IFX_CPUBUSMPULFM_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

[!SELECT "as:modconf('CpuBusMpuLfmTst')[1]"!][!//

[!VAR "TotalConfig" = "num:i(count(CpuBusMpuLfmTstConfigSet/*))"!][!//

[!IF "$derivate = 'TC277' or $derivate = 'TC275' or $derivate = 'TC298' or $derivate = 'TC299' or $derivate = 'TC297'"!]
[!VAR "TotalCpucount" = "num:i(3)"!][!//
[!ELSEIF "$derivate = 'TC264' or $derivate = 'TC265' or $derivate = 'TC267'"!]
[!VAR "TotalCpucount" = "num:i(2)"!][!//	
[!ELSE!]
[!VAR "TotalCpucount" = "num:i(1)"!][!//
[!ENDIF!]	

[!VAR "TotalConfig" = "num:i(count(CpuBusMpuLfmTstConfigSet/*))"!][!//


/* CPU Bus MPU LFM test configuration:                                      */
const CpuBusMpuLfmTst_ConfigType
CpuBusMpuLfmTst_ConfigRoot[CPUBUSMPU_LFM_TST_CFG_PARAM_COUNT] =
{
[!FOR "CpuBusMpuTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "CpuBusMpuLfmTstConfigSet/*[num:i($CpuBusMpuTstId)]"!][!//
  /* CpuBusMpuLfmTst_ConfigRoot[[!"num:i($CpuBusMpuTstId - 1)"!]]:*/
  {
    {
      /* Core0 TestMemory */
      {
        [!FOR "TstId" ="num:i(1)" TO "(num:i(8))"!][!//
        [!SELECT "CpuBusMpuLfmTstTestMemoryCpu0/*[num:i($TstId)]"!][!//
        (uint32*)[!"num:inttohex(CpuBusMpuLfmTstTestMemoryCpu0, 8)"!]U[!IF "$TstId < num:i(8)"!],[!ELSE!] [!ENDIF!][!//

        [!ENDSELECT!][!//
        [!ENDFOR!][!//
      },
      [!IF "$TotalCpucount = num:i(2) or $TotalCpucount = num:i(3)"!]  	  
      /* Core1 TestMemory */
      {
        [!FOR "TstId" ="num:i(1)" TO "(num:i(8))"!][!//
        [!SELECT "CpuBusMpuLfmTstTestMemoryCpu1/*[num:i($TstId)]"!][!//
        (uint32*)[!"num:inttohex(CpuBusMpuLfmTstTestMemoryCpu1, 8)"!]U[!IF "$TstId < num:i(8)"!],[!ELSE!] [!ENDIF!][!//

        [!ENDSELECT!][!//
        [!ENDFOR!][!//
      },  
      [!ENDIF!]      
      [!IF "$TotalCpucount = num:i(3)"!]    
      /* Core2 TestMemory */
      {
        
        [!FOR "TstId" ="num:i(1)" TO "(num:i(8))"!][!//
        [!SELECT "CpuBusMpuLfmTstTestMemoryCpu2/*[num:i($TstId)]"!][!//
        (uint32*)[!"num:inttohex(CpuBusMpuLfmTstTestMemoryCpu2, 8)"!]U[!IF "$TstId < num:i(8)"!],[!ELSE!] [!ENDIF!][!//

        [!ENDSELECT!][!//
        [!ENDFOR!][!//       
      }
      [!ENDIF!]
    },
    {     
      /*  Unauthorized Addr Cpu0 */
      {
        (uint32*)[!"num:inttohex(CpuBusMpuLfmTstUnauthorizedAddrCpu0/CpuBusMpuLfmTstUnauthorizedAddrCpu0)"!]U,
      },
      [!IF "$TotalCpucount = num:i(2) or $TotalCpucount = num:i(3)"!]    
      /*  Unauthorized Addr Cpu1 */
      {
        (uint32*)[!"num:inttohex(CpuBusMpuLfmTstUnauthorizedAddrCpu1/CpuBusMpuLfmTstUnauthorizedAddrCpu1)"!]U,
      }, 
      [!ENDIF!]  
      [!IF "$TotalCpucount = num:i(3)"!]    
      /*  Unauthorized Addr Cpu1 */
      {
        (uint32*)[!"num:inttohex(CpuBusMpuLfmTstUnauthorizedAddrCpu2/CpuBusMpuLfmTstUnauthorizedAddrCpu2)"!]U,
      }, 
      [!ENDIF!]   
    }
  }[!IF "$CpuBusMpuTstId < num:i($TotalConfig)"!],[!ELSE!][!ENDIF!][!//
  
[!ENDSELECT!][!//    
[!ENDFOR!][!//   
};

[!ENDSELECT!][!//
[!AUTOSPACING!]    

#define IFX_CPUBUSMPULFM_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
