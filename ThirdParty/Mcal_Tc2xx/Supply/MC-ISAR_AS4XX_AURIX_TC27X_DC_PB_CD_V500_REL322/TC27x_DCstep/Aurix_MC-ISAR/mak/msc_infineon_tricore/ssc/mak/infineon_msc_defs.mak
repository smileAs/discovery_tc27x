#******************************************************************************* 
#                                                                             ** 
#* Copyright (C) Infineon Technologies (2011)                                 **
#*                                                                            ** 
#* All rights reserved.                                                       ** 
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       ** 
#* Technologies. Passing on and copying of this document, and communication   ** 
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            ** 
#******************************************************************************* 
#*                                                                            ** 
#*  FILENAME  : infineon_msc_defs.mak                                         ** 
#*                                                                            ** 
#*  VERSION   : 0.1.0                                                         **
#*                                                                            ** 
#*  DATE      : 2011.03.22                                                    **
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file contains the variable definitions                ** 
#*                            of MSC module                                   ** 
#*                                                                            ** 
#*                                                                            ** 
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      ** 
#*                                                                            ** 
#******************************************************************************/ 

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* PR           Pawan Reddy                                                  **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.1.0 : PR: Intial Version for Aurix                          **
#*
#******************************************************************************/
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/msc_infineon_tricore/ssc/mak/infineon_msc_check.mak 
#***************************** SPECIFIC ****************************************/  
MSC_SSC_OBJECTS = $(MSC_BASE_PATH)/ssc/obj/Msc.$(OBJ_FILE_SUFFIX) 
MSC_PB_CFG_OBJECTS = $(MSC_BASE_PATH)/$(mscpath)/obj/Msc_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(MSC_DELIVERY_MODE),VARIANTPB_SOURCE) 
MSC_CLEAN_OBJECTS = $(MSC_SSC_OBJECTS) 
MSC_INCLUDE_PATH += $(CC_INC) "$(MSC_BASE_PATH)/ssc/inc" 
MSC_INCLUDE_PATH += $(CC_INC) "$(MSC_BASE_PATH)/$(mscpath)/inc" 
endif 
MSC_DEMO_INCLUDE_PATH += $(CC_INC) "$(MSC_BASE_PATH)/demo/inc" 
 
 
ifeq ($(MSC_DEMO),STD_ON) 
MSC_DEMO_OBJECTS = $(MSC_BASE_PATH)/demo/obj/Msc_Demo.$(OBJ_FILE_SUFFIX) 
else 
MSC_DEMO_OBJECTS = 
endif 
MSC_CLEAN_OBJECTS += $(MSC_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(MSC_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(MSC_DEMO_OBJECTS) 
# Following variables are to be used by the application  
MSC_DEP_HEADERS = $(MSC_BASE_PATH)/ssc/inc/Msc.h $(MSC_BASE_PATH)/$(mscpath)/inc/Msc_Cfg.h 
