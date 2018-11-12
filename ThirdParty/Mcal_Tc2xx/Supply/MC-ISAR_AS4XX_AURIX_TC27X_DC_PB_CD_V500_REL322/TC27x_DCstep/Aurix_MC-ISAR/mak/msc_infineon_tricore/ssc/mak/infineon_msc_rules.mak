#******************************************************************************* 
#                                                                             ** 
#* Copyright (C) Infineon Technologies (2009)                                 **
#*                                                                            ** 
#* All rights reserved.                                                       ** 
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       ** 
#* Technologies. Passing on and copying of this document, and communication   ** 
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            ** 
#******************************************************************************* 
#*                                                                            ** 
#*  FILENAME  : infineon_msc_rules.mak                                        ** 
#*                                                                            ** 
#*  VERSION   : 0.0.2                                                         ** 
#*                                                                            ** 
#*  DATE      : 2012.11.02                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This make file builds the MSC Driver                       ** 
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
#* HM          Hamzath                                                       ** 
#* MK          Mundhra Karan                                                 ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.2 : 2012.11.02, MK  : Multi compiler support changes
#*  V0.0.1 : 2009.02.24, HM  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/msc_infineon_tricore/ssc/mak/infineon_msc_defs.mak 
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(MSC_DEP_HEADERS) 
MSC_INC_PATHS_FILE = msc_include_paths.ifx 
 
 
build_msc_driver : info mscincpaths $(MSC_SSC_OBJECTS) 
$(MSC_BASE_PATH)/ssc/obj/Msc.$(OBJ_FILE_SUFFIX) : $(MSC_BASE_PATH)/ssc/src/Msc.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_MSC) $(OUTPUT) $(MSC_BASE_PATH)/ssc/obj/Msc.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(MSC_INC_PATHS_FILE)  $(OBJ_CREATION)  $(MSC_BASE_PATH)\ssc\src\Msc.c  $(ERROR_REPORT) 
	@-rm -f $(MSC_BASE_PATH)/ssc/obj/Msc.ers 
 
 
print: 
	@echo $(MSC_SSC_OBJECTS) 
mscincpaths: 
	@echo $(STANDARD_INCLUDE) > $(MSC_INC_PATHS_FILE) 
	@echo $(MSC_INCLUDE_PATH) >> $(MSC_INC_PATHS_FILE) 
info:  
	@echo -------------Compiling MSC Module--------------- 
