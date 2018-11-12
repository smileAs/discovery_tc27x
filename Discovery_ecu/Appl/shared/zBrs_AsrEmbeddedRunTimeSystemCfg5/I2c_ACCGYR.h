#ifndef _I2c_ACCGYR_H
#define _I2c_ACCGYR_H
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
**  $FILENAME   : I2c_Demo.h $                                               **
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
**                - sample Demo Test for  ADC module                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef float32 I2c_AccDataType;
typedef float32 I2c_GYRDataType;


typedef struct  I2c_AccDataPackettype
{
  I2c_AccDataType AccXData;
  I2c_AccDataType AccYData;
  I2c_AccDataType AccZData;
}I2c_AccDataPackettype;

typedef enum I2c_AccAxistype
{
    I2c_AccAxisX = 0,
    I2c_AccAxisY,
    I2c_AccAxisZ,
}I2c_AccAxistype;


typedef enum I2c_GYRAxistype
{
    I2c_GYRAxisX = 0,
    I2c_GYRAxisY,
    I2c_GYRAxisZ,
}I2c_GYRAxistype;


typedef enum I2c_AccRangetype
{
    I2c_AccRange2g = 0,
    I2c_AccRange4g,
    I2c_AccRange8g,
    I2c_AccRange16g,
}I2c_AccRangetype;



/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define AccAxisX         (0x0U)
#define AccAxisY         (0x2U)
#define AccAxisZ         (0x4U)




/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
extern I2c_PacketInfoType I2c_PacketInfo[I2C_MAX_PACKET];
extern const I2c_ConfigType I2c_ConfigRoot[1];


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

void I2c_ACCGYR (void);
Std_ReturnType I2c_ACCSoftReset (void);
I2c_AccDataType I2c_ACCReadAxis (I2c_AccAxistype I2c_AccAxis);
Std_ReturnType I2c_ACCSelfTest (I2c_AccAxistype I2c_AccAxis);
Std_ReturnType I2c_ACCSetRange (I2c_AccRangetype I2c_AccRange);

uint8 Float2Char(float value,uint8 *array);

#endif
