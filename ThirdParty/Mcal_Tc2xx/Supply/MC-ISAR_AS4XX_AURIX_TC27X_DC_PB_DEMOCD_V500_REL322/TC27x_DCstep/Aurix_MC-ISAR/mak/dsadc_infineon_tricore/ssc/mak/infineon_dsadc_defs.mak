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
#*  FILENAME  : infineon_dsadc_defs.mak                                       ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         **
#*                                                                            ** 
#*  DATE      : 2013-09-24                                                    **
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file contains the variable definitions                ** 
#*                            of DSADC module                                 ** 
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
#* AJ           Abdul Jaffar                                                 **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.0.1 : AJ: Intial Version for Dsadc                          **
#*
#******************************************************************************/
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/dsadc_infineon_tricore/ssc/mak/infineon_dsadc_check.mak 
#***************************** SPECIFIC ****************************************/  
DSADC_SSC_OBJECTS = $(DSADC_BASE_PATH)/ssc/obj/Dsadc.$(OBJ_FILE_SUFFIX) 
DSADC_PB_CFG_OBJECTS = $(DSADC_BASE_PATH)/$(dsadcpath)/obj/Dsadc_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(DSADC_DELIVERY_MODE),VARIANTPB_SOURCE) 
DSADC_CLEAN_OBJECTS = $(DSADC_SSC_OBJECTS) 
DSADC_INCLUDE_PATH += $(CC_INC) "$(DSADC_BASE_PATH)/ssc/inc" 
DSADC_INCLUDE_PATH += $(CC_INC) "$(DSADC_BASE_PATH)/$(dsadcpath)/inc" 
endif 
DSADC_DEMO_INCLUDE_PATH += $(CC_INC) "$(DSADC_BASE_PATH)/demo/inc" 
 
 
ifeq ($(DSADC_DEMO),STD_ON) 
DSADC_DEMO_OBJECTS = $(DSADC_BASE_PATH)/demo/obj/Dsadc_Demo.$(OBJ_FILE_SUFFIX) 
else 
DSADC_DEMO_OBJECTS = 
endif 
DSADC_CLEAN_OBJECTS += $(DSADC_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(DSADC_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(DSADC_DEMO_OBJECTS) 
# Following variables are to be used by the application  
DSADC_DEP_HEADERS = $(DSADC_BASE_PATH)/ssc/inc/Dsadc.h $(DSADC_BASE_PATH)/$(dsadcpath)/inc/Dsadc_Cfg.h 
