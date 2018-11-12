#######################################################################################################################
# File Name  : Makefile                                                                                               #
# Description: local main project Makefile                                                                            #
# Project    : Vector Basic Runtime System                                                                            #
# Module     : BrsHw for Platform Infineon Aurix                                                                      #
#              and Compiler Hightec GNU,                                                                              #
#              using Vector PES Makesupport 3.13                                                                      #
# Template   : This Makefile is reviewed according to zBrs_Template@root[2.01.00]                                     #
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
# Nika Hamidi                   visnhi        Vector Informatik GmbH                                                  #
# Sascha Mauser                 vismaa        Vector Informatik GmbH                                                  #
# Roland Reinl                  virrro        Vector Informatik GmbH                                                  #
#---------------------------------------------------------------------------------------------------------------------#
# REVISION HISTORY                                                                                                    #
#---------------------------------------------------------------------------------------------------------------------#
# Version   Date        Author  Description                                                                           #
# --------  ----------  ------  --------------------------------------------------------------------------------------#
# 01.00.00  2014-11-24  visbwa  First Version (derived from zBrs_Tricore 2.01.24)                                     #
# 01.00.01  2015-02-24  visbwa  Added BRS_EVA_BOARD_$(EVA_BOARD)                                                      #
# 01.00.02  2015-11-26  visbwa  Fixed BRS_CPU_ to proper BRS_PLATFORM_ defines                                        #
# 02.00.00  2016-03-09  visbwa  Updated to zBrs_Template@root[2.00.00] and Makesupport 3.13                           #
# 02.01.00  2016-06-23  visbwa  Reworked file header structure to fit with Brs_Template 2.00.01                       #
# 02.01.01  2016-09-02  visnhi  Added linkage support for Os_CoreGen7                                                 #
# 02.01.02  2016-12-14  vismaa  Fixed compiler license handling                                                       #
# 02.01.03  2016-12-22  visbwa  Added check for USER_LINKER_COMMAND_FILE within UseCase OsGen7                        #
# 02.01.04  2017-01-09  visbwa  Inserted USER_LINKER_COMMAND_FILE for OsGen7 from Makefile.config                     #
# 02.01.05  2017-02-23  virrro  Moved OsGen7-specific usage of USER_LINKER_COMMAND_FILE from Makefile to              #
#                               Makefile.AURIX.GNU.ALL.make                                                           #
# 03.00.00  2017-05-02  visbwa  Splitted platform/compiler static settings into Makefile.static (Brs_Template 2.01.00)#
# 03.00.01  2017-06-13  visbwa  Moved check for OsGen7 USER_LINKER_COMMAND_FILE from Makefile.static to Makefile      #
#######################################################################################################################

#------------------------------------------------------------------------------
# Name of this project (dir under which the appl dir resides)
# E.g.: TestSuit
#------------------------------------------------------------------------------
PROJECT_NAME = DiscoveryEcu

#------------------------------------------------------------------------------
# More static settings placed inside separate file
#------------------------------------------------------------------------------
include Makefile.static

#------------------------------------------------------------------------------
# Define Compiler path
# E.g.: COMPILER_BASE = D:\uti\%vendor%\%platform%\%version%
#       COMPILER_BIN  = $(COMPILER_BASE)\bin
#       COMPILER_INC  = $(COMPILER_BASE)\inc
#       COMPILER_LIB  = $(COMPILER_BASE)\lib
#------------------------------------------------------------------------------
#COMPILER_BASE = D:\uti\HIGHTEC\TRICORE\V4.6.3.0\toolchains\tricore\v4.6.3.0
COMPILER_BASE = C:\HIGHTEC\toolchains\tricore\v4.6.5.0
COMPILER_BIN  = $(COMPILER_BASE)\bin
COMPILER_INC  = $(COMPILER_BASE)\tricore\include \
                $(COMPILER_BASE)\tricore\include\machine
COMPILER_LIB  = $(COMPILER_BASE)\lib\gcc\tricore\4.6.4 \
                $(COMPILER_BASE)\tricore\lib\tc161

ifeq ($(OS_USECASE),OSGEN7)
  #$(warning For OsGen7, OS-specific LinkerScript as .h file is mandatory! Check the default set up here!)
  #------------------------------------------------------------------------------
  #-------------- Must be filled out for UseCase Os_CoreGen7 --------------------
  # Select the name of the OS-specific Linkerscript.
  # (a sample file (OsGen7_LinkerScript.h) is part of the BRS and 
  #  can be adapted for your special needs)
  #------------------------------------------------------------------------------
  USER_LINKER_COMMAND_FILE = OsGen7_LinkerScript.h
endif

#------------------------------------------------------------------------------
# Build Options Selection: VECTOR / CUSTOMER
#------------------------------------------------------------------------------
ASFLAGS_SELECTOR = VECTOR
CFLAGS_SELECTOR  = VECTOR
LDFLAGS_SELECTOR = VECTOR

#------------------------------------------------------------------------------
# Default License server and port
#------------------------------------------------------------------------------
LICENSE_SERVER = 1790hj2491.iok.la
LICENSE_SERVER_PORT = 36644

#------------------------------------------------------------------------------
# Define Emulator path
# E.g.: EMU_PATH = C:\UTI\HITOPWIN\P6811
#------------------------------------------------------------------------------
EMU_PATH =

#------------------------------------------------------------------------------
# Set NANT_USED to '1', to enable the usage of NAnt support within
# Global Makefile. If this is enabled, the Makesupport will include the
# NAnt support from a intranel link and the NAnt build-targets can be used.
#------------------------------------------------------------------------------
NANT_USED=1
NEW_DEPENDENCY_FORMAT=1
#------------------------------------------------------------------------------
# Set MKVERBOSE to a various value, to enable enhanced debug output from 
# Makesupport. To disable this afterwards, set MKVERBOSE to nothing
# (comment out this line and type "set MKVERBOSE=" in command window)
#------------------------------------------------------------------------------
#MKVERBOSE=1

#------------------------------------------------------------------------------
# Set BRSVINFO_USED to '1', to enable the generation of BrsVInfo.h within the
# GenData folder by the Makesupport.
# The BrsVInfo.h will contain e.g. kBrsCompilerVersion, to use this 
# information within the embedded code.
#------------------------------------------------------------------------------
#BRSVINFO_USED=1

#------------------------------------------------------------------------------
# Turn off strict c setting for dependency generation
#------------------------------------------------------------------------------
#STRICT_C_OFF=1

#------------------------------------------------------------------------------
# Set DELETE_DLD to '1', to enable the deleting of previously 
# generated/outdated Linker-script file, before every new linkage request.
#------------------------------------------------------------------------------
#DELETE_DLD=1

#------------------------------------------------------------------------------
# If you want to use code analysis tools like PC-Lint or QAC,
# configure them within Makefile.analysis (part of global-make-package)
# and inlcude this file here
#------------------------------------------------------------------------------
#include Makefile.analysis

ifeq ($(CORE1_START_IMMEDIATE),)
#Default is 0
CORE1_START_IMMEDIATE = 0
endif
ifeq ($(CORE2_START_IMMEDIATE),)
#Default is 0
CORE2_START_IMMEDIATE = 0
endif

#------------------------------------------------------------------------------
# Dependency defines
# These defines are used for the GNU-Preprocessor,
# e.g.: BRS_TIMEBASE_CLOCK=$(TIMEBASE_CLOCK)
#------------------------------------------------------------------------------
DEP_DEFINES = BRS_DERIVATIVE_$(DERIVATIVE)                       \
              BRS_OSC_CLK=$(MAIN_OSC_CLK)                        \
              BRS_TIMEBASE_CLOCK=$(TIMEBASE_CLOCK)               \
              BRS_OS_USECASE_$(OS_USECASE)                       \
              BRS_EVA_BOARD_$(EVA_BOARD)                         \
              BRS_PLATFORM_$(PLATFORM)                           \
              BRS_COMP_$(COMPILER_MANUFACTURER)                  \
              BRS_CORE1_START_IMMEDIATE=$(CORE1_START_IMMEDIATE) \
              BRS_CORE2_START_IMMEDIATE=$(CORE2_START_IMMEDIATE) \
              __CTC__

#------------------------------------------------------------------------------
# $(AS_ENV) is the environment necessary to run the assembler
# $(AS) defines the path to the assembler
# $(ASFLAGS_VECTOR_MAKESUPPORT) defines all assembler switches, mandatory for
#                               the Vector build environment (Makesupport/BrsHw)
# $(ASFLAGS_VECTOR_OPTIONS) defines the Vector default assembler switches
# $(ASFLAGS_CUSTOMER_OPTIONS) defines the customer requested assembler switches
# Depending of ASFLAGS_SELECTOR, ASFLAGS_VECTOR_OPTIONS or ASFLAGS_CUSTOMER_OPTIONS
# are used together with ASFLAGS_VECTOR_MAKESUPPORT for Build.
#------------------------------------------------------------------------------
# -Wa,<option>     Pass <option> as an option to the assembler.
#
# Enable Listings: '-a[cdhlns]’
# -----------------------------
# -a               Requests highlevel, assembly, and symbols listing.
#                  -ah requests a high-level language listing.
#                  -al requests an output-program assembly listing.
#                  -as requests a symbol table listing.
#                  -ac omits false conditionals from a listing.
#                  -ad omits debugging directives from the listing.
#                  -an turns off all forms processing.
#
# Work Faster: '-f’
# -----------------
# -f               Stops the assembler from doing whitespace and comment
#                  preprocessing on the input file(s) before assembling them.
#
# .include search path: '-I’ path
# -------------------------------
# -I               Adds a path to the list of directories GNU as searches for
#                  files specified in .include directives.
#
# Include Local Labels: '-L’
# --------------------------
# -L               Retains 'L...’ symbols (recognized as local labels) in the
#                  object file.
#
# Configuring listing output: '--listing’
# ---------------------------------------
# --listing-lhs-width='number’
#                  Sets the maximum width, in words, of the first line of the
#                  hex byte dump.
# --listing-lhs-width2='number’
#                  Sets the maximum width, in words, of any further lines of
#                  the hex byte dump for a given inut source line.
# --listing-rhs-width='number’
#                  Sets the maximum width, in characters, of the source line
#                  that is displayed alongside the hex dump.
# --listing-cont-lines='number’
#                  Sets the maximum number of continuation lines of hex dump
#                  that will be displayed for a given single line of source input.
#
# Assemble in MRI Compatibility Mode: '-M’
# ----------------------------------------
# -M               Selects MRI compatibility mode.
#
# Dependency tracking: '--MD’
# ---------------------------
# --MD             Generates a dependency file for the file it creates.
#
# Name the Object File: '-o’
# --------------------------
# -o <outfile>     Outputs resulting binary to <outfile>.
#
# Join Data and Text Sections: '-R’
# ---------------------------------
# -R               Writes the object file as if all data-section data lives in
#                  the text section.
#
# Display Assembly Statistics: '--statistics’
# -------------------------------------------
# --statistics     Displays two statistics about the resources:
#                  - the maximum amount of space allocated during the assembly
#                    (in bytes).
#                  - the total execution time taken for the assembly
#                    (in cpu seconds).
#
# Compatible output: '--traditional-format’
# -----------------------------------------
# --traditional-format
#                  Requests GNU-as to use the traditional format.
#
# Announce Version: '-v’
# ----------------------
# -v               Prints GNU-as' version.
#
# Control Warnings: '-W’, '--warn’, '--no-warn’, '--fatal-warnings’
# -----------------------------------------------------------------
# -W
# --no-warn        Issues no warnings.
# --fatal-warnings Considers files that generate warnings to be in error.
# --warn           Causes warnings to be output as usual.
#
# Generate Object File in Spite of Errors: '-Z’
# ---------------------------------------------
# -Z               Generates output file even if there are errors.
#------------------------------------------------------------------------------
AS_ENV  = $(CC_ENV)
AS      = $(CC)

#Please add only absolutely mandatory options below
ASFLAGS_VECTOR_MAKESUPPORT = -o $(OBJ_PATH)\$*.$(OBJ_SUFFIX)

#Please add any other option below (vector default options)
ASFLAGS_VECTOR_OPTIONS = -x assembler                       \
                         -c                                 \
                         -mcpu=$(MCPU_SWITCH_$(DERIVATIVE)) \
                         -nostartfiles                      \
                         -Wa

#Please enter all customer options below
ASFLAGS_CUSTOMER_OPTIONS =

#------------------------------------------------------------------------------
# $(ASVERSION) defines the assembler switch for version report
# E.g.: ASVERSION = -V
#------------------------------------------------------------------------------
ASVERSION = $(CVERSION)

#------------------------------------------------------------------------------
# $(AS_LC) defines the number of lines used for assembler version information
# in BrsVinfo.h and Deliverydescription (default is 5)
#------------------------------------------------------------------------------
AS_LC =

#------------------------------------------------------------------------------
#------------------------- MUST be filled out ---------------------------------
# $(CC_ENV) is the environment necessary to run the compiler
# $(CC) defines the path to the C-Compiler
# $(CFLAGS_VECTOR_MAKESUPPORT) defines all compiler switches, mandatory for
#                               the Vector build environment (Makesupport/BrsHw)
# $(CFLAGS_VECTOR_OPTIONS) defines the Vector default compiler switches
# $(CFLAGS_CUSTOMER_OPTIONS) defines the customer requested compiler switches
# Depending of CFLAGS_SELECTOR, CFLAGS_VECTOR_OPTIONS or CFLAGS_CUSTOMER_OPTIONS
# are used together with CFLAGS_VECTOR_MAKESUPPORT for Build.
#------------------------------------------------------------------------------
#
# Options Controlling the Kind of Output
# --------------------------------------
# -x <language>    Specify explicitly the language for the following input files.
#                  Possible values for language are:
#                  c, objective-c, c++, c-header, cpp-output, c++-cpp-output,
#                  assembler, assembler-with-cpp
# -x none          Turn of any specification of a language.
# -c               Compile or assemble the source files, but do not link.
# -o <file>        Place output in file <file>.
#                  If '-o’ is not specified, the default is to put an executable
#                  file in 'a.out’.
# -v               Print (on standard error output) the commands executed to run
#                  the stages of compilation. Also print the version number.
# --help           Print (on the standard output) a description of the command
#                  line options understood by gcc.
#
# Options Controlling C Dialect
# -----------------------------
# -ansi            In C mode, support all ANSI standard C programs.
# -funsigned-char  Let the type char be unsigned, like unsigned char.
# -fsigned-bitfields
# -funsigned-bitfields
# -fno-signed-bitfields
# -fno-unsigned-bitfields
#                  These options control whether a bitfield is signed or unsigned,
#                  when the declaration does not use either signed or unsigned.
#                  When '-traditional’ is used, bitfields are all unsigned no
#                  matter what.
#
# Options to Request or Suppress Warnings
# ---------------------------------------
# -Wall            All'-W’ options combined except the ones below.
# -Wconversion     Warn if a prototype causes a type conversion that is
#                  different from what would happen to the same argument in the
#                  absence of a prototype.
# -Wsign-compare   Warn when a comparison between signed and unsigned values
#                  could produce an incorrect result when the signed value is
#                  converted to unsigned.
# -Waggregate-return
#                  Warn if any functions that return structures or unions are
#                  defined or called.
# -Wstrict-prototypes
#                  Warn if a function is declared or defined without specifying
#                  the argument types.
# -Wmissing-prototypes
#                  Warn if a global function is defined without a previous
#                  prototype declaration.
# -Wmissing-declarations
#                  Warn if a global function is defined without a previous
#                  declaration.
# -Wmissing-noreturn
#                  Warn about functions which might be candidates for attribute
#                  noreturn.
#
# Options That Control Optimization
# ---------------------------------
# -O
# -O1              Optimize. Optimizing compilation takes somewhat more time,
#                  and a lot more memory for a large function.
#                  With '-O’, the compiler tries to reduce code size and
#                  execution time.
# -O2              Optimize even more.
# -O3              Optimize yet more.
# -O0              Do not optimize.
# -Os              Optimize for size.
#
# Options Controlling the Preprocessor
# ------------------------------------
# -D<macro>        Define macro <macro> with the string '1’ as its definition.
# -D<macro>=<defn> Define macro <macro> as <defn>.
#
# Options for Directory Search
# ----------------------------
# -I<dir>          Add the directory <dir> to the head of the list of directories
#                  to be searched for header files.
# -I-              Any directories you specify with '-I’ options before the '-I-’
#                  option are searched only for the case of '#include "file"’;
#                  they are not searched for '#include <file>’.
#------------------------------------------------------------------------------
CC_ENV  = export TMPDIR="$(TEMP)"; \
          export RLM_LICENSE=$(LICENSE_SERVER)@$(LICENSE_SERVER_PORT);
CC      = $(COMPILER_BIN)\tricore-gcc.exe

#Please add only absolutely mandatory options below
CFLAGS_VECTOR_MAKESUPPORT = -DBRS_DERIVATIVE_$(DERIVATIVE)                       \
                            -DBRS_OSC_CLK=$(MAIN_OSC_CLK)                        \
                            -DBRS_TIMEBASE_CLOCK=$(TIMEBASE_CLOCK)               \
                            -DBRS_OS_USECASE_$(OS_USECASE)                       \
                            -DBRS_EVA_BOARD_$(EVA_BOARD)                         \
                            -DBRS_PLATFORM_$(PLATFORM)                           \
                            -DBRS_COMP_$(COMPILER_MANUFACTURER)                  \
                            -DBRS_CORE1_START_IMMEDIATE=$(CORE1_START_IMMEDIATE) \
                            -DBRS_CORE2_START_IMMEDIATE=$(CORE2_START_IMMEDIATE) \
                            -c                                                   \
                            -error-file=$(ERR_PATH)\$*.$(ERR_SUFFIX)             \
                            -o $(OBJ_PATH)\$*.$(OBJ_SUFFIX)

MCPU_SWITCH_TC21X = tc21xx
MCPU_SWITCH_TC22X = tc22xx
MCPU_SWITCH_TC23X = tc23xx
MCPU_SWITCH_TC26X = tc26xx
MCPU_SWITCH_TC27X = tc27xx
MCPU_SWITCH_TC29X = tc29xx

ifeq ($(MCPU_SWITCH_$(DERIVATIVE)),)
 $(warning COMPILERFLAGERROR: The compiler option (-mcpu=<value>) is not defined!)
endif

#Please add any other option below (vector default options)
CFLAGS_VECTOR_OPTIONS = -mcpu=$(MCPU_SWITCH_$(DERIVATIVE)) \
                        -O                                 \
                        -g                                 \
                        -save-temps                        \
                        -fno-common                        \
                        -fno-builtin                       \
                        -fno-short-enums                   \
                        -maligned-data-sections            \
                        -iquote                            \
                        -Wl,--gc-sections                  \
                        -Wl,--mem-holes                    \
                        -Wl,--no-warn-flags                \
                        -Wl,--cref                         \
                        -fshort-double

#                        -nostartfiles                              \
#                        -x c                                       \

#Please enter all customer options below
CFLAGS_CUSTOMER_OPTIONS =

# DO NOT optimize for size (-Os)!!! This would block the debugger in some way...
#           -pedantic                                  \
#           -ansi                                      \

#------------------------------------------------------------------------------
# $(CVERSION) defines the compiler switch for version report
# E.g.: CVERSION = -V
#------------------------------------------------------------------------------
CVERSION = -v

#------------------------------------------------------------------------------
# $(CC_LC) defines the number of lines used for compiler version information
# in BrsVinfo.h and Deliverydescription (default is 5)
#------------------------------------------------------------------------------
CC_LC =

#------------------------------------------------------------------------------
# $(CINC) defines the include switch of the used compiler.
# E.g.: COSMIC Compiler use: CINC = -i
#------------------------------------------------------------------------------
CINC = -I

#------------------------------------------------------------------------------
#------------------------- MUST be filled out ---------------------------------
# $(LD_ENV) is the environment necessary to run the linker
# $(LD) defines the path linker
# $(LDFLAGS_VECTOR_MAKESUPPORT) defines all linker switches, mandatory for
#                               the Vector build environment (Makesupport/BrsHw)
# $(LDFLAGS_VECTOR_OPTIONS) defines the Vector default linker switches
# $(LDFLAGS_CUSTOMER_OPTIONS) defines the customer requested linker switches
# Depending of LDFLAGS_SELECTOR, LDFLAGS_VECTOR_OPTIONS or LDFLAGS_CUSTOMER_OPTIONS
# are used together with LDFLAGS_VECTOR_MAKESUPPORT for Build.
#------------------------------------------------------------------------------
#
# -i              Perform an incremental link (same as option '-r’).
#
# -l<archive>
# --library=<archive>
#                 Add archive file <archive> to the list of files to link.
#
# -L<searchdir>
# --library-path=<searchdir>
#                 Add path <searchdir> to the list of paths that ld will search
#                 for archive libraries and ld control scripts.
#
# -o <output>
# --output=<output>
#                 Use <output> as the name for the program produced by ld.
#
# -T <scriptfile>
# --script=<scriptfile>
#                 Use <scriptfile> as the linker script.
#
# -v
# --version
# -V              Display the version number for ld. The '-V’ option also lists
#                 the supported emulations.
#
# --cref          Output a cross reference table. If a linker map file is being
#                 generated, the cross reference table is printed to the map
#                 file. Otherwise, it is printed on the standard output.
#
# --no-gc-sections
# --gc-sections   Enable garbage collection of unused input sections.
#
# --help          Print a summary of the command-line options on the standard
#                 output and exit.
#
# --target-help   Print a summary of all target specific options on the
#                 standard output and exit.
#
# -Map <mapfile>  Print a link map to the file <mapfile>.
#
# --oformat output-format
#                 ld may be configured to support more than one kind of
#                 object file. If your ld is configured this way, you can
#                 use the '--oformat’ option to specify the binary format for
#                 the output object file.
#
# -rpath <dir>    Add a directory to the runtime library search path.
#
# --warn-section-align
#                 Warn if the address of an output section is changed because
#                 of alignment.
#
#------------------------------------------------------------------------------
LD_ENV  = $(CC_ENV)
LD      = $(CC)

#Please add only absolutely mandatory options below
LDFLAGS_VECTOR_MAKESUPPORT =

#Please add any other option below (vector default options)
LDFLAGS_VECTOR_OPTIONS = -mcpu=$(MCPU_SWITCH_$(DERIVATIVE))                 \
                         -o $(PROJECT_NAME).$(BINARY_SUFFIX)                \
                         -Xlinker -Map -Xlinker $(PROJECT_NAME).map         \
                         -nostartfiles                                      \
                         $(addprefix -L,$(COMPILER_LIB))                    \
                         -Xlinker -T -Xlinker $(PROJECT_NAME).$(LNK_SUFFIX) \
                         -mtc161                                            \
                         -lgcc -los

#Please enter all customer options below
LDFLAGS_CUSTOMER_OPTIONS =

#------------------------------------------------------------------------------
# $(LDVERSION) defines the linker switch for version report
# E.g.: LDVERSION = -v
#------------------------------------------------------------------------------
LDVERSION = $(CVERSION)

#------------------------------------------------------------------------------
# $(LD_LC) defines the number of lines used for linker version information
# in BrsVinfo.h and Deliverydescription (default is 5)
#------------------------------------------------------------------------------
LD_LC =

#------------------------------------------------------------------------------
#------------------------- MUST be filled out ---------------------------------
# $(LB_ENV) is the environment necessary to run the librarian
# $(LB) defines the path to the C-librarian
# $(LBFLAGS) defines all librarian switches
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
LB_ENV  = $(LD_ENV)
LB      = $(COMPILER_BIN)\tricore-ar.exe

LBFLAGS = -rvsc $@

#------------------------------------------------------------------------------
# $(LBVERSION) defines the archiver switch for version report
# E.g.: LBVERSION = -v
#------------------------------------------------------------------------------
LBVERSION = -V

#------------------------------------------------------------------------------
# $(LB_LC) defines the number of lines used for librarian version information
# in BrsVinfo.h
#------------------------------------------------------------------------------
LB_LC = 1

#------------------------------------------------------------------------------
# Additional includes essentially for compilation
#------------------------------------------------------------------------------
ADDITIONAL_INCLUDES +=

#------------------------------------------------------------------------------
# Additional objects essentially for linking
# E.g.: ADDITIONAL_OBJECTS = $(OBJ_PATH)\myobject.$(OBJ_SUFFIX)
#------------------------------------------------------------------------------
ADDITIONAL_OBJECTS +=

#------------------------------------------------------------------------------
# List of assembler source files
# E.g.: ASM_SOURCES = source\startup.$(ASM_SUFFIX)
#------------------------------------------------------------------------------
ASM_SOURCES +=

#------------------------------------------------------------------------------
# Add Startup code to application source list
# E.g.: APP_SOURCE_LST += source\startup.c
#------------------------------------------------------------------------------
APP_SOURCE_LST +=

#------------------------------------------------------------------------------
# Check if all necessary variables are set
# (Checks that are not possible to be performed within Makefile.static)
#------------------------------------------------------------------------------
ifeq ($(OS_USECASE),OSGEN7)
  ifeq ($(USER_LINKER_COMMAND_FILE),)
  $(error Variable USER_LINKER_COMMAND_FILE is not defined! Mandatory for linkage of OsGen7)
  endif
endif

###############################################################################
######### DO NOT remove these lines from the end of the Makefile!!! ###########
###############################################################################

#------------------------------------------------------------------------------
# Platform/compiler/derivative/emulator dependant makefile is included here
# It defines a rule to generate the linker and a rule to generate the
# symbol preprocessor command file.
# A template for this Makefile can be found under
#     R:\Can_Base\CANtate\BRS\PlatformSpecific\...\OrganiAndMake\...
#------------------------------------------------------------------------------
include Makefile.$(PLATFORM).$(COMPILER_MANUFACTURER).$(EMULATOR).make

#------------------------------------------------------------------------------
# Include the main makefile where all the targets are defined
#------------------------------------------------------------------------------
include $(MAKESUPPORT_DIR)\Global.Makefile.target.make.$(VERSION)

#End of Makefile
