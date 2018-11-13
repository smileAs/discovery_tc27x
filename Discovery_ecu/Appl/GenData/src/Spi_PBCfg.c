/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Spi_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\88 $                                                 **
**                                                                            **
**  DATE, TIME: 2018-11-06, 14:01:42                                         **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SPI configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include SPI Module File */
/* [cover parentID=DS_NAS_SPI_PR699,DS_NAS_SPI_PR709] */

#include "Spi.h"
/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* MISRA RULE 87 VIOLATION: Inclusion of MemMap.h in between the code can't
   be avoided as it is required for mapping global variables, constants
   and code
*/
/* Violates MISRA Required Rule 16.9,
            function identifier used without '&' or parenthisized parameter list
           when using function pointer in configurations
*/

/*
                     Container: SpiChannelConfiguration
*/
#define SPI_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"
/*
Configuration : Channel Configuration Constant Structure.
The IB Channels are configured first followed by EB.
*/
static const Spi_ChannelConfigType Spi_kChannelConfig0[] =
{
/* EB Channel: SpiChannel_0 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(16U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
        /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)64U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_1 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(8U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)64U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_2 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(8U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)64U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
/* EB Channel: SpiChannel_3 Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)0x00000000U,
    /* Data Configuration */
    Spi_DataConfig(8U, /* Data Width */
                   SPI_DATA_MSB_FIRST), /* Transfer Start */
    /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)64U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_EB_BUFFER,
  },
};

/*
                    Container: SpiJobConfiguration
*/
/* Notification Function of SpiJobPMIC is NULL_PTR */
/* Notification Function of SpiJobRTK is NULL_PTR */
/* Notification Function of SpiJobSOC is NULL_PTR */
/* Notification Function of SpiJobSD is NULL_PTR */


/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJobPMIC*/
static const Spi_ChannelType SpiJobPMIC_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_0,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJobRTK*/
static const Spi_ChannelType SpiJobRTK_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_1,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJobSOC*/
static const Spi_ChannelType SpiJobSOC_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_2,
  SPI_CHANNEL_LINK_DELIMITER
};
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: SpiJobSD*/
static const Spi_ChannelType SpiJobSD_ChannelLinkPtr[] =
{
  SpiConf_SpiChannel_SpiChannel_3,
  SPI_CHANNEL_LINK_DELIMITER
};

/*
Configuration: Job Configuration Constant Structure.
*/
static const Spi_JobConfigType Spi_kJobConfig0[] =
{

/* Job: SpiJobPMIC Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJobPMIC_ChannelLinkPtr,
    /* Baud Rate (5000000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x1U),
              /*A*/(0x1U), /*B*/(0x3U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x01U,/*IDLE*/ 0x01U,
        /*LPRE*/0x00U, /*LEAD*/0x01U,
        /*TPRE*/0x00U, /*TRAIL*/0x01U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_TRAIL),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL11 << 4U) | (SPI_QSPI2_INDEX),

    /* Channel Based Chip Select */
    (uint8)1U,

    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJobRTK Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJobRTK_ChannelLinkPtr,
    /* Baud Rate (2000000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x0U), /*Q*/(0x3U),
              /*A*/(0x3U), /*B*/(0x3U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x01U,/*IDLE*/ 0x01U,
        /*LPRE*/0x00U, /*LEAD*/0x01U,
        /*TPRE*/0x00U, /*TRAIL*/0x01U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL10 << 4U) | (SPI_QSPI0_INDEX),

    /* Channel Based Chip Select */
    (uint8)1U,

    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJobSOC Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJobSOC_ChannelLinkPtr,
    /* Baud Rate (100000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x1U), /*Q*/(0x27U),
              /*A*/(0x3U), /*B*/(0x3U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x01U,/*IDLE*/ 0x01U,
        /*LPRE*/0x00U, /*LEAD*/0x01U,
        /*TPRE*/0x00U, /*TRAIL*/0x01U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL12 << 4U) | (SPI_QSPI3_INDEX),

    /* Channel Based Chip Select */
    (uint8)1U,

    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  },
/* Job: SpiJobSD Configuration */
  {
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
    NULL_PTR,
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    SpiJobSD_ChannelLinkPtr,
    /* Baud Rate (100000 Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/(0x1U), /*Q*/(0x27U),
              /*A*/(0x3U), /*B*/(0x3U), /*C*/(0x3U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/0x01U,/*IDLE*/ 0x01U,
        /*LPRE*/0x00U, /*LEAD*/0x01U,
        /*TPRE*/0x00U, /*TRAIL*/0x01U),

    SPI_CS_HW, /* Hw CS Pin is Selected */

    /*CS Active level Polarity*/
    SPI_CS_POLARITY_LOW,

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig(SPI_CLK_IDLE_LOW,
                      SPI_DATA_SHIFT_LEAD),
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,

    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_CHANNEL10 << 4U) | (SPI_QSPI1_INDEX),

    /* Channel Based Chip Select */
    (uint8)1U,

    /* Spi Parity Selection */
    (uint8)SPI_QSPI_PARITY_UNUSED,
    
  }
};

/*
                     Container: Spi_SequenceConfiguration
*/
/* Notification Function of Sequence: SpiSequencePMIC is NULL_PTR */
/* Notification Function of Sequence: SpiSequenceRTK is NULL_PTR */
/* Notification Function of Sequence: SpiSequenceSD is NULL_PTR */
/* Notification Function of Sequence: SpiSequenceSOC is NULL_PTR */

/* Job Assignment of Sequence: SpiSequencePMIC */
static const Spi_JobType SpiSequencePMIC_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJobPMIC,
  SPI_JOB_LINK_DELIMITER
};
/* Job Assignment of Sequence: SpiSequenceRTK */
static const Spi_JobType SpiSequenceRTK_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJobRTK,
  SPI_JOB_LINK_DELIMITER
};
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: SpiSequenceSD */
static const Spi_JobType SpiSequenceSD_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJobSD,
  SPI_JOB_LINK_DELIMITER
};
/* Job Assignment of Sequence: SpiSequenceSOC */
static const Spi_JobType SpiSequenceSOC_JobLinkPtr[] =
{
  SpiConf_SpiJob_SpiJobSOC,
  SPI_JOB_LINK_DELIMITER
};




/*
Configuration: Sequence Configuration Constant Structure.
*/
static const Spi_SequenceConfigType Spi_kSequenceConfig0[] =
{   /* Sequence: SpiSequencePMIC Configuration */
  {
    /* Spi_SeqEndNotification */
    NULL_PTR,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequencePMIC_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
    /* This holds the total number of jobs linked to this sequence */
    1U,
  },
  /* Sequence: SpiSequenceRTK Configuration */
  {
    /* Spi_SeqEndNotification */
    NULL_PTR,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequenceRTK_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
    /* This holds the total number of jobs linked to this sequence */
    1U,
  },
  /* Sequence: SpiSequenceSOC Configuration */
  {
    /* Spi_SeqEndNotification */
    NULL_PTR,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequenceSOC_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
    /* This holds the total number of jobs linked to this sequence */
    1U,
  },
    
  /* Sequence: SpiSequenceSD Configuration */
  {
    /* Spi_SeqEndNotification */
    NULL_PTR,

    /* User given name outside the naming convention */    /* Spi_JobLinkPtr */
    SpiSequenceSD_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */
    NULL_PTR,
     /* This holds the total number of jobs linked to this sequence */
    1U,
  },
};

static const Spi_DmaConfigType Spi_kDmaConfig0[]=
{

  { /* QSPI0 Module Hw Dma Config */
    DMA_CHANNEL0,  /* Tx */    DMA_CHANNEL1   /* Rx */  },

  { /* QSPI1 Module Hw Dma Config */
    DMA_CHANNEL2,  /* Tx */    DMA_CHANNEL3   /* Rx */  },

  { /* QSPI2 Module Hw Dma Config */
    DMA_CHANNEL4,  /* Tx */    DMA_CHANNEL5   /* Rx */  },

  { /* QSPI3 Module Hw Dma Config */
    DMA_CHANNEL6,  /* Tx */    DMA_CHANNEL7   /* Rx */  },

};

static const Spi_HWModuleConfigType Spi_kModuleConfig0[]=
{
  /* QSPI0 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
      SPI_QSPI0_MRIS_SEL,
      &Spi_kDmaConfig0[0U],
  },
  /* QSPI1 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
      SPI_QSPI1_MRIS_SEL,
      &Spi_kDmaConfig0[1U],
  },
  /* QSPI2 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
      SPI_QSPI2_MRIS_SEL,
      &Spi_kDmaConfig0[2U],
  },
  /* QSPI3 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      SPI_CLK_SLEEP_DISABLE,
      SPI_QSPI3_MRIS_SEL,
      &Spi_kDmaConfig0[3U],
  },
};



static const Spi_BaudrateEconType Spi_kBaudrateEcon0[]=
{
  {
    Spi_BaudRateECON(0x1U, 0x1U, 0x3U, 0x3U,
    SPI_DATA_SHIFT_TRAIL,
    SPI_CLK_IDLE_LOW,
    SPI_QSPI_PARITY_DISABLE),
    (uint8)((uint8)SPI_QSPI_CHANNEL11 << 4U) | (SPI_QSPI2_INDEX)
  },
  {
    Spi_BaudRateECON(0x3U, 0x3U, 0x3U, 0x3U,
    SPI_DATA_SHIFT_LEAD,
    SPI_CLK_IDLE_LOW,
    SPI_QSPI_PARITY_DISABLE),
    (uint8)((uint8)SPI_QSPI_CHANNEL10 << 4U) | (SPI_QSPI0_INDEX)
  },
  {
    Spi_BaudRateECON(0x27U, 0x3U, 0x3U, 0x3U,
    SPI_DATA_SHIFT_LEAD,
    SPI_CLK_IDLE_LOW,
    SPI_QSPI_PARITY_DISABLE),
    (uint8)((uint8)SPI_QSPI_CHANNEL12 << 4U) | (SPI_QSPI3_INDEX)
  },
  {
    Spi_BaudRateECON(0x27U, 0x3U, 0x3U, 0x3U,
    SPI_DATA_SHIFT_LEAD,
    SPI_CLK_IDLE_LOW,
    SPI_QSPI_PARITY_DISABLE),
    (uint8)((uint8)SPI_QSPI_CHANNEL10 << 4U) | (SPI_QSPI1_INDEX)
  }
};

const Spi_ConfigType Spi_ConfigRoot[1U] =
{
  {
    Spi_kChannelConfig0,
    Spi_kJobConfig0,
    Spi_kSequenceConfig0,
    {
      &Spi_kModuleConfig0[0U],
      &Spi_kModuleConfig0[1U],
      &Spi_kModuleConfig0[2U],
      &Spi_kModuleConfig0[3U],
    },
    Spi_kBaudrateEcon0,
    (Spi_JobType)(sizeof(Spi_kJobConfig0) / sizeof(Spi_JobConfigType)),
    (Spi_ChannelType)(sizeof(Spi_kChannelConfig0) / \
                      sizeof(Spi_ChannelConfigType)),
    (Spi_SequenceType)(sizeof(Spi_kSequenceConfig0) / \
                                        sizeof(Spi_SequenceConfigType)),
    (uint8)(sizeof(Spi_kBaudrateEcon0) / sizeof(Spi_BaudrateEconType)),
    3U
  }
};


#define SPI_STOP_SEC_POSTBUILDCFG
/* Allows to map variables, constants and code of modules to individual
  memory sections.*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/  
#include "MemMap.h"

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
/* General Notes */
/*
SPI095: The code file structure shall not be defined within this specification
completely. At this point it shall be pointed out that the code-file structure
shall include the following file named:
- Spi_Lcfg.c ?for link time and for post-build configurable parameters and
- Spi_PBcfg.c ?for post build time configurable parameters.
These files shall contain all link time and post-build time configurable
parameters.
This file shall contain all link time and post-build time configurable
parameters.
For the implementation of VariantPC, the implementation stores the
pre compile time parameters that have to be defined as constants in this file.

SPI123: In this configuration, all Sequences declared are considered as Non
Interruptible Sequences. That means, their dedicated parameter
SPI_INTERRUPTIBLE_SEQUENCE (see SPI064 & SPI106) could be omitted or the
FALSE value should be used as default.

*/


