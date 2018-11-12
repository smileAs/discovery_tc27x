###############################################################################
# File Name  : Mcal_rules.mak                                                  #
# Description: Autosar makefile Template                                      #
#              This makefile is a template to implement the common            #
#              features of each project.                                      #
#              It is included by the Global.Makefile.target.make.$(Version)   #
#              and is supported from version 3.24 .                           #
#                                                                             #
# This Template is based on AUTOSAR_BSW_MakefileInterface.doc version 0.4     #
#                                                                             #
#-----------------------------------------------------------------------------#
#               C O P Y R I G H T                                             #
#-----------------------------------------------------------------------------#
# Copyright (c) 2016 by Vector Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               A U T H O R   I D E N T I T Y                                 #
#-----------------------------------------------------------------------------#
# Initials     Name                      Company                              #
# --------     ---------------------     -------------------------------------#
# virgaj       Andrej Gazvoda            Vector Informatik GmbH               #
#-----------------------------------------------------------------------------#
#               R E V I S I O N   H I S T O R Y                               #
#-----------------------------------------------------------------------------#
# Date         Version  Sign    Description                                   #
# ----------   -------  ------  ----------------------------------------------#
# 2017/02/06   1.00.00  Virgaj	Initial revision TC2xx SUPERSET               #
# 2017/03/30   1.00.01  Virgaj	Integration of SafeTLib and SHE+			  #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 0.1                                                       #
###############################################################################


###############################################################
# REGISTRY
#

#e.g.: LIBRARIES_TO_BUILD      +=    $(LIB_OUPUT_PATH)\vendorx_canlib1.$(LIB_FILE_SUFFIX)
LIBRARIES_TO_BUILD      +=

# e.g.: CC_FILES_TO_BUILD       += drv\can_drv.c

#Path to Mcal source and include files
MCAL_PATH_BASE = ..\ThirdParty\Mcal_Tc2xx\Supply\MC-ISAR_AS4XX_AURIX_TC27X_DC_PB_BASE_V500_REL322
MCAL_PATH_MEM = ..\ThirdParty\Mcal_Tc2xx\Supply\MC-ISAR_AS4XX_AURIX_TC27X_DC_PB_MEM_V500_REL322
MCAL_PATH_CD = ..\ThirdParty\Mcal_Tc2xx\Supply\MC-ISAR_AS4XX_AURIX_TC27X_DC_PB_CD_V500_REL322
MCAL_PATH_DEMO_CD = ..\ThirdParty\Mcal_Tc2xx\Supply\MC-ISAR_AS4XX_AURIX_TC27X_DC_PB_DEMOCD_V500_REL322
MCAL_PATH_LIB = ..\ThirdParty\Mcal_Tc2xx\Supply\MC-ISAR_AS4XX_AURIX_TC27X_DC_PC_LIB_V500_REL322
AURIX_STEP = TC27x_DCstep
AURIX_STEP_INC = TC27xD
SAFETLIB_BASE_PATH =
SHEPLUS_BASE_PATH = ..\ThirdParty\Mcal_Tc2xx\Supply\MC-ISAR_SHEPlus_AS4XX_AURIX_TC27X_DB_PC_Src_V703

#Path to Irq source and include files
IRQ_BASE_PATH = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\irq_infineon_tricore\ssc
CC_INCLUDE_PATH += $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\integration_general\inc
CC_INCLUDE_PATH += $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\general\tricore\inc\$(AURIX_STEP_INC)
CC_INCLUDE_PATH += $(SAFETLIB_BASE_PATH)\$(AURIX_STEP)\01_SafeTlib\Common
GENERAL_BASE_PATH = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\tricore_general\ssc

CC_FILES_TO_BUILD  += $(GENERAL_BASE_PATH)\src\Mcal_TcLib.c \
					  $(GENERAL_BASE_PATH)\src\Mcal_WdgLib.c \
					  $(GENERAL_BASE_PATH)\src\Mcal_DmaLib.c
CC_FILES_TO_BUILD  += $(IRQ_BASE_PATH)\src\Irq.c
CC_INCLUDE_PATH    += $(GENERAL_BASE_PATH)\inc $(IRQ_BASE_PATH)\inc


ifneq ($(MCAL_EXCLUDE_ADC),1)
ADC_BASE_PATH     = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\adc_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Adc_PBCfg.c
CC_FILES_TO_BUILD  += $(ADC_BASE_PATH)\src\Adc.c \
					  $(ADC_BASE_PATH)\src\Adc_Calibration.c \
					  $(ADC_BASE_PATH)\src\Adc_ConvHandle.c \
					  $(ADC_BASE_PATH)\src\Adc_HwHandle.c \
					  $(ADC_BASE_PATH)\src\Adc_Ver.c \
					  $(IRQ_BASE_PATH)\src\Adc_Irq.c
CC_INCLUDE_PATH    += $(ADC_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_DIO),1)
DIO_BASE_PATH     = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\dio_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Dio_PBCfg.c
CC_FILES_TO_BUILD  += $(DIO_BASE_PATH)\src\Dio.c \
					  $(DIO_BASE_PATH)\src\Dio_Ver.c
CC_INCLUDE_PATH    += $(DIO_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_GPT),1)
GPT_BASE_PATH     = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\gpt_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Gpt_PBCfg.c
CC_FILES_TO_BUILD  += $(GPT_BASE_PATH)\src\Gpt.c \
					  $(GPT_BASE_PATH)\src\Gpt_Ver.c \
					  $(IRQ_BASE_PATH)\src\Irq.c
CC_INCLUDE_PATH    += $(GPT_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_ICU),1)
ICU_BASE_PATH     = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Icu_17_GtmCcu6_PBCfg.c
CC_FILES_TO_BUILD  += $(ICU_BASE_PATH)\src\Icu_17_GtmCcu6.c \
					  $(ICU_BASE_PATH)\src\Icu_17_GtmCcu6_Safe.c \
					  $(ICU_BASE_PATH)\src\Icu_17_GtmCcu6_Ver.c
CC_INCLUDE_PATH    += $(ICU_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_MCU),1)
MCU_BASE_PATH     = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\mcu_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Gtm_PBCfg.c \
						   $(GENDATA_DIR)\src\Mcu_PBCfg.c \
						   $(GENDATA_DIR)\src\Gtm_LCfg.c
CC_FILES_TO_BUILD  += $(MCU_BASE_PATH)\src\Gtm.c \
					  $(MCU_BASE_PATH)\src\Gtm_Platform.c \
					  $(MCU_BASE_PATH)\src\Mcu.c \
					  $(MCU_BASE_PATH)\src\Mcu_Crc.c \
					  $(MCU_BASE_PATH)\src\Mcu_Dma.c \
					  $(MCU_BASE_PATH)\src\Mcu_Platform.c \
					  $(MCU_BASE_PATH)\src\Mcu_Ver.c \
					  $(IRQ_BASE_PATH)\src\Ccu6_Irq.c \
					  $(IRQ_BASE_PATH)\src\Dma_Irq.c \
					  $(IRQ_BASE_PATH)\src\Eru_Irq.c \
					  $(IRQ_BASE_PATH)\src\Gtm_Irq.c
CC_INCLUDE_PATH    += $(MCU_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_PORT),1)
PORT_BASE_PATH    = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\port_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Port_PBCfg.c
CC_FILES_TO_BUILD  += $(PORT_BASE_PATH)\src\Port.c
CC_INCLUDE_PATH    += $(PORT_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_PWM),1)
PWM_BASE_PATH     = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Pwm_17_Gtm_PBCfg.c
CC_FILES_TO_BUILD  += $(PWM_BASE_PATH)\src\Pwm_17_Gtm.c \
					  $(PWM_BASE_PATH)\src\Pwm_17_Gtm_Ver.c
CC_INCLUDE_PATH    += $(PWM_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_SPI),1)
SPI_BASE_PATH     = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\spi_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Spi_PBCfg.c
CC_FILES_TO_BUILD  += $(SPI_BASE_PATH)\src\Spi.c \
					  $(SPI_BASE_PATH)\src\SpiSlave.c \
					  $(SPI_BASE_PATH)\src\Spi_Ver.c \
					  $(IRQ_BASE_PATH)\src\Spi_Irq.c
CC_INCLUDE_PATH    += $(SPI_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_UART),1)
UART_BASE_PATH     = $(MCAL_PATH_CD)\$(AURIX_STEP)\Aurix_MC-ISAR\uart_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Uart_PBCfg.c
CC_FILES_TO_BUILD  += $(UART_BASE_PATH)\src\Uart.c
CC_INCLUDE_PATH    += $(UART_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_I2C),1)
I2C_BASE_PATH     = $(MCAL_PATH_DEMO_CD)\$(AURIX_STEP)\Aurix_MC-ISAR\i2c_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\I2c_PBCfg.c
CC_FILES_TO_BUILD  += $(I2C_BASE_PATH)\src\I2c.c
CC_INCLUDE_PATH    += $(I2C_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_WDG),1)
WDG_BASE_PATH     = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\wdg_17_scu_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Wdg_17_Scu_PBCfg.c
CC_FILES_TO_BUILD  += $(WDG_BASE_PATH)\src\Wdg_17_Scu.c \
					  $(WDG_BASE_PATH)\src\Wdg_17_Scu_Safe.c
CC_INCLUDE_PATH    += $(WDG_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_FEE),1)
FEE_BASE_PATH     = $(MCAL_PATH_MEM)\$(AURIX_STEP)\Aurix_MC-ISAR\fee_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Fee_PBCfg.c
CC_FILES_TO_BUILD  += $(FEE_BASE_PATH)\src\Fee.c \
					  $(FEE_BASE_PATH)\src\Fee_Ver.c
CC_INCLUDE_PATH    += $(FEE_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_FLS),1)
FLS_BASE_PATH     = $(MCAL_PATH_MEM)\$(AURIX_STEP)\Aurix_MC-ISAR\fls_17_pmu_infineon_tricore\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Fls_17_Pmu_PBCfg.c
CC_FILES_TO_BUILD  += $(FLS_BASE_PATH)\src\Fls_17_Pmu.c \
					  $(FLS_BASE_PATH)\src\Fls_17_Pmu_ac.c \
					  $(FLS_BASE_PATH)\src\Fls_17_Pmu_Ver.c \
					  $(IRQ_BASE_PATH)\src\Fls_Irq.c
CC_INCLUDE_PATH    += $(FLS_BASE_PATH)\inc
endif

ifneq ($(MCAL_EXCLUDE_IRQ),1)
IRQ_BASE_PATH     = $(MCAL_PATH_BASE)\$(AURIX_STEP)\Aurix_MC-ISAR\irq_infineon_tricore\ssc
CC_FILES_TO_BUILD  += $(IRQ_BASE_PATH)\src\Irq.c
CC_INCLUDE_PATH    += $(IRQ_BASE_PATH)\inc
endif

# prepared to be added if SafeTlib package is needed
ifneq ($(MCAL_EXCLUDE_SAFETLIB),1)
SAFETLIB_MICROTESTLIB_PATH = $(SAFETLIB_BASE_PATH)\$(AURIX_STEP)\01_SafeTlib\SafeTlibCD\MicroTestLib
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Smu_PBCfg.c
CC_FILES_TO_BUILD  += $(SAFETLIB_BASE_PATH)\$(AURIX_STEP)\01_SafeTlib\SafeTlibCD\SMU\src\Smu.c
CC_INCLUDE_PATH    += $(SAFETLIB_BASE_PATH)\$(AURIX_STEP)\01_SafeTlib\SafeTlibCD\SMU\inc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\TstHandler_PBCfg.c
CC_FILES_TO_BUILD  += $(SAFETLIB_BASE_PATH)\$(AURIX_STEP)\01_SafeTlib\SafeTlibCD\TestHandler\src\TstHandler.c
CC_INCLUDE_PATH    += $(SAFETLIB_BASE_PATH)\$(AURIX_STEP)\01_SafeTlib\SafeTlibCD\TestHandler\inc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\CpuMpuTst_LCfg.c \
						   $(GENDATA_DIR)\src\SfrTst_LCfg.c \
						   $(GENDATA_DIR)\src\CpuBusMpuLfmTst_LCfg.c \
						   $(GENDATA_DIR)\src\TrapTst_LCfg.c \
						   $(GENDATA_DIR)\src\SriTst_LCfg.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\RegAccProtTst_LCfg.c \
						   $(GENDATA_DIR)\src\PflashMonTst_LCfg.c \
						   $(GENDATA_DIR)\src\WdgTst_LCfg.c \
						   $(GENDATA_DIR)\src\SramEccTst_LCfg.c \
						   $(GENDATA_DIR)\src\PhlSramTst_LCfg.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\SpbTst_LCfg.c \
						   $(GENDATA_DIR)\src\DmaTst_LCfg.c \
						   $(GENDATA_DIR)\src\IRTst_LCfg.c \
						   $(GENDATA_DIR)\src\IomTst_LCfg.c \
						   $(GENDATA_DIR)\src\LmuBusMpuLfmTst_LCfg.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\ $(GENDATA_DIR)\src\FceTst_LCfg.c
CC_FILES_TO_BUILD  += $(SAFETLIB_MICROTESTLIB_PATH)\src\CpuMpuTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\Mtl_Trap.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\Mtl_TrapTab.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\SfrCmpTst.c
CC_FILES_TO_BUILD  += $(SAFETLIB_MICROTESTLIB_PATH)\src\SfrCrcTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\CpuBusMpuLfmTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\ClkmTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\VltmTst.c
CC_FILES_TO_BUILD  += $(SAFETLIB_MICROTESTLIB_PATH)\src\SffTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\TrapTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\SriTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\RegAccProtTst.c
CC_FILES_TO_BUILD  += $(SAFETLIB_MICROTESTLIB_PATH)\src\PmuEccEdcTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\PmuEccEdcTst_RefPtrnDef.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\PflashMonTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\WdgTst.c
CC_FILES_TO_BUILD  += $(SAFETLIB_MICROTESTLIB_PATH)\src\SramEccTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\SramEccTst_MemDef.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\PhlSramTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\PhlSramTst_MemDef.c
CC_FILES_TO_BUILD  += $(SAFETLIB_MICROTESTLIB_PATH)\src\CpuSbstTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\LockStepTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\SmuTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\SpbTst.c
CC_FILES_TO_BUILD  += $(SAFETLIB_MICROTESTLIB_PATH)\src\DmaTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\IRTst_IRTab.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\IRTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\IomTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\FceTst.c
ifneq ($(AURIX_STEP),TC26x_BCstep)
CC_FILES_TO_BUILD  += $(SAFETLIB_MICROTESTLIB_PATH)\src\LmuRegAccProtTst.c \
					  $(SAFETLIB_MICROTESTLIB_PATH)\src\LmuBusMpuLfmTst.c
endif
					  
CC_INCLUDE_PATH    += $(SAFETLIB_BASE_PATH)\inc
endif

# prepared to be added if SHE+ package is needed
ifneq ($(MCAL_EXCLUDE_CRY),1)
SHEPLUS_SOURCE_PATH = $(SHEPLUS_BASE_PATH)\AURIX_STEP\Aurix_MC-ISAR\she_infineon_tricore\ssc\src

CC_FILES_TO_BUILD += $(SHEPLUS_SOURCE_PATH)\Cry_Hsm.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesCMacGenerate.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesCMacVerify.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesDecrypt.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesEcbDecrypt.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesEcbEncrypt.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesEncrypt.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesGcmDecrypt.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesGcmEncrypt.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesXtsDecrypt.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmAesXtsEncrypt.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmDebug.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmGetUID.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmKeyExport.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmKeyLoad.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmKeyLoadPlain.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmRandomGenerate.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmRandomSeedExtend.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmRandomSeedInit.c \
					 $(SHEPLUS_SOURCE_PATH)\Cry_HsmSecureBoot.c
endif

CPP_FILES_TO_BUILD +=
ASM_FILES_TO_BUILD +=

#LIBRARIES_LINK_ONLY     += (not yet supported)
#OBJECTS_LINK_ONLY       += (not yet supported)

#-------------------------------------------------------------------------------------------------
#only define new dirs, OBJ, LIB, LOG were created automaticly
#-------------------------------------------------------------------------------------------------
DIRECTORIES_TO_CREATE   +=

#DEPEND_GCC_OPTS         += (not yet supported)

# e.g.:  GENERATED_SOURCE_FILES += $(GENDATA_DIR)\drv_par.c
ADDITIONAL_INCLUDES     += $(GENDATA_DIR)\inc

#e.g.: COMMON_SOURCE_FILES     += $(GENDATA_DIR)\v_par.c
COMMON_SOURCE_FILES     +=

#-------------------------------------------------------------------------------------------------
# <project>.dep & <projekt>.lnk & <project>.bin and.....
# all in err\ & obj\ & lst\ & lib\ & log\ will be deleted by clean-rule automaticly
# so in this clean-rule it is only necessary to define additional files which
# were not delete automaticly.
# e.g.: $(<PATH>)\can_test.c
#-------------------------------------------------------------------------------------------------
MAKE_CLEAN_RULES        +=
#MAKE_GENERATE_RULES     +=
#MAKE_COMPILER_RULES     +=
#MAKE_DEBUG_RULES        +=
#MAKE_CONFIG_RULES       +=
#MAKE_ADD_RULES          +=


###############################################################
# REQUIRED   (defined in BaseMake (global.Makefile.target.make...))
#
# SSC_ROOT		(required)
# PROJECT_ROOT	(required)
#
# LIB_OUTPUT_PATH	(optional)
# OBJ_OUTPUT_PATH	(optional)
#
# OBJ_FILE_SUFFIX
# LIB_FILE_SUFFIX
#
###############################################################


###############################################################
# PROVIDE   this Section can be used to define own additional rules
#
# In vendorx_can_cfg.mak:
# Please configure the project file:
#CAN_CONFIG_FILE = $(PROJECT_ROOT)\source\network\can\my_can_config.cfg

#In vendorx_can_config :
#generate_can_config:
#$(SSC_ROOT)\core\com\can\tools\canconfiggen.exe -o $(CAN_CONFIG_FILE)


###############################################################
# SPECIFIC
#
# There are no rules defined for the Specific part of the
# Rules-Makefile. Each author is free to create temporary
# variables or to use other resources of GNU-MAKE
#
###############################################################


