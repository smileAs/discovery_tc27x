/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Msc_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-10 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                sample Demo Test for MSC module.                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Msc.h"
#include "Msc_Demo.h"
#include "Test_Print.h"
#include "Test_Time.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************;***********************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
uint32 Msc_CmdFrame = 0;
uint32 Msc_DataFrame = 0;
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
char MscCmdFrameText[25] = "Command Frame in Hex";
char MscDataFrameText[25] = "Data Frame in Hex";

static const PAR_t Msc_CmdFrameStruct[] = 
{
  {
    PAR_TYP_HEX,                    /* uwType */
    sizeof(Msc_CmdFrame),           /* uwSize */
    &Msc_CmdFrame,                  /* pvData */
    0x0U,                           /* uwMin */
    0xFFFFFFFFU,                    /* uwMax */
    "CommandFrameValue",            /* szText */
    "%x"                            /* szOutputFormat */
  }
};   
   
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
** Syntax : void Msc_Demo(void)                                               **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description :
**                                                                            **
*******************************************************************************/

void Msc_Demo(void)
{

  uint32 LoopCtr;
  uint32 PressedKey;
  Msc_RxStatusType RxStatus;
  uint16 RxData;
  uint32 DataFrame[2] = {0x12341234,0xAAAAAAAA};
  

  /* Print user information */
  print_f("\n\n\n");
  print_f("\n----------------------------------\n");
  print_f("\n       MSC DRIVER DEMO MENU      ");
  print_f("\n        ENTER YOUR OPTION        ");
  print_f("\n----------------------------------\n");
  LoopCtr = 1U;

  while(LoopCtr != 0)
  {

    print_f("\n '1'. Send a Command Frame");
    print_f("\n '2'. Send a Data Frame");
    print_f("\n '3'. Read Status of UD0 register");
    print_f("\n '4'. Read Data in UD0");
    print_f("\n 'x'. Exit and go back to main menu \n");

    /* Get the Key pressed from user */
    PressedKey = get_char();
    if(PressedKey == '1')
    {
      if (ParMenu(&MscCmdFrameText[0], 
             (PAR_t *)Msc_CmdFrameStruct,  
              sizeof Msc_CmdFrameStruct/sizeof Msc_CmdFrameStruct[0]) != 'q')
     {
       Msc_ChangeTxState(0,MSC_TX_ON);
       Msc_TxCmdFrame(0,MSC_TX_DEVICE_0, Msc_CmdFrame);
       print_f("\n Command Frame Sent, Value = 0x%x \n",Msc_CmdFrame);
     }
    }
    else if(PressedKey == '2')
    {
       Msc_ChangeTxState(0,MSC_TX_ON);
       Msc_TxDataFrame(0,MSC_TX_DEVICE_0,MSC_TX_DEVICE_0, &DataFrame[0]);
       print_f("\n Data Frame Sent");    
    }
    else if(PressedKey == '3')
    {
       RxStatus = Msc_GetRxStatus(0,MSC_UD0);
       if(RxStatus==MSC_RX_NOT_OK)
       {
          print_f("\n MSC_RX_NOT_OK.DET Occured \n");
       }
       else if(RxStatus==MSC_DATA_RECEIVED)
       {
          print_f("\n MSC_DATA_RECEIVED.Data Received \n");
       }
       else if(RxStatus==MSC_RX_ERROR)
       {
          print_f("\n MSC_RX_ERROR.Error on Rx");
       }
       else
       {
          print_f("\n MSC_RX_NO_RESPONSE.No Repsonse \n");
       }
    }
    else if(PressedKey == '4')
    {
       Msc_GetRxData(0,MSC_UD0,(uint16*)&RxData);
       print_f("\n Data Received  = 0x%x \n", RxData);
    }
    else if((PressedKey == 'X') || (PressedKey == 'x'))
    {
      LoopCtr = 0;
    }
    else
    {
      print_f("\n  Invalid key pressed,  ");
    }

  }/* while */

  print_f("\n----------------------------------\n");
  print_f("\n       END OF MSC DEMO            \n");
  print_f("\n----------------------------------\n");
  return;

} /* Msc_Demo */


