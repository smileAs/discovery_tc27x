#######################################################################################################################
# File Name  : Makefile.AURIX.GNU.ALL.make                                                                            #
# Description: Linker/Symbol Preprocessor command file generation                                                     #
# Project    : Vector Basic Runtime System                                                                            #
# Module     : BrsHw for Platform Infineon Aurix                                                                      #
#              and Compiler Hightec GNU                                                                               #
#                                                                                                                     #
#---------------------------------------------------------------------------------------------------------------------#
# COPYRIGHT                                                                                                           #
#---------------------------------------------------------------------------------------------------------------------#
# Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved. #
#                                                                                                                     #
#---------------------------------------------------------------------------------------------------------------------#
# AUTHOR IDENTITY                                                                                                     #
#---------------------------------------------------------------------------------------------------------------------#
# Name                          Initials      Company                                                                 #
# ----------------------------  ------------  ------------------------------------------------------------------------#
# Benjamin Walter               visbwa        Vector Informatik GmbH                                                  #
# Roland Reinl                  virrro        Vector Informatik GmbH                                                  #
#---------------------------------------------------------------------------------------------------------------------#
# REVISION HISTORY                                                                                                    #
#---------------------------------------------------------------------------------------------------------------------#
# Version   Date        Author  Description                                                                           #
# --------  ----------  ------  --------------------------------------------------------------------------------------#
# 01.00.00  2016-08-25  visbwa  Initial creation to separate OsCoreGen7 from Default UseCase                          #
# 01.00.01  2016-12-22  visbwa  Review according to Brs_Template 2.00.03                                              #
# 01.00.02  2017-02-23  virrro  Moved OsGen7-specific usage of USER_LINKER_COMMAND_FILE from Makefile to              #
#                               Makefile.AURIX.GNU.ALL.make                                                           #
#######################################################################################################################

##########################################################################################################
# LINKER FILE GENERATION
##########################################################################################################

ifeq ($(OS_USECASE),OSGEN7)
else
  include Makefile.AURIX.GNU.ALL.LinkerScriptDefault
endif

# virrro: Additional dependency for linking. Independent of the current configuration, a linker script is required.
# This rule ensures that the linker script will be created before starting the link process.
$(PROJECT_NAME).$(BINARY_SUFFIX): $(PROJECT_NAME).$(LNK_SUFFIX)

#------------------------------------------------------------------------------
# rule to generate linker command file
#------------------------------------------------------------------------------
$(PROJECT_NAME).$(LNK_SUFFIX): Makefile \
                               Makefile.config \
                               Makefile.Project.Part.Defines \
                               Makefile.$(PLATFORM).$(COMPILER_MANUFACTURER).$(EMULATOR).make
ifeq ($(OS_USECASE),OSGEN7)
	$(subst \,/,$(CC_ENV)) && $(subst \,/,$(COMPILER_BIN)\tricore-gcc.exe -E -P -C $(USER_LINKER_COMMAND_FILE) -o $(PROJECT_NAME).$(LNK_SUFFIX) -I .\GenData)
else
#---------------------------------------------------------------------------------
# _NEVER_ delete the leading "Tab" in the first ECHO-line below!!!
# The Linker-Command-File which will be generated:
#---------------------------------------------------------------------------------
	@$(ECHO) "Generating linker command file for $(CPU_TYPE) $@:"; \
  $(LINK_LOCATE_RULE_TC2XX)              \
  $(ECHO) "...done";                     \
  $(ECHO) "";
endif

#----------------------------------------------------------------------------------------------------------
# Rule to generate Motorola S-Record file
#----------------------------------------------------------------------------------------------------------
$(PROJECT_NAME).sre: $(PROJECT_NAME).$(BINARY_SUFFIX)
	@$(ECHO) Converting to Motorola S-Record...;                                                                                  \
  $(subst \,/,$(COMPILER_BIN)\tricore-objcopy.exe) -Ielf32-tricore -Osrec $(PROJECT_NAME).$(BINARY_SUFFIX) $(PROJECT_NAME).sre; \
  $(subst \,/,$(COMPILER_BIN)\tricore-objcopy.exe) -O ihex $(PROJECT_NAME).$(BINARY_SUFFIX) $(PROJECT_NAME).hex; \
  $(ECHO) ...done!

#End of Makefile.AURIX.GNU.ALL.make
