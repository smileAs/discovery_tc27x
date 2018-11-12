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
**   $FILENAME   : SpbTst_LCfg.c $                                            **
**                                                                            **
**   $CC VERSION : \main\27 $                                                 **
**                                                                            **
**   $DATE       : 2016-08-16 $                                               **
**                                                                            **
**  BSW MODULE DESCRIPTION : SpbTst.bmd/xdm                                   **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SpbTst_LCfg.c file                       **
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
**  FILENAME  : SpbTst_LCfg.c                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DESCRIPTION : SpbTst.bmd/xdm                                   **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SpbTst configuration                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include module header File */ 
#include "SpbTst_Cfg.h"
#include "SpbTst.h"
[!VAR "ModHeaderInclMultiCAN" = "num:i(0)"!][!//
[!VAR "ModHeaderInclASCLIN" = "num:i(0)"!][!//
[!VAR "ModHeaderInclQSPI" = "num:i(0)"!][!//
[!VAR "ModHeaderInclGTM" = "num:i(0)"!][!//
[!VAR "ModHeaderInclMSC" = "num:i(0)"!][!//
[!VAR "ModHeaderInclETHMAC" = "num:i(0)"!][!//
[!VAR "ModHeaderInclI2C" = "num:i(0)"!][!//
[!VAR "ModHeaderInclSENT" = "num:i(0)"!][!//
[!VAR "ModHeaderInclERAY" = "num:i(0)"!][!//
[!VAR "ModHeaderInclCCU6" = "num:i(0)"!][!//
[!VAR "ModHeaderInclPSI5" = "num:i(0)"!][!//
[!VAR "ModHeaderInclPSI5_S" = "num:i(0)"!][!//
[!VAR "ModHeaderInclGPT12" = "num:i(0)"!][!//
[!VAR "ModHeaderInclPORT" = "num:i(0)"!][!//
[!VAR "ModHeaderInclSMU" = "num:i(0)"!][!//
[!VAR "ModHeaderInclIOM" = "num:i(0)"!][!//
[!VAR "ModHeaderInclFCE" = "num:i(0)"!][!//
[!VAR "ModHeaderInclSTM" = "num:i(0)"!][!//
[!VAR "ModHeaderInclIR" = "num:i(0)"!][!//
[!VAR "ModHeaderInclDSADC" = "num:i(0)"!][!//
[!VAR "ModHeaderInclVADC" = "num:i(0)"!][!//
[!VAR "ModHeaderInclSCU" = "num:i(0)"!][!//
[!VAR "ModHeaderInclMTU" = "num:i(0)"!][!//
[!VAR "ModHeaderInclHSSL" = "num:i(0)"!][!//
[!VAR "ModHeaderInclHSCT" = "num:i(0)"!][!//
[!VAR "ModHeaderInclSBCU" = "num:i(0)"!][!//
[!VAR "ModHeaderInclDMA" = "num:i(0)"!][!//
[!VAR "ModHeaderInclXBAR" = "num:i(0)"!][!//
[!VAR "ModHeaderInclPMU" = "num:i(0)"!][!//

/* SPB test configuration:  */
[!SELECT "as:modconf('SpbTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SpbTstConfigSet/*))"!][!//
[!FOR "SpbTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SpbTstConfigSet/*[num:i($SpbTstId)]"!][!//
[!IF "MultiCANTestEn = 'true'"!][!//
[!VAR "ModHeaderInclMultiCAN" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "ASCLIN0TestEn = 'true' or ASCLIN1TestEn = 'true' or ASCLIN2TestEn = 'true' or ASCLIN3TestEn = 'true'"!][!//
[!VAR "ModHeaderInclASCLIN" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "QSPI0TestEn = 'true' or QSPI1TestEn = 'true' or QSPI2TestEn = 'true' or QSPI3TestEn = 'true' or QSPI4TestEn = 'true' or QSPI5TestEn = 'true'"!][!//
[!VAR "ModHeaderInclQSPI" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "GTMTestEn = 'true'"!][!//
[!VAR "ModHeaderInclGTM" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "MSC0TestEn = 'true' or MSC1TestEn = 'true'"!][!//
[!VAR "ModHeaderInclMSC" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "EtherMacTestEn = 'true'"!][!//
[!VAR "ModHeaderInclETHMAC" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "I2CTestEn = 'true'"!][!//
[!VAR "ModHeaderInclI2C" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "SENTTestEn = 'true'"!][!//
[!VAR "ModHeaderInclSENT" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "ERay0TestEn = 'true' or ERay1TestEn = 'true'"!][!//
[!VAR "ModHeaderInclERAY" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "CCU60TestEn = 'true' or CCU61TestEn = 'true'"!][!//
[!VAR "ModHeaderInclCCU6" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "PSI5TestEn = 'true'"!][!//
[!VAR "ModHeaderInclPSI5" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "PSI5_STestEn = 'true'"!][!//
[!VAR "ModHeaderInclPSI5_S" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "GPT12TestEn = 'true'"!][!//
[!VAR "ModHeaderInclGPT12" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "Port00TestEn = 'true' or Port01TestEn = 'true' or Port02TestEn = 'true' or Port10TestEn = 'true' or Port11TestEn = 'true' or Port12TestEn = 'true' or Port13TestEn = 'true' or Port14TestEn = 'true' or Port15TestEn = 'true' or Port20TestEn = 'true' or Port21TestEn = 'true' or Port22TestEn = 'true' or Port23TestEn = 'true' or Port24TestEn = 'true' or Port25TestEn = 'true' or Port26TestEn = 'true' or Port30TestEn = 'true' or Port31TestEn = 'true' or Port32TestEn = 'true' or Port33TestEn = 'true' or Port34TestEn = 'true' or Port40TestEn = 'true' or Port41TestEn = 'true'"!][!//
[!VAR "ModHeaderInclPORT" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "SMUTestEn = 'true'"!][!//
[!VAR "ModHeaderInclSMU" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "IOMTestEn = 'true'"!][!//
[!VAR "ModHeaderInclIOM" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "FCETestEn = 'true'"!][!//
[!VAR "ModHeaderInclFCE" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "STM0TestEn = 'true' or STM1TestEn = 'true'"!][!//
[!VAR "ModHeaderInclSTM" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "IntRouter0TestEn = 'true' or IntRouter1TestEn = 'true'"!][!//
[!VAR "ModHeaderInclIR" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "DSADCxTestEn = 'true'"!][!//
[!VAR "ModHeaderInclDSADC" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "VADCxTestEn = 'true'"!][!//
[!VAR "ModHeaderInclVADC" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "SCUTestEn = 'true'"!][!//
[!VAR "ModHeaderInclSCU" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "MTUTestEn = 'true'"!][!//
[!VAR "ModHeaderInclMTU" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "HSSLTestEn = 'true'"!][!//
[!VAR "ModHeaderInclHSSL" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "HSCTTestEn = 'true'"!][!//
[!VAR "ModHeaderInclHSCT" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "SBCUTestEn = 'true'"!][!//
[!VAR "ModHeaderInclSBCU" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "DMATestEn = 'true'"!][!//
[!VAR "ModHeaderInclDMA" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "XBARTestEn = 'true'"!][!//
[!VAR "ModHeaderInclXBAR" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "PMUTestEn = 'true'"!][!//
[!VAR "ModHeaderInclPMU" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!//
/* Number of different test configuration sets */
[!IF "($ModHeaderInclMultiCAN) = num:i(1)"!][!//
#include "IfxCan_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclASCLIN) = num:i(1)"!][!//
#include "IfxAsclin_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclQSPI) = num:i(1)"!][!//
#include "IfxQspi_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclGTM) = num:i(1)"!][!//
#include "IfxGtm_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclMSC) = num:i(1)"!][!//
#include "IfxMsc_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclETHMAC) = num:i(1)"!][!//
#include "IfxEth_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclI2C) = num:i(1)"!][!//
#include "IfxI2c_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclSENT) = num:i(1)"!][!//
#include "IfxSent_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclERAY) = num:i(1)"!][!//
#include "IfxEray_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclCCU6) = num:i(1)"!][!//
#include "IfxCcu6_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclPSI5) = num:i(1)"!][!//
#include "IfxPsi5_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclPSI5_S) = num:i(1)"!][!//
#include "IfxPsi5s_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclGPT12) = num:i(1)"!][!//
#include "IfxGpt12_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclPORT) = num:i(1)"!][!//
#include "IfxPort_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclSMU) = num:i(1)"!][!//
#include "IfxSmu_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclIOM) = num:i(1)"!][!//
#include "IfxIom_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclFCE) = num:i(1)"!][!//
#include "IfxFce_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclSTM) = num:i(1)"!][!//
#include "IfxStm_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclIR) = num:i(1)"!][!//
#include "IfxInt_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclDSADC) = num:i(1)"!][!//
#include "IfxDsadc_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclVADC) = num:i(1)"!][!//
#include "IfxVadc_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclSCU) = num:i(1)"!][!//
#include "IfxScu_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclMTU) = num:i(1)"!][!//
#include "IfxMtu_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclHSSL) = num:i(1)"!][!//
#include "IfxHssl_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclHSCT) = num:i(1)"!][!//
#include "IfxHsct_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclSBCU) = num:i(1)"!][!//
#include "IfxSbcu_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclDMA) = num:i(1)"!][!//
#include "IfxDma_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclXBAR) = num:i(1)"!][!//
#include "IfxXbar_reg.h"
[!ENDIF!][!//
[!IF "($ModHeaderInclPMU) = num:i(1)"!][!//
#include "IfxFlash_reg.h"
[!ENDIF!][!//
/*******************************************************************************
**                      Inclusion File Check                                  **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
#define IFX_SPBTST_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
[!VAR "IsRmc_AvailableEnabled" = "num:i(0)"!]
[!VAR "IsRmc_Not_AvailableEnabled" = "num:i(0)"!]
[!VAR "TotalConfig" = "num:i(count(SpbTstConfigSet/*))"!][!//
[!FOR "SpbTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SpbTstConfigSet/*[num:i($SpbTstId)]"!][!//
[!IF "I2CTestEn = 'true' or SENTTestEn = 'true' or ERay0TestEn = 'true' or ERay1TestEn = 'true' or IOMTestEn = 'true'"!][!//
[!VAR "IsRmc_AvailableEnabled" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "MultiCANTestEn = 'true' or ASCLIN0TestEn = 'true' or ASCLIN1TestEn = 'true' or ASCLIN2TestEn = 'true' or ASCLIN3TestEn = 'true' or QSPI0TestEn = 'true' or QSPI1TestEn = 'true' or QSPI2TestEn = 'true' or QSPI3TestEn = 'true' or QSPI4TestEn = 'true' or QSPI5TestEn = 'true' or GTMTestEn = 'true' or SpbPeripheralCfgPtr_1.MSC0TestEn = 'true' or MSC0TestEn = 'true' or MSC1TestEn = 'true' or EtherMacTestEn = 'true' or CCU60TestEn = 'true' or CCU61TestEn = 'true' or PSI5TestEn = 'true' or PSI5_STestEn = 'true' or GPT12TestEn = 'true' or Port00TestEn = 'true' or Port01TestEn = 'true' or Port02TestEn = 'true' or Port10TestEn = 'true' or Port11TestEn = 'true' or Port12TestEn = 'true' or Port13TestEn = 'true' or Port14TestEn = 'true' or Port15TestEn = 'true' or Port20TestEn = 'true' or Port21TestEn = 'true' or Port22TestEn = 'true' or Port23TestEn = 'true' or Port24TestEn = 'true' or Port25TestEn = 'true' or Port26TestEn = 'true' or Port30TestEn = 'true' or Port31TestEn = 'true' or Port32TestEn = 'true' or Port33TestEn = 'true' or Port34TestEn = 'true' or Port40TestEn = 'true' or Port41TestEn = 'true' or SMUTestEn = 'true' or FCETestEn = 'true' or STM0TestEn = 'true' or STM1TestEn = 'true' or STM2TestEn = 'true' or IntRouter0TestEn = 'true' or IntRouter1TestEn = 'true' or DSADCxTestEn = 'true' or VADCxTestEn = 'true' or SCUTestEn = 'true' or MTUTestEn = 'true' or HSSLTestEn = 'true' or HSCTTestEn = 'true' or SBCUTestEn = 'true' or DMATestEn = 'true' or XBARTestEn = 'true' or PMUTestEn = 'true'"!][!//
[!VAR "IsRmc_Not_AvailableEnabled" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!IF "$IsRmc_Not_AvailableEnabled = num:i(1)"!][!//
static unsigned_int Rmc_Not_Available = 0U;
[!ENDIF!][!//
[!IF "$IsRmc_AvailableEnabled = num:i(1)"!][!//
static unsigned_int Rmc_Available = 1U;
[!ENDIF!][!//

#define IFX_SPBTST_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define IFX_SPBTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

[!VAR "TotalConfig" = "num:i(count(SpbTstConfigSet/*))"!][!//

[!FOR "SpbTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SpbTstConfigSet/*[num:i($SpbTstId)]"!][!//
/* SpbTest configuration  */
static const SpbTst_AccEnType SpbPeripheralCfgPtr_[!"num:i($SpbTstId)"!][] =
{
  /* Number of different test configuration sets */
[!IF "MultiCANTestEn = 'true'"!]
  {&CAN_CLC.U, &CAN_ACCEN0.U, &CAN_MCR.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "ASCLIN0TestEn = 'true'"!][!//
  {&ASCLIN0_CLC.U, &ASCLIN0_ACCEN0.U, &ASCLIN0_DATCON.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "ASCLIN1TestEn = 'true'"!][!//
  {&ASCLIN1_CLC.U, &ASCLIN1_ACCEN0.U, &ASCLIN1_DATCON.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "ASCLIN2TestEn = 'true'"!][!//
  {&ASCLIN2_CLC.U, &ASCLIN2_ACCEN0.U, &ASCLIN2_DATCON.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "ASCLIN3TestEn = 'true'"!][!//
  {&ASCLIN3_CLC.U, &ASCLIN3_ACCEN0.U, &ASCLIN3_DATCON.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "QSPI0TestEn = 'true'"!][!//
  {&QSPI0_CLC.U, &QSPI0_ACCEN0.U, &QSPI0_PISEL.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "QSPI1TestEn = 'true'"!][!//
  {&QSPI1_CLC.U, &QSPI1_ACCEN0.U, &QSPI1_PISEL.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "QSPI2TestEn = 'true'"!][!//
  {&QSPI2_CLC.U, &QSPI2_ACCEN0.U, &QSPI2_PISEL.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "QSPI3TestEn = 'true'"!][!//
  {&QSPI3_CLC.U, &QSPI3_ACCEN0.U, &QSPI3_PISEL.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "QSPI4TestEn = 'true'"!][!//
  {&QSPI4_CLC.U, &QSPI4_ACCEN0.U, &QSPI4_PISEL.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "QSPI5TestEn = 'true'"!][!//
  {&QSPI5_CLC.U, &QSPI5_ACCEN0.U, &QSPI5_PISEL.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "GTMTestEn = 'true'"!][!//
  {&GTM_CLC.U, &GTM_ACCEN0.U, &GTM_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "SpbPeripheralCfgPtr_1.MSC0TestEn = 'true'"!][!//
  {&MSC0_CLC.U, &MSC0_ACCEN0.U, &MSC0_ICR.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "MSC0TestEn = 'true'"!][!//
  {&MSC0_CLC.U, &MSC0_ACCEN0.U, &MSC0_ICR.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "MSC1TestEn = 'true'"!][!//
  {&MSC1_CLC.U, &MSC1_ACCEN0.U, &MSC1_ICR.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "EtherMacTestEn = 'true'"!][!//
  {&ETH_CLC.U, &ETH_ACCEN0.U, &ETH_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "I2CTestEn = 'true'"!][!//
  {&I2C0_CLC.U, &I2C0_ACCEN0.U, &I2C0_KRST0.U, &Rmc_Available},
[!ENDIF!][!//
[!IF "SENTTestEn = 'true'"!][!//
  {&SENT_CLC.U, &SENT_ACCEN0.U, &SENT_FDR.U, &Rmc_Available},
[!ENDIF!][!//
[!IF "ERay0TestEn = 'true'"!][!//
  {&ERAY0_CLC.U, &ERAY0_ACCEN0.U, &ERAY0_KRST0.U, &Rmc_Available},
[!ENDIF!][!//
[!IF "ERay1TestEn = 'true'"!][!//
  {&ERAY1_CLC.U, &ERAY1_ACCEN0.U, &ERAY1_KRST0.U, &Rmc_Available},
[!ENDIF!][!//
[!IF "CCU60TestEn = 'true'"!][!//
  {&CCU60_CLC.U, &CCU60_ACCEN0.U, &CCU60_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "CCU61TestEn = 'true'"!][!//
  {&CCU61_CLC.U, &CCU61_ACCEN0.U, &CCU61_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "PSI5TestEn = 'true'"!][!//
  {&PSI5_CLC.U, &PSI5_ACCEN0.U, &PSI5_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "PSI5_STestEn = 'true'"!][!//
  {&PSI5S_CLC.U, &PSI5S_ACCEN0.U, &PSI5S_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "GPT12TestEn = 'true'"!][!//
  {&GPT120_CLC.U, &GPT120_ACCEN0.U, &GPT120_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port00TestEn = 'true'"!][!//
  {NULL_PTR, &P00_ACCEN0.U, &P00_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port01TestEn = 'true'"!][!//
  {NULL_PTR, &P01_ACCEN0.U, &P01_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port02TestEn = 'true'"!][!//
  {NULL_PTR, &P02_ACCEN0.U, &P02_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port10TestEn = 'true'"!][!//
  {NULL_PTR, &P10_ACCEN0.U, &P10_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port11TestEn = 'true'"!][!//
  {NULL_PTR, &P11_ACCEN0.U, &P11_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port12TestEn = 'true'"!][!//
  {NULL_PTR, &P12_ACCEN0.U, &P12_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port13TestEn = 'true'"!][!//
  {NULL_PTR, &P13_ACCEN0.U, &P13_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port14TestEn = 'true'"!][!//
  {NULL_PTR, &P14_ACCEN0.U, &P14_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port15TestEn = 'true'"!][!//
  {NULL_PTR, &P15_ACCEN0.U, &P15_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port20TestEn = 'true'"!][!//
  {NULL_PTR, &P20_ACCEN0.U, &P20_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port21TestEn = 'true'"!][!//
  {NULL_PTR, &P21_ACCEN0.U, &P21_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port22TestEn = 'true'"!][!//
  {NULL_PTR, &P22_ACCEN0.U, &P22_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port23TestEn = 'true'"!][!//
  {NULL_PTR, &P23_ACCEN0.U, &P23_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port24TestEn = 'true'"!][!//
  {NULL_PTR, &P24_ACCEN0.U, &P24_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port25TestEn = 'true'"!][!//
  {NULL_PTR, &P25_ACCEN0.U, &P25_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port26TestEn = 'true'"!][!//
  {NULL_PTR, &P26_ACCEN0.U, &P26_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port30TestEn = 'true'"!][!//
  {NULL_PTR, &P30_ACCEN0.U, &P30_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port31TestEn = 'true'"!][!//
  {NULL_PTR, &P31_ACCEN0.U, &P31_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port32TestEn = 'true'"!][!//
  {NULL_PTR, &P32_ACCEN0.U, &P32_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port33TestEn = 'true'"!][!//
  {NULL_PTR, &P33_ACCEN0.U, &P33_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port34TestEn = 'true'"!][!//
  {NULL_PTR, &P34_ACCEN0.U, &P34_OUT.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port40TestEn = 'true'"!][!//
  {NULL_PTR, &P40_ACCEN0.U, &P40_IOCR0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "Port41TestEn = 'true'"!][!//
  {NULL_PTR, &P41_ACCEN0.U, &P41_IOCR0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "SMUTestEn = 'true'"!][!//
  {&SMU_CLC.U, &SMU_ACCEN0.U, &SMU_CMD.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "IOMTestEn = 'true'"!][!//
  {&IOM_CLC.U, &IOM_ACCEN0.U, &IOM_KRST0.U, &Rmc_Available},
[!ENDIF!][!//
[!IF "FCETestEn = 'true'"!][!//
  {&FCE_CLC.U, &FCE_ACCEN0.U, &FCE_IR0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "STM0TestEn = 'true'"!][!//
  {&STM0_CLC.U, &STM0_ACCEN0.U, &STM0_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "STM1TestEn = 'true'"!][!//
  {&STM1_CLC.U, &STM1_ACCEN0.U, &STM1_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "STM2TestEn = 'true'"!][!//
  {&STM2_CLC.U, &STM2_ACCEN0.U, &STM2_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "IntRouter0TestEn = 'true'"!][!//
  {NULL_PTR, &INT_ACCEN00.U, &INT_SRB0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "IntRouter1TestEn = 'true'"!][!//
  {NULL_PTR, &INT_ACCEN10.U, &INT_ECR0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "DSADCxTestEn = 'true'"!][!//
  {&DSADC_CLC.U, &DSADC_ACCEN0.U, &DSADC_GLOBCFG.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "VADCxTestEn = 'true'"!][!//
  {&VADC_CLC.U, &VADC_ACCEN0.U, &VADC_GLOBCFG.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "SCUTestEn = 'true'"!][!//
  {NULL_PTR, &SCU_ACCEN0.U, &SCU_LCLTEST.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "MTUTestEn = 'true'"!][!//
  {&MTU_CLC.U, &MTU_ACCEN0.U, &MTU_MEMTEST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "HSSLTestEn = 'true'"!][!//
  {&HSSL_CLC.U, &HSSL_ACCEN0.U, &HSSL_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "HSCTTestEn = 'true'"!][!//
  {&HSCT_CLC.U, &HSCT_ACCEN0.U, &HSCT_KRST0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "SBCUTestEn = 'true'"!][!//
  {NULL_PTR, &SBCU_ACCEN0.U, &SBCU_CON.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "DMATestEn = 'true'"!][!//
  {&DMA_CLC.U, &DMA_ACCEN00.U, &DMA_MEMCON.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "XBARTestEn = 'true'"!][!//
  {NULL_PTR, &XBAR_ACCEN0.U, &XBAR_ARBCON0.U, &Rmc_Not_Available},
[!ENDIF!][!//
[!IF "PMUTestEn = 'true'"!][!//
  {NULL_PTR, &FLASH0_ACCEN0.U, &FLASH0_FPRO.U, &Rmc_Not_Available},
[!ENDIF!][!//
};


static const uint32 SmuAlarm_[!"num:i($SpbTstId)"!][] =
{
  /* Number of different test configuration sets */
[!IF "MultiCANTestEn = 'true'"!]
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "ASCLIN0TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "ASCLIN1TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "ASCLIN2TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "ASCLIN3TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "QSPI0TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "QSPI1TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "QSPI2TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "QSPI3TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "QSPI4TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "QSPI5TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "GTMTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "MSC0TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "MSC1TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "EtherMacTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "I2CTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "SENTTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "ERay0TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "ERay1TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "CCU60TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "CCU61TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "PSI5TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "PSI5_STestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "GPT12TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port00TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port01TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port02TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port10TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port11TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port12TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port13TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port14TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port15TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port20TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port21TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port22TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port23TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port24TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port25TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port26TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port30TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port31TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port32TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port33TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port34TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port40TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "Port41TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "SMUTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "IOMTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "FCETestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "STM0TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "STM1TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "STM2TestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "IntRouter0TestEn = 'true'"!][!//
  SPBTST_SPB_ACC_ENB_ERR_STS,
[!ENDIF!][!//
  [!IF "IntRouter1TestEn = 'true'"!][!//
  SPBTST_SPB_ACC_ENB_ERR_STS,
[!ENDIF!][!//
[!IF "DSADCxTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "VADCxTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "SCUTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "MTUTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "HSSLTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "HSCTTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "SBCUTestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "DMATestEn = 'true'"!][!//
  SPBTST_SPB_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "XBARTestEn = 'true'"!][!//
  SPBTST_SRI_BUS_ERR_STS,
[!ENDIF!][!//
[!IF "PMUTestEn = 'true'"!][!//
  SPBTST_SRI_BUS_ERR_STS,
[!ENDIF!][!//

};
[!ENDSELECT!][!//    
[!ENDFOR!][!//
/* The index given in the API function is used to choose which */
/* configuration is used from config root                 */
const SpbTst_ConfigType SpbTst_ConfigRoot[[!"$TotalConfig"!]] =
{
[!FOR "SpbTstId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SpbTstConfigSet/*[num:i($SpbTstId)]"!][!//
[!VAR "SpbTstRegister" = "num:i(0)"!][!//
[!IF "MultiCANTestEn = 'true'"!]
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "ASCLIN0TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "ASCLIN1TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "ASCLIN2TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "ASCLIN3TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "QSPI0TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "QSPI1TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "QSPI2TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "QSPI3TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "QSPI4TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "QSPI5TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "GTMTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "MSC0TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "MSC1TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "EtherMacTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "I2CTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "SENTTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "ERay0TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "ERay1TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "CCU60TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "CCU61TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "PSI5TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "PSI5_STestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "GPT12TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port00TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port01TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port02TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port10TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port11TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port12TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port13TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port14TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port15TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port20TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port21TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port22TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port23TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port24TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port25TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port26TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port30TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port31TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port32TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port33TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port34TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port40TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "Port41TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "SMUTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "IOMTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "FCETestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "STM0TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "STM1TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "STM2TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "IntRouter0TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "IntRouter1TestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "DSADCxTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "VADCxTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "SCUTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "MTUTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "HSSLTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "HSCTTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "SBCUTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "DMATestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "XBARTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
[!IF "PMUTestEn = 'true'"!][!//
[!VAR "SpbTstRegister" = "$SpbTstRegister+1"!][!//
[!ENDIF!][!//
  {
    SpbPeripheralCfgPtr_[!"$SpbTstId"!],
    [!"num:i($SpbTstRegister)"!]U,
    SmuAlarm_[!"$SpbTstId"!]
  }[!IF "$SpbTstId < $TotalConfig"!],
 [!ELSE!]
 [!VAR "SpbTstId" = "num:i(0)"!] 
 [!ENDIF!]

[!ENDSELECT!][!//    
[!ENDFOR!][!// 
};
[!ENDSELECT!][!//
[!AUTOSPACING!]
#define IFX_SPBTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"



/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
