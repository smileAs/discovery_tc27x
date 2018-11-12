/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Hssl_Demo.c $                                              **
**                                                                           **
**  $CC VERSION : \main\18 $                                                 **
**                                                                           **
**  $DATE       : 2015-10-14 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Demo Application for HSSL driver.                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
    TRACEABILITY : [cover parentID=] [/cover]
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Test_Main.h"
#include "Test_Print.h"
#include "Hssl_Demo.h"
#include "Mcal.h"
#include "IfxStm_reg.h"
#include "IfxPort_reg.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
void HSCT_lInit(uint8 Mode) ;
uint8 HSCT_lReset(void) ;
void Hssl_lSendControlCommand(uint32 PayloadVal) ;
void HsslDemo_lDelay(unsigned int delay) ;

/*******************************************************************************
**                      Private Macro Declarations                            **
*******************************************************************************/
#define HSCT_MASTER              (0U)
#define HSCT_SLAVE               (1U)
                                 
#define HSCT_MODE                (HSCT_MASTER)
                                 
#define HSCT_P21_LPCR2_MASK      (0x00E0U)
#define HSCT_LOW_SPEED           (0U)
#define HSCT_MEDIUM_SPEED        (1U)
#define HSCT_HIGH_SPEED          (2U)
#define HSCT_SPEED               (HSCT_LOW_SPEED)

#define PLL_REF_CLOCK_SYS_CLK_IP (0U)
#define PLL_REF_CLOCK_OSC_IP     (1U)

/* Interface Command PayLoad Values */
#define HSCT_IFCTRL_PING              (0x00U)
#define HSCT_IFCTRL_SLAVE_MUX_START   (0x02U)
#define HSCT_IFCTRL_SLAVE_MUX_STOP    (0x04U)
#define HSCT_IFCTRL_TX_LINK_LS        (0x08U)
#define HSCT_IFCTRL_TX_LINK_HS        (0x10U)
#define HSCT_IFCTRL_RX_LINK_LS        (0x20U)
#define HSCT_IFCTRL_RX_LINK_MS        (0x40U)
#define HSCT_IFCTRL_RX_LINK_HS        (0x80U)
#define HSCT_IFCTRL_SLAVE_TX_ON       (0x31U)
#define HSCT_IFCTRL_SLAVE_TX_OFF      (0x32U)
#define HSCT_IFCTRL_SLAVE_TEST_ON     (0x34U)
#define HSCT_IFCTRL_SLAVE_TEST_OFF    (0x38U)
#define HSCT_IFCTRL_SLAVE_LOOP_ON     (0xFFU)

/* RXDN --> 21.2 , RXDP --> 21.3 */
/* TXDN --> 21.4 , TXDP --> 21.5 */
/* P21_LPCR2 : TDIS_CTRL = 1,TX_DIS = 0, TX_PD = 0,RX_DIS = 0 */
/* SYSCLK --> 20.0 */
#define IO_INIT_HSCT_LVDS    { P21_IOCR0.U = 0x00000000;  \
                               P21_IOCR4.U = 0x00008080;  \
                               Mcal_ResetENDINIT();       \
                               P21_LPCR1.B_P21.RDIS_CTRL = 1; \
                               P21_LPCR2.U  = HSCT_P21_LPCR2_MASK;\
                               Mcal_SetENDINIT();}

#define IO_RELEASE_HSCT_LVDS { P21_IOCR0.U = 0x10101010; \
                               P21_IOCR4.U = 0x10101010; \
                               Mcal_ResetENDINIT(); \
                               P21_LPCR1.B_P21.RDIS_CTRL = 0; \
                               P21_LPCR1.B_P21.RX_DIS = 1; \
                               P21_LPCR2.B.TDIS_CTRL = 0; \
                               P21_LPCR2.B.TX_DIS = 1; \
                               P21_LPCR2.B.TX_PD = 1; \
                               Mcal_SetENDINIT();}
/*PAD_IN_PULL_DN; */
#define IO_INIT_HSCT_CLKIN   { P20_IOCR0.B.PC0 = 0x1U ;}
/* PAD_OUT_PP_ALT5; */
#define IO_INIT_HSCT_CLKOUT  { P20_IOCR0.B.PC0 = 0x15U ;}


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define HSSL_START_SEC_VAR_FAST_32BIT
#include "MemMap.h"

uint32 SrcAddrStart[32U] ;
Hssl_DataTemplateType WriteData[2U];
Hssl_DataTemplateType ReadData[2U];
uint32 DataBuffer[4U];
uint32 AddrBuffer[4U];

#define HSSL_STOP_SEC_VAR_FAST_32BIT
#include "MemMap.h"
/*******************************************************************************
** Syntax : void Hssl_Demo(void)                                              **
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
** Description : HSSL driver Demo function                                    **
*******************************************************************************/
void Hssl_Demo(void)
{

#if (HSCT_MODE == HSCT_MASTER)
  
  uint8 TempUSage = 1;
  char szString[80];

  while (TempUSage == 1)
  {
    print_f("\n");
    print_f("\n/*********************************************************/\n");
    print_f("\n           HSSL DRIVER DEMO MENU                          ");
    print_f("\n                                                         ");
    print_f("\n 1: Hssl Register Write");
    print_f("\n 2: Hssl Register Read");
    print_f("\n 3: Multiple Hssl Register Write");
    print_f("\n 4: Multiple Hssl Register Read");
    print_f("\n 5: Start Stream Data");
    print_f("\n 6: Stop Stream Data");
    print_f("\n 7: Read ID");
    print_f("\n x. Go back to Main Menu    ");
    print_f("\n  ENTER YOUR OPTION   : ");
    getline(szString, sizeof szString - 1);

     switch (*szString)
     {
      case '1':
        Hssl_RegisterWriteDemo();
        break;
      case '2':
        Hssl_RegisterReadDemo();
        break;
      case '3':
        Hssl_MultipleRegisterWriteDemo();
        break;
      case '4':
        Hssl_MultipleRegisterReadDemo();
        break;
      case '5':
        Hssl_StartStreamingDemo();
        break;
      case '6':
        Hssl_StopStreamingDemo();
        break;
      case '7':
        Hssl_IDReadDemo();
        break;
      case 'x':
      case 'X':
        TempUSage = 0;
        print_f("\n\n/*************************************************/\n\n");
        break;
      default:
        print_f("\n\n  INVALID OPTION \n\n");
        break;
    }
  }
#else
  /* HSCT Slave */
  
  Hssl_ChannelType Channel;  
  
  print_f("\n HSSL Demo : Slave Application \n");
  
  HSCT_lInit(HSCT_SLAVE) ;
  /* Put HSSL in Init Mode */
  Hssl_SetMode(HSSL_MODE_INIT) ;
  Hssl_Init (0xff) ;
  Hssl_SetMode(HSSL_MODE_RUN) ;
  Channel.Number = 0U;
  Channel.Timeout = 0xFFU;

  Hssl_InitChannel(Channel, 0U,0U,0U,0U,0U,0U);
  
  while(1);
#endif  
}

/*******************************************************************************
** Syntax : void Hssl_RegisterWriteDemo(void)                                 **
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
** Description : This routine performs a direct write transfer.               **
*******************************************************************************/
void Hssl_RegisterWriteDemo(void)
{
  Hssl_ChannelType channel;
  uint32 Error ;
  Hssl_DataTemplateType WriteData ;
  static uint32 DataBuffer = 0x2A80;
  uint32 DataAddr ;
  
  print_f("\n\n Hssl Register Write Demo\r\n" );
  
  /* call HSSL and HSCT init */
  HSCT_lInit(HSCT_MASTER) ;

  /* Put HSSL in Init Mode */
  Hssl_SetMode(HSSL_MODE_INIT) ;
  Hssl_Init (0xff) ;
  Hssl_SetMode(HSSL_MODE_RUN) ;
  channel.Number = 0U;
  channel.Timeout = 0xFFU;

  /* Send Enable Slave Transmitter */
  HSCT_IFCTRL.B.IFCVS = HSCT_IFCTRL_SLAVE_TX_ON;
  HSCT_IFCTRL.B.SIFCV = 1U;
  while (HSCT_IFCTRL.B.SIFCV);
  while (!HSCT_IRQ.B.IFCFS);
  HSCT_IRQCLR.B.IFCFSCLR = 1U;
  HsslDemo_lDelay (1000); 

  DataBuffer = DataBuffer ^ 0xFFFF;
  WriteData.Data = &DataBuffer ;
  DataAddr =  0x70003410U;
  WriteData.Address = &DataAddr;

  print_f ("Writting to address= %x Data = %x  \r\n" , DataAddr , DataBuffer);

  Hssl_InitChannel(channel, 0U,0U,0U,0U,0U,0U);

  Error = Hssl_Write (&WriteData, HSSL_DATA_SIZE_32BIT, channel ,0U);

  if(!Error)
  {
    Error = Hssl_WriteAck(channel);

    if(Error)
    {
      print_f ("Error while Writting : %x \r\n" , Error) ;
    }
    else
    {
      print_f("data sent \r\n");
    }
  }

  Hssl_Reset ();
  HSCT_lReset ();
}

/*******************************************************************************
** Syntax : void Hssl_RegisterReadDemo(void)                                  **
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
** Description : This routine Reads Data from the microcontroller             **
*******************************************************************************/
void Hssl_RegisterReadDemo(void )
{
  Hssl_ChannelType channel;
  uint32 Error ;
  Hssl_DataTemplateType data_address ;
  uint32 DataBuffer ;
  uint32 DataAddr ;
  
  print_f("\n\n Hssl Register Read Demo\r\n" );

  /* call HSSL and HSCT init */
  HSCT_lInit(HSCT_MASTER) ;

  /* Put HSSL in Init Mode */
  Hssl_SetMode(HSSL_MODE_INIT) ;
  Hssl_Init (0xff) ;
  Hssl_SetMode(HSSL_MODE_RUN) ;

  /* Send Enable Slave Transmitter */
  HSCT_IFCTRL.B.IFCVS = HSCT_IFCTRL_SLAVE_TX_ON;
  HSCT_IFCTRL.B.SIFCV = 1U;
  while (HSCT_IFCTRL.B.SIFCV);
  while (!HSCT_IRQ.B.IFCFS);
  HSCT_IRQCLR.B.IFCFSCLR = 1U;
  HsslDemo_lDelay (1000);

  channel.Number = 0U;
  channel.Timeout = 0xFFU;
  data_address.Data = &DataBuffer;
  DataAddr = 0x70003410U;
  data_address.Address = &DataAddr;

  Hssl_InitChannel(channel, 0U,0U,0U,0U,0U,0U);

  print_f ("Reading From Address =  %x \r\n" , DataAddr) ;

  Error = Hssl_Read( &data_address , HSSL_DATA_SIZE_32BIT, channel ,0U);

  if(!Error)
  {
    Error = Hssl_ReadRply(&data_address , channel) ;

    if(Error)
    {
      print_f ("Error while reading : %x \r\n" , Error) ;
    }
    else
    {
      print_f ("Data read is : %x \r\n" , DataBuffer) ;
    }
  }

  Hssl_Reset ();
  HSCT_lReset ();
}

/*******************************************************************************
** Syntax : void Hssl_RegisterWriteDemo(void)                                 **
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
** Description : This routine does direct transfer of multiple set of data    **
*******************************************************************************/
void Hssl_MultipleRegisterWriteDemo(void )
{
  Hssl_ChannelType channel;
  uint32 Error ;

  print_f("\n\n Hssl Multiple Register Write Demo\r\n" );
  
  /* call HSSL and HSCT init */
  HSCT_lInit(HSCT_MASTER) ;

  /* Put HSSL in Init Mode */
  Hssl_SetMode(HSSL_MODE_INIT) ;
  Hssl_Init (0xff) ;
  Hssl_SetMode(HSSL_MODE_RUN) ;

  Hssl_lSendControlCommand(HSCT_IFCTRL_TX_LINK_LS);

  channel.Number = 0U;
  channel.Timeout = 0xFFU;

  DataBuffer[0U] = 0x12345678U;
  DataBuffer[1U] = 0x70003410U;
  DataBuffer[2U] = 0x55667788U;
  DataBuffer[3U] = 0x70003400U;

  WriteData[0U].Data = &DataBuffer[0U] ;
  WriteData[0U].Address = &DataBuffer[1U];
  WriteData[1U].Data = &DataBuffer[2U] ;
  WriteData[1U].Address = &DataBuffer[3U];

  Hssl_InitChannel(channel, 0U,0U,0U,0U,0U,0U);

  Error = Hssl_MultiWrite ((Hssl_DataTemplateType *)WriteData, \
  HSSL_DATA_SIZE_32BIT, 4U, channel ,0U);
  
  if(Error)
  {
    print_f ("Error while Writting : %x \r\n" , Error) ;
  }
  else
  {
    print_f("data sent \r\n");
  }
  
  DataBuffer[0U] = 0x12345678U;
  DataBuffer[1U] = 0x70003510U;
  DataBuffer[2U] = 0x55667788U;
  DataBuffer[3U] = 0x70003500U;

  WriteData[0U].Data = &DataBuffer[0U] ;
  WriteData[0U].Address = &DataBuffer[1U];
  WriteData[1U].Data = &DataBuffer[2U] ;
  WriteData[1U].Address = &DataBuffer[3U];

  Hssl_InitChannel(channel, 0U,0U,0U,0U,0U,0U);

  Error = Hssl_MultiWrite ((Hssl_DataTemplateType *)WriteData, \
  HSSL_DATA_SIZE_32BIT, 4U, channel ,0U);

  if(Error)
  {
    print_f ("Error while Writting : %x \r\n" , Error) ;
  }
  else
  {
    print_f("data sent \r\n");
  }

  Hssl_Reset ();
  HSCT_lReset ();
}

/*******************************************************************************
** Syntax : void Hssl_RegisterReadDemo(void)                                 **
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
** Description : This routine does reading of multiple set of data            **
*******************************************************************************/
void Hssl_MultipleRegisterReadDemo(void )
{
  Hssl_ChannelType channel;
  uint32 Error ;
   
  print_f("\n\n Hssl Multiple Register Read Demo \r\n" );
  
  /* call HSSL and HSCT init */
  HSCT_lInit(HSCT_MASTER) ;

  /* Put HSSL in Init Mode */
  Hssl_SetMode(HSSL_MODE_INIT) ;
  Hssl_Init (0xff) ;
  Hssl_SetMode(HSSL_MODE_RUN) ;

  Hssl_lSendControlCommand(HSCT_IFCTRL_TX_LINK_LS);

  channel.Number = 0U;
  channel.Timeout = 0xFFU;

  DataBuffer[0U] = 0U;
  DataBuffer[1U] = 0U;

  AddrBuffer[0U] = 0x70003408U ;
  AddrBuffer[1U] = 0x70003410U ;

  ReadData[0U].Data = &DataBuffer[0U];
  ReadData[0U].Address = &AddrBuffer[0U];

  ReadData[1U].Data = &DataBuffer[1U] ;
  ReadData[1U].Address = &AddrBuffer[1U];

  Hssl_InitChannel(channel, 0U,0U,0U,0U,0U,0U);

  Error =  Hssl_MultiRead ((struct Hssl_DataTemplateType *)ReadData, \
  HSSL_DATA_SIZE_32BIT, 2U, channel ,0U);

  if(Error)
  {
    print_f ("Error while Multiple Register Read : %x \r\n" , Error) ;
  }
  else
  {
    print_f("Multiple Register Data read: Address0 = %x , Data0 = %x , \
     Address1 = %x , Data1 = %x \r\n" , AddrBuffer[0U] , \
     DataBuffer[0U] , AddrBuffer[1U] , DataBuffer[1U]);
  }

  Hssl_Reset ();
  HSCT_lReset ();
}

/*******************************************************************************
** Syntax : void Hssl_RegisterReadDemo(void)                                 **
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
** Description : This routine Reads the ID                                    **
*******************************************************************************/
void Hssl_IDReadDemo(void )
{
  Hssl_ChannelType channel;
  uint32 store_address ;

  print_f("\n\n Hssl ID Read Demo \r\n" );
  
  /* call HSSL and HSCT init */
  HSCT_lInit(HSCT_MASTER) ;

  /* Put HSSL in Init Mode */
  Hssl_SetMode(HSSL_MODE_INIT) ;
  Hssl_Init (0xff) ;
  Hssl_SetMode(HSSL_MODE_RUN) ;

  Hssl_lSendControlCommand(HSCT_IFCTRL_TX_LINK_LS);

  Hssl_lSendControlCommand(0x12);
  
  channel.Number = 0U;
  channel.Timeout = 0xFFU;

  Hssl_InitChannel(channel, 0U,0U,0U,0U,0U,0U);

  Hssl_Id(&store_address);
  print_f("Read ID = %x" , store_address);

  Hssl_Reset ();
  HSCT_lReset ();

}

/*******************************************************************************
** Syntax : void Hssl_StartStreamingDemo(void)                                 **
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
** Description : This routine does a streaming transfer                       **
*******************************************************************************/
void Hssl_StartStreamingDemo(void )
{
  uint32 Error ;
  uint32 Index;
  uint16 DataSize;
  Hssl_ChannelType channel;

  print_f("\n\n Hssl Start Streaming Demo\r\n" );

  /* call HSSL and HSCT init */
  HSCT_lInit(HSCT_MASTER) ;

  /* Put HSSL in Init Mode */
  Hssl_SetMode(HSSL_MODE_INIT) ;
  Hssl_Init (0xff) ;
  Hssl_SetMode(HSSL_MODE_RUN) ;

  Hssl_lSendControlCommand(HSCT_IFCTRL_TX_LINK_LS);

  channel.Number = 0U;
  channel.Timeout = 0xFFU;

  Hssl_InitChannel(channel, 0U,0U,0U,0U,0U,0U);

  DataSize = 20U;

  for(Index = 0U; Index < DataSize; Index++)
  {
    SrcAddrStart[Index] = Index;
  }

  Error =  Hssl_StartStream ( SrcAddrStart, DataSize, 0U );

  if(Error)
  {
    print_f ("Error while Writting : %x \r\n" , Error) ;
  }
  else
  {
    print_f("data sent \r\n");
  }
}


/*******************************************************************************
** Syntax : void Hssl_StopStreamingDemo(void)                                 **
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
** Description : This routine Stope the the streaming transfer               **
*******************************************************************************/
void Hssl_StopStreamingDemo(void )
{
  print_f("\n\n Hssl Stop Streaming Demo\r\n" );
  Hssl_StopStream();

  Hssl_Reset ();
  HSCT_lReset ();
}


/*******************************************************************************
** Syntax : void Hssl_User_Fn(void)                                           **
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
** Description : This routine is a user defined function                      **
*******************************************************************************/
/* User function for HSSL */
void Hssl_User_Fn (void)
{
  /* */
  print_f ("\n\n HSSL user function  with Hssl Code = %d \r\n" ) ;

}

/* HSCT related functions */
/*******************************************************************************
** Syntax : void HSCT_lReset(void)                                            **
** Description :                                                              **
**  This function performs soft reset of module. Clears all status and error
**  registers, returning the module to 'Disabled'. Any transfers in progress,
    when reset executed will immediately end. Returns '0' if successful,
    error code otherwise.                                                     **
**  return Returns '0' if successful, error code otherwise.                   **
*******************************************************************************/
uint8 HSCT_lReset(void)
{
  Mcal_ResetENDINIT();
  HSCT_KRST0.B.RST  = 1U;
  HSCT_KRST1.B.RST = 1U;
  Mcal_SetENDINIT();

  return 0U;
}

/*******************************************************************************
** Syntax : void HSCT_lInit(uint8 Mode)
** Description : This function initializes Pysical layer HSCT
*******************************************************************************/
void HSCT_lInit(uint8 Mode)
{
  /* Select the IO pins */
  /* P21.5 and 21.4 are used as TXDP and TXDN ,
     P21.2 and P21.3 used as RXDN and RXDP  */
  IO_INIT_HSCT_LVDS;

  /* Enable HSCT module */
  Mcal_ResetENDINIT( );
  HSCT_CLC.U = 0;
  /* Wait for DISS bit to be cleared */
  while (HSCT_CLC.U);
  Mcal_SetENDINIT( );

  HSCT_IRQCLR.B.TXTECLR = 1;
 /* Not Required now as LVDS has been moved to PORT Config */

   /* Select interface Mode INIT.IFM */
  HSCT_INIT.B.IFM  = Mode;

  if(Mode == HSCT_MASTER)
  {
      /* P20.0 --> If master SYSCLK is output , else SYSCLK is a input */
    IO_INIT_HSCT_CLKOUT;
     /* enable the SysClk INIT.SYS_CLK_EN */
    HSCT_INIT.B.SYS_CLK_EN = 1U;
    /* Select the Sysclokc / Reference Clock */
    HSCT_INIT.B.SRCF = 0U ; /* 0-20Mhz, 1- 10MHz */
    /* PLL reference clock is Oscillator input */
    HSCT_CONFIGPHY.B.OSCCLKEN = PLL_REF_CLOCK_OSC_IP;
    HSCT_CONFIGPHY.B.PHYRST   = 0U;
    HSCT_CONFIGPHY.B.PLLPON = 1U;
    /* Low speed its don't care */
    HSCT_CONFIGPHY.B.PLLWMF = 16U;
    /* Low Speed */

    HSCT_IFCTRL.B.MTXSPEED  = HSCT_LOW_SPEED;
    HSCT_IFCTRL.B.MRXSPEED  = HSCT_LOW_SPEED;

#if (HSCT_SPEED == HSCT_HIGH_SPEED)
      /* High Speed */
    HSCT_IFCTRL.B.MTXSPEED  = HSCT_HIGH_SPEED;
    HSCT_IFCTRL.B.MRXSPEED  = HSCT_HIGH_SPEED;
#endif
    while (HSCT_STATPHY.B.PLOCK == 0)
    {

    }
    HsslDemo_lDelay (0x00000500);
  }
  else
  {
    /* slave interface */

    IO_INIT_HSCT_CLKIN;
    /* disable the SysClk INIT.SYS_CLK_EN */
    HSCT_INIT.B.SYS_CLK_EN = 0U;
    /* Select the Sysclokc / Reference Clock */
    HSCT_INIT.B.SRCF = 0U ; /* 0-20Mhz, 1- 10MHz */
    /* PLL reference clock is HSCT SysClk_i */
    HSCT_CONFIGPHY.B.OSCCLKEN = PLL_REF_CLOCK_SYS_CLK_IP;
    HSCT_CONFIGPHY.B.PHYRST   = 0U;
    HSCT_CONFIGPHY.B.PLLWMF = 16U;
     /* Low Speed */
    HSCT_IFCTRL.B.MTXSPEED  = HSCT_LOW_SPEED;
    HSCT_IFCTRL.B.MRXSPEED  = HSCT_LOW_SPEED;

    HsslDemo_lDelay (0x00000500);

#if (HSCT_SPEED == HSCT_HIGH_SPEED)
    HSCT_IFCTRL.B.MTXSPEED  = HSCT_HIGH_SPEED;
    HSCT_IFCTRL.B.MRXSPEED  = HSCT_HIGH_SPEED;

    HSCT_CONFIGPHY.B.OSCCLKEN = PLL_REF_CLOCK_OSC_IP;
  Hssl_lSendControlCommand (HSCT_IFCTRL_SLAVE_MUX_START);
    Hssl_lSendControlCommand (HSCT_IFCTRL_TX_LINK_HS);
    Hssl_lSendControlCommand (HSCT_IFCTRL_RX_LINK_HS);
#endif

  }

  HsslDemo_lDelay (0x00001000);
  HSCT_DISABLE.U = 0U;

  /* Enable all the interrupts in IRQEN and clear previous pending
   interrupts if any in IRQCLR */
}

/*******************************************************************************
** Syntax : void Hssl_lSendControlCommand(uint8 Mode)
** Description : This function sends control command for each function
*******************************************************************************/
void Hssl_lSendControlCommand(uint32 PayloadVal)
{
    HSCT_IRQCLR.B.IFCFSCLR = 1U;
    HSCT_IFCTRL.B.IFCVS = PayloadVal;
    HSCT_IFCTRL.B.SIFCV = 1U;

    HsslDemo_lDelay (1250);  /* wait until the change happens */
}

/*******************************************************************************
** Syntax : void HsslDemo_lDelay(unsigned int delay)
** Description : This function is used for introducing delay
*******************************************************************************/
void HsslDemo_lDelay(unsigned int delay)
{
    /* get current STM value */
    unsigned int stm_value = STM0_TIM0.U;

    /* note that this even works on 32bit counter wrap-arounds */
    while( (STM0_TIM0.U - stm_value) <= delay );
}
