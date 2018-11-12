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
 *          File:  SchM_Spi.h
 *        Config:  discovery_ecu.dpa
 *   ECU-Project:  P2P
 *
 *     Generator:  MICROSAR RTE Generator Version 4.14.0
 *                 RTE Core Version 1.14.0
 *       License:  Unlimited license CBD1800319 for Tong Ji University
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Spi>
 *********************************************************************************************************************/
#ifndef SCHM_SPI_H
# define SCHM_SPI_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Spi_Type.h"

# define SPI_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void); *//* PRQA S 3451 */ /* MD_Rte_3451 */

# define SPI_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Spi_AsyncTransmit(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_AsyncTransmit(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Cancel(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Cancel(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_DeInit(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_DeInit(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_GetSequenceResult(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_GetSequenceResult(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Init(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Init(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_SyncTransmit(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_SyncTransmit(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_WriteIB(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_WriteIB(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_SPI_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
