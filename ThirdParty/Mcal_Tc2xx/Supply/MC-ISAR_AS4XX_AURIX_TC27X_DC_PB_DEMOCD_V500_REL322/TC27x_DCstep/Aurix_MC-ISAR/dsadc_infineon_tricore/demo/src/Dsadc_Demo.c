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
**  $FILENAME   : Dsadc_Demo.c $                                             **
**                                                                           **
**  $CC VERSION : \main\3 $                                                  **
**                                                                           **
**  $DATE       : 2013-09-26 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                sample Demo Test for DSADC module.                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Dsadc.h"
#include "Dsadc_Demo.h"
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
**   
                   Global Variable Definitions                           **
*******************************************************************************/
  uint32 temp_buffer[100U];
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


  
   
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
** Syntax : void Dsadc_Demo(void)                                               **
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

void Dsadc_Demo(void)
{

  uint16 LoopCtr = 0U;
   
  /* Print user information */
  print_f("\n\n\n");
  print_f("\n------------------------------------\n");
  print_f("\n       DSADC DRIVER DEMO MENU         ");
  print_f("\n Read 100 samples in Analog channel0  ");
  print_f("\n------------------------------------\n");


  for(LoopCtr = 0U; LoopCtr < 100U; LoopCtr++)
  {
      temp_buffer[LoopCtr] = 0U;
  }
  Dsadc_StartChannel(Dsadc_Channel0_RunCt | Dsadc_Channel0_Mod_RunCt);
  LoopCtr = 0U; 

  while(LoopCtr < 100U )
  {
	  if((Dsadc_GetResultEventStatus()& Dsadc_Channel0_MainEvent) == Dsadc_Channel0_MainEvent)
	  	{
       temp_buffer[LoopCtr] = Dsadc_GetMainResult(Dsadc_ChannelId_0);

       Dsadc_ClearResultEventStatus(Dsadc_Channel0_MainEvent);
       LoopCtr++;
      }
  }

  for(LoopCtr = 0U; LoopCtr < 100U; LoopCtr++)
  {
  	print_f("\n 0x%X", temp_buffer[LoopCtr]);
  }
  
  Dsadc_StopChannel(Dsadc_Channel0_RunCt | Dsadc_Channel0_Mod_RunCt);

  print_f("\n----------------------------------\n");
  print_f("\n       END OF DSADC DEMO            \n");
  print_f("\n----------------------------------\n");
  return;

} /* Dsadc_Demo */


