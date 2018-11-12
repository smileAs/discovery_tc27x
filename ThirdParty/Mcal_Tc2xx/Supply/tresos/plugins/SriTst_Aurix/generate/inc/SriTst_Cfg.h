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
**   $FILENAME   : SriTst_Cfg.h $                                             **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
**                                                                            **
**   $DATE       : 2015-11-21 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : SriTst.bmd/xdm                                    **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for SriTst_Cfg.h file                        **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
***************************************************************************/!][!//
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
**  FILENAME  : SriTst_Cfg.h                                                  **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SriTst.bmd /xdm                                   **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SriTst configuration header file                           **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SRITST_CFG_H
#define SRITST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/



/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!SELECT "as:modconf('SriTst')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SriTstConfigSet/*))"!][!//

/* Number of different test configuration sets */
#define SRI_EDC_BUSERR_TST_CFG_PARAM_COUNT        ( [!"$TotalConfig"!]U )

/* These definitions are dependent on the user configuration.                 */
[!VAR "DMA_CHANNEL_NUM" = "SriTstGeneral/SriTstDMAChannelNum"!][!//
[!IF "$DMA_CHANNEL_NUM <= num:i(9)"!][!//
/* DMA Channel Configuration  */
#define DMA_CONFIG_SRI        ([!"concat('DMA_CHCFGR00',$DMA_CHANNEL_NUM,'')"!])
/* DMA Channel Source Address            */
#define DMA_SOURCE_SRI        ([!"concat('DMA_SADR00',$DMA_CHANNEL_NUM,'')"!])
/* DMA Channel Destination Address       */
#define DMA_DESTINATION_SRI   ([!"concat('DMA_DADR00',$DMA_CHANNEL_NUM,'')"!])
/* DMA Channel Control/Status Register   */
#define DMA_CHCONTROL_SRI     ([!"concat('DMA_CHCSR00',$DMA_CHANNEL_NUM,'')"!])
/* DMA Read Data CRC Register       */
#define DMA_RDATA_CRC_SRI     ([!"concat('DMA_RDCRCR00',$DMA_CHANNEL_NUM,'')"!])
/* DMA Source and Destination Address CRC Register   */
#define DMA_SDADDR_CRC_SRI     ([!"concat('DMA_SDCRCR00',$DMA_CHANNEL_NUM,'')"!])
[!ELSEIF "$DMA_CHANNEL_NUM <= num:i(99)"!][!//
/* DMA Channel Configuration             */
#define DMA_CONFIG_SRI        ([!"concat('DMA_CHCFGR0',$DMA_CHANNEL_NUM,'')"!])
/* DMA Channel Source Address */
#define DMA_SOURCE_SRI        ([!"concat('DMA_SADR0',$DMA_CHANNEL_NUM,'')"!])
/* DMA Channel Destination Address       */      
#define DMA_DESTINATION_SRI   ([!"concat('DMA_DADR0',$DMA_CHANNEL_NUM,'')"!])
/* DMA Channel Control/Status Register   */
#define DMA_CHCONTROL_SRI     ([!"concat('DMA_CHCSR0',$DMA_CHANNEL_NUM,'')"!])
/* DMA Read Data CRC Register       */
#define DMA_RDATA_CRC_SRI     ([!"concat('DMA_RDCRCR0',$DMA_CHANNEL_NUM,'')"!])
/* DMA Source and Destination Address CRC Register   */
#define DMA_SDADDR_CRC_SRI     ([!"concat('DMA_SDCRCR0',$DMA_CHANNEL_NUM,'')"!])
[!ELSEIF "$DMA_CHANNEL_NUM <= num:i(999)"!][!//
/* DMA Channel Configuration             */
#define DMA_CONFIG_SRI        ([!"concat('DMA_CHCFGR',$DMA_CHANNEL_NUM,'')"!])
/* DMA Channel Source Address */ 
#define DMA_SOURCE_SRI        ([!"concat('DMA_SADR',$DMA_CHANNEL_NUM,'')"!])
/* DMA Channel Destination Address       */ 
#define DMA_DESTINATION_SRI   ([!"concat('DMA_DADR',$DMA_CHANNEL_NUM,'')"!])
/* DMA Channel Control/Status Register   */
#define DMA_CHCONTROL_SRI     ([!"concat('DMA_CHCSR',$DMA_CHANNEL_NUM,'')"!])
/* DMA Read Data CRC Register       */
#define DMA_RDATA_CRC_SRI     ([!"concat('DMA_RDCRCR',$DMA_CHANNEL_NUM,'')"!])
/* DMA Source and Destination Address CRC Register   */
#define DMA_SDADDR_CRC_SRI     ([!"concat('DMA_SDCRCR',$DMA_CHANNEL_NUM,'')"!])
[!ENDIF!][!//

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
#endif  /* SRITST_CFG_H */
[!AUTOSPACING!]
