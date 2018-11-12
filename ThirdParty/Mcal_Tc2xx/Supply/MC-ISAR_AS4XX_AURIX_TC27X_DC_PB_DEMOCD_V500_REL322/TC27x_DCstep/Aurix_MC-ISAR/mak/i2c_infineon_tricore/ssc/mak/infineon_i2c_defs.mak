#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2013)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_i2c_defs.mak                                         **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2013.10.10                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the I2C driver files only                         **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: no                                       **
#*                                                                            **
#******************************************************************************/

#*******************************************************************************
#*                      Author(s) Identity                                    **
#*******************************************************************************
#*                                                                            **
#* Initials     Name                                                          **
#* ---------------------------------------------------------------------------**
#* JN           Jayaprakash Narayana                                          **
#*                                                                            **
#******************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1 : 2013.10.10, JN  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/i2c_infineon_tricore/ssc/mak/infineon_i2c_check.mak 

#***************************** SPECIFIC ***************************************/  

I2C_SSC_OBJECTS = $(I2C_BASE_PATH)/ssc/obj/I2c.$(OBJ_FILE_SUFFIX)
I2C_SSC_OBJECTS += $(I2C_BASE_PATH)/$(i2cpath)/obj/I2c_LCfg.$(OBJ_FILE_SUFFIX) 

I2C_PB_CFG_OBJECTS = $(I2C_BASE_PATH)/$(i2cpath)/obj/I2c_PBCfg.$(OBJ_FILE_SUFFIX) 

 
ifeq ($(I2C_DELIVERY_MODE),VARIANTPB_SOURCE) 
I2C_CLEAN_OBJECTS = $(I2C_SSC_OBJECTS) 
I2C_INCLUDE_PATH += $(CC_INC) "$(I2C_BASE_PATH)/ssc/inc" 
I2C_INCLUDE_PATH += $(CC_INC) "$(I2C_BASE_PATH)/$(i2cpath)/inc" 
endif 


ifeq ($(I2C_DEMO),STD_ON)
I2C_DEMO_OBJECTS = $(I2C_BASE_PATH)/demo/obj/I2c_Demo.$(OBJ_FILE_SUFFIX)
I2C_DEMO_INCLUDE_PATH += $(CC_INC) "$(I2C_BASE_PATH)/demo/inc" 
I2C_CLEAN_OBJECTS += $(I2C_DEMO_OBJECTS)
else
I2C_DEMO_OBJECTS =
endif


CLEAN_DRIVER_OBJECTS += $(I2C_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(I2C_DEMO_OBJECTS) 
# Following variables are to be used by the application  
I2C_DEP_HEADERS = $(I2C_BASE_PATH)/ssc/inc/I2c.h $(I2C_BASE_PATH)/$(i2cpath)/inc/I2c_Cfg.h
