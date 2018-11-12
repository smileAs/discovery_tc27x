/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  disc_ecu.c
 *        Config:  discovery_ecu.dpa
 *     SW-C Type:  disc_ecu
 *
 *     Generator:  MICROSAR RTE Generator Version 4.14.0
 *                 RTE Core Version 1.14.0
 *       License:  Unlimited license CBD1800319 for Tong Ji University
 *
 *   Description:  C-Code implementation template for SW-C <disc_ecu>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Runnable Entities:
 * ==================
 * disc_ecu_main
 *
 *
 *********************************************************************************************************************/
#include "Dio.h"
#include "Uart.h"
#include "Spi.h"
#include "IfxQspi_reg.h"
#include "Rte_disc_ecu.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
//#include "TSC_disc_ecu.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

#include "Can.h"
#include "CanIf.h"
#include "PduR.h"
#include "Com.h"
#include "CanSM.h"
#include "ComM.h"
#include "BswM.h"
#include "EcuM.h"
#include "Qspi_tlf35584.h"
#include "Qspi_gnss.h"
#include "Lin_Ultrasonic.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Com_Cot.h"

#include "Ioc.h"

#include "I2c.h"
#include "I2c_ACCGYR.h"


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * uint32: Integer in interval [0...4294967295] (standard type)
 *
 *********************************************************************************************************************/


#define disc_ecu_START_SEC_CODE
#include "disc_ecu_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: disc_ecu_main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *   - triggered on TimingEvent every 20ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: disc_ecu_main_doc
 *********************************************************************************************************************/
uint32 Ledcounter_10ms = 0;
uint32 stateflag=0;
uint32 counter_10ms = 0;
uint32 can_counter_10ms = 0;
uint8 Can_u8buffer2[8]={0,0,0,0,0,0,0,0};
uint16 Can_u8buffer1 = 0xAAAA;
uint8 GaaByteArray[] = { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22,
                         0x33, 0x44, 0x44, 0x66, 0x77, 0x88, 0x99, 0xAA};
uint8 CanRX_msg1[8];
uint8 CanRX_msg0[8];
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
const uint8 test_string[] = "abcd\r\n";
FUNC(void, disc_ecu_CODE) Core0_Task_10ms(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: disc_ecu_main
 *********************************************************************************************************************/

    uint8 led_flag = 0;
    Can_PduType LddCanPduType;
    uint8 LucHthId;
    counter_10ms++;
    can_counter_10ms++;
	if(can_counter_10ms%50==1)
	{
		LucHthId = CanConf_CN_CAN00_388e5969_Tx_Std;
		LddCanPduType.length = 0x08;
		LddCanPduType.swPduHandle = 0x01;
		LddCanPduType.id = 0x100;
		LddCanPduType.sdu = &GaaByteArray[8];
		/*Can_Write(LucHthId, &LddCanPduType);*/
	}
    if (counter_10ms % 20==1)
    {
        I2c_ACCGYR();
        Dio_FlipChannel(DIO_CHANNEL_15_2);
        IocSend_OsIocCommunication(0xAA);
      /*  Uart_Write(0, test_string, 6);*/
    }
	Com_SendSignal(ComConf_ComSignal_APAAlvRCHSC2_64ef05b4, &Can_u8buffer1);
	Com_ReceiveSignal(ComConf_ComSignal_ABSAHSC2_5ee26fe4, &Can_u8buffer2[0]);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
uint32 time_counter_1s = 0;
boolean flag = TRUE;
FUNC(void, disc_ecu_CODE) Core0_Task_100ms(void)
{
    time_counter_1s++;
    if(time_counter_1s%10 == 1)
    {
        if(flag == TRUE)
        {
            Qspi_gnss_test(TRUE);
            flag = FALSE;
        }
        else
        {
            Qspi_gnss_test(FALSE);
        }
    }
    if(time_counter_1s >= 1000000)
        time_counter_1s = 0;
}
FUNC(void, disc_ecu_CODE) Core0_Task_20ms(void)
{
    /* Lin_driver_test(); */
}
FUNC(void, disc_ecu_CODE) Core0_Task_50ms(void)
{

}



#define disc_ecu_STOP_SEC_CODE
#include "disc_ecu_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(boolean, COM_APPL_CODE) MessageTX_P2P_HSC2_FrP00(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    PduInfoPtr->SduLength = 8;
    PduInfoPtr->SduDataPtr = GaaByteArray;
    return TRUE;
}
/* Configurable interface RxPduCallout */
FUNC(boolean, COM_APPL_CODE) MessageRX_GW_HSC2_FrP13(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
	uint8 *rxptr;
	rxptr=PduInfoPtr->SduDataPtr;
	CanRX_msg0[0] = *rxptr;
	CanRX_msg0[1] = *(rxptr+1);
	CanRX_msg0[2] = *(rxptr+2);
	CanRX_msg0[3] = *(rxptr+3);
	CanRX_msg0[4] = *(rxptr+4);
	CanRX_msg0[5] = *(rxptr+5);
	CanRX_msg0[6] = *(rxptr+6);
	CanRX_msg0[7] = *(rxptr+7);
	return TRUE;
}
FUNC(boolean, COM_APPL_CODE) MessageRX_SCS_HSC2_FrP05(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
	uint8 *rxptr;
	rxptr=PduInfoPtr->SduDataPtr;
	CanRX_msg1[0] = *rxptr;
	CanRX_msg1[1] = *(rxptr+1);
	CanRX_msg1[2] = *(rxptr+2);
	CanRX_msg1[3] = *(rxptr+3);
	CanRX_msg1[4] = *(rxptr+4);
	CanRX_msg1[5] = *(rxptr+5);
	CanRX_msg1[6] = *(rxptr+6);
	CanRX_msg1[7] = *(rxptr+7);
	return TRUE;
}
FUNC(boolean, COM_APPL_CODE) MessageRX_GW_HSC2_HCU_FrP13(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
	uint8 *rxptr;
	rxptr=PduInfoPtr->SduDataPtr;
	CanRX_msg1[0] = *rxptr;
	CanRX_msg1[1] = *(rxptr+1);
	CanRX_msg1[2] = *(rxptr+2);
	CanRX_msg1[3] = *(rxptr+3);
	CanRX_msg1[4] = *(rxptr+4);
	CanRX_msg1[5] = *(rxptr+5);
	CanRX_msg1[6] = *(rxptr+6);
	CanRX_msg1[7] = *(rxptr+7);
	return TRUE;
}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/

