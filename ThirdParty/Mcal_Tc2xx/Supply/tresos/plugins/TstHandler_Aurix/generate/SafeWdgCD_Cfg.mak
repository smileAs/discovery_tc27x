#******************************************************************************* 
#                                                                             ** 
#* Copyright (C) Infineon Technologies (2014)                                 **
#*                                                                            ** 
#* All rights reserved.                                                       ** 
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       ** 
#* Technologies. Passing on and copying of this document, and communication   ** 
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            ** 
#******************************************************************************* 
#*                                                                            ** 
#*  $FILENAME   : SafeWdgCD_Cfg.mak $                                        **
#*                                                                            **
#*  $CC VERSION : \main\3 $                                                  **
#*                                                                            **
#*  $DATE       : 2014-07-09 $                                               **
#*                                                                            ** 
#*  AUTHOR    : SafeTlib Team                                                 **
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file defines safety lib WDG CD modules delivery ON/OFF** 
#*         - Based on this delivery type values modules will be compiled      **
#*                                                                            ** 
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      ** 
#*                                                                            ** 
#******************************************************************************/ 
#
[!VAR "SafeWdgExtCicModuleUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('SafeWdgExtCic')[1]"!][!//
[!VAR "SafeWdgExtCicModuleUsed" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$SafeWdgExtCicModuleUsed = 'ON'"!][!/*
*/!]SAFEWDGEXTCIC_DELIVERY = ON
[!ELSE!][!/*
*/!]SAFEWDGEXTCIC_DELIVERY = OFF
[!ENDIF!][!//
[!VAR "SafeWdgAscLinModuleUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('SafeWdgAscLin')[1]"!][!//
[!VAR "SafeWdgAscLinModuleUsed" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$SafeWdgAscLinModuleUsed = 'ON'"!][!/*
*/!]SAFEWDGASCLIN_DELIVERY = ON
[!ELSE!][!/*
*/!]SAFEWDGASCLIN_DELIVERY = OFF
[!ENDIF!][!//

[!VAR "SafeWdgExtTlfModuleUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('SafeWdgExtTlf')[1]"!][!//
[!VAR "SafeWdgExtTlfModuleUsed" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$SafeWdgExtTlfModuleUsed = 'ON'"!][!/*
*/!]SAFEWDGEXTTLF_DELIVERY = ON
[!ELSE!][!/*
*/!]SAFEWDGEXTTLF_DELIVERY = OFF
[!ENDIF!][!//
[!VAR "SafeWdgQspiModuleUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('SafeWdgQspi')[1]"!][!//
[!VAR "SafeWdgQspiModuleUsed" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$SafeWdgQspiModuleUsed = 'ON'"!][!/*
*/!]SAFEWDGQSPI_DELIVERY = ON
[!ELSE!][!/*
*/!]SAFEWDGQSPI_DELIVERY = OFF
[!ENDIF!][!//

[!IF "$SafeWdgExtTlfModuleUsed = 'ON' and $SafeWdgExtCicModuleUsed = 'ON'"!]
[!ERROR!]
 Both CIC and TLF watchdog configured. Configure any one of the watchdog as required.
[!ENDERROR!]
[!ENDIF!][!//

[!IF "$SafeWdgQspiModuleUsed = 'ON' and $SafeWdgAscLinModuleUsed = 'ON'"!]
[!ERROR!]
 Both ASCLIN and QSPI modules configured. Configure any one of the modules based on the watchdog used.
[!ENDERROR!]
[!ENDIF!]

[!VAR "SafeWdgExtAliveModuleUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('SafeWdgExtAlive')[1]"!][!//
[!VAR "SafeWdgExtAliveModuleUsed" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$SafeWdgExtAliveModuleUsed = 'ON'"!][!/*
*/!]SAFEWDGEXTALIVE_DELIVERY = ON
[!ELSE!][!/*
*/!]SAFEWDGEXTALIVE_DELIVERY = OFF
[!ENDIF!][!//
[!VAR "SafeWdgIntModuleUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('SafeWdgInt')[1]"!][!//
[!VAR "SafeWdgIntModuleUsed" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$SafeWdgIntModuleUsed = 'ON'"!][!/*
*/!]SAFEWDGINT_DELIVERY = ON
[!ELSE!][!/*
*/!]SAFEWDGINT_DELIVERY = OFF
[!ENDIF!][!//
[!VAR "SafeWdgIfModuleUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('SafeWdgIf')[1]"!][!//
[!VAR "SafeWdgIfModuleUsed" = "'ON'"!][!//
[!ENDSELECT!][!//
[!IF "$SafeWdgIfModuleUsed = 'ON'"!][!/*
*/!]SAFEWDGIF_DELIVERY = ON
[!ELSE!][!/*
*/!]SAFEWDGIF_DELIVERY = OFF
[!ENDIF!][!//