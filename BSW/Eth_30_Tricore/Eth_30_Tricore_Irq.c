/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Eth_30_Tricore_Irq.c
 *      Project:  TcpIp-Stack
 *       Module:  Ethernet Driver for Tricore MAC
 *    Generator:  DrvEth_TricoreEthAsr.jar
 *
 *  Description:  interrupt handler
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Eth_30_Tricore.h"
#include "Eth_30_Tricore_Int.h"
#include "Eth_30_Tricore_Regs.h"
#include "Eth_30_Tricore_Lcfg.h"
#if (ETH_30_TRICORE_INTERRUPT_CATEGORY == ETH_30_TRICORE_ISR_CATEGORY_2)
# include "Os.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
#define ETH_30_TRICORE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  EthIsr_0
 **********************************************************************************************************************/
/*! \brief      Ethernet ISR
 *  \context    interrupt level
 *  \note       ISR of controller 0
 **********************************************************************************************************************/
# if ( ETH_30_TRICORE_ENABLE_RX_INTERRUPT == STD_ON ) || ( ETH_30_TRICORE_ENABLE_TX_INTERRUPT == STD_ON )
#  if (ETH_30_TRICORE_INTERRUPT_CATEGORY == ETH_30_TRICORE_ISR_CATEGORY_2)
ISR ( EthIsr_0 )
#  else
FUNC(void, ETH_30_TRICORE_CODE_ISR) EthIsr_0(void) /* PRQA S 3408 */ /* MD_Eth_3408 */
#  endif
{
  uint32 IntFlags;
  Eth_RxStatusType RxStatus = ETH_NOT_RECEIVED;

  do
  {
    /* Read all interrupt flags */
    /* PRQA S 0306 1 */ /* MD_Eth_0306 */
    IntFlags = Eth_30_Tricore_VCtrlRegReadValue(0, ETH_30_TRICORE_REG_OFFS_STATUS);

    if ((0 != (IntFlags & ETH_30_TRICORE_REG_STATUS_RI)) || (ETH_RECEIVED_MORE_DATA_AVAILABLE == RxStatus))
    {
      Eth_30_Tricore_Receive(0, &RxStatus);
      /* PRQA S 0306 1 */ /* MD_Eth_0306 */
      Eth_30_Tricore_VCtrlRegWriteValue(0, ETH_30_TRICORE_REG_OFFS_STATUS, ETH_30_TRICORE_REG_STATUS_RI | ETH_30_TRICORE_REG_STATUS_NIS);
    }
    if (0 != (IntFlags & ETH_30_TRICORE_REG_STATUS_TI))
    {
      Eth_30_Tricore_TxConfirmation(0);
      /* PRQA S 0306 1 */ /* MD_Eth_0306 */
      Eth_30_Tricore_VCtrlRegWriteValue(0, ETH_30_TRICORE_REG_OFFS_STATUS, ETH_30_TRICORE_REG_STATUS_TI | ETH_30_TRICORE_REG_STATUS_NIS);
    }
    if (0 != (IntFlags & ETH_30_TRICORE_REG_STATUS_OVF))
    {
      /* PRQA S 0306 1 */ /* MD_Eth_0306 */
      Eth_30_Tricore_VCtrlRegWriteValue(0, ETH_30_TRICORE_REG_OFFS_STATUS, ETH_30_TRICORE_REG_STATUS_OVF);
    }
  }
  while (ETH_RECEIVED_MORE_DATA_AVAILABLE == RxStatus);
}
# endif
  /* ETH_30_TRICORE_ENABLE_RX_INTERRUPT || ETH_30_TRICORE_ENABLE_TX_INTERRUPT */


#define ETH_30_TRICORE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 1 */ /* MD_MSR_19.1 */


/* module specific MISRA deviations:
 MD_Eth_0303:
      Reason:     Hardware accesses need a cast from integral type to a pointer to object.
      Risk:       There is no risk as the register is mapped to the respective memory address.
      Prevention: Covered by code review.
 MD_Eth_3408
      Reason:     Interrupt service routine shall not be accessed from extern.
      Risk:       There is no risk.
      Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: Eth_30_Tricore_Irq.c
 *********************************************************************************************************************/
