#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2007)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_hssl_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2007.09.22                                                    **
#*                                                                            **
#*                                                                            **                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the HSSL driver            **
#*                    configuration objects only                              **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: no                                       **
#*                                                                            **
#******************************************************************************/

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* RS           Roopa Sirur                                                  **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  
#*  V0.0.1:  2007.09.22, RS  : Initial version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/hssl_infineon_tricore/ssc/mak/infineon_hssl_defs.mak


#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(HSSL_DEP_HEADERS) 
HSSL_INC_PATHS_FILE = hssl_include_paths.ifx


build_hssl_driver : info hsslincpaths $(HSSL_PB_CFG_OBJECTS) 
$(HSSL_BASE_PATH)/$(hsslpath)/obj/Hssl_Lcfg.$(OBJ_FILE_SUFFIX) : $(HSSL_BASE_PATH)/$(hsslpath)/src/Hssl_Lcfg.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@"$(COMPILER)"  $(OUTPUT) $(HSSL_BASE_PATH)/$(hsslpath)/obj/Hssl_Lcfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ) $(HSSL_INC_PATHS_FILE)  $(OBJ_CREATION)  $(HSSL_BASE_PATH)/$(hsslpath)/src/Hssl_Lcfg.c  $(ERROR_REPORT) 
	@-rm -f $(HSSL_BASE_PATH)/$(hsslpath)/obj/Hssl_Lcfg.ers 

print:
	@echo $(HSSL_PB_CFG_OBJECTS) 
	
hsslincpaths: 
	@echo $(STANDARD_INCLUDE) > $(HSSL_INC_PATHS_FILE)
	@echo $(HSSL_INCLUDE_PATH) >> $(HSSL_INC_PATHS_FILE)
	

info: 
	@echo -------------Compiling HSSL Configuration---------------
