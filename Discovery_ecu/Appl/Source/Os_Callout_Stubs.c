/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Tong Ji University
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC277TP-64
 *    License Scope : The usage is restricted to CBD1800319_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Callout_Stubs.c
 *   Generation Time: 2018-08-04 14:15:27
 *           Project: discovery_ecu - Version 1.0
 *          Delivery: CBD1800319_D00
 *      Tool Version: DaVinci Configurator (beta) 5.15.11 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Os/IdleTask_OsCore_Core0[0:OsTaskPriority](value=-1) is not in range [0, 4294967295].
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/IdleTask_OsCore_Core0[0:OsTaskPriority](value=-1) (DefRef: /MICROSAR/Os/OsTask/OsTaskPriority)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Os/IdleTask_OsCore_Core1[0:OsTaskPriority](value=-1) is not in range [0, 4294967295].
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/IdleTask_OsCore_Core1[0:OsTaskPriority](value=-1) (DefRef: /MICROSAR/Os/OsTask/OsTaskPriority)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/Os/IdleTask_OsCore_Core2[0:OsTaskPriority](value=-1) is not in range [0, 4294967295].
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/IdleTask_OsCore_Core2[0:OsTaskPriority](value=-1) (DefRef: /MICROSAR/Os/OsTask/OsTaskPriority)
 * 
 * [Warning] Cfg95301 - Os Interrupt Service Routine parameter invalid or different to configuration in BSW module 
 * - [Reduced Severity due to User-Defined Parameter] Either this parameter deviates from its definition in the /ActiveEcuC/Can Os Interrupt Service Routine or the definition of this parameter is invalid.
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/CanIsr_1 (DefRef: /MICROSAR/Os/OsIsr)
 * /ActiveEcuC/Os/CanIsr_1[0:OsIsrInterruptPriority](value=11) (DefRef: /MICROSAR/Os/OsIsr/OsIsrInterruptPriority)
 * 
 * [Warning] Cfg95301 - Os Interrupt Service Routine parameter invalid or different to configuration in BSW module 
 * - [Reduced Severity due to User-Defined Parameter] Either this parameter deviates from its definition in the /ActiveEcuC/Can Os Interrupt Service Routine or the definition of this parameter is invalid.
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/CanIsr_2 (DefRef: /MICROSAR/Os/OsIsr)
 * /ActiveEcuC/Os/CanIsr_2[0:OsIsrInterruptPriority](value=12) (DefRef: /MICROSAR/Os/OsIsr/OsIsrInterruptPriority)
 *********************************************************************************************************************/
#define OS_CALLOUT_STUBS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Os.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_Include>
 *********************************************************************************************************************/
#include "EcuM.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StartupHook()
 *********************************************************************************************************************/
#if OS_CFG_STARTUPHOOK_SYSTEM == STD_ON
# define OS_START_SEC_STARTUPHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, OS_STARTUPHOOK_CODE) StartupHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_StartupHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_STARTUPHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* OS_CFG_STARTUPHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ShutdownHook()
 *********************************************************************************************************************/
#if OS_CFG_SHUTDOWNHOOK_SYSTEM == STD_ON
# define OS_START_SEC_SHUTDOWNHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, OS_SHUTDOWNHOOK_CODE) ShutdownHook(StatusType Fatalerror)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ShutdownHook>
 *********************************************************************************************************************/
  EcuM_Shutdown();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_SHUTDOWNHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* OS_CFG_SHUTDOWNHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ErrorHook()
 *********************************************************************************************************************/
#if OS_CFG_ERRORHOOK_SYSTEM == STD_ON
# define OS_START_SEC_ERRORHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, OS_ERRORHOOK_CODE) ErrorHook(StatusType Error)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ErrorHook>
 *********************************************************************************************************************/
  Os_ErrorInformationType CurrentError;
  volatile uint8 endless = 1u;
  (void)Os_GetDetailedError(&CurrentError);
  while(endless)
  {
    
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_ERRORHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* OS_CFG_ERRORHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ProtectionHook()
 *********************************************************************************************************************/
#if OS_CFG_PROTECTIONHOOK_SYSTEM == STD_ON
# define OS_START_SEC_PROTECTIONHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(ProtectionReturnType, OS_PROTECTIONHOOK_CODE) ProtectionHook(StatusType Fatalerror)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ProtectionHook>
 *********************************************************************************************************************/
  return PRO_SHUTDOWN;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PROTECTIONHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* OS_CFG_PROTECTIONHOOK_SYSTEM */


/**********************************************************************************************************************
 *  PreTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_PRETASKHOOK == STD_ON
# define OS_START_SEC_PRETASKHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, OS_PRETASKHOOK_CODE) PreTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PreTaskHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PRETASKHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* OS_CFG_PRETASKHOOK */


/**********************************************************************************************************************
 *  PostTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_POSTTASKHOOK == STD_ON
# define OS_START_SEC_POSTTASKHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, OS_POSTTASKHOOK_CODE) PostTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PostTaskHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_POSTTASKHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* OS_CFG_POSTTASKHOOK */


/**********************************************************************************************************************
 *  Os_PanicHook()
 *********************************************************************************************************************/
#if OS_CFG_PANICHOOK == STD_ON
# define OS_START_SEC_PANICHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, OS_PANICHOOK_CODE) Os_PanicHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PanicHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PANICHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* OS_CFG_PANICHOOK */



/* Unrecognized User Blocks */
#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: Os_Callout_Stubs.c
 *********************************************************************************************************************/
