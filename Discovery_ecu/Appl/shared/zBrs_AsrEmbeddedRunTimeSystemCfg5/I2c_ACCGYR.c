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
#include "I2c.h"
#include "I2c_ACCGYR.h"



/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define I2C_NUMBER_OF_BYTES        (0x02u)

/****        Packet Id definitions******/
#define Packet_ACCX                (0x00u)
#define Packet_ACCY                (0x01u)
#define Packet_ACCZ                (0x02u)
#define Packet_GYRX                (0x03u)
#define Packet_GYRY                (0x04u)
#define Packet_GYRZ                (0x05u)



/*******************************************************************************
**                      Private Variable Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                         **
*******************************************************************************/
I2c_GYRDataType GYRDiscovery;
I2c_AccDataType  AccDiscovery;


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
** Syntax : I2c_AccDataType I2c_ACCReadAxis(I2c_AccAxistype I2c_AccAxis)      **
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


I2c_AccDataType I2c_ACCReadAxis(I2c_AccAxistype I2c_AccAxis)
{
  uint8 Buffer[]={0X00};
  uint8 PacketName;
  uint16 ACCReadData0 = 0x0000U;
  sint16 ACCReadData1;

  Std_ReturnType Result;
  I2c_DataType *ACCReadDataPtr;
  I2c_AccDataType ACCReturnData;

 switch (I2c_AccAxis)
 	{
 	case I2c_AccAxisX:
 		{
 		PacketName = Packet_ACCX;
		break;
 		}
	case I2c_AccAxisY:
		{
		PacketName = Packet_ACCY;
		break;
		}
	case I2c_AccAxisZ:
		{
		PacketName = Packet_ACCZ;
		break;
		}
 	}

  I2c_SetupPacket(PacketName, Buffer);

  #if (I2C_ASYNC_READ_WRITE == 1U)
  Result = I2c_AsyncOperation(PacketName, I2C_READ );
  #else
  Result = I2c_SyncOperation(PacketName, I2C_READ );
  #endif

  if (Result == E_OK)
  {
   /************ Data Processing*****************/
    ACCReadDataPtr = I2c_PacketInfo[PacketName].NativeDataPtr;
    ACCReadData0 = *(ACCReadDataPtr);
	ACCReadDataPtr++;
	ACCReadData0 = ACCReadData0 | ( (uint16)*(ACCReadDataPtr) << 8);
	ACCReadData1 = (sint16) ACCReadData0;

	ACCReturnData=(float32)(ACCReadData1*9.8)/(0x8000/2);

	return ACCReturnData;          /**/
  }
  else
  {
    return 0xFFFFFFFF;
  }

}


/*******************************************************************************
** Syntax : I2c_GYRDataType I2c_GYRReadAxis(I2c_GYRAxistype I2c_GYRAxis)      **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): I2c_GYRAxis    Axis of GYR                                **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value: I2c_GYRDataType    Data Read from Each Axis                  **
**                                                                            **
** Description : Read GYR Data of Each Axis                                   **
*******************************************************************************/

I2c_GYRDataType I2c_GYRReadAxis(I2c_GYRAxistype I2c_GYRAxis)
{
  uint8 Buffer[]={0X00};
  uint8 PacketName;
  uint16 GYRReadData0 = 0x0000U;
  sint16 GYRReadData1;

  Std_ReturnType Result;
  I2c_DataType *GYRReadDataPtr;
  I2c_GYRDataType GYRReturnData;

 switch (I2c_GYRAxis)                 /*Switch Axis*/
 	{
 	case I2c_GYRAxisX:
 		{
 		PacketName = Packet_GYRX;
		break;
 		}
	case I2c_GYRAxisY:
		{
		PacketName = Packet_GYRY;
		break;
		}
	case I2c_GYRAxisZ:
		{
		PacketName = Packet_GYRZ;
		break;
		}
 	}

  I2c_SetupPacket(PacketName, Buffer);

  #if (I2C_ASYNC_READ_WRITE == 1U)
  Result = I2c_AsyncOperation(PacketName, I2C_READ );
  #else
  Result = I2c_SyncOperation(PacketName, I2C_READ );
  #endif

  if (Result == E_OK)
  {
    /************ Data Processing*****************/

    GYRReadDataPtr = I2c_PacketInfo[PacketName].NativeDataPtr;
    GYRReadData0 = *(GYRReadDataPtr);
	GYRReadDataPtr++;
	GYRReadData0 = GYRReadData0 | ( (uint16)*(GYRReadDataPtr) << 8);
	GYRReadData1 = (sint16) GYRReadData0;

	GYRReturnData=(float32)(GYRReadData1*2000)/(0x8000);

	return GYRReturnData;
  }
  else
  {
    return 0xFFFFFFFF;
  }

}




/*******************************************************************************
** Syntax : void I2c_ACCGYR (void )                                           **
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
** Description :  I2c_ACCGYR Demo                                             **
*******************************************************************************/

void I2c_ACCGYR (void )
{
  I2c_AccDataType ACCReturnData;
  I2c_GYRDataType GYRReturnData;


  ACCReturnData = I2c_ACCReadAxis(I2c_AccAxisZ);
  AccDiscovery = ACCReturnData;

  GYRReturnData = I2c_GYRReadAxis(I2c_GYRAxisZ);
  GYRDiscovery = GYRReturnData;

 }



