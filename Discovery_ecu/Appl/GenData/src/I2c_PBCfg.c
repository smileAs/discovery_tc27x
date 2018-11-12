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
**  FILENAME  : I2c_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  DATE, TIME: 2018-08-21, 08:48:03                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : I2c configuration generated out of ECU configuration       **
**                 file(I2c.bmd/.xdm)                                         **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEBILITY :                                                             **
**                                                                            **
*******************************************************************************/

            
            


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include I2C Module File */
#include "I2c.h"
/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

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
#define I2C_START_SEC_POSTBUILDCFG
#include "MemMap.h"

static const I2c_PacketConfigType I2c_kPacketConfig0[] =
{
  {
  /****Packet_ACCX (0x00u)***ACCD_X_LSB,ACCD_X_MSB*******************************/
    /* Address */
    0x2U,        /**ACCD_X_LSB***/
        
    /* Length */
    0x2U,
        
    /* HwUnit */
    0x0U,
        
	/* ExternalDeviceAddress    0x18<<1*/
    0x30U,
        
    /* AdddressCfgValue */
    0x080022U,
        
    /* FracDividerCfgValue */
    0x0100E8U,
        
    /* TimingCfgvalue */
    0x0U,
        
    /* FIFOCfgValue */
    0x32200U,
        
    /* PortPinCfgvalue */
    0x1U,
          },
    {
    /****Packet_ACCY (0x01u)***ACCD_Y_LSB,ACCD_Y_MSB*******************************/
    /* Address */
    0x04U,
        
    /* Length */
    0x2U,
        
    /* HwUnit */
    0x0U,
        
	/* ExternalDeviceAddress     0x18<<1*/
    0x30U,
        
    /* AdddressCfgValue */
    0x080022U,
        
    /* FracDividerCfgValue */
    0x0100E8U,
        
    /* TimingCfgvalue */
    0x0U,
        
    /* FIFOCfgValue */
    0x32200U,
        
    /* PortPinCfgvalue */
    0x1U,
          },
    {
    /****Packet_ACCZ (0z02u)***ACCD_Z_LSB,ACCD_Z_MSB*******************************/
    /* Address */
    0x06U,
        
    /* Length */
    0x2U,
        
    /* HwUnit */
    0x0U,
        
	/* ExternalDeviceAddress     0x18<<1*/
    0x30U,
        
    /* AdddressCfgValue */
    0x080022U,
        
    /* FracDividerCfgValue */
    0x0100E8U,
        
    /* TimingCfgvalue */
    0x0U,
        
    /* FIFOCfgValue */
    0x32200U,
        
    /* PortPinCfgvalue */
    0x1U,
          },
     {
    /****Packet_GYRX  (0x03u)********GYR_CHIPIID  register******************/
    /* Address */
    0x02U,
     
    /* Length */
    0x2U,
    
    /* HwUnit */
    0x0U,
    
    /* ExternalDeviceAddress     0x68<<1*/
    0xD0U,
    
    /* AdddressCfgValue */
    0x080022U,
    
    /* FracDividerCfgValue */
    0x0100E8U,
    
    /* TimingCfgvalue */
    0x0U,
    
    /* FIFOCfgValue */
    0x32200U,
    
    /* PortPinCfgvalue */
    0x1U,
    },
    {
    /****Packet_GYRY  (0x04u)********GYR_CHIPIID  register******************/
    /* Address */
    0x04U,
     
    /* Length */
    0x2U,
    
    /* HwUnit */
    0x0U,
    
    /* ExternalDeviceAddress    0x68<<1*/
    0xD0U,
    
    /* AdddressCfgValue */
    0x080022U,
    
    /* FracDividerCfgValue */
    0x0100E8U,
    
    /* TimingCfgvalue */
    0x0U,
    
    /* FIFOCfgValue */
    0x32200U,
    
    /* PortPinCfgvalue */
    0x1U,
    },
   {
    /****Packet_GYRZ  (0x05u)********GYR_CHIPIID  register******************/
    /* Address */
    0x06U,
     
    /* Length */
    0x2U,
    
    /* HwUnit */
    0x0U,
    
    /* ExternalDeviceAddress    0x68<<1*/
    0xD0U,
    
    /* AdddressCfgValue */
    0x080022U,
    
    /* FracDividerCfgValue */
    0x0100E8U,
    
    /* TimingCfgvalue */
    0x0U,
    
    /* FIFOCfgValue */
    0x32200U,
    
    /* PortPinCfgvalue */
    0x1U,
    },

};



static const I2c_HWModuleConfigType I2c_kModuleConfig0[]=
{
  /* I2C0 Module */
  {
			    	    		        0x108U,
          },
};

const I2c_ConfigType I2c_ConfigRoot[1] =
{
      {
    &I2c_kPacketConfig0[0],

    &I2c_kModuleConfig0[0],

    {
      0x0U,
    },
    {
      0xffU,
    },
    (I2c_PacketType)(sizeof(I2c_kPacketConfig0) / sizeof(I2c_PacketConfigType)),
  }
  };

#define I2C_STOP_SEC_POSTBUILDCFG
/* IFX_MISRA_RULE_19_01_STATUS= Memmap file included as per AUTOSAR */
#include "MemMap.h"



