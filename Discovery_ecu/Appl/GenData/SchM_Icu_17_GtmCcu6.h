/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SchM_Icu_17_GtmCcu6.h
 *        Config:  discovery_ecu.dpa"
 *   ECU-Project:  P2P
 *
 *     Generator:  MICROSAR RTE Generator Version 4.14.0
 *                 RTE Core Version 1.14.0
 *       License:  Unlimited license CBD1800319 for Tong Ji University
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Icu_17_GtmCcu6>
 *********************************************************************************************************************/
#ifndef SCHM_ICU_17_GTMCCU6_H
# define SCHM_ICU_17_GTMCCU6_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Icu_17_GtmCcu6_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_Ccu6IenUpdate(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_Ccu6IenUpdate(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_CcuInterruptHandle(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_CcuInterruptHandle(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_CcuVariableupdate(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_CcuVariableupdate(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_EnableNotification(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_EnableNotification(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_EnableWakeup(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_EnableWakeup(void);
FUNC(void, RTE_CODE) SchM_Enter_Icu_17_GtmCcu6_ResetEdgeCount(void);
FUNC(void, RTE_CODE) SchM_Exit_Icu_17_GtmCcu6_ResetEdgeCount(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_ICU_17_GTMCCU6_H */
