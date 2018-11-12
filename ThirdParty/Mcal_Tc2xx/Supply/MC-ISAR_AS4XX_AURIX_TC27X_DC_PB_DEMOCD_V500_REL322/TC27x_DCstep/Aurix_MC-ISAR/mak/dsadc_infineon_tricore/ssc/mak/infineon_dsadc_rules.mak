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
#*  FILENAME  : infineon_dsadc_rules.mak                                      ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2013-09-24                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This make file builds the DSADC Driver                     ** 
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
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2013.09.24, AJ  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/dsadc_infineon_tricore/ssc/mak/infineon_dsadc_defs.mak 
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(DSADC_DEP_HEADERS) 
DSADC_INC_PATHS_FILE = dsadc_include_paths.ifx 
 
 
build_dsadc_driver : info dsadcincpaths $(DSADC_SSC_OBJECTS) 
$(DSADC_BASE_PATH)/ssc/obj/Dsadc.$(OBJ_FILE_SUFFIX) : $(DSADC_BASE_PATH)/ssc/src/Dsadc.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_DSADC) $(OUTPUT) $(DSADC_BASE_PATH)/ssc/obj/Dsadc.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(DSADC_INC_PATHS_FILE)  $(OBJ_CREATION)  $(DSADC_BASE_PATH)\ssc\src\Dsadc.c  $(ERROR_REPORT) 
	@-rm -f $(DSADC_BASE_PATH)/ssc/obj/Dsadc.ers 
 
 
print: 
	@echo $(DSADC_SSC_OBJECTS) 
dsadcincpaths: 
	@echo $(STANDARD_INCLUDE) > $(DSADC_INC_PATHS_FILE) 
	@echo $(DSADC_INCLUDE_PATH) >> $(DSADC_INC_PATHS_FILE) 
info:  
	@echo -------------Compiling DSADC Module--------------- 
