/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : I2c_Demo.c $                                               **
**                                                                            **
**  $CC VERSION : \main\1 $                                                  **
**                                                                            **
**  $DATE       : 2013-12-04 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                - sample Demo Test for  I2C module                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal.h"
#include "Test_Print.h"
#include "Test_Time.h"
#include "Test_Main.h"
#include "I2c.h"
#include "I2c_Demo.h"
#include "DemoApp_Cfg.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define I2C_NUMBER_OF_BYTES  0x02u
#define PACKET_0             0x00u


/*******************************************************************************
**                      Private Variable Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Syntax : void I2c_Demo(void)                                               **
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
** Return value: none                                                         **
**                                                                            **
** Description : Writes and Reads data from EEPROM asynchromously using QI2Cx **
*******************************************************************************/
void I2c_Demo(void)
{
  uint8 Buffer[I2C_NUMBER_OF_BYTES];
  uint8 LoopCount;
  uint8 Result;

  print_f("------ Start of I2C demo ------\n");

  for (LoopCount=I2C_ZERO;LoopCount<I2C_NUMBER_OF_BYTES;LoopCount++)
  {
    Buffer[LoopCount] = 0x30;
  }

  I2c_SetupPacket(PACKET_0, Buffer);

  print_f("Enter the Data to be written: Enter %d numbers/charaters\n", I2C_NUMBER_OF_BYTES);

  for (LoopCount=I2C_ZERO;LoopCount<I2C_NUMBER_OF_BYTES;LoopCount++)
  {
    print_f("Enter the %d  data:\n", LoopCount);
    getline( (char *)(Buffer + LoopCount), 0 );
    print_f("\n");
  }
  print_f("\n");


  #if (I2C_ASYNC_READ_WRITE == 1U)
  print_f ("ASYNCHRONOUS Writing into EEPROM started\n");
  Result = I2c_AsyncOperation(PACKET_0, I2C_WRITE);
  while(I2c_GetStatus() == I2C_BUSY)
  {
    /* Wait for Async Operation completion*/
  }
  #else
  print_f ("SYNCHRONOUS Writing into EEPROM started\n");
  Result = I2c_SyncOperation(PACKET_0, I2C_WRITE);
  #endif

  if (Result == E_OK)
  {
    print_f ("Writing into EEPROM Successfull\n");
  }
  else
  {
    print_f ("Writing into EEPROM failed\n");
  }
  print_f("\n");

  print_f ("Internal buffer is Flushed i.e Written Zero\n");
  for (LoopCount=I2C_ZERO;LoopCount<I2C_NUMBER_OF_BYTES;LoopCount++)
  {
    Buffer[LoopCount] = 0x30;
  }
  print_f("\n");


  #if (I2C_ASYNC_READ_WRITE == 1U)
  Result = I2c_AsyncOperation(PACKET_0, I2C_READ);
  #else
  Result = I2c_SyncOperation(PACKET_0, I2C_READ);
  #endif

  if (Result == E_OK)
  {
    #if (I2C_ASYNC_READ_WRITE == 1U)
    print_f ("ASYNCHRONOUS Reading from EEPROM Successfull\n");
    #else
    print_f ("SYNCHRONOUS Reading from EEPROM Successfull\n");
    #endif
    print_f ("Data read from EEPROM is following:\n");

    for (LoopCount=I2C_ZERO;LoopCount<I2C_NUMBER_OF_BYTES;LoopCount++)
    {
      put_char(Buffer[LoopCount]);
      put_char('\n');
    }
  }
  else
  {
    print_f ("Reading from EEPROM failed\n");
  }

  print_f("------ End of I2C Demo------\n");
}
