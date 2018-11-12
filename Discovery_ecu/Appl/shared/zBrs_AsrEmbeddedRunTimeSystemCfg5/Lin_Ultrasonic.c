#include "Lin_Ultrasonic.h"

uint8 count_lin = 0;
uint8 data_lin[8] = {0};
volatile uint8 *test_string_lin = data_lin;
uint8 Sdu_Data_temp[][8] =
{
  {1, 2, 3, 4, 5, 6, 7, 8},
  {0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00}
};
uint8 LinTX_init[3] = {0x01, 0x04, 0x04};
uint8 LinRX_LRU1[8];
uint8 LinRX_SRU3[8];

Lin_PduType Lin_Pdu_temp[] =
{
    /*Lin_FramePidType Pid, Lin_FrameCsModelType Cs,Lin_FrameResponseType Drc,Lin_FrameDlType Dl, uint8 *SduPtr */
    {0x80, LIN_ENHANCED_CS, LIN_MASTER_RESPONSE, 8, Sdu_Data_temp[0]},
    {0xC1, LIN_ENHANCED_CS, LIN_SLAVE_RESPONSE, 8, Sdu_Data_temp[1]},
    {0xC1, LIN_ENHANCED_CS, LIN_MASTER_RESPONSE, 3, LinTX_init},
    {0x1F, LIN_ENHANCED_CS, LIN_SLAVE_RESPONSE, 8, Sdu_Data_temp[1]}
};

void Lin_driver_test()
{
    uint8 retVal_temp;
    uint8 Lin_Channel_temp = 0;
    count_lin++;
    if(count_lin==40)
    retVal_temp = Lin_SendFrame(Lin_Channel_temp, &Lin_Pdu_temp[2]);
    if(count_lin==43)
    {
        retVal_temp = Lin_SendFrame(Lin_Channel_temp, &Lin_Pdu_temp[3]);
        count_lin = 0;
        do
        {
            retVal_temp = Lin_GetStatus(Lin_Channel_temp, (uint8 **)&test_string_lin);
            if ((retVal_temp != LIN_TX_BUSY) && (retVal_temp != LIN_RX_OK)
                && (retVal_temp != LIN_RX_NO_RESPONSE) && (retVal_temp != LIN_RX_BUSY) && (retVal_temp != LIN_OPERATIONAL))
            {
                /* print_f(" Lin Slave->Master Response Failed \n"); */
                /* Uart_Write(0, "error", 8); */
                break;
            }
        }while(retVal_temp != LIN_RX_OK);
        if(retVal_temp == LIN_RX_OK)
        {
            Uart_Write(0, test_string_lin, 3);
        }
    }
}

FUNC(boolean, COM_APPL_CODE) ComIPduTriggerTransmitCallout_Init_LRU1_oLIN00_3abd61be(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    PduInfoPtr->SduLength = 1;
    PduInfoPtr->SduDataPtr = LinTX_init;
    return TRUE;
}
FUNC(boolean, COM_APPL_CODE) ComIPduTriggerTransmitCallout_Init_SRU3_oLIN00_3abd61be(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    PduInfoPtr->SduLength = 2;
    PduInfoPtr->SduDataPtr = &(LinTX_init[1]);
    return TRUE;
}

/* receive data form LRU1 */
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_Read_LRU1_oLIN00_3abd61be(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 *rxptr;
    rxptr=PduInfoPtr->SduDataPtr;
    LinRX_LRU1[0] = *rxptr;
    LinRX_LRU1[1] = *(rxptr+1);
    LinRX_LRU1[2] = *(rxptr+2);
    LinRX_LRU1[3] = *(rxptr+3);
    LinRX_LRU1[4] = *(rxptr+4);
    LinRX_LRU1[5] = *(rxptr+5);
    LinRX_LRU1[6] = *(rxptr+6);
    LinRX_LRU1[7] = *(rxptr+7);
    data_lin[0] = (LinRX_LRU1[1]*256+LinRX_LRU1[0])/59;
    Uart_Write(0, test_string_lin, 1);
    return TRUE;
}

/* receive data form SRU3 */
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_Read_SRU3_oLIN00_3abd61be(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 *rxptr;
    rxptr=PduInfoPtr->SduDataPtr;
    LinRX_SRU3[0] = *rxptr;
    LinRX_SRU3[1] = *(rxptr+1);
    LinRX_SRU3[2] = *(rxptr+2);
    LinRX_SRU3[3] = *(rxptr+3);
    LinRX_SRU3[4] = *(rxptr+4);
    LinRX_SRU3[5] = *(rxptr+5);
    LinRX_SRU3[6] = *(rxptr+6);
    LinRX_SRU3[7] = *(rxptr+7);
    data_lin[0] = (LinRX_SRU3[1]*256+LinRX_SRU3[0])/59;
    Uart_Write(0, test_string_lin, 1);
    return TRUE;
}

