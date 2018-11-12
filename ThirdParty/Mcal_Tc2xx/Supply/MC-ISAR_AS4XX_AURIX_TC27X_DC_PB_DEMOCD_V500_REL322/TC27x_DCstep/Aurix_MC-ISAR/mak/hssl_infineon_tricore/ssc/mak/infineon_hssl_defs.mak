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
#*  FILENAME  : infineon_hssl_defs.mak 	                                      **
#*                                                                            **
#*  VERSION   : 0.1.0                                                         **
#*                                                                            **
#*  DATE      : 2011.03.22                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the HSSL module and associates with appropriate folder.**
#*                 						                                                **
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

include $(SSC_ROOT)/mak/hssl_infineon_tricore/ssc/mak/infineon_hssl_check.mak

#***************************** SPECIFIC ****************************************/

HSSL_SSC_OBJECTS = $(HSSL_BASE_PATH)/ssc/obj/Hssl.$(OBJ_FILE_SUFFIX)

HSSL_PC_CFG_OBJECTS = $(HSSL_BASE_PATH)/$(hsslpath)/obj/Hssl_Lcfg.$(OBJ_FILE_SUFFIX) 


ifeq ($(HSSL_DELIVERY_MODE),VARIANTPC_SOURCE) 

HSSL_CLEAN_OBJECTS = $(HSSL_SSC_OBJECTS) 

HSSL_INCLUDE_PATH += $(CC_INC) "$(HSSL_BASE_PATH)/ssc/inc" 


HSSL_INCLUDE_PATH += $(CC_INC) "$(HSSL_BASE_PATH)/$(hsslpath)/inc" 
endif 
HSSL_DEMO_INCLUDE_PATH += $(CC_INC) "$(HSSL_BASE_PATH)/demo/inc" 




ifeq ($(HSSL_DEMO),STD_ON)
HSSL_DEMO_OBJECTS = $(HSSL_BASE_PATH)/demo/obj/Hssl_Demo.$(OBJ_FILE_SUFFIX)
else
HSSL_DEMO_OBJECTS =
endif
HSSL_CLEAN_OBJECTS += $(HSSL_DEMO_OBJECTS)


CLEAN_DRIVER_OBJECTS += $(HSSL_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(HSSL_DEMO_OBJECTS) 
# Following variables are to be used by the application 

HSSL_DEP_HEADERS = $(HSSL_BASE_PATH)/ssc/inc/Hssl.h $(HSSL_BASE_PATH)/$(hsslpath)/inc/Hssl_Cfg.h 
